/*
 *      Elemental OS
 *Copyright(c) Andrey Skripcka, 2022
 * 
 */

#ifndef KSTDIO
#define KSTDIO
#include "kstdint.h"
#include "thread.h"

#define EOF -1

#define NULL (void*)0

//чтение из потока
extern uint64_t read(tid_t, char * , uint64_t);
//запись в поток
extern uint8_t write(tid_t, const char * uint64_t);
//открытые потока
extern int open(const char *, mode_t);
//закрытие потока
extern int close(tid_t);
//позиционирование потока
extern lseek(tid_t, long, uint64_t);

#endif