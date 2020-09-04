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
#include "boss_horAI.h"
#include "halls_of_reflection.h"
#include "InstanceScript.h"

enum Texts
{
    SAY_AGGRO                                     = 0,
    SAY_SLAY                                      = 1,
    SAY_DEATH                                     = 2,
    SAY_IMPENDING_DESPAIR                         = 3,
    SAY_DEFILING_HORROR                           = 4
};

enum Spells
{
    SPELL_QUIVERING_STRIKE                        = 72422,
    SPELL_IMPENDING_DESPAIR                       = 72426,
    SPELL_DEFILING_HORROR                         = 72435,
    SPELL_HOPELESSNESS_1                          = 72395,
    SPELL_HOPELESSNESS_2                          = 72396,
    SPELL_HOPELESSNESS_3                          = 72397
};

enum Events
{
    EVENT_NONE,
    EVENT_QUIVERING_STRIKE,
    EVENT_IMPENDING_DESPAIR,
    EVENT_DEFILING_HORROR
};

uint32 const HopelessnessHelper[3] = { SPELL_HOPELESSNESS_1, SPELL_HOPELESSNESS_2, SPELL_HOPELESSNESS_3 };

class boss_falric : public CreatureScript
{
    public:
        boss_falric() : CreatureScript("boss_falric") { }

        struct boss_falricAI : public boss_horAI
        {
            boss_falricAI(Creature* creature) : boss_horAI(creature, DATA_FALRIC)
            {
                Initialize();
            }

            void Initialize()
            {
                _hopelessnessCount = 0;
            }

            void Reset() override
            {
                boss_horAI::Reset();
                Initialize();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                Talk(SAY_AGGRO);
                DoZoneInCombat();
                instance->SetBossState(DATA_FALRIC, IN_PROGRESS);

                events.ScheduleEvent(EVENT_QUIVERING_STRIKE, 23000);
                events.ScheduleEvent(EVENT_IMPENDING_DESPAIR, 9000);
                events.ScheduleEvent(EVENT_DEFILING_HORROR, urand(21000, 39000));
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage) override
            {
                if ((_hopelessnessCount < 1 && me->HealthBelowPctDamaged(66, damage))
                    || (_hopelessnessCount < 2 && me->HealthBelowPctDamaged(33, damage))
                    || (_hopelessnessCount < 3 && me->HealthBelowPctDamaged(10, damage)))
                {
                    if (_hopelessnessCount)
                        me->RemoveOwnedAura(HopelessnessHelper[_hopelessnessCount - 1]);
                    DoCast(me, HopelessnessHelper[_hopelessnessCount]);
                    ++_hopelessnessCount;
                }
            }

            void JustDied(Unit* /*killer*/) override
            {
                Talk(SAY_DEATH);
                events.Reset();
                instance->SetBossState(DATA_FALRIC, DONE);
            }

            void KilledUnit(Unit* who) override
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_SLAY);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                switch (events.ExecuteEvent())
                {
                    case EVENT_QUIVERING_STRIKE:
                        DoCastVictim(SPELL_QUIVERING_STRIKE);
                        events.ScheduleEvent(EVENT_QUIVERING_STRIKE, 10000);
                        break;
                    case EVENT_IMPENDING_DESPAIR:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 45.0f, true))
                        {
                            Talk(SAY_IMPENDING_DESPAIR);
                            DoCast(target, SPELL_IMPENDING_DESPAIR);
                        }
                        events.ScheduleEvent(EVENT_IMPENDING_DESPAIR, 13000);
                        break;
                    case EVENT_DEFILING_HORROR:
                        DoCastAOE(SPELL_DEFILING_HORROR);
                        events.ScheduleEvent(EVENT_DEFILING_HORROR, urand(21000, 39000));
                        break;
                    default:
                        break;
                }

                DoMeleeAttackIfReady();
            }

        private:
            uint8 _hopelessnessCount;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetHallsOfReflectionAI<boss_falricAI>(creature);
        }
};

void AddSC_boss_falric()
{
    new boss_falric();
}
