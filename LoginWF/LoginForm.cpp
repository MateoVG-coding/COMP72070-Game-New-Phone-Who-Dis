#include "LoginForm.h"
#include "SignupForm.h"
#include "ChatForm.h"
#include "JudgeForm.h"

using namespace System;
using namespace System::Windows::Forms;

void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	LoginWF::LoginForm form;
	Application::Run(% form);
}

