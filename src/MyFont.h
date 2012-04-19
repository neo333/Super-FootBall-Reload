#ifndef _MYFONT_SFR
#define _MYFONT_SFR

/*
		MyFont
	Questa classe rappresenta un'astrazione del gi� noto tipo TTF_Font della libreria SDL
*/

#include <SDL/SDL_ttf.h>
#include <string>

class MyFont{
private:
	TTF_Font* pFont;
public:
	MyFont(void);
	~MyFont(void);

	void FreeFont(void);
	void LoadFont(const std::string&, int);

	operator TTF_Font*(void){
		return this->pFont;
	}
};

#endif
