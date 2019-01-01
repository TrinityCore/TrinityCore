/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#include "Item.h"
#include "ArtifactPackets.h"
#include "Bag.h"
#include "CollectionMgr.h"
#include "Common.h"
#include "ConditionMgr.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "GameTables.h"
#include "ItemEnchantmentMgr.h"
#include "ItemPackets.h"
#include "Log.h"
#include "LootMgr.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "TradeData.h"
#include "UpdateData.h"
#include "World.h"
#include "WorldSession.h"

void AddItemsSetItem(Player* player, Item* item)
{
    ItemTemplate const* proto = item->GetTemplate();
    uint32 setid = proto->GetItemSet();

    ItemSetEntry const* set = sItemSetStore.LookupEntry(setid);

    if (!set)
    {
        TC_LOG_ERROR("sql.sql", "Item set %u for item (id %u) not found, mods not applied.", setid, proto->GetId());
        return;
    }

    if (set->RequiredSkill && player->GetSkillValue(set->RequiredSkill) < set->RequiredSkillRank)
        return;

    if (set->SetFlags & ITEM_SET_FLAG_LEGACY_INACTIVE)
        return;

    ItemSetEffect* eff = NULL;

    for (size_t x = 0; x < player->ItemSetEff.size(); ++x)
    {
        if (player->ItemSetEff[x] && player->ItemSetEff[x]->ItemSetID == setid)
        {
            eff = player->ItemSetEff[x];
            break;
        }
    }

    if (!eff)
    {
        eff = new ItemSetEffect();
        eff->ItemSetID = setid;
        eff->EquippedItemCount = 0;

        size_t x = 0;
        for (; x < player->ItemSetEff.size(); ++x)
            if (!player->ItemSetEff[x])
                break;

        if (x < player->ItemSetEff.size())
            player->ItemSetEff[x] = eff;
        else
            player->ItemSetEff.push_back(eff);
    }

    ++eff->EquippedItemCount;

    if (std::vector<ItemSetSpellEntry const*> const* itemSetSpells = sDB2Manager.GetItemSetSpells(setid))
    {
        for (ItemSetSpellEntry const* itemSetSpell : *itemSetSpells)
        {
            //not enough for  spell
            if (itemSetSpell->Threshold > eff->EquippedItemCount)
                continue;

            if (eff->SetBonuses.count(itemSetSpell))
                continue;

            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(itemSetSpell->SpellID);
            if (!spellInfo)
            {
                TC_LOG_ERROR("entities.player.items", "WORLD: unknown spell id %u in items set %u effects", itemSetSpell->SpellID, setid);
                continue;
            }

            eff->SetBonuses.insert(itemSetSpell);
            // spell cast only if fit form requirement, in other case will cast at form change
            if (!itemSetSpell->ChrSpecID || itemSetSpell->ChrSpecID == player->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID))
                player->ApplyEquipSpell(spellInfo, NULL, true);
        }
    }
}

void RemoveItemsSetItem(Player* player, ItemTemplate const* proto)
{
    uint32 setid = proto->GetItemSet();

    ItemSetEntry const* set = sItemSetStore.LookupEntry(setid);

    if (!set)
    {
        TC_LOG_ERROR("sql.sql", "Item set #%u for item #%u not found, mods not removed.", setid, proto->GetId());
        return;
    }

    ItemSetEffect* eff = NULL;
    size_t setindex = 0;
    for (; setindex < player->ItemSetEff.size(); setindex++)
    {
        if (player->ItemSetEff[setindex] && player->ItemSetEff[setindex]->ItemSetID == setid)
        {
            eff = player->ItemSetEff[setindex];
            break;
        }
    }

    // can be in case now enough skill requirement for set appling but set has been appliend when skill requirement not enough
    if (!eff)
        return;

    --eff->EquippedItemCount;

    if (std::vector<ItemSetSpellEntry const*> const* itemSetSpells = sDB2Manager.GetItemSetSpells(setid))
    {
        for (ItemSetSpellEntry const* itemSetSpell : *itemSetSpells)
        {
            // enough for spell
            if (itemSetSpell->Threshold <= eff->EquippedItemCount)
                continue;

            if (!eff->SetBonuses.count(itemSetSpell))
                continue;

            player->ApplyEquipSpell(sSpellMgr->AssertSpellInfo(itemSetSpell->SpellID), nullptr, false);
            eff->SetBonuses.erase(itemSetSpell);
        }
    }

    if (!eff->EquippedItemCount)                                    //all items of a set were removed
    {
        ASSERT(eff == player->ItemSetEff[setindex]);
        delete eff;
        player->ItemSetEff[setindex] = NULL;
    }
}

bool ItemCanGoIntoBag(ItemTemplate const* pProto, ItemTemplate const* pBagProto)
{
    if (!pProto || !pBagProto)
        return false;

    switch (pBagProto->GetClass())
    {
        case ITEM_CLASS_CONTAINER:
            switch (pBagProto->GetSubClass())
            {
                case ITEM_SUBCLASS_CONTAINER:
                    return true;
                case ITEM_SUBCLASS_SOUL_CONTAINER:
                    if (!(pProto->GetBagFamily() & BAG_FAMILY_MASK_SOUL_SHARDS))
                        return false;
                    return true;
                case ITEM_SUBCLASS_HERB_CONTAINER:
                    if (!(pProto->GetBagFamily() & BAG_FAMILY_MASK_HERBS))
                        return false;
                    return true;
                case ITEM_SUBCLASS_ENCHANTING_CONTAINER:
                    if (!(pProto->GetBagFamily() & BAG_FAMILY_MASK_ENCHANTING_SUPP))
                        return false;
                    return true;
                case ITEM_SUBCLASS_MINING_CONTAINER:
                    if (!(pProto->GetBagFamily() & BAG_FAMILY_MASK_MINING_SUPP))
                        return false;
                    return true;
                case ITEM_SUBCLASS_ENGINEERING_CONTAINER:
                    if (!(pProto->GetBagFamily() & BAG_FAMILY_MASK_ENGINEERING_SUPP))
                        return false;
                    return true;
                case ITEM_SUBCLASS_GEM_CONTAINER:
                    if (!(pProto->GetBagFamily() & BAG_FAMILY_MASK_GEMS))
                        return false;
                    return true;
                case ITEM_SUBCLASS_LEATHERWORKING_CONTAINER:
                    if (!(pProto->GetBagFamily() & BAG_FAMILY_MASK_LEATHERWORKING_SUPP))
                        return false;
                    return true;
                case ITEM_SUBCLASS_INSCRIPTION_CONTAINER:
                    if (!(pProto->GetBagFamily() & BAG_FAMILY_MASK_INSCRIPTION_SUPP))
                        return false;
                    return true;
                case ITEM_SUBCLASS_TACKLE_CONTAINER:
                    if (!(pProto->GetBagFamily() & BAG_FAMILY_MASK_FISHING_SUPP))
                        return false;
                    return true;
                case ITEM_SUBCLASS_COOKING_CONTAINER:
                    if (!(pProto->GetBagFamily() & BAG_FAMILY_MASK_COOKING_SUPP))
                        return false;
                    return true;
                default:
                    return false;
            }
        case ITEM_CLASS_QUIVER:
            switch (pBagProto->GetSubClass())
            {
                case ITEM_SUBCLASS_QUIVER:
                    if (!(pProto->GetBagFamily() & BAG_FAMILY_MASK_ARROWS))
                        return false;
                    return true;
                case ITEM_SUBCLASS_AMMO_POUCH:
                    if (!(pProto->GetBagFamily() & BAG_FAMILY_MASK_BULLETS))
                        return false;
                    return true;
                default:
                    return false;
            }
    }
    return false;
}

ItemModifier const AppearanceModifierSlotBySpec[MAX_SPECIALIZATIONS] =
{
    ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_1,
    ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_2,
    ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_3,
    ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_4
};

static uint32 const AppearanceModifierMaskSpecSpecific =
    (1 << ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_1) |
    (1 << ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_2) |
    (1 << ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_3) |
    (1 << ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_4);

ItemModifier const IllusionModifierSlotBySpec[MAX_SPECIALIZATIONS] =
{
    ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_1,
    ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_2,
    ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_3,
    ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_4
};

static uint32 const IllusionModifierMaskSpecSpecific =
    (1 << ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_1) |
    (1 << ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_2) |
    (1 << ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_3) |
    (1 << ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_4);

Item::Item()
{
    m_objectType |= TYPEMASK_ITEM;
    m_objectTypeId = TYPEID_ITEM;

    m_valuesCount = ITEM_END;
    _dynamicValuesCount = ITEM_DYNAMIC_END;
    m_slot = 0;
    uState = ITEM_NEW;
    uQueuePos = -1;
    m_container = NULL;
    m_lootGenerated = false;
    mb_in_trade = false;
    m_lastPlayedTimeUpdate = time(NULL);

    m_paidMoney = 0;
    m_paidExtendedCost = 0;

    memset(&_bonusData, 0, sizeof(_bonusData));
}

bool Item::Create(ObjectGuid::LowType guidlow, uint32 itemId, Player const* owner)
{
    Object::_Create(ObjectGuid::Create<HighGuid::Item>(guidlow));

    SetEntry(itemId);
    SetObjectScale(1.0f);

    if (owner)
    {
        SetOwnerGUID(owner->GetGUID());
        SetGuidValue(ITEM_FIELD_CONTAINED, owner->GetGUID());
    }

    ItemTemplate const* itemProto = sObjectMgr->GetItemTemplate(itemId);
    if (!itemProto)
        return false;

    _bonusData.Initialize(itemProto);
    SetUInt32Value(ITEM_FIELD_STACK_COUNT, 1);
    SetUInt32Value(ITEM_FIELD_MAXDURABILITY, itemProto->MaxDurability);
    SetUInt32Value(ITEM_FIELD_DURABILITY, itemProto->MaxDurability);

    for (std::size_t i = 0; i < itemProto->Effects.size(); ++i)
        if (i < 5)
            SetSpellCharges(i, itemProto->Effects[i]->Charges);

    SetUInt32Value(ITEM_FIELD_DURATION, itemProto->GetDuration());
    SetUInt32Value(ITEM_FIELD_CREATE_PLAYED_TIME, 0);

    if (itemProto->GetArtifactID())
    {
        InitArtifactPowers(itemProto->GetArtifactID(), 0);
        for (ArtifactAppearanceEntry const* artifactAppearance : sArtifactAppearanceStore)
        {
            if (ArtifactAppearanceSetEntry const* artifactAppearanceSet = sArtifactAppearanceSetStore.LookupEntry(artifactAppearance->ArtifactAppearanceSetID))
            {
                if (itemProto->GetArtifactID() != artifactAppearanceSet->ArtifactID)
                    continue;

                if (PlayerConditionEntry const* playerCondition = sPlayerConditionStore.LookupEntry(artifactAppearance->UnlockPlayerConditionID))
                    if (!owner || !sConditionMgr->IsPlayerMeetingCondition(owner, playerCondition))
                        continue;

                SetModifier(ITEM_MODIFIER_ARTIFACT_APPEARANCE_ID, artifactAppearance->ID);
                SetAppearanceModId(artifactAppearance->ItemAppearanceModifierID);
                break;
            }
        }

        CheckArtifactRelicSlotUnlock(owner ? owner : GetOwner());
    }

    return true;
}

// Returns true if Item is a bag AND it is not empty.
// Returns false if Item is not a bag OR it is an empty bag.
bool Item::IsNotEmptyBag() const
{
    if (Bag const* bag = ToBag())
        return !bag->IsEmpty();
    return false;
}

void Item::UpdateDuration(Player* owner, uint32 diff)
{
    if (!GetUInt32Value(ITEM_FIELD_DURATION))
        return;

    TC_LOG_DEBUG("entities.player.items", "Item::UpdateDuration Item (Entry: %u Duration %u Diff %u)", GetEntry(), GetUInt32Value(ITEM_FIELD_DURATION), diff);

    if (GetUInt32Value(ITEM_FIELD_DURATION) <= diff)
    {
        sScriptMgr->OnItemExpire(owner, GetTemplate());
        owner->DestroyItem(GetBagSlot(), GetSlot(), true);
        return;
    }

    SetUInt32Value(ITEM_FIELD_DURATION, GetUInt32Value(ITEM_FIELD_DURATION) - diff);
    SetState(ITEM_CHANGED, owner);                          // save new time in database
}

void Item::SaveToDB(SQLTransaction& trans)
{
    bool isInTransaction = bool(trans);
    if (!isInTransaction)
        trans = CharacterDatabase.BeginTransaction();

    switch (uState)
    {
        case ITEM_NEW:
        case ITEM_CHANGED:
        {
            uint8 index = 0;
            PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(uState == ITEM_NEW ? CHAR_REP_ITEM_INSTANCE : CHAR_UPD_ITEM_INSTANCE);
            stmt->setUInt32(  index, GetEntry());
            stmt->setUInt64(++index, GetOwnerGUID().GetCounter());
            stmt->setUInt64(++index, GetGuidValue(ITEM_FIELD_CREATOR).GetCounter());
            stmt->setUInt64(++index, GetGuidValue(ITEM_FIELD_GIFTCREATOR).GetCounter());
            stmt->setUInt32(++index, GetCount());
            stmt->setUInt32(++index, GetUInt32Value(ITEM_FIELD_DURATION));

            std::ostringstream ssSpells;
            if (ItemTemplate const* itemProto = sObjectMgr->GetItemTemplate(GetEntry()))
                for (uint8 i = 0; i < itemProto->Effects.size(); ++i)
                    ssSpells << GetSpellCharges(i) << ' ';
            stmt->setString(++index, ssSpells.str());

            stmt->setUInt32(++index, GetUInt32Value(ITEM_FIELD_FLAGS));

            std::ostringstream ssEnchants;
            for (uint8 i = 0; i < MAX_ENCHANTMENT_SLOT; ++i)
            {
                ssEnchants << GetEnchantmentId(EnchantmentSlot(i)) << ' ';
                ssEnchants << GetEnchantmentDuration(EnchantmentSlot(i)) << ' ';
                ssEnchants << GetEnchantmentCharges(EnchantmentSlot(i)) << ' ';
            }
            stmt->setString(++index, ssEnchants.str());

            stmt->setUInt8(++index, uint8(GetItemRandomEnchantmentId().Type));
            stmt->setUInt32(++index, GetItemRandomEnchantmentId().Id);
            stmt->setUInt16(++index, GetUInt32Value(ITEM_FIELD_DURABILITY));
            stmt->setUInt32(++index, GetUInt32Value(ITEM_FIELD_CREATE_PLAYED_TIME));
            stmt->setString(++index, m_text);
            stmt->setUInt32(++index, GetModifier(ITEM_MODIFIER_UPGRADE_ID));
            stmt->setUInt32(++index, GetModifier(ITEM_MODIFIER_BATTLE_PET_SPECIES_ID));
            stmt->setUInt32(++index, GetModifier(ITEM_MODIFIER_BATTLE_PET_BREED_DATA));
            stmt->setUInt32(++index, GetModifier(ITEM_MODIFIER_BATTLE_PET_LEVEL));
            stmt->setUInt32(++index, GetModifier(ITEM_MODIFIER_BATTLE_PET_DISPLAY_ID));
            stmt->setUInt8(++index, uint8(GetUInt32Value(ITEM_FIELD_CONTEXT)));

            std::ostringstream bonusListIDs;
            for (uint32 bonusListID : GetDynamicValues(ITEM_DYNAMIC_FIELD_BONUSLIST_IDS))
                bonusListIDs << bonusListID << ' ';
            stmt->setString(++index, bonusListIDs.str());

            stmt->setUInt64(++index, GetGUID().GetCounter());

            trans->Append(stmt);

            if ((uState == ITEM_CHANGED) && HasFlag(ITEM_FIELD_FLAGS, ITEM_FIELD_FLAG_WRAPPED))
            {
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GIFT_OWNER);
                stmt->setUInt64(0, GetOwnerGUID().GetCounter());
                stmt->setUInt64(1, GetGUID().GetCounter());
                trans->Append(stmt);
            }

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEM_INSTANCE_GEMS);
            stmt->setUInt64(0, GetGUID().GetCounter());
            trans->Append(stmt);

            if (GetGems().size())
            {
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_ITEM_INSTANCE_GEMS);
                stmt->setUInt64(0, GetGUID().GetCounter());
                uint32 i = 0;
                uint32 const gemFields = 4;
                for (ItemDynamicFieldGems const& gemData : GetGems())
                {
                    if (gemData.ItemId)
                    {
                        stmt->setUInt32(1 + i * gemFields, gemData.ItemId);
                        std::ostringstream gemBonusListIDs;
                        for (uint16 bonusListID : gemData.BonusListIDs)
                            if (bonusListID)
                                gemBonusListIDs << bonusListID << ' ';
                        stmt->setString(2 + i * gemFields, gemBonusListIDs.str());
                        stmt->setUInt8(3 + i * gemFields, gemData.Context);
                        stmt->setUInt32(4 + i * gemFields, m_gemScalingLevels[i]);
                    }
                    else
                    {
                        stmt->setUInt32(1 + i * gemFields, 0);
                        stmt->setString(2 + i * gemFields, "");
                        stmt->setUInt8(3 + i * gemFields, 0);
                        stmt->setUInt32(4 + i * gemFields, 0);
                    }
                    ++i;
                }
                for (; i < MAX_GEM_SOCKETS; ++i)
                {
                    stmt->setUInt32(1 + i * gemFields, 0);
                    stmt->setString(2 + i * gemFields, "");
                    stmt->setUInt8(3 + i * gemFields, 0);
                    stmt->setUInt32(4 + i * gemFields, 0);
                }
                trans->Append(stmt);
            }

            static ItemModifier const transmogMods[10] =
            {
                ITEM_MODIFIER_TRANSMOG_APPEARANCE_ALL_SPECS,
                ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_1,
                ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_2,
                ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_3,
                ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_4,

                ITEM_MODIFIER_ENCHANT_ILLUSION_ALL_SPECS,
                ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_1,
                ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_2,
                ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_3,
                ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_4,
            };

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEM_INSTANCE_TRANSMOG);
            stmt->setUInt64(0, GetGUID().GetCounter());
            trans->Append(stmt);

            if (std::find_if(std::begin(transmogMods), std::end(transmogMods), [this](ItemModifier modifier) { return GetModifier(modifier) != 0; }) != std::end(transmogMods))
            {
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_ITEM_INSTANCE_TRANSMOG);
                stmt->setUInt64(0, GetGUID().GetCounter());
                stmt->setUInt32(1, GetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_ALL_SPECS));
                stmt->setUInt32(2, GetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_1));
                stmt->setUInt32(3, GetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_2));
                stmt->setUInt32(4, GetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_3));
                stmt->setUInt32(5, GetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_4));
                stmt->setUInt32(6, GetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_ALL_SPECS));
                stmt->setUInt32(7, GetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_1));
                stmt->setUInt32(8, GetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_2));
                stmt->setUInt32(9, GetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_3));
                stmt->setUInt32(10, GetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_4));
                trans->Append(stmt);
            }

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEM_INSTANCE_ARTIFACT);
            stmt->setUInt64(0, GetGUID().GetCounter());
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEM_INSTANCE_ARTIFACT_POWERS);
            stmt->setUInt64(0, GetGUID().GetCounter());
            trans->Append(stmt);

            if (GetTemplate()->GetArtifactID())
            {
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_ITEM_INSTANCE_ARTIFACT);
                stmt->setUInt64(0, GetGUID().GetCounter());
                stmt->setUInt64(1, GetUInt64Value(ITEM_FIELD_ARTIFACT_XP));
                stmt->setUInt32(2, GetModifier(ITEM_MODIFIER_ARTIFACT_APPEARANCE_ID));
                stmt->setUInt32(3, GetModifier(ITEM_MODIFIER_ARTIFACT_TIER));
                trans->Append(stmt);

                for (ItemDynamicFieldArtifactPowers const& artifactPower : GetArtifactPowers())
                {
                    stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_ITEM_INSTANCE_ARTIFACT_POWERS);
                    stmt->setUInt64(0, GetGUID().GetCounter());
                    stmt->setUInt32(1, artifactPower.ArtifactPowerId);
                    stmt->setUInt8(2, artifactPower.PurchasedRank);
                    trans->Append(stmt);
                }
            }

            static ItemModifier const modifiersTable[] =
            {
                ITEM_MODIFIER_SCALING_STAT_DISTRIBUTION_FIXED_LEVEL,
                ITEM_MODIFIER_ARTIFACT_KNOWLEDGE_LEVEL
            };

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEM_INSTANCE_MODIFIERS);
            stmt->setUInt64(0, GetGUID().GetCounter());
            trans->Append(stmt);

            if (std::find_if(std::begin(modifiersTable), std::end(modifiersTable), [this](ItemModifier modifier) { return GetModifier(modifier) != 0; }) != std::end(modifiersTable))
            {
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_ITEM_INSTANCE_MODIFIERS);
                stmt->setUInt64(0, GetGUID().GetCounter());
                stmt->setUInt32(1, GetModifier(ITEM_MODIFIER_SCALING_STAT_DISTRIBUTION_FIXED_LEVEL));
                stmt->setUInt32(2, GetModifier(ITEM_MODIFIER_ARTIFACT_KNOWLEDGE_LEVEL));
                trans->Append(stmt);
            }

            break;
        }
        case ITEM_REMOVED:
        {
            PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEM_INSTANCE);
            stmt->setUInt64(0, GetGUID().GetCounter());
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEM_INSTANCE_GEMS);
            stmt->setUInt64(0, GetGUID().GetCounter());
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEM_INSTANCE_TRANSMOG);
            stmt->setUInt64(0, GetGUID().GetCounter());
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEM_INSTANCE_ARTIFACT);
            stmt->setUInt64(0, GetGUID().GetCounter());
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEM_INSTANCE_ARTIFACT_POWERS);
            stmt->setUInt64(0, GetGUID().GetCounter());
            trans->Append(stmt);

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEM_INSTANCE_MODIFIERS);
            stmt->setUInt64(0, GetGUID().GetCounter());
            trans->Append(stmt);

            if (HasFlag(ITEM_FIELD_FLAGS, ITEM_FIELD_FLAG_WRAPPED))
            {
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GIFT);
                stmt->setUInt64(0, GetGUID().GetCounter());
                trans->Append(stmt);
            }

            if (!isInTransaction)
                CharacterDatabase.CommitTransaction(trans);

            // Delete the items if this is a container
            if (!loot.isLooted())
                ItemContainerDeleteLootMoneyAndLootItemsFromDB();

            delete this;
            return;
        }
        case ITEM_UNCHANGED:
            break;
    }

    SetState(ITEM_UNCHANGED);

    if (!isInTransaction)
        CharacterDatabase.CommitTransaction(trans);
}

bool Item::LoadFromDB(ObjectGuid::LowType guid, ObjectGuid ownerGuid, Field* fields, uint32 entry)
{
    //           0          1            2                3      4         5        6      7             8                   9                10          11          12    13
    // SELECT guid, itemEntry, creatorGuid, giftCreatorGuid, count, duration, charges, flags, enchantments, randomPropertyType, randomPropertyId, durability, playedTime, text,
    //               14                  15                  16              17                  18       19            20
    //        upgradeId, battlePetSpeciesId, battlePetBreedData, battlePetLevel, battlePetDisplayId, context, bonusListIDs,
    //                                   21                            22                           23                           24                           25
    //        itemModifiedAppearanceAllSpecs, itemModifiedAppearanceSpec1, itemModifiedAppearanceSpec2, itemModifiedAppearanceSpec3, itemModifiedAppearanceSpec4,
    //                                  26                        27                          28                         29                         30
    //        spellItemEnchantmentAllSpecs, spellItemEnchantmentSpec1, spellItemEnchantmentSpec2, spellItemEnchantmentSpec3, spellItemEnchantmentSpec4,
    //                31           32           33                34          35           36           37                38          39           40           41                42
    //        gemItemId1, gemBonuses1, gemContext1, gemScalingLevel1, gemItemId2, gemBonuses2, gemContext2, gemScalingLevel2, gemItemId3, gemBonuses3, gemContext3, gemScalingLevel3
    //                       43                      44
    //        fixedScalingLevel, artifactKnowledgeLevel FROM item_instance

    // create item before any checks for store correct guid
    // and allow use "FSetState(ITEM_REMOVED); SaveToDB();" for deleting item from DB
    Object::_Create(ObjectGuid::Create<HighGuid::Item>(guid));

    // Set entry, MUST be before proto check
    SetEntry(entry);
    SetObjectScale(1.0f);

    ItemTemplate const* proto = GetTemplate();
    if (!proto)
        return false;

    _bonusData.Initialize(proto);

    // set owner (not if item is only loaded for gbank/auction/mail
    if (!ownerGuid.IsEmpty())
        SetOwnerGUID(ownerGuid);

    uint32 itemFlags = fields[7].GetUInt32();
    bool need_save = false;                                 // need explicit save data at load fixes
    if (uint64 creator = fields[2].GetUInt64())
    {
        if (!(itemFlags & ITEM_FIELD_FLAG_CHILD))
            SetGuidValue(ITEM_FIELD_CREATOR, ObjectGuid::Create<HighGuid::Player>(creator));
        else
            SetGuidValue(ITEM_FIELD_CREATOR, ObjectGuid::Create<HighGuid::Item>(creator));
    }
    if (uint64 giftCreator = fields[3].GetUInt64())
        SetGuidValue(ITEM_FIELD_GIFTCREATOR, ObjectGuid::Create<HighGuid::Player>(giftCreator));
    SetCount(fields[4].GetUInt32());

    uint32 duration = fields[5].GetUInt32();
    SetUInt32Value(ITEM_FIELD_DURATION, duration);
    // update duration if need, and remove if not need
    if ((proto->GetDuration() == 0) != (duration == 0))
    {
        SetUInt32Value(ITEM_FIELD_DURATION, proto->GetDuration());
        need_save = true;
    }

    Tokenizer tokens(fields[6].GetString(), ' ', proto->Effects.size());
    if (tokens.size() == proto->Effects.size())
        for (uint8 i = 0; i < proto->Effects.size(); ++i)
            SetSpellCharges(i, atoi(tokens[i]));

    SetUInt32Value(ITEM_FIELD_FLAGS, itemFlags);

    uint32 durability = fields[11].GetUInt16();
    SetUInt32Value(ITEM_FIELD_DURABILITY, durability);
    // update max durability (and durability) if need
    SetUInt32Value(ITEM_FIELD_MAXDURABILITY, proto->MaxDurability);
    if (durability > proto->MaxDurability)
    {
        SetUInt32Value(ITEM_FIELD_DURABILITY, proto->MaxDurability);
        need_save = true;
    }

    SetUInt32Value(ITEM_FIELD_CREATE_PLAYED_TIME, fields[12].GetUInt32());
    SetText(fields[13].GetString());

    uint32 upgradeId = fields[14].GetUInt32();
    ItemUpgradeEntry const* rulesetUpgrade = sItemUpgradeStore.LookupEntry(sDB2Manager.GetRulesetItemUpgrade(entry));
    ItemUpgradeEntry const* upgrade = sItemUpgradeStore.LookupEntry(upgradeId);
    if (!rulesetUpgrade || !upgrade || rulesetUpgrade->ItemUpgradePathID != upgrade->ItemUpgradePathID)
    {
        upgradeId = 0;
        need_save = true;
    }

    if (rulesetUpgrade && !upgradeId)
    {
        upgradeId = rulesetUpgrade->ID;
        need_save = true;
    }

    SetModifier(ITEM_MODIFIER_UPGRADE_ID, upgradeId);
    SetModifier(ITEM_MODIFIER_BATTLE_PET_SPECIES_ID, fields[15].GetUInt32());
    SetModifier(ITEM_MODIFIER_BATTLE_PET_BREED_DATA, fields[16].GetUInt32());
    SetModifier(ITEM_MODIFIER_BATTLE_PET_LEVEL, fields[17].GetUInt16());
    SetModifier(ITEM_MODIFIER_BATTLE_PET_DISPLAY_ID, fields[18].GetUInt32());

    SetUInt32Value(ITEM_FIELD_CONTEXT, fields[19].GetUInt8());

    Tokenizer bonusListIDs(fields[20].GetString(), ' ');
    for (char const* token : bonusListIDs)
    {
        uint32 bonusListID = atoul(token);
        AddBonuses(bonusListID);
    }

    SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_ALL_SPECS, fields[21].GetUInt32());
    SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_1, fields[22].GetUInt32());
    SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_2, fields[23].GetUInt32());
    SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_3, fields[24].GetUInt32());
    SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_4, fields[25].GetUInt32());

    SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_ALL_SPECS, fields[26].GetUInt32());
    SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_1, fields[27].GetUInt32());
    SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_2, fields[28].GetUInt32());
    SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_3, fields[29].GetUInt32());
    SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_4, fields[30].GetUInt32());

    uint32 const gemFields = 4;
    ItemDynamicFieldGems gemData[MAX_GEM_SOCKETS];
    memset(gemData, 0, sizeof(gemData));
    for (uint32 i = 0; i < MAX_GEM_SOCKETS; ++i)
    {
        gemData[i].ItemId = fields[31 + i * gemFields].GetUInt32();
        Tokenizer gemBonusListIDs(fields[32 + i * gemFields].GetString(), ' ');
        uint32 b = 0;
        for (char const* token : gemBonusListIDs)
            if (uint32 bonusListID = atoul(token))
                gemData[i].BonusListIDs[b++] = bonusListID;

        gemData[i].Context = fields[33 + i * gemFields].GetUInt8();
        if (gemData[i].ItemId)
            SetGem(i, &gemData[i], fields[34 + i * gemFields].GetUInt32());
    }

    SetModifier(ITEM_MODIFIER_SCALING_STAT_DISTRIBUTION_FIXED_LEVEL, fields[43].GetUInt32());
    SetModifier(ITEM_MODIFIER_ARTIFACT_KNOWLEDGE_LEVEL, fields[44].GetUInt32());

    // Enchants must be loaded after all other bonus/scaling data
    _LoadIntoDataField(fields[8].GetString(), ITEM_FIELD_ENCHANTMENT, MAX_ENCHANTMENT_SLOT * MAX_ENCHANTMENT_OFFSET);
    m_randomEnchantment.Type = ItemRandomEnchantmentType(fields[9].GetUInt8());
    m_randomEnchantment.Id = fields[10].GetUInt32();
    if (m_randomEnchantment.Type == ItemRandomEnchantmentType::Property)
        SetUInt32Value(ITEM_FIELD_RANDOM_PROPERTIES_ID, m_randomEnchantment.Id);
    else if (m_randomEnchantment.Type == ItemRandomEnchantmentType::Suffix)
    {
        SetInt32Value(ITEM_FIELD_RANDOM_PROPERTIES_ID, -int32(m_randomEnchantment.Id));
        // recalculate suffix factor
        UpdateItemSuffixFactor();
    }

    // Remove bind flag for items vs BIND_NONE set
    if (IsSoulBound() && GetBonding() == BIND_NONE)
    {
        ApplyModFlag(ITEM_FIELD_FLAGS, ITEM_FIELD_FLAG_SOULBOUND, false);
        need_save = true;
    }

    if (need_save)                                           // normal item changed state set not work at loading
    {
        uint8 index = 0;
        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ITEM_INSTANCE_ON_LOAD);
        stmt->setUInt32(index++, GetUInt32Value(ITEM_FIELD_DURATION));
        stmt->setUInt32(index++, GetUInt32Value(ITEM_FIELD_FLAGS));
        stmt->setUInt32(index++, GetUInt32Value(ITEM_FIELD_DURABILITY));
        stmt->setUInt32(index++, GetModifier(ITEM_MODIFIER_UPGRADE_ID));
        stmt->setUInt64(index++, guid);
        CharacterDatabase.Execute(stmt);
    }

    return true;
}

void Item::LoadArtifactData(Player* owner, uint64 xp, uint32 artifactAppearanceId, uint32 artifactTier, std::vector<ItemDynamicFieldArtifactPowers>& powers)
{
    for (uint8 i = 0; i <= artifactTier; ++i)
        InitArtifactPowers(GetTemplate()->GetArtifactID(), i);

    SetUInt64Value(ITEM_FIELD_ARTIFACT_XP, xp);
    SetModifier(ITEM_MODIFIER_ARTIFACT_APPEARANCE_ID, artifactAppearanceId);
    SetModifier(ITEM_MODIFIER_ARTIFACT_TIER, artifactTier);

    if (ArtifactAppearanceEntry const* artifactAppearance = sArtifactAppearanceStore.LookupEntry(artifactAppearanceId))
        SetAppearanceModId(artifactAppearance->ItemAppearanceModifierID);

    uint8 totalPurchasedRanks = 0;
    for (ItemDynamicFieldArtifactPowers& power : powers)
    {
        power.CurrentRankWithBonus += power.PurchasedRank;
        totalPurchasedRanks += power.PurchasedRank;

        ArtifactPowerEntry const* artifactPower = sArtifactPowerStore.AssertEntry(power.ArtifactPowerId);
        for (uint32 e = SOCK_ENCHANTMENT_SLOT; e <= SOCK_ENCHANTMENT_SLOT_3; ++e)
        {
            if (SpellItemEnchantmentEntry const* enchant = sSpellItemEnchantmentStore.LookupEntry(GetEnchantmentId(EnchantmentSlot(e))))
            {
                for (uint32 i = 0; i < MAX_ITEM_ENCHANTMENT_EFFECTS; ++i)
                {
                    switch (enchant->Effect[i])
                    {
                        case ITEM_ENCHANTMENT_TYPE_ARTIFACT_POWER_BONUS_RANK_BY_TYPE:
                            if (uint32(artifactPower->Label) == enchant->EffectArg[i])
                                power.CurrentRankWithBonus += enchant->EffectPointsMin[i];
                            break;
                        case ITEM_ENCHANTMENT_TYPE_ARTIFACT_POWER_BONUS_RANK_BY_ID:
                            if (artifactPower->ID == enchant->EffectArg[i])
                                power.CurrentRankWithBonus += enchant->EffectPointsMin[i];
                            break;
                        case ITEM_ENCHANTMENT_TYPE_ARTIFACT_POWER_BONUS_RANK_PICKER:
                            if (_bonusData.GemRelicType[e - SOCK_ENCHANTMENT_SLOT] != -1)
                            {
                                if (ArtifactPowerPickerEntry const* artifactPowerPicker = sArtifactPowerPickerStore.LookupEntry(enchant->EffectArg[i]))
                                {
                                    PlayerConditionEntry const* playerCondition = sPlayerConditionStore.LookupEntry(artifactPowerPicker->PlayerConditionID);
                                    if (!playerCondition || sConditionMgr->IsPlayerMeetingCondition(owner, playerCondition))
                                        if (artifactPower->Label == _bonusData.GemRelicType[e - SOCK_ENCHANTMENT_SLOT])
                                            power.CurrentRankWithBonus += enchant->EffectPointsMin[i];
                                }
                            }
                            break;
                        default:
                            break;
                    }
                }
            }
        }

        SetArtifactPower(&power);
    }

    for (ItemDynamicFieldArtifactPowers& power : powers)
    {
        ArtifactPowerEntry const* scaledArtifactPowerEntry = sArtifactPowerStore.AssertEntry(power.ArtifactPowerId);
        if (!(scaledArtifactPowerEntry->Flags & ARTIFACT_POWER_FLAG_SCALES_WITH_NUM_POWERS))
            continue;

        power.CurrentRankWithBonus = totalPurchasedRanks + 1;
        SetArtifactPower(&power);
    }

    CheckArtifactRelicSlotUnlock(owner ? owner : GetOwner());
}

void Item::CheckArtifactRelicSlotUnlock(Player const* owner)
{
    if (!owner)
        return;

    uint8 artifactId = GetTemplate()->GetArtifactID();
    if (!artifactId)
        return;

    for (ArtifactUnlockEntry const* artifactUnlock : sArtifactUnlockStore)
        if (artifactUnlock->ArtifactID == artifactId)
            if (owner->MeetPlayerCondition(artifactUnlock->PlayerConditionID))
                AddBonuses(artifactUnlock->ItemBonusListID);
}

/*static*/
void Item::DeleteFromDB(SQLTransaction& trans, ObjectGuid::LowType itemGuid)
{
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEM_INSTANCE);
    stmt->setUInt64(0, itemGuid);
    trans->Append(stmt);
}

void Item::DeleteFromDB(SQLTransaction& trans)
{
    DeleteFromDB(trans, GetGUID().GetCounter());

    // Delete the items if this is a container
    if (!loot.isLooted())
        ItemContainerDeleteLootMoneyAndLootItemsFromDB();
}

/*static*/
void Item::DeleteFromInventoryDB(SQLTransaction& trans, ObjectGuid::LowType itemGuid)
{
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_INVENTORY_BY_ITEM);
    stmt->setUInt64(0, itemGuid);
    trans->Append(stmt);
}

void Item::DeleteFromInventoryDB(SQLTransaction& trans)
{
    DeleteFromInventoryDB(trans, GetGUID().GetCounter());
}

ItemTemplate const* Item::GetTemplate() const
{
    return sObjectMgr->GetItemTemplate(GetEntry());
}

Player* Item::GetOwner() const
{
    return ObjectAccessor::FindPlayer(GetOwnerGUID());
}

// Just a "legacy shortcut" for proto->GetSkill()
uint32 Item::GetSkill()
{
    ItemTemplate const* proto = GetTemplate();
    return proto->GetSkill();
}

void Item::SetItemRandomProperties(ItemRandomEnchantmentId const& randomPropId)
{
    if (!randomPropId.Id)
        return;

    switch (randomPropId.Type)
    {
        case ItemRandomEnchantmentType::Property:
            if (ItemRandomPropertiesEntry const* item_rand = sItemRandomPropertiesStore.LookupEntry(randomPropId.Id))
            {
                if (GetUInt32Value(ITEM_FIELD_RANDOM_PROPERTIES_ID) != randomPropId.Id)
                {
                    SetUInt32Value(ITEM_FIELD_RANDOM_PROPERTIES_ID, randomPropId.Id);
                    SetState(ITEM_CHANGED, GetOwner());
                }
                for (uint32 i = PROP_ENCHANTMENT_SLOT_0; i <= PROP_ENCHANTMENT_SLOT_4; ++i)
                    SetEnchantment(EnchantmentSlot(i), item_rand->Enchantment[i - PROP_ENCHANTMENT_SLOT_0], 0, 0);
            }
            break;
        case ItemRandomEnchantmentType::Suffix:
            if (ItemRandomSuffixEntry const* item_rand = sItemRandomSuffixStore.LookupEntry(randomPropId.Id))
            {
                if (GetInt32Value(ITEM_FIELD_RANDOM_PROPERTIES_ID) != -int32(randomPropId.Id) || !GetItemSuffixFactor())
                {
                    SetInt32Value(ITEM_FIELD_RANDOM_PROPERTIES_ID, -int32(randomPropId.Id));
                    UpdateItemSuffixFactor();
                    SetState(ITEM_CHANGED, GetOwner());
                }

                for (uint32 i = PROP_ENCHANTMENT_SLOT_0; i <= PROP_ENCHANTMENT_SLOT_4; ++i)
                    SetEnchantment(EnchantmentSlot(i), item_rand->Enchantment[i - PROP_ENCHANTMENT_SLOT_0], 0, 0);
            }
            break;
        case ItemRandomEnchantmentType::BonusList:
            AddBonuses(randomPropId.Id);
            break;
        default:
            break;
    }
}

void Item::UpdateItemSuffixFactor()
{
    if (!GetTemplate()->GetRandomSuffix())
        return;

    uint32 suffixFactor = 0;
    if (Player* owner = GetOwner())
        suffixFactor = GetRandomPropertyPoints(GetItemLevel(owner), GetQuality(), GetTemplate()->GetInventoryType(), GetTemplate()->GetSubClass());
    else
        suffixFactor = GenerateEnchSuffixFactor(GetEntry());

    if (GetItemSuffixFactor() == suffixFactor)
        return;
    SetUInt32Value(ITEM_FIELD_PROPERTY_SEED, suffixFactor);
}

void Item::SetState(ItemUpdateState state, Player* forplayer)
{
    if (uState == ITEM_NEW && state == ITEM_REMOVED)
    {
        // pretend the item never existed
        if (forplayer)
        {
            RemoveItemFromUpdateQueueOf(this, forplayer);
            forplayer->DeleteRefundReference(GetGUID());
        }
        delete this;
        return;
    }
    if (state != ITEM_UNCHANGED)
    {
        // new items must stay in new state until saved
        if (uState != ITEM_NEW)
            uState = state;

        if (forplayer)
            AddItemToUpdateQueueOf(this, forplayer);
    }
    else
    {
        // unset in queue
        // the item must be removed from the queue manually
        uQueuePos = -1;
        uState = ITEM_UNCHANGED;
    }
}

void AddItemToUpdateQueueOf(Item* item, Player* player)
{
    if (item->IsInUpdateQueue())
        return;

    ASSERT(player != NULL);

    if (player->GetGUID() != item->GetOwnerGUID())
    {
        TC_LOG_DEBUG("entities.player.items", "Item::AddToUpdateQueueOf - Owner's guid (%s) and player's guid (%s) don't match!",
            item->GetOwnerGUID().ToString().c_str(), player->GetGUID().ToString().c_str());
        return;
    }

    if (player->m_itemUpdateQueueBlocked)
        return;

    player->m_itemUpdateQueue.push_back(item);
    item->uQueuePos = player->m_itemUpdateQueue.size() - 1;
}

void RemoveItemFromUpdateQueueOf(Item* item, Player* player)
{
    if (!item->IsInUpdateQueue())
        return;

    ASSERT(player != NULL);

    if (player->GetGUID() != item->GetOwnerGUID())
    {
        TC_LOG_DEBUG("entities.player.items", "Item::RemoveFromUpdateQueueOf - Owner's guid (%s) and player's guid (%s) don't match!",
            item->GetOwnerGUID().ToString().c_str(), player->GetGUID().ToString().c_str());
        return;
    }

    if (player->m_itemUpdateQueueBlocked)
        return;

    player->m_itemUpdateQueue[item->uQueuePos] = nullptr;
    item->uQueuePos = -1;
}

uint8 Item::GetBagSlot() const
{
    return m_container ? m_container->GetSlot() : uint8(INVENTORY_SLOT_BAG_0);
}

bool Item::IsEquipped() const
{
    return !IsInBag() && m_slot < EQUIPMENT_SLOT_END;
}

bool Item::CanBeTraded(bool mail, bool trade) const
{
    if (m_lootGenerated)
        return false;

    if ((!mail || !IsBoundAccountWide()) && (IsSoulBound() && (!HasFlag(ITEM_FIELD_FLAGS, ITEM_FIELD_FLAG_BOP_TRADEABLE) || !trade)))
        return false;

    if (IsBag() && (Player::IsBagPos(GetPos()) || !ToBag()->IsEmpty()))
        return false;

    if (Player* owner = GetOwner())
    {
        if (owner->CanUnequipItem(GetPos(), false) != EQUIP_ERR_OK)
            return false;
        if (owner->GetLootGUID() == GetGUID())
            return false;
    }

    if (IsBoundByEnchant())
        return false;

    return true;
}

void Item::SetCount(uint32 value)
{
    SetUInt32Value(ITEM_FIELD_STACK_COUNT, value);

    if (Player* player = GetOwner())
    {
        if (TradeData* tradeData = player->GetTradeData())
        {
            TradeSlots slot = tradeData->GetTradeSlotForItem(GetGUID());

            if (slot != TRADE_SLOT_INVALID)
                tradeData->SetItem(slot, this, true);
        }
    }
}

bool Item::HasEnchantRequiredSkill(const Player* player) const
{
    // Check all enchants for required skill
    for (uint32 enchant_slot = PERM_ENCHANTMENT_SLOT; enchant_slot < MAX_ENCHANTMENT_SLOT; ++enchant_slot)
    {
        if (uint32 enchant_id = GetEnchantmentId(EnchantmentSlot(enchant_slot)))
            if (SpellItemEnchantmentEntry const* enchantEntry = sSpellItemEnchantmentStore.LookupEntry(enchant_id))
                if (enchantEntry->RequiredSkillID && player->GetSkillValue(enchantEntry->RequiredSkillID) < enchantEntry->RequiredSkillRank)
                    return false;
    }

  return true;
}

uint32 Item::GetEnchantRequiredLevel() const
{
    uint32 level = 0;

    // Check all enchants for required level
    for (uint32 enchant_slot = PERM_ENCHANTMENT_SLOT; enchant_slot < MAX_ENCHANTMENT_SLOT; ++enchant_slot)
    {
        if (uint32 enchant_id = GetEnchantmentId(EnchantmentSlot(enchant_slot)))
            if (SpellItemEnchantmentEntry const* enchantEntry = sSpellItemEnchantmentStore.LookupEntry(enchant_id))
                if (enchantEntry->MinLevel > level)
                    level = enchantEntry->MinLevel;
    }

    return level;
}

bool Item::IsBoundByEnchant() const
{
    // Check all enchants for soulbound
    for (uint32 enchant_slot = PERM_ENCHANTMENT_SLOT; enchant_slot < MAX_ENCHANTMENT_SLOT; ++enchant_slot)
        if (uint32 enchant_id = GetEnchantmentId(EnchantmentSlot(enchant_slot)))
            if (SpellItemEnchantmentEntry const* enchantEntry = sSpellItemEnchantmentStore.LookupEntry(enchant_id))
                if (enchantEntry->Flags & ENCHANTMENT_CAN_SOULBOUND)
                    return true;

    return false;
}

InventoryResult Item::CanBeMergedPartlyWith(ItemTemplate const* proto) const
{
    // not allow merge looting currently items
    if (m_lootGenerated)
        return EQUIP_ERR_LOOT_GONE;

    // check item type
    if (GetEntry() != proto->GetId())
        return EQUIP_ERR_CANT_STACK;

    // check free space (full stacks can't be target of merge
    if (GetCount() >= proto->GetMaxStackSize())
        return EQUIP_ERR_CANT_STACK;

    return EQUIP_ERR_OK;
}

bool Item::IsFitToSpellRequirements(SpellInfo const* spellInfo) const
{
    ItemTemplate const* proto = GetTemplate();

    bool isEnchantSpell = spellInfo->HasEffect(SPELL_EFFECT_ENCHANT_ITEM) || spellInfo->HasEffect(SPELL_EFFECT_ENCHANT_ITEM_TEMPORARY) || spellInfo->HasEffect(SPELL_EFFECT_ENCHANT_ITEM_PRISMATIC);
    if (spellInfo->EquippedItemClass != -1)                 // -1 == any item class
    {
        if (isEnchantSpell && proto->GetFlags3() & ITEM_FLAG3_CAN_STORE_ENCHANTS)
            return true;

        if (spellInfo->EquippedItemClass != int32(proto->GetClass()))
            return false;                                   //  wrong item class

        if (spellInfo->EquippedItemSubClassMask != 0)        // 0 == any subclass
        {
            if ((spellInfo->EquippedItemSubClassMask & (1 << proto->GetSubClass())) == 0)
                return false;                               // subclass not present in mask
        }
    }

    if (isEnchantSpell && spellInfo->EquippedItemInventoryTypeMask != 0)       // 0 == any inventory type
    {
        // Special case - accept weapon type for main and offhand requirements
        if (proto->GetInventoryType() == INVTYPE_WEAPON &&
            (spellInfo->EquippedItemInventoryTypeMask & (1 << INVTYPE_WEAPONMAINHAND) ||
             spellInfo->EquippedItemInventoryTypeMask & (1 << INVTYPE_WEAPONOFFHAND)))
            return true;
        else if ((spellInfo->EquippedItemInventoryTypeMask & (1 << proto->GetInventoryType())) == 0)
            return false;                                   // inventory type not present in mask
    }

    return true;
}

void Item::SetEnchantment(EnchantmentSlot slot, uint32 id, uint32 duration, uint32 charges, ObjectGuid caster /*= ObjectGuid::Empty*/)
{
    // Better lost small time at check in comparison lost time at item save to DB.
    if ((GetEnchantmentId(slot) == id) && (GetEnchantmentDuration(slot) == duration) && (GetEnchantmentCharges(slot) == charges))
        return;

    Player* owner = GetOwner();
    if (slot < MAX_INSPECTED_ENCHANTMENT_SLOT)
    {
        if (uint32 oldEnchant = GetEnchantmentId(slot))
            owner->GetSession()->SendEnchantmentLog(GetOwnerGUID(), ObjectGuid::Empty, GetEntry(), oldEnchant);

        if (id)
            owner->GetSession()->SendEnchantmentLog(GetOwnerGUID(), caster, GetEntry(), id);
    }

    ApplyArtifactPowerEnchantmentBonuses(slot, GetEnchantmentId(slot), false, owner);
    ApplyArtifactPowerEnchantmentBonuses(slot, id, true, owner);

    SetUInt32Value(ITEM_FIELD_ENCHANTMENT + slot * MAX_ENCHANTMENT_OFFSET + ENCHANTMENT_ID_OFFSET, id);
    SetUInt32Value(ITEM_FIELD_ENCHANTMENT + slot * MAX_ENCHANTMENT_OFFSET + ENCHANTMENT_DURATION_OFFSET, duration);
    SetUInt32Value(ITEM_FIELD_ENCHANTMENT + slot * MAX_ENCHANTMENT_OFFSET + ENCHANTMENT_CHARGES_OFFSET, charges);
    SetState(ITEM_CHANGED, owner);
}

void Item::SetEnchantmentDuration(EnchantmentSlot slot, uint32 duration, Player* owner)
{
    if (GetEnchantmentDuration(slot) == duration)
        return;

    SetUInt32Value(ITEM_FIELD_ENCHANTMENT + slot * MAX_ENCHANTMENT_OFFSET + ENCHANTMENT_DURATION_OFFSET, duration);
    SetState(ITEM_CHANGED, owner);
    // Cannot use GetOwner() here, has to be passed as an argument to avoid freeze due to hashtable locking
}

void Item::SetEnchantmentCharges(EnchantmentSlot slot, uint32 charges)
{
    if (GetEnchantmentCharges(slot) == charges)
        return;

    SetUInt32Value(ITEM_FIELD_ENCHANTMENT + slot*MAX_ENCHANTMENT_OFFSET + ENCHANTMENT_CHARGES_OFFSET, charges);
    SetState(ITEM_CHANGED, GetOwner());
}

void Item::ClearEnchantment(EnchantmentSlot slot)
{
    if (!GetEnchantmentId(slot))
        return;

    for (uint8 x = 0; x < MAX_ITEM_ENCHANTMENT_EFFECTS; ++x)
        SetUInt32Value(ITEM_FIELD_ENCHANTMENT + slot*MAX_ENCHANTMENT_OFFSET + x, 0);
    SetState(ITEM_CHANGED, GetOwner());
}

DynamicFieldStructuredView<ItemDynamicFieldGems> Item::GetGems() const
{
    return GetDynamicStructuredValues<ItemDynamicFieldGems>(ITEM_DYNAMIC_FIELD_GEMS);
}

ItemDynamicFieldGems const* Item::GetGem(uint16 slot) const
{
    ASSERT(slot < MAX_GEM_SOCKETS);
    return GetDynamicStructuredValue<ItemDynamicFieldGems>(ITEM_DYNAMIC_FIELD_GEMS, slot);
}

void Item::SetGem(uint16 slot, ItemDynamicFieldGems const* gem, uint32 gemScalingLevel)
{
    ASSERT(slot < MAX_GEM_SOCKETS);
    m_gemScalingLevels[slot] = gemScalingLevel;
    _bonusData.GemItemLevelBonus[slot] = 0;
    if (ItemTemplate const* gemTemplate = sObjectMgr->GetItemTemplate(gem->ItemId))
    {
        if (GemPropertiesEntry const* gemProperties = sGemPropertiesStore.LookupEntry(gemTemplate->GetGemProperties()))
        {
            if (SpellItemEnchantmentEntry const* gemEnchant = sSpellItemEnchantmentStore.LookupEntry(gemProperties->EnchantId))
            {
                BonusData gemBonus;
                gemBonus.Initialize(gemTemplate);
                for (uint16 bonusListId : gem->BonusListIDs)
                    if (DB2Manager::ItemBonusList const* bonuses = sDB2Manager.GetItemBonusList(bonusListId))
                        for (ItemBonusEntry const* itemBonus : *bonuses)
                            gemBonus.AddBonus(itemBonus->Type, itemBonus->Value);

                uint32 gemBaseItemLevel = gemTemplate->GetBaseItemLevel();
                if (ScalingStatDistributionEntry const* ssd = sScalingStatDistributionStore.LookupEntry(gemBonus.ScalingStatDistribution))
                    if (uint32 scaledIlvl = uint32(sDB2Manager.GetCurveValueAt(ssd->PlayerLevelToItemLevelCurveID, gemScalingLevel)))
                        gemBaseItemLevel = scaledIlvl;

                _bonusData.GemRelicType[slot] = gemBonus.RelicType;

                for (uint32 i = 0; i < MAX_ITEM_ENCHANTMENT_EFFECTS; ++i)
                {
                    switch (gemEnchant->Effect[i])
                    {
                        case ITEM_ENCHANTMENT_TYPE_BONUS_LIST_ID:
                        {
                            if (DB2Manager::ItemBonusList const* bonuses = sDB2Manager.GetItemBonusList(gemEnchant->EffectArg[i]))
                                for (ItemBonusEntry const* itemBonus : *bonuses)
                                    if (itemBonus->Type == ITEM_BONUS_ITEM_LEVEL)
                                        _bonusData.GemItemLevelBonus[slot] += itemBonus->Value[0];
                            break;
                        }
                        case ITEM_ENCHANTMENT_TYPE_BONUS_LIST_CURVE:
                        {
                            if (uint32 bonusListId = sDB2Manager.GetItemBonusListForItemLevelDelta(int16(sDB2Manager.GetCurveValueAt(CURVE_ID_ARTIFACT_RELIC_ITEM_LEVEL_BONUS, gemBaseItemLevel + gemBonus.ItemLevelBonus))))
                                if (DB2Manager::ItemBonusList const* bonuses = sDB2Manager.GetItemBonusList(bonusListId))
                                    for (ItemBonusEntry const* itemBonus : *bonuses)
                                        if (itemBonus->Type == ITEM_BONUS_ITEM_LEVEL)
                                            _bonusData.GemItemLevelBonus[slot] += itemBonus->Value[0];
                            break;
                        }
                        default:
                            break;
                    }
                }
            }
        }
    }

    SetDynamicStructuredValue(ITEM_DYNAMIC_FIELD_GEMS, slot, gem);
}

bool Item::GemsFitSockets() const
{
    uint32 gemSlot = 0;
    for (ItemDynamicFieldGems const& gemData : GetGems())
    {
        SocketColor color = GetTemplate()->GetSocketColor(gemSlot);
        if (!color) // no socket slot
            continue;

        uint32 GemColor = 0;

        ItemTemplate const* gemProto = sObjectMgr->GetItemTemplate(gemData.ItemId);
        if (gemProto)
        {
            GemPropertiesEntry const* gemProperty = sGemPropertiesStore.LookupEntry(gemProto->GetGemProperties());
            if (gemProperty)
                GemColor = gemProperty->Type;
        }

        if (!(GemColor & SocketColorToGemTypeMask[color])) // bad gem color on this socket
            return false;
    }
    return true;
}

uint8 Item::GetGemCountWithID(uint32 GemID) const
{
    return uint8(std::count_if(GetGems().begin(), GetGems().end(), [GemID](ItemDynamicFieldGems const& gemData)
    {
        return gemData.ItemId == GemID;
    }));
}

uint8 Item::GetGemCountWithLimitCategory(uint32 limitCategory) const
{
    return uint8(std::count_if(GetGems().begin(), GetGems().end(), [limitCategory](ItemDynamicFieldGems const& gemData)
    {
        ItemTemplate const* gemProto = sObjectMgr->GetItemTemplate(gemData.ItemId);
        if (!gemProto)
            return false;

        return gemProto->GetItemLimitCategory() == limitCategory;
    }));
}

bool Item::IsLimitedToAnotherMapOrZone(uint32 cur_mapId, uint32 cur_zoneId) const
{
    ItemTemplate const* proto = GetTemplate();
    return proto && ((proto->GetMap() && proto->GetMap() != cur_mapId) || (proto->GetArea() && proto->GetArea() != cur_zoneId));
}

void Item::SendUpdateSockets()
{
    WorldPackets::Item::SocketGemsResult socketGems;
    socketGems.Item = GetGUID();
    GetOwner()->GetSession()->SendPacket(socketGems.Write());
}

// Though the client has the information in the item's data field,
// we have to send SMSG_ITEM_TIME_UPDATE to display the remaining
// time.
void Item::SendTimeUpdate(Player* owner)
{
    uint32 duration = GetUInt32Value(ITEM_FIELD_DURATION);
    if (!duration)
        return;

    WorldPackets::Item::ItemTimeUpdate itemTimeUpdate;
    itemTimeUpdate.ItemGuid = GetGUID();
    itemTimeUpdate.DurationLeft = duration;
    owner->GetSession()->SendPacket(itemTimeUpdate.Write());
}

Item* Item::CreateItem(uint32 itemEntry, uint32 count, Player const* player /*= nullptr*/)
{
    if (count < 1)
        return nullptr;                                        //don't create item at zero count

    ItemTemplate const* proto = sObjectMgr->GetItemTemplate(itemEntry);
    if (proto)
    {
        if (count > proto->GetMaxStackSize())
            count = proto->GetMaxStackSize();

        ASSERT(count != 0, "proto->Stackable == 0 but checked at loading already");

        Item* item = NewItemOrBag(proto);
        if (item->Create(sObjectMgr->GetGenerator<HighGuid::Item>().Generate(), itemEntry, player))
        {
            item->SetCount(count);
            return item;
        }
        else
            delete item;
    }
    else
        ABORT();
    return nullptr;
}

Item* Item::CloneItem(uint32 count, Player const* player /*= nullptr*/) const
{
    Item* newItem = CreateItem(GetEntry(), count, player);
    if (!newItem)
        return nullptr;

    newItem->SetGuidValue(ITEM_FIELD_CREATOR, GetGuidValue(ITEM_FIELD_CREATOR));
    newItem->SetGuidValue(ITEM_FIELD_GIFTCREATOR, GetGuidValue(ITEM_FIELD_GIFTCREATOR));
    newItem->SetUInt32Value(ITEM_FIELD_FLAGS,        GetUInt32Value(ITEM_FIELD_FLAGS) & ~(ITEM_FIELD_FLAG_REFUNDABLE | ITEM_FIELD_FLAG_BOP_TRADEABLE));
    newItem->SetUInt32Value(ITEM_FIELD_DURATION,     GetUInt32Value(ITEM_FIELD_DURATION));
    // player CAN be NULL in which case we must not update random properties because that accesses player's item update queue
    if (player)
        newItem->SetItemRandomProperties(GetItemRandomEnchantmentId());
    return newItem;
}

bool Item::IsBindedNotWith(Player const* player) const
{
    // not binded item
    if (!IsSoulBound())
        return false;

    // own item
    if (GetOwnerGUID() == player->GetGUID())
        return false;

    if (HasFlag(ITEM_FIELD_FLAGS, ITEM_FIELD_FLAG_BOP_TRADEABLE))
        if (allowedGUIDs.find(player->GetGUID()) != allowedGUIDs.end())
            return false;

    // BOA item case
    if (IsBoundAccountWide())
        return false;

    return true;
}

void Item::BuildUpdate(UpdateDataMapType& data_map)
{
    if (Player* owner = GetOwner())
        BuildFieldsUpdate(owner, data_map);
    ClearUpdateMask(false);
}

void Item::BuildDynamicValuesUpdate(uint8 updateType, ByteBuffer* data, Player* target) const
{
    if (!target)
        return;

    std::size_t blockCount = UpdateMask::GetBlockCount(_dynamicValuesCount);

    uint32* flags = nullptr;
    uint32 visibleFlag = GetDynamicUpdateFieldData(target, flags);

    *data << uint8(blockCount);
    std::size_t maskPos = data->wpos();
    data->resize(data->size() + blockCount * sizeof(UpdateMask::BlockType));

    using DynamicFieldChangeTypeUT = std::underlying_type<UpdateMask::DynamicFieldChangeType>::type;

    for (uint16 index = 0; index < _dynamicValuesCount; ++index)
    {
        std::vector<uint32> const& values = _dynamicValues[index];
        if (_fieldNotifyFlags & flags[index] ||
            ((updateType == UPDATETYPE_VALUES ? _dynamicChangesMask[index] != UpdateMask::UNCHANGED : !values.empty()) && (flags[index] & visibleFlag)))
        {
            UpdateMask::SetUpdateBit(data->contents() + maskPos, index);

            std::size_t arrayBlockCount = UpdateMask::GetBlockCount(values.size());
            *data << DynamicFieldChangeTypeUT(UpdateMask::EncodeDynamicFieldChangeType(arrayBlockCount, _dynamicChangesMask[index], updateType));
            if (updateType == UPDATETYPE_VALUES && _dynamicChangesMask[index] == UpdateMask::VALUE_AND_SIZE_CHANGED)
                *data << uint32(values.size());

            std::size_t arrayMaskPos = data->wpos();
            data->resize(data->size() + arrayBlockCount * sizeof(UpdateMask::BlockType));
            if (index != ITEM_DYNAMIC_FIELD_MODIFIERS)
            {
                for (std::size_t v = 0; v < values.size(); ++v)
                {
                    if (updateType != UPDATETYPE_VALUES || _dynamicChangesArrayMask[index][v])
                    {
                        UpdateMask::SetUpdateBit(data->contents() + arrayMaskPos, v);
                        *data << uint32(values[v]);
                    }
                }
            }
            else
            {
                uint32 m = 0;

                // work around stupid item modifier field requirements - push back values mask by sizeof(m) bytes if size was not appended yet
                if (updateType == UPDATETYPE_VALUES && _dynamicChangesMask[index] != UpdateMask::VALUE_AND_SIZE_CHANGED && _changesMask[ITEM_FIELD_MODIFIERS_MASK])
                {
                    data->put(arrayMaskPos - sizeof(DynamicFieldChangeTypeUT), data->read<uint16>(arrayMaskPos - sizeof(DynamicFieldChangeTypeUT)) | UpdateMask::VALUE_AND_SIZE_CHANGED);
                    *data << m;
                    arrayMaskPos += sizeof(m);
                }

                // in case of ITEM_DYNAMIC_FIELD_MODIFIERS it is ITEM_FIELD_MODIFIERS_MASK that controls index of each value, not updatemask
                // so we just have to write this starting from 0 index
                for (std::size_t v = 0; v < values.size(); ++v)
                {
                    if (values[v])
                    {
                        UpdateMask::SetUpdateBit(data->contents() + arrayMaskPos, m++);
                        *data << uint32(values[v]);
                    }
                }

                if (updateType == UPDATETYPE_VALUES && _changesMask[ITEM_FIELD_MODIFIERS_MASK])
                    data->put(arrayMaskPos - sizeof(m), m);
            }
        }
    }
}

void Item::AddToObjectUpdate()
{
    if (Player* owner = GetOwner())
        owner->GetMap()->AddUpdateObject(this);
}

void Item::RemoveFromObjectUpdate()
{
    if (Player* owner = GetOwner())
        owner->GetMap()->RemoveUpdateObject(this);
}

void Item::SaveRefundDataToDB()
{
    SQLTransaction trans = CharacterDatabase.BeginTransaction();

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEM_REFUND_INSTANCE);
    stmt->setUInt64(0, GetGUID().GetCounter());
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_ITEM_REFUND_INSTANCE);
    stmt->setUInt64(0, GetGUID().GetCounter());
    stmt->setUInt64(1, GetRefundRecipient().GetCounter());
    stmt->setUInt64(2, GetPaidMoney());
    stmt->setUInt16(3, uint16(GetPaidExtendedCost()));
    trans->Append(stmt);

    CharacterDatabase.CommitTransaction(trans);
}

void Item::DeleteRefundDataFromDB(SQLTransaction* trans)
{
    if (trans)
    {
        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEM_REFUND_INSTANCE);
        stmt->setUInt64(0, GetGUID().GetCounter());
        (*trans)->Append(stmt);

    }
}

void Item::SetNotRefundable(Player* owner, bool changestate /*= true*/, SQLTransaction* trans /*= nullptr*/, bool addToCollection /*= true*/)
{
    if (!HasFlag(ITEM_FIELD_FLAGS, ITEM_FIELD_FLAG_REFUNDABLE))
        return;

    WorldPackets::Item::ItemExpirePurchaseRefund itemExpirePurchaseRefund;
    itemExpirePurchaseRefund.ItemGUID = GetGUID();
    owner->SendDirectMessage(itemExpirePurchaseRefund.Write());

    RemoveFlag(ITEM_FIELD_FLAGS, ITEM_FIELD_FLAG_REFUNDABLE);
    // Following is not applicable in the trading procedure
    if (changestate)
        SetState(ITEM_CHANGED, owner);

    SetRefundRecipient(ObjectGuid::Empty);
    SetPaidMoney(0);
    SetPaidExtendedCost(0);
    DeleteRefundDataFromDB(trans);

    owner->DeleteRefundReference(GetGUID());
    if (addToCollection)
        owner->GetSession()->GetCollectionMgr()->AddItemAppearance(this);
}

void Item::UpdatePlayedTime(Player* owner)
{
    /*  Here we update our played time
        We simply add a number to the current played time,
        based on the time elapsed since the last update hereof.
    */
    // Get current played time
    uint32 current_playtime = GetUInt32Value(ITEM_FIELD_CREATE_PLAYED_TIME);
    // Calculate time elapsed since last played time update
    time_t curtime = time(NULL);
    uint32 elapsed = uint32(curtime - m_lastPlayedTimeUpdate);
    uint32 new_playtime = current_playtime + elapsed;
    // Check if the refund timer has expired yet
    if (new_playtime <= 2*HOUR)
    {
        // No? Proceed.
        // Update the data field
        SetUInt32Value(ITEM_FIELD_CREATE_PLAYED_TIME, new_playtime);
        // Flag as changed to get saved to DB
        SetState(ITEM_CHANGED, owner);
        // Speaks for itself
        m_lastPlayedTimeUpdate = curtime;
        return;
    }
    // Yes
    SetNotRefundable(owner);
}

uint32 Item::GetPlayedTime()
{
    time_t curtime = time(NULL);
    uint32 elapsed = uint32(curtime - m_lastPlayedTimeUpdate);
    return GetUInt32Value(ITEM_FIELD_CREATE_PLAYED_TIME) + elapsed;
}

bool Item::IsRefundExpired()
{
    return (GetPlayedTime() > 2*HOUR);
}

void Item::SetSoulboundTradeable(GuidSet const& allowedLooters)
{
    SetFlag(ITEM_FIELD_FLAGS, ITEM_FIELD_FLAG_BOP_TRADEABLE);
    allowedGUIDs = allowedLooters;
}

void Item::ClearSoulboundTradeable(Player* currentOwner)
{
    RemoveFlag(ITEM_FIELD_FLAGS, ITEM_FIELD_FLAG_BOP_TRADEABLE);
    if (allowedGUIDs.empty())
        return;

    currentOwner->GetSession()->GetCollectionMgr()->AddItemAppearance(this);
    allowedGUIDs.clear();
    SetState(ITEM_CHANGED, currentOwner);
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEM_BOP_TRADE);
    stmt->setUInt64(0, GetGUID().GetCounter());
    CharacterDatabase.Execute(stmt);
}

bool Item::CheckSoulboundTradeExpire()
{
    // called from owner's update - GetOwner() MUST be valid
    if (GetUInt32Value(ITEM_FIELD_CREATE_PLAYED_TIME) + 2*HOUR < GetOwner()->GetTotalPlayedTime())
    {
        ClearSoulboundTradeable(GetOwner());
        return true; // remove from tradeable list
    }

    return false;
}

bool Item::IsValidTransmogrificationTarget() const
{
    ItemTemplate const* proto = GetTemplate();
    if (!proto)
        return false;

    if (proto->GetClass() != ITEM_CLASS_ARMOR &&
        proto->GetClass() != ITEM_CLASS_WEAPON)
        return false;

    if (proto->GetClass() == ITEM_CLASS_WEAPON && proto->GetSubClass() == ITEM_SUBCLASS_WEAPON_FISHING_POLE)
        return false;

    if (proto->GetFlags2() & ITEM_FLAG2_NO_ALTER_ITEM_VISUAL)
        return false;

    if (!HasStats())
        return false;

    return true;
}

bool Item::HasStats() const
{
    if (GetItemRandomPropertyId() != 0)
        return true;

    ItemTemplate const* proto = GetTemplate();
    Player const* owner = GetOwner();
    for (uint8 i = 0; i < MAX_ITEM_PROTO_STATS; ++i)
        if ((owner ? GetItemStatValue(i, owner) : proto->GetItemStatAllocation(i)) != 0)
            return true;

    return false;
}

bool Item::HasStats(WorldPackets::Item::ItemInstance const& itemInstance, BonusData const* bonus)
{
    if (itemInstance.RandomPropertiesID != 0)
        return true;

    for (uint8 i = 0; i < MAX_ITEM_PROTO_STATS; ++i)
        if (bonus->ItemStatAllocation[i] != 0)
            return true;

    return false;
}

enum class ItemTransmogrificationWeaponCategory : uint8
{
    // Two-handed
    MELEE_2H,
    RANGED,

    // One-handed
    AXE_MACE_SWORD_1H,
    DAGGER,
    FIST,

    INVALID
};

static ItemTransmogrificationWeaponCategory GetTransmogrificationWeaponCategory(ItemTemplate const* proto)
{
    if (proto->GetClass() == ITEM_CLASS_WEAPON)
    {
        switch (proto->GetSubClass())
        {
            case ITEM_SUBCLASS_WEAPON_AXE2:
            case ITEM_SUBCLASS_WEAPON_MACE2:
            case ITEM_SUBCLASS_WEAPON_SWORD2:
            case ITEM_SUBCLASS_WEAPON_STAFF:
            case ITEM_SUBCLASS_WEAPON_POLEARM:
                return ItemTransmogrificationWeaponCategory::MELEE_2H;
            case ITEM_SUBCLASS_WEAPON_BOW:
            case ITEM_SUBCLASS_WEAPON_GUN:
            case ITEM_SUBCLASS_WEAPON_CROSSBOW:
                return ItemTransmogrificationWeaponCategory::RANGED;
            case ITEM_SUBCLASS_WEAPON_AXE:
            case ITEM_SUBCLASS_WEAPON_MACE:
            case ITEM_SUBCLASS_WEAPON_SWORD:
            case ITEM_SUBCLASS_WEAPON_WARGLAIVES:
                return ItemTransmogrificationWeaponCategory::AXE_MACE_SWORD_1H;
            case ITEM_SUBCLASS_WEAPON_DAGGER:
                return ItemTransmogrificationWeaponCategory::DAGGER;
            case ITEM_SUBCLASS_WEAPON_FIST_WEAPON:
                return ItemTransmogrificationWeaponCategory::FIST;
            default:
                break;
        }
    }

    return ItemTransmogrificationWeaponCategory::INVALID;
}

int32 const ItemTransmogrificationSlots[MAX_INVTYPE] =
{
    -1,                                                     // INVTYPE_NON_EQUIP
    EQUIPMENT_SLOT_HEAD,                                    // INVTYPE_HEAD
    -1,                                                     // INVTYPE_NECK
    EQUIPMENT_SLOT_SHOULDERS,                               // INVTYPE_SHOULDERS
    EQUIPMENT_SLOT_BODY,                                    // INVTYPE_BODY
    EQUIPMENT_SLOT_CHEST,                                   // INVTYPE_CHEST
    EQUIPMENT_SLOT_WAIST,                                   // INVTYPE_WAIST
    EQUIPMENT_SLOT_LEGS,                                    // INVTYPE_LEGS
    EQUIPMENT_SLOT_FEET,                                    // INVTYPE_FEET
    EQUIPMENT_SLOT_WRISTS,                                  // INVTYPE_WRISTS
    EQUIPMENT_SLOT_HANDS,                                   // INVTYPE_HANDS
    -1,                                                     // INVTYPE_FINGER
    -1,                                                     // INVTYPE_TRINKET
    EQUIPMENT_SLOT_MAINHAND,                                // INVTYPE_WEAPON
    EQUIPMENT_SLOT_OFFHAND,                                 // INVTYPE_SHIELD
    EQUIPMENT_SLOT_MAINHAND,                                // INVTYPE_RANGED
    EQUIPMENT_SLOT_BACK,                                    // INVTYPE_CLOAK
    EQUIPMENT_SLOT_MAINHAND,                                // INVTYPE_2HWEAPON
    -1,                                                     // INVTYPE_BAG
    EQUIPMENT_SLOT_TABARD,                                  // INVTYPE_TABARD
    EQUIPMENT_SLOT_CHEST,                                   // INVTYPE_ROBE
    EQUIPMENT_SLOT_MAINHAND,                                // INVTYPE_WEAPONMAINHAND
    EQUIPMENT_SLOT_MAINHAND,                                // INVTYPE_WEAPONOFFHAND
    EQUIPMENT_SLOT_OFFHAND,                                 // INVTYPE_HOLDABLE
    -1,                                                     // INVTYPE_AMMO
    -1,                                                     // INVTYPE_THROWN
    EQUIPMENT_SLOT_MAINHAND,                                // INVTYPE_RANGEDRIGHT
    -1,                                                     // INVTYPE_QUIVER
    -1                                                      // INVTYPE_RELIC
};

bool Item::CanTransmogrifyItemWithItem(Item const* item, ItemModifiedAppearanceEntry const* itemModifiedAppearance)
{
    ItemTemplate const* source = sObjectMgr->GetItemTemplate(itemModifiedAppearance->ItemID); // source
    ItemTemplate const* target = item->GetTemplate(); // dest

    if (!source || !target)
        return false;

    if (itemModifiedAppearance == item->GetItemModifiedAppearance())
        return false;

    if (!item->IsValidTransmogrificationTarget())
        return false;

    if (source->GetClass() != target->GetClass())
        return false;

    if (source->GetInventoryType() == INVTYPE_BAG ||
        source->GetInventoryType() == INVTYPE_RELIC ||
        source->GetInventoryType() == INVTYPE_FINGER ||
        source->GetInventoryType() == INVTYPE_TRINKET ||
        source->GetInventoryType() == INVTYPE_AMMO ||
        source->GetInventoryType() == INVTYPE_QUIVER)
        return false;

    if (source->GetSubClass() != target->GetSubClass())
    {
        switch (source->GetClass())
        {
            case ITEM_CLASS_WEAPON:
                if (GetTransmogrificationWeaponCategory(source) != GetTransmogrificationWeaponCategory(target))
                    return false;
                break;
            case ITEM_CLASS_ARMOR:
                if (source->GetSubClass() != ITEM_SUBCLASS_ARMOR_COSMETIC)
                    return false;
                if (source->GetInventoryType() != target->GetInventoryType())
                    if (ItemTransmogrificationSlots[source->GetInventoryType()] != ItemTransmogrificationSlots[target->GetInventoryType()])
                        return false;
                break;
            default:
                return false;
        }
    }

    return true;
}

uint32 Item::GetBuyPrice(Player const* owner, bool& standardPrice) const
{
    return Item::GetBuyPrice(GetTemplate(), GetQuality(), GetItemLevel(owner), standardPrice);
}

uint32 Item::GetBuyPrice(ItemTemplate const* proto, uint32 quality, uint32 itemLevel, bool& standardPrice)
{
    standardPrice = false;

    if (proto->GetFlags2() & ITEM_FLAG2_OVERRIDE_GOLD_COST)
        return proto->GetBuyPrice();

    ImportPriceQualityEntry const* qualityPrice = sImportPriceQualityStore.LookupEntry(quality + 1);
    if (!qualityPrice)
        return 0;

    ItemPriceBaseEntry const* basePrice = sItemPriceBaseStore.LookupEntry(itemLevel);
    if (!basePrice)
        return 0;

    float qualityFactor = qualityPrice->Data;
    float baseFactor = 0.0f;

    uint32 inventoryType = proto->GetInventoryType();

    if (inventoryType == INVTYPE_WEAPON ||
        inventoryType == INVTYPE_2HWEAPON ||
        inventoryType == INVTYPE_WEAPONMAINHAND ||
        inventoryType == INVTYPE_WEAPONOFFHAND ||
        inventoryType == INVTYPE_RANGED ||
        inventoryType == INVTYPE_THROWN ||
        inventoryType == INVTYPE_RANGEDRIGHT)
        baseFactor = basePrice->Weapon;
    else
        baseFactor = basePrice->Armor;

    if (inventoryType == INVTYPE_ROBE)
        inventoryType = INVTYPE_CHEST;

    if (proto->GetClass() == ITEM_CLASS_GEM && proto->GetSubClass() == ITEM_SUBCLASS_GEM_ARTIFACT_RELIC)
    {
        inventoryType = INVTYPE_WEAPON;
        baseFactor = basePrice->Weapon / 3.0f;
    }

    float typeFactor = 0.0f;
    int8 weapType = -1;

    switch (inventoryType)
    {
        case INVTYPE_HEAD:
        case INVTYPE_NECK:
        case INVTYPE_SHOULDERS:
        case INVTYPE_CHEST:
        case INVTYPE_WAIST:
        case INVTYPE_LEGS:
        case INVTYPE_FEET:
        case INVTYPE_WRISTS:
        case INVTYPE_HANDS:
        case INVTYPE_FINGER:
        case INVTYPE_TRINKET:
        case INVTYPE_CLOAK:
        case INVTYPE_HOLDABLE:
        {
            ImportPriceArmorEntry const* armorPrice = sImportPriceArmorStore.LookupEntry(inventoryType);
            if (!armorPrice)
                return 0;

            switch (proto->GetSubClass())
            {
                case ITEM_SUBCLASS_ARMOR_MISCELLANEOUS:
                case ITEM_SUBCLASS_ARMOR_CLOTH:
                    typeFactor = armorPrice->ClothModifier;
                    break;
                case ITEM_SUBCLASS_ARMOR_LEATHER:
                    typeFactor = armorPrice->LeatherModifier;
                    break;
                case ITEM_SUBCLASS_ARMOR_MAIL:
                    typeFactor = armorPrice->ChainModifier;
                    break;
                case ITEM_SUBCLASS_ARMOR_PLATE:
                    typeFactor = armorPrice->PlateModifier;
                    break;
                default:
                    typeFactor = 1.0f;
                    break;
            }

            break;
        }
        case INVTYPE_SHIELD:
        {
            ImportPriceShieldEntry const* shieldPrice = sImportPriceShieldStore.LookupEntry(2);
            if (!shieldPrice)
                return 0;

            typeFactor = shieldPrice->Data;
            break;
        }
        case INVTYPE_WEAPONMAINHAND:
            weapType = 0;
            break;
        case INVTYPE_WEAPONOFFHAND:
            weapType = 1;
            break;
        case INVTYPE_WEAPON:
            weapType = 2;
            break;
        case INVTYPE_2HWEAPON:
            weapType = 3;
            break;
        case INVTYPE_RANGED:
        case INVTYPE_RANGEDRIGHT:
        case INVTYPE_RELIC:
            weapType = 4;
            break;
        default:
            return proto->GetBuyPrice();
    }

    if (weapType != -1)
    {
        ImportPriceWeaponEntry const* weaponPrice = sImportPriceWeaponStore.LookupEntry(weapType + 1);
        if (!weaponPrice)
            return 0;

        typeFactor = weaponPrice->Data;
    }

    standardPrice = false;
    return uint32(proto->GetPriceVariance() * typeFactor * baseFactor * qualityFactor * proto->GetPriceRandomValue());
}

uint32 Item::GetSellPrice(Player const* owner) const
{
    return Item::GetSellPrice(GetTemplate(), GetQuality(), GetItemLevel(owner));
}

uint32 Item::GetSellPrice(ItemTemplate const* proto, uint32 quality, uint32 itemLevel)
{
    if (proto->GetFlags2() & ITEM_FLAG2_OVERRIDE_GOLD_COST)
        return proto->GetSellPrice();
    else
    {
        bool standardPrice;
        uint32 cost = Item::GetBuyPrice(proto, quality, itemLevel, standardPrice);

        if (standardPrice)
        {
            if (ItemClassEntry const* classEntry = sDB2Manager.GetItemClassByOldEnum(proto->GetClass()))
            {
                uint32 buyCount = std::max(proto->GetBuyCount(), 1u);
                return cost * classEntry->PriceModifier / buyCount;
            }

            return 0;
        }
        else
            return proto->GetSellPrice();
    }

    return 0;
}

void Item::ItemContainerSaveLootToDB()
{
    // Saves the money and item loot associated with an openable item to the DB
    if (loot.isLooted()) // no money and no loot
        return;

    SQLTransaction trans = CharacterDatabase.BeginTransaction();

    loot.containerID = GetGUID(); // Save this for when a LootItem is removed

    // Save money
    if (loot.gold > 0)
    {
        PreparedStatement* stmt_money = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEMCONTAINER_MONEY);
        stmt_money->setUInt64(0, loot.containerID.GetCounter());
        trans->Append(stmt_money);

        stmt_money = CharacterDatabase.GetPreparedStatement(CHAR_INS_ITEMCONTAINER_MONEY);
        stmt_money->setUInt64(0, loot.containerID.GetCounter());
        stmt_money->setUInt32(1, loot.gold);
        trans->Append(stmt_money);
    }

    // Save items
    if (!loot.isLooted())
    {
        PreparedStatement* stmt_items = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEMCONTAINER_ITEMS);
        stmt_items->setUInt64(0, loot.containerID.GetCounter());
        trans->Append(stmt_items);

        // Now insert the items
        for (LootItemList::const_iterator _li = loot.items.begin(); _li != loot.items.end(); ++_li)
        {
            // When an item is looted, it doesn't get removed from the items collection
            //  but we don't want to resave it.
            if (!_li->canSave)
                continue;
            // Conditions are not checked when loot is generated, it is checked when loot is sent to a player.
            // For items that are lootable, loot is saved to the DB immediately, that means that loot can be
            // saved to the DB that the player never should have gotten. This check prevents that, so that only
            // items that the player should get in loot are in the DB.
            // IE: Horde items are not saved to the DB for Ally players.
            Player* const guid = GetOwner();
            if (!_li->AllowedForPlayer(guid))
               continue;

            stmt_items = CharacterDatabase.GetPreparedStatement(CHAR_INS_ITEMCONTAINER_ITEMS);

            // container_id, item_id, item_count, follow_rules, ffa, blocked, counted, under_threshold, needs_quest, rnd_type, rnd_prop, rnd_suffix, context, bonus_list_ids
            stmt_items->setUInt64(0, loot.containerID.GetCounter());
            stmt_items->setUInt32(1, _li->itemid);
            stmt_items->setUInt32(2, _li->count);
            stmt_items->setBool(3, _li->follow_loot_rules);
            stmt_items->setBool(4, _li->freeforall);
            stmt_items->setBool(5, _li->is_blocked);
            stmt_items->setBool(6, _li->is_counted);
            stmt_items->setBool(7, _li->is_underthreshold);
            stmt_items->setBool(8, _li->needs_quest);
            stmt_items->setUInt8(9, uint8(_li->randomPropertyId.Type));
            stmt_items->setUInt32(10, _li->randomPropertyId.Id);
            stmt_items->setUInt32(11, _li->randomSuffix);
            stmt_items->setUInt8(12, _li->context);
            std::ostringstream bonusListIDs;
            for (int32 bonusListID : _li->BonusListIDs)
                bonusListIDs << bonusListID << ' ';
            stmt_items->setString(13, bonusListIDs.str());
            trans->Append(stmt_items);
        }
    }

    CharacterDatabase.CommitTransaction(trans);
}

bool Item::ItemContainerLoadLootFromDB()
{
    // Loads the money and item loot associated with an openable item from the DB
    // Default. If there are no records for this item then it will be rolled for in Player::SendLoot()
    m_lootGenerated = false;

    // Save this for later use
    loot.containerID = GetGUID();

    // First, see if there was any money loot. This gets added directly to the container.
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_ITEMCONTAINER_MONEY);
    stmt->setUInt64(0, loot.containerID.GetCounter());
    PreparedQueryResult money_result = CharacterDatabase.Query(stmt);

    if (money_result)
    {
        Field* fields = money_result->Fetch();
        loot.gold = fields[0].GetUInt32();
    }

    // Next, load any items that were saved
    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_ITEMCONTAINER_ITEMS);
    stmt->setUInt64(0, loot.containerID.GetCounter());
    PreparedQueryResult item_result = CharacterDatabase.Query(stmt);

    if (item_result)
    {
        // Get a LootTemplate for the container item. This is where
        //  the saved loot was originally rolled from, we will copy conditions from it
        LootTemplate const* lt = LootTemplates_Item.GetLootFor(GetEntry());
        if (lt)
        {
            do
            {
                // Create an empty LootItem
                LootItem loot_item = LootItem();

                // Fill in the rest of the LootItem from the DB
                Field* fields = item_result->Fetch();

                // item_id, itm_count, follow_rules, ffa, blocked, counted, under_threshold, needs_quest, rnd_type, rnd_prop, rnd_suffix, context, bonus_list_ids
                loot_item.itemid = fields[0].GetUInt32();
                loot_item.count = fields[1].GetUInt32();
                loot_item.follow_loot_rules = fields[2].GetBool();
                loot_item.freeforall = fields[3].GetBool();
                loot_item.is_blocked = fields[4].GetBool();
                loot_item.is_counted = fields[5].GetBool();
                loot_item.canSave = true;
                loot_item.is_underthreshold = fields[6].GetBool();
                loot_item.needs_quest = fields[7].GetBool();
                loot_item.randomPropertyId = { ItemRandomEnchantmentType(fields[8].GetUInt8()), fields[9].GetUInt32() };
                loot_item.randomSuffix = fields[10].GetUInt32();
                loot_item.context = fields[11].GetUInt8();
                Tokenizer bonusLists(fields[12].GetString(), ' ');
                std::transform(bonusLists.begin(), bonusLists.end(), std::back_inserter(loot_item.BonusListIDs), [](char const* token)
                {
                    return int32(strtol(token, NULL, 10));
                });

                // Copy the extra loot conditions from the item in the loot template
                lt->CopyConditions(&loot_item);

                // If container item is in a bag, add that player as an allowed looter
                if (GetBagSlot())
                    loot_item.AddAllowedLooter(GetOwner());

                // Finally add the LootItem to the container
                loot.items.push_back(loot_item);

                // Increment unlooted count
                loot.unlootedCount++;

            }
            while (item_result->NextRow());
        }
    }

    // Mark the item if it has loot so it won't be generated again on open
    m_lootGenerated = !loot.isLooted();

    return m_lootGenerated;
}

void Item::ItemContainerDeleteLootItemsFromDB()
{
    // Deletes items associated with an openable item from the DB
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEMCONTAINER_ITEMS);
    stmt->setUInt64(0, GetGUID().GetCounter());
    CharacterDatabase.Execute(stmt);
}

void Item::ItemContainerDeleteLootItemFromDB(uint32 itemID)
{
    // Deletes a single item associated with an openable item from the DB
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEMCONTAINER_ITEM);
    stmt->setUInt64(0, GetGUID().GetCounter());
    stmt->setUInt32(1, itemID);
    CharacterDatabase.Execute(stmt);
}

void Item::ItemContainerDeleteLootMoneyFromDB()
{
    // Deletes the money loot associated with an openable item from the DB
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEMCONTAINER_MONEY);
    stmt->setUInt64(0, GetGUID().GetCounter());
    CharacterDatabase.Execute(stmt);
}

void Item::ItemContainerDeleteLootMoneyAndLootItemsFromDB()
{
    // Deletes money and items associated with an openable item from the DB
    ItemContainerDeleteLootMoneyFromDB();
    ItemContainerDeleteLootItemsFromDB();
}

uint32 Item::GetItemLevel(Player const* owner) const
{
    uint32 minItemLevel = owner->GetUInt32Value(UNIT_FIELD_MIN_ITEM_LEVEL);
    uint32 minItemLevelCutoff = owner->GetUInt32Value(UNIT_FIELD_MIN_ITEM_LEVEL_CUTOFF);
    uint32 maxItemLevel = GetTemplate()->GetFlags3() & ITEM_FLAG3_IGNORE_ITEM_LEVEL_CAP_IN_PVP ? 0 : owner->GetUInt32Value(UNIT_FIELD_MAXITEMLEVEL);
    bool pvpBonus = owner->IsUsingPvpItemLevels();
    return Item::GetItemLevel(GetTemplate(), _bonusData, owner->getLevel(), GetModifier(ITEM_MODIFIER_SCALING_STAT_DISTRIBUTION_FIXED_LEVEL), GetModifier(ITEM_MODIFIER_UPGRADE_ID),
        minItemLevel, minItemLevelCutoff, maxItemLevel, pvpBonus);
}

uint32 Item::GetItemLevel(ItemTemplate const* itemTemplate, BonusData const& bonusData, uint32 level, uint32 fixedLevel, uint32 upgradeId,
    uint32 minItemLevel, uint32 minItemLevelCutoff, uint32 maxItemLevel, bool pvpBonus)
{
    if (!itemTemplate)
        return MIN_ITEM_LEVEL;

    uint32 itemLevel = itemTemplate->GetBaseItemLevel();
    if (ScalingStatDistributionEntry const* ssd = sScalingStatDistributionStore.LookupEntry(bonusData.ScalingStatDistribution))
    {
        if (fixedLevel)
            level = fixedLevel;
        else
            level = std::min(std::max(int32(level), ssd->MinLevel), ssd->MaxLevel);

        if (ContentTuningEntry const* contentTuning = sContentTuningStore.LookupEntry(bonusData.ContentTuningId))
            if ((contentTuning->Flags & 2 || contentTuning->MinLevel || contentTuning->MaxLevel) && !(contentTuning->Flags & 4))
                level = std::min(std::max(int32(level), contentTuning->MinLevel), contentTuning->MaxLevel);

        if (uint32 heirloomIlvl = uint32(sDB2Manager.GetCurveValueAt(ssd->PlayerLevelToItemLevelCurveID, level)))
            itemLevel = heirloomIlvl;
    }

    itemLevel += bonusData.ItemLevelBonus;

    for (uint32 i = 0; i < MAX_ITEM_PROTO_SOCKETS; ++i)
        itemLevel += bonusData.GemItemLevelBonus[i];

    uint32 itemLevelBeforeUpgrades = itemLevel;
    if (ItemUpgradeEntry const* upgrade = sItemUpgradeStore.LookupEntry(upgradeId))
        itemLevel += upgrade->ItemLevelIncrement;

    if (pvpBonus)
        itemLevel += sDB2Manager.GetPvpItemLevelBonus(itemTemplate->GetId());

    if (itemTemplate->GetInventoryType() != INVTYPE_NON_EQUIP)
    {
        if (minItemLevel && (!minItemLevelCutoff || itemLevelBeforeUpgrades >= minItemLevelCutoff) && itemLevel < minItemLevel)
            itemLevel = minItemLevel;

        if (maxItemLevel && itemLevel > maxItemLevel)
            itemLevel = maxItemLevel;
    }

    return std::min(std::max(itemLevel, uint32(MIN_ITEM_LEVEL)), uint32(MAX_ITEM_LEVEL));
}

int32 Item::GetItemStatValue(uint32 index, Player const* owner) const
{
    ASSERT(index < MAX_ITEM_PROTO_STATS);
    uint32 itemLevel = GetItemLevel(owner);
    if (uint32 randomPropPoints = GetRandomPropertyPoints(itemLevel, GetQuality(), GetTemplate()->GetInventoryType(), GetTemplate()->GetSubClass()))
    {
        float statValue = float(_bonusData.ItemStatAllocation[index] * randomPropPoints) * 0.0001f;
        if (GtItemSocketCostPerLevelEntry const* gtCost = sItemSocketCostPerLevelGameTable.GetRow(itemLevel))
            statValue -= float(int32(_bonusData.ItemStatSocketCostMultiplier[index] * gtCost->SocketCost));

        return int32(std::floor(statValue + 0.5f));
    }

    return 0;
}

ItemDisenchantLootEntry const* Item::GetDisenchantLoot(Player const* owner) const
{
    return Item::GetDisenchantLoot(GetTemplate(), GetQuality(), GetItemLevel(owner));
}

ItemDisenchantLootEntry const* Item::GetDisenchantLoot(ItemTemplate const* itemTemplate, uint32 quality, uint32 itemLevel)
{
    if (itemTemplate->GetFlags() & (ITEM_FLAG_CONJURED | ITEM_FLAG_NO_DISENCHANT) || itemTemplate->GetBonding() == BIND_QUEST)
        return nullptr;

    if (itemTemplate->GetArea() || itemTemplate->GetMap() || itemTemplate->GetMaxStackSize() > 1)
        return nullptr;

    if (!Item::GetSellPrice(itemTemplate, quality, itemLevel) && !sDB2Manager.HasItemCurrencyCost(itemTemplate->GetId()))
        return nullptr;

    uint32 itemClass = itemTemplate->GetClass();
    int8 itemSubClass = itemTemplate->GetSubClass();
    uint8 expansion = itemTemplate->GetRequiredExpansion();
    for (ItemDisenchantLootEntry const* disenchant : sItemDisenchantLootStore)
    {
        if (disenchant->Class != itemClass)
            continue;

        if (disenchant->Subclass >= 0 && itemSubClass)
            continue;

        if (disenchant->Quality != quality)
            continue;

        if (disenchant->MinLevel > itemLevel || disenchant->MaxLevel < itemLevel)
            continue;

        if (disenchant->ExpansionID != -2 && disenchant->ExpansionID != expansion)
            continue;

        return disenchant;
    }

    return nullptr;
}

uint32 Item::GetDisplayId(Player const* owner) const
{
    ItemModifier transmogModifier = ITEM_MODIFIER_TRANSMOG_APPEARANCE_ALL_SPECS;
    if (HasFlag(ITEM_FIELD_MODIFIERS_MASK, AppearanceModifierMaskSpecSpecific))
        transmogModifier = AppearanceModifierSlotBySpec[owner->GetActiveTalentGroup()];

    if (ItemModifiedAppearanceEntry const* transmog = sItemModifiedAppearanceStore.LookupEntry(GetModifier(transmogModifier)))
        if (ItemAppearanceEntry const* itemAppearance = sItemAppearanceStore.LookupEntry(transmog->ItemAppearanceID))
            return itemAppearance->ItemDisplayInfoID;

    return sDB2Manager.GetItemDisplayId(GetEntry(), GetAppearanceModId());
}

ItemModifiedAppearanceEntry const* Item::GetItemModifiedAppearance() const
{
    return sDB2Manager.GetItemModifiedAppearance(GetEntry(), _bonusData.AppearanceModID);
}

uint32 Item::GetModifier(ItemModifier modifier) const
{
    return GetDynamicValue(ITEM_DYNAMIC_FIELD_MODIFIERS, modifier);
}

void Item::SetModifier(ItemModifier modifier, uint32 value)
{
    ApplyModFlag(ITEM_FIELD_MODIFIERS_MASK, 1 << modifier, value != 0);
    SetDynamicValue(ITEM_DYNAMIC_FIELD_MODIFIERS, modifier, value);
}

uint32 Item::GetVisibleEntry(Player const* owner) const
{
    ItemModifier transmogModifier = ITEM_MODIFIER_TRANSMOG_APPEARANCE_ALL_SPECS;
    if (HasFlag(ITEM_FIELD_MODIFIERS_MASK, AppearanceModifierMaskSpecSpecific))
        transmogModifier = AppearanceModifierSlotBySpec[owner->GetActiveTalentGroup()];

    if (ItemModifiedAppearanceEntry const* transmog = sItemModifiedAppearanceStore.LookupEntry(GetModifier(transmogModifier)))
        return transmog->ItemID;

    return GetEntry();
}

uint16 Item::GetVisibleAppearanceModId(Player const* owner) const
{
    ItemModifier transmogModifier = ITEM_MODIFIER_TRANSMOG_APPEARANCE_ALL_SPECS;
    if (HasFlag(ITEM_FIELD_MODIFIERS_MASK, AppearanceModifierMaskSpecSpecific))
        transmogModifier = AppearanceModifierSlotBySpec[owner->GetActiveTalentGroup()];

    if (ItemModifiedAppearanceEntry const* transmog = sItemModifiedAppearanceStore.LookupEntry(GetModifier(transmogModifier)))
        return transmog->ItemAppearanceModifierID;

    return uint16(GetAppearanceModId());
}

uint32 Item::GetVisibleEnchantmentId(Player const* owner) const
{
    ItemModifier illusionModifier = ITEM_MODIFIER_ENCHANT_ILLUSION_ALL_SPECS;
    if (HasFlag(ITEM_FIELD_MODIFIERS_MASK, IllusionModifierMaskSpecSpecific))
        illusionModifier = IllusionModifierSlotBySpec[owner->GetActiveTalentGroup()];

    if (uint32 enchantIllusion = GetModifier(illusionModifier))
        return enchantIllusion;

    return GetEnchantmentId(PERM_ENCHANTMENT_SLOT);
}

uint16 Item::GetVisibleItemVisual(Player const* owner) const
{
    if (SpellItemEnchantmentEntry const* enchant = sSpellItemEnchantmentStore.LookupEntry(GetVisibleEnchantmentId(owner)))
        return enchant->ItemVisual;

    return 0;
}

void Item::AddBonuses(uint32 bonusListID)
{
    if (HasDynamicValue(ITEM_DYNAMIC_FIELD_BONUSLIST_IDS, bonusListID))
        return;

    if (DB2Manager::ItemBonusList const* bonuses = sDB2Manager.GetItemBonusList(bonusListID))
    {
        AddDynamicValue(ITEM_DYNAMIC_FIELD_BONUSLIST_IDS, bonusListID);
        for (ItemBonusEntry const* bonus : *bonuses)
            _bonusData.AddBonus(bonus->Type, bonus->Value);
        SetUInt32Value(ITEM_FIELD_APPEARANCE_MOD_ID, _bonusData.AppearanceModID);
    }
}

DynamicFieldStructuredView<ItemDynamicFieldArtifactPowers> Item::GetArtifactPowers() const
{
    return GetDynamicStructuredValues<ItemDynamicFieldArtifactPowers>(ITEM_DYNAMIC_FIELD_ARTIFACT_POWERS);
}

ItemDynamicFieldArtifactPowers const* Item::GetArtifactPower(uint32 artifactPowerId) const
{
    auto indexItr = m_artifactPowerIdToIndex.find(artifactPowerId);
    if (indexItr != m_artifactPowerIdToIndex.end())
        return GetDynamicStructuredValue<ItemDynamicFieldArtifactPowers>(ITEM_DYNAMIC_FIELD_ARTIFACT_POWERS, indexItr->second);

    return nullptr;
}

void Item::SetArtifactPower(ItemDynamicFieldArtifactPowers const* artifactPower, bool createIfMissing /*= false*/)
{
    auto indexItr = m_artifactPowerIdToIndex.find(artifactPower->ArtifactPowerId);
    uint16 index;
    if (indexItr != m_artifactPowerIdToIndex.end())
        index = indexItr->second;
    else
    {
        if (!createIfMissing)
            return;

        index = uint16(m_artifactPowerIdToIndex.size());
        m_artifactPowerIdToIndex[artifactPower->ArtifactPowerId] = index;
    }

    SetDynamicStructuredValue(ITEM_DYNAMIC_FIELD_ARTIFACT_POWERS, index, artifactPower);
}

void Item::InitArtifactPowers(uint8 artifactId, uint8 artifactTier)
{
    for (ArtifactPowerEntry const* artifactPower : sDB2Manager.GetArtifactPowers(artifactId))
    {
        if (artifactPower->Tier != artifactTier)
            continue;

        if (m_artifactPowerIdToIndex.find(artifactPower->ID) != m_artifactPowerIdToIndex.end())
            continue;

        ItemDynamicFieldArtifactPowers powerData;
        memset(&powerData, 0, sizeof(powerData));
        powerData.ArtifactPowerId = artifactPower->ID;
        powerData.PurchasedRank = 0;
        powerData.CurrentRankWithBonus = (artifactPower->Flags & ARTIFACT_POWER_FLAG_FIRST) == ARTIFACT_POWER_FLAG_FIRST ? 1 : 0;
        SetArtifactPower(&powerData, true);
    }
}

uint32 Item::GetTotalPurchasedArtifactPowers() const
{
    uint32 purchasedRanks = 0;
    for (ItemDynamicFieldArtifactPowers const& power : GetArtifactPowers())
        purchasedRanks += power.PurchasedRank;

    return purchasedRanks;
}

void Item::ApplyArtifactPowerEnchantmentBonuses(EnchantmentSlot slot, uint32 enchantId, bool apply, Player* owner)
{
    if (SpellItemEnchantmentEntry const* enchant = sSpellItemEnchantmentStore.LookupEntry(enchantId))
    {
        for (uint32 i = 0; i < MAX_ITEM_ENCHANTMENT_EFFECTS; ++i)
        {
            switch (enchant->Effect[i])
            {
                case ITEM_ENCHANTMENT_TYPE_ARTIFACT_POWER_BONUS_RANK_BY_TYPE:
                    for (ItemDynamicFieldArtifactPowers const& artifactPower : GetArtifactPowers())
                    {
                        if (uint32(sArtifactPowerStore.AssertEntry(artifactPower.ArtifactPowerId)->Label) == enchant->EffectArg[i])
                        {
                            ItemDynamicFieldArtifactPowers newPower = artifactPower;
                            if (apply)
                                newPower.CurrentRankWithBonus += enchant->EffectPointsMin[i];
                            else
                                newPower.CurrentRankWithBonus -= enchant->EffectPointsMin[i];

                            if (IsEquipped())
                                if (ArtifactPowerRankEntry const* artifactPowerRank = sDB2Manager.GetArtifactPowerRank(artifactPower.ArtifactPowerId, newPower.CurrentRankWithBonus ? newPower.CurrentRankWithBonus - 1 : 0))
                                    owner->ApplyArtifactPowerRank(this, artifactPowerRank, newPower.CurrentRankWithBonus != 0);

                            SetArtifactPower(&newPower);
                        }
                    }
                    break;
                case ITEM_ENCHANTMENT_TYPE_ARTIFACT_POWER_BONUS_RANK_BY_ID:
                    if (ItemDynamicFieldArtifactPowers const* artifactPower = GetArtifactPower(enchant->EffectArg[i]))
                    {
                        ItemDynamicFieldArtifactPowers newPower = *artifactPower;
                        if (apply)
                            newPower.CurrentRankWithBonus += enchant->EffectPointsMin[i];
                        else
                            newPower.CurrentRankWithBonus -= enchant->EffectPointsMin[i];

                        if (IsEquipped())
                            if (ArtifactPowerRankEntry const* artifactPowerRank = sDB2Manager.GetArtifactPowerRank(artifactPower->ArtifactPowerId, newPower.CurrentRankWithBonus ? newPower.CurrentRankWithBonus - 1 : 0))
                                owner->ApplyArtifactPowerRank(this, artifactPowerRank, newPower.CurrentRankWithBonus != 0);

                        SetArtifactPower(&newPower);
                    }
                    break;
                case ITEM_ENCHANTMENT_TYPE_ARTIFACT_POWER_BONUS_RANK_PICKER:
                    if (slot >= SOCK_ENCHANTMENT_SLOT && slot <= SOCK_ENCHANTMENT_SLOT_3 && _bonusData.GemRelicType[slot - SOCK_ENCHANTMENT_SLOT] != -1)
                    {
                        if (ArtifactPowerPickerEntry const* artifactPowerPicker = sArtifactPowerPickerStore.LookupEntry(enchant->EffectArg[i]))
                        {
                            PlayerConditionEntry const* playerCondition = sPlayerConditionStore.LookupEntry(artifactPowerPicker->PlayerConditionID);
                            if (!playerCondition || sConditionMgr->IsPlayerMeetingCondition(owner, playerCondition))
                            {
                                for (ItemDynamicFieldArtifactPowers const& artifactPower : GetArtifactPowers())
                                {
                                    if (sArtifactPowerStore.AssertEntry(artifactPower.ArtifactPowerId)->Label == _bonusData.GemRelicType[slot - SOCK_ENCHANTMENT_SLOT])
                                    {
                                        ItemDynamicFieldArtifactPowers newPower = artifactPower;
                                        if (apply)
                                            newPower.CurrentRankWithBonus += enchant->EffectPointsMin[i];
                                        else
                                            newPower.CurrentRankWithBonus -= enchant->EffectPointsMin[i];

                                        if (IsEquipped())
                                            if (ArtifactPowerRankEntry const* artifactPowerRank = sDB2Manager.GetArtifactPowerRank(artifactPower.ArtifactPowerId, newPower.CurrentRankWithBonus ? newPower.CurrentRankWithBonus - 1 : 0))
                                                owner->ApplyArtifactPowerRank(this, artifactPowerRank, newPower.CurrentRankWithBonus != 0);

                                        SetArtifactPower(&newPower);
                                    }
                                }
                            }
                        }
                    }
                    break;
                default:
                    break;
            }
        }
    }
}

void Item::CopyArtifactDataFromParent(Item* parent)
{
    memcpy(_bonusData.GemItemLevelBonus, parent->GetBonus()->GemItemLevelBonus, sizeof(_bonusData.GemItemLevelBonus));
    SetModifier(ITEM_MODIFIER_ARTIFACT_APPEARANCE_ID, parent->GetModifier(ITEM_MODIFIER_ARTIFACT_APPEARANCE_ID));
    SetAppearanceModId(parent->GetAppearanceModId());
}

void Item::GiveArtifactXp(uint64 amount, Item* sourceItem, uint32 artifactCategoryId)
{
    Player* owner = GetOwner();
    if (!owner)
        return;

    if (artifactCategoryId)
    {
        uint32 artifactKnowledgeLevel = 1;
        if (sourceItem && sourceItem->GetModifier(ITEM_MODIFIER_ARTIFACT_KNOWLEDGE_LEVEL))
            artifactKnowledgeLevel = sourceItem->GetModifier(ITEM_MODIFIER_ARTIFACT_KNOWLEDGE_LEVEL);

        if (GtArtifactKnowledgeMultiplierEntry const* artifactKnowledge = sArtifactKnowledgeMultiplierGameTable.GetRow(artifactKnowledgeLevel))
            amount = uint64(amount * artifactKnowledge->Multiplier);

        if (amount >= 5000)
            amount = 50 * (amount / 50);
        else if (amount >= 1000)
            amount = 25 * (amount / 25);
        else if (amount >= 50)
            amount = 5 * (amount / 5);
    }

    SetUInt64Value(ITEM_FIELD_ARTIFACT_XP, GetUInt64Value(ITEM_FIELD_ARTIFACT_XP) + amount);

    WorldPackets::Artifact::ArtifactXpGain artifactXpGain;
    artifactXpGain.ArtifactGUID = GetGUID();
    artifactXpGain.Amount = amount;
    owner->SendDirectMessage(artifactXpGain.Write());

    SetState(ITEM_CHANGED, owner);
}

void Item::SetFixedLevel(uint8 level)
{
    if (!_bonusData.HasFixedLevel || GetModifier(ITEM_MODIFIER_SCALING_STAT_DISTRIBUTION_FIXED_LEVEL))
        return;

    if (ScalingStatDistributionEntry const* ssd = sScalingStatDistributionStore.LookupEntry(_bonusData.ScalingStatDistribution))
    {
        level = std::min(std::max(int32(level), ssd->MinLevel), ssd->MaxLevel);

        if (ContentTuningEntry const* contentTuning = sContentTuningStore.LookupEntry(_bonusData.ContentTuningId))
            if ((contentTuning->Flags & 2 || contentTuning->MinLevel || contentTuning->MaxLevel) && !(contentTuning->Flags & 4))
                level = std::min(std::max(int32(level), contentTuning->MinLevel), contentTuning->MaxLevel);

        SetModifier(ITEM_MODIFIER_SCALING_STAT_DISTRIBUTION_FIXED_LEVEL, level);
    }
}

int32 Item::GetRequiredLevel() const
{
    if (_bonusData.RequiredLevelOverride)
        return _bonusData.RequiredLevelOverride;
    else if (_bonusData.HasFixedLevel)
        return GetModifier(ITEM_MODIFIER_SCALING_STAT_DISTRIBUTION_FIXED_LEVEL);
    else
        return _bonusData.RequiredLevel;
}

void BonusData::Initialize(ItemTemplate const* proto)
{
    Quality = proto->GetQuality();
    ItemLevelBonus = 0;
    RequiredLevel = proto->GetBaseRequiredLevel();
    for (uint32 i = 0; i < MAX_ITEM_PROTO_STATS; ++i)
        ItemStatType[i] = proto->GetItemStatType(i);

    for (uint32 i = 0; i < MAX_ITEM_PROTO_STATS; ++i)
        ItemStatAllocation[i] = proto->GetItemStatAllocation(i);

    for (uint32 i = 0; i < MAX_ITEM_PROTO_STATS; ++i)
        ItemStatSocketCostMultiplier[i] = proto->GetItemStatSocketCostMultiplier(i);

    for (uint32 i = 0; i < MAX_ITEM_PROTO_SOCKETS; ++i)
    {
        SocketColor[i] = proto->GetSocketColor(i);
        GemItemLevelBonus[i] = 0;
        GemRelicType[i] = -1;
        GemRelicRankBonus[i] = 0;
    }

    Bonding = proto->GetBonding();

    AppearanceModID = 0;
    RepairCostMultiplier = 1.0f;
    ScalingStatDistribution = proto->GetScalingStatDistribution();
    ContentTuningId = 0;
    RelicType = -1;
    HasItemLevelBonus = false;
    HasFixedLevel = false;
    RequiredLevelOverride = 0;

    _state.AppearanceModPriority = std::numeric_limits<int32>::max();
    _state.ScalingStatDistributionPriority = std::numeric_limits<int32>::max();
    _state.HasQualityBonus = false;
}

void BonusData::Initialize(WorldPackets::Item::ItemInstance const& itemInstance)
{
    ItemTemplate const* proto = sObjectMgr->GetItemTemplate(itemInstance.ItemID);
    if (!proto)
        return;

    Initialize(proto);

    if (itemInstance.ItemBonus)
        for (uint32 bonusListID : itemInstance.ItemBonus->BonusListIDs)
            if (DB2Manager::ItemBonusList const* bonuses = sDB2Manager.GetItemBonusList(bonusListID))
                for (ItemBonusEntry const* bonus : *bonuses)
                    AddBonus(bonus->Type, bonus->Value);
}

void BonusData::AddBonus(uint32 type, int32 const (&values)[3])
{
    switch (type)
    {
        case ITEM_BONUS_ITEM_LEVEL:
            ItemLevelBonus += values[0];
            HasItemLevelBonus = true;
            break;
        case ITEM_BONUS_STAT:
        {
            uint32 statIndex = 0;
            for (statIndex = 0; statIndex < MAX_ITEM_PROTO_STATS; ++statIndex)
                if (ItemStatType[statIndex] == values[0] || ItemStatType[statIndex] == -1)
                    break;

            if (statIndex < MAX_ITEM_PROTO_STATS)
            {
                ItemStatType[statIndex] = values[0];
                ItemStatAllocation[statIndex] += values[1];
            }
            break;
        }
        case ITEM_BONUS_QUALITY:
            if (!_state.HasQualityBonus)
            {
                Quality = static_cast<uint32>(values[0]);
                _state.HasQualityBonus = true;
            }
            else if (Quality < static_cast<uint32>(values[0]))
                Quality = static_cast<uint32>(values[0]);
            break;
        case ITEM_BONUS_SOCKET:
        {
            uint32 socketCount = values[0];
            for (uint32 i = 0; i < MAX_ITEM_PROTO_SOCKETS && socketCount; ++i)
            {
                if (!SocketColor[i])
                {
                    SocketColor[i] = values[1];
                    --socketCount;
                }
            }
            break;
        }
        case ITEM_BONUS_APPEARANCE:
            if (values[1] < _state.AppearanceModPriority)
            {
                AppearanceModID = static_cast<uint32>(values[0]);
                _state.AppearanceModPriority = values[1];
            }
            break;
        case ITEM_BONUS_REQUIRED_LEVEL:
            RequiredLevel += values[0];
            break;
        case ITEM_BONUS_REPAIR_COST_MULTIPLIER:
            RepairCostMultiplier *= static_cast<float>(values[0]) * 0.01f;
            break;
        case ITEM_BONUS_SCALING_STAT_DISTRIBUTION:
        case ITEM_BONUS_SCALING_STAT_DISTRIBUTION_FIXED:
            if (values[1] < _state.ScalingStatDistributionPriority)
            {
                ScalingStatDistribution = static_cast<uint32>(values[0]);
                ContentTuningId = static_cast<uint32>(values[2]);
                _state.ScalingStatDistributionPriority = values[1];
                HasFixedLevel = type == ITEM_BONUS_SCALING_STAT_DISTRIBUTION_FIXED;
            }
            break;
        case ITEM_BONUS_BONDING:
            Bonding = ItemBondingType(values[0]);
            break;
        case ITEM_BONUS_RELIC_TYPE:
            RelicType = values[0];
            break;
        case ITEM_BONUS_OVERRIDE_REQUIRED_LEVEL:
            RequiredLevelOverride = values[0];
            break;
    }
}
