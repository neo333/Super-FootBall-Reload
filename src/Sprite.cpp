#include "Sprite.h"
#include "global.h"

void Sprite::Load(const std::string& file_name){
	this->GetSurface_Component(0).Load(file_name);
	this->SetColorKey(0);
}

void Sprite::Process(void){
	Sint16 xc,yc;
	const Sint16 wc=40,hc=62;
	switch(this->face){
	case DIR_UP:
		yc=3*hc;
		break;
	case DIR_DOWN:
		yc=0*hc;
		break;
	case DIR_LEFT:
		yc=1*hc;
		break;
	case DIR_RIGHT:
		yc=2*hc;
		break;
	default:
		//TODO: fare errore (non può verificarsi questa possibilità!)
		break;
	}
	if(this->anim){
		if(this->delay_frames.Scaduto()){
			this->frame++;
			if(this->frame>3){
				this->frame=0;
			}
			this->delay_frames.Start();
		}
	}else{
		this->frame=0;
	}
	xc=this->frame*wc;

	Component* pcomp=&this->int_components[0];
	pcomp->cut_component=true;
	pcomp->x_cut=xc;
	pcomp->y_cut=yc;
	pcomp->w_component=wc;
	pcomp->h_component=hc;
}