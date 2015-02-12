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
#include "AccountMgr.h"
#include "AreaTriggerPackets.h"
#include "BattlegroundMgr.h"
#include "CharacterPackets.h"
#include "Chat.h"
#include "CinematicMgr.h"
#include "ClientConfigPackets.h"
#include "Common.h"
#include "Corpse.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "DatabaseEnv.h"
#include "DBCStores.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "GameTime.h"
#include "GossipDef.h"
#include "Group.h"
#include "Language.h"
#include "Log.h"
#include "MapManager.h"
#include "MiscPackets.h"
#include "MovementPackets.h"
#include "Object.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "OutdoorPvP.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "SpellInfo.h"
#include "SpellPackets.h"
#include "WhoListStorage.h"
#include "WhoPackets.h"
#include "World.h"
#include "WorldPacket.h"
#include <cstdarg>
#include <zlib.h>

void WorldSession::HandleRepopRequest(WorldPackets::Misc::RepopRequest& /*packet*/)
{
    TC_LOG_DEBUG("network", "WORLD: Recvd CMSG_REPOP_REQUEST Message");

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
        TC_LOG_DEBUG("network", "HandleRepopRequestOpcode: got request after player {} {} was killed and before he was updated",
            GetPlayer()->GetName(), GetPlayer()->GetGUID().ToString());
        GetPlayer()->KillPlayer();
    }

    //this is spirit release confirm?
    GetPlayer()->RemoveGhoul();
    GetPlayer()->RemovePet(nullptr, PET_SAVE_NOT_IN_SLOT, true);
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
    if (_player->PlayerTalkClass->GetGossipMenu().GetSenderGUID() != guid)
        return;

    Creature* unit = nullptr;
    GameObject* go = nullptr;
    if (guid.IsCreatureOrVehicle())
    {
        unit = GetPlayer()->GetNPCIfCanInteractWith(guid, UNIT_NPC_FLAG_GOSSIP);
        if (!unit)
        {
            TC_LOG_DEBUG("network", "WORLD: HandleGossipSelectOptionOpcode - {} not found or you can't interact with him.", guid.ToString());
            return;
        }
    }
    else if (guid.IsGameObject())
    {
        go = _player->GetGameObjectIfCanInteractWith(guid);
        if (!go)
        {
            TC_LOG_DEBUG("network", "WORLD: HandleGossipSelectOptionOpcode - {} not found or you can't interact with it.", guid.ToString());
            return;
        }
    }
    else
    {
        TC_LOG_DEBUG("network", "WORLD: HandleGossipSelectOptionOpcode - unsupported {}.", guid.ToString());
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
            if (!unit->AI()->OnGossipSelectCode(_player, menuId, gossipListId, code.c_str()))
                _player->OnGossipSelect(unit, gossipListId, menuId);
        }
        else
        {
            if (!go->AI()->OnGossipSelectCode(_player, menuId, gossipListId, code.c_str()))
                _player->OnGossipSelect(go, gossipListId, menuId);
        }
    }
    else
    {
        if (unit)
        {
            if (!unit->AI()->OnGossipSelect(_player, menuId, gossipListId))
                _player->OnGossipSelect(unit, gossipListId, menuId);
        }
        else
        {
            if (!go->AI()->OnGossipSelect(_player, menuId, gossipListId))
                _player->OnGossipSelect(go, gossipListId, menuId);
        }
    }
}

void WorldSession::HandleWhoOpcode(WorldPackets::Who::WhoRequestPkt& whoRequest)
{
    WorldPackets::Who::WhoRequest& request = whoRequest.Request;

    TC_LOG_DEBUG("network", "WorldSession::HandleWhoOpcode: MinLevel: {}, MaxLevel: {}, Name: {}, Guild: {}, RaceFilter: 0x{:X}, ClassFilter: {}, Areas: {}, Words: {}.",
        request.MinLevel, request.MaxLevel, request.Name, request.Guild,
        request.RaceFilter, request.ClassFilter, whoRequest.Request.Areas.size(), request.Words.size());

    std::vector<std::wstring> wWords;
    wWords.resize(request.Words.size());
    for (size_t i = 0; i < request.Words.size(); ++i)
    {
        TC_LOG_DEBUG("network", "WorldSession::HandleWhoOpcode: Word: {}", request.Words[i].Word);

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
        int32 lvl = target.GetLevel();
        if (lvl < request.MinLevel || lvl > request.MaxLevel)
            continue;

        // check if class matches classmask
        if (request.ClassFilter >= 0 && !(request.ClassFilter & (1 << target.GetClass())))
            continue;

        // check if race matches racemask
        if (request.RaceFilter >= 0 && !(request.RaceFilter & (1 << target.GetRace())))
            continue;

        if (!whoRequest.Request.Areas.empty())
            if (std::ranges::find(whoRequest.Request.Areas, int32(target.GetZoneId())) == whoRequest.Request.Areas.end())
                continue;

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

        ++response.Response.TotalMatches;

        // 50 is maximum player count sent to client - can be overridden
        // through config, but is unstable
        if (response.Response.Entries.size() >= sWorld->getIntConfig(CONFIG_MAX_WHO))
            continue;

        WorldPackets::Who::WhoEntry& whoEntry = response.Response.Entries.emplace_back();
        whoEntry.Name = target.GetPlayerName();
        whoEntry.GuildName = target.GetGuildName();
        whoEntry.Level = target.GetLevel();
        whoEntry.ClassID = target.GetClass();
        whoEntry.Race = target.GetRace();
        whoEntry.Sex = target.GetGender();
        whoEntry.AreaID = target.GetZoneId();
    }

    SendPacket(response.Write());
}

void WorldSession::HandleLogoutRequestOpcode(WorldPackets::Character::LogoutRequest& /*logoutRequest*/)
{
    ObjectGuid lguid = GetPlayer()->GetLootGUID();
    if (!lguid.IsEmpty())
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
        GetPlayer()->SetUnitFlag(UNIT_FLAG_STUNNED);
    }

    SetLogoutStartTime(GameTime::GetGameTime());
}

void WorldSession::HandlePlayerLogoutOpcode(WorldPackets::Character::PlayerLogout& /*playerLogout*/)
{
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
        GetPlayer()->RemoveUnitFlag(UNIT_FLAG_STUNNED);
    }
}

void WorldSession::HandleTogglePvP(WorldPackets::Misc::TogglePvP& togglePvP)
{
    // this opcode can be used in two ways: Either set explicit new status or toggle old status
    if (togglePvP.Enable)
    {
        GetPlayer()->ApplyModFlag(PLAYER_FLAGS, PLAYER_FLAGS_IN_PVP, *togglePvP.Enable);
        GetPlayer()->ApplyModFlag(PLAYER_FLAGS, PLAYER_FLAGS_PVP_TIMER, !*togglePvP.Enable);
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
}

void WorldSession::HandleZoneUpdateOpcode(WorldPacket& recvData)
{
    uint32 newZone;
    recvData >> newZone;

    TC_LOG_DEBUG("network", "WORLD: Recvd ZONE_UPDATE: {}", newZone);

    // use server side data, but only after update the player position. See Player::UpdatePosition().
    GetPlayer()->SetNeedsZoneUpdate(true);

    //GetPlayer()->SendInitWorldStates(true, newZone);
}

void WorldSession::HandleSetSelectionOpcode(WorldPackets::Misc::SetSelection& packet)
{
    _player->SetSelection(packet.Selection);

    // Update target of current autoshoot spell
    if (!packet.Selection.IsEmpty())
    {
        if (Spell* autoReapeatSpell = _player->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
        {
            if (!autoReapeatSpell->GetSpellInfo()->HasAttribute(SPELL_ATTR4_UNK24) // client automatically handles spells with SPELL_ATTR4_AUTO_RANGED_COMBAT
                && autoReapeatSpell->m_targets.GetUnitTargetGUID() != packet.Selection)
            {
                Unit* unitTarget = [&]() -> Unit*
                {
                    Unit* unit = ObjectAccessor::GetUnit(*_player, packet.Selection);
                    if (unit && _player->IsValidAttackTarget(unit, autoReapeatSpell->GetSpellInfo()))
                        return unit;
                    return nullptr;
                }();

                if (unitTarget)
                    autoReapeatSpell->m_targets.SetUnitTarget(unitTarget);
                else
                    autoReapeatSpell->m_targets.RemoveObjectTarget();
            }
        }
    }
}

void WorldSession::HandleStandStateChangeOpcode(WorldPackets::Misc::StandStateChange& packet)
{
    switch (packet.StandState)
    {
        case UNIT_STAND_STATE_STAND:
        case UNIT_STAND_STATE_SIT:
        case UNIT_STAND_STATE_SLEEP:
        case UNIT_STAND_STATE_KNEEL:
            break;
        default:
            return;
    }

    _player->SetStandState(packet.StandState);
}

void WorldSession::HandleBugOpcode(WorldPacket& recvData)
{
    uint32 suggestion, contentlen, typelen;
    std::string content, type;

    recvData >> suggestion >> contentlen >> content;

    recvData >> typelen >> type;

    if (suggestion == 0)
        TC_LOG_DEBUG("network", "WORLD: Received CMSG_BUG [Bug Report]");
    else
        TC_LOG_DEBUG("network", "WORLD: Received CMSG_BUG [Suggestion]");

    TC_LOG_DEBUG("network", "{}", type);
    TC_LOG_DEBUG("network", "{}", content);

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_BUG_REPORT);

    stmt->setString(0, type);
    stmt->setString(1, content);

    CharacterDatabase.Execute(stmt);
}

void WorldSession::HandleReclaimCorpse(WorldPackets::Misc::ReclaimCorpse& /*packet*/)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_RECLAIM_CORPSE");

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

void WorldSession::HandleResurrectResponse(WorldPackets::Misc::ResurrectResponse& packet)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_RESURRECT_RESPONSE");

    if (GetPlayer()->IsAlive())
        return;

    if (packet.Response == 0)
    {
        GetPlayer()->ClearResurrectRequestData();           // reject
        return;
    }

    if (!GetPlayer()->IsResurrectRequestedBy(packet.Resurrecter))
        return;

    GetPlayer()->ResurrectUsingRequestData();
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

void WorldSession::HandleAreaTriggerOpcode(WorldPackets::AreaTrigger::AreaTrigger& packet)
{
    TC_LOG_DEBUG("network", "CMSG_AREATRIGGER. Trigger ID: {}", packet.AreaTriggerID);

    Player* player = GetPlayer();
    if (player->IsInFlight())
    {
        TC_LOG_DEBUG("network", "HandleAreaTriggerOpcode: Player '{}' {} in flight, ignore Area Trigger ID:{}",
            player->GetName(), player->GetGUID().ToString(), packet.AreaTriggerID);
        return;
    }

    AreaTriggerEntry const* atEntry = sAreaTriggerStore.LookupEntry(packet.AreaTriggerID);
    if (!atEntry)
    {
        TC_LOG_DEBUG("network", "HandleAreaTriggerOpcode: Player '{}' {} send unknown (by DBC) Area Trigger ID:{}",
            player->GetName(), player->GetGUID().ToString(), packet.AreaTriggerID);
        return;
    }

    if (!player->IsInAreaTriggerRadius(atEntry))
    {
        TC_LOG_DEBUG("network", "HandleAreaTriggerOpcode: Player '{}' {} too far, ignore Area Trigger ID: {}",
            player->GetName(), player->GetGUID().ToString(), packet.AreaTriggerID);
        return;
    }

    if (player->isDebugAreaTriggers)
        ChatHandler(player->GetSession()).PSendSysMessage(LANG_DEBUG_AREATRIGGER_REACHED, packet.AreaTriggerID);

    if (!sConditionMgr->IsObjectMeetingNotGroupedConditions(CONDITION_SOURCE_TYPE_AREATRIGGER_CLIENT_TRIGGERED, atEntry->ID, player))
        return;

    if (sScriptMgr->OnAreaTrigger(player, atEntry))
        return;

    if (player->IsAlive())
        if (uint32 questId = sObjectMgr->GetQuestForAreaTrigger(packet.AreaTriggerID))
            if (player->GetQuestStatus(questId) == QUEST_STATUS_INCOMPLETE)
                player->AreaExploredOrEventHappens(questId);

    if (sObjectMgr->IsTavernAreaTrigger(packet.AreaTriggerID))
    {
        // set resting flag we are in the inn
        player->SetRestFlag(REST_FLAG_IN_TAVERN, atEntry->ID);

        if (sWorld->IsFFAPvPRealm())
            player->RemovePvpFlag(UNIT_BYTE2_FLAG_FFA_PVP);

        return;
    }

    if (Battleground* bg = player->GetBattleground())
        if (bg->GetStatus() == STATUS_IN_PROGRESS)
            bg->HandleAreaTrigger(player, packet.AreaTriggerID);

    if (OutdoorPvP* pvp = player->GetOutdoorPvP())
        if (pvp->HandleAreaTrigger(_player, packet.AreaTriggerID))
            return;

    AreaTriggerTeleport const* at = sObjectMgr->GetAreaTrigger(packet.AreaTriggerID);
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
                    TC_LOG_DEBUG("maps", "MAP: Player '{}' attempted to enter map with id {} which has no entry", player->GetName(), at->target_mapId);
                    break;
                case Map::CANNOT_ENTER_UNINSTANCED_DUNGEON:
                    TC_LOG_DEBUG("maps", "MAP: Player '{}' attempted to enter dungeon map {} but no instance template was found", player->GetName(), at->target_mapId);
                    break;
                case Map::CANNOT_ENTER_DIFFICULTY_UNAVAILABLE:
                    TC_LOG_DEBUG("maps", "MAP: Player '{}' attempted to enter instance map {} but the requested difficulty was not found", player->GetName(), at->target_mapId);
                    if (MapEntry const* entry = sMapStore.LookupEntry(at->target_mapId))
                        player->SendTransferAborted(entry->ID, TRANSFER_ABORT_DIFFICULTY, player->GetGroup() ? player->GetGroup()->GetDifficultyID(entry) : player->GetDifficultyID(entry));
                    break;
                case Map::CANNOT_ENTER_NOT_IN_RAID:
                {
                    WorldPacket data(SMSG_RAID_GROUP_ONLY, 4 + 4);
                    data << uint32(0);
                    data << uint32(2); // You must be in a raid group to enter this instance.
                    player->SendDirectMessage(&data);
                    TC_LOG_DEBUG("maps", "MAP: Player '{}' must be in a raid group to enter instance map {}", player->GetName(), at->target_mapId);
                    reviveAtTrigger = true;
                    break;
                }
                case Map::CANNOT_ENTER_CORPSE_IN_DIFFERENT_INSTANCE:
                {
                    player->SendDirectMessage(WorldPackets::AreaTrigger::AreaTriggerNoCorpse().Write());
                    TC_LOG_DEBUG("maps", "MAP: Player '{}' does not have a corpse in instance map {} and cannot enter", player->GetName(), at->target_mapId);
                    break;
                }
                case Map::CANNOT_ENTER_INSTANCE_BIND_MISMATCH:
                    if (MapEntry const* entry = sMapStore.LookupEntry(at->target_mapId))
                    {
                        char const* mapName = entry->MapName[player->GetSession()->GetSessionDbcLocale()];
                        TC_LOG_DEBUG("maps", "MAP: Player '{}' cannot enter instance map '{}' because their permanent bind is incompatible with their group's", player->GetName(), mapName);
                        // is there a special opcode for this?
                        // @todo figure out how to get player localized difficulty string (e.g. "10 player", "Heroic" etc)
                        ChatHandler(player->GetSession()).PSendSysMessage(player->GetSession()->GetTrinityString(LANG_INSTANCE_BIND_MISMATCH), mapName);
                    }
                    reviveAtTrigger = true;
                    break;
                case Map::CANNOT_ENTER_TOO_MANY_INSTANCES:
                    player->SendTransferAborted(at->target_mapId, TRANSFER_ABORT_TOO_MANY_INSTANCES);
                    TC_LOG_DEBUG("maps", "MAP: Player '{}' cannot enter instance map {} because he has exceeded the maximum number of instances per hour.", player->GetName(), at->target_mapId);
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

void WorldSession::HandleUpdateAccountData(WorldPackets::ClientConfig::UserClientUpdateAccountData& packet)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_UPDATE_ACCOUNT_DATA: type {}, time {}, decompressedSize {}",
        packet.DataType, packet.Time, packet.Size);

    if (packet.DataType >= NUM_ACCOUNT_DATA_TYPES)
        return;

    if (packet.Size == 0)                               // erase
    {
        SetAccountData(AccountDataType(packet.DataType), 0, "");

        WorldPackets::ClientConfig::UpdateAccountDataComplete updateAccountDataComplete;
        updateAccountDataComplete.DataType = packet.DataType;
        updateAccountDataComplete.Result = 0;
        SendPacket(updateAccountDataComplete.Write());

        return;
    }

    if (packet.Size > 0xFFFF)
    {
        TC_LOG_ERROR("network", "UAD: Account data packet too big, size {}", packet.Size);
        return;
    }

    std::string dest;
    dest.resize(packet.Size);

    uLongf realSize = packet.Size;
    if (uncompress(reinterpret_cast<Bytef*>(dest.data()), &realSize, packet.CompressedData.data(), packet.CompressedData.size()) != Z_OK)
    {
        TC_LOG_ERROR("network", "UAD: Failed to decompress account data");
        return;
    }

    SetAccountData(AccountDataType(packet.DataType), packet.Time, dest);

    WorldPackets::ClientConfig::UpdateAccountDataComplete updateAccountDataComplete;
    updateAccountDataComplete.DataType = packet.DataType;
    updateAccountDataComplete.Result = 0;
    SendPacket(updateAccountDataComplete.Write());
}

void WorldSession::HandleRequestAccountData(WorldPackets::ClientConfig::RequestAccountData& request)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_REQUEST_ACCOUNT_DATA: type {}", request.DataType);

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

    if (data.Size && compress(data.CompressedData.data(), &destSize, (uint8 const*)adata->Data.c_str(), data.Size) != Z_OK)
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
    uint8 type = ACTION_BUTTON_TYPE(packet.Action);

    TC_LOG_DEBUG("network", "CMSG_SET_ACTION_BUTTON Button: {} Action: {} Type: {}", packet.Index, action, uint32(type));

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
            TC_LOG_ERROR("network", "WorldSession::HandleSetActionBarToggles in not logged state with value: {}, ignored", uint32(packet.Mask));
        return;
    }

    GetPlayer()->SetMultiActionBars(packet.Mask);
}

void WorldSession::HandlePlayedTime(WorldPackets::Character::PlayedTimeClient& packet)
{
    WorldPackets::Character::PlayedTime playedTime;
    playedTime.TotalTime = _player->GetTotalPlayedTime();
    playedTime.LevelTime = _player->GetLevelPlayedTime();
    playedTime.TriggerScriptEvent = packet.TriggerScriptEvent;  // 0-1 - will not show in chat frame
    SendPacket(playedTime.Write());
}

void WorldSession::HandleWorldTeleportOpcode(WorldPackets::Misc::WorldTeleport& worldTeleport)
{
    if (_player->IsInFlight())
    {
        TC_LOG_DEBUG("network", "Player '{}' ({}) in flight, ignore worldport command.",
            _player->GetName(), _player->GetGUID().ToString());
        return;
    }

    WorldLocation loc(worldTeleport.MapID, worldTeleport.Pos);
    loc.SetOrientation(worldTeleport.Facing);
    TC_LOG_DEBUG("network", "CMSG_WORLD_TELEPORT: Player = {}, time = {}, map = {}, pos = {}",
        _player->GetName(), worldTeleport.Time, worldTeleport.MapID, loc.ToString());

    if (HasPermission(rbac::RBAC_PERM_OPCODE_WORLD_TELEPORT))
        _player->TeleportTo(loc);
    else
        SendNotification(LANG_YOU_NOT_HAVE_PERMISSION);
}

void WorldSession::HandleWhoIsOpcode(WorldPackets::Who::WhoIsRequest& packet)
{
    TC_LOG_DEBUG("network", "Received whois command from player {} for character {}",
        GetPlayer()->GetName(), packet.CharName);

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

    LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_ACCOUNT_WHOIS);
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
    WorldPacket data(SMSG_COMPLAIN_RESULT, 1);
    data << uint8(0);
    SendPacket(&data);

    TC_LOG_DEBUG("network", "REPORT SPAM: type {}, {}, unk1 {}, unk2 {}, unk3 {}, unk4 {}, message {}",
        spam_type, spammer_guid.ToString(), unk1, unk2, unk3, unk4, description);
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
    //TC_LOG_DEBUG("response sent {}", unk);
}

void WorldSession::HandleFarSightOpcode(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "WORLD: CMSG_FAR_SIGHT");

    bool apply;
    recvData >> apply;

    if (apply)
    {
        TC_LOG_DEBUG("network", "Added FarSight {} to player {}", _player->GetGuidValue(PLAYER_FARSIGHT).ToString(), _player->GetGUID().ToString());
        if (WorldObject* target = _player->GetViewpoint())
            _player->SetSeer(target);
        else
            TC_LOG_DEBUG("network", "Player {} {} requests non-existing seer {}", _player->GetName(), _player->GetGUID().ToString(), _player->GetGuidValue(PLAYER_FARSIGHT).ToString());
    }
    else
    {
        TC_LOG_DEBUG("network", "Player {} set vision to self", _player->GetGUID().ToString());
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

void WorldSession::HandleSetDungeonDifficultyOpcode(WorldPackets::Misc::SetDungeonDifficulty& setDungeonDifficulty)
{
    TC_LOG_DEBUG("network", "MSG_SET_DUNGEON_DIFFICULTY");

    if (setDungeonDifficulty.DifficultyID >= MAX_DUNGEON_DIFFICULTY)
    {
        TC_LOG_DEBUG("network", "WorldSession::HandleSetDungeonDifficultyOpcode: {} sent an invalid instance mode {}!",
            _player->GetGUID().ToString(), setDungeonDifficulty.DifficultyID);
        return;
    }

    // cannot reset while in an instance
    Map* map = _player->FindMap();
    if (map && map->IsDungeon())
    {
        TC_LOG_DEBUG("network", "WorldSession::HandleSetDungeonDifficultyOpcode: player (Name: {}, {}) tried to reset the instance while player is inside!",
            _player->GetName(), _player->GetGUID().ToString());
        return;
    }

    Difficulty difficultyID = Difficulty(setDungeonDifficulty.DifficultyID);

    Group* group = _player->GetGroup();
    if (group)
    {
        if (difficultyID == group->GetDungeonDifficultyID())
            return;

        if (!group->IsLeader(_player->GetGUID()))
            return;

        if (group->isLFGGroup())
            return;

        for (GroupReference* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
        {
            Player* groupGuy = itr->GetSource();
            if (!groupGuy)
                continue;

            if (!groupGuy->IsInWorld())
                return;

            if (groupGuy->GetMap()->IsNonRaidDungeon())
            {
                TC_LOG_DEBUG("network", "WorldSession::HandleSetDungeonDifficultyOpcode: {} tried to reset the instance while group member (Name: {}, {}) is inside!",
                    _player->GetGUID().ToString(), groupGuy->GetName(), groupGuy->GetGUID().ToString());
                return;
            }
        }
        // the difficulty is set even if the instances can't be reset
        //_player->SendDungeonDifficulty(true);
        group->ResetInstances(INSTANCE_RESET_CHANGE_DIFFICULTY, false, _player);
        group->SetDungeonDifficultyID(Difficulty(setDungeonDifficulty.DifficultyID));
    }

    if (difficultyID == _player->GetDungeonDifficultyID())
        return;

    if (!group)
        _player->ResetInstances(INSTANCE_RESET_CHANGE_DIFFICULTY, false);

    _player->SetDungeonDifficultyID(Difficulty(setDungeonDifficulty.DifficultyID));
}

void WorldSession::HandleSetRaidDifficultyOpcode(WorldPackets::Misc::SetRaidDifficulty& setRaidDifficulty)
{
    TC_LOG_DEBUG("network", "MSG_SET_RAID_DIFFICULTY");

    if (setRaidDifficulty.DifficultyID >= MAX_RAID_DIFFICULTY)
    {
        TC_LOG_DEBUG("network", "WorldSession::HandleSetDungeonDifficultyOpcode: {} sent an invalid instance mode {}!",
            _player->GetGUID().ToString(), setRaidDifficulty.DifficultyID);
        return;
    }

    // cannot reset while in an instance
    Map* map = _player->FindMap();
    if (map && map->IsDungeon())
    {
        TC_LOG_DEBUG("network", "WorldSession::HandleSetRaidDifficultyOpcode: player (Name: {}, {}) tried to reset the instance while player is inside!",
            _player->GetName(), _player->GetGUID().ToString());
        return;
    }

    Difficulty difficultyID = Difficulty(setRaidDifficulty.DifficultyID);

    Group* group = _player->GetGroup();
    if (group)
    {
        if (difficultyID == group->GetRaidDifficultyID())
            return;

        if (!group->IsLeader(_player->GetGUID()))
            return;

        if (group->isLFGGroup())
            return;

        for (GroupReference* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
        {
            Player* groupGuy = itr->GetSource();
            if (!groupGuy)
                continue;

            if (!groupGuy->IsInWorld())
                return;

            if (groupGuy->GetMap()->IsRaid())
            {
                TC_LOG_DEBUG("network", "WorldSession::HandleSetRaidDifficultyOpcode: {} tried to reset the instance while group member (Name: {}, {}) is inside!",
                    _player->GetGUID().ToString(), groupGuy->GetName(), groupGuy->GetGUID().ToString());
                return;
            }
        }
        // the difficulty is set even if the instances can't be reset
        //_player->SendDungeonDifficulty(true);
        group->ResetInstances(INSTANCE_RESET_CHANGE_DIFFICULTY, true, _player);
        group->SetRaidDifficultyID(Difficulty(setRaidDifficulty.DifficultyID));
    }

    if (difficultyID == _player->GetRaidDifficultyID())
        return;

    if (!group)
        _player->ResetInstances(INSTANCE_RESET_CHANGE_DIFFICULTY, true);

    _player->SetRaidDifficultyID(Difficulty(setRaidDifficulty.DifficultyID));
}

void WorldSession::HandleSetTaxiBenchmarkOpcode(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "WORLD: CMSG_SET_TAXI_BENCHMARK_MODE");

    uint8 mode;
    recvData >> mode;

    mode ? _player->SetFlag(PLAYER_FLAGS, PLAYER_FLAGS_TAXI_BENCHMARK) : _player->RemoveFlag(PLAYER_FLAGS, PLAYER_FLAGS_TAXI_BENCHMARK);

    TC_LOG_DEBUG("network", "Client used \"/timetest {}\" command", mode);
}

void WorldSession::HandleUITimeRequest(WorldPackets::Misc::UITimeRequest& /*request*/)
{
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

void WorldSession::SendSetPhaseShift(uint32 PhaseShift)
{
    WorldPacket data(SMSG_SET_PHASE_SHIFT, 4);
    data << uint32(PhaseShift);
    SendPacket(&data);
}

void WorldSession::HandleInstanceLockResponse(WorldPacket& recvPacket)
{
    uint8 accept;
    recvPacket >> accept;

    if (!_player->HasPendingBind())
    {
        TC_LOG_INFO("network", "InstanceLockResponse: Player {} {} tried to bind himself/teleport to graveyard without a pending bind!",
            _player->GetName(), _player->GetGUID().ToString());
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
    float pitch, speed;
    TaggedPosition<Position::XYZ> firePos;
    TaggedPosition<Position::XYZ> impactPos;
    uint8 moveStop;

    recvPacket >> guid >> spellId >> pitch >> speed;
    recvPacket >> firePos;
    recvPacket >> impactPos;
    recvPacket >> moveStop;

    Unit* caster = ObjectAccessor::GetUnit(*_player, guid);
    Spell* spell = caster ? caster->GetCurrentSpell(CURRENT_GENERIC_SPELL) : nullptr;
    if (!spell || spell->m_spellInfo->Id != spellId || !spell->m_targets.HasDst() || !spell->m_targets.HasSrc())
    {
        recvPacket.rfinish();
        return;
    }

    spell->m_targets.ModSrc(firePos);
    spell->m_targets.ModDst(impactPos);

    spell->m_targets.SetPitch(pitch);
    spell->m_targets.SetSpeed(speed);

    if (moveStop)
    {
        OpcodeClient opcode = static_cast<OpcodeClient>(recvPacket.read<uint32>());
        MovementInfo movementInfo;
        recvPacket >> movementInfo.guid.ReadAsPacked();
        recvPacket >> movementInfo;
        HandleMovementOpcode(opcode, movementInfo);
    }
}
