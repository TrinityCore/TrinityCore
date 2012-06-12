/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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
 * Interaction between core and LFGScripts
 */

#include "Common.h"
#include "SharedDefines.h"
#include "Player.h"
#include "Group.h"
#include "ScriptPCH.h"
#include "LFGScripts.h"
#include "LFGMgr.h"

LFGPlayerScript::LFGPlayerScript() : PlayerScript("LFGPlayerScript")
{
}

void LFGPlayerScript::OnLevelChanged(Player* player, uint8 /*oldLevel*/)
{
    sLFGMgr->InitializeLockedDungeons(player);
}

void LFGPlayerScript::OnLogout(Player* player)
{
    sLFGMgr->Leave(player);
    LfgUpdateData updateData = LfgUpdateData(LFG_UPDATETYPE_REMOVED_FROM_QUEUE);
    player->GetSession()->SendLfgUpdateParty(updateData);
    player->GetSession()->SendLfgUpdatePlayer(updateData);
    player->GetSession()->SendLfgUpdateSearch(false);
    uint64 guid = player->GetGUID();
    // TODO - Do not remove, add timer before deleting
    sLFGMgr->RemovePlayerData(guid);
}

void LFGPlayerScript::OnLogin(Player* player)
{
    sLFGMgr->InitializeLockedDungeons(player);
    // TODO - Restore LfgPlayerData and send proper status to player if it was in a group
}

void LFGPlayerScript::OnBindToInstance(Player* player, Difficulty difficulty, uint32 mapId, bool /*permanent*/)
{
    MapEntry const* mapEntry = sMapStore.LookupEntry(mapId);
    if (mapEntry->IsDungeon() && difficulty > DUNGEON_DIFFICULTY_NORMAL)
        sLFGMgr->InitializeLockedDungeons(player);
}

LFGGroupScript::LFGGroupScript() : GroupScript("LFGGroupScript")
{
}

void LFGGroupScript::OnAddMember(Group* group, uint64 guid)
{
    uint64 gguid = group->GetGUID();
    if (!gguid)
        return;

    sLog->outDebug(LOG_FILTER_LFG, "LFGScripts::OnAddMember [" UI64FMTD "]: added [" UI64FMTD "]", gguid, guid);
    LfgUpdateData updateData = LfgUpdateData(LFG_UPDATETYPE_CLEAR_LOCK_LIST);
    for (GroupReference* itr = group->GetFirstMember(); itr != NULL; itr = itr->next())
    {
        if (Player* plrg = itr->getSource())
        {
            plrg->GetSession()->SendLfgUpdatePlayer(updateData);
            plrg->GetSession()->SendLfgUpdateParty(updateData);
        }
    }

    // TODO - if group is queued and new player is added convert to rolecheck without notify the current players queued
    if (sLFGMgr->GetState(gguid) == LFG_STATE_QUEUED)
        sLFGMgr->Leave(NULL, group);

    if (sLFGMgr->GetState(guid) == LFG_STATE_QUEUED)
        if (Player* player = ObjectAccessor::FindPlayer(guid))
            sLFGMgr->Leave(player);
}

void LFGGroupScript::OnRemoveMember(Group* group, uint64 guid, RemoveMethod method, uint64 kicker, char const* reason)
{
    uint64 gguid = group->GetGUID();
    if (!gguid || method == GROUP_REMOVEMETHOD_DEFAULT)
        return;

    sLog->outDebug(LOG_FILTER_LFG, "LFGScripts::OnRemoveMember [" UI64FMTD "]: remove [" UI64FMTD "] Method: %d Kicker: [" UI64FMTD "] Reason: %s", gguid, guid, method, kicker, (reason ? reason : ""));
    if (sLFGMgr->GetState(gguid) == LFG_STATE_QUEUED)
    {
        // TODO - Do not remove, just remove the one leaving and rejoin queue with all other data
        sLFGMgr->Leave(NULL, group);
    }

    if (!group->isLFGGroup())
        return;

    if (method == GROUP_REMOVEMETHOD_KICK)                 // Player have been kicked
    {
        // TODO - Update internal kick cooldown of kicker
        std::string str_reason = "";
        if (reason)
            str_reason = std::string(reason);
        sLFGMgr->InitBoot(group, kicker, guid, str_reason);
        return;
    }

    uint32 state = sLFGMgr->GetState(gguid);
    sLFGMgr->ClearState(guid);
    sLFGMgr->SetState(guid, LFG_STATE_NONE);
    if (Player* player = ObjectAccessor::FindPlayer(guid))
    {
        if (method == GROUP_REMOVEMETHOD_LEAVE && state != LFG_STATE_FINISHED_DUNGEON && player->HasAura(LFG_SPELL_DUNGEON_COOLDOWN))
            player->CastSpell(player, LFG_SPELL_DUNGEON_DESERTER, false);
        /*
        else if (group->isLfgKickActive())
            // Update internal kick cooldown of kicked
        */

        LfgUpdateData updateData = LfgUpdateData(LFG_UPDATETYPE_LEADER);
        player->GetSession()->SendLfgUpdateParty(updateData);
        if (player->GetMap()->IsDungeon())                    // Teleport player out the dungeon
            sLFGMgr->TeleportPlayer(player, true);
    }

    if (state != LFG_STATE_FINISHED_DUNGEON)// Need more players to finish the dungeon
        sLFGMgr->OfferContinue(group);
}

void LFGGroupScript::OnDisband(Group* group)
{
    uint64 gguid = group->GetGUID();
    sLog->outDebug(LOG_FILTER_LFG, "LFGScripts::OnDisband [" UI64FMTD "]", gguid);

    sLFGMgr->RemoveGroupData(gguid);
}

void LFGGroupScript::OnChangeLeader(Group* group, uint64 newLeaderGuid, uint64 oldLeaderGuid)
{
    uint64 gguid = group->GetGUID();
    if (!gguid)
        return;

    sLog->outDebug(LOG_FILTER_LFG, "LFGScripts::OnChangeLeader [" UI64FMTD "]: old [" UI64FMTD "] new [" UI64FMTD "]", gguid, newLeaderGuid, oldLeaderGuid);
    Player* player = ObjectAccessor::FindPlayer(newLeaderGuid);

    LfgUpdateData updateData = LfgUpdateData(LFG_UPDATETYPE_LEADER);
    if (player)
        player->GetSession()->SendLfgUpdateParty(updateData);

    player = ObjectAccessor::FindPlayer(oldLeaderGuid);
    if (player)
    {
        updateData.updateType = LFG_UPDATETYPE_GROUP_DISBAND;
        player->GetSession()->SendLfgUpdateParty(updateData);
    }
}

void LFGGroupScript::OnInviteMember(Group* group, uint64 guid)
{
    uint64 gguid = group->GetGUID();
    if (!gguid)
        return;

    sLog->outDebug(LOG_FILTER_LFG, "LFGScripts::OnInviteMember [" UI64FMTD "]: invite [" UI64FMTD "] leader [" UI64FMTD "]", gguid, guid, group->GetLeaderGUID());
    sLFGMgr->Leave(NULL, group);
}
