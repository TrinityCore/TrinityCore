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

#include "EnumFlag.h"
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

    void WriteCreate(ByteBuffer& data, EnumFlag<UpdateFieldFlag> fieldVisibilityFlags, Object const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, EnumFlag<UpdateFieldFlag> fieldVisibilityFlags, Object const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, UpdateMask<4> const& changesMask, bool ignoreNestedChangesMask, Object const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

struct ItemEnchantment : public IsUpdateFieldStructureTag, public HasChangesMask<5>
{
    UpdateField<int32, 0, 1> ID;
    UpdateField<uint32, 0, 2> Duration;
    UpdateField<int16, 0, 3> Charges;
    UpdateField<uint16, 0, 4> Inactive;

    void WriteCreate(ByteBuffer& data, Item const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, bool ignoreChangesMask, Item const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

struct ItemMod : public IsUpdateFieldStructureTag
{
    int32 Value;
    uint8 Type;

    void WriteCreate(ByteBuffer& data, Item const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, bool ignoreChangesMask, Item const* owner, Player const* receiver) const;
    bool operator==(ItemMod const& right) const;
    bool operator!=(ItemMod const& right) const { return !(*this == right); }
};

struct ItemModList : public IsUpdateFieldStructureTag, public HasChangesMask<1>
{
    DynamicUpdateField<UF::ItemMod, 0, 0> Values;

    void WriteCreate(ByteBuffer& data, Item const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, bool ignoreChangesMask, Item const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

struct ArtifactPower : public IsUpdateFieldStructureTag
{
    int16 ArtifactPowerID;
    uint8 PurchasedRank;
    uint8 CurrentRankWithBonus;

    void WriteCreate(ByteBuffer& data, Item const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, bool ignoreChangesMask, Item const* owner, Player const* receiver) const;
    bool operator==(ArtifactPower const& right) const;
    bool operator!=(ArtifactPower const& right) const { return !(*this == right); }
};

struct SocketedGem : public IsUpdateFieldStructureTag, public HasChangesMask<20>
{
    UpdateField<int32, 0, 1> ItemID;
    UpdateField<uint8, 0, 2> Context;
    UpdateFieldArray<uint16, 16, 3, 4> BonusListIDs;

    void WriteCreate(ByteBuffer& data, Item const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, bool ignoreChangesMask, Item const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

struct ItemData : public IsUpdateFieldStructureTag, public HasChangesMask<40>
{
    UpdateField<std::vector<int32>, 0, 1> BonusListIDs;
    DynamicUpdateField<UF::ArtifactPower, 0, 2> ArtifactPowers;
    DynamicUpdateField<UF::SocketedGem, 0, 3> Gems;
    UpdateField<ObjectGuid, 0, 4> Owner;
    UpdateField<ObjectGuid, 0, 5> ContainedIn;
    UpdateField<ObjectGuid, 0, 6> Creator;
    UpdateField<ObjectGuid, 0, 7> GiftCreator;
    UpdateField<uint32, 0, 8> StackCount;
    UpdateField<uint32, 0, 9> Expiration;
    UpdateField<uint32, 0, 10> DynamicFlags;
    UpdateField<uint32, 0, 11> Durability;
    UpdateField<uint32, 0, 12> MaxDurability;
    UpdateField<uint32, 0, 13> CreatePlayedTime;
    UpdateField<int32, 0, 14> Context;
    UpdateField<int32, 0, 15> CreateTime;
    UpdateField<uint64, 0, 16> ArtifactXP;
    UpdateField<uint8, 0, 17> ItemAppearanceModID;
    UpdateField<UF::ItemModList, 0, 18> Modifiers;
    UpdateField<uint32, 0, 19> DynamicFlags2;
    UpdateFieldArray<int32, 5, 20, 21> SpellCharges;
    UpdateFieldArray<UF::ItemEnchantment, 13, 26, 27> Enchantment;

    void WriteCreate(ByteBuffer& data, EnumFlag<UpdateFieldFlag> fieldVisibilityFlags, Item const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, EnumFlag<UpdateFieldFlag> fieldVisibilityFlags, Item const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, UpdateMask<40> const& changesMask, bool ignoreNestedChangesMask, Item const* owner, Player const* receiver) const;
    void AppendAllowedFieldsMaskForFlag(UpdateMask<40>& allowedMaskForTarget, EnumFlag<UpdateFieldFlag> fieldVisibilityFlags) const;
    void FilterDisallowedFieldsMaskForFlag(UpdateMask<40>& changesMask, EnumFlag<UpdateFieldFlag> fieldVisibilityFlags) const;
    void ClearChangesMask();
};

struct ContainerData : public IsUpdateFieldStructureTag, public HasChangesMask<39>
{
    UpdateField<uint32, 0, 1> NumSlots;
    UpdateFieldArray<ObjectGuid, 36, 2, 3> Slots;

    void WriteCreate(ByteBuffer& data, EnumFlag<UpdateFieldFlag> fieldVisibilityFlags, Bag const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, EnumFlag<UpdateFieldFlag> fieldVisibilityFlags, Bag const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, UpdateMask<39> const& changesMask, bool ignoreNestedChangesMask, Bag const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

struct AzeriteEmpoweredItemData : public IsUpdateFieldStructureTag, public HasChangesMask<6>
{
    UpdateFieldArray<int32, 5, 0, 1> Selections;

    void WriteCreate(ByteBuffer& data, EnumFlag<UpdateFieldFlag> fieldVisibilityFlags, AzeriteEmpoweredItem const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, EnumFlag<UpdateFieldFlag> fieldVisibilityFlags, AzeriteEmpoweredItem const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, UpdateMask<6> const& changesMask, bool ignoreNestedChangesMask, AzeriteEmpoweredItem const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

struct UnlockedAzeriteEssence : public IsUpdateFieldStructureTag
{
    uint32 AzeriteEssenceID;
    uint32 Rank;

    void WriteCreate(ByteBuffer& data, AzeriteItem const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, bool ignoreChangesMask, AzeriteItem const* owner, Player const* receiver) const;
    bool operator==(UnlockedAzeriteEssence const& right) const;
    bool operator!=(UnlockedAzeriteEssence const& right) const { return !(*this == right); }
};

struct SelectedAzeriteEssences : public IsUpdateFieldStructureTag, public HasChangesMask<8>
{
    UpdateField<uint32, 0, 1> SpecializationID;
    UpdateField<uint32, 0, 2> Enabled;
    UpdateFieldArray<uint32, 4, 3, 4> AzeriteEssenceID;

    void WriteCreate(ByteBuffer& data, AzeriteItem const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, bool ignoreChangesMask, AzeriteItem const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

struct AzeriteItemData : public IsUpdateFieldStructureTag, public HasChangesMask<10>
{
    UpdateField<bool, 0, 1> Enabled;
    DynamicUpdateField<UF::UnlockedAzeriteEssence, 0, 2> UnlockedEssences;
    DynamicUpdateField<uint32, 0, 4> UnlockedEssenceMilestones;
    DynamicUpdateField<UF::SelectedAzeriteEssences, 0, 3> SelectedEssences;
    UpdateField<uint64, 0, 5> Xp;
    UpdateField<uint32, 0, 6> Level;
    UpdateField<uint32, 0, 7> AuraLevel;
    UpdateField<uint32, 0, 8> KnowledgeLevel;
    UpdateField<int32, 0, 9> DEBUGknowledgeWeek;

    void WriteCreate(ByteBuffer& data, EnumFlag<UpdateFieldFlag> fieldVisibilityFlags, AzeriteItem const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, EnumFlag<UpdateFieldFlag> fieldVisibilityFlags, AzeriteItem const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, UpdateMask<10> const& changesMask, bool ignoreNestedChangesMask, AzeriteItem const* owner, Player const* receiver) const;
    void AppendAllowedFieldsMaskForFlag(UpdateMask<10>& allowedMaskForTarget, EnumFlag<UpdateFieldFlag> fieldVisibilityFlags) const;
    void FilterDisallowedFieldsMaskForFlag(UpdateMask<10>& changesMask, EnumFlag<UpdateFieldFlag> fieldVisibilityFlags) const;
    void ClearChangesMask();
};

struct SpellCastVisual : public IsUpdateFieldStructureTag
{
    int32 SpellXSpellVisualID;
    int32 ScriptVisualID;

    void WriteCreate(ByteBuffer& data, Object const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, bool ignoreChangesMask, Object const* owner, Player const* receiver) const;
    bool operator==(SpellCastVisual const& right) const;
    bool operator!=(SpellCastVisual const& right) const { return !(*this == right); }
};

struct UnitChannel : public IsUpdateFieldStructureTag
{
    int32 SpellID;
    UF::SpellCastVisual SpellVisual;

    void WriteCreate(ByteBuffer& data, Unit const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, bool ignoreChangesMask, Unit const* owner, Player const* receiver) const;
    bool operator==(UnitChannel const& right) const;
    bool operator!=(UnitChannel const& right) const { return !(*this == right); }
};

struct VisibleItem : public IsUpdateFieldStructureTag, public HasChangesMask<5>
{
    UpdateField<int32, 0, 1> ItemID;
    UpdateField<int32, 0, 2> ItemModifiedAppearanceID;
    UpdateField<uint16, 0, 3> ItemAppearanceModID;
    UpdateField<uint16, 0, 4> ItemVisual;

    void WriteCreate(ByteBuffer& data, Unit const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, bool ignoreChangesMask, Unit const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

struct PassiveSpellHistory : public IsUpdateFieldStructureTag
{
    int32 SpellID;
    int32 AuraSpellID;

    void WriteCreate(ByteBuffer& data, Unit const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, bool ignoreChangesMask, Unit const* owner, Player const* receiver) const;
    bool operator==(PassiveSpellHistory const& right) const;
    bool operator!=(PassiveSpellHistory const& right) const { return !(*this == right); }
};

struct UnitData : public IsUpdateFieldStructureTag, public HasChangesMask<189>
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
    UpdateField<int32, 0, 10> SpellOverrideNameID;
    UpdateField<ObjectGuid, 0, 11> Charm;
    UpdateField<ObjectGuid, 0, 12> Summon;
    UpdateField<ObjectGuid, 0, 13> Critter;
    UpdateField<ObjectGuid, 0, 14> CharmedBy;
    UpdateField<ObjectGuid, 0, 15> SummonedBy;
    UpdateField<ObjectGuid, 0, 16> CreatedBy;
    UpdateField<ObjectGuid, 0, 17> DemonCreator;
    UpdateField<ObjectGuid, 0, 18> LookAtControllerTarget;
    UpdateField<ObjectGuid, 0, 19> Target;
    UpdateField<ObjectGuid, 0, 20> BattlePetCompanionGUID;
    UpdateField<uint64, 0, 21> BattlePetDBID;
    UpdateField<UF::UnitChannel, 0, 22> ChannelData;
    UpdateField<uint32, 0, 23> SummonedByHomeRealm;
    UpdateField<uint8, 0, 24> Race;
    UpdateField<uint8, 0, 25> ClassId;
    UpdateField<uint8, 0, 26> PlayerClassId;
    UpdateField<uint8, 0, 27> Sex;
    UpdateField<uint8, 0, 28> DisplayPower;
    UpdateField<uint32, 0, 29> OverrideDisplayPowerID;
    UpdateField<int64, 0, 30> Health;
    UpdateField<int64, 0, 31> MaxHealth;
    UpdateField<int32, 32, 33> Level;
    UpdateField<int32, 32, 34> EffectiveLevel;
    UpdateField<int32, 32, 35> ContentTuningID;
    UpdateField<int32, 32, 36> ScalingLevelMin;
    UpdateField<int32, 32, 37> ScalingLevelMax;
    UpdateField<int32, 32, 38> ScalingLevelDelta;
    UpdateField<int32, 32, 39> ScalingFactionGroup;
    UpdateField<int32, 32, 40> ScalingHealthItemLevelCurveID;
    UpdateField<int32, 32, 41> ScalingDamageItemLevelCurveID;
    UpdateField<int32, 32, 42> FactionTemplate;
    struct FactionTemplateTag : ViewerDependentValueTag<int32> {};
    UpdateField<uint32, 32, 43> Flags;
    struct FlagsTag : ViewerDependentValueTag<uint32> {};
    UpdateField<uint32, 32, 44> Flags2;
    UpdateField<uint32, 32, 45> Flags3;
    UpdateField<uint32, 32, 46> AuraState;
    struct AuraStateTag : ViewerDependentValueTag<uint32> {};
    UpdateField<uint32, 32, 47> RangedAttackRoundBaseTime;
    UpdateField<float, 32, 48> BoundingRadius;
    UpdateField<float, 32, 49> CombatReach;
    UpdateField<float, 32, 50> DisplayScale;
    UpdateField<int32, 32, 51> CreatureFamily;
    UpdateField<int32, 32, 52> CreatureType;
    UpdateField<int32, 32, 53> NativeDisplayID;
    UpdateField<float, 32, 54> NativeXDisplayScale;
    UpdateField<int32, 32, 55> MountDisplayID;
    UpdateField<int32, 32, 56> CosmeticMountDisplayID;
    UpdateField<float, 32, 57> MinDamage;
    UpdateField<float, 32, 58> MaxDamage;
    UpdateField<float, 32, 59> MinOffHandDamage;
    UpdateField<float, 32, 60> MaxOffHandDamage;
    UpdateField<uint8, 32, 61> StandState;
    UpdateField<uint8, 32, 62> PetTalentPoints;
    UpdateField<uint8, 32, 63> VisFlags;
    UpdateField<uint8, 64, 65> AnimTier;
    UpdateField<uint32, 64, 66> PetNumber;
    UpdateField<uint32, 64, 67> PetNameTimestamp;
    UpdateField<uint32, 64, 68> PetExperience;
    UpdateField<uint32, 64, 69> PetNextLevelExperience;
    UpdateField<float, 64, 70> ModCastingSpeed;
    UpdateField<float, 64, 71> ModCastingSpeedNeg;
    UpdateField<float, 64, 72> ModSpellHaste;
    UpdateField<float, 64, 73> ModHaste;
    UpdateField<float, 64, 74> ModRangedHaste;
    UpdateField<float, 64, 75> ModHasteRegen;
    UpdateField<float, 64, 76> ModTimeRate;
    UpdateField<int32, 64, 77> CreatedBySpell;
    UpdateField<int32, 64, 78> EmoteState;
    UpdateField<int32, 64, 79> BaseMana;
    UpdateField<int32, 64, 80> BaseHealth;
    UpdateField<uint8, 64, 81> SheatheState;
    UpdateField<uint8, 64, 82> PvpFlags;
    struct PvpFlagsTag : ViewerDependentValueTag<uint8> {};
    UpdateField<uint8, 64, 83> PetFlags;
    UpdateField<uint8, 64, 84> ShapeshiftForm;
    UpdateField<int32, 64, 85> AttackPower;
    UpdateField<int32, 64, 86> AttackPowerModPos;
    UpdateField<int32, 64, 87> AttackPowerModNeg;
    UpdateField<float, 64, 88> AttackPowerMultiplier;
    UpdateField<int32, 64, 89> RangedAttackPower;
    UpdateField<int32, 64, 90> RangedAttackPowerModPos;
    UpdateField<int32, 64, 91> RangedAttackPowerModNeg;
    UpdateField<float, 64, 92> RangedAttackPowerMultiplier;
    UpdateField<int32, 64, 93> MainHandWeaponAttackPower;
    UpdateField<int32, 64, 94> OffHandWeaponAttackPower;
    UpdateField<int32, 64, 95> RangedWeaponAttackPower;
    UpdateField<int32, 96, 97> SetAttackSpeedAura;
    UpdateField<float, 96, 98> Lifesteal;
    UpdateField<float, 96, 99> MinRangedDamage;
    UpdateField<float, 96, 100> MaxRangedDamage;
    UpdateField<float, 96, 101> ManaCostModifierModifier;
    UpdateField<float, 96, 102> MaxHealthModifier;
    UpdateField<float, 96, 103> HoverHeight;
    UpdateField<int32, 96, 104> MinItemLevelCutoff;
    UpdateField<int32, 96, 105> MinItemLevel;
    UpdateField<int32, 96, 106> MaxItemLevel;
    UpdateField<int32, 96, 107> AzeriteItemLevel;
    UpdateField<int32, 96, 108> WildBattlePetLevel;
    UpdateField<uint32, 96, 109> BattlePetCompanionNameTimestamp;
    UpdateField<int32, 96, 110> InteractSpellID;
    UpdateField<int32, 96, 111> ScaleDuration;
    UpdateField<int32, 96, 112> LooksLikeMountID;
    UpdateField<int32, 96, 113> LooksLikeCreatureID;
    UpdateField<int32, 96, 114> LookAtControllerID;
    UpdateField<int32, 96, 115> TaxiNodesID;
    UpdateField<ObjectGuid, 96, 116> GuildGUID;
    UpdateField<ObjectGuid, 96, 117> SkinningOwnerGUID;
    UpdateField<uint32, 96, 118> SilencedSchoolMask;
    UpdateFieldArray<uint32, 2, 119, 120> NpcFlags;
    struct NpcFlagsTag : ViewerDependentValueTag<uint32> {};
    UpdateFieldArray<int32, 6, 122, 123> Power;
    UpdateFieldArray<int32, 6, 122, 129> MaxPower;
    UpdateFieldArray<float, 6, 122, 135> PowerRegenFlatModifier;
    UpdateFieldArray<float, 6, 122, 141> PowerRegenInterruptedFlatModifier;
    UpdateFieldArray<UF::VisibleItem, 3, 147, 148> VirtualItems;
    UpdateFieldArray<uint32, 2, 151, 152> AttackRoundBaseTime;
    UpdateFieldArray<int32, 4, 154, 155> Stats;
    UpdateFieldArray<int32, 4, 154, 159> StatPosBuff;
    UpdateFieldArray<int32, 4, 154, 163> StatNegBuff;
    UpdateFieldArray<int32, 7, 167, 168> Resistances;
    UpdateFieldArray<int32, 7, 167, 175> BonusResistanceMods;
    UpdateFieldArray<int32, 7, 167, 182> PowerCostModifier;

    void WriteCreate(ByteBuffer& data, EnumFlag<UpdateFieldFlag> fieldVisibilityFlags, Unit const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, EnumFlag<UpdateFieldFlag> fieldVisibilityFlags, Unit const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, UpdateMask<189> const& changesMask, bool ignoreNestedChangesMask, Unit const* owner, Player const* receiver) const;
    void AppendAllowedFieldsMaskForFlag(UpdateMask<189>& allowedMaskForTarget, EnumFlag<UpdateFieldFlag> fieldVisibilityFlags) const;
    void FilterDisallowedFieldsMaskForFlag(UpdateMask<189>& changesMask, EnumFlag<UpdateFieldFlag> fieldVisibilityFlags) const;
    void ClearChangesMask();
};

struct ChrCustomizationChoice : public IsUpdateFieldStructureTag
{
    uint32 ChrCustomizationOptionID;
    uint32 ChrCustomizationChoiceID;

    void WriteCreate(ByteBuffer& data, Object const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, bool ignoreChangesMask, Object const* owner, Player const* receiver) const;
    bool operator==(ChrCustomizationChoice const& right) const;
    bool operator!=(ChrCustomizationChoice const& right) const { return !(*this == right); }
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
    void WriteUpdate(ByteBuffer& data, bool ignoreChangesMask, Player const* owner, Player const* receiver) const;
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
    void WriteUpdate(ByteBuffer& data, bool ignoreChangesMask, Player const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

struct CTROptions : public IsUpdateFieldStructureTag
{
    int32 ContentTuningConditionMask;
    uint32 Field_4;
    uint32 ExpansionLevelMask;

    void WriteCreate(ByteBuffer& data, Player const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, bool ignoreChangesMask, Player const* owner, Player const* receiver) const;
    bool operator==(CTROptions const& right) const;
    bool operator!=(CTROptions const& right) const { return !(*this == right); }
};

struct PlayerData : public IsUpdateFieldStructureTag, public HasChangesMask<185>
{
    UpdateField<bool, 0, 1> HasQuestSession;
    UpdateField<bool, 0, 2> HasLevelLink;
    DynamicUpdateField<UF::ChrCustomizationChoice, 0, 3> Customizations;
    DynamicUpdateField<UF::QuestLog, 0, 4> QuestSessionQuestLog;
    DynamicUpdateField<UF::ArenaCooldown, 0, 5> ArenaCooldowns;
    UpdateField<ObjectGuid, 0, 6> DuelArbiter;
    UpdateField<ObjectGuid, 0, 7> WowAccount;
    UpdateField<ObjectGuid, 0, 8> LootTargetGUID;
    UpdateField<uint32, 0, 9> PlayerFlags;
    UpdateField<uint32, 0, 10> PlayerFlagsEx;
    UpdateField<uint32, 0, 11> GuildRankID;
    UpdateField<uint32, 0, 12> GuildDeleteDate;
    UpdateField<int32, 0, 13> GuildLevel;
    UpdateField<uint8, 0, 14> PartyType;
    UpdateField<uint8, 0, 15> NativeSex;
    UpdateField<uint8, 0, 16> Inebriation;
    UpdateField<uint8, 0, 17> PvpTitle;
    UpdateField<uint8, 0, 18> ArenaFaction;
    UpdateField<uint32, 0, 19> DuelTeam;
    UpdateField<int32, 0, 20> GuildTimeStamp;
    UpdateField<int32, 0, 21> PlayerTitle;
    UpdateField<int32, 0, 22> FakeInebriation;
    UpdateField<uint32, 0, 23> VirtualPlayerRealm;
    UpdateField<uint32, 0, 24> CurrentSpecID;
    UpdateField<int32, 0, 25> TaxiMountAnimKitID;
    UpdateField<uint8, 0, 26> CurrentBattlePetBreedQuality;
    UpdateField<int32, 0, 27> HonorLevel;
    UpdateField<int32, 0, 28> Field_B0;
    UpdateField<int32, 0, 29> Field_B4;
    UpdateField<UF::CTROptions, 0, 30> CtrOptions;
    UpdateField<int32, 0, 31> CovenantID;
    UpdateField<int32, 32, 33> SoulbindID;
    UpdateFieldArray<UF::QuestLog, 125, 34, 35> QuestLog;
    UpdateFieldArray<UF::VisibleItem, 19, 160, 161> VisibleItems;
    UpdateFieldArray<float, 4, 180, 181> AvgItemLevel;

    void WriteCreate(ByteBuffer& data, EnumFlag<UpdateFieldFlag> fieldVisibilityFlags, Player const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, EnumFlag<UpdateFieldFlag> fieldVisibilityFlags, Player const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, UpdateMask<185> const& changesMask, bool ignoreNestedChangesMask, Player const* owner, Player const* receiver) const;
    void AppendAllowedFieldsMaskForFlag(UpdateMask<185>& allowedMaskForTarget, EnumFlag<UpdateFieldFlag> fieldVisibilityFlags) const;
    void FilterDisallowedFieldsMaskForFlag(UpdateMask<185>& changesMask, EnumFlag<UpdateFieldFlag> fieldVisibilityFlags) const;
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
    void WriteUpdate(ByteBuffer& data, bool ignoreChangesMask, Player const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

struct RestInfo : public IsUpdateFieldStructureTag, public HasChangesMask<3>
{
    UpdateField<uint32, 0, 1> Threshold;
    UpdateField<uint8, 0, 2> StateID;

    void WriteCreate(ByteBuffer& data, Player const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, bool ignoreChangesMask, Player const* owner, Player const* receiver) const;
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
    void WriteUpdate(ByteBuffer& data, bool ignoreChangesMask, Player const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

struct CharacterRestriction : public IsUpdateFieldStructureTag
{
    int32 Field_0;
    int32 Field_4;
    int32 Field_8;
    uint32 Type;

    void WriteCreate(ByteBuffer& data, Player const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, bool ignoreChangesMask, Player const* owner, Player const* receiver) const;
    bool operator==(CharacterRestriction const& right) const;
    bool operator!=(CharacterRestriction const& right) const { return !(*this == right); }
};

struct SpellPctModByLabel : public IsUpdateFieldStructureTag
{
    int32 ModIndex;
    float ModifierValue;
    int32 LabelID;

    void WriteCreate(ByteBuffer& data, Player const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, bool ignoreChangesMask, Player const* owner, Player const* receiver) const;
    bool operator==(SpellPctModByLabel const& right) const;
    bool operator!=(SpellPctModByLabel const& right) const { return !(*this == right); }
};

struct SpellFlatModByLabel : public IsUpdateFieldStructureTag
{
    int32 ModIndex;
    int32 ModifierValue;
    int32 LabelID;

    void WriteCreate(ByteBuffer& data, Player const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, bool ignoreChangesMask, Player const* owner, Player const* receiver) const;
    bool operator==(SpellFlatModByLabel const& right) const;
    bool operator!=(SpellFlatModByLabel const& right) const { return !(*this == right); }
};

struct Research : public IsUpdateFieldStructureTag
{
    int16 ResearchProjectID;

    void WriteCreate(ByteBuffer& data, Player const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, bool ignoreChangesMask, Player const* owner, Player const* receiver) const;
    bool operator==(Research const& right) const;
    bool operator!=(Research const& right) const { return !(*this == right); }
};

struct MawPower : public IsUpdateFieldStructureTag
{
    int32 Field_0;
    int32 Field_4;
    int32 Field_8;

    void WriteCreate(ByteBuffer& data, Player const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, bool ignoreChangesMask, Player const* owner, Player const* receiver) const;
    bool operator==(MawPower const& right) const;
    bool operator!=(MawPower const& right) const { return !(*this == right); }
};

struct MultiFloorExplore : public IsUpdateFieldStructureTag
{
    std::vector<int32> WorldMapOverlayIDs;

    void WriteCreate(ByteBuffer& data, Player const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, bool ignoreChangesMask, Player const* owner, Player const* receiver) const;
    bool operator==(MultiFloorExplore const& right) const;
    bool operator!=(MultiFloorExplore const& right) const { return !(*this == right); }
};

struct RecipeProgressionInfo : public IsUpdateFieldStructureTag
{
    uint16 RecipeProgressionGroupID;
    uint16 Experience;

    void WriteCreate(ByteBuffer& data, Player const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, bool ignoreChangesMask, Player const* owner, Player const* receiver) const;
    bool operator==(RecipeProgressionInfo const& right) const;
    bool operator!=(RecipeProgressionInfo const& right) const { return !(*this == right); }
};

struct ActivePlayerUnk901 : public IsUpdateFieldStructureTag, public HasChangesMask<3>
{
    UpdateField<ObjectGuid, 0, 1> Field_0;
    UpdateField<int32, 0, 2> Field_10;

    void WriteCreate(ByteBuffer& data, Player const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, bool ignoreChangesMask, Player const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

struct QuestSession : public IsUpdateFieldStructureTag, public HasChangesMask<878>
{
    UpdateField<ObjectGuid, 0, 1> Owner;
    UpdateFieldArray<uint64, 875, 2, 3> QuestCompleted;

    void WriteCreate(ByteBuffer& data, Player const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, bool ignoreChangesMask, Player const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

struct ReplayedQuest : public IsUpdateFieldStructureTag, public HasChangesMask<3>
{
    UpdateField<int32, 0, 1> QuestID;
    UpdateField<uint32, 0, 2> ReplayTime;

    void WriteCreate(ByteBuffer& data, Player const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, bool ignoreChangesMask, Player const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

struct ActivePlayerData : public IsUpdateFieldStructureTag, public HasChangesMask<1511>
{
    UpdateField<bool, 0, 1> BackpackAutoSortDisabled;
    UpdateField<bool, 0, 2> BankAutoSortDisabled;
    UpdateField<bool, 0, 3> SortBagsRightToLeft;
    UpdateField<bool, 0, 4> InsertItemsLeftToRight;
    UpdateFieldArray<DynamicUpdateFieldBase<UF::Research>, 1, 27, 28> Research;
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
    DynamicUpdateField<uint32, 0, 17> RuneforgePowers;
    DynamicUpdateField<uint32, 0, 18> TransmogIllusions;
    DynamicUpdateField<UF::SpellPctModByLabel, 0, 20> SpellPctModByLabel;
    DynamicUpdateField<UF::SpellFlatModByLabel, 0, 21> SpellFlatModByLabel;
    DynamicUpdateField<UF::MawPower, 0, 22> MawPowers;
    DynamicUpdateField<UF::MultiFloorExplore, 0, 23> MultiFloorExploration;
    DynamicUpdateField<UF::RecipeProgressionInfo, 0, 24> RecipeProgression;
    DynamicUpdateField<UF::ReplayedQuest, 0, 25> ReplayedQuests;
    DynamicUpdateField<int32, 0, 26> DisabledSpells;
    DynamicUpdateField<UF::CharacterRestriction, 0, 19> CharacterRestrictions;
    UpdateField<ObjectGuid, 0, 29> FarsightObject;
    UpdateField<ObjectGuid, 0, 30> SummonedBattlePetGUID;
    UpdateField<uint64, 0, 31> Coinage;
    UpdateField<int32, 0, 32> XP;
    UpdateField<int32, 0, 33> NextLevelXP;
    UpdateField<int32, 34, 35> TrialXP;
    UpdateField<UF::SkillInfo, 34, 36> Skill;
    UpdateField<int32, 34, 37> CharacterPoints;
    UpdateField<int32, 34, 38> MaxTalentTiers;
    UpdateField<int32, 34, 39> TrackCreatureMask;
    UpdateField<float, 34, 40> MainhandExpertise;
    UpdateField<float, 34, 41> OffhandExpertise;
    UpdateField<float, 34, 42> RangedExpertise;
    UpdateField<float, 34, 43> CombatRatingExpertise;
    UpdateField<float, 34, 44> BlockPercentage;
    UpdateField<float, 34, 45> DodgePercentage;
    UpdateField<float, 34, 46> DodgePercentageFromAttribute;
    UpdateField<float, 34, 47> ParryPercentage;
    UpdateField<float, 34, 48> ParryPercentageFromAttribute;
    UpdateField<float, 34, 49> CritPercentage;
    UpdateField<float, 34, 50> RangedCritPercentage;
    UpdateField<float, 34, 51> OffhandCritPercentage;
    UpdateField<float, 34, 52> SpellCritPercentage;
    UpdateField<int32, 34, 53> ShieldBlock;
    UpdateField<float, 34, 54> ShieldBlockCritPercentage;
    UpdateField<float, 34, 55> Mastery;
    UpdateField<float, 34, 56> Speed;
    UpdateField<float, 34, 57> Avoidance;
    UpdateField<float, 34, 58> Sturdiness;
    UpdateField<int32, 34, 59> Versatility;
    UpdateField<float, 34, 60> VersatilityBonus;
    UpdateField<float, 34, 61> PvpPowerDamage;
    UpdateField<float, 34, 62> PvpPowerHealing;
    UpdateField<int32, 34, 63> ModHealingDonePos;
    UpdateField<float, 34, 64> ModHealingPercent;
    UpdateField<float, 34, 65> ModPeriodicHealingDonePercent;
    UpdateField<float, 66, 67> ModSpellPowerPercent;
    UpdateField<float, 66, 68> ModResiliencePercent;
    UpdateField<float, 66, 69> OverrideSpellPowerByAPPercent;
    UpdateField<float, 66, 70> OverrideAPBySpellPowerPercent;
    UpdateField<int32, 66, 71> ModTargetResistance;
    UpdateField<int32, 66, 72> ModTargetPhysicalResistance;
    UpdateField<uint32, 66, 73> LocalFlags;
    UpdateField<uint8, 66, 74> GrantableLevels;
    UpdateField<uint8, 66, 75> MultiActionBars;
    UpdateField<uint8, 66, 76> LifetimeMaxRank;
    UpdateField<uint8, 66, 77> NumRespecs;
    UpdateField<uint32, 66, 78> PvpMedals;
    UpdateField<uint16, 66, 79> TodayHonorableKills;
    UpdateField<uint16, 66, 80> YesterdayHonorableKills;
    UpdateField<uint32, 66, 81> LifetimeHonorableKills;
    UpdateField<int32, 66, 82> WatchedFactionIndex;
    UpdateField<int32, 66, 83> MaxLevel;
    UpdateField<int32, 66, 84> ScalingPlayerLevelDelta;
    UpdateField<int32, 66, 85> MaxCreatureScalingLevel;
    UpdateField<int32, 66, 86> PetSpellPower;
    UpdateField<float, 66, 87> UiHitModifier;
    UpdateField<float, 66, 88> UiSpellHitModifier;
    UpdateField<int32, 66, 89> HomeRealmTimeOffset;
    UpdateField<float, 66, 90> ModPetHaste;
    UpdateField<int8, 66, 91> JailersTowerLevelMax;
    UpdateField<int8, 66, 92> JailersTowerLevel;
    UpdateField<uint8, 66, 93> LocalRegenFlags;
    UpdateField<uint8, 66, 94> AuraVision;
    UpdateField<uint8, 66, 95> NumBackpackSlots;
    UpdateField<int32, 66, 96> OverrideSpellsID;
    UpdateField<uint16, 66, 97> LootSpecID;
    UpdateField<uint32, 98, 99> OverrideZonePVPType;
    UpdateField<ObjectGuid, 98, 100> BnetAccount;
    UpdateField<uint64, 98, 101> GuildClubMemberID;
    UpdateField<int32, 98, 102> Honor;
    UpdateField<int32, 98, 103> HonorNextLevel;
    UpdateField<int32, 98, 104> PvpRewardAchieved;
    UpdateField<int32, 98, 105> PvpTierMaxFromWins;
    UpdateField<int32, 98, 106> PvpLastWeeksRewardAchieved;
    UpdateField<int32, 98, 107> PvpLastWeeksTierMaxFromWins;
    UpdateField<int32, 98, 108> PvpLastWeeksRewardClaimed;
    UpdateField<uint8, 98, 109> NumBankSlots;
    UpdateField<UF::ActivePlayerUnk901, 98, 111> Field_1410;
    OptionalUpdateField<UF::QuestSession, 98, 110> QuestSession;
    UpdateField<int32, 98, 112> UiChromieTimeExpansionID;
    UpdateField<int32, 98, 113> TransportServerTime;
    UpdateFieldArray<ObjectGuid, 199, 114, 115> InvSlots;
    UpdateFieldArray<uint32, 2, 314, 315> TrackResourceMask;
    UpdateFieldArray<uint64, 192, 317, 318> ExploredZones;
    UpdateFieldArray<UF::RestInfo, 2, 510, 511> RestInfo;
    UpdateFieldArray<int32, 7, 513, 514> ModDamageDonePos;
    UpdateFieldArray<int32, 7, 513, 521> ModDamageDoneNeg;
    UpdateFieldArray<float, 7, 513, 528> ModDamageDonePercent;
    UpdateFieldArray<float, 7, 513, 535> ModHealingDonePercent;
    UpdateFieldArray<float, 3, 542, 543> WeaponDmgMultipliers;
    UpdateFieldArray<float, 3, 542, 546> WeaponAtkSpeedMultipliers;
    UpdateFieldArray<uint32, 12, 549, 550> BuybackPrice;
    UpdateFieldArray<uint32, 12, 549, 562> BuybackTimestamp;
    UpdateFieldArray<int32, 32, 574, 575> CombatRatings;
    UpdateFieldArray<UF::PVPInfo, 6, 607, 608> PvpInfo;
    UpdateFieldArray<uint32, 4, 614, 615> NoReagentCostMask;
    UpdateFieldArray<int32, 2, 619, 620> ProfessionSkillLine;
    UpdateFieldArray<uint32, 4, 622, 623> BagSlotFlags;
    UpdateFieldArray<uint32, 7, 627, 628> BankBagSlotFlags;
    UpdateFieldArray<uint64, 875, 635, 636> QuestCompleted;

    void WriteCreate(ByteBuffer& data, EnumFlag<UpdateFieldFlag> fieldVisibilityFlags, Player const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, EnumFlag<UpdateFieldFlag> fieldVisibilityFlags, Player const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, UpdateMask<1511> const& changesMask, bool ignoreNestedChangesMask, Player const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

struct GameObjectData : public IsUpdateFieldStructureTag, public HasChangesMask<21>
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
    UpdateField<int8, 0, 14> State;
    struct StateTag : ViewerDependentValueTag<int8> {};
    UpdateField<int8, 0, 15> TypeID;
    UpdateField<uint8, 0, 16> PercentHealth;
    UpdateField<uint32, 0, 17> ArtKit;
    UpdateField<uint32, 0, 18> CustomParam;
    UpdateField<int32, 0, 19> Level;
    struct LevelTag : ViewerDependentValueTag<int32> {};
    UpdateField<uint32, 0, 20> AnimGroupInstance;

    void WriteCreate(ByteBuffer& data, EnumFlag<UpdateFieldFlag> fieldVisibilityFlags, GameObject const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, EnumFlag<UpdateFieldFlag> fieldVisibilityFlags, GameObject const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, UpdateMask<21> const& changesMask, bool ignoreNestedChangesMask, GameObject const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

struct DynamicObjectData : public IsUpdateFieldStructureTag, public HasChangesMask<7>
{
    UpdateField<ObjectGuid, 0, 1> Caster;
    UpdateField<UF::SpellCastVisual, 0, 2> SpellVisual;
    UpdateField<int32, 0, 3> SpellID;
    UpdateField<float, 0, 4> Radius;
    UpdateField<uint32, 0, 5> CastTime;
    UpdateField<uint8, 0, 6> Type;

    void WriteCreate(ByteBuffer& data, EnumFlag<UpdateFieldFlag> fieldVisibilityFlags, DynamicObject const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, EnumFlag<UpdateFieldFlag> fieldVisibilityFlags, DynamicObject const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, UpdateMask<7> const& changesMask, bool ignoreNestedChangesMask, DynamicObject const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

struct CorpseData : public IsUpdateFieldStructureTag, public HasChangesMask<33>
{
    DynamicUpdateField<UF::ChrCustomizationChoice, 0, 1> Customizations;
    UpdateField<uint32, 0, 2> DynamicFlags;
    UpdateField<ObjectGuid, 0, 3> Owner;
    UpdateField<ObjectGuid, 0, 4> PartyGUID;
    UpdateField<ObjectGuid, 0, 5> GuildGUID;
    UpdateField<uint32, 0, 6> DisplayID;
    UpdateField<uint8, 0, 7> Unused;
    UpdateField<uint8, 0, 8> RaceID;
    UpdateField<uint8, 0, 9> Sex;
    UpdateField<uint32, 0, 10> Flags;
    UpdateField<int32, 0, 11> FactionTemplate;
    UpdateField<uint32, 0, 12> StateSpellVisualKitID;
    UpdateFieldArray<uint32, 19, 13, 14> Items;

    void WriteCreate(ByteBuffer& data, EnumFlag<UpdateFieldFlag> fieldVisibilityFlags, Corpse const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, EnumFlag<UpdateFieldFlag> fieldVisibilityFlags, Corpse const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, UpdateMask<33> const& changesMask, bool ignoreNestedChangesMask, Corpse const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

struct ScaleCurve : public IsUpdateFieldStructureTag, public HasChangesMask<7>
{
    UpdateField<bool, 0, 1> OverrideActive;
    UpdateField<uint32, 0, 2> StartTimeOffset;
    UpdateField<uint32, 0, 3> ParameterCurve;
    UpdateFieldArray<TaggedPosition<Position::XY>, 2, 4, 5> Points;

    void WriteCreate(ByteBuffer& data, AreaTrigger const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, bool ignoreChangesMask, AreaTrigger const* owner, Player const* receiver) const;
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
    UpdateField<UF::SpellCastVisual, 0, 10> SpellVisual;
    UpdateField<float, 0, 11> BoundsRadius2D;
    UpdateField<uint32, 0, 12> DecalPropertiesID;
    UpdateField<ObjectGuid, 0, 13> CreatingEffectGUID;

    void WriteCreate(ByteBuffer& data, EnumFlag<UpdateFieldFlag> fieldVisibilityFlags, AreaTrigger const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, EnumFlag<UpdateFieldFlag> fieldVisibilityFlags, AreaTrigger const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, UpdateMask<14> const& changesMask, bool ignoreNestedChangesMask, AreaTrigger const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

struct SceneObjectData : public IsUpdateFieldStructureTag, public HasChangesMask<5>
{
    UpdateField<int32, 0, 1> ScriptPackageID;
    UpdateField<uint32, 0, 2> RndSeedVal;
    UpdateField<ObjectGuid, 0, 3> CreatedBy;
    UpdateField<uint32, 0, 4> SceneType;

    void WriteCreate(ByteBuffer& data, EnumFlag<UpdateFieldFlag> fieldVisibilityFlags, Object const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, EnumFlag<UpdateFieldFlag> fieldVisibilityFlags, Object const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, UpdateMask<5> const& changesMask, bool ignoreNestedChangesMask, Object const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

struct ConversationLine : public IsUpdateFieldStructureTag
{
    int32 ConversationLineID;
    uint32 StartTime;
    int32 UiCameraID;
    uint8 ActorIndex;
    uint8 Flags;
    uint8 ChatType;

    void WriteCreate(ByteBuffer& data, Conversation const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, bool ignoreChangesMask, Conversation const* owner, Player const* receiver) const;
    bool operator==(ConversationLine const& right) const;
    bool operator!=(ConversationLine const& right) const { return !(*this == right); }
};

struct ConversationActor : public IsUpdateFieldStructureTag
{
    uint32 CreatureID;
    uint32 CreatureDisplayInfoID;
    ObjectGuid ActorGUID;
    int32 Field_18;
    uint32 Type;
    uint32 NoActorObject;

    void WriteCreate(ByteBuffer& data, Conversation const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, bool ignoreChangesMask, Conversation const* owner, Player const* receiver) const;
    bool operator==(ConversationActor const& right) const;
    bool operator!=(ConversationActor const& right) const { return !(*this == right); }
};

struct ConversationData : public IsUpdateFieldStructureTag, public HasChangesMask<5>
{
    UpdateField<std::vector<UF::ConversationLine>, 0, 1> Lines;
    DynamicUpdateField<UF::ConversationActor, 0, 2> Actors;
    UpdateField<int32, 0, 3> LastLineEndTime;
    UpdateField<uint32, 0, 4> Field_1C;

    void WriteCreate(ByteBuffer& data, EnumFlag<UpdateFieldFlag> fieldVisibilityFlags, Conversation const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, EnumFlag<UpdateFieldFlag> fieldVisibilityFlags, Conversation const* owner, Player const* receiver) const;
    void WriteUpdate(ByteBuffer& data, UpdateMask<5> const& changesMask, bool ignoreNestedChangesMask, Conversation const* owner, Player const* receiver) const;
    void ClearChangesMask();
};

}

#endif // UpdateFields_h__
