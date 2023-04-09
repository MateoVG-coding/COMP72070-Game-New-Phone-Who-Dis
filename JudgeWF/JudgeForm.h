#pragma once

namespace JudgeWF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for JudgeForm
	/// </summary>
	public ref class JudgeForm : public System::Windows::Forms::Form
	{
	public:
		JudgeForm(void)
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
		~JudgeForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::SplitContainer^ splitContainer1;
	protected:
	private: System::Windows::Forms::RichTextBox^ richTextBox_Chat;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Button^ button_Player3;


	private: System::Windows::Forms::Button^ button_Player1;
	private: System::Windows::Forms::Button^ button_Player2;


	private: System::Windows::Forms::Button^ button_Player4;
	private: System::Windows::Forms::Button^ button_Player5;
	private: System::Windows::Forms::Button^ button_Player6;



	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(JudgeForm::typeid));
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->richTextBox_Chat = (gcnew System::Windows::Forms::RichTextBox());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->button_Player3 = (gcnew System::Windows::Forms::Button());
			this->button_Player1 = (gcnew System::Windows::Forms::Button());
			this->button_Player2 = (gcnew System::Windows::Forms::Button());
			this->button_Player6 = (gcnew System::Windows::Forms::Button());
			this->button_Player5 = (gcnew System::Windows::Forms::Button());
			this->button_Player4 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// splitContainer1
			// 
			this->splitContainer1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->splitContainer1->Location = System::Drawing::Point(0, 0);
			this->splitContainer1->Name = L"splitContainer1";
			this->splitContainer1->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->richTextBox_Chat);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->tableLayoutPanel1);
			this->splitContainer1->Size = System::Drawing::Size(1382, 753);
			this->splitContainer1->SplitterDistance = 514;
			this->splitContainer1->TabIndex = 2;
			// 
			// richTextBox_Chat
			// 
			this->richTextBox_Chat->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->richTextBox_Chat->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->richTextBox_Chat->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->richTextBox_Chat->Font = (gcnew System::Drawing::Font(L"Courier New", 15, System::Drawing::FontStyle::Bold));
			this->richTextBox_Chat->ForeColor = System::Drawing::SystemColors::ControlText;
			this->richTextBox_Chat->HideSelection = false;
			this->richTextBox_Chat->Location = System::Drawing::Point(12, 14);
			this->richTextBox_Chat->Name = L"richTextBox_Chat";
			this->richTextBox_Chat->ReadOnly = true;
			this->richTextBox_Chat->Size = System::Drawing::Size(1358, 486);
			this->richTextBox_Chat->TabIndex = 0;
			this->richTextBox_Chat->Text = L"";
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 3;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33332F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33334F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33334F)));
			this->tableLayoutPanel1->Controls->Add(this->button_Player4, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->button_Player5, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->button_Player6, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->button_Player3, 2, 0);
			this->tableLayoutPanel1->Controls->Add(this->button_Player1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->button_Player2, 1, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1382, 235);
			this->tableLayoutPanel1->TabIndex = 3;
			// 
			// button_Player3
			// 
			this->button_Player3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_Player3->AutoSize = true;
			this->button_Player3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(167)),
				static_cast<System::Int32>(static_cast<System::Byte>(206)));
			this->button_Player3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_Player3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_Player3->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_Player3->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button_Player3->Location = System::Drawing::Point(923, 3);
			this->button_Player3->Name = L"button_Player3";
			this->button_Player3->Size = System::Drawing::Size(456, 111);
			this->button_Player3->TabIndex = 2;
			this->button_Player3->Text = L"Player 3";
			this->button_Player3->UseVisualStyleBackColor = false;
			// 
			// button_Player1
			// 
			this->button_Player1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_Player1->AutoSize = true;
			this->button_Player1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(167)),
				static_cast<System::Int32>(static_cast<System::Byte>(206)));
			this->button_Player1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_Player1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_Player1->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_Player1->Location = System::Drawing::Point(3, 3);
			this->button_Player1->Name = L"button_Player1";
			this->button_Player1->Size = System::Drawing::Size(454, 111);
			this->button_Player1->TabIndex = 0;
			this->button_Player1->Text = L"Player 1";
			this->button_Player1->UseVisualStyleBackColor = false;
			// 
			// button_Player2
			// 
			this->button_Player2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_Player2->AutoSize = true;
			this->button_Player2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(167)),
				static_cast<System::Int32>(static_cast<System::Byte>(206)));
			this->button_Player2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_Player2->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_Player2->Location = System::Drawing::Point(463, 3);
			this->button_Player2->Name = L"button_Player2";
			this->button_Player2->Size = System::Drawing::Size(454, 111);
			this->button_Player2->TabIndex = 1;
			this->button_Player2->Text = L"Player 2";
			this->button_Player2->UseVisualStyleBackColor = false;
			// 
			// button_Player6
			// 
			this->button_Player6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_Player6->AutoSize = true;
			this->button_Player6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(167)),
				static_cast<System::Int32>(static_cast<System::Byte>(206)));
			this->button_Player6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_Player6->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_Player6->Location = System::Drawing::Point(923, 120);
			this->button_Player6->Name = L"button_Player6";
			this->button_Player6->Size = System::Drawing::Size(456, 112);
			this->button_Player6->TabIndex = 4;
			this->button_Player6->Text = L"Player 6";
			this->button_Player6->UseVisualStyleBackColor = false;
			// 
			// button_Player5
			// 
			this->button_Player5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_Player5->AutoSize = true;
			this->button_Player5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(167)),
				static_cast<System::Int32>(static_cast<System::Byte>(206)));
			this->button_Player5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_Player5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_Player5->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_Player5->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button_Player5->Location = System::Drawing::Point(463, 120);
			this->button_Player5->Name = L"button_Player5";
			this->button_Player5->Size = System::Drawing::Size(454, 112);
			this->button_Player5->TabIndex = 5;
			this->button_Player5->Text = L"Player 5";
			this->button_Player5->UseVisualStyleBackColor = false;
			// 
			// button_Player4
			// 
			this->button_Player4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_Player4->AutoSize = true;
			this->button_Player4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(167)),
				static_cast<System::Int32>(static_cast<System::Byte>(206)));
			this->button_Player4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_Player4->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_Player4->Location = System::Drawing::Point(3, 120);
			this->button_Player4->Name = L"button_Player4";
			this->button_Player4->Size = System::Drawing::Size(454, 112);
			this->button_Player4->TabIndex = 6;
			this->button_Player4->Text = L"Player 4";
			this->button_Player4->UseVisualStyleBackColor = false;
			// 
			// JudgeForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(178)), static_cast<System::Int32>(static_cast<System::Byte>(178)),
				static_cast<System::Int32>(static_cast<System::Byte>(178)));
			this->ClientSize = System::Drawing::Size(1382, 753);
			this->Controls->Add(this->splitContainer1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"JudgeForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"New Phone, Who Dis\?";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
