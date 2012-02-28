#include "Applicazione.h"
#include "global.h"
#include "Intro.h"
#include "MenuPrincipale.h"

Applicazione* sys_data::app_main=NULL;
Punto sys_data::Mouse_Coordinate;
OutSound* sys_data::sound_main=NULL;

Applicazione::Applicazione(void): SDL_main(SDL_MAIN), loaded(false), SDL_image(SDL_IMG), SDL_ttf(SDL_TTF),SDL_mix(SDL_MIX),force_exit(-1), pnt_schermata(NULL){
	sys_data::app_main=this;
}

bool Applicazione::Init_Libraries(void){
	if(this->SDL_main.Apri_Libreria()==false){
		return false;
	}
	if(this->SDL_image.Apri_Libreria()==false){
		return false;
	}
	if(this->SDL_ttf.Apri_Libreria()==false){
		return false;
	}
	if(this->SDL_mix.Apri_Libreria()==false){
		return false;
	}
	OutRegistro(Errore_Form("0xYINIT_LIB","Librerie di sistema inizializzate correttamente!"));
	return true;
}

void Applicazione::Close_Libreries(void){
	this->SDL_mix.Chiudi_Libreria();
	this->SDL_ttf.Chiudi_Libreria();
	this->SDL_image.Chiudi_Libreria();
	this->SDL_main.Chiudi_Libreria();
	OutRegistro(Errore_Form("0xYCLOSE_LIB","Librerie di sistema terminate correttamente!"));
}

Applicazione::~Applicazione(void){
	this->Close_All();
	sys_data::app_main=NULL;
}

void Applicazione::Close_All(void){
	if(this->loaded){
		this->Close_Sys_Sound();
		this->Close_Fonts();
		this->main_screen.Close_MainWin();
		this->Close_Libreries();
		this->loaded=false;

		if(this->force_exit==0){
			OutRegistro(Errore_Form("0xYCLOSE_APP","Applicazione conclusa con successo!"));
		}else{
			OutRegistro(Errore_Form("0xECLOSE_APP","Applicazione terminata con errori!"));
		}
	}
}

void Applicazione::Init_All(void){
	if(!this->loaded){
		if(this->Init_Libraries()==false){
			OutRegistro(Errore_Form("1xNINIT_LIB","Impossibile inizializzare le librerie di sistema.\n"
												  "Contattare l'amministratore del software"));
			this->force_exit=1;
		}
		if(this->main_screen.Open_MainWin(this->opz_app)==false){
			this->SetError();
		}
		this->Set_Win_Title();
		this->Init_Fonts();
		this->Init_Sys_Sound();
		this->loaded=true;
	}
}

int Applicazione::Run(void){
	this->Init_All();

	//RUN___APP
	this->Set_Pointer_Schermata(schermate_game::INTRO);
	type_event::mess_event mty_event;
	while(this->force_exit==-1){
		this->main_screen.DrawnBackBuffer();
		mty_event=this->mSysEvent.UpDateEvents();
		switch(mty_event){
		case type_event::QUIT_APP:
			this->force_exit=0;
			break;
		}
		if(this->pnt_schermata){
			this->pnt_schermata->Run(mty_event,this->main_screen);
		}
		this->main_screen.Flip();
		sys_data::keys_main.FlushKeys();
	}
	//CLOSE_APP
	this->Close_All();
	return this->force_exit;
}

void Applicazione::Set_Win_Title(void){
	SDL_WM_SetCaption("Super FootBall Reload",NULL);
}

void Applicazione::SetError(void){
	this->force_exit=1;
}

void Applicazione::Set_Pointer_Schermata(const schermate_game::typ_schermate& title_scene){
	if(this->pnt_schermata){
		this->pnt_schermata->UnLoad();
		delete this->pnt_schermata;
		this->pnt_schermata=NULL;
	}

	switch(title_scene){
	case schermate_game::INTRO:
		this->pnt_schermata=new Intro;
		break;
	case schermate_game::MENU_PRINCIPALE:
		this->pnt_schermata=new MenuPrincipale;
		break;
	default:
		OutRegistro(Errore_Form("1xESCENE_APP","Impossibile caricare la risorsa richiesta dal modulo!\n"
											   "Contattare l'amministratore del software!"));
		this->SetError();
		break;
	}

	if(this->pnt_schermata){
		this->pnt_schermata->Load();
	}
}

void Applicazione::Init_Fonts(void){
	fonts_data::font_puls.LoadFont("Data/fonts/arial.ttf",20);
}

void Applicazione::Close_Fonts(void){
	fonts_data::font_puls.FreeFont();
}

void Applicazione::Close_Game(void){
	this->force_exit=0;
}

void Applicazione::Init_Sys_Sound(void){
	if(this->main_sys_sound.IsLoaded()==false){
		if(this->main_sys_sound.LoadSystem()==false){
			//TODO: errore
		}
	}
	sys_data::sound_main=&this->main_sys_sound;
}

void Applicazione::Close_Sys_Sound(void){
	if(this->main_sys_sound.IsLoaded()==true){
		this->main_sys_sound.CloseSystem();
	}
	sys_data::sound_main=NULL;
}