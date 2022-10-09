#include "process/process_data.h"
#include "process/process_struct.h"
#include "process/used_pid.h"

void free_pid(pid_t id)
{
    struct pid * next_pid = root_pid;
    for( pid_t i = 1; i <= MAX_PID; i++ )
    {
        if(next_pid->pid == id)
        {
            if (next_pid->used_pid == NOT_USED)
            {
                return -1;
            }
            next_pid->used_pid = NOT_USED;
            count_used_pid--;
            return 0;
        }
    }
    
}