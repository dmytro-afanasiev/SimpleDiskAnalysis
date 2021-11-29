#include "FileMeta.h"

FileMeta::FileMeta(String^ pathToFile, uintmax_t fileSize, String^ extension)
{
	this->pathToFile = pathToFile;
    this->fileSize = fileSize;
	this->extension = extension;
}

FileMeta::FileMeta(const FileMeta^& another)
{
	this->pathToFile = another->pathToFile;
	this->fileSize = another->fileSize;
	this->extension = another->extension;
}

String^ FileMeta::getPathToFile()
{
    return this->pathToFile;
}

uintmax_t FileMeta::getFileSize()
{
    return this->fileSize;
}

String^ FileMeta::getHumanSize()
{
	return Helpers::bytesToHumanSize(this->fileSize);
}

String^ FileMeta::getInfoString()
{
	return gcnew String(this->getPathToFile() + L" - " + this->getHumanSize() + System::Environment::NewLine);
}

bool FileMeta::hasExtension()
{
	return !this->extension->Equals(L"");
}

String^ FileMeta::getExtention()
{
	return this->extension;
}
