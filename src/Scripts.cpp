#include "Scripts.h"
#include "global.h"

void scripts::Quit_Game(void){
	sys_data::app_main->Close_Game();
}

void scripts::Set_Schermata_Game(void){
	sys_data::app_main->Set_Pointer_Schermata(schermate_game::GAME);
}

void scripts_sprite::script_ball_vone(Sprite& obj){
	obj.Set_Speed(MyVector(0,1));
}