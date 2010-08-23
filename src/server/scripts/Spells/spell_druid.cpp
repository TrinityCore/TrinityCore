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
 * Scripts for spells with SPELLFAMILY_DRUID and SPELLFAMILY_GENERIC spells used by druid players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_dru_".
 */

#include "ScriptPCH.h"
#include "SpellAuraEffects.h"

enum DruidSpells
{
    DRUID_INCREASED_MOONFIRE_DURATION   = 38414,
    DRUID_NATURES_SPLENDOR              = 57865
};

// 54846 Glyph of Starfire
class spell_dru_glyph_of_starfire : public SpellHandlerScript
{
public:
    spell_dru_glyph_of_starfire() : SpellHandlerScript("spell_dru_glyph_of_starfire") { }

    class spell_dru_glyph_of_starfire_SpellScript : public SpellScript
    {
        bool Validate(SpellEntry const * /*spellEntry*/)
        {
            if (!sSpellStore.LookupEntry(DRUID_INCREASED_MOONFIRE_DURATION))
                return false;
            if (!sSpellStore.LookupEntry(DRUID_NATURES_SPLENDOR))
                return false;
            return true;
        }

        void HandleScriptEffect(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            if (Unit* unitTarget = GetHitUnit())
                if (AuraEffect const * aurEff = unitTarget->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE,SPELLFAMILY_DRUID, 0x00000002, 0, 0, caster->GetGUID()))
                {
                    Aura* aura = aurEff->GetBase();

                    uint32 countMin = aura->GetMaxDuration();
                    uint32 countMax = 18000;
                    if (caster->HasAura(DRUID_INCREASED_MOONFIRE_DURATION))
                        countMax += 3000;
                    if (caster->HasAura(DRUID_NATURES_SPLENDOR))
                        countMax += 3000;

                    if (countMin < countMax)
                    {
                        aura->SetDuration(uint32(aura->GetDuration() + 3000));
                        aura->SetMaxDuration(countMin + 3000);
                    }
                }
        }

        void Register()
        {
            EffectHandlers += EffectHandlerFn(spell_dru_glyph_of_starfire_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_dru_glyph_of_starfire_SpellScript();
    }
};

void AddSC_druid_spell_scripts()
{
    new spell_dru_glyph_of_starfire();
}
