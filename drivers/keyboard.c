/*
 *      Elemental OS
 *Copyright Andrey Skripcka, 2022
 */

#include "keypress.h"
#include <kstdint.h>

uint8_t * keyboard()
{
    //возвращаемый массив команд
    uint8_t get_command[256];
    for(uint8_t i = 0; i < 256; i++)
    {
        //получаем символ
        uint8_t temp_key = keypress();
        //сверяем с Enter
        if(temp_key == 13)
            break;
        get_command[i] = temp_key;
    }
    return get_command;
}