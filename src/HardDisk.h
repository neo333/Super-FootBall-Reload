#ifndef _HARD_DISK_SFR
#define _HARD_DISK_SFR

#include <SDL/SDL.h>
#include <map>
#include <string>
#include "MySurface.h"
#include <SDL/SDL_mixer.h>

class HardDisk{
private:
	std::map<std::string, MySurface> caches_surfaces;

	void SvuotaCaches(void){
		this->caches_surfaces.clear();
	}
	void CheckCaches(void);
public:
	HardDisk(void){

	}
	bool LoadSurface_to_file(const std::string&, MySurface&);
	void DEBUG_OutAllCaches_Surface(void) const;

	Mix_Chunk* LoadSound_to_file(const std::string&);
};

#endif
