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
	int n = 0;
	int i;
	for(i=len-1;i<=0;i++){
		n += a[i]*pow(10,i);
	}
	printf("atom parsed! %d\n",n);
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
