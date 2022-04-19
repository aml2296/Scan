#ifndef JOBDATABASE
#define JOBDATABASE

#include <iostream>
#include <string>
using namespace std;

class JobNode;
class JobData;
class JobDataB;

class JobNode
{
public:
  JobNode * first = nullptr;
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
  int GetID ();
  string StringID ();
  string Name ();
  string ToString ();

    JobData ();
    JobData (string nameF, string nameL, int _id, JobNode * firstPtr =
	     nullptr, JobNode * lastPtr = nullptr, JobNode * nextPtr =
	     nullptr, JobNode * prevPtr = nullptr);
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
  bool DeleteJob (int);
  bool AddEmptyData ();
  bool AddJobData (string nameF, string nameL, int _id);
};
#endif
