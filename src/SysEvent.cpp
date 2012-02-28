#include "SysEvent.h"
#include "global.h"

type_event::mess_event SysEvent::UpDateEvents(void){
	if(SDL_PollEvent(&this->mEvent)){
		switch(this->mEvent.type){
			//mouse motion
		case SDL_MOUSEMOTION:
			sys_data::Mouse_Coordinate.x=this->mEvent.motion.x;
			sys_data::Mouse_Coordinate.y=this->mEvent.motion.y;
			break;

			//quit
		case SDL_QUIT:
			return type_event::QUIT_APP;
			break;

			//key_press
		case SDL_KEYDOWN:
			switch(mEvent.key.keysym.sym){
			case SDLK_RETURN:
				sys_data::keys_main.KEY_ENTER_PRESS=true;
				return type_event::KEY_PRESS;
				break;
			}
			break;

			//key_unpress
		case SDL_KEYUP:
			switch(mEvent.key.keysym.sym){
			case SDLK_RETURN:
				sys_data::keys_main.KEY_ENTER_PRESS=false;
				return type_event::KEY_RELASE;
				break;
			}
			break;

			//mouse press
		case SDL_MOUSEBUTTONDOWN:
			if(mEvent.button.button==SDL_BUTTON_LEFT){
				return type_event::MOUSE_CLIC;
			}
		}
	}
	return type_event::NONE;
}