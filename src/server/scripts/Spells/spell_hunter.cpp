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
 * Scripts for spells with SPELLFAMILY_HUNTER, SPELLFAMILY_PET and SPELLFAMILY_GENERIC spells used by hunter players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_hun_".
 */

#include "ScriptMgr.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "Unit.h"

namespace Scripts::Spells::Hunter
{
    enum HunterSpells
    {
        SPELL_HUN_IMPROVED_STEADY_SHOT_TRIGGERED = 53220
    };

    enum HunterSpellFamilies
    {
        SPELL_FAMILY_HUN_STEADY_SHOT = 0x1
    };

    // -53221 - Improved Steady Shot
    class spell_hun_improved_steady_shot : public AuraScript
    {
        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_HUN_IMPROVED_STEADY_SHOT_TRIGGERED });
        }

        // If a ranged spell with spell_family_hunter is being cast, check if it's a steady shot ability. If not, reset the counter back to zero
        bool CheckEffectProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
        {
            if (!eventInfo.GetSpellInfo() || eventInfo.GetSpellInfo()->IsAutoRepeatRangedSpell() || !eventInfo.GetSpellInfo()->IsRangedWeaponSpell())
                return false;

            if (!eventInfo.GetSpellInfo()->SpellFamilyFlags.HasFlag(0, SPELL_FAMILY_HUN_STEADY_SHOT, 0, 0))
            {
                _steadyShotCount = 0;
                return false;
            }

            return true;
        }

        // Increment the steady shot counter. If the counter is at 2 or higher, trigger the haste bonus spell cast and reset the counter back to zero
        void HandleEffectProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
        {
            ++_steadyShotCount;
            if (_steadyShotCount >= 2)
            {
                eventInfo.GetActor()->CastSpell(nullptr, SPELL_HUN_IMPROVED_STEADY_SHOT_TRIGGERED, CastSpellExtraArgs(TRIGGERED_FULL_MASK)
                    .SetTriggeringAura(aurEff)
                    .AddSpellBP0(aurEff->GetAmount()));

                _steadyShotCount = 0;
            }
        }

        void Register() override
        {
            DoCheckEffectProc += AuraCheckEffectProcFn(spell_hun_improved_steady_shot::CheckEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
            OnEffectProc += AuraEffectProcFn(spell_hun_improved_steady_shot::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
        }

    private:
        uint8 _steadyShotCount = 0;
    };
}

void AddSC_hunter_spell_scripts()
{
    using namespace Scripts::Spells::Hunter;
    RegisterSpellScript(spell_hun_improved_steady_shot);
}
