#include "FileLog.h"
#include "global.h"
#include <vector>

/***************REGISTRO GLOBALE**********************/
FileLog sys_data::Registro(sys_data::filename_registro);
/*****************************************************/

FileLog::FileLog(const std::string& file_name, bool fast_open):reg_filename(file_name){
	if(fast_open){
		this->OpenStream();
	}
}

FileLog::~FileLog(void){
	this->CloseStream();
}

void FileLog::CloseStream(void){
	if(this->pFile.is_open()){
		this->pFile.close();
	}
}

bool FileLog::OpenStream(void){
	if(this->reg_filename.size() > 0){
		this->pFile.open(this->reg_filename.c_str());
		if(this->pFile.fail()){
			return false;
		}
	}else{
		return false;
	}
	this->Stampa_Intestazione();
	return true;
}

FileLog& FileLog::operator<<(const std::string& input){
	this->Write_String(input);
	return *this;
}

FileLog& FileLog::operator<<(const Errore_Form& input){
#ifndef _DEBUG
	if(input.ID.substr(0,2)=="2x"){
		return *this;
	}
#endif
	bool flag_error=false;
	this->Write_String("\t > ");
	std::string comp="1x";
	if(input.ID.substr(0,2)==comp){
		this->Write_String("Errore Critico ");
		flag_error=true;
	}else{
		this->Write_String("Avviso ");
	}
	this->Write_String("ID: ");
	*this << input.ID;

	std::vector<std::string> lines_temp;
	std::string buffer_temp(input.message);
	size_t cursor;
	bool exit=false;
	while(!exit){
		cursor=buffer_temp.find('\n');
		if(cursor==buffer_temp.npos){
			lines_temp.push_back(buffer_temp);
			exit=true;
		}else{
			lines_temp.push_back(buffer_temp.substr(0,cursor));
			buffer_temp=buffer_temp.substr(cursor+1);
		}
	}
	
	for(unsigned int i=0; i<lines_temp.size() ;i++){
		this->Write_String("\n\t\t");
		*this << lines_temp[i];
	}
	this->Write_String("\n");

	return *this;
}

void FileLog::_OutMessage_Pox(const Errore_Form& input, const char* file_p, const long line_p){
	*this << input;
#ifdef _DEBUG
	char buffer_temp[10];
	//_itoa_s(line_p,buffer_temp,10,10);	//TODO: fare funzione anche per linux!
	this->Write_String("\t\tFile: ");
	this->Write_String(file_p);
	this->Write_String("\n\t\tLine: ");
	this->Write_String(buffer_temp);
	this->Write_String("\n");
#endif
}

void FileLog::Stampa_Intestazione(void){
	*this << "\n"
			 "               SUPER FOOTBALL RELOAD\n"
			 "                      by Neo333 (alias Biagio Festa)\n"
			 "                      Versione: 2.0\n\n"
			 "    REGISTRO DI SISTEMA:\n";
}
