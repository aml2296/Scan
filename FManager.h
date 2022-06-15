#ifndef FILEMANAGER
#define FILEMANAGER

#include <fstream>
#include <iostream>
#include <streambuf>
#include "JobDataB.h"
#include "MatAttribute.h"

class FManager
{
    private:
    const string bufferFile = "BuffData.txt"; //Data pertaining to more recent and active jobs
    const string archFile = "ArchData.txt"; //Archived Data for older jobs
    const char BUFFERFILL = '=';
    JobDataB data;
    
    
    bool readError = false;
    public:
    bool WriteData();
    bool ReadData();
    JobDataB GetData();
    
    FManager();
    FManager(JobDataB dataB);
};
#endif
