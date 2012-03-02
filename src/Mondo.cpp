#include "Mondo.h"

OutVideo& operator<<(OutVideo& screen, Mondo& obj){
	unsigned int size=obj.object.size();
	for(register unsigned int i=0; i<size; i++){
		screen << obj.object[i];
	}
	return screen;
}

Sprite* Mondo::int_MoveSprite(Sprite* pSprite){
	//DA FARE!!!!
	//motore fisico su vettore velocità!
	register std::vector<Sprite>::iterator it;

	for(int i=0; i<p; i++){
		pSprite->Step_One(dir,1);
		for(it=this->object.begin(); it!=this->object.end(); it++){
			if(&(*it)!=pSprite){
				if(pSprite->CheckCollision((*it))){
					pSprite->Step_One(dir,-1);
					return &(*it);
				}
			}
		}
	}

	return NULL;
}