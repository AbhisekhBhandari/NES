# Setting the compiler
CC = gcc

# CFLAGS varibale sets compile flags for gcc:
# -g = compile with debug information
#  -Wall = give verbose compiler warnings
#  -O0  = DO NOT Optimize generated code
#  -std = C99  use the C99 standard language definition
CFLAGS = -g -Wall 

# THe LDFLAGS variable sets flags for linker
#  -lm = says to link in libm(the math library);

LDFLAGS = -lm

# In this section, you list the files that are part of the project.
# If you add/change names of source files, here is where you edit

# SRC_DIR = src/
SOURCES = src/main.c src/cpu_6502.c src/instruction.c
# FULL_SOURCES= $(addprefix $(SRC_DIR), $(SOURCES)) 

# Defines the "OBJECTS" macro to be the same as the "SOURCES" macro except tgat every instance
# of .c is repleaced by .o
OBJECTS = $(SOURCES:.c=.o)
TARGET = cpu_6502

# The first target defined in the makefile is the one used when make is invoked with no argument.
# GIven the definitions aboce, this Makefile file will build the one named TARGER
# and assume that it depends on all the named OBJECTS files.


# Built in macros 
# $@ =	main
# @^ = main.o 

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# gcc -g -Wall -std=c99 -o cpu_6502 main.o cpu_6502.o instructions.o -lm 

#phony means not a "Real" target, it doesn't build anything 
# the phony target "clean" is used to remove all compiled object files

.PHONY:clean

clean: 	
	@rm -f $(TARGET) $(OBJECTS) core



# # Targets and their associated acttions are writte in the form
# # target-name : dependencies
# # 				action


# # when only "make" is invoked the defualt target is used whereas,
# # "make [target-name]" can be used to use specific targets at command line



# # damn chagpt
# # Define source and header files without the directory prefix
# SOURCES = main.c cpu_6502.c instruction.c
# HEADERS = instruction.h cpu_6502.h  # List your headers here

# # Automatically add `src/` to each source and header file
# SRC_DIR = src/
# FULL_SOURCES = $(addprefix $(SRC_DIR), $(SOURCES))
# FULL_HEADERS = $(addprefix $(SRC_DIR), $(HEADERS))

# # Define object files based on sources
# OBJECTS = $(FULL_SOURCES:.c=.o)

# # Compiler and flags
# CC = gcc
# CFLAGS = -g -Wall -std=c99 -I$(SRC_DIR)
# LDFLAGS = -lm

# # Target
# TARGET = cpu_6502	

# $(TARGET): $(OBJECTS)
# 	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# # Implicit rule to compile .c files to .o
# %.o: %.c $(FULL_HEADERS)
# 	$(CC) $(CFLAGS) -c $< -o $@

# # Clean up
# .PHONY: clean
# clean:
# 	rm -f $(OBJECTS) $(TARGET) core



# copied sir

# CFLAGS	= -Wall -Wextra  -std=c99
# LDFLAGS	= -L/usr/local/lib

# sources = src/main.c src/cpu_6502.c src/instruction.c 
# headers = src/main.h src/cpu_6502.h src/instruction.h

# all: bin/emulator.out
	
# bin/emulator.out: $(sources) $(headers)
# 	@mkdir -p bin
# 	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(sources) 


# clean:
# 	rm -rf bin