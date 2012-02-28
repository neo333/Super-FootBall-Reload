#include "Tastiera.h"
#include "global.h"

Tastiera sys_data::keys_main;

void Tastiera::FlushKeys(void){
	this->KEY_ENTER_PRESS=false;
}