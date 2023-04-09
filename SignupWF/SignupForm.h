#pragma once

namespace SignupWF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SignupForm
	/// </summary>
	public ref class SignupForm : public System::Windows::Forms::Form
	{
	public:
		SignupForm(void)
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
		~SignupForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::SplitContainer^ splitContainer1;
	private: System::Windows::Forms::PictureBox^ logo;
	private: System::Windows::Forms::Label^ signUp_Label;

	private: System::Windows::Forms::Label^ label_username;
	private: System::Windows::Forms::Label^ label_Password;
	private: System::Windows::Forms::TextBox^ textBox_Username;
	private: System::Windows::Forms::TextBox^ textBox_RePassword;

	private: System::Windows::Forms::Label^ label_RePassword;
	private: System::Windows::Forms::TextBox^ textBox_Password;


	private: System::Windows::Forms::Button^ button_SignUp;
	private: System::Windows::Forms::LinkLabel^ linkLabel_SignIn;


	protected:

	protected:


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(SignupForm::typeid));
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->logo = (gcnew System::Windows::Forms::PictureBox());
			this->linkLabel_SignIn = (gcnew System::Windows::Forms::LinkLabel());
			this->button_SignUp = (gcnew System::Windows::Forms::Button());
			this->textBox_RePassword = (gcnew System::Windows::Forms::TextBox());
			this->label_RePassword = (gcnew System::Windows::Forms::Label());
			this->textBox_Password = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Username = (gcnew System::Windows::Forms::TextBox());
			this->label_Password = (gcnew System::Windows::Forms::Label());
			this->label_username = (gcnew System::Windows::Forms::Label());
			this->signUp_Label = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->logo))->BeginInit();
			this->SuspendLayout();
			// 
			// splitContainer1
			// 
			this->splitContainer1->Location = System::Drawing::Point(0, 0);
			this->splitContainer1->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"splitContainer1.Panel1.BackgroundImage")));
			this->splitContainer1->Panel1->Controls->Add(this->logo);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->linkLabel_SignIn);
			this->splitContainer1->Panel2->Controls->Add(this->button_SignUp);
			this->splitContainer1->Panel2->Controls->Add(this->textBox_RePassword);
			this->splitContainer1->Panel2->Controls->Add(this->label_RePassword);
			this->splitContainer1->Panel2->Controls->Add(this->textBox_Password);
			this->splitContainer1->Panel2->Controls->Add(this->textBox_Username);
			this->splitContainer1->Panel2->Controls->Add(this->label_Password);
			this->splitContainer1->Panel2->Controls->Add(this->label_username);
			this->splitContainer1->Panel2->Controls->Add(this->signUp_Label);
			this->splitContainer1->Panel2->Font = (gcnew System::Drawing::Font(L"Courier New", 15));
			this->splitContainer1->Size = System::Drawing::Size(1382, 865);
			this->splitContainer1->SplitterDistance = 533;
			this->splitContainer1->TabIndex = 0;
			// 
			// logo
			// 
			this->logo->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->logo->BackColor = System::Drawing::Color::Transparent;
			this->logo->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"logo.Image")));
			this->logo->Location = System::Drawing::Point(1, 118);
			this->logo->Margin = System::Windows::Forms::Padding(3, 6, 3, 6);
			this->logo->Name = L"logo";
			this->logo->Size = System::Drawing::Size(531, 460);
			this->logo->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->logo->TabIndex = 1;
			this->logo->TabStop = false;
			// 
			// linkLabel_SignIn
			// 
			this->linkLabel_SignIn->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->linkLabel_SignIn->Font = (gcnew System::Drawing::Font(L"Courier New", 15));
			this->linkLabel_SignIn->LinkColor = System::Drawing::Color::Black;
			this->linkLabel_SignIn->Location = System::Drawing::Point(224, 634);
			this->linkLabel_SignIn->Name = L"linkLabel_SignIn";
			this->linkLabel_SignIn->Size = System::Drawing::Size(397, 29);
			this->linkLabel_SignIn->TabIndex = 10;
			this->linkLabel_SignIn->TabStop = true;
			this->linkLabel_SignIn->Text = L"I already have an account";
			this->linkLabel_SignIn->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->linkLabel_SignIn->VisitedLinkColor = System::Drawing::Color::Black;
			// 
			// button_SignUp
			// 
			this->button_SignUp->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button_SignUp->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(108)),
				static_cast<System::Int32>(static_cast<System::Byte>(148)));
			this->button_SignUp->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_SignUp->Font = (gcnew System::Drawing::Font(L"Courier New", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_SignUp->ForeColor = System::Drawing::Color::White;
			this->button_SignUp->Location = System::Drawing::Point(317, 547);
			this->button_SignUp->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->button_SignUp->Name = L"button_SignUp";
			this->button_SignUp->Size = System::Drawing::Size(210, 67);
			this->button_SignUp->TabIndex = 9;
			this->button_SignUp->Text = L"SIGN UP";
			this->button_SignUp->UseVisualStyleBackColor = false;
			// 
			// textBox_RePassword
			// 
			this->textBox_RePassword->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox_RePassword->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->textBox_RePassword->Location = System::Drawing::Point(57, 453);
			this->textBox_RePassword->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->textBox_RePassword->Name = L"textBox_RePassword";
			this->textBox_RePassword->Size = System::Drawing::Size(738, 34);
			this->textBox_RePassword->TabIndex = 8;
			this->textBox_RePassword->UseSystemPasswordChar = true;
			// 
			// label_RePassword
			// 
			this->label_RePassword->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label_RePassword->AutoSize = true;
			this->label_RePassword->Cursor = System::Windows::Forms::Cursors::Default;
			this->label_RePassword->Font = (gcnew System::Drawing::Font(L"Courier New", 18));
			this->label_RePassword->Location = System::Drawing::Point(50, 391);
			this->label_RePassword->Name = L"label_RePassword";
			this->label_RePassword->Size = System::Drawing::Size(303, 33);
			this->label_RePassword->TabIndex = 7;
			this->label_RePassword->Text = L"Re-type password";
			// 
			// textBox_Password
			// 
			this->textBox_Password->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox_Password->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->textBox_Password->Location = System::Drawing::Point(57, 328);
			this->textBox_Password->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->textBox_Password->Name = L"textBox_Password";
			this->textBox_Password->Size = System::Drawing::Size(738, 34);
			this->textBox_Password->TabIndex = 6;
			// 
			// textBox_Username
			// 
			this->textBox_Username->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox_Username->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->textBox_Username->Location = System::Drawing::Point(57, 203);
			this->textBox_Username->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->textBox_Username->Name = L"textBox_Username";
			this->textBox_Username->Size = System::Drawing::Size(738, 34);
			this->textBox_Username->TabIndex = 5;
			// 
			// label_Password
			// 
			this->label_Password->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label_Password->AutoSize = true;
			this->label_Password->Cursor = System::Windows::Forms::Cursors::Default;
			this->label_Password->Font = (gcnew System::Drawing::Font(L"Courier New", 18));
			this->label_Password->Location = System::Drawing::Point(50, 266);
			this->label_Password->Name = L"label_Password";
			this->label_Password->Size = System::Drawing::Size(159, 33);
			this->label_Password->TabIndex = 4;
			this->label_Password->Text = L"Password";
			// 
			// label_username
			// 
			this->label_username->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label_username->AutoSize = true;
			this->label_username->Font = (gcnew System::Drawing::Font(L"Courier New", 18));
			this->label_username->Location = System::Drawing::Point(50, 141);
			this->label_username->Name = L"label_username";
			this->label_username->Size = System::Drawing::Size(159, 33);
			this->label_username->TabIndex = 2;
			this->label_username->Text = L"Username";
			// 
			// signUp_Label
			// 
			this->signUp_Label->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->signUp_Label->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->signUp_Label->Font = (gcnew System::Drawing::Font(L"Courier New", 35));
			this->signUp_Label->Location = System::Drawing::Point(283, 26);
			this->signUp_Label->Name = L"signUp_Label";
			this->signUp_Label->Size = System::Drawing::Size(281, 89);
			this->signUp_Label->TabIndex = 1;
			this->signUp_Label->Text = L"SIGN UP";
			this->signUp_Label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// SignupForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(1382, 703);
			this->Controls->Add(this->splitContainer1);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1400, 900);
			this->Name = L"SignupForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"New Phone, Who Dis\? - Sign Up";
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			this->splitContainer1->Panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->logo))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
