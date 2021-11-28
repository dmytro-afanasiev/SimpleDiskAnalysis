#include "FileMeta.h"

FileMeta::FileMeta(String^ pathToFile, uintmax_t fileSize)
{
	this->pathToFile = pathToFile;
    this->fileSize = fileSize;
}

FileMeta::FileMeta(const FileMeta^& another)
{
	this->pathToFile = another->pathToFile;
	this->fileSize = another->fileSize;
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
	if (this->fileSize == 0) {
		return gcnew String("0 B");
	}
	int logBase = 1024;
	char* suffixes[] = { "B", "KB", "MB", "GB", "TB" };  // 5 
	short numberOfsuffixes = 5;

	short index = (short) ceil(log(this->fileSize) / log(logBase));
	if (index > numberOfsuffixes) index = numberOfsuffixes;
	
	double convertedValue = this->fileSize / pow(logBase, index - 1);
	convertedValue = (double)((long long int)(convertedValue * 1000.0f) / 1000.0f);  // don't be afraid, I just round it to 2 digits
	return gcnew String(System::Convert::ToString(convertedValue) + L" " + gcnew String(suffixes[index - 1]));
}

String^ FileMeta::getInfoString()
{
	return gcnew String(this->getPathToFile() + L" - " + this->getHumanSize() + System::Environment::NewLine);
}
