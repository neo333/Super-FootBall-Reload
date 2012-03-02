#ifndef _LEVEL0_SFR
#define _LEVEL0_SFR

#include "Mondo.h"

class Level0:public Mondo{
private:
	Sprite* ctrl_key;
public:
	Level0(void):ctrl_key(NULL){

	}
	void Load(void);
	void UnLoad(void);

	void Process(const type_event::mess_event&, OutVideo&);
};

#endif