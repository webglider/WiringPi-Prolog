#include <SWI-Prolog.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

int
parse_int(char** str){
	char *a = *str;
	int len = 0;
	while(a[len] != '\0'){
		len++;
	}
	*n = 0;
	int i;
	for(i=len-1;i<=0;i++){
		*n += a[i]*pow(10,i);
	}
	printf("atom parsed! %d\n",*n);
	return n;
}


foreign_t
pl_delayMicroseconds (term_t){
	char *str;
	if(!PL_get_chars(t,&str,CVT_NUMBER)){
		PL_warning("pl_delayMicroseconds/1: instantiation fault in PL_get_chars/2");
	}
	delayMicroseconds(parse_int(&str));
	PL_succeed;
}


static foreign_t
pl_delayMicrosecondsHard(term_t t){
	char *str;
	if(PL_get_chars(t,&str,CVT_NUMBER)){
		PL_warning("pl_********** : instantiation fault in PL_get_chars/1");
	}
	delayMicrosecondsHard(parse_int(&str));
	PL_succeed;
}


static foreign_t
pl_delay(term_t t){
	char *str;
	if(PL_get_chars(t,&str,CVT_NUMBER)){
		PL_warning("pl_********** : instantiation fault in PL_get_chars/1");
	}
	delay(parse_int(&str));
	PL_succeed;
}

static foreign_t
pl_micros (term_t){
	return PL_unify_integer(t,micros());
}
static foreign_t
pl_millis (term_t t){
	return PL_unify_integer(t,millis());
}


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


//pinMode
install_t
install() { 
	PL_register_foreign("wiringPiSetup", 0, pl_wiringPiSetup, 0);
	PL_register_foreign("pinMode", 2, pl_pinMode, 0);
	PL_register_foreign("pwmWrite", 2, pl_pwmWrite, 0);
	PL_register_foreign("digitalRead", 2, pl_digitalRead, 0);
	PL_register_foreign("digitalWrite", 2, pl_digitalWrite, 0);
	PL_register_foreign("pullUpDnControl", 2, pl_pullUpDnControl, 0);	
	PL_register_foreign("wiringPiSetupSys", 2, pl_wiringPiSetupSys, 0);
	PL_register_foreign("wiringPiSetupGpio", 2, pl_wiringPiSetupGpio, 0);
	PL_register_foreign("millis", 2, pl_millis, 0);
	PL_register_foreign("micros", 2, pl_micros, 0);
	PL_register_foreign("delay", 2, pl_delay, 0);
	PL_register_foreign("delayMicrosecondsHard", 2, pl_delayMicrosecondsHard, 0);
	PL_register_foreign("delayMicroseconds", 2, pl_delayMicroseconds, 0);
}
