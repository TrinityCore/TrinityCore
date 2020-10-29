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

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ScriptedCreature.h"
#include "the_stockade.h"

enum Spells
{
    // Randolph Moloch
    SPELL_WILDLY_STABBING           = 86726,
    SPELL_SWEEP                     = 86729,
    SPELL_VANISH                    = 55964,
    SPELL_SHADOWSTEP                = 55966
};

enum Events
{
    // Randolph Moloch
    EVENT_WILDLY_STABBING = 1,
    EVENT_SWEEP,
    EVENT_VANISH,
    EVENT_JUST_VANISHED,
    EVENT_ATTACK_RANDOM,

    // Mortimer Moloch
    EVENT_MORTIMER_MOLOCH_EMOTE,
    EVENT_MORTIMER_MOLOCH_DEATH
};

enum Says
{
    // Randolph Moloch
    SAY_AGGRO           = 0,
    SAY_VANISH          = 1,
    SAY_DEATH           = 2,

    // Mortimer Moloch
    SAY_RANDOLPH_DIED   = 0,
    SAY_HEART_ATTACK    = 1
};

enum Points
{
    // Mortimer Moloch
    POINT_FINISH = 0
};

Position const MortimerMolochPos = { 145.5811f, 0.7059f, -25.606f, 6.2f };

struct boss_randolph_moloch : public BossAI
{
    boss_randolph_moloch(Creature* creature) : BossAI(creature, DATA_RANDOLPH_MOLOCH), _vanishCount(0) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
        events.ScheduleEvent(EVENT_WILDLY_STABBING, 4s, 5s);
        events.ScheduleEvent(EVENT_SWEEP, 2s, 3s);
    }

    void JustSummoned(Creature* summon) override
    {
        BossAI::JustSummoned(summon);
        if (summon->GetEntry() == NPC_MORTIMER_MOLOCH)
        {
            summon->SetWalk(true);
            summon->GetMotionMaster()->MovePoint(POINT_FINISH, me->GetPosition());
        }
    }

    void Reset() override
    {
        BossAI::Reset();
        _vanishCount = 0;
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_DEATH);
        _JustDied();
        if (instance->instance->GetTeamInInstance() == ALLIANCE)
            me->SummonCreature(NPC_MORTIMER_MOLOCH, MortimerMolochPos);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_WILDLY_STABBING:
                    DoCastVictim(SPELL_WILDLY_STABBING);
                    events.Repeat(8s, 12s);
                    break;
                case EVENT_SWEEP:
                    DoCastVictim(SPELL_SWEEP);
                    events.ScheduleEvent(EVENT_SWEEP, 6s, 7s);
                    break;
                case EVENT_VANISH:
                    Talk(SAY_VANISH);
                    me->RemoveAllAuras();
                    DoCastSelf(SPELL_VANISH);
                    me->SetReactState(REACT_PASSIVE);
                    events.ScheduleEvent(EVENT_JUST_VANISHED, 2s);
                    break;
                case EVENT_JUST_VANISHED:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                        DoCast(target, SPELL_SHADOWSTEP);
                    me->SetReactState(REACT_AGGRESSIVE);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (me->HealthBelowPctDamaged(71, damage) && me->HealthAbovePct(59) && _vanishCount < 1)
        {
            events.ScheduleEvent(EVENT_VANISH, 1s);
            ++_vanishCount;
        }

        if (me->HealthBelowPctDamaged(41, damage) && me->HealthAbovePct(29) && _vanishCount < 2)
        {
            events.ScheduleEvent(EVENT_VANISH, 1s);
            ++_vanishCount;
        }
    }

private:
    uint8 _vanishCount;
};

struct npc_mortimer_moloch : public ScriptedAI
{
    npc_mortimer_moloch(Creature* creature) : ScriptedAI(creature) { }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type == POINT_MOTION_TYPE)
            if (id == POINT_FINISH)
                _events.ScheduleEvent(EVENT_MORTIMER_MOLOCH_EMOTE, 4s);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_MORTIMER_MOLOCH_EMOTE:
                    Talk(SAY_HEART_ATTACK);
                    _events.ScheduleEvent(EVENT_MORTIMER_MOLOCH_DEATH, 3s);
                    break;
                case EVENT_MORTIMER_MOLOCH_DEATH:
                    Talk(SAY_RANDOLPH_DIED);
                    me->KillSelf();
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
};

void AddSC_boss_randolph_moloch()
{
    RegisterStormwindStockadeAI(boss_randolph_moloch);
    RegisterStormwindStockadeAI(npc_mortimer_moloch);
}
