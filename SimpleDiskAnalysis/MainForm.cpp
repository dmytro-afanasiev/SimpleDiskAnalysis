#include "MainForm.h"
#include <Windows.h>

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

System::Void SimpleDiskAnalysis::MainForm::startButtonClick(System::Object^ sender, System::EventArgs^ e) {
	
}
