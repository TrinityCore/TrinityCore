/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
#include "mana_tombs.h"

enum Texts
{
    SAY_AGGRO                       = 0,
    SAY_KILL                        = 1,
    SAY_DEATH                       = 2,
    EMOTE_DARK_SHELL                = 3
};

enum Spells
{
    SPELL_VOID_BLAST = 32325,
    SPELL_DARK_SHELL = 32358
};

enum Events
{
    EVENT_VOID_BLAST = 1,
    EVENT_DARK_SHELL
};


class boss_pandemonius : public CreatureScript
{
public:
    boss_pandemonius() : CreatureScript("boss_pandemonius") { }

    struct boss_pandemoniusAI : public BossAI
    {
        boss_pandemoniusAI(Creature* creature) : BossAI(creature, DATA_PANDEMONIUS)
        {
            VoidBlastCounter = 0;
        }

        void Reset() override
        {
            _Reset();
            VoidBlastCounter = 0;
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);
        }

        void KilledUnit(Unit* /*victim*/) override
        {
            Talk(SAY_KILL);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();
            Talk(SAY_AGGRO);
            events.ScheduleEvent(EVENT_DARK_SHELL, 20000);
            events.ScheduleEvent(EVENT_VOID_BLAST, urand(8000, 23000));
        }

        void ExecuteEvent(uint32 eventId) override
        {
            switch (eventId)
            {
                case EVENT_VOID_BLAST:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    {
                        DoCast(target, SPELL_VOID_BLAST);
                        ++VoidBlastCounter;
                    }

                    if (VoidBlastCounter == 5)
                    {
                        VoidBlastCounter = 0;
                        events.ScheduleEvent(EVENT_VOID_BLAST, urand(15000, 25000));
                    }
                    else
                    {
                        events.ScheduleEvent(EVENT_VOID_BLAST, 500);
                        events.DelayEvents(EVENT_DARK_SHELL, 500);
                    }
                    break;
                case EVENT_DARK_SHELL:
                    if (me->IsNonMeleeSpellCast(false))
                        me->InterruptNonMeleeSpells(true);
                    Talk(EMOTE_DARK_SHELL);
                    DoCast(me, SPELL_DARK_SHELL);
                    events.ScheduleEvent(EVENT_DARK_SHELL, 20000);
                    break;
                default:
                    break;
            }
        }

        private:
            uint32 VoidBlastCounter;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetManaTombsAI<boss_pandemoniusAI>(creature);
    }
};

void AddSC_boss_pandemonius()
{
    new boss_pandemonius();
}
