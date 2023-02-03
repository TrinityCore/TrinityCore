#ifndef _PerformanceMonitor_H
#define _PerformanceMonitor_H

#include "Common.h"
#include "PlayerbotAIBase.h"
#include "PlayerbotAIConfig.h"

using namespace std;

struct PerformanceData
{
    uint32 minTime, maxTime, totalTime, count;
#ifdef CMANGOS
    std::mutex lock;
#endif
};

enum PerformanceMetric
{
    PERF_MON_TRIGGER,
    PERF_MON_VALUE,
    PERF_MON_ACTION,
    PERF_MON_RNDBOT,
    PERF_MON_TOTAL
};

class PerformanceMonitorOperation
{
public:
    PerformanceMonitorOperation(PerformanceData* data);
    void finish();

private:
    PerformanceData* data;
#ifdef CMANGOS
    std::chrono::milliseconds started;
#endif
};

class PerformanceMonitor
{
    public:
        PerformanceMonitor();
        virtual ~PerformanceMonitor();
        static PerformanceMonitor& instance()
        {
            static PerformanceMonitor instance;
            return instance;
        }

	public:
        PerformanceMonitorOperation* start(PerformanceMetric metric, string name);
        void PrintStats();
        void Reset();

	private:
        map<PerformanceMetric, map<string, PerformanceData*> > data;
};


#define sPerformanceMonitor PerformanceMonitor::instance()

#endif
