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

/* ScriptData
SDName: Boss_Broodlord_Lashlayer
SD%Complete: 100
SDComment:
SDCategory: Blackwing Lair
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"

enum Say
{
    SAY_AGGRO               = 0,
    SAY_LEASH               = 1,
};

enum Events
{
    EVENT_CLEAVE            = 1,
    EVENT_MORTAL_STRIKE     = 2,
    EVENT_BLAST_WAVE        = 3,
    EVENT_KNOCK_BACK        = 4,
};

enum Spells
{
    SPELL_CLEAVE            = 26350,
    SPELL_BLAST_WAVE        = 23331,
    SPELL_MORTAL_STRIKE     = 24573,
    SPELL_KNOCK_BACK        = 25778
};

class boss_broodlord : public CreatureScript
{
public:
    boss_broodlord() : CreatureScript("boss_broodlord") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_broodlordAI (creature);
    }

    struct boss_broodlordAI : public ScriptedAI
    {
        boss_broodlordAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset()
        {
            // These timers are probably wrong
            events.ScheduleEvent(EVENT_CLEAVE, 8000);
            events.ScheduleEvent(EVENT_BLAST_WAVE, 12000);
            events.ScheduleEvent(EVENT_MORTAL_STRIKE, 20000);
            events.ScheduleEvent(EVENT_KNOCK_BACK, 30000);
        }

        void EnterCombat(Unit* /*who*/)
        {
            Talk(SAY_AGGRO);
            DoZoneInCombat();
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (EnterEvadeIfOutOfCombatArea(diff))
                Talk(SAY_LEASH);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_CLEAVE:
                        DoCastVictim(SPELL_CLEAVE);
                        events.ScheduleEvent(EVENT_CLEAVE, 8000);
                        break;
                    case EVENT_MORTAL_STRIKE:
                        DoCastVictim(SPELL_MORTAL_STRIKE);
                        events.ScheduleEvent(EVENT_MORTAL_STRIKE, 20000);
                        break;
                    case EVENT_BLAST_WAVE:
                        DoCastVictim(SPELL_BLAST_WAVE);
                        events.ScheduleEvent(EVENT_BLAST_WAVE, 12000);
                        break;
                    case EVENT_KNOCK_BACK:
                        if (Unit* target = me->GetVictim())
                        {
                            DoCast(target, SPELL_BLAST_WAVE);
                            // Drop 50% of threat
                            if (DoGetThreat(target))
                                DoModifyThreatPercent(target, -50);
                        }
                        events.ScheduleEvent(EVENT_KNOCK_BACK, 30000);
                        break;
                    default:
                        break;
                }
            }

            if (EnterEvadeIfOutOfCombatArea(diff))
                Talk(SAY_LEASH);

            DoMeleeAttackIfReady();
        }

        private:
            EventMap events; /// @todo: change BWL to instance script and bosses to BossAI
    };
};

void AddSC_boss_broodlord()
{
    new boss_broodlord();
}
