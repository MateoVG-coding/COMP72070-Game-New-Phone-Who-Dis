#include <windows.networking.sockets.h>
#pragma comment(lib, "Ws2_32.lib")
#include "Packet.h"
#include <iostream>

#define BUFF_LEN 512

using namespace std;

int main()
{
	//starts Winsock DLLs
	WSADATA wsaData;
	if ((WSAStartup(MAKEWORD(2, 2), &wsaData)) != 0) {
		return 0;
	}

	//initializes socket. SOCK_STREAM: TCP
	SOCKET ClientSocket;
	ClientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (ClientSocket == INVALID_SOCKET) {
		WSACleanup();
		return 0;
	}

	//Connect socket to specified server
	sockaddr_in SvrAddr;
	SvrAddr.sin_family = AF_INET;						//Address family type itnernet
	SvrAddr.sin_port = htons(27000);					//port (host to network conversion)
	SvrAddr.sin_addr.s_addr = inet_addr("127.0.0.1");	//IP address
	if ((connect(ClientSocket, (struct sockaddr*)&SvrAddr, sizeof(SvrAddr))) == SOCKET_ERROR) {
		closesocket(ClientSocket);
		WSACleanup();
		return 0;
	}

	bool bDone = false;
	while (!bDone) {

		// Recieving responses from the server
		char RxBuffer[BUFF_LEN];
		recv(ClientSocket, RxBuffer, sizeof(RxBuffer), 0);
		Packet RxPkt(RxBuffer);

		
		//Sending packet
		Packet TxPkt;
		int size = 0;
		char* TxBuffer = TxPkt.serializeData(size);
		
		send(ClientSocket, TxBuffer, sizeof(TxBuffer), 0);

		// Exit keywords
		if ((strcmp(TxBuffer, "EXIT") == 0) || (strcmp(TxBuffer, "exit") == 0))
			bDone = true;

		if ((strcmp(TxBuffer, "QUIT") == 0) || (strcmp(TxBuffer, "quit") == 0))
			bDone = true;


	}
	//closes connection and socket
	closesocket(ClientSocket);

	//frees Winsock DLL resources
	WSACleanup();

	return 1;
}

