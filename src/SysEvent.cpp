#include "SysEvent.h"
#include "global.h"

#ifdef _DEBUG
#include "ConsoleDebug.h"
#include <iostream>
#define _MAX_BUFFER_CMD_DEBUG 100
#endif

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
				break;

#ifdef _DEBUG
			case SDLK_F1:
				{
				bool exit=false;
				std::string cmd_ins;
				char buffer[_MAX_BUFFER_CMD_DEBUG];
				while(!exit){
					std::cout << "CONSOLE DI COMANDO _DEBUG_:\n";
					std::cin.getline(buffer,_MAX_BUFFER_CMD_DEBUG);
					cmd_ins=buffer;
					if(cmd_ins=="exit"){
						exit=true;
					}else{
						ConsoleDebug::Run(cmd_ins);
					}
				}
				break;
				}
#endif

			case SDLK_UP:
				sys_data::keys_main.UP_KEY=true;
				break;

			case SDLK_DOWN:
				sys_data::keys_main.DOWN_KEY=true;
				break;

			case SDLK_RIGHT:
				sys_data::keys_main.RIGHT_KEY=true;
				break;

			case SDLK_LEFT:
				sys_data::keys_main.LEFT_KEY=true;
				break;
			}
			return type_event::KEY_PRESS;
			break;

			//key_unpress
		case SDL_KEYUP:
			switch(mEvent.key.keysym.sym){
			case SDLK_RETURN:
				sys_data::keys_main.KEY_ENTER_PRESS=false;
				break;

			case SDLK_UP:
				sys_data::keys_main.UP_KEY=false;
				break;

			case SDLK_DOWN:
				sys_data::keys_main.DOWN_KEY=false;
				break;

			case SDLK_RIGHT:
				sys_data::keys_main.RIGHT_KEY=false;
				break;

			case SDLK_LEFT:
				sys_data::keys_main.LEFT_KEY=false;
				break;
			}
			return type_event::KEY_RELASE;
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