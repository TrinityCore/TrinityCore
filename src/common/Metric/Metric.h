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

#ifndef METRIC_H__
#define METRIC_H__

#include "Define.h"
#include "MPSCQueue.h"
#include <chrono>
#include <functional>
#include <iosfwd>
#include <memory>
#include <string>

namespace Trinity
{
    namespace Asio
    {
        class IoContext;
        class DeadlineTimer;
    }
}

enum MetricDataType
{
    METRIC_DATA_VALUE,
    METRIC_DATA_EVENT
};

struct MetricData
{
    std::string Category;
    std::chrono::system_clock::time_point Timestamp;
    MetricDataType Type;

    // LogValue-specific fields
    std::string Value;

    // LogEvent-specific fields
    std::string Title;
    std::string Text;
};

class TC_COMMON_API Metric
{
private:
    std::iostream& GetDataStream() { return *_dataStream; }
    std::unique_ptr<std::iostream> _dataStream;
    MPSCQueue<MetricData> _queuedData;
    std::unique_ptr<Trinity::Asio::DeadlineTimer> _batchTimer;
    std::unique_ptr<Trinity::Asio::DeadlineTimer> _overallStatusTimer;
    int32 _updateInterval = 0;
    int32 _overallStatusTimerInterval = 0;
    bool _enabled = false;
    bool _overallStatusTimerTriggered = false;
    std::string _hostname;
    std::string _port;
    std::string _databaseName;
    std::function<void()> _overallStatusLogger;
    std::string _realmName;

    bool Connect();
    void SendBatch();
    void ScheduleSend();
    void ScheduleOverallStatusLog();

    static std::string FormatInfluxDBValue(bool value);
    template<class T>
    static std::string FormatInfluxDBValue(T value);
    static std::string FormatInfluxDBValue(std::string const& value);
    static std::string FormatInfluxDBValue(const char* value);
    static std::string FormatInfluxDBValue(double value);
    static std::string FormatInfluxDBValue(float value);

    static std::string FormatInfluxDBTagValue(std::string const& value);

    // ToDo: should format TagKey and FieldKey too in the same way as TagValue

public:
    Metric();
    ~Metric();
    static Metric* instance();

    void Initialize(std::string const& realmName, Trinity::Asio::IoContext& ioContext, std::function<void()> overallStatusLogger);
    void LoadFromConfigs();
    void Update();

    template<class T>
    void LogValue(std::string const& category, T value)
    {
        using namespace std::chrono;

        MetricData* data = new MetricData;
        data->Category = category;
        data->Timestamp = system_clock::now();
        data->Type = METRIC_DATA_VALUE;
        data->Value = FormatInfluxDBValue(value);

        _queuedData.Enqueue(data);
    }

    void LogEvent(std::string const& category, std::string const& title, std::string const& description);

    void ForceSend();
    bool IsEnabled() const { return _enabled; }
};

#define sMetric Metric::instance()

#if TRINITY_PLATFORM != TRINITY_PLATFORM_WINDOWS
#define TC_METRIC_EVENT(category, title, description)                    \
        do {                                                            \
            if (sMetric->IsEnabled())                              \
                sMetric->LogEvent(category, title, description);   \
        } while (0)
#define TC_METRIC_VALUE(category, value)                                 \
        do {                                                            \
            if (sMetric->IsEnabled())                              \
                sMetric->LogValue(category, value);                \
        } while (0)
#else
#define TC_METRIC_EVENT(category, title, description)                    \
        __pragma(warning(push))                                         \
        __pragma(warning(disable:4127))                                 \
        do {                                                            \
            if (sMetric->IsEnabled())                              \
                sMetric->LogEvent(category, title, description);   \
        } while (0)                                                     \
        __pragma(warning(pop))
#define TC_METRIC_VALUE(category, value)                                 \
        __pragma(warning(push))                                         \
        __pragma(warning(disable:4127))                                 \
        do {                                                            \
            if (sMetric->IsEnabled())                              \
                sMetric->LogValue(category, value);                \
        } while (0)                                                     \
        __pragma(warning(pop))
#endif

#endif // METRIC_H__
