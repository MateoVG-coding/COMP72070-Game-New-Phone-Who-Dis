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
		unsigned int usernameLength;
		unsigned int dataLength;
	}HEAD;

	struct Body
	{
		char* username;
		char* data;
	}BODY;

	char* pSerialBuf;
	unsigned int CRC;

public:

	Packet() : pSerialBuf(nullptr) { memset(&HEAD, 0, sizeof(HEAD)); memset(&BODY, 0, sizeof(BODY)); };

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

	void set_Username(char* username)
	{
		
	}

	void set_Data(char* data)
	{

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

	char* serializeData()
	{

		return pSerialBuf;
	}

};