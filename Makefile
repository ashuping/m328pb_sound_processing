include common.makerules
include config.makerules # See README.md

PNAME=project

OTHER_MODULES=usart.o sampling.o goertzel.o leds.o

MCU?=atmega328pb
MCUS?=atmega328p
CCOPTS?=
LNOPTS?=

CF=-Wall -g --std=c11 -Os -mmcu=$(MCU) -B $(SUPPORT_PACK)/gcc/dev/atmega328pb -Wl,-u,vfprintf -lprintf_flt -lm $(CCOPTS)
LF=-Wall -g --std=c11 -mmcu=$(MCU) -B $(SUPPORT_PACK)/gcc/dev/atmega328pb -Wl,-u,vfprintf -lprintf_flt -lm $(LNOPTS)
UF=-p atmega328pb -c atmelice_isp # NOTE: edit this as appropriate if your programmer is not an ATMEL-ICE.
OCF=-j .text -j .data -O ihex
ASF=--mcu=$(MCUS) --format=avr

#####################################################
# Silent mode by default                            #
# (set the environment variable VERBOSE to override #
#####################################################
ifndef VERBOSE
.SILENT:
endif

#####################
# Default Target    #
# Makes all modules #
# (no unit tests)   #
#####################
# Builds all modules and runs the final executable
$(PNAME).hex : $(PNAME).c common.h $(OTHER_MODULES)
	echo "$(T_COMP) $(PNAME).c -> $(PNAME).o"
	avr-gcc $(CF) -c $(PNAME).c $(CCOPTS)
	echo "$(T_LINK) $(PNAME).o $(OTHER_MODULES) -> $(PNAME).elf"
	avr-gcc $(LF) -o $(PNAME).elf $(PNAME).o $(OTHER_MODULES)
	echo "$(T_HEX) $(PNAME).elf -> $(PNAME).hex"
	avr-objcopy $(OCF) $(PNAME).elf $(PNAME).hex
	avr-size $(ASF) project.elf

usart.o : usart.c usart.h
	echo "$(T_COMP) usart.c -> usart.o"
	avr-gcc $(CF) -c usart.c $(CCOPTS)

sampling.o : sampling.c sampling.h
	echo "$(T_COMP) sampling.c -> sampling.o"
	avr-gcc $(CF) -c sampling.c $(CCOPTS)

goertzel.o : goertzel.c goertzel.h
	echo "$(T_COMP) goertzel.c -> goertzel.o"
	avr-gcc $(CF) -c goertzel.c $(CCOPTS)

leds.o: leds.c leds.h
	echo "$(T_COMP) leds.c -> leds.o"
	avr-gcc $(CF) -c leds.c $(CCOPTS)

UPLOAD : $(PNAME).hex
	echo "$(T_UPL) $(PNAME).hex"
	avrdude $(UF) -U flash:w:$(PNAME).hex

TERM :
	avrdude $(UF) -t

build: 
	mkdir build

################
# Util Targets #
################
# Cleans up compiled object files / binaries
clean :
	-rm $(PNAME).o $(PNAME).hex $(PNAME).elf sampling.o usart.o goertzel.o
	-rm -r build
