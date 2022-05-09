#include "JobData.cpp"
#include "BMat.cpp"
#include "FManager.cpp"
void Write(JobDataB&,FManager&);

int main()
{
    JobDataB temp;
    FManager fMang(temp);
    fMang.ReadData();
    return 0;
}

void Write(JobDataB &temp, FManager &fMang)
{
    temp.AddJobData("Tim","M", 6969);
    temp.AddJobData("Abe", "A",80085 );
    temp.AddJobData("Christain", "B", 666);
    temp.AddJobData("British", "Guy", 3434);
    temp.AddJobData("Fuck","Shit",999900);
    fMang.WriteData();
}
