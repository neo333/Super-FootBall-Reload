#ifndef _LEVEL0_SFR
#define _LEVEL0_SFR

#include "Mondo.h"

class Level0:public Mondo{
public:
	Level0(void){

	}
	void Load(void);
	void UnLoad(void);

	void Process(const type_event::mess_event&, OutVideo&);
};

#endif