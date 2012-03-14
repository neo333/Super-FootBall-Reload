#include "Sp_Ball.h"

void Sp_Ball::Main_Script(void){
	const Collision* obj_col=this->Get_Collide_Near();
	if(obj_col){
		switch(obj_col->Get_DirectionObj()){
		case DIR_UP:
			this->Set_Speed(MyVector(this->Get_Speed().Get_X(),this->Get_Speed().Get_Y()*-1));
			break;
		case DIR_DOWN:
			this->Set_Speed(MyVector(this->Get_Speed().Get_X(),this->Get_Speed().Get_Y()*-1));
			break;
		case DIR_LEFT:
			this->Set_Speed(MyVector(this->Get_Speed().Get_X()*-1,this->Get_Speed().Get_Y()));
			break;
		case DIR_RIGHT:
			this->Set_Speed(MyVector(this->Get_Speed().Get_X()*-1,this->Get_Speed().Get_Y()));
			break;
		}
	}
}