#include "MyFont.h"
#include "global.h"

/**********FONTS GLOBALI*******************/
MyFont fonts_data::font_puls;
/******************************************/

MyFont::MyFont(void):pFont(NULL){

}

MyFont::~MyFont(void){
	this->FreeFont();
}

void MyFont::FreeFont(void){
	if(this->pFont){
		TTF_CloseFont(this->pFont);
		this->pFont=NULL;
	}
}

void MyFont::LoadFont(const std::string& filename, int pt_size){
	this->FreeFont();
	this->pFont=TTF_OpenFont(filename.c_str(),pt_size);
	if(this->pFont==NULL){
		OutRegistro(Errore_Form("1xELOAD_FNT","Impossibile caricare la risorsa richiesta: '"+filename+"'\n"
											  "Una nuova installazione potrebbe risolvere il problema!"));
#ifdef _DEBUG
		sys_data::Registro << TTF_GetError() << "\n";;
#endif
		sys_data::app_main->SetError();
	}
}