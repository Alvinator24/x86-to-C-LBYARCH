section .text
bits 64
default rel
global distance
distance:
L1:
    movsd xmm0, [rdx]
    movsd xmm1, [r8]
    mulsd xmm0, xmm0
    mulsd xmm1, xmm1
    addsd xmm0, xmm1
    sqrtsd xmm2, xmm0
    movsd [r9], xmm2
    add rdx, 8
    add r8, 8
    add r9, 8
    loop L1
    ret