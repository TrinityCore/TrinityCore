/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

/*
 * Interaction between core and LFGMgr
 */

#include "ScriptPCH.h"
#include "LFGMgr.h"

class DungeonFinderScript: public GroupScript, PlayerScript
{
public:
    DungeonFinderScript(): GroupScript("DungeonFinderScript"), PlayerScript("DungeonFinderScript") { }

    void OnAddMember(Group* group, uint64 guid)
    {
        uint64 gguid = group->GetGUID();
        sLog.outDebug("OnAddMember [" UI64FMTD "]: added [" UI64FMTD "]", gguid, guid);
        if (!gguid)
            return;

        for (GroupReference *itr = group->GetFirstMember(); itr != NULL; itr = itr->next())
        {
            if (Player *plrg = itr->getSource())
            {
                plrg->GetSession()->SendLfgUpdatePlayer(LFG_UPDATETYPE_CLEAR_LOCK_LIST);
                plrg->GetSession()->SendLfgUpdateParty(LFG_UPDATETYPE_CLEAR_LOCK_LIST);
            }
        }

        if (group->isLfgQueued())
            sLFGMgr.Leave(NULL, group);

        Player *plr = sObjectMgr.GetPlayer(guid);
        if (plr && plr->isUsingLfg())
            sLFGMgr.Leave(plr);
    }

    void OnRemoveMember(Group* group, uint64 guid, RemoveMethod& method)
    {
        uint64 gguid = group->GetGUID();
        sLog.outDebug("OnRemoveMember [" UI64FMTD "]: remove [" UI64FMTD "] Method: %d", gguid, guid, method);
        if (!gguid)
            return;

        if (group->isLfgQueued())
        {
            // TODO - Do not remove, just remove the one leaving and rejoin queue with all other data
            sLFGMgr.Leave(NULL, group);
        }

        if (!group->isLFGGroup())
            return;

        if (!group->isLfgDungeonComplete())                 // Need more players to finish the dungeon
            sLFGMgr.OfferContinue(group);

        if (method == GROUP_REMOVEMETHOD_KICK)              // Player have been kicked
        {
            // TODO - Update internal kick cooldown
        }
        else
        {
            // Deserter flag
        }

        if (Player *plr = sObjectMgr.GetPlayer(guid))
        {
            plr->GetSession()->SendLfgUpdateParty(LFG_UPDATETYPE_LEADER);
            if (plr->GetMap()->IsDungeon())                 // Teleport player out the dungeon
                sLFGMgr.TeleportPlayer(plr, true);
        }
    }

    void OnDisband(Group* group)
    {
        uint64 gguid = group->GetGUID();
        sLog.outDebug("OnDisband [" UI64FMTD "]", gguid);
        if (!gguid)
            return;

        if (group->isLfgQueued())
            sLFGMgr.Leave(NULL, group);

        for (GroupReference *itr = group->GetFirstMember(); itr != NULL; itr = itr->next())
        {
            if (Player *plrg = itr->getSource())
            {
                plrg->GetSession()->SendLfgUpdateParty(LFG_UPDATETYPE_GROUP_DISBAND);
                plrg->GetSession()->SendLfgUpdateParty(LFG_UPDATETYPE_LEADER);
                if (plrg->GetMap()->IsDungeon())            // Teleport player out the dungeon
                    sLFGMgr.TeleportPlayer(plrg, true);
            }
        }
    }

    void OnChangeLeader(Group* group, uint64 newLeaderGuid, uint64 oldLeaderGuid)
    {
        uint64 gguid = group->GetGUID();
        sLog.outDebug("OnChangeLeader [" UI64FMTD "]: old [" UI64FMTD "] new [" UI64FMTD "]", gguid, newLeaderGuid, oldLeaderGuid);
        if (!gguid)
            return;

        Player *plr = sObjectMgr.GetPlayer(newLeaderGuid);
        if (plr)
            plr->GetSession()->SendLfgUpdateParty(LFG_UPDATETYPE_LEADER);

        plr = sObjectMgr.GetPlayer(oldLeaderGuid);
        if (plr)
            plr->GetSession()->SendLfgUpdateParty(LFG_UPDATETYPE_GROUP_DISBAND);
    }

    void OnInviteMember(Group* group, uint64 guid)
    {
        uint64 gguid = group->GetGUID();
        sLog.outDebug("OnInviteMember [" UI64FMTD "]: invite [" UI64FMTD "] leader [" UI64FMTD "]", gguid, guid, group->GetLeaderGUID());
        if (!gguid)
            return;

        sLFGMgr.Leave(NULL, group);
    }

    void OnLevelChanged(Player* /*player*/, uint8 /*newLevel*/)
    {
    }

    void OnLogout(Player* player)
    {
        sLFGMgr.Leave(player);
        player->GetSession()->SendLfgUpdateParty(LFG_UPDATETYPE_REMOVED_FROM_QUEUE);
        player->GetSession()->SendLfgUpdatePlayer(LFG_UPDATETYPE_REMOVED_FROM_QUEUE);
        player->GetSession()->SendLfgUpdateSearch(false);
    }
};

void AddSC_dungeon_finder()
{
    new DungeonFinderScript();
}
