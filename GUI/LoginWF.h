#pragma once
#include "Game Client.h"

#include <msclr\marshal.h>
#include <msclr\marshal_cppstd.h>

#include "SignupWF.h"

namespace GUI{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for LoginForm
	/// </summary>
	public ref class LoginForm : public System::Windows::Forms::Form
	{
	public:

		SOCKET clientSocket;
		String^ username;

		LoginForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::SplitContainer^ splitContainer1;
	private: System::Windows::Forms::PictureBox^ logo;
	private: System::Windows::Forms::Label^ welcome_Label;
	private: System::Windows::Forms::TextBox^ textBox_Username;
	private: System::Windows::Forms::Label^ label_username;
	private: System::Windows::Forms::TextBox^ textBox_password;
	private: System::Windows::Forms::Label^ label_Password;
	private: System::Windows::Forms::LinkLabel^ linkLabel_Signup;

	private: System::Windows::Forms::Button^ button_Login;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LoginForm::typeid));
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->logo = (gcnew System::Windows::Forms::PictureBox());
			this->linkLabel_Signup = (gcnew System::Windows::Forms::LinkLabel());
			this->button_Login = (gcnew System::Windows::Forms::Button());
			this->textBox_password = (gcnew System::Windows::Forms::TextBox());
			this->label_Password = (gcnew System::Windows::Forms::Label());
			this->textBox_Username = (gcnew System::Windows::Forms::TextBox());
			this->label_username = (gcnew System::Windows::Forms::Label());
			this->welcome_Label = (gcnew System::Windows::Forms::Label());
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->SuspendLayout();
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->Location = System::Drawing::Point(0, 0);
			this->splitContainer1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->BackgroundImage = Image::FromFile("../Resources/background_login.jpg");
			this->splitContainer1->Panel1->Controls->Add(this->logo);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->linkLabel_Signup);
			this->splitContainer1->Panel2->Controls->Add(this->button_Login);
			this->splitContainer1->Panel2->Controls->Add(this->textBox_password);
			this->splitContainer1->Panel2->Controls->Add(this->label_Password);
			this->splitContainer1->Panel2->Controls->Add(this->textBox_Username);
			this->splitContainer1->Panel2->Controls->Add(this->label_username);
			this->splitContainer1->Panel2->Controls->Add(this->welcome_Label);
			this->splitContainer1->Size = System::Drawing::Size(1382, 703);
			this->splitContainer1->SplitterDistance = 534;
			this->splitContainer1->SplitterWidth = 5;
			this->splitContainer1->TabIndex = 0;
			// 
			// logo
			// 
			this->logo->BackColor = System::Drawing::Color::Transparent;
			this->logo->Image = Image::FromFile("../Resources/logo.png");
			this->logo->Location = System::Drawing::Point(1, 118);
			this->logo->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->logo->Name = L"logo";
			this->logo->Size = System::Drawing::Size(531, 460);
			this->logo->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->logo->TabIndex = 0;
			this->logo->TabStop = false;
			// 
			// linkLabel_Signup
			// 
			this->linkLabel_Signup->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->linkLabel_Signup->Font = (gcnew System::Drawing::Font(L"Courier New", 15));
			this->linkLabel_Signup->LinkColor = System::Drawing::Color::Black;
			this->linkLabel_Signup->Location = System::Drawing::Point(274, 643);
			this->linkLabel_Signup->Name = L"linkLabel_Signup";
			this->linkLabel_Signup->Size = System::Drawing::Size(343, 29);
			this->linkLabel_Signup->TabIndex = 6;
			this->linkLabel_Signup->TabStop = true;
			this->linkLabel_Signup->Text = L"Don\'t have an account\?";
			this->linkLabel_Signup->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->linkLabel_Signup->VisitedLinkColor = System::Drawing::Color::Black;
			this->linkLabel_Signup->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &LoginForm::linkLabel_Signup_LinkClicked);
			// 
			// button_Login
			// 
			this->button_Login->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button_Login->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(108)),static_cast<System::Int32>(static_cast<System::Byte>(148)));
			this->button_Login->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_Login->Font = (gcnew System::Drawing::Font(L"Courier New", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,static_cast<System::Byte>(0)));
			this->button_Login->ForeColor = System::Drawing::Color::White;
			this->button_Login->Location = System::Drawing::Point(338, 547);
			this->button_Login->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button_Login->Name = L"button_Login";
			this->button_Login->Size = System::Drawing::Size(210, 67);
			this->button_Login->TabIndex = 5;
			this->button_Login->Text = L"LOGIN";
			this->button_Login->UseVisualStyleBackColor = false;
			this->button_Login->Click += gcnew System::EventHandler(this, &LoginForm::button_Login_Click);
			// 
			// textBox_password
			// 
			this->textBox_password->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox_password->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->textBox_password->Location = System::Drawing::Point(52, 328);
			this->textBox_password->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox_password->Name = L"textBox_password";
			this->textBox_password->Size = System::Drawing::Size(738, 34);
			this->textBox_password->TabIndex = 4;
			this->textBox_password->UseSystemPasswordChar = true;
			// 
			// label_Password
			// 
			this->label_Password->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label_Password->AutoSize = true;
			this->label_Password->Cursor = System::Windows::Forms::Cursors::Default;
			this->label_Password->Font = (gcnew System::Drawing::Font(L"Courier New", 18));
			this->label_Password->Location = System::Drawing::Point(45, 266);
			this->label_Password->Name = L"label_Password";
			this->label_Password->Size = System::Drawing::Size(159, 33);
			this->label_Password->TabIndex = 3;
			this->label_Password->Text = L"Password";
			// 
			// textBox_Username
			// 
			this->textBox_Username->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox_Username->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->textBox_Username->Location = System::Drawing::Point(52, 203);
			this->textBox_Username->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox_Username->Name = L"textBox_Username";
			this->textBox_Username->Size = System::Drawing::Size(738, 34);
			this->textBox_Username->TabIndex = 2;
			// 
			// label_username
			// 
			this->label_username->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label_username->AutoSize = true;
			this->label_username->Font = (gcnew System::Drawing::Font(L"Courier New", 18));
			this->label_username->Location = System::Drawing::Point(45, 141);
			this->label_username->Name = L"label_username";
			this->label_username->Size = System::Drawing::Size(159, 33);
			this->label_username->TabIndex = 1;
			this->label_username->Text = L"Username";
			// 
			// welcome_Label
			// 
			this->welcome_Label->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->welcome_Label->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->welcome_Label->Font = (gcnew System::Drawing::Font(L"Courier New", 35));
			this->welcome_Label->Location = System::Drawing::Point(278, 26);
			this->welcome_Label->Name = L"welcome_Label";
			this->welcome_Label->Size = System::Drawing::Size(281, 89);
			this->welcome_Label->TabIndex = 0;
			this->welcome_Label->Text = L"WELCOME";
			this->welcome_Label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// LoginForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1382, 703);
			this->Controls->Add(this->splitContainer1);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->Icon = gcnew System::Drawing::Icon("./Resources/sms.ico");
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->MaximizeBox = false;
			this->Name = L"LoginForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"New Phone, Who Dis\? - Login";
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			this->splitContainer1->Panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->logo))->EndInit();
			this->ResumeLayout(false);
		}
#pragma endregion
	private: System::Void button_Login_Click(System::Object^ sender, System::EventArgs^ e) {

		Packet pkt;

		std::string strU = msclr::interop::marshal_as<std::string>(textBox_Username->Text);
		strU += "login";
		char* username = new char[strU.length() + 1];
		std::strcpy(username, strU.c_str());
		int sizeUsername = static_cast<int>(strU.length());

		pkt.set_Username(username, sizeUsername);

		std::string strP = msclr::interop::marshal_as<std::string>(textBox_password->Text);
		char* password = new char[strP.length() + 1];
		std::strcpy(password, strP.c_str());
		int sizePassword = static_cast<int>(strP.length());

		pkt.set_Data(password, sizePassword);

		delete[] username;
		delete[] password;

		sendPackets_Client(pkt, clientSocket);

	}
	private: System::Void linkLabel_Signup_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {

		//this->Hide();
		//SignupForm^ FormSignup = gcnew SignupForm();
		//FormSignup->ShowDialog();
	}
	};
}
