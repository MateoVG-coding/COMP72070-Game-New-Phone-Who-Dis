#pragma

#include "Game Client.h"
#include "Packet.h"


using namespace std;

// Function to set the data for a given packet
void SetPacketData(Packet& pkt, std::string username, std::string data)
{
    //To be changed
   const char* source = "127.0.0.1";
    const char* dst = "Server";
    int seqNum = 1234;

    bool ackFlag = false;
    bool errFlag = false;
    bool finFlag = false;

    int usrLen = username.size();
    int datLen = data.size();

    // Set the header data
    pkt.set_Source(source[0]);
    pkt.set_Destination(dst[0]);
    pkt.set_SeqNumber(seqNum);
    pkt.set_AckFlag(&ackFlag);
    pkt.set_ErrFlag(&errFlag);
    pkt.set_FinFlag(&finFlag);
    pkt.set_UsernameLength(usrLen);
    pkt.set_DataLength(datLen);

    // Set the body data
    pkt.set_Username(const_cast<char*>(username.c_str()), usrLen); //create a non-constant char* pointer from the const char* pointer using a typecast
    pkt.set_Data(const_cast<char*>(data.c_str()), datLen);

}

// Function to get the data from a received packet
void GetPacketData(Packet& pkt, std::string username, std::string data)
{
    // Get the header data
    char sourceID = pkt.get_Source();
    char destinationID = pkt.get_Destination();
    unsigned int sequenceNumber = pkt.get_SeqNumber();
    bool ackFlag = pkt.get_AckFlag();
    bool errFlag = pkt.get_ErrFlag();
    bool finFlag = pkt.get_FinFlag();
    unsigned int usernameLength = pkt.get_UsernameLength();
    unsigned int dataLength = pkt.get_DataLength();

    // Get the body data
    username = (pkt.get_User(), usernameLength);
    data = (pkt.get_Data(), dataLength);
}
