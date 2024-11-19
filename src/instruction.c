#include "instruction.h"



struct instruction_t lookup[256] = {
    // 0X00
    {"BRK", &BRK,IMMEDIATE ,&immediate_mode, 7}, 
    {"ORA", &ORA, ZERO_PAGE_INDIRECT, &zero_page_indexed_indirect_mode, 6},
    {"???", &XXX, IMPLIED, &implied_mode, 2},
    {"???", &XXX, IMPLIED, &implied_mode, 8},
    {"TSB", &TSB, ZERO_PAGE, &zero_page_mode, 3}, // TSB
    {"ORA", &ORA, ZERO_PAGE, &zero_page_mode, 3},
    {"ASL", &ASL, ZERO_PAGE, &zero_page_mode, 5},
    {"RMB0", &RMB, ZERO_PAGE, &zero_page_mode, 5},   //RMB0
    {"PHP", &PHP, IMPLIED, &implied_mode, 3},
    {"ORA", &ORA, IMMEDIATE, &immediate_mode, 2},
    {"ASL", &ASL, ACCUMULATOR, &accumulator_mode, 2}, 
    {"???", &XXX, IMPLIED, &implied_mode, 2},
    {"TSB", &TSB, ABSOLUTE, &absolute_mode, 4},   //TSB
    {"ORA", &ORA, ABSOLUTE, &absolute_mode, 4},
    {"ASL", &ASL, ABSOLUTE, &absolute_mode, 6},
    {"???", &XXX, IMPLIED,  &implied_mode, 6},  //BBR0
    // 0x0F

    // Ox10
    {"BPL", &BPL, PROGRAM_COUNTER_RELATIVE, &program_counter_relative_mode, 2},
    {"ORA", &ORA, ZERO_PAGE_INDIRECT_INDEXED_Y, &zero_page_indirect_indexed_y, 5},
    {"ORA", &ORA, ZERO_PAGE_INDIRECT, &zero_page_indirect, 2},           
    {"???", &XXX, IMPLIED, &implied_mode, 8},
    {"TRB", &TRB, ZERO_PAGE, &zero_page_mode, 4},        //TRB
    {"ORA", &ORA, ZERO_PAGE_INDEXED_X, &zero_page_indexed_X, 4},
    {"ASL", &ASL, ZERO_PAGE_INDEXED_X, &zero_page_indexed_X, 6},
    {"RMB1", &RMB, ZERO_PAGE, &zero_page_mode, 6},   
    {"CLC", &CLC, IMPLIED, &implied_mode, 2},
    {"ORA", &ORA, ABSOLUTE_INDEXED_Y, &absolute_indexed_y_mode, 4},
    {"INC", &INC, ACCUMULATOR, &accumulator_mode, 2}, 
    {"???", &XXX, IMPLIED, &implied_mode, 7},   
    {"TRB", &TRB, IMPLIED, &implied_mode, 4},  //TRB
    {"ORA", &ORA, ABSOLUTE_INDEXED_X, &absolute_indexed_x_mode, 4},
    {"ASL", &ASL, ABSOLUTE_INDEXED_X, &absolute_indexed_x_mode, 7},
    {"???", &XXX, IMPLIED, &implied_mode, 7},  // BBR1
    //0X1F


    // 0x20
    {"JSR", &JSR,  ABSOLUTE, &absolute_mode, 6},
    {"AND", &AND, ZERO_PAGE_INDEXED_INDIRECT, &zero_page_indexed_indirect_mode, 6},
    {"???", &XXX, IMPLIED, &implied_mode, 2},
    {"???", &XXX, IMPLIED, &implied_mode, 8},
    {"BIT", &BIT, ZERO_PAGE, &zero_page_mode, 3},
    {"AND", &AND, ZERO_PAGE, &zero_page_mode, 3},
    {"ROL", &ROL, ZERO_PAGE, &zero_page_mode, 5},
    {"RMB", &XXX, ZERO_PAGE, &zero_page_mode, 5},   //RMB2
    {"PLP", &PLP, IMPLIED, &implied_mode, 4},
    {"AND", &AND, IMMEDIATE, &immediate_mode, 2},
    {"ROL", &ROL, ACCUMULATOR, &accumulator_mode, 2},
    {"???", &XXX, IMPLIED, &implied_mode, 2}, 
    {"BIT", &BIT, ABSOLUTE, &absolute_mode, 4},
    {"AND", &AND, ABSOLUTE,&absolute_mode, 4},
    {"ROL", &ROL, ABSOLUTE, &absolute_mode, 6}, 
    {"???", &XXX, IMPLIED, &implied_mode, 6},   //BBR2
    // 0X2F

    // 0x30
    {"BMI", &BMI, PROGRAM_COUNTER_RELATIVE, &program_counter_relative_mode, 2},
     {"AND", &AND, ZERO_PAGE_INDEXED_Y, &zero_page_indirect_indexed_y, 5},
      {"AND", &AND, ZERO_PAGE_INDIRECT, &zero_page_indirect, 2}, 
    {"???", &XXX, IMPLIED, &implied_mode, 8},
     {"BIT", &BIT, ABSOLUTE_INDEXED_X, &absolute_indexed_x_mode, 4}, //BIT
     {"AND", &AND, ZERO_PAGE_INDEXED_X, &zero_page_indexed_X, 4},
    {"ROL", &ROL, ZERO_PAGE_INDEXED_X, &zero_page_indexed_X, 6}, 
    {"RMB3", &RMB, ZERO_PAGE, &zero_page_mode, 6},   //RMB3
    {"SEC", &SEC, IMPLIED, &implied_mode, 2},
    {"AND", &AND, ABSOLUTE_INDEXED_Y, &absolute_indexed_y_mode, 4},
     {"DEC", &DEC, ACCUMULATOR, &accumulator_mode, 2},  //DEC
      {"???", &XXX, IMPLIED, &implied_mode, 7},
    {"BIT", &BIT, ZERO_PAGE_INDEXED_X, &zero_page_indexed_X, 4},   //BIT
     {"AND", &AND, ABSOLUTE_INDEXED_X, &absolute_indexed_x_mode, 4},
      {"ROL", &ROL, ABSOLUTE_INDEXED_X, &absolute_indexed_x_mode, 7},
    {"???", &XXX, IMPLIED, &implied_mode, 7},       //BBR3
    //0x3F
    
    // 0x40
     {"RTI", &RTI, IMPLIED, &implied_mode, 6},
      {"EOR", &EOR, ZERO_PAGE_INDEXED_INDIRECT, &zero_page_indexed_indirect_mode, 6},
    {"???", &XXX, IMPLIED, &implied_mode, 2},
    {"???", &XXX, IMPLIED, &implied_mode, 8},
    {"???", &NOP, IMPLIED, &implied_mode, 3},
    {"EOR", &EOR, ZERO_PAGE, &zero_page_mode, 3},
    {"LSR", &LSR, ZERO_PAGE, &zero_page_mode, 5}, 
    {"RMB4", &RMB, ZERO_PAGE, &zero_page_mode, 5},   //RMB4
    {"PHA", &PHA, IMPLIED, &implied_mode, 3}, 
    {"EOR", &EOR, IMMEDIATE, &immediate_mode, 2}, 
    {"LSR", &LSR, ACCUMULATOR, &accumulator_mode, 2},
    {"???", &XXX, IMPLIED, &implied_mode, 2},
     {"JMP", &JMP, ABSOLUTE , &absolute_mode, 3},
      {"EOR", &EOR, ABSOLUTE , &absolute_mode, 4},
    {"LSR", &LSR, ABSOLUTE , &absolute_mode, 6},
     {"???", &XXX, IMPLIED, &implied_mode, 6},  //BBR4
    //0x4F

    //0x50
    {"BVC", &BVC, PROGRAM_COUNTER_RELATIVE ,&program_counter_relative_mode, 2},
    {"EOR", &EOR, ZERO_PAGE_INDIRECT_INDEXED_Y,&zero_page_indirect_indexed_y, 5}, 
    {"EOR", &EOR, ZERO_PAGE_INDIRECT, &zero_page_indirect, 2},   //EOR
    {"???", &XXX, IMPLIED, &implied_mode, 8},
    {"???", &NOP, IMPLIED, &implied_mode, 4},
    {"EOR", &EOR, ZERO_PAGE_INDEXED_X,&zero_page_indexed_X, 4},
    {"LSR", &LSR, ZERO_PAGE_INDEXED_X,&zero_page_indexed_X, 6},
    {"RMB5", &RMB, ZERO_PAGE, &zero_page_mode, 6},   //RMB5
    {"CLI", &CLI, IMPLIED, &implied_mode, 2},
    {"EOR", &EOR, ABSOLUTE_INDEXED_Y,&absolute_indexed_y_mode, 4},
    {"PHY", &PHY, STACK, &stack_mode, 2},   //PHY
    {"???", &XXX, IMPLIED, &implied_mode, 7},
    {"???", &NOP, IMPLIED, &implied_mode, 4},
    {"EOR", &EOR, ABSOLUTE_INDEXED_X ,&absolute_indexed_x_mode, 4},
    {"LSR", &LSR, ABSOLUTE_INDEXED_X ,&absolute_indexed_x_mode, 7},
    {"???", &XXX, IMPLIED, &implied_mode, 7}, //BBR5
    //0x5F

    //0x60
    {"RTS", &RTS, STACK, &stack_mode, 6},
     {"ADC", &ADC, ZERO_PAGE_INDEXED_INDIRECT,&zero_page_indexed_indirect_mode, 6},
      {"???", &XXX, IMPLIED, &implied_mode, 2},
    {"???", &XXX, IMPLIED, &implied_mode, 8},
     {"STZ", &STZ, ZERO_PAGE, &zero_page_mode, 3},  //STZ
      {"ADC", &ADC, ZERO_PAGE, &zero_page_mode, 3},
    {"ROR", &ROR, ZERO_PAGE, &zero_page_mode, 5}, 
    {"RMB6", &RMB, ZERO_PAGE, &zero_page_mode, 5},   //RMB6
    {"PLA", &PLA, IMPLIED, &implied_mode, 4},
    {"ADC", &ADC, IMMEDIATE, &immediate_mode, 2}, 
    {"ROR", &ROR, ACCUMULATOR, &accumulator_mode, 2}, 
    {"???", &XXX, IMPLIED, &implied_mode, 2},
    {"JMP", &JMP, ABSOLUTE_INDIRECT, &absolute_indirect_mode, 5}, 
    {"ADC", &ADC, ABSOLUTE , &absolute_mode, 4}, 
    {"ROR", &ROR, ABSOLUTE , &absolute_mode, 6},
    {"???", &XXX, IMPLIED, &implied_mode, 6},   //BBR6
    //0x6F

    //0x70
    {"BVS", &BVS, PROGRAM_COUNTER_RELATIVE ,&program_counter_relative_mode, 2}, 
    {"ADC", &ADC, ZERO_PAGE_INDIRECT_INDEXED_Y,&zero_page_indirect_indexed_y, 5},
    {"ADC", &ADC, ZERO_PAGE_INDIRECT, &zero_page_indirect, 2},   //ADC
    {"???", &XXX, IMPLIED, &implied_mode, 8}, 
    {"STZ", &STZ, ZERO_PAGE_INDEXED_X, &zero_page_indexed_X, 4},   //STZ
    {"ADC", &ADC, ZERO_PAGE_INDEXED_X,&zero_page_indexed_X, 4},
    {"ROR", &ROR, ZERO_PAGE_INDEXED_X,&zero_page_indexed_X, 6}, 
    {"RMB7", &RMB, ZERO_PAGE, &zero_page_mode, 6},   //RMB7
    {"SEI", &SEI, IMPLIED, &implied_mode, 2}, 
    {"ADC", &ADC, ABSOLUTE_INDEXED_Y,&absolute_indexed_y_mode, 4}, 
    {"PLY", &PLY, STACK, &stack_mode, 2},   //PLY
    {"???", &XXX, IMPLIED, &implied_mode, 7}, 
    {"JMP", &JMP, ABSOLUTE_INDEXED_INDIRECT, &absolute_indexed_indirect_mode, 4},   //JMP
    {"ADC", &ADC, ABSOLUTE_INDEXED_X ,&absolute_indexed_x_mode, 4},
    {"ROR", &ROR, ABSOLUTE_INDEXED_X ,&absolute_indexed_x_mode, 7}, 
    {"???", &XXX, IMPLIED, &implied_mode, 7},       //BBR7
    //0x7F


    // Ox80
    {"BRA", &BRA, PROGRAM_COUNTER_RELATIVE, &program_counter_relative_mode, 2},   //BRA
    {"STA", &STA, ZERO_PAGE_INDEXED_INDIRECT,&zero_page_indexed_indirect_mode, 6}, 
    {"???", &NOP, IMPLIED, &implied_mode, 2}, 
    {"???", &XXX, IMPLIED, &implied_mode, 2},
    {"STY", &STY, ZERO_PAGE, &zero_page_mode, 3}, 
    {"STA", &STA, ZERO_PAGE, &zero_page_mode, 3}, 
    {"STX", &STX, ZERO_PAGE, &zero_page_mode, 3},
    {"???", &XXX, IMPLIED, &implied_mode, 3},   //SMB0
    {"DEY", &DEY, IMPLIED, &implied_mode, 2}, 
    {"BIT", &BIT, IMMEDIATE, &immediate_mode, 2},   //BIT
    {"TXA", &TXA, IMPLIED, &implied_mode, 2}, 
    {"???", &XXX, IMPLIED, &implied_mode, 2}, 
    {"STY", &STY, ABSOLUTE , &absolute_mode, 4},
    {"STA", &STA, ABSOLUTE , &absolute_mode, 4}, 
    {"STX", &STX, ABSOLUTE , &absolute_mode, 4}, 
    {"???", &XXX, IMPLIED, &implied_mode, 4},       //BBS0
    //0x8F

    //0x90
    {"BCC", &BCC, PROGRAM_COUNTER_RELATIVE ,&program_counter_relative_mode, 2}, 
    {"STA", &STA, ZERO_PAGE_INDIRECT_INDEXED_Y,&zero_page_indirect_indexed_y, 6}, 
    {"STA", &STA, ZERO_PAGE_INDIRECT, &zero_page_indirect, 2},   //STA
    {"???", &XXX, IMPLIED, &implied_mode, 8}, 
    {"STY", &STY, ZERO_PAGE_INDEXED_X,&zero_page_indexed_X, 4}, 
    {"STA", &STA, ZERO_PAGE_INDEXED_X,&zero_page_indexed_X, 4},
    {"STX", &STX,ZERO_PAGE_INDEXED_Y, &zero_page_indexed_Y, 4}, 
    {"???", &XXX, IMPLIED, &implied_mode, 4},   //SMB1
    {"TYA", &TYA, IMPLIED, &implied_mode, 2},
    {"STA", &STA, ABSOLUTE_INDEXED_Y,&absolute_indexed_y_mode, 5}, 
    {"TXS", &TXS, IMPLIED, &implied_mode, 2}, 
    {"???", &XXX, IMPLIED, &implied_mode, 5},
    {"STZ", &STZ, ABSOLUTE, &absolute_mode, 5},   //STZ
    {"STA", &STA, ABSOLUTE_INDEXED_X ,&absolute_indexed_x_mode, 5}, 
    {"STZ", &STZ, ABSOLUTE_INDEXED_X, &absolute_indexed_x_mode, 5},       //STZ
    {"???", &XXX, IMPLIED, &implied_mode, 7},       //BBS2
    //0x9F


    //0x0A
    {"LDY", &LDY, IMMEDIATE, &immediate_mode, 2}, 
    {"LDA", &LDA, ZERO_PAGE_INDEXED_INDIRECT,&zero_page_indexed_indirect_mode, 6},
    {"LDX", &LDX, IMMEDIATE, &immediate_mode, 2}, 
    {"???", &XXX, IMPLIED, &implied_mode, 6}, 
    {"LDY", &LDY, ZERO_PAGE, &zero_page_mode, 3},
    {"LDA", &LDA, ZERO_PAGE, &zero_page_mode, 3}, 
    {"LDX", &LDX, ZERO_PAGE, &zero_page_mode, 3}, 
    {"???", &XXX, IMPLIED, &implied_mode, 3},   //SMB2
    {"TAY", &TAY, IMPLIED, &implied_mode, 2}, 
    {"LDA", &LDA, IMMEDIATE, &immediate_mode, 2}, 
    {"TAX", &TAX, IMPLIED, &implied_mode, 2},
    {"???", &XXX, IMPLIED, &implied_mode, 2}, 
    {"LDY", &LDY, ABSOLUTE , &absolute_mode, 4}, 
    {"LDA", &LDA, ABSOLUTE , &absolute_mode, 4},
    {"LDX", &LDX, ABSOLUTE , &absolute_mode, 4}, 
    {"???", &XXX, IMPLIED, &implied_mode, 4},   //BBS3
    //0xAF

    //0xB0
    {"BCS", &BCS, PROGRAM_COUNTER_RELATIVE ,&program_counter_relative_mode, 2},
    {"LDA", &LDA, ZERO_PAGE_INDIRECT_INDEXED_Y,&zero_page_indirect_indexed_y, 5}, 
    {"LDA", &LDA, ZERO_PAGE_INDIRECT, &zero_page_indirect, 2},       //LDA
    {"???", &XXX, IMPLIED, &implied_mode, 8},
    {"LDY", &LDY, ZERO_PAGE_INDEXED_X,&zero_page_indexed_X, 4}, 
    {"LDA", &LDA, ZERO_PAGE_INDEXED_X,&zero_page_indexed_X, 4}, 
    {"LDX", &LDX, ZERO_PAGE_INDEXED_Y, &zero_page_indexed_Y, 4},
    {"???", &XXX, IMPLIED, &implied_mode, 4},       //SMB3
    {"CLV", &CLV, IMPLIED, &implied_mode, 2}, 
    {"LDA", &LDA, ABSOLUTE_INDEXED_Y,&absolute_indexed_y_mode, 4},
    {"TSX", &TSX, IMPLIED, &implied_mode, 2}, 
    {"???", &XXX, IMPLIED, &implied_mode, 4}, 
    {"LDY", &LDY, ABSOLUTE_INDEXED_X ,&absolute_indexed_x_mode, 4},
    {"LDA", &LDA, ABSOLUTE_INDEXED_X ,&absolute_indexed_x_mode, 4}, 
    {"LDX", &LDX, ABSOLUTE_INDEXED_Y,&absolute_indexed_y_mode, 4}, 
    {"???", &XXX, IMPLIED, &implied_mode, 4},   //BBS3
    //0xBF

    //0xC0
    {"CPY", &CPY, IMMEDIATE, &immediate_mode, 2}, 
    {"CMP", &CMP, ZERO_PAGE_INDEXED_INDIRECT,&zero_page_indexed_indirect_mode, 6}, 
    {"???", &NOP, IMPLIED, &implied_mode, 2},
    {"???", &XXX, IMPLIED, &implied_mode, 8}, 
    {"CPY", &CPY, ZERO_PAGE, &zero_page_mode, 3}, 
    {"CMP", &CMP, ZERO_PAGE, &zero_page_mode, 3},
    {"DEC", &DEC, ZERO_PAGE, &zero_page_mode, 5}, 
    {"???", &XXX, IMPLIED, &implied_mode, 5},   //SMB4
    {"INY", &INY, IMPLIED, &implied_mode, 2},
    {"CMP", &CMP, IMMEDIATE, &immediate_mode, 2}, 
    {"DEX", &DEX, IMPLIED, &implied_mode, 2}, 
    {"???", &XXX, IMPLIED, &implied_mode, 2},   //WAI
    {"CPY", &CPY, ABSOLUTE , &absolute_mode, 4}, 
    {"CMP", &CMP, ABSOLUTE , &absolute_mode, 4}, 
    {"DEC", &DEC, ABSOLUTE , &absolute_mode, 6},
    {"???", &XXX, IMPLIED, &implied_mode, 6},   //BBS5
    //0XCF

    //0xD0
    {"BNE", &BNE, PROGRAM_COUNTER_RELATIVE ,&program_counter_relative_mode, 2}, 
    {"CMP", &CMP, ZERO_PAGE_INDIRECT_INDEXED_Y,&zero_page_indirect_indexed_y, 5},
    {"CMP", &CMP, ZERO_PAGE_INDIRECT, &zero_page_indirect, 2},   //CMP
    {"???", &XXX, IMPLIED, &implied_mode, 8}, 
    {"???", &NOP, IMPLIED, &implied_mode, 4},
    {"CMP", &CMP, ZERO_PAGE_INDEXED_X,&zero_page_indexed_X, 4}, 
    {"DEC", &DEC, ZERO_PAGE_INDEXED_X,&zero_page_indexed_X, 6}, 
    {"???", &XXX, IMPLIED, &implied_mode, 6},       //SMB5
    {"CLD", &CLD, IMPLIED, &implied_mode, 2}, 
    {"CMP", &CMP, ABSOLUTE_INDEXED_Y,&absolute_indexed_y_mode, 4}, 
    {"PHX", &PHX, STACK, &stack_mode, 2},       //PHX
    {"???", &XXX, IMPLIED, &implied_mode, 7},   //STP
    {"???", &NOP, IMPLIED, &implied_mode, 4}, 
    {"CMP", &CMP, ABSOLUTE_INDEXED_X ,&absolute_indexed_x_mode, 4},
    {"DEC", &DEC, ABSOLUTE_INDEXED_X ,&absolute_indexed_x_mode, 7}, 
    {"???", &XXX, IMPLIED, &implied_mode, 7},   //BBS5
    //0xDF

    // 0xE0
    {"CPX", &CPX, IMMEDIATE, &immediate_mode, 2},
    {"SBC", &SBC, ZERO_PAGE_INDEXED_INDIRECT,&zero_page_indexed_indirect_mode, 6}, 
    {"???", &NOP, IMPLIED, &implied_mode, 2}, 
    {"???", &XXX, IMPLIED, &implied_mode, 8},
    {"CPX", &CPX, ZERO_PAGE, &zero_page_mode, 3}, 
    {"SBC", &SBC, ZERO_PAGE, &zero_page_mode, 3}, 
    {"INC", &INC, ZERO_PAGE, &zero_page_mode, 5},
    {"???", &XXX, IMPLIED, &implied_mode, 5},   //SMB6
    {"INX", &INX, IMPLIED, &implied_mode, 2}, 
    {"SBC", &SBC, IMMEDIATE, &immediate_mode, 2},
    {"NOP", &NOP, IMPLIED, &implied_mode, 2}, 
    {"???", &SBC, IMPLIED, &implied_mode, 4}, 
    {"CPX", &CPX, ABSOLUTE , &absolute_mode, 4},
    {"SBC", &SBC, ABSOLUTE , &absolute_mode, 4}, 
    {"INC", &INC, ABSOLUTE , &absolute_mode, 6}, 
    {"???", &XXX, IMPLIED, &implied_mode, 6},   //BBS6
    //0xEF

    //0XF0
    {"BEQ", &BEQ, PROGRAM_COUNTER_RELATIVE ,&program_counter_relative_mode, 2}, 
    {"SBC", &SBC, ZERO_PAGE_INDIRECT_INDEXED_Y,&zero_page_indirect_indexed_y, 5}, 
    {"SBC", &SBC, ZERO_PAGE_INDIRECT, &zero_page_indirect, 2},       //SBC
    {"???", &XXX, IMPLIED, &implied_mode, 8}, 
    {"???", &NOP, IMPLIED, &implied_mode, 4}, 
    {"SBC", &SBC, ZERO_PAGE_INDEXED_X,&zero_page_indexed_X, 4},
    {"INC", &INC, ZERO_PAGE_INDEXED_X,&zero_page_indexed_X, 6}, 
    {"???", &XXX, IMPLIED, &implied_mode, 6},   //SMB7
    {"SED", &SED, IMPLIED, &implied_mode, 2},
    {"SBC", &SBC, ABSOLUTE_INDEXED_Y,&absolute_indexed_y_mode, 4}, 
    {"PLX", &PLX, STACK, &stack_mode, 2},       //PLX
    {"???", &XXX, IMPLIED, &implied_mode, 7},
    {"???", &NOP, IMPLIED, &implied_mode, 4}, 
    {"SBC", &SBC, ABSOLUTE_INDEXED_X ,&absolute_indexed_x_mode, 4}, 
    {"INC", &INC, ABSOLUTE_INDEXED_X ,&absolute_indexed_x_mode, 7},
    {"???", &XXX, IMPLIED, &implied_mode, 7}    //BBS7
    // 0xFF

};





void branch(cpu_6502_t* cpu_6502) {
    int8_t offset = fetch_next_byte(cpu_6502);
    cpu_6502->registers.PC_reg  += offset;     
}



// Absolute mode(A)
uint16_t absolute_mode(cpu_6502_t* cpu_6502) {
    uint8_t addr_lower = fetch_next_byte(cpu_6502);
    uint8_t addr_higher = fetch_next_byte(cpu_6502);
    return addr_higher << 8 | addr_lower;

};


// Absolute indexed indirexct:(a, x)
uint16_t absolute_indexed_indirect_mode(cpu_6502_t* cpu_6502) {
    // Fetch the base address from the next two bytes in memory
    uint16_t base_address = fetch_next_byte(cpu_6502) | (fetch_next_byte(cpu_6502) << 8);

    // Add the value in the X register to compute the indirect address
    uint16_t indirect_address = base_address + cpu_6502->registers.X_reg;

    // Fetch the effective address from the indirect address in memory
    uint16_t effective_address = cpu_6502->ram[indirect_address] |
                                (cpu_6502->ram[indirect_address + 1] << 8);

    // Update the Program Counter to the effective address
    // cpu_6502->registers.PC_reg = effective_address;

    return effective_address;
}

// Absolute Indexed with X:  a,x
uint16_t absolute_indexed_x_mode(cpu_6502_t* cpu_6502) {
    uint8_t addr_lower = fetch_next_byte(cpu_6502);
    uint8_t addr_higher = fetch_next_byte(cpu_6502);

    return (((addr_higher << 8) | addr_lower) + cpu_6502->registers.X_reg);

};


// Absolute Indexed with Y:  a,y
uint16_t absolute_indexed_y_mode(cpu_6502_t* cpu_6502) {
    uint8_t addr_lower = fetch_next_byte(cpu_6502);
    uint8_t addr_higher = fetch_next_byte(cpu_6502);

    return (((addr_higher << 8) | addr_lower) + cpu_6502->registers.Y_reg);

};

// Absoulte indirect(a)
uint16_t absolute_indirect_mode(cpu_6502_t* cpu_6502) {
    uint8_t addr_lower = fetch_next_byte(cpu_6502);
    uint8_t addr_higher = fetch_next_byte(cpu_6502);
    cpu_6502->registers.PC_reg = addr_higher << 8 | addr_lower; 
    return 0;

}
// Accumulator A
uint16_t accumulator_mode(cpu_6502_t* cpu_6502){
        return cpu_6502->registers.A_reg;
}

//  Immediate Addressing  #
uint16_t immediate_mode(cpu_6502_t* cpu_6502) {
    return 0;
}

// Implied I
uint16_t implied_mode(cpu_6502_t* cpu_6502) {
    return 0;
}

// Relative addressing r
uint16_t program_counter_relative_mode(cpu_6502_t* cpu_6502){
    // offset is added to the pc and returned
    uint8_t offset = fetch_next_byte(cpu_6502);
    uint16_t effective_address = cpu_6502->registers.PC_reg + offset;
    return effective_address;


};

// Stack s
uint16_t stack_mode(cpu_6502_t* cpu_6502) {
    return 0;
}

// Zero Page zp
uint16_t zero_page_mode(cpu_6502_t* cpu_6502) {
    uint16_t fetched_byte = fetch_next_byte(cpu_6502);
    printf("ZERO MODE RETURNED: %4X", (fetched_byte & 0x00FF));
    return (fetched_byte & 0x00FF);

}

// Zero Page Indexed Indirect (zp, x)
uint16_t zero_page_indexed_indirect_mode(cpu_6502_t* cpu_6502) {
    uint16_t zero_page_address = fetch_next_byte(cpu_6502);
    uint16_t indirect_address = zero_page_address + cpu_6502->registers.X_reg;
    uint16_t effective_address = cpu_6502->ram[indirect_address];
    return effective_address;
}

// Zero page indexed with X zp,x
uint16_t zero_page_indexed_X(cpu_6502_t* cpu_6502) {
    uint8_t zero_page_lower = fetch_next_byte(cpu_6502);
    return (zero_page_lower + cpu_6502->registers.X_reg);


}
// Zero page indexed with Y zp,y
uint16_t zero_page_indexed_Y(cpu_6502_t* cpu_6502) {
    uint8_t zero_page_lower = fetch_next_byte(cpu_6502);
    return (zero_page_lower + cpu_6502->registers.Y_reg);

}

//Zero page indirect (zp)
uint16_t zero_page_indirect(cpu_6502_t* cpu_6502) {
    return fetch_next_byte(cpu_6502);

}

// Zero page indirect indexed with y: (zp),y
uint16_t zero_page_indirect_indexed_y(cpu_6502_t* cpu_6502) {
    uint16_t indirect_base_address = fetch_next_byte(cpu_6502);
    uint16_t effective_address = cpu_6502->ram[indirect_base_address] + cpu_6502->registers.Y_reg;
    return effective_address;

};





// Instructions


// // UNKNOWN OPCODES

void XXX(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup){
    return;
};





void ADC(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    // A =  A + memory + C
    
    uint8_t value;
    if(selected_lookup->addr_mode == IMMEDIATE) {
        value = fetch_next_byte(cpu_6502);
    }else {

    uint16_t memory_addr = selected_lookup->op_mode(cpu_6502);
    value = cpu_6502->ram[memory_addr];
    }
    uint8_t carry = (cpu_6502->registers.status_regs & STATUS_CARRY) ? 1 : 0;
    uint16_t  adc_sum = cpu_6502->registers.A_reg + value + carry;
    //set carry flag
    if(adc_sum > 0xFF) {
        cpu_6502->registers.status_regs |= STATUS_CARRY;
    }else{
        cpu_6502->registers.status_regs &= ~STATUS_CARRY;
    }
    if (adc_sum & 0x0080) {
        cpu_6502->registers.status_regs |= STATUS_NEGATIVE;
    } else {
        cpu_6502->registers.status_regs &= ~STATUS_NEGATIVE;
    }
    //set overflow
    bool overflow = (~(cpu_6502->registers.A_reg ^ value) & (cpu_6502->registers.A_reg ^ (adc_sum & 0xFF)) & 0x80) != 0;
    if (overflow) {
        cpu_6502->registers.status_regs |= STATUS_OVERFLOW;
    } else {
        cpu_6502->registers.status_regs &= ~STATUS_OVERFLOW;
    }

    cpu_6502->registers.A_reg = adc_sum & 0xFF;

}


void AND(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    // A = A & memory
    //absolute, immediate
    uint8_t value;
    if(selected_lookup->addr_mode == IMMEDIATE){
        value = fetch_next_byte(cpu_6502);
    }else{
        uint16_t memory_addr = selected_lookup->op_mode(cpu_6502);
        value = cpu_6502->ram[memory_addr];
    }
    cpu_6502->registers.A_reg &= value;
    
}

void ASL(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup){
    // Shifts to the left by 1 byte: memory or accumulator
    if (selected_lookup->addr_mode == ACCUMULATOR) {
        // Save the previous MSB (bit 7) for the carry flag
        bool carry = cpu_6502->registers.A_reg & 0x80;

        // Shift the accumulator left by 1 bit
        cpu_6502->registers.A_reg <<= 1;

        // Update the carry flag (bit 7 of the accumulator before the shift)
        if (carry) {
            cpu_6502->registers.status_regs |= STATUS_CARRY;
        } else {
            cpu_6502->registers.status_regs &= ~STATUS_CARRY;
        }

        // Update the zero flag (set if result is zero)
        if (cpu_6502->registers.A_reg == 0) {
            cpu_6502->registers.status_regs |= STATUS_ZERO;
        } else {
            cpu_6502->registers.status_regs &= ~STATUS_ZERO;
        }

    } else {
        uint16_t memory_addr = selected_lookup->op_mode(cpu_6502);
        
        // Get the value from memory
        uint8_t value = cpu_6502->ram[memory_addr];
        
        // Save the previous MSB (bit 7) for the carry flag
        bool carry = value & 0x80;

        // Shift the value in memory left by 1 bit
        value <<= 1;

        // Update the carry flag (bit 7 of the value before the shift)
        if (carry) {
            cpu_6502->registers.status_regs |= STATUS_CARRY;
        } else {
            cpu_6502->registers.status_regs &= ~STATUS_CARRY;
        }

        // Update the zero flag (set if result is zero)
        if (value == 0) {
            cpu_6502->registers.status_regs |= STATUS_ZERO;
        } else {
            cpu_6502->registers.status_regs &= ~STATUS_ZERO;
        }

        // Store the updated value back in memory
        cpu_6502->ram[memory_addr] = value;
    }
}
// BCC - Branch if Carry Clear
void BCC(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    //  PC = PC + 2 + memory(signed)
    if((cpu_6502->registers.status_regs & STATUS_CARRY) == 0) {
        // carry flag is set 
        branch(cpu_6502);     
        return;
    }
    cpu_6502->registers.PC_reg++;

}

// BCS - Branch if Carry Set
void BCS(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    //  PC = PC + 2 + memory(signed)
    if((cpu_6502->registers.status_regs & STATUS_CARRY) == 1) {
        // carry flag is set 
        branch(cpu_6502);     
        return;
    }
    cpu_6502->registers.PC_reg++;

}


// BEQ = Branch if Equal
void BEQ(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    // if zero flag is set, branch
    if(cpu_6502->registers.status_regs & STATUS_ZERO) {
        //branch
        branch(cpu_6502);     
        return;
    }
    cpu_6502->registers.PC_reg++;

}

// BIT - Bit test
void BIT(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    // does not change memorty but flags
    //A & memory
    uint8_t operand;
    if(selected_lookup->addr_mode == IMMEDIATE){
        operand = fetch_next_byte(cpu_6502);
    }else{
        uint16_t memory_address = selected_lookup->op_mode(cpu_6502);
        operand = cpu_6502->ram[memory_address];
    }

    uint8_t result = cpu_6502->registers.A_reg & operand;
    //update zero flag if zero
    cpu_6502->registers.status_regs = (cpu_6502->registers.status_regs & ~STATUS_ZERO) | (result == 0 ? STATUS_ZERO : 0);

    //update the negative and overflow flags 
    cpu_6502->registers.status_regs = (cpu_6502->registers.status_regs &  ~(STATUS_NEGATIVE | STATUS_OVERFLOW)) | (operand & (STATUS_NEGATIVE | STATUS_OVERFLOW));

}


// BMI - Branch if Minus
void BMI(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    // if negative flag is set BMI branches to nearby offset of pC
    // uint16_t memory_address = selected_lookup->op_mode();
    if(cpu_6502->registers.status_regs & STATUS_NEGATIVE) {
          branch(cpu_6502);     
        return;
    }
    cpu_6502->registers.PC_reg++;
}


//BNE - Branch If not equal
void BNE(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
// if zero flag is clear, branch
    if(!(cpu_6502->registers.status_regs & STATUS_ZERO)) {
          branch(cpu_6502);     
        return;
    }   
    cpu_6502->registers.PC_reg++;

}

// BPL - Branch if Plus    uint8_t operand;


void BPL(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    // If negativity is clear
        if(!(cpu_6502->registers.status_regs & STATUS_NEGATIVE)) {
          branch(cpu_6502);     
        return;
    }
    cpu_6502->registers.PC_reg++;
} 

// BRK - BReak(software IRQ)
void BRK(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {

};

// BVC - branch if overflow clear
void BVC(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    //if overflow flag is clear, branch
    if(!(cpu_6502->registers.status_regs & STATUS_OVERFLOW)) {
        branch(cpu_6502);     
        return;
    }
    cpu_6502->registers.PC_reg++;

}

// BVS - Branch if overflow set
void BVS(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    //if overflow is set, branch
        if(cpu_6502->registers.status_regs & STATUS_OVERFLOW) {
        branch(cpu_6502);     
        return;
    }
    cpu_6502->registers.PC_reg++;

}


// CLC - Clear Carry
void CLC(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    // clears the carry flag
    cpu_6502->registers.status_regs &= (~STATUS_CARRY);

}

// CLD- Clear decimal 
void CLD(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    // clears the carry flag
    cpu_6502->registers.status_regs &= (~STATUS_DECIMAL);

}

//CLI - Clear Interrupt Disable
void CLI(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    // clears the carry flag
    cpu_6502->registers.status_regs &= (~STATUS_IRQB_DISABLE);

}

// CLV - Clear Overflow
void CLV(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    // clears the carry flag
    cpu_6502->registers.status_regs &= (~STATUS_OVERFLOW);

}

// CMP - Compare A 
void CMP(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    //compares accumulator with memory setting the flags: A - Memory 
    uint16_t memory_address = selected_lookup->op_mode(cpu_6502);
    uint8_t operand = cpu_6502->ram[memory_address];
    uint8_t diff = cpu_6502->registers.A_reg - cpu_6502->ram[memory_address];

    //set zero flag
    cpu_6502->registers.status_regs = (cpu_6502->registers.status_regs & ~STATUS_ZERO) | (diff == 0 ? STATUS_ZERO : 0);

    //set negative flag
    cpu_6502->registers.status_regs = (cpu_6502->registers.status_regs & ~STATUS_NEGATIVE) | (diff & 0x80 ? STATUS_NEGATIVE : 0);

      // Update the Carry flag: Set if A >= operand (no borrow)
     cpu_6502->registers.status_regs = 
        (cpu_6502->registers.status_regs & ~STATUS_CARRY) | (cpu_6502->registers.A_reg >= operand ? STATUS_CARRY : 0);

}
//  ////
// CPX- compare x
void CPX(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    uint16_t memory_address = selected_lookup->op_mode(cpu_6502);
    uint8_t operand = cpu_6502->ram[memory_address];
    uint8_t diff = cpu_6502->registers.X_reg - cpu_6502->ram[memory_address];

    //set zero flag
    cpu_6502->registers.status_regs = (cpu_6502->registers.status_regs & ~STATUS_ZERO) | (diff == 0 ? STATUS_ZERO : 0);

    //set negative flag
    cpu_6502->registers.status_regs = (cpu_6502->registers.status_regs & ~STATUS_NEGATIVE) | (diff & 0x80 ? STATUS_NEGATIVE : 0);

      // Update the Carry flag: Set if A >= operand (no borrow)
     cpu_6502->registers.status_regs = 
        (cpu_6502->registers.status_regs & ~STATUS_CARRY) | (cpu_6502->registers.X_reg >= operand ? STATUS_CARRY : 0);
}

//CPY - compare Y 
void CPY(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    uint16_t memory_address = selected_lookup->op_mode(cpu_6502);
    uint8_t operand = cpu_6502->ram[memory_address];
    uint8_t diff = cpu_6502->registers.Y_reg - cpu_6502->ram[memory_address];

    //set zero flag
    cpu_6502->registers.status_regs = (cpu_6502->registers.status_regs & ~STATUS_ZERO) | (diff == 0 ? STATUS_ZERO : 0);

    //set negative flag
    cpu_6502->registers.status_regs = (cpu_6502->registers.status_regs & ~STATUS_NEGATIVE) | (diff & 0x80 ? STATUS_NEGATIVE : 0);

      // Update the Carry flag: Set if A >= operand (no borrow)
     cpu_6502->registers.status_regs = 
        (cpu_6502->registers.status_regs & ~STATUS_CARRY) | (cpu_6502->registers.Y_reg >= operand ? STATUS_CARRY : 0);
}

// DEC - decrement Memory 
void DEC(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    uint8_t result;
    
    if(selected_lookup->addr_mode == ACCUMULATOR){
        result = --cpu_6502->registers.A_reg;
    }else{
        uint16_t memory_address = selected_lookup->op_mode(cpu_6502);
        result = --cpu_6502->ram[memory_address];
    }
    
    //Update zero flag
    cpu_6502->registers.status_regs = 
        (cpu_6502->registers.status_regs & ~STATUS_ZERO) | (result == 0 ? STATUS_ZERO : 0);

    //Update negative flag
    cpu_6502->registers.status_regs = 
        (cpu_6502->registers.status_regs & ~STATUS_NEGATIVE) | (result & 0x80 ? STATUS_NEGATIVE : 0);
}

//DEX - decremet x
void DEX(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    uint8_t result = --cpu_6502->registers.X_reg;
    
    //Update zero flag
    cpu_6502->registers.status_regs = 
        (cpu_6502->registers.status_regs & ~STATUS_ZERO) | (result == 0 ? STATUS_ZERO : 0);

    //Update negative flag
    cpu_6502->registers.status_regs = 
        (cpu_6502->registers.status_regs & ~STATUS_NEGATIVE) | (result & 0x80 ? STATUS_NEGATIVE : 0);
}

// DEY - decrement Y
void DEY(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    uint8_t result = --cpu_6502->registers.Y_reg;
    
    //Update zero flag
    cpu_6502->registers.status_regs = 
        (cpu_6502->registers.status_regs & ~STATUS_ZERO) | (result == 0 ? STATUS_ZERO : 0);

    //Update negative flag
    cpu_6502->registers.status_regs = 
        (cpu_6502->registers.status_regs & ~STATUS_NEGATIVE) | (result & 0x80 ? STATUS_NEGATIVE : 0);
}

// EOR - Bitwise Exclusive OR
void EOR(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    //  A= A ^ Memory
    uint8_t operand;
    if(selected_lookup->addr_mode == IMMEDIATE){
        operand = fetch_next_byte(cpu_6502);

    }else{
        uint16_t memory_address = selected_lookup->op_mode(cpu_6502);
        operand = cpu_6502->ram[memory_address];
    }
    uint8_t result = cpu_6502->registers.A_reg ^ operand;
    cpu_6502->registers.A_reg = result;
    // set zero flag
    cpu_6502->registers.status_regs = 
        (cpu_6502->registers.status_regs & ~STATUS_ZERO) | (result == 0 ? STATUS_ZERO : 0);

    // negative zero flag
     cpu_6502->registers.status_regs = 
        (cpu_6502->registers.status_regs & ~STATUS_NEGATIVE) | (result & 0x80 ? STATUS_NEGATIVE : 0);

}

// INC - Increment Memory
void INC(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    uint8_t result;
    if(selected_lookup->addr_mode == ACCUMULATOR){
       result = cpu_6502->registers.A_reg++;
        
    }else{
        uint16_t memory_address = selected_lookup->op_mode(cpu_6502);
        result = ++cpu_6502->ram[memory_address];
    }
    
    //Update zero flag
    cpu_6502->registers.status_regs = 
        (cpu_6502->registers.status_regs & ~STATUS_ZERO) | (result == 0 ? STATUS_ZERO : 0);

    //Update negative flag
    cpu_6502->registers.status_regs = 
        (cpu_6502->registers.status_regs & ~STATUS_NEGATIVE) | (result & 0x80 ? STATUS_NEGATIVE : 0);
}

// INX - Increment X
void INX(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    uint8_t result = ++cpu_6502->registers.X_reg;
    
    //Update zero flag
    cpu_6502->registers.status_regs = 
        (cpu_6502->registers.status_regs & ~STATUS_ZERO) | (result == 0 ? STATUS_ZERO : 0);

    //Update negative flag
    cpu_6502->registers.status_regs = 
        (cpu_6502->registers.status_regs & ~STATUS_NEGATIVE) | (result & 0x80 ? STATUS_NEGATIVE : 0);
}

// INY - Increment Y
void INY(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    uint8_t result = ++cpu_6502->registers.Y_reg;
    
    //Update zero flag
    cpu_6502->registers.status_regs = 
        (cpu_6502->registers.status_regs & ~STATUS_ZERO) | (result == 0 ? STATUS_ZERO : 0);

    //Update negative flag
    cpu_6502->registers.status_regs = 
        (cpu_6502->registers.status_regs & ~STATUS_NEGATIVE) | (result & 0x80 ? STATUS_NEGATIVE : 0);
}


void JMP(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    // Get the effective address from the addressing mode
    // if(selected_lookup->addr_mode == ABSOLUTE){
    //     effective_address = 
    // }
    uint16_t effective_address = selected_lookup->op_mode(cpu_6502);

    // If the address is greater than or equal to ROM_START, it's already in the ROM space
    if (effective_address >= ROM_START) {
        printf("IF stat, Addr: %04X, Value: %02X", effective_address, cpu_6502->ram[effective_address]);
        cpu_6502->registers.PC_reg = effective_address;
    }
    // Otherwise, adjust the address to be in the ROM space
    else {
        printf("else stat, Addr: %04X, Value: %02X", (ROM_START + effective_address), cpu_6502->ram[(ROM_START + effective_address)]);

        cpu_6502->registers.PC_reg = ROM_START + effective_address;
    }
}

// // JMP - Jump
// void JMP(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
//     // PC  = memory
//     uint16_t memory_address = selected_lookup->op_mode(cpu_6502); 
//     uint16_t to_jump_mem = ROM_START + memory_address;
//     printf("IN JMP: PC is set to %4X", to_jump_mem);
//     cpu_6502->registers.PC_reg =   to_jump_mem;
    
// }

//  JSR - Jump to subroutine 
void JSR(cpu_6502_t* cpu_6502, struct instruction_t* selectect_lookup) {
    // push PC + 2 to the stack
    // pc = memory
    uint16_t memory_address = selectect_lookup->op_mode(cpu_6502);
    //push pc
    // cpu_6502->registers.PC_reg += 2;        //two bytes after jsr
    cpu_6502->stack[cpu_6502->registers.SP_reg--] = ((cpu_6502->registers.PC_reg) & 0xFF);     //push low byte
    cpu_6502->stack[cpu_6502->registers.SP_reg--] = (((cpu_6502->registers.PC_reg) & 0xFF00) >> 8);     //push upper byte


    cpu_6502->registers.PC_reg = ROM_START + memory_address;


}


//LDA - Load A
void LDA(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    // loads memory into accumulator
    uint8_t result;
    if(selected_lookup->addr_mode == IMMEDIATE)
    {
        result = fetch_next_byte(cpu_6502);
    }else {
        uint16_t memory_address = selected_lookup->op_mode(cpu_6502);
        result = cpu_6502->ram[memory_address];
    }
    cpu_6502->registers.A_reg = result;
    
        //Update zero flag    if

    cpu_6502->registers.status_regs = 
        (cpu_6502->registers.status_regs & ~STATUS_ZERO) | (result == 0 ? STATUS_ZERO : 0);

    //Update negative flag
    cpu_6502->registers.status_regs = 
        (cpu_6502->registers.status_regs & ~STATUS_NEGATIVE) | (result & 0x80 ? STATUS_NEGATIVE : 0);
}

// LDX -load x
void LDX(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    // loads memory into accumulator
    uint8_t result;
    if(selected_lookup->addr_mode == IMMEDIATE)
    {
        result = fetch_next_byte(cpu_6502);
    } else {
        uint16_t memory_address = selected_lookup->op_mode(cpu_6502);
        result = cpu_6502->ram[memory_address];
    }
    cpu_6502->registers.X_reg = result;
    
        //Update zero flag
    cpu_6502->registers.status_regs = 
        (cpu_6502->registers.status_regs & ~STATUS_ZERO) | (result == 0 ? STATUS_ZERO : 0);

    //Update negative flag
    cpu_6502->registers.status_regs = 
        (cpu_6502->registers.status_regs & ~STATUS_NEGATIVE) | (result & 0x80 ? STATUS_NEGATIVE : 0);
}

// LDY - load Y
void LDY(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    // loads memory into accumulator
    uint8_t result;
    if(selected_lookup->addr_mode == IMMEDIATE){
        result = fetch_next_byte(cpu_6502);
    } else {
        uint16_t memory_address = selected_lookup->op_mode(cpu_6502);
        result = cpu_6502->ram[memory_address];
    }
    cpu_6502->registers.Y_reg = result;
    
        //Update zero flag
    cpu_6502->registers.status_regs = 
        (cpu_6502->registers.status_regs & ~STATUS_ZERO) | (result == 0 ? STATUS_ZERO : 0);

    //Update negative flag
    cpu_6502->registers.status_regs = 
        (cpu_6502->registers.status_regs & ~STATUS_NEGATIVE) | (result & 0x80 ? STATUS_NEGATIVE : 0);
}

// LSR - logical shift Right
void LSR(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {

    uint8_t value;

    if(selected_lookup->addr_mode == ACCUMULATOR)
    {
        value = cpu_6502->registers.A_reg >> 1;
        cpu_6502->registers.A_reg = value;
        
    }else {
        // Fetch the memory address from the instruction's operand mode
        uint16_t memory_address = selected_lookup->op_mode(cpu_6502);
        // Fetch the value from memory and calculate the result of the shift
        value = cpu_6502->ram[memory_address];
        // Set the Carry flag to the original bit 0 before shifting

        cpu_6502->registers.status_regs = 
            (cpu_6502->registers.status_regs & ~STATUS_CARRY) | (value & 0x01 ? STATUS_CARRY : 0);
        // Perform the logical shift right
        value >>= 1;
        cpu_6502->ram[memory_address] = value;  // Store the result back in memory
    }

    // Set the Zero flag if the result is zero
    cpu_6502->registers.status_regs = 
        (cpu_6502->registers.status_regs & ~STATUS_ZERO) | (value == 0 ? STATUS_ZERO : 0);

    // Clear the Negative flag as LSR cannot produce a negative result
    cpu_6502->registers.status_regs &= ~STATUS_NEGATIVE;
}


void NOP(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    return;
}

void ORA(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup){ 
    //  A = A | memory
    uint16_t memory_addr =  (selected_lookup->op_mode)(cpu_6502);
    uint8_t result = cpu_6502->registers.A_reg | cpu_6502->ram[memory_addr];
    cpu_6502->registers.A_reg = result;
    // Set the Zero flag if the result is zero
    cpu_6502->registers.status_regs = 
        (cpu_6502->registers.status_regs & ~STATUS_ZERO) | (result == 0 ? STATUS_ZERO : 0);

    // Clear the Negative flag as LSR cannot produce a negative result
    cpu_6502->registers.status_regs &= ~STATUS_NEGATIVE;

}

// PHA- push A 
void PHA(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    // pushes the A to the stack and decrements SP
    cpu_6502->stack[cpu_6502->registers.SP_reg--] = cpu_6502->registers.A_reg;

} 

// PHP - push processor status
void PHP(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    // ($0100 + SP) = NV11DIZC

    cpu_6502->stack[cpu_6502->registers.SP_reg--] = (cpu_6502->registers.status_regs | 0x30);

}

// PLA- Pull A 
void PLA(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    cpu_6502->registers.A_reg = cpu_6502->stack[++cpu_6502->registers.SP_reg];

    // Update the Zero flag if the accumulator is zero
    cpu_6502->registers.status_regs = 
        (cpu_6502->registers.status_regs & ~STATUS_ZERO) | 
        (cpu_6502->registers.A_reg == 0 ? STATUS_ZERO : 0);

    // Update the Negative flag based on the sign bit of the accumulator
    cpu_6502->registers.status_regs = 
        (cpu_6502->registers.status_regs & ~STATUS_NEGATIVE) | 
        (cpu_6502->registers.A_reg & 0x80 ? STATUS_NEGATIVE : 0);


}

// PLP - Pull Processor Status
void PLP(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    uint8_t pulled_status_flags = cpu_6502->stack[++cpu_6502->registers.SP_reg];
    cpu_6502->registers.status_regs = 
    (cpu_6502->registers.status_regs & 0x30) |(pulled_status_flags & 0xCF);      

}


// ROL - Rotate Left
void ROL(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    // carry -> bit 0
    //bit 7 -> carry

    int8_t value;
    bool carry_flag_status = (cpu_6502->registers.status_regs & STATUS_CARRY) ? 1 : 0;
    if(selected_lookup->addr_mode == ACCUMULATOR)
    {
        value = cpu_6502->registers.A_reg;
        //set carry flag to bit 7
        cpu_6502->registers.status_regs = (cpu_6502->registers.status_regs & ~STATUS_CARRY) |
                                        ((value & 0x80) ? STATUS_CARRY : 0);
        value <<= 1;
        //set  bit 0 to carry
        value = value | (carry_flag_status ? 0x1 : 0);
        cpu_6502->registers.A_reg = value;
    } else {
        uint16_t mem_addr = selected_lookup->op_mode(cpu_6502);
        value = cpu_6502->ram[mem_addr]; 
            //set carry flag to bit 0
        cpu_6502->registers.status_regs = (cpu_6502->registers.status_regs & ~STATUS_CARRY) |
                                        ((value & 0x80) ? STATUS_CARRY : 0);
        value <<= 1;
        value = value | (carry_flag_status ? 0x1 : 0);
        cpu_6502->ram[mem_addr] = value;


    }



}

// ROR- Rotate Right
void ROR(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    int8_t value;
    bool carry_flag_status = (cpu_6502->registers.status_regs & STATUS_CARRY) ? 1 : 0;
    if(selected_lookup->addr_mode == ACCUMULATOR)
    {
        value = cpu_6502->registers.A_reg;
        //set carry flag to bit 0
        cpu_6502->registers.status_regs = (cpu_6502->registers.status_regs & ~STATUS_CARRY) |
                                        ((value & 0x1) ? STATUS_CARRY : 0);
        value >>= 1;
        //set  bit 7 to carry
        value = value | (carry_flag_status ? 0x80 : 0);
        cpu_6502->registers.A_reg = value;
    } else {
        uint16_t mem_addr = selected_lookup->op_mode(cpu_6502);
        value = cpu_6502->ram[mem_addr]; 
            //set carry flag to bit 0
        cpu_6502->registers.status_regs = (cpu_6502->registers.status_regs & ~STATUS_CARRY) |
                                        ((value & 0x1) ? STATUS_CARRY : 0);
        value >>= 1;
        value = value | (carry_flag_status ? 0x80 : 0);
        cpu_6502->ram[mem_addr] = value;


    }


}


// Return from Interrupt 
void RTI(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {

}


//TODO;
//RTS - Return from Subroutine
void RTS(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    //pulls PC from the stack, increments PC
    // cpu_6502->registers.SP_reg = cpu_6502->ram[++cpu_6502->registers.SP_reg];
    cpu_6502->registers.SP_reg++;
    uint8_t high_byte = cpu_6502->stack[cpu_6502->registers.SP_reg];

    // increment sp again
    cpu_6502->registers.SP_reg++;
    uint8_t low_byte = cpu_6502->stack[cpu_6502->registers.SP_reg];
    uint16_t address_to_jump = (high_byte << 8) | low_byte;

    cpu_6502->registers.PC_reg =  address_to_jump ;
    
}


// SBC - Subtract with Carry
void SBC(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    // A = A - momory - ~C or  A = A + ~memory + C
  // Fetch the operand value from memory (based on the addressing mode)
    uint16_t memory = selected_lookup->op_mode(cpu_6502);
    uint8_t operand = cpu_6502->ram[memory];

    // Perform the subtraction with carry:
    // A = A - memory - (1 - carry) --> A = A - memory - (1 if no carry, 0 if carry)
    uint8_t result = cpu_6502->registers.A_reg - operand - (cpu_6502->registers.status_regs & STATUS_CARRY ? 0 : 1);

    // Set the carry flag: if there's no borrow (A >= operand + borrow), set carry to 1
    cpu_6502->registers.status_regs = (cpu_6502->registers.status_regs & ~STATUS_CARRY) | (cpu_6502->registers.A_reg >= operand + (cpu_6502->registers.status_regs & STATUS_CARRY ? 0 : 1) ? STATUS_CARRY : 0);

    // Set the Zero flag if the result is zero
    cpu_6502->registers.status_regs = (cpu_6502->registers.status_regs & ~STATUS_ZERO) | (result == 0 ? STATUS_ZERO : 0);

    // Set the Negative flag based on bit 7 of the result
    cpu_6502->registers.status_regs = (cpu_6502->registers.status_regs & ~STATUS_NEGATIVE) | (result & 0x80 ? STATUS_NEGATIVE : 0);

    // Set the Overflow flag based on signed overflow (subtraction)
    // Overflow occurs if the signs of A and operand differ, but the result sign is wrong
    cpu_6502->registers.status_regs = (cpu_6502->registers.status_regs & ~STATUS_OVERFLOW) | 
        (((cpu_6502->registers.A_reg ^ operand) & 0x80) && ((cpu_6502->registers.A_reg ^ result) & 0x80) ? STATUS_OVERFLOW : 0);

    // Store the result back into the accumulator
    cpu_6502->registers.A_reg = result;
}

// SEC - Set Carry
void SEC(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    cpu_6502->registers.status_regs |= STATUS_CARRY;

}

// SED - Set Decimal
void SED(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    cpu_6502->registers.status_regs |= STATUS_DECIMAL ;
    
}

// SEI - Set Interrupt Disable
void SEI(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    cpu_6502->registers.status_regs |= STATUS_IRQB_DISABLE;

}

// STA - Store A
void STA(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    // Memory = A
    uint16_t memory_address = selected_lookup->op_mode(cpu_6502);
    cpu_6502->ram[memory_address] = cpu_6502->registers.A_reg;
}

// STX- Store X
void STX(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    // Memory = X
    uint16_t memory_address = selected_lookup->op_mode(cpu_6502);
    cpu_6502->ram[memory_address] = cpu_6502->registers.X_reg;
}

// STY - Store Y
void STY(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    // Memory = Y
    uint16_t memory_address = selected_lookup->op_mode(cpu_6502);
    cpu_6502->ram[memory_address] = cpu_6502->registers.Y_reg;
}

// TAX - Transfer A to X
void TAX(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    // X = A
    uint8_t result = cpu_6502->registers.A_reg;
    cpu_6502->registers.X_reg = result;

       // Set the Zero flag if the result is zero
    cpu_6502->registers.status_regs = 
        (cpu_6502->registers.status_regs & ~STATUS_ZERO) | (result == 0 ? STATUS_ZERO : 0);

    // Set the negative flag based on bit 7 of result
    cpu_6502->registers.status_regs = (cpu_6502->registers.status_regs & ~STATUS_NEGATIVE) | (result & 0x80 ? STATUS_NEGATIVE : 0);

    
}

// TAY - Transfer A to Y
void TAY(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    // Y = A
    uint8_t result = cpu_6502->registers.A_reg;
    cpu_6502->registers.Y_reg = result;

       // Set the Zero flag if the result is zero
    cpu_6502->registers.status_regs = 
        (cpu_6502->registers.status_regs & ~STATUS_ZERO) | (result == 0 ? STATUS_ZERO : 0);

    // Set the negative flag based on bit 7 of result
    cpu_6502->registers.status_regs = (cpu_6502->registers.status_regs & ~STATUS_NEGATIVE) | (result & 0x80 ? STATUS_NEGATIVE : 0);

    
}

// TSX - Transfer Stack pointer to X
void TSX(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    // X = SP
    uint8_t result = cpu_6502->registers.SP_reg;
    cpu_6502->registers.X_reg = result;

       // Set the Zero flag if the result is zero
    cpu_6502->registers.status_regs = 
        (cpu_6502->registers.status_regs & ~STATUS_ZERO) | (result == 0 ? STATUS_ZERO : 0);

    // Set the negative flag based on bit 7 of result
    cpu_6502->registers.status_regs = (cpu_6502->registers.status_regs & ~STATUS_NEGATIVE) | (result & 0x80 ? STATUS_NEGATIVE : 0);

    
}

// TXA - Transfer X to A
void TXA(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    // A = X
    uint8_t result = cpu_6502->registers.X_reg;
    cpu_6502->registers.A_reg = result;

       // Set the Zero flag if the result is zero
    cpu_6502->registers.status_regs = 
        (cpu_6502->registers.status_regs & ~STATUS_ZERO) | (result == 0 ? STATUS_ZERO : 0);

    // Set the negative flag based on bit 7 of result
    cpu_6502->registers.status_regs = (cpu_6502->registers.status_regs & ~STATUS_NEGATIVE) | (result & 0x80 ? STATUS_NEGATIVE : 0);

    
}


// TXS - Transfer X to SP
void TXS(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    // SP = X
    uint8_t result = cpu_6502->registers.X_reg;
    cpu_6502->registers.SP_reg = result;

       // Set the Zero flag if the result is zero
    cpu_6502->registers.status_regs = 
        (cpu_6502->registers.status_regs & ~STATUS_ZERO) | (result == 0 ? STATUS_ZERO : 0);

    // Set the negative flag based on bit 7 of result
    cpu_6502->registers.status_regs = (cpu_6502->registers.status_regs & ~STATUS_NEGATIVE) | (result & 0x80 ? STATUS_NEGATIVE : 0);

    
}

// TYA - Transfer Y to a
void TYA(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    // A = Y
    uint8_t result = cpu_6502->registers.Y_reg;
    cpu_6502->registers.A_reg    = result;

       // Set the Zero flag if the result is zero
    cpu_6502->registers.status_regs = 
        (cpu_6502->registers.status_regs & ~STATUS_ZERO) | (result == 0 ? STATUS_ZERO : 0);

    // Set the negative flag based on bit 7 of result
    cpu_6502->registers.status_regs = (cpu_6502->registers.status_regs & ~STATUS_NEGATIVE) | (result & 0x80 ? STATUS_NEGATIVE : 0);

    
}



// PHY: push y register on stack
void PHY(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    cpu_6502->stack[cpu_6502->registers.SP_reg--] = cpu_6502->registers.Y_reg;

}

// PLY - Pull Y register from the stack
void PLY(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup){
    cpu_6502->registers.Y_reg = cpu_6502->stack[++cpu_6502->registers.SP_reg];

}

// PHX: push x register on stack
void PHX(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    cpu_6502->stack[cpu_6502->registers.SP_reg--] = cpu_6502->registers.X_reg;
}
// PLX = pull X register from the stack
void PLX(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    cpu_6502->registers.X_reg = cpu_6502->stack[++cpu_6502->registers.SP_reg];
}

// TSB - Test and set memory bit
void TSB(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
// A & M, only change the zero flag
//  M = A | M
// zero page mode or absolute
    uint16_t memory_address = selected_lookup->op_mode(cpu_6502);
    uint16_t memory_value = cpu_6502->ram[memory_address];
    //  updating zero flag  (A & M)
    cpu_6502->registers.status_regs = (cpu_6502->registers.status_regs & ~STATUS_ZERO) | ((memory_value & cpu_6502->registers.A_reg) == 0 ? STATUS_ZERO : 0);

    cpu_6502->ram[memory_address] = cpu_6502->registers.A_reg | memory_value;
}

// RMB = Reset memory bit
void RMB(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup){
// RMB0 = clears bit 0 of provided memory location and so on...
    uint8_t position_to_clear = (uint8_t)(selected_lookup->opcode[3] - '0');
    uint16_t memory_address = selected_lookup->op_mode(cpu_6502);
    cpu_6502->ram[memory_address] &= (~(1 << position_to_clear)); 


}
// TRB
void TRB(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    // Fetch the memory address
    uint16_t memory_address = selected_lookup->op_mode(cpu_6502);

    // Test: Calculate the Zero flag based on (A & memory)
    uint8_t memory_value = cpu_6502->ram[memory_address];
    cpu_6502->registers.status_regs = 
        (cpu_6502->registers.status_regs & ~STATUS_ZERO) | 
        ((cpu_6502->registers.A_reg & memory_value) == 0 ? STATUS_ZERO : 0);

    // Reset: Clear bits in memory that are set in the accumulator
    cpu_6502->ram[memory_address] &= ~(cpu_6502->registers.A_reg);
}

// STZ = Store zero in memory
void STZ(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup){
    uint16_t memory_address = selected_lookup->op_mode(cpu_6502);
    cpu_6502->ram[memory_address] = 0x00;
}

// BRA = branch always
void BRA(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup){
    //PC_relative_mode
    int8_t offset = fetch_next_byte(cpu_6502);
    cpu_6502->registers.PC_reg += offset;
}