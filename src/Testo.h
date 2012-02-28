#ifndef _TESTO_SFR
#define _TESTO_SFR

#include "Bgui.h"
#include "MyFont.h"
#include "colors.h"

struct Size{
	Sint16 w;
	Sint16 h;

	Size(void):w(0),h(0){

	}
};

class Testo: public Bgui{
private:
	void Process(void){

	}

	std::string str_main;
	MyFont* font_main;
	Colors color_main;

	void Render(void);
public:
	Testo(const std::string& str=std::string()):font_main(NULL){
		if(str.size()>0){
			this->SetString(str);
		}
	}
	void FreeTesto(void);
	void SetString(const std::string&);
	void SetFont(MyFont*);
	void SetColor(const Colors&);
	Size Size_String_Pixel(void) const;

	const Colors& GetColor(void) const{
		return this->color_main;
	}
};

#endif