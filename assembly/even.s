start
    ldr     r0, =array
    mov     r1, #4
    bl      count_even
    end

count_even
    mov     r2, #0
loop
    subs    r1, r1, #0
    moveq   r0, r2
    moveq   pc, lr
    
    ldr     r3, [r0], #4
    tst     r3, #1
    addeq   r2, r2, #1

    subs    r1, r1, #1
    b       loop

array dcd 12, 7, 4, 15
