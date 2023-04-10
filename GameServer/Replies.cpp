#include "GameServer.h"
std::mutex file_mutex;
static string chosen_inbox;
using namespace std;

void addReply(Packet& pkt)
{
	std::lock_guard<std::mutex> lock(file_mutex);
	ofstream file("repliesClients.txt", ios::app);

	if (file.is_open())
	{
		file << pkt.get_User() << "|" << pkt.get_Data() << endl;
	}
	else
	{
		cout << "Error opening ""replies"" file!" << endl;
	}

	file.close();
}

void deleteClient(Packet pkt, const char* filename) 
{
	lock_guard<mutex> lock(file_mutex);
	vector<string> lines;
	ifstream file(filename);
	string line;
	while (getline(file, line)) {
		if (line.find(pkt.get_User()) == string::npos) {
			// This line does not contain the user we want to delete, so keep it
			lines.push_back(line);
		}
	}
	file.close();

	ofstream outfile(filename);
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
		file.close();
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

bool checkClients(char* name, int length, const char* filename)
{
	ifstream file(filename);
	if (!file.is_open()) {
		cout << "Error opening ""clientsConnected"" file!" << endl;
		return false;
	}

	string line;
	while (getline(file, line)) {
		if (line.length() == length && line.compare(0, length, name) == 0) {
			file.close();
			return true;
		}
	}

	file.close();
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
			file.close();
			return true;
		}

		file.close();
		return false;
	}
	else
	{
		cout << "Error opening file!" << endl;
		file.close();
		return true;
	}
}

void emptyFile(const char* filename)
{
	ofstream file(filename, ios::out);

	if (!file.is_open())
	{
		cout << "Error opening file!" << endl;
		return;
	}

	file.close();
}

void readRepliesClient(Packet& pkt, int* pointer)
{
	std::lock_guard<std::mutex> lock(file_mutex);

	ifstream file("repliesClients.txt");

	file.seekg(*pointer);

	if (!file.is_open())
	{
		cout << "Error opening ""replies"" file!" << endl;
		return;
	}

	if (file.eof()) {
		cout << "Reached end of file." << endl;
		return;
	}

	string line;
	string username;
	string rep;
	size_t pos;

	getline(file, line);
	pos = line.find("|");
	username = line.substr(0, pos);
	rep = line.substr(pos + 1);

	std::unique_ptr<char[]> usr(new char[username.length() + 1]);
	std::unique_ptr<char[]> reply(new char[rep.length() + 1]);

	strcpy(usr.get(), username.c_str());
	strcpy(reply.get(), rep.c_str());

	pkt.set_Username(usr.get(), strlen(usr.get()));
	pkt.set_Data(reply.get(), strlen(reply.get()));
	pkt.set_DataLength(strlen(reply.get()));
	pkt.set_UsernameLength(strlen(usr.get()));

	*pointer = file.tellg(); // Update the file stream pointer to the next line

	file.close();
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

	// create a local random number generator for each thread
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

		std::unique_ptr<char[]> usr(new char[username.length() + 1]);
		std::unique_ptr<char[]> reply(new char[line.length() + 1]);

		strcpy(usr.get(), username.c_str());
		strcpy(reply.get(), line.c_str());

		pkt.set_Username(usr.get(), strlen(usr.get()));
		pkt.set_Data(reply.get(), strlen(reply.get()));
		pkt.set_DataLength(strlen(reply.get()));
		pkt.set_UsernameLength(strlen(usr.get()));

		chosen_inbox = line;

		file.close();
	}
	else
	{
		string username = "inbox";
		std::unique_ptr<char[]> usr(new char[username.length() + 1]);
		std::unique_ptr<char[]> reply(new char[chosen_inbox.length() + 1]);

		strcpy(usr.get(), username.c_str());
		strcpy(reply.get(), chosen_inbox.c_str());

		pkt.set_Username(usr.get(), strlen(usr.get()));
		pkt.set_Data(reply.get(), strlen(reply.get()));
		pkt.set_DataLength(strlen(reply.get()));
		pkt.set_UsernameLength(strlen(usr.get()));

	}
}

bool sendImagePacket(SOCKET socket, const std::string& filename) {
	// Open image file
	std::ifstream imageFile(filename, std::ios::binary);
	if (!imageFile.is_open()) {
		std::cerr << "Error opening file " << filename << std::endl;
		return false;
	}

	// Get size of file
	imageFile.seekg(0, std::ios::end);
	size_t fileSize = imageFile.tellg();
	imageFile.seekg(0, std::ios::beg);

	// Allocate buffer for image data
	std::vector<char> buffer(fileSize);
	if (!imageFile.read(buffer.data(), fileSize)) {
		std::cerr << "Error reading file " << filename << std::endl;
		return false;
	}

	// Create packet
	Packet packet;
	packet.set_Data(buffer.data(), fileSize);
	packet.set_DataLength(fileSize);
	// Set other packet fields as needed (e.g. destination address)

	// Send packet over socket
	size_t bytesSent = send(socket, packet.get_Data(), packet.get_DataLength(), 0);
	if (bytesSent == -1) {
		std::cerr << "Error sending packet" << std::endl;
		return false;
	}
	else if (static_cast<size_t>(bytesSent) != fileSize) {
		std::cerr << "Sent " << bytesSent << " bytes, but expected to send " << fileSize << " bytes" << std::endl;
		return false;
	}

	return true;
}
