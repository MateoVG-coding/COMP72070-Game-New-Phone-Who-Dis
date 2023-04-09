#include "Source.h"

void writePacketIntoLogFile(Packet RxPkt)
{
    ofstream outFile("log.txt", ios::app);

    time_t timestamp = RxPkt.get_Timestamp();

    std::string timeStr = ctime(&timestamp);

    if (outFile.is_open())
    {
        outFile << "{" << endl;
        outFile << timeStr;
        outFile << RxPkt.get_User() << endl;
        outFile << RxPkt.get_Data() << endl;
        outFile << "}" << endl;
    }
    else
    {
        cout << "Error opening log file!" << endl;
    }
}

int sendPacketToServer(Packet TxPkt)
{
    //This function checks if the user is already connected to the game server

    // start Winsock DLLs
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        return 0;
    }

    // create client socket 
    SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (clientSocket == INVALID_SOCKET) {
        WSACleanup();
        return 0;
    }

    // connect to game server
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(27000);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        closesocket(clientSocket);
        WSACleanup();
        return 0;
    }

    int Size = 0;
    char* Tx = TxPkt.serializeData(Size);

    send(clientSocket, Tx, Size, 0);

    char RxBuffer[128];
    int bytesReceived = recv(clientSocket, RxBuffer, sizeof(RxBuffer), 0);

    if (bytesReceived > 0)
    {
        Packet RxPkt(RxBuffer);

        // close client socket
        closesocket(clientSocket);

        // free Winsock DLL resources
        WSACleanup();

        if (RxPkt.get_ErrFlag() == true) //The user is already connected to the game server
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }

    return 1;
}

void sendPacketToClient(Packet RxPkt, SOCKET clientSocket)
{
    Packet TxPkt;
    TxPkt.set_AckFlag(true);
    string username(RxPkt.get_User());
    string password(RxPkt.get_Data());

    if (username.find("login") != std::string::npos) //Check if the client wants to login or signup
    {
        Packet GameServerPkt;

        char username_LoginServer[] = "LOGIN_SERVER";

        GameServerPkt.set_Username(username_LoginServer, sizeof(username_LoginServer) / sizeof(username_LoginServer[0]));

        GameServerPkt.set_Data(RxPkt.get_User(), RxPkt.get_UsernameLength());

        if (checkCredentials(username, password, "credentials.txt") && sendPacketToServer(GameServerPkt)) //Login information is correct and the user is not already connected to the server
        {
            TxPkt.set_ErrFlag(false);
        }
        else
        {
            TxPkt.set_ErrFlag(true);
        }
    }
    else
    {
        addCredentials(username, password, "credentials.txt");
        TxPkt.set_ErrFlag(false);
    }

    int Size = 0;
    char* Tx = TxPkt.serializeData(Size);

    send(clientSocket, Tx, Size, 0);
}

void clientHandler(SOCKET clientSocket) {

    //Function to send and recv packets from any client side.

    char RxBuffer[128];
    int bytesReceived = recv(clientSocket, RxBuffer, sizeof(RxBuffer), 0);

    if (bytesReceived > 0)
    {
        Packet RxPkt(RxBuffer);

        time_t timestamp = RxPkt.get_Timestamp();
        std::tm* localTime = std::localtime(&timestamp);
        char buffer[80];
        strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", localTime);

        std::cout << "Username: " << RxPkt.get_User() << " | " << "Data: " << RxPkt.get_Data() << " | " << buffer << std::endl;

        sendPacketToClient(RxPkt, clientSocket);
    }

    cout << "A Client has disconnected..." << endl;

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
    localAddr.sin_port = htons(27001);
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

        cout << "A Client has connected.." << endl;

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