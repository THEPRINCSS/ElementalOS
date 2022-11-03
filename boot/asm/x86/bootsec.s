/*
 *      Elemental OS
 *Copyright(c) Andrey Skripcka, 2022
 * 
 */

.code32
.global _start
_start:
    movb $0x0, %al
    movb $0x02, %ah
    int $0x10
    xor %ax, %ax
    movw %ax, %es
    movw $(0x7c00 + 513), %bx
    xor %dx, %dx
    movb $0x2, %ah
    xor %cx, %cx
    movb $2, %cl
    movb $10, %al
    int $0x13
    movw %es, %ax
    leal (%eax,%ebx), %eax
    jmp *%eax

.org 510
boot_sec:
    .word 0xaa55