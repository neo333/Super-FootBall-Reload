#include "OutVideo.h"
#include <SDL\SDL.h>
#include "global.h"
#include <cassert>

OutVideo* sys_data::win_main;
const Uint32 FRAMES_PER_SECOND = 60;

OutVideo::OutVideo(void):screen(NULL),time_last_call_flip(0){
}

bool OutVideo::Open_MainWin(const OpzioniGame& opz_param){
	OutRegistro(Errore_Form("0xLMAIN_WIN","Inizializzazione Finestra Grafica in corso ..."));
	Uint32 flags= SDL_HWSURFACE| SDL_ANYFORMAT | SDL_DOUBLEBUF;
	if(opz_param.Get_FullScreen()){
		flags=flags | SDL_FULLSCREEN;
	}

	if(!this->screen){
		this->screen=SDL_SetVideoMode(opz_param.Get_Wwin(), opz_param.Get_Hwin(), opz_param.Get_Bppwin(), flags);
		if(this->screen.IsLoaded()==false){
			OutRegistro(Errore_Form("1xEMAIN_WIN","Impossibile inizializzare il metodo grafico richiesto!\n"
												  "Controllare i settaggi della scheda video e delle opzioni."));
			return false;
		}
	}else{
		this->Close_MainWin();
		return this->Open_MainWin(opz_param);
	}
	this->backbuffer.Load(files_image_pat::backbufferscreen);
	OutRegistro(Errore_Form("0xYMAIN_WIN","Inizializzazione Finestra Grafica effettuata con successo!"));
	sys_data::win_main=this;
	return true;
}

void OutVideo::Close_MainWin(void){
	if(this->screen.IsLoaded()){
		this->backbuffer.FreeSurface();
		this->screen.FreeSurface();
		OutRegistro(Errore_Form("0xCLMAIN_WIN","Finestra Grafica Terminata."));
	}
}

void OutVideo::Flip(void){
	if(SDL_GetTicks() - this->time_last_call_flip >= 1000/FRAMES_PER_SECOND){
		if(SDL_Flip(this->screen)!=0){
			OutRegistro(Errore_Form("1xEFLIP_WIN","Impossibile eseguire il Flip del buffer video.\n"
												  "Contattare l'amministratore del software!"));
			sys_data::app_main->SetError();
			return;
		}
		this->time_last_call_flip=SDL_GetTicks();
	}else{
		SDL_Delay(( 1000 / FRAMES_PER_SECOND) - (SDL_GetTicks() - this->time_last_call_flip));
	}
}

void OutVideo::DrawnBackBuffer(void){
	*this << this->backbuffer;
}

OutVideo& OutVideo::operator<<(MySurface& oth){
	if(&oth==&this->screen || oth.IsLoaded()==false || this->screen.IsLoaded()==false){
		OutRegistro(Errore_Form("1xESCREEN_OUT","Parametri interni dell'applicazione non corretti!\n"
												 "Contattare l'amministratore del software."));
		sys_data::app_main->SetError();
		return *this;
	}
	OutVideo::BlitSurface(oth,NULL,this->screen,NULL);
	return *this;
}

void OutVideo::BlitSurface(SDL_Surface *src, SDL_Rect *srcrect, SDL_Surface *dst, SDL_Rect *dstrect){
	if(SDL_BlitSurface(src, srcrect, dst, dstrect)!=0){
		OutRegistro(Errore_Form("1xNBLIT_WIN","Impossibile eseguire il blit dell'immagine richiesta!\n"
										"Contattare l'amministratore del software."));
		#ifdef _DEBUG
			sys_data::Registro << SDL_GetError() << "\n";
		#endif
		sys_data::app_main->SetError();
	}
}