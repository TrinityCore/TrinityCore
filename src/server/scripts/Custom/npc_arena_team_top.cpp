/*******************************************************************************************
*              _   _                                      __   _                           *
*              | \ | |   ___    _ __ ___    ___    ___    / _| | |_                        *
*              |  \| |  / _ \  | '_ ` _ \  / __|  / _ \  | |_  | __|                       *
*              | |\  | | (_) | | | | | | | \__ \ | (_) | |  _| | |_                        *
*              |_| \_|  \___/  |_| |_| |_| |___/  \___/  |_|    \__|                       *
*                               The policy of Nomsoftware states: Releasing our software   *
*                               or any other files are protected. You cannot re-release    * 
*                               anywhere unless you were given permission.                 *
*                           (C) Nomsoftware 2011-2012. All rights reserved.                *
********************************************************************************************/

#include "ScriptPCH.h"
using namespace std;

class npc_arena_team_top : public CreatureScript
{
    public:
        npc_arena_team_top() : CreatureScript("npc_arena_team_top") { }

        bool OnGossipHello(Player * player, Creature * creature)
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "View top 10 2v2 Arena Teams", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "View top 10 3v3 Arena Teams", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "View top 10 5v5 Arena Teams", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Nevermind", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+4);
            player->SEND_GOSSIP_MENU(1, creature->GetGUID());
            return true;
        }

        bool OnGossipSelect(Player * player, Creature * creature, uint32 sender, uint32 actions)
        {
            if (sender == GOSSIP_SENDER_MAIN)
            {
                switch (actions)
                {
                    case GOSSIP_ACTION_INFO_DEF+1:
                    {
                        QueryResult result = CharacterDatabase.Query("SELECT `name`, `rating` FROM `arena_team` WHERE type = '2' ORDER BY `rating` DESC LIMIT 10");
                        if (!result)
                            return false;

                        Field * fields = NULL;
                        player->MonsterWhisper("|cffFFFF00Here are the Top 10 2v2 arena teams:|r", player->GetGUID());
                        do
                        {
                            fields = result->Fetch();
                            string arena_name = fields[0].GetString();
                            string rating = fields[1].GetString();
                            char msg[250];
                            snprintf(msg, 250, "|cff00FFE6Team Name:|r |cffFFFF00%s|r, |cff00FFE6Team Rating:|r |cffFFFF00%s|r \n", arena_name.c_str(), rating.c_str());
                            player->MonsterWhisper(msg, player->GetGUID());
                        }

                        while (result->NextRow());
                    } break;

                    case GOSSIP_ACTION_INFO_DEF+2:
                    {
                        QueryResult result = CharacterDatabase.Query("SELECT `name`, `rating` FROM `arena_team` WHERE type = '3' ORDER BY `rating` DESC LIMIT 10");
                        if (!result)
                            return false;

                        Field * fields = NULL;
                        player->MonsterWhisper("|cffFFFF00Here are the Top 10 3v3 arena teams:|r", player->GetGUID());
                        do
                        {
                            fields = result->Fetch();
                            string arena_name = fields[0].GetString();
                            string rating = fields[1].GetString();
                            char msg[250];
                            snprintf(msg, 250, "|cff00FFE6Team Name:|r |cffFFFF00%s|r, |cff00FFE6Team Rating:|r |cffFFFF00%s|r \n", arena_name.c_str(), rating.c_str());
                            player->MonsterWhisper(msg, player->GetGUID());
                        }

                        while (result->NextRow());
                    } break;

                    case GOSSIP_ACTION_INFO_DEF+3:
                    {
                        QueryResult result = CharacterDatabase.Query("SELECT `name`, `rating` FROM `arena_team` WHERE type = '5' ORDER BY `rating` DESC LIMIT 10");
                        if (!result)
                            return false;

                        Field * fields = NULL;
                        player->MonsterWhisper("|cffFFFF00Here are the Top 10 5v5 arena teams:|r", player->GetGUID());
                        do
                        {
                            fields = result->Fetch();
                            string arena_name = fields[0].GetString();
                            string rating = fields[1].GetString();
                            char msg[250];
                            snprintf(msg, 250, "|cff00FFE6Team Name:|r |cffFFFF00%s|r, |cff00FFE6Team Rating:|r |cffFFFF00%s|r \n", arena_name.c_str(), rating.c_str());
                            player->MonsterWhisper(msg, player->GetGUID());
                        }

                        while (result->NextRow());
                    } break;

                    case GOSSIP_ACTION_INFO_DEF+4:
                    {
                        player->PlayerTalkClass->SendCloseGossip();
                    } break;
                }
            }
            return true;
        }
};

void AddSC_npc_arena_setup()
{
    new npc_arena_team_top;
}
