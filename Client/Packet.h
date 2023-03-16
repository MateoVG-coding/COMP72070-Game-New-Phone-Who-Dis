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

	Packet()
	{
		// head
		head.sourceID = 0;
		head.destinationID = 0;
		head.sequenceNumber = 0;
		head.ackFlag = false;
		head.errFlag = false;
		head.finFlag = false;
		head.bodyLength = 0;
		
		// body
		body.response = nullptr;
		body.username = nullptr;

		// tail
		crc = 0;

		pSerialBuf = nullptr;
	}

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

	char getDestination()
	{
		return head.destinationID;
	}

	char getSource()
	{
		return head.sourceID;
	}

	int getSeqNumber()
	{
		return head.sequenceNumber;
	}

	bool getAckFlag()
	{
		return head.ackFlag;
	}

	bool getFinFlag()
	{
		return head.finFlag;
	}

	bool getErrFlag()
	{
		return head.errFlag;
	}

	int getLength()
	{
		return head.bodyLength;
	}
	
	char* getUser()
	{
		return body.username;
	}

	char* getResponse()
	{
		return body.response;
	}

	int getCRC()
	{
		return crc;
	}

	char* serializeData()
	{
		int size = sizeof(head) + head.bodyLength + sizeof(crc);

		pSerialBuf = new char[size];

		memcpy(pSerialBuf, &head, sizeof(head));
		memcpy(pSerialBuf + sizeof(head), body.username, sizeof(body.username));
		memcpy(pSerialBuf + sizeof(head) + sizeof(body.username), body.response, sizeof(body.response));
		memcpy(pSerialBuf + sizeof(head) + head.bodyLength, &crc, sizeof(crc));

		return pSerialBuf;
	}

};