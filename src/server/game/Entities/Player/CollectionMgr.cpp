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

#include "CollectionMgr.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "Item.h"
#include "Log.h"
#include "MiscPackets.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "Timer.h"
#include "TransmogrificationPackets.h"
#include "WorldSession.h"
#include <boost/dynamic_bitset.hpp>

namespace
{
    MountDefinitionMap FactionSpecificMounts;
}

void CollectionMgr::LoadMountDefinitions()
{
    uint32 oldMSTime = getMSTime();

    QueryResult result = WorldDatabase.Query("SELECT spellId, otherFactionSpellId FROM mount_definitions");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 mount definitions. DB table `mount_definitions` is empty.");
        return;
    }

    do
    {
        Field* fields = result->Fetch();

        uint32 spellId = fields[0].GetUInt32();
        uint32 otherFactionSpellId = fields[1].GetUInt32();

        if (!sDB2Manager.GetMount(spellId))
        {
            TC_LOG_ERROR("sql.sql", "Mount spell %u defined in `mount_definitions` does not exist in Mount.db2, skipped", spellId);
            continue;
        }

        if (otherFactionSpellId && !sDB2Manager.GetMount(otherFactionSpellId))
        {
            TC_LOG_ERROR("sql.sql", "otherFactionSpellId %u defined in `mount_definitions` for spell %u does not exist in Mount.db2, skipped", otherFactionSpellId, spellId);
            continue;
        }

        FactionSpecificMounts[spellId] = otherFactionSpellId;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded " SZFMTD " mount definitions in %u ms", FactionSpecificMounts.size(), GetMSTimeDiffToNow(oldMSTime));
}

namespace
{
    EnumFlag<ToyFlags> GetToyFlags(bool isFavourite, bool hasFanfare)
    {
        ToyFlags flags = ToyFlags::None;
        if (isFavourite)
            flags |= ToyFlags::Favorite;

        if (hasFanfare)
            flags |= ToyFlags::HasFanfare;

        return flags;
    }
}

CollectionMgr::CollectionMgr(WorldSession* owner) : _owner(owner), _appearances(std::make_unique<boost::dynamic_bitset<uint32>>())
{
}

CollectionMgr::~CollectionMgr()
{
}

void CollectionMgr::LoadToys()
{
    for (auto const& t : _toys)
        _owner->GetPlayer()->AddToy(t.first, t.second.AsUnderlyingType());
}

bool CollectionMgr::AddToy(uint32 itemId, bool isFavourite, bool hasFanfare)
{
    if (UpdateAccountToys(itemId, isFavourite, hasFanfare))
    {
        _owner->GetPlayer()->AddToy(itemId, GetToyFlags(isFavourite, hasFanfare).AsUnderlyingType());
        return true;
    }

    return false;
}

void CollectionMgr::LoadAccountToys(PreparedQueryResult result)
{
    if (!result)
        return;

    do
    {
        Field* fields = result->Fetch();
        uint32 itemId = fields[0].GetUInt32();
        _toys.emplace(itemId, GetToyFlags(fields[1].GetBool(), fields[2].GetBool()));
    } while (result->NextRow());
}

void CollectionMgr::SaveAccountToys(LoginDatabaseTransaction& trans)
{
    LoginDatabasePreparedStatement* stmt = nullptr;
    for (auto const& toy : _toys)
    {
        stmt = LoginDatabase.GetPreparedStatement(LOGIN_REP_ACCOUNT_TOYS);
        stmt->setUInt32(0, _owner->GetBattlenetAccountId());
        stmt->setUInt32(1, toy.first);
        stmt->setBool(2, toy.second.HasFlag(ToyFlags::Favorite));
        stmt->setBool(3, toy.second.HasFlag(ToyFlags::HasFanfare));
        trans->Append(stmt);
    }
}

bool CollectionMgr::UpdateAccountToys(uint32 itemId, bool isFavourite, bool hasFanfare)
{
    return _toys.insert(ToyBoxContainer::value_type(itemId, GetToyFlags(isFavourite, hasFanfare))).second;
}

void CollectionMgr::ToySetFavorite(uint32 itemId, bool favorite)
{
    ToyBoxContainer::iterator itr = _toys.find(itemId);
    if (itr == _toys.end())
        return;

    if (favorite)
        itr->second |= ToyFlags::Favorite;
    else
        itr->second &= ~ToyFlags::Favorite;
}

void CollectionMgr::ToyClearFanfare(uint32 itemId)
{
    auto itr = _toys.find(itemId);
    if (itr == _toys.end())
        return;

    itr->second &= ~ ToyFlags::HasFanfare;
}

void CollectionMgr::OnItemAdded(Item* item)
{
    if (sDB2Manager.GetHeirloomByItemId(item->GetEntry()))
        AddHeirloom(item->GetEntry(), 0);

    AddItemAppearance(item);
}

void CollectionMgr::LoadAccountHeirlooms(PreparedQueryResult result)
{
    if (!result)
        return;

    do
    {
        Field* fields = result->Fetch();
        uint32 itemId = fields[0].GetUInt32();
        uint32 flags = fields[1].GetUInt32();

        HeirloomEntry const* heirloom = sDB2Manager.GetHeirloomByItemId(itemId);
        if (!heirloom)
            continue;

        uint32 bonusId = 0;

        if (flags & HEIRLOOM_FLAG_BONUS_LEVEL_120)
            bonusId = heirloom->UpgradeItemBonusListID[3];
        else if (flags & HEIRLOOM_FLAG_BONUS_LEVEL_110)
            bonusId = heirloom->UpgradeItemBonusListID[2];
        else if (flags & HEIRLOOM_FLAG_BONUS_LEVEL_100)
            bonusId = heirloom->UpgradeItemBonusListID[1];
        else if (flags & HEIRLOOM_FLAG_BONUS_LEVEL_90)
            bonusId = heirloom->UpgradeItemBonusListID[0];

        _heirlooms[itemId] = HeirloomData(flags, bonusId);
    } while (result->NextRow());
}

void CollectionMgr::SaveAccountHeirlooms(LoginDatabaseTransaction& trans)
{
    LoginDatabasePreparedStatement* stmt = nullptr;
    for (auto const& heirloom : _heirlooms)
    {
        stmt = LoginDatabase.GetPreparedStatement(LOGIN_REP_ACCOUNT_HEIRLOOMS);
        stmt->setUInt32(0, _owner->GetBattlenetAccountId());
        stmt->setUInt32(1, heirloom.first);
        stmt->setUInt32(2, heirloom.second.flags);
        trans->Append(stmt);
    }
}

bool CollectionMgr::UpdateAccountHeirlooms(uint32 itemId, uint32 flags)
{
    return _heirlooms.insert(HeirloomContainer::value_type(itemId, HeirloomData(flags, 0))).second;
}

uint32 CollectionMgr::GetHeirloomBonus(uint32 itemId) const
{
    HeirloomContainer::const_iterator itr = _heirlooms.find(itemId);
    if (itr != _heirlooms.end())
        return itr->second.bonusId;

    return 0;
}

void CollectionMgr::LoadHeirlooms()
{
    for (auto const& item : _heirlooms)
        _owner->GetPlayer()->AddHeirloom(item.first, item.second.flags);
}

void CollectionMgr::AddHeirloom(uint32 itemId, uint32 flags)
{
    if (UpdateAccountHeirlooms(itemId, flags))
        _owner->GetPlayer()->AddHeirloom(itemId, flags);
}

void CollectionMgr::UpgradeHeirloom(uint32 itemId, int32 castItem)
{
    Player* player = _owner->GetPlayer();
    if (!player)
        return;

    HeirloomEntry const* heirloom = sDB2Manager.GetHeirloomByItemId(itemId);
    if (!heirloom)
        return;

    HeirloomContainer::iterator itr = _heirlooms.find(itemId);
    if (itr == _heirlooms.end())
        return;

    uint32 flags = itr->second.flags;
    uint32 bonusId = 0;

    if (heirloom->UpgradeItemID[0] == castItem)
    {
        flags |= HEIRLOOM_FLAG_BONUS_LEVEL_90;
        bonusId = heirloom->UpgradeItemBonusListID[0];
    }
    if (heirloom->UpgradeItemID[1] == castItem)
    {
        flags |= HEIRLOOM_FLAG_BONUS_LEVEL_100;
        bonusId = heirloom->UpgradeItemBonusListID[1];
    }
    if (heirloom->UpgradeItemID[2] == castItem)
    {
        flags |= HEIRLOOM_FLAG_BONUS_LEVEL_110;
        bonusId = heirloom->UpgradeItemBonusListID[2];
    }
    if (heirloom->UpgradeItemID[3] == castItem)
    {
        flags |= HEIRLOOM_FLAG_BONUS_LEVEL_120;
        bonusId = heirloom->UpgradeItemBonusListID[3];
    }

    for (Item* item : player->GetItemListByEntry(itemId, true))
        item->AddBonuses(bonusId);

    // Get heirloom offset to update only one part of dynamic field
    auto const& heirlooms = player->m_activePlayerData->Heirlooms;
    uint32 offset = uint32(std::distance(heirlooms.begin(), std::find(heirlooms.begin(), heirlooms.end(), itemId)));

    player->SetHeirloomFlags(offset, flags);
    itr->second.flags = flags;
    itr->second.bonusId = bonusId;
}

void CollectionMgr::CheckHeirloomUpgrades(Item* item)
{
    Player* player = _owner->GetPlayer();
    if (!player)
        return;

    // Check already owned heirloom for upgrade kits
    if (HeirloomEntry const* heirloom = sDB2Manager.GetHeirloomByItemId(item->GetEntry()))
    {
        HeirloomContainer::iterator itr = _heirlooms.find(item->GetEntry());
        if (itr == _heirlooms.end())
            return;

        // Check for heirloom pairs (normal - heroic, heroic - mythic)
        uint32 heirloomItemId = heirloom->StaticUpgradedItemID;
        uint32 newItemId = 0;
        while (HeirloomEntry const* heirloomDiff = sDB2Manager.GetHeirloomByItemId(heirloomItemId))
        {
            if (player->GetItemByEntry(heirloomDiff->ItemID))
                newItemId = heirloomDiff->ItemID;

            if (HeirloomEntry const* heirloomSub = sDB2Manager.GetHeirloomByItemId(heirloomDiff->StaticUpgradedItemID))
            {
                heirloomItemId = heirloomSub->ItemID;
                continue;
            }

            break;
        }

        if (newItemId)
        {
            auto const& heirlooms = player->m_activePlayerData->Heirlooms;
            uint32 offset = uint32(std::distance(heirlooms.begin(), std::find(heirlooms.begin(), heirlooms.end(), itr->first)));

            player->SetHeirloom(offset, newItemId);
            player->SetHeirloomFlags(offset, 0);

            _heirlooms.erase(itr);
            _heirlooms[newItemId] = 0;

            return;
        }

        auto const& bonusListIDs = item->m_itemData->BonusListIDs;

        for (uint32 bonusId : *bonusListIDs)
        {
            if (bonusId != itr->second.bonusId)
            {
                item->ClearBonuses();
                break;
            }
        }

        if (std::find(bonusListIDs->begin(), bonusListIDs->end(), itr->second.bonusId) == bonusListIDs->end())
            item->AddBonuses(itr->second.bonusId);
    }
}

bool CollectionMgr::CanApplyHeirloomXpBonus(uint32 itemId, uint32 level)
{
    if (!sDB2Manager.GetHeirloomByItemId(itemId))
        return false;

    HeirloomContainer::iterator itr = _heirlooms.find(itemId);
    if (itr == _heirlooms.end())
        return false;

    if (itr->second.flags & HEIRLOOM_FLAG_BONUS_LEVEL_120)
        return level <= 120;
    if (itr->second.flags & HEIRLOOM_FLAG_BONUS_LEVEL_110)
        return level <= 110;
    if (itr->second.flags & HEIRLOOM_FLAG_BONUS_LEVEL_100)
        return level <= 100;
    if (itr->second.flags & HEIRLOOM_FLAG_BONUS_LEVEL_90)
        return level <= 90;

    return level <= 60;
}

void CollectionMgr::LoadMounts()
{
    for (auto const& m : _mounts)
        AddMount(m.first, m.second, false, false);
}

void CollectionMgr::LoadAccountMounts(PreparedQueryResult result)
{
    if (!result)
        return;

    do
    {
        Field* fields = result->Fetch();
        uint32 mountSpellId = fields[0].GetUInt32();
        MountStatusFlags flags = MountStatusFlags(fields[1].GetUInt8());

        if (!sDB2Manager.GetMount(mountSpellId))
            continue;

        _mounts[mountSpellId] = flags;
    } while (result->NextRow());
}

void CollectionMgr::SaveAccountMounts(LoginDatabaseTransaction& trans)
{
    for (auto const& mount : _mounts)
    {
        LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_REP_ACCOUNT_MOUNTS);
        stmt->setUInt32(0, _owner->GetBattlenetAccountId());
        stmt->setUInt32(1, mount.first);
        stmt->setUInt8(2, mount.second);
        trans->Append(stmt);
    }
}

bool CollectionMgr::AddMount(uint32 spellId, MountStatusFlags flags, bool factionMount /*= false*/, bool learned /*= false*/)
{
    Player* player = _owner->GetPlayer();
    if (!player)
        return false;

    MountEntry const* mount = sDB2Manager.GetMount(spellId);
    if (!mount)
        return false;

    MountDefinitionMap::const_iterator itr = FactionSpecificMounts.find(spellId);
    if (itr != FactionSpecificMounts.end() && !factionMount)
        AddMount(itr->second, flags, true, learned);

    _mounts.insert(MountContainer::value_type(spellId, flags));

    // Mount condition only applies to using it, should still learn it.
    if (mount->PlayerConditionID)
    {
        PlayerConditionEntry const* playerCondition = sPlayerConditionStore.LookupEntry(mount->PlayerConditionID);
        if (playerCondition && !ConditionMgr::IsPlayerMeetingCondition(player, playerCondition))
            return false;
    }

    if (!learned)
    {
        if (!factionMount)
            SendSingleMountUpdate(std::make_pair(spellId, flags));
        if (!player->HasSpell(spellId))
            player->LearnSpell(spellId, true);
    }

    return true;
}

void CollectionMgr::MountSetFavorite(uint32 spellId, bool favorite)
{
    auto itr = _mounts.find(spellId);
    if (itr == _mounts.end())
        return;

    if (favorite)
        itr->second = MountStatusFlags(itr->second | MOUNT_IS_FAVORITE);
    else
        itr->second = MountStatusFlags(itr->second & ~MOUNT_IS_FAVORITE);

    SendSingleMountUpdate(*itr);
}

void CollectionMgr::SendSingleMountUpdate(std::pair<uint32, MountStatusFlags> mount)
{
    Player* player = _owner->GetPlayer();
    if (!player)
        return;

    // Temporary container, just need to store only selected mount
    MountContainer tempMounts;
    tempMounts.insert(mount);

    WorldPackets::Misc::AccountMountUpdate mountUpdate;
    mountUpdate.IsFullUpdate = false;
    mountUpdate.Mounts = &tempMounts;
    player->SendDirectMessage(mountUpdate.Write());
}

struct DynamicBitsetBlockOutputIterator : public std::iterator<std::output_iterator_tag, void, void, void, void>
{
    explicit DynamicBitsetBlockOutputIterator(std::function<void(uint32)>&& action) : _action(std::forward<std::function<void(uint32)>>(action)) { }

    DynamicBitsetBlockOutputIterator& operator=(uint32 value)
    {
        _action(value);
        return *this;
    }

    DynamicBitsetBlockOutputIterator& operator*() { return *this; }
    DynamicBitsetBlockOutputIterator& operator++() { return *this; }
    DynamicBitsetBlockOutputIterator operator++(int) { return *this; }

private:
    std::function<void(uint32)> _action;
};

void CollectionMgr::LoadItemAppearances()
{
    Player* owner = _owner->GetPlayer();
    boost::to_block_range(*_appearances, DynamicBitsetBlockOutputIterator([owner](uint32 blockValue)
    {
        owner->AddTransmogBlock(blockValue);
    }));

    for (auto itr = _temporaryAppearances.begin(); itr != _temporaryAppearances.end(); ++itr)
        owner->AddConditionalTransmog(itr->first);
}

void CollectionMgr::LoadAccountItemAppearances(PreparedQueryResult knownAppearances, PreparedQueryResult favoriteAppearances)
{
    if (knownAppearances)
    {
        std::vector<uint32> blocks;
        do
        {
            Field* fields = knownAppearances->Fetch();
            uint16 blobIndex = fields[0].GetUInt16();
            if (blobIndex >= blocks.size())
                blocks.resize(blobIndex + 1);

            blocks[blobIndex] = fields[1].GetUInt32();

        } while (knownAppearances->NextRow());

        _appearances->init_from_block_range(blocks.begin(), blocks.end());
    }

    if (favoriteAppearances)
    {
        do
        {
            _favoriteAppearances[favoriteAppearances->Fetch()[0].GetUInt32()] = FavoriteAppearanceState::Unchanged;
        } while (favoriteAppearances->NextRow());
    }

    // Static item appearances known by every player
    static uint32 constexpr hiddenAppearanceItems[] =
    {
        134110, // Hidden Helm
        134111, // Hidden Cloak
        134112, // Hidden Shoulder
        168659, // Hidden Chestpiece
        142503, // Hidden Shirt
        142504, // Hidden Tabard
        168665, // Hidden Bracers
        158329, // Hidden Gloves
        143539, // Hidden Belt
        168664  // Hidden Boots
    };

    for (uint32 hiddenItem : hiddenAppearanceItems)
    {
        ItemModifiedAppearanceEntry const* hiddenAppearance = sDB2Manager.GetItemModifiedAppearance(hiddenItem, 0);
        ASSERT(hiddenAppearance);
        if (_appearances->size() <= hiddenAppearance->ID)
            _appearances->resize(hiddenAppearance->ID + 1);

        _appearances->set(hiddenAppearance->ID);
    }
}

void CollectionMgr::SaveAccountItemAppearances(LoginDatabaseTransaction& trans)
{
    uint16 blockIndex = 0;
    boost::to_block_range(*_appearances, DynamicBitsetBlockOutputIterator([this, &blockIndex, trans](uint32 blockValue)
    {
        if (blockValue) // this table is only appended/bits are set (never cleared) so don't save empty blocks
        {
            LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_BNET_ITEM_APPEARANCES);
            stmt->setUInt32(0, _owner->GetBattlenetAccountId());
            stmt->setUInt16(1, blockIndex);
            stmt->setUInt32(2, blockValue);
            trans->Append(stmt);
        }

        ++blockIndex;
    }));

    LoginDatabasePreparedStatement* stmt;
    for (auto itr = _favoriteAppearances.begin(); itr != _favoriteAppearances.end();)
    {
        switch (itr->second)
        {
            case FavoriteAppearanceState::New:
                stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_BNET_ITEM_FAVORITE_APPEARANCE);
                stmt->setUInt32(0, _owner->GetBattlenetAccountId());
                stmt->setUInt32(1, itr->first);
                trans->Append(stmt);
                itr->second = FavoriteAppearanceState::Unchanged;
                ++itr;
                break;
            case FavoriteAppearanceState::Removed:
                stmt = LoginDatabase.GetPreparedStatement(LOGIN_DEL_BNET_ITEM_FAVORITE_APPEARANCE);
                stmt->setUInt32(0, _owner->GetBattlenetAccountId());
                stmt->setUInt32(1, itr->first);
                trans->Append(stmt);
                itr = _favoriteAppearances.erase(itr);
                break;
            case FavoriteAppearanceState::Unchanged:
                ++itr;
                break;
        }
    }
}

uint32 const PlayerClassByArmorSubclass[MAX_ITEM_SUBCLASS_ARMOR] =
{
    CLASSMASK_ALL_PLAYABLE,                                                                                                 //ITEM_SUBCLASS_ARMOR_MISCELLANEOUS
    (1 << (CLASS_PRIEST - 1)) | (1 << (CLASS_MAGE - 1)) | (1 << (CLASS_WARLOCK - 1)),                                       //ITEM_SUBCLASS_ARMOR_CLOTH
    (1 << (CLASS_ROGUE - 1)) | (1 << (CLASS_MONK - 1)) | (1 << (CLASS_DRUID - 1)) | (1 << (CLASS_DEMON_HUNTER - 1)),        //ITEM_SUBCLASS_ARMOR_LEATHER
    (1 << (CLASS_HUNTER - 1)) | (1 << (CLASS_SHAMAN - 1)),                                                                  //ITEM_SUBCLASS_ARMOR_MAIL
    (1 << (CLASS_WARRIOR - 1)) | (1 << (CLASS_PALADIN - 1)) | (1 << (CLASS_DEATH_KNIGHT - 1)),                              //ITEM_SUBCLASS_ARMOR_PLATE
    CLASSMASK_ALL_PLAYABLE,                                                                                                 //ITEM_SUBCLASS_ARMOR_BUCKLER
    (1 << (CLASS_WARRIOR - 1)) | (1 << (CLASS_PALADIN - 1)) | (1 << (CLASS_SHAMAN - 1)),                                    //ITEM_SUBCLASS_ARMOR_SHIELD
    1 << (CLASS_PALADIN - 1),                                                                                               //ITEM_SUBCLASS_ARMOR_LIBRAM
    1 << (CLASS_DRUID - 1),                                                                                                 //ITEM_SUBCLASS_ARMOR_IDOL
    1 << (CLASS_SHAMAN - 1),                                                                                                //ITEM_SUBCLASS_ARMOR_TOTEM
    1 << (CLASS_DEATH_KNIGHT - 1),                                                                                          //ITEM_SUBCLASS_ARMOR_SIGIL
    (1 << (CLASS_PALADIN - 1)) | (1 << (CLASS_DEATH_KNIGHT - 1)) | (1 << (CLASS_SHAMAN - 1)) | (1 << (CLASS_DRUID - 1)),    //ITEM_SUBCLASS_ARMOR_RELIC
};

void CollectionMgr::AddItemAppearance(Item* item)
{
    if (!item->IsSoulBound())
        return;

    ItemModifiedAppearanceEntry const* itemModifiedAppearance = item->GetItemModifiedAppearance();
    if (!CanAddAppearance(itemModifiedAppearance))
        return;

    if (item->HasItemFlag(ItemFieldFlags(ITEM_FIELD_FLAG_BOP_TRADEABLE | ITEM_FIELD_FLAG_REFUNDABLE)))
    {
        AddTemporaryAppearance(item->GetGUID(), itemModifiedAppearance);
        return;
    }

    AddItemAppearance(itemModifiedAppearance);
}

void CollectionMgr::AddItemAppearance(uint32 itemId, uint32 appearanceModId /*= 0*/)
{
    ItemModifiedAppearanceEntry const* itemModifiedAppearance = sDB2Manager.GetItemModifiedAppearance(itemId, appearanceModId);
    if (!CanAddAppearance(itemModifiedAppearance))
        return;

    AddItemAppearance(itemModifiedAppearance);
}

void CollectionMgr::AddTransmogSet(uint32 transmogSetId)
{
    std::vector<TransmogSetItemEntry const*> const* items = sDB2Manager.GetTransmogSetItems(transmogSetId);
    if (!items)
        return;

    for (TransmogSetItemEntry const* item : *items)
    {
        ItemModifiedAppearanceEntry const* itemModifiedAppearance = sItemModifiedAppearanceStore.LookupEntry(item->ItemModifiedAppearanceID);
        if (!itemModifiedAppearance)
            continue;

        AddItemAppearance(itemModifiedAppearance);
    }
}

bool CollectionMgr::IsSetCompleted(uint32 transmogSetId) const
{
    std::vector<TransmogSetItemEntry const*> const* transmogSetItems = sDB2Manager.GetTransmogSetItems(transmogSetId);
    if (!transmogSetItems)
        return false;

    std::array<int8, EQUIPMENT_SLOT_END> knownPieces;
    knownPieces.fill(-1);
    for (TransmogSetItemEntry const* transmogSetItem : *transmogSetItems)
    {
        ItemModifiedAppearanceEntry const* itemModifiedAppearance = sItemModifiedAppearanceStore.LookupEntry(transmogSetItem->ItemModifiedAppearanceID);
        if (!itemModifiedAppearance)
            continue;

        ItemEntry const* item = sItemStore.LookupEntry(itemModifiedAppearance->ItemID);
        if (!item)
            continue;

        int32 transmogSlot = ItemTransmogrificationSlots[item->InventoryType];
        if (transmogSlot < 0 || knownPieces[transmogSlot] == 1)
            continue;

        bool hasAppearance, isTemporary;
        std::tie(hasAppearance, isTemporary) = HasItemAppearance(transmogSetItem->ItemModifiedAppearanceID);

        knownPieces[transmogSlot] = (hasAppearance && !isTemporary) ? 1 : 0;
    }

    return std::find(knownPieces.begin(), knownPieces.end(), 0) == knownPieces.end();
}

bool CollectionMgr::CanAddAppearance(ItemModifiedAppearanceEntry const* itemModifiedAppearance) const
{
    if (!itemModifiedAppearance)
        return false;

    if (itemModifiedAppearance->TransmogSourceTypeEnum == 6 || itemModifiedAppearance->TransmogSourceTypeEnum == 9)
        return false;

    if (!sItemSearchNameStore.LookupEntry(itemModifiedAppearance->ItemID))
        return false;

    ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(itemModifiedAppearance->ItemID);
    if (!itemTemplate)
        return false;

    if (!_owner->GetPlayer())
        return false;

    if (_owner->GetPlayer()->CanUseItem(itemTemplate) != EQUIP_ERR_OK)
        return false;

    if (itemTemplate->GetFlags2() & ITEM_FLAG2_NO_SOURCE_FOR_ITEM_VISUAL || itemTemplate->GetQuality() == ITEM_QUALITY_ARTIFACT)
        return false;

    switch (itemTemplate->GetClass())
    {
        case ITEM_CLASS_WEAPON:
        {
            if (!(_owner->GetPlayer()->GetWeaponProficiency() & (1 << itemTemplate->GetSubClass())))
                return false;
            if (itemTemplate->GetSubClass() == ITEM_SUBCLASS_WEAPON_EXOTIC ||
                itemTemplate->GetSubClass() == ITEM_SUBCLASS_WEAPON_EXOTIC2 ||
                itemTemplate->GetSubClass() == ITEM_SUBCLASS_WEAPON_MISCELLANEOUS ||
                itemTemplate->GetSubClass() == ITEM_SUBCLASS_WEAPON_THROWN ||
                itemTemplate->GetSubClass() == ITEM_SUBCLASS_WEAPON_SPEAR ||
                itemTemplate->GetSubClass() == ITEM_SUBCLASS_WEAPON_FISHING_POLE)
                return false;
            break;
        }
        case ITEM_CLASS_ARMOR:
        {
            switch (itemTemplate->GetInventoryType())
            {
                case INVTYPE_BODY:
                case INVTYPE_SHIELD:
                case INVTYPE_CLOAK:
                case INVTYPE_TABARD:
                case INVTYPE_HOLDABLE:
                    break;
                case INVTYPE_HEAD:
                case INVTYPE_SHOULDERS:
                case INVTYPE_CHEST:
                case INVTYPE_WAIST:
                case INVTYPE_LEGS:
                case INVTYPE_FEET:
                case INVTYPE_WRISTS:
                case INVTYPE_HANDS:
                case INVTYPE_ROBE:
                    if (itemTemplate->GetSubClass() == ITEM_SUBCLASS_ARMOR_MISCELLANEOUS)
                        return false;
                    break;
                default:
                    return false;
            }
            if (itemTemplate->GetInventoryType() != INVTYPE_CLOAK)
                if (!(PlayerClassByArmorSubclass[itemTemplate->GetSubClass()] & _owner->GetPlayer()->getClassMask()))
                    return false;
            break;
        }
        default:
            return false;
    }

    if (itemTemplate->GetQuality() < ITEM_QUALITY_UNCOMMON)
        if (!(itemTemplate->GetFlags2() & ITEM_FLAG2_IGNORE_QUALITY_FOR_ITEM_VISUAL_SOURCE) || !(itemTemplate->GetFlags3() & ITEM_FLAG3_ACTS_AS_TRANSMOG_HIDDEN_VISUAL_OPTION))
            return false;

    if (itemModifiedAppearance->ID < _appearances->size() && _appearances->test(itemModifiedAppearance->ID))
        return false;

    return true;
}

void CollectionMgr::AddItemAppearance(ItemModifiedAppearanceEntry const* itemModifiedAppearance)
{
    Player* owner = _owner->GetPlayer();
    if (_appearances->size() <= itemModifiedAppearance->ID)
    {
        std::size_t numBlocks = _appearances->num_blocks();
        _appearances->resize(itemModifiedAppearance->ID + 1);
        numBlocks = _appearances->num_blocks() - numBlocks;
        while (numBlocks--)
            owner->AddTransmogBlock(0);
    }

    _appearances->set(itemModifiedAppearance->ID);
    uint32 blockIndex = itemModifiedAppearance->ID / 32;
    uint32 bitIndex = itemModifiedAppearance->ID % 32;
    owner->AddTransmogFlag(blockIndex, 1 << bitIndex);
    auto temporaryAppearance = _temporaryAppearances.find(itemModifiedAppearance->ID);
    if (temporaryAppearance != _temporaryAppearances.end())
    {
        owner->RemoveConditionalTransmog(itemModifiedAppearance->ID);
        _temporaryAppearances.erase(temporaryAppearance);
    }

    if (ItemEntry const* item = sItemStore.LookupEntry(itemModifiedAppearance->ItemID))
    {
        int32 transmogSlot = ItemTransmogrificationSlots[item->InventoryType];
        if (transmogSlot >= 0)
            _owner->GetPlayer()->UpdateCriteria(CRITERIA_TYPE_APPEARANCE_UNLOCKED_BY_SLOT, transmogSlot, 1);
    }

    if (std::vector<TransmogSetEntry const*> const* sets = sDB2Manager.GetTransmogSetsForItemModifiedAppearance(itemModifiedAppearance->ID))
        for (TransmogSetEntry const* set : *sets)
            if (IsSetCompleted(set->ID))
                _owner->GetPlayer()->UpdateCriteria(CRITERIA_TYPE_TRANSMOG_SET_UNLOCKED, set->TransmogSetGroupID);
}

void CollectionMgr::AddTemporaryAppearance(ObjectGuid const& itemGuid, ItemModifiedAppearanceEntry const* itemModifiedAppearance)
{
    std::unordered_set<ObjectGuid>& itemsWithAppearance = _temporaryAppearances[itemModifiedAppearance->ID];
    if (itemsWithAppearance.empty())
        _owner->GetPlayer()->AddConditionalTransmog(itemModifiedAppearance->ID);

    itemsWithAppearance.insert(itemGuid);
}

void CollectionMgr::RemoveTemporaryAppearance(Item* item)
{
    ItemModifiedAppearanceEntry const* itemModifiedAppearance = item->GetItemModifiedAppearance();
    if (!itemModifiedAppearance)
        return;

    auto itr = _temporaryAppearances.find(itemModifiedAppearance->ID);
    if (itr == _temporaryAppearances.end())
        return;

    itr->second.erase(item->GetGUID());
    if (itr->second.empty())
    {
        _owner->GetPlayer()->RemoveConditionalTransmog(itemModifiedAppearance->ID);
        _temporaryAppearances.erase(itr);
    }
}

std::pair<bool, bool> CollectionMgr::HasItemAppearance(uint32 itemModifiedAppearanceId) const
{
    if (itemModifiedAppearanceId < _appearances->size() && _appearances->test(itemModifiedAppearanceId))
        return{ true, false };

    if (_temporaryAppearances.find(itemModifiedAppearanceId) != _temporaryAppearances.end())
        return{ true,true };

    return{ false,false };
}

std::unordered_set<ObjectGuid> CollectionMgr::GetItemsProvidingTemporaryAppearance(uint32 itemModifiedAppearanceId) const
{
    auto temporaryAppearance = _temporaryAppearances.find(itemModifiedAppearanceId);
    if (temporaryAppearance != _temporaryAppearances.end())
        return temporaryAppearance->second;

    return std::unordered_set<ObjectGuid>();
}

std::unordered_set<uint32> CollectionMgr::GetAppearanceIds() const
{
    std::unordered_set<uint32> appearances;
    std::size_t id = _appearances->find_first();
    while (id != boost::dynamic_bitset<uint32>::npos)
    {
        appearances.insert(sItemModifiedAppearanceStore.AssertEntry(id)->ItemAppearanceID);
        id = _appearances->find_next(id);
    }

    return appearances;
}

void CollectionMgr::SetAppearanceIsFavorite(uint32 itemModifiedAppearanceId, bool apply)
{
    auto itr = _favoriteAppearances.find(itemModifiedAppearanceId);
    if (apply)
    {
        if (itr == _favoriteAppearances.end())
            _favoriteAppearances[itemModifiedAppearanceId] = FavoriteAppearanceState::New;
        else if (itr->second == FavoriteAppearanceState::Removed)
            itr->second = FavoriteAppearanceState::Unchanged;
        else
            return;
    }
    else if (itr != _favoriteAppearances.end())
    {
        if (itr->second == FavoriteAppearanceState::New)
            _favoriteAppearances.erase(itemModifiedAppearanceId);
        else
            itr->second = FavoriteAppearanceState::Removed;
    }
    else
        return;

    WorldPackets::Transmogrification::AccountTransmogUpdate accountTransmogUpdate;
    accountTransmogUpdate.IsFullUpdate = false;
    accountTransmogUpdate.IsSetFavorite = apply;
    accountTransmogUpdate.FavoriteAppearances.push_back(itemModifiedAppearanceId);

    _owner->SendPacket(accountTransmogUpdate.Write());
}

void CollectionMgr::SendFavoriteAppearances() const
{
    WorldPackets::Transmogrification::AccountTransmogUpdate accountTransmogUpdate;
    accountTransmogUpdate.IsFullUpdate = true;
    accountTransmogUpdate.FavoriteAppearances.reserve(_favoriteAppearances.size());
    for (auto itr = _favoriteAppearances.begin(); itr != _favoriteAppearances.end(); ++itr)
        if (itr->second != FavoriteAppearanceState::Removed)
            accountTransmogUpdate.FavoriteAppearances.push_back(itr->first);

    _owner->SendPacket(accountTransmogUpdate.Write());
}
