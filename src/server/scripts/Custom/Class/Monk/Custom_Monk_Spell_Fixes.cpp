/*
 * This file is part of the Stefal WoW Project.
 * It is designed to work exclusively with the TrinityCore framework.
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
 * This code is provided for personal and educational use within the
 * Stefal WoW Project. It is not intended for commercial distribution,
 * resale, or any form of monetization.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ScriptMgr.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "ObjectAccessor.h"
#include "Unit.h"
#include "CommonPredicates.h"

#include "Custom_Monk_Defines.h"

namespace Scripts::Custom::Monk
{
    // 115151 - Renewing Mist
    class spell_monk_renewing_mist : public SpellScript
    {
        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ Spells::RenewingMist });
        }

        void HandleDummy(SpellEffIndex /*effIndex*/) const
        {
            GetCaster()->CastSpell(GetHitUnit(), Spells::RenewingMist, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
                .TriggeringSpell = GetSpell()
                });
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_monk_renewing_mist::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    // 119611 - Renewing Mist (Heal)
    class spell_monk_renewing_mist_heal : public AuraScript
    {
        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ Spells::RenewingMistJump });
        }

        void HandlePeriodicHeal(AuraEffect const* aurEff) const
        {
            Unit* caster = GetCaster();
            Unit* target = GetTarget();
            if (!caster)
                return;

            if (target->IsFullHealth())
                caster->CastSpell(target, Spells::RenewingMistJump, CastSpellExtraArgsInit{
                    .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
                    .TriggeringAura = aurEff
                    });
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_monk_renewing_mist_heal::HandlePeriodicHeal, EFFECT_0, SPELL_AURA_PERIODIC_HEAL);
        }
    };

    // 119607 - Renewing Mist Jump
    class spell_monk_renewing_mist_jump : public SpellScript
    {
        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ Spells::RenewingMist });
        }

        void HandleTargets(std::list<WorldObject*>& targets)
        {
            Unit* previousTarget = GetExplTargetUnit();

            targets.remove_if([](WorldObject* object)
                {
                    Unit* ally = object->ToUnit();
                    if (!ally || ally->IsFullHealth())
                        return true;

                    return false;
                });

            if (targets.size() > 1)
            {
                targets.sort(Trinity::Predicates::HealthPctOrderPred());
                targets.resize(1);
            }

            _previousTargetGuid = previousTarget->GetGUID();
        }

        void HandleHit(SpellEffIndex /*effIndex*/) const
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            Unit* previousTarget = ObjectAccessor::GetUnit(*caster, _previousTargetGuid);

            if (previousTarget)
            {
                if (Aura* oldRenewingMist = previousTarget->GetAura(Spells::RenewingMist, caster->GetGUID()))
                    if (Aura* newRenewingMist = caster->AddAura(Spells::RenewingMist, target))
                    {
                        newRenewingMist->SetDuration(oldRenewingMist->GetDuration());
                        previousTarget->SendPlaySpellVisual(target, Spells::VisualRenewingMist, 0, 0, 50.0f);
                        oldRenewingMist->Remove();
                    }
            }
        }

    private:
        ObjectGuid _previousTargetGuid;

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_monk_renewing_mist_jump::HandleTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ALLY);
            OnEffectHitTarget += SpellEffectFn(spell_monk_renewing_mist_jump::HandleHit, EFFECT_1, SPELL_EFFECT_DUMMY);
        }
    };
}

void AddSC_custom_monk_spell_fixes()
{
    using namespace Scripts::Custom::Monk;

    RegisterSpellScript(spell_monk_renewing_mist);
    RegisterSpellScript(spell_monk_renewing_mist_heal);
    RegisterSpellScript(spell_monk_renewing_mist_jump);
}
