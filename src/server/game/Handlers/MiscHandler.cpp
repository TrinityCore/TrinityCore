/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#include "Common.h"
#include "Language.h"
#include "DatabaseEnv.h"
#include "WorldPacket.h"
#include "Opcodes.h"
#include "Log.h"
#include "Player.h"
#include "GossipDef.h"
#include "World.h"
#include "ObjectMgr.h"
#include "GuildMgr.h"
#include "WorldSession.h"
#include "BigNumber.h"
#include "SHA1.h"
#include "UpdateData.h"
#include "LootMgr.h"
#include "Chat.h"
#include "zlib.h"
#include "ObjectAccessor.h"
#include "Object.h"
#include "Battleground.h"
#include "OutdoorPvP.h"
#include "Pet.h"
#include "CellImpl.h"
#include "AccountMgr.h"
#include "Vehicle.h"
#include "CreatureAI.h"
#include "DBCEnums.h"
#include "ScriptMgr.h"
#include "MapManager.h"
#include "InstanceScript.h"
#include "GameObjectAI.h"
#include "Group.h"
#include "AccountMgr.h"
#include "Spell.h"
#include "SpellPackets.h"
#include "BattlegroundMgr.h"
#include "Battlefield.h"
#include "BattlefieldMgr.h"
#include "DB2Stores.h"
#include "CharacterPackets.h"
#include "ClientConfigPackets.h"
#include "MiscPackets.h"
#include "NPCPackets.h"
#include "AchievementPackets.h"
#include "WhoPackets.h"

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
        TC_LOG_DEBUG("network", "HandleRepopRequestOpcode: got request after player %s(%s) was killed and before he was updated",
            GetPlayer()->GetName().c_str(), GetPlayer()->GetGUID().ToString().c_str());
        GetPlayer()->KillPlayer();
    }

    //this is spirit release confirm?
    GetPlayer()->RemovePet(NULL, PET_SAVE_NOT_IN_SLOT, true);
    GetPlayer()->BuildPlayerRepop();
    GetPlayer()->RepopAtGraveyard();
}

void WorldSession::HandleGossipSelectOptionOpcode(WorldPackets::NPC::GossipSelectOption& packet)
{
    if (!_player->PlayerTalkClass->GetGossipMenu().GetItem(packet.GossipIndex))
        return;

    // Prevent cheating on C++ scripted menus
    if (_player->PlayerTalkClass->GetGossipMenu().GetSenderGUID() != packet.GossipUnit)
        return;

    Creature* unit = nullptr;
    GameObject* go = nullptr;
    if (packet.GossipUnit.IsCreatureOrVehicle())
    {
        unit = GetPlayer()->GetNPCIfCanInteractWith(packet.GossipUnit, UNIT_NPC_FLAG_NONE);
        if (!unit)
        {

            TC_LOG_DEBUG("network", "WORLD: HandleGossipSelectOptionOpcode - %s not found or you can't interact with him.", packet.GossipUnit.ToString().c_str());
            return;
        }
    }
    else if (packet.GossipUnit.IsGameObject())
    {
        go = _player->GetMap()->GetGameObject(packet.GossipUnit);
        if (!go)
        {
            TC_LOG_DEBUG("network", "WORLD: HandleGossipSelectOptionOpcode - %s not found.", packet.GossipUnit.ToString().c_str());
            return;
        }
    }
    else
    {

        TC_LOG_DEBUG("network", "WORLD: HandleGossipSelectOptionOpcode - unsupported %s.", packet.GossipUnit.ToString().c_str());
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    if ((unit && unit->GetCreatureTemplate()->ScriptID != unit->LastUsedScriptID) || (go && go->GetGOInfo()->ScriptId != go->LastUsedScriptID))
    {
        TC_LOG_DEBUG("network", "WORLD: HandleGossipSelectOptionOpcode - Script reloaded while in use, ignoring and set new scipt id");
        if (unit)
            unit->LastUsedScriptID = unit->GetCreatureTemplate()->ScriptID;

        if (go)
            go->LastUsedScriptID = go->GetGOInfo()->ScriptId;
        _player->PlayerTalkClass->SendCloseGossip();
        return;
    }

    if (!packet.PromotionCode.empty())
    {
        if (unit)
        {
            unit->AI()->sGossipSelectCode(_player, packet.GossipID, packet.GossipIndex, packet.PromotionCode.c_str());
            if (!sScriptMgr->OnGossipSelectCode(_player, unit, _player->PlayerTalkClass->GetGossipOptionSender(packet.GossipIndex), _player->PlayerTalkClass->GetGossipOptionAction(packet.GossipIndex), packet.PromotionCode.c_str()))
                _player->OnGossipSelect(unit, packet.GossipIndex, packet.GossipID);
        }
        else
        {
            go->AI()->GossipSelectCode(_player, packet.GossipID, packet.GossipIndex, packet.PromotionCode.c_str());
            if (!sScriptMgr->OnGossipSelectCode(_player, go, _player->PlayerTalkClass->GetGossipOptionSender(packet.GossipIndex), _player->PlayerTalkClass->GetGossipOptionAction(packet.GossipIndex), packet.PromotionCode.c_str()))
                _player->OnGossipSelect(go, packet.GossipIndex, packet.GossipID);
        }
    }
    else
    {
        if (unit)
        {
            unit->AI()->sGossipSelect(_player, packet.GossipID, packet.GossipIndex);
            if (!sScriptMgr->OnGossipSelect(_player, unit, _player->PlayerTalkClass->GetGossipOptionSender(packet.GossipIndex), _player->PlayerTalkClass->GetGossipOptionAction(packet.GossipIndex)))
                _player->OnGossipSelect(unit, packet.GossipIndex, packet.GossipID);
        }
        else
        {
            go->AI()->GossipSelect(_player, packet.GossipID, packet.GossipIndex);
            if (!sScriptMgr->OnGossipSelect(_player, go, _player->PlayerTalkClass->GetGossipOptionSender(packet.GossipIndex), _player->PlayerTalkClass->GetGossipOptionAction(packet.GossipIndex)))
                _player->OnGossipSelect(go, packet.GossipIndex, packet.GossipID);
        }
    }
}

void WorldSession::HandleWhoOpcode(WorldPackets::Who::WhoRequestPkt& whoRequest)
{
    WorldPackets::Who::WhoRequest& request = whoRequest.Request;

    TC_LOG_DEBUG("network", "WorldSession::HandleWhoOpcode: MinLevel: %u, MaxLevel: %u, Name: %s (VirtualRealmName: %s), Guild: %s (GuildVirtualRealmName: %s), RaceFilter: %d, ClassFilter: %d, Areas: " SZFMTD ", Words: " SZFMTD ".",
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
        if (request.RaceFilter >= 0 && !(request.RaceFilter & (1 << target->getRace())))
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
            if (AreaTableEntry const* areaEntry = GetAreaEntryByAreaID(target->GetZoneId()))
                aName = areaEntry->ZoneName;

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
    TC_LOG_DEBUG("network", "WORLD: Recvd CMSG_LOGOUT_REQUEST Message, security - %u", GetSecurity());

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
        GetPlayer()->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);
    }

    SetLogoutStartTime(time(NULL));
}

void WorldSession::HandleLogoutCancelOpcode(WorldPackets::Character::LogoutCancel& /*logoutCancel*/)
{
    TC_LOG_DEBUG("network", "WORLD: Recvd CMSG_LOGOUT_CANCEL Message");

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
            GetPlayer()->pvpInfo.EndTimer = time(NULL);     // start toggle-off
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

void WorldSession::HandleBugReportOpcode(WorldPacket& recvData)
{
    uint32 suggestion, contentlen, typelen;
    std::string content, type;

    recvData >> suggestion >> contentlen;
    content = recvData.ReadString(contentlen);

    recvData >> typelen;
    type = recvData.ReadString(typelen);

    if (suggestion == 0)
        TC_LOG_DEBUG("network", "WORLD: Received CMSG_BUG_REPORT [Bug Report]");
    else
        TC_LOG_DEBUG("network", "WORLD: Received CMSG_BUG_REPORT [Suggestion]");

    TC_LOG_DEBUG("network", "%s", type.c_str());
    TC_LOG_DEBUG("network", "%s", content.c_str());

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_BUG_REPORT);

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

void WorldSession::SendAreaTriggerMessage(const char* Text, ...)
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

void WorldSession::HandleAreaTriggerOpcode(WorldPackets::Misc::AreaTrigger& packet)
{
    TC_LOG_DEBUG("network", "CMSG_AREATRIGGER. Trigger ID: %u", packet.AreaTriggerID);

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

    if (player->GetMapId() != atEntry->MapID)
    {
        TC_LOG_DEBUG("network", "HandleAreaTriggerOpcode: Player '%s' (%s) too far (trigger map: %u player map: %u), ignore Area Trigger ID: %u",
            player->GetName().c_str(), player->GetGUID().ToString().c_str(), atEntry->MapID, player->GetMapId(), packet.AreaTriggerID);
        return;
    }

    // delta is safe radius
    const float delta = 5.0f;

    if (atEntry->Radius > 0)
    {
        // if we have radius check it
        float dist = player->GetDistance(atEntry->Pos.X, atEntry->Pos.Y, atEntry->Pos.Z);
        if (dist > atEntry->Radius + delta)
        {
            TC_LOG_DEBUG("network", "HandleAreaTriggerOpcode: Player '%s' (%s) too far (radius: %f distance: %f), ignore Area Trigger ID: %u",
                player->GetName().c_str(), player->GetGUID().ToString().c_str(), atEntry->Radius, dist, packet.AreaTriggerID);
            return;
        }
    }
    else
    {
        // we have only extent

        // rotate the players position instead of rotating the whole cube, that way we can make a simplified
        // is-in-cube check and we have to calculate only one point instead of 4

        // 2PI = 360°, keep in mind that ingame orientation is counter-clockwise
        double rotation = 2 * M_PI - atEntry->BoxYaw;
        double sinVal = std::sin(rotation);
        double cosVal = std::cos(rotation);

        float playerBoxDistX = player->GetPositionX() - atEntry->Pos.X;
        float playerBoxDistY = player->GetPositionY() - atEntry->Pos.Y;

        float rotPlayerX = float(atEntry->Pos.X + playerBoxDistX * cosVal - playerBoxDistY*sinVal);
        float rotPlayerY = float(atEntry->Pos.Y + playerBoxDistY * cosVal + playerBoxDistX*sinVal);

        // box edges are parallel to coordiante axis, so we can treat every dimension independently :D
        float dz = player->GetPositionZ() - atEntry->Pos.Z;
        float dx = rotPlayerX - atEntry->Pos.X;
        float dy = rotPlayerY - atEntry->Pos.Y;
        if ((std::fabs(dx) > atEntry->BoxLength / 2 + delta) ||
            (std::fabs(dy) > atEntry->BoxWidth / 2 + delta) ||
            (std::fabs(dz) > atEntry->BoxHeight / 2 + delta))
        {
            TC_LOG_DEBUG("network", "HandleAreaTriggerOpcode: Player '%s' (%s) too far (1/2 box X: %f 1/2 box Y: %f 1/2 box Z: %f rotatedPlayerX: %f rotatedPlayerY: %f dZ:%f), ignore Area Trigger ID: %u",
                player->GetName().c_str(), player->GetGUID().ToString().c_str(), atEntry->BoxLength / 2, atEntry->BoxWidth / 2, atEntry->BoxHeight / 2, rotPlayerX, rotPlayerY, dz, packet.AreaTriggerID);
            return;
        }
    }

    if (player->isDebugAreaTriggers)
        ChatHandler(player->GetSession()).PSendSysMessage(LANG_DEBUG_AREATRIGGER_REACHED, packet.AreaTriggerID);

    if (sScriptMgr->OnAreaTrigger(player, atEntry))
        return;

    if (player->IsAlive())
    {
        if (uint32 questId = sObjectMgr->GetQuestForAreaTrigger(packet.AreaTriggerID))
        {
            Quest const* qInfo = sObjectMgr->GetQuestTemplate(questId);
            if (qInfo && player->GetQuestStatus(questId) == QUEST_STATUS_INCOMPLETE)
            {
                for (uint8 j = 0; j < qInfo->Objectives.size(); ++j)
                {
                    if (qInfo->Objectives[j].Type == QUEST_OBJECTIVE_AREATRIGGER)
                    {
                        player->SetQuestObjectiveData(qInfo, j, int32(true));
                        break;
                    }
                }

                if (player->CanCompleteQuest(questId))
                    player->CompleteQuest(questId);
            }
        }
    }

    if (sObjectMgr->IsTavernAreaTrigger(packet.AreaTriggerID))
    {
        // set resting flag we are in the inn
        player->SetFlag(PLAYER_FLAGS, PLAYER_FLAGS_RESTING);
        player->InnEnter(time(NULL), atEntry->MapID, atEntry->Pos.X, atEntry->Pos.Y, atEntry->Pos.Z);
        player->SetRestType(REST_TYPE_IN_TAVERN);

        if (sWorld->IsFFAPvPRealm())
            player->RemoveByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_FFA_PVP);

        return;
    }

    if (Battleground* bg = player->GetBattleground())
        if (bg->GetStatus() == STATUS_IN_PROGRESS)
            bg->HandleAreaTrigger(player, packet.AreaTriggerID);

    if (OutdoorPvP* pvp = player->GetOutdoorPvP())
        if (pvp->HandleAreaTrigger(_player, packet.AreaTriggerID))
            return;

    AreaTriggerStruct const* at = sObjectMgr->GetAreaTrigger(packet.AreaTriggerID);
    if (!at)
        return;

    bool teleported = false;
    if (player->GetMapId() != at->target_mapId)
    {
        if (!sMapMgr->CanPlayerEnter(at->target_mapId, player, false))
            return;

        if (Group* group = player->GetGroup())
            if (group->isLFGGroup() && player->GetMap()->IsDungeon())
                teleported = player->TeleportToBGEntryPoint();
    }

    if (!teleported)
        player->TeleportTo(at->target_mapId, at->target_X, at->target_Y, at->target_Z, at->target_Orientation, TELE_TO_NOT_LEAVE_TRANSPORT);
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

int32 WorldSession::HandleEnableNagleAlgorithm()
{
    // Instructs the server we wish to receive few amounts of large packets (SMSG_MULTIPLE_PACKETS?)
    // instead of large amount of small packets
    return 0;
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

void WorldSession::HandleCompleteCinematic(WorldPacket& /*recvData*/)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_COMPLETE_CINEMATIC");
}

void WorldSession::HandleNextCinematicCamera(WorldPacket& /*recvData*/)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_NEXT_CINEMATIC_CAMERA");
}

void WorldSession::HandleMoveTimeSkippedOpcode(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_MOVE_TIME_SKIPPED");

    ObjectGuid guid;
    uint32 time;
    recvData >> time;

    guid[5] = recvData.ReadBit();
    guid[1] = recvData.ReadBit();
    guid[3] = recvData.ReadBit();
    guid[7] = recvData.ReadBit();
    guid[6] = recvData.ReadBit();
    guid[0] = recvData.ReadBit();
    guid[4] = recvData.ReadBit();
    guid[2] = recvData.ReadBit();

    recvData.ReadByteSeq(guid[7]);
    recvData.ReadByteSeq(guid[1]);
    recvData.ReadByteSeq(guid[2]);
    recvData.ReadByteSeq(guid[4]);
    recvData.ReadByteSeq(guid[3]);
    recvData.ReadByteSeq(guid[6]);
    recvData.ReadByteSeq(guid[0]);
    recvData.ReadByteSeq(guid[5]);

    //TODO!

    /*
        uint64 guid;
        uint32 time_skipped;
        recvData >> guid;
        recvData >> time_skipped;
        TC_LOG_DEBUG("network", "WORLD: CMSG_MOVE_TIME_SKIPPED");

        //// @todo
        must be need use in Trinity
        We substract server Lags to move time (AntiLags)
        for exmaple
        GetPlayer()->ModifyLastMoveTime(-int32(time_skipped));
    */
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

    TC_LOG_DEBUG("network", "WORLD: CMSG_MOVE_FORCE_UNROOT_ACK");

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

    TC_LOG_DEBUG("network", "WORLD: CMSG_MOVE_FORCE_ROOT_ACK");

    recvData.read_skip<uint32>();                          // unk

    MovementInfo movementInfo;
    ReadMovementInfo(recvData, &movementInfo);
*/
}

void WorldSession::HandleSetActionBarToggles(WorldPackets::Character::SetActionBarToggles& packet)
{
    if (!GetPlayer())                                        // ignore until not logged (check needed because STATUS_AUTHED)
    {
        if (packet.Mask != 0)
            TC_LOG_ERROR("network", "WorldSession::HandleSetActionBarToggles in not logged state with value: %u, ignored", uint32(packet.Mask));
        return;
    }

    GetPlayer()->SetByteValue(PLAYER_FIELD_BYTES, PLAYER_FIELD_BYTES_OFFSET_ACTION_BAR_TOGGLES, packet.Mask);
}

void WorldSession::HandlePlayedTime(WorldPackets::Character::PlayedTimeClient& packet)
{
    WorldPackets::Character::PlayedTime playedTime;
    playedTime.TotalTime = _player->GetTotalPlayedTime();
    playedTime.LevelTime = _player->GetLevelPlayedTime();
    playedTime.TriggerEvent = packet.TriggerScriptEvent;  // 0-1 - will not show in chat frame
    SendPacket(playedTime.Write());
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
        TC_LOG_DEBUG("network", "Player '%s' (%s) in flight, ignore worldport command.",
            GetPlayer()->GetName().c_str(), GetPlayer()->GetGUID().ToString().c_str());
        return;
    }

    TC_LOG_DEBUG("network", "CMSG_WORLD_TELEPORT: Player = %s, Time = %u, map = %u, x = %f, y = %f, z = %f, o = %f",
        GetPlayer()->GetName().c_str(), time, mapid, PositionX, PositionY, PositionZ, Orientation);

    if (HasPermission(rbac::RBAC_PERM_OPCODE_WORLD_TELEPORT))
        GetPlayer()->TeleportTo(mapid, PositionX, PositionY, PositionZ, Orientation);
    else
        SendNotification(LANG_YOU_NOT_HAVE_PERMISSION);
}

void WorldSession::HandleWhoisOpcode(WorldPackets::Who::WhoIsRequest& packet)
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
    WorldPacket data(SMSG_COMPLAINT_RESULT, 2);
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
        TC_LOG_DEBUG("network", "Added FarSight %s to %s", _player->GetGuidValue(PLAYER_FARSIGHT).ToString().c_str(), _player->GetGUID().ToString().c_str());
        if (WorldObject* target = _player->GetViewpoint())
            _player->SetSeer(target);
        else
            TC_LOG_ERROR("network", "Player %s (%s) requests non-existing seer %s", _player->GetName().c_str(), _player->GetGUID().ToString().c_str(), _player->GetGuidValue(PLAYER_FARSIGHT).ToString().c_str());
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
    TC_LOG_DEBUG("network", "CMSG_SET_TITLE");
    
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
    TC_LOG_DEBUG("network", "CMSG_TIME_SYNC_RESPONSE");

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

void WorldSession::HandleResetInstancesOpcode(WorldPacket& /*recvData*/)
{
    TC_LOG_DEBUG("network", "WORLD: CMSG_RESET_INSTANCES");

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

    _player->m_mover->m_movementInfo.flags = movementInfo.GetMovementFlags();
}

void WorldSession::HandleRequestPetInfoOpcode(WorldPacket& /*recvData */)
{
    /*
        TC_LOG_DEBUG("network", "WORLD: CMSG_REQUEST_PET_INFO");
        recvData.hexlike();
    */
}

void WorldSession::HandleSetTaxiBenchmarkOpcode(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "WORLD: CMSG_SET_TAXI_BENCHMARK_MODE");

    uint8 mode;
    recvData >> mode;

    mode ? _player->SetFlag(PLAYER_FLAGS, PLAYER_FLAGS_TAXI_BENCHMARK) : _player->RemoveFlag(PLAYER_FLAGS, PLAYER_FLAGS_TAXI_BENCHMARK);

    TC_LOG_DEBUG("network", "Client used \"/timetest %d\" command", mode);
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

void WorldSession::SendSetPhaseShift(std::set<uint32> const& phaseIds, std::set<uint32> const& terrainswaps, std::set<uint32> const& worldMapAreaSwaps)
{
    ObjectGuid guid = _player->GetGUID();

    WorldPacket data(SMSG_SET_PHASE_SHIFT_CHANGE, 1 + 8 + 4 + 4 + 4 + 4 + 2 * phaseIds.size() + 4 + terrainswaps.size() * 2);
    data.WriteBit(guid[2]);
    data.WriteBit(guid[3]);
    data.WriteBit(guid[1]);
    data.WriteBit(guid[6]);
    data.WriteBit(guid[4]);
    data.WriteBit(guid[5]);
    data.WriteBit(guid[0]);
    data.WriteBit(guid[7]);

    data.WriteByteSeq(guid[7]);
    data.WriteByteSeq(guid[4]);

    data << uint32(worldMapAreaSwaps.size());
    for (auto mapSwap : worldMapAreaSwaps)
        data << uint16(mapSwap);                    // WorldMapArea.dbc id (controls map display)

    data.WriteByteSeq(guid[1]);

    data << uint32(phaseIds.size() ? 0 : 8);  // flags (not phasemask)

    data.WriteByteSeq(guid[2]);
    data.WriteByteSeq(guid[6]);

    data << uint32(0);                          // Inactive terrain swaps
    //for (uint8 i = 0; i < inactiveSwapsCount; ++i)
    //    data << uint16(0);

    data << uint32(phaseIds.size()) * 2;        // Phase.dbc ids
    for (std::set<uint32>::const_iterator itr = phaseIds.begin(); itr != phaseIds.end(); ++itr)
        data << uint16(*itr);

    data.WriteByteSeq(guid[3]);
    data.WriteByteSeq(guid[0]);

    data << uint32(terrainswaps.size()) * 2;    // Active terrain swaps
    for (std::set<uint32>::const_iterator itr = terrainswaps.begin(); itr != terrainswaps.end(); ++itr)
        data << uint16(*itr);

    data.WriteByteSeq(guid[5]);

    SendPacket(&data);
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

    if (/*Battlefield* bf = */sBattlefieldMgr->GetBattlefieldToZoneId(_player->GetZoneId()))
    {
        // bf->PlayerAskToLeave(_player); FIXME
        return;
    }

    AreaTableEntry const* atEntry = GetAreaEntryByAreaID(_player->GetAreaId());
    if (!atEntry || !(atEntry->Flags[0] & AREA_FLAG_WINTERGRASP_2))
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
        TC_LOG_INFO("network", "InstanceLockResponse: Player %s (%s) tried to bind himself/teleport to graveyard without a pending bind!",
            _player->GetName().c_str(), _player->GetGUID().ToString().c_str());
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
    float curX, curY, curZ;
    float targetX, targetY, targetZ;
    uint8 moveStop;

    recvPacket >> guid >> spellId >> pitch >> speed;
    recvPacket >> curX >> curY >> curZ;
    recvPacket >> targetX >> targetY >> targetZ;
    recvPacket >> moveStop;

    Unit* caster = ObjectAccessor::GetUnit(*_player, guid);
    Spell* spell = caster ? caster->GetCurrentSpell(CURRENT_GENERIC_SPELL) : NULL;
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

    spell->m_targets.SetPitch(pitch);
    spell->m_targets.SetSpeed(speed);

    if (moveStop)
    {
        uint32 opcode;
        recvPacket >> opcode;
        recvPacket.SetOpcode(CMSG_MOVE_STOP); // always set to CMSG_MOVE_STOP in client SetOpcode
        //HandleMovementOpcodes(recvPacket);
    }
}

void WorldSession::HandleViolenceLevel(WorldPackets::Misc::ViolenceLevel& /*violenceLevel*/)
{
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
    TC_LOG_ERROR("network", "Object update failed for %s (%s) for player %s (%s)", guid.ToString().c_str(), obj ? obj->GetName().c_str() : "object-not-found", GetPlayerName().c_str(), _player->GetGUID().ToString().c_str());

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

    CUFProfile* profiles[MAX_CUF_PROFILES];
    uint8 strlens[MAX_CUF_PROFILES];

    for (uint8 i = 0; i < count; ++i)
    {
        profiles[i] = new CUFProfile;
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
        recvPacket >> profiles[i]->Unk146;
        profiles[i]->ProfileName = recvPacket.ReadString(strlens[i]);
        recvPacket >> profiles[i]->Unk152;
        recvPacket >> profiles[i]->FrameHeight;
        recvPacket >> profiles[i]->FrameWidth;
        recvPacket >> profiles[i]->Unk150;
        recvPacket >> profiles[i]->HealthText;
        recvPacket >> profiles[i]->Unk147;
        recvPacket >> profiles[i]->SortBy;
        recvPacket >> profiles[i]->Unk154;
        recvPacket >> profiles[i]->Unk148;

        GetPlayer()->SaveCUFProfile(i, profiles[i]);
    }

    for (uint8 i = count; i < MAX_CUF_PROFILES; ++i)
        GetPlayer()->SaveCUFProfile(i, NULL);
}

void WorldSession::SendLoadCUFProfiles()
{
    Player* player = GetPlayer();

    uint8 count = player->GetCUFProfilesCount();

    ByteBuffer byteBuffer(25 * count);
    WorldPacket data(SMSG_LOAD_CUF_PROFILES, 5 * count + 25 * count);

    data.WriteBits(count, 20);
    for (uint8 i = 0; i < MAX_CUF_PROFILES; ++i)
    {
        CUFProfile* profile = player->GetCUFProfile(i);
        if (!profile)
            continue;

        data.WriteBit(profile->BoolOptions[CUF_UNK_157]);
        data.WriteBit(profile->BoolOptions[CUF_AUTO_ACTIVATE_10_PLAYERS]);
        data.WriteBit(profile->BoolOptions[CUF_AUTO_ACTIVATE_5_PLAYERS]);
        data.WriteBit(profile->BoolOptions[CUF_AUTO_ACTIVATE_25_PLAYERS]);
        data.WriteBit(profile->BoolOptions[CUF_DISPLAY_HEAL_PREDICTION]);
        data.WriteBit(profile->BoolOptions[CUF_AUTO_ACTIVATE_PVE]);
        data.WriteBit(profile->BoolOptions[CUF_DISPLAY_HORIZONTAL_GROUPS]);
        data.WriteBit(profile->BoolOptions[CUF_AUTO_ACTIVATE_40_PLAYERS]);
        data.WriteBit(profile->BoolOptions[CUF_AUTO_ACTIVATE_3_PLAYERS]);
        data.WriteBit(profile->BoolOptions[CUF_DISPLAY_AGGRO_HIGHLIGHT]);
        data.WriteBit(profile->BoolOptions[CUF_DISPLAY_BORDER]);
        data.WriteBit(profile->BoolOptions[CUF_AUTO_ACTIVATE_2_PLAYERS]);
        data.WriteBit(profile->BoolOptions[CUF_DISPLAY_NON_BOSS_DEBUFFS]);
        data.WriteBit(profile->BoolOptions[CUF_DISPLAY_MAIN_TANK_AND_ASSIST]);
        data.WriteBit(profile->BoolOptions[CUF_UNK_156]);
        data.WriteBit(profile->BoolOptions[CUF_AUTO_ACTIVATE_SPEC_2]);
        data.WriteBit(profile->BoolOptions[CUF_USE_CLASS_COLORS]);
        data.WriteBit(profile->BoolOptions[CUF_DISPLAY_POWER_BAR]);
        data.WriteBit(profile->BoolOptions[CUF_AUTO_ACTIVATE_SPEC_1]);
        data.WriteBits(profile->ProfileName.size(), 8);
        data.WriteBit(profile->BoolOptions[CUF_DISPLAY_ONLY_DISPELLABLE_DEBUFFS]);
        data.WriteBit(profile->BoolOptions[CUF_KEEP_GROUPS_TOGETHER]);
        data.WriteBit(profile->BoolOptions[CUF_UNK_145]);
        data.WriteBit(profile->BoolOptions[CUF_AUTO_ACTIVATE_15_PLAYERS]);
        data.WriteBit(profile->BoolOptions[CUF_DISPLAY_PETS]);
        data.WriteBit(profile->BoolOptions[CUF_AUTO_ACTIVATE_PVP]);

        byteBuffer << uint16(profile->Unk154);
        byteBuffer << uint16(profile->FrameHeight);
        byteBuffer << uint16(profile->Unk152);
        byteBuffer << uint8(profile->Unk147);
        byteBuffer << uint16(profile->Unk150);
        byteBuffer << uint8(profile->Unk146);
        byteBuffer << uint8(profile->HealthText);
        byteBuffer << uint8(profile->SortBy);
        byteBuffer << uint16(profile->FrameWidth);
        byteBuffer << uint8(profile->Unk148);
        byteBuffer.WriteString(profile->ProfileName);
    }

    data.FlushBits();
    data.append(byteBuffer);
    SendPacket(&data);
}
