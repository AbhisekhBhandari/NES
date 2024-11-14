#include "main.h"


#include "cpu_6502.h"


bool load_rom(cpu_6502_t *cpu, const char* rom_file_name) { 
    FILE* rom_file = fopen(rom_file_name, "rb");

    if(rom_file == NULL) {
        fprintf(stderr, "Invalid ROM \n");
        return false;
    }

    fseek(rom_file, 0, SEEK_END);
    uint16_t rom_length = ftell(rom_file);
    rewind(rom_file);

    if(rom_length > TOTAL_MEMORY) { 
        fprintf(stderr, "ROM exceeds memory size \n");
        fclose(rom_file);
        return false;

    }
    size_t bytes_read = fread(cpu->ram, sizeof(uint8_t), rom_length, rom_file);
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
    if(argc < 2) {
        fprintf(stderr, "Please provide a ROM \n");
        exit(EXIT_FAILURE);
    }
 
    //load from rom
    if(!load_rom(&my_cpu, *argv)) {
        fprintf(stderr, "Failed to setup rom \n");
        exit(EXIT_FAILURE);
    };

    // initialize cpu
    
    cpu_init(&my_cpu);

    while(true) { 
        
        emulate_instructions(&my_cpu);
    };
    //
    return 0;

}

