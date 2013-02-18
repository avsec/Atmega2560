# Arion project's makefile
# Created by Carmelo J. Fdez-Agüera Tortosa, a.k.a. Technik
# On November 24th, 2012

PRJ_NAME = atmega2560
MCU ?= atmega2560
debug ?= false

# -- Global variables --
ATMEGA_TOOLCHAIN := $(AVR_HOME)/bin

# -- GNU Tools --
AS := $(ATMEGA_TOOLCHAIN)/avr-as # Assembler
AR := $(ATMEGA_TOOLCHAIN)/avr-ar # Archiver
CC := $(ATMEGA_TOOLCHAIN)/avr-gcc # C Compiler
CXX := $(ATMEGA_TOOLCHAIN)/avr-g++ # C++ Compiler
OBJCOPY := $(ATMEGA_TOOLCHAIN)/avr-objcopy # Obj copy
OBJDUMP := $(ATMEGA_TOOLCHAIN)/avr-objdump # Obj dump
READELF := $(ATMEGA_TOOLCHAIN)/avr-readelf # Read elf
AVRDUDE := $(ATMEGA_TOOLCHAIN)/avrdude # To load programs into the boards
	#C:/Users/technik/programming/tools/arduino-1.0.1/hardware/tools/avr/bin/avrdude
 #-CC:/Users/technik/programming/tools/arduino-1.0.1/hardware/tools/avr/etc/avrdude.conf
 #$(ATMEGA_TOOLCHAIN)/avrdude

AVR_DEFINITIONS := -DATMEGA
ifeq (atmega328p, $(MCU))
    PLATFROM_DEFINITIONS := $(AVR_DEFINITIONS) -DATMEGA328P -DF_CPU=16000000L
    PLATFORM_FLAGS := -mmcu=atmega328p
	PROG_PROTOCOL ?= arduino
	PORT ?= COM3
endif
ifeq (atmega2560, $(MCU))
    PLATFROM_DEFINITIONS := $(AVR_DEFINITIONS) -DATMEGA2560 -DF_CPU=16000000L
    PLATFORM_FLAGS := -mmcu=atmega2560
	PROG_PROTOCOL ?= wiring
	PORT ?= COM4
endif

# -- Folder structure --
ROOT_DIR := ../../..
SRC_DIR := $(ROOT_DIR)/src
CODE_DIR := $(SRC_DIR)/code
OUT_DIR := $(ROOT_DIR)/bin/$(MCU)

OUT_NAME := $(OUT_DIR)/$(PRJ_NAME)
OUTPUT := $(OUT_NAME).hex

CXX_SRC := $(CODE_DIR)/main.cpp \
			$(CODE_DIR)/core/board/board.cpp \
			$(CODE_DIR)/core/board/arduinoMega2560/arduinoMega2560Board.cpp \
			$(CODE_DIR)/core/memory/memory.cpp \
			$(CODE_DIR)/core/time/time.cpp \
			$(CODE_DIR)/core/interrupts/interrupts.cpp 
			
CXX_OBJ := $(patsubst %.cpp, %.cpp.o, $(CXX_SRC))

TEMP_FILES := $(CXX_OBJ)

# -- Build variables --
PREPROCESSOR_DEFINITIONS := $(PLATFROM_DEFINITIONS)
WARNING_FLAGS := -Wall -Werror
INCLUDE_FLAGS := -I$(CODE_DIR)
CXX_COMPILE_FLAGS := -std=c++0x -fno-access-control -fno-enforce-eh-specs\
 			-fno-rtti -fno-exceptions -ffunction-sections -fdata-sections
ifeq (true, $(debug))
	DEBUG_FLAGS := -g -D_DEBUG
	OPTIMIZATION_FLAGS := # -O4
endif
ifeq (false ,$(debug))
	DEBUG_FLAGS := #-g
	OPTIMIZATION_FLAGS := -O4
endif
COMMON_C_FLAGS := $(PLATFORM_FLAGS) $(PREPROCESSOR_DEFINITIONS) $(WARNING_FLAGS)\
 			 $(INCLUDE_FLAGS) $(DEBUG_FLAGS) $(OPTIMIZATION_FLAGS)
CC_FLAGS := $(COMMON_C_FLAGS)
CXX_FLAGS := $(COMMON_C_FLAGS) $(CXX_COMPILE_FLAGS)

# -- Rules --
all: $(OUTPUT)

clean:
	rm -f $(OUTPUT) $(TEMP_FILES) $(OUT_NAME).elf

run: $(OUTPUT)
	$(AVRDUDE) -p$(MCU) -c$(PROG_PROTOCOL) -b115200 -P$(PORT) -D -Uflash:w:$^:i

%.hex: %.elf
	$(OBJCOPY) -O ihex -R .eeprom -R .fuse -R .lock -R .signature $^ $@

$(OUT_NAME).elf: $(CXX_SRC)
	$(CXX) -o $@ $^ $(CXX_FLAGS) $(REV_INCLUDE) $(LIB_DIR)

readelf: $(OUT_NAME).elf
	$(READELF) -a $^

dump: $(OUT_NAME).elf
	$(OBJDUMP) -h $^

dwarf: $(OUT_NAME).elf
	$(OBJDUMP) --dwarf=info $^

assebly: (OUT_NAME).S

$(OUT_NAME).S: $(CXX_SRC)
	$(CXX) -S -o $@ $^ $(CXX_FLAGS)

.PHONY: readelf run clean