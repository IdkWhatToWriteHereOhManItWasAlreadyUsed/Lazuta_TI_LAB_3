#pragma once
#include <string>
#include <msclr/marshal_cppstd.h>
#include "Encryption.h"
#include "Math.h"
#include <vector>
#include <fstream>
#include <sstream>  

namespace $safeprojectname$ 
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	std::vector<uint8_t> inMessage;
	std::vector<uint8_t> outMessage;

	public ref class MyForm : public System::Windows::Forms::Form
	{

	#pragma region FormProperties
		/// <summary>
			/// Required method for Designer support - do not modify
			/// the contents of this method with the code editor.
			/// </summary>
		public:
		MyForm(void)
			{
				InitializeComponent();
				//
				//TODO: Add the constructor code here
				//
			}
		protected:
		~MyForm() {if (components){delete components;}}
	private: System::Windows::Forms::TextBox^ PTextBox;
	protected:

		private: System::Windows::Forms::Label^ label1;
		private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ GComboBox;

		private: System::Windows::Forms::Button^ GenerateNewPlainNumButton;
	private: System::Windows::Forms::TextBox^ XTextBox;

		private: System::Windows::Forms::Label^ label4;
		private: System::Windows::Forms::Button^ GenerateNewXButton;
		private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ YTextBox;

		private: System::Windows::Forms::MenuStrip^ menuStrip1;
		private: System::Windows::Forms::ToolStripMenuItem^ файлToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^ открытьToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^ сохранитьToolStripMenuItem;
	private: System::Windows::Forms::TextBox^ inTextBox;
	private: System::Windows::Forms::TextBox^ outTexrBox;
	private: System::Windows::Forms::Label^ lbl1;
	private: System::Windows::Forms::Label^ lbl2;




	private: System::Windows::Forms::Button^ CryptoButton;

	private: System::Windows::Forms::RadioButton^ rbDoEncryption;
	private: System::Windows::Forms::RadioButton^ rbDoDecryption;
	private: System::Windows::Forms::ProgressBar^ progressBar1;


	protected:
		private:
		System::ComponentModel::Container ^components;
    #pragma endregion
	#pragma region Windows Form Designer generated code
			/// <summary>
			/// Required method for Designer support - do not modify
			/// the contents of this method with the code editor.
			/// </summary>
			void InitializeComponent(void)
			{
				this->PTextBox = (gcnew System::Windows::Forms::TextBox());
				this->label1 = (gcnew System::Windows::Forms::Label());
				this->label2 = (gcnew System::Windows::Forms::Label());
				this->GComboBox = (gcnew System::Windows::Forms::ComboBox());
				this->GenerateNewPlainNumButton = (gcnew System::Windows::Forms::Button());
				this->XTextBox = (gcnew System::Windows::Forms::TextBox());
				this->label4 = (gcnew System::Windows::Forms::Label());
				this->GenerateNewXButton = (gcnew System::Windows::Forms::Button());
				this->label5 = (gcnew System::Windows::Forms::Label());
				this->YTextBox = (gcnew System::Windows::Forms::TextBox());
				this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
				this->файлToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->открытьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->сохранитьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->inTextBox = (gcnew System::Windows::Forms::TextBox());
				this->outTexrBox = (gcnew System::Windows::Forms::TextBox());
				this->lbl1 = (gcnew System::Windows::Forms::Label());
				this->lbl2 = (gcnew System::Windows::Forms::Label());
				this->CryptoButton = (gcnew System::Windows::Forms::Button());
				this->rbDoEncryption = (gcnew System::Windows::Forms::RadioButton());
				this->rbDoDecryption = (gcnew System::Windows::Forms::RadioButton());
				this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
				this->menuStrip1->SuspendLayout();
				this->SuspendLayout();
				// 
				// PTextBox
				// 
				this->PTextBox->Location = System::Drawing::Point(16, 65);
				this->PTextBox->Name = L"PTextBox";
				this->PTextBox->Size = System::Drawing::Size(130, 20);
				this->PTextBox->TabIndex = 0;
				this->PTextBox->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
				// 
				// label1
				// 
				this->label1->AutoSize = true;
				this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(204)));
				this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
					static_cast<System::Int32>(static_cast<System::Byte>(192)));
				this->label1->Location = System::Drawing::Point(8, 24);
				this->label1->Name = L"label1";
				this->label1->Size = System::Drawing::Size(341, 24);
				this->label1->TabIndex = 4;
				this->label1->Text = L"Cлучайное простое число р > 256";
				// 
				// label2
				// 
				this->label2->AutoSize = true;
				this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(204)));
				this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
					static_cast<System::Int32>(static_cast<System::Byte>(192)));
				this->label2->Location = System::Drawing::Point(11, 88);
				this->label2->Name = L"label2";
				this->label2->Size = System::Drawing::Size(525, 24);
				this->label2->TabIndex = 5;
				this->label2->Text = L"g, являющееся первообразным корнем по модулю р";
				// 
				// GComboBox
				// 
				this->GComboBox->FormattingEnabled = true;
				this->GComboBox->Location = System::Drawing::Point(16, 115);
				this->GComboBox->Name = L"GComboBox";
				this->GComboBox->Size = System::Drawing::Size(130, 21);
				this->GComboBox->TabIndex = 7;
				this->GComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
				// 
				// GenerateNewPlainNumButton
				// 
				this->GenerateNewPlainNumButton->BackColor = System::Drawing::Color::Red;
				this->GenerateNewPlainNumButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
				this->GenerateNewPlainNumButton->Location = System::Drawing::Point(152, 56);
				this->GenerateNewPlainNumButton->Name = L"GenerateNewPlainNumButton";
				this->GenerateNewPlainNumButton->Size = System::Drawing::Size(203, 29);
				this->GenerateNewPlainNumButton->TabIndex = 8;
				this->GenerateNewPlainNumButton->Text = L"Сгенерировать новое простое число";
				this->GenerateNewPlainNumButton->UseVisualStyleBackColor = false;
				this->GenerateNewPlainNumButton->Click += gcnew System::EventHandler(this, &MyForm::GenerateNewPlainNumButton_Click);
				// 
				// XTextBox
				// 
				this->XTextBox->Location = System::Drawing::Point(15, 170);
				this->XTextBox->Name = L"XTextBox";
				this->XTextBox->Size = System::Drawing::Size(130, 20);
				this->XTextBox->TabIndex = 9;
				this->XTextBox->TextChanged += gcnew System::EventHandler(this, &MyForm::XTextBox_TextChanged);
				// 
				// label4
				// 
				this->label4->AutoSize = true;
				this->label4->BackColor = System::Drawing::Color::LightCoral;
				this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(204)));
				this->label4->ForeColor = System::Drawing::Color::MidnightBlue;
				this->label4->Location = System::Drawing::Point(12, 139);
				this->label4->Name = L"label4";
				this->label4->Size = System::Drawing::Size(773, 24);
				this->label4->TabIndex = 10;
				this->label4->Text = L"Cлучайное целое положительное число x< p−1, не равное 1 (закрытый ключ)";
				// 
				// GenerateNewXButton
				// 
				this->GenerateNewXButton->BackColor = System::Drawing::Color::Red;
				this->GenerateNewXButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
				this->GenerateNewXButton->Location = System::Drawing::Point(151, 166);
				this->GenerateNewXButton->Name = L"GenerateNewXButton";
				this->GenerateNewXButton->Size = System::Drawing::Size(203, 27);
				this->GenerateNewXButton->TabIndex = 11;
				this->GenerateNewXButton->Text = L"Сгенерировать новое x";
				this->GenerateNewXButton->UseVisualStyleBackColor = false;
				this->GenerateNewXButton->Click += gcnew System::EventHandler(this, &MyForm::GenerateNewXButton_Click);
				// 
				// label5
				// 
				this->label5->AutoSize = true;
				this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(204)));
				this->label5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
					static_cast<System::Int32>(static_cast<System::Byte>(192)));
				this->label5->Location = System::Drawing::Point(12, 196);
				this->label5->Name = L"label5";
				this->label5->Size = System::Drawing::Size(142, 24);
				this->label5->TabIndex = 12;
				this->label5->Text = L"y = g^x mod p";
				// 
				// YTextBox
				// 
				this->YTextBox->Location = System::Drawing::Point(16, 232);
				this->YTextBox->Name = L"YTextBox";
				this->YTextBox->ReadOnly = true;
				this->YTextBox->Size = System::Drawing::Size(130, 20);
				this->YTextBox->TabIndex = 13;
				// 
				// menuStrip1
				// 
				this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->файлToolStripMenuItem });
				this->menuStrip1->Location = System::Drawing::Point(0, 0);
				this->menuStrip1->Name = L"menuStrip1";
				this->menuStrip1->Size = System::Drawing::Size(1357, 24);
				this->menuStrip1->TabIndex = 14;
				this->menuStrip1->Text = L"menuStrip1";
				// 
				// файлToolStripMenuItem
				// 
				this->файлToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
					this->открытьToolStripMenuItem,
						this->сохранитьToolStripMenuItem
				});
				this->файлToolStripMenuItem->Name = L"файлToolStripMenuItem";
				this->файлToolStripMenuItem->Size = System::Drawing::Size(48, 20);
				this->файлToolStripMenuItem->Text = L"Файл";
				// 
				// открытьToolStripMenuItem
				// 
				this->открытьToolStripMenuItem->Name = L"открытьToolStripMenuItem";
				this->открытьToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
				this->открытьToolStripMenuItem->Size = System::Drawing::Size(180, 22);
				this->открытьToolStripMenuItem->Text = L"Открыть";
				this->открытьToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::открытьToolStripMenuItem_Click);
				// 
				// сохранитьToolStripMenuItem
				// 
				this->сохранитьToolStripMenuItem->Name = L"сохранитьToolStripMenuItem";
				this->сохранитьToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
				this->сохранитьToolStripMenuItem->Size = System::Drawing::Size(180, 22);
				this->сохранитьToolStripMenuItem->Text = L"Сохранить";
				this->сохранитьToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::сохранитьToolStripMenuItem_Click);
				// 
				// inTextBox
				// 
				this->inTextBox->BackColor = System::Drawing::Color::LightGoldenrodYellow;
				this->inTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(204)));
				this->inTextBox->Location = System::Drawing::Point(16, 302);
				this->inTextBox->Multiline = true;
				this->inTextBox->Name = L"inTextBox";
				this->inTextBox->ReadOnly = true;
				this->inTextBox->Size = System::Drawing::Size(1287, 123);
				this->inTextBox->TabIndex = 15;
				this->inTextBox->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox4_TextChanged);
				// 
				// outTexrBox
				// 
				this->outTexrBox->BackColor = System::Drawing::Color::LightYellow;
				this->outTexrBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(204)));
				this->outTexrBox->Location = System::Drawing::Point(12, 483);
				this->outTexrBox->Multiline = true;
				this->outTexrBox->Name = L"outTexrBox";
				this->outTexrBox->ReadOnly = true;
				this->outTexrBox->Size = System::Drawing::Size(1324, 123);
				this->outTexrBox->TabIndex = 16;
				// 
				// lbl1
				// 
				this->lbl1->AutoSize = true;
				this->lbl1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(204)));
				this->lbl1->ForeColor = System::Drawing::Color::AliceBlue;
				this->lbl1->Location = System::Drawing::Point(11, 275);
				this->lbl1->Name = L"lbl1";
				this->lbl1->Size = System::Drawing::Size(170, 24);
				this->lbl1->TabIndex = 17;
				this->lbl1->Text = L"Исходный текст";
				// 
				// lbl2
				// 
				this->lbl2->AutoSize = true;
				this->lbl2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(204)));
				this->lbl2->ForeColor = System::Drawing::Color::AliceBlue;
				this->lbl2->Location = System::Drawing::Point(11, 456);
				this->lbl2->Name = L"lbl2";
				this->lbl2->Size = System::Drawing::Size(131, 24);
				this->lbl2->TabIndex = 18;
				this->lbl2->Text = L"Шифротекст";
				// 
				// CryptoButton
				// 
				this->CryptoButton->BackColor = System::Drawing::Color::Chartreuse;
				this->CryptoButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
					System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
				this->CryptoButton->ForeColor = System::Drawing::Color::Indigo;
				this->CryptoButton->Location = System::Drawing::Point(160, 209);
				this->CryptoButton->Name = L"CryptoButton";
				this->CryptoButton->Size = System::Drawing::Size(310, 63);
				this->CryptoButton->TabIndex = 19;
				this->CryptoButton->Text = L"Зашифровать";
				this->CryptoButton->UseVisualStyleBackColor = false;
				this->CryptoButton->Click += gcnew System::EventHandler(this, &MyForm::CryptoButton_Click);
				// 
				// rbDoEncryption
				// 
				this->rbDoEncryption->AutoSize = true;
				this->rbDoEncryption->Checked = true;
				this->rbDoEncryption->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(204)));
				this->rbDoEncryption->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
				this->rbDoEncryption->Location = System::Drawing::Point(492, 209);
				this->rbDoEncryption->Name = L"rbDoEncryption";
				this->rbDoEncryption->Size = System::Drawing::Size(143, 28);
				this->rbDoEncryption->TabIndex = 20;
				this->rbDoEncryption->TabStop = true;
				this->rbDoEncryption->Text = L"Шифрование";
				this->rbDoEncryption->UseVisualStyleBackColor = true;
				this->rbDoEncryption->CheckedChanged += gcnew System::EventHandler(this, &MyForm::rbDoEncryption_CheckedChanged);
				// 
				// rbDoDecryption
				// 
				this->rbDoDecryption->AutoSize = true;
				this->rbDoDecryption->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(204)));
				this->rbDoDecryption->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
				this->rbDoDecryption->Location = System::Drawing::Point(492, 243);
				this->rbDoDecryption->Name = L"rbDoDecryption";
				this->rbDoDecryption->Size = System::Drawing::Size(175, 28);
				this->rbDoDecryption->TabIndex = 21;
				this->rbDoDecryption->Text = L"Расшифрование";
				this->rbDoDecryption->UseVisualStyleBackColor = true;
				this->rbDoDecryption->CheckedChanged += gcnew System::EventHandler(this, &MyForm::rbDoDecryption_CheckedChanged);
				// 
				// progressBar1
				// 
				this->progressBar1->BackColor = System::Drawing::Color::MediumBlue;
				this->progressBar1->Dock = System::Windows::Forms::DockStyle::Bottom;
				this->progressBar1->ForeColor = System::Drawing::Color::Orange;
				this->progressBar1->Location = System::Drawing::Point(0, 635);
				this->progressBar1->Name = L"progressBar1";
				this->progressBar1->Size = System::Drawing::Size(1357, 28);
				this->progressBar1->TabIndex = 22;
				// 
				// MyForm
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->BackColor = System::Drawing::Color::Indigo;
				this->ClientSize = System::Drawing::Size(1357, 663);
				this->Controls->Add(this->progressBar1);
				this->Controls->Add(this->rbDoDecryption);
				this->Controls->Add(this->rbDoEncryption);
				this->Controls->Add(this->CryptoButton);
				this->Controls->Add(this->lbl2);
				this->Controls->Add(this->lbl1);
				this->Controls->Add(this->outTexrBox);
				this->Controls->Add(this->inTextBox);
				this->Controls->Add(this->YTextBox);
				this->Controls->Add(this->label5);
				this->Controls->Add(this->GenerateNewXButton);
				this->Controls->Add(this->label4);
				this->Controls->Add(this->XTextBox);
				this->Controls->Add(this->GenerateNewPlainNumButton);
				this->Controls->Add(this->GComboBox);
				this->Controls->Add(this->label2);
				this->Controls->Add(this->label1);
				this->Controls->Add(this->PTextBox);
				this->Controls->Add(this->menuStrip1);
				this->MainMenuStrip = this->menuStrip1;
				this->Name = L"MyForm";
				this->ShowIcon = false;
				this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
				this->Text = L"351004 Лазута ТИ, ЛР3 вариант 2";
				this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
				this->menuStrip1->ResumeLayout(false);
				this->menuStrip1->PerformLayout();
				this->ResumeLayout(false);
				this->PerformLayout();

			}
	#pragma endregion

		System::String^ ConvertString(const std::string& str) {
			return msclr::interop::marshal_as<System::String^>(str);
		}

		std::string ConvertString(System::String^ str) {
			return msclr::interop::marshal_as<std::string>(str);
		}

		private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) 
		{
			SetYEditText();
		}

	    int ConvertToPositiveNumber(System::String^ str)
	    {
			try
			{
				std::string nativeStr = msclr::interop::marshal_as<std::string>(str->Trim());
				if (nativeStr.empty())
					return -1;
				int number = std::stoi(nativeStr);
				return (number > 0) ? number : 0;
			}
			catch (...)
			{
				return 0;
			}
		}

		void SetYEditText()
		{
			YTextBox->Text = "";
			int p = ConvertToPositiveNumber(PTextBox->Text);
			if (is_prime(p) && p > 256)
			{
				int x = ConvertToPositiveNumber(XTextBox->Text);
				if (x)
				{
					if (GComboBox->SelectedItem)
					{
						int g = ConvertToPositiveNumber(GComboBox->SelectedItem->ToString());
						if (g)
						{
							int y = exp_module(g, x, p);
							YTextBox->Text = y.ToString();
						}
					}					
				}
			}
		}

		private: System::Void GenerateNewPlainNumButton_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			GComboBox->Items->Clear();
			int plainNum = getRandomPrime(256, 999);
			PTextBox->Text = ConvertString(std::to_string(plainNum));
			std::vector<int> roots = find_primitive_roots(plainNum);
			for(int root: roots)
			{
				GComboBox->Items->Add(root.ToString());
			}
			SetYEditText();
		}

	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		GComboBox->Items->Clear();
		int num = ConvertToPositiveNumber(PTextBox->Text);
		if (is_prime(num))
		{
			std::vector<int> roots = find_primitive_roots(num);
			for (int root : roots)
			{
				GComboBox->Items->Add(root.ToString());
			}
		}
		SetYEditText();
	}
		private: System::Void GenerateNewXButton_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			int plainNum = ConvertToPositiveNumber(PTextBox->Text);
			if (is_prime(plainNum))
			{
				XTextBox->Text = (rand() % (plainNum - 1)).ToString();
				SetYEditText();
			}
			else
			{
				MessageBox::Show("Введите простое Р!");
			}
			
		}
		private: System::Void открытьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
			openFileDialog->Title = "Выберите файл для чтения";
			openFileDialog->Filter = "Все файлы (*.*)|*.*";
			openFileDialog->RestoreDirectory = true;

			if (openFileDialog->ShowDialog() == Windows::Forms::DialogResult::OK)
			{
				try
				{
					String^ filePath = openFileDialog->FileName;
					std::string nativePath = msclr::interop::marshal_as<std::string>(filePath);

					// Читаем файл в бинарном режиме
					std::ifstream file(nativePath, std::ios::binary | std::ios::ate);
					if (!file.is_open())
						return;

					// Получаем размер файла
					std::streamsize size = file.tellg();
					file.seekg(0, std::ios::beg);

					// Читаем данные в вектор
					inMessage.resize(static_cast<size_t>(size));
					if (!file.read(reinterpret_cast<char*>(inMessage.data()), size))
					{
						inMessage.clear();
						return;
					}

					showContents(inMessage, inTextBox);
					outTexrBox->Text = "";
					return;
				}
				catch (...)
				{
					inMessage.clear();
					return;
				}
			}
			return;
		}

		void showContents(std::vector<uint8_t> data, System::Windows::Forms::TextBox^ textBox)
		{
			std::ostringstream ss; 

			if (data.size() > 20)
			{
				ss << "[First 20 bytes]: ";
				for (size_t i = 0; i < 20 && i < data.size(); ++i) {
					ss << static_cast<int>(data[i]) << " ";
				}
				ss << "                              [Last 20 bytes]: ";
#undef max
				for (size_t i = std::max(data.size() - 20, size_t(0)); i < data.size(); ++i) {
					ss << static_cast<int>(data[i]) << " ";
				}
			}
			else
			{
				ss << "[All bytes]: ";
				for (const auto& byte : data) {
					ss << static_cast<int>(byte) << " ";
				}
			}

			textBox->Text = msclr::interop::marshal_as<System::String^>(ss.str());
		}


		private: System::Void сохранитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			if (outMessage.empty())
				return;

			SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();
			saveFileDialog->Title = "Выберите файл для сохранения";
			saveFileDialog->Filter = "Все файлы (*.*)|*.*";
			saveFileDialog->RestoreDirectory = true;

			if (saveFileDialog->ShowDialog() == Windows::Forms::DialogResult::OK)
			{
				try
				{
					String^ filePath = saveFileDialog->FileName;
					std::string nativePath = msclr::interop::marshal_as<std::string>(filePath);

					// Записываем файл в бинарном режиме
					std::ofstream file(nativePath, std::ios::binary);
					if (!file.is_open())
						return;
					 
					long long progress = 0;
					long long  end = outMessage.size();
					for (uint8_t byte: outMessage)
					{
						file << byte;
						progressBar1->Value = progress++ * 100 / end;
					}
					file.close();
					progressBar1->Value = 0;
					return;
				}
				catch (std::exception ex)
				{
					MessageBox::Show("Error durind writing: " + ConvertString(ex.what()));
					return;
				}
			}
			return;
		}
	private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void rbDoDecryption_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (rbDoDecryption->Checked)
	{
		CryptoButton->Text = "Расшифровать";
		lbl1->Text = "Шифротекст";
		lbl2->Text = "Исходный текст";
	}
		
	else
	{
		CryptoButton->Text = "Зашифровать";
		lbl1->Text = "Исходный текст";
		lbl2->Text = "Шифротекст";
	}
}
private: System::Void XTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	uint8_t plainNum = ConvertToPositiveNumber(XTextBox->Text);
	if (!plainNum || plainNum > ConvertToPositiveNumber(PTextBox->Text) - 1)
	{
		XTextBox->Text = "";
	}
	SetYEditText();
}


	private: System::Void CryptoButton_Click(System::Object^ sender, System::EventArgs^ e) {
		ULONGLONG a = GetTickCount64();
		int p = ConvertToPositiveNumber(PTextBox->Text);
		if (is_prime(p))
		{
			int x = ConvertToPositiveNumber(XTextBox->Text);
			if (x > 1 && x < p)
			{
				if (GComboBox->SelectedItem)
				{
					int g = ConvertToPositiveNumber(GComboBox->SelectedItem->ToString());
					if (g)
					{
						if (inMessage.size())
						{
							int y = exp_module(g, x, p);
							if (rbDoEncryption->Checked)
							{
								outMessage = EncryptMessage(inMessage, p, g, y);
								showContents(outMessage, outTexrBox);
							}
							else
							{
								outMessage = DecryptMessage(inMessage, p, x);
								showContents(outMessage, outTexrBox);
							}		
							a = GetTickCount64() - a;
							MessageBox::Show(a.ToString() + " ms");
						}
					}
				}
				else
					MessageBox::Show("Пожалуйста, выберите первообразный корень!");
			}
			else
				MessageBox::Show("Введите значение Х от 2 до Р не включительно!");
		}
		else
			MessageBox::Show("Р должно быть простым!");
	}
private: System::Void rbDoEncryption_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
