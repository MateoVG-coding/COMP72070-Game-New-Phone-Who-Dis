#include "GameServer.h"
#define MAX_PACKET_SIZE 1500;
atomic<int> numClients(0);

void connectionHandler(SOCKET clientSocket) {

    //Function to send and recv packets from any client side.

    char RxBuffer_check[300];

    recv(clientSocket, RxBuffer_check, sizeof(RxBuffer_check), 0);

    Packet connection(RxBuffer_check);

    if (strcmp(connection.get_User(), "server") == 0)
    {
        serverHandler(clientSocket, RxBuffer_check);
    }
    else
        clientHandler(clientSocket, RxBuffer_check);

}

void serverHandler(SOCKET clientSocket, char* buffer)
{
    Packet user(buffer);
    Packet response;
    int size = 0;

    if (checkClients(user.get_User(), user.get_UsernameLength()) == true)
    {
        response.set_ErrFlag(true);
        char* TxBuffer = response.serializeData(size);
        send(clientSocket, TxBuffer, size + 1, 0);
    }
    else
    {
        char* TxBuffer = response.serializeData(size);
        send(clientSocket, TxBuffer, size + 1, 0);
    }

    closesocket(clientSocket);
}

void clientHandler(SOCKET clientSocket, char* buffer)
{
    numClients++;
    Packet confirmation(buffer);
    addClient(confirmation);

    while (numClients < 3)
    {
        continue;
    }

    

    cout << confirmation.get_User();

    addConfirmation(confirmation.get_User());

    while (checkFileFull(numClients, "confirmations.txt") != true)
    {
        continue;
    }

    while (true)
    {
        sendInbox(clientSocket);
        
        if (receiveAck(clientSocket) == false)
            break;

        for (int i = 0; i < 7; i++)
        {
            Packet pkt_replies;
            pkt_replies.set_CRC();
            int size_rep = 0;

            readReplies(pkt_replies);

            char* TxBuffer_replies = pkt_replies.serializeData(size_rep);

            send(clientSocket, TxBuffer_replies, size_rep + 1, 0);

            if (receiveAck(clientSocket) == false)
                break;
        }

        char RxClientReply[300];
        recv(clientSocket, RxClientReply, sizeof(RxClientReply), 0);
        Packet clientReply(RxClientReply);

        if (clientReply.get_ErrFlag() == true || clientReply.get_AckFlag() == false)
        {
            break;
        }

        addReply(clientReply);

        while (checkFileFull(numClients, "repliesClients.txt") != true)
        {
            continue;
        }


        for (int i = 0; i < numClients; i++)
        {
            Packet pkt_clientReply;
            pkt_clientReply.set_CRC();
            int size_clientrep = 0;
            bool x = readRepliesClient(pkt_clientReply, i + 1);

            if (x == true)
            {
                char* TxBuffer_clientrep = pkt_clientReply.serializeData(size_clientrep);

                send(clientSocket, TxBuffer_clientrep, size_clientrep + 1, 0);
            }
            else
            {
                char lok[2];
                strcpy(lok, "@");
                pkt_clientReply.set_Data(lok, 2);

                char* TxBuffer_clientrep = pkt_clientReply.serializeData(size_clientrep);
                send(clientSocket, TxBuffer_clientrep, size_clientrep + 1, 0);
            }

            if (receiveAck(clientSocket) == false)
                break;
          
        }

        emptyFile("repliesClients.txt");
        emptyFile("confirmations.txt");
    }

    // close client socket
    closesocket(clientSocket);

    numClients--;

    deleteClient(confirmation);
}

void sendInbox(SOCKET clientSocket)
{
    
    Packet pkt_inbox;
    pkt_inbox.set_CRC();

    readInbox(pkt_inbox);

    int size = 0;
    char* TxBuffer = pkt_inbox.serializeData(size);

    send(clientSocket, TxBuffer, size + 1, 0);
}

bool receiveAck(SOCKET clientSocket)
{
    char RxBuffer[128];

    recv(clientSocket, RxBuffer, sizeof(RxBuffer), 0);

    Packet Rx(RxBuffer);

    if (Rx.get_ErrFlag() == true || Rx.get_AckFlag() == false)
    {
        return false;
    }
    else
        return true;
}

int main(int argc, char* argv[])
{

    // starts Winsock DLLs
    WSADATA wsaData;
    if ((WSAStartup(MAKEWORD(2, 2), &wsaData)) != 0) {
        return 0;
    }

    // create server socket
    SOCKET ServerSocket;
    ServerSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (ServerSocket == INVALID_SOCKET) {
        WSACleanup();
        return 0;
    }

    // binds socket to address
    sockaddr_in localAddr;
    localAddr.sin_family = AF_INET;
    localAddr.sin_port = htons(27000);
    localAddr.sin_addr.s_addr = INADDR_ANY;
    if (bind(ServerSocket, (struct sockaddr*)&localAddr, sizeof(localAddr)) == SOCKET_ERROR) {
        closesocket(ServerSocket);
        WSACleanup();
        return 0;
    }

    // listen for incoming connections
    if (listen(ServerSocket, SOMAXCONN) == SOCKET_ERROR) {
        closesocket(ServerSocket);
        WSACleanup();
        return 0;
    }

    vector<thread> clientThreads;

    while (true)
    {

        // accept incoming connection
        SOCKET clientSocket;
        sockaddr_in clientAddr;
        int addrLen = sizeof(clientAddr);

        clientSocket = accept(ServerSocket, (struct sockaddr*)&clientAddr, &addrLen);
        if (clientSocket == INVALID_SOCKET) {
            break;
        }

        thread t(connectionHandler, clientSocket);
        clientThreads.push_back(move(t));

    }

    for (auto& t : clientThreads) {
        t.join();
    }


    // closes server socket
    closesocket(ServerSocket);

    // frees Winsock DLL resources
    WSACleanup();

    emptyFile("clientsConnected.txt");
}