#ifndef _SYSEVENT_SFR
#define _SYSEVENT_SFR

#include <SDL\SDL.h>

namespace type_event{
	enum mess_event{
		NONE,
		QUIT_APP,
		KEY_PRESS,
		KEY_RELASE,
		MOUSE_CLIC
	};
}

class SysEvent{
private:
	SDL_Event mEvent;
public:
	type_event::mess_event UpDateEvents(void);
};

#endif