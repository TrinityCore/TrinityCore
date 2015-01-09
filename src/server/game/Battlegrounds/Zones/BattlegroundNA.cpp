/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#include "ArenaScore.h"
#include "BattlegroundNA.h"
#include "Player.h"
#include "WorldPacket.h"

void BattlegroundNA::InitializeObjects()
{
    ObjectGUIDsByType.resize(BG_NA_OBJECT_MAX);
    if (GetStatus() == STATUS_IN_PROGRESS)
    {
        if (GetStartTime() >= 47*MINUTE*IN_MILLISECONDS)    // after 47 minutes without one team losing, the arena closes with no winner and no rating change
        {
            UpdateArenaWorldState();
            CheckArenaAfterTimerConditions();
        }
    }

    for (uint32 i = BG_NA_OBJECT_DOOR_1; i <= BG_NA_OBJECT_DOOR_4; ++i)
        SpawnGameObject(i, RESPAWN_IMMEDIATELY);
}

void BattlegroundNA::StartBattleground()
{
    for (uint32 i = BG_NA_OBJECT_DOOR_1; i <= BG_NA_OBJECT_DOOR_2; ++i)
        DoorOpen(i);

    for (uint32 i = BG_NA_OBJECT_BUFF_1; i <= BG_NA_OBJECT_BUFF_2; ++i)
        SpawnGameObject(i, 60);
}

{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    switch (trigger)
    {
        case 4536:                                          // buff trigger?
        case 4537:                                          // buff trigger?
            break;
        default:
            Battleground::HandleAreaTrigger(player, trigger);
            break;
    }
}

void BattlegroundNA::FillInitialWorldStates(WorldPacket& data)
{
    data << uint32(0xa11) << uint32(1);     // 9 show
    Arena::FillInitialWorldStates(data);
}
        TC_LOG_ERROR("sql.sql", "BatteGroundNA: Failed to spawn some object!");
