#include "instruction.h"
#include "cpu_6502.h"

#include "debug.h"



#define DEBUG

uint8_t fetch_next_byte(cpu_6502_t* cpu_6502) {
    uint8_t next_byte = cpu_6502->ram[cpu_6502->registers.PC_reg++]; 
    return next_byte;

};  

void emulate_instructions(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {

    // uint8_t opcode = fetch_next_byte(cpu_6502);
    // struct instruction_t selected_lookup = lookup[opcode];

    // #ifdef DEBUG
    //         show_debug(cpu_6502, &selected_lookup, opcode);
    //     #endif
    if(selected_lookup->op_func != NULL) {

        void (*func_ptr)(cpu_6502_t*, struct instruction_t* ) = selected_lookup->op_func;
        cpu_6502->cycles = selected_lookup->cycles;
        (*func_ptr)(cpu_6502, selected_lookup); 
    }else{


        fprintf(stderr, "Emulate_instruction failed to call the op func \n");
    }
}


void cpu_init(cpu_6502_t *cpu_6502) {
   for(int i = 0; i < RAM_SIZE; i++){
        cpu_6502->ram[i] = 0;
    }
    // memset(cpu_6502->ram, 0, sizeof(RAM_SIZE));
    memset(&cpu_6502->registers, 0, sizeof(cpu_6502_regs_t)); //sets all the registers to 0
    cpu_6502->registers.SP_reg = STACK_START_PTR;
    // cpu_6502->registers.status_regs |= STATUS_IRQB_DISABLE; //sets the interrupt flage
    cpu_6502->registers.PC_reg = ROM_START;


}   

