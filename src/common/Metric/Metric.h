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
#include "Duration.h"
#include "MPSCQueue.h"
#include "Optional.h"
#include <boost/container/small_vector.hpp>
#include <functional>
#include <iosfwd>
#include <memory>
#include <string>
#include <unordered_map>
#include <utility>

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

using MetricTag = std::pair<std::string, std::string>;
using MetricTagsVector = boost::container::small_vector<MetricTag, 2>;

struct MetricData
{
    std::string Category;
    SystemTimePoint Timestamp;
    MetricDataType Type;

    // LogValue-specific fields
    MetricTagsVector Tags;

    // LogEvent-specific fields
    std::string Title;

    std::string ValueOrEventText;

    // intrusive queue link
    std::atomic<MetricData*> QueueLink;
};

class TC_COMMON_API Metric
{
private:
    std::iostream& GetDataStream() { return *_dataStream; }
    std::unique_ptr<std::iostream> _dataStream;
    MPSCQueue<MetricData, &MetricData::QueueLink> _queuedData;
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
    std::unordered_map<std::string, int64> _thresholds;

    bool Connect();
    void SendBatch();
    void ScheduleSend();
    void ScheduleOverallStatusLog();

    static std::string FormatInfluxDBValue(bool value);
    template <class T>
    static std::string FormatInfluxDBValue(T value);
    static std::string FormatInfluxDBValue(std::string const& value);
    static std::string FormatInfluxDBValue(char const* value);
    static std::string FormatInfluxDBValue(double value);
    static std::string FormatInfluxDBValue(float value);
    static std::string FormatInfluxDBValue(std::chrono::nanoseconds value);

    static std::string FormatInfluxDBTagValue(std::string const& value);

    // ToDo: should format TagKey and FieldKey too in the same way as TagValue

public:
    Metric();
    ~Metric();
    static Metric* instance();

    void Initialize(std::string const& realmName, Trinity::Asio::IoContext& ioContext, std::function<void()> overallStatusLogger);
    void LoadFromConfigs();
    void Update();
    bool ShouldLog(std::string const& category, int64 value) const;

    template<class T, class... Tags>
    void LogValue(std::string category, T value, Tags&&... tags)
    {
        using namespace std::chrono;

        MetricData* data = new MetricData;
        data->Category = std::move(category);
        data->Timestamp = system_clock::now();
        data->Type = METRIC_DATA_VALUE;
        data->ValueOrEventText = FormatInfluxDBValue(value);
        if constexpr (sizeof...(tags) > 0)
            (data->Tags.emplace_back(std::move(tags)), ...);

        _queuedData.Enqueue(data);
    }

    void LogEvent(std::string category, std::string title, std::string description);

    void Unload();
    bool IsEnabled() const { return _enabled; }
};

#define sMetric Metric::instance()

template<typename LoggerType>
class MetricStopWatch
{
public:
    MetricStopWatch(LoggerType&& loggerFunc) :
        _logger(std::forward<LoggerType>(loggerFunc)),
        _startTime(std::chrono::steady_clock::now())
    {
    }

    ~MetricStopWatch()
    {
        _logger(_startTime);
    }

private:
    LoggerType _logger;
    TimePoint _startTime;
};

template<typename LoggerType>
Optional<MetricStopWatch<LoggerType>> MakeMetricStopWatch(LoggerType&& loggerFunc)
{
    if (!sMetric->IsEnabled())
        return {};

    return Optional<MetricStopWatch<LoggerType>>(std::in_place, std::forward<LoggerType>(loggerFunc));
}

#define TC_METRIC_TAG(name, value) MetricTag(name, value)

#define TC_METRIC_DO_CONCAT(a, b) a ## b
#define TC_METRIC_CONCAT(a, b) TC_METRIC_DO_CONCAT(a, b)
#define TC_METRIC_UNIQUE_NAME(name) TC_METRIC_CONCAT(name, __LINE__)

#if defined PERFORMANCE_PROFILING || defined WITHOUT_METRICS
#define TC_METRIC_EVENT(category, title, description) ((void)0)
#define TC_METRIC_VALUE(category, value, ...) ((void)0)
#define TC_METRIC_TIMER(category, ...) ((void)0)
#define TC_METRIC_DETAILED_EVENT(category, title, description) ((void)0)
#define TC_METRIC_DETAILED_TIMER(category, ...) ((void)0)
#define TC_METRIC_DETAILED_NO_THRESHOLD_TIMER(category, ...) ((void)0)
#else
#  if TRINITY_PLATFORM != TRINITY_PLATFORM_WINDOWS
#define TC_METRIC_EVENT(category, title, description)                  \
        do {                                                           \
            if (sMetric->IsEnabled())                                  \
                sMetric->LogEvent(category, title, description);       \
        } while (0)
#define TC_METRIC_VALUE(category, value, ...)                          \
        do {                                                           \
            if (sMetric->IsEnabled())                                  \
                sMetric->LogValue(category, value, ##__VA_ARGS__);     \
        } while (0)
#  else
#define TC_METRIC_EVENT(category, title, description)                  \
        __pragma(warning(push))                                        \
        __pragma(warning(disable:4127))                                \
        do {                                                           \
            if (sMetric->IsEnabled())                                  \
                sMetric->LogEvent(category, title, description);       \
        } while (0)                                                    \
        __pragma(warning(pop))
#define TC_METRIC_VALUE(category, value, ...)                          \
        __pragma(warning(push))                                        \
        __pragma(warning(disable:4127))                                \
        do {                                                           \
            if (sMetric->IsEnabled())                                  \
                sMetric->LogValue(category, value, ##__VA_ARGS__);     \
        } while (0)                                                    \
        __pragma(warning(pop))
#  endif
#define TC_METRIC_TIMER(category, ...)                                                                           \
        auto TC_METRIC_UNIQUE_NAME(__tc_metric_stop_watch) = MakeMetricStopWatch([&](TimePoint start)            \
        {                                                                                                        \
            sMetric->LogValue(category, std::chrono::steady_clock::now() - start, ##__VA_ARGS__);                \
        });
#  if defined WITH_DETAILED_METRICS
#define TC_METRIC_DETAILED_TIMER(category, ...)                                                                  \
        auto TC_METRIC_UNIQUE_NAME(__tc_metric_stop_watch) = MakeMetricStopWatch([&](TimePoint start)            \
        {                                                                                                        \
            int64 duration = int64(std::chrono::duration_cast<Milliseconds>(std::chrono::steady_clock::now() - start).count()); \
            std::string category2 = category;                                                                    \
            if (sMetric->ShouldLog(category2, duration))                                                         \
                sMetric->LogValue(std::move(category2), duration, ##__VA_ARGS__);                                \
        });
#define TC_METRIC_DETAILED_NO_THRESHOLD_TIMER(category, ...) TC_METRIC_TIMER(category, ##__VA_ARGS__)
#define TC_METRIC_DETAILED_EVENT(category, title, description) TC_METRIC_EVENT(category, title, description)
#  else
#define TC_METRIC_DETAILED_EVENT(category, title, description) ((void)0)
#define TC_METRIC_DETAILED_TIMER(category, ...) ((void)0)
#define TC_METRIC_DETAILED_NO_THRESHOLD_TIMER(category, ...) ((void)0)
#  endif

#endif

#endif // METRIC_H__
