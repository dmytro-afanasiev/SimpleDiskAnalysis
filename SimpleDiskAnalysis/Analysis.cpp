#include "Analysis.h"

Analysis::Analysis(String^ rootPath, System::Windows::Forms::TextBox^% outTextBox)
{
    this->id = Helpers::generateUuid();
    this->rootPath = rootPath;
    this->outTextBox = outTextBox;
    this->files = gcnew List<FileMeta^>(50);
}

System::Void Analysis::execute()
{
    std::string standartRootPath = Helpers::toStandartString(this->rootPath);
    for (const fs::directory_entry& entry : fs::recursive_directory_iterator(standartRootPath, fs::directory_options::skip_permission_denied)) {
        if (!entry.is_directory()) {
            FileMeta^ fileMeta = gcnew FileMeta(gcnew String(entry.path().c_str()), entry.file_size());
            this->files->Add(fileMeta);
            this->outTextBox->AppendText(fileMeta->getInfoString());
        }
    }
    this->finished = true;
}

String^ Analysis::getId()
{
    return this->id;
}

uintmax_t Analysis::getWholeSize()
{
    uintmax_t result = 0;
    List<FileMeta^>::Enumerator e  = this->files->GetEnumerator();
    while (e.MoveNext()) {
        result += e.Current->getFileSize();
    }
    return result;
}

String^ Analysis::getRootPath()
{
    return this->rootPath;
}

String^ Analysis::getWholeHumanSize()
{
    uintmax_t wholeSize = this->getWholeSize();
    return Helpers::bytesToHumanSize(wholeSize);
}

String^ Analysis::getReport()
{
    List<String^>^ infoLines = gcnew List<String^>(10);
    infoLines->Add(String::Format("ID аналізу: \"{0}\";", this->getId()));
    infoLines->Add(String::Format("Статус аналізу: \"{0}\";", this->isFinished() ? "завершений" : "не завершений (це смс не з'явиться ніколи)"));
    infoLines->Add(String::Format("Кореневий шлях: \"{0}\";", this->getRootPath()));
    infoLines->Add(String::Format("Кількість проаналізованих файлів: {0};", this->getNumberOfAnalysedFiles()));
    infoLines->Add(L"Інформація по типам файлів:");
    
    Dictionary<String^, ExtensionSpreading^>^ spreading =  this->calculateExtensionsSpreading();
    Dictionary<String^, ExtensionSpreading^>::Enumerator e = spreading->GetEnumerator();
    while (e.MoveNext()) {
        infoLines->Add(String::Format("  {0}: кількість файлів: {1}, загальна вага: {2};", e.Current.Key, e.Current.Value->numberOffiles, e.Current.Value->getWholeHumanSize()));
    }
    String^ result = String::Join(System::Environment::NewLine, infoLines);
    return result;
}

bool Analysis::isFinished()
{
    return this->finished;
}

int Analysis::getNumberOfAnalysedFiles()
{
    return this->files->Count;
}

Dictionary<String^, ExtensionSpreading^>^% Analysis::calculateExtensionsSpreading()
{
    Dictionary<String^, ExtensionSpreading^>^ result = gcnew Dictionary<String^, ExtensionSpreading^>;
    List<FileMeta^>::Enumerator e = this->files->GetEnumerator();
    while (e.MoveNext()) {
        String^ extension = e.Current->hasExtension() ? e.Current->getExtention() : ZERO_EXTENSION;
        if (!result->ContainsKey(extension)) {
            result[extension] = gcnew ExtensionSpreading;
        }
        result[extension]->numberOffiles++;
        result[extension]->sizeOfFilesThisExtension += e.Current->getFileSize();
    }
    return result;
}

String^ ExtensionSpreading::getWholeHumanSize()
{
    return Helpers::bytesToHumanSize(this->sizeOfFilesThisExtension);
}
