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

class StatsLogger
{
private:
    StatsLogger();
    ~StatsLogger();

    boost::asio::ip::tcp::iostream _dataStream;
    MPSCQueue<std::string> _queuedData;
    boost::asio::deadline_timer* _batchTimer;
    uint32 _updateInterval;
    bool _enabled;

    void SendBatch();
    void Enqueue(std::string const& data);
    void ScheduleSend();

public:
    static StatsLogger* instance()
    {
        static StatsLogger instance;
        return &instance;
    }

    void Initialize(boost::asio::io_service& ioService, uint32 updateInterval);
    void LoadFromConfigs();
    void LogValue(std::string const& category, uint32 value);
    void LogEvent(std::string const& title, std::string const& description);
    void ForceSend();
    bool IsEnabled() { return _enabled; }
};

#define sStatsLogger StatsLogger::instance()

#if PLATFORM != PLATFORM_WINDOWS
#define TC_STATS_EVENT(title, description)                              \
        do {                                                            \
            if (sStatsLogger->IsEnabled())                              \
                sStatsLogger->LogEvent(title, description);             \
        } while (0)
#define TC_STATS_VALUE(category, value)                                 \
        do {                                                            \
            if (sStatsLogger->IsEnabled())                              \
                sStatsLogger->LogValue(category, value);                \
        } while (0)
#else
#define TC_STATS_EVENT(title, description)                              \
        __pragma(warning(push))                                         \
        __pragma(warning(disable:4127))                                 \
        do {                                                            \
            if (sStatsLogger->IsEnabled())                              \
                sStatsLogger->LogEvent(title, description);             \
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
