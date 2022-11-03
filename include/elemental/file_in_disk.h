#ifndef FILE_IN_DISK
#define FILE_IN_DISK

#include "kstdint.h"

struct file_in_disk 
{
    uint16_t high_port;
    uint16_t middle_port;
    uint16_t low_port;
};

#endif