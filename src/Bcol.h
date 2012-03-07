#ifndef _BCOL_SFR
#define _BCOL_SFR

#include <string>
#include "MyRect.h"
#include "MySurface.h"
#include <vector>
#include "Sprite.h"

class Bcol{
private:
	friend class Sprite;
	Bcol(void);

	/*Ritorna true se il punto si trova dentro il rettangolo*/
	static bool Point_into_Rect(const Sint16& x, const Sint16& y, const MyRect& rect){
		if(x>=rect.x && x<=rect.x+rect.w && y>=rect.y && y<=rect.y+rect.h){
			return true;
		}
		return false;
	}

	/*Crea il rettangolo e lo inserisce nel vettore.
	E' responsabile di non inserimenti di punti già presi.*/
	static void Make_Rect(const int&,const int&,std::vector<MyRect>&, MySurface&);
public:
	/*Codifica un'immagine e ne interpreta ricostruendo il file Bcol associato (file data per le collisioni del
	software specifico). Inserire il nome del file dell'immagine (1 parametro) e il 
	nome dove si desidera creare il file data (secondo parametro).
	Ritorna lo stato della riuscita dell'operazione*/
	static bool Converted_IMAGE(const std::string&, const std::string&);
};
#endif