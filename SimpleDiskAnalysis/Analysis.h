#pragma once
#include <filesystem>
#include "helpers.h"
#include "FileMeta.h"

namespace fs = std::filesystem;

using namespace System;
using namespace System::Windows;
using namespace System::Collections::Generic;

ref class Analysis
{
private:
	String^ rootPath;
	String^ id;
	System::Windows::Forms::TextBox^ outTextBox;
	List<FileMeta^>^ files;
public:
	Analysis(String^ rootPath, System::Windows::Forms::TextBox^ % outTextBox);
	System::Void execute();
	String^ getId();
	uintmax_t getWholeSize();
	String^ getWholeHumanSize();
};

