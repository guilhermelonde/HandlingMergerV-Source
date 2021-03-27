#include <shobjidl.h> 
#include <msclr\marshal_cppstd.h>
#include "toolSet.cpp" 

#pragma once

namespace HandlingMergerV {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	toolSet::MainTool MTObj;

	/// <summary>
	/// Sumário para MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Adicione o código do construtor aqui
			//
		}

	protected:
		/// <summary>
		/// Limpar os recursos que estão sendo usados.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ SelectMod;
	private: System::Windows::Forms::Button^ SelectHandling;











	private: System::Windows::Forms::Label^ DirF1;
	private: System::Windows::Forms::Label^ DirF2;
	private: System::Windows::Forms::CheckedListBox^ CommonList;

	private: System::Windows::Forms::Button^ SelectAll;
	private: System::Windows::Forms::Button^ UnselectAll;
	private: System::Windows::Forms::CheckedListBox^ CommonVarList;

	private: System::Windows::Forms::Button^ UnselectAllVar;
	private: System::Windows::Forms::Button^ SelectAllVar;

	private: System::Windows::Forms::Button^ Merge;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::Button^ UnselectAllInsert;
	private: System::Windows::Forms::CheckedListBox^ UncommonList;
	private: System::Windows::Forms::Button^ SelectAllInsert;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ Insert;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::Button^ UnselectAllVarVar;
	private: System::Windows::Forms::Button^ SelectAllVarVar;
	private: System::Windows::Forms::Button^ UnselectAllVerVeh;
	private: System::Windows::Forms::Button^ SelectAllVarVeh;
	private: System::Windows::Forms::Button^ InsertVar;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::CheckedListBox^ UncommonVarVar;
	private: System::Windows::Forms::CheckedListBox^ UncommonVarVehicles;

	private: CheckedListBox^ currentCLB;
	private: int currentSelectedInCLB;











	private:
		/// <summary>
		/// Variável de designer necessária.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necessário para suporte ao Designer - não modifique 
		/// o conteúdo deste método com o editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SelectMod = (gcnew System::Windows::Forms::Button());
			this->SelectHandling = (gcnew System::Windows::Forms::Button());
			this->DirF1 = (gcnew System::Windows::Forms::Label());
			this->DirF2 = (gcnew System::Windows::Forms::Label());
			this->CommonList = (gcnew System::Windows::Forms::CheckedListBox());
			this->SelectAll = (gcnew System::Windows::Forms::Button());
			this->UnselectAll = (gcnew System::Windows::Forms::Button());
			this->CommonVarList = (gcnew System::Windows::Forms::CheckedListBox());
			this->UnselectAllVar = (gcnew System::Windows::Forms::Button());
			this->SelectAllVar = (gcnew System::Windows::Forms::Button());
			this->Merge = (gcnew System::Windows::Forms::Button());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->UnselectAllVarVar = (gcnew System::Windows::Forms::Button());
			this->SelectAllVarVar = (gcnew System::Windows::Forms::Button());
			this->UnselectAllVerVeh = (gcnew System::Windows::Forms::Button());
			this->SelectAllVarVeh = (gcnew System::Windows::Forms::Button());
			this->InsertVar = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->UncommonVarVar = (gcnew System::Windows::Forms::CheckedListBox());
			this->UncommonVarVehicles = (gcnew System::Windows::Forms::CheckedListBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->UncommonList = (gcnew System::Windows::Forms::CheckedListBox());
			this->SelectAllInsert = (gcnew System::Windows::Forms::Button());
			this->Insert = (gcnew System::Windows::Forms::Button());
			this->UnselectAllInsert = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 35);
			this->label1->MaximumSize = System::Drawing::Size(160, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(158, 26);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Select the file with the modified handling data to retrieve:";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(451, 37);
			this->label2->MaximumSize = System::Drawing::Size(170, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(170, 26);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Select the handling.meta file that will receive modded handling data:";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// SelectMod
			// 
			this->SelectMod->Cursor = System::Windows::Forms::Cursors::Hand;
			this->SelectMod->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->SelectMod->ForeColor = System::Drawing::SystemColors::ControlText;
			this->SelectMod->Location = System::Drawing::Point(184, 34);
			this->SelectMod->Name = L"SelectMod";
			this->SelectMod->Size = System::Drawing::Size(105, 29);
			this->SelectMod->TabIndex = 2;
			this->SelectMod->Text = L"Select";
			this->SelectMod->UseVisualStyleBackColor = false;
			this->SelectMod->Click += gcnew System::EventHandler(this, &MyForm::SelectMod_Click);
			// 
			// SelectHandling
			// 
			this->SelectHandling->BackColor = System::Drawing::SystemColors::ControlLight;
			this->SelectHandling->Cursor = System::Windows::Forms::Cursors::Hand;
			this->SelectHandling->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->SelectHandling->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->SelectHandling->Location = System::Drawing::Point(625, 34);
			this->SelectHandling->Name = L"SelectHandling";
			this->SelectHandling->Size = System::Drawing::Size(105, 29);
			this->SelectHandling->TabIndex = 3;
			this->SelectHandling->Text = L"Select";
			this->SelectHandling->UseVisualStyleBackColor = false;
			this->SelectHandling->Click += gcnew System::EventHandler(this, &MyForm::SelectHandling_Click);
			// 
			// DirF1
			// 
			this->DirF1->AutoSize = true;
			this->DirF1->Location = System::Drawing::Point(5, 72);
			this->DirF1->MaximumSize = System::Drawing::Size(430, 13);
			this->DirF1->MinimumSize = System::Drawing::Size(430, 13);
			this->DirF1->Name = L"DirF1";
			this->DirF1->Size = System::Drawing::Size(430, 13);
			this->DirF1->TabIndex = 7;
			this->DirF1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// DirF2
			// 
			this->DirF2->AutoSize = true;
			this->DirF2->Location = System::Drawing::Point(440, 72);
			this->DirF2->MaximumSize = System::Drawing::Size(440, 13);
			this->DirF2->MinimumSize = System::Drawing::Size(440, 13);
			this->DirF2->Name = L"DirF2";
			this->DirF2->Size = System::Drawing::Size(440, 13);
			this->DirF2->TabIndex = 8;
			this->DirF2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// CommonList
			// 
			this->CommonList->CheckOnClick = true;
			this->CommonList->Cursor = System::Windows::Forms::Cursors::Hand;
			this->CommonList->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CommonList->ForeColor = System::Drawing::SystemColors::InfoText;
			this->CommonList->FormattingEnabled = true;
			this->CommonList->Location = System::Drawing::Point(7, 44);
			this->CommonList->Name = L"CommonList";
			this->CommonList->Size = System::Drawing::Size(344, 304);
			this->CommonList->TabIndex = 2;
			this->CommonList->MouseDown += gcnew Windows::Forms::MouseEventHandler(this, &MyForm::CommonList_MouseDown);
			// 
			// SelectAll
			// 
			this->SelectAll->Cursor = System::Windows::Forms::Cursors::Hand;
			this->SelectAll->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->SelectAll->Location = System::Drawing::Point(219, 17);
			this->SelectAll->Name = L"SelectAll";
			this->SelectAll->Size = System::Drawing::Size(65, 25);
			this->SelectAll->TabIndex = 4;
			this->SelectAll->Text = L"Mark all";
			this->SelectAll->UseVisualStyleBackColor = true;
			this->SelectAll->Click += gcnew System::EventHandler(this, &MyForm::SelectAll_Click);
			// 
			// UnselectAll
			// 
			this->UnselectAll->Cursor = System::Windows::Forms::Cursors::Hand;
			this->UnselectAll->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->UnselectAll->Location = System::Drawing::Point(286, 17);
			this->UnselectAll->Name = L"UnselectAll";
			this->UnselectAll->Size = System::Drawing::Size(65, 25);
			this->UnselectAll->TabIndex = 5;
			this->UnselectAll->Text = L"Unmark all";
			this->UnselectAll->UseVisualStyleBackColor = true;
			this->UnselectAll->Click += gcnew System::EventHandler(this, &MyForm::UnselectAll_Click);
			// 
			// CommonVarList
			// 
			this->CommonVarList->CheckOnClick = true;
			this->CommonVarList->Cursor = System::Windows::Forms::Cursors::Hand;
			this->CommonVarList->FormattingEnabled = true;
			this->CommonVarList->Location = System::Drawing::Point(8, 44);
			this->CommonVarList->Name = L"CommonVarList";
			this->CommonVarList->Size = System::Drawing::Size(350, 304);
			this->CommonVarList->TabIndex = 6;
			// 
			// UnselectAllVar
			// 
			this->UnselectAllVar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->UnselectAllVar->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->UnselectAllVar->Location = System::Drawing::Point(293, 17);
			this->UnselectAllVar->Name = L"UnselectAllVar";
			this->UnselectAllVar->Size = System::Drawing::Size(65, 25);
			this->UnselectAllVar->TabIndex = 8;
			this->UnselectAllVar->Text = L"Unmark all";
			this->UnselectAllVar->UseVisualStyleBackColor = true;
			this->UnselectAllVar->Click += gcnew System::EventHandler(this, &MyForm::UnselectAllVar_Click);
			// 
			// SelectAllVar
			// 
			this->SelectAllVar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->SelectAllVar->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->SelectAllVar->Location = System::Drawing::Point(226, 17);
			this->SelectAllVar->Name = L"SelectAllVar";
			this->SelectAllVar->Size = System::Drawing::Size(65, 25);
			this->SelectAllVar->TabIndex = 9;
			this->SelectAllVar->Text = L"Mark all";
			this->SelectAllVar->UseVisualStyleBackColor = true;
			this->SelectAllVar->Click += gcnew System::EventHandler(this, &MyForm::SelectAllVar_Click);
			// 
			// Merge
			// 
			this->Merge->BackColor = System::Drawing::SystemColors::ControlLight;
			this->Merge->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->Merge->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Merge->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->Merge->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Merge->Location = System::Drawing::Point(748, 309);
			this->Merge->Name = L"Merge";
			this->Merge->Size = System::Drawing::Size(100, 45);
			this->Merge->TabIndex = 0;
			this->Merge->Text = L"Replace!";
			this->Merge->UseVisualStyleBackColor = false;
			this->Merge->Click += gcnew System::EventHandler(this, &MyForm::Merge_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(8, 93);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(872, 394);
			this->tabControl1->TabIndex = 16;
			// 
			// tabPage1
			// 
			this->tabPage1->BackColor = System::Drawing::Color::Transparent;
			this->tabPage1->Controls->Add(this->label3);
			this->tabPage1->Controls->Add(this->groupBox2);
			this->tabPage1->Controls->Add(this->groupBox1);
			this->tabPage1->Controls->Add(this->Merge);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(864, 368);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Replace Options";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Black;
			this->label3->Location = System::Drawing::Point(743, 16);
			this->label3->MaximumSize = System::Drawing::Size(115, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(109, 135);
			this->label3->TabIndex = 12;
			this->label3->Text = L"The vehicles or variables on the file with modified handling data that are not on"
				L" some of these list may be found in \"Add Options\" tab.";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->UnselectAllVar);
			this->groupBox2->Controls->Add(this->SelectAllVar);
			this->groupBox2->Controls->Add(this->CommonVarList);
			this->groupBox2->Location = System::Drawing::Point(369, 6);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(364, 356);
			this->groupBox2->TabIndex = 11;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Variables to replace";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->CommonList);
			this->groupBox1->Controls->Add(this->UnselectAll);
			this->groupBox1->Controls->Add(this->SelectAll);
			this->groupBox1->Location = System::Drawing::Point(6, 6);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(357, 356);
			this->groupBox1->TabIndex = 10;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Vehicles to replace";
			// 
			// tabPage2
			// 
			this->tabPage2->BackColor = System::Drawing::Color::Transparent;
			this->tabPage2->Controls->Add(this->groupBox4);
			this->tabPage2->Controls->Add(this->label4);
			this->tabPage2->Controls->Add(this->groupBox3);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(864, 368);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Add Options";
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->UnselectAllVarVar);
			this->groupBox4->Controls->Add(this->SelectAllVarVar);
			this->groupBox4->Controls->Add(this->UnselectAllVerVeh);
			this->groupBox4->Controls->Add(this->SelectAllVarVeh);
			this->groupBox4->Controls->Add(this->InsertVar);
			this->groupBox4->Controls->Add(this->label5);
			this->groupBox4->Controls->Add(this->UncommonVarVar);
			this->groupBox4->Controls->Add(this->UncommonVarVehicles);
			this->groupBox4->Location = System::Drawing::Point(363, 21);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(494, 341);
			this->groupBox4->TabIndex = 14;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Variables to add";
			// 
			// UnselectAllVarVar
			// 
			this->UnselectAllVarVar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->UnselectAllVarVar->Location = System::Drawing::Point(421, 17);
			this->UnselectAllVarVar->Name = L"UnselectAllVarVar";
			this->UnselectAllVarVar->Size = System::Drawing::Size(65, 25);
			this->UnselectAllVarVar->TabIndex = 20;
			this->UnselectAllVarVar->Text = L"Unmark all";
			this->UnselectAllVarVar->UseVisualStyleBackColor = true;
			this->UnselectAllVarVar->Click += gcnew System::EventHandler(this, &MyForm::UnselectAllVarVar_Click);
			// 
			// SelectAllVarVar
			// 
			this->SelectAllVarVar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->SelectAllVarVar->Location = System::Drawing::Point(354, 17);
			this->SelectAllVarVar->Name = L"SelectAllVarVar";
			this->SelectAllVarVar->Size = System::Drawing::Size(65, 25);
			this->SelectAllVarVar->TabIndex = 19;
			this->SelectAllVarVar->Text = L"Mark all";
			this->SelectAllVarVar->UseVisualStyleBackColor = true;
			this->SelectAllVarVar->Click += gcnew System::EventHandler(this, &MyForm::SelectAllVarVar_Click);
			// 
			// UnselectAllVerVeh
			// 
			this->UnselectAllVerVeh->Cursor = System::Windows::Forms::Cursors::Hand;
			this->UnselectAllVerVeh->Location = System::Drawing::Point(179, 17);
			this->UnselectAllVerVeh->Name = L"UnselectAllVerVeh";
			this->UnselectAllVerVeh->Size = System::Drawing::Size(65, 25);
			this->UnselectAllVerVeh->TabIndex = 17;
			this->UnselectAllVerVeh->Text = L"Unmark all";
			this->UnselectAllVerVeh->UseVisualStyleBackColor = true;
			this->UnselectAllVerVeh->Click += gcnew System::EventHandler(this, &MyForm::UnselectAllVerVeh_Click);
			// 
			// SelectAllVarVeh
			// 
			this->SelectAllVarVeh->Cursor = System::Windows::Forms::Cursors::Hand;
			this->SelectAllVarVeh->Location = System::Drawing::Point(112, 17);
			this->SelectAllVarVeh->Name = L"SelectAllVarVeh";
			this->SelectAllVarVeh->Size = System::Drawing::Size(65, 25);
			this->SelectAllVarVeh->TabIndex = 17;
			this->SelectAllVarVeh->Text = L"Mark all";
			this->SelectAllVarVeh->UseVisualStyleBackColor = true;
			this->SelectAllVarVeh->Click += gcnew System::EventHandler(this, &MyForm::SelectAllVarVeh_Click);
			// 
			// InsertVar
			// 
			this->InsertVar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->InsertVar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->InsertVar->Location = System::Drawing::Point(396, 288);
			this->InsertVar->Name = L"InsertVar";
			this->InsertVar->Size = System::Drawing::Size(90, 45);
			this->InsertVar->TabIndex = 18;
			this->InsertVar->Text = L"Add!";
			this->InsertVar->UseVisualStyleBackColor = true;
			this->InsertVar->Click += gcnew System::EventHandler(this, &MyForm::InsertVar_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::Black;
			this->label5->Location = System::Drawing::Point(251, 260);
			this->label5->MaximumSize = System::Drawing::Size(130, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(127, 75);
			this->label5->TabIndex = 17;
			this->label5->Text = L"The variables above are only in the file with modified handling mod for the vehic"
				L"les specified at left.";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// UncommonVarVar
			// 
			this->UncommonVarVar->CheckOnClick = true;
			this->UncommonVarVar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->UncommonVarVar->FormattingEnabled = true;
			this->UncommonVarVar->Location = System::Drawing::Point(248, 44);
			this->UncommonVarVar->Name = L"UncommonVarVar";
			this->UncommonVarVar->Size = System::Drawing::Size(238, 214);
			this->UncommonVarVar->TabIndex = 1;
			// 
			// UncommonVarVehicles
			// 
			this->UncommonVarVehicles->CheckOnClick = true;
			this->UncommonVarVehicles->Cursor = System::Windows::Forms::Cursors::Hand;
			this->UncommonVarVehicles->FormattingEnabled = true;
			this->UncommonVarVehicles->Location = System::Drawing::Point(7, 44);
			this->UncommonVarVehicles->Name = L"UncommonVarVehicles";
			this->UncommonVarVehicles->Size = System::Drawing::Size(237, 289);
			this->UncommonVarVehicles->TabIndex = 0;
			this->UncommonVarVehicles->MouseDown += gcnew Windows::Forms::MouseEventHandler(this, &MyForm::UncommonVarVehicles_MouseDown);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Black;
			this->label4->Location = System::Drawing::Point(12, 3);
			this->label4->MaximumSize = System::Drawing::Size(840, 0);
			this->label4->MinimumSize = System::Drawing::Size(840, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(840, 13);
			this->label4->TabIndex = 13;
			this->label4->Text = L"Add incompatible data may cause crashes in the game. Sometimes an updated gamecon"
				L"fig.xml mod is needed.";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->label7);
			this->groupBox3->Controls->Add(this->UncommonList);
			this->groupBox3->Controls->Add(this->SelectAllInsert);
			this->groupBox3->Controls->Add(this->Insert);
			this->groupBox3->Controls->Add(this->UnselectAllInsert);
			this->groupBox3->Location = System::Drawing::Point(6, 21);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(351, 341);
			this->groupBox3->TabIndex = 0;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Vehicles to add";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::Black;
			this->label7->Location = System::Drawing::Point(251, 16);
			this->label7->MaximumSize = System::Drawing::Size(95, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(95, 120);
			this->label7->TabIndex = 16;
			this->label7->Text = L"Here are the vehicles found on the file with your modified handling data but not "
				L"in the handling.meta that will receive mods.";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// UncommonList
			// 
			this->UncommonList->CheckOnClick = true;
			this->UncommonList->Cursor = System::Windows::Forms::Cursors::Hand;
			this->UncommonList->FormattingEnabled = true;
			this->UncommonList->Location = System::Drawing::Point(7, 44);
			this->UncommonList->Name = L"UncommonList";
			this->UncommonList->Size = System::Drawing::Size(239, 289);
			this->UncommonList->TabIndex = 0;
			this->UncommonList->MouseDown += gcnew Windows::Forms::MouseEventHandler(this, &MyForm::UncommonList_MouseDown);
			// 
			// SelectAllInsert
			// 
			this->SelectAllInsert->Cursor = System::Windows::Forms::Cursors::Hand;
			this->SelectAllInsert->Location = System::Drawing::Point(114, 17);
			this->SelectAllInsert->Name = L"SelectAllInsert";
			this->SelectAllInsert->Size = System::Drawing::Size(65, 25);
			this->SelectAllInsert->TabIndex = 1;
			this->SelectAllInsert->Text = L"Mark all";
			this->SelectAllInsert->UseVisualStyleBackColor = true;
			this->SelectAllInsert->Click += gcnew System::EventHandler(this, &MyForm::SelectAllInsert_Click);
			// 
			// Insert
			// 
			this->Insert->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Insert->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Insert->Location = System::Drawing::Point(253, 289);
			this->Insert->Name = L"Insert";
			this->Insert->Size = System::Drawing::Size(90, 45);
			this->Insert->TabIndex = 14;
			this->Insert->Text = L"Add!";
			this->Insert->UseVisualStyleBackColor = true;
			this->Insert->Click += gcnew System::EventHandler(this, &MyForm::Insert_Click);
			// 
			// UnselectAllInsert
			// 
			this->UnselectAllInsert->Cursor = System::Windows::Forms::Cursors::Hand;
			this->UnselectAllInsert->Location = System::Drawing::Point(181, 17);
			this->UnselectAllInsert->Name = L"UnselectAllInsert";
			this->UnselectAllInsert->Size = System::Drawing::Size(65, 25);
			this->UnselectAllInsert->TabIndex = 2;
			this->UnselectAllInsert->Text = L"Unmark all";
			this->UnselectAllInsert->UseVisualStyleBackColor = true;
			this->UnselectAllInsert->Click += gcnew System::EventHandler(this, &MyForm::UnselectAllInsert_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::Red;
			this->label6->Location = System::Drawing::Point(2, 9);
			this->label6->MaximumSize = System::Drawing::Size(880, 0);
			this->label6->MinimumSize = System::Drawing::Size(880, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(880, 15);
			this->label6->TabIndex = 15;
			this->label6->Text = L"Actions here are not reversible. Backup your handling.meta before anything!";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::WhiteSmoke;
			this->ClientSize = System::Drawing::Size(884, 491);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->DirF2);
			this->Controls->Add(this->DirF1);
			this->Controls->Add(this->SelectHandling);
			this->Controls->Add(this->SelectMod);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(900, 530);
			this->MinimumSize = System::Drawing::Size(900, 530);
			this->Name = L"MyForm";
			this->Text = L"Handling Merger V";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: void openF1(String^ dir, bool printLogs) {
		if (dir == "")
			return;
		this->Cursor = System::Windows::Forms::Cursors::WaitCursor;
		DirF1->Text = dir;
		CommonList->Items->Clear();
		std::string dirS = msclr::interop::marshal_as<std::string>(dir);
		bool success = MTObj.setF1(dirS, printLogs);
		if (!success && printLogs) {
			MessageBox::Show("Fatal error in the selected file. Check \"Handling Merger V logs.txt\" for details.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		std::list<std::string> L = MTObj.common();
		while (!L.empty()) {
			String^ i = gcnew String(L.front().c_str());
			CommonList->Items->Add(i);
			L.pop_front();
		}
		CommonVarList->Items->Clear();
		L = MTObj.getVar();
		while (!L.empty()) {
			String^ i = gcnew String(L.front().c_str());
			CommonVarList->Items->Add(i);
			L.pop_front();
		}
		UncommonList->Items->Clear();
		L = MTObj.uncommon();
		while (!L.empty()) {
			String^ i = gcnew String(L.front().c_str());
			UncommonList->Items->Add(i);
			L.pop_front();
		}
		UncommonVarVar->Items->Clear();
		L = MTObj.uncommonVarVar();
		while (!L.empty()) {
			String^ i = gcnew String(L.front().c_str());
			UncommonVarVar->Items->Add(i);
			L.pop_front();
		}
		UncommonVarVehicles->Items->Clear();
		L = MTObj.uncommonVarVeh();
		while (!L.empty()) {
			String^ i = gcnew String(L.front().c_str());
			UncommonVarVehicles->Items->Add(i);
			L.pop_front();
		}
		this->Cursor = System::Windows::Forms::Cursors::Default;
	}

	private: System::Void SelectMod_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ O = gcnew OpenFileDialog;
		O->Title = "Select the file with the modified handling data to retrieve";
		O->ShowDialog();
		String^ dir = O->FileName;
		openF1(dir, 1);
	}

	private: void openF2(String^ dir, bool printLogs) {
		if (dir == "")
			return;
		this->Cursor = System::Windows::Forms::Cursors::WaitCursor;
		DirF2->Text = dir;
		CommonList->Items->Clear();
		std::string dirS = msclr::interop::marshal_as<std::string>(dir);
		bool success = MTObj.setF2(dirS, printLogs);
		if (!success && printLogs) {
			MessageBox::Show("Fatal error in the selected file. Check \"Handling Merger V logs.txt\" for details.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		std::list<std::string> L = MTObj.common();
		while (!L.empty()) {
			String^ i = gcnew String(L.front().c_str());
			CommonList->Items->Add(i);
			L.pop_front();
		}
		UncommonList->Items->Clear();
		L = MTObj.uncommon();
		while (!L.empty()) {
			String^ i = gcnew String(L.front().c_str());
			UncommonList->Items->Add(i);
			L.pop_front();
		}
		UncommonVarVar->Items->Clear();
		L = MTObj.uncommonVarVar();
		while (!L.empty()) {
			String^ i = gcnew String(L.front().c_str());
			UncommonVarVar->Items->Add(i);
			L.pop_front();
		}
		UncommonVarVehicles->Items->Clear();
		L = MTObj.uncommonVarVeh();
		while (!L.empty()) {
			String^ i = gcnew String(L.front().c_str());
			UncommonVarVehicles->Items->Add(i);
			L.pop_front();
		}
		this->Cursor = System::Windows::Forms::Cursors::Default;
	}

	private: System::Void SelectHandling_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ O = gcnew OpenFileDialog;
		O->Title = "Select the handling.meta file that will receive modded handling data";
		O->ShowDialog();
		String^ dir = O->FileName;
		openF2(dir, 1);
	}
	private: System::Void SelectAll_Click(System::Object^ sender, System::EventArgs^ e) {
		int n = CommonList->Items->Count;
		for (int i = 0; i < n; i++) {
			CommonList->SetItemChecked(i, true);
		}
	}
	private: System::Void UnselectAll_Click(System::Object^ sender, System::EventArgs^ e) {
		int n = CommonList->Items->Count;
		for (int i = 0; i < n; i++) {
			CommonList->SetItemChecked(i, false);
		}
	}
	private: System::Void Merge_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Cursor = System::Windows::Forms::Cursors::WaitCursor;
		std::list<int> Vehicles, Variables;
		int n = CommonList->Items->Count;
		for (int i = 0; i < n; i++) {
			if (CommonList->GetItemChecked(i)) {
				Vehicles.push_back(i);
			}
		}
		n = CommonVarList->Items->Count;
		for (int i = 0; i < n; i++) {
			if (CommonVarList->GetItemChecked(i)) {
				Variables.push_back(i);
			}
		}
		MTObj.merge(Vehicles, Variables);
		CommonList->Items->Clear();
		CommonVarList->Items->Clear();
		UncommonList->Items->Clear();
		UncommonVarVar->Items->Clear();
		UncommonVarVehicles->Items->Clear();
		openF1(DirF1->Text, 0);
		openF2(DirF2->Text, 0);
		this->Cursor = System::Windows::Forms::Cursors::Default;
		MessageBox::Show("Replaced!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void UnselectAllVar_Click(System::Object^ sender, System::EventArgs^ e) {
		int n = CommonVarList->Items->Count;
		for (int i = 0; i < n; i++) {
			CommonVarList->SetItemChecked(i, false);
		}
	}
	private: System::Void SelectAllVar_Click(System::Object^ sender, System::EventArgs^ e) {
		int n = CommonVarList->Items->Count;
		for (int i = 0; i < n; i++) {
			CommonVarList->SetItemChecked(i, true);
		}
	}
	private: System::Void UnselectAllInsert_Click(System::Object^ sender, System::EventArgs^ e) {
		int n = UncommonList->Items->Count;
		for (int i = 0; i < n; i++) {
			UncommonList->SetItemChecked(i, false);
		}
	}
	private: System::Void SelectAllInsert_Click(System::Object^ sender, System::EventArgs^ e) {
		int n = UncommonList->Items->Count;
		for (int i = 0; i < n; i++) {
			UncommonList->SetItemChecked(i, true);
		}
	}
	private: System::Void Insert_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Cursor = System::Windows::Forms::Cursors::WaitCursor;
		std::list<int> Vehicles;
		int n = UncommonList->Items->Count;
		for (int i = 0; i < n; i++) {
			if (UncommonList->GetItemChecked(i)) {
				Vehicles.push_back(i);
			}
		}
		MTObj.insert(Vehicles);
		CommonList->Items->Clear();
		CommonVarList->Items->Clear();
		UncommonList->Items->Clear();
		UncommonVarVar->Items->Clear();
		UncommonVarVehicles->Items->Clear();
		openF1(DirF1->Text, 0);
		openF2(DirF2->Text, 0);
		this->Cursor = System::Windows::Forms::Cursors::Default;
		MessageBox::Show("Added!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	private: System::Void SelectAllVarVeh_Click(System::Object^ sender, System::EventArgs^ e) {
		int n = UncommonVarVehicles->Items->Count;
		for (int i = 0; i < n; i++) {
			UncommonVarVehicles->SetItemChecked(i, true);
		}
	}
	private: System::Void UnselectAllVerVeh_Click(System::Object^ sender, System::EventArgs^ e) {
		int n = UncommonVarVehicles->Items->Count;
		for (int i = 0; i < n; i++) {
			UncommonVarVehicles->SetItemChecked(i, false);
		}
	}
	private: System::Void SelectAllVarVar_Click(System::Object^ sender, System::EventArgs^ e) {
		int n = UncommonVarVar->Items->Count;
		for (int i = 0; i < n; i++) {
			UncommonVarVar->SetItemChecked(i, true);
		}
	}
	private: System::Void UnselectAllVarVar_Click(System::Object^ sender, System::EventArgs^ e) {
		int n = UncommonVarVar->Items->Count;
		for (int i = 0; i < n; i++) {
			UncommonVarVar->SetItemChecked(i, false);
		}
	}
	private: System::Void InsertVar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Cursor = System::Windows::Forms::Cursors::WaitCursor;
		std::list<int> Vehicles, Variables;
		int n = UncommonVarVehicles->Items->Count;
		for (int i = 0; i < n; i++) {
			if (UncommonVarVehicles->GetItemChecked(i)) {
				Vehicles.push_back(i);
			}
		}
		n = UncommonVarVar->Items->Count;
		for (int i = 0; i < n; i++) {
			if (UncommonVarVar->GetItemChecked(i)) {
				Variables.push_back(i);
			}
		}
		MTObj.insertVar(Vehicles, Variables);
		CommonList->Items->Clear();
		CommonVarList->Items->Clear();
		UncommonList->Items->Clear();
		UncommonVarVar->Items->Clear();
		UncommonVarVehicles->Items->Clear();
		openF1(DirF1->Text, 0);
		openF2(DirF2->Text, 0);
		this->Cursor = System::Windows::Forms::Cursors::Default;
		MessageBox::Show("Added!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

	private: System::Void CommonList_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
		if (e->Button == System::Windows::Forms::MouseButtons::Right)
		{
			currentSelectedInCLB = CommonList->IndexFromPoint(CommonList->PointToClient(this->MousePosition));
			currentCLB = CommonList;
			if (currentSelectedInCLB == -1)
				return;
			System::Windows::Forms::ContextMenu^ cms = gcnew System::Windows::Forms::ContextMenu;
			cms->MenuItems->Add("Mark all from this category", gcnew System::EventHandler(this, &MyForm::CommonList_LeftMarkClick));
			cms->MenuItems->Add("Unmark all from this category", gcnew System::EventHandler(this, &MyForm::CommonList_LeftUnmarkClick));
			cms->Show(this, this->PointToClient(this->MousePosition));
		}
	}

	private: System::Void UncommonList_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Right)
		{
			currentSelectedInCLB = UncommonList->IndexFromPoint(UncommonList->PointToClient(this->MousePosition));
			currentCLB = UncommonList;
			if (currentSelectedInCLB == -1)
				return;
			System::Windows::Forms::ContextMenu^ cms = gcnew System::Windows::Forms::ContextMenu;
			cms->MenuItems->Add("Mark all from this category", gcnew System::EventHandler(this, &MyForm::CommonList_LeftMarkClick));
			cms->MenuItems->Add("Unmark all from this category", gcnew System::EventHandler(this, &MyForm::CommonList_LeftUnmarkClick));
			cms->Show(this, this->PointToClient(this->MousePosition));
		}
	}

	private: System::Void UncommonVarVehicles_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Right)
		{
			currentSelectedInCLB = UncommonVarVehicles->IndexFromPoint(UncommonVarVehicles->PointToClient(this->MousePosition));
			currentCLB = UncommonVarVehicles;
			if (currentSelectedInCLB == -1)
				return;
			System::Windows::Forms::ContextMenu^ cms = gcnew System::Windows::Forms::ContextMenu;
			cms->MenuItems->Add("Mark all from this category", gcnew System::EventHandler(this, &MyForm::CommonList_LeftMarkClick));
			cms->MenuItems->Add("Unmark all from this category", gcnew System::EventHandler(this, &MyForm::CommonList_LeftUnmarkClick));
			cms->Show(this, this->PointToClient(this->MousePosition));
		}
	}

	private: string getCat(int i) {
		String^ a = this->currentCLB->GetItemText(this->currentCLB->Items[i]);
		std::string b = msclr::interop::marshal_as<std::string>(a);
		std::string c = "";
		if (b.find("]") != string::npos) {
			c = b.substr(1, b.find("]") - 1);
		}
		return c;
	}

	private: System::Void CommonList_LeftMarkClick(System::Object^ sender, System::EventArgs^ e) {
		string x = getCat(currentSelectedInCLB);
		if (x == "")
			return;
		int n = currentCLB->Items->Count;
		for (int i = 0; i < n; i++) {
			if (getCat(i) == x) {
				currentCLB->SetItemChecked(i, true);
			}
		}
	}

	private: System::Void CommonList_LeftUnmarkClick(System::Object^ sender, System::EventArgs^ e) {
		string x = getCat(currentSelectedInCLB);
		if (x == "")
			return;
		int n = currentCLB->Items->Count;
		for (int i = 0; i < n; i++) {
			if (getCat(i) == x) {
				currentCLB->SetItemChecked(i, false);
			}
		}
	}

	};

}