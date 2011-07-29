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

#include "SpellInfo.h"
#include "SpellMgr.h"
#include "DBCStores.h"

SpellImplicitTargetInfo::SpellImplicitTargetInfo(uint32 target)
{
    _target = Targets(target);
}

bool SpellImplicitTargetInfo::IsArea() const
{
    return Area[_target];
}

SpellSelectTargetTypes SpellImplicitTargetInfo::GetType() const
{
    return Type[_target];
}


Targets SpellImplicitTargetInfo::GetTarget() const
{
    return _target;
}

bool SpellImplicitTargetInfo::IsPosition(uint32 targetType)
{
    switch (SpellImplicitTargetInfo::Type[targetType])
    {
        case TARGET_TYPE_DEST_CASTER:
        case TARGET_TYPE_DEST_TARGET:
        case TARGET_TYPE_DEST_DEST:
            return true;
        default:
            break;
    }
    return false;
}

bool SpellImplicitTargetInfo::InitStaticData()
{
    InitAreaData();
    InitTypeData();
    return true;
}

void SpellImplicitTargetInfo::InitAreaData()
{
    for (int32 i = 0; i < TOTAL_SPELL_TARGETS; ++i)
    {
        switch (i)
        {
            case TARGET_UNIT_AREA_ENEMY_DST:
            case TARGET_UNIT_AREA_ENEMY_SRC:
            case TARGET_UNIT_AREA_ALLY_DST:
            case TARGET_UNIT_AREA_ALLY_SRC:
            case TARGET_UNIT_AREA_ENTRY_DST:
            case TARGET_UNIT_AREA_ENTRY_SRC:
            case TARGET_UNIT_AREA_PARTY_DST:
            case TARGET_UNIT_AREA_PARTY_SRC:
            case TARGET_UNIT_TARGET_ALLY_PARTY:
            case TARGET_UNIT_PARTY_CASTER:
            case TARGET_UNIT_CONE_ENEMY:
            case TARGET_UNIT_CONE_ALLY:
            case TARGET_UNIT_CONE_ENEMY_UNKNOWN:
            case TARGET_UNIT_AREA_PATH:
            case TARGET_GAMEOBJECT_AREA_PATH:
            case TARGET_UNIT_RAID_CASTER:
                Area[i] = true;
                break;
            default:
                Area[i] = false;
                break;
        }
    }
}

void SpellImplicitTargetInfo::InitTypeData()
{
    for (uint8 i = 0; i < TOTAL_SPELL_TARGETS; ++i)
    {
        switch (i)
        {
            case TARGET_UNIT_CASTER:
            case TARGET_UNIT_CASTER_FISHING:
            case TARGET_UNIT_MASTER:
            case TARGET_UNIT_PET:
            case TARGET_UNIT_PARTY_CASTER:
            case TARGET_UNIT_RAID_CASTER:
            case TARGET_UNIT_VEHICLE:
            case TARGET_UNIT_PASSENGER_0:
            case TARGET_UNIT_PASSENGER_1:
            case TARGET_UNIT_PASSENGER_2:
            case TARGET_UNIT_PASSENGER_3:
            case TARGET_UNIT_PASSENGER_4:
            case TARGET_UNIT_PASSENGER_5:
            case TARGET_UNIT_PASSENGER_6:
            case TARGET_UNIT_PASSENGER_7:
            case TARGET_UNIT_SUMMONER:
                Type[i] = TARGET_TYPE_UNIT_CASTER;
                break;
            case TARGET_UNIT_TARGET_MINIPET:
            case TARGET_UNIT_TARGET_ALLY:
            case TARGET_UNIT_TARGET_RAID:
            case TARGET_UNIT_TARGET_ANY:
            case TARGET_UNIT_TARGET_ENEMY:
            case TARGET_UNIT_TARGET_PARTY:
            case TARGET_UNIT_TARGET_PASSENGER:
            case TARGET_UNIT_TARGET_ALLY_PARTY:
            case TARGET_UNIT_TARGET_CLASS_RAID:
            case TARGET_UNIT_CHAINHEAL:
                Type[i] = TARGET_TYPE_UNIT_TARGET;
                break;
            case TARGET_UNIT_NEARBY_ENEMY:
            case TARGET_UNIT_NEARBY_ALLY:
            case TARGET_UNIT_NEARBY_ENTRY:
            case TARGET_UNIT_NEARBY_PARTY:
            case TARGET_UNIT_NEARBY_RAID:
            case TARGET_GAMEOBJECT_NEARBY_ENTRY:
                Type[i] = TARGET_TYPE_UNIT_NEARBY;
                break;
            case TARGET_UNIT_AREA_ENEMY_SRC:
            case TARGET_UNIT_AREA_ALLY_SRC:
            case TARGET_UNIT_AREA_ENTRY_SRC:
            case TARGET_UNIT_AREA_PARTY_SRC:
            case TARGET_GAMEOBJECT_AREA_SRC:
                Type[i] = TARGET_TYPE_AREA_SRC;
                break;
            case TARGET_UNIT_AREA_ENEMY_DST:
            case TARGET_UNIT_AREA_ALLY_DST:
            case TARGET_UNIT_AREA_ENTRY_DST:
            case TARGET_UNIT_AREA_PARTY_DST:
            case TARGET_GAMEOBJECT_AREA_DST:
                Type[i] = TARGET_TYPE_AREA_DST;
                break;
            case TARGET_UNIT_CONE_ENEMY:
            case TARGET_UNIT_CONE_ALLY:
            case TARGET_UNIT_CONE_ENTRY:
            case TARGET_UNIT_CONE_ENEMY_UNKNOWN:
            case TARGET_UNIT_AREA_PATH:
            case TARGET_GAMEOBJECT_AREA_PATH:
                Type[i] = TARGET_TYPE_AREA_CONE;
                break;
            case TARGET_DST_CASTER:
            case TARGET_SRC_CASTER:
            case TARGET_MINION:
            case TARGET_DEST_CASTER_FRONT_LEAP:
            case TARGET_DEST_CASTER_FRONT:
            case TARGET_DEST_CASTER_BACK:
            case TARGET_DEST_CASTER_RIGHT:
            case TARGET_DEST_CASTER_LEFT:
            case TARGET_DEST_CASTER_FRONT_LEFT:
            case TARGET_DEST_CASTER_BACK_LEFT:
            case TARGET_DEST_CASTER_BACK_RIGHT:
            case TARGET_DEST_CASTER_FRONT_RIGHT:
            case TARGET_DEST_CASTER_RANDOM:
            case TARGET_DEST_CASTER_RADIUS:
                Type[i] = TARGET_TYPE_DEST_CASTER;
                break;
            case TARGET_DST_TARGET_ENEMY:
            case TARGET_DEST_TARGET_ANY:
            case TARGET_DEST_TARGET_FRONT:
            case TARGET_DEST_TARGET_BACK:
            case TARGET_DEST_TARGET_RIGHT:
            case TARGET_DEST_TARGET_LEFT:
            case TARGET_DEST_TARGET_FRONT_LEFT:
            case TARGET_DEST_TARGET_BACK_LEFT:
            case TARGET_DEST_TARGET_BACK_RIGHT:
            case TARGET_DEST_TARGET_FRONT_RIGHT:
            case TARGET_DEST_TARGET_RANDOM:
            case TARGET_DEST_TARGET_RADIUS:
                Type[i] = TARGET_TYPE_DEST_TARGET;
                break;
            case TARGET_DEST_DYNOBJ_ENEMY:
            case TARGET_DEST_DYNOBJ_ALLY:
            case TARGET_DEST_DYNOBJ_NONE:
            case TARGET_DEST_DEST:
            case TARGET_DEST_TRAJ:
            case TARGET_DEST_DEST_FRONT_LEFT:
            case TARGET_DEST_DEST_BACK_LEFT:
            case TARGET_DEST_DEST_BACK_RIGHT:
            case TARGET_DEST_DEST_FRONT_RIGHT:
            case TARGET_DEST_DEST_FRONT:
            case TARGET_DEST_DEST_BACK:
            case TARGET_DEST_DEST_RIGHT:
            case TARGET_DEST_DEST_LEFT:
            case TARGET_DEST_DEST_RANDOM:
            case TARGET_DEST_DEST_RANDOM_DIR_DIST:
                Type[i] = TARGET_TYPE_DEST_DEST;
                break;
            case TARGET_DST_DB:
            case TARGET_DST_HOME:
            case TARGET_DST_NEARBY_ENTRY:
                Type[i] = TARGET_TYPE_DEST_SPECIAL;
                break;
            case TARGET_UNIT_CHANNEL_TARGET:
            case TARGET_DEST_CHANNEL_TARGET:
            case TARGET_DEST_CHANNEL_CASTER:
                Type[i] = TARGET_TYPE_CHANNEL;
                break;
            default:
                Type[i] = TARGET_TYPE_DEFAULT;
        }
    }
}

bool SpellImplicitTargetInfo::Init = SpellImplicitTargetInfo::InitStaticData();
bool SpellImplicitTargetInfo::Area[TOTAL_SPELL_TARGETS];
SpellSelectTargetTypes SpellImplicitTargetInfo::Type[TOTAL_SPELL_TARGETS];

SpellEffectInfo::SpellEffectInfo(SpellEntry const* spellEntry, SpellInfo const* spellInfo, uint8 effIndex)
{
    _spellInfo = spellInfo;
    _effIndex = effIndex;
    Effect = spellEntry->Effect[effIndex];
    ApplyAuraName = spellEntry->EffectApplyAuraName[effIndex];
    Amplitude = spellEntry->EffectAmplitude[effIndex];
    DieSides = spellEntry->EffectDieSides[effIndex];
    RealPointsPerLevel = spellEntry->EffectRealPointsPerLevel[effIndex];
    BasePoints = spellEntry->EffectBasePoints[effIndex];
    PointsPerComboPoint = spellEntry->EffectPointsPerComboPoint[effIndex];
    ValueMultiplier = spellEntry->EffectValueMultiplier[effIndex];
    DamageMultiplier = spellEntry->EffectDamageMultiplier[effIndex];
    BonusMultiplier = spellEntry->EffectBonusMultiplier[effIndex];
    MiscValue = spellEntry->EffectMiscValue[effIndex];
    MiscValueB = spellEntry->EffectMiscValueB[effIndex];
    Mechanic = Mechanics(spellEntry->EffectMechanic[effIndex]);
    TargetA = SpellImplicitTargetInfo(spellEntry->EffectImplicitTargetA[effIndex]);
    TargetB = SpellImplicitTargetInfo(spellEntry->EffectImplicitTargetB[effIndex]);
    RadiusEntry = spellEntry->EffectRadiusIndex[effIndex] ? sSpellRadiusStore.LookupEntry(spellEntry->EffectRadiusIndex[effIndex]) : NULL;
    ChainTarget = spellEntry->EffectChainTarget[effIndex];
    ItemType = spellEntry->EffectItemType[effIndex];
    TriggerSpell = spellEntry->EffectTriggerSpell[effIndex];
    SpellClassMask = spellEntry->EffectSpellClassMask[effIndex];
}

bool SpellEffectInfo::IsEffect() const
{
    return Effect != 0;
}

bool SpellEffectInfo::IsEffect(SpellEffects effectName) const
{
    return Effect == effectName;
}

bool SpellEffectInfo::IsAura() const
{
    return (IsUnitOwnedAuraEffect() || Effect == SPELL_EFFECT_PERSISTENT_AREA_AURA) && ApplyAuraName != 0;
}

bool SpellEffectInfo::IsAura(AuraType aura) const
{
    return IsAura() && ApplyAuraName == aura;
}

bool SpellEffectInfo::IsArea() const
{
    return TargetA.IsArea() || TargetB.IsArea();
}

bool SpellEffectInfo::IsAreaAuraEffect() const
{
    if (Effect == SPELL_EFFECT_APPLY_AREA_AURA_PARTY    ||
        Effect == SPELL_EFFECT_APPLY_AREA_AURA_RAID     ||
        Effect == SPELL_EFFECT_APPLY_AREA_AURA_FRIEND   ||
        Effect == SPELL_EFFECT_APPLY_AREA_AURA_ENEMY    ||
        Effect == SPELL_EFFECT_APPLY_AREA_AURA_PET      ||
        Effect == SPELL_EFFECT_APPLY_AREA_AURA_OWNER)
        return true;
    return false;
}

bool SpellEffectInfo::IsFarUnitTargetEffect() const
{
    return (Effect == SPELL_EFFECT_SUMMON_PLAYER);
}

bool SpellEffectInfo::IsFarDestTargetEffect() const
{
    return (Effect == SPELL_EFFECT_TELEPORT_UNITS);
}

bool SpellEffectInfo::IsUnitOwnedAuraEffect() const
{
    return (IsAreaAuraEffect() || Effect == SPELL_EFFECT_APPLY_AURA);
}

int32 SpellEffectInfo::CalcValue(Unit const* caster, int32 const* bp, Unit const* /*target*/) const
{
    float basePointsPerLevel = RealPointsPerLevel;
    int32 basePoints = bp ? *bp : BasePoints;
    int32 randomPoints = int32(DieSides);

    // base amount modification based on spell lvl vs caster lvl
    if (caster)
    {
        int32 level = int32(caster->getLevel());
        if (level > int32(_spellInfo->MaxLevel) && _spellInfo->MaxLevel > 0)
            level = int32(_spellInfo->MaxLevel);
        else if (level < int32(_spellInfo->BaseLevel))
            level = int32(_spellInfo->BaseLevel);
        level -= int32(_spellInfo->SpellLevel);
        basePoints += int32(level * basePointsPerLevel);
    }

    // roll in a range <1;EffectDieSides> as of patch 3.3.3
    switch (randomPoints)
    {
        case 0: break;
        case 1: basePoints += 1; break;                     // range 1..1
        default:
            // range can have positive (1..rand) and negative (rand..1) values, so order its for irand
            int32 randvalue = (randomPoints >= 1)
                ? irand(1, randomPoints)
                : irand(randomPoints, 1);

            basePoints += randvalue;
            break;
    }

    float value = float(basePoints);

    // random damage
    if (caster)
    {
        // bonus amount from combo points
        if (caster->m_movedPlayer)
            if (uint8 comboPoints = caster->m_movedPlayer->GetComboPoints())
                if (float comboDamage = PointsPerComboPoint)
                    value += comboDamage * comboPoints;

        value = caster->ApplyEffectModifiers(_spellInfo, _effIndex, value);

        // amount multiplication based on caster's level
        if (!basePointsPerLevel && (_spellInfo->Attributes & SPELL_ATTR0_LEVEL_DAMAGE_CALCULATION && _spellInfo->SpellLevel) &&
                Effect != SPELL_EFFECT_WEAPON_PERCENT_DAMAGE &&
                Effect != SPELL_EFFECT_KNOCK_BACK &&
                ApplyAuraName != SPELL_AURA_MOD_SPEED_ALWAYS &&
                ApplyAuraName != SPELL_AURA_MOD_SPEED_NOT_STACK &&
                ApplyAuraName != SPELL_AURA_MOD_INCREASE_SPEED &&
                ApplyAuraName != SPELL_AURA_MOD_DECREASE_SPEED)
                //there are many more: slow speed, -healing pct
            value *= 0.25f * exp(caster->getLevel() * (70 - _spellInfo->SpellLevel) / 1000.0f);
            //value = int32(value * (int32)getLevel() / (int32)(_spellInfo->spellLevel ? _spellInfo->spellLevel : 1));
    }

    return int32(value);
}

int32 SpellEffectInfo::CalcBaseValue(int32 value) const
{
    if (DieSides == 0)
        return value;
    else
        return value - 1;
}

float SpellEffectInfo::CalcValueMultiplier(Unit* caster, Spell* spell) const
{
    float multiplier = ValueMultiplier;
    if (Player* modOwner = (caster ? caster->GetSpellModOwner() : NULL))
        modOwner->ApplySpellMod(_spellInfo->Id, SPELLMOD_VALUE_MULTIPLIER, multiplier, spell);
    return multiplier;
}

float SpellEffectInfo::CalcDamageMultiplier(Unit* caster, Spell* spell) const
{
    float multiplier = DamageMultiplier;
    if (Player* modOwner = (caster ? caster->GetSpellModOwner() : NULL))
        modOwner->ApplySpellMod(_spellInfo->Id, SPELLMOD_DAMAGE_MULTIPLIER, multiplier, spell);
    return multiplier;
}

bool SpellEffectInfo::HasRadius() const
{
    return RadiusEntry != NULL;
}

float SpellEffectInfo::CalcRadius(Unit* caster, Spell* spell) const
{
    if (!HasRadius())
        return 0.0f;

    float radius = RadiusEntry->radiusMax;
    if (Player* modOwner = (caster ? caster->GetSpellModOwner() : NULL))
        modOwner->ApplySpellMod(_spellInfo->Id, SPELLMOD_RADIUS, radius, spell);

    return radius;
}

SpellEffectTargetTypes SpellEffectInfo::GetRequiredTargetType() const
{
    return RequiredTargetType[Effect];
}

bool SpellEffectInfo::InitStaticData()
{
    InitRequiredTargetTypeData();
    return true;
}

void SpellEffectInfo::InitRequiredTargetTypeData()
{
    for (uint8 i = 0; i < TOTAL_SPELL_EFFECTS; ++i)
    {
        switch (i)
        {
            case SPELL_EFFECT_PERSISTENT_AREA_AURA: //27
            case SPELL_EFFECT_SUMMON:               //28
            case SPELL_EFFECT_TRIGGER_MISSILE:      //32
            case SPELL_EFFECT_TRANS_DOOR:           //50 summon object
            case SPELL_EFFECT_SUMMON_PET:           //56
            case SPELL_EFFECT_ADD_FARSIGHT:         //72
            case SPELL_EFFECT_SUMMON_OBJECT_WILD:   //76
            //case SPELL_EFFECT_SUMMON_CRITTER:       //97 not 303
            case SPELL_EFFECT_SUMMON_OBJECT_SLOT1:  //104
            case SPELL_EFFECT_SUMMON_OBJECT_SLOT2:  //105
            case SPELL_EFFECT_SUMMON_OBJECT_SLOT3:  //106
            case SPELL_EFFECT_SUMMON_OBJECT_SLOT4:  //107
            case SPELL_EFFECT_SUMMON_DEAD_PET:      //109
            case SPELL_EFFECT_TRIGGER_SPELL_2:      //151 ritual of summon
                RequiredTargetType[i] = SPELL_REQUIRE_DEST;
                break;
            case SPELL_EFFECT_PARRY: // 0
            case SPELL_EFFECT_BLOCK: // 0
            case SPELL_EFFECT_SKILL: // always with dummy 3 as A
            //case SPELL_EFFECT_LEARN_SPELL: // 0 may be 5 pet
            case SPELL_EFFECT_TRADE_SKILL: // 0 or 1
            case SPELL_EFFECT_PROFICIENCY: // 0
                RequiredTargetType[i] = SPELL_REQUIRE_NONE;
                break;
            case SPELL_EFFECT_ENCHANT_ITEM:
            case SPELL_EFFECT_ENCHANT_ITEM_TEMPORARY:
            case SPELL_EFFECT_DISENCHANT:
            //in 243 this is 0, in 309 it is 1
            //so both item target and unit target is pushed, and cause crash
            //case SPELL_EFFECT_FEED_PET:
            case SPELL_EFFECT_PROSPECTING:
            case SPELL_EFFECT_MILLING:
            case SPELL_EFFECT_ENCHANT_ITEM_PRISMATIC:
                RequiredTargetType[i] = SPELL_REQUIRE_ITEM;
                break;
            //caster must be pushed otherwise no sound
            case SPELL_EFFECT_APPLY_AREA_AURA_PARTY:
            case SPELL_EFFECT_APPLY_AREA_AURA_FRIEND:
            case SPELL_EFFECT_APPLY_AREA_AURA_ENEMY:
            case SPELL_EFFECT_APPLY_AREA_AURA_PET:
            case SPELL_EFFECT_APPLY_AREA_AURA_OWNER:
            case SPELL_EFFECT_APPLY_AREA_AURA_RAID:
            case SPELL_EFFECT_CHARGE:
            case SPELL_EFFECT_CHARGE_DEST:
            case SPELL_EFFECT_JUMP:
            case SPELL_EFFECT_JUMP_DEST:
            case SPELL_EFFECT_LEAP_BACK:
                RequiredTargetType[i] = SPELL_REQUIRE_CASTER;
                break;
            //case SPELL_EFFECT_WMO_DAMAGE:
            //case SPELL_EFFECT_WMO_REPAIR:
            //case SPELL_EFFECT_WMO_CHANGE:
            //    RequiredTargetType[i] = SPELL_REQUIRE_GOBJECT;
            //    break;
            default:
                RequiredTargetType[i] = SPELL_REQUIRE_UNIT;
                break;
        }
    }
}

bool SpellEffectInfo::Init = SpellEffectInfo::InitStaticData();
SpellEffectTargetTypes SpellEffectInfo::RequiredTargetType[TOTAL_SPELL_EFFECTS];

SpellInfo::SpellInfo(SpellEntry const* spellEntry)
{
    Id = spellEntry->Id;
    Category = spellEntry->Category;
    Dispel = spellEntry->Dispel;
    Mechanic = spellEntry->Mechanic;
    Attributes = spellEntry->Attributes;
    AttributesEx = spellEntry->AttributesEx;
    AttributesEx2 = spellEntry->AttributesEx2;
    AttributesEx3 = spellEntry->AttributesEx3;
    AttributesEx4 = spellEntry->AttributesEx4;
    AttributesEx5 = spellEntry->AttributesEx5;
    AttributesEx6 = spellEntry->AttributesEx6;
    AttributesEx7 = spellEntry->AttributesEx7;
    AttributesCu = 0;
    Stances = spellEntry->Stances;
    StancesNot = spellEntry->StancesNot;
    Targets = spellEntry->Targets;
    TargetCreatureType = spellEntry->TargetCreatureType;
    RequiresSpellFocus = spellEntry->RequiresSpellFocus;
    FacingCasterFlags = spellEntry->FacingCasterFlags;
    CasterAuraState = spellEntry->CasterAuraState;
    TargetAuraState = spellEntry->TargetAuraState;
    CasterAuraStateNot = spellEntry->CasterAuraStateNot;
    TargetAuraStateNot = spellEntry->TargetAuraStateNot;
    CasterAuraSpell = spellEntry->casterAuraSpell;
    TargetAuraSpell = spellEntry->targetAuraSpell;
    ExcludeCasterAuraSpell = spellEntry->excludeCasterAuraSpell;
    ExcludeTargetAuraSpell = spellEntry->excludeTargetAuraSpell;
    CastTimeEntry = spellEntry->CastingTimeIndex ? sSpellCastTimesStore.LookupEntry(spellEntry->CastingTimeIndex) : NULL;
    RecoveryTime = spellEntry->RecoveryTime;
    CategoryRecoveryTime = spellEntry->CategoryRecoveryTime;
    StartRecoveryCategory = spellEntry->StartRecoveryCategory;
    StartRecoveryTime = spellEntry->StartRecoveryTime;
    InterruptFlags = spellEntry->InterruptFlags;
    AuraInterruptFlags = spellEntry->AuraInterruptFlags;
    ChannelInterruptFlags = spellEntry->ChannelInterruptFlags;
    ProcFlags = spellEntry->procFlags;
    ProcChance = spellEntry->procChance;
    ProcCharges = spellEntry->procCharges;
    MaxLevel = spellEntry->maxLevel;
    BaseLevel = spellEntry->baseLevel;
    SpellLevel = spellEntry->spellLevel;
    DurationEntry = spellEntry->DurationIndex ? sSpellDurationStore.LookupEntry(spellEntry->DurationIndex) : NULL;
    PowerType = spellEntry->powerType;
    ManaCost = spellEntry->manaCost;
    ManaCostPerlevel = spellEntry->manaCostPerlevel;
    ManaPerSecond = spellEntry->manaPerSecond;
    ManaPerSecondPerLevel = spellEntry->manaPerSecondPerLevel;
    ManaCostPercentage = spellEntry->ManaCostPercentage;
    RuneCostID = spellEntry->runeCostID;
    RangeEntry = spellEntry->rangeIndex ? sSpellRangeStore.LookupEntry(spellEntry->rangeIndex) : NULL;
    Speed = spellEntry->speed;
    StackAmount = spellEntry->StackAmount;
    for (uint8 i = 0; i < 2; ++i)
        Totem[i] = spellEntry->Totem[i];
    for (uint8 i = 0; i < MAX_SPELL_REAGENTS; ++i)
        Reagent[i] = spellEntry->Reagent[i];
    for (uint8 i = 0; i < MAX_SPELL_REAGENTS; ++i)
        ReagentCount[i] = spellEntry->ReagentCount[i];
    EquippedItemClass = spellEntry->EquippedItemClass;
    EquippedItemSubClassMask = spellEntry->EquippedItemSubClassMask;
    EquippedItemInventoryTypeMask = spellEntry->EquippedItemInventoryTypeMask;
    for (uint8 i = 0; i < 2; ++i)
        TotemCategory[i] = spellEntry->TotemCategory[i];
    for (uint8 i = 0; i < 2; ++i)
        SpellVisual[i] = spellEntry->SpellVisual[i];
    SpellIconID = spellEntry->SpellIconID;
    ActiveIconID = spellEntry->activeIconID;
    for (uint8 i = 0; i < 16; ++i)
        SpellName[i] = spellEntry->SpellName[i];
    for (uint8 i = 0; i < 16; ++i)
        Rank[i] = spellEntry->Rank[i];
    MaxTargetLevel = spellEntry->MaxTargetLevel;
    MaxAffectedTargets = spellEntry->MaxAffectedTargets;
    SpellFamilyName = spellEntry->SpellFamilyName;
    SpellFamilyFlags = spellEntry->SpellFamilyFlags;
    DmgClass = spellEntry->DmgClass;
    PreventionType = spellEntry->PreventionType;
    AreaGroupId  = spellEntry->AreaGroupId;
    SchoolMask = spellEntry->SchoolMask;
    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
        Effects[i] = SpellEffectInfo(spellEntry, this, i);
    ChainEntry = NULL;
}

bool SpellInfo::HasEffect(SpellEffects effect) const
{
    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
        if (Effects[i].IsEffect(effect))
            return true;
    return false;
}

bool SpellInfo::HasAura(AuraType aura) const
{
    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
        if (Effects[i].IsAura(aura))
            return true;
    return false;
}

bool SpellInfo::HasAreaAuraEffect() const
{
    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
        if (Effects[i].IsAreaAuraEffect())
            return true;
    return false;
}

bool SpellInfo::IsExplicitDiscovery() const
{
    return ((Effects[0].Effect == SPELL_EFFECT_CREATE_RANDOM_ITEM
        || Effects[0].Effect == SPELL_EFFECT_CREATE_ITEM_2)
        && Effects[1].Effect == SPELL_EFFECT_SCRIPT_EFFECT)
        || Id == 64323;
}

bool SpellInfo::IsLootCrafting() const
{
    return (Effects[0].Effect == SPELL_EFFECT_CREATE_RANDOM_ITEM ||
        // different random cards from Inscription (121==Virtuoso Inking Set category) r without explicit item
        (Effects[0].Effect == SPELL_EFFECT_CREATE_ITEM_2 &&
        (TotemCategory[0] != 0 || Effects[0].ItemType == 0)));
}

bool SpellInfo::IsQuestTame() const
{
    return Effects[0].Effect == SPELL_EFFECT_THREAT && Effects[1].Effect == SPELL_EFFECT_APPLY_AURA && Effects[1].ApplyAuraName == SPELL_AURA_DUMMY;
}

bool SpellInfo::IsProfessionOrRiding() const
{
    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
    {
        if (Effects[i].Effect == SPELL_EFFECT_SKILL)
        {
            uint32 skill = Effects[i].MiscValue;

            if (IsProfessionOrRidingSkill(skill))
                return true;
        }
    }
    return false;
}

bool SpellInfo::IsProfession() const
{
    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
    {
        if (Effects[i].Effect == SPELL_EFFECT_SKILL)
        {
            uint32 skill = Effects[i].MiscValue;

            if (IsProfessionSkill(skill))
                return true;
        }
    }
    return false;
}

bool SpellInfo::IsPrimaryProfession() const
{
    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
    {
        if (Effects[i].Effect == SPELL_EFFECT_SKILL)
        {
            uint32 skill = Effects[i].MiscValue;

            if (IsPrimaryProfessionSkill(skill))
                return true;
        }
    }
    return false;
}

bool SpellInfo::IsPrimaryProfessionFirstRank() const
{
    return IsPrimaryProfession() && GetRank() == 1;
}

bool SpellInfo::IsAbilityLearnedWithProfession() const
{
    SkillLineAbilityMapBounds bounds = sSpellMgr->GetSkillLineAbilityMapBounds(Id);

    for (SkillLineAbilityMap::const_iterator _spell_idx = bounds.first; _spell_idx != bounds.second; ++_spell_idx)
    {
        SkillLineAbilityEntry const* pAbility = _spell_idx->second;
        if (!pAbility || pAbility->learnOnGetSkill != ABILITY_LEARNED_ON_GET_PROFESSION_SKILL)
            continue;

        if (pAbility->req_skill_value > 0)
            return true;
    }

    return false;
}

bool SpellInfo::IsAbilityOfSkillType(uint32 skillType) const
{
    SkillLineAbilityMapBounds bounds = sSpellMgr->GetSkillLineAbilityMapBounds(Id);

    for (SkillLineAbilityMap::const_iterator _spell_idx = bounds.first; _spell_idx != bounds.second; ++_spell_idx)
        if (_spell_idx->second->skillId == uint32(skillType))
            return true;

    return false;
}

bool SpellInfo::IsAOE() const
{
    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
        if (Effects[i].IsArea())
            return true;
    return false;
}

bool SpellInfo::IsRequiringSelectedTarget() const
{
    for (uint8 i = 0 ; i < MAX_SPELL_EFFECTS; ++i)
    {
        if (Effects[i].TargetA.GetType() == TARGET_TYPE_UNIT_TARGET
            || Effects[i].TargetB.GetType() == TARGET_TYPE_UNIT_TARGET
            || Effects[i].TargetA.GetType() == TARGET_TYPE_CHANNEL
            || Effects[i].TargetB.GetType() == TARGET_TYPE_CHANNEL
            || Effects[i].TargetA.GetType() == TARGET_TYPE_DEST_TARGET
            || Effects[i].TargetB.GetType() == TARGET_TYPE_DEST_TARGET)
            return true;
    }
    return false;
}

bool SpellInfo::IsPassive() const
{
    return Attributes & SPELL_ATTR0_PASSIVE;
}

bool SpellInfo::IsAutocastable() const
{
    if (Attributes & SPELL_ATTR0_PASSIVE)
        return false;
    if (AttributesEx & SPELL_ATTR1_UNAUTOCASTABLE_BY_PET)
        return false;
    return true;
}

bool SpellInfo::IsStackableWithRanks() const
{
    if (IsPassive())
        return false;
    if (PowerType != POWER_MANA && PowerType != POWER_HEALTH)
        return false;
    if (IsProfessionOrRiding())
        return false;

    if (IsAbilityLearnedWithProfession())
        return false;

    // All stance spells. if any better way, change it.
    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
    {
        switch (SpellFamilyName)
        {
            case SPELLFAMILY_PALADIN:
                // Paladin aura Spell
                if (Effects[i].Effect == SPELL_EFFECT_APPLY_AREA_AURA_RAID)
                    return false;
                break;
            case SPELLFAMILY_DRUID:
                // Druid form Spell
                if (Effects[i].Effect == SPELL_EFFECT_APPLY_AURA &&
                    Effects[i].ApplyAuraName == SPELL_AURA_MOD_SHAPESHIFT)
                    return false;
                break;
            case SPELLFAMILY_ROGUE:
                // Rogue Stealth
                if (Effects[i].Effect == SPELL_EFFECT_APPLY_AURA &&
                    Effects[i].ApplyAuraName == SPELL_AURA_MOD_SHAPESHIFT)
                    return false;
        }
    }
    return true;
}

bool SpellInfo::IsPassiveStackableWithRanks() const
{
    return IsPassive() && !HasEffect(SPELL_EFFECT_APPLY_AURA);
}

bool SpellInfo::IsMultiSlotAura() const
{
    return IsPassive() || Id == 44413;
}

bool SpellInfo::IsDeathPersistent() const
{
    return AttributesEx3 & SPELL_ATTR3_DEATH_PERSISTENT;
}

bool SpellInfo::IsRequiringDeadTarget() const
{
    return AttributesEx3 & SPELL_ATTR3_REQUIRE_DEAD_TARGET;
}

bool SpellInfo::IsAllowingDeadTarget() const
{
    return AttributesEx2 & SPELL_ATTR2_ALLOW_DEAD_TARGET;
}

bool SpellInfo::CanBeUsedInCombat() const
{
    return !(Attributes & SPELL_ATTR0_CANT_USED_IN_COMBAT);
}

bool SpellInfo::IsPositive() const
{
    return !(AttributesCu & SPELL_ATTR0_CU_NEGATIVE);
}

bool SpellInfo::IsPositiveEffect(uint8 effIndex) const
{
    switch (effIndex)
    {
        default:
        case 0:
            return !(AttributesCu & SPELL_ATTR0_CU_NEGATIVE_EFF0);
        case 1:
            return !(AttributesCu & SPELL_ATTR0_CU_NEGATIVE_EFF1);
        case 2:
            return !(AttributesCu & SPELL_ATTR0_CU_NEGATIVE_EFF2);
    }
}

bool SpellInfo::IsChanneled() const
{
    return (AttributesEx & (SPELL_ATTR1_CHANNELED_1 | SPELL_ATTR1_CHANNELED_2));
}

bool SpellInfo::NeedsComboPoints() const
{
    return (AttributesEx & (SPELL_ATTR1_REQ_COMBO_POINTS1 | SPELL_ATTR1_REQ_COMBO_POINTS2));
}

bool SpellInfo::IsBreakingStealth() const
{
    return !(AttributesEx & SPELL_ATTR1_NOT_BREAK_STEALTH);
}

bool SpellInfo::IsRangedWeaponSpell() const
{
    return (SpellFamilyName == SPELLFAMILY_HUNTER && !(SpellFamilyFlags[1] & 0x10000000)) // for 53352, cannot find better way
        || (EquippedItemSubClassMask & ITEM_SUBCLASS_MASK_WEAPON_RANGED);
}

bool SpellInfo::IsAutoRepeatRangedSpell() const
{
    return AttributesEx2 & SPELL_ATTR2_AUTOREPEAT_FLAG;
}

bool SpellInfo::IsAffectedBySpellMod(SpellModifier* mod) const
{
    SpellInfo const* affectSpell = sSpellMgr->GetSpellInfo(mod->spellId);
    // False if affect_spell == NULL or spellFamily not equal
    if (!affectSpell || affectSpell->SpellFamilyName != SpellFamilyName)
        return false;

    // true
    if (mod->mask  & SpellFamilyFlags)
        return true;

    return false;
}

bool SpellInfo::CanPierceImmuneAura(SpellInfo const* aura) const
{
    // these spells pierce all avalible spells (Resurrection Sickness for example)
    if (Attributes & SPELL_ATTR0_UNAFFECTED_BY_INVULNERABILITY)
        return true;

    // these spells (Cyclone for example) can pierce all...
    if ((AttributesEx & SPELL_ATTR1_UNAFFECTED_BY_SCHOOL_IMMUNE)
        // ...but not these (Divine shield for example)
        && !(aura && (aura->Mechanic == MECHANIC_IMMUNE_SHIELD || aura->Mechanic == MECHANIC_INVULNERABILITY)))
        return true;

    return false;
}

bool SpellInfo::CanDispelAura(SpellInfo const* aura) const
{
    // These auras (like ressurection sickness) can't be dispelled
    if (aura->Attributes & SPELL_ATTR0_NEGATIVE_1)
        return false;

    // These spells (like Mass Dispel) can dispell all auras
    if (Attributes & SPELL_ATTR0_UNAFFECTED_BY_INVULNERABILITY)
        return true;

    // These auras (like Divine Shield) can't be dispelled
    if (aura->Attributes & SPELL_ATTR0_UNAFFECTED_BY_INVULNERABILITY)
        return false;

    // These auras (Cyclone for example) are not dispelable
    if (aura->AttributesEx & SPELL_ATTR1_UNAFFECTED_BY_SCHOOL_IMMUNE)
        return false;

    return true;
}

bool SpellInfo::IsSingleTarget() const
{
    // all other single target spells have if it has AttributesEx5
    if (AttributesEx5 & SPELL_ATTR5_SINGLE_TARGET_SPELL)
        return true;

    switch (GetSpellSpecific())
    {
        case SPELL_SPECIFIC_JUDGEMENT:
            return true;
        default:
            break;
    }

    return false;
}

bool SpellInfo::IsSingleTargetWith(SpellInfo const* spellInfo) const
{
    // TODO - need better check
    // Equal icon and spellfamily
    if (SpellFamilyName == spellInfo->SpellFamilyName &&
        SpellIconID == spellInfo->SpellIconID)
        return true;

    SpellSpecificType spec = GetSpellSpecific();
    // spell with single target specific types
    switch (spec)
    {
        case SPELL_SPECIFIC_JUDGEMENT:
        case SPELL_SPECIFIC_MAGE_POLYMORPH:
            if (spellInfo->GetSpellSpecific() == spec)
                return true;
            break;
        default:
            break;
    }

    return false;
}

bool SpellInfo::IsAuraExclusiveBySpecificWith(SpellInfo const* spellInfo) const
{
    SpellSpecificType spellSpec = GetSpellSpecific();
    switch (spellSpec)
    {
        case SPELL_SPECIFIC_SEAL:
        case SPELL_SPECIFIC_HAND:
        case SPELL_SPECIFIC_AURA:
        case SPELL_SPECIFIC_STING:
        case SPELL_SPECIFIC_CURSE:
        case SPELL_SPECIFIC_ASPECT:
        case SPELL_SPECIFIC_JUDGEMENT:
        case SPELL_SPECIFIC_WARLOCK_CORRUPTION:
            return spellSpec == spellInfo->GetSpellSpecific();
        default:
            return false;
    }
}

bool SpellInfo::IsAuraExclusiveBySpecificPerCasterWith(SpellInfo const* spellInfo) const
{
    SpellSpecificType spellSpec1 = GetSpellSpecific();
    SpellSpecificType spellSpec2 = spellInfo->GetSpellSpecific();
    switch (spellSpec1)
    {
        case SPELL_SPECIFIC_PHASE:
        case SPELL_SPECIFIC_TRACKER:
        case SPELL_SPECIFIC_WARLOCK_ARMOR:
        case SPELL_SPECIFIC_MAGE_ARMOR:
        case SPELL_SPECIFIC_ELEMENTAL_SHIELD:
        case SPELL_SPECIFIC_MAGE_POLYMORPH:
        case SPELL_SPECIFIC_PRESENCE:
        case SPELL_SPECIFIC_CHARM:
        case SPELL_SPECIFIC_SCROLL:
        case SPELL_SPECIFIC_WARRIOR_ENRAGE:
        case SPELL_SPECIFIC_MAGE_ARCANE_BRILLANCE:
        case SPELL_SPECIFIC_PRIEST_DIVINE_SPIRIT:
            return spellSpec1 == spellSpec2;
        case SPELL_SPECIFIC_FOOD:
            return spellSpec2 == SPELL_SPECIFIC_FOOD
                || spellSpec2 == SPELL_SPECIFIC_FOOD_AND_DRINK;
        case SPELL_SPECIFIC_DRINK:
            return spellSpec2 == SPELL_SPECIFIC_DRINK
                || spellSpec2 == SPELL_SPECIFIC_FOOD_AND_DRINK;
        case SPELL_SPECIFIC_FOOD_AND_DRINK:
            return spellSpec2 == SPELL_SPECIFIC_FOOD
                || spellSpec2 == SPELL_SPECIFIC_DRINK
                || spellSpec2 == SPELL_SPECIFIC_FOOD_AND_DRINK;
        default:
            return false;
    }
}

SpellCastResult SpellInfo::CheckShapeshift(uint32 form) const
{
    // talents that learn spells can have stance requirements that need ignore
    // (this requirement only for client-side stance show in talent description)
    if (GetTalentSpellCost(Id) > 0 &&
        (Effects[0].Effect == SPELL_EFFECT_LEARN_SPELL || Effects[1].Effect == SPELL_EFFECT_LEARN_SPELL || Effects[2].Effect == SPELL_EFFECT_LEARN_SPELL))
        return SPELL_CAST_OK;

    uint32 stanceMask = (form ? 1 << (form - 1) : 0);

    if (stanceMask & StancesNot)                 // can explicitly not be casted in this stance
        return SPELL_FAILED_NOT_SHAPESHIFT;

    if (stanceMask & Stances)                    // can explicitly be casted in this stance
        return SPELL_CAST_OK;

    bool actAsShifted = false;
    SpellShapeshiftEntry const* shapeInfo = NULL;
    if (form > 0)
    {
        shapeInfo = sSpellShapeshiftStore.LookupEntry(form);
        if (!shapeInfo)
        {
            sLog->outError("GetErrorAtShapeshiftedCast: unknown shapeshift %u", form);
            return SPELL_CAST_OK;
        }
        actAsShifted = !(shapeInfo->flags1 & 1);            // shapeshift acts as normal form for spells
    }

    if (actAsShifted)
    {
        if (Attributes & SPELL_ATTR0_NOT_SHAPESHIFT) // not while shapeshifted
            return SPELL_FAILED_NOT_SHAPESHIFT;
        else if (Stances != 0)                   // needs other shapeshift
            return SPELL_FAILED_ONLY_SHAPESHIFT;
    }
    else
    {
        // needs shapeshift
        if (!(AttributesEx2 & SPELL_ATTR2_NOT_NEED_SHAPESHIFT) && Stances != 0)
            return SPELL_FAILED_ONLY_SHAPESHIFT;
    }

    // Check if stance disables cast of not-stance spells
    // Example: cannot cast any other spells in zombie or ghoul form
    // TODO: Find a way to disable use of these spells clientside
    if (shapeInfo && shapeInfo->flags1 & 0x400)
    {
        if (!(stanceMask & Stances))
            return SPELL_FAILED_ONLY_SHAPESHIFT;
    }

    return SPELL_CAST_OK;
}

SpellCastResult SpellInfo::CheckLocation(uint32 map_id, uint32 zone_id, uint32 area_id, Player const* player) const
{
    // normal case
    if (AreaGroupId > 0)
    {
        bool found = false;
        AreaGroupEntry const* groupEntry = sAreaGroupStore.LookupEntry(AreaGroupId);
        while (groupEntry)
        {
            for (uint8 i = 0; i < MAX_GROUP_AREA_IDS; ++i)
                if (groupEntry->AreaId[i] == zone_id || groupEntry->AreaId[i] == area_id)
                    found = true;
            if (found || !groupEntry->nextGroup)
                break;
            // Try search in next group
            groupEntry = sAreaGroupStore.LookupEntry(groupEntry->nextGroup);
        }

        if (!found)
            return SPELL_FAILED_INCORRECT_AREA;
    }

    // continent limitation (virtual continent)
    if (AttributesEx4 & SPELL_ATTR4_CAST_ONLY_IN_OUTLAND)
    {
        uint32 v_map = GetVirtualMapForMapAndZone(map_id, zone_id);
        MapEntry const* mapEntry = sMapStore.LookupEntry(v_map);
        if (!mapEntry || mapEntry->addon < 1 || !mapEntry->IsContinent())
            return SPELL_FAILED_INCORRECT_AREA;
    }

    // raid instance limitation
    if (AttributesEx6 & SPELL_ATTR6_NOT_IN_RAID_INSTANCE)
    {
        MapEntry const* mapEntry = sMapStore.LookupEntry(map_id);
        if (!mapEntry || mapEntry->IsRaid())
            return SPELL_FAILED_NOT_IN_RAID_INSTANCE;
    }

    // DB base check (if non empty then must fit at least single for allow)
    SpellAreaMapBounds saBounds = sSpellMgr->GetSpellAreaMapBounds(Id);
    if (saBounds.first != saBounds.second)
    {
        for (SpellAreaMap::const_iterator itr = saBounds.first; itr != saBounds.second; ++itr)
        {
            if (itr->second.IsFitToRequirements(player, zone_id, area_id))
                return SPELL_CAST_OK;
        }
        return SPELL_FAILED_INCORRECT_AREA;
    }

    // bg spell checks
    switch (Id)
    {
        case 23333:                                         // Warsong Flag
        case 23335:                                         // Silverwing Flag
            return map_id == 489 && player && player->InBattleground() ? SPELL_CAST_OK : SPELL_FAILED_REQUIRES_AREA;
        case 34976:                                         // Netherstorm Flag
            return map_id == 566 && player && player->InBattleground() ? SPELL_CAST_OK : SPELL_FAILED_REQUIRES_AREA;
        case 2584:                                          // Waiting to Resurrect
        case 22011:                                         // Spirit Heal Channel
        case 22012:                                         // Spirit Heal
        case 24171:                                         // Resurrection Impact Visual
        case 42792:                                         // Recently Dropped Flag
        case 43681:                                         // Inactive
        case 44535:                                         // Spirit Heal (mana)
        {
            MapEntry const* mapEntry = sMapStore.LookupEntry(map_id);
            if (!mapEntry)
                return SPELL_FAILED_INCORRECT_AREA;

            return zone_id == 4197 || (mapEntry->IsBattleground() && player && player->InBattleground()) ? SPELL_CAST_OK : SPELL_FAILED_REQUIRES_AREA;
        }
        case 44521:                                         // Preparation
        {
            if (!player)
                return SPELL_FAILED_REQUIRES_AREA;

            MapEntry const* mapEntry = sMapStore.LookupEntry(map_id);
            if (!mapEntry)
                return SPELL_FAILED_INCORRECT_AREA;

            if (!mapEntry->IsBattleground())
                return SPELL_FAILED_REQUIRES_AREA;

            Battleground* bg = player->GetBattleground();
            return bg && bg->GetStatus() == STATUS_WAIT_JOIN ? SPELL_CAST_OK : SPELL_FAILED_REQUIRES_AREA;
        }
        case 32724:                                         // Gold Team (Alliance)
        case 32725:                                         // Green Team (Alliance)
        case 35774:                                         // Gold Team (Horde)
        case 35775:                                         // Green Team (Horde)
        {
            MapEntry const* mapEntry = sMapStore.LookupEntry(map_id);
            if (!mapEntry)
                return SPELL_FAILED_INCORRECT_AREA;

            return mapEntry->IsBattleArena() && player && player->InBattleground() ? SPELL_CAST_OK : SPELL_FAILED_REQUIRES_AREA;
        }
        case 32727:                                         // Arena Preparation
        {
            if (!player)
                return SPELL_FAILED_REQUIRES_AREA;

            MapEntry const* mapEntry = sMapStore.LookupEntry(map_id);
            if (!mapEntry)
                return SPELL_FAILED_INCORRECT_AREA;

            if (!mapEntry->IsBattleArena())
                return SPELL_FAILED_REQUIRES_AREA;

            Battleground* bg = player->GetBattleground();
            return bg && bg->GetStatus() == STATUS_WAIT_JOIN ? SPELL_CAST_OK : SPELL_FAILED_REQUIRES_AREA;
        }
    }

    // aura limitations
    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
    {
        switch (Effects[i].ApplyAuraName)
        {
            case SPELL_AURA_MOD_INCREASE_MOUNTED_FLIGHT_SPEED:
            case SPELL_AURA_FLY:
            {
                if (player && !player->IsKnowHowFlyIn(map_id, zone_id))
                    return SPELL_FAILED_INCORRECT_AREA;
            }
        }
    }

    return SPELL_CAST_OK;
}

SpellSchoolMask SpellInfo::GetSchoolMask() const
{
    return SpellSchoolMask(SchoolMask);
}

uint32 SpellInfo::GetAllEffectsMechanicMask() const
{
    uint32 mask = 0;
    if (Mechanic)
        mask |= 1<< Mechanic;
    for (int i = 0; i < MAX_SPELL_EFFECTS; ++i)
        if (Effects[i].Mechanic)
            mask |= 1<< Effects[i].Mechanic;
    return mask;
}

uint32 SpellInfo::GetEffectMechanicMask(uint8 effIndex) const
{
    uint32 mask = 0;
    if (Mechanic)
        mask |= 1<< Mechanic;
    if (Effects[effIndex].Mechanic)
        mask |= 1<< Effects[effIndex].Mechanic;
    return mask;
}

Mechanics SpellInfo::GetEffectMechanic(uint8 effIndex) const
{
    if (Effects[effIndex].Mechanic)
        return Mechanics(Effects[effIndex].Mechanic);
    if (Mechanic)
        return Mechanics(Mechanic);
    return MECHANIC_NONE;
}

uint32 SpellInfo::GetDispelMask() const
{
    return SpellInfo::GetDispelMask(DispelType(Dispel));
}

uint32 SpellInfo::GetDispelMask(DispelType type)
{
    // If dispel all
    if (type == DISPEL_ALL)
        return DISPEL_ALL_MASK;
    else
        return uint32(1 << type);
}

AuraStateType SpellInfo::GetAuraState() const
{
    // Seals
    if (GetSpellSpecific() == SPELL_SPECIFIC_SEAL)
        return AURA_STATE_JUDGEMENT;

    // Conflagrate aura state on Immolate and Shadowflame
    if (SpellFamilyName == SPELLFAMILY_WARLOCK &&
        // Immolate
        ((SpellFamilyFlags[0] & 4) ||
        // Shadowflame
        (SpellFamilyFlags[2] & 2)))
        return AURA_STATE_CONFLAGRATE;

    // Faerie Fire (druid versions)
    if (SpellFamilyName == SPELLFAMILY_DRUID && SpellFamilyFlags[0] & 0x400)
        return AURA_STATE_FAERIE_FIRE;

    // Sting (hunter's pet ability)
    if (Category == 1133)
        return AURA_STATE_FAERIE_FIRE;

    // Victorious
    if (SpellFamilyName == SPELLFAMILY_WARRIOR &&  SpellFamilyFlags[1] & 0x00040000)
        return AURA_STATE_WARRIOR_VICTORY_RUSH;

    // Swiftmend state on Regrowth & Rejuvenation
    if (SpellFamilyName == SPELLFAMILY_DRUID && SpellFamilyFlags[0] & 0x50)
        return AURA_STATE_SWIFTMEND;

    // Deadly poison aura state
    if (SpellFamilyName == SPELLFAMILY_ROGUE && SpellFamilyFlags[0] & 0x10000)
        return AURA_STATE_DEADLY_POISON;

    // Enrage aura state
    if (Dispel == DISPEL_ENRAGE)
        return AURA_STATE_ENRAGE;

    // Bleeding aura state
    if (GetAllEffectsMechanicMask() & 1<<MECHANIC_BLEED)
        return AURA_STATE_BLEEDING;

    if (GetSchoolMask() & SPELL_SCHOOL_MASK_FROST)
        for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
            if (Effects[i].ApplyAuraName == SPELL_AURA_MOD_STUN
                || Effects[i].ApplyAuraName == SPELL_AURA_MOD_ROOT)
                return AURA_STATE_FROZEN;

    switch (Id)
    {
        case 71465: // Divine Surge
            return AURA_STATE_UNKNOWN22;
        default:
            break;
    }

    return AURA_STATE_NONE;
}

SpellSpecificType SpellInfo::GetSpellSpecific() const
{
    switch (SpellFamilyName)
    {
        case SPELLFAMILY_GENERIC:
        {
            // Food / Drinks (mostly)
            if (AuraInterruptFlags & AURA_INTERRUPT_FLAG_NOT_SEATED)
            {
                bool food = false;
                bool drink = false;
                for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
                {
                    switch (Effects[i].ApplyAuraName)
                    {
                        // Food
                        case SPELL_AURA_MOD_REGEN:
                        case SPELL_AURA_OBS_MOD_HEALTH:
                            food = true;
                            break;
                        // Drink
                        case SPELL_AURA_MOD_POWER_REGEN:
                        case SPELL_AURA_OBS_MOD_POWER:
                            drink = true;
                            break;
                        default:
                            break;
                    }
                }

                if (food && drink)
                    return SPELL_SPECIFIC_FOOD_AND_DRINK;
                else if (food)
                    return SPELL_SPECIFIC_FOOD;
                else if (drink)
                    return SPELL_SPECIFIC_DRINK;
            }
            // scrolls effects
            else
            {
                SpellInfo const* firstRankSpellInfo = GetFirstRankSpell();
                switch (firstRankSpellInfo->Id)
                {
                    case 8118: // Strength
                    case 8099: // Stamina
                    case 8112: // Spirit
                    case 8096: // Intellect
                    case 8115: // Agility
                    case 8091: // Armor
                        return SPELL_SPECIFIC_SCROLL;
                    case 12880: // Enrage (Enrage)
                    case 57518: // Enrage (Wrecking Crew)
                        return SPELL_SPECIFIC_WARRIOR_ENRAGE;
                }
            }
            break;
        }
        case SPELLFAMILY_MAGE:
        {
            // family flags 18(Molten), 25(Frost/Ice), 28(Mage)
            if (SpellFamilyFlags[0] & 0x12040000)
                return SPELL_SPECIFIC_MAGE_ARMOR;

            // Arcane brillance and Arcane intelect (normal check fails because of flags difference)
            if (SpellFamilyFlags[0] & 0x400)
                return SPELL_SPECIFIC_MAGE_ARCANE_BRILLANCE;

            if ((SpellFamilyFlags[0] & 0x1000000) && Effects[0].ApplyAuraName == SPELL_AURA_MOD_CONFUSE)
                return SPELL_SPECIFIC_MAGE_POLYMORPH;

            break;
        }
        case SPELLFAMILY_WARRIOR:
        {
            if (Id == 12292) // Death Wish
                return SPELL_SPECIFIC_WARRIOR_ENRAGE;

            break;
        }
        case SPELLFAMILY_WARLOCK:
        {
            // only warlock curses have this
            if (Dispel == DISPEL_CURSE)
                return SPELL_SPECIFIC_CURSE;

            // Warlock (Demon Armor | Demon Skin | Fel Armor)
            if (SpellFamilyFlags[1] & 0x20000020 || SpellFamilyFlags[2] & 0x00000010)
                return SPELL_SPECIFIC_WARLOCK_ARMOR;

            //seed of corruption and corruption
            if (SpellFamilyFlags[1] & 0x10 || SpellFamilyFlags[0] & 0x2)
                return SPELL_SPECIFIC_WARLOCK_CORRUPTION;
            break;
        }
        case SPELLFAMILY_PRIEST:
        {
            // Divine Spirit and Prayer of Spirit
            if (SpellFamilyFlags[0] & 0x20)
                return SPELL_SPECIFIC_PRIEST_DIVINE_SPIRIT;

            break;
        }
        case SPELLFAMILY_HUNTER:
        {
            // only hunter stings have this
            if (Dispel == DISPEL_POISON)
                return SPELL_SPECIFIC_STING;

            // only hunter aspects have this (but not all aspects in hunter family)
            if (SpellFamilyFlags.HasFlag(0x00380000, 0x00440000, 0x00001010))
                return SPELL_SPECIFIC_ASPECT;

            break;
        }
        case SPELLFAMILY_PALADIN:
        {
            // Collection of all the seal family flags. No other paladin spell has any of those.
            if (SpellFamilyFlags[1] & 0x26000C00
                || SpellFamilyFlags[0] & 0x0A000000)
                return SPELL_SPECIFIC_SEAL;

            if (SpellFamilyFlags[0] & 0x00002190)
                return SPELL_SPECIFIC_HAND;

            // Judgement of Wisdom, Judgement of Light, Judgement of Justice
            if (Id == 20184 || Id == 20185 || Id == 20186)
                return SPELL_SPECIFIC_JUDGEMENT;

            // only paladin auras have this (for palaldin class family)
            if (SpellFamilyFlags[2] & 0x00000020)
                return SPELL_SPECIFIC_AURA;

            break;
        }
        case SPELLFAMILY_SHAMAN:
        {
            // family flags 10 (Lightning), 42 (Earth), 37 (Water), proc shield from T2 8 pieces bonus
            if (SpellFamilyFlags[1] & 0x420
                || SpellFamilyFlags[0] & 0x00000400
                || Id == 23552)
                return SPELL_SPECIFIC_ELEMENTAL_SHIELD;

            break;
        }
        case SPELLFAMILY_DEATHKNIGHT:
            if (Id == 48266 || Id == 48263 || Id == 48265)
                return SPELL_SPECIFIC_PRESENCE;
            break;
    }

    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
    {
        if (Effects[i].Effect == SPELL_EFFECT_APPLY_AURA)
        {
            switch (Effects[i].ApplyAuraName)
            {
                case SPELL_AURA_MOD_CHARM:
                case SPELL_AURA_MOD_POSSESS_PET:
                case SPELL_AURA_MOD_POSSESS:
                case SPELL_AURA_AOE_CHARM:
                    return SPELL_SPECIFIC_CHARM;
                case SPELL_AURA_TRACK_CREATURES:
                case SPELL_AURA_TRACK_RESOURCES:
                case SPELL_AURA_TRACK_STEALTHED:
                    return SPELL_SPECIFIC_TRACKER;
                case SPELL_AURA_PHASE:
                    return SPELL_SPECIFIC_PHASE;
            }
        }
    }

    return SPELL_SPECIFIC_NORMAL;
}

float SpellInfo::GetMinRange(bool positive) const
{
    if (!RangeEntry)
        return 0.0f;
    if (positive)
        return RangeEntry->minRangeFriend;
    return RangeEntry->minRangeHostile;
}

float SpellInfo::GetMaxRange(bool positive) const
{
    if (!RangeEntry)
        return 0.0f;
    if (positive)
        return RangeEntry->maxRangeFriend;
    return RangeEntry->maxRangeHostile;
}

int32 SpellInfo::GetDuration() const
{
    if (!DurationEntry)
        return 0;
    return (DurationEntry->Duration[0] == -1) ? -1 : abs(DurationEntry->Duration[0]);
}

int32 SpellInfo::GetMaxDuration() const
{
    if (!DurationEntry)
        return 0;
    return (DurationEntry->Duration[2] == -1) ? -1 : abs(DurationEntry->Duration[2]);
}

uint32 SpellInfo::CalcCastTime(Unit* caster, Spell* spell) const
{
    // not all spells have cast time index and this is all is pasiive abilities
    if (!CastTimeEntry)
        return 0;

    int32 castTime = CastTimeEntry->CastTime;

    if (caster)
        caster->ModSpellCastTime(this, castTime, spell);

    if (Attributes & SPELL_ATTR0_REQ_AMMO && (!IsAutoRepeatRangedSpell()))
        castTime += 500;

    return (castTime > 0) ? uint32(castTime) : 0;
}

uint32 SpellInfo::GetRecoveryTime() const
{
    return RecoveryTime > CategoryRecoveryTime ? RecoveryTime : CategoryRecoveryTime;
}

uint32 SpellInfo::CalcPowerCost(Unit const* caster, SpellSchoolMask schoolMask) const
{
    // Spell drain all exist power on cast (Only paladin lay of Hands)
    if (AttributesEx & SPELL_ATTR1_DRAIN_ALL_POWER)
    {
        // If power type - health drain all
        if (PowerType == POWER_HEALTH)
            return caster->GetHealth();
        // Else drain all power
        if (PowerType < MAX_POWERS)
            return caster->GetPower(Powers(PowerType));
        sLog->outError("SpellInfo::CalcPowerCost: Unknown power type '%d' in spell %d", PowerType, Id);
        return 0;
    }

    // Base powerCost
    int32 powerCost = ManaCost;
    // PCT cost from total amount
    if (ManaCostPercentage)
    {
        switch (PowerType)
        {
            // health as power used
            case POWER_HEALTH:
                powerCost += int32(CalculatePctU(caster->GetCreateHealth(), ManaCostPercentage));
                break;
            case POWER_MANA:
                powerCost += int32(CalculatePctU(caster->GetCreateMana(), ManaCostPercentage));
                break;
            case POWER_RAGE:
            case POWER_FOCUS:
            case POWER_ENERGY:
            case POWER_HAPPINESS:
                powerCost += int32(CalculatePctU(caster->GetMaxPower(Powers(PowerType)), ManaCostPercentage));
                break;
            case POWER_RUNE:
            case POWER_RUNIC_POWER:
                sLog->outDebug(LOG_FILTER_SPELLS_AURAS, "CalculateManaCost: Not implemented yet!");
                break;
            default:
                sLog->outError("CalculateManaCost: Unknown power type '%d' in spell %d", PowerType, Id);
                return 0;
        }
    }
    SpellSchools school = GetFirstSchoolInMask(schoolMask);
    // Flat mod from caster auras by spell school
    powerCost += caster->GetInt32Value(UNIT_FIELD_POWER_COST_MODIFIER + school);
    // Shiv - costs 20 + weaponSpeed*10 energy (apply only to non-triggered spell with energy cost)
    if (AttributesEx4 & SPELL_ATTR4_SPELL_VS_EXTEND_COST)
        powerCost += caster->GetAttackTime(OFF_ATTACK) / 100;
    // Apply cost mod by spell
    if (Player* modOwner = caster->GetSpellModOwner())
        modOwner->ApplySpellMod(Id, SPELLMOD_COST, powerCost);

    if (Attributes & SPELL_ATTR0_LEVEL_DAMAGE_CALCULATION)
        powerCost = int32(powerCost / (1.117f * SpellLevel / caster->getLevel() -0.1327f));

    // PCT mod from user auras by school
    powerCost = int32(powerCost * (1.0f + caster->GetFloatValue(UNIT_FIELD_POWER_COST_MULTIPLIER + school)));
    if (powerCost < 0)
        powerCost = 0;
    return powerCost;
}

bool SpellInfo::IsRanked() const
{
    return ChainEntry != NULL;
}

uint8 SpellInfo::GetRank() const
{
    if (!ChainEntry)
        return 1;
    return ChainEntry->rank;
}

SpellInfo const* SpellInfo::GetFirstRankSpell() const
{
    if (!ChainEntry)
        return this;
    return ChainEntry->first;
}
SpellInfo const* SpellInfo::GetLastRankSpell() const
{
    if (!ChainEntry)
        return NULL;
    return ChainEntry->last;
}
SpellInfo const* SpellInfo::GetNextRankSpell() const
{
    if (!ChainEntry)
        return NULL;
    return ChainEntry->next;
}
SpellInfo const* SpellInfo::GetPrevRankSpell() const
{
    if (!ChainEntry)
        return NULL;
    return ChainEntry->prev;
}

SpellInfo const* SpellInfo::GetAuraRankForLevel(uint8 level) const
{
    // ignore passive spells
    if (IsPassive())
        return this;

    bool needRankSelection = false;
    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
    {
        if (IsPositiveEffect(i) &&
            (Effects[i].Effect == SPELL_EFFECT_APPLY_AURA ||
            Effects[i].Effect == SPELL_EFFECT_APPLY_AREA_AURA_PARTY ||
            Effects[i].Effect == SPELL_EFFECT_APPLY_AREA_AURA_RAID))
        {
            needRankSelection = true;
            break;
        }
    }

    // not required
    if (!needRankSelection)
        return this;

    for (SpellInfo const* nextSpellInfo = this; nextSpellInfo != NULL; nextSpellInfo = nextSpellInfo->GetPrevRankSpell())
    {
        // if found appropriate level
        if (uint32(level + 10) >= nextSpellInfo->SpellLevel)
            return nextSpellInfo;

        // one rank less then
    }

    // not found
    return NULL;
}

bool SpellInfo::IsRankOf(SpellInfo const* spellInfo) const
{
    return GetFirstRankSpell() == spellInfo->GetFirstRankSpell();
}

bool SpellInfo::IsDifferentRankOf(SpellInfo const* spellInfo) const
{
    if (Id == spellInfo->Id)
        return false;
    return IsRankOf(spellInfo);
}

bool SpellInfo::IsHighRankOf(SpellInfo const* spellInfo) const
{
    if (ChainEntry && spellInfo->ChainEntry)
    {
        if (ChainEntry->first == spellInfo->ChainEntry->first)
            if (ChainEntry->rank > spellInfo->ChainEntry->rank)
                return true;
    }
    return false;
}

bool SpellInfo::_IsPositiveEffect(uint8 effIndex, bool deep) const
{
    // not found a single positive spell with this attribute
    if (Attributes & SPELL_ATTR0_NEGATIVE_1)
        return false;

    switch (SpellFamilyName)
    {
        case SPELLFAMILY_GENERIC:
            switch (Id)
            {
                case 34700: // Allergic Reaction
                case 61716: // Rabbit Costume
                case 61734: // Noblegarden Bunny
                case 61987: // Avenging Wrath Marker
                case 61988: // Divine Shield exclude aura
                case 62532: // Conservator's Grip
                    return false;
                case 30877: // Tag Murloc
                case 62344: // Fists of Stone
                    return true;
                default:
                    break;
            }
            break;
        case SPELLFAMILY_MAGE:
            // Amplify Magic, Dampen Magic
            if (SpellFamilyFlags[0] == 0x00002000)
                return true;
            // Ignite
            if (SpellIconID == 45)
                return true;
            break;
        case SPELLFAMILY_PRIEST:
            switch (Id)
            {
                case 64844: // Divine Hymn
                case 64904: // Hymn of Hope
                case 47585: // Dispersion
                    return true;
                default:
                    break;
            }
            break;
        case SPELLFAMILY_HUNTER:
            // Aspect of the Viper
            if (Id == 34074)
                return true;
            break;
        case SPELLFAMILY_SHAMAN:
            if (Id == 30708)
                return false;
            break;
        default:
            break;
    }

    switch (Mechanic)
    {
        case MECHANIC_IMMUNE_SHIELD:
            return true;
        default:
            break;
    }

    // Special case: effects which determine positivity of whole spell
    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
    {
        if (Effects[i].ApplyAuraName == SPELL_AURA_MOD_STEALTH)
            return true;
    }

    switch (Effects[effIndex].Effect)
    {
        case SPELL_EFFECT_DUMMY:
            // some explicitly required dummy effect sets
            switch (Id)
            {
                case 28441:
                    return false; // AB Effect 000
                default:
                    break;
            }
            break;
        // always positive effects (check before target checks that provided non-positive result in some case for positive effects)
        case SPELL_EFFECT_HEAL:
        case SPELL_EFFECT_LEARN_SPELL:
        case SPELL_EFFECT_SKILL_STEP:
        case SPELL_EFFECT_HEAL_PCT:
        case SPELL_EFFECT_ENERGIZE_PCT:
            return true;

            // non-positive aura use
        case SPELL_EFFECT_APPLY_AURA:
        case SPELL_EFFECT_APPLY_AREA_AURA_FRIEND:
        {
            switch (Effects[effIndex].ApplyAuraName)
            {
                case SPELL_AURA_MOD_DAMAGE_DONE:            // dependent from bas point sign (negative -> negative)
                case SPELL_AURA_MOD_STAT:
                case SPELL_AURA_MOD_SKILL:
                case SPELL_AURA_MOD_DODGE_PERCENT:
                case SPELL_AURA_MOD_HEALING_PCT:
                case SPELL_AURA_MOD_HEALING_DONE:
                case SPELL_AURA_MOD_DAMAGE_PERCENT_DONE:
                    if (Effects[effIndex].CalcValue() < 0)
                        return false;
                    break;
                case SPELL_AURA_MOD_DAMAGE_TAKEN:           // dependent from bas point sign (positive -> negative)
                    if (Effects[effIndex].CalcValue() > 0)
                        return false;
                    break;
                case SPELL_AURA_MOD_CRIT_PCT:
                case SPELL_AURA_MOD_SPELL_CRIT_CHANCE:
                    if (Effects[effIndex].CalcValue() > 0)
                        return true;                        // some expected positive spells have SPELL_ATTR1_NEGATIVE
                    break;
                case SPELL_AURA_ADD_TARGET_TRIGGER:
                    return true;
                case SPELL_AURA_PERIODIC_TRIGGER_SPELL_WITH_VALUE:
                case SPELL_AURA_PERIODIC_TRIGGER_SPELL:
                    if (!deep)
                    {
                        if (SpellInfo const* spellTriggeredProto = sSpellMgr->GetSpellInfo(Effects[effIndex].TriggerSpell))
                        {
                            // negative targets of main spell return early
                            for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
                            {
                                if (!spellTriggeredProto->Effects[i].Effect)
                                    continue;
                                // if non-positive trigger cast targeted to positive target this main cast is non-positive
                                // this will place this spell auras as debuffs
                                if (_IsPositiveTarget(spellTriggeredProto->Effects[i].TargetA.GetTarget(), spellTriggeredProto->Effects[effIndex].TargetB.GetTarget()) && !spellTriggeredProto->_IsPositiveEffect(i, true))
                                    return false;
                            }
                        }
                    }
                case SPELL_AURA_PROC_TRIGGER_SPELL:
                    // many positive auras have negative triggered spells at damage for example and this not make it negative (it can be canceled for example)
                    break;
                case SPELL_AURA_MOD_STUN:                   //have positive and negative spells, we can't sort its correctly at this moment.
                    if (effIndex == 0 && Effects[1].Effect == 0 && Effects[2].Effect == 0)
                        return false;                       // but all single stun aura spells is negative
                    break;
                case SPELL_AURA_MOD_PACIFY_SILENCE:
                    if (Id == 24740)             // Wisp Costume
                        return true;
                    return false;
                case SPELL_AURA_MOD_ROOT:
                case SPELL_AURA_MOD_SILENCE:
                case SPELL_AURA_GHOST:
                case SPELL_AURA_PERIODIC_LEECH:
                case SPELL_AURA_MOD_STALKED:
                case SPELL_AURA_PERIODIC_DAMAGE_PERCENT:
                case SPELL_AURA_PREVENT_RESSURECTION:
                    return false;
                case SPELL_AURA_PERIODIC_DAMAGE:            // used in positive spells also.
                    // part of negative spell if casted at self (prevent cancel)
                    if (Effects[effIndex].TargetA.GetTarget() == TARGET_UNIT_CASTER)
                        return false;
                    break;
                case SPELL_AURA_MOD_DECREASE_SPEED:         // used in positive spells also
                    // part of positive spell if casted at self
                    if (Effects[effIndex].TargetA.GetTarget() != TARGET_UNIT_CASTER)
                        return false;
                    // but not this if this first effect (didn't find better check)
                    if (Attributes & SPELL_ATTR0_NEGATIVE_1 && effIndex == 0)
                        return false;
                    break;
                case SPELL_AURA_MECHANIC_IMMUNITY:
                {
                    // non-positive immunities
                    switch (Effects[effIndex].MiscValue)
                    {
                        case MECHANIC_BANDAGE:
                        case MECHANIC_SHIELD:
                        case MECHANIC_MOUNT:
                        case MECHANIC_INVULNERABILITY:
                            return false;
                        default:
                            break;
                    }
                    break;
                }
                case SPELL_AURA_ADD_FLAT_MODIFIER:          // mods
                case SPELL_AURA_ADD_PCT_MODIFIER:
                {
                    // non-positive mods
                    switch (Effects[effIndex].MiscValue)
                    {
                        case SPELLMOD_COST:                 // dependent from bas point sign (negative -> positive)
                            if (Effects[effIndex].CalcValue() > 0)
                            {
                                if (!deep)
                                {
                                    bool negative = true;
                                    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
                                    {
                                        if (i != effIndex)
                                            if (_IsPositiveEffect(i, true))
                                            {
                                                negative = false;
                                                break;
                                            }
                                    }
                                    if (negative)
                                        return false;
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
            break;
        }
        default:
            break;
    }

    // non-positive targets
    if (!_IsPositiveTarget(Effects[effIndex].TargetA.GetTarget(), Effects[effIndex].TargetB.GetTarget()))
        return false;

    // negative spell if triggered spell is negative
    if (!deep && !Effects[effIndex].ApplyAuraName && Effects[effIndex].TriggerSpell)
    {
        if (SpellInfo const* spellTriggeredProto = sSpellMgr->GetSpellInfo(Effects[effIndex].TriggerSpell))
            if (!spellTriggeredProto->_IsPositiveSpell())
                return false;
    }

    // ok, positive
    return true;
}

bool SpellInfo::_IsPositiveSpell() const
{
    // spells with at least one negative effect are considered negative
    // some self-applied spells have negative effects but in self casting case negative check ignored.
    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
        if (!_IsPositiveEffect(i, true))
            return false;
    return true;
}

bool SpellInfo::_IsPositiveTarget(uint32 targetA, uint32 targetB)
{
    // non-positive targets
    switch (targetA)
    {
        case TARGET_UNIT_NEARBY_ENEMY:
        case TARGET_UNIT_TARGET_ENEMY:
        case TARGET_UNIT_AREA_ENEMY_SRC:
        case TARGET_UNIT_AREA_ENEMY_DST:
        case TARGET_UNIT_CONE_ENEMY:
        case TARGET_UNIT_AREA_PATH:
        case TARGET_DEST_DYNOBJ_ENEMY:
        case TARGET_DST_TARGET_ENEMY:
            return false;
        default:
            break;
    }
    if (targetB)
        return _IsPositiveTarget(targetB, 0);
    return true;
}
