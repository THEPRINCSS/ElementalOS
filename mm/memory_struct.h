/*
 *      Elemental OS
 *Copyright(c) Andrey Skripcka, 2022
 * 
 */

#ifndef MEMORY_STRUCT
#define MEMORY_STRUCT
#include <kstdint.h>
#include "memory_type.h"


struct memory{
    uint64_t high_memory;
    uint64_t low_memory;
    uint64_t byte_count;
    memory_type mt;
    struct memory * next;    
};

#endif