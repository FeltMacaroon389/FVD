CC = i386-elf-gcc
OBJCOPY = i386-elf-objcopy

CCFLAGS = -std=gnu99 -m32 -ffreestanding -nostdlib
OBJCOPYFLAGS = -O binary

SRC_DIR = src
INC_DIR = include
BUILD_DIR = build

.PHONY: all clean

all:
	mkdir -p $(BUILD_DIR)
	
	$(CC) $(CCFLAGS) -o $(BUILD_DIR)/fvd.o -c $(SRC_DIR)/fvd.c -I$(INC_DIR)
	$(OBJCOPY) $(OBJCOPYFLAGS) $(BUILD_DIR)/fvd.o $(BUILD_DIR)/fvd.bin

clean:
	rm -rf $(BUILD_DIR)

