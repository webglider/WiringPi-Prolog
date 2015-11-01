#include <SWI-Prolog.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

foreign_t
pl_piHiPri(term_t priority_){
	int priority;
	if(!PL_get_integer(priority_,&priority)){
		return PL_warning("Instantiation falut piHiPri/1");
	}
	if(piHiPri(priority) < 0){
		printf("set priority failed\n");
	}
	else{
		printf("priority successfully updated\n");
	}
	PL_succeed;
}

foreign_t
pl_piThreadCreate(term_t name_){
	char *name;
	if(!PL_get_atom_chars(name_,&name)){
		return PL_warning("Instantiation fault in piThreadCreate/1");
	}
	piThreadCreate(&name);
	PL_succeed;
}

foreign_t
pl_piLock(term_t keyNum_){
	int keyNum;
	if(!PL_get_integer(keyNum_,&keyNum)){
		return PL_warning("Instantiation fault in piLock/1.");
	}
	piLock(keyNum);
	PL_succeed;
}

foreign_t
pl_piUnlock(term_t keyNum_){
	int keyNum;
	if(!PL_get_integer(keyNum_,&keyNum)){
		return PL_warning("Instantiation fault in piUnlock/1.");
	}
	piUnlock(keyNum);
	PL_succeed;
}
