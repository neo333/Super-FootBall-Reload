#include "OutSound.h"
#include <SDL/SDL_mixer.h>

OutSound::OutSound(void):loaded(false){

}

OutSound::~OutSound(void){
	this->CloseSystem();
}

bool OutSound::LoadSystem(void){
	if(!this->loaded){
		if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024)==0){
			this->loaded=true;
			return true;
		}
	}
	return false;
}

void OutSound::CloseSystem(void){
	if(this->loaded){
		Mix_CloseAudio();
		this->loaded=false;
	}
}

OutSound& OutSound::operator<<(Sound& oth){
	if(oth.IsLoaded()){
		if(Mix_PlayChannel(-1, oth, 0)==-1){
			//TODO: errror
		}
	}
	return *this;
}
