#ifndef _SPRITE_SFR
#define _SPRITE_SFR

#include "Bgui.h"
#include "MyTimer.h"
#include "MyVector.h"

enum Direction{
	DIR_UP,
	DIR_DOWN,
	DIR_LEFT,
	DIR_RIGHT
};

class Sprite: public Bgui{
private:
	void Process(void);
	Direction face;

	unsigned short frame;
	MyTimer delay_frames;
	bool anim;

	MyVector speed;
public:
	Sprite(void):frame(0),anim(false),face(DIR_DOWN){
		this->Set_Delay_Frames(130);
	}

	/*Carica un'immagine di tipo Sprite!*/
	void Load(const std::string&);

	/*Setta il tempo (in millisecs) di attesa tra un frame e l'altro di animazione*/
	void Set_Delay_Frames(const Uint32& pDelay){
		this->delay_frames.Set(pDelay);
	}

	/*Setta se lo sprite è in modalita' di animazione o no*/
	void Set_Anim(const bool sw){
		switch(sw){
		case true:
			this->delay_frames.Start();
			break;
		case false:
			this->delay_frames.Stop();
			break;
		}
		this->anim=sw;
	}

	/*Setta la direzione dello Sprite*/
	void Set_Face(const Direction& pDir){
		this->face=pDir;
	}

	/*Setta la velocità di spostamento dello sprite*/
	void Set_Speed(const MyVector& pSpeed){
		this->speed=pSpeed;
	}

	/*Ritorna la velocità di spostamento di uno sprite*/
	const MyVector& Get_Speed(void) const{
		return this->speed;
	}

	/*Sposta di 'unit'(parametro Sint16) pixel lo sprite nella direzione indicata*/
	void Step_One(const Direction& p_dir, const Sint16& unit){
		switch(p_dir){
		case DIR_UP:
			this->SetY(this->GetY()-unit);
			break;
		case DIR_DOWN:
			this->SetY(this->GetY()+unit);
			break;
		case DIR_LEFT:
			this->SetX(this->GetX()-unit);
			break;
		case DIR_RIGHT:
			this->SetX(this->GetX()+unit);
			break;
		default:
			//TODO: errore! Nessuna direzione definita!
			return;
		}
	}
};

#endif