#include "Opzioni.h"
#include "global.h"
#include <cstdio>

void OpzioniGame::SetDefault(void){
	this->full_screen=false;
	this->w_win=800;
	this->h_win=600;
	this->bpp_win=32;
}

OpzioniGame::OpzioniGame(void){
	this->SetDefault();
	if(this->Load_to_file(sys_data::filename_opzioni)==false){
		this->Save_to_file(sys_data::filename_opzioni);
	}
}

bool OpzioniGame::Load_to_file(const std::string& filename){
	OutRegistro(Errore_Form("0xLOPZ_FILE","Caricamento opzioni di gioco in corso ..."));
	if(filename.size() == 0){
		return false;
	}
	FILE* pfile=NULL;
	pfile=fopen(filename.c_str(),"rb");
	if(pfile==NULL){
		return false;
	}
	fread(this,sizeof(OpzioniGame),1,pfile);
	fclose(pfile);
	pfile=NULL;
	OutRegistro(Errore_Form("0xLYOPZ_FILE","Opzioni di gioco caricate con successo!"));
	return true;
}

void OpzioniGame::Save_to_file(const std::string& filename) const{
	OutRegistro(Errore_Form("0xSOPZ_FILE","Salvataggio opzioni di gioco in corso ..."));
	FILE* pfile=NULL;
	pfile=fopen(filename.c_str(),"wb");
	if(pfile!=NULL){
		fwrite(this,sizeof(OpzioniGame),1,pfile);
		fclose(pfile);
		pfile=NULL;
	}else{
		OutRegistro(Errore_Form("1xSAVOPZ_FILE","Impossibile effettuare il salvataggio delle ozioni!\n"
												"  Controllare che il disco non sia pieno o protetto da scrittura"));
	}
	OutRegistro(Errore_Form("0xSYOPZ_FILE","Salvataggio opzioni di gioco effettuato con successo!"));
}
