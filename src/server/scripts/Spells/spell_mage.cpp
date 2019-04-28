/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
 * Scripts for spells with SPELLFAMILY_MAGE and SPELLFAMILY_GENERIC spells used by mage players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_mage_".
 */

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "Creature.h"
#include "CombatAI.h"
#include "GridNotifiers.h"
#include "Group.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "TemporarySummon.h"

enum MageSpells
{
    //7.3.2.25549
    SPELL_MAGE_COLD_SNAP                         = 235219,
    SPELL_MAGE_FROST_NOVA                        = 122,
    SPELL_MAGE_CONE_OF_COLD                      = 120,
    SPELL_MAGE_CONE_OF_COLD_SLOW                 = 212792,
    SPELL_MAGE_ICE_BARRIER                       = 11426,
    SPELL_MAGE_ICE_BLOCK                         = 45438,
    SPELL_MAGE_GLACIAL_INSULATION                = 235297,
    SPELL_MAGE_BONE_CHILLING                     = 205027,
    SPELL_MAGE_BONE_CHILLING_BUFF                = 205766,
    SPELL_MAGE_CHILLED                           = 205708,
    SPELL_MAGE_ICE_LANCE                         = 30455,
    SPELL_MAGE_ICE_LANCE_TRIGGER                 = 228598,
    SPELL_MAGE_THERMAL_VOID                      = 155149,
    SPELL_MAGE_ICY_VEINS                         = 12472,
    SPELL_MAGE_GLACIAL_SPIKE                     = 199786,
    SPELL_MAGE_ICICLE_PERIODIC_TRIGGER           = 148023,
    SPELL_MAGE_FLURRY_DEBUFF_PROC                = 228354,
    SPELL_MAGE_FLURRY                            = 44614,
    SPELL_MAGE_FLURRY_DAMAGE                     = 228672,
    SPELL_MAGE_FLURRY_CHILL_PROC                 = 228358,
    SPELL_MAGE_FLURRY_VISUAL                     = 228596,
    SPELL_MAGE_SHIELD_OF_ALODI                   = 195354,
    SPELL_MAGE_BRAIN_FREEZE                      = 190447,
    SPELL_MAGE_BRAIN_FREEZE_AURA                 = 190446,
    SPELL_MAGE_BRAIN_FREEZE_IMPROVED             = 231584,
    SPELL_MAGE_JOUSTER                           = 214626,
    SPELL_MAGE_CHAIN_REACTION                    = 195419,
    SPELL_MAGE_CHILLED_TO_THE_CORE               = 195448,
    SPELL_MAGE_GLARITY_OF_THOUGHT                = 195351,
    SPELL_MAGE_ICE_NOVA                          = 157997,
    SPELL_MAGE_FROZEN_TOUCH                      = 205030,
    SPELL_MAGE_FROZEN_ORB                        = 84714,
    SPELL_MAGE_FROZEN_ORB_DAMAGE                 = 84721,
    SPELL_MAGE_BLIZZARD_RANK_2                   = 236662,
    SPELL_MAGE_UNSTABLE_MAGIC                    = 157976,
    SPELL_MAGE_UNSTABLE_MAGIC_DAMAGE_FIRE        = 157977,
    SPELL_MAGE_UNSTABLE_MAGIC_DAMAGE_FROST       = 157978,
    SPELL_MAGE_UNSTABLE_MAGIC_DAMAGE_ARCANE      = 157979,
    SPELL_MAGE_FINGERS_OF_FROST                  = 112965,
    SPELL_MAGE_FINGERS_OF_FROST_AURA             = 44544,
    SPELL_MAGE_FINGERS_OF_FROST_VISUAL_UI        = 126084,
    SPELL_MAGE_FROST_BOMB_AURA                   = 112948,
    SPELL_MAGE_FROST_BOMB_TRIGGERED              = 113092,
    SPELL_MAGE_FROSTBOLT                         = 116,
    SPELL_MAGE_FROSTBOLT_TRIGGER                 = 228597,
    SPELL_MAGE_RAY_OF_FROST                      = 205021,
    SPELL_MAGE_RAY_OF_FROST_BUFF                 = 208166,
    SPELL_MAGE_RAY_OF_FROST_DAMAGE_INCREASE      = 208141,
    SPELL_BLAZING_BARRIER_TRIGGER                = 235314,
    SPELL_MAGE_SCORCH                            = 2948,
    SPELL_MAGE_FIREBALL                          = 133,
    SPELL_MAGE_FIRE_BLAST                        = 108853,
    SPELL_MAGE_FLAMESTRIKE                       = 2120,
    SPELL_MAGE_PYROBLAST                         = 11366,
    SPELL_MAGE_PHOENIX_FLAMES                    = 194466,
    SPELL_MAGE_DRAGON_BREATH                     = 31661,
    SPELL_MAGE_PYROMANIAC                        = 205020,
    SPELL_MAGE_ALEXSTRASZAS_FURY                 = 235870,
    SPELL_MAGE_LIVING_BOMB_DAMAGE                = 44461,
    SPELL_MAGE_LIVING_BOMB_DOT                   = 217694,
    SPELL_MAGE_METEOR_DAMAGE                     = 153564,
    SPELL_MAGE_METEOR_TIMER                      = 177345,
    SPELL_MAGE_METEOR_VISUAL                     = 174556,
    SPELL_MAGE_METEOR_BURN                       = 155158,
    SPELL_MAGE_COMET_STORM                       = 153595,
    SPELL_MAGE_COMET_STORM_DAMAGE                = 153596,
    SPELL_MAGE_COMET_STORM_VISUAL                = 242210,
    SPELL_MAGE_POLYMORPH_CRITTERMORPH            = 120091,
    SPELL_MAGE_HEATING_UP                        = 48107,
    SPELL_MAGE_HOT_STREAK                        = 48108,
    SPELL_MAGE_ENHANCED_PYROTECHNICS_AURA        = 157644,

    SPELL_MAGE_INCANTERS_FLOW_BUFF               = 116267,
    SPELL_MAGE_RUNE_OF_POWER_BUFF                = 116014,
    SPELL_MAGE_OVERPOWERED                       = 155147,
    SPELL_MAGE_ARCANE_POWER                      = 12042,
    SPELL_MAGE_CHRONO_SHIFT                      = 235711,
    SPELL_MAGE_CHRONO_SHIFT_SLOW                 = 236299,
    SPELL_MAGE_ARCANE_BLAST                      = 30451,
    SPELL_MAGE_ARCANE_BARRAGE                    = 44425,
    SPELL_MAGE_ARCANE_BARRAGE_TRIGGERED          = 241241,
    SPELL_MAGE_PRESENCE_OF_MIND                  = 205025,
    SPELL_MAGE_ARCANE_MISSILES_VISUAL_TWO        = 79808,
    SPELL_MAGE_ARCANE_MISSILES_VISUAL_ONE        = 170571,
    SPELL_MAGE_ARCANE_MISSILES_VISUAL_THREE      = 170572,
    SPELL_MAGE_ARCANE_MISSILES_TRIGGER           = 7268,
    SPELL_MAGE_ARCANE_MISSILES                   = 5143,
    SPELL_MAGE_ARCANE_MISSILES_DAMAGE            = 7268,
    SPELL_MAGE_ARCANE_MISSILES_POWER             = 208030,
    SPELL_MAGE_ARCANE_MISSILES_CHARGES           = 79683,
    SPELL_MAGE_ARCANE_ORB_DAMAGE                 = 153640,
    SPELL_MAGE_ARCANE_AMPLIFICATION              = 236628,

    //7.3.2.25549 END
    SPELL_MAGE_RING_OF_FROST_FREEZE              = 82691,
    SPELL_MAGE_RING_OF_FROST_IMMUNE              = 91264,
    SPELL_MAGE_RING_OF_FROST                     = 113724,
    SPELL_MAGE_FIRE_MAGE_PASSIVE                 = 137019,
    SPELL_MAGE_FIRE_ON                           = 205029,
    SPELL_MAGE_FIRESTARTER                       = 205026,
    SPELL_MAGE_CAUTERIZE                         = 87023,
    SPELL_MAGE_MIRROR_IMAGE_LEFT                 = 58834,
    SPELL_MAGE_MIRROR_IMAGE_RIGHT                = 58833,
    SPELL_MAGE_MIRROR_IMAGE_FRONT                = 58831,
    SPELL_MAGE_COMBUSTION                        = 190319,
    SPELL_MAGE_WATER_JET                         = 135029,
    SPELL_MAGE_ICE_FLOES                         = 108839,
    SPELL_MAGE_CONJURE_REFRESHMENT_GROUP         = 167145,
    SPELL_MAGE_CONJURE_REFRESHMENT_SOLO          = 116136,
    SPELL_MAGE_HYPOTHERMIA                       = 41425,
    SPELL_INFERNO                                = 253220,
    SPELL_MAGE_BLAZING_BARRIER                   = 235313,
    SPELL_MAGE_BLAZING_SOUL                      = 235365,
    SPELL_MAGE_CONTROLLED_BURN                   = 205033,
    SPELL_MAGE_FLAME_PATCH                       = 205037,
    SPELL_MAGE_FLAME_PATCH_TRIGGER               = 205470,
    SPELL_MAGE_FLAME_PATCH_AOE_DMG               = 205472,
    SPELL_MAGE_CINDERSTORM                       = 198929,
    SPELL_MAGE_CINDERSTORM_DMG                   = 198928,
    SPELL_MAGE_SPLITTING_ICE                     = 56377,
    SPELL_MAGE_EBONBOLT_DAMAGE                   = 214634,
    SPELL_MAGE_IGNITE_DOT                        = 12654
};

enum TemporalDisplacementSpells
{
    SPELL_MAGE_TEMPORAL_DISPLACEMENT             = 80354,
    SPELL_HUNTER_INSANITY                        = 95809,
    SPELL_PRIEST_SHADOW_WORD_DEATH               = 32409,
    SPELL_SHAMAN_EXHAUSTION                      = 57723,
    SPELL_SHAMAN_SATED                           = 57724,
    SPELL_PET_NETHERWINDS_FATIGUED               = 160455
};

// Runic Empowerment - 81229
class playerscript_mage_arcane : public PlayerScript
{
public:
    playerscript_mage_arcane() : PlayerScript("playerscript_mage_arcane") {}

    enum eSpells
    {
        AURA_ARCANIC_CHARGE = 36032,
    };

    void OnModifyPower(Player* player, Powers power, int32 /*oldValue*/, int32& newValue, bool /*regen*/, bool /*after*/)
    {
        if (power != POWER_ARCANE_CHARGES)
            return;

        player->RemoveAurasDueToSpell(AURA_ARCANIC_CHARGE);

        for (int32 i = 0; i < newValue; ++i)
            player->CastSpell(player, AURA_ARCANIC_CHARGE, true);
    }
};

// Chrono Shift - 235711
class spell_mage_chrono_shift : public AuraScript
{
    PrepareAuraScript(spell_mage_chrono_shift);

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        bool _spellCanProc = (eventInfo.GetSpellInfo()->Id == SPELL_MAGE_ARCANE_BARRAGE || eventInfo.GetSpellInfo()->Id == SPELL_MAGE_ARCANE_BARRAGE_TRIGGERED);

        if (_spellCanProc)
            return true;
        return false;
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_mage_chrono_shift::CheckProc);
    }
};

// Arcane Explosion - 1449
class spell_mage_arcane_explosion : public SpellScript
{
    PrepareSpellScript(spell_mage_arcane_explosion);

    bool _hit;

    bool Load() override
    {
        _hit = false;
        return true;
    }

    void CheckTargets(std::list<WorldObject*>& targets)
    {
        if (!targets.empty())
            _hit = true;
    }

    void Prevent(SpellEffIndex effIndex)
    {
        if (!_hit)
            PreventHitEffect(effIndex);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_mage_arcane_explosion::CheckTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectLaunch += SpellEffectFn(spell_mage_arcane_explosion::Prevent, EFFECT_1, SPELL_EFFECT_ENERGIZE);
        OnEffectLaunchTarget += SpellEffectFn(spell_mage_arcane_explosion::Prevent, EFFECT_1, SPELL_EFFECT_ENERGIZE);
        OnEffectHit += SpellEffectFn(spell_mage_arcane_explosion::Prevent, EFFECT_1, SPELL_EFFECT_ENERGIZE);
        OnEffectHitTarget += SpellEffectFn(spell_mage_arcane_explosion::Prevent, EFFECT_1, SPELL_EFFECT_ENERGIZE);
    }
};

// Arcane Missiles - 5143
class spell_mage_arcane_missiles : public AuraScript
{
    PrepareAuraScript(spell_mage_arcane_missiles);

    void OnApply(AuraEffect const* /*p_AurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->CastSpell(caster, SPELL_MAGE_ARCANE_MISSILES_POWER, true);

        if (Aura* missilesCharges = caster->GetAura(SPELL_MAGE_ARCANE_MISSILES_CHARGES))
        {
            switch (missilesCharges->GetStackAmount())
            {
                case 1:
                    caster->RemoveAurasDueToSpell(SPELL_MAGE_ARCANE_MISSILES_VISUAL_ONE);
                    break;
                case 2:
                    caster->RemoveAurasDueToSpell(SPELL_MAGE_ARCANE_MISSILES_VISUAL_TWO);
                    caster->CastSpell(caster, SPELL_MAGE_ARCANE_MISSILES_VISUAL_ONE, true);
                    break;
                case 3:
                    caster->RemoveAurasDueToSpell(SPELL_MAGE_ARCANE_MISSILES_VISUAL_THREE);
                    caster->CastSpell(caster, SPELL_MAGE_ARCANE_MISSILES_VISUAL_TWO, true);
                    break;
            }
            missilesCharges->ModStackAmount(-1);
        }
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_mage_arcane_missiles::OnApply, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

// Arcane Missiles Damage - 7268
class spell_mage_arcane_missiles_damage :public SpellScript
{
    PrepareSpellScript(spell_mage_arcane_missiles_damage);

    void CheckTarget(WorldObject*& target)
    {
        if (target == GetCaster())
            target = nullptr;
    }

    void Register() override
    {
        OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_mage_arcane_missiles_damage::CheckTarget, EFFECT_0, TARGET_UNIT_CHANNEL_TARGET);
    }
};

// Arcane Missiles Proc - 79684
class spell_mage_arcane_missiles_proc : public AuraScript
{
    PrepareAuraScript(spell_mage_arcane_missiles_proc);

    bool HandleProc(ProcEventInfo& eventInfo)
    {
        if (eventInfo.GetSpellInfo()->Id == SPELL_MAGE_ARCANE_MISSILES ||
            eventInfo.GetSpellInfo()->Id == SPELL_MAGE_ARCANE_MISSILES_TRIGGER)
            return false;
        return true;
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_mage_arcane_missiles_proc::HandleProc);
    }
};

// Arcane Missiles charges - 79683
class spell_mage_arcane_missiles_charges : public AuraScript
{
    PrepareAuraScript(spell_mage_arcane_missiles_charges);

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (Aura* missilesCharges = caster->GetAura(SPELL_MAGE_ARCANE_MISSILES_CHARGES))
        {
            switch (missilesCharges->GetStackAmount())
            {
                case 1:
                    caster->CastSpell(caster, SPELL_MAGE_ARCANE_MISSILES_VISUAL_ONE, true);
                    break;
                case 2:
                    caster->RemoveAurasDueToSpell(SPELL_MAGE_ARCANE_MISSILES_VISUAL_ONE);
                    caster->CastSpell(caster, SPELL_MAGE_ARCANE_MISSILES_VISUAL_TWO, true);
                    break;
                case 3:
                    caster->RemoveAurasDueToSpell(SPELL_MAGE_ARCANE_MISSILES_VISUAL_TWO);
                    caster->CastSpell(caster, SPELL_MAGE_ARCANE_MISSILES_VISUAL_THREE, true);
                    break;
            }
        }
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        Aura* missilesCharges = caster->GetAura(SPELL_MAGE_ARCANE_MISSILES_CHARGES);

        if (!missilesCharges)
        {
            caster->RemoveAurasDueToSpell(SPELL_MAGE_ARCANE_MISSILES_VISUAL_ONE);
            caster->RemoveAurasDueToSpell(SPELL_MAGE_ARCANE_MISSILES_VISUAL_TWO);
            caster->RemoveAurasDueToSpell(SPELL_MAGE_ARCANE_MISSILES_VISUAL_THREE);
        }
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectApplyFn(spell_mage_arcane_missiles_charges::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectApply += AuraEffectApplyFn(spell_mage_arcane_missiles_charges::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

class CheckArcaneBarrageImpactPredicate
{
public:
    CheckArcaneBarrageImpactPredicate(Unit* caster, Unit* mainTarget) : _caster(caster), _mainTarget(mainTarget) {}

    bool operator()(Unit* target)
    {
        if (!_caster || !_mainTarget)
            return true;

        if (!_caster->IsValidAttackTarget(target))
            return true;

        if (!target->IsWithinLOSInMap(_caster))
            return true;

        if (!_caster->isInFront(target))
            return true;

        if (target->GetGUID() == _caster->GetGUID())
            return true;

        if (target->GetGUID() == _mainTarget->GetGUID())
            return true;

        return false;
    }

private:
    Unit * _caster;
    Unit* _mainTarget;
};

// Arcane Barrage - 44425
class spell_mage_arcane_barrage : public SpellScript
{
    PrepareSpellScript(spell_mage_arcane_barrage);

    void OnHit(SpellEffIndex /* effIndex */)
    {
        GetCaster()->SetPower(POWER_ARCANE_CHARGES, 0);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_mage_arcane_barrage::OnHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// Arcane Blast - 30451
class spell_mage_arcane_blast : public SpellScript
{
    PrepareSpellScript(spell_mage_arcane_blast);

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster || !caster->IsPlayer())
            return;

        if (Aura* presenceOfMind = caster->GetAura(SPELL_MAGE_PRESENCE_OF_MIND))
            presenceOfMind->ModCharges(-1);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_mage_arcane_blast::HandleHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// Arcane Barrier - 235450
class spell_mage_arcane_barrier : public AuraScript
{
    PrepareAuraScript(spell_mage_arcane_barrier);

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& canBeRecalculated)
    {
        canBeRecalculated = false;
        if (Unit* caster = GetCaster())
            amount += int32(7.0f * caster->SpellBaseHealingBonusDone(GetSpellInfo()->GetSchoolMask()));
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_mage_arcane_barrier::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
    }
};

// Fire Blast - 108853
class spell_mage_fire_blast : public SpellScript
{
    PrepareSpellScript(spell_mage_fire_blast);

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        // this is already handled by Pyroblast Clearcasting Driver - 44448
        /*bool procCheck = false;

        if (Unit* caster = GetCaster())
        {
            if (!caster->HasAura(SPELL_MAGE_HEATING_UP) && !caster->HasAura(SPELL_MAGE_HOT_STREAK))
            {
                caster->CastSpell(caster, SPELL_MAGE_HEATING_UP, true);
                procCheck = true;
            }
                

            if (caster->HasAura(SPELL_MAGE_HEATING_UP) && !caster->HasAura(SPELL_MAGE_HOT_STREAK) && !procCheck)
            {
                caster->RemoveAurasDueToSpell(SPELL_MAGE_HEATING_UP);
                caster->CastSpell(caster, SPELL_MAGE_HOT_STREAK, true);
            }
        }*/
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_mage_fire_blast::HandleHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// Enhanced Pyrotechnics - 157642
class spell_mage_enhanced_pyrotechnics : public AuraScript
{
    PrepareAuraScript(spell_mage_enhanced_pyrotechnics);

    bool HandleProc(ProcEventInfo& eventInfo)
    {
        Unit* caster = GetCaster();

        if (eventInfo.GetSpellInfo()->Id == SPELL_MAGE_FIREBALL)
        {
            if ((eventInfo.GetHitMask() & PROC_HIT_CRITICAL))
            {
                if (caster->HasAura(SPELL_MAGE_ENHANCED_PYROTECHNICS_AURA))
                    caster->RemoveAurasDueToSpell(SPELL_MAGE_ENHANCED_PYROTECHNICS_AURA);
                return false;
            }
            return true;
        }
        return false;
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_mage_enhanced_pyrotechnics::HandleProc);
    }
};

// Polymorph - 118
class spell_mage_polymorph : public SpellScript
{
    PrepareSpellScript(spell_mage_polymorph);

    void HandleTarget(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
        {
            if (!caster->HasAura(56382))
                return;

            if (Unit* target = GetHitUnit())
            {
                if (target->GetCreatureType() == CREATURE_TYPE_CRITTER)
                {
                    PreventHitAura();

                    caster->CastSpell(target, SPELL_MAGE_POLYMORPH_CRITTERMORPH, true);
                }
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_mage_polymorph::HandleTarget, EFFECT_1, TARGET_UNIT_TARGET_ENEMY);
    }
};

// Comet Storm - 153595
class spell_mage_comet_storm : public SpellScript
{
    PrepareSpellScript(spell_mage_comet_storm);

    void HandleDummy()
    {
        Unit* caster = GetCaster();
        WorldLocation const* dest = GetExplTargetDest();

        if (!caster || !dest)
            return;

        Position targetPos = dest->GetPosition();

        for (uint8 i = 0; i < 7; ++i)
        {
            caster->GetScheduler().Schedule(Milliseconds(300 * i), [targetPos](TaskContext context)
            {
                GetContextUnit()->CastSpell(targetPos, SPELL_MAGE_COMET_STORM_VISUAL, true);

                // Damage come 1sec after visual
                context.Schedule(Milliseconds(1000), [targetPos](TaskContext context)
                {
                    GetContextUnit()->CastSpell(targetPos, SPELL_MAGE_COMET_STORM_DAMAGE, true);
                });
            });
        }
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_mage_comet_storm::HandleDummy);
    }
};

// Meteor - 153561
class spell_mage_meteor : public SpellScript
{
    PrepareSpellScript(spell_mage_meteor);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGE_METEOR_DAMAGE });
    }

    void HandleDummy()
    {
        Unit* caster = GetCaster();
        WorldLocation const* dest = GetExplTargetDest();
        if (!caster || !dest)
            return;

        caster->CastSpell(dest->GetPositionX(), dest->GetPositionY(), dest->GetPositionZ(), SPELL_MAGE_METEOR_TIMER, true);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_mage_meteor::HandleDummy);
    }
};

// Meteor Damage - 153564
class spell_mage_meteor_damage : public SpellScript
{
    PrepareSpellScript(spell_mage_meteor_damage);

    int32 _targets;

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        Unit* unit = GetHitUnit();
        if (!unit)
            return;

        SetHitDamage(GetHitDamage() / _targets);
    }

    void CountTargets(std::list<WorldObject*>& targets)
    {
        _targets = targets.size();
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_mage_meteor_damage::HandleHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_mage_meteor_damage::CountTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
    }
};

// Living Bomb - 44457
class spell_mage_living_bomb : public SpellScript
{
    PrepareSpellScript(spell_mage_living_bomb);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo
        ({
            SPELL_MAGE_LIVING_BOMB_DAMAGE,
            SPELL_MAGE_LIVING_BOMB_DOT
        });
    }

    void HandleOnHit(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();
        if (!target || !caster)
            return;

        caster->CastCustomSpell(SPELL_MAGE_LIVING_BOMB_DOT, SPELLVALUE_BASE_POINT1, 1, target, TRIGGERED_FULL_MASK);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_mage_living_bomb::HandleOnHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// Living Bomb Dot - 217694
class spell_mage_living_bomb_dot : public AuraScript
{
    PrepareAuraScript(spell_mage_living_bomb_dot);

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetTarget();
        if (!caster || !target)
            return;

        int32 check = GetAura()->GetEffect(EFFECT_1)->GetBaseAmount();
        caster->CastCustomSpell(SPELL_MAGE_LIVING_BOMB_DAMAGE, SPELLVALUE_BASE_POINT0, check, target, TRIGGERED_FULL_MASK);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_mage_living_bomb_dot::HandleRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
    }
};

// Living Bomb Damage - 44461
class spell_mage_living_bomb_spread : public SpellScript
{
    PrepareSpellScript(spell_mage_living_bomb_spread);

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* hitunit = GetHitUnit();
        Unit* explunit = GetExplTargetUnit();
        if (!caster || !hitunit || !explunit)
            return;

        int32 check = GetSpellValue()->EffectBasePoints[0];
        if (check && hitunit != explunit)
            caster->CastCustomSpell(SPELL_MAGE_LIVING_BOMB_DOT, SPELLVALUE_BASE_POINT1, 0, hitunit, TRIGGERED_FULL_MASK);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_mage_living_bomb_spread::HandleHit, EFFECT_1, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// Frenetic Speed - 236058
class spell_mage_frenetic_speed : public AuraScript
{
    PrepareAuraScript(spell_mage_frenetic_speed);

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        bool _spellCanProc = (eventInfo.GetSpellInfo()->Id == SPELL_MAGE_SCORCH);

        if (_spellCanProc)
            return true;

        return false;
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_mage_frenetic_speed::CheckProc);
    }
};

// Conflagration - 205023
class spell_mage_conflagration : public AuraScript
{
    PrepareAuraScript(spell_mage_conflagration);

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        return eventInfo.GetSpellInfo()->Id == SPELL_MAGE_FIREBALL;
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_mage_conflagration::CheckProc);
    }
};

// Blazing Barrier - 235313
class spell_mage_blazing_barrier : public AuraScript
{
    PrepareAuraScript(spell_mage_blazing_barrier);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_BLAZING_BARRIER_TRIGGER });
    }

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& canBeRecalculated)
    {
        canBeRecalculated = false;
        if (Unit* caster = GetCaster())
            amount += int32(caster->SpellBaseHealingBonusDone(GetSpellInfo()->GetSchoolMask()) * 7.0f);
    }

    void Absorb(AuraEffect* auraEffect, DamageInfo& dmgInfo, uint32& /*absorbAmount*/)
    {
        Unit* caster = auraEffect->GetCaster();
        Unit* target = dmgInfo.GetAttacker();
        if (!caster || !target || caster == target)
            return;

        if (target->HasAura(GetId()))
            return;

        caster->CastSpell(target, SPELL_BLAZING_BARRIER_TRIGGER, true);
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_mage_blazing_barrier::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
        AfterEffectAbsorb += AuraEffectAbsorbFn(spell_mage_blazing_barrier::Absorb, EFFECT_0);
    }
};

// Pyroblast 11366
class spell_mage_pyroblast : public SpellScript
{
    PrepareSpellScript(spell_mage_pyroblast);

    void HandleOnHit(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (caster->HasAura(SPELL_MAGE_HOT_STREAK))
        {
            caster->RemoveAurasDueToSpell(SPELL_MAGE_HOT_STREAK);
            if (caster->HasAura(SPELL_MAGE_PYROMANIAC))
            {
                int32 pyromaniacChance = 0;

                if (Aura* pyromaniacAura = caster->GetAura(SPELL_MAGE_PYROMANIAC))
                {
                    pyromaniacChance = (pyromaniacAura->GetEffect(EFFECT_0)->GetAmount());
                }

                if (roll_chance_i(pyromaniacChance))
                {
                    if (caster->HasAura(SPELL_MAGE_HEATING_UP))
                        caster->RemoveAurasDueToSpell(SPELL_MAGE_HEATING_UP);
                    caster->CastSpell(caster, SPELL_MAGE_HOT_STREAK, true);
                }
            }
        }      
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_mage_pyroblast::HandleOnHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// Flamestrike 2120
class spell_mage_flamestrike : public SpellScript
{
    PrepareSpellScript(spell_mage_flamestrike);

    void HandleOnHit(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (caster->HasAura(SPELL_MAGE_HOT_STREAK))
        {
            caster->RemoveAurasDueToSpell(SPELL_MAGE_HOT_STREAK);
            if (caster->HasAura(SPELL_MAGE_PYROMANIAC))
            {
                int32 pyromaniacChance = 0;

                if (Aura* pyromaniacAura = caster->GetAura(SPELL_MAGE_PYROMANIAC))
                {
                    pyromaniacChance = (pyromaniacAura->GetEffect(EFFECT_0)->GetAmount());
                }

                if (roll_chance_i(pyromaniacChance))
                {
                    if (caster->HasAura(SPELL_MAGE_HEATING_UP))
                        caster->RemoveAurasDueToSpell(SPELL_MAGE_HEATING_UP);
                    caster->CastSpell(caster, SPELL_MAGE_HOT_STREAK, true);
                } 
            }
        }
    }

    void HandleDummy()
    {
        Unit* caster = GetCaster();
        WorldLocation const* dest = GetExplTargetDest();
        if (!caster || !dest)
            return;

        if (caster->HasAura(SPELL_MAGE_FLAME_PATCH))
        {
            if (WorldLocation const* dest = GetExplTargetDest())
            {
                caster->CastSpell(dest->GetPosition(), SPELL_MAGE_FLAME_PATCH_TRIGGER, true);
            }
        }
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_mage_flamestrike::HandleOnHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        AfterCast += SpellCastFn(spell_mage_flamestrike::HandleDummy);
    }
};

// Kindling - 155148
class spell_mage_kindling : public AuraScript
{
    PrepareAuraScript(spell_mage_kindling);

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        bool _spellCanProc = (eventInfo.GetSpellInfo()->Id == SPELL_MAGE_FIREBALL || eventInfo.GetSpellInfo()->Id == SPELL_MAGE_FIRE_BLAST || eventInfo.GetSpellInfo()->Id == SPELL_MAGE_PYROBLAST);

        if (_spellCanProc)
            return true;
        return false;
    }

    void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->GetSpellHistory()->ModifyCooldown(SPELL_MAGE_COMBUSTION, -1 * IN_MILLISECONDS);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_mage_kindling::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_mage_kindling::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// Pyroblast Clearcasting Driver - 44448
class spell_mage_pyroblast_clearcasting_driver : public AuraScript
{
    PrepareAuraScript(spell_mage_pyroblast_clearcasting_driver);

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        Unit* caster = GetCaster();

        bool _spellCanProc = (eventInfo.GetSpellInfo()->Id == SPELL_MAGE_SCORCH || eventInfo.GetSpellInfo()->Id == SPELL_MAGE_FIREBALL || eventInfo.GetSpellInfo()->Id == SPELL_MAGE_FIRE_BLAST || eventInfo.GetSpellInfo()->Id == SPELL_MAGE_FLAMESTRIKE || eventInfo.GetSpellInfo()->Id == SPELL_MAGE_PYROBLAST || eventInfo.GetSpellInfo()->Id == SPELL_MAGE_PHOENIX_FLAMES || (eventInfo.GetSpellInfo()->Id == SPELL_MAGE_DRAGON_BREATH && caster->HasAura(SPELL_MAGE_ALEXSTRASZAS_FURY)));

        if (_spellCanProc)
            return true;
        return false;
    }

    void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        bool procCheck = false;

        Unit* caster = GetCaster();

        if ((eventInfo.GetHitMask() & PROC_HIT_NORMAL))
        {
            if (caster->HasAura(SPELL_MAGE_HEATING_UP))
                caster->RemoveAurasDueToSpell(SPELL_MAGE_HEATING_UP);
            return;
        }

        if (!caster->HasAura(SPELL_MAGE_HEATING_UP) && !caster->HasAura(SPELL_MAGE_HOT_STREAK))
        {
            caster->CastSpell(caster, SPELL_MAGE_HEATING_UP, true);

            procCheck = true;

            if (AuraEffect* burn = caster->GetAuraEffect(SPELL_MAGE_CONTROLLED_BURN, EFFECT_0))
                if (roll_chance_i(burn->GetAmount()))
                    procCheck = false;
        }


        if (caster->HasAura(SPELL_MAGE_HEATING_UP) && !caster->HasAura(SPELL_MAGE_HOT_STREAK) && !procCheck)
        {
            caster->RemoveAurasDueToSpell(SPELL_MAGE_HEATING_UP);
            caster->CastSpell(caster, SPELL_MAGE_HOT_STREAK, true);
        }
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_mage_pyroblast_clearcasting_driver::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
        DoCheckProc += AuraCheckProcFn(spell_mage_pyroblast_clearcasting_driver::CheckProc);
    }
};

// Fireball 133
// Pyroblast 11366
class spell_mage_firestarter : public SpellScript
{
    PrepareSpellScript(spell_mage_firestarter);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo
        ({
            SPELL_MAGE_FIREBALL,
            SPELL_MAGE_PYROBLAST,
            SPELL_MAGE_FIRESTARTER
        });
    }

    void HandleCritChance(Unit* victim, float& chance)
    {
        if (Aura* aura = GetCaster()->GetAura(SPELL_MAGE_FIRESTARTER))
            if (victim->GetHealthPct() >= aura->GetEffect(EFFECT_0)->GetBaseAmount())
                chance = 100.f;
    }

    void Register() override
    {
        OnCalcCritChance += SpellOnCalcCritChanceFn(spell_mage_firestarter::HandleCritChance);
    }
};

//235219 - Cold Snap
class spell_mage_cold_snap : public SpellScript
{
    PrepareSpellScript(spell_mage_cold_snap);

    void HandleOnHit(SpellEffIndex /*effIndex*/)
    {
        std::initializer_list<uint32> spells =
        {
            SPELL_MAGE_FROST_NOVA,
            SPELL_MAGE_CONE_OF_COLD,
            SPELL_MAGE_ICE_BARRIER,
            SPELL_MAGE_ICE_BLOCK
        };

        for (uint32 spellId : spells)
        {
            GetCaster()->GetSpellHistory()->ResetCooldown(spellId, true);

            if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId))
                GetCaster()->GetSpellHistory()->ResetCharges(spellInfo->ChargeCategoryId);
        }
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_mage_cold_snap::HandleOnHit, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// Ice Block - 45438
class spell_mage_ice_block : public AuraScript
{
    PrepareAuraScript(spell_mage_ice_block);

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_MAGE_HYPOTHERMIA, true);
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTarget()->HasAura(SPELL_MAGE_GLACIAL_INSULATION))
            GetTarget()->CastSpell(GetTarget(), SPELL_MAGE_ICE_BARRIER, true);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_mage_ice_block::OnApply, EFFECT_2, SPELL_AURA_SCHOOL_IMMUNITY, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectRemoveFn(spell_mage_ice_block::OnRemove, EFFECT_2, SPELL_AURA_SCHOOL_IMMUNITY, AURA_EFFECT_HANDLE_REAL);
    }
};

// Ice Barrier - 11426
class spell_mage_ice_barrier : public AuraScript
{
    PrepareAuraScript(spell_mage_ice_barrier);

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& canBeRecalculated)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        canBeRecalculated = false;
        int32 absorbamount = int32(10.0f * caster->SpellBaseHealingBonusDone(GetSpellInfo()->GetSchoolMask()));

        if (caster->HasAura(SPELL_MAGE_SHIELD_OF_ALODI))
        {
            if (Aura* shieldOfAlodiRank = caster->GetAura(SPELL_MAGE_SHIELD_OF_ALODI))
            {
                int32 pct = shieldOfAlodiRank->GetEffect(EFFECT_0)->GetAmount();
                AddPct(absorbamount, pct);
            }
        }

        amount += absorbamount;
    }

    void Absorb(AuraEffect* auraEffect, DamageInfo& dmgInfo, uint32& /*absorbAmount*/)
    {
        Unit* caster = auraEffect->GetCaster();
        Unit* target = dmgInfo.GetAttacker();
        if (!caster || !target)
            return;

        caster->CastSpell(target, SPELL_MAGE_CHILLED, true);
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_mage_ice_barrier::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
        OnEffectAbsorb += AuraEffectAbsorbFn(spell_mage_ice_barrier::Absorb, EFFECT_0);
    }
};

// Chilled - 205708 
class spell_mage_chilled : public AuraScript
{
    PrepareAuraScript(spell_mage_chilled);

    void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (caster->HasAura(SPELL_MAGE_BONE_CHILLING))
        {
            //@TODO REDUCE BONE CHILLING DAMAGE PER STACK TO 0.5% from 1%
            caster->CastSpell(caster, SPELL_MAGE_BONE_CHILLING_BUFF, true);
        }
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_mage_chilled::HandleApply, EFFECT_0, SPELL_AURA_MOD_DECREASE_SPEED, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
    }
};

// Ray of Frost - 205021
class spell_mage_ray_of_frost : public AuraScript
{
    PrepareAuraScript(spell_mage_ray_of_frost);

    void HandleApply(AuraEffect const* /*aurEffect*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* caster = GetCaster())
            if (!caster->HasAura(SPELL_MAGE_RAY_OF_FROST_BUFF))
                caster->CastSpell(caster, SPELL_MAGE_RAY_OF_FROST_BUFF, true);
    }

    void OnTick(AuraEffect const* /*auraEff*/)
    {
        if (Unit* caster = GetCaster())
        {
            if (AuraEffect* aurEff = GetAura()->GetEffect(EFFECT_1))
                aurEff->SetDamage(caster->SpellDamageBonusDone(GetTarget(), GetSpellInfo(), 0, DOT, aurEff->GetSpellEffectInfo(), GetStackAmount()) * aurEff->GetDonePct());

            caster->CastSpell(caster, SPELL_MAGE_RAY_OF_FROST_DAMAGE_INCREASE, true);
        }
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_mage_ray_of_frost::HandleApply, EFFECT_0, SPELL_AURA_MOD_DECREASE_SPEED, AURA_EFFECT_HANDLE_REAL);
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_mage_ray_of_frost::OnTick, EFFECT_1, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

// 208166
class spell_mage_ray_of_frost_buff : public AuraScript
{
    PrepareAuraScript(spell_mage_ray_of_frost_buff);

    void HandleApply(AuraEffect const* /*aurEffect*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->GetSpellHistory()->ResetCooldown(SPELL_MAGE_RAY_OF_FROST, true);
    }

    void HandleRemove(AuraEffect const* /*aurEffect*/, AuraEffectHandleModes /*mode*/)
    {
        if (SpellInfo const* rayOfFrostInfo = sSpellMgr->GetSpellInfo(SPELL_MAGE_RAY_OF_FROST))
            GetTarget()->GetSpellHistory()->StartCooldown(rayOfFrostInfo, 0, nullptr, false, true);

        if (GetTarget()->GetChannelSpellId() == SPELL_MAGE_RAY_OF_FROST)
            GetTarget()->FinishSpell(CURRENT_CHANNELED_SPELL);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_mage_ray_of_frost_buff::HandleApply, EFFECT_0, SPELL_AURA_ADD_PCT_MODIFIER, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectRemoveFn(spell_mage_ray_of_frost_buff::HandleRemove, EFFECT_0, SPELL_AURA_ADD_PCT_MODIFIER, AURA_EFFECT_HANDLE_REAL);
    }
};

// Cone of Cold - 120
class spell_mage_cone_of_cold : public SpellScript
{
    PrepareSpellScript(spell_mage_cone_of_cold);

    void HandleOnHit(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();
        if (!target || !caster)
            return;

        caster->CastSpell(target, SPELL_MAGE_CONE_OF_COLD_SLOW, true);

        if (caster->HasAura(SPELL_MAGE_BONE_CHILLING))
            caster->CastSpell(caster, SPELL_MAGE_BONE_CHILLING_BUFF, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_mage_cone_of_cold::HandleOnHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// Ice Lance - 30455
class spell_mage_ice_lance : public SpellScript
{
    PrepareSpellScript(spell_mage_ice_lance);

    void HandleOnHit(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();
        if (!caster && !target)
            return;

        caster->CastSpell(target, SPELL_MAGE_ICE_LANCE_TRIGGER, true);

        // Frost Bomb
        if (target->HasAura(SPELL_MAGE_FROST_BOMB_AURA) && (target->HasAuraState(AURA_STATE_FROZEN) || caster->HasAura(SPELL_MAGE_FINGERS_OF_FROST_AURA)))
            caster->CastSpell(target, SPELL_MAGE_FROST_BOMB_TRIGGERED, true);

        // Thermal Void
        if (caster->HasAura(SPELL_MAGE_THERMAL_VOID) && (target->HasAuraState(AURA_STATE_FROZEN) || caster->HasAura(SPELL_MAGE_FINGERS_OF_FROST_AURA)))
        {
            if (Aura* icyVeins = caster->GetAura(SPELL_MAGE_ICY_VEINS))
            {
                int32 increaseDuration = sSpellMgr->GetSpellInfo(SPELL_MAGE_THERMAL_VOID)->GetEffect(EFFECT_0)->BasePoints * IN_MILLISECONDS;
                int32 newDuration = (icyVeins->GetDuration() + increaseDuration);
                icyVeins->SetDuration(newDuration);
            }
        }

        if (Aura* fingersOfFrost = caster->GetAura(SPELL_MAGE_FINGERS_OF_FROST_AURA))
        {
            uint8 stack = fingersOfFrost->GetStackAmount();

            if (stack == 2)
                caster->RemoveAura(SPELL_MAGE_FINGERS_OF_FROST_VISUAL_UI);
            fingersOfFrost->ModStackAmount(-1);
        }
    }

    void HandleAfterHit()
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();
        if (!caster && !target)
            return;

        if (target->IsAlive() && !caster->HasSpell(SPELL_MAGE_GLACIAL_SPIKE))
        {
            caster->Variables.Set("IciclesTarget", target->GetGUID());
            caster->CastSpell(caster, SPELL_MAGE_ICICLE_PERIODIC_TRIGGER, true);
        }
    }

    void Register() override
    {
        AfterHit += SpellHitFn(spell_mage_ice_lance::HandleAfterHit);
        OnEffectHitTarget += SpellEffectFn(spell_mage_ice_lance::HandleOnHit, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// Flurry - 44614
class spell_mage_flurry : public SpellScript
{
    PrepareSpellScript(spell_mage_flurry);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();
        bool isImproved = false;
        if (!caster || !target)
            return;

        if (caster->HasAura(SPELL_MAGE_BRAIN_FREEZE_AURA))
        {
            caster->RemoveAura(SPELL_MAGE_BRAIN_FREEZE_AURA);
            if (caster->HasSpell(SPELL_MAGE_BRAIN_FREEZE_IMPROVED))
                isImproved = true;
        }

        ObjectGuid targetGuid = target->GetGUID();
        for (uint8 i = 1; i < GetEffectInfo(EFFECT_0)->BasePoints; ++i)
        {
            caster->GetScheduler().Schedule(Milliseconds(i * 250), [targetGuid, isImproved](TaskContext context)
            {
                if (Unit* caster = GetContextUnit())
                {
                    if (Unit* target = ObjectAccessor::GetUnit(*caster, targetGuid))
                    {
                        caster->CastSpell(target, SPELL_MAGE_FLURRY_VISUAL, false);

                        if (isImproved)
                            caster->CastSpell(target, SPELL_MAGE_FLURRY_CHILL_PROC, false);
                    }
                }
            });
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_mage_flurry::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// Jouster - 214626
class spell_mage_jouster : public AuraScript
{
    PrepareAuraScript(spell_mage_jouster);

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        bool _spellCanProc = (eventInfo.GetSpellInfo()->Id == SPELL_MAGE_ICE_LANCE);

        if (_spellCanProc)
            return true;
        return false;
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_mage_jouster::CheckProc);
    }
};

// Jouster Buff - 195391
class spell_mage_jouster_buff : public AuraScript
{
    PrepareAuraScript(spell_mage_jouster_buff);

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (Aura* jousterRank = caster->GetAura(SPELL_MAGE_JOUSTER))
        {
            amount = (jousterRank->GetEffect(EFFECT_0)->GetAmount());
        }
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_mage_jouster_buff::CalculateAmount, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN);
    }
};

// Chain Reaction - 195419
class spell_mage_chain_reaction : public AuraScript
{
    PrepareAuraScript(spell_mage_chain_reaction);

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        bool _spellCanProc = (eventInfo.GetSpellInfo()->Id == SPELL_MAGE_FROSTBOLT || eventInfo.GetSpellInfo()->Id == SPELL_MAGE_FROSTBOLT_TRIGGER);

        if (_spellCanProc)
            return true;

        return false;
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_mage_chain_reaction::CheckProc);
    }
};

// Frozen Veins - 195345
class spell_mage_frozen_veins : public AuraScript
{
    PrepareAuraScript(spell_mage_frozen_veins);

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        bool _spellCanProc = (eventInfo.GetSpellInfo()->Id == SPELL_MAGE_FROSTBOLT || eventInfo.GetSpellInfo()->Id == SPELL_MAGE_FROSTBOLT_TRIGGER);

        if (_spellCanProc)
            return true;

        return false;
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (caster->GetSpellHistory()->HasCooldown(SPELL_MAGE_ICY_VEINS))
            caster->GetSpellHistory()->ModifyCooldown(SPELL_MAGE_ICY_VEINS, aurEff->GetAmount());
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_mage_frozen_veins::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
        DoCheckProc += AuraCheckProcFn(spell_mage_frozen_veins::CheckProc);
    }
};

// Chilled to the Core - 195448
class spell_mage_chilled_to_the_core : public AuraScript
{
    PrepareAuraScript(spell_mage_chilled_to_the_core);

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        bool _spellCanProc = (eventInfo.GetSpellInfo()->Id == SPELL_MAGE_ICY_VEINS);

        if (_spellCanProc)
            return true;

        return false;
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_mage_chilled_to_the_core::CheckProc);
    }
};

// Frostbolt - 228597
class spell_mage_frostbolt : public SpellScript
{
    PrepareSpellScript(spell_mage_frostbolt);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();
        if (!caster || !target)
            return;

        caster->CastSpell(target, SPELL_MAGE_CHILLED, true);

        // Brain Freeze
        if (caster->HasSpell(SPELL_MAGE_BRAIN_FREEZE))
        {
            int32 clarityOfThoughtChance = 0;
            float brainFreezeChance = sSpellMgr->GetSpellInfo(SPELL_MAGE_BRAIN_FREEZE)->GetEffect(EFFECT_0)->CalcValue(caster);

            if (Aura* clarityOfThought = caster->GetAura(SPELL_MAGE_GLARITY_OF_THOUGHT))
            {
                clarityOfThoughtChance = (clarityOfThought->GetEffect(EFFECT_0)->GetAmount());
            }

            brainFreezeChance += clarityOfThoughtChance;

            if (roll_chance_i(brainFreezeChance))
                caster->CastSpell(caster, SPELL_MAGE_BRAIN_FREEZE_AURA, true);
        }

        // Fingers of Frost
        if (caster->HasSpell(SPELL_MAGE_FINGERS_OF_FROST))
        {
            float fingersFrostChance = sSpellMgr->GetSpellInfo(SPELL_MAGE_FINGERS_OF_FROST)->GetEffect(EFFECT_0)->CalcValue(caster);

            if (caster->HasAura(SPELL_MAGE_FROZEN_TOUCH))
            {
                if (Aura* frozenTouchPct = caster->GetAura(SPELL_MAGE_FROZEN_TOUCH))
                {
                    int32 pct = frozenTouchPct->GetEffect(EFFECT_0)->GetAmount();
                    AddPct(fingersFrostChance, pct);
                }
            }

            if (roll_chance_f(fingersFrostChance))
            {
                if (caster->HasAura(SPELL_MAGE_FINGERS_OF_FROST_AURA))
                    caster->CastSpell(caster, SPELL_MAGE_FINGERS_OF_FROST_VISUAL_UI, true);
                caster->CastSpell(caster, SPELL_MAGE_FINGERS_OF_FROST_AURA, true);
            }
        }

        Unit* pet = caster->GetGuardianPet();
        if (!pet)
            return;

        // Water Jet
        if (target->HasAura(SPELL_MAGE_WATER_JET, pet->GetGUID()))
        {
            if (caster->HasAura(SPELL_MAGE_FINGERS_OF_FROST_AURA))
                caster->CastSpell(caster, SPELL_MAGE_FINGERS_OF_FROST_VISUAL_UI, true);
            caster->CastSpell(caster, SPELL_MAGE_FINGERS_OF_FROST_AURA, true);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_mage_frostbolt::HandleDummy, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// Frost Bomb Damage - 113092 
class spell_mage_frost_bomb_damage : public SpellScript
{
    PrepareSpellScript(spell_mage_frost_bomb_damage);

    void HandleDamage(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();
        Unit* explunit = GetExplTargetUnit();
        if (!caster || !target || !explunit)
            return;

        float mplier = 1.15128f;

        if (target == explunit)
            mplier = 1.84275f;

        int32 sp = caster->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_SPELL);
        int32 dmg = (sp * mplier);

        SetHitDamage(dmg);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_mage_frost_bomb_damage::HandleDamage, EFFECT_1, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// Ice Nova | Supernova - 157997 | 157980
class spell_mage_nova_talent : public SpellScript
{
    PrepareSpellScript(spell_mage_nova_talent);

    ObjectGuid PlayerGUID;

    void HandleOnCast()
    {
        if (GetExplTargetUnit())
            PlayerGUID = GetExplTargetUnit()->GetGUID();
    }

    void HandleDamage(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();
        if (!target || !caster)
            return;

        if (target->GetGUID() == PlayerGUID && !target->IsFriendlyTo(caster))
        {
            int32 dmg = (GetHitDamage() * 2);
            SetHitDamage(dmg);
        }
    }

    void Register() override
    {
        OnCast += SpellCastFn(spell_mage_nova_talent::HandleOnCast);
        OnEffectHitTarget += SpellEffectFn(spell_mage_nova_talent::HandleDamage, EFFECT_1, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// Unstable Magic - 157976
// Called by Arcane Blast - 30451, Fireball - 133, Frostbolt - 228597
class spell_mage_unstable_magic : public SpellScript
{
    PrepareSpellScript(spell_mage_unstable_magic);

    void HandleDamage(SpellEffIndex)
    {
        if (Player* player = GetCaster()->ToPlayer())
        {
            if (Aura* unstableMagic = player->GetAura(SPELL_MAGE_UNSTABLE_MAGIC))
            {
                int32 chance = 0;
                uint32 spec = player->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID);
                switch (spec)
                {
                    case TALENT_SPEC_MAGE_ARCANE:
                        chance = unstableMagic->GetEffect(EFFECT_0) ? unstableMagic->GetEffect(EFFECT_0)->GetAmount() : 0;
                        break;
                    case TALENT_SPEC_MAGE_FROST:
                        chance = unstableMagic->GetEffect(EFFECT_1) ? unstableMagic->GetEffect(EFFECT_1)->GetAmount() : 0;
                        break;
                    case TALENT_SPEC_MAGE_FIRE:
                        chance = unstableMagic->GetEffect(EFFECT_2) ? unstableMagic->GetEffect(EFFECT_2)->GetAmount() : 0;
                        break;
                    default:
                    break;
                }

                if (!roll_chance_i(chance))
                    return;

                if (Unit* target = GetHitUnit())
                {
                    int32 pct = unstableMagic->GetEffect(EFFECT_3) ? unstableMagic->GetEffect(EFFECT_3)->GetAmount() : 0;
                    int32 basePoints = CalculatePct(GetHitDamage(), pct);
                    uint32 spellID = GetSpellInfo()->Id;
                    switch (spellID)
                    {
                        case SPELL_MAGE_ARCANE_BLAST:
                            player->CastCustomSpell(target, SPELL_MAGE_UNSTABLE_MAGIC_DAMAGE_ARCANE, &basePoints, nullptr, nullptr, true);
                            break;
                        case SPELL_MAGE_FROSTBOLT_TRIGGER:
                            player->CastCustomSpell(target, SPELL_MAGE_UNSTABLE_MAGIC_DAMAGE_FROST, &basePoints, nullptr, nullptr, true);
                            break;
                        case SPELL_MAGE_FIREBALL:
                            player->CastCustomSpell(target, SPELL_MAGE_UNSTABLE_MAGIC_DAMAGE_FIRE, &basePoints, nullptr, nullptr, true);
                            break;
                        default:
                        break;
                    }
                }
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_mage_unstable_magic::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// Blizzard damge - 190357
class spell_mage_blizzard : public SpellScript
{
    PrepareSpellScript(spell_mage_blizzard);

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();
        if (!caster || !target)
            return;

        caster->CastSpell(target, SPELL_MAGE_CHILLED, true);

        if (caster->HasSpell(SPELL_MAGE_BLIZZARD_RANK_2))
        {
            if (caster->GetSpellHistory()->HasCooldown(SPELL_MAGE_FROZEN_ORB))
                caster->GetSpellHistory()->ModifyCooldown(SPELL_MAGE_FROZEN_ORB, -0.5 * IN_MILLISECONDS);
        }

        // Fingers of Frost
        if (caster->HasSpell(SPELL_MAGE_FINGERS_OF_FROST))
        {
            float fingersFrostChance = sSpellMgr->GetSpellInfo(SPELL_MAGE_FINGERS_OF_FROST)->GetEffect(EFFECT_0)->CalcValue(caster);

            if (caster->HasAura(SPELL_MAGE_FROZEN_TOUCH))
            {
                if (Aura* frozenTouchPct = caster->GetAura(SPELL_MAGE_FROZEN_TOUCH))
                {
                    int32 pct = frozenTouchPct->GetEffect(EFFECT_0)->GetAmount();
                    AddPct(fingersFrostChance, pct);
                }
            }

            if (roll_chance_f(fingersFrostChance))
            {
                if (caster->HasAura(SPELL_MAGE_FINGERS_OF_FROST_AURA))
                    caster->CastSpell(caster, SPELL_MAGE_FINGERS_OF_FROST_VISUAL_UI, true);
                caster->CastSpell(caster, SPELL_MAGE_FINGERS_OF_FROST_AURA, true);
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_mage_blizzard::HandleHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// Frozen Orb (damage) - 84721
class spell_mage_frozen_orb : public SpellScript
{
    PrepareSpellScript(spell_mage_frozen_orb);

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();
        if (!caster || !target)
            return;

        caster->CastSpell(target, SPELL_MAGE_CHILLED, true);

        // Fingers of Frost
        if (caster->HasSpell(SPELL_MAGE_FINGERS_OF_FROST))
        {
            float fingersFrostChance = sSpellMgr->GetSpellInfo(SPELL_MAGE_FINGERS_OF_FROST)->GetEffect(EFFECT_0)->CalcValue(caster);

            if (caster->HasAura(SPELL_MAGE_FROZEN_TOUCH))
            {
                if (Aura* frozenTouchPct = caster->GetAura(SPELL_MAGE_FROZEN_TOUCH))
                {
                    int32 pct = frozenTouchPct->GetEffect(EFFECT_0)->GetAmount();
                    AddPct(fingersFrostChance, pct);
                }
            }

            if (roll_chance_f(fingersFrostChance))
            {
                if (caster->HasAura(SPELL_MAGE_FINGERS_OF_FROST_AURA))
                    caster->CastSpell(caster, SPELL_MAGE_FINGERS_OF_FROST_VISUAL_UI, true);
                caster->CastSpell(caster, SPELL_MAGE_FINGERS_OF_FROST_AURA, true);
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_mage_frozen_orb::HandleHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

//7.3.2.25549 END

// Combustion - 190319
class spell_mage_combustion : public SpellScriptLoader
{
public:
    spell_mage_combustion() : SpellScriptLoader("spell_mage_combustion") {}

    class spell_mage_combustion_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_mage_combustion_AuraScript);

        void CalcAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (!caster->ToPlayer())
                return;

            int32 crit = caster->GetUInt32Value(ACTIVE_PLAYER_FIELD_COMBAT_RATING + CR_CRIT_SPELL);
            amount += crit;
        }

        void HandleRemove(AuraEffect const* /*aurEffect*/, AuraEffectHandleModes /*mode*/)
        {
            GetCaster()->RemoveAurasDueToSpell(SPELL_INFERNO);
        }

        void Register() override
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_mage_combustion_AuraScript::CalcAmount, EFFECT_1, SPELL_AURA_MOD_RATING);
            OnEffectRemove += AuraEffectRemoveFn(spell_mage_combustion_AuraScript::HandleRemove, EFFECT_1, SPELL_AURA_MOD_RATING, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_mage_combustion_AuraScript();
    }
};

// Incanter's Flow - 1463
class spell_mage_incanters_flow : public SpellScriptLoader
{
public:
    spell_mage_incanters_flow() : SpellScriptLoader("spell_mage_incanters_flow") { }

    class spell_mage_incanters_flow_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_mage_incanters_flow_AuraScript);

        bool m_Up = true;
        bool m_Changed = false;

        void OnTick(AuraEffect const* /*auraEff*/)
        {
            if (Unit* caster = GetCaster())
            {
                /// Break the cycle if caster is out of combat
                if (!caster->IsInCombat())
                    return;

                if (caster->HasAura(SPELL_MAGE_INCANTERS_FLOW_BUFF))
                {
                    if (Aura* incantersFlow = caster->GetAura(SPELL_MAGE_INCANTERS_FLOW_BUFF))
                    {
                        m_Changed = false;

                        if (incantersFlow->GetStackAmount() == 5 && m_Up)
                        {
                            m_Up = false;
                            m_Changed = true;
                        }
                        else if (incantersFlow->GetStackAmount() == 1 && !m_Up)
                        {
                            m_Up = true;
                            m_Changed = true;
                        }

                        if (!m_Changed)
                            incantersFlow->ModStackAmount(m_Up ? 1 : -1);
                    }
                }
                else if (caster->IsInCombat())
                {
                    caster->CastSpell(caster, SPELL_MAGE_INCANTERS_FLOW_BUFF, true);
                    m_Up = true;
                    m_Changed = false;
                }
            }
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_mage_incanters_flow_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_mage_incanters_flow_AuraScript();
    }
};

// Time Warp - 80353
class spell_mage_time_warp : public SpellScriptLoader
{
    public:
        spell_mage_time_warp() : SpellScriptLoader("spell_mage_time_warp") { }

        class spell_mage_time_warp_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mage_time_warp_SpellScript);

            std::vector<uint32> spellIds
            {
                SPELL_MAGE_TEMPORAL_DISPLACEMENT,
                SPELL_HUNTER_INSANITY,
                SPELL_SHAMAN_EXHAUSTION,
                SPELL_SHAMAN_SATED,
                SPELL_PET_NETHERWINDS_FATIGUED
            };

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                for (uint32 spell : spellIds)
                {
                    if (!sSpellMgr->GetSpellInfo(spell))
                        return false;
                }
                return true;
            }

            SpellCastResult CheckCast()
            {
                Player* player = GetCaster()->ToPlayer();
                if (!player)
                    return SPELL_FAILED_DONT_REPORT;
                Group* grp = player->GetGroup();
                if (!grp)
                {
                    return HasSated(player) ? SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW : SPELL_CAST_OK;
                }
                for (GroupReference* itr = grp->GetFirstMember(); itr != NULL; itr = itr->next())
                {
                    Player* member = itr->GetSource();

                    if (!member || !member->GetSession())
                        continue;

                    if (!HasSated(member))
                    {
                        return SPELL_CAST_OK; // we have at least one valid target
                    }
                }
                return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;
            }

            bool HasSated(Unit* target)
            {
                for (uint32 spell : spellIds)
                {
                    if (target->HasAura(spell))
                        return true;
                }
                return false;
            }

            void RemoveInvalidTargets(std::list<WorldObject*>& targets)
            {
                for (uint32 spell : spellIds)
                {
                    targets.remove_if(Trinity::UnitAuraCheck(true, spell));
                }
            }

            void ApplyDebuff()
            {
                if (Unit* target = GetHitUnit())
                    target->CastSpell(target, SPELL_MAGE_TEMPORAL_DISPLACEMENT, true);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_mage_time_warp_SpellScript::RemoveInvalidTargets, EFFECT_ALL, TARGET_UNIT_CASTER_AREA_RAID);
                AfterHit += SpellHitFn(spell_mage_time_warp_SpellScript::ApplyDebuff);
                OnCheckCast += SpellCheckCastFn(spell_mage_time_warp_SpellScript::CheckCast);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mage_time_warp_SpellScript();
        }
};

// Fire mage (passive) - 137019
class spell_mage_fire_mage_passive : public SpellScriptLoader
{
public:
    spell_mage_fire_mage_passive() : SpellScriptLoader("spell_mage_fire_mage_passive") {}

    class spell_mage_fire_mage_passive_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_mage_fire_mage_passive_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_MAGE_FIRE_MAGE_PASSIVE) ||
                !sSpellMgr->GetSpellInfo(SPELL_MAGE_FIRE_BLAST))
                return false;
            return true;
        }

    public:

        spell_mage_fire_mage_passive_AuraScript() {}

    private:

        SpellModifier* mod = nullptr;

        void HandleApply(AuraEffect const* aurEffect, AuraEffectHandleModes /*mode*/)
        {
            Player* player = GetCaster()->ToPlayer();
            if (!player)
                return;

            mod = new SpellModifier(aurEffect->GetBase());
            mod->op = SPELLMOD_CRITICAL_CHANCE;
            mod->type = SPELLMOD_FLAT;
            mod->spellId = SPELL_MAGE_FIRE_MAGE_PASSIVE;
            mod->value = 200;
            mod->mask[0] = 0x2;

            player->AddSpellMod(mod, true);
        }

        void HandleRemove(AuraEffect const* /*aurEffect*/, AuraEffectHandleModes /*mode*/)
        {
            Player* player = GetCaster()->ToPlayer();
            if (!player)
                return;

            if (mod)
                player->AddSpellMod(mod, false);
        }

        void Register() override
        {
            OnEffectApply += AuraEffectApplyFn(spell_mage_fire_mage_passive_AuraScript::HandleApply, EFFECT_4, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(spell_mage_fire_mage_passive_AuraScript::HandleRemove, EFFECT_4, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_mage_fire_mage_passive_AuraScript();
    }
};

// Ice Floes - 108839
class spell_mage_ice_floes : public AuraScript
{
    PrepareAuraScript(spell_mage_ice_floes);

    void HandleAfterProc(ProcEventInfo& eventInfo)
    {
        if (eventInfo.GetSpellInfo() && eventInfo.GetSpellInfo()->CalcCastTime() && eventInfo.GetSpellInfo()->Id != 2948) // Exclude Scorch
            if (Unit* caster = GetCaster())
                if (Aura* iceFloes = caster->GetAura(SPELL_MAGE_ICE_FLOES))
                    iceFloes->ModStackAmount(-1);
    }

    void Register() override
    {
        AfterProc += AuraProcFn(spell_mage_ice_floes::HandleAfterProc);
    }
};

// Flame On - 205029
class spell_mage_fire_on : public SpellScriptLoader
{
public:
    spell_mage_fire_on() : SpellScriptLoader("spell_mage_fire_on") { }

    class spell_mage_fire_on_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_mage_fire_on_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_MAGE_FIRE_ON) ||
                !sSpellMgr->GetSpellInfo(SPELL_MAGE_FIRE_BLAST))
                return false;
            return true;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            if (!caster || !target)
                return;

            caster->ToPlayer()->GetSpellHistory()->ResetCharges(sSpellMgr->GetSpellInfo(SPELL_MAGE_FIRE_BLAST)->ChargeCategoryId);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_mage_fire_on_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_mage_fire_on_SpellScript();
    }
};

// Mirror Image - 55342
class spell_mage_mirror_image_summon : public SpellScriptLoader
{
public:
    spell_mage_mirror_image_summon() : SpellScriptLoader("spell_mage_mirror_image_summon") { }

    class spell_mage_mirror_image_summon_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_mage_mirror_image_summon_SpellScript);

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
            {
                caster->CastSpell(caster, SPELL_MAGE_MIRROR_IMAGE_LEFT, true);
                caster->CastSpell(caster, SPELL_MAGE_MIRROR_IMAGE_FRONT, true);
                caster->CastSpell(caster, SPELL_MAGE_MIRROR_IMAGE_RIGHT, true);
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_mage_mirror_image_summon_SpellScript::HandleDummy, EFFECT_1, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_mage_mirror_image_summon_SpellScript();
    }
};

// Cauterize - 86949
class spell_mage_cauterize : public SpellScriptLoader
{
public:
    spell_mage_cauterize() : SpellScriptLoader("spell_mage_cauterize") { }

    class spell_mage_cauterize_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_mage_cauterize_AuraScript);

        int32 healtPct;

        bool Load() override
        {
            healtPct = GetSpellInfo()->GetEffect(EFFECT_1)->CalcValue(GetCaster());
            return GetUnitOwner()->GetTypeId() == TYPEID_PLAYER;
        }

        void CalculateAmount(AuraEffect const* /*auraEffect*/, int32& amount, bool& /*canBeRecalculated*/)
        {
            amount = -1;
        }

        void Absorb(AuraEffect* /*auraEffect*/, DamageInfo& dmgInfo, uint32& absorbAmount)
        {
            Unit* target = GetTarget();

            if (dmgInfo.GetDamage() < target->GetHealth())
                return;

            if (target->ToPlayer()->GetSpellHistory()->HasCooldown(SPELL_MAGE_CAUTERIZE))
                return;

            int bp1 = target->CountPctFromMaxHealth(healtPct);
            target->CastCustomSpell(target, SPELL_MAGE_CAUTERIZE, NULL, &bp1, NULL, true);
            target->CastSpell(target, GetSpellInfo()->GetEffect(EFFECT_2)->TriggerSpell, true);
            target->GetSpellHistory()->AddCooldown(SPELL_MAGE_CAUTERIZE, 0, std::chrono::minutes(2));

            absorbAmount = dmgInfo.GetDamage();
        }

        void Register() override
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_mage_cauterize_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
            OnEffectAbsorb += AuraEffectAbsorbFn(spell_mage_cauterize_AuraScript::Absorb, EFFECT_0);
        }
    };

    class spell_mage_cauterize_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_mage_cauterize_SpellScript);

        void PreventTrigger(SpellEffIndex effIndex)
        {
            PreventHitEffect(effIndex);
        }

        void Register() override
        {
            OnEffectHit += SpellEffectFn(spell_mage_cauterize_SpellScript::PreventTrigger, EFFECT_2, SPELL_EFFECT_TRIGGER_SPELL);
            OnEffectHitTarget += SpellEffectFn(spell_mage_cauterize_SpellScript::PreventTrigger, EFFECT_2, SPELL_EFFECT_TRIGGER_SPELL);
            OnEffectLaunch += SpellEffectFn(spell_mage_cauterize_SpellScript::PreventTrigger, EFFECT_2, SPELL_EFFECT_TRIGGER_SPELL);
            OnEffectLaunchTarget += SpellEffectFn(spell_mage_cauterize_SpellScript::PreventTrigger, EFFECT_2, SPELL_EFFECT_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_mage_cauterize_AuraScript();
    }

    SpellScript* GetSpellScript() const override
    {
        return new spell_mage_cauterize_SpellScript();
    }
};

// Ring of Frost - 136511
class spell_mage_ring_of_frost : public AuraScript
{
    PrepareAuraScript(spell_mage_ring_of_frost);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGE_RING_OF_FROST, SPELL_MAGE_RING_OF_FROST_FREEZE });
    }

    void OnTick(AuraEffect const* /*aurEff*/)
    {
        if (Unit* caster = GetCaster())
            if (Unit* frozenRing = caster->GetSummonedCreatureByEntry(44199))
                caster->CastSpell(frozenRing->GetPosition(), SPELL_MAGE_RING_OF_FROST_FREEZE, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_mage_ring_of_frost::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

// Ring of Frost - 82691
class spell_mage_ring_of_frost_stun : public SpellScriptLoader
{
public:
    spell_mage_ring_of_frost_stun() : SpellScriptLoader("spell_mage_ring_of_frost_stun") { }

    class spell_mage_ring_of_frost_stun_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_mage_ring_of_frost_stun_AuraScript);

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetTarget();
            if (!target || !caster)
                return;

            caster->CastSpell(target, SPELL_MAGE_RING_OF_FROST_IMMUNE, true);
        }

        void Register() override
        {
            OnEffectRemove += AuraEffectRemoveFn(spell_mage_ring_of_frost_stun_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_mage_ring_of_frost_stun_AuraScript();
    }

    class spell_mage_ring_of_frost_stun_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_mage_ring_of_frost_stun_SpellScript);

        void CheckTargets(std::list<WorldObject*>& targets)
        {
            // following the visual's size
            float radiusMin = 5.0f;
            float radiusMax = 6.5f;
            WorldLocation const* center = GetExplTargetDest();
            if (!center)
            {
                // should never happen
                targets.clear();
                return;
            }

            // prevent reapply at every 100ms or if it was just removed and immune for 2.5secs, also check inner/outer circle distance
            const SpellInfo* spell = GetSpellInfo();
            targets.remove_if([spell, radiusMin, radiusMax, center](WorldObject* obj) -> bool
            {
                if (Unit* unit = obj->ToUnit())
                {
                    if (unit->HasAura(spell->Id) || unit->HasAura(SPELL_MAGE_RING_OF_FROST_IMMUNE))
                        return true;
                    if (unit->GetPosition().GetExactDist(center->GetPosition()) >= radiusMin && unit->GetPosition().GetExactDist(center->GetPosition()) <= radiusMax)
                        return false;
                }
                return true;
            });
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_mage_ring_of_frost_stun_SpellScript::CheckTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_mage_ring_of_frost_stun_SpellScript();
    }
};

// Freeze (Water Elemental's) - 33395
class spell_mage_pet_freeze : public AuraScript
{
    PrepareAuraScript(spell_mage_pet_freeze);

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* caster = GetCaster())
        {
            if (caster->GetOwner())
            {
                if (Player* player = caster->GetOwner()->ToPlayer())
                {
                    if (player->HasAura(SPELL_MAGE_FINGERS_OF_FROST_AURA))
                        player->CastSpell(player, SPELL_MAGE_FINGERS_OF_FROST_VISUAL_UI, true);
                    player->CastSpell(player, SPELL_MAGE_FINGERS_OF_FROST_AURA, true);
                }
            }
        }
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_mage_pet_freeze::OnApply, EFFECT_0, SPELL_AURA_MOD_ROOT_2, AURA_EFFECT_HANDLE_REAL);
    }
};

// Conjure Refreshment - 190336
class spell_mage_conjure_refreshment : public SpellScriptLoader
{
public:
    spell_mage_conjure_refreshment() : SpellScriptLoader("spell_mage_conjure_refreshment") { }

    class spell_mage_conjure_refreshment_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_mage_conjure_refreshment_SpellScript);

        void HandleOnHit()
        {
            if (Player* player = GetCaster()->ToPlayer())
            {
                Group* group = player->GetGroup();

                if (group)
                    player->CastSpell(player, SPELL_MAGE_CONJURE_REFRESHMENT_GROUP, true);
                else
                    player->CastSpell(player, SPELL_MAGE_CONJURE_REFRESHMENT_SOLO, true);
            }
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_mage_conjure_refreshment_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_mage_conjure_refreshment_SpellScript();
    }
};


// Meteor - 177345
// AreaTriggerID - 3467
class at_mage_meteor_timer : public AreaTriggerEntityScript
{
public:
    at_mage_meteor_timer() : AreaTriggerEntityScript("at_mage_meteor_timer") {}

    struct at_mage_meteor_timerAI : AreaTriggerAI
    {
        at_mage_meteor_timerAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        void OnCreate() override
        {
            Unit* caster = at->GetCaster();
            if (!caster)
                return;

            if (TempSummon* tempSumm = caster->SummonCreature(WORLD_TRIGGER, at->GetPosition(), TEMPSUMMON_TIMED_DESPAWN, 5 * IN_MILLISECONDS))
            {
                tempSumm->setFaction(caster->getFaction());
                tempSumm->SetGuidValue(UNIT_FIELD_SUMMONEDBY, caster->GetGUID());
                PhasingHandler::InheritPhaseShift(tempSumm, caster);
                caster->CastSpell(tempSumm, SPELL_MAGE_METEOR_VISUAL, true);
            }

        }

        void OnRemove() override
        {
            Unit* caster = at->GetCaster();
            if (!caster)
                return;

            if (TempSummon* tempSumm = caster->SummonCreature(WORLD_TRIGGER, at->GetPosition(), TEMPSUMMON_TIMED_DESPAWN, 5 * IN_MILLISECONDS))
            {
                tempSumm->setFaction(caster->getFaction());
                tempSumm->SetGuidValue(UNIT_FIELD_SUMMONEDBY, caster->GetGUID());
                PhasingHandler::InheritPhaseShift(tempSumm, caster);
                caster->CastSpell(tempSumm, SPELL_MAGE_METEOR_DAMAGE, true);
            }
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new at_mage_meteor_timerAI(areatrigger);
    }
};

// Meteor Burn - 175396
// AreaTriggerID - 1712
class at_mage_meteor_burn : public AreaTriggerEntityScript
{
public:
    at_mage_meteor_burn() : AreaTriggerEntityScript("at_mage_meteor_burn") { }

    struct at_mage_meteor_burnAI : AreaTriggerAI
    {
        at_mage_meteor_burnAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        void OnUnitEnter(Unit* unit) override
        {
            Unit* caster = at->GetCaster();

            if (!caster || !unit)
                return;

            if (!caster->ToPlayer())
                return;

            if (caster->IsValidAttackTarget(unit))
                caster->CastSpell(unit, SPELL_MAGE_METEOR_BURN, true);
        }

        void OnUnitExit(Unit* unit) override
        {
            Unit* caster = at->GetCaster();

            if (!caster || !unit)
                return;

            if (!caster->ToPlayer())
                return;

            if (Aura* meteor = unit->GetAura(SPELL_MAGE_METEOR_BURN, caster->GetGUID()))
                meteor->SetDuration(0);
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new at_mage_meteor_burnAI(areatrigger);
    }
};

// Blizzard - 190356
// AreaTriggerID - 4658
class at_mage_blizzard : public AreaTriggerEntityScript
{
public:
    at_mage_blizzard() : AreaTriggerEntityScript("at_mage_blizzard") { }

    struct at_mage_blizzardAI : AreaTriggerAI
    {
        at_mage_blizzardAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger)
        {
            timeInterval = 1000;
        }

        int32 timeInterval;

        enum UsingSpells
        {
            SPELL_MAGE_BLIZZARD_DAMAGE = 190357
        };

        void OnUpdate(uint32 diff) override
        {
            Unit* caster = at->GetCaster();

            if (!caster)
                return;

            if (!caster->ToPlayer())
                return;

            timeInterval += diff;
            if (timeInterval < 1000)
                return;

            if (Creature* tempSumm = caster->SummonCreature(WORLD_TRIGGER, at->GetPosition(), TEMPSUMMON_TIMED_DESPAWN, 200))
            {
                tempSumm->setFaction(caster->getFaction());
                tempSumm->SetGuidValue(UNIT_FIELD_SUMMONEDBY, caster->GetGUID());
                PhasingHandler::InheritPhaseShift(tempSumm, caster);
                caster->CastSpell(tempSumm, SPELL_MAGE_BLIZZARD_DAMAGE, true);
            }

            timeInterval -= 1000;
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new at_mage_blizzardAI(areatrigger);
    }
};

// Rune of Power - 116011
// AreaTriggerID - 2947
struct at_mage_rune_of_power : AreaTriggerAI
{
    at_mage_rune_of_power(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    enum UsingSpells
    {
        SPELL_MAGE_RUNE_OF_POWER_AURA = 116014
    };

    void OnCreate() override
    {
        at->SetUInt32Value(AREATRIGGER_SPELL_X_SPELL_VISUAL_ID, 25943);
    }

    void OnUnitEnter(Unit* unit) override
    {
        if (Unit* caster = at->GetCaster())
            if (unit->GetGUID() == caster->GetGUID())
                caster->CastSpell(unit, SPELL_MAGE_RUNE_OF_POWER_AURA, true);
    }

    void OnUnitExit(Unit* unit) override
    {
        if (unit->HasAura(SPELL_MAGE_RUNE_OF_POWER_AURA))
            unit->RemoveAurasDueToSpell(SPELL_MAGE_RUNE_OF_POWER_AURA);
    }
};

// Frozen Orb - 84714
// AreaTriggerID - 8661
struct at_mage_frozen_orb : AreaTriggerAI
{
    at_mage_frozen_orb(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger)
    {
        damageInterval = 500;
    }

    uint32 damageInterval;
    bool procDone = false;

    void OnInitialize() override
    {
        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        Position pos = caster->GetPosition();

        at->MovePositionToFirstCollision(pos, 40.0f, 0.0f);
        at->SetDestination(pos, 4000);
    }

    void OnCreate() override
    {
        at->SetUInt32Value(AREATRIGGER_SPELL_X_SPELL_VISUAL_ID, 40291);
    }

    void OnUpdate(uint32 diff) override
    {
        Unit* caster = at->GetCaster();
        if (!caster || !caster->IsPlayer())
            return;

        if (damageInterval <= diff)
        {
            if (!procDone)
            {
                for (ObjectGuid guid : at->GetInsideUnits())
                {
                    if (Unit* unit = ObjectAccessor::GetUnit(*caster, guid))
                    {
                        if (caster->IsValidAttackTarget(unit))
                        {
                            if (caster->HasAura(SPELL_MAGE_FINGERS_OF_FROST_AURA))
                                caster->CastSpell(caster, SPELL_MAGE_FINGERS_OF_FROST_VISUAL_UI, true);

                            caster->CastSpell(caster, SPELL_MAGE_FINGERS_OF_FROST_AURA, true);

                            at->UpdateTimeToTarget(8000);
                            procDone = true;
                            break;
                        }
                    }
                }
            }

            caster->CastSpell(at->GetPosition(), SPELL_MAGE_FROZEN_ORB_DAMAGE, true);
            damageInterval = 500;
        }
        else
            damageInterval -= diff;
    }
};

// Arcane Orb - 153626
// AreaTriggerID - 1612
struct at_mage_arcane_orb : AreaTriggerAI
{
    at_mage_arcane_orb(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (Unit* caster = at->GetCaster())
            if (caster->IsValidAttackTarget(unit))
                caster->CastSpell(unit, SPELL_MAGE_ARCANE_ORB_DAMAGE, true);
    }
};

// 31216 - Mirror Image
class npc_mirror_image : public CreatureScript
{
public:
    npc_mirror_image() : CreatureScript("npc_mirror_image") { }

    enum eSpells
    {
        SPELL_MAGE_FROSTBOLT        = 59638,
        SPELL_MAGE_FIREBALL         = 133,
        SPELL_MAGE_ARCANE_BLAST     = 30451,
        SPELL_MAGE_GLYPH            = 63093,
        SPELL_INITIALIZE_IMAGES     = 102284,
        SPELL_CLONE_CASTER          = 60352,
        SPELL_INHERIT_MASTER_THREAT = 58838
    };

    struct npc_mirror_imageAI : CasterAI
    {
        npc_mirror_imageAI(Creature* creature) : CasterAI(creature) { }

        void IsSummonedBy(Unit* owner) override
        {
            if (!owner || !owner->IsPlayer())
                return;

            if (!me->HasUnitState(UnitState::UNIT_STATE_FOLLOW))
            {
                me->GetMotionMaster()->Clear(false);
                me->GetMotionMaster()->MoveFollow(owner, PET_FOLLOW_DIST, me->GetFollowAngle(), MovementSlot::MOTION_SLOT_ACTIVE);
            }

            me->SetMaxPower(me->GetPowerType(), owner->GetMaxPower(me->GetPowerType()));
            me->SetFullPower(me->GetPowerType());
            me->SetMaxHealth(owner->GetMaxHealth());
            me->SetHealth(owner->GetHealth());
            me->SetReactState(ReactStates::REACT_DEFENSIVE);

            me->CastSpell(owner, SPELL_INHERIT_MASTER_THREAT, true);

            // here mirror image casts on summoner spell (not present in client dbc) 49866
            // here should be auras (not present in client dbc): 35657, 35658, 35659, 35660 selfcasted by mirror images (stats related?)

            for (uint32 attackType = 0; attackType < WeaponAttackType::MAX_ATTACK; ++attackType)
            {
                WeaponAttackType attackTypeEnum = static_cast<WeaponAttackType>(attackType);
                me->SetBaseWeaponDamage(attackTypeEnum, WeaponDamageRange::MAXDAMAGE, owner->GetWeaponDamageRange(attackTypeEnum, WeaponDamageRange::MAXDAMAGE));
                me->SetBaseWeaponDamage(attackTypeEnum, WeaponDamageRange::MINDAMAGE, owner->GetWeaponDamageRange(attackTypeEnum, WeaponDamageRange::MINDAMAGE));
            }

            me->UpdateAttackPowerAndDamage();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            if (!me->GetOwner())
                return;

            Player* owner = me->GetOwner()->ToPlayer();
            if (!owner)
                return;

            eSpells spellId = eSpells::SPELL_MAGE_FROSTBOLT;
            /*if (owner->HasAura(SPELL_MAGE_GLYPH))
            {*/
            switch (owner->GetSpecializationId())
            {
            case TALENT_SPEC_MAGE_ARCANE:   spellId = eSpells::SPELL_MAGE_ARCANE_BLAST; break;
            case TALENT_SPEC_MAGE_FIRE:     spellId = eSpells::SPELL_MAGE_FIREBALL;     break;
            default: break;
            }
            //}

            events.ScheduleEvent(spellId, 0); ///< Schedule cast
            me->GetMotionMaster()->Clear(false);
        }

        void EnterEvadeMode(EvadeReason /*reason*/) override
        {
            if (me->IsInEvadeMode() || !me->IsAlive())
                return;

            Unit* owner = me->GetOwner();

            me->CombatStop(true);
            if (owner && !me->HasUnitState(UNIT_STATE_FOLLOW))
            {
                me->GetMotionMaster()->Clear(false);
                me->GetMotionMaster()->MoveFollow(owner, PET_FOLLOW_DIST, me->GetFollowAngle(), MovementSlot::MOTION_SLOT_ACTIVE);
            }
        }

        void Reset() override
        {
            if (Unit* owner = me->GetOwner())
            {
                owner->CastSpell(me, SPELL_INITIALIZE_IMAGES, true);
                owner->CastSpell(me, SPELL_CLONE_CASTER, true);
            }
        }

        bool CanAIAttack(Unit const* target) const override
        {
            /// Am I supposed to attack this target? (ie. do not attack polymorphed target)
            return target && !target->HasAuraType(SPELL_AURA_MOD_CONFUSE);
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            Unit* l_Victim = me->GetVictim();
            if (l_Victim)
            {
                if (CanAIAttack(l_Victim))
                {
                    /// If not already casting, cast! ("I'm a cast machine")
                    if (!me->HasUnitState(UNIT_STATE_CASTING))
                    {
                        if (uint32 spellId = events.ExecuteEvent())
                        {
                            DoCast(spellId);
                            uint32 castTime = me->GetCurrentSpellCastTime(spellId);
                            events.ScheduleEvent(spellId, (castTime ? castTime : 500) + sSpellMgr->GetSpellInfo(spellId)->ProcCooldown);
                        }
                    }
                }
                else
                {
                    /// My victim has changed state, I shouldn't attack it anymore
                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        me->CastStop();

                    me->AI()->EnterEvadeMode();
                }
            }
            else
            {
                /// Let's choose a new target
                Unit* target = me->SelectVictim();
                if (!target)
                {
                    /// No target? Let's see if our owner has a better target for us
                    if (Unit* owner = me->GetOwner())
                    {
                        Unit* ownerVictim = owner->GetVictim();
                        if (ownerVictim && me->CanCreatureAttack(ownerVictim))
                            target = ownerVictim;
                    }
                }

                if (target)
                    me->AI()->AttackStart(target);
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_mirror_imageAI(creature);
    }
};

// Blazing Soul - 235365
class spell_mage_blazing_soul : public AuraScript
{
    PrepareAuraScript(spell_mage_blazing_soul);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_MAGE_BLAZING_BARRIER, SPELL_MAGE_BLAZING_SOUL });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        Unit* caster = GetCaster();
        Unit* victim = eventInfo.GetActionTarget();
        int32 dist = aurEff->GetBase()->GetEffect(EFFECT_1)->GetAmount();

        if (!caster || !victim || caster->GetDistance(victim) > dist || !eventInfo.GetDamageInfo())
            return;

        if (AuraEffect* barrier = caster->GetAuraEffect(SPELL_MAGE_BLAZING_BARRIER, EFFECT_0))
        {
            int32 bonus = eventInfo.GetDamageInfo()->GetDamage() * aurEff->GetAmount() / 100;
            int32 maxAmount = int32(barrier->GetBaseAmount() + caster->SpellBaseHealingBonusDone(barrier->GetSpellInfo()->GetSchoolMask()) * 7.0f);
            barrier->ChangeAmount(std::min(barrier->GetAmount() + bonus, maxAmount));
        }
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_mage_blazing_soul::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// Flame Patch
// AreaTriggerID - 10801
struct at_mage_flame_patch : AreaTriggerAI
{
    at_mage_flame_patch(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }


    void OnCreate() override
    {
        timeInterval = 1000;
    }

    int32 timeInterval;

    void OnUpdate(uint32 diff) override
    {
        Unit* caster = at->GetCaster();

        if (!caster)
            return;

        if (!caster->ToPlayer())
            return;

        timeInterval += diff;
        if (timeInterval < 1000)
            return;

        caster->CastSpell(at->GetPosition(), SPELL_MAGE_FLAME_PATCH_AOE_DMG, true);

        timeInterval -= 1000;
    }
};

// Cinderstorm - 198929
// AreaTriggerID - 10194
struct at_mage_cinderstorm : AreaTriggerAI
{
    at_mage_cinderstorm(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (Unit* caster = at->GetCaster())
            if (caster->IsValidAttackTarget(unit))
                caster->CastSpell(unit, SPELL_MAGE_CINDERSTORM_DMG, true);
    }
};

// Cinderstorm - 198928
class spell_mage_cinderstorm : public SpellScript
{
    PrepareSpellScript(spell_mage_cinderstorm);

    void HandleDamage(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();
        if (!caster || !target)
            return;

        if (target->HasAura(SPELL_MAGE_IGNITE_DOT))
        {
            int32 pct = sSpellMgr->GetSpellInfo(SPELL_MAGE_CINDERSTORM)->GetEffect(EFFECT_0)->CalcValue(caster);
            int32 dmg = GetHitDamage();
            AddPct(dmg, pct);
            SetHitDamage(dmg);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_mage_cinderstorm::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 257537 - Ebonbolt
class spell_mage_ebonbolt : public SpellScript
{
    PrepareSpellScript(spell_mage_ebonbolt);

    void DoCast()
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_MAGE_BRAIN_FREEZE_AURA, true);
    }

    void DoEffectHitTarget(SpellEffIndex /*effIndex*/)
    {
        Unit* explTarget = GetExplTargetUnit();
        Unit* hitUnit = GetHitUnit();
       // if (!hitUnit !explTarget)
            return;

        if (GetCaster()->HasAura(SPELL_MAGE_SPLITTING_ICE))
            GetCaster()->Variables.Set<ObjectGuid>("explTarget", explTarget->GetGUID());

        GetCaster()->CastSpell(hitUnit, SPELL_MAGE_EBONBOLT_DAMAGE, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_mage_ebonbolt::DoEffectHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnCast += SpellCastFn(spell_mage_ebonbolt::DoCast);
    }
};

// 257538 - Ebonbolt Damage
class spell_mage_ebonbolt_damage : public SpellScript
{
    PrepareSpellScript(spell_mage_ebonbolt_damage);

    void DoEffectHitTarget(SpellEffIndex /*effIndex*/)
    {
        Unit* hitUnit = GetHitUnit();
        ObjectGuid& primaryTarget = GetCaster()->Variables.GetValue<ObjectGuid>("explTarget");
        int32 damage = GetHitDamage();
        //if (!hitUnit !primaryTarget)
            return;

        if (AuraEffect const* eff1 = GetCaster()->GetAuraEffect(SPELL_MAGE_SPLITTING_ICE, EFFECT_1))
            if (hitUnit->GetGUID() != primaryTarget)
                SetHitDamage(CalculatePct(damage, eff1->GetAmount()));
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_mage_ebonbolt_damage::DoEffectHitTarget, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

void AddSC_mage_spell_scripts()
{
    new playerscript_mage_arcane();

    new spell_mage_combustion();
    new spell_mage_incanters_flow();
    new spell_mage_polymorph();
    new spell_mage_time_warp();
    new spell_mage_fire_mage_passive();
    new spell_mage_fire_on();
    new spell_mage_mirror_image_summon();
    new spell_mage_cauterize();
    new spell_mage_conjure_refreshment();
    RegisterAuraScript(spell_mage_ice_floes);

    //7.3.2.25549
    RegisterSpellScript(spell_mage_unstable_magic);
    RegisterSpellScript(spell_mage_cold_snap);
    RegisterSpellScript(spell_mage_cone_of_cold);
    RegisterSpellScript(spell_mage_ice_lance);
    RegisterSpellScript(spell_mage_flurry);
    RegisterSpellScript(spell_mage_nova_talent);
    RegisterSpellScript(spell_mage_frostbolt);
    RegisterSpellScript(spell_mage_blizzard);
    RegisterSpellScript(spell_mage_frozen_orb);
    RegisterSpellScript(spell_mage_frost_bomb_damage);
    RegisterSpellScript(spell_mage_firestarter);
    RegisterSpellScript(spell_mage_pyroblast);
    RegisterSpellScript(spell_mage_living_bomb);
    RegisterSpellScript(spell_mage_living_bomb_spread);
    RegisterSpellScript(spell_mage_meteor);
    RegisterSpellScript(spell_mage_meteor_damage);
    RegisterSpellScript(spell_mage_comet_storm);
    RegisterSpellScript(spell_mage_fire_blast);
    RegisterSpellScript(spell_mage_arcane_blast);
    RegisterSpellScript(spell_mage_arcane_barrage);
    RegisterSpellScript(spell_mage_arcane_missiles_damage);
    RegisterSpellScript(spell_mage_arcane_explosion);

    RegisterAuraScript(spell_mage_chrono_shift);
    RegisterAuraScript(spell_mage_arcane_missiles);
    RegisterAuraScript(spell_mage_arcane_missiles_proc);
    RegisterAuraScript(spell_mage_arcane_missiles_charges);
    RegisterAuraScript(spell_mage_arcane_barrier);
    RegisterAuraScript(spell_mage_conflagration);
    RegisterAuraScript(spell_mage_enhanced_pyrotechnics);
    RegisterAuraScript(spell_mage_frenetic_speed);
    RegisterAuraScript(spell_mage_living_bomb_dot);
    RegisterAuraScript(spell_mage_blazing_barrier);
    RegisterAuraScript(spell_mage_kindling);
    RegisterAuraScript(spell_mage_pyroblast_clearcasting_driver);
    RegisterAuraScript(spell_mage_frozen_veins);
    RegisterAuraScript(spell_mage_chilled_to_the_core);
    RegisterAuraScript(spell_mage_chain_reaction);
    RegisterAuraScript(spell_mage_jouster);
    RegisterAuraScript(spell_mage_jouster_buff);
    RegisterAuraScript(spell_mage_ice_barrier);
    RegisterAuraScript(spell_mage_ice_block);
    RegisterAuraScript(spell_mage_chilled);
    RegisterAuraScript(spell_mage_ray_of_frost);
    RegisterAuraScript(spell_mage_ray_of_frost_buff);
    //7.3.2.25549 END

    RegisterAuraScript(spell_mage_blazing_soul);
    RegisterSpellScript(spell_mage_flamestrike);
    RegisterAuraScript(spell_mage_ring_of_frost);
    new spell_mage_ring_of_frost_stun();
    RegisterSpellScript(spell_mage_cinderstorm);
    
    // Spell Pet scripts
    RegisterAuraScript(spell_mage_pet_freeze);

    // AreaTrigger scripts
    new at_mage_meteor_timer();
    new at_mage_meteor_burn();
    new at_mage_blizzard();
    RegisterAreaTriggerAI(at_mage_rune_of_power);
    RegisterAreaTriggerAI(at_mage_frozen_orb);
    RegisterAreaTriggerAI(at_mage_arcane_orb);
    RegisterAreaTriggerAI(at_mage_flame_patch);
    RegisterAreaTriggerAI(at_mage_cinderstorm);

    // NPC Scripts
    new npc_mirror_image(); 

    new spell_mage_ebonbolt();
    new spell_mage_ebonbolt_damage();
}
