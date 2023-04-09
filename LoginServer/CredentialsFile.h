#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

using namespace std;

void addCredentials(string username, string password, string filename);
void createCredentialsFile(string filename);
void deleteCredentialsFile(string filename);
bool checkCredentials(string username, string password, string filename);