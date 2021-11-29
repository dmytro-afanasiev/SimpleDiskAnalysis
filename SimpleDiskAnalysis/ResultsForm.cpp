#include "ResultsForm.h"

System::Void SimpleDiskAnalysis::ResultsForm::loadResultForm(System::Object^ sender, System::EventArgs^ e)
{
	Analysis^ analysis = MainForm::getCurrentAnalysis();
	this->Text = this->Text + "\"" + analysis->getId() + "\"";

	this->reportInformation->Text = analysis->getReport();
}
