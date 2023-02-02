#include "../botpch.h"
#include "playerbot.h"
#include "PlayerbotAIConfig.h"
#include "PerformanceMonitor.h"

#include "../../modules/Bots/ahbot/AhBot.h"
#include "DatabaseEnv.h"
#include "PlayerbotAI.h"

#include "../../modules/Bots/ahbot/AhBotConfig.h"

PerformanceMonitor::PerformanceMonitor() {}
PerformanceMonitor::~PerformanceMonitor()
{
}

PerformanceMonitorOperation* PerformanceMonitor::start(PerformanceMetric metric, string name)
{
    PerformanceData *pd = data[metric][name];
    if (!pd)
    {
        pd = new PerformanceData();
        pd->minTime = pd->maxTime = pd->totalTime = pd->count = 0;
        data[metric][name] = pd;
    }

    return sPlayerbotAIConfig.perfMonEnabled ? new PerformanceMonitorOperation(pd) : NULL;
}

void PerformanceMonitor::PrintStats()
{
    for (map<PerformanceMetric, map<string, PerformanceData*> >::iterator i = data.begin(); i != data.end(); ++i)
    {
        map<string, PerformanceData*> pdMap = i->second;

        string key;
        switch (i->first)
        {
        case PERF_MON_TRIGGER: key = "T"; break;
        case PERF_MON_VALUE: key = "V"; break;
        case PERF_MON_ACTION: key = "A"; break;
        case PERF_MON_RNDBOT: key = "RndBot"; break;
        case PERF_MON_TOTAL: key = "Total"; break;
        default: key = "?";
        }

        for (map<string, PerformanceData*>::iterator j = pdMap.begin(); j != pdMap.end(); ++j)
        {
            PerformanceData* pd = j->second;
            float avg = (float)pd->totalTime / (float)pd->count;
            if (avg >= 0.5f || pd->maxTime > 10)
            {
                sLog.outString("%6u .. %6u (%.4f of %6u) - %s: %s",
                        pd->minTime, pd->maxTime, avg, pd->count,
                        key.c_str(), j->first.c_str());
            }
        }
    }
}

void PerformanceMonitor::Reset()
{
    for (map<PerformanceMetric, map<string, PerformanceData*> >::iterator i = data.begin(); i != data.end(); ++i)
    {
        map<string, PerformanceData*> pdMap = i->second;
        for (map<string, PerformanceData*>::iterator j = pdMap.begin(); j != pdMap.end(); ++j)
        {
#ifdef CMANGOS
            PerformanceData* pd = j->second;
            std::lock_guard<std::mutex> guard(pd->lock);
            pd->minTime = pd->maxTime = pd->totalTime = pd->count = 0;
#endif
        }
    }
}

PerformanceMonitorOperation::PerformanceMonitorOperation(PerformanceData* data) : data(data)
{
#ifdef CMANGOS
    started = (std::chrono::time_point_cast<std::chrono::milliseconds>(Clock::now())).time_since_epoch();
#endif
}

void PerformanceMonitorOperation::finish()
{
#ifdef CMANGOS
    std::chrono::milliseconds finished = (std::chrono::time_point_cast<std::chrono::milliseconds>(Clock::now())).time_since_epoch();
    uint32 elapsed = (finished - started).count();

    std::lock_guard<std::mutex> guard(data->lock);
    if (elapsed > 0)
    {
        if (!data->minTime || data->minTime > elapsed) data->minTime = elapsed;
        if (!data->maxTime || data->maxTime < elapsed) data->maxTime = elapsed;
        data->totalTime += elapsed;
    }
    data->count++;
    delete this;
#endif
}

#ifdef CMANGOS
bool ChatHandler::HandlePerfMonCommand(char* args)
{
    if (!strcmp(args, "reset"))
    {
        sPerformanceMonitor.Reset();
        return true;
    }

    sPerformanceMonitor.PrintStats();
    return true;
}
#endif