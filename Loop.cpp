#include "App.h"

inline int
Loop::CheckInput(std::string inputSTR) //Check each Command for a valid Input
{                                       //Returns Command index if valid, else returns -1
        int rIndex = -1;
        HFunc hfucntion;
        inputSTR = hfucntion.LowerStr(inputSTR);
        /*for (int i = 0; i < commands.length; i++)
        {
                if(commands[i].compare(rIndex) == 0)
                        rIndex = i; break;
        } */      
        return rIndex;
}

inline void 
Loop::Init()
{
        commands = new std::string[3];
        commands[0] = "exit";
        commands[1] = "help";
        commands[2] = "build";
}

inline void
Loop::Run() //Loops until exit is called,
{
        loopLock.lock();
        int lastCommandIndex = -1;
        while( 0 != 1) //while command does not equal exit
        {
            std::cout << "."; std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        loopLock.unlock();
}

Loop::Loop()
{
        loopThread = std::thread(&Loop::Run, this); //Probably wont work
}

Loop::~Loop()
{
    loopThread.join();
}