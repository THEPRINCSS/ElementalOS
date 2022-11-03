.code32
.global port_input
port_input:
    inw %esi, %edi
    xor %eax, %eax
    retw