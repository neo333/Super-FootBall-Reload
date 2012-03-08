#include "Player.h"
#include "global.h"

void Player::Run(const type_event::mess_event& mEvent){
	if(this->pSprite){
		this->Process_Moving(mEvent);
		this->Process_Anim();
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
	}else{
		if(mEvent==type_event::KEY_PRESS){
			Sint16 x_vel=0, y_vel=0;
			if(sys_data::keys_main.DOWN_KEY){
				this->dir_moving=DIR_DOWN;
				y_vel=this->rapid_move;
			}
			if(sys_data::keys_main.UP_KEY){
				this->dir_moving=DIR_UP;
				y_vel=-this->rapid_move;
			}
			if(sys_data::keys_main.LEFT_KEY){
				this->dir_moving=DIR_LEFT;
				x_vel=-this->rapid_move;
			}
			if(sys_data::keys_main.RIGHT_KEY){
				this->dir_moving=DIR_RIGHT;
				x_vel=this->rapid_move;
			}
			if(x_vel || y_vel){
				this->in_moving=true;
				this->pSprite->Set_Speed(MyVector(x_vel,y_vel));
			}
		}
	}
}