#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "CppUnitTest.h"
#include "../GameServer/GameServer.h"
#include "../GameServer/Replies.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTetsGameServer
{
	TEST_CLASS(UnitTetsGameServer)
	{
	public:
		
		TEST_METHOD(TestAddReply)
		{
			// Arrange
			Packet pkt;
			char user[15];
			char data[15];
			strcpy_s(user, "testUser");
			strcpy_s(data, "testData");
			pkt.set_Username(user, strlen(user));
			pkt.set_Data(data, strlen(data));
			std::ofstream outfile("repliesClients.txt");

			// Act
			addReply(pkt);

			// Assert
			std::ifstream infile("repliesClients.txt");
			std::string line;
			bool found = false;
			while (std::getline(infile, line))
			{
				if (line.find("testUser|testData") != std::string::npos)
				{
					found = true;
					break;
				}
			}
			infile.close();
			Assert::IsTrue(found);
			outfile.close();
			std::remove("repliesClients.txt");
		}

		TEST_METHOD(TestDeleteClient)
		{
			// Arrange
			Packet pkt;
			char user[15];
			strcpy_s(user, "testuser2");
			pkt.set_Username(user, strlen(user));
			std::ofstream outfile("clientsConnected.txt");
			outfile << "testuser1" << std::endl;
			outfile << "testuser2" << std::endl;
			outfile << "testuser3" << std::endl;
			outfile.close();

			// Act
			deleteClient(pkt, "clientsConnected.txt");

			// Assert
			std::ifstream infile("clientsConnected.txt");
			std::string line;
			std::vector<std::string> lines;
			while (std::getline(infile, line))
			{
				lines.push_back(line);
			}
			infile.close();
			Assert::AreEqual(std::string("testuser1"), lines[0]);
			Assert::AreEqual(std::string("testuser3"), lines[1]);
			std::remove("clientsConnected.txt");
		}

		TEST_METHOD(TestAddConfirmation)
		{
			// Arrange
			std::ofstream outfile("confirmations.txt");

			// Act
			char user[15];
			strcpy_s(user, "testUser");
			addConfirmation(user);

			// Assert
			std::ifstream infile("confirmations.txt");
			std::string line;
			bool found = false;
			while (std::getline(infile, line))
			{
				if (line.find("testUser") != std::string::npos)
				{
					found = true;
					break;
				}
			}
			infile.close();
			Assert::IsTrue(found);
			outfile.close();
			std::remove("confirmations.txt");
		}

		TEST_METHOD(TestAddClient)
		{
			// Arrange
			Packet pkt;
			char user[15];
			strcpy_s(user, "testUser");
			pkt.set_Username(user, strlen(user));
			std::ofstream outfile("clientsConnected.txt");

			// Act
			addClient(pkt);

			// Assert
			std::ifstream infile("clientsConnected.txt");
			std::string line;
			bool found = false;
			while (std::getline(infile, line))
			{
				if (line == "testUser")
				{
					found = true;
					break;
				}
			}
			infile.close();
			Assert::IsTrue(found);
			outfile.close();
			std::remove("clientsConnected.txt");
		}

		TEST_METHOD(CheckClientsTest)
		{
			std::ofstream file("clientsConnected.txt");
			file << "Alice\nBob\nCharlie\n";
			file.close();

			// Act
			bool result = checkClients("Bob", 3);

			// Assert
			Assert::IsTrue(result);
		}

		TEST_METHOD(CheckClientsTest_CheckNonExistingClient_ReturnsFalse)
		{
			// Arrange
			std::ofstream file("clientsConnected.txt");
			file << "Alice\nBob\nCharlie\n";
			file.close();

			// Act
			bool result = checkClients("Dave", 4);

			// Assert
			Assert::IsFalse(result);
		}

		TEST_METHOD(CheckFileFull_NumClientsMatchesNumLines)
		{
			// Arrange
			int numClients = 3;
			const char* filename = "testfile.txt";
			std::ofstream outfile(filename);
			outfile << "line 1\nline 2\nline 3\n";
			outfile.close();

			// Act
			bool result = checkFileFull(numClients, filename);

			// Assert
			Assert::IsTrue(result);
		}

		TEST_METHOD(EmptyFile)
		{
			const char* filename = "testfile.txt";
			std::ofstream outfile(filename);
			outfile << "line 1\nline 2\nline 3\n";
			outfile.close();

			emptyFile(filename);

			std::ifstream file(filename, std::ios::ate);
			int numLines = 0;
			string line;
			while (getline(file, line)) {
				numLines++;
			}

			file.close();
			
			Assert::AreEqual(0, numLines);
		}

		TEST_METHOD(test_readRepliesClient)
		{
			// Write to the file
			ofstream file("repliesClients.txt");
			file << "user1|reply1\n";
			file << "user2|reply2\n";
			file.close();

			// Set up Packet and pointer variables
			Packet pkt;
			int pointer = 0;

			// Call the function
			readRepliesClient(pkt, &pointer);

			// Check that the Packet was set up correctly
			Assert::AreEqual(string("user1"), string(pkt.get_User(), pkt.get_UsernameLength()));
			Assert::AreEqual(string("reply1"), string(pkt.get_Data(), pkt.get_DataLength()));

			// Call the function again to read the second line
			readRepliesClient(pkt, &pointer);

			// Check that the Packet was set up correctly for the second line
			Assert::AreEqual(string("user2"), string(pkt.get_User(), pkt.get_UsernameLength()));
			Assert::AreEqual(string("reply2"), string(pkt.get_Data(), pkt.get_DataLength()));
		}

		TEST_METHOD(ReadReplies_Test)
		{
			// Write test data to the file
			Packet testPacket;

			readReplies(testPacket);

			std::ifstream infile("Reply_Cards.txt");
			std::string line;
			bool found = false;
			while (std::getline(infile, line))
			{
				if (strcmp(line.c_str(), testPacket.get_Data()))
				{
					found = true;
					break;
				}
			}
			infile.close();
			Assert::IsTrue(found);
			infile.close();
		}

		TEST_METHOD(TestReadInbox)
		{
			// Create a test packet object
			Packet testPacket;

			readInbox(testPacket);

			std::ifstream infile("Inbox_Cards.txt");
			std::string line;
			bool found = false;
			while (std::getline(infile, line))
			{
				if (strcmp(line.c_str(), testPacket.get_Data()))
				{
					found = true;
					break;
				}
			}
			infile.close();
			Assert::IsTrue(found);
			infile.close();
		}
	};
}
