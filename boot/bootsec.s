.code16
.global _start
_start:

.org 510
boot_sec:
    .word 0xaa55