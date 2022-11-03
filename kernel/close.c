#include <kstdint.h>
#include <kstdio.h>
#include <thread.h>


struct thread * first_thread;
struct thread * second_thread;

int close(tid_t tid)
{
    first_thread = root_thread;
    second_thread = root_thread;
    while(second_thread != NULL)
    {
        if(second_thread->tid == tid)
        {
            if(second_thread == root_thread)
            {
                root_thread = second_thread->next_thread;
                return 0;
            }
            else
            {
                first_thread->next_thread = second_thread->next_thread;
                return 0;
            }
        }
    }
    return -1;
}