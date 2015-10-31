#include <SWI-Prolog.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>


static foreign_t
pl_wiringPiSetup(){
	if(wiringPiSetup() != 0){
		printf("\nwiringPiSetup failed\n");
		PL_fail;
	}
	PL_succeed;
}

static foreign_t
pl_wiringPiSetupGpio(){
	if(wiringPiSetupGpio() != 0){
		printf("\nwiringPiSetup failed\n");
		PL_fail;
	}
	PL_succeed;
}

static foreign_t
pl_wiringPiSetupSys(){
	if(wiringPiSetupSys() != 0){
		printf("\nwiringPiSetup failed\n");
		PL_fail;
	}
	PL_succeed;
}