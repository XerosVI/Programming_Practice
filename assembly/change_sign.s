start
    mov     r0, #5
    bl      change_sign
    end

change_sign
    rsb     r0, r0, #0
    mov     pc, lr
