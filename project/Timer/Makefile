all: Timer.a

CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as
AR              = msp430-elf-ar

Timer.a: timer.o
	$(AR) crs $@ $^

install: Timer.a
	mkdir -p ../h ../timer
	mv $^ ../timer
	cp *.c ../c

clean:
	rm -f timer.a *.o

