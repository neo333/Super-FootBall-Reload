#ifndef _SPRITE_SFR
#define _SPRITE_SFR

#include "Bgui.h"
#include "MyTimer.h"
#include "MyVector.h"
#include <set>

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

	MyRect box_collide;
	void Load_BoxCollide(const std::string&);

	std::set<Sprite*> list_collide;
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

	/*Svuota la lista delle collisioni*/
	void Clear_ListCollide(void){
		this->list_collide.clear();
	}

	/*Aggiunge uno sprite alla lista delle collisioni*/
	void Add_ListCollide(Sprite* oth){
		if(this!=oth){
			this->list_collide.insert(oth);
		}
	}

	/*Sposta lo sprite in una direzione del valore indicato*/
	void Traslate_Instant(const Direction& p_dir, const Sint16& p_mov){
		switch(p_dir){
		case DIR_UP:
			this->SetY(this->GetY() - p_mov);
			break;
		case DIR_DOWN:
			this->SetY(this->GetY() + p_mov);
			break;
		case DIR_RIGHT:
			this->SetX(this->GetX() + p_mov);
			break;
		case DIR_LEFT:
			this->SetX(this->GetX() - p_mov);
			break;
		default:
			//TODO: errore! direzione non valide
			return;
		}
	}
};

#endif