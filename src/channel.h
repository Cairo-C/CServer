#pragma once

#include "utils.h"

typedef int EVENT_TYPE;
const int EVENT_READ = 0x01;
const int EVENT_WRITE = 0x02;

struct Channel {
    int fd;
    void* data = NULL;
    EVENT_TYPE event_type;
    const string name = "";

    Channel(int _fd = -1, EVENT_TYPE _event_type = 0, const string& _name = "")
        : fd(_fd), event_type(_event_type), name(_name){}

    virtual int event_read_call_back() = 0;
    virtual int event_write_call_back() = 0;
    virtual ~Channel() {}
};

struct Http_channel: public Channel {
    Http_channel(int _fd = -1, EVENT_TYPE _event_type = 0, void* dispatcher = NULL)
        : Channel(_fd, _event_type, "http channel"){  data = dispatcher; }

    int event_read_call_back();
    int event_write_call_back() {
        log_write("! Error: call write back function in accept channel");
        return 0;
    };
};

struct Wakeup_channel: public Channel {
    Wakeup_channel(int _fd = -1, EVENT_TYPE _event_type = 0, void* dispatcher = NULL)
        : Channel(_fd, _event_type, "wake up channel"){  data = dispatcher; }

    int event_read_call_back();
    int event_write_call_back() {
        log_write("! Error: call write back function in wake up channel");
        return 0;
    };
};

struct Accept_channel_data {
    void* thread_pool;
    void* event_loop;
};

struct Accept_channel: public Channel {
    Accept_channel(int _fd = -1, EVENT_TYPE _event_type = 0, void* dispatcher = NULL)
        : Channel(_fd, _event_type, "Accept channel") { data = dispatcher;}

    int event_read_call_back();
    int event_write_call_back() {
        log_write("! Error: call write back function in accept channel");
        return 0;
    };
};
