#include <SDL\SDL_collide.h>
#include "Bgui.h"
#include "global.h"

OutVideo& operator<<(OutVideo& screen, Bgui& oth){
	oth.Process();
	unsigned int size=oth.int_components.size();
	SDL_Rect pos,cut;
	Component* pointer;
	for(register unsigned int i=0; i<size; i++){
		pointer=&oth.int_components[i];
		if(pointer->surf_component.IsLoaded()){
			pos.x=oth.x + pointer->x_component;
			pos.y=oth.y + pointer->y_component;

			if(pointer->cut_component){
				cut.x=pointer->x_cut;
				cut.y=pointer->y_cut;
				cut.w=pointer->w_cut;
				cut.h=pointer->h_cut;
				OutVideo::BlitSurface(pointer->surf_component,&cut,screen,&pos);
			}else{
				OutVideo::BlitSurface(pointer->surf_component,NULL,screen,&pos);
			}
		}
	}
	return screen;
}

void Bgui::SetColorKey(const int& index, const Colors& color_param){
	bool error=false;
	if(index<0){
		unsigned int size=this->int_components.size();
		for(register unsigned int i=0; i<size; i++){
			Uint32 mask=SDL_MapRGB(this->GetSurface_Component(i).PixelFormat(), color_param.c_red, color_param.c_green, color_param.c_blue);
			if(SDL_SetColorKey(this->GetSurface_Component(i), SDL_SRCCOLORKEY | SDL_RLEACCEL, mask)!=0){
				error=true;
			}
		}
	}else{
		Uint32 mask=SDL_MapRGB(this->GetSurface_Component(index).PixelFormat(), color_param.c_red, color_param.c_green, color_param.c_blue);
		if(SDL_SetColorKey(this->GetSurface_Component(index), SDL_SRCCOLORKEY | SDL_RLEACCEL, mask)!=0){
			error=true;
		}
	}

	if(error){
		OutRegistro(Errore_Form("1xECOLKEY_BGUI","Impossibile ottimizzare la risorsa richiesta dall'applicazione!"));
#ifdef _DEBUG
		sys_data::Registro << SDL_GetError() << "\n";
#endif
		sys_data::app_main->SetError();
	}
}

void Bgui::SetAlpha(const int& index, const Uint8& alpha_param){
	bool error=false;
	if(index<0){
		unsigned int size=this->int_components.size();
		for(register unsigned int i=0; i<size; i++){
			if(SDL_SetAlpha(this->GetSurface_Component(i), SDL_RLEACCEL | SDL_SRCALPHA, alpha_param)!=0){
				error=true;
			}
		}
	}else{
		if(SDL_SetAlpha(this->GetSurface_Component(index), SDL_RLEACCEL | SDL_SRCALPHA, alpha_param)!=0){
				error=true;
			}
	}

	if(error){
		OutRegistro(Errore_Form("1xEALPHA_BGUI","Impossibile ottimizzare la risorsa richiesta dall'applicazione!"));
#ifdef _DEBUG
		sys_data::Registro << SDL_GetError() << "\n";
#endif
		sys_data::app_main->SetError();
	}
}

MySurface* Bgui::GetSurface_AtPos(const Sint16& x_pix, const Sint16& y_pix, int& index){
	index=-1;
	unsigned int size=this->int_components.size();
	Component* pointer;
	Sint16 x_temp,y_temp,w_temp,h_temp;
	for(register unsigned int i=0; i<size; i++){
		pointer=&this->int_components[i];
		x_temp=this->GetX()+pointer->x_component;
		y_temp=this->GetY()+pointer->y_component;
		w_temp=x_temp;
		h_temp=y_temp;
		if(pointer->cut_component){
			w_temp+=pointer->w_cut;
			h_temp+=pointer->h_cut;
		}else{
			w_temp+=pointer->surf_component.Get_WSurface();
			h_temp+=pointer->surf_component.Get_HSurface();
		}
		
		if(x_pix>=x_temp && x_pix<=w_temp && y_pix>=y_temp && y_pix<=h_temp){
			index=i;
			return &pointer->surf_component;
		}
	}
	return NULL;
}

bool Bgui::GetColorPixel(Colors& color_param, const Sint16& x_pix, const Sint16 y_pix){
	Sint16 x_rel=x_pix + this->GetX();
	Sint16 y_rel=y_pix + this->GetY();

	int index;
	MySurface* pnt=this->GetSurface_AtPos(x_rel,y_rel,index);
	if(pnt==NULL){
		return false;
	}
	return pnt->GetColorPixel(color_param,x_pix,y_pix);
}