#include "Level0.h"

static const std::string wall_filename("Data/images/sp_wall.bin");
static const std::string pg_filename("Data/images/sp_p.bin");

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

	//player
	this->object.insert(this->object.end(),1,Sprite());
	this->object.back().Load(pg_filename);
	this->object.back().Set_Face(DIR_RIGHT);
	this->mplayer.Set_Operator_Sprite(&this->object.back());
}

void Level0::UnLoad(void){
	this->object.clear();
}

void Level0::Process(const type_event::mess_event& mEvent, OutVideo& screen){
	this->mplayer.Run(mEvent);
}