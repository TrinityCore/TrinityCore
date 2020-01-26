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

#ifndef AzeriteItem_h__
#define AzeriteItem_h__

#include "Item.h"

constexpr uint32 ITEM_ID_HEART_OF_AZEROTH = 158075;
constexpr uint32 MAX_AZERITE_ITEM_LEVEL = 70;
constexpr uint32 MAX_AZERITE_ITEM_KNOWLEDGE_LEVEL = 30;
constexpr uint32 PLAYER_CONDITION_ID_UNLOCKED_AZERITE_ESSENCES = 69048;
constexpr uint32 SPELL_ID_HEART_ESSENCE_ACTION_BAR_OVERRIDE = 298554;

class TC_GAME_API AzeriteItem : public Item
{
public:
    AzeriteItem();

    bool Create(ObjectGuid::LowType guidlow, uint32 itemId, ItemContext context, Player const* owner) override;

    void SaveToDB(CharacterDatabaseTransaction& trans) override;
    void LoadAzeriteItemData(Player const* owner, AzeriteItemData& azeriteItem);
    static void DeleteFromDB(CharacterDatabaseTransaction& trans, ObjectGuid::LowType itemGuid);
    void DeleteFromDB(CharacterDatabaseTransaction& trans) override;

    uint32 GetLevel() const { return m_azeriteItemData->Level; }
    uint32 GetEffectiveLevel() const
    {
        uint32 level = m_azeriteItemData->AuraLevel;
        if (!level)
            level = m_azeriteItemData->Level;

        return level;
    }

    // Gaining artifact power
    static uint32 GetCurrentKnowledgeLevel();
    static uint64 CalcTotalXPToNextLevel(uint32 level, uint32 knowledgeLevel);
    void GiveXP(uint64 xp);

    // Essences
    // C_AzeriteEssence.CanOpenUI - checks PlayerCondition 69048 - HasAura(261912) || RewardedQuest(57010) || IsOnQuest(57010)
    static GameObject const* FindHeartForge(Player const* owner);
    bool CanUseEssences() const;
    bool HasUnlockedEssenceSlot(uint8 slot) const;
    bool HasUnlockedEssenceMilestone(uint32 azeriteItemMilestonePowerId) const { return m_azeriteItemData->UnlockedEssenceMilestones.FindIndex(azeriteItemMilestonePowerId) != -1; }
    void AddUnlockedEssenceMilestone(uint32 azeriteItemMilestonePowerId)
    {
        AddDynamicUpdateFieldValue(m_values.ModifyValue(&AzeriteItem::m_azeriteItemData)
            .ModifyValue(&UF::AzeriteItemData::UnlockedEssenceMilestones)) = azeriteItemMilestonePowerId;
    }

    uint32 GetEssenceRank(uint32 azeriteEssenceId) const;
    void SetEssenceRank(uint32 azeriteEssenceId, uint32 rank);

    UF::SelectedAzeriteEssences const* GetSelectedAzeriteEssences() const;
    void SetSelectedAzeriteEssences(uint32 specializationId);
    void CreateSelectedAzeriteEssences(uint32 specializationId);
    void SetSelectedAzeriteEssence(uint8 slot, uint32 azeriteEssenceId);

    void BuildValuesCreate(ByteBuffer* data, Player const* target) const override;
    void BuildValuesUpdate(ByteBuffer* data, Player const* target) const override;
    void BuildValuesUpdateWithFlag(ByteBuffer* data, UF::UpdateFieldFlag flags, Player const* target) const override;
    void ClearUpdateMask(bool remove) override;

    UF::UpdateField<UF::AzeriteItemData, 0, TYPEID_AZERITE_ITEM> m_azeriteItemData;

private:
    void UnlockDefaultMilestones();
};

#endif // AzeriteItem_h__
