/*
 *      Elemental OS
 *Copyright(c) Andrey Skripcka
 */

//переключение между режимом ядра
//и режимом пользователя
.code16
.global switch_mode
switch_mode:
    movl %cr0, %eax
    or $0x1, %ax
    movl %eax, %cr0
    movw $0x0, %ax
    retw