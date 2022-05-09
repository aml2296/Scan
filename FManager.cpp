#include "FManager.h"

inline FManager::FManager()
{
    
}

inline FManager::FManager(JobDataB jobDB)
{
    data = jobDB;
}

inline bool FManager::WriteData()
{
    ofstream file(bufferFile);
    data.SetIterator(0);
    if(data.Count() < 1)
    {
        std::cout << "No Data to Write!";
        return false;
    }
    for(int i = 0; i < data.Count(); i++)
    {
        JobData jb = data.Current();
        file << jb.Compress() << JobData::EndOfData;
        data.Next();
    }
    file.close();
    return true;
}

inline bool FManager::ReadData()
{
    int bufferLimit = 100;
    ifstream file(bufferFile,ios::in);
    if(file.is_open())
    {
        char buffer[bufferLimit]  = {""};
        string buildDataStr;
        int iterator = 0;
        int dataChunckEnd = 0;
        
        file.seekg(0);
        //data.Clear();
        
        
        while(file >> buffer)
        {   
            while(iterator < bufferLimit)
            {
                string buildDataStr = "";
                for(iterator = dataChunckEnd; 
                buffer[iterator] != JobData::EndOfData || iterator > bufferLimit;
                iterator++)
                {
                    buildDataStr += buffer[iterator];
                }
                dataChunckEnd = iterator+1;
                std::cout << buildDataStr;
            }
        }
        file.close();
        return true;
    }
    return false;
}
