#ifndef DEBUG_CODE
#define DEBUG_CODE


#include <ncurses.h>
#include "cpu_6502.h"
// #include "instruction.h"


void show_debug(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup, uint8_t actual_op);
void show_mem(cpu_6502_t* cpu_6502, uint8_t x_cursor, uint8_t y_cursor, uint16_t start_address) ;
void show_stack(cpu_6502_t* cpu_6502);


    





#endif


