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

#ifndef AzeriteEmpoweredItem_h__
#define AzeriteEmpoweredItem_h__

#include "Item.h"

class TC_GAME_API AzeriteEmpoweredItem : public Item
{
public:
    AzeriteEmpoweredItem();

    bool Create(ObjectGuid::LowType guidlow, uint32 itemId, ItemContext context, Player const* owner) override;

    void SaveToDB(CharacterDatabaseTransaction& trans) override;
    void LoadAzeriteEmpoweredItemData(Player const* owner, AzeriteEmpoweredItemData& azeriteEmpoweredItem);
    static void DeleteFromDB(CharacterDatabaseTransaction& trans, ObjectGuid::LowType itemGuid);
    void DeleteFromDB(CharacterDatabaseTransaction& trans) override;

    uint32 GetRequiredAzeriteLevelForTier(uint32 tier) const;
    int32 GetTierForAzeritePower(Classes playerClass, int32 azeritePowerId) const;
    int32 GetMaxAzeritePowerTier() const { return m_maxTier; }

    uint32 GetSelectedAzeritePower(int32 tier) const { return uint32(m_azeriteEmpoweredItemData->Selections[uint32(tier)]); }
    void SetSelectedAzeritePower(int32 tier, int32 azeritePowerId);
    void ClearSelectedAzeritePowers();

    int64 GetRespecCost() const;

protected:
    void BuildValuesCreate(ByteBuffer* data, Player const* target) const override;
    void BuildValuesUpdate(ByteBuffer* data, Player const* target) const override;
    void ClearUpdateMask(bool remove) override;

public:
    void BuildValuesUpdateForPlayerWithMask(UpdateData* data, UF::ObjectData::Mask const& requestedObjectMask, UF::ItemData::Mask const& requestedItemMask,
        UF::AzeriteEmpoweredItemData::Mask const& requestedAzeriteEmpoweredItemMask, Player const* target) const;

    UF::UpdateField<UF::AzeriteEmpoweredItemData, 0, TYPEID_AZERITE_EMPOWERED_ITEM> m_azeriteEmpoweredItemData;

private:
    void InitAzeritePowerData();
    std::vector<AzeritePowerSetMemberEntry const*> const* m_azeritePowers;
    int32 m_maxTier;
};

#endif // AzeriteEmpoweredItem_h__
