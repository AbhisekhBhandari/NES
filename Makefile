# Setting the compiler
CC = gcc

# Compiler flags:
# -g: Include debug information
# -Wall: Enable all warnings
CFLAGS = -g -Wall -O0 -std=c99

# Linker flags:
# -lm: Link with the math library
# -lncurses: Link with the ncurses library
LDLIBS = -lm -lncurses

# Project structure
SRC_DIR = src
BUILD_DIR = build

# Source files
SOURCES = $(SRC_DIR)/main.c $(SRC_DIR)/instruction.c $(SRC_DIR)/cpu_6502.c $(SRC_DIR)/debug.c
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SOURCES))

# Target executable
TARGET = $(BUILD_DIR)/program

# Default rule
all: $(TARGET)

# Rule to create the build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Rule to link the final executable
$(TARGET): $(OBJECTS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

# Rule to compile source files into object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)
