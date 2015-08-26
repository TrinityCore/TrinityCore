#include <sstream>
#include <string>
#include <vector>
#include "Creature.h"
#include "Define.h"
#include "EventProcessor.h"
#include "GossipDef.h"
#include "Item.h"
#include "ItemPrototype.h"
#include "ObjectGuid.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "ScriptedGossip.h"
#include "ScriptMgr.h"
#include "SharedDefines.h"
#include "Spell.h"
#include "Transaction.h"
#include "WorldPacket.h"
#include "WorldSession.h"

/*
Reforging by Rochet2
http://rochet2.github.io/Transmogrification.html

Rules of thumb:
Item can be reforged once.
Item reforge wont show to anyone but you in tooltips. Stats will be there nevertheless.
You will see the increased stats on all tooltips of the same item you reforged.
You can disable the stat changes to tooltips by setting send_cache_packets to false.
Reforges are stripped when you mail, ah, guildbank the item etc. Only YOU can have the reforge.
Only item base stats are reforgable. Enchants and random stats are not.

This script is made blizzlike. This means that the reforgable stats etc are from CATACLYSM!
I have been informed that some stats were removed etc that would be important to be reforgable.
However I do not know what those stats are currently. Do look through the statTypes to add whatever you want.
Edit IsReforgable is you want to tweak requirements

*/

static const bool send_cache_packets = true;    // change player cache?

// Remember to add to GetStatName too
static const ItemModType statTypes[] = { ITEM_MOD_SPIRIT, ITEM_MOD_DODGE_RATING, ITEM_MOD_PARRY_RATING, ITEM_MOD_HIT_RATING, ITEM_MOD_CRIT_RATING, ITEM_MOD_HASTE_RATING, ITEM_MOD_EXPERTISE_RATING };
static const uint8 stat_type_max = sizeof(statTypes) / sizeof(*statTypes);

static const char* GetStatName(uint32 ItemStatType)
{
    switch(ItemStatType)
    {
    case ITEM_MOD_SPIRIT                   	: return "Spirit"; break;
    case ITEM_MOD_DODGE_RATING             	: return "Dodge rating"; break;
    case ITEM_MOD_PARRY_RATING             	: return "Parry rating"; break;
    case ITEM_MOD_HIT_RATING               	: return "Hit rating"; break;
    case ITEM_MOD_CRIT_RATING              	: return "Crit rating"; break;
    case ITEM_MOD_HASTE_RATING             	: return "Haste rating"; break;
    case ITEM_MOD_EXPERTISE_RATING         	: return "Expertise rating"; break;
    default: return NULL;
    }
}

static const char* GetSlotName(uint8 slot, WorldSession* /*session*/)
{
    switch (slot)
    {
    case EQUIPMENT_SLOT_HEAD      : return "Head";
    case EQUIPMENT_SLOT_NECK      : return "Neck";
    case EQUIPMENT_SLOT_SHOULDERS : return "Shoulders";
    case EQUIPMENT_SLOT_BODY      : return "Shirt";
    case EQUIPMENT_SLOT_CHEST     : return "Chest";
    case EQUIPMENT_SLOT_WAIST     : return "Waist";
    case EQUIPMENT_SLOT_LEGS      : return "Legs";
    case EQUIPMENT_SLOT_FEET      : return "Feet";
    case EQUIPMENT_SLOT_WRISTS    : return "Wrists";
    case EQUIPMENT_SLOT_HANDS     : return "Hands";
    case EQUIPMENT_SLOT_FINGER1   : return "Right finger";
    case EQUIPMENT_SLOT_FINGER2   : return "Left finger";
    case EQUIPMENT_SLOT_TRINKET1  : return "Right trinket";
    case EQUIPMENT_SLOT_TRINKET2  : return "Left trinket";
    case EQUIPMENT_SLOT_BACK      : return "Back";
    case EQUIPMENT_SLOT_MAINHAND  : return "Main hand";
    case EQUIPMENT_SLOT_OFFHAND   : return "Off hand";
    case EQUIPMENT_SLOT_TABARD    : return "Tabard";
    case EQUIPMENT_SLOT_RANGED    : return "Ranged";
    default: return NULL;
    }
}

static uint32 Melt(uint8 i, uint8 j)
{
    return (i << 8) + j;
}

static void Unmelt(uint32 melt, uint8& i, uint8& j)
{
    i = melt >> 8;
    j = melt & 0xFF;
}

static std::vector<Item*> GetItemList(const Player* player)
{
    std::vector<Item*> itemlist;

    // Copy paste from Player::GetItemByGuid(guid)

    for (uint8 i = EQUIPMENT_SLOT_START; i < INVENTORY_SLOT_ITEM_END; ++i)
        if (Item* pItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            itemlist.push_back(pItem);

    for (uint8 i = KEYRING_SLOT_START; i < CURRENCYTOKEN_SLOT_END; ++i)
        if (Item* pItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            itemlist.push_back(pItem);

    for (int i = BANK_SLOT_ITEM_START; i < BANK_SLOT_BAG_END; ++i)
        if (Item* pItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            itemlist.push_back(pItem);

    for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
        if (Bag* pBag = player->GetBagByPos(i))
            for (uint32 j = 0; j < pBag->GetBagSize(); ++j)
                if (Item* pItem = pBag->GetItemByPos(j))
                    itemlist.push_back(pItem);

    for (uint8 i = BANK_SLOT_BAG_START; i < BANK_SLOT_BAG_END; ++i)
        if (Bag* pBag = player->GetBagByPos(i))
            for (uint32 j = 0; j < pBag->GetBagSize(); ++j)
                if (Item* pItem = pBag->GetItemByPos(j))
                    itemlist.push_back(pItem);

    return itemlist;
}

static Item* GetEquippedItem(Player* player, uint32 guidlow)
{
    for (uint8 i = EQUIPMENT_SLOT_START; i < INVENTORY_SLOT_ITEM_END; ++i)
        if (Item* pItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            if (pItem->GetGUIDLow() == guidlow)
                return pItem;
    return NULL;
}

void RemoveReforge(Player* player, uint32 itemguid, bool update);

// Supply lowguid or reforge! (or both)
// Warning, this function may modify player->reforgeMap when lowguid is supplied
static void SendReforgePacket(Player* player, uint32 entry, uint32 lowguid = 0, const ReforgeData* reforge = NULL)
{
    ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(entry);
    if (!pProto)
        return;

    if (lowguid)
    {
        if (!player->reforgeMap.empty() && player->reforgeMap.find(lowguid) != player->reforgeMap.end())
            reforge = &player->reforgeMap[lowguid];
        else
            RemoveReforge(player, lowguid, true);
    }

    // Update player cache (self only) pure visual.
    // HandleItemQuerySingleOpcode copy paste
    std::string Name        = pProto->Name1;
    std::string Description = pProto->Description;
    int loc_idx = player->GetSession()->GetSessionDbLocaleIndex();
    if (loc_idx >= 0)
    {
        if (ItemLocale const* il = sObjectMgr->GetItemLocale(pProto->ItemId))
        {
            ObjectMgr::GetLocaleString(il->Name, loc_idx, Name);
            ObjectMgr::GetLocaleString(il->Description, loc_idx, Description);
        }
    }
    WorldPacket data(SMSG_ITEM_QUERY_SINGLE_RESPONSE, 600);
    data << pProto->ItemId;
    data << pProto->Class;
    data << pProto->SubClass;
    data << pProto->SoundOverrideSubclass;
    data << Name;
    data << uint8(0x00);                                //pProto->Name2; // blizz not send name there, just uint8(0x00); <-- \0 = empty string = empty name...
    data << uint8(0x00);                                //pProto->Name3; // blizz not send name there, just uint8(0x00);
    data << uint8(0x00);                                //pProto->Name4; // blizz not send name there, just uint8(0x00);
    data << pProto->DisplayInfoID;
    data << pProto->Quality;
    data << pProto->Flags;
    data << pProto->Flags2;
    data << pProto->BuyPrice;
    data << pProto->SellPrice;
    data << pProto->InventoryType;
    data << pProto->AllowableClass;
    data << pProto->AllowableRace;
    data << pProto->ItemLevel;
    data << pProto->RequiredLevel;
    data << pProto->RequiredSkill;
    data << pProto->RequiredSkillRank;
    data << pProto->RequiredSpell;
    data << pProto->RequiredHonorRank;
    data << pProto->RequiredCityRank;
    data << pProto->RequiredReputationFaction;
    data << pProto->RequiredReputationRank;
    data << int32(pProto->MaxCount);
    data << int32(pProto->Stackable);
    data << pProto->ContainerSlots;
    data << pProto->StatsCount + (reforge ? 1 : 0); // increase stat count by 1
    bool decreased = false;
    for (uint32 i = 0; i < pProto->StatsCount; ++i)
    {
        data << pProto->ItemStat[i].ItemStatType;
        if (reforge && !decreased && pProto->ItemStat[i].ItemStatType == reforge->decrease)
        {
            data << pProto->ItemStat[i].ItemStatValue-reforge->stat_value;
            decreased = true;
        }
        else
        {
            data << pProto->ItemStat[i].ItemStatValue;
        }
    }
    if (reforge)
    {
        data << reforge->increase;      // set new stat type
        data << reforge->stat_value;    // and value
    }
    data << pProto->ScalingStatDistribution;            // scaling stats distribution
    data << pProto->ScalingStatValue;                   // some kind of flags used to determine stat values column
    for (int i = 0; i < MAX_ITEM_PROTO_DAMAGES; ++i)
    {
        data << pProto->Damage[i].DamageMin;
        data << pProto->Damage[i].DamageMax;
        data << pProto->Damage[i].DamageType;
    }

    // resistances (7)
    data << pProto->Armor;
    data << pProto->HolyRes;
    data << pProto->FireRes;
    data << pProto->NatureRes;
    data << pProto->FrostRes;
    data << pProto->ShadowRes;
    data << pProto->ArcaneRes;

    data << pProto->Delay;
    data << pProto->AmmoType;
    data << pProto->RangedModRange;

    for (int s = 0; s < MAX_ITEM_PROTO_SPELLS; ++s)
    {
        // send DBC data for cooldowns in same way as it used in Spell::SendSpellCooldown
        // use `item_template` or if not set then only use spell cooldowns
        SpellInfo const* spell = sSpellMgr->GetSpellInfo(pProto->Spells[s].SpellId);
        if (spell)
        {
            bool db_data = pProto->Spells[s].SpellCooldown >= 0 || pProto->Spells[s].SpellCategoryCooldown >= 0;

            data << pProto->Spells[s].SpellId;
            data << pProto->Spells[s].SpellTrigger;
            data << uint32(-abs(pProto->Spells[s].SpellCharges));

            if (db_data)
            {
                data << uint32(pProto->Spells[s].SpellCooldown);
                data << uint32(pProto->Spells[s].SpellCategory);
                data << uint32(pProto->Spells[s].SpellCategoryCooldown);
            }
            else
            {
                data << uint32(spell->RecoveryTime);
                data << uint32(spell->GetCategory());
                data << uint32(spell->CategoryRecoveryTime);
            }
        }
        else
        {
            data << uint32(0);
            data << uint32(0);
            data << uint32(0);
            data << uint32(-1);
            data << uint32(0);
            data << uint32(-1);
        }
    }
    data << pProto->Bonding;
    data << Description;
    data << pProto->PageText;
    data << pProto->LanguageID;
    data << pProto->PageMaterial;
    data << pProto->StartQuest;
    data << pProto->LockID;
    data << int32(pProto->Material);
    data << pProto->Sheath;
    data << pProto->RandomProperty;
    data << pProto->RandomSuffix;
    data << pProto->Block;
    data << pProto->ItemSet;
    data << pProto->MaxDurability;
    data << pProto->Area;
    data << pProto->Map;                                // Added in 1.12.x & 2.0.1 client branch
    data << pProto->BagFamily;
    data << pProto->TotemCategory;
    for (int s = 0; s < MAX_ITEM_PROTO_SOCKETS; ++s)
    {
        data << pProto->Socket[s].Color;
        data << pProto->Socket[s].Content;
    }
    data << pProto->socketBonus;
    data << pProto->GemProperties;
    data << pProto->RequiredDisenchantSkill;
    data << pProto->ArmorDamageModifier;
    data << pProto->Duration;                           // added in 2.4.2.8209, duration (seconds)
    data << pProto->ItemLimitCategory;                  // WotLK, ItemLimitCategory
    data << pProto->HolidayId;                          // Holiday.dbc?
    player->GetSession()->SendPacket(&data);
}

static void SendReforgePackets(Player* player)
{
    if (!send_cache_packets)
        return;

    std::vector<Item*> items = GetItemList(player);
    for (std::vector<Item*>::const_iterator it = items.begin(); it != items.end(); ++it)
        SendReforgePacket(player, (*it)->GetEntry(), (*it)->GetGUIDLow());
}

void RemoveReforge(Player* player, uint32 itemguid, bool update)
{
    if (!itemguid || player->reforgeMap.empty() ||
        player->reforgeMap.find(itemguid) == player->reforgeMap.end())
        return;

    Item* invItem = update ? player->GetItemByGuid(ObjectGuid(HIGHGUID_ITEM, 0, itemguid)) : NULL;
    if (!invItem)
    {
        player->reforgeMap.erase(itemguid);
        return;
    }

    player->_ApplyItemMods(invItem, invItem->GetSlot(), false);
    player->reforgeMap.erase(itemguid);
    player->_ApplyItemMods(invItem, invItem->GetSlot(), true);
    SendReforgePacket(player, invItem->GetEntry());
}

static bool IsReforgable(Item* invItem, Player* player)
{
    //if (!invItem->IsEquipped())
    //    return false;
    if (invItem->GetOwnerGUID() != player->GetGUID())
        return false;
    const ItemTemplate* pProto = invItem->GetTemplate();
    //if (pProto->ItemLevel < 200)
    //    return false;
    //if (pProto->Quality == ITEM_QUALITY_HEIRLOOM) // block heirlooms necessary?
    //    return false;
    if (!pProto->StatsCount || pProto->StatsCount >= MAX_ITEM_PROTO_STATS) // Mandatory! Do NOT remove or edit
        return false;
    if (!player->reforgeMap.empty() && player->reforgeMap.find(invItem->GetGUIDLow()) != player->reforgeMap.end()) // Mandatory! Do NOT remove or edit
        return false;
    for (uint32 i = 0; i < pProto->StatsCount; ++i)
    {
        if (!GetStatName(pProto->ItemStat[i].ItemStatType))
            continue;
        if (((int32)floorf((float)pProto->ItemStat[i].ItemStatValue * 0.4f)) > 1)
            return true;
    }
    return false;
}

static void UpdatePlayerReforgeStats(Item* invItem, Player* player, uint32 decrease, uint32 increase) // stat types
{
    const ItemTemplate* pProto = invItem->GetTemplate();

    int32 stat_diff = 0;
    for (uint32 i = 0; i < pProto->StatsCount; ++i)
    {
        if (pProto->ItemStat[i].ItemStatType == increase)
            return; // Should not have the increased stat already
        if (pProto->ItemStat[i].ItemStatType == decrease)
            stat_diff = (int32)floorf((float)pProto->ItemStat[i].ItemStatValue * 0.4f);
    }
    if (stat_diff <= 0)
        return; // Should have some kind of diff

    // Update player stats
    player->_ApplyItemMods(invItem, invItem->GetSlot(), false);
    uint32 guidlow = invItem->GetGUIDLow();
    ReforgeData& data = player->reforgeMap[guidlow];
    data.increase = increase;
    data.decrease = decrease;
    data.stat_value = stat_diff;
    player->_ApplyItemMods(invItem, invItem->GetSlot(), true);
    // CharacterDatabase.PExecute("REPLACE INTO `custom_reforging` (`GUID`, `increase`, `decrease`, `stat_value`) VALUES (%u, %u, %u, %i)", guidlow, increase, decrease, stat_diff);
    player->ModifyMoney(pProto->SellPrice < (10*GOLD) ? (-10*GOLD) : -(int32)pProto->SellPrice);
    SendReforgePacket(player, invItem->GetEntry(), 0, &data);
    // player->SaveToDB();
}

class REFORGE_PLAYER : public PlayerScript
{
public:
    REFORGE_PLAYER() : PlayerScript("REFORGE_PLAYER")
    {
        CharacterDatabase.DirectExecute("DELETE FROM `custom_reforging` WHERE NOT EXISTS (SELECT 1 FROM `item_instance` WHERE `item_instance`.`guid` = `custom_reforging`.`GUID`)");
    }

    class SendRefPackLogin : public BasicEvent
    {
    public:
        SendRefPackLogin(Player* _player) : player(_player)
        {
            _player->m_Events.AddEvent(this, _player->m_Events.CalculateTime(1000));
        }

        bool Execute(uint64, uint32) override
        {
            SendReforgePackets(player);
            return true;
        }
        Player* player;
    };

    void OnLogin(Player* player, bool /*firstLogin*/) override
    {
        uint32 playerGUID = player->GetGUIDLow();
        QueryResult result = CharacterDatabase.PQuery("SELECT `GUID`, `increase`, `decrease`, `stat_value` FROM `custom_reforging` WHERE `Owner` = %u", playerGUID);
        if (result)
        {
            do
            {
                uint32 lowGUID = (*result)[0].GetUInt32();
                Item* invItem = player->GetItemByGuid(ObjectGuid(HIGHGUID_ITEM, 0, lowGUID));
                if (invItem)
                    player->_ApplyItemMods(invItem, invItem->GetSlot(), false);
                ReforgeData& data = player->reforgeMap[lowGUID];
                data.increase = (*result)[1].GetUInt32();
                data.decrease = (*result)[2].GetUInt32();
                data.stat_value = (*result)[3].GetInt32();
                if (invItem)
                    player->_ApplyItemMods(invItem, invItem->GetSlot(), true);
                // SendReforgePacket(player, entry, lowGUID);
            } while (result->NextRow());

            // SendReforgePackets(player);
            new SendRefPackLogin(player);
        }
    }

    //void OnLogout(Player* player) override
    //{
    //    if (player->reforgeMap.empty())
    //        return;
    //    for (ReforgeMapType::const_iterator it = player->reforgeMap.begin(); it != player->reforgeMap.end();)
    //    {
    //        ReforgeMapType::const_iterator old_it = it++;
    //        RemoveReforge(player, old_it->first, false);
    //    }
    //}

    void OnSave(Player* player) override
    {
        uint32 lowguid = player->GetGUIDLow();
        SQLTransaction trans = CharacterDatabase.BeginTransaction();
        trans->PAppend("DELETE FROM `custom_reforging` WHERE `Owner` = %u", lowguid);
        if (!player->reforgeMap.empty())
        {
            // Only save items that are in inventory / bank / etc
            std::vector<Item*> items = GetItemList(player);
            for (std::vector<Item*>::const_iterator it = items.begin(); it != items.end(); ++it)
            {
                ReforgeMapType::const_iterator it2 = player->reforgeMap.find((*it)->GetGUIDLow());
                if (it2 == player->reforgeMap.end())
                    continue;

                const ReforgeData& data = it2->second;
                trans->PAppend("REPLACE INTO `custom_reforging` (`GUID`, `increase`, `decrease`, `stat_value`, `Owner`) VALUES (%u, %u, %u, %i, %u)", it2->first, data.increase, data.decrease, data.stat_value, lowguid);
            }
        }

        if (trans->GetSize()) // basically never false
            CharacterDatabase.CommitTransaction(trans);
    }
};

class REFORGER_NPC : public CreatureScript
{
public:
    REFORGER_NPC() : CreatureScript("REFORGER_NPC") { }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_BATTLE, "Select slot of the item to reforge:", 0, Melt(MAIN_MENU, 0));
        for (uint8 slot = EQUIPMENT_SLOT_START; slot < EQUIPMENT_SLOT_END; ++slot)
        {
            if (Item* invItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, slot))
                if (IsReforgable(invItem, player))
                    if (const char* slotname = GetSlotName(slot, player->GetSession()))
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, slotname, 0, Melt(SELECT_STAT_REDUCE, slot));
        }
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, "Remove reforges", 0, Melt(SELECT_RESTORE, 0));
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Update menu", 0, Melt(MAIN_MENU, 0));
        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 melt) override
    {
        player->PlayerTalkClass->ClearMenus();

        uint8 menu, action;
        Unmelt(melt, menu, action);

        switch (menu)
        {
        case MAIN_MENU: OnGossipHello(player, creature); break;
        case SELECT_STAT_REDUCE:
            // action = slot
            if (Item* invItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, action))
            {
                if (IsReforgable(invItem, player))
                {
                    uint32 guidlow = invItem->GetGUIDLow();
                    const ItemTemplate* pProto = invItem->GetTemplate();
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_BATTLE, "Stat to decrease:", sender, melt);
                    for (uint32 i = 0; i < pProto->StatsCount; ++i)
                    {
                        int32 stat_diff = ((int32)floorf((float)pProto->ItemStat[i].ItemStatValue * 0.4f));
                        if (stat_diff > 1)
                            if (const char* stat_name = GetStatName(pProto->ItemStat[i].ItemStatType))
                            {
                                std::ostringstream oss;
                                oss << stat_name << " (" << pProto->ItemStat[i].ItemStatValue << " |cFFDB2222-" << stat_diff << "|r)";
                                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, oss.str(), guidlow, Melt(SELECT_STAT_INCREASE, i));
                            }
                    }
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Back..", 0, Melt(MAIN_MENU, 0));
                    player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
                }
                else
                {
                    player->GetSession()->SendNotification("Invalid item selected");
                    OnGossipHello(player, creature);
                }
            }
            else
            {
                player->GetSession()->SendNotification("Invalid item selected");
                OnGossipHello(player, creature);
            }
            break;
        case SELECT_STAT_INCREASE:
            // sender = item guidlow
            // action = StatsCount id
            {
                Item* invItem = GetEquippedItem(player, sender);
                if (invItem)
                {
                    const ItemTemplate* pProto = invItem->GetTemplate();
                    int32 stat_diff = ((int32)floorf((float)pProto->ItemStat[action].ItemStatValue * 0.4f));

                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_BATTLE, "Stat to increase:", sender, melt);
                    for (uint8 i = 0; i < stat_type_max; ++i)
                    {
                        bool cont = false;
                        for (uint32 j = 0; j < pProto->StatsCount; ++j)
                        {
                            if (statTypes[i] == pProto->ItemStat[j].ItemStatType) // skip existing stats on item
                            {
                                cont = true;
                                break;
                            }
                        }
                        if (cont)
                            continue;
                        if (const char* stat_name = GetStatName(statTypes[i]))
                        {
                            std::ostringstream oss;
                            oss << stat_name << " |cFF3ECB3C+" << stat_diff << "|r";
                            player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_INTERACT_1, oss.str(), sender, Melt(i, (uint8)pProto->ItemStat[action].ItemStatType), "Are you sure you want to reforge\n\n" + pProto->Name1, (pProto->SellPrice < (10 * GOLD) ? (10 * GOLD) : pProto->SellPrice), false);
                        }
                    }
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Back..", 0, Melt(SELECT_STAT_REDUCE, invItem->GetSlot()));
                    player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
                }
                else
                {
                    player->GetSession()->SendNotification("Invalid item selected");
                    OnGossipHello(player, creature);
                }
            }
            break;
        case SELECT_RESTORE:
            {
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_BATTLE, "Select slot to remove reforge from:", sender, melt);
                if (!player->reforgeMap.empty())
                {
                    for (uint8 slot = EQUIPMENT_SLOT_START; slot < EQUIPMENT_SLOT_END; ++slot)
                    {
                        if (Item* invItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, slot))
                            if (player->reforgeMap.find(invItem->GetGUIDLow()) != player->reforgeMap.end())
                                if (const char* slotname = GetSlotName(slot, player->GetSession()))
                                    player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_INTERACT_1, slotname, invItem->GetGUIDLow(), Melt(RESTORE, 0), "Remove reforge from\n\n" + invItem->GetTemplate()->Name1, 0, false);
                    }
                }
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Update menu", sender, melt);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Back..", 0, Melt(MAIN_MENU, 0));
                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
            }
            break;
        case RESTORE:
            // sender = item guidlow
            {
                if (player->GetItemByGuid(ObjectGuid(HIGHGUID_ITEM, 0, sender)))
                {
                    if (!player->reforgeMap.empty() && player->reforgeMap.find(sender) != player->reforgeMap.end())
                        RemoveReforge(player, sender, true);
                }
                OnGossipHello(player, creature);
            }
            break;
        default: // Reforge
            // sender = item guidlow
            // menu = stat type to increase index to statTypes[]
            // action = stat type to decrease
            {
                if (menu < stat_type_max)
                {
                    Item* invItem = GetEquippedItem(player, sender);
                    if (invItem && IsReforgable(invItem, player))
                    {
                        if (player->HasEnoughMoney(invItem->GetTemplate()->SellPrice < (10 * GOLD) ? (10 * GOLD) : invItem->GetTemplate()->SellPrice))
                        {
                            // int32 stat_diff = ((int32)floorf((float)invItem->GetTemplate()->ItemStat[action].ItemStatValue * 0.4f));
                            UpdatePlayerReforgeStats(invItem, player, action, statTypes[menu]); // rewrite this function
                        }
                        else
                        {
                            player->GetSession()->SendNotification("Not enough money");
                        }
                    }
                    else
                    {
                        player->GetSession()->SendNotification("Invalid item selected");
                    }
                }
                OnGossipHello(player, creature);
            }
        }
        return true;
    }

    enum Menus
    {
        MAIN_MENU = 200, // stat_type_max
        SELECT_ITEM,
        SELECT_STAT_REDUCE,
        SELECT_STAT_INCREASE,
        SELECT_RESTORE,
        RESTORE,
        REFORGE,
    };
};

void AddSC_REFORGER_NPC()
{
    new REFORGER_NPC;
    new REFORGE_PLAYER;
}

#undef FOR_REFORGE_ITEMS
