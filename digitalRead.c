#include <SWI-Prolog.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

foreign_t
pl_digitalRead(term_t pin_, term_t value)  {

 	int pin, value, retval; 
 	if(!PL_get_integer(pin_, &pin)) {
		PL_warning("Argument `pin` not number!\n");
		PL_fail;
 	}
	retval = digitalRead(pin);
	PL_unify_integer(value, &retval);
	PL_succeed;      
}

install_t
install() {
	PL_register_foreign("digitalRead", 2, pl_digitalRead, 0);
}