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
	if(this->in_moving){
		if(mEvent==type_event::KEY_RELASE){
			switch(this->dir_moving){
			case DIR_DOWN:
				if(!sys_data::keys_main.DOWN_KEY){
					this->in_moving=false;
				}
				break;
			case DIR_UP:
				if(!sys_data::keys_main.UP_KEY){
					this->in_moving=false;
				}
				break;
			case DIR_RIGHT:
				if(!sys_data::keys_main.RIGHT_KEY){
					this->in_moving=false;
				}
				break;
			case DIR_LEFT:
				if(!sys_data::keys_main.LEFT_KEY){
					this->in_moving=false;
				}
				break;
			}
			if(!this->in_moving){
				this->pSprite->Set_Speed(MyVector(0,0));
			}
		}
	}
	
	if(mEvent==type_event::KEY_PRESS){
		Sint16 x_vel=0, y_vel=0;
		bool press_scan=false;

		switch(sys_data::keys_main.Get_Last_Key_operand()){
		case SDLK_DOWN:
			this->dir_moving=DIR_DOWN;
			y_vel=this->rapid_move;
			break;
		case SDLK_UP:
			this->dir_moving=DIR_UP;
			y_vel=-this->rapid_move;
			break;
		case SDLK_LEFT:
			this->dir_moving=DIR_LEFT;
			x_vel=-this->rapid_move;
			break;
		case SDLK_RIGHT:
			this->dir_moving=DIR_RIGHT;
			x_vel=this->rapid_move;
			break;
		}
		if(x_vel || y_vel){
			this->in_moving=true;
			this->pSprite->Set_Speed(MyVector(x_vel,y_vel));
		}
	}
}

void Player::Process_SetFace(void){
	switch(this->dir_moving){
	case DIR_DOWN:
		break;
	case DIR_UP:
		break;
	case DIR_LEFT:
		this->pSprite->Set_Face(this->dir_moving);
		break;
	case DIR_RIGHT:
		this->pSprite->Set_Face(this->dir_moving);
		break;
	}
}