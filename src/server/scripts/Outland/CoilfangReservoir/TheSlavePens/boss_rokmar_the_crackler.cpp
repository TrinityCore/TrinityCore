/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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
SDName: boss_rokmar_the_crackler
SD%Complete: 100%
SDComment:
SDCategory: Coilfang Reservoir, The Slave Pens
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "the_slave_pens.h"

enum Spells
{
    SPELL_GRIEVOUS_WOUND            = 31956,
    SPELL_ENSNARING_MOSS            = 31948,
    SPELL_WATER_SPIT                = 35008,
    SPELL_FRENZY                    = 34970
};

enum Events
{
    EVENT_GRIEVOUS_WOUND            = 1,
    EVENT_ENSNARING_MOSS            = 2,
    EVENT_WATER_SPIT                = 3
};

class boss_rokmar_the_crackler : public CreatureScript
{
    public:
        boss_rokmar_the_crackler() : CreatureScript("boss_rokmar_the_crackler") { }

        struct boss_rokmar_the_cracklerAI : public BossAI
        {
            boss_rokmar_the_cracklerAI(Creature* creature) : BossAI(creature, DATA_MENNU_THE_BETRAYER)
            {
                Initialize();
            }

            void Initialize()
            {
                rokmarFrenzy = false;
            }

            void Reset() override
            {
                _Reset();
                Initialize();
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _EnterCombat();
                events.ScheduleEvent(EVENT_GRIEVOUS_WOUND, 10000);
                events.ScheduleEvent(EVENT_ENSNARING_MOSS, 20000);
                events.ScheduleEvent(EVENT_WATER_SPIT, 14000);
            }

            void KilledUnit(Unit* /*victim*/) override { }

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
                        case EVENT_GRIEVOUS_WOUND:
                            DoCastVictim(SPELL_GRIEVOUS_WOUND, true);
                            events.ScheduleEvent(EVENT_GRIEVOUS_WOUND, urand(20000, 30000));
                            break;
                        case EVENT_ENSNARING_MOSS:
                            DoCastAOE(SPELL_ENSNARING_MOSS);
                            events.ScheduleEvent(EVENT_ENSNARING_MOSS, urand(20000, 30000));
                            break;
                        case EVENT_WATER_SPIT:
                            DoCastAOE(SPELL_WATER_SPIT);
                            events.ScheduleEvent(EVENT_WATER_SPIT, urand(14000, 18000));
                            break;
                        default:
                            break;
                    }
                }

                if (HealthBelowPct(10) && !rokmarFrenzy)
                {
                    DoCast(me, SPELL_FRENZY);
                    rokmarFrenzy = true;
                }

                DoMeleeAttackIfReady();
            }

            private:
                bool   rokmarFrenzy;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_rokmar_the_cracklerAI(creature);
        }
};

void AddSC_boss_rokmar_the_crackler()
{
    new boss_rokmar_the_crackler();
}
