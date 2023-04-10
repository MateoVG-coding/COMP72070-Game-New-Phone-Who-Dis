#include "LoginForm.h"

using namespace System;
using namespace System::Windows::Forms;

void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	LoginWF::LoginForm form;
	form.clientSocket = CreateSocket(27001);

	try
	{
		Application::Run(% form);
	}
	catch (System::IO::FileNotFoundException^ excep)
	{
		MessageBox::Show("Missing file is: " + excep->FileName);
	}
}

