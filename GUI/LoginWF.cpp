#include "LoginWF.h"
#include <Windows.h>
using namespace Login_Form;

void Main(array<String^>^ args)
{
    LPCSTR loginServer = "..\\x64\\Debug\\LoginServer.exe";
    LPCSTR GameServer = "..\\x64\\Debug\\GameServer.exe";

    int loginServerLength = MultiByteToWideChar(CP_UTF8, 0, loginServer, -1, NULL, 0);
    int GameServerLength = MultiByteToWideChar(CP_UTF8, 0, GameServer, -1, NULL, 0);
    LPWSTR loginServerW = new WCHAR[loginServerLength];
    LPWSTR GameServerW = new WCHAR[GameServerLength];
    MultiByteToWideChar(CP_UTF8, 0, loginServer, -1, loginServerW, loginServerLength);
    MultiByteToWideChar(CP_UTF8, 0, GameServer, -1, GameServerW, GameServerLength);

    // Launch LoginServer process
    STARTUPINFO si1 = { sizeof(si1) };
    PROCESS_INFORMATION pi1;
    if (!CreateProcess(loginServerW, NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si1, &pi1))
    {
        // Error handling
        return;
    }

    // Launch GameServer process
    STARTUPINFO si2 = { sizeof(si2) };
    PROCESS_INFORMATION pi2;
    if (!CreateProcess(GameServerW, NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si2, &pi2))
    {
        // Error handling
        return;
    }

    // Launch the GUI
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    LoginForm form;
    form.clientSocket = CreateSocket(27001);
    Application::Run(% form);

    // Cleanup
    CloseHandle(pi1.hProcess);
    CloseHandle(pi1.hThread);
    delete[] loginServerW;
    delete[] GameServerW;;
}

