/*
Transmog display vendor
Code by Rochet2
Ideas LilleCarl

ScriptName for NPC:
NPC_TransmogDisplayVendor

Compatible with Transmogrification 6.1 by Rochet2
http://rochet2.github.io/Transmogrification
*/

#include "TransmogDisplayVendorConf.h"
#include "Bag.h"
#include "Common.h"
#include "Config.h"
#include "Creature.h"
#include "DatabaseEnv.h"
#include "DBCStructure.h"
#include "Define.h"
#include "Field.h"
#include "GameEventMgr.h"
#include "GossipDef.h"
#include "Item.h"
#include "ItemPrototype.h"
#include "Language.h"
#include "Log.h"
#include "Player.h"
#include "ObjectGuid.h"
#include "ObjectMgr.h"
#include "QueryResult.h"
#include "ScriptedGossip.h"
#include "ScriptMgr.h"
#include "SharedDefines.h"
#include "Transaction.h"
#include "WorldSession.h"
#include <sstream>
#include <string>

// Config start

// Edit Transmogrification compatibility in TransmogDisplayVendorConf.h

// A multiplier for the default gold cost (change to 0.0f for no default cost)
const float TransmogDisplayVendorMgr::ScaledCostModifier = 1.0f;
// Cost added on top of other costs (can be negative)
const int32 TransmogDisplayVendorMgr::CopperCost = 0;
// For custom gold cost set ScaledCostModifier to 0.0f and CopperCost to what ever cost you want

const bool TransmogDisplayVendorMgr::RequireToken = false;
const uint32 TransmogDisplayVendorMgr::TokenEntry = 49426;
const uint32 TransmogDisplayVendorMgr::TokenAmount = 1;

const bool TransmogDisplayVendorMgr::AllowPoor = false;
const bool TransmogDisplayVendorMgr::AllowCommon = false;
const bool TransmogDisplayVendorMgr::AllowUncommon = true;
const bool TransmogDisplayVendorMgr::AllowRare = true;
const bool TransmogDisplayVendorMgr::AllowEpic = true;
const bool TransmogDisplayVendorMgr::AllowLegendary = false;
const bool TransmogDisplayVendorMgr::AllowArtifact = false;
const bool TransmogDisplayVendorMgr::AllowHeirloom = true;

const bool TransmogDisplayVendorMgr::AllowMixedArmorTypes = false;
const bool TransmogDisplayVendorMgr::AllowMixedWeaponTypes = false;
const bool TransmogDisplayVendorMgr::AllowFishingPoles = false;

const bool TransmogDisplayVendorMgr::IgnoreReqRace = false;
const bool TransmogDisplayVendorMgr::IgnoreReqClass = false;
const bool TransmogDisplayVendorMgr::IgnoreReqSkill = false;
const bool TransmogDisplayVendorMgr::IgnoreReqSpell = false;
const bool TransmogDisplayVendorMgr::IgnoreReqLevel = false;
const bool TransmogDisplayVendorMgr::IgnoreReqEvent = false;
const bool TransmogDisplayVendorMgr::IgnoreReqStats = false;

// Example AllowedItems[] = { 123, 234, 345 };
static const uint32 AllowedItems[] = { 0 };
static const uint32 NotAllowedItems[] = { 0 };

// Config end

std::set<uint32> TransmogDisplayVendorMgr::Allowed;
std::set<uint32> TransmogDisplayVendorMgr::NotAllowed;

#ifndef UNORDERED_MAP
#define UNORDERED_MAP std::unordered_map
#endif

#ifdef BOOST_VERSION
#define USING_BOOST
#endif
#ifdef USING_BOOST
#include <boost/thread/locks.hpp>
#include <boost/thread/shared_mutex.hpp>
#endif

namespace
{
    class RWLockable
    {
    public:
#ifdef USING_BOOST
        typedef boost::shared_mutex LockType;
        typedef boost::shared_lock<boost::shared_mutex> ReadGuard;
        typedef boost::unique_lock<boost::shared_mutex> WriteGuard;
#else
        typedef ACE_RW_Thread_Mutex LockType;
        typedef ACE_Read_Guard<LockType> ReadGuard;
        typedef ACE_Write_Guard<LockType> WriteGuard;
#endif
        LockType& GetLock() { return _lock; }
    private:
        LockType _lock;
    };

    class SelectionStore : public RWLockable
    {
    public:
        struct Selection { uint32 item; uint8 slot; uint32 offset; uint32 quality; };
        typedef UNORDERED_MAP<uint32, Selection> PlayerLowToSelection;

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
};

// Selection store
static SelectionStore selectionStore; // selectionStore[lowGUID] = Selection

// Vendor data store
// optionMap[Class? + SubClass][invtype][Quality] = EntryVector
typedef std::vector<uint32> EntryVector;
static EntryVector* optionMap[MAX_ITEM_SUBCLASS_WEAPON + MAX_ITEM_SUBCLASS_ARMOR][MAX_INVTYPE][MAX_ITEM_QUALITY];

uint32 TransmogDisplayVendorMgr::GetFakeEntry(const Item* item)
{
    TC_LOG_DEBUG("custom.transmog", "TransmogDisplayVendorMgr::GetFakeEntry");

    Player* owner = item->GetOwner();

    if (!owner)
        return 0;
    if (owner->transmogMap.empty())
        return 0;

    TransmogMapType::const_iterator it = owner->transmogMap.find(item->GetGUID());
    if (it == owner->transmogMap.end())
        return 0;
    return it->second;
}
void TransmogDisplayVendorMgr::DeleteFakeEntry(Player* player, Item* item)
{
    TC_LOG_DEBUG("custom.transmog", "TransmogDisplayVendorMgr::DeleteFakeEntry");

    if (player->transmogMap.erase(item->GetGUID()) != 0)
        UpdateItem(player, item);
}
void TransmogDisplayVendorMgr::SetFakeEntry(Player* player, Item* item, uint32 entry)
{
    TC_LOG_DEBUG("custom.transmog", "TransmogDisplayVendorMgr::SetFakeEntry");

    player->transmogMap[item->GetGUID()] = entry;
    UpdateItem(player, item);
}
void TransmogDisplayVendorMgr::UpdateItem(Player* player, Item* item)
{
    TC_LOG_DEBUG("custom.transmog", "TransmogDisplayVendorMgr::UpdateItem");

    if (item->IsEquipped())
    {
        player->SetVisibleItemSlot(item->GetSlot(), item);
        if (player->IsInWorld())
            item->SendUpdateToPlayer(player);
    }
}
const char* TransmogDisplayVendorMgr::getSlotName(uint8 slot, WorldSession* /*session*/)
{
    TC_LOG_DEBUG("custom.transmog", "TransmogDisplayVendorMgr::TransmogDisplayVendorMgr::getSlotName");

    switch (slot)
    {
        case EQUIPMENT_SLOT_HEAD: return  "Head";// session->GetTrinityString(LANG_SLOT_NAME_HEAD);
        case EQUIPMENT_SLOT_SHOULDERS: return  "Shoulders";// session->GetTrinityString(LANG_SLOT_NAME_SHOULDERS);
        case EQUIPMENT_SLOT_BODY: return  "Shirt";// session->GetTrinityString(LANG_SLOT_NAME_BODY);
        case EQUIPMENT_SLOT_CHEST: return  "Chest";// session->GetTrinityString(LANG_SLOT_NAME_CHEST);
        case EQUIPMENT_SLOT_WAIST: return  "Waist";// session->GetTrinityString(LANG_SLOT_NAME_WAIST);
        case EQUIPMENT_SLOT_LEGS: return  "Legs";// session->GetTrinityString(LANG_SLOT_NAME_LEGS);
        case EQUIPMENT_SLOT_FEET: return  "Feet";// session->GetTrinityString(LANG_SLOT_NAME_FEET);
        case EQUIPMENT_SLOT_WRISTS: return  "Wrists";// session->GetTrinityString(LANG_SLOT_NAME_WRISTS);
        case EQUIPMENT_SLOT_HANDS: return  "Hands";// session->GetTrinityString(LANG_SLOT_NAME_HANDS);
        case EQUIPMENT_SLOT_BACK: return  "Back";// session->GetTrinityString(LANG_SLOT_NAME_BACK);
        case EQUIPMENT_SLOT_MAINHAND: return  "Main hand";// session->GetTrinityString(LANG_SLOT_NAME_MAINHAND);
        case EQUIPMENT_SLOT_OFFHAND: return  "Off hand";// session->GetTrinityString(LANG_SLOT_NAME_OFFHAND);
        case EQUIPMENT_SLOT_RANGED: return  "Ranged";// session->GetTrinityString(LANG_SLOT_NAME_RANGED);
        case EQUIPMENT_SLOT_TABARD: return  "Tabard";// session->GetTrinityString(LANG_SLOT_NAME_TABARD);
        default: return NULL;
    }
}
uint32 TransmogDisplayVendorMgr::GetSpecialPrice(ItemTemplate const* proto)
{
    TC_LOG_DEBUG("custom.transmog", "TransmogDisplayVendorMgr::GetSpecialPrice");

    uint32 cost = proto->SellPrice < 10000 ? 10000 : proto->SellPrice;
    return cost;
}
bool TransmogDisplayVendorMgr::CanTransmogrifyItemWithItem(Player* player, ItemTemplate const* target, ItemTemplate const* source)
{
    TC_LOG_DEBUG("custom.transmog", "TransmogDisplayVendorMgr::CanTransmogrifyItemWithItem");

    if (!target || !source)
        return false;

    if (source->ItemId == target->ItemId)
        return false;

    if (source->DisplayInfoID == target->DisplayInfoID)
        return false;

    if (source->Class != target->Class)
        return false;

    if (source->InventoryType == INVTYPE_BAG ||
        source->InventoryType == INVTYPE_RELIC ||
        // source->InventoryType == INVTYPE_BODY ||
        source->InventoryType == INVTYPE_FINGER ||
        source->InventoryType == INVTYPE_TRINKET ||
        source->InventoryType == INVTYPE_AMMO ||
        source->InventoryType == INVTYPE_QUIVER)
        return false;

    if (target->InventoryType == INVTYPE_BAG ||
        target->InventoryType == INVTYPE_RELIC ||
        // target->InventoryType == INVTYPE_BODY ||
        target->InventoryType == INVTYPE_FINGER ||
        target->InventoryType == INVTYPE_TRINKET ||
        target->InventoryType == INVTYPE_AMMO ||
        target->InventoryType == INVTYPE_QUIVER)
        return false;

    if (!SuitableForTransmogrification(player, target) || !SuitableForTransmogrification(player, source)) // if (!transmogrified->CanTransmogrify() || !transmogrifier->CanBeTransmogrified())
        return false;

    if (IsRangedWeapon(source->Class, source->SubClass) != IsRangedWeapon(target->Class, target->SubClass))
        return false;

    if (source->SubClass != target->SubClass && !IsRangedWeapon(target->Class, target->SubClass))
    {
        if (source->Class == ITEM_CLASS_ARMOR && !AllowMixedArmorTypes)
            return false;
        if (source->Class == ITEM_CLASS_WEAPON && !AllowMixedWeaponTypes)
            return false;
    }

    if (source->InventoryType != target->InventoryType)
    {
        if (source->Class == ITEM_CLASS_WEAPON && !((IsRangedWeapon(target->Class, target->SubClass) ||
            ((target->InventoryType == INVTYPE_WEAPON || target->InventoryType == INVTYPE_2HWEAPON) &&
                (source->InventoryType == INVTYPE_WEAPON || source->InventoryType == INVTYPE_2HWEAPON)) ||
            ((target->InventoryType == INVTYPE_WEAPONMAINHAND || target->InventoryType == INVTYPE_WEAPONOFFHAND) &&
                (source->InventoryType == INVTYPE_WEAPON || source->InventoryType == INVTYPE_2HWEAPON)))))
            return false;
        if (source->Class == ITEM_CLASS_ARMOR &&
            !((source->InventoryType == INVTYPE_CHEST || source->InventoryType == INVTYPE_ROBE) &&
                (target->InventoryType == INVTYPE_CHEST || target->InventoryType == INVTYPE_ROBE)))
            return false;
    }

    return true;
}
bool TransmogDisplayVendorMgr::SuitableForTransmogrification(Player* player, ItemTemplate const* proto)
{
    TC_LOG_DEBUG("custom.transmog", "TransmogDisplayVendorMgr::SuitableForTransmogrification");

    // ItemTemplate const* proto = item->GetTemplate();
    if (!proto)
        return false;

    if (proto->Class != ITEM_CLASS_ARMOR &&
        proto->Class != ITEM_CLASS_WEAPON)
        return false;

    // Skip all checks for allowed items
    if (IsAllowed(proto->ItemId))
        return true;

    if (IsNotAllowed(proto->ItemId))
        return false;

    if (!AllowFishingPoles && proto->Class == ITEM_CLASS_WEAPON && proto->SubClass == ITEM_SUBCLASS_WEAPON_FISHING_POLE)
        return false;

    if (!IsAllowedQuality(proto->Quality)) // (proto->Quality == ITEM_QUALITY_LEGENDARY)
        return false;

    if (player)
    {
        if ((proto->Flags2 & ITEM_FLAGS_EXTRA_HORDE_ONLY) && player->GetTeam() != HORDE)
            return false;

        if ((proto->Flags2 & ITEM_FLAGS_EXTRA_ALLIANCE_ONLY) && player->GetTeam() != ALLIANCE)
            return false;

        if (!IgnoreReqClass && (proto->AllowableClass & player->getClassMask()) == 0)
            return false;

        if (!IgnoreReqRace && (proto->AllowableRace & player->getRaceMask()) == 0)
            return false;

        if (!IgnoreReqSkill && proto->RequiredSkill != 0)
        {
            if (player->GetSkillValue(proto->RequiredSkill) == 0)
                return false;
            else if (player->GetSkillValue(proto->RequiredSkill) < proto->RequiredSkillRank)
                return false;
        }

        if (!IgnoreReqSpell && proto->RequiredSpell != 0 && !player->HasSpell(proto->RequiredSpell))
            return false;

        if (!IgnoreReqLevel && player->getLevel() < proto->RequiredLevel)
            return false;
    }

    // If World Event is not active, prevent using event dependant items
    if (!IgnoreReqEvent && proto->HolidayId && !IsHolidayActive((HolidayIds)proto->HolidayId))
        return false;

    if (!IgnoreReqStats)
    {
        if (!proto->RandomProperty && !proto->RandomSuffix)
        {
            bool found = false;
            for (uint8 i = 0; i < proto->StatsCount; ++i)
            {
                if (proto->ItemStat[i].ItemStatValue != 0)
                {
                    found = true;
                    break;
                }
            }
            if (!found)
                return false;
        }
    }

    return true;
}

bool TransmogDisplayVendorMgr::IsRangedWeapon(uint32 Class, uint32 SubClass)
{
    TC_LOG_DEBUG("custom.transmog", "TransmogDisplayVendorMgr::IsRangedWeapon");

    return Class == ITEM_CLASS_WEAPON && (
        SubClass == ITEM_SUBCLASS_WEAPON_BOW ||
        SubClass == ITEM_SUBCLASS_WEAPON_GUN ||
        SubClass == ITEM_SUBCLASS_WEAPON_CROSSBOW);
}
bool TransmogDisplayVendorMgr::IsAllowed(uint32 entry)
{
    TC_LOG_DEBUG("custom.transmog", "TransmogDisplayVendorMgr::IsAllowed");

    return Allowed.find(entry) != Allowed.end();
}
bool TransmogDisplayVendorMgr::IsNotAllowed(uint32 entry)
{
    TC_LOG_DEBUG("custom.transmog", "TransmogDisplayVendorMgr::IsNotAllowed");

    return NotAllowed.find(entry) != NotAllowed.end();
}
bool TransmogDisplayVendorMgr::IsAllowedQuality(uint32 quality)
{
    TC_LOG_DEBUG("custom.transmog", "TransmogDisplayVendorMgr::IsAllowedQuality");

    switch (quality)
    {
        case ITEM_QUALITY_POOR: return AllowPoor;
        case ITEM_QUALITY_NORMAL: return AllowCommon;
        case ITEM_QUALITY_UNCOMMON: return AllowUncommon;
        case ITEM_QUALITY_RARE: return AllowRare;
        case ITEM_QUALITY_EPIC: return AllowEpic;
        case ITEM_QUALITY_LEGENDARY: return AllowLegendary;
        case ITEM_QUALITY_ARTIFACT: return AllowArtifact;
        case ITEM_QUALITY_HEIRLOOM: return AllowHeirloom;
        default: return false;
    }
}

static const char* getQualityName(uint32 quality)
{
    switch (quality)
    {
        case ITEM_QUALITY_POOR: return "|CFF9d9d9d[Poor]";
        case ITEM_QUALITY_NORMAL: return "|CFFffffff[Common]";
        case ITEM_QUALITY_UNCOMMON: return "|CFF1eff00[Uncommon]";
        case ITEM_QUALITY_RARE: return "|CFF0070dd[Rare]";
        case ITEM_QUALITY_EPIC: return "|CFFa335ee[Epic]";
        case ITEM_QUALITY_LEGENDARY: return "|CFFff8000[Legendary]";
        case ITEM_QUALITY_ARTIFACT: return "|CFFe6cc80[Artifact]";
        case ITEM_QUALITY_HEIRLOOM: return "|CFFe5cc80[Heirloom]";
        default: return "[Unknown]";
    }
}

static std::string getItemName(const ItemTemplate* itemTemplate, WorldSession* session)
{
    std::string name = itemTemplate->Name1;
    int loc_idx = session->GetSessionDbLocaleIndex();
    if (loc_idx >= 0)
        if (ItemLocale const* il = sObjectMgr->GetItemLocale(itemTemplate->ItemId))
            sObjectMgr->GetLocaleString(il->Name, loc_idx, name);
    return name;
}

static uint32 getCorrectInvType(uint32 inventorytype)
{
    switch (inventorytype)
    {
        case INVTYPE_WEAPONMAINHAND:
        case INVTYPE_WEAPONOFFHAND:
            return INVTYPE_WEAPON;
        case INVTYPE_RANGEDRIGHT:
            return INVTYPE_RANGED;
        case INVTYPE_ROBE:
            return INVTYPE_CHEST;
        default:
            return inventorytype;
    }
}

void TransmogDisplayVendorMgr::HandleTransmogrify(Player* player, Creature* /*creature*/, uint32 vendorslot, uint32 itemEntry, bool no_cost)
{
    TC_LOG_DEBUG("custom.transmog", "TransmogDisplayVendorMgr::HandleTransmogrify");

    SelectionStore::Selection selection;
    if (!selectionStore.GetSelection(player->GetGUID().GetCounter(), selection))
        return; // cheat, no slot selected

    const char* slotname = TransmogDisplayVendorMgr::getSlotName(selection.slot, player->GetSession());
    if (!slotname)
        return;
    uint8 slot = selection.slot;

    // slot of the transmogrified item
    if (slot >= EQUIPMENT_SLOT_END)
    {
        TC_LOG_DEBUG("custom.transmog", "TransmogDisplayVendorMgr::HandleTransmogrify - %s (%s) tried to transmogrify item %u with a wrong slot (%u) when transmogrifying items.", player->GetName().c_str(), player->GetGUID().ToString().c_str(), itemEntry, slot);
        return; // LANG_ERR_TRANSMOG_INVALID_SLOT
    }

    const ItemTemplate* itemTransmogrifier = NULL;
    // guid of the transmogrifier item, if it's not 0
    if (itemEntry)
    {
        itemTransmogrifier = sObjectMgr->GetItemTemplate(itemEntry);
        if (!itemTransmogrifier)
        {
            TC_LOG_DEBUG("custom.transmog", "TransmogDisplayVendorMgr::HandleTransmogrify - %s (%s) tried to transmogrify with an invalid item entry %u.", player->GetName().c_str(), player->GetGUID().ToString().c_str(), itemEntry);
            return; // LANG_ERR_TRANSMOG_MISSING_SRC_ITEM
        }
    }

    // transmogrified item
    Item* itemTransmogrified = player->GetItemByPos(INVENTORY_SLOT_BAG_0, slot);
    if (!itemTransmogrified)
    {
        TC_LOG_DEBUG("custom.transmog", "TransmogDisplayVendorMgr::HandleTransmogrify - %s (%s) tried to transmogrify an invalid item in a valid slot (slot: %u).", player->GetName().c_str(), player->GetGUID().ToString().c_str(), slot);
        player->GetSession()->SendNotification("No item in %s slot", slotname);
        return; // LANG_ERR_TRANSMOG_MISSING_DEST_ITEM
    }

    if (!itemTransmogrifier) // reset look newEntry
    {
        DeleteFakeEntry(player, itemTransmogrified);
    }
    else
    {
        if (!CanTransmogrifyItemWithItem(player, itemTransmogrified->GetTemplate(), itemTransmogrifier))
        {
            TC_LOG_DEBUG("custom.transmog", "TransmogDisplayVendorMgr::HandleTransmogrify - %s (%s) failed CanTransmogrifyItemWithItem (%u with %u).", player->GetName().c_str(), player->GetGUID().ToString().c_str(), itemTransmogrified->GetEntry(), itemTransmogrifier->ItemId);
            player->GetSession()->SendNotification("Equipped item is not suitable for selected transmogrification");
            return; // LANG_ERR_TRANSMOG_INVALID_ITEMS
        }

        if (uint32 fakeEntry = GetFakeEntry(itemTransmogrified))
        {
            if (const ItemTemplate* fakeItemTemplate = sObjectMgr->GetItemTemplate(fakeEntry))
            {
                if (fakeItemTemplate->DisplayInfoID == itemTransmogrifier->DisplayInfoID)
                {
                    player->GetSession()->SendNotification("%s already transmogrified with %s", slotname, getItemName(itemTransmogrifier, player->GetSession()).c_str());
                    return;
                }
            }
        }

        // {{entry}, {entry}, ...}
        std::list<uint32> L;
        uint32 counter = 0;
        bool over = false;
        if (itemTransmogrified->GetTemplate()->Class != ITEM_CLASS_WEAPON && TransmogDisplayVendorMgr::AllowMixedArmorTypes)
        {
            for (uint32 i = 0; i < MAX_ITEM_SUBCLASS_ARMOR; ++i)
            {
                const EntryVector* oM = optionMap[MAX_ITEM_SUBCLASS_WEAPON + i][getCorrectInvType(itemTransmogrified->GetTemplate()->InventoryType)][selection.quality];
                if (!oM)
                    continue;
                if (!over && counter + oM->size() < selection.offset)
                {
                    counter += oM->size();
                }
                else
                {
                    over = true;
                    L.insert(L.end(), oM->begin(), oM->end());
                }
            }
        }
        else if (itemTransmogrified->GetTemplate()->Class == ITEM_CLASS_WEAPON && TransmogDisplayVendorMgr::AllowMixedWeaponTypes)
        {
            for (uint32 i = 0; i < MAX_ITEM_SUBCLASS_WEAPON; ++i)
            {
                const EntryVector* oM = optionMap[i][getCorrectInvType(itemTransmogrified->GetTemplate()->InventoryType)][selection.quality];
                if (!oM)
                    continue;
                if (!over && counter + oM->size() < selection.offset)
                {
                    counter += oM->size();
                }
                else
                {
                    over = true;
                    L.insert(L.end(), oM->begin(), oM->end());
                }
            }
        }
        else
        {
            const EntryVector* oM = optionMap[(itemTransmogrified->GetTemplate()->Class != ITEM_CLASS_WEAPON ? MAX_ITEM_SUBCLASS_WEAPON : 0) + itemTransmogrified->GetTemplate()->SubClass][getCorrectInvType(itemTransmogrified->GetTemplate()->InventoryType)][selection.quality];
            if (oM)
            {
                if (!over && counter + oM->size() < selection.offset)
                {
                    counter += oM->size();
                }
                else
                {
                    over = true;
                    L.insert(L.end(), oM->begin(), oM->end());
                }
            }
        }
        std::list<uint32>::const_iterator it = L.begin();
        std::advance(it, (selection.offset - counter) + vendorslot);
        if (it == L.end() || (*it) != itemEntry)
        {
            player->GetSession()->SendNotification("Equipped item is not suitable for selected transmogrification");
            return; // either cheat or changed items (not found in correct place in transmog vendor view)
        }

        if (!no_cost)
        {
            if (RequireToken)
            {
                if (player->HasItemCount(TokenEntry, TokenAmount))
                {
                    player->DestroyItemCount(TokenEntry, TokenAmount, true);
                }
                else
                {
                    player->GetSession()->SendNotification("You do not have enough %ss", getItemName(sObjectMgr->GetItemTemplate(TransmogDisplayVendorMgr::TokenEntry), player->GetSession()).c_str());
                    return; // LANG_ERR_TRANSMOG_NOT_ENOUGH_TOKENS
                }
            }

            int32 cost = 0;
            cost = GetSpecialPrice(itemTransmogrified->GetTemplate());
            cost *= ScaledCostModifier;
            cost += CopperCost;

            if (cost) // 0 cost if reverting look
            {
                if (cost < 0)
                {
                    TC_LOG_DEBUG("custom.transmog", "TransmogDisplayVendorMgr::HandleTransmogrify - %s (%s) transmogrification invalid cost (non negative, amount %i). Transmogrified %u with %u", player->GetName().c_str(), player->GetGUID().ToString().c_str(), -cost, itemTransmogrified->GetEntry(), itemTransmogrifier->ItemId);
                }
                else
                {
                    if (!player->HasEnoughMoney(cost))
                    {
                        player->GetSession()->SendNotification("You do not have enough money");
                        return; // LANG_ERR_TRANSMOG_NOT_ENOUGH_MONEY
                    }
                    player->ModifyMoney(-cost, false);
                }
            }

            SetFakeEntry(player, itemTransmogrified, itemTransmogrifier->ItemId);

            itemTransmogrified->UpdatePlayedTime(player);

            itemTransmogrified->SetOwnerGUID(player->GetGUID());
            itemTransmogrified->SetNotRefundable(player);
            itemTransmogrified->ClearSoulboundTradeable(player);

            //if (itemTransmogrifier->GetTemplate()->Bonding == BIND_WHEN_EQUIPED || itemTransmogrifier->GetTemplate()->Bonding == BIND_WHEN_USE)
            //    itemTransmogrifier->SetBinding(true);

            //itemTransmogrifier->SetOwnerGUID(player->GetGUID());
            //itemTransmogrifier->SetNotRefundable(player);
            //itemTransmogrifier->ClearSoulboundTradeable(player);
        }

        player->PlayDirectSound(3337);
        player->GetSession()->SendAreaTriggerMessage("%s transmogrified", slotname);
        //return LANG_ERR_TRANSMOG_OK;
    }
}

class NPC_TransmogDisplayVendor : public CreatureScript
{
public:
    NPC_TransmogDisplayVendor() : CreatureScript("NPC_TransmogDisplayVendor") { } // If you change this, also change in Player.cpp: if (creature->GetScriptName() == "NPC_TransmogDisplayVendor")

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        player->PlayerTalkClass->ClearMenus();
        selectionStore.RemoveSelection(player->GetGUID().GetCounter());
        WorldSession* session = player->GetSession();
        for (uint8 slot = EQUIPMENT_SLOT_START; slot < EQUIPMENT_SLOT_END; slot++)
        {
            // if (player->GetItemByPos(INVENTORY_SLOT_BAG_0, slot))
            if (const char* slotName = TransmogDisplayVendorMgr::getSlotName(slot, session))
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, slotName, SENDER_SELECT_VENDOR, slot);
        }
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Remove transmogrifications", SENDER_REMOVE_MENU, 0);
        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action) override
    {
        WorldSession* session = player->GetSession();
        player->PlayerTalkClass->ClearMenus();
        switch (sender)
        {
            case SENDER_SELECT_VENDOR: // action = slot
            {
                Item* item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, action);
                if (!item)
                {
                    if (const char* slotname = TransmogDisplayVendorMgr::getSlotName(action, player->GetSession()))
                        session->SendNotification("No item equipped in %s slot", slotname);
                    OnGossipHello(player, creature);
                    return true;
                }
                const ItemTemplate * itemTemplate = item->GetTemplate();
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, (std::string)"Update selected; " + getItemName(itemTemplate, session), sender, action);

                // [quality] = {size}
                std::map<uint32, uint32> L;
                if (itemTemplate->Class != ITEM_CLASS_WEAPON && TransmogDisplayVendorMgr::AllowMixedArmorTypes)
                {
                    for (uint32 i = 0; i < MAX_ITEM_SUBCLASS_ARMOR; ++i)
                    {
                        EntryVector** oM = optionMap[MAX_ITEM_SUBCLASS_WEAPON + i][getCorrectInvType(itemTemplate->InventoryType)];
                        for (uint32 i = 0; i < MAX_ITEM_QUALITY; ++i, ++oM)
                            if (TransmogDisplayVendorMgr::IsAllowedQuality(i)) // skip not allowed qualities
                                if (*oM)
                                    L[i] += (*oM)->size();
                    }
                }
                else if (itemTemplate->Class == ITEM_CLASS_WEAPON && TransmogDisplayVendorMgr::AllowMixedWeaponTypes)
                {
                    for (uint32 i = 0; i < MAX_ITEM_SUBCLASS_WEAPON; ++i)
                    {
                        EntryVector** oM = optionMap[i][getCorrectInvType(itemTemplate->InventoryType)];
                        for (uint32 i = 0; i < MAX_ITEM_QUALITY; ++i, ++oM)
                            if (TransmogDisplayVendorMgr::IsAllowedQuality(i)) // skip not allowed qualities
                                if (*oM)
                                    L[i] += (*oM)->size();
                    }
                }
                else
                {
                    EntryVector** oM = optionMap[(itemTemplate->Class != ITEM_CLASS_WEAPON ? MAX_ITEM_SUBCLASS_WEAPON : 0) + itemTemplate->SubClass][getCorrectInvType(itemTemplate->InventoryType)];
                    for (uint32 i = 0; i < MAX_ITEM_QUALITY; ++i, ++oM)
                        if (TransmogDisplayVendorMgr::IsAllowedQuality(i)) // skip not allowed qualities
                            if (*oM)
                                L[i] += (*oM)->size();
                }

                for (std::map<uint32, uint32>::const_iterator it = L.begin(); it != L.end(); ++it)
                {
                    for (uint32 count = 0; count*MAX_VENDOR_ITEMS < it->second; ++count)
                    {
                        std::ostringstream ss;
                        ss << getQualityName(it->first);
                        if (count)
                            ss << " [" << count << "]";
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, ss.str().c_str(), it->first, count*MAX_VENDOR_ITEMS);
                    }
                }

                if (player->PlayerTalkClass->GetGossipMenu().GetMenuItemCount() <= 1)
                {
                    if (const char* slotname = TransmogDisplayVendorMgr::getSlotName(action, player->GetSession()))
                        session->SendNotification("No transmogrifications available for %s", slotname);
                    OnGossipHello(player, creature);
                    return true;
                }

                SelectionStore::Selection temp = { item->GetEntry(), action, 0, 0 }; // entry, slot, offset, quality
                selectionStore.SetSelection(player->GetGUID().GetCounter(), temp);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Back..", SENDER_BACK, 0);
                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
            } break;
            case SENDER_BACK: // Back
            {
                OnGossipHello(player, creature);
            } break;
            case SENDER_REMOVE_ALL: // Remove TransmogDisplayVendorMgrs
            {
                bool removed = false;
                for (uint8 Slot = EQUIPMENT_SLOT_START; Slot < EQUIPMENT_SLOT_END; Slot++)
                {
                    if (Item* newItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, Slot))
                    {
                        if (!TransmogDisplayVendorMgr::GetFakeEntry(newItem))
                            continue;
                        TransmogDisplayVendorMgr::DeleteFakeEntry(player, newItem);
                        removed = true;
                    }
                }
                if (removed)
                {
                    session->SendAreaTriggerMessage("Transmogrifications removed from equipped items");
                    player->PlayDirectSound(3337);
                }
                else
                {
                    session->SendNotification("You have no transmogrified items equipped");
                }
                OnGossipSelect(player, creature, SENDER_REMOVE_MENU, 0);
            } break;
            case SENDER_REMOVE_ONE: // Remove TransmogDisplayVendorMgr from single item
            {
                const char* slotname = TransmogDisplayVendorMgr::getSlotName(action, player->GetSession());
                if (Item* newItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, action))
                {
                    if (TransmogDisplayVendorMgr::GetFakeEntry(newItem))
                    {
                        TransmogDisplayVendorMgr::DeleteFakeEntry(player, newItem);
                        if (slotname)
                            session->SendAreaTriggerMessage("%s transmogrification removed", slotname);
                        player->PlayDirectSound(3337);
                    }
                    else if (slotname)
                    {
                        session->SendNotification("No transmogrification on %s slot", slotname);
                    }
                }
                else if (slotname)
                {
                    session->SendNotification("No item equipped in %s slot", slotname);
                }
                OnGossipSelect(player, creature, SENDER_REMOVE_MENU, 0);
            } break;
            case SENDER_REMOVE_MENU:
            {
                for (uint8 slot = EQUIPMENT_SLOT_START; slot < EQUIPMENT_SLOT_END; slot++)
                {
                    const char* slotname = TransmogDisplayVendorMgr::getSlotName(slot, player->GetSession());
                    if (!slotname)
                        continue;
                    std::ostringstream ss;
                    ss << "Remove transmogrification from " << slotname << "?";
                    player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_INTERACT_1, (std::string)"Remove from " + slotname, SENDER_REMOVE_ONE, slot, ss.str().c_str(), 0, false);
                }
                player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_INTERACT_1, "Remove all transmogrifications", SENDER_REMOVE_ALL, 0, "Are you sure you want to remove all transmogrifications?", 0, false);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Back..", SENDER_BACK, 0);
                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
            } break;
            default: // Show items you can use
            {
                if (sender >= MAX_ITEM_QUALITY) // sender = quality, action = iterator
                    return false; // cheat

                SelectionStore::Selection selection;
                if (!selectionStore.GetSelection(player->GetGUID().GetCounter(), selection))
                    return false; // cheat
                if (selection.offset != 0 || selection.quality != 0)
                    return false; // cheat (something is off)

                selection.offset = action;
                selection.quality = sender;
                uint32 slot = selection.slot; // slot
                selectionStore.SetSelection(player->GetGUID().GetCounter(), selection);

                if (const ItemTemplate* itemTemplate = sObjectMgr->GetItemTemplate(selection.item))
                {
                    if (!TransmogDisplayVendorMgr::SuitableForTransmogrification(player, itemTemplate))
                    {
                        player->GetSession()->SendNotification("Equipped item is not suitable for transmogrification");
                        OnGossipSelect(player, creature, SENDER_SELECT_VENDOR, slot);
                        return true;
                    }

                    // {{entry}, {entry}, ...}
                    std::list<uint32> L;
                    uint32 counter = 0;
                    bool over = false;
                    if (itemTemplate->Class != ITEM_CLASS_WEAPON && TransmogDisplayVendorMgr::AllowMixedArmorTypes)
                    {
                        for (uint32 i = 0; i < MAX_ITEM_SUBCLASS_ARMOR; ++i)
                        {
                            const EntryVector* oM = optionMap[MAX_ITEM_SUBCLASS_WEAPON + i][getCorrectInvType(itemTemplate->InventoryType)][selection.quality];
                            if (!oM)
                                continue;
                            if (!over && counter + oM->size() < selection.offset)
                            {
                                counter += oM->size();
                            }
                            else
                            {
                                over = true;
                                L.insert(L.end(), oM->begin(), oM->end());
                            }
                        }
                    }
                    else if (itemTemplate->Class == ITEM_CLASS_WEAPON && TransmogDisplayVendorMgr::AllowMixedWeaponTypes)
                    {
                        for (uint32 i = 0; i < MAX_ITEM_SUBCLASS_WEAPON; ++i)
                        {
                            const EntryVector* oM = optionMap[i][getCorrectInvType(itemTemplate->InventoryType)][selection.quality];
                            if (!oM)
                                continue;
                            if (!over && counter + oM->size() < selection.offset)
                                counter += oM->size();
                            else
                            {
                                over = true;
                                L.insert(L.end(), oM->begin(), oM->end());
                            }
                        }
                    }
                    else
                    {
                        const EntryVector* oM = optionMap[(itemTemplate->Class != ITEM_CLASS_WEAPON ? MAX_ITEM_SUBCLASS_WEAPON : 0) + itemTemplate->SubClass][getCorrectInvType(itemTemplate->InventoryType)][selection.quality];
                        if (oM)
                        {
                            if (!over && counter + oM->size() < selection.offset)
                            {
                                counter += oM->size();
                            }
                            else
                            {
                                over = true;
                                L.insert(L.end(), oM->begin(), oM->end());
                            }
                        }
                    }

                    // EntryVector oM = optionMap[(itemTemplate->Class != ITEM_CLASS_WEAPON ? MAX_ITEM_SUBCLASS_WEAPON : 0) + itemTemplate->SubClass][getCorrectInvType(itemTemplate->InventoryType)][selection.quality];
                    uint32 itemCount = L.size() - (selection.offset - counter);
                    if (itemCount > MAX_VENDOR_ITEMS)
                        itemCount = MAX_VENDOR_ITEMS;

                    if (!itemCount)
                    {
                        session->SendAreaTriggerMessage("No items found");
                        OnGossipSelect(player, creature, SENDER_SELECT_VENDOR, slot);
                        return true;
                    }
                    player->CLOSE_GOSSIP_MENU();

                    TC_LOG_DEBUG("network", "WORLD: Sent SMSG_LIST_INVENTORY");

                    Creature* vendor = player->GetNPCIfCanInteractWith(creature->GetGUID(), UNIT_NPC_FLAG_VENDOR);
                    if (!vendor)
                    {
                        TC_LOG_DEBUG("network", "WORLD: SendListInventory - Unit (GUID: %u) not found or you can not interact with him.", creature->GetGUID().GetCounter());
                        player->SendSellError(SELL_ERR_CANT_FIND_VENDOR, NULL, ObjectGuid::Empty, 0);
                        return true;
                    }

                    if (player->HasUnitState(UNIT_STATE_DIED))
                        player->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

                    if (vendor->HasUnitState(UNIT_STATE_MOVING))
                        vendor->StopMoving();

                    uint8 count = 0;

                    WorldPacket data(SMSG_LIST_INVENTORY, 8 + 1 + itemCount * 8 * 4);
                    data << uint64(creature->GetGUID());

                    size_t countPos = data.wpos();
                    data << uint8(count);

                    uint32 item_amount = 0;
                    std::list<uint32>::const_iterator it = L.begin();
                    std::advance(it, (selection.offset - counter));
                    for (; it != L.end() && count < itemCount; ++it, ++count)
                    {
                        if (ItemTemplate const* curtemp = sObjectMgr->GetItemTemplate(*it))
                        {
                            if (!TransmogDisplayVendorMgr::CanTransmogrifyItemWithItem(player, itemTemplate, curtemp))
                                continue;

                            data << uint32(count + 1);
                            data << uint32(curtemp->ItemId);
                            data << uint32(curtemp->DisplayInfoID);
                            data << int32(0xFFFFFFFF);
                            data << uint32(0);
                            data << uint32(curtemp->MaxDurability);
                            data << uint32(curtemp->BuyCount);
                            data << uint32(0);
                            ++item_amount;
                        }
                    }

                    if (!item_amount)
                    {
                        session->SendAreaTriggerMessage("No transmogrifications found for equipped item");
                        OnGossipSelect(player, creature, SENDER_SELECT_VENDOR, slot);
                        return true;
                    }
                    else
                    {
                        data.put<uint8>(countPos, item_amount);
                        session->SendPacket(&data);
                    }
                }
                else
                {
                    session->SendNotification("Invalid item equipped");
                    OnGossipSelect(player, creature, SENDER_SELECT_VENDOR, slot);
                    return true;
                }
            } break;
        }
        return true;
    }
};

#if !TRANSMOGRIFICATION_ALREADY_INSTALLED
class Player_Transmogrify : public PlayerScript
{
public:
    Player_Transmogrify() : PlayerScript("Player_Transmogrify") { }

    std::vector<ObjectGuid> GetItemList(const Player* player) const
    {
        std::vector<ObjectGuid> itemlist;

        // Copy paste from Player::GetItemByGuid(guid)

        for (uint8 i = EQUIPMENT_SLOT_START; i < INVENTORY_SLOT_ITEM_END; ++i)
            if (Item* pItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
                itemlist.push_back(pItem->GetGUID());

        for (uint8 i = KEYRING_SLOT_START; i < CURRENCYTOKEN_SLOT_END; ++i)
            if (Item* pItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
                itemlist.push_back(pItem->GetGUID());

        for (int i = BANK_SLOT_ITEM_START; i < BANK_SLOT_BAG_END; ++i)
            if (Item* pItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
                itemlist.push_back(pItem->GetGUID());

        for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
            if (Bag* pBag = player->GetBagByPos(i))
                for (uint32 j = 0; j < pBag->GetBagSize(); ++j)
                    if (Item* pItem = pBag->GetItemByPos(j))
                        itemlist.push_back(pItem->GetGUID());

        for (uint8 i = BANK_SLOT_BAG_START; i < BANK_SLOT_BAG_END; ++i)
            if (Bag* pBag = player->GetBagByPos(i))
                for (uint32 j = 0; j < pBag->GetBagSize(); ++j)
                    if (Item* pItem = pBag->GetItemByPos(j))
                        itemlist.push_back(pItem->GetGUID());

        return itemlist;
    }

    void OnSave(Player* player) override
    {
        uint32 lowguid = player->GetGUID().GetCounter();
        SQLTransaction trans = CharacterDatabase.BeginTransaction();
        trans->PAppend("DELETE FROM `custom_transmogrification` WHERE `Owner` = %u", lowguid);

        if (!player->transmogMap.empty())
        {
            // Only save items that are in inventory / bank / etc
            std::vector<ObjectGuid> items = GetItemList(player);
            for (std::vector<ObjectGuid>::const_iterator it = items.begin(); it != items.end(); ++it)
            {
                TransmogMapType::const_iterator it2 = player->transmogMap.find(*it);
                if (it2 == player->transmogMap.end())
                    continue;

                trans->PAppend("REPLACE INTO custom_transmogrification (GUID, FakeEntry, Owner) VALUES (%u, %u, %u)", it2->first.GetCounter(), it2->second, lowguid);
            }
        }

        if (trans->GetSize()) // basically never false
            CharacterDatabase.CommitTransaction(trans);
    }

    void OnLogin(Player* player, bool /*firstLogin*/) override
    {
        QueryResult result = CharacterDatabase.PQuery("SELECT GUID, FakeEntry FROM custom_transmogrification WHERE Owner = %u", player->GetGUID().GetCounter());

        if (result)
        {
            do
            {
                Field* field = result->Fetch();
                ObjectGuid itemGUID(HighGuid::Item, 0, field[0].GetUInt32());
                uint32 fakeEntry = field[1].GetUInt32();
                // Only load items that are in inventory / bank / etc
                if (sObjectMgr->GetItemTemplate(fakeEntry) && player->GetItemByGuid(itemGUID))
                {
                    player->transmogMap[itemGUID] = fakeEntry;
                }
                else
                {
                    // Ignore, will be erased on next save.
                    // Additionally this can happen if an item was deleted from DB but still exists for the player
                    // TC_LOG_ERROR("custom.transmog", "Item entry (Entry: %u, itemGUID: %u, playerGUID: %u) does not exist, ignoring.", fakeEntry, GUID_LOPART(itemGUID), player->GetGUID().GetCounter());
                    // CharacterDatabase.PExecute("DELETE FROM custom_transmogrification WHERE FakeEntry = %u", fakeEntry);
                }
            } while (result->NextRow());

            if (!player->transmogMap.empty())
            {
                for (uint8 slot = EQUIPMENT_SLOT_START; slot < EQUIPMENT_SLOT_END; ++slot)
                {
                    if (Item* item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, slot))
                    {
                        player->SetVisibleItemSlot(slot, item);
                        if (player->IsInWorld())
                            item->SendUpdateToPlayer(player);
                    }
                }
            }
        }
    }

    void OnLogout(Player* player) override
    {
        selectionStore.RemoveSelection(player->GetGUID().GetCounter());
    }
};
#endif

class PREP_TransmogDisplayVendor : public WorldScript
{
public:
    PREP_TransmogDisplayVendor() : WorldScript("PREP_TransmogDisplayVendor") { }

    void OnStartup() override
    {
        for (size_t i = 0; i < sizeof(AllowedItems) / sizeof(*AllowedItems); ++i)
            TransmogDisplayVendorMgr::Allowed.insert(AllowedItems[i]);
        for (size_t i = 0; i < sizeof(NotAllowedItems) / sizeof(*NotAllowedItems); ++i)
            TransmogDisplayVendorMgr::NotAllowed.insert(NotAllowedItems[i]);

        TC_LOG_INFO("server.loading", "Creating a list of usable transmogrification entries...");
        // initialize .. for reload in future?
        for (uint32 i = 0; i < MAX_ITEM_SUBCLASS_WEAPON + MAX_ITEM_SUBCLASS_ARMOR; ++i)
            for (uint32 j = 0; j < MAX_INVTYPE; ++j)
                for (uint32 k = 0; k < MAX_ITEM_QUALITY; ++k)
                    delete optionMap[i][j][k], optionMap[i][j][k] = NULL;

        std::unordered_set<uint32> displays;
        ItemTemplateContainer const* its = sObjectMgr->GetItemTemplateStore();
        for (ItemTemplateContainer::const_iterator itr = its->begin(); itr != its->end(); ++itr)
        {
            if (itr->second.Class != ITEM_CLASS_WEAPON && itr->second.Class != ITEM_CLASS_ARMOR)
                continue;
            if (!TransmogDisplayVendorMgr::SuitableForTransmogrification(NULL, &itr->second))
                continue;
            if (displays.find(itr->second.DisplayInfoID) != displays.end()) // skip duplicate item displays
                continue;
            EntryVector* oM = optionMap[(itr->second.Class != ITEM_CLASS_WEAPON ? MAX_ITEM_SUBCLASS_WEAPON : 0) + itr->second.SubClass][getCorrectInvType(itr->second.InventoryType)][itr->second.Quality];
            if (!oM)
            {
                oM = new EntryVector();
                optionMap[(itr->second.Class != ITEM_CLASS_WEAPON ? MAX_ITEM_SUBCLASS_WEAPON : 0) + itr->second.SubClass][getCorrectInvType(itr->second.InventoryType)][itr->second.Quality] = oM;
            }
            if (oM->size() < MAX_VENDOR_ITEMS * 3)
            {
                oM->push_back(itr->second.ItemId);
                displays.insert(itr->second.DisplayInfoID);
            }
            else
            {
                TC_LOG_INFO("server.loading", "Too many items for transmogrification: Class: %u SubClass: %u InventoryType: %u Quality: %u", itr->second.Class, itr->second.SubClass, getCorrectInvType(itr->second.InventoryType), itr->second.Quality);
            }
        }

        // resize entry lists
        for (uint32 i = 0; i < MAX_ITEM_SUBCLASS_WEAPON + MAX_ITEM_SUBCLASS_ARMOR; ++i)
            for (uint32 j = 0; j < MAX_INVTYPE; ++j)
                for (uint32 k = 0; k < MAX_ITEM_QUALITY; ++k)
                    if (optionMap[i][j][k])
                        optionMap[i][j][k]->resize(optionMap[i][j][k]->size());

#if !TRANSMOGRIFICATION_ALREADY_INSTALLED
        TC_LOG_INFO("custom.transmog", "Deleting non-existing transmogrification entries...");
        CharacterDatabase.DirectExecute("DELETE FROM custom_transmogrification WHERE NOT EXISTS (SELECT 1 FROM item_instance WHERE item_instance.guid = custom_transmogrification.GUID)");
#endif
    }

    void OnShutdown() override
    {
        for (uint32 i = 0; i < MAX_ITEM_SUBCLASS_WEAPON + MAX_ITEM_SUBCLASS_ARMOR; ++i)
            for (uint32 j = 0; j < MAX_INVTYPE; ++j)
                for (uint32 k = 0; k < MAX_ITEM_QUALITY; ++k)
                    delete optionMap[i][j][k], optionMap[i][j][k] = NULL;
    }
};

void AddSC_NPC_TransmogDisplayVendor()
{
    new NPC_TransmogDisplayVendor();
    new PREP_TransmogDisplayVendor();

#if !TRANSMOGRIFICATION_ALREADY_INSTALLED
    new Player_Transmogrify();
#endif
}
