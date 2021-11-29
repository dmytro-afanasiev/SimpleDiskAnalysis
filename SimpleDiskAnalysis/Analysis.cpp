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

String^ Analysis::getWholeHumanSize()
{
    uintmax_t wholeSize = this->getWholeSize();
    return Helpers::bytesToHumanSize(wholeSize);
}

