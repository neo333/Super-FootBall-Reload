#include "Picture.h"
#include <SDL/SDL_rotozoom.h>

Picture::Picture(void):angle_curr(0), zoom_curr(0), alpha_curr(255), alpha_process(false){

}

void Picture::ModZoom(const double& zoom_param){
	this->GetSurface_Component(0)=rotozoomSurface(this->GetSurface_Component(0),this->angle_curr,zoom_param,SMOOTHING_ON);
	this->zoom_curr=zoom_param;
}

void Picture::Anim_SetAlpha(const Uint8& alpha_param){
	this->alpha_dest=alpha_param;
	this->alpha_process=true;
}

void Picture::Process(void){
	if(this->alpha_process){
		if(this->alpha_dest > this->alpha_curr){
			this->SetAlpha(this->alpha_curr+1);
		}else{
			this->SetAlpha(this->alpha_curr-1);
		}
		if(this->alpha_dest==this->alpha_curr){
			this->alpha_process=false;
		}
	}
}

void Picture::Load(const std::string& filename){
	this->GetSurface_Component(0).Load(filename);
}

void Picture::FreeSurface(void){
	this->GetSurface_Component(0).FreeSurface();
}
