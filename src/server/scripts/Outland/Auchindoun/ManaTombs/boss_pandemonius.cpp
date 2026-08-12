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
 * Is Dark Shell cast really delayed? Currently we have to delay it to not interrupt Void Blast sequence
 * Spell 32326 is NYI. Not sure what it does. Don't know if it is used or not
 */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "Spell.h"
#include "SpellScript.h"
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
    SPELL_DARK_SHELL          = 32358
};

enum PandemoniusEvents
{
    EVENT_VOID_BLAST          = 1,
    EVENT_DARK_SHELL,

    DARK_SHELL_EVENT_GROUP
};

// 18341 - Pandemonius
struct boss_pandemonius : public BossAI
{
    boss_pandemonius(Creature* creature) : BossAI(creature, DATA_PANDEMONIUS) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        Talk(SAY_AGGRO);

        events.ScheduleEvent(EVENT_VOID_BLAST, 10s, 25s);
        events.ScheduleEvent(EVENT_DARK_SHELL, 15s, 20s, DARK_SHELL_EVENT_GROUP);
    }

    void OnSpellStart(SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == sSpellMgr->GetSpellIdForDifficulty(SPELL_DARK_SHELL, me))
            Talk(EMOTE_DARK_SHELL);
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_VOID_BLAST:
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.0f))
                    DoCast(target, SPELL_VOID_BLAST);
                events.Repeat(25s, 35s);
                events.DelayEvents(2500ms, DARK_SHELL_EVENT_GROUP);
                break;
            case EVENT_DARK_SHELL:
                DoCastSelf(SPELL_DARK_SHELL);
                events.Repeat(20s, 30s);
                break;
            default:
                break;
        }
    }
};

// 32325, 38760 - Void Blast
class spell_pandemonius_void_blast : public SpellScript
{
    PrepareSpellScript(spell_pandemonius_void_blast);

    void TriggerNext()
    {
        int32 castIndex = GetCastIndex();
        if (castIndex >= 4)
            return;

        if (Creature* caster = GetCaster()->ToCreature())
            if (Unit* target = caster->AI()->SelectTarget(SelectTargetMethod::Random, 0, 100.0f))
                caster->CastSpell(target, GetSpellInfo()->Id, CastSpellExtraArgs()
                    .AddSpellMod(SPELLVALUE_BASE_POINT2, castIndex + 1));
    }

    int32 GetCastIndex() const
    {
        // We are storing number of casts in a non-effect SPELLVALUE_BASE_POINT2
        return GetSpellValue()->EffectBasePoints[EFFECT_2];
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_pandemonius_void_blast::TriggerNext);
    }
};

void AddSC_boss_pandemonius()
{
    RegisterManaTombsCreatureAI(boss_pandemonius);
    RegisterSpellScript(spell_pandemonius_void_blast);
}
