#include "cpu_6502.h"





uint8_t fetch_next_byte(cpu_6502_t* cpu_6502) {
    return cpu_6502->ram[cpu_6502->registers.PC_reg++]; 
};

void emulate_instructions(cpu_6502_t *cpu_6502) {
    uint8_t opcode = fetch_next_byte(cpu_6502);
    struct instruction_t selected_lookup = lookup[opcode];
    if(selected_lookup.op_func != NULL) {

         void (*func_ptr)(cpu_6502_t*, struct instruction_t* ) = selected_lookup.op_func;
        (*func_ptr)(cpu_6502, &selected_lookup); 
    }else{
        fprintf(stderr, "Emulate_instruction failed to call the op func \n");
    }
}


void cpu_init(cpu_6502_t *cpu_6502) {
    memset(&cpu_6502->registers, 0, sizeof(cpu_6502_regs_t)); //sets all the registers to 0
    cpu_6502->registers.SP_reg = STACK_START_PTR;
    cpu_6502->registers.status_regs |= STATUS_IRQB_DISABLE; //sets the interrupt flag


}   