/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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
 * Scripts for spells with SPELLFAMILY_SHAMAN and SPELLFAMILY_GENERIC spells used by shaman players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_sha_".
 */

#include "Player.h"
#include "ScriptMgr.h"
#include "GridNotifiers.h"
#include "Unit.h"
#include "SpellHistory.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"

enum ShamanSpells
{
    SPELL_SHAMAN_ANCESTRAL_AWAKENING_DUMMY      = 52759,
    SPELL_SHAMAN_ANCESTRAL_AWAKENING_PROC       = 52752,
    SPELL_SHAMAN_BIND_SIGHT                     = 6277,
    SPELL_SHAMAN_CLEANSING_TOTEM_EFFECT         = 52025,
    SPELL_SHAMAN_EARTH_SHIELD_HEAL              = 379,
    SPELL_SHAMAN_ELEMENTAL_MASTERY              = 16166,
    SPELL_SHAMAN_EXHAUSTION                     = 57723,
    SPELL_SHAMAN_FIRE_NOVA_R1                   = 1535,
    SPELL_SHAMAN_FIRE_NOVA_TRIGGERED_R1         = 8349,
    SPELL_SHAMAN_GLYPH_OF_EARTH_SHIELD          = 63279,
    SPELL_SHAMAN_GLYPH_OF_HEALING_STREAM_TOTEM  = 55456,
    SPELL_SHAMAN_GLYPH_OF_MANA_TIDE             = 55441,
    SPELL_SHAMAN_GLYPH_OF_THUNDERSTORM          = 62132,
    SPELL_SHAMAN_ITEM_LIGHTNING_SHIELD          = 23552,
    SPELL_SHAMAN_ITEM_LIGHTNING_SHIELD_DAMAGE   = 27635,
    SPELL_SHAMAN_ITEM_MANA_SURGE                = 23571,
    SPELL_SHAMAN_LAVA_FLOWS_R1                  = 51480,
    SPELL_SHAMAN_LAVA_FLOWS_TRIGGERED_R1        = 64694,
    SPELL_SHAMAN_LIGHTNING_SHIELD_R1            = 26364,
    SPELL_SHAMAN_MANA_SPRING_TOTEM_ENERGIZE     = 52032,
    SPELL_SHAMAN_MANA_TIDE_TOTEM                = 39609,
    SPELL_SHAMAN_NATURE_GUARDIAN                = 31616,
    SPELL_SHAMAN_SATED                          = 57724,
    SPELL_SHAMAN_STORM_EARTH_AND_FIRE           = 51483,
    SPELL_SHAMAN_TOTEM_EARTHBIND_EARTHGRAB      = 64695,
    SPELL_SHAMAN_TOTEM_EARTHBIND_TOTEM          = 6474,
    SPELL_SHAMAN_TOTEM_EARTHEN_POWER            = 59566,
    SPELL_SHAMAN_TOTEM_HEALING_STREAM_HEAL      = 52042,
    SPELL_SHAMAN_TOTEMIC_MASTERY                = 38437,
    SPELL_SHAMAN_TIDAL_FORCE_CRIT               = 55166,
    SPELL_SHAMAN_TOTEMIC_POWER_MP5              = 28824,
    SPELL_SHAMAN_TOTEMIC_POWER_SPELL_POWER      = 28825,
    SPELL_SHAMAN_TOTEMIC_POWER_ATTACK_POWER     = 28826,
    SPELL_SHAMAN_TOTEMIC_POWER_ARMOR            = 28827,
    SPELL_SHAMAN_WINDFURY_WEAPON_R1             = 8232,
    SPELL_SHAMAN_WINDFURY_ATTACK_MH             = 25504,
    SPELL_SHAMAN_WINDFURY_ATTACK_OH             = 33750,
    SPELL_SHAMAN_ENERGY_SURGE                   = 40465,
    SPELL_SHAMAN_POWER_SURGE                    = 40466,
    SPELL_SHAMAN_GLYPH_OF_HEALING_WAVE_HEAL     = 55533,
    SPELL_SHAMAN_SPIRIT_HUNT_HEAL               = 58879,
    SPELL_SHAMAN_ELECTRIFIED                    = 64930,
    SPELL_SHAMAN_LAVA_BURST_BONUS_DAMAGE        = 71824,
    SPELL_SHAMAN_CHAINED_HEAL                   = 70809,
    SPELL_SHAMAN_TOTEM_OF_WRATH_SPELL_POWER     = 63283,
    SPELL_SHAMAN_FREEZE                         = 63685,
    SPELL_SHAMAN_FLAMETONGUE_ATTACK             = 10444,
    SPELL_SHAMAN_LIGHTNING_BOLT_OVERLOAD_R1     = 45284,
    SPELL_SHAMAN_CHAIN_LIGHTNING_OVERLOAD_R1    = 45297,
    SPELL_SHAMAN_LIGHTNING_SHIELD_DAMAGE_R1     = 26364,
    SPELL_SHAMAN_SHAMANISTIC_RAGE_PROC          = 30824,
    SPELL_SHAMAN_MAELSTROM_POWER                = 70831,
    SPELL_SHAMAN_T10_ENHANCEMENT_4P_BONUS       = 70832
};

enum ShamanSpellIcons
{
    SHAMAN_ICON_ID_RESTORATIVE_TOTEMS           = 338,
    SHAMAN_ICON_ID_SHAMAN_LAVA_FLOW             = 3087,
    SHAMAN_ICON_ID_TOTEM_OF_WRATH               = 2019
};

// -51556 - Ancestral Awakening
class spell_sha_ancestral_awakening : public SpellScriptLoader
{
    public:
        spell_sha_ancestral_awakening() : SpellScriptLoader("spell_sha_ancestral_awakening") { }

        class spell_sha_ancestral_awakening_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_ancestral_awakening_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_ANCESTRAL_AWAKENING_DUMMY))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                HealInfo* healInfo = eventInfo.GetHealInfo();
                if (!healInfo || !healInfo->GetHeal())
                    return;

                int32 amount = CalculatePct(static_cast<int32>(healInfo->GetHeal()), aurEff->GetAmount());
                eventInfo.GetActor()->CastCustomSpell(SPELL_SHAMAN_ANCESTRAL_AWAKENING_DUMMY, SPELLVALUE_BASE_POINT0, amount, (Unit*)nullptr, true);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_sha_ancestral_awakening_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_ancestral_awakening_AuraScript();
        }
};

// 52759 - Ancestral Awakening (Proc)
class spell_sha_ancestral_awakening_proc : public SpellScriptLoader
{
    public:
        spell_sha_ancestral_awakening_proc() : SpellScriptLoader("spell_sha_ancestral_awakening_proc") { }

        class spell_sha_ancestral_awakening_proc_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_ancestral_awakening_proc_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_ANCESTRAL_AWAKENING_PROC))
                    return false;
                return true;
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.size() < 2)
                    return;

                targets.sort(Trinity::HealthPctOrderPred());

                WorldObject* target = targets.front();
                targets.clear();
                targets.push_back(target);
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                int32 damage = GetEffectValue();
                if (GetHitUnit())
                    GetCaster()->CastCustomSpell(GetHitUnit(), SPELL_SHAMAN_ANCESTRAL_AWAKENING_PROC, &damage, NULL, NULL, true);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_ancestral_awakening_proc_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_CASTER_AREA_RAID);
                OnEffectHitTarget += SpellEffectFn(spell_sha_ancestral_awakening_proc_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_sha_ancestral_awakening_proc_SpellScript();
        }
};

// 51474 - Astral Shift
class spell_sha_astral_shift : public SpellScriptLoader
{
    public:
        spell_sha_astral_shift() : SpellScriptLoader("spell_sha_astral_shift") { }

        class spell_sha_astral_shift_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_astral_shift_AuraScript);

        public:
            spell_sha_astral_shift_AuraScript()
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
                // reduces all damage taken while stun, fear or silence
                if (GetTarget()->GetUInt32Value(UNIT_FIELD_FLAGS) & (UNIT_FLAG_FLEEING | UNIT_FLAG_SILENCED) || (GetTarget()->GetUInt32Value(UNIT_FIELD_FLAGS) & (UNIT_FLAG_STUNNED) && GetTarget()->HasAuraWithMechanic(1<<MECHANIC_STUN)))
                    absorbAmount = CalculatePct(dmgInfo.GetDamage(), absorbPct);
            }

            void Register() override
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_sha_astral_shift_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
                OnEffectAbsorb += AuraEffectAbsorbFn(spell_sha_astral_shift_AuraScript::Absorb, EFFECT_0);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_astral_shift_AuraScript();
        }
};

// -51474 - Astral Shift aura
class spell_sha_astral_shift_aura : public SpellScriptLoader
{
    public:
        spell_sha_astral_shift_aura() : SpellScriptLoader("spell_sha_astral_shift_aura") { }

        class spell_sha_astral_shift_aura_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_astral_shift_aura_AuraScript);

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                if (SpellInfo const* spellInfo = eventInfo.GetSpellInfo())
                    if (spellInfo->GetAllEffectsMechanicMask() & ((1 << MECHANIC_SILENCE) | (1 << MECHANIC_STUN) | (1 << MECHANIC_FEAR)))
                        return true;

                return false;
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_sha_astral_shift_aura_AuraScript::CheckProc);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_astral_shift_aura_AuraScript();
        }
};

// 2825 - Bloodlust
class spell_sha_bloodlust : public SpellScriptLoader
{
    public:
        spell_sha_bloodlust() : SpellScriptLoader("spell_sha_bloodlust") { }

        class spell_sha_bloodlust_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_bloodlust_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_SATED))
                    return false;
                return true;
            }

            void RemoveInvalidTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if(Trinity::UnitAuraCheck(true, SPELL_SHAMAN_SATED));
            }

            void ApplyDebuff()
            {
                if (Unit* target = GetHitUnit())
                    target->CastSpell(target, SPELL_SHAMAN_SATED, true);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_bloodlust_SpellScript::RemoveInvalidTargets, EFFECT_0, TARGET_UNIT_CASTER_AREA_RAID);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_bloodlust_SpellScript::RemoveInvalidTargets, EFFECT_1, TARGET_UNIT_CASTER_AREA_RAID);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_bloodlust_SpellScript::RemoveInvalidTargets, EFFECT_2, TARGET_UNIT_CASTER_AREA_RAID);
                AfterHit += SpellHitFn(spell_sha_bloodlust_SpellScript::ApplyDebuff);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_sha_bloodlust_SpellScript();
        }
};

// -1064 - Chain Heal
class spell_sha_chain_heal : public SpellScriptLoader
{
    public:
        spell_sha_chain_heal() : SpellScriptLoader("spell_sha_chain_heal") { }

        class spell_sha_chain_heal_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_chain_heal_SpellScript);

        public:
            spell_sha_chain_heal_SpellScript()
            {
                firstHeal = true;
                riptide = false;
            }

        private:
            void HandleHeal(SpellEffIndex /*effIndex*/)
            {
                if (firstHeal)
                {
                    // Check if the target has Riptide
                    if (AuraEffect* aurEff = GetHitUnit()->GetAuraEffect(SPELL_AURA_PERIODIC_HEAL, SPELLFAMILY_SHAMAN, 0, 0, 0x10, GetCaster()->GetGUID()))
                    {
                        riptide = true;
                        // Consume it
                        GetHitUnit()->RemoveAura(aurEff->GetBase());
                    }
                    firstHeal = false;
                }
                // Riptide increases the Chain Heal effect by 25%
                if (riptide)
                    SetHitHeal(GetHitHeal() * 1.25f);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_sha_chain_heal_SpellScript::HandleHeal, EFFECT_0, SPELL_EFFECT_HEAL);
            }

            bool firstHeal;
            bool riptide;
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_sha_chain_heal_SpellScript();
        }
};

// 8171 - Cleansing Totem (Pulse)
class spell_sha_cleansing_totem_pulse : public SpellScriptLoader
{
    public:
        spell_sha_cleansing_totem_pulse() : SpellScriptLoader("spell_sha_cleansing_totem_pulse") { }

        class spell_sha_cleansing_totem_pulse_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_cleansing_totem_pulse_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_CLEANSING_TOTEM_EFFECT))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                int32 bp = 1;
                if (GetCaster() && GetHitUnit() && GetOriginalCaster())
                    GetCaster()->CastCustomSpell(GetHitUnit(), SPELL_SHAMAN_CLEANSING_TOTEM_EFFECT, NULL, &bp, NULL, true, NULL, NULL, GetOriginalCaster()->GetGUID());
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_sha_cleansing_totem_pulse_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_sha_cleansing_totem_pulse_SpellScript();
        }
};

// -974 - Earth Shield
class spell_sha_earth_shield : public SpellScriptLoader
{
    public:
        spell_sha_earth_shield() : SpellScriptLoader("spell_sha_earth_shield") { }

        class spell_sha_earth_shield_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_earth_shield_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_EARTH_SHIELD_HEAL))
                    return false;
                return true;
            }

            void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
            {
                if (Unit* caster = GetCaster())
                    amount = caster->SpellHealingBonusDone(GetUnitOwner(), GetSpellInfo(), amount, HEAL);
                // SpellHealingBonusTaken will be called on Heal
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();

                GetTarget()->CastCustomSpell(SPELL_SHAMAN_EARTH_SHIELD_HEAL, SPELLVALUE_BASE_POINT0, aurEff->GetAmount(), GetTarget(), true, NULL, aurEff, GetCasterGUID());
            }

            void Register() override
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_sha_earth_shield_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_DUMMY);
                OnEffectProc += AuraEffectProcFn(spell_sha_earth_shield_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_earth_shield_AuraScript();
        }
};

// 6474 - Earthbind Totem - Fix Talent: Earthen Power
class spell_sha_earthbind_totem : public SpellScriptLoader
{
    public:
        spell_sha_earthbind_totem() : SpellScriptLoader("spell_sha_earthbind_totem") { }

        class spell_sha_earthbind_totem_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_earthbind_totem_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_TOTEM_EARTHBIND_TOTEM) || !sSpellMgr->GetSpellInfo(SPELL_SHAMAN_TOTEM_EARTHEN_POWER))
                    return false;
                return true;
            }

            void HandleEffectPeriodic(AuraEffect const* /*aurEff*/)
            {
                if (!GetCaster())
                    return;
                if (Player* owner = GetCaster()->GetCharmerOrOwnerPlayerOrPlayerItself())
                    if (AuraEffect* aur = owner->GetDummyAuraEffect(SPELLFAMILY_SHAMAN, 2289, 0))
                        if (roll_chance_i(aur->GetBaseAmount()))
                            GetTarget()->CastSpell((Unit*)NULL, SPELL_SHAMAN_TOTEM_EARTHEN_POWER, true);
            }

            void Apply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (!GetCaster())
                    return;
                Player* owner = GetCaster()->GetCharmerOrOwnerPlayerOrPlayerItself();
                if (!owner)
                    return;
                // Storm, Earth and Fire
                if (AuraEffect* aurEff = owner->GetAuraEffectOfRankedSpell(SPELL_SHAMAN_STORM_EARTH_AND_FIRE, EFFECT_1))
                {
                    if (roll_chance_i(aurEff->GetAmount()))
                        GetCaster()->CastSpell(GetCaster(), SPELL_SHAMAN_TOTEM_EARTHBIND_EARTHGRAB, false);
                }
            }

            void Register() override
            {
                 OnEffectPeriodic += AuraEffectPeriodicFn(spell_sha_earthbind_totem_AuraScript::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
                 OnEffectApply += AuraEffectApplyFn(spell_sha_earthbind_totem_AuraScript::Apply, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_earthbind_totem_AuraScript();
        }
};

class EarthenPowerTargetSelector
{
    public:
        EarthenPowerTargetSelector() { }

        bool operator() (WorldObject* target)
        {
            if (!target->ToUnit())
                return true;

            if (!target->ToUnit()->HasAuraWithMechanic(1 << MECHANIC_SNARE))
                return true;

            return false;
        }
};

// 59566 - Earthen Power
class spell_sha_earthen_power : public SpellScriptLoader
{
    public:
        spell_sha_earthen_power() : SpellScriptLoader("spell_sha_earthen_power") { }

        class spell_sha_earthen_power_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_earthen_power_SpellScript);

            void FilterTargets(std::list<WorldObject*>& unitList)
            {
                unitList.remove_if(EarthenPowerTargetSelector());
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_earthen_power_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_sha_earthen_power_SpellScript();
        }
};

// -1535 - Fire Nova
class spell_sha_fire_nova : public SpellScriptLoader
{
    public:
        spell_sha_fire_nova() : SpellScriptLoader("spell_sha_fire_nova") { }

        class spell_sha_fire_nova_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_fire_nova_SpellScript);

            bool Validate(SpellInfo const* spellInfo) override
            {
                SpellInfo const* firstRankSpellInfo = sSpellMgr->GetSpellInfo(SPELL_SHAMAN_FIRE_NOVA_R1);
                if (!firstRankSpellInfo || !spellInfo->IsRankOf(firstRankSpellInfo))
                    return false;

                uint8 rank = spellInfo->GetRank();
                if (!sSpellMgr->GetSpellWithRank(SPELL_SHAMAN_FIRE_NOVA_TRIGGERED_R1, rank, true))
                    return false;
                return true;
            }

            SpellCastResult CheckFireTotem()
            {
                // fire totem
                if (!GetCaster()->m_SummonSlot[1])
                {
                    SetCustomCastResultMessage(SPELL_CUSTOM_ERROR_MUST_HAVE_FIRE_TOTEM);
                    return SPELL_FAILED_CUSTOM_ERROR;
                }

                return SPELL_CAST_OK;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                if (Creature* totem = caster->GetMap()->GetCreature(caster->m_SummonSlot[1]))
                {
                    uint8 rank = GetSpellInfo()->GetRank();
                    if (totem->IsTotem())
                        caster->CastSpell(totem, sSpellMgr->GetSpellWithRank(SPELL_SHAMAN_FIRE_NOVA_TRIGGERED_R1, rank), true);
                }
            }

            void Register() override
            {
                OnCheckCast += SpellCheckCastFn(spell_sha_fire_nova_SpellScript::CheckFireTotem);
                OnEffectHitTarget += SpellEffectFn(spell_sha_fire_nova_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_sha_fire_nova_SpellScript();
        }
};

// -8050 - Flame Shock
class spell_sha_flame_shock : public SpellScriptLoader
{
    public:
        spell_sha_flame_shock() : SpellScriptLoader("spell_sha_flame_shock") { }

        class spell_sha_flame_shock_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_flame_shock_AuraScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_LAVA_FLOWS_R1))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_LAVA_FLOWS_TRIGGERED_R1))
                    return false;
                return true;
            }

            void HandleDispel(DispelInfo* /*dispelInfo*/)
            {
                if (Unit* caster = GetCaster())
                    // Lava Flows
                    if (AuraEffect const* aurEff = caster->GetDummyAuraEffect(SPELLFAMILY_SHAMAN, SHAMAN_ICON_ID_SHAMAN_LAVA_FLOW, EFFECT_0))
                    {
                        if (SpellInfo const* firstRankSpellInfo = sSpellMgr->GetSpellInfo(SPELL_SHAMAN_LAVA_FLOWS_R1))
                            if (!aurEff->GetSpellInfo()->IsRankOf(firstRankSpellInfo))
                                return;

                        uint8 rank = aurEff->GetSpellInfo()->GetRank();
                        caster->CastSpell(caster, sSpellMgr->GetSpellWithRank(SPELL_SHAMAN_LAVA_FLOWS_TRIGGERED_R1, rank), true);
                    }
            }

            void Register() override
            {
                AfterDispel += AuraDispelFn(spell_sha_flame_shock_AuraScript::HandleDispel);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_flame_shock_AuraScript();
        }
};

// -10400 - Flametongue Weapon (Passive)
class spell_sha_flametongue_weapon : public SpellScriptLoader
{
    public:
        spell_sha_flametongue_weapon() : SpellScriptLoader("spell_sha_flametongue_weapon") { }

        class spell_sha_flametongue_weapon_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_flametongue_weapon_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_FLAMETONGUE_ATTACK))
                    return false;
                return true;
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                Player* player = eventInfo.GetActor()->ToPlayer();
                if (!player)
                    return false;

                Item* item = player->GetItemByGuid(GetAura()->GetCastItemGUID());
                if (!item || !item->IsEquipped())
                    return false;

                WeaponAttackType attType = static_cast<WeaponAttackType>(player->GetAttackBySlot(item->GetSlot()));
                if (attType != BASE_ATTACK && attType != OFF_ATTACK)
                    return false;

                if (((attType == BASE_ATTACK) && !(eventInfo.GetTypeMask() & PROC_FLAG_DONE_MAINHAND_ATTACK)) ||
                    ((attType == OFF_ATTACK) && !(eventInfo.GetTypeMask() & PROC_FLAG_DONE_OFFHAND_ATTACK)))
                    return false;

                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                Player* player = eventInfo.GetActor()->ToPlayer();
                Unit* target = eventInfo.GetProcTarget();
                WeaponAttackType attType = BASE_ATTACK;
                if (eventInfo.GetTypeMask() & PROC_FLAG_DONE_OFFHAND_ATTACK)
                    attType = OFF_ATTACK;

                Item* item = ASSERT_NOTNULL(player->GetWeaponForAttack(attType));

                float basePoints(GetSpellInfo()->Effects[aurEff->GetEffIndex()].CalcValue());

                // Flametongue max damage is normalized based on a 4.0 speed weapon
                // Tooltip says max damage = BasePoints / 25, so BasePoints / 25 / 4 to get base damage per 1.0s AS
                float fireDamage = basePoints / 100.0f;
                float attackSpeed = player->GetAttackTime(attType) / 1000.f;
                fireDamage *= attackSpeed;

                // clip value between (BasePoints / 77) and (BasePoints / 25) as the tooltip indicates
                RoundToInterval(fireDamage, basePoints / 77.0f, basePoints / 25.0f);

                // Calculate Spell Power scaling
                float spellPowerBonus(player->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_FIRE) + target->SpellBaseDamageBonusTaken(SPELL_SCHOOL_MASK_FIRE));
                float const spCoeff = 0.03811f;
                spellPowerBonus *= spCoeff * attackSpeed;

                // All done, now proc damage
                int32 amount = static_cast<int32>(fireDamage + spellPowerBonus);
                player->CastCustomSpell(SPELL_SHAMAN_FLAMETONGUE_ATTACK, SPELLVALUE_BASE_POINT0, amount, target, true, item);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_sha_flametongue_weapon_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_sha_flametongue_weapon_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_flametongue_weapon_AuraScript();
        }
};

// -63373 - Frozen Power
class spell_sha_frozen_power : public SpellScriptLoader
{
    public:
        spell_sha_frozen_power() : SpellScriptLoader("spell_sha_frozen_power") { }

        class spell_sha_frozen_power_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_frozen_power_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_FREEZE))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                if (!roll_chance_i(aurEff->GetAmount()))
                    return;

                Unit* caster = eventInfo.GetActor();
                SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(SPELL_SHAMAN_FREEZE);
                float minDistance(spellInfo->Effects[EFFECT_0].CalcValue(caster));

                Unit* target = eventInfo.GetProcTarget();
                if (caster->GetDistance(target) < minDistance)
                    return;

                caster->CastSpell(target, SPELL_SHAMAN_FREEZE, true);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_sha_frozen_power_AuraScript::HandleProc, EFFECT_1, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_frozen_power_AuraScript();
        }
};

// 63279 - Glyph of Earth Shield
class spell_sha_glyph_of_earth_shield : public SpellScriptLoader
{
    public:
        spell_sha_glyph_of_earth_shield() : SpellScriptLoader("spell_sha_glyph_of_earth_shield") { }

        class spell_sha_glyph_of_earth_shield_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_glyph_of_earth_shield_AuraScript);

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                SpellInfo const* earthShield = eventInfo.GetSpellInfo();
                if (!earthShield)
                    return;

                AuraEffect* earthShieldEffect = eventInfo.GetProcTarget()->GetAuraEffect(earthShield->Id, EFFECT_0, eventInfo.GetActor()->GetGUID());
                if (!earthShieldEffect)
                    return;

                int32 amount = earthShieldEffect->GetAmount();
                AddPct(amount, aurEff->GetAmount());
                earthShieldEffect->SetAmount(amount);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_sha_glyph_of_earth_shield_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_glyph_of_earth_shield_AuraScript();
        }
};

// 55440 - Glyph of Healing Wave
class spell_sha_glyph_of_healing_wave : public SpellScriptLoader
{
    public:
        spell_sha_glyph_of_healing_wave() : SpellScriptLoader("spell_sha_glyph_of_healing_wave") { }

        class spell_sha_glyph_of_healing_wave_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_glyph_of_healing_wave_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_GLYPH_OF_HEALING_WAVE_HEAL))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                Unit* caster = eventInfo.GetActor();
                if (caster == eventInfo.GetProcTarget())
                    return;

                HealInfo* healInfo = eventInfo.GetHealInfo();
                if (!healInfo || !healInfo->GetHeal())
                    return;

                int32 amount = CalculatePct(static_cast<int32>(healInfo->GetHeal()), aurEff->GetAmount());
                caster->CastCustomSpell(SPELL_SHAMAN_GLYPH_OF_HEALING_WAVE_HEAL, SPELLVALUE_BASE_POINT0, amount, (Unit*)nullptr, true);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_sha_glyph_of_healing_wave_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_glyph_of_healing_wave_AuraScript();
        }
};

// 63280 - Glyph of Totem of Wrath
class spell_sha_glyph_of_totem_of_wrath : public SpellScriptLoader
{
    public:
        spell_sha_glyph_of_totem_of_wrath() : SpellScriptLoader("spell_sha_glyph_of_totem_of_wrath") { }

        class spell_sha_glyph_of_totem_of_wrath_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_glyph_of_totem_of_wrath_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_TOTEM_OF_WRATH_SPELL_POWER))
                    return false;
                return true;
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                // Totem of Wrath shares family flags with other totems
                // filter by spellIcon instead
                SpellInfo const* spellInfo = eventInfo.GetSpellInfo();
                if (!spellInfo || spellInfo->SpellIconID != SHAMAN_ICON_ID_TOTEM_OF_WRATH)
                    return false;

                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                Unit* caster = eventInfo.GetActor();

                // Fire totem summon slot
                Creature* totem = ObjectAccessor::GetCreature(*caster, caster->m_SummonSlot[1]);
                if (!totem)
                    return;

                SpellInfo const* totemSpell = sSpellMgr->GetSpellInfo(totem->m_spells[0]);
                if (!totemSpell)
                    return;

                int32 bp0 = CalculatePct(totemSpell->Effects[EFFECT_0].CalcValue(caster), aurEff->GetAmount());
                int32 bp1 = CalculatePct(totemSpell->Effects[EFFECT_1].CalcValue(caster), aurEff->GetAmount());
                caster->CastCustomSpell((Unit*)nullptr, SPELL_SHAMAN_TOTEM_OF_WRATH_SPELL_POWER, &bp0, &bp1, nullptr, true);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_sha_glyph_of_totem_of_wrath_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_sha_glyph_of_totem_of_wrath_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_glyph_of_totem_of_wrath_AuraScript();
        }
};

// 52041, 52046, 52047, 52048, 52049, 52050, 58759, 58760, 58761 - Healing Stream Totem
class spell_sha_healing_stream_totem : public SpellScriptLoader
{
    public:
        spell_sha_healing_stream_totem() : SpellScriptLoader("spell_sha_healing_stream_totem") { }

        class spell_sha_healing_stream_totem_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_healing_stream_totem_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_GLYPH_OF_HEALING_STREAM_TOTEM) || !sSpellMgr->GetSpellInfo(SPELL_SHAMAN_TOTEM_HEALING_STREAM_HEAL))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                int32 damage = GetEffectValue();
                SpellInfo const* triggeringSpell = GetTriggeringSpell();
                if (Unit* target = GetHitUnit())
                {
                    if (Unit* caster = GetCaster())
                    {
                        if (Unit* owner = caster->GetOwner())
                        {
                            if (triggeringSpell)
                                damage = int32(owner->SpellHealingBonusDone(target, triggeringSpell, damage, HEAL));

                            // Restorative Totems
                            if (AuraEffect* dummy = owner->GetAuraEffect(SPELL_AURA_DUMMY, SPELLFAMILY_SHAMAN, SHAMAN_ICON_ID_RESTORATIVE_TOTEMS, 1))
                                AddPct(damage, dummy->GetAmount());

                            // Glyph of Healing Stream Totem
                            if (AuraEffect const* aurEff = owner->GetAuraEffect(SPELL_SHAMAN_GLYPH_OF_HEALING_STREAM_TOTEM, EFFECT_0))
                                AddPct(damage, aurEff->GetAmount());

                            damage = int32(target->SpellHealingBonusTaken(owner, triggeringSpell, damage, HEAL));
                        }
                        caster->CastCustomSpell(target, SPELL_SHAMAN_TOTEM_HEALING_STREAM_HEAL, &damage, 0, 0, true, 0, 0, GetOriginalCaster()->GetGUID());
                    }
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_sha_healing_stream_totem_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_sha_healing_stream_totem_SpellScript();
        }
};

// 32182 - Heroism
class spell_sha_heroism : public SpellScriptLoader
{
    public:
        spell_sha_heroism() : SpellScriptLoader("spell_sha_heroism") { }

        class spell_sha_heroism_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_heroism_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_EXHAUSTION))
                    return false;
                return true;
            }

            void RemoveInvalidTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if(Trinity::UnitAuraCheck(true, SPELL_SHAMAN_EXHAUSTION));
            }

            void ApplyDebuff()
            {
                if (Unit* target = GetHitUnit())
                    target->CastSpell(target, SPELL_SHAMAN_EXHAUSTION, true);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_heroism_SpellScript::RemoveInvalidTargets, EFFECT_0, TARGET_UNIT_CASTER_AREA_RAID);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_heroism_SpellScript::RemoveInvalidTargets, EFFECT_1, TARGET_UNIT_CASTER_AREA_RAID);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_heroism_SpellScript::RemoveInvalidTargets, EFFECT_2, TARGET_UNIT_CASTER_AREA_RAID);
                AfterHit += SpellHitFn(spell_sha_heroism_SpellScript::ApplyDebuff);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_sha_heroism_SpellScript();
        }
};

// -16180 - Improved Water Shield
class spell_sha_imp_water_shield : public SpellScriptLoader
{
    public:
        spell_sha_imp_water_shield() : SpellScriptLoader("spell_sha_imp_water_shield") { }

        class spell_sha_imp_water_shield_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_imp_water_shield_AuraScript);

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                SpellInfo const* spellInfo = eventInfo.GetSpellInfo();
                if (!spellInfo)
                    return false;

                // If we're here, we've already passed initial aura roll
                // So just chance based on 100%

                // Default chance for Healing Wave and Riptide
                int32 chance = 100;
                // Lesser Healing Wave - 0.6 of default
                if (spellInfo->SpellFamilyFlags[0] & 0x00000080)
                    chance = 60;
                // Chain heal - 0.3 of default
                else if (spellInfo->SpellFamilyFlags[0] & 0x00000100)
                    chance = 30;

                if (!roll_chance_i(chance))
                    return false;

                return true;
            }

            void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                Unit* caster = eventInfo.GetActor();
                // Get Water Shield
                AuraEffect const* aurEff = caster->GetAuraEffect(SPELL_AURA_PROC_TRIGGER_SPELL, SPELLFAMILY_SHAMAN, 0x00000000, 0x00000020, 0x00000000, caster->GetGUID());
                if (!aurEff)
                    return;

                uint32 spellId = aurEff->GetSpellInfo()->Effects[aurEff->GetEffIndex()].TriggerSpell;
                caster->CastSpell((Unit*)nullptr, spellId, true);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_sha_imp_water_shield_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_sha_imp_water_shield_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_imp_water_shield_AuraScript();
        }
};

// -30675 - Lightning Overload
class spell_sha_lightning_overload : public SpellScriptLoader
{
    public:
        spell_sha_lightning_overload() : SpellScriptLoader("spell_sha_lightning_overload") { }

        class spell_sha_lightning_overload_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_lightning_overload_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_LIGHTNING_BOLT_OVERLOAD_R1) ||
                    !sSpellMgr->GetSpellInfo(SPELL_SHAMAN_CHAIN_LIGHTNING_OVERLOAD_R1))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                SpellInfo const* spellInfo = eventInfo.GetSpellInfo();
                if (!spellInfo)
                    return;

                uint32 spellId;

                // Lightning Bolt
                if (spellInfo->SpellFamilyFlags[0] & 0x00000001)
                    spellId = sSpellMgr->GetSpellWithRank(SPELL_SHAMAN_LIGHTNING_BOLT_OVERLOAD_R1, spellInfo->GetRank());
                // Chain Lightning
                else
                {
                    // Chain lightning has [LightOverload_Proc_Chance] / [Max_Number_of_Targets] chance to proc of each individual target hit.
                    // A maxed LO would have a 33% / 3 = 11% chance to proc of each target.
                    // LO chance was already "accounted" at the proc chance roll, now need to divide the chance by [Max_Number_of_Targets]
                    float chance = 100.0f / spellInfo->Effects[EFFECT_0].ChainTarget;
                    if (!roll_chance_f(chance))
                        return;

                    spellId = sSpellMgr->GetSpellWithRank(SPELL_SHAMAN_CHAIN_LIGHTNING_OVERLOAD_R1, spellInfo->GetRank());
                }

                eventInfo.GetActor()->CastSpell(eventInfo.GetProcTarget(), spellId, true);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_sha_lightning_overload_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_lightning_overload_AuraScript();
        }
};

// 23551 - Lightning Shield T2 Bonus
class spell_sha_item_lightning_shield : public SpellScriptLoader
{
    public:
        spell_sha_item_lightning_shield() : SpellScriptLoader("spell_sha_item_lightning_shield") { }

        class spell_sha_item_lightning_shield_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_item_lightning_shield_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_ITEM_LIGHTNING_SHIELD))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                GetTarget()->CastSpell(eventInfo.GetProcTarget(), SPELL_SHAMAN_ITEM_LIGHTNING_SHIELD, true, NULL, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_sha_item_lightning_shield_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_item_lightning_shield_AuraScript();
        }
};

// 23552 - Lightning Shield T2 Bonus
class spell_sha_item_lightning_shield_trigger : public SpellScriptLoader
{
    public:
        spell_sha_item_lightning_shield_trigger() : SpellScriptLoader("spell_sha_item_lightning_shield_trigger") { }

        class spell_sha_item_lightning_shield_trigger_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_item_lightning_shield_trigger_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_ITEM_LIGHTNING_SHIELD_DAMAGE))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                GetTarget()->CastSpell(GetTarget(), SPELL_SHAMAN_ITEM_LIGHTNING_SHIELD_DAMAGE, true, NULL, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_sha_item_lightning_shield_trigger_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_item_lightning_shield_trigger_AuraScript();
        }
};

// 23572 - Mana Surge
class spell_sha_item_mana_surge : public SpellScriptLoader
{
    public:
        spell_sha_item_mana_surge() : SpellScriptLoader("spell_sha_item_mana_surge") { }

        class spell_sha_item_mana_surge_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_item_mana_surge_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_ITEM_MANA_SURGE))
                    return false;
                return true;
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                return eventInfo.GetDamageInfo()->GetSpellInfo() != nullptr;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                SpellInfo const* spellInfo = eventInfo.GetSpellInfo();
                if (!spellInfo)
                    return;

                int32 mana = spellInfo->CalcPowerCost(GetTarget(), eventInfo.GetSchoolMask());
                int32 damage = CalculatePct(mana, 35);

                GetTarget()->CastCustomSpell(SPELL_SHAMAN_ITEM_MANA_SURGE, SPELLVALUE_BASE_POINT0, damage, GetTarget(), true, NULL, aurEff);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_sha_item_mana_surge_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_sha_item_mana_surge_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_item_mana_surge_AuraScript();
        }
};

// 40463 - Shaman Tier 6 Trinket
class spell_sha_item_t6_trinket : public SpellScriptLoader
{
    public:
        spell_sha_item_t6_trinket() : SpellScriptLoader("spell_sha_item_t6_trinket") { }

        class spell_sha_item_t6_trinket_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_item_t6_trinket_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_ENERGY_SURGE) ||
                    !sSpellMgr->GetSpellInfo(SPELL_SHAMAN_POWER_SURGE))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                SpellInfo const* spellInfo = eventInfo.GetSpellInfo();
                if (!spellInfo)
                    return;

                uint32 spellId;
                int32 chance;

                // Lesser Healing Wave
                if (spellInfo->SpellFamilyFlags[0] & 0x00000080)
                {
                    spellId = SPELL_SHAMAN_ENERGY_SURGE;
                    chance = 10;
                }
                // Lightning Bolt
                else if (spellInfo->SpellFamilyFlags[0] & 0x00000001)
                {
                    spellId = SPELL_SHAMAN_ENERGY_SURGE;
                    chance = 15;
                }
                // Stormstrike
                else if (spellInfo->SpellFamilyFlags[1] & 0x00000010)
                {
                    spellId = SPELL_SHAMAN_POWER_SURGE;
                    chance = 50;
                }
                else
                    return;

                if (roll_chance_i(chance))
                    eventInfo.GetActor()->CastSpell((Unit*)nullptr, spellId, true);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_sha_item_t6_trinket_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_item_t6_trinket_AuraScript();
        }
};

// 70811 - Item - Shaman T10 Elemental 2P Bonus
class spell_sha_item_t10_elemental_2p_bonus : public SpellScriptLoader
{
    public:
        spell_sha_item_t10_elemental_2p_bonus() : SpellScriptLoader("spell_sha_item_t10_elemental_2p_bonus") { }

        class spell_sha_item_t10_elemental_2p_bonus_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_item_t10_elemental_2p_bonus_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_ELEMENTAL_MASTERY))
                    return false;
                return true;
            }

            void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                if (Player* target = GetTarget()->ToPlayer())
                    target->GetSpellHistory()->ModifyCooldown(SPELL_SHAMAN_ELEMENTAL_MASTERY, -aurEff->GetAmount());
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_sha_item_t10_elemental_2p_bonus_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_item_t10_elemental_2p_bonus_AuraScript();
        }
};

// 60103 - Lava Lash
class spell_sha_lava_lash : public SpellScriptLoader
{
    public:
        spell_sha_lava_lash() : SpellScriptLoader("spell_sha_lava_lash") { }

        class spell_sha_lava_lash_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_lava_lash_SpellScript);

            bool Load() override
            {
                return GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                if (Player* caster = GetCaster()->ToPlayer())
                {
                    int32 damage = GetEffectValue();
                    int32 hitDamage = GetHitDamage();
                    if (Item* offhand = caster->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND))
                    {
                        // Damage is increased by 25% if your off-hand weapon is enchanted with Flametongue.
                        if (AuraEffect const* aurEff = caster->GetAuraEffect(SPELL_AURA_DUMMY, SPELLFAMILY_SHAMAN, 0x200000, 0, 0))
                            if (aurEff->GetBase()->GetCastItemGUID() == offhand->GetGUID())
                                AddPct(hitDamage, damage);
                        SetHitDamage(hitDamage);
                    }
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_sha_lava_lash_SpellScript::HandleDummy, EFFECT_1, SPELL_EFFECT_DUMMY);
            }

        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_sha_lava_lash_SpellScript();
        }
};

// -324 - Lightning Shield
class spell_sha_lightning_shield : public SpellScriptLoader
{
public:
    spell_sha_lightning_shield() : SpellScriptLoader("spell_sha_lightning_shield") { }

    class spell_sha_lightning_shield_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_sha_lightning_shield_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_LIGHTNING_SHIELD_R1))
                return false;
            return true;
        }

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            if (eventInfo.GetActionTarget())
                return true;
            return false;
        }

        void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
        {
            PreventDefaultAction();
            uint32 triggerSpell = sSpellMgr->GetSpellWithRank(SPELL_SHAMAN_LIGHTNING_SHIELD_R1, aurEff->GetSpellInfo()->GetRank());

            eventInfo.GetActionTarget()->CastSpell(eventInfo.GetActor(), triggerSpell, true, nullptr, aurEff);
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_sha_lightning_shield_AuraScript::CheckProc);
            OnEffectProc += AuraEffectProcFn(spell_sha_lightning_shield_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_sha_lightning_shield_AuraScript();
    }
};

// 53817 - Maelstrom Weapon
class spell_sha_maelstrom_weapon : public SpellScriptLoader
{
    public:
        spell_sha_maelstrom_weapon() : SpellScriptLoader("spell_sha_maelstrom_weapon") { }

        class spell_sha_maelstrom_weapon_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_maelstrom_weapon_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_MAELSTROM_POWER) ||
                    !sSpellMgr->GetSpellInfo(SPELL_SHAMAN_T10_ENHANCEMENT_4P_BONUS))
                    return false;
                return true;
            }

            void HandleBonus(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (GetStackAmount() < GetSpellInfo()->StackAmount)
                    return;

                Unit* caster = GetUnitOwner();
                AuraEffect const* aurEff = caster->GetAuraEffect(SPELL_SHAMAN_T10_ENHANCEMENT_4P_BONUS, EFFECT_0);
                if (!aurEff || !roll_chance_i(aurEff->GetAmount()))
                    return;

                caster->CastSpell((Unit*)nullptr, SPELL_SHAMAN_MAELSTROM_POWER, true);
            }

            void Register() override
            {
                OnEffectApply += AuraEffectApplyFn(spell_sha_maelstrom_weapon_AuraScript::HandleBonus, EFFECT_0, SPELL_AURA_ADD_PCT_MODIFIER, AURA_EFFECT_HANDLE_CHANGE_AMOUNT);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_maelstrom_weapon_AuraScript();
        }
};

// 52031, 52033, 52034, 52035, 52036, 58778, 58779, 58780 - Mana Spring Totem
class spell_sha_mana_spring_totem : public SpellScriptLoader
{
    public:
        spell_sha_mana_spring_totem() : SpellScriptLoader("spell_sha_mana_spring_totem") { }

        class spell_sha_mana_spring_totem_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_mana_spring_totem_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_MANA_SPRING_TOTEM_ENERGIZE))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                int32 damage = GetEffectValue();
                if (Unit* target = GetHitUnit())
                    if (Unit* caster = GetCaster())
                        if (target->getPowerType() == POWER_MANA)
                            caster->CastCustomSpell(target, SPELL_SHAMAN_MANA_SPRING_TOTEM_ENERGIZE, &damage, nullptr, nullptr, true, nullptr, nullptr, GetOriginalCaster()->GetGUID());
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_sha_mana_spring_totem_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }

        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_sha_mana_spring_totem_SpellScript();
        }
};

// 39610 - Mana Tide Totem
class spell_sha_mana_tide_totem : public SpellScriptLoader
{
    public:
        spell_sha_mana_tide_totem() : SpellScriptLoader("spell_sha_mana_tide_totem") { }

        class spell_sha_mana_tide_totem_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_mana_tide_totem_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_GLYPH_OF_MANA_TIDE) || !sSpellMgr->GetSpellInfo(SPELL_SHAMAN_MANA_TIDE_TOTEM))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                if (Unit* caster = GetCaster())
                {
                    if (Unit* unitTarget = GetHitUnit())
                    {
                        if (unitTarget->getPowerType() == POWER_MANA)
                        {
                            int32 effValue = GetEffectValue();
                            // Glyph of Mana Tide
                            if (Unit* owner = caster->GetOwner())
                                if (AuraEffect* dummy = owner->GetAuraEffect(SPELL_SHAMAN_GLYPH_OF_MANA_TIDE, 0))
                                    effValue += dummy->GetAmount();
                            // Regenerate 6% of Total Mana Every 3 secs
                            int32 effBasePoints0 = int32(CalculatePct(unitTarget->GetMaxPower(POWER_MANA), effValue));
                            caster->CastCustomSpell(unitTarget, SPELL_SHAMAN_MANA_TIDE_TOTEM, &effBasePoints0, NULL, NULL, true, NULL, NULL, GetOriginalCaster()->GetGUID());
                        }
                    }
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_sha_mana_tide_totem_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_sha_mana_tide_totem_SpellScript();
        }
};

// -30881 - Nature's Guardian
class spell_sha_nature_guardian : public SpellScriptLoader
{
public:
    spell_sha_nature_guardian() : SpellScriptLoader("spell_sha_nature_guardian") { }

    class spell_sha_nature_guardian_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_sha_nature_guardian_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_NATURE_GUARDIAN))
                return false;
            return true;
        }

        void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
        {
            PreventDefaultAction();
            DamageInfo* damageInfo = eventInfo.GetDamageInfo();
            if (!damageInfo)
                return;

            int32 healthpct = aurEff->GetSpellInfo()->Effects[EFFECT_1].CalcValue(); // %s2 - the 30% threshold for health

            if (Unit* target = eventInfo.GetActionTarget())
            {
                if (target->HealthBelowPctDamaged(healthpct, damageInfo->GetDamage()))
                {

                    uint32 bp = CalculatePct(target->GetMaxHealth(), aurEff->GetAmount());
                    target->CastCustomSpell(SPELL_SHAMAN_NATURE_GUARDIAN, SPELLVALUE_BASE_POINT0, bp, target, true, nullptr, aurEff);

                    // Threat reduction is around 10% confirmed in retail and from wiki
                    Unit* attacker = eventInfo.GetActor();
                    if (attacker->IsAlive())
                        attacker->getThreatManager().modifyThreatPercent(target, -10);
                }
            }
        }

        void Register() override
        {
            OnEffectProc += AuraEffectProcFn(spell_sha_nature_guardian_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_sha_nature_guardian_AuraScript();
    }
};

// 6495 - Sentry Totem
class spell_sha_sentry_totem : public SpellScriptLoader
{
    public:
        spell_sha_sentry_totem() : SpellScriptLoader("spell_sha_sentry_totem") { }

        class spell_sha_sentry_totem_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_sentry_totem_AuraScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_BIND_SIGHT))
                    return false;
                return true;
            }

            void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* caster = GetCaster())
                    if (Creature* totem = caster->GetMap()->GetCreature(caster->m_SummonSlot[4]))
                        if (totem->IsTotem())
                            caster->CastSpell(totem, SPELL_SHAMAN_BIND_SIGHT, true);
            }

            void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* caster = GetCaster())
                    if (caster->GetTypeId() == TYPEID_PLAYER)
                        caster->ToPlayer()->StopCastingBindSight();
            }

            void Register() override
            {
                 AfterEffectApply += AuraEffectApplyFn(spell_sha_sentry_totem_AuraScript::AfterApply, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
                 AfterEffectRemove += AuraEffectRemoveFn(spell_sha_sentry_totem_AuraScript::AfterRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_sentry_totem_AuraScript();
        }
};

// 30823 - Shamanistic Rage
class spell_sha_shamanistic_rage : public SpellScriptLoader
{
    public:
        spell_sha_shamanistic_rage() : SpellScriptLoader("spell_sha_shamanistic_rage") { }

        class spell_sha_shamanistic_rage_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_shamanistic_rage_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_SHAMANISTIC_RAGE_PROC))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();

                Unit* target = GetTarget();
                int32 amount = CalculatePct(static_cast<int32>(target->GetTotalAttackPowerValue(BASE_ATTACK)), aurEff->GetAmount());
                target->CastCustomSpell(SPELL_SHAMAN_SHAMANISTIC_RAGE_PROC, SPELLVALUE_BASE_POINT0, amount, target, true, nullptr, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_sha_shamanistic_rage_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_shamanistic_rage_AuraScript();
        }
};

// 58877 - Spirit Hunt
class spell_sha_spirit_hunt : public SpellScriptLoader
{
    public:
        spell_sha_spirit_hunt() : SpellScriptLoader("spell_sha_spirit_hunt") { }

        class spell_sha_spirit_hunt_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_spirit_hunt_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_SPIRIT_HUNT_HEAL))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                DamageInfo* damageInfo = eventInfo.GetDamageInfo();
                if (!damageInfo || !damageInfo->GetDamage())
                    return;

                Unit* caster = eventInfo.GetActor();
                Unit* target = caster->GetOwner();
                if (!target)
                    return;

                int32 amount = CalculatePct(static_cast<int32>(damageInfo->GetDamage()), aurEff->GetAmount());
                caster->CastCustomSpell(SPELL_SHAMAN_SPIRIT_HUNT_HEAL, SPELLVALUE_BASE_POINT0, amount, caster, true);
                caster->CastCustomSpell(SPELL_SHAMAN_SPIRIT_HUNT_HEAL, SPELLVALUE_BASE_POINT0, amount, target, true);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_sha_spirit_hunt_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_spirit_hunt_AuraScript();
        }
};

// -51525 - Static Shock
class spell_sha_static_shock : public SpellScriptLoader
{
    public:
        spell_sha_static_shock() : SpellScriptLoader("spell_sha_static_shock") { }

        class spell_sha_static_shock_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_static_shock_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_LIGHTNING_SHIELD_DAMAGE_R1))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                Unit* caster = eventInfo.GetActor();

                // Get Lightning Shield
                AuraEffect const* aurEff = caster->GetAuraEffect(SPELL_AURA_PROC_TRIGGER_SPELL, SPELLFAMILY_SHAMAN, 0x00000400, 0x00000000, 0x00000000, caster->GetGUID());
                if (!aurEff)
                    return;

                uint32 spellId = sSpellMgr->GetSpellWithRank(SPELL_SHAMAN_LIGHTNING_SHIELD_DAMAGE_R1, aurEff->GetSpellInfo()->GetRank());
                eventInfo.GetActor()->CastSpell(eventInfo.GetProcTarget(), spellId, true);
                aurEff->GetBase()->DropCharge();
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_sha_static_shock_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_static_shock_AuraScript();
        }
};

// 55198 - Tidal Force
class spell_sha_tidal_force_dummy : public SpellScriptLoader
{
    public:
        spell_sha_tidal_force_dummy() : SpellScriptLoader("spell_sha_tidal_force_dummy") { }

        class spell_sha_tidal_force_dummy_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_tidal_force_dummy_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_TIDAL_FORCE_CRIT))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                eventInfo.GetActor()->RemoveAuraFromStack(SPELL_SHAMAN_TIDAL_FORCE_CRIT);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_sha_tidal_force_dummy_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_tidal_force_dummy_AuraScript();
        }
};

// -51490 - Thunderstorm
class spell_sha_thunderstorm : public SpellScriptLoader
{
    public:
        spell_sha_thunderstorm() : SpellScriptLoader("spell_sha_thunderstorm") { }

        class spell_sha_thunderstorm_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_thunderstorm_SpellScript);

            void HandleKnockBack(SpellEffIndex effIndex)
            {
                // Glyph of Thunderstorm
                if (GetCaster()->HasAura(SPELL_SHAMAN_GLYPH_OF_THUNDERSTORM))
                    PreventHitDefaultEffect(effIndex);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_sha_thunderstorm_SpellScript::HandleKnockBack, EFFECT_2, SPELL_EFFECT_KNOCK_BACK);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_sha_thunderstorm_SpellScript();
        }
};

// 38443 - Totemic Mastery (Tier 6 - 2P)
class spell_sha_totemic_mastery : public SpellScriptLoader
{
public:
    spell_sha_totemic_mastery() : SpellScriptLoader("spell_sha_totemic_mastery") { }

    class spell_sha_totemic_mastery_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_sha_totemic_mastery_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_TOTEMIC_MASTERY))
                return false;
            return true;
        }

        void HandleDummy(AuraEffect const* /*aurEff*/)
        {
            Unit* target = GetTarget();
            for (uint8 i = SUMMON_SLOT_TOTEM; i < MAX_TOTEM_SLOT; ++i)
                if (!target->m_SummonSlot[i])
                    return;

            target->CastSpell(target, SPELL_SHAMAN_TOTEMIC_MASTERY, true);
            PreventDefaultAction();
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_sha_totemic_mastery_AuraScript::HandleDummy, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_sha_totemic_mastery_AuraScript();
    }
};

// 28823 - Totemic Power
class spell_sha_t3_6p_bonus : public SpellScriptLoader
{
    public:
        spell_sha_t3_6p_bonus() : SpellScriptLoader("spell_sha_t3_6p_bonus") { }

        class spell_sha_t3_6p_bonus_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_t3_6p_bonus_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_TOTEMIC_POWER_ARMOR) ||
                    !sSpellMgr->GetSpellInfo(SPELL_SHAMAN_TOTEMIC_POWER_ATTACK_POWER) ||
                    !sSpellMgr->GetSpellInfo(SPELL_SHAMAN_TOTEMIC_POWER_SPELL_POWER) ||
                    !sSpellMgr->GetSpellInfo(SPELL_SHAMAN_TOTEMIC_POWER_MP5))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                uint32 spellId;
                Unit* caster = eventInfo.GetActor();
                Unit* target = eventInfo.GetProcTarget();

                switch (target->getClass())
                {
                    case CLASS_PALADIN:
                    case CLASS_PRIEST:
                    case CLASS_SHAMAN:
                    case CLASS_DRUID:
                        spellId = SPELL_SHAMAN_TOTEMIC_POWER_MP5;
                        break;
                    case CLASS_MAGE:
                    case CLASS_WARLOCK:
                        spellId = SPELL_SHAMAN_TOTEMIC_POWER_SPELL_POWER;
                        break;
                    case CLASS_HUNTER:
                    case CLASS_ROGUE:
                        spellId = SPELL_SHAMAN_TOTEMIC_POWER_ATTACK_POWER;
                        break;
                    case CLASS_WARRIOR:
                        spellId = SPELL_SHAMAN_TOTEMIC_POWER_ARMOR;
                        break;
                    default:
                        return;
                }

                caster->CastSpell(target, spellId, true);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_sha_t3_6p_bonus_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_t3_6p_bonus_AuraScript();
        }
};

// 64928 - Item - Shaman T8 Elemental 4P Bonus
class spell_sha_t8_elemental_4p_bonus : public SpellScriptLoader
{
    public:
        spell_sha_t8_elemental_4p_bonus() : SpellScriptLoader("spell_sha_t8_elemental_4p_bonus") { }

        class spell_sha_t8_elemental_4p_bonus_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_t8_elemental_4p_bonus_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_ELECTRIFIED))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                DamageInfo* damageInfo = eventInfo.GetDamageInfo();
                if (!damageInfo || !damageInfo->GetDamage())
                    return;

                SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(SPELL_SHAMAN_ELECTRIFIED);
                int32 amount = CalculatePct(static_cast<int32>(damageInfo->GetDamage()), aurEff->GetAmount());
                amount /= spellInfo->GetMaxTicks();

                // Add remaining ticks to healing done
                Unit* caster = eventInfo.GetActor();
                Unit* target = eventInfo.GetProcTarget();
                amount += target->GetRemainingPeriodicAmount(caster->GetGUID(), SPELL_SHAMAN_ELECTRIFIED, SPELL_AURA_PERIODIC_DAMAGE);

                caster->CastCustomSpell(SPELL_SHAMAN_ELECTRIFIED, SPELLVALUE_BASE_POINT0, amount, target, true);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_sha_t8_elemental_4p_bonus_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_t8_elemental_4p_bonus_AuraScript();
        }
};

// 67228 - Item - Shaman T9 Elemental 4P Bonus (Lava Burst)
class spell_sha_t9_elemental_4p_bonus : public SpellScriptLoader
{
    public:
        spell_sha_t9_elemental_4p_bonus() : SpellScriptLoader("spell_sha_t9_elemental_4p_bonus") { }

        class spell_sha_t9_elemental_4p_bonus_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_t9_elemental_4p_bonus_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_LAVA_BURST_BONUS_DAMAGE))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                DamageInfo* damageInfo = eventInfo.GetDamageInfo();
                if (!damageInfo || !damageInfo->GetDamage())
                    return;

                SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(SPELL_SHAMAN_LAVA_BURST_BONUS_DAMAGE);
                int32 amount = CalculatePct(static_cast<int32>(damageInfo->GetDamage()), aurEff->GetAmount());
                amount /= spellInfo->GetMaxTicks();

                // Add remaining ticks to healing done
                Unit* caster = eventInfo.GetActor();
                Unit* target = eventInfo.GetProcTarget();
                amount += target->GetRemainingPeriodicAmount(caster->GetGUID(), SPELL_SHAMAN_LAVA_BURST_BONUS_DAMAGE, SPELL_AURA_PERIODIC_DAMAGE);

                caster->CastCustomSpell(SPELL_SHAMAN_LAVA_BURST_BONUS_DAMAGE, SPELLVALUE_BASE_POINT0, amount, target, true);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_sha_t9_elemental_4p_bonus_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_t9_elemental_4p_bonus_AuraScript();
        }
};

// 70817 - Item - Shaman T10 Elemental 4P Bonus
class spell_sha_t10_elemental_4p_bonus : public SpellScriptLoader
{
    public:
        spell_sha_t10_elemental_4p_bonus() : SpellScriptLoader("spell_sha_t10_elemental_4p_bonus") { }

        class spell_sha_t10_elemental_4p_bonus_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_t10_elemental_4p_bonus_AuraScript);

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                Unit* caster = eventInfo.GetActor();
                Unit* target = eventInfo.GetProcTarget();

                // try to find spell Flame Shock on the target
                AuraEffect* flameShock = target->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_SHAMAN, 0x10000000, 0x00000000, 0x00000000, caster->GetGUID());
                if (!flameShock)
                    return;

                Aura* flameShockAura = flameShock->GetBase();

                int32 maxDuration = flameShockAura->GetMaxDuration();
                int32 newDuration = flameShockAura->GetDuration() + aurEff->GetAmount() * IN_MILLISECONDS;

                flameShockAura->SetDuration(newDuration);
                // is it blizzlike to change max duration for FS?
                if (newDuration > maxDuration)
                    flameShockAura->SetMaxDuration(newDuration);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_sha_t10_elemental_4p_bonus_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_t10_elemental_4p_bonus_AuraScript();
        }
};

// 70808 - Item - Shaman T10 Restoration 4P Bonus
class spell_sha_t10_restoration_4p_bonus : public SpellScriptLoader
{
    public:
        spell_sha_t10_restoration_4p_bonus() : SpellScriptLoader("spell_sha_t10_restoration_4p_bonus") { }

        class spell_sha_t10_restoration_4p_bonus_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_t10_restoration_4p_bonus_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_CHAINED_HEAL))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                HealInfo* healInfo = eventInfo.GetHealInfo();
                if (!healInfo || !healInfo->GetHeal())
                    return;

                SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(SPELL_SHAMAN_CHAINED_HEAL);
                int32 amount = CalculatePct(static_cast<int32>(healInfo->GetHeal()), aurEff->GetAmount());
                amount /= spellInfo->GetMaxTicks();

                // Add remaining ticks to healing done
                Unit* caster = eventInfo.GetActor();
                Unit* target = eventInfo.GetProcTarget();
                amount += target->GetRemainingPeriodicAmount(caster->GetGUID(), SPELL_SHAMAN_CHAINED_HEAL, SPELL_AURA_PERIODIC_HEAL);

                caster->CastCustomSpell(SPELL_SHAMAN_CHAINED_HEAL, SPELLVALUE_BASE_POINT0, amount, target, true);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_sha_t10_restoration_4p_bonus_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_t10_restoration_4p_bonus_AuraScript();
        }
};

// 33757 - Windfury Weapon (Passive)
class spell_sha_windfury_weapon : public SpellScriptLoader
{
    public:
        spell_sha_windfury_weapon() : SpellScriptLoader("spell_sha_windfury_weapon") { }

        class spell_sha_windfury_weapon_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_windfury_weapon_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_WINDFURY_WEAPON_R1) ||
                    !sSpellMgr->GetSpellInfo(SPELL_SHAMAN_WINDFURY_ATTACK_MH) ||
                    !sSpellMgr->GetSpellInfo(SPELL_SHAMAN_WINDFURY_ATTACK_OH))
                    return false;
                return true;
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {

                Player* player = eventInfo.GetActor()->ToPlayer();
                if (!player)
                    return false;

                Item* item = player->GetItemByGuid(GetAura()->GetCastItemGUID());
                if (!item || !item->IsEquipped())
                    return false;

                WeaponAttackType attType = static_cast<WeaponAttackType>(player->GetAttackBySlot(item->GetSlot()));
                if (attType != BASE_ATTACK && attType != OFF_ATTACK)
                    return false;

                if (((attType == BASE_ATTACK) && !(eventInfo.GetTypeMask() & PROC_FLAG_DONE_MAINHAND_ATTACK)) ||
                    ((attType == OFF_ATTACK) && !(eventInfo.GetTypeMask() & PROC_FLAG_DONE_OFFHAND_ATTACK)))
                    return false;

                return true;
            }

            void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                Player* player = eventInfo.GetActor()->ToPlayer();

                uint32 spellId = 0;
                WeaponAttackType attType = BASE_ATTACK;
                if (eventInfo.GetTypeMask() & PROC_FLAG_DONE_MAINHAND_ATTACK)
                    spellId = SPELL_SHAMAN_WINDFURY_ATTACK_MH;

                if (eventInfo.GetTypeMask() & PROC_FLAG_DONE_OFFHAND_ATTACK)
                {
                    spellId = SPELL_SHAMAN_WINDFURY_ATTACK_OH;
                    attType = OFF_ATTACK;
                }

                Item* item = ASSERT_NOTNULL(player->GetWeaponForAttack(attType));

                int32 enchantId = static_cast<int32>(item->GetEnchantmentId(TEMP_ENCHANTMENT_SLOT));
                int32 extraAttackPower = 0;
                SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(SPELL_SHAMAN_WINDFURY_WEAPON_R1);
                while (spellInfo)
                {
                    if (spellInfo->Effects[EFFECT_0].MiscValue == enchantId)
                    {
                        extraAttackPower = spellInfo->Effects[EFFECT_1].CalcValue(player);
                        break;
                    }
                    spellInfo = spellInfo->GetNextRankSpell();
                }

                if (!extraAttackPower)
                    return;

                // Value gained from additional AP
                int32 amount = static_cast<int32>(extraAttackPower / 14.f * player->GetAttackTime(attType) / 1000.f);

                // Attack twice
                for (uint8 i = 0; i < 2; ++i)
                    player->CastCustomSpell(spellId, SPELLVALUE_BASE_POINT0, amount, eventInfo.GetProcTarget(), true, item);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_sha_windfury_weapon_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_sha_windfury_weapon_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_windfury_weapon_AuraScript();
        }
};

void AddSC_shaman_spell_scripts()
{
    new spell_sha_ancestral_awakening();
    new spell_sha_ancestral_awakening_proc();
    new spell_sha_astral_shift();
    new spell_sha_astral_shift_aura();
    new spell_sha_bloodlust();
    new spell_sha_chain_heal();
    new spell_sha_cleansing_totem_pulse();
    new spell_sha_earth_shield();
    new spell_sha_earthbind_totem();
    new spell_sha_earthen_power();
    new spell_sha_fire_nova();
    new spell_sha_flame_shock();
    new spell_sha_flametongue_weapon();
    new spell_sha_frozen_power();
    new spell_sha_glyph_of_earth_shield();
    new spell_sha_glyph_of_healing_wave();
    new spell_sha_glyph_of_totem_of_wrath();
    new spell_sha_healing_stream_totem();
    new spell_sha_heroism();
    new spell_sha_imp_water_shield();
    new spell_sha_lightning_overload();
    new spell_sha_item_lightning_shield();
    new spell_sha_item_lightning_shield_trigger();
    new spell_sha_item_mana_surge();
    new spell_sha_item_t6_trinket();
    new spell_sha_item_t10_elemental_2p_bonus();
    new spell_sha_lava_lash();
    new spell_sha_lightning_shield();
    new spell_sha_maelstrom_weapon();
    new spell_sha_mana_spring_totem();
    new spell_sha_mana_tide_totem();
    new spell_sha_nature_guardian();
    new spell_sha_sentry_totem();
    new spell_sha_shamanistic_rage();
    new spell_sha_spirit_hunt();
    new spell_sha_static_shock();
    new spell_sha_tidal_force_dummy();
    new spell_sha_thunderstorm();
    new spell_sha_totemic_mastery();
    new spell_sha_t3_6p_bonus();
    new spell_sha_t8_elemental_4p_bonus();
    new spell_sha_t9_elemental_4p_bonus();
    new spell_sha_t10_elemental_4p_bonus();
    new spell_sha_t10_restoration_4p_bonus();
    new spell_sha_windfury_weapon();
}
