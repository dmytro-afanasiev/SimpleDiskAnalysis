#pragma once
#include "AboutForm.h"
#include "InfoForm.h"
#include "helpers.h"
#include "FileMeta.h"
#include "Analysis.h"

namespace SimpleDiskAnalysis {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;
	using namespace System::Collections::Generic;

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
	private: System::Windows::Forms::Button^ startButton;

	private: System::Windows::Forms::FolderBrowserDialog^ choseFolderToAnalyze;
	private: System::Windows::Forms::TextBox^ analysisInformation;
	private: System::Windows::Forms::Label^ statusLabel;
	private: System::Windows::Forms::Label^ statusValueLabel;
	private: System::Windows::Forms::Button^ clearButton;
	private: System::Windows::Forms::ToolStripMenuItem^ openMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ saveMenuItem;


	private: System::Windows::Forms::ToolStripMenuItem^ infoMenuItem;






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
			this->startButton = (gcnew System::Windows::Forms::Button());
			this->choseFolderToAnalyze = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->analysisInformation = (gcnew System::Windows::Forms::TextBox());
			this->statusLabel = (gcnew System::Windows::Forms::Label());
			this->statusValueLabel = (gcnew System::Windows::Forms::Label());
			this->clearButton = (gcnew System::Windows::Forms::Button());
			this->openMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->infoMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->menu->Size = System::Drawing::Size(814, 28);
			this->menu->TabIndex = 0;
			this->menu->Text = L"menuText";
			// 
			// fileMenuItem
			// 
			this->fileMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->openMenuItem,
					this->saveMenuItem, this->infoMenuItem
			});
			this->fileMenuItem->Name = L"fileMenuItem";
			this->fileMenuItem->Size = System::Drawing::Size(57, 24);
			this->fileMenuItem->Text = L"Файл";
			// 
			// helpMenuItem
			// 
			this->helpMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->aboutMenuItem });
			this->helpMenuItem->Name = L"helpMenuItem";
			this->helpMenuItem->Size = System::Drawing::Size(80, 24);
			this->helpMenuItem->Text = L"Справка";
			// 
			// aboutMenuItem
			// 
			this->aboutMenuItem->Name = L"aboutMenuItem";
			this->aboutMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::A));
			this->aboutMenuItem->Size = System::Drawing::Size(231, 26);
			this->aboutMenuItem->Text = L"Про програму";
			this->aboutMenuItem->Click += gcnew System::EventHandler(this, &MainForm::aboutMenuItemClick);
			// 
			// startButton
			// 
			this->startButton->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->startButton->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->startButton->Font = (gcnew System::Drawing::Font(L"Arial", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->startButton->Location = System::Drawing::Point(172, 62);
			this->startButton->Name = L"startButton";
			this->startButton->Size = System::Drawing::Size(449, 45);
			this->startButton->TabIndex = 2;
			this->startButton->Text = L"Розпочати аналіз";
			this->startButton->UseVisualStyleBackColor = false;
			this->startButton->Click += gcnew System::EventHandler(this, &MainForm::startButtonClick);
			// 
			// choseFolderToAnalyze
			// 
			this->choseFolderToAnalyze->Description = L"Виберіть папку для аналізу";
			this->choseFolderToAnalyze->RootFolder = System::Environment::SpecialFolder::MyComputer;
			this->choseFolderToAnalyze->ShowNewFolderButton = false;
			// 
			// analysisInformation
			// 
			this->analysisInformation->BackColor = System::Drawing::SystemColors::ControlLight;
			this->analysisInformation->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->analysisInformation->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->analysisInformation->Location = System::Drawing::Point(30, 155);
			this->analysisInformation->MaxLength = 2147483647;
			this->analysisInformation->Multiline = true;
			this->analysisInformation->Name = L"analysisInformation";
			this->analysisInformation->ReadOnly = true;
			this->analysisInformation->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->analysisInformation->Size = System::Drawing::Size(771, 308);
			this->analysisInformation->TabIndex = 3;
			// 
			// statusLabel
			// 
			this->statusLabel->AutoSize = true;
			this->statusLabel->Font = (gcnew System::Drawing::Font(L"Arial", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->statusLabel->Location = System::Drawing::Point(29, 473);
			this->statusLabel->Name = L"statusLabel";
			this->statusLabel->Size = System::Drawing::Size(70, 19);
			this->statusLabel->TabIndex = 4;
			this->statusLabel->Text = L"Статус:";
			// 
			// statusValueLabel
			// 
			this->statusValueLabel->AutoSize = true;
			this->statusValueLabel->Font = (gcnew System::Drawing::Font(L"Arial", 10.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->statusValueLabel->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->statusValueLabel->Location = System::Drawing::Point(96, 473);
			this->statusValueLabel->Name = L"statusValueLabel";
			this->statusValueLabel->Size = System::Drawing::Size(68, 19);
			this->statusValueLabel->TabIndex = 5;
			this->statusValueLabel->Text = L"[layout]";
			// 
			// clearButton
			// 
			this->clearButton->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->clearButton->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->clearButton->Font = (gcnew System::Drawing::Font(L"Arial", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->clearButton->Location = System::Drawing::Point(647, 467);
			this->clearButton->Name = L"clearButton";
			this->clearButton->Size = System::Drawing::Size(136, 32);
			this->clearButton->TabIndex = 6;
			this->clearButton->Text = L"Очистити";
			this->clearButton->UseVisualStyleBackColor = false;
			this->clearButton->Click += gcnew System::EventHandler(this, &MainForm::clearButtonClick);
			// 
			// openMenuItem
			// 
			this->openMenuItem->Name = L"openMenuItem";
			this->openMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
			this->openMenuItem->Size = System::Drawing::Size(224, 26);
			this->openMenuItem->Text = L"Відкрити";
			// 
			// saveMenuItem
			// 
			this->saveMenuItem->Name = L"saveMenuItem";
			this->saveMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->saveMenuItem->Size = System::Drawing::Size(224, 26);
			this->saveMenuItem->Text = L"Зберегти";
			// 
			// infoMenuItem
			// 
			this->infoMenuItem->Name = L"infoMenuItem";
			this->infoMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::I));
			this->infoMenuItem->Size = System::Drawing::Size(224, 26);
			this->infoMenuItem->Text = L"Інфо";
			this->infoMenuItem->Click += gcnew System::EventHandler(this, &MainForm::infoMenuItemClick);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->ClientSize = System::Drawing::Size(814, 511);
			this->Controls->Add(this->clearButton);
			this->Controls->Add(this->statusValueLabel);
			this->Controls->Add(this->statusLabel);
			this->Controls->Add(this->analysisInformation);
			this->Controls->Add(this->startButton);
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

	private: System::Void mainFormLoad(System::Object^ sender, System::EventArgs^ e);

	private: System::Void aboutMenuItemClick(System::Object^ sender, System::EventArgs^ e);

	private: System::Void mainFormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
	private: System::Void startButtonClick(System::Object^ sender, System::EventArgs^ e);
	private: System::Void infoMenuItemClick(System::Object^ sender, System::EventArgs^ e);

	private: System::Void setStatusValue(String^ text, System::Drawing::Color color);
	private: System::Void setStatusValue();

	private: System::Void clearButtonClick(System::Object^ sender, System::EventArgs^ e);
	};
}

