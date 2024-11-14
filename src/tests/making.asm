# Setting the compiler
CC = gcc

# CFLAGS varibale sets compile flags for gcc:
# -g = compile with debug information
#  -Wall = give verbose compiler warnings
#  -O0  = DO NOT Optimize generated code
#  -std = C99  use the C99 standard language definition
CFLAGS = -g -Wall -std= c99

# THe LDFLAGS variable sets flags for linker
#  -lm = says to link in libm(the math library);

LDFLAGS = -lm

# In this section, you list the files that are part of the project.
# If you add/change names of source files, here is where you edit

SOURCES= main.c cpu_6502.c instruction.c 

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



# Targets and their associated acttions are writte in the form
# target-name : dependencies
# 				action


# when only "make" is invoked the defualt target is used whereas,
# "make [target-name]" can be used to use specific targets at command line