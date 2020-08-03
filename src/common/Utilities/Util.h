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
#include <array>
#include <string>
#include <vector>
#include "advstd.h"

enum LocaleConstant : uint8;

class TC_COMMON_API Tokenizer
{
public:
    typedef std::vector<char const*> StorageType;

    typedef StorageType::size_type size_type;

    typedef StorageType::const_iterator const_iterator;
    typedef StorageType::reference reference;
    typedef StorageType::const_reference const_reference;

public:
    Tokenizer(const std::string &src, char const sep, uint32 vectorReserve = 0, bool keepEmptyStrings = true);
    ~Tokenizer() { delete[] m_str; }

    const_iterator begin() const { return m_storage.begin(); }
    const_iterator end() const { return m_storage.end(); }

    size_type size() const { return m_storage.size(); }

    reference operator [] (size_type i) { return m_storage[i]; }
    const_reference operator [] (size_type i) const { return m_storage[i]; }

private:
    char* m_str;
    StorageType m_storage;
};

TC_COMMON_API void stripLineInvisibleChars(std::string &src);

TC_COMMON_API int64 MoneyStringToMoney(const std::string& moneyString);

TC_COMMON_API struct tm* localtime_r(const time_t* time, struct tm *result);

TC_COMMON_API std::string secsToTimeString(uint64 timeInSecs, bool shortText = false, bool hoursOnly = false);
TC_COMMON_API uint32 TimeStringToSecs(const std::string& timestring);
TC_COMMON_API std::string TimeToTimestampStr(time_t t);

// Percentage calculation
template <class T, class U>
inline T CalculatePct(T base, U pct)
{
    return T(base * static_cast<float>(pct) / 100.0f);
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

// UTF8 handling
TC_COMMON_API bool Utf8toWStr(const std::string& utf8str, std::wstring& wstr);

// in wsize==max size of buffer, out wsize==real string size
TC_COMMON_API bool Utf8toWStr(char const* utf8str, size_t csize, wchar_t* wstr, size_t& wsize);

inline bool Utf8toWStr(const std::string& utf8str, wchar_t* wstr, size_t& wsize)
{
    return Utf8toWStr(utf8str.c_str(), utf8str.size(), wstr, wsize);
}

TC_COMMON_API bool WStrToUtf8(std::wstring const& wstr, std::string& utf8str);
// size==real string size
TC_COMMON_API bool WStrToUtf8(wchar_t* wstr, size_t size, std::string& utf8str);

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

inline bool isEastAsianCharacter(wchar_t wchar)
{
    if (wchar >= 0x1100 && wchar <= 0x11F9)                  // Hangul Jamo
        return true;
    if (wchar >= 0x3041 && wchar <= 0x30FF)                  // Hiragana + Katakana
        return true;
    if (wchar >= 0x3131 && wchar <= 0x318E)                  // Hangul Compatibility Jamo
        return true;
    if (wchar >= 0x31F0 && wchar <= 0x31FF)                  // Katakana Phonetic Ext.
        return true;
    if (wchar >= 0x3400 && wchar <= 0x4DB5)                  // CJK Ideographs Ext. A
        return true;
    if (wchar >= 0x4E00 && wchar <= 0x9FC3)                  // Unified CJK Ideographs
        return true;
    if (wchar >= 0xAC00 && wchar <= 0xD7A3)                  // Hangul Syllables
        return true;
    if (wchar >= 0xFF01 && wchar <= 0xFFEE)                  // Halfwidth forms
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

inline bool isBasicLatinString(const std::wstring &wstr, bool numericOrSpace)
{
    for (size_t i = 0; i < wstr.size(); ++i)
        if (!isBasicLatinCharacter(wstr[i]) && (!numericOrSpace || !isNumericOrSpace(wstr[i])))
            return false;
    return true;
}

inline bool isExtendedLatinString(const std::wstring &wstr, bool numericOrSpace)
{
    for (size_t i = 0; i < wstr.size(); ++i)
        if (!isExtendedLatinCharacter(wstr[i]) && (!numericOrSpace || !isNumericOrSpace(wstr[i])))
            return false;
    return true;
}

inline bool isCyrillicString(const std::wstring &wstr, bool numericOrSpace)
{
    for (size_t i = 0; i < wstr.size(); ++i)
        if (!isCyrillicCharacter(wstr[i]) && (!numericOrSpace || !isNumericOrSpace(wstr[i])))
            return false;
    return true;
}

inline bool isEastAsianString(const std::wstring &wstr, bool numericOrSpace)
{
    for (size_t i = 0; i < wstr.size(); ++i)
        if (!isEastAsianCharacter(wstr[i]) && (!numericOrSpace || !isNumericOrSpace(wstr[i])))
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

TC_COMMON_API std::wstring wstrCaseAccentInsensitiveParse(std::wstring const& wstr, LocaleConstant locale);

TC_COMMON_API void wstrToUpper(std::wstring& str);
TC_COMMON_API void wstrToLower(std::wstring& str);

TC_COMMON_API std::wstring GetMainPartOfName(std::wstring const& wname, uint32 declension);

TC_COMMON_API bool utf8ToConsole(const std::string& utf8str, std::string& conStr);
TC_COMMON_API bool consoleToUtf8(const std::string& conStr, std::string& utf8str);
TC_COMMON_API bool Utf8FitTo(const std::string& str, std::wstring const& search);
TC_COMMON_API void utf8printf(FILE* out, const char *str, ...);
TC_COMMON_API void vutf8printf(FILE* out, const char *str, va_list* ap);
TC_COMMON_API bool Utf8ToUpperOnlyLatin(std::string& utf8String);

TC_COMMON_API bool IsIPAddress(char const* ipaddress);

TC_COMMON_API uint32 CreatePIDFile(std::string const& filename);
TC_COMMON_API uint32 GetPID();

TC_COMMON_API std::string ByteArrayToHexStr(uint8 const* bytes, size_t length, bool reverse = false);
template <typename Container>
std::string ByteArrayToHexStr(Container const& c, bool reverse = false) { return ByteArrayToHexStr(advstd::data(c), advstd::size(c), reverse); }
TC_COMMON_API void HexStrToByteArray(std::string const& str, uint8* out, bool reverse = false);
template <size_t Size>
void HexStrToByteArray(std::string const& str, std::array<uint8, Size>& buf, bool reverse = false)
{
    ASSERT(str.size() == (2 * Size));
    HexStrToByteArray(str, buf.data(), reverse);
}
template <size_t Size>
std::array<uint8, Size> HexStrToByteArray(std::string const& str, bool reverse = false)
{
    std::array<uint8, Size> arr;
    HexStrToByteArray(str, arr, reverse);
    return arr;
}

TC_COMMON_API bool StringToBool(std::string const& str);
TC_COMMON_API float DegToRad(float degrees);

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

class TC_COMMON_API flag128
{
private:
    uint32 part[4];

public:
    flag128(uint32 p1 = 0, uint32 p2 = 0, uint32 p3 = 0, uint32 p4 = 0)
    {
        part[0] = p1;
        part[1] = p2;
        part[2] = p3;
        part[3] = p4;
    }

    inline bool IsEqual(uint32 p1 = 0, uint32 p2 = 0, uint32 p3 = 0, uint32 p4 = 0) const
    {
        return (part[0] == p1 && part[1] == p2 && part[2] == p3 && part[3] == p4);
    }

    inline bool HasFlag(uint32 p1 = 0, uint32 p2 = 0, uint32 p3 = 0, uint32 p4 = 0) const
    {
        return (part[0] & p1 || part[1] & p2 || part[2] & p3 || part[3] & p4);
    }

    inline void Set(uint32 p1 = 0, uint32 p2 = 0, uint32 p3 = 0, uint32 p4 = 0)
    {
        part[0] = p1;
        part[1] = p2;
        part[2] = p3;
        part[3] = p4;
    }

    inline bool operator <(const flag128 &right) const
    {
        for (uint8 i = 4; i > 0; --i)
        {
            if (part[i - 1] < right.part[i - 1])
                return true;
            else if (part[i - 1] > right.part[i - 1])
                return false;
        }
        return false;
    }

    inline bool operator ==(const flag128 &right) const
    {
        return
            (
            part[0] == right.part[0] &&
            part[1] == right.part[1] &&
            part[2] == right.part[2] &&
            part[3] == right.part[3]
            );
    }

    inline bool operator !=(const flag128 &right) const
    {
        return !this->operator ==(right);
    }

    inline flag128 operator &(const flag128 &right) const
    {
        return flag128(part[0] & right.part[0], part[1] & right.part[1],
            part[2] & right.part[2], part[3] & right.part[3]);
    }

    inline flag128 & operator &=(const flag128 &right)
    {
        part[0] &= right.part[0];
        part[1] &= right.part[1];
        part[2] &= right.part[2];
        part[3] &= right.part[3];
        return *this;
    }

    inline flag128 operator |(const flag128 &right) const
    {
        return flag128(part[0] | right.part[0], part[1] | right.part[1],
            part[2] | right.part[2], part[3] | right.part[3]);
    }

    inline flag128 & operator |=(const flag128 &right)
    {
        part[0] |= right.part[0];
        part[1] |= right.part[1];
        part[2] |= right.part[2];
        part[3] |= right.part[3];
        return *this;
    }

    inline flag128 operator ~() const
    {
        return flag128(~part[0], ~part[1], ~part[2], ~part[3]);
    }

    inline flag128 operator ^(const flag128 &right) const
    {
        return flag128(part[0] ^ right.part[0], part[1] ^ right.part[1],
            part[2] ^ right.part[2], part[3] ^ right.part[3]);
    }

    inline flag128 & operator ^=(const flag128 &right)
    {
        part[0] ^= right.part[0];
        part[1] ^= right.part[1];
        part[2] ^= right.part[2];
        part[3] ^= right.part[3];
        return *this;
    }

    inline operator bool() const
    {
        return (part[0] != 0 || part[1] != 0 || part[2] != 0 || part[3] != 0);
    }

    inline bool operator !() const
    {
        return !this->operator bool();
    }

    inline uint32 & operator [](uint8 el)
    {
        return part[el];
    }

    inline const uint32 & operator [](uint8 el) const
    {
        return part[el];
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

template<typename T>
struct NonDefaultConstructible
{
    constexpr /*implicit*/ NonDefaultConstructible(T value) : Value(std::move(value))
    {
    }

    T Value;
};

#endif
