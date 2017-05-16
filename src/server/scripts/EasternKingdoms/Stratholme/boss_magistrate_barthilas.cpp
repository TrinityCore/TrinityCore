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
SDName: Boss_Magistrate_Barthilas
SD%Complete: 70
SDComment:
SDCategory: Stratholme
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "stratholme.h"

enum Spells
{
    SPELL_DRAININGBLOW      = 16793,
    SPELL_CROWDPUMMEL       = 10887,
    SPELL_MIGHTYBLOW        = 14099,
    SPELL_FURIOUS_ANGER     = 16791
};

enum Events
{
    EVENT_DRAININGBLOW      = 1,
    EVENT_CROWDPUMMEL       = 2,
    EVENT_MIGHTYBLOW        = 3,
    EVENT_FURIOUS_ANGER     = 4,
};

enum Models
{
    MODEL_NORMAL            = 10433,
    MODEL_HUMAN             = 3637
};

class boss_magistrate_barthilas : public CreatureScript
{
public:
    boss_magistrate_barthilas() : CreatureScript("boss_magistrate_barthilas") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_magistrate_barthilasAI(creature);
    }

    struct boss_magistrate_barthilasAI : public ScriptedAI
    {
        boss_magistrate_barthilasAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            AngerCount = 0;
            if (me->IsAlive())
                me->SetDisplayId(MODEL_NORMAL);
            else
                me->SetDisplayId(MODEL_HUMAN);
            _events.Reset();
        }

        void MoveInLineOfSight(Unit* who) override

        {
            //nothing to see here yet

            ScriptedAI::MoveInLineOfSight(who);
        }

        void JustDied(Unit* /*killer*/) override
        {
            me->SetDisplayId(MODEL_HUMAN);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _events.ScheduleEvent(EVENT_DRAININGBLOW, 20 * IN_MILLISECONDS);
            _events.ScheduleEvent(EVENT_CROWDPUMMEL, 15 * IN_MILLISECONDS);
            _events.ScheduleEvent(EVENT_MIGHTYBLOW, 10 * IN_MILLISECONDS);
            _events.ScheduleEvent(EVENT_FURIOUS_ANGER, 5 * IN_MILLISECONDS);
        }

        void UpdateAI(uint32 diff) override
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            _events.Update(diff);
            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_DRAININGBLOW:
                        DoCastVictim(SPELL_DRAININGBLOW);
                        _events.ScheduleEvent(EVENT_DRAININGBLOW, 15 * IN_MILLISECONDS);
                        break;
                    case EVENT_CROWDPUMMEL:
                        DoCastVictim(SPELL_CROWDPUMMEL);
                        _events.ScheduleEvent(EVENT_CROWDPUMMEL, 15 * IN_MILLISECONDS);
                        break;
                    case EVENT_MIGHTYBLOW:
                        DoCastVictim(SPELL_MIGHTYBLOW);
                        _events.ScheduleEvent(EVENT_MIGHTYBLOW, 20 * IN_MILLISECONDS);
                        break;
                    case EVENT_FURIOUS_ANGER:
                        if (AngerCount > 25)
                            return;
                        ++AngerCount;
                        DoCast(me, SPELL_FURIOUS_ANGER, false);
                        _events.ScheduleEvent(EVENT_FURIOUS_ANGER, 4 * IN_MILLISECONDS);
                        break;
                    default:
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    private:
        uint32 AngerCount;
        EventMap _events;
    };

};

void AddSC_boss_magistrate_barthilas()
{
    new boss_magistrate_barthilas();
}
