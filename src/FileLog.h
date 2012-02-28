#ifndef _FILELOG_SFR_
#define _FILELOG_SFR_

#include <fstream>
#include <string>
#include <iostream>

/*
		_ERROR_FORM_
	Avviso di registro 	0x...
	Errore critico 		1x...
	Avviso di Debug		2x...
*/

class Errore_Form{
public:
	std::string ID;
	std::string message;

	Errore_Form(const std::string& id_p, const std::string& mess_p): ID(id_p), message(mess_p){

	}
};

class FileLog{
private:
	std::ofstream pFile;
	std::string reg_filename;

	void Write_String(const std::string& mString){
		if(this->pFile.is_open()){
#ifdef _DEBUG
			std::cout << mString;
#endif
			this->pFile << mString;
		}
	}
public:
	FileLog(const std::string&, bool=true);
	~FileLog(void);

	bool OpenStream(void);
	void CloseStream(void);

	FileLog& operator<<(const std::string&);
	FileLog& operator<<(const Errore_Form&);

	void _OutMessage_Pox(const Errore_Form&, const char*, const long);

	void Stampa_Intestazione(void);
};

#endif