#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <windows.networking.sockets.h>
#include "../Client/Packet.h"
#include "Replies.h"

#include <iostream>
#include <thread>
#include <vector>
#include <random>
#include <atomic>
#include <unordered_set>
#include <chrono>

#pragma comment(lib, "Ws2_32.lib")

void connectionHandler(SOCKET clientSocket);
void clientHandler(SOCKET clientSocket, char*);
void serverHandler(SOCKET clientSocket, char*);
bool receiveAck(SOCKET clientSocket);
void sendInbox(SOCKET clientSocket);
int generateJudge(int numClients);
void sendJudge(SOCKET clientSocket);
void receivePacket(Packet& pkt, SOCKET clientSocket);
void sendPackets(Packet& pkt, SOCKET clientSocket);