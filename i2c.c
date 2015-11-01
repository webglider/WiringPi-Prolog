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
	return PL_unify_integer(byte,x);
}

foreign_t
pl_wiringPiI2CReadReg8(term_t fd_, term_t reg_, term_t byte){
	int fd,reg;
	if(!PL_get_integer(fd_,&fd)){
		return PL_warning("Instantiation fault in wiringPiI2CReadReg8/3.");
	}
	if(!PL_get_integer(reg_,&reg)){
		return PL_warning("Instantiation fault in wiringPiI2CReadReg8/3.");
	}
	int x = wiringPiI2CReadReg8(fd, reg);
	if(x < 0){
		return PL_warning("wiringPiI2CReadReg8 failed.");
	}
	return PL_unify_integer(byte,x);
}

foreign_t
pl_wiringPiI2CReadReg16(term_t fd_, term_t reg_, term_t byte){
	int fd,reg;
	if(!PL_get_integer(fd_,&fd)){
		return PL_warning("Instantiation fault in wiringPiI2CReadreg16/3.");
	}
	if(!PL_get_integer(reg_,&reg)){
		return PL_warning("Instantiation fault in wiringPiI2CReadReg16/3.");
	}
	int x = wiringPiI2CReadReg16(fd, reg);
	if(x < 0){
		return PL_warning("wiringPiI2CReadReg16 failed.");
	}
	return PL_unify_integer(byte,x);
}

foreign_t
pl_wiringPiI2CWrite(term_t fd_, term_t byte_){
	int fd,byte;
	if(!PL_get_integer(fd_,&fd)){
		return PL_warning("Instantiation fault in wiringPiI2CWrite/2.");
	}
	if(!PL_get_integer(byte_,&byte)){
		return PL_warning("Instantiation fault in wiringPiI2CWrite/2.");
	}
	if(wiringPiI2CWrite(fd,byte) < 0){
		return PL_warning("wiringPiI2CWrite failed.");
	}
	PL_succeed;
}

foreign_t
pl_wiringPiI2CWriteReg8(term_t fd_, term_t reg_, term_t byte_){
	int fd,byte,reg;
	if(!PL_get_integer(fd_,&fd)){
		return PL_warning("Instantiation fault in wiringPiI2CWriteReg8/3.");
	}
	if(!PL_get_integer(byte_,&byte)){
		return PL_warning("Instantiation fault in wiringPiI2CWriteReg8/3.");
	}
	if(!PL_get_integer(reg_,&reg)){
		return PL_warning("Instantiation fault in wiringPiI2CWriteReg8/3.");
	}
	if(wiringPiI2CWriteReg8(fd,reg,byte) < 0){
		return PL_warning("wiringPiI2CWriteReg8 failed.");
	}
	PL_succeed;
}
foreign_t
pl_wiringPiI2CWriteReg16(term_t fd_, term_t reg_, term_t byte_){
	int fd,byte,reg;
	if(!PL_get_integer(fd_,&fd)){
		return PL_warning("Instantiation fault in wiringPiI2CWriteReg16/3.");
	}
	if(!PL_get_integer(byte_,&byte)){
		return PL_warning("Instantiation fault in wiringPiI2CWriteReg16/3.");
	}
	if(!PL_get_integer(reg_,&reg)){
		return PL_warning("Instantiation fault in wiringPiI2CWriteReg16/3.");
	}
	if(wiringPiI2CWriteReg16(fd,reg,byte) < 0){
		return PL_warning("wiringPiI2CWrite failed.");
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
	return PL_unify_integer(fd,x);
}

install_t
install(){
	PL_register_foreign("wiringPiI2CSetup",2,pl_wiringPiI2CSetup,0);
	PL_register_foreign("wiringPiI2CWriteReg16",3,pl_wiringPiI2CWriteReg16,0);
	PL_register_foreign("wiringPiI2CWriteReg8",3,pl_wiringPiI2CWriteReg8,0);
	PL_register_foreign("wiringPiI2CRead",2,pl_wiringPiI2CRead,0);
	PL_register_foreign("wiringPiI2CWrite",2,pl_wiringPiI2CWrite,0);
	PL_register_foreign("wiringPiI2CReadReg8",3,pl_wiringPiI2CReadReg8,0);
	PL_register_foreign("wiringPiI2CReadReg16",3,pl_wiringPiI2CReadReg16,0);
}
