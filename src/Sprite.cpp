#include "Sprite.h"
#include "global.h"

namespace dims_frames{
	static const Sint16 wc=40;
	static const Sint16 hc=62;
	static const Sint16 n_frames=4;
}

void Sprite::Load(const std::string& file_name){
	this->GetSurface_Component(0).Load(file_name);
	this->Load_BoxCollide(file_name);
	this->SetColorKey(0);	
}

void Sprite::Process(void){
	Sint16 xc,yc;
	switch(this->face){
	case DIR_UP:
		yc=3*dims_frames::hc;
		break;
	case DIR_DOWN:
		yc=0*dims_frames::hc;
		break;
	case DIR_LEFT:
		yc=1*dims_frames::hc;
		break;
	case DIR_RIGHT:
		yc=2*dims_frames::hc;
		break;
	default:
		//TODO: fare errore (non può verificarsi questa possibilità!)
		break;
	}
	if(this->anim){
		if(this->delay_frames.Scaduto()){
			this->frame++;
			if(this->frame>=dims_frames::n_frames){
				this->frame=0;
			}
			this->delay_frames.Start();
		}
	}else{
		this->frame=0;
	}
	xc=this->frame*dims_frames::wc;

	Component* pcomp=&this->int_components[0];
	pcomp->cut_component=true;
	pcomp->x_cut=xc;
	pcomp->y_cut=yc;
	pcomp->w_cut=dims_frames::wc;
	pcomp->h_cut=dims_frames::hc;
}

void Sprite::Load_BoxCollide(const std::string& filename){
	//TODO: da fare funzione!!
}