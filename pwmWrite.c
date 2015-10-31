#include <SWI-Prolog.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

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

install_t
install() { 
	PL_register_foreign("pwmWrite", 2, pl_pwmWrite, 0);
}