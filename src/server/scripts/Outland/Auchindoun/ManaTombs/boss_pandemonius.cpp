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

/*
 * Timers requires to be revisited
 * Is Dark Shell cast really delayed?
 */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "mana_tombs.h"

enum PandemoniusTexts
{
    SAY_AGGRO                 = 0,
    SAY_SLAY                  = 1,
    SAY_DEATH                 = 2,
    EMOTE_DARK_SHELL          = 3
};

enum PandemoniusSpells
{
    SPELL_VOID_BLAST          = 32325,
    SPELL_VOID_BLAST_SCRIPT   = 32326,    // NYI. Is it used? What it does?
    SPELL_DARK_SHELL          = 32358
};

enum PandemoniusEvents
{
    EVENT_VOID_BLAST          = 1,
    EVENT_DARK_SHELL
};

uint32 constexpr DARK_SHELL_EVENT_GROUP = 1;

// 18341 - Pandemonius
struct boss_pandemonius : public BossAI
{
    boss_pandemonius(Creature* creature) : BossAI(creature, DATA_PANDEMONIUS), _voidBlastCounter(0) { }

    void Reset() override
    {
        _Reset();
        _voidBlastCounter = 0;
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
        events.ScheduleEvent(EVENT_DARK_SHELL, 20s, DARK_SHELL_EVENT_GROUP);
        events.ScheduleEvent(EVENT_VOID_BLAST, 8s, 23s);
    }

    void OnSpellStart(SpellInfo const* spell) override
    {
        if (spell->Id == sSpellMgr->GetSpellIdForDifficulty(SPELL_DARK_SHELL, me))
            Talk(EMOTE_DARK_SHELL);
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_DEATH);
        _JustDied();
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_VOID_BLAST:
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.0f, true))
                {
                    DoCast(target, SPELL_VOID_BLAST);
                    ++_voidBlastCounter;
                }

                if (_voidBlastCounter == 5)
                {
                    _voidBlastCounter = 0;
                    events.ScheduleEvent(EVENT_VOID_BLAST, 15s, 25s);
                }
                else
                {
                    events.ScheduleEvent(EVENT_VOID_BLAST, 500ms);
                    events.DelayEvents(500ms, DARK_SHELL_EVENT_GROUP);
                }
                break;
            case EVENT_DARK_SHELL:
                DoCastSelf(SPELL_DARK_SHELL);
                events.ScheduleEvent(EVENT_DARK_SHELL, 20s, DARK_SHELL_EVENT_GROUP);
                break;
            default:
                break;
        }
    }

private:
    uint32 _voidBlastCounter;
};

void AddSC_boss_pandemonius()
{
    RegisterManaTombsCreatureAI(boss_pandemonius);
}
