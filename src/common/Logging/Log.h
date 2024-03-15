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

#ifndef TRINITYCORE_LOG_H
#define TRINITYCORE_LOG_H

#include "Define.h"
#include "AsioHacksFwd.h"
#include "LogCommon.h"
#include "StringFormat.h"
#include <memory>
#include <unordered_map>
#include <vector>

class Appender;
class Logger;
struct LogMessage;

namespace Trinity
{
    namespace Asio
    {
        class IoContext;
    }
}

#define LOGGER_ROOT "root"

typedef Appender*(*AppenderCreatorFn)(uint8 id, std::string const& name, LogLevel level, AppenderFlags flags, std::vector<std::string_view> const& extraArgs);

template <class AppenderImpl>
Appender* CreateAppender(uint8 id, std::string const& name, LogLevel level, AppenderFlags flags, std::vector<std::string_view> const& extraArgs)
{
    return new AppenderImpl(id, name, level, flags, extraArgs);
}

class TC_COMMON_API Log
{
    private:
        Log();
        ~Log();
        Log(Log const&) = delete;
        Log(Log&&) = delete;
        Log& operator=(Log const&) = delete;
        Log& operator=(Log&&) = delete;

    public:
        static Log* instance();

        void Initialize(Trinity::Asio::IoContext* ioContext);
        void SetSynchronous();  // Not threadsafe - should only be called from main() after all threads are joined
        void LoadFromConfig();
        void Close();
        bool ShouldLog(std::string_view type, LogLevel level) const;
        bool SetLogLevel(std::string const& name, int32 level, bool isLogger = true);

        template<typename... Args>
        void OutMessage(std::string_view filter, LogLevel const level, Trinity::FormatString<Args...> fmt, Args&&... args)
        {
            OutMessageImpl(filter, level, fmt, Trinity::MakeFormatArgs(args...));
        }

        template<typename... Args>
        void OutCommand(uint32 account, Trinity::FormatString<Args...> fmt, Args&&... args)
        {
            if (!ShouldLog("commands.gm", LOG_LEVEL_INFO))
                return;

            OutCommandImpl(account, fmt, Trinity::MakeFormatArgs(args...));
        }

        void OutCharDump(char const* str, uint32 account_id, uint64 guid, char const* name);

        void SetRealmId(uint32 id);

        template<class AppenderImpl>
        void RegisterAppender()
        {
            RegisterAppender(AppenderImpl::type, &CreateAppender<AppenderImpl>);
        }

        std::string const& GetLogsDir() const { return m_logsDir; }
        std::string const& GetLogsTimestamp() const { return m_logsTimestamp; }

        void CreateAppenderFromConfigLine(std::string const& name, std::string const& options);
        void CreateLoggerFromConfigLine(std::string const& name, std::string const& options);

        template <typename StringOrStringView>
        static constexpr std::string_view make_string_view(StringOrStringView const& stringOrStringView)
        {
            return stringOrStringView;
        }

        template <size_t CharArraySize>
        static consteval std::string_view make_string_view(char const(&chars)[CharArraySize])
        {
            return { std::begin(chars), (chars[CharArraySize - 1] == '\0' ? CharArraySize - 1 : CharArraySize) };
        }

    private:
        static std::string GetTimestampStr();
        void write(std::unique_ptr<LogMessage> msg) const;

        Logger const* GetLoggerByType(std::string_view type) const;
        Appender* GetAppenderByName(std::string_view name);
        uint8 NextAppenderId();
        void CreateAppenderFromConfig(std::string const& name);
        void CreateLoggerFromConfig(std::string const& name);
        void ReadAppendersFromConfig();
        void ReadLoggersFromConfig();
        void RegisterAppender(uint8 index, AppenderCreatorFn appenderCreateFn);
        void OutMessageImpl(std::string_view filter, LogLevel level, Trinity::FormatStringView messageFormat, Trinity::FormatArgs messageFormatArgs);
        void OutCommandImpl(uint32 account, Trinity::FormatStringView messageFormat, Trinity::FormatArgs messageFormatArgs);

        std::unordered_map<uint8, AppenderCreatorFn> appenderFactory;
        std::unordered_map<uint8, std::unique_ptr<Appender>> appenders;
        std::unordered_map<std::string_view, std::unique_ptr<Logger>> loggers;
        uint8 AppenderId;
        LogLevel lowestLogLevel;

        std::string m_logsDir;
        std::string m_logsTimestamp;

        Trinity::Asio::IoContext* _ioContext;
        Trinity::Asio::Strand* _strand;
};

#define sLog Log::instance()

#define TC_LOG_MESSAGE_BODY_CORE(filterType__, level__, message__, ...)                                                                  \
        do {                                                                                                                             \
            if (Log* logInstance = sLog; logInstance->ShouldLog(Log::make_string_view(filterType__), level__))                           \
                logInstance->OutMessage(Log::make_string_view(filterType__), level__, Log::make_string_view(message__), ## __VA_ARGS__); \
        } while (0)

#ifdef PERFORMANCE_PROFILING
#define TC_LOG_MESSAGE_BODY(filterType__, level__, message__, ...) ((void)0)
#elif TRINITY_PLATFORM != TRINITY_PLATFORM_WINDOWS
#define TC_LOG_MESSAGE_BODY(filterType__, level__, message__, ...) TC_LOG_MESSAGE_BODY_CORE(filterType__, level__, message__, ## __VA_ARGS__)
#else
#define TC_LOG_MESSAGE_BODY(filterType__, level__, message__, ...)                 \
        __pragma(warning(push))                                                    \
        __pragma(warning(disable:4127))                                            \
        TC_LOG_MESSAGE_BODY_CORE(filterType__, level__, message__, ## __VA_ARGS__) \
        __pragma(warning(pop))
#endif

#define TC_LOG_TRACE(filterType__, message__, ...) \
    TC_LOG_MESSAGE_BODY(filterType__, LOG_LEVEL_TRACE, message__, ## __VA_ARGS__)

#define TC_LOG_DEBUG(filterType__, message__, ...) \
    TC_LOG_MESSAGE_BODY(filterType__, LOG_LEVEL_DEBUG, message__, ## __VA_ARGS__)

#define TC_LOG_INFO(filterType__, message__, ...)  \
    TC_LOG_MESSAGE_BODY(filterType__, LOG_LEVEL_INFO, message__, ## __VA_ARGS__)

#define TC_LOG_WARN(filterType__, message__, ...)  \
    TC_LOG_MESSAGE_BODY(filterType__, LOG_LEVEL_WARN, message__, ## __VA_ARGS__)

#define TC_LOG_ERROR(filterType__, message__, ...) \
    TC_LOG_MESSAGE_BODY(filterType__, LOG_LEVEL_ERROR, message__, ## __VA_ARGS__)

#define TC_LOG_FATAL(filterType__, message__, ...) \
    TC_LOG_MESSAGE_BODY(filterType__, LOG_LEVEL_FATAL, message__, ## __VA_ARGS__)

#endif
