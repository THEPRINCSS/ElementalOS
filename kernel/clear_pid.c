#include "process/process_data.h"
#include "process/used_pid.h"
 #include "process/process_struct.h"

//struct pid * next = root_pid;

void clear_pid()
{
    struct pid * next = root_pid;
    for(pid_t i = 1; i <= MAX_PID; i++)
    {
        next->pid = i;
        next->used_pid = NOT_USED;
        next = next->next_pid;
    }
    count_used_pid = 0;
}