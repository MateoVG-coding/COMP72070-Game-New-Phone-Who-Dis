#include "GameServer.h"
#define MAX_PACKET_SIZE 1500;
atomic<int> numClients(0);
static string chosen_judge;
static string chosen_winner;
std::mutex mtx;

void connectionHandler(SOCKET clientSocket) {

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

int generateJudge(int numClients)
{
    lock_guard<mutex> lock(mtx);
    static thread_local std::mt19937 generator{ std::random_device{}() };
    static thread_local std::unordered_set<int> generatedNumbers;

    std::uniform_int_distribution<int> distribution(1, numClients);

    while (true)
    {
        int number = distribution(generator);
        if (generatedNumbers.insert(number).second)
        {
            return number;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

void serverHandler(SOCKET clientSocket, char* buffer)
{
    Packet user(buffer);
    Packet response;
    int size = 0;

    if (checkClients(user.get_User(), user.get_UsernameLength()) == true)
    {
        response.set_ErrFlag(true);
        sendPackets(response, clientSocket);
    }
    else
    {
        sendPackets(response, clientSocket);
    }

    closesocket(clientSocket);
}

void clientHandler(SOCKET clientSocket, char* buffer)
{
    numClients++;
    Packet confirmation(buffer);
    confirmation.set_SeqNumber(numClients);
    addClient(confirmation);

    while (numClients < 3)
    {
        continue;
    }

    bool continueprogram = true;

    while (continueprogram)
    {
        while (numClients < 3)
        {
            continue;
        }

        addConfirmation(confirmation.get_User());

        while (checkFileFull(numClients, "confirmations.txt") != true)
        {
            continue;
        }

        int judgeNumber = generateJudge(numClients);
        bool is_judge = false;

        if (confirmation.get_SeqNumber() == judgeNumber && chosen_judge.empty())
        {
            cout << "Judge is: " << confirmation.get_User() << endl;
            chosen_judge = confirmation.get_User();
            is_judge = true;
        }

        while (chosen_judge.empty())
        {
            continue;
        }

        sendJudge(clientSocket);

        sendInbox(clientSocket);
        
        if (receiveAck(clientSocket) == false)
            break;

        for (int i = 0; i < 4; i++)
        {
            Packet pkt_replies;

            readReplies(pkt_replies);

            sendPackets(pkt_replies, clientSocket);
           
            if (receiveAck(clientSocket) == false)
                break;
        }

        Packet clientReply;
        receivePacket(clientReply, clientSocket);

        if (clientReply.get_ErrFlag() == true || clientReply.get_AckFlag() == false)
        {
            break;
        }

        addReply(clientReply);

        while (checkFileFull(numClients, "repliesClients.txt") != true)
        {
            continue;
        }

        int pointer = 0;

        for (int i = 0; i < numClients; i++)
        {
            Packet pkt_clientReply;
            readRepliesClient(pkt_clientReply, &pointer);

            sendPackets(pkt_clientReply, clientSocket);

            if (receiveAck(clientSocket) == false)
                break;
          
        }

        if (is_judge == true)
        {
            Packet winner;
            receivePacket(winner, clientSocket);

            chosen_winner = winner.get_User();
        }

        while (chosen_winner.empty())
        {
            continue;
        }

        Packet pkt_winner;

        std::unique_ptr<char[]> usr(new char[chosen_winner.length() + 1]);

        strcpy(usr.get(), chosen_winner.c_str());
        pkt_winner.set_Username(usr.get(), strlen(usr.get()));
        pkt_winner.set_UsernameLength(strlen(usr.get()));

        sendPackets(pkt_winner, clientSocket);

        Packet decision;
        receivePacket(decision, clientSocket);

        if (decision.get_FinFlag() == true)
            continueprogram = false;

        emptyFile("confirmations.txt");
    }

    // close client socket
    closesocket(clientSocket);

    numClients--;

    deleteClient(confirmation, "confirmations.txt");
    deleteClient(confirmation, "clientsConnected.txt");
}

void sendPackets(Packet& pkt, SOCKET clientSocket)
{
    lock_guard<mutex> lock(mtx);
    pkt.set_CRC();
    pkt.set_AckFlag(true);
    int size = 0;

    char* TxBuffer(pkt.serializeData(size));

    send(clientSocket, TxBuffer, size + 1, 0);
}

void receivePacket(Packet& pkt, SOCKET clientSocket)
{
    char buffer[300];
    recv(clientSocket, buffer, sizeof(buffer), 0);

    pkt = Packet(buffer);
}

void sendJudge(SOCKET clientSocket)
{
    int size = 0;

    Packet pkt_judge;
    pkt_judge.set_CRC();

    std::unique_ptr<char[]> usr(new char[chosen_judge.length() + 1]);

    strcpy(usr.get(), chosen_judge.c_str());
    pkt_judge.set_Username(usr.get(), strlen(usr.get()));
    pkt_judge.set_UsernameLength(strlen(usr.get()));

    sendPackets(pkt_judge, clientSocket);
}

void sendInbox(SOCKET clientSocket)
{
    Packet pkt_inbox;
    pkt_inbox.set_CRC();

    readInbox(pkt_inbox);

    sendPackets(pkt_inbox, clientSocket);
}

bool receiveAck(SOCKET clientSocket)
{
    char RxBuffer[128];

    recv(clientSocket, RxBuffer, sizeof(RxBuffer), 0);

    Packet Rx(RxBuffer);

    if (Rx.get_ErrFlag() == true || Rx.get_AckFlag() == false || Rx.get_FinFlag() == true)
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