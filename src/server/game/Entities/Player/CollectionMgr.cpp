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
#include "CollectionPackets.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "Item.h"
#include "Log.h"
#include "MapUtils.h"
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
    std::vector<uint32> DefaultWarbandScenes;
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
            TC_LOG_ERROR("sql.sql", "Mount spell {} defined in `mount_definitions` does not exist in Mount.db2, skipped", spellId);
            continue;
        }

        if (otherFactionSpellId && !sDB2Manager.GetMount(otherFactionSpellId))
        {
            TC_LOG_ERROR("sql.sql", "otherFactionSpellId {} defined in `mount_definitions` for spell {} does not exist in Mount.db2, skipped", otherFactionSpellId, spellId);
            continue;
        }

        FactionSpecificMounts[spellId] = otherFactionSpellId;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} mount definitions in {} ms", FactionSpecificMounts.size(), GetMSTimeDiffToNow(oldMSTime));
}

void CollectionMgr::LoadWarbandSceneDefinitions()
{
    for (WarbandSceneEntry const* warbandScene : sWarbandSceneStore)
        if (warbandScene->GetFlags().HasFlag(WarbandSceneFlags::AwardedAutomatically))
            DefaultWarbandScenes.push_back(warbandScene->ID);
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

CollectionMgr::CollectionMgr(WorldSession* owner) : _owner(owner), _appearances(std::make_unique<boost::dynamic_bitset<uint32>>()), _transmogIllusions(std::make_unique<boost::dynamic_bitset<uint32>>())
{
}

CollectionMgr::~CollectionMgr() = default;

void CollectionMgr::LoadToys()
{
    for (auto const& [itemId, flags] : _toys)
        _owner->GetPlayer()->AddToy(itemId, flags.AsUnderlyingType());
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

void CollectionMgr::SaveAccountToys(LoginDatabaseTransaction trans)
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

        for (int32 upgradeLevel = std::size(heirloom->UpgradeItemID) - 1; upgradeLevel >= 0; --upgradeLevel)
        {
            if (flags & (1 << upgradeLevel))
            {
                bonusId = heirloom->UpgradeItemBonusListID[upgradeLevel];
                break;
            }
        }

        _heirlooms[itemId] = HeirloomData(flags, bonusId);
    } while (result->NextRow());
}

void CollectionMgr::SaveAccountHeirlooms(LoginDatabaseTransaction trans)
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
    {
        _owner->GetPlayer()->UpdateCriteria(CriteriaType::LearnHeirloom, itemId);
        _owner->GetPlayer()->UpdateCriteria(CriteriaType::LearnAnyHeirloom, 1);
        _owner->GetPlayer()->AddHeirloom(itemId, flags);
    }
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

    for (size_t upgradeLevel = 0; upgradeLevel < std::size(heirloom->UpgradeItemID); ++upgradeLevel)
    {
        if (heirloom->UpgradeItemID[upgradeLevel] == castItem)
        {
            flags |= 1 << upgradeLevel;
            bonusId = heirloom->UpgradeItemBonusListID[upgradeLevel];
        }
    }

    for (Item* item : player->GetItemListByEntry(itemId, true))
        item->AddBonuses(bonusId);

    // Get heirloom offset to update only one part of dynamic field
    auto const& heirlooms = player->m_activePlayerData->Heirlooms;
    uint32 offset = uint32(std::ranges::distance(heirlooms.begin(), std::ranges::find(heirlooms, int32(itemId))));

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
            uint32 offset = uint32(std::ranges::distance(heirlooms.begin(), std::ranges::find(heirlooms, int32(itr->first))));

            player->SetHeirloom(offset, newItemId);
            player->SetHeirloomFlags(offset, 0);

            _heirlooms.erase(itr);
            _heirlooms[newItemId] = 0;

            return;
        }

        std::vector<int32> const& bonusListIDs = item->GetBonusListIDs();

        for (uint32 bonusId : bonusListIDs)
        {
            if (bonusId != itr->second.bonusId)
            {
                item->ClearBonuses();
                break;
            }
        }

        if (!advstd::ranges::contains(bonusListIDs, int32(itr->second.bonusId)))
            item->AddBonuses(itr->second.bonusId);
    }
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

void CollectionMgr::SaveAccountMounts(LoginDatabaseTransaction trans)
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
    if (!ConditionMgr::IsPlayerMeetingCondition(player, mount->PlayerConditionID))
        return false;

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

template <std::invocable<uint32> OutputAction>
struct DynamicBitsetBlockOutputIterator
{
    using iterator_category = std::output_iterator_tag;
    using value_type = void;
    using difference_type = void;
    using pointer = void;
    using reference = void;

    explicit DynamicBitsetBlockOutputIterator(OutputAction const& action) : _action(&action) { }

    DynamicBitsetBlockOutputIterator& operator=(uint32 value)
    {
        std::invoke(*_action, value);
        return *this;
    }

    DynamicBitsetBlockOutputIterator& operator*() { return *this; }
    DynamicBitsetBlockOutputIterator& operator++() { return *this; }
    DynamicBitsetBlockOutputIterator operator++(int) { return *this; }

private:
    OutputAction const* _action;
};

void CollectionMgr::LoadItemAppearances()
{
    Player* owner = _owner->GetPlayer();
    boost::to_block_range(*_appearances, DynamicBitsetBlockOutputIterator([owner](uint32 blockValue)
    {
        owner->AddTransmogBlock(blockValue);
    }));

    for (auto const& [itemModifiedAppearanceId, _] : _temporaryAppearances)
        owner->AddConditionalTransmog(itemModifiedAppearanceId);
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
            _favoriteAppearances[favoriteAppearances->Fetch()[0].GetUInt32()] = CollectionItemState::Unchanged;
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

void CollectionMgr::SaveAccountItemAppearances(LoginDatabaseTransaction trans)
{
    uint16 blockIndex = 0;
    boost::to_block_range(*_appearances, DynamicBitsetBlockOutputIterator([this, &blockIndex, trans = trans.get()](uint32 blockValue)
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
            case CollectionItemState::New:
                stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_BNET_ITEM_FAVORITE_APPEARANCE);
                stmt->setUInt32(0, _owner->GetBattlenetAccountId());
                stmt->setUInt32(1, itr->first);
                trans->Append(stmt);
                itr->second = CollectionItemState::Unchanged;
                ++itr;
                break;
            case CollectionItemState::Removed:
                stmt = LoginDatabase.GetPreparedStatement(LOGIN_DEL_BNET_ITEM_FAVORITE_APPEARANCE);
                stmt->setUInt32(0, _owner->GetBattlenetAccountId());
                stmt->setUInt32(1, itr->first);
                trans->Append(stmt);
                itr = _favoriteAppearances.erase(itr);
                break;
            case CollectionItemState::Unchanged:
            case CollectionItemState::Changed:
                ++itr;
                break;
        }
    }
}

constexpr uint32 PlayerClassByArmorSubclass[MAX_ITEM_SUBCLASS_ARMOR] =
{
    CLASSMASK_ALL_PLAYABLE,                                                                                                 //ITEM_SUBCLASS_ARMOR_MISCELLANEOUS
    (1 << (CLASS_PRIEST - 1)) | (1 << (CLASS_MAGE - 1)) | (1 << (CLASS_WARLOCK - 1)),                                       //ITEM_SUBCLASS_ARMOR_CLOTH
    (1 << (CLASS_ROGUE - 1)) | (1 << (CLASS_MONK - 1)) | (1 << (CLASS_DRUID - 1)) | (1 << (CLASS_DEMON_HUNTER - 1)),        //ITEM_SUBCLASS_ARMOR_LEATHER
    (1 << (CLASS_HUNTER - 1)) | (1 << (CLASS_SHAMAN - 1)) | (1 << (CLASS_EVOKER - 1)),                                      //ITEM_SUBCLASS_ARMOR_MAIL
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

    if (item->IsBOPTradeable() || item->IsRefundable())
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

        auto [hasAppearance, isTemporary] = HasItemAppearance(transmogSetItem->ItemModifiedAppearanceID);

        knownPieces[transmogSlot] = (hasAppearance && !isTemporary) ? 1 : 0;
    }

    return !advstd::ranges::contains(knownPieces, 0);
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

    if (itemTemplate->HasFlag(ITEM_FLAG2_NO_SOURCE_FOR_ITEM_VISUAL) || itemTemplate->GetQuality() == ITEM_QUALITY_ARTIFACT)
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
                if (!(PlayerClassByArmorSubclass[itemTemplate->GetSubClass()] & _owner->GetPlayer()->GetClassMask()))
                    return false;
            break;
        }
        default:
            return false;
    }

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

    _owner->GetPlayer()->UpdateCriteria(CriteriaType::LearnAnyTransmog, 1);

    if (ItemEntry const* item = sItemStore.LookupEntry(itemModifiedAppearance->ItemID))
    {
        int32 transmogSlot = ItemTransmogrificationSlots[item->InventoryType];
        if (transmogSlot >= 0)
            _owner->GetPlayer()->UpdateCriteria(CriteriaType::LearnAnyTransmogInSlot, transmogSlot, itemModifiedAppearance->ID);
    }

    if (std::vector<TransmogSetEntry const*> const* sets = sDB2Manager.GetTransmogSetsForItemModifiedAppearance(itemModifiedAppearance->ID))
        for (TransmogSetEntry const* set : *sets)
            if (IsSetCompleted(set->ID))
                _owner->GetPlayer()->UpdateCriteria(CriteriaType::CollectTransmogSetFromGroup, set->TransmogSetGroupID);
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
        return { true, false };

    if (_temporaryAppearances.contains(itemModifiedAppearanceId))
        return { true, true };

    return { false, false };
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
            _favoriteAppearances[itemModifiedAppearanceId] = CollectionItemState::New;
        else if (itr->second == CollectionItemState::Removed)
            itr->second = CollectionItemState::Unchanged;
        else
            return;
    }
    else if (itr != _favoriteAppearances.end())
    {
        if (itr->second == CollectionItemState::New)
            _favoriteAppearances.erase(itemModifiedAppearanceId);
        else
            itr->second = CollectionItemState::Removed;
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
    for (auto [itemModifiedAppearanceId, state] : _favoriteAppearances)
        if (state != CollectionItemState::Removed)
            accountTransmogUpdate.FavoriteAppearances.push_back(itemModifiedAppearanceId);

    _owner->SendPacket(accountTransmogUpdate.Write());
}

void CollectionMgr::LoadTransmogIllusions()
{
    Player* owner = _owner->GetPlayer();
    boost::to_block_range(*_transmogIllusions, DynamicBitsetBlockOutputIterator([owner](uint32 blockValue)
    {
        owner->AddIllusionBlock(blockValue);
    }));
}

void CollectionMgr::LoadAccountTransmogIllusions(PreparedQueryResult knownTransmogIllusions)
{
    if (knownTransmogIllusions)
    {
        std::vector<uint32> blocks;
        do
        {
            Field* fields = knownTransmogIllusions->Fetch();
            uint16 blobIndex = fields[0].GetUInt16();
            if (blobIndex >= blocks.size())
                blocks.resize(blobIndex + 1);

            blocks[blobIndex] = fields[1].GetUInt32();

        } while (knownTransmogIllusions->NextRow());

        _transmogIllusions->init_from_block_range(blocks.begin(), blocks.end());
    }

    // Static illusions known by every player
    static uint16 constexpr defaultIllusions[] =
    {
        3, // Lifestealing
        13, // Crusader
        22, // Striking
        23, // Agility
        34, // Hide Weapon Enchant
        43, // Beastslayer
        44, // Titanguard
    };

    for (uint16 illusionId : defaultIllusions)
    {
        if (_transmogIllusions->size() <= illusionId)
            _transmogIllusions->resize(illusionId + 1);

        _transmogIllusions->set(illusionId);
    }
}

void CollectionMgr::SaveAccountTransmogIllusions(LoginDatabaseTransaction trans)
{
    uint16 blockIndex = 0;

    boost::to_block_range(*_transmogIllusions, DynamicBitsetBlockOutputIterator([this, &blockIndex, trans = trans.get()](uint32 blockValue)
    {
        if (blockValue) // this table is only appended/bits are set (never cleared) so don't save empty blocks
        {
            LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_BNET_TRANSMOG_ILLUSIONS);
            stmt->setUInt32(0, _owner->GetBattlenetAccountId());
            stmt->setUInt16(1, blockIndex);
            stmt->setUInt32(2, blockValue);
            trans->Append(stmt);
        }
        ++blockIndex;
    }));
}

void CollectionMgr::AddTransmogIllusion(uint32 transmogIllusionId)
{
    Player* owner = _owner->GetPlayer();
    if (_transmogIllusions->size() <= transmogIllusionId)
    {
        std::size_t numBlocks = _transmogIllusions->num_blocks();
        _transmogIllusions->resize(transmogIllusionId + 1);
        numBlocks = _transmogIllusions->num_blocks() - numBlocks;
        while (numBlocks--)
            owner->AddIllusionBlock(0);
    }

    _transmogIllusions->set(transmogIllusionId);
    uint32 blockIndex = transmogIllusionId / 32;
    uint32 bitIndex = transmogIllusionId % 32;

    owner->AddIllusionFlag(blockIndex, 1 << bitIndex);
}

bool CollectionMgr::HasTransmogIllusion(uint32 transmogIllusionId) const
{
    return transmogIllusionId < _transmogIllusions->size() && _transmogIllusions->test(transmogIllusionId);
}

void CollectionMgr::LoadWarbandScenes()
{
    Player* owner = _owner->GetPlayer();
    for (auto const& [warbandSceneId, _] : _warbandScenes)
        owner->AddWarbandScenesFlag(warbandSceneId / 32, 1 << warbandSceneId % 32);
}

void CollectionMgr::LoadAccountWarbandScenes(PreparedQueryResult knownWarbandScenes)
{
    if (knownWarbandScenes)
    {
        do
        {
            Field* fields = knownWarbandScenes->Fetch();
            uint32 warbandSceneId = fields[0].GetUInt32();
            if (!sWarbandSceneStore.HasRecord(warbandSceneId))
            {
                _warbandScenes[warbandSceneId].State = CollectionItemState::Removed;
                continue;
            }

            bool isFavorite = fields[1].GetBool();
            bool hasFanfare = fields[2].GetBool();

            WarbandSceneCollectionItem& warbandScene = _warbandScenes.try_emplace(warbandSceneId).first->second;
            if (isFavorite)
                warbandScene.Flags |= WarbandSceneCollectionFlags::Favorite;

            if (hasFanfare)
                warbandScene.Flags |= WarbandSceneCollectionFlags::HasFanfare;

        } while (knownWarbandScenes->NextRow());
    }

    for (uint32 warbandSceneId : DefaultWarbandScenes)
        if (auto [itr, isNew] = _warbandScenes.try_emplace(warbandSceneId); isNew)
            itr->second.State = CollectionItemState::New;
}

void CollectionMgr::SaveAccountWarbandScenes(LoginDatabaseTransaction trans)
{
    LoginDatabasePreparedStatement* stmt;
    for (auto itr = _warbandScenes.begin(); itr != _warbandScenes.end(); )
    {
        auto& [warbandSceneId, data] = *itr;
        switch (data.State)
        {
            case CollectionItemState::New:
                stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_BNET_WARBAND_SCENE);
                stmt->setUInt32(0, _owner->GetBattlenetAccountId());
                stmt->setUInt32(1, warbandSceneId);
                stmt->setBool(2, data.Flags.HasFlag(WarbandSceneCollectionFlags::Favorite));
                stmt->setBool(3, data.Flags.HasFlag(WarbandSceneCollectionFlags::HasFanfare));
                trans->Append(stmt);
                data.State = CollectionItemState::Unchanged;
                ++itr;
                break;
            case CollectionItemState::Changed:
                stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_BNET_WARBAND_SCENE);
                stmt->setBool(0, data.Flags.HasFlag(WarbandSceneCollectionFlags::Favorite));
                stmt->setBool(1, data.Flags.HasFlag(WarbandSceneCollectionFlags::HasFanfare));
                stmt->setUInt32(2, _owner->GetBattlenetAccountId());
                stmt->setUInt32(3, warbandSceneId);
                trans->Append(stmt);
                data.State = CollectionItemState::Unchanged;
                ++itr;
                break;
            case CollectionItemState::Removed:
                stmt = LoginDatabase.GetPreparedStatement(LOGIN_DEL_BNET_WARBAND_SCENE);
                stmt->setUInt32(0, _owner->GetBattlenetAccountId());
                stmt->setUInt32(1, warbandSceneId);
                trans->Append(stmt);
                itr = _warbandScenes.erase(itr);
                break;
            default:
                ++itr;
                break;
        }
    }
}

void CollectionMgr::AddWarbandScene(uint32 warbandSceneId)
{
    if (!sWarbandSceneStore.HasRecord(warbandSceneId))
        return;

    WarbandSceneCollectionItem& warbandScene = _warbandScenes.try_emplace(warbandSceneId).first->second;
    warbandScene.State = CollectionItemState::New;

    uint32 blockIndex = warbandSceneId / 32;
    uint32 bitIndex = warbandSceneId % 32;
    _owner->GetPlayer()->AddWarbandScenesFlag(blockIndex, 1 << bitIndex);
}

bool CollectionMgr::HasWarbandScene(uint32 warbandSceneId) const
{
    return _warbandScenes.contains(warbandSceneId);
}

void CollectionMgr::SetWarbandSceneIsFavorite(uint32 warbandSceneId, bool apply)
{
    WarbandSceneCollectionItem* warbandScene = Trinity::Containers::MapGetValuePtr(_warbandScenes, warbandSceneId);
    if (!warbandScene)
        return;

    if (apply)
        warbandScene->Flags |= WarbandSceneCollectionFlags::Favorite;
    else
        warbandScene->Flags &= ~WarbandSceneCollectionFlags::Favorite;

    if (warbandScene->State == CollectionItemState::Unchanged)
        warbandScene->State = CollectionItemState::Changed;
}

void CollectionMgr::SendWarbandSceneCollectionData() const
{
    WorldPackets::Collections::AccountItemCollectionData accountItemCollection;
    accountItemCollection.Type = ItemCollectionType::WarbandScene;

    for (auto const& [warbandSceneId, data] : _warbandScenes)
    {
        if (data.State == CollectionItemState::Removed)
            continue;

        WorldPackets::Collections::ItemCollectionItemData& item = accountItemCollection.Items.emplace_back();
        item.ID = warbandSceneId;
        item.Type = ItemCollectionType::WarbandScene;
        item.Flags = data.Flags.AsUnderlyingType();
    }

    _owner->SendPacket(accountItemCollection.Write());
}
