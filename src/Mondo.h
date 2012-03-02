#ifndef _MONDO_SFR
#define _MONDO_SFR

#include "Sprite.h"
#include <vector>
#include "SysEvent.h"

class Mondo{
private:
	Sprite* int_MoveSprite(Sprite*);
protected:
	std::vector<Sprite> object;

	/*Muove uno sprite del Mondo
	PARAMETRI: indice del vettore, pixel del passo di movimento, direzione del movimento*/
	//bool MoveSprite(const unsigned int&, const Sint16&, const Direction&);
public:
	Mondo(void){

	}
	~Mondo(void){
		this->object.clear();
	}
	virtual void Load(void)=0;
	virtual void UnLoad(void)=0;
	
	friend OutVideo& operator<<(OutVideo&, Mondo&);

	//questa funzione verrà chiamata un attimo prima del disegno a video del Mondo direttamente dalla schermtata Game
	virtual void Process(const type_event::mess_event&, OutVideo&)=0;
};

OutVideo& operator<<(OutVideo&, Mondo&);

#endif