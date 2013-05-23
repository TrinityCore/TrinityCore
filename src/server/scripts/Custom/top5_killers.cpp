/*******************************************************************************************
*              ______                   ______                   _____                     *
*             / _____)                 |  ___ \                 / ___ \       _            *
*            | /  ___  ____  ____ _   _| | _ | | ___ _   _ ____| |   | |_   _| |_          *
*            | | (___)/ _  |/ ___) | | | || || |/ _ \ | | / _  ) |   | | | | |  _)         *
*            | \____/( ( | | |   | |_| | || || | |_| \ V ( (/ /| |___| | |_| | |__         *
*             \_____/ \_||_|_|    \__  |_||_||_|\___/ \_/ \____)\_____/ \____|\___)        *
*                                (____/                                                    *
*                               or any other files are protected. You cannot re-release    * 
*                               anywhere unless you were given permission.                 *
*                           (C) GaryMoveOut 2013. All rights reserved.                     *
********************************************************************************************/

#include "ScriptPCH.h"
using namespace std;  

/* Basic Menu */
#define Menu_Whisp     "Murder World Top Class killers"
#define Notification   "Murder World Top Class killers"
#define M_Whisper      "Murder World Top Class killers"
#define leave          "Nevermind"

/* Class E_Menu */
#define E_Warrior      "View top 5 Warrior Killers"
#define E_Paladin      "View top 5 Paladin Killers"
#define E_Hunter       "View top 5 Hunter Killers"
#define E_Rogue        "View top 5 Rogue Killers"
#define E_Priest       "View top 5 Priest Killers"
#define E_Shaman       "View top 5 Shaman Killers"
#define E_Mage         "View top 5 Mage Killers"
#define E_Warlock      "View top 5 Warlock Killers"
#define E_Druid        "View top 5 Druid Killers"
#define E_Death_knight "View top 5 Death knight Killers"

/* Top 5 Message */
#define M_Warrior      "Here is top 5 Warrior Killers"
#define M_Paladin      "Here is top 5 Paladin Killers"
#define M_Hunter       "Here is top 5 Hunter Killers"
#define M_Rogue        "Here is top 5 Rogue Killers"
#define M_Priest       "Here is top 5 Priest Killers"
#define M_Shaman       "Here is top 5 Shaman Killers"
#define M_Mage         "Here is top 5 Mage Killers"
#define M_Warlock      "Here is top 5 Warlock Killers"
#define M_Druid        "Here is top 5 Druid Killers"
#define M_Death_knight "Here is top 5 Death knight Killers"

class top5_killers : public CreatureScript
{
    public:
        top5_killers() : CreatureScript("top5_killers") { }

        bool OnGossipHello(Player* player, Creature* creature)
        {
            player->ADD_GOSSIP_ITEM(0, Menu_Whisp, GOSSIP_SENDER_MAIN, 0);
            player->ADD_GOSSIP_ITEM(1, E_Warrior, GOSSIP_SENDER_MAIN, 1);
            player->ADD_GOSSIP_ITEM(1, E_Paladin, GOSSIP_SENDER_MAIN, 2);
            player->ADD_GOSSIP_ITEM(1, E_Hunter, GOSSIP_SENDER_MAIN, 3);
            player->ADD_GOSSIP_ITEM(1, E_Rogue, GOSSIP_SENDER_MAIN, 4);
            player->ADD_GOSSIP_ITEM(1, E_Priest, GOSSIP_SENDER_MAIN, 5);
            player->ADD_GOSSIP_ITEM(1, E_Shaman, GOSSIP_SENDER_MAIN, 6);
            player->ADD_GOSSIP_ITEM(1, E_Mage, GOSSIP_SENDER_MAIN, 7);
            player->ADD_GOSSIP_ITEM(1, E_Warlock, GOSSIP_SENDER_MAIN, 8);
            player->ADD_GOSSIP_ITEM(1, E_Druid, GOSSIP_SENDER_MAIN, 9);
            player->ADD_GOSSIP_ITEM(1, E_Death_knight, GOSSIP_SENDER_MAIN, 10);
            player->ADD_GOSSIP_ITEM(1, leave, GOSSIP_SENDER_MAIN, 11);
            player->SEND_GOSSIP_MENU(1, creature->GetGUID());
            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)
        {
            if (sender == GOSSIP_SENDER_MAIN)
            {
                player->PlayerTalkClass->ClearMenus();

                switch (action)
                {
                    case 12:
                        player->ADD_GOSSIP_ITEM(0, Menu_Whisp, GOSSIP_SENDER_MAIN, 0);
                        player->ADD_GOSSIP_ITEM(1, E_Warrior, GOSSIP_SENDER_MAIN, 1);
                        player->ADD_GOSSIP_ITEM(1, E_Paladin, GOSSIP_SENDER_MAIN, 2);
                        player->ADD_GOSSIP_ITEM(1, E_Hunter, GOSSIP_SENDER_MAIN, 3);
                        player->ADD_GOSSIP_ITEM(1, E_Rogue, GOSSIP_SENDER_MAIN, 4);
                        player->ADD_GOSSIP_ITEM(1, E_Priest, GOSSIP_SENDER_MAIN, 5);
                        player->ADD_GOSSIP_ITEM(1, E_Shaman, GOSSIP_SENDER_MAIN, 6);
                        player->ADD_GOSSIP_ITEM(1, E_Mage, GOSSIP_SENDER_MAIN, 7);
                        player->ADD_GOSSIP_ITEM(1, E_Warlock, GOSSIP_SENDER_MAIN, 8);
                        player->ADD_GOSSIP_ITEM(1, E_Druid, GOSSIP_SENDER_MAIN, 9);
                        player->ADD_GOSSIP_ITEM(1, E_Death_knight, GOSSIP_SENDER_MAIN, 10);
                        player->ADD_GOSSIP_ITEM(1, leave, GOSSIP_SENDER_MAIN, 11);
                        player->SEND_GOSSIP_MENU(1, creature->GetGUID());
                        break;
                    case 11:
                        player->PlayerTalkClass->SendCloseGossip();
                        break;
                    case 0:
                        player->GetSession()->SendNotification(Notification);
                        ChatHandler(player->GetSession()).PSendSysMessage(M_Whisper);
                        player->PlayerTalkClass->SendGossipMenu(12, creature->GetGUID());
                        break;
                    // Warrior
                    case 1:
                    {
                        QueryResult result = CharacterDatabase.Query("SELECT name, totalKills FROM characters WHERE class = '1' ORDER BY totalKills DESC LIMIT 5");
                        if (!result)
                            return false;

                        Field * fields = NULL;
                        ChatHandler(player->GetSession()).PSendSysMessage(M_Warrior);
                        do
                        {
                            fields = result->Fetch();
                            string name = fields[0].GetString();
                            uint32 totalKills = fields[1].GetUInt32();
                            char msg[250];
                            snprintf(msg, 250, "Name: %s, With Total Kills : %u", name.c_str(), totalKills);
                            ChatHandler(player->GetSession()).PSendSysMessage(msg);
                        }
                        while(result->NextRow());
                        player->SaveToDB();
                        player->PlayerTalkClass->SendCloseGossip();
                    }
                    break;
                    // Paladin
                    case 2:
                    {
                        QueryResult result = CharacterDatabase.Query("SELECT name, totalKills FROM characters WHERE class = '2' ORDER BY totalKills DESC LIMIT 5");
                        if (!result)
                            return false;

                        Field * fields = NULL;
                        ChatHandler(player->GetSession()).PSendSysMessage(M_Paladin);
                        do
                        {
                            fields = result->Fetch();
                            string name = fields[0].GetString();
                            uint32 totalKills = fields[1].GetUInt32();
                            char msg[250];
                            snprintf(msg, 250, "Name: %s, With Total Kills : %u", name.c_str(), totalKills);
                            ChatHandler(player->GetSession()).PSendSysMessage(msg);
                        }
                        while(result->NextRow());
                        player->SaveToDB();
                        player->PlayerTalkClass->SendCloseGossip();
                    }
                    break;
                    // Hunter
                    case 3:
                    {
                        QueryResult result = CharacterDatabase.Query("SELECT name, totalKills FROM characters WHERE class = '3' ORDER BY totalKills DESC LIMIT 5");
                        if (!result)
                            return false;

                        Field * fields = NULL;
                        ChatHandler(player->GetSession()).PSendSysMessage(M_Hunter);
                        do
                        {
                            fields = result->Fetch();
                            string name = fields[0].GetString();
                            uint32 totalKills = fields[1].GetUInt32();
                            char msg[250];
                            snprintf(msg, 250, "Name: %s, With Total Kills : %u", name.c_str(), totalKills);
                            ChatHandler(player->GetSession()).PSendSysMessage(msg);
                        }
                        while(result->NextRow());
                        player->SaveToDB();
                        player->PlayerTalkClass->SendCloseGossip();
                    }
                    break;
                    // Rogue
                    case 4:
                    {
                        QueryResult result = CharacterDatabase.Query("SELECT name, totalKills FROM characters WHERE class = '4' ORDER BY totalKills DESC LIMIT 5");
                        if (!result)
                            return false;

                        Field * fields = NULL;
                        ChatHandler(player->GetSession()).PSendSysMessage(M_Rogue);
                        do
                        {
                            fields = result->Fetch();
                            string name = fields[0].GetString();
                            uint32 totalKills = fields[1].GetUInt32();
                            char msg[250];
                            snprintf(msg, 250, "Name: %s, With Total Kills : %u", name.c_str(), totalKills);
                            ChatHandler(player->GetSession()).PSendSysMessage(msg);
                        }
                        while(result->NextRow());
                        player->SaveToDB();
                        player->PlayerTalkClass->SendCloseGossip();
                    }
                    break;
                    // Priest
                    case 5:
                    {
                        QueryResult result = CharacterDatabase.Query("SELECT name, totalKills FROM characters WHERE class = '5' ORDER BY totalKills DESC LIMIT 5");
                        if (!result)
                            return false;

                        Field * fields = NULL;
                        ChatHandler(player->GetSession()).PSendSysMessage(M_Priest);
                        do
                        {
                            fields = result->Fetch();
                            string name = fields[0].GetString();
                            uint32 totalKills = fields[1].GetUInt32();
                            char msg[250];
                            snprintf(msg, 250, "Name: %s, With Total Kills : %u", name.c_str(), totalKills);
                            ChatHandler(player->GetSession()).PSendSysMessage(msg);
                        }
                        while(result->NextRow());
                        player->SaveToDB();
                        player->PlayerTalkClass->SendCloseGossip();
                    }
                    break;
                    // Shaman
                    case 6: 
                    {
                        QueryResult result = CharacterDatabase.Query("SELECT name, totalKills FROM characters WHERE class = '7' ORDER BY totalKills DESC LIMIT 5");
                        if (!result)
                            return false;

                        Field * fields = NULL;
                        ChatHandler(player->GetSession()).PSendSysMessage(M_Shaman);
                        do
                        {
                            fields = result->Fetch();
                            string name = fields[0].GetString();
                            uint32 totalKills = fields[1].GetUInt32();
                            char msg[250];
                            snprintf(msg, 250, "Name: %s, With Total Kills : %u", name.c_str(), totalKills);
                            ChatHandler(player->GetSession()).PSendSysMessage(msg);
                        }
                        while(result->NextRow());
                        player->SaveToDB();
                        player->PlayerTalkClass->SendCloseGossip();
                    }
                    break;
                    // Mage
                    case 7:
                    {
                        QueryResult result = CharacterDatabase.Query("SELECT name, totalKills FROM characters WHERE class = '8' ORDER BY totalKills DESC LIMIT 5");
                        if (!result)
                            return false;

                        Field * fields = NULL;
                        ChatHandler(player->GetSession()).PSendSysMessage(M_Mage);
                        do
                        {
                            fields = result->Fetch();
                            string name = fields[0].GetString();
                            uint32 totalKills = fields[1].GetUInt32();
                            char msg[250];
                            snprintf(msg, 250, "Name: %s, With Total Kills : %u", name.c_str(), totalKills);
                            ChatHandler(player->GetSession()).PSendSysMessage(msg);
                        }
                        while(result->NextRow());
                        player->SaveToDB();
                        player->PlayerTalkClass->SendCloseGossip();
                    }
                    break;
                    // Warlock
                    case 8:
                    {
                        QueryResult result = CharacterDatabase.Query("SELECT name, totalKills FROM characters WHERE class = '9' ORDER BY totalKills DESC LIMIT 5");
                        if (!result)
                           return false;

                        Field * fields = NULL;
                        ChatHandler(player->GetSession()).PSendSysMessage(M_Warlock);
                        do
                        {
                            fields = result->Fetch();
                            string name = fields[0].GetString();
                            uint32 totalKills = fields[1].GetUInt32();
                            char msg[250];
                            snprintf(msg, 250, "Name: %s, With Total Kills : %u", name.c_str(), totalKills);
                            ChatHandler(player->GetSession()).PSendSysMessage(msg);
                        }
                        while(result->NextRow());
                        player->SaveToDB();
                        player->PlayerTalkClass->SendCloseGossip();
                    }
                    break;
                    // Druid
                    case 9:
                    {
                        QueryResult result = CharacterDatabase.Query("SELECT name, totalKills FROM characters WHERE class = '11' ORDER BY totalKills DESC LIMIT 5");
                        if (!result)
                            return false;

                        Field * fields = NULL;
                        ChatHandler(player->GetSession()).PSendSysMessage(M_Druid);
                        do
                        {
                            fields = result->Fetch();
                            string name = fields[0].GetString();
                            uint32 totalKills = fields[1].GetUInt32();
                            char msg[250];
                            snprintf(msg, 250, "Name: %s, With Total Kills : %u", name.c_str(), totalKills);
                            ChatHandler(player->GetSession()).PSendSysMessage(msg);
                        }
                        while(result->NextRow());
                        player->SaveToDB();
                        player->PlayerTalkClass->SendCloseGossip();
                    }
                    break;
                    // Death knight
                    case 10:
                    {
                        QueryResult result = CharacterDatabase.Query("SELECT name, totalKills FROM characters WHERE class = '6' ORDER BY totalKills DESC LIMIT 5");
                        if (!result)
                            return false;

                        Field * fields = NULL;
                        ChatHandler(player->GetSession()).PSendSysMessage(M_Death_knight);
                        do
                        {
                            fields = result->Fetch();
                            string name = fields[0].GetString();
                            uint32 totalKills = fields[1].GetUInt32();
                            char msg[250];
                            snprintf(msg, 250, "Name: %s, With Total Kills : %u", name.c_str(), totalKills);
                            ChatHandler(player->GetSession()).PSendSysMessage(msg);
                        }
                        while(result->NextRow());
                        player->SaveToDB();
                        player->PlayerTalkClass->SendCloseGossip();
                        }
                        break;
                }
            }
            return true;
        }
};

void AddSC_top5_killers()
{
    new top5_killers();
}
