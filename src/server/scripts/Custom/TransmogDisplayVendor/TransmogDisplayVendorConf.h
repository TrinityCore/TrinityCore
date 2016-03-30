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
#include "ItemPrototype.h"
#include "SharedDefines.h"
#include <set>

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

class TransmogDisplayVendorMgr
{
public:
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

    static std::set<uint32> Allowed;
    static std::set<uint32> NotAllowed;

    static void HandleTransmogrify(Player* player, Creature* creature, uint32 vendorslot, uint32 itemEntry, bool no_cost = false);

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
