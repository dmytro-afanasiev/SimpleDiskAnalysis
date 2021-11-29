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



bool SimpleDiskAnalysis::MainForm::isCurrentAnalysis()
{
	if (MainForm::currentAnalysis == nullptr) {
		return false;
	}
	return true;
}

System::Void SimpleDiskAnalysis::MainForm::setCurrentAnalysis(Analysis^% analysis)
{
	MainForm::currentAnalysis = analysis;
}

System::Void SimpleDiskAnalysis::MainForm::setCurrentAnalysis()
{
	MainForm::currentAnalysis = nullptr;
}

Analysis^% SimpleDiskAnalysis::MainForm::getCurrentAnalysis()
{
	return MainForm::currentAnalysis;
}

System::Void SimpleDiskAnalysis::MainForm::setAnalysisChosen(Analysis^% analysis, bool isLoaded)
{
	MainForm::setCurrentAnalysis(analysis);
	this->resultsButton->Enabled = true;
	if (isLoaded) {
		List<FileMeta^>::Enumerator e = analysis->getFiles()->GetEnumerator();
		String^ result = "";
		while (e.MoveNext()) {
			result = result + e.Current->getInfoString();
		}
		this->analysisInformation->Text = result;
		this->setStatusValue("аналіз успішно завантажено!", System::Drawing::Color::Green);
		return;
	}
	this->setStatusValue("аналіз успішно завершено!", System::Drawing::Color::Green);
}

System::Void SimpleDiskAnalysis::MainForm::setAnalysisNotChosen()
{
	MainForm::setCurrentAnalysis();  // set it to nullptr - look above..
	this->resultsButton->Enabled = false;
	this->setStatusValue();
	this->analysisInformation->Text = L"";
}

System::Void SimpleDiskAnalysis::MainForm::mainFormLoad(System::Object^ sender, System::EventArgs^ e) {
	this->setAnalysisNotChosen();  // if the method is called without args, they will be default
}

System::Void SimpleDiskAnalysis::MainForm::startButtonClick(System::Object^ sender, System::EventArgs^ e) {
	
	if (MainForm::isCurrentAnalysis()) {
		System::Windows::Forms::DialogResult result = MessageBox::Show("Спочатку збережіть або очистіть результати поточного аналізу", "Увага!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}
	this->setStatusValue("аналіз триває...", System::Drawing::Color::Brown);
	Windows::Forms::DialogResult result = choseFolderToAnalyze->ShowDialog();
	if (result == Windows::Forms::DialogResult::OK) {
		Analysis^ analysis = gcnew Analysis(choseFolderToAnalyze->SelectedPath, this->analysisInformation);
		analysis->execute();
		
		this->setAnalysisChosen(analysis, false);
	}
	else {
		this->setAnalysisNotChosen();
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

System::Void SimpleDiskAnalysis::MainForm::clearButtonClick(System::Object^ sender, System::EventArgs^ e)
{
	System::Windows::Forms::DialogResult result = MessageBox::Show("Ви дійсно хочете очистити результати аналізу?", "Увага!", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
	if (result == System::Windows::Forms::DialogResult::Yes) {
		this->setAnalysisNotChosen();
	}
}

System::Void SimpleDiskAnalysis::MainForm::resultsButtonClick(System::Object^ sender, System::EventArgs^ e)
{
	ResultsForm^ resultsForm = gcnew ResultsForm;
	resultsForm->Show();
}

System::Void SimpleDiskAnalysis::MainForm::openButtonClick(System::Object^ sender, System::EventArgs^ e)
{
	if (MainForm::isCurrentAnalysis()) {
		System::Windows::Forms::DialogResult result = MessageBox::Show("Спочатку збережіть або очистіть результати поточного аналізу", "Увага!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}
	Windows::Forms::DialogResult result = this->choseFileToOpenAnalysis->ShowDialog();
	if (result == Windows::Forms::DialogResult::OK) {
		FileStream^ fileStream = gcnew FileStream(this->choseFileToOpenAnalysis->FileName, FileMode::Open);
		BinaryFormatter^ binaryFormatter = gcnew BinaryFormatter();
		Analysis^ analysis = dynamic_cast<Analysis^>(binaryFormatter->Deserialize(fileStream));
		fileStream->Close();
		this->setAnalysisChosen(analysis, true);
	}
}

System::Void SimpleDiskAnalysis::MainForm::saveButtonClick(System::Object^ sender, System::EventArgs^ e)
{
	if (!MainForm::isCurrentAnalysis()) {
		System::Windows::Forms::DialogResult result = MessageBox::Show("Спочатку розпочніть аналіз", "Увага!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}
	Analysis^ analysis = MainForm::getCurrentAnalysis();
	this->choseFileToSaveAnalysis->FileName = analysis->getId();
	Windows::Forms::DialogResult result = this->choseFileToSaveAnalysis->ShowDialog();
	if (result == Windows::Forms::DialogResult::OK) {
		FileStream^ fileStream = gcnew FileStream(this->choseFileToSaveAnalysis->FileName, FileMode::Create);
		BinaryFormatter^ binaryFormatter = gcnew BinaryFormatter;
		binaryFormatter->Serialize(fileStream, analysis);
		fileStream->Close();
	}
}
