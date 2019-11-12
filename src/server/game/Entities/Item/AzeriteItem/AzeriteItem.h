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

#ifndef AzeriteItem_h__
#define AzeriteItem_h__

#include "Item.h"

constexpr uint32 ITEM_ID_HEART_OF_AZEROTH = 158075;
constexpr uint32 MAX_AZERITE_ITEM_LEVEL = 70;
constexpr uint32 MAX_AZERITE_ITEM_KNOWLEDGE_LEVEL = 30;

class TC_GAME_API AzeriteItem : public Item
{
public:
    AzeriteItem();

    bool Create(ObjectGuid::LowType guidlow, uint32 itemId, Player const* owner) override;

    void SaveToDB(CharacterDatabaseTransaction& trans) override;
    bool LoadFromDB(ObjectGuid::LowType guid, ObjectGuid ownerGuid, Field* fields, uint32 entry) override;
    void DeleteFromDB(CharacterDatabaseTransaction& trans) override;

    uint32 GetItemLevel(Player const* owner) const override;

    static uint32 GetCurrentKnowledgeLevel();
    static uint64 CalcTotalXPToNextLevel(uint32 level, uint32 knowledgeLevel);
    void GiveXP(uint64 xp);

    void BuildValuesCreate(ByteBuffer* data, Player const* target) const override;
    void BuildValuesUpdate(ByteBuffer* data, Player const* target) const override;
    void BuildValuesUpdateWithFlag(ByteBuffer* data, UF::UpdateFieldFlag flags, Player const* target) const override;
    void ClearUpdateMask(bool remove) override;

    UF::UpdateField<UF::AzeriteItemData, 0, TYPEID_AZERITE_ITEM> m_azeriteItemData;
};

#endif // AzeriteItem_h__
