#include <elemental/thread.h>
#include <elemental/thread_open_mode.h>
#include <elemental/kstdint.h>
#include <elemental/kbool.h>
#include <elemental/kstdio.h>

uint64_t read(tid_t tid, char* data, uint64_t size)
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
    if(next_thread->mode == O_WRONLY)
    {
        return -1;
    }
    uint64_t read_sym = 0;
    for(uint64_t i = 0; i < size; i++)
    {
        if(next_thread->addr[next_thread->step] == EOF)
        {
            return read_sym;
        }
        data[i] = next_thread->addr[next_thread->step];
        next_thread->step++;
        read_sym++;
    }

}