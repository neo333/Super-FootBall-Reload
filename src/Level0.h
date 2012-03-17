#ifndef _LEVEL0_SFR
#define _LEVEL0_SFR

#include "Mondo.h"

class Sp_Enemy;

class Level0:public Mondo{
private:
	friend class Sp_Enemy;
	void Create_Ball(void);
	std::vector<Sprite*> balls_ingame;
	Sprite* sprite_enemy;

	void Set_PositionSTART_Players(void);
	void Check_Ball_InScreen(void);
public:
	Level0(void):sprite_enemy(NULL){

	}
	void Load(void);
	void UnLoad(void);

	void Process(const type_event::mess_event&, OutVideo&);
};

#endif