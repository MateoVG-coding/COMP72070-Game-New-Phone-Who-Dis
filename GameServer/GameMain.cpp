#include "GameServer.h"
#define MAX_PACKET_SIZE 1500;
atomic<int> numClients(0);
static string chosen_judge;
static string chosen_winner;
static bool is_judge;
std::mutex mtx;

void connectionHandler(SOCKET clientSocket) {

    char RxBuffer_check[300];

    recv(clientSocket, RxBuffer_check, sizeof(RxBuffer_check), 0);

    Packet connection(RxBuffer_check);

    if (strcmp(connection.get_User(), "LOGIN_SERVER") == 0)
    {
        if (serverHandler(clientSocket, RxBuffer_check) == false)
        {
            Packet user(RxBuffer_check);
            char empty[2];
            strcpy(empty, "");

            user.set_Username(user.get_Data(), user.get_DataLength());
            user.set_UsernameLength(user.get_DataLength());
            user.set_Data(empty, strlen(empty));
            user.set_DataLength(strlen(empty));
            addClient(user);
        }
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

bool serverHandler(SOCKET clientSocket, char* buffer)
{
    Packet user(buffer);
    Packet response;
    int size = 0;

    if (checkClients(user.get_Data(), user.get_DataLength()) == true)
    {
        response.set_ErrFlag(true);
        sendPackets(response, clientSocket);
    }
    else
    {
        sendPackets(response, clientSocket);
    }

    closesocket(clientSocket);

    return response.get_ErrFlag();
}

void handleConfirmation(SOCKET clientSocket)
{
    Packet confirmation;
    receivePacket(confirmation, clientSocket);

    addConfirmation(confirmation.get_User());

    while (checkFileFull(numClients, "confirmations.txt") != true)
    {
        continue;
    }
}

void handleJudge(SOCKET clientSocket, Packet user)
{
    int judgeNumber = generateJudge(numClients);
    is_judge = false;

    if (user.get_SeqNumber() == judgeNumber && chosen_judge.empty())
    {
        cout << "Judge is: " << user.get_User() << endl;
        chosen_judge = user.get_User();
        is_judge = true;
    }

    while (chosen_judge.empty())
    {
        continue;
    }

    sendJudge(clientSocket);
}

void handleReplies(SOCKET clientSocket)
{
    Packet pkt_replies;

    readReplies(pkt_replies);

    sendPackets(pkt_replies, clientSocket);
}

void handleClientReply(SOCKET clientSocket)
{
    Packet clientReply;
    receivePacket(clientReply, clientSocket);
    addReply(clientReply);

    while (checkFileFull(numClients, "repliesClients.txt") != true)
    {
        continue;
    }
}

void handleReadClientReply(SOCKET clientSocket)
{
    int pointer = 0;

    for (int i = 0; i < numClients; i++)
    {
        Packet pkt_clientReply;
        readRepliesClient(pkt_clientReply, &pointer);

        sendPackets(pkt_clientReply, clientSocket);
    }
}

void handleIsJudge(SOCKET clientSocket, Packet user)
{
    if (is_judge == true)
    {
        Packet winner;
        receivePacket(winner, clientSocket);

        chosen_winner = winner.get_Data();
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

    if (strcmp(chosen_winner.c_str(), user.get_User()) == 0)
    {
        sendImagePacket(clientSocket, "winner_image.png");
    }
}

void clientHandler(SOCKET clientSocket, char* buffer)
{
    numClients++;

    Packet user(buffer);
    user.set_SeqNumber(numClients);

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

        Packet pkt;
        receivePacket(pkt, clientSocket);
        
        // read and send inbox
        if (strcmp(pkt.get_Data(), "inbox"))
        {
            sendInbox(clientSocket);
        }
        // generetae a judge
        else if (strcmp(pkt.get_Data(), "choose_judge"))
        {
            handleJudge(clientSocket, user);
        }
        // receive the reply chosen from a client
        else if (strcmp(pkt.get_Data(), "write_reply"))
        {
            handleClientReply(clientSocket);
        }
        // read all replies from clients
        else if (strcmp(pkt.get_Data(), "read_reply"))
        {
            handleReadClientReply(clientSocket);
        }
        // read and send a repliy to clients
        else if (strcmp(pkt.get_Data(), "reply"))
        {
            handleReplies(clientSocket);
        }
        // receive and store confirmation from user
        else if (strcmp(pkt.get_Data(), "confirmation"))
        {
            handleConfirmation(clientSocket);
        }
        // Judge chooses a winner and winner is sent to other clients
        else if (strcmp(pkt.get_Data(), "winner"))
        {
            handleIsJudge(clientSocket, user);
        }
        else if (pkt.get_FinFlag() == true)
        {
            continueprogram = false;
            break;
        }
        
        emptyFile("confirmations.txt");
    }

    // close client socket
    closesocket(clientSocket);

    numClients--;

    deleteClient(user, "clientsConnected.txt");
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

    time_t timestamp = pkt.get_Timestamp();
    std::tm* localTime = std::localtime(&timestamp);
    char buffer2[80];
    strftime(buffer2, 80, "%Y-%m-%d %H:%M:%S", localTime);

    std::cout << "Username: " << pkt.get_User() << " | " << "Data: " << pkt.get_Data() << " | " << buffer2 << std::endl;
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

int main()
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