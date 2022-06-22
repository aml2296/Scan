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
    static wchar_t* charToWChar(const char* text)
    {
        const size_t size = strlen(text) + 1;
        wchar_t* wText = new wchar_t[size];
        mbstowcs(wText, text, size);
        return wText;
    }
};

#endif