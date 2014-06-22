/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "Util.h"
#include "Common.h"
#include "utf8.h"
#include "SFMT.h"
#include "Errors.h" // for ASSERT
#include <boost/thread/tss.hpp>

static boost::thread_specific_ptr<SFMTRand> sfmtRand;

static SFMTRand* GetRng()
{
    SFMTRand* rand = sfmtRand.get();

    if (!rand)
    {
        rand = new SFMTRand();
        sfmtRand.reset(rand);
    }

    return rand;
}

int32 irand(int32 min, int32 max)
{
    ASSERT(max >= min);
    return int32(GetRng()->IRandom(min, max));
}

uint32 urand(uint32 min, uint32 max)
{
    ASSERT(max >= min);
    return GetRng()->URandom(min, max);
}

float frand(float min, float max)
{
    ASSERT(max >= min);
    return float(GetRng()->Random() * (max - min) + min);
}

int32 rand32()
{
    return int32(GetRng()->BRandom());
}

double rand_norm(void)
{
    return GetRng()->Random();
}

double rand_chance(void)
{
    return GetRng()->Random() * 100.0;
}

Tokenizer::Tokenizer(const std::string &src, const char sep, uint32 vectorReserve)
{
    m_str = new char[src.length() + 1];
    memcpy(m_str, src.c_str(), src.length() + 1);

    if (vectorReserve)
        m_storage.reserve(vectorReserve);

    char* posold = m_str;
    char* posnew = m_str;

    for (;;)
    {
        if (*posnew == sep)
        {
            m_storage.push_back(posold);
            posold = posnew + 1;

            *posnew = '\0';
        }
        else if (*posnew == '\0')
        {
            // Hack like, but the old code accepted these kind of broken strings,
            // so changing it would break other things
            if (posold != posnew)
                m_storage.push_back(posold);

            break;
        }

        ++posnew;
    }
}

void stripLineInvisibleChars(std::string &str)
{
    static std::string const invChars = " \t\7\n";

    size_t wpos = 0;

    bool space = false;
    for (size_t pos = 0; pos < str.size(); ++pos)
    {
        if (invChars.find(str[pos])!=std::string::npos)
        {
            if (!space)
            {
                str[wpos++] = ' ';
                space = true;
            }
        }
        else
        {
            if (wpos!=pos)
                str[wpos++] = str[pos];
            else
                ++wpos;
            space = false;
        }
    }

    if (wpos < str.size())
        str.erase(wpos, str.size());
    if (str.find("|TInterface")!=std::string::npos)
        str.clear();

}

#if (defined(WIN32) || defined(_WIN32) || defined(__WIN32__))
struct tm* localtime_r(const time_t* time, struct tm *result)
{
    localtime_s(result, time);
    return result;
}
#endif

std::string secsToTimeString(uint64 timeInSecs, bool shortText, bool hoursOnly)
{
    uint64 secs    = timeInSecs % MINUTE;
    uint64 minutes = timeInSecs % HOUR / MINUTE;
    uint64 hours   = timeInSecs % DAY  / HOUR;
    uint64 days    = timeInSecs / DAY;

    std::ostringstream ss;
    if (days)
        ss << days << (shortText ? "d" : " Day(s) ");
    if (hours || hoursOnly)
        ss << hours << (shortText ? "h" : " Hour(s) ");
    if (!hoursOnly)
    {
        if (minutes)
            ss << minutes << (shortText ? "m" : " Minute(s) ");
        if (secs || (!days && !hours && !minutes) )
            ss << secs << (shortText ? "s" : " Second(s).");
    }

    return ss.str();
}

int32 MoneyStringToMoney(const std::string& moneyString)
{
    int32 money = 0;

    if (!(std::count(moneyString.begin(), moneyString.end(), 'g') == 1 ||
        std::count(moneyString.begin(), moneyString.end(), 's') == 1 ||
        std::count(moneyString.begin(), moneyString.end(), 'c') == 1))
        return 0; // Bad format

    Tokenizer tokens(moneyString, ' ');
    for (Tokenizer::const_iterator itr = tokens.begin(); itr != tokens.end(); ++itr)
    {
        std::string tokenString(*itr);
        size_t gCount = std::count(tokenString.begin(), tokenString.end(), 'g');
        size_t sCount = std::count(tokenString.begin(), tokenString.end(), 's');
        size_t cCount = std::count(tokenString.begin(), tokenString.end(), 'c');
        if (gCount + sCount + cCount != 1)
            return 0;

        uint32 amount = atoi(*itr);
        if (gCount == 1)
            money += amount * 100 * 100;
        else if (sCount == 1)
            money += amount * 100;
        else if (cCount == 1)
            money += amount;
    }

    return money;
}

uint32 TimeStringToSecs(const std::string& timestring)
{
    uint32 secs       = 0;
    uint32 buffer     = 0;
    uint32 multiplier = 0;

    for (std::string::const_iterator itr = timestring.begin(); itr != timestring.end(); ++itr)
    {
        if (isdigit(*itr))
        {
            buffer*=10;
            buffer+= (*itr)-'0';
        }
        else
        {
            switch (*itr)
            {
                case 'd': multiplier = DAY;     break;
                case 'h': multiplier = HOUR;    break;
                case 'm': multiplier = MINUTE;  break;
                case 's': multiplier = 1;       break;
                default : return 0;                         //bad format
            }
            buffer*=multiplier;
            secs+=buffer;
            buffer=0;
        }
    }

    return secs;
}

std::string TimeToTimestampStr(time_t t)
{
    tm aTm;
    localtime_r(&t, &aTm);
    //       YYYY   year
    //       MM     month (2 digits 01-12)
    //       DD     day (2 digits 01-31)
    //       HH     hour (2 digits 00-23)
    //       MM     minutes (2 digits 00-59)
    //       SS     seconds (2 digits 00-59)
    char buf[20];
    snprintf(buf, 20, "%04d-%02d-%02d_%02d-%02d-%02d", aTm.tm_year+1900, aTm.tm_mon+1, aTm.tm_mday, aTm.tm_hour, aTm.tm_min, aTm.tm_sec);
    return std::string(buf);
}

/// Check if the string is a valid ip address representation
bool IsIPAddress(char const* ipaddress)
{
    if (!ipaddress)
        return false;

    // Let the big boys do it.
    // Drawback: all valid ip address formats are recognized e.g.: 12.23, 121234, 0xABCD)
    return inet_addr(ipaddress) != INADDR_NONE;
}

/// create PID file
uint32 CreatePIDFile(const std::string& filename)
{
    FILE* pid_file = fopen (filename.c_str(), "w" );
    if (pid_file == NULL)
        return 0;

#ifdef _WIN32
    DWORD pid = GetCurrentProcessId();
#else
    pid_t pid = getpid();
#endif

    fprintf(pid_file, "%u", pid );
    fclose(pid_file);

    return (uint32)pid;
}

size_t utf8length(std::string& utf8str)
{
    try
    {
        return utf8::distance(utf8str.c_str(), utf8str.c_str()+utf8str.size());
    }
    catch(std::exception)
    {
        utf8str = "";
        return 0;
    }
}

void utf8truncate(std::string& utf8str, size_t len)
{
    try
    {
        size_t wlen = utf8::distance(utf8str.c_str(), utf8str.c_str()+utf8str.size());
        if (wlen <= len)
            return;

        std::wstring wstr;
        wstr.resize(wlen);
        utf8::utf8to16(utf8str.c_str(), utf8str.c_str()+utf8str.size(), &wstr[0]);
        wstr.resize(len);
        char* oend = utf8::utf16to8(wstr.c_str(), wstr.c_str()+wstr.size(), &utf8str[0]);
        utf8str.resize(oend-(&utf8str[0]));                 // remove unused tail
    }
    catch(std::exception)
    {
        utf8str = "";
    }
}

bool Utf8toWStr(char const* utf8str, size_t csize, wchar_t* wstr, size_t& wsize)
{
    try
    {
        size_t len = utf8::distance(utf8str, utf8str+csize);
        if (len > wsize)
        {
            if (wsize > 0)
                wstr[0] = L'\0';
            wsize = 0;
            return false;
        }

        wsize = len;
        utf8::utf8to16(utf8str, utf8str+csize, wstr);
        wstr[len] = L'\0';
    }
    catch(std::exception)
    {
        if (wsize > 0)
            wstr[0] = L'\0';
        wsize = 0;
        return false;
    }

    return true;
}

bool Utf8toWStr(const std::string& utf8str, std::wstring& wstr)
{
    try
    {
        if (size_t len = utf8::distance(utf8str.c_str(), utf8str.c_str()+utf8str.size()))
        {
            wstr.resize(len);
            utf8::utf8to16(utf8str.c_str(), utf8str.c_str()+utf8str.size(), &wstr[0]);
        }
    }
    catch(std::exception)
    {
        wstr = L"";
        return false;
    }

    return true;
}

bool WStrToUtf8(wchar_t* wstr, size_t size, std::string& utf8str)
{
    try
    {
        std::string utf8str2;
        utf8str2.resize(size*4);                            // allocate for most long case

        if (size)
        {
            char* oend = utf8::utf16to8(wstr, wstr+size, &utf8str2[0]);
            utf8str2.resize(oend-(&utf8str2[0]));               // remove unused tail
        }
        utf8str = utf8str2;
    }
    catch(std::exception)
    {
        utf8str = "";
        return false;
    }

    return true;
}

bool WStrToUtf8(std::wstring wstr, std::string& utf8str)
{
    try
    {
        std::string utf8str2;
        utf8str2.resize(wstr.size()*4);                     // allocate for most long case

        if (wstr.size())
        {
            char* oend = utf8::utf16to8(wstr.c_str(), wstr.c_str()+wstr.size(), &utf8str2[0]);
            utf8str2.resize(oend-(&utf8str2[0]));                // remove unused tail
        }
        utf8str = utf8str2;
    }
    catch(std::exception)
    {
        utf8str = "";
        return false;
    }

    return true;
}

typedef wchar_t const* const* wstrlist;

std::wstring GetMainPartOfName(std::wstring wname, uint32 declension)
{
    // supported only Cyrillic cases
    if (wname.size() < 1 || !isCyrillicCharacter(wname[0]) || declension > 5)
        return wname;

    // Important: end length must be <= MAX_INTERNAL_PLAYER_NAME-MAX_PLAYER_NAME (3 currently)

    static wchar_t const a_End[]    = { wchar_t(1), wchar_t(0x0430), wchar_t(0x0000)};
    static wchar_t const o_End[]    = { wchar_t(1), wchar_t(0x043E), wchar_t(0x0000)};
    static wchar_t const ya_End[]   = { wchar_t(1), wchar_t(0x044F), wchar_t(0x0000)};
    static wchar_t const ie_End[]   = { wchar_t(1), wchar_t(0x0435), wchar_t(0x0000)};
    static wchar_t const i_End[]    = { wchar_t(1), wchar_t(0x0438), wchar_t(0x0000)};
    static wchar_t const yeru_End[] = { wchar_t(1), wchar_t(0x044B), wchar_t(0x0000)};
    static wchar_t const u_End[]    = { wchar_t(1), wchar_t(0x0443), wchar_t(0x0000)};
    static wchar_t const yu_End[]   = { wchar_t(1), wchar_t(0x044E), wchar_t(0x0000)};
    static wchar_t const oj_End[]   = { wchar_t(2), wchar_t(0x043E), wchar_t(0x0439), wchar_t(0x0000)};
    static wchar_t const ie_j_End[] = { wchar_t(2), wchar_t(0x0435), wchar_t(0x0439), wchar_t(0x0000)};
    static wchar_t const io_j_End[] = { wchar_t(2), wchar_t(0x0451), wchar_t(0x0439), wchar_t(0x0000)};
    static wchar_t const o_m_End[]  = { wchar_t(2), wchar_t(0x043E), wchar_t(0x043C), wchar_t(0x0000)};
    static wchar_t const io_m_End[] = { wchar_t(2), wchar_t(0x0451), wchar_t(0x043C), wchar_t(0x0000)};
    static wchar_t const ie_m_End[] = { wchar_t(2), wchar_t(0x0435), wchar_t(0x043C), wchar_t(0x0000)};
    static wchar_t const soft_End[] = { wchar_t(1), wchar_t(0x044C), wchar_t(0x0000)};
    static wchar_t const j_End[]    = { wchar_t(1), wchar_t(0x0439), wchar_t(0x0000)};

    static wchar_t const* const dropEnds[6][8] = {
        { &a_End[1],  &o_End[1],    &ya_End[1],   &ie_End[1],  &soft_End[1], &j_End[1],    NULL,       NULL },
        { &a_End[1],  &ya_End[1],   &yeru_End[1], &i_End[1],   NULL,         NULL,         NULL,       NULL },
        { &ie_End[1], &u_End[1],    &yu_End[1],   &i_End[1],   NULL,         NULL,         NULL,       NULL },
        { &u_End[1],  &yu_End[1],   &o_End[1],    &ie_End[1],  &soft_End[1], &ya_End[1],   &a_End[1],  NULL },
        { &oj_End[1], &io_j_End[1], &ie_j_End[1], &o_m_End[1], &io_m_End[1], &ie_m_End[1], &yu_End[1], NULL },
        { &ie_End[1], &i_End[1],    NULL,         NULL,        NULL,         NULL,         NULL,       NULL }
    };

    for (wchar_t const* const* itr = &dropEnds[declension][0]; *itr; ++itr)
    {
        size_t len = size_t((*itr)[-1]);                    // get length from string size field

        if (wname.substr(wname.size()-len, len)==*itr)
            return wname.substr(0, wname.size()-len);
    }

    return wname;
}

bool utf8ToConsole(const std::string& utf8str, std::string& conStr)
{
#if PLATFORM == PLATFORM_WINDOWS
    std::wstring wstr;
    if (!Utf8toWStr(utf8str, wstr))
        return false;

    conStr.resize(wstr.size());
    CharToOemBuffW(&wstr[0], &conStr[0], wstr.size());
#else
    // not implemented yet
    conStr = utf8str;
#endif

    return true;
}

bool consoleToUtf8(const std::string& conStr, std::string& utf8str)
{
#if PLATFORM == PLATFORM_WINDOWS
    std::wstring wstr;
    wstr.resize(conStr.size());
    OemToCharBuffW(&conStr[0], &wstr[0], conStr.size());

    return WStrToUtf8(wstr, utf8str);
#else
    // not implemented yet
    utf8str = conStr;
    return true;
#endif
}

bool Utf8FitTo(const std::string& str, std::wstring search)
{
    std::wstring temp;

    if (!Utf8toWStr(str, temp))
        return false;

    // converting to lower case
    wstrToLower( temp );

    if (temp.find(search) == std::wstring::npos)
        return false;

    return true;
}

void utf8printf(FILE* out, const char *str, ...)
{
    va_list ap;
    va_start(ap, str);
    vutf8printf(out, str, &ap);
    va_end(ap);
}

void vutf8printf(FILE* out, const char *str, va_list* ap)
{
#if PLATFORM == PLATFORM_WINDOWS
    char temp_buf[32*1024];
    wchar_t wtemp_buf[32*1024];

    size_t temp_len = vsnprintf(temp_buf, 32*1024, str, *ap);
    //vsnprintf returns -1 if the buffer is too small
    if (temp_len == size_t(-1))
        temp_len = 32*1024-1;

    size_t wtemp_len = 32*1024-1;
    Utf8toWStr(temp_buf, temp_len, wtemp_buf, wtemp_len);

    CharToOemBuffW(&wtemp_buf[0], &temp_buf[0], wtemp_len+1);
    fprintf(out, "%s", temp_buf);
#else
    vfprintf(out, str, *ap);
#endif
}

std::string ByteArrayToHexStr(uint8 const* bytes, uint32 arrayLen, bool reverse /* = false */)
{
    int32 init = 0;
    int32 end = arrayLen;
    int8 op = 1;

    if (reverse)
    {
        init = arrayLen - 1;
        end = -1;
        op = -1;
    }

    std::ostringstream ss;
    for (int32 i = init; i != end; i += op)
    {
        char buffer[4];
        sprintf(buffer, "%02X", bytes[i]);
        ss << buffer;
    }

    return ss.str();
}
