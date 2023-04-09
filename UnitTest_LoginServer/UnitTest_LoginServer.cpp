#include "pch.h"
#include "CppUnitTest.h"
#include "CredentialsFile.h"
#include "Source.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLoginServer
{
	TEST_CLASS(UnitTestLoginServer)
	{
	public:
		
        TEST_METHOD(Test_LoginServer_Write_UnregisteredUser_On_Credentials_File)
        {
            string username = "testuser";
            string password = "testpassword";
            string filename = "credentials.txt";
            ofstream outFile(filename); // create the file before adding credentials
            outFile.close();

            addCredentials(username, password, filename);

            ifstream inFile(filename);
            string line;
            getline(inFile, line);
            Assert::AreEqual(username + ":" + password, line);
            inFile.close();
        }

        TEST_METHOD(Test_Create_Credentials_File)
        {
            string filename = "credentials.txt";
            remove(filename.c_str()); // delete the file if it already exists

            createCredentialsFile(filename);

            ifstream inFile(filename);
            Assert::IsTrue(inFile.good());
            inFile.close();

            remove(filename.c_str());
        }

        TEST_METHOD(Test_Delete_Credentials_File)
        {
            string filename = "deletecredentials.txt";
            ofstream outFile(filename); // create the file before deleting
            outFile.close();

            deleteCredentialsFile(filename);

            ifstream inFile(filename);
            Assert::IsFalse(inFile.good());
            inFile.close();
        }

        TEST_METHOD(Test_Login_Validation)
        {
            string username = "testuser";
            string password = "testpassword";
            string filename = "credentials.txt";
            addCredentials(username, password, filename);

            Assert::IsTrue(checkCredentials(username, password, filename));
            Assert::IsFalse(checkCredentials("wronguser", password, filename));
            Assert::IsFalse(checkCredentials(username, "wrongpassword", filename));

            ofstream outFile(filename);
            outFile.close();
        }

        TEST_METHOD(Test_Write_Packet_Into_LogFile)
        {
            Packet pkt;
            pkt.set_Timestamp(1649132528);
            pkt.set_Username("user", 4);
            pkt.set_Data("message", 7);

            writePacketIntoLogFile(pkt);

            ifstream inFile("log.txt");
            string line;
            getline(inFile, line);
            Assert::AreEqual(line, string("{"));
            getline(inFile, line);
            Assert::AreEqual(line, string("Tue Apr  5 00:22:08 2022"));
            getline(inFile, line);
            Assert::AreEqual(line, string("user"));
            getline(inFile, line); 
            Assert::AreEqual(line, string("message"));
            getline(inFile, line);
            Assert::AreEqual(line, string("}"));

            inFile.close();
        }
	};
}
