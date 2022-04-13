#include <iostream>
#include <string>
using namespace std;
class JobNode
{
    public:
        JobNode *first = nullptr;
        JobNode *last = nullptr;
        JobNode *next = nullptr;
        JobNode *prev = nullptr;
        JobData *data = nullptr;
    
        int GetID();
        string StringID();
        string Name();
        string ToString();
    
        JobNode();
        JobNode(string nameF, string nameL, int _id,  JobNode *firstPtr = nullptr, JobNode *lastPtr = nullptr, JobNode *nextPtr = nullptr, JobNode *prevPtr = nullptr);
};
class JobData
{
        private:
        string firstName;
        string lastName;
        int JobID = -1;


        int GetID();
        string StringID();
        string Name();
        string ToString();
}
class JobDataB
{
    private:
    JobNode *jobHead = nullptr;
    JobNode *jobTail = nullptr;

    int count = 0;
    
    public: 
    JobDataB()
    {
        
    }
    string ToString();
    bool AddJobData(string nameF, string nameL, int _id);
};