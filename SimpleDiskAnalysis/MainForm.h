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
			this->menu->Size = System::Drawing::Size(814, 30);
			this->menu->TabIndex = 0;
			this->menu->Text = L"menuText";
			// 
			// fileMenuItem
			// 
			this->fileMenuItem->Name = L"fileMenuItem";
			this->fileMenuItem->Size = System::Drawing::Size(57, 26);
			this->fileMenuItem->Text = L"Файл";
			// 
			// helpMenuItem
			// 
			this->helpMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->aboutMenuItem });
			this->helpMenuItem->Name = L"helpMenuItem";
			this->helpMenuItem->Size = System::Drawing::Size(80, 26);
			this->helpMenuItem->Text = L"Справка";
			// 
			// aboutMenuItem
			// 
			this->aboutMenuItem->Name = L"aboutMenuItem";
			this->aboutMenuItem->Size = System::Drawing::Size(182, 26);
			this->aboutMenuItem->Text = L"Про програму";
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
};
}
