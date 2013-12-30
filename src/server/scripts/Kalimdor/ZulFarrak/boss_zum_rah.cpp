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

/*
Name: Boss_Zum_Rah
Category: Tanaris, ZulFarrak
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "zulfarrak.h"

enum Says
{
    SAY_SANCT_INVADE    = 0,
    SAY_WARD            = 1,
    SAY_KILL            = 2
};

enum Spells
{
    SPELL_SHADOW_BOLT               = 12739,
    SPELL_SHADOWBOLT_VOLLEY         = 15245,
    SPELL_WARD_OF_ZUM_RAH           = 11086,
    SPELL_HEALING_WAVE              = 12491
};

enum Events
{
    EVENT_SHADOW_BOLT           = 1,
    EVENT_SHADOWBOLT_VOLLEY     = 2,
    EVENT_WARD_OF_ZUM_RAH       = 3,
    EVENT_HEALING_WAVE          = 4
};

enum Faction
{
    ZUMRAH_FRIENDLY_FACTION     = 35
};

class boss_zum_rah : public CreatureScript
{
public:
    boss_zum_rah() : CreatureScript("boss_zum_rah") { }

    struct boss_zum_rahAI : public BossAI
    {
        boss_zum_rahAI(Creature* creature) : BossAI(creature, DATA_ZUM_RAH) { }

        void Reset() OVERRIDE
        {
            me->setFaction(ZUMRAH_FRIENDLY_FACTION); // areatrigger sets faction to enemy
            _ward80 = false;
            _ward40 = false;
            _heal30 = false;
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            Talk(SAY_SANCT_INVADE);
            events.ScheduleEvent(EVENT_SHADOW_BOLT, 1000);
            events.ScheduleEvent(EVENT_SHADOWBOLT_VOLLEY, 10000);
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            instance->SetData(DATA_ZUM_RAH, DONE);
        }

        void KilledUnit(Unit* /*victim*/) OVERRIDE
        {
            Talk(SAY_KILL);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SHADOW_BOLT:
                        DoCastVictim(SPELL_SHADOW_BOLT);
                        events.ScheduleEvent(EVENT_SHADOW_BOLT, 4000);
                        break;
                    case EVENT_WARD_OF_ZUM_RAH:
                        DoCast(me,SPELL_WARD_OF_ZUM_RAH);
                        break;
                    case EVENT_HEALING_WAVE:
                        DoCast(me,SPELL_HEALING_WAVE);
                        break;
                    case EVENT_SHADOWBOLT_VOLLEY:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_SHADOWBOLT_VOLLEY);
                        events.ScheduleEvent(EVENT_SHADOWBOLT_VOLLEY, 9000);
                        break;
                    default:
                        break;
                }
            }

            if (!_ward80 && HealthBelowPct(80))
            {
                _ward80 = true;
                Talk(SAY_WARD);
                events.ScheduleEvent(EVENT_WARD_OF_ZUM_RAH, 1000);
            }

            if (!_ward40 && HealthBelowPct(40))
            {
                _ward40 = true;
                Talk(SAY_WARD);
                events.ScheduleEvent(EVENT_WARD_OF_ZUM_RAH, 1000);
            }

            if (!_heal30 && HealthBelowPct(30))
            {
                _heal30 = true;
                events.ScheduleEvent(EVENT_HEALING_WAVE, 3000);
            }

            DoMeleeAttackIfReady();
        }

        private:
            bool _ward80;
            bool _ward40;
            bool _heal30;

    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return GetInstanceAI<boss_zum_rahAI>(creature);
    }
};

void AddSC_boss_zum_rah()
{
    new boss_zum_rah();
}
