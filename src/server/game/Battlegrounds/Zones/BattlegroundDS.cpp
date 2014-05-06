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

#include "BattlegroundDS.h"
#include "Creature.h"
#include "GameObject.h"
#include "Language.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "WorldPacket.h"

BattlegroundDS::BattlegroundDS()
{
    BgObjects.resize(BG_DS_OBJECT_MAX);
    BgCreatures.resize(BG_DS_NPC_MAX);

    _waterfallTimer = 0;
    _waterfallStatus = 0;
    _waterfallKnockbackTimer = 0;
    _pipeKnockBackTimer = 0;
    _pipeKnockBackCount = 0;

    StartDelayTimes[BG_STARTING_EVENT_FIRST]  = BG_START_DELAY_1M;
    StartDelayTimes[BG_STARTING_EVENT_SECOND] = BG_START_DELAY_30S;
    StartDelayTimes[BG_STARTING_EVENT_THIRD]  = BG_START_DELAY_15S;
    StartDelayTimes[BG_STARTING_EVENT_FOURTH] = BG_START_DELAY_NONE;
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

    if (getPipeKnockBackCount() < BG_DS_PIPE_KNOCKBACK_TOTAL_COUNT)
    {
        if (getPipeKnockBackTimer() < diff)
        {
            for (uint32 i = BG_DS_NPC_PIPE_KNOCKBACK_1; i <= BG_DS_NPC_PIPE_KNOCKBACK_2; ++i)
                if (Creature* waterSpout = GetBgMap()->GetCreature(BgCreatures[i]))
                    waterSpout->CastSpell(waterSpout, BG_DS_SPELL_FLUSH, true);

            setPipeKnockBackCount(getPipeKnockBackCount() + 1);
            setPipeKnockBackTimer(BG_DS_PIPE_KNOCKBACK_DELAY);
        }
        else
            setPipeKnockBackTimer(getPipeKnockBackTimer() - diff);
    }

    if (getWaterFallStatus() == BG_DS_WATERFALL_STATUS_ON) // Repeat knockback while the waterfall still active
    {
        if (getWaterFallKnockbackTimer() < diff)
        {
            if (Creature* waterSpout = GetBgMap()->GetCreature(BgCreatures[BG_DS_NPC_WATERFALL_KNOCKBACK]))
                waterSpout->CastSpell(waterSpout, BG_DS_SPELL_WATER_SPOUT, true);

            setWaterFallKnockbackTimer(BG_DS_WATERFALL_KNOCKBACK_TIMER);
        }
        else
            setWaterFallKnockbackTimer(getWaterFallKnockbackTimer() - diff);
    }

    if (getWaterFallTimer() < diff)
    {
        if (getWaterFallStatus() == BG_DS_WATERFALL_STATUS_OFF) // Add the water
        {
            DoorClose(BG_DS_OBJECT_WATER_2);
            setWaterFallTimer(BG_DS_WATERFALL_WARNING_DURATION);
            setWaterFallStatus(BG_DS_WATERFALL_STATUS_WARNING);
        }
        else if (getWaterFallStatus() == BG_DS_WATERFALL_STATUS_WARNING) // Active collision and start knockback timer
        {
            if (GameObject* gob = GetBgMap()->GetGameObject(BgObjects[BG_DS_OBJECT_WATER_1]))
                gob->SetGoState(GO_STATE_READY);

            setWaterFallTimer(BG_DS_WATERFALL_DURATION);
            setWaterFallStatus(BG_DS_WATERFALL_STATUS_ON);
            setWaterFallKnockbackTimer(BG_DS_WATERFALL_KNOCKBACK_TIMER);
        }
        else //if (getWaterFallStatus() == BG_DS_WATERFALL_STATUS_ON) // Remove collision and water
        {
            // turn off collision
            if (GameObject* gob = GetBgMap()->GetGameObject(BgObjects[BG_DS_OBJECT_WATER_1]))
                gob->SetGoState(GO_STATE_ACTIVE);

            DoorOpen(BG_DS_OBJECT_WATER_2);
            setWaterFallTimer(urand(BG_DS_WATERFALL_TIMER_MIN, BG_DS_WATERFALL_TIMER_MAX));
            setWaterFallStatus(BG_DS_WATERFALL_STATUS_OFF);
        }
    }
    else
        setWaterFallTimer(getWaterFallTimer() - diff);
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

    setWaterFallTimer(urand(BG_DS_WATERFALL_TIMER_MIN, BG_DS_WATERFALL_TIMER_MAX));
    setWaterFallStatus(BG_DS_WATERFALL_STATUS_OFF);

    setPipeKnockBackTimer(BG_DS_PIPE_KNOCKBACK_FIRST_DELAY);
    setPipeKnockBackCount(0);

    SpawnBGObject(BG_DS_OBJECT_WATER_2, RESPAWN_IMMEDIATELY);
    DoorOpen(BG_DS_OBJECT_WATER_2);

    // Turn off collision
    if (GameObject* gob = GetBgMap()->GetGameObject(BgObjects[BG_DS_OBJECT_WATER_1]))
        gob->SetGoState(GO_STATE_ACTIVE);

    // Remove effects of Demonic Circle Summon
    for (BattlegroundPlayerMap::const_iterator itr = GetPlayers().begin(); itr != GetPlayers().end(); ++itr)
        if (Player* player = ObjectAccessor::FindPlayer(itr->first))
            if (player->HasAura(48018))
                player->RemoveAurasDueToSpell(48018);
}

void BattlegroundDS::AddPlayer(Player* player)
{
    Battleground::AddPlayer(player);
    PlayerScores[player->GetGUID()] = new BattlegroundScore;
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
        TC_LOG_ERROR("bg.battleground", "BattlegroundDS: Killer player not found");
        return;
    }

    Battleground::HandleKillPlayer(player, killer);

    UpdateArenaWorldState();
    CheckArenaWinConditions();
}

void BattlegroundDS::HandleAreaTrigger(Player* player, uint32 trigger)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    switch (trigger)
    {
        case 5347:
        case 5348:
            // Remove effects of Demonic Circle Summon
            if (player->HasAura(48018))
                player->RemoveAurasDueToSpell(48018);

            // Someone has get back into the pipes and the knockback has already been performed,
            // so we reset the knockback count for kicking the player again into the arena.
            if (getPipeKnockBackCount() >= BG_DS_PIPE_KNOCKBACK_TOTAL_COUNT)
                setPipeKnockBackCount(0);
            break;
        default:
            Battleground::HandleAreaTrigger(player, trigger);
            break;
    }
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
        || !AddObject(BG_DS_OBJECT_BUFF_2, BG_DS_OBJECT_TYPE_BUFF_2, 1291.7f, 768.911f, 7.11472f, 1.55194f, 0, 0, 0.700409f, 0.713742f, 120)
        // knockback creatures
        || !AddCreature(BG_DS_NPC_TYPE_WATER_SPOUT, BG_DS_NPC_WATERFALL_KNOCKBACK, 1292.587f, 790.2205f, 7.19796f, 3.054326f, TEAM_NEUTRAL, RESPAWN_IMMEDIATELY)
        || !AddCreature(BG_DS_NPC_TYPE_WATER_SPOUT, BG_DS_NPC_PIPE_KNOCKBACK_1, 1369.977f, 817.2882f, 16.08718f, 3.106686f, TEAM_NEUTRAL, RESPAWN_IMMEDIATELY)
        || !AddCreature(BG_DS_NPC_TYPE_WATER_SPOUT, BG_DS_NPC_PIPE_KNOCKBACK_2, 1212.833f, 765.3871f, 16.09484f, 0.0f, TEAM_NEUTRAL, RESPAWN_IMMEDIATELY))
    {
        TC_LOG_ERROR("sql.sql", "BatteGroundDS: Failed to spawn some object!");
        return false;
    }

    return true;
}
