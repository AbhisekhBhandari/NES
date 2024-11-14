#include "instruction.h"





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
uint16_t absolute_indexed_indirect_mode(cpu_6502_t* cpu_6502){

};

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
    return fetch_next_byte(cpu_6502);
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
    return fetch_next_byte(cpu_6502);

}

// Zero Page Indexed Indirect (zp, x)
uint16_t zero_page_indexed_indirect_mode(cpu_6502_t* cpu_6502) {
    uint8_t zero_page_lower = fetch_next_byte(cpu_6502);
    return (zero_page_lower + cpu_6502->registers.X_reg);
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
    uint16_t operand_address = indirect_base_address + cpu_6502->registers.Y_reg;

    return operand_address;

};





// Instructions


// // UNKNOWN OPCODES

void XXX(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup){
    return;
};





void ADC(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    // A =  A + memory + C
    
    uint16_t memory_addr = selected_lookup->op_mode(cpu_6502);
    uint8_t carry = (cpu_6502->registers.status_regs & STATUS_CARRY) ? 1 : 0;
    uint16_t  adc_sum = cpu_6502->registers.A_reg + cpu_6502->ram[memory_addr] + carry;
    //set carry flag
    if(adc_sum > 0xFF) {
        cpu_6502->registers.status_regs |= STATUS_CARRY;
    }else{
        cpu_6502->registers.status_regs &= ~STATUS_CARRY;
    }
    //
    cpu_6502->registers.A_reg = adc_sum & 0xFF;

}


void AND(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    // A = A & memory
    uint16_t memory_addr = selected_lookup->op_mode(cpu_6502);
    cpu_6502->registers.A_reg &= cpu_6502->ram[memory_addr];
    
}

void ASL(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup){
    // shifts to the left by 1 byte: memory or accumulator
    if(selected_lookup->op_mode == accumulator_mode) {
        cpu_6502->registers.A_reg <<= 1;
        return;
    }    
    uint16_t memory_addr = selected_lookup->op_mode(cpu_6502);
    cpu_6502->ram[memory_addr] <<= 1;
    
};

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
    uint16_t memory_address = selected_lookup->op_mode(cpu_6502);
    uint8_t operand = cpu_6502->ram[memory_address];

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

// BPL - Branch if Plus
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
    uint16_t memory_address = selected_lookup->op_mode(cpu_6502);
    uint8_t result = --cpu_6502->ram[memory_address];
    
    //Update zero flag
    cpu_6502->registers.status_regs = 
        (cpu_6502->registers.status_regs & ~STATUS_ZERO) | (result == 0 ? STATUS_ZERO : 0);

    //Update negative flag
    cpu_6502->registers.status_regs = 
        (cpu_6502->registers.status_regs & ~STATUS_NEGATIVE) | (result & 0x80 ? STATUS_NEGATIVE : 0);
}

//DEX - decremet x
void DEX(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    uint16_t memory_address = selected_lookup->op_mode(cpu_6502);
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
    uint16_t memory_address = selected_lookup->op_mode(cpu_6502);
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
    uint16_t memory_address = selected_lookup->op_mode(cpu_6502);
    uint8_t result = cpu_6502->registers.A_reg ^ cpu_6502->ram[memory_address];

    // set zero flag
    cpu_6502->registers.status_regs = 
        (cpu_6502->registers.status_regs & ~STATUS_ZERO) | (result == 0 ? STATUS_ZERO : 0);

    // negative zero flag
     cpu_6502->registers.status_regs = 
        (cpu_6502->registers.status_regs & ~STATUS_NEGATIVE) | (result & 0x80 ? STATUS_NEGATIVE : 0);

}

// INC - Increment Memory
void INC(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    uint16_t memory_address = selected_lookup->op_mode(cpu_6502);
    uint8_t result = ++cpu_6502->ram[memory_address];
    
    //Update zero flag
    cpu_6502->registers.status_regs = 
        (cpu_6502->registers.status_regs & ~STATUS_ZERO) | (result == 0 ? STATUS_ZERO : 0);

    //Update negative flag
    cpu_6502->registers.status_regs = 
        (cpu_6502->registers.status_regs & ~STATUS_NEGATIVE) | (result & 0x80 ? STATUS_NEGATIVE : 0);
}

// INX - Increment X
void INX(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    uint16_t memory_address = selected_lookup->op_mode(cpu_6502);
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
    uint16_t memory_address = selected_lookup->op_mode(cpu_6502);
    uint8_t result = ++cpu_6502->registers.Y_reg;
    
    //Update zero flag
    cpu_6502->registers.status_regs = 
        (cpu_6502->registers.status_regs & ~STATUS_ZERO) | (result == 0 ? STATUS_ZERO : 0);

    //Update negative flag
    cpu_6502->registers.status_regs = 
        (cpu_6502->registers.status_regs & ~STATUS_NEGATIVE) | (result & 0x80 ? STATUS_NEGATIVE : 0);
}

// JMP - Jump
void JMP(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    // PC  = memory
    uint16_t memory_address = selected_lookup->op_mode(cpu_6502);
    cpu_6502->registers.PC_reg = cpu_6502->ram[memory_address];
    
}

//  JSR - Jump to subroutine 
void JSR(cpu_6502_t* cpu_6502_t, struct instruction_t* selectect_lookup) {
    // push PC + 2 to the stack
    // pc = memory


}


//LDA - Load A
void LDA(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    // loads memory into accumulator
    uint16_t memory_address = selected_lookup->op_mode(cpu_6502);
    uint8_t result = cpu_6502->ram[memory_address];
    cpu_6502->registers.A_reg = result;
    
        //Update zero flag
    cpu_6502->registers.status_regs = 
        (cpu_6502->registers.status_regs & ~STATUS_ZERO) | (result == 0 ? STATUS_ZERO : 0);

    //Update negative flag
    cpu_6502->registers.status_regs = 
        (cpu_6502->registers.status_regs & ~STATUS_NEGATIVE) | (result & 0x80 ? STATUS_NEGATIVE : 0);
}

// LDX -load x
void LDX(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    // loads memory into accumulator
    uint16_t memory_address = selected_lookup->op_mode(cpu_6502);
    uint8_t result = cpu_6502->ram[memory_address];
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
    uint16_t memory_address = selected_lookup->op_mode(cpu_6502);
    uint8_t result = cpu_6502->ram[memory_address];
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
    // Fetch the memory address from the instruction's operand mode
    uint16_t memory_address = selected_lookup->op_mode(cpu_6502);
    
    // Fetch the value from memory and calculate the result of the shift
    uint8_t value = cpu_6502->ram[memory_address];
    // Set the Carry flag to the original bit 0 before shifting
    cpu_6502->registers.status_regs = 
        (cpu_6502->registers.status_regs & ~STATUS_CARRY) | (value & 0x01 ? STATUS_CARRY : 0);
    // Perform the logical shift right
    value >>= 1;
    cpu_6502->ram[memory_address] = value;  // Store the result back in memory

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

}

// ROL - Rotate Left
void ROL(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    // carry -> bit 0
    //bit 7 -> carry
    uint8_t operand;
    uint8_t temp_status_flags = cpu_6502->registers.status_regs;

    if(selected_lookup->op_mode == implied_mode) {
        operand = cpu_6502->registers.A_reg;        

        cpu_6502->registers.A_reg <<= 1;
        //copy carry flag into bit 0
        cpu_6502->registers.A_reg = (operand & ~0x1) |
                                (temp_status_flags & STATUS_CARRY);

    }else {
        uint16_t memory_address = selected_lookup->op_mode(cpu_6502);
        operand = cpu_6502->ram[memory_address];

        cpu_6502->ram[memory_address] <<= 1;
        cpu_6502->ram[memory_address] = (operand & ~0x1) | (temp_status_flags & 0x1);

    }

    // bit  7 ->carry
    cpu_6502->registers.status_regs = (temp_status_flags & ~STATUS_CARRY) | 
                                        (operand & 0X80);

}

// ROR- Rotate Right
void ROR(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    // carry -> bit 7
    //bit 0 -> carry
    uint8_t operand;
    uint8_t temp_status_flags = cpu_6502->registers.status_regs;

    if(selected_lookup->op_mode == implied_mode) {
        operand = cpu_6502->registers.A_reg;        

        cpu_6502->registers.A_reg <<= 1;
        //copy carry flag into bit 7
        cpu_6502->registers.A_reg = (operand & ~0x80) |
                                ((temp_status_flags & STATUS_CARRY) << 7);

    }else {
        uint16_t memory_address = selected_lookup->op_mode(cpu_6502);
        operand = cpu_6502->ram[memory_address];

        cpu_6502->ram[memory_address] <<= 1;
        cpu_6502->ram[memory_address] = (operand & ~0x1) | (temp_status_flags & 0x1);

    }

    // bit  7 ->carry
    cpu_6502->registers.status_regs = (temp_status_flags & ~STATUS_CARRY) | 
                                        (operand & 0X80);

}


// Return from Interrupt 
void RTI(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {

}

//RTS - Return from Subroutine
void RTS(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    //pulls PC from the stack, increments PC
    uint16_t pc = cpu_6502->ram[++cpu_6502->registers.SP_reg];

}


// TOdo
// SBC - Subtract with Carry
void SBC(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
    // A = A - momory - ~C or  A = A + ~memory + C

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


