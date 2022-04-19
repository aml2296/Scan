#ifndef FILEMANAGER
#define FILEMANAGER

#include <fstream>
#include <iostream>
#include "JobDataB.h"

class FManager
{
    private:
    const string bufferFile = "BuffData.txt"; //Data pertaining to more recent and active jobs
    const string archFile = "ArchData.txt"; //Archived Data for older jobs
  
    JobDataB data;
  
    public:
    bool WriteData();
    bool ReadData();
    
    FManager();
    FManager(JobDataB dataB);
};
#endif