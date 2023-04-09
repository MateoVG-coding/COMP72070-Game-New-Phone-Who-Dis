#include "SignupForm.h"

using namespace System;
using namespace System::Windows::Forms;

void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	SignupWF::SignupForm form;

	Application::Run(% form);
}

