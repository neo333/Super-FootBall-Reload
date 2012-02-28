#ifndef _OUTSOUND_SFR
#define _OUTSOUND_SFR

#include "Sound.h"

class OutSound{
private:
	bool loaded;
public:
	OutSound(void);
	~OutSound(void);

	bool LoadSystem(void);
	void CloseSystem(void);
	bool IsLoaded(void) const{
		return this->loaded;
	}

	OutSound& operator<<(Sound&);
};

#endif