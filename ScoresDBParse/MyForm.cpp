#include "MyForm.h"
#include <Windows.h>

using namespace System;
using namespace System::Windows::Forms;
using namespace ScoresDBParse;

INT WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::Run(gcnew MyForm());
	return TRUE;
}
