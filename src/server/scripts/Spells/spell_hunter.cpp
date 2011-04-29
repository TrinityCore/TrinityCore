/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
 * Scripts for spells with SPELLFAMILY_HUNTER, SPELLFAMILY_PET and SPELLFAMILY_GENERIC spells used by hunter players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_hun_".
 */

#include "ScriptPCH.h"
#include "SpellAuraEffects.h"

enum HunterSpells
{
    HUNTER_SPELL_READINESS                       = 23989,
    HUNTER_SPELL_BESTIAL_WRATH                   = 19574,
    HUNTER_PET_SPELL_LAST_STAND_TRIGGERED        = 53479,
    HUNTER_PET_HEART_OF_THE_PHOENIX              = 55709,
    HUNTER_PET_HEART_OF_THE_PHOENIX_TRIGGERED    = 54114,
    HUNTER_PET_HEART_OF_THE_PHOENIX_DEBUFF       = 55711,
    HUNTER_PET_SPELL_CARRION_FEEDER_TRIGGERED    = 54045,
    HUNTER_SPELL_INVIGORATION_TRIGGERED          = 53398,
    HUNTER_SPELL_MASTERS_CALL_TRIGGERED          = 62305,
    HUNTER_SPELL_CHIMERA_SHOT_SERPENT            = 53353,
    HUNTER_SPELL_CHIMERA_SHOT_VIPER              = 53358,
    HUNTER_SPELL_CHIMERA_SHOT_SCORPID            = 53359,
};

// 53209 Chimera Shot
class spell_hun_chimera_shot : public SpellScriptLoader
{
public:
    spell_hun_chimera_shot() : SpellScriptLoader("spell_hun_chimera_shot") { }

    class spell_hun_chimera_shot_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_hun_chimera_shot_SpellScript)
        bool Validate(SpellEntry const * /*spellEntry*/)
        {
            if (!sSpellStore.LookupEntry(HUNTER_SPELL_CHIMERA_SHOT_SERPENT))
                return false;
            if (!sSpellStore.LookupEntry(HUNTER_SPELL_CHIMERA_SHOT_VIPER))
                return false;
            if (!sSpellStore.LookupEntry(HUNTER_SPELL_CHIMERA_SHOT_SCORPID))
                return false;
            return true;
        }

        void HandleScriptEffect(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* unitTarget = GetHitUnit();
            if (!unitTarget)
                return;

            uint32 spellId = 0;
            int32 basePoint = 0;
            Unit::AuraApplicationMap& Auras = unitTarget->GetAppliedAuras();
            for (Unit::AuraApplicationMap::iterator i = Auras.begin(); i != Auras.end(); ++i)
            {
                Aura* aura = i->second->GetBase();
                if (aura->GetCasterGUID() != caster->GetGUID())
                    continue;

                // Search only Serpent Sting, Viper Sting, Scorpid Sting auras
                flag96 familyFlag = aura->GetSpellProto()->SpellFamilyFlags;
                if (!(familyFlag[1] & 0x00000080 || familyFlag[0] & 0x0000C000))
                    continue;
                if (AuraEffect const * aurEff = aura->GetEffect(0))
                {
                    // Serpent Sting - Instantly deals 40% of the damage done by your Serpent Sting.
                    if (familyFlag[0] & 0x4000)
                    {
                        int32 TickCount = aurEff->GetTotalTicks();
                        spellId = HUNTER_SPELL_CHIMERA_SHOT_SERPENT;
                        basePoint = caster->SpellDamageBonus(unitTarget, aura->GetSpellProto(), aurEff->GetAmount(), DOT, aura->GetStackAmount());
                        ApplyPctN(basePoint, TickCount * 40);
                    }
                    // Viper Sting - Instantly restores mana to you equal to 60% of the total amount drained by your Viper Sting.
                    else if (familyFlag[1] & 0x00000080)
                    {
                        int32 TickCount = aura->GetEffect(0)->GetTotalTicks();
                        spellId = HUNTER_SPELL_CHIMERA_SHOT_VIPER;

                        // Amount of one aura tick
                        basePoint = int32(CalculatePctN(unitTarget->GetMaxPower(POWER_MANA), aurEff->GetAmount()));
                        int32 casterBasePoint = aurEff->GetAmount() * unitTarget->GetMaxPower(POWER_MANA) / 50; // TODO: WTF? caster uses unitTarget?
                        if (basePoint > casterBasePoint)
                            basePoint = casterBasePoint;
                        ApplyPctN(basePoint, TickCount * 60);
                    }
                    // Scorpid Sting - Attempts to Disarm the target for 10 sec. This effect cannot occur more than once per 1 minute.
                    else if (familyFlag[0] & 0x00008000)
                        spellId = HUNTER_SPELL_CHIMERA_SHOT_SCORPID;
                    // ?? nothing say in spell desc (possibly need addition check)
                    //if (familyFlag & 0x0000010000000000LL || // dot
                    //    familyFlag & 0x0000100000000000LL)   // stun
                    //{
                    //    spellId = 53366; // 53366 Chimera Shot - Wyvern
                    //}

                    // Refresh aura duration
                    aura->RefreshDuration();
                }
                break;
            }
            if (spellId)
                caster->CastCustomSpell(unitTarget, spellId, &basePoint, 0, 0, true);
            if (spellId == HUNTER_SPELL_CHIMERA_SHOT_SCORPID && caster->ToPlayer()) // Scorpid Sting - Add 1 minute cooldown
                caster->ToPlayer()->AddSpellCooldown(spellId, 0, uint32(time(NULL) + 60));
        }

        void Register()
        {
            OnEffect += SpellEffectFn(spell_hun_chimera_shot_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_hun_chimera_shot_SpellScript();
    }
};

// 53412 Invigoration
class spell_hun_invigoration : public SpellScriptLoader
{
public:
    spell_hun_invigoration() : SpellScriptLoader("spell_hun_invigoration") { }

    class spell_hun_invigoration_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_hun_invigoration_SpellScript)
        bool Validate(SpellEntry const * /*spellEntry*/)
        {
            if (!sSpellStore.LookupEntry(HUNTER_SPELL_INVIGORATION_TRIGGERED))
                return false;
            return true;
        }

        void HandleScriptEffect(SpellEffIndex /*effIndex*/)
        {
            if (Unit* unitTarget = GetHitUnit())
                if (AuraEffect* aurEff = unitTarget->GetDummyAuraEffect(SPELLFAMILY_HUNTER, 3487, 0))
                    if (roll_chance_i(aurEff->GetAmount()))
                        unitTarget->CastSpell(unitTarget, HUNTER_SPELL_INVIGORATION_TRIGGERED, true);
        }

        void Register()
        {
            OnEffect += SpellEffectFn(spell_hun_invigoration_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_hun_invigoration_SpellScript();
    }
};

class spell_hun_last_stand_pet : public SpellScriptLoader
{
public:
    spell_hun_last_stand_pet() : SpellScriptLoader("spell_hun_last_stand_pet") { }

    class spell_hun_last_stand_pet_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_hun_last_stand_pet_SpellScript)
        bool Validate(SpellEntry const * /*spellEntry*/)
        {
            if (!sSpellStore.LookupEntry(HUNTER_PET_SPELL_LAST_STAND_TRIGGERED))
                return false;
            return true;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            Unit *caster = GetCaster();
            int32 healthModSpellBasePoints0 = int32(caster->CountPctFromMaxHealth(30));
            caster->CastCustomSpell(caster, HUNTER_PET_SPELL_LAST_STAND_TRIGGERED, &healthModSpellBasePoints0, NULL, NULL, true, NULL);
        }

        void Register()
        {
            // add dummy effect spell handler to pet's Last Stand
            OnEffect += SpellEffectFn(spell_hun_last_stand_pet_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_hun_last_stand_pet_SpellScript();
    }
};

class spell_hun_masters_call : public SpellScriptLoader
{
public:
    spell_hun_masters_call() : SpellScriptLoader("spell_hun_masters_call") { }

    class spell_hun_masters_call_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_hun_masters_call_SpellScript)
        bool Validate(SpellEntry const * spellEntry)
        {
            if (!sSpellStore.LookupEntry(HUNTER_SPELL_MASTERS_CALL_TRIGGERED))
                return false;
            if (!sSpellStore.LookupEntry(SpellMgr::CalculateSpellEffectAmount(spellEntry, EFFECT_0)))
                return false;
            if (!sSpellStore.LookupEntry(SpellMgr::CalculateSpellEffectAmount(spellEntry, EFFECT_1)))
                return false;
            return true;
        }

        void HandleScriptEffect(SpellEffIndex /*effIndex*/)
        {
            if (Unit * target = GetHitUnit())
            {
                target->CastSpell(target, GetEffectValue(), true);
                target->CastSpell(target, HUNTER_SPELL_MASTERS_CALL_TRIGGERED, true);
                // there is a possibility that this effect should access effect 0 (dummy) target, but i dubt that
                // it's more likely that on on retail it's possible to call target selector based on dbc values
                // anyways, we're using GetTargetUnit() here and it's ok
                if (Unit * ally = GetTargetUnit())
                {
                    target->CastSpell(ally, GetEffectValue(), true);
                    target->CastSpell(ally, SpellMgr::CalculateSpellEffectAmount(GetSpellInfo(), EFFECT_0), true);
                }
            }
        }

        void Register()
        {
            OnEffect += SpellEffectFn(spell_hun_masters_call_SpellScript::HandleScriptEffect, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_hun_masters_call_SpellScript();
    }
};

class spell_hun_readiness : public SpellScriptLoader
{
public:
    spell_hun_readiness() : SpellScriptLoader("spell_hun_readiness") { }

    class spell_hun_readiness_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_hun_readiness_SpellScript)
        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            Unit *caster = GetCaster();
            if (caster->GetTypeId() != TYPEID_PLAYER)
                return;

            // immediately finishes the cooldown on your other Hunter abilities except Bestial Wrath
            const SpellCooldowns& cm = caster->ToPlayer()->GetSpellCooldownMap();
            for (SpellCooldowns::const_iterator itr = cm.begin(); itr != cm.end();)
            {
                SpellEntry const *spellInfo = sSpellStore.LookupEntry(itr->first);

                ///! If spellId in cooldown map isn't valid, the above will return a null pointer.
                if (spellInfo &&
                    spellInfo->SpellFamilyName == SPELLFAMILY_HUNTER &&
                    spellInfo->Id != HUNTER_SPELL_READINESS &&
                    spellInfo->Id != HUNTER_SPELL_BESTIAL_WRATH &&
                    GetSpellRecoveryTime(spellInfo) > 0)
                    caster->ToPlayer()->RemoveSpellCooldown((itr++)->first, true);
                else
                    ++itr;
            }
        }

        void Register()
        {
            // add dummy effect spell handler to Readiness
            OnEffect += SpellEffectFn(spell_hun_readiness_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_hun_readiness_SpellScript();
    }
};

// 37506 Scatter Shot
class spell_hun_scatter_shot : public SpellScriptLoader
{
public:
    spell_hun_scatter_shot() : SpellScriptLoader("spell_hun_scatter_shot") { }

    class spell_hun_scatter_shot_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_hun_scatter_shot_SpellScript)
        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            if (caster->GetTypeId() != TYPEID_PLAYER)
                return;

            // break Auto Shot and autohit
            caster->InterruptSpell(CURRENT_AUTOREPEAT_SPELL);
            caster->AttackStop();
            caster->ToPlayer()->SendAttackSwingCancelAttack();
        }

        void Register()
        {
            OnEffect += SpellEffectFn(spell_hun_scatter_shot_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_hun_scatter_shot_SpellScript();
    }
};

// 53302, 53303, 53304 Sniper Training
enum eSniperTrainingSpells
{
    SPELL_SNIPER_TRAINING_R1        = 53302,
    SPELL_SNIPER_TRAINING_BUFF_R1   = 64418,
};

class spell_hun_sniper_training : public SpellScriptLoader
{
public:
    spell_hun_sniper_training() : SpellScriptLoader("spell_hun_sniper_training") { }

    class spell_hun_sniper_training_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_hun_sniper_training_AuraScript)
        bool Validate(SpellEntry const * /*entry*/)
        {
            if (!sSpellStore.LookupEntry(SPELL_SNIPER_TRAINING_R1))
                return false;
            if (!sSpellStore.LookupEntry(SPELL_SNIPER_TRAINING_BUFF_R1))
                return false;
            return true;
        }

        void HandlePeriodic(AuraEffect const * aurEff)
        {
            PreventDefaultAction();
            if (aurEff->GetAmount() > 0)
                return;

            uint32 spellId = SPELL_SNIPER_TRAINING_BUFF_R1 + GetId() - SPELL_SNIPER_TRAINING_R1;
            Unit * pTarget = GetTarget();
            if (!pTarget->HasAura(spellId))
            {
                SpellEntry const * triggeredSpellInfo = sSpellStore.LookupEntry(spellId);
                Unit* triggerCaster = GetTriggeredSpellCaster(triggeredSpellInfo, GetCaster(), pTarget);
                triggerCaster->CastSpell(pTarget, triggeredSpellInfo, true, 0, aurEff);
            }
        }

        void HandleUpdatePeriodic(AuraEffect * aurEff)
        {
            Unit * pTarget = GetUnitOwner();
            if (Player* pPlayerTarget = pTarget->ToPlayer())
            {
                int32 baseAmount = aurEff->GetBaseAmount();
                int32 amount = pPlayerTarget->isMoving() ?
                pTarget->CalculateSpellDamage(pTarget, GetSpellProto(), aurEff->GetEffIndex(), &baseAmount) :
                aurEff->GetAmount() - 1;
                aurEff->SetAmount(amount);
            }
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_hun_sniper_training_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            OnEffectUpdatePeriodic += AuraEffectUpdatePeriodicFn(spell_hun_sniper_training_AuraScript::HandleUpdatePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }
    };

    AuraScript *GetAuraScript() const
    {
        return new spell_hun_sniper_training_AuraScript();
    }
};

class spell_hun_pet_heart_of_the_phoenix : public SpellScriptLoader
{
public:
    spell_hun_pet_heart_of_the_phoenix() : SpellScriptLoader("spell_hun_pet_heart_of_the_phoenix") { }

    class spell_hun_pet_heart_of_the_phoenix_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_hun_pet_heart_of_the_phoenix_SpellScript)
        bool Validate(SpellEntry const * /*spellEntry*/)
        {
            if (!sSpellStore.LookupEntry(HUNTER_PET_HEART_OF_THE_PHOENIX_TRIGGERED))
                return false;
            if (!sSpellStore.LookupEntry(HUNTER_PET_HEART_OF_THE_PHOENIX_DEBUFF))
                return false;
            return true;
        }

        void HandleScript(SpellEffIndex /*effIndex*/)
        {
            Unit *caster = GetCaster();
            Unit *owner = caster->GetOwner();
            if (!owner || caster->HasAura(HUNTER_PET_HEART_OF_THE_PHOENIX_DEBUFF))
                return;
            owner->CastCustomSpell(HUNTER_PET_HEART_OF_THE_PHOENIX_TRIGGERED, SPELLVALUE_BASE_POINT0, 100, caster, true);
            caster->CastSpell(caster, HUNTER_PET_HEART_OF_THE_PHOENIX_DEBUFF, true);
        }

        void Register()
        {
            // add dummy effect spell handler to pet's Last Stand
            OnEffect += SpellEffectFn(spell_hun_pet_heart_of_the_phoenix_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }

        bool Load()
        {
            if (!GetCaster()->isPet())
                return false;
            return true;
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_hun_pet_heart_of_the_phoenix_SpellScript();
    }
};

class spell_hun_pet_carrion_feeder : public SpellScriptLoader
{
public:
    spell_hun_pet_carrion_feeder() : SpellScriptLoader("spell_hun_pet_carrion_feeder") { }

    class spell_hun_pet_carrion_feeder_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_hun_pet_carrion_feeder_SpellScript)
        bool Validate(SpellEntry const * /*spellEntry*/)
        {
            if (!sSpellStore.LookupEntry(HUNTER_PET_SPELL_CARRION_FEEDER_TRIGGERED))
                return false;
            return true;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (!GetHitUnit())
                return;
            Unit *caster = GetCaster();
            caster->CastSpell(caster, HUNTER_PET_SPELL_CARRION_FEEDER_TRIGGERED, false);
        }

        void Register()
        {
            // add dummy effect spell handler to pet's Last Stand
            OnEffect += SpellEffectFn(spell_hun_pet_carrion_feeder_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }

        bool Load()
        {
            if (!GetCaster()->isPet())
                return false;
            return true;
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_hun_pet_carrion_feeder_SpellScript();
    }
};

void AddSC_hunter_spell_scripts()
{
    new spell_hun_chimera_shot();
    new spell_hun_invigoration();
    new spell_hun_last_stand_pet();
    new spell_hun_masters_call();
    new spell_hun_readiness();
    new spell_hun_scatter_shot();
    new spell_hun_sniper_training();
    new spell_hun_pet_heart_of_the_phoenix();
    new spell_hun_pet_carrion_feeder();
}
