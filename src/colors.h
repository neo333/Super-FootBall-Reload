#ifndef COLORS_SFR
#define COLORS_SFR

#include <SDL/SDL.h>

struct Colors{
	Uint8 c_red;
	Uint8 c_green;
	Uint8 c_blue;

	Colors(const Uint8& r_p=0, const Uint8& g_p=0, const Uint8& b_p=0):c_red(r_p),c_green(g_p),c_blue(b_p){

	}

	bool operator==(const Colors& oth) const{
		if(this->c_blue==oth.c_blue && this->c_green==oth.c_green && this->c_red==oth.c_red){
			return true;
		}
		return false;
	}

	bool operator!=(const Colors& oth) const{
		if(*this==oth){
			return false;
		}
		return true;
	}
};

namespace typ_colors{
	static Colors Default_Trasparent(255,0,255);
	static Colors Bottone_Select(255,0,0);
	static Colors Bottone_NoSelect(255,255,255);
};

#endif
