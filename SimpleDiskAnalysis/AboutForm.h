#pragma once

namespace SimpleDiskAnalysis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AboutForm
	/// </summary>
	public ref class AboutForm : public System::Windows::Forms::Form
	{
	public:
		AboutForm(void)
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
		~AboutForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ mainInformation;
	private: System::Windows::Forms::Button^ understandButton;
	private: System::Windows::Forms::Label^ authorLabel;



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AboutForm::typeid));
			this->mainInformation = (gcnew System::Windows::Forms::TextBox());
			this->understandButton = (gcnew System::Windows::Forms::Button());
			this->authorLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// mainInformation
			// 
			this->mainInformation->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->mainInformation->Enabled = false;
			this->mainInformation->Font = (gcnew System::Drawing::Font(L"Arial", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->mainInformation->ForeColor = System::Drawing::SystemColors::InfoText;
			this->mainInformation->Location = System::Drawing::Point(12, 12);
			this->mainInformation->Multiline = true;
			this->mainInformation->Name = L"mainInformation";
			this->mainInformation->ReadOnly = true;
			this->mainInformation->Size = System::Drawing::Size(570, 211);
			this->mainInformation->TabIndex = 0;
			this->mainInformation->Text = resources->GetString(L"mainInformation.Text");
			// 
			// understandButton
			// 
			this->understandButton->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->understandButton->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->understandButton->Font = (gcnew System::Drawing::Font(L"Arial", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->understandButton->Location = System::Drawing::Point(12, 271);
			this->understandButton->Name = L"understandButton";
			this->understandButton->Size = System::Drawing::Size(570, 45);
			this->understandButton->TabIndex = 1;
			this->understandButton->Text = L"Погоджуюся";
			this->understandButton->UseVisualStyleBackColor = false;
			this->understandButton->Click += gcnew System::EventHandler(this, &AboutForm::understandButtonClick);
			// 
			// authorLabel
			// 
			this->authorLabel->AutoSize = true;
			this->authorLabel->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->authorLabel->Location = System::Drawing::Point(264, 226);
			this->authorLabel->Name = L"authorLabel";
			this->authorLabel->Size = System::Drawing::Size(318, 18);
			this->authorLabel->TabIndex = 2;
			this->authorLabel->Text = L"Афанасьєв Дмитро Андрійович, 27.11.2021";
			// 
			// AboutForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(594, 328);
			this->Controls->Add(this->authorLabel);
			this->Controls->Add(this->understandButton);
			this->Controls->Add(this->mainInformation);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"AboutForm";
			this->Text = L"Про програму";
			this->Load += gcnew System::EventHandler(this, &AboutForm::AboutForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void AboutForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void understandButtonClick(System::Object^ sender, System::EventArgs^ e) {
		AboutForm::Close();
	}
	};
}
