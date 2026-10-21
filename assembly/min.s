start
    mov     r0, #5
    mov     r1, #-3
    bl      min_two_integers
    end

min_two_integers
    cmp     r0, r1
    movgt   r0, r1
    mov     pc, lr
