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
#include "StringConvert.h"
#include "StringFormat.h"
#include <boost/core/demangle.hpp>
#include <utf8.h>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <string>
#include <cctype>
#include <cstdarg>
#include <ctime>

void Trinity::VerifyOsVersion()
{
#if TRINITY_PLATFORM == TRINITY_PLATFORM_WINDOWS
    auto isWindowsBuildGreaterOrEqual = [](DWORD build)
    {
        OSVERSIONINFOEX osvi = { sizeof(osvi), 0, 0, build, 0, {0}, 0, 0, 0, 0 };
        ULONGLONG conditionMask = 0;
        VER_SET_CONDITION(conditionMask, VER_BUILDNUMBER, VER_GREATER_EQUAL);

        return VerifyVersionInfo(&osvi, VER_BUILDNUMBER, conditionMask);
    };

    if (!isWindowsBuildGreaterOrEqual(TRINITY_REQUIRED_WINDOWS_BUILD))
    {
        OSVERSIONINFOEX osvi = { sizeof(osvi), 0, 0, 0, 0, {0}, 0, 0, 0, 0 };
        GetVersionEx((LPOSVERSIONINFO)&osvi);
        ABORT_MSG("TrinityCore requires Windows 10 19H1 (1903) or Windows Server 2019 (1903) - require build number 10.0.%d but found %d.%d.%d",
            TRINITY_REQUIRED_WINDOWS_BUILD, osvi.dwMajorVersion, osvi.dwMinorVersion, osvi.dwBuildNumber);
    }
#endif
}

std::vector<std::string_view> Trinity::Tokenize(std::string_view str, char sep, bool keepEmpty)
{
    std::vector<std::string_view> tokens;

    size_t start = 0;
    for (size_t end = str.find(sep); end != std::string_view::npos; end = str.find(sep, start))
    {
        if (keepEmpty || (start < end))
            tokens.push_back(str.substr(start, end - start));
        start = end+1;
    }

    if (keepEmpty || (start < str.length()))
        tokens.push_back(str.substr(start));

    return tokens;
}

#if (defined(WIN32) || defined(_WIN32) || defined(__WIN32__))
struct tm* localtime_r(time_t const* time, struct tm *result)
{
    if (localtime_s(result, time) != 0)
        return nullptr;
    return result;
}
struct tm* gmtime_r(time_t const* time, struct tm* result)
{
    if (gmtime_s(result, time) != 0)
        return nullptr;
    return result;
}
time_t timegm(struct tm* tm)
{
    return _mkgmtime(tm);
}
#endif

tm TimeBreakdown(time_t time)
{
    tm timeLocal;
    localtime_r(&time, &timeLocal);
    return timeLocal;
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
            return Trinity::StringFormat("{}:{:02}:{:02}:{:02}", days, hours, minutes, secs);
        else if (hours)
            return Trinity::StringFormat("{}:{:02}:{:02}", hours, minutes, secs);
        else if (minutes)
            return Trinity::StringFormat("{}:{:02}", minutes, secs);
        else
            return Trinity::StringFormat("0:{:02}", secs);
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

Optional<int64> MoneyStringToMoney(std::string const& moneyString)
{
    int64 money = 0;

    bool hadG = false;
    bool hadS = false;
    bool hadC = false;

    for (std::string_view token : Trinity::Tokenize(moneyString, ' ', false))
    {
        uint32 unit;
        switch (token[token.length() - 1])
        {
            case 'g':
                if (hadG) return std::nullopt;
                hadG = true;
                unit = 100 * 100;
                break;
            case 's':
                if (hadS) return std::nullopt;
                hadS = true;
                unit = 100;
                break;
            case 'c':
                if (hadC) return std::nullopt;
                hadC = true;
                unit = 1;
                break;
            default:
                return std::nullopt;
        }

        Optional<uint64> amount = Trinity::StringTo<uint32>(token.substr(0, token.length() - 1));
        if (amount)
            money += (unit * *amount);
        else
            return std::nullopt;
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
    return Trinity::StringFormat("{:04}-{:02}-{:02}_{:02}-{:02}-{:02}", aTm.tm_year + 1900, aTm.tm_mon + 1, aTm.tm_mday, aTm.tm_hour, aTm.tm_min, aTm.tm_sec);
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
    catch (std::exception const&)
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
    catch (std::exception const&)
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
    catch (std::exception const&)
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

bool Utf8toWStr(std::string_view utf8str, std::wstring& wstr)
{
    wstr.clear();
    try
    {
        utf8::utf8to16(utf8str.begin(), utf8str.end(), std::back_inserter(wstr));
    }
    catch (std::exception const&)
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
    catch (std::exception const&)
    {
        utf8str.clear();
        return false;
    }

    return true;
}

bool WStrToUtf8(std::wstring_view wstr, std::string& utf8str)
{
    try
    {
        std::string utf8str2;
        utf8str2.resize(wstr.size()*4);                     // allocate for most long case

        if (!wstr.empty())
        {
            char* oend = utf8::utf16to8(wstr.begin(), wstr.end(), &utf8str2[0]);
            utf8str2.resize(oend-(&utf8str2[0]));                // remove unused tail
        }
        utf8str = utf8str2;
    }
    catch (std::exception const&)
    {
        utf8str.clear();
        return false;
    }

    return true;
}

void wstrToUpper(std::wstring& str) { std::transform(std::begin(str), std::end(str), std::begin(str), wcharToUpper); }
void wstrToLower(std::wstring& str) { std::transform(std::begin(str), std::end(str), std::begin(str), wcharToLower); }
void strToUpper(std::string& str) { std::transform(std::begin(str), std::end(str), std::begin(str), charToUpper); }
void strToLower(std::string& str) { std::transform(std::begin(str), std::end(str), std::begin(str), charToLower); }

std::wstring wstrCaseAccentInsensitiveParse(std::wstring_view wstr, LocaleConstant locale)
{
    std::wstring result;
    result.reserve(wstr.length() * 2);

    switch (locale)
    {
        case LOCALE_frFR:
            for (wchar_t wchar : wstr)
            {
                wchar = wcharToLower(wchar);
                switch (wchar)
                {
                    case 0x00A0:                             // NO-BREAK SPACE
                        result += L' ';
                        break;
                    case 0x00AB:                             // LEFT-POINTING DOUBLE ANGLE QUOTATION MARK
                    case 0x00BB:                             // RIGHT-POINTING DOUBLE ANGLE QUOTATION MARK
                        result += L'"';
                        break;
                    case 0x00E7:                             // LATIN SMALL LETTER C WITH CEDILLA
                        result += L'c';
                        break;
                    case 0x00E8:                             // LATIN SMALL LETTER E WITH GRAVE
                    case 0x00E9:                             // LATIN SMALL LETTER E WITH ACUTE
                    case 0x00EA:                             // LATIN SMALL LETTER E WITH CIRCUMFLEX
                    case 0x00EB:                             // LATIN SMALL LETTER E WITH DIAERESIS
                        result += L'e';
                        break;
                    case 0x00EE:                             // LATIN SMALL LETTER I WITH CIRCUMFLEX
                    case 0x00EF:                             // LATIN SMALL LETTER I WITH DIAERESIS
                        result += L'i';
                        break;
                    case 0x00F2:                             // LATIN SMALL LETTER O WITH GRAVE
                    case 0x00F3:                             // LATIN SMALL LETTER O WITH ACUTE
                    case 0x00F4:                             // LATIN SMALL LETTER O WITH CIRCUMFLEX
                    case 0x00F6:                             // LATIN SMALL LETTER O WITH DIAERESIS
                        result += L'o';
                        break;
                    case 0x00F9:                             // LATIN SMALL LETTER U WITH GRAVE
                    case 0x00FA:                             // LATIN SMALL LETTER U WITH ACUTE
                    case 0x00FB:                             // LATIN SMALL LETTER U WITH CIRCUMFLEX
                    case 0x00FC:                             // LATIN SMALL LETTER U WITH DIAERESIS
                        result += L'u';
                        break;
                    case 0x0153:                             // LATIN SMALL LIGATURE OE
                        result += L'o';
                        result += L'e';
                        break;
                    case 0x2013:                             // EN DASH
                        result += L'-';
                        break;
                    case 0x2018:                             // LEFT SINGLE QUOTATION MARK
                    case 0x2019:                             // RIGHT SINGLE QUOTATION MARK
                        result += L'\'';
                        break;
                    default:
                        result += wchar;
                        break;
                }
            }
            break;
        case LOCALE_deDE:
            for (wchar_t wchar : wstr)
            {
                wchar = wcharToLower(wchar);
                if (wchar == 0x00DF)                         // LATIN SMALL LETTER SHARP S
                {
                    result += L's';
                    result += L's';
                }
                else
                    result += wchar;
            }
            break;
        case LOCALE_esES:
        case LOCALE_esMX:
        case LOCALE_itIT:
            for (wchar_t wchar : wstr)
            {
                wchar = wcharToLower(wchar);
                switch (wchar)
                {
                    case 0x00E1:                             // LATIN SMALL LETTER A WITH ACUTE
                        result += L'a';
                        break;
                    case 0x00E9:                             // LATIN SMALL LETTER E WITH ACUTE
                        result += L'e';
                        break;
                    case 0x00ED:                             // LATIN SMALL LETTER I WITH ACUTE
                        result += L'i';
                        break;
                    case 0x00F1:                             // LATIN SMALL LETTER N WITH TILDE
                        result += L'n';
                        break;
                    case 0x00F3:                             // LATIN SMALL LETTER O WITH ACUTE
                        result += L'o';
                        break;
                    case 0x00FA:                             // LATIN SMALL LETTER U WITH ACUTE
                    case 0x00FC:                             // LATIN SMALL LETTER U WITH DIAERESIS
                        result += L'u';
                        break;
                    default:
                        result += wchar;
                        break;
                }
            }
            break;
        case LOCALE_ruRU:
            for (wchar_t wchar : wstr)
            {
                wchar = wcharToLower(wchar);
                switch (wchar)
                {
                    case 0x451:                              // CYRILLIC SMALL LETTER IO
                        result += wchar_t(0x435);
                        break;
                    case 0x2013:                             // EN DASH
                        result += L'-';
                        break;
                    default:
                        result += wchar;
                        break;
                }
            }
            break;
        case LOCALE_ptBR:
            for (wchar_t wchar : wstr)
            {
                wchar = wcharToLower(wchar);
                switch (wchar)
                {
                    case 0x00E0:                             // LATIN SMALL LETTER A WITH GRAVE
                    case 0x00E1:                             // LATIN SMALL LETTER A WITH ACUTE
                    case 0x00E2:                             // LATIN SMALL LETTER A WITH CIRCUMFLEX
                    case 0x00E3:                             // LATIN SMALL LETTER A WITH TILDE
                    case 0x00E4:                             // LATIN SMALL LETTER A WITH DIAERESIS
                        result += L'a';
                        break;
                    case 0x00E7:                             // LATIN SMALL LETTER C WITH CEDILLA
                        result += L'c';
                        break;
                    case 0x00E8:                             // LATIN SMALL LETTER E WITH GRAVE
                    case 0x00E9:                             // LATIN SMALL LETTER E WITH ACUTE
                    case 0x00EA:                             // LATIN SMALL LETTER E WITH CIRCUMFLEX
                    case 0x00EB:                             // LATIN SMALL LETTER E WITH DIAERESIS
                        result += L'e';
                        break;
                    case 0x00EC:                             // LATIN SMALL LETTER I WITH GRAVE
                    case 0x00ED:                             // LATIN SMALL LETTER I WITH ACUTE
                    case 0x00EE:                             // LATIN SMALL LETTER I WITH CIRCUMFLEX
                    case 0x00EF:                             // LATIN SMALL LETTER I WITH DIAERESIS
                        result += L'i';
                        break;
                    case 0x00F1:                             // LATIN SMALL LETTER N WITH TILDE
                        result += L'n';
                        break;
                    case 0x00F2:                             // LATIN SMALL LETTER O WITH GRAVE
                    case 0x00F3:                             // LATIN SMALL LETTER O WITH ACUTE
                    case 0x00F4:                             // LATIN SMALL LETTER O WITH CIRCUMFLEX
                    case 0x00F5:                             // LATIN SMALL LETTER O WITH TILDE
                    case 0x00F6:                             // LATIN SMALL LETTER O WITH DIAERESIS
                        result += L'o';
                        break;
                    case 0x00F9:                             // LATIN SMALL LETTER U WITH GRAVE
                    case 0x00FA:                             // LATIN SMALL LETTER U WITH ACUTE
                    case 0x00FB:                             // LATIN SMALL LETTER U WITH CIRCUMFLEX
                    case 0x00FC:                             // LATIN SMALL LETTER U WITH DIAERESIS
                        result += L'u';
                        break;
                    default:
                        result += wchar;
                        break;
                }
            }
            break;
        default:
            result = wstr;
            wstrToLower(result);
            break;
    }

    return result;
}

std::wstring GetMainPartOfName(std::wstring const& wname, uint32 declension)
{
    // supported only Cyrillic cases
    if (wname.empty() || !isCyrillicCharacter(wname[0]) || declension > 5)
        return wname;

    // Important: end length must be <= MAX_INTERNAL_PLAYER_NAME-MAX_PLAYER_NAME (3 currently)
    static std::wstring const a_End    = { wchar_t(0x0430)                  };
    static std::wstring const o_End    = { wchar_t(0x043E)                  };
    static std::wstring const ya_End   = { wchar_t(0x044F)                  };
    static std::wstring const ie_End   = { wchar_t(0x0435)                  };
    static std::wstring const i_End    = { wchar_t(0x0438)                  };
    static std::wstring const yeru_End = { wchar_t(0x044B)                  };
    static std::wstring const u_End    = { wchar_t(0x0443)                  };
    static std::wstring const yu_End   = { wchar_t(0x044E)                  };
    static std::wstring const oj_End   = { wchar_t(0x043E), wchar_t(0x0439) };
    static std::wstring const ie_j_End = { wchar_t(0x0435), wchar_t(0x0439) };
    static std::wstring const io_j_End = { wchar_t(0x0451), wchar_t(0x0439) };
    static std::wstring const o_m_End  = { wchar_t(0x043E), wchar_t(0x043C) };
    static std::wstring const io_m_End = { wchar_t(0x0451), wchar_t(0x043C) };
    static std::wstring const ie_m_End = { wchar_t(0x0435), wchar_t(0x043C) };
    static std::wstring const soft_End = { wchar_t(0x044C)                  };
    static std::wstring const j_End    = { wchar_t(0x0439)                  };

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

bool utf8ToConsole(std::string_view utf8str, std::string& conStr)
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

bool consoleToUtf8(std::string_view conStr, std::string& utf8str)
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

bool Utf8FitTo(std::string_view str, std::wstring_view search)
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

#if TRINITY_PLATFORM == TRINITY_PLATFORM_WINDOWS
bool ReadWinConsole(std::string& str, size_t size /*= 256*/)
{
    wchar_t* commandbuf = new wchar_t[size + 1];
    HANDLE hConsole = GetStdHandle(STD_INPUT_HANDLE);
    DWORD read = 0;

    if (!ReadConsoleW(hConsole, commandbuf, size, &read, nullptr) || read == 0)
    {
        delete[] commandbuf;
        return false;
    }

    commandbuf[read] = 0;

    bool ok = WStrToUtf8(commandbuf, wcslen(commandbuf), str);
    delete[] commandbuf;
    return ok;
}

bool WriteWinConsole(std::string_view str, bool error /*= false*/)
{
    std::wstring wstr;
    if (!Utf8toWStr(str, wstr))
        return false;

    HANDLE hConsole = GetStdHandle(error ? STD_ERROR_HANDLE : STD_OUTPUT_HANDLE);
    DWORD write = 0;

    return WriteConsoleW(hConsole, wstr.c_str(), wstr.size(), &write, nullptr);
}
#endif

TC_COMMON_API Optional<std::size_t> RemoveCRLF(std::string & str)
{
    std::size_t nextLineIndex = str.find_first_of("\r\n");
    if (nextLineIndex == std::string::npos)
        return std::nullopt;

    str.erase(nextLineIndex);
    return nextLineIndex;
}

std::string Trinity::Impl::ByteArrayToHexStr(uint8 const* bytes, size_t arrayLen, bool reverse /* = false */)
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

    std::string result;
    result.reserve(arrayLen * 2);
    auto inserter = std::back_inserter(result);
    for (int32 i = init; i != end; i += op)
        Trinity::StringFormatTo(inserter, "{:02X}", bytes[i]);

    return result;
}

void Trinity::Impl::HexStrToByteArray(std::string_view str, uint8* out, size_t outlen, bool reverse /*= false*/)
{
    ASSERT(str.size() == (2 * outlen));

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
        out[j++] = Trinity::StringTo<uint8>(str.substr(i, 2), 16).value_or(0);
}

bool StringEqualI(std::string_view a, std::string_view b)
{
    return std::equal(a.begin(), a.end(), b.begin(), b.end(), [](char c1, char c2) { return std::tolower(c1) == std::tolower(c2); });
}

bool StringContainsStringI(std::string_view haystack, std::string_view needle)
{
    return haystack.end() !=
        std::search(haystack.begin(), haystack.end(), needle.begin(), needle.end(), [](char c1, char c2) { return std::tolower(c1) == std::tolower(c2); });
}

bool StringCompareLessI(std::string_view a, std::string_view b)
{
    return std::lexicographical_compare(a.begin(), a.end(), b.begin(), b.end(), [](char c1, char c2) { return std::tolower(c1) < std::tolower(c2); });
}

std::string Trinity::Impl::GetTypeName(std::type_info const& info)
{
    return boost::core::demangle(info.name());
}

float DegToRad(float degrees)
{
    return degrees * (2.f * float(M_PI) / 360.f);
}
