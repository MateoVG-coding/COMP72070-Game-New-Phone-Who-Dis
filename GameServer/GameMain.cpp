#include "GameServer.h"
atomic<int> numClients(0);

void clientHandler(SOCKET clientSocket) {

    //Function to send and recv packets from any client side.

    numClients++;

    while (true)
    {
        Packet pkt_inbox;
        pkt_inbox.set_CRC();

        readInbox(pkt_inbox);

        int size = 0;
        char* TxBuffer = pkt_inbox.serializeData(size);

        send(clientSocket, TxBuffer, size, 0);

        char RxBuffer[128];
        int bytesReceived = recv(clientSocket, RxBuffer, sizeof(RxBuffer), 0);

        if (bytesReceived > 0)
        {
            Packet Rx(RxBuffer);

            if (Rx.get_ErrFlag() == true || Rx.get_AckFlag() == false)
            {
                break;
            }

            Packet pkt_replies;
            pkt_replies.set_CRC();

            for (int i = 0; i < 7; i++)
            {
                int size_rep = 0;

                readReplies(pkt_replies);
                
                TxBuffer = pkt_replies.serializeData(size_rep);

                send(clientSocket, TxBuffer, size, 0);

                bytesReceived = recv(clientSocket, RxBuffer, sizeof(RxBuffer), 0);

                Packet RxReplies(RxBuffer);

                if (RxReplies.get_ErrFlag() == true || RxReplies.get_AckFlag() == false)
                {
                    break;
                }
            }

            bytesReceived = recv(clientSocket, RxBuffer, sizeof(RxBuffer), 0);
            Packet clientReply(RxBuffer);

            if (bytesReceived > 0)
            {
                if (clientReply.get_ErrFlag() == true || clientReply.get_AckFlag() == false)
                {
                    break;
                }

                addReply(clientReply);

                while (checkFileFull(numClients) != true)
                {
                    continue;
                }

                Packet pkt_clientReply;
                pkt_clientReply.set_CRC();

                for (int i = 0; i < numClients; i++)
                {
                    int size_clientrep = 0;
                    readRepliesClient(pkt_clientReply, i);

                    TxBuffer = pkt_clientReply.serializeData(size_clientrep);

                    send(clientSocket, TxBuffer, size_clientrep, 0);

                    bytesReceived = recv(clientSocket, RxBuffer, sizeof(RxBuffer), 0);
                    Packet client_ack(RxBuffer);

                    if (bytesReceived < 0 || client_ack.get_AckFlag() == false || client_ack.get_ErrFlag() == true)
                    {
                        break;
                    }
                }

                emptyFile();
            }
        }
    }
   
    // close client socket
    closesocket(clientSocket);

    numClients--;
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

        thread t(clientHandler, clientSocket);
        clientThreads.push_back(move(t));

    }

    for (auto& t : clientThreads) {
        t.join();
    }


    // closes server socket
    closesocket(ServerSocket);

    // frees Winsock DLL resources
    WSACleanup();
}