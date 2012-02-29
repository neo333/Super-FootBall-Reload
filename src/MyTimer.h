#ifndef _MYTIMER_SFR
#define _MYTIMER_SFR

#include <SDL\SDL.h>

class MyTimer{
private:
	Uint32 time_start;
	Uint32 delay_int;
	bool started;
public:
	MyTimer(void):delay_int(0),time_start(0),started(false){

	}
	MyTimer(const Uint32& delay_param, bool start_param=false): delay_int(delay_param), time_start(0){
		if(start_param){
			this->Start();
		}
	}
	void Start(void){
		this->time_start=SDL_GetTicks();
		this->started=true;
	}
	void Stop(void){
		this->started=false;
	}
	bool Scaduto(void) const{
		if(this->started){
			if(SDL_GetTicks()-this->time_start >= this->delay_int){
				return true;
			}
		}
		return false;
	}
	void Set(const Uint32& delay_param){
		this->started=false;
		this->delay_int=delay_param;
	}
};

#endif