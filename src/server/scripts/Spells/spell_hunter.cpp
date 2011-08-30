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
#include "GridNotifiers.h"

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
    HUNTER_SPELL_ASPECT_OF_THE_BEAST_PET         = 61669,
};

// 13161 Aspect of the Beast
class spell_hun_aspect_of_the_beast : public SpellScriptLoader
{
public:
    spell_hun_aspect_of_the_beast() : SpellScriptLoader("spell_hun_aspect_of_the_beast") { }

    class spell_hun_aspect_of_the_beast_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_hun_aspect_of_the_beast_AuraScript)
        bool Validate(SpellInfo const* /*entry*/)
        {
            if (!sSpellMgr->GetSpellInfo(HUNTER_SPELL_ASPECT_OF_THE_BEAST_PET))
                return false;
            return true;
        }

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (!GetCaster())
                return;

            Unit* caster = GetCaster();
            if (caster->ToPlayer())
                if (Pet* pet = caster->ToPlayer()->GetPet())
                    pet->RemoveAurasDueToSpell(HUNTER_SPELL_ASPECT_OF_THE_BEAST_PET);
        }

        void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (!GetCaster())
                return;

            Unit* caster = GetCaster();
            if (caster->ToPlayer())
                if (Pet* pet = caster->ToPlayer()->GetPet())
                    caster->CastSpell(caster, HUNTER_SPELL_ASPECT_OF_THE_BEAST_PET, true);
        }

        void Register()
        {
            AfterEffectApply += AuraEffectApplyFn(spell_hun_aspect_of_the_beast_AuraScript::OnApply, EFFECT_0, SPELL_AURA_UNTRACKABLE, AURA_EFFECT_HANDLE_REAL);
            AfterEffectRemove += AuraEffectRemoveFn(spell_hun_aspect_of_the_beast_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_UNTRACKABLE, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript *GetAuraScript() const
    {
        return new spell_hun_aspect_of_the_beast_AuraScript();
    }
};

// 53209 Chimera Shot
class spell_hun_chimera_shot : public SpellScriptLoader
{
public:
    spell_hun_chimera_shot() : SpellScriptLoader("spell_hun_chimera_shot") { }

    class spell_hun_chimera_shot_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_hun_chimera_shot_SpellScript)
        bool Validate(SpellInfo const* /*spellEntry*/)
        {
            if (!sSpellMgr->GetSpellInfo(HUNTER_SPELL_CHIMERA_SHOT_SERPENT))
                return false;
            if (!sSpellMgr->GetSpellInfo(HUNTER_SPELL_CHIMERA_SHOT_VIPER))
                return false;
            if (!sSpellMgr->GetSpellInfo(HUNTER_SPELL_CHIMERA_SHOT_SCORPID))
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
                flag96 familyFlag = aura->GetSpellInfo()->SpellFamilyFlags;
                if (!(familyFlag[1] & 0x00000080 || familyFlag[0] & 0x0000C000))
                    continue;
                if (AuraEffect const* aurEff = aura->GetEffect(0))
                {
                    // Serpent Sting - Instantly deals 40% of the damage done by your Serpent Sting.
                    if (familyFlag[0] & 0x4000)
                    {
                        int32 TickCount = aurEff->GetTotalTicks();
                        spellId = HUNTER_SPELL_CHIMERA_SHOT_SERPENT;
                        basePoint = caster->SpellDamageBonus(unitTarget, aura->GetSpellInfo(), aurEff->GetAmount(), DOT, aura->GetStackAmount());
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
        bool Validate(SpellInfo const* /*spellEntry*/)
        {
            if (!sSpellMgr->GetSpellInfo(HUNTER_SPELL_INVIGORATION_TRIGGERED))
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
        bool Validate(SpellInfo const* /*spellEntry*/)
        {
            if (!sSpellMgr->GetSpellInfo(HUNTER_PET_SPELL_LAST_STAND_TRIGGERED))
                return false;
            return true;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
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
            bool Validate(SpellInfo const* spellEntry)
            {
                if (!sSpellMgr->GetSpellInfo(HUNTER_SPELL_MASTERS_CALL_TRIGGERED))
                    return false;
                if (!sSpellMgr->GetSpellInfo(spellEntry->Effects[EFFECT_0].CalcValue()))
                    return false;
                if (!sSpellMgr->GetSpellInfo(spellEntry->Effects[EFFECT_1].CalcValue()))
                    return false;
                return true;
            }

            void HandleScriptEffect(SpellEffIndex /*effIndex*/)
            {
                if (Unit* target = GetHitUnit())
                {
                    // Cannot be processed while pet is dead
                    TriggerCastFlags castMask = TriggerCastFlags(TRIGGERED_FULL_MASK & ~TRIGGERED_IGNORE_CASTER_AURASTATE);
                    target->CastSpell(target, GetEffectValue(), castMask);
                    target->CastSpell(target, HUNTER_SPELL_MASTERS_CALL_TRIGGERED, castMask);
                    // there is a possibility that this effect should access effect 0 (dummy) target, but i dubt that
                    // it's more likely that on on retail it's possible to call target selector based on dbc values
                    // anyways, we're using GetTargetUnit() here and it's ok
                    if (Unit* ally = GetTargetUnit())
                    {
                        target->CastSpell(ally, GetEffectValue(), castMask);
                        target->CastSpell(ally, GetSpellInfo()->Effects[EFFECT_0].CalcValue(), castMask);
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
            Unit* caster = GetCaster();
            if (caster->GetTypeId() != TYPEID_PLAYER)
                return;

            // immediately finishes the cooldown on your other Hunter abilities except Bestial Wrath
            const SpellCooldowns& cm = caster->ToPlayer()->GetSpellCooldownMap();
            for (SpellCooldowns::const_iterator itr = cm.begin(); itr != cm.end();)
            {
                SpellInfo const *spellInfo = sSpellMgr->GetSpellInfo(itr->first);

                ///! If spellId in cooldown map isn't valid, the above will return a null pointer.
                if (spellInfo &&
                    spellInfo->SpellFamilyName == SPELLFAMILY_HUNTER &&
                    spellInfo->Id != HUNTER_SPELL_READINESS &&
                    spellInfo->Id != HUNTER_SPELL_BESTIAL_WRATH &&
                    spellInfo->GetRecoveryTime() > 0)
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
        bool Validate(SpellInfo const* /*entry*/)
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_SNIPER_TRAINING_R1))
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_SNIPER_TRAINING_BUFF_R1))
                return false;
            return true;
        }

        void HandlePeriodic(AuraEffect const* aurEff)
        {
            PreventDefaultAction();
            if (aurEff->GetAmount() > 0)
                return;

            Unit* caster = GetCaster();

            if (!caster)
                return;

            uint32 spellId = SPELL_SNIPER_TRAINING_BUFF_R1 + GetId() - SPELL_SNIPER_TRAINING_R1;
            Unit* target = GetTarget();
            if (!target->HasAura(spellId))
            {
                SpellInfo const* triggeredSpellInfo = sSpellMgr->GetSpellInfo(spellId);
                Unit* triggerCaster = triggeredSpellInfo->NeedsToBeTriggeredByCaster() ? caster : target;
                triggerCaster->CastSpell(target, triggeredSpellInfo, true, 0, aurEff);
            }
        }

        void HandleUpdatePeriodic(AuraEffect * aurEff)
        {
            Unit* target = GetUnitOwner();
            if (Player* playerTarget = target->ToPlayer())
            {
                int32 baseAmount = aurEff->GetBaseAmount();
                int32 amount = playerTarget->isMoving() ?
                target->CalculateSpellDamage(target, GetSpellInfo(), aurEff->GetEffIndex(), &baseAmount) :
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
        bool Validate(SpellInfo const* /*spellEntry*/)
        {
            if (!sSpellMgr->GetSpellInfo(HUNTER_PET_HEART_OF_THE_PHOENIX_TRIGGERED))
                return false;
            if (!sSpellMgr->GetSpellInfo(HUNTER_PET_HEART_OF_THE_PHOENIX_DEBUFF))
                return false;
            return true;
        }

        void HandleScript(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* owner = caster->GetOwner();
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
        bool Validate(SpellInfo const* /*spellEntry*/)
        {
            if (!sSpellMgr->GetSpellInfo(HUNTER_PET_SPELL_CARRION_FEEDER_TRIGGERED))
                return false;
            return true;
        }

        SpellCastResult CheckIfCorpseNear()
        {
            Unit* caster = GetCaster();
            float max_range = GetSpellInfo()->GetMaxRange(false);
            WorldObject* result = NULL;
            // search for nearby enemy corpse in range
            Trinity::AnyDeadUnitSpellTargetInRangeCheck check(caster, max_range, GetSpellInfo(), TARGET_SELECT_CHECK_ENEMY);
            Trinity::WorldObjectSearcher<Trinity::AnyDeadUnitSpellTargetInRangeCheck> searcher(caster, result, check);
            caster->GetMap()->VisitFirstFound(caster->m_positionX, caster->m_positionY, max_range, searcher);
            if (!result)
                return SPELL_FAILED_NO_EDIBLE_CORPSES;
            return SPELL_CAST_OK;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            caster->CastSpell(caster, HUNTER_PET_SPELL_CARRION_FEEDER_TRIGGERED, false);
        }

        void Register()
        {
            // add dummy effect spell handler to pet's Last Stand
            OnEffect += SpellEffectFn(spell_hun_pet_carrion_feeder_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            OnCheckCast += SpellCheckCastFn(spell_hun_pet_carrion_feeder_SpellScript::CheckIfCorpseNear);
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
    new spell_hun_aspect_of_the_beast();
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
