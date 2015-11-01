:- initialization(wipi_init).


compile_init:-
	shell("gcc -I/usr/lib/swi-prolog/include -fpic -c corefunc.c"),
	shell("gcc -shared -o corefunc.so corefunc.o -Wall -lwiringPi"),

	shell("gcc -I/usr/lib/swi-prolog/include -fpic -c i2c.c"),
	shell("gcc -shared -o i2c.so i2c.o -Wall -lwiringPi"),

	shell("gcc -I/usr/lib/swi-prolog/include -fpic -c timing.c"),
	shell("gcc -shared -o timing.so timing.o -Wall -lwiringPi"),

	shell("gcc -I/usr/lib/swi-prolog/include -fpic -c setup.c"),
	shell("gcc -shared -o setup.so setup.o -Wall -lwiringPi"),

	shell("gcc -I/usr/lib/swi-prolog/include -fpic -c specifics.c"),
	shell("gcc -shared -o specifics.so specifics.o -Wall -lwiringPi").

wipi_init :-
%%	compile_init,

	load_foreign_library(corefunc),
	load_foreign_library(i2c),
%% load_foreign_library(interrupt),
	load_foreign_library(setup),
	load_foreign_library(specifics),
%% load_foreign_library(threads),
	load_foreign_library(timing),

	consult('modes.pl'),
	consult('platform_14052015.pl'),	

	wiringPiSetup.
init(P):-
	platform_start(localhost,P),
	set_token(9595).

blink:-
	output_mode(X),
	pinMode(1,X),
	digitalWrite(1,1),
	delay(1000),
	digitalWrite(1,0),
	delay(1000),
	blink.
