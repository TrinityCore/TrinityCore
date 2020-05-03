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
#include "MotionMaster.h"
#include "ScriptedCreature.h"
#include "the_stockade.h"

enum Spells
{
    SPELL_WILDLY_STABBING           = 86726,
    SPELL_SWEEP                     = 86729,
    SPELL_VANISH                    = 55964,
    SPELL_SHADOWSTEP                = 55966
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
    SAY_PULL                = 0, //Allow me to introduce myself. I am Randolph Moloch and I will be killing you all today.
    SAY_VANISH              = 1, // Area Trigger: %s vanishes!
    SAY_DEATH               = 2, //My epic schemes, my great plans! Gone!

    MORTIMER_MOLOCH_DEATH   = 0, // %s collapses from a heart attack!
    MORTIMER_MOLOCH_EMOTE   = 1, //Egad! My sophisticated heart!
};

enum Points
{
    POINT_FINISH = 0,
};

Position const mortimerMolochPos = { 145.5811f, 0.7059f, -25.606f, 6.2f };

class boss_randolph_moloch : public CreatureScript
{
public:
    boss_randolph_moloch() : CreatureScript("boss_randolph_moloch") {}

    struct boss_randolph_molochAI : public BossAI
    {
        boss_randolph_molochAI(Creature* creature) : BossAI(creature, DATA_RANDOLPH_MOLOCH)
        {
            firstVanish = false;
            secondVanish = false;
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();
            Talk(SAY_PULL);
            events.ScheduleEvent(EVENT_WILDLY_STABBING, Seconds(4), Seconds(5));
            events.ScheduleEvent(EVENT_SWEEP, Seconds(2), Seconds(3));
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

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);
            _JustDied();
            me->SummonCreature(NPC_MORTIMER_MOLOCH, mortimerMolochPos);
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
                    events.Repeat(Seconds(8), Seconds(12));
                    break;
                case EVENT_SWEEP:
                    DoCastVictim(SPELL_SWEEP);
                    events.ScheduleEvent(EVENT_SWEEP, Seconds(6), Seconds(7));
                    break;
                case EVENT_VANISH:
                    Talk(SAY_VANISH);
                    me->RemoveAllAuras();
                    DoCastSelf(SPELL_VANISH);
                    me->SetReactState(REACT_PASSIVE);
                    me->SetInCombatState(true); // Prevents the boss from resetting
                    events.ScheduleEvent(EVENT_JUST_VANISHED, Seconds(2));
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

            DoMeleeAttackIfReady();
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
            if (me->HealthBelowPctDamaged(71, damage) && me->HealthAbovePct(59) && !firstVanish)
            {
                firstVanish = true;
                events.ScheduleEvent(EVENT_VANISH, Seconds(1));
            }

            if (me->HealthBelowPctDamaged(41, damage) && me->HealthAbovePct(29) && !secondVanish)
            {
                secondVanish = true;
                events.ScheduleEvent(EVENT_VANISH, Seconds(1));
            }
        }

    private:
        bool firstVanish, secondVanish;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetStormwindStockadeAI<boss_randolph_molochAI>(creature);
    }
};

class npc_mortimer_moloch : public CreatureScript
{
public:
    npc_mortimer_moloch() : CreatureScript("npc_mortimer_moloch") {}

    struct npc_mortimer_molochAI : public ScriptedAI
    {
        npc_mortimer_molochAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() override
        {
            me->SetReactState(REACT_PASSIVE);
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == POINT_MOTION_TYPE)
                if(id == POINT_FINISH)
                    _events.ScheduleEvent(EVENT_MORTIMER_MOLOCH_EMOTE, Seconds(4));
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_MORTIMER_MOLOCH_EMOTE:
                    Talk(MORTIMER_MOLOCH_EMOTE);
                    _events.ScheduleEvent(EVENT_MORTIMER_MOLOCH_DEATH, Seconds(3));
                    break;
                case EVENT_MORTIMER_MOLOCH_DEATH:
                    Talk(MORTIMER_MOLOCH_DEATH);
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

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetStormwindStockadeAI<npc_mortimer_molochAI>(creature);
    }
};

void AddSC_boss_randolph_moloch()
{
    new boss_randolph_moloch();
    new npc_mortimer_moloch();
}
