#include "Scripts.h"
#include "global.h"

void scripts::Quit_Game(void){
	sys_data::app_main->Close_Game();
}

void scripts::Set_Schermata_Game(void){
	sys_data::app_main->Set_Pointer_Schermata(schermate_game::GAME);
}