#ifndef _SOUND_SFR
#define _SOUND_SFR

/*			SOUND
	Questa classe rappresenta un'astrazione del tipo Mix_Chunk definito nella libreria SDL_mix
*/

#include <SDL\SDL_mixer.h>
#include <string>

class Sound{
private:
	Mix_Chunk* pSound;
	std::string filename_mem;
public:
	Sound(void);
	~Sound(void);

	Sound& operator=(const Sound&);
	operator Mix_Chunk*(void);
	operator int(void);

	bool LoadSound(const std::string&);
	void FreeSound(void);
	bool IsLoaded(void) const;
};

#endif