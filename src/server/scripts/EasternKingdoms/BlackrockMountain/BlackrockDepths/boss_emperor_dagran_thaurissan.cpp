/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
#include "blackrock_depths.h"

enum Yells
{
    SAY_AGGRO                                              = 0,
    SAY_SLAY                                               = 1
};

enum Spells
{
    SPELL_HANDOFTHAURISSAN                                 = 17492,
    SPELL_AVATAROFFLAME                                    = 15636
};

enum Events
{
    EVENT_HANDOFTHAURISSAN                                 = 1,
    EVENT_AVATAROFFLAME                                    = 2
};

class boss_emperor_dagran_thaurissan : public CreatureScript
{
public:
    boss_emperor_dagran_thaurissan() : CreatureScript("boss_emperor_dagran_thaurissan") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return GetInstanceAI<boss_draganthaurissanAI>(creature);
    }

    struct boss_draganthaurissanAI : public ScriptedAI
    {
        boss_draganthaurissanAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = me->GetInstanceScript();
        }

        InstanceScript* instance;

        void Reset() OVERRIDE
        {
            _events.ScheduleEvent(EVENT_HANDOFTHAURISSAN, 4000);
            _events.ScheduleEvent(EVENT_AVATAROFFLAME, 25000);
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            Talk(SAY_AGGRO);
            me->CallForHelp(VISIBLE_RANGE);
        }

        void KilledUnit(Unit* /*victim*/) OVERRIDE
        {
            Talk(SAY_SLAY);
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            if (Creature* Moira = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_MOIRA)))
            {
                Moira->AI()->EnterEvadeMode();
                Moira->setFaction(35);
            }
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_HANDOFTHAURISSAN:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_HANDOFTHAURISSAN);
                        _events.ScheduleEvent(EVENT_HANDOFTHAURISSAN, 5000);
                        break;
                    case EVENT_AVATAROFFLAME:
                        DoCastVictim(SPELL_AVATAROFFLAME);
                        _events.ScheduleEvent(EVENT_AVATAROFFLAME, 18000);
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
        private:
            EventMap _events;
    };
};

void AddSC_boss_draganthaurissan()
{
    new boss_emperor_dagran_thaurissan();
}
