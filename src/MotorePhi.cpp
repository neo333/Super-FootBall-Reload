#include "MotorePhi.h"
#include <math.h>

void MotorePhi::Process(void){
	this->MoveAll();
}


Sprite* MotorePhi::sing_CheckCollisione_static(Sprite* pSprite){
	register std::vector<Sprite*>::iterator it;
	for(it=this->pObjs->begin(); it!=this->pObjs->end(); it++){
		if((*it)!=pSprite){
			if(pSprite->Collide_with_Sprite(*(*it))){
				return (*it);
			}
		}
	}

	return NULL;
}

void MotorePhi::MoveAll(void){
	std::vector<Sprite*>::iterator it;
	Sint16 x_step, y_step, delay;
	Sprite* ptemp;
	bool collide;
	Direction mov_inst;
	MyRect con_area;

	for(it=this->pObjs->begin(); it!=this->pObjs->end(); it++){
		(*it)->Clear_ListCollide();
		x_step=(*it)->Get_Speed().Get_X();
		y_step=(*it)->Get_Speed().Get_Y();

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
					(*it)->Traslate_Instant(DIR_DOWN,1*this->Sign(y_step));
					if(y_step>=0){
						mov_inst=DIR_DOWN;
					}else{
						mov_inst=DIR_UP;
					}
				}else{
					(*it)->Traslate_Instant(DIR_RIGHT,1*this->Sign(x_step));
					if(x_step>=0){
						mov_inst=DIR_RIGHT;
					}else{
						mov_inst=DIR_LEFT;
					}
				}
				ptemp=this->sing_CheckCollisione_static((*it));
				if(ptemp){
					collide=true;
					(*it)->Add_ListCollide(Collision(ptemp,mov_inst));
					ptemp->Add_ListCollide(Collision((*it),this->Reverse_Direction(mov_inst)));
					if(passo){
						(*it)->Traslate_Instant(DIR_DOWN,-1*this->Sign(y_step));
					}else{
						(*it)->Traslate_Instant(DIR_RIGHT,-1*this->Sign(x_step));
					}
				}else{
					//------------controlla constraint area---------------
					if((*it)->Get_Constraint_Area(con_area)){
						if((*it)->GetX() < con_area.x || (*it)->GetX() > con_area.x+con_area.w){
							if(passo){
								(*it)->Traslate_Instant(DIR_DOWN,-1*this->Sign(y_step));
							}else{
								(*it)->Traslate_Instant(DIR_RIGHT,-1*this->Sign(x_step));
							}
						}
						if((*it)->GetY() < con_area.y || (*it)->GetY() > con_area.y+con_area.h){
							if(passo){
								(*it)->Traslate_Instant(DIR_DOWN,-1*this->Sign(y_step));
							}else{
								(*it)->Traslate_Instant(DIR_RIGHT,-1*this->Sign(x_step));
							}
						}
					}
					//------------------------------------------------------
				}
			}
		}
	}
}