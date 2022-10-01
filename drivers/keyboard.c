#include "keypress.h"
#include <kstdint.h>

uint8_t * keyboard()
{
    uint8_t get_command[256];
    for(uint8_t i = 0; i < 256; i++)
    {
        uint8_t temp_key = keypress();
        if(temp_key == 13)
            break;
        get_command[i] = temp_key;
    }
    return get_command;
}