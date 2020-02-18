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

#ifndef UpdateFields_h__
#define UpdateFields_h__

#include "EnumClassFlag.h"
#include "ObjectGuid.h"
#include "Position.h"
#include "QuaternionData.h"
#include "UpdateField.h"
#include "UpdateMask.h"

class AreaTrigger;
class AzeriteEmpoweredItem;
class AzeriteItem;
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

    void WriteCreate(ByteBuffer& data, Item const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, Item const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

struct ArtifactPower : public IsUpdateFieldStructureTag
{
    int16 ArtifactPowerID;
    uint8 PurchasedRank;
    uint8 CurrentRankWithBonus;

    void WriteCreate(ByteBuffer& data, Item const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, Item const* owner, Player const* receiver) const;
};

struct SocketedGem : public IsUpdateFieldStructureTag, public HasChangesMask<20>
{
    UpdateField<int32, 0, 1> ItemID;
    UpdateField<uint8, 0, 2> Context;
    UpdateFieldArray<uint16, 16, 3, 4> BonusListIDs;

    void WriteCreate(ByteBuffer& data, Item const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, Item const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

struct ItemData : public IsUpdateFieldStructureTag, public HasChangesMask<40>
{
    UpdateField<std::vector<int32>, 0, 1> BonusListIDs;
    DynamicUpdateField<int32, 0, 2> Modifiers;
    DynamicUpdateField<UF::ArtifactPower, 0, 3> ArtifactPowers;
    DynamicUpdateField<UF::SocketedGem, 0, 4> Gems;
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
    UpdateField<uint32, 0, 19> DynamicFlags2;
    UpdateFieldArray<int32, 5, 20, 21> SpellCharges;
    UpdateFieldArray<UF::ItemEnchantment, 13, 26, 27> Enchantment;

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

    void WriteCreate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, AzeriteEmpoweredItem const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, AzeriteEmpoweredItem const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

struct UnlockedAzeriteEssence : public IsUpdateFieldStructureTag
{
    uint32 AzeriteEssenceID;
    uint32 Rank;

    void WriteCreate(ByteBuffer& data, AzeriteItem const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, AzeriteItem const* owner, Player const* receiver) const;
};

struct SelectedAzeriteEssences : public IsUpdateFieldStructureTag, public HasChangesMask<8>
{
    UpdateField<uint32, 0, 1> SpecializationID;
    UpdateField<uint32, 0, 2> Enabled;
    UpdateFieldArray<uint32, 4, 3, 4> AzeriteEssenceID;

    void WriteCreate(ByteBuffer& data, AzeriteItem const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, AzeriteItem const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

struct AzeriteItemData : public IsUpdateFieldStructureTag, public HasChangesMask<9>
{
    DynamicUpdateField<UF::UnlockedAzeriteEssence, 0, 1> UnlockedEssences;
    DynamicUpdateField<uint32, 0, 3> UnlockedEssenceMilestones;
    DynamicUpdateField<UF::SelectedAzeriteEssences, 0, 2> SelectedEssences;
    UpdateField<uint64, 0, 4> Xp;
    UpdateField<uint32, 0, 5> Level;
    UpdateField<uint32, 0, 6> AuraLevel;
    UpdateField<uint32, 0, 7> KnowledgeLevel;
    UpdateField<int32, 0, 8> DEBUGknowledgeWeek;

    void WriteCreate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, AzeriteItem const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, AzeriteItem const* owner, Player const* receiver) const;
    void AppendAllowedFieldsMaskForFlag(UpdateMask<9>& allowedMaskForTarget, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags) const;
    void WriteUpdate(ByteBuffer& data, UpdateMask<9> const& changesMask, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, AzeriteItem const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

struct UnitChannel : public IsUpdateFieldStructureTag
{
    int32 SpellID;
    int32 SpellXSpellVisualID;

    void WriteCreate(ByteBuffer& data, Unit const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, Unit const* owner, Player const* receiver) const;
};

struct VisibleItem : public IsUpdateFieldStructureTag, public HasChangesMask<4>
{
    UpdateField<int32, 0, 1> ItemID;
    UpdateField<uint16, 0, 2> ItemAppearanceModID;
    UpdateField<uint16, 0, 3> ItemVisual;

    void WriteCreate(ByteBuffer& data, Unit const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, Unit const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

struct PassiveSpellHistory : public IsUpdateFieldStructureTag
{
    int32 SpellID;
    int32 AuraSpellID;

    void WriteCreate(ByteBuffer& data, Unit const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, Unit const* owner, Player const* receiver) const;
};

struct UnitData : public IsUpdateFieldStructureTag, public HasChangesMask<192>
{
    UpdateField<std::vector<uint32>, 0, 1> StateWorldEffectIDs;
    DynamicUpdateField<UF::PassiveSpellHistory, 0, 2> PassiveSpells;
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
    UpdateField<UF::UnitChannel, 0, 21> ChannelData;
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
    UpdateField<ObjectGuid, 96, 114> SkinningOwnerGUID;
    UpdateFieldArray<uint32, 2, 115, 116> NpcFlags;
    struct NpcFlagsTag : ViewerDependentValueTag<uint32> {};
    UpdateFieldArray<int32, 6, 118, 119> Power;
    UpdateFieldArray<int32, 6, 118, 125> MaxPower;
    UpdateFieldArray<float, 6, 118, 131> PowerRegenFlatModifier;
    UpdateFieldArray<float, 6, 118, 137> PowerRegenInterruptedFlatModifier;
    UpdateFieldArray<UF::VisibleItem, 3, 143, 144> VirtualItems;
    UpdateFieldArray<uint32, 2, 147, 148> AttackRoundBaseTime;
    UpdateFieldArray<int32, 4, 150, 151> Stats;
    UpdateFieldArray<int32, 4, 150, 155> StatPosBuff;
    UpdateFieldArray<int32, 4, 150, 159> StatNegBuff;
    UpdateFieldArray<int32, 7, 163, 164> Resistances;
    UpdateFieldArray<int32, 7, 163, 171> BonusResistanceMods;
    UpdateFieldArray<int32, 7, 163, 178> PowerCostModifier;
    UpdateFieldArray<float, 7, 163, 185> PowerCostMultiplier;

    void WriteCreate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Unit const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Unit const* owner, Player const* receiver) const;
    void AppendAllowedFieldsMaskForFlag(UpdateMask<192>& allowedMaskForTarget, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags) const;
    void WriteUpdate(ByteBuffer& data, UpdateMask<192> const& changesMask, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Unit const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

struct QuestLog : public IsUpdateFieldStructureTag, public HasChangesMask<31>
{
    UpdateField<int32, 0, 1> QuestID;
    UpdateField<uint32, 0, 2> StateFlags;
    UpdateField<uint32, 0, 3> EndTime;
    UpdateField<uint32, 0, 4> AcceptTime;
    UpdateField<uint32, 0, 5> Field_10;
    UpdateFieldArray<int16, 24, 6, 7> ObjectiveProgress;

    void WriteCreate(ByteBuffer& data, Player const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, Player const* owner, Player const* receiver) const;
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

    void WriteCreate(ByteBuffer& data, Player const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, Player const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

struct PlayerData : public IsUpdateFieldStructureTag, public HasChangesMask<192>
{
    UpdateField<bool, 0, 1> HasQuestSession;
    UpdateField<bool, 0, 2> HasLevelLink;
    DynamicUpdateField<UF::QuestLog, 0, 3> QuestSessionQuestLog;
    DynamicUpdateField<UF::ArenaCooldown, 0, 4> ArenaCooldowns;
    UpdateField<ObjectGuid, 0, 5> DuelArbiter;
    UpdateField<ObjectGuid, 0, 6> WowAccount;
    UpdateField<ObjectGuid, 0, 7> LootTargetGUID;
    UpdateField<uint32, 0, 8> PlayerFlags;
    UpdateField<uint32, 0, 9> PlayerFlagsEx;
    UpdateField<uint32, 0, 10> GuildRankID;
    UpdateField<uint32, 0, 11> GuildDeleteDate;
    UpdateField<int32, 0, 12> GuildLevel;
    UpdateField<uint8, 0, 13> SkinID;
    UpdateField<uint8, 0, 14> FaceID;
    UpdateField<uint8, 0, 15> HairStyleID;
    UpdateField<uint8, 0, 16> HairColorID;
    UpdateField<uint8, 0, 17> FacialHairStyleID;
    UpdateField<uint8, 0, 18> PartyType;
    UpdateField<uint8, 0, 19> NativeSex;
    UpdateField<uint8, 0, 20> Inebriation;
    UpdateField<uint8, 0, 21> PvpTitle;
    UpdateField<uint8, 0, 22> ArenaFaction;
    UpdateField<uint32, 0, 23> DuelTeam;
    UpdateField<int32, 0, 24> GuildTimeStamp;
    UpdateField<int32, 0, 25> PlayerTitle;
    UpdateField<int32, 0, 26> FakeInebriation;
    UpdateField<uint32, 0, 27> VirtualPlayerRealm;
    UpdateField<uint32, 0, 28> CurrentSpecID;
    UpdateField<int32, 0, 29> TaxiMountAnimKitID;
    UpdateField<uint8, 0, 30> CurrentBattlePetBreedQuality;
    UpdateField<int32, 0, 31> HonorLevel;
    UpdateField<int32, 32, 33> Field_B0;
    UpdateField<int32, 32, 34> Field_B4;
    UpdateField<ObjectGuid, 32, 35> Field_F8;
    UpdateField<int32, 32, 36> Field_108;
    UpdateFieldArray<uint8, 3, 37, 38> CustomDisplayOption;
    UpdateFieldArray<UF::QuestLog, 125, 41, 42> QuestLog;
    UpdateFieldArray<UF::VisibleItem, 19, 167, 168> VisibleItems;
    UpdateFieldArray<float, 4, 187, 188> AvgItemLevel;

    void WriteCreate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Player const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Player const* owner, Player const* receiver) const;
    void AppendAllowedFieldsMaskForFlag(UpdateMask<192>& allowedMaskForTarget, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags) const;
    void WriteUpdate(ByteBuffer& data, UpdateMask<192> const& changesMask, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Player const* owner, Player const* receiver) const;
    void ClearChangesMask();
    bool IsQuestLogChangesMaskSkipped() const { return false; } // bandwidth savings aren't worth the cpu time
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

    void WriteCreate(ByteBuffer& data, Player const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, Player const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

struct RestInfo : public IsUpdateFieldStructureTag, public HasChangesMask<3>
{
    UpdateField<uint32, 0, 1> Threshold;
    UpdateField<uint8, 0, 2> StateID;

    void WriteCreate(ByteBuffer& data, Player const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, Player const* owner, Player const* receiver) const;
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

    void WriteCreate(ByteBuffer& data, Player const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, Player const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

struct CharacterRestriction : public IsUpdateFieldStructureTag
{
    int32 Field_0;
    int32 Field_4;
    int32 Field_8;
    uint32 Type;

    void WriteCreate(ByteBuffer& data, Player const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, Player const* owner, Player const* receiver) const;
};

struct SpellPctModByLabel : public IsUpdateFieldStructureTag
{
    int32 ModIndex;
    float ModifierValue;
    int32 LabelID;

    void WriteCreate(ByteBuffer& data, Player const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, Player const* owner, Player const* receiver) const;
};

struct SpellFlatModByLabel : public IsUpdateFieldStructureTag
{
    int32 ModIndex;
    int32 ModifierValue;
    int32 LabelID;

    void WriteCreate(ByteBuffer& data, Player const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, Player const* owner, Player const* receiver) const;
};

struct Research : public IsUpdateFieldStructureTag
{
    int16 ResearchProjectID;

    void WriteCreate(ByteBuffer& data, Player const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, Player const* owner, Player const* receiver) const;
};

struct ReplayedQuest : public IsUpdateFieldStructureTag, public HasChangesMask<3>
{
    UpdateField<int32, 0, 1> QuestID;
    UpdateField<uint32, 0, 2> ReplayTime;

    void WriteCreate(ByteBuffer& data, Player const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, Player const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

struct QuestSession : public IsUpdateFieldStructureTag, public HasChangesMask<878>
{
    UpdateField<ObjectGuid, 0, 1> Owner;
    UpdateFieldArray<uint64, 875, 2, 3> QuestCompleted;

    void WriteCreate(ByteBuffer& data, Player const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, Player const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

struct ActivePlayerData : public IsUpdateFieldStructureTag, public HasChangesMask<1494>
{
    UpdateField<bool, 0, 1> BackpackAutoSortDisabled;
    UpdateField<bool, 0, 2> BankAutoSortDisabled;
    UpdateField<bool, 0, 3> SortBagsRightToLeft;
    UpdateField<bool, 0, 4> InsertItemsLeftToRight;
    UpdateFieldArray<DynamicUpdateField<UF::Research, -1, -1>, 1, 22, 23> Research;
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
    DynamicUpdateField<UF::SpellPctModByLabel, 0, 18> SpellPctModByLabel;
    DynamicUpdateField<UF::SpellFlatModByLabel, 0, 19> SpellFlatModByLabel;
    DynamicUpdateField<UF::ReplayedQuest, 0, 20> ReplayedQuests;
    DynamicUpdateField<int32, 0, 21> DisabledSpells;
    DynamicUpdateField<UF::CharacterRestriction, 0, 17> CharacterRestrictions;
    UpdateField<ObjectGuid, 0, 24> FarsightObject;
    UpdateField<ObjectGuid, 0, 25> SummonedBattlePetGUID;
    UpdateField<uint64, 0, 26> Coinage;
    UpdateField<int32, 0, 27> XP;
    UpdateField<int32, 0, 28> NextLevelXP;
    UpdateField<int32, 0, 29> TrialXP;
    UpdateField<UF::SkillInfo, 0, 30> Skill;
    UpdateField<int32, 0, 31> CharacterPoints;
    UpdateField<int32, 0, 32> MaxTalentTiers;
    UpdateField<int32, 0, 33> TrackCreatureMask;
    UpdateField<float, 34, 35> MainhandExpertise;
    UpdateField<float, 34, 36> OffhandExpertise;
    UpdateField<float, 34, 37> RangedExpertise;
    UpdateField<float, 34, 38> CombatRatingExpertise;
    UpdateField<float, 34, 39> BlockPercentage;
    UpdateField<float, 34, 40> DodgePercentage;
    UpdateField<float, 34, 41> DodgePercentageFromAttribute;
    UpdateField<float, 34, 42> ParryPercentage;
    UpdateField<float, 34, 43> ParryPercentageFromAttribute;
    UpdateField<float, 34, 44> CritPercentage;
    UpdateField<float, 34, 45> RangedCritPercentage;
    UpdateField<float, 34, 46> OffhandCritPercentage;
    UpdateField<float, 34, 47> SpellCritPercentage;
    UpdateField<int32, 34, 48> ShieldBlock;
    UpdateField<float, 34, 49> ShieldBlockCritPercentage;
    UpdateField<float, 34, 50> Mastery;
    UpdateField<float, 34, 51> Speed;
    UpdateField<float, 34, 52> Avoidance;
    UpdateField<float, 34, 53> Sturdiness;
    UpdateField<int32, 34, 54> Versatility;
    UpdateField<float, 34, 55> VersatilityBonus;
    UpdateField<float, 34, 56> PvpPowerDamage;
    UpdateField<float, 34, 57> PvpPowerHealing;
    UpdateField<int32, 34, 58> ModHealingDonePos;
    UpdateField<float, 34, 59> ModHealingPercent;
    UpdateField<float, 34, 60> ModHealingDonePercent;
    UpdateField<float, 34, 61> ModPeriodicHealingDonePercent;
    UpdateField<float, 34, 62> ModSpellPowerPercent;
    UpdateField<float, 34, 63> ModResiliencePercent;
    UpdateField<float, 34, 64> OverrideSpellPowerByAPPercent;
    UpdateField<float, 34, 65> OverrideAPBySpellPowerPercent;
    UpdateField<int32, 66, 67> ModTargetResistance;
    UpdateField<int32, 66, 68> ModTargetPhysicalResistance;
    UpdateField<int32, 66, 69> LocalFlags;
    UpdateField<uint8, 66, 70> GrantableLevels;
    UpdateField<uint8, 66, 71> MultiActionBars;
    UpdateField<uint8, 66, 72> LifetimeMaxRank;
    UpdateField<uint8, 66, 73> NumRespecs;
    UpdateField<uint32, 66, 74> PvpMedals;
    UpdateField<uint16, 66, 75> TodayHonorableKills;
    UpdateField<uint16, 66, 76> YesterdayHonorableKills;
    UpdateField<uint32, 66, 77> LifetimeHonorableKills;
    UpdateField<int32, 66, 78> WatchedFactionIndex;
    UpdateField<int32, 66, 79> MaxLevel;
    UpdateField<int32, 66, 80> ScalingPlayerLevelDelta;
    UpdateField<int32, 66, 81> MaxCreatureScalingLevel;
    UpdateField<int32, 66, 82> PetSpellPower;
    UpdateField<float, 66, 83> UiHitModifier;
    UpdateField<float, 66, 84> UiSpellHitModifier;
    UpdateField<int32, 66, 85> HomeRealmTimeOffset;
    UpdateField<float, 66, 86> ModPetHaste;
    UpdateField<uint8, 66, 87> LocalRegenFlags;
    UpdateField<uint8, 66, 88> AuraVision;
    UpdateField<uint8, 66, 89> NumBackpackSlots;
    UpdateField<int32, 66, 90> OverrideSpellsID;
    UpdateField<int32, 66, 91> LfgBonusFactionID;
    UpdateField<uint16, 66, 92> LootSpecID;
    UpdateField<uint32, 66, 93> OverrideZonePVPType;
    UpdateField<int32, 66, 94> Honor;
    UpdateField<int32, 66, 95> HonorNextLevel;
    UpdateField<int32, 66, 96> PvpRewardAchieved;
    UpdateField<int32, 66, 97> PvpTierMaxFromWins;
    UpdateField<int32, 98, 99> PvpLastWeeksRewardAchieved;
    UpdateField<int32, 98, 100> PvpLastWeeksTierMaxFromWins;
    UpdateField<int32, 98, 101> PvpLastWeeksRewardClaimed;
    UpdateField<uint8, 98, 102> NumBankSlots;
    OptionalUpdateField<UF::QuestSession, 98, 103> QuestSession;
    UpdateFieldArray<ObjectGuid, 199, 104, 105> InvSlots;
    UpdateFieldArray<uint32, 2, 304, 305> TrackResourceMask;
    UpdateFieldArray<uint64, 192, 307, 308> ExploredZones;
    UpdateFieldArray<UF::RestInfo, 2, 500, 501> RestInfo;
    UpdateFieldArray<int32, 7, 503, 504> ModDamageDonePos;
    UpdateFieldArray<int32, 7, 503, 511> ModDamageDoneNeg;
    UpdateFieldArray<float, 7, 503, 518> ModDamageDonePercent;
    UpdateFieldArray<float, 3, 525, 526> WeaponDmgMultipliers;
    UpdateFieldArray<float, 3, 525, 529> WeaponAtkSpeedMultipliers;
    UpdateFieldArray<uint32, 12, 532, 533> BuybackPrice;
    UpdateFieldArray<uint32, 12, 532, 545> BuybackTimestamp;
    UpdateFieldArray<int32, 32, 557, 558> CombatRatings;
    UpdateFieldArray<UF::PVPInfo, 6, 590, 591> PvpInfo;
    UpdateFieldArray<uint32, 4, 597, 598> NoReagentCostMask;
    UpdateFieldArray<int32, 2, 602, 603> ProfessionSkillLine;
    UpdateFieldArray<uint32, 4, 605, 606> BagSlotFlags;
    UpdateFieldArray<uint32, 7, 610, 611> BankBagSlotFlags;
    UpdateFieldArray<uint64, 875, 618, 619> QuestCompleted;

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
    UpdateField<uint8, 0, 17> PercentHealth;
    UpdateField<uint32, 0, 18> ArtKit;
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

struct ScaleCurve : public IsUpdateFieldStructureTag, public HasChangesMask<7>
{
    UpdateField<bool, 0, 1> OverrideActive;
    UpdateField<uint32, 0, 2> StartTimeOffset;
    UpdateField<uint32, 0, 3> ParameterCurve;
    UpdateFieldArray<TaggedPosition<Position::XY>, 2, 4, 5> Points;

    void WriteCreate(ByteBuffer& data, AreaTrigger const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, AreaTrigger const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

struct AreaTriggerData : public IsUpdateFieldStructureTag, public HasChangesMask<14>
{
    UpdateField<UF::ScaleCurve, 0, 1> OverrideScaleCurve;
    UpdateField<UF::ScaleCurve, 0, 2> ExtraScaleCurve;
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

    void WriteCreate(ByteBuffer& data, Conversation const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, Conversation const* owner, Player const* receiver) const;
};

struct ConversationActor : public IsUpdateFieldStructureTag
{
    uint32 CreatureID;
    uint32 CreatureDisplayInfoID;
    ObjectGuid ActorGUID;
    int32 Field_18;
    uint32 Type;

    void WriteCreate(ByteBuffer& data, Conversation const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, Conversation const* owner, Player const* receiver) const;
};

struct ConversationData : public IsUpdateFieldStructureTag, public HasChangesMask<5>
{
    UpdateField<std::vector<UF::ConversationLine>, 0, 1> Lines;
    DynamicUpdateField<UF::ConversationActor, 0, 2> Actors;
    UpdateField<int32, 0, 3> LastLineEndTime;
    UpdateField<uint32, 0, 4> Field_1C;

    void WriteCreate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Conversation const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Conversation const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

}

#endif // UpdateFields_h__
