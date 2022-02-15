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

/* ScriptData
SDName: Boss_Watchkeeper_Gargolmar
SD%Complete: 80
SDComment: Missing adds to heal him. Surge should be used on target furthest away, not random.
SDCategory: Hellfire Citadel, Hellfire Ramparts
EndScriptData */

#include "ScriptMgr.h"
#include "hellfire_ramparts.h"
#include "ScriptedCreature.h"

enum Says
{
    SAY_TAUNT              = 0,
    SAY_HEAL               = 1,
    SAY_SURGE              = 2,
    SAY_AGGRO              = 3,
    SAY_KILL               = 4,
    SAY_DIE                = 5
};

enum Spells
{
    SPELL_MORTAL_WOUND     = 30641,
    SPELL_SURGE            = 34645,
    SPELL_RETALIATION      = 22857
};

enum Events
{
    EVENT_MORTAL_WOUND     = 1,
    EVENT_SURGE            = 2,
    EVENT_RETALIATION      = 3
};

class boss_watchkeeper_gargolmar : public CreatureScript
{
    public:
        boss_watchkeeper_gargolmar() : CreatureScript("boss_watchkeeper_gargolmar") { }

        struct boss_watchkeeper_gargolmarAI : public BossAI
        {
            boss_watchkeeper_gargolmarAI(Creature* creature) : BossAI(creature, DATA_WATCHKEEPER_GARGOLMAR)
            {
                Initialize();
            }

            void Initialize()
            {
                hasTaunted = false;
                yelledForHeal = false;
                retaliation = false;
            }

            void Reset() override
            {
                Initialize();
                _Reset();
            }

            void JustEngagedWith(Unit* who) override
            {
                Talk(SAY_AGGRO);
                events.ScheduleEvent(EVENT_MORTAL_WOUND, 5s);
                events.ScheduleEvent(EVENT_SURGE, 4s);
                BossAI::JustEngagedWith(who);
            }

            void MoveInLineOfSight(Unit* who) override
            {
                if (!me->GetVictim() && me->CanCreatureAttack(who))
                {
                    if (!me->CanFly() && me->GetDistanceZ(who) > CREATURE_Z_ATTACK_RANGE)
                        return;

                    float attackRadius = me->GetAttackDistance(who);
                    if (me->IsWithinDistInMap(who, attackRadius) && me->IsWithinLOSInMap(who))
                    {
                        //who->RemoveSpellsCausingAura(SPELL_AURA_MOD_STEALTH);
                        AttackStart(who);
                    }
                    else if (!hasTaunted && me->IsWithinDistInMap(who, 60.0f))
                    {
                        Talk(SAY_TAUNT);
                        hasTaunted = true;
                    }
                }
            }

            void KilledUnit(Unit* /*victim*/) override
            {
                Talk(SAY_KILL);
            }

            void JustDied(Unit* /*killer*/) override
            {
                Talk(SAY_DIE);
                _JustDied();
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
                        case EVENT_MORTAL_WOUND:
                            DoCastVictim(SPELL_MORTAL_WOUND);
                            events.ScheduleEvent(EVENT_MORTAL_WOUND, 5s, 13s);
                            break;
                        case EVENT_SURGE:
                            Talk(SAY_SURGE);
                            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                                DoCast(target, SPELL_SURGE);
                            events.ScheduleEvent(EVENT_SURGE, 5s, 13s);
                            break;
                        case EVENT_RETALIATION:
                            DoCast(me, SPELL_RETALIATION);
                            events.ScheduleEvent(EVENT_RETALIATION, 30s);
                            break;
                        default:
                            break;
                    }
                }

                if (!retaliation)
                {
                    if (HealthBelowPct(20))
                    {
                        events.ScheduleEvent(EVENT_RETALIATION, 1s);
                        retaliation = true;
                    }
                }

                if (!yelledForHeal)
                {
                    if (HealthBelowPct(40))
                    {
                        Talk(SAY_HEAL);
                        yelledForHeal = true;
                    }
                }

                DoMeleeAttackIfReady();
            }

            private:
                bool hasTaunted;
                bool yelledForHeal;
                bool retaliation;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetHellfireRampartsAI<boss_watchkeeper_gargolmarAI>(creature);
        }
};

void AddSC_boss_watchkeeper_gargolmar()
{
    new boss_watchkeeper_gargolmar();
}
