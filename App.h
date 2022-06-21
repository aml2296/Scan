#ifndef APPSCAN
#define APPSCAN

#include <thread>
#include <string>
#include <mutex>
#include <cstdlib>
#include <chrono>
#include <algorithm>
#include <windows.h>
#include "AccInput.h"
#include "JobDataB.h"
#include "FManager.h"
#include "HelpfulFunctions.h"
class Loop
{
private:
    std::mutex loopLock;
    thread loopThread; //Thread that handles Loop
    std::string* commands; //Available Commands
    accInput currentInput = accInput::None; //Might not need

    int CheckInput(std::string); //Checks all commands for a matching input, returns -1 for not found and index of found
public:
    Loop();
    ~Loop();

    virtual void Run(); //Core Loop, [Read Input, Check Input, HandleInput]
    virtual void Init(); //Initalize commands and start Run Thread
    //virtual Loop HandleInput(); //Returns new Loop Class relevant to Input
};
class LoopTest : public Loop
{

};


class App
{
        private:
                FManager fileManager;
                JobDataB jobDatabase;
                std::string input;
                accInput lastInputEnum = accInput::None;
                Loop *mLoop = nullptr;
        public:
                const char EXIT[5] = {'e','x','i','t','\0'};
                const char BUILD[6] = {'b','u','i','l','d','\0'};
                const char HELP[5] = {'h','e','l','p','\0'};
 
                App();
                ~App();
                void Init();
                void End();
                bool CheckInput(std::string);
                
                static accInput hashInputToEnum(std::string);
};
#endif
