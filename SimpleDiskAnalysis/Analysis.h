#pragma once
#include <filesystem>
#include "helpers.h"
#include "FileMeta.h"

namespace fs = std::filesystem;

using namespace System;
using namespace System::Windows;

ref class Analysis
{
private:
	String^ rootPath;
	System::Windows::Forms::TextBox^ outTextBox;
public:
	Analysis(String^ rootPath, System::Windows::Forms::TextBox^ % outTextBox);
	System::Void execute();
};

