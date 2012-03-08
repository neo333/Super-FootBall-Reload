#ifndef _MYVECTOR_SFR
#define _MYVECTOR_SFR

#include <SDL\SDL.h>

class MyVector{
private:
	Sint16 x;
	Sint16 y;
public:
	MyVector(const Sint16& x_param=0, const Sint16& y_param=0):x(x_param),y(y_param){

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

	MyVector operator-(const MyVector& oth) const{
		return MyVector(this->x - oth.x,this->y - oth.y);
	}

	MyVector operator*(const int& oth) const{
		return MyVector(this->x*oth,this->y*oth);
	}
};

#endif