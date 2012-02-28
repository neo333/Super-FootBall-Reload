#ifndef _OPZIONI_SFR_
#define _OPZIONI_SFR_

#include <string>

class OpzioniGame{
private:
	bool full_screen;
	int w_win;
	int h_win;
	int bpp_win;

	void SetDefault(void);
public:
	OpzioniGame(void);
	bool Load_to_file(const std::string&);
	void Save_to_file(const std::string&) const;

	const bool& Get_FullScreen(void) const{
		return this->full_screen;
	}
	const int& Get_Wwin(void) const{
		return this->w_win;
	}
	const int& Get_Hwin(void) const{
		return this->h_win;
	}
	const int& Get_Bppwin(void) const{
		return this->bpp_win;
	}
};

#endif