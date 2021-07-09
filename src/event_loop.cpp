#include <sys/socket.h>
#include <sys/types.h>

#include "channel.h"
#include "event_loop.h"

Event_loop::Event_loop(const string& _name, pthread_t _tid) 
    :name(_name), dispatcher(_name), t_id(_tid) {
    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&con, NULL);

    if (socketpair(AF_UNIX, SOCK_STREAM, 0, socket_pair) < 0) {
        log_write("! Error: " + name + " failed to open socket pair");
        err_then_die("Failed to open socket_pair");
    }
    Channel* c = new Wakeup_channel(socket_pair[1], EVENT_READ, &dispatcher);
    add_pending_channel(c, add);
}

Event_loop::~Event_loop() {
    pthread_mutex_lock(&lock);
    while (!pending_events.empty()) {
        auto x = pending_events.front();
        pending_events.pop();
        delete x.c;
    }
    pthread_mutex_unlock(&lock);
    close(socket_pair[0]);
    close(socket_pair[1]);
}

void Event_loop::run() {
    log_write("Event loop: " + name + " start running");
    while (true) {
        handle_pending_channels();
        dispatcher.dispatch();
    }
}

void Event_loop::wake_up(Event_loop* e) {
    int fd = e->socket_pair[0];
    char x = 'a';
    if (send(fd, &x, sizeof x, 0) < 0)
        log_write("! Error: " + name + " failed to wake event loop: " + e->name);
    else 
        log_write("Try to wake event loop: " + e->name);
}

void Event_loop::add_pending_channel(Channel* c, Pending_type type) {
    pthread_mutex_lock(&lock);
    pending_events.push(Event_loop_pending_channel(c, type));
    string ty;
    if (type == add) ty = "add";
    else ty = "del";
    log_write(name + " successfully add " + c->name + " with fd: " + to_string(c->fd) + " with type: " + ty + " to pending queue");
    pthread_mutex_unlock(&lock);
}

void Event_loop::handle_pending_channels() {
    pthread_mutex_lock(&lock);
    log_write(name + " is handling pending channels");
    while (!pending_events.empty()) {
        auto pc = pending_events.front();
        pending_events.pop();
        log_write(name + " handle pending channel with fd: " + to_string((pc.c)->fd));
        switch (pc.pending_type) {
        case del:
            dispatcher.del(pc.c); break;
        case add:
            dispatcher.add(pc.c); break;
        case update:
            dispatcher.update(pc.c); break;
        default:
            break;
        }
    }
    pthread_mutex_unlock(&lock);
    log_write(name + " Finish handling pending channels");
}
