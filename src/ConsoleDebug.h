#ifndef _CONSOLEDEBUG_SFR
#define _CONSOLEDEBUG_SFR

#include <string>

class ConsoleDebug{
private:
	struct Cmd_Dec{
		enum Istruzione{
			NOT_DEFINE,
			MAKE_BCOL_FILE,
			DEBUG_BCOL_VIS
		}istruzione_int;
		std::string string1;

		Cmd_Dec(void):istruzione_int(ConsoleDebug::Cmd_Dec::NOT_DEFINE){
		}
	}cmd_int;

	ConsoleDebug(void){

	}
	void DecodeCMD(const std::string&);
	void ZeroCmd_Int(void);
	void Exeque(void);
public:
	static void Run(const std::string&);
};

/*			COMANDI della console di DEBUG
NOTA PRELIMINARE:
	Per informazioni sulla console di Debug leggere il file di documentazione.

COMANDI:
	> bcol_make -f[filename]
		esegue la conversione in file ".bcol" del file immesso come parametro

	> bcol_vis
		attiva/disattiva (switch) la visualizzazione dei Box_Collide sullo schermo

*/

#endif