#ifndef PROCESS_DATA
#define PROCESS_DATA

#include "process_struct.h"
#include <kstdint.h>
#include "used_pid.h"

#define MAX_PID 0xffff
uint32_t count_used_pid;


struct pid{
    pid_t pid;
    used_pid_t used_pid;
    struct pid * next_pid;

};

struct pid * root_pid;

#endif