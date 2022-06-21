#ifndef HFunctions
#define HFunctions
#include <string>
class HFunc
{
public:
    static std::string LowerStr(std::string s)
    {
        for (char& c : s)
            c = tolower(c);
        return s;
    }
};

#endif