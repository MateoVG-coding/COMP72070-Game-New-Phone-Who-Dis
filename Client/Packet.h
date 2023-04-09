#pragma once
#include <ctime>
#include <iostream>

const int EmptyPktSize = 31;  // Number of bytes in a packet with no data field

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
		unsigned int usernameLength;
		unsigned int dataLength;
	}HEAD;

	struct Body
	{
		char* username;
		char* data;
	}BODY;

	unsigned int CRC;


	char* pSerialBuf;

public:

	Packet() : pSerialBuf(nullptr) { memset(&HEAD, 0, sizeof(HEAD)); memset(&BODY, 0, sizeof(BODY)); };

	Packet(char* src)
	{
		memcpy(&HEAD, src, sizeof(Header));

		//Username

		int usernameSize = HEAD.usernameLength;

		BODY.username = new char[usernameSize + 1];

		BODY.username[usernameSize] = '\0';

		//Data

		int dataSize = HEAD.dataLength;

		BODY.data = new char[dataSize + 1];

		BODY.data[dataSize] = '\0';

		memcpy(BODY.username, src + sizeof(Header), usernameSize);

		memcpy(BODY.data, src + sizeof(Header) + usernameSize, dataSize);

		int bodySize = usernameSize + dataSize;

		memcpy(&CRC, src + sizeof(Header) + bodySize, sizeof(unsigned int));
	}

	void set_Destination(char value)
	{
		HEAD.destinationID = value;
	}

	void set_Source(char value)
	{
		HEAD.sourceID = value;
	}

	void set_SeqNumber(int value)
	{
		HEAD.sequenceNumber = value;
	}

	void set_Timestamp(time_t time)
	{
		HEAD.timestamp = time;
	}

	void set_AckFlag(bool value)
	{
		HEAD.ackFlag = value;
	}

	void set_FinFlag(bool value)
	{
		HEAD.finFlag = value;
	}

	void set_ErrFlag(bool value)
	{
		HEAD.errFlag = value;
	}

	void set_UsernameLength(int value)
	{
		HEAD.usernameLength = value;
	}

	void set_DataLength(int value)
	{
		HEAD.dataLength = value;
	}

	void set_Username(char* username, int size)
	{
		if (BODY.username)
			delete[] BODY.username;

		HEAD.usernameLength = size;

		BODY.username = new char[size + 1];

		BODY.username[size] = '\0';

		memcpy(BODY.username, username, size);
	}

	void set_Data(char* data, int size)
	{
		if (BODY.data)
			delete[] BODY.data;

		HEAD.dataLength = size;

		BODY.data = new char[size + 1];

		BODY.data[size] = '\0';

		memcpy(BODY.data, data, size);
	}

	void set_CRC()
	{
		CRC = 0xF500FF75;
	}

	char get_Destination()
	{
		return HEAD.destinationID;
	}

	char get_Source()
	{
		return HEAD.sourceID;
	}

	int get_SeqNumber()
	{
		return HEAD.sequenceNumber;
	}

	time_t get_Timestamp()
	{
		return HEAD.timestamp;
	}

	bool get_AckFlag()
	{
		return HEAD.ackFlag;
	}

	bool get_FinFlag()
	{
		return HEAD.finFlag;
	}

	bool get_ErrFlag()
	{
		return HEAD.errFlag;
	}

	int get_UsernameLength()
	{
		return HEAD.usernameLength;
	}

	int get_DataLength()
	{
		return HEAD.dataLength;
	}

	char* get_User()
	{
		return BODY.username;
	}

	char* get_Data()
	{
		return BODY.data;
	}

	int get_CRC()
	{
		return CRC;
	}

	char* serializeData(int& TotalSize)
	{
		if (pSerialBuf)
		{
			delete[] pSerialBuf;
		}

		TotalSize = EmptyPktSize + HEAD.dataLength + HEAD.usernameLength;

		pSerialBuf = new char[TotalSize];

		memcpy(pSerialBuf, &HEAD, sizeof(HEAD));

		memcpy(pSerialBuf + sizeof(HEAD), BODY.username, HEAD.usernameLength);

		memcpy(pSerialBuf + sizeof(HEAD) + HEAD.usernameLength, BODY.data, HEAD.dataLength);

		memcpy(pSerialBuf + sizeof(HEAD) + HEAD.usernameLength + HEAD.dataLength, &CRC, sizeof(CRC));

		return pSerialBuf;
	}

};