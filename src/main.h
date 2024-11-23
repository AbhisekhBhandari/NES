#ifndef MAIN_HEADER
#define MAIN_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <math.h>



#define TOTAL_MEMORY 0x10000
#define STACK_SIZE 256
#define STACK_START_PTR 0xFF
#define ZERO_PAGE_START 0x0
#define ZERO_PAGE_END 0x00FF
#define RAM_SIZE (TOTAL_MEMORY)



typedef struct  {
    uint8_t A_reg;          //accumulator 
    uint8_t Y_reg;          //Index Y register
    uint8_t X_reg;          //Index X register
    uint16_t PC_reg;        //Program Counter
    uint8_t SP_reg;         // Stack pointer register
    uint8_t status_regs;    //Carry,    zero,  IRQB, Dcecimal, BRK, 1,  overflow, ngative

} cpu_6502_regs_t;

typedef struct {
    uint8_t ram[RAM_SIZE];          //2kb ram
    cpu_6502_regs_t registers;
    uint16_t address_bus;       //address bus
    uint8_t stack[STACK_SIZE];
    uint16_t cycles;
    
} cpu_6502_t;
 

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
    ZERO_PAGE_INDIRECT_INDEXED_Y,   

}addressing_modes_t;


struct instruction_t {
    char* opcode;
    void (*op_func)(cpu_6502_t*, struct instruction_t*);
    addressing_modes_t addr_mode;
    uint16_t (*op_mode)(cpu_6502_t* cpu_6502);
    uint8_t cycles;
};


#endif