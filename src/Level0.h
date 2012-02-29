#ifndef _LEVEL0_SFR
#define _LEVEL0_SFR

#include "Mondo.h"

class Level0:public Mondo{
private:
	void Process(void);
public:
	void Load(void);
	void UnLoad(void);
};

#endif