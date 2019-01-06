/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
    SPELL_ROGUE_BLADE_FLURRY_EXTRA_ATTACK       = 22482,
    SPELL_ROGUE_CHEAT_DEATH_COOLDOWN            = 31231,
    SPELL_ROGUE_GLYPH_OF_PREPARATION            = 56819,
    SPELL_ROGUE_KILLING_SPREE                   = 51690,
    SPELL_ROGUE_KILLING_SPREE_TELEPORT          = 57840,
    SPELL_ROGUE_KILLING_SPREE_WEAPON_DMG        = 57841,
    SPELL_ROGUE_KILLING_SPREE_DMG_BUFF          = 61851,
    SPELL_ROGUE_PREY_ON_THE_WEAK                = 58670,
    SPELL_ROGUE_SHIV_TRIGGERED                  =  5940,
    SPELL_ROGUE_TRICKS_OF_THE_TRADE             = 57934,
    SPELL_ROGUE_TRICKS_OF_THE_TRADE_DMG_BOOST   = 57933,
    SPELL_ROGUE_TRICKS_OF_THE_TRADE_PROC        = 59628,
    SPELL_ROGUE_HONOR_AMONG_THIEVES             = 51698,
    SPELL_ROGUE_HONOR_AMONG_THIEVES_PROC        = 52916,
    SPELL_ROGUE_HONOR_AMONG_THIEVES_2           = 51699,
    SPELL_ROGUE_T10_2P_BONUS                    = 70804,
    SPELL_ROGUE_GLYPH_OF_BACKSTAB_TRIGGER       = 63975,
    SPELL_ROGUE_QUICK_RECOVERY_ENERGY           = 31663,
    SPELL_ROGUE_CRIPPLING_POISON                =  3409,
    SPELL_ROGUE_MASTER_OF_SUBTLETY_BUFF         = 31665,
    SPELL_ROGUE_OVERKILL_BUFF                   = 58427,
    SPELL_ROGUE_STEALTH                         =  1784
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

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                _procTarget = eventInfo.GetActor()->SelectNearbyTarget(eventInfo.GetProcTarget());
                return _procTarget != nullptr;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                if (DamageInfo* damageInfo = eventInfo.GetDamageInfo())
                {
                    CastSpellExtraArgs args(aurEff);
                    args.AddSpellBP0(damageInfo->GetDamage());
                    GetTarget()->CastSpell(_procTarget, SPELL_ROGUE_BLADE_FLURRY_EXTRA_ATTACK, args);
                }
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_rog_blade_flurry_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_rog_blade_flurry_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_MOD_MELEE_HASTE);
            }

            Unit* _procTarget = nullptr;
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_rog_blade_flurry_AuraScript();
        }
};

// -31228 - Cheat Death
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

// -51664 - Cut to the Chase
class spell_rog_cut_to_the_chase : public SpellScriptLoader
{
    public:
        spell_rog_cut_to_the_chase() : SpellScriptLoader("spell_rog_cut_to_the_chase") { }

        class spell_rog_cut_to_the_chase_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_rog_cut_to_the_chase_AuraScript);

            void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                // "refresh your Slice and Dice duration to its 5 combo point maximum"
                Unit* caster = eventInfo.GetActor();
                // lookup Slice and Dice
                if (AuraEffect const* snd = caster->GetAuraEffect(SPELL_AURA_MOD_MELEE_HASTE, SPELLFAMILY_ROGUE, 0x00040000, 0x00000000, 0x00000000, caster->GetGUID()))
                {
                    // Max 5 cp duration
                    uint32 countMax = snd->GetSpellInfo()->GetMaxDuration();

                    snd->GetBase()->SetDuration(countMax, true);
                    snd->GetBase()->SetMaxDuration(snd->GetBase()->GetDuration());
                }
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

// -51625 - Deadly Brew
class spell_rog_deadly_brew : public SpellScriptLoader
{
    public:
        spell_rog_deadly_brew() : SpellScriptLoader("spell_rog_deadly_brew") { }

        class spell_rog_deadly_brew_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_rog_deadly_brew_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_ROGUE_CRIPPLING_POISON });
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                eventInfo.GetActor()->CastSpell(eventInfo.GetProcTarget(), SPELL_ROGUE_CRIPPLING_POISON, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_rog_deadly_brew_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_rog_deadly_brew_AuraScript();
        }
};

// -2818 - Deadly Poison
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
                        SpellItemEnchantmentEntry const* enchant = sSpellItemEnchantmentStore.LookupEntry(item->GetEnchantmentId(EnchantmentSlot(slot)));
                        if (!enchant)
                            continue;

                        for (uint8 s = 0; s < 3; ++s)
                        {
                            if (enchant->type[s] != ITEM_ENCHANTMENT_TYPE_COMBAT_SPELL)
                                continue;

                            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(enchant->spellid[s]);
                            if (!spellInfo)
                            {
                                TC_LOG_ERROR("spells", "Player::CastItemCombatSpell Enchant %i, player (Name: %s, GUID: %u) cast unknown spell %i", enchant->ID, player->GetName().c_str(), player->GetGUID().GetCounter(), enchant->spellid[s]);
                                continue;
                            }

                            // Proc only rogue poisons
                            if (spellInfo->SpellFamilyName != SPELLFAMILY_ROGUE || spellInfo->Dispel != DISPEL_POISON)
                                continue;

                            // Do not reproc deadly
                            if (spellInfo->SpellFamilyFlags.IsEqual(0x10000, 0x80000, 0))
                                continue;

                            if (spellInfo->IsPositive())
                                player->CastSpell(player, enchant->spellid[s], item);
                            else
                                player->CastSpell(target, enchant->spellid[s], item);
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

// -31130 - Nerves of Steel
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

// 31666 - Master of Subtlety
// 58428 - Overkill - aura remove spell (SERVERSIDE)
template <uint32 RemoveSpell>
class spell_rog_overkill_mos : public SpellScriptLoader
{
    public:
        spell_rog_overkill_mos(char const* ScriptName) : SpellScriptLoader(ScriptName) { }

        template <uint32 RemoveSpellId>
        class spell_rog_overkill_mos_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_rog_overkill_mos_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ RemoveSpellId });
            }

            void PeriodicTick(AuraEffect const* /*aurEff*/)
            {
                GetTarget()->RemoveAurasDueToSpell(RemoveSpellId);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_rog_overkill_mos_AuraScript::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_rog_overkill_mos_AuraScript<RemoveSpell>();
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

                    return (spellInfo->SpellFamilyFlags[1] & SPELLFAMILYFLAG1_ROGUE_COLDB_SHADOWSTEP ||  // Cold Blood, Shadowstep
                        spellInfo->SpellFamilyFlags[0] & SPELLFAMILYFLAG_ROGUE_VAN_EVAS_SPRINT) ||       // Vanish, Evasion, Sprint
                        (caster->HasAura(SPELL_ROGUE_GLYPH_OF_PREPARATION) &&
                        (spellInfo->SpellFamilyFlags[1] & SPELLFAMILYFLAG1_ROGUE_DISMANTLE ||            // Dismantle
                        spellInfo->SpellFamilyFlags[0] & SPELLFAMILYFLAG_ROGUE_KICK ||                   // Kick
                        (spellInfo->SpellFamilyFlags[0] & SPELLFAMILYFLAG_ROGUE_BLADE_FLURRY &&          // Blade Flurry
                        spellInfo->SpellFamilyFlags[1] & SPELLFAMILYFLAG1_ROGUE_BLADE_FLURRY)));
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

// -51685 - Prey on the Weak
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
                        CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
                        args.AddSpellBP0(GetSpellInfo()->Effects[EFFECT_0].CalcValue());
                        target->CastSpell(target, SPELL_ROGUE_PREY_ON_THE_WEAK, args);
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

// -31244 - Quick Recovery
class spell_rog_quick_recovery : public SpellScriptLoader
{
    public:
        spell_rog_quick_recovery() : SpellScriptLoader("spell_rog_quick_recovery") { }

        class spell_rog_quick_recovery_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_rog_quick_recovery_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_ROGUE_QUICK_RECOVERY_ENERGY });
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                SpellInfo const* spellInfo = eventInfo.GetSpellInfo();
                if (!spellInfo)
                    return;

                Unit* caster = eventInfo.GetActor();
                int32 amount = CalculatePct(spellInfo->CalcPowerCost(caster, spellInfo->GetSchoolMask()), aurEff->GetAmount());
                CastSpellExtraArgs args(aurEff);
                args.AddSpellBP0(amount);
                caster->CastSpell(nullptr, SPELL_ROGUE_QUICK_RECOVERY_ENERGY, args);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_rog_quick_recovery_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_rog_quick_recovery_AuraScript();
        }
};

// -1943 - Rupture
class spell_rog_rupture : public SpellScriptLoader
{
    public:
        static char constexpr const ScriptName[] = "spell_rog_rupture";

        spell_rog_rupture() : SpellScriptLoader(ScriptName) { }

        class spell_rog_rupture_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_rog_rupture_AuraScript);

            bool Load() override
            {
                Unit* caster = GetCaster();
                BonusDuration = 0;
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

                    uint8 cp = caster->ToPlayer()->GetComboPoints();
                    if (cp > 5)
                        cp = 5;

                    amount += int32(caster->GetTotalAttackPowerValue(BASE_ATTACK) * attackpowerPerCombo[cp]);
                }
            }

            void ResetDuration(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                BonusDuration = 0;
            }

            void Register() override
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_rog_rupture_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
                AfterEffectApply += AuraEffectApplyFn(spell_rog_rupture_AuraScript::ResetDuration, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAPPLY);
            }

        public:
            // For Glyph of Backstab use
            uint32 BonusDuration;
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_rog_rupture_AuraScript();
        }
};
char constexpr const spell_rog_rupture::ScriptName[];

// 56800 - Glyph of Backstab (dummy)
class spell_rog_glyph_of_backstab : public SpellScriptLoader
{
    public:
        spell_rog_glyph_of_backstab() : SpellScriptLoader("spell_rog_glyph_of_backstab") { }

        class spell_rog_glyph_of_backstab_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_rog_glyph_of_backstab_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_ROGUE_GLYPH_OF_BACKSTAB_TRIGGER });
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                eventInfo.GetActor()->CastSpell(eventInfo.GetProcTarget(), SPELL_ROGUE_GLYPH_OF_BACKSTAB_TRIGGER, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_rog_glyph_of_backstab_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_rog_glyph_of_backstab_AuraScript();
        }
};

// 63975 - Glyph of Backstab (triggered - serverside)
class spell_rog_glyph_of_backstab_triggered : public SpellScriptLoader
{
    public:
        spell_rog_glyph_of_backstab_triggered() : SpellScriptLoader("spell_rog_glyph_of_backstab_triggered") { }

        class spell_rog_glyph_of_backstab_triggered_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_rog_glyph_of_backstab_triggered_SpellScript);

            typedef spell_rog_rupture::spell_rog_rupture_AuraScript RuptureAuraScript;

            void HandleScript(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);

                Unit* caster = GetCaster();
                // search our Rupture aura on target
                if (AuraEffect* aurEff = GetHitUnit()->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_ROGUE, 0x00100000, 0, 0, caster->GetGUID()))
                {
                    RuptureAuraScript* ruptureAuraScript = aurEff->GetBase()->GetScript<RuptureAuraScript>(spell_rog_rupture::ScriptName);
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

// -13983 - Setup
class spell_rog_setup : public SpellScriptLoader
{
    public:
        spell_rog_setup() : SpellScriptLoader("spell_rog_setup") { }

        class spell_rog_setup_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_rog_setup_AuraScript);

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                if (Player* target = GetTarget()->ToPlayer())
                    if (eventInfo.GetActor() == target->GetSelectedUnit())
                        return true;

                return false;
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_rog_setup_AuraScript::CheckProc);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_rog_setup_AuraScript();
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

// 57934 - Tricks of the Trade
class spell_rog_tricks_of_the_trade_aura : public AuraScript
{
    PrepareAuraScript(spell_rog_tricks_of_the_trade_aura);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_ROGUE_TRICKS_OF_THE_TRADE_DMG_BOOST,
            SPELL_ROGUE_TRICKS_OF_THE_TRADE_PROC
        });
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_DEFAULT || !GetTarget()->HasAura(SPELL_ROGUE_TRICKS_OF_THE_TRADE_PROC))
            GetTarget()->GetThreatManager().UnregisterRedirectThreat(SPELL_ROGUE_TRICKS_OF_THE_TRADE);
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();

        Unit* rogue = GetTarget();
        Unit* target = ObjectAccessor::GetUnit(*rogue, _redirectTarget);
        if (target)
        {
            rogue->CastSpell(target, SPELL_ROGUE_TRICKS_OF_THE_TRADE_DMG_BOOST, aurEff);
            rogue->CastSpell(rogue, SPELL_ROGUE_TRICKS_OF_THE_TRADE_PROC, aurEff);
        }
        Remove(AURA_REMOVE_BY_DEFAULT);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_rog_tricks_of_the_trade_aura::OnRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectProc += AuraEffectProcFn(spell_rog_tricks_of_the_trade_aura::HandleProc, EFFECT_1, SPELL_AURA_DUMMY);
    }

    ObjectGuid _redirectTarget;
public:
    void SetRedirectTarget(ObjectGuid const& guid) { _redirectTarget = guid; }
};

class spell_rog_tricks_of_the_trade : public SpellScript
{
    PrepareSpellScript(spell_rog_tricks_of_the_trade);

    void DoAfterHit()
    {
        if (Aura* aura = GetHitAura())
            if (auto* script = aura->GetScript<spell_rog_tricks_of_the_trade_aura>("spell_rog_tricks_of_the_trade"))
            {
                if (Unit* explTarget = GetExplTargetUnit())
                    script->SetRedirectTarget(explTarget->GetGUID());
                else
                    script->SetRedirectTarget(ObjectGuid::Empty);
            }
    }

    void Register() override
    {
        AfterHit += SpellHitFn(spell_rog_tricks_of_the_trade::DoAfterHit);
    }
};

// 59628 - Tricks of the Trade (Proc)
class spell_rog_tricks_of_the_trade_proc : public AuraScript
{
    PrepareAuraScript(spell_rog_tricks_of_the_trade_proc);

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->GetThreatManager().UnregisterRedirectThreat(SPELL_ROGUE_TRICKS_OF_THE_TRADE);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_rog_tricks_of_the_trade_proc::HandleRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 51698,51700,51701 - Honor Among Thieves
class spell_rog_honor_among_thieves : public SpellScriptLoader
{
public:
    spell_rog_honor_among_thieves() : SpellScriptLoader("spell_rog_honor_among_thieves") { }

    class spell_rog_honor_among_thieves_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_rog_honor_among_thieves_AuraScript);

        bool Validate(SpellInfo const* spellInfo) override
        {
            return ValidateSpellInfo(
            {
                SPELL_ROGUE_HONOR_AMONG_THIEVES_2,
                spellInfo->Effects[EFFECT_0].TriggerSpell
            });
        }

        bool CheckProc(ProcEventInfo& /*eventInfo*/)
        {
            Unit* caster = GetCaster();
            if (!caster || caster->HasAura(SPELL_ROGUE_HONOR_AMONG_THIEVES_2))
                return false;

            return true;
        }

        void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
        {
            PreventDefaultAction();

            Unit* caster = GetCaster();
            if (!caster)
                return;

            Unit* target = GetTarget();
            target->CastSpell(target, GetSpellInfo()->Effects[aurEff->GetEffIndex()].TriggerSpell, { aurEff, caster->GetGUID() });
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_rog_honor_among_thieves_AuraScript::CheckProc);
            OnEffectProc += AuraEffectProcFn(spell_rog_honor_among_thieves_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_rog_honor_among_thieves_AuraScript();
    }
};

// 52916 - Honor Among Thieves (Proc)
class spell_rog_honor_among_thieves_proc : public SpellScriptLoader
{
public:
    spell_rog_honor_among_thieves_proc() : SpellScriptLoader("spell_rog_honor_among_thieves_proc") { }

    class spell_rog_honor_among_thieves_proc_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_rog_honor_among_thieves_proc_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_ROGUE_HONOR_AMONG_THIEVES_PROC });
        }

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            targets.clear();

            Unit* target = GetOriginalCaster();
            if (!target)
                return;

            targets.push_back(target);
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_rog_honor_among_thieves_proc_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_CASTER_AREA_PARTY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_rog_honor_among_thieves_proc_SpellScript();
    }

    class spell_rog_honor_among_thieves_proc_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_rog_honor_among_thieves_proc_AuraScript);

        void HandleEffectApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (Player* player = caster->ToPlayer())
                player->CastSpell(nullptr, SPELL_ROGUE_HONOR_AMONG_THIEVES_2, true);
        }

        void Register() override
        {
            AfterEffectApply += AuraEffectApplyFn(spell_rog_honor_among_thieves_proc_AuraScript::HandleEffectApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_rog_honor_among_thieves_proc_AuraScript();
    }
};

// -51627 - Turn the Tables
class spell_rog_turn_the_tables : public SpellScriptLoader
{
    public:
        spell_rog_turn_the_tables() : SpellScriptLoader("spell_rog_turn_the_tables") { }

        class spell_rog_turn_the_tables_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_rog_turn_the_tables_AuraScript);

            bool Validate(SpellInfo const* spellInfo) override
            {
                return ValidateSpellInfo({ spellInfo->Effects[EFFECT_0].TriggerSpell });
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();

                Unit* caster = GetCaster();
                if (!caster)
                    return;

                caster->CastSpell(nullptr, GetSpellInfo()->Effects[EFFECT_0].TriggerSpell, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_rog_turn_the_tables_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_rog_turn_the_tables_AuraScript();
        }
};

// -11327 - Vanish
class spell_rog_vanish : public AuraScript
{
    PrepareAuraScript(spell_rog_vanish);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ROGUE_STEALTH });
    }

    void ApplyStealth(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* unitTarget = GetTarget();
        unitTarget->RemoveAurasByType(SPELL_AURA_MOD_STALKED);

        // See if we already are stealthed. If so, we're done.
        if (unitTarget->HasAura(SPELL_ROGUE_STEALTH))
            return;

        // Reset cooldown on stealth if needed
        if (unitTarget->GetSpellHistory()->HasCooldown(SPELL_ROGUE_STEALTH))
            unitTarget->GetSpellHistory()->ResetCooldown(SPELL_ROGUE_STEALTH);

        unitTarget->CastSpell(nullptr, SPELL_ROGUE_STEALTH, true);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_rog_vanish::ApplyStealth, EFFECT_1, SPELL_AURA_MOD_STEALTH, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
    }
};

void AddSC_rogue_spell_scripts()
{
    new spell_rog_blade_flurry();
    new spell_rog_cheat_death();
    new spell_rog_cut_to_the_chase();
    new spell_rog_deadly_brew();
    new spell_rog_deadly_poison();
    new spell_rog_killing_spree();
    new spell_rog_nerves_of_steel();
    new spell_rog_overkill_mos<SPELL_ROGUE_OVERKILL_BUFF>("spell_rog_overkill");
    new spell_rog_overkill_mos<SPELL_ROGUE_MASTER_OF_SUBTLETY_BUFF>("spell_rog_master_of_subtlety");
    new spell_rog_preparation();
    new spell_rog_prey_on_the_weak();
    new spell_rog_quick_recovery();
    new spell_rog_rupture();
    new spell_rog_glyph_of_backstab();
    new spell_rog_glyph_of_backstab_triggered();
    new spell_rog_setup();
    new spell_rog_shiv();
    RegisterSpellAndAuraScriptPair(spell_rog_tricks_of_the_trade, spell_rog_tricks_of_the_trade_aura);
    RegisterAuraScript(spell_rog_tricks_of_the_trade_proc);
    new spell_rog_honor_among_thieves();
    new spell_rog_honor_among_thieves_proc();
    new spell_rog_turn_the_tables();
    RegisterAuraScript(spell_rog_vanish);
}
