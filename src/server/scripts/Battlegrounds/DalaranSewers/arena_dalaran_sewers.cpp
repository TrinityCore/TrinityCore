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
#include "SpellAuraEffects.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "TaskScheduler.h"

namespace DalaranSewers
{
    namespace Creatures
    {
        static constexpr uint32 WaterSpout = 28567;
    }

    namespace Events
    {
        static constexpr uint32 WaterfallWarning = 1;
        static constexpr uint32 WaterfallOn = 2;
        static constexpr uint32 WaterfallOff = 3;
        static constexpr uint32 WaterfallKnockBack = 4;
    }

    namespace GameObjects
    {
        static constexpr uint32 Door01 = 192642;
        static constexpr uint32 Door02 = 192643;

        static constexpr uint32 WaterCollision = 194395;
        static constexpr uint32 Waterfall = 191877;
    }

    namespace MapIds
    {
        static constexpr uint32 DalaranSewers = 617;
    }

    namespace Spells
    {
        static constexpr uint32 PipeFlushKnockbackSearchTrigger = 96539;
        static constexpr uint32 DalaranSewersPetTeleport = 254013;
        static constexpr uint32 WaterSpout = 58873; // Knock back
        static constexpr uint32 Flush = 57405;

        static constexpr uint32 WarlockDemonicCircle = 48018;
    }

    namespace StringIds
    {
        static constexpr std::string_view WaterSpoutPipe = "arena_dalaran_sewers_water_spout_pipe";
        static constexpr std::string_view WaterSpoutCenter = "arena_dalaran_sewers_water_spout_center";
    }

    namespace Timers
    {
        static constexpr Seconds Waterfall = 30s;
        static constexpr Seconds WaterfallWarningDuration = 5s;
        static constexpr Seconds WaterfallDuration = 30s;
        static constexpr Milliseconds WaterfallKnockBack = 1500ms;
    }
}

struct arena_dalaran_sewers : ArenaScript
{
    explicit arena_dalaran_sewers(BattlegroundMap* map) : ArenaScript(map) { }

    void OnUpdate(uint32 diff) override
    {
        ArenaScript::OnUpdate(diff);

        if (battleground->GetStatus() != STATUS_IN_PROGRESS)
            return;

        _events.Update(diff);
        _scheduler.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case DalaranSewers::Events::WaterfallWarning:
                    // Add the water
                    if (GameObject* go = battlegroundMap->GetGameObject(_waterfallGUID))
                        go->UseDoorOrButton();
                    _events.ScheduleEvent(DalaranSewers::Events::WaterfallOn, DalaranSewers::Timers::WaterfallWarningDuration);
                    break;
                case DalaranSewers::Events::WaterfallOn:
                    // Active collision and start knockback timer
                    if (GameObject* go = battlegroundMap->GetGameObject(_waterCollisionGUID))
                        go->UseDoorOrButton();
                    _events.ScheduleEvent(DalaranSewers::Events::WaterfallOff, DalaranSewers::Timers::WaterfallDuration);
                    _events.ScheduleEvent(DalaranSewers::Events::WaterfallKnockBack, DalaranSewers::Timers::WaterfallKnockBack);
                    break;
                case DalaranSewers::Events::WaterfallOff:
                    // Remove collision and water
                    if (GameObject* go = battlegroundMap->GetGameObject(_waterCollisionGUID))
                        go->ResetDoorOrButton();
                    if (GameObject* go = battlegroundMap->GetGameObject(_waterfallGUID))
                        go->ResetDoorOrButton();
                    _events.CancelEvent(DalaranSewers::Events::WaterfallKnockBack);
                    _events.ScheduleEvent(DalaranSewers::Events::WaterfallWarning, DalaranSewers::Timers::Waterfall);
                    break;
                case DalaranSewers::Events::WaterfallKnockBack:
                    // Repeat knock back while the waterfall still active
                    if (Creature* waterSpout = battlegroundMap->GetCreature(_waterSpoutCenterGUID))
                        waterSpout->CastSpell(waterSpout, DalaranSewers::Spells::WaterSpout, true);
                    _events.ScheduleEvent(eventId, DalaranSewers::Timers::WaterfallKnockBack);
                    break;
                default:
                    break;
            }
        }
    }

    void OnStart() override
    {
        ArenaScript::OnStart();

        for (ObjectGuid const& guid : _doorGUIDs)
        {
            if (GameObject* door = battlegroundMap->GetGameObject(guid))
            {
                door->UseDoorOrButton();
                door->DespawnOrUnsummon(5s);
            }
        }

        _events.ScheduleEvent(DalaranSewers::Events::WaterfallWarning, DalaranSewers::Timers::Waterfall);

        // Remove collision and water
        if (GameObject* go = battlegroundMap->GetGameObject(_waterCollisionGUID))
            go->ResetDoorOrButton();
        if (GameObject* go = battlegroundMap->GetGameObject(_waterfallGUID))
            go->ResetDoorOrButton();

        for (const auto& [playerGuid, _] : battleground->GetPlayers())
            if (Player* player = ObjectAccessor::FindPlayer(playerGuid))
                player->RemoveAurasDueToSpell(DalaranSewers::Spells::WarlockDemonicCircle);

        _scheduler.Schedule(6s, [&](TaskContext)
        {
            for (ObjectGuid const& guid : _waterSpoutEntranceGUIDs)
            {
                if (Creature* creature = battlegroundMap->GetCreature(guid))
                {
                    creature->CastSpell(nullptr, DalaranSewers::Spells::Flush, CastSpellExtraArgsInit{
                        .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR
                    });
                    creature->CastSpell(creature, DalaranSewers::Spells::PipeFlushKnockbackSearchTrigger, CastSpellExtraArgsInit{
                        .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR
                    });
                }
            }
        });
    }

    void OnCreatureCreate(Creature* creature) override
    {
        switch (creature->GetEntry())
        {
            case DalaranSewers::Creatures::WaterSpout:
                if (creature->HasStringId(DalaranSewers::StringIds::WaterSpoutPipe))
                    _waterSpoutEntranceGUIDs.push_back(creature->GetGUID());
                else if (creature->HasStringId(DalaranSewers::StringIds::WaterSpoutCenter))
                    _waterSpoutCenterGUID = creature->GetGUID();
                break;
            default:
                break;
        }
    }

    void OnGameObjectCreate(GameObject* gameobject) override
    {
        switch (gameobject->GetEntry())
        {
            case DalaranSewers::GameObjects::Door01:
            case DalaranSewers::GameObjects::Door02:
                _doorGUIDs.push_back(gameobject->GetGUID());
                break;
            case DalaranSewers::GameObjects::WaterCollision:
                _waterCollisionGUID = gameobject->GetGUID();
                break;
            case DalaranSewers::GameObjects::Waterfall:
                _waterfallGUID = gameobject->GetGUID();
                break;
            default:
                break;
        }
    }

private:
    GuidVector _doorGUIDs;
    ObjectGuid _waterCollisionGUID;
    ObjectGuid _waterfallGUID;
    EventMap _events;

    GuidVector _waterSpoutEntranceGUIDs;
    ObjectGuid _waterSpoutCenterGUID;

    TaskScheduler _scheduler;
};

class at_ds_pipe_knockback : public AreaTriggerScript
{
public:
    at_ds_pipe_knockback() : AreaTriggerScript("at_ds_pipe_knockback") { }

    static void Trigger(Player* player)
    {
        if (Battleground const* battleground = player->GetBattleground())
        {
            if (battleground->GetStatus() != STATUS_IN_PROGRESS)
                return;

            // Remove effects of Demonic Circle Summon
            player->RemoveAurasDueToSpell(DalaranSewers::Spells::WarlockDemonicCircle);
            player->CastSpell(nullptr, DalaranSewers::Spells::DalaranSewersPetTeleport);
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

// 96538 - Pipe Flush Knockback Search Effect
class spell_arena_dalaran_sewers_pipe_flush_knockback_search_trigger : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({
            static_cast<uint32>(spellInfo->GetEffect(EFFECT_0).CalcValue())
        });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(nullptr, GetSpellInfo()->GetEffect(EFFECT_0).CalcValue(), CastSpellExtraArgsInit
        {
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR
        });
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_arena_dalaran_sewers_pipe_flush_knockback_search_trigger::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 61698 - Flush - Knockback effect (SERVERSIDE)
class spell_arena_dalaran_sewers_flush_knock_back_effect : public SpellScript
{
    void HandleDummy(SpellEffIndex /*effIndex*/) const
    {
        static constexpr float SpeedXY = 30.0f;
        static constexpr float SpeedZ = 19.0f;

        Unit* caster = GetCaster();
        Unit const* target = GetHitUnit();
        caster->KnockbackFrom(target->GetPosition(), SpeedXY, SpeedZ);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_arena_dalaran_sewers_flush_knock_back_effect::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

void AddSC_arena_dalaran_sewers()
{
    RegisterBattlegroundMapScript(arena_dalaran_sewers, DalaranSewers::MapIds::DalaranSewers);
    new at_ds_pipe_knockback();
    RegisterSpellScript(spell_arena_dalaran_sewers_flush_knock_back_effect);
}
