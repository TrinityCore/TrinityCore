#include "Reforging.h"

#include "Define.h"
#include "Player.h"
#include "WorldSession.h"
#include "Item.h"
#include "ItemTemplate.h"
#include "ObjectGuid.h"
#include "WorldPacket.h"
#include "Opcodes.h"
#include "ObjectMgr.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include <vector>
#include <string>

static const bool send_cache_packets = true;    // change player cache?

std::vector<Item*> GetItemList(const Player* player)
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

void RemoveReforge(Player* player, uint32 itemguid, bool update)
{
    if (!itemguid || player->reforgeMap.empty() ||
        player->reforgeMap.find(itemguid) == player->reforgeMap.end())
        return;

    Item* invItem = update ? player->GetItemByGuid(ObjectGuid(HighGuid::Item, 0, itemguid)) : NULL;
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

void SendReforgePackets(Player* player)
{
    if (!send_cache_packets)
        return;

    std::vector<Item*> items = GetItemList(player);
    for (std::vector<Item*>::const_iterator it = items.begin(); it != items.end(); ++it)
        SendReforgePacket(player, (*it)->GetEntry(), (*it)->GetGUID().GetCounter());
}

// Supply lowguid or reforge! (or both)
// Warning, this function may modify player->reforgeMap when lowguid is supplied
void SendReforgePacket(Player* player, uint32 entry, uint32 lowguid, const ReforgeData* reforge)
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
    std::string Name = pProto->Name1;
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
            data << pProto->ItemStat[i].ItemStatValue - reforge->stat_value;
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