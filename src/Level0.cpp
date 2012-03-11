#include "Level0.h"
#include "Scripts.h"

#ifdef _DEBUG
#include <iostream>
#endif

static const std::string wall_filename("Data/images/sp_wall.bin");
static const std::string pg_filename("Data/images/sp_p.bin");
static const std::string ball_filename("Data/images/sp_ball.bin");
static const Sint16 X_PLAYER_START=50;
static const Sint16 Y_PLAYER_START=250;

void Level0::Load(void){
	Sprite wall;
	unsigned int size;

	wall.Load(wall_filename);
	wall.Set_Face(DIR_UP);

	//mura superiori
	wall.SetY(0);
	this->object.insert(this->object.begin(),20,wall);
	size=this->object.size();
	for(unsigned int i=0; i<size; i++){
		this->object[i].SetX(i*40);
	}

	//mura inferiori
	wall.Set_Face(DIR_DOWN);
	wall.SetY(535);
	this->object.insert(this->object.end(),20,wall);
	for(unsigned int i=size; i<this->object.size(); i++){
		this->object[i].SetX((i-size)*40);
	}

	//mura sinistre
	wall.Set_Face(DIR_LEFT);
	wall.SetX(0);
	wall.SetY(10);
	for(unsigned int i=0; i<5; i++){
		this->object.insert(this->object.end(),1,wall);
		this->object.back().SetY(i*40+wall.GetY());
	}
	wall.SetX(0);
	wall.SetY(524);
	for(unsigned int i=0; i<5; i++){
		this->object.insert(this->object.end(),1,wall);
		this->object.back().SetY(wall.GetY()-i*40);
	}

	//mura destre
	wall.Set_Face(DIR_RIGHT);
	wall.SetX(760);
	wall.SetY(8);
	for(unsigned int i=0; i<5; i++){
		this->object.insert(this->object.end(),1,wall);
		this->object.back().SetY(i*40+wall.GetY());
	}
	wall.SetX(760);
	wall.SetY(524);
	for(unsigned int i=0; i<5; i++){
		this->object.insert(this->object.end(),1,wall);
		this->object.back().SetY(wall.GetY()-i*40);
	}

	//player
	this->object.insert(this->object.end(),1,Sprite());
	this->object.back().Load(pg_filename);
	this->mplayer.Set_Operator_Sprite(&this->object.back());


	//inizializza le posizioni
	this->Set_PositionSTART_Players();
}

void Level0::UnLoad(void){
	this->object.clear();
	this->mplayer.Set_Operator_Sprite(NULL);
}

void Level0::Process(const type_event::mess_event& mEvent, OutVideo& screen){
	this->mplayer.Run(mEvent);

	//controllo su tutte le palle in game
	if(this->balls_ingame.size()!=0){
		std::vector<Sprite*>::iterator it;
		for(it=this->balls_ingame.begin(); it!=this->balls_ingame.end(); ){
			if((*it)->Is_Visible_InScreen()==false){
				this->DeleteSprite((*it));
				it=this->balls_ingame.erase(it);
			}else{
				it++;
			}
		}
	}else{
		this->Create_Ball();
	}
}

void Level0::Create_Ball(void){
	this->object.insert(this->object.end(),1,Sprite());
	this->object.back().Load(ball_filename);
	this->object.back().SetX(400);
	this->object.back().SetY(300);
	this->object.back().Set_Script(scripts_sprite::script_ball_vone);
	this->object.back().Set_Speed(MyVector(-3,-3));

	this->balls_ingame.insert(this->balls_ingame.end(),&(this->object.back()));
}

void Level0::Set_PositionSTART_Players(void){
	if(this->mplayer.Get_Sprite()){
		this->mplayer.Get_Sprite()->SetX(X_PLAYER_START);
		this->mplayer.Get_Sprite()->SetY(Y_PLAYER_START);
		this->mplayer.Get_Sprite()->Set_Face(DIR_RIGHT);
	}
}