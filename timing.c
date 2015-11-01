#include <SWI-Prolog.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <math.h>


foreign_t
pl_delayMicroseconds (term_t t_){
	int t;
	if(!PL_get_integer(t_,&t)){
		PL_warning("pl_delayMicroseconds/1: instantiation fault in PL_get_chars/2");
	}
	delayMicroseconds(t);
	PL_succeed;
}


static foreign_t
pl_delayMicrosecondsHard(term_t t_){
	int t;
	if(!PL_get_integer(t_,&t)){
		PL_warning("pl_********** : instantiation fault in PL_get_chars/1");
	}
	delayMicrosecondsHard(t);
	PL_succeed;
}


static foreign_t
pl_delay(term_t t_){
	int t;
	if(!PL_get_integer(t_,&t)){
		PL_warning("pl_********** : instantiation fault in PL_get_chars/1");
	}
	delay(t);
	PL_succeed;
}

static foreign_t
pl_micros (term_t t){
	return PL_unify_integer(t,micros());
}
static foreign_t
pl_millis (term_t t){
	return PL_unify_integer(t,millis());
}


install_t
install(){
	PL_register_foreign("delayMicroseconds",1,pl_delayMicroseconds,0);
	PL_register_foreign("delayMicrosecondsHard",1,pl_delayMicrosecondsHard,0);
	PL_register_foreign("delay",1,pl_delay,0);
	PL_register_foreign("micros",1,pl_micros,0);
	PL_register_foreign("millis",1,pl_millis,0);
}
