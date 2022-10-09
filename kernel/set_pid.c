#include <kstdint.h>
#include "process/used_pid.h"
#include "process/process_data.h"

struct pid * next_pid;

uint32_t set_pid(){
    struct pid * next_pid = root_pid;
    for(uint32_t search_free_pid = 0; search_free_pid < MAX_PID; search_free_pid++)
    {
        if(next_pid->used_pid == NOT_USED){
            next_pid->used_pid = USED;
            count_used_pid++;
            return next_pid->pid;
        }
        next_pid = next_pid->next_pid;
    }
}