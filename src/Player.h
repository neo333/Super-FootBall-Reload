#ifndef _PLAYER_SFR
#define _PLAYER_SFR

#include "Sprite.h"
#include "SysEvent.h"

class Player{
private:
	Sprite* pSprite;

	MyVector speed_player;
	Sint16 mod_speed;

	void Process_Moving(const type_event::mess_event&);
	void Process_Anim(void){
		if(this->speed_player.Get_X() || this->speed_player.Get_Y()){
			this->pSprite->Set_Anim(true);
		}else{
			this->pSprite->Set_Anim(false);
		}
	}
	void Process_SetFace(void);
public:
	Player(void):pSprite(NULL),mod_speed(2){
	}

	/*Definisce su quale sprite il giocatore ha il controllo*/
	void Set_Operator_Sprite(Sprite* sp_param){
		this->pSprite=sp_param;
	}

	/*Ritorna il puntatore dello sprite*/
	Sprite* Get_Sprite(void){
		return this->pSprite;
	}

	void Run(const type_event::mess_event&);
};
#endif