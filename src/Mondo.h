#ifndef _MONDO_SFR
#define _MONDO_SFR

#include "Sprite.h"
#include <vector>
#include "SysEvent.h"
#include "MotorePhi.h"
#include "Player.h"

class Game;

enum TYPE_SPRITE{
	SP_DEFAULT,
	SP_BALL,
	SP_ENEMY
};

class Mondo{
private:
	friend class Game;

	std::vector<Sprite*> objects;
	MotorePhi motore_fisico;
	void Process_MotorPhi(void){
		this->motore_fisico.Process();
	}
	Player mplayer;

	friend OutVideo& operator<<(OutVideo&, Mondo&);
protected:

	/*Cancella uno sprite dal mondo passandone il puntatore*/
	void DeleteSprite(const Sprite*);

	/*Inserisce uno sprite nel mondo*/
	Sprite* Insert_Sprite(const TYPE_SPRITE& =SP_DEFAULT);

	/*Cancella TUTTI gli sprite del mondo*/
	void Clear_AllSprites(void);

	/*Setta lo sprite del player*/
	void Set_Sprite_Player(Sprite* pSprite_param){
		this->mplayer.Set_Operator_Sprite(pSprite_param);
	}

	/*Ritorna lo sprite del player*/
	Sprite* Get_Sprite_Player(void){
		return this->mplayer.Get_Sprite();
	}
public:
	Mondo(void):motore_fisico(&objects){

	}
	virtual ~Mondo(void){
		this->Clear_AllSprites();
		this->Set_Sprite_Player(NULL);
	}

	/*Carica tutti gli oggetti del livello. Inserendoli nel vettore object*/
	virtual void Load(void)=0;

	/*Si occupa di deallocale, e terminare tutti gli oggetti del livello*/
	virtual void UnLoad(void){
		this->Clear_AllSprites();
		this->Set_Sprite_Player(NULL);
	}
	
	/*Processa il livello. Viene chiamata prima del disegno a video globale*/
	virtual void Process(const type_event::mess_event&, OutVideo&)=0;
};

/*Visualizza a video tutti gli oggetti del mondo*/
OutVideo& operator<<(OutVideo&, Mondo&);

#endif