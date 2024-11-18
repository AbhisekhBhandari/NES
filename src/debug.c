// #include "debug.h"


// #define DEBUG_PAGE_SIZE 256
// #define DEBUG_ADDRESS_SIZE 16


// void show_debug(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup) {
//     move(0, 0);
//     printw("Fetched opcode(op): 0x%X, ", selected_lookup->opcode);
//     printw("Selected opcode(exec): %s \n", selected_lookup->opcode);

//     printw("Registers: \n");
//     printw("Accumulator: 0x%x, X: 0x%x, Y: 0x%x \n", cpu_6502->registers.A_reg, cpu_6502->registers.X_reg, cpu_6502->registers.Y_reg);
//     printw("PC: 0x%x, SP: 0x%x \n", cpu_6502->registers.PC_reg, cpu_6502->registers.SP_reg);
//     printw("-------------------------------------------------------------------------------\n");

//     uint8_t carry = (cpu_6502->registers.status_regs & STATUS_CARRY) ? 1 : 0;
//     uint8_t zero = (cpu_6502->registers.status_regs & STATUS_ZERO) ? 1 : 0;
//     uint8_t IRQB = (cpu_6502->registers.status_regs & STATUS_IRQB_DISABLE) ? 1 : 0;
//     uint8_t decimal = (cpu_6502->registers.status_regs & STATUS_DECIMAL) ? 1 : 0;
//     uint8_t BRK = (cpu_6502->registers.status_regs & STATUS_BREAK) ? 1 : 0;
//     uint8_t overflow = (cpu_6502->registers.status_regs & STATUS_OVERFLOW) ? 1 : 0;
//     uint8_t negative = (cpu_6502->registers.status_regs & STATUS_NEGATIVE) ? 1 : 0;

//     printw("FLAGS: Carry: %d, Zero: %d, IRQB: %d, Decimal: %d,\nBreak: %d, Overflow: %d,  Negative: %d \n", 
//            carry, zero, IRQB, decimal, BRK, overflow, negative);

//     printw("Current Inst: %02X\n", cpu_6502->ram[cpu_6502->registers.PC_reg]);
//     printw("-------------------------------------------------------------------------------\n");
    
//     int8_t x_mem_cursor, y_mem_cursor;

//     int16_t MAX_PAGE = (TOTAL_MEMORY / DEBUG_PAGE_SIZE) - 1;
//     printw("Max page: %d \n", MAX_PAGE);
//     int16_t CURR_PAGE = 0;

//     bool infinite_loop = true;
    
//     getyx(stdscr, y_mem_cursor, x_mem_cursor);
//     while (infinite_loop) {


//         show_mem(cpu_6502, x_mem_cursor, y_mem_cursor, CURR_PAGE * DEBUG_PAGE_SIZE);

//         printw("Current Page: %02X \n", CURR_PAGE);

//         int ch;
//         ch = getch();
//         switch (ch) {
//             case '\n':  // ENTER
//                 infinite_loop = false;
//                 break;

//             case KEY_RIGHT:  // Next page
//                 CURR_PAGE = (CURR_PAGE + 1) % (MAX_PAGE + 1); // Ensure it wraps correctly
//                 show_mem(cpu_6502, x_mem_cursor, y_mem_cursor, CURR_PAGE * DEBUG_PAGE_SIZE);
//                 break;

//             case KEY_LEFT:  // Previous page
//                 CURR_PAGE = (CURR_PAGE - 1 + (MAX_PAGE + 1)) % (MAX_PAGE + 1); // Ensure it wraps correctly
//                 show_mem(cpu_6502, x_mem_cursor, y_mem_cursor, CURR_PAGE * DEBUG_PAGE_SIZE);
//                 break;

//             default:
//                 break;
//         }
//         printw("\nYou are in debug mode:\n");
//         printw("ENTER - Next Instruction\n");
//         printw("ARROW LEFT - Prev memory page\n");
//         printw("ARROW RIGHT - Next memory page\n");

//         refresh();
//     }
// }
// void show_mem(cpu_6502_t* cpu_6502, int8_t x_cursor, int8_t y_cursor, int16_t start_address) {

//     move(y_cursor, x_cursor);
//     clrtobot();
//     move(y_cursor, x_cursor);

//     start_color();
//     init_pair(1, COLOR_RED, COLOR_BLACK);
//     printf("CUrsor page: %X", start_address);
//     for (int i = 0; i < 16; i++) {
//         int address = start_address + (i * 16);
//         if (address >= TOTAL_MEMORY) {
//             break;
//         }

//         printw("0x%04X \t", address);
//         for (int j = 0; j < 16; j++) {
//             int offset = address + j;
//             if (offset >= TOTAL_MEMORY) {
//                 break;
//             }

//             int8_t value = cpu_6502->ram[offset];
//             if (value != 0) {
//                 attron(COLOR_PAIR(1));
//                 printw("%02X  ", value);
//                 attroff(COLOR_PAIR(1));
//             } else {
//                 printw("%02X  ", value);
//             }
//         }
//         printw("\n");
//     }
// }

#include "debug.h"

#define DEBUG_PAGE_SIZE 256
#define DEBUG_ADDRESS_SIZE 16

char* adressing_mode_strings[] = {
    "ABSOLUTE",
    "ABSOLUTE_INDEXED_INDIRECT",
    "ABSOLUTE_INDEXED_X",
    "ABSOLUTE_INDEXED_Y",   
    "ABSOLUTE_INDIRECT",
    "ACCUMULATOR",
    "IMMEDIATE",
    "IMPLIED",
    "PROGRAM_COUNTER_RELATIVE",
    "STACK",
    "ZERO_PAGE",
    "ZERO_PAGE_INDEXED_INDIRECT",
    "ZERO_PAGE_INDEXED_X",
    "ZERO_PAGE_INDEXED_Y",
    "ZERO_PAGE_INDIRECT",
    "ZERO_PAGE_INDIRECT_INDEXED_Y"  

};

void show_debug(cpu_6502_t* cpu_6502, struct instruction_t* selected_lookup, uint8_t actual_opcode) {
    // memset(&cpu_6502->ram, 0, sizeof(RAM_SIZE));
  

    move(0, 0);
    
    printw("Fetched opcode(op): 0x%2X, ", actual_opcode);
    printw("Selected opcode(exec): %s \n", selected_lookup->opcode);  // Assuming 'mnemonic' is the string for the opcode
    printw("Addressing mode: %s \n", adressing_mode_strings[(int)(selected_lookup->addr_mode)]);

    printw("Registers: \n");
    printw("Accumulator: 0x%2X, X: 0x%2X, Y: 0x%2X \n", cpu_6502->registers.A_reg, cpu_6502->registers.X_reg, cpu_6502->registers.Y_reg);
    printw("PC: 0x%4X, SP: 0x%4X \n", cpu_6502->registers.PC_reg, cpu_6502->registers.SP_reg);
    printw("-------------------------------------------------------------------------------\n");

    uint8_t carry = (cpu_6502->registers.status_regs & STATUS_CARRY) ? 1 : 0;
    uint8_t zero = (cpu_6502->registers.status_regs & STATUS_ZERO) ? 1 : 0;
    uint8_t IRQB = (cpu_6502->registers.status_regs & STATUS_IRQB_DISABLE) ? 1 : 0;
    uint8_t decimal = (cpu_6502->registers.status_regs & STATUS_DECIMAL) ? 1 : 0;
    uint8_t BRK = (cpu_6502->registers.status_regs & STATUS_BREAK) ? 1 : 0;
    uint8_t overflow = (cpu_6502->registers.status_regs & STATUS_OVERFLOW) ? 1 : 0;
    uint8_t negative = (cpu_6502->registers.status_regs & STATUS_NEGATIVE) ? 1 : 0;

    printw("FLAGS: Carry: %d, Zero: %d, IRQB: %d, Decimal: %d,\nBreak: %d, Overflow: %d,  Negative: %d \n", 
           carry, zero, IRQB, decimal, BRK, overflow, negative);

    printw("Current Inst: %02X\n", cpu_6502->ram[cpu_6502->registers.PC_reg]);
    printw("-------------------------------------------------------------------------------\n");
    
    int8_t x_mem_cursor, y_mem_cursor;

    int16_t MAX_PAGE = (TOTAL_MEMORY / DEBUG_PAGE_SIZE) - 1; // Ensure the page count is correct
    printw("Max page: %d \n", MAX_PAGE);
    int16_t CURR_PAGE = 0;

    bool infinite_loop = true;
    
    getyx(stdscr, y_mem_cursor, x_mem_cursor);
    while (infinite_loop) {
        show_mem(cpu_6502, x_mem_cursor, y_mem_cursor, CURR_PAGE * DEBUG_PAGE_SIZE);

        printw("Current Page: %02X \n", CURR_PAGE);

        printw("\n------------------------------------------\n");
        printw("STACK \n");
        uint8_t STACK_START_ADDRESS = 0xFF;
        int8_t stack_x_cursor, stack_y_cursor;
        getyx(stdscr, stack_y_cursor, stack_x_cursor);
        show_stack(cpu_6502, stack_x_cursor, stack_y_cursor, STACK_START_ADDRESS);


        int ch;
        ch = getch();
        switch (ch) {
            case '\n':  // ENTER
                infinite_loop = false;
                break;

            case KEY_RIGHT:  // Next page
                CURR_PAGE = (CURR_PAGE + 1); // Ensure it wraps correctly
                show_mem(cpu_6502, x_mem_cursor, y_mem_cursor, CURR_PAGE * DEBUG_PAGE_SIZE);
                break;

            case KEY_LEFT:  // Previous page
                CURR_PAGE = (CURR_PAGE - 1); // Ensure it wraps correctly
                show_mem(cpu_6502, x_mem_cursor, y_mem_cursor, CURR_PAGE * DEBUG_PAGE_SIZE);
                break;

            default:
                break;
        }
        // printw("\nYou are in debug mode:\n");
        // printw("ENTER - Next Instruction\n");
        // printw("ARROW LEFT - Prev memory page\n");
        // printw("ARROW RIGHT - Next memory page\n");

        refresh();
    }
}

void show_mem(cpu_6502_t* cpu_6502, int8_t x_cursor, int8_t y_cursor, int16_t start_address) {
    move(y_cursor, x_cursor);
    clrtobot();
    move(y_cursor, x_cursor);

    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    printw("Cursor page: %X \n", start_address); // Fixed typo ("CUrsor" to "Cursor")
    for (int i = 0; i < 16; i++) {
        int address = start_address + (i * 16);
        if (address >= TOTAL_MEMORY) {
            break;
        }

        printw("0x%04X \t", address);
        for (int j = 0; j < 16; j++) {
            int offset = address + j;
            if (offset >= TOTAL_MEMORY) {
                break;
            }

            uint8_t value = cpu_6502->ram[offset];
            if (value != 0) {
                attron(COLOR_PAIR(1));
                printw("%02X  ", value);
                attroff(COLOR_PAIR(1));
            } else {
                if(j == 7){
                    printw("%02X    ", value);
                }else {
                    printw("%02X  ", value);

                }
            }
        }
        printw("\n");
    }
}

void show_stack(cpu_6502_t* cpu_6502, uint8_t x_cursor, uint8_t y_cursor ,uint8_t start_address){
    move(y_cursor, x_cursor);
    for(uint8_t i = 11; i > 0; i--){
        printw("%4X -> ", start_address - i + 1);        //stack address
        printw("|%2X |", cpu_6502->stack[start_address - i + 1]);
        printw("\n---------------------- \n");
    }


}
