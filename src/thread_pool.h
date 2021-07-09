#pragma once 

#include <vector>
#include "utils.h"
#include "event_loop.h"

using std::vector;

class Thread_pool {
public:
    Thread_pool(int _num);
    Event_loop* get_loop();

private:
    int thread_num;
    int position;
    vector<Event_loop*> loops;
};

