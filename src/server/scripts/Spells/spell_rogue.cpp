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
#include "DBCStores.h"
#include "Item.h"
#include "Log.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "SpellScript.h"

enum RogueSpells
{
    SPELL_ROGUE_ADRENALIN_RUSH                      = 13750,
    SPELL_ROGUE_BANDITS_GUILE                       = 84748,
    SPELL_ROGUE_BLADE_FLURRY                        = 13877,
    SPELL_ROGUE_BLADE_FLURRY_EXTRA_ATTACK           = 22482,
    SPELL_ROGUE_CHEAT_DEATH_COOLDOWN                = 31231,
    SPELL_ROGUE_CRIPPLING_POISON                    = 3409,
    SPELL_ROGUE_DEEP_INSIGHT                        = 84747,
    SPELL_ROGUE_ENERGETIC_RECOVERY                  = 4893,
    SPELL_ROGUE_EVISCERATE_AND_ENVENOM_BONUS_DAMAGE = 37169,
    SPELL_ROGUE_EXPOSE_ARMOR                        = 8647,
    SPELL_ROGUE_GLYPH_OF_PREPARATION                = 56819,
    SPELL_ROGUE_GLYPH_HEMORRHAGE_TRIGGERED          = 89775,
    SPELL_ROGUE_IMPROVED_EXPOSE_ARMOR               = 79128,
    SPELL_ROGUE_KILLING_SPREE                       = 51690,
    SPELL_ROGUE_KILLING_SPREE_TELEPORT              = 57840,
    SPELL_ROGUE_KILLING_SPREE_WEAPON_DMG            = 57841,
    SPELL_ROGUE_KILLING_SPREE_DMG_BUFF              = 61851,
    SPELL_ROGUE_MAIN_GAUCHE                         = 86392,
    SPELL_ROGUE_MASTER_OF_SUBTLETY_DAMAGE_PERCENT   = 31665,
    SPELL_ROGUE_MASTER_OF_SUBTLETY_PASSIVE          = 31223,
    SPELL_ROGUE_MASTER_OF_SUBTLETY_PERIODIC         = 31666,
    SPELL_ROGUE_MODERATE_INSIGHT                    = 84746,
    SPELL_ROGUE_MURDEROUS_INTENT                    = 79132,
    SPELL_ROGUE_OVERKILL_TALENT                     = 58426,
    SPELL_ROGUE_OVERKILL_PERIODIC                   = 58428,
    SPELL_ROGUE_OVERKILL_POWER_REGEN                = 58427,
    SPELL_ROGUE_PREY_ON_THE_WEAK                    = 58670,
    SPELL_ROGUE_REVEALING_STRIKE                    = 84617,
    SPELL_ROGUE_REDIRECT                            = 73981,
    SPELL_ROGUE_SHALLOW_INSIGHT                     = 84745,
    SPELL_ROGUE_SHIV_TRIGGERED                      = 5940,
    SPELL_ROGUE_SILCE_AND_DICE                      = 5171,
    SPELL_ROGUE_SPRINT                              = 2983,
    SPELL_ROGUE_TRICKS_OF_THE_TRADE_DMG_BOOST       = 57933,
    SPELL_ROGUE_TRICKS_OF_THE_TRADE_PROC            = 59628,
    SPELL_ROGUE_SERRATED_BLADES_R1                  = 14171,
    SPELL_ROGUE_RUPTURE                             = 1943,
    SPELL_ROGUE_HONOR_AMONG_THIEVES_TRIGGERED       = 51699,
    SPELL_ROGUE_BLACKJACK_R1                        = 79123
};

enum RogueSpellIcons
{
    ICON_ROGUE_IMPROVED_RECUPERATE                  = 4819,
    ROGUE_ICON_ID_SERRATED_BLADES                   = 2004
};

// 13877, 33735, (check 51211, 65956) - Blade Flurry
class spell_rog_blade_flurry : public SpellScriptLoader
{
    public:
        spell_rog_blade_flurry() : SpellScriptLoader("spell_rog_blade_flurry") { }

        class spell_rog_blade_flurry_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_rog_blade_flurry_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_ROGUE_BLADE_FLURRY_EXTRA_ATTACK });
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                if (DamageInfo* damageInfo = eventInfo.GetDamageInfo())
                    if (Unit* procTarget = damageInfo->GetVictim())
                        if (Unit* target = GetTarget()->SelectNearbyTarget(procTarget, GetTarget()->GetFloatValue(UNIT_FIELD_COMBATREACH)))
                            GetTarget()->CastCustomSpell(SPELL_ROGUE_BLADE_FLURRY_EXTRA_ATTACK, SPELLVALUE_BASE_POINT0, damageInfo->GetDamage(), target, true, nullptr, aurEff);
            }

            void Register() override
            {
                if (m_scriptSpellId == SPELL_ROGUE_BLADE_FLURRY)
                    OnEffectProc += AuraEffectProcFn(spell_rog_blade_flurry_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_MOD_POWER_REGEN_PERCENT);
                else
                    OnEffectProc += AuraEffectProcFn(spell_rog_blade_flurry_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_MOD_MELEE_HASTE);
            }
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

            uint32 absorbChance = 0;

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_ROGUE_CHEAT_DEATH_COOLDOWN });
            }

            bool Load() override
            {
                absorbChance = GetSpellInfo()->Effects[EFFECT_0].CalcValue();
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
                GetTarget()->CastSpell(eventInfo.GetProcTarget(), SPELL_ROGUE_CRIPPLING_POISON, true, nullptr, aurEff);
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

// -51664 - Cut to the Chase
class spell_rog_cut_to_the_chase : public SpellScriptLoader
{
    public:
        spell_rog_cut_to_the_chase () : SpellScriptLoader("spell_rog_cut_to_the_chase") { }

        class spell_rog_cut_to_the_chase_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_rog_cut_to_the_chase_AuraScript);

            void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                if (Aura* aur = GetTarget()->GetAura(SPELL_ROGUE_SILCE_AND_DICE))
                    aur->SetDuration(aur->GetSpellInfo()->GetMaxDuration(), true);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_rog_cut_to_the_chase_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_rog_cut_to_the_chase_AuraScript();
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

            bool Load() override
            {
                // at this point CastItem must already be initialized
                return GetCaster()->GetTypeId() == TYPEID_PLAYER && GetCastItem();
            }

            void HandleBeforeHit()
            {
                if (Unit* target = GetHitUnit())
                    // Deadly Poison
                    if (AuraEffect const* aurEff = target->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_ROGUE, 0x10000, 0x80000, 0, GetCaster()->GetGUID()))
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
                        if (slot > PRISMATIC_ENCHANTMENT_SLOT && slot < PROP_ENCHANTMENT_SLOT_0)    // not holding enchantment id
                            continue;

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
                                TC_LOG_ERROR("spells", "Player::CastItemCombatSpell Enchant %i, player (Name: %s, GUID: %u) cast unknown spell %i", enchant->ID, player->GetName().c_str(), player->GetGUID().GetCounter(), enchant->EffectArg[s]);
                                continue;
                            }

                            // Proc only rogue poisons
                            if (spellInfo->SpellFamilyName != SPELLFAMILY_ROGUE || spellInfo->Dispel != DISPEL_POISON)
                                continue;

                            // Do not reproc deadly
                            if (spellInfo->SpellFamilyFlags.IsEqual(0x10000, 0x80000, 0))
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
                BeforeHit += SpellHitFn(spell_rog_deadly_poison_SpellScript::HandleBeforeHit);
                AfterHit += SpellHitFn(spell_rog_deadly_poison_SpellScript::HandleAfterHit);
            }

            uint8 _stackAmount = 0;
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

// 31130 - Nerves of Steel
class spell_rog_nerves_of_steel : public SpellScriptLoader
{
    public:
        spell_rog_nerves_of_steel() : SpellScriptLoader("spell_rog_nerves_of_steel") { }

        class spell_rog_nerves_of_steel_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_rog_nerves_of_steel_AuraScript);

        public:
            spell_rog_nerves_of_steel_AuraScript()
            {
                absorbPct = 0;
            }

        private:
            uint32 absorbPct;

            bool Load() override
            {
                absorbPct = GetSpellInfo()->Effects[EFFECT_0].CalcValue(GetCaster());
                return true;
            }

            void CalculateAmount(AuraEffect const* /*aurEff*/, int32 & amount, bool & /*canBeRecalculated*/)
            {
                // Set absorbtion amount to unlimited
                amount = -1;
            }

            void Absorb(AuraEffect* /*aurEff*/, DamageInfo & dmgInfo, uint32 & absorbAmount)
            {
                // reduces all damage taken while stun or fear
                if (GetTarget()->GetUInt32Value(UNIT_FIELD_FLAGS) & (UNIT_FLAG_FLEEING) || (GetTarget()->GetUInt32Value(UNIT_FIELD_FLAGS) & (UNIT_FLAG_STUNNED) && GetTarget()->HasAuraWithMechanic(1<<MECHANIC_STUN)))
                    absorbAmount = CalculatePct(dmgInfo.GetDamage(), absorbPct);
            }

            void Register() override
            {
                 DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_rog_nerves_of_steel_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
                 OnEffectAbsorb += AuraEffectAbsorbFn(spell_rog_nerves_of_steel_AuraScript::Absorb, EFFECT_0);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_rog_nerves_of_steel_AuraScript();
        }
};

// 58428 - Overkill
class spell_rog_overkill : public SpellScriptLoader
{
    public:
        spell_rog_overkill() : SpellScriptLoader("spell_rog_overkill") { }

        class spell_rog_overkill_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_rog_overkill_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_ROGUE_OVERKILL_POWER_REGEN });
            }

            void HandleEffectPeriodic(AuraEffect const* /*aurEff*/)
            {
                Unit* target = GetTarget();

                if (!target->HasAuraType(SPELL_AURA_MOD_STEALTH))
                    target->RemoveAurasDueToSpell(SPELL_ROGUE_OVERKILL_POWER_REGEN);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_rog_overkill_AuraScript::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_rog_overkill_AuraScript();
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
                caster->GetSpellHistory()->ResetCooldowns([caster](SpellHistory::CooldownStorageType::iterator itr) -> bool
                {
                    SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(itr->first);
                    if (spellInfo->SpellFamilyName != SPELLFAMILY_ROGUE)
                        return false;

                    return (spellInfo->SpellFamilyFlags[0] & SPELLFAMILYFLAG0_ROGUE_VAN_SPRINT) ||              // Vanish, Sprint
                        // Glyph of Preparation
                        (caster->HasAura(SPELL_ROGUE_GLYPH_OF_PREPARATION) &&
                        (spellInfo->SpellFamilyFlags[1] & SPELLFAMILYFLAG1_ROGUE_DISMANTLE_SMOKE_BOMB ||    // Dismantle, Smoke Bomb
                        spellInfo->SpellFamilyFlags[0] & SPELLFAMILYFLAG0_ROGUE_KICK));
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

// 51685 - Prey on the Weak
class spell_rog_prey_on_the_weak : public SpellScriptLoader
{
    public:
        spell_rog_prey_on_the_weak() : SpellScriptLoader("spell_rog_prey_on_the_weak") { }

        class spell_rog_prey_on_the_weak_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_rog_prey_on_the_weak_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_ROGUE_PREY_ON_THE_WEAK });
            }

            void HandleEffectPeriodic(AuraEffect const* /*aurEff*/)
            {
                Unit* target = GetTarget();
                Unit* victim = target->GetVictim();
                if (victim && (target->GetHealthPct() > victim->GetHealthPct()))
                {
                    if (!target->HasAura(SPELL_ROGUE_PREY_ON_THE_WEAK))
                    {
                        int32 bp = GetSpellInfo()->Effects[EFFECT_0].CalcValue();
                        target->CastCustomSpell(target, SPELL_ROGUE_PREY_ON_THE_WEAK, &bp, nullptr, nullptr, true);
                    }
                }
                else
                    target->RemoveAurasDueToSpell(SPELL_ROGUE_PREY_ON_THE_WEAK);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_rog_prey_on_the_weak_AuraScript::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_rog_prey_on_the_weak_AuraScript();
        }
};

// 73651 - Recuperate
class spell_rog_recuperate : public AuraScript
{
    PrepareAuraScript(spell_rog_recuperate);

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_PLAYER;
    }

    void OnPeriodic(AuraEffect const* /*aurEff*/)
    {
        if (Unit* caster = GetCaster())
            if (AuraEffect* effect = GetAura()->GetEffect(EFFECT_0))
                effect->RecalculateAmount(caster);
    }

    void CalculateBonus(AuraEffect const* /*aurEff*/, int32& amount, bool& canBeRecalculated)
    {
        canBeRecalculated = false;
        if (Unit* caster = GetCaster())
        {
            int32 baseAmount = GetSpellInfo()->Effects[EFFECT_0].CalcValue(caster) * 1000;
            // Improved Recuperate
            if (AuraEffect const* auraEffect = caster->GetDummyAuraEffect(SPELLFAMILY_ROGUE, ICON_ROGUE_IMPROVED_RECUPERATE, EFFECT_0))
                baseAmount += auraEffect->GetAmount();

            amount = CalculatePct(caster->GetMaxHealth(), float(baseAmount) / 1000.0f);
        }
    }

    void HandleEffectApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        Duration = aurEff->GetBase()->GetDuration();
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_rog_recuperate::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_HEAL);
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_rog_recuperate::CalculateBonus, EFFECT_0, SPELL_AURA_PERIODIC_HEAL);
        AfterEffectApply += AuraEffectApplyFn(spell_rog_recuperate::HandleEffectApply, EFFECT_0, SPELL_AURA_PERIODIC_HEAL, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
    }
public:
    int32 Duration = 0;
};

// -1943 - Rupture
class spell_rog_rupture : public AuraScript
{
    PrepareAuraScript(spell_rog_rupture);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ROGUE_REVEALING_STRIKE });
    }

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
                0.015f,         // 1 point:  ${($m1 + $b1*1 + 0.015 * $AP) * 5} damage over 8 secs
                0.024f,         // 2 points: ${($m1 + $b1*2 + 0.024 * $AP) * 5} damage over 10 secs
                0.03f,          // 3 points: ${($m1 + $b1*3 + 0.03 * $AP) * 5} damage over 12 secs
                0.03428571f,    // 4 points: ${($m1 + $b1*4 + 0.03428571 * $AP) * 5} damage over 14 secs
                0.0375f         // 5 points: ${($m1 + $b1*5 + 0.0375 * $AP) * 5} damage over 16 secs
            };

            uint8 cp = std::min(caster->ToPlayer()->GetComboPoints(), uint8(5));
            amount += int32(caster->GetTotalAttackPowerValue(BASE_ATTACK) * attackpowerPerCombo[cp]);

            if (AuraEffect* const revealingStrike = GetUnitOwner()->GetAuraEffect(SPELL_ROGUE_REVEALING_STRIKE, EFFECT_2, caster->GetGUID()))
            {
                amount += CalculatePct(amount, revealingStrike->GetAmount());
                revealingStrike->GetBase()->Remove();
            }
        }
    }

    void ResetDuration(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        BonusDuration = 0;
    }

    void StoreOriginalDuration(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        OriginalDuration = aurEff->GetBase()->GetDuration();
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_rog_rupture::CalculateAmount, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
        AfterEffectApply += AuraEffectApplyFn(spell_rog_rupture::ResetDuration, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAPPLY);
        AfterEffectApply += AuraEffectApplyFn(spell_rog_rupture::StoreOriginalDuration, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
    }

public:
    // For Glyph of Backstab use
    uint32 BonusDuration = 0;
    int32 OriginalDuration = 0;
};

// 63975 - Glyph of Backstab (triggered - serverside)
class spell_rog_glyph_of_backstab_triggered : public SpellScriptLoader
{
    public:
        spell_rog_glyph_of_backstab_triggered() : SpellScriptLoader("spell_rog_glyph_of_backstab_triggered") { }

        class spell_rog_glyph_of_backstab_triggered_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_rog_glyph_of_backstab_triggered_SpellScript);

            void HandleScript(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);

                Unit* caster = GetCaster();
                // search our Rupture aura on target
                if (AuraEffect* aurEff = GetHitUnit()->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_ROGUE, 0x00100000, 0, 0, caster->GetGUID()))
                {
                    spell_rog_rupture* ruptureAuraScript = aurEff->GetBase()->GetScript<spell_rog_rupture>("spell_rog_rupture");
                    if (!ruptureAuraScript)
                        return;

                    uint32& bonusDuration = ruptureAuraScript->BonusDuration;

                    // already includes duration mod from Glyph of Rupture
                    uint32 countMin = aurEff->GetBase()->GetMaxDuration();
                    uint32 countMax = countMin - bonusDuration;

                    // this glyph
                    countMax += 6000;

                    if (countMin < countMax)
                    {
                        bonusDuration += 2000;

                        aurEff->GetBase()->SetDuration(aurEff->GetBase()->GetDuration() + 2000);
                        aurEff->GetBase()->SetMaxDuration(countMin + 2000);
                    }

                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_rog_glyph_of_backstab_triggered_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_rog_glyph_of_backstab_triggered_SpellScript();
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
                        SPELL_ROGUE_MASTER_OF_SUBTLETY_PERIODIC,
                        SPELL_ROGUE_OVERKILL_TALENT,
                        SPELL_ROGUE_OVERKILL_POWER_REGEN,
                        SPELL_ROGUE_OVERKILL_PERIODIC
                    });
            }

            void HandleEffectApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();

                // Master of Subtlety
                if (AuraEffect const* aurEff = target->GetAuraEffect(SPELL_ROGUE_MASTER_OF_SUBTLETY_PASSIVE, EFFECT_0))
                {
                    int32 basepoints0 = aurEff->GetAmount();
                    target->CastCustomSpell(target, SPELL_ROGUE_MASTER_OF_SUBTLETY_DAMAGE_PERCENT, &basepoints0, nullptr, nullptr, true);
                }

                // Overkill
                if (target->HasAura(SPELL_ROGUE_OVERKILL_TALENT))
                    target->CastSpell(target, SPELL_ROGUE_OVERKILL_POWER_REGEN, true);
            }

            void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();

                // Master of subtlety
                if (target->HasAura(SPELL_ROGUE_MASTER_OF_SUBTLETY_PASSIVE))
                    target->CastSpell(target, SPELL_ROGUE_MASTER_OF_SUBTLETY_PERIODIC, true);

                // Overkill
                if (target->HasAura(SPELL_ROGUE_OVERKILL_TALENT))
                    target->CastSpell(target, SPELL_ROGUE_OVERKILL_PERIODIC, true);
            }

            void Register() override
            {
                AfterEffectApply += AuraEffectApplyFn(spell_rog_stealth_AuraScript::HandleEffectApply, EFFECT_0, SPELL_AURA_MOD_SHAPESHIFT, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
                AfterEffectRemove += AuraEffectRemoveFn(spell_rog_stealth_AuraScript::HandleEffectRemove, EFFECT_0, SPELL_AURA_MOD_SHAPESHIFT, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_rog_stealth_AuraScript();
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

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_ROGUE_TRICKS_OF_THE_TRADE_DMG_BOOST, SPELL_ROGUE_TRICKS_OF_THE_TRADE_PROC });
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (!GetTargetApplication()->GetRemoveMode().HasFlag(AuraRemoveFlags::ByDefault))
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
                Remove(AuraRemoveFlags::ByDefault); // maybe handle by proc charges
            }

            void Register() override
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_rog_tricks_of_the_trade_AuraScript::OnRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
                DoCheckProc += AuraCheckProcFn(spell_rog_tricks_of_the_trade_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_rog_tricks_of_the_trade_AuraScript::HandleProc, EFFECT_1, SPELL_AURA_DUMMY);
            }

            Unit* _redirectTarget = nullptr;
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

// -51698 - Honor Among Thieves
class spell_rog_honor_among_thieves : public AuraScript
{
    PrepareAuraScript(spell_rog_honor_among_thieves);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ROGUE_HONOR_AMONG_THIEVES_TRIGGERED });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();

        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (Player* player = caster->ToPlayer())
            if (Unit* target = ObjectAccessor::GetUnit(*player, player->GetTarget()))
                caster->CastSpell(target, SPELL_ROGUE_HONOR_AMONG_THIEVES_TRIGGERED, true, nullptr, aurEff);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_rog_honor_among_thieves::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 76806 - Main Gauche
class spell_rog_main_gauche : public AuraScript
{
    PrepareAuraScript(spell_rog_main_gauche);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ROGUE_MAIN_GAUCHE });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        Player* player = eventInfo.GetActor()->ToPlayer();
        if (!player)
            return false;

        Item* item = player->GetWeaponForAttack(BASE_ATTACK);
        if (!item || !item->IsEquipped())
            return false;

        if (!(eventInfo.GetTypeMask() & PROC_FLAG_DONE_MAINHAND_ATTACK))
            return false;

        return roll_chance_i(GetEffect(EFFECT_0)->GetAmount());
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        Player* caster = eventInfo.GetActor()->ToPlayer();
        Unit* target = eventInfo.GetProcTarget();
        Item* item = ASSERT_NOTNULL(caster->GetWeaponForAttack(BASE_ATTACK));

        caster->CastSpell(target, SPELL_ROGUE_MAIN_GAUCHE, true, item, aurEff);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_rog_main_gauche::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_rog_main_gauche::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

class spell_rog_glyph_of_hemorrhage : public AuraScript
{
    PrepareAuraScript(spell_rog_glyph_of_hemorrhage);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ROGUE_GLYPH_HEMORRHAGE_TRIGGERED });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        DamageInfo* damage = eventInfo.GetDamageInfo();
        if (!damage)
            return;

        int32 bp = CalculatePct(damage->GetDamage(), aurEff->GetAmount());
        SpellInfo const* spell = sSpellMgr->AssertSpellInfo(SPELL_ROGUE_GLYPH_HEMORRHAGE_TRIGGERED);
        if (uint8 ticks = spell->GetMaxTicks())
        {
            bp /= ticks;
            GetTarget()->CastCustomSpell(damage->GetVictim(), SPELL_ROGUE_GLYPH_HEMORRHAGE_TRIGGERED, &bp, nullptr, nullptr, true, nullptr, aurEff);
        }
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_rog_glyph_of_hemorrhage::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 2098 - Eviscerate
class spell_rog_eviscerate : public SpellScript
{
    PrepareSpellScript(spell_rog_eviscerate);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_ROGUE_EVISCERATE_AND_ENVENOM_BONUS_DAMAGE,
                SPELL_ROGUE_REVEALING_STRIKE
            });
    }

    bool Load() override
    {
        if (GetCaster()->GetTypeId() != TYPEID_PLAYER)
            return false;

        if (GetCaster()->ToPlayer()->getClass() != CLASS_ROGUE)
            return false;

        return true;
    }

    void ChangeDamage(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();
        if (!caster || !target)
            return;

        if (Player* player = caster->ToPlayer())
        {
            int32 damage = GetEffectValue();
            damage += int32(player->GetComboPoints() * (player->GetTotalAttackPowerValue(BASE_ATTACK) * 0.091f));

            // Eviscerate and Envenom Bonus Damage (item set effect)
            if (AuraEffect* aurEff = caster->GetAuraEffect(SPELL_ROGUE_EVISCERATE_AND_ENVENOM_BONUS_DAMAGE, EFFECT_0))
                damage += player->GetComboPoints() * aurEff->GetAmount();

            if (AuraEffect* const revealingStrike = target->GetAuraEffect(SPELL_ROGUE_REVEALING_STRIKE, EFFECT_2, caster->GetGUID()))
            {
                damage += CalculatePct(damage, revealingStrike->GetAmount());
                revealingStrike->GetBase()->Remove();
            }

            SetEffectValue(damage);
        }
    }

    void HandleSerratedBlades(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();
        if (!caster)
            return;

        Player* player = caster->ToPlayer();

        if (AuraEffect const* blades = caster->GetDummyAuraEffect(SPELLFAMILY_ROGUE, ROGUE_ICON_ID_SERRATED_BLADES, EFFECT_0))
            if (roll_chance_i(blades->GetAmount() * player->GetComboPoints()))
                if (AuraEffect const* rupture = target->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_ROGUE, 0x00100000, 0, 0, caster->GetGUID()))
                    if (spell_rog_rupture* script = rupture->GetBase()->GetScript<spell_rog_rupture>("spell_rog_rupture"))
                        rupture->GetBase()->SetDuration(script->OriginalDuration);
    }

    void Register() override
    {
        OnEffectLaunchTarget += SpellEffectFn(spell_rog_eviscerate::ChangeDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        OnEffectHitTarget += SpellEffectFn(spell_rog_eviscerate::HandleSerratedBlades, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 32645 - Envenom
class spell_rog_envenom : public SpellScript
{
    PrepareSpellScript(spell_rog_envenom);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ROGUE_REVEALING_STRIKE });
    }

    bool Load() override
    {
        if (GetCaster()->GetTypeId() != TYPEID_PLAYER)
            return false;

        if (GetCaster()->ToPlayer()->getClass() != CLASS_ROGUE)
            return false;

        return true;
    }

    void ChangeDamage(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();
        if (!caster || !target)
            return;

        int32 damage = GetEffectValue();
        if (Player* player = caster->ToPlayer())
        {
            // consume from stack dozes not more that have combo-points
            if (uint32 combo = player->GetComboPoints())
            {
                // Lookup for Deadly poison (only attacker applied)
                if (AuraEffect const* aurEff = target->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_ROGUE, 0x00010000, 0, 0, caster->GetGUID()))
                {
                    // count consumed deadly poison doses at target
                    bool needConsume = true;
                    uint32 spellId = aurEff->GetId();

                    uint32 doses = aurEff->GetBase()->GetStackAmount();
                    if (doses > combo)
                        doses = combo;

                    // Master Poisoner
                    Unit::AuraEffectList const& auraList = player->GetAuraEffectsByType(SPELL_AURA_MOD_AURA_DURATION_BY_DISPEL_NOT_STACK);
                    for (Unit::AuraEffectList::const_iterator iter = auraList.begin(); iter != auraList.end(); ++iter)
                    {
                        if ((*iter)->GetSpellInfo()->SpellFamilyName == SPELLFAMILY_ROGUE && (*iter)->GetSpellInfo()->SpellIconID == 1960)
                        {
                            uint32 chance = (*iter)->GetSpellInfo()->Effects[EFFECT_2].CalcValue(caster);

                            if (chance && roll_chance_i(chance))
                                needConsume = false;

                            break;
                        }
                    }

                    if (needConsume)
                        for (uint32 i = 0; i < doses; ++i)
                            target->RemoveAuraFromStack(spellId, caster->GetGUID());

                    damage *= doses;
                    damage += int32(player->GetTotalAttackPowerValue(BASE_ATTACK) * 0.09f * combo);
                }

                // Eviscerate and Envenom Bonus Damage (item set effect)
                if (caster->HasAura(37169))
                    damage += combo * 40;

                if (AuraEffect* const revealingStrike = target->GetAuraEffect(SPELL_ROGUE_REVEALING_STRIKE, EFFECT_2, caster->GetGUID()))
                {
                    damage += CalculatePct(damage, revealingStrike->GetAmount());
                    revealingStrike->GetBase()->Remove();
                }
            }
        }
    }

    void Register() override
    {
        OnEffectLaunchTarget += SpellEffectFn(spell_rog_envenom::ChangeDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 5171 - Slice and Dice
class spell_rog_slice_and_dice : public AuraScript
{
    PrepareAuraScript(spell_rog_slice_and_dice);

    void HandleEffectApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        Duration = aurEff->GetBase()->GetDuration();
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_rog_slice_and_dice::HandleEffectApply, EFFECT_0, SPELL_AURA_MOD_MELEE_HASTE_3, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
    }
public:
    int32 Duration = 0;
};

// -79121 - Deadly Momentum
class spell_rog_deadly_momentum : public AuraScript
{
    PrepareAuraScript(spell_rog_deadly_momentum);

    void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
    {
        Unit* target = GetTarget();

        // Slice and Dice duration refreshing
        if (AuraEffect* slice = target->GetAuraEffect(SPELL_AURA_MOD_MELEE_HASTE_3, SPELLFAMILY_ROGUE, 0x00040000, 0, 0))
            if (spell_rog_slice_and_dice* script = slice->GetBase()->GetScript<spell_rog_slice_and_dice>("spell_rog_slice_and_dice"))
                slice->GetBase()->SetDuration(script->Duration);

        // Recuperate duration refreshing
        if (AuraEffect* recuperate = target->GetAuraEffect(SPELL_AURA_PERIODIC_HEAL, SPELLFAMILY_ROGUE, 0, 0x08000000, 0))
            if (spell_rog_recuperate* script = recuperate->GetBase()->GetScript<spell_rog_recuperate>("spell_rog_recuperate"))
                recuperate->GetBase()->SetDuration(script->Duration);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_rog_deadly_momentum::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL_WITH_VALUE);
    }
};

// 6770 - Sap
class spell_rog_sap: public AuraScript
{
    PrepareAuraScript(spell_rog_sap);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ROGUE_BLACKJACK_R1 });
    }

    void HandleBlackJack(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (Aura const* aura = caster->GetAuraOfRankedSpell(SPELL_ROGUE_BLACKJACK_R1))
            caster->CastSpell(GetTarget(), aura->GetSpellInfo()->Id + 1, true);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_rog_sap::HandleBlackJack, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
    }
};

// -14168 - Improved Expose Armor
class spell_rog_improved_expose_armor : public AuraScript
{
    PrepareAuraScript(spell_rog_improved_expose_armor);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_ROGUE_IMPROVED_EXPOSE_ARMOR,
                SPELL_ROGUE_EXPOSE_ARMOR
            });
    }

    bool Load() override
    {
        return GetUnitOwner()->IsPlayer();
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        // Expose Armor shares its family mask with all other finishing moves so there is no way arround an ID check
        if (!eventInfo.GetSpellInfo() || eventInfo.GetSpellInfo()->Id != SPELL_ROGUE_EXPOSE_ARMOR)
            return false;

        return eventInfo.GetProcTarget();
    }

    void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        Player* player = GetTarget()->ToPlayer();
        player->CastCustomSpell(SPELL_ROGUE_IMPROVED_EXPOSE_ARMOR, SPELLVALUE_BASE_POINT0, player->GetComboPoints(), eventInfo.GetProcTarget(), true);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_rog_improved_expose_armor::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_rog_improved_expose_armor::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// -14158 - Murderous Intent
class spell_rog_murderous_intent : public AuraScript
{
    PrepareAuraScript(spell_rog_murderous_intent);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ROGUE_MURDEROUS_INTENT });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        return eventInfo.GetProcTarget() && eventInfo.GetProcTarget()->GetHealthPct() <= GetSpellInfo()->Effects[EFFECT_1].CalcValue(GetTarget());
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
        GetTarget()->CastCustomSpell(SPELL_ROGUE_MURDEROUS_INTENT, SPELLVALUE_BASE_POINT0, aurEff->GetAmount(), GetTarget(), true);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_rog_murderous_intent::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_rog_murderous_intent::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// -35541 - Combat Potency
class spell_rog_combat_potency : public AuraScript
{
    PrepareAuraScript(spell_rog_combat_potency);

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        if (eventInfo.GetSpellInfo())
            return eventInfo.GetSpellInfo()->SpellFamilyFlags[2] == 0x00000002;
        else if (eventInfo.GetDamageInfo())
            return eventInfo.GetDamageInfo()->GetAttackType() == OFF_ATTACK;

        return false;
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_rog_combat_potency::CheckProc);
    }
};

// -79095 - Restless Blades
class spell_rog_restless_blades : public AuraScript
{
    PrepareAuraScript(spell_rog_restless_blades);

    bool Load() override
    {
        return GetUnitOwner()->IsPlayer();
    }

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_ROGUE_ADRENALIN_RUSH,
                SPELL_ROGUE_KILLING_SPREE,
                SPELL_ROGUE_REDIRECT,
                SPELL_ROGUE_SPRINT
            });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
        Player* player = GetTarget()->ToPlayer();
        int32 cooldownReduction = 0;
        cooldownReduction -= player->GetComboPoints() * aurEff->GetAmount();
        player->GetSpellHistory()->ModifyCooldown(SPELL_ROGUE_ADRENALIN_RUSH, cooldownReduction);
        player->GetSpellHistory()->ModifyCooldown(SPELL_ROGUE_KILLING_SPREE, cooldownReduction);
        player->GetSpellHistory()->ModifyCooldown(SPELL_ROGUE_REDIRECT, cooldownReduction);
        player->GetSpellHistory()->ModifyCooldown(SPELL_ROGUE_SPRINT, cooldownReduction);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_rog_restless_blades::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// -84652 - Bandit's Guile
class spell_rog_bandits_guile : public AuraScript
{
    PrepareAuraScript(spell_rog_bandits_guile);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_ROGUE_SHALLOW_INSIGHT,
                SPELL_ROGUE_MODERATE_INSIGHT,
                SPELL_ROGUE_DEEP_INSIGHT,
                SPELL_ROGUE_BANDITS_GUILE
            });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        if (GetTarget()->HasAura(SPELL_ROGUE_DEEP_INSIGHT, GetTarget()->GetGUID()))
            return false;

        return eventInfo.GetProcTarget();
    }

    void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        Unit* target = GetTarget();
        Unit* procTarget = eventInfo.GetProcTarget();
        uint32 spellId = SPELL_ROGUE_SHALLOW_INSIGHT;
        int32 basepoints = 10;

        // We are striking a new opponent, reset progress
        if (_recentTargetGUID != procTarget->GetGUID())
        {
            target->RemoveAurasDueToSpell(SPELL_ROGUE_SHALLOW_INSIGHT, target->GetGUID());
            target->RemoveAurasDueToSpell(SPELL_ROGUE_MODERATE_INSIGHT, target->GetGUID());
            _recentTargetGUID = procTarget->GetGUID();
        }

        // We are increasing our insight on the opponent
        if (target->HasAura(SPELL_ROGUE_SHALLOW_INSIGHT, target->GetGUID()))
        {
            target->RemoveAurasDueToSpell(SPELL_ROGUE_SHALLOW_INSIGHT, target->GetGUID());
            spellId = SPELL_ROGUE_MODERATE_INSIGHT;
            basepoints = 20;
        }
        else if (target->HasAura(SPELL_ROGUE_MODERATE_INSIGHT, target->GetGUID()))
        {
            target->RemoveAurasDueToSpell(SPELL_ROGUE_MODERATE_INSIGHT, target->GetGUID());
            spellId = SPELL_ROGUE_DEEP_INSIGHT;
            basepoints = 30;
        }

        target->CastSpell(target, spellId, true);
        target->CastCustomSpell(procTarget, SPELL_ROGUE_BANDITS_GUILE, &basepoints, &basepoints, nullptr, true);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_rog_bandits_guile::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_rog_bandits_guile::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
private:
    ObjectGuid _recentTargetGUID;
};

void AddSC_rogue_spell_scripts()
{
    RegisterAuraScript(spell_rog_bandits_guile);
    new spell_rog_blade_flurry();
    new spell_rog_cheat_death();
    new spell_rog_crippling_poison();
    new spell_rog_cut_to_the_chase();
    RegisterAuraScript(spell_rog_combat_potency);
    RegisterAuraScript(spell_rog_deadly_momentum);
    new spell_rog_deadly_poison();
    RegisterSpellScript(spell_rog_envenom);
    RegisterSpellScript(spell_rog_eviscerate);
    RegisterAuraScript(spell_rog_glyph_of_hemorrhage);
    RegisterAuraScript(spell_rog_improved_expose_armor);
    new spell_rog_killing_spree();
    RegisterAuraScript(spell_rog_main_gauche);
    new spell_rog_master_of_subtlety();
    RegisterAuraScript(spell_rog_murderous_intent);
    new spell_rog_nerves_of_steel();
    new spell_rog_overkill();
    new spell_rog_preparation();
    new spell_rog_prey_on_the_weak();
    RegisterAuraScript(spell_rog_recuperate);
    RegisterAuraScript(spell_rog_restless_blades);
    RegisterAuraScript(spell_rog_rupture);
    new spell_rog_glyph_of_backstab_triggered();
    RegisterAuraScript(spell_rog_sap);
    new spell_rog_shiv();
    RegisterAuraScript(spell_rog_slice_and_dice);
    new spell_rog_stealth();
    new spell_rog_tricks_of_the_trade();
    new spell_rog_tricks_of_the_trade_proc();
    RegisterAuraScript(spell_rog_honor_among_thieves);
}
