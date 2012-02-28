#ifndef _OUTVIDEO_SFR
#define _OUTVIDEO_SFR

#include "MySurface.h"
#include "Opzioni.h"

class OutVideo{
private:
	MySurface screen;
	Uint32 time_last_call_flip;

	MySurface backbuffer;
public:
	OutVideo(void);
	bool Open_MainWin(const OpzioniGame&);
	void Close_MainWin(void);
	
	void Flip(void);
	void DrawnBackBuffer(void);

	OutVideo& operator<<(MySurface&);

	static void BlitSurface(SDL_Surface *src, SDL_Rect *srcrect, SDL_Surface *dst, SDL_Rect *dstrect);

	operator SDL_Surface*(void){
		return screen;
	}
};

#endif