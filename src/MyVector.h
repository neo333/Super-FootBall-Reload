#ifndef _MYVECTOR_SFR
#define _MYVECTOR_SFR

#include <SDL\SDL.h>

class MyVector{
private:
	Sint16 x;
	Sint16 y;
public:
	MyVector(void):x(0),y(0){

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
};

#endif