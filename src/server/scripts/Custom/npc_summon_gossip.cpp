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
#include "Group.h"

class npc_summon_gossip : public CreatureScript
{
public:
    npc_summon_gossip() : CreatureScript("npc_summon_gossip") { }

    bool OnGossipHello(Player * player, Creature * creature)
    {
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Summon Group", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Nevermind", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
        player->SEND_GOSSIP_MENU(1, creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player * player, Creature * creature, uint32 sender, uint32 actions)
    {
        if(sender == GOSSIP_SENDER_MAIN)
        {
            switch(actions)
            {
            case GOSSIP_ACTION_INFO_DEF+1:
                {
                    Group * group = player->GetGroup();
                    if(!group) // If the player isn't in a group
                    {
                        player->MonsterWhisper("You aren't in a group!", player->GetGUID());
                        player->PlayerTalkClass->SendCloseGossip(); // Closing the gossip menu
                        return false;
                    }

                    if(group->IsLeader(player->GetGUID())) // If the current player is this group's leader
                    {
                        for (GroupReference* itr = group->GetFirstMember(); itr != NULL; itr = itr->next())
                        {
                            Player * plr = itr->getSource();

                            if (!plr || !plr->GetSession())
                                continue;

                            if(plr->GetGUID() ==player->GetGUID())
                                continue;

                            if (plr->IsBeingTeleported()) // If is being teleported..
                                continue;

                            if (plr->isInFlight()) // Is the player in flight?
                            {
                                plr->GetMotionMaster()->MovementExpired();
                                plr->CleanupAfterTaxiFlight();
                            }
                            else
                                plr->SaveRecallPosition();



                            plr->SetSummonPoint(player->GetMapId(), player->GetPositionX(), player->GetPositionY(), player->GetPositionZ());
                            WorldPacket data(SMSG_SUMMON_REQUEST, 8+4+4);
                            data << uint64(player->GetGUID());                    // summoner guid
                            data << uint32(player->GetZoneId());                  // summoner zone
                            data << uint32(MAX_PLAYER_SUMMON_DELAY*IN_MILLISECONDS); // auto decline after msecs
                            plr->GetSession()->SendPacket(&data);
                        }
                    }
                    else
                    {
                        player->MonsterWhisper("You aren't the leader of this group!", player->GetGUID());
                        player->PlayerTalkClass->SendCloseGossip();
                    }
                }break;

            case GOSSIP_ACTION_INFO_DEF+2:
                player->PlayerTalkClass->SendCloseGossip();
                break;
            }
        }
        return true;
    }
};

void AddSC_summon_setup()
{
    new npc_summon_gossip;
}