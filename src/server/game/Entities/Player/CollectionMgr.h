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

#ifndef CollectionMgr_h__
#define CollectionMgr_h__

#include "Define.h"
#include "DatabaseEnvFwd.h"
#include "EnumFlag.h"
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
    HEIRLOOM_FLAG_UPGRADE_LEVEL_1         = 0x01,
    HEIRLOOM_FLAG_UPGRADE_LEVEL_2         = 0x02,
    HEIRLOOM_FLAG_UPGRADE_LEVEL_3         = 0x04,
    HEIRLOOM_FLAG_UPGRADE_LEVEL_4         = 0x08,
    HEIRLOOM_FLAG_UPGRADE_LEVEL_5         = 0x10,
    HEIRLOOM_FLAG_UPGRADE_LEVEL_6         = 0x20,
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

enum class ToyFlags : uint32
{
    None        = 0,
    Favorite    = 0x01,
    HasFanfare  = 0x02
};

DEFINE_ENUM_FLAG(ToyFlags);

typedef std::map<uint32, EnumFlag<ToyFlags>> ToyBoxContainer;
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
    void SaveAccountToys(LoginDatabaseTransaction& trans);
    void ToySetFavorite(uint32 itemId, bool favorite);
    void ToyClearFanfare(uint32 itemId);

    bool AddToy(uint32 itemId, bool isFavourite, bool hasFanfare);
    bool UpdateAccountToys(uint32 itemId, bool isFavourite, bool hasFanfare);
    bool HasToy(uint32 itemId) const { return _toys.count(itemId) > 0; }

    ToyBoxContainer const& GetAccountToys() const { return _toys; }

    void OnItemAdded(Item* item);

    // Account-wide heirlooms
    void LoadHeirlooms();
    void LoadAccountHeirlooms(PreparedQueryResult result);
    void SaveAccountHeirlooms(LoginDatabaseTransaction& trans);
    void AddHeirloom(uint32 itemId, uint32 flags);
    void UpgradeHeirloom(uint32 itemId, int32 castItem);
    void CheckHeirloomUpgrades(Item* item);

    bool UpdateAccountHeirlooms(uint32 itemId, uint32 flags);
    uint32 GetHeirloomBonus(uint32 itemId) const;
    HeirloomContainer const& GetAccountHeirlooms() const { return _heirlooms; }

    // Account-wide mounts
    void LoadMounts();
    void LoadAccountMounts(PreparedQueryResult result);
    void SaveAccountMounts(LoginDatabaseTransaction& trans);
    bool AddMount(uint32 spellId, MountStatusFlags flags, bool factionMount = false, bool learned = false);
    void MountSetFavorite(uint32 spellId, bool favorite);
    void SendSingleMountUpdate(std::pair<uint32, MountStatusFlags> mount);
    MountContainer const& GetAccountMounts() const { return _mounts; }

    // Appearances
    void LoadItemAppearances();
    void LoadAccountItemAppearances(PreparedQueryResult knownAppearances, PreparedQueryResult favoriteAppearances);
    void SaveAccountItemAppearances(LoginDatabaseTransaction& trans);
    void AddItemAppearance(Item* item);
    void AddItemAppearance(uint32 itemId, uint32 appearanceModId = 0);
    void AddTransmogSet(uint32 transmogSetId);
    bool IsSetCompleted(uint32 transmogSetId) const;
    void RemoveTemporaryAppearance(Item* item);
    // returns pair<hasAppearance, isTemporary>
    std::pair<bool, bool> HasItemAppearance(uint32 itemModifiedAppearanceId) const;
    std::unordered_set<ObjectGuid> GetItemsProvidingTemporaryAppearance(uint32 itemModifiedAppearanceId) const;
    // returns ItemAppearance::ID, not ItemModifiedAppearance::ID
    std::unordered_set<uint32> GetAppearanceIds() const;

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
