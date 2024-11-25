section .data
    x1 dq 1.5, 4.0, 3.5, 2.0
    x2 dq 3.0, 2.5, 2.5, 1.0
    y1 dq 4.0, 3.0, 3.5, 3.0
    y2 dq 2.0, 2.5, 1.0, 1.5
    z dq 0.0, 0.0, 0.0, 0.0

section .text
bits 64
default rel
global main
main:
    mov rbp, rsp; for correct debugging
    ;write your code here
    movsd xmm0, [x2]
    movsd xmm1, [x1]
    subsd xmm0, xmm1
    mulsd xmm0, xmm0
    movsd xmm3, xmm0
    movsd xmm0, [y2]
    movsd xmm1, [y1]
    subsd xmm0, xmm1
    mulsd xmm0, xmm0
    movsd xmm4, xmm0
    addsd xmm4, xmm3
    sqrtsd xmm5, xmm4 ; sqrt((x2[0]-x1[0])^2 + (y2[0]-y1[0])^2)
    movsd [z], xmm5
    movsd xmm9, [z]
    
    movsd xmm0, [x2+8]
    movsd xmm1, [x1+8]
    subsd xmm0, xmm1
    mulsd xmm0, xmm0
    movsd xmm3, xmm0
    movsd xmm0, [y2+8]
    movsd xmm1, [y1+8]
    subsd xmm0, xmm1
    mulsd xmm0, xmm0
    movsd xmm4, xmm0
    addsd xmm4, xmm3
    sqrtsd xmm6, xmm4 ; sqrt((x2[1]-x1[1])^2 + (y2[1]-y1[1])^2)
    movsd [z+8], xmm6
    movsd xmm10, [z+8]
    
    movsd xmm0, [x2+16]
    movsd xmm1, [x1+16]
    subsd xmm0, xmm1
    mulsd xmm0, xmm0
    movsd xmm3, xmm0
    movsd xmm0, [y2+16]
    movsd xmm1, [y1+16]
    subsd xmm0, xmm1
    mulsd xmm0, xmm0
    movsd xmm4, xmm0
    addsd xmm4, xmm3
    sqrtsd xmm7, xmm4 ; sqrt((x2[2]-x1[2])^2 + (y2[2]-y1[2])^2)
    movsd [z+16], xmm7
    movsd xmm11, [z+16]
    
    movsd xmm0, [x2+24]
    movsd xmm1, [x1+24]
    subsd xmm0, xmm1
    mulsd xmm0, xmm0
    movsd xmm3, xmm0
    movsd xmm0, [y2+24]
    movsd xmm1, [y1+24]
    subsd xmm0, xmm1
    mulsd xmm0, xmm0
    movsd xmm4, xmm0
    addsd xmm4, xmm3
    sqrtsd xmm8, xmm4 ; sqrt((x2[3]-x1[3])^2 + (y2[3]-y1[3])^2)
    movsd [z+24], xmm8
    movsd xmm12, [z+24]
    
    xor rax, rax
    ret