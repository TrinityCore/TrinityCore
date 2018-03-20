/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#ifndef TRINITYCORE_COMMON_H
#define TRINITYCORE_COMMON_H

#include "Define.h"
#include <memory>
#include <string>
#include <utility>
#include <boost/any.hpp>
#include <mutex>
#include <unordered_map>
#include <map>
#include <regex>
#include <list>
#include "Errors.h"
#include "LockedQueue.h"
#include "StringFormat.h"

#if TRINITY_PLATFORM == TRINITY_PLATFORM_WINDOWS
#  if TRINITY_COMPILER == TRINITY_COMPILER_INTEL
#    if !defined(BOOST_ASIO_HAS_MOVE)
#      define BOOST_ASIO_HAS_MOVE
#    endif // !defined(BOOST_ASIO_HAS_MOVE)
#  endif // if TRINITY_COMPILER == TRINITY_COMPILER_INTEL
#else
#  include <sys/types.h>
#  include <sys/ioctl.h>
#  include <sys/socket.h>
#  include <netinet/in.h>
#  include <unistd.h>
#  include <netdb.h>
#  include <cstdlib>
#endif

#if TRINITY_COMPILER == TRINITY_COMPILER_MICROSOFT

#define snprintf _snprintf
#define atoll _atoi64
#define vsnprintf _vsnprintf
#define llabs _abs64

#else

#define stricmp strcasecmp
#define strnicmp strncasecmp

#endif

inline unsigned long atoul(char const* str) { return strtoul(str, nullptr, 10); }
inline unsigned long long atoull(char const* str) { return strtoull(str, nullptr, 10); }

#define STRINGIZE(a) #a

enum TimeConstants
{
    MINUTE          = 60,
    HOUR            = MINUTE*60,
    DAY             = HOUR*24,
    WEEK            = DAY*7,
    MONTH           = DAY*30,
    YEAR            = MONTH*12,
    IN_MILLISECONDS = 1000
};

enum AccountTypes
{
    SEC_PLAYER         = 0,
    SEC_MODERATOR      = 1,
    SEC_GAMEMASTER     = 2,
    SEC_ADMINISTRATOR  = 3,
    SEC_CONSOLE        = 4                                  // must be always last in list, accounts must have less security level always also
};

enum LocaleConstant : uint8
{
    LOCALE_enUS = 0,
    LOCALE_koKR = 1,
    LOCALE_frFR = 2,
    LOCALE_deDE = 3,
    LOCALE_zhCN = 4,
    LOCALE_zhTW = 5,
    LOCALE_esES = 6,
    LOCALE_esMX = 7,
    LOCALE_ruRU = 8,
    LOCALE_none = 9,
    LOCALE_ptBR = 10,
    LOCALE_itIT = 11,

    TOTAL_LOCALES
};

enum DiscordMessageChannel
{
    DISCORD_WORLD_A = 1,
    DISCORD_WORLD_H = 2,
    DISCORD_TICKET  = 3
};

struct DiscordMessage
{
    DiscordMessageChannel channel;
    std::string message;

    // Channel Specific
    std::string characterName;
    bool isGm;
};

TC_COMMON_API extern LockedQueue<DiscordMessage*> DiscordMessageQueue;

const uint8 OLD_TOTAL_LOCALES = 9; /// @todo convert in simple system
#define DEFAULT_LOCALE LOCALE_enUS

#define MAX_LOCALES 11

TC_COMMON_API extern char const* localeNames[TOTAL_LOCALES];

TC_COMMON_API LocaleConstant GetLocaleByName(std::string const& name);

#pragma pack(push, 1)

struct TC_COMMON_API LocalizedString
{
    char const* Str[TOTAL_LOCALES];
};

#pragma pack(pop)

// we always use stdlib std::max/std::min, undefine some not C++ standard defines (Win API and some other platforms)
#ifdef max
#undef max
#endif

#ifdef min
#undef min
#endif

#ifndef M_PI
#define M_PI            3.14159265358979323846
#endif

#define MAX_QUERY_LEN 32*1024

namespace Trinity
{
    using std::make_unique;
}

namespace Ashamane
{
    class TC_GAME_API Variables
    {
        friend class VariablesSafe;

        public:
            Variables() : variables(100), ensureAlreadyExists(false) { }
            virtual ~Variables() { }

            typedef std::unordered_map<std::string, boost::any> variablesMap;

            template<typename T>
            T * Get(std::string const& key) const
            {
                _ensureVariable(key);
                auto itr = variables.find(key);
                if (itr != variables.end())
                    return const_cast<T*>(boost::any_cast<T>(&itr->second));
                return nullptr;
            }
            template<typename T>
            T * GetOrCreate(std::string const& key)
            {
                static_assert(std::is_fundamental<T>::value, "GetOrCreate() must be used only for fundamental types, use GetAuto() instead");
                if (!IsSet(key))
                    Reset<T>(key);
                return Get<T>(key);
            }
            template<typename T>
            T GetValue(std::string const& key) const
            {
                _ensureVariable(key);
                auto itr = variables.find(key);
                if (itr != variables.end())
                    return boost::any_cast<T>(itr->second);
                return T();
            }
            template<typename T>
            T GetValue(std::string const& key, T defaultValue) const
            {
                auto itr = variables.find(key);
                if (itr != variables.end())
                    return boost::any_cast<T>(itr->second);
                return defaultValue;
            }
            template<typename T>
            Variables * Set(std::string const& key, T&& value)
            {
                _ensureVariable(key);
                variables[key] = (boost::any)(value);
                return this;
            }
            template<typename T>
            T SetAndReturnValue(std::string const& key, T&& value)
            {
                _ensureVariable(key);
                variables[key] = (boost::any)(value);
                return value;
            }
            template<typename T>
            Variables * Reset(std::string const& key)
            {
                Set<T>(key, T());
                return this;
            }
            Variables * ToggleBool(std::string const& key)
            {
                if (IsSet(key))
                    Remove(key);
                else
                    Set(key, true);
                return this;
            }
            template<typename T>
            T * GetAuto(std::string const& key, bool createIfInexistent = true)
            {
                static_assert(!std::is_fundamental<T>::value, "GetAuto() must not be used for fundamental types, use GetOrCreate() instead");
                _ensureVariable(key);
                if (IsSet(key))
                    return *Get<T*>(key);
                else if (!createIfInexistent)
                    return nullptr;
                T * value = new T;
                _destructors[key].p = value;
                _destructors[key].destroy = [](const void* x) { static_cast<const T*>(x)->~T(); };
                variables[key] = (boost::any)(value);
                return value;
            }
            Variables * Remove(std::string const& key)
            {
                std::list<std::string> keys;
                if (key.find("*") != std::string::npos)
                {
                    std::string expr = key;
                    std::replace(expr.begin(), expr.end(), '.', '|');
                    while (expr.find("|") != std::string::npos)
                        expr.replace(expr.find("|"), 1, std::string(R"(\.)"));
                    std::replace(expr.begin(), expr.end(), '*', '|');
                    while (expr.find("|") != std::string::npos)
                        expr.replace(expr.find("|"), 1, std::string(".*"));
                    expr = "^" + expr + "$";
                    for (auto var : variables)
                        if (std::regex_match(var.first, std::regex(expr)))
                            keys.push_back(var.first);
                }
                else
                    keys.push_back(key);
                for (auto k : keys)
                {
                    _destructors.erase(k);
                    variables.erase(k);
                }
                return this;
            }

            inline bool IsSet(std::string const& key) const { return variables.find(key) != variables.end(); }
            Variables * Clear() { _destructors.clear(); variables.clear(); return this; }

            void EnsureVariablesAlreadyExist(bool state) { ensureAlreadyExists = state; }

            variablesMap const * GetVariables() const { return &variables; }

            uint32 Increment(std::string const& key, uint32 increment = 1)
            {
                uint32 currentValue = GetValue<uint32>(key, uint32(0));
                Set(key, currentValue += increment);
                return currentValue;
            }

            bool IncrementOrProcCounter(std::string const& key, uint32 maxVal, uint32 increment = 1)
            {
                uint32 newValue = Increment(key, increment);
                if (newValue < maxVal)
                    return false;

                Remove(key);
                return true;
            }

            // format helpers
            template<typename T, typename... Args> T * Get(std::string const& key, Args&&... args) const { return Get<T>(Trinity::StringFormat(key, std::forward<Args>(args)...)); }
            template<typename T, typename... Args> T * GetOrCreate(std::string const& key, Args&&... args) { static_assert(std::is_fundamental<T>::value, "GetOrCreate() must be used only for fundamental types, use GetAuto() instead"); return GetOrCreate<T>(Trinity::StringFormat(key, std::forward<Args>(args)...)); }
            template<typename T, typename... Args> T GetValue(std::string const& key, Args&&... args) const { return GetValue<T>(Trinity::StringFormat(key, std::forward<Args>(args)...)); }
            template<typename T, typename... Args> Variables * Set(std::string const& key, T&& value, Args&&... args) { return Set(Trinity::StringFormat(key, std::forward<Args>(args)...), (T&&)value); }
            template<typename T, typename... Args> T SetAndReturnValue(std::string const& key, T&& value, Args&&... args) { return SetAndReturnValue<T>(Trinity::StringFormat(key, std::forward<Args>(args)...), (T&&)value); }
            template<typename T, typename... Args> Variables * Reset(std::string const& key, Args&&... args) { return Reset<T>(Trinity::StringFormat(key, std::forward<Args>(args)...)); }
            template<typename... Args> Variables * ToggleBool(std::string const& key, Args&&... args) { return ToggleBool(Trinity::StringFormat(key, std::forward<Args>(args)...)); }
            template<typename T, typename... Args> typename std::enable_if<(sizeof...(Args) != 0), T*>::type GetAuto(std::string const& key, bool createIfInexistent, Args&&... args) { static_assert(!std::is_fundamental<T>::value, "GetAuto() must not be used for fundamental types, use GetOrCreate() instead"); return GetAuto<T>(Trinity::StringFormat(key, std::forward<Args>(args)...), createIfInexistent); }
            template<typename... Args> Variables * Remove(std::string const& key, Args&&... args) { return Remove(Trinity::StringFormat(key, std::forward<Args>(args)...)); }
            template<typename... Args> bool IsSet(std::string const& key, Args&&... args) const { return IsSet(Trinity::StringFormat(key, std::forward<Args>(args)...)); }

        protected:
            variablesMap variables;
            bool ensureAlreadyExists;

        private:
            struct destructor
            {
                const void* p;
                void(*destroy)(const void*);
                ~destructor() { destroy(p); delete (char*)p; }
            };
            std::map<std::string, destructor> _destructors;
            void _ensureVariable(std::string const& key) const
            {
                if (!ensureAlreadyExists)
                    return;
                ASSERT(IsSet(key), "Invalid variable '%s'", key.c_str());
            }
    };

    #define __LOCK std::lock_guard<std::recursive_mutex> lock(_lock)
    class TC_GAME_API VariablesSafe : public Variables
    {
        public:
            template<typename T> T * Get(std::string const& key) const { __LOCK; return Variables::Get<T>(key); }
            template<typename T> T * GetOrCreate(std::string const& key) { static_assert(std::is_fundamental<T>::value, "GetOrCreate() must be used only for fundamental types, use GetAuto() instead"); __LOCK; return Variables::GetOrCreate<T>(key); }
            template<typename T> T GetValue(std::string const& key) const { __LOCK; return Variables::GetValue<T>(key); }
            template<typename T> T GetValue(std::string const& key, T defaultValue) const { __LOCK; return Variables::GetValue<T>(key, defaultValue); }
            template<typename T> VariablesSafe * Set(std::string const& key, T&& value) { __LOCK; return dynamic_cast<VariablesSafe*>(Variables::Set<T>(key, (T&&)value)); }
            template<typename T> T SetAndReturnValue(std::string const& key, T&& value) { __LOCK; return Variables::SetAndReturnValue<T>(key, (T&&)value); }
            template<typename T> VariablesSafe * Reset(std::string const& key) { __LOCK; return dynamic_cast<VariablesSafe*>(Variables::Reset<T>(key)); }
            VariablesSafe * ToggleBool(std::string const& key) { __LOCK; return dynamic_cast<VariablesSafe*>(Variables::ToggleBool(key)); }
            template<typename T> T * GetAuto(std::string const& key, bool createIfInexistent = true) { static_assert(!std::is_fundamental<T>::value, "GetAuto() must not be used for fundamental types, use GetOrCreate() instead"); __LOCK; return Variables::GetAuto<T>(key, createIfInexistent); }
            VariablesSafe * Remove(std::string const& key) { __LOCK; return dynamic_cast<VariablesSafe*>(Variables::Remove(key)); }
            inline bool IsSet(std::string const& key) const { __LOCK; return Variables::IsSet(key); }
            VariablesSafe * Clear() { __LOCK; return dynamic_cast<VariablesSafe*>(Variables::Clear()); }

            // format helpers
            template<typename T, typename... Args> T * Get(std::string const& key, Args&&... args) const { __LOCK; return Variables::Get<T>(Trinity::StringFormat(key, std::forward<Args>(args)...)); }
            template<typename T, typename... Args> T * GetOrCreate(std::string const& key, Args&&... args) { static_assert(std::is_fundamental<T>::value, "GetOrCreate() must be used only for fundamental types, use GetAuto() instead"); __LOCK; return Variables::GetOrCreate<T>(Trinity::StringFormat(key, std::forward<Args>(args)...)); }
            template<typename T, typename... Args> T GetValue(std::string const& key, Args&&... args) const { __LOCK; return Variables::GetValue<T>(Trinity::StringFormat(key, std::forward<Args>(args)...)); }
            template<typename T, typename... Args> VariablesSafe * Set(std::string const& key, T&& value, Args&&... args) { __LOCK; return dynamic_cast<VariablesSafe*>(Variables::Set<T>(Trinity::StringFormat(key, std::forward<Args>(args)...), (T&&)value)); }
            template<typename T, typename... Args> T SetAndReturnValue(std::string const& key, T&& value, Args&&... args) { __LOCK; return Variables::SetAndReturnValue<T>(Trinity::StringFormat(key, std::forward<Args>(args)...), (T&&)value); }
            template<typename T, typename... Args> VariablesSafe * Reset(std::string const& key, Args&&... args) { __LOCK; return dynamic_cast<VariablesSafe*>(Variables::Reset<T>(Trinity::StringFormat(key, std::forward<Args>(args)...))); }
            template<typename... Args> VariablesSafe * ToggleBool(std::string const& key, Args&&... args) { __LOCK; return dynamic_cast<VariablesSafe*>(Variables::ToggleBool(Trinity::StringFormat(key, std::forward<Args>(args)...))); }
            template<typename T, typename... Args> typename std::enable_if<(sizeof...(Args) != 0), T*>::type GetAuto(std::string const& key, bool createIfInexistent, Args&&... args) { static_assert(!std::is_fundamental<T>::value, "GetAuto() must not be used for fundamental types, use GetOrCreate() instead"); __LOCK; return Variables::GetAuto<T>(Trinity::StringFormat(key, std::forward<Args>(args)...), createIfInexistent); }
            template<typename... Args> VariablesSafe * Remove(std::string const& key, Args&&... args) { __LOCK; return dynamic_cast<VariablesSafe*>(Variables::Remove(Trinity::StringFormat(key, std::forward<Args>(args)...))); }
            template<typename... Args> bool IsSet(std::string const& key, Args&&... args) const { __LOCK; return Variables::IsSet(Trinity::StringFormat(key, std::forward<Args>(args)...)); }

            void Lock() { _lock.lock(); }
            void Unlock() { _lock.unlock(); }

        private:
            mutable std::recursive_mutex _lock;
    };
}

#endif
