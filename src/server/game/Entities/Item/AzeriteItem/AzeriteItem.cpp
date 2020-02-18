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

#include "AzeriteItem.h"
#include "AzeritePackets.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "GameObject.h"
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

bool AzeriteItem::Create(ObjectGuid::LowType guidlow, uint32 itemId, ItemContext context, Player const* owner)
{
    if (!Item::Create(guidlow, itemId, context, owner))
        return false;

    SetUpdateFieldValue(m_values.ModifyValue(&AzeriteItem::m_azeriteItemData).ModifyValue(&UF::AzeriteItemData::Level), 1);
    SetUpdateFieldValue(m_values.ModifyValue(&AzeriteItem::m_azeriteItemData).ModifyValue(&UF::AzeriteItemData::KnowledgeLevel), GetCurrentKnowledgeLevel());
    UnlockDefaultMilestones();
    return true;
}

void AzeriteItem::SaveToDB(CharacterDatabaseTransaction& trans)
{
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEM_INSTANCE_AZERITE);
    stmt->setUInt64(0, GetGUID().GetCounter());
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEM_INSTANCE_AZERITE_MILESTONE_POWER);
    stmt->setUInt64(0, GetGUID().GetCounter());
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEM_INSTANCE_AZERITE_UNLOCKED_ESSENCE);
    stmt->setUInt64(0, GetGUID().GetCounter());
    trans->Append(stmt);

    switch (GetState())
    {
        case ITEM_NEW:
        case ITEM_CHANGED:
        {
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_ITEM_INSTANCE_AZERITE);
            stmt->setUInt64(0, GetGUID().GetCounter());
            stmt->setUInt64(1, m_azeriteItemData->Xp);
            stmt->setUInt32(2, m_azeriteItemData->Level);
            stmt->setUInt32(3, m_azeriteItemData->KnowledgeLevel);
            std::size_t specIndex = 0;
            for (; specIndex < m_azeriteItemData->SelectedEssences.size(); ++specIndex)
            {
                stmt->setUInt32(4 + specIndex * 5, m_azeriteItemData->SelectedEssences[specIndex].SpecializationID);
                for (std::size_t j = 0; j < MAX_AZERITE_ESSENCE_SLOT; ++j)
                    stmt->setUInt32(5 + specIndex * 5 + j, m_azeriteItemData->SelectedEssences[specIndex].AzeriteEssenceID[j]);
            }
            for (; specIndex < MAX_SPECIALIZATIONS; ++specIndex)
            {
                stmt->setUInt32(4 + specIndex * 5, 0);
                for (std::size_t j = 0; j < MAX_AZERITE_ESSENCE_SLOT; ++j)
                    stmt->setUInt32(5 + specIndex * 5 + j, 0);
            }

            trans->Append(stmt);

            for (uint32 azeriteItemMilestonePowerId : m_azeriteItemData->UnlockedEssenceMilestones)
            {
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_ITEM_INSTANCE_AZERITE_MILESTONE_POWER);
                stmt->setUInt64(0, GetGUID().GetCounter());
                stmt->setUInt32(1, azeriteItemMilestonePowerId);
                trans->Append(stmt);
            }

            for (UF::UnlockedAzeriteEssence const& azeriteEssence : m_azeriteItemData->UnlockedEssences)
            {
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_ITEM_INSTANCE_AZERITE_UNLOCKED_ESSENCE);
                stmt->setUInt64(0, GetGUID().GetCounter());
                stmt->setUInt32(1, azeriteEssence.AzeriteEssenceID);
                stmt->setUInt32(2, azeriteEssence.Rank);
                trans->Append(stmt);
            }
            break;
        }
        case ITEM_REMOVED:
        default:
            break;
    }

    Item::SaveToDB(trans);
}

void AzeriteItem::LoadAzeriteItemData(Player const* owner, AzeriteItemData& azeriteItemData)
{
    bool needSave = false;

    if (!sAzeriteLevelInfoStore.LookupEntry(azeriteItemData.Level))
    {
        azeriteItemData.Xp = 0;
        azeriteItemData.Level = 1;
        azeriteItemData.KnowledgeLevel = GetCurrentKnowledgeLevel();
        needSave = true;
    }
    else if (azeriteItemData.Level > MAX_AZERITE_ITEM_LEVEL)
    {
        azeriteItemData.Xp = 0;
        azeriteItemData.Level = MAX_AZERITE_ITEM_LEVEL;
        needSave = true;
    }

    if (azeriteItemData.KnowledgeLevel != GetCurrentKnowledgeLevel())
    {
        // rescale XP to maintain same progress %
        uint64 oldMax = CalcTotalXPToNextLevel(azeriteItemData.Level, azeriteItemData.KnowledgeLevel);
        azeriteItemData.KnowledgeLevel = GetCurrentKnowledgeLevel();
        uint64 newMax = CalcTotalXPToNextLevel(azeriteItemData.Level, azeriteItemData.KnowledgeLevel);
        azeriteItemData.Xp = uint64(azeriteItemData.Xp / double(oldMax) * newMax);
        needSave = true;
    }
    else if (azeriteItemData.KnowledgeLevel > MAX_AZERITE_ITEM_KNOWLEDGE_LEVEL)
    {
        azeriteItemData.KnowledgeLevel = MAX_AZERITE_ITEM_KNOWLEDGE_LEVEL;
        needSave = true;
    }

    SetUpdateFieldValue(m_values.ModifyValue(&AzeriteItem::m_azeriteItemData).ModifyValue(&UF::AzeriteItemData::Xp), azeriteItemData.Xp);
    SetUpdateFieldValue(m_values.ModifyValue(&AzeriteItem::m_azeriteItemData).ModifyValue(&UF::AzeriteItemData::Level), azeriteItemData.Level);
    SetUpdateFieldValue(m_values.ModifyValue(&AzeriteItem::m_azeriteItemData).ModifyValue(&UF::AzeriteItemData::KnowledgeLevel), azeriteItemData.KnowledgeLevel);
    for (uint32 azeriteItemMilestonePowerId : azeriteItemData.AzeriteItemMilestonePowers)
        AddUnlockedEssenceMilestone(azeriteItemMilestonePowerId);

    UnlockDefaultMilestones();

    for (AzeriteEssencePowerEntry const* unlockedAzeriteEssence : azeriteItemData.UnlockedAzeriteEssences)
        SetEssenceRank(unlockedAzeriteEssence->AzeriteEssenceID, unlockedAzeriteEssence->Tier);

    for (AzeriteItemSelectedEssencesData const& selectedEssenceData : azeriteItemData.SelectedAzeriteEssences)
    {
        if (!selectedEssenceData.SpecializationId)
            continue;

        auto selectedEssences = AddDynamicUpdateFieldValue(m_values.ModifyValue(&AzeriteItem::m_azeriteItemData).ModifyValue(&UF::AzeriteItemData::SelectedEssences));
        selectedEssences.ModifyValue(&UF::SelectedAzeriteEssences::SpecializationID).SetValue(selectedEssenceData.SpecializationId);
        for (uint32 i = 0; i < MAX_AZERITE_ESSENCE_SLOT; ++i)
        {
            // Check if essence was unlocked
            if (!GetEssenceRank(selectedEssenceData.AzeriteEssenceId[i]))
                continue;

            selectedEssences.ModifyValue(&UF::SelectedAzeriteEssences::AzeriteEssenceID, i).SetValue(selectedEssenceData.AzeriteEssenceId[i]);
        }

        if (owner && owner->GetPrimarySpecialization() == selectedEssenceData.SpecializationId)
            selectedEssences.ModifyValue(&UF::SelectedAzeriteEssences::Enabled).SetValue(1);
    }

    // add selected essences for current spec
    if (owner && !GetSelectedAzeriteEssences())
        CreateSelectedAzeriteEssences(owner->GetPrimarySpecialization());

    if (needSave)
    {
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ITEM_INSTANCE_AZERITE_ON_LOAD);
        stmt->setUInt64(0, azeriteItemData.Xp);
        stmt->setUInt32(1, azeriteItemData.KnowledgeLevel);
        stmt->setUInt64(2, GetGUID().GetCounter());
        CharacterDatabase.Execute(stmt);
    }
}

void AzeriteItem::DeleteFromDB(CharacterDatabaseTransaction& trans, ObjectGuid::LowType itemGuid)
{
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEM_INSTANCE_AZERITE);
    stmt->setUInt64(0, itemGuid);
    CharacterDatabase.ExecuteOrAppend(trans, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEM_INSTANCE_AZERITE_MILESTONE_POWER);
    stmt->setUInt64(0, itemGuid);
    CharacterDatabase.ExecuteOrAppend(trans, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEM_INSTANCE_AZERITE_UNLOCKED_ESSENCE);
    stmt->setUInt64(0, itemGuid);
    CharacterDatabase.ExecuteOrAppend(trans, stmt);
}

void AzeriteItem::DeleteFromDB(CharacterDatabaseTransaction& trans)
{
    AzeriteItem::DeleteFromDB(trans, GetGUID().GetCounter());
    Item::DeleteFromDB(trans);
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
            UnlockDefaultMilestones();
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

GameObject const* AzeriteItem::FindHeartForge(Player const* owner)
{
    if (GameObject const* forge = owner->FindNearestGameObjectOfType(GAMEOBJECT_TYPE_ITEM_FORGE, 40.0f))
        if (forge->GetGOInfo()->itemForge.ForgeType == 2)
            return forge;

    return nullptr;
}

bool AzeriteItem::CanUseEssences() const
{
    if (PlayerConditionEntry const* condition = sPlayerConditionStore.LookupEntry(PLAYER_CONDITION_ID_UNLOCKED_AZERITE_ESSENCES))
        return ConditionMgr::IsPlayerMeetingCondition(GetOwner(), condition);

    return false;
}

bool AzeriteItem::HasUnlockedEssenceSlot(uint8 slot) const
{
    AzeriteItemMilestonePowerEntry const* milestone = sDB2Manager.GetAzeriteItemMilestonePower(slot);
    return m_azeriteItemData->UnlockedEssenceMilestones.FindIndex(milestone->ID) != -1;
}

uint32 AzeriteItem::GetEssenceRank(uint32 azeriteEssenceId) const
{
    int32 index = m_azeriteItemData->UnlockedEssences.FindIndexIf([azeriteEssenceId](UF::UnlockedAzeriteEssence const& essence)
    {
        return essence.AzeriteEssenceID == azeriteEssenceId;
    });

    if (index < 0)
        return 0;

    return m_azeriteItemData->UnlockedEssences[index].Rank;
}

void AzeriteItem::SetEssenceRank(uint32 azeriteEssenceId, uint32 rank)
{
    int32 index = m_azeriteItemData->UnlockedEssences.FindIndexIf([azeriteEssenceId](UF::UnlockedAzeriteEssence const& essence)
    {
        return essence.AzeriteEssenceID == azeriteEssenceId;
    });

    if (!rank && index >= 0)
    {
        RemoveDynamicUpdateFieldValue(m_values.ModifyValue(&AzeriteItem::m_azeriteItemData).ModifyValue(&UF::AzeriteItemData::UnlockedEssences), index);
        return;
    }

    if (!sDB2Manager.GetAzeriteEssencePower(azeriteEssenceId, rank))
        return;

    if (index < 0)
    {
        UF::UnlockedAzeriteEssence& unlockedEssence = AddDynamicUpdateFieldValue(m_values.ModifyValue(&AzeriteItem::m_azeriteItemData)
            .ModifyValue(&UF::AzeriteItemData::UnlockedEssences));
        unlockedEssence.AzeriteEssenceID = azeriteEssenceId;
        unlockedEssence.Rank = rank;
    }
    else
        SetUpdateFieldValue(m_values.ModifyValue(&AzeriteItem::m_azeriteItemData).ModifyValue(&UF::AzeriteItemData::UnlockedEssences, index)
            .ModifyValue(&UF::UnlockedAzeriteEssence::Rank), rank);
}

UF::SelectedAzeriteEssences const* AzeriteItem::GetSelectedAzeriteEssences() const
{
    for (UF::SelectedAzeriteEssences const& essences : m_azeriteItemData->SelectedEssences)
        if (essences.Enabled)
            return &essences;

    return nullptr;
}

void AzeriteItem::SetSelectedAzeriteEssences(uint32 specializationId)
{
    int32 index = m_azeriteItemData->SelectedEssences.FindIndexIf([](UF::SelectedAzeriteEssences const& essences) { return essences.Enabled == 1; });
    if (index >= 0)
        SetUpdateFieldValue(m_values.ModifyValue(&AzeriteItem::m_azeriteItemData).ModifyValue(&UF::AzeriteItemData::SelectedEssences, index)
            .ModifyValue(&UF::SelectedAzeriteEssences::Enabled), 0);

    index = m_azeriteItemData->SelectedEssences.FindIndexIf([specializationId](UF::SelectedAzeriteEssences const& essences)
    {
        return essences.SpecializationID == specializationId;
    });

    if (index >= 0)
        SetUpdateFieldValue(m_values.ModifyValue(&AzeriteItem::m_azeriteItemData).ModifyValue(&UF::AzeriteItemData::SelectedEssences, index)
            .ModifyValue(&UF::SelectedAzeriteEssences::Enabled), 1);
    else
        CreateSelectedAzeriteEssences(specializationId);
}

void AzeriteItem::CreateSelectedAzeriteEssences(uint32 specializationId)
{
    auto selectedEssences = AddDynamicUpdateFieldValue(m_values.ModifyValue(&AzeriteItem::m_azeriteItemData).ModifyValue(&UF::AzeriteItemData::SelectedEssences));
    selectedEssences.ModifyValue(&UF::SelectedAzeriteEssences::SpecializationID).SetValue(specializationId);
    selectedEssences.ModifyValue(&UF::SelectedAzeriteEssences::Enabled).SetValue(1);
}

void AzeriteItem::SetSelectedAzeriteEssence(uint8 slot, uint32 azeriteEssenceId)
{
    ASSERT(slot < MAX_AZERITE_ESSENCE_SLOT);
    int32 index = m_azeriteItemData->SelectedEssences.FindIndexIf([](UF::SelectedAzeriteEssences const& essences) { return essences.Enabled == 1; });
    ASSERT(index >= 0);
    SetUpdateFieldValue(m_values.ModifyValue(&AzeriteItem::m_azeriteItemData).ModifyValue(&UF::AzeriteItemData::SelectedEssences, index)
        .ModifyValue(&UF::SelectedAzeriteEssences::AzeriteEssenceID, slot), azeriteEssenceId);
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

void AzeriteItem::UnlockDefaultMilestones()
{
    bool hasPreviousMilestone = true;
    for (AzeriteItemMilestonePowerEntry const* milestone : sDB2Manager.GetAzeriteItemMilestonePowers())
    {
        if (!hasPreviousMilestone)
            break;

        if (milestone->RequiredLevel > int32(GetLevel()))
            break;

        if (HasUnlockedEssenceMilestone(milestone->ID))
            continue;

        if (milestone->AutoUnlock)
        {
            AddUnlockedEssenceMilestone(milestone->ID);
            hasPreviousMilestone = true;
        }
        else
            hasPreviousMilestone = false;
    }
}
