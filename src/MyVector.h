#ifndef _MYVECTOR_SFR
#define _MYVECTOR_SFR

#include <SDL\SDL.h>
#include "OutVideo.h"
#include "colors.h"
#include <cmath>

class MyVector{
private:
	Colors mColor;

	Sint16 x;
	Sint16 y;
public:
	MyVector(const Sint16& x_param=0, const Sint16& y_param=0, const Colors& c_param=Colors(255,0,0)):x(x_param),y(y_param),mColor(c_param){

	}

	void Set_X(const Sint16& p_x){
		this->x=p_x;
	}
	void Set_Y(const Sint16& p_y){
		this->y=p_y;
	}
	const Sint16& Get_X(void) const{
		return this->x;
	}
	const Sint16& Get_Y(void) const{
		return this->y;
	}
	void Set_Color(const Colors& c_param){
		this->mColor=c_param;
	}
	const Colors& Get_Color(void) const{
		return this->mColor;
	}

	MyVector operator-(const MyVector& oth) const{
		return MyVector(this->x - oth.x,this->y - oth.y);
	}
	MyVector operator*(const int& oth) const{
		return MyVector(this->x*oth,this->y*oth);
	}
	bool operator==(const MyVector& oth)const{
		if(this->x==oth.x && this->y==oth.y){
			return true;
		}
		return false;
	}

	float Module(void) const{
		return sqrt((float)((this->x*this->x) + (this->y*this->y)));
	}

	friend OutVideo& operator<<(OutVideo&, const MyVector);
};

OutVideo& operator<<(OutVideo&, const MyVector);

#endif