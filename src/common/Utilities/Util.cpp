/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
#include "Containers.h"
#include "IpAddress.h"
#include "StringFormat.h"
#include <utf8.h>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <string>
#include <cctype>
#include <cstdarg>
#include <ctime>

#if TRINITY_COMPILER == TRINITY_COMPILER_GNU
  #include <sys/socket.h>
  #include <netinet/in.h>
  #include <arpa/inet.h>
#endif

Tokenizer::Tokenizer(const std::string &src, const char sep, uint32 vectorReserve /*= 0*/, bool keepEmptyStrings /*= true*/)
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
            if (keepEmptyStrings || posold != posnew)
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

#if (defined(WIN32) || defined(_WIN32) || defined(__WIN32__))
struct tm* localtime_r(time_t const* time, struct tm *result)
{
    localtime_s(result, time);
    return result;
}
#endif

tm TimeBreakdown(time_t time)
{
    tm timeLocal;
    localtime_r(&time, &timeLocal);
    return timeLocal;
}

time_t LocalTimeToUTCTime(time_t time)
{
#if (defined(WIN32) || defined(_WIN32) || defined(__WIN32__))
    return time + _timezone;
#else
    return time + timezone;
#endif
}

time_t GetLocalHourTimestamp(time_t time, uint8 hour, bool onlyAfterTime)
{
    tm timeLocal = TimeBreakdown(time);
    timeLocal.tm_hour = 0;
    timeLocal.tm_min = 0;
    timeLocal.tm_sec = 0;
    time_t midnightLocal = mktime(&timeLocal);
    time_t hourLocal = midnightLocal + hour * HOUR;

    if (onlyAfterTime && hourLocal <= time)
        hourLocal += DAY;

    return hourLocal;
}

std::string secsToTimeString(uint64 timeInSecs, TimeFormat timeFormat, bool hoursOnly)
{
    uint64 secs    = timeInSecs % MINUTE;
    uint64 minutes = timeInSecs % HOUR / MINUTE;
    uint64 hours   = timeInSecs % DAY  / HOUR;
    uint64 days    = timeInSecs / DAY;

    if (timeFormat == TimeFormat::Numeric)
    {
        if (days)
            return Trinity::StringFormat("%u:%02u:%02u:%02u", days, hours, minutes, secs);
        else if (hours)
            return Trinity::StringFormat("%u:%02u:%02u", hours, minutes, secs);
        else if (minutes)
            return Trinity::StringFormat("%u:%02u", minutes, secs);
        else
            return Trinity::StringFormat("0:%02u", secs);
    }

    std::ostringstream ss;
    if (days)
    {
        ss << days;
        switch (timeFormat)
        {
            case TimeFormat::ShortText:
                ss << "d";
                break;
            case TimeFormat::FullText:
                if (days == 1)
                    ss << " Day ";
                else
                    ss << " Days ";
                break;
            default:
                return "<Unknown time format>";
        }
    }

    if (hours || hoursOnly)
    {
        ss << hours;
        switch (timeFormat)
        {
            case TimeFormat::ShortText:
                ss << "h";
                break;
            case TimeFormat::FullText:
                if (hours <= 1)
                    ss << " Hour ";
                else
                    ss << " Hours ";
                break;
            default:
                return "<Unknown time format>";
        }
    }
    if (!hoursOnly)
    {
        if (minutes)
        {
            ss << minutes;
            switch (timeFormat)
            {
                case TimeFormat::ShortText:
                    ss << "m";
                    break;
                case TimeFormat::FullText:
                    if (minutes == 1)
                        ss << " Minute ";
                    else
                        ss << " Minutes ";
                    break;
                default:
                    return "<Unknown time format>";
            }
        }

        if (secs || (!days && !hours && !minutes))
        {
            ss << secs;
            switch (timeFormat)
            {
                case TimeFormat::ShortText:
                    ss << "s";
                    break;
                case TimeFormat::FullText:
                    if (secs <= 1)
                        ss << " Second.";
                    else
                        ss << " Seconds.";
                    break;
                default:
                    return "<Unknown time format>";
            }
        }
    }

    return ss.str();
}

int32 MoneyStringToMoney(std::string const& moneyString)
{
    int32 money = 0;

    if (!(std::count(moneyString.begin(), moneyString.end(), 'g') == 1 ||
        std::count(moneyString.begin(), moneyString.end(), 's') == 1 ||
        std::count(moneyString.begin(), moneyString.end(), 'c') == 1))
        return 0; // Bad format

    Tokenizer tokens(moneyString, ' ');
    for (char const* token : tokens)
    {
        std::string tokenString(token);
        size_t gCount = std::count(tokenString.begin(), tokenString.end(), 'g');
        size_t sCount = std::count(tokenString.begin(), tokenString.end(), 's');
        size_t cCount = std::count(tokenString.begin(), tokenString.end(), 'c');
        if (gCount + sCount + cCount != 1)
            return 0;

        uint32 amount = strtoul(token, nullptr, 10);
        if (gCount == 1)
            money += amount * 100 * 100;
        else if (sCount == 1)
            money += amount * 100;
        else if (cCount == 1)
            money += amount;
    }

    return money;
}

uint32 TimeStringToSecs(std::string const& timestring)
{
    uint32 secs       = 0;
    uint32 buffer     = 0;
    uint32 multiplier = 0;

    for (char itr : timestring)
    {
        if (isdigit(itr))
        {
            buffer *= 10;
            buffer += itr - '0';
        }
        else
        {
            switch (itr)
            {
                case 'd': multiplier = DAY;     break;
                case 'h': multiplier = HOUR;    break;
                case 'm': multiplier = MINUTE;  break;
                case 's': multiplier = 1;       break;
                default : return 0;                         //bad format
            }
            buffer *= multiplier;
            secs += buffer;
            buffer = 0;
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
    return Trinity::StringFormat("%04d-%02d-%02d_%02d-%02d-%02d", aTm.tm_year + 1900, aTm.tm_mon + 1, aTm.tm_mday, aTm.tm_hour, aTm.tm_min, aTm.tm_sec);
}

std::string TimeToHumanReadable(time_t t)
{
    tm time;
    localtime_r(&t, &time);
    char buf[30];
    strftime(buf, 30, "%c", &time);
    return std::string(buf);
}

/// Check if the string is a valid ip address representation
bool IsIPAddress(char const* ipaddress)
{
    if (!ipaddress)
        return false;

    boost::system::error_code error;
    Trinity::Net::make_address(ipaddress, error);
    return !error;
}

/// create PID file
uint32 CreatePIDFile(std::string const& filename)
{
    FILE* pid_file = fopen(filename.c_str(), "w");
    if (pid_file == nullptr)
        return 0;

    uint32 pid = GetPID();

    fprintf(pid_file, "%u", pid);
    fclose(pid_file);

    return pid;
}

uint32 GetPID()
{
#ifdef _WIN32
    DWORD pid = GetCurrentProcessId();
#else
    pid_t pid = getpid();
#endif

    return uint32(pid);
}

size_t utf8length(std::string& utf8str)
{
    try
    {
        return utf8::distance(utf8str.c_str(), utf8str.c_str()+utf8str.size());
    }
    catch(std::exception const&)
    {
        utf8str.clear();
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
    catch(std::exception const&)
    {
        utf8str.clear();
    }
}

bool Utf8toWStr(char const* utf8str, size_t csize, wchar_t* wstr, size_t& wsize)
{
    try
    {
        Trinity::CheckedBufferOutputIterator<wchar_t> out(wstr, wsize);
        out = utf8::utf8to16(utf8str, utf8str+csize, out);
        wsize -= out.remaining(); // remaining unused space
        wstr[wsize] = L'\0';
    }
    catch(std::exception const&)
    {
        // Replace the converted string with an error message if there is enough space
        // Otherwise just return an empty string
        wchar_t const* errorMessage = L"An error occurred converting string from UTF-8 to WStr";
        size_t errorMessageLength = wcslen(errorMessage);
        if (wsize >= errorMessageLength)
        {
            wcscpy(wstr, errorMessage);
            wsize = wcslen(wstr);
        }
        else if (wsize > 0)
        {
            wstr[0] = L'\0';
            wsize = 0;
        }
        else
            wsize = 0;

        return false;
    }

    return true;
}

bool Utf8toWStr(const std::string& utf8str, std::wstring& wstr)
{
    wstr.clear();
    try
    {
        utf8::utf8to16(utf8str.c_str(), utf8str.c_str()+utf8str.size(), std::back_inserter(wstr));
    }
    catch(std::exception const&)
    {
        wstr.clear();
        return false;
    }

    return true;
}

bool WStrToUtf8(wchar_t const* wstr, size_t size, std::string& utf8str)
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
    catch(std::exception const&)
    {
        utf8str.clear();
        return false;
    }

    return true;
}

bool WStrToUtf8(std::wstring const& wstr, std::string& utf8str)
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
    catch(std::exception const&)
    {
        utf8str.clear();
        return false;
    }

    return true;
}

typedef wchar_t const* const* wstrlist;

void wstrToUpper(std::wstring& str)
{
    std::transform(str.begin(), str.end(), str.begin(), wcharToUpper);
}

void wstrToLower(std::wstring& str)
{
    std::transform(str.begin(), str.end(), str.begin(), wcharToLower);
}

std::wstring GetMainPartOfName(std::wstring const& wname, uint32 declension)
{
    // supported only Cyrillic cases
    if (wname.empty() || !isCyrillicCharacter(wname[0]) || declension > 5)
        return wname;

    // Important: end length must be <= MAX_INTERNAL_PLAYER_NAME-MAX_PLAYER_NAME (3 currently)
    static std::wstring const a_End    = { wchar_t(0x0430), wchar_t(0x0000) };
    static std::wstring const o_End    = { wchar_t(0x043E), wchar_t(0x0000) };
    static std::wstring const ya_End   = { wchar_t(0x044F), wchar_t(0x0000) };
    static std::wstring const ie_End   = { wchar_t(0x0435), wchar_t(0x0000) };
    static std::wstring const i_End    = { wchar_t(0x0438), wchar_t(0x0000) };
    static std::wstring const yeru_End = { wchar_t(0x044B), wchar_t(0x0000) };
    static std::wstring const u_End    = { wchar_t(0x0443), wchar_t(0x0000) };
    static std::wstring const yu_End   = { wchar_t(0x044E), wchar_t(0x0000) };
    static std::wstring const oj_End   = { wchar_t(0x043E), wchar_t(0x0439), wchar_t(0x0000) };
    static std::wstring const ie_j_End = { wchar_t(0x0435), wchar_t(0x0439), wchar_t(0x0000) };
    static std::wstring const io_j_End = { wchar_t(0x0451), wchar_t(0x0439), wchar_t(0x0000) };
    static std::wstring const o_m_End  = { wchar_t(0x043E), wchar_t(0x043C), wchar_t(0x0000) };
    static std::wstring const io_m_End = { wchar_t(0x0451), wchar_t(0x043C), wchar_t(0x0000) };
    static std::wstring const ie_m_End = { wchar_t(0x0435), wchar_t(0x043C), wchar_t(0x0000) };
    static std::wstring const soft_End = { wchar_t(0x044C), wchar_t(0x0000) };
    static std::wstring const j_End    = { wchar_t(0x0439), wchar_t(0x0000) };

    static std::array<std::array<std::wstring const*, 7>, 6> const dropEnds = {{
        { &a_End,  &o_End,    &ya_End,   &ie_End,  &soft_End, &j_End,    nullptr },
        { &a_End,  &ya_End,   &yeru_End, &i_End,   nullptr,   nullptr,   nullptr },
        { &ie_End, &u_End,    &yu_End,   &i_End,   nullptr,   nullptr,   nullptr },
        { &u_End,  &yu_End,   &o_End,    &ie_End,  &soft_End, &ya_End,   &a_End  },
        { &oj_End, &io_j_End, &ie_j_End, &o_m_End, &io_m_End, &ie_m_End, &yu_End },
        { &ie_End, &i_End,    nullptr,   nullptr,  nullptr,   nullptr,   nullptr }
    }};

    std::size_t const thisLen = wname.length();
    std::array<std::wstring const*, 7> const& endings = dropEnds[declension];
    for (auto itr = endings.begin(), end = endings.end(); (itr != end) && *itr; ++itr)
    {
        std::wstring const& ending = **itr;
        std::size_t const endLen = ending.length();
        if (!(endLen <= thisLen))
            continue;

        if (wname.substr(thisLen-endLen, thisLen) == ending)
            return wname.substr(0, thisLen-endLen);
    }

    return wname;
}

bool utf8ToConsole(const std::string& utf8str, std::string& conStr)
{
#if TRINITY_PLATFORM == TRINITY_PLATFORM_WINDOWS
    std::wstring wstr;
    if (!Utf8toWStr(utf8str, wstr))
        return false;

    conStr.resize(wstr.size());
    CharToOemBuffW(&wstr[0], &conStr[0], uint32(wstr.size()));
#else
    // not implemented yet
    conStr = utf8str;
#endif

    return true;
}

bool consoleToUtf8(const std::string& conStr, std::string& utf8str)
{
#if TRINITY_PLATFORM == TRINITY_PLATFORM_WINDOWS
    std::wstring wstr;
    wstr.resize(conStr.size());
    OemToCharBuffW(&conStr[0], &wstr[0], uint32(conStr.size()));

    return WStrToUtf8(wstr, utf8str);
#else
    // not implemented yet
    utf8str = conStr;
    return true;
#endif
}

bool Utf8FitTo(const std::string& str, std::wstring const& search)
{
    std::wstring temp;

    if (!Utf8toWStr(str, temp))
        return false;

    // converting to lower case
    wstrToLower(temp);

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
#if TRINITY_PLATFORM == TRINITY_PLATFORM_WINDOWS
    char temp_buf[32 * 1024];
    wchar_t wtemp_buf[32 * 1024];

    size_t temp_len = vsnprintf(temp_buf, 32 * 1024, str, *ap);
    //vsnprintf returns -1 if the buffer is too small
    if (temp_len == size_t(-1))
        temp_len = 32*1024-1;

    size_t wtemp_len = 32*1024-1;
    Utf8toWStr(temp_buf, temp_len, wtemp_buf, wtemp_len);

    CharToOemBuffW(&wtemp_buf[0], &temp_buf[0], uint32(wtemp_len + 1));
    fprintf(out, "%s", temp_buf);
#else
    vfprintf(out, str, *ap);
#endif
}

bool Utf8ToUpperOnlyLatin(std::string& utf8String)
{
    std::wstring wstr;
    if (!Utf8toWStr(utf8String, wstr))
        return false;

    std::transform(wstr.begin(), wstr.end(), wstr.begin(), wcharToUpperOnlyLatin);

    return WStrToUtf8(wstr, utf8String);
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

void HexStrToByteArray(std::string const& str, uint8* out, bool reverse /*= false*/)
{
    // string must have even number of characters
    if (str.length() & 1)
        return;

    int32 init = 0;
    int32 end = int32(str.length());
    int8 op = 1;

    if (reverse)
    {
        init = int32(str.length() - 2);
        end = -2;
        op = -1;
    }

    uint32 j = 0;
    for (int32 i = init; i != end; i += 2 * op)
    {
        char buffer[3] = { str[i], str[i + 1], '\0' };
        out[j++] = uint8(strtoul(buffer, nullptr, 16));
    }
}

bool StringToBool(std::string const& str)
{
    std::string lowerStr = str;
    std::transform(str.begin(), str.end(), lowerStr.begin(), ::tolower);
    return lowerStr == "1" || lowerStr == "true" || lowerStr == "yes";
}

bool StringContainsStringI(std::string const& haystack, std::string const& needle)
{
    return haystack.end() !=
        std::search(haystack.begin(), haystack.end(), needle.begin(), needle.end(), [](char c1, char c2) { return std::toupper(c1) == std::toupper(c2); });
}
