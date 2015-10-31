#include <SWI-Prolog.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

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

install_t
install() { 
	PL_register_foreign("pullUpDnControl", 2, pl_pullUpDnControl, 0);
}