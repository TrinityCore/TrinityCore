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

/*
 * Blade Dance implementation requires additional research
 * Timers requires to be revisited
 */

#include "ScriptMgr.h"
#include "Containers.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "shattered_halls.h"

enum KargathTexts
{
    SAY_AGGRO                      = 0,
    SAY_SLAY                       = 1,
    SAY_DEATH                      = 2,

    SAY_CALL_EXECUTIONER_A         = 3,
    SAY_CALL_EXECUTIONER_H         = 4,

    SAY_LEASH                      = 5
};

enum KargathSpells
{
    // Kargath
    SPELL_BLADE_DANCE_TARGETING    = 30738,
    SPELL_CHARGE_H                 = 25821,

    // Warchief's Portal
    SPELL_SUMMON_HEATHEN           = 30737,
    SPELL_SUMMON_REAVER            = 30785,
    SPELL_SUMMON_SHARPSHOOTER      = 30786,

    // Scripts
    SPELL_BLADE_DANCE              = 30739,
    SPELL_BLADE_DANCE_CHARGE       = 30751
};

enum KargathEvents
{
    EVENT_BLADE_DANCE              = 1,
    EVENT_CHARGE_H,
    EVENT_SUMMON_PORTAL,
    EVENT_SUMMON_ASSASSINS,
    EVENT_LEASH
};

enum KargathMisc
{
    NPC_SHATTERED_ASSASSIN         = 17695,
    MAX_BLADE_DANCE_COUNT          = 8,
    SUMMON_GROUP_PORTAL            = 0,
    SUMMON_GROUP_ASSASSINS         = 1
};

// 16808 - Warchief Kargath Bladefist
struct boss_warchief_kargath_bladefist : public BossAI
{
    boss_warchief_kargath_bladefist(Creature* creature) : BossAI(creature, DATA_KARGATH), _bladeDanceCount(0) { }

    void Reset() override
    {
        _Reset();
        _bladeDanceCount = 0;
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        Talk(SAY_AGGRO);

        events.ScheduleEvent(EVENT_BLADE_DANCE, 30s, 35s);
        events.ScheduleEvent(EVENT_SUMMON_PORTAL, 1s);
        events.ScheduleEvent(EVENT_SUMMON_ASSASSINS, 3s);
        events.ScheduleEvent(EVENT_LEASH, 1s);
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_EXECUTIONER_TAUNT)
        {
            switch (instance->GetData(DATA_TEAM_IN_INSTANCE))
            {
                case ALLIANCE:
                    Talk(SAY_CALL_EXECUTIONER_A);
                    break;
                case HORDE:
                    Talk(SAY_CALL_EXECUTIONER_H);
                    break;
                default:
                    break;
            }
        }
    }

    void JustSummoned(Creature* summon) override
    {
        if (summon->GetEntry() == NPC_SHATTERED_ASSASSIN)
            summon->GetMotionMaster()->MoveRandom(5.0f);

        // Allow despawn but do not engage all summons (assassins shouldn't be engaged)
        summons.Summon(summon);
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_BLADE_DANCE:
                    if (_bladeDanceCount < MAX_BLADE_DANCE_COUNT)
                    {
                        DoCastSelf(SPELL_BLADE_DANCE_TARGETING);
                        events.ScheduleEvent(EVENT_BLADE_DANCE, 500ms);
                        ++_bladeDanceCount;
                    }
                    else
                    {
                        if (IsHeroic())
                            events.ScheduleEvent(EVENT_CHARGE_H, 500ms);
                        events.ScheduleEvent(EVENT_BLADE_DANCE, 45s, 50s);
                        _bladeDanceCount = 0;
                    }
                    break;
                case EVENT_CHARGE_H:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, SPELL_CHARGE_H);
                    break;
                case EVENT_SUMMON_PORTAL:
                    me->SummonCreatureGroup(SUMMON_GROUP_PORTAL);
                    break;
                case EVENT_SUMMON_ASSASSINS:
                    me->SummonCreatureGroup(SUMMON_GROUP_ASSASSINS);
                    break;
                case EVENT_LEASH:
                    // He CAN evade during Blade Dance on retail, however with this distance he will not
                    if (me->GetDistance(me->GetHomePosition()) > 40.0f)
                    {
                        Talk(SAY_LEASH);
                        EnterEvadeMode(EVADE_REASON_BOUNDARY);
                    }
                    events.Repeat(1s);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    uint8 _bladeDanceCount;
};

// 17611 - Warchief's Portal
struct npc_warchiefs_portal : public ScriptedAI
{
    npc_warchiefs_portal(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void JustAppeared() override
    {
        _scheduler
            .Schedule(20s, [this](TaskContext task)
            {
                DoCastSelf(SPELL_SUMMON_HEATHEN);
                task.Repeat(60s);
            })
            .Schedule(40s, [this](TaskContext task)
            {
                DoCastSelf(SPELL_SUMMON_REAVER);
                task.Repeat(60s);
            })
            .Schedule(60s, [this](TaskContext task)
            {
                DoCastSelf(SPELL_SUMMON_SHARPSHOOTER);
                task.Repeat(60s);
            });
    }

    void JustSummoned(Creature* summon) override
    {
        // Not correct to despawn them after encounter is finished, originally they become passive and start path and despawn on reaching last waypoint
        if (Creature* kargath = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(NPC_KARGATH_BLADEFIST)))
            kargath->AI()->JustSummoned(summon);
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
    InstanceScript* _instance;
};

// 30738 - Blade Dance Targeting
class spell_kargath_blade_dance_targeting : public SpellScript
{
    PrepareSpellScript(spell_kargath_blade_dance_targeting);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BLADE_DANCE_CHARGE, SPELL_BLADE_DANCE });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        WorldObject* target = Trinity::Containers::SelectRandomContainerElement(targets);

        _selectedTargetGuid = target->GetGUID();
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();

        if (target->GetGUID() == _selectedTargetGuid)
        {
            caster->CastSpell(target, SPELL_BLADE_DANCE_CHARGE);
            caster->CastSpell(nullptr, SPELL_BLADE_DANCE);
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_kargath_blade_dance_targeting::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        OnEffectHitTarget += SpellEffectFn(spell_kargath_blade_dance_targeting::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }

private:
    ObjectGuid _selectedTargetGuid;
};

void AddSC_boss_warchief_kargath_bladefist()
{
    RegisterShatteredHallsCreatureAI(boss_warchief_kargath_bladefist);
    RegisterShatteredHallsCreatureAI(npc_warchiefs_portal);
    RegisterSpellScript(spell_kargath_blade_dance_targeting);
}
