#pragma once
#include "MainForm.h"

namespace SimpleDiskAnalysis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ResultsForm
	/// </summary>
	public ref class ResultsForm : public System::Windows::Forms::Form
	{
	public:
		ResultsForm(void)
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
		~ResultsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ reportInformation;
	private: System::Windows::Forms::Label^ reportTitle;
	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ResultsForm::typeid));
			this->reportInformation = (gcnew System::Windows::Forms::TextBox());
			this->reportTitle = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// reportInformation
			// 
			this->reportInformation->BackColor = System::Drawing::SystemColors::ControlLight;
			this->reportInformation->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->reportInformation->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->reportInformation->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->reportInformation->Location = System::Drawing::Point(28, 60);
			this->reportInformation->MaxLength = 32000;
			this->reportInformation->Multiline = true;
			this->reportInformation->Name = L"reportInformation";
			this->reportInformation->ReadOnly = true;
			this->reportInformation->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->reportInformation->Size = System::Drawing::Size(642, 314);
			this->reportInformation->TabIndex = 4;
			// 
			// reportTitle
			// 
			this->reportTitle->AutoSize = true;
			this->reportTitle->Font = (gcnew System::Drawing::Font(L"Arial", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->reportTitle->Location = System::Drawing::Point(270, 20);
			this->reportTitle->Name = L"reportTitle";
			this->reportTitle->Size = System::Drawing::Size(145, 21);
			this->reportTitle->TabIndex = 5;
			this->reportTitle->Text = L"«в≥т по анал≥зу";
			// 
			// ResultsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(682, 386);
			this->Controls->Add(this->reportTitle);
			this->Controls->Add(this->reportInformation);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"ResultsForm";
			this->Text = L"«в≥т по анал≥зу ";
			this->Load += gcnew System::EventHandler(this, &ResultsForm::loadResultForm);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void loadResultForm(System::Object^ sender, System::EventArgs^ e);

	};
}
