#include "Game Client.h"

SOCKET CreateSocket(int port) {
	//starts Winsock DLLs
	WSADATA wsaData;
	if ((WSAStartup(MAKEWORD(2, 2), &wsaData)) != 0) {
		return INVALID_SOCKET;
	}

	//initializes socket. SOCK_STREAM: TCP
	SOCKET clientSocket;
	clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (clientSocket == INVALID_SOCKET) {
		WSACleanup();
		return INVALID_SOCKET;
	}

	//Connect socket to specified server
	sockaddr_in serverAddr;
	serverAddr.sin_family = AF_INET;						//Address family type itnernet
	serverAddr.sin_port = htons(port);						//port (host to network conversion)
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");	//IP address

	if ((connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr))) == SOCKET_ERROR) {
		closesocket(clientSocket);
		WSACleanup();
		return INVALID_SOCKET;
	}

	return clientSocket;
}

void sendPackets_Client(Packet pkt, SOCKET clientSocket)
{
	//lock_guard<mutex> lock(mtx);
	pkt.set_CRC();
	pkt.set_AckFlag(true);

	auto now = std::chrono::system_clock::now();

	std::time_t time = std::chrono::system_clock::to_time_t(now);

	pkt.set_Timestamp(time);

	int size = 0;

	char* TxBuffer = pkt.serializeData(size);

	send(clientSocket, TxBuffer, size + 1, 0);
}

void exitGame(SOCKET clientSocket)
{
	Packet exit;
	exit.set_CRC();
	exit.set_FinFlag(true);

	int size = 0;

	char* TxBuffer = exit.serializeData(size);

	send(clientSocket, TxBuffer, size + 1, 0);
}

void sendUser(char* name, SOCKET clientSocket)
{
	Packet user;
	user.set_Username(name, strlen(name));
	user.set_UsernameLength(strlen(name));

	sendPackets_Client(user, clientSocket);
}

Packet receivePacket(SOCKET clientSocket)
{
	char buffer[300];
	recv(clientSocket, buffer, sizeof(buffer), 0);

	Packet pkt(buffer);

	return pkt;
}

void sendReply(char* name, char* reply, SOCKET clientSocket)
{
	Packet user;

	user.set_Username(name, strlen(name));
	user.set_UsernameLength(strlen(name));
	user.set_Data(reply, strlen(reply));
	user.set_DataLength(strlen(reply));

	sendPackets_Client(user, clientSocket);
}

bool checkJudge(char* name, Packet judge)
{
	if (strcmp(judge.get_User(), name) == 0)
	{
		return true;
	}
	else
		return false;
}

void main(void)
{

}