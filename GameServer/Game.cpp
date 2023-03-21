#define _CRT_SECURE_NO_WARNINGS
#include <windows.networking.sockets.h>
#pragma comment(lib, "Ws2_32.lib")
#include <iostream>
using namespace std;

int main()
{
	//starts Winsock DLLs		
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		return 0;

	//create server socket
	SOCKET ServerSocket_LogInServer;
	ServerSocket_LogInServer = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (ServerSocket_LogInServer == INVALID_SOCKET) {
		WSACleanup();
		return 0;
	}

	sockaddr_in SvrAddr_LogInServer;
	SvrAddr_LogInServer.sin_family = AF_INET;
	SvrAddr_LogInServer.sin_addr.s_addr = INADDR_ANY;
	SvrAddr_LogInServer.sin_port = htons(8082);
	if (bind(ServerSocket_LogInServer, (struct sockaddr*)&SvrAddr_LogInServer, sizeof(SvrAddr_LogInServer)) == SOCKET_ERROR)
	{
		closesocket(ServerSocket_LogInServer);
		WSACleanup();
		return 0;
	}

	if (listen(ServerSocket_LogInServer, 1) == SOCKET_ERROR) {
		closesocket(ServerSocket_LogInServer);
		WSACleanup();
		return 0;
	}

	//accepts a connection from a client
	SOCKET ConnectionSocket_LogInServer;
	ConnectionSocket_LogInServer = SOCKET_ERROR;
	if ((ConnectionSocket_LogInServer = accept(ServerSocket_LogInServer, NULL, NULL)) == SOCKET_ERROR) {
		closesocket(ServerSocket_LogInServer);
		WSACleanup();
		return 0;
	}

	// create client socket to connect to remote server
	SOCKET ClientSocket_RemoteServer;
	ClientSocket_RemoteServer = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (ClientSocket_RemoteServer == INVALID_SOCKET) {
		WSACleanup();
		return 0;
	}

	sockaddr_in SvrAddr_RemoteServer;
	SvrAddr_RemoteServer.sin_family = AF_INET;
	SvrAddr_RemoteServer.sin_addr.s_addr = inet_addr("remote.server.address"); // replace with actual address of remote server
	SvrAddr_RemoteServer.sin_port = htons(1234); // replace with actual port number of remote server
	if (connect(ClientSocket_RemoteServer, (sockaddr*)&SvrAddr_RemoteServer, sizeof(SvrAddr_RemoteServer)) == SOCKET_ERROR) {
		closesocket(ClientSocket_RemoteServer);
		WSACleanup();
		return 0;
	}

	SOCKET ServerSockets[4];
	for (int i = 0; i < 4; i++) {
		ServerSockets[i] = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (ServerSockets[i] == INVALID_SOCKET) {
			WSACleanup();
			return 0;
		}

		sockaddr_in SvrAddr;
		SvrAddr.sin_family = AF_INET;
		SvrAddr.sin_addr.s_addr = INADDR_ANY;
		SvrAddr.sin_port = htons(27000 + i);
		if (bind(ServerSockets[i], (struct sockaddr*)&SvrAddr, sizeof(SvrAddr)) == SOCKET_ERROR)
		{
			closesocket(ServerSockets[i]);
			WSACleanup();
			return 0;
		}
	}

}