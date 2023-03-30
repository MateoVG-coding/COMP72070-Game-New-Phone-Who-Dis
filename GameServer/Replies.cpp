#include "GameServer.h"

void addReply(Packet pkt)
{
	ofstream file("replies.txt", ios::app);

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
	ifstream file("replie.txt");

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
	ofstream file("replies.txt", ios::trunc);

	if (!file.is_open())
	{
		cout << "Error opening ""replies"" file!" << endl;
	}

	file.close();
}

void readFile(Packet pkt)
{
	ifstream file("replies.txt");

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

		return;
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
	
	pkt.set_Username(usr, strlen(usr));
	pkt.set_Data(rep, strlen(rep));
	pkt.set_UsernameLength(sizeof(usr));
	pkt.set_DataLength(sizeof(rep));

	file.close();
}