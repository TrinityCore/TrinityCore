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
    SPELL_MIGHTYBLOW                                       = 14099,
    SPELL_HAMSTRING                                        = 9080,
    SPELL_CLEAVE                                           = 20691
};

enum Events
{
    EVENT_MIGHTYBLOW                                       = 1,
    EVENT_HAMSTRING                                        = 2,
    EVENT_CLEAVE                                           = 3,
    EVENT_ADDS                                             = 4
};

class boss_general_angerforge : public CreatureScript
{
public:
    boss_general_angerforge() : CreatureScript("boss_general_angerforge") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new boss_general_angerforgeAI(creature);
    }

    struct boss_general_angerforgeAI : public ScriptedAI
    {
        boss_general_angerforgeAI(Creature* creature) : ScriptedAI(creature) {}
        
        void Reset() OVERRIDE
        {            
            _events.ScheduleEvent(EVENT_MIGHTYBLOW, 8000);
            _events.ScheduleEvent(EVENT_HAMSTRING, 12000);
            _events.ScheduleEvent(EVENT_CLEAVE, 16000);
            _medics = false;
            _phaseTwo = false;            
        }

        void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/) OVERRIDE
        {
            if (!HealthAbovePct(20) && !_phaseTwo)
            {
                _phaseTwo = true;
                _events.ScheduleEvent(EVENT_ADDS, 0);
            }
        }

        void SummonAdds(Unit* victim)
        {
            if (Creature* SummonedAdd = DoSpawnCreature(8901, float(irand(-14, 14)), float(irand(-14, 14)), 0, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 120000))
                SummonedAdd->AI()->AttackStart(victim);
        }

        void SummonMedics(Unit* victim)
        {
            if (Creature* SummonedMedic = DoSpawnCreature(8894, float(irand(-9, 9)), float(irand(-9, 9)), 0, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 120000))
                SummonedMedic->AI()->AttackStart(victim);
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
                    case EVENT_MIGHTYBLOW:
                        DoCastVictim(SPELL_MIGHTYBLOW);
                        _events.ScheduleEvent(EVENT_MIGHTYBLOW, 18000);
                        break;
                    case EVENT_HAMSTRING:
                        DoCastVictim(SPELL_HAMSTRING);
                        _events.ScheduleEvent(EVENT_HAMSTRING, 15000);
                        break;
                    case EVENT_CLEAVE:
                        DoCastVictim(SPELL_CLEAVE);
                        _events.ScheduleEvent(EVENT_CLEAVE, 9000);
                        break;
                    case EVENT_ADDS:
                        for (uint32 i10 = 0; i10 < 3; ++i10)
                            SummonAdds(me->GetVictim());
                        if (!_medics)
                        {
                            for (uint32 i10 = 0; i10 < 2; ++i10)
                                SummonMedics(me->GetVictim());
                            _medics = true;
                        }
                        _events.ScheduleEvent(EVENT_ADDS, 25000);
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
        private:
            EventMap _events;
            bool _medics;
            bool _phaseTwo; // Sub 20% Phase
    };
};

void AddSC_boss_general_angerforge()
{
    new boss_general_angerforge();
}
