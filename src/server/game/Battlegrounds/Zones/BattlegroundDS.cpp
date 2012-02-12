/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#include "Battleground.h"
#include "BattlegroundDS.h"
#include "Language.h"
#include "Player.h"
#include "Object.h"
#include "ObjectMgr.h"
#include "WorldPacket.h"

BattlegroundDS::BattlegroundDS()
{
    BgObjects.resize(BG_DS_OBJECT_MAX);

    StartDelayTimes[BG_STARTING_EVENT_FIRST]  = BG_START_DELAY_1M;
    StartDelayTimes[BG_STARTING_EVENT_SECOND] = BG_START_DELAY_30S;
    StartDelayTimes[BG_STARTING_EVENT_THIRD]  = BG_START_DELAY_15S;
    StartDelayTimes[BG_STARTING_EVENT_FOURTH] = BG_START_DELAY_NONE;
    //we must set messageIds
    StartMessageIds[BG_STARTING_EVENT_FIRST]  = LANG_ARENA_ONE_MINUTE;
    StartMessageIds[BG_STARTING_EVENT_SECOND] = LANG_ARENA_THIRTY_SECONDS;
    StartMessageIds[BG_STARTING_EVENT_THIRD]  = LANG_ARENA_FIFTEEN_SECONDS;
    StartMessageIds[BG_STARTING_EVENT_FOURTH] = LANG_ARENA_HAS_BEGUN;
}

BattlegroundDS::~BattlegroundDS()
{

}

void BattlegroundDS::PostUpdateImpl(uint32 diff)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    // constant checking if players are not in starting places
    if (_KnockbackTimer <= diff)
    {
        for (BattlegroundPlayerMap::const_iterator itr = GetPlayers().begin(); itr != GetPlayers().end(); ++itr)
        {
            Player *player = ObjectAccessor::FindPlayer(itr->first);
            if (!player)
                continue;

            if (player->GetDistance2d(1214.0f, 765.0f) <= 50.0f && player->GetPositionZ() > 13.0f)
                player->KnockBackWithAngle(0.0f, 50.0f, 8.0f);
            else if (player->GetDistance2d(1369.0f, 817.0f) <= 50.0f && player->GetPositionZ() > 13.0f)
                player->KnockBackWithAngle(M_PI, 50.0f, 8.0f);
        }
        _KnockbackTimer = 5*IN_MILLISECONDS;
    } else _KnockbackTimer -= diff;

    // Waterfall handling
    if (getWaterFallTimer() < diff)
    {
        if (getWaterFallStatus() == BG_DS_WATERFALL_STATUS_OFF) // Add the water
        {
            DoorClose(BG_DS_OBJECT_WATER_2);
            setWaterFallTimer(BG_DS_WATERFALL_WARNING_DURATION);
            setWaterFallStatus(BG_DS_WATERFALL_STATUS_WARNING);
        }
        else if (getWaterFallStatus() == BG_DS_WATERFALL_STATUS_WARNING) // Active collision
        {
            if (GameObject* gob = GetBgMap()->GetGameObject(BgObjects[BG_DS_OBJECT_WATER_1]))
                gob->SetGoState(GO_STATE_READY);

            setWaterFallTimer(BG_DS_WATERFALL_DURATION);
            setWaterFallStatus(BG_DS_WATERFALL_STATUS_ON);
        }
        else //if (getWaterFallStatus() == BG_DS_WATERFALL_STATUS_ON) // Remove collision and water
        {
            // turn off collision
            if (GameObject* gob = GetBgMap()->GetGameObject(BgObjects[BG_DS_OBJECT_WATER_1]))
                gob->SetGoState(GO_STATE_ACTIVE);

            DoorOpen(BG_DS_OBJECT_WATER_2);
            setWaterFallTimer(BG_DS_WATERFALL_TIMER);
            setWaterFallStatus(BG_DS_WATERFALL_STATUS_OFF);
        }
    }
    else
        setWaterFallTimer(getWaterFallTimer() - diff);

    // handling of knockback when waterfall is active
    if (getWaterFallStatus() == BG_DS_WATERFALL_STATUS_ON)
    {
        for(BattlegroundPlayerMap::const_iterator itr = GetPlayers().begin(); itr != GetPlayers().end();itr++)
        {
            Player * player = ObjectAccessor::FindPlayer(itr->first);
            if (!player)
                continue;

            if (player->GetDistance2d(1291.56f, 790.837f) < 3.8f)
                player->KnockbackFrom(1291.56f, 790.837f, 30.0f, 4.5f);
        }
    }
}

void BattlegroundDS::StartingEventCloseDoors()
{
    for (uint32 i = BG_DS_OBJECT_DOOR_1; i <= BG_DS_OBJECT_DOOR_2; ++i)
        SpawnBGObject(i, RESPAWN_IMMEDIATELY);
}

void BattlegroundDS::StartingEventOpenDoors()
{
    for (uint32 i = BG_DS_OBJECT_DOOR_1; i <= BG_DS_OBJECT_DOOR_2; ++i)
        DoorOpen(i);

    for (uint32 i = BG_DS_OBJECT_BUFF_1; i <= BG_DS_OBJECT_BUFF_2; ++i)
        SpawnBGObject(i, 60);

    setWaterFallTimer(BG_DS_WATERFALL_TIMER);
    setWaterFallStatus(BG_DS_WATERFALL_STATUS_OFF);

    SpawnBGObject(BG_DS_OBJECT_WATER_2, RESPAWN_IMMEDIATELY);
    DoorOpen(BG_DS_OBJECT_WATER_2);

    // Turn off collision
    if (GameObject* gob = GetBgMap()->GetGameObject(BgObjects[BG_DS_OBJECT_WATER_1]))
        gob->SetGoState(GO_STATE_ACTIVE);

    // Init start checking of starting places
    _KnockbackTimer = 10*IN_MILLISECONDS;
}

void BattlegroundDS::AddPlayer(Player* player)
{
    Battleground::AddPlayer(player);
    //create score and add it to map, default values are set in constructor
    BattlegroundDSScore* score = new BattlegroundDSScore;

    PlayerScores[player->GetGUID()] = score;

    UpdateArenaWorldState();
}

void BattlegroundDS::RemovePlayer(Player* /*player*/, uint64 /*guid*/, uint32 /*team*/)
{
    if (GetStatus() == STATUS_WAIT_LEAVE)
        return;

    UpdateArenaWorldState();
    CheckArenaWinConditions();
}

void BattlegroundDS::HandleKillPlayer(Player* player, Player* killer)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    if (!killer)
    {
        sLog->outError("BattlegroundDS: Killer player not found");
        return;
    }

    Battleground::HandleKillPlayer(player, killer);

    UpdateArenaWorldState();
    CheckArenaWinConditions();
}

void BattlegroundDS::HandleAreaTrigger(Player* Source, uint32 Trigger)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    switch (Trigger)
    {
        case 5347:
        case 5348:
            break;
        default:
            sLog->outError("WARNING: Unhandled AreaTrigger in Battleground: %u", Trigger);
            Source->GetSession()->SendAreaTriggerMessage("Warning: Unhandled AreaTrigger in Battleground: %u", Trigger);
            break;
    }
}

bool BattlegroundDS::HandlePlayerUnderMap(Player* player)
{
    player->TeleportTo(GetMapId(), 1299.046f, 784.825f, 9.338f, 2.422f, false);
    return true;
}

void BattlegroundDS::FillInitialWorldStates(WorldPacket &data)
{
    data << uint32(3610) << uint32(1);                                              // 9 show
    UpdateArenaWorldState();
}

void BattlegroundDS::Reset()
{
    //call parent's class reset
    Battleground::Reset();
}

bool BattlegroundDS::SetupBattleground()
{
    // gates
    if (!AddObject(BG_DS_OBJECT_DOOR_1, BG_DS_OBJECT_TYPE_DOOR_1, 1350.95f, 817.2f, 20.8096f, 3.15f, 0, 0, 0.99627f, 0.0862864f, RESPAWN_IMMEDIATELY)
        || !AddObject(BG_DS_OBJECT_DOOR_2, BG_DS_OBJECT_TYPE_DOOR_2, 1232.65f, 764.913f, 20.0729f, 6.3f, 0, 0, 0.0310211f, -0.999519f, RESPAWN_IMMEDIATELY)
    // water
        || !AddObject(BG_DS_OBJECT_WATER_1, BG_DS_OBJECT_TYPE_WATER_1, 1291.56f, 790.837f, 7.1f, 3.14238f, 0, 0, 0.694215f, -0.719768f, 120)
        || !AddObject(BG_DS_OBJECT_WATER_2, BG_DS_OBJECT_TYPE_WATER_2, 1291.56f, 790.837f, 7.1f, 3.14238f, 0, 0, 0.694215f, -0.719768f, 120)
    // buffs
        || !AddObject(BG_DS_OBJECT_BUFF_1, BG_DS_OBJECT_TYPE_BUFF_1, 1291.7f, 813.424f, 7.11472f, 4.64562f, 0, 0, 0.730314f, -0.683111f, 120)
        || !AddObject(BG_DS_OBJECT_BUFF_2, BG_DS_OBJECT_TYPE_BUFF_2, 1291.7f, 768.911f, 7.11472f, 1.55194f, 0, 0, 0.700409f, 0.713742f, 120))
    {
        sLog->outErrorDb("BatteGroundDS: Failed to spawn some object!");
        return false;
    }

    return true;
}
