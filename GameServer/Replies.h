#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

using namespace std;

void addReply(Packet pkt);
bool checkFileFull(int);
void emptyFile();
void readFile(Packet pkt);