#include "MainForm.h"


System::Void SimpleDiskAnalysis::MainForm::aboutMenuItemClick(System::Object^ sender, System::EventArgs^ e) {
	AboutForm^ aboutForm = gcnew AboutForm;
	aboutForm->Show();
}

System::Void SimpleDiskAnalysis::MainForm::mainFormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	System::Windows::Forms::DialogResult result = MessageBox::Show("�� ����� ������ ������� �������?", "�����!", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
	if (result != System::Windows::Forms::DialogResult::Yes) {
		e->Cancel = true;
	}
}

System::Void SimpleDiskAnalysis::MainForm::mainFormLoad(System::Object^ sender, System::EventArgs^ e) {
}


System::Void SimpleDiskAnalysis::MainForm::startButtonClick(System::Object^ sender, System::EventArgs^ e) {
	Windows::Forms::DialogResult result = choseFolderToAnalyze->ShowDialog();
	if (result == Windows::Forms::DialogResult::OK) {
		Analysis^ analysis = gcnew Analysis(choseFolderToAnalyze->SelectedPath, this->analysisInformation);
		analysis->execute();
	}
}

System::Void SimpleDiskAnalysis::MainForm::infoMenuItemClick(System::Object^ sender, System::EventArgs^ e)
{
	InfoForm^ infoForm = gcnew InfoForm;
	infoForm->Show();
}
