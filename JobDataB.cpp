#include "JobDataB.h"
using namespace std;



inline
JobNode::JobNode()
{

}

inline int
JobData::GetID ()
{
  return JobID;
}

inline string
JobData::StringID ()
{
  return to_string (JobID);
}

inline string
JobData::Name ()
{
  string rStr = "";
  rStr += firstName;
  rStr += " ";
  rStr += lastName;
  return rStr.c_str ();
}

inline string
JobData::ToString ()
{
  string str = StringID ();
  str += " ";
  str += Name ();
  return str;
}

inline string
JobData::Compress ()
{
  string str = "";
  dataBlockCount = 0;
  str += StringID ();
  str += DataBreak;		//Record Seperator
  dataBlockCount++;
  str += firstName;
  str += DataBreak;
  dataBlockCount++;
  str += lastName;
  dataBlockCount++;
  str = DataBreak + str;
  str = (char)dataBlockCount + str;
  return str;
}

inline
JobData::JobData ()
{

}

inline
JobData::JobData (string nameF, string nameL, int _id, JobNode * firstPtr,
		  JobNode * lastPtr, JobNode * nextPtr, JobNode * prevPtr)
{
  firstName = nameF;
  lastName = nameL;

  JobID = _id < 0 ? 0 : _id;
}

inline
JobData::JobData (string dataStr)
{
  int iterator = 0;
  int endDataBlock = 0;
  int startDataBlock = iterator;
  JobData returnValue;

  while (dataStr.length () > 0)
    {
      int subStrLength = dataStr.find (DataBreak, 0);
      string subStr = dataStr.substr (0, subStrLength - 1);
      returnValue.ReadID (subStr);

      dataStr.erase (0, subStrLength);
    }





  while (iterator < dataStr.length () && dataStr[iterator] != EndOfData)
    {
      while (dataStr[iterator] != DataBreak && dataStr[iterator] != EndOfData)
	{

	  iterator++;
	}
      iterator++;
    }
}

inline void
JobData::ReadID (string strID)
{
  stringstream ss (strID);
  ss >> JobID;
  std::cout << JobID;
}

inline int
JobDataB::Count ()
{
  return count;
}

inline
JobDataB::JobDataB ()
{
  count = 0;
}

inline string
JobDataB::Compress ()
{
  JobNode *iterator = jobHead;
  std::string str = "";
  std::cout << count;
  for (int i = 0; i < count && iterator != nullptr;
       i++, iterator = iterator->next)
    {
      str += iterator->data->Compress ();
      str += JobData::EndOfData;	//Char to represent end of record
    }
  return str == "" ? "No Job's in database!!" : str;
}

inline string
JobDataB::ToString ()
{
  JobNode *iterator = jobHead;
  std::string str = "";
  std::cout << count;
  for (int i = 0; i < count && iterator != nullptr;
       i++, iterator = iterator->next)
    {
      str += iterator->data->ToString ();
      str += '\n';
    }
  return str == "" ? "No Job's in database!!" : str;
}

inline bool
JobDataB::AddEmptyData ()
{
  JobNode *nData = new JobNode ();
  nData->data = new JobData ();
  return InsertJobNode (nData);
}

inline bool
JobDataB::AddJobData (string nameF, string nameL, int _id)
{
  JobNode *nData = new JobNode ();
  nData->data = new JobData (nameF, nameL, _id);
  return InsertJobNode (nData);
}

inline void
JobDataB::Clear ()
{
  if (jobHead != nullptr)
    {
      JobNode *temp = jobHead;
      while (temp != nullptr)
	{
	  JobNode *next = temp->next;
	  delete temp->data;
	  delete temp;
	  temp = next;
	}
    }
}

inline bool
JobDataB::DeleteJob (int _id)
{
  //Search for Job
  if (_id < jobTail->data->GetID ())
    return false;
  JobNode *iterator = jobHead;
  while (iterator != nullptr && iterator->data->GetID () > _id)
    iterator = iterator->next;
  if (iterator == nullptr)
    return false;
  //RemoveJob
  if (iterator->next != nullptr)
    {
      iterator->next->prev = iterator->prev;
    }
  else
    {
      jobTail = iterator->prev;
    }
  if (iterator->prev != nullptr)
    {
      iterator->prev->next = iterator->next;
    }
  else
    {
      jobHead = iterator->next;
    }
  delete iterator->data;
  delete iterator;
  count--;
  return true;
}

inline bool
JobDataB::InsertJobNode (JobNode * job)
{
  if (job == nullptr)
    return false;
  if (count == 0)
    {
      jobCurrent = jobTail = jobHead = job;
    }
  else if (count > 0)
    {
      if (count == 1)
	{
	  if (jobHead->data->GetID () >= job->data->GetID ())
	    {
	      jobCurrent = jobTail = job;
	    }
	  else
	    {
	      jobCurrent = jobHead = job;
	    }
	  jobTail->prev = jobHead;
	  jobHead->next = jobTail;
	}
      else
	{
	  JobNode IT;
	  JobNode *iterator = jobHead;

	  if (jobHead->data->GetID () < job->data->GetID ())
	    {
	      jobHead->prev = job;
	      job->next = jobHead;
	      jobHead = job;
	    }
	  else if (jobTail->data->GetID () <= job->data->GetID ())
	    {
	      jobTail->next = job;
	      job->prev = jobTail;
	      jobTail = job;
	    }
	  else
	    {
	      while (iterator != nullptr
		     && iterator->data->GetID () >= job->data->GetID ())
		{
		  IT = *iterator;
		  iterator = iterator->next;
		}
	      if (iterator == nullptr)
		{
		  jobTail->next = job;
		  job->prev = jobTail;
		  jobCurrent = jobTail = job;
		}
	      else
		{
		  iterator->prev->next = job;
		  job->prev = iterator->prev;
		  iterator->prev = job;
		  job->next = iterator;
		  jobCurrent = job;
		}
	    }
	}
    }
  else
    {
      return false;
    }
  count++;
  return true;
}


inline bool
JobDataB::SetIterator (int pos)
{
  if (count < pos)
    return false;
  else
    {
      jobCurrent = jobHead;
      for (int i = 0; i < pos && jobCurrent != nullptr; i++)
	Next ();
      if (jobCurrent == nullptr)
	return false;
    }
  return true;
};

inline JobData
JobDataB::Head ()
{
  if (jobHead != nullptr)
    return *jobHead->data;
  return JobData ();
}

inline JobData
JobDataB::Tail ()
{
  if (jobTail != nullptr)
    return *jobTail->data;
  return JobData ();
}

inline JobData
JobDataB::Current ()
{
  if (jobCurrent != nullptr)
    return *jobCurrent->data;
  return JobData ();
}

inline JobData
JobDataB::Next ()
{
  if (jobCurrent != nullptr && jobCurrent->next != nullptr)
    {
      jobCurrent = jobCurrent->next;
      return *jobCurrent->data;
    }
  return JobData ();
}

inline JobData
JobDataB::Prev ()
{
  if (jobCurrent != nullptr && jobCurrent->prev != nullptr)
    {
      jobCurrent = jobCurrent->prev;
      return *jobCurrent->data;
    }
  return JobData ();
}
