/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

/* ScriptData
SDName: Guards
SD%Complete: 100
SDComment: All Guard gossip data, quite some npc_text-id's still missing, adding constantly as new id's are known. CombatAI should be organized better for future.
SDCategory: Guards
EndScriptData */

/* ContentData
guard_azuremyst
guard_bluffwatcher
guard_contested
guard_darnassus
guard_dunmorogh
guard_durotar
guard_elwynnforest
guard_eversong
guard_exodar
guard_ironforge
guard_mulgore
guard_orgrimmar
guard_shattrath
guard_shattrath_aldor
guard_shattrath_scryer
guard_silvermoon
guard_stormwind
guard_teldrassil
guard_tirisfal
guard_undercity
EndContentData */

#include "precompiled.h"
#include "guard_ai.h"

//script spesific action
#define GOSSIP_ACTION_TAVERN                  101
#define GOSSIP_ACTION_GEMMERCHANT             102
#define GOSSIP_ACTION_MANALOOM                103

//script spesific sender
#define GOSSIP_SENDER_SEC_GEMMERCHANT         101
#define GOSSIP_SENDER_SEC_AUCTIONHOUSE        102

//script spesific gossip text
#define GOSSIP_TEXT_TAVERN                    "Worlds End Tavern"
#define GOSSIP_TEXT_BANKSCYERS                "Scyers bank"
#define GOSSIP_TEXT_BANKALDOR                 "Aldor Bank"
#define GOSSIP_TEXT_INNSCYERS                 "Scyers Inn"
#define GOSSIP_TEXT_INNALDOR                  "Aldor Inn"
#define GOSSIP_TEXT_STABLESCYERS              "Scyers Stable"
#define GOSSIP_TEXT_STABLEALDOR               "Aldor Stable"
#define GOSSIP_TEXT_BATTLEMASTERALLIANCE      "Alliance Battlemasters"
#define GOSSIP_TEXT_BATTLEMASTERHORDE         "Horde Battlemasters"
#define GOSSIP_TEXT_BATTLEMASTERARENA         "Arena Battlemasters"
#define GOSSIP_TEXT_MANALOOM                  "Mana Loom"
#define GOSSIP_TEXT_ALCHEMYLAB                "Alchemy Lab"
#define GOSSIP_TEXT_GEMMERCHANT               "Gem Merchant"
#define GOSSIP_TEXT_GEMSCYERS                 "Scyers Gem Merchant"
#define GOSSIP_TEXT_GEMALDOR                  "Aldor Gem Merchant"

#define GOSSIP_TEXT_AH_SILVERMOON_1           "Western Auction House"
#define GOSSIP_TEXT_AH_SILVERMOON_2           "Royal Exchange Auction House"

#define GOSSIP_TEXT_INN_SILVERMOON_1          "Silvermoon City Inn"
#define GOSSIP_TEXT_INN_SILVERMOON_2          "Wayfarer's Rest tavern"

//common used for guards in main cities
void DoReplyToTextEmote(Creature *_Creature,uint32 em)
{
    switch(em)
    {
        case TEXTEMOTE_KISS:    _Creature->HandleEmoteCommand(EMOTE_ONESHOT_BOW); break;
        case TEXTEMOTE_WAVE:    _Creature->HandleEmoteCommand(EMOTE_ONESHOT_WAVE); break;
        case TEXTEMOTE_SALUTE:  _Creature->HandleEmoteCommand(EMOTE_ONESHOT_SALUTE); break;
        case TEXTEMOTE_SHY:     _Creature->HandleEmoteCommand(EMOTE_ONESHOT_FLEX); break;
        case TEXTEMOTE_RUDE:
        case TEXTEMOTE_CHICKEN: _Creature->HandleEmoteCommand(EMOTE_ONESHOT_POINT); break;
    }
}

/*******************************************************
 * guard_azuremyst start
 *******************************************************/

bool GossipHello_guard_azuremyst(Player *player, Creature *_Creature)
{
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BANK            , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_HIPPOGRYPH      , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_GUILDMASTER     , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_INN             , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_STABLEMASTER    , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_CLASSTRAINER    , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_PROFTRAINER     , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
    player->SEND_GOSSIP_MENU(10066,_Creature->GetGUID());
    return true;
}

void SendDefaultMenu_guard_azuremyst(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Bank
            player->SEND_POI(-3918.95, -11544.7, 7, 6, 0, "Bank");
            player->SEND_GOSSIP_MENU(10067,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Hippogryph Master
            player->SEND_POI(-4057.15, -11788.6, 7, 6, 0, "Stephanos");
            player->SEND_GOSSIP_MENU(10071,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Guild master
            player->SEND_POI(-4092.43, -11626.6, 7, 6, 0, "Funaam");
            player->SEND_GOSSIP_MENU(10073,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Inn
            player->SEND_POI(-4129.43, -12469, 7, 6, 0, "Caregiver Chellan");
            player->SEND_GOSSIP_MENU(10074,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Stable Master
            player->SEND_POI(-4146.42, -12492.7, 7, 6, 0, "Esbina");
            player->SEND_GOSSIP_MENU(10075,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //Class trainer
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_DRUID               , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_HUNTER              , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_MAGE                , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_PALADIN             , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_PRIEST              , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_SHAMAN              , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 6);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_WARRIOR             , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 7);
            player->SEND_GOSSIP_MENU(10076,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Profession trainer
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ALCHEMY             , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BLACKSMITHING       , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_COOKING             , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ENCHANTING          , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ENGINEERING         , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_FIRSTAID            , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 6);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_FISHING             , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 7);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_HERBALISM           , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 8);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_JEWELCRAFTING       , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 9);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_LEATHERWORKING      , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 10);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_MINING              , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 11);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_SKINNING            , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 12);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_TAILORING           , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 13);
            player->SEND_GOSSIP_MENU(10087,_Creature->GetGUID());
            break;
    }
}

void SendClassTrainerMenu_guard_azuremyst(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Druid
            player->SEND_POI(-4274.81, -11495.3, 7, 6, 0, "Shalannius");
            player->SEND_GOSSIP_MENU(10077,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Hunter
            player->SEND_POI(-4203.65, -12526.5, 7, 6, 0, "Acteon");
            player->SEND_GOSSIP_MENU(10078,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Mage
            player->SEND_POI(-4149.62, -12530.1, 7, 6, 0, "Semid");
            player->SEND_GOSSIP_MENU(10081,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Paladin
            player->SEND_POI(-4138.98, -12468.5, 7, 6, 0, "Tullas");
            player->SEND_GOSSIP_MENU(10083,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Priest
            player->SEND_POI(-4131.66, -12478.6, 7, 6, 0, "Guvan");
            player->SEND_GOSSIP_MENU(10084,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //Shaman
            player->SEND_POI(-4162.33, -12456.1, 7, 6, 0, "Tuluun");
            player->SEND_GOSSIP_MENU(10085,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Warrior
            player->SEND_POI(-4165.05, -12536.4, 7, 6, 0, "Ruada");
            player->SEND_GOSSIP_MENU(10086,_Creature->GetGUID());
            break;
    }
}

void SendProfTrainerMenu_guard_azuremyst(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Alchemy
            player->SEND_POI(-4191.15, -12470, 7, 6, 0, "Daedal");
            player->SEND_GOSSIP_MENU(10088,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Blacksmithing
            player->SEND_POI(-4726.29, -12387, 7, 6, 0, "Blacksmith Calypso");
            player->SEND_GOSSIP_MENU(10089,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Cooking
            player->SEND_POI(-4710.87, -12400.6, 7, 6, 0, "'Cookie' McWeaksauce");
            player->SEND_GOSSIP_MENU(10090,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Enchanting
            player->SEND_POI(-3882.85, -11496.7, 7, 6, 0, "Nahogg");
            player->SEND_GOSSIP_MENU(10091,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Engineering
            player->SEND_POI(-4157.57, -12470.2, 7, 6, 0, "Artificer Daelo");
            player->SEND_GOSSIP_MENU(10092,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //First Aid
            player->SEND_POI(-4199.11, -12469.9, 7, 6, 0, "Anchorite Fateema");
            player->SEND_GOSSIP_MENU(10093,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Fishing
            player->SEND_POI(-4266.38, -12985.1, 7, 6, 0, "Diktynna");
            player->SEND_GOSSIP_MENU(10094,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 8:                    //Herbalism
            player->SEND_GOSSIP_MENU(10095,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 9:                    //Jewelcrafting
            player->SEND_POI(-3781.55, -11541.8, 7, 6, 0, "Farii");
            player->SEND_GOSSIP_MENU(10096,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 10:                   //Leatherworking
            player->SEND_POI(-3442.68, -12322.2, 7, 6, 0, "Moordo");
            player->SEND_GOSSIP_MENU(10098,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 11:                   //Mining
            player->SEND_POI(-4179.89, -12493.1, 7, 6, 0, "Dulvi");
            player->SEND_GOSSIP_MENU(10097,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 12:                   //Skinning
            player->SEND_POI(-3431.17, -12316.5, 7, 6, 0, "Gurf");
            player->SEND_GOSSIP_MENU(10098,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 13:                   //Tailoring
            player->SEND_POI(-4711.54, -12386.7, 7, 6, 0, "Erin Kelly");
            player->SEND_GOSSIP_MENU(10099,_Creature->GetGUID());
            break;
    }
}

bool GossipSelect_guard_azuremyst(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    switch (sender)
    {
        case GOSSIP_SENDER_MAIN:            SendDefaultMenu_guard_azuremyst(player, _Creature, action); break;
        case GOSSIP_SENDER_SEC_CLASSTRAIN:  SendClassTrainerMenu_guard_azuremyst(player, _Creature, action); break;
        case GOSSIP_SENDER_SEC_PROFTRAIN:   SendProfTrainerMenu_guard_azuremyst(player, _Creature, action); break;
    }
    return true;
}

/*******************************************************
 * guard_azuremyst end
 *******************************************************/

CreatureAI* GetAI_guard_azuremyst(Creature *_Creature)
{
    return new guardAI (_Creature);
}

/*******************************************************
 * guard_bluffwatcher start
 *******************************************************/

bool GossipHello_guard_bluffwatcher(Player *player, Creature *_Creature)
{
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BANK         , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_WINDRIDER    , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_GUILDMASTER  , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_INN          , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_MAILBOX      , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_AUCTIONHOUSE , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_WEAPONMASTER , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_STABLEMASTER , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 8);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BATTLEMASTER , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 9);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_CLASSTRAINER , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 10);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_PROFTRAINER  , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);
    player->SEND_GOSSIP_MENU(3543,_Creature->GetGUID());
    return true;
}

void SendDefaultMenu_guard_bluffwatcher(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Bank
            player->SEND_POI(-1257.8, 24.14, 7, 6, 0, "Thunder Bluff Bank");
            player->SEND_GOSSIP_MENU(1292,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Wind master
            player->SEND_POI(-1196.43, 28.26, 7, 6, 0, "Wind Rider Roost");
            player->SEND_GOSSIP_MENU(1293,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Guild master
            player->SEND_POI(-1296.5, 127.57, 7, 6, 0, "Thunder Bluff Civic Information");
            player->SEND_GOSSIP_MENU(1291,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Inn
            player->SEND_POI(-1296, 39.7, 7, 6, 0, "Thunder Bluff Inn");
            player->SEND_GOSSIP_MENU(3153,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Mailbox
            player->SEND_POI(-1263.59, 44.36, 7, 6, 0, "Thunder Bluff Mailbox");
            player->SEND_GOSSIP_MENU(3154,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //Auction House
            player->SEND_POI(1381.77, -4371.16, 7, 6, 0, GOSSIP_TEXT_AUCTIONHOUSE);
            player->SEND_GOSSIP_MENU(3155,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Weapon master
            player->SEND_POI(-1282.31, 89.56, 7, 6, 0, "Ansekhwa");
            player->SEND_GOSSIP_MENU(4520,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 8:                    //Stable master
            player->SEND_POI(-1270.19, 48.84, 7, 6, 0, "Bulrug");
            player->SEND_GOSSIP_MENU(5977,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 9:                    //battlemaster
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ALTERACVALLEY       , GOSSIP_SENDER_SEC_BATTLEINFO, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ARATHIBASIN         , GOSSIP_SENDER_SEC_BATTLEINFO, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_WARSONGULCH         , GOSSIP_SENDER_SEC_BATTLEINFO, GOSSIP_ACTION_INFO_DEF + 3);
            player->SEND_GOSSIP_MENU(7527,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 10:                   //Class trainer
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_DRUID               , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_HUNTER              , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_MAGE                , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_PRIEST              , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_SHAMAN              , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_WARRIOR             , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 6);
            player->SEND_GOSSIP_MENU(3542,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 11:                   //Profession trainer
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ALCHEMY             , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BLACKSMITHING       , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_COOKING             , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ENCHANTING          , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_FIRSTAID            , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_FISHING             , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 6);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_HERBALISM           , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 7);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_LEATHERWORKING      , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 8);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_MINING              , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 9);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_SKINNING            , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 10);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_TAILORING           , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 11);
            player->SEND_GOSSIP_MENU(3541,_Creature->GetGUID());
            break;
    }
}

void SendBattleMasterMenu_guard_bluffwatcher(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //AV
            player->SEND_POI(-1387.82, -97.55, 7, 6, 0, "Taim Ragetotem");
            player->SEND_GOSSIP_MENU(7522,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //AB
            player->SEND_POI(-997, 214.12, 7, 6, 0, "Martin Lindsey");
            player->SEND_GOSSIP_MENU(7648,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //WSG
            player->SEND_POI(-1384.94, -75.91, 7, 6, 0, "Kergul Bloodaxe");
            player->SEND_GOSSIP_MENU(7523,_Creature->GetGUID());
            break;
    }
}

void SendClassTrainerMenu_guard_bluffwatcher(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Druid
            player->SEND_POI(-1054.47, -285, 7, 6, 0, "Hall of Elders");
            player->SEND_GOSSIP_MENU(1294,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Hunter
            player->SEND_POI(-1416.32, -114.28, 7, 6, 0, "Hunter's Hall");
            player->SEND_GOSSIP_MENU(1295,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Mage
            player->SEND_POI(-1061.2, 195.5, 7, 6, 0, "Pools of Vision");
            player->SEND_GOSSIP_MENU(1296,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Priest
            player->SEND_POI(-1061.2, 195.5, 7, 6, 0, "Pools of Vision");
            player->SEND_GOSSIP_MENU(1297,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Shaman
            player->SEND_POI(-989.54, 278.25, 7, 6, 0, "Hall of Spirits");
            player->SEND_GOSSIP_MENU(1298,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //Warrior
            player->SEND_POI(-1416.32, -114.28, 7, 6, 0, "Hunter's Hall");
            player->SEND_GOSSIP_MENU(1299,_Creature->GetGUID());
            break;
    }
}

void SendProfTrainerMenu_guard_bluffwatcher(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Alchemy
            player->SEND_POI(-1085.56, 27.29, 7, 6, 0, "Bena's Alchemy");
            player->SEND_GOSSIP_MENU(1332,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Blacksmithing
            player->SEND_POI(-1239.75, 104.88, 7, 6, 0, "Karn's Smithy");
            player->SEND_GOSSIP_MENU(1333,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Cooking
            player->SEND_POI(-1214.5, -21.23, 7, 6, 0, "Aska's Kitchen");
            player->SEND_GOSSIP_MENU(1334,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Enchanting
            player->SEND_POI(-1112.65, 48.26, 7, 6, 0, "Dawnstrider Enchanters");
            player->SEND_GOSSIP_MENU(1335,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //First Aid
            player->SEND_POI(-996.58, 200.5, 7, 6, 0, "Spiritual Healing");
            player->SEND_GOSSIP_MENU(1336,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //Fishing
            player->SEND_POI(-1169.35, -68.87, 7, 6, 0, "Mountaintop Bait & Tackle");
            player->SEND_GOSSIP_MENU(1337,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Herbalism
            player->SEND_POI(-1137.7, -1.51, 7, 6, 0, "Holistic Herbalism");
            player->SEND_GOSSIP_MENU(1338,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 8:                    //Leatherworking
            player->SEND_POI(-1156.22, 66.86, 7, 6, 0, "Thunder Bluff Armorers");
            player->SEND_GOSSIP_MENU(1339,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 9:                    //Mining
            player->SEND_POI(-1249.17, 155, 7, 6, 0, "Stonehoof Geology");
            player->SEND_GOSSIP_MENU(1340,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 10:                   //Skinning
            player->SEND_POI(-1148.56, 51.18, 7, 6, 0, "Mooranta");
            player->SEND_GOSSIP_MENU(1343,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 11:                   //Tailoring
            player->SEND_POI(-1156.22, 66.86, 7, 6, 0, "Thunder Bluff Armorers");
            player->SEND_GOSSIP_MENU(1341,_Creature->GetGUID());
            break;
    }
}

bool GossipSelect_guard_bluffwatcher(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    switch (sender)
    {
        case GOSSIP_SENDER_MAIN:            SendDefaultMenu_guard_bluffwatcher(player, _Creature, action); break;
        case GOSSIP_SENDER_SEC_CLASSTRAIN:  SendClassTrainerMenu_guard_bluffwatcher(player, _Creature, action); break;
        case GOSSIP_SENDER_SEC_PROFTRAIN:   SendProfTrainerMenu_guard_bluffwatcher(player, _Creature, action); break;
        case GOSSIP_SENDER_SEC_BATTLEINFO:  SendBattleMasterMenu_guard_bluffwatcher(player, _Creature, action); break;
    }
    return true;
}

/*******************************************************
 * guard_bluffwatcher end
 *******************************************************/

CreatureAI* GetAI_guard_bluffwatcher(Creature *_Creature)
{
    return new guardAI (_Creature);
}

/*******************************************************
 * guard_contested start
 *******************************************************/

CreatureAI* GetAI_guard_contested(Creature *_Creature)
{
     return new guardAI (_Creature);
}
/*******************************************************
 * guard_contested end
 *******************************************************/

/*******************************************************
 * guard_darnassus start
 *******************************************************/

bool GossipHello_guard_darnassus(Player *player, Creature *_Creature)
{
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_AUCTIONHOUSE   , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BANK           , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_HIPPOGRYPH     , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_GUILDMASTER    , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_INN            , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_MAILBOX        , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_STABLEMASTER   , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_WEAPONMASTER   , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 8);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BATTLEMASTER   , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 9);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_CLASSTRAINER   , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 10);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_PROFTRAINER    , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);
    player->SEND_GOSSIP_MENU(3016, _Creature->GetGUID());
    return true;
}

void SendDefaultMenu_guard_darnassus(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Auction house
            player->SEND_POI(9861.23, 2334.55, 7, 6, 0, "Darnassus Auction House");
            player->SEND_GOSSIP_MENU(3833, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Bank
            player->SEND_POI(9938.45, 2512.35, 7, 6, 0, "Darnassus Bank");
            player->SEND_GOSSIP_MENU(3017, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Wind master
            player->SEND_POI(9945.65, 2618.94, 7, 6, 0, "Rut'theran Village");
            player->SEND_GOSSIP_MENU(3018, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Guild master
            player->SEND_POI(10076.40, 2199.59, 7, 6, 0, "Darnassus Guild Master");
            player->SEND_GOSSIP_MENU(3019, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Inn
            player->SEND_POI(10133.29, 2222.52, 7, 6, 0, "Darnassus Inn");
            player->SEND_GOSSIP_MENU(3020, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //Mailbox
            player->SEND_POI(9942.17, 2495.48, 7, 6, 0, "Darnassus Mailbox");
            player->SEND_GOSSIP_MENU(3021, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Stable master
            player->SEND_POI(10167.20, 2522.66, 7, 6, 0, "Alassin");
            player->SEND_GOSSIP_MENU(5980, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 8:                    //Weapon trainer
            player->SEND_POI(9907.11, 2329.70, 7, 6, 0, "Ilyenia Moonfire");
            player->SEND_GOSSIP_MENU(4517, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 9:                    //Battlemaster
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ALTERACVALLEY   , GOSSIP_SENDER_SEC_BATTLEINFO, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ARATHIBASIN     , GOSSIP_SENDER_SEC_BATTLEINFO, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_WARSONGULCH     , GOSSIP_SENDER_SEC_BATTLEINFO, GOSSIP_ACTION_INFO_DEF + 3);
            player->SEND_GOSSIP_MENU(7519, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 10:                   //Class trainer
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_DRUID           , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_HUNTER          , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_PRIEST          , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ROGUE           , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_WARRIOR         , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            player->SEND_GOSSIP_MENU(4264, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 11:                   //Profession trainer
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ALCHEMY         , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_COOKING         , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ENCHANTING      , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_FIRSTAID        , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_FISHING         , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_HERBALISM       , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 6);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_LEATHERWORKING  , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 7);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_SKINNING        , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 8);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_TAILORING       , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 9);
            player->SEND_GOSSIP_MENU(4273, _Creature->GetGUID());
            break;
    }
}

void SendBattleMasterMenu_guard_darnassus(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //AV
            player->SEND_POI(9923.61, 2327.43, 7, 6, 0, "Brogun Stoneshield");
            player->SEND_GOSSIP_MENU(7518, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //AB
            player->SEND_POI(9977.37, 2324.39, 7, 6, 0, "Keras Wolfheart");
            player->SEND_GOSSIP_MENU(7651,  _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //WSG
            player->SEND_POI(9979.84, 2315.79, 7, 6, 0, "Aethalas");
            player->SEND_GOSSIP_MENU(7482, _Creature->GetGUID());
            break;
    }
}

void SendClassTrainerMenu_guard_darnassus(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Druid
            player->SEND_POI(10186, 2570.46, 7, 6, 0, "Darnassus Druid Trainer");
            player->SEND_GOSSIP_MENU(3024, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Hunter
            player->SEND_POI(10177.29, 2511.10, 7, 6, 0, "Darnassus Hunter Trainer");
            player->SEND_GOSSIP_MENU(3023, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Priest
            player->SEND_POI(9659.12, 2524.88, 7, 6, 0, "Temple of the Moon");
            player->SEND_GOSSIP_MENU(3025, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Rogue
            player->SEND_POI(10122, 2599.12, 7, 6, 0, "Darnassus Rogue Trainer");
            player->SEND_GOSSIP_MENU(3026, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Warrior
            player->SEND_POI(9951.91, 2280.38, 7, 6, 0, "Warrior's Terrace");
            player->SEND_GOSSIP_MENU(3033, _Creature->GetGUID());
            break;
    }
}

void SendProfTrainerMenu_guard_darnassus(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Alchemy
            player->SEND_POI(10075.90, 2356.76, 7, 6, 0, "Darnassus Alchemy Trainer");
            player->SEND_GOSSIP_MENU(3035, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Cooking
            player->SEND_POI(10088.59, 2419.21, 7, 6, 0, "Darnassus Cooking Trainer");
            player->SEND_GOSSIP_MENU(3036, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Enchanting
            player->SEND_POI(10146.09, 2313.42, 7, 6, 0, "Darnassus Enchanting Trainer");
            player->SEND_GOSSIP_MENU(3337, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //First Aid
            player->SEND_POI(10150.09, 2390.43, 7, 6, 0, "Darnassus First Aid Trainer");
            player->SEND_GOSSIP_MENU(3037, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Fishing
            player->SEND_POI(9836.20, 2432.17, 7, 6, 0, "Darnassus Fishing Trainer");
            player->SEND_GOSSIP_MENU(3038, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //Herbalism
            player->SEND_POI(9757.17, 2430.16, 7, 6, 0, "Darnassus Herbalism Trainer");
            player->SEND_GOSSIP_MENU(3039, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Leatherworking
            player->SEND_POI(10086.59, 2255.77, 7, 6, 0, "Darnassus Leatherworking Trainer");
            player->SEND_GOSSIP_MENU(3040, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 8:                    //Skinning
            player->SEND_POI(10081.40, 2257.18, 7, 6, 0, "Darnassus Skinning Trainer");
            player->SEND_GOSSIP_MENU(3042, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 9:                    //Tailoring
            player->SEND_POI(10079.70, 2268.19, 7, 6, 0, "Darnassus Tailor");
            player->SEND_GOSSIP_MENU(3044, _Creature->GetGUID());
            break;
    }
}

bool GossipSelect_guard_darnassus(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    switch (sender)
    {
        case GOSSIP_SENDER_MAIN:            SendDefaultMenu_guard_darnassus(player, _Creature, action); break;
        case GOSSIP_SENDER_SEC_CLASSTRAIN:  SendClassTrainerMenu_guard_darnassus(player, _Creature, action); break;
        case GOSSIP_SENDER_SEC_PROFTRAIN:   SendProfTrainerMenu_guard_darnassus(player, _Creature, action); break;
        case GOSSIP_SENDER_SEC_BATTLEINFO:  SendBattleMasterMenu_guard_darnassus(player, _Creature, action); break;
    }
    return true;
}

/*******************************************************
 * guard_darnassus end
 *******************************************************/

CreatureAI* GetAI_guard_darnassus(Creature *_Creature)
{
    return new guardAI (_Creature);
}

/*******************************************************
 * guard_dunmorogh start
 *******************************************************/

bool GossipHello_guard_dunmorogh(Player *player, Creature *_Creature)
{
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BANK             , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_HIPPOGRYPH       , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_GUILDMASTER      , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_INN              , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_STABLEMASTER     , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_CLASSTRAINER     , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_PROFTRAINER      , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
    player->SEND_GOSSIP_MENU(4287,_Creature->GetGUID());

    return true;
}

void SendDefaultMenu_guard_dunmorogh(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Bank
            player->SEND_GOSSIP_MENU(4288,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Gryphon master
            player->SEND_GOSSIP_MENU(4289,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Guild master
            player->SEND_GOSSIP_MENU(4290,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Inn
            player->SEND_POI(-5582.66, -525.89, 7, 6, 0, "Thunderbrew Distillery");
            player->SEND_GOSSIP_MENU(4291,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Stable Master
            player->SEND_POI(-5604, -509.58, 7, 6, 0, "Shelby Stoneflint");
            player->SEND_GOSSIP_MENU(5985,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //Class trainer
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_HUNTER               , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_MAGE                 , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_PALADIN              , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_PRIEST               , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ROGUE                , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_WARLOCK              , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 6);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_WARRIOR              , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 7);
            player->SEND_GOSSIP_MENU(4292,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Profession trainer
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ALCHEMY              , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BLACKSMITHING        , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_COOKING              , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ENCHANTING           , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ENGINEERING          , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_FIRSTAID             , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 6);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_FISHING              , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 7);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_HERBALISM            , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 8);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_LEATHERWORKING       , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 9);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_MINING               , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 10);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_SKINNING             , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 11);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_TAILORING            , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 12);
            player->SEND_GOSSIP_MENU(4300,_Creature->GetGUID());
            break;
    }
}

void SendClassTrainerMenu_guard_dunmorogh(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Hunter
            player->SEND_POI(-5618.29, -454.25, 7, 6, 0, "Grif Wildheart");
            player->SEND_GOSSIP_MENU(4293,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Mage
            player->SEND_POI(-5585.6, -539.99, 7, 6, 0, "Magis Sparkmantle");
            player->SEND_GOSSIP_MENU(4294,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Paladin
            player->SEND_POI(-5585.6, -539.99, 7, 6, 0, "Azar Stronghammer");
            player->SEND_GOSSIP_MENU(4295,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Priest
            player->SEND_POI(-5591.74, -525.61, 7, 6, 0, "Maxan Anvol");
            player->SEND_GOSSIP_MENU(4296,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Rogue
            player->SEND_POI(-5602.75, -542.4, 7, 6, 0, "Hogral Bakkan");
            player->SEND_GOSSIP_MENU(4297,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //Warlock
            player->SEND_POI(-5641.97, -523.76, 7, 6, 0, "Gimrizz Shadowcog");
            player->SEND_GOSSIP_MENU(4298,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Warrior
            player->SEND_POI(-5604.79, -529.38, 7, 6, 0, "Granis Swiftaxe");
            player->SEND_GOSSIP_MENU(4299,_Creature->GetGUID());
            break;
    }
}

void SendProfTrainerMenu_guard_dunmorogh(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Alchemy
            player->SEND_GOSSIP_MENU(4301,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Blacksmithing
            player->SEND_POI(-5584.72, -428.41, 7, 6, 0, "Tognus Flintfire");
            player->SEND_GOSSIP_MENU(4302,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Cooking
            player->SEND_POI(-5596.85, -541.43, 7, 6, 0, "Gremlock Pilsnor");
            player->SEND_GOSSIP_MENU(4303,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Enchanting
            player->SEND_GOSSIP_MENU(4304,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Engineering
            player->SEND_POI(-5531, -666.53, 7, 6, 0, "Bronk Guzzlegear");
            player->SEND_GOSSIP_MENU(4305,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //First Aid
            player->SEND_POI(-5603.67, -523.57, 7, 6, 0, "Thamner Pol");
            player->SEND_GOSSIP_MENU(4306,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Fishing
            player->SEND_POI(-5199.9, 58.58, 7, 6, 0, "Paxton Ganter");
            player->SEND_GOSSIP_MENU(4307,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 8:                    //Herbalism
            player->SEND_GOSSIP_MENU(4308,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 9:                    //Leatherworking
            player->SEND_GOSSIP_MENU(4310,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 10:                   //Mining
            player->SEND_POI(-5531, -666.53, 7, 6, 0, "Yarr Hamerstone");
            player->SEND_GOSSIP_MENU(4311,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 11:                   //Skinning
            player->SEND_GOSSIP_MENU(4312,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 12:                   //Tailoring
            player->SEND_GOSSIP_MENU(4313,_Creature->GetGUID());
            break;
    }
}

bool GossipSelect_guard_dunmorogh(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    switch (sender)
    {
        case GOSSIP_SENDER_MAIN:            SendDefaultMenu_guard_dunmorogh(player, _Creature, action); break;
        case GOSSIP_SENDER_SEC_CLASSTRAIN:  SendClassTrainerMenu_guard_dunmorogh(player, _Creature, action); break;
        case GOSSIP_SENDER_SEC_PROFTRAIN:   SendProfTrainerMenu_guard_dunmorogh(player, _Creature, action); break;
    }
    return true;
}

/*******************************************************
 * guard_dunmorogh end
 *******************************************************/

CreatureAI* GetAI_guard_dunmorogh(Creature *_Creature)
{
    return new guardAI (_Creature);
}

/*******************************************************
 * guard_durotar start
 *******************************************************/

bool GossipHello_guard_durotar(Player *player, Creature *_Creature)
{
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BANK         , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_WINDRIDER    , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_INN          , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_STABLEMASTER , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_CLASSTRAINER , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_PROFTRAINER  , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
    player->SEND_GOSSIP_MENU(4037,_Creature->GetGUID());
    return true;
}

void SendDefaultMenu_guard_durotar(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Bank
            player->SEND_GOSSIP_MENU(4032,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Wind rider
            player->SEND_GOSSIP_MENU(4033,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Inn
            player->SEND_POI(338.7, -4688.87, 7, 6, 0, "Razor Hill Inn");
            player->SEND_GOSSIP_MENU(4034,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Stable master
            player->SEND_POI(330.31, -4710.66, 7, 6, 0, "Shoja'my");
            player->SEND_GOSSIP_MENU(5973,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Class trainer
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_HUNTER              , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_MAGE                , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_PRIEST              , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ROGUE               , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_SHAMAN              , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_WARLOCK             , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 6);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_WARRIOR             , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 7);
            player->SEND_GOSSIP_MENU(4035,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //Profession trainer
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ALCHEMY             , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BLACKSMITHING       , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_COOKING             , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ENCHANTING          , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ENGINEERING         , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_FIRSTAID            , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 6);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_FISHING             , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 7);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_HERBALISM           , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 8);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_LEATHERWORKING      , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 9);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_MINING              , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 10);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_SKINNING            , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 11);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_TAILORING           , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 12);
            player->SEND_GOSSIP_MENU(4036,_Creature->GetGUID());
            break;
    }
}

void SendClassTrainerMenu_guard_durotar(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Hunter
            player->SEND_POI(276, -4706.72, 7, 6, 0, "Thotar");
            player->SEND_GOSSIP_MENU(4013,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Mage
            player->SEND_POI(-839.33, -4935.6, 7, 6, 0, "Un'Thuwa");
            player->SEND_GOSSIP_MENU(4014,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Priest
            player->SEND_POI(296.22, -4828.1, 7, 6, 0, "Tai'jin");
            player->SEND_GOSSIP_MENU(4015,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Rogue
            player->SEND_POI(265.76, -4709, 7, 6, 0, "Kaplak");
            player->SEND_GOSSIP_MENU(4016,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Shaman
            player->SEND_POI(307.79, -4836.97, 7, 6, 0, "Swart");
            player->SEND_GOSSIP_MENU(4017,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //Warlock
            player->SEND_POI(355.88, -4836.45, 7, 6, 0, "Dhugru Gorelust");
            player->SEND_GOSSIP_MENU(4018,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Warrior
            player->SEND_POI(312.3, -4824.66, 7, 6, 0, "Tarshaw Jaggedscar");
            player->SEND_GOSSIP_MENU(4019,_Creature->GetGUID());
            break;
    }
}

void SendProfTrainerMenu_guard_durotar(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Alchemy
            player->SEND_POI(-800.25, -4894.33, 7, 6, 0, "Miao'zan");
            player->SEND_GOSSIP_MENU(4020,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Blacksmithing
            player->SEND_POI(373.24, -4716.45, 7, 6, 0, "Dwukk");
            player->SEND_GOSSIP_MENU(4021,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Cooking
            player->SEND_GOSSIP_MENU(4022,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Enchanting
            player->SEND_GOSSIP_MENU(4023,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Engineering
            player->SEND_POI(368.95, -4723.95, 7, 6, 0, "Mukdrak");
            player->SEND_GOSSIP_MENU(4024,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //First Aid
            player->SEND_POI(327.17, -4825.62, 7, 6, 0, "Rawrk");
            player->SEND_GOSSIP_MENU(4025,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Fishing
            player->SEND_POI(-1065.48, -4777.43, 7, 6, 0, "Lau'Tiki");
            player->SEND_GOSSIP_MENU(4026,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 8:                    //Herbalism
            player->SEND_POI(-836.25, -4896.89, 7, 6, 0, "Mishiki");
            player->SEND_GOSSIP_MENU(4027,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 9:                    //Leatherworking
            player->SEND_GOSSIP_MENU(4028,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 10:                   //Mining
            player->SEND_POI(366.94, -4705, 7, 6, 0, "Krunn");
            player->SEND_GOSSIP_MENU(4029,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 11:                   //Skinning
            player->SEND_GOSSIP_MENU(4030,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 12:                   //Tailoring
            player->SEND_GOSSIP_MENU(4031,_Creature->GetGUID());
            break;
    }
}

bool GossipSelect_guard_durotar(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    switch (sender)
    {
        case GOSSIP_SENDER_MAIN:            SendDefaultMenu_guard_durotar(player, _Creature, action); break;
        case GOSSIP_SENDER_SEC_CLASSTRAIN:  SendClassTrainerMenu_guard_durotar(player, _Creature, action); break;
        case GOSSIP_SENDER_SEC_PROFTRAIN:   SendProfTrainerMenu_guard_durotar(player, _Creature, action); break;
    }
    return true;
}

/*******************************************************
 * guard_durotar end
 *******************************************************/

CreatureAI* GetAI_guard_durotar(Creature *_Creature)
{
    return new guardAI (_Creature);
}

/*******************************************************
 * guard_elwynnforest start
 *******************************************************/

bool GossipHello_guard_elwynnforest(Player *player, Creature *_Creature)
{
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BANK          , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_GRYPHON       , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_GUILDMASTER   , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_INN           , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_STABLEMASTER  , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_CLASSTRAINER  , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_PROFTRAINER   , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
    player->SEND_GOSSIP_MENU(933,_Creature->GetGUID());
    return true;
}

void SendDefaultMenu_guard_elwynnforest(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Bank
            player->SEND_GOSSIP_MENU(4260,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Gryphon master
            player->SEND_GOSSIP_MENU(4261,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Guild master
            player->SEND_GOSSIP_MENU(4262,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Inn
            player->SEND_POI(-9459.34, 42.08, 7, 6, 0, "Lion's Pride Inn");
            player->SEND_GOSSIP_MENU(4263,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Stable Master
            player->SEND_POI(-9466.62, 45.87, 7, 6, 0, "Erma");
            player->SEND_GOSSIP_MENU(5983,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //Class trainer
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_DRUID               , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_HUNTER              , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_MAGE                , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_PALADIN             , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_PRIEST              , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ROGUE               , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 6);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_WARLOCK             , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 7);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_WARRIOR             , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 8);
            player->SEND_GOSSIP_MENU(4264,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Profession trainer
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ALCHEMY             , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BLACKSMITHING       , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_COOKING             , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ENCHANTING          , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ENGINEERING         , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_FIRSTAID            , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 6);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_FISHING             , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 7);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_HERBALISM           , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 8);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_LEATHERWORKING      , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 9);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_MINING              , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 10);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_SKINNING            , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 11);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_TAILORING           , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 12);
            player->SEND_GOSSIP_MENU(4273,_Creature->GetGUID());
            break;
    }
}

void SendClassTrainerMenu_guard_elwynnforest(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Druid
            player->SEND_GOSSIP_MENU(4265,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Hunter
            player->SEND_GOSSIP_MENU(4266,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Mage
            player->SEND_POI(-9471.12, 33.44, 7, 6, 0, "Zaldimar Wefhellt");
            player->SEND_GOSSIP_MENU(4268,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Paladin
            player->SEND_POI(-9469, 108.05, 7, 6, 0, "Brother Wilhelm");
            player->SEND_GOSSIP_MENU(4269,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Priest
            player->SEND_POI(-9461.07, 32.6, 7, 6, 0, "Priestess Josetta");
            player->SEND_GOSSIP_MENU(4267,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //Rogue
            player->SEND_POI(-9465.13, 13.29, 7, 6, 0, "Keryn Sylvius");
            player->SEND_GOSSIP_MENU(4270,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Warlock
            player->SEND_POI(-9473.21, -4.08, 7, 6, 0, "Maximillian Crowe");
            player->SEND_GOSSIP_MENU(4272,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 8:                    //Warrior
            player->SEND_POI(-9461.82, 109.50, 7, 6, 0, "Lyria Du Lac");
            player->SEND_GOSSIP_MENU(4271,_Creature->GetGUID());
            break;
    }
}

void SendProfTrainerMenu_guard_elwynnforest(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Alchemy
            player->SEND_POI(-9057.04, 153.63, 7, 6, 0, "Alchemist Mallory");
            player->SEND_GOSSIP_MENU(4274,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Blacksmithing
            player->SEND_POI(-9456.58, 87.90, 7, 6, 0, "Smith Argus");
            player->SEND_GOSSIP_MENU(4275,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Cooking
            player->SEND_POI(-9467.54, -3.16, 7, 6, 0, "Tomas");
            player->SEND_GOSSIP_MENU(4276,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Enchanting
            player->SEND_GOSSIP_MENU(4277,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Engineering
            player->SEND_GOSSIP_MENU(4278,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //First Aid
            player->SEND_POI(-9456.82, 30.49, 7, 6, 0, "Michelle Belle");
            player->SEND_GOSSIP_MENU(4279,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Fishing
            player->SEND_POI(-9386.54, -118.73, 7, 6, 0, "Lee Brown");
            player->SEND_GOSSIP_MENU(4280,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 8:                    //Herbalism
            player->SEND_POI(-9060.70, 149.23, 7, 6, 0, "Herbalist Pomeroy");
            player->SEND_GOSSIP_MENU(4281,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 9:                    //Leatherworking
            player->SEND_POI(-9376.12, -75.23, 7, 6, 0, "Adele Fielder");
            player->SEND_GOSSIP_MENU(4282,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 10:                   //Mining
            player->SEND_GOSSIP_MENU(4283,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 11:                   //Skinning
            player->SEND_POI(-9536.91, -1212.76, 7, 6, 0, "Helene Peltskinner");
            player->SEND_GOSSIP_MENU(4284,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 12:                   //Tailoring
            player->SEND_POI(-9376.12, -75.23, 7, 6, 0, "Eldrin");
            player->SEND_GOSSIP_MENU(4285,_Creature->GetGUID());
            break;
    }
}

bool GossipSelect_guard_elwynnforest(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    switch (sender)
    {
        case GOSSIP_SENDER_MAIN:            SendDefaultMenu_guard_elwynnforest(player, _Creature, action); break;
        case GOSSIP_SENDER_SEC_CLASSTRAIN:  SendClassTrainerMenu_guard_elwynnforest(player, _Creature, action); break;
        case GOSSIP_SENDER_SEC_PROFTRAIN:   SendProfTrainerMenu_guard_elwynnforest(player, _Creature, action); break;
    }
    return true;
}

/*******************************************************
 * guard_elwynnforest end
 *******************************************************/

CreatureAI* GetAI_guard_elwynnforest(Creature *_Creature)
{
    return new guardAI (_Creature);
}

/*******************************************************
 * guard_eversong start
 *******************************************************/

bool GossipHello_guard_eversong(Player *player, Creature *_Creature)
{
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BATHANDLER    , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_GUILDMASTER   , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_INN           , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_STABLEMASTER  , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_CLASSTRAINER  , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_PROFTRAINER   , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
    player->SEND_GOSSIP_MENU(10180,_Creature->GetGUID());
    return true;
}

void SendDefaultMenu_guard_eversong(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Bat Handler
            player->SEND_POI(9371.93, -7164.80, 7, 6, 0, "Skymistress Gloaming");
            player->SEND_GOSSIP_MENU(10181,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Guild master
            player->SEND_GOSSIP_MENU(10182,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Inn
            player->SEND_POI(9483.74, -6844.58, 7, 6, 0, "Delaniel's inn");
            player->SEND_GOSSIP_MENU(10183,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Stable Master
            player->SEND_POI(9489.62, -6829.93, 7, 6, 0, "Anathos");
            player->SEND_GOSSIP_MENU(10184,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Class trainer
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_DRUID               , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_HUNTER              , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_MAGE                , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_PALADIN             , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_PRIEST              , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ROGUE               , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 6);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_WARLOCK             , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 7);
            player->SEND_GOSSIP_MENU(10180,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //Profession trainer
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ALCHEMY             , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BLACKSMITHING       , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_COOKING             , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ENGINEERING         , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_FIRSTAID            , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_FISHING             , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 6);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_HERBALISM           , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 7);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_JEWELCRAFTING       , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 8);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_LEATHERWORKING      , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 9);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_MINING              , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 10);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_SKINNING            , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 11);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_TAILORING           , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 12);
            player->SEND_GOSSIP_MENU(10180,_Creature->GetGUID());
            break;
    }
}

void SendClassTrainerMenu_guard_eversong(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Druid
            player->SEND_GOSSIP_MENU(10185,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Hunter
            player->SEND_POI(9527.44, -6865.25, 7, 6, 0, "Hannovia");
            player->SEND_GOSSIP_MENU(10186,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Mage
            player->SEND_POI(9464.24, -6855.52, 7, 6, 0, "Garridel");
            player->SEND_GOSSIP_MENU(10187,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Paladin
            player->SEND_POI(9517.61, -6871.04, 7, 6, 0, "Noellene");
            player->SEND_GOSSIP_MENU(10189,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Priest
            player->SEND_POI(9467.39, -6845.72, 7, 6, 0, "Ponaris");
            player->SEND_GOSSIP_MENU(10190,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //Rogue
            player->SEND_POI(9533.67, -6877.39, 7, 6, 0, "Tannaria");
            player->SEND_GOSSIP_MENU(10191,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Warlock
            player->SEND_POI(9468.99, -6865.60, 7, 6, 0, "Celoenus");
            player->SEND_GOSSIP_MENU(10192,_Creature->GetGUID());
            break;
    }
}

void SendProfTrainerMenu_guard_eversong(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Alchemy
            player->SEND_POI(8659.90, -6368.12, 7, 6, 0, "Arcanist Sheynathren");
            player->SEND_GOSSIP_MENU(10193,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Blacksmithing
            player->SEND_POI(8984.21, -7419.21, 7, 6, 0, "Arathel Sunforge");
            player->SEND_GOSSIP_MENU(10194,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Cooking
            player->SEND_POI(9494.04, -6881.51, 7, 6, 0, "Quarelestra");
            player->SEND_GOSSIP_MENU(10195,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Engineering
            player->SEND_GOSSIP_MENU(10197,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //First Aid
            player->SEND_POI(9479.46, -6879.16, 7, 6, 0, "Kanaria");
            player->SEND_GOSSIP_MENU(10198,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //Fishing
            player->SEND_GOSSIP_MENU(10199,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Herbalism
            player->SEND_POI(8678.92, -6329.09, 7, 6, 0, "Botanist Tyniarrel");
            player->SEND_GOSSIP_MENU(10200,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 8:                    //Jewelcrafting
            player->SEND_POI(9484.32, -6874.98, 7, 6, 0, "Aleinia");
            player->SEND_GOSSIP_MENU(10203,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 9:                    //Leatherworking
            player->SEND_POI(9362.04, -7130.33, 7, 6, 0, "Sathein");
            player->SEND_GOSSIP_MENU(10204,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 10:                   //Mining
            player->SEND_GOSSIP_MENU(10205,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 11:                   //Skinning
            player->SEND_POI(9362.04, -7130.33, 7, 6, 0, "Mathreyn");
            player->SEND_GOSSIP_MENU(10206,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 12:                   //Tailoring
            player->SEND_POI(8680.36, -6327.51, 7, 6, 0, "Sempstress Ambershine");
            player->SEND_GOSSIP_MENU(10207,_Creature->GetGUID());
            break;
    }
}

bool GossipSelect_guard_eversong(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    switch (sender)
    {
        case GOSSIP_SENDER_MAIN:            SendDefaultMenu_guard_eversong(player, _Creature, action); break;
        case GOSSIP_SENDER_SEC_CLASSTRAIN:  SendClassTrainerMenu_guard_eversong(player, _Creature, action); break;
        case GOSSIP_SENDER_SEC_PROFTRAIN:   SendProfTrainerMenu_guard_eversong(player, _Creature, action); break;
    }
    return true;
}

/*******************************************************
 * guard_eversong end
 *******************************************************/

CreatureAI* GetAI_guard_eversong(Creature *_Creature)
{
    return new guardAI (_Creature);
}

/*******************************************************
 * guard_exodar start
 *******************************************************/

bool GossipHello_guard_exodar(Player *player, Creature *_Creature)
{
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_AUCTIONHOUSE   , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BANK           , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_GUILDMASTER    , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_HIPPOGRYPH     , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_INN            , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_MAILBOX        , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_STABLEMASTER   , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_WEAPONMASTER   , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 8);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BATTLEMASTER   , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 9);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_CLASSTRAINER   , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 10);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_PROFTRAINER    , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);
    player->SEND_GOSSIP_MENU(9551, _Creature->GetGUID());
    return true;
}

void SendDefaultMenu_guard_exodar(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Auction house
            player->SEND_POI(-4023.6, -11739.3, 7, 6, 0, "Exodar Auction House");
            player->SEND_GOSSIP_MENU(9528, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Bank
            player->SEND_POI(-3923.89, -11544.5, 7, 6, 0, "Exodar Bank");
            player->SEND_GOSSIP_MENU(9529, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Guild master
            player->SEND_POI(-4092.57, -11626.5, 7, 6, 0, "Exodar Guild Master");
            player->SEND_GOSSIP_MENU(9539, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Hippogryph master
            player->SEND_POI(-4060.46, -11787.1, 7, 6, 0, "Exodar Hippogryph Master");
            player->SEND_GOSSIP_MENU(9530, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Inn
            player->SEND_POI(-3741.87, -11695.1, 7, 6, 0, "Exodar Inn");
            player->SEND_GOSSIP_MENU(9545, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //Mailbox
            player->SEND_POI(-3972.5, -11696.0, 7, 6, 0, "Mailbox");
            player->SEND_GOSSIP_MENU(10254, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Stable master
            player->SEND_POI(-3786.5, -11702.5, 7, 6, 0, "Stable Master Arthaid");
            player->SEND_GOSSIP_MENU(9558, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 8:                    //Weapon trainer
            player->SEND_POI(-4215.68, -11628.9, 7, 6, 0, "Weapon Master Handiir");
            player->SEND_GOSSIP_MENU(9565, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 9:                    //Battlemaster
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ALTERACVALLEY       , GOSSIP_SENDER_SEC_BATTLEINFO, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ARATHIBASIN         , GOSSIP_SENDER_SEC_BATTLEINFO, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ARENA               , GOSSIP_SENDER_SEC_BATTLEINFO, GOSSIP_ACTION_INFO_DEF + 3);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_EYEOFTHESTORM       , GOSSIP_SENDER_SEC_BATTLEINFO, GOSSIP_ACTION_INFO_DEF + 4);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_WARSONGULCH         , GOSSIP_SENDER_SEC_BATTLEINFO, GOSSIP_ACTION_INFO_DEF + 5);
            player->SEND_GOSSIP_MENU(9531, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 10:                   //Class trainer
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_DRUID               , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_HUNTER              , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_MAGE                , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_PALADIN             , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_PRIEST              , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_SHAMAN              , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 6);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_WARRIOR             , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 7);
            player->SEND_GOSSIP_MENU(9533, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 11:                   //Profession trainer
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ALCHEMY             , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BLACKSMITHING       , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_COOKING             , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ENCHANTING          , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ENGINEERING         , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_FIRSTAID            , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 6);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_FISHING             , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 7);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_JEWELCRAFTING       , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 8);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_HERBALISM           , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 9);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_LEATHERWORKING      , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 10);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_MINING              , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 11);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_SKINNING            , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 12);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_TAILORING           , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 13);
            player->SEND_GOSSIP_MENU(9555, _Creature->GetGUID());
            break;
    }
}

void SendBattleMasterMenu_guard_exodar(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //AV
            player->SEND_POI(-3978.1, -11357, 7, 6, 0, "Alterac Valley Battlemaster");
            player->SEND_GOSSIP_MENU(9531, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //AB
            player->SEND_POI(-3998.9, -11345.2, 7, 6, 0, "Arathi Basin Battlemaster");
            player->SEND_GOSSIP_MENU(9531,  _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //A
            player->SEND_POI(-3759.27, -11695.63, 7, 6, 0, "Miglik Blotstrom");
            player->SEND_GOSSIP_MENU(10223, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //EOS
            player->SEND_POI(-3978.1, -11357, 7, 6, 0, "Eye Of The Storm Battlemaster");
            player->SEND_GOSSIP_MENU(9531, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //WSG
            player->SEND_POI(-3977.5, -11381.2, 7, 6, 0, "Warsong Gulch Battlemaster");
            player->SEND_GOSSIP_MENU(9531, _Creature->GetGUID());
            break;
    }
}

void SendClassTrainerMenu_guard_exodar(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Druid
            player->SEND_POI(-4276.0, -11495, 7, 6, 0, "Exodar Druid Trainer");
            player->SEND_GOSSIP_MENU(9534, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Hunter
            player->SEND_POI(-4210.6, -11575.2, 7, 6, 0, "Exodar Hunter Trainer");
            player->SEND_GOSSIP_MENU(9544, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Mage
            player->SEND_POI(-4057.32, -11556.5, 7, 6, 0, "Exodar Mage Trainer");
            player->SEND_GOSSIP_MENU(9550, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Paladin
            player->SEND_POI(-4191.2, -11470.4, 7, 6, 0, "Exodar Paladin Trainer");
            player->SEND_GOSSIP_MENU(9553, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Priest
            player->SEND_POI(-3969.63, -11482.8, 7, 6, 0, "Exodar Priest Trainer");
            player->SEND_GOSSIP_MENU(9554, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //Shaman
            player->SEND_POI(-3805.5, -11380.7, 7, 6, 0, "Exodar Shaman Trainer");
            player->SEND_GOSSIP_MENU(9556, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Warrior
            player->SEND_POI(-4189.43, -11653.7, 7, 6, 0, "Exodar Warrior Trainer");
            player->SEND_GOSSIP_MENU(9562, _Creature->GetGUID());
            break;
    }
}

void SendProfTrainerMenu_guard_exodar(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Alchemy
            player->SEND_POI(-4040.6, -11364.5, 7, 6, 0, "Exodar Alchemy Trainer");
            player->SEND_GOSSIP_MENU(9527, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Blacksmithing
            player->SEND_POI(-4229.5, -11706, 7, 6, 0, "Exodar Blacksmithing Trainer");
            player->SEND_GOSSIP_MENU(9532, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Cooking
            player->SEND_POI(-3798.3, -11651.7, 7, 6, 0, "Exodar Cooking Trainer");
            player->SEND_GOSSIP_MENU(9551, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Enchanting
            player->SEND_POI(-3889.3, -11495, 7, 6, 0, "Exodar Enchanting Trainer");
            player->SEND_GOSSIP_MENU(9535, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Engineering
            player->SEND_POI(-4257.68, -11640.3, 7, 6, 0, "Exodar Engineering Trainer");
            player->SEND_GOSSIP_MENU(9536, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //First Aid
            player->SEND_POI(-3769.5, -11479.6, 7, 6, 0, "Exodar First Aid Trainer");
            player->SEND_GOSSIP_MENU(9537, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Fishing
            player->SEND_POI(-3725.5, -11385.2, 7, 6, 0, "Exodar Fishing Trainer");
            player->SEND_GOSSIP_MENU(9538, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 8:                    //Jewelcrafting
            player->SEND_POI(-3783, -11546, 7, 6, 0, "Exodar Jewelcrafting Trainer");
            player->SEND_GOSSIP_MENU(9547, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 9:                    //Herbalism
            player->SEND_POI(-4040.6, -11364.5, 7, 6, 0, "Exodar Herbalist Trainer");
            player->SEND_GOSSIP_MENU(9543, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 10:                   //Leatherworking
            player->SEND_POI(-4140.6, -11776.7, 7, 6, 0, "Exodar Leatherworking Trainer");
            player->SEND_GOSSIP_MENU(9549, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 11:                   //Mining
            player->SEND_POI(-4228, -11697, 7, 6, 0, "Exodar Mining Trainer");
            player->SEND_GOSSIP_MENU(9552, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 12:                   //Skinning
            player->SEND_POI(-4134.97, -11760.5, 7, 6, 0, "Exodar Skinning Trainer");
            player->SEND_GOSSIP_MENU(9557, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 13:                   //Tailoring
            player->SEND_POI(-4092.5, -11744.5, 7, 6, 0, "Exodar Tailor Trainer");
            player->SEND_GOSSIP_MENU(9559, _Creature->GetGUID());
            break;
    }
}

bool GossipSelect_guard_exodar(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    switch (sender)
    {
        case GOSSIP_SENDER_MAIN:            SendDefaultMenu_guard_exodar(player, _Creature, action); break;
        case GOSSIP_SENDER_SEC_CLASSTRAIN:  SendClassTrainerMenu_guard_exodar(player, _Creature, action); break;
        case GOSSIP_SENDER_SEC_PROFTRAIN:   SendProfTrainerMenu_guard_exodar(player, _Creature, action); break;
        case GOSSIP_SENDER_SEC_BATTLEINFO:  SendBattleMasterMenu_guard_exodar(player, _Creature, action); break;
    }
    return true;
}

/*******************************************************
 * guard_exodar end
 *******************************************************/

CreatureAI* GetAI_guard_exodar(Creature *_Creature)
{
    return new guardAI (_Creature);
}

/*******************************************************
 * guard_ironforge start
 *******************************************************/

bool GossipHello_guard_ironforge(Player *player, Creature *_Creature)
{
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_AUCTIONHOUSE      , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_IRONFORGE_BANK    , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_DEEPRUNTRAM       , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_GRYPHON           , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_GUILDMASTER       , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_INN               , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_MAILBOX           , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_STABLEMASTER      , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 8);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_WEAPONMASTER      , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 9);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BATTLEMASTER      , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 10);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_CLASSTRAINER      , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_PROFTRAINER       , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 12);
    player->SEND_GOSSIP_MENU(2760, _Creature->GetGUID());
    return true;
}

void SendDefaultMenu_guard_ironforge(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Auction House
            player->SEND_POI(-4957.39, -911.6, 7, 6, 0, "Ironforge Auction House");
            player->SEND_GOSSIP_MENU(3014, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Bank
            player->SEND_POI(-4891.91, -991.47, 7, 6, 0, "The Vault");
            player->SEND_GOSSIP_MENU(2761, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Tram
            player->SEND_POI(-4835.27, -1294.69, 7, 6, 0, "Deeprun Tram");
            player->SEND_GOSSIP_MENU(3814, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Gryphon Master
            player->SEND_POI(-4821.52, -1152.3, 7, 6, 0, "Ironforge Gryphon Master");
            player->SEND_GOSSIP_MENU(2762, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Guild Master
            player->SEND_POI(-5021, -996.45, 7, 6, 0, "Ironforge Visitor's Center");
            player->SEND_GOSSIP_MENU(2764, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //Inn
            player->SEND_POI(-4850.47, -872.57, 7, 6, 0, "Stonefire Tavern");
            player->SEND_GOSSIP_MENU(2768, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Mailbox
            player->SEND_POI(-4845.7, -880.55, 7, 6, 0, "Ironforge Mailbox");
            player->SEND_GOSSIP_MENU(2769, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 8:                    //Stable Master
            player->SEND_POI(-5010.2, -1262, 7, 6, 0, "Ulbrek Firehand");
            player->SEND_GOSSIP_MENU(5986, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 9:                    //Weapons Trainer
            player->SEND_POI(-5040, -1201.88, 7, 6, 0, "Bixi and Buliwyf");
            player->SEND_GOSSIP_MENU(4518, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 10:                   //Battlemaster
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ALTERACVALLEY   , GOSSIP_SENDER_SEC_BATTLEINFO, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ARATHIBASIN     , GOSSIP_SENDER_SEC_BATTLEINFO, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_WARSONGULCH     , GOSSIP_SENDER_SEC_BATTLEINFO, GOSSIP_ACTION_INFO_DEF + 3);
            player->SEND_GOSSIP_MENU(7529, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 11:                   //Class Trainer
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_HUNTER          , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_MAGE            , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_PALADIN         , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_PRIEST          , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ROGUE           , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_WARLOCK         , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 6);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_WARRIOR         , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 7);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_SHAMAN          , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 8);
            player->SEND_GOSSIP_MENU(2766, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 12:                   //Profession Trainer
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ALCHEMY         , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BLACKSMITHING   , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_COOKING         , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ENCHANTING      , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ENGINEERING     , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_FIRSTAID        , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 6);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_FISHING         , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 7);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_HERBALISM       , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 8);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_LEATHERWORKING  , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 9);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_MINING          , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 10);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_SKINNING        , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 11);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_TAILORING       , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 12);
            player->SEND_GOSSIP_MENU(2793, _Creature->GetGUID());
            break;
    }
}

void SendBattleMasterMenu_guard_ironforge(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //AV
            player->SEND_POI(-5047.87, -1263.77, 7, 6, 0, "Glordrum Steelbeard");
            player->SEND_GOSSIP_MENU(7483, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //AB
            player->SEND_POI(-5038.37, -1266.39, 7, 6, 0, "Donal Osgood");
            player->SEND_GOSSIP_MENU(7649, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //WSG
            player->SEND_POI(-5037.24, -1274.82, 7, 6, 0, "Lylandris");
            player->SEND_GOSSIP_MENU(7528, _Creature->GetGUID());
            break;
    }
}

void SendClassTrainerMenu_guard_ironforge(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Hunter
            player->SEND_POI(-5023, -1253.68, 7, 6, 0, "Hall of Arms");
            player->SEND_GOSSIP_MENU(2770, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Mage
            player->SEND_POI(-4627, -926.45, 7, 6, 0, "Hall of Mysteries");
            player->SEND_GOSSIP_MENU(2771, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Paladin
            player->SEND_POI(-4627.02, -926.45, 7, 6, 0, "Hall of Mysteries");
            player->SEND_GOSSIP_MENU(2773, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Priest
            player->SEND_POI(-4627, -926.45, 7, 6, 0, "Hall of Mysteries");
            player->SEND_GOSSIP_MENU(2772, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Rogue
            player->SEND_POI(-4647.83, -1124, 7, 6, 0, "Ironforge Rogue Trainer");
            player->SEND_GOSSIP_MENU(2774, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //Warlock
            player->SEND_POI(-4605, -1110.45, 7, 6, 0, "Ironforge Warlock Trainer");
            player->SEND_GOSSIP_MENU(2775, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Warrior
            player->SEND_POI(-5023.08, -1253.68, 7, 6, 0, "Hall of Arms");
            player->SEND_GOSSIP_MENU(2776, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 8:                    //Shaman
            player->SEND_POI(-4732, -1147, 7, 6, 0, "Ironforge Shaman Trainer");
                                                            //incorrect id
            player->SEND_GOSSIP_MENU(2766, _Creature->GetGUID());
            break;
    }
}

void SendProfTrainerMenu_guard_ironforge(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Alchemy
            player->SEND_POI(-4858.5, -1241.83, 7, 6, 0, "Berryfizz's Potions and Mixed Drinks");
            player->SEND_GOSSIP_MENU(2794, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Blacksmithing
            player->SEND_POI(-4796.97, -1110.17, 7, 6, 0, "The Great Forge");
            player->SEND_GOSSIP_MENU(2795, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Cooking
            player->SEND_POI(-4767.83, -1184.59, 7, 6, 0, "The Bronze Kettle");
            player->SEND_GOSSIP_MENU(2796, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Enchanting
            player->SEND_POI(-4803.72, -1196.53, 7, 6, 0, "Thistlefuzz Arcanery");
            player->SEND_GOSSIP_MENU(2797, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Engineering
            player->SEND_POI(-4799.56, -1250.23, 7, 6, 0, "Springspindle's Gadgets");
            player->SEND_GOSSIP_MENU(2798, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //First Aid
            player->SEND_POI(-4881.6, -1153.13, 7, 6, 0, "Ironforge Physician");
            player->SEND_GOSSIP_MENU(2799, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Fishing
            player->SEND_POI(-4597.91, -1091.93, 7, 6, 0, "Traveling Fisherman");
            player->SEND_GOSSIP_MENU(2800, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 8:                    //Herbalism
            player->SEND_POI(-4876.9, -1151.92, 7, 6, 0, "Ironforge Physician");
            player->SEND_GOSSIP_MENU(2801, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 9:                    //Leatherworking
            player->SEND_POI(-4745, -1027.57, 7, 6, 0, "Finespindle's Leather Goods");
            player->SEND_GOSSIP_MENU(2802, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 10:                   //Minning
            player->SEND_POI(-4705.06, -1116.43, 7, 6, 0, "Deepmountain Mining Guild");
            player->SEND_GOSSIP_MENU(2804, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 11:                   //Skinning
            player->SEND_POI(-4745, -1027.57, 7, 6, 0, "Finespindle's Leather Goods");
            player->SEND_GOSSIP_MENU(2805, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 12:                   //Tailoring
            player->SEND_POI(-4719.60, -1056.96, 7, 6, 0, "Stonebrow's Clothier");
            player->SEND_GOSSIP_MENU(2807, _Creature->GetGUID());
            break;
    }
}

bool GossipSelect_guard_ironforge(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    switch (sender)
    {
        case GOSSIP_SENDER_MAIN:            SendDefaultMenu_guard_ironforge(player, _Creature, action); break;
        case GOSSIP_SENDER_SEC_CLASSTRAIN:  SendClassTrainerMenu_guard_ironforge(player, _Creature, action); break;
        case GOSSIP_SENDER_SEC_PROFTRAIN:   SendProfTrainerMenu_guard_ironforge(player, _Creature, action); break;
        case GOSSIP_SENDER_SEC_BATTLEINFO:  SendBattleMasterMenu_guard_ironforge(player, _Creature, action); break;
    }
    return true;
}

/*******************************************************
 * guard_ironforge end
 *******************************************************/

CreatureAI* GetAI_guard_ironforge(Creature *_Creature)
{
    return new guardAI (_Creature);
}

/*******************************************************
 * guard_mulgore start
 *******************************************************/

bool GossipHello_guard_mulgore(Player *player, Creature *_Creature)
{
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BANK         , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_WINDRIDER    , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_INN          , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_STABLEMASTER , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_CLASSTRAINER , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_PROFTRAINER  , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
    player->SEND_GOSSIP_MENU(3543,_Creature->GetGUID());
    return true;
}

void SendDefaultMenu_guard_mulgore(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Bank
            player->SEND_GOSSIP_MENU(4051,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Wind rider
            player->SEND_GOSSIP_MENU(4052,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Inn
            player->SEND_POI(-2361.38, -349.19, 7, 6, 0, "Bloodhoof Village Inn");
            player->SEND_GOSSIP_MENU(4053,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Stable master
            player->SEND_POI(-2338.86, -357.56, 7, 6, 0, "Seikwa");
            player->SEND_GOSSIP_MENU(5976,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Class trainer
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_DRUID           , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_HUNTER          , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_SHAMAN          , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_WARRIOR         , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            player->SEND_GOSSIP_MENU(4069,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //Profession trainer
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ALCHEMY         , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BLACKSMITHING   , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_COOKING         , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ENCHANTING      , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_FIRSTAID        , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_FISHING         , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 6);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_HERBALISM       , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 7);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_LEATHERWORKING  , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 8);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_MINING          , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 9);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_SKINNING        , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 10);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_TAILORING       , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 11);
            player->SEND_GOSSIP_MENU(4070,_Creature->GetGUID());
            break;
    }
}

void SendClassTrainerMenu_guard_mulgore(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Druid
            player->SEND_POI(-2312.15, -443.69, 7, 6, 0, "Gennia Runetotem");
            player->SEND_GOSSIP_MENU(4054,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Hunter
            player->SEND_POI(-2178.14, -406.14, 7, 6, 0, "Yaw Sharpmane");
            player->SEND_GOSSIP_MENU(4055,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Shaman
            player->SEND_POI(-2301.5, -439.87, 7, 6, 0, "Narm Skychaser");
            player->SEND_GOSSIP_MENU(4056,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Warrior
            player->SEND_POI(-2345.43, -494.11, 7, 6, 0, "Krang Stonehoof");
            player->SEND_GOSSIP_MENU(4057,_Creature->GetGUID());
            break;
    }
}

void SendProfTrainerMenu_guard_mulgore(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Alchemy
            player->SEND_GOSSIP_MENU(4058,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Blacksmithing
            player->SEND_GOSSIP_MENU(4059,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Cooking
            player->SEND_POI(-2263.34, -287.91, 7, 6, 0, "Pyall Silentstride");
            player->SEND_GOSSIP_MENU(4060,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Enchanting
            player->SEND_GOSSIP_MENU(4061,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //First Aid
            player->SEND_POI(-2353.52, -355.82, 7, 6, 0, "Vira Younghoof");
            player->SEND_GOSSIP_MENU(4062,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //Fishing
            player->SEND_POI(-2349.21, -241.37, 7, 6, 0, "Uthan Stillwater");
            player->SEND_GOSSIP_MENU(4063,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Herbalism
            player->SEND_GOSSIP_MENU(4064,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 8:                    //Leatherworking
            player->SEND_POI(-2257.12, -288.63, 7, 6, 0, "Chaw Stronghide");
            player->SEND_GOSSIP_MENU(4065,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 9:                    //Mining
            player->SEND_GOSSIP_MENU(4066,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 10:                   //Skinning
            player->SEND_POI(-2252.94, -291.32, 7, 6, 0, "Yonn Deepcut");
            player->SEND_GOSSIP_MENU(4067,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 11:                   //Tailoring
            player->SEND_GOSSIP_MENU(4068,_Creature->GetGUID());
            break;
    }
}

bool GossipSelect_guard_mulgore(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    switch (sender)
    {
        case GOSSIP_SENDER_MAIN:            SendDefaultMenu_guard_mulgore(player, _Creature, action); break;
        case GOSSIP_SENDER_SEC_CLASSTRAIN:  SendClassTrainerMenu_guard_mulgore(player, _Creature, action); break;
        case GOSSIP_SENDER_SEC_PROFTRAIN:   SendProfTrainerMenu_guard_mulgore(player, _Creature, action); break;
    }
    return true;
}

/*******************************************************
 * guard_mulgore end
 *******************************************************/

CreatureAI* GetAI_guard_mulgore(Creature *_Creature)
{
    return new guardAI (_Creature);
}

/*******************************************************
 * guard_orgrimmar start
 *******************************************************/

bool GossipHello_guard_orgrimmar(Player *player, Creature *_Creature)
{
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BANK          , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_WINDRIDER     , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_GUILDMASTER   , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_INN           , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_MAILBOX       , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_AUCTIONHOUSE  , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ZEPPLINMASTER , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_WEAPONMASTER  , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 8);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_STABLEMASTER  , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 9);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_OFFICERS      , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 10);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BATTLEMASTER  , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_CLASSTRAINER  , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 12);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_PROFTRAINER   , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 13);
    player->SEND_GOSSIP_MENU(2593,_Creature->GetGUID());

    return true;
}

void SendDefaultMenu_guard_orgrimmar(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Bank
            player->SEND_POI(1631.51, -4375.33, 7, 6, 0, "Bank of Orgrimmar");
            player->SEND_GOSSIP_MENU(2554,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //wind rider
            player->SEND_POI(1676.6, -4332.72, 7, 6, 0, "The Sky Tower");
            player->SEND_GOSSIP_MENU(2555,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //guild master
            player->SEND_POI(1576.93, -4294.75, 7, 6, 0, "Horde Embassy");
            player->SEND_GOSSIP_MENU(2556,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Inn
            player->SEND_POI(1644.51, -4447.27, 7, 6, 0, "Orgrimmar Inn");
            player->SEND_GOSSIP_MENU(2557,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //mailbox
            player->SEND_POI(1622.53, -4388.79, 7, 6, 0, "Orgrimmar Mailbox");
            player->SEND_GOSSIP_MENU(2558,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //auction house
            player->SEND_POI(1679.21, -4450.1, 7, 6, 0, "Orgrimmar Auction House");
            player->SEND_GOSSIP_MENU(3075,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //zeppelin
            player->SEND_POI(1337.36, -4632.7, 7, 6, 0, "Orgrimmar Zeppelin Tower");
            player->SEND_GOSSIP_MENU(3173,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 8:                    //weapon master
            player->SEND_POI(2092.56, -4823.95, 7, 6, 0, "Sayoc & Hanashi");
            player->SEND_GOSSIP_MENU(4519,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 9:                    //stable master
            player->SEND_POI(2133.12, -4663.93, 7, 6, 0, "Xon'cha");
            player->SEND_GOSSIP_MENU(5974,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 10:                   //officers lounge
            player->SEND_POI(1633.56, -4249.37, 7, 6, 0, "Hall of Legends");
            player->SEND_GOSSIP_MENU(7046,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 11:                   //battlemaster
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ALTERACVALLEY       , GOSSIP_SENDER_SEC_BATTLEINFO, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ARATHIBASIN         , GOSSIP_SENDER_SEC_BATTLEINFO, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_WARSONGULCH         , GOSSIP_SENDER_SEC_BATTLEINFO, GOSSIP_ACTION_INFO_DEF + 3);
            player->SEND_GOSSIP_MENU(7521,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 12:                   //class trainer
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_HUNTER              , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_MAGE                , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_PRIEST              , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_SHAMAN              , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ROGUE               , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_WARLOCK             , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 6);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_WARRIOR             , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 7);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_PALADIN             , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 8);
            player->SEND_GOSSIP_MENU(2599,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 13:                   //profession trainer
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ALCHEMY             , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BLACKSMITHING       , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_COOKING             , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ENCHANTING          , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ENGINEERING         , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_FIRSTAID            , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 6);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_FISHING             , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 7);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_HERBALISM           , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 8);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_LEATHERWORKING      , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 9);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_MINING              , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 10);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_SKINNING            , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 11);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_TAILORING           , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 12);
            player->SEND_GOSSIP_MENU(2594,_Creature->GetGUID());
            break;
    }
}

void SendBattleMasterMenu_guard_orgrimmar(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //AV
            player->SEND_POI(1983.92, -4794.2, 7, 6, 0, "Hall of the Brave");
            player->SEND_GOSSIP_MENU(7484,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //AB
            player->SEND_POI(1983.92, -4794.2, 7, 6, 0, "Hall of the Brave");
            player->SEND_GOSSIP_MENU(7644,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //WSG
            player->SEND_POI(1983.92, -4794.2, 7, 6, 0, "Hall of the Brave");
            player->SEND_GOSSIP_MENU(7520,_Creature->GetGUID());
            break;
    }
}

void SendClassTrainerMenu_guard_orgrimmar(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Hunter
            player->SEND_POI(2114.84, -4625.31, 7, 6, 0, "Orgrimmar Hunter's Hall");
            player->SEND_GOSSIP_MENU(2559,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Mage
            player->SEND_POI(1451.26, -4223.33, 7, 6, 0, "Darkbriar Lodge");
            player->SEND_GOSSIP_MENU(2560,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Priest
            player->SEND_POI(1442.21, -4183.24, 7, 6, 0, "Spirit Lodge");
            player->SEND_GOSSIP_MENU(2561,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Shaman
            player->SEND_POI(1925.34, -4181.89, 7, 6, 0, "Thrall's Fortress");
            player->SEND_GOSSIP_MENU(2562,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Rogue
            player->SEND_POI(1773.39, -4278.97, 7, 6, 0, "Shadowswift Brotherhood");
            player->SEND_GOSSIP_MENU(2563,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //Warlock
            player->SEND_POI(1849.57, -4359.68, 7, 6, 0, "Darkfire Enclave");
            player->SEND_GOSSIP_MENU(2564,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Warrior
            player->SEND_POI(1983.92, -4794.2, 7, 6, 0, "Hall of the Brave");
            player->SEND_GOSSIP_MENU(2565,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 8:                    //Paladin
            player->SEND_POI(1906.65, -4134.26, 7, 6, 0, "Valley of Wisdom");
            player->SEND_GOSSIP_MENU(10843,_Creature->GetGUID());
            break;
    }
}

void SendProfTrainerMenu_guard_orgrimmar(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Alchemy
            player->SEND_POI(1955.17, -4475.79, 7, 6, 0, "Yelmak's Alchemy and Potions");
            player->SEND_GOSSIP_MENU(2497,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Blacksmithing
            player->SEND_POI(2054.34, -4831.85, 7, 6, 0, "The Burning Anvil");
            player->SEND_GOSSIP_MENU(2499,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Cooking
            player->SEND_POI(1780.96, -4481.31, 7, 6, 0, "Borstan's Firepit");
            player->SEND_GOSSIP_MENU(2500,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Enchanting
            player->SEND_POI(1917.5, -4434.95, 7, 6, 0, "Godan's Runeworks");
            player->SEND_GOSSIP_MENU(2501,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Engineering
            player->SEND_POI(2038.45, -4744.75, 7, 6, 0, "Nogg's Machine Shop");
            player->SEND_GOSSIP_MENU(2653,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //First Aid
            player->SEND_POI(1485.21, -4160.91, 7, 6, 0, "Survival of the Fittest");
            player->SEND_GOSSIP_MENU(2502,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Fishing
            player->SEND_POI(1994.15, -4655.7, 7, 6, 0, "Lumak's Fishing");
            player->SEND_GOSSIP_MENU(2503,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 8:                    //Herbalism
            player->SEND_POI(1898.61, -4454.93, 7, 6, 0, "Jandi's Arboretum");
            player->SEND_GOSSIP_MENU(2504,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 9:                    //Leatherworking
            player->SEND_POI(1852.82, -4562.31, 7, 6, 0, "Kodohide Leatherworkers");
            player->SEND_GOSSIP_MENU(2513,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 10:                   //Mining
            player->SEND_POI(2029.79, -4704, 7, 6, 0, "Red Canyon Mining");
            player->SEND_GOSSIP_MENU(2515,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 11:                   //Skinning
            player->SEND_POI(1852.82, -4562.31, 7, 6, 0, "Kodohide Leatherworkers");
            player->SEND_GOSSIP_MENU(2516,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 12:                   //Tailoring
            player->SEND_POI(1802.66, -4560.66, 7, 6, 0, "Magar's Cloth Goods");
            player->SEND_GOSSIP_MENU(2518,_Creature->GetGUID());
            break;
    }
}

bool GossipSelect_guard_orgrimmar(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    switch (sender)
    {
        case GOSSIP_SENDER_MAIN:            SendDefaultMenu_guard_orgrimmar(player, _Creature, action); break;
        case GOSSIP_SENDER_SEC_CLASSTRAIN:  SendClassTrainerMenu_guard_orgrimmar(player, _Creature, action); break;
        case GOSSIP_SENDER_SEC_PROFTRAIN:   SendProfTrainerMenu_guard_orgrimmar(player, _Creature, action); break;
        case GOSSIP_SENDER_SEC_BATTLEINFO:  SendBattleMasterMenu_guard_orgrimmar(player, _Creature, action); break;
    }
    return true;
}

bool ReceiveEmote_guard_orgrimmar(Player *player, Creature *_Creature, uint32 emote)
{
    if( player->GetTeam() == HORDE )
        DoReplyToTextEmote(_Creature,emote);
    return true;
}

/*******************************************************
 * guard_orgrimmar end
 *******************************************************/

CreatureAI* GetAI_guard_orgrimmar(Creature *_Creature)
{
    return new guardAI (_Creature);
}

/*******************************************************
 * guard_shattrath start
 *******************************************************/

bool GossipHello_guard_shattrath(Player *player, Creature *_Creature)
{
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_TAVERN                       , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BANK                         , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_INN                          , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_FLIGHTMASTER                 , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_MAILBOX                      , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_STABLEMASTER                 , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BATTLEMASTER                 , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_PROFTRAINER                  , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 8);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_MANALOOM                     , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 9);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ALCHEMYLAB                   , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 10);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_GEMMERCHANT                  , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);
    player->SEND_GOSSIP_MENU(10321, _Creature->GetGUID());

    return true;
}

void SendDefaultMenu_guard_shattrath(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Tavern
            player->SEND_POI(-1759.5, 5165, 7, 6, 0, "Worlds End Tavern");
            player->SEND_GOSSIP_MENU(10394, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Bank
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BANKALDOR            , GOSSIP_SENDER_SEC_BANK, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BANKSCYERS           , GOSSIP_SENDER_SEC_BANK, GOSSIP_ACTION_INFO_DEF + 2);
            player->SEND_GOSSIP_MENU(10379, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Inn
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_INNALDOR             , GOSSIP_SENDER_SEC_INN, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_INNSCYERS            , GOSSIP_SENDER_SEC_INN, GOSSIP_ACTION_INFO_DEF + 2);
            player->SEND_GOSSIP_MENU(10382, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Flight master
            player->SEND_POI(-1832, 5299, 7, 6, 0, "Flight Master");
            player->SEND_GOSSIP_MENU(10385, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Mailbox
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BANKALDOR           , GOSSIP_SENDER_SEC_MAILBOX, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_INNALDOR            , GOSSIP_SENDER_SEC_MAILBOX, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BANKSCYERS          , GOSSIP_SENDER_SEC_MAILBOX, GOSSIP_ACTION_INFO_DEF + 3);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_INNSCYERS           , GOSSIP_SENDER_SEC_MAILBOX, GOSSIP_ACTION_INFO_DEF + 4);
            player->SEND_GOSSIP_MENU(10386, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //Stable master
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_STABLEALDOR          , GOSSIP_SENDER_SEC_STABLEMASTER, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_STABLESCYERS         , GOSSIP_SENDER_SEC_STABLEMASTER, GOSSIP_ACTION_INFO_DEF + 2);
            player->SEND_GOSSIP_MENU(10387, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Battlemaster
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BATTLEMASTERALLIANCE , GOSSIP_SENDER_SEC_BATTLEINFO, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BATTLEMASTERHORDE    , GOSSIP_SENDER_SEC_BATTLEINFO, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BATTLEMASTERARENA    , GOSSIP_SENDER_SEC_BATTLEINFO, GOSSIP_ACTION_INFO_DEF + 3);
            player->SEND_GOSSIP_MENU(10388, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 8:                    //Profession master
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ALCHEMY              , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BLACKSMITHING        , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_COOKING              , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ENCHANTING           , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_FIRSTAID             , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_JEWELCRAFTING        , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 6);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_LEATHERWORKING       , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 7);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_SKINNING             , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 8);
            player->SEND_GOSSIP_MENU(10391, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 9:                    //Mana Loom
            player->SEND_POI(-2070, 5265.5, 7, 6, 0, "Mana Loom");
            player->SEND_GOSSIP_MENU(10503, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 10:                   //Alchemy Lab
            player->SEND_POI(-1648.5, 5540, 7, 6, 0, "Alchemy Lab");
            player->SEND_GOSSIP_MENU(10321, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 11:                   //Gem Merchant
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_GEMALDOR             , GOSSIP_SENDER_SEC_GEMMERCHANT, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_GEMSCYERS            , GOSSIP_SENDER_SEC_GEMMERCHANT, GOSSIP_ACTION_INFO_DEF + 2);
            player->SEND_GOSSIP_MENU(10697, _Creature->GetGUID());
            break;
    }
}

void SendBankMenu_guard_shattrath(Player *player, Creature *_Creature, uint32 action)
{
    if (action == GOSSIP_ACTION_INFO_DEF + 1)
    {
        player->SEND_POI(-1730.5, 5496, 7, 6, 0, "Aldor Bank");
        player->SEND_GOSSIP_MENU(10380,  _Creature->GetGUID());
    }
    if (action == GOSSIP_ACTION_INFO_DEF + 2)
    {
        player->SEND_POI(-1997.7, 5363, 7, 6, 0, "Scyers Bank");
        player->SEND_GOSSIP_MENU(10381, _Creature->GetGUID());
    }
}

void SendInnMenu_guard_shattrath(Player *player, Creature *_Creature, uint32 action)
{
    if (action == GOSSIP_ACTION_INFO_DEF + 1)
    {
        player->SEND_POI(-1895, 5767, 7, 6, 0, "Aldor Inn");
        player->SEND_GOSSIP_MENU(10383,  _Creature->GetGUID());
    }
    if (action == GOSSIP_ACTION_INFO_DEF + 2)
    {
        player->SEND_POI(-2178, 5405, 7, 6, 0, "Scyers Inn");
        player->SEND_GOSSIP_MENU(10384, _Creature->GetGUID());
    }
}

void SendMailboxMenu_guard_shattrath(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:
            player->SEND_POI(-1730.5, 5496, 7, 6, 0, "Aldor Bank");
            player->SEND_GOSSIP_MENU(10380,  _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:
            player->SEND_POI(-1895, 5767, 7, 6, 0, "Aldor Inn");
            player->SEND_GOSSIP_MENU(10383,  _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:
            player->SEND_POI(-1997.7, 5363, 7, 6, 0, "Scyers Bank");
            player->SEND_GOSSIP_MENU(10381, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:
            player->SEND_POI(-2178, 5405, 7, 6, 0, "Scyers Inn");
            player->SEND_GOSSIP_MENU(10384, _Creature->GetGUID());
            break;
    }
}

void SendStableMasterMenu_guard_shattrath(Player *player, Creature *_Creature, uint32 action)
{
    if (action == GOSSIP_ACTION_INFO_DEF + 1)
    {
        player->SEND_POI(-1888.5, 5761, 7, 6, 0, "Aldor Stable");
        player->SEND_GOSSIP_MENU(10321,  _Creature->GetGUID());
    }
    if (action == GOSSIP_ACTION_INFO_DEF + 2)
    {
        player->SEND_POI(-2170, 5404, 7, 6, 0, "Scyers Stable");
        player->SEND_GOSSIP_MENU(10321, _Creature->GetGUID());
    }
}

void SendBattleMasterMenu_guard_shattrath(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:
            player->SEND_POI(-1774, 5251, 7, 6, 0, "Alliance Battlemasters");
            player->SEND_GOSSIP_MENU(10389, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:
            player->SEND_POI(-1963, 5263, 7, 6, 0, "Horde Battlemasters");
            player->SEND_GOSSIP_MENU(10390,  _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:
            player->SEND_POI(-1960, 5175, 7, 6, 0, "Arena Battlemasters");
            player->SEND_GOSSIP_MENU(12510,  _Creature->GetGUID());
            break;
    }
}

void SendProfTrainerMenu_guard_shattrath(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Alchemy
            player->SEND_POI(-1648.5, 5534, 7, 6, 0, "Lorokeem");
            player->SEND_GOSSIP_MENU(10392, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Blacksmithing
            player->SEND_POI(-1847, 5222, 7, 6, 0, "Kradu Grimblade and Zula Slagfury");
            player->SEND_GOSSIP_MENU(10400, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Cooking
            player->SEND_POI(-2067.4, 5316.5, 7, 6, 0, "Jack Trapper");
            player->SEND_GOSSIP_MENU(10393, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Enchanting
            player->SEND_POI(-2263.5, 5563.5, 7, 6, 0, "High Enchanter Bardolan");
            player->SEND_GOSSIP_MENU(10395, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //First Aid
            player->SEND_POI(-1591, 5265.5, 7, 6, 0, "Mildred Fletcher");
            player->SEND_GOSSIP_MENU(10396, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //Jewelcrafting
            player->SEND_POI(-1654, 5667.5, 7, 6, 0, "Hamanar");
            player->SEND_GOSSIP_MENU(10397, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Leatherworking
            player->SEND_POI(-2060.5, 5256.5, 7, 6, 0, "Darmari");
            player->SEND_GOSSIP_MENU(10399, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 8:                    //Skinning
            player->SEND_POI(-2048, 5300, 7, 6, 0, "Seymour");
            player->SEND_GOSSIP_MENU(10398, _Creature->GetGUID());
            break;
    }
}

void SendGemMerchantMenu_guard_shattrath(Player *player, Creature *_Creature, uint32 action)
{
    if (action == GOSSIP_ACTION_INFO_DEF + 1)
    {
        player->SEND_POI(-1645, 5669.5, 7, 6, 0, "Aldor Gem Merchant");
        player->SEND_GOSSIP_MENU(10698,  _Creature->GetGUID());
    }
    if (action == GOSSIP_ACTION_INFO_DEF + 2)
    {
        player->SEND_POI(-2193, 5424.5, 7, 6, 0, "Scyers Gem Merchant");
        player->SEND_GOSSIP_MENU(10699, _Creature->GetGUID());
    }
}

bool GossipSelect_guard_shattrath(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    switch (sender)
    {
        case GOSSIP_SENDER_MAIN:              SendDefaultMenu_guard_shattrath(player, _Creature, action); break;
        case GOSSIP_SENDER_SEC_BANK:          SendBankMenu_guard_shattrath(player, _Creature, action); break;
        case GOSSIP_SENDER_SEC_INN:           SendInnMenu_guard_shattrath(player, _Creature, action); break;
        case GOSSIP_SENDER_SEC_STABLEMASTER:  SendStableMasterMenu_guard_shattrath(player, _Creature, action); break;
        case GOSSIP_SENDER_SEC_GEMMERCHANT:   SendGemMerchantMenu_guard_shattrath(player, _Creature, action); break;
        case GOSSIP_SENDER_SEC_MAILBOX:       SendMailboxMenu_guard_shattrath(player, _Creature, action); break;
        case GOSSIP_SENDER_SEC_PROFTRAIN:     SendProfTrainerMenu_guard_shattrath(player, _Creature, action); break;
        case GOSSIP_SENDER_SEC_BATTLEINFO:    SendBattleMasterMenu_guard_shattrath(player, _Creature, action); break;
    }
    return true;
}

/*******************************************************
 * guard_shattrath end
 *******************************************************/

CreatureAI* GetAI_guard_shattrath(Creature *_Creature)
{
    return new guardAI (_Creature);
}

/*******************************************************
 * guard_shattrath_aldor
 *******************************************************/

#define SPELL_BANISHED_SHATTRATH_A  36642
#define SPELL_BANISHED_SHATTRATH_S  36671
#define SPELL_BANISH_TELEPORT       36643
#define SPELL_EXILE                 39533

struct TRINITY_DLL_DECL guard_shattrath_aldorAI : public guardAI
{
    guard_shattrath_aldorAI(Creature *c) : guardAI(c) {}

    uint32 Exile_Timer;
    uint32 Banish_Timer;
    uint64 playerGUID;
    bool CanTeleport;

    void Reset()
    {
        Banish_Timer = 5000;
        Exile_Timer = 8500;
        playerGUID = 0;
        CanTeleport = false;
    }

    void Aggro(Unit *who) {}

    void UpdateAI(const uint32 diff)
    {
        if(!UpdateVictim())
            return;

        if( CanTeleport )
        {
            if( Exile_Timer < diff )
            {
                if( Unit* temp = Unit::GetUnit(*m_creature,playerGUID) )
                {
                    temp->CastSpell(temp,SPELL_EXILE,true);
                    temp->CastSpell(temp,SPELL_BANISH_TELEPORT,true);
                }
                playerGUID = 0;
                Exile_Timer = 8500;
                CanTeleport = false;
            }else Exile_Timer -= diff;
        }
        else if( Banish_Timer < diff )
        {
            Unit* temp = m_creature->getVictim();
            if( temp && temp->GetTypeId() == TYPEID_PLAYER )
            {
                DoCast(temp,SPELL_BANISHED_SHATTRATH_A);
                Banish_Timer = 9000;
                playerGUID = temp->GetGUID();
                if( playerGUID )
                    CanTeleport = true;
            }
        }else Banish_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

bool GossipHello_guard_shattrath_aldor(Player *player, Creature *_Creature)
{
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_TAVERN                       , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BANK                         , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_INN                          , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_FLIGHTMASTER                 , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_MAILBOX                      , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_STABLEMASTER                 , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BATTLEMASTER                 , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_PROFTRAINER                  , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 8);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_MANALOOM                     , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 9);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ALCHEMYLAB                   , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 10);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_GEMMERCHANT                  , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);
    player->SEND_GOSSIP_MENU(10524, _Creature->GetGUID());
    return true;
}

void SendDefaultMenu_guard_shattrath_aldor(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Tavern
            player->SEND_POI(-1759.5, 5165, 7, 6, 0, "Worlds End Tavern");
            player->SEND_GOSSIP_MENU(10394, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Bank
            player->SEND_POI(-1730.5, 5496, 7, 6, 0, "Aldor Bank");
            player->SEND_GOSSIP_MENU(10380, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Inn
            player->SEND_POI(-1895, 5767, 7, 6, 0, "Aldor Inn");
            player->SEND_GOSSIP_MENU(10525,  _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Flight master
            player->SEND_POI(-1832, 5299, 7, 6, 0, "Shattrath Flight Master");
            player->SEND_GOSSIP_MENU(10402, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Mailbox
            player->SEND_POI(0, 0, 7, 6, 0, "Aldor Mailbox");
                                                            //unknown
            player->SEND_GOSSIP_MENU(10524, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //Stable master
            player->SEND_POI(-1888.5, 5761, 7, 6, 0, "Aldor Stable Master");
            player->SEND_GOSSIP_MENU(10527, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Battlemaster
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BATTLEMASTERALLIANCE , GOSSIP_SENDER_SEC_BATTLEINFO, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BATTLEMASTERHORDE    , GOSSIP_SENDER_SEC_BATTLEINFO, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BATTLEMASTERARENA    , GOSSIP_SENDER_SEC_BATTLEINFO, GOSSIP_ACTION_INFO_DEF + 3);
            player->SEND_GOSSIP_MENU(10388, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 8:                    //Profession master
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ALCHEMY              , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BLACKSMITHING        , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_COOKING              , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ENCHANTING           , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_FIRSTAID             , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_JEWELCRAFTING        , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 6);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_LEATHERWORKING       , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 7);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_SKINNING             , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 8);
            player->SEND_GOSSIP_MENU(10391, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 9:                    //Mana Loom
            player->SEND_POI(-2070, 5265.5, 7, 6, 0, "Mana Loom");
            player->SEND_GOSSIP_MENU(10522, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 10:                   //Alchemy Lab
            player->SEND_POI(-1648.5, 5540, 7, 6, 0, "Alchemy Lab");
            player->SEND_GOSSIP_MENU(10696, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 11:                   //Gem Merchant
            player->SEND_POI(-1645, 5669.5, 7, 6, 0, "Aldor Gem Merchant");
            player->SEND_GOSSIP_MENU(10411, _Creature->GetGUID());
            break;
    }
}

void SendProfTrainerMenu_guard_shattrath_aldor(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Alchemy
            player->SEND_POI(-1648.5, 5534, 7, 6, 0, "Lorokeem");
            player->SEND_GOSSIP_MENU(10392, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Blacksmithing
            player->SEND_POI(-1847, 5222, 7, 6, 0, "Kradu Grimblade and Zula Slagfury");
            player->SEND_GOSSIP_MENU(10400, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Cooking
            player->SEND_POI(-2067.4, 5316.5, 7, 6, 0, "Jack Trapper");
            player->SEND_GOSSIP_MENU(10393, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Enchanting
            player->SEND_POI(-2263.5, 5563.5, 7, 6, 0, "High Enchanter Bardolan");
            player->SEND_GOSSIP_MENU(10528, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //First Aid
            player->SEND_POI(-1591, 5265.5, 7, 6, 0, "Mildred Fletcher");
            player->SEND_GOSSIP_MENU(10396, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //Jewelcrafting
            player->SEND_POI(-1654, 5667.5, 7, 6, 0, "Hamanar");
            player->SEND_GOSSIP_MENU(10529, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Leatherworking
            player->SEND_POI(-2060.5, 5256.5, 7, 6, 0, "Darmari");
            player->SEND_GOSSIP_MENU(10399, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 8:                    //Skinning
            player->SEND_POI(-2048, 5300, 7, 6, 0, "Seymour");
            player->SEND_GOSSIP_MENU(10419, _Creature->GetGUID());
            break;
    }
}

bool GossipSelect_guard_shattrath_aldor(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    switch (sender)
    {
        case GOSSIP_SENDER_MAIN:            SendDefaultMenu_guard_shattrath_aldor(player, _Creature, action); break;
        case GOSSIP_SENDER_SEC_PROFTRAIN:   SendProfTrainerMenu_guard_shattrath_aldor(player, _Creature, action); break;
        case GOSSIP_SENDER_SEC_BATTLEINFO:  SendBattleMasterMenu_guard_shattrath(player, _Creature, action); break;
    }
    return true;
}

/*******************************************************
 * guard_shattrath_aldor end
 *******************************************************/

CreatureAI* GetAI_guard_shattrath_aldor(Creature *_Creature)
{
    return new guard_shattrath_aldorAI (_Creature);
}

/*******************************************************
 * guard_shattrath_scryer
 *******************************************************/

struct TRINITY_DLL_DECL guard_shattrath_scryerAI : public guardAI
{
    guard_shattrath_scryerAI(Creature *c) : guardAI(c) {}

    uint32 Exile_Timer;
    uint32 Banish_Timer;
    uint64 playerGUID;
    bool CanTeleport;

    void Reset()
    {
        Banish_Timer = 5000;
        Exile_Timer = 8500;
        playerGUID = 0;
        CanTeleport = false;
    }

    void Aggro(Unit *who) {}

    void UpdateAI(const uint32 diff)
    {
        if(!UpdateVictim())
            return;

        if( CanTeleport )
        {
            if( Exile_Timer < diff )
            {
                if( Unit* temp = Unit::GetUnit(*m_creature,playerGUID) )
                {
                    temp->CastSpell(temp,SPELL_EXILE,true);
                    temp->CastSpell(temp,SPELL_BANISH_TELEPORT,true);
                }
                playerGUID = 0;
                Exile_Timer = 8500;
                CanTeleport = false;
            }else Exile_Timer -= diff;
        }
        else if( Banish_Timer < diff )
        {
            Unit* temp = m_creature->getVictim();
            if( temp && temp->GetTypeId() == TYPEID_PLAYER )
            {
                DoCast(temp,SPELL_BANISHED_SHATTRATH_S);
                Banish_Timer = 9000;
                playerGUID = temp->GetGUID();
                if( playerGUID )
                    CanTeleport = true;
            }
        }else Banish_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

bool GossipHello_guard_shattrath_scryer(Player *player, Creature *_Creature)
{
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_TAVERN                       , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BANK                         , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_INN                          , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_FLIGHTMASTER                 , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_MAILBOX                      , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_STABLEMASTER                 , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BATTLEMASTER                 , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_PROFTRAINER                  , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 8);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_MANALOOM                     , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 9);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ALCHEMYLAB                   , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 10);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_GEMMERCHANT                  , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);
    player->SEND_GOSSIP_MENU(10430, _Creature->GetGUID());
    return true;
}

void SendDefaultMenu_guard_shattrath_scryer(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Tavern
            player->SEND_POI(-1759.5, 5165, 7, 6, 0, "Worlds End Tavern");
            player->SEND_GOSSIP_MENU(10431, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Bank
            player->SEND_POI(-1996.6, 5363.7, 7, 6, 0, "Scryer Bank");
            player->SEND_GOSSIP_MENU(10432, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Inn
            player->SEND_POI(-2176.6, 5405.8, 7, 6, 0, "Scryer Inn");
            player->SEND_GOSSIP_MENU(10433,  _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Flight master
            player->SEND_POI(-1832, 5299, 7, 6, 0, "Shattrath Flight Master");
            player->SEND_GOSSIP_MENU(10435, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Mailbox
            player->SEND_POI(-2174.3, 5411.4, 7, 6, 0, "Scryer Mailbox");
            player->SEND_GOSSIP_MENU(10436, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //Stable master
            player->SEND_POI(-2169.9, 5405.1, 7, 6, 0, "Scryer Stable Master");
            player->SEND_GOSSIP_MENU(10437, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Battlemaster
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BATTLEMASTERALLIANCE , GOSSIP_SENDER_SEC_BATTLEINFO, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BATTLEMASTERHORDE    , GOSSIP_SENDER_SEC_BATTLEINFO, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BATTLEMASTERARENA    , GOSSIP_SENDER_SEC_BATTLEINFO, GOSSIP_ACTION_INFO_DEF + 3);
            player->SEND_GOSSIP_MENU(10438, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 8:                    //Profession master
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ALCHEMY              , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BLACKSMITHING        , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_COOKING              , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ENCHANTING           , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_FIRSTAID             , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_JEWELCRAFTING        , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 6);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_LEATHERWORKING       , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 7);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_SKINNING             , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 8);
            player->SEND_GOSSIP_MENU(10504, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 9:                    //Mana Loom
            player->SEND_POI(-2070, 5265.5, 7, 6, 0, "Mana Loom");
            player->SEND_GOSSIP_MENU(10522, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 10:                   //Alchemy Lab
            player->SEND_POI(-1648.5, 5540, 7, 6, 0, "Alchemy Lab");
            player->SEND_GOSSIP_MENU(10701, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 11:                   //Gem Merchant
            player->SEND_POI(-1645, 5669.5, 7, 6, 0, "Scryer Gem Merchant");
            player->SEND_GOSSIP_MENU(10702, _Creature->GetGUID());
            break;
    }
}

void SendProfTrainerMenu_guard_shattrath_scryer(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Alchemy
            player->SEND_POI(-1648.5, 5534, 7, 6, 0, "Lorokeem");
            player->SEND_GOSSIP_MENU(10516, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Blacksmithing
            player->SEND_POI(-1847, 5222, 7, 6, 0, "Kradu Grimblade and Zula Slagfury");
            player->SEND_GOSSIP_MENU(10517, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Cooking
            player->SEND_POI(-2067.4, 5316.5, 7, 6, 0, "Jack Trapper");
            player->SEND_GOSSIP_MENU(10518, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Enchanting
            player->SEND_POI(-2263.5, 5563.5, 7, 6, 0, "High Enchanter Bardolan");
            player->SEND_GOSSIP_MENU(10519, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //First Aid
            player->SEND_POI(-1591, 5265.5, 7, 6, 0, "Mildred Fletcher");
            player->SEND_GOSSIP_MENU(10520, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //Jewelcrafting
            player->SEND_POI(-1654, 5667.5, 7, 6, 0, "Hamanar");
            player->SEND_GOSSIP_MENU(10521, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Leatherworking
            player->SEND_POI(-2060.5, 5256.5, 7, 6, 0, "Darmari");
            player->SEND_GOSSIP_MENU(10523, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 8:                    //Skinning
            player->SEND_POI(-2048, 5300, 7, 6, 0, "Seymour");
            player->SEND_GOSSIP_MENU(10523, _Creature->GetGUID());
            break;
    }
}

bool GossipSelect_guard_shattrath_scryer(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    switch (sender)
    {
        case GOSSIP_SENDER_MAIN:            SendDefaultMenu_guard_shattrath_scryer(player, _Creature, action); break;
        case GOSSIP_SENDER_SEC_PROFTRAIN:   SendProfTrainerMenu_guard_shattrath_scryer(player, _Creature, action); break;
        case GOSSIP_SENDER_SEC_BATTLEINFO:  SendBattleMasterMenu_guard_shattrath(player, _Creature, action); break;
    }
    return true;
}

/*******************************************************
 * guard_shattrath_scryer end
 *******************************************************/

CreatureAI* GetAI_guard_shattrath_scryer(Creature *_Creature)
{
    return new guard_shattrath_scryerAI (_Creature);
}

/*******************************************************
 * guard_silvermoon start
 *******************************************************/

bool GossipHello_guard_silvermoon(Player *player, Creature *_Creature)
{
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_AUCTIONHOUSE   , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BANK           , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_GUILDMASTER    , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_INN            , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_MAILBOX        , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_STABLEMASTER   , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_WEAPONMASTER   , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_WINDRIDER      , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 8);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BATTLEMASTER   , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 9);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_CLASSTRAINER   , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 10);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_PROFTRAINER    , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);
    player->SEND_GOSSIP_MENU(9316, _Creature->GetGUID());
    return true;
}

void SendDefaultMenu_guard_silvermoon(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Auction house
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_AH_SILVERMOON_1 , GOSSIP_SENDER_SEC_AUCTIONHOUSE, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_AH_SILVERMOON_2 , GOSSIP_SENDER_SEC_AUCTIONHOUSE, GOSSIP_ACTION_INFO_DEF + 2);
            player->SEND_GOSSIP_MENU(9317, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Bank
            player->SEND_POI(9808.4, -7488.16, 7, 6, 0, "Silvermoon Bank");
            player->SEND_GOSSIP_MENU(9322, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Guild master
            player->SEND_POI(9474.97, -7345.21, 7, 6, 0, "Tandrine");
            player->SEND_GOSSIP_MENU(9324, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Inn
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_INN_SILVERMOON_1 , GOSSIP_SENDER_SEC_INN, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_INN_SILVERMOON_2 , GOSSIP_SENDER_SEC_INN, GOSSIP_ACTION_INFO_DEF + 2);
            player->SEND_GOSSIP_MENU(9602, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Mailbox
            player->SEND_POI(9658.33, -7492.17, 7, 6, 0, "Silvermoon Mailbox");
            player->SEND_GOSSIP_MENU(9326, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //Stable master
            player->SEND_POI(9904.95, -7404.31, 7, 6, 0, "Shalenn");
            player->SEND_GOSSIP_MENU(9327, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Weapon trainer
            player->SEND_POI(9841.17, -7505.13, 7, 6, 0, "Ileda");
            player->SEND_GOSSIP_MENU(9328, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 8:                    //Wind master
            player->SEND_POI(9378.45, -7163.94, 7, 6, 0, "Silvermoon Wind Master");
            player->SEND_GOSSIP_MENU(10181, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 9:                    //Battlemaster
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ALTERACVALLEY   , GOSSIP_SENDER_SEC_BATTLEINFO, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ARATHIBASIN     , GOSSIP_SENDER_SEC_BATTLEINFO, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ARENA           , GOSSIP_SENDER_SEC_BATTLEINFO, GOSSIP_ACTION_INFO_DEF + 3);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_EYEOFTHESTORM   , GOSSIP_SENDER_SEC_BATTLEINFO, GOSSIP_ACTION_INFO_DEF + 4);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_WARSONGULCH     , GOSSIP_SENDER_SEC_BATTLEINFO, GOSSIP_ACTION_INFO_DEF + 5);
            player->SEND_GOSSIP_MENU(9329, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 10:                   //Class trainer
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_DRUID                , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_HUNTER               , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_MAGE                 , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_PALADIN              , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_PRIEST               , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ROGUE                , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 6);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_WARLOCK              , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 7);
            player->SEND_GOSSIP_MENU(9331, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 11:                   //Profession trainer
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ALCHEMY              , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BLACKSMITHING        , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_COOKING              , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ENCHANTING           , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ENGINEERING          , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_FIRSTAID             , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 6);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_FISHING              , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 7);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_JEWELCRAFTING        , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 8);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_HERBALISM            , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 9);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_LEATHERWORKING       , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 10);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_MINING               , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 11);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_SKINNING             , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 12);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_TAILORING            , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 13);
            player->SEND_GOSSIP_MENU(9338, _Creature->GetGUID());
            break;
    }
}

void SendAuctionhouseMenu_guard_silvermoon(Player *player, Creature *_Creature, uint32 action)
{
    if (action == GOSSIP_ACTION_INFO_DEF + 1)
    {
        player->SEND_POI(9644.47, -7140.22, 7, 6, 0, "Western Auction House");
        player->SEND_GOSSIP_MENU(9318, _Creature->GetGUID());
    }
    if (action == GOSSIP_ACTION_INFO_DEF + 2)
    {
        player->SEND_POI(9683.27, -7521.22, 7, 6, 0, "Royal Exchange Auction House");
        player->SEND_GOSSIP_MENU(9319, _Creature->GetGUID());
    }
}

void SendInnMenu_guard_silvermoon(Player *player, Creature *_Creature, uint32 action)
{
    if (action == GOSSIP_ACTION_INFO_DEF + 1)
    {
        player->SEND_POI(9677.7, -7368, 7, 6, 0, "Silvermoon City Inn");
        player->SEND_GOSSIP_MENU(9325, _Creature->GetGUID());
    }
    if (action == GOSSIP_ACTION_INFO_DEF + 2)
    {
        player->SEND_POI(9561.1, -7517.5, 7, 6, 0, "Wayfarer's Rest tavern");
        player->SEND_GOSSIP_MENU(9603, _Creature->GetGUID());
    }
}

void SendBattleMasterMenu_guard_silvermoon(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //AV
            player->SEND_POI(9850.49, -7572.26, 7, 6, 0, "Gurak");
            player->SEND_GOSSIP_MENU(9329, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //AB
            player->SEND_POI(9857.18, -7564.36, 7, 6, 0, "Karen Wentworth");
            player->SEND_GOSSIP_MENU(9329,  _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //A
            player->SEND_POI(9850.6, -7559.25, 7, 6, 0, "Bipp Glizzitor");
            player->SEND_GOSSIP_MENU(9329, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //EOS
            player->SEND_POI(9857.18, -7564.36, 7, 6, 0, "Karen Wentworth");
            player->SEND_GOSSIP_MENU(9329, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //WSG
            player->SEND_POI(9845.45, -7562.58, 7, 6, 0, "Krukk");
            player->SEND_GOSSIP_MENU(9329, _Creature->GetGUID());
            break;
    }
}

void SendClassTrainerMenu_guard_silvermoon(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Druid
            player->SEND_POI(9700.55, -7262.57, 7, 6, 0, "Harene Plainwalker");
            player->SEND_GOSSIP_MENU(9330, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Hunter
            player->SEND_POI(9927.48, -7426.14, 7, 6, 0, "Zandine");
            player->SEND_GOSSIP_MENU(9332, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Mage
            player->SEND_POI(9995.07, -7118.17, 7, 6, 0, "Quithas");
            player->SEND_GOSSIP_MENU(9333, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Paladin
            player->SEND_POI(9850.22, -7516.93, 7, 6, 0, "Champion Bachi");
            player->SEND_GOSSIP_MENU(9334, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Priest
            player->SEND_POI(9926.79, -7066.66, 7, 6, 0, "Belestra");
            player->SEND_GOSSIP_MENU(9335, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //Rogue
            player->SEND_POI(9739.88, -7374.33, 7, 6, 0, "Zelanis");
            player->SEND_GOSSIP_MENU(9336, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Warlock
            player->SEND_POI(9787.57, -7284.63, 7, 6, 0, "Alamma");
            player->SEND_GOSSIP_MENU(9337, _Creature->GetGUID());
            break;
    }
}

void SendProfTrainerMenu_guard_silvermoon(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Alchemy
            player->SEND_POI(9998.09, -7214.36, 7, 6, 0, "Silvermoon Alchemy Trainer");
            player->SEND_GOSSIP_MENU(9316, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Blacksmithing
            player->SEND_POI(9841.43, -7361.53, 7, 6, 0, "Silvermoon Blacksmithing Trainer");
            player->SEND_GOSSIP_MENU(9340, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Cooking
            player->SEND_POI(9577.26, -7243.6, 7, 6, 0, "Silvermoon Cooking Trainer");
            player->SEND_GOSSIP_MENU(9316, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Enchanting
            player->SEND_POI(9962.57, -7246.18, 7, 6, 0, "Silvermoon Enchanting Trainer");
            player->SEND_GOSSIP_MENU(9341, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Engineering
            player->SEND_POI(9820.18, -7329.56, 7, 6, 0, "Silvermoon Engineering Trainer");
            player->SEND_GOSSIP_MENU(9316, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //First Aid
            player->SEND_POI(9579.8, -7343.71, 7, 6, 0, "Silvermoon First Aid Trainer");
            player->SEND_GOSSIP_MENU(9316, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Fishing
            player->SEND_POI(9602.73, -7328.3, 7, 6, 0, "Silvermoon Fishing Trainer");
            player->SEND_GOSSIP_MENU(9316, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 8:                    //Jewelcrafting
            player->SEND_POI(9553.54, -7506.43, 7, 6, 0, "Silvermoon Jewelcrafting Trainer");
            player->SEND_GOSSIP_MENU(9346, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 9:                    //Herbalism
            player->SEND_POI(10004.4, -7216.86, 7, 6, 0, "Silvermoon Herbalism Trainer");
            player->SEND_GOSSIP_MENU(9316, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 10:                   //Leatherworking
            player->SEND_POI(9503.72, -7430.16, 7, 6, 0, "Silvermoon Leatherworking Trainer");
            player->SEND_GOSSIP_MENU(9347, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 11:                   //Mining
            player->SEND_POI(9805.1, -7355.56, 7, 6, 0, "Silvermoon Mining Trainer");
            player->SEND_GOSSIP_MENU(9348, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 12:                   //Skinning
            player->SEND_POI(9513.37, -7429.4, 7, 6, 0, "Silvermoon Skinning Trainer");
            player->SEND_GOSSIP_MENU(9316, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 13:                   //Tailoring
            player->SEND_POI(9750.55, -7095.28, 7, 6, 0, "Silvermoon Tailor");
            player->SEND_GOSSIP_MENU(9350, _Creature->GetGUID());
            break;
    }
}

bool GossipSelect_guard_silvermoon(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    switch (sender)
    {
        case GOSSIP_SENDER_MAIN:                SendDefaultMenu_guard_silvermoon(player, _Creature, action); break;
        case GOSSIP_SENDER_SEC_AUCTIONHOUSE:    SendAuctionhouseMenu_guard_silvermoon(player, _Creature, action); break;
        case GOSSIP_SENDER_SEC_INN:             SendInnMenu_guard_silvermoon(player, _Creature, action); break;
        case GOSSIP_SENDER_SEC_CLASSTRAIN:      SendClassTrainerMenu_guard_silvermoon(player, _Creature, action); break;
        case GOSSIP_SENDER_SEC_PROFTRAIN:       SendProfTrainerMenu_guard_silvermoon(player, _Creature, action); break;
        case GOSSIP_SENDER_SEC_BATTLEINFO:      SendBattleMasterMenu_guard_silvermoon(player, _Creature, action); break;
    }
    return true;
}

/*******************************************************
 * guard_silvermoon end
 *******************************************************/

CreatureAI* GetAI_guard_silvermoon(Creature *_Creature)
{
    return new guardAI (_Creature);
}

/*******************************************************
 * guard_stormwind start
 *******************************************************/

bool GossipHello_guard_stormwind(Player *player, Creature *_Creature)
{
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_AUCTIONHOUSE      , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_STORMWIND_BANK    , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_DEEPRUNTRAM       , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_INN               , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_GRYPHON           , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_GUILDMASTER       , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_MAILBOX           , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_STABLEMASTER      , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 8);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_WEAPONMASTER      , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 9);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_OFFICERS          , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 10);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BATTLEMASTER      , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_CLASSTRAINER      , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 12);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_PROFTRAINER       , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 13);
    player->SEND_GOSSIP_MENU(933,_Creature->GetGUID());
    return true;
}

void SendDefaultMenu_guard_stormwind(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Auction House
            player->SEND_POI(-8811.46, 667.46, 7, 6, 0, "Stormwind Auction House");
            player->SEND_GOSSIP_MENU(3834,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Bank
            player->SEND_POI(-8916.87, 622.87, 7, 6, 0, "Stormwind Bank");
            player->SEND_GOSSIP_MENU(764,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Deeprun tram
            player->SEND_POI(-8378.88, 554.23, 7, 6, 0, "The Deeprun Tram");
            player->SEND_GOSSIP_MENU(3813,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Inn
            player->SEND_POI(-8869.0, 675.4, 7, 6, 0, "The Gilded Rose");
            player->SEND_GOSSIP_MENU(3860,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Gryphon Master
            player->SEND_POI(-8837.0, 493.5, 7, 6, 0, "Stormwind Gryphon Master");
            player->SEND_GOSSIP_MENU(879,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //Guild Master
            player->SEND_POI(-8894.0, 611.2, 7, 6, 0, "Stormwind Vistor`s Center");
            player->SEND_GOSSIP_MENU(882,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Mailbox
            player->SEND_POI(-8876.48, 649.18, 7, 6, 0, "Stormwind Mailbox");
            player->SEND_GOSSIP_MENU(3861,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 8:                    //Stable Master
            player->SEND_POI(-8433.0, 554.7, 7, 6, 0, "Jenova Stoneshield");
            player->SEND_GOSSIP_MENU(5984,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 9:                    //Weapon Trainer
            player->SEND_POI(-8797.0, 612.8, 7, 6, 0, "Woo Ping");
            player->SEND_GOSSIP_MENU(4516,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 10:                   //Officers Lounge
            player->SEND_POI(-8759.92, 399.69, 7, 6, 0, "Champions` Hall");
            player->SEND_GOSSIP_MENU(7047,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 11:                   //Battlemasters
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ALTERACVALLEY        , GOSSIP_SENDER_SEC_BATTLEINFO, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ARATHIBASIN          , GOSSIP_SENDER_SEC_BATTLEINFO, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_WARSONGULCH          , GOSSIP_SENDER_SEC_BATTLEINFO, GOSSIP_ACTION_INFO_DEF + 3);
            player->SEND_GOSSIP_MENU(7499,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 12:                   //Class trainers
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_MAGE                 , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ROGUE                , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_WARRIOR              , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_DRUID                , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_PRIEST               , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_PALADIN              , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 6);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_HUNTER               , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 7);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_WARLOCK              , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 8);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_SHAMAN               , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 9);
            player->SEND_GOSSIP_MENU(898,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 13:                   //Profession trainers
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ALCHEMY              , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BLACKSMITHING        , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_COOKING              , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ENCHANTING           , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ENGINEERING          , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_FIRSTAID             , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 6);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_FISHING              , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 7);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_HERBALISM            , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 8);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_LEATHERWORKING       , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 9);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_MINING               , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 10);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_SKINNING             , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 11);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_TAILORING            , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 12);
            player->SEND_GOSSIP_MENU(918,_Creature->GetGUID());
            break;
    }
}

void SendBattleMasterMenu_guard_stormwind(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //AV
            player->SEND_POI(-8443.88, 335.99, 7, 6, 0, "Thelman Slatefist");
            player->SEND_GOSSIP_MENU(7500, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //AB
            player->SEND_POI(-8443.88, 335.99, 7, 6, 0, "Lady Hoteshem");
            player->SEND_GOSSIP_MENU(7650, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //WSG
            player->SEND_POI(-8443.88, 335.99, 7, 6, 0, "Elfarran");
            player->SEND_GOSSIP_MENU(7501, _Creature->GetGUID());
            break;
    }
}

void SendClassTrainerMenu_guard_stormwind(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Mage
            player->SEND_POI(-9012.0, 867.6, 7, 6, 0, "Wizard`s Sanctum");
            player->SEND_GOSSIP_MENU(899,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Rogue
            player->SEND_POI(-8753.0, 367.8, 7, 6, 0, "Stormwind - Rogue House");
            player->SEND_GOSSIP_MENU(900,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Warrior
            player->SEND_POI(-8690.11, 324.85, 7, 6, 0, "Command Center");
            player->SEND_GOSSIP_MENU(901,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Druid
            player->SEND_POI(-8751.0, 1124.5, 7, 6, 0, "The Park");
            player->SEND_GOSSIP_MENU(902,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Priest
            player->SEND_POI(-8512.0, 862.4, 7, 6, 0, "Catedral Of Light");
            player->SEND_GOSSIP_MENU(903,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //Paladin
            player->SEND_POI(-8577.0, 881.7, 7, 6, 0, "Catedral Of Light");
            player->SEND_GOSSIP_MENU(904,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Hunter
            player->SEND_POI(-8413.0, 541.5, 7, 6, 0, "Hunter Lodge");
            player->SEND_GOSSIP_MENU(905,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 8:                    //Warlock
            player->SEND_POI(-8948.91, 998.35, 7, 6, 0, "The Slaughtered Lamb");
            player->SEND_GOSSIP_MENU(906,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 9:                    //Shaman
            player->SEND_POI(-9033, 550, 7, 6, 0, "Valley Of Heroes");
                                                            //incorrect id
            player->SEND_GOSSIP_MENU(2593,_Creature->GetGUID());
            break;
    }
}

void SendProfTrainerMenu_guard_stormwind(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Alchemy
            player->SEND_POI(-8988.0, 759.60, 7, 6, 0, "Alchemy Needs");
            player->SEND_GOSSIP_MENU(919,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Blacksmithing
            player->SEND_POI(-8424.0, 616.9, 7, 6, 0, "Therum Deepforge");
            player->SEND_GOSSIP_MENU(920,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Cooking
            player->SEND_POI(-8611.0, 364.6, 7, 6, 0, "Pig and Whistle Tavern");
            player->SEND_GOSSIP_MENU(921,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Enchanting
            player->SEND_POI(-8858.0, 803.7, 7, 6, 0, "Lucan Cordell");
            player->SEND_GOSSIP_MENU(941,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Engineering
            player->SEND_POI(-8347.0, 644.1, 7, 6, 0, "Lilliam Sparkspindle");
            player->SEND_GOSSIP_MENU(922,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //First Aid
            player->SEND_POI(-8513.0, 801.8, 7, 6, 0, "Shaina Fuller");
            player->SEND_GOSSIP_MENU(923,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Fishing
            player->SEND_POI(-8803.0, 767.5, 7, 6, 0, "Arnold Leland");
            player->SEND_GOSSIP_MENU(940,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 8:                    //Herbalism
            player->SEND_POI(-8967.0, 779.5, 7, 6, 0, "Alchemy Needs");
            player->SEND_GOSSIP_MENU(924,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 9:                    //Leatherworking
            player->SEND_POI(-8726.0, 477.4, 7, 6, 0, "The Protective Hide");
            player->SEND_GOSSIP_MENU(925,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 10:                   //Mining
            player->SEND_POI(-8434.0, 692.8, 7, 6, 0, "Gelman Stonehand");
            player->SEND_GOSSIP_MENU(927,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 11:                   //Skinning
            player->SEND_POI(-8716.0, 469.4, 7, 6, 0, "The Protective Hide");
            player->SEND_GOSSIP_MENU(928,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 12:                   //Tailoring
            player->SEND_POI(-8938.0, 800.7, 7, 6, 0, "Duncan`s Textiles");
            player->SEND_GOSSIP_MENU(929,_Creature->GetGUID());
            break;
    }
}

bool GossipSelect_guard_stormwind(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    switch (sender)
    {
        case GOSSIP_SENDER_MAIN:            SendDefaultMenu_guard_stormwind(player, _Creature, action); break;
        case GOSSIP_SENDER_SEC_CLASSTRAIN:  SendClassTrainerMenu_guard_stormwind(player, _Creature, action); break;
        case GOSSIP_SENDER_SEC_PROFTRAIN:   SendProfTrainerMenu_guard_stormwind(player, _Creature, action); break;
        case GOSSIP_SENDER_SEC_BATTLEINFO:  SendBattleMasterMenu_guard_stormwind(player, _Creature, action); break;
    }
    return true;
}

bool ReceiveEmote_guard_stormwind(Player *player, Creature *_Creature, uint32 emote)
{
    if( player->GetTeam() == ALLIANCE )
        DoReplyToTextEmote(_Creature,emote);
    return true;
}

/*******************************************************
 * guard_stormwind end
 *******************************************************/

CreatureAI* GetAI_guard_stormwind(Creature *_Creature)
{
    return new guardAI (_Creature);
}

/*******************************************************
 * guard_teldrassil start
 *******************************************************/

bool GossipHello_guard_teldrassil(Player *player, Creature *_Creature)
{
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BANK         , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_FERRY        , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_GUILDMASTER  , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_INN          , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_STABLEMASTER , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_CLASSTRAINER , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_PROFTRAINER  , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
    player->SEND_GOSSIP_MENU(4316,_Creature->GetGUID());
    return true;
}

void SendDefaultMenu_guard_teldrassil(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Bank
            player->SEND_GOSSIP_MENU(4317,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Rut`theran
            player->SEND_GOSSIP_MENU(4318,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Guild master
            player->SEND_GOSSIP_MENU(4319,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Inn
            player->SEND_POI(9821.49, 960.13, 7, 6, 0, "Dolanaar Inn");
            player->SEND_GOSSIP_MENU(4320,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //stable master
            player->SEND_POI(9808.37, 931.1, 7, 6, 0, "Seriadne");
            player->SEND_GOSSIP_MENU(5982,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //class trainer
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_DRUID                , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_HUNTER               , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_PRIEST               , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ROGUE                , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_WARRIOR              , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            player->SEND_GOSSIP_MENU(4264,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //profession trainer
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ALCHEMY              , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_COOKING              , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ENCHANTING           , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_FIRSTAID             , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_FISHING              , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_HERBALISM            , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 6);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_LEATHERWORKING       , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 7);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_SKINNING             , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 8);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_TAILORING            , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 9);
            player->SEND_GOSSIP_MENU(4273,_Creature->GetGUID());
            break;
    }
}

void SendClassTrainerMenu_guard_teldrassil(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Druid
            player->SEND_POI(9741.58, 963.7, 7, 6, 0, "Kal");
            player->SEND_GOSSIP_MENU(4323,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Hunter
            player->SEND_POI(9815.12, 926.28, 7, 6, 0, "Dazalar");
            player->SEND_GOSSIP_MENU(4324,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Priest
            player->SEND_POI(9906.16, 986.63, 7, 6, 0, "Laurna Morninglight");
            player->SEND_GOSSIP_MENU(4325,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Rogue
            player->SEND_POI(9789, 942.86, 7, 6, 0, "Jannok Breezesong");
            player->SEND_GOSSIP_MENU(4326,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Warrior
            player->SEND_POI(9821.96, 950.61, 7, 6, 0, "Kyra Windblade");
            player->SEND_GOSSIP_MENU(4327,_Creature->GetGUID());
            break;
    }
}

void SendProfTrainerMenu_guard_teldrassil(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Alchemy
            player->SEND_POI(9767.59, 878.81, 7, 6, 0, "Cyndra Kindwhisper");
            player->SEND_GOSSIP_MENU(4329,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Cooking
            player->SEND_POI(9751.19, 906.13, 7, 6, 0, "Zarrin");
            player->SEND_GOSSIP_MENU(4330,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Enchanting
            player->SEND_POI(10677.59, 1946.56, 7, 6, 0, "Alanna Raveneye");
            player->SEND_GOSSIP_MENU(4331,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //First Aid
            player->SEND_POI(9903.12, 999, 7, 6, 0, "Byancie");
            player->SEND_GOSSIP_MENU(4332,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Fishing
            player->SEND_GOSSIP_MENU(4333,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //Herbalism
            player->SEND_POI(9773.78, 875.88, 7, 6, 0, "Malorne Bladeleaf");
            player->SEND_GOSSIP_MENU(4334,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Leatherworking
            player->SEND_POI(10152.59, 1681.46, 7, 6, 0, "Nadyia Maneweaver");
            player->SEND_GOSSIP_MENU(4335,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 8:                    //Skinning
            player->SEND_POI(10135.59, 1673.18, 7, 6, 0, "Radnaal Maneweaver");
            player->SEND_GOSSIP_MENU(4336,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 9:                    //Tailoring
            player->SEND_GOSSIP_MENU(4337,_Creature->GetGUID());
            break;
    }
}

bool GossipSelect_guard_teldrassil(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    switch (sender)
    {
        case GOSSIP_SENDER_MAIN:            SendDefaultMenu_guard_teldrassil(player, _Creature, action); break;
        case GOSSIP_SENDER_SEC_CLASSTRAIN:  SendClassTrainerMenu_guard_teldrassil(player, _Creature, action); break;
        case GOSSIP_SENDER_SEC_PROFTRAIN:   SendProfTrainerMenu_guard_teldrassil(player, _Creature, action); break;
    }
    return true;
}

/*******************************************************
 * guard_teldrassil end
 *******************************************************/

CreatureAI* GetAI_guard_teldrassil(Creature *_Creature)
{
    return new guardAI (_Creature);
}

/*******************************************************
 * guard_tirisfal start
 *******************************************************/

bool GossipHello_guard_tirisfal(Player *player, Creature *_Creature)
{
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BANK            , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BATHANDLER      , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_INN             , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_STABLEMASTER    , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_CLASSTRAINER    , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_PROFTRAINER     , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
    player->SEND_GOSSIP_MENU(4097,_Creature->GetGUID());
    return true;
}

void SendDefaultMenu_guard_tirisfal(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Bank
            player->SEND_GOSSIP_MENU(4074,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //bat handler
            player->SEND_GOSSIP_MENU(4075,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Inn
            player->SEND_POI(2246.68, 241.89, 7, 6, 0, "Gallows` End Tavern");
            player->SEND_GOSSIP_MENU(4076,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Stable Master
            player->SEND_POI(2267.66, 319.32, 7, 6, 0, "Morganus");
            player->SEND_GOSSIP_MENU(5978,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Class trainer
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_MAGE                 , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_PRIEST               , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ROGUE                , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_WARLOCK              , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_WARRIOR              , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            player->SEND_GOSSIP_MENU(4292,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //Profession trainer
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ALCHEMY              , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BLACKSMITHING        , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_COOKING              , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ENCHANTING           , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ENGINEERING          , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_FIRSTAID             , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 6);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_FISHING              , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 7);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_HERBALISM            , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 8);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_LEATHERWORKING       , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 9);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_MINING               , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 10);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_SKINNING             , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 11);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_TAILORING            , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 12);
            player->SEND_GOSSIP_MENU(4096,_Creature->GetGUID());
            break;
    }
}

void SendClassTrainerMenu_guard_tirisfal(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Mage
            player->SEND_POI(2259.18, 240.93, 7, 6, 0, "Cain Firesong");
            player->SEND_GOSSIP_MENU(4077,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Priest
            player->SEND_POI(2259.18, 240.93, 7, 6, 0, "Dark Cleric Beryl");
            player->SEND_GOSSIP_MENU(4078,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Rogue
            player->SEND_POI(2259.18, 240.93, 7, 6, 0, "Marion Call");
            player->SEND_GOSSIP_MENU(4079,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Warlock
            player->SEND_POI(2259.18, 240.93, 7, 6, 0, "Rupert Boch");
            player->SEND_GOSSIP_MENU(4080,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Warrior
            player->SEND_POI(2256.48, 240.32, 7, 6, 0, "Austil de Mon");
            player->SEND_GOSSIP_MENU(4081,_Creature->GetGUID());
            break;
    }
}

void SendProfTrainerMenu_guard_tirisfal(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Alchemy
            player->SEND_POI(2263.25, 344.23, 7, 6, 0, "Carolai Anise");
            player->SEND_GOSSIP_MENU(4082,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Blacksmithing
            player->SEND_GOSSIP_MENU(4083,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Cooking
            player->SEND_GOSSIP_MENU(4084,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Enchanting
            player->SEND_POI(2250.35, 249.12, 7, 6, 0, "Vance Undergloom");
            player->SEND_GOSSIP_MENU(4085,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Engineering
            player->SEND_GOSSIP_MENU(4086,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //First Aid
            player->SEND_POI(2246.68, 241.89, 7, 6, 0, "Nurse Neela");
            player->SEND_GOSSIP_MENU(4087,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Fishing
            player->SEND_POI(2292.37, -10.72, 7, 6, 0, "Clyde Kellen");
            player->SEND_GOSSIP_MENU(4088,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 8:                    //Herbalism
            player->SEND_POI(2268.21, 331.69, 7, 6, 0, "Faruza");
            player->SEND_GOSSIP_MENU(4089,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 9:                    //Leatherworking
            player->SEND_POI(2027, 78.72, 7, 6, 0, "Shelene Rhobart");
            player->SEND_GOSSIP_MENU(4090,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 10:                   //Mining
            player->SEND_GOSSIP_MENU(4091,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 11:                   //Skinning
            player->SEND_POI(2027, 78.72, 7, 6, 0, "Rand Rhobart");
            player->SEND_GOSSIP_MENU(4092,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 12:                   //Tailoring
            player->SEND_POI(2160.45, 659.93, 7, 6, 0, "Bowen Brisboise");
            player->SEND_GOSSIP_MENU(4093,_Creature->GetGUID());
            break;
    }
}

bool GossipSelect_guard_tirisfal(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    switch (sender)
    {
        case GOSSIP_SENDER_MAIN:            SendDefaultMenu_guard_tirisfal(player, _Creature, action); break;
        case GOSSIP_SENDER_SEC_CLASSTRAIN:  SendClassTrainerMenu_guard_tirisfal(player, _Creature, action); break;
        case GOSSIP_SENDER_SEC_PROFTRAIN:   SendProfTrainerMenu_guard_tirisfal(player, _Creature, action); break;
    }
    return true;
}

/*******************************************************
 * guard_tirisfal end
 *******************************************************/

CreatureAI* GetAI_guard_tirisfal(Creature *_Creature)
{
    return new guardAI (_Creature);
}

/*******************************************************
 * guard_undercity start
 *******************************************************/

bool GossipHello_guard_undercity(Player *player, Creature *_Creature)
{
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BANK          , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BATHANDLER    , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_GUILDMASTER   , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_INN           , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_MAILBOX       , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_AUCTIONHOUSE  , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ZEPPLINMASTER , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_WEAPONMASTER  , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 8);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_STABLEMASTER  , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 9);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BATTLEMASTER  , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 10);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_CLASSTRAINER  , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);
    player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_PROFTRAINER   , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 12);
    player->SEND_GOSSIP_MENU(3543,_Creature->GetGUID());
    return true;
}

void SendDefaultMenu_guard_undercity(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Bank
            player->SEND_POI(1595.64, 232.45, 7, 6, 0, "Undercity Bank");
            player->SEND_GOSSIP_MENU(3514,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Bat handler
            player->SEND_POI(1565.9, 271.43, 7, 6, 0, "Undercity Bat Handler");
            player->SEND_GOSSIP_MENU(3515,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Guild master
            player->SEND_POI(1594.17, 205.57, 7, 6, 0, "Undercity Guild Master");
            player->SEND_GOSSIP_MENU(3516,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Inn
            player->SEND_POI(1639.43, 220.99, 7, 6, 0, "Undercity Inn");
            player->SEND_GOSSIP_MENU(3517,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Mailbox
            player->SEND_POI(1632.68, 219.4, 7, 6, 0, "Undercity Mailbox");
            player->SEND_GOSSIP_MENU(3518,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //Auction House
            player->SEND_POI(1647.9, 258.49, 7, 6, 0, "Undercity Auction House");
            player->SEND_GOSSIP_MENU(3519,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Zeppelin
            player->SEND_POI(2059, 274.86, 7, 6, 0, "Undercity Zeppelin");
            player->SEND_GOSSIP_MENU(3520,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 8:                    //Weapon Master
            player->SEND_POI(1670.31, 324.66, 7, 6, 0, "Archibald");
            player->SEND_GOSSIP_MENU(4521,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 9:                    //Stable master
            player->SEND_POI(1634.18, 226.76, 7, 6, 0, "Anya Maulray");
            player->SEND_GOSSIP_MENU(5979,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 10:                   //Battlemaster
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ALTERACVALLEY   , GOSSIP_SENDER_SEC_BATTLEINFO, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ARATHIBASIN     , GOSSIP_SENDER_SEC_BATTLEINFO, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_WARSONGULCH     , GOSSIP_SENDER_SEC_BATTLEINFO, GOSSIP_ACTION_INFO_DEF + 3);
            player->SEND_GOSSIP_MENU(7527,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 11:                   //Class trainer
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_MAGE            , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_PRIEST          , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ROGUE           , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_WARLOCK         , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_WARRIOR         , GOSSIP_SENDER_SEC_CLASSTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            player->SEND_GOSSIP_MENU(3542,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 12:                   //Profession trainer
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ALCHEMY         , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_BLACKSMITHING   , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_COOKING         , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 3);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ENCHANTING      , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 4);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_ENGINEERING     , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 5);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_FIRSTAID        , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 6);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_FISHING         , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 7);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_HERBALISM       , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 8);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_LEATHERWORKING  , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 9);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_MINING          , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 10);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_SKINNING        , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 11);
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_TEXT_TAILORING       , GOSSIP_SENDER_SEC_PROFTRAIN, GOSSIP_ACTION_INFO_DEF + 12);
            player->SEND_GOSSIP_MENU(3541,_Creature->GetGUID());
            break;
    }
}

void SendBattleMasterMenu_guard_undercity(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //AV
            player->SEND_POI(1329, 333.92, 7, 6, 0, "Grizzle Halfmane");
            player->SEND_GOSSIP_MENU(7525,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //AB
            player->SEND_POI(1283.3, 287.16, 7, 6, 0, "Sir Malory Wheeler");
            player->SEND_GOSSIP_MENU(7646,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //WSG
            player->SEND_POI(1265, 351.18, 7, 6, 0, "Kurden Bloodclaw");
            player->SEND_GOSSIP_MENU(7526,_Creature->GetGUID());
            break;
    }
}

void SendClassTrainerMenu_guard_undercity(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Mage
            player->SEND_POI(1781, 53, 7, 6, 0, "Undercity Mage Trainers");
            player->SEND_GOSSIP_MENU(3513,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Priest
            player->SEND_POI(1758.33, 401.5, 7, 6, 0, "Undercity Priest Trainers");
            player->SEND_GOSSIP_MENU(3521,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Rogue
            player->SEND_POI(1418.56, 65, 7, 6, 0, "Undercity Rogue Trainers");
            player->SEND_GOSSIP_MENU(3524,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Warlock
            player->SEND_POI(1780.92, 53.16, 7, 6, 0, "Undercity Warlock Trainers");
            player->SEND_GOSSIP_MENU(3526,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Warrior
            player->SEND_POI(1775.59, 418.19, 7, 6, 0, "Undercity Warrior Trainers");
            player->SEND_GOSSIP_MENU(3527,_Creature->GetGUID());
            break;
    }
}

void SendProfTrainerMenu_guard_undercity(Player *player, Creature *_Creature, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF + 1:                    //Alchemy
            player->SEND_POI(1419.82, 417.19, 7, 6, 0, "The Apothecarium");
            player->SEND_GOSSIP_MENU(3528,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:                    //Blacksmithing
            player->SEND_POI(1696, 285, 7, 6, 0, "Undercity Blacksmithing Trainer");
            player->SEND_GOSSIP_MENU(3529,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:                    //Cooking
            player->SEND_POI(1596.34, 274.68, 7, 6, 0, "Undercity Cooking Trainer");
            player->SEND_GOSSIP_MENU(3530,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 4:                    //Enchanting
            player->SEND_POI(1488.54, 280.19, 7, 6, 0, "Undercity Enchanting Trainer");
            player->SEND_GOSSIP_MENU(3531,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 5:                    //Engineering
            player->SEND_POI(1408.58, 143.43, 7, 6, 0, "Undercity Engineering Trainer");
            player->SEND_GOSSIP_MENU(3532,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 6:                    //First Aid
            player->SEND_POI(1519.65, 167.19, 7, 6, 0, "Undercity First Aid Trainer");
            player->SEND_GOSSIP_MENU(3533,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 7:                    //Fishing
            player->SEND_POI(1679.9, 89, 7, 6, 0, "Undercity Fishing Trainer");
            player->SEND_GOSSIP_MENU(3534,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 8:                    //Herbalism
            player->SEND_POI(1558, 349.36, 7, 6, 0, "Undercity Herbalism Trainer");
            player->SEND_GOSSIP_MENU(3535,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 9:                    //Leatherworking
            player->SEND_POI(1498.76, 196.43, 7, 6, 0, "Undercity Leatherworking Trainer");
            player->SEND_GOSSIP_MENU(3536,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 10:                   //Mining
            player->SEND_POI(1642.88, 335.58, 7, 6, 0, "Undercity Mining Trainer");
            player->SEND_GOSSIP_MENU(3537,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 11:                   //Skinning
            player->SEND_POI(1498.6, 196.46, 7, 6, 0, "Undercity Skinning Trainer");
            player->SEND_GOSSIP_MENU(3538,_Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 12:                   //Tailoring
            player->SEND_POI(1689.55, 193, 7, 6, 0, "Undercity Tailoring Trainer");
            player->SEND_GOSSIP_MENU(3539,_Creature->GetGUID());
            break;
    }
}

bool GossipSelect_guard_undercity(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    switch (sender)
    {
        case GOSSIP_SENDER_MAIN:            SendDefaultMenu_guard_undercity(player, _Creature, action); break;
        case GOSSIP_SENDER_SEC_CLASSTRAIN:  SendClassTrainerMenu_guard_undercity(player, _Creature, action); break;
        case GOSSIP_SENDER_SEC_PROFTRAIN:   SendProfTrainerMenu_guard_undercity(player, _Creature, action); break;
        case GOSSIP_SENDER_SEC_BATTLEINFO:  SendBattleMasterMenu_guard_undercity(player, _Creature, action); break;
    }
    return true;
}

/*******************************************************
 * guard_undercity end
 *******************************************************/

CreatureAI* GetAI_guard_undercity(Creature *_Creature)
{
    return new guardAI (_Creature);
}

/*******************************************************
 * AddSC
 *******************************************************/

void AddSC_guards()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="guard_azuremyst";
    newscript->pGossipHello          = &GossipHello_guard_azuremyst;
    newscript->pGossipSelect         = &GossipSelect_guard_azuremyst;
    newscript->GetAI = &GetAI_guard_azuremyst;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="guard_bluffwatcher";
    newscript->pGossipHello          = &GossipHello_guard_bluffwatcher;
    newscript->pGossipSelect         = &GossipSelect_guard_bluffwatcher;
    newscript->GetAI = &GetAI_guard_bluffwatcher;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="guard_contested";
    newscript->GetAI = &GetAI_guard_contested;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="guard_darnassus";
    newscript->pGossipHello          = &GossipHello_guard_darnassus;
    newscript->pGossipSelect         = &GossipSelect_guard_darnassus;
    newscript->GetAI = &GetAI_guard_darnassus;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="guard_dunmorogh";
    newscript->pGossipHello          = &GossipHello_guard_dunmorogh;
    newscript->pGossipSelect         = &GossipSelect_guard_dunmorogh;
    newscript->GetAI = &GetAI_guard_dunmorogh;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="guard_durotar";
    newscript->pGossipHello          = &GossipHello_guard_durotar;
    newscript->pGossipSelect         = &GossipSelect_guard_durotar;
    newscript->GetAI = &GetAI_guard_durotar;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="guard_elwynnforest";
    newscript->pGossipHello          = &GossipHello_guard_elwynnforest;
    newscript->pGossipSelect         = &GossipSelect_guard_elwynnforest;
    newscript->GetAI = &GetAI_guard_elwynnforest;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="guard_eversong";
    newscript->pGossipHello          = &GossipHello_guard_eversong;
    newscript->pGossipSelect         = &GossipSelect_guard_eversong;
    newscript->GetAI = &GetAI_guard_eversong;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="guard_exodar";
    newscript->pGossipHello          = &GossipHello_guard_exodar;
    newscript->pGossipSelect         = &GossipSelect_guard_exodar;
    newscript->GetAI = &GetAI_guard_exodar;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="guard_ironforge";
    newscript->pGossipHello          = &GossipHello_guard_ironforge;
    newscript->pGossipSelect         = &GossipSelect_guard_ironforge;
    newscript->GetAI = &GetAI_guard_ironforge;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="guard_mulgore";
    newscript->pGossipHello          = &GossipHello_guard_mulgore;
    newscript->pGossipSelect         = &GossipSelect_guard_mulgore;
    newscript->GetAI = &GetAI_guard_mulgore;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="guard_orgrimmar";
    newscript->pGossipHello          = &GossipHello_guard_orgrimmar;
    newscript->pGossipSelect         = &GossipSelect_guard_orgrimmar;
    //newscript->pReceiveEmote         = &ReceiveEmote_guard_orgrimmar;
    newscript->GetAI = &GetAI_guard_orgrimmar;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="guard_shattrath";
    newscript->pGossipHello          = &GossipHello_guard_shattrath;
    newscript->pGossipSelect         = &GossipSelect_guard_shattrath;
    newscript->GetAI = &GetAI_guard_shattrath;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="guard_shattrath_aldor";
    newscript->GetAI = &GetAI_guard_shattrath_aldor;
    newscript->pGossipHello          = &GossipHello_guard_shattrath_aldor;
    newscript->pGossipSelect         = &GossipSelect_guard_shattrath_aldor;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="guard_shattrath_scryer";
    newscript->GetAI = &GetAI_guard_shattrath_scryer;
    newscript->pGossipHello          = &GossipHello_guard_shattrath_scryer;
    newscript->pGossipSelect         = &GossipSelect_guard_shattrath_scryer;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="guard_silvermoon";
    newscript->pGossipHello          = &GossipHello_guard_silvermoon;
    newscript->pGossipSelect         = &GossipSelect_guard_silvermoon;
    newscript->GetAI = &GetAI_guard_silvermoon;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="guard_stormwind";
    newscript->pGossipHello          = &GossipHello_guard_stormwind;
    newscript->pGossipSelect         = &GossipSelect_guard_stormwind;
    //newscript->pReceiveEmote         = &ReceiveEmote_guard_stormwind;
    newscript->GetAI = &GetAI_guard_stormwind;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="guard_teldrassil";
    newscript->pGossipHello          = &GossipHello_guard_teldrassil;
    newscript->pGossipSelect         = &GossipSelect_guard_teldrassil;
    newscript->GetAI = &GetAI_guard_teldrassil;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="guard_tirisfal";
    newscript->pGossipHello          = &GossipHello_guard_tirisfal;
    newscript->pGossipSelect         = &GossipSelect_guard_tirisfal;
    newscript->GetAI = &GetAI_guard_tirisfal;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="guard_undercity";
    newscript->pGossipHello          = &GossipHello_guard_undercity;
    newscript->pGossipSelect         = &GossipSelect_guard_undercity;
    newscript->GetAI = &GetAI_guard_undercity;
    newscript->RegisterSelf();
}

