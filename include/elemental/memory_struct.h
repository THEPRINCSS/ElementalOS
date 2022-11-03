/*
 *      Elemental OS
 *Copyright(c) Andrey Skripcka, 2022
 * 
 */

#ifndef MEMORY_STRUCT
#define MEMORY_STRUCT
#include "kstdint.h"


struct memory{
    uint32_t high_memory;
    uint32_t low_memory;
    uint64_t byte_count;
    struct memory * next;    
};

struct memory * root_memory;

#endif