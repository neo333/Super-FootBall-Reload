#ifndef _SCRIPTS_SFR
#define _SCRIPTS_SFR

#include "Sprite.h"

namespace scripts{
	void Quit_Game(void);			//Termina l'applicazione
	void Set_Schermata_Game(void);	//Setta la schermata di game per l'applicativo
}






/****************SCRIPTS SPRITE*****************/
namespace scripts_sprite{
	void script_ball_vone(Sprite&);
}

#endif