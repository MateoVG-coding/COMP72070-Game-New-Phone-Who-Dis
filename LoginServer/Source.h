#pragma once

#include <windows.networking.sockets.h>
#include "../Client/Packet.h"
#include "CredentialsFile.h"

#include <iostream>
#include <thread>
#include <vector>

#pragma comment(lib, "Ws2_32.lib")

using namespace std;

void clientHandler(SOCKET clientSocket);
