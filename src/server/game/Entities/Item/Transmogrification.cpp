#include "Transmogrification.h"
#include "Bag.h"
#include "Chat.h"
#include "Common.h"
#include "Config.h"
#include "DatabaseEnv.h"
#include "DBCStores.h"
#include "DBCStructure.h"
#include "Define.h"
#include "Field.h"
#include "GameEventMgr.h"
#include "Item.h"
#include "ItemTemplate.h"
#include "Language.h"
#include "Log.h"
#include "ObjectGuid.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "QueryResult.h"
#include "ScriptMgr.h"
#include "SharedDefines.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "Transaction.h"
#include "WorldSession.h"
#include "World.h"
#include <sstream>
#include <string>

/*
SELECT ItemVisual, GROUP_CONCAT(DBCNAME), GROUP_CONCAT(Name_Lang_enUS), GROUP_CONCAT(effect) FROM
(
SELECT a.ID, b.Effect_1 AS effect, a.ItemVisual, a.Name_Lang_enUS AS DBCNAME, b.Name_Lang_enUS FROM db_spellitemenchantment_12340 a LEFT JOIN db_spell_12340 b ON a.ID = b.EffectMiscValue_1 WHERE a.ItemVisual > 0
UNION
SELECT a.ID, b.Effect_2 AS effect, a.ItemVisual, a.Name_Lang_enUS AS DBCNAME, b.Name_Lang_enUS FROM db_spellitemenchantment_12340 a LEFT JOIN db_spell_12340 b ON a.ID = b.EffectMiscValue_2 WHERE a.ItemVisual > 0
UNION
SELECT a.ID, b.Effect_3 AS effect, a.ItemVisual, a.Name_Lang_enUS AS DBCNAME, b.Name_Lang_enUS FROM db_spellitemenchantment_12340 a LEFT JOIN db_spell_12340 b ON a.ID = b.EffectMiscValue_3 WHERE a.ItemVisual > 0
ORDER BY ID ASC
) x
WHERE effect IN (53, 54, 92) OR effect IS NULL GROUP BY ItemVisual ORDER BY ItemVisual ASC;
*/
const std::unordered_map<uint32, std::string> Transmogrification::enchant_visual_to_name = {
    {1  , "Frozen Rune Weapon, Razorice, Shadow Oil"},
    {2  , "Impact, Striking"},
    {24 , "Superior Impact"},
    {25 , "Fiery, Demonslaying, Icebreaker, Giant Slayer, Lichbane"},
    {26 , "Poison"},
    {27 , "Frost Oil"},
    {28 , "Sharpened"},
    {29 , "Spirit, Intellect"},
    {31 , "Beastslayer, Elemental Slayer, Scourgebane, Righteous Weapon Coating"},
    {32 , "Flametongue"},
    {33 , "Frostbrand"},
    {42 , "Striking, Impact, Blessed Weapon Coating"},
    {61 , "Rockbiter"},
    {81 , "Windfury"},
    {101, "Savagery"},
    {102, "Healing"},
    {103, "Crusader, Lifeward"},
    {104, "Holy Glow"}, // Made up name. Not from spells. +150 Attack Power vs Undead and Demons
    {105, "Arcane Glow"}, // Made up name. MHTest02
    {106, "Potency, Earthliving"},
    {107, "Feedback, Spellpower"},
    {125, "Agility"},
    {126, "Icy Chill"},
    {128, "Arcane Surge"}, // Made up name. Not from spells. +69 Spell Power
    {139, "Dancing Rune Weapon"}, // Black Temple Dummy
    {151, "Radiance"}, // Made up name. +43 Spell Power,+43 Spell Power,QAEnchant Weapon +81 Healing
    {155, "Mongoose"},
    {156, "Savagery, Rune of Swordshattering, Rune of Swordbreaking"},
    {157, "Soulfrost"},
    {158, "Sunfire"},
    {159, "Battlemaster, Titanium Weapon Chain"},
    {160, "Spellsurge, Rune of the Fallen Crusader"},
    {161, "Unholy Weapon, Black Magic, Rune of Spellshattering, Rune of Spellbreaking"},
    {164, "Blood Draining"},
    {165, "Executioner"},
    {166, "Deathfrost, Rune of Cinderglacier"},
    {172, "Lichflame"}, // Made up name. Not from spells. +81 Spell Power
    {173, "Empower Rune Weapon"}, // Not from spells. Empower Rune Weapon
    {178, "Berserking"}, // Not from spells. Berserking,+110 Attack Power
    {186, "Blade Ward"},
};

Transmogrification & Transmogrification::instance()
{
    static Transmogrification inst;
    return inst;
}

const char* Transmogrification::GetSlotName(uint8 slot, WorldSession* /*session*/)
{
    TC_LOG_DEBUG("custom.transmog", "Transmogrification::GetSlotName");

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

std::string Transmogrification::GetItemIcon(uint32 entry, uint32 width, uint32 height, int x, int y)
{
    TC_LOG_DEBUG("custom.transmog", "Transmogrification::GetItemIcon");

    std::ostringstream ss;
    ss << "|TInterface";
    const ItemTemplate* temp = sObjectMgr->GetItemTemplate(entry);
    const ItemDisplayInfoEntry* dispInfo = NULL;
    if (temp)
    {
        dispInfo = sItemDisplayInfoStore.LookupEntry(temp->DisplayInfoID);
        if (dispInfo)
            ss << "/ICONS/" << dispInfo->InventoryIcon[0]; // what is in InventoryIcon[1]?
    }
    if (!dispInfo)
        ss << "/InventoryItems/WoWUnknownItem01";
    ss << ":" << width << ":" << height << ":" << x << ":" << y << "|t";
    return ss.str();
}

std::string Transmogrification::GetSlotIcon(uint8 slot, uint32 width, uint32 height, int x, int y)
{
    TC_LOG_DEBUG("custom.transmog", "Transmogrification::GetSlotIcon");

    std::ostringstream ss;
    ss << "|TInterface/PaperDoll/";
    switch (slot)
    {
        case EQUIPMENT_SLOT_HEAD: ss << "UI-PaperDoll-Slot-Head"; break;
        case EQUIPMENT_SLOT_SHOULDERS: ss << "UI-PaperDoll-Slot-Shoulder"; break;
        case EQUIPMENT_SLOT_BODY: ss << "UI-PaperDoll-Slot-Shirt"; break;
        case EQUIPMENT_SLOT_CHEST: ss << "UI-PaperDoll-Slot-Chest"; break;
        case EQUIPMENT_SLOT_WAIST: ss << "UI-PaperDoll-Slot-Waist"; break;
        case EQUIPMENT_SLOT_LEGS: ss << "UI-PaperDoll-Slot-Legs"; break;
        case EQUIPMENT_SLOT_FEET: ss << "UI-PaperDoll-Slot-Feet"; break;
        case EQUIPMENT_SLOT_WRISTS: ss << "UI-PaperDoll-Slot-Wrists"; break;
        case EQUIPMENT_SLOT_HANDS: ss << "UI-PaperDoll-Slot-Hands"; break;
        case EQUIPMENT_SLOT_BACK: ss << "UI-PaperDoll-Slot-Chest"; break;
        case EQUIPMENT_SLOT_MAINHAND: ss << "UI-PaperDoll-Slot-MainHand"; break;
        case EQUIPMENT_SLOT_OFFHAND: ss << "UI-PaperDoll-Slot-SecondaryHand"; break;
        case EQUIPMENT_SLOT_RANGED: ss << "UI-PaperDoll-Slot-Ranged"; break;
        case EQUIPMENT_SLOT_TABARD: ss << "UI-PaperDoll-Slot-Tabard"; break;
        default: ss << "UI-Backpack-EmptySlot";
    }
    ss << ":" << width << ":" << height << ":" << x << ":" << y << "|t";
    return ss.str();
}

std::string Transmogrification::GetItemName(ItemTemplate const* itemTemplate, WorldSession* session)
{
    if (!itemTemplate)
        return std::string();
    LocaleConstant loc_idx = session->GetSessionDbLocaleIndex();
    std::string name = itemTemplate->Name1;
    if (ItemLocale const* il = sObjectMgr->GetItemLocale(itemTemplate->ItemId))
        ObjectMgr::GetLocaleString(il->Name, loc_idx, name);
    return name;
}

std::string Transmogrification::GetItemName(Item const* item, WorldSession* session)
{
    if (!item)
        return std::string();
    LocaleConstant localeConstant = session->GetSessionDbLocaleIndex();
    int loc_idx = session->GetSessionDbcLocale();
    const ItemTemplate* temp = item->GetTemplate();
    std::string name = temp->Name1;
    if (localeConstant != LOCALE_enUS)
        if (ItemLocale const* il = sObjectMgr->GetItemLocale(temp->ItemId))
            ObjectMgr::GetLocaleString(il->Name, localeConstant, name);

    if (int32 itemRandPropId = item->GetItemRandomPropertyId())
    {
        std::array<char const*, 16> const* suffix = nullptr;
        if (itemRandPropId < 0)
        {
            const ItemRandomSuffixEntry* itemRandEntry = sItemRandomSuffixStore.LookupEntry(-itemRandPropId);
            if (itemRandEntry)
                suffix = &itemRandEntry->Name;
        }
        else
        {
            const ItemRandomPropertiesEntry* itemRandEntry = sItemRandomPropertiesStore.LookupEntry(itemRandPropId);
            if (itemRandEntry)
                suffix = &itemRandEntry->Name;
        }
        if (suffix)
        {
            name += ' ';
            name += (*suffix)[loc_idx >= 0 ? loc_idx : LOCALE_enUS];
        }
    }
    return name;
}

std::string Transmogrification::GetItemLink(Item* item, WorldSession* session)
{
    TC_LOG_DEBUG("custom.transmog", "Transmogrification::GetItemLink");

    const ItemTemplate* temp = item->GetTemplate();
    std::ostringstream oss;
    oss << "|c" << std::hex << ItemQualityColors[temp->Quality] << std::dec <<
        "|Hitem:" << temp->ItemId << ":" <<
        item->GetEnchantmentId(PERM_ENCHANTMENT_SLOT) << ":" <<
        item->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT) << ":" <<
        item->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2) << ":" <<
        item->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3) << ":" <<
        item->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT) << ":" <<
        item->GetItemRandomPropertyId() << ":" << item->GetItemSuffixFactor() << ":" <<
        (uint32)item->GetOwner()->GetLevel() << "|h[" << GetItemName(item, session) << "]|h|r";

    return oss.str();
}

std::string Transmogrification::GetItemLink(uint32 entry, WorldSession* session)
{
    TC_LOG_DEBUG("custom.transmog", "Transmogrification::GetItemLink");

    const ItemTemplate* temp = sObjectMgr->GetItemTemplate(entry);
    std::ostringstream oss;
    oss << "|c" << std::hex << ItemQualityColors[temp->Quality] << std::dec <<
        "|Hitem:" << entry << ":0:0:0:0:0:0:0:0:0|h[" << GetItemName(temp, session) << "]|h|r";

    return oss.str();
}

void Transmogrification::UpdateItem(Player* player, Item* item)
{
    TC_LOG_DEBUG("custom.transmog", "Transmogrification::UpdateItem");

    if (item->IsEquipped())
    {
        player->SetVisibleItemSlot(item->GetSlot(), item);
        if (player->IsInWorld())
            item->SendUpdateToPlayer(player);
    }
}

TransmogResult Transmogrification::CannotTransmogrifyItemWithItem(Player* player, ItemTemplate const* target, ItemTemplate const* source, bool ever)
{
    // commented out because items can be same, in which case looks is reverted to old look
    // if (source->ItemId == target->ItemId)
    //     return false;

    // commented out because display can be same as different item entries can have same look but you want to display different item in inspect etc
    // if (source->DisplayInfoID == target->DisplayInfoID)
    //     return false;

    if (source->Class != target->Class)
        return TransmogResult_ItemTypesDontMatch;

    if (TransmogResult res = CannotTransmogrifyItem(player, source, ever))
        return res;

    if (TransmogResult res = CannotTransmogrifyItem(player, target, ever))
        return res;

    if (IsBowOrGunOrCrossbow(source) != IsBowOrGunOrCrossbow(target) ||
        IsMeleeWeapon(source) != IsMeleeWeapon(target))
        return TransmogResult_ItemTypesDontMatch;

    if (source->SubClass != target->SubClass && !IsBowOrGunOrCrossbow(target))
    {
        if (source->Class == ITEM_CLASS_ARMOR && !AllowMixedArmorTypes)
            return TransmogResult_ArmorTypesDontMatch;
        if (source->Class == ITEM_CLASS_WEAPON && !AllowMixedWeaponTypes)
            return TransmogResult_WeaponTypesDontMatch;
        if (source->Class == ITEM_CLASS_WEAPON && !IsMeleeWeapon(target)) // Wands and thrown should not be transmogrifiable with other items like swords etc.
            return TransmogResult_WeaponTypesDontMatch;
    }

    if (source->InventoryType != target->InventoryType)
    {
        if (source->Class == ITEM_CLASS_WEAPON && !((IsBowOrGunOrCrossbow(target) ||
            AllowMixedInventoryTypes ||
            ((target->InventoryType == INVTYPE_WEAPON || target->InventoryType == INVTYPE_2HWEAPON) &&
            (source->InventoryType == INVTYPE_WEAPON || source->InventoryType == INVTYPE_2HWEAPON)) ||
                ((target->InventoryType == INVTYPE_WEAPONMAINHAND || target->InventoryType == INVTYPE_WEAPONOFFHAND) &&
            (source->InventoryType == INVTYPE_WEAPON || source->InventoryType == INVTYPE_2HWEAPON)))))
            return TransmogResult_EquipSlotsDontMatch;
        if (source->Class == ITEM_CLASS_ARMOR &&
            !((source->InventoryType == INVTYPE_CHEST || source->InventoryType == INVTYPE_ROBE) &&
            (target->InventoryType == INVTYPE_CHEST || target->InventoryType == INVTYPE_ROBE)))
            return TransmogResult_EquipSlotsDontMatch;
    }

    return TransmogResult_Ok;
}

// Item::IsFitToSpellRequirements copy paste
static bool IsFitToSpellRequirements(SpellInfo const* spellInfo, ItemTemplate const* proto)
{
    (void)spellInfo;
    (void)proto;
    //bool const isEnchantSpell = spellInfo->HasEffect(SPELL_EFFECT_ENCHANT_ITEM) || spellInfo->HasEffect(SPELL_EFFECT_ENCHANT_ITEM_TEMPORARY) || spellInfo->HasEffect(SPELL_EFFECT_ENCHANT_ITEM_PRISMATIC);
    //if (spellInfo->EquippedItemClass != -1)                 // -1 == any item class
    //{
    //    // Special case - accept vellum for armor/weapon requirements
    //    if (isEnchantSpell && ((spellInfo->EquippedItemClass == ITEM_CLASS_ARMOR && proto->IsArmorVellum())
    //        || (spellInfo->EquippedItemClass == ITEM_CLASS_WEAPON && proto->IsWeaponVellum())))
    //        return true;

    //    if (spellInfo->EquippedItemClass != int32(proto->Class))
    //        return false;                                   //  wrong item class

    //    if (spellInfo->EquippedItemSubClassMask != 0)        // 0 == any subclass
    //    {
    //        if ((spellInfo->EquippedItemSubClassMask & (1 << proto->SubClass)) == 0)
    //            return false;                               // subclass not present in mask
    //    }
    //}

    //if (isEnchantSpell && spellInfo->EquippedItemInventoryTypeMask != 0)       // 0 == any inventory type
    //{
    //    // Special case - accept weapon type for main and offhand requirements
    //    if (proto->InventoryType == INVTYPE_WEAPON &&
    //        (spellInfo->EquippedItemInventoryTypeMask & (1 << INVTYPE_WEAPONMAINHAND) ||
    //            spellInfo->EquippedItemInventoryTypeMask & (1 << INVTYPE_WEAPONOFFHAND)))
    //        return true;
    //    else if ((spellInfo->EquippedItemInventoryTypeMask & (1 << proto->InventoryType)) == 0)
    //        return false;                                   // inventory type not present in mask
    //}

    return true;
}

TransmogResult Transmogrification::CannotTransmogrifyItemWithEnchant(Player * player, ItemTemplate const * destination, uint32 enchant, bool ever)
{
    (void)player;
    (void)ever;
    auto it = enchant_to_spells.find(enchant);
    if (it != enchant_to_spells.end()) {
        for (auto* spellInfo : it->second)
            if (!IsFitToSpellRequirements(spellInfo, destination))
                return TransmogResult_ItemNotFitForEnchantRequirements;
    }
    else {
        return TransmogResult_NonexistantTransmog;
    }

    // Checks just gem requirements, not needed
    //if (!Ignore && source->EnchantmentCondition && !player->EnchantmentFitsRequirements(source->EnchantmentCondition, -1))
    //    return ??;

    //if (!IgnoreReqLevel && source->MinLevel > player->GetLevel())
    //    return TransmogResult_TooLowLevelPlayer;
    //if (!IgnoreReqLevel && source->RequiredSkillID > 0 && source->RequiredSkillRank > player->GetSkillValue(source->RequiredSkillID))
    //    return TransmogResult_TooLowSkill;
    //if (destination->ItemLevel < spellInfo->BaseLevel || (destination->RequiredLevel && destination->RequiredLevel < spellInfo->BaseLevel))
    //    return TransmogResult_TooLowLevelItem;
    //if (spellInfo->MaxLevel && destination->ItemLevel > spellInfo->MaxLevel)
    //    return TransmogResult_TooHighLevelItem;
    return TransmogResult_Ok;
}

TransmogResult Transmogrification::CannotTransmogrifyItem(Player* player, ItemTemplate const* proto, bool ever)
{
    if (TransmogResult res = CannotTransmogrify(proto))
        return res;

    if (ever)
    {
        if (TransmogResult res = CannotEverEquip(player, proto))
            return res;
    }
    else
    {
        if (TransmogResult res = CannotEquip(player, proto))
            return res;
    }

    return TransmogResult_Ok;
}

uint32 Transmogrification::GetSpecialPrice(ItemTemplate const* proto)
{
    TC_LOG_DEBUG("custom.transmog", "Transmogrification::GetSpecialPrice");

    uint32 cost = proto->SellPrice < 10000 ? 10000 : proto->SellPrice;
    return cost;
}

bool Transmogrification::IsBowOrGunOrCrossbow(ItemTemplate const* itemTemplate)
{
    TC_LOG_DEBUG("custom.transmog", "Transmogrification::IsBowOrGunOrCrossbow");

    uint32 Class = itemTemplate->Class;
    uint32 SubClass = itemTemplate->SubClass;
    return Class == ITEM_CLASS_WEAPON && (
        SubClass == ITEM_SUBCLASS_WEAPON_BOW ||
        SubClass == ITEM_SUBCLASS_WEAPON_GUN ||
        SubClass == ITEM_SUBCLASS_WEAPON_CROSSBOW);
}

bool Transmogrification::IsMeleeWeapon(ItemTemplate const* itemTemplate)
{
    TC_LOG_DEBUG("custom.transmog", "Transmogrification::IsMeleeWeapon");

    uint32 Class = itemTemplate->Class;
    uint32 SubClass = itemTemplate->SubClass;
    return Class == ITEM_CLASS_WEAPON && (
        SubClass == ITEM_SUBCLASS_WEAPON_AXE ||
        SubClass == ITEM_SUBCLASS_WEAPON_AXE2 ||
        SubClass == ITEM_SUBCLASS_WEAPON_MACE ||
        SubClass == ITEM_SUBCLASS_WEAPON_MACE2 ||
        SubClass == ITEM_SUBCLASS_WEAPON_POLEARM ||
        SubClass == ITEM_SUBCLASS_WEAPON_SWORD ||
        SubClass == ITEM_SUBCLASS_WEAPON_SWORD2 ||
        SubClass == ITEM_SUBCLASS_WEAPON_STAFF ||
        SubClass == ITEM_SUBCLASS_WEAPON_FIST_WEAPON ||
        SubClass == ITEM_SUBCLASS_WEAPON_DAGGER ||
        SubClass == ITEM_SUBCLASS_WEAPON_SPEAR);
}

bool Transmogrification::IsAllowed(uint32 entry)
{
    TC_LOG_DEBUG("custom.transmog", "Transmogrification::IsAllowed");

    return Allowed.find(entry) != Allowed.end();
}

bool Transmogrification::IsNotAllowed(uint32 entry)
{
    TC_LOG_DEBUG("custom.transmog", "Transmogrification::IsNotAllowed");

    return NotAllowed.find(entry) != NotAllowed.end();
}

bool Transmogrification::IsAllowedQuality(uint32 quality)
{
    TC_LOG_DEBUG("custom.transmog", "Transmogrification::IsAllowedQuality");

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

void Transmogrification::LoadConfig(bool /*reload*/)
{
    TC_LOG_DEBUG("custom.transmog", "Transmogrification::LoadConfig");

    EnableSetInfo = sConfigMgr->GetBoolDefault("Transmogrification.EnableSetInfo", true);
    SetNpcText = uint32(sConfigMgr->GetIntDefault("Transmogrification.SetNpcText", 65001));

    EnableSets = sConfigMgr->GetBoolDefault("Transmogrification.EnableSets", true);
    MaxSets = (uint8)sConfigMgr->GetIntDefault("Transmogrification.MaxSets", 10);

    if (MaxSets > AbsoluteMaxSets)
    {
        MaxSets = AbsoluteMaxSets;
    }

    EnableTransmogInfo = sConfigMgr->GetBoolDefault("Transmogrification.EnableTransmogInfo", true);
    TransmogNpcText = uint32(sConfigMgr->GetIntDefault("Transmogrification.TransmogNpcText", 65000));

    std::istringstream issAllowed(sConfigMgr->GetStringDefault("Transmogrification.Allowed", ""));
    std::istringstream issNotAllowed(sConfigMgr->GetStringDefault("Transmogrification.NotAllowed", ""));
    while (issAllowed.good())
    {
        uint32 entry;
        issAllowed >> entry;
        if (issAllowed.fail())
            break;
        Allowed.insert(entry);
    }
    while (issNotAllowed.good())
    {
        uint32 entry;
        issNotAllowed >> entry;
        if (issNotAllowed.fail())
            break;
        NotAllowed.insert(entry);
    }

    ScaledCostModifier = sConfigMgr->GetFloatDefault("Transmogrification.ScaledCostModifier", 1.0f);
    CopperCost = sConfigMgr->GetIntDefault("Transmogrification.CopperCost", 0);

    AllowPoor = sConfigMgr->GetBoolDefault("Transmogrification.AllowPoor", false);
    AllowCommon = sConfigMgr->GetBoolDefault("Transmogrification.AllowCommon", false);
    AllowUncommon = sConfigMgr->GetBoolDefault("Transmogrification.AllowUncommon", true);
    AllowRare = sConfigMgr->GetBoolDefault("Transmogrification.AllowRare", true);
    AllowEpic = sConfigMgr->GetBoolDefault("Transmogrification.AllowEpic", true);
    AllowLegendary = sConfigMgr->GetBoolDefault("Transmogrification.AllowLegendary", false);
    AllowArtifact = sConfigMgr->GetBoolDefault("Transmogrification.AllowArtifact", false);
    AllowHeirloom = sConfigMgr->GetBoolDefault("Transmogrification.AllowHeirloom", true);

    AllowMixedArmorTypes = sConfigMgr->GetBoolDefault("Transmogrification.AllowMixedArmorTypes", false);
    AllowMixedWeaponTypes = sConfigMgr->GetBoolDefault("Transmogrification.AllowMixedWeaponTypes", false);
    AllowMixedInventoryTypes = sConfigMgr->GetBoolDefault("Transmogrification.AllowMixedInventoryTypes", false);
    AllowFishingPoles = sConfigMgr->GetBoolDefault("Transmogrification.AllowFishingPoles", false);

    IgnoreReqRace = sConfigMgr->GetBoolDefault("Transmogrification.IgnoreReqRace", false);
    IgnoreReqClass = sConfigMgr->GetBoolDefault("Transmogrification.IgnoreReqClass", false);
    IgnoreReqSkill = sConfigMgr->GetBoolDefault("Transmogrification.IgnoreReqSkill", false);
    IgnoreReqSpell = sConfigMgr->GetBoolDefault("Transmogrification.IgnoreReqSpell", false);
    IgnoreReqLevel = sConfigMgr->GetBoolDefault("Transmogrification.IgnoreReqLevel", false);
    IgnoreReqEvent = sConfigMgr->GetBoolDefault("Transmogrification.IgnoreReqEvent", false);
    IgnoreReqStats = sConfigMgr->GetBoolDefault("Transmogrification.IgnoreReqStats", false);
    IgnorePlayerMissingProfiency = sConfigMgr->GetBoolDefault("Transmogrification.IgnorePlayerMissingProfiency", false);
    IgnoreReqFaction = sConfigMgr->GetBoolDefault("Transmogrification.IgnoreReqFaction", false);
    IgnoreReqBound = sConfigMgr->GetIntDefault("Transmogrification.IgnoreReqBound", 0);
}

void Transmogrification::LoadEnchants()
{
    enchant_to_spells.clear();
    spell_to_enchants.clear();
    for (auto* enchant : sSpellItemEnchantmentStore) {
        if (enchant && enchant->ItemVisual && enchant->ItemVisual < static_cast<uint32>(-1)) // Visual can be -1 also
            enchant_to_spells[enchant->ID]; // initialize
    }
    for (uint32 spellid = 0; spellid < sSpellMgr->GetSpellInfoStoreSize(); ++spellid) {
        auto* info = sSpellMgr->GetSpellInfo(spellid);
        if (!info)
            continue;
        for (auto& effect : info->GetEffects()) {
            if (effect.Effect == SpellEffects::SPELL_EFFECT_ENCHANT_ITEM || effect.Effect == SpellEffects::SPELL_EFFECT_ENCHANT_ITEM_TEMPORARY || effect.Effect == SpellEffects::SPELL_EFFECT_ENCHANT_HELD_ITEM) {
                if (enchant_to_spells.find(effect.MiscValue) != enchant_to_spells.end()) {
                    enchant_to_spells[effect.MiscValue].push_back(info);
                    spell_to_enchants[info->Id].push_back(effect.MiscValue);
                }
            }
        }
    }
}

std::vector<ObjectGuid> Transmogrification::GetItemList(const Player* player)
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

TransmogResult Transmogrification::TrySetPendingTransmog(Player* player, uint32 slot, uint32 entry)
{
    TC_LOG_DEBUG("custom.transmog", "Transmogrification::Transmogrify");

    // slot of the transmogrified item
    if (slot >= EQUIPMENT_SLOT_END)
    {
        TC_LOG_DEBUG("custom.transmog", "Transmogrification::Transmogrify - {} ({}) tried to transmogrify invalid slot ({}) with {}.", player->GetName(), player->GetGUID().ToString(), slot, entry);
        return TransmogResult_InvalidSlot;
    }

    ItemTemplate const * itemtemplate = nullptr;
    bool hasTemplate = entry != NormalEntry && entry != InvisibleEntry;
    if (hasTemplate)
    {
        itemtemplate = sObjectMgr->GetItemTemplate(entry);
        if (!itemtemplate)
        {
            TC_LOG_DEBUG("custom.transmog", "Transmogrification::Transmogrify - {} ({}) tried to transmogrify slot {} with a non-existant item entry {}.", player->GetName(), player->GetGUID().ToString(), slot, entry);
            return TransmogResult_NonexistantTransmog;
        }
    }

    // transmogrified item
    Item* itemTransmogrified = player->GetItemByPos(INVENTORY_SLOT_BAG_0, slot);
    if (!itemTransmogrified)
    {
        TC_LOG_DEBUG("custom.transmog", "Transmogrification::Transmogrify - {} ({}) tried to transmogrify slot {} with entry {}, but the slot was empty.", player->GetName(), player->GetGUID().ToString(), slot, entry);
        return TransmogResult_EmptySlot;
    }

    if (hasTemplate)
    {
        if (TransmogResult res = CannotTransmogrifyItemWithItem(player, itemTransmogrified->GetTemplate(), itemtemplate, false))
        {
            TC_LOG_DEBUG("custom.transmog", "Transmogrification::Transmogrify - {} ({}) failed CannotTransmogrifyItemWithItem ({} with {}).", player->GetName(), player->GetGUID().ToString(), itemTransmogrified->GetEntry(), entry);
            return res;
        }
    }

    if (entry == InvisibleEntry && (slot == SLOT_MAIN_HAND || slot == SLOT_OFF_HAND || slot == SLOT_RANGED))
        return TransmogResult_NonexistantTransmog;

    if (entry == InvisibleEntry)
        entry = 0;
    if (entry == NormalEntry)
        entry = itemTransmogrified->GetEntry();
    // Set pending transmog
    player->SetUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID + (slot * 2), entry);
    return TransmogResult_Ok;
}

TransmogResult Transmogrification::TrySetPendingEnchant(Player* player, uint32 slot, uint32 entry)
{
    TC_LOG_DEBUG("custom.transmog", "Transmogrification::Transmogrify");

    // slot of the transmogrified item
    if (slot >= EQUIPMENT_SLOT_END)
    {
        TC_LOG_DEBUG("custom.transmog", "Transmogrification::Transmogrify - {} ({}) tried to transmogrify invalid slot ({}) with {}.", player->GetName(), player->GetGUID().ToString(), slot, entry);
        return TransmogResult_InvalidSlot;
    }

    bool hasTemplate = entry != NormalEntry && entry != InvisibleEntry;

    // transmogrified item
    Item* itemTransmogrified = player->GetItemByPos(INVENTORY_SLOT_BAG_0, slot);
    if (!itemTransmogrified)
    {
        TC_LOG_DEBUG("custom.transmog", "Transmogrification::Transmogrify - {} ({}) tried to transmogrify slot {} with entry {}, but the slot was empty.", player->GetName(), player->GetGUID().ToString(), slot, entry);
        return TransmogResult_EmptySlot;
    }

    if (hasTemplate)
    {
        if (TransmogResult res = CannotTransmogrifyItemWithEnchant(player, itemTransmogrified->GetTemplate(), entry, false)) {
            TC_LOG_DEBUG("custom.transmog", "Transmogrification::Transmogrify - {} ({}) failed CannotTransmogrifyItemWithEnchant ({} with {}).", player->GetName(), player->GetGUID().ToString(), itemTransmogrified->GetEntry(), entry);
            return res;
        }
    }

    if (entry == InvisibleEntry)
        entry = 0;
    if (entry == NormalEntry)
        entry = itemTransmogrified->GetEnchantmentId(PERM_ENCHANTMENT_SLOT);
    // Set pending transmog
    player->SetUInt16Value(PLAYER_VISIBLE_ITEM_1_ENCHANTMENT + (slot * 2), 0, entry);
    return TransmogResult_Ok;
}

void Transmogrification::Transmogrify(Player* player, Item* itemTransmogrified, AppearanceType type, uint32 entry)
{
    if (entry == InvisibleEntry)
        entry = InvisibleEntry;
    if (entry == NormalEntry)
        entry = 0;
    switch (type)
    {
        case TRANSMOG_TYPE_ITEM:
            itemTransmogrified->SetTransmog(entry);
            break;
        case TRANSMOG_TYPE_ENCHANT:
            itemTransmogrified->SetEnchant(entry);
            break;
        case TRANSMOG_TYPE_COUNT:
            return;
    }
    itemTransmogrified->UpdatePlayedTime(player);
    itemTransmogrified->SetOwnerGUID(player->GetGUID());
    itemTransmogrified->SetNotRefundable(player);
    itemTransmogrified->ClearSoulboundTradeable(player);
    itemTransmogrified->SetBinding(true);
    itemTransmogrified->SetState(ITEM_CHANGED, player);
    UpdateItem(player, itemTransmogrified);
}

TransmogResult Transmogrification::CannotEquip(Player* player, ItemTemplate const* proto)
{
    if (!IgnoreReqFaction)
    {
        if ((proto->Flags2 & ITEM_FLAG2_FACTION_HORDE) && player->GetTeam() != HORDE)
            return TransmogResult_InvalidFaction;

        if ((proto->Flags2 & ITEM_FLAG2_FACTION_ALLIANCE) && player->GetTeam() != ALLIANCE)
            return TransmogResult_InvalidFaction;
    }

    if (!IgnoreReqClass && (proto->AllowableClass & player->GetClassMask()) == 0)
        return TransmogResult_InvalidClass;

    if (!IgnoreReqRace && (proto->AllowableRace & player->GetRaceMask()) == 0)
        return TransmogResult_InvalidRace;

    if (!IgnorePlayerMissingProfiency && (proto->GetSkill() != 0 && player->GetSkillValue(proto->GetSkill()) == 0))
        return TransmogResult_MissingProfiency;

    if (!IgnoreReqSkill && proto->RequiredSkill != 0)
    {
        if (player->GetSkillValue(proto->RequiredSkill) == 0)
            return TransmogResult_MissingSkill;
        else if (player->GetSkillValue(proto->RequiredSkill) < proto->RequiredSkillRank)
            return TransmogResult_TooLowSkill;
    }

    if (!IgnoreReqSpell && proto->RequiredSpell != 0 && !player->HasSpell(proto->RequiredSpell))
        return TransmogResult_MissingSpell;

    if (!IgnoreReqLevel && player->GetLevel() < proto->RequiredLevel)
        return TransmogResult_TooLowLevelPlayer;

    return TransmogResult_Ok;
}

static constexpr uint32 classesToClassMask(std::initializer_list<Classes> classes) {
    uint32 mask = 0;
    for (auto c : classes)
        mask |= (1 << (c - 1));
    return mask;
};

// Skills from player->GetSkill() implementation
static std::map<SkillType, uint32> SkillToClassMask = {
    { SKILL_PLATE_MAIL, classesToClassMask({CLASS_PALADIN, CLASS_WARRIOR, CLASS_DEATH_KNIGHT })},
    { SKILL_MAIL, classesToClassMask({CLASS_PALADIN, CLASS_WARRIOR, CLASS_DEATH_KNIGHT, CLASS_HUNTER, CLASS_SHAMAN })},
    { SKILL_LEATHER, classesToClassMask({CLASS_PALADIN, CLASS_WARRIOR, CLASS_DEATH_KNIGHT, CLASS_HUNTER, CLASS_SHAMAN, CLASS_DRUID, CLASS_ROGUE })},
    { SKILL_SHIELD, classesToClassMask({CLASS_PALADIN, CLASS_WARRIOR, CLASS_SHAMAN })},

    { SKILL_2H_AXES, classesToClassMask({CLASS_WARRIOR, CLASS_SHAMAN, CLASS_PALADIN, CLASS_HUNTER, CLASS_DEATH_KNIGHT})},
    { SKILL_AXES, classesToClassMask({CLASS_WARRIOR, CLASS_SHAMAN, CLASS_PALADIN, CLASS_HUNTER, CLASS_DEATH_KNIGHT, CLASS_ROGUE})},

    { SKILL_2H_SWORDS, classesToClassMask({CLASS_WARRIOR, CLASS_PALADIN, CLASS_HUNTER, CLASS_DEATH_KNIGHT})},
    { SKILL_SWORDS, classesToClassMask({CLASS_WARRIOR, CLASS_PALADIN, CLASS_HUNTER, CLASS_DEATH_KNIGHT, CLASS_WARLOCK, CLASS_ROGUE, CLASS_MAGE, })},

    { SKILL_2H_MACES, classesToClassMask({CLASS_WARRIOR, CLASS_SHAMAN, CLASS_PALADIN, CLASS_DRUID, CLASS_DEATH_KNIGHT})},
    { SKILL_MACES, classesToClassMask({CLASS_WARRIOR, CLASS_SHAMAN, CLASS_PALADIN, CLASS_DRUID, CLASS_DEATH_KNIGHT, CLASS_ROGUE, CLASS_PRIEST})},

    { SKILL_BOWS, classesToClassMask({CLASS_WARRIOR, CLASS_HUNTER, CLASS_ROGUE})},
    { SKILL_CROSSBOWS, classesToClassMask({CLASS_WARRIOR, CLASS_HUNTER, CLASS_ROGUE})},
    { SKILL_GUNS, classesToClassMask({CLASS_WARRIOR, CLASS_HUNTER, CLASS_ROGUE})},

    { SKILL_STAVES, classesToClassMask({CLASS_WARRIOR, CLASS_WARLOCK, CLASS_SHAMAN, CLASS_PRIEST, CLASS_MAGE, CLASS_HUNTER, CLASS_DRUID})},
    { SKILL_POLEARMS, classesToClassMask({CLASS_WARRIOR, CLASS_PALADIN, CLASS_HUNTER, CLASS_DRUID, CLASS_DEATH_KNIGHT})},
    { SKILL_FIST_WEAPONS, classesToClassMask({CLASS_WARRIOR, CLASS_SHAMAN, CLASS_ROGUE, CLASS_HUNTER, CLASS_DRUID})},
    { SKILL_DAGGERS, classesToClassMask({CLASS_WARRIOR, CLASS_WARLOCK, CLASS_SHAMAN, CLASS_ROGUE, CLASS_PRIEST, CLASS_MAGE, CLASS_HUNTER, CLASS_DRUID})},
    { SKILL_THROWN, classesToClassMask({CLASS_WARRIOR, CLASS_ROGUE})},
    { SKILL_WANDS, classesToClassMask({CLASS_WARLOCK, CLASS_PRIEST, CLASS_MAGE})},

    { SKILL_FISHING, CLASSMASK_ALL_PLAYABLE},
    { SKILL_ASSASSINATION, 0},
};

TransmogResult Transmogrification::CannotEverEquip(Player* player, ItemTemplate const* proto)
{
    if (!IgnoreReqFaction)
    {
        if ((proto->Flags2 & ITEM_FLAG2_FACTION_HORDE) && player->GetTeam() != HORDE)
            return TransmogResult_InvalidFaction;

        if ((proto->Flags2 & ITEM_FLAG2_FACTION_ALLIANCE) && player->GetTeam() != ALLIANCE)
            return TransmogResult_InvalidFaction;
    }

    if (!IgnoreReqClass && (proto->AllowableClass & player->GetClassMask()) == 0)
        return TransmogResult_InvalidClass;

    if (!IgnoreReqRace && (proto->AllowableRace & player->GetRaceMask()) == 0)
        return TransmogResult_InvalidRace;

    // We need to check that player can ever get the required profiency
    if (!IgnorePlayerMissingProfiency && proto->GetSkill() != 0)
    {
        auto it = SkillToClassMask.find(static_cast<SkillType>(proto->GetSkill()));
        if (it != SkillToClassMask.end() && (it->second & player->GetClassMask()) == 0)
            return TransmogResult_MissingProfiency;
    }

    // Ignore required level as player can level up
    // Ignore required skill as in DB they are all profession related and player can learn them later
    // Ignore required spells as in DB they are all profession related and player can learn them later

    return TransmogResult_Ok;
}

TransmogResult Transmogrification::CannotTransmogrify(ItemTemplate const* proto)
{
    // select * from item_template where class not in (2,4) and inventorytype in (1,34,5,6,7,8,9,10,13,14,1516,17,19,20,21,22,23,25,26,28)
    if (proto->Class != ITEM_CLASS_ARMOR &&
        proto->Class != ITEM_CLASS_WEAPON)
        return TransmogResult_InvalidItemType;

    if (proto->InventoryType != INVTYPE_HEAD &&
        proto->InventoryType != INVTYPE_SHOULDERS &&
        proto->InventoryType != INVTYPE_BODY &&
        proto->InventoryType != INVTYPE_CHEST &&
        proto->InventoryType != INVTYPE_WAIST &&
        proto->InventoryType != INVTYPE_LEGS &&
        proto->InventoryType != INVTYPE_FEET &&
        proto->InventoryType != INVTYPE_WRISTS &&
        proto->InventoryType != INVTYPE_HANDS &&
        proto->InventoryType != INVTYPE_WEAPON &&
        proto->InventoryType != INVTYPE_SHIELD &&
        proto->InventoryType != INVTYPE_RANGED &&
        proto->InventoryType != INVTYPE_CLOAK &&
        proto->InventoryType != INVTYPE_2HWEAPON &&
        proto->InventoryType != INVTYPE_TABARD &&
        proto->InventoryType != INVTYPE_ROBE &&
        proto->InventoryType != INVTYPE_WEAPONMAINHAND &&
        proto->InventoryType != INVTYPE_WEAPONOFFHAND &&
        proto->InventoryType != INVTYPE_HOLDABLE &&
        proto->InventoryType != INVTYPE_THROWN &&
        proto->InventoryType != INVTYPE_RANGEDRIGHT &&
        proto->InventoryType != INVTYPE_RELIC)
        return TransmogResult_InvalidItemType;

    // Skip all checks for allowed items
    if (IsAllowed(proto->ItemId))
        return TransmogResult_Ok;

    if (IsNotAllowed(proto->ItemId))
        return TransmogResult_ItemBlocked;

    if (!AllowFishingPoles && proto->Class == ITEM_CLASS_WEAPON && proto->SubClass == ITEM_SUBCLASS_WEAPON_FISHING_POLE)
        return TransmogResult_FishingPoleBlocked;

    if (!IsAllowedQuality(proto->Quality))
        return TransmogResult_InvalidItemQuality;

    // Commented out because not sure if such restriction exists
    // If World Event is not active, prevent using event dependant items
    // if (!IgnoreReqEvent && proto->HolidayId && !IsHolidayActive((HolidayIds)proto->HolidayId))
    //     return TransmogResult_RequiredEventNotActive;

    if (!IgnoreReqStats)
    {
        static const auto hasStat = [](ItemTemplate const* proto) {
            for (decltype(proto->StatsCount) i = 0; i < proto->StatsCount; ++i)
            {
                if (proto->ItemStat[i].ItemStatValue != 0)
                    return true;
            }
            return false;
        };
        if (!proto->RandomProperty && !proto->RandomSuffix && !hasStat(proto))
            return TransmogResult_ItemMustHaveStats;
    }

    return TransmogResult_Ok;
}

bool IsBound(Item* item)
{
    if (item->HasFlag(ITEM_FIELD_FLAGS, ITEM_FIELD_FLAG_BOP_TRADEABLE))
        return false;
    if (!item->IsSoulBound() && !item->IsBoundAccountWide())
        return false;
    return true;
}

bool Transmogrification::CanAddToCollection(Player* player, Item* item)
{
    if (IgnoreReqBound == 0 && !IsBound(item))
        return false;
    ItemTemplate const* temp = item->GetTemplate();
    if (IgnoreReqBound == 1 && !IsBound(item) && temp->Bonding != NO_BIND)
        return false;
    //if (IgnoreReqBound == 2)
    //    pass;
    return CanAddToCollection(player, temp);
}

bool Transmogrification::CanAddEnchantToCollection(Player* player, Item* item)
{
    (void)player;
    (void)item;
    //if (!IgnoreReqBound && !IsBound(item))
    //    return false;
    //if (CannotEverEquip(player, item->GetTemplate()))
    //    return false;
    return true;
}

bool Transmogrification::CanAddToCollection(Player* player, ItemTemplate const* itemTemplate)
{
    if (CannotTransmogrify(itemTemplate))
        return false;
    if (CannotEverEquip(player, itemTemplate))
        return false;
    return true;
}

void Transmogrification::SaveToDB(Player* player, AppearanceType transmogtype, uint32 visual)
{
    auto stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_ACCOUNT_TRANSMOG);
    stmt->setUInt32(0, player->GetSession()->GetAccountId());
    stmt->setUInt32(1, transmogtype);
    stmt->setUInt32(2, visual);
    CharacterDatabase.Execute(stmt);
}

bool Transmogrification::HasVisual(Player* player, AppearanceType transmogtype, uint32 visual)
{
    if (transmogtype == AppearanceType::TRANSMOG_TYPE_ENCHANT) {
        // Enchants are currently not all saved to appearances
        auto it = enchant_to_spells.find(visual);
        if (it != enchant_to_spells.end()) {
            return true;
        }
    }
    auto& cont = player->transmogrification_appearances[transmogtype];
    return cont.find(visual) != cont.end();
}

uint32 Transmogrification::Save(Player* player, AppearanceType transmogtype, uint32 visual)
{
    if (player->transmogrification_appearances[transmogtype].insert(visual).second)
    {
        SaveToDB(player, transmogtype, visual);
        return visual;
    }
    return 0;
}

uint32 Transmogrification::AddItemVisualToCollection(Player* player, Item* item)
{
    uint32 visual = item->GetEntry();
    if (!visual || !CanAddToCollection(player, item))
        return 0;
    return Save(player, TRANSMOG_TYPE_ITEM, visual);
}

uint32 Transmogrification::AddItemVisualToCollection(Player* player, const ItemTemplate* itemtemplate)
{
    if (!itemtemplate || !CanAddToCollection(player, itemtemplate))
        return 0;
    return Save(player, TRANSMOG_TYPE_ITEM, itemtemplate->ItemId);
}

uint32 Transmogrification::AddEnchantVisualToCollection(Player* player, uint32 enchant_id)
{
    //// only weapon enchants
    //auto item_template = item->GetTemplate();
    //if (!IsMeleeWeapon(item_template) && !IsBowOrGunOrCrossbow(item_template))
    //    return 0;

    //// only permanent enchants
    //uint32 enchant_id = item->GetEnchantmentId(PERM_ENCHANTMENT_SLOT);
    if (!enchant_id)
        return 0;
    //if (!CanAddEnchantToCollection(player, item))
    //    return 0;
    return Save(player, TRANSMOG_TYPE_ENCHANT, enchant_id);
}

void Transmogrification::AddToCollection(Player* player, Item* item)
{
    if (!player)
        return;
    if (!item)
        return;
    if (uint32 transmog = AddItemVisualToCollection(player, item))
        ChatHandler(player->GetSession()).PSendSysMessage(AddToCollectionMessageFmt, GetItemLink(transmog, player->GetSession()).c_str());
}

void Transmogrification::AddToCollection(Player* player, const ItemTemplate* itemtemplate)
{
    if (!player)
        return;
    if (!itemtemplate)
        return;
    if (uint32 transmog = AddItemVisualToCollection(player, itemtemplate)) {
        ChatHandler(player->GetSession()).PSendSysMessage(AddToCollectionMessageFmt, GetItemLink(transmog, player->GetSession()).c_str());
    }
}

void Transmogrification::AddToCollectionEnchant(Player* player, uint32 enchant_id)
{
    if (!player)
        return;
    if (uint32 enchant = AddEnchantVisualToCollection(player, enchant_id))
    {
        decltype(auto) enchantEntry = sSpellItemEnchantmentStore.LookupEntry(enchant);
        if (enchantEntry)
        {
            auto it = enchant_visual_to_name.find(enchantEntry->ItemVisual);
            if (it != enchant_visual_to_name.end()) {
                ChatHandler(player->GetSession()).PSendSysMessage(AddToCollectionMessageFmt, it->second);
            }
        }
    }
}

void Transmogrification::RemoveAllTransmogrifications(Player* player)
{
    for (Item* item : GetEquippedItems(player))
    {
        player->SetUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID + (item->GetSlot() * 2), item->GetEntry());
        player->SetUInt16Value(PLAYER_VISIBLE_ITEM_1_ENCHANTMENT + (item->GetSlot() * 2), 0, item->GetEnchantmentId(PERM_ENCHANTMENT_SLOT));
    }
}

void Transmogrification::RevertAllTransmogrifications(Player* player)
{
    for (auto&& pending : GetPendingTransmogs(player))
        UpdateItem(player, std::get<Item*>(pending));
}

bool Transmogrification::RevertTransmogrification(Player* player, uint8 slot)
{
    Item* item;
    if (HasPendingTransmog(player, slot, &item))
    {
        uint32 enchant = player->GetUInt16Value(PLAYER_VISIBLE_ITEM_1_ENCHANTMENT + (slot * 2), 0);
        UpdateItem(player, item); // removes pending enchant and transmog
        player->SetUInt16Value(PLAYER_VISIBLE_ITEM_1_ENCHANTMENT + (slot * 2), 0, enchant); // restore pending enchant
        return true;
    }
    return false;
}

bool Transmogrification::RevertEnchant(Player* player, uint8 slot)
{
    Item* item;
    if (HasPendingEnchant(player, slot, &item))
    {
        uint32 transmog = player->GetUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID + (slot * 2));
        UpdateItem(player, item); // removes pending enchant and transmog
        player->SetUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID + (slot * 2), transmog); // restore pending transmog
        return true;
    }
    return false;
}

Item* Transmogrification::GetEquippedItem(Player* player, uint8 slot)
{
    return player->GetItemByPos(INVENTORY_SLOT_BAG_0, slot);
}

std::vector<Item*> Transmogrification::GetEquippedItems(Player* player)
{
    std::vector<Item*> items;
    for (uint8 slot = EQUIPMENT_SLOT_START; slot < EQUIPMENT_SLOT_END; ++slot)
        if (Item* item = GetEquippedItem(player, slot))
            items.push_back(item);
    return items;
}

bool Transmogrification::HasPendingTransmog(Player* player, uint8 slot, Item** retItem, uint32* retPending, uint32* retCurrent)
{
    Item* item = GetEquippedItem(player, slot);
    if (!item)
        return false;
    uint32 current = GetCurrentVisual(item);
    uint32 pending = player->GetUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID + (slot * 2));
    if (current == item->GetEntry())
        current = NormalEntry;
    if (current == 0)
        pending = InvisibleEntry;
    if (pending == item->GetEntry())
        pending = NormalEntry;
    if (pending == 0)
        pending = InvisibleEntry;
    if (pending != current)
    {
        if (pending == NormalEntry || pending == InvisibleEntry)
        {
            if (CannotTransmogrifyItem(player, item->GetTemplate(), false))
                return false;
        }
        else
        {
            decltype(auto) sourceTemplate = sObjectMgr->GetItemTemplate(pending);
            if (!sourceTemplate)
                return false;
            if (CannotTransmogrifyItemWithItem(player, item->GetTemplate(), sourceTemplate, false))
                return false;
        }
        if (retItem)
            *retItem = item;
        if (retPending)
            *retPending = pending;
        if (retCurrent)
            *retCurrent = current;
        return true;
    }
    return false;
}

bool Transmogrification::HasPendingEnchant(Player* player, uint8 slot, Item** retItem, uint32* retPending, uint32* retCurrent)
{
    Item* item = GetEquippedItem(player, slot);
    if (!item)
        return false;
    uint32 current = GetCurrentVisualEnchant(item);
    uint32 pending = player->GetUInt16Value(PLAYER_VISIBLE_ITEM_1_ENCHANTMENT + (item->GetSlot() * 2), 0);
    if (current == item->GetEnchantmentId(PERM_ENCHANTMENT_SLOT))
        current = NormalEntry;
    if (current == 0)
        pending = InvisibleEntry;
    if (pending == item->GetEnchantmentId(PERM_ENCHANTMENT_SLOT))
        pending = NormalEntry;
    if (pending == 0)
        pending = InvisibleEntry;
    if (pending != current)
    {
        if (pending == NormalEntry || pending == InvisibleEntry)
        {
            if (CannotTransmogrifyItem(player, item->GetTemplate(), false))
                return false;
        }
        else
        {
            decltype(auto) enchantEntry = sSpellItemEnchantmentStore.LookupEntry(pending);
            if (!enchantEntry)
                return false;
            if (CannotTransmogrifyItem(player, item->GetTemplate(), false))
                return false;
        }
        if (retItem)
            *retItem = item;
        if (retPending)
            *retPending = pending;
        if (retCurrent)
            *retCurrent = current;
        return true;
    }
    return false;
}

PendingTransmogs Transmogrification::GetPendingTransmogs(Player* player)
{
    PendingTransmogs pending_transmogs;
    for (uint8 slot = EQUIPMENT_SLOT_START; slot < EQUIPMENT_SLOT_END; ++slot)
    {
        Item* item;
        uint32 pending;
        if (HasPendingTransmog(player, slot, &item, &pending))
            pending_transmogs.emplace_back(item, pending, TRANSMOG_TYPE_ITEM);
        if (HasPendingEnchant(player, slot, &item, &pending))
            pending_transmogs.emplace_back(item, pending, TRANSMOG_TYPE_ENCHANT);
    }
    return pending_transmogs;
}

uint32 Transmogrification::GetCurrentVisual(Item* item)
{
    if (item->GetTransmog())
        return item->GetTransmog();
    return item->GetEntry();
}

uint32 Transmogrification::GetCurrentVisualEnchant(Item* item)
{
    if (item->GetEnchant())
        return item->GetEnchant();
    return item->GetEnchantmentId(PERM_ENCHANTMENT_SLOT);
}

int32 Transmogrification::CalculateTransmogCost(PendingTransmogs& items)
{
    int32 cost = 0;
    for (auto&& pending : items)
    {
        uint32 entry = std::get<uint32>(pending);
        switch (std::get<AppearanceType>(pending))
        {
            case TRANSMOG_TYPE_ITEM:
                cost += CalculateTransmogCost(entry);
                break;
            case TRANSMOG_TYPE_ENCHANT:
                if (entry == InvisibleEntry)
                    break;
                if (entry == NormalEntry)
                    break;
                cost += 1 * GOLD;
                break;
            case TRANSMOG_TYPE_COUNT:
                break;
        }
    }
    return cost;
}

int32 Transmogrification::CalculateTransmogCost(uint32 entry)
{
    if (entry == InvisibleEntry)
        return 0;
    if (entry == NormalEntry)
        return 0;
    auto const* temp = sObjectMgr->GetItemTemplate(entry);
    if (!temp)
        return 0;
    int32 cost = 0;
    cost += GetSpecialPrice(temp);
    cost *= ScaledCostModifier;
    cost += CopperCost;
    return std::max(cost, 0);
}

TransmogResult Transmogrification::TransmogrifyPending(Player* player, int32 expectedCost /*= -1*/)
{
    auto pending = GetPendingTransmogs(player);
    if (pending.empty())
        return TransmogResult_NoPendingTarnsmogs;
    int32 cost = CalculateTransmogCost(pending);
    if (cost >= 0 && cost != expectedCost)
        return TransmogResult_CostChangedDuringTransaction;
    if (cost > 0 && !player->HasEnoughMoney(cost))
        return TransmogResult_NotEnoughMoney;
    player->ModifyMoney(-cost);
    for (auto&& transmog : pending)
    {
        Transmogrify(player, std::get<Item*>(transmog), std::get<AppearanceType>(transmog), std::get<uint32>(transmog));
    }
    return TransmogResult_Ok;
}
