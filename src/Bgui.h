#ifndef _BGUI_SFR
#define _BGUI_SFR

/*			BGUI
	Astrazione di un'entità interfaccia ad un elemento grafico
*/

#include "MySurface.h"
#include <SDL\SDL.h>
#include <vector>
#include "OutVideo.h"
#include "colors.h"

struct Component{
	MySurface surf_component;
	Sint16 x_component;
	Sint16 y_component;
	Sint16 x_cut;
	Sint16 y_cut;
	Sint16 w_component;
	Sint16 h_component;
	bool cut_component;

	Component(void):x_component(0),y_component(0),x_cut(0),y_cut(0),w_component(0),h_component(0),cut_component(false){

	}
};

class Bgui{
private:
	/*Processa l'elemento. Viene chiamata ad ogni output a video dello stesso elemento*/
	virtual void Process(void)=0;
	Sint16 x;
	Sint16 y;

protected:
	std::vector<Component> int_components;

	/*Set Alpha alle surface. Passare '-1' per tutte! Altrimenti l'indice*/
	void SetAlpha(const int&, const Uint8&);
public:
	Bgui(const Sint16& x_init=0, const Sint16& y_init=0):x(x_init),y(y_init){

	}
	void SetX(const Sint16& x_param){
		this->x=x_param;
	}
	void SetY(const Sint16& y_param){
		this->y=y_param;
	}
	const Sint16& GetX(void) const{
		return this->x;
	}
	const Sint16& GetY(void) const{
		return this->y;
	}

	/*OutPut a video dell'elemento grafico*/
	friend OutVideo& operator<<(OutVideo&, Bgui&);

	/*Ritorna TRUE se la risorsa grafica è vuota (priva di componenti)*/
	bool Empty(void) const{
		if(this->int_components.size() == 0){
			return true;
		}
		return false;
	}

	/*Accesso alle surface dei componenti. Nel caso di accesso per un indice inesistente, il vettore componenti verrà ridimensionato*/
	MySurface& GetSurface_Component(const unsigned int& index){
		if(index + 1 <= this->int_components.size()){
			return this->int_components[index].surf_component;
		}else{
			this->int_components.resize(index + 1);
			return this->GetSurface_Component(index);
		}
	}

	/*Dealloca tutti i componenti*/
	void ClearAll(void){
		this->int_components.clear();
	}

	/*Set ColorKey alle surface. Passare '-1' per tutte!*/
	void SetColorKey(const int&, const Colors& = typ_colors::Default_Trasparent);

	/*Ritorna il Colore del pixel (rispetto alla Bgui) specificato. Ritorna false se non vengono
	trovati componenti in quella locazione.*/
	bool GetColorPixel(Colors&, const Sint16&, const Sint16);

	/*Ritorna il puntatore la MySurface del componente che si trova alle coordinate (da schermo) indicate
	Inoltre il 3 parametro è output e indica l'indice dell'array del componente della Bgui
	Se non esiste viene ritornato un valore NULLO*/
	MySurface* GetSurface_AtPos(const Sint16&, const Sint16&, int&);

	/*Ritorna TRUE se la Bgui corrente è sovrapposta (con pixel!) (il controllo viene fatto su tutti i componenti)
	ad un'altra Bgui*/
	bool CheckCollision(Bgui&);
};

OutVideo& operator<<(OutVideo&, Bgui&);

#endif