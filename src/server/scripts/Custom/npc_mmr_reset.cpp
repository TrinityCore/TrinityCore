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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "WorldPacket.h"
#include "ScriptPCH.h"
#include "ObjectMgr.h"
#include "ArenaTeam.h"
#include "ArenaTeamMgr.h"
#include "World.h"
#include "Player.h"
#include "WorldSession.h"
#include "Group.h"
#include "ObjectAccessor.h"
#include "Unit.h"

class npc_mmr_reset : public CreatureScript
{
    public:
        npc_mmr_reset() : CreatureScript("npc_mmr_reset") { }

        uint16* GetMmr(Player *player)
        {
            uint16 *mmr = new uint16[3];
            mmr[0] = 0;
            mmr[1] = 0;
            mmr[2] = 0;
            for(int x = 0; x < 3; x++)
            {
                if (ArenaTeam *twos = sArenaTeamMgr->GetArenaTeamById(player->GetArenaTeamId(x)))
                {
                    ArenaTeamMember *member = twos->GetMember(player->GetGUID());
                    if (player->GetGUID() == twos->GetCaptain())
                    {
                        mmr[x] = 0;
                    }
                    else
                    {
                        mmr[x] = twos->GetMember(player->GetGUID())->MatchMakerRating;
                    }
                }
                else
                {
                    mmr[x] = 0;
                }
            }
            return mmr;
        }

        bool ChangeMmr(Player *player, int slot, int value)
        {
            if (ArenaTeam *team = sArenaTeamMgr->GetArenaTeamById(player->GetArenaTeamId(slot)))
            {
                ArenaTeamMember *member = team->GetMember(player->GetGUID());
                member->MatchMakerRating = value;
                member->ModifyMatchmakerRating(value - (int)member->MatchMakerRating, slot);
                team->SaveToDB();
                team->DelMember(player->GetGUID(), true);
                team->SaveToDB();
                return true;
            }
            return false;
        }

        bool OnGossipHello(Player *player, Creature *_creature)
        {
            uint16 *mmr = GetMmr(player);

            if (mmr[0] > 0)
            {
                if (mmr[0] >= 1950)
                    player->ADD_GOSSIP_ITEM(0, "Lower 2v2 MMR to 1950 and leave team!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                else
                    player->ADD_GOSSIP_ITEM(0, "Reset 2v2 MMR to 1500 and leave team!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            }

            if (mmr[1] > 0)
            {
                if (mmr[1] >= 1800)
                    player->ADD_GOSSIP_ITEM(0, "Lower 3v3 MMR to 1800 and leave team!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
                else
                    player->ADD_GOSSIP_ITEM(0, "Reset 3v3 MMR to 1500 and leave team!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
            }

            if (mmr[2] > 0)
            {
                if (mmr[1] >= 1650)
                    player->ADD_GOSSIP_ITEM(0, "Lower 5v5 MMR to 1650 and leave team!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
                else
                    player->ADD_GOSSIP_ITEM(0, "Reset 5v5 MMR to 1500 and leave team!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
            }

            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Bye", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+7);
            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());
            return true;
        }

        bool OnGossipSelect(Player *player, Creature *_creature, uint32 sender, uint32 action)
        {
            if (action < GOSSIP_ACTION_INFO_DEF + 7)
            {
                uint16 *mmr = GetMmr(player);
                switch (action - GOSSIP_ACTION_INFO_DEF)
                {
                    case 1: // reset 2v2 mmr to 1500
                        if (mmr[0] > 0)
                        {
                            if (ChangeMmr(player, 0, 1500))
                            {
                                player->SaveToDB();
                            }
                        }
                        break;
                    case 2: // reset 2v2 mmr to 1950
                        if (mmr[0] >= 1950)
                        {
                            if (ChangeMmr(player, 0, 1950))
                            {
                                player->SaveToDB();
                            }
                        }
                        break;
                    case 3: // reset 3v3 mmr to 1500
                        if (mmr[1] > 0)
                        {
                            if (ChangeMmr(player, 1, 1500))
                            {
                                player->SaveToDB();
                            }
                        }
                        break;
                    case 4: // reset 3v3 mmr to 1750
                        if (mmr[1] >= 1800)
                        {
                            if (ChangeMmr(player, 1, 1800))
                            {
                                player->SaveToDB();
                            }
                        }
                        break;
                    case 5: // reset 5v5 mmr to 1500
                        if (mmr[2] > 0)
                        {
                            if (ChangeMmr(player, 2, 1500))
                            {
                                player->SaveToDB();
                            }
                        }
                        break;
                    case 6: // reset 5v5 mmr to 1650
                        if (mmr[2] >= 1650)
                        {
                            if (ChangeMmr(player, 2, 1650))
                            {
                                player->SaveToDB();
                            }
                        }
                        break;
                    default:
                        break;
                }
            }

            player->CLOSE_GOSSIP_MENU();
            return true;
        }
};

void AddSC_npc_mmr_reset()
{
    new npc_mmr_reset;
}
