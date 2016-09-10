/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#include "BattlegroundBE.h"
#include "Player.h"
#include "WorldPacket.h"

BattlegroundGOSpawnPoint const BG_BE_GameObjects[BG_BE_OBJECT_MAX] =
{
    // gates
    { BG_BE_OBJECT_TYPE_DOOR_1, { 6287.277f, 282.1877f, 3.810925f, -2.26019700f }, { 0.f, 0.f, -0.90445420f, 0.4265707f }, RESPAWN_IMMEDIATELY },
    { BG_BE_OBJECT_TYPE_DOOR_2, { 6189.546f, 241.7099f, 3.101481f,  0.88139170f }, { 0.f, 0.f,  0.42656890f, 0.9044551f }, RESPAWN_IMMEDIATELY },
    { BG_BE_OBJECT_TYPE_DOOR_3, { 6299.116f, 296.5494f, 3.308032f,  0.88139180f }, { 0.f, 0.f,  0.42656900f, 0.9044550f }, RESPAWN_IMMEDIATELY },
    { BG_BE_OBJECT_TYPE_DOOR_4, { 6177.708f, 227.3481f, 3.604374f, -2.26019700f }, { 0.f, 0.f, -0.90445420f, 0.4265707f }, RESPAWN_IMMEDIATELY },
    // buffs
    { BG_BE_OBJECT_TYPE_BUFF_1, { 6249.042f, 275.3239f, 11.22033f, -1.44862200f }, { 0.f, 0.f, -0.66261960f, 0.7489561f }, 2 * MINUTE          },
    { BG_BE_OBJECT_TYPE_BUFF_2, { 6228.260f, 249.5660f, 11.21812f, -0.06981307f }, { 0.f, 0.f, -0.03489876f, 0.9993908f }, 2 * MINUTE          }
};

BattlegroundBE::BattlegroundBE()
{
    SetGameObjectsNumber(BG_BE_OBJECT_MAX);
}

void BattlegroundBE::StartingEventCloseDoors()
{
    for (uint32 i = BG_BE_OBJECT_DOOR_1; i <= BG_BE_OBJECT_DOOR_4; ++i)
        SpawnBGObject(i, RESPAWN_IMMEDIATELY);

    for (uint32 i = BG_BE_OBJECT_BUFF_1; i <= BG_BE_OBJECT_BUFF_2; ++i)
        SpawnBGObject(i, RESPAWN_ONE_DAY);
}

void BattlegroundBE::StartingEventOpenDoors()
{
    for (uint32 i = BG_BE_OBJECT_DOOR_1; i <= BG_BE_OBJECT_DOOR_2; ++i)
        DoorOpen(i);

    for (uint32 i = BG_BE_OBJECT_BUFF_1; i <= BG_BE_OBJECT_BUFF_2; ++i)
        SpawnBGObject(i, 60);
}

void BattlegroundBE::HandleAreaTrigger(Player* player, uint32 trigger)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    switch (trigger)
    {
        case 4538:                                          // buff trigger?
        case 4539:                                          // buff trigger?
            break;
        default:
            Battleground::HandleAreaTrigger(player, trigger);
            break;
    }
}

void BattlegroundBE::FillInitialWorldStates(WorldPacket& data)
{
    data << uint32(0x9f3) << uint32(1);     // 9 show
    Arena::FillInitialWorldStates(data);
}

bool BattlegroundBE::SetupBattleground()
{
    for (uint32 i = 0; i < BG_BE_OBJECT_MAX; ++i)
    {
        BattlegroundGOSpawnPoint const& object = BG_BE_GameObjects[i];
        if (!AddObject(i, object.Entry, object.Pos, object.Rot, object.SpawnTime))
        {
            TC_LOG_ERROR("bg.battleground", "BattleGroundBE: Failed to spawn some object (Entry %u). Battleground not created!", object.Entry);
            return false;
        }
    }

    return true;
}
