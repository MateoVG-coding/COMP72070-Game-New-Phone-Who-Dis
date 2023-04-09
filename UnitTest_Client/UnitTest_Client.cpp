#include "pch.h"
#include "CppUnitTest.h"
#include "../Client/Packet.h"
#include <Game Client.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestClient
{
    TEST_CLASS(UnitTestClient)
    {
    public:
        TEST_METHOD(SetPacketData_LogInServerTest)
        {
            // create a Packet object to hold the data
            Packet pkt;

            // set the input values for the function
            std::string username = "test";
            std::string data = "example data";

            // call the function we want to test
            SetPacketData_LogInServer(pkt, username, data);

            // check that the header data was set correctly
            Assert::AreEqual(pkt.get_Source(), '\0');
            Assert::AreEqual(pkt.get_Destination(), '\0');
            Assert::AreEqual(pkt.get_SeqNumber(), 1234);
            Assert::IsFalse(pkt.get_AckFlag());
            Assert::IsFalse(pkt.get_ErrFlag());
            Assert::IsFalse(pkt.get_FinFlag());
            Assert::AreEqual(pkt.get_UsernameLength(), 9); // expected length of "testlogin"
           /* Assert::AreEqual(pkt.get_DataLength(), data.size());*/
            Assert::AreEqual(static_cast<int>(pkt.get_DataLength()), static_cast<int>(data.size()));


            // check that the body data was set correctly
            /*Assert::AreEqual(std::string(pkt.get_User()), "testlogin");*/
            Assert::AreEqual(pkt.get_User(), "testlogin");
            Assert::AreEqual(std::string(pkt.get_Data()), data);
        }

        TEST_METHOD(SetPacketData_GameServerTest)
        {
            // create a Packet object to hold the data
            Packet pkt1;

            // set the input values for the function
            std::string username = "testuser";
            std::string data = "example data";

            // call the function we want to test
            SetPacketData_GameServer(pkt1, username, data);

            // check that the header data was set correctly
            Assert::AreEqual(pkt1.get_Source(), '\0');
            Assert::AreEqual(pkt1.get_Destination(), '\0');
            Assert::AreEqual(pkt1.get_SeqNumber(), 1234);
            Assert::IsFalse(pkt1.get_AckFlag());
            Assert::IsFalse(pkt1.get_ErrFlag());
            Assert::IsFalse(pkt1.get_FinFlag());
            Assert::AreEqual(pkt1.get_UsernameLength(), 8); // expected length of "testuser"
            /* Assert::AreEqual(pkt.get_DataLength(), data.size());*/
            Assert::AreEqual(static_cast<int>(pkt1.get_DataLength()), static_cast<int>(data.size()));


            // check that the body data was set correctly
            /*Assert::AreEqual(std::string(pkt.get_User()), "testlogin");*/
            Assert::AreEqual(pkt1.get_User(), "testuser");
            Assert::AreEqual(std::string(pkt1.get_Data()), data);
        }

        TEST_METHOD(GetPacketDataTest)
        {
            // create a Packet object and populate its header and body data
            Packet pkt;
            pkt.set_Source('A');
            pkt.set_Destination('B');
            pkt.set_SeqNumber(5678);
            pkt.set_AckFlag(true);
            pkt.set_ErrFlag(false);
            pkt.set_FinFlag(false);
            pkt.set_Username("testuser", 8);
            pkt.set_Data("example data", 12);

            // call the function we want to test
            std::string username;
            std::string data;
            GetPacketData(pkt, username, data);

            // check that the output values match the input values
            Assert::AreEqual('A', pkt.get_Source());
            Assert::AreEqual('B', pkt.get_Destination());
            Assert::AreEqual(5678, pkt.get_SeqNumber());
            Assert::IsTrue(pkt.get_AckFlag());
            Assert::IsFalse(pkt.get_ErrFlag());
            Assert::IsFalse(pkt.get_FinFlag());
            Assert::AreEqual("testuser", pkt.get_User());
            Assert::AreEqual("example data", pkt.get_Data());
        }

    };

};
