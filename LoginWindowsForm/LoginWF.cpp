#include "LoginWF.h"

using namespace GUI;

void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	LoginForm form;
	form.clientSocket = CreateSocket(27001);
	Application::Run(% form);
}

