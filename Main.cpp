#include "JobData.cpp"
#include "BMat.cpp"
#include "FManager.cpp"
int main()
{
    JobDataB temp;
    temp.AddJobData("Tim","M", 6969);
    temp.AddJobData("Abe", "A",80085 );
    temp.AddJobData("Christain", "B", 666);
    temp.AddJobData("British", "Guy", 3434);
    temp.AddJobData("Fuck","Shit",999900);
    FManager fMang(temp);
    fMang.WriteData();
    std::cout << temp.ToString();
    return 0;
}
