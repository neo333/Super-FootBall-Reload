#include "Mondo.h"

OutVideo& operator<<(OutVideo& screen, Mondo& obj){
	unsigned int size=obj.object.size();
	for(register unsigned int i=0; i<size; i++){
		screen << obj.object[i];
	}
	return screen;
}