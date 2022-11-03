#ifndef DIR_STRUCT
#define DIR_STRUCT

#include "kstdint.h"
#include "file_struct.h"

struct dir_struct
{
    char                 name[256];
    uint64_t             child_dir_count;
    struct dir_struct *  child_dir;
    uint64_t             file_count;
    struct file_struct * file;
};

#endif
