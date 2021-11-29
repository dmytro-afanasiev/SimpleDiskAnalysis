#include "Analysis.h"

Analysis::Analysis(String^ rootPath, System::Windows::Forms::TextBox^% outTextBox)
{
    this->id = Helpers::generateUuid();
    this->rootPath = rootPath;
    this->outTextBox = outTextBox;
}

System::Void Analysis::execute()
{
    std::string standartRootPath = Helpers::toStandartString(this->rootPath);
    for (const fs::directory_entry& entry : fs::recursive_directory_iterator(standartRootPath, fs::directory_options::skip_permission_denied)) {
        if (!entry.is_directory()) {
            FileMeta^ fileMeta = gcnew FileMeta(gcnew String(entry.path().c_str()), entry.file_size());
            this->outTextBox->AppendText(fileMeta->getInfoString());
            
        }
    }
}

String^ Analysis::getId()
{
    return this->id;
}
