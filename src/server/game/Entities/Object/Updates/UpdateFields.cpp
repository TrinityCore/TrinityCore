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

#include "UpdateFields.h"
#include "ByteBuffer.h"
#include "Player.h"
#include "ViewerDependentValues.h"

#if TRINITY_COMPILER == TRINITY_COMPILER_GNU
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#else
#pragma warning(push)
#pragma warning(disable: 4100)
#endif

namespace UF
{
void ObjectData::WriteCreate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Object const* owner, Player const* receiver) const
{
    data << int32(EntryID);
    data << uint32(ViewerDependentValue<DynamicFlagsTag>::GetValue(DynamicFlags, owner, receiver));
    data << float(Scale);
}

void ObjectData::WriteUpdate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Object const* owner, Player const* receiver) const
{
    UpdateMask<4> const& changesMask = _changesMask;
    data.WriteBits(changesMask.GetBlock(0), 4);

    data.FlushBits();
    if (changesMask[0])
    {
        if (changesMask[1])
        {
            data << int32(EntryID);
        }
        if (changesMask[2])
        {
            data << uint32(ViewerDependentValue<DynamicFlagsTag>::GetValue(DynamicFlags, owner, receiver));
        }
        if (changesMask[3])
        {
            data << float(Scale);
        }
    }
}

void ObjectData::ClearChangesMask()
{
    Base::ClearChangesMask(EntryID);
    Base::ClearChangesMask(DynamicFlags);
    Base::ClearChangesMask(Scale);
    _changesMask.ResetAll();
}

void ItemEnchantment::WriteCreate(ByteBuffer& data, Item const* owner, Player const* receiver) const
{
    data << int32(ID);
    data << uint32(Duration);
    data << int16(Charges);
    data << uint16(Inactive);
}

void ItemEnchantment::WriteUpdate(ByteBuffer& data, Item const* owner, Player const* receiver) const
{
    UpdateMask<5> const& changesMask = _changesMask;
    data.WriteBits(changesMask.GetBlock(0), 5);

    data.FlushBits();
    if (changesMask[0])
    {
        if (changesMask[1])
        {
            data << int32(ID);
        }
        if (changesMask[2])
        {
            data << uint32(Duration);
        }
        if (changesMask[3])
        {
            data << int16(Charges);
        }
        if (changesMask[4])
        {
            data << uint16(Inactive);
        }
    }
}

void ItemEnchantment::ClearChangesMask()
{
    Base::ClearChangesMask(ID);
    Base::ClearChangesMask(Duration);
    Base::ClearChangesMask(Charges);
    Base::ClearChangesMask(Inactive);
    _changesMask.ResetAll();
}

void ArtifactPower::WriteCreate(ByteBuffer& data, Item const* owner, Player const* receiver) const
{
    data << int16(ArtifactPowerID);
    data << uint8(PurchasedRank);
    data << uint8(CurrentRankWithBonus);
}

void ArtifactPower::WriteUpdate(ByteBuffer& data, Item const* owner, Player const* receiver) const
{
    data << int16(ArtifactPowerID);
    data << uint8(PurchasedRank);
    data << uint8(CurrentRankWithBonus);
}

void SocketedGem::WriteCreate(ByteBuffer& data, Item const* owner, Player const* receiver) const
{
    data << int32(ItemID);
    for (std::size_t i = 0; i < 16; ++i)
    {
        data << uint16(BonusListIDs[i]);
    }
    data << uint8(Context);
}

void SocketedGem::WriteUpdate(ByteBuffer& data, Item const* owner, Player const* receiver) const
{
    UpdateMask<20> const& changesMask = _changesMask;
    data.WriteBits(changesMask.GetBlocksMask(0), 1);
    if (changesMask.GetBlock(0))
        data.WriteBits(changesMask.GetBlock(0), 32);

    data.FlushBits();
    if (changesMask[0])
    {
        if (changesMask[1])
        {
            data << int32(ItemID);
        }
        if (changesMask[2])
        {
            data << uint8(Context);
        }
    }
    if (changesMask[3])
    {
        for (std::size_t i = 0; i < 16; ++i)
        {
            if (changesMask[4 + i])
            {
                data << uint16(BonusListIDs[i]);
            }
        }
    }
}

void SocketedGem::ClearChangesMask()
{
    Base::ClearChangesMask(ItemID);
    Base::ClearChangesMask(Context);
    Base::ClearChangesMask(BonusListIDs);
    _changesMask.ResetAll();
}

void ItemData::WriteCreate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Item const* owner, Player const* receiver) const
{
    data << uint32(BonusListIDs->size());
    for (std::size_t i = 0; i < BonusListIDs->size(); ++i)
    {
        data << int32((*BonusListIDs)[i]);
    }
    data << Owner;
    data << ContainedIn;
    data << Creator;
    data << GiftCreator;
    if (fieldVisibilityFlags.HasFlag(UpdateFieldFlag::Owner))
    {
        data << uint32(StackCount);
        data << uint32(Expiration);
        for (std::size_t i = 0; i < 5; ++i)
        {
            data << int32(SpellCharges[i]);
        }
    }
    data << uint32(DynamicFlags);
    for (std::size_t i = 0; i < 13; ++i)
    {
        Enchantment[i].WriteCreate(data, owner, receiver);
    }
    if (fieldVisibilityFlags.HasFlag(UpdateFieldFlag::Owner))
    {
        data << uint32(Durability);
        data << uint32(MaxDurability);
    }
    data << uint32(CreatePlayedTime);
    if (fieldVisibilityFlags.HasFlag(UpdateFieldFlag::Owner))
    {
        data << uint32(ModifiersMask);
    }
    data << int32(Context);
    if (fieldVisibilityFlags.HasFlag(UpdateFieldFlag::Owner))
    {
        data << uint64(ArtifactXP);
        data << uint8(ItemAppearanceModID);
    }
    data << uint32(Modifiers.size());
    data << uint32(ArtifactPowers.size());
    data << uint32(Gems.size());
    if (fieldVisibilityFlags.HasFlag(UpdateFieldFlag::Owner))
    {
        data << uint32(DynamicFlags2);
    }
    for (std::size_t i = 0; i < Modifiers.size(); ++i)
    {
        data << int32(Modifiers[i]);
    }
    for (std::size_t i = 0; i < ArtifactPowers.size(); ++i)
    {
        ArtifactPowers[i].WriteCreate(data, owner, receiver);
    }
    for (std::size_t i = 0; i < Gems.size(); ++i)
    {
        Gems[i].WriteCreate(data, owner, receiver);
    }
}

void ItemData::WriteUpdate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Item const* owner, Player const* receiver) const
{
    UpdateMask<40> allowedMaskForTarget({ 0xFC0149FFu, 0x000000FFu });
    AppendAllowedFieldsMaskForFlag(allowedMaskForTarget, fieldVisibilityFlags);
    WriteUpdate(data, _changesMask & allowedMaskForTarget, fieldVisibilityFlags, owner, receiver);
}

void ItemData::AppendAllowedFieldsMaskForFlag(UpdateMask<40>& allowedMaskForTarget, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags) const
{
    if (fieldVisibilityFlags.HasFlag(UpdateFieldFlag::Owner))
        allowedMaskForTarget |= { 0x03FEB600u, 0x00000000u };
}

void ItemData::WriteUpdate(ByteBuffer& data, UpdateMask<40> const& changesMask, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Item const* owner, Player const* receiver) const
{
    data.WriteBits(changesMask.GetBlocksMask(0), 2);
    for (std::size_t i = 0; i < 2; ++i)
        if (changesMask.GetBlock(i))
            data.WriteBits(changesMask.GetBlock(i), 32);

    if (changesMask[0])
    {
        if (changesMask[1])
        {
            data.WriteBits(BonusListIDs->size(), 32);
            for (std::size_t i = 0; i < BonusListIDs->size(); ++i)
            {
                data << int32((*BonusListIDs)[i]);
            }
        }
    }
    data.FlushBits();
    if (changesMask[0])
    {
        if (changesMask[2])
        {
            Modifiers.WriteUpdateMask(data);
        }
        if (changesMask[3])
        {
            ArtifactPowers.WriteUpdateMask(data);
        }
        if (changesMask[4])
        {
            Gems.WriteUpdateMask(data);
        }
    }
    data.FlushBits();
    if (changesMask[0])
    {
        if (changesMask[2])
        {
            for (std::size_t i = 0; i < Modifiers.size(); ++i)
            {
                if (Modifiers.HasChanged(i))
                {
                    data << int32(Modifiers[i]);
                }
            }
        }
        if (changesMask[3])
        {
            for (std::size_t i = 0; i < ArtifactPowers.size(); ++i)
            {
                if (ArtifactPowers.HasChanged(i))
                {
                    ArtifactPowers[i].WriteUpdate(data, owner, receiver);
                }
            }
        }
        if (changesMask[4])
        {
            for (std::size_t i = 0; i < Gems.size(); ++i)
            {
                if (Gems.HasChanged(i))
                {
                    Gems[i].WriteUpdate(data, owner, receiver);
                }
            }
        }
        if (changesMask[5])
        {
            data << Owner;
        }
        if (changesMask[6])
        {
            data << ContainedIn;
        }
        if (changesMask[7])
        {
            data << Creator;
        }
        if (changesMask[8])
        {
            data << GiftCreator;
        }
        if (changesMask[9])
        {
            data << uint32(StackCount);
        }
        if (changesMask[10])
        {
            data << uint32(Expiration);
        }
        if (changesMask[11])
        {
            data << uint32(DynamicFlags);
        }
        if (changesMask[12])
        {
            data << uint32(Durability);
        }
        if (changesMask[13])
        {
            data << uint32(MaxDurability);
        }
        if (changesMask[14])
        {
            data << uint32(CreatePlayedTime);
        }
        if (changesMask[15])
        {
            data << uint32(ModifiersMask);
        }
        if (changesMask[16])
        {
            data << int32(Context);
        }
        if (changesMask[17])
        {
            data << uint64(ArtifactXP);
        }
        if (changesMask[18])
        {
            data << uint8(ItemAppearanceModID);
        }
        if (changesMask[19])
        {
            data << uint32(DynamicFlags2);
        }
    }
    if (changesMask[20])
    {
        for (std::size_t i = 0; i < 5; ++i)
        {
            if (changesMask[21 + i])
            {
                data << int32(SpellCharges[i]);
            }
        }
    }
    if (changesMask[26])
    {
        for (std::size_t i = 0; i < 13; ++i)
        {
            if (changesMask[27 + i])
            {
                Enchantment[i].WriteUpdate(data, owner, receiver);
            }
        }
    }
}

void ItemData::ClearChangesMask()
{
    Base::ClearChangesMask(BonusListIDs);
    Base::ClearChangesMask(Modifiers);
    Base::ClearChangesMask(ArtifactPowers);
    Base::ClearChangesMask(Gems);
    Base::ClearChangesMask(Owner);
    Base::ClearChangesMask(ContainedIn);
    Base::ClearChangesMask(Creator);
    Base::ClearChangesMask(GiftCreator);
    Base::ClearChangesMask(StackCount);
    Base::ClearChangesMask(Expiration);
    Base::ClearChangesMask(DynamicFlags);
    Base::ClearChangesMask(Durability);
    Base::ClearChangesMask(MaxDurability);
    Base::ClearChangesMask(CreatePlayedTime);
    Base::ClearChangesMask(ModifiersMask);
    Base::ClearChangesMask(Context);
    Base::ClearChangesMask(ArtifactXP);
    Base::ClearChangesMask(ItemAppearanceModID);
    Base::ClearChangesMask(DynamicFlags2);
    Base::ClearChangesMask(SpellCharges);
    Base::ClearChangesMask(Enchantment);
    _changesMask.ResetAll();
}

void ContainerData::WriteCreate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Bag const* owner, Player const* receiver) const
{
    for (std::size_t i = 0; i < 36; ++i)
    {
        data << Slots[i];
    }
    data << uint32(NumSlots);
}

void ContainerData::WriteUpdate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Bag const* owner, Player const* receiver) const
{
    UpdateMask<39> const& changesMask = _changesMask;
    data.WriteBits(changesMask.GetBlocksMask(0), 2);
    for (std::size_t i = 0; i < 2; ++i)
        if (changesMask.GetBlock(i))
            data.WriteBits(changesMask.GetBlock(i), 32);

    data.FlushBits();
    if (changesMask[0])
    {
        if (changesMask[1])
        {
            data << uint32(NumSlots);
        }
    }
    if (changesMask[2])
    {
        for (std::size_t i = 0; i < 36; ++i)
        {
            if (changesMask[3 + i])
            {
                data << Slots[i];
            }
        }
    }
}

void ContainerData::ClearChangesMask()
{
    Base::ClearChangesMask(NumSlots);
    Base::ClearChangesMask(Slots);
    _changesMask.ResetAll();
}

void AzeriteEmpoweredItemData::WriteCreate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, AzeriteEmpoweredItem const* owner, Player const* receiver) const
{
    for (std::size_t i = 0; i < 5; ++i)
    {
        data << int32(Selections[i]);
    }
}

void AzeriteEmpoweredItemData::WriteUpdate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, AzeriteEmpoweredItem const* owner, Player const* receiver) const
{
    UpdateMask<6> const& changesMask = _changesMask;
    data.WriteBits(changesMask.GetBlocksMask(0), 1);
    if (changesMask.GetBlock(0))
        data.WriteBits(changesMask.GetBlock(0), 32);

    data.FlushBits();
    if (changesMask[0])
    {
        for (std::size_t i = 0; i < 5; ++i)
        {
            if (changesMask[1 + i])
            {
                data << int32(Selections[i]);
            }
        }
    }
}

void AzeriteEmpoweredItemData::ClearChangesMask()
{
    Base::ClearChangesMask(Selections);
    _changesMask.ResetAll();
}

void UnlockedAzeriteEssence::WriteCreate(ByteBuffer& data, AzeriteItem const* owner, Player const* receiver) const
{
    data << uint32(AzeriteEssenceID);
    data << uint32(Rank);
}

void UnlockedAzeriteEssence::WriteUpdate(ByteBuffer& data, AzeriteItem const* owner, Player const* receiver) const
{
    data << uint32(AzeriteEssenceID);
    data << uint32(Rank);
}

void SelectedAzeriteEssences::WriteCreate(ByteBuffer& data, AzeriteItem const* owner, Player const* receiver) const
{
    for (std::size_t i = 0; i < 4; ++i)
    {
        data << uint32(AzeriteEssenceID[i]);
    }
    data << uint32(SpecializationID);
    data.WriteBits(Enabled, 1);
    data.FlushBits();
}

void SelectedAzeriteEssences::WriteUpdate(ByteBuffer& data, AzeriteItem const* owner, Player const* receiver) const
{
    UpdateMask<8> const& changesMask = _changesMask;
    data.WriteBits(changesMask.GetBlocksMask(0), 1);
    if (changesMask.GetBlock(0))
        data.WriteBits(changesMask.GetBlock(0), 32);

    data.FlushBits();
    if (changesMask[0])
    {
        if (changesMask[1])
        {
            data << uint32(SpecializationID);
        }
        if (changesMask[2])
        {
            data.WriteBits(Enabled, 1);
        }
    }
    if (changesMask[3])
    {
        for (std::size_t i = 0; i < 4; ++i)
        {
            if (changesMask[4 + i])
            {
                data << uint32(AzeriteEssenceID[i]);
            }
        }
    }
    data.FlushBits();
}

void SelectedAzeriteEssences::ClearChangesMask()
{
    Base::ClearChangesMask(SpecializationID);
    Base::ClearChangesMask(Enabled);
    Base::ClearChangesMask(AzeriteEssenceID);
    _changesMask.ResetAll();
}

void AzeriteItemData::WriteCreate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, AzeriteItem const* owner, Player const* receiver) const
{
    if (fieldVisibilityFlags.HasFlag(UpdateFieldFlag::Owner))
    {
        data << uint64(Xp);
        data << uint32(Level);
        data << uint32(AuraLevel);
        data << uint32(KnowledgeLevel);
        data << int32(DEBUGknowledgeWeek);
    }
    data << uint32(UnlockedEssences.size());
    data << uint32(SelectedEssences.size());
    data << uint32(UnlockedEssenceMilestones.size());
    for (std::size_t i = 0; i < UnlockedEssences.size(); ++i)
    {
        UnlockedEssences[i].WriteCreate(data, owner, receiver);
    }
    for (std::size_t i = 0; i < UnlockedEssenceMilestones.size(); ++i)
    {
        data << uint32(UnlockedEssenceMilestones[i]);
    }
    for (std::size_t i = 0; i < SelectedEssences.size(); ++i)
    {
        SelectedEssences[i].WriteCreate(data, owner, receiver);
    }
}

void AzeriteItemData::WriteUpdate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, AzeriteItem const* owner, Player const* receiver) const
{
    UpdateMask<9> allowedMaskForTarget({ 0x0000000Fu });
    AppendAllowedFieldsMaskForFlag(allowedMaskForTarget, fieldVisibilityFlags);
    WriteUpdate(data, _changesMask & allowedMaskForTarget, fieldVisibilityFlags, owner, receiver);
}

void AzeriteItemData::AppendAllowedFieldsMaskForFlag(UpdateMask<9>& allowedMaskForTarget, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags) const
{
    if (fieldVisibilityFlags.HasFlag(UpdateFieldFlag::Owner))
        allowedMaskForTarget |= { 0x000001F0u };
}

void AzeriteItemData::WriteUpdate(ByteBuffer& data, UpdateMask<9> const& changesMask, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, AzeriteItem const* owner, Player const* receiver) const
{
    data.WriteBits(changesMask.GetBlock(0), 9);

    if (changesMask[0])
    {
        if (changesMask[1])
        {
            UnlockedEssences.WriteUpdateMask(data);
        }
        if (changesMask[2])
        {
            SelectedEssences.WriteUpdateMask(data);
        }
        if (changesMask[3])
        {
            UnlockedEssenceMilestones.WriteUpdateMask(data);
        }
    }
    data.FlushBits();
    if (changesMask[0])
    {
        if (changesMask[1])
        {
            for (std::size_t i = 0; i < UnlockedEssences.size(); ++i)
            {
                if (UnlockedEssences.HasChanged(i))
                {
                    UnlockedEssences[i].WriteUpdate(data, owner, receiver);
                }
            }
        }
        if (changesMask[3])
        {
            for (std::size_t i = 0; i < UnlockedEssenceMilestones.size(); ++i)
            {
                if (UnlockedEssenceMilestones.HasChanged(i))
                {
                    data << uint32(UnlockedEssenceMilestones[i]);
                }
            }
        }
        if (changesMask[2])
        {
            for (std::size_t i = 0; i < SelectedEssences.size(); ++i)
            {
                if (SelectedEssences.HasChanged(i))
                {
                    SelectedEssences[i].WriteUpdate(data, owner, receiver);
                }
            }
        }
        if (changesMask[4])
        {
            data << uint64(Xp);
        }
        if (changesMask[5])
        {
            data << uint32(Level);
        }
        if (changesMask[6])
        {
            data << uint32(AuraLevel);
        }
        if (changesMask[7])
        {
            data << uint32(KnowledgeLevel);
        }
        if (changesMask[8])
        {
            data << int32(DEBUGknowledgeWeek);
        }
    }
}

void AzeriteItemData::ClearChangesMask()
{
    Base::ClearChangesMask(UnlockedEssences);
    Base::ClearChangesMask(UnlockedEssenceMilestones);
    Base::ClearChangesMask(SelectedEssences);
    Base::ClearChangesMask(Xp);
    Base::ClearChangesMask(Level);
    Base::ClearChangesMask(AuraLevel);
    Base::ClearChangesMask(KnowledgeLevel);
    Base::ClearChangesMask(DEBUGknowledgeWeek);
    _changesMask.ResetAll();
}

void UnitChannel::WriteCreate(ByteBuffer& data, Unit const* owner, Player const* receiver) const
{
    data << int32(SpellID);
    data << int32(SpellXSpellVisualID);
}

void UnitChannel::WriteUpdate(ByteBuffer& data, Unit const* owner, Player const* receiver) const
{
    data << int32(SpellID);
    data << int32(SpellXSpellVisualID);
}

void VisibleItem::WriteCreate(ByteBuffer& data, Unit const* owner, Player const* receiver) const
{
    data << int32(ItemID);
    data << uint16(ItemAppearanceModID);
    data << uint16(ItemVisual);
}

void VisibleItem::WriteUpdate(ByteBuffer& data, Unit const* owner, Player const* receiver) const
{
    UpdateMask<4> const& changesMask = _changesMask;
    data.WriteBits(changesMask.GetBlock(0), 4);

    data.FlushBits();
    if (changesMask[0])
    {
        if (changesMask[1])
        {
            data << int32(ItemID);
        }
        if (changesMask[2])
        {
            data << uint16(ItemAppearanceModID);
        }
        if (changesMask[3])
        {
            data << uint16(ItemVisual);
        }
    }
}

void VisibleItem::ClearChangesMask()
{
    Base::ClearChangesMask(ItemID);
    Base::ClearChangesMask(ItemAppearanceModID);
    Base::ClearChangesMask(ItemVisual);
    _changesMask.ResetAll();
}

void PassiveSpellHistory::WriteCreate(ByteBuffer& data, Unit const* owner, Player const* receiver) const
{
    data << int32(SpellID);
    data << int32(AuraSpellID);
}

void PassiveSpellHistory::WriteUpdate(ByteBuffer& data, Unit const* owner, Player const* receiver) const
{
    data << int32(SpellID);
    data << int32(AuraSpellID);
}

void UnitData::WriteCreate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Unit const* owner, Player const* receiver) const
{
    data << int32(ViewerDependentValue<DisplayIDTag>::GetValue(DisplayID, owner, receiver));
    for (std::size_t i = 0; i < 2; ++i)
    {
        data << uint32(ViewerDependentValue<NpcFlagsTag>::GetValue(NpcFlags[i], i, owner, receiver));
    }
    data << uint32(StateSpellVisualID);
    data << uint32(StateAnimID);
    data << uint32(StateAnimKitID);
    data << uint32(StateWorldEffectIDs->size());
    data << uint32(StateWorldEffectsQuestObjectiveID);
    for (std::size_t i = 0; i < StateWorldEffectIDs->size(); ++i)
    {
        data << uint32((*StateWorldEffectIDs)[i]);
    }
    data << Charm;
    data << Summon;
    if (fieldVisibilityFlags.HasFlag(UpdateFieldFlag::Owner))
    {
        data << Critter;
    }
    data << CharmedBy;
    data << SummonedBy;
    data << CreatedBy;
    data << DemonCreator;
    data << LookAtControllerTarget;
    data << Target;
    data << BattlePetCompanionGUID;
    data << uint64(BattlePetDBID);
    ChannelData->WriteCreate(data, owner, receiver);
    data << uint32(SummonedByHomeRealm);
    data << uint8(Race);
    data << uint8(ClassId);
    data << uint8(PlayerClassId);
    data << uint8(Sex);
    data << uint8(DisplayPower);
    data << uint32(OverrideDisplayPowerID);
    data << int64(Health);
    for (std::size_t i = 0; i < 6; ++i)
    {
        data << int32(Power[i]);
        data << int32(MaxPower[i]);
    }
    if (fieldVisibilityFlags.HasFlag(UpdateFieldFlag::Owner) || fieldVisibilityFlags.HasFlag(UpdateFieldFlag::UnitAll))
    {
        for (std::size_t i = 0; i < 6; ++i)
        {
            data << float(PowerRegenFlatModifier[i]);
            data << float(PowerRegenInterruptedFlatModifier[i]);
        }
    }
    data << int64(MaxHealth);
    data << int32(Level);
    data << int32(EffectiveLevel);
    data << int32(ContentTuningID);
    data << int32(ScalingLevelMin);
    data << int32(ScalingLevelMax);
    data << int32(ScalingLevelDelta);
    data << int32(ScalingFactionGroup);
    data << int32(ScalingHealthItemLevelCurveID);
    data << int32(ScalingDamageItemLevelCurveID);
    data << int32(ViewerDependentValue<FactionTemplateTag>::GetValue(FactionTemplate, owner, receiver));
    for (std::size_t i = 0; i < 3; ++i)
    {
        VirtualItems[i].WriteCreate(data, owner, receiver);
    }
    data << uint32(ViewerDependentValue<FlagsTag>::GetValue(Flags, owner, receiver));
    data << uint32(Flags2);
    data << uint32(Flags3);
    data << uint32(ViewerDependentValue<AuraStateTag>::GetValue(AuraState, owner, receiver));
    for (std::size_t i = 0; i < 2; ++i)
    {
        data << uint32(AttackRoundBaseTime[i]);
    }
    if (fieldVisibilityFlags.HasFlag(UpdateFieldFlag::Owner))
    {
        data << uint32(RangedAttackRoundBaseTime);
    }
    data << float(BoundingRadius);
    data << float(CombatReach);
    data << float(DisplayScale);
    data << int32(NativeDisplayID);
    data << float(NativeXDisplayScale);
    data << int32(MountDisplayID);
    data << int32(CosmeticMountDisplayID);
    if (fieldVisibilityFlags.HasFlag(UpdateFieldFlag::Owner) || fieldVisibilityFlags.HasFlag(UpdateFieldFlag::Empath))
    {
        data << float(MinDamage);
        data << float(MaxDamage);
        data << float(MinOffHandDamage);
        data << float(MaxOffHandDamage);
    }
    data << uint8(StandState);
    data << uint8(PetTalentPoints);
    data << uint8(VisFlags);
    data << uint8(AnimTier);
    data << uint32(PetNumber);
    data << uint32(PetNameTimestamp);
    data << uint32(PetExperience);
    data << uint32(PetNextLevelExperience);
    data << float(ModCastingSpeed);
    data << float(ModSpellHaste);
    data << float(ModHaste);
    data << float(ModRangedHaste);
    data << float(ModHasteRegen);
    data << float(ModTimeRate);
    data << int32(CreatedBySpell);
    data << int32(EmoteState);
    if (fieldVisibilityFlags.HasFlag(UpdateFieldFlag::Owner))
    {
        for (std::size_t i = 0; i < 4; ++i)
        {
            data << int32(Stats[i]);
            data << int32(StatPosBuff[i]);
            data << int32(StatNegBuff[i]);
        }
    }
    if (fieldVisibilityFlags.HasFlag(UpdateFieldFlag::Owner) || fieldVisibilityFlags.HasFlag(UpdateFieldFlag::Empath))
    {
        for (std::size_t i = 0; i < 7; ++i)
        {
            data << int32(Resistances[i]);
        }
    }
    if (fieldVisibilityFlags.HasFlag(UpdateFieldFlag::Owner))
    {
        for (std::size_t i = 0; i < 7; ++i)
        {
            data << int32(BonusResistanceMods[i]);
            data << int32(PowerCostModifier[i]);
            data << float(PowerCostMultiplier[i]);
        }
    }
    data << int32(BaseMana);
    if (fieldVisibilityFlags.HasFlag(UpdateFieldFlag::Owner))
    {
        data << int32(BaseHealth);
    }
    data << uint8(SheatheState);
    data << uint8(ViewerDependentValue<PvpFlagsTag>::GetValue(PvpFlags, owner, receiver));
    data << uint8(PetFlags);
    data << uint8(ShapeshiftForm);
    if (fieldVisibilityFlags.HasFlag(UpdateFieldFlag::Owner))
    {
        data << int32(AttackPower);
        data << int32(AttackPowerModPos);
        data << int32(AttackPowerModNeg);
        data << float(AttackPowerMultiplier);
        data << int32(RangedAttackPower);
        data << int32(RangedAttackPowerModPos);
        data << int32(RangedAttackPowerModNeg);
        data << float(RangedAttackPowerMultiplier);
        data << int32(MainHandWeaponAttackPower);
        data << int32(OffHandWeaponAttackPower);
        data << int32(RangedWeaponAttackPower);
        data << int32(SetAttackSpeedAura);
        data << float(Lifesteal);
        data << float(MinRangedDamage);
        data << float(MaxRangedDamage);
        data << float(ManaCostModifierModifier);
        data << float(MaxHealthModifier);
    }
    data << float(HoverHeight);
    data << int32(MinItemLevelCutoff);
    data << int32(MinItemLevel);
    data << int32(MaxItemLevel);
    data << int32(AzeriteItemLevel);
    data << int32(WildBattlePetLevel);
    data << uint32(BattlePetCompanionNameTimestamp);
    data << int32(InteractSpellID);
    data << int32(ScaleDuration);
    data << int32(SpellOverrideNameID);
    data << int32(LooksLikeMountID);
    data << int32(LooksLikeCreatureID);
    data << int32(LookAtControllerID);
    data << int32(TaxiNodesID);
    data << GuildGUID;
    data << uint32(PassiveSpells.size());
    data << uint32(WorldEffects.size());
    data << uint32(ChannelObjects.size());
    data << SkinningOwnerGUID;
    for (std::size_t i = 0; i < PassiveSpells.size(); ++i)
    {
        PassiveSpells[i].WriteCreate(data, owner, receiver);
    }
    for (std::size_t i = 0; i < WorldEffects.size(); ++i)
    {
        data << int32(WorldEffects[i]);
    }
    for (std::size_t i = 0; i < ChannelObjects.size(); ++i)
    {
        data << ChannelObjects[i];
    }
}

void UnitData::WriteUpdate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Unit const* owner, Player const* receiver) const
{
    UpdateMask<192> allowedMaskForTarget({ 0xFFFFEFFFu, 0xFC3FBFFFu, 0x0001EFFFu, 0xFFBFFFF9u, 0x003F8007u, 0x00000000u });
    AppendAllowedFieldsMaskForFlag(allowedMaskForTarget, fieldVisibilityFlags);
    WriteUpdate(data, _changesMask & allowedMaskForTarget, fieldVisibilityFlags, owner, receiver);
}

void UnitData::AppendAllowedFieldsMaskForFlag(UpdateMask<192>& allowedMaskForTarget, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags) const
{
    if (fieldVisibilityFlags.HasFlag(UpdateFieldFlag::Owner))
        allowedMaskForTarget |= { 0x00001000u, 0x03C04000u, 0xFFFE1000u, 0x00400006u, 0xFFC07FF8u, 0xFFFFFFFFu };
    if (fieldVisibilityFlags.HasFlag(UpdateFieldFlag::UnitAll))
        allowedMaskForTarget |= { 0x00000000u, 0x00000000u, 0x00000000u, 0x00400000u, 0x00007FF8u, 0x00000000u };
    if (fieldVisibilityFlags.HasFlag(UpdateFieldFlag::Empath))
        allowedMaskForTarget |= { 0x00000000u, 0x03C00000u, 0x00000000u, 0x00000000u, 0x00000000u, 0x000007F8u };
}

void UnitData::WriteUpdate(ByteBuffer& data, UpdateMask<192> const& changesMask, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Unit const* owner, Player const* receiver) const
{
    data.WriteBits(changesMask.GetBlocksMask(0), 6);
    for (std::size_t i = 0; i < 6; ++i)
        if (changesMask.GetBlock(i))
            data.WriteBits(changesMask.GetBlock(i), 32);

    if (changesMask[0])
    {
        if (changesMask[1])
        {
            data.WriteBits(StateWorldEffectIDs->size(), 32);
            for (std::size_t i = 0; i < StateWorldEffectIDs->size(); ++i)
            {
                data << uint32((*StateWorldEffectIDs)[i]);
            }
        }
    }
    data.FlushBits();
    if (changesMask[0])
    {
        if (changesMask[2])
        {
            PassiveSpells.WriteUpdateMask(data);
        }
        if (changesMask[3])
        {
            WorldEffects.WriteUpdateMask(data);
        }
        if (changesMask[4])
        {
            ChannelObjects.WriteUpdateMask(data);
        }
    }
    data.FlushBits();
    if (changesMask[0])
    {
        if (changesMask[2])
        {
            for (std::size_t i = 0; i < PassiveSpells.size(); ++i)
            {
                if (PassiveSpells.HasChanged(i))
                {
                    PassiveSpells[i].WriteUpdate(data, owner, receiver);
                }
            }
        }
        if (changesMask[3])
        {
            for (std::size_t i = 0; i < WorldEffects.size(); ++i)
            {
                if (WorldEffects.HasChanged(i))
                {
                    data << int32(WorldEffects[i]);
                }
            }
        }
        if (changesMask[4])
        {
            for (std::size_t i = 0; i < ChannelObjects.size(); ++i)
            {
                if (ChannelObjects.HasChanged(i))
                {
                    data << ChannelObjects[i];
                }
            }
        }
        if (changesMask[5])
        {
            data << int32(ViewerDependentValue<DisplayIDTag>::GetValue(DisplayID, owner, receiver));
        }
        if (changesMask[6])
        {
            data << uint32(StateSpellVisualID);
        }
        if (changesMask[7])
        {
            data << uint32(StateAnimID);
        }
        if (changesMask[8])
        {
            data << uint32(StateAnimKitID);
        }
        if (changesMask[9])
        {
            data << uint32(StateWorldEffectsQuestObjectiveID);
        }
        if (changesMask[10])
        {
            data << Charm;
        }
        if (changesMask[11])
        {
            data << Summon;
        }
        if (changesMask[12])
        {
            data << Critter;
        }
        if (changesMask[13])
        {
            data << CharmedBy;
        }
        if (changesMask[14])
        {
            data << SummonedBy;
        }
        if (changesMask[15])
        {
            data << CreatedBy;
        }
        if (changesMask[16])
        {
            data << DemonCreator;
        }
        if (changesMask[17])
        {
            data << LookAtControllerTarget;
        }
        if (changesMask[18])
        {
            data << Target;
        }
        if (changesMask[19])
        {
            data << BattlePetCompanionGUID;
        }
        if (changesMask[20])
        {
            data << uint64(BattlePetDBID);
        }
        if (changesMask[21])
        {
            ChannelData->WriteUpdate(data, owner, receiver);
        }
        if (changesMask[22])
        {
            data << uint32(SummonedByHomeRealm);
        }
        if (changesMask[23])
        {
            data << uint8(Race);
        }
        if (changesMask[24])
        {
            data << uint8(ClassId);
        }
        if (changesMask[25])
        {
            data << uint8(PlayerClassId);
        }
        if (changesMask[26])
        {
            data << uint8(Sex);
        }
        if (changesMask[27])
        {
            data << uint8(DisplayPower);
        }
        if (changesMask[28])
        {
            data << uint32(OverrideDisplayPowerID);
        }
        if (changesMask[29])
        {
            data << int64(Health);
        }
        if (changesMask[30])
        {
            data << int64(MaxHealth);
        }
        if (changesMask[31])
        {
            data << int32(Level);
        }
    }
    if (changesMask[32])
    {
        if (changesMask[33])
        {
            data << int32(EffectiveLevel);
        }
        if (changesMask[34])
        {
            data << int32(ContentTuningID);
        }
        if (changesMask[35])
        {
            data << int32(ScalingLevelMin);
        }
        if (changesMask[36])
        {
            data << int32(ScalingLevelMax);
        }
        if (changesMask[37])
        {
            data << int32(ScalingLevelDelta);
        }
        if (changesMask[38])
        {
            data << int32(ScalingFactionGroup);
        }
        if (changesMask[39])
        {
            data << int32(ScalingHealthItemLevelCurveID);
        }
        if (changesMask[40])
        {
            data << int32(ScalingDamageItemLevelCurveID);
        }
        if (changesMask[41])
        {
            data << int32(ViewerDependentValue<FactionTemplateTag>::GetValue(FactionTemplate, owner, receiver));
        }
        if (changesMask[42])
        {
            data << uint32(ViewerDependentValue<FlagsTag>::GetValue(Flags, owner, receiver));
        }
        if (changesMask[43])
        {
            data << uint32(Flags2);
        }
        if (changesMask[44])
        {
            data << uint32(Flags3);
        }
        if (changesMask[45])
        {
            data << uint32(ViewerDependentValue<AuraStateTag>::GetValue(AuraState, owner, receiver));
        }
        if (changesMask[46])
        {
            data << uint32(RangedAttackRoundBaseTime);
        }
        if (changesMask[47])
        {
            data << float(BoundingRadius);
        }
        if (changesMask[48])
        {
            data << float(CombatReach);
        }
        if (changesMask[49])
        {
            data << float(DisplayScale);
        }
        if (changesMask[50])
        {
            data << int32(NativeDisplayID);
        }
        if (changesMask[51])
        {
            data << float(NativeXDisplayScale);
        }
        if (changesMask[52])
        {
            data << int32(MountDisplayID);
        }
        if (changesMask[53])
        {
            data << int32(CosmeticMountDisplayID);
        }
        if (changesMask[54])
        {
            data << float(MinDamage);
        }
        if (changesMask[55])
        {
            data << float(MaxDamage);
        }
        if (changesMask[56])
        {
            data << float(MinOffHandDamage);
        }
        if (changesMask[57])
        {
            data << float(MaxOffHandDamage);
        }
        if (changesMask[58])
        {
            data << uint8(StandState);
        }
        if (changesMask[59])
        {
            data << uint8(PetTalentPoints);
        }
        if (changesMask[60])
        {
            data << uint8(VisFlags);
        }
        if (changesMask[61])
        {
            data << uint8(AnimTier);
        }
        if (changesMask[62])
        {
            data << uint32(PetNumber);
        }
        if (changesMask[63])
        {
            data << uint32(PetNameTimestamp);
        }
    }
    if (changesMask[64])
    {
        if (changesMask[65])
        {
            data << uint32(PetExperience);
        }
        if (changesMask[66])
        {
            data << uint32(PetNextLevelExperience);
        }
        if (changesMask[67])
        {
            data << float(ModCastingSpeed);
        }
        if (changesMask[68])
        {
            data << float(ModSpellHaste);
        }
        if (changesMask[69])
        {
            data << float(ModHaste);
        }
        if (changesMask[70])
        {
            data << float(ModRangedHaste);
        }
        if (changesMask[71])
        {
            data << float(ModHasteRegen);
        }
        if (changesMask[72])
        {
            data << float(ModTimeRate);
        }
        if (changesMask[73])
        {
            data << int32(CreatedBySpell);
        }
        if (changesMask[74])
        {
            data << int32(EmoteState);
        }
        if (changesMask[75])
        {
            data << int32(BaseMana);
        }
        if (changesMask[76])
        {
            data << int32(BaseHealth);
        }
        if (changesMask[77])
        {
            data << uint8(SheatheState);
        }
        if (changesMask[78])
        {
            data << uint8(ViewerDependentValue<PvpFlagsTag>::GetValue(PvpFlags, owner, receiver));
        }
        if (changesMask[79])
        {
            data << uint8(PetFlags);
        }
        if (changesMask[80])
        {
            data << uint8(ShapeshiftForm);
        }
        if (changesMask[81])
        {
            data << int32(AttackPower);
        }
        if (changesMask[82])
        {
            data << int32(AttackPowerModPos);
        }
        if (changesMask[83])
        {
            data << int32(AttackPowerModNeg);
        }
        if (changesMask[84])
        {
            data << float(AttackPowerMultiplier);
        }
        if (changesMask[85])
        {
            data << int32(RangedAttackPower);
        }
        if (changesMask[86])
        {
            data << int32(RangedAttackPowerModPos);
        }
        if (changesMask[87])
        {
            data << int32(RangedAttackPowerModNeg);
        }
        if (changesMask[88])
        {
            data << float(RangedAttackPowerMultiplier);
        }
        if (changesMask[89])
        {
            data << int32(MainHandWeaponAttackPower);
        }
        if (changesMask[90])
        {
            data << int32(OffHandWeaponAttackPower);
        }
        if (changesMask[91])
        {
            data << int32(RangedWeaponAttackPower);
        }
        if (changesMask[92])
        {
            data << int32(SetAttackSpeedAura);
        }
        if (changesMask[93])
        {
            data << float(Lifesteal);
        }
        if (changesMask[94])
        {
            data << float(MinRangedDamage);
        }
        if (changesMask[95])
        {
            data << float(MaxRangedDamage);
        }
    }
    if (changesMask[96])
    {
        if (changesMask[97])
        {
            data << float(ManaCostModifierModifier);
        }
        if (changesMask[98])
        {
            data << float(MaxHealthModifier);
        }
        if (changesMask[99])
        {
            data << float(HoverHeight);
        }
        if (changesMask[100])
        {
            data << int32(MinItemLevelCutoff);
        }
        if (changesMask[101])
        {
            data << int32(MinItemLevel);
        }
        if (changesMask[102])
        {
            data << int32(MaxItemLevel);
        }
        if (changesMask[103])
        {
            data << int32(AzeriteItemLevel);
        }
        if (changesMask[104])
        {
            data << int32(WildBattlePetLevel);
        }
        if (changesMask[105])
        {
            data << uint32(BattlePetCompanionNameTimestamp);
        }
        if (changesMask[106])
        {
            data << int32(InteractSpellID);
        }
        if (changesMask[107])
        {
            data << int32(ScaleDuration);
        }
        if (changesMask[108])
        {
            data << int32(SpellOverrideNameID);
        }
        if (changesMask[109])
        {
            data << int32(LooksLikeMountID);
        }
        if (changesMask[110])
        {
            data << int32(LooksLikeCreatureID);
        }
        if (changesMask[111])
        {
            data << int32(LookAtControllerID);
        }
        if (changesMask[112])
        {
            data << int32(TaxiNodesID);
        }
        if (changesMask[113])
        {
            data << GuildGUID;
        }
        if (changesMask[114])
        {
            data << SkinningOwnerGUID;
        }
    }
    if (changesMask[115])
    {
        for (std::size_t i = 0; i < 2; ++i)
        {
            if (changesMask[116 + i])
            {
                data << uint32(ViewerDependentValue<NpcFlagsTag>::GetValue(NpcFlags[i], i, owner, receiver));
            }
        }
    }
    if (changesMask[118])
    {
        for (std::size_t i = 0; i < 6; ++i)
        {
            if (changesMask[119 + i])
            {
                data << int32(Power[i]);
            }
            if (changesMask[125 + i])
            {
                data << int32(MaxPower[i]);
            }
            if (changesMask[131 + i])
            {
                data << float(PowerRegenFlatModifier[i]);
            }
            if (changesMask[137 + i])
            {
                data << float(PowerRegenInterruptedFlatModifier[i]);
            }
        }
    }
    if (changesMask[143])
    {
        for (std::size_t i = 0; i < 3; ++i)
        {
            if (changesMask[144 + i])
            {
                VirtualItems[i].WriteUpdate(data, owner, receiver);
            }
        }
    }
    if (changesMask[147])
    {
        for (std::size_t i = 0; i < 2; ++i)
        {
            if (changesMask[148 + i])
            {
                data << uint32(AttackRoundBaseTime[i]);
            }
        }
    }
    if (changesMask[150])
    {
        for (std::size_t i = 0; i < 4; ++i)
        {
            if (changesMask[151 + i])
            {
                data << int32(Stats[i]);
            }
            if (changesMask[155 + i])
            {
                data << int32(StatPosBuff[i]);
            }
            if (changesMask[159 + i])
            {
                data << int32(StatNegBuff[i]);
            }
        }
    }
    if (changesMask[163])
    {
        for (std::size_t i = 0; i < 7; ++i)
        {
            if (changesMask[164 + i])
            {
                data << int32(Resistances[i]);
            }
            if (changesMask[171 + i])
            {
                data << int32(BonusResistanceMods[i]);
            }
            if (changesMask[178 + i])
            {
                data << int32(PowerCostModifier[i]);
            }
            if (changesMask[185 + i])
            {
                data << float(PowerCostMultiplier[i]);
            }
        }
    }
}

void UnitData::ClearChangesMask()
{
    Base::ClearChangesMask(StateWorldEffectIDs);
    Base::ClearChangesMask(PassiveSpells);
    Base::ClearChangesMask(WorldEffects);
    Base::ClearChangesMask(ChannelObjects);
    Base::ClearChangesMask(DisplayID);
    Base::ClearChangesMask(StateSpellVisualID);
    Base::ClearChangesMask(StateAnimID);
    Base::ClearChangesMask(StateAnimKitID);
    Base::ClearChangesMask(StateWorldEffectsQuestObjectiveID);
    Base::ClearChangesMask(Charm);
    Base::ClearChangesMask(Summon);
    Base::ClearChangesMask(Critter);
    Base::ClearChangesMask(CharmedBy);
    Base::ClearChangesMask(SummonedBy);
    Base::ClearChangesMask(CreatedBy);
    Base::ClearChangesMask(DemonCreator);
    Base::ClearChangesMask(LookAtControllerTarget);
    Base::ClearChangesMask(Target);
    Base::ClearChangesMask(BattlePetCompanionGUID);
    Base::ClearChangesMask(BattlePetDBID);
    Base::ClearChangesMask(ChannelData);
    Base::ClearChangesMask(SummonedByHomeRealm);
    Base::ClearChangesMask(Race);
    Base::ClearChangesMask(ClassId);
    Base::ClearChangesMask(PlayerClassId);
    Base::ClearChangesMask(Sex);
    Base::ClearChangesMask(DisplayPower);
    Base::ClearChangesMask(OverrideDisplayPowerID);
    Base::ClearChangesMask(Health);
    Base::ClearChangesMask(MaxHealth);
    Base::ClearChangesMask(Level);
    Base::ClearChangesMask(EffectiveLevel);
    Base::ClearChangesMask(ContentTuningID);
    Base::ClearChangesMask(ScalingLevelMin);
    Base::ClearChangesMask(ScalingLevelMax);
    Base::ClearChangesMask(ScalingLevelDelta);
    Base::ClearChangesMask(ScalingFactionGroup);
    Base::ClearChangesMask(ScalingHealthItemLevelCurveID);
    Base::ClearChangesMask(ScalingDamageItemLevelCurveID);
    Base::ClearChangesMask(FactionTemplate);
    Base::ClearChangesMask(Flags);
    Base::ClearChangesMask(Flags2);
    Base::ClearChangesMask(Flags3);
    Base::ClearChangesMask(AuraState);
    Base::ClearChangesMask(RangedAttackRoundBaseTime);
    Base::ClearChangesMask(BoundingRadius);
    Base::ClearChangesMask(CombatReach);
    Base::ClearChangesMask(DisplayScale);
    Base::ClearChangesMask(NativeDisplayID);
    Base::ClearChangesMask(NativeXDisplayScale);
    Base::ClearChangesMask(MountDisplayID);
    Base::ClearChangesMask(CosmeticMountDisplayID);
    Base::ClearChangesMask(MinDamage);
    Base::ClearChangesMask(MaxDamage);
    Base::ClearChangesMask(MinOffHandDamage);
    Base::ClearChangesMask(MaxOffHandDamage);
    Base::ClearChangesMask(StandState);
    Base::ClearChangesMask(PetTalentPoints);
    Base::ClearChangesMask(VisFlags);
    Base::ClearChangesMask(AnimTier);
    Base::ClearChangesMask(PetNumber);
    Base::ClearChangesMask(PetNameTimestamp);
    Base::ClearChangesMask(PetExperience);
    Base::ClearChangesMask(PetNextLevelExperience);
    Base::ClearChangesMask(ModCastingSpeed);
    Base::ClearChangesMask(ModSpellHaste);
    Base::ClearChangesMask(ModHaste);
    Base::ClearChangesMask(ModRangedHaste);
    Base::ClearChangesMask(ModHasteRegen);
    Base::ClearChangesMask(ModTimeRate);
    Base::ClearChangesMask(CreatedBySpell);
    Base::ClearChangesMask(EmoteState);
    Base::ClearChangesMask(BaseMana);
    Base::ClearChangesMask(BaseHealth);
    Base::ClearChangesMask(SheatheState);
    Base::ClearChangesMask(PvpFlags);
    Base::ClearChangesMask(PetFlags);
    Base::ClearChangesMask(ShapeshiftForm);
    Base::ClearChangesMask(AttackPower);
    Base::ClearChangesMask(AttackPowerModPos);
    Base::ClearChangesMask(AttackPowerModNeg);
    Base::ClearChangesMask(AttackPowerMultiplier);
    Base::ClearChangesMask(RangedAttackPower);
    Base::ClearChangesMask(RangedAttackPowerModPos);
    Base::ClearChangesMask(RangedAttackPowerModNeg);
    Base::ClearChangesMask(RangedAttackPowerMultiplier);
    Base::ClearChangesMask(MainHandWeaponAttackPower);
    Base::ClearChangesMask(OffHandWeaponAttackPower);
    Base::ClearChangesMask(RangedWeaponAttackPower);
    Base::ClearChangesMask(SetAttackSpeedAura);
    Base::ClearChangesMask(Lifesteal);
    Base::ClearChangesMask(MinRangedDamage);
    Base::ClearChangesMask(MaxRangedDamage);
    Base::ClearChangesMask(ManaCostModifierModifier);
    Base::ClearChangesMask(MaxHealthModifier);
    Base::ClearChangesMask(HoverHeight);
    Base::ClearChangesMask(MinItemLevelCutoff);
    Base::ClearChangesMask(MinItemLevel);
    Base::ClearChangesMask(MaxItemLevel);
    Base::ClearChangesMask(AzeriteItemLevel);
    Base::ClearChangesMask(WildBattlePetLevel);
    Base::ClearChangesMask(BattlePetCompanionNameTimestamp);
    Base::ClearChangesMask(InteractSpellID);
    Base::ClearChangesMask(ScaleDuration);
    Base::ClearChangesMask(SpellOverrideNameID);
    Base::ClearChangesMask(LooksLikeMountID);
    Base::ClearChangesMask(LooksLikeCreatureID);
    Base::ClearChangesMask(LookAtControllerID);
    Base::ClearChangesMask(TaxiNodesID);
    Base::ClearChangesMask(GuildGUID);
    Base::ClearChangesMask(SkinningOwnerGUID);
    Base::ClearChangesMask(NpcFlags);
    Base::ClearChangesMask(Power);
    Base::ClearChangesMask(MaxPower);
    Base::ClearChangesMask(PowerRegenFlatModifier);
    Base::ClearChangesMask(PowerRegenInterruptedFlatModifier);
    Base::ClearChangesMask(VirtualItems);
    Base::ClearChangesMask(AttackRoundBaseTime);
    Base::ClearChangesMask(Stats);
    Base::ClearChangesMask(StatPosBuff);
    Base::ClearChangesMask(StatNegBuff);
    Base::ClearChangesMask(Resistances);
    Base::ClearChangesMask(BonusResistanceMods);
    Base::ClearChangesMask(PowerCostModifier);
    Base::ClearChangesMask(PowerCostMultiplier);
    _changesMask.ResetAll();
}

void QuestLog::WriteCreate(ByteBuffer& data, Player const* owner, Player const* receiver) const
{
    data << int32(QuestID);
    data << uint32(StateFlags);
    data << uint32(EndTime);
    data << uint32(AcceptTime);
    data << uint32(Field_10);
    for (std::size_t i = 0; i < 24; ++i)
    {
        data << int16(ObjectiveProgress[i]);
    }
}

void QuestLog::WriteUpdate(ByteBuffer& data, Player const* owner, Player const* receiver) const
{
    UpdateMask<31> const& changesMask = _changesMask;
    data.WriteBits(changesMask.GetBlocksMask(0), 1);
    if (changesMask.GetBlock(0))
        data.WriteBits(changesMask.GetBlock(0), 32);

    data.FlushBits();
    if (changesMask[0])
    {
        if (changesMask[1])
        {
            data << int32(QuestID);
        }
        if (changesMask[2])
        {
            data << uint32(StateFlags);
        }
        if (changesMask[3])
        {
            data << uint32(EndTime);
        }
        if (changesMask[4])
        {
            data << uint32(AcceptTime);
        }
        if (changesMask[5])
        {
            data << uint32(Field_10);
        }
    }
    if (changesMask[6])
    {
        for (std::size_t i = 0; i < 24; ++i)
        {
            if (changesMask[7 + i])
            {
                data << int16(ObjectiveProgress[i]);
            }
        }
    }
}

void QuestLog::ClearChangesMask()
{
    Base::ClearChangesMask(QuestID);
    Base::ClearChangesMask(StateFlags);
    Base::ClearChangesMask(EndTime);
    Base::ClearChangesMask(AcceptTime);
    Base::ClearChangesMask(Field_10);
    Base::ClearChangesMask(ObjectiveProgress);
    _changesMask.ResetAll();
}

void ArenaCooldown::WriteCreate(ByteBuffer& data, Player const* owner, Player const* receiver) const
{
    data << int32(SpellID);
    data << int32(Charges);
    data << uint32(Flags);
    data << uint32(StartTime);
    data << uint32(EndTime);
    data << uint32(NextChargeTime);
    data << uint8(MaxCharges);
}

void ArenaCooldown::WriteUpdate(ByteBuffer& data, Player const* owner, Player const* receiver) const
{
    UpdateMask<8> const& changesMask = _changesMask;
    data.WriteBits(changesMask.GetBlock(0), 8);

    data.FlushBits();
    if (changesMask[0])
    {
        if (changesMask[1])
        {
            data << int32(SpellID);
        }
        if (changesMask[2])
        {
            data << int32(Charges);
        }
        if (changesMask[3])
        {
            data << uint32(Flags);
        }
        if (changesMask[4])
        {
            data << uint32(StartTime);
        }
        if (changesMask[5])
        {
            data << uint32(EndTime);
        }
        if (changesMask[6])
        {
            data << uint32(NextChargeTime);
        }
        if (changesMask[7])
        {
            data << uint8(MaxCharges);
        }
    }
}

void ArenaCooldown::ClearChangesMask()
{
    Base::ClearChangesMask(SpellID);
    Base::ClearChangesMask(Charges);
    Base::ClearChangesMask(Flags);
    Base::ClearChangesMask(StartTime);
    Base::ClearChangesMask(EndTime);
    Base::ClearChangesMask(NextChargeTime);
    Base::ClearChangesMask(MaxCharges);
    _changesMask.ResetAll();
}

void PlayerData::WriteCreate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Player const* owner, Player const* receiver) const
{
    data << DuelArbiter;
    data << WowAccount;
    data << LootTargetGUID;
    data << uint32(PlayerFlags);
    data << uint32(PlayerFlagsEx);
    data << uint32(GuildRankID);
    data << uint32(GuildDeleteDate);
    data << int32(GuildLevel);
    data << uint8(SkinID);
    data << uint8(FaceID);
    data << uint8(HairStyleID);
    data << uint8(HairColorID);
    for (std::size_t i = 0; i < 3; ++i)
    {
        data << uint8(CustomDisplayOption[i]);
    }
    data << uint8(FacialHairStyleID);
    data << uint8(PartyType);
    data << uint8(NativeSex);
    data << uint8(Inebriation);
    data << uint8(PvpTitle);
    data << uint8(ArenaFaction);
    data << uint32(DuelTeam);
    data << int32(GuildTimeStamp);
    if (fieldVisibilityFlags.HasFlag(UpdateFieldFlag::PartyMember))
    {
        for (std::size_t i = 0; i < 125; ++i)
        {
            QuestLog[i].WriteCreate(data, owner, receiver);
        }
        data << uint32(QuestSessionQuestLog.size());
    }
    for (std::size_t i = 0; i < 19; ++i)
    {
        VisibleItems[i].WriteCreate(data, owner, receiver);
    }
    data << int32(PlayerTitle);
    data << int32(FakeInebriation);
    data << uint32(VirtualPlayerRealm);
    data << uint32(CurrentSpecID);
    data << int32(TaxiMountAnimKitID);
    for (std::size_t i = 0; i < 4; ++i)
    {
        data << float(AvgItemLevel[i]);
    }
    data << uint8(CurrentBattlePetBreedQuality);
    data << int32(HonorLevel);
    data << uint32(ArenaCooldowns.size());
    data << int32(Field_B0);
    data << int32(Field_B4);
    data << Field_F8;
    data << int32(Field_108);
    if (fieldVisibilityFlags.HasFlag(UpdateFieldFlag::PartyMember))
    {
        for (std::size_t i = 0; i < QuestSessionQuestLog.size(); ++i)
        {
            QuestSessionQuestLog[i].WriteCreate(data, owner, receiver);
        }
    }
    for (std::size_t i = 0; i < ArenaCooldowns.size(); ++i)
    {
        ArenaCooldowns[i].WriteCreate(data, owner, receiver);
    }
    if (fieldVisibilityFlags.HasFlag(UpdateFieldFlag::PartyMember))
    {
        data.WriteBit(HasQuestSession);
    }
    data.WriteBit(HasLevelLink);
    data.FlushBits();
}

void PlayerData::WriteUpdate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Player const* owner, Player const* receiver) const
{
    UpdateMask<192> allowedMaskForTarget({ 0xFFFFFFF5u, 0x000001FFu, 0x00000000u, 0x00000000u, 0x00000000u, 0xFFFFFF80u });
    AppendAllowedFieldsMaskForFlag(allowedMaskForTarget, fieldVisibilityFlags);
    WriteUpdate(data, _changesMask & allowedMaskForTarget, fieldVisibilityFlags, owner, receiver);
}

void PlayerData::AppendAllowedFieldsMaskForFlag(UpdateMask<192>& allowedMaskForTarget, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags) const
{
    if (fieldVisibilityFlags.HasFlag(UpdateFieldFlag::PartyMember))
        allowedMaskForTarget |= { 0x0000000Au, 0xFFFFFE00u, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0x0000007Fu };
}

void PlayerData::WriteUpdate(ByteBuffer& data, UpdateMask<192> const& changesMask, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Player const* owner, Player const* receiver) const
{
    data.WriteBits(changesMask.GetBlocksMask(0), 6);
    for (std::size_t i = 0; i < 6; ++i)
        if (changesMask.GetBlock(i))
            data.WriteBits(changesMask.GetBlock(i), 32);

    bool noQuestLogChangesMask = data.WriteBit(IsQuestLogChangesMaskSkipped());
    if (changesMask[0])
    {
        if (changesMask[1])
        {
            data.WriteBit(HasQuestSession);
        }
        if (changesMask[2])
        {
            data.WriteBit(HasLevelLink);
        }
        if (changesMask[3])
        {
            QuestSessionQuestLog.WriteUpdateMask(data);
        }
        if (changesMask[4])
        {
            ArenaCooldowns.WriteUpdateMask(data);
        }
    }
    data.FlushBits();
    if (changesMask[0])
    {
        if (changesMask[3])
        {
            for (std::size_t i = 0; i < QuestSessionQuestLog.size(); ++i)
            {
                if (QuestSessionQuestLog.HasChanged(i))
                {
                    if (noQuestLogChangesMask)
                        QuestSessionQuestLog[i].WriteCreate(data, owner, receiver);
                    else
                        QuestSessionQuestLog[i].WriteUpdate(data, owner, receiver);
                }
            }
        }
        if (changesMask[4])
        {
            for (std::size_t i = 0; i < ArenaCooldowns.size(); ++i)
            {
                if (ArenaCooldowns.HasChanged(i))
                {
                    ArenaCooldowns[i].WriteUpdate(data, owner, receiver);
                }
            }
        }
        if (changesMask[5])
        {
            data << DuelArbiter;
        }
        if (changesMask[6])
        {
            data << WowAccount;
        }
        if (changesMask[7])
        {
            data << LootTargetGUID;
        }
        if (changesMask[8])
        {
            data << uint32(PlayerFlags);
        }
        if (changesMask[9])
        {
            data << uint32(PlayerFlagsEx);
        }
        if (changesMask[10])
        {
            data << uint32(GuildRankID);
        }
        if (changesMask[11])
        {
            data << uint32(GuildDeleteDate);
        }
        if (changesMask[12])
        {
            data << int32(GuildLevel);
        }
        if (changesMask[13])
        {
            data << uint8(SkinID);
        }
        if (changesMask[14])
        {
            data << uint8(FaceID);
        }
        if (changesMask[15])
        {
            data << uint8(HairStyleID);
        }
        if (changesMask[16])
        {
            data << uint8(HairColorID);
        }
        if (changesMask[17])
        {
            data << uint8(FacialHairStyleID);
        }
        if (changesMask[18])
        {
            data << uint8(PartyType);
        }
        if (changesMask[19])
        {
            data << uint8(NativeSex);
        }
        if (changesMask[20])
        {
            data << uint8(Inebriation);
        }
        if (changesMask[21])
        {
            data << uint8(PvpTitle);
        }
        if (changesMask[22])
        {
            data << uint8(ArenaFaction);
        }
        if (changesMask[23])
        {
            data << uint32(DuelTeam);
        }
        if (changesMask[24])
        {
            data << int32(GuildTimeStamp);
        }
        if (changesMask[25])
        {
            data << int32(PlayerTitle);
        }
        if (changesMask[26])
        {
            data << int32(FakeInebriation);
        }
        if (changesMask[27])
        {
            data << uint32(VirtualPlayerRealm);
        }
        if (changesMask[28])
        {
            data << uint32(CurrentSpecID);
        }
        if (changesMask[29])
        {
            data << int32(TaxiMountAnimKitID);
        }
        if (changesMask[30])
        {
            data << uint8(CurrentBattlePetBreedQuality);
        }
        if (changesMask[31])
        {
            data << int32(HonorLevel);
        }
    }
    if (changesMask[32])
    {
        if (changesMask[33])
        {
            data << int32(Field_B0);
        }
        if (changesMask[34])
        {
            data << int32(Field_B4);
        }
        if (changesMask[35])
        {
            data << Field_F8;
        }
        if (changesMask[36])
        {
            data << int32(Field_108);
        }
    }
    if (changesMask[37])
    {
        for (std::size_t i = 0; i < 3; ++i)
        {
            if (changesMask[38 + i])
            {
                data << uint8(CustomDisplayOption[i]);
            }
        }
    }
    if (changesMask[41])
    {
        for (std::size_t i = 0; i < 125; ++i)
        {
            if (changesMask[42 + i])
            {
                if (noQuestLogChangesMask)
                    QuestLog[i].WriteCreate(data, owner, receiver);
                else
                    QuestLog[i].WriteUpdate(data, owner, receiver);
            }
        }
    }
    if (changesMask[167])
    {
        for (std::size_t i = 0; i < 19; ++i)
        {
            if (changesMask[168 + i])
            {
                VisibleItems[i].WriteUpdate(data, owner, receiver);
            }
        }
    }
    if (changesMask[187])
    {
        for (std::size_t i = 0; i < 4; ++i)
        {
            if (changesMask[188 + i])
            {
                data << float(AvgItemLevel[i]);
            }
        }
    }
    data.FlushBits();
}

void PlayerData::ClearChangesMask()
{
    Base::ClearChangesMask(HasQuestSession);
    Base::ClearChangesMask(HasLevelLink);
    Base::ClearChangesMask(QuestSessionQuestLog);
    Base::ClearChangesMask(ArenaCooldowns);
    Base::ClearChangesMask(DuelArbiter);
    Base::ClearChangesMask(WowAccount);
    Base::ClearChangesMask(LootTargetGUID);
    Base::ClearChangesMask(PlayerFlags);
    Base::ClearChangesMask(PlayerFlagsEx);
    Base::ClearChangesMask(GuildRankID);
    Base::ClearChangesMask(GuildDeleteDate);
    Base::ClearChangesMask(GuildLevel);
    Base::ClearChangesMask(SkinID);
    Base::ClearChangesMask(FaceID);
    Base::ClearChangesMask(HairStyleID);
    Base::ClearChangesMask(HairColorID);
    Base::ClearChangesMask(FacialHairStyleID);
    Base::ClearChangesMask(PartyType);
    Base::ClearChangesMask(NativeSex);
    Base::ClearChangesMask(Inebriation);
    Base::ClearChangesMask(PvpTitle);
    Base::ClearChangesMask(ArenaFaction);
    Base::ClearChangesMask(DuelTeam);
    Base::ClearChangesMask(GuildTimeStamp);
    Base::ClearChangesMask(PlayerTitle);
    Base::ClearChangesMask(FakeInebriation);
    Base::ClearChangesMask(VirtualPlayerRealm);
    Base::ClearChangesMask(CurrentSpecID);
    Base::ClearChangesMask(TaxiMountAnimKitID);
    Base::ClearChangesMask(CurrentBattlePetBreedQuality);
    Base::ClearChangesMask(HonorLevel);
    Base::ClearChangesMask(Field_B0);
    Base::ClearChangesMask(Field_B4);
    Base::ClearChangesMask(Field_F8);
    Base::ClearChangesMask(Field_108);
    Base::ClearChangesMask(CustomDisplayOption);
    Base::ClearChangesMask(QuestLog);
    Base::ClearChangesMask(VisibleItems);
    Base::ClearChangesMask(AvgItemLevel);
    _changesMask.ResetAll();
}

void SkillInfo::WriteCreate(ByteBuffer& data, Player const* owner, Player const* receiver) const
{
    for (std::size_t i = 0; i < 256; ++i)
    {
        data << uint16(SkillLineID[i]);
        data << uint16(SkillStep[i]);
        data << uint16(SkillRank[i]);
        data << uint16(SkillStartingRank[i]);
        data << uint16(SkillMaxRank[i]);
        data << int16(SkillTempBonus[i]);
        data << uint16(SkillPermBonus[i]);
    }
}

void SkillInfo::WriteUpdate(ByteBuffer& data, Player const* owner, Player const* receiver) const
{
    UpdateMask<1793> const& changesMask = _changesMask;
    for (std::size_t i = 0; i < 1; ++i)
        data << uint32(changesMask.GetBlocksMask(i));
    data.WriteBits(changesMask.GetBlocksMask(1), 25);
    for (std::size_t i = 0; i < 57; ++i)
        if (changesMask.GetBlock(i))
            data.WriteBits(changesMask.GetBlock(i), 32);

    data.FlushBits();
    if (changesMask[0])
    {
        for (std::size_t i = 0; i < 256; ++i)
        {
            if (changesMask[1 + i])
            {
                data << uint16(SkillLineID[i]);
            }
            if (changesMask[257 + i])
            {
                data << uint16(SkillStep[i]);
            }
            if (changesMask[513 + i])
            {
                data << uint16(SkillRank[i]);
            }
            if (changesMask[769 + i])
            {
                data << uint16(SkillStartingRank[i]);
            }
            if (changesMask[1025 + i])
            {
                data << uint16(SkillMaxRank[i]);
            }
            if (changesMask[1281 + i])
            {
                data << int16(SkillTempBonus[i]);
            }
            if (changesMask[1537 + i])
            {
                data << uint16(SkillPermBonus[i]);
            }
        }
    }
}

void SkillInfo::ClearChangesMask()
{
    Base::ClearChangesMask(SkillLineID);
    Base::ClearChangesMask(SkillStep);
    Base::ClearChangesMask(SkillRank);
    Base::ClearChangesMask(SkillStartingRank);
    Base::ClearChangesMask(SkillMaxRank);
    Base::ClearChangesMask(SkillTempBonus);
    Base::ClearChangesMask(SkillPermBonus);
    _changesMask.ResetAll();
}

void RestInfo::WriteCreate(ByteBuffer& data, Player const* owner, Player const* receiver) const
{
    data << uint32(Threshold);
    data << uint8(StateID);
}

void RestInfo::WriteUpdate(ByteBuffer& data, Player const* owner, Player const* receiver) const
{
    UpdateMask<3> const& changesMask = _changesMask;
    data.WriteBits(changesMask.GetBlock(0), 3);

    data.FlushBits();
    if (changesMask[0])
    {
        if (changesMask[1])
        {
            data << uint32(Threshold);
        }
        if (changesMask[2])
        {
            data << uint8(StateID);
        }
    }
}

void RestInfo::ClearChangesMask()
{
    Base::ClearChangesMask(Threshold);
    Base::ClearChangesMask(StateID);
    _changesMask.ResetAll();
}

void PVPInfo::WriteCreate(ByteBuffer& data, Player const* owner, Player const* receiver) const
{
    data << uint32(Field_0);
    data << uint32(Field_4);
    data << uint32(Field_8);
    data << uint32(Field_C);
    data << uint32(Rating);
    data << uint32(Field_14);
    data << uint32(Field_18);
    data << uint32(PvpTierID);
    data.WriteBits(Field_20, 1);
    data.FlushBits();
}

void PVPInfo::WriteUpdate(ByteBuffer& data, Player const* owner, Player const* receiver) const
{
    UpdateMask<10> const& changesMask = _changesMask;
    data.WriteBits(changesMask.GetBlock(0), 10);

    data.FlushBits();
    if (changesMask[0])
    {
        if (changesMask[1])
        {
            data << uint32(Field_0);
        }
        if (changesMask[2])
        {
            data << uint32(Field_4);
        }
        if (changesMask[3])
        {
            data << uint32(Field_8);
        }
        if (changesMask[4])
        {
            data << uint32(Field_C);
        }
        if (changesMask[5])
        {
            data << uint32(Rating);
        }
        if (changesMask[6])
        {
            data << uint32(Field_14);
        }
        if (changesMask[7])
        {
            data << uint32(Field_18);
        }
        if (changesMask[8])
        {
            data << uint32(PvpTierID);
        }
        if (changesMask[9])
        {
            data.WriteBits(Field_20, 1);
        }
    }
    data.FlushBits();
}

void PVPInfo::ClearChangesMask()
{
    Base::ClearChangesMask(Field_0);
    Base::ClearChangesMask(Field_4);
    Base::ClearChangesMask(Field_8);
    Base::ClearChangesMask(Field_C);
    Base::ClearChangesMask(Rating);
    Base::ClearChangesMask(Field_14);
    Base::ClearChangesMask(Field_18);
    Base::ClearChangesMask(PvpTierID);
    Base::ClearChangesMask(Field_20);
    _changesMask.ResetAll();
}

void CharacterRestriction::WriteCreate(ByteBuffer& data, Player const* owner, Player const* receiver) const
{
    data << int32(Field_0);
    data << int32(Field_4);
    data << int32(Field_8);
    data.WriteBits(Type, 5);
    data.FlushBits();
}

void CharacterRestriction::WriteUpdate(ByteBuffer& data, Player const* owner, Player const* receiver) const
{
    data << int32(Field_0);
    data << int32(Field_4);
    data << int32(Field_8);
    data.WriteBits(Type, 5);
    data.FlushBits();
}

void SpellPctModByLabel::WriteCreate(ByteBuffer& data, Player const* owner, Player const* receiver) const
{
    data << int32(ModIndex);
    data << float(ModifierValue);
    data << int32(LabelID);
}

void SpellPctModByLabel::WriteUpdate(ByteBuffer& data, Player const* owner, Player const* receiver) const
{
    data << int32(ModIndex);
    data << float(ModifierValue);
    data << int32(LabelID);
}

void SpellFlatModByLabel::WriteCreate(ByteBuffer& data, Player const* owner, Player const* receiver) const
{
    data << int32(ModIndex);
    data << int32(ModifierValue);
    data << int32(LabelID);
}

void SpellFlatModByLabel::WriteUpdate(ByteBuffer& data, Player const* owner, Player const* receiver) const
{
    data << int32(ModIndex);
    data << int32(ModifierValue);
    data << int32(LabelID);
}

void Research::WriteCreate(ByteBuffer& data, Player const* owner, Player const* receiver) const
{
    data << int16(ResearchProjectID);
}

void Research::WriteUpdate(ByteBuffer& data, Player const* owner, Player const* receiver) const
{
    data << int16(ResearchProjectID);
}

void ReplayedQuest::WriteCreate(ByteBuffer& data, Player const* owner, Player const* receiver) const
{
    data << int32(QuestID);
    data << uint32(ReplayTime);
}

void ReplayedQuest::WriteUpdate(ByteBuffer& data, Player const* owner, Player const* receiver) const
{
    UpdateMask<3> const& changesMask = _changesMask;
    data.WriteBits(changesMask.GetBlock(0), 3);

    data.FlushBits();
    if (changesMask[0])
    {
        if (changesMask[1])
        {
            data << int32(QuestID);
        }
        if (changesMask[2])
        {
            data << uint32(ReplayTime);
        }
    }
}

void ReplayedQuest::ClearChangesMask()
{
    Base::ClearChangesMask(QuestID);
    Base::ClearChangesMask(ReplayTime);
    _changesMask.ResetAll();
}

void QuestSession::WriteCreate(ByteBuffer& data, Player const* owner, Player const* receiver) const
{
    data << Owner;
    for (std::size_t i = 0; i < 875; ++i)
    {
        data << uint64(QuestCompleted[i]);
    }
}

void QuestSession::WriteUpdate(ByteBuffer& data, Player const* owner, Player const* receiver) const
{
    UpdateMask<878> const& changesMask = _changesMask;
    data.WriteBits(changesMask.GetBlocksMask(0), 28);
    for (std::size_t i = 0; i < 28; ++i)
        if (changesMask.GetBlock(i))
            data.WriteBits(changesMask.GetBlock(i), 32);

    data.FlushBits();
    if (changesMask[0])
    {
        if (changesMask[1])
        {
            data << Owner;
        }
    }
    if (changesMask[2])
    {
        for (std::size_t i = 0; i < 875; ++i)
        {
            if (changesMask[3 + i])
            {
                data << uint64(QuestCompleted[i]);
            }
        }
    }
}

void QuestSession::ClearChangesMask()
{
    Base::ClearChangesMask(Owner);
    Base::ClearChangesMask(QuestCompleted);
    _changesMask.ResetAll();
}

void ActivePlayerData::WriteCreate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Player const* owner, Player const* receiver) const
{
    for (std::size_t i = 0; i < 199; ++i)
    {
        data << InvSlots[i];
    }
    data << FarsightObject;
    data << SummonedBattlePetGUID;
    data << uint32(KnownTitles.size());
    data << uint64(Coinage);
    data << int32(XP);
    data << int32(NextLevelXP);
    data << int32(TrialXP);
    Skill->WriteCreate(data, owner, receiver);
    data << int32(CharacterPoints);
    data << int32(MaxTalentTiers);
    data << int32(TrackCreatureMask);
    for (std::size_t i = 0; i < 2; ++i)
    {
        data << uint32(TrackResourceMask[i]);
    }
    data << float(MainhandExpertise);
    data << float(OffhandExpertise);
    data << float(RangedExpertise);
    data << float(CombatRatingExpertise);
    data << float(BlockPercentage);
    data << float(DodgePercentage);
    data << float(DodgePercentageFromAttribute);
    data << float(ParryPercentage);
    data << float(ParryPercentageFromAttribute);
    data << float(CritPercentage);
    data << float(RangedCritPercentage);
    data << float(OffhandCritPercentage);
    data << float(SpellCritPercentage);
    data << int32(ShieldBlock);
    data << float(ShieldBlockCritPercentage);
    data << float(Mastery);
    data << float(Speed);
    data << float(Avoidance);
    data << float(Sturdiness);
    data << int32(Versatility);
    data << float(VersatilityBonus);
    data << float(PvpPowerDamage);
    data << float(PvpPowerHealing);
    for (std::size_t i = 0; i < 192; ++i)
    {
        data << uint64(ExploredZones[i]);
    }
    for (std::size_t i = 0; i < 2; ++i)
    {
        RestInfo[i].WriteCreate(data, owner, receiver);
    }
    for (std::size_t i = 0; i < 7; ++i)
    {
        data << int32(ModDamageDonePos[i]);
        data << int32(ModDamageDoneNeg[i]);
        data << float(ModDamageDonePercent[i]);
    }
    data << int32(ModHealingDonePos);
    data << float(ModHealingPercent);
    data << float(ModHealingDonePercent);
    data << float(ModPeriodicHealingDonePercent);
    for (std::size_t i = 0; i < 3; ++i)
    {
        data << float(WeaponDmgMultipliers[i]);
        data << float(WeaponAtkSpeedMultipliers[i]);
    }
    data << float(ModSpellPowerPercent);
    data << float(ModResiliencePercent);
    data << float(OverrideSpellPowerByAPPercent);
    data << float(OverrideAPBySpellPowerPercent);
    data << int32(ModTargetResistance);
    data << int32(ModTargetPhysicalResistance);
    data << int32(LocalFlags);
    data << uint8(GrantableLevels);
    data << uint8(MultiActionBars);
    data << uint8(LifetimeMaxRank);
    data << uint8(NumRespecs);
    data << uint32(PvpMedals);
    for (std::size_t i = 0; i < 12; ++i)
    {
        data << uint32(BuybackPrice[i]);
        data << uint32(BuybackTimestamp[i]);
    }
    data << uint16(TodayHonorableKills);
    data << uint16(YesterdayHonorableKills);
    data << uint32(LifetimeHonorableKills);
    data << int32(WatchedFactionIndex);
    for (std::size_t i = 0; i < 32; ++i)
    {
        data << int32(CombatRatings[i]);
    }
    data << int32(MaxLevel);
    data << int32(ScalingPlayerLevelDelta);
    data << int32(MaxCreatureScalingLevel);
    for (std::size_t i = 0; i < 4; ++i)
    {
        data << uint32(NoReagentCostMask[i]);
    }
    data << int32(PetSpellPower);
    for (std::size_t i = 0; i < 2; ++i)
    {
        data << int32(ProfessionSkillLine[i]);
    }
    data << float(UiHitModifier);
    data << float(UiSpellHitModifier);
    data << int32(HomeRealmTimeOffset);
    data << float(ModPetHaste);
    data << uint8(LocalRegenFlags);
    data << uint8(AuraVision);
    data << uint8(NumBackpackSlots);
    data << int32(OverrideSpellsID);
    data << int32(LfgBonusFactionID);
    data << uint16(LootSpecID);
    data << uint32(OverrideZonePVPType);
    for (std::size_t i = 0; i < 4; ++i)
    {
        data << uint32(BagSlotFlags[i]);
    }
    for (std::size_t i = 0; i < 7; ++i)
    {
        data << uint32(BankBagSlotFlags[i]);
    }
    for (std::size_t i = 0; i < 875; ++i)
    {
        data << uint64(QuestCompleted[i]);
    }
    data << int32(Honor);
    data << int32(HonorNextLevel);
    data << int32(PvpRewardAchieved);
    data << int32(PvpTierMaxFromWins);
    data << int32(PvpLastWeeksRewardAchieved);
    data << int32(PvpLastWeeksTierMaxFromWins);
    data << int32(PvpLastWeeksRewardClaimed);
    data << uint8(NumBankSlots);
    data << uint32(ResearchSites.size());
    data << uint32(ResearchSiteProgress.size());
    data << uint32(DailyQuestsCompleted.size());
    data << uint32(AvailableQuestLineXQuestIDs.size());
    data << uint32(Heirlooms.size());
    data << uint32(HeirloomFlags.size());
    data << uint32(Toys.size());
    data << uint32(ToyFlags.size());
    data << uint32(Transmog.size());
    data << uint32(ConditionalTransmog.size());
    data << uint32(SelfResSpells.size());
    data << uint32(CharacterRestrictions.size());
    data << uint32(SpellPctModByLabel.size());
    data << uint32(SpellFlatModByLabel.size());
    for (std::size_t i = 0; i < 1; ++i)
    {
        data << uint32(Research[i].size());
        for (std::size_t j = 0; j < Research[i].size(); ++j)
        {
            Research[i][j].WriteCreate(data, owner, receiver);
        }
    }
    data << uint32(ReplayedQuests.size());
    data << uint32(DisabledSpells.size());
    for (std::size_t i = 0; i < KnownTitles.size(); ++i)
    {
        data << uint64(KnownTitles[i]);
    }
    for (std::size_t i = 0; i < ResearchSites.size(); ++i)
    {
        data << uint16(ResearchSites[i]);
    }
    for (std::size_t i = 0; i < ResearchSiteProgress.size(); ++i)
    {
        data << uint32(ResearchSiteProgress[i]);
    }
    for (std::size_t i = 0; i < DailyQuestsCompleted.size(); ++i)
    {
        data << int32(DailyQuestsCompleted[i]);
    }
    for (std::size_t i = 0; i < AvailableQuestLineXQuestIDs.size(); ++i)
    {
        data << int32(AvailableQuestLineXQuestIDs[i]);
    }
    for (std::size_t i = 0; i < Heirlooms.size(); ++i)
    {
        data << int32(Heirlooms[i]);
    }
    for (std::size_t i = 0; i < HeirloomFlags.size(); ++i)
    {
        data << uint32(HeirloomFlags[i]);
    }
    for (std::size_t i = 0; i < Toys.size(); ++i)
    {
        data << int32(Toys[i]);
    }
    for (std::size_t i = 0; i < ToyFlags.size(); ++i)
    {
        data << uint32(ToyFlags[i]);
    }
    for (std::size_t i = 0; i < Transmog.size(); ++i)
    {
        data << uint32(Transmog[i]);
    }
    for (std::size_t i = 0; i < ConditionalTransmog.size(); ++i)
    {
        data << int32(ConditionalTransmog[i]);
    }
    for (std::size_t i = 0; i < SelfResSpells.size(); ++i)
    {
        data << int32(SelfResSpells[i]);
    }
    for (std::size_t i = 0; i < SpellPctModByLabel.size(); ++i)
    {
        SpellPctModByLabel[i].WriteCreate(data, owner, receiver);
    }
    for (std::size_t i = 0; i < SpellFlatModByLabel.size(); ++i)
    {
        SpellFlatModByLabel[i].WriteCreate(data, owner, receiver);
    }
    for (std::size_t i = 0; i < ReplayedQuests.size(); ++i)
    {
        ReplayedQuests[i].WriteCreate(data, owner, receiver);
    }
    for (std::size_t i = 0; i < DisabledSpells.size(); ++i)
    {
        data << int32(DisabledSpells[i]);
    }
    for (std::size_t i = 0; i < 6; ++i)
    {
        PvpInfo[i].WriteCreate(data, owner, receiver);
    }
    data.WriteBit(BackpackAutoSortDisabled);
    data.WriteBit(BankAutoSortDisabled);
    data.WriteBit(SortBagsRightToLeft);
    data.WriteBit(InsertItemsLeftToRight);
    data.WriteBit(QuestSession.is_initialized());
    for (std::size_t i = 0; i < CharacterRestrictions.size(); ++i)
    {
        CharacterRestrictions[i].WriteCreate(data, owner, receiver);
    }
    if (QuestSession.is_initialized())
    {
        QuestSession->WriteCreate(data, owner, receiver);
    }
    data.FlushBits();
}

void ActivePlayerData::WriteUpdate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Player const* owner, Player const* receiver) const
{
    UpdateMask<1494> const& changesMask = _changesMask;
    for (std::size_t i = 0; i < 1; ++i)
        data << uint32(changesMask.GetBlocksMask(i));
    data.WriteBits(changesMask.GetBlocksMask(1), 15);
    for (std::size_t i = 0; i < 47; ++i)
        if (changesMask.GetBlock(i))
            data.WriteBits(changesMask.GetBlock(i), 32);

    if (changesMask[0])
    {
        if (changesMask[1])
        {
            data.WriteBit(BackpackAutoSortDisabled);
        }
        if (changesMask[2])
        {
            data.WriteBit(BankAutoSortDisabled);
        }
        if (changesMask[3])
        {
            data.WriteBit(SortBagsRightToLeft);
        }
        if (changesMask[4])
        {
            data.WriteBit(InsertItemsLeftToRight);
        }
        if (changesMask[5])
        {
            KnownTitles.WriteUpdateMask(data);
        }
        if (changesMask[6])
        {
            ResearchSites.WriteUpdateMask(data);
        }
        if (changesMask[7])
        {
            ResearchSiteProgress.WriteUpdateMask(data);
        }
        if (changesMask[8])
        {
            DailyQuestsCompleted.WriteUpdateMask(data);
        }
        if (changesMask[9])
        {
            AvailableQuestLineXQuestIDs.WriteUpdateMask(data);
        }
        if (changesMask[10])
        {
            Heirlooms.WriteUpdateMask(data);
        }
        if (changesMask[11])
        {
            HeirloomFlags.WriteUpdateMask(data);
        }
        if (changesMask[12])
        {
            Toys.WriteUpdateMask(data);
        }
        if (changesMask[13])
        {
            ToyFlags.WriteUpdateMask(data);
        }
        if (changesMask[14])
        {
            Transmog.WriteUpdateMask(data);
        }
        if (changesMask[15])
        {
            ConditionalTransmog.WriteUpdateMask(data);
        }
        if (changesMask[16])
        {
            SelfResSpells.WriteUpdateMask(data);
        }
        if (changesMask[17])
        {
            CharacterRestrictions.WriteUpdateMask(data);
        }
        if (changesMask[18])
        {
            SpellPctModByLabel.WriteUpdateMask(data);
        }
        if (changesMask[19])
        {
            SpellFlatModByLabel.WriteUpdateMask(data);
        }
    }
    if (changesMask[22])
    {
        for (std::size_t i = 0; i < 1; ++i)
        {
            if (changesMask[23 + i])
            {
                Research[i].WriteUpdateMask(data);
            }
        }
    }
    if (changesMask[22])
    {
        for (std::size_t i = 0; i < 1; ++i)
        {
            if (changesMask[23 + i])
            {
                for (std::size_t j = 0; j < Research[i].size(); ++j)
                {
                    if (Research[i].HasChanged(j))
                    {
                        Research[i][j].WriteUpdate(data, owner, receiver);
                    }
                }
            }
        }
    }
    data.FlushBits();
    if (changesMask[0])
    {
        if (changesMask[20])
        {
            ReplayedQuests.WriteUpdateMask(data);
        }
        if (changesMask[21])
        {
            DisabledSpells.WriteUpdateMask(data);
        }
    }
    data.FlushBits();
    if (changesMask[0])
    {
        if (changesMask[5])
        {
            for (std::size_t i = 0; i < KnownTitles.size(); ++i)
            {
                if (KnownTitles.HasChanged(i))
                {
                    data << uint64(KnownTitles[i]);
                }
            }
        }
        if (changesMask[6])
        {
            for (std::size_t i = 0; i < ResearchSites.size(); ++i)
            {
                if (ResearchSites.HasChanged(i))
                {
                    data << uint16(ResearchSites[i]);
                }
            }
        }
        if (changesMask[7])
        {
            for (std::size_t i = 0; i < ResearchSiteProgress.size(); ++i)
            {
                if (ResearchSiteProgress.HasChanged(i))
                {
                    data << uint32(ResearchSiteProgress[i]);
                }
            }
        }
        if (changesMask[8])
        {
            for (std::size_t i = 0; i < DailyQuestsCompleted.size(); ++i)
            {
                if (DailyQuestsCompleted.HasChanged(i))
                {
                    data << int32(DailyQuestsCompleted[i]);
                }
            }
        }
        if (changesMask[9])
        {
            for (std::size_t i = 0; i < AvailableQuestLineXQuestIDs.size(); ++i)
            {
                if (AvailableQuestLineXQuestIDs.HasChanged(i))
                {
                    data << int32(AvailableQuestLineXQuestIDs[i]);
                }
            }
        }
        if (changesMask[10])
        {
            for (std::size_t i = 0; i < Heirlooms.size(); ++i)
            {
                if (Heirlooms.HasChanged(i))
                {
                    data << int32(Heirlooms[i]);
                }
            }
        }
        if (changesMask[11])
        {
            for (std::size_t i = 0; i < HeirloomFlags.size(); ++i)
            {
                if (HeirloomFlags.HasChanged(i))
                {
                    data << uint32(HeirloomFlags[i]);
                }
            }
        }
        if (changesMask[12])
        {
            for (std::size_t i = 0; i < Toys.size(); ++i)
            {
                if (Toys.HasChanged(i))
                {
                    data << int32(Toys[i]);
                }
            }
        }
        if (changesMask[13])
        {
            for (std::size_t i = 0; i < ToyFlags.size(); ++i)
            {
                if (ToyFlags.HasChanged(i))
                {
                    data << uint32(ToyFlags[i]);
                }
            }
        }
        if (changesMask[14])
        {
            for (std::size_t i = 0; i < Transmog.size(); ++i)
            {
                if (Transmog.HasChanged(i))
                {
                    data << uint32(Transmog[i]);
                }
            }
        }
        if (changesMask[15])
        {
            for (std::size_t i = 0; i < ConditionalTransmog.size(); ++i)
            {
                if (ConditionalTransmog.HasChanged(i))
                {
                    data << int32(ConditionalTransmog[i]);
                }
            }
        }
        if (changesMask[16])
        {
            for (std::size_t i = 0; i < SelfResSpells.size(); ++i)
            {
                if (SelfResSpells.HasChanged(i))
                {
                    data << int32(SelfResSpells[i]);
                }
            }
        }
        if (changesMask[18])
        {
            for (std::size_t i = 0; i < SpellPctModByLabel.size(); ++i)
            {
                if (SpellPctModByLabel.HasChanged(i))
                {
                    SpellPctModByLabel[i].WriteUpdate(data, owner, receiver);
                }
            }
        }
        if (changesMask[19])
        {
            for (std::size_t i = 0; i < SpellFlatModByLabel.size(); ++i)
            {
                if (SpellFlatModByLabel.HasChanged(i))
                {
                    SpellFlatModByLabel[i].WriteUpdate(data, owner, receiver);
                }
            }
        }
        if (changesMask[20])
        {
            for (std::size_t i = 0; i < ReplayedQuests.size(); ++i)
            {
                if (ReplayedQuests.HasChanged(i))
                {
                    ReplayedQuests[i].WriteUpdate(data, owner, receiver);
                }
            }
        }
        if (changesMask[21])
        {
            for (std::size_t i = 0; i < DisabledSpells.size(); ++i)
            {
                if (DisabledSpells.HasChanged(i))
                {
                    data << int32(DisabledSpells[i]);
                }
            }
        }
        if (changesMask[17])
        {
            for (std::size_t i = 0; i < CharacterRestrictions.size(); ++i)
            {
                if (CharacterRestrictions.HasChanged(i))
                {
                    CharacterRestrictions[i].WriteUpdate(data, owner, receiver);
                }
            }
        }
        if (changesMask[24])
        {
            data << FarsightObject;
        }
        if (changesMask[25])
        {
            data << SummonedBattlePetGUID;
        }
        if (changesMask[26])
        {
            data << uint64(Coinage);
        }
        if (changesMask[27])
        {
            data << int32(XP);
        }
        if (changesMask[28])
        {
            data << int32(NextLevelXP);
        }
        if (changesMask[29])
        {
            data << int32(TrialXP);
        }
        if (changesMask[30])
        {
            Skill->WriteUpdate(data, owner, receiver);
        }
        if (changesMask[31])
        {
            data << int32(CharacterPoints);
        }
        if (changesMask[32])
        {
            data << int32(MaxTalentTiers);
        }
        if (changesMask[33])
        {
            data << int32(TrackCreatureMask);
        }
    }
    if (changesMask[34])
    {
        if (changesMask[35])
        {
            data << float(MainhandExpertise);
        }
        if (changesMask[36])
        {
            data << float(OffhandExpertise);
        }
        if (changesMask[37])
        {
            data << float(RangedExpertise);
        }
        if (changesMask[38])
        {
            data << float(CombatRatingExpertise);
        }
        if (changesMask[39])
        {
            data << float(BlockPercentage);
        }
        if (changesMask[40])
        {
            data << float(DodgePercentage);
        }
        if (changesMask[41])
        {
            data << float(DodgePercentageFromAttribute);
        }
        if (changesMask[42])
        {
            data << float(ParryPercentage);
        }
        if (changesMask[43])
        {
            data << float(ParryPercentageFromAttribute);
        }
        if (changesMask[44])
        {
            data << float(CritPercentage);
        }
        if (changesMask[45])
        {
            data << float(RangedCritPercentage);
        }
        if (changesMask[46])
        {
            data << float(OffhandCritPercentage);
        }
        if (changesMask[47])
        {
            data << float(SpellCritPercentage);
        }
        if (changesMask[48])
        {
            data << int32(ShieldBlock);
        }
        if (changesMask[49])
        {
            data << float(ShieldBlockCritPercentage);
        }
        if (changesMask[50])
        {
            data << float(Mastery);
        }
        if (changesMask[51])
        {
            data << float(Speed);
        }
        if (changesMask[52])
        {
            data << float(Avoidance);
        }
        if (changesMask[53])
        {
            data << float(Sturdiness);
        }
        if (changesMask[54])
        {
            data << int32(Versatility);
        }
        if (changesMask[55])
        {
            data << float(VersatilityBonus);
        }
        if (changesMask[56])
        {
            data << float(PvpPowerDamage);
        }
        if (changesMask[57])
        {
            data << float(PvpPowerHealing);
        }
        if (changesMask[58])
        {
            data << int32(ModHealingDonePos);
        }
        if (changesMask[59])
        {
            data << float(ModHealingPercent);
        }
        if (changesMask[60])
        {
            data << float(ModHealingDonePercent);
        }
        if (changesMask[61])
        {
            data << float(ModPeriodicHealingDonePercent);
        }
        if (changesMask[62])
        {
            data << float(ModSpellPowerPercent);
        }
        if (changesMask[63])
        {
            data << float(ModResiliencePercent);
        }
        if (changesMask[64])
        {
            data << float(OverrideSpellPowerByAPPercent);
        }
        if (changesMask[65])
        {
            data << float(OverrideAPBySpellPowerPercent);
        }
    }
    if (changesMask[66])
    {
        if (changesMask[67])
        {
            data << int32(ModTargetResistance);
        }
        if (changesMask[68])
        {
            data << int32(ModTargetPhysicalResistance);
        }
        if (changesMask[69])
        {
            data << int32(LocalFlags);
        }
        if (changesMask[70])
        {
            data << uint8(GrantableLevels);
        }
        if (changesMask[71])
        {
            data << uint8(MultiActionBars);
        }
        if (changesMask[72])
        {
            data << uint8(LifetimeMaxRank);
        }
        if (changesMask[73])
        {
            data << uint8(NumRespecs);
        }
        if (changesMask[74])
        {
            data << uint32(PvpMedals);
        }
        if (changesMask[75])
        {
            data << uint16(TodayHonorableKills);
        }
        if (changesMask[76])
        {
            data << uint16(YesterdayHonorableKills);
        }
        if (changesMask[77])
        {
            data << uint32(LifetimeHonorableKills);
        }
        if (changesMask[78])
        {
            data << int32(WatchedFactionIndex);
        }
        if (changesMask[79])
        {
            data << int32(MaxLevel);
        }
        if (changesMask[80])
        {
            data << int32(ScalingPlayerLevelDelta);
        }
        if (changesMask[81])
        {
            data << int32(MaxCreatureScalingLevel);
        }
        if (changesMask[82])
        {
            data << int32(PetSpellPower);
        }
        if (changesMask[83])
        {
            data << float(UiHitModifier);
        }
        if (changesMask[84])
        {
            data << float(UiSpellHitModifier);
        }
        if (changesMask[85])
        {
            data << int32(HomeRealmTimeOffset);
        }
        if (changesMask[86])
        {
            data << float(ModPetHaste);
        }
        if (changesMask[87])
        {
            data << uint8(LocalRegenFlags);
        }
        if (changesMask[88])
        {
            data << uint8(AuraVision);
        }
        if (changesMask[89])
        {
            data << uint8(NumBackpackSlots);
        }
        if (changesMask[90])
        {
            data << int32(OverrideSpellsID);
        }
        if (changesMask[91])
        {
            data << int32(LfgBonusFactionID);
        }
        if (changesMask[92])
        {
            data << uint16(LootSpecID);
        }
        if (changesMask[93])
        {
            data << uint32(OverrideZonePVPType);
        }
        if (changesMask[94])
        {
            data << int32(Honor);
        }
        if (changesMask[95])
        {
            data << int32(HonorNextLevel);
        }
        if (changesMask[96])
        {
            data << int32(PvpRewardAchieved);
        }
        if (changesMask[97])
        {
            data << int32(PvpTierMaxFromWins);
        }
    }
    if (changesMask[98])
    {
        if (changesMask[99])
        {
            data << int32(PvpLastWeeksRewardAchieved);
        }
        if (changesMask[100])
        {
            data << int32(PvpLastWeeksTierMaxFromWins);
        }
        if (changesMask[101])
        {
            data << int32(PvpLastWeeksRewardClaimed);
        }
        if (changesMask[102])
        {
            data << uint8(NumBankSlots);
        }
    }
    data.FlushBits();
    if (changesMask[98])
    {
        data.WriteBit(QuestSession.is_initialized());
        if (changesMask[103])
        {
            if (QuestSession.is_initialized())
            {
                QuestSession->WriteUpdate(data, owner, receiver);
            }
        }
    }
    if (changesMask[104])
    {
        for (std::size_t i = 0; i < 199; ++i)
        {
            if (changesMask[105 + i])
            {
                data << InvSlots[i];
            }
        }
    }
    if (changesMask[304])
    {
        for (std::size_t i = 0; i < 2; ++i)
        {
            if (changesMask[305 + i])
            {
                data << uint32(TrackResourceMask[i]);
            }
        }
    }
    if (changesMask[307])
    {
        for (std::size_t i = 0; i < 192; ++i)
        {
            if (changesMask[308 + i])
            {
                data << uint64(ExploredZones[i]);
            }
        }
    }
    if (changesMask[500])
    {
        for (std::size_t i = 0; i < 2; ++i)
        {
            if (changesMask[501 + i])
            {
                RestInfo[i].WriteUpdate(data, owner, receiver);
            }
        }
    }
    if (changesMask[503])
    {
        for (std::size_t i = 0; i < 7; ++i)
        {
            if (changesMask[504 + i])
            {
                data << int32(ModDamageDonePos[i]);
            }
            if (changesMask[511 + i])
            {
                data << int32(ModDamageDoneNeg[i]);
            }
            if (changesMask[518 + i])
            {
                data << float(ModDamageDonePercent[i]);
            }
        }
    }
    if (changesMask[525])
    {
        for (std::size_t i = 0; i < 3; ++i)
        {
            if (changesMask[526 + i])
            {
                data << float(WeaponDmgMultipliers[i]);
            }
            if (changesMask[529 + i])
            {
                data << float(WeaponAtkSpeedMultipliers[i]);
            }
        }
    }
    if (changesMask[532])
    {
        for (std::size_t i = 0; i < 12; ++i)
        {
            if (changesMask[533 + i])
            {
                data << uint32(BuybackPrice[i]);
            }
            if (changesMask[545 + i])
            {
                data << uint32(BuybackTimestamp[i]);
            }
        }
    }
    if (changesMask[557])
    {
        for (std::size_t i = 0; i < 32; ++i)
        {
            if (changesMask[558 + i])
            {
                data << int32(CombatRatings[i]);
            }
        }
    }
    if (changesMask[597])
    {
        for (std::size_t i = 0; i < 4; ++i)
        {
            if (changesMask[598 + i])
            {
                data << uint32(NoReagentCostMask[i]);
            }
        }
    }
    if (changesMask[602])
    {
        for (std::size_t i = 0; i < 2; ++i)
        {
            if (changesMask[603 + i])
            {
                data << int32(ProfessionSkillLine[i]);
            }
        }
    }
    if (changesMask[605])
    {
        for (std::size_t i = 0; i < 4; ++i)
        {
            if (changesMask[606 + i])
            {
                data << uint32(BagSlotFlags[i]);
            }
        }
    }
    if (changesMask[610])
    {
        for (std::size_t i = 0; i < 7; ++i)
        {
            if (changesMask[611 + i])
            {
                data << uint32(BankBagSlotFlags[i]);
            }
        }
    }
    if (changesMask[618])
    {
        for (std::size_t i = 0; i < 875; ++i)
        {
            if (changesMask[619 + i])
            {
                data << uint64(QuestCompleted[i]);
            }
        }
    }
    if (changesMask[590])
    {
        for (std::size_t i = 0; i < 6; ++i)
        {
            if (changesMask[591 + i])
            {
                PvpInfo[i].WriteUpdate(data, owner, receiver);
            }
        }
    }
    data.FlushBits();
}

void ActivePlayerData::ClearChangesMask()
{
    Base::ClearChangesMask(BackpackAutoSortDisabled);
    Base::ClearChangesMask(BankAutoSortDisabled);
    Base::ClearChangesMask(SortBagsRightToLeft);
    Base::ClearChangesMask(InsertItemsLeftToRight);
    Base::ClearChangesMask(Research);
    Base::ClearChangesMask(KnownTitles);
    Base::ClearChangesMask(ResearchSites);
    Base::ClearChangesMask(ResearchSiteProgress);
    Base::ClearChangesMask(DailyQuestsCompleted);
    Base::ClearChangesMask(AvailableQuestLineXQuestIDs);
    Base::ClearChangesMask(Heirlooms);
    Base::ClearChangesMask(HeirloomFlags);
    Base::ClearChangesMask(Toys);
    Base::ClearChangesMask(ToyFlags);
    Base::ClearChangesMask(Transmog);
    Base::ClearChangesMask(ConditionalTransmog);
    Base::ClearChangesMask(SelfResSpells);
    Base::ClearChangesMask(SpellPctModByLabel);
    Base::ClearChangesMask(SpellFlatModByLabel);
    Base::ClearChangesMask(ReplayedQuests);
    Base::ClearChangesMask(DisabledSpells);
    Base::ClearChangesMask(CharacterRestrictions);
    Base::ClearChangesMask(FarsightObject);
    Base::ClearChangesMask(SummonedBattlePetGUID);
    Base::ClearChangesMask(Coinage);
    Base::ClearChangesMask(XP);
    Base::ClearChangesMask(NextLevelXP);
    Base::ClearChangesMask(TrialXP);
    Base::ClearChangesMask(Skill);
    Base::ClearChangesMask(CharacterPoints);
    Base::ClearChangesMask(MaxTalentTiers);
    Base::ClearChangesMask(TrackCreatureMask);
    Base::ClearChangesMask(MainhandExpertise);
    Base::ClearChangesMask(OffhandExpertise);
    Base::ClearChangesMask(RangedExpertise);
    Base::ClearChangesMask(CombatRatingExpertise);
    Base::ClearChangesMask(BlockPercentage);
    Base::ClearChangesMask(DodgePercentage);
    Base::ClearChangesMask(DodgePercentageFromAttribute);
    Base::ClearChangesMask(ParryPercentage);
    Base::ClearChangesMask(ParryPercentageFromAttribute);
    Base::ClearChangesMask(CritPercentage);
    Base::ClearChangesMask(RangedCritPercentage);
    Base::ClearChangesMask(OffhandCritPercentage);
    Base::ClearChangesMask(SpellCritPercentage);
    Base::ClearChangesMask(ShieldBlock);
    Base::ClearChangesMask(ShieldBlockCritPercentage);
    Base::ClearChangesMask(Mastery);
    Base::ClearChangesMask(Speed);
    Base::ClearChangesMask(Avoidance);
    Base::ClearChangesMask(Sturdiness);
    Base::ClearChangesMask(Versatility);
    Base::ClearChangesMask(VersatilityBonus);
    Base::ClearChangesMask(PvpPowerDamage);
    Base::ClearChangesMask(PvpPowerHealing);
    Base::ClearChangesMask(ModHealingDonePos);
    Base::ClearChangesMask(ModHealingPercent);
    Base::ClearChangesMask(ModHealingDonePercent);
    Base::ClearChangesMask(ModPeriodicHealingDonePercent);
    Base::ClearChangesMask(ModSpellPowerPercent);
    Base::ClearChangesMask(ModResiliencePercent);
    Base::ClearChangesMask(OverrideSpellPowerByAPPercent);
    Base::ClearChangesMask(OverrideAPBySpellPowerPercent);
    Base::ClearChangesMask(ModTargetResistance);
    Base::ClearChangesMask(ModTargetPhysicalResistance);
    Base::ClearChangesMask(LocalFlags);
    Base::ClearChangesMask(GrantableLevels);
    Base::ClearChangesMask(MultiActionBars);
    Base::ClearChangesMask(LifetimeMaxRank);
    Base::ClearChangesMask(NumRespecs);
    Base::ClearChangesMask(PvpMedals);
    Base::ClearChangesMask(TodayHonorableKills);
    Base::ClearChangesMask(YesterdayHonorableKills);
    Base::ClearChangesMask(LifetimeHonorableKills);
    Base::ClearChangesMask(WatchedFactionIndex);
    Base::ClearChangesMask(MaxLevel);
    Base::ClearChangesMask(ScalingPlayerLevelDelta);
    Base::ClearChangesMask(MaxCreatureScalingLevel);
    Base::ClearChangesMask(PetSpellPower);
    Base::ClearChangesMask(UiHitModifier);
    Base::ClearChangesMask(UiSpellHitModifier);
    Base::ClearChangesMask(HomeRealmTimeOffset);
    Base::ClearChangesMask(ModPetHaste);
    Base::ClearChangesMask(LocalRegenFlags);
    Base::ClearChangesMask(AuraVision);
    Base::ClearChangesMask(NumBackpackSlots);
    Base::ClearChangesMask(OverrideSpellsID);
    Base::ClearChangesMask(LfgBonusFactionID);
    Base::ClearChangesMask(LootSpecID);
    Base::ClearChangesMask(OverrideZonePVPType);
    Base::ClearChangesMask(Honor);
    Base::ClearChangesMask(HonorNextLevel);
    Base::ClearChangesMask(PvpRewardAchieved);
    Base::ClearChangesMask(PvpTierMaxFromWins);
    Base::ClearChangesMask(PvpLastWeeksRewardAchieved);
    Base::ClearChangesMask(PvpLastWeeksTierMaxFromWins);
    Base::ClearChangesMask(PvpLastWeeksRewardClaimed);
    Base::ClearChangesMask(NumBankSlots);
    Base::ClearChangesMask(QuestSession);
    Base::ClearChangesMask(InvSlots);
    Base::ClearChangesMask(TrackResourceMask);
    Base::ClearChangesMask(ExploredZones);
    Base::ClearChangesMask(RestInfo);
    Base::ClearChangesMask(ModDamageDonePos);
    Base::ClearChangesMask(ModDamageDoneNeg);
    Base::ClearChangesMask(ModDamageDonePercent);
    Base::ClearChangesMask(WeaponDmgMultipliers);
    Base::ClearChangesMask(WeaponAtkSpeedMultipliers);
    Base::ClearChangesMask(BuybackPrice);
    Base::ClearChangesMask(BuybackTimestamp);
    Base::ClearChangesMask(CombatRatings);
    Base::ClearChangesMask(PvpInfo);
    Base::ClearChangesMask(NoReagentCostMask);
    Base::ClearChangesMask(ProfessionSkillLine);
    Base::ClearChangesMask(BagSlotFlags);
    Base::ClearChangesMask(BankBagSlotFlags);
    Base::ClearChangesMask(QuestCompleted);
    _changesMask.ResetAll();
}

void GameObjectData::WriteCreate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, GameObject const* owner, Player const* receiver) const
{
    data << int32(DisplayID);
    data << uint32(SpellVisualID);
    data << uint32(StateSpellVisualID);
    data << uint32(SpawnTrackingStateAnimID);
    data << uint32(SpawnTrackingStateAnimKitID);
    data << uint32(StateWorldEffectIDs->size());
    data << uint32(StateWorldEffectsQuestObjectiveID);
    for (std::size_t i = 0; i < StateWorldEffectIDs->size(); ++i)
    {
        data << uint32((*StateWorldEffectIDs)[i]);
    }
    data << CreatedBy;
    data << GuildGUID;
    data << uint32(ViewerDependentValue<FlagsTag>::GetValue(Flags, owner, receiver));
    data << float(ParentRotation->x);
    data << float(ParentRotation->y);
    data << float(ParentRotation->z);
    data << float(ParentRotation->w);
    data << int32(FactionTemplate);
    data << int32(ViewerDependentValue<LevelTag>::GetValue(Level, owner, receiver));
    data << int8(ViewerDependentValue<StateTag>::GetValue(State, owner, receiver));
    data << int8(TypeID);
    data << uint8(PercentHealth);
    data << uint32(ArtKit);
    data << uint32(EnableDoodadSets.size());
    data << uint32(CustomParam);
    for (std::size_t i = 0; i < EnableDoodadSets.size(); ++i)
    {
        data << int32(EnableDoodadSets[i]);
    }
}

void GameObjectData::WriteUpdate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, GameObject const* owner, Player const* receiver) const
{
    UpdateMask<20> const& changesMask = _changesMask;
    data.WriteBits(changesMask.GetBlock(0), 20);

    if (changesMask[0])
    {
        if (changesMask[1])
        {
            data.WriteBits(StateWorldEffectIDs->size(), 32);
            for (std::size_t i = 0; i < StateWorldEffectIDs->size(); ++i)
            {
                data << uint32((*StateWorldEffectIDs)[i]);
            }
        }
    }
    data.FlushBits();
    if (changesMask[0])
    {
        if (changesMask[2])
        {
            EnableDoodadSets.WriteUpdateMask(data);
        }
    }
    data.FlushBits();
    if (changesMask[0])
    {
        if (changesMask[2])
        {
            for (std::size_t i = 0; i < EnableDoodadSets.size(); ++i)
            {
                if (EnableDoodadSets.HasChanged(i))
                {
                    data << int32(EnableDoodadSets[i]);
                }
            }
        }
        if (changesMask[3])
        {
            data << int32(DisplayID);
        }
        if (changesMask[4])
        {
            data << uint32(SpellVisualID);
        }
        if (changesMask[5])
        {
            data << uint32(StateSpellVisualID);
        }
        if (changesMask[6])
        {
            data << uint32(SpawnTrackingStateAnimID);
        }
        if (changesMask[7])
        {
            data << uint32(SpawnTrackingStateAnimKitID);
        }
        if (changesMask[8])
        {
            data << uint32(StateWorldEffectsQuestObjectiveID);
        }
        if (changesMask[9])
        {
            data << CreatedBy;
        }
        if (changesMask[10])
        {
            data << GuildGUID;
        }
        if (changesMask[11])
        {
            data << uint32(ViewerDependentValue<FlagsTag>::GetValue(Flags, owner, receiver));
        }
        if (changesMask[12])
        {
            data << float(ParentRotation->x);
            data << float(ParentRotation->y);
            data << float(ParentRotation->z);
            data << float(ParentRotation->w);
        }
        if (changesMask[13])
        {
            data << int32(FactionTemplate);
        }
        if (changesMask[14])
        {
            data << int32(ViewerDependentValue<LevelTag>::GetValue(Level, owner, receiver));
        }
        if (changesMask[15])
        {
            data << int8(ViewerDependentValue<StateTag>::GetValue(State, owner, receiver));
        }
        if (changesMask[16])
        {
            data << int8(TypeID);
        }
        if (changesMask[17])
        {
            data << uint8(PercentHealth);
        }
        if (changesMask[18])
        {
            data << uint32(ArtKit);
        }
        if (changesMask[19])
        {
            data << uint32(CustomParam);
        }
    }
}

void GameObjectData::ClearChangesMask()
{
    Base::ClearChangesMask(StateWorldEffectIDs);
    Base::ClearChangesMask(EnableDoodadSets);
    Base::ClearChangesMask(DisplayID);
    Base::ClearChangesMask(SpellVisualID);
    Base::ClearChangesMask(StateSpellVisualID);
    Base::ClearChangesMask(SpawnTrackingStateAnimID);
    Base::ClearChangesMask(SpawnTrackingStateAnimKitID);
    Base::ClearChangesMask(StateWorldEffectsQuestObjectiveID);
    Base::ClearChangesMask(CreatedBy);
    Base::ClearChangesMask(GuildGUID);
    Base::ClearChangesMask(Flags);
    Base::ClearChangesMask(ParentRotation);
    Base::ClearChangesMask(FactionTemplate);
    Base::ClearChangesMask(Level);
    Base::ClearChangesMask(State);
    Base::ClearChangesMask(TypeID);
    Base::ClearChangesMask(PercentHealth);
    Base::ClearChangesMask(ArtKit);
    Base::ClearChangesMask(CustomParam);
    _changesMask.ResetAll();
}

void DynamicObjectData::WriteCreate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, DynamicObject const* owner, Player const* receiver) const
{
    data << Caster;
    data << int32(SpellXSpellVisualID);
    data << int32(SpellID);
    data << float(Radius);
    data << uint32(CastTime);
    data << uint8(Type);
}

void DynamicObjectData::WriteUpdate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, DynamicObject const* owner, Player const* receiver) const
{
    UpdateMask<7> const& changesMask = _changesMask;
    data.WriteBits(changesMask.GetBlock(0), 7);

    data.FlushBits();
    if (changesMask[0])
    {
        if (changesMask[1])
        {
            data << Caster;
        }
        if (changesMask[2])
        {
            data << int32(SpellXSpellVisualID);
        }
        if (changesMask[3])
        {
            data << int32(SpellID);
        }
        if (changesMask[4])
        {
            data << float(Radius);
        }
        if (changesMask[5])
        {
            data << uint32(CastTime);
        }
        if (changesMask[6])
        {
            data << uint8(Type);
        }
    }
}

void DynamicObjectData::ClearChangesMask()
{
    Base::ClearChangesMask(Caster);
    Base::ClearChangesMask(SpellXSpellVisualID);
    Base::ClearChangesMask(SpellID);
    Base::ClearChangesMask(Radius);
    Base::ClearChangesMask(CastTime);
    Base::ClearChangesMask(Type);
    _changesMask.ResetAll();
}

void CorpseData::WriteCreate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Corpse const* owner, Player const* receiver) const
{
    data << uint32(DynamicFlags);
    data << Owner;
    data << PartyGUID;
    data << GuildGUID;
    data << uint32(DisplayID);
    for (std::size_t i = 0; i < 19; ++i)
    {
        data << uint32(Items[i]);
    }
    data << uint8(Unused);
    data << uint8(RaceID);
    data << uint8(Sex);
    data << uint8(SkinID);
    data << uint8(FaceID);
    data << uint8(HairStyleID);
    data << uint8(HairColorID);
    data << uint8(FacialHairStyleID);
    data << uint32(Flags);
    data << int32(FactionTemplate);
    for (std::size_t i = 0; i < 3; ++i)
    {
        data << uint8(CustomDisplayOption[i]);
    }
}

void CorpseData::WriteUpdate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Corpse const* owner, Player const* receiver) const
{
    UpdateMask<40> const& changesMask = _changesMask;
    data.WriteBits(changesMask.GetBlocksMask(0), 2);
    for (std::size_t i = 0; i < 2; ++i)
        if (changesMask.GetBlock(i))
            data.WriteBits(changesMask.GetBlock(i), 32);

    data.FlushBits();
    if (changesMask[0])
    {
        if (changesMask[1])
        {
            data << uint32(DynamicFlags);
        }
        if (changesMask[2])
        {
            data << Owner;
        }
        if (changesMask[3])
        {
            data << PartyGUID;
        }
        if (changesMask[4])
        {
            data << GuildGUID;
        }
        if (changesMask[5])
        {
            data << uint32(DisplayID);
        }
        if (changesMask[6])
        {
            data << uint8(Unused);
        }
        if (changesMask[7])
        {
            data << uint8(RaceID);
        }
        if (changesMask[8])
        {
            data << uint8(Sex);
        }
        if (changesMask[9])
        {
            data << uint8(SkinID);
        }
        if (changesMask[10])
        {
            data << uint8(FaceID);
        }
        if (changesMask[11])
        {
            data << uint8(HairStyleID);
        }
        if (changesMask[12])
        {
            data << uint8(HairColorID);
        }
        if (changesMask[13])
        {
            data << uint8(FacialHairStyleID);
        }
        if (changesMask[14])
        {
            data << uint32(Flags);
        }
        if (changesMask[15])
        {
            data << int32(FactionTemplate);
        }
    }
    if (changesMask[16])
    {
        for (std::size_t i = 0; i < 19; ++i)
        {
            if (changesMask[17 + i])
            {
                data << uint32(Items[i]);
            }
        }
    }
    if (changesMask[36])
    {
        for (std::size_t i = 0; i < 3; ++i)
        {
            if (changesMask[37 + i])
            {
                data << uint8(CustomDisplayOption[i]);
            }
        }
    }
}

void CorpseData::ClearChangesMask()
{
    Base::ClearChangesMask(DynamicFlags);
    Base::ClearChangesMask(Owner);
    Base::ClearChangesMask(PartyGUID);
    Base::ClearChangesMask(GuildGUID);
    Base::ClearChangesMask(DisplayID);
    Base::ClearChangesMask(Unused);
    Base::ClearChangesMask(RaceID);
    Base::ClearChangesMask(Sex);
    Base::ClearChangesMask(SkinID);
    Base::ClearChangesMask(FaceID);
    Base::ClearChangesMask(HairStyleID);
    Base::ClearChangesMask(HairColorID);
    Base::ClearChangesMask(FacialHairStyleID);
    Base::ClearChangesMask(Flags);
    Base::ClearChangesMask(FactionTemplate);
    Base::ClearChangesMask(Items);
    Base::ClearChangesMask(CustomDisplayOption);
    _changesMask.ResetAll();
}

void ScaleCurve::WriteCreate(ByteBuffer& data, AreaTrigger const* owner, Player const* receiver) const
{
    data << uint32(StartTimeOffset);
    for (std::size_t i = 0; i < 2; ++i)
    {
        data << Points[i];
    }
    data << uint32(ParameterCurve);
    data.WriteBit(OverrideActive);
    data.FlushBits();
}

void ScaleCurve::WriteUpdate(ByteBuffer& data, AreaTrigger const* owner, Player const* receiver) const
{
    UpdateMask<7> const& changesMask = _changesMask;
    data.WriteBits(changesMask.GetBlock(0), 7);

    if (changesMask[0])
    {
        if (changesMask[1])
        {
            data.WriteBit(OverrideActive);
        }
    }
    data.FlushBits();
    if (changesMask[0])
    {
        if (changesMask[2])
        {
            data << uint32(StartTimeOffset);
        }
        if (changesMask[3])
        {
            data << uint32(ParameterCurve);
        }
    }
    if (changesMask[4])
    {
        for (std::size_t i = 0; i < 2; ++i)
        {
            if (changesMask[5 + i])
            {
                data << Points[i];
            }
        }
    }
    data.FlushBits();
}

void ScaleCurve::ClearChangesMask()
{
    Base::ClearChangesMask(OverrideActive);
    Base::ClearChangesMask(StartTimeOffset);
    Base::ClearChangesMask(ParameterCurve);
    Base::ClearChangesMask(Points);
    _changesMask.ResetAll();
}

void AreaTriggerData::WriteCreate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, AreaTrigger const* owner, Player const* receiver) const
{
    OverrideScaleCurve->WriteCreate(data, owner, receiver);
    data << Caster;
    data << uint32(Duration);
    data << uint32(TimeToTarget);
    data << uint32(TimeToTargetScale);
    data << uint32(TimeToTargetExtraScale);
    data << int32(SpellID);
    data << int32(SpellForVisuals);
    data << int32(SpellXSpellVisualID);
    data << float(BoundsRadius2D);
    data << uint32(DecalPropertiesID);
    data << CreatingEffectGUID;
    ExtraScaleCurve->WriteCreate(data, owner, receiver);
}

void AreaTriggerData::WriteUpdate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, AreaTrigger const* owner, Player const* receiver) const
{
    UpdateMask<14> const& changesMask = _changesMask;
    data.WriteBits(changesMask.GetBlock(0), 14);

    data.FlushBits();
    if (changesMask[0])
    {
        if (changesMask[1])
        {
            OverrideScaleCurve->WriteUpdate(data, owner, receiver);
        }
        if (changesMask[3])
        {
            data << Caster;
        }
        if (changesMask[4])
        {
            data << uint32(Duration);
        }
        if (changesMask[5])
        {
            data << uint32(TimeToTarget);
        }
        if (changesMask[6])
        {
            data << uint32(TimeToTargetScale);
        }
        if (changesMask[7])
        {
            data << uint32(TimeToTargetExtraScale);
        }
        if (changesMask[8])
        {
            data << int32(SpellID);
        }
        if (changesMask[9])
        {
            data << int32(SpellForVisuals);
        }
        if (changesMask[10])
        {
            data << int32(SpellXSpellVisualID);
        }
        if (changesMask[11])
        {
            data << float(BoundsRadius2D);
        }
        if (changesMask[12])
        {
            data << uint32(DecalPropertiesID);
        }
        if (changesMask[13])
        {
            data << CreatingEffectGUID;
        }
        if (changesMask[2])
        {
            ExtraScaleCurve->WriteUpdate(data, owner, receiver);
        }
    }
}

void AreaTriggerData::ClearChangesMask()
{
    Base::ClearChangesMask(OverrideScaleCurve);
    Base::ClearChangesMask(ExtraScaleCurve);
    Base::ClearChangesMask(Caster);
    Base::ClearChangesMask(Duration);
    Base::ClearChangesMask(TimeToTarget);
    Base::ClearChangesMask(TimeToTargetScale);
    Base::ClearChangesMask(TimeToTargetExtraScale);
    Base::ClearChangesMask(SpellID);
    Base::ClearChangesMask(SpellForVisuals);
    Base::ClearChangesMask(SpellXSpellVisualID);
    Base::ClearChangesMask(BoundsRadius2D);
    Base::ClearChangesMask(DecalPropertiesID);
    Base::ClearChangesMask(CreatingEffectGUID);
    _changesMask.ResetAll();
}

void SceneObjectData::WriteCreate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Object const* owner, Player const* receiver) const
{
    data << int32(ScriptPackageID);
    data << uint32(RndSeedVal);
    data << CreatedBy;
    data << uint32(SceneType);
}

void SceneObjectData::WriteUpdate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Object const* owner, Player const* receiver) const
{
    UpdateMask<5> const& changesMask = _changesMask;
    data.WriteBits(changesMask.GetBlock(0), 5);

    data.FlushBits();
    if (changesMask[0])
    {
        if (changesMask[1])
        {
            data << int32(ScriptPackageID);
        }
        if (changesMask[2])
        {
            data << uint32(RndSeedVal);
        }
        if (changesMask[3])
        {
            data << CreatedBy;
        }
        if (changesMask[4])
        {
            data << uint32(SceneType);
        }
    }
}

void SceneObjectData::ClearChangesMask()
{
    Base::ClearChangesMask(ScriptPackageID);
    Base::ClearChangesMask(RndSeedVal);
    Base::ClearChangesMask(CreatedBy);
    Base::ClearChangesMask(SceneType);
    _changesMask.ResetAll();
}

void ConversationLine::WriteCreate(ByteBuffer& data, Conversation const* owner, Player const* receiver) const
{
    data << int32(ConversationLineID);
    data << uint32(StartTime);
    data << int32(UiCameraID);
    data << uint8(ActorIndex);
    data << uint8(Flags);
}

void ConversationLine::WriteUpdate(ByteBuffer& data, Conversation const* owner, Player const* receiver) const
{
    data << int32(ConversationLineID);
    data << uint32(StartTime);
    data << int32(UiCameraID);
    data << uint8(ActorIndex);
    data << uint8(Flags);
}

void ConversationActor::WriteCreate(ByteBuffer& data, Conversation const* owner, Player const* receiver) const
{
    data << uint32(CreatureID);
    data << uint32(CreatureDisplayInfoID);
    data << ActorGUID;
    data << int32(Field_18);
    data.WriteBits(Type, 1);
    data.FlushBits();
}

void ConversationActor::WriteUpdate(ByteBuffer& data, Conversation const* owner, Player const* receiver) const
{
    data << uint32(CreatureID);
    data << uint32(CreatureDisplayInfoID);
    data << ActorGUID;
    data << int32(Field_18);
    data.WriteBits(Type, 1);
    data.FlushBits();
}

void ConversationData::WriteCreate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Conversation const* owner, Player const* receiver) const
{
    data << uint32(Lines->size());
    data << int32(LastLineEndTime);
    data << uint32(Field_1C);
    for (std::size_t i = 0; i < Lines->size(); ++i)
    {
        (*Lines)[i].WriteCreate(data, owner, receiver);
    }
    data << uint32(Actors.size());
    for (std::size_t i = 0; i < Actors.size(); ++i)
    {
        Actors[i].WriteCreate(data, owner, receiver);
    }
}

void ConversationData::WriteUpdate(ByteBuffer& data, EnumClassFlag<UpdateFieldFlag> fieldVisibilityFlags, Conversation const* owner, Player const* receiver) const
{
    UpdateMask<5> const& changesMask = _changesMask;
    data.WriteBits(changesMask.GetBlock(0), 5);

    if (changesMask[0])
    {
        if (changesMask[1])
        {
            data.WriteBits(Lines->size(), 32);
            for (std::size_t i = 0; i < Lines->size(); ++i)
            {
                (*Lines)[i].WriteUpdate(data, owner, receiver);
            }
        }
    }
    data.FlushBits();
    if (changesMask[0])
    {
        if (changesMask[2])
        {
            Actors.WriteUpdateMask(data);
        }
    }
    data.FlushBits();
    if (changesMask[0])
    {
        if (changesMask[2])
        {
            for (std::size_t i = 0; i < Actors.size(); ++i)
            {
                if (Actors.HasChanged(i))
                {
                    Actors[i].WriteUpdate(data, owner, receiver);
                }
            }
        }
        if (changesMask[3])
        {
            data << int32(LastLineEndTime);
        }
        if (changesMask[4])
        {
            data << uint32(Field_1C);
        }
    }
}

void ConversationData::ClearChangesMask()
{
    Base::ClearChangesMask(Lines);
    Base::ClearChangesMask(Actors);
    Base::ClearChangesMask(LastLineEndTime);
    Base::ClearChangesMask(Field_1C);
    _changesMask.ResetAll();
}

}

#if TRINITY_COMPILER == TRINITY_COMPILER_GNU
#pragma GCC diagnostic pop
#else
#pragma warning(pop)
#endif
