#ifndef _SP_ENEMY_SFR
#define _SP_ENEMY_SFR

#include "Sprite.h"
#include "Level0.h"
#include "MyTimer.h"

enum TYPE_ACTION{
	STAY,
	OFFENSIVE,
	RETURN
};

class Sp_Enemy: public Sprite{
private:
	virtual void Main_Script(void);
	std::vector<Sprite*>* balls_ingame;
	Sprite* sprite_player;
	Sint16 rapid_move;
	Sint16 sfaso_precision;
	MyTimer rand_gen;

	TYPE_ACTION action;

	//cervello nemico
	void CTRL_Action(const Sprite* ball);
	//
public:
	Sp_Enemy(Level0*);
};

#endif