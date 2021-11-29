#pragma once
#include <Windows.h>
#include "FileMeta.h"
#include <msclr\marshal_cppstd.h>
#include <random>
#include <sstream>


using namespace System;
using namespace System::Diagnostics;
using namespace System::Collections::Generic;

namespace Helpers {
	std::string toStandartString(String^ s);
	String^ getDisksInfoString();
	String^ generateUuid();
}