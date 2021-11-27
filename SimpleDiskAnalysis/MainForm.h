#pragma once
#include "AboutForm.h"

namespace SimpleDiskAnalysis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menu;
	private: System::Windows::Forms::ToolStripMenuItem^ fileMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ helpMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ aboutMenuItem;

	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->menu = (gcnew System::Windows::Forms::MenuStrip());
			this->fileMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu->SuspendLayout();
			this->SuspendLayout();
			// 
			// menu
			// 
			this->menu->BackColor = System::Drawing::SystemColors::ControlLight;
			this->menu->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->menu->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->fileMenuItem, this->helpMenuItem });
			this->menu->Location = System::Drawing::Point(0, 0);
			this->menu->Name = L"menu";
			this->menu->Size = System::Drawing::Size(814, 25);
			this->menu->TabIndex = 0;
			this->menu->Text = L"menuText";
			// 
			// fileMenuItem
			// 
			this->fileMenuItem->Name = L"fileMenuItem";
			this->fileMenuItem->Size = System::Drawing::Size(57, 21);
			this->fileMenuItem->Text = L"����";
			// 
			// helpMenuItem
			// 
			this->helpMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->aboutMenuItem });
			this->helpMenuItem->Name = L"helpMenuItem";
			this->helpMenuItem->Size = System::Drawing::Size(80, 21);
			this->helpMenuItem->Text = L"�������";
			// 
			// aboutMenuItem
			// 
			this->aboutMenuItem->Name = L"aboutMenuItem";
			this->aboutMenuItem->Size = System::Drawing::Size(224, 26);
			this->aboutMenuItem->Text = L"��� ��������";
			this->aboutMenuItem->Click += gcnew System::EventHandler(this, &MainForm::aboutMenuItemClick);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->ClientSize = System::Drawing::Size(814, 504);
			this->Controls->Add(this->menu);
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MainForm";
			this->Text = L"Simple Disk Analysis";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::mainFormClosing);
			this->Load += gcnew System::EventHandler(this, &MainForm::mainFormLoad);
			this->menu->ResumeLayout(false);
			this->menu->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void mainFormLoad(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void aboutMenuItemClick(System::Object^ sender, System::EventArgs^ e) {
		AboutForm^ aboutForm = gcnew AboutForm;
		aboutForm->Show();
	}
	private: System::Void mainFormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		System::Windows::Forms::DialogResult result = MessageBox::Show("�� ����� ������ ������� �������?", "�����!", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
		if (result != System::Windows::Forms::DialogResult::Yes) {
			e->Cancel = true;
		}
	}
	};
}

