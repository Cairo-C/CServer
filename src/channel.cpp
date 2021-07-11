#include <string>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "channel.h"
#include "dispatcher.h"
#include "thread_pool.h"
#include "event_loop.h"

using std::cout;
using std::endl;
using std::vector;
using std::ifstream;
using std::string;
using std::to_string;

int Wakeup_channel::event_read_call_back() {
    char buffer[128];
    Dispatcher* dispatcher = static_cast<Dispatcher*>(data);
    if (read(fd, buffer, sizeof buffer) < 0)
        log_write("! Read error when waking up event loop: " + dispatcher->get_owner_name());
    else
        log_write("Event loop: " + dispatcher->get_owner_name() + " wake up");
    return 0;
}

int Accept_channel::event_read_call_back() {
    sockaddr_in client_addr;
    memset(&client_addr, 0, sizeof client_addr);
    socklen_t caddr_len = sizeof client_addr;

    int client_fd = accept(fd, (sockaddr*) &client_addr, &caddr_len);
    if (client_fd < 0) {
        log_write("Accept failed on fd: " + to_string(fd));
        return - 1;
    }
    log_write("Accept client with addr: " + string(inet_ntoa(client_addr.sin_addr)) + \
              " on fd: " + to_string(client_fd));

    Thread_pool& tp = *static_cast<Thread_pool*>(data);
    Event_loop& event_loop = *(tp.get_loop());

    Channel* c = new Http_channel(client_fd, EVENT_READ, &(event_loop));
    event_loop.add_pending_channel(c, add);

    if (!pthread_equal(pthread_self(), event_loop.get_pthread_t())) 
        event_loop.wake_up(&event_loop);
    return 0;
}

int Http_channel::event_read_call_back() {
    string replyToClient;
    replyToClient += "HTTP/1.1 200 OK\r\n";
    replyToClient += "Content-type: text/html\r\n";
    replyToClient += "\r\n";
    replyToClient += "<HTML><TITLE>Cairo</TITLE>\r\n";
    replyToClient += "<BODY><P>Magic Happens !\r\n";
    replyToClient += "</BODY></HTML>\r\n";

    Event_loop* e = (Event_loop*)data;

    const char* rep = replyToClient.c_str();
    int repSize = replyToClient.size();
    char buffer[1024];

    int res = 0;
    if ((res = read(fd, buffer, 1024)) > 0) {
        buffer[res] = '\0';
        log_write(e->get_name() + " get datagram from fd: " + to_string(fd) + " as follows:\n" + string(buffer));

        if (send(fd, rep, repSize, 0) < 0) {
            log_write("! Error: failed to write to fd: " + to_string(fd));
            return -1;
        } else {
            log_write(e->get_name() + " successfully send data to fd: " + to_string(fd));
        } 
    } else if (res == 0) {
        log_write("! Error: read res = 0");
    } else
        log_write("! Error: failed to read fd: " + to_string(fd));
    // shutdown(fd, SHUT_RD);
    e->add_pending_channel(this, del);
    if (close(fd) < 0) {
        log_write("! Error: failed to close fd: " + to_string(fd));
    }
    return 0;
}
