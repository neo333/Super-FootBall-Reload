#include "Game.h"
#include "Level0.h"

void Game::Load(void){
	this->SetLevel(W_LEVEL_0);
}

void Game::UnLoad(void){
	if(this->pLevel){
		this->pLevel->UnLoad();
		delete this->pLevel;
		this->pLevel=NULL;
	}
}

int Game::Run(const type_event::mess_event& mEvent, OutVideo& screen){
	if(this->pLevel){
		this->pLevel->Process_MotorPhi();
		this->pLevel->Process(mEvent,screen);
		this->pLevel->mplayer.Run(mEvent);
		screen << *this->pLevel;
	}
	return 0;
}

void Game::SetLevel(const WORLD_LEVEL& lev_param){
	if(this->pLevel){
		this->pLevel->UnLoad();
		delete this->pLevel;
		this->pLevel=NULL;
	}
	switch(lev_param){
	case W_LEVEL_0:
		this->pLevel=new Level0;
		break;
	default:
		//TODO: fare errore! (tentativo di accesso a livello non definito!)
		break;
	}

	if(this->pLevel){
		this->pLevel->Load();
	}
}