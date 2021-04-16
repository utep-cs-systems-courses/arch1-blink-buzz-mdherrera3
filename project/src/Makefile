COMMON_OBJECTS 	=
CPU		= msp430g2553
CFLAGS		= -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include


CC		= msp430-elf-gcc
AS		= msp430-elf-as

all: toy.elf

toy.elf: ${COMMON_OBJECTS} blinkBuzzMain.o switches.o StateMachines.o buzzer.o led.o wdInterruptHandler.o p2_interrupt_handler.o ../timerLib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: toy.elf
	msp430loader.sh toy.elf

clean:
	rm -f *.o *.elf

led.o: led.c led.h

wdInterruptHandler.o: StateMachines.h led.h switches.h buzzer.h

StateMachines.o: led.h StateMachines.h buzzer.h

buzzer.o: buzzer.h

p2_interrupt_handler.o: switches.h

switches.o: switches.h led.h

blinkBuzzMain.o: led.h switches.h buzzer.h
