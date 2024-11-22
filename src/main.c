#define _POSIX_C_SOURCE 199309L


#include "main.h"
#include <time.h>

#include "cpu_6502.h"
#include "debug.h"
#include "instruction.h"

#define DEBUG

bool load_rom(cpu_6502_t *cpu, const char* rom_file_name) { 

    FILE* rom_file = fopen(rom_file_name, "rb");

    if(rom_file == NULL) {
        fprintf(stderr, "Invalid ROM \n");
        return false;
    }
 
    fseek(rom_file, 0, SEEK_END);
    uint16_t rom_length = ftell(rom_file);
    rewind(rom_file);

    if(rom_length > ROM_SIZE) { 
        fprintf(stderr, "ROM exceeds ROM size \n");
        fclose(rom_file);
        return false;

    }
    size_t bytes_read = fread(&cpu->ram[ROM_START], sizeof(uint8_t), rom_length, rom_file);

    if(bytes_read != rom_length) { 
        fprintf(stderr, "Error reading ROM \n");
        fclose(rom_file);
        return false;
    }
    fclose(rom_file);
    return true;

}



int main(int argc, char **argv) 
{
    //get the rom(file) from the command line
    //if not provided, return - STACK_SIZE];

    // initialize cpu
    cpu_6502_t my_cpu = {0};
    // 


    cpu_init(&my_cpu);
    if(argc < 2) {
        fprintf(stderr, "Please provide a ROM \n"); 
        exit(EXIT_FAILURE);
    }
 
    //load from rom
    bool is_rom_loaded = load_rom(&my_cpu, *(argv + 1));
    if(!is_rom_loaded) {
        fprintf(stderr, "Failed to setup rom \n");
        exit(EXIT_FAILURE);
    };

    // initialize cpu
    

    #ifdef DEBUG
        initscr();  //curses mode
        noecho();
        cbreak();
        keypad(stdscr, TRUE);
        start_color();
        nodelay(stdscr, TRUE);
    #endif  
    while(true) { 

        struct timespec start, end;
        clock_gettime(CLOCK_MONOTONIC_RAW, &start);
        // 
        uint8_t opcode = fetch_next_byte(&my_cpu);
        struct instruction_t selected_lookup = lookup[opcode];
    // 
        #ifdef DEBUG
            show_debug(&my_cpu, &selected_lookup, opcode);
        #endif
        emulate_instructions(&my_cpu, &selected_lookup);

        clock_gettime(CLOCK_MONOTONIC_RAW, &end);
        // recording time elapsed during execution
        double time_elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) * 1e-9;
        // calculating required time per cycle;
        double target_time = (1.0 / CPU_CLOCK_FREQUENCY) * my_cpu.cycles;
        double sleep_time = target_time - time_elapsed;

        if(sleep_time > 0) {
            struct timespec req = {(time_t)sleep_time, (sleep_time - (time_t)sleep_time) * 1e9};
            nanosleep(&req, NULL);
        }



    };
    #ifdef DEBUG
        endwin();
    #endif
    return 0;

}
