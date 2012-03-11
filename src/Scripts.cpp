#include "Scripts.h"
#include "global.h"

#ifdef _DEBUG
#include <iostream>
#endif

void scripts::Quit_Game(void){
	sys_data::app_main->Close_Game();
}

void scripts::Set_Schermata_Game(void){
	sys_data::app_main->Set_Pointer_Schermata(schermate_game::GAME);
}

void scripts_sprite::script_ball_vone(Sprite& obj){
	const Sprite* obj_col=obj.Get_Collide_Near();
	if(obj_col){
		switch(obj.Pos_Relative(*obj_col)){
		case DIR_UP:
			obj.Set_Speed(MyVector(obj.Get_Speed().Get_X(),obj.Get_Speed().Get_Y()*-1));
			break;
		case DIR_DOWN:
			obj.Set_Speed(MyVector(obj.Get_Speed().Get_X(),obj.Get_Speed().Get_Y()*-1));
			break;
		case DIR_LEFT:
			obj.Set_Speed(MyVector(obj.Get_Speed().Get_X()*-1,obj.Get_Speed().Get_Y()));
			break;
		case DIR_RIGHT:
			obj.Set_Speed(MyVector(obj.Get_Speed().Get_X()*-1,obj.Get_Speed().Get_Y()));
			break;
		}
	}
}