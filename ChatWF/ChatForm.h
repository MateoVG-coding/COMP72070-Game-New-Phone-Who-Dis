#pragma once

namespace ChatWF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ChatForm
	/// </summary>
	public ref class ChatForm : public System::Windows::Forms::Form
	{
	public:
		ChatForm(void)
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
		~ChatForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::SplitContainer^ splitContainer1;
	private: System::Windows::Forms::Button^ button_Option3;




	private: System::Windows::Forms::Button^ button_Option1;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Button^ button_Option2;
	private: System::Windows::Forms::RichTextBox^ richTextBox_Chat;
	private: System::Windows::Forms::Button^ button_Option4;







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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ChatForm::typeid));
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->richTextBox_Chat = (gcnew System::Windows::Forms::RichTextBox());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->button_Option1 = (gcnew System::Windows::Forms::Button());
			this->button_Option3 = (gcnew System::Windows::Forms::Button());
			this->button_Option2 = (gcnew System::Windows::Forms::Button());
			this->button_Option4 = (gcnew System::Windows::Forms::Button());
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
			this->splitContainer1->TabIndex = 1;
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
			this->tableLayoutPanel1->ColumnCount = 4;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25.06265F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25.06266F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25.06266F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				24.81203F)));
			this->tableLayoutPanel1->Controls->Add(this->button_Option4, 3, 0);
			this->tableLayoutPanel1->Controls->Add(this->button_Option3, 2, 0);
			this->tableLayoutPanel1->Controls->Add(this->button_Option1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->button_Option2, 1, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1382, 235);
			this->tableLayoutPanel1->TabIndex = 3;
			// 
			// button_Option1
			// 
			this->button_Option1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_Option1->AutoSize = true;
			this->button_Option1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(167)),
				static_cast<System::Int32>(static_cast<System::Byte>(206)));
			this->button_Option1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_Option1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_Option1->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_Option1->Location = System::Drawing::Point(3, 3);
			this->button_Option1->Name = L"button_Option1";
			this->button_Option1->Size = System::Drawing::Size(340, 229);
			this->button_Option1->TabIndex = 0;
			this->button_Option1->Text = L"Reply 1";
			this->button_Option1->UseVisualStyleBackColor = false;
			// 
			// button_Option3
			// 
			this->button_Option3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_Option3->AutoSize = true;
			this->button_Option3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(167)),
				static_cast<System::Int32>(static_cast<System::Byte>(206)));
			this->button_Option3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_Option3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_Option3->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_Option3->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button_Option3->Location = System::Drawing::Point(695, 3);
			this->button_Option3->Name = L"button_Option3";
			this->button_Option3->Size = System::Drawing::Size(340, 229);
			this->button_Option3->TabIndex = 2;
			this->button_Option3->Text = L"Reply 3";
			this->button_Option3->UseVisualStyleBackColor = false;
			// 
			// button_Option2
			// 
			this->button_Option2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_Option2->AutoSize = true;
			this->button_Option2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(167)),
				static_cast<System::Int32>(static_cast<System::Byte>(206)));
			this->button_Option2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_Option2->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_Option2->Location = System::Drawing::Point(349, 3);
			this->button_Option2->Name = L"button_Option2";
			this->button_Option2->Size = System::Drawing::Size(340, 229);
			this->button_Option2->TabIndex = 1;
			this->button_Option2->Text = L"Reply 2";
			this->button_Option2->UseVisualStyleBackColor = false;
			// 
			// button_Option4
			// 
			this->button_Option4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_Option4->AutoSize = true;
			this->button_Option4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(167)),
				static_cast<System::Int32>(static_cast<System::Byte>(206)));
			this->button_Option4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_Option4->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_Option4->Location = System::Drawing::Point(1041, 3);
			this->button_Option4->Name = L"button_Option4";
			this->button_Option4->Size = System::Drawing::Size(338, 229);
			this->button_Option4->TabIndex = 2;
			this->button_Option4->Text = L"Reply 4";
			this->button_Option4->UseVisualStyleBackColor = false;
			// 
			// ChatForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(178)), static_cast<System::Int32>(static_cast<System::Byte>(178)),
				static_cast<System::Int32>(static_cast<System::Byte>(178)));
			this->ClientSize = System::Drawing::Size(1382, 753);
			this->Controls->Add(this->splitContainer1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"ChatForm";
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
