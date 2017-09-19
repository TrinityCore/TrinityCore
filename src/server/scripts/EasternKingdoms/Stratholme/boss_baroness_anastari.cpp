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
#include "InstanceScript.h"
#include "ScriptedCreature.h"
#include "stratholme.h"

enum Spells
{
    SPELL_BANSHEEWAIL       = 16565,
    SPELL_BANSHEECURSE      = 16867,
    SPELL_SILENCE           = 18327,
    SPELL_POSSESS           = 17244,
    SPELL_POSSESSED         = 17246
};

enum BaronessAnastariEvents
{
    EVENT_SPELL_BANSHEEWAIL     = 1,
    EVENT_SPELL_BANSHEECURSE    = 2,
    EVENT_SPELL_SILENCE         = 3,
    EVENT_SPELL_POSSESS         = 4,
    EVENT_INVISIBLE             = 5
};

class boss_baroness_anastari : public CreatureScript
{
public:
    boss_baroness_anastari() : CreatureScript("boss_baroness_anastari") { }

    struct boss_baroness_anastariAI : public ScriptedAI
    {
        boss_baroness_anastariAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = me->GetInstanceScript();
        }

        InstanceScript* instance;
        
        bool invisible;
        Unit* possessedTarget;
        uint32 invisibleTimer; // after 2 minutes dispell possessed

        void Reset() override
        {
            if (possessedTarget)
            {
                if (possessedTarget->HasAura(SPELL_POSSESSED) && possessedTarget->IsAlive())
                {
                    possessedTarget->RemoveAurasDueToSpell(SPELL_POSSESSED);
                    possessedTarget->RemoveAurasDueToSpell(SPELL_POSSESS);
                    possessedTarget->SetObjectScale(1.0f);
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->SetVisible(true);
                }
            }
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _events.ScheduleEvent(EVENT_SPELL_BANSHEEWAIL, Seconds(1));
            _events.ScheduleEvent(EVENT_SPELL_BANSHEECURSE, Seconds(11));
            _events.ScheduleEvent(EVENT_SPELL_SILENCE, Seconds(13));
            _events.ScheduleEvent(EVENT_SPELL_POSSESS, Seconds(20), Seconds(30));
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
                if (invisible)
                {
                    if (!possessedTarget->HasAura(SPELL_POSSESSED))
                        _events.ScheduleEvent(EVENT_INVISIBLE, Seconds(0));

                    if (possessedTarget->GetHealthPct() <= 50)
                        _events.ScheduleEvent(EVENT_INVISIBLE, Seconds(0));
                }
                
                switch (eventId)
                {
                    case EVENT_SPELL_BANSHEEWAIL:
                        DoCast(me->GetVictim(),SPELL_BANSHEEWAIL);
                        _events.ScheduleEvent(EVENT_SPELL_BANSHEEWAIL, Seconds(4));
                        break;
                    case EVENT_SPELL_BANSHEECURSE:
                        DoCast(me->GetVictim(), SPELL_BANSHEECURSE);
                        _events.ScheduleEvent(EVENT_SPELL_BANSHEECURSE, Seconds(18));
                        break;
                    case EVENT_SPELL_SILENCE:
                        DoCast(me->GetVictim(), SPELL_SILENCE);
                        _events.ScheduleEvent(EVENT_SPELL_SILENCE, Seconds(13));
                        break;
                    case EVENT_SPELL_POSSESS:
                        if (possessedTarget = (SelectTarget(SELECT_TARGET_RANDOM, 1, 0, true, false)))
                        {
                            me->CastStop();
                            DoCast(possessedTarget, SPELL_POSSESS);
                            DoCast(possessedTarget, SPELL_POSSESSED);
                            possessedTarget->SetObjectScale(1.5f);
                            me->SetReactState(REACT_PASSIVE);
                            me->SetVisible(false);
                            invisible = true;
                            invisibleTimer = 120000;
                        }
                        else
                            _events.ScheduleEvent(EVENT_SPELL_POSSESS, Seconds(20), Seconds(30));
                        break;
                    case EVENT_INVISIBLE:
                            possessedTarget->RemoveAurasDueToSpell(SPELL_POSSESS);
                            possessedTarget->RemoveAurasDueToSpell(SPELL_POSSESSED);
                            possessedTarget->SetObjectScale(1.0f);
                            me->SetReactState(REACT_AGGRESSIVE);
                            me->SetVisible(true);
                            invisible = false;
                            invisibleTimer = 0;
                            _events.ScheduleEvent(EVENT_SPELL_POSSESS, Seconds(20), Seconds(30));
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

        private:
            EventMap _events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetStratholmeAI<boss_baroness_anastariAI>(creature);
    }
};

void AddSC_boss_baroness_anastari()
{
    new boss_baroness_anastari();
}
