#ifndef CPU_6502_INCLUDE

#define CPU_6502_INCLUDE

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

#include "instruction.h"


//Memory Map

    // 0000-00FF RAM used for zero page and indirect memory addressing
    // operation.
    // 0100-01FF RAM used for stack processing and for absolute addressi
    // 0200-3FFF Normally RAM.
    // 4000-7FFF Normally I/O
    // 8000-FFF9 Program storage normally ROM.
    // FFFA Vector low address for NMI.
    // FFFB Vector high address for NMI.
    // FFFC Vector low address for RESET.
    // FFFD Vector high address for RESET.
    // FFFE Vector low address for IRQ + BRK.
    // FFFF Vector high address for IRQ + BRK.

// -----------------------------------------------------------------------------

#define TOTAL_MEMORY 0x10000
#define STACK_SIZE 256
#define STACK_START_PTR 0xFF
#define ZERO_PAGE_START 0x0
#define ZERO_PAGE_END 0x00FF
#define RAM_SIZE (TOTAL_MEMORY)

// ROM
#define ROM_START   0x8000
#define ROM_END     0xFFF9
#define ROM_LOAD_START
#define ROM_SIZE    (ROM_END - ROM_START + 1)


// Flags bitmask 
#define STATUS_CARRY 0x01
#define STATUS_ZERO 0x02
#define STATUS_IRQB_DISABLE 0X04
#define STATUS_DECIMAL 0X08
#define STATUS_BREAK 0x10
#define STATUS_UNUSED 0x20
#define STATUS_OVERFLOW 0x40
#define STATUS_NEGATIVE 0x80


//  Flag position
#define CARRY_POS 0
#define ZERO_POS  1
#define IRQB_DISABLE_POS 2
#define DECIMAL_POS 3
#define BREAK_POS 4
#define UNUSED_POS 5
#define OVERFLOW_POS 6
#define NEGATIVE_POS 7



// CLock

#define MASTER_CLOCK_FREQUENCY 21.477       //MHz
#define CPU_CLOCK_FREQUENCY (1.79 * pow(10, 20))           //MHz



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








void emulate_instructions(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup);
void cpu_init(cpu_6502_t *cpu_6502);
uint8_t fetch_next_byte(cpu_6502_t* cpu_6502);


#endif