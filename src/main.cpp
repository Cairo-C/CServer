#include <iostream>
#include <fstream>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <csignal>
#include <pthread.h>
#include <fcntl.h>

#include "utils.h"
#include "event_loop.h"
#include "thread_pool.h"

#define LISTEN_PORT 12345

using std::cout;
using std::endl;
using std::vector;
using std::ifstream;
using std::string;

int start_up() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    // fcntl(sock, F_SETFL, O_NONBLOCK);

    sockaddr_in serverSocket;
    memset(&serverSocket, 0, sizeof serverSocket);

    serverSocket.sin_family = AF_INET;
    serverSocket.sin_addr.s_addr = INADDR_ANY;
    serverSocket.sin_port = htons(LISTEN_PORT);

    int on = 1;
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));

    if (bind(sock, (sockaddr*) &serverSocket, sizeof serverSocket) < 0)
        err_then_die("! Error when binding. ");
    if (listen(sock, 1024) < 0)
        err_then_die("! Error when listening. ");

    return sock;
}

void exe_end(int x) {
    log_write("Server shut down ************************************************");
    exit(0);
}

int main() {
    signal(SIGABRT, exe_end);
    signal(SIGTERM, exe_end);
    signal(SIGINT, exe_end);

    int sock = start_up();
    log_write("Server start ****************************************************");
    cout << "Server start !" << endl;

    Thread_pool tp(4);
    sockaddr_in client_addr;
    while (true) {
        memset(&client_addr, 0, sizeof client_addr);
        socklen_t caddr_len = sizeof client_addr;

        int client_fd = accept(sock, (sockaddr*) &client_addr, &caddr_len);
        if (client_fd < 0) {
            log_write("Accept failed on fd: " + to_string(sock));
            return - 1;
        }
        
        Event_loop& event_loop = *(tp.get_loop());
        Channel* c = new Http_channel(client_fd, EVENT_READ, &(event_loop));
        event_loop.add_pending_channel(c, add);
        log_write("Accept client with addr: " + string(inet_ntoa(client_addr.sin_addr)) + " on fd: " + to_string(client_fd) + " and add to loop: " + event_loop.get_name());

        event_loop.wake_up(&event_loop);
    }
    return 0;
}
