#ifndef _BOTTONE_SFR
#define _BOTTONE_SFR

#include "Bgui.h"
#include "Testo.h"
#include "SysEvent.h"
#include "Sound.h"

class Bottone: public Bgui{
private:
	void Process(void);
	Testo text_main;
	Sint16 botw_size;

	static Sound snd_clic;

	void (*action_clic)(void);

	void SetSelect(const bool&);
public:
	Bottone(const std::string& = std::string());
	void Load(const unsigned int&);
	void SetText(const std::string&);
	void SetAction_Clic(void (*)(void));

	Bottone& operator<<(const type_event::mess_event&);

	friend OutVideo& operator<<(OutVideo&,Bottone&);
};

OutVideo& operator<<(OutVideo&,Bottone&);

#endif