#include "JobDataB.h"

using namespace std;

inline const char* JobNode::ID()
{
    return to_string(JobID).c_str();
}
inline const char* JobNode::Name()
{
    string rStr = "";
    rStr += firstName;
    rStr += " ";
    rStr += lastName;
    return rStr.c_str();
}
inline const char * JobNode::ToString()
{
    string str = ID();
    str += " ";
    str += Name();
    return str.c_str();
}
inline JobNode::JobNode()
{
    
}
inline JobNode::JobNode(string nameF, string nameL, int _id,JobNode *firstPtr, JobNode *lastPtr, JobNode *nextPtr, JobNode *prevPtr)
        {
            //char Array consists of string elements + char notify it's the end of the array
            firstName = new char[nameF.length()];
            firstName = &nameF[0];
            
            lastName = new char[nameL.length()];
            lastName = &nameL[0];
            
            JobID = _id < 0? 0 : _id;
        }




inline bool JobDataB::AddJobData(string nameF, string nameL, int _id)
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