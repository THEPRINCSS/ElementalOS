#include <elemental/kstdint.h>
#include <elemental/thread.h>
#include <elemental/kstdio.h>

#define MAX_THREAD_FILE 0xffff
tid_t open_thread_file_count = 0;

int open(const char * pathname, mode_t oflag)
{
    open_thread_file_count++;
    if(open_thread_file_count == MAX_THREAD_FILE)
    {
        return -1;
    }
    struct thread * next_thread;
    next_thread = root_thread;
    while(next_thread->next_thread != NULL)
    {
        next_thread = next_thread->next_thread;
    }
    next_thread = next-thread->next_thread;
    next_thread->next_thread = NULL;
    next_thread->tid = open_thread_file_count;
    next_thread->step = 0;
    next_thread->mode = oflag;
    
}