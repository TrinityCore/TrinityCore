#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"

enum
{
    GC_TOKEN                        = 22726,

    GOSSIP_TEXTID_MENU              = 70000,        //"Hello $N! All these items are obtainable via donation system aswell!"
    GOSSIP_TEXTID_CHOOSE            = 70001,        //"Visit Fufu, Mumu and Zuzu if you need preview of these items!"

    GOSSIP_TEXTID_CONFIRM           = 70002,        //"Are you sure you want to buy selected item?"
    GOSSIP_TEXTID_SUCCESS           = 70003,        //"Trade was successful! Thank you $N!"
    GOSSIP_TEXTID_FAIL              = 70004,        //"Your trade was unsuccessful.Please make sure that following requirements are met:Right amount of GC Tokens, Enough inventory space, Item you want to buy is not unique-type. You can get more GC Tokens through voting system and ingame events. Also you can donate and get this item as a gift! Visit gamingconsortium.org for more info."

    GOSSIP_TEXTID_CONFIRM_NAME      = 70005,        //"Character Name change includes Name change, Gender change and Look change. Are you sure you want to use this customization option?"
    GOSSIP_TEXTID_CONFIRM_RACE      = 70006,        //"Character Race change includes Race change, Name change, Gender change and Look change. Are you sure you want to use this customization option?"
    GOSSIP_TEXTID_CONFIRM_FACTION   = 70007,        //"Character Faction change includes Faction change, Race change, Name change, Gender change and Look change.  Are you sure you want to use this customization option?"        
    GOSSIP_TEXTID_SUCCESS_C         = 70008,        //"Thank you $N. Your customization will be applied on next login. Relog to apply changes."
    GOSSIP_TEXTID_FAIL_C            = 70009,        //"You do not have enough GC Tokens to use this customization option. You can get more GC Tokens through voting system and ingame events. Also you can donate and get this option change as a gift! Visit gamingconsortium.org for more info."
    GOSSIP_TEXTID_CONTACT_GM        = 70010,        //"In order to choose this reward you need to contact a gm.."

    SHOW_MAIN_MENU                  = 500,
    SHOW_CUSTOMIZATION_SUCCESS_MENU = 400,
    SHOW_CUSTOMIZATION_FAIL_MENU    = 300,
    SHOW_FAIL_MENU                  = 200,
    SHOW_SUCCESS_MENU               = 100,

    SHOW_MOUNT_MENU                 = 1000,
    SHOW_PET_MENU                   = 2000,
    SHOW_FUN_ITEM_MENU              = 3000,
    SHOW_CUSTOMIZATION_MENU         = 4000,

    SHOW_CUSTOMIZE_NAME             = 4101,
    SHOW_TRANSFER_CHAR              = 4102,
    SHOW_CUSTOMIZE_RACE             = 4201,
    SHOW_CUSTOMIZE_FACTION          = 4202,
    SHOW_RESTORE_FROM_DB            = 4203,

    HANDLE_VALUE                    = 10000,
};

// Universal Answers
#define ANSWER_BACK "Back"
#define ANSWER_YES "Yes"
#define ANSWER_NO "No"

// Mounts, Token Answers
#define ANSWER_1_0_0_0 "Mounts"
#define ANSWER_1_1_0_0 "500 GC Tokens"
#define ANSWER_1_2_0_0 "400 GC Tokens"
#define ANSWER_1_3_0_0 "300 GC Tokens"
// Mounts, Option Answers
#define ANSWER_1_1_0_1 "X-51 Nether-Rocket" //49285
#define ANSWER_1_1_0_2 "X-51 Nether-Rocket X-TREME" //49286
#define ANSWER_1_1_0_3 "Blazing Hippogryph" //54069
#define ANSWER_1_1_0_4 "X-53 Touring Rocket" //54860
#define ANSWER_1_2_0_1 "Reins of the Swift Spectral Tiger" //49284
#define ANSWER_1_2_0_2 "Big Battle Bear" //49282
#define ANSWER_1_2_0_3 "Wooly White Rhino" //54068
#define ANSWER_1_2_0_4 "Swift Zhevra" //37719
#define ANSWER_1_3_0_1 "Riding Turtle" //23720
#define ANSWER_1_3_0_2 "Reins of the Spectral Tiger" //49283
// Mounts, Positive Answers
#define ANSWER_YES_1_1_0_1 "Yes, I want to purchase X-51 Nether Rocket."
#define ANSWER_YES_1_1_0_2 "Yes, I want to purchase X-51 Nether-Rocket X-TREME."
#define ANSWER_YES_1_1_0_3 "Yes, I want to purchase Blazing Hippogryph."
#define ANSWER_YES_1_1_0_4 "Yes, I want to purchase Touring Rocket."
#define ANSWER_YES_1_2_0_1 "Yes, I want to purchase Reins of the Swift Spectral Tiger."
#define ANSWER_YES_1_2_0_2 "Yes, I want to purchase Big Battle Bear."
#define ANSWER_YES_1_2_0_3 "Yes, I want to purchase Wooly White Rhino."
#define ANSWER_YES_1_2_0_4 "Yes, I want to purchase Swift Zhevra."
#define ANSWER_YES_1_3_0_1 "Yes, I want to purchase Riding Turtle."
#define ANSWER_YES_1_3_0_2 "Yes, I want to purchase Reins of the Spectral Tiger."

// Non-combat Pets, Token Answers
#define ANSWER_2_0_0_0 "Non-combat Pets"
#define ANSWER_2_1_0_0 "200 GC Tokens"
#define ANSWER_2_2_0_0 "100 GC Tokens"
// Non-combat Pets, Option Answers
#define ANSWER_2_1_0_1 "Blue Murloc Egg" //20371
#define ANSWER_2_1_0_2 "Diablo Stone" //13584
#define ANSWER_2_1_0_3 "Frosty's Collar" //39286
#define ANSWER_2_1_0_4 "Lurky's Egg" //30360
#define ANSWER_2_1_0_5 "Mini Thor" //56806
#define ANSWER_2_1_0_6 "Netherwhelp's Collar" //25535
#define ANSWER_2_1_0_7 "Panda Collar" //13583
#define ANSWER_2_1_0_8 "Pink Murloc Egg" //22114
#define ANSWER_2_1_0_9 "Tyrael's Hilt" //39656
#define ANSWER_2_1_1_0 "Zergling Leash" //13582
#define ANSWER_2_2_0_1 "Dragon Kite" //34493
#define ANSWER_2_2_0_2 "Hippogryph Hatchling" //23713
#define ANSWER_2_2_0_3 "Tuskarr Kite" //49287
#define ANSWER_2_2_0_4 "Banana Charm" //32588
#define ANSWER_2_2_0_5 "Gryphon Hatchling" //49662
#define ANSWER_2_2_0_6 "Heavy Murloc Egg" //46802
#define ANSWER_2_2_0_7 "Lil' Phylactery" //49693
#define ANSWER_2_2_0_8 "Lil' XT" //54847
#define ANSWER_2_2_0_9 "Pandaren Monk" //49665
#define ANSWER_2_2_1_0 "Rocket Chicken" //34492
#define ANSWER_2_2_1_1 "Soul-Trader Beacon" //38050
#define ANSWER_2_2_1_2 "Spectral Tiger Cub" //49343
#define ANSWER_2_2_1_3 "Wind Rider Cub" //49663
// Non-combat Pets, Positive Answers
#define ANSWER_YES_2_1_0_1 "Yes, I want to purchase Blue Murloc Egg"
#define ANSWER_YES_2_1_0_2 "Yes, I want to purchase Diablo Stone"
#define ANSWER_YES_2_1_0_3 "Yes, I want to purchase Frosty's Collar"
#define ANSWER_YES_2_1_0_4 "Yes, I want to purchase Lurky's Egg"
#define ANSWER_YES_2_1_0_5 "Yes, I want to purchase Mini Thor"
#define ANSWER_YES_2_1_0_6 "Yes, I want to purchase Netherwhelp's Collar"
#define ANSWER_YES_2_1_0_7 "Yes, I want to purchase Panda Collar"
#define ANSWER_YES_2_1_0_8 "Yes, I want to purchase Pink Murloc Egg"
#define ANSWER_YES_2_1_0_9 "Yes, I want to purchase Tyrael's Hilt"
#define ANSWER_YES_2_1_1_0 "Yes, I want to purchase Zergling Leash"
#define ANSWER_YES_2_2_0_1 "Yes, I want to purchase Dragon Kite"
#define ANSWER_YES_2_2_0_2 "Yes, I want to purchase Hippogryph Hatchling"
#define ANSWER_YES_2_2_0_3 "Yes, I want to purchase Tuskarr Kite"
#define ANSWER_YES_2_2_0_4 "Yes, I want to purchase Banana Charm"
#define ANSWER_YES_2_2_0_5 "Yes, I want to purchase Gryphon Hatchling"
#define ANSWER_YES_2_2_0_6 "Yes, I want to purchase Heavy Murloc Egg"
#define ANSWER_YES_2_2_0_7 "Yes, I want to purchase Lil' Phylactery"
#define ANSWER_YES_2_2_0_8 "Yes, I want to purchase Lil' XT"
#define ANSWER_YES_2_2_0_9 "Yes, I want to purchase Pandaren Monk"
#define ANSWER_YES_2_2_1_0 "Yes, I want to purchase Rocket Chicken"
#define ANSWER_YES_2_2_1_1 "Yes, I want to purchase Soul-Trader Beacon"
#define ANSWER_YES_2_2_1_2 "Yes, I want to purchase Spectral Tiger Cub"
#define ANSWER_YES_2_2_1_3 "Yes, I want to purchase Wind Rider Cub"

// Fun Items, Token Answers
#define ANSWER_3_0_0_0 "Fun Items"
#define ANSWER_3_1_0_0 "200 GC Tokens"
#define ANSWER_3_2_0_0 "100 GC Tokens (Consumable)"
// Fun Items, Option Answers
#define ANSWER_3_1_0_1 "Goblin Weather Machine-Prototype 01-B" //35227
#define ANSWER_3_1_0_2 "Carved Ogre Idol" //49704
#define ANSWER_3_1_0_3 "Perpetual Purple Firework" //49703
#define ANSWER_3_1_0_4 "Fishing Chair" //33223
#define ANSWER_3_1_0_5 "Paper Flying Machine Kit" //34499
#define ANSWER_3_1_0_6 "Picnic Basket" //32566
#define ANSWER_3_1_0_7 "Goblin Gumbo Kettle" //33219
#define ANSWER_3_1_0_8 "Imp in a Ball" //32542
#define ANSWER_3_1_0_9 "Murloc Costume" //33079
#define ANSWER_3_1_1_0 "Epic Purple Shirt" //45037
#define ANSWER_3_2_0_1 "Papa Hummel's Old-Fashioned Pet Biscuit(x250)" //35223
#define ANSWER_3_2_0_2 "Party G.R.E.N.A.D.E.(x250)" //38577
#define ANSWER_3_2_0_3 "Path of Cenarius(x250)" //46779
#define ANSWER_3_2_0_4 "Path of Illidan(x250)" //38233
// Fun Items, Positive Answers
#define ANSWER_YES_3_1_0_1 "Yes, I want to purchase Goblin Weather Machine-Prototype 01-B"
#define ANSWER_YES_3_1_0_2 "Yes, I want to purchase Carved Ogre Idol"
#define ANSWER_YES_3_1_0_3 "Yes, I want to purchase Perpetual Purple Firework"
#define ANSWER_YES_3_1_0_4 "Yes, I want to purchase Fishing Chair"
#define ANSWER_YES_3_1_0_5 "Yes, I want to purchase Paper Flying Machine Kit"
#define ANSWER_YES_3_1_0_6 "Yes, I want to purchase Picnic Basket"
#define ANSWER_YES_3_1_0_7 "Yes, I want to purchase Goblin Gumbo Kettle"
#define ANSWER_YES_3_1_0_8 "Yes, I want to purchase Imp in a Ball"
#define ANSWER_YES_3_1_0_9 "Yes, I want to purchase Murloc Costume"
#define ANSWER_YES_3_1_1_0 "Yes, I want to purchase Epic Purple Shirt"
#define ANSWER_YES_3_2_0_1 "Yes, I want to purchase Papa Hummel's Old-Fashioned Pet Biscuit(x250)"
#define ANSWER_YES_3_2_0_2 "Yes, I want to purchase Party G.R.E.N.A.D.E.(x250)"
#define ANSWER_YES_3_2_0_3 "Yes, I want to purchase Path of Cenarius(x250)"
#define ANSWER_YES_3_2_0_4 "Yes, I want to purchase Path of Illidan(x250)"

// Customization Answers
#define ANSWER_CUSTOMIZE_4_0_0_0 "Character Customization"
#define ANSWER_CUSTOMIZE_4_1_0_0 "500 GC Tokens"
#define ANSWER_CUSTOMIZE_NAME "Appearance and Name change"
#define ANSWER_TRANSFER_CHAR "Char transfer between accounts"
#define ANSWER_CUSTOMIZE_4_2_0_0 "600 GC Tokens"
#define ANSWER_CUSTOMIZE_RACE "Race change"
#define ANSWER_CUSTOMIZE_FACTION "Faction change"
#define ANSWER_RESTORE_FROM_DB "Restore a deleted char"

class npc_gc_vendor : public CreatureScript
{
    public:
        npc_gc_vendor() : CreatureScript("npc_gc_vendor") { }

        struct npc_gc_vendorAI : public ScriptedAI
        {
            npc_gc_vendorAI(Creature* creature) : ScriptedAI(creature)
            {
            }
        };

        bool CheckGCTokens(Player* player, uint32 value)
        {
            if (player->HasItemCount(GC_TOKEN, value, false))
                return true;
            else
                return false;
        }

        bool HandleItemExchange(Player* player, uint32 item, uint32 count, uint32 value)
        {
            if (CheckGCTokens(player, value))
            {
                InventoryResult res = player->CanTakeMoreSimilarItems(item, count);
                if (res == EQUIP_ERR_OK)
                {
                    player->AddItem(item, count);
                    player->DestroyItemCount(GC_TOKEN, value, true, false);
                    return true;
                }
            }
            return false;
        }

        bool HandleCustomizationChange(Player* player, uint32 value, uint32 change)
        {
            switch (change)
            {
                case 1:
                    if (CheckGCTokens(player, value))
                    {
                        player->SetAtLoginFlag(AT_LOGIN_CUSTOMIZE);
                        player->DestroyItemCount(GC_TOKEN, value, true, false);
                        return true;
                    }
                    break;
                case 2:
                    if (CheckGCTokens(player, value))
                    {
                        player->SetAtLoginFlag(AT_LOGIN_CHANGE_RACE);
                        player->DestroyItemCount(GC_TOKEN, value, true, false);
                        return true;
                    }
                    break;
                case 3:
                    if (CheckGCTokens(player, value))
                    {
                        player->SetAtLoginFlag(AT_LOGIN_CHANGE_FACTION);
                        player->DestroyItemCount(GC_TOKEN, value, true, false);
                        return true;
                    }
                    break;
                default:
                    break;
            }
            return false;
        }

        void GossipMenuPreview(Player* player, Creature* creature, uint16 menuId)
        {
            player->PlayerTalkClass->ClearMenus();
            switch (menuId)
            {
                case SHOW_MAIN_MENU:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, ANSWER_1_0_0_0, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + SHOW_MOUNT_MENU);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, ANSWER_2_0_0_0, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + SHOW_PET_MENU);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, ANSWER_3_0_0_0, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + SHOW_FUN_ITEM_MENU);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, ANSWER_CUSTOMIZE_4_0_0_0, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + SHOW_CUSTOMIZATION_MENU);
                    player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_MENU, creature->GetGUID());
                    break;

                case SHOW_MOUNT_MENU:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, ANSWER_1_1_0_0, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + SHOW_MOUNT_MENU);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, ANSWER_1_1_0_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1101);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, ANSWER_1_1_0_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1102);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, ANSWER_1_1_0_3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1103);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, ANSWER_1_1_0_4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1104);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, ANSWER_1_2_0_0, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + SHOW_MOUNT_MENU);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, ANSWER_1_2_0_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1201);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, ANSWER_1_2_0_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1202);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, ANSWER_1_2_0_3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1203);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, ANSWER_1_2_0_4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1204);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, ANSWER_1_3_0_0, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + SHOW_MOUNT_MENU);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, ANSWER_1_3_0_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1301);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, ANSWER_1_3_0_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1302);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_BACK, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + SHOW_MAIN_MENU);
                    player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_CHOOSE, creature->GetGUID());
                    break;

                case SHOW_PET_MENU:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, ANSWER_2_1_0_0, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + SHOW_PET_MENU);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, ANSWER_2_1_0_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2101);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, ANSWER_2_1_0_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2102);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, ANSWER_2_1_0_3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2103);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, ANSWER_2_1_0_4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2104);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, ANSWER_2_1_0_5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2105);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, ANSWER_2_1_0_6, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2106);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, ANSWER_2_1_0_7, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2107);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, ANSWER_2_1_0_8, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2108);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, ANSWER_2_1_0_9, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2109);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, ANSWER_2_1_1_0, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2110);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, ANSWER_2_2_0_0, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + SHOW_PET_MENU);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, ANSWER_2_2_0_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2201);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, ANSWER_2_2_0_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2202);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, ANSWER_2_2_0_3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2203);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, ANSWER_2_2_0_4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2204);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, ANSWER_2_2_0_5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2205);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, ANSWER_2_2_0_6, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2206);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, ANSWER_2_2_0_7, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2207);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, ANSWER_2_2_0_8, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2208);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, ANSWER_2_2_0_9, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2209);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, ANSWER_2_2_1_0, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2210);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, ANSWER_2_2_1_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2211);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, ANSWER_2_2_1_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2212);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, ANSWER_2_2_1_3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2213);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_BACK, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + SHOW_MAIN_MENU);
                    player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_CHOOSE, creature->GetGUID());
                    break;

                case SHOW_FUN_ITEM_MENU:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, ANSWER_3_1_0_0, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + SHOW_FUN_ITEM_MENU);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, ANSWER_3_1_0_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3101);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, ANSWER_3_1_0_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3102);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, ANSWER_3_1_0_3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3103);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, ANSWER_3_1_0_4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3104);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, ANSWER_3_1_0_5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3105);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, ANSWER_3_1_0_6, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3106);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, ANSWER_3_1_0_7, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3107);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, ANSWER_3_1_0_8, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3108);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, ANSWER_3_1_0_9, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3109);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, ANSWER_3_1_1_0, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3110);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, ANSWER_3_2_0_0, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + SHOW_FUN_ITEM_MENU);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, ANSWER_3_2_0_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3201);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, ANSWER_3_2_0_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3202);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, ANSWER_3_2_0_3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3203);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, ANSWER_3_2_0_4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3204);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_BACK, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + SHOW_MAIN_MENU);
                    player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_CHOOSE, creature->GetGUID());
                    break;

                case SHOW_CUSTOMIZATION_MENU:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, ANSWER_CUSTOMIZE_4_2_0_0, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + SHOW_CUSTOMIZATION_MENU);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TABARD, ANSWER_CUSTOMIZE_RACE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4201);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TABARD, ANSWER_CUSTOMIZE_FACTION, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4202);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TABARD, ANSWER_RESTORE_FROM_DB, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4203);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, ANSWER_CUSTOMIZE_4_1_0_0, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + SHOW_CUSTOMIZATION_MENU);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TABARD, ANSWER_CUSTOMIZE_NAME, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4101);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TABARD, ANSWER_TRANSFER_CHAR, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4102);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_BACK, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + SHOW_MAIN_MENU);
                    player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_MENU, creature->GetGUID());
                    break;

                case SHOW_FAIL_MENU:
                    player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_FAIL, creature->GetGUID());
                    break;

                case SHOW_SUCCESS_MENU:
                    player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_SUCCESS, creature->GetGUID());
                    break;

                case SHOW_CUSTOMIZATION_SUCCESS_MENU:
                    player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_SUCCESS_C, creature->GetGUID());
                    break;

                case SHOW_CUSTOMIZATION_FAIL_MENU:
                    player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_FAIL_C, creature->GetGUID());
                    break;

                case SHOW_RESTORE_FROM_DB:
                case SHOW_TRANSFER_CHAR:
                    player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_CONTACT_GM, creature->GetGUID());
                    break;

                default:
                    break;
            }
        }

        void GossipMountConfirm(Player* player, Creature* creature, uint32 mountId)
        {
            player->PlayerTalkClass->ClearMenus();
            switch (mountId)
            {
                case 1101: 
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_YES_1_1_0_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + HANDLE_VALUE + mountId);
                    break;
                case 1102:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_YES_1_1_0_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + HANDLE_VALUE + mountId);
                    break;
                case 1103:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_YES_1_1_0_3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + HANDLE_VALUE + mountId);
                    break;
                case 1104:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_YES_1_1_0_4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + HANDLE_VALUE + mountId);
                    break;
                case 1201:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_YES_1_2_0_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + HANDLE_VALUE + mountId);
                    break;
                case 1202:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_YES_1_2_0_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + HANDLE_VALUE + mountId);
                    break;
                case 1203:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_YES_1_2_0_3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + HANDLE_VALUE + mountId);
                    break;
                case 1204:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_YES_1_2_0_4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + HANDLE_VALUE + mountId);
                    break;
                case 1301:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_YES_1_3_0_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + HANDLE_VALUE + mountId);
                    break;
                case 1302:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_YES_1_3_0_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + HANDLE_VALUE + mountId);
                    break;
                default:
                    break;
            }
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_NO, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + SHOW_MOUNT_MENU);
            player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_CONFIRM, creature->GetGUID());
        }

        void GossipPetConfirm(Player* player, Creature* creature, uint32 petId)
        {
            player->PlayerTalkClass->ClearMenus();
            switch (petId)
            {
                case 2101:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_YES_2_1_0_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + HANDLE_VALUE + petId);
                    break;
                case 2102:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_YES_2_1_0_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + HANDLE_VALUE + petId);
                    break;
                case 2103:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_YES_2_1_0_3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + HANDLE_VALUE + petId);
                    break;
                case 2104:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_YES_2_1_0_4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + HANDLE_VALUE + petId);
                    break;
                case 2105:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_YES_2_1_0_5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + HANDLE_VALUE + petId);
                    break;
                case 2106:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_YES_2_1_0_6, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + HANDLE_VALUE + petId);
                    break;
                case 2107:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_YES_2_1_0_7, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + HANDLE_VALUE + petId);
                    break;
                case 2108:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_YES_2_1_0_8, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + HANDLE_VALUE + petId);
                    break;
                case 2109:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_YES_2_1_0_9, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + HANDLE_VALUE + petId);
                    break;
                case 2110:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_YES_2_1_1_0, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + HANDLE_VALUE + petId);
                    break;
                case 2201:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_YES_2_2_0_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + HANDLE_VALUE + petId);
                    break;
                case 2202:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_YES_2_2_0_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + HANDLE_VALUE + petId);
                    break;
                case 2203:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_YES_2_2_0_3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + HANDLE_VALUE + petId);
                    break;
                case 2204:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_YES_2_2_0_4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + HANDLE_VALUE + petId);
                    break;
                case 2205:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_YES_2_2_0_5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + HANDLE_VALUE + petId);
                    break;
                case 2206:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_YES_2_2_0_6, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + HANDLE_VALUE + petId);
                    break;
                case 2207:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_YES_2_2_0_7, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + HANDLE_VALUE + petId);
                    break;
                case 2208:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_YES_2_2_0_8, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + HANDLE_VALUE + petId);
                    break;
                case 2209:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_YES_2_2_0_9, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + HANDLE_VALUE + petId);
                    break;
                case 2210:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_YES_2_2_1_0, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + HANDLE_VALUE + petId);
                    break;
                case 2211:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_YES_2_2_1_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + HANDLE_VALUE + petId);
                    break;
                case 2212:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_YES_2_2_1_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + HANDLE_VALUE + petId);
                    break;
                case 2213:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_YES_2_2_1_3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + HANDLE_VALUE + petId);
                    break;
                default:
                    break;
            }
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_NO, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + SHOW_PET_MENU);
            player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_CONFIRM, creature->GetGUID());
        }

        void GossipFunItemConfirm(Player* player, Creature* creature, uint32 funItemId)
        {
            player->PlayerTalkClass->ClearMenus();
            switch (funItemId)
            {
                case 3101:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_YES_3_1_0_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + HANDLE_VALUE + funItemId);
                    break;
                case 3102:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_YES_3_1_0_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + HANDLE_VALUE + funItemId);
                    break;
                case 3103:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_YES_3_1_0_3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + HANDLE_VALUE + funItemId);
                    break;
                case 3104:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_YES_3_1_0_4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + HANDLE_VALUE + funItemId);
                    break;
                case 3105:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_YES_3_1_0_5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + HANDLE_VALUE + funItemId);
                    break;
                case 3106:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_YES_3_1_0_6, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + HANDLE_VALUE + funItemId);
                    break;
                case 3107:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_YES_3_1_0_7, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + HANDLE_VALUE + funItemId);
                    break;
                case 3108:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_YES_3_1_0_8, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + HANDLE_VALUE + funItemId);
                    break;
                case 3109:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_YES_3_1_0_9, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + HANDLE_VALUE + funItemId);
                    break;
                case 3110:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_YES_3_1_1_0, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + HANDLE_VALUE + funItemId);
                    break;
                case 3201:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_YES_3_2_0_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + HANDLE_VALUE + funItemId);
                    break;
                case 3202:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_YES_3_2_0_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + HANDLE_VALUE + funItemId);
                    break;
                case 3203:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_YES_3_2_0_3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + HANDLE_VALUE + funItemId);
                    break;
                case 3204:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_YES_3_2_0_4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + HANDLE_VALUE + funItemId);
                    break;
                default:
                    break;
            }
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_NO, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + SHOW_FUN_ITEM_MENU);
            player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_CONFIRM, creature->GetGUID());
        }

        void GossipCustomizationConfirm(Player* player, Creature* creature, uint32 customizationId)
        {
            player->PlayerTalkClass->ClearMenus();
            switch (customizationId)
            {
                case SHOW_CUSTOMIZE_NAME:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_YES, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 14101);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_NO, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4000);
                    player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_CONFIRM_NAME, creature->GetGUID());
                    break;
                case SHOW_CUSTOMIZE_RACE:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_YES, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 14201);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_NO, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4000);
                    player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_CONFIRM_RACE, creature->GetGUID());
                    break;
                case SHOW_CUSTOMIZE_FACTION:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_YES, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 14202);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, ANSWER_NO, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4000);
                    player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_CONFIRM_FACTION, creature->GetGUID());
                    break;
                default:
                    break;
            }
        }

        void GossipMountTrade(Player* player, Creature* creature, uint32 mountId)
        {
            player->PlayerTalkClass->ClearMenus();
            switch (mountId)
            {
                // 500 GC Tokens
                case 11101: // "X-51 Nether-Rocket" //49285
                    if (HandleItemExchange(player, 49285, 1, 500))
                        GossipMenuPreview(player, creature, SHOW_SUCCESS_MENU);
                    else
                        GossipMenuPreview(player, creature, SHOW_FAIL_MENU);
                    break;
                case 11102: // "X-51 Nether-Rocket X-TREME" //49286
                    if (HandleItemExchange(player, 49286, 1, 500))
                        GossipMenuPreview(player, creature, SHOW_SUCCESS_MENU);
                    else
                        GossipMenuPreview(player, creature, SHOW_FAIL_MENU);
                    break;
                case 11103: // "Blazing Hippogryph" //54069
                    if (HandleItemExchange(player, 54069, 1, 500))
                        GossipMenuPreview(player, creature, SHOW_SUCCESS_MENU);
                    else
                        GossipMenuPreview(player, creature, SHOW_FAIL_MENU);
                    break;
                case 11104: // "X-53 Touring Rocket" //54860
                    if (HandleItemExchange(player, 54860, 1, 500))
                        GossipMenuPreview(player, creature, SHOW_SUCCESS_MENU);
                    else GossipMenuPreview(player, creature, SHOW_FAIL_MENU);
                    break;
                // 400 GC Tokens
                case 11201: // "Reins of the Swift Spectral Tiger" //49284
                    if (HandleItemExchange(player, 49284, 1, 400))
                        GossipMenuPreview(player, creature, SHOW_SUCCESS_MENU);
                    else
                        GossipMenuPreview(player, creature, SHOW_FAIL_MENU);
                    break;
                case 11202: // "Big Battle Bear" //49282
                    if (HandleItemExchange(player, 49282, 1, 400))
                        GossipMenuPreview(player, creature, SHOW_SUCCESS_MENU);
                    else
                        GossipMenuPreview(player, creature, SHOW_FAIL_MENU);
                    break;
                case 11203: // "Wooly White Rhino" //54068
                    if (HandleItemExchange(player, 54068, 1, 400))
                        GossipMenuPreview(player, creature, SHOW_SUCCESS_MENU);
                    else
                        GossipMenuPreview(player, creature, SHOW_FAIL_MENU);
                    break;
                case 11204: // "Swift Zhevra" //37719
                    if (HandleItemExchange(player, 37719, 1, 400))
                        GossipMenuPreview(player, creature, SHOW_SUCCESS_MENU);
                    else
                        GossipMenuPreview(player, creature, SHOW_FAIL_MENU);
                    break;
                // 300 GC Tokens
                case 11301: // "Riding Turtle" //23720
                    if (HandleItemExchange(player, 23720, 1, 300))
                        GossipMenuPreview(player, creature, SHOW_SUCCESS_MENU);
                    else
                        GossipMenuPreview(player, creature, SHOW_FAIL_MENU);
                    break;
                case 11302: // "Reins of the Spectral Tiger" //49283
                    if (HandleItemExchange(player, 49283, 1, 300))
                        GossipMenuPreview(player, creature, SHOW_SUCCESS_MENU);
                    else
                        GossipMenuPreview(player, creature, SHOW_FAIL_MENU);
                    break;
                default:
                    break;
            }
        }

        void GossipPetTrade(Player* player, Creature* creature, uint32 petId)
        {
            player->PlayerTalkClass->ClearMenus();
            switch (petId)
            {
                // 200 GC Tokens
                case 12101: // "Blue Murloc Egg" //20371
                    if (HandleItemExchange(player, 20371, 1, 200))
                        GossipMenuPreview(player, creature, SHOW_SUCCESS_MENU);
                    else
                        GossipMenuPreview(player, creature, SHOW_FAIL_MENU);
                    break;
                case 12102: // "Diablo Stone" //13584
                    if (HandleItemExchange(player, 13584, 1, 200))
                        GossipMenuPreview(player, creature, SHOW_SUCCESS_MENU);
                    else
                        GossipMenuPreview(player, creature, SHOW_FAIL_MENU);
                    break;
                case 12103: // "Frosty's Collar" //39286
                    if (HandleItemExchange(player, 39286, 1, 200))
                        GossipMenuPreview(player, creature, SHOW_SUCCESS_MENU);
                    else
                        GossipMenuPreview(player, creature, SHOW_FAIL_MENU);
                    break;
                case 12104: // "Lurky's Egg" //30360
                    if (HandleItemExchange(player, 30360, 1, 200))
                        GossipMenuPreview(player, creature, SHOW_SUCCESS_MENU);
                    else
                        GossipMenuPreview(player, creature, SHOW_FAIL_MENU);
                    break;
                case 12105: // "Mini Thor" //56806
                    if (HandleItemExchange(player, 56806, 1, 200))
                        GossipMenuPreview(player, creature, SHOW_SUCCESS_MENU);
                    else
                        GossipMenuPreview(player, creature, SHOW_FAIL_MENU);
                    break;
                case 12106: // "Netherwhelp's Collar" //25535
                    if (HandleItemExchange(player, 25535, 1, 200))
                        GossipMenuPreview(player, creature, SHOW_SUCCESS_MENU);
                    else
                        GossipMenuPreview(player, creature, SHOW_FAIL_MENU);
                    break;
                case 12107: // "Panda Collar" //13583
                    if (HandleItemExchange(player, 13583, 1, 200))
                        GossipMenuPreview(player, creature, SHOW_SUCCESS_MENU);
                    else
                        GossipMenuPreview(player, creature, SHOW_FAIL_MENU);
                    break;
                case 12108: // "Pink Murloc Egg" //22114
                    if (HandleItemExchange(player, 22114, 1, 200))
                        GossipMenuPreview(player, creature, SHOW_SUCCESS_MENU);
                    else
                        GossipMenuPreview(player, creature, SHOW_FAIL_MENU);
                    break;
                case 12109: // "Tyrael's Hilt" //39656
                    if (HandleItemExchange(player, 39656, 1, 200))
                        GossipMenuPreview(player, creature, SHOW_SUCCESS_MENU);
                    else
                        GossipMenuPreview(player, creature, SHOW_FAIL_MENU);
                    break;
                case 12110: // "Zergling Leash" //13582
                    if (HandleItemExchange(player, 13582, 1, 200))
                        GossipMenuPreview(player, creature, SHOW_SUCCESS_MENU);
                    else
                        GossipMenuPreview(player, creature, SHOW_FAIL_MENU);
                    break;
                    // 100 GC Tokens
                case 12201: // "Dragon Kite" //34493
                    if (HandleItemExchange(player, 34493, 1, 100))
                        GossipMenuPreview(player, creature, SHOW_SUCCESS_MENU);
                    else
                        GossipMenuPreview(player, creature, SHOW_FAIL_MENU);
                    break;
                case 12202: // "Hippogryph Hatchling" //23713
                    if (HandleItemExchange(player, 23713, 1, 100))
                        GossipMenuPreview(player, creature, SHOW_SUCCESS_MENU);
                    else
                        GossipMenuPreview(player, creature, SHOW_FAIL_MENU);
                    break;
                case 12203: // "Tuskarr Kite" //49287
                    if (HandleItemExchange(player, 49287, 1, 100))
                        GossipMenuPreview(player, creature, SHOW_SUCCESS_MENU);
                    else
                        GossipMenuPreview(player, creature, SHOW_FAIL_MENU);
                    break;
                case 12204: // "Banana Charm" //32588
                    if (HandleItemExchange(player, 32588, 1, 100))
                        GossipMenuPreview(player, creature, SHOW_SUCCESS_MENU);
                    else
                        GossipMenuPreview(player, creature, SHOW_FAIL_MENU);
                    break;
                case 12205: // "Gryphon Hatchling" //49662
                    if (HandleItemExchange(player, 49662, 1, 100))
                        GossipMenuPreview(player, creature, SHOW_SUCCESS_MENU);
                    else
                        GossipMenuPreview(player, creature, SHOW_FAIL_MENU);
                    break;
                case 12206: // "Heavy Murloc Egg" //46802
                    if (HandleItemExchange(player, 46802, 1, 100))
                        GossipMenuPreview(player, creature, SHOW_SUCCESS_MENU);
                    else
                        GossipMenuPreview(player, creature, SHOW_FAIL_MENU);
                    break;
                case 12207: // "Lil' Phylactery" //49693
                    if (HandleItemExchange(player, 49693, 1, 100))
                        GossipMenuPreview(player, creature, SHOW_SUCCESS_MENU);
                    else
                        GossipMenuPreview(player, creature, SHOW_FAIL_MENU);
                    break;
                case 12208: // "Lil' XT" //54847
                    if (HandleItemExchange(player, 54847, 1, 100))
                        GossipMenuPreview(player, creature, SHOW_SUCCESS_MENU);
                    else
                        GossipMenuPreview(player, creature, SHOW_FAIL_MENU);
                    break;
                case 12209: // "Pandaren Monk" //49665
                    if (HandleItemExchange(player, 49665, 1, 100))
                        GossipMenuPreview(player, creature, SHOW_SUCCESS_MENU);
                    else
                        GossipMenuPreview(player, creature, SHOW_FAIL_MENU);
                    break;
                case 12210: // "Rocket Chicken" //34492
                    if (HandleItemExchange(player, 34492, 1, 100))
                        GossipMenuPreview(player, creature, SHOW_SUCCESS_MENU);
                    else
                        GossipMenuPreview(player, creature, SHOW_FAIL_MENU);
                    break;
                case 12211: // "Soul-Trader Beacon" //38050
                    if (HandleItemExchange(player, 38050, 1, 100))
                        GossipMenuPreview(player, creature, SHOW_SUCCESS_MENU);
                    else
                        GossipMenuPreview(player, creature, SHOW_FAIL_MENU);
                    break;
                case 12212: // "Spectral Tiger Cub" //49343
                    if (HandleItemExchange(player, 49343, 1, 100))
                        GossipMenuPreview(player, creature, SHOW_SUCCESS_MENU);
                    else
                        GossipMenuPreview(player, creature, SHOW_FAIL_MENU);
                    break;
                case 12213: // "Wind Rider Cub" //49663
                    if (HandleItemExchange(player, 49663, 1, 100))
                        GossipMenuPreview(player, creature, SHOW_SUCCESS_MENU);
                    else
                        GossipMenuPreview(player, creature, SHOW_FAIL_MENU);
                    break;
                default:
                    break;
            }
        }


        void GossipFunItemTrade(Player* player, Creature* creature, uint32 funItemId)
        {
            player->PlayerTalkClass->ClearMenus();
            switch (funItemId)
            {
                // 200 GC Tokens
                case 13101: // "Goblin Weather Machine-Prototype 01-B" //35227
                    if (HandleItemExchange(player, 35227, 1, 200))
                        GossipMenuPreview(player, creature, SHOW_SUCCESS_MENU);
                    else
                        GossipMenuPreview(player, creature, SHOW_FAIL_MENU);
                    break;
                case 13102: // "Carved Ogre Idol" //49704
                    if (HandleItemExchange(player, 49704, 1, 200))
                        GossipMenuPreview(player, creature, SHOW_SUCCESS_MENU);
                    else
                        GossipMenuPreview(player, creature, SHOW_FAIL_MENU);
                    break;
                case 13103: // "Perpetual Purple Firework" //49703
                    if (HandleItemExchange(player, 49703, 1, 200))
                        GossipMenuPreview(player, creature, SHOW_SUCCESS_MENU);
                    else
                        GossipMenuPreview(player, creature, SHOW_FAIL_MENU);
                    break;
                case 13104: // "Fishing Chair" //33223
                    if (HandleItemExchange(player, 33223, 1, 200))
                        GossipMenuPreview(player, creature, SHOW_SUCCESS_MENU);
                    else
                        GossipMenuPreview(player, creature, SHOW_FAIL_MENU);
                    break;
                case 13105: //"Paper Flying Machine Kit" //34499
                    if (HandleItemExchange(player, 34499, 1, 200))
                        GossipMenuPreview(player, creature, SHOW_SUCCESS_MENU);
                    else
                        GossipMenuPreview(player, creature, SHOW_FAIL_MENU);
                    break;
                case 13106: // "Picnic Basket" //32566
                    if (HandleItemExchange(player, 32566, 1, 200))
                        GossipMenuPreview(player, creature, SHOW_SUCCESS_MENU);
                    else
                        GossipMenuPreview(player, creature, SHOW_FAIL_MENU);
                    break;
                case 13107: // "Goblin Gumbo Kettle" //33219
                    if (HandleItemExchange(player, 33219, 1, 200))
                        GossipMenuPreview(player, creature, SHOW_SUCCESS_MENU);
                    else
                        GossipMenuPreview(player, creature, SHOW_FAIL_MENU);
                    break;
                case 13108: // "Imp in a Ball" //32542
                    if (HandleItemExchange(player, 32542, 1, 200))
                        GossipMenuPreview(player, creature, SHOW_SUCCESS_MENU);
                    else
                        GossipMenuPreview(player, creature, SHOW_FAIL_MENU);
                    break;
                case 13109: // "Murloc Costume" //33079
                    if (HandleItemExchange(player, 33079, 1, 200))
                        GossipMenuPreview(player, creature, SHOW_SUCCESS_MENU);
                    else
                        GossipMenuPreview(player, creature, SHOW_FAIL_MENU);
                    break;
                case 13110: // "Epic Purple Shirt" //45037
                    if (HandleItemExchange(player, 45037, 1, 200))
                        GossipMenuPreview(player, creature, SHOW_SUCCESS_MENU);
                    else
                        GossipMenuPreview(player, creature, SHOW_FAIL_MENU);
                    break;
                // 100 GC Tokens (Consumables) 
                case 13201: // "Papa Hummel's Old-Fashioned Pet Biscuit(x250)" //35223
                    if (HandleItemExchange(player, 35223, 250, 100))
                        GossipMenuPreview(player, creature, SHOW_SUCCESS_MENU);
                    else
                        GossipMenuPreview(player, creature, SHOW_FAIL_MENU);
                    break;
                case 13202: // "Party G.R.E.N.A.D.E.(x250)" //38577
                    if (HandleItemExchange(player, 38577, 250, 100))
                        GossipMenuPreview(player, creature, SHOW_SUCCESS_MENU);
                    else
                        GossipMenuPreview(player, creature, SHOW_FAIL_MENU);
                    break;
                case 13203: // "Path of Cenarius(x250)" //46779
                    if (HandleItemExchange(player, 46779, 250, 100))
                        GossipMenuPreview(player, creature, SHOW_SUCCESS_MENU);
                    else
                        GossipMenuPreview(player, creature, SHOW_FAIL_MENU);
                    break;
                case 13204: // "Path of Illidan(x250)" //38233
                    if (HandleItemExchange(player, 38233, 250, 100))
                        GossipMenuPreview(player, creature, SHOW_SUCCESS_MENU);
                    else
                        GossipMenuPreview(player, creature, SHOW_FAIL_MENU);
                    break;
            }
        }

        bool OnGossipHello(Player* player, Creature* creature)
        {
            GossipMenuPreview(player, creature, SHOW_MAIN_MENU);
            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
        {
            player->PlayerTalkClass->ClearMenus();
            switch (action - GOSSIP_ACTION_INFO_DEF)
            {
                // Mounts Gossip
                case 1000:
                    GossipMenuPreview(player, creature, SHOW_MOUNT_MENU);
                    break;
                case 1101: case 1102: case 1103: case 1104:
                case 1201: case 1202: case 1203: case 1204:
                case 1301: case 1302:
                    GossipMountConfirm(player, creature, action - GOSSIP_ACTION_INFO_DEF);
                    break;

                // Non-combat Pets Gossip
                case 2000:
                    GossipMenuPreview(player, creature, SHOW_PET_MENU);
                    break;
                case 2101: case 2102: case 2103: case 2104: case 2105: case 2106: case 2107: case 2108: case 2109: case 2110:
                case 2201: case 2202: case 2203: case 2204: case 2205: case 2206: case 2207: case 2208: case 2209: case 2210: case 2211: case 2212: case 2213:
                    GossipPetConfirm(player, creature, action - GOSSIP_ACTION_INFO_DEF);
                    break;

                // Fun Items Gossip
                case 3000:
                    GossipMenuPreview(player, creature, SHOW_FUN_ITEM_MENU);
                    break;
                case 3101: case 3102: case 3103: case 3104: case 3105: case 3106: case 3107: case 3108: case 3109: case 3110:
                case 3201: case 3202: case 3203: case 3204:
                    GossipFunItemConfirm(player, creature, action - GOSSIP_ACTION_INFO_DEF);
                    break;

                // Customization Gossip
                case 4000:
                    GossipMenuPreview(player, creature, SHOW_CUSTOMIZATION_MENU);
                    break;
                case 4101:  // Name Change
                    GossipCustomizationConfirm(player, creature, SHOW_CUSTOMIZE_NAME);
                    break;
                case 4102:  // Transfer char between accounts
                    GossipMenuPreview(player, creature, SHOW_TRANSFER_CHAR);
                    break;
                case 4201:  // Race Change
                    GossipCustomizationConfirm(player, creature, SHOW_CUSTOMIZE_RACE);
                    break;
                case 4202:  // Faction Change
                    GossipCustomizationConfirm(player, creature, SHOW_CUSTOMIZE_FACTION);
                    break;
                case 4203:  // Restore from db
                    GossipMenuPreview(player, creature, SHOW_RESTORE_FROM_DB);
                    break;

                // Mounts Trade Handling
                case 11101: case 11102: case 11103: case 11104:
                case 11201: case 11202: case 11203: case 11204:
                case 11301: case 11302:
                    GossipMountTrade(player, creature, action - GOSSIP_ACTION_INFO_DEF);
                    break;

                // Non-combat Pets Trade Handling
                case 12101: case 12102: case 12103: case 12104: case 12105: case 12106: case 12107: case 12108: case 12109: case 12110:
                case 12201: case 12202: case 12203: case 12204: case 12205: case 12206: case 12207: case 12208: case 12209: case 12210: case 12211: case 12212: case 12213:
                    GossipPetTrade(player, creature, action - GOSSIP_ACTION_INFO_DEF);
                    break;

                // Fun Items Trade Handling
                case 13101: case 13102: case 13103: case 13104: case 13105: case 13106: case 13107: case 13108: case 13109: case 13110:
                case 13201: case 13202: case 13203: case 13204:
                    GossipFunItemTrade(player, creature, action - GOSSIP_ACTION_INFO_DEF);
                    break;

                // Customization Handling
                case 14101:    // Name Change Handling
                    if (HandleCustomizationChange(player, 500, 1))
                        GossipMenuPreview(player, creature, SHOW_CUSTOMIZATION_SUCCESS_MENU);
                    else
                        GossipMenuPreview(player, creature, SHOW_CUSTOMIZATION_FAIL_MENU);
                    break;
                case 14201: // Race Change Handling
                    if (HandleCustomizationChange(player, 600, 2))
                        GossipMenuPreview(player, creature, SHOW_CUSTOMIZATION_SUCCESS_MENU);
                    else
                        GossipMenuPreview(player, creature, SHOW_CUSTOMIZATION_FAIL_MENU);
                    break;
                case 14202: // Faction Change Handling
                    if (HandleCustomizationChange(player, 600, 3))
                        GossipMenuPreview(player, creature, SHOW_CUSTOMIZATION_SUCCESS_MENU);
                    else
                        GossipMenuPreview(player, creature, SHOW_CUSTOMIZATION_FAIL_MENU);
                    break;

                // Main menu
                case 500:
                    GossipMenuPreview(player, creature, SHOW_MAIN_MENU);
                    break;

                default:
                    break;
            }
            return true;
        }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_gc_vendorAI(creature);
        }
};

void AddSC_custom()
{
    new npc_gc_vendor();
}
