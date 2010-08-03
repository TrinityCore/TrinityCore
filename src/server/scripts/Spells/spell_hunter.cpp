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
 * Scripts for spells with SPELLFAMILY_HUNTER, SPELLFAMILY_PET and SPELLFAMILY_GENERIC spells used by hunter players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_hun_".
 */

#include "ScriptPCH.h"

enum HunterSpells
{
    HUNTER_SPELL_READINESS                       = 23989,
    HUNTER_SPELL_BESTIAL_WRATH                   = 19574,
    HUNTER_PET_SPELL_LAST_STAND_TRIGGERED        = 53479,
    HUNTER_PET_HEART_OF_THE_PHOENIX              = 55709,
    HUNTER_PET_HEART_OF_THE_PHOENIX_TRIGGERED    = 54114,
    HUNTER_PET_HEART_OF_THE_PHOENIX_DEBUFF       = 55711,
};

class spell_hun_last_stand_pet_SpellScript : public SpellScript
{
    bool Validate(SpellEntry const * spellEntry)
    {
        if (!sSpellStore.LookupEntry(HUNTER_PET_SPELL_LAST_STAND_TRIGGERED))
            return false;
        return true;
    }

    void HandleDummy(SpellEffIndex effIndex)
    {
        Unit *caster = GetCaster();
        int32 healthModSpellBasePoints0 = int32(caster->GetMaxHealth()*0.3);
        caster->CastCustomSpell(caster, HUNTER_PET_SPELL_LAST_STAND_TRIGGERED, &healthModSpellBasePoints0, NULL, NULL, true, NULL);
    }

    void Register()
    {
        // add dummy effect spell handler to pet's Last Stand
        EffectHandlers += EffectHandlerFn(spell_hun_last_stand_pet_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

SpellScript * GetSpellScript_spell_hun_last_stand_pet()
{
    return new spell_hun_last_stand_pet_SpellScript();
}

class spell_hun_masters_call_SpellScript : public SpellScript
{
    void HandleDummy(SpellEffIndex effIndex)
    {
        Unit *caster = GetCaster();
        Unit *unitTarget = GetHitUnit();

        if (caster->GetTypeId() != TYPEID_PLAYER || !unitTarget)
            return;

        if (Pet *pet = caster->ToPlayer()->GetPet())
            if (pet->isAlive())
                pet->CastSpell(unitTarget, SpellMgr::CalculateSpellEffectAmount(GetSpellInfo(), effIndex), true);
    }

    void Register()
    {
        // add dummy effect spell handler to Master's Call
        EffectHandlers += EffectHandlerFn(spell_hun_masters_call_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

SpellScript * GetSpellScript_spell_hun_masters_call()
{
    return new spell_hun_masters_call_SpellScript();
}

class spell_hun_readiness_SpellScript : public SpellScript
{
    void HandleDummy(SpellEffIndex effIndex)
    {
        Unit *caster = GetCaster();
        if (caster->GetTypeId() != TYPEID_PLAYER)
            return;

        // immediately finishes the cooldown on your other Hunter abilities except Bestial Wrath
        const SpellCooldowns& cm = caster->ToPlayer()->GetSpellCooldownMap();
        for (SpellCooldowns::const_iterator itr = cm.begin(); itr != cm.end();)
        {
            SpellEntry const *spellInfo = sSpellStore.LookupEntry(itr->first);

            if (spellInfo->SpellFamilyName == SPELLFAMILY_HUNTER &&
                spellInfo->Id != HUNTER_SPELL_READINESS &&
                spellInfo->Id != HUNTER_SPELL_BESTIAL_WRATH &&
                GetSpellRecoveryTime(spellInfo) > 0)
                caster->ToPlayer()->RemoveSpellCooldown((itr++)->first,true);
            else
                ++itr;
        }
    }

    void Register()
    {
        // add dummy effect spell handler to Readiness
        EffectHandlers += EffectHandlerFn(spell_hun_readiness_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

SpellScript * GetSpellScript_spell_hun_readiness()
{
    return new spell_hun_readiness_SpellScript();
}

class spell_hun_pet_heart_of_the_phoenix : public SpellScript
{
    bool Validate(SpellEntry const * spellEntry)
    {
        if (!sSpellStore.LookupEntry(HUNTER_PET_HEART_OF_THE_PHOENIX_TRIGGERED))
            return false;
        if (!sSpellStore.LookupEntry(HUNTER_PET_HEART_OF_THE_PHOENIX_DEBUFF))
            return false;
        return true;
    }

    void HandleScript(SpellEffIndex effIndex)
    {
        Unit *caster = GetCaster();
        if (caster->HasAura(HUNTER_PET_HEART_OF_THE_PHOENIX_DEBUFF))
            return;
        caster->CastCustomSpell(HUNTER_PET_HEART_OF_THE_PHOENIX_TRIGGERED, SPELLVALUE_BASE_POINT0, 100, caster, true);
        caster->CastSpell(caster, HUNTER_PET_HEART_OF_THE_PHOENIX_DEBUFF, true);
    }

    void Register()
    {
        // add dummy effect spell handler to pet's Last Stand
        EffectHandlers += EffectHandlerFn(spell_hun_pet_heart_of_the_phoenix::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }

    bool Load()
    {
        if (!GetCaster()->isPet())
            return false;
        return true;
    }
};

SpellScript * GetSpellScript_spell_hun_pet_heart_of_the_phoenix()
{
    return new spell_hun_pet_heart_of_the_phoenix();
}

void AddSC_hunter_spell_scripts()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "spell_hun_last_stand_pet";
    newscript->GetSpellScript = &GetSpellScript_spell_hun_last_stand_pet;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "spell_hun_masters_call";
    newscript->GetSpellScript = &GetSpellScript_spell_hun_masters_call;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "spell_hun_readiness";
    newscript->GetSpellScript = &GetSpellScript_spell_hun_readiness;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "spell_hun_pet_heart_of_the_phoenix";
    newscript->GetSpellScript = &GetSpellScript_spell_hun_pet_heart_of_the_phoenix;
    newscript->RegisterSelf();
}
