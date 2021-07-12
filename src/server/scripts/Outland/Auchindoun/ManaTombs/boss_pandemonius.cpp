/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

uint32 constexpr DARK_SHELL_EVENT_GROUP = 1;

struct boss_pandemonius : public BossAI
{
    boss_pandemonius(Creature* creature) : BossAI(creature, DATA_PANDEMONIUS)
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

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
        events.ScheduleEvent(EVENT_DARK_SHELL, 20s, DARK_SHELL_EVENT_GROUP);
        events.ScheduleEvent(EVENT_VOID_BLAST, 8s, 23s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_VOID_BLAST:
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.0f, true))
                {
                    DoCast(target, SPELL_VOID_BLAST);
                    ++VoidBlastCounter;
                }

                if (VoidBlastCounter == 5)
                {
                    VoidBlastCounter = 0;
                    events.ScheduleEvent(EVENT_VOID_BLAST, 15s, 25s);
                }
                else
                {
                    events.ScheduleEvent(EVENT_VOID_BLAST, 500ms);
                    events.DelayEvents(500ms, DARK_SHELL_EVENT_GROUP);
                }
                break;
            case EVENT_DARK_SHELL:
                if (me->IsNonMeleeSpellCast(false))
                    me->InterruptNonMeleeSpells(true);
                Talk(EMOTE_DARK_SHELL);
                DoCast(me, SPELL_DARK_SHELL);
                events.ScheduleEvent(EVENT_DARK_SHELL, 20s, DARK_SHELL_EVENT_GROUP);
                break;
            default:
                break;
        }
    }

    private:
        uint32 VoidBlastCounter;
};

void AddSC_boss_pandemonius()
{
    RegisterManaTombsCreatureAI(boss_pandemonius);
}
