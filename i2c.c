#include <SWI-Prolog.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

foreign_t
pl_wiringPiI2CRead(term_t fd_,term_t byte){
	int fd;
	if(!PL_get_integer(fd_,&fd)){
		return PL_warning("Instantiation fault in wiringPiI2CRead/2.");
	}
	int x = wiringPiI2CRead(fd);
	if(x < 0){
		return PL_warning("wiringPiI2CRead failed.");
	}
	return PL_unify_integer(byte,&x);
}

foreign_t
pl_wiringPiI2CReadReg8(term_t fd_,term_t byte){
	int fd;
	if(!PL_get_integer(fd_,&fd)){
		return PL_warning("Instantiation fault in wiringPiI2CReadReg8/2.");
	}
	int x = wiringPiI2CReadReg8(fd);
	if(x < 0){
		return PL_warning("wiringPiI2CReadReg8 failed.");
	}
	return PL_unify_integer(byte,&x);
}

foreign_t
pl_wiringPiI2CRead16(term_t fd_,term_t byte){
	int fd;
	if(!PL_get_integer(fd_,&fd)){
		return PL_warning("Instantiation fault in wiringPiI2CReadreg16/2.");
	}
	int x = wiringPiI2CReadReg16(fd);
	if(x < 0){
		return PL_warning("wiringPiI2CReadReg16 failed.");
	}
	return PL_unify_integer(byte,&x);
}

foreign_t
pl_wiringPII2CWrite(term_t fd_, term_t byte_){
	int fd,byte;
	if(!PL_get_integer(fd_,&fd)){
		return PL_warning("Instantiation fault in wiringPiI2CWrite/2.");
	}
	if(!PL_get_integer(byte_,&byte)){
		return PL_warning("Instantiation fault in wiringPiI2CWrite/2.");
	}
	if(wiringPII2CWrite(fd,byte) < 0){
		return PL_warning("wiringPII2CWrite failed.");
	}
	PL_succeed;
}

foreign_t
pl_wiringPII2CWriteReg8(term_t fd_, term_t byte_){
	int fd,byte;
	if(!PL_get_integer(fd_,&fd)){
		return PL_warning("Instantiation fault in wiringPII2CWriteReg8/2.");
	}
	if(!PL_get_integer(byte_,&byte)){
		return PL_warning("Instantiation fault in wiringPII2CWriteReg8/2.");
	}
	if(wiringPII2CWriteReg8(fd,byte) < 0){
		return PL_warning("wiringPII2CWriteReg8 failed.");
	}
	PL_succeed;
}
foreign_t
pl_wiringPII2CWriteReg16(term_t fd_, term_t byte_){
	int fd,byte;
	if(!PL_get_integer(fd_,&fd)){
		return PL_warning("Instantiation fault in wiringPiI2CWriteReg16/2.");
	}
	if(!PL_get_integer(byte_,&byte)){
		return PL_warning("Instantiation fault in wiringPiI2CWriteReg16/2.");
	}
	if(wiringPiI2CWriteReg16(fd,byte) < 0){
		return PL_warning("wiringPII2CWrite failed.");
	}
	PL_succeed;
}


foreign_t
pl_wiringPiI2CSetup(term_t devId_,term_t fd){
	int devId;
	if(!PL_get_integer(devId_,&devId)){
		return PL_warning("Instantiation fault in wiringPiI2CSetup/1");
	}
	int x = wiringPiI2CSetup(devId);
	if(x < 0){
		return PL_warning("wiringPiI2CSetup failed.");
	}
	return PL_unify_integer(fd,&x);
}