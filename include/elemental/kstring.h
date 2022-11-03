/*
 *      Elemental OS
 *Copyright(c) Andrey Skripcka, 2022
 * 
 */

#ifndef KSTRING
#define KSTRING

#include "kstdint.h"
//длина строки
size_t kstrlen(const char*);
//сравнение строк
size_t kstrcmp(const char*, const char*);
//разделение строк
char * kstrtok(char * , const char *);

#endif