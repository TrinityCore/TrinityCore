/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
SDName: boss_gatewatcher_gyrokill
SD%Complete: 99%
SDComment:
SDCategory: Tempest Keep, The Mechanar
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "mechanar.h"

enum Say
{
    SAY_AGGRO                       = 0,
    SAY_SLAY                        = 1,
    SAY_SAW_BLADEs                  = 2,
    SAY_DEATH                       = 3
};

enum Spells
{
    SPELL_STREAM_OF_MACHINE_FLUID   = 35311,
    SPELL_SAW_BLADE                 = 35318,
    H_SPELL_SAW_BLADE               = 39192,
    SPELL_SHADOW_POWER              = 35322,
    H_SPELL_SHADOW_POWER            = 39193
};

enum Events
{
    EVENT_STREAM_OF_MACHINE_FLUID   = 1,
    EVENT_SAW_BLADE                 = 2,
    EVENT_SHADOW_POWER              = 3
};

class boss_gatewatcher_gyrokill : public CreatureScript
{
    public:
        boss_gatewatcher_gyrokill() : CreatureScript("boss_gatewatcher_gyrokill") { }

        struct boss_gatewatcher_gyrokillAI : public BossAI
        {
            boss_gatewatcher_gyrokillAI(Creature* creature) : BossAI(creature, DATA_GATEWATCHER_GYROKILL) { }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                Talk(SAY_DEATH);
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _EnterCombat();
                events.ScheduleEvent(EVENT_STREAM_OF_MACHINE_FLUID, 10000);
                events.ScheduleEvent(EVENT_SAW_BLADE, 20000);
                events.ScheduleEvent(EVENT_SHADOW_POWER, 25000);
                Talk(SAY_AGGRO);
            }

            void KilledUnit(Unit* /*victim*/) override
            {
                Talk(SAY_SLAY);
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
                        case EVENT_STREAM_OF_MACHINE_FLUID:
                            DoCastVictim(SPELL_STREAM_OF_MACHINE_FLUID, true);
                            events.ScheduleEvent(EVENT_STREAM_OF_MACHINE_FLUID, urand(13000, 17000));
                            break;
                        case EVENT_SAW_BLADE:
                            DoCast(me, SPELL_SAW_BLADE);
                            Talk(SAY_SAW_BLADEs);
                            events.ScheduleEvent(EVENT_SAW_BLADE, urand(20000, 30000));
                            break;
                        case EVENT_SHADOW_POWER:
                            DoCast(me, SPELL_SHADOW_POWER);
                            events.ScheduleEvent(EVENT_SAW_BLADE, urand(25000, 35000));
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_gatewatcher_gyrokillAI(creature);
        }
};

void AddSC_boss_gatewatcher_gyrokill()
{
    new boss_gatewatcher_gyrokill();
}
