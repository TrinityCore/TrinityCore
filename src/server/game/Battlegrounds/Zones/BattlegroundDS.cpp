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

#include "BattlegroundDS.h"
#include "Creature.h"
#include "Player.h"
#include "WorldPacket.h"

BattlegroundSpawnPoint const BG_DS_Creatures[BG_DS_NPC_MAX] =
{
    { BG_DS_NPC_TYPE_WATER_SPOUT, { 1292.587f, 790.2205f, 7.197960f, 3.054326f }, RESPAWN_IMMEDIATELY },
    { BG_DS_NPC_TYPE_WATER_SPOUT, { 1369.977f, 817.2882f, 16.08718f, 3.106686f }, RESPAWN_IMMEDIATELY },
    { BG_DS_NPC_TYPE_WATER_SPOUT, { 1212.833f, 765.3871f, 16.09484f, 0.000000f }, RESPAWN_IMMEDIATELY }
};

BattlegroundGOSpawnPoint const BG_DS_GameObjects[BG_DS_OBJECT_MAX] =
{
    { BG_DS_OBJECT_TYPE_DOOR_1,  { 1350.95f, 817.200f, 20.8096f, 3.15000f }, { 0.f, 0.f, 0.9962700f,  0.0862864f }, RESPAWN_IMMEDIATELY },
    { BG_DS_OBJECT_TYPE_DOOR_2,  { 1232.65f, 764.913f, 20.0729f, 6.30000f }, { 0.f, 0.f, 0.0310211f, -0.9995190f }, RESPAWN_IMMEDIATELY },
    { BG_DS_OBJECT_TYPE_WATER_1, { 1291.56f, 790.837f, 7.10000f, 3.14238f }, { 0.f, 0.f, 0.6942150f, -0.7197680f }, 2 * MINUTE          },
    { BG_DS_OBJECT_TYPE_WATER_2, { 1291.56f, 790.837f, 7.10000f, 3.14238f }, { 0.f, 0.f, 0.6942150f, -0.7197680f }, 2 * MINUTE          },
    { BG_DS_OBJECT_TYPE_BUFF_1,  { 1291.70f, 813.424f, 7.11472f, 4.64562f }, { 0.f, 0.f, 0.7303140f, -0.6831110f }, 2 * MINUTE          },
    { BG_DS_OBJECT_TYPE_BUFF_2,  { 1291.70f, 768.911f, 7.11472f, 1.55194f }, { 0.f, 0.f, 0.7004090f,  0.7137420f }, 2 * MINUTE          }
};

BattlegroundDS::BattlegroundDS()
{
    SetGameObjectsNumber(BG_DS_OBJECT_MAX);
    SetCreaturesNumber(BG_DS_NPC_MAX);

    _pipeKnockBackTimer = 0;
    _pipeKnockBackCount = 0;
}

void BattlegroundDS::PostUpdateImpl(uint32 diff)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    _events.Update(diff);

    while (uint32 eventId = _events.ExecuteEvent())
    {
        switch (eventId)
        {
            case BG_DS_EVENT_WATERFALL_WARNING:
                // Add the water
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
        }
    }

    if (_pipeKnockBackCount < BG_DS_PIPE_KNOCKBACK_TOTAL_COUNT)
    {
        if (_pipeKnockBackTimer < diff)
        {
            for (uint32 i = BG_DS_NPC_PIPE_KNOCKBACK_1; i <= BG_DS_NPC_PIPE_KNOCKBACK_2; ++i)
                if (Creature* waterSpout = GetBGCreature(i))
                    waterSpout->CastSpell(waterSpout, BG_DS_SPELL_FLUSH, true);

            ++_pipeKnockBackCount;
            _pipeKnockBackTimer = BG_DS_PIPE_KNOCKBACK_DELAY;
        }
        else
            _pipeKnockBackTimer -= diff;
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

    _events.ScheduleEvent(BG_DS_EVENT_WATERFALL_WARNING, urand(BG_DS_WATERFALL_TIMER_MIN, BG_DS_WATERFALL_TIMER_MAX));
    //for (uint8 i = 0; i < BG_DS_PIPE_KNOCKBACK_TOTAL_COUNT; ++i)
    //    _events.ScheduleEvent(BG_DS_EVENT_PIPE_KNOCKBACK, BG_DS_PIPE_KNOCKBACK_FIRST_DELAY + i * BG_DS_PIPE_KNOCKBACK_DELAY);

    _pipeKnockBackCount = 0;
    _pipeKnockBackTimer = BG_DS_PIPE_KNOCKBACK_FIRST_DELAY;

    SpawnBGObject(BG_DS_OBJECT_WATER_2, RESPAWN_IMMEDIATELY);

    DoorOpen(BG_DS_OBJECT_WATER_1); // Turn off collision
    DoorOpen(BG_DS_OBJECT_WATER_2);

    // Remove effects of Demonic Circle Summon
    for (BattlegroundPlayerMap::const_iterator itr = GetPlayers().begin(); itr != GetPlayers().end(); ++itr)
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

void BattlegroundDS::FillInitialWorldStates(WorldPacket& data)
{
    data << uint32(3610) << uint32(1);      // 9 show
    Arena::FillInitialWorldStates(data);
}

bool BattlegroundDS::SetupBattleground()
{
    for (uint32 i = 0; i < BG_DS_NPC_MAX; ++i)
    {
        BattlegroundSpawnPoint const& creature = BG_DS_Creatures[i];
        if (!AddCreature(creature.Entry, i, creature.Pos, creature.SpawnTime))
        {
            TC_LOG_ERROR("bg.battleground", "BattleGroundDS: Failed to spawn Creature! (Entry: %u). Battleground not created!", creature.Entry);
            return false;
        }
    }

    for (uint32 i = 0; i < BG_DS_OBJECT_MAX; ++i)
    {
        BattlegroundGOSpawnPoint const& object = BG_DS_GameObjects[i];
        if (!AddObject(i, object.Entry, object.Pos, object.Rot, object.SpawnTime))
        {
            TC_LOG_ERROR("bg.battleground", "BattleGroundDS: Failed to spawn GameObject! (Entry: %u). Battleground not created!", object.Entry);
            return false;
        }
    }

    return true;
}
