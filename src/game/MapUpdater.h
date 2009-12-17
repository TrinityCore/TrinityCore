#ifndef _MAP_UPDATER_H_INCLUDED
#define _MAP_UPDATER_H_INCLUDED

#include <ace/Thread_Mutex.h>
#include <ace/Condition_Thread_Mutex.h>

#include "DelayExecutor.h"

class Map;

class MapUpdater
{
    public:
        MapUpdater();
        virtual ~MapUpdater();

        friend class MapUpdateRequest;

        int schedule_update(Map& map, ACE_UINT32 diff);

        int wait();

        int activate(size_t num_threads);

        int deactivate(void);

        bool activated();
    private:
        void update_finished();

        DelayExecutor m_executor;
        ACE_Condition_Thread_Mutex m_condition;
        ACE_Thread_Mutex m_mutex;
        size_t pedning_requests;
};
#endif //_MAP_UPDATER_H_INCLUDED
