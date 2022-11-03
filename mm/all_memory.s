.code32
.global all_memory
all_memory:
    movb $0x8a, %ah
    int $0x15
    movl %edx, %ebx
    shl $16, %ebx
    addl %eax, %ebx
    movl %ebx, %eax
    retw