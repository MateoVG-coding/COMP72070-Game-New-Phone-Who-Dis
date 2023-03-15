#pragma once
#include <ctime>

class Packet {

private:
	struct Header
	{
		char sourceID;
		char destinationID;
		unsigned int sequenceNumber;
		time_t timestamp;
		bool ackFlag : 1;
		bool errFlag : 1;
		bool finFlag : 1;
		unsigned int bodyLength;
	}head;

	struct Body
	{
		char* username;
		char* response;
	}body;

	char* pSerialBuf;
	unsigned int crc;

public:


};