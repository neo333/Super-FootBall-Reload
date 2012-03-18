#include "Level0.h"
#include "Scripts.h"

#ifdef _DEBUG
#include <iostream>
#endif

static const std::string wall_filename("Data/images/sp_wall.bin");
static const std::string pg_filename("Data/images/sp_p.bin");
static const std::string enemy_filename("Data/images/sp_e.bin");
static const std::string ball_filename("Data/images/sp_ball.bin");
static const Sint16 X_PLAYER_START=50;
static const Sint16 Y_PLAYER_START=250;
static const Sint16 X_ENEMY_START=700;
static const Sint16 Y_ENEMY_START=250;

void Level0::Load(void){
	Sprite* curs;
	for(unsigned int i=0; i<20; i++){
		curs=this->Insert_Sprite();
		curs->Load(wall_filename);
		curs->Set_Face(DIR_UP);
		curs->SetY(0);
		curs->SetX(i*40);
	}

	//mura inferiori
	for(unsigned int i=0; i<20; i++){
		curs=this->Insert_Sprite();
		curs->Load(wall_filename);
		curs->Set_Face(DIR_DOWN);
		curs->SetY(535);
		curs->SetX(i*40);
	}

	//mura sinistre
	for(unsigned int i=0; i<5; i++){
		curs=this->Insert_Sprite();
		curs->Load(wall_filename);
		curs->Set_Face(DIR_LEFT);
		curs->SetY(i*40+8);
		curs->SetX(0);
	}
	for(unsigned int i=0; i<5; i++){
		curs=this->Insert_Sprite();
		curs->Load(wall_filename);
		curs->Set_Face(DIR_LEFT);
		curs->SetY(524-i*40);
		curs->SetX(0);
	}

	//mura destre
	for(unsigned int i=0; i<5; i++){
		curs=this->Insert_Sprite();
		curs->Load(wall_filename);
		curs->Set_Face(DIR_RIGHT);
		curs->SetY(i*40+8);
		curs->SetX(760);
	}
	for(unsigned int i=0; i<5; i++){
		curs=this->Insert_Sprite();
		curs->Load(wall_filename);
		curs->Set_Face(DIR_RIGHT);
		curs->SetY(524-i*40);
		curs->SetX(760);
	}

	//pg
	curs=this->Insert_Sprite();
	curs->Load(pg_filename);
	curs->Set_Constraint_Area(MyRect(0,0,770,600),true);
	this->Set_Sprite_Player(curs);

	//nemico
	curs=this->Insert_Sprite(SP_ENEMY);
	curs->Load(enemy_filename);
	curs->Set_Constraint_Area(MyRect(0,0,770,600),true);
	this->sprite_enemy=curs;

	//inizializza le posizioni
	this->Set_PositionSTART_Players();
}

void Level0::UnLoad(void){
	this->Clear_AllSprites();
	this->Set_Sprite_Player(NULL);
}

void Level0::Process(const type_event::mess_event& mEvent, OutVideo& screen){
	this->Check_Ball_InScreen();
}

void Level0::Create_Ball(void){
	Sprite* curr=this->Insert_Sprite(SP_BALL);
	curr->Load(ball_filename);
	curr->SetX(400);
	curr->SetY(300);
	curr->Set_Speed(MyVector(-3,-3));

	this->balls_ingame.insert(this->balls_ingame.end(),curr);
}

void Level0::Set_PositionSTART_Players(void){
	if(this->Get_Sprite_Player()){
		this->Get_Sprite_Player()->SetX(X_PLAYER_START);
		this->Get_Sprite_Player()->SetY(Y_PLAYER_START);
		this->Get_Sprite_Player()->Set_Face(DIR_RIGHT);
	}
	if(this->sprite_enemy){
		this->sprite_enemy->SetX(X_ENEMY_START);
		this->sprite_enemy->SetY(Y_ENEMY_START);
		this->sprite_enemy->Set_Face(DIR_LEFT);
	}
}

void Level0::Check_Ball_InScreen(void){
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
		this->Set_PositionSTART_Players();
	}
}