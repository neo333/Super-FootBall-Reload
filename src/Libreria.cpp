#include "Libreria.h"
#include <SDL\SDL.h>
#include <sdl\SDL_image.h>
#include <SDL\SDL_ttf.h>
#include <SDL\SDL_mixer.h>

Libreria::Libreria(const LIB_TYPE& lib_param):loaded(false), typ_library(lib_param){

}

Libreria::~Libreria(void){
	this->Chiudi_Libreria();
}

void Libreria::Chiudi_Libreria(void){
	if(this->loaded){
		switch(this->typ_library){
		case SDL_MAIN:
			SDL_Quit();
			break;
		case SDL_IMG:
			IMG_Quit();
			break;
		case SDL_TTF:
			TTF_Quit();
			break;
		case SDL_MIX:
			Mix_Quit();
			break;
		default:
			break;
		}
		this->loaded=false;
	}
}

bool Libreria::Apri_Libreria(void){
	if(!this->loaded){
		switch(this->typ_library){
		case SDL_MAIN:
			if(SDL_Init(SDL_INIT_EVENTTHREAD)!=0){
				return false;
			}
			break;
		case SDL_IMG:{
			int flags=IMG_INIT_JPG|IMG_INIT_PNG;
			int initted=IMG_Init(flags);
			if((initted&flags) != flags){
				return false;
			}
			break;
					 }
		case SDL_TTF:
			if(TTF_Init()!=0){
				return false;
			}
			break;
		case SDL_MIX:{
			int flags=MIX_INIT_OGG|MIX_INIT_MOD;
			int initted=Mix_Init(flags);
			if((initted&flags) != flags){
				return false;
			}
			break;
					 }
		default:
			return false;
			break;
		}
		this->loaded=true;
		return true;
	}else{
		this->Chiudi_Libreria();
		return this->Apri_Libreria();
	}
}