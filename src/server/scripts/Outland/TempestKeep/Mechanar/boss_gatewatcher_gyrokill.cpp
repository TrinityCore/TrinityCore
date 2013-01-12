/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
SDName: Boss_Gatewatcher_Gyrokill
SD%Complete: 0
SDComment: Place Holder
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
    EVENT_STREAM_OF_MACHINE_FLUID   = 0,
    EVENT_SAW_BLADE                 = 1,
    EVENT_SHADOW_POWER              = 2
};

class Boss_Gatewatcher_Gyrokill : public CreatureScript
{
    public: Boss_Gatewatcher_Gyrokill() : CreatureScript("Boss_Gatewatcher_Gyrokill") { }

        struct Boss_Gatewatcher_GyrokillAI : public BossAI
        {
            Boss_Gatewatcher_GyrokillAI(Creature* creature) : BossAI(creature, DATA_GATEWATCHER_GYROKILL) {}

            void Reset()
            {
                if (instance)
                    instance->SetData(DATA_GATEWATCHER_GYROKILL, NOT_STARTED);
            }

            void JustDied(Unit* /*killer*/)
            {
                if (instance)
                    instance->SetData(DATA_GATEWATCHER_GYROKILL, DONE);

                Talk(SAY_DEATH);
            }

            void EnterCombat(Unit* /*who*/)
            {
                 if (instance)
                    instance->SetData(DATA_GATEWATCHER_GYROKILL, IN_PROGRESS);

                events.ScheduleEvent(EVENT_STREAM_OF_MACHINE_FLUID, 10000);
                events.ScheduleEvent(EVENT_SAW_BLADE, 20000);
                events.ScheduleEvent(EVENT_SHADOW_POWER, 25000);

                Talk(SAY_AGGRO);
            }

            void KilledUnit(Unit* /*victim*/)
            {
                Talk(SAY_SLAY);
            }

            void UpdateAI(uint32 const diff)
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
                            if (IsHeroic())
                                DoCast(me, H_SPELL_SAW_BLADE);
                            else
                                DoCast(me, SPELL_SAW_BLADE);
                            Talk(SAY_SAW_BLADEs);
                            events.ScheduleEvent(EVENT_SAW_BLADE, urand(20000, 30000));
                            break;
                        case EVENT_SHADOW_POWER:
                            if (IsHeroic())
                                DoCast(me, H_SPELL_SHADOW_POWER);
                            else
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

        CreatureAI* GetAI(Creature* creature) const
        {
            return new Boss_Gatewatcher_GyrokillAI (creature);
        }
};

void AddSC_Boss_Gatewatcher_Gyrokill()
{
    new Boss_Gatewatcher_Gyrokill();
}