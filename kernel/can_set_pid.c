#include <kstdint.h>
#include <kbool.h>
#include "process/process_data.h"
#include "process/process_struct.h"
#include "process/used_pid.h"

bool_t can_set_pid()
{
    if(count_used_pid == MAX_PID)
    {
        return FALSE;
    }
    return TRUE;
}
