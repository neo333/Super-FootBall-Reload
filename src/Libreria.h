#ifndef _LIBRERIA_SFR
#define _LIBRERIA_SFR

enum LIB_TYPE{
	NOT_DEFINE,
	SDL_MAIN,
	SDL_IMG,
	SDL_TTF,
	SDL_MIX
};

class Libreria{
private:
	bool loaded;
	LIB_TYPE typ_library;
public:
	Libreria(const LIB_TYPE&);
	~Libreria(void);

	void Chiudi_Libreria(void);
	bool Apri_Libreria(void);
};

#endif