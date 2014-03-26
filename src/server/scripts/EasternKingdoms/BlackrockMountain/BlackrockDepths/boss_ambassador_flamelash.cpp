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

enum Spells
{
    SPELL_FIREBLAST                                        = 15573
};

enum Events
{
    EVENT_FIREBLAST                                        = 1,
    EVENT_SUMMON_SPIRITS                                   = 2
};

class boss_ambassador_flamelash : public CreatureScript
{
public:
    boss_ambassador_flamelash() : CreatureScript("boss_ambassador_flamelash") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new boss_ambassador_flamelashAI(creature);
    }

    struct boss_ambassador_flamelashAI : public ScriptedAI
    {
        boss_ambassador_flamelashAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() OVERRIDE 
        {
            _events.ScheduleEvent(EVENT_FIREBLAST, 2000);
            _events.ScheduleEvent(EVENT_SUMMON_SPIRITS, 24000); 
        }

        void SummonSpirits(Unit* victim)
        {
            if (Creature* Spirit = DoSpawnCreature(9178, float(irand(-9, 9)), float(irand(-9, 9)), 0, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 60000))
                Spirit->AI()->AttackStart(victim);
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
                    case EVENT_FIREBLAST:
                        DoCastVictim(SPELL_FIREBLAST);
                        _events.ScheduleEvent(EVENT_FIREBLAST, 7000);
                        break;
                    case EVENT_SUMMON_SPIRITS:
                        for (uint32 i10 = 0; i10 < 4; ++i10)
                            SummonSpirits(me->GetVictim());
                        _events.ScheduleEvent(EVENT_SUMMON_SPIRITS, 30000);
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
        private:
            EventMap _events;
    };
};

void AddSC_boss_ambassador_flamelash()
{
    new boss_ambassador_flamelash();
}
