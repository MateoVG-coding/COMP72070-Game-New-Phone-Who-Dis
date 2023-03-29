#include "CredentialsFile.h"

void addCredentials(string username, string password, string filename) {
    
    ofstream outFile(filename, ios::app); 

    if (outFile.is_open()) 
    {
        outFile << username << ":" << password << endl;
        outFile.close();
    }
    else 
    {
        cout << "Error opening credentials file!" << endl;
    }
}

void createCredentialsFile(string filename) 
{  
    ifstream file(filename);

    if (file.good()) // check if the file already exists
    {
        cout << "Credentials file already exists" << endl;
        file.close();
        return;
    }
    
    file.close();

    ofstream outFile(filename); // create the file if doesn't exist
    if (outFile.is_open()) 
    {
        cout << "Credentials file created" << endl;
        outFile.close(); 
    }
    else 
    {
        cout << "Error creating credentials file!" << endl;
    }
}

void deleteCredentialsFile(string filename) 
{
    int result = remove(filename.c_str());

    if (result == 0) {
        cout << "Credentials file deleted" << endl;
    }
    else {
        cout << "Error deleting credentials file!" << endl;
    }
}

bool checkCredentials(string username, string password, string filename) 
{
    ifstream inFile(filename);

    string line;

    while (getline(inFile, line)) 
    { 
        size_t pos = line.find(":"); 
        string fileUsername = line.substr(0, pos); 
        string filePassword = line.substr(pos + 1);

        if (username == fileUsername && password == filePassword) //check for username and password
        { 
            inFile.close(); 
            return true; 
        }
    }

    inFile.close(); 

    return false; 
}
bool checkCredentials(string username, string password, string filename) 
{
    ifstream inFile(filename);

    string line;

    while (getline(inFile, line)) 
    { 
        size_t pos = line.find(":"); 
        string fileUsername = line.substr(0, pos); 
        string filePassword = line.substr(pos + 1);

        if (username == fileUsername && password == filePassword) //check for username and password
        { 
            inFile.close(); 
            return true; 
        }
    }

    inFile.close(); 

    return false; 
}