/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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
 * Scripts for spells with SPELLFAMILY_WARRIOR and SPELLFAMILY_GENERIC spells used by warrior players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_warr_".
 */

#include "ScriptPCH.h"

enum WarriorSpells
{
    WARRIOR_SPELL_LAST_STAND_TRIGGERED           = 12976,
    WARRIOR_SPELL_WARRIORS_WRATH_TRIGGERED       = 21887,
};

class spell_warr_last_stand_SpellScript : public SpellScript
{
    bool Validate(SpellEntry const *spellEntry)
    {
        if (!sSpellStore.LookupEntry(WARRIOR_SPELL_LAST_STAND_TRIGGERED))
            return false;
        return true;
    }

    void HandleDummy(SpellEffIndex effIndex)
    {
        int32 healthModSpellBasePoints0 = int32(GetCaster()->GetMaxHealth() * 0.3);
        GetCaster()->CastCustomSpell(GetCaster(), WARRIOR_SPELL_LAST_STAND_TRIGGERED, &healthModSpellBasePoints0, NULL, NULL, true, NULL);
    }

    void Register()
    {
        // add dummy effect spell handler to Last Stand
        EffectHandlers += EffectHandlerFn(spell_warr_last_stand_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

SpellScript * GetSpellScript_spell_warr_last_stand()
{
    return new spell_warr_last_stand_SpellScript();
}

class spell_warr_warriors_wrath_SpellScript : public SpellScript
{
    bool Validate(SpellEntry const *spellEntry)
    {
        if (!sSpellStore.LookupEntry(WARRIOR_SPELL_WARRIORS_WRATH_TRIGGERED))
            return false;
        return true;
    }

    void HandleDummy(SpellEffIndex effIndex)
    {
        if (Unit *unitTarget = GetHitUnit())
            GetCaster()->CastSpell(unitTarget, WARRIOR_SPELL_WARRIORS_WRATH_TRIGGERED, true);
    }

    void Register()
    {
        // add dummy effect spell handler to Warrior's Wrath
        EffectHandlers += EffectHandlerFn(spell_warr_warriors_wrath_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

SpellScript * GetSpellScript_spell_warr_warriors_wrath()
{
    return new spell_warr_warriors_wrath_SpellScript();
}

void AddSC_warrior_spell_scripts()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "spell_warr_last_stand";
    newscript->GetSpellScript = &GetSpellScript_spell_warr_last_stand;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "spell_warr_warriors_wrath";
    newscript->GetSpellScript = &GetSpellScript_spell_warr_warriors_wrath;
    newscript->RegisterSelf();
}
