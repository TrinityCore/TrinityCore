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

#include "AzeriteEmpoweredItem.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "Player.h"
#include "UpdateData.h"

AzeriteEmpoweredItem::AzeriteEmpoweredItem()
{
    m_objectType |= TYPEMASK_AZERITE_EMPOWERED_ITEM;
    m_objectTypeId = TYPEID_AZERITE_EMPOWERED_ITEM;

    m_azeritePowers = nullptr;
    m_maxTier = 0;
}

bool AzeriteEmpoweredItem::Create(ObjectGuid::LowType guidlow, uint32 itemId, ItemContext context, Player const* owner)
{
    if (!Item::Create(guidlow, itemId, context, owner))
        return false;

    InitAzeritePowerData();
    return true;
}

void AzeriteEmpoweredItem::SaveToDB(CharacterDatabaseTransaction& trans)
{
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEM_INSTANCE_AZERITE_EMPOWERED);
    stmt->setUInt64(0, GetGUID().GetCounter());
    trans->Append(stmt);

    switch (GetState())
    {
        case ITEM_NEW:
        case ITEM_CHANGED:
        {
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_ITEM_INSTANCE_AZERITE_EMPOWERED);
            stmt->setUInt64(0, GetGUID().GetCounter());
            for (uint32 i = 0; i < MAX_AZERITE_EMPOWERED_TIER; ++i)
                stmt->setInt32(1 + i, m_azeriteEmpoweredItemData->Selections[i]);

            trans->Append(stmt);
            break;
        }
        case ITEM_REMOVED:
        default:
            break;
    }

    Item::SaveToDB(trans);
}

void AzeriteEmpoweredItem::LoadAzeriteEmpoweredItemData(Player const* owner, AzeriteEmpoweredItemData& azeriteEmpoweredItem)
{
    InitAzeritePowerData();
    bool needSave = false;
    if (m_azeritePowers)
    {
        for (int32 i = MAX_AZERITE_EMPOWERED_TIER; --i >= 0; )
        {
            int32 selection = azeriteEmpoweredItem.SelectedAzeritePowers[i];
            if (GetTierForAzeritePower(Classes(owner->getClass()), selection) != i)
            {
                needSave = true;
                break;
            }

            SetSelectedAzeritePower(i, selection);
        }
    }
    else
        needSave = true;

    if (needSave)
    {
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ITEM_INSTANCE_AZERITE_EMPOWERED);
        for (uint32 i = 0; i < MAX_AZERITE_EMPOWERED_TIER; ++i)
            stmt->setInt32(i, m_azeriteEmpoweredItemData->Selections[i]);

        stmt->setUInt64(5, GetGUID().GetCounter());
        CharacterDatabase.Execute(stmt);
    }
}

void AzeriteEmpoweredItem::DeleteFromDB(CharacterDatabaseTransaction& trans, ObjectGuid::LowType itemGuid)
{
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEM_INSTANCE_AZERITE_EMPOWERED);
    stmt->setUInt64(0, itemGuid);
    CharacterDatabase.ExecuteOrAppend(trans, stmt);
}

void AzeriteEmpoweredItem::DeleteFromDB(CharacterDatabaseTransaction& trans)
{
    AzeriteEmpoweredItem::DeleteFromDB(trans, GetGUID().GetCounter());
    Item::DeleteFromDB(trans);
}

uint32 AzeriteEmpoweredItem::GetRequiredAzeriteLevelForTier(uint32 tier) const
{
    return sDB2Manager.GetRequiredAzeriteLevelForAzeritePowerTier(_bonusData.AzeriteTierUnlockSetId, GetContext(), tier);
}

int32 AzeriteEmpoweredItem::GetTierForAzeritePower(Classes playerClass, int32 azeritePowerId) const
{
    auto azeritePowerItr = std::find_if(m_azeritePowers->begin(), m_azeritePowers->end(), [&](AzeritePowerSetMemberEntry const* power)
    {
        return power->AzeritePowerID == azeritePowerId && power->Class == playerClass;
    });
    if (azeritePowerItr != m_azeritePowers->end())
        return (*azeritePowerItr)->Tier;

    return MAX_AZERITE_EMPOWERED_TIER;
}

void AzeriteEmpoweredItem::SetSelectedAzeritePower(int32 tier, int32 azeritePowerId)
{
    SetUpdateFieldValue(m_values.ModifyValue(&AzeriteEmpoweredItem::m_azeriteEmpoweredItemData).ModifyValue(&UF::AzeriteEmpoweredItemData::Selections, uint32(tier)), azeritePowerId);

    // Not added to UF::ItemData::BonusListIDs, client fakes it on its own too
    _bonusData.AddBonusList(sAzeritePowerStore.AssertEntry(azeritePowerId)->ItemBonusListID);
}

void AzeriteEmpoweredItem::ClearSelectedAzeritePowers()
{
    for (uint32 i = 0; i < MAX_AZERITE_EMPOWERED_TIER; ++i)
        SetUpdateFieldValue(m_values.ModifyValue(&AzeriteEmpoweredItem::m_azeriteEmpoweredItemData).ModifyValue(&UF::AzeriteEmpoweredItemData::Selections, i), 0);

    _bonusData.Initialize(GetTemplate());
    for (int32 bonusListID : *m_itemData->BonusListIDs)
        _bonusData.AddBonusList(bonusListID);
}

int64 AzeriteEmpoweredItem::GetRespecCost() const
{
    if (Player const* owner = GetOwner())
        return int64(GOLD * sDB2Manager.GetCurveValueAt(CURVE_ID_AZERITE_EMPOWERED_ITEM_RESPEC_COST, float(owner->GetNumRespecs())));

    return MAX_MONEY_AMOUNT + 1;
}

void AzeriteEmpoweredItem::BuildValuesCreate(ByteBuffer* data, Player const* target) const
{
    UF::UpdateFieldFlag flags = GetUpdateFieldFlagsFor(target);
    std::size_t sizePos = data->wpos();
    *data << uint32(0);
    *data << uint8(flags);
    m_objectData->WriteCreate(*data, flags, this, target);
    m_itemData->WriteCreate(*data, flags, this, target);
    m_azeriteEmpoweredItemData->WriteCreate(*data, flags, this, target);
    data->put<uint32>(sizePos, data->wpos() - sizePos - 4);
}

void AzeriteEmpoweredItem::BuildValuesUpdate(ByteBuffer* data, Player const* target) const
{
    UF::UpdateFieldFlag flags = GetUpdateFieldFlagsFor(target);
    std::size_t sizePos = data->wpos();
    *data << uint32(0);
    *data << uint32(m_values.GetChangedObjectTypeMask());

    if (m_values.HasChanged(TYPEID_OBJECT))
        m_objectData->WriteUpdate(*data, flags, this, target);

    if (m_values.HasChanged(TYPEID_ITEM))
        m_itemData->WriteUpdate(*data, flags, this, target);

    if (m_values.HasChanged(TYPEID_AZERITE_EMPOWERED_ITEM))
        m_azeriteEmpoweredItemData->WriteUpdate(*data, flags, this, target);

    data->put<uint32>(sizePos, data->wpos() - sizePos - 4);
}

void AzeriteEmpoweredItem::BuildValuesUpdateForPlayerWithMask(UpdateData* data, UF::ObjectData::Mask const& requestedObjectMask,
    UF::ItemData::Mask const& requestedItemMask, UF::AzeriteEmpoweredItemData::Mask const& requestedAzeriteEmpoweredItemMask, Player const* target) const
{
    UF::UpdateFieldFlag flags = GetUpdateFieldFlagsFor(target);
    UpdateMask<NUM_CLIENT_OBJECT_TYPES> valuesMask;
    if (requestedObjectMask.IsAnySet())
        valuesMask.Set(TYPEID_OBJECT);

    UF::ItemData::Mask itemMask = requestedItemMask;
    m_itemData->FilterDisallowedFieldsMaskForFlag(itemMask, flags);
    if (itemMask.IsAnySet())
        valuesMask.Set(TYPEID_ITEM);

    if (requestedAzeriteEmpoweredItemMask.IsAnySet())
        valuesMask.Set(TYPEID_AZERITE_EMPOWERED_ITEM);

    ByteBuffer buffer = PrepareValuesUpdateBuffer();
    std::size_t sizePos = buffer.wpos();
    buffer << uint32(0);
    buffer << uint32(valuesMask.GetBlock(0));

    if (valuesMask[TYPEID_OBJECT])
        m_objectData->WriteUpdate(buffer, requestedObjectMask, true, this, target);

    if (valuesMask[TYPEID_ITEM])
        m_itemData->WriteUpdate(buffer, itemMask, true, this, target);

    if (valuesMask[TYPEID_AZERITE_EMPOWERED_ITEM])
        m_azeriteEmpoweredItemData->WriteUpdate(buffer, requestedAzeriteEmpoweredItemMask, true, this, target);

    buffer.put<uint32>(sizePos, buffer.wpos() - sizePos - 4);

    data->AddUpdateBlock(buffer);
}

void AzeriteEmpoweredItem::ClearUpdateMask(bool remove)
{
    m_values.ClearChangesMask(&AzeriteEmpoweredItem::m_azeriteEmpoweredItemData);
    Item::ClearUpdateMask(remove);
}

void AzeriteEmpoweredItem::InitAzeritePowerData()
{
    m_azeritePowers = sDB2Manager.GetAzeritePowers(GetEntry());
    if (m_azeritePowers)
    {
        m_maxTier = (*std::max_element(m_azeritePowers->begin(), m_azeritePowers->end(), [](AzeritePowerSetMemberEntry const* a1, AzeritePowerSetMemberEntry const* a2)
        {
            return a1->Tier < a2->Tier;
        }))->Tier;
    }
}
