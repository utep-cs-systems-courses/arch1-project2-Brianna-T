# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: toy.elf 

#additional rules for files
toy.elf: ${COMMON_OBJECTS} Blinkmain.o stateM.o Blinkled.o interrupt.o buzz.o Buzzmain.o ../Timer.a
	${CC} ${CFLAGS} -o $@ $^

load: toy.elf
	msp430loader.sh toy.elf

clean:
	rm -f *.o *.elf

Blinkled.o: Blinkled.c
interrupt.o: interrupt.c
stateM.o:Blinkled.c stateM.c

buzzer.c: buzz.c
buzzerMain.c: buzz.c


