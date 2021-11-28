#include "MainForm.h"


System::Void SimpleDiskAnalysis::MainForm::aboutMenuItemClick(System::Object^ sender, System::EventArgs^ e) {
	AboutForm^ aboutForm = gcnew AboutForm;
	aboutForm->Show();
}

System::Void SimpleDiskAnalysis::MainForm::mainFormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	System::Windows::Forms::DialogResult result = MessageBox::Show("Ви дійсно хочете закрити додаток?", "Увага!", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
	if (result != System::Windows::Forms::DialogResult::Yes) {
		e->Cancel = true;
	}
}

System::Void SimpleDiskAnalysis::MainForm::mainFormLoad(System::Object^ sender, System::EventArgs^ e) {
	this->setStatusValue();  // if the method is called without args, they will be default
}

System::Void SimpleDiskAnalysis::MainForm::startButtonClick(System::Object^ sender, System::EventArgs^ e) {
	this->setStatusValue("аналіз триває...", System::Drawing::Color::Yellow);
	Windows::Forms::DialogResult result = choseFolderToAnalyze->ShowDialog();
	if (result == Windows::Forms::DialogResult::OK) {
		Analysis^ analysis = gcnew Analysis(choseFolderToAnalyze->SelectedPath, this->analysisInformation);
		analysis->execute();
		this->setStatusValue("аналіз успішно завершено!", System::Drawing::Color::Green);
	}
}

System::Void SimpleDiskAnalysis::MainForm::infoMenuItemClick(System::Object^ sender, System::EventArgs^ e)
{
	InfoForm^ infoForm = gcnew InfoForm;
	infoForm->Show();
}

System::Void SimpleDiskAnalysis::MainForm::setStatusValue(String^ text, System::Drawing::Color color)
{
	this->statusValueLabel->Text = text;
	this->statusValueLabel->ForeColor = color;
}

System::Void SimpleDiskAnalysis::MainForm::setStatusValue()
{
	this->setStatusValue("аналіз не розпочато", System::Drawing::Color::Gray);
}
