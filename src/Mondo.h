#ifndef _MONDO_SFR
#define _MONDO_SFR

#include "Sprite.h"
#include <vector>
#include "SysEvent.h"

class Mondo{
private:
	//questa funzione verrà chiamata un attimo prima del disegno a video del Mondo
	virtual void Process(void)=0;
protected:
	std::vector<Sprite> object;
public:
	Mondo(void){

	}
	~Mondo(void){
		this->object.clear();
	}
	virtual void Load(void)=0;
	virtual void UnLoad(void)=0;
	
	friend OutVideo& operator<<(OutVideo&, Mondo&);
};

OutVideo& operator<<(OutVideo&, Mondo&);

#endif