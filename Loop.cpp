#include "App.h"

inline int
Loop::CheckInput(std::string inputSTR) //Check each Command for a valid Input
{                                       //Returns Command index if valid, else returns -1
        int rIndex = -1;
        inputSTR = LowerStr(inputSTR);
        for(int i = 0; i < commands.length; i++)
        {
                if(commands[i].compare(rIndex) == 0)
                        rIndex = i; break;
        }       
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
        m1.lock();
        int lastCommandIndex = -1;
        while(lastCommandIndex != commands[0]) //while command does not equal exit
        {
                std::cin >> currInput;
                lastCommandIndex = CheckInput(currInput);
                if(lastCommandIndex > 0)
                {
                        
                }
        }
        m1.unlock();
}

inline void Loop::Loop(thread &t)
{
        loopThread = std::thread(&App::Loop, t); //Probably wont work
}
