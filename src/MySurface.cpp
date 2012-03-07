#include "MySurface.h"
#include "global.h"

void MySurface::Load(const std::string& filename){
	this->FreeSurface();
	if(sys_data::hd_sysdata.LoadSurface_to_file(filename,*this)==false){
		//TODO: gestire l'errore!
		sys_data::app_main->SetError();
	}
}

MySurface& MySurface::operator=(const MySurface& oth){
	if(&oth==this){
		OutRegistro(Errore_Form("2xOPNTVL_PNT","La gestione di un'operazione della memoria\n"
												"ha comportato un'abiguita' del sistema"));
		return *this;
	}
	this->FreeSurface();
	if(oth.psurface){
		this->psurface=SDL_DisplayFormat(oth.psurface);
	}
	return *this;
}

bool MySurface::GetColorPixel(Colors& color_param, const Sint16& x_pix, const Sint16& y_pix){
	if(this->psurface && x_pix < this->Get_WSurface() && y_pix < this->Get_HSurface()){
		SDL_LockSurface(this->psurface);
		int bpp = this->psurface->format->BytesPerPixel;
		Uint8 *p = (Uint8 *)this->psurface->pixels + y_pix * this->psurface->pitch + x_pix * bpp;
		color_param.c_red=*p;
		color_param.c_green=*(p+1);
		color_param.c_blue=*(p+2);

		SDL_UnlockSurface(this->psurface);
	}else{
		return false;
	}
	return true;
}