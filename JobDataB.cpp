#include "JobDataB.h"

using namespace std;

inline int JobData::GetID()
{
    return JobID;
}
inline string JobData::StringID()
{
    return to_string(JobID);
}
inline string JobData::Name()
{
    string rStr = "";
    rStr += firstName;
    rStr += " ";
    rStr += lastName;
    return rStr.c_str();
}
inline string JobData::ToString()
{
    string str = StringID();
    str += " ";
    str += Name();
    return str;
}
inline JobNode::JobNode()
{
    
}
inline JobData::JobData()
{
    
}
inline JobNode::JobNode(string nameF, string nameL, int _id,JobNode *firstPtr, JobNode *lastPtr, JobNode *nextPtr, JobNode *prevPtr)
        {
            firstName = nameF;
            lastName = nameL;
            
            JobID = _id < 0? 0 : _id;
        }



inline string JobDataB::ToString()
    {
        JobNode* iterator = jobHead;
        std::string str = "";
        for(int i =0; i < count && iterator != nullptr; i++,iterator =  iterator->next)
        {
            str += iterator->ToString();
            str += '\n';
        }
        return str == ""?"No Job's in database!!" : str;
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
            if(count == 1)
            {
                if(jobHead->GetID() >= temp->GetID())
                {
                    jobTail = temp;
                }
                else
                {
                    jobHead = temp;
                }
                    jobTail->prev = jobHead;
                    jobHead->next = jobTail;
            }
            else
            {
                JobNode IT;
                JobNode TEMP;
                JobNode *iterator = jobHead;
                
                    if(jobHead->GetID() < temp->GetID())
                    {
                         jobHead->prev = temp;
                         temp->next = jobHead;
                         jobHead = temp;
                    }
                    else if(jobTail->GetID() <= temp->GetID())
                    {
                        jobTail->next = temp;
                        temp->prev = jobTail;
                        jobTail = temp;
                    }
                    else
                    {
                    while(iterator != nullptr && iterator->GetID() >= temp->GetID())
                    {
                        IT = *iterator;
                        iterator = iterator->next;
                    }
                    if(iterator == nullptr)
                    {
                        jobTail->next = temp;
                        temp->prev = jobTail;
                        jobTail = temp;
                    }
                    else
                    {
                        iterator->prev->next = temp;
                        temp->prev = iterator->prev;
                        iterator->prev = temp;
                        temp->next = iterator;
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