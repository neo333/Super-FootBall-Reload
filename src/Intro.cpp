#include "Intro.h"
#include "MyTimer.h"
#include "global.h"
#include "Schermata.h"

/*____FILE NAME____*/
static std::string logo_1_pat("Data/images/logo1.bin");
static std::string logo_2_pat("Data/images/logo2.bin");
/*******************/

int Intro::Run(const type_event::mess_event& mEvent, OutVideo& ovideo){
	static short logo_disp=0;
	if(logo_disp==0){
		if(this->logo_1.IsAnim_Alpha()==false){
			this->logo_1.Anim_SetAlpha(255);
		}
		ovideo << this->logo_1;
		if(this->logo_1.IsAnim_Alpha()==false){
			logo_disp++;
		}
	}else{
		if(logo_disp==1){
			if(this->logo_2.IsAnim_Alpha()==false){
				this->logo_2.Anim_SetAlpha(255);
			}
			ovideo << this->logo_2;
			if(this->logo_2.IsAnim_Alpha()==false){
				logo_disp++;
			}
		}else{
			sys_data::app_main->Set_Pointer_Schermata(schermate_game::MENU_PRINCIPALE);
		}
	}
	if((mEvent==type_event::KEY_PRESS || mEvent==type_event::MOUSE_CLIC) && logo_disp < 2){
		if(sys_data::keys_main.KEY_ENTER_PRESS==true){
			logo_disp++;
		}
		if(mEvent==type_event::MOUSE_CLIC){
			logo_disp++;
		}
	}
	return 0;
}

void Intro::Load(void){
	this->logo_1.Load(logo_1_pat);
	this->logo_2.Load(logo_2_pat);
	this->logo_1.SetAlpha(0);
	this->logo_2.SetAlpha(0);
}