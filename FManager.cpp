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
    }
    for(int i = 0; i < data.Count(); i++)
    {
        JobData jb = data.Current();
        file << jb.ToString() << '\n';
        data.Next();
    }
    return true;
}

inline FManager::ReadData()
{
    ifstream file(bufferFile); 
    data.Clear();
    
}

inline bool FManager::ReadData()
{
  return true;
}
    