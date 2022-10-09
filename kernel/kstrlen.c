/*
 *      Elemental OS
 *Copyright(c) Andrey Skripcka, 2022
 * 
 */

#include <kstdint.h>

size_t kstrlen(const char* str)
{
    size_t len_ret = 0;
    while(str[len_ret] != '\0')
    {
        len_ret++;
    }
    return len_ret;
}