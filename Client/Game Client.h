#pragma

#include <windows.networking.sockets.h>
#pragma comment(lib, "Ws2_32.lib")
#include "Packet.h"
#include <iostream>
#include <string>
#include <chrono>
#include <fstream>
#include <sstream>


void sendPackets_Client(Packet pkt, SOCKET clientSocket);
void exitGame(SOCKET clientSocket);
void sendUser(char* name, SOCKET clientSocket);
Packet receivePacket(SOCKET clientSocket);
void sendReply(char* name, char* reply, SOCKET clientSocket);
bool checkJudge(char* name, Packet judge);
SOCKET CreateSocket(int port);

void SetPacketData_LogInServer(Packet& pkt, std::string username, std::string data);

// Function to set the data for a given packet
void SetPacketData_GameServer(Packet& pkt, std::string username, std::string data);

// Function to get the data from a received packet
void GetPacketData(Packet& pkt, std::string username, std::string data);