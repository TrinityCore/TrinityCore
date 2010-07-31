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
 * Scripts for spells with SPELLFAMILY_PALADIN and SPELLFAMILY_GENERIC spells used by paladin players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_pal_".
 */

#include "ScriptPCH.h"

enum PaladinSpells
{
    PALADIN_SPELL_HOLY_SHOCK_R1                  = 20473,
    PALADIN_SPELL_HOLY_SHOCK_R1_DAMAGE           = 25912,
    PALADIN_SPELL_HOLY_SHOCK_R1_HEALING          = 25914,
    PALADIN_SPELL_HOLY_SHOCK_R2                  = 20929,
    PALADIN_SPELL_HOLY_SHOCK_R2_DAMAGE           = 25911,
    PALADIN_SPELL_HOLY_SHOCK_R2_HEALING          = 25913,
    PALADIN_SPELL_HOLY_SHOCK_R3                  = 20930,
    PALADIN_SPELL_HOLY_SHOCK_R3_DAMAGE           = 25902,
    PALADIN_SPELL_HOLY_SHOCK_R3_HEALING          = 25903,
    PALADIN_SPELL_HOLY_SHOCK_R4                  = 27174,
    PALADIN_SPELL_HOLY_SHOCK_R4_DAMAGE           = 27176,
    PALADIN_SPELL_HOLY_SHOCK_R4_HEALING          = 27175,
    PALADIN_SPELL_HOLY_SHOCK_R5                  = 33072,
    PALADIN_SPELL_HOLY_SHOCK_R5_DAMAGE           = 33073,
    PALADIN_SPELL_HOLY_SHOCK_R5_HEALING          = 33074,
    PALADIN_SPELL_HOLY_SHOCK_R6                  = 48824,
    PALADIN_SPELL_HOLY_SHOCK_R6_DAMAGE           = 48822,
    PALADIN_SPELL_HOLY_SHOCK_R6_HEALING          = 48820,
    PALADIN_SPELL_HOLY_SHOCK_R7                  = 48825,
    PALADIN_SPELL_HOLY_SHOCK_R7_DAMAGE           = 48823,
    PALADIN_SPELL_HOLY_SHOCK_R7_HEALING          = 48821,

    SPELL_BLESSING_OF_LOWER_CITY_DRUID           = 37878,
    SPELL_BLESSING_OF_LOWER_CITY_PALADIN         = 37879,
    SPELL_BLESSING_OF_LOWER_CITY_PRIEST          = 37880,
    SPELL_BLESSING_OF_LOWER_CITY_SHAMAN          = 37881,
};

class spell_pal_blessing_of_faith_SpellScript : public SpellScript
{
    bool Validate(SpellEntry const * spellEntry)
    {
        if (!sSpellStore.LookupEntry(SPELL_BLESSING_OF_LOWER_CITY_DRUID))
            return false;
        if (!sSpellStore.LookupEntry(SPELL_BLESSING_OF_LOWER_CITY_PALADIN))
            return false;
        if (!sSpellStore.LookupEntry(SPELL_BLESSING_OF_LOWER_CITY_PRIEST))
            return false;
        if (!sSpellStore.LookupEntry(SPELL_BLESSING_OF_LOWER_CITY_SHAMAN))
            return false;
        return true;
    }

    void HandleDummy(SpellEffIndex effIndex)
    {
        if (Unit *unitTarget = GetHitUnit())
        {
            uint32 spell_id = 0;
            switch(unitTarget->getClass())
            {
                case CLASS_DRUID:   spell_id = SPELL_BLESSING_OF_LOWER_CITY_DRUID; break;
                case CLASS_PALADIN: spell_id = SPELL_BLESSING_OF_LOWER_CITY_PALADIN; break;
                case CLASS_PRIEST:  spell_id = SPELL_BLESSING_OF_LOWER_CITY_PRIEST; break;
                case CLASS_SHAMAN:  spell_id = SPELL_BLESSING_OF_LOWER_CITY_SHAMAN; break;
                default: return;                    // ignore for non-healing classes
            }

            GetCaster()->CastSpell(GetCaster(), spell_id, true);
        }
    }

    void Register()
    {
        // add dummy effect spell handler to Blessing of Faith
        EffectHandlers += EffectHandlerFn(spell_pal_blessing_of_faith_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

SpellScript * GetSpellScript_spell_pal_blessing_of_faith()
{
    return new spell_pal_blessing_of_faith_SpellScript();
}

class spell_pal_holy_shock_SpellScript : public SpellScript
{
    bool Validate(SpellEntry const * spellEntry)
    {
        if (!sSpellStore.LookupEntry(PALADIN_SPELL_HOLY_SHOCK_R1))
            return false;
        if (!sSpellStore.LookupEntry(PALADIN_SPELL_HOLY_SHOCK_R1_DAMAGE))
            return false;
        if (!sSpellStore.LookupEntry(PALADIN_SPELL_HOLY_SHOCK_R1_HEALING))
            return false;

        if (!sSpellStore.LookupEntry(PALADIN_SPELL_HOLY_SHOCK_R2))
            return false;
        if (!sSpellStore.LookupEntry(PALADIN_SPELL_HOLY_SHOCK_R2_DAMAGE))
            return false;
        if (!sSpellStore.LookupEntry(PALADIN_SPELL_HOLY_SHOCK_R2_HEALING))
            return false;

        if (!sSpellStore.LookupEntry(PALADIN_SPELL_HOLY_SHOCK_R3))
            return false;
        if (!sSpellStore.LookupEntry(PALADIN_SPELL_HOLY_SHOCK_R3_DAMAGE))
            return false;
        if (!sSpellStore.LookupEntry(PALADIN_SPELL_HOLY_SHOCK_R3_HEALING))
            return false;

        if (!sSpellStore.LookupEntry(PALADIN_SPELL_HOLY_SHOCK_R4))
            return false;
        if (!sSpellStore.LookupEntry(PALADIN_SPELL_HOLY_SHOCK_R4_DAMAGE))
            return false;
        if (!sSpellStore.LookupEntry(PALADIN_SPELL_HOLY_SHOCK_R4_HEALING))
            return false;

        if (!sSpellStore.LookupEntry(PALADIN_SPELL_HOLY_SHOCK_R5))
            return false;
        if (!sSpellStore.LookupEntry(PALADIN_SPELL_HOLY_SHOCK_R5_DAMAGE))
            return false;
        if (!sSpellStore.LookupEntry(PALADIN_SPELL_HOLY_SHOCK_R5_HEALING))
            return false;

        if (!sSpellStore.LookupEntry(PALADIN_SPELL_HOLY_SHOCK_R6))
            return false;
        if (!sSpellStore.LookupEntry(PALADIN_SPELL_HOLY_SHOCK_R6_DAMAGE))
            return false;
        if (!sSpellStore.LookupEntry(PALADIN_SPELL_HOLY_SHOCK_R6_HEALING))
            return false;

        if (!sSpellStore.LookupEntry(PALADIN_SPELL_HOLY_SHOCK_R7))
            return false;
        if (!sSpellStore.LookupEntry(PALADIN_SPELL_HOLY_SHOCK_R7_DAMAGE))
            return false;
        if (!sSpellStore.LookupEntry(PALADIN_SPELL_HOLY_SHOCK_R7_HEALING))
            return false;

        return true;
    }

    void HandleDummy(SpellEffIndex effIndex)
    {
        if (Unit *unitTarget = GetHitUnit())
        {
            Unit *caster = GetCaster();

            int hurt = 0;
            int heal = 0;

            switch(GetSpellInfo()->Id)
            {
                case PALADIN_SPELL_HOLY_SHOCK_R1:
                    hurt = PALADIN_SPELL_HOLY_SHOCK_R1_DAMAGE;
                    heal = PALADIN_SPELL_HOLY_SHOCK_R1_HEALING;
                    break;
                case PALADIN_SPELL_HOLY_SHOCK_R2:
                    hurt = PALADIN_SPELL_HOLY_SHOCK_R2_DAMAGE;
                    heal = PALADIN_SPELL_HOLY_SHOCK_R2_HEALING;
                    break;
                case PALADIN_SPELL_HOLY_SHOCK_R3:
                    hurt = PALADIN_SPELL_HOLY_SHOCK_R3_DAMAGE;
                    heal = PALADIN_SPELL_HOLY_SHOCK_R3_HEALING;
                    break;
                case PALADIN_SPELL_HOLY_SHOCK_R4:
                    hurt = PALADIN_SPELL_HOLY_SHOCK_R4_DAMAGE;
                    heal = PALADIN_SPELL_HOLY_SHOCK_R4_HEALING;
                    break;
                case PALADIN_SPELL_HOLY_SHOCK_R5:
                    hurt = PALADIN_SPELL_HOLY_SHOCK_R5_DAMAGE;
                    heal = PALADIN_SPELL_HOLY_SHOCK_R5_HEALING;
                    break;
                case PALADIN_SPELL_HOLY_SHOCK_R6:
                    hurt = PALADIN_SPELL_HOLY_SHOCK_R6_DAMAGE;
                    heal = PALADIN_SPELL_HOLY_SHOCK_R6_HEALING;
                    break;
                case PALADIN_SPELL_HOLY_SHOCK_R7:
                    hurt = PALADIN_SPELL_HOLY_SHOCK_R7_DAMAGE;
                    heal = PALADIN_SPELL_HOLY_SHOCK_R7_HEALING;
                    break;
                default:
                    sLog.outError("spell_pal_holy_shock_SpellScript::HandleDummy: Spell %u not handled in HS",GetSpellInfo()->Id);
                    return;
            }

            if (caster->IsFriendlyTo(unitTarget))
                caster->CastSpell(unitTarget, heal, true, 0);
            else
                caster->CastSpell(unitTarget, hurt, true, 0);
        }
    }

    void Register()
    {
        // add dummy effect spell handler to Holy Shock
        EffectHandlers += EffectHandlerFn(spell_pal_holy_shock_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

SpellScript * GetSpellScript_spell_pal_holy_shock()
{
    return new spell_pal_holy_shock_SpellScript();
}

class spell_pal_judgement_of_command_SpellScript : public SpellScript
{
    void HandleDummy(SpellEffIndex effIndex)
    {
        if (Unit *unitTarget = GetHitUnit())
            if (SpellEntry const* spell_proto = sSpellStore.LookupEntry(GetEffectValue()))
                GetCaster()->CastSpell(unitTarget, spell_proto, true, NULL);
    }

    void Register()
    {
        // add dummy effect spell handler to Judgement of Command
        EffectHandlers += EffectHandlerFn(spell_pal_judgement_of_command_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

SpellScript * GetSpellScript_spell_pal_judgement_of_command()
{
    return new spell_pal_judgement_of_command_SpellScript();
}

void AddSC_paladin_spell_scripts()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "spell_pal_blessing_of_faith";
    newscript->GetSpellScript = &GetSpellScript_spell_pal_blessing_of_faith;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "spell_pal_holy_shock";
    newscript->GetSpellScript = &GetSpellScript_spell_pal_holy_shock;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "spell_pal_judgement_of_command";
    newscript->GetSpellScript = &GetSpellScript_spell_pal_judgement_of_command;
    newscript->RegisterSelf();
}
