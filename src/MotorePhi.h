#ifndef _MOTORE_PHI_SFR
#define _MOTORE_PHI_SFR

#include "Sprite.h"

class MotorePhi{
private:
	std::vector<Sprite> *pObjs;

	/*Verifica se nell'esatto momento della chiamata di questa funzione lo sprite passato nel parametro è sovrapposto
	ad un altro. Ritorna NULL in caso negativo*/
	Sprite* sing_CheckCollisione_static(Sprite*);

	/*Funzione segno. Ritorna 1 se il numero è positivo, -1 se il numero è negativo altrimenti ritorna 0*/
	template<class T> static int Sign(const T& num){
		if(num>0){
			return 1;
		}
		if(num<0){
			return -1;
		}
		return 0;
	}

	
	void MoveAll(void);
public:
	MotorePhi(std::vector<Sprite>* ppobjs):pObjs(ppobjs){
		
	}
	void Process(void);

	/*Forza il controllo sulle liste di collisioni di tutti gli oggetti.
	Refresha in maniera rigorosa ogni lista di collisione di ogni oggetto del mondo*/
	void Force_CheckCollision(void);
};

#endif