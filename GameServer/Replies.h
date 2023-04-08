#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <mutex>

using namespace std;

void addReply(Packet& pkt);
bool checkFileFull(int numClients, const char* filename);
void emptyFile(const char* filename);
void deleteClient(Packet pkt);
bool readRepliesClient(Packet& pkt, int);
void readReplies(Packet& pkt);
void readInbox(Packet& pkt);
void addClient(Packet pkt);
bool checkClients(char* name, int length);
void sendInbox(SOCKET clientSocket);
void addConfirmation(char* username);