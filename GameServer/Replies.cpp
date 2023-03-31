#include "GameServer.h"

void addReply(Packet pkt)
{
	ofstream file("repliesClients.txt", ios::app);

	if (file.is_open())
	{
		file << pkt.get_User() << "|" << pkt.get_Data() << endl;
		file.close();
	}
	else
	{
		cout << "Error opening ""replies"" file!" << endl;
	}

	file.close();
}

bool checkFileFull(int numClients)
{
	ifstream file("repliesClients.txt");

	int numLines = 0;
	string line;

	if (file.is_open())
	{
		while (getline(file, line))
		{
			numLines++;
		}

		if (numLines == numClients)
		{
			return true;
		}

		file.close();
		return false;
	}
	else
	{
		cout << "Error opening ""replies"" file!" << endl;
		return true;
	}
}

void emptyFile()
{
	ofstream file("repliesClients.txt", ios::trunc);

	if (!file.is_open())
	{
		cout << "Error opening ""replies"" file!" << endl;
	}

	file.close();
}

void readRepliesClient(Packet pkt, int pointer)
{
	ifstream file("repliesClients.txt");

	file.seekg(pointer);

	if (!file.is_open())
	{
		cout << "Error opening ""replies"" file!" << endl;
		return;
	}
	if (file.eof()) {
		cout << "Reached end of file." << endl;

		Packet emptyPkt;

		pkt.set_Username(pkt.get_User(), pkt.get_UsernameLength());
		pkt.set_UsernameLength(pkt.get_UsernameLength());
		pkt.set_Data(pkt.get_Data(), pkt.get_DataLength());
		pkt.set_DataLength(pkt.get_DataLength());
	}

	string line;
	string username;
	string reply;
	size_t pos;

	char* usr = new char[username.length() + 1];
	char* rep = new char[reply.length() + 1];

	getline(file, line);
	pos = line.find("|");
	username = line.substr(0, pos);
	reply = line.substr(pos + 1);

	strcpy(usr, username.c_str());
	strcpy(rep, reply.c_str());
	
	pkt.set_Username(usr, strlen(usr));
	pkt.set_Data(rep, strlen(rep));
	pkt.set_UsernameLength(sizeof(usr));
	pkt.set_DataLength(sizeof(rep));

	delete[] usr;
	delete[] rep;

	file.close();
}

void readReplies(Packet pkt)
{
	ifstream file("Reply_Cards");

	if (!file.is_open())
	{
		cout << "Error opening ""Reply_Cards"" file!" << endl;
		return;
	}

	string line;
	string username;
	username = "reply_opt";

	int min = 1;
	int max = 94;

	random_device rd;
	mt19937 gen(rd());

	// define the distribution
	uniform_int_distribution<int> dist(min, max);

	// generate a random number
	int random_number = dist(gen);

	for (int i = 1; i != random_number; i++)
	{
		getline(file, line);
	}

	getline(file, line);

	char* usr = new char[username.length() + 1];
	char* reply = new char[line.length() + 1];
	
	strcpy(usr, username.c_str());
	strcpy(reply, line.c_str());

	pkt.set_Username(usr, strlen(usr));
	pkt.set_Data(reply, strlen(reply));
	pkt.set_DataLength(sizeof(reply));
	pkt.set_UsernameLength(sizeof(usr));

	delete[] usr;
	delete[] reply;

	file.close();
}

void readInbox(Packet pkt)
{
	ifstream file("Inbox_Cards");

	if (!file.is_open())
	{
		cout << "Error opening ""Reply_Cards"" file!" << endl;
		return;
	}

	string line;
	string username;
	username = "inbox";

	int min = 1;
	int max = 37;

	random_device rd;
	mt19937 gen(rd());

	// define the distribution
	uniform_int_distribution<int> dist(min, max);

	// generate a random number
	int random_number = dist(gen);

	for (int i = 1; i != random_number; i++)
	{
		getline(file, line);
	}

	getline(file, line);

	char* usr = new char[username.length() + 1];
	char* reply = new char[line.length() + 1];

	strcpy(usr, username.c_str());
	strcpy(reply, line.c_str());

	pkt.set_Username(usr, strlen(usr));
	pkt.set_Data(reply, strlen(reply));
	pkt.set_DataLength(sizeof(reply));
	pkt.set_UsernameLength(sizeof(usr));

	delete[] usr;
	delete[] reply;
 
	file.close();
}