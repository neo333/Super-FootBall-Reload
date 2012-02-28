#ifndef _MENU_PRINCIPALE_SFR
#define _MENU_PRINCIPALE_SFR

#include "Schermata.h"
#include "Picture.h"
#include "Bottone.h"

class MenuPrincipale: public Schermata{
private:
	Picture sfondo;
	Bottone bEsci;
	Bottone bGioca;
	Bottone bExtra;
public:
	void Load(void);
	void UnLoad(void);
	int Run(const type_event::mess_event&, OutVideo&);
};

#endif