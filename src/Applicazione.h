#ifndef _APPLICAZIONE_SFR_
#define _APPLICAZIONE_SFR_

#include "Libreria.h"
#include "Opzioni.h"
#include "OutVideo.h"
#include "SysEvent.h"
#include "Schermata.h"
#include "MyFont.h"
#include "OutSound.h"
#include <vector>

struct Punto{
	Sint16 x;
	Sint16 y;

	Punto(const Sint16& x_param=0, const Sint16& y_param=0):x(x_param),y(y_param){

	}
};

class Applicazione{
private:
	/*--------------------*/
	Libreria SDL_main;
	Libreria SDL_image;
	Libreria SDL_ttf;
	Libreria SDL_mix;
	/*--------------------*/

	/*--------------------*/
	OpzioniGame opz_app;
	/*--------------------*/

	/*--------------------*/
	OutVideo main_screen;
	/*--------------------*/

	/*--------------------*/
	OutSound main_sys_sound;
	/*--------------------*/

	/*--------------------*/
	SysEvent mSysEvent;
	/*--------------------*/

	/*--------------------*/
	Schermata* pnt_schermata;
	std::vector<schermate_game::typ_schermate> sys_scherm;
	/*--------------------*/

	/*----DEBUG-----------*/
	bool vis_bcol_rect;
	/*--------------------*/

	bool loaded;
	int force_exit;

	bool Init_Libraries(void);
	void Close_Libreries(void);

	void Init_Fonts(void);
	void Close_Fonts(void);

	void Init_Sys_Sound(void);
	void Close_Sys_Sound(void);

	void Init_All(void);
	void Close_All(void);

	void Set_Win_Title(void);

	void Process_Schermate(void);
	void Set_Schermate_int(const schermate_game::typ_schermate&);
public:
	Applicazione(void);
	~Applicazione(void);

	int Run(void);
	void SetError(void);
	void Set_Pointer_Schermata(const schermate_game::typ_schermate&);
	void Close_Game(void);

	void Set_Debug_Vis_Bcol(const bool& fset){
		this->vis_bcol_rect=fset;
	}
	const bool& Get_Debug_Vis_Bcol(void) const{
		return this->vis_bcol_rect;
	}
};

#endif