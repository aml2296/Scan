#include "App.h"


inline std::string LowerStr(std::string s)
{
        for(char &c:s)
                c = tolower(c);
        return s;
}

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
  jobDatabase = fileManager.GetData ();
  t1 = std::thread(&App::Loop, this);
}

inline void
App::Loop ()
{       
        m1.lock();
        std::cout << "A" << std::endl;
        std::string currInput = "";
        while(lastInputEnum != accInput::Exit)
        {
                std::cin >> currInput;
                if(CheckInput(currInput))
                {
                        std::cout << "Valid" << std::endl;
                }
        }
        m1.unlock();
}

inline void
App::End()
{
        t1.join();
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
        for(char &c : s)
                LowerStr(c);
        if(s.compare(App::EXIT) == 0) return accInput::Exit;
        if(s.compare(App::BUILD) == 0) return accInput::Build;
        if(s.compare(App::HELP) == 0) return accInput::Help;
        return accInput::None;
}
