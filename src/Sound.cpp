#include "Sound.h"
#include "global.h"

Sound::Sound(void):pSound(NULL){

}

Sound::~Sound(void){
	this->FreeSound();
}

void Sound::FreeSound(void){
	if(this->pSound){
		Mix_FreeChunk(this->pSound);
		this->pSound=NULL;
	}
}

bool Sound::LoadSound(const std::string& filename_param){
	if(filename_param.size()>0){
		this->FreeSound();
		this->pSound=sys_data::hd_sysdata.LoadSound_to_file(filename_param);
		this->filename_mem=filename_param;
		return true;
	}
	return false;
}

Sound& Sound::operator=(const Sound& oth){
	if(&oth!=this){
		this->LoadSound(oth.filename_mem);
	}
	return *this;
}

bool Sound::IsLoaded(void) const{
	if(this->pSound){
		return true;
	}
	return false;
}

Sound::operator Mix_Chunk*(void){
	return this->pSound;
}

Sound::operator int(void){
	return (int)(this->pSound);
}