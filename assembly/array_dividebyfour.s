start                      
    ldr     r0, =data
    ldr     r1, =4
    bl      array_divide_items_by_four
    end
array_divide_items_by_four 
    lsl     r1, r1, #2
    add     r1, r0, r1
loop                       
    cmp     r0, r1
    moveq   pc, lr
    ldr     r2, [r0]
    lsr     r2, r2, #2
    str     r2, [r0], #4
    b       loop
data dcd 10,20,15,8
