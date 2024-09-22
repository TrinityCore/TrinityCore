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
 * Scripts for spells with SPELLFAMILY_DRUID and SPELLFAMILY_GENERIC spells used by druid players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_dru_".
 */

#include "ScriptMgr.h"
#include "SpellScript.h"
#include "SpellInfo.h"
#include "Unit.h"

namespace Scripts::Spells::Druid
{
    enum DruidSpells
    {
        SPELL_DRUID_ECLIPSE_ENERGY                      = 89265,
        SPELL_DRUID_STARSURGE_ENERGIZE                  = 86605,
        SPELL_DRUID_ECLIPSE_MARKER_0                    = 67483, // points towards Solar Power
        SPELL_DRUID_ECLIPSE_MARKER_1                    = 67484, // points towards Lunar Power
        SPELL_DRUID_ECLIPSE_SOLAR                       = 48517,
        SPELL_DRUID_ECLIPSE_LUNAR                       = 48518,
        SPELL_DRUID_ECLIPSE_SOLAR_OVERRIDE_ACTION_BAR   = 94338,
        SPELL_DRUID_SUNFIRE                             = 93402
    };

    namespace EclipseHelper
    {
        static void AwardEclipsePower(int32 effectValue, Unit* caster, bool solarPower, bool starsurge = false)
        {
            int32 energy = solarPower ? effectValue : -effectValue;

            if (starsurge)
            {
                if (caster->HasAura(SPELL_DRUID_ECLIPSE_MARKER_1, caster->GetGUID()))
                    energy *= -1;

                if (energy)
                    caster->CastSpell(nullptr, SPELL_DRUID_STARSURGE_ENERGIZE, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellBP0(energy));

                return;
            }

            if ((solarPower && caster->HasAura(SPELL_DRUID_ECLIPSE_MARKER_1, caster->GetGUID())) || (!solarPower && caster->HasAura(SPELL_DRUID_ECLIPSE_MARKER_0, caster->GetGUID())))
                energy = 0;

            if (energy)
                caster->CastSpell(nullptr, SPELL_DRUID_ECLIPSE_ENERGY, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellBP0(energy));
        }
    }

    // 5176 - Wrath
    class spell_dru_wrath : public SpellScript
    {
        bool Validate(SpellInfo const* spellInfo) override
        {
            return ValidateSpellEffect({ { spellInfo->Id, EFFECT_1 } });
        }

        void HandleEclipsePower(SpellEffIndex /*effIndex*/)
        {
            EclipseHelper::AwardEclipsePower(GetSpellInfo()->GetEffect(EFFECT_1).CalcValue(GetCaster()), GetCaster(), false);
        }

        void Register() override
        {
            OnEffectLaunchTarget += SpellEffectFn(spell_dru_wrath::HandleEclipsePower, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    // 2912 - Starfire
    class spell_dru_starfire : public SpellScript
    {
        bool Validate(SpellInfo const* spellInfo) override
        {
            return ValidateSpellEffect({ { spellInfo->Id, EFFECT_1 } });
        }

        void HandleEclipsePower(SpellEffIndex /*effIndex*/)
        {
            EclipseHelper::AwardEclipsePower(GetSpellInfo()->GetEffect(EFFECT_1).CalcValue(GetCaster()), GetCaster(), true);
        }

        void Register() override
        {
            OnEffectLaunchTarget += SpellEffectFn(spell_dru_starfire::HandleEclipsePower, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    // 78674 - Starsurge
    class spell_dru_starsurge : public SpellScript
    {
        bool Validate(SpellInfo const* spellInfo) override
        {
            return ValidateSpellEffect({ { spellInfo->Id, EFFECT_1 } });
        }

        void HandleEclipsePower(SpellEffIndex /*effIndex*/)
        {
            EclipseHelper::AwardEclipsePower(GetSpellInfo()->GetEffect(EFFECT_1).CalcValue(GetCaster()), GetCaster(), true, true);
        }

        void Register() override
        {
            OnEffectLaunchTarget += SpellEffectFn(spell_dru_starsurge::HandleEclipsePower, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    // 48517 - Eclipse (Solar)
    class spell_dru_eclipse_solar : public AuraScript
    {
        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo(
                {
                    SPELL_DRUID_ECLIPSE_SOLAR_OVERRIDE_ACTION_BAR,
                    SPELL_DRUID_SUNFIRE,
                    SPELL_DRUID_ECLIPSE_MARKER_0,
                    SPELL_DRUID_ECLIPSE_MARKER_1,
                });
        }

        void AfterApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
        {
            GetTarget()->CastSpell(nullptr, SPELL_DRUID_ECLIPSE_SOLAR_OVERRIDE_ACTION_BAR, CastSpellExtraArgs(aurEff).AddSpellBP0(SPELL_DRUID_SUNFIRE));

            GetTarget()->RemoveAurasDueToSpell(SPELL_DRUID_ECLIPSE_MARKER_0, GetCasterGUID());
            GetTarget()->CastSpell(nullptr, SPELL_DRUID_ECLIPSE_MARKER_1, aurEff);
        }

        void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            GetTarget()->RemoveAurasDueToSpell(SPELL_DRUID_ECLIPSE_SOLAR_OVERRIDE_ACTION_BAR, GetCasterGUID());
        }

        void Register() override
        {
            AfterEffectApply += AuraEffectApplyFn(spell_dru_eclipse_solar::AfterApply, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, AURA_EFFECT_HANDLE_REAL);
            AfterEffectRemove += AuraEffectApplyFn(spell_dru_eclipse_solar::AfterRemove, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, AURA_EFFECT_HANDLE_REAL);
        }
    };

    // 48518 - Eclipse (Lunar)
    class spell_dru_eclipse_lunar : public AuraScript
    {
        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo(
                {
                    SPELL_DRUID_ECLIPSE_MARKER_0,
                    SPELL_DRUID_ECLIPSE_MARKER_1,
                });
        }

        void AfterApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
        {
            GetTarget()->RemoveAurasDueToSpell(SPELL_DRUID_ECLIPSE_MARKER_1, GetCasterGUID());
            GetTarget()->CastSpell(nullptr, SPELL_DRUID_ECLIPSE_MARKER_0, aurEff);
        }

        void Register() override
        {
            AfterEffectApply += AuraEffectApplyFn(spell_dru_eclipse_lunar::AfterApply, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, AURA_EFFECT_HANDLE_REAL);
        }
    };

    // 79577 - Eclipse Mastery Driver Passive
    class spell_dru_eclipse_mastery_driver_passive : public AuraScript
    {
        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo(
                {
                    SPELL_DRUID_ECLIPSE_MARKER_0,
                    SPELL_DRUID_ECLIPSE_MARKER_1,
                });
        }

        void HandleEclipseRemoval(ProcEventInfo& /*eventInfo*/)
        {
            int32 power = GetTarget()->GetPower(POWER_BALANCE);

            if (power <= 0)
                GetTarget()->RemoveAurasDueToSpell(SPELL_DRUID_ECLIPSE_SOLAR, GetCasterGUID());
            else if (power >= 0)
                GetTarget()->RemoveAurasDueToSpell(SPELL_DRUID_ECLIPSE_LUNAR, GetCasterGUID());
        }

        void Register() override
        {
            AfterProc += AuraProcFn(spell_dru_eclipse_mastery_driver_passive::HandleEclipseRemoval);
        }
    };
}

void AddSC_druid_spell_scripts()
{
    using namespace Scripts::Spells::Druid;
    RegisterSpellScript(spell_dru_wrath);
    RegisterSpellScript(spell_dru_starfire);
    RegisterSpellScript(spell_dru_starsurge);
    RegisterSpellScript(spell_dru_eclipse_solar);
    RegisterSpellScript(spell_dru_eclipse_lunar);
    RegisterSpellScript(spell_dru_eclipse_mastery_driver_passive);
}
