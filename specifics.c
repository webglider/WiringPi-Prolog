#include <SWI-Prolog.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>


static foreign_t
pl_digitalWriteByte(term_t t){

	int value;
	if (!PL_get_integer(t,&value)) {
		PL_warning("Argument `value` not number!\n");
		PL_fail;
	}

	digitalWriteByte(value);
	PL_succeed;	
}

static foreign_t
pl_pwmSetMode (term_t mode_){

	int mode;

	if (!PL_get_integer(mode_,&mode)) {
		PL_warning("Argument `mode` not number!\n");
		PL_fail;		
	}

	pwmSetMode(mode);
	PL_succeed;
}

static foreign_t
pl_pwmSetRange (term_t range_){

	unsigned int range;

	if (!PL_get_integer(range_,&range)) {
		PL_warning("Argument `range` not number!\n");
		PL_fail;		
	}
	if (range<0)
	{
		PL_warning("Argument 'range' not unsigned one!\n");
		PL_fail;
	}

	pwmSetRange(range);
	PL_succeed;
}

static foreign_t
pl_pwmSetClock (term_t divisor_){

	int divisor;

	if (!PL_get_integer(divisor_,&divisor)) {
		PL_warning("Argument `divisor` not number!\n");
		PL_fail;		
	}

	pwmSetClock(divisor);
	PL_succeed;
}

static foreign_t
pl_piBoardRev (term_t t){
	return PL_unify_integer(t,piBoardRev());
}

static foreign_t
pl_wpiPinToGpio (term_t wPiPin_,term_t t){
	int wPiPin;	
	if (!PL_get_integer(wPiPin_,&wPiPin))
	{
		PL_warning("Argument 'wPiPin' not number");
		PL_fail;
	}
	return PL_unify_integer(t,wpiPinToGpio(wPiPin));
}

static foreign_t
pl_physPinToGpio (term_t physPin_,term_t t){
	int physPin;	
	if (!PL_get_integer(physPin_,&physPin))
	{
		PL_warning("Argument 'physPin' not number");
		PL_fail;
	}

	return PL_unify_integer(t,physPinToGpio(physPin));
}

static foreign_t
pl_setPadDrive (term_t group_, term_t value_){
	int group,value;
	if (!PL_get_integer(group,&group))
	{
		PL_warning("Argument 'group' not number");
		PL_fail;
	}
	if (!PL_get_integer(value,&value))
	{
		PL_warning("Argument 'value' not number");
		PL_fail;
	}

	setPadDrive(group,value);
	PL_succeed;

}


//pinMode
install_t
install() { 	
	// pi specifics install() 
	PL_register_foreign("digitalWriteByte",2,pl_digitalWriteByte,0);
	PL_register_foreign("pwmSetMode",1,pl_pwmSetMode,0);
	PL_register_foreign("pwmSetRange",1,pl_pwmSetRange,0);
	PL_register_foreign("pwmSetClock",1,pl_pwmSetClock,0);
	PL_register_foreign("piBoardRev",1,pl_piBoardRev,0);
	PL_register_foreign("wpiPinToGpio",2,pl_wpiPinToGpio,0);
	PL_register_foreign("physPinToGpio",2,pl_physPinToGpio,0);
	PL_register_foreign("setPadDrive",2,pl_setPadDrive,0);
}
