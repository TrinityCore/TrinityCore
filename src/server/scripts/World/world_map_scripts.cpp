/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "ScriptMgr.h"
#include "Transport.h"
#include "ObjectMgr.h"

enum DeeprunTram
{
    MAP_DEEPRUN_TRAM    = 369,

    GO_SUBWAY           = 176080,
    MAX_SUBWAY_COUNT    = 6
};

Position const SubwaysPos[MAX_SUBWAY_COUNT] =
{
    { 4.580650f, 28.20970f, 7.01107f, 1.5708f },
    { 4.528070f, 8.435290f, 7.01107f, 1.5708f },
    { -45.4005f, 2492.790f, 6.98860f, 1.5708f },
    { -45.4007f, 2512.150f, 6.98860f, 1.5708f },
    { -45.3934f, 2472.930f, 6.98860f, 1.5708f },
    { 4.498830f, -11.3475f, 7.01107f, 1.5708f }
};

static QuaternionData worldRotation = QuaternionData(0.0f, 0.0f, 0.7071066f, 0.7071069f);
static QuaternionData parentRotation = QuaternionData(0.0f, 0.0f, 1.0f, -0.0000000437114f);

class world_map_deeprun_tram: public WorldMapScript
{
    public:
        world_map_deeprun_tram() : WorldMapScript("world_map_deeprun_tram", MAP_DEEPRUN_TRAM)
        {
            Initialize();
        }

        void Initialize()
        {
            _initializedTrams = false;
        }

        void OnPlayerEnter(Map* map, Player* /*player*/) override
        {
            if (!_initializedTrams)
            {
                _initializedTrams = true;

                for (uint8 i = 0; i < MAX_SUBWAY_COUNT; ++i)
                {
                    GameObject* transport = new Transport();

                    if (!transport->Create(map->GenerateLowGuid<HighGuid::Transport>(), GO_SUBWAY + i, map, 0, SubwaysPos[i], worldRotation, 255, GO_STATE_READY))
                    {
                        delete transport;
                        continue;
                    }

                    transport->SetParentRotation(parentRotation);

                    uint32 spawnId = sObjectMgr->GenerateGameObjectSpawnId();
                    transport->SetSpawnId(spawnId);

                    transport->setActive(true);
                    transport->SetFarVisible(true);
                    map->AddToMap(transport);
                }
            }
        }
    private:
        bool _initializedTrams;
};

void AddSC_world_map_scripts()
{
    new world_map_deeprun_tram();
}
