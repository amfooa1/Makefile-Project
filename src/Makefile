#Copyrights : Ahmed Fathi
# Makefile for compiling main.c and linking with lib.a for AVR using avr-gcc

# Compiler and flags
CC = avr-gcc
CCopy = avr-objcopy
CSize = avr-size
CFLAGS = -mmcu=atmega32 -Os

# Source files
SRC_FILES = main.c
LIB_NAME = libDIO.a

# Output executable
OUTPUT = snake_effect.elf
OUTPUTH = snake_effect.hex
OUTPUT_TXT = binaryReport.txt
OUT_DIR = build
LOCATION = ../lib

# Targets
all: $(OUTPUT_TXT)

$(OUTPUT): $(SRC_FILES) $(LIB_NAME)
	$(CC) $(CFLAGS) -o $@ $(SRC_FILES) -L. -l:$(LIB_NAME)
	mv $(OUTPUT) ../$(OUT_DIR)

$(LIB_NAME):
	$(MAKE) -C $(LOCATION)


$(OUTPUTH): $(OUTPUT)
	$(CCopy) -O ihex ../$(OUT_DIR)/$(OUTPUT) $(OUTPUTH)
	mv $(OUTPUTH) ../$(OUT_DIR)

$(OUTPUT_TXT): $(OUTPUTH)
	$(CSize) ../$(OUT_DIR)/$(OUTPUTH) > $(OUTPUT_TXT)
	mv $(OUTPUT_TXT) ../$(OUT_DIR)


clean:
	rm -f ../$(OUT_DIR)/$(OUTPUT) ../$(OUT_DIR)/$(OUTPUTH) ../$(OUT_DIR)/$(OUTPUT_TXT) $(LIB_NAME)

.PHONY: all clean
