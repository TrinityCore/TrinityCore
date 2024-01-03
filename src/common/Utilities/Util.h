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

#ifndef _UTIL_H
#define _UTIL_H

#include "Define.h"
#include "Errors.h"
#include "Optional.h"

#include <array>
#include <string>
#include <string_view>
#include <typeinfo>
#include <utility>
#include <vector>

enum LocaleConstant : uint8;

enum class TimeFormat : uint8
{
    FullText,       // 1 Days 2 Hours 3 Minutes 4 Seconds
    ShortText,      // 1d 2h 3m 4s
    Numeric         // 1:2:3:4
};

namespace Trinity
{
    TC_COMMON_API void VerifyOsVersion();

    TC_COMMON_API std::vector<std::string_view> Tokenize(std::string_view str, char sep, bool keepEmpty);

    /* this would return string_view into temporary otherwise */
    std::vector<std::string_view> Tokenize(std::string&&, char, bool) = delete;
    std::vector<std::string_view> Tokenize(std::string const&&, char, bool) = delete;

    /* the delete overload means we need to make this explicit */
    inline std::vector<std::string_view> Tokenize(char const* str, char sep, bool keepEmpty) { return Tokenize(std::string_view(str ? str : ""), sep, keepEmpty); }
}

TC_COMMON_API Optional<int64> MoneyStringToMoney(std::string const& moneyString);

#if (defined(WIN32) || defined(_WIN32) || defined(__WIN32__))
TC_COMMON_API struct tm* localtime_r(time_t const* time, struct tm *result);
TC_COMMON_API struct tm* gmtime_r(time_t const* time, struct tm *result);
TC_COMMON_API time_t timegm(struct tm* tm);
#endif
TC_COMMON_API time_t GetLocalHourTimestamp(time_t time, uint8 hour, bool onlyAfterTime = true);
TC_COMMON_API tm TimeBreakdown(time_t t);

TC_COMMON_API std::string secsToTimeString(uint64 timeInSecs, TimeFormat timeFormat = TimeFormat::FullText, bool hoursOnly = false);
TC_COMMON_API uint32 TimeStringToSecs(std::string const& timestring);
TC_COMMON_API std::string TimeToTimestampStr(time_t t);
TC_COMMON_API std::string TimeToHumanReadable(time_t t);

// Percentage calculation
template <class T, class U>
inline T CalculatePct(T base, U pct)
{
    return T(base * static_cast<float>(pct) / 100.0f);
}

template <class T>
inline float GetPctOf(T value, T max)
{
    ASSERT(max);
    return float(static_cast<float>(value) / static_cast<float>(max) * 100.0f);
}

template <class T, class U>
inline T AddPct(T &base, U pct)
{
    return base += CalculatePct(base, pct);
}

template <class T, class U>
inline T ApplyPct(T &base, U pct)
{
    return base = CalculatePct(base, pct);
}

template <class T>
inline T RoundToInterval(T& num, T floor, T ceil)
{
    return num = std::min(std::max(num, floor), ceil);
}

template <class T>
inline T square(T x) { return x*x; }

// UTF8 handling
TC_COMMON_API bool Utf8toWStr(std::string_view utf8str, std::wstring& wstr);

// in wsize==max size of buffer, out wsize==real string size
TC_COMMON_API bool Utf8toWStr(char const* utf8str, size_t csize, wchar_t* wstr, size_t& wsize);

inline bool Utf8toWStr(std::string_view utf8str, wchar_t* wstr, size_t& wsize)
{
    return Utf8toWStr(utf8str.data(), utf8str.size(), wstr, wsize);
}

TC_COMMON_API bool WStrToUtf8(std::wstring_view wstr, std::string& utf8str);
// size==real string size
TC_COMMON_API bool WStrToUtf8(wchar_t const* wstr, size_t size, std::string& utf8str);

// set string to "" if invalid utf8 sequence
TC_COMMON_API size_t utf8length(std::string& utf8str);
TC_COMMON_API void utf8truncate(std::string& utf8str, size_t len);

inline bool isBasicLatinCharacter(wchar_t wchar)
{
    if (wchar >= L'a' && wchar <= L'z')                      // LATIN SMALL LETTER A - LATIN SMALL LETTER Z
        return true;
    if (wchar >= L'A' && wchar <= L'Z')                      // LATIN CAPITAL LETTER A - LATIN CAPITAL LETTER Z
        return true;
    return false;
}

inline bool isExtendedLatinCharacter(wchar_t wchar)
{
    if (isBasicLatinCharacter(wchar))
        return true;
    if (wchar >= 0x00C0 && wchar <= 0x00D6)                  // LATIN CAPITAL LETTER A WITH GRAVE - LATIN CAPITAL LETTER O WITH DIAERESIS
        return true;
    if (wchar >= 0x00D8 && wchar <= 0x00DE)                  // LATIN CAPITAL LETTER O WITH STROKE - LATIN CAPITAL LETTER THORN
        return true;
    if (wchar == 0x00DF)                                     // LATIN SMALL LETTER SHARP S
        return true;
    if (wchar >= 0x00E0 && wchar <= 0x00F6)                  // LATIN SMALL LETTER A WITH GRAVE - LATIN SMALL LETTER O WITH DIAERESIS
        return true;
    if (wchar >= 0x00F8 && wchar <= 0x00FE)                  // LATIN SMALL LETTER O WITH STROKE - LATIN SMALL LETTER THORN
        return true;
    if (wchar >= 0x0100 && wchar <= 0x012F)                  // LATIN CAPITAL LETTER A WITH MACRON - LATIN SMALL LETTER I WITH OGONEK
        return true;
    if (wchar == 0x1E9E)                                     // LATIN CAPITAL LETTER SHARP S
        return true;
    return false;
}

inline bool isCyrillicCharacter(wchar_t wchar)
{
    if (wchar >= 0x0410 && wchar <= 0x044F)                  // CYRILLIC CAPITAL LETTER A - CYRILLIC SMALL LETTER YA
        return true;
    if (wchar == 0x0401 || wchar == 0x0451)                  // CYRILLIC CAPITAL LETTER IO, CYRILLIC SMALL LETTER IO
        return true;
    return false;
}

inline bool isKoreanCharacter(wchar_t wchar)
{
    if (wchar >= 0x1100 && wchar <= 0x11F9)                  // Hangul Jamo
        return true;
    if (wchar >= 0x3131 && wchar <= 0x318E)                  // Hangul Compatibility Jamo
        return true;
    if (wchar >= 0xAC00 && wchar <= 0xD7A3)                  // Hangul Syllables
        return true;
    if (wchar >= 0xFF01 && wchar <= 0xFFEE)                  // Halfwidth forms
        return true;
    return false;
}

inline bool isChineseCharacter(wchar_t wchar)
{
    if (wchar >= 0x4E00 && wchar <= 0x9FFF)                  // Unified CJK Ideographs
        return true;
    if (wchar >= 0x3400 && wchar <= 0x4DBF)                  // CJK Ideographs Ext. A
        return true;
    if (wchar >= 0x3100 && wchar <= 0x312C)                  // Bopomofo
        return true;
    if (wchar >= 0xF900 && wchar <= 0xFAFF)                  // CJK Compatibility Ideographs
        return true;
    return false;
}

inline bool isNumeric(wchar_t wchar)
{
    return (wchar >= L'0' && wchar <=L'9');
}

inline bool isNumeric(char c)
{
    return (c >= '0' && c <='9');
}

inline bool isNumeric(char const* str)
{
    for (char const* c = str; *c; ++c)
        if (!isNumeric(*c))
            return false;

    return true;
}

inline bool isNumericOrSpace(wchar_t wchar)
{
    return isNumeric(wchar) || wchar == L' ';
}

inline bool isBasicLatinString(std::wstring_view wstr, bool numericOrSpace)
{
    for (wchar_t c : wstr)
        if (!isBasicLatinCharacter(c) && (!numericOrSpace || !isNumericOrSpace(c)))
            return false;
    return true;
}

inline bool isExtendedLatinString(std::wstring_view wstr, bool numericOrSpace)
{
    for (wchar_t c : wstr)
        if (!isExtendedLatinCharacter(c) && (!numericOrSpace || !isNumericOrSpace(c)))
            return false;
    return true;
}

inline bool isCyrillicString(std::wstring_view wstr, bool numericOrSpace)
{
    for (wchar_t c : wstr)
        if (!isCyrillicCharacter(c) && (!numericOrSpace || !isNumericOrSpace(c)))
            return false;
    return true;
}

inline bool isKoreanString(std::wstring_view wstr, bool numericOrSpace)
{
    for (wchar_t c : wstr)
        if (!isKoreanCharacter(c) && (!numericOrSpace || !isNumericOrSpace(c)))
            return false;
    return true;
}

inline bool isChineseString(std::wstring_view wstr, bool numericOrSpace)
{
    for (wchar_t c : wstr)
        if (!isChineseCharacter(c) && (!numericOrSpace || !isNumericOrSpace(c)))
            return false;
    return true;
}

inline wchar_t wcharToUpper(wchar_t wchar)
{
    if (wchar >= L'a' && wchar <= L'z')                      // LATIN SMALL LETTER A - LATIN SMALL LETTER Z
        return wchar_t(uint16(wchar)-0x0020);
    if (wchar == 0x00DF)                                     // LATIN SMALL LETTER SHARP S
        return wchar_t(0x1E9E);
    if (wchar >= 0x00E0 && wchar <= 0x00F6)                  // LATIN SMALL LETTER A WITH GRAVE - LATIN SMALL LETTER O WITH DIAERESIS
        return wchar_t(uint16(wchar)-0x0020);
    if (wchar >= 0x00F8 && wchar <= 0x00FE)                  // LATIN SMALL LETTER O WITH STROKE - LATIN SMALL LETTER THORN
        return wchar_t(uint16(wchar)-0x0020);
    if (wchar >= 0x0101 && wchar <= 0x012F)                  // LATIN SMALL LETTER A WITH MACRON - LATIN SMALL LETTER I WITH OGONEK (only %2=1)
    {
        if (wchar % 2 == 1)
            return wchar_t(uint16(wchar)-0x0001);
    }
    if (wchar >= 0x0430 && wchar <= 0x044F)                  // CYRILLIC SMALL LETTER A - CYRILLIC SMALL LETTER YA
        return wchar_t(uint16(wchar)-0x0020);
    if (wchar == 0x0451)                                     // CYRILLIC SMALL LETTER IO
        return wchar_t(0x0401);
    if (wchar == 0x0153)                                     // LATIN SMALL LIGATURE OE
        return wchar_t(0x0152);
    if (wchar == 0x00FF)                                     // LATIN SMALL LETTER Y WITH DIAERESIS
        return wchar_t(0x0178);

    return wchar;
}

inline wchar_t wcharToUpperOnlyLatin(wchar_t wchar)
{
    return isBasicLatinCharacter(wchar) ? wcharToUpper(wchar) : wchar;
}

inline wchar_t wcharToLower(wchar_t wchar)
{
    if (wchar >= L'A' && wchar <= L'Z')                      // LATIN CAPITAL LETTER A - LATIN CAPITAL LETTER Z
        return wchar_t(uint16(wchar)+0x0020);
    if (wchar >= 0x00C0 && wchar <= 0x00D6)                  // LATIN CAPITAL LETTER A WITH GRAVE - LATIN CAPITAL LETTER O WITH DIAERESIS
        return wchar_t(uint16(wchar)+0x0020);
    if (wchar >= 0x00D8 && wchar <= 0x00DE)                  // LATIN CAPITAL LETTER O WITH STROKE - LATIN CAPITAL LETTER THORN
        return wchar_t(uint16(wchar)+0x0020);
    if (wchar >= 0x0100 && wchar <= 0x012E)                  // LATIN CAPITAL LETTER A WITH MACRON - LATIN CAPITAL LETTER I WITH OGONEK (only %2=0)
    {
        if (wchar % 2 == 0)
            return wchar_t(uint16(wchar)+0x0001);
    }
    if (wchar == 0x1E9E)                                     // LATIN CAPITAL LETTER SHARP S
        return wchar_t(0x00DF);
    if (wchar == 0x0401)                                     // CYRILLIC CAPITAL LETTER IO
        return wchar_t(0x0451);
    if (wchar == 0x0152)                                     // LATIN CAPITAL LIGATURE OE
        return wchar_t(0x0153);
    if (wchar == 0x0178)                                     // LATIN CAPITAL LETTER Y WITH DIAERESIS
        return wchar_t(0x00FF);
    if (wchar >= 0x0410 && wchar <= 0x042F)                  // CYRILLIC CAPITAL LETTER A - CYRILLIC CAPITAL LETTER YA
        return wchar_t(uint16(wchar)+0x0020);

    return wchar;
}

inline bool isLower(wchar_t wchar)
{
    if (wchar >= L'a' && wchar <= L'z')                      // LATIN CAPITAL LETTER A - LATIN CAPITAL LETTER Z
        return true;
    if (wchar >= 0x00E0 && wchar <= 0x00FF)                  // LATIN SMALL LETTER A WITH GRAVE - LATIN SMALL LETTER Y WITH DIAERESIS
        return true;
    if (wchar >= 0x0430 && wchar <= 0x044F)                  // CYRILLIC SMALL LETTER A - CYRILLIC SMALL LETTER YA
        return true;
    if (wchar == 0x0451)                                     // CYRILLIC SMALL LETTER IO
        return true;
    return false;
}

inline bool isUpper(wchar_t wchar)
{
    return !isLower(wchar);
}

inline char charToUpper(char c) { return std::toupper(c); }
inline char charToLower(char c) { return std::tolower(c); }

TC_COMMON_API void wstrToUpper(std::wstring& str);
TC_COMMON_API void wstrToLower(std::wstring& str);
TC_COMMON_API void strToUpper(std::string& str);
TC_COMMON_API void strToLower(std::string& str);

TC_COMMON_API std::wstring wstrCaseAccentInsensitiveParse(std::wstring_view wstr, LocaleConstant locale);

TC_COMMON_API std::wstring GetMainPartOfName(std::wstring const& wname, uint32 declension);

TC_COMMON_API bool utf8ToConsole(std::string_view utf8str, std::string& conStr);
TC_COMMON_API bool consoleToUtf8(std::string_view conStr, std::string& utf8str);
TC_COMMON_API bool Utf8FitTo(std::string_view str, std::wstring_view search);
TC_COMMON_API void utf8printf(FILE* out, const char *str, ...);
TC_COMMON_API void vutf8printf(FILE* out, const char *str, va_list* ap);
TC_COMMON_API bool Utf8ToUpperOnlyLatin(std::string& utf8String);

#if TRINITY_PLATFORM == TRINITY_PLATFORM_WINDOWS
TC_COMMON_API bool ReadWinConsole(std::string& str, size_t size = 256);
TC_COMMON_API bool WriteWinConsole(std::string_view str, bool error = false);
#endif

TC_COMMON_API Optional<std::size_t> RemoveCRLF(std::string& str);

TC_COMMON_API bool IsIPAddress(char const* ipaddress);

TC_COMMON_API uint32 CreatePIDFile(std::string const& filename);
TC_COMMON_API uint32 GetPID();

namespace Trinity::Impl
{
    TC_COMMON_API std::string ByteArrayToHexStr(uint8 const* bytes, size_t length, bool reverse = false);
    TC_COMMON_API void HexStrToByteArray(std::string_view str, uint8* out, size_t outlen, bool reverse = false);
}

template <typename Container>
std::string ByteArrayToHexStr(Container const& c, bool reverse = false)
{
    return Trinity::Impl::ByteArrayToHexStr(std::data(c), std::size(c), reverse);
}

template <size_t Size>
void HexStrToByteArray(std::string_view str, std::array<uint8, Size>& buf, bool reverse = false)
{
    Trinity::Impl::HexStrToByteArray(str, buf.data(), Size, reverse);
}
template <size_t Size>
std::array<uint8, Size> HexStrToByteArray(std::string_view str, bool reverse = false)
{
    std::array<uint8, Size> arr;
    HexStrToByteArray(str, arr, reverse);
    return arr;
}

inline std::vector<uint8> HexStrToByteVector(std::string_view str, bool reverse = false)
{
    std::vector<uint8> buf;
    size_t const sz = (str.size() / 2);
    buf.resize(sz);
    Trinity::Impl::HexStrToByteArray(str, buf.data(), sz, reverse);
    return buf;
}

TC_COMMON_API float DegToRad(float degrees);

TC_COMMON_API bool StringEqualI(std::string_view str1, std::string_view str2);
inline bool StringStartsWith(std::string_view haystack, std::string_view needle) { return (haystack.substr(0, needle.length()) == needle); }
inline bool StringStartsWithI(std::string_view haystack, std::string_view needle) { return StringEqualI(haystack.substr(0, needle.length()), needle); }
TC_COMMON_API bool StringContainsStringI(std::string_view haystack, std::string_view needle);
template <typename T>
inline bool ValueContainsStringI(std::pair<T, std::string_view> const& haystack, std::string_view needle)
{
    return StringContainsStringI(haystack.second, needle);
}
TC_COMMON_API bool StringCompareLessI(std::string_view a, std::string_view b);

struct StringCompareLessI_T
{
    bool operator()(std::string_view a, std::string_view b) const { return StringCompareLessI(a, b); }
};

// simple class for not-modifyable list
template <typename T>
class HookList final
{
    private:
        typedef std::vector<T> ContainerType;

        ContainerType _container;

    public:
        typedef typename ContainerType::const_iterator const_iterator;
        typedef typename ContainerType::iterator iterator;

        HookList<T>& operator+=(T&& t)
        {
            _container.push_back(std::move(t));
            return *this;
        }

        size_t size() const
        {
            return _container.size();
        }

        iterator begin()
        {
            return _container.begin();
        }

        iterator end()
        {
            return _container.end();
        }

        const_iterator begin() const
        {
            return _container.begin();
        }

        const_iterator end() const
        {
            return _container.end();
        }
};

enum ComparisionType
{
    COMP_TYPE_EQ = 0,
    COMP_TYPE_HIGH,
    COMP_TYPE_LOW,
    COMP_TYPE_HIGH_EQ,
    COMP_TYPE_LOW_EQ,
    COMP_TYPE_MAX
};

template <class T>
bool CompareValues(ComparisionType type, T val1, T val2)
{
    switch (type)
    {
        case COMP_TYPE_EQ:
            return val1 == val2;
        case COMP_TYPE_HIGH:
            return val1 > val2;
        case COMP_TYPE_LOW:
            return val1 < val2;
        case COMP_TYPE_HIGH_EQ:
            return val1 >= val2;
        case COMP_TYPE_LOW_EQ:
            return val1 <= val2;
        default:
            // incorrect parameter
            ABORT();
            return false;
    }
}

template<typename E>
constexpr typename std::underlying_type<E>::type AsUnderlyingType(E enumValue)
{
    static_assert(std::is_enum<E>::value, "AsUnderlyingType can only be used with enums");
    return static_cast<typename std::underlying_type<E>::type>(enumValue);
}

template<typename Ret, typename T1, typename... T>
Ret* Coalesce(T1* first, T*... rest)
{
    if constexpr (sizeof...(T) > 0)
        return (first ? static_cast<Ret*>(first) : Coalesce<Ret>(rest...));
    else
        return static_cast<Ret*>(first);
}

namespace Trinity
{
namespace Impl
{
    TC_COMMON_API std::string GetTypeName(std::type_info const&);
}

template <typename T>
std::string GetTypeName() { return Impl::GetTypeName(typeid(T)); }
template <typename T>
std::string GetTypeName(T&& v)
{
    if constexpr (std::is_same_v<std::remove_cv_t<T>, std::type_info>)
        return Impl::GetTypeName(v);
    else
        return Impl::GetTypeName(typeid(v));
}
}

template<typename T>
struct NonDefaultConstructible
{
    constexpr /*implicit*/ NonDefaultConstructible(T value) : Value(std::move(value))
    {
    }

    T Value;
};

#endif
