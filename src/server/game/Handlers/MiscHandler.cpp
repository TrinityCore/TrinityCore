/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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
#include "AccountMgr.h"
#include "AchievementPackets.h"
#include "AreaTriggerPackets.h"
#include "Battleground.h"
#include "CharacterPackets.h"
#include "Chat.h"
#include "CinematicMgr.h"
#include "ClientConfigPackets.h"
#include "Common.h"
#include "Corpse.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "GossipDef.h"
#include "Group.h"
#include "Guild.h"
#include "GuildMgr.h"
#include "InstancePackets.h"
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
#include "RestMgr.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "SpellPackets.h"
#include "WhoPackets.h"
#include "World.h"
#include "WorldPacket.h"
#include <boost/thread/shared_mutex.hpp>
#include <boost/thread/locks.hpp>
#include <zlib.h>

void WorldSession::HandleRepopRequest(WorldPackets::Misc::RepopRequest& /*packet*/)
{
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
        TC_LOG_DEBUG("network", "HandleRepopRequestOpcode: got request after player %s(%s) was killed and before he was updated",
            GetPlayer()->GetName().c_str(), GetPlayer()->GetGUID().ToString().c_str());
        GetPlayer()->KillPlayer();
    }

    //this is spirit release confirm?
    GetPlayer()->RemovePet(NULL, PET_SAVE_NOT_IN_SLOT, true);
    GetPlayer()->BuildPlayerRepop();
    GetPlayer()->RepopAtGraveyard();
}

void WorldSession::HandleWhoOpcode(WorldPackets::Who::WhoRequestPkt& whoRequest)
{
    WorldPackets::Who::WhoRequest& request = whoRequest.Request;

    TC_LOG_DEBUG("network", "WorldSession::HandleWhoOpcode: MinLevel: %u, MaxLevel: %u, Name: %s (VirtualRealmName: %s), Guild: %s (GuildVirtualRealmName: %s), RaceFilter: " UI64FMTD ", ClassFilter: %d, Areas: " SZFMTD ", Words: " SZFMTD ".",
        request.MinLevel, request.MaxLevel, request.Name.c_str(), request.VirtualRealmName.c_str(), request.Guild.c_str(), request.GuildVirtualRealmName.c_str(),
        request.RaceFilter, request.ClassFilter, whoRequest.Areas.size(), request.Words.size());

    // zones count, client limit = 10 (2.0.10)
    // can't be received from real client or broken packet
    if (whoRequest.Areas.size() > 10)
        return;

    // user entered strings count, client limit=4 (checked on 2.0.10)
    // can't be received from real client or broken packet
    if (request.Words.size() > 4)
        return;

    /// @todo: handle following packet values
    /// VirtualRealmNames
    /// ShowEnemies
    /// ShowArenaPlayers
    /// ExactName
    /// ServerInfo

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

    uint32 gmLevelInWhoList  = sWorld->getIntConfig(CONFIG_GM_LEVEL_IN_WHO_LIST);

    WorldPackets::Who::WhoResponsePkt response;

    boost::shared_lock<boost::shared_mutex> lock(*HashMapHolder<Player>::GetLock());

    HashMapHolder<Player>::MapType const& m = ObjectAccessor::GetPlayers();
    for (HashMapHolder<Player>::MapType::const_iterator itr = m.begin(); itr != m.end(); ++itr)
    {
        Player* target = itr->second;
        // player can see member of other team only if has RBAC_PERM_TWO_SIDE_WHO_LIST
        if (target->GetTeam() != team && !HasPermission(rbac::RBAC_PERM_TWO_SIDE_WHO_LIST))
            continue;

        // player can see MODERATOR, GAME MASTER, ADMINISTRATOR only if has RBAC_PERM_WHO_SEE_ALL_SEC_LEVELS
        if (target->GetSession()->GetSecurity() > AccountTypes(gmLevelInWhoList) && !HasPermission(rbac::RBAC_PERM_WHO_SEE_ALL_SEC_LEVELS))
            continue;

        // do not process players which are not in world
        if (!target->IsInWorld())
            continue;

        // check if target is globally visible for player
        if (!target->IsVisibleGloballyFor(_player))
            continue;

        // check if target's level is in level range
        uint8 lvl = target->getLevel();
        if (lvl < request.MinLevel || lvl > request.MaxLevel)
            continue;

        // check if class matches classmask
        if (request.ClassFilter >= 0 && !(request.ClassFilter & (1 << target->getClass())))
            continue;

        // check if race matches racemask
        if (request.RaceFilter >= 0 && !(request.RaceFilter & (SI64LIT(1) << target->getRace())))
            continue;

        if (!whoRequest.Areas.empty())
        {
            if (std::find(whoRequest.Areas.begin(), whoRequest.Areas.end(), target->GetZoneId()) == whoRequest.Areas.end())
                continue;
        }

        std::wstring wTargetName;

        if (!Utf8toWStr(target->GetName(), wTargetName))
            continue;

        wstrToLower(wTargetName);

        if (!wPlayerName.empty() && wTargetName.find(wPlayerName) == std::wstring::npos)
            continue;

        Guild* targetGuild = target->GetGuild();
        std::wstring wTargetGuildName;

        if (!Utf8toWStr(targetGuild ? targetGuild->GetName() : "", wTargetGuildName))
            continue;

        wstrToLower(wTargetGuildName);

        if (!wGuildName.empty() && wTargetGuildName.find(wGuildName) == std::wstring::npos)
            continue;

        if (!wWords.empty())
        {
            std::string aName;
            if (AreaTableEntry const* areaEntry = sAreaTableStore.LookupEntry(target->GetZoneId()))
                aName = areaEntry->AreaName->Str[GetSessionDbcLocale()];

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
        if (!whoEntry.PlayerData.Initialize(target->GetGUID(), target))
            continue;

        if (targetGuild)
        {
            whoEntry.GuildGUID = targetGuild->GetGUID();
            whoEntry.GuildVirtualRealmAddress = GetVirtualRealmAddress();
            whoEntry.GuildName = targetGuild->GetName();
        }

        whoEntry.AreaID = target->GetZoneId();
        whoEntry.IsGM = target->IsGameMaster();

        response.Response.Entries.push_back(whoEntry);

        // 50 is maximum player count sent to client - can be overridden
        // through config, but is unstable
        if (response.Response.Entries.size() >= sWorld->getIntConfig(CONFIG_MAX_WHO))
            break;
    }

    SendPacket(response.Write());
}

void WorldSession::HandleLogoutRequestOpcode(WorldPackets::Character::LogoutRequest& /*logoutRequest*/)
{
    if (!GetPlayer()->GetLootGUID().IsEmpty())
        GetPlayer()->SendLootReleaseAll();

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

    WorldPackets::Character::LogoutResponse logoutResponse;
    logoutResponse.LogoutResult = reason;
    logoutResponse.Instant = instantLogout;
    SendPacket(logoutResponse.Write());

    if (reason)
    {
        SetLogoutStartTime(0);
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

    SetLogoutStartTime(time(NULL));
}

void WorldSession::HandleLogoutCancelOpcode(WorldPackets::Character::LogoutCancel& /*logoutCancel*/)
{
    // Player have already logged out serverside, too late to cancel
    if (!GetPlayer())
        return;

    SetLogoutStartTime(0);

    SendPacket(WorldPackets::Character::LogoutCancelAck().Write());

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
}

void WorldSession::HandleTogglePvP(WorldPackets::Misc::TogglePvP& /*packet*/)
{
    bool inPvP = GetPlayer()->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_IN_PVP);

    GetPlayer()->ApplyModFlag(PLAYER_FLAGS, PLAYER_FLAGS_IN_PVP, !inPvP);
    GetPlayer()->ApplyModFlag(PLAYER_FLAGS, PLAYER_FLAGS_PVP_TIMER, inPvP);

    if (GetPlayer()->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_IN_PVP))
    {
        if (!GetPlayer()->IsPvP() || GetPlayer()->pvpInfo.EndTimer)
            GetPlayer()->UpdatePvP(true, true);
    }
    else
    {
        if (!GetPlayer()->pvpInfo.IsHostile && GetPlayer()->IsPvP())
            GetPlayer()->pvpInfo.EndTimer = time(nullptr); // start toggle-off
    }
}

void WorldSession::HandleSetPvP(WorldPackets::Misc::SetPvP& packet)
{
    GetPlayer()->ApplyModFlag(PLAYER_FLAGS, PLAYER_FLAGS_IN_PVP, packet.EnablePVP);
    GetPlayer()->ApplyModFlag(PLAYER_FLAGS, PLAYER_FLAGS_PVP_TIMER, !packet.EnablePVP);

    if (GetPlayer()->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_IN_PVP))
    {
        if (!GetPlayer()->IsPvP() || GetPlayer()->pvpInfo.EndTimer)
            GetPlayer()->UpdatePvP(true, true);
    }
    else
    {
        if (!GetPlayer()->pvpInfo.IsHostile && GetPlayer()->IsPvP())
            GetPlayer()->pvpInfo.EndTimer = time(nullptr); // start set-off
    }
}

void WorldSession::HandlePortGraveyard(WorldPackets::Misc::PortGraveyard& /*packet*/)
{
    if (GetPlayer()->IsAlive() || !GetPlayer()->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_GHOST))
        return;
    GetPlayer()->RepopAtGraveyard();
}

void WorldSession::HandleRequestCemeteryList(WorldPackets::Misc::RequestCemeteryList& /*packet*/)
{
    uint32 zoneId = _player->GetZoneId();
    uint32 team = _player->GetTeam();

    std::vector<uint32> graveyardIds;
    auto range = sObjectMgr->GraveYardStore.equal_range(zoneId);

    for (auto it = range.first; it != range.second && graveyardIds.size() < 16; ++it) // client max
    {
        if (it->second.team == 0 || it->second.team == team)
            graveyardIds.push_back(it->first);
    }

    if (graveyardIds.empty())
    {
        TC_LOG_DEBUG("network", "No graveyards found for zone %u for %s (team %u) in CMSG_REQUEST_CEMETERY_LIST",
            zoneId, _player->GetGUID().ToString().c_str(), team);
        return;
    }

    WorldPackets::Misc::RequestCemeteryListResponse packet;
    packet.IsGossipTriggered = false;
    packet.CemeteryID.reserve(graveyardIds.size());

    for (uint32 id : graveyardIds)
        packet.CemeteryID.push_back(id);

    SendPacket(packet.Write());
}

void WorldSession::HandleSetSelectionOpcode(WorldPackets::Misc::SetSelection& packet)
{
    _player->SetSelection(packet.Selection);
}

void WorldSession::HandleStandStateChangeOpcode(WorldPackets::Misc::StandStateChange& packet)
{
    _player->SetStandState(packet.StandState);
}

void WorldSession::HandleReclaimCorpse(WorldPackets::Misc::ReclaimCorpse& /*packet*/)
{
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
    if (time_t(corpse->GetGhostTime() + _player->GetCorpseReclaimDelay(corpse->GetType() == CORPSE_RESURRECTABLE_PVP)) > time_t(time(NULL)))
        return;

    if (!corpse->IsWithinDistInMap(_player, CORPSE_RECLAIM_RADIUS, true))
        return;

    // resurrect
    _player->ResurrectPlayer(_player->InBattleground() ? 1.0f : 0.5f);

    // spawn bones
    _player->SpawnCorpseBones();
}

void WorldSession::HandleResurrectResponse(WorldPackets::Misc::ResurrectResponse& packet)
{
    if (GetPlayer()->IsAlive())
        return;

    if (packet.Response != 0) // Accept = 0 Decline = 1 Timeout = 2
    {
        GetPlayer()->ClearResurrectRequestData();           // reject
        return;
    }

    if (!GetPlayer()->IsResurrectRequestedBy(packet.Resurrecter))
        return;

    if (Player* ressPlayer = ObjectAccessor::GetPlayer(*GetPlayer(), packet.Resurrecter))
    {
        if (InstanceScript* instance = ressPlayer->GetInstanceScript())
        {
            if (instance->IsEncounterInProgress())
            {
                if (!instance->GetCombatResurrectionCharges())
                    return;
                else
                    instance->UseCombatResurrection();
            }
        }
    }

    GetPlayer()->ResurrectUsingRequestData();
}

void WorldSession::HandleAreaTriggerOpcode(WorldPackets::AreaTrigger::AreaTrigger& packet)
{
    Player* player = GetPlayer();
    if (player->IsInFlight())
    {
        TC_LOG_DEBUG("network", "HandleAreaTriggerOpcode: Player '%s' (%s) in flight, ignore Area Trigger ID:%u",
            player->GetName().c_str(), player->GetGUID().ToString().c_str(), packet.AreaTriggerID);
        return;
    }

    AreaTriggerEntry const* atEntry = sAreaTriggerStore.LookupEntry(packet.AreaTriggerID);
    if (!atEntry)
    {
        TC_LOG_DEBUG("network", "HandleAreaTriggerOpcode: Player '%s' (%s) send unknown (by DBC) Area Trigger ID:%u",
            player->GetName().c_str(), player->GetGUID().ToString().c_str(), packet.AreaTriggerID);
        return;
    }

    if (packet.Entered && !player->IsInAreaTriggerRadius(atEntry))
    {
        TC_LOG_DEBUG("network", "HandleAreaTriggerOpcode: Player '%s' (%s) too far, ignore Area Trigger ID: %u",
            player->GetName().c_str(), player->GetGUID().ToString().c_str(), packet.AreaTriggerID);
        return;
    }

    if (player->isDebugAreaTriggers)
        ChatHandler(player->GetSession()).PSendSysMessage(packet.Entered ? LANG_DEBUG_AREATRIGGER_ENTERED : LANG_DEBUG_AREATRIGGER_LEFT, packet.AreaTriggerID);

    if (sScriptMgr->OnAreaTrigger(player, atEntry, packet.Entered))
        return;

    if (player->IsAlive())
    {
        if (std::unordered_set<uint32> const* quests = sObjectMgr->GetQuestsForAreaTrigger(packet.AreaTriggerID))
        {
            for (uint32 questId : *quests)
            {
                Quest const* qInfo = sObjectMgr->GetQuestTemplate(questId);
                if (qInfo && player->GetQuestStatus(questId) == QUEST_STATUS_INCOMPLETE)
                {
                    for (QuestObjective const& obj : qInfo->Objectives)
                    {
                        if (obj.Type == QUEST_OBJECTIVE_AREATRIGGER && !player->IsQuestObjectiveComplete(obj))
                        {
                            player->SetQuestObjectiveData(obj, 1);
                            player->SendQuestUpdateAddCreditSimple(obj);
                            break;
                        }
                    }

                    if (player->CanCompleteQuest(questId))
                        player->CompleteQuest(questId);
                }
            }
        }
    }

    if (sObjectMgr->IsTavernAreaTrigger(packet.AreaTriggerID))
    {
        // set resting flag we are in the inn
        player->GetRestMgr().SetRestFlag(REST_FLAG_IN_TAVERN, atEntry->ID);

        if (sWorld->IsFFAPvPRealm())
            player->RemoveByteFlag(UNIT_FIELD_BYTES_2, UNIT_BYTES_2_OFFSET_PVP_FLAG, UNIT_BYTE2_FLAG_FFA_PVP);

        return;
    }

    if (Battleground* bg = player->GetBattleground())
        bg->HandleAreaTrigger(player, packet.AreaTriggerID, packet.Entered);

    if (OutdoorPvP* pvp = player->GetOutdoorPvP())
        if (pvp->HandleAreaTrigger(_player, packet.AreaTriggerID, packet.Entered))
            return;

    AreaTriggerStruct const* at = sObjectMgr->GetAreaTrigger(packet.AreaTriggerID);
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
                        player->SendTransferAborted(entry->ID, TRANSFER_ABORT_DIFFICULTY, player->GetDifficultyID(entry));
                    break;
                case Map::CANNOT_ENTER_NOT_IN_RAID:
                    TC_LOG_DEBUG("maps", "MAP: Player '%s' must be in a raid group to enter map %d", player->GetName().c_str(), at->target_mapId);
                    player->SendRaidGroupOnlyMessage(RAID_GROUP_ERR_ONLY, 0);
                    reviveAtTrigger = true;
                    break;
                case Map::CANNOT_ENTER_CORPSE_IN_DIFFERENT_INSTANCE:
                    player->GetSession()->SendPacket(WorldPackets::AreaTrigger::AreaTriggerNoCorpse().Write());
                    TC_LOG_DEBUG("maps", "MAP: Player '%s' does not have a corpse in instance map %d and cannot enter", player->GetName().c_str(), at->target_mapId);
                    break;
                case Map::CANNOT_ENTER_INSTANCE_BIND_MISMATCH:
                    if (MapEntry const* entry = sMapStore.LookupEntry(at->target_mapId))
                    {
                        char const* mapName = entry->MapName->Str[player->GetSession()->GetSessionDbcLocale()];
                        TC_LOG_DEBUG("maps", "MAP: Player '%s' cannot enter instance map '%s' because their permanent bind is incompatible with their group's", player->GetName().c_str(), mapName);
                        // is there a special opcode for this?
                        // @todo figure out how to get player localized difficulty string (e.g. "10 player", "Heroic" etc)
                        ChatHandler(player->GetSession()).PSendSysMessage(player->GetSession()->GetTrinityString(LANG_INSTANCE_BIND_MISMATCH), mapName);
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
    {
        WorldSafeLocsEntry const* entranceLocation = nullptr;
        InstanceSave* instanceSave = player->GetInstanceSave(at->target_mapId);
        if (instanceSave)
        {
            // Check if we can contact the instancescript of the instance for an updated entrance location
            if (Map* map = sMapMgr->FindMap(at->target_mapId, player->GetInstanceSave(at->target_mapId)->GetInstanceId()))
                if (InstanceMap* instanceMap = map->ToInstanceMap())
                    if (InstanceScript* instanceScript = instanceMap->GetInstanceScript())
                        entranceLocation = sWorldSafeLocsStore.LookupEntry(instanceScript->GetEntranceLocation());

            // Finally check with the instancesave for an entrance location if we did not get a valid one from the instancescript
            if (!entranceLocation)
                entranceLocation = sWorldSafeLocsStore.LookupEntry(instanceSave->GetEntranceLocation());
        }

        if (entranceLocation)
            player->TeleportTo(entranceLocation->MapID, entranceLocation->Loc.X, entranceLocation->Loc.Y, entranceLocation->Loc.Z, entranceLocation->Facing * M_PI / 180, TELE_TO_NOT_LEAVE_TRANSPORT);
        else
            player->TeleportTo(at->target_mapId, at->target_X, at->target_Y, at->target_Z, at->target_Orientation, TELE_TO_NOT_LEAVE_TRANSPORT);
    }
}

void WorldSession::HandleUpdateAccountData(WorldPackets::ClientConfig::UserClientUpdateAccountData& packet)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_UPDATE_ACCOUNT_DATA: type %u, time %u, decompressedSize %u",
        packet.DataType, packet.Time, packet.Size);

    if (packet.DataType > NUM_ACCOUNT_DATA_TYPES)
        return;

    if (packet.Size == 0)                               // erase
    {
        SetAccountData(AccountDataType(packet.DataType), 0, "");
        return;
    }

    if (packet.Size > 0xFFFF)
    {
        TC_LOG_ERROR("network", "UAD: Account data packet too big, size %u", packet.Size);
        return;
    }

    ByteBuffer dest;
    dest.resize(packet.Size);

    uLongf realSize = packet.Size;
    if (uncompress(dest.contents(), &realSize, packet.CompressedData.contents(), packet.CompressedData.size()) != Z_OK)
    {
        TC_LOG_ERROR("network", "UAD: Failed to decompress account data");
        return;
    }

    std::string adata;
    dest >> adata;

    SetAccountData(AccountDataType(packet.DataType), packet.Time, adata);
}

void WorldSession::HandleRequestAccountData(WorldPackets::ClientConfig::RequestAccountData& request)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_REQUEST_ACCOUNT_DATA: type %u", request.DataType);

    if (request.DataType >= NUM_ACCOUNT_DATA_TYPES)
        return;

    AccountData const* adata = GetAccountData(AccountDataType(request.DataType));

    WorldPackets::ClientConfig::UpdateAccountData data;
    data.Player = _player ? _player->GetGUID() : ObjectGuid::Empty;
    data.Time = adata->Time;
    data.Size = adata->Data.size();
    data.DataType = request.DataType;

    uLongf destSize = compressBound(data.Size);

    data.CompressedData.resize(destSize);

    if (data.Size && compress(data.CompressedData.contents(), &destSize, (uint8 const*)adata->Data.c_str(), data.Size) != Z_OK)
    {
        TC_LOG_ERROR("network", "RAD: Failed to compress account data");
        return;
    }

    data.CompressedData.resize(destSize);

    SendPacket(data.Write());
}

void WorldSession::HandleSetActionButtonOpcode(WorldPackets::Spells::SetActionButton& packet)
{
    uint32 action = ACTION_BUTTON_ACTION(packet.Action);
    uint32 type = ACTION_BUTTON_TYPE(packet.Action);

    TC_LOG_DEBUG("network", "CMSG_SET_ACTION_BUTTON Button: %u Action: %u Type: %u", packet.Index, action, type);

    if (!packet.Action)
        GetPlayer()->RemoveActionButton(packet.Index);
    else
        GetPlayer()->AddActionButton(packet.Index, action, type);
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

void WorldSession::HandleCompleteMovie(WorldPackets::Misc::CompleteMovie& /*packet*/)
{
    uint32 movie = _player->GetMovie();
    if (!movie)
        return;

    _player->SetMovie(0);
    sScriptMgr->OnMovieComplete(_player, movie);
}

void WorldSession::HandleSetActionBarToggles(WorldPackets::Character::SetActionBarToggles& packet)
{
    if (!GetPlayer())                                        // ignore until not logged (check needed because STATUS_AUTHED)
    {
        if (packet.Mask != 0)
            TC_LOG_ERROR("network", "WorldSession::HandleSetActionBarToggles in not logged state with value: %u, ignored", uint32(packet.Mask));
        return;
    }

    GetPlayer()->SetByteValue(ACTIVE_PLAYER_FIELD_BYTES, PLAYER_FIELD_BYTES_OFFSET_ACTION_BAR_TOGGLES, packet.Mask);
}

void WorldSession::HandlePlayedTime(WorldPackets::Character::RequestPlayedTime& packet)
{
    WorldPackets::Character::PlayedTime playedTime;
    playedTime.TotalTime = _player->GetTotalPlayedTime();
    playedTime.LevelTime = _player->GetLevelPlayedTime();
    playedTime.TriggerEvent = packet.TriggerScriptEvent;  // 0-1 - will not show in chat frame
    SendPacket(playedTime.Write());
}

void WorldSession::HandleWhoIsOpcode(WorldPackets::Who::WhoIsRequest& packet)
{
    TC_LOG_DEBUG("network", "Received whois command from player %s for character %s",
        GetPlayer()->GetName().c_str(), packet.CharName.c_str());

    if (!HasPermission(rbac::RBAC_PERM_OPCODE_WHOIS))
    {
        SendNotification(LANG_YOU_NOT_HAVE_PERMISSION);
        return;
    }

    if (packet.CharName.empty() || !normalizePlayerName(packet.CharName))
    {
        SendNotification(LANG_NEED_CHARACTER_NAME);
        return;
    }

    Player* player = ObjectAccessor::FindConnectedPlayerByName(packet.CharName);
    if (!player)
    {
        SendNotification(LANG_PLAYER_NOT_EXIST_OR_OFFLINE, packet.CharName.c_str());
        return;
    }

    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_ACCOUNT_WHOIS);
    stmt->setUInt32(0, player->GetSession()->GetAccountId());

    PreparedQueryResult result = LoginDatabase.Query(stmt);
    if (!result)
    {
        SendNotification(LANG_ACCOUNT_FOR_PLAYER_NOT_FOUND, packet.CharName.c_str());
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

    WorldPackets::Who::WhoIsResponse response;
    response.AccountName = packet.CharName + "'s " + "account is " + acc + ", e-mail: " + email + ", last ip: " + lastip;
    SendPacket(response.Write());
}

void WorldSession::HandleFarSightOpcode(WorldPackets::Misc::FarSight& packet)
{
    if (packet.Enable)
    {
        TC_LOG_DEBUG("network", "Added FarSight %s to %s", _player->GetGuidValue(ACTIVE_PLAYER_FIELD_FARSIGHT).ToString().c_str(), _player->GetGUID().ToString().c_str());
        if (WorldObject* target = _player->GetViewpoint())
            _player->SetSeer(target);
        else
            TC_LOG_DEBUG("network", "Player %s (%s) requests non-existing seer %s", _player->GetName().c_str(), _player->GetGUID().ToString().c_str(), _player->GetGuidValue(ACTIVE_PLAYER_FIELD_FARSIGHT).ToString().c_str());
    }
    else
    {
        TC_LOG_DEBUG("network", "%s set vision to self", _player->GetGUID().ToString().c_str());
        _player->SetSeer(_player);
    }

    GetPlayer()->UpdateVisibilityForPlayer();
}

void WorldSession::HandleSetTitleOpcode(WorldPackets::Character::SetTitle& packet)
{
    // -1 at none
    if (packet.TitleID > 0 && packet.TitleID < MAX_TITLE_INDEX)
    {
       if (!GetPlayer()->HasTitle(packet.TitleID))
            return;
    }
    else
        packet.TitleID = 0;

    GetPlayer()->SetUInt32Value(PLAYER_CHOSEN_TITLE, packet.TitleID);
}

void WorldSession::HandleTimeSyncResponse(WorldPackets::Misc::TimeSyncResponse& packet)
{
    // Prevent crashing server if queue is empty
    if (_player->m_timeSyncQueue.empty())
    {
        TC_LOG_ERROR("network", "Received CMSG_TIME_SYNC_RESPONSE from player %s without requesting it (hacker?)", _player->GetName().c_str());
        return;
    }

    if (packet.SequenceIndex != _player->m_timeSyncQueue.front())
        TC_LOG_ERROR("network", "Wrong time sync counter from player %s (cheater?)", _player->GetName().c_str());

    TC_LOG_DEBUG("network", "Time sync received: counter %u, client ticks %u, time since last sync %u", packet.SequenceIndex, packet.ClientTime, packet.ClientTime - _player->m_timeSyncClient);

    uint32 ourTicks = packet.ClientTime + (getMSTime() - _player->m_timeSyncServer);

    // diff should be small
    TC_LOG_DEBUG("network", "Our ticks: %u, diff %u, latency %u", ourTicks, ourTicks - packet.ClientTime, GetLatency());

    _player->m_timeSyncClient = packet.ClientTime;
    _player->m_timeSyncQueue.pop();
}

void WorldSession::HandleResetInstancesOpcode(WorldPackets::Instance::ResetInstances& /*packet*/)
{
    if (Group* group = _player->GetGroup())
    {
        if (group->IsLeader(_player->GetGUID()))
            group->ResetInstances(INSTANCE_RESET_ALL, false, false, _player);
    }
    else
        _player->ResetInstances(INSTANCE_RESET_ALL, false, false);
}

void WorldSession::HandleSetDungeonDifficultyOpcode(WorldPackets::Misc::SetDungeonDifficulty& setDungeonDifficulty)
{
    DifficultyEntry const* difficultyEntry = sDifficultyStore.LookupEntry(setDungeonDifficulty.DifficultyID);
    if (!difficultyEntry)
    {
        TC_LOG_DEBUG("network", "WorldSession::HandleSetDungeonDifficultyOpcode: %s sent an invalid instance mode %d!",
            _player->GetGUID().ToString().c_str(), setDungeonDifficulty.DifficultyID);
        return;
    }

    if (difficultyEntry->InstanceType != MAP_INSTANCE)
    {
        TC_LOG_DEBUG("network", "WorldSession::HandleSetDungeonDifficultyOpcode: %s sent an non-dungeon instance mode %d!",
            _player->GetGUID().ToString().c_str(), difficultyEntry->ID);
        return;
    }

    if (!(difficultyEntry->Flags & DIFFICULTY_FLAG_CAN_SELECT))
    {
        TC_LOG_DEBUG("network", "WorldSession::HandleSetDungeonDifficultyOpcode: %s sent unselectable instance mode %d!",
            _player->GetGUID().ToString().c_str(), difficultyEntry->ID);
        return;
    }

    Difficulty difficultyID = Difficulty(difficultyEntry->ID);
    if (difficultyID == _player->GetDungeonDifficultyID())
        return;

    // cannot reset while in an instance
    Map* map = _player->FindMap();
    if (map && map->IsDungeon())
    {
        TC_LOG_DEBUG("network", "WorldSession::HandleSetDungeonDifficultyOpcode: player (Name: %s, %s) tried to reset the instance while player is inside!",
            _player->GetName().c_str(), _player->GetGUID().ToString().c_str());
        return;
    }

    Group* group = _player->GetGroup();
    if (group)
    {
        if (group->IsLeader(_player->GetGUID()))
        {
            for (GroupReference* itr = group->GetFirstMember(); itr != NULL; itr = itr->next())
            {
                Player* groupGuy = itr->GetSource();
                if (!groupGuy)
                    continue;

                if (!groupGuy->IsInMap(groupGuy))
                    return;

                if (groupGuy->GetMap()->IsNonRaidDungeon())
                {
                    TC_LOG_DEBUG("network", "WorldSession::HandleSetDungeonDifficultyOpcode: %s tried to reset the instance while group member (Name: %s, %s) is inside!",
                        _player->GetGUID().ToString().c_str(), groupGuy->GetName().c_str(), groupGuy->GetGUID().ToString().c_str());
                    return;
                }
            }
            // the difficulty is set even if the instances can't be reset
            //_player->SendDungeonDifficulty(true);
            group->ResetInstances(INSTANCE_RESET_CHANGE_DIFFICULTY, false, false, _player);
            group->SetDungeonDifficultyID(difficultyID);
        }
    }
    else
    {
        _player->ResetInstances(INSTANCE_RESET_CHANGE_DIFFICULTY, false, false);
        _player->SetDungeonDifficultyID(difficultyID);
        _player->SendDungeonDifficulty();
    }
}

void WorldSession::HandleSetRaidDifficultyOpcode(WorldPackets::Misc::SetRaidDifficulty& setRaidDifficulty)
{
    DifficultyEntry const* difficultyEntry = sDifficultyStore.LookupEntry(setRaidDifficulty.DifficultyID);
    if (!difficultyEntry)
    {
        TC_LOG_DEBUG("network", "WorldSession::HandleSetDungeonDifficultyOpcode: %s sent an invalid instance mode %u!",
            _player->GetGUID().ToString().c_str(), setRaidDifficulty.DifficultyID);
        return;
    }

    if (difficultyEntry->InstanceType != MAP_RAID)
    {
        TC_LOG_DEBUG("network", "WorldSession::HandleSetDungeonDifficultyOpcode: %s sent an non-dungeon instance mode %u!",
            _player->GetGUID().ToString().c_str(), difficultyEntry->ID);
        return;
    }

    if (!(difficultyEntry->Flags & DIFFICULTY_FLAG_CAN_SELECT))
    {
        TC_LOG_DEBUG("network", "WorldSession::HandleSetDungeonDifficultyOpcode: %s sent unselectable instance mode %u!",
            _player->GetGUID().ToString().c_str(), difficultyEntry->ID);
        return;
    }

    if (((difficultyEntry->Flags & DIFFICULTY_FLAG_LEGACY) >> 5) != setRaidDifficulty.Legacy)
    {
        TC_LOG_DEBUG("network", "WorldSession::HandleSetDungeonDifficultyOpcode: %s sent not matching legacy difficulty %u!",
            _player->GetGUID().ToString().c_str(), difficultyEntry->ID);
        return;
    }

    Difficulty difficultyID = Difficulty(difficultyEntry->ID);
    if (difficultyID == (setRaidDifficulty.Legacy ?  _player->GetLegacyRaidDifficultyID() : _player->GetRaidDifficultyID()))
        return;

    // cannot reset while in an instance
    Map* map = _player->FindMap();
    if (map && map->IsDungeon())
    {
        TC_LOG_DEBUG("network", "WorldSession::HandleSetRaidDifficultyOpcode: player (Name: %s, %s) tried to reset the instance while player is inside!",
            _player->GetName().c_str(), _player->GetGUID().ToString().c_str());
        return;
    }

    Group* group = _player->GetGroup();
    if (group)
    {
        if (group->IsLeader(_player->GetGUID()))
        {
            for (GroupReference* itr = group->GetFirstMember(); itr != NULL; itr = itr->next())
            {
                Player* groupGuy = itr->GetSource();
                if (!groupGuy)
                    continue;

                if (!groupGuy->IsInMap(groupGuy))
                    return;

                if (groupGuy->GetMap()->IsRaid())
                {
                    TC_LOG_DEBUG("network", "WorldSession::HandleSetRaidDifficultyOpcode: %s tried to reset the instance while group member (Name: %s, %s) is inside!",
                        _player->GetGUID().ToString().c_str(), groupGuy->GetName().c_str(), groupGuy->GetGUID().ToString().c_str());
                    return;
                }
            }
            // the difficulty is set even if the instances can't be reset
            group->ResetInstances(INSTANCE_RESET_CHANGE_DIFFICULTY, true, setRaidDifficulty.Legacy != 0, _player);
            if (setRaidDifficulty.Legacy)
                group->SetLegacyRaidDifficultyID(difficultyID);
            else
                group->SetRaidDifficultyID(difficultyID);
        }
    }
    else
    {
        _player->ResetInstances(INSTANCE_RESET_CHANGE_DIFFICULTY, true, setRaidDifficulty.Legacy != 0);
        if (setRaidDifficulty.Legacy)
            _player->SetLegacyRaidDifficultyID(difficultyID);
        else
            _player->SetRaidDifficultyID(difficultyID);

        _player->SendRaidDifficulty(setRaidDifficulty.Legacy != 0);
    }
}

void WorldSession::HandleSetTaxiBenchmark(WorldPackets::Misc::SetTaxiBenchmarkMode& packet)
{
    _player->ApplyModFlag(PLAYER_FLAGS, PLAYER_FLAGS_TAXI_BENCHMARK, packet.Enable);
}

void WorldSession::HandleGuildSetFocusedAchievement(WorldPackets::Achievement::GuildSetFocusedAchievement& setFocusedAchievement)
{
    if (Guild* guild = sGuildMgr->GetGuildById(_player->GetGuildId()))
        guild->GetAchievementMgr().SendAchievementInfo(_player, setFocusedAchievement.AchievementID);
}

void WorldSession::HandleUITimeRequest(WorldPackets::Misc::UITimeRequest& /*request*/)
{
    WorldPackets::Misc::UITime response;
    response.Time = time(NULL);
    SendPacket(response.Write());
}

void WorldSession::HandleInstanceLockResponse(WorldPackets::Instance::InstanceLockResponse& packet)
{
    if (!_player->HasPendingBind())
    {
        TC_LOG_INFO("network", "InstanceLockResponse: Player %s (%s) tried to bind himself/teleport to graveyard without a pending bind!",
            _player->GetName().c_str(), _player->GetGUID().ToString().c_str());
        return;
    }

    if (packet.AcceptLock)
        _player->BindToInstance();
    else
        _player->RepopAtGraveyard();

    _player->SetPendingBind(0, 0);
}

void WorldSession::HandleViolenceLevel(WorldPackets::Misc::ViolenceLevel& /*violenceLevel*/)
{
    // do something?
}

void WorldSession::HandleObjectUpdateFailedOpcode(WorldPackets::Misc::ObjectUpdateFailed& objectUpdateFailed)
{
    TC_LOG_ERROR("network", "Object update failed for %s for player %s (%s)", objectUpdateFailed.ObjectGUID.ToString().c_str(), GetPlayerName().c_str(), _player->GetGUID().ToString().c_str());

    // If create object failed for current player then client will be stuck on loading screen
    if (_player->GetGUID() == objectUpdateFailed.ObjectGUID)
    {
        LogoutPlayer(true);
        return;
    }

    // Pretend we've never seen this object
    _player->m_clientGUIDs.erase(objectUpdateFailed.ObjectGUID);
}

void WorldSession::HandleObjectUpdateRescuedOpcode(WorldPackets::Misc::ObjectUpdateRescued& objectUpdateRescued)
{
    TC_LOG_ERROR("network", "Object update rescued for %s for player %s (%s)", objectUpdateRescued.ObjectGUID.ToString().c_str(), GetPlayerName().c_str(), _player->GetGUID().ToString().c_str());

    // Client received values update after destroying object
    // re-register object in m_clientGUIDs to send DestroyObject on next visibility update
    _player->m_clientGUIDs.insert(objectUpdateRescued.ObjectGUID);
}

void WorldSession::HandleSaveCUFProfiles(WorldPackets::Misc::SaveCUFProfiles& packet)
{
    if (packet.CUFProfiles.size() > MAX_CUF_PROFILES)
    {
        TC_LOG_ERROR("entities.player", "HandleSaveCUFProfiles - %s tried to save more than %i CUF profiles. Hacking attempt?", GetPlayerName().c_str(), MAX_CUF_PROFILES);
        return;
    }

    for (uint8 i = 0; i < packet.CUFProfiles.size(); ++i)
        GetPlayer()->SaveCUFProfile(i, std::move(packet.CUFProfiles[i]));

    for (uint8 i = packet.CUFProfiles.size(); i < MAX_CUF_PROFILES; ++i)
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

void WorldSession::HandleSetAdvancedCombatLogging(WorldPackets::ClientConfig::SetAdvancedCombatLogging& setAdvancedCombatLogging)
{
    _player->SetAdvancedCombatLogging(setAdvancedCombatLogging.Enable);
}

void WorldSession::HandleMountSpecialAnimOpcode(WorldPackets::Misc::MountSpecial& /*mountSpecial*/)
{
    WorldPackets::Misc::SpecialMountAnim specialMountAnim;
    specialMountAnim.UnitGUID = _player->GetGUID();
    GetPlayer()->SendMessageToSet(specialMountAnim.Write(), false);
}

void WorldSession::HandleMountSetFavorite(WorldPackets::Misc::MountSetFavorite& mountSetFavorite)
{
    _collectionMgr->MountSetFavorite(mountSetFavorite.MountSpellID, mountSetFavorite.IsFavorite);
}

void WorldSession::HandleCloseInteraction(WorldPackets::Misc::CloseInteraction& closeInteraction)
{
    if (_player->PlayerTalkClass->GetInteractionData().SourceGuid == closeInteraction.SourceGuid)
        _player->PlayerTalkClass->GetInteractionData().Reset();
}
