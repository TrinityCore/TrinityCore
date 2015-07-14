/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#include "Common.h"
#include "Item.h"
#include "ObjectMgr.h"
#include "WorldPacket.h"
#include "DatabaseEnv.h"
#include "ItemEnchantmentMgr.h"
#include "SpellMgr.h"
#include "SpellInfo.h"
#include "ScriptMgr.h"
#include "ConditionMgr.h"
#include "Player.h"
#include "Opcodes.h"
#include "WorldSession.h"
#include "ItemPackets.h"

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

    ItemSetSpells& spells = sItemSetSpellsStore[setid];

    for (ItemSetSpellEntry const* itemSetSpell : spells)
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

    ItemSetSpells const& spells = sItemSetSpellsStore[setid];
    for (ItemSetSpellEntry const* itemSetSpell : spells)
    {
        // enough for spell
        if (itemSetSpell->Threshold <= eff->EquippedItemCount)
            continue;

        if (!eff->SetBonuses.count(itemSetSpell))
            continue;

        player->ApplyEquipSpell(sSpellMgr->AssertSpellInfo(itemSetSpell->SpellID), nullptr, false);
        eff->SetBonuses.erase(itemSetSpell);
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

Item::Item()
{
    m_objectType |= TYPEMASK_ITEM;
    m_objectTypeId = TYPEID_ITEM;

    m_updateFlag = 0;

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

    memset(_modifiers, 0, sizeof(_modifiers));
    memset(&_bonusData, 0, sizeof(_bonusData));
}

bool Item::Create(ObjectGuid::LowType guidlow, uint32 itemid, Player const* owner)
{
    Object::_Create(ObjectGuid::Create<HighGuid::Item>(guidlow));

    SetEntry(itemid);
    SetObjectScale(1.0f);

    if (owner)
    {
        SetOwnerGUID(owner->GetGUID());
        SetGuidValue(ITEM_FIELD_CONTAINED, owner->GetGUID());
    }

    ItemTemplate const* itemProto = sObjectMgr->GetItemTemplate(itemid);
    if (!itemProto)
        return false;

    _bonusData.Initialize(itemProto);
    SetUInt32Value(ITEM_FIELD_STACK_COUNT, 1);
    SetUInt32Value(ITEM_FIELD_MAXDURABILITY, itemProto->MaxDurability);
    SetUInt32Value(ITEM_FIELD_DURABILITY, itemProto->MaxDurability);

    for (uint8 i = 0; i < itemProto->Effects.size() && i < 5; ++i)
        SetSpellCharges(i, itemProto->Effects[i]->Charges);

    SetUInt32Value(ITEM_FIELD_DURATION, itemProto->GetDuration());
    SetUInt32Value(ITEM_FIELD_CREATE_PLAYED_TIME, 0);
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

            stmt->setInt16 (++index, GetItemRandomPropertyId());
            stmt->setUInt16(++index, GetUInt32Value(ITEM_FIELD_DURABILITY));
            stmt->setUInt32(++index, GetUInt32Value(ITEM_FIELD_CREATE_PLAYED_TIME));
            stmt->setString(++index, m_text);
            stmt->setUInt32(++index, GetModifier(ITEM_MODIFIER_TRANSMOG_ITEM_ID) | (GetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_MOD) << 24));
            stmt->setUInt32(++index, GetModifier(ITEM_MODIFIER_UPGRADE_ID));
            stmt->setUInt32(++index, GetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION));

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
            break;
        }
        case ITEM_REMOVED:
        {
            PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ITEM_INSTANCE);
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
    //                                             0          1            2                3      4         5        6      7             8                 9          10          11    12                  13         14               15            16
    //result = CharacterDatabase.PQuery("SELECT guid, itemEntry, creatorGuid, giftCreatorGuid, count, duration, charges, flags, enchantments, randomPropertyId, durability, playedTime, text, transmogrification, upgradeId, enchantIllusion, bonusListIDs FROM item_instance WHERE guid = '%u'", guid);

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

    bool need_save = false;                                 // need explicit save data at load fixes
    if (uint64 creator = fields[2].GetUInt64())
        SetGuidValue(ITEM_FIELD_CREATOR, ObjectGuid::Create<HighGuid::Player>(creator));
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

    SetUInt32Value(ITEM_FIELD_FLAGS, fields[7].GetUInt32());
    // Remove bind flag for items vs NO_BIND set
    if (IsSoulBound() && proto->GetBonding() == NO_BIND)
    {
        ApplyModFlag(ITEM_FIELD_FLAGS, ITEM_FIELD_FLAG_SOULBOUND, false);
        need_save = true;
    }

    std::string enchants = fields[8].GetString();
    _LoadIntoDataField(enchants, ITEM_FIELD_ENCHANTMENT, MAX_ENCHANTMENT_SLOT * MAX_ENCHANTMENT_OFFSET);
    SetInt32Value(ITEM_FIELD_RANDOM_PROPERTIES_ID, fields[9].GetInt16());
    // recalculate suffix factor
    if (GetItemRandomPropertyId() < 0)
        UpdateItemSuffixFactor();

    uint32 durability = fields[10].GetUInt16();
    SetUInt32Value(ITEM_FIELD_DURABILITY, durability);
    // update max durability (and durability) if need
    SetUInt32Value(ITEM_FIELD_MAXDURABILITY, proto->MaxDurability);
    if (durability > proto->MaxDurability)
    {
        SetUInt32Value(ITEM_FIELD_DURABILITY, proto->MaxDurability);
        need_save = true;
    }

    SetUInt32Value(ITEM_FIELD_CREATE_PLAYED_TIME, fields[11].GetUInt32());
    SetText(fields[12].GetString());

    if (uint32 transmogEntry = fields[13].GetUInt32())
    {
        SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_MOD, (transmogEntry >> 24) & 0xFF);
        SetModifier(ITEM_MODIFIER_TRANSMOG_ITEM_ID, transmogEntry & 0xFFFFFF);
    }
    SetModifier(ITEM_MODIFIER_UPGRADE_ID, fields[14].GetUInt32());
    SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION, fields[15].GetUInt32());

    Tokenizer bonusListIDs(fields[16].GetString(), ' ');
    for (char const* token : bonusListIDs)
    {
        uint32 bonusListID = atoul(token);
        AddBonuses(bonusListID);
    }

    if (need_save)                                           // normal item changed state set not work at loading
    {
        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ITEM_INSTANCE_ON_LOAD);
        stmt->setUInt32(0, GetUInt32Value(ITEM_FIELD_DURATION));
        stmt->setUInt32(1, GetUInt32Value(ITEM_FIELD_FLAGS));
        stmt->setUInt32(2, GetUInt32Value(ITEM_FIELD_DURABILITY));
        stmt->setUInt64(3, guid);
        CharacterDatabase.Execute(stmt);
    }

    return true;
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

Player* Item::GetOwner()const
{
    return ObjectAccessor::FindPlayer(GetOwnerGUID());
}

uint32 Item::GetSkill()
{
    const static uint32 item_weapon_skills[MAX_ITEM_SUBCLASS_WEAPON] =
    {
        SKILL_AXES,     SKILL_2H_AXES,  SKILL_BOWS,          SKILL_GUNS,      SKILL_MACES,
        SKILL_2H_MACES, SKILL_POLEARMS, SKILL_SWORDS,        SKILL_2H_SWORDS, 0,
        SKILL_STAVES,   0,              0,                   SKILL_FIST_WEAPONS,   0,
        SKILL_DAGGERS,  SKILL_THROWN,   SKILL_ASSASSINATION, SKILL_CROSSBOWS, SKILL_WANDS,
        SKILL_FISHING
    };

    const static uint32 item_armor_skills[MAX_ITEM_SUBCLASS_ARMOR] =
    {
        0, SKILL_CLOTH, SKILL_LEATHER, SKILL_MAIL, SKILL_PLATE_MAIL, 0, SKILL_SHIELD, 0, 0, 0, 0
    };

    ItemTemplate const* proto = GetTemplate();

    switch (proto->GetClass())
    {
        case ITEM_CLASS_WEAPON:
            if (proto->GetSubClass() >= MAX_ITEM_SUBCLASS_WEAPON)
                return 0;
            else
                return item_weapon_skills[proto->GetSubClass()];

        case ITEM_CLASS_ARMOR:
            if (proto->GetSubClass() >= MAX_ITEM_SUBCLASS_ARMOR)
                return 0;
            else
                return item_armor_skills[proto->GetSubClass()];

        default:
            return 0;
    }
}

int32 Item::GenerateItemRandomPropertyId(uint32 item_id)
{
    ItemTemplate const* itemProto = sObjectMgr->GetItemTemplate(item_id);

    if (!itemProto)
        return 0;

    // item must have one from this field values not null if it can have random enchantments
    if ((!itemProto->GetRandomProperty()) && (!itemProto->GetRandomSuffix()))
        return 0;

    // item can have not null only one from field values
    if ((itemProto->GetRandomProperty()) && (itemProto->GetRandomSuffix()))
    {
        TC_LOG_ERROR("sql.sql", "Item template %u have RandomProperty == %u and RandomSuffix == %u, but must have one from field =0", itemProto->GetId(), itemProto->GetRandomProperty(), itemProto->GetRandomSuffix());
        return 0;
    }

    // RandomProperty case
    if (itemProto->GetRandomProperty())
    {
        uint32 randomPropId = GetItemEnchantMod(itemProto->GetRandomProperty());
        ItemRandomPropertiesEntry const* random_id = sItemRandomPropertiesStore.LookupEntry(randomPropId);
        if (!random_id)
        {
            TC_LOG_ERROR("sql.sql", "Enchantment id #%u used but it doesn't have records in 'ItemRandomProperties.dbc'", randomPropId);
            return 0;
        }

        return random_id->ID;
    }
    // RandomSuffix case
    else
    {
        uint32 randomPropId = GetItemEnchantMod(itemProto->GetRandomSuffix());
        ItemRandomSuffixEntry const* random_id = sItemRandomSuffixStore.LookupEntry(randomPropId);
        if (!random_id)
        {
            TC_LOG_ERROR("sql.sql", "Enchantment id #%u used but it doesn't have records in sItemRandomSuffixStore.", randomPropId);
            return 0;
        }

        return -int32(random_id->ID);
    }
}

void Item::SetItemRandomProperties(int32 randomPropId)
{
    if (!randomPropId)
        return;

    if (randomPropId > 0)
    {
        ItemRandomPropertiesEntry const* item_rand = sItemRandomPropertiesStore.LookupEntry(randomPropId);
        if (item_rand)
        {
            if (GetInt32Value(ITEM_FIELD_RANDOM_PROPERTIES_ID) != int32(item_rand->ID))
            {
                SetInt32Value(ITEM_FIELD_RANDOM_PROPERTIES_ID, item_rand->ID);
                SetState(ITEM_CHANGED, GetOwner());
            }
            for (uint32 i = PROP_ENCHANTMENT_SLOT_1; i < PROP_ENCHANTMENT_SLOT_1 + 3; ++i)
                SetEnchantment(EnchantmentSlot(i), item_rand->Enchantment[i - PROP_ENCHANTMENT_SLOT_1], 0, 0);
        }
    }
    else
    {
        ItemRandomSuffixEntry const* item_rand = sItemRandomSuffixStore.LookupEntry(-randomPropId);
        if (item_rand)
        {
            if (GetInt32Value(ITEM_FIELD_RANDOM_PROPERTIES_ID) != -int32(item_rand->ID) ||
                !GetItemSuffixFactor())
            {
                SetInt32Value(ITEM_FIELD_RANDOM_PROPERTIES_ID, -int32(item_rand->ID));
                UpdateItemSuffixFactor();
                SetState(ITEM_CHANGED, GetOwner());
            }

            for (uint32 i = PROP_ENCHANTMENT_SLOT_0; i <= PROP_ENCHANTMENT_SLOT_4; ++i)
                SetEnchantment(EnchantmentSlot(i), item_rand->Enchantment[i - PROP_ENCHANTMENT_SLOT_0], 0, 0);
        }
    }
}

void Item::UpdateItemSuffixFactor()
{
    uint32 suffixFactor = GenerateEnchSuffixFactor(GetEntry());
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
            RemoveFromUpdateQueueOf(forplayer);
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
            AddToUpdateQueueOf(forplayer);
    }
    else
    {
        // unset in queue
        // the item must be removed from the queue manually
        uQueuePos = -1;
        uState = ITEM_UNCHANGED;
    }
}

void Item::AddToUpdateQueueOf(Player* player)
{
    if (IsInUpdateQueue())
        return;

    ASSERT(player != NULL);

    if (player->GetGUID() != GetOwnerGUID())
    {
        TC_LOG_DEBUG("entities.player.items", "Item::AddToUpdateQueueOf - Owner's guid (%s) and player's guid (%s) don't match!",
            GetOwnerGUID().ToString().c_str(), player->GetGUID().ToString().c_str());
        return;
    }

    if (player->m_itemUpdateQueueBlocked)
        return;

    player->m_itemUpdateQueue.push_back(this);
    uQueuePos = player->m_itemUpdateQueue.size()-1;
}

void Item::RemoveFromUpdateQueueOf(Player* player)
{
    if (!IsInUpdateQueue())
        return;

    ASSERT(player != NULL);

    if (player->GetGUID() != GetOwnerGUID())
    {
        TC_LOG_DEBUG("entities.player.items", "Item::RemoveFromUpdateQueueOf - Owner's guid (%s) and player's guid (%s) don't match!",
            GetOwnerGUID().ToString().c_str(), player->GetGUID().ToString().c_str());
        return;
    }

    if (player->m_itemUpdateQueueBlocked)
        return;

    player->m_itemUpdateQueue[uQueuePos] = NULL;
    uQueuePos = -1;
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

    if (IsBag() && (Player::IsBagPos(GetPos()) || !((Bag const*)this)->IsEmpty()))
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

    if (spellInfo->EquippedItemClass != -1)                 // -1 == any item class
    {
        // Special case - accept vellum for armor/weapon requirements
        if ((spellInfo->EquippedItemClass == ITEM_CLASS_ARMOR ||
            spellInfo->EquippedItemClass == ITEM_CLASS_WEAPON) && proto->IsVellum())
            if (spellInfo->IsAbilityOfSkillType(SKILL_ENCHANTING)) // only for enchanting spells
                return true;

        if (spellInfo->EquippedItemClass != int32(proto->GetClass()))
            return false;                                   //  wrong item class

        if (spellInfo->EquippedItemSubClassMask != 0)        // 0 == any subclass
        {
            if ((spellInfo->EquippedItemSubClassMask & (1 << proto->GetSubClass())) == 0)
                return false;                               // subclass not present in mask
        }
    }

    if (spellInfo->EquippedItemInventoryTypeMask != 0)       // 0 == any inventory type
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

    SetUInt32Value(ITEM_FIELD_ENCHANTMENT + slot*MAX_ENCHANTMENT_OFFSET + ENCHANTMENT_ID_OFFSET, id);
    SetUInt32Value(ITEM_FIELD_ENCHANTMENT + slot*MAX_ENCHANTMENT_OFFSET + ENCHANTMENT_DURATION_OFFSET, duration);
    SetUInt32Value(ITEM_FIELD_ENCHANTMENT + slot*MAX_ENCHANTMENT_OFFSET + ENCHANTMENT_CHARGES_OFFSET, charges);
    SetState(ITEM_CHANGED, owner);
}

void Item::SetEnchantmentDuration(EnchantmentSlot slot, uint32 duration, Player* owner)
{
    if (GetEnchantmentDuration(slot) == duration)
        return;

    SetUInt32Value(ITEM_FIELD_ENCHANTMENT + slot*MAX_ENCHANTMENT_OFFSET + ENCHANTMENT_DURATION_OFFSET, duration);
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

bool Item::GemsFitSockets() const
{
    for (uint32 enchant_slot = SOCK_ENCHANTMENT_SLOT; enchant_slot < SOCK_ENCHANTMENT_SLOT+MAX_GEM_SOCKETS; ++enchant_slot)
    {
        uint8 SocketColor = GetTemplate()->GetSocketColor(enchant_slot - SOCK_ENCHANTMENT_SLOT);

        if (!SocketColor) // no socket slot
            continue;

        uint32 enchant_id = GetEnchantmentId(EnchantmentSlot(enchant_slot));
        if (!enchant_id) // no gems on this socket
            return false;

        SpellItemEnchantmentEntry const* enchantEntry = sSpellItemEnchantmentStore.LookupEntry(enchant_id);
        if (!enchantEntry) // invalid gem id on this socket
            return false;

        uint8 GemColor = 0;

        uint32 gemid = enchantEntry->SRCItemID;
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

        if (!(GemColor & SocketColor)) // bad gem color on this socket
            return false;
    }
    return true;
}

uint8 Item::GetGemCountWithID(uint32 GemID) const
{
    uint8 count = 0;
    for (uint32 enchant_slot = SOCK_ENCHANTMENT_SLOT; enchant_slot < SOCK_ENCHANTMENT_SLOT+MAX_GEM_SOCKETS; ++enchant_slot)
    {
        uint32 enchant_id = GetEnchantmentId(EnchantmentSlot(enchant_slot));
        if (!enchant_id)
            continue;

        SpellItemEnchantmentEntry const* enchantEntry = sSpellItemEnchantmentStore.LookupEntry(enchant_id);
        if (!enchantEntry)
            continue;

        if (GemID == enchantEntry->SRCItemID)
            ++count;
    }
    return count;
}

uint8 Item::GetGemCountWithLimitCategory(uint32 limitCategory) const
{
    uint8 count = 0;
    for (uint32 enchant_slot = SOCK_ENCHANTMENT_SLOT; enchant_slot < SOCK_ENCHANTMENT_SLOT+MAX_GEM_SOCKETS; ++enchant_slot)
    {
        uint32 enchant_id = GetEnchantmentId(EnchantmentSlot(enchant_slot));
        if (!enchant_id)
            continue;

        SpellItemEnchantmentEntry const* enchantEntry = sSpellItemEnchantmentStore.LookupEntry(enchant_id);
        if (!enchantEntry)
            continue;

        ItemTemplate const* gemProto = sObjectMgr->GetItemTemplate(enchantEntry->SRCItemID);
        if (!gemProto)
            continue;

        if (gemProto->GetItemLimitCategory() == limitCategory)
            ++count;
    }
    return count;
}

bool Item::IsLimitedToAnotherMapOrZone(uint32 cur_mapId, uint32 cur_zoneId) const
{
    ItemTemplate const* proto = GetTemplate();
    return proto && ((proto->GetMap() && proto->GetMap() != cur_mapId) || (proto->GetArea() && proto->GetArea() != cur_zoneId));
}

void Item::SendUpdateSockets()
{
    WorldPacket data(SMSG_SOCKET_GEMS, 8+4+4+4+4);
    data << GetGUID();
    for (uint32 i = SOCK_ENCHANTMENT_SLOT; i <= BONUS_ENCHANTMENT_SLOT; ++i)
        data << uint32(GetEnchantmentId(EnchantmentSlot(i)));

    GetOwner()->GetSession()->SendPacket(&data);
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

Item* Item::CreateItem(uint32 itemEntry, uint32 count, Player const* player)
{
    if (count < 1)
        return NULL;                                        //don't create item at zero count

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
        ASSERT(false);
    return NULL;
}

Item* Item::CloneItem(uint32 count, Player const* player) const
{
    Item* newItem = CreateItem(GetEntry(), count, player);
    if (!newItem)
        return NULL;

    newItem->SetGuidValue(ITEM_FIELD_CREATOR, GetGuidValue(ITEM_FIELD_CREATOR));
    newItem->SetGuidValue(ITEM_FIELD_GIFTCREATOR, GetGuidValue(ITEM_FIELD_GIFTCREATOR));
    newItem->SetUInt32Value(ITEM_FIELD_FLAGS,        GetUInt32Value(ITEM_FIELD_FLAGS) & ~(ITEM_FIELD_FLAG_REFUNDABLE | ITEM_FIELD_FLAG_BOP_TRADEABLE));
    newItem->SetUInt32Value(ITEM_FIELD_DURATION,     GetUInt32Value(ITEM_FIELD_DURATION));
    // player CAN be NULL in which case we must not update random properties because that accesses player's item update queue
    if (player)
        newItem->SetItemRandomProperties(GetItemRandomPropertyId());
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

    ByteBuffer fieldBuffer;
    UpdateMask updateMask;
    updateMask.SetCount(_dynamicValuesCount);

    uint32* flags = nullptr;
    uint32 visibleFlag = GetDynamicUpdateFieldData(target, flags);

    for (uint16 index = 0; index < _dynamicValuesCount; ++index)
    {
        ByteBuffer buffer;
        std::vector<uint32> const& values = _dynamicValues[index];
        if (_fieldNotifyFlags & flags[index] ||
            ((updateType == UPDATETYPE_VALUES ? _dynamicChangesMask.GetBit(index) : !values.empty()) && (flags[index] & visibleFlag)) ||
            (index == ITEM_DYNAMIC_FIELD_MODIFIERS && (updateType == UPDATETYPE_VALUES ? _changesMask.GetBit(ITEM_FIELD_MODIFIERS_MASK) : GetUInt32Value(ITEM_FIELD_MODIFIERS_MASK) != 0)))
        {
            updateMask.SetBit(index);

            UpdateMask arrayMask;
            if (index != ITEM_DYNAMIC_FIELD_MODIFIERS)
            {
                arrayMask.SetCount(values.size());
                for (std::size_t v = 0; v < values.size(); ++v)
                {
                    if (updateType != UPDATETYPE_VALUES || _dynamicChangesArrayMask[index].GetBit(v))
                    {
                        arrayMask.SetBit(v);
                        buffer << uint32(values[v]);
                    }
                }
            }
            else
            {
                uint32 count = 0;
                arrayMask.SetCount(MAX_ITEM_MODIFIERS);
                for (uint32 v = 0; v < MAX_ITEM_MODIFIERS; ++v)
                {
                    if (uint32 modifier = _modifiers[v])
                    {
                        arrayMask.SetBit(count++);
                        buffer << uint32(modifier);
                    }
                }

            }

            fieldBuffer << uint8(arrayMask.GetBlockCount());
            arrayMask.AppendToPacket(&fieldBuffer);
            fieldBuffer.append(buffer);
        }
    }

    *data << uint8(updateMask.GetBlockCount());
    updateMask.AppendToPacket(data);
    data->append(fieldBuffer);
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
    stmt->setUInt32(2, GetPaidMoney());
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

void Item::SetNotRefundable(Player* owner, bool changestate /*=true*/, SQLTransaction* trans /*=NULL*/)
{
    if (!HasFlag(ITEM_FIELD_FLAGS, ITEM_FIELD_FLAG_REFUNDABLE))
        return;

    RemoveFlag(ITEM_FIELD_FLAGS, ITEM_FIELD_FLAG_REFUNDABLE);
    // Following is not applicable in the trading procedure
    if (changestate)
        SetState(ITEM_CHANGED, owner);

    SetRefundRecipient(ObjectGuid::Empty);
    SetPaidMoney(0);
    SetPaidExtendedCost(0);
    DeleteRefundDataFromDB(trans);

    owner->DeleteRefundReference(GetGUID());
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

bool Item::CanBeTransmogrified() const
{
    ItemTemplate const* proto = GetTemplate();

    if (!proto)
        return false;

    if (proto->GetQuality() == ITEM_QUALITY_LEGENDARY)
        return false;

    if (proto->GetClass() != ITEM_CLASS_ARMOR &&
        proto->GetClass() != ITEM_CLASS_WEAPON)
        return false;

    if (proto->GetClass() == ITEM_CLASS_WEAPON && proto->GetSubClass() == ITEM_SUBCLASS_WEAPON_FISHING_POLE)
        return false;

    if (proto->GetFlags2() & ITEM_FLAG2_CANNOT_BE_TRANSMOG)
        return false;

    if (!HasStats())
        return false;

    return true;
}

bool Item::CanTransmogrify() const
{
    ItemTemplate const* proto = GetTemplate();

    if (!proto)
        return false;

    if (proto->GetFlags2() & ITEM_FLAG2_CANNOT_TRANSMOG)
        return false;

    if (proto->GetQuality() == ITEM_QUALITY_LEGENDARY)
        return false;

    if (proto->GetClass() != ITEM_CLASS_ARMOR &&
        proto->GetClass() != ITEM_CLASS_WEAPON)
        return false;

    if (proto->GetClass() == ITEM_CLASS_WEAPON && proto->GetSubClass() == ITEM_SUBCLASS_WEAPON_FISHING_POLE)
        return false;

    if (proto->GetFlags2() & ITEM_FLAG2_CAN_TRANSMOG)
        return true;

    if (!HasStats())
        return false;

    return true;
}

bool Item::CanTransmogrifyItemWithItem(Item const* transmogrified, Item const* transmogrifier)
{
    if (!transmogrifier || !transmogrified)
        return false;

    ItemTemplate const* proto1 = transmogrifier->GetTemplate(); // source
    ItemTemplate const* proto2 = transmogrified->GetTemplate(); // dest

    if (proto1->GetId() == proto2->GetId())
        return false;

    if (!transmogrified->CanTransmogrify() || !transmogrifier->CanBeTransmogrified())
        return false;

    if (proto1->GetInventoryType() == INVTYPE_BAG ||
        proto1->GetInventoryType() == INVTYPE_RELIC ||
        proto1->GetInventoryType() == INVTYPE_BODY ||
        proto1->GetInventoryType() == INVTYPE_FINGER ||
        proto1->GetInventoryType() == INVTYPE_TRINKET ||
        proto1->GetInventoryType() == INVTYPE_AMMO ||
        proto1->GetInventoryType() == INVTYPE_QUIVER)
        return false;

    if (proto1->GetSubClass() != proto2->GetSubClass() && (proto1->GetClass() != ITEM_CLASS_WEAPON || !proto2->IsRangedWeapon() || !proto1->IsRangedWeapon()))
        return false;

    if (proto1->GetInventoryType() != proto2->GetInventoryType() &&
        (proto1->GetClass() != ITEM_CLASS_WEAPON || (proto2->GetInventoryType() != INVTYPE_WEAPONMAINHAND && proto2->GetInventoryType() != INVTYPE_WEAPONOFFHAND)) &&
        (proto1->GetClass() != ITEM_CLASS_ARMOR || (proto1->GetInventoryType() != INVTYPE_CHEST && proto2->GetInventoryType() != INVTYPE_ROBE && proto1->GetInventoryType() != INVTYPE_ROBE && proto2->GetInventoryType() != INVTYPE_CHEST)))
        return false;

    return true;
}

bool Item::HasStats() const
{
    if (GetItemRandomPropertyId() != 0)
        return true;

    ItemTemplate const* proto = GetTemplate();
    for (uint8 i = 0; i < MAX_ITEM_PROTO_STATS; ++i)
        if (proto->GetItemStatValue(i) != 0)
            return true;

    return false;
}

// used by mail items, transmog cost, stationeryinfo and others
uint32 Item::GetSellPrice(ItemTemplate const* proto, bool& normalSellPrice)
{
    normalSellPrice = true;

    if (proto->GetFlags2() & ITEM_FLAG2_HAS_NORMAL_PRICE)
    {
        return proto->GetBuyPrice();
    }
    else
    {
        ImportPriceQualityEntry const* qualityPrice = sImportPriceQualityStore.LookupEntry(proto->GetQuality() + 1);
        ItemPriceBaseEntry const* basePrice = sItemPriceBaseStore.LookupEntry(proto->GetBaseItemLevel());

        if (!qualityPrice || !basePrice)
            return 0;

        float qualityFactor = qualityPrice->Factor;
        float baseFactor = 0.0f;

        uint32 inventoryType = proto->GetInventoryType();

        if (inventoryType == INVTYPE_WEAPON ||
            inventoryType == INVTYPE_2HWEAPON ||
            inventoryType == INVTYPE_WEAPONMAINHAND ||
            inventoryType == INVTYPE_WEAPONOFFHAND ||
            inventoryType == INVTYPE_RANGED ||
            inventoryType == INVTYPE_THROWN ||
            inventoryType == INVTYPE_RANGEDRIGHT)
            baseFactor = basePrice->WeaponFactor;
        else
            baseFactor = basePrice->ArmorFactor;

        if (inventoryType == INVTYPE_ROBE)
            inventoryType = INVTYPE_CHEST;

        float typeFactor = 0.0f;
        int8 weapType = -1;

        switch (inventoryType)
        {
            case INVTYPE_HEAD:
            case INVTYPE_SHOULDERS:
            case INVTYPE_CHEST:
            case INVTYPE_WAIST:
            case INVTYPE_LEGS:
            case INVTYPE_FEET:
            case INVTYPE_WRISTS:
            case INVTYPE_HANDS:
            case INVTYPE_CLOAK:
            {
                ImportPriceArmorEntry const* armorPrice = sImportPriceArmorStore.LookupEntry(inventoryType);
                if (!armorPrice)
                    return 0;

                switch (proto->GetSubClass())
                {
                    case ITEM_SUBCLASS_ARMOR_MISCELLANEOUS:
                    case ITEM_SUBCLASS_ARMOR_CLOTH:
                        typeFactor = armorPrice->ClothFactor;
                        break;
                    case ITEM_SUBCLASS_ARMOR_LEATHER:
                        typeFactor = armorPrice->LeatherFactor;
                        break;
                    case ITEM_SUBCLASS_ARMOR_MAIL:
                        typeFactor = armorPrice->MailFactor;
                        break;
                    case ITEM_SUBCLASS_ARMOR_PLATE:
                        typeFactor = armorPrice->PlateFactor;
                        break;
                    default:
                        return 0;
                }

                break;
            }
            case INVTYPE_SHIELD:
            {
                ImportPriceShieldEntry const* shieldPrice = sImportPriceShieldStore.LookupEntry(1); // it only has two rows, it's unclear which is the one used
                if (!shieldPrice)
                    return 0;

                typeFactor = shieldPrice->Factor;
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

            typeFactor = weaponPrice->Factor;
        }

        normalSellPrice = false;
        return uint32(qualityFactor * proto->GetUnk1() * proto->GetUnk2() * typeFactor * baseFactor);
    }
}

uint32 Item::GetSpecialPrice(ItemTemplate const* proto, uint32 minimumPrice /*= 10000*/)
{
    uint32 cost = 0;

    if (proto->GetFlags2() & ITEM_FLAG2_HAS_NORMAL_PRICE)
        cost = proto->GetSellPrice();
    else
    {
        bool normalPrice;
        cost = Item::GetSellPrice(proto, normalPrice);

        if (!normalPrice)
        {
            if (proto->GetBuyCount() <= 1)
            {
                ItemClassEntry const* classEntry = sItemClassStore.LookupEntry(proto->GetClass());
                if (classEntry)
                    cost *= classEntry->PriceMod;
                else
                    cost = 0;
            }
            else
                cost /= 4 * proto->GetBuyCount();
        }
        else
            cost = proto->GetSellPrice();
    }

    if (cost < minimumPrice)
        cost = minimumPrice;

    return cost;
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

            // container_id, item_id, item_count, follow_rules, ffa, blocked, counted, under_threshold, needs_quest, rnd_prop, rnd_suffix
            stmt_items->setUInt64(0, loot.containerID.GetCounter());
            stmt_items->setUInt32(1, _li->itemid);
            stmt_items->setUInt32(2, _li->count);
            stmt_items->setBool(3, _li->follow_loot_rules);
            stmt_items->setBool(4, _li->freeforall);
            stmt_items->setBool(5, _li->is_blocked);
            stmt_items->setBool(6, _li->is_counted);
            stmt_items->setBool(7, _li->is_underthreshold);
            stmt_items->setBool(8, _li->needs_quest);
            stmt_items->setInt32(9, _li->randomPropertyId);
            stmt_items->setUInt32(10, _li->randomSuffix);
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

                // item_id, itm_count, follow_rules, ffa, blocked, counted, under_threshold, needs_quest, rnd_prop, rnd_suffix
                loot_item.itemid = fields[0].GetUInt32();
                loot_item.count = fields[1].GetUInt32();
                loot_item.follow_loot_rules = fields[2].GetBool();
                loot_item.freeforall = fields[3].GetBool();
                loot_item.is_blocked = fields[4].GetBool();
                loot_item.is_counted = fields[5].GetBool();
                loot_item.canSave = true;
                loot_item.is_underthreshold = fields[6].GetBool();
                loot_item.needs_quest = fields[7].GetBool();
                loot_item.randomPropertyId = fields[8].GetInt32();
                loot_item.randomSuffix = fields[9].GetUInt32();

                // Copy the extra loot conditions from the item in the loot template
                lt->CopyConditions(&loot_item);

                // If container item is in a bag, add that player as an allowed looter
                if (GetBagSlot())
                    loot_item.allowedGUIDs.insert(GetOwner()->GetGUID());

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
    ItemTemplate const* stats = GetTemplate();
    if (!stats)
        return MIN_ITEM_LEVEL;

    uint32 itemLevel = stats->GetBaseItemLevel();
    if (ScalingStatDistributionEntry const* ssd = sScalingStatDistributionStore.LookupEntry(stats->GetScalingStatDistribution()))
        if (uint32 heirloomIlvl = sDB2Manager.GetHeirloomItemLevel(ssd->ItemLevelCurveID, owner->getLevel()))
            itemLevel = heirloomIlvl;

    return std::min(std::max(itemLevel + _bonusData.ItemLevel, uint32(MIN_ITEM_LEVEL)), uint32(MAX_ITEM_LEVEL));
}

int32 Item::GetItemStatValue(uint32 index, Player const* owner) const
{
    ASSERT(index < MAX_ITEM_PROTO_STATS);
    uint32 itemLevel = GetItemLevel(owner);
    if (uint32 randomPropPoints = GetRandomPropertyPoints(itemLevel, GetQuality(), GetTemplate()->GetInventoryType(), GetTemplate()->GetSubClass()))
    {
        float statValue = float(_bonusData.ItemStatAllocation[index] * randomPropPoints) * 0.0001f;
        if (GtItemSocketCostPerLevelEntry const* gtCost = sGtItemSocketCostPerLevelStore.EvaluateTable(itemLevel - 1, 0))
            statValue -= float(int32(_bonusData.ItemStatSocketCostMultiplier[index] * gtCost->ratio));

        return int32(std::floor(statValue + 0.5f));
    }

    return _bonusData.ItemStatValue[index];
}

uint32 Item::GetDisplayId() const
{
    if (uint32 transmogrification = GetModifier(ITEM_MODIFIER_TRANSMOG_ITEM_ID))
        return sDB2Manager.GetItemDisplayId(transmogrification, GetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_MOD));

    return sDB2Manager.GetItemDisplayId(GetEntry(), GetAppearanceModId());
}

void Item::SetModifier(ItemModifier modifier, uint32 value)
{
    _modifiers[modifier] = value;
    ApplyModFlag(ITEM_FIELD_MODIFIERS_MASK, 1 << modifier, value != 0);
}

uint32 Item::GetVisibleEntry() const
{
    if (uint32 transmogrification = GetModifier(ITEM_MODIFIER_TRANSMOG_ITEM_ID))
        return transmogrification;

    return GetEntry();
}

uint32 Item::GetVisibleAppearanceModId() const
{
    if (uint32 transmogMod = GetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_MOD))
        return transmogMod;

    return GetAppearanceModId();
}

void Item::AddBonuses(uint32 bonusListID)
{
    if (DB2Manager::ItemBonusList const* bonuses = sDB2Manager.GetItemBonusList(bonusListID))
    {
        AddDynamicValue(ITEM_DYNAMIC_FIELD_BONUSLIST_IDS, bonusListID);
        for (ItemBonusEntry const* bonus : *bonuses)
            _bonusData.AddBonus(bonus->Type, bonus->Value);
    }
}

void BonusData::Initialize(ItemTemplate const* proto)
{
    Quality = proto->GetQuality();
    ItemLevel = 0;
    RequiredLevel = proto->GetBaseRequiredLevel();
    for (uint32 i = 0; i < MAX_ITEM_PROTO_STATS; ++i)
        ItemStatType[i] = proto->GetItemStatType(i);

    for (uint32 i = 0; i < MAX_ITEM_PROTO_STATS; ++i)
        ItemStatValue[i] = proto->GetItemStatValue(i);

    for (uint32 i = 0; i < MAX_ITEM_PROTO_STATS; ++i)
        ItemStatAllocation[i] = proto->GetItemStatAllocation(i);

    for (uint32 i = 0; i < MAX_ITEM_PROTO_STATS; ++i)
        ItemStatSocketCostMultiplier[i] = proto->GetItemStatSocketCostMultiplier(i);

    for (uint32 i = 0; i < MAX_ITEM_PROTO_SOCKETS; ++i)
        SocketColor[i] = proto->GetSocketColor(i);

    AppearanceModID = 0;
}

void BonusData::AddBonus(uint32 type, int32 const (&values)[2])
{
    switch (type)
    {
        case ITEM_BONUS_ITEM_LEVEL:
            ItemLevel += values[0];
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
            if (Quality < static_cast<uint32>(values[0]))
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
            if (AppearanceModID < static_cast<uint32>(values[0]))
                AppearanceModID = static_cast<uint32>(values[0]);
            break;
        case ITEM_BONUS_REQUIRED_LEVEL:
            RequiredLevel += values[0];
            break;
    }
}
