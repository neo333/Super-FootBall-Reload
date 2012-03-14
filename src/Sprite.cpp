#include "Sprite.h"
#include "global.h"
#include <fstream>
#include "Bcol.h"
#include <SDL\SDL_collide.h>

#ifdef _DEBUG
#include <iostream>
#endif

namespace dims_frames{
	static const Sint16 wc=40;
	static const Sint16 hc=62;
	static const Sint16 n_frames=4;
}

void Sprite::Load(const std::string& file_name){
	this->GetSurface_Component(0).Load(file_name);
	this->Load_BoxCollide(file_name);
	this->SetColorKey(0);	
}

void Sprite::Process(void){
	Sint16 xc,yc;
	switch(this->face){
	case DIR_UP:
		yc=3*dims_frames::hc;
		break;
	case DIR_DOWN:
		yc=0*dims_frames::hc;
		break;
	case DIR_LEFT:
		yc=1*dims_frames::hc;
		break;
	case DIR_RIGHT:
		yc=2*dims_frames::hc;
		break;
	default:
		//TODO: fare errore (non può verificarsi questa possibilità!)
		break;
	}
	if(this->anim){
		if(this->delay_frames.Scaduto()){
			this->frame++;
			if(this->frame>=dims_frames::n_frames){
				this->frame=0;
			}
			this->delay_frames.Start();
		}
	}else{
		this->frame=0;
	}
	xc=this->frame*dims_frames::wc;

	Component* pcomp=&this->int_components[0];
	pcomp->cut_component=true;
	pcomp->x_cut=xc;
	pcomp->y_cut=yc;
	pcomp->w_cut=dims_frames::wc;
	pcomp->h_cut=dims_frames::hc;

	this->Main_Script();
}

void Sprite::Load_BoxCollide(const std::string& filename){
	std::string filename_adjust=filename;
	std::string name;
	size_t cur;
	do{
		cur=filename_adjust.find('\\');
		if(cur!=filename_adjust.npos){
			filename_adjust.replace(cur,1,1,'/');
		}
	}while(cur!=filename_adjust.npos);
	cur=filename_adjust.rfind('/');
	name=filename_adjust.substr(cur,filename_adjust.size()-cur-3);
	name+="bcol";
	cur=filename_adjust.rfind('/',cur-1);
	filename_adjust=filename_adjust.substr(0,cur);
	filename_adjust+="/bcol";
	filename_adjust+=name;

	std::ifstream file;
	std::vector<MyRect> list;
	MyRect temp_ins;
	file.open(filename_adjust, std::ios::binary);
	if(file.is_open()==false){
		return;
	}
	while(!file.eof()){
		file.read((char*)(&temp_ins),sizeof(MyRect));
		list.push_back(temp_ins);
	}

	register std::vector<MyRect>::iterator it;
	MyRect temp_box;
	register unsigned int i=0;
	for(it=list.begin(); it!=list.end(); it++){
		temp_box.x=0;
		temp_box.y=dims_frames::hc*i;
		temp_box.w=dims_frames::wc;
		temp_box.h=dims_frames::hc;
		if(Bcol::Point_into_Rect((*it).x,(*it).y,temp_box)==true){
			(*it).y-=dims_frames::hc*i;
			this->box_collide[i]=(*it);
			i++;
		}
	}

	file.close();
}

bool Sprite::Collide_with_Sprite(const Sprite& oth) const{
	if(SDL_CollideBoundingBox2(this->Get_Box_Collide(),oth.Get_Box_Collide())){
		return true;
	}
	return false;
}

OutVideo& operator<<(OutVideo& screen, Sprite& oth){
	screen << (Bgui&)oth;

#ifdef _DEBUG
	if(sys_data::app_main->Get_Debug_Vis_Bcol()){
		screen << oth.Get_Box_Collide();
		screen << oth.Get_Baricentro();
	}
#endif

	return screen;
}

const Direction Sprite::Pos_Relative(const Sprite& oth) const{
	MyVector point=oth.Get_Baricentro()-this->Get_Baricentro();
	point.Set_Y(point.Get_Y()*-1);
	if(point.Get_Y() >= point.Get_X() && point.Get_Y() >= point.Get_X()*-1){
		return DIR_UP;
	}
	if(point.Get_Y() <= point.Get_X() && point.Get_Y() <= point.Get_X()*-1){
		return DIR_DOWN;
	}
	if(point.Get_Y() <= point.Get_X() && point.Get_Y() >= point.Get_X()*-1){
		return DIR_RIGHT;
	}
	if(point.Get_Y() >= point.Get_X() && point.Get_Y() <= point.Get_X()*-1){
		return DIR_LEFT;
	}
	//TODO: errore!

	return DIR_DOWN;
}

bool Sprite::Is_Visible_InScreen(void) const{
	if(SDL_CollideBoundingBox2(this->Get_Box_Collide(),MyRect(0,0,sys_data::app_main->Get_W_Screen(),sys_data::app_main->Get_H_Screen()))){
		return true;
	}
	return false;
}