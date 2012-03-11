#ifndef _LEVEL0_SFR
#define _LEVEL0_SFR

#include "Mondo.h"

class Level0:public Mondo{
private:
	void Create_Ball(void);
	std::vector<Sprite*> balls_ingame;

	void Set_PositionSTART_Players(void);
public:
	Level0(void){

	}
	void Load(void);
	void UnLoad(void);

	void Process(const type_event::mess_event&, OutVideo&);
};

#endif