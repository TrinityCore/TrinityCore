#ifndef DEF_TRANSMOGRIFICATION_DEFINES_H
#define DEF_TRANSMOGRIFICATION_DEFINES_H

#include "Define.h"
#include <limits>

enum AppearanceType : uint32
{
    TRANSMOG_TYPE_ITEM,
    TRANSMOG_TYPE_ENCHANT,
    TRANSMOG_TYPE_COUNT,
};

enum TransmogResult
{
    TransmogResult_Ok = 0, // expected to be 0 while others are expected not to be 0
    TransmogResult_InvalidItemType,
    TransmogResult_ItemBlocked,
    TransmogResult_FishingPoleBlocked,
    TransmogResult_InvalidItemQuality,
    TransmogResult_RequiredEventNotActive,
    TransmogResult_ItemMustHaveStats,
    TransmogResult_InvalidFaction,
    TransmogResult_InvalidClass,
    TransmogResult_InvalidRace,
    TransmogResult_MissingProfiency,
    TransmogResult_MissingSkill,
    TransmogResult_TooLowSkill,
    TransmogResult_MissingSpell,
    TransmogResult_TooLowLevelPlayer,
    TransmogResult_TooLowLevelItem,
    TransmogResult_TooHighLevelItem,
    TransmogResult_ItemTypesDontMatch,
    TransmogResult_ArmorTypesDontMatch,
    TransmogResult_WeaponTypesDontMatch,
    TransmogResult_EquipSlotsDontMatch,
    TransmogResult_InvalidSlot,
    TransmogResult_NonexistantTransmog,
    TransmogResult_EmptySlot,
    TransmogResult_NoPendingTarnsmogs,
    TransmogResult_CostChangedDuringTransaction,
    TransmogResult_NotEnoughMoney,
    TransmogResult_TooLongSetName,
    TransmogResult_NoTransmogrifications,
    TransmogResult_AtMaxSets,
    TransmogResult_NonexistantSet,
    TransmogResult_ItemNotFitForEnchantRequirements,
};

inline const char* CanTransmogrifyResultMessage(TransmogResult result)
{
    switch (result)
    {
        case TransmogResult_Ok: return "Item transmogrified";
        case TransmogResult_InvalidItemType: return "This type of item cannot be transmogrified";
        case TransmogResult_ItemBlocked: return "This item cannot be transmogrified";
        case TransmogResult_FishingPoleBlocked: return "Fishing poles cannot be transmogrified";
        case TransmogResult_InvalidItemQuality: return "This item quality cannot be transmogrified";
        case TransmogResult_RequiredEventNotActive: return "Required event to use this item is not active";
        case TransmogResult_ItemMustHaveStats: return "Transmogrifiable item must have stat effects";
        case TransmogResult_InvalidFaction: return "Your faction cannot use that item";
        case TransmogResult_InvalidClass: return "Your class cannot use that item";
        case TransmogResult_InvalidRace: return "Your race cannot use that item";
        case TransmogResult_MissingProfiency: return "You do not have the profiency to use that item";
        case TransmogResult_MissingSkill: return "You do not have the required skill to use that item";
        case TransmogResult_TooLowSkill: return "You do not have the required skill level to use that item";
        case TransmogResult_MissingSpell: return "You do not have the required spell to use that item";
        case TransmogResult_TooLowLevelPlayer: return "Your level is too low to use that item";
        case TransmogResult_TooLowLevelItem: return "The item is too low level";
        case TransmogResult_TooHighLevelItem: return "The item is too high level";
        case TransmogResult_ItemTypesDontMatch: return "The item types do not match";
        case TransmogResult_ArmorTypesDontMatch: return "The armor types do not match";
        case TransmogResult_WeaponTypesDontMatch: return "The weapon types do not match";
        case TransmogResult_EquipSlotsDontMatch: return "The item equip slots do not allow transmogrifying";
        case TransmogResult_InvalidSlot: return "Items equipped in this slot cannot be transmogrified";
        case TransmogResult_NonexistantTransmog: return "The selected transmogrification does not exist";
        case TransmogResult_EmptySlot: return "You do not have an item equipped in that slot";
        case TransmogResult_NoPendingTarnsmogs: return "You have no pending transmogrifications";
        case TransmogResult_CostChangedDuringTransaction: return "Cost changed during transaction";
        case TransmogResult_NotEnoughMoney: return "Not enough money";
        case TransmogResult_TooLongSetName: return "The set name is too long or too short";
        case TransmogResult_NoTransmogrifications: return "You have no items equipped with pending or non-pending transmogrifications";
        case TransmogResult_AtMaxSets: return "You cannot save more sets";
        case TransmogResult_NonexistantSet: return "The set does not exist";
        case TransmogResult_ItemNotFitForEnchantRequirements: return "The item is not fit for the enchant";
    }
    return nullptr;
};
const char* const TransmogResult_Ok_PendingMessage = "Pending transmog added";
const char* const AddToCollectionMessageFmt = "%s has been added to your appearance collection.";
const uint32 InvisibleEntry = std::numeric_limits<uint32>::max();
const uint32 NormalEntry = InvisibleEntry - 1;
const uint32 RemovePending = NormalEntry - 1;
const uint32 AbsoluteMaxSets = 25;

class Item;
typedef std::vector<std::tuple<Item* /*item*/, uint32 /*transmog*/, AppearanceType /*transmog type*/>> PendingTransmogs;
typedef std::vector<std::tuple<uint8 /*slot*/, uint32 /*transmog*/, AppearanceType /*transmog type*/>> SetTransmogs;

#endif
