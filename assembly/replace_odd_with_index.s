start
    ldr     r0, =data
    ldr     r1, =4
    bl      replace_odd_with_index
    end
replace_odd_with_index
    mov     r2, #0
    mov     r3, #0
loop
    cmp     r2, r1
    moveq   r0, r3
    moveq   pc, lr
    ldr     r4, [r0]
    tst     r4, #1
    beq     skip
    str     r2, [r0]
    add     r3, r3, #1
skip
    add     r0, r0, #4
    add     r2, r2, #1
    b       loop
data dcd 4, 7, 11, 2
