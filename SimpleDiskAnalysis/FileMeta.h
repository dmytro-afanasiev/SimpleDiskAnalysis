#pragma once
#include <cstdint>
#include <cmath>
#include "helpers.h"
#define ZERO_EXTENSION "[NO EXTENSION]"


using namespace System;

ref class FileMeta
{
private:
	String^ pathToFile;
	uintmax_t fileSize;
	String^ extension = L"";

public:
	FileMeta(String^ pathToFile, uintmax_t fileSize);
	FileMeta(const FileMeta^& another);
	String^ getPathToFile();
	uintmax_t getFileSize();

	String^ getHumanSize();
	String^ getInfoString();
	bool hasExtension();
	String^ getExtention();
};

