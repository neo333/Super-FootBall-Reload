#include "MyVector.h"
#include <SDL/SDL_gfxPrimitives.h>

OutVideo& operator<<(OutVideo& screen, const MyVector oth){
	if(pixelRGBA(screen,oth.x,oth.y,oth.mColor.c_red,oth.mColor.c_green,oth.mColor.c_blue,255)!=0){
		//TODO: fare errore!
	}
	return screen;
}
