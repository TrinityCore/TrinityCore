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

/* Blade Dance implementation requires recheck. Apparently SPELL_BLADE_DANCE_CHARGE can miss, as result handling half of Blade Dance sequence
 in SpellHitTarget will stop sequence */

#include "ScriptMgr.h"
#include "Containers.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
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
    SPELL_BLADE_DANCE              = 30739,
    SPELL_BLADE_DANCE_CHARGE       = 30751,
    SPELL_CHARGE_H                 = 25821,

    // Warchief's Portal
    SPELL_SUMMON_HEATHEN           = 30737,
    SPELL_SUMMON_REAVER            = 30785,
    SPELL_SUMMON_SHARPSHOOTER      = 30786
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
        _bladeDanceTargets.clear();
        _bladeDanceTargetGUID.Clear();
        _bladeDanceCount = 0;
    }

    void JustEngagedWith(Unit* who) override
    {
        Talk(SAY_AGGRO);
        BossAI::JustEngagedWith(who);
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

    void SpellHitTarget(WorldObject* target, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_BLADE_DANCE_TARGETING)
            _bladeDanceTargets.push_back(target->GetGUID());
    }

    void JustSummoned(Creature* summon) override
    {
        if (summon->GetEntry() == NPC_SHATTERED_ASSASSIN)
            summon->GetMotionMaster()->MoveRandom(5.0f);

        // Allow despawn but do not engage all summons (assassins shouldn't be engaged)
        summons.Summon(summon);
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
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
                {
                    if (_bladeDanceCount < MAX_BLADE_DANCE_COUNT)
                    {
                        _bladeDanceTargets.clear();

                        DoCastSelf(SPELL_BLADE_DANCE_TARGETING);

                        if (!_bladeDanceTargets.empty())
                        {
                            _bladeDanceTargetGUID.Clear();

                            _bladeDanceTargetGUID = Trinity::Containers::SelectRandomContainerElement(_bladeDanceTargets);

                            Creature* target = ObjectAccessor::GetCreature(*me, _bladeDanceTargetGUID);
                            if (target)
                                DoCast(target, SPELL_BLADE_DANCE_CHARGE);

                            DoCastSelf(SPELL_BLADE_DANCE);
                        }

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
                }
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
    GuidList _bladeDanceTargets;
    ObjectGuid _bladeDanceTargetGUID;
    uint8 _bladeDanceCount;
};

// 17611 - Warchief's Portal
struct npc_warchiefs_portal : public ScriptedAI
{
    npc_warchiefs_portal(Creature* creature) : ScriptedAI(creature), _summonCount(0), _instance(creature->GetInstanceScript()) { }

    void JustAppeared() override
    {
        _summonCount = 1;

        _scheduler.Schedule(20s, [this](TaskContext task)
        {
            switch (_summonCount)
            {
                // In this exact order and repeat again
                case 1: DoCastSelf(SPELL_SUMMON_HEATHEN); break;
                case 2: DoCastSelf(SPELL_SUMMON_REAVER); break;
                case 3: DoCastSelf(SPELL_SUMMON_SHARPSHOOTER); break;
                default: break;
            }

            if (_summonCount >= 3)
                _summonCount = 1;
            else
                ++_summonCount;

            task.Repeat(20s);
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
    uint8 _summonCount;
    TaskScheduler _scheduler;
    InstanceScript* _instance;
};

void AddSC_boss_warchief_kargath_bladefist()
{
    RegisterShatteredHallsCreatureAI(boss_warchief_kargath_bladefist);
    RegisterShatteredHallsCreatureAI(npc_warchiefs_portal);
}
