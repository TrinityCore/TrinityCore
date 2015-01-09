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

#include "Battleground.h"
#include "BattlegroundDS.h"
#include "Creature.h"
#include "GameObject.h"
#include "Player.h"
#include "WorldPacket.h"

void BattlegroundDS::InitializeObjects()
{
    ObjectGUIDsByType.resize(BG_DS_OBJECT_MAX);
    BgCreatures.resize(BG_DS_NPC_MAX);
    m_StartDelayTimes[BG_STARTING_EVENT_FIRST]  = BG_START_DELAY_1M;
    m_StartDelayTimes[BG_STARTING_EVENT_SECOND] = BG_START_DELAY_30S;
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;
}
    while (uint32 eventId = _events.ExecuteEvent())
        if (GetStartTime() >= 47*MINUTE*IN_MILLISECONDS)    // after 47 minutes without one team losing, the arena closes with no winner and no rating change
                DoorClose(BG_DS_OBJECT_WATER_2);
                _events.ScheduleEvent(BG_DS_EVENT_WATERFALL_ON, BG_DS_WATERFALL_WARNING_DURATION);
                break;
            case BG_DS_EVENT_WATERFALL_ON:
                // Active collision and start knockback timer
                DoorClose(BG_DS_OBJECT_WATER_1);
                _events.ScheduleEvent(BG_DS_EVENT_WATERFALL_OFF, BG_DS_WATERFALL_DURATION);
                _events.ScheduleEvent(BG_DS_EVENT_WATERFALL_KNOCKBACK, BG_DS_WATERFALL_KNOCKBACK_TIMER);
                break;
            case BG_DS_EVENT_WATERFALL_OFF:
                // Remove collision and water
                DoorOpen(BG_DS_OBJECT_WATER_1);
                DoorOpen(BG_DS_OBJECT_WATER_2);
                _events.CancelEvent(BG_DS_EVENT_WATERFALL_KNOCKBACK);
                _events.ScheduleEvent(BG_DS_EVENT_WATERFALL_WARNING, urand(BG_DS_WATERFALL_TIMER_MIN, BG_DS_WATERFALL_TIMER_MAX));
                break;
            case BG_DS_EVENT_WATERFALL_KNOCKBACK:
                // Repeat knockback while the waterfall still active
                if (Creature* waterSpout = GetBGCreature(BG_DS_NPC_WATERFALL_KNOCKBACK))
                    waterSpout->CastSpell(waterSpout, BG_DS_SPELL_WATER_SPOUT, true);
                _events.ScheduleEvent(eventId, BG_DS_WATERFALL_KNOCKBACK_TIMER);
                break;
            case BG_DS_EVENT_PIPE_KNOCKBACK:
                for (uint32 i = BG_DS_NPC_PIPE_KNOCKBACK_1; i <= BG_DS_NPC_PIPE_KNOCKBACK_2; ++i)
                    if (Creature* waterSpout = GetBGCreature(i))
                        waterSpout->CastSpell(waterSpout, BG_DS_SPELL_FLUSH, true);
                break;

    // gates
    AddGameObject(BG_DS_OBJECT_DOOR_1, BG_DS_OBJECT_TYPE_DOOR_1, 1350.95f, 817.2f, 20.8096f, 3.15f, 0, 0, 0.99627f, 0.0862864f, RESPAWN_IMMEDIATELY);
    AddGameObject(BG_DS_OBJECT_DOOR_2, BG_DS_OBJECT_TYPE_DOOR_2, 1232.65f, 764.913f, 20.0729f, 6.3f, 0, 0, 0.0310211f, -0.999519f, RESPAWN_IMMEDIATELY);
    // water
            for (uint32 i = BG_DS_NPC_PIPE_KNOCKBACK_1; i <= BG_DS_NPC_PIPE_KNOCKBACK_2; ++i)
                if (Creature* waterSpout = GetBGCreature(i))
                    waterSpout->CastSpell(waterSpout, BG_DS_SPELL_FLUSH, true);

            ++_pipeKnockBackCount;
            _pipeKnockBackTimer = BG_DS_PIPE_KNOCKBACK_DELAY;

    for (uint32 i = BG_DS_OBJECT_DOOR_1; i <= BG_DS_OBJECT_DOOR_2; ++i)
        SpawnGameObject(i, RESPAWN_IMMEDIATELY);
}

void BattlegroundDS::StartBattleground()
{
    for (uint32 i = BG_DS_OBJECT_DOOR_1; i <= BG_DS_OBJECT_DOOR_2; ++i)
        DoorOpen(i);

    for (uint32 i = BG_DS_OBJECT_BUFF_1; i <= BG_DS_OBJECT_BUFF_2; ++i)
        SpawnGameObject(i, 60);

    setWaterFallTimer(urand(BG_DS_WATERFALL_TIMER_MIN, BG_DS_WATERFALL_TIMER_MAX));
    setWaterFallActive(false);
    //    _events.ScheduleEvent(BG_DS_EVENT_PIPE_KNOCKBACK, BG_DS_PIPE_KNOCKBACK_FIRST_DELAY + i * BG_DS_PIPE_KNOCKBACK_DELAY);
        SpawnGameObject(i, GetWaterFallTimer());
    Battleground::AddPlayer(plr);
void BattlegroundDS::RemovePlayer(Player* /*plr*/, uint64 /*guid*/, uint32 /*team*/)
        if (IsWaterFallActive())
        {
            SetWaterFallTimer(urand(BG_DS_WATERFALL_TIMER_MIN, BG_DS_WATERFALL_TIMER_MAX));
            for (uint32 i = BG_DS_OBJECT_WATER_1; i <= BG_DS_OBJECT_WATER_2; ++i)
                SpawnGameObject(i, GetWaterFallTimer());
    UpdateArenaWorldState();
}
        else
void BattlegroundDS::HandleKillPlayer(Player* player, Player* killer)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;
                SpawnGameObject(i, RESPAWN_IMMEDIATELY);

            SetWaterFallActive(true);
    }
    else
        SetWaterFallTimer(GetWaterFallTimer() - diff);
    UpdateArenaWorldState();
    CheckArenaWinConditions();
        if (Player* player = _GetPlayer(itr, "BattlegroundDS::StartingEventOpenDoors"))
            player->RemoveAurasDueToSpell(SPELL_WARL_DEMONIC_CIRCLE);
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
            player->RemoveAurasDueToSpell(SPELL_WARL_DEMONIC_CIRCLE);

            // Someone has get back into the pipes and the knockback has already been performed,
            // so we reset the knockback count for kicking the player again into the arena.
            if (_pipeKnockBackCount >= BG_DS_PIPE_KNOCKBACK_TOTAL_COUNT)
                _pipeKnockBackCount = 0;
            break;
        default:
            Battleground::HandleAreaTrigger(player, trigger);
            break;
    }
}

    player->TeleportTo(GetId(), 1299.046f, 784.825f, 9.338f, 2.422f, false);
void BattlegroundDS::FillInitialWorldStates(WorldPacket& data)
{
    data << uint32(3610) << uint32(1);      // 9 show
    Arena::FillInitialWorldStates(data);
        // knockback creatures
        || !AddCreature(BG_DS_NPC_TYPE_WATER_SPOUT, BG_DS_NPC_WATERFALL_KNOCKBACK, 1292.587f, 790.2205f, 7.19796f, 3.054326f, TEAM_NEUTRAL, RESPAWN_IMMEDIATELY)
        || !AddCreature(BG_DS_NPC_TYPE_WATER_SPOUT, BG_DS_NPC_PIPE_KNOCKBACK_1, 1369.977f, 817.2882f, 16.08718f, 3.106686f, TEAM_NEUTRAL, RESPAWN_IMMEDIATELY)
        || !AddCreature(BG_DS_NPC_TYPE_WATER_SPOUT, BG_DS_NPC_PIPE_KNOCKBACK_2, 1212.833f, 765.3871f, 16.09484f, 0.0f, TEAM_NEUTRAL, RESPAWN_IMMEDIATELY))
        TC_LOG_ERROR("sql.sql", "BatteGroundDS: Failed to spawn some object!");
}
