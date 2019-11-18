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

#include "AzeriteItem.h"
#include "AzeritePackets.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "GameTime.h"
#include "Player.h"
#include <boost/date_time/gregorian/gregorian_types.hpp>
#include <boost/date_time/posix_time/conversion.hpp>

AzeriteItem::AzeriteItem() : Item()
{
    m_objectType |= TYPEMASK_AZERITE_ITEM;
    m_objectTypeId = TYPEID_AZERITE_ITEM;

    SetUpdateFieldValue(m_values.ModifyValue(&AzeriteItem::m_azeriteItemData).ModifyValue(&UF::AzeriteItemData::DEBUGknowledgeWeek), -1);
}

bool AzeriteItem::Create(ObjectGuid::LowType guidlow, uint32 itemId, Player const* owner)
{
    if (!Item::Create(guidlow, itemId, owner))
        return false;

    SetUpdateFieldValue(m_values.ModifyValue(&AzeriteItem::m_azeriteItemData).ModifyValue(&UF::AzeriteItemData::Level), 1);
    SetUpdateFieldValue(m_values.ModifyValue(&AzeriteItem::m_azeriteItemData).ModifyValue(&UF::AzeriteItemData::KnowledgeLevel), GetCurrentKnowledgeLevel());
    return true;
}

void AzeriteItem::SaveToDB(CharacterDatabaseTransaction& trans)
{
    Item::SaveToDB(trans);

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEM_INSTANCE_AZERITE);
    stmt->setUInt64(0, GetGUID().GetCounter());
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_ITEM_INSTANCE_AZERITE);
    stmt->setUInt64(0, GetGUID().GetCounter());
    stmt->setUInt64(1, m_azeriteItemData->Xp);
    stmt->setUInt32(2, m_azeriteItemData->Level);
    stmt->setUInt32(3, m_azeriteItemData->KnowledgeLevel);
    trans->Append(stmt);
}

bool AzeriteItem::LoadFromDB(ObjectGuid::LowType guid, ObjectGuid ownerGuid, Field* fields, uint32 entry)
{
    if (!Item::LoadFromDB(guid, ownerGuid, fields, entry))
        return false;

    bool needSave = false;

    uint64 xp = fields[43].GetUInt64();
    uint32 level = fields[44].GetUInt32();
    uint32 knowledgeLevel = fields[45].GetUInt32();

    if (!sAzeriteLevelInfoStore.LookupEntry(level))
    {
        xp = 0;
        level = 1;
        knowledgeLevel = GetCurrentKnowledgeLevel();
        needSave = true;
    }
    else if (level > MAX_AZERITE_ITEM_LEVEL)
    {
        xp = 0;
        level = MAX_AZERITE_ITEM_LEVEL;
        needSave = true;
    }

    if (knowledgeLevel != GetCurrentKnowledgeLevel())
    {
        // rescale XP to maintain same progress %
        uint64 oldMax = CalcTotalXPToNextLevel(level, knowledgeLevel);
        knowledgeLevel = GetCurrentKnowledgeLevel();
        uint64 newMax = CalcTotalXPToNextLevel(level, knowledgeLevel);
        xp = uint64(xp / double(oldMax) * newMax);
        needSave = true;
    }
    else if (knowledgeLevel > MAX_AZERITE_ITEM_KNOWLEDGE_LEVEL)
    {
        knowledgeLevel = MAX_AZERITE_ITEM_KNOWLEDGE_LEVEL;
        needSave = true;
    }

    SetUpdateFieldValue(m_values.ModifyValue(&AzeriteItem::m_azeriteItemData).ModifyValue(&UF::AzeriteItemData::Xp), xp);
    SetUpdateFieldValue(m_values.ModifyValue(&AzeriteItem::m_azeriteItemData).ModifyValue(&UF::AzeriteItemData::Level), level);
    SetUpdateFieldValue(m_values.ModifyValue(&AzeriteItem::m_azeriteItemData).ModifyValue(&UF::AzeriteItemData::KnowledgeLevel), knowledgeLevel);

    if (needSave)
    {
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ITEM_INSTANCE_AZERITE_ON_LOAD);
        stmt->setUInt64(0, xp);
        stmt->setUInt32(1, knowledgeLevel);
        stmt->setUInt64(2, guid);
        CharacterDatabase.Execute(stmt);
    }

    return true;
}

void AzeriteItem::DeleteFromDB(CharacterDatabaseTransaction& trans)
{
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEM_INSTANCE_AZERITE);
    stmt->setUInt64(0, GetGUID().GetCounter());
    trans->Append(stmt);

    Item::DeleteFromDB(trans);
}

uint32 AzeriteItem::GetItemLevel(Player const* /*owner*/) const
{
    return sAzeriteLevelInfoStore.AssertEntry(m_azeriteItemData->Level)->ItemLevel;
}

uint32 AzeriteItem::GetCurrentKnowledgeLevel()
{
    // count weeks from 26.06.2019
    boost::gregorian::date now = boost::posix_time::from_time_t(GameTime::GetGameTime()).date();
    boost::gregorian::week_iterator itr(boost::gregorian::date(2019, boost::date_time::Jun, 26));
    uint32 knowledge = 0;
    while (*itr < now && knowledge < MAX_AZERITE_ITEM_KNOWLEDGE_LEVEL)
    {
        ++knowledge;
        ++itr;
    }
    return knowledge;
}

uint64 AzeriteItem::CalcTotalXPToNextLevel(uint32 level, uint32 knowledgeLevel)
{
    AzeriteLevelInfoEntry const* levelInfo = sAzeriteLevelInfoStore.AssertEntry(level);
    uint64 totalXp = levelInfo->BaseExperienceToNextLevel * sAzeriteKnowledgeMultiplierStore.AssertEntry(knowledgeLevel)->Multiplier;
    return std::max(totalXp, levelInfo->MinimumExperienceToNextLevel);
}

void AzeriteItem::GiveXP(uint64 xp)
{
    Player* owner = GetOwner();
    uint32 level = m_azeriteItemData->Level;
    if (level < MAX_AZERITE_ITEM_LEVEL)
    {
        uint64 currentXP = m_azeriteItemData->Xp;
        uint64 remainingXP = xp;
        do
        {
            uint64 totalXp = CalcTotalXPToNextLevel(level, m_azeriteItemData->KnowledgeLevel);
            if (currentXP + remainingXP >= totalXp)
            {
                // advance to next level
                ++level;
                remainingXP -= totalXp - currentXP;
                currentXP = 0;
            }
            else
            {
                currentXP += remainingXP;
                remainingXP = 0;
            }
        } while (remainingXP > 0 && level < MAX_AZERITE_ITEM_LEVEL);

        SetUpdateFieldValue(m_values.ModifyValue(&AzeriteItem::m_azeriteItemData).ModifyValue(&UF::AzeriteItemData::Xp), currentXP);

        owner->UpdateCriteria(CRITERIA_TYPE_HEART_OF_AZEROTH_ARTIFACT_POWER_EARNED, xp);

        // changing azerite level changes item level, need to update stats
        if (m_azeriteItemData->Level != level)
        {
            if (IsEquipped())
                owner->_ApplyItemBonuses(this, GetSlot(), false);

            SetUpdateFieldValue(m_values.ModifyValue(&AzeriteItem::m_azeriteItemData).ModifyValue(&UF::AzeriteItemData::Level), level);
            owner->UpdateCriteria(CRITERIA_TYPE_HEART_OF_AZEROTH_LEVEL_REACHED, level);

            if (IsEquipped())
                owner->_ApplyItemBonuses(this, GetSlot(), true);
        }

        SetState(ITEM_CHANGED, owner);
    }

    WorldPackets::Azerite::AzeriteXpGain xpGain;
    xpGain.ItemGUID = GetGUID();
    xpGain.XP = xp;
    owner->SendDirectMessage(xpGain.Write());
}

UF::SelectedAzeriteEssences const* AzeriteItem::GetSelectedAzeriteEssences() const
{
    for (UF::SelectedAzeriteEssences const& essences : m_azeriteItemData->SelectedEssences)
        if (essences.Enabled)
            return &essences;

    return nullptr;
}

void AzeriteItem::BuildValuesCreate(ByteBuffer* data, Player const* target) const
{
    UF::UpdateFieldFlag flags = GetUpdateFieldFlagsFor(target);
    std::size_t sizePos = data->wpos();
    *data << uint32(0);
    *data << uint8(flags);
    m_objectData->WriteCreate(*data, flags, this, target);
    m_itemData->WriteCreate(*data, flags, this, target);
    m_azeriteItemData->WriteCreate(*data, flags, this, target);
    data->put<uint32>(sizePos, data->wpos() - sizePos - 4);
}

void AzeriteItem::BuildValuesUpdate(ByteBuffer* data, Player const* target) const
{
    UF::UpdateFieldFlag flags = GetUpdateFieldFlagsFor(target);
    std::size_t sizePos = data->wpos();
    *data << uint32(0);
    *data << uint32(m_values.GetChangedObjectTypeMask());

    if (m_values.HasChanged(TYPEID_OBJECT))
        m_objectData->WriteUpdate(*data, flags, this, target);

    if (m_values.HasChanged(TYPEID_ITEM))
        m_itemData->WriteUpdate(*data, flags, this, target);

    if (m_values.HasChanged(TYPEID_AZERITE_ITEM))
        m_azeriteItemData->WriteUpdate(*data, flags, this, target);

    data->put<uint32>(sizePos, data->wpos() - sizePos - 4);
}

void AzeriteItem::BuildValuesUpdateWithFlag(ByteBuffer* data, UF::UpdateFieldFlag flags, Player const* target) const
{
    UpdateMask<NUM_CLIENT_OBJECT_TYPES> valuesMask;
    valuesMask.Set(TYPEID_ITEM);
    valuesMask.Set(TYPEID_AZERITE_ITEM);

    std::size_t sizePos = data->wpos();
    *data << uint32(0);
    *data << uint32(valuesMask.GetBlock(0));

    UF::ItemData::Mask mask;
    m_itemData->AppendAllowedFieldsMaskForFlag(mask, flags);
    m_itemData->WriteUpdate(*data, mask, flags, this, target);

    UF::AzeriteItemData::Mask mask2;
    m_azeriteItemData->AppendAllowedFieldsMaskForFlag(mask2, flags);
    m_azeriteItemData->WriteUpdate(*data, mask2, flags, this, target);

    data->put<uint32>(sizePos, data->wpos() - sizePos - 4);
}

void AzeriteItem::ClearUpdateMask(bool remove)
{
    m_values.ClearChangesMask(&AzeriteItem::m_azeriteItemData);
    Item::ClearUpdateMask(remove);
}
