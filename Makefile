


all:	corefunc.so i2c.so setup.so specifics.so timing.so

corefunc.o: corefunc.c
	gcc -I/usr/lib/swi-prolog/include -fpic -c corefunc.c

i2c.o: i2c.c
	gcc -I/usr/lib/swi-prolog/include -fpic -c i2c.c

setup.o: setup.c
	gcc -I/usr/lib/swi-prolog/include -fpic -c setup.c

specifics.o: specifics.c
	gcc -I/usr/lib/swi-prolog/include -fpic -c specifics.c

timing.o: timing.c
	gcc -I/usr/lib/swi-prolog/include -fpic -c timing.c



corefunc.so: corefunc.o
	gcc -shared -o ./build/corefunc.so corefunc.o -Wall -lwiringPi

i2c.so: i2c.o
	gcc -shared -o ./build/i2c.so i2c.o -Wall -lwiringPi

setup.so: setup.o
	gcc -shared -o ./build/setup.so setup.o -Wall -lwiringPi

specifics.so: specifics.o
	gcc -shared -o ./build/specifics.so specifics.o -Wall -lwiringPi

timing.so: timing.o
	gcc -shared -o ./build/timing.so timing.o -Wall -lwiringPi


clean:
	rm *o 
