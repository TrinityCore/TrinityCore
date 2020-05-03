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
 * Scripts for spells with SPELLFAMILY_ROGUE and SPELLFAMILY_GENERIC spells used by rogue players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_rog_".
 */

#include "ScriptMgr.h"
#include "Containers.h"
#include "DB2Stores.h"
#include "Item.h"
#include "Log.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "SpellScript.h"

enum RogueSpells
{
    SPELL_ROGUE_BLADE_FLURRY                        = 13877,
    SPELL_ROGUE_BLADE_FLURRY_EXTRA_ATTACK           = 22482,
    SPELL_ROGUE_CHEAT_DEATH_COOLDOWN                = 31231,
    SPELL_ROGUE_CRIPPLING_POISON                    = 3409,
    SPELL_ROGUE_GLYPH_OF_PREPARATION                = 56819,
    SPELL_ROGUE_KILLING_SPREE                       = 51690,
    SPELL_ROGUE_KILLING_SPREE_TELEPORT              = 57840,
    SPELL_ROGUE_KILLING_SPREE_WEAPON_DMG            = 57841,
    SPELL_ROGUE_KILLING_SPREE_DMG_BUFF              = 61851,
    SPELL_ROGUE_MASTER_OF_SUBTLETY_DAMAGE_PERCENT   = 31665,
    SPELL_ROGUE_MASTER_OF_SUBTLETY_PASSIVE          = 31223,
    SPELL_ROGUE_SANCTUARY                           = 98877,
    SPELL_ROGUE_SHADOW_FOCUS                        = 108209,
    SPELL_ROGUE_SHADOW_FOCUS_EFFECT                 = 112942,
    SPELL_ROGUE_STEALTH                             = 1784,
    SPELL_ROGUE_STEALTH_STEALTH_AURA                = 158185,
    SPELL_ROGUE_STEALTH_SHAPESHIFT_AURA             = 158188,
    SPELL_ROGUE_VANISH_AURA                         = 11327,
    SPELL_ROGUE_PREY_ON_THE_WEAK                    = 58670,
    SPELL_ROGUE_SHIV_TRIGGERED                      = 5940,
    SPELL_ROGUE_TRICKS_OF_THE_TRADE_DMG_BOOST       = 57933,
    SPELL_ROGUE_TRICKS_OF_THE_TRADE_PROC            = 59628,
    SPELL_ROGUE_SERRATED_BLADES_R1                  = 14171,
    SPELL_ROGUE_RUPTURE                             = 1943,
    SPELL_ROGUE_HONOR_AMONG_THIEVES_ENERGIZE        = 51699,
    SPELL_ROGUE_T5_2P_SET_BONUS                     = 37169
};

// 13877, 33735, (check 51211, 65956) - Blade Flurry
class spell_rog_blade_flurry : public SpellScriptLoader
{
    public:
        spell_rog_blade_flurry() : SpellScriptLoader("spell_rog_blade_flurry") { }

        class spell_rog_blade_flurry_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_rog_blade_flurry_AuraScript);

        public:
            spell_rog_blade_flurry_AuraScript()
            {
                _procTarget = nullptr;
            }

        private:
            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_ROGUE_BLADE_FLURRY_EXTRA_ATTACK });
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                _procTarget = GetTarget()->SelectNearbyTarget(eventInfo.GetProcTarget());
                return _procTarget && eventInfo.GetDamageInfo();
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                if (DamageInfo* damageInfo = eventInfo.GetDamageInfo())
                {
                    int32 damage = damageInfo->GetDamage();
                    GetTarget()->CastCustomSpell(SPELL_ROGUE_BLADE_FLURRY_EXTRA_ATTACK, SPELLVALUE_BASE_POINT0, damage, _procTarget, true, nullptr, aurEff);
                }
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_rog_blade_flurry_AuraScript::CheckProc);
                if (m_scriptSpellId == SPELL_ROGUE_BLADE_FLURRY)
                    OnEffectProc += AuraEffectProcFn(spell_rog_blade_flurry_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_MOD_POWER_REGEN_PERCENT);
                else
                    OnEffectProc += AuraEffectProcFn(spell_rog_blade_flurry_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_MOD_MELEE_HASTE);
            }

        private:
            Unit* _procTarget;
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_rog_blade_flurry_AuraScript();
        }
};

// 31228 - Cheat Death
class spell_rog_cheat_death : public SpellScriptLoader
{
    public:
        spell_rog_cheat_death() : SpellScriptLoader("spell_rog_cheat_death") { }

        class spell_rog_cheat_death_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_rog_cheat_death_AuraScript);

        public:
            spell_rog_cheat_death_AuraScript()
            {
                absorbChance = 0;
            }

        private:
            uint32 absorbChance;

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_ROGUE_CHEAT_DEATH_COOLDOWN });
            }

            bool Load() override
            {
                // 6.x has basepoint = 0 !
                absorbChance = GetSpellInfo()->GetEffect(EFFECT_0)->CalcValue();
                return GetUnitOwner()->GetTypeId() == TYPEID_PLAYER;
            }

            void CalculateAmount(AuraEffect const* /*aurEff*/, int32 & amount, bool & /*canBeRecalculated*/)
            {
                // Set absorbtion amount to unlimited
                amount = -1;
            }

            void Absorb(AuraEffect* /*aurEff*/, DamageInfo & dmgInfo, uint32 & absorbAmount)
            {
                Player* target = GetTarget()->ToPlayer();
                if (dmgInfo.GetDamage() < target->GetHealth() || target->GetSpellHistory()->HasCooldown(SPELL_ROGUE_CHEAT_DEATH_COOLDOWN) || !roll_chance_i(absorbChance))
                    return;

                target->CastSpell(target, SPELL_ROGUE_CHEAT_DEATH_COOLDOWN, true);
                target->GetSpellHistory()->AddCooldown(SPELL_ROGUE_CHEAT_DEATH_COOLDOWN, 0, std::chrono::minutes(1));

                uint32 health10 = target->CountPctFromMaxHealth(10);

                // hp > 10% - absorb hp till 10%
                if (target->GetHealth() > health10)
                    absorbAmount = dmgInfo.GetDamage() - target->GetHealth() + health10;
                // hp lower than 10% - absorb everything
                else
                    absorbAmount = dmgInfo.GetDamage();
            }

            void Register() override
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_rog_cheat_death_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
                OnEffectAbsorb += AuraEffectAbsorbFn(spell_rog_cheat_death_AuraScript::Absorb, EFFECT_0);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_rog_cheat_death_AuraScript();
        }
};

// -51625 - Deadly Brew
class spell_rog_crippling_poison : public SpellScriptLoader
{
    public:
        spell_rog_crippling_poison() : SpellScriptLoader("spell_rog_crippling_poison") { }

        class spell_rog_crippling_poison_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_rog_crippling_poison_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_ROGUE_CRIPPLING_POISON });
            }

            void OnProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                GetTarget()->CastSpell(eventInfo.GetProcTarget(), SPELL_ROGUE_CRIPPLING_POISON, true, NULL, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_rog_crippling_poison_AuraScript::OnProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_rog_crippling_poison_AuraScript();
        }
};

// 2818 - Deadly Poison
class spell_rog_deadly_poison : public SpellScriptLoader
{
    public:
        spell_rog_deadly_poison() : SpellScriptLoader("spell_rog_deadly_poison") { }

        class spell_rog_deadly_poison_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_rog_deadly_poison_SpellScript);

        public:
            spell_rog_deadly_poison_SpellScript()
            {
                _stackAmount = 0;
            }

        private:
            bool Load() override
            {
                // at this point CastItem must already be initialized
                return GetCaster()->GetTypeId() == TYPEID_PLAYER && GetCastItem();
            }

            void HandleBeforeHit(SpellMissInfo missInfo)
            {
                if (missInfo != SPELL_MISS_NONE)
                    return;

                if (Unit* target = GetHitUnit())
                    // Deadly Poison
                    if (AuraEffect const* aurEff = target->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_ROGUE, flag128(0x10000, 0x80000, 0), GetCaster()->GetGUID()))
                        _stackAmount = aurEff->GetBase()->GetStackAmount();
            }

            void HandleAfterHit()
            {
                if (_stackAmount < 5)
                    return;

                Player* player = GetCaster()->ToPlayer();

                if (Unit* target = GetHitUnit())
                {

                    Item* item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);

                    if (item == GetCastItem())
                        item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);

                    if (!item)
                        return;

                    // item combat enchantments
                    for (uint8 slot = 0; slot < MAX_ENCHANTMENT_SLOT; ++slot)
                    {
                        SpellItemEnchantmentEntry const* enchant = sSpellItemEnchantmentStore.LookupEntry(item->GetEnchantmentId(EnchantmentSlot(slot)));
                        if (!enchant)
                            continue;

                        for (uint8 s = 0; s < 3; ++s)
                        {
                            if (enchant->Effect[s] != ITEM_ENCHANTMENT_TYPE_COMBAT_SPELL)
                                continue;

                            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(enchant->EffectArg[s]);
                            if (!spellInfo)
                            {
                                TC_LOG_ERROR("spells", "Player::CastItemCombatSpell Enchant %i, player (Name: %s, %s) cast unknown spell %i", enchant->ID, player->GetName().c_str(), player->GetGUID().ToString().c_str(), enchant->EffectArg[s]);
                                continue;
                            }

                            // Proc only rogue poisons
                            if (spellInfo->SpellFamilyName != SPELLFAMILY_ROGUE || spellInfo->Dispel != DISPEL_POISON)
                                continue;

                            // Do not reproc deadly
                            if (spellInfo->SpellFamilyFlags == flag128(0x10000, 0x80000, 0, 0))
                                continue;

                            if (spellInfo->IsPositive())
                                player->CastSpell(player, enchant->EffectArg[s], true, item);
                            else
                                player->CastSpell(target, enchant->EffectArg[s], true, item);
                        }
                    }
                }
            }

            void Register() override
            {
                BeforeHit += BeforeSpellHitFn(spell_rog_deadly_poison_SpellScript::HandleBeforeHit);
                AfterHit += SpellHitFn(spell_rog_deadly_poison_SpellScript::HandleAfterHit);
            }

            uint8 _stackAmount;
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_rog_deadly_poison_SpellScript();
        }
};

// 51690 - Killing Spree
class spell_rog_killing_spree : public SpellScriptLoader
{
    public:
        static char constexpr const ScriptName[] = "spell_rog_killing_spree";

        spell_rog_killing_spree() : SpellScriptLoader(ScriptName) { }

        class spell_rog_killing_spree_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_rog_killing_spree_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty() || GetCaster()->GetVehicleBase())
                    FinishCast(SPELL_FAILED_OUT_OF_RANGE);
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                if (Aura* aura = GetCaster()->GetAura(SPELL_ROGUE_KILLING_SPREE))
                    if (spell_rog_killing_spree_AuraScript* script = aura->GetScript<spell_rog_killing_spree_AuraScript>(ScriptName))
                        script->AddTarget(GetHitUnit());
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_rog_killing_spree_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_rog_killing_spree_SpellScript::HandleDummy, EFFECT_1, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_rog_killing_spree_SpellScript();
        }

        class spell_rog_killing_spree_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_rog_killing_spree_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                {
                    SPELL_ROGUE_KILLING_SPREE_TELEPORT,
                    SPELL_ROGUE_KILLING_SPREE_WEAPON_DMG,
                    SPELL_ROGUE_KILLING_SPREE_DMG_BUFF
                });
            }

            void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                GetTarget()->CastSpell(GetTarget(), SPELL_ROGUE_KILLING_SPREE_DMG_BUFF, true);
            }

            void HandleEffectPeriodic(AuraEffect const* /*aurEff*/)
            {
                while (!_targets.empty())
                {
                    ObjectGuid guid = Trinity::Containers::SelectRandomContainerElement(_targets);
                    if (Unit* target = ObjectAccessor::GetUnit(*GetTarget(), guid))
                    {
                        GetTarget()->CastSpell(target, SPELL_ROGUE_KILLING_SPREE_TELEPORT, true);
                        GetTarget()->CastSpell(target, SPELL_ROGUE_KILLING_SPREE_WEAPON_DMG, true);
                        break;
                    }
                    else
                        _targets.remove(guid);
                }
            }

            void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                GetTarget()->RemoveAurasDueToSpell(SPELL_ROGUE_KILLING_SPREE_DMG_BUFF);
            }

            void Register() override
            {
                AfterEffectApply += AuraEffectApplyFn(spell_rog_killing_spree_AuraScript::HandleApply, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_rog_killing_spree_AuraScript::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
                AfterEffectRemove += AuraEffectRemoveFn(spell_rog_killing_spree_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }

        public:
            void AddTarget(Unit* target)
            {
                _targets.push_back(target->GetGUID());
            }

        private:
            GuidList _targets;
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_rog_killing_spree_AuraScript();
        }
};
char constexpr const spell_rog_killing_spree::ScriptName[];

// 31666 - Master of Subtlety
class spell_rog_master_of_subtlety : public SpellScriptLoader
{
    public:
        spell_rog_master_of_subtlety() : SpellScriptLoader("spell_rog_master_of_subtlety") { }

        class spell_rog_master_of_subtlety_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_rog_master_of_subtlety_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_ROGUE_MASTER_OF_SUBTLETY_DAMAGE_PERCENT });
            }

            void HandleEffectPeriodic(AuraEffect const* /*aurEff*/)
            {
                Unit* target = GetTarget();

                if (!target->HasAuraType(SPELL_AURA_MOD_STEALTH))
                    target->RemoveAurasDueToSpell(SPELL_ROGUE_MASTER_OF_SUBTLETY_DAMAGE_PERCENT);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_rog_master_of_subtlety_AuraScript::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_rog_master_of_subtlety_AuraScript();
        }
};

// 14185 - Preparation
class spell_rog_preparation : public SpellScriptLoader
{
    public:
        spell_rog_preparation() : SpellScriptLoader("spell_rog_preparation") { }

        class spell_rog_preparation_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_rog_preparation_SpellScript);

            bool Load() override
            {
                return GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_ROGUE_GLYPH_OF_PREPARATION });
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                caster->GetSpellHistory()->ResetCooldowns([caster](SpellHistory::CooldownStorageType::iterator itr)
                {
                    SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(itr->first);
                    if (spellInfo->SpellFamilyName != SPELLFAMILY_ROGUE)
                        return false;

                    return (spellInfo->SpellFamilyFlags[1] & SPELLFAMILYFLAG1_ROGUE_SHADOWSTEP ||           // Shadowstep
                        spellInfo->SpellFamilyFlags[0] & SPELLFAMILYFLAG0_ROGUE_VAN_SPRINT) ||              // Vanish, Sprint
                        // Glyph of Preparation
                        (caster->HasAura(SPELL_ROGUE_GLYPH_OF_PREPARATION) &&
                        (spellInfo->SpellFamilyFlags[1] & SPELLFAMILYFLAG1_ROGUE_DISMANTLE_SMOKE_BOMB ||    // Dismantle, Smoke Bomb
                        spellInfo->SpellFamilyFlags[0] & SPELLFAMILYFLAG0_ROGUE_KICK));                     // Kick

                }, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_rog_preparation_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_rog_preparation_SpellScript();
        }
};

// 1943 - Rupture
class spell_rog_rupture : public SpellScriptLoader
{
    public:
        spell_rog_rupture() : SpellScriptLoader("spell_rog_rupture") { }

        class spell_rog_rupture_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_rog_rupture_AuraScript);

            bool Load() override
            {
                Unit* caster = GetCaster();
                return caster && caster->GetTypeId() == TYPEID_PLAYER;
            }

            void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& canBeRecalculated)
            {
                if (Unit* caster = GetCaster())
                {
                    canBeRecalculated = false;

                    float const attackpowerPerCombo[6] =
                    {
                        0.0f,
                        0.015f,         // 1 point:  ${($m1 + $b1*1 + 0.015 * $AP) * 4} damage over 8 secs
                        0.024f,         // 2 points: ${($m1 + $b1*2 + 0.024 * $AP) * 5} damage over 10 secs
                        0.03f,          // 3 points: ${($m1 + $b1*3 + 0.03 * $AP) * 6} damage over 12 secs
                        0.03428571f,    // 4 points: ${($m1 + $b1*4 + 0.03428571 * $AP) * 7} damage over 14 secs
                        0.0375f         // 5 points: ${($m1 + $b1*5 + 0.0375 * $AP) * 8} damage over 16 secs
                    };

                    uint32 cp = caster->ToPlayer()->GetComboPoints();
                    if (cp > 5)
                        cp = 5;

                    amount += int32(caster->GetTotalAttackPowerValue(BASE_ATTACK) * attackpowerPerCombo[cp]);
                }
            }

            void Register() override
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_rog_rupture_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_rog_rupture_AuraScript();
        }
};

// 5938 - Shiv
class spell_rog_shiv : public SpellScriptLoader
{
    public:
        spell_rog_shiv() : SpellScriptLoader("spell_rog_shiv") { }

        class spell_rog_shiv_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_rog_shiv_SpellScript);

            bool Load() override
            {
                return GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_ROGUE_SHIV_TRIGGERED });
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                if (Unit* unitTarget = GetHitUnit())
                    caster->CastSpell(unitTarget, SPELL_ROGUE_SHIV_TRIGGERED, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_rog_shiv_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_rog_shiv_SpellScript();
        }
};

// 1784 - Stealth
class spell_rog_stealth : public SpellScriptLoader
{
    public:
        spell_rog_stealth() : SpellScriptLoader("spell_rog_stealth") { }

        class spell_rog_stealth_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_rog_stealth_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                {
                    SPELL_ROGUE_MASTER_OF_SUBTLETY_PASSIVE,
                    SPELL_ROGUE_MASTER_OF_SUBTLETY_DAMAGE_PERCENT,
                    SPELL_ROGUE_SANCTUARY,
                    SPELL_ROGUE_SHADOW_FOCUS,
                    SPELL_ROGUE_SHADOW_FOCUS_EFFECT,
                    SPELL_ROGUE_STEALTH_STEALTH_AURA,
                    SPELL_ROGUE_STEALTH_SHAPESHIFT_AURA
                });
            }

            void HandleEffectApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();

                // Master of Subtlety
                if (target->HasAura(SPELL_ROGUE_MASTER_OF_SUBTLETY_PASSIVE))
                    target->CastSpell(target, SPELL_ROGUE_MASTER_OF_SUBTLETY_DAMAGE_PERCENT, TRIGGERED_FULL_MASK);

                // Shadow Focus
                if (target->HasAura(SPELL_ROGUE_SHADOW_FOCUS))
                    target->CastSpell(target, SPELL_ROGUE_SHADOW_FOCUS_EFFECT, TRIGGERED_FULL_MASK);

                target->CastSpell(target, SPELL_ROGUE_SANCTUARY, TRIGGERED_FULL_MASK);
                target->CastSpell(target, SPELL_ROGUE_STEALTH_STEALTH_AURA, TRIGGERED_FULL_MASK);
                target->CastSpell(target, SPELL_ROGUE_STEALTH_SHAPESHIFT_AURA, TRIGGERED_FULL_MASK);
            }

            void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();

                // Master of Subtlety
                if (AuraEffect* masterOfSubtletyPassive = GetTarget()->GetAuraEffect(SPELL_ROGUE_MASTER_OF_SUBTLETY_PASSIVE, EFFECT_0))
                {
                    if (Aura* masterOfSubtletyAura = GetTarget()->GetAura(SPELL_ROGUE_MASTER_OF_SUBTLETY_DAMAGE_PERCENT))
                    {
                        masterOfSubtletyAura->SetMaxDuration(masterOfSubtletyPassive->GetAmount());
                        masterOfSubtletyAura->RefreshDuration();
                    }
                }

                target->RemoveAurasDueToSpell(SPELL_ROGUE_SHADOW_FOCUS_EFFECT);
                target->RemoveAurasDueToSpell(SPELL_ROGUE_STEALTH_STEALTH_AURA);
                target->RemoveAurasDueToSpell(SPELL_ROGUE_STEALTH_SHAPESHIFT_AURA);
            }

            void Register() override
            {
                AfterEffectApply += AuraEffectApplyFn(spell_rog_stealth_AuraScript::HandleEffectApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove += AuraEffectRemoveFn(spell_rog_stealth_AuraScript::HandleEffectRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_rog_stealth_AuraScript();
        }
};

// 1856 - Vanish
class spell_rog_vanish : public SpellScriptLoader
{
    public:
        spell_rog_vanish() : SpellScriptLoader("spell_rog_vanish") { }

        class spell_rog_vanish_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_rog_vanish_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_ROGUE_VANISH_AURA, SPELL_ROGUE_STEALTH_SHAPESHIFT_AURA });
            }

            void OnLaunchTarget(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);

                Unit* target = GetHitUnit();

                target->RemoveMovementImpairingAuras(true);
                target->RemoveAurasByType(SPELL_AURA_MOD_STALKED);
                if (target->GetTypeId() != TYPEID_PLAYER)
                    return;

                if (target->HasAura(SPELL_ROGUE_VANISH_AURA))
                    return;

                target->CastSpell(target, SPELL_ROGUE_VANISH_AURA, TRIGGERED_FULL_MASK);
                target->CastSpell(target, SPELL_ROGUE_STEALTH_SHAPESHIFT_AURA, TRIGGERED_FULL_MASK);
            }

            void Register() override
            {
                OnEffectLaunchTarget += SpellEffectFn(spell_rog_vanish_SpellScript::OnLaunchTarget, EFFECT_1, SPELL_EFFECT_TRIGGER_SPELL);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_rog_vanish_SpellScript();
        }
};

// 11327 - Vanish
class spell_rog_vanish_aura : public SpellScriptLoader
{
    public:
        spell_rog_vanish_aura() : SpellScriptLoader("spell_rog_vanish_aura") { }

        class spell_rog_vanish_aura_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_rog_vanish_aura_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_ROGUE_STEALTH });
            }

            void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                GetTarget()->CastSpell(GetTarget(), SPELL_ROGUE_STEALTH, TRIGGERED_FULL_MASK);
            }

            void Register() override
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_rog_vanish_aura_AuraScript::HandleEffectRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_rog_vanish_aura_AuraScript();
        }
};

// 57934 - Tricks of the Trade
class spell_rog_tricks_of_the_trade : public SpellScriptLoader
{
    public:
        spell_rog_tricks_of_the_trade() : SpellScriptLoader("spell_rog_tricks_of_the_trade") { }

        class spell_rog_tricks_of_the_trade_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_rog_tricks_of_the_trade_AuraScript);

        public:
            spell_rog_tricks_of_the_trade_AuraScript()
            {
                _redirectTarget = nullptr;
            }

        private:
            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_ROGUE_TRICKS_OF_THE_TRADE_DMG_BOOST, SPELL_ROGUE_TRICKS_OF_THE_TRADE_PROC });
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_DEFAULT)
                    GetTarget()->ResetRedirectThreat();
            }

            bool CheckProc(ProcEventInfo& /*eventInfo*/)
            {
                _redirectTarget = GetTarget()->GetRedirectThreatTarget();
                return _redirectTarget != nullptr;
            }

            void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();

                Unit* target = GetTarget();
                target->CastSpell(_redirectTarget, SPELL_ROGUE_TRICKS_OF_THE_TRADE_DMG_BOOST, true);
                target->CastSpell(target, SPELL_ROGUE_TRICKS_OF_THE_TRADE_PROC, true);
                Remove(AURA_REMOVE_BY_DEFAULT); // maybe handle by proc charges
            }

            void Register() override
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_rog_tricks_of_the_trade_AuraScript::OnRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
                DoCheckProc += AuraCheckProcFn(spell_rog_tricks_of_the_trade_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_rog_tricks_of_the_trade_AuraScript::HandleProc, EFFECT_1, SPELL_AURA_DUMMY);
            }

        private:
            Unit* _redirectTarget;
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_rog_tricks_of_the_trade_AuraScript();
        }
};

// 59628 - Tricks of the Trade (Proc)
class spell_rog_tricks_of_the_trade_proc : public SpellScriptLoader
{
    public:
        spell_rog_tricks_of_the_trade_proc() : SpellScriptLoader("spell_rog_tricks_of_the_trade_proc") { }

        class spell_rog_tricks_of_the_trade_proc_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_rog_tricks_of_the_trade_proc_AuraScript);

            void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                GetTarget()->ResetRedirectThreat();
            }

            void Register() override
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_rog_tricks_of_the_trade_proc_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_rog_tricks_of_the_trade_proc_AuraScript();
        }
};

class spell_rog_serrated_blades : public SpellScriptLoader
{
public:
    spell_rog_serrated_blades() : SpellScriptLoader("spell_rog_serrated_blades") { }

    class spell_rog_serrated_blades_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_rog_serrated_blades_SpellScript);

        void HandleHit()
        {
            if (AuraEffect* blade = GetCaster()->GetAuraEffectOfRankedSpell(SPELL_ROGUE_SERRATED_BLADES_R1, EFFECT_0))
            {
                uint32 combo = GetCaster()->ToPlayer()->GetComboPoints();

                if (roll_chance_i(blade->GetAmount() * combo))
                    if (Aura* dot = GetHitUnit()->GetAura(SPELL_ROGUE_RUPTURE, GetCaster()->GetGUID()))
                        dot->RefreshDuration();

            }
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_rog_serrated_blades_SpellScript::HandleHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_rog_serrated_blades_SpellScript();
    }
};

// 198031 - Honor Among Thieves
/// 7.1.5
class spell_rog_honor_among_thieves : public SpellScriptLoader
{
public:
    spell_rog_honor_among_thieves() : SpellScriptLoader("spell_rog_honor_among_thieves") { }

    class spell_rog_honor_among_thieves_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_rog_honor_among_thieves_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo(
            {
                SPELL_ROGUE_HONOR_AMONG_THIEVES_ENERGIZE
            });
        }

        void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
        {
            PreventDefaultAction();

            Unit* target = GetTarget();
            target->CastSpell(target, SPELL_ROGUE_HONOR_AMONG_THIEVES_ENERGIZE, TRIGGERED_FULL_MASK, nullptr, aurEff);
        }

        void Register() override
        {
            OnEffectProc += AuraEffectProcFn(spell_rog_honor_among_thieves_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_rog_honor_among_thieves_AuraScript();
    }
};

// 196819 - Eviscerate
class spell_rog_eviscerate : public SpellScriptLoader
{
public:
    spell_rog_eviscerate() : SpellScriptLoader("spell_rog_eviscerate") { }

    class spell_rog_eviscerate_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_rog_eviscerate_SpellScript);

        void CalculateDamage(SpellEffIndex /*effIndex*/)
        {
            int32 damagePerCombo = GetHitDamage();
            if (AuraEffect const* t5 = GetCaster()->GetAuraEffect(SPELL_ROGUE_T5_2P_SET_BONUS, EFFECT_0))
                damagePerCombo += t5->GetAmount();

            int32 finalDamage = damagePerCombo;
            std::vector<SpellPowerCost> const& costs = GetSpell()->GetPowerCost();
            auto c = std::find_if(costs.begin(), costs.end(), [](SpellPowerCost const& cost) { return cost.Power == POWER_COMBO_POINTS; });
            if (c != costs.end())
                finalDamage *= c->Amount;

            SetHitDamage(finalDamage);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_rog_eviscerate_SpellScript::CalculateDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_rog_eviscerate_SpellScript();
    }
};

// 32645 - Envenom
class spell_rog_envenom : public SpellScriptLoader
{
public:
    spell_rog_envenom() : SpellScriptLoader("spell_rog_envenom") { }

    class spell_rog_envenom_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_rog_envenom_SpellScript);

        void CalculateDamage(SpellEffIndex /*effIndex*/)
        {
            int32 damagePerCombo = GetHitDamage();
            if (AuraEffect const* t5 = GetCaster()->GetAuraEffect(SPELL_ROGUE_T5_2P_SET_BONUS, EFFECT_0))
                damagePerCombo += t5->GetAmount();

            int32 finalDamage = damagePerCombo;
            std::vector<SpellPowerCost> const& costs = GetSpell()->GetPowerCost();
            auto c = std::find_if(costs.begin(), costs.end(), [](SpellPowerCost const& cost) { return cost.Power == POWER_COMBO_POINTS; });
            if (c != costs.end())
                finalDamage *= c->Amount;

            SetHitDamage(finalDamage);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_rog_envenom_SpellScript::CalculateDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_rog_envenom_SpellScript();
    }
};

void AddSC_rogue_spell_scripts()
{
    new spell_rog_blade_flurry();
    new spell_rog_cheat_death();
    new spell_rog_crippling_poison();
    new spell_rog_deadly_poison();
    new spell_rog_killing_spree();
    new spell_rog_master_of_subtlety();
    new spell_rog_preparation();
    new spell_rog_rupture();
    new spell_rog_shiv();
    new spell_rog_stealth();
    new spell_rog_vanish();
    new spell_rog_vanish_aura();
    new spell_rog_tricks_of_the_trade();
    new spell_rog_tricks_of_the_trade_proc();
    new spell_rog_serrated_blades();
    new spell_rog_honor_among_thieves();
    new spell_rog_eviscerate();
    new spell_rog_envenom();
}
