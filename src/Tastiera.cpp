#include "Tastiera.h"
#include "global.h"

Tastiera sys_data::keys_main;

void Tastiera::FlushKeys(void){
	this->KEY_ENTER_PRESS=false;
	this->DOWN_KEY=false;
	this->LEFT_KEY=false;
	this->RIGHT_KEY=false;
	this->UP_KEY=false;
}