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

#ifndef _MAP_UPDATER_H_INCLUDED
#define _MAP_UPDATER_H_INCLUDED

#include "Define.h"
#include "ProducerConsumerQueue.h"
#include <atomic>
#include <memory>
#include <thread>
#include <vector>

class MapUpdateRequest;
class Map;

class TC_GAME_API MapUpdater
{
    public:

        MapUpdater();
        ~MapUpdater();

        friend class MapUpdateRequest;

        void schedule_update(Map& map, uint32 diff);

        void wait();

        void activate(size_t num_threads);

        void deactivate();

        bool activated() const;

    private:

        ProducerConsumerQueue<std::unique_ptr<MapUpdateRequest>> _queue;

        std::vector<std::thread> _workerThreads;

        std::atomic<std::size_t> _pendingRequests;

        void update_finished();

        void WorkerThread();
};

#endif //_MAP_UPDATER_H_INCLUDED
