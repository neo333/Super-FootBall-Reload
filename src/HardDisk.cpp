#include "HardDisk.h"
#include "global.h"
#include <SDL\SDL_image.h>
#include "cryp_lib.h"

#define __MAX_CACHES_SURFACE__ 50

HardDisk sys_data::hd_sysdata;

bool HardDisk::LoadSurface_to_file(const std::string& filename, MySurface& surf_load){
	this->CheckCaches();
	OutRegistro(Errore_Form("2xINFLOAD_IMG","Accesso all'Hard Disk del system!\nRichiesta della risorsa: '"+filename+"'"));
	std::map<std::string, MySurface>::iterator pos;
	pos=this->caches_surfaces.find(filename);
	if(pos==this->caches_surfaces.end()){
		SDL_Surface* buf_temp=NULL, *buf_opt=NULL;
		//------LOAD_to_memory--------
		long size_mem=0;
		char* Memory=DeCryp(filename,size_mem);
		if(Memory==NULL){
			OutRegistro(Errore_Form("1xRES_NTF","Impossibile caricare la risorsa richiesta: '"+filename+"'\n"
												"Una nuova installazione potrebbe risolvere il problema!"));
			sys_data::app_main->SetError();
			return false;
		}
		SDL_RWops* pMem=SDL_RWFromMem(Memory, size_mem);
		if(pMem==NULL){
			OutRegistro(Errore_Form("1xMEMORY_RWmem","Area di memoria corrotta. Impossibile effettuare un'operazione di lettura."));
			sys_data::app_main->SetError();
			return false;
		}
		buf_temp=IMG_Load_RW(pMem, 0);
		SDL_FreeRW(pMem);
		delete[] Memory;
		Memory=NULL;
		//-----------------------------
		if(buf_temp==NULL){
			OutRegistro(Errore_Form("1xNTLOAD_IMG","Impossibile caricare la risorsa richiesta: '"+filename+"'\n"
													"Una nuova installazione potrebbe risolvere il problema!"));
#ifdef _DEBUG
			sys_data::Registro << IMG_GetError() << "\n";
#endif
			return false;
		}
		buf_opt=SDL_DisplayFormat(buf_temp);
		if(buf_opt==NULL){
			OutRegistro(Errore_Form("1xOPTLOAD_IMG","Impossibile ottimizzare la risorsa richiesta.\n"
													"Controllare le impostazioni grafiche!"));
#ifdef _DEBUG
			sys_data::Registro << SDL_GetError() << "\n";;
#endif
			return false;
		}
		SDL_FreeSurface(buf_temp);
		buf_temp=NULL;
		this->caches_surfaces.insert(std::pair<std::string, MySurface>(filename,buf_opt));
		OutRegistro(Errore_Form("2xINFCACHES_IMG","Aggiunta di una cache al system_data!"));
		surf_load=buf_opt;
	}else{
		surf_load=(*pos).second;	
	}
	return true;
}

void HardDisk::CheckCaches(void){
	if(this->caches_surfaces.size() > __MAX_CACHES_SURFACE__){
		this->caches_surfaces.clear();
	}
}

void HardDisk::DEBUG_OutAllCaches_Surface(void) const{
	std::map<std::string, MySurface>::const_iterator it;
	for(it = this->caches_surfaces.begin(); it != this->caches_surfaces.end(); it++){
		OutRegistro(Errore_Form("2xINFCACHE_LIST_IMG"," > Cache IMG filename: '"+(*it).first+"'\n"
			"             memory_pointer: '"+(std::string)((*it).second)+"'"));
	}
}

Mix_Chunk* HardDisk::LoadSound_to_file(const std::string& filename){
	if(filename.size() > 0){
		OutRegistro(Errore_Form("2xINFLOAD_SND","Accesso all'Hard Disk del system!\nRichiesta della risorsa: '"+filename+"'"));
		long size_mem=0;
		char* Memory=DeCryp(filename,size_mem);
		if(Memory==NULL){
			OutRegistro(Errore_Form("1xRES_NTF","Impossibile caricare la risorsa richiesta: '"+filename+"'\n"
												"Una nuova installazione potrebbe risolvere il problema!"));
			sys_data::app_main->SetError();
			return NULL;
		}
		SDL_RWops* pMem=SDL_RWFromMem(Memory, size_mem);
		if(pMem==NULL){
			OutRegistro(Errore_Form("1xMEMORY_RWmem","Area di memoria corrotta. Impossibile effettuare un'operazione di lettura."));
			sys_data::app_main->SetError();
			return NULL;
		}
		Mix_Chunk* rts=NULL;
		rts=Mix_LoadWAV_RW(pMem, 0);
		SDL_FreeRW(pMem);
		delete[] Memory;
		Memory=NULL;
		return rts;
	}
	return NULL;
}