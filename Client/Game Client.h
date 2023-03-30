#pragma
#include "Packet.h"
#include <string>

// Function to set the data for a given packet
void SetPacketData(Packet& pkt, std::string username, std::string data);

// Function to get the data from a received packet
void GetPacketData(Packet& pkt, std::string username, std::string data);