#pragma once
#include <filesystem>
#include "helpers.h"
#include "FileMeta.h"

namespace fs = std::filesystem;

using namespace System;
using namespace System::Windows;
using namespace System::Collections::Generic;

ref struct ExtensionSpreading
{
	int numberOffiles = 0;
	uintmax_t sizeOfFilesThisExtension = 0;
	String^ getWholeHumanSize();
};


ref class Analysis
{
private:
	bool finished = false;
	String^ rootPath;
	String^ id;
	System::Windows::Forms::TextBox^ outTextBox;
	List<FileMeta^>^ files;
	
public:
	Analysis(String^ rootPath, System::Windows::Forms::TextBox^ % outTextBox);
	System::Void execute();
	String^ getRootPath();
	String^ getId();
	uintmax_t getWholeSize();
	String^ getWholeHumanSize();
	String^ getReport();
	bool isFinished();
	int getNumberOfAnalysedFiles();
	Dictionary<String^, ExtensionSpreading^>^% calculateExtensionsSpreading();
};

