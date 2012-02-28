#ifndef _GLOBAL_SFR
#define _GLOBAL_SFR

#include "FileLog.h"
#include "HardDisk.h"
#include "OutVideo.h"
#include "Applicazione.h"
#include "Tastiera.h"
#include "MyFont.h"

namespace sys_data{
	static const char filename_registro[]="Data/sys/Registro.log";		//Pat. Registro fisico
	extern FileLog Registro;											//Registro globale
	static const char filename_opzioni[]="Data/sys/Opz_data.bin";		//Pat Opzioni fisico
	extern HardDisk hd_sysdata;											//Hard Disk applicazione
	extern OutVideo* win_main;											//finestra principale dell'applicazione
	extern Applicazione* app_main;										//puntatore dell'applicazione principale
	extern Tastiera keys_main;											//tastiera principale dell'applicazione
	extern Punto Mouse_Coordinate;										//coordinate del mouse in tempo reale
	extern OutSound* sound_main;										//systema sound principale
}

namespace files_image_pat{
	static const char backbufferscreen[]="Data/images/backbuffer.bin";	//sfondo nero
}

namespace fonts_data{
	extern MyFont font_puls;
}

#define OutRegistro(X) sys_data::Registro._OutMessage_Pox(X,__FILE__,__LINE__);
#endif