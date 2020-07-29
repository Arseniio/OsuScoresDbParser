#pragma once
#include "ScoresParser.h"
#include <string>
#include <msclr\marshal.h>
#include <msclr\marshal_cppstd.h>
namespace ScoresDBParse {
	using namespace msclr::interop;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected:
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;


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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Location = System::Drawing::Point(12, 10);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Open";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox1->Location = System::Drawing::Point(103, 12);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(213, 20);
			this->textBox1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(127, 45);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(13, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"0";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 45);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(109, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Count of local scores:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 68);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(126, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Count of scores in offline:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(144, 68);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(13, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"0";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(328, 96);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		if (textBox1->Text->Contains("scores.db")) {
			String^ test = textBox1->Text;
			std::string path = marshal_as<std::string>(test);
			ScoresParser osuDb = ScoresParser(path);
			label1->Text = Convert::ToString(osuDb.numOfReplays);
			label4->Text = Convert::ToString(osuDb.numOfOfflineReplays);
		}
		else MessageBox::Show("Path must be pointed to scores.db", "Error");

	}
	};
}
