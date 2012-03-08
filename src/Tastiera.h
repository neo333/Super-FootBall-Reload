#ifndef _TASTIERA_SFR
#define _TASTIERA_SFR

class Tastiera{
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
};

#endif