#include "InfoForm.h"
#include "helpers.h"

System::Void SimpleDiskAnalysis::InfoForm::loadInfoForm(System::Object^ sender, System::EventArgs^ e)
{
	this->disksInformation->Text = Helpers::getDisksInfoString();
}
