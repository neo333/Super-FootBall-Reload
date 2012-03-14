#include "Player.h"
#include "global.h"

void Player::Run(const type_event::mess_event& mEvent){
	if(this->pSprite){
		this->Process_Moving(mEvent);
		this->Process_Anim();
		this->Process_SetFace();
	}
}

void Player::Process_Moving(const type_event::mess_event& mEvent){
	this->speed_player.Set_X(0);
	this->speed_player.Set_Y(0);

	if(sys_data::keys_main.DOWN_KEY){
		this->speed_player.Set_Y(this->mod_speed);
	}
	if(sys_data::keys_main.UP_KEY){
		this->speed_player.Set_Y(-this->mod_speed);
	}
	if(sys_data::keys_main.RIGHT_KEY){
		this->speed_player.Set_X(this->mod_speed);
	}
	if(sys_data::keys_main.LEFT_KEY){
		this->speed_player.Set_X(-this->mod_speed);
	}

	this->pSprite->Set_Speed(this->speed_player);
}

void Player::Process_SetFace(void){
	if(this->speed_player.Get_X() > 0){
		this->pSprite->Set_Face(DIR_RIGHT);
	}
	if(this->speed_player.Get_X() < 0){
		this->pSprite->Set_Face(DIR_LEFT);
	}

}