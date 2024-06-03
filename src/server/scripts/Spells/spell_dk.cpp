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
 * Scripts for spells with SPELLFAMILY_DEATHKNIGHT and SPELLFAMILY_GENERIC spells used by deathknight players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_dk_".
 */

#include "ScriptMgr.h"
#include "Containers.h"
#include "CreatureAI.h"
#include "DBCStores.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "PlayerAI.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "Unit.h"

enum DeathKnightSpells
{
    SPELL_DK_ACCLIMATION_HOLY                   = 50490,
    SPELL_DK_ACCLIMATION_FIRE                   = 50362,
    SPELL_DK_ACCLIMATION_FROST                  = 50485,
    SPELL_DK_ACCLIMATION_ARCANE                 = 50486,
    SPELL_DK_ACCLIMATION_SHADOW                 = 50489,
    SPELL_DK_ACCLIMATION_NATURE                 = 50488,
    SPELL_DK_ADVANTAGE_T10_4P_MELEE             = 70657,
    SPELL_DK_ANTI_MAGIC_SHELL_TALENT            = 51052,
    SPELL_DK_BLACK_ICE_R1                       = 49140,
    SPELL_DK_BLOOD_BOIL_TRIGGERED               = 65658,
    SPELL_DK_BLOOD_GORGED_HEAL                  = 50454,
    SPELL_DK_BLOOD_PRESENCE                     = 48266,
    SPELL_DK_CORPSE_EXPLOSION_TRIGGERED         = 43999,
    SPELL_DK_CORPSE_EXPLOSION_VISUAL            = 51270,
    SPELL_DK_DEATH_AND_DECAY_DAMAGE             = 52212,
    SPELL_DK_DEATH_COIL_DAMAGE                  = 47632,
    SPELL_DK_DEATH_COIL_HEAL                    = 47633,
    SPELL_DK_DEATH_GRIP                         = 49560,
    SPELL_DK_DEATH_STRIKE_HEAL                  = 45470,
    SPELL_DK_FROST_FEVER                        = 55095,
    SPELL_DK_FROST_PRESENCE                     = 48263,
    SPELL_DK_FROST_PRESENCE_TRIGGERED           = 61261,
    SPELL_DK_GHOUL_EXPLODE                      = 47496,
    SPELL_DK_GLYPH_OF_DISEASE                   = 63334,
    SPELL_DK_GLYPH_OF_ICEBOUND_FORTITUDE        = 58625,
    SPELL_DK_IMPROVED_BLOOD_PRESENCE_R1         = 50365,
    SPELL_DK_IMPROVED_FROST_PRESENCE_R1         = 50384,
    SPELL_DK_IMPROVED_UNHOLY_PRESENCE_R1        = 50391,
    SPELL_DK_IMPROVED_BLOOD_PRESENCE_HEAL       = 50475,
    SPELL_DK_IMPROVED_BLOOD_PRESENCE_TRIGGERED  = 63611,
    SPELL_DK_IMPROVED_UNHOLY_PRESENCE_TRIGGERED = 63622,
    SPELL_DK_ITEM_SIGIL_VENGEFUL_HEART          = 64962,
    SPELL_DK_ITEM_T8_MELEE_4P_BONUS             = 64736,
    SPELL_DK_MASTER_OF_GHOULS                   = 52143,
    SPELL_DK_BLOOD_PLAGUE                       = 55078,
    SPELL_DK_RAISE_DEAD_USE_REAGENT             = 48289,
    SPELL_DK_RUNIC_POWER_ENERGIZE               = 49088,
    SPELL_DK_SCENT_OF_BLOOD                     = 50422,
    SPELL_DK_SCOURGE_STRIKE_TRIGGERED           = 70890,
    SPELL_DK_UNHOLY_PRESENCE                    = 48265,
    SPELL_DK_UNHOLY_PRESENCE_TRIGGERED          = 49772,
    SPELL_DK_WILL_OF_THE_NECROPOLIS_TALENT_R1   = 49189,
    SPELL_DK_WILL_OF_THE_NECROPOLIS_AURA_R1     = 52284,
    SPELL_DK_GHOUL_THRASH                       = 47480,
    SPELL_DK_GLYPH_OF_SCOURGE_STRIKE_SCRIPT     = 69961,
    SPELL_DK_BUTCHERY_RUNIC_POWER               = 50163,
    SPELL_DK_MARK_OF_BLOOD_HEAL                 = 61607,
    SPELL_DK_UNHOLY_BLIGHT_DAMAGE               = 50536,
    SPELL_DK_GLYPH_OF_UNHOLY_BLIGHT             = 63332,
    SPELL_DK_VENDETTA_HEAL                      = 50181,
    SPELL_DK_NECROSIS_DAMAGE                    = 51460,
    SPELL_DK_OBLITERATE_OFF_HAND_R1             = 66198,
    SPELL_DK_FROST_STRIKE_OFF_HAND_R1           = 66196,
    SPELL_DK_PLAGUE_STRIKE_OFF_HAND_R1          = 66216,
    SPELL_DK_DEATH_STRIKE_OFF_HAND_R1           = 66188,
    SPELL_DK_RUNE_STRIKE_OFF_HAND_R1            = 66217,
    SPELL_DK_BLOOD_STRIKE_OFF_HAND_R1           = 66215,
    SPELL_DK_RUNIC_RETURN                       = 61258,
    SPELL_DK_WANDERING_PLAGUE_DAMAGE            = 50526,
    SPELL_DK_DEATH_COIL_R1                      = 47541,
    SPELL_DK_DEATH_GRIP_INITIAL                 = 49576,
    SPELL_DK_BLOOD_STRIKE                       = 45902,
    SPELL_DK_ICY_TOUCH                          = 45477,
    SPELL_DK_PLAGUE_STRIKE                      = 45462,
    SPELL_DK_DEATH_STRIKE                       = 49998,
    SPELL_DK_HEART_STRIKE                       = 55050,
    SPELL_DK_OBLITERATE                         = 49020,
    SPELL_DK_RUNE_STRIKE                        = 56815
};

enum DeathKnightSpellIcons
{
    DK_ICON_ID_EPIDEMIC                         = 234,
    DK_ICON_ID_IMPROVED_DEATH_STRIKE            = 2751
};

enum DeathKnightMisc
{
    NPC_DK_GHOUL                                = 26125,
    NPC_DK_DANCING_RUNE_WEAPON                  = 27893,
    SPELL_CATEGORY_HOWLING_BLAST                = 1248
};

// -49200 - Acclimation
class spell_dk_acclimation : public AuraScript
{
    PrepareAuraScript(spell_dk_acclimation);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_DK_ACCLIMATION_HOLY,
            SPELL_DK_ACCLIMATION_FIRE,
            SPELL_DK_ACCLIMATION_NATURE,
            SPELL_DK_ACCLIMATION_FROST,
            SPELL_DK_ACCLIMATION_SHADOW,
            SPELL_DK_ACCLIMATION_ARCANE
        });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        if (DamageInfo* damageInfo = eventInfo.GetDamageInfo())
        {
            switch (GetFirstSchoolInMask(damageInfo->GetSchoolMask()))
            {
                case SPELL_SCHOOL_HOLY:
                case SPELL_SCHOOL_FIRE:
                case SPELL_SCHOOL_NATURE:
                case SPELL_SCHOOL_FROST:
                case SPELL_SCHOOL_SHADOW:
                case SPELL_SCHOOL_ARCANE:
                    return true;
                default:
                    break;
            }
        }

        return false;
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        uint32 triggerspell = 0;

        switch (GetFirstSchoolInMask(eventInfo.GetDamageInfo()->GetSchoolMask()))
        {
            case SPELL_SCHOOL_HOLY:
                triggerspell = SPELL_DK_ACCLIMATION_HOLY;
                break;
            case SPELL_SCHOOL_FIRE:
                triggerspell = SPELL_DK_ACCLIMATION_FIRE;
                break;
            case SPELL_SCHOOL_NATURE:
                triggerspell = SPELL_DK_ACCLIMATION_NATURE;
                break;
            case SPELL_SCHOOL_FROST:
                triggerspell = SPELL_DK_ACCLIMATION_FROST;
                break;
            case SPELL_SCHOOL_SHADOW:
                triggerspell = SPELL_DK_ACCLIMATION_SHADOW;
                break;
            case SPELL_SCHOOL_ARCANE:
                triggerspell = SPELL_DK_ACCLIMATION_ARCANE;
                break;
            default:
                return;
        }

        if (Unit* target = eventInfo.GetActionTarget())
            target->CastSpell(target, triggerspell, aurEff);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_dk_acclimation::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_dk_acclimation::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 70656 - Advantage (T10 4P Melee Bonus)
class spell_dk_advantage_t10_4p : public AuraScript
{
    PrepareAuraScript(spell_dk_advantage_t10_4p);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DK_ADVANTAGE_T10_4P_MELEE });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        if (Unit* caster = eventInfo.GetActor())
        {
            if (caster->GetTypeId() != TYPEID_PLAYER || caster->GetClass() != CLASS_DEATH_KNIGHT)
                return false;

            for (uint8 i = 0; i < MAX_RUNES; ++i)
                if (caster->ToPlayer()->GetRuneCooldown(i) == 0)
                    return false;

            return true;
        }

        return false;
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_dk_advantage_t10_4p::CheckProc);
    }
};

// 50462 - Anti-Magic Shell (on raid member)
class spell_dk_anti_magic_shell_raid : public AuraScript
{
    PrepareAuraScript(spell_dk_anti_magic_shell_raid);

public:
    spell_dk_anti_magic_shell_raid()
    {
        absorbPct = 0;
    }

private:
    uint32 absorbPct;

    bool Load() override
    {
        absorbPct = GetEffectInfo(EFFECT_0).CalcValue(GetCaster());
        return true;
    }

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32 & amount, bool & /*canBeRecalculated*/)
    {
        /// @todo this should absorb limited amount of damage, but no info on calculation formula
        amount = -1;
    }

    void Absorb(AuraEffect* /*aurEff*/, DamageInfo & dmgInfo, uint32 & absorbAmount)
    {
        absorbAmount = CalculatePct(dmgInfo.GetDamage(), absorbPct);
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dk_anti_magic_shell_raid::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
        OnEffectAbsorb += AuraEffectAbsorbFn(spell_dk_anti_magic_shell_raid::Absorb, EFFECT_0);
    }
};

// 48707 - Anti-Magic Shell (on self)
class spell_dk_anti_magic_shell_self : public AuraScript
{
    PrepareAuraScript(spell_dk_anti_magic_shell_self);

public:
    spell_dk_anti_magic_shell_self()
    {
        absorbPct = 0;
        hpPct = 0;
    }

private:
    uint32 absorbPct, hpPct;
    bool Load() override
    {
        absorbPct = GetEffectInfo(EFFECT_0).CalcValue(GetCaster());
        hpPct = GetEffectInfo(EFFECT_1).CalcValue(GetCaster());
        return true;
    }

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DK_RUNIC_POWER_ENERGIZE });
    }

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32 & amount, bool & /*canBeRecalculated*/)
    {
        amount = GetCaster()->CountPctFromMaxHealth(hpPct);
    }

    void Absorb(AuraEffect* /*aurEff*/, DamageInfo & dmgInfo, uint32 & absorbAmount)
    {
        absorbAmount = std::min(CalculatePct(dmgInfo.GetDamage(), absorbPct), GetTarget()->CountPctFromMaxHealth(hpPct));
    }

    void Trigger(AuraEffect* aurEff, DamageInfo& /*dmgInfo*/, uint32& absorbAmount)
    {
        // damage absorbed by Anti-Magic Shell energizes the DK with additional runic power.
        // This, if I'm not mistaken, shows that we get back ~20% of the absorbed damage as runic power.
        CastSpellExtraArgs args(aurEff);
        args.AddSpellBP0(CalculatePct(absorbAmount, 20));
        GetTarget()->CastSpell(GetTarget(), SPELL_DK_RUNIC_POWER_ENERGIZE, args);
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dk_anti_magic_shell_self::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
        OnEffectAbsorb += AuraEffectAbsorbFn(spell_dk_anti_magic_shell_self::Absorb, EFFECT_0);
        AfterEffectAbsorb += AuraEffectAbsorbFn(spell_dk_anti_magic_shell_self::Trigger, EFFECT_0);
    }
};

// 50461 - Anti-Magic Zone
class spell_dk_anti_magic_zone : public AuraScript
{
    PrepareAuraScript(spell_dk_anti_magic_zone);

public:
    spell_dk_anti_magic_zone()
    {
        absorbPct = 0;
    }

private:
    uint32 absorbPct;

    bool Load() override
    {
        absorbPct = GetEffectInfo(EFFECT_0).CalcValue(GetCaster());
        return true;
    }

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DK_ANTI_MAGIC_SHELL_TALENT });
    }

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
    {
        SpellInfo const* talentSpell = sSpellMgr->AssertSpellInfo(SPELL_DK_ANTI_MAGIC_SHELL_TALENT);
        Unit* owner = GetCaster()->GetOwner();
        if (!owner)
            return;

        amount = talentSpell->GetEffect(EFFECT_0).CalcValue(owner);
        if (Player* player = owner->ToPlayer())
            amount += int32(2 * player->GetTotalAttackPowerValue(BASE_ATTACK));
    }

    void Absorb(AuraEffect* /*aurEff*/, DamageInfo& dmgInfo, uint32 &absorbAmount)
    {
        absorbAmount = CalculatePct(dmgInfo.GetDamage(), absorbPct);
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dk_anti_magic_zone::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
        OnEffectAbsorb += AuraEffectAbsorbFn(spell_dk_anti_magic_zone::Absorb, EFFECT_0);
    }
};

// -49182 - Blade Barrier
class spell_dk_blade_barrier : public AuraScript
{
    PrepareAuraScript(spell_dk_blade_barrier);

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        if (eventInfo.GetSpellInfo() != nullptr)
            if (Player* player = eventInfo.GetActor()->ToPlayer())
                if (player->GetClass() == CLASS_DEATH_KNIGHT && player->IsBaseRuneSlotsOnCooldown(RUNE_BLOOD))
                    return true;

        return false;
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_dk_blade_barrier::CheckProc);
    }
};

// -48721 - Blood Boil
class spell_dk_blood_boil : public SpellScript
{
    PrepareSpellScript(spell_dk_blood_boil);

public:
    spell_dk_blood_boil()
    {
        _executed = false;
    }

private:
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DK_BLOOD_BOIL_TRIGGERED });
    }

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_PLAYER && GetCaster()->GetClass() == CLASS_DEATH_KNIGHT;
    }

    void HandleAfterHit()
    {
        if (_executed || !GetHitUnit())
            return;

        _executed = true;
        GetCaster()->CastSpell(GetCaster(), SPELL_DK_BLOOD_BOIL_TRIGGERED, true);
    }

    void Register() override
    {
        AfterHit += SpellHitFn(spell_dk_blood_boil::HandleAfterHit);
    }

    bool _executed;
};

// 50453 - Bloodworms Health Leech
class spell_dk_blood_gorged : public AuraScript
{
    PrepareAuraScript(spell_dk_blood_gorged);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DK_BLOOD_GORGED_HEAL });
    }

    bool CheckProc(ProcEventInfo& /*eventInfo*/)
    {
        _procTarget = GetTarget()->GetOwner();
        return _procTarget != nullptr;
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        DamageInfo* damageInfo = eventInfo.GetDamageInfo();
        if (!damageInfo || !damageInfo->GetDamage())
            return;

        CastSpellExtraArgs args(aurEff);
        args.AddSpellBP0(damageInfo->GetDamage() * 1.5f);
        GetTarget()->CastSpell(_procTarget, SPELL_DK_BLOOD_GORGED_HEAL, args);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_dk_blood_gorged::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_dk_blood_gorged::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }

private:
    Unit* _procTarget = nullptr;
};

// -49027 - Bloodworms
class spell_dk_bloodworms : public AuraScript
{
    PrepareAuraScript(spell_dk_bloodworms);

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        aurEff->GetBase()->RecalculateAmountOfEffects();
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_dk_bloodworms::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL_WITH_VALUE);
    }
};

// -48979 - Butchery
class spell_dk_butchery : public AuraScript
{
    PrepareAuraScript(spell_dk_butchery);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DK_BUTCHERY_RUNIC_POWER });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        CastSpellExtraArgs args(aurEff);
        args.AddSpellBP0(aurEff->GetAmount());
        eventInfo.GetActor()->CastSpell(nullptr, SPELL_DK_BUTCHERY_RUNIC_POWER, args);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_dk_butchery::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

class CorpseExplosionCheck
{
public:
    explicit CorpseExplosionCheck(ObjectGuid casterGUID, bool allowGhoul) : _casterGUID(casterGUID),
        _allowGhoul(allowGhoul) { }

    bool operator()(WorldObject* obj) const
    {
        if (Unit* target = obj->ToUnit())
        {
            if ((target->isDead() || (_allowGhoul && target->GetEntry() == NPC_DK_GHOUL && target->GetOwnerGUID() == _casterGUID))
                && !(target->GetCreatureTypeMask() & CREATURE_TYPEMASK_MECHANICAL_OR_ELEMENTAL)
                && target->GetDisplayId() == target->GetNativeDisplayId())
                return false;
        }

        return true;
    }

private:
    ObjectGuid _casterGUID;
    bool _allowGhoul;
};

// -49158 - Corpse Explosion (51325, 51326, 51327, 51328)
class spell_dk_corpse_explosion : public SpellScript
{
    PrepareSpellScript(spell_dk_corpse_explosion);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo(
        {
            SPELL_DK_CORPSE_EXPLOSION_TRIGGERED,
            SPELL_DK_GHOUL_EXPLODE,
            SPELL_DK_CORPSE_EXPLOSION_VISUAL,
            static_cast<uint32>(spellInfo->GetEffect(EFFECT_1).CalcValue())
        });
    }

    void CheckTarget(WorldObject*& target)
    {
        if (CorpseExplosionCheck(GetCaster()->GetGUID(), true)(target))
            target = nullptr;

        _target = target;
    }

    void CheckTargets(std::list<WorldObject*>& targets)
    {
        WorldObject* target = _target;
        if (!target)
        {
            targets.remove_if(CorpseExplosionCheck(GetCaster()->GetGUID(), false));
            if (targets.empty())
            {
                FinishCast(SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW);
                return;
            }
            target = Trinity::Containers::SelectRandomContainerElement(targets);
            targets.clear();
            targets.push_back(target);
        }
        else
            targets.clear();
    }

    void HandleDamage(SpellEffIndex effIndex, Unit* target)
    {
        CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
        if (effIndex == EFFECT_0)
        {
            args.AddSpellBP0(GetEffectValue());
            GetCaster()->CastSpell(target, GetEffectInfo(EFFECT_1).CalcValue(), args);
        }
        else if (effIndex == EFFECT_1)
        {
            args.AddSpellBP0(GetSpell()->CalculateDamage(GetEffectInfo(EFFECT_0)));
            GetCaster()->CastSpell(target, GetEffectValue(), args);
        }
    }

    void HandleCorpseExplosion(SpellEffIndex effIndex)
    {
        if (Unit* unitTarget = GetHitUnit())
        {
            if (unitTarget->IsAlive())  // Living ghoul as a target
            {
                unitTarget->CastSpell(unitTarget, SPELL_DK_GHOUL_EXPLODE, false);
                // Corpse Explosion (Suicide) and Set corpse look handled in SpellScript of SPELL_DK_GHOUL_EXPLODE
            }
            else                        // Some corpse
            {
                HandleDamage(effIndex, unitTarget);
                // Corpse Explosion (Suicide)
                unitTarget->CastSpell(unitTarget, SPELL_DK_CORPSE_EXPLOSION_TRIGGERED, true);
                // Set corpse look
                GetCaster()->CastSpell(unitTarget, SPELL_DK_CORPSE_EXPLOSION_VISUAL, true);
            }
        }
    }

    void Register() override
    {
        OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_dk_corpse_explosion::CheckTarget, EFFECT_0, TARGET_UNIT_TARGET_ANY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dk_corpse_explosion::CheckTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ENTRY);
        OnEffectHitTarget += SpellEffectFn(spell_dk_corpse_explosion::HandleCorpseExplosion, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnEffectHitTarget += SpellEffectFn(spell_dk_corpse_explosion::HandleCorpseExplosion, EFFECT_1, SPELL_EFFECT_DUMMY);
    }

    WorldObject* _target = nullptr;
};

// -43265 - Death and Decay
class spell_dk_death_and_decay : public AuraScript
{
    PrepareAuraScript(spell_dk_death_and_decay);

    void HandleDummyTick(AuraEffect const* aurEff)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;
        CastSpellExtraArgs args(aurEff);
        args.AddSpellBP0(aurEff->GetAmount());
        caster->CastSpell(GetTarget(), SPELL_DK_DEATH_AND_DECAY_DAMAGE, args);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_dk_death_and_decay::HandleDummyTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// -47541, 52375, 59134, -62900 - Death Coil
class spell_dk_death_coil : public SpellScript
{
    PrepareSpellScript(spell_dk_death_coil);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_DK_DEATH_COIL_DAMAGE, SPELL_DK_DEATH_COIL_HEAL });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (Unit* target = GetHitUnit())
        {
            if (caster->IsFriendlyTo(target))
            {
                CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
                args.AddSpellBP0(GetEffectValue() * 1.5f);
                caster->CastSpell(target, SPELL_DK_DEATH_COIL_HEAL, args);
            }
            else
            {
                int32 damage = GetEffectValue();
                if (AuraEffect const* auraEffect = caster->GetAuraEffect(SPELL_DK_ITEM_SIGIL_VENGEFUL_HEART, EFFECT_1))
                    damage += auraEffect->GetBaseAmount();
                CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
                args.AddSpellBP0(damage);
                caster->CastSpell(target, SPELL_DK_DEATH_COIL_DAMAGE, args);
            }
        }
    }

    SpellCastResult CheckCast()
    {
        Unit* caster = GetCaster();
        if (Unit* target = GetExplTargetUnit())
        {
            if (!caster->IsFriendlyTo(target) && !caster->isInFront(target))
                return SPELL_FAILED_UNIT_NOT_INFRONT;

            if (target->IsFriendlyTo(caster) && target->GetCreatureType() != CREATURE_TYPE_UNDEAD)
                return SPELL_FAILED_BAD_TARGETS;
        }
        else
            return SPELL_FAILED_BAD_TARGETS;

        return SPELL_CAST_OK;
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_dk_death_coil::CheckCast);
        OnEffectHitTarget += SpellEffectFn(spell_dk_death_coil::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 52751 - Death Gate
class spell_dk_death_gate : public SpellScript
{
    PrepareSpellScript(spell_dk_death_gate);

    SpellCastResult CheckClass()
    {
        if (GetCaster()->GetClass() != CLASS_DEATH_KNIGHT)
        {
            SetCustomCastResultMessage(SPELL_CUSTOM_ERROR_MUST_BE_DEATH_KNIGHT);
            return SPELL_FAILED_CUSTOM_ERROR;
        }

        return SPELL_CAST_OK;
    }

    void HandleScript(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
        if (Unit* target = GetHitUnit())
            target->CastSpell(target, GetEffectValue(), false);
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_dk_death_gate::CheckClass);
        OnEffectHitTarget += SpellEffectFn(spell_dk_death_gate::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 49560 - Death Grip
class spell_dk_death_grip : public SpellScript
{
    PrepareSpellScript(spell_dk_death_grip);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (Unit* target = GetHitUnit())
            if (!target->HasAuraType(SPELL_AURA_DEFLECT_SPELLS)) // Deterrence
                target->CastSpell(GetExplTargetDest()->GetPosition(), GetEffectValue(), true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_dk_death_grip::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 48743 - Death Pact
class spell_dk_death_pact : public SpellScript
{
    PrepareSpellScript(spell_dk_death_pact);

    void FilterTargets(std::list<WorldObject*>& targetList)
    {
        targetList.remove_if([&](WorldObject* target)
        {
            Unit* unit = target->ToUnit();
            if (!unit)
                return true;
            if (unit->GetOwnerGUID() != GetCaster()->GetGUID())
                return true;
            if (unit->GetCreatureType() != CREATURE_TYPE_UNDEAD)
                return true;
            return false;
        });

        if (targetList.empty())
        {
            FinishCast(SPELL_FAILED_NO_PET);
            return;
        }

        targetList.remove_if([&](WorldObject* target)
        {
            return target->ToUnit()->IsImmunedToSpell(GetSpellInfo(), GetCaster());
        });

        if (targetList.empty())
        {
            FinishCast(SPELL_FAILED_IMMUNE);
            return;
        }

        Trinity::Containers::RandomResize(targetList, 1);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dk_death_pact::FilterTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ALLY);
    }
};

// -54639 - Blood of the North
// -49208 - Reaping
// -49467 - Death Rune Mastery
class spell_dk_death_rune : public AuraScript
{
    PrepareAuraScript(spell_dk_death_rune);

    bool Load() override
    {
        return GetUnitOwner()->GetTypeId() == TYPEID_PLAYER && GetUnitOwner()->ToPlayer()->GetClass() == CLASS_DEATH_KNIGHT;
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        Unit* caster = eventInfo.GetActor();

        if (caster->GetTypeId() != TYPEID_PLAYER)
            return false;

        Player* player = caster->ToPlayer();
        if (player->GetClass() != CLASS_DEATH_KNIGHT)
            return false;

        return true;
    }

    void HandleProc(ProcEventInfo& eventInfo)
    {
        Player* player = eventInfo.GetActor()->ToPlayer();

        AuraEffect* aurEff = GetEffect(EFFECT_0);
        if (!aurEff)
            return;

        // Reset amplitude - set death rune remove timer to 30s
        aurEff->ResetPeriodic(true);

        uint32 runesLeft = 1;

        // Death Rune Mastery
        if (GetSpellInfo()->SpellIconID == 2622)
            runesLeft = 2;

        for (uint8 i = 0; i < MAX_RUNES && runesLeft; ++i)
        {
            if (GetSpellInfo()->SpellIconID == 2622)
            {
                if (player->GetBaseRune(i) == RUNE_BLOOD)
                    continue;
            }
            else
            {
                if (player->GetBaseRune(i) != RUNE_BLOOD)
                    continue;
            }

            if (player->GetRuneCooldown(i) != (player->GetRuneBaseCooldown(i) - player->GetLastRuneGraceTimer(i)))
                continue;

            --runesLeft;
            // Mark aura as used
            player->AddRuneByAuraEffect(i, RUNE_DEATH, aurEff);
        }
    }

    void PeriodicTick(AuraEffect const* aurEff)
    {
        // timer expired - remove death runes
        GetTarget()->ToPlayer()->RemoveRunesByAuraEffect(aurEff);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_dk_death_rune::CheckProc);
        OnProc += AuraProcFn(spell_dk_death_rune::HandleProc);
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_dk_death_rune::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// -49998 - Death Strike
class spell_dk_death_strike : public SpellScript
{
    PrepareSpellScript(spell_dk_death_strike);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DK_DEATH_STRIKE_HEAL });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (Unit* target = GetHitUnit())
        {
            uint32 count = target->GetDiseasesByCaster(caster->GetGUID());
            int32 bp = int32(count * caster->CountPctFromMaxHealth(int32(GetEffectInfo(EFFECT_0).DamageMultiplier)));
            // Improved Death Strike
            if (AuraEffect const* aurEff = caster->GetAuraEffect(SPELL_AURA_ADD_PCT_MODIFIER, SPELLFAMILY_DEATHKNIGHT, DK_ICON_ID_IMPROVED_DEATH_STRIKE, 0))
                AddPct(bp, caster->CalculateSpellDamage(aurEff->GetSpellInfo()->GetEffect(EFFECT_2)));

            // @todo castspell refactor note: this is not triggered - is this intended??
            CastSpellExtraArgs args;
            args.AddSpellBP0(bp);
            caster->CastSpell(caster, SPELL_DK_DEATH_STRIKE_HEAL, args);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_dk_death_strike::HandleDummy, EFFECT_2, SPELL_EFFECT_DUMMY);
    }
};

// 47496 - Explode, Ghoul spell for Corpse Explosion
class spell_dk_ghoul_explode : public SpellScript
{
    PrepareSpellScript(spell_dk_ghoul_explode);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ SPELL_DK_CORPSE_EXPLOSION_TRIGGERED }) &&
            spellInfo->GetEffect(EFFECT_2).CalcValue() > 0;
    }

    void HandleDamage(SpellEffIndex /*effIndex*/)
    {
        int32 value = int32(GetCaster()->CountPctFromMaxHealth(GetSpellInfo()->GetEffect(EFFECT_2).CalcValue(GetCaster())));
        SetEffectValue(value);
    }

    void Suicide(SpellEffIndex /*effIndex*/)
    {
        if (Unit* unitTarget = GetHitUnit())
        {
            // Corpse Explosion (Suicide)
            unitTarget->CastSpell(unitTarget, SPELL_DK_CORPSE_EXPLOSION_TRIGGERED, true);
            // Set corpse look
            GetCaster()->CastSpell(unitTarget, SPELL_DK_CORPSE_EXPLOSION_VISUAL, true);
        }
    }

    void Register() override
    {
        OnEffectLaunchTarget += SpellEffectFn(spell_dk_ghoul_explode::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        OnEffectHitTarget += SpellEffectFn(spell_dk_ghoul_explode::Suicide, EFFECT_1, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 62259 - Glyph of Death Grip
class spell_dk_glyph_of_death_grip : public AuraScript
{
    PrepareAuraScript(spell_dk_glyph_of_death_grip);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DK_DEATH_GRIP_INITIAL });
    }

    void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        eventInfo.GetActor()->GetSpellHistory()->ResetCooldown(SPELL_DK_DEATH_GRIP_INITIAL, true);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_dk_glyph_of_death_grip::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 58642 - Glyph of Scourge Strike
class spell_dk_glyph_of_scourge_strike : public AuraScript
{
    PrepareAuraScript(spell_dk_glyph_of_scourge_strike);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DK_GLYPH_OF_SCOURGE_STRIKE_SCRIPT });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        eventInfo.GetActor()->CastSpell(eventInfo.GetProcTarget(), SPELL_DK_GLYPH_OF_SCOURGE_STRIKE_SCRIPT, aurEff);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_dk_glyph_of_scourge_strike::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 69961 - Glyph of Scourge Strike
class spell_dk_glyph_of_scourge_strike_script : public SpellScript
{
    PrepareSpellScript(spell_dk_glyph_of_scourge_strike_script);

    void HandleScriptEffect(SpellEffIndex /* effIndex */)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();

        Unit::AuraEffectList const& mPeriodic = target->GetAuraEffectsByType(SPELL_AURA_PERIODIC_DAMAGE);
        for (Unit::AuraEffectList::const_iterator i = mPeriodic.begin(); i != mPeriodic.end(); ++i)
        {
            AuraEffect const* aurEff = *i;
            SpellInfo const* spellInfo = aurEff->GetSpellInfo();
            // search our Blood Plague and Frost Fever on target
            if (spellInfo->SpellFamilyName == SPELLFAMILY_DEATHKNIGHT && spellInfo->SpellFamilyFlags[2] & 0x2 &&
                aurEff->GetCasterGUID() == caster->GetGUID())
            {
                uint32 countMin = aurEff->GetBase()->GetMaxDuration();
                uint32 countMax = spellInfo->GetMaxDuration();

                // this Glyph
                countMax += 9000;
                // talent Epidemic
                if (AuraEffect const* epidemic = caster->GetAuraEffect(SPELL_AURA_ADD_FLAT_MODIFIER, SPELLFAMILY_DEATHKNIGHT, DK_ICON_ID_EPIDEMIC, EFFECT_0))
                    countMax += epidemic->GetAmount();

                if (countMin < countMax)
                {
                    aurEff->GetBase()->SetDuration(aurEff->GetBase()->GetDuration() + 3000);
                    aurEff->GetBase()->SetMaxDuration(countMin + 3000);
                }
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_dk_glyph_of_scourge_strike_script::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 49016 - Hysteria
class spell_dk_hysteria : public AuraScript
{
    PrepareAuraScript(spell_dk_hysteria);

    void PeriodicTick(AuraEffect const* aurEff)
    {
        uint32 const damage = GetTarget()->CountPctFromMaxHealth(GetTarget()->CalculateSpellDamage(aurEff->GetSpellEffectInfo()));
        Unit::DealDamage(GetTarget(), GetTarget(), damage, nullptr, SELF_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, nullptr, false);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_dk_hysteria::PeriodicTick, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 55095 - Frost Fever
class spell_dk_frost_fever : public AuraScript
{
    PrepareAuraScript(spell_dk_frost_fever);

    void HandleDispel(DispelInfo* /*dispelInfo*/)
    {
        if (Unit* caster = GetCaster())
            if (AuraEffect* icyClutch = GetUnitOwner()->GetAuraEffect(SPELL_AURA_MOD_DECREASE_SPEED, SPELLFAMILY_DEATHKNIGHT, 0, 0x00040000, 0, caster->GetGUID()))
                GetUnitOwner()->RemoveAurasDueToSpell(icyClutch->GetId());
    }

    void Register() override
    {
        AfterDispel += AuraDispelFn(spell_dk_frost_fever::HandleDispel);
    }
};

// 51209 - Hungering Cold
class spell_dk_hungering_cold : public AuraScript
{
    PrepareAuraScript(spell_dk_hungering_cold);

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        SpellInfo const* spellInfo = eventInfo.GetSpellInfo();
        if (!spellInfo) // probably melee damage so let's proc
            return true;

        return (spellInfo->Dispel != DISPEL_DISEASE);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_dk_hungering_cold::CheckProc);
    }
};

// 48792 - Icebound Fortitude
class spell_dk_icebound_fortitude : public AuraScript
{
    PrepareAuraScript(spell_dk_icebound_fortitude);

    bool Load() override
    {
        Unit* caster = GetCaster();
        return caster && caster->GetTypeId() == TYPEID_PLAYER;
    }

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
    {
        if (Unit* caster = GetCaster())
        {
            int32 value = amount;
            uint32 defValue = uint32(caster->ToPlayer()->GetSkillValue(SKILL_DEFENSE) + caster->ToPlayer()->GetRatingBonusValue(CR_DEFENSE_SKILL));

            if (defValue > 400)
                value -= int32((defValue - 400) * 0.15);

            // Glyph of Icebound Fortitude
            if (AuraEffect const* aurEff = caster->GetAuraEffect(SPELL_DK_GLYPH_OF_ICEBOUND_FORTITUDE, EFFECT_0))
            {
                int32 valMax = -aurEff->GetAmount();
                if (value > valMax)
                    value = valMax;
            }
            amount = value;
        }
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dk_icebound_fortitude::CalculateAmount, EFFECT_2, SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN);
    }
};

// -50365 - Improved Blood Presence
class spell_dk_improved_blood_presence : public AuraScript
{
    PrepareAuraScript(spell_dk_improved_blood_presence);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_DK_BLOOD_PRESENCE,
            SPELL_DK_FROST_PRESENCE,
            SPELL_DK_UNHOLY_PRESENCE,
            SPELL_DK_IMPROVED_BLOOD_PRESENCE_TRIGGERED
        });
    }

    void HandleEffectApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        if ((target->HasAura(SPELL_DK_FROST_PRESENCE) || target->HasAura(SPELL_DK_UNHOLY_PRESENCE)) && !target->HasAura(SPELL_DK_IMPROVED_BLOOD_PRESENCE_TRIGGERED))
        {
            CastSpellExtraArgs args(aurEff);
            args.AddSpellMod(SPELLVALUE_BASE_POINT1, aurEff->GetAmount());
            target->CastSpell(target, SPELL_DK_IMPROVED_BLOOD_PRESENCE_TRIGGERED, args);
        }
    }

    void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        if (!target->HasAura(SPELL_DK_BLOOD_PRESENCE))
            target->RemoveAura(SPELL_DK_IMPROVED_BLOOD_PRESENCE_TRIGGERED);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_dk_improved_blood_presence::HandleEffectApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_dk_improved_blood_presence::HandleEffectRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 63611 - Improved Blood Presence Triggered
class spell_dk_improved_blood_presence_triggered : public AuraScript
{
    PrepareAuraScript(spell_dk_improved_blood_presence_triggered);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DK_IMPROVED_BLOOD_PRESENCE_HEAL });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        if (eventInfo.GetActor()->GetTypeId() == TYPEID_PLAYER)
            return true;

        return false;
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        if (DamageInfo* dmgInfo = eventInfo.GetDamageInfo())
        {
            CastSpellExtraArgs args(aurEff);
            args.AddSpellBP0(CalculatePct(dmgInfo->GetDamage(), aurEff->GetAmount()));
            eventInfo.GetActor()->CastSpell(eventInfo.GetActor(), SPELL_DK_IMPROVED_BLOOD_PRESENCE_HEAL, args);
        }
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_dk_improved_blood_presence_triggered::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_dk_improved_blood_presence_triggered::HandleProc, EFFECT_1, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// -50384 - Improved Frost Presence
class spell_dk_improved_frost_presence : public AuraScript
{
    PrepareAuraScript(spell_dk_improved_frost_presence);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_DK_BLOOD_PRESENCE,
            SPELL_DK_FROST_PRESENCE,
            SPELL_DK_UNHOLY_PRESENCE,
            SPELL_DK_FROST_PRESENCE_TRIGGERED
        });
    }

    void HandleEffectApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        if ((target->HasAura(SPELL_DK_BLOOD_PRESENCE) || target->HasAura(SPELL_DK_UNHOLY_PRESENCE)) && !target->HasAura(SPELL_DK_FROST_PRESENCE_TRIGGERED))
        {
            CastSpellExtraArgs args(aurEff);
            args.AddSpellBP0(aurEff->GetAmount());
            target->CastSpell(target, SPELL_DK_FROST_PRESENCE_TRIGGERED, args);
        }
    }

    void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        if (!target->HasAura(SPELL_DK_FROST_PRESENCE))
            target->RemoveAura(SPELL_DK_FROST_PRESENCE_TRIGGERED);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_dk_improved_frost_presence::HandleEffectApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_dk_improved_frost_presence::HandleEffectRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// -50391 - Improved Unholy Presence
class spell_dk_improved_unholy_presence : public AuraScript
{
    PrepareAuraScript(spell_dk_improved_unholy_presence);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_DK_BLOOD_PRESENCE,
            SPELL_DK_FROST_PRESENCE,
            SPELL_DK_UNHOLY_PRESENCE,
            SPELL_DK_IMPROVED_UNHOLY_PRESENCE_TRIGGERED,
            SPELL_DK_UNHOLY_PRESENCE_TRIGGERED
        });
    }

    void HandleEffectApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        if (target->HasAura(SPELL_DK_UNHOLY_PRESENCE) && !target->HasAura(SPELL_DK_IMPROVED_UNHOLY_PRESENCE_TRIGGERED))
        {
            // Not listed as any effect, only base points set in dbc
            int32 basePoints = GetEffectInfo(EFFECT_1).CalcValue();
            CastSpellExtraArgs args(aurEff);
            for (uint32 i = 0; i < MAX_SPELL_EFFECTS; ++i)
                args.AddSpellMod(SpellValueMod(SPELLVALUE_BASE_POINT0 + i), basePoints);
            target->CastSpell(target, SPELL_DK_IMPROVED_UNHOLY_PRESENCE_TRIGGERED, args);
        }

        if ((target->HasAura(SPELL_DK_BLOOD_PRESENCE) || target->HasAura(SPELL_DK_FROST_PRESENCE)) && !target->HasAura(SPELL_DK_UNHOLY_PRESENCE_TRIGGERED))
        {
            CastSpellExtraArgs args(aurEff);
            args.AddSpellBP0(aurEff->GetAmount());
            target->CastSpell(target, SPELL_DK_UNHOLY_PRESENCE_TRIGGERED, args);
        }
    }

    void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();

        target->RemoveAura(SPELL_DK_IMPROVED_UNHOLY_PRESENCE_TRIGGERED);

        if (!target->HasAura(SPELL_DK_UNHOLY_PRESENCE))
            target->RemoveAura(SPELL_DK_UNHOLY_PRESENCE_TRIGGERED);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_dk_improved_unholy_presence::HandleEffectApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_dk_improved_unholy_presence::HandleEffectRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 61257 - Runic Power Back on Snare/Root
class spell_dk_pvp_4p_bonus : public AuraScript
{
    PrepareAuraScript(spell_dk_pvp_4p_bonus);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DK_RUNIC_RETURN });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        SpellInfo const* spellInfo = eventInfo.GetSpellInfo();
        if (!spellInfo)
            return false;

        return (spellInfo->GetAllEffectsMechanicMask() & ((1 << MECHANIC_ROOT) | (1 << MECHANIC_SNARE))) != 0;
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        eventInfo.GetActionTarget()->CastSpell(nullptr, SPELL_DK_RUNIC_RETURN, aurEff);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_dk_pvp_4p_bonus::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_dk_pvp_4p_bonus::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 49005 - Mark of Blood
class spell_dk_mark_of_blood : public AuraScript
{
    PrepareAuraScript(spell_dk_mark_of_blood);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DK_MARK_OF_BLOOD_HEAL });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        eventInfo.GetActor()->CastSpell(eventInfo.GetProcTarget(), SPELL_DK_MARK_OF_BLOOD_HEAL, aurEff);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_dk_mark_of_blood::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// -51459 - Necrosis
class spell_dk_necrosis : public AuraScript
{
    PrepareAuraScript(spell_dk_necrosis);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DK_NECROSIS_DAMAGE });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        DamageInfo* damageInfo = eventInfo.GetDamageInfo();
        if (!damageInfo || !damageInfo->GetDamage())
            return;

        CastSpellExtraArgs args(aurEff);
        args.AddSpellBP0(CalculatePct(damageInfo->GetDamage(), aurEff->GetAmount()));
        eventInfo.GetActor()->CastSpell(eventInfo.GetProcTarget(), SPELL_DK_NECROSIS_DAMAGE, args);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_dk_necrosis::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 50842 - Pestilence
class spell_dk_pestilence : public SpellScript
{
    PrepareSpellScript(spell_dk_pestilence);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_DK_GLYPH_OF_DISEASE,
            SPELL_DK_BLOOD_PLAGUE,
            SPELL_DK_FROST_FEVER
        });
    }

    void OnHit(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* hitUnit = GetHitUnit();
        Unit* victim = GetExplTargetUnit();

        if (!victim)
            return;

        if (victim != hitUnit || caster->HasAura(SPELL_DK_GLYPH_OF_DISEASE))
        {
            if (Aura* aurOld = victim->GetAura(SPELL_DK_BLOOD_PLAGUE, caster->GetGUID())) // Check Blood Plague application on victim.
            {
                float donePct = aurOld->GetDonePct();
                float critChance = aurOld->GetCritChance();

                if (aurOld->GetEffect(EFFECT_0))
                {
                    caster->CastSpell(hitUnit, SPELL_DK_BLOOD_PLAGUE, true); // Spread the disease to hitUnit.

                    if (Aura* aurNew = hitUnit->GetAura(SPELL_DK_BLOOD_PLAGUE, caster->GetGUID())) // Check Blood Plague application on hitUnit.
                    {
                        aurNew->SetCritChance(critChance); // Blood Plague can crit if caster has T9.
                        aurNew->SetDonePct(donePct);
                        if (AuraEffect* aurEffNew = aurNew->GetEffect(EFFECT_0))
                            aurEffNew->ChangeAmount(aurEffNew->CalculateAmount(aurEffNew->GetCaster()), false);
                    }
                }
            }

            if (Aura* aurOld = victim->GetAura(SPELL_DK_FROST_FEVER, caster->GetGUID())) // Check Frost Fever application on victim.
            {
                float donePct = aurOld->GetDonePct();

                if (aurOld->GetEffect(EFFECT_0))
                {
                    caster->CastSpell(hitUnit, SPELL_DK_FROST_FEVER, true); // Spread the disease to hitUnit.

                    if (Aura* aurNew = hitUnit->GetAura(SPELL_DK_FROST_FEVER, caster->GetGUID())) // Check Frost Fever application on hitUnit.
                    {
                        aurNew->SetDonePct(donePct);
                        if (AuraEffect* aurEffNew = aurNew->GetEffect(EFFECT_0))
                            aurEffNew->ChangeAmount(aurEffNew->CalculateAmount(aurEffNew->GetCaster()), false);
                    }
                }
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_dk_pestilence::OnHit, EFFECT_2, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 48266 - Blood Presence
// 48263 - Frost Presence
// 48265 - Unholy Presence
class spell_dk_presence : public AuraScript
{
    PrepareAuraScript(spell_dk_presence);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_DK_BLOOD_PRESENCE,
            SPELL_DK_FROST_PRESENCE,
            SPELL_DK_UNHOLY_PRESENCE,
            SPELL_DK_IMPROVED_BLOOD_PRESENCE_R1,
            SPELL_DK_IMPROVED_FROST_PRESENCE_R1,
            SPELL_DK_IMPROVED_UNHOLY_PRESENCE_R1,
            SPELL_DK_IMPROVED_BLOOD_PRESENCE_TRIGGERED,
            SPELL_DK_IMPROVED_UNHOLY_PRESENCE_TRIGGERED,
            SPELL_DK_FROST_PRESENCE_TRIGGERED,
            SPELL_DK_UNHOLY_PRESENCE_TRIGGERED
        });
    }

    void HandleImprovedBloodPresence(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();

        if (GetId() == SPELL_DK_BLOOD_PRESENCE)
            target->CastSpell(target, SPELL_DK_IMPROVED_BLOOD_PRESENCE_TRIGGERED, true);
        else if (AuraEffect const* impAurEff = target->GetAuraEffectOfRankedSpell(SPELL_DK_IMPROVED_BLOOD_PRESENCE_R1, EFFECT_0))
            if (!target->HasAura(SPELL_DK_IMPROVED_BLOOD_PRESENCE_TRIGGERED))
            {
                CastSpellExtraArgs args(aurEff);
                args.AddSpellMod(SPELLVALUE_BASE_POINT1, impAurEff->GetAmount());
                target->CastSpell(target, SPELL_DK_IMPROVED_BLOOD_PRESENCE_TRIGGERED, args);
            }
    }

    void HandleImprovedFrostPresence(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();

        if (GetId() == SPELL_DK_FROST_PRESENCE)
            target->CastSpell(target, SPELL_DK_FROST_PRESENCE_TRIGGERED, true);
        else if (AuraEffect const* impAurEff = target->GetAuraEffectOfRankedSpell(SPELL_DK_IMPROVED_FROST_PRESENCE_R1, EFFECT_0))
            if (!target->HasAura(SPELL_DK_FROST_PRESENCE_TRIGGERED))
            {
                CastSpellExtraArgs args(aurEff);
                args.AddSpellBP0(impAurEff->GetAmount());
                target->CastSpell(target, SPELL_DK_FROST_PRESENCE_TRIGGERED, args);
            }
    }

    void HandleImprovedUnholyPresence(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();

        if (GetId() == SPELL_DK_UNHOLY_PRESENCE)
            target->CastSpell(target, SPELL_DK_UNHOLY_PRESENCE_TRIGGERED, true);

        if (AuraEffect const* impAurEff = target->GetAuraEffectOfRankedSpell(SPELL_DK_IMPROVED_UNHOLY_PRESENCE_R1, EFFECT_0))
        {
            if (GetId() == SPELL_DK_UNHOLY_PRESENCE)
            {
                // Not listed as any effect, only base points set
                int32 bp = impAurEff->GetSpellInfo()->GetEffect(EFFECT_1).CalcValue();
                CastSpellExtraArgs args(aurEff);
                for (uint32 i = 0; i < MAX_SPELL_EFFECTS; ++i)
                    args.AddSpellMod(SpellValueMod(SPELLVALUE_BASE_POINT0 + i), bp);
                target->CastSpell(target, SPELL_DK_IMPROVED_UNHOLY_PRESENCE_TRIGGERED, args);
            }
            else if (!target->HasAura(SPELL_DK_UNHOLY_PRESENCE_TRIGGERED))
            {
                CastSpellExtraArgs args(aurEff);
                args.AddSpellBP0(impAurEff->GetAmount());
                target->CastSpell(target, SPELL_DK_UNHOLY_PRESENCE_TRIGGERED, args);
            }
        }
    }

    void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->RemoveAura(SPELL_DK_IMPROVED_BLOOD_PRESENCE_TRIGGERED);
        target->RemoveAura(SPELL_DK_IMPROVED_UNHOLY_PRESENCE_TRIGGERED);
        target->RemoveAura(SPELL_DK_FROST_PRESENCE_TRIGGERED);
        target->RemoveAura(SPELL_DK_UNHOLY_PRESENCE_TRIGGERED);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_dk_presence::HandleImprovedBloodPresence, EFFECT_0, SPELL_AURA_ANY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectApply += AuraEffectApplyFn(spell_dk_presence::HandleImprovedFrostPresence, EFFECT_0, SPELL_AURA_ANY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectApply += AuraEffectApplyFn(spell_dk_presence::HandleImprovedUnholyPresence, EFFECT_0, SPELL_AURA_ANY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_dk_presence::HandleEffectRemove, EFFECT_0, SPELL_AURA_ANY, AURA_EFFECT_HANDLE_REAL);
    }
};

class RaiseDeadCheck
{
    public:
        explicit RaiseDeadCheck(Player const* caster) : _caster(caster) { }

        bool operator()(WorldObject* obj) const
        {
            if (Unit* target = obj->ToUnit())
            {
                if (!target->IsAlive()
                    && _caster->isHonorOrXPTarget(target)
                    && target->GetCreatureType() == CREATURE_TYPE_HUMANOID
                    && target->GetDisplayId() == target->GetNativeDisplayId())
                    return false;
            }

            return true;
        }

    private:
        Player const* _caster;
};

// 46584 - Raise Dead
class spell_dk_raise_dead : public SpellScript
{
    PrepareSpellScript(spell_dk_raise_dead);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo(
        {
            static_cast<uint32>(spellInfo->GetEffect(EFFECT_1).CalcValue()),
            static_cast<uint32>(spellInfo->GetEffect(EFFECT_2).CalcValue()),
            SPELL_DK_RAISE_DEAD_USE_REAGENT,
            SPELL_DK_MASTER_OF_GHOULS
        });
    }

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_PLAYER;
    }

    SpellCastResult CheckCast()
    {
        /// process spell target selection before cast starts
        /// targets of effect_1 are used to check cast
        GetSpell()->SelectSpellTargets();
        /// cleanup spell target map, and fill it again on normal way
        GetSpell()->CleanupTargetList();
        /// _result is set in spell target selection
        return _result;
    }

    SpellCastResult CheckReagents()
    {
        /// @workaround: there is no access to castresult of other spells, check it manually
        SpellInfo const* reagentSpell = sSpellMgr->AssertSpellInfo(SPELL_DK_RAISE_DEAD_USE_REAGENT);
        Player* player = GetCaster()->ToPlayer();
        if (!player->CanNoReagentCast(reagentSpell))
        {
            for (uint32 i = 0; i < MAX_SPELL_REAGENTS; i++)
            {
                if (reagentSpell->Reagent[i] <= 0)
                    continue;

                if (!player->HasItemCount(reagentSpell->Reagent[i], reagentSpell->ReagentCount[i]))
                {
                    Spell::SendCastResult(player, reagentSpell, 0, SPELL_FAILED_REAGENTS);
                    return SPELL_FAILED_DONT_REPORT;
                }
            }
        }
        return SPELL_CAST_OK;
    }

    void CheckTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if(RaiseDeadCheck(GetCaster()->ToPlayer()));

        if (targets.empty())
        {
            if (GetSpell()->getState() == SPELL_STATE_PREPARING)
                _result = CheckReagents();

            return;
        }

        WorldObject* target = Trinity::Containers::SelectRandomContainerElement(targets);
        targets.clear();
        targets.push_back(target);
        _corpse = true;
    }

    void CheckTarget(WorldObject*& target)
    {
        // Don't add caster to target map, if we found a corpse to raise dead
        if (_corpse)
            target = nullptr;
    }

    void ConsumeReagents()
    {
        // No corpse found, take reagents
        if (!_corpse)
            GetCaster()->CastSpell(GetCaster(), SPELL_DK_RAISE_DEAD_USE_REAGENT, TriggerCastFlags(TRIGGERED_FULL_MASK & ~TRIGGERED_IGNORE_POWER_AND_REAGENT_COST));
    }

    uint32 GetGhoulSpellId()
    {
        // Do we have talent Master of Ghouls?
        if (GetCaster()->HasAura(SPELL_DK_MASTER_OF_GHOULS))
            // summon as pet
            return GetSpellInfo()->GetEffect(EFFECT_2).CalcValue();

        // or guardian
        return GetSpellInfo()->GetEffect(EFFECT_1).CalcValue();
    }

    void HandleRaiseDead(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit()->GetPosition(), GetGhoulSpellId(), TRIGGERED_FULL_MASK);
    }

    void OverrideCooldown()
    {
        // Because the ghoul is summoned by one of triggered spells SendCooldownEvent is not sent for this spell
        // but the client has locked it by itself so we need some link between this spell and the real spell summoning.
        // Luckily such link already exists - spell category
        // This starts infinite category cooldown which can later be used by SendCooldownEvent to send packet for this spell
        GetCaster()->GetSpellHistory()->StartCooldown(GetSpellInfo(), 0, nullptr, true);
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_dk_raise_dead::CheckCast);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dk_raise_dead::CheckTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ENTRY);
        OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_dk_raise_dead::CheckTarget, EFFECT_2, TARGET_UNIT_CASTER);
        OnCast += SpellCastFn(spell_dk_raise_dead::ConsumeReagents);
        OnEffectHitTarget += SpellEffectFn(spell_dk_raise_dead::HandleRaiseDead, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
        OnEffectHitTarget += SpellEffectFn(spell_dk_raise_dead::HandleRaiseDead, EFFECT_2, SPELL_EFFECT_DUMMY);
        AfterCast += SpellCastFn(spell_dk_raise_dead::OverrideCooldown);
    }

    SpellCastResult _result = SPELL_CAST_OK;
    bool _corpse = false;
};

// -49188 - Rime
class spell_dk_rime : public AuraScript
{
    PrepareAuraScript(spell_dk_rime);

    bool CheckProc(ProcEventInfo& /*eventInfo*/)
    {
        return GetTarget()->GetTypeId() == TYPEID_PLAYER;
    }

    void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
    {
        GetTarget()->GetSpellHistory()->ResetCooldowns([](SpellHistory::CooldownStorageType::iterator itr) -> bool
        {
            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(itr->first);
            return spellInfo && spellInfo->GetCategory() == SPELL_CATEGORY_HOWLING_BLAST;
        }, true);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_dk_rime::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_dk_rime::HandleProc, EFFECT_1, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// 59754 Rune Tap - Party
class spell_dk_rune_tap_party : public SpellScript
{
    PrepareSpellScript(spell_dk_rune_tap_party);

    void CheckTargets(std::list<WorldObject*>& targets)
    {
        targets.remove(GetCaster());
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dk_rune_tap_party::CheckTargets, EFFECT_0, TARGET_UNIT_CASTER_AREA_PARTY);
    }
};

// 50421 - Scent of Blood
class spell_dk_scent_of_blood : public AuraScript
{
    PrepareAuraScript(spell_dk_scent_of_blood);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DK_SCENT_OF_BLOOD });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
        GetTarget()->CastSpell(GetTarget(), SPELL_DK_SCENT_OF_BLOOD, aurEff);
        ModStackAmount(-1);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_dk_scent_of_blood::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// -55090 - Scourge Strike (55265, 55270, 55271)
class spell_dk_scourge_strike : public SpellScript
{
    PrepareSpellScript(spell_dk_scourge_strike);

public:
    spell_dk_scourge_strike()
    {
        multiplier = 1.0f;
    }

private:
    float multiplier;

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DK_SCOURGE_STRIKE_TRIGGERED });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (Unit* unitTarget = GetHitUnit())
        {
            multiplier = (GetEffectValue() * unitTarget->GetDiseasesByCaster(caster->GetGUID()) / 100.f);
            // Death Knight T8 Melee 4P Bonus
            if (AuraEffect const* aurEff = caster->GetAuraEffect(SPELL_DK_ITEM_T8_MELEE_4P_BONUS, EFFECT_0))
                AddPct(multiplier, aurEff->GetAmount());
        }
    }

    void HandleAfterHit()
    {
        Unit* caster = GetCaster();
        if (Unit* unitTarget = GetHitUnit())
        {
            int32 bp = GetHitDamage() * multiplier;

            if (AuraEffect* aurEff = caster->GetAuraEffectOfRankedSpell(SPELL_DK_BLACK_ICE_R1, EFFECT_0))
                AddPct(bp, aurEff->GetAmount());

            CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
            args.AddSpellBP0(bp);
            caster->CastSpell(unitTarget, SPELL_DK_SCOURGE_STRIKE_TRIGGERED, args);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_dk_scourge_strike::HandleDummy, EFFECT_2, SPELL_EFFECT_DUMMY);
        AfterHit += SpellHitFn(spell_dk_scourge_strike::HandleAfterHit);
    }
};

// -49145 - Spell Deflection
class spell_dk_spell_deflection : public AuraScript
{
    PrepareAuraScript(spell_dk_spell_deflection);

public:
    spell_dk_spell_deflection()
    {
        absorbPct = 0;
    }

private:
    uint32 absorbPct;

    bool Load() override
    {
        absorbPct = GetEffectInfo(EFFECT_0).CalcValue(GetCaster());
        return true;
    }

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32 & amount, bool & /*canBeRecalculated*/)
    {
        // Set absorbtion amount to unlimited
        amount = -1;
    }

    void Absorb(AuraEffect* /*aurEff*/, DamageInfo & dmgInfo, uint32 & absorbAmount)
    {
        // You have a chance equal to your Parry chance
        if ((dmgInfo.GetDamageType() == SPELL_DIRECT_DAMAGE) && roll_chance_f(GetTarget()->GetFloatValue(PLAYER_PARRY_PERCENTAGE)))
            absorbAmount = CalculatePct(dmgInfo.GetDamage(), absorbPct);
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dk_spell_deflection::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
        OnEffectAbsorb += AuraEffectAbsorbFn(spell_dk_spell_deflection::Absorb, EFFECT_0);
    }
};

// -49018 - Sudden Doom
class spell_dk_sudden_doom : public AuraScript
{
    PrepareAuraScript(spell_dk_sudden_doom);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DK_DEATH_COIL_R1 });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        Unit* caster = eventInfo.GetActor();
        SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(SPELL_DK_DEATH_COIL_R1);
        uint32 spellId = 0;

        while (spellInfo)
        {
            if (!caster->HasSpell(spellInfo->Id))
                break;

            spellId = spellInfo->Id;
            spellInfo = spellInfo->GetNextRankSpell();
        }

        if (!spellId)
            return;

        caster->CastSpell(eventInfo.GetProcTarget(), spellId, aurEff);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_dk_sudden_doom::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// -65661 Threat of Thassarian
class spell_dk_threat_of_thassarian : public AuraScript
{
    PrepareAuraScript(spell_dk_threat_of_thassarian);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_DK_OBLITERATE_OFF_HAND_R1,
            SPELL_DK_FROST_STRIKE_OFF_HAND_R1,
            SPELL_DK_PLAGUE_STRIKE_OFF_HAND_R1,
            SPELL_DK_DEATH_STRIKE_OFF_HAND_R1,
            SPELL_DK_RUNE_STRIKE_OFF_HAND_R1,
            SPELL_DK_BLOOD_STRIKE_OFF_HAND_R1
        });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        if (!roll_chance_i(aurEff->GetAmount()))
            return;

        SpellInfo const* spellInfo = eventInfo.GetSpellInfo();
        if (!spellInfo)
            return;

        // Must dual wield
        Unit* caster = eventInfo.GetActor();
        if (!caster->haveOffhandWeapon())
            return;

        uint32 spellId = 0;
        // Plague Strike
        if (spellInfo->SpellFamilyFlags[0] & 0x00000001)
            spellId = SPELL_DK_PLAGUE_STRIKE_OFF_HAND_R1;
        // Death Strike
        else if (spellInfo->SpellFamilyFlags[0] & 0x00000010)
            spellId = SPELL_DK_DEATH_STRIKE_OFF_HAND_R1;
        // Blood Strike
        else if (spellInfo->SpellFamilyFlags[0] & 0x00400000)
            spellId = SPELL_DK_BLOOD_STRIKE_OFF_HAND_R1;
        // Frost Strike
        else if (spellInfo->SpellFamilyFlags[1] & 0x00000004)
            spellId = SPELL_DK_FROST_STRIKE_OFF_HAND_R1;
        // Obliterate
        else if (spellInfo->SpellFamilyFlags[1] & 0x00020000)
            spellId = SPELL_DK_OBLITERATE_OFF_HAND_R1;
        // Rune Strike
        else if (spellInfo->SpellFamilyFlags[1] & 0x20000000)
            spellId = SPELL_DK_RUNE_STRIKE_OFF_HAND_R1;

        if (!spellId)
            return;

        spellId = sSpellMgr->GetSpellWithRank(spellId, spellInfo->GetRank());
        caster->CastSpell(eventInfo.GetProcTarget(), spellId, aurEff);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_dk_threat_of_thassarian::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 49194 - Unholy Blight
class spell_dk_unholy_blight : public AuraScript
{
    PrepareAuraScript(spell_dk_unholy_blight);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_DK_UNHOLY_BLIGHT_DAMAGE,
            SPELL_DK_GLYPH_OF_UNHOLY_BLIGHT
        });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        DamageInfo* damageInfo = eventInfo.GetDamageInfo();
        if (!damageInfo || !damageInfo->GetDamage())
            return;

        Unit* caster = eventInfo.GetActor();
        Unit* target = eventInfo.GetProcTarget();

        SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(SPELL_DK_UNHOLY_BLIGHT_DAMAGE);
        int32 amount = CalculatePct(static_cast<int32>(damageInfo->GetDamage()), aurEff->GetAmount());
        if (AuraEffect const* glyph = caster->GetAuraEffect(SPELL_DK_GLYPH_OF_UNHOLY_BLIGHT, EFFECT_0, caster->GetGUID()))
            AddPct(amount, glyph->GetAmount());

        ASSERT(spellInfo->GetMaxTicks() > 0);
        amount /= spellInfo->GetMaxTicks();

        CastSpellExtraArgs args(aurEff);
        args.AddSpellBP0(amount);
        caster->CastSpell(target, SPELL_DK_UNHOLY_BLIGHT_DAMAGE, args);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_dk_unholy_blight::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 55233 - Vampiric Blood
class spell_dk_vampiric_blood : public AuraScript
{
    PrepareAuraScript(spell_dk_vampiric_blood);

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
    {
        amount = GetUnitOwner()->CountPctFromMaxHealth(amount);
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dk_vampiric_blood::CalculateAmount, EFFECT_1, SPELL_AURA_MOD_INCREASE_HEALTH);
    }
};

// -49015 - Vendetta
class spell_dk_vendetta : public AuraScript
{
    PrepareAuraScript(spell_dk_vendetta);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DK_VENDETTA_HEAL });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        Unit* const caster = eventInfo.GetActor();
        CastSpellExtraArgs args(aurEff);
        args.AddSpellBP0(caster->CountPctFromMaxHealth(aurEff->GetAmount()));
        caster->CastSpell(nullptr, SPELL_DK_VENDETTA_HEAL, args);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_dk_vendetta::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// -49217 - Wandering Plague
class spell_dk_wandering_plague : public AuraScript
{
    PrepareAuraScript(spell_dk_wandering_plague);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DK_WANDERING_PLAGUE_DAMAGE });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        Unit* caster = eventInfo.GetActor();
        Unit* target = eventInfo.GetProcTarget();
        if (!roll_chance_f(caster->GetUnitCriticalChanceAgainst(BASE_ATTACK, target)))
            return;

        DamageInfo* damageInfo = eventInfo.GetDamageInfo();
        if (!damageInfo || !damageInfo->GetDamage())
            return;

        int32 amount = CalculatePct(static_cast<int32>(damageInfo->GetDamage()), aurEff->GetAmount());
        CastSpellExtraArgs args(aurEff);
        args.AddSpellBP0(amount);
        caster->CastSpell(target, SPELL_DK_WANDERING_PLAGUE_DAMAGE, args);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_dk_wandering_plague::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 50526 - Wandering Plague (Damage)
class spell_dk_wandering_plague_damage : public SpellScript
{
    PrepareSpellScript(spell_dk_wandering_plague_damage);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([](WorldObject* object) -> bool
        {
            Unit* target = object->ToUnit();
            return target && target->HasBreakableByDamageCrowdControlAura();
        });
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dk_wandering_plague_damage::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
    }
};

// -52284 - Will of the Necropolis
class spell_dk_will_of_the_necropolis : public AuraScript
{
    PrepareAuraScript(spell_dk_will_of_the_necropolis);

    bool Validate(SpellInfo const* spellInfo) override
    {
        SpellInfo const* firstRankSpellInfo = sSpellMgr->GetSpellInfo(SPELL_DK_WILL_OF_THE_NECROPOLIS_AURA_R1);
        if (!firstRankSpellInfo)
            return false;

        // can't use other spell than will of the necropolis due to spell_ranks dependency
        if (!spellInfo->IsRankOf(firstRankSpellInfo))
            return false;

        uint8 rank = spellInfo->GetRank();
        if (!sSpellMgr->GetSpellWithRank(SPELL_DK_WILL_OF_THE_NECROPOLIS_TALENT_R1, rank, true))
            return false;

        return true;
    }

    uint32 absorbPct = 0;

    bool Load() override
    {
        absorbPct = GetEffectInfo(EFFECT_0).CalcValue(GetCaster());
        return true;
    }

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32 & amount, bool & /*canBeRecalculated*/)
    {
        // Set absorbtion amount to unlimited
        amount = -1;
    }

    void Absorb(AuraEffect* /*aurEff*/, DamageInfo & dmgInfo, uint32 & absorbAmount)
    {
        // min pct of hp is stored in effect 0 of talent spell
        uint8 rank = GetSpellInfo()->GetRank();
        SpellInfo const* talentProto = sSpellMgr->AssertSpellInfo(sSpellMgr->GetSpellWithRank(SPELL_DK_WILL_OF_THE_NECROPOLIS_TALENT_R1, rank));

        int32 remainingHp = int32(GetTarget()->GetHealth() - dmgInfo.GetDamage());
        int32 minHp = int32(GetTarget()->CountPctFromMaxHealth(talentProto->GetEffect(EFFECT_0).CalcValue(GetCaster())));

        // Damage that would take you below [effect0] health or taken while you are at [effect0]
        if (remainingHp < minHp)
            absorbAmount = CalculatePct(dmgInfo.GetDamage(), absorbPct);
    }

    void Register() override
    {
         DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dk_will_of_the_necropolis::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
         OnEffectAbsorb += AuraEffectAbsorbFn(spell_dk_will_of_the_necropolis::Absorb, EFFECT_0);
    }
};

// 49576 - Death Grip Initial
class spell_dk_death_grip_initial : public SpellScript
{
    PrepareSpellScript(spell_dk_death_grip_initial);

    SpellCastResult CheckCast()
    {
        Unit* caster = GetCaster();
        // Death Grip should not be castable while jumping/falling
        if (caster->HasUnitState(UNIT_STATE_JUMPING) || caster->HasUnitMovementFlag(MOVEMENTFLAG_FALLING))
            return SPELL_FAILED_MOVING;

        // Patch 3.3.3 (2010-03-23): Minimum range has been changed to 8 yards in PvP.
        Unit* target = GetExplTargetUnit();
        if (target && target->GetTypeId() == TYPEID_PLAYER)
            if (caster->GetDistance(target) < 8.f)
                return SPELL_FAILED_TOO_CLOSE;

        return SPELL_CAST_OK;
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_DK_DEATH_GRIP, true);
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_dk_death_grip_initial::CheckCast);
        OnEffectHitTarget += SpellEffectFn(spell_dk_death_grip_initial::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

enum RaiseAllyMisc
{
    TEXT_RISE_ALLY = 33055,

    SPELL_DK_RISEN_GHOUL_SELF_STUN = 47466,
    SPELL_DK_RISEN_GHOUL_SPAWN__IN = 47448,
    SPELL_DK_SUMMON_HEAL = 36492,
    SPELL_DK_DEATH_KNIGHT_RUNE_WEAPON_SCALING_02 = 51906,
    SPELL_DK_DEATH_KNIGHT_PET_SCALING_01 = 54566,
    SPELL_DK_DEATH_KNIGHT_PET_SCALING_03 = 61697,
    SPELL_DK_MIRROR_NAME = 62224,
    SPELL_DK_MIRROR_NAME_TRIGGERED = 62214,
    SPELL_DK_PET_SCALING___MASTER_SPELL_03___INTELLECT_SPIRIT_RESILIENCE = 67557,
    SPELL_DK_PET_SCALING___MASTER_SPELL_06___SPELL_HIT_EXPERTISE_SPELL_PENETRATION = 67561,

    SPELL_GHOUL_FRENZY = 62218,

    NPC_RISEN_ALLY = 30230
};

// 61999 - Raise Ally Initial
class spell_dk_raise_ally_initial : public SpellScript
{
    PrepareSpellScript(spell_dk_raise_ally_initial);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ static_cast<uint32>(spellInfo->GetEffect(EFFECT_0).CalcValue()) });
    }

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_PLAYER;
    }

    SpellCastResult CheckCast()
    {
        Unit* target = GetExplTargetUnit();
        if (!target)
            return SPELL_FAILED_NO_VALID_TARGETS;
        if (target->IsAlive())
            return SPELL_FAILED_TARGET_NOT_DEAD;
        if (target->IsGhouled())
            return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;
        return SPELL_CAST_OK;
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (Player* target = GetHitPlayer())
        {
            if (target->IsResurrectRequested()) // already have one active request
                return;
            target->SetResurrectRequestData(GetCaster(), 0, 0, uint32(GetEffectValue()));
            GetSpell()->SendResurrectRequest(target);
        }
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_dk_raise_ally_initial::CheckCast);
        OnEffectHitTarget += SpellEffectFn(spell_dk_raise_ally_initial::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class player_ghoulAI : public PlayerAI
{
    public:
        player_ghoulAI(Player* player, ObjectGuid ghoulGUID) : PlayerAI(player), _ghoulGUID(ghoulGUID), _ghoulCheckTimer(1000){ }

        void UpdateAI(uint32 diff) override
        {
            if (_ghoulCheckTimer <= diff)
            {
                _ghoulCheckTimer = 1000;

                Creature* ghoul = ObjectAccessor::GetCreature(*me, _ghoulGUID);
                if (!ghoul || !ghoul->IsAlive())
                    me->RemoveAura(SPELL_DK_RAISE_ALLY);
            }
            else
                _ghoulCheckTimer -= diff;
        }

    private:
        ObjectGuid _ghoulGUID;
        uint32 _ghoulCheckTimer;
};

// 46619 - Raise Ally
class spell_dk_raise_ally : public SpellScriptLoader
{
public:
    static char constexpr const ScriptName[] = "spell_dk_raise_ally";

    spell_dk_raise_ally() : SpellScriptLoader(ScriptName) { }

    class spell_dk_raise_ally_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dk_raise_ally_SpellScript);

        bool Load() override
        {
            return GetCaster()->GetTypeId() == TYPEID_PLAYER;
        }

        void SendText()
        {
            if (Unit* original = GetOriginalCaster())
                original->Unit::Whisper(TEXT_RISE_ALLY, GetCaster()->ToPlayer(), true);
        }

        void HandleSummon(SpellEffIndex effIndex)
        {
            PreventHitDefaultEffect(effIndex);

            Unit* caster = GetCaster();
            Unit* originalCaster = GetOriginalCaster();
            if (!originalCaster)
                return;

            uint32 entry = uint32(GetEffectInfo().MiscValue);

            //! HACK - StatSystem needs further develop to enable update on Puppet stats
            // Using same summon properties as Raise Dead 46585 (Guardian) - EffectMiscValueB = 829
            SummonPropertiesEntry const* properties = sSummonPropertiesStore.LookupEntry(829);

            uint32 duration = uint32(GetSpellInfo()->GetDuration());

            TempSummon* summon = originalCaster->GetMap()->SummonCreature(entry, *GetHitDest(), properties, duration, originalCaster, GetSpellInfo()->Id);
            if (!summon)
                return;

            //! Leaving this here as it's necessary if statsystem problem is solved
            /*
                Default SUMMON_CATEGORY_PUPPET behaviour sets possesor as originalCaster,
                in this case we need caster as possesor and originalCaster as owner
            */
            //summon->RemoveCharmedBy(nullptr);

            summon->SetCharmedBy(caster, CHARM_TYPE_POSSESS);

            summon->CastSpell(summon, SPELL_DK_RISEN_GHOUL_SELF_STUN, true);
            summon->CastSpell(summon, SPELL_DK_RISEN_GHOUL_SPAWN__IN, true);
            summon->CastSpell(summon, SPELL_DK_SUMMON_HEAL, true);
            summon->CastSpell(caster, SPELL_DK_MIRROR_NAME, true);
            caster->CastSpell(summon, SPELL_DK_MIRROR_NAME_TRIGGERED, true);
            summon->CastSpell(summon, SPELL_DK_DEATH_KNIGHT_RUNE_WEAPON_SCALING_02, true);
            summon->CastSpell(summon, SPELL_DK_DEATH_KNIGHT_PET_SCALING_01, true);
            summon->CastSpell(summon, SPELL_DK_DEATH_KNIGHT_PET_SCALING_03, true);
            summon->CastSpell(summon, SPELL_DK_PET_SCALING___MASTER_SPELL_03___INTELLECT_SPIRIT_RESILIENCE, true);
            summon->CastSpell(summon, SPELL_DK_PET_SCALING___MASTER_SPELL_06___SPELL_HIT_EXPERTISE_SPELL_PENETRATION, true);

            // SMSG_POWER_UPDATE is sent
            summon->SetMaxPower(POWER_ENERGY, 100);

            _ghoulGuid = summon->GetGUID();
        }

        void SetGhoul(SpellEffIndex /*effIndex*/)
        {
            if (Aura* aura = GetHitAura())
                if (spell_dk_raise_ally_AuraScript* script = aura->GetScript<spell_dk_raise_ally_AuraScript>(ScriptName))
                    script->SetGhoulGuid(_ghoulGuid);
        }

        void Register() override
        {
            AfterHit += SpellHitFn(spell_dk_raise_ally_SpellScript::SendText);
            OnEffectHit += SpellEffectFn(spell_dk_raise_ally_SpellScript::HandleSummon, EFFECT_0, SPELL_EFFECT_SUMMON);
            OnEffectHitTarget += SpellEffectFn(spell_dk_raise_ally_SpellScript::SetGhoul, EFFECT_1, SPELL_EFFECT_APPLY_AURA);
        }

    private:
        ObjectGuid _ghoulGuid;
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dk_raise_ally_SpellScript();
    }

    class spell_dk_raise_ally_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dk_raise_ally_AuraScript);

    public:
        void SetGhoulGuid(ObjectGuid guid)
        {
            ghoulGuid = guid;
        }

    private:
        bool Load() override
        {
            return GetUnitOwner()->GetTypeId() == TYPEID_PLAYER;
        }

        void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Player* player = GetTarget()->ToPlayer();
            if (ghoulGuid.IsEmpty())
                return;

            player->PushAI(new player_ghoulAI(player, ghoulGuid));
        }

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Player* player = GetTarget()->ToPlayer();

            player->PopAI();

            // Dismiss ghoul if necessary
            if (Creature* ghoul = ObjectAccessor::GetCreature(*player, ghoulGuid))
            {
                ghoul->RemoveCharmedBy(player);
                ghoul->DespawnOrUnsummon(1s);
            }

            player->ClearResurrectRequestData();
            player->RemoveAura(SPELL_GHOUL_FRENZY);
        }

        void Register() override
        {
            AfterEffectApply += AuraEffectApplyFn(spell_dk_raise_ally_AuraScript::OnApply, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            AfterEffectRemove += AuraEffectRemoveFn(spell_dk_raise_ally_AuraScript::OnRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }

        ObjectGuid ghoulGuid;
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dk_raise_ally_AuraScript();
    }
};
char constexpr const spell_dk_raise_ally::ScriptName[];

// 47480 - Thrash
class spell_dk_ghoul_thrash : public SpellScript
{
    PrepareSpellScript(spell_dk_ghoul_thrash);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_GHOUL_FRENZY });
    }

    void CalcDamage(SpellEffIndex /*effIndex*/)
    {
        /*
        Causes more damage per frenzy point:
           1 point   : ${$AP*$m1*0.01+$AP*0.05}-${$AP*$m1*0.01+$AP*0.10} damage
           2 points  : ${$AP*$m1*0.01+$AP*0.10}-${$AP*$m1*0.01+$AP*0.20} damage
           3 points  : ${$AP*$m1*0.01+$AP*0.15}-${$AP*$m1*0.01+$AP*0.30} damage
           4 points  : ${$AP*$m1*0.01+$AP*0.20}-${$AP*$m1*0.01+$AP*0.40} damage
           5 points  : ${$AP*$m1*0.01+$AP*0.25}-${$AP*$m1*0.01+$AP*0.50} damage
        */

        if (Aura* frenzy = GetCaster()->GetAura(SPELL_GHOUL_FRENZY))
        {
            float APBonus = GetCaster()->GetTotalAttackPowerValue(BASE_ATTACK);
            float fixedDamageBonus = APBonus * GetEffectValue() * 0.01f;
            APBonus *= 0.05f * frenzy->GetStackAmount();

            frenzy->Remove(AURA_REMOVE_BY_ENEMY_SPELL);
            SetEffectValue(fixedDamageBonus + irand(int32(APBonus), int32(APBonus * 2.f)));
        }

        /*
            Also remove aura from charmer
            SPELL_GHOUL_FRENZY (62218) - Targets (1, 27) (TARGET_UNIT_CASTER, TARGET_UNIT_MASTER)
        */
        if (Unit* charmer = GetCaster()->GetCharmer())
            charmer->RemoveAura(SPELL_GHOUL_FRENZY);
    }

    void Register() override
    {
        OnEffectLaunchTarget += SpellEffectFn(spell_dk_ghoul_thrash::CalcDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

#define DKBloodTapScriptName "spell_dk_blood_tap"

// 45529 - Blood Tap
class spell_dk_blood_tap : public SpellScriptLoader
{
public:
    spell_dk_blood_tap() : SpellScriptLoader(DKBloodTapScriptName) { }

    class spell_dk_blood_tap_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dk_blood_tap_AuraScript);

    public:
        spell_dk_blood_tap_AuraScript()
        {
            _runeIndex = MAX_RUNES;
        }

        void SetRuneIndex(uint8 index)
        {
            _runeIndex = index;
        }

        void HandleApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
        {
            PreventDefaultAction();

            Player* player = GetTarget()->ToPlayer();
            if (!player)
                return;

            if (player->GetClass() != CLASS_DEATH_KNIGHT || _runeIndex == MAX_RUNES)
                return;

            player->AddRuneByAuraEffect(_runeIndex, RUNE_DEATH, aurEff);
        }

        void Register() override
        {
            OnEffectApply += AuraEffectApplyFn(spell_dk_blood_tap_AuraScript::HandleApply, EFFECT_1, SPELL_AURA_CONVERT_RUNE, AURA_EFFECT_HANDLE_REAL);
        }

    private:
        uint8 _runeIndex;
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dk_blood_tap_AuraScript();
    }

    class spell_dk_blood_tap_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dk_blood_tap_SpellScript);

    public:
        spell_dk_blood_tap_SpellScript()
        {
            _runeIndex = MAX_RUNES;
        }

        void HandleEffect(SpellEffIndex effIndex)
        {
            PreventHitDefaultEffect(effIndex);

            Unit* caster = GetCaster();
            if (caster->GetTypeId() != TYPEID_PLAYER)
                return;

            Player* player = caster->ToPlayer();
            if (player->GetClass() != CLASS_DEATH_KNIGHT)
                return;

            // needed later
            if (Spell* spell = GetSpell())
                spell->SetRuneState(caster->ToPlayer()->GetRunesState());

            uint8 resetIndex;
            // Rune reset:
            // If both runes are on cooldown, reset the shorter one
            // If only one rune is on cooldown, reset that rune
            if (!player->GetRuneCooldown(1))
                resetIndex = 0; // 1 is ready, so reset 0 (no matter if it's on cd)
            else if (!player->GetRuneCooldown(0) || player->GetRuneCooldown(1) < player->GetRuneCooldown(0))
                resetIndex = 1; // 0 is ready, or both are on cd and 1 is shorter, so reset 1
            else
                resetIndex = 0; // both are on cd and 0 is shorter, reset 0

            // if both runes are the same type, transform the same one as above
            if (player->GetCurrentRune(0) == player->GetCurrentRune(1))
                _runeIndex = resetIndex;
            else // otherwise transform the blood rune
                _runeIndex = player->GetCurrentRune(0) == RUNE_BLOOD ? 0 : 1;

            player->SetRuneCooldown(resetIndex, 0);
        }

        void SetRuneIndex(SpellEffIndex /*effIndex*/)
        {
            if (Aura* aura = GetHitAura())
                if (spell_dk_blood_tap_AuraScript* script = aura->GetScript<spell_dk_blood_tap_AuraScript>(DKBloodTapScriptName))
                    script->SetRuneIndex(_runeIndex);
        }

        void Register() override
        {
            OnEffectLaunch += SpellEffectFn(spell_dk_blood_tap_SpellScript::HandleEffect, EFFECT_0, SPELL_EFFECT_ACTIVATE_RUNE);
            OnEffectHitTarget += SpellEffectFn(spell_dk_blood_tap_SpellScript::SetRuneIndex, EFFECT_1, SPELL_EFFECT_APPLY_AURA);
        }

    private:
        uint8 _runeIndex;
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dk_blood_tap_SpellScript();
    }
};

// 51963 - Gargoyle Strike
class spell_pet_dk_gargoyle_strike : public SpellScript
{
    PrepareSpellScript(spell_pet_dk_gargoyle_strike);

    void HandleDamageCalc(SpellEffIndex /*effIndex*/)
    {
        int32 damage = 60;
        if (Unit* caster = GetCaster())
        {
            if (caster->GetLevel() >= 60)
                damage += (caster->GetLevel() - 60) * 4;
        }

        SetEffectValue(damage);
    }

    void Register() override
    {
        OnEffectLaunchTarget += SpellEffectFn(spell_pet_dk_gargoyle_strike::HandleDamageCalc, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

enum DancingRuneWeaponMisc
{
    DATA_INITIAL_TARGET_GUID = 1,
};

// 49028 - Dancing Rune Weapon
class spell_dk_dancing_rune_weapon : public AuraScript
{
    PrepareAuraScript(spell_dk_dancing_rune_weapon);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({
            SPELL_DK_BLOOD_STRIKE,
            SPELL_DK_ICY_TOUCH,
            SPELL_DK_PLAGUE_STRIKE,
            SPELL_DK_DEATH_COIL_DAMAGE,
            SPELL_DK_DEATH_STRIKE,
            SPELL_DK_HEART_STRIKE,
            SPELL_DK_OBLITERATE,
            SPELL_DK_RUNE_STRIKE
        });
    }

    void HandleTarget(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        std::list<Creature*> runeWeapons;
        caster->GetAllMinionsByEntry(runeWeapons, NPC_DK_DANCING_RUNE_WEAPON);
        for (Creature* temp : runeWeapons)
        {
            if (temp->IsAIEnabled())
                temp->AI()->SetGUID(GetTarget()->GetGUID(), DATA_INITIAL_TARGET_GUID);
            temp->GetThreatManager().RegisterRedirectThreat(GetId(), caster->GetGUID(), 100);
        }
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        if (SpellInfo const* procSpell = eventInfo.GetSpellInfo())
        {
            if (procSpell->IsRankOf(sSpellMgr->GetSpellInfo(SPELL_DK_BLOOD_STRIKE)) ||
                procSpell->IsRankOf(sSpellMgr->GetSpellInfo(SPELL_DK_ICY_TOUCH)) ||
                procSpell->IsRankOf(sSpellMgr->GetSpellInfo(SPELL_DK_PLAGUE_STRIKE)) ||
                procSpell->IsRankOf(sSpellMgr->GetSpellInfo(SPELL_DK_DEATH_COIL_DAMAGE)) ||
                procSpell->IsRankOf(sSpellMgr->GetSpellInfo(SPELL_DK_DEATH_STRIKE)) ||
                procSpell->IsRankOf(sSpellMgr->GetSpellInfo(SPELL_DK_HEART_STRIKE)) ||
                procSpell->IsRankOf(sSpellMgr->GetSpellInfo(SPELL_DK_OBLITERATE)) ||
                procSpell->IsRankOf(sSpellMgr->GetSpellInfo(SPELL_DK_RUNE_STRIKE)))
                return true;
        }

        return false;
    }

    void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        Unit* owner = GetUnitOwner();
        if (!owner)
            return;

        SpellInfo const* procSpell = eventInfo.GetSpellInfo();
        Unit* runeWeapon = nullptr;
        for (auto itr = owner->m_Controlled.begin(); itr != owner->m_Controlled.end() && !runeWeapon; itr++)
            if ((*itr)->GetEntry() == NPC_DK_DANCING_RUNE_WEAPON)
                runeWeapon = *itr;

        if (!runeWeapon)
            return;

        if (runeWeapon->IsInCombat() && runeWeapon->GetVictim())
            runeWeapon->CastSpell(runeWeapon->GetVictim(), procSpell->Id, CastSpellExtraArgs(TriggerCastFlags::TRIGGERED_IGNORE_POWER_AND_REAGENT_COST));
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_dk_dancing_rune_weapon::HandleTarget, EFFECT_2, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        DoCheckProc += AuraCheckProcFn(spell_dk_dancing_rune_weapon::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_dk_dancing_rune_weapon::HandleProc, EFFECT_1, SPELL_AURA_DUMMY);
    }
};

void AddSC_deathknight_spell_scripts()
{
    RegisterSpellScript(spell_dk_acclimation);
    RegisterSpellScript(spell_dk_advantage_t10_4p);
    RegisterSpellScript(spell_dk_anti_magic_shell_raid);
    RegisterSpellScript(spell_dk_anti_magic_shell_self);
    RegisterSpellScript(spell_dk_anti_magic_zone);
    RegisterSpellScript(spell_dk_blade_barrier);
    RegisterSpellScript(spell_dk_blood_boil);
    RegisterSpellScript(spell_dk_blood_gorged);
    RegisterSpellScript(spell_dk_bloodworms);
    RegisterSpellScript(spell_dk_butchery);
    RegisterSpellScript(spell_dk_corpse_explosion);
    RegisterSpellScript(spell_dk_death_and_decay);
    RegisterSpellScript(spell_dk_death_coil);
    RegisterSpellScript(spell_dk_death_gate);
    RegisterSpellScript(spell_dk_death_grip);
    RegisterSpellScript(spell_dk_death_pact);
    RegisterSpellScript(spell_dk_death_rune);
    RegisterSpellScript(spell_dk_death_strike);
    RegisterSpellScript(spell_dk_ghoul_explode);
    RegisterSpellScript(spell_dk_glyph_of_death_grip);
    RegisterSpellScript(spell_dk_glyph_of_scourge_strike);
    RegisterSpellScript(spell_dk_glyph_of_scourge_strike_script);
    RegisterSpellScript(spell_dk_hysteria);
    RegisterSpellScript(spell_dk_frost_fever);
    RegisterSpellScript(spell_dk_hungering_cold);
    RegisterSpellScript(spell_dk_icebound_fortitude);
    RegisterSpellScript(spell_dk_improved_blood_presence);
    RegisterSpellScript(spell_dk_improved_blood_presence_triggered);
    RegisterSpellScript(spell_dk_improved_frost_presence);
    RegisterSpellScript(spell_dk_improved_unholy_presence);
    RegisterSpellScript(spell_dk_pvp_4p_bonus);
    RegisterSpellScript(spell_dk_mark_of_blood);
    RegisterSpellScript(spell_dk_necrosis);
    RegisterSpellScript(spell_dk_pestilence);
    RegisterSpellScript(spell_dk_presence);
    RegisterSpellScript(spell_dk_raise_dead);
    RegisterSpellScript(spell_dk_rime);
    RegisterSpellScript(spell_dk_rune_tap_party);
    RegisterSpellScript(spell_dk_scent_of_blood);
    RegisterSpellScript(spell_dk_scourge_strike);
    RegisterSpellScript(spell_dk_spell_deflection);
    RegisterSpellScript(spell_dk_sudden_doom);
    RegisterSpellScript(spell_dk_threat_of_thassarian);
    RegisterSpellScript(spell_dk_unholy_blight);
    RegisterSpellScript(spell_dk_vampiric_blood);
    RegisterSpellScript(spell_dk_vendetta);
    RegisterSpellScript(spell_dk_wandering_plague);
    RegisterSpellScript(spell_dk_wandering_plague_damage);
    RegisterSpellScript(spell_dk_will_of_the_necropolis);
    RegisterSpellScript(spell_dk_death_grip_initial);
    RegisterSpellScript(spell_dk_raise_ally_initial);
    new spell_dk_raise_ally();
    RegisterSpellScript(spell_dk_ghoul_thrash);
    new spell_dk_blood_tap();
    RegisterSpellScript(spell_pet_dk_gargoyle_strike);
    RegisterSpellScript(spell_dk_dancing_rune_weapon);
}
