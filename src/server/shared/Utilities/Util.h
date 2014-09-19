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

#ifndef _UTIL_H
#define _UTIL_H

#include "Define.h"
#include "Errors.h"

#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <map>

// Searcher for map of structs
template<typename T, class S> struct Finder
{
    T val_;
    T S::* idMember_;

    Finder(T val, T S::* idMember) : val_(val), idMember_(idMember) {}
    bool operator()(const std::pair<int, S> &obj) { return obj.second.*idMember_ == val_; }
};

class Tokenizer
{
public:
    typedef std::vector<char const*> StorageType;

    typedef StorageType::size_type size_type;

    typedef StorageType::const_iterator const_iterator;
    typedef StorageType::reference reference;
    typedef StorageType::const_reference const_reference;

public:
    Tokenizer(const std::string &src, char const sep, uint32 vectorReserve = 0);
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

void stripLineInvisibleChars(std::string &src);

int32 MoneyStringToMoney(const std::string& moneyString);

struct tm* localtime_r(const time_t* time, struct tm *result);

std::string secsToTimeString(uint64 timeInSecs, bool shortText = false, bool hoursOnly = false);
uint32 TimeStringToSecs(const std::string& timestring);
std::string TimeToTimestampStr(time_t t);

/* Return a random number in the range min..max. */
int32 irand(int32 min, int32 max);

/* Return a random number in the range min..max (inclusive). */
uint32 urand(uint32 min, uint32 max);

/* Return a random number in the range 0 .. UINT32_MAX. */
uint32 rand32();

/* Return a random number in the range min..max */
float frand(float min, float max);

/* Return a random double from 0.0 to 1.0 (exclusive). */
double rand_norm();

/* Return a random double from 0.0 to 100.0 (exclusive). */
double rand_chance();

/* Return true if a random roll fits in the specified chance (range 0-100). */
inline bool roll_chance_f(float chance)
{
    return chance > rand_chance();
}

/* Return true if a random roll fits in the specified chance (range 0-100). */
inline bool roll_chance_i(int chance)
{
    return chance > irand(0, 99);
}

inline void ApplyPercentModFloatVar(float& var, float val, bool apply)
{
    if (val == -100.0f)     // prevent set var to zero
        val = -99.99f;
    var *= (apply ? (100.0f + val) / 100.0f : 100.0f / (100.0f + val));
}

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
bool Utf8toWStr(const std::string& utf8str, std::wstring& wstr);
// in wsize==max size of buffer, out wsize==real string size
bool Utf8toWStr(char const* utf8str, size_t csize, wchar_t* wstr, size_t& wsize);
inline bool Utf8toWStr(const std::string& utf8str, wchar_t* wstr, size_t& wsize)
{
    return Utf8toWStr(utf8str.c_str(), utf8str.size(), wstr, wsize);
}

bool WStrToUtf8(std::wstring const& wstr, std::string& utf8str);
// size==real string size
bool WStrToUtf8(wchar_t* wstr, size_t size, std::string& utf8str);

size_t utf8length(std::string& utf8str);                    // set string to "" if invalid utf8 sequence
void utf8truncate(std::string& utf8str, size_t len);

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
    if (wchar >= 0x0410 && wchar <= 0x042F)                  // CYRILLIC CAPITAL LETTER A - CYRILLIC CAPITAL LETTER YA
        return wchar_t(uint16(wchar)+0x0020);

    return wchar;
}

inline void wstrToUpper(std::wstring& str)
{
    std::transform( str.begin(), str.end(), str.begin(), wcharToUpper );
}

inline void wstrToLower(std::wstring& str)
{
    std::transform( str.begin(), str.end(), str.begin(), wcharToLower );
}

std::wstring GetMainPartOfName(std::wstring const& wname, uint32 declension);

bool utf8ToConsole(const std::string& utf8str, std::string& conStr);
bool consoleToUtf8(const std::string& conStr, std::string& utf8str);
bool Utf8FitTo(const std::string& str, std::wstring const& search);
void utf8printf(FILE* out, const char *str, ...);
void vutf8printf(FILE* out, const char *str, va_list* ap);

bool IsIPAddress(char const* ipaddress);

uint32 CreatePIDFile(const std::string& filename);

std::string ByteArrayToHexStr(uint8 const* bytes, uint32 length, bool reverse = false);

// simple class for not-modifyable list
template <typename T>
class HookList
{
    typedef typename std::list<T>::iterator ListIterator;
    private:
        typename std::list<T> m_list;
    public:
        HookList<T> & operator+=(T t)
        {
            m_list.push_back(t);
            return *this;
        }
        HookList<T> & operator-=(T t)
        {
            m_list.remove(t);
            return *this;
        }
        size_t size()
        {
            return m_list.size();
        }
        ListIterator begin()
        {
            return m_list.begin();
        }
        ListIterator end()
        {
            return m_list.end();
        }
};

class flag96
{
private:
    uint32 part[3];

public:
    flag96(uint32 p1 = 0, uint32 p2 = 0, uint32 p3 = 0)
    {
        part[0] = p1;
        part[1] = p2;
        part[2] = p3;
    }

    inline bool IsEqual(uint32 p1 = 0, uint32 p2 = 0, uint32 p3 = 0) const
    {
        return (part[0] == p1 && part[1] == p2 && part[2] == p3);
    }

    inline bool HasFlag(uint32 p1 = 0, uint32 p2 = 0, uint32 p3 = 0) const
    {
        return (part[0] & p1 || part[1] & p2 || part[2] & p3);
    }

    inline void Set(uint32 p1 = 0, uint32 p2 = 0, uint32 p3 = 0)
    {
        part[0] = p1;
        part[1] = p2;
        part[2] = p3;
    }

    inline bool operator <(const flag96 &right) const
    {
        for (uint8 i = 3; i > 0; --i)
        {
            if (part[i - 1] < right.part[i - 1])
                return true;
            else if (part[i - 1] > right.part[i - 1])
                return false;
        }
        return false;
    }

    inline bool operator ==(const flag96 &right) const
    {
        return
        (
            part[0] == right.part[0] &&
            part[1] == right.part[1] &&
            part[2] == right.part[2]
        );
    }

    inline bool operator !=(const flag96 &right) const
    {
        return !this->operator ==(right);
    }

    inline flag96 & operator =(const flag96 &right)
    {
        part[0] = right.part[0];
        part[1] = right.part[1];
        part[2] = right.part[2];
        return *this;
    }

    inline flag96 operator &(const flag96 &right) const
    {
        return flag96(part[0] & right.part[0], part[1] & right.part[1],
            part[2] & right.part[2]);
    }

    inline flag96 & operator &=(const flag96 &right)
    {
        part[0] &= right.part[0];
        part[1] &= right.part[1];
        part[2] &= right.part[2];
        return *this;
    }

    inline flag96 operator |(const flag96 &right) const
    {
        return flag96(part[0] | right.part[0], part[1] | right.part[1],
            part[2] | right.part[2]);
    }

    inline flag96 & operator |=(const flag96 &right)
    {
        part[0] |= right.part[0];
        part[1] |= right.part[1];
        part[2] |= right.part[2];
        return *this;
    }

    inline flag96 operator ~() const
    {
        return flag96(~part[0], ~part[1], ~part[2]);
    }

    inline flag96 operator ^(const flag96 &right) const
    {
        return flag96(part[0] ^ right.part[0], part[1] ^ right.part[1],
            part[2] ^ right.part[2]);
    }

    inline flag96 & operator ^=(const flag96 &right)
    {
        part[0] ^= right.part[0];
        part[1] ^= right.part[1];
        part[2] ^= right.part[2];
        return *this;
    }

    inline operator bool() const
    {
        return (part[0] != 0 || part[1] != 0 || part[2] != 0);
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
            ASSERT(false);
            return false;
    }
}

class EventMap
{
    /**
    * Internal storage type.
    * Key: Time as uint32 when the event should occur.
    * Value: The event data as uint32.
    *
    * Structure of event data:
    * - Bit  0 - 15: Event Id.
    * - Bit 16 - 23: Group
    * - Bit 24 - 31: Phase
    * - Pattern: 0xPPGGEEEE
    */
    typedef std::multimap<uint32, uint32> EventStore;

    public:
        EventMap() : _time(0), _phase(0), _lastEvent(0) { }

        /**
        * @name Reset
        * @brief Removes all scheduled events and resets time and phase.
        */
        void Reset()
        {
            _eventMap.clear();
            _time = 0;
            _phase = 0;
        }

        /**
         * @name Update
         * @brief Updates the timer of the event map.
         * @param time Value to be added to time.
         */
        void Update(uint32 time)
        {
            _time += time;
        }

        /**
        * @name GetTimer
        * @return Current timer value.
        */
        uint32 GetTimer() const
        {
            return _time;
        }

        /**
        * @name GetPhaseMask
        * @return Active phases as mask.
        */
        uint8 GetPhaseMask() const
        {
            return _phase;
        }

        /**
        * @name Empty
        * @return True, if there are no events scheduled.
        */
        bool Empty() const
        {
            return _eventMap.empty();
        }

        /**
        * @name SetPhase
        * @brief Sets the phase of the map (absolute).
        * @param phase Phase which should be set. Values: 1 - 8. 0 resets phase.
        */
        void SetPhase(uint8 phase)
        {
            if (!phase)
                _phase = 0;
            else if (phase <= 8)
                _phase = uint8(1 << (phase - 1));
        }

        /**
        * @name AddPhase
        * @brief Activates the given phase (bitwise).
        * @param phase Phase which should be activated. Values: 1 - 8
        */
        void AddPhase(uint8 phase)
        {
            if (phase && phase <= 8)
                _phase |= uint8(1 << (phase - 1));
        }

        /**
        * @name RemovePhase
        * @brief Deactivates the given phase (bitwise).
        * @param phase Phase which should be deactivated. Values: 1 - 8.
        */
        void RemovePhase(uint8 phase)
        {
            if (phase && phase <= 8)
                _phase &= uint8(~(1 << (phase - 1)));
        }

        /**
        * @name ScheduleEvent
        * @brief Creates new event entry in map.
        * @param eventId The id of the new event.
        * @param time The time in milliseconds until the event occurs.
        * @param group The group which the event is associated to. Has to be between 1 and 8. 0 means it has no group.
        * @param phase The phase in which the event can occur. Has to be between 1 and 8. 0 means it can occur in all phases.
        */
        void ScheduleEvent(uint32 eventId, uint32 time, uint32 group = 0, uint8 phase = 0)
        {
            if (group && group <= 8)
                eventId |= (1 << (group + 15));

            if (phase && phase <= 8)
                eventId |= (1 << (phase + 23));

            _eventMap.insert(EventStore::value_type(_time + time, eventId));
        }

        /**
        * @name RescheduleEvent
        * @brief Cancels the given event and reschedules it.
        * @param eventId The id of the event.
        * @param time The time in milliseconds until the event occurs.
        * @param group The group which the event is associated to. Has to be between 1 and 8. 0 means it has no group.
        * @param phase The phase in which the event can occur. Has to be between 1 and 8. 0 means it can occur in all phases.
        */
        void RescheduleEvent(uint32 eventId, uint32 time, uint32 group = 0, uint8 phase = 0)
        {
            CancelEvent(eventId);
            ScheduleEvent(eventId, time, group, phase);
        }

        /**
        * @name RepeatEvent
        * @brief Repeats the mostly recently executed event.
        * @param time Time until the event occurs.
        */
        void Repeat(uint32 time)
        {
            _eventMap.insert(EventStore::value_type(_time + time, _lastEvent));
        }

        /**
        * @name RepeatEvent
        * @brief Repeats the mostly recently executed event.
        * @param time Time until the event occurs. Equivalent to Repeat(urand(minTime, maxTime).
        */
        void Repeat(uint32 minTime, uint32 maxTime)
        {
            Repeat(urand(minTime, maxTime));
        }

        /**
        * @name ExecuteEvent
        * @brief Returns the next event to execute and removes it from map.
        * @return Id of the event to execute.
        */
        uint32 ExecuteEvent()
        {
            while (!Empty())
            {
                EventStore::iterator itr = _eventMap.begin();

                if (itr->first > _time)
                    return 0;
                else if (_phase && (itr->second & 0xFF000000) && !((itr->second >> 24) & _phase))
                    _eventMap.erase(itr);
                else
                {
                    uint32 eventId = (itr->second & 0x0000FFFF);
                    _lastEvent = itr->second; // include phase/group
                    _eventMap.erase(itr);
                    return eventId;
                }
            }

            return 0;
        }

        /**
        * @name DelayEvents
        * @brief Delays all events in the map. If delay is greater than or equal internal timer, delay will be 0.
        * @param delay Amount of delay.
        */
        void DelayEvents(uint32 delay)
        {
            _time = delay < _time ? _time - delay : 0;
        }

        /**
        * @name DelayEvents
        * @brief Delay all events of the same group.
        * @param delay Amount of delay.
        * @param group Group of the events.
        */
        void DelayEvents(uint32 delay, uint32 group)
        {
            if (!group || group > 8 || Empty())
                return;

            EventStore delayed;

            for (EventStore::iterator itr = _eventMap.begin(); itr != _eventMap.end();)
            {
                if (itr->second & (1 << (group + 15)))
                {
                    delayed.insert(EventStore::value_type(itr->first + delay, itr->second));
                    _eventMap.erase(itr++);
                }
                else
                    ++itr;
            }

            _eventMap.insert(delayed.begin(), delayed.end());
        }

        /**
        * @name CancelEvent
        * @brief Cancels all events of the specified id.
        * @param eventId Event id to cancel.
        */
        void CancelEvent(uint32 eventId)
        {
            if (Empty())
                return;

            for (EventStore::iterator itr = _eventMap.begin(); itr != _eventMap.end();)
            {
                if (eventId == (itr->second & 0x0000FFFF))
                    _eventMap.erase(itr++);
                else
                    ++itr;
            }
        }

        /**
        * @name CancelEventGroup
        * @brief Cancel events belonging to specified group.
        * @param group Group to cancel.
        */
        void CancelEventGroup(uint32 group)
        {
            if (!group || group > 8 || Empty())
                return;

            for (EventStore::iterator itr = _eventMap.begin(); itr != _eventMap.end();)
            {
                if (itr->second & (1 << (group + 15)))
                    _eventMap.erase(itr++);
                else
                    ++itr;
            }
        }

        /**
        * @name GetNextEventTime
        * @brief Returns closest occurence of specified event.
        * @param eventId Wanted event id.
        * @return Time of found event.
        */
        uint32 GetNextEventTime(uint32 eventId) const
        {
            if (Empty())
                return 0;

            for (EventStore::const_iterator itr = _eventMap.begin(); itr != _eventMap.end(); ++itr)
                if (eventId == (itr->second & 0x0000FFFF))
                    return itr->first;

            return 0;
        }

        /**
         * @name GetNextEventTime
         * @return Time of next event.
         */
        uint32 GetNextEventTime() const
        {
            return Empty() ? 0 : _eventMap.begin()->first;
        }

        /**
        * @name IsInPhase
        * @brief Returns wether event map is in specified phase or not.
        * @param phase Wanted phase.
        * @return True, if phase of event map contains specified phase.
        */
        bool IsInPhase(uint8 phase)
        {
            return phase <= 8 && (!phase || _phase & (1 << (phase - 1)));
        }

        /**
        * @name GetTimeUntilEvent
        * @brief Returns time in milliseconds until next event.
        * @param Id of the event.
        * @return Time of next event.
        */
        uint32 GetTimeUntilEvent(uint32 eventId) const;

    private:
        /**
        * @name _time
        * @brief Internal timer.
        *
        * This does not represent the real date/time value.
        * It's more like a stopwatch: It can run, it can be stopped,
        * it can be resetted and so on. Events occur when this timer
        * has reached their time value. Its value is changed in the
        * Update method.
        */
        uint32 _time;

        /**
        * @name _phase
        * @brief Phase mask of the event map.
        *
        * Contains the phases the event map is in. Multiple
        * phases from 1 to 8 can be set with SetPhase or
        * AddPhase. RemovePhase deactives a phase.
        */
        uint8 _phase;

        /**
        * @name _eventMap
        * @brief Internal event storage map. Contains the scheduled events.
        *
        * See typedef at the beginning of the class for more
        * details.
        */
        EventStore _eventMap;

        /**
        * @name _lastEvent
        * @brief Stores information on the most recently executed event
        */
        uint32 _lastEvent;
};

#endif
