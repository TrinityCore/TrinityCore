/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#ifndef UpdateFields_h__
#define UpdateFields_h__

#include "EnumClassFlag.h"
#include "ObjectGuid.h"
#include "Position.h"
#include "QuaternionData.h"
#include "UpdateField.h"
#include "UpdateMask.h"

class AreaTrigger;
class Bag;
class ByteBuffer;
class Conversation;
class Corpse;
class DynamicObject;
class GameObject;
class Item;
class Object;
class Player;
class Unit;

namespace UF
{
struct ObjectData : public IsUpdateFieldStructureTag, public HasChangesMask<4>
{
    UpdateField<int32, 0, 1> EntryID;
    UpdateField<uint32, 0, 2> DynamicFlags;
    struct DynamicFlagsTag : ViewerDependentValueTag<uint32> {};
    UpdateField<float, 0, 3> Scale;

    void WriteCreate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Object const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Object const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

struct ItemEnchantment : public IsUpdateFieldStructureTag, public HasChangesMask<5>
{
    UpdateField<int32, 0, 1> ID;
    UpdateField<uint32, 0, 2> Duration;
    UpdateField<int16, 0, 3> Charges;
    UpdateField<uint16, 0, 4> Inactive;

    void WriteCreate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Item const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Item const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

struct ArtifactPower : public IsUpdateFieldStructureTag
{
    int16 ArtifactPowerID;
    uint8 PurchasedRank;
    uint8 CurrentRankWithBonus;

    void WriteCreate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Item const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Item const* owner, Player const* receiver) const;
};

struct SocketedGem : public IsUpdateFieldStructureTag, public HasChangesMask<20>
{
    UpdateField<int32, 0, 1> ItemID;
    UpdateField<uint8, 0, 2> Context;
    UpdateFieldArray<uint16, 16, 3, 4> BonusListIDs;

    void WriteCreate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Item const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Item const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

struct ItemData : public IsUpdateFieldStructureTag, public HasChangesMask<40>
{
    UpdateField<std::vector<int32>, 0, 1> BonusListIDs;
    DynamicUpdateField<int32, 0, 2> Modifiers;
    DynamicUpdateField<ArtifactPower, 0, 3> ArtifactPowers;
    DynamicUpdateField<SocketedGem, 0, 4> Gems;
    UpdateField<ObjectGuid, 0, 5> Owner;
    UpdateField<ObjectGuid, 0, 6> ContainedIn;
    UpdateField<ObjectGuid, 0, 7> Creator;
    UpdateField<ObjectGuid, 0, 8> GiftCreator;
    UpdateField<uint32, 0, 9> StackCount;
    UpdateField<uint32, 0, 10> Expiration;
    UpdateField<uint32, 0, 11> DynamicFlags;
    UpdateField<uint32, 0, 12> Durability;
    UpdateField<uint32, 0, 13> MaxDurability;
    UpdateField<uint32, 0, 14> CreatePlayedTime;
    UpdateField<uint32, 0, 15> ModifiersMask;
    UpdateField<int32, 0, 16> Context;
    UpdateField<uint64, 0, 17> ArtifactXP;
    UpdateField<uint8, 0, 18> ItemAppearanceModID;
    UpdateField<uint32, 0, 19> Field_130;
    UpdateFieldArray<int32, 5, 20, 21> SpellCharges;
    UpdateFieldArray<ItemEnchantment, 13, 26, 27> Enchantment;

    void WriteCreate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Item const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Item const* owner, Player const* receiver) const;
    void AppendAllowedFieldsMaskForFlag(UpdateMask<40>& allowedMaskForTarget, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags) const;
    void WriteUpdate(ByteBuffer& data, UpdateMask<40> const& changesMask, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Item const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

struct ContainerData : public IsUpdateFieldStructureTag, public HasChangesMask<39>
{
    UpdateField<uint32, 0, 1> NumSlots;
    UpdateFieldArray<ObjectGuid, 36, 2, 3> Slots;

    void WriteCreate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Bag const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Bag const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

struct AzeriteEmpoweredItemData : public IsUpdateFieldStructureTag, public HasChangesMask<6>
{
    UpdateFieldArray<int32, 5, 0, 1> Selections;

    void WriteCreate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Item const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Item const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

struct AzeriteItemData : public IsUpdateFieldStructureTag, public HasChangesMask<6>
{
    UpdateField<uint64, 0, 1> Xp;
    UpdateField<uint32, 0, 2> Level;
    UpdateField<uint32, 0, 3> AuraLevel;
    UpdateField<uint32, 0, 4> KnowledgeLevel;
    UpdateField<uint32, 0, 5> DEBUGknowledgeWeek;

    void WriteCreate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Item const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Item const* owner, Player const* receiver) const;
    void AppendAllowedFieldsMaskForFlag(UpdateMask<6>& allowedMaskForTarget, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags) const;
    void WriteUpdate(ByteBuffer& data, UpdateMask<6> const& changesMask, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Item const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

struct UnitChannel : public IsUpdateFieldStructureTag
{
    int32 SpellID;
    int32 SpellXSpellVisualID;

    void WriteCreate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Unit const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Unit const* owner, Player const* receiver) const;
};

struct VisibleItem : public IsUpdateFieldStructureTag, public HasChangesMask<4>
{
    UpdateField<int32, 0, 1> ItemID;
    UpdateField<uint16, 0, 2> ItemAppearanceModID;
    UpdateField<uint16, 0, 3> ItemVisual;

    void WriteCreate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Unit const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Unit const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

struct PassiveSpellHistory : public IsUpdateFieldStructureTag
{
    int32 SpellID;
    int32 AuraSpellID;

    void WriteCreate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Unit const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Unit const* owner, Player const* receiver) const;
};

struct UnitData : public IsUpdateFieldStructureTag, public HasChangesMask<191>
{
    UpdateField<std::vector<uint32>, 0, 1> StateWorldEffectIDs;
    DynamicUpdateField<PassiveSpellHistory, 0, 2> PassiveSpells;
    DynamicUpdateField<int32, 0, 3> WorldEffects;
    DynamicUpdateField<ObjectGuid, 0, 4> ChannelObjects;
    UpdateField<int32, 0, 5> DisplayID;
    struct DisplayIDTag : ViewerDependentValueTag<int32> {};
    UpdateField<uint32, 0, 6> StateSpellVisualID;
    UpdateField<uint32, 0, 7> StateAnimID;
    UpdateField<uint32, 0, 8> StateAnimKitID;
    UpdateField<uint32, 0, 9> StateWorldEffectsQuestObjectiveID;
    UpdateField<ObjectGuid, 0, 10> Charm;
    UpdateField<ObjectGuid, 0, 11> Summon;
    UpdateField<ObjectGuid, 0, 12> Critter;
    UpdateField<ObjectGuid, 0, 13> CharmedBy;
    UpdateField<ObjectGuid, 0, 14> SummonedBy;
    UpdateField<ObjectGuid, 0, 15> CreatedBy;
    UpdateField<ObjectGuid, 0, 16> DemonCreator;
    UpdateField<ObjectGuid, 0, 17> LookAtControllerTarget;
    UpdateField<ObjectGuid, 0, 18> Target;
    UpdateField<ObjectGuid, 0, 19> BattlePetCompanionGUID;
    UpdateField<uint64, 0, 20> BattlePetDBID;
    UpdateField<UnitChannel, 0, 21> ChannelData;
    UpdateField<uint32, 0, 22> SummonedByHomeRealm;
    UpdateField<uint8, 0, 23> Race;
    UpdateField<uint8, 0, 24> ClassId;
    UpdateField<uint8, 0, 25> PlayerClassId;
    UpdateField<uint8, 0, 26> Sex;
    UpdateField<uint8, 0, 27> DisplayPower;
    UpdateField<uint32, 0, 28> OverrideDisplayPowerID;
    UpdateField<int64, 0, 29> Health;
    UpdateField<int64, 0, 30> MaxHealth;
    UpdateField<int32, 0, 31> Level;
    UpdateField<int32, 32, 33> EffectiveLevel;
    UpdateField<int32, 32, 34> ContentTuningID;
    UpdateField<int32, 32, 35> ScalingLevelMin;
    UpdateField<int32, 32, 36> ScalingLevelMax;
    UpdateField<int32, 32, 37> ScalingLevelDelta;
    UpdateField<int32, 32, 38> ScalingFactionGroup;
    UpdateField<int32, 32, 39> ScalingHealthItemLevelCurveID;
    UpdateField<int32, 32, 40> ScalingDamageItemLevelCurveID;
    UpdateField<int32, 32, 41> FactionTemplate;
    struct FactionTemplateTag : ViewerDependentValueTag<int32> {};
    UpdateField<uint32, 32, 42> Flags;
    struct FlagsTag : ViewerDependentValueTag<uint32> {};
    UpdateField<uint32, 32, 43> Flags2;
    UpdateField<uint32, 32, 44> Flags3;
    UpdateField<uint32, 32, 45> AuraState;
    struct AuraStateTag : ViewerDependentValueTag<uint32> {};
    UpdateField<uint32, 32, 46> RangedAttackRoundBaseTime;
    UpdateField<float, 32, 47> BoundingRadius;
    UpdateField<float, 32, 48> CombatReach;
    UpdateField<float, 32, 49> DisplayScale;
    UpdateField<int32, 32, 50> NativeDisplayID;
    UpdateField<float, 32, 51> NativeXDisplayScale;
    UpdateField<int32, 32, 52> MountDisplayID;
    UpdateField<int32, 32, 53> CosmeticMountDisplayID;
    UpdateField<float, 32, 54> MinDamage;
    UpdateField<float, 32, 55> MaxDamage;
    UpdateField<float, 32, 56> MinOffHandDamage;
    UpdateField<float, 32, 57> MaxOffHandDamage;
    UpdateField<uint8, 32, 58> StandState;
    UpdateField<uint8, 32, 59> PetTalentPoints;
    UpdateField<uint8, 32, 60> VisFlags;
    UpdateField<uint8, 32, 61> AnimTier;
    UpdateField<uint32, 32, 62> PetNumber;
    UpdateField<uint32, 32, 63> PetNameTimestamp;
    UpdateField<uint32, 64, 65> PetExperience;
    UpdateField<uint32, 64, 66> PetNextLevelExperience;
    UpdateField<float, 64, 67> ModCastingSpeed;
    UpdateField<float, 64, 68> ModSpellHaste;
    UpdateField<float, 64, 69> ModHaste;
    UpdateField<float, 64, 70> ModRangedHaste;
    UpdateField<float, 64, 71> ModHasteRegen;
    UpdateField<float, 64, 72> ModTimeRate;
    UpdateField<int32, 64, 73> CreatedBySpell;
    UpdateField<int32, 64, 74> EmoteState;
    UpdateField<int32, 64, 75> BaseMana;
    UpdateField<int32, 64, 76> BaseHealth;
    UpdateField<uint8, 64, 77> SheatheState;
    UpdateField<uint8, 64, 78> PvpFlags;
    struct PvpFlagsTag : ViewerDependentValueTag<uint8> {};
    UpdateField<uint8, 64, 79> PetFlags;
    UpdateField<uint8, 64, 80> ShapeshiftForm;
    UpdateField<int32, 64, 81> AttackPower;
    UpdateField<int32, 64, 82> AttackPowerModPos;
    UpdateField<int32, 64, 83> AttackPowerModNeg;
    UpdateField<float, 64, 84> AttackPowerMultiplier;
    UpdateField<int32, 64, 85> RangedAttackPower;
    UpdateField<int32, 64, 86> RangedAttackPowerModPos;
    UpdateField<int32, 64, 87> RangedAttackPowerModNeg;
    UpdateField<float, 64, 88> RangedAttackPowerMultiplier;
    UpdateField<int32, 64, 89> MainHandWeaponAttackPower;
    UpdateField<int32, 64, 90> OffHandWeaponAttackPower;
    UpdateField<int32, 64, 91> RangedWeaponAttackPower;
    UpdateField<int32, 64, 92> SetAttackSpeedAura;
    UpdateField<float, 64, 93> Lifesteal;
    UpdateField<float, 64, 94> MinRangedDamage;
    UpdateField<float, 64, 95> MaxRangedDamage;
    UpdateField<float, 96, 97> ManaCostModifierModifier;
    UpdateField<float, 96, 98> MaxHealthModifier;
    UpdateField<float, 96, 99> HoverHeight;
    UpdateField<int32, 96, 100> MinItemLevelCutoff;
    UpdateField<int32, 96, 101> MinItemLevel;
    UpdateField<int32, 96, 102> MaxItemLevel;
    UpdateField<int32, 96, 103> AzeriteItemLevel;
    UpdateField<int32, 96, 104> WildBattlePetLevel;
    UpdateField<uint32, 96, 105> BattlePetCompanionNameTimestamp;
    UpdateField<int32, 96, 106> InteractSpellID;
    UpdateField<int32, 96, 107> ScaleDuration;
    UpdateField<int32, 96, 108> SpellOverrideNameID;
    UpdateField<int32, 96, 109> LooksLikeMountID;
    UpdateField<int32, 96, 110> LooksLikeCreatureID;
    UpdateField<int32, 96, 111> LookAtControllerID;
    UpdateField<int32, 96, 112> TaxiNodesID;
    UpdateField<ObjectGuid, 96, 113> GuildGUID;
    UpdateFieldArray<uint32, 2, 114, 115> NpcFlags;
    struct NpcFlagsTag : ViewerDependentValueTag<uint32> {};
    UpdateFieldArray<int32, 6, 117, 118> Power;
    UpdateFieldArray<int32, 6, 117, 124> MaxPower;
    UpdateFieldArray<float, 6, 117, 130> PowerRegenFlatModifier;
    UpdateFieldArray<float, 6, 117, 136> PowerRegenInterruptedFlatModifier;
    UpdateFieldArray<VisibleItem, 3, 142, 143> VirtualItems;
    UpdateFieldArray<uint32, 2, 146, 147> AttackRoundBaseTime;
    UpdateFieldArray<int32, 4, 149, 150> Stats;
    UpdateFieldArray<int32, 4, 149, 154> StatPosBuff;
    UpdateFieldArray<int32, 4, 149, 158> StatNegBuff;
    UpdateFieldArray<int32, 7, 162, 163> Resistances;
    UpdateFieldArray<int32, 7, 162, 170> BonusResistanceMods;
    UpdateFieldArray<int32, 7, 162, 177> PowerCostModifier;
    UpdateFieldArray<float, 7, 162, 184> PowerCostMultiplier;

    void WriteCreate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Unit const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Unit const* owner, Player const* receiver) const;
    void AppendAllowedFieldsMaskForFlag(UpdateMask<191>& allowedMaskForTarget, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags) const;
    void WriteUpdate(ByteBuffer& data, UpdateMask<191> const& changesMask, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Unit const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

struct QuestLog : public IsUpdateFieldStructureTag, public HasChangesMask<30>
{
    UpdateField<int32, 0, 1> QuestID;
    UpdateField<uint32, 0, 2> StateFlags;
    UpdateField<uint32, 0, 3> EndTime;
    UpdateField<uint32, 0, 4> AcceptTime;
    UpdateFieldArray<int16, 24, 5, 6> ObjectiveProgress;

    void WriteCreate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Player const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Player const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

struct ArenaCooldown : public IsUpdateFieldStructureTag, public HasChangesMask<8>
{
    UpdateField<int32, 0, 1> SpellID;
    UpdateField<int32, 0, 2> Charges;
    UpdateField<uint32, 0, 3> Flags;
    UpdateField<uint32, 0, 4> StartTime;
    UpdateField<uint32, 0, 5> EndTime;
    UpdateField<uint32, 0, 6> NextChargeTime;
    UpdateField<uint8, 0, 7> MaxCharges;

    void WriteCreate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Player const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Player const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

struct PlayerData : public IsUpdateFieldStructureTag, public HasChangesMask<161>
{
    DynamicUpdateField<ArenaCooldown, 0, 1> ArenaCooldowns;
    UpdateField<ObjectGuid, 0, 2> DuelArbiter;
    UpdateField<ObjectGuid, 0, 3> WowAccount;
    UpdateField<ObjectGuid, 0, 4> LootTargetGUID;
    UpdateField<uint32, 0, 5> PlayerFlags;
    UpdateField<uint32, 0, 6> PlayerFlagsEx;
    UpdateField<uint32, 0, 7> GuildRankID;
    UpdateField<uint32, 0, 8> GuildDeleteDate;
    UpdateField<int32, 0, 9> GuildLevel;
    UpdateField<uint8, 0, 10> SkinID;
    UpdateField<uint8, 0, 11> FaceID;
    UpdateField<uint8, 0, 12> HairStyleID;
    UpdateField<uint8, 0, 13> HairColorID;
    UpdateField<uint8, 0, 14> FacialHairStyleID;
    UpdateField<uint8, 0, 15> PartyType;
    UpdateField<uint8, 0, 16> NativeSex;
    UpdateField<uint8, 0, 17> Inebriation;
    UpdateField<uint8, 0, 18> PvpTitle;
    UpdateField<uint8, 0, 19> ArenaFaction;
    UpdateField<uint32, 0, 20> DuelTeam;
    UpdateField<int32, 0, 21> GuildTimeStamp;
    UpdateField<int32, 0, 22> PlayerTitle;
    UpdateField<int32, 0, 23> FakeInebriation;
    UpdateField<uint32, 0, 24> VirtualPlayerRealm;
    UpdateField<uint32, 0, 25> CurrentSpecID;
    UpdateField<int32, 0, 26> TaxiMountAnimKitID;
    UpdateField<uint8, 0, 27> CurrentBattlePetBreedQuality;
    UpdateField<int32, 0, 28> HonorLevel;
    UpdateField<int32, 0, 29> Field_B0;
    UpdateField<int32, 0, 30> Field_B4;
    UpdateFieldArray<uint8, 3, 31, 32> CustomDisplayOption;
    UpdateFieldArray<QuestLog, 100, 35, 36> QuestLog;
    UpdateFieldArray<VisibleItem, 19, 136, 137> VisibleItems;
    UpdateFieldArray<float, 4, 156, 157> AvgItemLevel;

    void WriteCreate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Player const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Player const* owner, Player const* receiver) const;
    void AppendAllowedFieldsMaskForFlag(UpdateMask<161>& allowedMaskForTarget, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags) const;
    void WriteUpdate(ByteBuffer& data, UpdateMask<161> const& changesMask, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Player const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

struct SkillInfo : public IsUpdateFieldStructureTag, public HasChangesMask<1793>
{
    UpdateFieldArray<uint16, 256, 0, 1> SkillLineID;
    UpdateFieldArray<uint16, 256, 0, 257> SkillStep;
    UpdateFieldArray<uint16, 256, 0, 513> SkillRank;
    UpdateFieldArray<uint16, 256, 0, 769> SkillStartingRank;
    UpdateFieldArray<uint16, 256, 0, 1025> SkillMaxRank;
    UpdateFieldArray<int16, 256, 0, 1281> SkillTempBonus;
    UpdateFieldArray<uint16, 256, 0, 1537> SkillPermBonus;

    void WriteCreate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Player const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Player const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

struct RestInfo : public IsUpdateFieldStructureTag, public HasChangesMask<3>
{
    UpdateField<uint32, 0, 1> Threshold;
    UpdateField<uint8, 0, 2> StateID;

    void WriteCreate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Player const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Player const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

struct PVPInfo : public IsUpdateFieldStructureTag, public HasChangesMask<10>
{
    UpdateField<uint32, 0, 1> Field_0;
    UpdateField<uint32, 0, 2> Field_4;
    UpdateField<uint32, 0, 3> Field_8;
    UpdateField<uint32, 0, 4> Field_C;
    UpdateField<uint32, 0, 5> Rating;
    UpdateField<uint32, 0, 6> Field_14;
    UpdateField<uint32, 0, 7> Field_18;
    UpdateField<uint32, 0, 8> PvpTierID;
    UpdateField<uint32, 0, 9> Field_20;

    void WriteCreate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Player const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Player const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

struct CharacterRestriction : public IsUpdateFieldStructureTag
{
    int32 Field_0;
    int32 Field_4;
    int32 Field_8;
    uint32 Type;

    void WriteCreate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Player const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Player const* owner, Player const* receiver) const;
};

struct SpellPctModByLabel : public IsUpdateFieldStructureTag
{
    int32 ModIndex;
    float ModifierValue;
    int32 LabelID;

    void WriteCreate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Player const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Player const* owner, Player const* receiver) const;
};

struct SpellFlatModByLabel : public IsUpdateFieldStructureTag
{
    int32 ModIndex;
    int32 ModifierValue;
    int32 LabelID;

    void WriteCreate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Player const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Player const* owner, Player const* receiver) const;
};

struct Research : public IsUpdateFieldStructureTag
{
    int16 ResearchProjectID;

    void WriteCreate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Player const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Player const* owner, Player const* receiver) const;
};

struct ActivePlayerData : public IsUpdateFieldStructureTag, public HasChangesMask<1455>
{
    UpdateField<bool, 0, 1> BackpackAutoSortDisabled;
    UpdateField<bool, 0, 2> BankAutoSortDisabled;
    UpdateField<bool, 0, 3> SortBagsRightToLeft;
    UpdateField<bool, 0, 4> InsertItemsLeftToRight;
    UpdateFieldArray<DynamicUpdateField<Research, -1, -1>, 1, 20, 21> Research;
    DynamicUpdateField<uint64, 0, 5> KnownTitles;
    DynamicUpdateField<uint16, 0, 6> ResearchSites;
    DynamicUpdateField<uint32, 0, 7> ResearchSiteProgress;
    DynamicUpdateField<int32, 0, 8> DailyQuestsCompleted;
    DynamicUpdateField<int32, 0, 9> AvailableQuestLineXQuestIDs;
    DynamicUpdateField<int32, 0, 10> Heirlooms;
    DynamicUpdateField<uint32, 0, 11> HeirloomFlags;
    DynamicUpdateField<int32, 0, 12> Toys;
    DynamicUpdateField<uint32, 0, 13> ToyFlags;
    DynamicUpdateField<uint32, 0, 14> Transmog;
    DynamicUpdateField<int32, 0, 15> ConditionalTransmog;
    DynamicUpdateField<int32, 0, 16> SelfResSpells;
    DynamicUpdateField<SpellPctModByLabel, 0, 17> SpellPctModByLabel;
    DynamicUpdateField<SpellFlatModByLabel, 0, 18> SpellFlatModByLabel;
    DynamicUpdateField<CharacterRestriction, 0, 19> CharacterRestrictions;
    UpdateField<ObjectGuid, 0, 22> FarsightObject;
    UpdateField<ObjectGuid, 0, 23> SummonedBattlePetGUID;
    UpdateField<uint64, 0, 24> Coinage;
    UpdateField<int32, 0, 25> XP;
    UpdateField<int32, 0, 26> NextLevelXP;
    UpdateField<int32, 0, 27> TrialXP;
    UpdateField<SkillInfo, 0, 28> Skill;
    UpdateField<int32, 0, 29> CharacterPoints;
    UpdateField<int32, 0, 30> MaxTalentTiers;
    UpdateField<int32, 0, 31> TrackCreatureMask;
    UpdateField<float, 0, 32> MainhandExpertise;
    UpdateField<float, 0, 33> OffhandExpertise;
    UpdateField<float, 34, 35> RangedExpertise;
    UpdateField<float, 34, 36> CombatRatingExpertise;
    UpdateField<float, 34, 37> BlockPercentage;
    UpdateField<float, 34, 38> DodgePercentage;
    UpdateField<float, 34, 39> DodgePercentageFromAttribute;
    UpdateField<float, 34, 40> ParryPercentage;
    UpdateField<float, 34, 41> ParryPercentageFromAttribute;
    UpdateField<float, 34, 42> CritPercentage;
    UpdateField<float, 34, 43> RangedCritPercentage;
    UpdateField<float, 34, 44> OffhandCritPercentage;
    UpdateField<float, 34, 45> SpellCritPercentage;
    UpdateField<int32, 34, 46> ShieldBlock;
    UpdateField<float, 34, 47> ShieldBlockCritPercentage;
    UpdateField<float, 34, 48> Mastery;
    UpdateField<float, 34, 49> Speed;
    UpdateField<float, 34, 50> Avoidance;
    UpdateField<float, 34, 51> Sturdiness;
    UpdateField<int32, 34, 52> Versatility;
    UpdateField<float, 34, 53> VersatilityBonus;
    UpdateField<float, 34, 54> PvpPowerDamage;
    UpdateField<float, 34, 55> PvpPowerHealing;
    UpdateField<int32, 34, 56> ModHealingDonePos;
    UpdateField<float, 34, 57> ModHealingPercent;
    UpdateField<float, 34, 58> ModHealingDonePercent;
    UpdateField<float, 34, 59> ModPeriodicHealingDonePercent;
    UpdateField<float, 34, 60> ModSpellPowerPercent;
    UpdateField<float, 34, 61> ModResiliencePercent;
    UpdateField<float, 34, 62> OverrideSpellPowerByAPPercent;
    UpdateField<float, 34, 63> OverrideAPBySpellPowerPercent;
    UpdateField<int32, 34, 64> ModTargetResistance;
    UpdateField<int32, 34, 65> ModTargetPhysicalResistance;
    UpdateField<int32, 66, 67> LocalFlags;
    UpdateField<uint8, 66, 68> GrantableLevels;
    UpdateField<uint8, 66, 69> MultiActionBars;
    UpdateField<uint8, 66, 70> LifetimeMaxRank;
    UpdateField<uint8, 66, 71> NumRespecs;
    UpdateField<uint32, 66, 72> PvpMedals;
    UpdateField<uint16, 66, 73> TodayHonorableKills;
    UpdateField<uint16, 66, 74> YesterdayHonorableKills;
    UpdateField<uint32, 66, 75> LifetimeHonorableKills;
    UpdateField<int32, 66, 76> WatchedFactionIndex;
    UpdateField<int32, 66, 77> MaxLevel;
    UpdateField<int32, 66, 78> ScalingPlayerLevelDelta;
    UpdateField<int32, 66, 79> MaxCreatureScalingLevel;
    UpdateField<int32, 66, 80> PetSpellPower;
    UpdateField<float, 66, 81> UiHitModifier;
    UpdateField<float, 66, 82> UiSpellHitModifier;
    UpdateField<int32, 66, 83> HomeRealmTimeOffset;
    UpdateField<float, 66, 84> ModPetHaste;
    UpdateField<uint8, 66, 85> LocalRegenFlags;
    UpdateField<uint8, 66, 86> AuraVision;
    UpdateField<uint8, 66, 87> NumBackpackSlots;
    UpdateField<int32, 66, 88> OverrideSpellsID;
    UpdateField<int32, 66, 89> LfgBonusFactionID;
    UpdateField<uint16, 66, 90> LootSpecID;
    UpdateField<uint32, 66, 91> OverrideZonePVPType;
    UpdateField<int32, 66, 92> Honor;
    UpdateField<int32, 66, 93> HonorNextLevel;
    UpdateField<int32, 66, 94> PvpRewardAchieved;
    UpdateField<int32, 66, 95> PvpTierMaxFromWins;
    UpdateField<int32, 66, 96> PvpLastWeeksRewardAchieved;
    UpdateField<int32, 66, 97> PvpLastWeeksTierMaxFromWins;
    UpdateField<int32, 98, 99> PvpLastWeeksRewardClaimed;
    UpdateField<uint8, 98, 100> NumBankSlots;
    UpdateFieldArray<ObjectGuid, 195, 101, 102> InvSlots;
    UpdateFieldArray<uint32, 2, 297, 298> TrackResourceMask;
    UpdateFieldArray<uint64, 160, 300, 301> ExploredZones;
    UpdateFieldArray<RestInfo, 2, 461, 462> RestInfo;
    UpdateFieldArray<int32, 7, 464, 465> ModDamageDonePos;
    UpdateFieldArray<int32, 7, 464, 472> ModDamageDoneNeg;
    UpdateFieldArray<float, 7, 464, 479> ModDamageDonePercent;
    UpdateFieldArray<float, 3, 486, 487> WeaponDmgMultipliers;
    UpdateFieldArray<float, 3, 486, 490> WeaponAtkSpeedMultipliers;
    UpdateFieldArray<uint32, 12, 493, 494> BuybackPrice;
    UpdateFieldArray<uint32, 12, 493, 506> BuybackTimestamp;
    UpdateFieldArray<int32, 32, 518, 519> CombatRatings;
    UpdateFieldArray<PVPInfo, 6, 551, 552> PvpInfo;
    UpdateFieldArray<uint32, 4, 558, 559> NoReagentCostMask;
    UpdateFieldArray<int32, 2, 563, 564> ProfessionSkillLine;
    UpdateFieldArray<uint32, 4, 566, 567> BagSlotFlags;
    UpdateFieldArray<uint32, 7, 571, 572> BankBagSlotFlags;
    UpdateFieldArray<uint64, 875, 579, 580> QuestCompleted;

    void WriteCreate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Player const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Player const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

struct GameObjectData : public IsUpdateFieldStructureTag, public HasChangesMask<20>
{
    UpdateField<std::vector<uint32>, 0, 1> StateWorldEffectIDs;
    DynamicUpdateField<int32, 0, 2> EnableDoodadSets;
    UpdateField<int32, 0, 3> DisplayID;
    UpdateField<uint32, 0, 4> SpellVisualID;
    UpdateField<uint32, 0, 5> StateSpellVisualID;
    UpdateField<uint32, 0, 6> SpawnTrackingStateAnimID;
    UpdateField<uint32, 0, 7> SpawnTrackingStateAnimKitID;
    UpdateField<uint32, 0, 8> StateWorldEffectsQuestObjectiveID;
    UpdateField<ObjectGuid, 0, 9> CreatedBy;
    UpdateField<ObjectGuid, 0, 10> GuildGUID;
    UpdateField<uint32, 0, 11> Flags;
    struct FlagsTag : ViewerDependentValueTag<uint32> {};
    UpdateField<QuaternionData, 0, 12> ParentRotation;
    UpdateField<int32, 0, 13> FactionTemplate;
    UpdateField<int32, 0, 14> Level;
    struct LevelTag : ViewerDependentValueTag<int32> {};
    UpdateField<int8, 0, 15> State;
    struct StateTag : ViewerDependentValueTag<int8> {};
    UpdateField<int8, 0, 16> TypeID;
    UpdateField<uint8, 0, 17> ArtKit;
    UpdateField<uint8, 0, 18> PercentHealth;
    UpdateField<uint32, 0, 19> CustomParam;

    void WriteCreate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, GameObject const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, GameObject const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

struct DynamicObjectData : public IsUpdateFieldStructureTag, public HasChangesMask<7>
{
    UpdateField<ObjectGuid, 0, 1> Caster;
    UpdateField<int32, 0, 2> SpellXSpellVisualID;
    UpdateField<int32, 0, 3> SpellID;
    UpdateField<float, 0, 4> Radius;
    UpdateField<uint32, 0, 5> CastTime;
    UpdateField<uint8, 0, 6> Type;

    void WriteCreate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, DynamicObject const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, DynamicObject const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

struct CorpseData : public IsUpdateFieldStructureTag, public HasChangesMask<40>
{
    UpdateField<uint32, 0, 1> DynamicFlags;
    UpdateField<ObjectGuid, 0, 2> Owner;
    UpdateField<ObjectGuid, 0, 3> PartyGUID;
    UpdateField<ObjectGuid, 0, 4> GuildGUID;
    UpdateField<uint32, 0, 5> DisplayID;
    UpdateField<uint8, 0, 6> Unused;
    UpdateField<uint8, 0, 7> RaceID;
    UpdateField<uint8, 0, 8> Sex;
    UpdateField<uint8, 0, 9> SkinID;
    UpdateField<uint8, 0, 10> FaceID;
    UpdateField<uint8, 0, 11> HairStyleID;
    UpdateField<uint8, 0, 12> HairColorID;
    UpdateField<uint8, 0, 13> FacialHairStyleID;
    UpdateField<uint32, 0, 14> Flags;
    UpdateField<int32, 0, 15> FactionTemplate;
    UpdateFieldArray<uint32, 19, 16, 17> Items;
    UpdateFieldArray<uint8, 3, 36, 37> CustomDisplayOption;

    void WriteCreate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Corpse const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Corpse const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

struct ScaleCurve : public IsUpdateFieldStructureTag
{
    bool OverrideActive;
    uint32 StartTimeOffset;
    uint32 ParameterCurve;
    TaggedPosition<Position::XY> Points[2];

    void WriteCreate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, AreaTrigger const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, AreaTrigger const* owner, Player const* receiver) const;
};

struct AreaTriggerData : public IsUpdateFieldStructureTag, public HasChangesMask<14>
{
    UpdateField<ScaleCurve, 0, 1> OverrideScaleCurve;
    UpdateField<ScaleCurve, 0, 2> ExtraScaleCurve;
    UpdateField<ObjectGuid, 0, 3> Caster;
    UpdateField<uint32, 0, 4> Duration;
    UpdateField<uint32, 0, 5> TimeToTarget;
    UpdateField<uint32, 0, 6> TimeToTargetScale;
    UpdateField<uint32, 0, 7> TimeToTargetExtraScale;
    UpdateField<int32, 0, 8> SpellID;
    UpdateField<int32, 0, 9> SpellForVisuals;
    UpdateField<int32, 0, 10> SpellXSpellVisualID;
    UpdateField<float, 0, 11> BoundsRadius2D;
    UpdateField<uint32, 0, 12> DecalPropertiesID;
    UpdateField<ObjectGuid, 0, 13> CreatingEffectGUID;

    void WriteCreate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, AreaTrigger const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, AreaTrigger const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

struct SceneObjectData : public IsUpdateFieldStructureTag, public HasChangesMask<5>
{
    UpdateField<int32, 0, 1> ScriptPackageID;
    UpdateField<uint32, 0, 2> RndSeedVal;
    UpdateField<ObjectGuid, 0, 3> CreatedBy;
    UpdateField<uint32, 0, 4> SceneType;

    void WriteCreate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Object const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Object const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

struct ConversationLine : public IsUpdateFieldStructureTag
{
    int32 ConversationLineID;
    uint32 StartTime;
    int32 UiCameraID;
    uint8 ActorIndex;
    uint8 Flags;

    void WriteCreate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Conversation const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Conversation const* owner, Player const* receiver) const;
};

struct ConversationActor : public IsUpdateFieldStructureTag
{
    uint32 CreatureID;
    uint32 CreatureDisplayInfoID;
    ObjectGuid ActorGUID;
    int32 Field_18;
    uint32 Type;

    void WriteCreate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Conversation const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Conversation const* owner, Player const* receiver) const;
};

struct ConversationData : public IsUpdateFieldStructureTag, public HasChangesMask<4>
{
    UpdateField<std::vector<ConversationLine>, 0, 1> Lines;
    DynamicUpdateField<ConversationActor, 0, 2> Actors;
    UpdateField<int32, 0, 3> LastLineEndTime;

    void WriteCreate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Conversation const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Conversation const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

}

#endif // UpdateFields_h__
