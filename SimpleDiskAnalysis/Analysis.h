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

[Serializable]
ref class Analysis
{
private:
	bool finished = false;
	String^ rootPath;
	String^ id;
	List<FileMeta^>^ files;
	[NonSerialized]
	System::Windows::Forms::TextBox^ outTextBox;
	[NonSerialized]
	System::Windows::Forms::ProgressBar^ analysisProgress;
	
public:
	Analysis(String^ rootPath, System::Windows::Forms::TextBox^ % outTextBox, System::Windows::Forms::ProgressBar^ % analysisProgress);
	System::Void execute();
	String^ getRootPath();
	String^ getId();
	uintmax_t getWholeSize();
	String^ getWholeHumanSize();
	String^ getReport();
	bool isFinished();
	int getNumberOfAnalysedFiles();
	int getNumberOfDirs();
	Dictionary<String^, ExtensionSpreading^>^% calculateExtensionsSpreading();
	List<FileMeta^>^ getFiles();
};

