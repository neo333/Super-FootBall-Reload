#include "MotorePhi.h"
#include <math.h>

void MotorePhi::Process(void){
	this->MoveAll();
}

void MotorePhi::Force_CheckCollision(void){
	std::vector<Sprite>::iterator it;
	Direction mov_loc;
	Sprite* p_temp;

	for(it=this->pObjs->begin(); it!=this->pObjs->end(); it++){
		(*it).Clear_ListCollide();
		for(unsigned int i=0; i<4; i++){
			switch(i){
			case 0:
				mov_loc=DIR_UP;
				break;
			case 1:
				mov_loc=DIR_DOWN;
				break;
			case 2:
				mov_loc=DIR_LEFT;
				break;
			case 3:
				mov_loc=DIR_RIGHT;
				break;
			}
			(*it).Traslate_Instant(mov_loc,1);
			p_temp=this->sing_CheckCollisione_static(&(*it));
			if(p_temp){
				(*it).Add_ListCollide(p_temp);
			}
			(*it).Traslate_Instant(mov_loc,-1);
		}
	}
}

Sprite* MotorePhi::sing_CheckCollisione_static(Sprite* pSprite){
	//TODO: da fare funzione!
	return NULL;
}

void MotorePhi::MoveAll(void){
	std::vector<Sprite>::iterator it;
	Sint16 x_step, y_step, delay;
	Sprite* ptemp;
	bool collide;

	for(it=this->pObjs->begin(); it!=this->pObjs->end(); it++){
		(*it).Clear_ListCollide();
		x_step=(*it).Get_Speed().Get_X();
		y_step=(*it).Get_Speed().Get_Y();

		for(unsigned int passo=0; passo<2; passo++){
			if(passo){
				delay=y_step;
			}else{
				delay=x_step;
			}
			delay=(int)(fabs((float)(delay)));
			collide=false;

			for(Sint16 i=0; i<delay && !collide; i++){
				if(passo){
					(*it).Traslate_Instant(DIR_DOWN,y_step);
				}else{
					(*it).Traslate_Instant(DIR_RIGHT,x_step);
				}
				ptemp=this->sing_CheckCollisione_static(&(*it));
				if(ptemp){
					collide=true;
					(*it).Add_ListCollide(ptemp);
					if(passo){
						(*it).Traslate_Instant(DIR_DOWN,-y_step);
					}else{
						(*it).Traslate_Instant(DIR_RIGHT,-x_step);
					}
				}
			}
		}
	}
}