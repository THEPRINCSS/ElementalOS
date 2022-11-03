#ifndef THREAD
#define THREAD

#include "kstdint.h"
#include "thread_open_mode.h"
struct thread{
    tid_t tid;
    char * addr;
    uint64_t step;
    mode_t mode;
    struct thread * next_thread;
};

struct thread * root_thread;

#endif