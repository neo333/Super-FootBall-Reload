#ifndef _SPRITE_SFR
#define _SPRITE_SFR

#include "Bgui.h"
#include "MyTimer.h"
#include "MyVector.h"
#include "MyRect.h"
#include <set>

class Sprite;

enum Direction{
	DIR_UP,
	DIR_DOWN,
	DIR_LEFT,
	DIR_RIGHT
};

class Collision{
private:
	const Sprite* oth_obj;
	const Direction dir_oth_obj;

	friend class Sprite;
	operator const Sprite&(void)const{
		return *this->oth_obj;
	}
public:
	Collision(const Sprite* oo_param, const Direction& dir_param):oth_obj(oo_param),dir_oth_obj(dir_param){
		if(!this->oth_obj){
			//TODO: fare errore! è stata creata una collisione nulla!
		}
	}
	bool operator<(const Collision& oth) const{
		if((int)(this->oth_obj)<(int)(oth.oth_obj)){
			return true;
		}
		return false;
	}

	const Sprite* Get_SpritePointer(void) const{
		return this->oth_obj;
	}
	const Direction& Get_DirectionObj(void) const{
		return this->dir_oth_obj;
	}
};

class Sprite: public Bgui{
private:
	void Process(void);
	Direction face;

	unsigned short frame;
	MyTimer delay_frames;
	bool anim;

	MyVector speed;

	std::vector<MyRect> box_collide;
	void Load_BoxCollide(const std::string&);

	std::set<Collision> list_collide;

	virtual void Main_Script(void){

	}

	bool constraint_area_active;
	MyRect constraint_area;
public:
	Sprite(void):frame(0),anim(false),face(DIR_DOWN),constraint_area_active(false){
		this->Set_Delay_Frames(130);
		this->box_collide.resize(4);
	}

	/*Carica un'immagine di tipo Sprite!*/
	void Load(const std::string&);

	/*Setta il tempo (in millisecs) di attesa tra un frame e l'altro di animazione*/
	void Set_Delay_Frames(const Uint32& pDelay){
		this->delay_frames.Set(pDelay);
	}

	/*Setta se lo sprite è in modalita' di animazione o no*/
	void Set_Anim(const bool sw){
		switch(sw){
		case true:
			if(this->anim==false){
				this->delay_frames.Start();
			}
			break;
		case false:
			if(this->anim==true){
				this->delay_frames.Stop();
			}
			break;
		}
		this->anim=sw;
	}

	/*Setta la direzione dello Sprite*/
	void Set_Face(const Direction& pDir){
		this->face=pDir;
	}

	/*Setta la velocità di spostamento dello sprite*/
	void Set_Speed(const MyVector& pSpeed){
		this->speed=pSpeed;
	}

	/*Ritorna la velocità di spostamento di uno sprite*/
	const MyVector& Get_Speed(void) const{
		return this->speed;
	}

	/*Svuota la lista delle collisioni*/
	void Clear_ListCollide(void){
		this->list_collide.clear();
	}

	/*Aggiunge una collisione alla lista delle collisioni*/
	void Add_ListCollide(const Collision& col_param){
		if(this!=col_param.Get_SpritePointer()){
			this->list_collide.insert(col_param);
		}
	}

	/*Sposta lo sprite in una direzione del valore indicato*/
	void Traslate_Instant(const Direction& p_dir, const Sint16& p_mov){
		switch(p_dir){
		case DIR_UP:
			this->SetY(this->GetY() - p_mov);
			break;
		case DIR_DOWN:
			this->SetY(this->GetY() + p_mov);
			break;
		case DIR_RIGHT:
			this->SetX(this->GetX() + p_mov);
			break;
		case DIR_LEFT:
			this->SetX(this->GetX() - p_mov);
			break;
		default:
			//TODO: errore! direzione non valide
			return;
		}
	}

	/*Ritorna il MyRect(Box) per la collisione (relativo allo schermo!)*/
	MyRect Get_Box_Collide(void) const{
		MyRect rts;
		switch(this->face){
		case DIR_DOWN:
			rts=this->box_collide[0];
			break;
		case DIR_UP:
			rts=this->box_collide[3];
			break;
		case DIR_RIGHT:
			rts=this->box_collide[2];
			break;
		case DIR_LEFT:
			rts=this->box_collide[1];
			break;
		}
		rts.x+=this->GetX();
		rts.y+=this->GetY();
		return rts;
	}

	/*Ritorna True se due sprite collidono*/
	bool Collide_with_Sprite(const Sprite&) const;

	/*Ritorna la lista delle collisioni dell'oggetto*/
	const std::set<Collision>& Get_Collide_List(void) const{
		return this->list_collide;
	}

	/*Ritorna la collisione più vicina dell'oggetto (in caso collida con più oggetti)
	In caso di nessuna collisione ritorna NULL!*/
	const Collision* Get_Collide_Near(void) const{
		const Collision* rts=NULL;
		std::set<Collision>::iterator it;
		for(it=this->list_collide.begin(); it!=this->list_collide.end(); it++){
			if(rts){
				if(this->Distance_Sprite((*it)) < this->Distance_Sprite(*rts)){
					rts=&(*it);
				}
			}else{
				rts=&(*it);
			}
		}
		return rts;
	}

	/*Ritorna la posizione dello Sprite passato nel parametro rispetto a l'oggetto in questionE*/
	const Direction Pos_Relative(const Sprite&) const;

	/*Ritorna il baricentro dello sprite*/
	const MyVector Get_Baricentro(void) const{
		MyRect temp=this->Get_Box_Collide();
		return MyVector(temp.x+(temp.w/2),temp.y+(temp.h/2));
	}

	/*Ritorna TRUE se lo sprite è visibile sullo schermo*/
	bool Is_Visible_InScreen(void) const;

	/*Ritorna la distanza in float con lo sprite passato nel parametro*/
	float Distance_Sprite(const Sprite& oth) const{
		MyVector dist_point=this->Get_Baricentro()-oth.Get_Baricentro();
		return dist_point.Module();
	}

	/*Ritorna lo stato dell'area di costrizione dello sprite*/
	bool Get_Constraint_Area(MyRect& rparam) const{
		rparam=this->constraint_area;
		return this->constraint_area_active;
	}

	/*Setta lo stesto dell'area di costrizione dello sprite*/
	void Set_Constraint_Area(const MyRect& rparam, bool bparam){
		this->constraint_area=rparam;
		this->constraint_area_active=bparam;
	}
};

OutVideo& operator<<(OutVideo&, Sprite&);

#endif