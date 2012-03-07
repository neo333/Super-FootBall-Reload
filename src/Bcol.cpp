#include "Bcol.h"
#include <fstream>
#include <SDL\SDL_image.h>

bool Bcol::Converted_IMAGE(const std::string& file_name_input, const std::string& file_name_output){
	if(file_name_input.size()==0){
		return false;
	}
	MySurface image=IMG_Load(file_name_input.c_str());
	if(image.IsLoaded()==false){
		return false;
	}
	int w_image=image.Get_WSurface();
	int h_image=image.Get_HSurface();
	int x,y;
	Colors col_image;
	std::vector<MyRect> out;

	for(y=0; y<h_image; y++){
		for(x=0; x<w_image; x++){
			if(image.GetColorPixel(col_image,x,y)==false){
				return false;
			}
			if(col_image!=typ_colors::Default_Trasparent){
				Bcol::Make_Rect(x,y,out,image);
			}
		}
	}
	image.FreeSurface();

	std::ofstream file_out;
	std::vector<MyRect>::iterator it;
	file_out.open(file_name_output);
	if(file_out.is_open()==false){
		return false;
	}


	for(it=out.begin(); it!=out.end(); it++){
		file_out.write((const char*)(&(*it)),sizeof(MyRect));
	}
	file_out.close();

	return true;
}

void Bcol::Make_Rect(const int& x,const int& y, std::vector<MyRect>& list, MySurface& image){
	register std::vector<MyRect>::iterator elem;
	for(elem=list.begin(); elem!=list.end(); elem++){
		if(Bcol::Point_into_Rect(x,y,(*elem))==true){
			return;
		}
	}

	MyRect ins;
	Colors col_image;
	int temp;
	int w_image=image.Get_WSurface();
	int h_image=image.Get_HSurface();

	ins.x=x;
	ins.y=y;
	bool exit=false;
	for(temp=x;!exit && temp < w_image;temp++){
		if(image.GetColorPixel(col_image,temp,y)==false){
			/*TODO: lanciare errore! qualcosa è andato storto con la funzione GetColorPixel*/
			return;
		}
		if(col_image==typ_colors::Default_Trasparent){
			exit=true;
		}
	}
	ins.w=temp-x;

	exit=false;
	for(temp=y;!exit && temp < h_image;temp++){
		if(image.GetColorPixel(col_image,x,temp)==false){
			/*TODO: lanciare errore! qualcosa è andato storto con la funzione GetColorPixel*/
			return;
		}
		if(col_image==typ_colors::Default_Trasparent){
			exit=true;
		}
	}
	ins.h=temp-y;

	list.push_back(ins);
}