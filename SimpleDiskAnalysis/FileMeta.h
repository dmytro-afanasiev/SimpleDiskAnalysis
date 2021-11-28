#pragma once
#include <cstdint>
#include <cmath>


using namespace System;

ref class FileMeta
{
private:
	String^ pathToFile;
	uintmax_t fileSize;

public:
	FileMeta(String^ pathToFile, uintmax_t fileSize);
	FileMeta(const FileMeta^& another);
	String^ getPathToFile();
	uintmax_t getFileSize();

	String^ getHumanSize();
	String^ getInfoString();
};

