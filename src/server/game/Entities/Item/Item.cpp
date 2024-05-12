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

#include "Item.h"
#include "ArtifactPackets.h"
#include "Bag.h"
#include "CollectionMgr.h"
#include "Common.h"
#include "ConditionMgr.h"
#include "Containers.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "GameTables.h"
#include "GameTime.h"
#include "ItemBonusMgr.h"
#include "ItemEnchantmentMgr.h"
#include "ItemPackets.h"
#include "Log.h"
#include "Loot.h"
#include "LootItemStorage.h"
#include "LootMgr.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "StringConvert.h"
#include "TradeData.h"
#include "UpdateData.h"
#include "World.h"
#include "WorldSession.h"
#include <sstream>

Item* NewItemOrBag(ItemTemplate const* proto)
{
    if (proto->GetInventoryType() == INVTYPE_BAG)
        return new Bag();

    return new Item();
}

void AddItemsSetItem(Player* player, Item const* item)
{
    ItemTemplate const* proto = item->GetTemplate();
    uint32 setid = proto->GetItemSet();

    ItemSetEntry const* set = sItemSetStore.LookupEntry(setid);

    if (!set)
    {
        TC_LOG_ERROR("sql.sql", "Item set {} for item (id {}) not found, mods not applied.", setid, proto->GetId());
        return;
    }

    if (set->RequiredSkill && player->GetSkillValue(set->RequiredSkill) < set->RequiredSkillRank)
        return;

    if (set->SetFlags & ITEM_SET_FLAG_LEGACY_INACTIVE)
        return;

    // Check player level for heirlooms
    if (sDB2Manager.GetHeirloomByItemId(item->GetEntry()))
    {
        if (item->GetBonus()->PlayerLevelToItemLevelCurveId)
        {
            uint32 maxLevel = sDB2Manager.GetCurveXAxisRange(item->GetBonus()->PlayerLevelToItemLevelCurveId).second;

            if (Optional<ContentTuningLevels> contentTuning = sDB2Manager.GetContentTuningData(item->GetBonus()->ContentTuningId, 0 /*player->m_playerData->CtrOptions->ContentTuningConditionMask*/, true))
                maxLevel = std::min<uint32>(maxLevel, contentTuning->MaxLevel);

            if (player->GetLevel() > maxLevel)
                return;
        }
    }

    ItemSetEffect* eff = nullptr;

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

        size_t x = 0;
        for (; x < player->ItemSetEff.size(); ++x)
            if (!player->ItemSetEff[x])
                break;

        if (x < player->ItemSetEff.size())
            player->ItemSetEff[x] = eff;
        else
            player->ItemSetEff.push_back(eff);
    }

    eff->EquippedItems.insert(item);

    if (std::vector<ItemSetSpellEntry const*> const* itemSetSpells = sDB2Manager.GetItemSetSpells(setid))
    {
        for (ItemSetSpellEntry const* itemSetSpell : *itemSetSpells)
        {
            //not enough for  spell
            if (itemSetSpell->Threshold > eff->EquippedItems.size())
                continue;

            if (eff->SetBonuses.count(itemSetSpell))
                continue;

            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(itemSetSpell->SpellID, DIFFICULTY_NONE);
            if (!spellInfo)
            {
                TC_LOG_ERROR("entities.player.items", "WORLD: unknown spell id {} in items set {} effects", itemSetSpell->SpellID, setid);
                continue;
            }

            eff->SetBonuses.insert(itemSetSpell);
            // spell cast only if fit form requirement, in other case will cast at form change
            if (!itemSetSpell->ChrSpecID || ChrSpecialization(itemSetSpell->ChrSpecID) == player->GetPrimarySpecialization())
                player->ApplyEquipSpell(spellInfo, nullptr, true);
        }
    }
}

void RemoveItemsSetItem(Player* player, Item const* item)
{
    uint32 setid = item->GetTemplate()->GetItemSet();

    ItemSetEntry const* set = sItemSetStore.LookupEntry(setid);

    if (!set)
    {
        TC_LOG_ERROR("sql.sql", "Item set #{} for item #{} not found, mods not removed.", setid, item->GetEntry());
        return;
    }

    ItemSetEffect* eff = nullptr;
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

    eff->EquippedItems.erase(item);

    if (std::vector<ItemSetSpellEntry const*> const* itemSetSpells = sDB2Manager.GetItemSetSpells(setid))
    {
        for (ItemSetSpellEntry const* itemSetSpell : *itemSetSpells)
        {
            // enough for spell
            if (itemSetSpell->Threshold <= eff->EquippedItems.size())
                continue;

            if (!eff->SetBonuses.count(itemSetSpell))
                continue;

            player->ApplyEquipSpell(sSpellMgr->AssertSpellInfo(itemSetSpell->SpellID, DIFFICULTY_NONE), nullptr, false);
            eff->SetBonuses.erase(itemSetSpell);
        }
    }

    if (eff->EquippedItems.empty())                                 //all items of a set were removed
    {
        ASSERT(eff == player->ItemSetEff[setindex]);
        delete eff;
        player->ItemSetEff[setindex] = nullptr;
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
                case ITEM_SUBCLASS_REAGENT_CONTAINER:
                    return pProto->IsCraftingReagent();
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
    ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_4,
    ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_5
};

ItemModifier const IllusionModifierSlotBySpec[MAX_SPECIALIZATIONS] =
{
    ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_1,
    ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_2,
    ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_3,
    ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_4,
    ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_5
};

ItemModifier const SecondaryAppearanceModifierSlotBySpec[MAX_SPECIALIZATIONS] =
{
    ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_1,
    ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_2,
    ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_3,
    ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_4,
    ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_5
};

void ItemAdditionalLoadInfo::Init(std::unordered_map<ObjectGuid::LowType, ItemAdditionalLoadInfo>* loadInfo,
    PreparedQueryResult artifactResult)
{
    //                 0     1                       2                 3                   4                 5
    // SELECT a.itemGuid, a.xp, a.artifactAppearanceId, a.artifactTierId, ap.artifactPowerId, ap.purchasedRank FROM item_instance_artifact_powers ap LEFT JOIN item_instance_artifact a ON ap.itemGuid = a.itemGuid ...
    if (artifactResult)
    {
        do
        {
            Field* fields = artifactResult->Fetch();
            ItemAdditionalLoadInfo& info = (*loadInfo)[fields[0].GetUInt64()];
            if (!info.Artifact)
                info.Artifact.emplace();
            info.Artifact->Xp = fields[1].GetUInt64();
            info.Artifact->ArtifactAppearanceId = fields[2].GetUInt32();
            info.Artifact->ArtifactTierId = fields[3].GetUInt32();
            ArtifactPowerData artifactPowerData;
            artifactPowerData.ArtifactPowerId = fields[4].GetUInt32();
            artifactPowerData.PurchasedRank = fields[5].GetUInt8();
            if (ArtifactPowerEntry const* artifactPower = sArtifactPowerStore.LookupEntry(artifactPowerData.ArtifactPowerId))
            {
                uint32 maxRank = artifactPower->MaxPurchasableRank;
                // allow ARTIFACT_POWER_FLAG_FINAL to overflow maxrank here - needs to be handled in Item::CheckArtifactUnlock (will refund artifact power)
                if (artifactPower->Flags & ARTIFACT_POWER_FLAG_MAX_RANK_WITH_TIER && artifactPower->Tier < info.Artifact->ArtifactTierId)
                    maxRank += info.Artifact->ArtifactTierId - artifactPower->Tier;

                if (artifactPowerData.PurchasedRank > maxRank)
                    artifactPowerData.PurchasedRank = maxRank;

                artifactPowerData.CurrentRankWithBonus = (artifactPower->Flags & ARTIFACT_POWER_FLAG_FIRST) == ARTIFACT_POWER_FLAG_FIRST ? 1 : 0;

                info.Artifact->ArtifactPowers.push_back(artifactPowerData);
            }

        } while (artifactResult->NextRow());
    }
}

Item::Item()
{
    m_objectType |= TYPEMASK_ITEM;
    m_objectTypeId = TYPEID_ITEM;

    m_slot = 0;
    uState = ITEM_NEW;
    uQueuePos = -1;
    m_container = nullptr;
    m_lootGenerated = false;
    mb_in_trade = false;

    m_paidMoney = 0;
    m_paidExtendedCost = 0;

    m_randomBonusListId = 0;
    m_gemScalingLevels = { };

    memset(&_bonusData, 0, sizeof(_bonusData));
}

Item::~Item() = default;

bool Item::Create(ObjectGuid::LowType guidlow, uint32 itemId, ItemContext context, Player const* owner)
{
    Object::_Create(ObjectGuid::Create<HighGuid::Item>(guidlow));

    SetEntry(itemId);
    SetObjectScale(1.0f);

    if (owner)
    {
        SetOwnerGUID(owner->GetGUID());
        SetContainedIn(owner->GetGUID());
    }

    ItemTemplate const* itemProto = sObjectMgr->GetItemTemplate(itemId);
    if (!itemProto)
        return false;

    _bonusData.Initialize(itemProto);
    SetCount(1);
    SetUpdateFieldValue(m_values.ModifyValue(&Item::m_itemData).ModifyValue(&UF::ItemData::MaxDurability), itemProto->MaxDurability);
    SetDurability(itemProto->MaxDurability);

    for (std::size_t i = 0; i < itemProto->Effects.size(); ++i)
        if (itemProto->Effects[i]->LegacySlotIndex < 5)
            SetSpellCharges(itemProto->Effects[i]->LegacySlotIndex, itemProto->Effects[i]->Charges);

    SetExpiration(itemProto->GetDuration());
    SetCreatePlayedTime(0);
    SetCreateTime(GameTime::GetGameTime());
    SetContext(context);

    if (itemProto->GetArtifactID())
    {
        InitArtifactPowers(itemProto->GetArtifactID(), 0);
        for (ArtifactAppearanceEntry const* artifactAppearance : sArtifactAppearanceStore)
        {
            if (ArtifactAppearanceSetEntry const* artifactAppearanceSet = sArtifactAppearanceSetStore.LookupEntry(artifactAppearance->ArtifactAppearanceSetID))
            {
                if (itemProto->GetArtifactID() != artifactAppearanceSet->ArtifactID)
                    continue;

                if (!owner || !ConditionMgr::IsPlayerMeetingCondition(owner, artifactAppearance->UnlockPlayerConditionID))
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

std::string Item::GetNameForLocaleIdx(LocaleConstant locale) const
{
    ItemTemplate const* itemTemplate = GetTemplate();
    if (ItemNameDescriptionEntry const* suffix = sItemNameDescriptionStore.LookupEntry(_bonusData.Suffix))
        return Trinity::StringFormat("{} {}", itemTemplate->GetName(locale), suffix->Description[locale]);

    return itemTemplate->GetName(locale);
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
    uint32 duration = m_itemData->Expiration;
    if (!duration)
        return;

    TC_LOG_DEBUG("entities.player.items", "Item::UpdateDuration Item (Entry: {} Duration {} Diff {})", GetEntry(), duration, diff);

    if (duration <= diff)
    {
        sScriptMgr->OnItemExpire(owner, GetTemplate());
        owner->DestroyItem(GetBagSlot(), GetSlot(), true);
        return;
    }

    SetExpiration(duration - diff);
    SetState(ITEM_CHANGED, owner);                          // save new time in database
}

void Item::SaveToDB(CharacterDatabaseTransaction trans)
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
            CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(uState == ITEM_NEW ? CHAR_REP_ITEM_INSTANCE : CHAR_UPD_ITEM_INSTANCE);
            stmt->setUInt32(  index, GetEntry());
            stmt->setUInt64(++index, GetOwnerGUID().GetCounter());
            stmt->setUInt64(++index, GetCreator().GetCounter());
            stmt->setUInt64(++index, GetGiftCreator().GetCounter());
            stmt->setUInt32(++index, GetCount());
            stmt->setUInt32(++index, m_itemData->Expiration);

            std::ostringstream ssSpells;
            for (uint8 i = 0; i < m_itemData->SpellCharges.size() && i < _bonusData.EffectCount; ++i)
                ssSpells << GetSpellCharges(i) << ' ';
            stmt->setString(++index, ssSpells.str());

            stmt->setUInt32(++index, m_itemData->DynamicFlags);

            std::ostringstream ssEnchants;
            for (uint8 i = 0; i < MAX_ENCHANTMENT_SLOT; ++i)
            {
                if (SpellItemEnchantmentEntry const* enchantment = sSpellItemEnchantmentStore.LookupEntry(GetEnchantmentId(EnchantmentSlot(i)));
                    enchantment && !enchantment->GetFlags().HasFlag(SpellItemEnchantmentFlags::DoNotSaveToDB))
                {
                    ssEnchants << GetEnchantmentId(EnchantmentSlot(i)) << ' ';
                    ssEnchants << GetEnchantmentDuration(EnchantmentSlot(i)) << ' ';
                    ssEnchants << GetEnchantmentCharges(EnchantmentSlot(i)) << ' ';
                }
                else
                {
                    ssEnchants << "0 0 0 ";
                }
            }
            stmt->setString(++index, ssEnchants.str());

            stmt->setUInt32(++index, m_randomBonusListId);
            stmt->setUInt16(++index, m_itemData->Durability);
            stmt->setUInt32(++index, m_itemData->CreatePlayedTime);
            stmt->setInt64(++index, m_itemData->CreateTime);
            stmt->setString(++index, m_text);
            stmt->setUInt32(++index, GetModifier(ITEM_MODIFIER_BATTLE_PET_SPECIES_ID));
            stmt->setUInt32(++index, GetModifier(ITEM_MODIFIER_BATTLE_PET_BREED_DATA));
            stmt->setUInt32(++index, GetModifier(ITEM_MODIFIER_BATTLE_PET_LEVEL));
            stmt->setUInt32(++index, GetModifier(ITEM_MODIFIER_BATTLE_PET_DISPLAY_ID));
            stmt->setUInt8(++index, uint8(m_itemData->Context));

            std::ostringstream bonusListIDs;
            for (int32 bonusListID : GetBonusListIDs())
                bonusListIDs << bonusListID << ' ';
            stmt->setString(++index, bonusListIDs.str());

            stmt->setUInt64(++index, GetGUID().GetCounter());

            trans->Append(stmt);

            if ((uState == ITEM_CHANGED) && IsWrapped())
            {
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GIFT_OWNER);
                stmt->setUInt64(0, GetOwnerGUID().GetCounter());
                stmt->setUInt64(1, GetGUID().GetCounter());
                trans->Append(stmt);
            }

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEM_INSTANCE_GEMS);
            stmt->setUInt64(0, GetGUID().GetCounter());
            trans->Append(stmt);

            if (m_itemData->Gems.size())
            {
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_ITEM_INSTANCE_GEMS);
                stmt->setUInt64(0, GetGUID().GetCounter());
                uint32 i = 0;
                uint32 const gemFields = 4;
                for (UF::SocketedGem const& gemData : m_itemData->Gems)
                {
                    if (gemData.ItemID)
                    {
                        stmt->setUInt32(1 + i * gemFields, gemData.ItemID);
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

            static ItemModifier const transmogMods[18] =
            {
                ITEM_MODIFIER_TRANSMOG_APPEARANCE_ALL_SPECS,
                ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_1,
                ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_2,
                ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_3,
                ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_4,
                ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_5,

                ITEM_MODIFIER_ENCHANT_ILLUSION_ALL_SPECS,
                ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_1,
                ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_2,
                ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_3,
                ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_4,
                ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_5,

                ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_ALL_SPECS,
                ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_1,
                ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_2,
                ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_3,
                ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_4,
                ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_5
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
                stmt->setUInt32(6, GetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_5));
                stmt->setUInt32(7, GetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_ALL_SPECS));
                stmt->setUInt32(8, GetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_1));
                stmt->setUInt32(9, GetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_2));
                stmt->setUInt32(10, GetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_3));
                stmt->setUInt32(11, GetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_4));
                stmt->setUInt32(12, GetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_5));
                stmt->setUInt32(13, GetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_ALL_SPECS));
                stmt->setUInt32(14, GetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_1));
                stmt->setUInt32(15, GetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_2));
                stmt->setUInt32(16, GetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_3));
                stmt->setUInt32(17, GetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_4));
                stmt->setUInt32(18, GetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_5));
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
                stmt->setUInt64(1, m_itemData->ArtifactXP);
                stmt->setUInt32(2, GetModifier(ITEM_MODIFIER_ARTIFACT_APPEARANCE_ID));
                stmt->setUInt32(3, GetModifier(ITEM_MODIFIER_ARTIFACT_TIER));
                trans->Append(stmt);

                for (UF::ArtifactPower const& artifactPower : m_itemData->ArtifactPowers)
                {
                    stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_ITEM_INSTANCE_ARTIFACT_POWERS);
                    stmt->setUInt64(0, GetGUID().GetCounter());
                    stmt->setUInt32(1, artifactPower.ArtifactPowerID);
                    stmt->setUInt8(2, artifactPower.PurchasedRank);
                    trans->Append(stmt);
                }
            }

            static ItemModifier const modifiersTable[] =
            {
                ITEM_MODIFIER_TIMEWALKER_LEVEL,
                ITEM_MODIFIER_ARTIFACT_KNOWLEDGE_LEVEL
            };

            stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEM_INSTANCE_MODIFIERS);
            stmt->setUInt64(0, GetGUID().GetCounter());
            trans->Append(stmt);

            if (std::find_if(std::begin(modifiersTable), std::end(modifiersTable), [this](ItemModifier modifier) { return GetModifier(modifier) != 0; }) != std::end(modifiersTable))
            {
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_ITEM_INSTANCE_MODIFIERS);
                stmt->setUInt64(0, GetGUID().GetCounter());
                stmt->setUInt32(1, GetModifier(ITEM_MODIFIER_TIMEWALKER_LEVEL));
                stmt->setUInt32(2, GetModifier(ITEM_MODIFIER_ARTIFACT_KNOWLEDGE_LEVEL));
                trans->Append(stmt);
            }

            break;
        }
        case ITEM_REMOVED:
        {
            CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEM_INSTANCE);
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

            if (IsWrapped())
            {
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GIFT);
                stmt->setUInt64(0, GetGUID().GetCounter());
                trans->Append(stmt);
            }

            if (!isInTransaction)
                CharacterDatabase.CommitTransaction(trans);

            // Delete the items if this is a container
            if (m_loot && !m_loot->isLooted())
                sLootItemStorage->RemoveStoredLootForContainer(GetGUID().GetCounter());

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
    //           0          1            2                3      4         5        6      7             8                  9          10          11          12    13
    // SELECT guid, itemEntry, creatorGuid, giftCreatorGuid, count, duration, charges, flags, enchantments, randomBonusListId, durability, playedTime, createTime, text,
    //                        14                  15              16                  17       18            19
    //        battlePetSpeciesId, battlePetBreedData, battlePetLevel, battlePetDisplayId, context, bonusListIDs,
    //                                    20                           21                           22                           23                           24                           25
    //        itemModifiedAppearanceAllSpecs, itemModifiedAppearanceSpec1, itemModifiedAppearanceSpec2, itemModifiedAppearanceSpec3, itemModifiedAppearanceSpec4, itemModifiedAppearanceSpec5,
    //                                  26                         27                         28                         29                         30                         31
    //        spellItemEnchantmentAllSpecs, spellItemEnchantmentSpec1, spellItemEnchantmentSpec2, spellItemEnchantmentSpec3, spellItemEnchantmentSpec4, spellItemEnchantmentSpec5,
    //                                             32                                    33                                    34
    //        secondaryItemModifiedAppearanceAllSpecs, secondaryItemModifiedAppearanceSpec1, secondaryItemModifiedAppearanceSpec2,
    //                                          35                                    36                                    37
    //        secondaryItemModifiedAppearanceSpec3, secondaryItemModifiedAppearanceSpec4, secondaryItemModifiedAppearanceSpec5,
    //                38           39           40                41          42           43           44                45          46           47           48                49
    //        gemItemId1, gemBonuses1, gemContext1, gemScalingLevel1, gemItemId2, gemBonuses2, gemContext2, gemScalingLevel2, gemItemId3, gemBonuses3, gemContext3, gemScalingLevel3
    //                       50                      51
    //        fixedScalingLevel, artifactKnowledgeLevel FROM item_instance

    // create item before any checks for store correct guid
    // and allow use "FSetState(ITEM_REMOVED); SaveToDB();" for deleting item from DB
    Object::_Create(ObjectGuid::Create<HighGuid::Item>(guid));

    // Set entry, MUST be before proto check
    SetEntry(entry);
    SetObjectScale(1.0f);

    ItemTemplate const* proto = GetTemplate();
    if (!proto)
    {
        TC_LOG_ERROR("entities.item", "Invalid entry {} for item {}. Refusing to load.", GetEntry(), GetGUID().ToString());
        return false;
    }

    _bonusData.Initialize(proto);

    // set owner (not if item is only loaded for gbank/auction/mail
    if (!ownerGuid.IsEmpty())
        SetOwnerGUID(ownerGuid);

    uint32 itemFlags = fields[7].GetUInt32();
    bool need_save = false;                                 // need explicit save data at load fixes
    if (uint64 creator = fields[2].GetUInt64())
    {
        if (!(itemFlags & ITEM_FIELD_FLAG_CHILD))
            SetCreator(ObjectGuid::Create<HighGuid::Player>(creator));
        else
            SetCreator(ObjectGuid::Create<HighGuid::Item>(creator));
    }
    if (uint64 giftCreator = fields[3].GetUInt64())
        SetGiftCreator(ObjectGuid::Create<HighGuid::Player>(giftCreator));
    SetCount(fields[4].GetUInt32());

    uint32 duration = fields[5].GetUInt32();
    SetExpiration(duration);
    // update duration if need, and remove if not need
    if ((proto->GetDuration() == 0) != (duration == 0))
    {
        SetExpiration(proto->GetDuration());
        need_save = true;
    }

    ReplaceAllItemFlags(ItemFieldFlags(itemFlags));

    uint32 durability = fields[10].GetUInt16();
    SetDurability(durability);
    // update max durability (and durability) if need
    SetUpdateFieldValue(m_values.ModifyValue(&Item::m_itemData).ModifyValue(&UF::ItemData::MaxDurability), proto->MaxDurability);

    // do not overwrite durability for wrapped items
    if (durability > proto->MaxDurability && !IsWrapped())
    {
        SetDurability(proto->MaxDurability);
        need_save = true;
    }

    SetCreatePlayedTime(fields[11].GetUInt32());
    SetCreateTime(fields[12].GetInt64());
    SetText(fields[13].GetString());

    SetModifier(ITEM_MODIFIER_BATTLE_PET_SPECIES_ID, fields[14].GetUInt32());
    SetModifier(ITEM_MODIFIER_BATTLE_PET_BREED_DATA, fields[15].GetUInt32());
    SetModifier(ITEM_MODIFIER_BATTLE_PET_LEVEL, fields[16].GetUInt16());
    SetModifier(ITEM_MODIFIER_BATTLE_PET_DISPLAY_ID, fields[17].GetUInt32());

    SetContext(ItemContext(fields[18].GetUInt8()));

    std::vector<std::string_view> bonusListString = Trinity::Tokenize(fields[19].GetStringView(), ' ', false);
    std::vector<int32> bonusListIDs;
    bonusListIDs.reserve(bonusListString.size());
    for (std::string_view token : bonusListString)
        if (Optional<int32> bonusListID = Trinity::StringTo<int32>(token))
            bonusListIDs.push_back(*bonusListID);
    SetBonuses(std::move(bonusListIDs));

    // load charges after bonuses, they can add more item effects
    std::vector<std::string_view> tokens = Trinity::Tokenize(fields[6].GetStringView(), ' ', false);
    for (uint8 i = 0; i < m_itemData->SpellCharges.size() && i < _bonusData.EffectCount && i < tokens.size(); ++i)
        SetSpellCharges(i, Trinity::StringTo<int32>(tokens[i]).value_or(0));

    SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_ALL_SPECS, fields[20].GetUInt32());
    SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_1, fields[21].GetUInt32());
    SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_2, fields[22].GetUInt32());
    SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_3, fields[23].GetUInt32());
    SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_4, fields[24].GetUInt32());
    SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_5, fields[25].GetUInt32());

    SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_ALL_SPECS, fields[26].GetUInt32());
    SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_1, fields[27].GetUInt32());
    SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_2, fields[28].GetUInt32());
    SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_3, fields[29].GetUInt32());
    SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_4, fields[30].GetUInt32());
    SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_5, fields[31].GetUInt32());

    SetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_ALL_SPECS, fields[32].GetUInt32());
    SetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_1, fields[33].GetUInt32());
    SetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_2, fields[34].GetUInt32());
    SetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_3, fields[35].GetUInt32());
    SetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_4, fields[36].GetUInt32());
    SetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_SPEC_5, fields[37].GetUInt32());

    uint32 const gemFields = 4;
    ItemDynamicFieldGems gemData[MAX_GEM_SOCKETS];
    memset(gemData, 0, sizeof(gemData));
    for (uint32 i = 0; i < MAX_GEM_SOCKETS; ++i)
    {
        gemData[i].ItemId = fields[38 + i * gemFields].GetUInt32();
        std::vector<std::string_view> gemBonusListIDs = Trinity::Tokenize(fields[39 + i * gemFields].GetStringView(), ' ', false);
        uint32 b = 0;
        for (std::string_view token : gemBonusListIDs)
            if (Optional<uint16> bonusListID = Trinity::StringTo<uint16>(token))
                gemData[i].BonusListIDs[b++] = *bonusListID;

        gemData[i].Context = fields[40 + i * gemFields].GetUInt8();
        if (gemData[i].ItemId)
            SetGem(i, &gemData[i], fields[41 + i * gemFields].GetUInt32());
    }

    SetModifier(ITEM_MODIFIER_TIMEWALKER_LEVEL, fields[50].GetUInt32());
    SetModifier(ITEM_MODIFIER_ARTIFACT_KNOWLEDGE_LEVEL, fields[51].GetUInt32());

    // Enchants must be loaded after all other bonus/scaling data
    std::vector<std::string_view> enchantmentTokens = Trinity::Tokenize(fields[8].GetStringView(), ' ', false);
    if (enchantmentTokens.size() == MAX_ENCHANTMENT_SLOT * MAX_ENCHANTMENT_OFFSET)
    {
        for (uint32 i = 0; i < MAX_ENCHANTMENT_SLOT; ++i)
        {
            auto enchantmentField = m_values.ModifyValue(&Item::m_itemData).ModifyValue(&UF::ItemData::Enchantment, i);
            SetUpdateFieldValue(enchantmentField.ModifyValue(&UF::ItemEnchantment::ID), Trinity::StringTo<int32>(enchantmentTokens[i * MAX_ENCHANTMENT_OFFSET + 0]).value_or(0));
            SetUpdateFieldValue(enchantmentField.ModifyValue(&UF::ItemEnchantment::Duration), Trinity::StringTo<uint32>(enchantmentTokens[i * MAX_ENCHANTMENT_OFFSET + 1]).value_or(0));
            SetUpdateFieldValue(enchantmentField.ModifyValue(&UF::ItemEnchantment::Charges), Trinity::StringTo<int16>(enchantmentTokens[i * MAX_ENCHANTMENT_OFFSET + 2]).value_or(0));
        }
    }
    m_randomBonusListId = fields[9].GetUInt32();

    // Remove bind flag for items vs BIND_NONE set
    if (IsSoulBound() && GetBonding() == BIND_NONE)
    {
        RemoveItemFlag(ITEM_FIELD_FLAG_SOULBOUND);
        need_save = true;
    }

    if (need_save)                                           // normal item changed state set not work at loading
    {
        uint8 index = 0;
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ITEM_INSTANCE_ON_LOAD);
        stmt->setUInt32(index++, m_itemData->Expiration);
        stmt->setUInt32(index++, m_itemData->DynamicFlags);
        stmt->setUInt32(index++, m_itemData->Durability);
        stmt->setUInt64(index++, guid);
        CharacterDatabase.Execute(stmt);
    }

    return true;
}

void Item::LoadArtifactData(Player const* owner, uint64 xp, uint32 artifactAppearanceId, uint32 artifactTier, std::vector<ArtifactPowerData>& powers)
{
    for (uint8 i = 0; i <= artifactTier; ++i)
        InitArtifactPowers(GetTemplate()->GetArtifactID(), i);

    SetUpdateFieldValue(m_values.ModifyValue(&Item::m_itemData).ModifyValue(&UF::ItemData::ArtifactXP), xp);
    SetModifier(ITEM_MODIFIER_ARTIFACT_APPEARANCE_ID, artifactAppearanceId);
    SetModifier(ITEM_MODIFIER_ARTIFACT_TIER, artifactTier);

    if (ArtifactAppearanceEntry const* artifactAppearance = sArtifactAppearanceStore.LookupEntry(artifactAppearanceId))
        SetAppearanceModId(artifactAppearance->ItemAppearanceModifierID);

    uint8 totalPurchasedRanks = 0;
    for (ArtifactPowerData& power : powers)
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
                            if (artifactPower->Label == enchant->EffectArg[i])
                                power.CurrentRankWithBonus += enchant->EffectPointsMin[i];
                            break;
                        case ITEM_ENCHANTMENT_TYPE_ARTIFACT_POWER_BONUS_RANK_BY_ID:
                            if (int32(artifactPower->ID) == enchant->EffectArg[i])
                                power.CurrentRankWithBonus += enchant->EffectPointsMin[i];
                            break;
                        case ITEM_ENCHANTMENT_TYPE_ARTIFACT_POWER_BONUS_RANK_PICKER:
                            if (_bonusData.GemRelicType[e - SOCK_ENCHANTMENT_SLOT] != -1)
                            {
                                ArtifactPowerPickerEntry const* artifactPowerPicker = sArtifactPowerPickerStore.LookupEntry(enchant->EffectArg[i]);
                                if (artifactPowerPicker && owner && ConditionMgr::IsPlayerMeetingCondition(owner, artifactPowerPicker->PlayerConditionID))
                                    if (artifactPower->Label == _bonusData.GemRelicType[e - SOCK_ENCHANTMENT_SLOT])
                                        power.CurrentRankWithBonus += enchant->EffectPointsMin[i];
                            }
                            break;
                        default:
                            break;
                    }
                }
            }
        }

        SetArtifactPower(power.ArtifactPowerId, power.PurchasedRank, power.CurrentRankWithBonus);
    }

    for (ArtifactPowerData& power : powers)
    {
        ArtifactPowerEntry const* scaledArtifactPowerEntry = sArtifactPowerStore.AssertEntry(power.ArtifactPowerId);
        if (!(scaledArtifactPowerEntry->Flags & ARTIFACT_POWER_FLAG_SCALES_WITH_NUM_POWERS))
            continue;

        SetArtifactPower(power.ArtifactPowerId, power.PurchasedRank, totalPurchasedRanks + 1);
    }

    CheckArtifactRelicSlotUnlock(owner);
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
void Item::DeleteFromDB(CharacterDatabaseTransaction trans, ObjectGuid::LowType itemGuid)
{
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEM_INSTANCE);
    stmt->setUInt64(0, itemGuid);
    CharacterDatabase.ExecuteOrAppend(trans, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEM_INSTANCE_GEMS);
    stmt->setUInt64(0, itemGuid);
    CharacterDatabase.ExecuteOrAppend(trans, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEM_INSTANCE_TRANSMOG);
    stmt->setUInt64(0, itemGuid);
    CharacterDatabase.ExecuteOrAppend(trans, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEM_INSTANCE_ARTIFACT);
    stmt->setUInt64(0, itemGuid);
    CharacterDatabase.ExecuteOrAppend(trans, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEM_INSTANCE_ARTIFACT_POWERS);
    stmt->setUInt64(0, itemGuid);
    CharacterDatabase.ExecuteOrAppend(trans, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEM_INSTANCE_MODIFIERS);
    stmt->setUInt64(0, itemGuid);
    CharacterDatabase.ExecuteOrAppend(trans, stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_GIFT);
    stmt->setUInt64(0, itemGuid);
    CharacterDatabase.ExecuteOrAppend(trans, stmt);
}

void Item::DeleteFromDB(CharacterDatabaseTransaction trans)
{
    DeleteFromDB(trans, GetGUID().GetCounter());

    // Delete the items if this is a container
    if (m_loot && !m_loot->isLooted())
        sLootItemStorage->RemoveStoredLootForContainer(GetGUID().GetCounter());
}

/*static*/
void Item::DeleteFromInventoryDB(CharacterDatabaseTransaction trans, ObjectGuid::LowType itemGuid)
{
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_INVENTORY_BY_ITEM);
    stmt->setUInt64(0, itemGuid);
    trans->Append(stmt);
}

void Item::DeleteFromInventoryDB(CharacterDatabaseTransaction trans)
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

void Item::SetItemRandomBonusList(ItemRandomBonusListId bonusListId)
{
    if (!bonusListId)
        return;

    AddBonuses(bonusListId);
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

    ASSERT(player != nullptr);

    if (player->GetGUID() != item->GetOwnerGUID())
    {
        TC_LOG_DEBUG("entities.player.items", "AddItemToUpdateQueueOf - Owner's guid ({}) and player's guid ({}) don't match!",
            item->GetOwnerGUID().ToString(), player->GetGUID().ToString());
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

    ASSERT(player != nullptr);

    if (player->GetGUID() != item->GetOwnerGUID())
    {
        TC_LOG_DEBUG("entities.player.items", "RemoveItemFromUpdateQueueOf - Owner's guid ({}) and player's guid ({}) don't match!",
            item->GetOwnerGUID().ToString(), player->GetGUID().ToString());
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
    return !IsInBag() && (m_slot < EQUIPMENT_SLOT_END
        || (m_slot >= PROFESSION_SLOT_START && m_slot < PROFESSION_SLOT_END));
}

bool Item::CanBeTraded(bool mail, bool trade) const
{
    if (m_lootGenerated)
        return false;

    if ((!mail || !IsBoundAccountWide()) && (IsSoulBound() && (!IsBOPTradeable() || !trade)))
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
    SetUpdateFieldValue(m_values.ModifyValue(&Item::m_itemData).ModifyValue(&UF::ItemData::StackCount), value);

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

uint64 Item::CalculateDurabilityRepairCost(float discount) const
{
    uint32 maxDurability = m_itemData->MaxDurability;
    if (!maxDurability)
        return 0;

    uint32 curDurability = m_itemData->Durability;
    ASSERT(maxDurability >= curDurability);

    uint32 lostDurability = maxDurability - curDurability;
    if (!lostDurability)
        return 0;

    ItemTemplate const* itemTemplate = GetTemplate();

    DurabilityCostsEntry const* durabilityCost = sDurabilityCostsStore.LookupEntry(GetItemLevel(GetOwner()));
    if (!durabilityCost)
        return 0;

    uint32 durabilityQualityEntryId = (GetQuality() + 1) * 2;
    DurabilityQualityEntry const* durabilityQualityEntry = sDurabilityQualityStore.LookupEntry(durabilityQualityEntryId);
    if (!durabilityQualityEntry)
        return 0;

    uint32 dmultiplier = 0;
    if (itemTemplate->GetClass() == ITEM_CLASS_WEAPON)
        dmultiplier = durabilityCost->WeaponSubClassCost[itemTemplate->GetSubClass()];
    else if (itemTemplate->GetClass() == ITEM_CLASS_ARMOR)
        dmultiplier = durabilityCost->ArmorSubClassCost[itemTemplate->GetSubClass()];

    uint64 cost = std::round(lostDurability * dmultiplier * durabilityQualityEntry->Data * GetRepairCostMultiplier());
    cost = uint64(cost * discount * sWorld->getRate(RATE_REPAIRCOST));

    if (cost == 0) // Fix for ITEM_QUALITY_ARTIFACT
        cost = 1;

    return cost;
}

bool Item::HasEnchantRequiredSkill(Player const* player) const
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
    int32 level = 0;

    // Check all enchants for required level
    for (uint32 enchant_slot = PERM_ENCHANTMENT_SLOT; enchant_slot < MAX_ENCHANTMENT_SLOT; ++enchant_slot)
        if (uint32 enchant_id = GetEnchantmentId(EnchantmentSlot(enchant_slot)))
            if (SpellItemEnchantmentEntry const* enchantEntry = sSpellItemEnchantmentStore.LookupEntry(enchant_id))
                if (enchantEntry->MinLevel > level)
                    level = enchantEntry->MinLevel;

    return static_cast<uint32>(level);
}

bool Item::IsBoundByEnchant() const
{
    // Check all enchants for soulbound
    for (uint32 enchant_slot = PERM_ENCHANTMENT_SLOT; enchant_slot < MAX_ENCHANTMENT_SLOT; ++enchant_slot)
        if (uint32 enchant_id = GetEnchantmentId(EnchantmentSlot(enchant_slot)))
            if (SpellItemEnchantmentEntry const* enchantEntry = sSpellItemEnchantmentStore.LookupEntry(enchant_id))
                if (enchantEntry->GetFlags().HasFlag(SpellItemEnchantmentFlags::Soulbound))
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
        if (isEnchantSpell && proto->HasFlag(ITEM_FLAG3_CAN_STORE_ENCHANTS))
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
        if (SpellItemEnchantmentEntry const* oldEnchant = sSpellItemEnchantmentStore.LookupEntry(GetEnchantmentId(slot)))
            if (!oldEnchant->GetFlags().HasFlag(SpellItemEnchantmentFlags::DoNotLog))
                owner->GetSession()->SendEnchantmentLog(GetOwnerGUID(), ObjectGuid::Empty, GetGUID(), GetEntry(), oldEnchant->ID, slot);

        if (SpellItemEnchantmentEntry const* newEnchant = sSpellItemEnchantmentStore.LookupEntry(id))
            if (!newEnchant->GetFlags().HasFlag(SpellItemEnchantmentFlags::DoNotLog))
                owner->GetSession()->SendEnchantmentLog(GetOwnerGUID(), caster, GetGUID(), GetEntry(), id, slot);
    }

    ApplyArtifactPowerEnchantmentBonuses(slot, GetEnchantmentId(slot), false, owner);
    ApplyArtifactPowerEnchantmentBonuses(slot, id, true, owner);

    auto enchantmentField = m_values.ModifyValue(&Item::m_itemData).ModifyValue(&UF::ItemData::Enchantment, slot);
    SetUpdateFieldValue(enchantmentField.ModifyValue(&UF::ItemEnchantment::ID), id);
    SetUpdateFieldValue(enchantmentField.ModifyValue(&UF::ItemEnchantment::Duration), duration);
    SetUpdateFieldValue(enchantmentField.ModifyValue(&UF::ItemEnchantment::Charges), charges);
    SetState(ITEM_CHANGED, owner);
}

void Item::SetEnchantmentDuration(EnchantmentSlot slot, uint32 duration, Player* owner)
{
    if (GetEnchantmentDuration(slot) == duration)
        return;

    SetUpdateFieldValue(m_values.ModifyValue(&Item::m_itemData).ModifyValue(&UF::ItemData::Enchantment, slot).ModifyValue(&UF::ItemEnchantment::Duration), duration);
    SetState(ITEM_CHANGED, owner);
    // Cannot use GetOwner() here, has to be passed as an argument to avoid freeze due to hashtable locking
}

void Item::SetEnchantmentCharges(EnchantmentSlot slot, uint32 charges)
{
    if (GetEnchantmentCharges(slot) == charges)
        return;

    SetUpdateFieldValue(m_values.ModifyValue(&Item::m_itemData).ModifyValue(&UF::ItemData::Enchantment, slot).ModifyValue(&UF::ItemEnchantment::Charges), charges);
    SetState(ITEM_CHANGED, GetOwner());
}

void Item::ClearEnchantment(EnchantmentSlot slot)
{
    if (!GetEnchantmentId(slot))
        return;

    auto enchantmentField = m_values.ModifyValue(&Item::m_itemData).ModifyValue(&UF::ItemData::Enchantment, slot);
    SetUpdateFieldValue(enchantmentField.ModifyValue(&UF::ItemEnchantment::ID), 0);
    SetUpdateFieldValue(enchantmentField.ModifyValue(&UF::ItemEnchantment::Duration), 0);
    SetUpdateFieldValue(enchantmentField.ModifyValue(&UF::ItemEnchantment::Charges), 0);
    SetUpdateFieldValue(enchantmentField.ModifyValue(&UF::ItemEnchantment::Field_A), 0);
    SetUpdateFieldValue(enchantmentField.ModifyValue(&UF::ItemEnchantment::Field_B), 0);
    SetState(ITEM_CHANGED, GetOwner());
}

UF::SocketedGem const* Item::GetGem(uint16 slot) const
{
    ASSERT(slot < MAX_GEM_SOCKETS);
    return slot < m_itemData->Gems.size() ? &m_itemData->Gems[slot] : nullptr;
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
                    gemBonus.AddBonusList(bonusListId);

                uint32 gemBaseItemLevel = gemTemplate->GetBaseItemLevel();
                if (gemBonus.PlayerLevelToItemLevelCurveId)
                    if (uint32 scaledIlvl = uint32(sDB2Manager.GetCurveValueAt(gemBonus.PlayerLevelToItemLevelCurveId, gemScalingLevel)))
                        gemBaseItemLevel = scaledIlvl;

                _bonusData.GemRelicType[slot] = gemBonus.RelicType;

                for (uint32 i = 0; i < MAX_ITEM_ENCHANTMENT_EFFECTS; ++i)
                {
                    switch (gemEnchant->Effect[i])
                    {
                        case ITEM_ENCHANTMENT_TYPE_BONUS_LIST_ID:
                        {
                            for (ItemBonusEntry const* itemBonus : ItemBonusMgr::GetItemBonuses(gemEnchant->EffectArg[i]))
                                if (itemBonus->Type == ITEM_BONUS_ITEM_LEVEL)
                                    _bonusData.GemItemLevelBonus[slot] += itemBonus->Value[0];
                            break;
                        }
                        case ITEM_ENCHANTMENT_TYPE_BONUS_LIST_CURVE:
                        {
                            if (uint32 bonusListId = ItemBonusMgr::GetItemBonusListForItemLevelDelta(int16(sDB2Manager.GetCurveValueAt(CURVE_ID_ARTIFACT_RELIC_ITEM_LEVEL_BONUS, gemBaseItemLevel + gemBonus.ItemLevelBonus))))
                                for (ItemBonusEntry const* itemBonus : ItemBonusMgr::GetItemBonuses(bonusListId))
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

    auto gemField = m_values.ModifyValue(&Item::m_itemData).ModifyValue(&UF::ItemData::Gems, slot);
    SetUpdateFieldValue(gemField.ModifyValue(&UF::SocketedGem::ItemID), gem->ItemId);
    SetUpdateFieldValue(gemField.ModifyValue(&UF::SocketedGem::Context), gem->Context);
    for (uint32 i = 0; i < 16; ++i)
        SetUpdateFieldValue(gemField.ModifyValue(&UF::SocketedGem::BonusListIDs, i), gem->BonusListIDs[i]);
}

bool Item::GemsFitSockets() const
{
    for (uint32 gemSlot = 0; gemSlot < MAX_ITEM_PROTO_SOCKETS; ++gemSlot)
    {
        uint8 SocketColor = GetTemplate()->GetSocketColor(gemSlot);

        if (!SocketColor) // no socket slot
            continue;

        if (gemSlot >= m_itemData->Gems.size()) // no gems on this socket
            return false;

        uint8 GemColor = 0;

        uint32 gemid = m_itemData->Gems[gemSlot].ItemID;
        if (gemid)
        {
            ItemTemplate const* gemProto = sObjectMgr->GetItemTemplate(gemid);
            if (gemProto)
            {
                GemPropertiesEntry const* gemProperty = sGemPropertiesStore.LookupEntry(gemProto->GetGemProperties());
                if (gemProperty)
                    GemColor = gemProperty->Type;
            }
        }

        if (!(GemColor & SocketColorToGemTypeMask[SocketColor])) // bad gem color on this socket
            return false;
    }
    return true;
}

uint8 Item::GetGemCountWithID(uint32 GemID) const
{
    return uint8(std::count_if(m_itemData->Gems.begin(), m_itemData->Gems.end(), [GemID](UF::SocketedGem const& gemData)
    {
        return gemData.ItemID == int32(GemID);
    }));
}

uint8 Item::GetGemCountWithLimitCategory(uint32 limitCategory) const
{
    return uint8(std::count_if(m_itemData->Gems.begin(), m_itemData->Gems.end(), [limitCategory](UF::SocketedGem const& gemData)
    {
        ItemTemplate const* gemProto = sObjectMgr->GetItemTemplate(gemData.ItemID);
        if (!gemProto)
            return false;

        return gemProto->GetItemLimitCategory() == limitCategory;
    }));
}

bool Item::IsLimitedToAnotherMapOrZone(uint32 cur_mapId, uint32 cur_zoneId) const
{
    ItemTemplate const* proto = GetTemplate();
    return proto && ((proto->GetMap() && proto->GetMap() != cur_mapId) ||
        ((proto->GetArea(0) && proto->GetArea(0) != cur_zoneId) && (proto->GetArea(1) && proto->GetArea(1) != cur_zoneId)));
}

void Item::SendUpdateSockets()
{
    WorldPackets::Item::SocketGemsSuccess socketGems;
    socketGems.Item = GetGUID();
    GetOwner()->GetSession()->SendPacket(socketGems.Write());
}

// Though the client has the information in the item's data field,
// we have to send SMSG_ITEM_TIME_UPDATE to display the remaining
// time.
void Item::SendTimeUpdate(Player* owner)
{
    uint32 duration = m_itemData->Expiration;
    if (!duration)
        return;

    WorldPackets::Item::ItemTimeUpdate itemTimeUpdate;
    itemTimeUpdate.ItemGuid = GetGUID();
    itemTimeUpdate.DurationLeft = duration;
    owner->GetSession()->SendPacket(itemTimeUpdate.Write());
}

Item* Item::CreateItem(uint32 itemEntry, uint32 count, ItemContext context, Player const* player /*= nullptr*/, bool addDefaultBonuses /*= true*/)
{
    if (count < 1)
        return nullptr;                                        //don't create item at zero count

    ItemTemplate const* proto = sObjectMgr->GetItemTemplate(itemEntry);
    if (proto)
    {
        if (count > proto->GetMaxStackSize())
            count = proto->GetMaxStackSize();

        ASSERT_NODEBUGINFO(count != 0, "proto->Stackable == 0 but checked at loading already");

        Item* item = NewItemOrBag(proto);
        if (item->Create(sObjectMgr->GetGenerator<HighGuid::Item>().Generate(), itemEntry, context, player))
        {
            item->SetCount(count);
            if (addDefaultBonuses)
                item->SetBonuses(ItemBonusMgr::GetBonusListsForItem(itemEntry, context));

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
    Item* newItem = CreateItem(GetEntry(), count, GetContext(), player, false);
    if (!newItem)
        return nullptr;

    newItem->SetCreator(GetCreator());
    newItem->SetGiftCreator(GetGiftCreator());
    newItem->ReplaceAllItemFlags(ItemFieldFlags(*m_itemData->DynamicFlags) & ~(ITEM_FIELD_FLAG_REFUNDABLE | ITEM_FIELD_FLAG_BOP_TRADEABLE));
    newItem->SetExpiration(m_itemData->Expiration);
    newItem->SetBonuses(m_itemData->ItemBonusKey->BonusListIDs);
    newItem->SetFixedLevel(GetModifier(ITEM_MODIFIER_TIMEWALKER_LEVEL));
    // player CAN be NULL in which case we must not update random properties because that accesses player's item update queue
    if (player)
        newItem->SetItemRandomBonusList(m_randomBonusListId);
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

    if (IsBOPTradeable())
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

UF::UpdateFieldFlag Item::GetUpdateFieldFlagsFor(Player const* target) const
{
    if (target->GetGUID() == GetOwnerGUID())
        return UF::UpdateFieldFlag::Owner;

    return UF::UpdateFieldFlag::None;
}

void Item::BuildValuesCreate(ByteBuffer* data, Player const* target) const
{
    UF::UpdateFieldFlag flags = GetUpdateFieldFlagsFor(target);
    std::size_t sizePos = data->wpos();
    *data << uint32(0);
    *data << uint8(flags);
    m_objectData->WriteCreate(*data, flags, this, target);
    m_itemData->WriteCreate(*data, flags, this, target);
    data->put<uint32>(sizePos, data->wpos() - sizePos - 4);
}

void Item::BuildValuesUpdate(ByteBuffer* data, Player const* target) const
{
    UF::UpdateFieldFlag flags = GetUpdateFieldFlagsFor(target);
    std::size_t sizePos = data->wpos();
    *data << uint32(0);
    *data << uint32(m_values.GetChangedObjectTypeMask());

    if (m_values.HasChanged(TYPEID_OBJECT))
        m_objectData->WriteUpdate(*data, flags, this, target);

    if (m_values.HasChanged(TYPEID_ITEM))
        m_itemData->WriteUpdate(*data, flags, this, target);

    data->put<uint32>(sizePos, data->wpos() - sizePos - 4);
}

void Item::BuildValuesUpdateWithFlag(ByteBuffer* data, UF::UpdateFieldFlag flags, Player const* target) const
{
    UpdateMask<NUM_CLIENT_OBJECT_TYPES> valuesMask;
    valuesMask.Set(TYPEID_ITEM);

    std::size_t sizePos = data->wpos();
    *data << uint32(0);
    *data << uint32(valuesMask.GetBlock(0));

    UF::ItemData::Mask mask;
    m_itemData->AppendAllowedFieldsMaskForFlag(mask, flags);
    m_itemData->WriteUpdate(*data, mask, true, this, target);

    data->put<uint32>(sizePos, data->wpos() - sizePos - 4);
}

void Item::BuildValuesUpdateForPlayerWithMask(UpdateData* data, UF::ObjectData::Mask const& requestedObjectMask,
    UF::ItemData::Mask const& requestedItemMask, Player const* target) const
{
    UF::UpdateFieldFlag flags = GetUpdateFieldFlagsFor(target);
    UpdateMask<NUM_CLIENT_OBJECT_TYPES> valuesMask;
    if (requestedObjectMask.IsAnySet())
        valuesMask.Set(TYPEID_OBJECT);

    UF::ItemData::Mask itemMask = requestedItemMask;
    m_itemData->FilterDisallowedFieldsMaskForFlag(itemMask, flags);
    if (itemMask.IsAnySet())
        valuesMask.Set(TYPEID_ITEM);

    ByteBuffer& buffer = PrepareValuesUpdateBuffer(data);
    std::size_t sizePos = buffer.wpos();
    buffer << uint32(0);
    buffer << uint32(valuesMask.GetBlock(0));

    if (valuesMask[TYPEID_OBJECT])
        m_objectData->WriteUpdate(buffer, requestedObjectMask, true, this, target);

    if (valuesMask[TYPEID_ITEM])
        m_itemData->WriteUpdate(buffer, itemMask, true, this, target);

    buffer.put<uint32>(sizePos, buffer.wpos() - sizePos - 4);

    data->AddUpdateBlock();
}

void Item::ValuesUpdateForPlayerWithMaskSender::operator()(Player const* player) const
{
    UpdateData udata(player->GetMapId());
    WorldPacket packet;

    Owner->BuildValuesUpdateForPlayerWithMask(&udata, ObjectMask.GetChangesMask(), ItemMask.GetChangesMask(), player);

    udata.BuildPacket(&packet);
    player->SendDirectMessage(&packet);
}

void Item::ClearUpdateMask(bool remove)
{
    m_values.ClearChangesMask(&Item::m_itemData);
    Object::ClearUpdateMask(remove);
}

bool Item::AddToObjectUpdate()
{
    if (Player* owner = GetOwner())
    {
        owner->GetMap()->AddUpdateObject(this);
        return true;
    }

    return false;
}

void Item::RemoveFromObjectUpdate()
{
    if (Player* owner = GetOwner())
        owner->GetMap()->RemoveUpdateObject(this);
}

void Item::SaveRefundDataToDB()
{
    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEM_REFUND_INSTANCE);
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

void Item::DeleteRefundDataFromDB(CharacterDatabaseTransaction* trans)
{
    if (trans)
    {
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEM_REFUND_INSTANCE);
        stmt->setUInt64(0, GetGUID().GetCounter());
        (*trans)->Append(stmt);

    }
}

void Item::SetNotRefundable(Player* owner, bool changestate /*= true*/, CharacterDatabaseTransaction* trans /*= nullptr*/, bool addToCollection /*= true*/)
{
    if (!IsRefundable())
        return;

    WorldPackets::Item::ItemExpirePurchaseRefund itemExpirePurchaseRefund;
    itemExpirePurchaseRefund.ItemGUID = GetGUID();
    owner->SendDirectMessage(itemExpirePurchaseRefund.Write());

    RemoveItemFlag(ITEM_FIELD_FLAG_REFUNDABLE);
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

uint32 Item::GetPlayedTime() const
{
    return *m_itemData->CreatePlayedTime;
}

bool Item::IsRefundExpired() const
{
    return *m_itemData->CreateTime + 2 * HOUR <= GameTime::GetGameTime();
}

void Item::SetSoulboundTradeable(GuidSet const& allowedLooters)
{
    SetItemFlag(ITEM_FIELD_FLAG_BOP_TRADEABLE);
    allowedGUIDs = allowedLooters;
}

void Item::ClearSoulboundTradeable(Player* currentOwner)
{
    RemoveItemFlag(ITEM_FIELD_FLAG_BOP_TRADEABLE);
    if (allowedGUIDs.empty())
        return;

    currentOwner->GetSession()->GetCollectionMgr()->AddItemAppearance(this);
    allowedGUIDs.clear();
    SetState(ITEM_CHANGED, currentOwner);
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEM_BOP_TRADE);
    stmt->setUInt64(0, GetGUID().GetCounter());
    CharacterDatabase.Execute(stmt);
}

bool Item::CheckSoulboundTradeExpire()
{
    // called from owner's update - GetOwner() MUST be valid
    if (m_itemData->CreatePlayedTime + 4 * HOUR < GetOwner()->GetTotalPlayedTime())
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

    if (proto->HasFlag(ITEM_FLAG2_NO_ALTER_ITEM_VISUAL))
        return false;

    if (!HasStats())
        return false;

    return true;
}

bool Item::HasStats() const
{
    ItemTemplate const* proto = GetTemplate();
    Player const* owner = GetOwner();
    for (uint8 i = 0; i < MAX_ITEM_PROTO_STATS; ++i)
        if ((owner ? GetItemStatValue(i, owner) : proto->GetStatPercentEditor(i)) != 0)
            return true;

    return false;
}

bool Item::HasStats(WorldPackets::Item::ItemInstance const& /*itemInstance*/, BonusData const* bonus)
{
    for (uint8 i = 0; i < MAX_ITEM_PROTO_STATS; ++i)
        if (bonus->StatPercentEditor[i] != 0)
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
    -1,                                                     // INVTYPE_PROFESSION_TOOL
    -1,                                                     // INVTYPE_PROFESSION_GEAR
    -1,                                                     // INVTYPE_EQUIPABLE_SPELL_OFFENSIVE
    -1,                                                     // INVTYPE_EQUIPABLE_SPELL_UTILITY
    -1,                                                     // INVTYPE_EQUIPABLE_SPELL_DEFENSIVE
    -1                                                      // INVTYPE_EQUIPABLE_SPELL_MOBILITY
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

    if (proto->HasFlag(ITEM_FLAG2_OVERRIDE_GOLD_COST))
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

    standardPrice = true;
    return uint32(proto->GetPriceVariance() * typeFactor * baseFactor * qualityFactor * proto->GetPriceRandomValue());
}

uint32 Item::GetSellPrice(Player const* owner) const
{
    return Item::GetSellPrice(GetTemplate(), GetQuality(), GetItemLevel(owner));
}

uint32 Item::GetSellPrice(ItemTemplate const* proto, uint32 quality, uint32 itemLevel)
{
    if (proto->HasFlag(ITEM_FLAG2_OVERRIDE_GOLD_COST))
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

uint32 Item::GetItemLevel(Player const* owner) const
{
    ItemTemplate const* itemTemplate = GetTemplate();
    uint32 minItemLevel = owner->m_unitData->MinItemLevel;
    uint32 minItemLevelCutoff = owner->m_unitData->MinItemLevelCutoff;
    uint32 maxItemLevel = itemTemplate->HasFlag(ITEM_FLAG3_IGNORE_ITEM_LEVEL_CAP_IN_PVP) ? 0 : owner->m_unitData->MaxItemLevel;
    bool pvpBonus = owner->IsUsingPvpItemLevels();
    return Item::GetItemLevel(itemTemplate, _bonusData, owner->GetLevel(), GetModifier(ITEM_MODIFIER_TIMEWALKER_LEVEL),
        minItemLevel, minItemLevelCutoff, maxItemLevel, pvpBonus);
}

uint32 Item::GetItemLevel(ItemTemplate const* itemTemplate, BonusData const& bonusData, uint32 level, uint32 fixedLevel,
    uint32 minItemLevel, uint32 minItemLevelCutoff, uint32 maxItemLevel, bool pvpBonus)
{
    if (!itemTemplate)
        return MIN_ITEM_LEVEL;

    uint32 itemLevel = itemTemplate->GetBaseItemLevel();
    if (bonusData.PlayerLevelToItemLevelCurveId)
    {
        if (fixedLevel)
            level = fixedLevel;
        else if (Optional<ContentTuningLevels> levels = sDB2Manager.GetContentTuningData(bonusData.ContentTuningId, 0, true))
            level = std::min(std::max(int16(level), levels->MinLevel), levels->MaxLevel);

        itemLevel = uint32(sDB2Manager.GetCurveValueAt(bonusData.PlayerLevelToItemLevelCurveId, level));
    }

    itemLevel += bonusData.ItemLevelBonus;

    for (uint32 i = 0; i < MAX_ITEM_PROTO_SOCKETS; ++i)
        itemLevel += bonusData.GemItemLevelBonus[i];

    uint32 itemLevelBeforeUpgrades = itemLevel;

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

float Item::GetItemStatValue(uint32 index, Player const* owner) const
{
    ASSERT(index < MAX_ITEM_PROTO_STATS);
    switch (GetItemStatType(index))
    {
        case ITEM_MOD_CORRUPTION:
        case ITEM_MOD_CORRUPTION_RESISTANCE:
            return _bonusData.StatPercentEditor[index];
        default:
            break;
    }

    uint32 itemLevel = GetItemLevel(owner);
    if (float randomPropPoints = GetRandomPropertyPoints(itemLevel, GetQuality(), GetTemplate()->GetInventoryType(), GetTemplate()->GetSubClass()))
    {
        float statValue = float(_bonusData.StatPercentEditor[index] * randomPropPoints) * 0.0001f;
        //if (GtItemSocketCostPerLevelEntry const* gtCost = sItemSocketCostPerLevelGameTable.GetRow(itemLevel))
        //    statValue -= float(int32(_bonusData.ItemStatSocketCostMultiplier[index] * gtCost->SocketCost));

        return statValue;
    }

    return 0.0f;
}

ItemDisenchantLootEntry const* Item::GetDisenchantLoot(Player const* owner) const
{
    if (!_bonusData.CanDisenchant)
        return nullptr;

    return Item::GetDisenchantLoot(GetTemplate(), GetQuality(), GetItemLevel(owner));
}

ItemDisenchantLootEntry const* Item::GetDisenchantLoot(ItemTemplate const* itemTemplate, uint32 quality, uint32 itemLevel)
{
    if (itemTemplate->HasFlag(ITEM_FLAG_CONJURED) || itemTemplate->HasFlag(ITEM_FLAG_NO_DISENCHANT) || itemTemplate->GetBonding() == BIND_QUEST)
        return nullptr;

    if (itemTemplate->GetArea(0) || itemTemplate->GetArea(1) || itemTemplate->GetMap() || itemTemplate->GetMaxStackSize() > 1)
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
    uint32 itemModifiedAppearanceId = GetModifier(AppearanceModifierSlotBySpec[owner->GetActiveTalentGroup()]);
    if (!itemModifiedAppearanceId)
        itemModifiedAppearanceId = GetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_ALL_SPECS);

    if (ItemModifiedAppearanceEntry const* transmog = sItemModifiedAppearanceStore.LookupEntry(itemModifiedAppearanceId))
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
    int32 modifierIndex = m_itemData->Modifiers->Values.FindIndexIf([modifier](UF::ItemMod mod)
    {
        return mod.Type == modifier;
    });

    if (modifierIndex != -1)
        return m_itemData->Modifiers->Values[modifierIndex].Value;

    return 0;
}

void Item::SetModifier(ItemModifier modifier, uint32 value)
{
    int32 modifierIndex = m_itemData->Modifiers->Values.FindIndexIf([modifier](UF::ItemMod mod)
    {
        return mod.Type == modifier;
    });

    if (value)
    {
        if (modifierIndex == -1)
        {
            UF::ItemMod& mod = AddDynamicUpdateFieldValue(m_values.ModifyValue(&Item::m_itemData)
                .ModifyValue(&UF::ItemData::Modifiers).ModifyValue(&UF::ItemModList::Values));

            mod.Value = value;
            mod.Type = modifier;
        }
        else
            SetUpdateFieldValue(m_values.ModifyValue(&Item::m_itemData)
                .ModifyValue(&UF::ItemData::Modifiers)
                .ModifyValue(&UF::ItemModList::Values, modifierIndex)
                .ModifyValue(&UF::ItemMod::Value), value);
    }
    else
    {
        if (modifierIndex == -1)
            return;

        RemoveDynamicUpdateFieldValue(m_values.ModifyValue(&Item::m_itemData).ModifyValue(&UF::ItemData::Modifiers).ModifyValue(&UF::ItemModList::Values), modifierIndex);
    }
}

uint32 Item::GetVisibleEntry(Player const* owner) const
{
    uint32 itemModifiedAppearanceId = GetModifier(AppearanceModifierSlotBySpec[owner->GetActiveTalentGroup()]);
    if (!itemModifiedAppearanceId)
        itemModifiedAppearanceId = GetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_ALL_SPECS);

    if (ItemModifiedAppearanceEntry const* transmog = sItemModifiedAppearanceStore.LookupEntry(itemModifiedAppearanceId))
        return transmog->ItemID;

    return GetEntry();
}

uint16 Item::GetVisibleAppearanceModId(Player const* owner) const
{
    uint32 itemModifiedAppearanceId = GetModifier(AppearanceModifierSlotBySpec[owner->GetActiveTalentGroup()]);
    if (!itemModifiedAppearanceId)
        itemModifiedAppearanceId = GetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_ALL_SPECS);

    if (ItemModifiedAppearanceEntry const* transmog = sItemModifiedAppearanceStore.LookupEntry(itemModifiedAppearanceId))
        return transmog->ItemAppearanceModifierID;

    return uint16(GetAppearanceModId());
}

uint32 Item::GetVisibleModifiedAppearanceId(Player const* owner) const
{
    uint32 itemModifiedAppearanceId = GetModifier(AppearanceModifierSlotBySpec[owner->GetActiveTalentGroup()]);
    if (!itemModifiedAppearanceId)
        itemModifiedAppearanceId = GetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_ALL_SPECS);

    if (!itemModifiedAppearanceId)
        if (ItemModifiedAppearanceEntry const* itemModifiedAppearance = GetItemModifiedAppearance())
            itemModifiedAppearanceId = itemModifiedAppearance->ID;

    return itemModifiedAppearanceId;
}

int32 Item::GetVisibleSecondaryModifiedAppearanceId(Player const* owner) const
{
    uint32 itemModifiedAppearanceId = GetModifier(SecondaryAppearanceModifierSlotBySpec[owner->GetActiveTalentGroup()]);
    if (!itemModifiedAppearanceId)
        itemModifiedAppearanceId = GetModifier(ITEM_MODIFIER_TRANSMOG_SECONDARY_APPEARANCE_ALL_SPECS);

    return itemModifiedAppearanceId;
}

uint32 Item::GetVisibleEnchantmentId(Player const* owner) const
{
    uint32 enchantmentId = GetModifier(IllusionModifierSlotBySpec[owner->GetActiveTalentGroup()]);
    if (!enchantmentId)
        enchantmentId = GetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_ALL_SPECS);

    if (!enchantmentId)
        enchantmentId = GetEnchantmentId(PERM_ENCHANTMENT_SLOT);

    return enchantmentId;
}

uint16 Item::GetVisibleItemVisual(Player const* owner) const
{
    if (SpellItemEnchantmentEntry const* enchant = sSpellItemEnchantmentStore.LookupEntry(GetVisibleEnchantmentId(owner)))
        return enchant->ItemVisual;

    return 0;
}

void Item::AddBonuses(uint32 bonusListID)
{
    if (std::find(GetBonusListIDs().begin(), GetBonusListIDs().end(), int32(bonusListID)) != GetBonusListIDs().end())
        return;

    WorldPackets::Item::ItemBonusKey itemBonusKey;
    itemBonusKey.ItemID = GetEntry();
    itemBonusKey.BonusListIDs = GetBonusListIDs();
    itemBonusKey.BonusListIDs.push_back(bonusListID);
    SetUpdateFieldValue(m_values.ModifyValue(&Item::m_itemData).ModifyValue(&UF::ItemData::ItemBonusKey), std::move(itemBonusKey));
    for (ItemBonusEntry const* bonus : ItemBonusMgr::GetItemBonuses(bonusListID))
        _bonusData.AddBonus(bonus->Type, bonus->Value);
    SetUpdateFieldValue(m_values.ModifyValue(&Item::m_itemData).ModifyValue(&UF::ItemData::ItemAppearanceModID), _bonusData.AppearanceModID);
}

void Item::SetBonuses(std::vector<int32> bonusListIDs)
{
    WorldPackets::Item::ItemBonusKey itemBonusKey;
    itemBonusKey.ItemID = GetEntry();
    itemBonusKey.BonusListIDs = std::move(bonusListIDs);
    SetUpdateFieldValue(m_values.ModifyValue(&Item::m_itemData).ModifyValue(&UF::ItemData::ItemBonusKey), std::move(itemBonusKey));

    for (int32 bonusListID : GetBonusListIDs())
        _bonusData.AddBonusList(bonusListID);

    SetUpdateFieldValue(m_values.ModifyValue(&Item::m_itemData).ModifyValue(&UF::ItemData::ItemAppearanceModID), _bonusData.AppearanceModID);
}

void Item::ClearBonuses()
{
    WorldPackets::Item::ItemBonusKey itemBonusKey;
    itemBonusKey.ItemID = GetEntry();
    SetUpdateFieldValue(m_values.ModifyValue(&Item::m_itemData).ModifyValue(&UF::ItemData::ItemBonusKey), std::move(itemBonusKey));
    _bonusData.Initialize(GetTemplate());
    SetUpdateFieldValue(m_values.ModifyValue(&Item::m_itemData).ModifyValue(&UF::ItemData::ItemAppearanceModID), _bonusData.AppearanceModID);
}

bool Item::IsArtifactDisabled() const
{
    if (ArtifactEntry const* artifact = sArtifactStore.LookupEntry(GetTemplate()->GetArtifactID()))
        return artifact->ArtifactCategoryID != 2; // fishing artifact

    return true;
}

UF::ArtifactPower const* Item::GetArtifactPower(uint32 artifactPowerId) const
{
    auto indexItr = m_artifactPowerIdToIndex.find(artifactPowerId);
    if (indexItr != m_artifactPowerIdToIndex.end())
        return &m_itemData->ArtifactPowers[indexItr->second];

    return nullptr;
}

void Item::AddArtifactPower(ArtifactPowerData const* artifactPower)
{
    uint16 index = uint16(m_artifactPowerIdToIndex.size());
    m_artifactPowerIdToIndex[artifactPower->ArtifactPowerId] = index;

    UF::ArtifactPower& powerField = AddDynamicUpdateFieldValue(m_values.ModifyValue(&Item::m_itemData).ModifyValue(&UF::ItemData::ArtifactPowers));
    powerField.ArtifactPowerID = artifactPower->ArtifactPowerId;
    powerField.PurchasedRank = artifactPower->PurchasedRank;
    powerField.CurrentRankWithBonus = artifactPower->CurrentRankWithBonus;
}

void Item::SetArtifactPower(uint16 artifactPowerId, uint8 purchasedRank, uint8 currentRankWithBonus)
{
    auto indexItr = m_artifactPowerIdToIndex.find(artifactPowerId);
    if (indexItr != m_artifactPowerIdToIndex.end())
    {
        SetUpdateFieldValue(m_values.ModifyValue(&Item::m_itemData)
            .ModifyValue(&UF::ItemData::ArtifactPowers, indexItr->second)
            .ModifyValue(&UF::ArtifactPower::PurchasedRank), purchasedRank);

        SetUpdateFieldValue(m_values.ModifyValue(&Item::m_itemData)
            .ModifyValue(&UF::ItemData::ArtifactPowers, indexItr->second)
            .ModifyValue(&UF::ArtifactPower::CurrentRankWithBonus), currentRankWithBonus);
    }
}

void Item::InitArtifactPowers(uint8 artifactId, uint8 artifactTier)
{
    for (ArtifactPowerEntry const* artifactPower : sDB2Manager.GetArtifactPowers(artifactId))
    {
        if (artifactPower->Tier != artifactTier)
            continue;

        if (m_artifactPowerIdToIndex.find(artifactPower->ID) != m_artifactPowerIdToIndex.end())
            continue;

        ArtifactPowerData powerData;
        powerData.ArtifactPowerId = artifactPower->ID;
        powerData.PurchasedRank = 0;
        powerData.CurrentRankWithBonus = (artifactPower->Flags & ARTIFACT_POWER_FLAG_FIRST) == ARTIFACT_POWER_FLAG_FIRST ? 1 : 0;
        AddArtifactPower(&powerData);
    }
}

uint32 Item::GetTotalUnlockedArtifactPowers() const
{
    uint32 purchased = GetTotalPurchasedArtifactPowers();
    uint64 artifactXp = m_itemData->ArtifactXP;
    //uint32 currentArtifactTier = GetModifier(ITEM_MODIFIER_ARTIFACT_TIER);
    uint32 extraUnlocked = 0;
    do
    {
        uint64 xpCost = 0;
        //if (GtArtifactLevelXPEntry const* cost = sArtifactLevelXPGameTable.GetRow(purchased + extraUnlocked + 1))
        //    xpCost = uint64(currentArtifactTier == MAX_ARTIFACT_TIER ? cost->XP2 : cost->XP);

        if (artifactXp < xpCost)
            break;

        artifactXp -= xpCost;
        ++extraUnlocked;

    } while (true);

    return purchased + extraUnlocked;
}

uint32 Item::GetTotalPurchasedArtifactPowers() const
{
    uint32 purchasedRanks = 0;
    for (UF::ArtifactPower const& power : m_itemData->ArtifactPowers)
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
                    for (uint32 artifactPowerIndex = 0; artifactPowerIndex < m_itemData->ArtifactPowers.size(); ++artifactPowerIndex)
                    {
                        UF::ArtifactPower const& artifactPower = m_itemData->ArtifactPowers[artifactPowerIndex];
                        if (sArtifactPowerStore.AssertEntry(artifactPower.ArtifactPowerID)->Label == enchant->EffectArg[i])
                        {
                            uint8 newRank = artifactPower.CurrentRankWithBonus;
                            if (apply)
                                newRank += enchant->EffectPointsMin[i];
                            else
                                newRank -= enchant->EffectPointsMin[i];

                            SetUpdateFieldValue(m_values.ModifyValue(&Item::m_itemData)
                                .ModifyValue(&UF::ItemData::ArtifactPowers, artifactPowerIndex)
                                .ModifyValue(&UF::ArtifactPower::CurrentRankWithBonus), newRank);

                            if (IsEquipped())
                                if (ArtifactPowerRankEntry const* artifactPowerRank = sDB2Manager.GetArtifactPowerRank(artifactPower.ArtifactPowerID, newRank ? newRank - 1 : 0))
                                    owner->ApplyArtifactPowerRank(this, artifactPowerRank, newRank != 0);
                        }
                    }
                    break;
                case ITEM_ENCHANTMENT_TYPE_ARTIFACT_POWER_BONUS_RANK_BY_ID:
                {
                    if (uint16 const* artifactPowerIndex = Trinity::Containers::MapGetValuePtr(m_artifactPowerIdToIndex, enchant->EffectArg[i]))
                    {
                        uint8 newRank = m_itemData->ArtifactPowers[*artifactPowerIndex].CurrentRankWithBonus;
                        if (apply)
                            newRank += enchant->EffectPointsMin[i];
                        else
                            newRank -= enchant->EffectPointsMin[i];

                        SetUpdateFieldValue(m_values.ModifyValue(&Item::m_itemData)
                            .ModifyValue(&UF::ItemData::ArtifactPowers, *artifactPowerIndex)
                            .ModifyValue(&UF::ArtifactPower::CurrentRankWithBonus), newRank);

                        if (IsEquipped())
                            if (ArtifactPowerRankEntry const* artifactPowerRank = sDB2Manager.GetArtifactPowerRank(m_itemData->ArtifactPowers[*artifactPowerIndex].ArtifactPowerID, newRank ? newRank - 1 : 0))
                                owner->ApplyArtifactPowerRank(this, artifactPowerRank, newRank != 0);
                    }
                    break;
                }
                case ITEM_ENCHANTMENT_TYPE_ARTIFACT_POWER_BONUS_RANK_PICKER:
                    if (slot >= SOCK_ENCHANTMENT_SLOT && slot <= SOCK_ENCHANTMENT_SLOT_3 && _bonusData.GemRelicType[slot - SOCK_ENCHANTMENT_SLOT] != -1)
                    {
                        if (ArtifactPowerPickerEntry const* artifactPowerPicker = sArtifactPowerPickerStore.LookupEntry(enchant->EffectArg[i]))
                        {
                            if (ConditionMgr::IsPlayerMeetingCondition(owner, artifactPowerPicker->PlayerConditionID))
                            {
                                for (uint32 artifactPowerIndex = 0; artifactPowerIndex < m_itemData->ArtifactPowers.size(); ++artifactPowerIndex)
                                {
                                    UF::ArtifactPower const& artifactPower = m_itemData->ArtifactPowers[artifactPowerIndex];
                                    if (sArtifactPowerStore.AssertEntry(artifactPower.ArtifactPowerID)->Label == _bonusData.GemRelicType[slot - SOCK_ENCHANTMENT_SLOT])
                                    {
                                        uint8 newRank = artifactPower.CurrentRankWithBonus;
                                        if (apply)
                                            newRank += enchant->EffectPointsMin[i];
                                        else
                                            newRank -= enchant->EffectPointsMin[i];

                                        SetUpdateFieldValue(m_values.ModifyValue(&Item::m_itemData)
                                            .ModifyValue(&UF::ItemData::ArtifactPowers, artifactPowerIndex)
                                            .ModifyValue(&UF::ArtifactPower::CurrentRankWithBonus), newRank);

                                        if (IsEquipped())
                                            if (ArtifactPowerRankEntry const* artifactPowerRank = sDB2Manager.GetArtifactPowerRank(artifactPower.ArtifactPowerID, newRank ? newRank - 1 : 0))
                                                owner->ApplyArtifactPowerRank(this, artifactPowerRank, newRank != 0);
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

void Item::GiveArtifactXp(uint64 amount, Item* /*sourceItem*/, uint32 artifactCategoryId)
{
    Player* owner = GetOwner();
    if (!owner)
        return;

    if (artifactCategoryId)
    {
        /*
        uint32 artifactKnowledgeLevel = 1;
        if (sourceItem && sourceItem->GetModifier(ITEM_MODIFIER_ARTIFACT_KNOWLEDGE_LEVEL))
            artifactKnowledgeLevel = sourceItem->GetModifier(ITEM_MODIFIER_ARTIFACT_KNOWLEDGE_LEVEL);

        if (GtArtifactKnowledgeMultiplierEntry const* artifactKnowledge = sArtifactKnowledgeMultiplierGameTable.GetRow(artifactKnowledgeLevel))
            amount = uint64(amount * artifactKnowledge->Multiplier);
        */

        if (amount >= 5000)
            amount = 50 * (amount / 50);
        else if (amount >= 1000)
            amount = 25 * (amount / 25);
        else if (amount >= 50)
            amount = 5 * (amount / 5);
    }

    SetArtifactXP(m_itemData->ArtifactXP + amount);

    WorldPackets::Artifact::ArtifactXpGain artifactXpGain;
    artifactXpGain.ArtifactGUID = GetGUID();
    artifactXpGain.Amount = amount;
    owner->SendDirectMessage(artifactXpGain.Write());

    SetState(ITEM_CHANGED, owner);
}

void Item::SetFixedLevel(uint8 level)
{
    if (!_bonusData.HasFixedLevel || GetModifier(ITEM_MODIFIER_TIMEWALKER_LEVEL))
        return;

    if (_bonusData.PlayerLevelToItemLevelCurveId)
    {
        if (Optional<ContentTuningLevels> levels = sDB2Manager.GetContentTuningData(_bonusData.ContentTuningId, 0, true))
            level = std::min(std::max(int16(level), levels->MinLevel), levels->MaxLevel);

        SetModifier(ITEM_MODIFIER_TIMEWALKER_LEVEL, level);
    }
}

int32 Item::GetRequiredLevel() const
{
    int32 fixedLevel = GetModifier(ITEM_MODIFIER_TIMEWALKER_LEVEL);
    if (_bonusData.RequiredLevelCurve)
        return sDB2Manager.GetCurveValueAt(_bonusData.RequiredLevelCurve, fixedLevel);
    if (_bonusData.RequiredLevelOverride)
        return _bonusData.RequiredLevelOverride;
    if (_bonusData.HasFixedLevel && _bonusData.PlayerLevelToItemLevelCurveId)
        return fixedLevel;
    return _bonusData.RequiredLevel;
}

std::string Item::GetDebugInfo() const
{
    std::stringstream sstr;
    sstr << Object::GetDebugInfo() << "\n"
        << std::boolalpha
        << "Owner: " << GetOwnerGUID().ToString() << " Count: " << GetCount()
        << " BagSlot: " << std::to_string(GetBagSlot()) << " Slot: " << std::to_string(GetSlot()) << " Equipped: " << IsEquipped();
    return sstr.str();
}

void BonusData::Initialize(ItemTemplate const* proto)
{
    Quality = proto->GetQuality();
    ItemLevelBonus = 0;
    RequiredLevel = proto->GetBaseRequiredLevel();
    for (uint32 i = 0; i < MAX_ITEM_PROTO_STATS; ++i)
        ItemStatType[i] = proto->GetStatModifierBonusStat(i);

    for (uint32 i = 0; i < MAX_ITEM_PROTO_STATS; ++i)
        StatPercentEditor[i] = proto->GetStatPercentEditor(i);

    for (uint32 i = 0; i < MAX_ITEM_PROTO_STATS; ++i)
        ItemStatSocketCostMultiplier[i] = proto->GetStatPercentageOfSocket(i);

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
    ContentTuningId = proto->GetScalingStatContentTuning();
    PlayerLevelToItemLevelCurveId = proto->GetPlayerLevelToItemLevelCurveId();
    RelicType = -1;
    HasFixedLevel = false;
    RequiredLevelOverride = 0;
    AzeriteTierUnlockSetId = 0;
    if (AzeriteEmpoweredItemEntry const* azeriteEmpoweredItem = sDB2Manager.GetAzeriteEmpoweredItem(proto->GetId()))
        AzeriteTierUnlockSetId = azeriteEmpoweredItem->AzeriteTierUnlockSetID;

    Suffix = 0;
    RequiredLevelCurve = 0;

    EffectCount = 0;
    for (ItemEffectEntry const* itemEffect : proto->Effects)
        Effects[EffectCount++] = itemEffect;

    for (std::size_t i = EffectCount; i < Effects.size(); ++i)
        Effects[i] = nullptr;

    CanDisenchant = !proto->HasFlag(ITEM_FLAG_NO_DISENCHANT);
    CanScrap = proto->HasFlag(ITEM_FLAG4_SCRAPABLE);

    _state.SuffixPriority = std::numeric_limits<int32>::max();
    _state.AppearanceModPriority = std::numeric_limits<int32>::max();
    _state.ScalingStatDistributionPriority = std::numeric_limits<int32>::max();
    _state.AzeriteTierUnlockSetPriority = std::numeric_limits<int32>::max();
    _state.RequiredLevelCurvePriority = std::numeric_limits<int32>::max();
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
            AddBonusList(bonusListID);
}

void BonusData::AddBonusList(uint32 bonusListId)
{
    for (ItemBonusEntry const* bonus : ItemBonusMgr::GetItemBonuses(bonusListId))
        AddBonus(bonus->Type, bonus->Value);
}

void BonusData::AddBonus(uint32 type, std::array<int32, 4> const& values)
{
    switch (type)
    {
        case ITEM_BONUS_ITEM_LEVEL:
            ItemLevelBonus += values[0];
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
                StatPercentEditor[statIndex] += values[1];
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
        case ITEM_BONUS_SUFFIX:
            if (values[1] < _state.SuffixPriority)
            {
                Suffix = static_cast<uint32>(values[0]);
                _state.SuffixPriority = values[1];
            }
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
                ContentTuningId = static_cast<uint32>(values[2]);
                PlayerLevelToItemLevelCurveId = static_cast<uint32>(values[3]);
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
        case ITEM_BONUS_AZERITE_TIER_UNLOCK_SET:
            if (values[1] < _state.AzeriteTierUnlockSetPriority)
            {
                AzeriteTierUnlockSetId = values[0];
                _state.AzeriteTierUnlockSetPriority = values[1];
            }
            break;
        case ITEM_BONUS_OVERRIDE_CAN_DISENCHANT:
            CanDisenchant = values[0] != 0;
            break;
        case ITEM_BONUS_OVERRIDE_CAN_SCRAP:
            CanScrap = values[0] != 0;
            break;
        case ITEM_BONUS_ITEM_EFFECT_ID:
            if (ItemEffectEntry const* itemEffect = sItemEffectStore.LookupEntry(values[0]))
                Effects[EffectCount++] = itemEffect;
            break;
        case ITEM_BONUS_REQUIRED_LEVEL_CURVE:
            if (values[2] < _state.RequiredLevelCurvePriority)
            {
                RequiredLevelCurve = values[0];
                _state.RequiredLevelCurvePriority = values[2];
                if (values[1])
                    ContentTuningId = static_cast<uint32>(values[1]);
            }
            break;
    }
}
