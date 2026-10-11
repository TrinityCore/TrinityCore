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

#ifndef TRINITYCORE_METRIC_H
#define TRINITYCORE_METRIC_H

#include "AsioHacksFwd.h"
#include "Define.h"
#include "Duration.h"
#include "Hash.h"
#include "MPSCQueue.h"
#include <functional>
#include <memory>
#include <string>
#include <unordered_map>
#include <utility>
#include <variant>

enum MetricDataType
{
    METRIC_DATA_VALUE,
    METRIC_DATA_EVENT
};

using MetricTag = std::pair<std::string, std::string>;
using MetricTags = std::variant<std::monostate, std::array<MetricTag, 2>, std::vector<MetricTag>>;

struct MetricData
{
    std::string Category;
    SystemTimePoint Timestamp;
    MetricDataType Type = METRIC_DATA_VALUE;

    // LogValue-specific fields
    MetricTags Tags;

    // LogEvent-specific fields
    std::string Title;

    std::string ValueOrEventText;

    // intrusive queue link
    std::atomic<MetricData*> QueueLink;
};

class TC_COMMON_API Metric
{
private:
    using iostream = boost::asio::basic_socket_iostream<boost::asio::ip::tcp, std::chrono::steady_clock, boost::asio::wait_traits<std::chrono::steady_clock>>;

    iostream& GetDataStream() { return *_dataStream; }
    std::unique_ptr<iostream> _dataStream;
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
    std::unordered_map<std::string, int64, Trinity::TransparentHash<std::string_view>, std::equal_to<>> _thresholds;

    bool Connect();
    void SendBatch();
    void ScheduleSend();
    void ScheduleOverallStatusLog();

    static std::string FormatInfluxDBValue(bool value);
    template <class T> requires std::integral<T> && (!std::same_as<T, bool>)
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
    Metric(Metric const&) = delete;
    Metric(Metric&&) = delete;
    Metric& operator=(Metric const&) = delete;
    Metric& operator=(Metric&&) = delete;
    static Metric* instance();

    void Initialize(std::string const& realmName, Trinity::Asio::IoContext& ioContext, std::function<void()> overallStatusLogger);
    void LoadFromConfigs();
    void Update();
    bool ShouldLog(std::string_view category, int64 value) const;

    template<class T, class... TagsList>
    void LogValue(std::string_view category, T value, TagsList&&... tags) noexcept
    {
        using TagsType = std::conditional_t<(sizeof...(tags) > 2),
            std::vector<MetricTag>,
            std::conditional_t<(sizeof...(tags) > 0),
                std::array<MetricTag, 2>,
                std::monostate>>;

        MetricData* data = new MetricData
        {
            .Category = std::string(category),
            .Timestamp = std::chrono::system_clock::now(),
            .Type = METRIC_DATA_VALUE,
            .Tags = MetricTags{ std::in_place_type<TagsType> },
            .ValueOrEventText = FormatInfluxDBValue(value)
        };
        if constexpr (sizeof...(tags) > 2)
        {
            TagsType& tagsVector = std::get<TagsType>(data->Tags);
            (tagsVector.emplace_back(std::forward<TagsList>(tags)), ...);
        }
        else if constexpr (sizeof...(tags) == 2)
        {
            [](TagsType& tagsArray, auto const& tag1, auto const& tag2)
            {
                tagsArray[0] = tag1;
                tagsArray[1] = tag2;
            }(std::get<TagsType>(data->Tags), std::forward<TagsList>(tags)...);
        }
        else if constexpr (sizeof...(tags) == 1)
        {
            [](TagsType& tagsArray, auto const& tag1)
            {
                tagsArray[0] = tag1;
            }(std::get<TagsType>(data->Tags), std::forward<TagsList>(tags)...);
        }

        _queuedData.Enqueue(data);
    }

    void LogEvent(std::string_view category, std::string_view title, std::string description);

    void Unload();
    bool IsEnabled() const { return _enabled; }
};

#define sMetric Metric::instance()

struct MetricStopWatchBase
{
    void Enable(Metric* metric) noexcept
    {
        MetricInstance = metric;
        StartTime = std::chrono::steady_clock::now();
    }

    Metric* MetricInstance = nullptr;
    TimePoint StartTime = { };
};

template<typename LoggerType>
struct MetricStopWatch : public LoggerType, public MetricStopWatchBase
{
    ~MetricStopWatch()
    {
        if (MetricInstance)
            LoggerType::operator()(MetricInstance, StartTime);
    }
};

template<typename LoggerType>
MetricStopWatch(LoggerType) -> MetricStopWatch<LoggerType>;

#define TC_METRIC_TAG(name, value) std::pair<std::string_view, std::string_view>(name, value)

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
#define TC_METRIC_EVENT(category, title, description)                  \
        do {                                                           \
            if (Metric* metric = sMetric; metric->IsEnabled())         \
                metric->LogEvent(category, title, description);        \
        } while (false)
#define TC_METRIC_VALUE(category, value, ...)                          \
        do {                                                           \
            if (Metric* metric = sMetric; metric->IsEnabled())         \
                metric->LogValue(category, value, ## __VA_ARGS__);     \
        } while (false)
#define TC_METRIC_TIMER_IMPL(variable, category, ...)                                               \
        MetricStopWatch variable{ [&](Metric* metric, TimePoint start)                              \
        {                                                                                           \
            metric->LogValue(category, std::chrono::steady_clock::now() - start, ## __VA_ARGS__);   \
        } };                                                                                        \
        do                                                                                          \
        {                                                                                           \
            if (Metric* metric = sMetric; metric->IsEnabled())                                      \
                variable.Enable(metric);                                                            \
        } while (false)
#define TC_METRIC_TIMER(category, ...) TC_METRIC_TIMER_IMPL(TC_METRIC_UNIQUE_NAME(tc_metric_stop_watch_), category, ## __VA_ARGS__)
#  if defined WITH_DETAILED_METRICS
#define TC_METRIC_DETAILED_TIMER_IMPL(variable, category, ...)                                                      \
        MetricStopWatch variable{ [&](Metric* metric, TimePoint start)                                              \
        {                                                                                                           \
            int64 duration = int64(duration_cast<Milliseconds>(std::chrono::steady_clock::now() - start).count());  \
            if (metric->ShouldLog(category, duration))                                                              \
                metric->LogValue(category, duration, ## __VA_ARGS__);                                               \
        } };                                                                                                        \
        do                                                                                                          \
        {                                                                                                           \
            if (Metric* metric = sMetric; metric->IsEnabled())                                                      \
                variable.Enable(metric);                                                                            \
        } while (false)
#define TC_METRIC_DETAILED_TIMER(category, ...) TC_METRIC_DETAILED_TIMER_IMPL(TC_METRIC_UNIQUE_NAME(tc_metric_stop_watch_), category, ## __VA_ARGS__)
#define TC_METRIC_DETAILED_NO_THRESHOLD_TIMER(category, ...) TC_METRIC_TIMER(category, ## __VA_ARGS__)
#define TC_METRIC_DETAILED_EVENT(category, title, description) TC_METRIC_EVENT(category, title, description)
#  else
#define TC_METRIC_DETAILED_EVENT(category, title, description) ((void)0)
#define TC_METRIC_DETAILED_TIMER(category, ...) ((void)0)
#define TC_METRIC_DETAILED_NO_THRESHOLD_TIMER(category, ...) ((void)0)
#  endif

#endif

#endif // TRINITYCORE_METRIC_H
