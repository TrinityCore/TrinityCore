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
    EVENT_INVISIBLE             = 5,
    EVENT_CHECK_POSSESSED       = 6
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

        void Reset() override
        {
            Unit* possessedTarget = me->GetMap()->GetPlayer(_possessedTargetGuid);

            if (_invisible)
            {
                if (possessedTarget && possessedTarget->IsAlive())
                {
                    possessedTarget->RemoveAurasDueToSpell(SPELL_POSSESSED);
                    possessedTarget->RemoveAurasDueToSpell(SPELL_POSSESS);
                    possessedTarget->SetObjectScale(1.0f);
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->SetVisible(true);
                    _invisible = false;
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
                switch (eventId)
                {
                    case EVENT_SPELL_BANSHEEWAIL:
                        DoCast(me->GetVictim(),SPELL_BANSHEEWAIL);
                        _events.ScheduleEvent(EVENT_SPELL_BANSHEEWAIL, Seconds(4));
                        break;
                    case EVENT_SPELL_BANSHEECURSE:
                        DoCastVictim(SPELL_BANSHEECURSE);
                        _events.Repeat(Seconds(18));
                        break;
                    case EVENT_SPELL_SILENCE:
                        DoCast(me->GetVictim(), SPELL_SILENCE);
                        _events.ScheduleEvent(EVENT_SPELL_SILENCE, Seconds(13));
                        break;
                    case EVENT_SPELL_POSSESS:
                        if (Unit* possessTarget = SelectTarget(SELECT_TARGET_RANDOM, 1, 0, true, false))    // Random target to be possessed
                        {
                            if (possessTarget && possessTarget->IsAlive())
                            {
                                me->CastStop();
                                DoCast(possessTarget, SPELL_POSSESS);
                                DoCast(possessTarget, SPELL_POSSESSED);
                                possessTarget->SetObjectScale(1.5f);
                                me->SetReactState(REACT_PASSIVE);
                                me->SetVisible(false);
                                _invisible = true;
                                _possessedTargetGuid = possessTarget->GetGUID();
                                _events.ScheduleEvent(EVENT_CHECK_POSSESSED, Seconds(0));
                            }
                            else
                                _events.ScheduleEvent(EVENT_SPELL_POSSESS, Seconds(20), Seconds(30));
                        }
                        break;
                    case EVENT_INVISIBLE:
                        if (Unit* possessedTarget = me->GetMap()->GetPlayer(_possessedTargetGuid))          // When there's a possessed target
                        {
                            possessedTarget->RemoveAurasDueToSpell(SPELL_POSSESS);
                            possessedTarget->RemoveAurasDueToSpell(SPELL_POSSESSED);
                            possessedTarget->SetObjectScale(1.0f);
                            me->SetReactState(REACT_AGGRESSIVE);
                            me->SetVisible(true);
                            _invisible = false;
                            _events.ScheduleEvent(EVENT_SPELL_POSSESS, Seconds(20), Seconds(30));
                        }
                        break;
                    case EVENT_CHECK_POSSESSED:
                        if (_invisible)
                        {
                            if (Unit* possessedTarget = me->GetMap()->GetPlayer(_possessedTargetGuid))
                            {
                                if (!possessedTarget->HasAura(SPELL_POSSESSED) || possessedTarget->GetHealthPct() <= 50)
                                    _events.ScheduleEvent(EVENT_INVISIBLE, Seconds(0));
                                else
                                    _events.ScheduleEvent(EVENT_CHECK_POSSESSED, Seconds(1));
                            }
                        }
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

        protected:
            InstanceScript* instance;

        private:
            EventMap _events;
            bool _invisible;
            ObjectGuid _possessedTargetGuid;
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
