/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#ifndef CollectionMgr_h__
#define CollectionMgr_h__

#include "Define.h"
#include "DatabaseEnvFwd.h"
#include "ObjectGuid.h"
#include <boost/dynamic_bitset_fwd.hpp>
#include <map>
#include <unordered_map>
#include <unordered_set>

class Item;
class WorldSession;
struct ItemModifiedAppearanceEntry;

enum HeirloomPlayerFlags
{
    HEIRLOOM_FLAG_NONE                    = 0x00,
    HEIRLOOM_FLAG_BONUS_LEVEL_90          = 0x01,
    HEIRLOOM_FLAG_BONUS_LEVEL_100         = 0x02,
    HEIRLOOM_FLAG_BONUS_LEVEL_110         = 0x04
};

enum HeirloomItemFlags
{
    HEIRLOOM_ITEM_FLAG_NONE               = 0x00,
    HEIRLOOM_ITEM_FLAG_SHOW_ONLY_IF_KNOWN = 0x01,
    HEIRLOOM_ITEM_FLAG_PVP                = 0x02
};

struct HeirloomData
{
    HeirloomData(uint32 _flags = 0, uint32 _bonusId = 0) : flags(_flags), bonusId(_bonusId) { }

    uint32 flags;
    uint32 bonusId;
};

typedef std::map<uint32, bool> ToyBoxContainer;
typedef std::map<uint32, HeirloomData> HeirloomContainer;

enum MountStatusFlags : uint8
{
    MOUNT_STATUS_NONE   = 0x00,
    MOUNT_NEEDS_FANFARE = 0x01,
    MOUNT_IS_FAVORITE   = 0x02
};

typedef std::map<uint32, MountStatusFlags> MountContainer;
typedef std::unordered_map<uint32, uint32> MountDefinitionMap;

class TC_GAME_API CollectionMgr
{
public:
    explicit CollectionMgr(WorldSession* owner);
    ~CollectionMgr();

    static void LoadMountDefinitions();

    // Account-wide toys
    void LoadToys();
    void LoadAccountToys(PreparedQueryResult result);
    void SaveAccountToys(SQLTransaction& trans);
    void ToySetFavorite(uint32 itemId, bool favorite);

    bool AddToy(uint32 itemId, bool isFavourite /*= false*/);
    bool UpdateAccountToys(uint32 itemId, bool isFavourite /*= false*/);
    bool HasToy(uint32 itemId) const { return _toys.count(itemId) > 0; }

    ToyBoxContainer const& GetAccountToys() const { return _toys; }

    void OnItemAdded(Item* item);

    // Account-wide heirlooms
    void LoadHeirlooms();
    void LoadAccountHeirlooms(PreparedQueryResult result);
    void SaveAccountHeirlooms(SQLTransaction& trans);
    void AddHeirloom(uint32 itemId, uint32 flags);
    void UpgradeHeirloom(uint32 itemId, uint32 castItem);
    void CheckHeirloomUpgrades(Item* item);

    bool UpdateAccountHeirlooms(uint32 itemId, uint32 flags);
    bool CanApplyHeirloomXpBonus(uint32 itemId, uint32 level);
    uint32 GetHeirloomBonus(uint32 itemId) const;
    HeirloomContainer const& GetAccountHeirlooms() const { return _heirlooms; }

    // Account-wide mounts
    void LoadMounts();
    void LoadAccountMounts(PreparedQueryResult result);
    void SaveAccountMounts(SQLTransaction& trans);
    bool AddMount(uint32 spellId, MountStatusFlags flags, bool factionMount = false, bool learned = false);
    void MountSetFavorite(uint32 spellId, bool favorite);
    void SendSingleMountUpdate(std::pair<uint32, MountStatusFlags> mount);
    MountContainer const& GetAccountMounts() const { return _mounts; }

    // Appearances
    void LoadItemAppearances();
    void LoadAccountItemAppearances(PreparedQueryResult knownAppearances, PreparedQueryResult favoriteAppearances);
    void SaveAccountItemAppearances(SQLTransaction& trans);
    void AddItemAppearance(Item* item);
    void AddItemAppearance(uint32 itemId, uint32 appearanceModId = 0);
    void AddTransmogSet(uint32 transmogSetId);
    bool IsSetCompleted(uint32 transmogSetId) const;
    void RemoveTemporaryAppearance(Item* item);
    // returns pair<hasAppearance, isTemporary>
    std::pair<bool, bool> HasItemAppearance(uint32 itemModifiedAppearanceId) const;
    std::unordered_set<ObjectGuid> GetItemsProvidingTemporaryAppearance(uint32 itemModifiedAppearanceId) const;

    enum class FavoriteAppearanceState
    {
        New,
        Removed,
        Unchanged
    };

    void SetAppearanceIsFavorite(uint32 itemModifiedAppearanceId, bool apply);
    void SendFavoriteAppearances() const;

private:
    bool CanAddAppearance(ItemModifiedAppearanceEntry const* itemModifiedAppearance) const;
    void AddItemAppearance(ItemModifiedAppearanceEntry const* itemModifiedAppearance);
    void AddTemporaryAppearance(ObjectGuid const& itemGuid, ItemModifiedAppearanceEntry const* itemModifiedAppearance);

    WorldSession* _owner;

    ToyBoxContainer _toys;
    HeirloomContainer _heirlooms;
    MountContainer _mounts;
    std::unique_ptr<boost::dynamic_bitset<uint32>> _appearances;
    std::unordered_map<uint32, std::unordered_set<ObjectGuid>> _temporaryAppearances;
    std::unordered_map<uint32, FavoriteAppearanceState> _favoriteAppearances;
};

#endif // CollectionMgr_h__
