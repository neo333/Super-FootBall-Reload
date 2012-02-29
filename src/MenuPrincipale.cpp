#include "MenuPrincipale.h"
#include "Scripts.h"

/**FILENAME*******/
namespace mp_filename{
	static const std::string sfondo_menu("Data/images/m_p.bin");
}
/*****************/

void MenuPrincipale::Load(void){
	this->sfondo.Load(mp_filename::sfondo_menu);
	this->bEsci.Load(1);
	this->bEsci.SetX(300);
	this->bEsci.SetY(360);
	this->bEsci.SetText("ESCI");
	this->bEsci.SetAction_Clic(scripts::Quit_Game);
	this->bGioca.Load(1);
	this->bGioca.SetX(300);
	this->bGioca.SetY(240);
	this->bGioca.SetText("GIOCA");
	this->bGioca.SetAction_Clic(scripts::Set_Schermata_Game);
	this->bExtra.Load(1);
	this->bExtra.SetX(300);
	this->bExtra.SetY(300);
	this->bExtra.SetText("EXTRA");
}

void MenuPrincipale::UnLoad(void){
	this->sfondo.FreeSurface();
	this->bEsci.ClearAll();
	this->bGioca.ClearAll();
	this->bExtra.ClearAll();
}

int MenuPrincipale::Run(const type_event::mess_event& mEvent, OutVideo& screen){
	this->bGioca << mEvent;
	this->bExtra << mEvent;
	this->bEsci << mEvent;

	screen << this->sfondo;
	screen << this->bExtra;
	screen << this->bGioca;
	screen << this->bEsci;
	return 0;
}