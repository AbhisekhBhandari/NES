#ifndef CPU_6502_INCLUDE

#define CPU_6502_INCLUDE

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "instruction.h"

#define TOTAL_MEMORY 65536
#define STACK_SIZE 256
#define STACK_START_PTR 0xFF
#define ZERO_PAGE_START 0x0
#define ZERO_PAGE_END 0x00FF


// Flags bitmask 
#define STATUS_CARRY 0x01
#define STATUS_ZERO 0x02
#define STATUS_IRQB_DISABLE 0X04
#define STATUS_DECIMAL 0X08
#define STATUS_BREAK 0x10
#define STATUS_UNUSED 0x20
#define STATUS_OVERFLOW 0x40
#define STATUS_NEGATIVE 0x80

typedef struct  {
    uint8_t A_reg;          //accumulator 
    uint8_t Y_reg;          //Index Y register
    uint8_t X_reg;          //Index X register
    uint16_t PC_reg;        //Program Counter
    uint8_t SP_reg;         // Stack pointer register
    uint8_t status_regs;    //Carry,    zero,  IRQB, Dcecimal, BRK, 1,  overflow, ngative

} cpu_6502_regs_t;

typedef struct {
    uint8_t ram[TOTAL_MEMORY - STACK_SIZE];          //2kb ram
    cpu_6502_regs_t registers;
    uint16_t address_bus;       //address bus
    uint8_t stack[STACK_SIZE];
    
} cpu_6502_t;

// typedef enum {
//     ABSOLUTE,
//     ABSOLUTE_INDEXED_INDIRECT,
//     ABSOLUTE_INDEXED_X,
//     ABSOLUTE_INDEXED_Y,
//     ABSOLUTE_INDIRECT,
//     ACCUMULATOR,
//     IMMEDIATE,
//     IMPLIED,
//     PROGRAM_COUNTER_RELATIVE,
//     STACK,
//     ZERO_PAGE,
//     ZERO_PAGE_INDEXED_INDIRECT,
//     ZERO_PAGE_INDEXED_X,
//     ZERO_PAGE_INDEXED_Y,
//     ZERO_PAGE_INDIRECT,
//     ZERO_PAGE_INDIRECT_INDEXED_Y    

// }addressing_modes_t;






void emulate_instructions(cpu_6502_t *cpu_6502);
void cpu_init(cpu_6502_t *cpu_6502);
uint8_t fetch_next_byte(cpu_6502_t* cpu_6502);


#endif