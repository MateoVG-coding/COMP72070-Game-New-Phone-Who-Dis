#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <mutex>

//using namespace std;

void addReply(Packet& pkt);
bool checkFileFull(int numClients, const char* filename);
void emptyFile(const char* filename);
void deleteClient(Packet pkt, const char*);
void readRepliesClient(Packet& pkt, int*);
void readReplies(Packet& pkt);
void readInbox(Packet& pkt);
void addClient(Packet pkt);
bool checkClients(char* name, int length, const char*);
void sendInbox(SOCKET clientSocket);
void addConfirmation(char* username); 
bool sendImagePacket(SOCKET socket, const std::string& filename);