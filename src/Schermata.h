#ifndef _SCHERMATA_SFR
#define _SCHERMATA_SFR

#include "SysEvent.h"
#include "OutVideo.h"

namespace schermate_game{
	enum typ_schermate{
		INTRO,
		MENU_PRINCIPALE,
		GAME
	};
}

class Schermata{
public:
	virtual void Load(void)=0;
	virtual void UnLoad(void)=0;
	virtual int Run(const type_event::mess_event&, OutVideo&)=0;
	virtual ~Schermata(void){

	}
};

#endif