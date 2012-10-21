/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/* ScriptData
Name: Arena Spectator
%Complete: 100
Comment: Script allow spectate arena games
Category: Custom Script
EndScriptData */

#include "ScriptPCH.h"
#include "Chat.h"
#include "ArenaTeamMgr.h"
#include "BattlegroundMgr.h"

class arena_spectator_commands : public CommandScript
{
    public:
        arena_spectator_commands() : CommandScript("arena_spectator_commands") { }

        static bool HandleSpectateCommand(ChatHandler* handler, const char *args)
        {
            Player* target;
            uint64 target_guid;
            std::string target_name;
            if (!handler->extractPlayerTarget((char*)args, &target, &target_guid, &target_name))
                return false;

            Player* player = handler->GetSession()->GetPlayer();
            if (target == player || target_guid == player->GetGUID())
            {
                handler->SendSysMessage(LANG_CANT_TELEPORT_SELF);
                handler->SetSentErrorMessage(true);
                return false;
            }

            if (player->isInCombat())
            {
                handler->SendSysMessage(LANG_YOU_IN_COMBAT);
                handler->SetSentErrorMessage(true);
                return false;
            }

            if (!target)
            {
                handler->SendSysMessage(LANG_PLAYER_NOT_EXIST_OR_OFFLINE);
                handler->SetSentErrorMessage(true);
                return false;
            }

            if (player->GetPet())
            {
                handler->PSendSysMessage("You must hide your pet.");
                handler->SetSentErrorMessage(true);
                return false;
            }

            if (player->GetMap()->IsBattlegroundOrArena() && !player->isSpectator())
            {
                handler->PSendSysMessage("You are already on battleground or arena.");
                handler->SetSentErrorMessage(true);
                return false;
            }

            Map* cMap = target->GetMap();
            if (!cMap->IsBattleArena())
            {
                handler->PSendSysMessage("Player didnt found in arena.");
                handler->SetSentErrorMessage(true);
                return false;
            }

            if (player->GetMap()->IsBattleground())
            {
                handler->PSendSysMessage("Cant do that while you are on battleground.");
                handler->SetSentErrorMessage(true);
                return false;
            }

            // all's well, set bg id
            // when porting out from the bg, it will be reset to 0
            player->SetBattlegroundId(target->GetBattlegroundId(), target->GetBattlegroundTypeId());
            // remember current position as entry point for return at bg end teleportation
            if (!player->GetMap()->IsBattlegroundOrArena())
                player->SetBattlegroundEntryPoint();

            if (target->isSpectator())
            {
                handler->PSendSysMessage("Can`t do that. Your target is spectator.");
                handler->SetSentErrorMessage(true);
                return false;
            }

            // stop flight if need
            if (player->isInFlight())
            {
                player->GetMotionMaster()->MovementExpired();
                player->CleanupAfterTaxiFlight();
            }
            // save only in non-flight case
            else
                player->SaveRecallPosition();

            // search for two teams
            Battleground *bGround = target->GetBattleground();
            if (bGround->isRated())
            {
                uint32 slot = bGround->GetArenaType() - 2;
                if (bGround->GetArenaType() > 3)
                    slot = 2;
                uint32 firstTeamID = target->GetArenaTeamId(slot);
                uint32 secondTeamID = 0;
                Player *firstTeamMember  = target;
                Player *secondTeamMember = NULL;
                for (Battleground::BattlegroundPlayerMap::const_iterator itr = bGround->GetPlayers().begin(); itr != bGround->GetPlayers().end(); ++itr)
                    if (Player* tmpPlayer = ObjectAccessor::FindPlayer(itr->first))
                    {
                        if (tmpPlayer->isSpectator())
                            continue;

                        uint32 tmpID = tmpPlayer->GetArenaTeamId(slot);
                        if (tmpID != firstTeamID && tmpID > 0)
                        {
                            secondTeamID = tmpID;
                            secondTeamMember = tmpPlayer;
                            break;
                        }
                    }

                if (firstTeamID > 0 && secondTeamID > 0 && secondTeamMember)
                {
                    ArenaTeam *firstTeam  = sArenaTeamMgr->GetArenaTeamById(firstTeamID);
                    ArenaTeam *secondTeam = sArenaTeamMgr->GetArenaTeamById(secondTeamID);
                    if (firstTeam && secondTeam)
                    {
                        handler->PSendSysMessage("You entered to rated arena.");
                        handler->PSendSysMessage("Teams:");
                        handler->PSendSysMessage("%s - %s", firstTeam->GetName().c_str(), secondTeam->GetName().c_str());
                        handler->PSendSysMessage("%u(%u) - %u(%u)", firstTeam->GetRating(), firstTeam->GetAverageMMR(firstTeamMember->GetGroup()),
                                                                    secondTeam->GetRating(), secondTeam->GetAverageMMR(secondTeamMember->GetGroup()));
                    }
                }
            }

            // to point to see at target with same orientation
            float x, y, z;
            target->GetContactPoint(player, x, y, z);

            player->TeleportTo(target->GetMapId(), x, y, z, player->GetAngle(target), TELE_TO_GM_MODE);
            player->SetPhaseMask(target->GetPhaseMask(), true);
            player->SetSpectate(true);
            target->GetBattleground()->AddSpectator(player->GetGUID());

            return true;
        }

        static bool HandleSpectateCancelCommand(ChatHandler* handler, const char* /*args*/)
        {
            Player* player =  handler->GetSession()->GetPlayer();

            if (!player->isSpectator())
            {
                handler->PSendSysMessage("You are not spectator.");
                handler->SetSentErrorMessage(true);
                return false;
            }

            player->GetBattleground()->RemoveSpectator(player->GetGUID());
            player->CancelSpectate();
            player->TeleportToBGEntryPoint();

            return true;
        }

        static bool HandleSpectateFromCommand(ChatHandler* handler, const char *args)
        {
            Player* target;
            uint64 target_guid;
            std::string target_name;
            if (!handler->extractPlayerTarget((char*)args, &target, &target_guid, &target_name))
                return false;

            Player* player = handler->GetSession()->GetPlayer();

            if (!target)
            {
                handler->PSendSysMessage("Cant find player.");
                handler->SetSentErrorMessage(true);
                return false;
            }

            if (!player->isSpectator())
            {
                handler->PSendSysMessage("You are not spectator, spectate someone first.");
                handler->SetSentErrorMessage(true);
                return false;
            }

            if (target->isSpectator() && target != player)
            {
                handler->PSendSysMessage("Can`t do that. Your target is spectator.");
                handler->SetSentErrorMessage(true);
                return false;
            }

            if (player->GetMap() != target->GetMap())
            {
                handler->PSendSysMessage("Cant do that. Different arenas?");
                handler->SetSentErrorMessage(true);
                return false;
            }

            // check for arena preperation
            // if exists than battle didn`t begin
            if (target->HasAura(32728) || target->HasAura(32727))
            {
                handler->PSendSysMessage("Cant do that. Arena didn`t started.");
                handler->SetSentErrorMessage(true);
                return false;
            }

            (target == player && player->getSpectateFrom()) ? player->SetViewpoint(player->getSpectateFrom(), false) :
                                                                player->SetViewpoint(target, true);
            return true;
        }

        static bool HandleSpectateResetCommand(ChatHandler* handler, const char *args)
        {
            Player* player = handler->GetSession()->GetPlayer();

            if (!player)
            {
                handler->PSendSysMessage("Cant find player.");
                handler->SetSentErrorMessage(true);
                return false;
            }

            if (!player->isSpectator())
            {
                handler->PSendSysMessage("You are not spectator!");
                handler->SetSentErrorMessage(true);
                return false;
            }

            Battleground *bGround = player->GetBattleground();
            if (!bGround)
                return false;

            if (bGround->GetStatus() != STATUS_IN_PROGRESS)
                return true;

            for (Battleground::BattlegroundPlayerMap::const_iterator itr = bGround->GetPlayers().begin(); itr != bGround->GetPlayers().end(); ++itr)
                if (Player* tmpPlayer = ObjectAccessor::FindPlayer(itr->first))
                {
                    if (tmpPlayer->isSpectator())
                        continue;

                    uint32 tmpID = bGround->GetPlayerTeam(tmpPlayer->GetGUID());

                    // generate addon massage
                    std::string pName = tmpPlayer->GetName();
                    std::string tName = "";

                    if (Player *target = tmpPlayer->GetSelectedPlayer())
                        tName = target->GetName();

                    SpectatorAddonMsg msg;
                    msg.SetPlayer(pName);
                    if (tName != "")
                        msg.SetTarget(tName);
                    msg.SetStatus(tmpPlayer->isAlive());
                    msg.SetClass(tmpPlayer->getClass());
                    msg.SetCurrentHP(tmpPlayer->GetHealth());
                    msg.SetMaxHP(tmpPlayer->GetMaxHealth());
                    Powers powerType = tmpPlayer->getPowerType();
                    msg.SetMaxPower(tmpPlayer->GetMaxPower(powerType));
                    msg.SetCurrentPower(tmpPlayer->GetPower(powerType));
                    msg.SetPowerType(powerType);
                    msg.SetTeam(tmpID);
                    msg.SendPacket(player->GetGUID());
                }

            return true;
        }

        ChatCommand* GetCommands() const
        {
            static ChatCommand spectateCommandTable[] =
            {
                { "player",         SEC_PLAYER,      true,  &HandleSpectateCommand,        "", NULL },
                { "view",           SEC_PLAYER,      true,  &HandleSpectateFromCommand,    "", NULL },
                { "reset",          SEC_PLAYER,      true,  &HandleSpectateResetCommand,   "", NULL },
                { "leave",          SEC_PLAYER,      true,  &HandleSpectateCancelCommand,  "", NULL },
                { NULL,             0,               false, NULL,                          "", NULL }
            };

            static ChatCommand commandTable[] =
            {
                { "spectate",       SEC_PLAYER, false,  NULL, "", spectateCommandTable },
                { NULL,             0,          false,  NULL, "", NULL }
            };
            return commandTable;
        }
};


enum NpcSpectatorAtions {
    // will be used for scrolling
    NPC_SPECTATOR_ACTION_LIST_GAMES         = 1000,
    NPC_SPECTATOR_ACTION_LIST_TOP_GAMES     = 2000,

    // NPC_SPECTATOR_ACTION_SELECTED_PLAYER + player.Guid()
    NPC_SPECTATOR_ACTION_SELECTED_PLAYER    = 3000
};

const uint16 TopGamesRating = 1800;
const uint8  GamesOnPage    = 10;

class npc_arena_spectator : public CreatureScript
{
    public:
        npc_arena_spectator() : CreatureScript("npc_arena_spectator") { }

        bool OnGossipHello(Player* pPlayer, Creature* pCreature)
        {
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "2x2/3x3 1800+Rating", GOSSIP_SENDER_MAIN, NPC_SPECTATOR_ACTION_LIST_TOP_GAMES);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "2x2/3x3 1000+Rating", GOSSIP_SENDER_MAIN, NPC_SPECTATOR_ACTION_LIST_GAMES);
            pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, pCreature->GetGUID());
            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
        {
            player->PlayerTalkClass->ClearMenus();
            if (action >= NPC_SPECTATOR_ACTION_LIST_GAMES && action < NPC_SPECTATOR_ACTION_LIST_TOP_GAMES)
            {
                ShowPage(player, action - NPC_SPECTATOR_ACTION_LIST_GAMES, false);
                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
            }
            else if (action >= NPC_SPECTATOR_ACTION_LIST_TOP_GAMES && action < NPC_SPECTATOR_ACTION_LIST_TOP_GAMES)
            {
                ShowPage(player, action - NPC_SPECTATOR_ACTION_LIST_TOP_GAMES, true);
                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
            }
            else
            {
                uint64 guid = action - NPC_SPECTATOR_ACTION_SELECTED_PLAYER;
                if (Player* target = ObjectAccessor::FindPlayer(guid))
                {
                    ChatHandler handler(player);
                    arena_spectator_commands::HandleSpectateCommand(&handler, target->GetName());
                }
            }
            return true;
        }

        std::string GetClassNameById(uint8 id)
        {
            std::string sClass = "";
            switch (id)
            {
                case CLASS_WARRIOR:         sClass = "Warrior ";        break;
                case CLASS_PALADIN:         sClass = "Pala ";           break;
                case CLASS_HUNTER:          sClass = "Hunt ";           break;
                case CLASS_ROGUE:           sClass = "Rogue ";          break;
                case CLASS_PRIEST:          sClass = "Priest ";         break;
                case CLASS_DEATH_KNIGHT:    sClass = "D.K. ";             break;
                case CLASS_SHAMAN:          sClass = "Shama ";          break;
                case CLASS_MAGE:            sClass = "Mage ";           break;
                case CLASS_WARLOCK:         sClass = "Warlock ";        break;
                case CLASS_DRUID:           sClass = "Druid ";          break;
            }
            return sClass;
        }

        std::string GetGamesStringData(Battleground *arena, uint16 mmr)
        {
            std::string teamsMember[BG_TEAMS_COUNT];
            uint32 firstTeamId = 0;
            for (Battleground::BattlegroundPlayerMap::const_iterator itr = arena->GetPlayers().begin(); itr != arena->GetPlayers().end(); ++itr)
                if (Player* player = ObjectAccessor::FindPlayer(itr->first))
                {
                    if (player->isSpectator())
                        continue;

                    uint32 team = itr->second.Team;
                    if (!firstTeamId)
                        firstTeamId = team;

                    teamsMember[firstTeamId == team] += GetClassNameById(player->getClass());
                }

            std::string data = teamsMember[0] + " ( ";
            std::stringstream ss;
            ss << mmr;
            data += ss.str();
            data += " ) " + teamsMember[1];
            return data;
        }

        uint64 GetFirstPlayerGuid(Battleground *arena)
        {
            for (Battleground::BattlegroundPlayerMap::const_iterator itr = arena->GetPlayers().begin(); itr != arena->GetPlayers().end(); ++itr)
                if (Player* player = ObjectAccessor::FindPlayer(itr->first))
                    return itr->first;
            return 0;
        }

        void ShowPage(Player *player, uint16 page, bool isTop)
        {
            uint16 highGames  = 0;
            uint16 lowGames   = 0;
            bool haveNextPage = false;
            for (uint8 i = BATTLEGROUND_NA; i <= BATTLEGROUND_RV; ++i)
            {
                if (!sBattlegroundMgr->IsArenaType((BattlegroundTypeId)i))
                    continue;

                BattlegroundSet bgs = sBattlegroundMgr->GetBattlegroundsByType((BattlegroundTypeId)i);
                for (BattlegroundSet::iterator itr = bgs.begin(); itr != bgs.end(); ++itr)
                {
                    Battleground* arena = itr->second;

                    if (!arena->GetPlayersSize())
                        continue;

                    uint16 mmr = arena->GetArenaMatchmakerRatingByIndex(0) + arena->GetArenaMatchmakerRatingByIndex(1);
                    mmr /= 2;

                    if (isTop && mmr >= TopGamesRating)
                    {
                        highGames++;
                        if (highGames > (page + 1) * GamesOnPage)
                        {
                            haveNextPage = true;
                            break;
                        }

                        if (highGames >= page * GamesOnPage)
                            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_BATTLE, GetGamesStringData(arena, mmr), GOSSIP_SENDER_MAIN, NPC_SPECTATOR_ACTION_SELECTED_PLAYER + GetFirstPlayerGuid(arena));
                    }
                    else if (!isTop && mmr < TopGamesRating)
                    {
                        lowGames++;
                        if (lowGames > (page + 1) * GamesOnPage)
                        {
                            haveNextPage = true;
                            break;
                        }

                        if (lowGames >= page * GamesOnPage)
                            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_BATTLE, GetGamesStringData(arena, mmr), GOSSIP_SENDER_MAIN, NPC_SPECTATOR_ACTION_SELECTED_PLAYER + GetFirstPlayerGuid(arena));
                    }
                }
            }

            if (page > 0)
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Previous", GOSSIP_SENDER_MAIN, NPC_SPECTATOR_ACTION_LIST_GAMES + page - 1);

            if (haveNextPage)
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Next", GOSSIP_SENDER_MAIN, NPC_SPECTATOR_ACTION_LIST_GAMES + page + 1);
        }
};


void AddSC_arena_spectator_script()
{
    new arena_spectator_commands();
    new npc_arena_spectator();
}
