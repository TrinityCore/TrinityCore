/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
#include "blackrock_spire.h"

enum Spells
{
    SPELL_CRYSTALIZE                = 16104,
    SPELL_MOTHERSMILK               = 16468,
    SPELL_SUMMON_SPIRE_SPIDERLING   = 16103,
};

enum Events
{
    EVENT_CRYSTALIZE                = 1,
    EVENT_MOTHERS_MILK              = 2,
};

class boss_mother_smolderweb : public CreatureScript
{
public:
    boss_mother_smolderweb() : CreatureScript("boss_mother_smolderweb") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_mothersmolderwebAI(creature);
    }

    struct boss_mothersmolderwebAI : public BossAI
    {
        boss_mothersmolderwebAI(Creature* creature) : BossAI(creature, DATA_MOTHER_SMOLDERWEB) {}

        void Reset()
        {
            _Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            _EnterCombat();
            events.ScheduleEvent(EVENT_CRYSTALIZE,   20 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_MOTHERS_MILK, 10 * IN_MILLISECONDS);
        }

        void JustDied(Unit* /*killer*/)
        {
            _JustDied();
        }

        void DamageTaken(Unit* /*done_by*/, uint32 &damage)
        {
            if (me->GetHealth() <= damage)
                DoCast(me, SPELL_SUMMON_SPIRE_SPIDERLING, true);
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
                    case EVENT_CRYSTALIZE:
                        DoCast(me, SPELL_CRYSTALIZE);
                        events.ScheduleEvent(EVENT_CRYSTALIZE, 15 * IN_MILLISECONDS);
                        break;
                    case EVENT_MOTHERS_MILK:
                        DoCast(me, SPELL_MOTHERSMILK);
                        events.ScheduleEvent(EVENT_MOTHERS_MILK, urand(5 * IN_MILLISECONDS, 12500));
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_mothersmolderweb()
{
    new boss_mother_smolderweb();
}
