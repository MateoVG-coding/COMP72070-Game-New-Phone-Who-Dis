#include "Source.h"

void clientHandler(SOCKET clientSocket) {

    //Function to send and recv packets from any client side.

    char RxBuffer[128];
    int bytesReceived = recv(clientSocket, RxBuffer, sizeof(RxBuffer), 0);

    if (bytesReceived > 0) {

        Packet RxPkt(RxBuffer);

        string username(RxPkt.get_User());

        string password(RxPkt.get_Data());

        if (username.find("login") != std::string::npos)
        {
            checkCredentials(username, password, "credentials.txt");
        }
        else
        {
            addCredentials(username, password, "credentials.txt");
        }

        Packet TxPkt;
        TxPkt.set_AckFlag(true);

        int Size = 0;
        char* Tx = TxPkt.serializeData(Size);

        send(clientSocket, Tx, Size, 0);
    }

    // close client socket
    closesocket(clientSocket);
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