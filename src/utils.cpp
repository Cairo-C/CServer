#include <pthread.h>
#include "utils.h"

void err_then_die(const string& msg) {
    cout << msg << endl;
    exit(EXIT_FAILURE);
}

void init_ofs(ofstream& ofs) {
    ofs.open("/root/cairo/webserver/log.log", std::fstream::app);
    if (!(ofs.is_open()))
        err_then_die("failed to open the log file !");
}

void log_write(const string& msg) {
    static ofstream ofs;
    static bool has_init = false;
    static pthread_mutex_t log_lock;

    if (!has_init) {
        init_ofs(ofs);
        has_init = true;
        pthread_mutex_init(&log_lock, NULL);
    }

    time_t timep;
    time (&timep);
    char tmp[64];
    strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S",localtime(&timep) );

    pthread_mutex_lock(&log_lock);
    ofs << tmp << " :  "<< msg << endl;
    pthread_mutex_unlock(&log_lock);
}
