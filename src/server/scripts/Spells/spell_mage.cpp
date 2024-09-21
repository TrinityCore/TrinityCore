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
 * Scripts for spells with SPELLFAMILY_MAGE and SPELLFAMILY_GENERIC spells used by mage players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_mage_".
 */

#include "ScriptMgr.h"
#include "Creature.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "Unit.h"

namespace Scripts::Spells::Mage
{
    enum MageSpells
    {
        SPELL_MAGE_ARCANE_MISSILES              = 5143,
        SPELL_MAGE_ARCANE_MISSILES_AURASTATE    = 79808
    };

    // 71761 - Deep Freeze Immunity State
    class spell_mage_deep_freeze_immunity_state : public AuraScript
    {
        bool CheckEffectProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
        {
            // Though the tooltip states that any target that is permanently stun immune can take damage, only creatures can actually achieve such a state
            // So we save ourselves some checks by filtering for creatures first
            if (!eventInfo.GetProcTarget() || !eventInfo.GetProcTarget()->IsCreature())
                return false;

            // We check for permanent immunities first by checking for a DB set immunities value.
            // If that check passes, we will check for the creature's current stun immunity to determine if we may proc or not.
            if (CreatureImmunities const* immunities = SpellMgr::GetCreatureImmunities(eventInfo.GetProcTarget()->ToCreature()->GetCreatureTemplate()->CreatureImmunitiesId))
                if ((immunities->Mechanic.to_ulong() & (1 << MECHANIC_STUN)) != 0)
                    if ((eventInfo.GetProcTarget()->GetMechanicImmunityMask() & (1 << MECHANIC_STUN)) != 0)
                        return true;

            return false;
        }

        void Register() override
        {
            DoCheckEffectProc += AuraCheckEffectProcFn(spell_mage_deep_freeze_immunity_state::CheckEffectProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
        }
    };

    // 79684 - Offensive State (DND)
    class spell_mage_offensive_state_dnd : public AuraScript
    {
        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_MAGE_ARCANE_MISSILES });
        }

        bool CheckEffectProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
        {
            // Only allow Arcane Missiles! to proc when the player has learned the according spell
            if (!GetTarget()->HasSpell(SPELL_MAGE_ARCANE_MISSILES))
                return false;

            // Arcane Missiles cannot trigger itself
            if ((eventInfo.GetSpellInfo()->SpellFamilyFlags[0] & (0x800 | 0x200000)) != 0)
                return false;

            return roll_chance_i(aurEff->GetAmount());
        }

        void Register() override
        {
            DoCheckEffectProc += AuraCheckEffectProcFn(spell_mage_offensive_state_dnd::CheckEffectProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
        }
    };

    // 79683 - Arcane Missiles!
    class spell_mage_arcane_missiles : public AuraScript
    {
        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_MAGE_ARCANE_MISSILES_AURASTATE });
        }

        void AfterApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
        {
            GetTarget()->CastSpell(nullptr, SPELL_MAGE_ARCANE_MISSILES_AURASTATE, aurEff);
        }

        void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            GetTarget()->RemoveAurasDueToSpell(SPELL_MAGE_ARCANE_MISSILES_AURASTATE, GetCasterGUID());
        }

        void Register() override
        {
            AfterEffectApply += AuraEffectApplyFn(spell_mage_arcane_missiles::AfterApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            AfterEffectRemove += AuraEffectApplyFn(spell_mage_arcane_missiles::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };
}

void AddSC_mage_spell_scripts()
{
    using namespace Scripts::Spells::Mage;
    RegisterSpellScript(spell_mage_deep_freeze_immunity_state);
    RegisterSpellScript(spell_mage_offensive_state_dnd);
    RegisterSpellScript(spell_mage_arcane_missiles);
}
