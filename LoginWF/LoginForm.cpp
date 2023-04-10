#include "LoginForm.h"

using namespace System;
using namespace System::Windows::Forms;

void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	LoginWF::LoginForm form;
	form.clientSocket = CreateSocket(27001);
	Application::Run(% form);
}

