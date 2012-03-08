#include "Level0.h"
#include "Scripts.h"

static const std::string wall_filename("Data/images/sp_wall.bin");
static const std::string pg_filename("Data/images/sp_p.bin");
static const std::string ball_filename("Data/images/sp_ball.bin");

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
	this->object.back().Set_Face(DIR_RIGHT);
	this->object.back().SetX(100);
	this->mplayer.Set_Operator_Sprite(&this->object.back());

	//palla
	this->Create_Ball();
}

void Level0::UnLoad(void){
	this->object.clear();
}

void Level0::Process(const type_event::mess_event& mEvent, OutVideo& screen){
	this->mplayer.Run(mEvent);
}

void Level0::Create_Ball(void){
	this->object.insert(this->object.end(),1,Sprite());
	this->object.back().Load(ball_filename);
	this->object.back().SetX(400);
	this->object.back().SetY(300);
	this->object.back().Set_Script(scripts_sprite::script_ball_vone);
	this->object.back().Set_Speed(MyVector(-3,-3));
}