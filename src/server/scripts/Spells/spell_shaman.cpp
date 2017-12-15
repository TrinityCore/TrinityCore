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
 * Scripts for spells with SPELLFAMILY_SHAMAN and SPELLFAMILY_GENERIC spells used by shaman players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_sha_".
 */

#include "ScriptMgr.h"
#include "CellImpl.h"
#include "CreatureAIImpl.h" // for RAND()
#include "GridNotifiersImpl.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "SpellScript.h"

enum ShamanSpells
{
    SPELL_SHAMAN_ANCESTRAL_GUIDANCE             = 108281,
    SPELL_SHAMAN_ANCESTRAL_GUIDANCE_HEAL        = 114911,
    SPELL_SHAMAN_CHAINED_HEAL                   = 70809,
    SPELL_SHAMAN_CRASH_LIGHTNING_CLEAVE         = 187878,
    SPELL_SHAMAN_EARTH_SHIELD_HEAL              = 204290,
    SPELL_SHAMAN_EARTHEN_RAGE_PASSIVE           = 170374,
    SPELL_SHAMAN_EARTHEN_RAGE_PERIODIC          = 170377,
    SPELL_SHAMAN_EARTHEN_RAGE_DAMAGE            = 170379,
    SPELL_SHAMAN_ELECTRIFIED                    = 64930,
    SPELL_SHAMAN_ELEMENTAL_BLAST_CRIT           = 118522,
    SPELL_SHAMAN_ELEMENTAL_BLAST_HASTE          = 173183,
    SPELL_SHAMAN_ELEMENTAL_BLAST_MASTERY        = 173184,
    SPELL_SHAMAN_ELEMENTAL_MASTERY              = 16166,
    SPELL_SHAMAN_ENERGY_SURGE                   = 40465,
    SPELL_SHAMAN_EXHAUSTION                     = 57723,
    SPELL_SHAMAN_FLAME_SHOCK                    = 8050,
    SPELL_SHAMAN_FLAME_SHOCK_MAELSTROM          = 188389,
    SPELL_SHAMAN_FLAMETONGUE_ATTACK             = 10444,
    SPELL_SHAMAN_GATHERING_STORMS               = 198299,
    SPELL_SHAMAN_GATHERING_STORMS_BUFF          = 198300,
    SPELL_SHAMAN_ITEM_LIGHTNING_SHIELD          = 23552,
    SPELL_SHAMAN_ITEM_LIGHTNING_SHIELD_DAMAGE   = 27635,
    SPELL_SHAMAN_ITEM_MANA_SURGE                = 23571,
    SPELL_SHAMAN_LAVA_BURST                     = 51505,
    SPELL_SHAMAN_LAVA_BURST_BONUS_DAMAGE        = 71824,
    SPELL_SHAMAN_LAVA_SURGE                     = 77762,
    SPELL_SHAMAN_PATH_OF_FLAMES_SPREAD          = 210621,
    SPELL_SHAMAN_PATH_OF_FLAMES_TALENT          = 201909,
    SPELL_SHAMAN_POWER_SURGE                    = 40466,
    SPELL_SHAMAN_SATED                          = 57724,
    SPELL_SHAMAN_TIDAL_WAVES                    = 53390,
    SPELL_SHAMAN_TOTEMIC_POWER_MP5              = 28824,
    SPELL_SHAMAN_TOTEMIC_POWER_SPELL_POWER      = 28825,
    SPELL_SHAMAN_TOTEMIC_POWER_ATTACK_POWER     = 28826,
    SPELL_SHAMAN_TOTEMIC_POWER_ARMOR            = 28827,
    SPELL_SHAMAN_WINDFURY_ATTACK                = 25504
};

enum MiscSpells
{
    SPELL_HUNTER_INSANITY                       = 95809,
    SPELL_MAGE_TEMPORAL_DISPLACEMENT            = 80354,
    SPELL_PET_NETHERWINDS_FATIGUED              = 160455
};

// 108281 - Ancestral Guidance
class spell_sha_ancestral_guidance : public SpellScriptLoader
{
public:
    spell_sha_ancestral_guidance() : SpellScriptLoader("spell_sha_ancestral_guidance") { }

    class spell_sha_ancestral_guidance_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_sha_ancestral_guidance_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_SHAMAN_ANCESTRAL_GUIDANCE_HEAL });
        }

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            if (eventInfo.GetHealInfo()->GetSpellInfo()->Id == SPELL_SHAMAN_ANCESTRAL_GUIDANCE_HEAL)
                return false;
            return true;
        }

        void HandleEffectProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
        {
            PreventDefaultAction();
            int32 bp0 = CalculatePct(int32(eventInfo.GetDamageInfo()->GetDamage()), aurEff->GetAmount());
            if (bp0)
                eventInfo.GetActor()->CastCustomSpell(SPELL_SHAMAN_ANCESTRAL_GUIDANCE_HEAL, SPELLVALUE_BASE_POINT0, bp0, eventInfo.GetActor(), true, nullptr, aurEff);
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_sha_ancestral_guidance_AuraScript::CheckProc);
            OnEffectProc += AuraEffectProcFn(spell_sha_ancestral_guidance_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_sha_ancestral_guidance_AuraScript();
    }
};

// 114911 - Ancestral Guidance Heal
class spell_sha_ancestral_guidance_heal : public SpellScriptLoader
{
public:
    spell_sha_ancestral_guidance_heal() : SpellScriptLoader("spell_sha_ancestral_guidance_heal") { }

    class spell_sha_ancestral_guidance_heal_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_sha_ancestral_guidance_heal_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_SHAMAN_ANCESTRAL_GUIDANCE });
        }

        void ResizeTargets(std::list<WorldObject*>& targets)
        {
            Trinity::Containers::RandomResize(targets, 3);
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_ancestral_guidance_heal_SpellScript::ResizeTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_sha_ancestral_guidance_heal_SpellScript();
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
                return ValidateSpellInfo(
                {
                    SPELL_SHAMAN_SATED,
                    SPELL_HUNTER_INSANITY,
                    SPELL_MAGE_TEMPORAL_DISPLACEMENT,
                    SPELL_PET_NETHERWINDS_FATIGUED
                });
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

// 187874 - Crash Lightning
class spell_sha_crash_lightning : public SpellScriptLoader
{
public:
    spell_sha_crash_lightning() : SpellScriptLoader("spell_sha_crash_lightning") { }

    class spell_sha_crash_lightning_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_sha_crash_lightning_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_SHAMAN_CRASH_LIGHTNING_CLEAVE });
        }

        void CountTargets(std::list<WorldObject*>& targets)
        {
            _targetsHit = targets.size();
        }

        void TriggerCleaveBuff()
        {
            if (_targetsHit >= 2)
                GetCaster()->CastSpell(GetCaster(), SPELL_SHAMAN_CRASH_LIGHTNING_CLEAVE, true);
            if (AuraEffect const* gatheringStorms = GetCaster()->GetAuraEffect(SPELL_SHAMAN_GATHERING_STORMS, EFFECT_0))
                GetCaster()->CastCustomSpell(SPELL_SHAMAN_GATHERING_STORMS_BUFF, SPELLVALUE_BASE_POINT0, int32(gatheringStorms->GetAmount() * _targetsHit), GetCaster(), true);
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_crash_lightning_SpellScript::CountTargets, EFFECT_0, TARGET_UNIT_CONE_ENEMY_104);
            AfterCast += SpellCastFn(spell_sha_crash_lightning_SpellScript::TriggerCleaveBuff);
        }

        size_t _targetsHit = 0;
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_sha_crash_lightning_SpellScript();
    }
};

// 204288 - Earth Shield
class spell_sha_earth_shield : public SpellScriptLoader
{
    public:
        spell_sha_earth_shield() : SpellScriptLoader("spell_sha_earth_shield") { }

        class spell_sha_earth_shield_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_earth_shield_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_SHAMAN_EARTH_SHIELD_HEAL });
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                if (!eventInfo.GetDamageInfo() || !HasEffect(EFFECT_1) || eventInfo.GetDamageInfo()->GetDamage() < GetTarget()->CountPctFromMaxHealth(GetEffect(EFFECT_1)->GetAmount()))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();

                GetTarget()->CastSpell(GetTarget(), SPELL_SHAMAN_EARTH_SHIELD_HEAL, true, nullptr, aurEff, GetCasterGUID());
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_sha_earth_shield_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_sha_earth_shield_AuraScript::HandleProc, EFFECT_1, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_earth_shield_AuraScript();
        }
};

// 170374 - Earthen Rage (Passive)
class spell_sha_earthen_rage_passive : public SpellScriptLoader
{
public:
    static char constexpr const ScriptName[] = "spell_sha_earthen_rage_passive";

    spell_sha_earthen_rage_passive() : SpellScriptLoader(ScriptName) { }

    class spell_sha_earthen_rage_passive_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_sha_earthen_rage_passive_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_SHAMAN_EARTHEN_RAGE_PERIODIC, SPELL_SHAMAN_EARTHEN_RAGE_DAMAGE });
        }

        void HandleEffectProc(AuraEffect* /*aurEff*/, ProcEventInfo& eventInfo)
        {
            PreventDefaultAction();
            _procTargetGuid = eventInfo.GetProcTarget()->GetGUID();
            eventInfo.GetActor()->CastSpell(eventInfo.GetActor(), SPELL_SHAMAN_EARTHEN_RAGE_PERIODIC, true);
        }

        void Register() override
        {
            OnEffectProc += AuraEffectProcFn(spell_sha_earthen_rage_passive_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
        }

        ObjectGuid _procTargetGuid;

    public:
        ObjectGuid const& GetProcTargetGuid() const
        {
            return _procTargetGuid;
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_sha_earthen_rage_passive_AuraScript();
    }
};
char constexpr const spell_sha_earthen_rage_passive::ScriptName[];

// 170377 - Earthen Rage (Proc Aura)
class spell_sha_earthen_rage_proc_aura : public SpellScriptLoader
{
public:
    spell_sha_earthen_rage_proc_aura() : SpellScriptLoader("spell_sha_earthen_rage_proc_aura") { }

    class spell_sha_earthen_rage_proc_aura_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_sha_earthen_rage_proc_aura_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_SHAMAN_EARTHEN_RAGE_PASSIVE, SPELL_SHAMAN_EARTHEN_RAGE_DAMAGE });
        }

        void HandleEffectPeriodic(AuraEffect const* /*aurEff*/)
        {
            using earthen_rage_script_t = spell_sha_earthen_rage_passive::spell_sha_earthen_rage_passive_AuraScript;

            PreventDefaultAction();
            if (Aura const* aura = GetCaster()->GetAura(SPELL_SHAMAN_EARTHEN_RAGE_PASSIVE))
                if (earthen_rage_script_t const* earthen_rage_script = aura->GetScript<earthen_rage_script_t>(spell_sha_earthen_rage_passive::ScriptName))
                    if (Unit* procTarget = ObjectAccessor::GetUnit(*GetCaster(), earthen_rage_script->GetProcTargetGuid()))
                        GetTarget()->CastSpell(procTarget, SPELL_SHAMAN_EARTHEN_RAGE_DAMAGE, true);
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_sha_earthen_rage_proc_aura_AuraScript::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_sha_earthen_rage_proc_aura_AuraScript();
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
            return ValidateSpellInfo(
            {
                SPELL_SHAMAN_ELEMENTAL_BLAST_CRIT,
                SPELL_SHAMAN_ELEMENTAL_BLAST_HASTE,
                SPELL_SHAMAN_ELEMENTAL_BLAST_MASTERY
            });
        }

        bool Load() override
        {
            return GetCaster()->GetTypeId() == TYPEID_PLAYER;
        }

        void TriggerBuff()
        {
            Player* caster = GetCaster()->ToPlayer();
            uint32 spellId = RAND(SPELL_SHAMAN_ELEMENTAL_BLAST_CRIT, SPELL_SHAMAN_ELEMENTAL_BLAST_HASTE, SPELL_SHAMAN_ELEMENTAL_BLAST_MASTERY);

            caster->CastSpell(caster, spellId, TRIGGERED_FULL_MASK);
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

// 194084 - Flametongue
class spell_sha_flametongue : public SpellScriptLoader
{
public:
    spell_sha_flametongue() : SpellScriptLoader("spell_sha_flametongue") { }

    class spell_sha_flametongue_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_sha_flametongue_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_SHAMAN_FLAMETONGUE_ATTACK });
        }

        void HandleEffectProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
        {
            PreventDefaultAction();

            Unit* attacker = eventInfo.GetActor();
            int32 damage = int32(attacker->GetTotalAttackPowerValue(BASE_ATTACK) * 0.125f / 2600 * attacker->GetBaseAttackTime(BASE_ATTACK));
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

// 52042 - Healing Stream Totem
class spell_sha_healing_stream_totem_heal : public SpellScriptLoader
{
    public:
        spell_sha_healing_stream_totem_heal() : SpellScriptLoader("spell_sha_healing_stream_totem_heal") { }

        class spell_sha_healing_stream_totem_heal_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_healing_stream_totem_heal_SpellScript);

            void SelectTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if([](WorldObject* target)
                {
                    return !target->ToUnit() || target->ToUnit()->IsFullHealth();
                });

                Trinity::Containers::RandomResize(targets, 1);

                if (targets.empty())
                    targets.push_back(GetOriginalCaster());
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_healing_stream_totem_heal_SpellScript::SelectTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
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
                return ValidateSpellInfo(
                {
                    SPELL_SHAMAN_EXHAUSTION,
                    SPELL_HUNTER_INSANITY,
                    SPELL_MAGE_TEMPORAL_DISPLACEMENT,
                    SPELL_PET_NETHERWINDS_FATIGUED
                });
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
                return ValidateSpellInfo({ SPELL_SHAMAN_ITEM_LIGHTNING_SHIELD });
            }

            void HandleProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                GetTarget()->CastSpell(eventInfo.GetProcTarget(), SPELL_SHAMAN_ITEM_LIGHTNING_SHIELD, true, nullptr, aurEff);
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
                return ValidateSpellInfo({ SPELL_SHAMAN_ITEM_LIGHTNING_SHIELD_DAMAGE });
            }

            void HandleProc(AuraEffect* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                GetTarget()->CastSpell(GetTarget(), SPELL_SHAMAN_ITEM_LIGHTNING_SHIELD_DAMAGE, true, nullptr, aurEff);
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
                return ValidateSpellInfo({ SPELL_SHAMAN_ITEM_MANA_SURGE });
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                return eventInfo.GetProcSpell() != nullptr;
            }

            void HandleProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                std::vector<SpellPowerCost> const& costs = eventInfo.GetProcSpell()->GetPowerCost();
                auto m = std::find_if(costs.begin(), costs.end(), [](SpellPowerCost const& cost) { return cost.Power == POWER_MANA; });
                if (m != costs.end())
                {
                    int32 mana = CalculatePct(m->Amount, 35);
                    if (mana > 0)
                        GetTarget()->CastCustomSpell(SPELL_SHAMAN_ITEM_MANA_SURGE, SPELLVALUE_BASE_POINT0, mana, GetTarget(), true, nullptr, aurEff);
                }
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
                return ValidateSpellInfo(
                {
                    SPELL_SHAMAN_ENERGY_SURGE,
                    SPELL_SHAMAN_POWER_SURGE
                });
            }

            void HandleProc(AuraEffect* /*aurEff*/, ProcEventInfo& eventInfo)
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
                    eventInfo.GetActor()->CastSpell(nullptr, spellId, true);
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
                return ValidateSpellInfo({ SPELL_SHAMAN_ELEMENTAL_MASTERY });
            }

            void HandleEffectProc(AuraEffect* aurEff, ProcEventInfo& /*eventInfo*/)
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

// 51505 - Lava burst
class spell_sha_lava_burst : public SpellScriptLoader
{
public:
    spell_sha_lava_burst() : SpellScriptLoader("spell_sha_lava_burst") { }

    class spell_sha_lava_burst_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_sha_lava_burst_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_SHAMAN_PATH_OF_FLAMES_TALENT, SPELL_SHAMAN_PATH_OF_FLAMES_SPREAD });
        }

        void HandleScript(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
                if (Unit* target = GetExplTargetUnit())
                    if (caster->HasAura(SPELL_SHAMAN_PATH_OF_FLAMES_TALENT))
                        caster->CastSpell(target, SPELL_SHAMAN_PATH_OF_FLAMES_SPREAD, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_sha_lava_burst_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_sha_lava_burst_SpellScript();
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
                return ValidateSpellInfo({ SPELL_SHAMAN_LAVA_SURGE });
            }

            void HandleEffectProc(AuraEffect* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
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
                return ValidateSpellInfo({ SPELL_SHAMAN_LAVA_BURST });
            }

            bool Load() override
            {
                return GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            void ResetCooldown()
            {
                GetCaster()->GetSpellHistory()->RestoreCharge(sSpellMgr->AssertSpellInfo(SPELL_SHAMAN_LAVA_BURST, GetCastDifficulty())->ChargeCategoryId);
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

// 210621 - Path of Flames Spread
class spell_sha_path_of_flames_spread : public SpellScriptLoader
{
public:
    spell_sha_path_of_flames_spread() : SpellScriptLoader("spell_sha_path_of_flames_spread") { }

    class spell_sha_path_of_flames_spread_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_sha_path_of_flames_spread_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_SHAMAN_FLAME_SHOCK_MAELSTROM });
        }

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            targets.remove(GetExplTargetUnit());
            Trinity::Containers::RandomResize(targets, [this](WorldObject* target)
            {
                return target->GetTypeId() == TYPEID_UNIT && !target->ToUnit()->HasAura(SPELL_SHAMAN_FLAME_SHOCK_MAELSTROM, GetCaster()->GetGUID());
            }, 1);
        }

        void HandleScript(SpellEffIndex /*effIndex*/)
        {
            if (Unit* mainTarget = GetExplTargetUnit())
            {
                if (Aura* flameShock = mainTarget->GetAura(SPELL_SHAMAN_FLAME_SHOCK_MAELSTROM, GetCaster()->GetGUID()))
                {
                    if (Aura* newAura = GetCaster()->AddAura(SPELL_SHAMAN_FLAME_SHOCK_MAELSTROM, GetHitUnit()))
                    {
                        newAura->SetDuration(flameShock->GetDuration());
                        newAura->SetMaxDuration(flameShock->GetDuration());
                    }
                }
            }
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_path_of_flames_spread_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ENEMY);
            OnEffectHitTarget += SpellEffectFn(spell_sha_path_of_flames_spread_SpellScript::HandleScript, EFFECT_1, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_sha_path_of_flames_spread_SpellScript();
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
                return ValidateSpellInfo({ SPELL_SHAMAN_TIDAL_WAVES });
            }

            void HandleEffectProc(AuraEffect* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                int32 basePoints0 = -aurEff->GetAmount();
                int32 basePoints1 = aurEff->GetAmount();

                GetTarget()->CastCustomSpell(GetTarget(), SPELL_SHAMAN_TIDAL_WAVES, &basePoints0, &basePoints1, nullptr, true, nullptr, aurEff);
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
                return ValidateSpellInfo(
                {
                    SPELL_SHAMAN_TOTEMIC_POWER_ARMOR,
                    SPELL_SHAMAN_TOTEMIC_POWER_ATTACK_POWER,
                    SPELL_SHAMAN_TOTEMIC_POWER_SPELL_POWER,
                    SPELL_SHAMAN_TOTEMIC_POWER_MP5
                });
            }

            void HandleProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
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

                caster->CastSpell(target, spellId, true, nullptr, aurEff);
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

// 28820 - Lightning Shield
class spell_sha_t3_8p_bonus : public AuraScript
{
    PrepareAuraScript(spell_sha_t3_8p_bonus);

    void PeriodicTick(AuraEffect const* /*aurEff*/)
    {
        PreventDefaultAction();

        // Need remove self if Lightning Shield not active
        if (!GetTarget()->GetAuraEffect(SPELL_AURA_PROC_TRIGGER_SPELL, SPELLFAMILY_SHAMAN, flag128(0x400), GetCaster()->GetGUID()))
            Remove();
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_sha_t3_8p_bonus::PeriodicTick, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
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
                return ValidateSpellInfo({ SPELL_SHAMAN_ELECTRIFIED });
            }

            void HandleProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                DamageInfo* damageInfo = eventInfo.GetDamageInfo();
                if (!damageInfo || !damageInfo->GetDamage())
                    return;

                SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(SPELL_SHAMAN_ELECTRIFIED, GetCastDifficulty());
                int32 amount = CalculatePct(static_cast<int32>(damageInfo->GetDamage()), aurEff->GetAmount());

                ASSERT(spellInfo->GetMaxTicks() > 0);
                amount /= spellInfo->GetMaxTicks();

                // Add remaining ticks to damage done
                Unit* caster = eventInfo.GetActor();
                Unit* target = eventInfo.GetProcTarget();
                amount += target->GetRemainingPeriodicAmount(caster->GetGUID(), SPELL_SHAMAN_ELECTRIFIED, SPELL_AURA_PERIODIC_DAMAGE);

                caster->CastCustomSpell(SPELL_SHAMAN_ELECTRIFIED, SPELLVALUE_BASE_POINT0, amount, target, true, nullptr, aurEff);
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
                return ValidateSpellInfo({ SPELL_SHAMAN_LAVA_BURST_BONUS_DAMAGE });
            }

            void HandleProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                DamageInfo* damageInfo = eventInfo.GetDamageInfo();
                if (!damageInfo || !damageInfo->GetDamage())
                    return;

                SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(SPELL_SHAMAN_LAVA_BURST_BONUS_DAMAGE, GetCastDifficulty());
                int32 amount = CalculatePct(static_cast<int32>(damageInfo->GetDamage()), aurEff->GetAmount());

                ASSERT(spellInfo->GetMaxTicks() > 0);
                amount /= spellInfo->GetMaxTicks();

                // Add remaining ticks to damage done
                Unit* caster = eventInfo.GetActor();
                Unit* target = eventInfo.GetProcTarget();
                amount += target->GetRemainingPeriodicAmount(caster->GetGUID(), SPELL_SHAMAN_LAVA_BURST_BONUS_DAMAGE, SPELL_AURA_PERIODIC_DAMAGE);

                caster->CastCustomSpell(SPELL_SHAMAN_LAVA_BURST_BONUS_DAMAGE, SPELLVALUE_BASE_POINT0, amount, target, true, nullptr, aurEff);
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

            void HandleProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                Unit* caster = eventInfo.GetActor();
                Unit* target = eventInfo.GetProcTarget();

                // try to find spell Flame Shock on the target
                AuraEffect* flameShock = target->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_SHAMAN, flag128(0x10000000), caster->GetGUID());
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
                return ValidateSpellInfo({ SPELL_SHAMAN_CHAINED_HEAL });
            }

            void HandleProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                HealInfo* healInfo = eventInfo.GetHealInfo();
                if (!healInfo || !healInfo->GetHeal())
                    return;

                SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(SPELL_SHAMAN_CHAINED_HEAL, GetCastDifficulty());
                int32 amount = CalculatePct(static_cast<int32>(healInfo->GetHeal()), aurEff->GetAmount());

                ASSERT(spellInfo->GetMaxTicks() > 0);
                amount /= spellInfo->GetMaxTicks();

                // Add remaining ticks to healing done
                Unit* caster = eventInfo.GetActor();
                Unit* target = eventInfo.GetProcTarget();
                amount += target->GetRemainingPeriodicAmount(caster->GetGUID(), SPELL_SHAMAN_CHAINED_HEAL, SPELL_AURA_PERIODIC_HEAL);

                caster->CastCustomSpell(SPELL_SHAMAN_CHAINED_HEAL, SPELLVALUE_BASE_POINT0, amount, target, true, nullptr, aurEff);
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
            return ValidateSpellInfo({ SPELL_SHAMAN_WINDFURY_ATTACK });
        }

        void HandleEffectProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
        {
            PreventDefaultAction();

            for (uint32 i = 0; i < 2; ++i)
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
    new spell_sha_ancestral_guidance();
    new spell_sha_ancestral_guidance_heal();
    new spell_sha_bloodlust();
    new spell_sha_crash_lightning();
    new spell_sha_earth_shield();
    new spell_sha_earthen_rage_passive();
    new spell_sha_earthen_rage_proc_aura();
    new spell_sha_elemental_blast();
    new spell_sha_flametongue();
    new spell_sha_healing_stream_totem_heal();
    new spell_sha_heroism();
    new spell_sha_item_lightning_shield();
    new spell_sha_item_lightning_shield_trigger();
    new spell_sha_item_mana_surge();
    new spell_sha_item_t6_trinket();
    new spell_sha_item_t10_elemental_2p_bonus();
    new spell_sha_item_t18_elemental_4p_bonus();
    new spell_sha_lava_burst();
    new spell_sha_lava_surge();
    new spell_sha_lava_surge_proc();
    new spell_sha_path_of_flames_spread();
    new spell_sha_tidal_waves();
    new spell_sha_t3_6p_bonus();
    RegisterAuraScript(spell_sha_t3_8p_bonus);
    new spell_sha_t8_elemental_4p_bonus();
    new spell_sha_t9_elemental_4p_bonus();
    new spell_sha_t10_elemental_4p_bonus();
    new spell_sha_t10_restoration_4p_bonus();
    new spell_sha_windfury();
}
