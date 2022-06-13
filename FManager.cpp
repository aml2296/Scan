#include "FManager.h"

inline FManager::FManager ()
{

}

inline FManager::FManager (JobDataB jobDB)
{
  data = jobDB;
}

inline bool
FManager::WriteData ()
{
  ofstream file (bufferFile);
  data.SetIterator (0);
  if (data.Count () < 1)
    {
      std::cout << "No Data to Write!";
      return false;
    }
  for (int i = 0; i < data.Count (); i++)
    {
      JobData jb = data.Current ();
      file << jb.Compress () << JobData::EndOfData;
      data.Next ();
    }
  file.close ();
  return true;
}
inline JobDataB
FManager::GetData()
{
        JobDataB returnValue;
        if(ReadData())
        {
                returnValue = data;
        }
        return returnValue;
}
inline bool
FManager::ReadData ()
{
  int bufferLimit = 100;
  ifstream file (bufferFile, ios::in);
  if (file.is_open ())
    {
      char buffer[bufferLimit] = { BUFFERFILL };
      string buildDataStr;
      int iterator = 0;
      int dataChunckEnd = 0;
      int idRead = 0;
      std::string firstNameRead = "";
      std::string lastNameRead = "";



      file.seekg (0);
      data.Clear ();


      while (file >> buffer)
	{
	  //Find DataBlock 
	  while (iterator < bufferLimit)
	    {
	      //Init buildDataStr and iterator
	      std::string buildDataStr = "";
	      for (iterator = dataChunckEnd;
		   buffer[iterator] != JobData::EndOfData
		   && iterator < bufferLimit; iterator++)
		{
		  if (buffer[iterator] == BUFFERFILL)
		    {
		      readError = true;
		      return false;
		    }
		  buildDataStr += buffer[iterator];
		}
	      dataChunckEnd = iterator + 1;
	      std::cout << buildDataStr + "!";
	      if (buffer[iterator] == BUFFERFILL
		  || buffer[iterator] == '\000')
		{
		  readError = true;
		  file.close ();
		  return false;
		}
	      //Convert DataBlock from Str to Data
	      //ID
	      std::size_t breakPoint = buildDataStr.find (JobData::DataBreak);
	      std::string intStr = buildDataStr.substr (0, breakPoint);
	      idRead = std::stoi (intStr);
	      buildDataStr.erase (0, breakPoint + 1);
	      //First Name
	      breakPoint = buildDataStr.find (JobData::DataBreak);
	      firstNameRead = buildDataStr.substr (0, breakPoint);
	      buildDataStr.erase (0, breakPoint + 1);
	      //Last Name
	      lastNameRead = buildDataStr;
	      data.AddJobData (firstNameRead, lastNameRead, idRead);
	    }
	}
      file.close ();
      return true;
    }
  return false;
}
