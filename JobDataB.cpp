inline #include <iostream>
inline #include <string>

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
        JobNode(string nameF, string nameL, int _id,
        JobNode *firstPtr = nullptr, JobNode *lastPtr = nullptr, JobNode *nextPtr = nullptr, JobNode *prevPtr = nullptr)
        {
            //char Array consists of string elements + char notify it's the end of the array
            firstName = new char[nameF.length()];
            firstName = &nameF[0];
            
            lastName = new char[nameL.length()];
            lastName = &nameL[0];
            
            JobID = _id < 0? 0 : _id;
        }
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
    bool AddJobData(string nameF, string nameL, int _id)
    {
        JobNode* temp = new JobNode(nameF,nameL,_id);
        if(count == 0)
        {
           jobTail = jobHead = temp;
        }
        else if(count > 0)
        {
            
        }
        else
        {
            return false;
        }
        count++;
    return true;
    }
};

const char* JobNode::ID()
{
    return to_string(JobID).c_str();
}
const char* JobNode::Name()
{
    string rStr = "";
    rStr += firstName;
    rStr += " ";
    rStr += lastName;
    return rStr.c_str();
}
const char * JobNode::ToString()
{
    string str = ID();
    str += " ";
    str += Name();
    return str.c_str();
}