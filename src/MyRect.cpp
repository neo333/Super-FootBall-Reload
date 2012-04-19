#include "MyRect.h"
#include <SDL/SDL_gfxPrimitives.h>

OutVideo& operator<<(OutVideo& screen, const MyRect& oth){
	if(rectangleColor(screen,oth.x,oth.y,oth.w+oth.x,oth.h+oth.y,0xFF0000FF)){
		//TODO: errore! funzione di disegno fallita!
	}
	return screen;
}
