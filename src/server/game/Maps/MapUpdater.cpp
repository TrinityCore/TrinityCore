/*
* Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#include <mutex>
#include <condition_variable>

#include "MapUpdater.h"
#include "Map.h"


class MapUpdateRequest
{
    private:

        Map& m_map;
        MapUpdater& m_updater;
        uint32 m_diff;

    public:

        MapUpdateRequest(Map& m, MapUpdater& u, uint32 d)
            : m_map(m), m_updater(u), m_diff(d)
        {
        }

        void call()
        {
            m_map.Update (m_diff);
            m_updater.update_finished();
        }
};

MapUpdater::MapUpdater(): pending_requests(0) { }

MapUpdater::~MapUpdater()
{
    deactivate();
}

void MapUpdater::activate(size_t num_threads)
{
    for (size_t i = 0; i < num_threads; ++i)
    {
        _workerThreads.push_back(std::thread(&MapUpdater::WorkerThread, this));
    }
}

void MapUpdater::deactivate()
{
    wait();

    _queue.Cancel();

    for (auto& thread : _workerThreads)
    {
        thread.join();
    }
}

void MapUpdater::wait()
{
    std::unique_lock<std::mutex> lock(_lock);

    while (pending_requests > 0)
        _condition.wait(lock);

    lock.unlock();
}

void MapUpdater::schedule_update(Map& map, uint32 diff)
{
    std::lock_guard<std::mutex> lock(_lock);

    ++pending_requests;

    _queue.Push(new MapUpdateRequest(map, *this, diff));
}

bool MapUpdater::activated()
{
    return _workerThreads.size() > 0;
}

void MapUpdater::update_finished()
{
    std::lock_guard<std::mutex> lock(_lock);

    --pending_requests;

    _condition.notify_all();
}

void MapUpdater::WorkerThread()
{
    while (1)
    {
        MapUpdateRequest* request = nullptr;

        _queue.WaitAndPop(request);

        if (_cancelationToken)
            return;

        request->call();

        delete request;
    }
}
