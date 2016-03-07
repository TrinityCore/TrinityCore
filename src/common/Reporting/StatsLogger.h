/*
* Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#ifndef STATSLOGGER_H__
#define STATSLOGGER_H__

#include "Common.h"
#include "Threading/MPSCQueue.h"
#include <boost/asio/ip/tcp.hpp>
#include <boost/algorithm/string.hpp>
#include <type_traits>

enum StatsEventCategory
{
    STATS_EVENT_CATEGORY_GENERIC = 0,
    STATS_EVENT_CATEGORY_MAP,
    STATS_EVENT_CATEGORY_MMAP,
    STATS_EVENT_CATEGORY_PLAYER,
    STATS_EVENT_CATEGORY_MAX
};

enum StatsValueCategory
{
    STATS_VALUE_UPDATE_TIME_DIFF = 0,
    STATS_VALUE_ONLINE_PLAYERS,
    STATS_VALUE_MAX
};

class StatsLogger
{
private:
    StatsLogger();
    ~StatsLogger();

    boost::asio::ip::tcp::iostream _dataStream;
    MPSCQueue<std::string> _queuedData;
    boost::asio::deadline_timer* _batchTimer;
    boost::asio::deadline_timer* _overallStatusTimer;
    int32 _updateInterval;
    int32 _overallStatusTimerInterval;
    bool _enabled;
    bool _overallStatusTimerTriggered;
    std::string _hostname;
    std::string _port;
    std::string _databaseName;
    std::function<void()> _overallStatusLogger;

    bool Connect();
    void SendBatch();
    void Enqueue(std::string const& data);
    void ScheduleSend();
    void ScheduleOverallStatusLog();

    std::string _categories[STATS_EVENT_CATEGORY_MAX];
    std::string _values[STATS_VALUE_MAX];

    template<class T, typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
    static std::string FormatInfluxDBValue(T value) { return std::to_string(value) + 'i'; }

    static std::string FormatInfluxDBValue(std::string const& value)
    {
        using boost::replace_all_copy;

        std::string escaped = replace_all_copy(replace_all_copy(replace_all_copy(value,
            "\"", "\\\""), // escape quotes
            ",", "\\,"), // escape commas
            " ", " \\ "); // escape spaces

        return '"' + escaped + '"';
    }

    static std::string FormatInfluxDBValue(bool value) { return value ? "t" : "f"; }
    static std::string FormatInfluxDBValue(const char* value) { return FormatInfluxDBValue(std::string(value)); }
    static std::string FormatInfluxDBValue(double value) { return std::to_string(value); }
    static std::string FormatInfluxDBValue(float value) { return FormatInfluxDBValue(double(value)); }

public:
    static StatsLogger* instance()
    {
        static StatsLogger instance;
        return &instance;
    }

    void Initialize(boost::asio::io_service& ioService, std::function<void()> overallStatusLogger = [](){});
    void LoadFromConfigs();
    void Update();

    template<class T>
    void LogValue(std::string const& category, T value)
    {
        using namespace std::chrono;

        std::string data = category + ",realm=Windows value=" + FormatInfluxDBValue(value)
            + " " + std::to_string(duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count());

        Enqueue(data);
    }

    template<class T>
    void LogValue(StatsValueCategory category, T value) { LogValue(_values[category], value); }

    void LogEvent(StatsEventCategory category, std::string const& title, std::string const& description);
    void ForceSend();
    bool IsEnabled() const { return _enabled; }
};

#define sStatsLogger StatsLogger::instance()

#if PLATFORM != PLATFORM_WINDOWS
#define TC_STATS_EVENT(category, title, description)                    \
        do {                                                            \
            if (sStatsLogger->IsEnabled())                              \
                sStatsLogger->LogEvent(category, title, description);   \
        } while (0)
#define TC_STATS_VALUE(category, value)                                 \
        do {                                                            \
            if (sStatsLogger->IsEnabled())                              \
                sStatsLogger->LogValue(category, value);                \
        } while (0)
#else
#define TC_STATS_EVENT(category, title, description)                    \
        __pragma(warning(push))                                         \
        __pragma(warning(disable:4127))                                 \
        do {                                                            \
            if (sStatsLogger->IsEnabled())                              \
                sStatsLogger->LogEvent(category, title, description);   \
        } while (0)                                                     \
        __pragma(warning(pop))
#define TC_STATS_VALUE(category, value)                                 \
        __pragma(warning(push))                                         \
        __pragma(warning(disable:4127))                                 \
        do {                                                            \
            if (sStatsLogger->IsEnabled())                              \
                sStatsLogger->LogValue(category, value);                \
        } while (0)                                                     \
        __pragma(warning(pop))
#endif

#endif // STATSLOGGER_H__
