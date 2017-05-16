/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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
SDName: Boss_Baroness_Anastari
SD%Complete: 90
SDComment: MC disabled
SDCategory: Stratholme
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "stratholme.h"

enum Spells
{
    SPELL_BANSHEEWAIL       = 16565,
    SPELL_BANSHEECURSE      = 16867,
    SPELL_SILENCE           = 18327
    //SPELL_POSSESS           = 17244
};

enum AnastariSpells
{
    EVENT_BANSHEEWAIL       = 0,
    EVENT_BANSHEECURSE      = 1,
    EVENT_SILENCE           = 2,
    //EVENT_POSSESS         = 3,
};

class boss_baroness_anastari : public CreatureScript
{
public:
    boss_baroness_anastari() : CreatureScript("boss_baroness_anastari") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<boss_baroness_anastariAI>(creature);
    }

    struct boss_baroness_anastariAI : public ScriptedAI
    {
        boss_baroness_anastariAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = me->GetInstanceScript();
        }
        
        void Reset() override
        {
            _events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _events.ScheduleEvent(EVENT_BANSHEEWAIL, 1 * IN_MILLISECONDS);
            _events.ScheduleEvent(EVENT_BANSHEECURSE, 11 * IN_MILLISECONDS);
            _events.ScheduleEvent(EVENT_SILENCE, 13 * IN_MILLISECONDS);
            //_events.ScheduleEvent(EVENT_POSSESS, 35*IN_MILLISECONDS);
        }

        void JustDied(Unit* /*killer*/) override
        {
            instance->SetData(TYPE_BARONESS, IN_PROGRESS);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            _events.Update(diff);
            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_BANSHEEWAIL:
                        if (rand32() % 95)
                            DoCastVictim(SPELL_BANSHEEWAIL);
                        _events.ScheduleEvent(EVENT_BANSHEEWAIL, 4 * IN_MILLISECONDS);
                        break;
                    case EVENT_BANSHEECURSE:
                        if (rand32() % 75)
                            DoCastVictim(SPELL_BANSHEECURSE);
                        _events.ScheduleEvent(EVENT_BANSHEECURSE, 18 * IN_MILLISECONDS);
                        break;
                    case EVENT_SILENCE:
                        if (rand32() % 80)
                            DoCastVictim(SPELL_SILENCE);
                        _events.ScheduleEvent(EVENT_SILENCE, 13 * IN_MILLISECONDS);
                        break;
                    default:
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    private:
        InstanceScript* instance;
        EventMap _events;
    };

};

void AddSC_boss_baroness_anastari()
{
    new boss_baroness_anastari();
}
