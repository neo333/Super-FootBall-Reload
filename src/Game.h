#ifndef _GAME_SFR
#define _GAME_SFR

#include "Schermata.h"
#include "Mondo.h"

enum WORLD_LEVEL{
	W_LEVEL_0
};

class Game: public Schermata{
private:
	Mondo* pLevel;
public:
	Game(void):pLevel(NULL){

	}
	~Game(void){
		this->UnLoad();
	}

	void Load(void);
	void UnLoad(void);
	int Run(const type_event::mess_event&, OutVideo&);

	void SetLevel(const WORLD_LEVEL&);
};

#endif