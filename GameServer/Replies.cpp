#include "GameServer.h"
std::mutex file_mutex;
static string chosen_inbox;

void addReply(Packet& pkt)
{
	std::lock_guard<std::mutex> lock(file_mutex);
	ofstream file("repliesClients.txt", ios::app);

	if (file.is_open())
	{
		file << "/" <<pkt.get_User() << "|" << pkt.get_Data() << endl;
	}
	else
	{
		cout << "Error opening ""replies"" file!" << endl;
	}

	file.close();
}

void deleteClient(Packet pkt) 
{
	lock_guard<mutex> lock(file_mutex);
	vector<string> lines;
	ifstream file("clientsConnected.txt");
	string line;
	while (getline(file, line)) {
		if (line.find(pkt.get_User()) == string::npos) {
			// This line does not contain the user we want to delete, so keep it
			lines.push_back(line);
		}
	}
	file.close();

	ofstream outfile("clientsConnected.txt");
	for (const auto& l : lines) {
		outfile << l << std::endl;
	}
	outfile.close();
}

void addConfirmation(char* username)
{
	std::lock_guard<std::mutex> lock(file_mutex);

	std::ofstream file("confirmations.txt", std::ios::app);

	if (!file.is_open())
	{
		std::cout << "Error opening file!" << std::endl;
		return;
	}

	file << username << std::endl;

	file.close();
}

void addClient(Packet pkt)
{
	std::lock_guard<std::mutex> lock(file_mutex);
	ofstream file("clientsConnected.txt", ios::app);

	if (!file.is_open())
	{
		cout << "Error opening ""cleintsConnected"" file!" << endl;
		file.close();
		return;
	}

	file << pkt.get_User() << endl;

	file.close();
}

bool checkClients(char* name, int length)
{
	ifstream file("clientsConnected.txt");

	if (!file.is_open())
	{
		cout << "Error opening ""cleintsConnected"" file!" << endl;
		file.close();
		return false;
	}

	string line;

	while (!file.eof())
	{
		getline(file, line);

		char* usr = new char[length + 1];

		if (strcmp(usr, name) == 0)
		{
			return true;
		}
		else
			continue;
	}

	return false;
}

bool checkFileFull(int numClients, const char* filename)
{
	ifstream file(filename);

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
		cout << "Error opening file!" << endl;
		return true;
	}
}

void emptyFile(const char* filename)
{
	ofstream file(filename, ios::trunc);

	if (!file.is_open())
	{
		cout << "Error opening file!" << endl;
	}

	file.close();
}

bool readRepliesClient(Packet& pkt, int pointer)
{
	static std::mutex file_mutex;  

	std::lock_guard<std::mutex> lock(file_mutex);

	ifstream file("repliesClients.txt");

	file.seekg(pointer);

	if (!file.is_open())
	{
		cout << "Error opening ""replies"" file!" << endl;
		return false;
	}
	if (file.eof()) {
		cout << "Reached end of file." << endl;

		return false;
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
	pkt.set_UsernameLength(strlen(usr));
	pkt.set_DataLength(strlen(rep));

	file.close();

	return true;
}

void readReplies(Packet& pkt)
{
	lock_guard<mutex> lock(file_mutex);

	ifstream file("Reply_Cards.txt");

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

	std::unique_ptr<char[]> usr(new char[username.length() + 1]);
	std::unique_ptr<char[]> reply(new char[line.length() + 1]);

	strcpy(usr.get(), username.c_str());
	strcpy(reply.get(), line.c_str());

	pkt.set_Username(usr.get(), strlen(usr.get()));
	pkt.set_Data(reply.get(), strlen(reply.get()));
	pkt.set_DataLength(strlen(reply.get()));
	pkt.set_UsernameLength(strlen(usr.get()));

	file.close();
}

void readInbox(Packet& pkt)
{
	lock_guard<mutex> lock(file_mutex);

	if (chosen_inbox.empty())
	{
		ifstream file("Inbox_Cards.txt");

		if (!file.is_open())
		{
			cout << "Error opening ""Inbox_Cards"" file!" << endl;
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
		pkt.set_DataLength(strlen(reply));
		pkt.set_UsernameLength(strlen(usr));

		chosen_inbox = line;

		file.close();
	}
	else
	{
		string username = "inbox";
		char* reply = new char[chosen_inbox.length() + 1];
		char* usr = new char[username.length() + 1];

		strcpy(usr, username.c_str());
		strcpy(reply, chosen_inbox.c_str());

		pkt.set_Username(usr, strlen(usr));
		pkt.set_Data(reply, strlen(reply));
		pkt.set_DataLength(strlen(reply));
		pkt.set_UsernameLength(strlen(usr));

	}
}