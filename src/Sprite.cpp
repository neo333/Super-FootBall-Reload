#include "Sprite.h"
#include "global.h"

void Sprite::Load(const std::string& file_name){
	this->int_components[0].surf_component.Load(file_name);
}

void Sprite::Process(void){
	Sint16 xc,yc,wc=40,hc=62;
	switch(this->face){
	case DIR_UP:
		yc=0;
		break;
	case DIR_DOWN:
		yc=1*40;
		break;
	case DIR_LEFT:
		yc=2*40;
		break;
	case DIR_RIGHT:
		yc=3*40;
		break;
	default:
		//TODO: fare errore (non può verificarsi questa possibilità!)
		break;
	}
	if(this->anim){
		if(this->delay_frames.Scaduto()){
			this->frame++;
			this->delay_frames.Start();
		}
	}else{
		this->frame=0;
	}
	yc=this->frame*62;

	Component* pcomp=&this->int_components[0];
	pcomp->cut_component=true;
	pcomp->x_cut=xc;
	pcomp->y_cut=yc;
	pcomp->w_component=wc;
	pcomp->h_component=hc;
}