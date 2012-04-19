#include "Testo.h"
#include <SDL/SDL_ttf.h>
#include "global.h"

void Testo::SetString(const std::string& str){
	this->str_main=str;
	this->Render();
}

void Testo::FreeTesto(void){
	this->ClearAll();
	this->font_main=NULL;
	this->str_main.clear();
}

void Testo::SetFont(MyFont* font_param){
	this->font_main=font_param;
	this->Render();
}

void Testo::Render(void){
	if((this->str_main.size() > 0) && this->font_main!=NULL){
		MySurface* pnt_temp;
		pnt_temp=&this->GetSurface_Component(0);
		pnt_temp->FreeSurface();
		SDL_Color color={this->color_main.c_red,this->color_main.c_green,this->color_main.c_blue};
		*pnt_temp=TTF_RenderText_Solid(*this->font_main, this->str_main.c_str(), color);
		if(pnt_temp->IsLoaded()==false){
			OutRegistro(Errore_Form("1xERND_FNT","Impossibile effettuare il redering della risorsa testuale!"));
#ifdef _DEBUG
			sys_data::Registro << TTF_GetError() << "\n";;
#endif
			sys_data::app_main->SetError();
		}
	}
}

void Testo::SetColor(const Colors& color_param){
	this->color_main=color_param;
	this->Render();
}

Size Testo::Size_String_Pixel(void) const{
	Size rts;
	if(this->font_main==NULL || this->str_main.size() == 0){
		return rts;
	}
	int w_temp,h_temp;
	if(TTF_SizeText(*this->font_main,this->str_main.c_str(),&w_temp,&h_temp)){
		//TODO: errore
	}
	rts.w=w_temp;
	rts.h=h_temp;
	return rts;
}
