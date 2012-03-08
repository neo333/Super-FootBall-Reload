#ifndef _PLAYER_SFR
#define _PLAYER_SFR

#include "Sprite.h"
#include "SysEvent.h"

class Player{
private:
	Sprite* pSprite;

	bool in_moving;
	Sint16 rapid_move;
	Direction dir_moving;

	void Process_Moving(const type_event::mess_event&);
	void Process_Anim(void){
		this->pSprite->Set_Anim(this->in_moving);
	}
public:
	Player(void):pSprite(NULL),in_moving(false),rapid_move(2){
	}

	/*Definisce su quale sprite il giocatore ha il controllo*/
	void Set_Operator_Sprite(Sprite* sp_param){
		this->pSprite=sp_param;
	}

	void Run(const type_event::mess_event&);
};
#endif