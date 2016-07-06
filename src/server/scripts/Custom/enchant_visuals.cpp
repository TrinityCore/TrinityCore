/*
Author: Rochet2 - https://rochet2.github.io/
Source: https://rochet2.github.io/?page=Item_Enchant_Visuals

Updated by ConanHUN

About:
All weapons looted have a 25% chance to have a random enchant *visual*
This is purely visual fun and the visual will be replaced if the weapon is enchanted.

This script is 100% automatic. Just add it to your source and DB table is automatically created

Works with BOOST and ACE
*/

// Do not edit anything below

#include "ScriptMgr.h"
#include "Config.h"
#include <Player.h>

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

static const uint32 ItemEnchants[] = { 3789, 3854, 3273, 3225, 3870, 1899, 2674, 2675, 2671, 2672, 3365, 2673, 2343, 425, 3855, 1894, 1103, 1898, 3345, 1743, 3093, 1900, 3846, 1606, 283, 1, 3265, 2, 3, 3266, 1903, 13, 26, 7, 803, 1896, 2666, 25 };
static const uint32 ItemEnchants_size = (sizeof(ItemEnchants) / sizeof(*ItemEnchants)) - 1;

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

    class EnchantStore : public RWLockable
    {
    public:
        typedef UNORDERED_MAP<uint32, uint32> ItemLowToEnchant;                 // map[itemguid] = {enchant}
        typedef UNORDERED_MAP<uint32, ItemLowToEnchant> PlayerLowToItemLowMap;  // map[playerguid] = {ItemLowToEnchant}

        void LoadPlayerEnchants(uint32 playerLow)
        {
            QueryResult result = CharacterDatabase.PQuery("SELECT iguid, display FROM custom_item_enchant_visuals WHERE iguid IN(SELECT guid FROM item_instance WHERE owner_guid = %u)", playerLow);
            if (!result)
                return;

            ItemLowToEnchant temp;
            do
            {
                uint32 iguid = result->Fetch()[0].GetUInt32();
                uint32 display = result->Fetch()[1].GetUInt32();
                temp[iguid] = display;
            } while (result->NextRow());

            WriteGuard lock(GetLock());
            hashmap[playerLow] = temp;
        }

        void DeletePlayerEnchants(uint32 playerLow)
        {
            WriteGuard lock(GetLock());
            hashmap.erase(playerLow);
        }

        void AddEnchant(uint32 playerLow, uint32 itemLow, uint32 enchant)
        {
            CharacterDatabase.PExecute("REPLACE INTO custom_item_enchant_visuals (iguid, display) VALUES (%u, %u)", itemLow, enchant);

            WriteGuard lock(GetLock());
            hashmap[playerLow][itemLow] = enchant;
        }

        uint32 GetEnchant(uint32 playerLow, uint32 itemLow)
        {
            ReadGuard lock(GetLock());

            PlayerLowToItemLowMap::iterator it = hashmap.find(playerLow);
            if (it == hashmap.end())
                return 0;

            ItemLowToEnchant::iterator it2 = it->second.find(itemLow);
            if (it2 == it->second.end())
                return 0;

            return it2->second;
        }

        void RemoveEnchant(uint32 playerLow, uint32 itemLow)
        {
            {
                WriteGuard lock(GetLock());

                PlayerLowToItemLowMap::iterator it = hashmap.find(playerLow);
                if (it == hashmap.end())
                    return;

                it->second.erase(itemLow);
                if (it->second.empty())
                    hashmap.erase(playerLow);
            }

            CharacterDatabase.PExecute("DELETE FROM custom_item_enchant_visuals WHERE iguid = %u", itemLow);
        }

    private:
        PlayerLowToItemLowMap hashmap;
    };
};

static EnchantStore enchantStore;

uint32 GetItemEnchantVisual(Player* player, Item* item)
{
    if (!player || !item)
        return 0;

    uint32 visual = enchantStore.GetEnchant(player->GetGUID(), item->GetGUID());
    if (!visual)
        return 0;

    if (uint32 enchant = item->GetEnchantmentId(PERM_ENCHANTMENT_SLOT))
    {
        enchantStore.RemoveEnchant(player->GetGUID(), item->GetGUID());
        player->SaveToDB();
        return enchant;
    }

    return visual;
}

void SetRandomEnchantVisual(Player* player, Item* item)
{
    if (!player || !item)
        return;

    const ItemTemplate* temp = item->GetTemplate();
    if (temp->Class != ITEM_CLASS_WEAPON)
        return;

    if (temp->SubClass == ITEM_SUBCLASS_WEAPON_BOW ||
        temp->SubClass == ITEM_SUBCLASS_WEAPON_GUN ||
        temp->SubClass == ITEM_SUBCLASS_WEAPON_obsolete ||
        temp->SubClass == ITEM_SUBCLASS_WEAPON_FIST ||
        temp->SubClass == ITEM_SUBCLASS_WEAPON_THROWN ||
        temp->SubClass == ITEM_SUBCLASS_WEAPON_SPEAR ||
        temp->SubClass == ITEM_SUBCLASS_WEAPON_CROSSBOW ||
        temp->SubClass == ITEM_SUBCLASS_WEAPON_WAND ||
        temp->SubClass == ITEM_SUBCLASS_WEAPON_FISHING_POLE)
        return;

    if (rand_norm() >= (sConfigMgr->GetFloatDefault("Visual.drop.chance", 0.10)))
        return;

    uint32 enchant = ItemEnchants[urand(0, ItemEnchants_size)];
    enchantStore.AddEnchant(player->GetGUID(), item->GetGUID(), enchant);

    player->SaveToDB();
    player->SetVisibleItemSlot(EQUIPMENT_SLOT_MAINHAND, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND));
    player->SetVisibleItemSlot(EQUIPMENT_SLOT_OFFHAND, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND));
}

class item_enchant_visuals : public PlayerScript
{
public:
    item_enchant_visuals() : PlayerScript("item_enchant_visuals")
    {
        // Create DB table on startup if doesnt exist
        const char* sql =
            "CREATE TABLE IF NOT EXISTS `custom_item_enchant_visuals` ("
            "    `iguid` INT(10) UNSIGNED NOT NULL COMMENT 'item DB guid',"
            "    `display` INT(10) UNSIGNED NOT NULL COMMENT 'enchantID',"
            "    PRIMARY KEY (`iguid`)"
            ")"
            "COMMENT='stores the enchant IDs for the visuals'"
            "COLLATE='latin1_swedish_ci'"
            "ENGINE=InnoDB;";
        CharacterDatabase.DirectExecute(sql);

        // Delete unused rows from DB table
        CharacterDatabase.DirectExecute("DELETE FROM custom_item_enchant_visuals WHERE NOT EXISTS(SELECT 1 FROM item_instance WHERE custom_item_enchant_visuals.iguid = item_instance.guid)");
    }

    void OnLogin(Player* player, bool /*firstLogin*/) override
    {
        enchantStore.LoadPlayerEnchants(player->GetGUID());
        player->SetVisibleItemSlot(EQUIPMENT_SLOT_MAINHAND, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND));
        player->SetVisibleItemSlot(EQUIPMENT_SLOT_OFFHAND, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND));
    }

    void OnLogout(Player* player) override
    {
        enchantStore.DeletePlayerEnchants(player->GetGUID());
    }
};

void AddSC_item_enchant_visuals()
{
    new item_enchant_visuals;
}