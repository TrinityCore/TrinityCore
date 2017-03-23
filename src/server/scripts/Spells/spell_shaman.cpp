/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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
    SPELL_SHAMAN_ANCESTRAL_GUIDANCE             = 108281,
    SPELL_SHAMAN_ANCESTRAL_GUIDANCE_HEAL        = 114911,
    SPELL_SHAMAN_CRASH_LIGHTNING_CLEAVE         = 187878,
    SPELL_SHAMAN_EARTH_SHIELD_HEAL              = 204290,
    SPELL_SHAMAN_EARTHEN_RAGE_PASSIVE           = 170374,
    SPELL_SHAMAN_EARTHEN_RAGE_PERIODIC          = 170377,
    SPELL_SHAMAN_EARTHEN_RAGE_DAMAGE            = 170379,
    SPELL_SHAMAN_ELEMENTAL_BLAST_CRIT           = 118522,
    SPELL_SHAMAN_ELEMENTAL_BLAST_HASTE          = 173183,
    SPELL_SHAMAN_ELEMENTAL_BLAST_MASTERY        = 173184,
    SPELL_SHAMAN_ELEMENTAL_MASTERY              = 16166,
    SPELL_SHAMAN_EXHAUSTION                     = 57723,
    SPELL_SHAMAN_FIRE_NOVA_TRIGGERED            = 8349,
    SPELL_SHAMAN_FLAME_SHOCK                    = 8050,
    SPELL_SHAMAN_FLAME_SHOCK_MAELSTROM          = 188389,
    SPELL_SHAMAN_FLAMETONGUE_ATTACK             = 10444,
    SPELL_SHAMAN_GATHERING_STORMS               = 198299,
    SPELL_SHAMAN_GATHERING_STORMS_BUFF          = 198300,
    SPELL_SHAMAN_HIGH_TIDE                      = 157154,
    SPELL_SHAMAN_ITEM_LIGHTNING_SHIELD          = 23552,
    SPELL_SHAMAN_ITEM_LIGHTNING_SHIELD_DAMAGE   = 27635,
    SPELL_SHAMAN_ITEM_MANA_SURGE                = 23571,
    SPELL_SHAMAN_LAVA_BURST                     = 51505,
    SPELL_SHAMAN_LAVA_LASH_SPREAD_FLAME_SHOCK   = 105792,
    SPELL_SHAMAN_LAVA_SURGE                     = 77762,
    SPELL_SHAMAN_PATH_OF_FLAMES_SPREAD          = 210621,
    SPELL_SHAMAN_PATH_OF_FLAMES_TALENT          = 201909,
    SPELL_SHAMAN_SATED                          = 57724,
    SPELL_SHAMAN_TIDAL_WAVES                    = 53390,
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
            if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_ANCESTRAL_GUIDANCE_HEAL))
                return false;
            return true;
        }

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            if (eventInfo.GetHealInfo()->GetSpellInfo()->Id == SPELL_SHAMAN_ANCESTRAL_GUIDANCE_HEAL)
                return false;
            return true;
        }

        void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
        {
            PreventDefaultAction();
            int32 bp0 = CalculatePct(int32(eventInfo.GetDamageInfo()->GetDamage()), aurEff->GetAmount());
            if (bp0)
                eventInfo.GetActor()->CastCustomSpell(SPELL_SHAMAN_ANCESTRAL_GUIDANCE_HEAL, SPELLVALUE_BASE_POINT0, bp0, eventInfo.GetActor(), true, NULL, aurEff);
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
            if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_ANCESTRAL_GUIDANCE))
                return false;
            return true;
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
            if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_CRASH_LIGHTNING_CLEAVE))
                return false;
            return true;
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
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_EARTH_SHIELD_HEAL))
                    return false;
                return true;
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                if (!eventInfo.GetDamageInfo() || !HasEffect(EFFECT_1) || eventInfo.GetDamageInfo()->GetDamage() < GetTarget()->CountPctFromMaxHealth(GetEffect(EFFECT_1)->GetAmount()))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
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
    spell_sha_earthen_rage_passive() : SpellScriptLoader("spell_sha_earthen_rage_passive") { }

    class spell_sha_earthen_rage_passive_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_sha_earthen_rage_passive_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_EARTHEN_RAGE_PERIODIC))
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_EARTHEN_RAGE_DAMAGE))
                return false;
            return true;
        }

        void HandleEffectProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
        {
            PreventDefaultAction();
            GetAura()->SetCastExtraParam("procTargetGUID", eventInfo.GetProcTarget()->GetGUID());
            eventInfo.GetActor()->CastSpell(eventInfo.GetActor(), SPELL_SHAMAN_EARTHEN_RAGE_PERIODIC, true);
        }

        void Register() override
        {
            OnEffectProc += AuraEffectProcFn(spell_sha_earthen_rage_passive_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_sha_earthen_rage_passive_AuraScript();
    }
};

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
            if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_EARTHEN_RAGE_PASSIVE))
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_EARTHEN_RAGE_DAMAGE))
                return false;
            return true;
        }

        void HandleEffectPeriodic(AuraEffect const* /*aurEff*/)
        {
            PreventDefaultAction();
            if (Aura const* aura = GetCaster()->GetAura(SPELL_SHAMAN_EARTHEN_RAGE_PASSIVE))
                if (ObjectGuid const* procTargetGUID = aura->GetCastExtraParam<ObjectGuid>("procTargetGUID"))
                    if (Unit* procTarget = ObjectAccessor::GetUnit(*GetCaster(), *procTargetGUID))
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
            if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_ELEMENTAL_BLAST_CRIT))
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_ELEMENTAL_BLAST_HASTE))
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_ELEMENTAL_BLAST_MASTERY))
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
            if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_FLAMETONGUE_ATTACK))
                return false;
            return true;
        }

        void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
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
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_ITEM_MANA_SURGE))
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
            if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_PATH_OF_FLAMES_TALENT))
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_PATH_OF_FLAMES_SPREAD))
                return false;
            return true;
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
                GetCaster()->GetSpellHistory()->RestoreCharge(sSpellMgr->AssertSpellInfo(SPELL_SHAMAN_LAVA_BURST)->ChargeCategoryId);
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
            if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_FLAME_SHOCK_MAELSTROM))
                return false;
            return true;
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
    new spell_sha_fire_nova();
    new spell_sha_flametongue();
    new spell_sha_healing_stream_totem_heal();
    new spell_sha_heroism();
    new spell_sha_item_lightning_shield();
    new spell_sha_item_lightning_shield_trigger();
    new spell_sha_item_mana_surge();
    new spell_sha_item_t10_elemental_2p_bonus();
    new spell_sha_item_t18_elemental_4p_bonus();
    new spell_sha_lava_burst();
    new spell_sha_lava_surge();
    new spell_sha_lava_surge_proc();
    new spell_sha_path_of_flames_spread();
    new spell_sha_tidal_waves();
    new spell_sha_windfury();
}
