#include <kstdint.h>

typedef struct 
{
    uint16_t signature;
    uint64_t last_byte;
    uint64_t total_byte;
    uint64_t count_addr_table;
    uint64_t header_size;
    uint64_t min_mem;
    uint64_t max_mem;
    uint64_t ss_start;
    uint64_t sp_start;
    uint64_t checksum;
    uint64_t cs_ip_start;
    
} pe;