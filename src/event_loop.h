# pragma once

#include <string>
#include <queue>
#include <pthread.h>

#include "dispatcher.h"

using std::queue;
using std::to_string;

enum Pending_type {
    del,
    add,
    update
};

struct Event_loop_pending_channel {
    Channel* c;
    Pending_type pending_type;

    Event_loop_pending_channel(Channel* _c, Pending_type(_type))
        : c(_c), pending_type(_type) {};
};


class Event_loop {
public:
    Event_loop(const string& _name, pthread_t _tid = 0);
    ~Event_loop();
    
    pthread_t& get_pthread_t() { return t_id; }
    const string get_name() { return name; }

    void add_pending_channel(Channel* c, Pending_type type);
    void handle_pending_channels();
    void run();
    void wake_up(Event_loop* e);

private:

    Dispatcher dispatcher;
    queue<Event_loop_pending_channel> pending_events;

    pthread_mutex_t lock;
    pthread_cond_t con;
    int socket_pair[2];

    string name;
    pthread_t t_id;
};
