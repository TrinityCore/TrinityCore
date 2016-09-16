#include "../pchdef.h"
#include "playerbot.h"
#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>

vector<string>& split(const string &s, char delim, vector<string> &elems)
{
    stringstream ss(s);
    string item;
    while(getline(ss, item, delim))
    {
        elems.push_back(item);
    }
    return elems;
}


vector<string> split(const string &s, char delim)
{
    vector<string> elems;
    return split(s, delim, elems);
}

char *strstri(const char *haystack, const char *needle)
{
    if ( !*needle )
    {
        return (char*)haystack;
    }
    for ( ; *haystack; ++haystack )
    {
        if ( tolower(*haystack) == tolower(*needle) )
        {
            const char *h = haystack, *n = needle;
            for ( ; *h && *n; ++h, ++n )
            {
                if ( tolower(*h) != tolower(*n) )
                {
                    break;
                }
            }
            if ( !*n )
            {
                return (char*)haystack;
            }
        }
    }
    return 0;
}



uint64 extractGuid(WorldPacket& packet)
{
    uint8 mask;
    packet >> mask;
    uint64 guid = 0;
    uint8 bit = 0;
    uint8 testMask = 1;
    while (true)
    {
        if (mask & testMask)
        {
            uint8 word;
            packet >> word;
            guid += (word << bit);
        }
        if (bit == 7)
            break;
        ++bit;
        testMask <<= 1;
    }
    return guid;
}

std::string &ltrim(std::string &s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
        return s;
}

std::string &rtrim(std::string &s) {
        s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
        return s;
}

std::string &trim(std::string &s) {
        return ltrim(rtrim(s));
}

