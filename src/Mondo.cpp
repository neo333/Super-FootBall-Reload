#include "Mondo.h"
#include "Sp_Ball.h"
#include "Sp_Enemy.h"

OutVideo& operator<<(OutVideo& screen, Mondo& obj){
	unsigned int size=obj.objects.size();
	for(register unsigned int i=0; i<size; i++){
		screen << *obj.objects[i];
	}
	return screen;
}

void Mondo::DeleteSprite(const Sprite* pSprite){
	register std::vector<Sprite*>::iterator it;
	for(it=this->objects.begin(); it!=this->objects.end(); ){
		if((*it)==pSprite){
			delete (*it);
			(*it)=NULL;
			it=this->objects.erase(it);
		}else{
			it++;
		}
	}
}

Sprite* Mondo::Insert_Sprite(const TYPE_SPRITE& typ){
	Sprite* pTemp;
	switch(typ){
	case SP_DEFAULT:
		pTemp=new Sprite;
		break;
	case SP_BALL:
		pTemp=new Sp_Ball;
		break;
	case SP_ENEMY:
		pTemp=new Sp_Enemy((Level0*)(this));
		break;
	default:
		//TODO: fare errore!!! critico!!
		return NULL;
	}
	this->objects.push_back(pTemp);
	return pTemp;
}

void Mondo::Clear_AllSprites(void){
	register std::vector<Sprite*>::iterator it;
	for(it=this->objects.begin(); it!=this->objects.end(); ){
		delete (*it);
		(*it)=NULL;
		it=this->objects.erase(it);
	}
}