#include "helpers.h"


std::string Helpers::toStandartString(String^ s) {
    msclr::interop::marshal_context context;
    return context.marshal_as<std::string>(s);    
}


String^ Helpers::getDisksInfoString()
{
    String^ newLine = System::Environment::NewLine;

    String^ resultString;
    array<String^>^ params = gcnew array<String^>(4);

    DWORD requiredBuffer;
    WCHAR* driveStrings;
    PWSTR driveTypeString;
    ULARGE_INTEGER freeSpace;
    ULARGE_INTEGER totalSpace;

    requiredBuffer = GetLogicalDriveStrings(0, NULL);
    driveStrings = new WCHAR[requiredBuffer+1];
    
    GetLogicalDriveStrings(requiredBuffer, driveStrings);

    WCHAR* singleDriveString = driveStrings;
    while (*singleDriveString)
    {
        GetDiskFreeSpaceEx(singleDriveString, &freeSpace, &totalSpace, NULL);

        switch (GetDriveType(singleDriveString))
        {
        case DRIVE_FIXED:
            driveTypeString = L"Hard disk";
            break;

        case DRIVE_CDROM:
            driveTypeString = L"CD/DVD";
            break;

        case DRIVE_REMOVABLE:
            driveTypeString = L"Removable";
            break;

        case DRIVE_REMOTE:
            driveTypeString = L"Network";
            break;

        default:
            driveTypeString = L"Unknown";
            break;
        }
        params[0] = gcnew String(driveTypeString);
        params[1] = gcnew String(singleDriveString);
        params[2] = System::Convert::ToString(freeSpace.QuadPart / 1024 / 1024 / 1024);
        params[3] = System::Convert::ToString(totalSpace.QuadPart / 1024 / 1024 / 1024);
        
        String^ oneDriveLine = String::Format(L"{0} {1} - {2}/{3} GB used;" + newLine, params);

        resultString = String::Concat(resultString, oneDriveLine);

        singleDriveString += lstrlen(singleDriveString) + 1;
    }
    delete[] driveStrings;
    return resultString;
}


String^ Helpers::generateUuid()
{
    static std::random_device dev;
    static std::mt19937 rng(dev());

    std::uniform_int_distribution<int> dist(0, 15);

    const char* v = "0123456789abcdef";
    const bool dash[] = { 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0 };

    std::string res;
    for (int i = 0; i < 16; i++) {
        if (dash[i]) res += "-";
        res += v[dist(rng)];
        res += v[dist(rng)];
    }
    return gcnew String(res.c_str());
}

String^ Helpers::bytesToHumanSize(uintmax_t bytes)
{
    if (bytes == 0) {
        return gcnew String("0 B");
    }
    int logBase = 1024;
    char* suffixes[] = { "B", "KB", "MB", "GB", "TB" };  // 5 
    short numberOfsuffixes = 5;

    short index = (short)ceil(log(bytes) / log(logBase));
    if (index > numberOfsuffixes) index = numberOfsuffixes;

    double convertedValue = bytes / pow(logBase, index - 1);
    convertedValue = (double)((long long int)(convertedValue * 1000.0f) / 1000.0f);  // don't be afraid, I just round it to 2 digits
    return gcnew String(System::Convert::ToString(convertedValue) + L" " + gcnew String(suffixes[index - 1]));
}

