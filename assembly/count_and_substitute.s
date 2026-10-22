start
    ldr     r0, =array
    mov     r1, #4
    mov     r2, #3
    bl      count_and_substitute
    end

count_and_substitute
    mov     r3, #0
loop
    cmp     r1, #0
    moveq   r0, r3
    moveq   pc, lr
    ldr     r4, [r0]
    cmp     r4, #0
    bge     skip
    str     r2, [r0]
    add     r3, r3, #1
skip
    add     r0, r0, #4
    sub     r1, r1, #1
    b       loop

array dcd 4, -3, -2, 1
