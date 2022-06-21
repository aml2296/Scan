#include "App.h"

inline App::App()
{
        
}
inline App::~App()
{
    End();
}
inline void
App::Init ()
{
  jobDatabase = fileManager.GetData();
  //mLoop = new Loop();
}

inline void
App::End()
{
    if (mLoop != nullptr)
        delete mLoop;
}

inline bool
App::CheckInput(std::string inputSTR)
{
        accInput enumInput = hashInputToEnum(inputSTR);
        bool isValidInput = false;
        switch(enumInput)
        {
                case accInput::Exit:
                        lastInputEnum = enumInput;
                        std::cout << (int)enumInput << std::endl;
                        isValidInput = true;
                        break;  
                case accInput::Build:
                        lastInputEnum = enumInput;
                        std::cout << (int)enumInput << std::endl;
                        isValidInput = true;
                        break;
                case accInput::Help:
                        lastInputEnum = enumInput;
                        std::cout << (int)enumInput << std::endl;
                        isValidInput = true;
                        break;
                case accInput::None:
                        break;
        }
        return isValidInput;
}

inline accInput 
App::hashInputToEnum(std::string s)
{
    HFunc hfucntion;
    s = hfucntion.LowerStr(s);
    //if(s.compare(App.EXIT) == 0) return accInput::Exit;
    //if(s.compare(App::BUILD) == 0) return accInput::Build;
    //if(s.compare(App::HELP) == 0) return accInput::Help;
    return accInput::None;
}
