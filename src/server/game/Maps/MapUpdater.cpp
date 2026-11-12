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

#include "MapUpdater.h"
#include "DatabaseEnv.h"
#include "Map.h"
#include "Metric.h"

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
            TC_METRIC_TIMER("map_update_time_diff", TC_METRIC_TAG("map_id", std::to_string(m_map.GetId())));
            m_map.Update (m_diff);
            m_updater.update_finished();
        }
};

MapUpdater::MapUpdater() : _pendingRequests(0)
{
}

MapUpdater::~MapUpdater() = default;

void MapUpdater::activate(size_t num_threads)
{
    for (size_t i = 0; i < num_threads; ++i)
        _workerThreads.emplace_back(&MapUpdater::WorkerThread, this);
}

void MapUpdater::deactivate()
{
    wait();

    _queue.Cancel();

    for (auto& thread : _workerThreads)
        thread.join();
}

void MapUpdater::wait()
{
    for (;;)
    {
        std::size_t pendingRequests = _pendingRequests.load(std::memory_order::acquire);
        if (!pendingRequests)
            break;

        // wait for change
        _pendingRequests.wait(pendingRequests, std::memory_order::relaxed);
    }
}

void MapUpdater::schedule_update(Map& map, uint32 diff)
{
    ++_pendingRequests;

    _queue.Push(std::make_unique<MapUpdateRequest>(map, *this, diff));
}

bool MapUpdater::activated() const
{
    return !_workerThreads.empty();
}

void MapUpdater::update_finished()
{
    if (_pendingRequests.fetch_sub(1, std::memory_order::release) == 1)
        _pendingRequests.notify_all();
}

void MapUpdater::WorkerThread()
{
    LoginDatabase.WarnAboutSyncQueries(true);
    CharacterDatabase.WarnAboutSyncQueries(true);
    WorldDatabase.WarnAboutSyncQueries(true);
    HotfixDatabase.WarnAboutSyncQueries(true);

    while (true)
    {
        std::unique_ptr<MapUpdateRequest> request = nullptr;

        if (!_queue.WaitAndPop(request))
            return;

        request->call();
    }
}
