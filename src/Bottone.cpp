#include "Bottone.h"
#include "global.h"

namespace bott_filename{
	static const std::string bt_filename("Data/images/p_t1.bin");
	static const std::string snd_filename("Data/sounds/bt_cl.bin");
}

Sound Bottone::snd_clic;

Bottone::Bottone(const std::string& str_param):botw_size(0),action_clic(NULL){
	if(str_param.size() > 0){
		this->SetText(str_param);
	}
	this->text_main.SetColor(typ_colors::Bottone_NoSelect);
	this->text_main.SetFont(&fonts_data::font_puls);
}

void Bottone::Process(void){
	Size siz_temp=this->text_main.Size_String_Pixel();
	this->text_main.SetX(this->GetX()+(this->botw_size/2)-(siz_temp.w/2));
	this->text_main.SetY(this->GetY()+(52/2)-(siz_temp.h/2));
}

void Bottone::Load(const unsigned int& w_size){
	this->ClearAll();

	unsigned int i;

	this->GetSurface_Component(0).Load(bott_filename::bt_filename);
	this->int_components[0].w_component=50;
	this->int_components[0].h_component=52;
	this->int_components[0].cut_component=true;

	for(i=1; i<w_size+1; i++){
		this->GetSurface_Component(i).Load(bott_filename::bt_filename);
		this->int_components[i].x_component=i*50;
		this->int_components[i].y_component=0;
		this->int_components[i].x_cut=50;
		this->int_components[i].y_cut=0;
		this->int_components[i].w_component=50;
		this->int_components[i].h_component=52;
		this->int_components[i].cut_component=true;
	}

	this->GetSurface_Component(i).Load(bott_filename::bt_filename);
	this->int_components[i].x_component=i*50;
	this->int_components[i].y_component=0;
	this->int_components[i].x_cut=100;
	this->int_components[i].y_cut=0;
	this->int_components[i].w_component=50;
	this->int_components[i].h_component=52;
	this->int_components[i].cut_component=true;

	this->SetColorKey(-1);
	if(this->snd_clic.IsLoaded()==false){
		this->snd_clic.LoadSound(bott_filename::snd_filename);
	}
	this->botw_size=(50*2) + (50*w_size);
}

void Bottone::SetText(const std::string& str_param){
	this->text_main.SetString(str_param);
}

Bottone& Bottone::operator<<(const type_event::mess_event& mEvent){
	int index;
	MySurface* pnt;
	Colors temp;
	pnt=this->GetSurface_AtPos(sys_data::Mouse_Coordinate.x,sys_data::Mouse_Coordinate.y,index);
	if(pnt){
		if(pnt->GetColorPixel(temp,sys_data::Mouse_Coordinate.x-this->GetX(),sys_data::Mouse_Coordinate.y-this->GetY())==true){
			if(temp!=typ_colors::Default_Trasparent){
				if(mEvent==type_event::MOUSE_CLIC){
					*sys_data::sound_main << this->snd_clic;
					if(this->action_clic){
						this->action_clic();
						return *this;
					}
				}
				this->SetSelect(true);
			}else{
				this->SetSelect(false);
			}
		}else{
			this->SetSelect(false);
		}
	}else{
		this->SetSelect(false);
	}
	return *this;
}

void Bottone::SetSelect(const bool& select){
	if(select){
		if(this->text_main.GetColor()!=typ_colors::Bottone_Select){
			this->text_main.SetColor(typ_colors::Bottone_Select);
		}
	}else{
		if(this->text_main.GetColor()!=typ_colors::Bottone_NoSelect){
			this->text_main.SetColor(typ_colors::Bottone_NoSelect);
		}
	}
}

OutVideo& operator<<(OutVideo& screen,Bottone& oth){
	operator<<(screen,(Bgui&)oth);
	operator<<(screen,oth.text_main);

	return screen;
}

void Bottone::SetAction_Clic(void (*pnt_temp)(void)){
	this->action_clic=pnt_temp;
}