#ifndef _MYSURFACE_SFR
#define _MYSURFACE_SFR

#include <SDL/SDL.h>
#include <string>
#include "colors.h"

/*			mySurface
	Astrazione oggetto della SDL_Surface implementata nella libreria SDL.
*/

class MySurface{
private:
	SDL_Surface* psurface;
public:
	/*Costruttore di Default. Surface vuota!*/
	MySurface(void):psurface(NULL){

	}

	/*Costruttore di Copia. Costruisce creando una copia della surface originale*/
	MySurface(const MySurface& oth):psurface(NULL){
		if(oth.psurface){
			this->psurface=SDL_DisplayFormat(oth.psurface);
		}
	}

	/*Costruttore con Surface. Costruiscre creando una copia della surface originale*/
	MySurface(SDL_Surface* oth):psurface(NULL){
		if(oth){
			this->psurface=SDL_DisplayFormat(oth);
		}
	}

	/*Operatore di Assegnazione di Default. Assegna copiando la surface originale*/
	MySurface& operator=(const MySurface&);

	/*Operatore di Assegnazione con Surface. Assegna la surface specificata (NB. Non crea una copia di tale)*/
	MySurface& operator=(SDL_Surface* oth){
		this->FreeSurface();
		if(oth){
			this->psurface=oth;
		}
		return *this;
	}

	/*Disturttore*/
	~MySurface(void){
		this->FreeSurface();
	}

	/*Dealloca la surface*/
	void FreeSurface(void){
		if(this->psurface){
			SDL_FreeSurface(this->psurface);
			this->psurface=NULL;
		}
	}

	/*Ritorna FALSE se la surface � vuota*/
	bool IsLoaded(void) const{
		if(this->psurface){
			return true;
		}
		return false;
	}

	/*Operatore di Casting in puntatore SDL_Suface*/
	operator SDL_Surface*(void){
		return this->psurface;
	}

	operator const SDL_Surface*(void) const{
		return this->psurface;
	}

	/*Operatore di Casting in string c++*/
	operator std::string(void) const{
		char buffer[20];
		//itoa((int)(this->psurface),buffer,10);	//TODO: rifare la funzione per linux!
		std::string rts=buffer;
		return rts;
	}

	/*Carica la surface da un file_name specificato*/
	void Load(const std::string&);

	/*Ritorna il Pixel Format della surface*/
	SDL_PixelFormat* PixelFormat(void){
		return this->psurface->format;
	}

	/*Ritorna il colore di un determinato Pixel della surface. In caso di errore ritorna FALSE!*/
	bool GetColorPixel(Colors&, const Sint16&, const Sint16&);

	/*Ritorna la larghezza dell'immagine. Se la surface non � caricata ritorna 0*/
	int Get_WSurface(void) const{
		if(this->psurface){
			return this->psurface->w;
		}
		return 0;
	}

	/*Ritorna l'altezza dell'immagine. Se la surface non � caricata ritorna 0*/
	int Get_HSurface(void) const{
		if(this->psurface){
			return this->psurface->h;
		}
		return 0;
	}
};

#endif
