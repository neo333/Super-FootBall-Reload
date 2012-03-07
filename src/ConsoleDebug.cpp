#include "ConsoleDebug.h"
#include "Bcol.h"
#include <iostream>
#include "global.h"

void ConsoleDebug::Run(const std::string& cmd){
	ConsoleDebug obj;
	obj.DecodeCMD(cmd);
	obj.Exeque();
}

void ConsoleDebug::DecodeCMD(const std::string& cmd){
	this->ZeroCmd_Int();
	size_t cur=cmd.find(' ');
	std::string temp_param,temp_cmd;
	temp_cmd=cmd.substr(0,cur);

	if(temp_cmd=="bcol_make"){
		this->cmd_int.istruzione_int=ConsoleDebug::Cmd_Dec::MAKE_BCOL_FILE;
		cur=cmd.find(" -f",cur);
		if(cur!=cmd.npos){
			temp_param=cmd.substr(cur+3,cmd.find(' ',cur+1));
			this->cmd_int.string1=temp_param;
		}
		return;
	}

	if(temp_cmd=="bcol_vis"){
		this->cmd_int.istruzione_int=ConsoleDebug::Cmd_Dec::DEBUG_BCOL_VIS;
		return;
	}
}

void ConsoleDebug::ZeroCmd_Int(void){
	this->cmd_int.string1.clear();
	this->cmd_int.istruzione_int=ConsoleDebug::Cmd_Dec::NOT_DEFINE;
}

void ConsoleDebug::Exeque(void){
	switch(this->cmd_int.istruzione_int){
	case ConsoleDebug::Cmd_Dec::MAKE_BCOL_FILE:
		if(this->cmd_int.string1.size()==0){
			std::cout << "Parametri comando non corretti!\n";
			break;
		}
		if(Bcol::Converted_IMAGE(this->cmd_int.string1,this->cmd_int.string1+".bcol")==false){
			std::cout << "Operazione non riuscita!\n";
			break;
		}
		std::cout << "Operazione conclusa!\n";
		break;

	case ConsoleDebug::Cmd_Dec::DEBUG_BCOL_VIS:
		if(sys_data::app_main->Get_Debug_Vis_Bcol()){
			sys_data::app_main->Set_Debug_Vis_Bcol(false);
		}else{
			sys_data::app_main->Set_Debug_Vis_Bcol(true);
		}
		break;

	default:
		std::cout << "Impossibile eseguire il comando immesso!\n";
		break;
	}
}