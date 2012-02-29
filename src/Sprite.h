#ifndef _SPRITE_SFR
#define _SPRITE_SFR

#include "Bgui.h"
#include "MyTimer.h"

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
public:
	Sprite(void):frame(0),anim(false),face(DIR_RIGHT){
		this->Set_Delay_Frames(100);
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
};

#endif

/*
			NOTE SPRITE_GRAFICO
		4x4 dimensioni 40x62
*/