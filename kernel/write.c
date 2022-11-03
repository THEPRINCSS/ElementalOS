#include <elemental/kstdint.h>
#include <elemental/thread.h>
#include <elemental/thread_open_mode.h>
#include <elemental/kbool.h>
#include <elemental/kstdio.h>
#include <elemental/kstring.h>

uint8_t write(tid_t tid, const char * data, uint64_t size)
{
    struct thread * next_thread = root_thread;
    bool_t search_flag = TRUE;
    while(next_thread != NULL)
    {
        if(next_thread->tid == tid)
        {
            search_flag = FALSE;
            break;
        }
    }
    if(search_flag)
    {
        return -1;
    }
    if(next_thread->mode == O_RDONLY)
    {
        return -1;
    }
    for(size_t i = 0; i < strlen(data); i++)
    {
        next_thread->addr[next_thread->step] = data[i];
        next_thread->step++;
    }
    return 0;
}