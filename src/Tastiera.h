#ifndef _TASTIERA_SFR
#define _TASTIERA_SFR

#include "SysEvent.h"

class Tastiera{
private:
	friend class SysEvent;
	SDLKey Last_effect_key;
public:
	Tastiera(void){
		this->FlushKeys();
	}
	void FlushKeys(void);

	/*KEYS*/
	bool KEY_ENTER_PRESS;
	bool UP_KEY;
	bool DOWN_KEY;
	bool LEFT_KEY;
	bool RIGHT_KEY;
	/*****/

	/**funzioni aggiuntive***/
	/*Ritorna l'ultimo tasto premuto/rilasciato*/
	const SDLKey& Get_Last_Key_operand(void) const{
		return this->Last_effect_key;
	}
	/***********************/
};

#endif