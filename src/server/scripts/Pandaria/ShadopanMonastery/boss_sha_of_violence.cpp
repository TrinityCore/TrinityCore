/*
 * Copyright (C) 2022 BfaCore Reforged
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
#include "ScriptedCreature.h"
#include "shadopan_monastery.h"

enum eSpells
{
    SPELL_SMOKE_BLADES          = 106826,
    SPELL_SHA_SPIKE             = 106871,
    SPELL_DISORIENTING_SMASH    = 106872,
    SPELL_PARTING_SMOKE         = 127576,
    SPELL_ENRAGE                = 130196,

    SPELL_ICE_TRAP              = 110610,
    SPELL_EXPLOSION             = 106966
};

enum eEvents
{
    // Gu
    EVENT_SMOKE_BLADES          = 1,
    EVENT_SHA_SPIKE             = 2,
    EVENT_DISORIENTING_SMASH    = 3
};

class boss_sha_of_violence : public CreatureScript
{
    public:
        boss_sha_of_violence() : CreatureScript("boss_sha_of_violence") {}

        struct boss_sha_of_violenceAI : public BossAI
        {
            boss_sha_of_violenceAI(Creature* creature) : BossAI(creature, DATA_SHA_VIOLENCE)
            {
                pInstance = creature->GetInstanceScript();
            }

            InstanceScript* pInstance;
            bool enrageDone;

            void Reset() override
            {
                _Reset();
                enrageDone = false;

                events.ScheduleEvent(EVENT_SMOKE_BLADES, urand(25000, 35000));
                events.ScheduleEvent(EVENT_SHA_SPIKE, urand(10000, 20000));
                events.ScheduleEvent(EVENT_DISORIENTING_SMASH, urand(20000, 30000));
            }

            void JustReachedHome() override
            {
                pInstance->SetBossState(DATA_SHA_VIOLENCE, FAIL);
                summons.DespawnAll();
            }

            void JustSummoned(Creature* summon) override
            {
                summons.Summon(summon);
                summon->CastSpell(summon, SPELL_ICE_TRAP, true);
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage) override
            {
                if (!enrageDone && me->HealthBelowPctDamaged(20, damage))
                    me->CastSpell(me, SPELL_ENRAGE, true);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                switch(events.ExecuteEvent())
                {
                    case EVENT_SMOKE_BLADES:
                        me->CastSpell(me, SPELL_SMOKE_BLADES, false);
                        events.ScheduleEvent(EVENT_SMOKE_BLADES,        urand(25000, 35000));
                        break;
                    case EVENT_SHA_SPIKE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                            me->CastSpell(target, SPELL_SHA_SPIKE, false);

                        events.ScheduleEvent(EVENT_SHA_SPIKE,           urand(10000, 20000));
                        break;
                    case EVENT_DISORIENTING_SMASH:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                            me->CastSpell(target, SPELL_DISORIENTING_SMASH, false);

                        events.ScheduleEvent(EVENT_DISORIENTING_SMASH,  urand(20000, 30000));
                        break;
                    default:
                        break;
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_sha_of_violenceAI(creature);
        }
};

void AddSC_boss_sha_of_violence()
{
    new boss_sha_of_violence();
}
