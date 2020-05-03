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

#include "InspectPackets.h"
#include "AzeriteItem.h"
#include "Item.h"
#include "Player.h"

void WorldPackets::Inspect::Inspect::Read()
{
    _worldPacket >> Target;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Inspect::InspectEnchantData const& enchantData)
{
    data << uint32(enchantData.Id);
    data << uint8(enchantData.Index);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Inspect::AzeriteEssenceData const& azeriteEssenceData)
{
    data << uint32(azeriteEssenceData.Index);
    data << uint32(azeriteEssenceData.AzeriteEssenceID);
    data << uint32(azeriteEssenceData.Rank);
    data.WriteBit(azeriteEssenceData.SlotUnlocked);
    data.FlushBits();

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Inspect::InspectItemData const& itemData)
{
    data << itemData.CreatorGUID;
    data << uint8(itemData.Index);
    data << uint32(itemData.AzeritePowers.size());
    data << uint32(itemData.AzeriteEssences.size());

    if (!itemData.AzeritePowers.empty())
        data.append(itemData.AzeritePowers.data(), itemData.AzeritePowers.size());

    data << itemData.Item;
    data.WriteBit(itemData.Usable);
    data.WriteBits(itemData.Enchants.size(), 4);
    data.WriteBits(itemData.Gems.size(), 2);
    data.FlushBits();

    for (WorldPackets::Inspect::AzeriteEssenceData const& azeriteEssenceData : itemData.AzeriteEssences)
        data << azeriteEssenceData;

    for (WorldPackets::Inspect::InspectEnchantData const& enchantData : itemData.Enchants)
        data << enchantData;

    for (WorldPackets::Item::ItemGemData const& gem : itemData.Gems)
        data << gem;

    return data;
}

void WorldPackets::Inspect::PlayerModelDisplayInfo::Initialize(Player const* player)
{
    GUID = player->GetGUID();
    SpecializationID = player->GetPrimarySpecialization();
    Name = player->GetName();
    GenderID = player->m_playerData->NativeSex;
    Skin = player->m_playerData->SkinID;
    HairColor = player->m_playerData->HairColorID;
    HairStyle = player->m_playerData->HairStyleID;
    FacialHairStyle = player->m_playerData->FacialHairStyleID;
    Face = player->m_playerData->FaceID;
    Race = player->getRace();
    ClassID = player->getClass();
    std::copy(player->m_playerData->CustomDisplayOption.begin(), player->m_playerData->CustomDisplayOption.end(), CustomDisplay.begin());

    for (uint8 i = 0; i < EQUIPMENT_SLOT_END; ++i)
        if (::Item* item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            Items.emplace_back(item, i);
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Inspect::PlayerModelDisplayInfo const& displayInfo)
{
    data << displayInfo.GUID;
    data << int32(displayInfo.SpecializationID);
    data << uint32(displayInfo.Items.size());
    data.WriteBits(displayInfo.Name.length(), 6);
    data << uint8(displayInfo.GenderID);
    data << uint8(displayInfo.Skin);
    data << uint8(displayInfo.HairColor);
    data << uint8(displayInfo.HairStyle);
    data << uint8(displayInfo.FacialHairStyle);
    data << uint8(displayInfo.Face);
    data << uint8(displayInfo.Race);
    data << uint8(displayInfo.ClassID);
    data.append(displayInfo.CustomDisplay.data(), displayInfo.CustomDisplay.size());
    data.WriteString(displayInfo.Name);

    for (WorldPackets::Inspect::InspectItemData const& item : displayInfo.Items)
        data << item;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Inspect::InspectGuildData const& guildData)
{
    data << guildData.GuildGUID;
    data << int32(guildData.NumGuildMembers);
    data << int32(guildData.AchievementPoints);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Inspect::PVPBracketData const& bracket)
{
    data << uint8(bracket.Bracket);
    data << int32(bracket.Rating);
    data << int32(bracket.Rank);
    data << int32(bracket.WeeklyPlayed);
    data << int32(bracket.WeeklyWon);
    data << int32(bracket.SeasonPlayed);
    data << int32(bracket.SeasonWon);
    data << int32(bracket.WeeklyBestRating);
    data << int32(bracket.Unk710);
    data << int32(bracket.Unk801_1);
    data.WriteBit(bracket.Unk801_2);
    data.FlushBits();

    return data;
}

WorldPackets::Inspect::InspectItemData::InspectItemData(::Item const* item, uint8 index)
{
    CreatorGUID = item->GetCreator();

    Item.Initialize(item);
    Index = index;
    Usable = true; /// @todo

    for (uint8 i = 0; i < MAX_ENCHANTMENT_SLOT; ++i)
        if (uint32 enchId = item->GetEnchantmentId(EnchantmentSlot(i)))
            Enchants.emplace_back(enchId, i);

    uint8 i = 0;
    for (UF::SocketedGem const& gemData : item->m_itemData->Gems)
    {
        if (gemData.ItemID)
        {
            Gems.emplace_back();

            WorldPackets::Item::ItemGemData& gem = Gems.back();
            gem.Slot = i;
            gem.Item.Initialize(&gemData);
        }
        ++i;
    }

    if (AzeriteItem const* azeriteItem = item->ToAzeriteItem())
    {
        if (UF::SelectedAzeriteEssences const* essences = azeriteItem->GetSelectedAzeriteEssences())
        {
            for (uint8 slot = 0; slot < essences->AzeriteEssenceID.size(); ++slot)
            {
                AzeriteEssences.emplace_back();

                WorldPackets::Inspect::AzeriteEssenceData& essence = AzeriteEssences.back();
                essence.Index = slot;
                essence.AzeriteEssenceID = essences->AzeriteEssenceID[slot];
                if (essence.AzeriteEssenceID)
                {
                    essence.Rank = azeriteItem->GetEssenceRank(essence.AzeriteEssenceID);
                    essence.SlotUnlocked = true;
                }
                else
                    essence.SlotUnlocked = azeriteItem->HasUnlockedEssenceSlot(slot);
            }
        }
    }
}

WorldPacket const* WorldPackets::Inspect::InspectResult::Write()
{
    _worldPacket << DisplayInfo;
    _worldPacket << uint32(Glyphs.size());
    _worldPacket << uint32(Talents.size());
    _worldPacket << uint32(PvpTalents.size());
    _worldPacket << int32(ItemLevel);
    _worldPacket << uint8(LifetimeMaxRank);
    _worldPacket << uint16(TodayHK);
    _worldPacket << uint16(YesterdayHK);
    _worldPacket << uint32(LifetimeHK);
    _worldPacket << uint32(HonorLevel);
    if (!Glyphs.empty())
        _worldPacket.append(Glyphs.data(), Glyphs.size());
    if (!Talents.empty())
        _worldPacket.append(Talents.data(), Talents.size());
    if (!PvpTalents.empty())
        _worldPacket.append(PvpTalents.data(), PvpTalents.size());

    _worldPacket.WriteBit(GuildData.is_initialized());
    _worldPacket.WriteBit(AzeriteLevel.is_initialized());
    _worldPacket.FlushBits();

    for (PVPBracketData const& bracket : Bracket)
        _worldPacket << bracket;

    if (GuildData)
        _worldPacket << *GuildData;

    if (AzeriteLevel)
        _worldPacket << int32(*AzeriteLevel);

    return &_worldPacket;
}

void WorldPackets::Inspect::QueryInspectAchievements::Read()
{
    _worldPacket >> Guid;
}
