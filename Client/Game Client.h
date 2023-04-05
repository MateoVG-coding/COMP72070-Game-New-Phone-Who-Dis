#pragma
#include "Packet.h"
#include <string>

using namespace std;

void SetPacketData_LogInServer(Packet& pkt, string username, string data);

// Function to set the data for a given packet
void SetPacketData_GameServer(Packet& pkt, string username, string data);

// Function to get the data from a received packet
void GetPacketData(Packet& pkt, string username, string data);