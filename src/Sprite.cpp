#include "Sprite.h"
#include "global.h"
#include <fstream>
#include "Bcol.h"

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
	file.open(filename_adjust);
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
			this->box_collide[i]=(*it);
			i++;
		}
	}

	file.close();
}