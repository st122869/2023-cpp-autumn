#include "MyForm.h"
#include <iostream>

using namespace System;
using namespace System::Windows::Forms;


[STAThreadAttribute]
int main(array<String^>^ args)
{
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	project::MyForm form;
	Application::Run(% form);
}


