#include <cstdlib>
#include "Applicazione.h"
#include <SDL\SDL.h>

#ifdef WIN32
#include <Windows.h>
#endif

int main(int n_param, char** l_param){
#ifdef WIN32
	SetDllDirectory("Data/bin");
#endif
	Applicazione SFR;
	SFR.Run();

#ifdef _DEBUG
#ifdef WIN32
	system("pause");
#endif
#endif
	return 0;
}