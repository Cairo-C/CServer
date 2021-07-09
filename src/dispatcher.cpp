#include <string>

#include "dispatcher.h"

using namespace std;

void Dispatcher::dispatch() {
    int num = poll(event_set, event_num, -1);
    if (num < 0) {
        log_write("! Error: event loop: " + owner_name + string(" poll error !"));
        err_then_die("Error after polling");
    }

    for (int i = 0; i < MAX_EVENT_NUM && num > 0; ++i) {
        if (event_set[i].fd == -1 || event_set[i].revents <= 0) 
            continue;
        
        auto& channel = *(channel_map[event_set[i].fd]);

        if (event_set[i].revents & POLLERR) {
            log_write("! " + channel.name + " fd: " + to_string(channel.fd) + " found poll err !");
            close(channel.fd);
        }
        if (event_set[i].revents & POLLIN) {
            if (channel.event_type & EVENT_READ) {
                log_write(channel.name + " fd: " + to_string(channel.fd) + " call back read function by loop: " + owner_name);
                channel.event_read_call_back();
            } else 
                log_write("! " + channel.name + " fd: " + to_string(channel.fd) + " call unregister read function");
        }
        if (event_set[i].revents & POLLOUT) {
            if (channel.event_type & EVENT_WRITE) {
                log_write(channel.name + " fd: " + to_string(channel.fd) + " call back write function by loop: " + owner_name);
                channel.event_write_call_back();
            } else 
                log_write("! " + channel.name + " fd: " + to_string(channel.fd) + " call unregister write function");
        }

        --num;
    }

    return ;
}

void Dispatcher::add(Channel* c) {
    if (event_num >= MAX_EVENT_NUM - 1) {
        log_write("Error: event loop: " + owner_name + " failed to add channel with fd: " + to_string(c->fd));
        return ;
    } else {
        for (int i = 0; i < MAX_EVENT_NUM; ++i) {
            if (event_set[i].fd == -1) {
                event_set[i].fd = c->fd;
                event_set[i].events = 0;

                if (c->event_type & EVENT_READ)
                    event_set[i].events |= POLLIN;
                if (c->event_type & EVENT_WRITE)
                    event_set[i].events |= POLLOUT;

                if (channel_map.count(c->fd) || fd_to_idx.count(c->fd))
                    log_write("! Error: add fd: " + to_string(c->fd) + " which is exits in the event set !");
                channel_map[c->fd] = c;
                fd_to_idx[c->fd] = i;
                log_write("Add " + c->name + " with fd: " + to_string(c->fd) + " to event loop: " + owner_name);
                
                ++event_num;
                break;
            }
        }
    }
}

void Dispatcher::del(Channel* c) {
    int idx = fd_to_idx[c->fd];
    if (event_set[idx].fd != c->fd) {
        string msg("Error: find event set fd inconsistent with channel fd: " + to_string(c->fd));
        log_write(msg);
        err_then_die(msg);
    }

    memset(&(event_set[idx]), -1, sizeof(event_set[idx]));
    channel_map.erase(c->fd);
    fd_to_idx.erase(c->fd);
    --event_num;

    log_write("Delete " + c->name + " with fd: " + to_string(c->fd) + " from event loop: " + owner_name);
    delete c;
}

void Dispatcher::update(Channel* c) {
    int idx = fd_to_idx[c->fd];
    if (event_set[idx].fd != c->fd) {
        string msg("Error: find event set fd inconsistent with channel fd: " + to_string(c->fd));
        log_write(msg);
        err_then_die(msg);
    }
    bool f1 = false, f2 = false;
    event_set[idx].events = 0;

    if (c->event_type & EVENT_READ) {
        event_set[idx].events |= POLLIN;
        f1 = true;
    }
    if (c->event_type & EVENT_WRITE) {
        event_set[idx].events |= POLLOUT;
        f2 = true;
    }
    
    string msg = "update " + c->name + " with fd: " + to_string(c->fd);
    if (f1) msg += " read event ";
    if (f2) msg += " write event ";
    if (!f1 && !f2) msg+= " nothing ";
    log_write(msg);
}
