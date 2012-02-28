#ifndef _PICTURE_SFR
#define _PICTURE_SFR

#include "Bgui.h"
#include "colors.h"

class Picture: public Bgui{
private:
	double angle_curr;
	double zoom_curr;
	Uint8 alpha_curr;

	/**anim_alpha**/
	Uint8 alpha_dest;
	bool alpha_process;
	/**************/

	void Process(void);
public:
	Picture(void);
	void ModZoom(const double&);

	void SetAlpha(const Uint8& alpha_param){
		this->Bgui::SetAlpha(0,alpha_param);
		this->alpha_curr=alpha_param;
	}

	void Anim_SetAlpha(const Uint8&);
	bool IsAnim_Alpha(void) const{
		return this->alpha_process;
	}

	operator SDL_Surface*(void){
		return this->GetSurface_Component(0);
	}

	void Load(const std::string&);
	void FreeSurface(void);
};

#endif