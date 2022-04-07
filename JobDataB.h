#include <iostream>
#include <string>
using namespace std;
class JobNode
{
    private:
        JobNode *first = nullptr;
        JobNode *last = nullptr;
        JobNode *next = nullptr;
        JobNode *prev = nullptr;
  
        char* firstName = nullptr;
        char* lastName = nullptr;
        int JobID = -1;
  
    
    
    public:
        const char* ID();
        const char* Name();
        const char* ToString();
    
        JobNode();
        JobNode(string nameF, string nameL, int _id,  JobNode *firstPtr = nullptr, JobNode *lastPtr = nullptr, JobNode *nextPtr = nullptr, JobNode *prevPtr = nullptr);
};
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
    string ToString()
    {
        JobNode* iterator = jobHead;
        std::string str = "";
        for(int i =0; i < count; i++)
        {
            str += iterator->ToString();
            str += '\n';
        }
        return str == ""?"No Job's in database!!" : str;
    }
    bool AddJobData(string nameF, string nameL, int _id);
};