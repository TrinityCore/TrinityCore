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
 * Scripts for spells with SPELLFAMILY_PRIEST and SPELLFAMILY_GENERIC spells used by priest players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_pri_".
 */

#include "ScriptPCH.h"

enum PriestSpells
{
    PRIEST_SPELL_PENANCE_R1                      = 47540,
    PRIEST_SPELL_PENANCE_R1_DAMAGE               = 47758,
    PRIEST_SPELL_PENANCE_R1_HEAL                 = 47757,
    PRIEST_SPELL_PENANCE_R2                      = 53005,
    PRIEST_SPELL_PENANCE_R2_DAMAGE               = 53001,
    PRIEST_SPELL_PENANCE_R2_HEAL                 = 52986,
    PRIEST_SPELL_PENANCE_R3                      = 53006,
    PRIEST_SPELL_PENANCE_R3_DAMAGE               = 53002,
    PRIEST_SPELL_PENANCE_R3_HEAL                 = 52987,
    PRIEST_SPELL_PENANCE_R4                      = 53007,
    PRIEST_SPELL_PENANCE_R4_DAMAGE               = 53003,
    PRIEST_SPELL_PENANCE_R4_HEAL                 = 52988,
};

class spell_pri_penance_SpellScript : public SpellScript
{
    bool Validate(SpellEntry const * spellEntry)
    {
        if (!sSpellStore.LookupEntry(PRIEST_SPELL_PENANCE_R1))
            return false;
        if (!sSpellStore.LookupEntry(PRIEST_SPELL_PENANCE_R1_DAMAGE))
            return false;
        if (!sSpellStore.LookupEntry(PRIEST_SPELL_PENANCE_R1_HEAL))
            return false;

        if (!sSpellStore.LookupEntry(PRIEST_SPELL_PENANCE_R2))
            return false;
        if (!sSpellStore.LookupEntry(PRIEST_SPELL_PENANCE_R2_DAMAGE))
            return false;
        if (!sSpellStore.LookupEntry(PRIEST_SPELL_PENANCE_R2_HEAL))
            return false;

        if (!sSpellStore.LookupEntry(PRIEST_SPELL_PENANCE_R3))
            return false;
        if (!sSpellStore.LookupEntry(PRIEST_SPELL_PENANCE_R3_DAMAGE))
            return false;
        if (!sSpellStore.LookupEntry(PRIEST_SPELL_PENANCE_R3_HEAL))
            return false;

        if (!sSpellStore.LookupEntry(PRIEST_SPELL_PENANCE_R4))
            return false;
        if (!sSpellStore.LookupEntry(PRIEST_SPELL_PENANCE_R4_DAMAGE))
            return false;
        if (!sSpellStore.LookupEntry(PRIEST_SPELL_PENANCE_R4_HEAL))
            return false;

        return true;
    }

    void HandleDummy(SpellEffIndex effIndex)
    {
        Unit *unitTarget = GetHitUnit();
        if (!unitTarget || !unitTarget->isAlive())
            return;

        Unit *caster = GetCaster();
        SpellEntry const *spellInfo = GetSpellInfo();

        int hurt = 0;
        int heal = 0;
        switch(spellInfo->Id)
        {
            case PRIEST_SPELL_PENANCE_R1:
                hurt = PRIEST_SPELL_PENANCE_R1_DAMAGE;
                heal = PRIEST_SPELL_PENANCE_R1_HEAL;
                break;
            case PRIEST_SPELL_PENANCE_R2:
                hurt = PRIEST_SPELL_PENANCE_R2_DAMAGE;
                heal = PRIEST_SPELL_PENANCE_R2_HEAL;
                break;
            case PRIEST_SPELL_PENANCE_R3:
                hurt = PRIEST_SPELL_PENANCE_R3_DAMAGE;
                heal = PRIEST_SPELL_PENANCE_R3_HEAL;
                break;
            case PRIEST_SPELL_PENANCE_R4:
                hurt = PRIEST_SPELL_PENANCE_R4_DAMAGE;
                heal = PRIEST_SPELL_PENANCE_R4_HEAL;
                break;
            default:
                sLog.outError("spell_pri_penance_SpellScript::HandleDummy: Spell %u Penance need set correct heal/damage spell", spellInfo->Id);
                return;
        }

        if (caster->IsFriendlyTo(unitTarget))
            caster->CastSpell(unitTarget, heal, false, 0);
        else
            caster->CastSpell(unitTarget, hurt, false, 0);
    }

    void Register()
    {
        // add dummy effect spell handler to Penance
        EffectHandlers += EffectHandlerFn(spell_pri_penance_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

SpellScript *GetSpellScript_spell_pri_penance()
{
    return new spell_pri_penance_SpellScript();
}

void AddSC_priest_spell_scripts()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "spell_pri_penance";
    newscript->GetSpellScript = &GetSpellScript_spell_pri_penance;
    newscript->RegisterSelf();
}
