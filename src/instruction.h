#ifndef INSTRUCTION
#define INSTRUCTION

#include "cpu_6502.h"

struct instruction_t {
    char* opcode;
    void (*op_func)(cpu_6502_t*, struct instruction_t*);
    uint8_t (*op_mode)(cpu_6502_t* cpu_6502);
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



static struct instruction_t lookup[256] = {};



// static struct instruction_t lookup[256] = {
//     {"BRK", &BRK, &immediate_mode, 7}, {"ORA", &ORA, &zero_page_indexed_indirect_mode, 6}, {"???", &XXX, &implied_mode, 2},
//     {"???", &XXX, &implied_mode, 8}, {"???", &NOP, &implied_mode, 3}, {"ORA", &ORA, &zero_page_mode, 3},
//     {"ASL", &ASL, &zero_page_mode, 5}, {"???", &XXX, &implied_mode, 5}, {"PHP", &PHP, &implied_mode, 3},
//     {"ORA", &ORA, &immediate_mode, 2}, {"ASL", &ASL, &accumulator_mode, 2}, {"???", &XXX, &implied_mode, 2},
//     {"???", &NOP, &implied_mode, 4}, {"ORA", &ORA, &absolute_mode, 4}, {"ASL", &ASL, &absolute_mode, 6},
//     {"???", &XXX, &implied_mode, 6}, {"BPL", &BPL, &program_counter_relative_mode, 2}, {"ORA", &ORA, &zero_page_indirect_indexed_y, 5},
//     {"???", &XXX, &implied_mode, 2}, {"???", &XXX, &implied_mode, 8}, {"???", &NOP, &implied_mode, 4},
//     {"ORA", &ORA, &zero_page_indexed_X, 4}, {"ASL", &ASL, &zero_page_indexed_X, 6}, {"???", &XXX, &implied_mode, 6},
//     {"CLC", &CLC, &implied_mode, 2}, {"ORA", &ORA, &absolute_indexed_y_mode, 4}, {"???", &NOP, &implied_mode, 2},
//     {"???", &XXX, &implied_mode, 7}, {"???", &NOP, &implied_mode, 4}, {"ORA", &ORA, &absolute_indexed_x_mode, 4},
//     {"ASL", &ASL, &absolute_indexed_x_mode, 7}, {"???", &XXX, &implied_mode, 7}, {"JSR", &JSR, &absolute_mode, 6},
//     {"AND", &AND, &zero_page_indexed_indirect_mode, 6}, {"???", &XXX, &implied_mode, 2}, {"???", &XXX, &implied_mode, 8},
//     {"BIT", &BIT, &zero_page_mode, 3}, {"AND", &AND, &zero_page_mode, 3}, {"ROL", &ROL, &zero_page_mode, 5},
//     {"???", &XXX, &implied_mode, 5}, {"PLP", &PLP, &implied_mode, 4}, {"AND", &AND, &immediate_mode, 2},
//     {"ROL", &ROL, &accumulator_mode, 2}, {"???", &XXX, &implied_mode, 2}, {"BIT", &BIT, &absolute_mode, 4},
//     {"AND", &AND, &absolute_mode, 4}, {"ROL", &ROL, &absolute_mode, 6}, {"???", &XXX, &implied_mode, 6},
//     {"BMI", &BMI, &program_counter_relative_mode, 2}, {"AND", &AND, &zero_page_indirect_indexed_y, 5}, {"???", &XXX, &implied_mode, 2},
//     {"???", &XXX, &implied_mode, 8}, {"???", &NOP, &implied_mode, 4}, {"AND", &AND, &zero_page_indexed_X, 4},
//     {"ROL", &ROL, &zero_page_indexed_X, 6}, {"???", &XXX, &implied_mode, 6}, {"SEC", &SEC, &implied_mode, 2},
//     {"AND", &AND, &absolute_indexed_y_mode, 4}, {"???", &NOP, &implied_mode, 2}, {"???", &XXX, &implied_mode, 7},
//     {"???", &NOP, &implied_mode, 4}, {"AND", &AND, &absolute_indexed_x_mode, 4}, {"ROL", &ROL, &absolute_indexed_x_mode, 7},
//     {"???", &XXX, &implied_mode, 7}, {"RTI", &RTI, &implied_mode, 6}, {"EOR", &EOR, &zero_page_indexed_indirect_mode, 6},
//     {"???", &XXX, &implied_mode, 2}, {"???", &XXX, &implied_mode, 8}, {"???", &NOP, &implied_mode, 3},
//     {"EOR", &EOR, &zero_page_mode, 3}, {"LSR", &LSR, &zero_page_mode, 5}, {"???", &XXX, &implied_mode, 5},
//     {"PHA", &PHA, &implied_mode, 3}, {"EOR", &EOR, &immediate_mode, 2}, {"LSR", &LSR, &accumulator_mode, 2},
//     {"???", &XXX, &implied_mode, 2}, {"JMP", &JMP, &absolute_mode, 3}, {"EOR", &EOR, &absolute_mode, 4},
//     {"LSR", &LSR, &absolute_mode, 6}, {"???", &XXX, &implied_mode, 6}, {"BVC", &BVC, &program_counter_relative_mode, 2},
//     {"EOR", &EOR, &zero_page_indirect_indexed_y, 5}, {"???", &XXX, &implied_mode, 2}, {"???", &XXX, &implied_mode, 8},
//     {"???", &NOP, &implied_mode, 4}, {"EOR", &EOR, &zero_page_indexed_X, 4}, {"LSR", &LSR, &zero_page_indexed_X, 6},
//     {"???", &XXX, &implied_mode, 6}, {"CLI", &CLI, &implied_mode, 2}, {"EOR", &EOR, &absolute_indexed_y_mode, 4},
//     {"???", &NOP, &implied_mode, 2}, {"???", &XXX, &implied_mode, 7}, {"???", &NOP, &implied_mode, 4},
//     {"EOR", &EOR, &absolute_indexed_x_mode, 4}, {"LSR", &LSR, &absolute_indexed_x_mode, 7}, {"???", &XXX, &implied_mode, 7},
//     {"RTS", &RTS, &implied_mode, 6}, {"ADC", &ADC, &zero_page_indexed_indirect_mode, 6}, {"???", &XXX, &implied_mode, 2},
//     {"???", &XXX, &implied_mode, 8}, {"???", &NOP, &implied_mode, 3}, {"ADC", &ADC, &zero_page_mode, 3},
//     {"ROR", &ROR, &zero_page_mode, 5}, {"???", &XXX, &implied_mode, 5}, {"PLA", &PLA, &implied_mode, 4},
//     {"ADC", &ADC, &immediate_mode, 2}, {"ROR", &ROR, &accumulator_mode, 2}, {"???", &XXX, &implied_mode, 2},
//     {"JMP", &JMP, &absolute_indirect_mode, 5}, {"ADC", &ADC, &absolute_mode, 4}, {"ROR", &ROR, &absolute_mode, 6},
//     {"???", &XXX, &implied_mode, 6}, {"BVS", &BVS, &program_counter_relative_mode, 2}, {"ADC", &ADC, &zero_page_indirect_indexed_y, 5},
//     {"???", &XXX, &implied_mode, 2}, {"???", &XXX, &implied_mode, 8}, {"???", &NOP, &implied_mode, 4},
//     {"ADC", &ADC, &zero_page_indexed_X, 4}, {"ROR", &ROR, &zero_page_indexed_X, 6}, {"???", &XXX, &implied_mode, 6},
//     {"SEI", &SEI, &implied_mode, 2}, {"ADC", &ADC, &absolute_indexed_y_mode, 4}, {"???", &NOP, &implied_mode, 2},
//     {"???", &XXX, &implied_mode, 7}, {"???", &NOP, &implied_mode, 4}, {"ADC", &ADC, &absolute_indexed_x_mode, 4},
//     {"ROR", &ROR, &absolute_indexed_x_mode, 7}, {"???", &XXX, &implied_mode, 7}, {"???", &NOP, &implied_mode, 2},
//     {"STA", &STA, &zero_page_indexed_indirect_mode, 6}, {"???", &NOP, &implied_mode, 2}, {"???", &XXX, &implied_mode, 2},
//     {"STY", &STY, &zero_page_mode, 3}, {"STA", &STA, &zero_page_mode, 3}, {"STX", &STX, &zero_page_mode, 3},
//     {"???", &XXX, &implied_mode, 3}, {"DEY", &DEY, &implied_mode, 2}, {"???", &NOP, &immediate_mode, 2},
//     {"TXA", &TXA, &implied_mode, 2}, {"???", &XXX, &implied_mode, 2}, {"STY", &STY, &absolute_mode, 4},
//     {"STA", &STA, &absolute_mode, 4}, {"STX", &STX, &absolute_mode, 4}, {"???", &XXX, &implied_mode, 4},
//     {"BCC", &BCC, &program_counter_relative_mode, 2}, {"STA", &STA, &zero_page_indirect_indexed_y, 6}, {"???", &XXX, &implied_mode, 2},
//     {"???", &XXX, &implied_mode, 8}, {"STY", &STY, &zero_page_indexed_X, 4}, {"STA", &STA, &zero_page_indexed_X, 4},
//     {"STX", &STX, &zero_page_indexed_Y, 4}, {"???", &XXX, &implied_mode, 4}, {"TYA", &TYA, &implied_mode, 2},
//     {"STA", &STA, &absolute_indexed_y_mode, 5}, {"TXS", &TXS, &implied_mode, 2}, {"???", &XXX, &implied_mode, 5},
//     {"???", &NOP, &implied_mode, 5}, {"STA", &STA, &absolute_indexed_x_mode, 5}, {"???", &XXX, &implied_mode, 5},
//     {"???", &XXX, &implied_mode, 7}, {"LDY", &LDY, &immediate_mode, 2}, {"LDA", &LDA, &zero_page_indexed_indirect_mode, 6},
//     {"LDX", &LDX, &immediate_mode, 2}, {"???", &XXX, &implied_mode, 6}, {"LDY", &LDY, &zero_page_mode, 3},
//     {"LDA", &LDA, &zero_page_mode, 3}, {"LDX", &LDX, &zero_page_mode, 3}, {"???", &XXX, &implied_mode, 3},
//     {"TAY", &TAY, &implied_mode, 2}, {"LDA", &LDA, &immediate_mode, 2}, {"TAX", &TAX, &implied_mode, 2},
//     {"???", &XXX, &implied_mode, 2}, {"LDY", &LDY, &absolute_mode, 4}, {"LDA", &LDA, &absolute_mode, 4},
//     {"LDX", &LDX, &absolute_mode, 4}, {"???", &XXX, &implied_mode, 4}, {"BCS", &BCS, &program_counter_relative_mode, 2},
//     {"LDA", &LDA, &zero_page_indirect_indexed_y, 5}, {"???", &XXX, &implied_mode, 2}, {"???", &XXX, &implied_mode, 8},
//     {"LDY", &LDY, &zero_page_indexed_X, 4}, {"LDA", &LDA, &zero_page_indexed_X, 4}, {"LDX", &LDX, &zero_page_indexed_Y, 4},
//     {"???", &XXX, &implied_mode, 4}, {"CLV", &CLV, &implied_mode, 2}, {"LDA", &LDA, &absolute_indexed_y_mode, 4},
//     {"TSX", &TSX, &implied_mode, 2}, {"???", &XXX, &implied_mode, 4}, {"LDY", &LDY, &absolute_indexed_x_mode, 4},
//     {"LDA", &LDA, &absolute_indexed_x_mode, 4}, {"LDX", &LDX, &absolute_indexed_y_mode, 4}, {"???", &XXX, &implied_mode, 4},
//     {"CPY", &CPY, &immediate_mode, 2}, {"CMP", &CMP, &zero_page_indexed_indirect_mode, 6}, {"???", &NOP, &implied_mode, 2},
//     {"???", &XXX, &implied_mode, 8}, {"CPY", &CPY, &zero_page_mode, 3}, {"CMP", &CMP, &zero_page_mode, 3},
//     {"DEC", &DEC, &zero_page_mode, 5}, {"???", &XXX, &implied_mode, 5}, {"INY", &INY, &implied_mode, 2},
//     {"CMP", &CMP, &immediate_mode, 2}, {"DEX", &DEX, &implied_mode, 2}, {"???", &XXX, &implied_mode, 2},
//     {"CPY", &CPY, &absolute_mode, 4}, {"CMP", &CMP, &absolute_mode, 4}, {"DEC", &DEC, &absolute_mode, 6},
//     {"???", &XXX, &implied_mode, 6}, {"BNE", &BNE, &program_counter_relative_mode, 2}, {"CMP", &CMP, &zero_page_indirect_indexed_y, 5},
//     {"???", &XXX, &implied_mode, 2}, {"???", &XXX, &implied_mode, 8}, {"???", &NOP, &implied_mode, 4},
//     {"CMP", &CMP, &zero_page_indexed_X, 4}, {"DEC", &DEC, &zero_page_indexed_X, 6}, {"???", &XXX, &implied_mode, 6},
//     {"CLD", &CLD, &implied_mode, 2}, {"CMP", &CMP, &absolute_indexed_y_mode, 4}, {"NOP", &NOP, &implied_mode, 2},
//     {"???", &XXX, &implied_mode, 7}, {"???", &NOP, &implied_mode, 4}, {"CMP", &CMP, &absolute_indexed_x_mode, 4},
//     {"DEC", &DEC, &absolute_indexed_x_mode, 7}, {"???", &XXX, &implied_mode, 7}, {"CPX", &CPX, &immediate_mode, 2},
//     {"SBC", &SBC, &zero_page_indexed_indirect_mode, 6}, {"???", &NOP, &implied_mode, 2}, {"???", &XXX, &implied_mode, 8},
//     {"CPX", &CPX, &zero_page_mode, 3}, {"SBC", &SBC, &zero_page_mode, 3}, {"INC", &INC, &zero_page_mode, 5},
//     {"???", &XXX, &implied_mode, 5}, {"INX", &INX, &implied_mode, 2}, {"SBC", &SBC, &immediate_mode, 2},
//     {"NOP", &NOP, &implied_mode, 2}, {"???", &SBC, &implied_mode, 4}, {"CPX", &CPX, &absolute_mode, 4},
//     {"SBC", &SBC, &absolute_mode, 4}, {"INC", &INC, &absolute_mode, 6}, {"???", &XXX, &implied_mode, 6},
//     {"BEQ", &BEQ, &program_counter_relative_mode, 2}, {"SBC", &SBC, &zero_page_indirect_indexed_y, 5}, {"???", &XXX, &implied_mode, 2},
//     {"???", &XXX, &implied_mode, 8}, {"???", &NOP, &implied_mode, 4}, {"SBC", &SBC, &zero_page_indexed_X, 4},
//     {"INC", &INC, &zero_page_indexed_X, 6}, {"???", &XXX, &implied_mode, 6}, {"SED", &SED, &implied_mode, 2},
//     {"SBC", &SBC, &absolute_indexed_y_mode, 4}, {"NOP", &NOP, &implied_mode, 2}, {"???", &XXX, &implied_mode, 7},
//     {"???", &NOP, &implied_mode, 4}, {"SBC", &SBC, &absolute_indexed_x_mode, 4}, {"INC", &INC, &absolute_indexed_x_mode, 7},
//     {"???", &XXX, &implied_mode, 7}
// };



#endif