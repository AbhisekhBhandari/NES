#ifndef INSTRUCTION
#define INSTRUCTION

#include <stdbool.h>
#include <stdlib.h>
#include <stdarg.h>

#include "cpu_6502.h"

typedef enum {
    ABSOLUTE,
    ABSOLUTE_INDEXED_INDIRECT,
    ABSOLUTE_INDEXED_X,
    ABSOLUTE_INDEXED_Y,
    ABSOLUTE_INDIRECT,
    ACCUMULATOR,
    IMMEDIATE,
    IMPLIED,
    PROGRAM_COUNTER_RELATIVE,
    STACK,
    ZERO_PAGE,
    ZERO_PAGE_INDEXED_INDIRECT,
    ZERO_PAGE_INDEXED_X,
    ZERO_PAGE_INDEXED_Y,
    ZERO_PAGE_INDIRECT,
    ZERO_PAGE_INDIRECT_INDEXED_Y    

}addressing_modes_t;


struct instruction_t {
    char* opcode;
    void (*op_func)(cpu_6502_t*, struct instruction_t*);
    addressing_modes_t addr_mode;
    uint16_t (*op_mode)(cpu_6502_t* cpu_6502);
    uint8_t cycles;
};

// modes
uint16_t absolute_mode(cpu_6502_t* cpu_6502);   //a
uint16_t absolute_indexed_indirect_mode(cpu_6502_t* cpu_6502); //(a,x)(4)
uint16_t absolute_indexed_x_mode(cpu_6502_t* cpu_6502); // a,x
uint16_t absolute_indexed_y_mode(cpu_6502_t* cpu_6502); //a,y
uint16_t absolute_indirect_mode(cpu_6502_t* cpu_6502);  // (a)
uint16_t accumulator_mode(cpu_6502_t* cpu_6502);        // A
uint16_t immediate_mode(cpu_6502_t* cpu_6502);          // #
uint16_t implied_mode(cpu_6502_t* cpu_6502);             // i
uint16_t program_counter_relative_mode(cpu_6502_t* cpu_6502);   // r
uint16_t stack_mode(cpu_6502_t* cpu_6502);       //s
uint16_t zero_page_mode(cpu_6502_t* cpu_6502);  //  zp
uint16_t zero_page_indexed_indirect_mode(cpu_6502_t* cpu_6502); //(zp, x)
uint16_t zero_page_indexed_X(cpu_6502_t* cpu_6502); // zp,x
uint16_t zero_page_indexed_Y(cpu_6502_t* cpu_6502); //zp, y
uint16_t zero_page_indirect(cpu_6502_t* cpu_6502);  // zp(4)
uint16_t zero_page_indirect_indexed_y(cpu_6502_t* cpu_6502); //(zp), y;


// // instructions
void XXX(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);

void ADC(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void AND(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void ASL(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void BCC(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void BCS(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void BEQ(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void BIT(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void BMI(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void BNE(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void BPL(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void BRK(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void BVC(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void BVS(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void CLC(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void CLD(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void CLI(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void CLV(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void CMP(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void CPX(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void CPY(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void DEC(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void DEX(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void DEY(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void EOR(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void INC(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void INX(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void INY(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void JMP(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void JSR(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void LDA(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void LDX(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void LDY(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void LSR(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void NOP(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void ORA(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void PHA(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void PHP(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void PLA(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void PLP(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void ROL(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void ROR(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void RTI(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void RTS(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void SBC(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void SEC(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void SED(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void SEI(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void STA(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void STX(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void STY(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void TAX(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void TAY(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void TSX(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void TXA(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void TXS(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void TYA(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void PHY(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void PLY(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void PHX(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void PLX(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void TRB(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void RMB(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void TSB(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void STZ(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void BRA(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);






extern struct instruction_t lookup[256];




#endif