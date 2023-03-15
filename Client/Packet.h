#pragma once
#include <ctime>
#include <iostream>

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

	void setDestination(char value)
	{
		head.destinationID = value;
	}

	void setSource(char value)
	{
		head.sourceID = value;
	}

	void setSeqNumber(int value)
	{
		head.sequenceNumber = value;
	}

	void setAckFlag(bool value)
	{
		head.ackFlag = value;
	}

	void setFinFlag(bool value)
	{
		head.finFlag = value;
	}

	void setErrFlag(bool value)
	{
		head.errFlag = value;
	}

	void setLength(int value)
	{
		head.bodyLength = value;
	}

	void setUser(char* user)
	{
		body.username = new char[sizeof(user)];
		memcpy(body.username, user, sizeof(user));
		head.bodyLength += sizeof(user);
	}

	void setData(char* data)
	{
		body.response = new char[sizeof(data)];
		memcpy(body.response, data, sizeof(data));
		head.bodyLength += sizeof(data);
	}

	void setCRC()
	{
		
	}


};