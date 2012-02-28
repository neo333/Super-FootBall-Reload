#ifndef _INTRO_SFR
#define _INTRO_SFR

#include "Schermata.h"
#include "Picture.h"

class Intro: public Schermata{
private:
	Picture logo_1;
	Picture logo_2;
public:
	int Run(const type_event::mess_event&, OutVideo&);
	void Load(void);
	void UnLoad(void){

	}
	~Intro(void){

	}
};

#endif