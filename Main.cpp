#include "JobDataB.cpp"
#include "BMaterial.cpp"

int main()
{
    JobDataB temp;
    temp.AddJobData("Tim","M", 6969);
    std::cout << temp.ToString();
    return 0;
}