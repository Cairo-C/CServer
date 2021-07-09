#include "thread_pool.h"

void* thread_main(void* data) {
    Event_loop* event_loop = (Event_loop*)data;
    event_loop->get_pthread_t() = pthread_self();
    log_write(event_loop->get_name() + " start runing");
    event_loop->run();
    return NULL;
} 

Thread_pool::Thread_pool(int _num) 
    :thread_num(_num), position(0) {
    for (int i = 0; i < _num; ++i) {
        Event_loop* e = new Event_loop("loop " + to_string(i));
        loops.emplace_back(e);
        pthread_t tmp;
        if (pthread_create(&tmp, NULL, thread_main, (void*)e) < 0) {
            log_write("! Error: failed to create loop: " + e->get_name());
            err_then_die("failed to create new thread!");
        }
    }
}

Event_loop* Thread_pool::get_loop() {
    Event_loop* e = loops[position];
    ++position;
    position %= thread_num;
    return e;
}
