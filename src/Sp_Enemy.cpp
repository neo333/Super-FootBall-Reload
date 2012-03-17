#include "Sp_Enemy.h"
#include <cstdlib>
#include <ctime>

#ifdef _DEBUG
#include <iostream>
#endif

void Sp_Enemy::Main_Script(void){
	this->Set_Speed(MyVector(0,0));
	if(this->balls_ingame){
		std::vector<Sprite*>::iterator it;
		Sprite* ball_near=NULL;
		for(it=this->balls_ingame->begin(); it!= this->balls_ingame->end(); it++){
			if(ball_near){
				if(this->Distance_Sprite(*(*it)) < this->Distance_Sprite(*ball_near)){
					ball_near=(*it);
				}
			}else{
				ball_near=(*it);
			}
		}
		if(ball_near){
			this->CTRL_Action(ball_near);
			float dist=this->Distance_Sprite(*ball_near);
			Sint16 sfaso;
			MyVector ball=ball_near->Get_Baricentro();
			MyVector enemy=this->Get_Baricentro();
			
			//calcolo sfaso
			if(dist <= 100){
				sfaso=this->sfaso_precision * 1;
			}
			if(dist > 100 && dist <=200){
				sfaso=(Sint16)((float)(this->sfaso_precision) * 1.50);
			}
			if(dist > 200){
				sfaso=this->sfaso_precision * 2;
			}
			//
			
			//calcolo della direzione sopra/sotto
			if(ball.Get_Y()+sfaso < enemy.Get_Y()){
				this->Set_Speed(MyVector(0,this->rapid_move*(-1)));
			}
			if(ball.Get_Y()-sfaso > enemy.Get_Y()){
				this->Set_Speed(MyVector(0,this->rapid_move));
			}
			//

			//esegue l'azione
			switch(this->action){
			case RETURN:
				this->Set_Speed(MyVector(this->rapid_move,this->Get_Speed().Get_Y()));
				break;
			case OFFENSIVE:
				this->Set_Speed(MyVector(this->rapid_move*(-1),this->Get_Speed().Get_Y()));
				break;
			}
			//
		}
	}
}

Sp_Enemy::Sp_Enemy(Level0* lev_sys):rapid_move(3),action(STAY),sfaso_precision(25){
	if(!lev_sys){
		//TODO: errore!
	}
	this->balls_ingame=&lev_sys->balls_ingame;
	this->sprite_player=lev_sys->Get_Sprite_Player();
	this->rand_gen.Set(5000);
	this->rand_gen.Start();
	srand((unsigned int)(time(NULL)));
}

void Sp_Enemy::CTRL_Action(const Sprite* ball){
	if(this->rand_gen.Scaduto()){
		int rnd = rand() % 5 + 1;
		if(rnd==1){
			if(ball->Get_Speed().Get_X() < 0){
				this->action=OFFENSIVE;
				return;
			}
		}
		this->rand_gen.Start();
	}
	if(ball->Get_Baricentro().Get_X() >= this->Get_Baricentro().Get_X()){
		this->action=RETURN;
		return;
	}
	if(this->action==STAY){
		if(this->Distance_Sprite(*this->sprite_player)<200){
			if(ball->Get_Speed().Get_X() < 0){
				this->action=OFFENSIVE;
				return;
			}
		}
	}
	this->action=STAY;
}