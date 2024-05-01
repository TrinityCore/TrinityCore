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

#include "Battleground.h"
#include "BattlegroundScript.h"
#include "Creature.h"
#include "Duration.h"
#include "EventMap.h"
#include "GameObject.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "TaskScheduler.h"

struct arena_dalaran_sewers : ArenaScript
{
    enum GameObjects
    {
        BG_DS_OBJECT_TYPE_DOOR_1        = 192642,
        BG_DS_OBJECT_TYPE_DOOR_2        = 192643,
        BG_DS_OBJECT_TYPE_WATER_1       = 194395, // Collision
        BG_DS_OBJECT_TYPE_WATER_2       = 191877,
        BG_DS_OBJECT_TYPE_BUFF_1        = 184663,
        BG_DS_OBJECT_TYPE_BUFF_2        = 184664
    };

    enum Events
    {
        BG_DS_EVENT_WATERFALL_WARNING   = 1, // Water starting to fall, but no LoS Blocking nor movement blocking
        BG_DS_EVENT_WATERFALL_ON        = 2, // LoS and Movement blocking active
        BG_DS_EVENT_WATERFALL_OFF       = 3,
        BG_DS_EVENT_WATERFALL_KNOCKBACK = 4,

        BG_DS_EVENT_PIPE_KNOCKBACK      = 5
    };

    enum Creatures
    {
        BG_DS_NPC_TYPE_WATER_SPOUT      = 28567
    };

    enum Spells
    {
        BG_DS_SPELL_FLUSH               = 57405, // Visual and target selector for the starting knockback from the pipe
        BG_DS_SPELL_FLUSH_KNOCKBACK     = 61698, // Knockback effect for previous spell (triggered, not needed to be cast)
        BG_DS_SPELL_WATER_SPOUT         = 58873, // Knockback effect of the central waterfall

        SPELL_WARL_DEMONIC_CIRCLE       = 48018  // Demonic Circle Summon
    };

    enum Data
    {
        // These values are NOT blizzlike... need the correct data!
        BG_DS_PIPE_KNOCKBACK_FIRST_DELAY    = 5000,
        BG_DS_PIPE_KNOCKBACK_DELAY          = 3000
    };

    // These values are NOT blizzlike... need the correct data!
    static constexpr Seconds BG_DS_WATERFALL_TIMER_MIN = 30s;
    static constexpr Seconds BG_DS_WATERFALL_TIMER_MAX = 60s;
    static constexpr Seconds BG_DS_WATERFALL_WARNING_DURATION = 5s;
    static constexpr Seconds BG_DS_WATERFALL_DURATION = 30s;
    static constexpr Milliseconds BG_DS_WATERFALL_KNOCKBACK_TIMER = 1500ms;
    static constexpr uint32 BG_DS_DATA_PIPE_KNOCKBACK_COUNT = 1;
    static constexpr uint32 BG_DS_PIPE_KNOCKBACK_TOTAL_COUNT = 2;

    explicit arena_dalaran_sewers(BattlegroundMap* map) : ArenaScript(map), _pipeKnockBackTimer(BG_DS_PIPE_KNOCKBACK_FIRST_DELAY), _pipeKnockBackCount(0) { }

    void OnUpdate(uint32 diff) override
    {
        if (battleground->GetStatus() != STATUS_IN_PROGRESS)
            return;

        _events.Update(diff);
        _scheduler.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case BG_DS_EVENT_WATERFALL_WARNING:
                    // Add the water
                    if (GameObject* go = battlegroundMap->GetGameObject(_water2GUID))
                        go->ResetDoorOrButton();
                    _events.ScheduleEvent(BG_DS_EVENT_WATERFALL_ON, BG_DS_WATERFALL_WARNING_DURATION);
                    break;
                case BG_DS_EVENT_WATERFALL_ON:
                    // Active collision and start knockback timer
                    if (GameObject* go = battlegroundMap->GetGameObject(_water1GUID))
                        go->ResetDoorOrButton();
                    _events.ScheduleEvent(BG_DS_EVENT_WATERFALL_OFF, BG_DS_WATERFALL_DURATION);
                    _events.ScheduleEvent(BG_DS_EVENT_WATERFALL_KNOCKBACK, BG_DS_WATERFALL_KNOCKBACK_TIMER);
                    break;
                case BG_DS_EVENT_WATERFALL_OFF:
                    // Remove collision and water
                    if (GameObject* go = battlegroundMap->GetGameObject(_water1GUID))
                        go->UseDoorOrButton();
                    if (GameObject* go = battlegroundMap->GetGameObject(_water2GUID))
                        go->UseDoorOrButton();
                    _events.CancelEvent(BG_DS_EVENT_WATERFALL_KNOCKBACK);
                    _events.ScheduleEvent(BG_DS_EVENT_WATERFALL_WARNING, BG_DS_WATERFALL_TIMER_MIN, BG_DS_WATERFALL_TIMER_MAX);
                    break;
                case BG_DS_EVENT_WATERFALL_KNOCKBACK:
                    // Repeat knockback while the waterfall still active
                    if (Creature* waterSpout = battlegroundMap->GetCreature(_waterfallCreatureGUID))
                        waterSpout->CastSpell(waterSpout, BG_DS_SPELL_WATER_SPOUT, true);
                    _events.ScheduleEvent(eventId, BG_DS_WATERFALL_KNOCKBACK_TIMER);
                    break;
                case BG_DS_EVENT_PIPE_KNOCKBACK:
                    for (ObjectGuid const& guid : _pipeCreatureGUIDs)
                        if (Creature* waterSpout = battlegroundMap->GetCreature(guid))
                            waterSpout->CastSpell(waterSpout, BG_DS_SPELL_FLUSH, true);
                    break;
                default:
                    break;
            }
        }

        if (_pipeKnockBackCount < BG_DS_PIPE_KNOCKBACK_TOTAL_COUNT)
        {
            if (_pipeKnockBackTimer < diff)
            {
                for (ObjectGuid const& guid : _pipeCreatureGUIDs)
                    if (Creature* waterSpout = battlegroundMap->GetCreature(guid))
                        waterSpout->CastSpell(waterSpout, BG_DS_SPELL_FLUSH, true);

                ++_pipeKnockBackCount;
                _pipeKnockBackTimer = BG_DS_PIPE_KNOCKBACK_DELAY;
            }
            else
                _pipeKnockBackTimer -= diff;
        }

    }

    void OnInit() override
    {
        AddObject(BG_DS_OBJECT_TYPE_DOOR_1, 1350.95f, 817.2f, 20.8096f, 3.15f, 0, 0, 0.99627f, 0.0862864f, GO_STATE_READY, _doorGUIDs);
        AddObject(BG_DS_OBJECT_TYPE_DOOR_2, 1232.65f, 764.913f, 20.0729f, 6.3f, 0, 0, 0.0310211f, -0.999519f, GO_STATE_READY, _doorGUIDs);

        if (GameObject const* go = CreateObject(BG_DS_OBJECT_TYPE_WATER_1, 1291.56f, 790.837f, 7.1f, 3.14238f, 0, 0, 0.694215f, -0.719768f, GO_STATE_READY))
            _water1GUID = go->GetGUID();

        if (GameObject const* go = CreateObject(BG_DS_OBJECT_TYPE_WATER_2, 1291.56f, 790.837f, 7.1f, 3.14238f, 0, 0, 0.694215f, -0.719768f, GO_STATE_READY))
            _water2GUID = go->GetGUID();
    }

    void OnStart() override
    {
        for (ObjectGuid const& guid : _doorGUIDs)
        {
            if (GameObject* door = battlegroundMap->GetGameObject(guid))
            {
                door->UseDoorOrButton();
                door->DespawnOrUnsummon(5s);
            }
        }

        _scheduler.Schedule(1min, [&](TaskContext)
        {
            CreateObject(BG_DS_OBJECT_TYPE_BUFF_1, 1291.7f, 813.424f, 7.11472f, 4.64562f, 0, 0, 0.730314f, -0.683111f);
            CreateObject(BG_DS_OBJECT_TYPE_BUFF_2, 1291.7f, 768.911f, 7.11472f, 1.55194f, 0, 0, 0.700409f, 0.713742f);
        });
        _events.ScheduleEvent(BG_DS_EVENT_WATERFALL_WARNING, BG_DS_WATERFALL_TIMER_MIN, BG_DS_WATERFALL_TIMER_MAX);
        _pipeKnockBackTimer = BG_DS_PIPE_KNOCKBACK_FIRST_DELAY;

        // Remove collision and water
        if (GameObject* go = battlegroundMap->GetGameObject(_water1GUID))
            go->UseDoorOrButton();
        if (GameObject* go = battlegroundMap->GetGameObject(_water2GUID))
            go->UseDoorOrButton();

        for (const auto& [playerGuid, _] : battleground->GetPlayers())
            if (Player* player = ObjectAccessor::FindPlayer(playerGuid))
                player->RemoveAurasDueToSpell(SPELL_WARL_DEMONIC_CIRCLE);
    }

    void AddObject(uint32 entry, float x, float y, float z, float o, float rotation0, float rotation1, float rotation2, float rotation3, GOState goState, GuidVector guidVector) const
    {
        if (GameObject const* go = CreateObject(entry, x, y, z, o, rotation0, rotation1, rotation2, rotation3, goState))
            guidVector.emplace_back(go->GetGUID());
    }

    void SetData(uint32 dataId, uint32 value) override
    {
        ArenaScript::SetData(dataId, value);
        if (dataId == BG_DS_DATA_PIPE_KNOCKBACK_COUNT)
            _pipeKnockBackCount = value;
    }

    uint32 GetData(uint32 dataId) const override
    {
        if (dataId == BG_DS_DATA_PIPE_KNOCKBACK_COUNT)
            return _pipeKnockBackCount;

        return ArenaScript::GetData(dataId);
    }

private:
    GuidVector _doorGUIDs;
    ObjectGuid _water1GUID;
    ObjectGuid _water2GUID;
    ObjectGuid _waterfallCreatureGUID;
    GuidVector _pipeCreatureGUIDs;
    TaskScheduler _scheduler;
    EventMap _events;

    uint32 _pipeKnockBackTimer;
    uint8 _pipeKnockBackCount;
};

class at_ds_pipe_knockback : public AreaTriggerScript
{
public:
    at_ds_pipe_knockback() : AreaTriggerScript("at_ds_pipe_knockback") { }

    void Trigger(Player* player) const
    {
        if (Battleground const* battleground = player->GetBattleground())
        {
            if (battleground->GetStatus() != STATUS_IN_PROGRESS)
                return;

            // Remove effects of Demonic Circle Summon
            player->RemoveAurasDueToSpell(arena_dalaran_sewers::SPELL_WARL_DEMONIC_CIRCLE);

            // Someone has get back into the pipes and the knockback has already been performed,
            // so we reset the knockback count for kicking the player again into the arena.
            if (battleground->GetBgMap()->GetBattlegroundScript()->GetData(arena_dalaran_sewers::BG_DS_DATA_PIPE_KNOCKBACK_COUNT) >= arena_dalaran_sewers::BG_DS_PIPE_KNOCKBACK_TOTAL_COUNT)
                battleground->GetBgMap()->GetBattlegroundScript()->SetData(arena_dalaran_sewers::BG_DS_DATA_PIPE_KNOCKBACK_COUNT, 0);
        }
    }

    bool OnTrigger(Player* player, AreaTriggerEntry const* /*trigger*/) override
    {
        Trigger(player);
        return true;
    }

    bool OnExit(Player* player, AreaTriggerEntry const* /*trigger*/) override
    {
        Trigger(player);
        return true;
    }
};

void AddSC_arena_dalaran_sewers()
{
    RegisterBattlegroundMapScript(arena_dalaran_sewers, 617);
    new at_ds_pipe_knockback();
}
