main:
    lda #$0B
    jmp setA45
    returnfromjmp:
        lda #$FF
        clc



    setA45: 
        lda #$45
        jmp returnfromjmp

        sec


