#ifndef FILE_STRUCT
#define FILE_STRUCT

#include "file_in_disk.h"

struct file_struct
{
    char name[256];
    file_in_disk * count_file;
};


#endif