#ifndef _MONDO_SFR
#define _MONDO_SFR

#include "Sprite.h"
#include <vector>
#include "SysEvent.h"
#include "MotorePhi.h"

class Mondo{
protected:
	std::vector<Sprite> object;
private:
	MotorePhi motore_fisico;
public:
	Mondo(void):motore_fisico(&object){

	}
	~Mondo(void){
		this->object.clear();
	}

	/*Carica tutti gli oggetti del livello. Inserendoli nel vettore object*/
	virtual void Load(void)=0;

	/*Si occupa di deallocale, e terminare tutti gli oggetti del livello*/
	virtual void UnLoad(void)=0;
	
	/*Processa il livello. Viene chiamata prima del disegno a video globale*/
	virtual void Process(const type_event::mess_event&, OutVideo&)=0;

	/*Visualizza a video tutti gli oggetti del mondo*/
	friend OutVideo& operator<<(OutVideo&, Mondo&);

	/*Processa il motore fisico. Viene chiamata prima della funzione di processo del livello corrente*/
	void Process_MotorPhi(void){
		this->motore_fisico.Process();
	}
};

OutVideo& operator<<(OutVideo&, Mondo&);

#endif