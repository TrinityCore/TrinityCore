/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
 *
 *Original Script by Mindsear
 *Refactored by SPP Developer MDic
*/

#include "ScriptMgr.h"
#include "ArenaTeamMgr.h"
#include "Common.h"
#include "DisableMgr.h"
#include "BattlegroundMgr.h"
#include "Battleground.h"
#include "ArenaTeam.h"
#include "Language.h"
#include "npc_arena1v1.h"
#include "World.h"
#include "Player.h"
#include "Chat.h"
#include "WorldSession.h"
#include "Log.h"
#include "ScriptedGossip.h"
#include "ScriptedCreature.h"
#include "CreatureAI.h"
#include "Config.h"
#include "ArenaTeam.h"
#include "Language.h"

class npc_1v1arena : public CreatureScript
{
public:
    npc_1v1arena() : CreatureScript("npc_1v1arena") { }

    struct npc_1v1arenaAI : public ScriptedAI
    {
        npc_1v1arenaAI(Creature* creature) : ScriptedAI(creature) { }

        bool JoinQueueArena(Player* player, Creature* me, bool isRated)
        {
            if (!player || !me)
                return false;

            if (config_minLevel > player->GetLevel())
                return false;

            uint8 arenaslot = ArenaTeam::GetSlotByType(ARENA_TEAM_5v5);
            uint8 arenatype = ARENA_TYPE_5v5;
            uint32 arenaRating = 0;
            uint32 matchmakerRating = 0;

            // ignore if we already in BG or BG queue
            if (player->InBattleground())
                return false;

            //check existance
            Battleground* bg = sBattlegroundMgr->GetBattlegroundTemplate(BATTLEGROUND_AA);
            if (!bg)
            {
                TC_LOG_ERROR("Arena", "Battleground: template bg (all arenas) not found");
                return false;
            }

            if (DisableMgr::IsDisabledFor(DISABLE_TYPE_BATTLEGROUND, BATTLEGROUND_AA, NULL))
            {
                ChatHandler(player->GetSession()).PSendSysMessage(LANG_ARENA_DISABLED);
                return false;
            }

            BattlegroundTypeId bgTypeId = bg->GetTypeID();
            BattlegroundQueueTypeId bgQueueTypeId = BattlegroundMgr::BGQueueTypeId(bgTypeId, arenatype);
            PvPDifficultyEntry const* bracketEntry = GetBattlegroundBracketByLevel(bg->GetMapId(), player->GetLevel());
            if (!bracketEntry)
                return false;

            // check if already in queue
            if (player->GetBattlegroundQueueIndex(bgQueueTypeId) < PLAYER_MAX_BATTLEGROUND_QUEUES)
                //player is already in this queue
                return false;
            // check if has free queue slots
            if (!player->HasFreeBattlegroundQueueId())
                return false;

            uint32 ateamId = 0;

            if (isRated)
            {
                ateamId = player->GetArenaTeamId(arenaslot);
                ArenaTeam* at = sArenaTeamMgr->GetArenaTeamById(ateamId);
                if (!at)
                {
                    player->GetSession()->SendNotInArenaTeamPacket(arenatype);
                    return false;
                }

                // get the team rating for queueing
                arenaRating = at->GetRating();
                matchmakerRating = arenaRating;
                // the arenateam id must match for everyone in the group

                if (arenaRating <= 0)
                    arenaRating = 1;
            }

            BattlegroundQueue &bgQueue = sBattlegroundMgr->GetBattlegroundQueue(bgQueueTypeId);
            bg->SetRated(isRated);

            GroupQueueInfo* ginfo = bgQueue.AddGroup(player, NULL, bgTypeId, bracketEntry, arenatype, isRated, false, arenaRating, matchmakerRating, ateamId);
            uint32 avgTime = bgQueue.GetAverageQueueWaitTime(ginfo, bracketEntry->GetBracketId());
            uint32 queueSlot = player->AddBattlegroundQueueId(bgQueueTypeId);

            WorldPacket data;
            // send status packet (in queue)
            sBattlegroundMgr->BuildBattlegroundStatusPacket(&data, bg, queueSlot, STATUS_WAIT_QUEUE, avgTime, 0, arenatype, 0);
            player->GetSession()->SendPacket(&data);

            sBattlegroundMgr->ScheduleQueueUpdate(matchmakerRating, arenatype, bgQueueTypeId, bgTypeId, bracketEntry->GetBracketId());

            return true;
        }

        bool CreateArenateam(Player* player, Creature* me)
        {
            if (!player || !me)
                return false;

            uint8 slot = ArenaTeam::GetSlotByType(ARENA_TEAM_5v5);
            if (slot >= MAX_ARENA_SLOT)
                return false;

            // Check if player is already in an arena team
            if (player->GetArenaTeamId(slot))
            {
                player->GetSession()->SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, player->GetName(), "", ERR_ALREADY_IN_ARENA_TEAM);
                return false;
            }

            // Teamname = playername
            // if teamname exist, we have to choose another name (playername + number)
            int i = 1;
            std::stringstream teamName;
            teamName << player->GetName();
            do
            {
                if (sArenaTeamMgr->GetArenaTeamByName(teamName.str()) != NULL) // teamname exist, so choose another name
                {
                    teamName.str(std::string());
                    teamName << player->GetName() << (i++);
                }
                else
                    break;
            } while (i < 100); // should never happen

            // Create arena team
            ArenaTeam* arenaTeam = new ArenaTeam();

            if (!arenaTeam->Create(player->GetGUID(), ARENA_TEAM_5v5, teamName.str(), 4283124816, 45, 4294242303, 5, 4294705149))
            {
                delete arenaTeam;
                return false;
            }

            // Register arena team
            sArenaTeamMgr->AddArenaTeam(arenaTeam);
            arenaTeam->AddMember(player->GetGUID());

            ChatHandler(player->GetSession()).SendSysMessage("|cffFF4500[1v1 Arena System]:|r Arenateam successfully created!");

            return true;
        }

        bool OnGossipHello(Player* player)
        {
            if (!player || !me)
                return true;

            if (config_Enable == false)
            {
                ChatHandler(player->GetSession()).SendSysMessage("|cffFF4500[1v1 Arena System]:|r 1v1 Arena is disabled!");
                return true;
            }

            if (player->InBattlegroundQueueForBattlegroundQueueType(BATTLEGROUND_QUEUE_5v5))
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Leave queue 1v1 Arena", GOSSIP_SENDER_MAIN, 3, "Are you sure?", 0, false);
            else
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Sign up 1v1 Arena (unrated)", GOSSIP_SENDER_MAIN, 20);

            if (player->GetArenaTeamId(ArenaTeam::GetSlotByType(ARENA_TEAM_5v5)) == 0)
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Create new 1v1 Arenateam", GOSSIP_SENDER_MAIN, 1, "Create 1v1 arenateam?", config_Costs, false);
            else
            {
                if (player->InBattlegroundQueueForBattlegroundQueueType(BATTLEGROUND_QUEUE_5v5) == false)
                {
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Sign up 1v1 Arena (rated)", GOSSIP_SENDER_MAIN, 2);
                    AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Disband arenateam", GOSSIP_SENDER_MAIN, 5, "Are you sure?", 0, false);
                }

                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Show statistics", GOSSIP_SENDER_MAIN, 4);
            }

            SendGossipMenuFor(player, 68, me->GetGUID());
            return true;
        }

        bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId)
        {
            uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);

            if (!player || !me)
                return true;

            ClearGossipMenuFor(player);

            switch (action)
            {
            case 1: // Create new Arenateam
            {
                if (config_minLevel <= player->GetLevel())
                {
                    if (player->GetMoney() >= config_Costs && CreateArenateam(player, me))
                        player->ModifyMoney(config_Costs * -1);
                }
                else
                {
                    ChatHandler(player->GetSession()).PSendSysMessage("|cffFF4500[1v1 Arena System]:|r You need level %u to create a 1v1 arenateam.", config_minLevel);
                    CloseGossipMenuFor(player);
                    return true;
                }
            }
            break;

            case 2: // Join Queue Arena (rated)
            {
                if (Arena1v1CheckTalents(player) && JoinQueueArena(player, me, true) == false)
                    ChatHandler(player->GetSession()).SendSysMessage("|cffFF4500[1v1 Arena System]:|r Something went wrong while join queue.");

                CloseGossipMenuFor(player);
                return true;
            }
            break;

            case 20: // Join Queue Arena (unrated)
            {
                if (Arena1v1CheckTalents(player) && JoinQueueArena(player, me, false) == false)
                    ChatHandler(player->GetSession()).SendSysMessage("|cffFF4500[1v1 Arena System]:|r Something went wrong while join queue.");

                CloseGossipMenuFor(player);
                return true;
            }
            break;

            case 3: // Leave Queue
            {
                WorldPacket Data;
                Data << (uint8)0x1 << (uint8)0x0 << (uint32)BATTLEGROUND_AA << (uint16)0x0 << (uint8)0x0;
                player->GetSession()->HandleBattleFieldPortOpcode(Data);
                CloseGossipMenuFor(player);
                return true;
            }
            break;

            case 4: // get statistics
            {
                ArenaTeam* at = sArenaTeamMgr->GetArenaTeamById(player->GetArenaTeamId(ArenaTeam::GetSlotByType(ARENA_TEAM_5v5)));
                if (at)
                {
                    std::stringstream s;
                    s << "|cffFF4500[1v1 Arena System]:|r Your statistics ";
                    s << "\nRating: " << at->GetStats().Rating;
                    s << "\nRank: " << at->GetStats().Rank;
                    s << "\nSeason Games: " << at->GetStats().SeasonGames;
                    s << "\nSeason Wins: " << at->GetStats().SeasonWins;
                    s << "\nWeek Games: " << at->GetStats().WeekGames;
                    s << "\nWeek Wins: " << at->GetStats().WeekWins;

                    ChatHandler(player->GetSession()).PSendSysMessage(s.str().c_str());
                }
            }
            break;

            case 5: // Disband arenateam
            {
                WorldPacket Data;
                Data << (uint32)player->GetArenaTeamId(ArenaTeam::GetSlotByType(ARENA_TEAM_5v5));
                player->GetSession()->HandleArenaTeamLeaveOpcode(Data);
                ChatHandler(player->GetSession()).SendSysMessage("|cffFF4500[1v1 Arena System]:|r Arenateam deleted!");
                CloseGossipMenuFor(player);
                return true;
            }
            break;

            }

            OnGossipHello(player);
            return true;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_1v1arenaAI(creature);
    }
};

class npc_arena1v1_world : public WorldScript
{
    public:
        npc_arena1v1_world() : WorldScript("npc_arena1v1_world") {}

        void OnConfigLoad(bool reload) override
        {
            if (reload) // if gm is using .reload config command // or using .reload config on worldserver console
            {
                TC1V1CONFIG();
                TC_LOG_INFO("server.loading", "============   Re-Loaded TC Arena 1v1...  ========================");
            }
            else // On worldserver Startup
            {
                TC1V1CONFIG();
                TC_LOG_INFO("server.loading", "============   Loaded TC Arena 1v1...  ===========================");
            }
        }
};

void AddSC_npc_1v1arena()
{
    new npc_1v1arena();
    new npc_arena1v1_world();
}
