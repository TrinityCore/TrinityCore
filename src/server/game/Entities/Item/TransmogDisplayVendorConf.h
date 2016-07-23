#ifndef DEF_TRANSMOGRIFICATION_DISPLAY_H
#define DEF_TRANSMOGRIFICATION_DISPLAY_H

/*
Transmogrification display vendor
Code by Rochet2
Ideas LilleCarl

ScriptName for NPC:
NPC_TransmogDisplayVendor

Compatible with Transmogrification 6.1 by Rochet2
http://rochet2.github.io/Transmogrification
*/

// use 0 or 1
#define TRANSMOGRIFICATION_ALREADY_INSTALLED    0
// Note! If you use both, set this to true (1) and in scriptloader make transmog load first

#include "Define.h"
#include "ItemTemplate.h"
#include "SharedDefines.h"
#include <set>
#include <vector>
#include <unordered_map>
#include <boost/thread/locks.hpp>
#include <boost/thread/shared_mutex.hpp>

class Creature;
class Item;
class Player;
class WorldSession;
struct ItemTemplate;

enum TransmogDisplayVendorSenders
{
    SENDER_START = MAX_ITEM_QUALITY,
    SENDER_BACK,
    SENDER_SELECT_VENDOR,
    SENDER_REMOVE_ALL,
    SENDER_REMOVE_ONE,
    SENDER_REMOVE_MENU,
    SENDER_END,
};

namespace
{
    class RWLockable
    {
    public:
        typedef boost::shared_mutex LockType;
        typedef boost::shared_lock<boost::shared_mutex> ReadGuard;
        typedef boost::unique_lock<boost::shared_mutex> WriteGuard;
        LockType& GetLock() { return _lock; }
    private:
        LockType _lock;
    };
};

class TC_GAME_API SelectionStore : public RWLockable
{
public:
    struct Selection { uint32 item; uint8 slot; uint32 offset; uint32 quality; };
    typedef std::unordered_map<uint32, Selection> PlayerLowToSelection;

    void SetSelection(uint32 playerLow, const Selection& selection)
    {
        WriteGuard guard(GetLock());
        hashmap[playerLow] = selection;
    }

    bool GetSelection(uint32 playerLow, Selection& returnVal)
    {
        ReadGuard guard(GetLock());

        PlayerLowToSelection::iterator it = hashmap.find(playerLow);
        if (it == hashmap.end())
            return false;

        returnVal = it->second;
        return true;
    }

    void RemoveSelection(uint32 playerLow)
    {
        WriteGuard guard(GetLock());
        hashmap.erase(playerLow);
    }

private:
    PlayerLowToSelection hashmap;
};

class TC_GAME_API TransmogDisplayVendorMgr
{
public:
    // Selection store
    static SelectionStore selectionStore; // selectionStore[lowGUID] = Selection

    // Vendor data store
    // optionMap[Class? + SubClass][invtype][Quality] = EntryVector
    typedef std::vector<uint32> EntryVector;
    static EntryVector* optionMap[MAX_ITEM_SUBCLASS_WEAPON + MAX_ITEM_SUBCLASS_ARMOR][MAX_INVTYPE][MAX_ITEM_QUALITY];

    static const std::set<uint32> AllowedItems;
    static const std::set<uint32> NotAllowedItems;

    static const float ScaledCostModifier;
    static const int32 CopperCost;

    static const bool RequireToken;
    static const uint32 TokenEntry;
    static const uint32 TokenAmount;

    static const bool AllowPoor;
    static const bool AllowCommon;
    static const bool AllowUncommon;
    static const bool AllowRare;
    static const bool AllowEpic;
    static const bool AllowLegendary;
    static const bool AllowArtifact;
    static const bool AllowHeirloom;

    static const bool AllowMixedArmorTypes;
    static const bool AllowMixedWeaponTypes;
    static const bool AllowFishingPoles;

    static const bool IgnoreReqRace;
    static const bool IgnoreReqClass;
    static const bool IgnoreReqSkill;
    static const bool IgnoreReqSpell;
    static const bool IgnoreReqLevel;
    static const bool IgnoreReqEvent;
    static const bool IgnoreReqStats;

    static std::vector<uint32> Allowed;
    static std::vector<uint32> NotAllowed;

    static void HandleTransmogrify(Player* player, Creature* creature, uint32 vendorslot, uint32 itemEntry, bool no_cost = false);

    static const char* getQualityName(uint32 quality);
    static std::string getItemName(const ItemTemplate* itemTemplate, WorldSession* session);
    static uint32 getCorrectInvType(uint32 inventorytype);

    // From Transmogrification
    static uint32 GetFakeEntry(const Item* item);
    static void DeleteFakeEntry(Player* player, Item* item);
    static void SetFakeEntry(Player* player, Item* item, uint32 entry);
    static const char* getSlotName(uint8 slot, WorldSession* session);
    static void UpdateItem(Player* player, Item* item);
    static uint32 GetSpecialPrice(ItemTemplate const* proto);
    static bool CanTransmogrifyItemWithItem(Player* player, ItemTemplate const* target, ItemTemplate const* source);
    static bool SuitableForTransmogrification(Player* player, ItemTemplate const* proto);
    static bool IsRangedWeapon(uint32 Class, uint32 SubClass);
    static bool IsAllowed(uint32 entry);
    static bool IsNotAllowed(uint32 entry);
    static bool IsAllowedQuality(uint32 quality);
};

#endif
