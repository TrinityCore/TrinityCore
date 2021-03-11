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
 */

#include "WorldSession.h"
#include "ArchaeologyPackets.h"
#include "AccountMgr.h"
#include "AchievementMgr.h"
#include "Battlefield.h"
#include "BattlefieldMgr.h"
#include "Battleground.h"
#include "BattlegroundMgr.h"
#include "CharacterPackets.h"
#include "Chat.h"
#include "CinematicMgr.h"
#include "Common.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "DBCEnums.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "GameTime.h"
#include "GossipDef.h"
#include "Group.h"
#include "Guild.h"
#include "GuildMgr.h"
#include "InstanceScript.h"
#include "Language.h"
#include "Log.h"
#include "MapManager.h"
#include "MiscPackets.h"
#include "Object.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Opcodes.h"
#include "OutdoorPvP.h"
#include "Player.h"
#include "QueryPackets.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "SpellInfo.h"
#include "WhoListStorage.h"
#include "WhoPackets.h"
#include "World.h"
#include "WorldPacket.h"
#include <zlib.h>

void WorldSession::HandleRepopRequestOpcode(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "WORLD: Recvd CMSG_REPOP_REQUEST Message");

    recvData.read_skip<uint8>();

    if (GetPlayer()->IsAlive() || GetPlayer()->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_GHOST))
        return;

    if (GetPlayer()->HasAuraType(SPELL_AURA_PREVENT_RESURRECTION))
        return; // silently return, client should display the error by itself

    // the world update order is sessions, players, creatures
    // the netcode runs in parallel with all of these
    // creatures can kill players
    // so if the server is lagging enough the player can
    // release spirit after he's killed but before he is updated
    if (GetPlayer()->getDeathState() == JUST_DIED)
    {
        TC_LOG_DEBUG("network", "HandleRepopRequestOpcode: got request after player %s(%d) was killed and before he was updated",
            GetPlayer()->GetName().c_str(), GetPlayer()->GetGUID().GetCounter());
        GetPlayer()->KillPlayer();
    }

    //this is spirit release confirm?
    GetPlayer()->RemovePet(nullptr, PET_SAVE_DISMISS, true);
    GetPlayer()->BuildPlayerRepop();
    GetPlayer()->RepopAtGraveyard();
}

void WorldSession::HandleGossipSelectOptionOpcode(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "WORLD: CMSG_GOSSIP_SELECT_OPTION");

    uint32 gossipListId;
    uint32 menuId;
    ObjectGuid guid;
    std::string code = "";

    recvData >> guid >> menuId >> gossipListId;

    if (!_player->PlayerTalkClass->GetGossipMenu().GetItem(gossipListId))
    {
        recvData.rfinish();
        return;
    }

    if (_player->PlayerTalkClass->IsGossipOptionCoded(gossipListId))
        recvData >> code;

    // Prevent cheating on C++ scripted menus
    if (_player->PlayerTalkClass->GetInteractionData().SourceGuid != guid)
        return;

    Creature* unit = nullptr;
    GameObject* go = nullptr;
    if (guid.IsCreatureOrVehicle())
    {
        unit = GetPlayer()->GetNPCIfCanInteractWith(guid, UNIT_NPC_FLAG_GOSSIP);
        if (!unit)
        {
            TC_LOG_DEBUG("network", "WORLD: HandleGossipSelectOptionOpcode - %s not found or you can't interact with him.", guid.ToString().c_str());
            return;
        }
    }
    else if (guid.IsGameObject())
    {
        go = _player->GetGameObjectIfCanInteractWith(guid);
        if (!go)
        {
            TC_LOG_DEBUG("network", "WORLD: HandleGossipSelectOptionOpcode - %s not found or you can't interact with it.", guid.ToString().c_str());
            return;
        }
    }
    else
    {
        TC_LOG_DEBUG("network", "WORLD: HandleGossipSelectOptionOpcode - unsupported %s.", guid.ToString().c_str());
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    if ((unit && unit->GetScriptId() != unit->LastUsedScriptID) || (go && go->GetScriptId() != go->LastUsedScriptID))
    {
        TC_LOG_DEBUG("network", "WORLD: HandleGossipSelectOptionOpcode - Script reloaded while in use, ignoring and set new scipt id");
        if (unit)
            unit->LastUsedScriptID = unit->GetScriptId();
        if (go)
            go->LastUsedScriptID = go->GetScriptId();
        _player->PlayerTalkClass->SendCloseGossip();
        return;
    }
    if (!code.empty())
    {
        if (unit)
        {
            if (!unit->AI()->GossipSelectCode(_player, menuId, gossipListId, code.c_str()))
                _player->OnGossipSelect(unit, gossipListId, menuId);
        }
        else
        {
            if (!go->AI()->GossipSelectCode(_player, menuId, gossipListId, code.c_str()))
                _player->OnGossipSelect(go, gossipListId, menuId);
        }
    }
    else
    {
        if (unit)
        {
            if (!unit->AI()->GossipSelect(_player, menuId, gossipListId))
                _player->OnGossipSelect(unit, gossipListId, menuId);
        }
        else
        {
            if (!go->AI()->GossipSelect(_player, menuId, gossipListId))
                _player->OnGossipSelect(go, gossipListId, menuId);
        }
    }
}

void WorldSession::HandleWhoOpcode(WorldPackets::Who::WhoRequestPkt& whoRequest)
{
    WorldPackets::Who::WhoRequest& request = whoRequest.Request;

    // zones count, client limit = 10 (2.0.10)
    // can't be received from real client or broken packet
    if (whoRequest.Request.Areas.size() > 10)
        return;

    // user entered strings count, client limit=4 (checked on 2.0.10)
    // can't be received from real client or broken packet
    if (request.Words.size() > 4)
        return;

    std::vector<std::wstring> wWords;
    wWords.resize(request.Words.size());
    for (size_t i = 0; i < request.Words.size(); ++i)
    {
        TC_LOG_DEBUG("network", "WorldSession::HandleWhoOpcode: Word: %s", request.Words[i].Word.c_str());

        // user entered string, it used as universal search pattern(guild+player name)?
        if (!Utf8toWStr(request.Words[i].Word, wWords[i]))
            continue;

        wstrToLower(wWords[i]);
    }

    std::wstring wPlayerName;
    std::wstring wGuildName;

    if (!(Utf8toWStr(request.Name, wPlayerName) && Utf8toWStr(request.Guild, wGuildName)))
        return;

    wstrToLower(wPlayerName);
    wstrToLower(wGuildName);

    // client send in case not set max level value 100 but Trinity supports 255 max level,
    // update it to show GMs with characters after 100 level
    if (whoRequest.Request.MaxLevel >= MAX_LEVEL)
        whoRequest.Request.MaxLevel = STRONG_MAX_LEVEL;

    uint32 team = _player->GetTeam();

    uint32 gmLevelInWhoList = sWorld->getIntConfig(CONFIG_GM_LEVEL_IN_WHO_LIST);

    WorldPackets::Who::WhoResponsePkt response;

    WhoListInfoVector const& whoList = sWhoListStorageMgr->GetWhoList();
    for (WhoListPlayerInfo const& target : whoList)
    {
        // player can see member of other team only if has RBAC_PERM_TWO_SIDE_WHO_LIST
        if (target.GetTeam() != team && !HasPermission(rbac::RBAC_PERM_TWO_SIDE_WHO_LIST))
            continue;

        // player can see MODERATOR, GAME MASTER, ADMINISTRATOR only if has RBAC_PERM_WHO_SEE_ALL_SEC_LEVELS
        if (target.GetSecurity() > AccountTypes(gmLevelInWhoList) && !HasPermission(rbac::RBAC_PERM_WHO_SEE_ALL_SEC_LEVELS))
            continue;

        // check if target is globally visible for player
        if (_player->GetGUID() != target.GetGuid() && !target.IsVisible())
            if (AccountMgr::IsPlayerAccount(_player->GetSession()->GetSecurity()) || target.GetSecurity() > _player->GetSession()->GetSecurity())
                continue;

        // check if target's level is in level range
        uint8 lvl = target.GetLevel();
        if (lvl < request.MinLevel || lvl > request.MaxLevel)
            continue;

        // check if class matches classmask
        if (request.ClassFilter >= 0 && !(request.ClassFilter & (1 << target.GetClass())))
            continue;

        // check if race matches racemask
        if (request.RaceFilter >= 0 && (request.RaceFilter & (1 << target.GetRace())))
            continue;

        if (!whoRequest.Request.Areas.empty())
        {
            if (std::find(whoRequest.Request.Areas.begin(), whoRequest.Request.Areas.end(), target.GetZoneId()) == whoRequest.Request.Areas.end())
                continue;
        }

        std::wstring const& wTargetName = target.GetWidePlayerName();
        if (!(wPlayerName.empty() || wTargetName.find(wPlayerName) != std::wstring::npos))
            continue;

        std::wstring const& wTargetGuildName = target.GetWideGuildName();

        if (!wGuildName.empty() && wTargetGuildName.find(wGuildName) == std::wstring::npos)
            continue;

        if (!wWords.empty())
        {
            std::string aName;
            if (AreaTableEntry const* areaEntry = sAreaTableStore.LookupEntry(target.GetZoneId()))
                aName = areaEntry->AreaName[GetSessionDbcLocale()];

            bool show = false;
            for (size_t i = 0; i < wWords.size(); ++i)
            {
                if (!wWords[i].empty())
                {
                    if (wTargetName.find(wWords[i]) != std::wstring::npos ||
                        wTargetGuildName.find(wWords[i]) != std::wstring::npos ||
                        Utf8FitTo(aName, wWords[i]))
                    {
                        show = true;
                        break;
                    }
                }
            }

            if (!show)
                continue;
        }

        WorldPackets::Who::WhoEntry whoEntry;
        if (!whoEntry.PlayerData.Initialize(target.GetGuid(), nullptr))
            continue;

        if (!target.GetGuildName().empty())
            whoEntry.GuildName = target.GetGuildName();

        whoEntry.AreaID = target.GetZoneId();

        response.Response.Entries.push_back(whoEntry);

        // 50 is maximum player count sent to client - can be overridden
        // through config, but is unstable
        if (response.Response.Entries.size() >= sWorld->getIntConfig(CONFIG_MAX_WHO))
            break;
    }

    SendPacket(response.Write());
}

void WorldSession::HandleLogoutRequestOpcode(WorldPacket& /*recvData*/)
{
    TC_LOG_DEBUG("network", "WORLD: Recvd CMSG_LOGOUT_REQUEST Message, security - %u", GetSecurity());

    if (ObjectGuid lguid = GetPlayer()->GetLootGUID())
        DoLootRelease(lguid);

    bool instantLogout = (GetPlayer()->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_RESTING) && !GetPlayer()->IsInCombat()) ||
                         GetPlayer()->IsInFlight() || HasPermission(rbac::RBAC_PERM_INSTANT_LOGOUT);

    /// TODO: Possibly add RBAC permission to log out in combat
    bool canLogoutInCombat = GetPlayer()->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_RESTING);

    uint32 reason = 0;
    if (GetPlayer()->IsInCombat() && !canLogoutInCombat)
        reason = 1;
    else if (GetPlayer()->IsFalling())
        reason = 3;                                         // is jumping or falling
    else if (GetPlayer()->duel || GetPlayer()->HasAura(9454)) // is dueling or frozen by GM via freeze command
        reason = 2;                                         // FIXME - Need the correct value

    WorldPacket data(SMSG_LOGOUT_RESPONSE, 1+4);
    data << uint32(reason);
    data << uint8(instantLogout);
    SendPacket(&data);

    if (reason)
    {
        LogoutRequest(0);
        return;
    }

    // instant logout in taverns/cities or on taxi or for admins, gm's, mod's if its enabled in worldserver.conf
    if (instantLogout)
    {
        LogoutPlayer(true);
        return;
    }

    // not set flags if player can't free move to prevent lost state at logout cancel
    if (GetPlayer()->CanFreeMove())
    {
        if (GetPlayer()->GetStandState() == UNIT_STAND_STATE_STAND)
            GetPlayer()->SetStandState(UNIT_STAND_STATE_SIT);
        GetPlayer()->SetRooted(true);
        GetPlayer()->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);
    }

    LogoutRequest(GameTime::GetGameTime());
}

void WorldSession::HandlePlayerLogoutOpcode(WorldPacket& /*recvData*/)
{
    TC_LOG_DEBUG("network", "WORLD: Recvd CMSG_PLAYER_LOGOUT Message");
}

void WorldSession::HandleLogoutCancelOpcode(WorldPacket& /*recvData*/)
{
    TC_LOG_DEBUG("network", "WORLD: Recvd CMSG_LOGOUT_CANCEL Message");

    // Player have already logged out serverside, too late to cancel
    if (!GetPlayer())
        return;

    LogoutRequest(0);

    WorldPacket data(SMSG_LOGOUT_CANCEL_ACK, 0);
    SendPacket(&data);

    // not remove flags if can't free move - its not set in Logout request code.
    if (GetPlayer()->CanFreeMove())
    {
        //!we can move again
        GetPlayer()->SetRooted(false);

        //! Stand Up
        GetPlayer()->SetStandState(UNIT_STAND_STATE_STAND);

        //! DISABLE_ROTATE
        GetPlayer()->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);
    }

    TC_LOG_DEBUG("network", "WORLD: Sent SMSG_LOGOUT_CANCEL_ACK Message");
}

void WorldSession::HandleTogglePvP(WorldPacket& recvData)
{
    // this opcode can be used in two ways: Either set explicit new status or toggle old status
    if (recvData.size() == 1)
    {
        bool newPvPStatus;
        recvData >> newPvPStatus;
        GetPlayer()->ApplyModFlag(PLAYER_FLAGS, PLAYER_FLAGS_IN_PVP, newPvPStatus);
        GetPlayer()->ApplyModFlag(PLAYER_FLAGS, PLAYER_FLAGS_PVP_TIMER, !newPvPStatus);
    }
    else
    {
        GetPlayer()->ToggleFlag(PLAYER_FLAGS, PLAYER_FLAGS_IN_PVP);
        GetPlayer()->ToggleFlag(PLAYER_FLAGS, PLAYER_FLAGS_PVP_TIMER);
    }

    if (GetPlayer()->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_IN_PVP))
    {
        if (!GetPlayer()->IsPvP() || GetPlayer()->pvpInfo.EndTimer)
            GetPlayer()->UpdatePvP(true, true);
    }
    else
    {
        if (!GetPlayer()->pvpInfo.IsHostile && GetPlayer()->IsPvP())
            GetPlayer()->pvpInfo.EndTimer = GameTime::GetGameTime();     // start toggle-off
    }

    //if (OutdoorPvP* pvp = _player->GetOutdoorPvP())
    //    pvp->HandlePlayerActivityChanged(_player);
}

void WorldSession::HandleZoneUpdateOpcode(WorldPacket& recvData)
{
    uint32 newZone;
    recvData >> newZone;

    TC_LOG_DEBUG("network", "WORLD: Recvd ZONE_UPDATE: %u", newZone);

    // use server side data, but only after update the player position. See Player::UpdatePosition().
    GetPlayer()->SetNeedsZoneUpdate(true);

    //GetPlayer()->SendInitWorldStates(true, newZone);
}

void WorldSession::HandleReturnToGraveyard(WorldPacket& /*recvPacket*/)
{
    if (GetPlayer()->IsAlive() || !GetPlayer()->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_GHOST))
        return;
    GetPlayer()->RepopAtGraveyard();
}

void WorldSession::HandleRequestCemeteryList(WorldPacket& /*recvPacket*/)
{
    uint32 zoneId = _player->GetZoneId();
    uint32 team = _player->GetTeam();

    std::vector<uint32> graveyardIds;
    auto range = sObjectMgr->GraveyardStore.equal_range(zoneId);

    for (auto it = range.first; it != range.second && graveyardIds.size() < 16; ++it) // client max
    {
        if (it->second.team == 0 || it->second.team == team)
            graveyardIds.push_back(it->first);
    }

    if (graveyardIds.empty())
    {
        TC_LOG_DEBUG("network", "No graveyards found for zone %u for player %u (team %u) in CMSG_REQUEST_CEMETERY_LIST",
            zoneId, m_GUIDLow, team);
        return;
    }

    WorldPackets::Misc::RequestCemeteryListResponse packet;
    packet.IsGossipTriggered = false;
    packet.CemeteryID.reserve(graveyardIds.size());

    for (uint32 id : graveyardIds)
        packet.CemeteryID.push_back(id);

    SendPacket(packet.Write());
}

void WorldSession::HandleSetSelectionOpcode(WorldPacket& recvData)
{
    ObjectGuid guid;
    recvData >> guid;

    _player->SetSelection(guid);
}

void WorldSession::HandleStandStateChangeOpcode(WorldPacket& recvData)
{
    uint32 animstate;
    recvData >> animstate;

    switch (animstate)
    {
        case UNIT_STAND_STATE_STAND:
        case UNIT_STAND_STATE_SIT:
        case UNIT_STAND_STATE_SLEEP:
        case UNIT_STAND_STATE_KNEEL:
            break;
        default:
            return;
    }

    _player->SetStandState(animstate);
}

void WorldSession::HandleBugOpcode(WorldPacket& recvData)
{
    uint32 suggestion, contentlen, typelen;
    std::string content, type;

    recvData >> suggestion >> contentlen;
    content = recvData.ReadString(contentlen);

    recvData >> typelen;
    type = recvData.ReadString(typelen);

    if (suggestion == 0)
        TC_LOG_DEBUG("network", "WORLD: Received CMSG_BUG [Bug Report]");
    else
        TC_LOG_DEBUG("network", "WORLD: Received CMSG_BUG [Suggestion]");

    TC_LOG_DEBUG("network", "%s", type.c_str());
    TC_LOG_DEBUG("network", "%s", content.c_str());

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_BUG_REPORT);

    stmt->setString(0, type);
    stmt->setString(1, content);

    CharacterDatabase.Execute(stmt);
}

void WorldSession::HandleReclaimCorpseOpcode(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_RECLAIM_CORPSE");

    ObjectGuid guid;
    recvData >> guid;

    if (_player->IsAlive())
        return;

    // do not allow corpse reclaim in arena
    if (_player->InArena())
        return;

    // body not released yet
    if (!_player->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_GHOST))
        return;

    Corpse* corpse = _player->GetCorpse();
    if (!corpse)
        return;

    // prevent resurrect before 30-sec delay after body release not finished
    if (time_t(corpse->GetGhostTime() + _player->GetCorpseReclaimDelay(corpse->GetType() == CORPSE_RESURRECTABLE_PVP)) > GameTime::GetGameTime())
        return;

    if (!corpse->IsWithinDistInMap(_player, CORPSE_RECLAIM_RADIUS, true))
        return;

    // resurrect
    _player->ResurrectPlayer(_player->InBattleground() ? 1.0f : 0.5f);

    // spawn bones
    _player->SpawnCorpseBones();
}

void WorldSession::HandleResurrectResponseOpcode(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_RESURRECT_RESPONSE");

    ObjectGuid guid;
    uint8 status;
    recvData >> guid;
    recvData >> status;

    Player* player = GetPlayer();
    if (!player)
        return;

    if (player->IsAlive())
        return;

    if (status == 0)
    {
        player->ClearResurrectRequestData();           // reject
        return;
    }

    if (!player->IsResurrectRequestedBy(guid))
        return;

    if (Player* resurrectingPlayer = ObjectAccessor::GetPlayer(*player, guid))
    {
        if (InstanceScript* instance = resurrectingPlayer->GetInstanceScript())
        {
            if (instance->IsEncounterInProgress() && resurrectingPlayer->GetMap()->IsRaid())
            {
                if (!instance->GetCombatResurrectionCharges())
                    return;
                else
                    instance->UseCombatResurrection();
            }
        }
    }

    player->ResurrectUsingRequestData();
}

void WorldSession::SendAreaTriggerMessage(char const* Text, ...)
{
    va_list ap;
    char szStr [1024];
    szStr[0] = '\0';

    va_start(ap, Text);
    vsnprintf(szStr, 1024, Text, ap);
    va_end(ap);

    uint32 length = strlen(szStr)+1;
    WorldPacket data(SMSG_AREA_TRIGGER_MESSAGE, 4+length);
    data << length;
    data << szStr;
    SendPacket(&data);
}

void WorldSession::HandleAreaTriggerOpcode(WorldPacket& recvData)
{
    uint32 triggerId;
    recvData >> triggerId;

    TC_LOG_DEBUG("network", "CMSG_AREATRIGGER. Trigger ID: %u", triggerId);

    Player* player = GetPlayer();
    if (player->IsInFlight())
    {
        TC_LOG_DEBUG("network", "HandleAreaTriggerOpcode: Player '%s' (GUID: %u) in flight, ignore Area Trigger ID:%u",
            player->GetName().c_str(), player->GetGUID().GetCounter(), triggerId);
        return;
    }

    AreaTriggerEntry const* atEntry = sAreaTriggerStore.LookupEntry(triggerId);
    if (!atEntry)
    {
        TC_LOG_DEBUG("network", "HandleAreaTriggerOpcode: Player '%s' (GUID: %u) send unknown (by DBC) Area Trigger ID:%u",
            player->GetName().c_str(), player->GetGUID().GetCounter(), triggerId);
        return;
    }

    if (!player->IsInAreaTriggerRadius(atEntry))
    {
        TC_LOG_DEBUG("network", "HandleAreaTriggerOpcode: Player '%s' (GUID: %u) too far, ignore Area Trigger ID: %u",
            player->GetName().c_str(), player->GetGUID().GetCounter(), triggerId);
        return;
    }

    if (player->isDebugAreaTriggers)
        ChatHandler(player->GetSession()).PSendSysMessage(LANG_DEBUG_AREATRIGGER_REACHED, triggerId);

    if (sScriptMgr->OnAreaTrigger(player, atEntry))
        return;

    if (player->IsAlive())
        if (uint32 questId = sObjectMgr->GetQuestForAreaTrigger(triggerId))
            if (player->GetQuestStatus(questId) == QUEST_STATUS_INCOMPLETE)
                player->AreaExploredOrEventHappens(questId);

    if (sObjectMgr->IsTavernAreaTrigger(triggerId))
    {
        // set resting flag we are in the inn
        player->SetRestFlag(REST_FLAG_IN_TAVERN, atEntry->ID);

        if (sWorld->IsFFAPvPRealm())
            player->RemoveByteFlag(UNIT_FIELD_BYTES_2, UNIT_BYTES_2_OFFSET_PVP_FLAG, UNIT_BYTE2_FLAG_FFA_PVP);

        return;
    }

    if (Battleground* bg = player->GetBattleground())
        if (bg->GetStatus() == STATUS_IN_PROGRESS)
            bg->HandleAreaTrigger(player, triggerId);

    if (OutdoorPvP* pvp = player->GetOutdoorPvP())
        if (pvp->HandleAreaTrigger(_player, triggerId))
            return;

    AreaTriggerStruct const* at = sObjectMgr->GetAreaTrigger(triggerId);
    if (!at)
        return;

    bool teleported = false;
    if (player->GetMapId() != at->target_mapId)
    {
        if (Map::EnterState denyReason = sMapMgr->PlayerCannotEnter(at->target_mapId, player, false))
        {
            bool reviveAtTrigger = false; // should we revive the player if he is trying to enter the correct instance?
            switch (denyReason)
            {
                case Map::CANNOT_ENTER_NO_ENTRY:
                    TC_LOG_DEBUG("maps", "MAP: Player '%s' attempted to enter map with id %d which has no entry", player->GetName().c_str(), at->target_mapId);
                    break;
                case Map::CANNOT_ENTER_UNINSTANCED_DUNGEON:
                    TC_LOG_DEBUG("maps", "MAP: Player '%s' attempted to enter dungeon map %d but no instance template was found", player->GetName().c_str(), at->target_mapId);
                    break;
                case Map::CANNOT_ENTER_DIFFICULTY_UNAVAILABLE:
                    TC_LOG_DEBUG("maps", "MAP: Player '%s' attempted to enter instance map %d but the requested difficulty was not found", player->GetName().c_str(), at->target_mapId);
                    if (MapEntry const* entry = sMapStore.LookupEntry(at->target_mapId))
                        player->SendTransferAborted(entry->ID, TRANSFER_ABORT_DIFFICULTY, player->GetDifficulty(entry->IsRaid()));
                    break;
                case Map::CANNOT_ENTER_NOT_IN_RAID:
                {
                    TC_LOG_DEBUG("maps", "MAP: Player '%s' must be in a raid group to enter instance map %d", player->GetName().c_str(), at->target_mapId);
                    player->SendRaidGroupOnlyMessage(RAID_GROUP_ERR_ONLY, 0);
                    reviveAtTrigger = true;
                    break;
                }
                case Map::CANNOT_ENTER_CORPSE_IN_DIFFERENT_INSTANCE:
                {
                    WorldPacket data(SMSG_CORPSE_NOT_IN_INSTANCE);
                    player->SendDirectMessage(&data);
                    TC_LOG_DEBUG("maps", "MAP: Player '%s' does not have a corpse in instance map %d and cannot enter", player->GetName().c_str(), at->target_mapId);
                    break;
                }
                case Map::CANNOT_ENTER_INSTANCE_BIND_MISMATCH:
                    if (MapEntry const* entry = sMapStore.LookupEntry(at->target_mapId))
                    {
                        char const* mapName = entry->MapName;
                        TC_LOG_DEBUG("maps", "MAP: Player '%s' cannot enter instance map '%s' because their permanent bind is incompatible with their group's", player->GetName().c_str(), mapName);
                        player->SendTransferAborted(entry->ID, TRANSFER_ABORT_LOCKED_TO_DIFFERENT_INSTANCE, player->GetDifficulty(entry->IsRaid()));
                    }
                    reviveAtTrigger = true;
                    break;
                case Map::CANNOT_ENTER_TOO_MANY_INSTANCES:
                    player->SendTransferAborted(at->target_mapId, TRANSFER_ABORT_TOO_MANY_INSTANCES);
                    TC_LOG_DEBUG("maps", "MAP: Player '%s' cannot enter instance map %d because he has exceeded the maximum number of instances per hour.", player->GetName().c_str(), at->target_mapId);
                    reviveAtTrigger = true;
                    break;
                case Map::CANNOT_ENTER_MAX_PLAYERS:
                    player->SendTransferAborted(at->target_mapId, TRANSFER_ABORT_MAX_PLAYERS);
                    reviveAtTrigger = true;
                    break;
                case Map::CANNOT_ENTER_ZONE_IN_COMBAT:
                    player->SendTransferAborted(at->target_mapId, TRANSFER_ABORT_ZONE_IN_COMBAT);
                    reviveAtTrigger = true;
                    break;
                default:
                    break;
            }

            if (reviveAtTrigger) // check if the player is touching the areatrigger leading to the map his corpse is on
                if (!player->IsAlive() && player->HasCorpse())
                    if (player->GetCorpseLocation().GetMapId() == at->target_mapId)
                    {
                        player->ResurrectPlayer(0.5f);
                        player->SpawnCorpseBones();
                    }

            return;
        }

        if (Group* group = player->GetGroup())
            if (group->isLFGGroup() && player->GetMap()->IsDungeon())
                teleported = player->TeleportToBGEntryPoint();
    }

    if (!teleported)
        player->TeleportTo(at->target_mapId, at->target_X, at->target_Y, at->target_Z, at->target_Orientation, TELE_TO_NOT_LEAVE_TRANSPORT);
}

void WorldSession::HandleUpdateAccountData(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_UPDATE_ACCOUNT_DATA");

    uint32 type, timestamp, decompressedSize;
    recvData >> type >> timestamp >> decompressedSize;

    TC_LOG_DEBUG("network", "UAD: type %u, time %u, decompressedSize %u", type, timestamp, decompressedSize);

    if (type > NUM_ACCOUNT_DATA_TYPES)
        return;

    if (decompressedSize == 0)                               // erase
    {
        SetAccountData(AccountDataType(type), 0, "");

        WorldPacket data(SMSG_UPDATE_ACCOUNT_DATA_COMPLETE, 4+4);
        data << uint32(type);
        data << uint32(0);
        SendPacket(&data);

        return;
    }

    if (decompressedSize > 0xFFFF)
    {
        recvData.rfinish();                   // unnneded warning spam in this case
        TC_LOG_ERROR("network", "UAD: Account data packet too big, size %u", decompressedSize);
        return;
    }

    ByteBuffer dest;
    dest.resize(decompressedSize);

    uLongf realSize = decompressedSize;
    if (uncompress(dest.contents(), &realSize, recvData.contents() + recvData.rpos(), recvData.size() - recvData.rpos()) != Z_OK)
    {
        recvData.rfinish();                   // unnneded warning spam in this case
        TC_LOG_ERROR("network", "UAD: Failed to decompress account data");
        return;
    }

    recvData.rfinish();                       // uncompress read (recvData.size() - recvData.rpos())

    std::string adata;
    dest >> adata;

    SetAccountData(AccountDataType(type), timestamp, adata);

    WorldPacket data(SMSG_UPDATE_ACCOUNT_DATA_COMPLETE, 4+4);
    data << uint32(type);
    data << uint32(0);
    SendPacket(&data);
}

void WorldSession::HandleRequestAccountData(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_REQUEST_ACCOUNT_DATA");

    uint32 type;
    recvData >> type;

    TC_LOG_DEBUG("network", "RAD: type %u", type);

    if (type >= NUM_ACCOUNT_DATA_TYPES)
        return;

    AccountData* adata = GetAccountData(AccountDataType(type));

    uint32 size = adata->Data.size();

    uLongf destSize = compressBound(size);

    ByteBuffer dest;
    dest.resize(destSize);

    if (size && compress(dest.contents(), &destSize, (uint8 const*)adata->Data.c_str(), size) != Z_OK)
    {
        TC_LOG_DEBUG("network", "RAD: Failed to compress account data");
        return;
    }

    dest.resize(destSize);

    WorldPacket data(SMSG_UPDATE_ACCOUNT_DATA, 8+4+4+4+destSize);
    data << uint64(_player ? _player->GetGUID() : ObjectGuid::Empty);
    data << uint32(type);                                   // type (0-7)
    data << uint32(adata->Time);                            // unix time
    data << uint32(size);                                   // decompressed length
    data.append(dest);                                      // compressed data
    SendPacket(&data);
}

int32 WorldSession::HandleEnableNagleAlgorithm()
{
    // Instructs the server we wish to receive few amounts of large packets (SMSG_MULTIPLE_PACKETS?)
    // instead of large amount of small packets
    return 0;
}

void WorldSession::HandleSetActionButtonOpcode(WorldPacket& recvData)
{
    uint8 button;
    uint32 packetData;
    recvData >> button >> packetData;
    TC_LOG_DEBUG("network", "CMSG_SET_ACTION_BUTTON Button: %u Data: %u", button, packetData);

    if (!packetData)
        GetPlayer()->removeActionButton(button);
    else
        GetPlayer()->addActionButton(button, ACTION_BUTTON_ACTION(packetData), ACTION_BUTTON_TYPE(packetData));
}

void WorldSession::HandleCompleteMovie(WorldPackets::Misc::CompleteMovie& /*packet*/)
{
    uint32 movie = _player->GetMovie();
    if (!movie)
        return;

    _player->SetMovie(0);
}

void WorldSession::HandleCompleteCinematic(WorldPackets::Misc::CompleteCinematic& /*packet*/)
{
    // If player has sight bound to visual waypoint NPC we should remove it
    GetPlayer()->GetCinematicMgr()->EndCinematic();
}

void WorldSession::HandleNextCinematicCamera(WorldPackets::Misc::NextCinematicCamera& /*packet*/)
{
    // Sent by client when cinematic actually begun. So we begin the server side process
    GetPlayer()->GetCinematicMgr()->BeginCinematic();
}

void WorldSession::HandleFeatherFallAck(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "WORLD: CMSG_MOVE_FEATHER_FALL_ACK");

    // no used
    recvData.rfinish();                       // prevent warnings spam
}

void WorldSession::HandleMoveUnRootAck(WorldPacket& recvData)
{
    // no used
    recvData.rfinish();                       // prevent warnings spam
/*
    uint64 guid;
    recvData >> guid;

    // now can skip not our packet
    if (_player->GetGUID() != guid)
    {
        recvData.rfinish();                   // prevent warnings spam
        return;
    }

    TC_LOG_DEBUG("network", "WORLD: CMSG_FORCE_MOVE_UNROOT_ACK");

    recvData.read_skip<uint32>();                          // unk

    MovementInfo movementInfo;
    movementInfo.guid = guid;
    ReadMovementInfo(recvData, &movementInfo);
    recvData.read_skip<float>();                           // unk2
*/
}

void WorldSession::HandleMoveRootAck(WorldPacket& recvData)
{
    // no used
    recvData.rfinish();                       // prevent warnings spam
/*
    uint64 guid;
    recvData >> guid;

    // now can skip not our packet
    if (_player->GetGUID() != guid)
    {
        recvData.rfinish();                   // prevent warnings spam
        return;
    }

    TC_LOG_DEBUG("network", "WORLD: CMSG_FORCE_MOVE_ROOT_ACK");

    recvData.read_skip<uint32>();                          // unk

    MovementInfo movementInfo;
    ReadMovementInfo(recvData, &movementInfo);
*/
}

void WorldSession::HandleSetActionBarToggles(WorldPacket& recvData)
{
    uint8 actionBar;
    recvData >> actionBar;

    if (!GetPlayer())                                        // ignore until not logged (check needed because STATUS_AUTHED)
    {
        if (actionBar != 0)
            TC_LOG_ERROR("network", "WorldSession::HandleSetActionBarToggles in not logged state with value: %u, ignored", uint32(actionBar));
        return;
    }

    GetPlayer()->SetByteValue(PLAYER_FIELD_BYTES, PLAYER_FIELD_BYTES_OFFSET_ACTION_BAR_TOGGLES, actionBar);
}

void WorldSession::HandlePlayedTime(WorldPacket& recvData)
{
    uint8 TriggerScriptEvent;
    recvData >> TriggerScriptEvent; // 0 or 1 expected

    WorldPackets::Character::PlayedTime packet;
    packet.TotalTime = _player->GetTotalPlayedTime();
    packet.LevelTime = _player->GetLevelPlayedTime();
    packet.TriggerEvent = bool(TriggerScriptEvent); // 0 - will not show in chat frame
    SendPacket(packet.Write());
}

void WorldSession::HandleInspectOpcode(WorldPacket& recvData)
{
    ObjectGuid guid;
    recvData >> guid;

    TC_LOG_DEBUG("network", "WORLD: Received CMSG_INSPECT");

    Player* player = ObjectAccessor::GetPlayer(*_player, guid);
    if (!player)
    {
        TC_LOG_DEBUG("network", "CMSG_INSPECT: No player found from %s", guid.ToString().c_str());
        return;
    }

    if (!GetPlayer()->IsWithinDistInMap(player, INSPECT_DISTANCE, false))
        return;

    if (GetPlayer()->IsValidAttackTarget(player))
        return;

    uint32 talent_points = 41;
    WorldPacket data(SMSG_INSPECT_TALENT, 8 + 4 + 1 + 1 + talent_points + 8 + 4 + 8 + 4);
    data << player->GetGUID();

    if (GetPlayer()->CanBeGameMaster() || sWorld->getIntConfig(CONFIG_TALENTS_INSPECTING) + (GetPlayer()->GetTeamId() == player->GetTeamId()) > 1)
        player->BuildPlayerTalentsInfoData(&data);
    else
    {
        data << uint32(0);                                  // unspentTalentPoints
        data << uint8(0);                                   // talentGroupCount
        data << uint8(0);                                   // talentGroupIndex
    }

    player->BuildEnchantmentsInfoData(&data);
    if (Guild* guild = sGuildMgr->GetGuildById(player->GetGuildId()))
    {
        data << uint64(guild->GetGUID());
        data << uint32(guild->GetLevel());
        data << uint64(guild->GetExperience());
        data << uint32(guild->GetMembersCount());
    }
    SendPacket(&data);
}

void WorldSession::HandleInspectHonorStatsOpcode(WorldPacket& recvData)
{
    ObjectGuid guid;
    guid[1] = recvData.ReadBit();
    guid[5] = recvData.ReadBit();
    guid[7] = recvData.ReadBit();
    guid[3] = recvData.ReadBit();
    guid[2] = recvData.ReadBit();
    guid[4] = recvData.ReadBit();
    guid[0] = recvData.ReadBit();
    guid[6] = recvData.ReadBit();

    recvData.ReadByteSeq(guid[4]);
    recvData.ReadByteSeq(guid[7]);
    recvData.ReadByteSeq(guid[0]);
    recvData.ReadByteSeq(guid[5]);
    recvData.ReadByteSeq(guid[1]);
    recvData.ReadByteSeq(guid[6]);
    recvData.ReadByteSeq(guid[2]);
    recvData.ReadByteSeq(guid[3]);
    Player* player = ObjectAccessor::GetPlayer(*_player, guid);
    if (!player)
    {
        TC_LOG_DEBUG("network", "CMSG_INSPECT_HONOR_STATS: No player found from %s", guid.ToString().c_str());
        return;
    }

    if (!GetPlayer()->IsWithinDistInMap(player, INSPECT_DISTANCE, false))
        return;

    if (GetPlayer()->IsValidAttackTarget(player))
        return;

    ObjectGuid playerGuid = player->GetGUID();
    WorldPacket data(SMSG_INSPECT_HONOR_STATS, 8+1+4+4);
    data.WriteBit(playerGuid[4]);
    data.WriteBit(playerGuid[3]);
    data.WriteBit(playerGuid[6]);
    data.WriteBit(playerGuid[2]);
    data.WriteBit(playerGuid[5]);
    data.WriteBit(playerGuid[0]);
    data.WriteBit(playerGuid[7]);
    data.WriteBit(playerGuid[1]);
    data << uint8(0);                                               // rank
    data << uint16(player->GetUInt16Value(PLAYER_FIELD_KILLS, 1));  // yesterday kills
    data << uint16(player->GetUInt16Value(PLAYER_FIELD_KILLS, 0));  // today kills
    data.WriteByteSeq(playerGuid[2]);
    data.WriteByteSeq(playerGuid[0]);
    data.WriteByteSeq(playerGuid[6]);
    data.WriteByteSeq(playerGuid[3]);
    data.WriteByteSeq(playerGuid[4]);
    data.WriteByteSeq(playerGuid[1]);
    data.WriteByteSeq(playerGuid[5]);
    data << uint32(player->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS));
    data.WriteByteSeq(playerGuid[7]);
    SendPacket(&data);
}

void WorldSession::HandleWorldTeleportOpcode(WorldPacket& recvData)
{
    uint32 time;
    uint32 mapid;
    float PositionX;
    float PositionY;
    float PositionZ;
    float Orientation;

    recvData >> time;                                      // time in m.sec.
    recvData >> mapid;
    recvData >> PositionX;
    recvData >> PositionY;
    recvData >> PositionZ;
    recvData >> Orientation;                               // o (3.141593 = 180 degrees)

    TC_LOG_DEBUG("network", "WORLD: Received CMSG_WORLD_TELEPORT");

    if (GetPlayer()->IsInFlight())
    {
        TC_LOG_DEBUG("network", "Player '%s' (GUID: %u) in flight, ignore worldport command.",
            GetPlayer()->GetName().c_str(), GetPlayer()->GetGUID().GetCounter());
        return;
    }

    TC_LOG_DEBUG("network", "CMSG_WORLD_TELEPORT: Player = %s, Time = %u, map = %u, x = %f, y = %f, z = %f, o = %f",
        GetPlayer()->GetName().c_str(), time, mapid, PositionX, PositionY, PositionZ, Orientation);

    if (HasPermission(rbac::RBAC_PERM_OPCODE_WORLD_TELEPORT))
        GetPlayer()->TeleportTo(mapid, PositionX, PositionY, PositionZ, Orientation);
    else
        SendNotification(LANG_YOU_NOT_HAVE_PERMISSION);
}

void WorldSession::HandleWhoisOpcode(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "Received opcode CMSG_WHOIS");
    std::string charname;
    recvData >> charname;

    if (!HasPermission(rbac::RBAC_PERM_OPCODE_WHOIS))
    {
        SendNotification(LANG_YOU_NOT_HAVE_PERMISSION);
        return;
    }

    if (charname.empty() || !normalizePlayerName (charname))
    {
        SendNotification(LANG_NEED_CHARACTER_NAME);
        return;
    }

    Player* player = ObjectAccessor::FindConnectedPlayerByName(charname);

    if (!player)
    {
        SendNotification(LANG_PLAYER_NOT_EXIST_OR_OFFLINE, charname.c_str());
        return;
    }

    uint32 accid = player->GetSession()->GetAccountId();

    LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_ACCOUNT_WHOIS);

    stmt->setUInt32(0, accid);

    PreparedQueryResult result = LoginDatabase.Query(stmt);

    if (!result)
    {
        SendNotification(LANG_ACCOUNT_FOR_PLAYER_NOT_FOUND, charname.c_str());
        return;
    }

    Field* fields = result->Fetch();
    std::string acc = fields[0].GetString();
    if (acc.empty())
        acc = "Unknown";
    std::string email = fields[1].GetString();
    if (email.empty())
        email = "Unknown";
    std::string lastip = fields[2].GetString();
    if (lastip.empty())
        lastip = "Unknown";

    std::string msg = charname + "'s " + "account is " + acc + ", e-mail: " + email + ", last ip: " + lastip;

    WorldPacket data(SMSG_WHOIS, msg.size()+1);
    data << msg;
    SendPacket(&data);

    TC_LOG_DEBUG("network", "Received whois command from player %s for character %s",
        GetPlayer()->GetName().c_str(), charname.c_str());
}

void WorldSession::HandleComplainOpcode(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "WORLD: CMSG_COMPLAIN");

    uint8 spam_type;                                        // 0 - mail, 1 - chat
    ObjectGuid spammer_guid;
    uint32 unk1 = 0;
    uint32 unk2 = 0;
    uint32 unk3 = 0;
    uint32 unk4 = 0;
    std::string description = "";
    recvData >> spam_type;                                 // unk 0x01 const, may be spam type (mail/chat)
    recvData >> spammer_guid;                              // player guid
    switch (spam_type)
    {
        case 0:
            recvData >> unk1;                              // const 0
            recvData >> unk2;                              // probably mail id
            recvData >> unk3;                              // const 0
            break;
        case 1:
            recvData >> unk1;                              // probably language
            recvData >> unk2;                              // message type?
            recvData >> unk3;                              // probably channel id
            recvData >> unk4;                              // time
            recvData >> description;                       // spam description string (messagetype, channel name, player name, message)
            break;
    }

    // NOTE: all chat messages from this spammer automatically ignored by spam reporter until logout in case chat spam.
    // if it's mail spam - ALL mails from this spammer automatically removed by client

    // Complaint Received message
    WorldPacket data(SMSG_COMPLAIN_RESULT, 2);
    data << uint8(0); // value 1 resets CGChat::m_complaintsSystemStatus in client. (unused?)
    data << uint8(0); // value 0xC generates a "CalendarError" in client.
    SendPacket(&data);

    TC_LOG_DEBUG("network", "REPORT SPAM: type %u, %s, unk1 %u, unk2 %u, unk3 %u, unk4 %u, message %s",
        spam_type, spammer_guid.ToString().c_str(), unk1, unk2, unk3, unk4, description.c_str());
}

void WorldSession::HandleRealmSplitOpcode(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "CMSG_REALM_SPLIT");

    uint32 unk;
    std::string split_date = "01/01/01";
    recvData >> unk;

    WorldPacket data(SMSG_REALM_SPLIT, 4+4+split_date.size()+1);
    data << unk;
    data << uint32(0x00000000);                             // realm split state
    // split states:
    // 0x0 realm normal
    // 0x1 realm split
    // 0x2 realm split pending
    data << split_date;
    SendPacket(&data);
    //TC_LOG_DEBUG("response sent %u", unk);
}

void WorldSession::HandleFarSightOpcode(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "WORLD: CMSG_FAR_SIGHT");

    bool apply;
    recvData >> apply;

    if (apply)
    {
        TC_LOG_DEBUG("network", "Added FarSight %s to player %u", _player->GetGuidValue(PLAYER_FARSIGHT).ToString().c_str(), _player->GetGUID().GetCounter());
        if (WorldObject* target = _player->GetViewpoint())
            _player->SetSeer(target);
        else
            TC_LOG_DEBUG("network", "Player %s (%s) requests non-existing seer %s", _player->GetName().c_str(), _player->GetGUID().ToString().c_str(), _player->GetGuidValue(PLAYER_FARSIGHT).ToString().c_str());
    }
    else
    {
        TC_LOG_DEBUG("network", "Player %u set vision to self", _player->GetGUID().GetCounter());
        _player->SetSeer(_player);
    }

    GetPlayer()->UpdateVisibilityForPlayer();
}

void WorldSession::HandleSetTitleOpcode(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "CMSG_SET_TITLE");

    int32 title;
    recvData >> title;

    // -1 at none
    if (title > 0 && title < MAX_TITLE_INDEX)
    {
       if (!GetPlayer()->HasTitle(title))
            return;
    }
    else
        title = 0;

    GetPlayer()->SetUInt32Value(PLAYER_CHOSEN_TITLE, title);
}

void WorldSession::HandleResetInstancesOpcode(WorldPacket& /*recvData*/)
{
    TC_LOG_DEBUG("network", "WORLD: CMSG_RESET_INSTANCES");

    if (Group* group = _player->GetGroup())
    {
        if (group->IsLeader(_player->GetGUID()))
            group->ResetInstances(INSTANCE_RESET_ALL, false, _player);
    }
    else
        _player->ResetInstances(INSTANCE_RESET_ALL, false);
}

void WorldSession::HandleSetDungeonDifficultyOpcode(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "MSG_SET_DUNGEON_DIFFICULTY");

    uint32 mode;
    recvData >> mode;

    if (mode >= MAX_DUNGEON_DIFFICULTY)
    {
        TC_LOG_DEBUG("network", "WorldSession::HandleSetDungeonDifficultyOpcode: player %d sent an invalid instance mode %d!", _player->GetGUID().GetCounter(), mode);
        return;
    }

    if (Difficulty(mode) == _player->GetDungeonDifficulty())
        return;

    // cannot reset while in an instance
    Map* map = _player->FindMap();
    if (map && map->IsDungeon())
    {
        TC_LOG_DEBUG("network", "WorldSession::HandleSetDungeonDifficultyOpcode: player (Name: %s, GUID: %u) tried to reset the instance while player is inside!",
            _player->GetName().c_str(), _player->GetGUID().GetCounter());
        return;
    }

    Group* group = _player->GetGroup();
    if (group)
    {
        if (group->IsLeader(_player->GetGUID()))
        {
            for (GroupReference* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
            {
                Player* groupGuy = itr->GetSource();
                if (!groupGuy)
                    continue;

                if (!groupGuy->IsInMap(groupGuy))
                    return;

                if (groupGuy->GetMap()->IsNonRaidDungeon())
                {
                    TC_LOG_DEBUG("network", "WorldSession::HandleSetDungeonDifficultyOpcode: player %d tried to reset the instance while group member (Name: %s, GUID: %u) is inside!",
                        _player->GetGUID().GetCounter(), groupGuy->GetName().c_str(), groupGuy->GetGUID().GetCounter());
                    return;
                }
            }
            // the difficulty is set even if the instances can't be reset
            //_player->SendDungeonDifficulty(true);
            group->ResetInstances(INSTANCE_RESET_CHANGE_DIFFICULTY, false, _player);
            group->SetDungeonDifficulty(Difficulty(mode));
        }
    }
    else
    {
        _player->ResetInstances(INSTANCE_RESET_CHANGE_DIFFICULTY, false);
        _player->SetDungeonDifficulty(Difficulty(mode));
    }
}

void WorldSession::HandleSetRaidDifficultyOpcode(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "MSG_SET_RAID_DIFFICULTY");

    uint32 mode;
    recvData >> mode;

    if (mode >= MAX_RAID_DIFFICULTY)
    {
        TC_LOG_ERROR("network", "WorldSession::HandleSetRaidDifficultyOpcode: player %d sent an invalid instance mode %d!", _player->GetGUID().GetCounter(), mode);
        return;
    }

    // cannot reset while in an instance
    Map* map = _player->FindMap();
    if (map && map->IsDungeon())
    {
        TC_LOG_DEBUG("network", "WorldSession::HandleSetRaidDifficultyOpcode: player %d tried to reset the instance while inside!", _player->GetGUID().GetCounter());
        return;
    }

    if (Difficulty(mode) == _player->GetRaidDifficulty())
        return;

    Group* group = _player->GetGroup();
    if (group)
    {
        if (group->IsLeader(_player->GetGUID()))
        {
            for (GroupReference* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
            {
                Player* groupGuy = itr->GetSource();
                if (!groupGuy)
                    continue;

                if (!groupGuy->IsInMap(groupGuy))
                    return;

                if (groupGuy->GetMap()->IsRaid())
                {
                    TC_LOG_DEBUG("network", "WorldSession::HandleSetRaidDifficultyOpcode: player %d tried to reset the instance while inside!", _player->GetGUID().GetCounter());
                    return;
                }
            }
            // the difficulty is set even if the instances can't be reset
            //_player->SendDungeonDifficulty(true);
            group->ResetInstances(INSTANCE_RESET_CHANGE_DIFFICULTY, true, _player);
            group->SetRaidDifficulty(Difficulty(mode));
        }
    }
    else
    {
        _player->ResetInstances(INSTANCE_RESET_CHANGE_DIFFICULTY, true);
        _player->SetRaidDifficulty(Difficulty(mode));
    }
}

void WorldSession::HandleCancelMountAuraOpcode(WorldPacket& /*recvData*/)
{
    TC_LOG_DEBUG("network", "WORLD: CMSG_CANCEL_MOUNT_AURA");

    //If player is not mounted, so go out :)
    if (!_player->IsMounted())                              // not blizz like; no any messages on blizz
    {
        ChatHandler(this).SendSysMessage(LANG_CHAR_NON_MOUNTED);
        return;
    }

    if (_player->IsInFlight())                               // not blizz like; no any messages on blizz
    {
        ChatHandler(this).SendSysMessage(LANG_YOU_IN_FLIGHT);
        return;
    }

    _player->RemoveAurasByType(SPELL_AURA_MOUNTED); // Calls Dismount()
}

void WorldSession::HandleMoveSetCanFlyAckOpcode(WorldPacket& recvData)
{
    // fly mode on/off
    TC_LOG_DEBUG("network", "WORLD: CMSG_MOVE_SET_CAN_FLY_ACK");

    MovementInfo movementInfo;
    _player->ReadMovementInfo(recvData, &movementInfo);

    _player->m_unitMovedByMe->m_movementInfo.flags = movementInfo.GetMovementFlags();
}

void WorldSession::HandleSetTaxiBenchmarkOpcode(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "WORLD: CMSG_SET_TAXI_BENCHMARK_MODE");

    uint8 mode;
    recvData >> mode;

    mode ? _player->SetFlag(PLAYER_FLAGS, PLAYER_FLAGS_TAXI_BENCHMARK) : _player->RemoveFlag(PLAYER_FLAGS, PLAYER_FLAGS_TAXI_BENCHMARK);

    TC_LOG_DEBUG("network", "Client used \"/timetest %d\" command", mode);
}

void WorldSession::HandleQueryInspectAchievements(WorldPacket& recvData)
{
    ObjectGuid guid;
    recvData >> guid.ReadAsPacked();

    TC_LOG_DEBUG("network", "CMSG_QUERY_INSPECT_ACHIEVEMENTS [%s] Inspected Player [%s]", _player->GetGUID().ToString().c_str(), guid.ToString().c_str());
    Player* player = ObjectAccessor::GetPlayer(*_player, guid);
    if (!player)
        return;

    if (!GetPlayer()->IsWithinDistInMap(player, INSPECT_DISTANCE, false))
        return;

    if (GetPlayer()->IsValidAttackTarget(player))
        return;

    player->SendRespondInspectAchievements(_player);
}

void WorldSession::HandleGuildAchievementProgressQuery(WorldPacket& recvData)
{
    uint32 achievementId;
    recvData >> achievementId;

    if (Guild* guild = _player->GetGuild())
        guild->GetAchievementMgr().SendAchievementInfo(_player, achievementId);
}

void WorldSession::HandleWorldStateUITimerUpdate(WorldPacket& /*recvData*/)
{
    // empty opcode
    TC_LOG_DEBUG("network", "WORLD: CMSG_WORLD_STATE_UI_TIMER_UPDATE");

    WorldPackets::Misc::UITime response;
    response.Time = GameTime::GetGameTime();
    SendPacket(response.Write());
}

void WorldSession::HandleReadyForAccountDataTimes(WorldPacket& /*recvData*/)
{
    // empty opcode
    TC_LOG_DEBUG("network", "WORLD: CMSG_READY_FOR_ACCOUNT_DATA_TIMES");

    SendAccountDataTimes(GLOBAL_CACHE_MASK);
}

// Battlefield and Battleground
void WorldSession::HandleAreaSpiritHealerQueryOpcode(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "WORLD: CMSG_AREA_SPIRIT_HEALER_QUERY");

    Battleground* bg = _player->GetBattleground();

    ObjectGuid guid;
    recvData >> guid;

    Creature* unit = GetPlayer()->GetMap()->GetCreature(guid);
    if (!unit)
        return;

    if (!unit->IsSpiritService())                            // it's not spirit service
        return;

    if (bg)
        sBattlegroundMgr->SendAreaSpiritHealerQueryOpcode(_player, bg, guid);

    if (Battlefield* bf = sBattlefieldMgr->GetBattlefieldToZoneId(_player->GetZoneId()))
        bf->SendAreaSpiritHealerQueryOpcode(_player, guid);
}

void WorldSession::HandleAreaSpiritHealerQueueOpcode(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "WORLD: CMSG_AREA_SPIRIT_HEALER_QUEUE");

    Battleground* bg = _player->GetBattleground();

    ObjectGuid guid;
    recvData >> guid;

    Creature* unit = GetPlayer()->GetMap()->GetCreature(guid);
    if (!unit)
        return;

    if (!unit->IsSpiritService())                            // it's not spirit service
        return;

    if (bg)
        bg->AddPlayerToResurrectQueue(guid, _player->GetGUID());

    if (Battlefield* bf = sBattlefieldMgr->GetBattlefieldToZoneId(_player->GetZoneId()))
        bf->AddPlayerToResurrectQueue(guid, _player->GetGUID());
}

void WorldSession::HandleHearthAndResurrect(WorldPacket& /*recvData*/)
{
    if (_player->IsInFlight())
        return;

    if (Battlefield* bf = sBattlefieldMgr->GetBattlefieldToZoneId(_player->GetZoneId()))
    {
        bf->PlayerAskToLeave(_player);
        return;
    }

    AreaTableEntry const* atEntry = sAreaTableStore.LookupEntry(_player->GetAreaId());
    if (!atEntry || !(atEntry->Flags & AREA_FLAG_CAN_HEARTH_AND_RESURRECT))
        return;

    _player->BuildPlayerRepop();
    _player->ResurrectPlayer(1.0f);
    _player->TeleportTo(_player->m_homebindMapId, _player->m_homebindX, _player->m_homebindY, _player->m_homebindZ, _player->GetOrientation());
}

void WorldSession::HandleInstanceLockResponse(WorldPacket& recvPacket)
{
    uint8 accept;
    recvPacket >> accept;

    if (!_player->HasPendingBind())
    {
        TC_LOG_INFO("network", "InstanceLockResponse: Player %s (guid %u) tried to bind himself/teleport to graveyard without a pending bind!",
            _player->GetName().c_str(), _player->GetGUID().GetCounter());
        return;
    }

    if (accept)
        _player->BindToInstance();
    else
        _player->RepopAtGraveyard();

    _player->SetPendingBind(0, 0);
}

void WorldSession::HandleUpdateMissileTrajectory(WorldPacket& recvPacket)
{
    TC_LOG_DEBUG("network", "WORLD: CMSG_UPDATE_MISSILE_TRAJECTORY");

    ObjectGuid guid;
    uint32 spellId;
    float elevation, speed;
    float curX, curY, curZ;
    float targetX, targetY, targetZ;
    uint8 moveStop;

    recvPacket >> guid >> spellId >> elevation >> speed;
    recvPacket >> curX >> curY >> curZ;
    recvPacket >> targetX >> targetY >> targetZ;
    recvPacket >> moveStop;

    Unit* caster = ObjectAccessor::GetUnit(*_player, guid);
    Spell* spell = caster ? caster->GetCurrentSpell(CURRENT_GENERIC_SPELL) : nullptr;
    if (!spell || spell->m_spellInfo->Id != spellId || !spell->m_targets.HasDst() || !spell->m_targets.HasSrc())
    {
        recvPacket.rfinish();
        return;
    }

    Position pos = *spell->m_targets.GetSrcPos();
    pos.Relocate(curX, curY, curZ);
    spell->m_targets.ModSrc(pos);

    pos = *spell->m_targets.GetDstPos();
    pos.Relocate(targetX, targetY, targetZ);
    spell->m_targets.ModDst(pos);

    spell->m_targets.SetElevation(elevation);
    spell->m_targets.SetSpeed(speed);

    if (moveStop)
    {
        uint32 opcode;
        recvPacket >> opcode;
        recvPacket.SetOpcode(MSG_MOVE_STOP); // always set to MSG_MOVE_STOP in client SetOpcode
        HandleMovementOpcodes(recvPacket);
    }
}

void WorldSession::HandleViolenceLevel(WorldPacket& recvPacket)
{
    uint8 violenceLevel;
    recvPacket >> violenceLevel;

    // do something?
}

void WorldSession::HandleObjectUpdateFailedOpcode(WorldPacket& recvPacket)
{
    ObjectGuid guid;
    guid[6] = recvPacket.ReadBit();
    guid[7] = recvPacket.ReadBit();
    guid[4] = recvPacket.ReadBit();
    guid[0] = recvPacket.ReadBit();
    guid[1] = recvPacket.ReadBit();
    guid[5] = recvPacket.ReadBit();
    guid[3] = recvPacket.ReadBit();
    guid[2] = recvPacket.ReadBit();

    recvPacket.ReadByteSeq(guid[6]);
    recvPacket.ReadByteSeq(guid[7]);
    recvPacket.ReadByteSeq(guid[2]);
    recvPacket.ReadByteSeq(guid[3]);
    recvPacket.ReadByteSeq(guid[1]);
    recvPacket.ReadByteSeq(guid[4]);
    recvPacket.ReadByteSeq(guid[0]);
    recvPacket.ReadByteSeq(guid[5]);

    WorldObject* obj = ObjectAccessor::GetWorldObject(*GetPlayer(), guid);
    TC_LOG_ERROR("network", "Object update failed for object " UI64FMTD " (%s) for player %s (%u)", uint64(guid), obj ? obj->GetName().c_str() : "object-not-found", GetPlayerName().c_str(), GetGUIDLow());

    // If create object failed for current player then client will be stuck on loading screen
    if (_player->GetGUID() == guid)
    {
        LogoutPlayer(true);
        return;
    }

    // Pretend we've never seen this object
    _player->m_clientGUIDs.erase(guid);
}

void WorldSession::HandleSaveCUFProfiles(WorldPacket& recvPacket)
{
    TC_LOG_DEBUG("network", "WORLD: CMSG_SAVE_CUF_PROFILES");

    uint8 count = (uint8)recvPacket.ReadBits(20);

    if (count > MAX_CUF_PROFILES)
    {
        TC_LOG_ERROR("entities.player", "HandleSaveCUFProfiles - %s tried to save more than %i CUF profiles. Hacking attempt?", GetPlayerName().c_str(), MAX_CUF_PROFILES);
        recvPacket.rfinish();
        return;
    }

    std::unique_ptr<CUFProfile> profiles[MAX_CUF_PROFILES];
    uint8 strlens[MAX_CUF_PROFILES];

    for (uint8 i = 0; i < count; ++i)
    {
        profiles[i] = Trinity::make_unique<CUFProfile>();
        profiles[i]->BoolOptions.set(CUF_AUTO_ACTIVATE_SPEC_2            , recvPacket.ReadBit());
        profiles[i]->BoolOptions.set(CUF_AUTO_ACTIVATE_10_PLAYERS        , recvPacket.ReadBit());
        profiles[i]->BoolOptions.set(CUF_UNK_157                         , recvPacket.ReadBit());
        profiles[i]->BoolOptions.set(CUF_DISPLAY_HEAL_PREDICTION         , recvPacket.ReadBit());
        profiles[i]->BoolOptions.set(CUF_AUTO_ACTIVATE_SPEC_1            , recvPacket.ReadBit());
        profiles[i]->BoolOptions.set(CUF_AUTO_ACTIVATE_PVP               , recvPacket.ReadBit());
        profiles[i]->BoolOptions.set(CUF_DISPLAY_POWER_BAR               , recvPacket.ReadBit());
        profiles[i]->BoolOptions.set(CUF_AUTO_ACTIVATE_15_PLAYERS        , recvPacket.ReadBit());
        profiles[i]->BoolOptions.set(CUF_AUTO_ACTIVATE_40_PLAYERS        , recvPacket.ReadBit());
        profiles[i]->BoolOptions.set(CUF_DISPLAY_PETS                    , recvPacket.ReadBit());
        profiles[i]->BoolOptions.set(CUF_AUTO_ACTIVATE_5_PLAYERS         , recvPacket.ReadBit());
        profiles[i]->BoolOptions.set(CUF_DISPLAY_ONLY_DISPELLABLE_DEBUFFS, recvPacket.ReadBit());
        profiles[i]->BoolOptions.set(CUF_AUTO_ACTIVATE_2_PLAYERS         , recvPacket.ReadBit());
        profiles[i]->BoolOptions.set(CUF_UNK_156                         , recvPacket.ReadBit());
        profiles[i]->BoolOptions.set(CUF_DISPLAY_NON_BOSS_DEBUFFS        , recvPacket.ReadBit());
        profiles[i]->BoolOptions.set(CUF_DISPLAY_MAIN_TANK_AND_ASSIST    , recvPacket.ReadBit());
        profiles[i]->BoolOptions.set(CUF_DISPLAY_AGGRO_HIGHLIGHT         , recvPacket.ReadBit());
        profiles[i]->BoolOptions.set(CUF_AUTO_ACTIVATE_3_PLAYERS         , recvPacket.ReadBit());
        profiles[i]->BoolOptions.set(CUF_DISPLAY_BORDER                  , recvPacket.ReadBit());
        profiles[i]->BoolOptions.set(CUF_USE_CLASS_COLORS                , recvPacket.ReadBit());
        profiles[i]->BoolOptions.set(CUF_UNK_145                         , recvPacket.ReadBit());
        strlens[i] = (uint8)recvPacket.ReadBits(8);
        profiles[i]->BoolOptions.set(CUF_AUTO_ACTIVATE_PVE               , recvPacket.ReadBit());
        profiles[i]->BoolOptions.set(CUF_DISPLAY_HORIZONTAL_GROUPS       , recvPacket.ReadBit());
        profiles[i]->BoolOptions.set(CUF_AUTO_ACTIVATE_25_PLAYERS        , recvPacket.ReadBit());
        profiles[i]->BoolOptions.set(CUF_KEEP_GROUPS_TOGETHER            , recvPacket.ReadBit());
    }

    for (uint8 i = 0; i < count; ++i)
    {
        recvPacket >> profiles[i]->TopPoint;
        profiles[i]->ProfileName = recvPacket.ReadString(strlens[i]);
        recvPacket >> profiles[i]->BottomOffset;
        recvPacket >> profiles[i]->FrameHeight;
        recvPacket >> profiles[i]->FrameWidth;
        recvPacket >> profiles[i]->TopOffset;
        recvPacket >> profiles[i]->HealthText;
        recvPacket >> profiles[i]->BottomPoint;
        recvPacket >> profiles[i]->SortBy;
        recvPacket >> profiles[i]->LeftOffset;
        recvPacket >> profiles[i]->LeftPoint;

        GetPlayer()->SaveCUFProfile(i, std::move(profiles[i]));
    }

    for (uint8 i = count; i < MAX_CUF_PROFILES; ++i)
        GetPlayer()->SaveCUFProfile(i, nullptr);
}

void WorldSession::SendLoadCUFProfiles()
{
    Player* player = GetPlayer();

    WorldPackets::Misc::LoadCUFProfiles loadCUFProfiles;

    for (uint8 i = 0; i < MAX_CUF_PROFILES; i++)
        if (CUFProfile* cufProfile = player->GetCUFProfile(i))
            loadCUFProfiles.CUFProfiles.push_back(cufProfile);
    SendPacket(loadCUFProfiles.Write());
}

void WorldSession::HandleChangePlayerDifficulty(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "Received CMSG_CHANGEPLAYER_DIFFICULTY");

    uint32 difficulty;

    recvData >> difficulty;

    uint32 result = 0;

    switch(result)
    {
        case ERR_DIFFICULTY_CHANGE_COOLDOWN_S:
        case ERR_DIFFICULTY_CHANGE_UPDATE_TIME:
        case ERR_DIFFICULTY_CHANGE_UPDATE_MAP_DIFFICULTY_ENTRY:
        {
            uint32 time = 0;
            uint32 difficultyMapId = 0;
            uint32 cooldownTime = 0;
            WorldPacket data(SMSG_PLAYER_DIFFICULTY_CHANGE, 8);

            data << result;

            if(result == ERR_DIFFICULTY_CHANGE_UPDATE_TIME)
                data << time;
            else if(result == ERR_DIFFICULTY_CHANGE_COOLDOWN_S)
                data << cooldownTime;
            else
                data << difficultyMapId;

            SendPacket(&data);
            break;
        }
        case ERR_DIFFICULTY_CHANGE_OTHER_HEROIC_S:
        {
            uint64 guid = 0;
            WorldPacket data(SMSG_PLAYER_DIFFICULTY_CHANGE);

            data << result;
            data.appendPackGUID(guid); //guid of the player which is locked

            SendPacket(&data);
            break;
        }
        default:
        {
            WorldPacket data(SMSG_PLAYER_DIFFICULTY_CHANGE, 4);

            data << result;

            SendPacket(&data);
            break;
        }
    }
}

void WorldSession::SendStreamingMovie()
{
    WorldPackets::Misc::StreamingMovies packet;

    // To-do: implement
    SendPacket(packet.Write());
}

void WorldSession::HandleRequestResearchHistory(WorldPackets::Archaeology::RequestResearchHistory& /*packet*/)
{
    _player->NotifyRequestResearchHistory();
}

void WorldSession::HandleOpeningCinematic(WorldPackets::Misc::OpeningCinematic& /*packet*/)
{
    // Only players that has not yet gained any experience can use this
    if (_player->GetUInt32Value(PLAYER_XP))
        return;

    if (ChrClassesEntry const* classEntry = sChrClassesStore.LookupEntry(_player->getClass()))
    {
        if (classEntry->CinematicSequenceID)
            _player->SendCinematicStart(classEntry->CinematicSequenceID);
        else if (ChrRacesEntry const* raceEntry = sChrRacesStore.LookupEntry(_player->getRace()))
            _player->SendCinematicStart(raceEntry->CinematicSequenceID);
    }
}
