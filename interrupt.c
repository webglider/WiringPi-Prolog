#include <SWI-Prolog.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>


static term_t isr_goals[64];

static void call_goal(int pin){
	printf("Executing ISR ... \n");
	PL_call(isr_goals[pin]);
}
static foreign_t
Pl_wiringPiISR(term_t pin, term_t mode, term_t goal){
	char *str_pin,*str_mode;
	if(PL_get_chars(pin,&str_pin,CVT_NUMBER)){
		PL_warning("pl_********** : instantiation fault in PL_get_chars/1");
	}
	if(PL_get_chars(mode,&str_mode,CVT_NUMBER)){
		PL_warning("pl_********** : instantiation fault in PL_get_chars/1");
	}
	if(PL_get_chars(callback,&str_mode,CVT_NUMBER)){
		PL_warning("pl_********** : instantiation fault in PL_get_chars/1");
	}
	void (*callback)(int) = &call_goal;
	wiringPiISR(parse_int(&str_pin),parse_int(mode),callback);
	PL_succeed;
}

foreign_t
pl_waitForInterruptGpio()(term_t pin, term_t t_msec, term_t intr){
	int pin_;
	int msec_;
	if(!PL_get_integer(pin,&pin_)){
		PL_warning("pl_waitForInterruptGpio/3 instantiation fault.")
		PL_fail;
	}
	if(!PL_get_integer(msec,&msec_)){
		PL_warning("pl_waitForInterruptGpio/3 instantiation fault.")
		PL_fail;
	}
	if(!waitForInterruptSys(pin_,msec_)){
		PL_warning("pl_waitForInterruptGpio/3 instantiation fault.");
	}
	return PL_unify_bool(intr,true);
}


foreign_t
pl_waitForInterruptSys()(term_t pin, term_t t_msec, term_t intr){
	int pin_;
	int msec_;
	if(!PL_get_integer(pin,&pin_)){
		PL_warning("pl_waitForInterruptSys/3 instantiation fault.")
		PL_fail;
	}
	if(!PL_get_integer(msec,&msec_)){
		PL_warning("pl_waitForInterruptSys/3 instantiation fault.")
		PL_fail;
	}
	if(!waitForInterruptSys(pin_,msec_)){
		PL_warning("pl_waitForInterruptSys/3 instantiation fault.");
	}
	return PL_unify_bool(intr,true);
}

foreign_t
pl_waitForInterruptWPi()(term_t pin, term_t t_msec, term_t intr){
	int pin_;
	int msec_;
	if(!PL_get_integer(pin,&pin_)){
		PL_warning("pl_waitForInterruptWpi/3 instantiation fault.")
		PL_fail;
	}
	if(!PL_get_integer(msec,&msec_)){
		PL_warning("pl_waitForInterruptWpi/3 instantiation fault.")
		PL_fail;
	}
	if(!waitForInterruptWpi(pin_,msec_)){
		PL_warning("pl_waitForInterruptWpi/3 instantiation fault.");
	}
	return PL_unify_bool(intr,true);
}


