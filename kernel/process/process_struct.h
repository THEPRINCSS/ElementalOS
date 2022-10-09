#ifndef PROCESS_STRUCT
#define PROCESS_STRUCT
#include <kstdint.h>


typedef struct{
    uint64_t reg[8];
    uint64_t res_rip;
} process;

#endif