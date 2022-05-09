#ifndef JOBDATABASE
#define JOBDATABASE

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class JobNode;
class JobData;
class JobDataB;

class JobNode
{
public:
    JobNode *first = nullptr;
    JobNode *last = nullptr;
    JobNode *next = nullptr;
    JobNode *prev = nullptr;
    JobData *data = nullptr;

    JobNode ();
};
class JobData
{
    private:
        string firstName;
        string lastName;
        int JobID = -1;
    
    public:
        const static char EndOfData = '|';
        const static char DataBreak = '\x1E';
        int GetID ();
        void ReadID();
        string StringID ();
        string Name ();
        string ToString ();
        string Compress();
        JobData ();
        JobData (string nameF, string nameL, int _id, JobNode * firstPtr =
             nullptr, JobNode * lastPtr = nullptr, JobNode * nextPtr =
             nullptr, JobNode * prevPtr = nullptr);
        JobData(string dataStr);
};
class JobDataB
{
private:
  JobNode *jobHead = nullptr;
  JobNode *jobTail = nullptr;
  JobNode *jobCurrent = nullptr;
  int count = 0;

  bool InsertJobNode (JobNode *);


public:
  JobDataB ();
  int Count();
  string ToString ();
  bool SetIterator(int);
  JobData Head();
  JobData Tail();
  JobData Current();
  JobData Prev();
  JobData Next();
  string Compress();
  bool DeleteJob (int);
  bool AddEmptyData ();
  bool AddJobData (string nameF, string nameL, int _id);
};
#endif
