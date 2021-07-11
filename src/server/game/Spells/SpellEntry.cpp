#include "SpellEntry.h"
#include "SharedDefines.h"
#include "SpellAuraDefines.h"
#include "SpellMgr.h"
#include "Spell.h"

using namespace Spells;

SpellSpecific Spells::GetSpellSpecific(uint32 spellId)
{
    SpellEntry const* spellInfo = sSpellMgr.GetSpellEntry(spellId);
    if (!spellInfo)
        return SPELL_NORMAL;

    switch (spellInfo->SpellFamilyName)
    {
        case SPELLFAMILY_GENERIC:
        {
            // Aspect of the Beast
            if (spellInfo->Id == 13161)
                return SPELL_ASPECT;

            // Food / Drinks (mostly)
            if (spellInfo->AuraInterruptFlags & AURA_INTERRUPT_FLAG_NOT_SEATED)
            {
                bool food = false;
                bool drink = false;
                for (uint32 i : spellInfo->EffectApplyAuraName)
                {
                    switch (i)
                    {
                        // Food
                        case SPELL_AURA_MOD_REGEN:
                        case SPELL_AURA_OBS_MOD_HEALTH:
                            food = true;
                            break;
                        // Drink
                        case SPELL_AURA_MOD_POWER_REGEN:
                        case SPELL_AURA_OBS_MOD_MANA:
                            drink = true;
                            break;
                        default:
                            break;
                    }
                }

                if (food && drink)
                    return SPELL_FOOD_AND_DRINK;
                else if (food)
                    return SPELL_FOOD;
                else if (drink)
                    return SPELL_DRINK;
            }
            else
            {
                // Well Fed buffs (must be exclusive with Food / Drink replenishment effects, or else Well Fed will cause them to be removed)
                if (spellInfo->AttributesEx2 & SPELL_ATTR_EX2_FOOD_BUFF)
                    return SPELL_WELL_FED;
            }
            break;
        }
        case SPELLFAMILY_MAGE:
        {
            // family flags 18(Molten), 25(Frost/Ice), 28(Mage)
            if (spellInfo->SpellFamilyFlags & UI64LIT(0x12000000))
                return SPELL_MAGE_ARMOR;

            if (spellInfo->EffectApplyAuraName[EFFECT_INDEX_0] == SPELL_AURA_MOD_CONFUSE && spellInfo->PreventionType == SPELL_PREVENTION_TYPE_SILENCE)
                return SPELL_MAGE_POLYMORPH;

            break;
        }
        case SPELLFAMILY_WARRIOR:
        {
            if (spellInfo->SpellFamilyFlags & UI64LIT(0x00008000010000))
                return SPELL_POSITIVE_SHOUT;

            break;
        }
        case SPELLFAMILY_WARLOCK:
        {
            // only warlock curses have this
            if (spellInfo->Dispel == DISPEL_CURSE)
                return SPELL_CURSE;
            break;
        }
        case SPELLFAMILY_PRIEST:
        {
            // "Well Fed" buff from Blessed Sunfruit, Blessed Sunfruit Juice, Alterac Spring Water
            if ((spellInfo->Attributes & SPELL_ATTR_CASTABLE_WHILE_SITTING) &&
                    (spellInfo->InterruptFlags & SPELL_INTERRUPT_FLAG_COMBAT) &&
                    (spellInfo->SpellIconID == 52 || spellInfo->SpellIconID == 79))
                return SPELL_WELL_FED;
            break;
        }
        case SPELLFAMILY_HUNTER:
        {
            // only hunter stings have this
            if (spellInfo->Dispel == DISPEL_POISON)
                return SPELL_STING;

            // only hunter aspects have this (one have generic family), if exclude Auto Shot
            if (spellInfo->activeIconID == 122 && spellInfo->Id != 75)
                return SPELL_ASPECT;

            break;
        }
        case SPELLFAMILY_PALADIN:
        {
            if (spellInfo->IsSealSpell())
                return SPELL_SEAL;

            if (spellInfo->IsFitToFamilyMask(UI64LIT(0x0000000010000100)))
                return SPELL_BLESSING;

            if ((spellInfo->IsFitToFamilyMask(UI64LIT(0x0000000020180400))) && spellInfo->baseLevel != 0)
                return SPELL_JUDGEMENT;

            // Old Judgement of Command
            if (spellInfo->SpellIconID == 561 && spellInfo->SpellVisual == 5652)
                return SPELL_JUDGEMENT;

            for (uint32 i : spellInfo->Effect)
            {
                // only paladin auras have this
                if (i == SPELL_EFFECT_APPLY_AREA_AURA_PARTY)
                    return SPELL_AURA;
            }
            break;
        }
        case SPELLFAMILY_SHAMAN:
        {
            if (spellInfo->IsElementalShield())
                return SPELL_ELEMENTAL_SHIELD;

            break;
        }

        case SPELLFAMILY_POTION:
            return sSpellMgr.GetSpellElixirSpecific(spellInfo->Id);
    }

    // only warlock armor/skin have this (in additional to family cases)
    if (spellInfo->SpellVisual == 130 && spellInfo->SpellIconID == 89)
        return SPELL_WARLOCK_ARMOR;

    // Tracking spells (exclude Well Fed, some other always allowed cases)
    if ((spellInfo->HasAura(SPELL_AURA_TRACK_CREATURES) ||
            spellInfo->HasAura(SPELL_AURA_TRACK_RESOURCES)  ||
            spellInfo->HasAura(SPELL_AURA_TRACK_STEALTHED)) &&
            ((spellInfo->AttributesEx & SPELL_ATTR_EX_NOT_RESET_AUTO_ACTIONS) || (spellInfo->Attributes & SPELL_ATTR_CASTABLE_WHILE_MOUNTED)))
        return SPELL_TRACKER;

    // elixirs can have different families, but potion most ofc.
    if (SpellSpecific sp = sSpellMgr.GetSpellElixirSpecific(spellInfo->Id))
        return sp;

    // Attack speed reduction
    if (spellInfo->HasSingleAura(SPELL_AURA_MOD_MELEE_HASTE))
        for (uint8 i = 0; i < MAX_EFFECT_INDEX; ++i)
            if (AuraType(spellInfo->EffectApplyAuraName[i]) == SPELL_AURA_MOD_MELEE_HASTE && spellInfo->EffectBasePoints[i] < 0)
                return SPELL_NEGATIVE_HASTE;

    // Movement speed reduction
    // Dazes are not affected
    if (spellInfo->HasSingleAura(SPELL_AURA_MOD_DECREASE_SPEED) && !(spellInfo->AttributesEx & SPELL_ATTR_EX_UNK18))
        return SPELL_SNARE;

    return SPELL_NORMAL;
}

int32 Spells::CompareAuraRanks(uint32 spellId_1, uint32 spellId_2)
{
    SpellEntry const*spellInfo_1 = sSpellMgr.GetSpellEntry(spellId_1);
    SpellEntry const*spellInfo_2 = sSpellMgr.GetSpellEntry(spellId_2);
    if (!spellInfo_1 || !spellInfo_2) return 0;
    if (spellId_1 == spellId_2) return 0;

    for (uint8 i = 0; i < MAX_EFFECT_INDEX; ++i)
    {
        if (spellInfo_1->Effect[i] != 0 && spellInfo_2->Effect[i] != 0 && spellInfo_1->Effect[i] == spellInfo_2->Effect[i])
        {
            int32 diff = spellInfo_1->EffectBasePoints[i] - spellInfo_2->EffectBasePoints[i];
            if (spellInfo_1->CalculateSimpleValue(SpellEffectIndex(i)) < 0 && spellInfo_2->CalculateSimpleValue(SpellEffectIndex(i)) < 0)
                return -diff;
            else return diff;
        }
    }
    return 0;
}

bool Spells::CompareSpellSpecificAuras(SpellEntry const* spellInfo_1, SpellEntry const* spellInfo_2)
{
    if (!spellInfo_1 || !spellInfo_2) return 0;
    if (spellInfo_1 == spellInfo_2) return 0;

    for (uint8 i = 0; i < MAX_EFFECT_INDEX; ++i)
    {
        for (uint8 j = 0; j < MAX_EFFECT_INDEX; ++j)
        {
            if (spellInfo_1->Effect[i] == SPELL_EFFECT_APPLY_AURA
                && spellInfo_1->EffectApplyAuraName[i] == spellInfo_2->EffectApplyAuraName[j])
            {
                if (spellInfo_1->EffectBasePoints[i] < spellInfo_2->EffectBasePoints[j] && spellInfo_2->EffectBasePoints[j] < 0)
                    return true;
                else if (spellInfo_1->EffectBasePoints[i] > spellInfo_2->EffectBasePoints[j] && spellInfo_2->EffectBasePoints[j] >= 0)
                    return true;
                else if (spellInfo_1->EffectBasePoints[i] == spellInfo_2->EffectBasePoints[j] && spellInfo_1->GetDuration() >= spellInfo_2->GetDuration())
                    return true;
            }
        }
    }

    return false;
}

bool Spells::IsPassiveSpell(uint32 spellId)
{
    SpellEntry const* spellInfo = sSpellMgr.GetSpellEntry(spellId);
    if (!spellInfo)
        return false;
    return spellInfo->IsPassiveSpell();
}

bool Spells::IsPositiveSpell(uint32 spellId)
{
    SpellEntry const* spellproto = sSpellMgr.GetSpellEntry(spellId);
    if (!spellproto)
        return false;

    return spellproto->IsPositiveSpell();
}

bool Spells::IsPositiveSpell(uint32 spellId, Unit* caster, Unit* victim)
{
    SpellEntry const* spellproto = sSpellMgr.GetSpellEntry(spellId);
    if (!spellproto)
        return false;

    return spellproto->IsPositiveSpell(caster, victim);
}

bool Spells::IsSingleTargetSpells(SpellEntry const* spellInfo1, SpellEntry const* spellInfo2)
{
    // TODO - need better check
    // Equal icon and spellfamily
    if (spellInfo1->SpellFamilyName == spellInfo2->SpellFamilyName &&
            spellInfo1->SpellIconID == spellInfo2->SpellIconID)
        return true;

    // TODO - need found Judgements rule
    SpellSpecific spec1 = GetSpellSpecific(spellInfo1->Id);
    // spell with single target specific types
    switch (spec1)
    {
        case SPELL_JUDGEMENT:
        case SPELL_MAGE_POLYMORPH:
            if (GetSpellSpecific(spellInfo2->Id) == spec1)
                return true;
            break;
        default:
            break;
    }

    return false;
}

void SpellEntry::InitCachedValues()
{
    ComputeBinary();
    ComputeDispel();
    ComputeNonPeriodicDispel();
}

void SpellEntry::ComputeBinary()
{
    _isBinary = false;
    // Les sorts non magiques ne sont pas concernes.
    if (DmgClass != SPELL_DAMAGE_CLASS_MAGIC)
        return;

    // Pareil pour les sorts physiques (charges)
    if (School == SPELL_SCHOOL_NORMAL)
        return;

    bool foundNoDamageAura   = false;
    for (int eff = 0; eff < 3; ++eff)
    {
        // Micro opt - don't iterate anymore if we already have an aura
        if (foundNoDamageAura)
            break;
        
        switch (Effect[eff])
        {
            case SPELL_EFFECT_INTERRUPT_CAST:
                foundNoDamageAura = true;
                break;
            case SPELL_EFFECT_APPLY_AURA:
                switch (EffectApplyAuraName[eff])
                {
                    case SPELL_AURA_MOD_DECREASE_SPEED:
                    case SPELL_AURA_MOD_FEAR:
                    case SPELL_AURA_MOD_STUN:
                    case SPELL_AURA_MOD_PACIFY:
                    case SPELL_AURA_MOD_ROOT:
                    case SPELL_AURA_MOD_SILENCE:
                    case SPELL_AURA_MOD_DISARM:
                    case SPELL_AURA_MOD_RESISTANCE:
                    case SPELL_AURA_MOD_DAMAGE_TAKEN:
                        foundNoDamageAura = true;
                        break;
                }
                break;
            case SPELL_EFFECT_KNOCK_BACK:
                foundNoDamageAura = true;
                break;
        }
    }
    _isBinary = foundNoDamageAura;
    if (Id == 26143) {              // SPELL_MIND_FLAY (C'Thuns Eye Tentacles)
        _isBinary = true;
    }
    else if (Id == 26478) {
        _isBinary = true;           // SPELL_GROUND_RUPTURE_NATURE (C'thuns Giant tentacles ground rupture)
    }
}

void SpellEntry::ComputeNonPeriodicDispel()
{
    _isNonPeriodicDispel = true;
    for (int i = 0; i < 3; ++i)
        if (_isNonPeriodicDispel && Effect[i] != 0 && (Effect[i] != SPELL_EFFECT_DISPEL || EffectRadiusIndex[i] != 0))
            _isNonPeriodicDispel = false;
}

void SpellEntry::ComputeDispel()
{
    _isDispel = false;
    for (uint32 i : Effect)
    {
        if (i == SPELL_EFFECT_DISPEL)
        {
            _isDispel = true;
            break;
        }
    }
}
DiminishingGroup SpellEntry::GetDiminishingReturnsGroup(bool triggered) const
{
    // Explicit Diminishing Groups
    switch (SpellFamilyName)
    {
        case SPELLFAMILY_ROGUE:
        {
            // Kidney Shot
            if (IsFitToFamilyMask<CF_ROGUE_KIDNEY_SHOT>())
                return DIMINISHING_KIDNEYSHOT;
            // Blind
            else if (IsFitToFamilyMask<CF_ROGUE_BLIND>())
                return DIMINISHING_NONE;
            break;
        }
        case SPELLFAMILY_HUNTER:
        {
            // World of Warcraft Client Patch 1.10.0 (2006-03-28)
            // - Freezing Traps are now affected by diminishing returns.
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_9_4
            // Freezing trap
            if (IsFitToFamilyMask<CF_HUNTER_FREEZING_TRAP_EFFECT>())
                return DIMINISHING_FREEZE;
#endif
            break;
        }
        case SPELLFAMILY_WARLOCK:
        {
            // Fear
            if (IsFitToFamilyMask<CF_WARLOCK_MISC_DEBUFFS>() && Mechanic == MECHANIC_FEAR)
                return DIMINISHING_WARLOCK_FEAR;

            // World of Warcraft Client Patch 1.4.0 (2005-04-19)
            // - Seduction (Succubus) - Is now considered a Fear effect for purposes 
            //   of diminishing returns.
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_3_1
            // Seduction
            if (Id == 6358)
                return DIMINISHING_WARLOCK_FEAR;
#endif
            // Curses/etc
            if (IsFitToFamilyMask<CF_WARLOCK_MISC_DEBUFFS>())
                return DIMINISHING_LIMITONLY;
            break;
        }
        case SPELLFAMILY_WARRIOR:
        {
            // Hamstring - limit duration to 10s in PvP
            if (IsFitToFamilyMask<CF_WARRIOR_HAMSTRING>())
                return DIMINISHING_LIMITONLY;
            break;
        }
        case SPELLFAMILY_SHAMAN:
        {
            // World of Warcraft Client Patch 1.4.0 (2005-04-19)
            // - Frost Shock - Now subject to diminishing returns in PvP. This is 
            //   considered a slowing effect.
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_3_1
            // Frost Shock
            if (IsFitToFamilyMask<CF_SHAMAN_FROST_SHOCK>())
                return DIMINISHING_CONTROL_ROOT;
#endif
            break;
        }
        case SPELLFAMILY_MAGE:
        {
            // Ice Block
            if (SpellVisual == 4325)
                return DIMINISHING_NONE;
            break;
        }
        case SPELLFAMILY_GENERIC:
        {
            // World of Warcraft Client Patch 1.9.0 (2006-01-03)
            // - Pyroclasm - The stun effect's duration no longer diminishes or is 
            //   diminished by controlled stun abilities and spells(e.g.Cheap Shot,
            //   Hammer of Justice, Charge, etc).
            // - Impact - The stun effect's duration no longer diminishes or is 
            //   diminished by controlled stun abilities and spells(e.g.Cheap Shot,
            //   Hammer of Justice, Charge etc.).
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
            // Impact
            if (Id == 12355)
                return DIMINISHING_TRIGGER_STUN;
            // Pyroclasm
            if (Id == 18093)
                return DIMINISHING_TRIGGER_STUN;
#endif
            // World of Warcraft Client Patch 1.8.0 (2005-10-11)
            // - Gnomish Mind Control Cap - Is now subject to diminishing returns in 
            //   the Charm category.
#if SUPPORTED_CLIENT_BUILD <= CLIENT_BUILD_1_7_1
            // Gnomish Mind Control Cap
            if (Id == 13181)
                return DIMINISHING_NONE;
#endif
            break;
        }

        default:
            break;
    }

    // No distinction between triggered and controlled CC before 1.9.
#if SUPPORTED_CLIENT_BUILD <= CLIENT_BUILD_1_8_4
    triggered = false;
#endif

    // These spells are 'triggered' but must not have a proc type DR.
    switch (Id)
    {
        // Charge Stun
        case 7922:
        // Intercept Stun
        case 20253: // Rank 1
        case 20614: // Rank 2
        case 20615: // Rank 3
            return DIMINISHING_CONTROL_STUN;
    }

    // Get by mechanic
    uint32 mechanic = GetAllSpellMechanicMask();
    if (!mechanic)
        return DIMINISHING_NONE;

    if (mechanic & (1 << (MECHANIC_STUN - 1)))
        return triggered ? DIMINISHING_TRIGGER_STUN : DIMINISHING_CONTROL_STUN;
    if (mechanic & (1 << (MECHANIC_SLEEP - 1)))
        return DIMINISHING_SLEEP;
    if (mechanic & (1 << (MECHANIC_POLYMORPH - 1)))
        return DIMINISHING_POLYMORPH;
    if (mechanic & (1 << (MECHANIC_ROOT - 1)))
        return triggered ? DIMINISHING_TRIGGER_ROOT : DIMINISHING_CONTROL_ROOT;
    if (mechanic & (1 << (MECHANIC_FEAR - 1)))
        return DIMINISHING_FEAR;
    if (mechanic & (1 << (MECHANIC_CHARM - 1)))
        return DIMINISHING_CHARM;
    if (mechanic & (1 << (MECHANIC_SILENCE - 1)))
        return DIMINISHING_SILENCE;
    if (mechanic & (1 << (MECHANIC_DISARM - 1)))
        return DIMINISHING_DISARM;
    if (mechanic & (1 << (MECHANIC_FREEZE - 1)))
        return DIMINISHING_FREEZE;
    if (mechanic & ((1 << (MECHANIC_KNOCKOUT - 1)) | (1 << (MECHANIC_SAPPED - 1))))
        return DIMINISHING_KNOCKOUT;
    if (mechanic & (1 << (MECHANIC_BANISH - 1)))
        return DIMINISHING_BANISH;
    if (mechanic & (1 << (MECHANIC_HORROR - 1)))
        return DIMINISHING_DEATHCOIL;

    return DIMINISHING_NONE;
}

bool SpellEntry::IsPvEHeartBeat() const
{
    if (!(Attributes & SPELL_ATTR_DIMINISHING_RETURNS))
        return false;

    for (uint32 i : EffectApplyAuraName)
    {
        switch (i)
        {
            case SPELL_AURA_MOD_FEAR:
            case SPELL_AURA_MOD_ROOT:
            case SPELL_AURA_MOD_PACIFY_SILENCE:
            case SPELL_AURA_MOD_CONFUSE:
                return false;
        }
    }

    return true;
}

bool SpellEntry::IsCCSpell() const
{
    if (IsChanneledSpell())
        return false;
    if (HasEffect(SPELL_EFFECT_INTERRUPT_CAST))
        return false;

    switch (GetDiminishingReturnsGroup(false))
    {
        case DIMINISHING_NONE:
        case DIMINISHING_LIMITONLY:
            return false;
    }
    return true;
}

WeaponAttackType SpellEntry::GetWeaponAttackType() const
{
    switch (DmgClass)
    {
        case SPELL_DAMAGE_CLASS_MELEE:
            if (HasAttribute(SPELL_ATTR_EX3_REQ_OFFHAND))
                return OFF_ATTACK;
            else
                return BASE_ATTACK;
            break;
        case SPELL_DAMAGE_CLASS_RANGED:
            return RANGED_ATTACK;
            break;
        default:
            // Wands
            if (HasAttribute(SPELL_ATTR_EX2_AUTOREPEAT_FLAG))
                return RANGED_ATTACK;
            else
                return BASE_ATTACK;
            break;
    }
}

uint32 SpellEntry::GetCastTime(Spell* spell) const
{
    if (spell)
    {
        // some triggered spells have data only usable for client
        if (spell->IsTriggeredSpellWithRedundentData())
            return 0;

        // spell targeted to non-trading trade slot item instant at trade success apply
        if (spell->GetCaster()->GetTypeId() == TYPEID_PLAYER)
            if (TradeData* my_trade = ((Player*)(spell->GetCaster()))->GetTradeData())
                if (Item* nonTrade = my_trade->GetTraderData()->GetItem(TRADE_SLOT_NONTRADED))
                    if (nonTrade == spell->m_targets.getItemTarget())
                        return 0;
    }

    SpellCastTimesEntry const* spellCastTimeEntry = sSpellCastTimesStore.LookupEntry(CastingTimeIndex);

    // not all spells have cast time index and this is all is pasiive abilities
    if (!spellCastTimeEntry)
        return 0;

    int32 castTime = spellCastTimeEntry->CastTime;

    if (spell)
    {
        if (Unit* pUnit = spell->GetCaster()->ToUnit())
        {
            // Nostalrius: do not consume the Spell Mod if 'castTime' = 0 (Nature's Grace 16886)
            if (castTime)
                if (Player* modOwner = pUnit->GetSpellModOwner())
                    modOwner->ApplySpellMod(Id, SPELLMOD_CASTING_TIME, castTime, spell);

            if (!(Attributes & (SPELL_ATTR_IS_ABILITY | SPELL_ATTR_TRADESPELL)))
            {
#if SUPPORTED_CLIENT_BUILD >= CLIENT_BUILD_1_12_1
                castTime = int32(castTime * pUnit->GetFloatValue(UNIT_MOD_CAST_SPEED));
#else
                castTime = int32(castTime * (1.0f + pUnit->GetInt32Value(UNIT_MOD_CAST_SPEED) / 100.0f));
#endif
            }
            else if (spell->m_spellInfo->IsRangedSpell() && !spell->IsAutoRepeat())
            {
                castTime = int32(castTime * pUnit->m_modAttackSpeedPct[RANGED_ATTACK]);
            }
        }
    }

    if (Attributes & SPELL_ATTR_RANGED && (!spell || !spell->IsAutoRepeat()))
        castTime += 500;

    return (castTime > 0) ? uint32(castTime) : 0;
}

uint32 SpellEntry::GetCastTimeForBonus(DamageEffectType damagetype) const
{
    uint32 CastingTime = !IsChanneledSpell() ? GetCastTime() : GetDuration();

    if (CastingTime > 7000) CastingTime = 7000;
    if (CastingTime < 1500) CastingTime = 1500;

    if (damagetype == DOT && !IsChanneledSpell())
        CastingTime = 3500;

    int32 overTime    = 0;
    uint8 effects     = 0;
    bool DirectDamage = false;
    bool AreaEffect   = false;

    for (uint8 i = 0; i < MAX_EFFECT_INDEX; ++i)
        if (IsAreaEffectTarget(SpellTarget(EffectImplicitTargetA[i])) || IsAreaEffectTarget(SpellTarget(EffectImplicitTargetB[i])))
            AreaEffect = true;

    for (uint8 i = 0; i < MAX_EFFECT_INDEX; ++i)
    {
        switch (Effect[i])
        {
            case SPELL_EFFECT_SCHOOL_DAMAGE:
            case SPELL_EFFECT_POWER_DRAIN:
            case SPELL_EFFECT_HEALTH_LEECH:
            case SPELL_EFFECT_ENVIRONMENTAL_DAMAGE:
            case SPELL_EFFECT_POWER_BURN:
            case SPELL_EFFECT_HEAL:
                DirectDamage = true;
                break;
            case SPELL_EFFECT_APPLY_AURA:
                switch (EffectApplyAuraName[i])
                {
                    case SPELL_AURA_PERIODIC_DAMAGE:
                    case SPELL_AURA_PERIODIC_HEAL:
                    case SPELL_AURA_PERIODIC_LEECH:
                        if (GetDuration())
                            overTime = GetDuration();
                        break;
                    // Penalty for additional effects
                    case SPELL_AURA_DUMMY:
                        ++effects;
                        break;
                    case SPELL_AURA_MOD_DECREASE_SPEED:
                        ++effects;
                        break;
                    case SPELL_AURA_MOD_CONFUSE:
                    case SPELL_AURA_MOD_STUN:
                    case SPELL_AURA_MOD_ROOT:
                        // -10% per effect
                        effects += 2;
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }

    // Combined Spells with Both Over Time and Direct Damage
    if (overTime > 0 && CastingTime > 0 && DirectDamage)
    {
        // mainly for DoTs which are 3500 here otherwise
        uint32 OriginalCastTime = GetCastTime();
        if (OriginalCastTime > 7000) OriginalCastTime = 7000;
        if (OriginalCastTime < 1500) OriginalCastTime = 1500;
        // Portion to Over Time
        float PtOT = (overTime / 15000.0f) / ((overTime / 15000.0f) + (OriginalCastTime / 3500.0f));

        if (damagetype == DOT)
            CastingTime = uint32(CastingTime * PtOT);
        else if (PtOT < 1.0f)
            CastingTime  = uint32(CastingTime * (1 - PtOT));
        else
            CastingTime = 0;
    }

    // Area Effect Spells receive only half of bonus
    if (AreaEffect)
        CastingTime /= 2;

    // 50% for damage and healing spells for leech spells from damage bonus and 0% from healing
    for (uint8 j = 0; j < MAX_EFFECT_INDEX; ++j)
    {
        if (Effect[j] == SPELL_EFFECT_HEALTH_LEECH ||
           (Effect[j] == SPELL_EFFECT_APPLY_AURA && EffectApplyAuraName[j] == SPELL_AURA_PERIODIC_LEECH))
        {
            CastingTime /= 2;
            break;
        }
    }

    // -5% of total per any additional effect (multiplicative)
    for (int i = 0; i < effects; ++i)
        CastingTime *= 0.95f;

    return CastingTime;
}

float SpellEntry::CalculateDefaultCoefficient(DamageEffectType const damagetype) const
{
    // Damage over Time spells bonus calculation
    float DotFactor = 1.0f;
    if (damagetype == DOT)
    {
        if (!IsChanneledSpell())
            DotFactor = GetDuration() / 15000.0f;

        if (uint16 DotTicks = GetAuraMaxTicks())
            DotFactor /= DotTicks;
    }

    // Distribute Damage over multiple effects, reduce by AoE
    float coeff = GetCastTimeForBonus(damagetype) / 3500.0f;

    return coeff * DotFactor;
}

float SpellEntry::CalculateCustomCoefficient(WorldObject const* caster, DamageEffectType const damageType, float coeff, Spell* spell, bool donePart) const
{
    if (!caster)
        return coeff;

    switch (SpellFamilyName)
    {
        case SPELLFAMILY_PALADIN:
        {
            // Seal of Righteousness
            if (IsFitToFamilyMask(UI64LIT(0x0000000008000000)) && SpellIconID == 25)
            {
                coeff = 0.092f;
                float speed = BASE_ATTACK_TIME;

                if (caster->IsPlayer())
                {
                    if (Item *item = ((Player*)caster)->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND))
                    {
                        coeff = item->isOneHandedWeapon() ? 0.092f : 0.108f;
                        speed = item->GetProto()->Delay;
                    }
                }

                speed /= 1000.0f;

                return speed * coeff;
            }
            // Seal of Command
            if (Id == 20424)
            {
                return donePart ? 0.20f : 0.29f;
            }
        }
        case SPELLFAMILY_SHAMAN:
        {
            if (!spell)
                return coeff;

            // Chain Lightning / Chain Heal / Healing Wave (T1 8/8 bonus)
            if (IsFitToFamilyMask(UI64LIT(0x00000000142)))
            {
                float multiplier = DmgMultiplier[0];

                if (spell->GetTargetNum() > 1)
                {
                    if (Unit const* pUnit = caster->ToUnit())
                    {
                        if (Player* modOwner = pUnit->GetSpellModOwner())
                        {
                            // Improved Chain Heal (T2 3/8 bonus) / Gift of the Gathering Storm Chain Lightning Bonus
                            modOwner->ApplySpellMod(spell->m_spellInfo->Id, SPELLMOD_EFFECT_PAST_FIRST, multiplier, spell);
                        }
                    }
                }

                for (uint8 i = 1; i < spell->GetTargetNum(); ++i)
                    coeff *= multiplier;
                return coeff;
            }
        }
        default:
            break;
    }

    return coeff;
}

int32 SpellEntry::GetDuration() const
{
    SpellDurationEntry const* du = sSpellDurationStore.LookupEntry(DurationIndex);
    if (!du)
        return 0;
    return (du->Duration[0] == -1) ? -1 : abs(du->Duration[0]);
}

int32 SpellEntry::GetMaxDuration() const
{
    SpellDurationEntry const* du = sSpellDurationStore.LookupEntry(DurationIndex);
    if (!du)
        return 0;
    return (du->Duration[2] == -1) ? -1 : abs(du->Duration[2]);
}

int32 SpellEntry::CalculateDuration(WorldObject const* caster) const
{
    int32 duration = GetDuration();

    if (duration != -1 && caster)
    {
        int32 maxduration = GetMaxDuration();

        if (duration != maxduration)
            if (Player const* pPlayer = caster->ToPlayer())
                duration += int32((maxduration - duration) * pPlayer->GetComboPoints() / 5);

        if (Unit const* pUnit = caster->ToUnit())
        {
            if (Player* modOwner = pUnit->GetSpellModOwner())
            {
                modOwner->ApplySpellMod(Id, SPELLMOD_DURATION, duration);

                if (duration < 0)
                    duration = 0;
            }
        }
    }

    return duration;
}

uint16 SpellEntry::GetAuraMaxTicks() const
{
    int32 DotDuration = GetDuration();
    if (DotDuration == 0)
        return 1;

    // 200% limit
    if (DotDuration > 30000)
        DotDuration = 30000;

    for (uint8 j = 0; j < MAX_EFFECT_INDEX; ++j)
    {
        if (Effect[j] == SPELL_EFFECT_APPLY_AURA && (
            EffectApplyAuraName[j] == SPELL_AURA_PERIODIC_DAMAGE ||
            EffectApplyAuraName[j] == SPELL_AURA_PERIODIC_HEAL ||
            EffectApplyAuraName[j] == SPELL_AURA_PERIODIC_LEECH))
        {
            if (EffectAmplitude[j] != 0)
                return DotDuration / EffectAmplitude[j];
            break;
        }
    }

    return 6;
}

bool SpellEntry::IsPositiveSpell(WorldObject const* caster, WorldObject const* victim) const
{
    if (Attributes & SPELL_ATTR_NEGATIVE)
        return false;
    // spells with at least one negative effect are considered negative
    // some self-applied spells have negative effects but in self casting case negative check ignored.
    for (uint8 i = 0; i < MAX_EFFECT_INDEX; ++i)
        if (Effect[i] && !IsPositiveEffect(SpellEffectIndex(i), caster, victim))
            return false;
    return true;
}

bool SpellEntry::IsPositiveEffect(SpellEffectIndex effIndex, WorldObject const* caster, WorldObject const* victim) const
{
    // Nostalrius (SpellMod)
    if (Custom & SPELL_CUSTOM_POSITIVE)
        return true;
    if (Custom & SPELL_CUSTOM_NEGATIVE)
        return false;

    // Hellfire. Damages the caster, but is still positive !
    // (Has same SpellFamilyFlags as Soul Fire oO)
    if (IsFitToFamily<SPELLFAMILY_WARLOCK, CF_WARLOCK_HELLFIRE>() && SpellIconID == 937 && SpellVisual == 5423)
        return true;

    switch (Effect[effIndex])
    {
        case SPELL_EFFECT_DUMMY:
            // some explicitly required dummy effect sets
            switch (Id)
            {
                case 10258:                                 // Awaken Vault Warder
                case 18153:                                 // Kodo Kombobulator
                    return true;
                default:
                    break;
            }
            break;
        // always positive effects (check before target checks that provided non-positive result in some case for positive effects)
        case SPELL_EFFECT_HEAL:
        case SPELL_EFFECT_LEARN_SPELL:
        case SPELL_EFFECT_SKILL_STEP:
            return true;
        // Negative Effects
        case SPELL_EFFECT_INSTAKILL:
            // Suicide is a positive spell - ex. Garr Massive Eruption
            if (EffectImplicitTargetA[effIndex] == TARGET_UNIT_CASTER && EffectImplicitTargetB[effIndex] == TARGET_NONE)
                return true;
            // Sacrifice is a positive spell - for the warlock :)
            return IsFitToFamily<SPELLFAMILY_WARLOCK, CF_WARLOCK_VOIDWALKER_SPELLS>();
        // Dispel can be positive or negative depending on the target
        case SPELL_EFFECT_DISPEL:
            if (caster && victim)
            {
                if (victim->IsUnit())
                {
                    if (CharmInfo const* charm = static_cast<Unit const*>(victim)->GetCharmInfo())
                        if (FactionTemplateEntry const* ft = charm->GetOriginalFactionTemplate())
                            return ft->IsFriendlyTo(*caster->getFactionTemplateEntry());
                }
                
                return caster->IsFriendlyTo(victim);
            }
        // non-positive aura use
        case SPELL_EFFECT_APPLY_AURA:
        {
            switch (EffectApplyAuraName[effIndex])
            {
                case SPELL_AURA_DUMMY:
                {
                    // dummy aura can be positive or negative dependent from casted spell
                    switch (Id)
                    {
                        case 13139:                         // net-o-matic special effect
                        case 23445:                         // evil twin
                            return false;
                        // some spells have unclear target modes for selection, so just make effect positive
                        case 27184:
                        case 27190:
                        case 27191:
                        case 27201:
                        case 27202:
                        case 27203:
                            return true;
                        default:
                            break;
                    }
                }
                break;
                case SPELL_AURA_MOD_DAMAGE_DONE:            // dependent from base point sign (negative -> negative)
                case SPELL_AURA_MOD_RESISTANCE:
                case SPELL_AURA_MOD_STAT:
                case SPELL_AURA_MOD_SKILL:
                case SPELL_AURA_MOD_DODGE_PERCENT:
                case SPELL_AURA_MOD_HEALING_PCT:
                case SPELL_AURA_MOD_HEALING_DONE:
                    if (CalculateSimpleValue(effIndex) < 0)
                        return false;
                    break;
                case SPELL_AURA_MOD_DAMAGE_TAKEN:           // dependent from bas point sign (positive -> negative)
                    if (CalculateSimpleValue(effIndex) < 0)
                        return true;
                    // let check by target modes (for Amplify Magic cases/etc)
                    break;
                case SPELL_AURA_MOD_SPELL_CRIT_CHANCE:
                case SPELL_AURA_MOD_INCREASE_HEALTH_PERCENT:
                case SPELL_AURA_MOD_DAMAGE_PERCENT_DONE:
                    if (CalculateSimpleValue(effIndex) > 0)
                        return true;                        // some expected positive spells have unclear target modes // maybe don't need this at all now that we don't check for what was SPELL_ATTR_EX_NEGATIVE
                    break;
                case SPELL_AURA_MOD_INCREASE_HEALTH:
                case SPELL_AURA_ADD_TARGET_TRIGGER:
                    return true;
                case SPELL_AURA_PERIODIC_TRIGGER_SPELL:
                    if (Id != EffectTriggerSpell[effIndex])
                    {
                        uint32 spellTriggeredId = EffectTriggerSpell[effIndex];
                        SpellEntry const* spellTriggeredProto = sSpellMgr.GetSpellEntry(spellTriggeredId);

                        if (spellTriggeredProto)
                        {
                            // non-positive targets of main spell return early
                            for (uint8 i = 0; i < MAX_EFFECT_INDEX; ++i)
                            {
                                // if non-positive trigger cast targeted to positive target this main cast is non-positive
                                // this will place this spell auras as debuffs
                                if (spellTriggeredProto->Effect[i] &&
                                        IsPositiveTarget(spellTriggeredProto->EffectImplicitTargetA[i], spellTriggeredProto->EffectImplicitTargetB[i]) &&
                                        !spellTriggeredProto->IsPositiveEffect(SpellEffectIndex(i)))
                                    return false;
                            }
                        }
                    }
                    break;
                case SPELL_AURA_PROC_TRIGGER_SPELL:
                    // many positive auras have negative triggered spells at damage for example and this not make it negative (it can be canceled for example)
                    break;
                case SPELL_AURA_MOD_STUN:                   //have positive and negative spells, we can't sort its correctly at this moment.
                    if (effIndex == EFFECT_INDEX_0 && Effect[EFFECT_INDEX_1] == 0 && Effect[EFFECT_INDEX_2] == 0)
                        return false;                       // but all single stun aura spells is negative
                    break;
                case SPELL_AURA_MOD_PACIFY_SILENCE:
                    if (Id == 24740)            // Wisp Costume
                        return true;
                    return false;
                case SPELL_AURA_MOD_SILENCE:
                    if (Id == 24732)            // Bat Costume
                        return true;
                    return false;
                case SPELL_AURA_MOD_ROOT:
                case SPELL_AURA_GHOST:
                case SPELL_AURA_PERIODIC_LEECH:
                case SPELL_AURA_MOD_STALKED:
                case SPELL_AURA_PERIODIC_DAMAGE_PERCENT:
                case SPELL_AURA_MOD_DETECT_RANGE:
                    return false;
                case SPELL_AURA_PERIODIC_DAMAGE:            // used in positive spells also.
                    // part of negative spell if casted at self (prevent cancel)
                    if (EffectImplicitTargetA[effIndex] == TARGET_UNIT_CASTER)
                        return false;
                    break;
                case SPELL_AURA_MOD_DECREASE_SPEED:         // used in positive spells also
                    // part of positive spell if casted at self
                    if (EffectImplicitTargetA[effIndex] == TARGET_UNIT_CASTER &&
                            SpellFamilyName == SPELLFAMILY_GENERIC)
                        return false;
                    // but not this if this first effect (don't found better check)
                    if (Attributes & 0x4000000 && effIndex == EFFECT_INDEX_0)
                        return false;
                    break;
                case SPELL_AURA_MOD_SCALE:
                    // some spells negative
                    switch (Id)
                    {
                        case 802:                           // Mutate Bug, wrongly negative by target modes
                            return true;
                    }
                    break;
                case SPELL_AURA_MECHANIC_IMMUNITY:
                {
                    // non-positive immunities
                    switch (EffectMiscValue[effIndex])
                    {
                        case MECHANIC_BANDAGE:
                        case MECHANIC_SHIELD:
                        case MECHANIC_MOUNT:
                        case MECHANIC_INVULNERABILITY:
                            return false;
                        default:
                            break;
                    }
                }
                break;
                case SPELL_AURA_ADD_FLAT_MODIFIER:          // mods
                case SPELL_AURA_ADD_PCT_MODIFIER:
                {
                    // non-positive mods
                    switch (EffectMiscValue[effIndex])
                    {
                        case SPELLMOD_COST:                 // dependent from bas point sign (negative -> positive)
                            if (CalculateSimpleValue(effIndex) > 0)
                                return false;
                            break;
                        default:
                            break;
                    }
                }
                break;
                default:
                    break;
            }
            break;
        }
        default:
            break;
    }

    // non-positive targets
    if (!IsPositiveTarget(EffectImplicitTargetA[effIndex], EffectImplicitTargetB[effIndex]))
        return false;

    // Attributes check
    if (Attributes & SPELL_ATTR_NEGATIVE)
        return false;

    // ok, positive
    return true;
}

bool SpellEntry::IsReflectableSpell(WorldObject const* caster, WorldObject const* victim) const
{
    return DmgClass == SPELL_DAMAGE_CLASS_MAGIC && !HasAttribute(SPELL_ATTR_IS_ABILITY)
        && !HasAttribute(SPELL_ATTR_EX_CANT_BE_REFLECTED) && !HasAttribute(SPELL_ATTR_UNAFFECTED_BY_INVULNERABILITY)
        && !HasAttribute(SPELL_ATTR_PASSIVE) && !IsPositiveSpell(caster, victim);
}

SpellCastResult SpellEntry::GetErrorAtShapeshiftedCast(uint32 form) const
{
    // talents that learn spells can have stance requirements that need ignore
    // (this requirement only for client-side stance show in talent description)
    if (GetTalentSpellCost(Id) > 0 &&
            (Effect[EFFECT_INDEX_0] == SPELL_EFFECT_LEARN_SPELL || Effect[EFFECT_INDEX_1] == SPELL_EFFECT_LEARN_SPELL || Effect[EFFECT_INDEX_2] == SPELL_EFFECT_LEARN_SPELL))
        return SPELL_CAST_OK;

    uint32 stanceMask = (form ? 1 << (form - 1) : 0);

    if (stanceMask & StancesNot)                 // can explicitly not be casted in this stance
        return SPELL_FAILED_NOT_SHAPESHIFT;

    if (stanceMask & Stances)                    // can explicitly be casted in this stance
        return SPELL_CAST_OK;

    bool actAsShifted = false;
    if (form > 0)
    {
        SpellShapeshiftFormEntry const* shapeInfo = sSpellShapeshiftFormStore.LookupEntry(form);
        if (!shapeInfo)
        {
            sLog.outError("GetErrorAtShapeshiftedCast: unknown shapeshift %u", form);
            return SPELL_CAST_OK;
        }
        actAsShifted = !(shapeInfo->flags1 & 1);            // shapeshift acts as normal form for spells
    }

    if (actAsShifted)
    {
        if (Attributes & SPELL_ATTR_NOT_SHAPESHIFT) // not while shapeshifted
            return SPELL_FAILED_NOT_SHAPESHIFT;
        else if (Stances != 0)                   // needs other shapeshift
            return SPELL_FAILED_ONLY_SHAPESHIFT;
    }
    else
    {
        // needs shapeshift
        if (!(AttributesEx2 & SPELL_ATTR_EX2_NOT_NEED_SHAPESHIFT) && Stances != 0)
            return SPELL_FAILED_ONLY_SHAPESHIFT;
    }

    return SPELL_CAST_OK;
}

bool SpellEntry::IsTargetInRange(WorldObject const* pCaster, WorldObject const* pTarget) const
{
    switch (rangeIndex)
    {
        case SPELL_RANGE_IDX_SELF_ONLY:
            for (auto radiusIndex : EffectRadiusIndex)
            {
                if (radiusIndex)
                    return pCaster->GetCombatDistance(pTarget) <= Spells::GetSpellRadius(sSpellRadiusStore.LookupEntry(radiusIndex));
            }
            for (auto triggeredSpell : EffectTriggerSpell)
            {
                if (triggeredSpell)
                    if (SpellEntry const* pSpellEntry = sSpellMgr.GetSpellEntry(triggeredSpell))
                        if (pSpellEntry->IsTargetInRange(pCaster, pTarget))
                            return true;
            }
            return pCaster == pTarget;
        case SPELL_RANGE_IDX_ANYWHERE:
            return true;
        case SPELL_RANGE_IDX_COMBAT:
            return pCaster->CanReachWithMeleeSpellAttack(pTarget);
    }

    SpellRangeEntry const* srange = sSpellRangeStore.LookupEntry(rangeIndex);
    float max_range = Spells::GetSpellMaxRange(srange);
    float min_range = Spells::GetSpellMinRange(srange);
    float dist = pCaster->GetCombatDistance(pTarget);

    return dist < max_range && dist >= min_range;
}
