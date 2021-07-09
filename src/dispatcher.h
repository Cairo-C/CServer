#pragma once

#include <unordered_map>

#include <unistd.h>
#include <poll.h>
#include <pthread.h>

#include "channel.h"
#include "utils.h"

using std::unordered_map;

class Dispatcher {
public:
    #define MAX_EVENT_NUM 1024

    Dispatcher(const string& _owner_id) :event_num(0), owner_name(_owner_id)
        { memset(&event_set, -1, sizeof event_set); }

    void add(Channel*);
    void del(Channel*);
    void update(Channel*);
    
    void dispatch();
    string& get_owner_name(){ return owner_name;}

private:
    size_t event_num;
    pollfd event_set[MAX_EVENT_NUM];

    string owner_name;
    unordered_map<int, Channel*> channel_map;
    unordered_map<int, int> fd_to_idx;
};
