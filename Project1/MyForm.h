#pragma once
#include "Queue.h"
#include "Sortirovka.h"
#include "Zveno.h"
#include <msclr\marshal_cppstd.h>

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	int size;
	string str;
	int flag = 0;
	int* mem;
	Sort A(mem, size);
	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ TextInput;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ buttonRun;
	private: System::Windows::Forms::Button^ buttonStep;
	private: System::Windows::Forms::Label^ Res;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ buttonNext;

	private: System::Windows::Forms::DataGridView^ dataOchered;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->TextInput = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->buttonRun = (gcnew System::Windows::Forms::Button());
			this->buttonStep = (gcnew System::Windows::Forms::Button());
			this->Res = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->buttonNext = (gcnew System::Windows::Forms::Button());
			this->dataOchered = (gcnew System::Windows::Forms::DataGridView());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataOchered))->BeginInit();
			this->SuspendLayout();
			// 
			// TextInput
			// 
			this->TextInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->TextInput->Location = System::Drawing::Point(12, 49);
			this->TextInput->Name = L"TextInput";
			this->TextInput->Size = System::Drawing::Size(408, 29);
			this->TextInput->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(269, 24);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Введите элементы очереди:";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// buttonRun
			// 
			this->buttonRun->BackColor = System::Drawing::Color::AntiqueWhite;
			this->buttonRun->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F));
			this->buttonRun->Location = System::Drawing::Point(426, 41);
			this->buttonRun->Name = L"buttonRun";
			this->buttonRun->Size = System::Drawing::Size(251, 37);
			this->buttonRun->TabIndex = 2;
			this->buttonRun->Text = L"Запустить программу";
			this->buttonRun->UseVisualStyleBackColor = false;
			this->buttonRun->Click += gcnew System::EventHandler(this, &MyForm::buttonRun_Click);
			// 
			// buttonStep
			// 
			this->buttonStep->BackColor = System::Drawing::Color::AntiqueWhite;
			this->buttonStep->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonStep->Location = System::Drawing::Point(888, 8);
			this->buttonStep->Name = L"buttonStep";
			this->buttonStep->Size = System::Drawing::Size(249, 38);
			this->buttonStep->TabIndex = 3;
			this->buttonStep->Text = L"Вывести таблицу шагов";
			this->buttonStep->UseVisualStyleBackColor = false;
			this->buttonStep->Click += gcnew System::EventHandler(this, &MyForm::buttonStep_Click);
			// 
			// Res
			// 
			this->Res->AutoSize = true;
			this->Res->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Res->Location = System::Drawing::Point(132, 209);
			this->Res->Name = L"Res";
			this->Res->Size = System::Drawing::Size(0, 25);
			this->Res->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(898, 210);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(239, 24);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Поразрядная сортировка";
			this->label3->Visible = false;
			// 
			// buttonNext
			// 
			this->buttonNext->BackColor = System::Drawing::Color::AntiqueWhite;
			this->buttonNext->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonNext->Location = System::Drawing::Point(888, 52);
			this->buttonNext->Name = L"buttonNext";
			this->buttonNext->Size = System::Drawing::Size(249, 38);
			this->buttonNext->TabIndex = 7;
			this->buttonNext->Text = L"Следующий шаг";
			this->buttonNext->UseVisualStyleBackColor = false;
			this->buttonNext->Visible = false;
			this->buttonNext->Click += gcnew System::EventHandler(this, &MyForm::buttonNext_Click);
			// 
			// dataOchered
			// 
			this->dataOchered->AllowUserToAddRows = false;
			this->dataOchered->AllowUserToDeleteRows = false;
			this->dataOchered->AllowUserToResizeColumns = false;
			this->dataOchered->AllowUserToResizeRows = false;
			this->dataOchered->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataOchered->BackgroundColor = System::Drawing::Color::Gray;
			this->dataOchered->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataOchered->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			this->dataOchered->ColumnHeadersHeight = 10;
			this->dataOchered->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->dataOchered->ColumnHeadersVisible = false;
			this->dataOchered->Cursor = System::Windows::Forms::Cursors::Default;
			this->dataOchered->EditMode = System::Windows::Forms::DataGridViewEditMode::EditOnEnter;
			this->dataOchered->GridColor = System::Drawing::SystemColors::Desktop;
			this->dataOchered->Location = System::Drawing::Point(12, 237);
			this->dataOchered->Name = L"dataOchered";
			this->dataOchered->ReadOnly = true;
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataOchered->RowHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this->dataOchered->RowHeadersVisible = false;
			this->dataOchered->RowHeadersWidth = 4;
			this->dataOchered->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.25F));
			this->dataOchered->RowsDefaultCellStyle = dataGridViewCellStyle4;
			this->dataOchered->Size = System::Drawing::Size(1125, 375);
			this->dataOchered->TabIndex = 8;
			this->dataOchered->Visible = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label2->Location = System::Drawing::Point(8, 113);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(72, 24);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Ответ:";
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::Window;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F));
			this->textBox1->Location = System::Drawing::Point(12, 140);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(408, 29);
			this->textBox1->TabIndex = 10;
			this->textBox1->Click += gcnew System::EventHandler(this, &MyForm::textBox1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FloralWhite;
			this->ClientSize = System::Drawing::Size(1149, 624);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->dataOchered);
			this->Controls->Add(this->buttonNext);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->Res);
			this->Controls->Add(this->buttonStep);
			this->Controls->Add(this->buttonRun);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->TextInput);
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->Name = L"MyForm";
			this->Text = L"Очередь";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataOchered))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		void rasdel(string str, int& k, int* w) {
			k = 0;
			str = str + " ";
			while (str.length() > 0) {
				int l = str.find(" ");
				if (l > 0) {
					w[k++] = stoi(str.substr(0, l));
				}
				str.erase(0, l + 1);
			}
		}
		void cleardataGrid(int size) {
			if (size > 0) {
				dataOchered->RowCount = 0;
				dataOchered->ColumnCount = 0;
				dataOchered->RowTemplate->Height = 687 / (size + 1);
				dataOchered->RowCount = size + 1;
				dataOchered->ColumnCount = 10;
			}
		}
	private: System::Void buttonRun_Click(System::Object^ sender, System::EventArgs^ e) {
		size = 0;
		int* mem = new int[100];
		int* res;
		str = msclr::interop::marshal_as<std::string>(TextInput->Text);
		rasdel(str, size, mem);
		Sort A(mem, size);
		A.allStep();
		res = A.GetMem();
		str = "";
		for (int i = 0; i < size; i++) {
			str += to_string(res[i]) + " ";
		}
		textBox1->Text = gcnew String(str.c_str());
	}


	private: System::Void buttonStep_Click(System::Object^ sender, System::EventArgs^ e) {

		buttonNext->Visible = TRUE;
		dataOchered->Visible = TRUE;
		label3->Visible = TRUE;
		size = 0;
		flag = 0;
		int* mem = new int[100];
		str = msclr::interop::marshal_as<std::string>(TextInput->Text);
		rasdel(str, size, mem);
		A = Sort(mem, size);
		cleardataGrid(size);
		for (int i = 0; i < 10; i++) {
			dataOchered->Rows[0]->Cells[i]->Value = gcnew String(to_string(i).c_str());
		}
	}
	private: System::Void buttonNext_Click(System::Object^ sender, System::EventArgs^ e) {
		if (flag % 2 == 0) {
			cleardataGrid(size);
			for (int i = 0; i < 10; i++) {
				dataOchered->Rows[0]->Cells[i]->Value = gcnew String(to_string(i).c_str());
			}
			A.FirstStep(flag / 2);
			flag++;
			QueueQueue tmp;
			for (int i = 0; i < 10; i++) {
				tmp = A.GetOchered(i);
				int j = 1;
				while (!tmp.pusto()) {
					str = to_string(tmp.del_element_iz_nachala());
					dataOchered->Rows[j++]->Cells[i]->Value = gcnew String(str.c_str());
				}
			}
		}
		else {
			cleardataGrid(size);
			for (int i = 0; i < 10; i++) {
				dataOchered->Rows[0]->Cells[i]->Value = gcnew String(to_string(i).c_str());
			}
			A.SecondStep();
			str = "";
			int* mem = A.GetMem();
			for (int i = 0; i < size; i++) {
				str += to_string(mem[i]) + " ";
			}
			Res->Text = "Текущая очередь: " + gcnew String(str.c_str());
			flag++;
		}
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_Click(System::Object^ sender, System::EventArgs^ e) {
		size = 0;
		int* mem = new int[100];
		int* res;
		str = msclr::interop::marshal_as<std::string>(TextInput->Text);
		rasdel(str, size, mem);
		Sort A(mem, size);
		A.allStep();
		res = A.GetMem();
		str = "";
		for (int i = 0; i < size; i++) {
			str += to_string(res[i]) + " ";
		}
		textBox1->Text = gcnew String(str.c_str());
	}
};
}
