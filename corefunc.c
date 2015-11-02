#include <SWI-Prolog.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

//wiringPiSetup
foreign_t
pl_wiringPiSetup()  {
	wiringPiSetup();
	PL_succeed;      
}


//pinMode
foreign_t
pl_pinMode(term_t pin_, term_t mode_)  {
 	
 	int pin, mode; 
 	if(!PL_get_integer(pin_, &pin)) {
 		PL_warning("Argument `pin` not number!\n");
 		PL_fail;
 	}

 	if(!PL_get_integer(mode_, &mode)) {
 		PL_warning("Argument `mode` not number!\n");
 		PL_fail;
 	}
	pinMode(pin, mode);
	PL_succeed;      
}
//pwmWrite
foreign_t
pl_pwmWrite(term_t pin_, term_t value_)  {
 	
 	int pin, value; 
 	if(!PL_get_integer(pin_, &pin)) {
 		PL_warning("Argument `pin` not number!\n");
 		PL_fail;
 	}

 	if(!PL_get_integer(value_, &value)) {
 		PL_warning("Argument `value` not number!\n");
 		PL_fail;
 	} 
	pwmWrite(pin, value);
	PL_succeed;      
}
//digitalRead
foreign_t
pl_digitalRead(term_t pin_, term_t value)  {

 	int pin, retval; 
 	if(!PL_get_integer(pin_, &pin)) {
		PL_warning("Argument `pin` not number!\n");
		PL_fail;
 	}
	retval = digitalRead(pin);
	return PL_unify_integer(value, retval);     
}
//digitalWrite
foreign_t
pl_digitalWrite(term_t pin_, term_t value_)  {
 	
 	int pin, value; 
 	if(!PL_get_integer(pin_, &pin)) {
 		PL_warning("Argument `pin` not number!\n");
 		PL_fail;
 	}

 	if(!PL_get_integer(value_, &value)) {
 		PL_warning("Argument `value` not number!\n");
 		PL_fail;
 	} 
	digitalWrite(pin, value);
	PL_succeed;      
}
//pullUpDnControl
foreign_t
pl_pullUpDnControl(term_t pin_, term_t pud_)  {

 	int pin, pud; 
 	if(!PL_get_integer(pin_, &pin)) {
 		PL_warning("Argument `pin` not number!\n");
 		PL_fail;
 	}

 	if(!PL_get_integer(pud_, &pud)) {
 		PL_warning("Argument `pud` not number!\n");
 		PL_fail;
 	} 
	pullUpDnControl(pin, pud);
	PL_succeed;      
}


//pinMode
install_t
install() { 
	PL_register_foreign("wiringPiSetup", 0, pl_wiringPiSetup, 0);
	PL_register_foreign("pinMode", 2, pl_pinMode, 0);
	PL_register_foreign("pwmWrite", 2, pl_pwmWrite, 0);
	PL_register_foreign("digitalRead", 2, pl_digitalRead, 0);
	PL_register_foreign("digitalWrite", 2, pl_digitalWrite, 0);
	PL_register_foreign("pullUpDnControl", 2, pl_pullUpDnControl, 0);
}
