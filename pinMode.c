#include <SWI-Prolog.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

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

install_t
install() { 
	PL_register_foreign("pinMode", 2, pl_pinMode, 0);
}