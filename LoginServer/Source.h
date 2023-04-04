#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <windows.networking.sockets.h>
#include "../Client/Packet.h"
#include "CredentialsFile.h"

#include <iostream>
#include <thread>
#include <vector>

#pragma comment(lib, "Ws2_32.lib")

using namespace std;

void clientHandler(SOCKET clientSocket);
void writePacketIntoLogFile(Packet RxPkt);
int sendPacketToServer(Packet TxPkt);
void sendPacketToClient(Packet RxPkt, SOCKET clientSocket);
void clientHandler(SOCKET clientSocket);
