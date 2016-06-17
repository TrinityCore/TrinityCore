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

#include "ScriptMgr.h"
#include "CellImpl.h"
#include "CreatureAIImpl.h" // for RAND()
#include "GridNotifiersImpl.h"
#include "Player.h"
#include "SpellScript.h"
#include "SpellHistory.h"
#include "SpellAuraEffects.h"

enum ShamanSpells
{
    SPELL_SHAMAN_EARTH_SHIELD_HEAL              = 379,
    SPELL_SHAMAN_EARTH_SHOCK                    = 8042,
    SPELL_SHAMAN_ELEMENTAL_BLAST_CRIT           = 118522,
    SPELL_SHAMAN_ELEMENTAL_BLAST_HASTE          = 173183,
    SPELL_SHAMAN_ELEMENTAL_BLAST_MASTERY        = 173184,
    SPELL_SHAMAN_ELEMENTAL_BLAST_MULTISTRIKE    = 173185,
    SPELL_SHAMAN_ELEMENTAL_BLAST_AGILITY        = 173186,
    SPELL_SHAMAN_ELEMENTAL_BLAST_SPIRIT         = 173187,
    SPELL_SHAMAN_ELEMENTAL_MASTERY              = 16166,
    SPELL_SHAMAN_EXHAUSTION                     = 57723,
    SPELL_SHAMAN_FIRE_NOVA_TRIGGERED            = 8349,
    SPELL_SHAMAN_FLAME_SHOCK                    = 8050,
    SPELL_SHAMAN_FLAMETONGUE_ATTACK             = 10444,
    SPELL_SHAMAN_FULMINATION                    = 88767,
    SPELL_SHAMAN_FULMINATION_UI_INDICATOR       = 95774,
    SPELL_SHAMAN_GLYPH_OF_HEALING_STREAM_TOTEM  = 55456,
    SPELL_SHAMAN_GLYPH_OF_HEALING_STREAM_TOTEM_TRIGGERED = 119523,
    SPELL_SHAMAN_GLYPH_OF_HEALING_WAVE          = 55533,
    SPELL_SHAMAN_GLYPH_OF_LAVA_LASH             = 55444,
    SPELL_SHAMAN_GLYPH_OF_THUNDERSTORM          = 62132,
    SPELL_SHAMAN_HEALING_STREAM_DUMMY           = 98856,
    SPELL_SHAMAN_HIGH_TIDE                      = 157154,
    SPELL_SHAMAN_IMPROVED_LIGHTNING_SHIELD      = 157774,
    SPELL_SHAMAN_ITEM_LIGHTNING_SHIELD          = 23552,
    SPELL_SHAMAN_ITEM_LIGHTNING_SHIELD_DAMAGE   = 27635,
    SPELL_SHAMAN_ITEM_MANA_SURGE                = 23571,
    SPELL_SHAMAN_ITEM_T18_ELEMENTAL_2P_BONUS    = 185880,
    SPELL_SHAMAN_ITEM_T18_ELEMENTAL_4P_BONUS    = 185881,
    SPELL_SHAMAN_ITEM_T18_GATHERING_VORTEX      = 189078,
    SPELL_SHAMAN_ITEM_T18_LIGHTNING_VORTEX      = 189063,
    SPELL_SHAMAN_LAVA_BURST                     = 51505,
    SPELL_SHAMAN_LAVA_LASH_SPREAD_FLAME_SHOCK   = 105792,
    SPELL_SHAMAN_LAVA_SURGE                     = 77762,
    SPELL_SHAMAN_LIGHTNING_SHIELD               = 324,
    SPELL_SHAMAN_NATURE_GUARDIAN                = 31616,
    SPELL_SHAMAN_RIPTIDE                        = 61295,
    SPELL_SHAMAN_RUSHING_STREAMS                = 147074,
    SPELL_SHAMAN_SATED                          = 57724,
    SPELL_SHAMAN_TOTEM_HEALING_STREAM_HEAL      = 52042,
    SPELL_SHAMAN_TIDAL_WAVES                    = 53390,
    SPELL_SHAMAN_WINDFURY_ATTACK                = 25504
};

enum MiscSpells
{
    SPELL_HUNTER_INSANITY                       = 95809,
    SPELL_MAGE_TEMPORAL_DISPLACEMENT            = 80354,
    SPELL_PET_NETHERWINDS_FATIGUED              = 160455
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
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_SATED)
                    || !sSpellMgr->GetSpellInfo(SPELL_HUNTER_INSANITY)
                    || !sSpellMgr->GetSpellInfo(SPELL_MAGE_TEMPORAL_DISPLACEMENT)
                    || !sSpellMgr->GetSpellInfo(SPELL_PET_NETHERWINDS_FATIGUED))
                    return false;
                return true;
            }

            void RemoveInvalidTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if(Trinity::UnitAuraCheck(true, SPELL_SHAMAN_SATED));
                targets.remove_if(Trinity::UnitAuraCheck(true, SPELL_HUNTER_INSANITY));
                targets.remove_if(Trinity::UnitAuraCheck(true, SPELL_MAGE_TEMPORAL_DISPLACEMENT));
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
                AfterHit += SpellHitFn(spell_sha_bloodlust_SpellScript::ApplyDebuff);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_sha_bloodlust_SpellScript();
        }
};

// 1064 - Chain Heal
class spell_sha_chain_heal : public SpellScriptLoader
{
    public:
        spell_sha_chain_heal() : SpellScriptLoader("spell_sha_chain_heal") { }

        class spell_sha_chain_heal_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_chain_heal_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_HIGH_TIDE))
                    return false;
                return true;
            }

            void CatchInitialTarget(WorldObject*& target)
            {
                _primaryTarget = target;
            }

            void SelectAdditionalTargets(std::list<WorldObject*>& targets)
            {
                Unit* caster = GetCaster();
                AuraEffect const* highTide = caster->GetAuraEffect(SPELL_SHAMAN_HIGH_TIDE, EFFECT_1);
                if (!highTide)
                    return;

                static float const range = 25.0f;
                SpellImplicitTargetInfo targetInfo(TARGET_UNIT_TARGET_CHAINHEAL_ALLY);
                ConditionContainer* conditions = GetSpellInfo()->GetEffect(EFFECT_0)->ImplicitTargetConditions;

                uint32 containerTypeMask = GetSpell()->GetSearcherTypeMask(targetInfo.GetObjectType(), conditions);
                if (!containerTypeMask)
                    return;

                std::list<WorldObject*> chainTargets;
                Trinity::WorldObjectSpellAreaTargetCheck check(range, _primaryTarget, caster, caster, GetSpellInfo(), targetInfo.GetCheckType(), conditions);
                Trinity::WorldObjectListSearcher<Trinity::WorldObjectSpellAreaTargetCheck> searcher(caster, chainTargets, check, containerTypeMask);
                caster->GetMap()->VisitAll(_primaryTarget->GetPositionX(), _primaryTarget->GetPositionY(), range, searcher);

                chainTargets.remove_if(Trinity::UnitAuraCheck(false, SPELL_SHAMAN_RIPTIDE, caster->GetGUID()));
                if (chainTargets.empty())
                    return;

                chainTargets.sort();
                targets.sort();

                std::list<WorldObject*> extraTargets;
                std::set_difference(chainTargets.begin(), chainTargets.end(), targets.begin(), targets.end(), std::back_inserter(extraTargets));
                Trinity::Containers::RandomResizeList(extraTargets, uint32(highTide->GetAmount()));
                targets.splice(targets.end(), extraTargets);
            }

            WorldObject* _primaryTarget = nullptr;

            void Register() override
            {
                OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_sha_chain_heal_SpellScript::CatchInitialTarget, EFFECT_0, TARGET_UNIT_TARGET_CHAINHEAL_ALLY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_chain_heal_SpellScript::SelectAdditionalTargets, EFFECT_0, TARGET_UNIT_TARGET_CHAINHEAL_ALLY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_sha_chain_heal_SpellScript();
        }
};

// 974 - Earth Shield
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

            void CalculateAmount(AuraEffect const* aurEff, int32& amount, bool & /*canBeRecalculated*/)
            {
                if (Unit* caster = GetCaster())
                {
                    amount = caster->SpellHealingBonusDone(GetUnitOwner(), GetSpellInfo(), amount, HEAL, aurEff->GetSpellEffectInfo());
                    amount = GetUnitOwner()->SpellHealingBonusTaken(caster, GetSpellInfo(), amount, HEAL, aurEff->GetSpellEffectInfo());

                    //! WORKAROUND
                    // If target is affected by healing reduction, modifier is guaranteed to be negative
                    // value (e.g. -50). To revert the effect, multiply amount with reciprocal of relative value:
                    // (100 / ((-1) * modifier)) * 100 = (-1) * 100 * 100 / modifier = -10000 / modifier
                    if (int32 modifier = GetUnitOwner()->GetMaxNegativeAuraModifier(SPELL_AURA_MOD_HEALING_PCT))
                        ApplyPct(amount, -10000.0f / float(modifier));
                }
            }

            bool CheckProc(ProcEventInfo& /*eventInfo*/)
            {
                //! HACK due to currenct proc system implementation
                if (Player* player = GetTarget()->ToPlayer())
                    if (player->GetSpellHistory()->HasCooldown(SPELL_SHAMAN_EARTH_SHIELD_HEAL))
                        return false;
                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();

                GetTarget()->CastCustomSpell(SPELL_SHAMAN_EARTH_SHIELD_HEAL, SPELLVALUE_BASE_POINT0, aurEff->GetAmount(), GetTarget(), true, NULL, aurEff, GetCasterGUID());

                /// @hack: due to currenct proc system implementation
                if (Player* player = GetTarget()->ToPlayer())
                    player->GetSpellHistory()->AddCooldown(SPELL_SHAMAN_EARTH_SHIELD_HEAL, 0, std::chrono::seconds(3));
            }

            void Register() override
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_sha_earth_shield_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_DUMMY);
                DoCheckProc += AuraCheckProcFn(spell_sha_earth_shield_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_sha_earth_shield_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_earth_shield_AuraScript();
        }
};

// 117014 - Elemental Blast
class spell_sha_elemental_blast : public SpellScriptLoader
{
public:
    spell_sha_elemental_blast() : SpellScriptLoader("spell_sha_elemental_blast") { }

    class spell_sha_elemental_blast_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_sha_elemental_blast_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_ELEMENTAL_BLAST_CRIT))
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_ELEMENTAL_BLAST_HASTE))
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_ELEMENTAL_BLAST_MASTERY))
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_ELEMENTAL_BLAST_MULTISTRIKE))
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_ELEMENTAL_BLAST_AGILITY))
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_ELEMENTAL_BLAST_SPIRIT))
                return false;
            return true;
        }

        bool Load() override
        {
            return GetCaster()->GetTypeId() == TYPEID_PLAYER;
        }

        void TriggerBuff()
        {
            Player* caster = GetCaster()->ToPlayer();
            uint32 spellId;
            if (caster->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID) == TALENT_SPEC_SHAMAN_ENHANCEMENT)
                spellId = RAND(SPELL_SHAMAN_ELEMENTAL_BLAST_CRIT, SPELL_SHAMAN_ELEMENTAL_BLAST_HASTE, SPELL_SHAMAN_ELEMENTAL_BLAST_MASTERY, SPELL_SHAMAN_ELEMENTAL_BLAST_MULTISTRIKE, SPELL_SHAMAN_ELEMENTAL_BLAST_AGILITY);
            else
                spellId = RAND(SPELL_SHAMAN_ELEMENTAL_BLAST_CRIT, SPELL_SHAMAN_ELEMENTAL_BLAST_HASTE, SPELL_SHAMAN_ELEMENTAL_BLAST_MASTERY, SPELL_SHAMAN_ELEMENTAL_BLAST_MULTISTRIKE);

            caster->CastSpell(caster, spellId, TRIGGERED_FULL_MASK);
            if (caster->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID) == TALENT_SPEC_SHAMAN_RESTORATION)
                caster->CastSpell(caster, SPELL_SHAMAN_ELEMENTAL_BLAST_SPIRIT, TRIGGERED_FULL_MASK);
        }

        void Register() override
        {
            AfterCast += SpellCastFn(spell_sha_elemental_blast_SpellScript::TriggerBuff);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_sha_elemental_blast_SpellScript();
    }
};

// 1535 Fire Nova
class spell_sha_fire_nova : public SpellScriptLoader
{
    public:
        spell_sha_fire_nova() : SpellScriptLoader("spell_sha_fire_nova") { }

        class spell_sha_fire_nova_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_fire_nova_SpellScript);

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                if (Unit* target = GetHitUnit())
                    if (target->HasAura(SPELL_SHAMAN_FLAME_SHOCK))
                        GetCaster()->CastSpell(target, SPELL_SHAMAN_FIRE_NOVA_TRIGGERED, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_sha_fire_nova_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_sha_fire_nova_SpellScript();
        }
};

// 10400 - Flametongue
class spell_sha_flametongue : public SpellScriptLoader
{
public:
    spell_sha_flametongue() : SpellScriptLoader("spell_sha_flametongue") { }

    class spell_sha_flametongue_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_sha_flametongue_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_FLAMETONGUE_ATTACK))
                return false;
            return true;
        }

        void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
        {
            PreventDefaultAction();

            Unit* attacker = eventInfo.GetActor();
            int32 damage = int32(attacker->GetTotalAttackPowerValue(BASE_ATTACK) * 0.075f / 2600 * attacker->GetAttackTime(BASE_ATTACK));
            attacker->CastCustomSpell(SPELL_SHAMAN_FLAMETONGUE_ATTACK, SPELLVALUE_BASE_POINT0, damage, eventInfo.GetActionTarget(), TRIGGERED_FULL_MASK, nullptr, aurEff);
        }

        void Register() override
        {
            OnEffectProc += AuraEffectProcFn(spell_sha_flametongue_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_sha_flametongue_AuraScript();
    }
};

// 88766 - Fulmination
class spell_sha_fulmination : public SpellScriptLoader
{
    public:
        spell_sha_fulmination() : SpellScriptLoader("spell_sha_fulmination") { }

        class spell_sha_fulmination_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_fulmination_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_FULMINATION))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_FULMINATION_UI_INDICATOR))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_IMPROVED_LIGHTNING_SHIELD))
                    return false;
                SpellInfo const* lightningShield = sSpellMgr->GetSpellInfo(SPELL_SHAMAN_LIGHTNING_SHIELD);
                if (!lightningShield || !lightningShield->GetEffect(EFFECT_0) || !sSpellMgr->GetSpellInfo(lightningShield->GetEffect(EFFECT_0)->TriggerSpell))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_ITEM_T18_ELEMENTAL_2P_BONUS))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_ITEM_T18_ELEMENTAL_4P_BONUS))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_ITEM_T18_LIGHTNING_VORTEX))
                    return false;
                return true;
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                // Lava Burst cannot add lightning shield stacks without Improved Lightning Shield
                if ((eventInfo.GetSpellInfo()->SpellFamilyFlags[1] & 0x00001000) && !eventInfo.GetActor()->HasAura(SPELL_SHAMAN_IMPROVED_LIGHTNING_SHIELD))
                    return false;

                return eventInfo.GetActor()->HasAura(SPELL_SHAMAN_LIGHTNING_SHIELD);
            }

            void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                Unit* caster = eventInfo.GetActor();
                Unit* target = eventInfo.GetActionTarget();
                if (Aura* aura = caster->GetAura(SPELL_SHAMAN_LIGHTNING_SHIELD))
                {
                    // Earth Shock releases the charges
                    if (eventInfo.GetSpellInfo()->SpellFamilyFlags[0] & 0x00100000)
                    {
                        uint32 stacks = aura->GetCharges();
                        if (stacks > 1)
                        {
                            SpellInfo const* triggerSpell = sSpellMgr->AssertSpellInfo(aura->GetSpellEffectInfo(EFFECT_0)->TriggerSpell);
                            SpellEffectInfo const* triggerEffect = triggerSpell->GetEffect(EFFECT_0);

                            uint32 damage;
                            damage = caster->SpellDamageBonusDone(target, triggerSpell, uint32(triggerEffect->CalcValue(caster)), SPELL_DIRECT_DAMAGE, triggerEffect, stacks - 1);
                            damage = target->SpellDamageBonusTaken(caster, triggerSpell, damage, SPELL_DIRECT_DAMAGE, triggerEffect, stacks - 1);

                            caster->CastCustomSpell(SPELL_SHAMAN_FULMINATION, SPELLVALUE_BASE_POINT0, int32(damage), target, TRIGGERED_FULL_MASK);
                            caster->RemoveAurasDueToSpell(SPELL_SHAMAN_FULMINATION_UI_INDICATOR);

                            if (AuraEffect const* t18_4p = caster->GetAuraEffect(SPELL_SHAMAN_ITEM_T18_ELEMENTAL_4P_BONUS, EFFECT_0))
                            {
                                if (Aura* gatheringVortex = caster->GetAura(SPELL_SHAMAN_ITEM_T18_GATHERING_VORTEX))
                                {
                                    if (gatheringVortex->GetStackAmount() + stacks >= uint32(t18_4p->GetAmount()))
                                        caster->CastSpell(caster, SPELL_SHAMAN_ITEM_T18_LIGHTNING_VORTEX, TRIGGERED_FULL_MASK);

                                    if (uint8 newStacks = uint8((gatheringVortex->GetStackAmount() + stacks) % t18_4p->GetAmount()))
                                        gatheringVortex->SetStackAmount(newStacks);
                                    else
                                        gatheringVortex->Remove();
                                }
                                else
                                    caster->CastCustomSpell(SPELL_SHAMAN_ITEM_T18_GATHERING_VORTEX, SPELLVALUE_AURA_STACK, stacks, caster, TRIGGERED_FULL_MASK);
                            }

                            if (AuraEffect const* t18_2p = caster->GetAuraEffect(SPELL_SHAMAN_ITEM_T18_ELEMENTAL_2P_BONUS, EFFECT_0))
                            {
                                if (roll_chance_i(t18_2p->GetAmount()))
                                {
                                    caster->GetSpellHistory()->ResetCooldown(SPELL_SHAMAN_EARTH_SHOCK, true);
                                    return;
                                }
                            }

                            aura->SetCharges(1);
                            aura->SetUsingCharges(false);
                        }
                    }
                    else
                    {
                        aura->SetCharges(std::min<uint8>(aura->GetCharges() + 1, uint8(aurEff->GetAmount())));
                        aura->SetUsingCharges(false);
                        aura->RefreshDuration();

                        if (aura->GetCharges() == aurEff->GetAmount())
                            caster->CastSpell(caster, SPELL_SHAMAN_FULMINATION_UI_INDICATOR, TRIGGERED_FULL_MASK);
                    }
                }
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_sha_fulmination_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_sha_fulmination_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_fulmination_AuraScript();
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
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_GLYPH_OF_HEALING_WAVE))
                    return false;
                return true;
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                // Not proc from self heals
                return GetTarget() != eventInfo.GetProcTarget();
            }

            void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                int32 heal = CalculatePct(int32(eventInfo.GetHealInfo()->GetHeal()), aurEff->GetAmount());

                GetTarget()->CastCustomSpell(SPELL_SHAMAN_GLYPH_OF_HEALING_WAVE, SPELLVALUE_BASE_POINT0, heal, (Unit*)NULL, true, NULL, aurEff);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_sha_glyph_of_healing_wave_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_sha_glyph_of_healing_wave_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_glyph_of_healing_wave_AuraScript();
        }
};

// 5394 - Healing Stream Totem
class spell_sha_healing_stream_totem : public SpellScriptLoader
{
    public:
        spell_sha_healing_stream_totem() : SpellScriptLoader("spell_sha_healing_stream_totem") { }

        class spell_sha_healing_stream_totem_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_healing_stream_totem_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return sSpellMgr->GetSpellInfo(SPELL_SHAMAN_TOTEM_HEALING_STREAM_HEAL) != nullptr;
            }

            void HandleDummy(AuraEffect const* aurEff)
            {
                if (Creature* waterTotem = GetTarget()->GetMap()->GetCreature(GetTarget()->m_SummonSlot[3]))
                    waterTotem->CastSpell((Unit*)nullptr, SPELL_SHAMAN_TOTEM_HEALING_STREAM_HEAL, TRIGGERED_FULL_MASK, nullptr, aurEff, GetTarget()->GetGUID());
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_sha_healing_stream_totem_AuraScript::HandleDummy, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_healing_stream_totem_AuraScript();
        }
};

// 52042 - Healing Stream Totem
class spell_sha_healing_stream_totem_heal : public SpellScriptLoader
{
    public:
        spell_sha_healing_stream_totem_heal() : SpellScriptLoader("spell_sha_healing_stream_totem_heal") { }

        class spell_sha_healing_stream_totem_heal_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_healing_stream_totem_heal_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/)
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_RUSHING_STREAMS) ||
                    !sSpellMgr->GetSpellInfo(SPELL_SHAMAN_GLYPH_OF_HEALING_STREAM_TOTEM) ||
                    !sSpellMgr->GetSpellInfo(SPELL_SHAMAN_GLYPH_OF_HEALING_STREAM_TOTEM_TRIGGERED) ||
                    !sSpellMgr->GetSpellInfo(SPELL_SHAMAN_HEALING_STREAM_DUMMY))
                    return false;

                return true;
            }

            void SelectTargets(std::list<WorldObject*>& targets)
            {
                uint32 targetLimit = 1;
                if (GetOriginalCaster()->HasAura(SPELL_SHAMAN_RUSHING_STREAMS))
                    targetLimit = 2;

                targets.remove_if([](WorldObject* target)
                {
                    return !target->ToUnit() || target->ToUnit()->IsFullHealth();
                });

                Trinity::Containers::RandomResizeList(targets, targetLimit);

                if (targets.empty())
                    targets.push_back(GetOriginalCaster());
            }

            void HandleEffect(SpellEffIndex /*effIndex*/)
            {
                if (GetOriginalCaster()->HasAura(SPELL_SHAMAN_GLYPH_OF_HEALING_STREAM_TOTEM))
                    GetCaster()->CastSpell(GetHitUnit(), SPELL_SHAMAN_GLYPH_OF_HEALING_STREAM_TOTEM_TRIGGERED, TRIGGERED_FULL_MASK);

                GetCaster()->CastSpell(GetHitUnit(), SPELL_SHAMAN_HEALING_STREAM_DUMMY, TRIGGERED_FULL_MASK);
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_healing_stream_totem_heal_SpellScript::SelectTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
                OnEffectHitTarget += SpellEffectFn(spell_sha_healing_stream_totem_heal_SpellScript::HandleEffect, EFFECT_0, SPELL_EFFECT_HEAL);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_sha_healing_stream_totem_heal_SpellScript();
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
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_EXHAUSTION)
                    || !sSpellMgr->GetSpellInfo(SPELL_HUNTER_INSANITY)
                    || !sSpellMgr->GetSpellInfo(SPELL_MAGE_TEMPORAL_DISPLACEMENT)
                    || !sSpellMgr->GetSpellInfo(SPELL_PET_NETHERWINDS_FATIGUED))
                    return false;
                return true;
            }

            void RemoveInvalidTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if(Trinity::UnitAuraCheck(true, SPELL_SHAMAN_EXHAUSTION));
                targets.remove_if(Trinity::UnitAuraCheck(true, SPELL_HUNTER_INSANITY));
                targets.remove_if(Trinity::UnitAuraCheck(true, SPELL_MAGE_TEMPORAL_DISPLACEMENT));
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
                AfterHit += SpellHitFn(spell_sha_heroism_SpellScript::ApplyDebuff);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_sha_heroism_SpellScript();
        }
};

// 23551 - Lightning Shield
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

            void OnProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                GetTarget()->CastSpell(eventInfo.GetProcTarget(), SPELL_SHAMAN_ITEM_LIGHTNING_SHIELD, true, NULL, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_sha_item_lightning_shield_AuraScript::OnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_item_lightning_shield_AuraScript();
        }
};

// 23552 - Lightning Shield
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

            void OnProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                GetTarget()->CastSpell(GetTarget(), SPELL_SHAMAN_ITEM_LIGHTNING_SHIELD_DAMAGE, true, NULL, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_sha_item_lightning_shield_trigger_AuraScript::OnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
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
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_ITEM_LIGHTNING_SHIELD_DAMAGE))
                    return false;
                return true;
            }

            void OnProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                std::vector<SpellInfo::CostData> costs = eventInfo.GetDamageInfo()->GetSpellInfo()->CalcPowerCost(GetTarget(), eventInfo.GetDamageInfo()->GetSchoolMask());
                auto m = std::find_if(costs.begin(), costs.end(), [](SpellInfo::CostData const& cost) { return cost.Power == POWER_MANA; });
                if (m != costs.end())
                {
                    int32 mana = CalculatePct(m->Amount, 35);
                    if (mana > 0)
                        GetTarget()->CastCustomSpell(SPELL_SHAMAN_ITEM_MANA_SURGE, SPELLVALUE_BASE_POINT0, mana, GetTarget(), true, NULL, aurEff);
                }
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_sha_item_mana_surge_AuraScript::OnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_item_mana_surge_AuraScript();
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

// 189063 - Lightning Vortex (proc 185881 Item - Shaman T18 Elemental 4P Bonus)
class spell_sha_item_t18_elemental_4p_bonus : public SpellScriptLoader
{
public:
    spell_sha_item_t18_elemental_4p_bonus() : SpellScriptLoader("spell_sha_item_t18_elemental_4p_bonus") { }

    class spell_sha_item_t18_elemental_4p_bonus_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_sha_item_t18_elemental_4p_bonus_AuraScript);

        void DiminishHaste(AuraEffect const* aurEff)
        {
            PreventDefaultAction();
            if (AuraEffect* hasteBuff = GetEffect(EFFECT_0))
                hasteBuff->ChangeAmount(hasteBuff->GetAmount() - aurEff->GetAmount());
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_sha_item_t18_elemental_4p_bonus_AuraScript::DiminishHaste, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_sha_item_t18_elemental_4p_bonus_AuraScript();
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
                if (GetCaster()->HasAura(SPELL_SHAMAN_GLYPH_OF_LAVA_LASH))
                    return;

                GetCaster()->CastCustomSpell(SPELL_SHAMAN_LAVA_LASH_SPREAD_FLAME_SHOCK, SPELLVALUE_MAX_TARGETS, GetEffectValue(), GetHitUnit(), TRIGGERED_FULL_MASK);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_sha_lava_lash_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_WEAPON_PERCENT_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_sha_lava_lash_SpellScript();
        }
};

// 105792 - Lava Lash
class spell_sha_lava_lash_spread_flame_shock : public SpellScriptLoader
{
    public:
        spell_sha_lava_lash_spread_flame_shock() : SpellScriptLoader("spell_sha_lava_lash_spread_flame_shock") { }

        class spell_sha_lava_lash_spread_flame_shock_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_lava_lash_spread_flame_shock_SpellScript);

            bool Load() override
            {
                return GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if(Trinity::UnitAuraCheck(true, SPELL_SHAMAN_FLAME_SHOCK, GetCaster()->GetGUID()));
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (Unit* mainTarget = GetExplTargetUnit())
                {
                    if (Aura* flameShock = mainTarget->GetAura(SPELL_SHAMAN_FLAME_SHOCK, GetCaster()->GetGUID()))
                    {
                        if (Aura* newAura = GetCaster()->AddAura(SPELL_SHAMAN_FLAME_SHOCK, GetHitUnit()))
                        {
                            newAura->SetDuration(flameShock->GetDuration());
                            newAura->SetMaxDuration(flameShock->GetDuration());
                        }
                    }
                }
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_lava_lash_spread_flame_shock_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_sha_lava_lash_spread_flame_shock_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_sha_lava_lash_spread_flame_shock_SpellScript();
        }
};

// 77756 - Lava Surge
class spell_sha_lava_surge : public SpellScriptLoader
{
    public:
        spell_sha_lava_surge() : SpellScriptLoader("spell_sha_lava_surge") { }

        class spell_sha_lava_surge_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_lava_surge_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_LAVA_SURGE))
                    return false;
                return true;
            }

            void HandleEffectProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                GetTarget()->CastSpell(GetTarget(), SPELL_SHAMAN_LAVA_SURGE, true);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_sha_lava_surge_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_lava_surge_AuraScript();
        }
};

// 77762 - Lava Surge
class spell_sha_lava_surge_proc : public SpellScriptLoader
{
    public:
        spell_sha_lava_surge_proc() : SpellScriptLoader("spell_sha_lava_surge_proc") { }

        class spell_sha_lava_surge_proc_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_lava_surge_proc_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_LAVA_BURST))
                    return false;
                return true;
            }

            bool Load() override
            {
                return GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            void ResetCooldown()
            {
                GetCaster()->GetSpellHistory()->RestoreCharge(sSpellMgr->AssertSpellInfo(SPELL_SHAMAN_LAVA_BURST)->ChargeCategoryEntry);
            }

            void Register() override
            {
                AfterHit += SpellHitFn(spell_sha_lava_surge_proc_SpellScript::ResetCooldown);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_sha_lava_surge_proc_SpellScript();
        }
};

// 324 - Lightning Shield
class spell_sha_lightning_shield : public SpellScriptLoader
{
public:
    spell_sha_lightning_shield() : SpellScriptLoader("spell_sha_lightning_shield") { }

    class spell_sha_lightning_shield_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_sha_lightning_shield_AuraScript);

        void UnsetUsingCharges(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            GetAura()->SetUsingCharges(false);
        }

        void Register() override
        {
            OnEffectApply += AuraEffectApplyFn(spell_sha_lightning_shield_AuraScript::UnsetUsingCharges, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_sha_lightning_shield_AuraScript();
    }
};

// 30884 - Nature's Guardian
class spell_sha_nature_guardian : public SpellScriptLoader
{
    public:
        spell_sha_nature_guardian() : SpellScriptLoader("spell_sha_nature_guardian") { }

        class spell_sha_nature_guardian_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_nature_guardian_AuraScript);

            bool Validate(SpellInfo const* spellInfo) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_NATURE_GUARDIAN))
                    return false;
                if (!spellInfo->GetEffect(EFFECT_1))
                    return false;
                return true;
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                //! HACK due to currenct proc system implementation
                if (GetTarget()->GetSpellHistory()->HasCooldown(GetSpellInfo()->Id))
                    return false;

                return GetTarget()->HealthBelowPctDamaged(30, eventInfo.GetDamageInfo()->GetDamage());
            }

            void OnProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                int32 basePoints0 = GetTarget()->CountPctFromMaxHealth(aurEff->GetAmount());

                GetTarget()->CastCustomSpell(GetTarget(), SPELL_SHAMAN_NATURE_GUARDIAN, &basePoints0, NULL, NULL, true);

                if (eventInfo.GetProcTarget() && eventInfo.GetProcTarget()->IsAlive())
                    eventInfo.GetProcTarget()->getThreatManager().modifyThreatPercent(GetTarget(), -10);

                GetTarget()->GetSpellHistory()->AddCooldown(GetSpellInfo()->Id, 0, std::chrono::seconds(aurEff->GetSpellInfo()->GetEffect(EFFECT_1)->CalcValue()));
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_sha_nature_guardian_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_sha_nature_guardian_AuraScript::OnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_nature_guardian_AuraScript();
        }
};

// 51490 - Thunderstorm
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
                OnEffectHitTarget += SpellEffectFn(spell_sha_thunderstorm_SpellScript::HandleKnockBack, EFFECT_1, SPELL_EFFECT_KNOCK_BACK);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_sha_thunderstorm_SpellScript();
        }
};

// 51564 - Tidal Waves
class spell_sha_tidal_waves : public SpellScriptLoader
{
    public:
        spell_sha_tidal_waves() : SpellScriptLoader("spell_sha_tidal_waves") { }

        class spell_sha_tidal_waves_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_tidal_waves_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_TIDAL_WAVES))
                    return false;
                return true;
            }

            void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                int32 basePoints0 = -aurEff->GetAmount();
                int32 basePoints1 = aurEff->GetAmount();

                GetTarget()->CastCustomSpell(GetTarget(), SPELL_SHAMAN_TIDAL_WAVES, &basePoints0, &basePoints1, NULL, true, NULL, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_sha_tidal_waves_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_tidal_waves_AuraScript();
        }
};

// 33757 - Windfury
class spell_sha_windfury : public SpellScriptLoader
{
public:
    spell_sha_windfury() : SpellScriptLoader("spell_sha_windfury") { }

    class spell_sha_windfury_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_sha_windfury_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_WINDFURY_ATTACK))
                return false;
            return true;
        }

        void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
        {
            PreventDefaultAction();

            for (uint32 i = 0; i < 3; ++i)
                eventInfo.GetActor()->CastSpell(eventInfo.GetProcTarget(), SPELL_SHAMAN_WINDFURY_ATTACK, true, nullptr, aurEff);
        }

        void Register() override
        {
            OnEffectProc += AuraEffectProcFn(spell_sha_windfury_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_sha_windfury_AuraScript();
    }
};

void AddSC_shaman_spell_scripts()
{
    new spell_sha_bloodlust();
    new spell_sha_chain_heal();
    new spell_sha_earth_shield();
    new spell_sha_elemental_blast();
    new spell_sha_fire_nova();
    new spell_sha_flametongue();
    new spell_sha_fulmination();
    new spell_sha_glyph_of_healing_wave();
    new spell_sha_healing_stream_totem();
    new spell_sha_healing_stream_totem_heal();
    new spell_sha_heroism();
    new spell_sha_item_lightning_shield();
    new spell_sha_item_lightning_shield_trigger();
    new spell_sha_item_mana_surge();
    new spell_sha_item_t10_elemental_2p_bonus();
    new spell_sha_item_t18_elemental_4p_bonus();
    new spell_sha_lava_lash();
    new spell_sha_lava_lash_spread_flame_shock();
    new spell_sha_lava_surge();
    new spell_sha_lava_surge_proc();
    new spell_sha_lightning_shield();
    new spell_sha_nature_guardian();
    new spell_sha_thunderstorm();
    new spell_sha_tidal_waves();
    new spell_sha_windfury();
}
