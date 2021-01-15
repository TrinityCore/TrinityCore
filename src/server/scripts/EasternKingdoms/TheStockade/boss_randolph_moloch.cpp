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

#include "MotionMaster.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "the_stockade.h"

enum Spells
{
    SPELL_WILDLY_STABBING = 86726,
    SPELL_SWEEP           = 86729,
    SPELL_VANISH          = 55964,
    SPELL_SHADOWSTEP      = 55966
};

enum Events
{
    EVENT_WILDLY_STABBING = 1,
    EVENT_SWEEP,
    EVENT_VANISH,
    EVENT_JUST_VANISHED,
    EVENT_ATTACK_RANDOM,

    EVENT_MORTIMER_MOLOCH_EMOTE,
    EVENT_MORTIMER_MOLOCH_DEATH
};

enum Says
{
    SAY_PULL                = 0, // Allow me to introduce myself. I am Randolph Moloch and I will be killing you all today.
    SAY_VANISH              = 1, // Area Trigger: %s vanishes!
    SAY_DEATH               = 2, // My epic schemes, my great plans! Gone!

    MORTIMER_MOLOCH_DEATH   = 0, // %s collapses from a heart attack!
    MORTIMER_MOLOCH_EMOTE   = 1, // Egad! My sophisticated heart!
};

enum Points
{
    POINT_FINISH = 1,
};

Position const mortimerMolochPos = { 145.5811f, 0.7059f, -25.606f, 6.2f };

// Randolph Moloch - 46383
struct boss_randolph_moloch : public BossAI
{
    boss_randolph_moloch(Creature* creature) : BossAI(creature, DATA_RANDOLPH_MOLOCH), _firstVanish(false),
        _secondVanish(false) { }

    void Reset() override
    {
        _firstVanish = false;
        _secondVanish = false;
    }
    void EnterCombat(Unit* who) override
    {
        BossAI::EnterCombat(who);

        Talk(SAY_PULL);

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

    void JustDied(Unit* killer) override
    {
        BossAI::JustDied(killer);

        Talk(SAY_DEATH);

        me->SummonCreature(NPC_MORTIMER_MOLOCH, mortimerMolochPos);
    }

    void ExecuteEvent(uint32 eventId) override
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
                me->SetInCombatState(true); // Prevents the boss from resetting
                events.ScheduleEvent(EVENT_JUST_VANISHED, 2s);
                break;
            case EVENT_JUST_VANISHED:
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                    DoCast(target, SPELL_SHADOWSTEP, true);
                me->SetReactState(REACT_AGGRESSIVE);
                break;
            default:
                break;
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (me->HealthBelowPctDamaged(71, damage) && me->HealthAbovePct(59) && !_firstVanish)
        {
            _firstVanish = true;
            events.ScheduleEvent(EVENT_VANISH, 1s);
        }

        if (me->HealthBelowPctDamaged(41, damage) && me->HealthAbovePct(29) && !_secondVanish)
        {
            _secondVanish = true;
            events.ScheduleEvent(EVENT_VANISH, 1s);
        }
    }

private:
    bool _firstVanish;
    bool _secondVanish;
};

// Mortimer Moloch - 46482
struct npc_mortimer_moloch : public ScriptedAI
{
    npc_mortimer_moloch(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (id == POINT_FINISH)
        {
            scheduler.Schedule(4s, [this](TaskContext /*context*/)
            {
                Talk(MORTIMER_MOLOCH_EMOTE);
            });

            scheduler.Schedule(7s, [this](TaskContext /*context*/)
            {
                Talk(MORTIMER_MOLOCH_DEATH);
                me->KillSelf();
            });
        }
    }

    void UpdateAI(uint32 diff) override
    {
        scheduler.Update(diff);
    }

private:
    TaskScheduler scheduler;
};

void AddSC_boss_randolph_moloch()
{
    RegisterStormwindStockadesAI(boss_randolph_moloch);
    RegisterStormwindStockadesAI(npc_mortimer_moloch);
}
