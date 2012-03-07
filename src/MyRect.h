#ifndef _MYRECT_SFR
#define _MYRECT_SFR

#include <SDL\SDL.h>

class MyRect{
public:
	Sint16 x;
	Sint16 y;
	Sint16 w;
	Sint16 h;

	MyRect(const Sint16& x_p=0, const Sint16& y_p=0, const Sint16& w_p=0, const Sint16& h_p=0):x(x_p),
		y(y_p),w(w_p),h(h_p){

	}
};

#endif