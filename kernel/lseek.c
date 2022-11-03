#include <elemental/kstdint.h>
#include <elemental/seek_step.h>
#include <elemental/thread.h>
#include <elemental/kstdio.h>
#include <elemental/kbool.h>

long lseek(tid_t tid, long offset, uint64_t origin)
{
    struct *next_thread = root_thread;
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
    switch (offset)
    {
    case SEEK_SET:
        next_thread->step = 0;
        next_thread->step += origin;
        break;
    case SEEK_CUR:
        next_thread->step += origin; 
        break;
    case SEEK_END:
        break;
    default:
        break;
    }
}