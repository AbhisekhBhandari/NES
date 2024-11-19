; Test LDA Instruction
LDA #$10      ; Load 0x10 into the accumulator
STA $0200     ; Store the accumulator into memory address 0x0200
BRK           ; Halt execution
