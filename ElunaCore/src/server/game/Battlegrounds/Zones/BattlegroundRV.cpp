/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
#include "BattlegroundRV.h"
#include "ObjectAccessor.h"
#include "Language.h"
#include "Player.h"
#include "WorldPacket.h"
#include "GameObject.h"

BattlegroundRV::BattlegroundRV()
{
    BgObjects.resize(BG_RV_OBJECT_MAX);

    StartDelayTimes[BG_STARTING_EVENT_FIRST]  = BG_START_DELAY_1M;
    StartDelayTimes[BG_STARTING_EVENT_SECOND] = BG_START_DELAY_30S;
    StartDelayTimes[BG_STARTING_EVENT_THIRD]  = BG_START_DELAY_15S;
    StartDelayTimes[BG_STARTING_EVENT_FOURTH] = BG_START_DELAY_NONE;
    StartMessageIds[BG_STARTING_EVENT_FIRST]  = LANG_ARENA_ONE_MINUTE;
    StartMessageIds[BG_STARTING_EVENT_SECOND] = LANG_ARENA_THIRTY_SECONDS;
    StartMessageIds[BG_STARTING_EVENT_THIRD]  = LANG_ARENA_FIFTEEN_SECONDS;
    StartMessageIds[BG_STARTING_EVENT_FOURTH] = LANG_ARENA_HAS_BEGUN;
}

BattlegroundRV::~BattlegroundRV() { }

void BattlegroundRV::PostUpdateImpl(uint32 diff)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    if (getTimer() < diff)
    {
        switch (getState())
        {
            case BG_RV_STATE_OPEN_FENCES:
                // Open fire (only at game start)
                for (uint8 i = BG_RV_OBJECT_FIRE_1; i <= BG_RV_OBJECT_FIREDOOR_2; ++i)
                    DoorOpen(i);
                setTimer(BG_RV_CLOSE_FIRE_TIMER);
                setState(BG_RV_STATE_CLOSE_FIRE);
                break;
            case BG_RV_STATE_CLOSE_FIRE:
                for (uint8 i = BG_RV_OBJECT_FIRE_1; i <= BG_RV_OBJECT_FIREDOOR_2; ++i)
                    DoorClose(i);
                // Fire got closed after five seconds, leaves twenty seconds before toggling pillars
                setTimer(BG_RV_FIRE_TO_PILLAR_TIMER);
                setState(BG_RV_STATE_SWITCH_PILLARS);
                break;
            case BG_RV_STATE_SWITCH_PILLARS:
                for (uint8 i = BG_RV_OBJECT_PILAR_1; i <= BG_RV_OBJECT_PULLEY_2; ++i)
                    DoorOpen(i);
                TogglePillarCollision();
                setTimer(BG_RV_PILLAR_SWITCH_TIMER);
                break;
        }
    }
    else
        setTimer(getTimer() - diff);
}

void BattlegroundRV::StartingEventCloseDoors()
{
}

void BattlegroundRV::StartingEventOpenDoors()
{
    // Buff respawn
    SpawnBGObject(BG_RV_OBJECT_BUFF_1, 90);
    SpawnBGObject(BG_RV_OBJECT_BUFF_2, 90);
    // Elevators
    DoorOpen(BG_RV_OBJECT_ELEVATOR_1);
    DoorOpen(BG_RV_OBJECT_ELEVATOR_2);

    setState(BG_RV_STATE_OPEN_FENCES);
    setTimer(BG_RV_FIRST_TIMER);

    // Should be false at first, TogglePillarCollision will do it.
    SetPillarCollision(true);
    TogglePillarCollision();
}

void BattlegroundRV::AddPlayer(Player* player)
{
    Battleground::AddPlayer(player);
    PlayerScores[player->GetGUID()] = new BattlegroundScore;

    UpdateWorldState(BG_RV_WORLD_STATE_A, GetAlivePlayersCountByTeam(ALLIANCE));
    UpdateWorldState(BG_RV_WORLD_STATE_H, GetAlivePlayersCountByTeam(HORDE));
}

void BattlegroundRV::RemovePlayer(Player* /*player*/, uint64 /*guid*/, uint32 /*team*/)
{
    if (GetStatus() == STATUS_WAIT_LEAVE)
        return;

    UpdateWorldState(BG_RV_WORLD_STATE_A, GetAlivePlayersCountByTeam(ALLIANCE));
    UpdateWorldState(BG_RV_WORLD_STATE_H, GetAlivePlayersCountByTeam(HORDE));

    CheckArenaWinConditions();
}

void BattlegroundRV::HandleKillPlayer(Player* player, Player* killer)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    if (!killer)
    {
        sLog->outError(LOG_FILTER_BATTLEGROUND, "BattlegroundRV: Killer player not found");
        return;
    }

    Battleground::HandleKillPlayer(player, killer);

    UpdateWorldState(BG_RV_WORLD_STATE_A, GetAlivePlayersCountByTeam(ALLIANCE));
    UpdateWorldState(BG_RV_WORLD_STATE_H, GetAlivePlayersCountByTeam(HORDE));

    CheckArenaWinConditions();
}

bool BattlegroundRV::HandlePlayerUnderMap(Player* player)
{
    player->TeleportTo(GetMapId(), 763.5f, -284, 28.276f, 2.422f);
    return true;
}

void BattlegroundRV::HandleAreaTrigger(Player* player, uint32 trigger)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    switch (trigger)
    {
        case 5224:
        case 5226:
        // fire was removed in 3.2.0
        case 5473:
        case 5474:
            break;
        default:
            Battleground::HandleAreaTrigger(player, trigger);
            break;
    }
}

void BattlegroundRV::FillInitialWorldStates(WorldPacket &data)
{
    data << uint32(BG_RV_WORLD_STATE_A) << uint32(GetAlivePlayersCountByTeam(ALLIANCE));
    data << uint32(BG_RV_WORLD_STATE_H) << uint32(GetAlivePlayersCountByTeam(HORDE));
    data << uint32(BG_RV_WORLD_STATE) << uint32(1);
}

void BattlegroundRV::Reset()
{
    //call parent's class reset
    Battleground::Reset();
}

bool BattlegroundRV::SetupBattleground()
{
    // elevators
    if (!AddObject(BG_RV_OBJECT_ELEVATOR_1, BG_RV_OBJECT_TYPE_ELEVATOR_1, 763.536377f, -294.535767f, 0.505383f, 3.141593f, 0, 0, 0, RESPAWN_IMMEDIATELY)
        || !AddObject(BG_RV_OBJECT_ELEVATOR_2, BG_RV_OBJECT_TYPE_ELEVATOR_2, 763.506348f, -273.873352f, 0.505383f, 0.000000f, 0, 0, 0, RESPAWN_IMMEDIATELY)
    // buffs
        || !AddObject(BG_RV_OBJECT_BUFF_1, BG_RV_OBJECT_TYPE_BUFF_1, 735.551819f, -284.794678f, 28.276682f, 0.034906f, 0, 0, 0, RESPAWN_IMMEDIATELY)
        || !AddObject(BG_RV_OBJECT_BUFF_2, BG_RV_OBJECT_TYPE_BUFF_2, 791.224487f, -284.794464f, 28.276682f, 2.600535f, 0, 0, 0, RESPAWN_IMMEDIATELY)
    // fire
        || !AddObject(BG_RV_OBJECT_FIRE_1, BG_RV_OBJECT_TYPE_FIRE_1, 743.543457f, -283.799469f, 28.286655f, 3.141593f, 0, 0, 0, RESPAWN_IMMEDIATELY)
        || !AddObject(BG_RV_OBJECT_FIRE_2, BG_RV_OBJECT_TYPE_FIRE_2, 782.971802f, -283.799469f, 28.286655f, 3.141593f, 0, 0, 0, RESPAWN_IMMEDIATELY)
        || !AddObject(BG_RV_OBJECT_FIREDOOR_1, BG_RV_OBJECT_TYPE_FIREDOOR_1, 743.711060f, -284.099609f, 27.542587f, 3.141593f, 0, 0, 0, RESPAWN_IMMEDIATELY)
        || !AddObject(BG_RV_OBJECT_FIREDOOR_2, BG_RV_OBJECT_TYPE_FIREDOOR_2, 783.221252f, -284.133362f, 27.535686f, 0.000000f, 0, 0, 0, RESPAWN_IMMEDIATELY)
    // Gear
        || !AddObject(BG_RV_OBJECT_GEAR_1, BG_RV_OBJECT_TYPE_GEAR_1, 763.664551f, -261.872986f, 26.686588f, 0.000000f, 0, 0, 0, RESPAWN_IMMEDIATELY)
        || !AddObject(BG_RV_OBJECT_GEAR_2, BG_RV_OBJECT_TYPE_GEAR_2, 763.578979f, -306.146149f, 26.665222f, 3.141593f, 0, 0, 0, RESPAWN_IMMEDIATELY)
    // Pulley
        || !AddObject(BG_RV_OBJECT_PULLEY_1, BG_RV_OBJECT_TYPE_PULLEY_1, 700.722290f, -283.990662f, 39.517582f, 3.141593f, 0, 0, 0, RESPAWN_IMMEDIATELY)
        || !AddObject(BG_RV_OBJECT_PULLEY_2, BG_RV_OBJECT_TYPE_PULLEY_2, 826.303833f, -283.996429f, 39.517582f, 0.000000f, 0, 0, 0, RESPAWN_IMMEDIATELY)
    // Pilars
        || !AddObject(BG_RV_OBJECT_PILAR_1, BG_RV_OBJECT_TYPE_PILAR_1, 763.632385f, -306.162384f, 25.909504f, 3.141593f, 0, 0, 0, RESPAWN_IMMEDIATELY)
        || !AddObject(BG_RV_OBJECT_PILAR_2, BG_RV_OBJECT_TYPE_PILAR_2, 723.644287f, -284.493256f, 24.648525f, 3.141593f, 0, 0, 0, RESPAWN_IMMEDIATELY)
        || !AddObject(BG_RV_OBJECT_PILAR_3, BG_RV_OBJECT_TYPE_PILAR_3, 763.611145f, -261.856750f, 25.909504f, 0.000000f, 0, 0, 0, RESPAWN_IMMEDIATELY)
        || !AddObject(BG_RV_OBJECT_PILAR_4, BG_RV_OBJECT_TYPE_PILAR_4, 802.211609f, -284.493256f, 24.648525f, 0.000000f, 0, 0, 0, RESPAWN_IMMEDIATELY)

    // Pilars Collision
        || !AddObject(BG_RV_OBJECT_PILAR_COLLISION_1, BG_RV_OBJECT_TYPE_PILAR_COLLISION_1, 763.632385f, -306.162384f, 30.639660f, 3.141593f, 0, 0, 0, RESPAWN_IMMEDIATELY)
        || !AddObject(BG_RV_OBJECT_PILAR_COLLISION_2, BG_RV_OBJECT_TYPE_PILAR_COLLISION_2, 723.644287f, -284.493256f, 32.382710f, 0.000000f, 0, 0, 0, RESPAWN_IMMEDIATELY)
        || !AddObject(BG_RV_OBJECT_PILAR_COLLISION_3, BG_RV_OBJECT_TYPE_PILAR_COLLISION_3, 763.611145f, -261.856750f, 30.639660f, 0.000000f, 0, 0, 0, RESPAWN_IMMEDIATELY)
        || !AddObject(BG_RV_OBJECT_PILAR_COLLISION_4, BG_RV_OBJECT_TYPE_PILAR_COLLISION_4, 802.211609f, -284.493256f, 32.382710f, 3.141593f, 0, 0, 0, RESPAWN_IMMEDIATELY)

)
    {
        sLog->outError(LOG_FILTER_SQL, "BatteGroundRV: Failed to spawn some object!");
        return false;
    }
    return true;
}


void BattlegroundRV::TogglePillarCollision()
{
    bool apply = GetPillarCollision();

    for (uint8 i = BG_RV_OBJECT_PILAR_1; i <= BG_RV_OBJECT_PILAR_COLLISION_4; ++i)
    {
        if (GameObject* gob = GetBgMap()->GetGameObject(BgObjects[i]))
        {
            if (i >= BG_RV_OBJECT_PILAR_COLLISION_1)
            {
                uint32 _state = GO_STATE_READY;
                if (gob->GetGOInfo()->door.startOpen)
                    _state = GO_STATE_ACTIVE;
                gob->SetGoState(apply ? (GOState)_state : (GOState)(!_state));

                if (gob->GetGOInfo()->door.startOpen)
                    gob->EnableCollision(!apply); // Forced collision toggle
            }

            for (BattlegroundPlayerMap::iterator itr = m_Players.begin(); itr != m_Players.end(); ++itr)
                if (Player* player = ObjectAccessor::FindPlayer(MAKE_NEW_GUID(itr->first, 0, HIGHGUID_PLAYER)))
                    gob->SendUpdateToPlayer(player);
        }
    }

    SetPillarCollision(!apply);
}
