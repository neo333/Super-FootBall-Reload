#include "Mondo.h"

OutVideo& operator<<(OutVideo& screen, Mondo& obj){
	unsigned int size=obj.object.size();
	for(register unsigned int i=0; i<size; i++){
		screen << obj.object[i];
	}
	return screen;
}

void Mondo::DeleteSprite(const Sprite* pSprite){
	register std::vector<Sprite>::iterator it;
	for(it=this->object.begin(); it!=this->object.end(); ){
		if(&(*it)==pSprite){
			it=this->object.erase(it);
		}else{
			it++;
		}
	}
}