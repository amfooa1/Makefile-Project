#Copyrights : Ahmed Fathi
# Makefile for building a static library (libDIO.a)

# Compiler and flags
CC = avr-gcc
CFLAGS = -mmcu=atmega32 -Os
AR = avr-ar
ARFLAGS = rcs

# Source files
SRC_FILES = DIO_program.c

# Object files
OBJ_FILES = $(SRC_FILES:.c=.o)

# Library name
LIB_NAME = libDIO.a

# Targets
all: $(LIB_NAME)

$(LIB_NAME): $(OBJ_FILES)
	$(AR) $(ARFLAGS) $(LIB_NAME) $(OBJ_FILES)
	rm -f $(OBJ_FILES)
	mv $(LIB_NAME) ../src/

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f ../src/$(LIB_NAME)

.PHONY: all clean
