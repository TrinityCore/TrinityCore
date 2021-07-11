/*
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
 * Copyright (C) 2009-2011 MaNGOSZero <https://github.com/mangos/zero>
 * Copyright (C) 2011-2016 Nostalrius <https://nostalrius.org>
 * Copyright (C) 2016-2017 Elysium Project <https://github.com/elysium-project>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "WorldSession.h"
#include "Battleground.h"
#include "Corpse.h"
#include "DB2Stores.h"
#include "FlightPathMovementGenerator.h"
#include "GameTime.h"
#include "Garrison.h"
#include "InstanceLockMgr.h"
#include "InstancePackets.h"
#include "Log.h"
#include "Map.h"
#include "MapManager.h"
#include "MiscPackets.h"
#include "MovementPackets.h"
#include "Common.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "Opcodes.h"
#include "Log.h"
#include "Player.h"
#include "SpellInfo.h"
#include "MotionMaster.h"
#include "MovementGenerator.h"
#include "MoveSpline.h"
#include "MapManager.h"
#include "Transport.h"
#include "Vehicle.h"
#include "SpellMgr.h"
#include <boost/accumulators/statistics/variance.hpp>
#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics.hpp>
#include <boost/circular_buffer.hpp>
#include "BattleGround.h"
#include "WaypointMovementGenerator.h"
#include "MapPersistentStateMgr.h"
#include "World.h"
#include "Anticheat.h"
#include "packet_builder.h"
#include "MovementPacketSender.h"

void WorldSession::HandleMoveWorldportAckOpcode(WorldPackets::Movement::WorldPortResponse& /*packet*/)

void WorldSession::HandleMoveWorldportAckOpcode(WorldPacket& /*recvData*/)
{
    DEBUG_LOG("WORLD: Recvd MSG_MOVE_WORLDPORT_ACK.");
    HandleMoveWorldportAckOpcode();
}

void WorldSession::HandleMoveWorldportAckOpcode()
{
    Player* player = GetPlayer();
    // ignore unexpected far teleports
    if (!player->IsBeingTeleportedFar())
        return;

    bool seamlessTeleport = player->IsBeingTeleportedSeamlessly();
    player->SetSemaphoreTeleportFar(false);
    // get start teleport coordinates (will used later in fail case)
    WorldLocation old_loc;
    GetPlayer()->GetPosition(old_loc);

    // get the teleport destination
    WorldLocation const& loc = player->GetTeleportDest();
    WorldLocation &loc = GetPlayer()->GetTeleportDest();

    // possible errors in the coordinate validity check (only cheating case possible)
    if (!MapManager::IsValidMapCoord(loc))
    {
        sLog.outError("WorldSession::HandleMoveWorldportAckOpcode: %s was teleported far to a not valid location "
                      "(map:%u, x:%f, y:%f, z:%f) We port him to his homebind instead..",
                      GetPlayer()->GetGuidStr().c_str(), loc.mapId, loc.x, loc.y, loc.z);
        // stop teleportation else we would try this again and again in LogoutPlayer...
        GetPlayer()->SetSemaphoreTeleportFar(false);
        // and teleport the player to a valid place
        GetPlayer()->TeleportToHomebind();
        return;
    }

    // get the destination map entry, not the current one, this will fix homebind and reset greeting
    MapEntry const* mEntry = sMapStore.LookupEntry(loc.GetMapId());
    MapEntry const* mEntry = sMapStorage.LookupEntry<MapEntry>(loc.mapId);

    // reset instance validity, except if going to an instance inside an instance
    if (player->m_InstanceValid == false && !mEntry->IsDungeon())
        player->m_InstanceValid = true;
    Map* map = nullptr;

    Map* oldMap = player->GetMap();
    Map* newMap = GetPlayer()->GetTeleportDestInstanceId() ?
        sMapMgr->FindMap(loc.GetMapId(), *GetPlayer()->GetTeleportDestInstanceId()) :
        sMapMgr->CreateMap(loc.GetMapId(), GetPlayer());
    // prevent crash at attempt landing to not existed battleground instance
    if (mEntry->IsBattleGround())
    {
        if (GetPlayer()->GetBattleGroundId())
            map = sMapMgr.FindMap(loc.mapId, GetPlayer()->GetBattleGroundId());

    MovementInfo::TransportInfo transportInfo = player->m_movementInfo.transport;
    if (TransportBase* transport = player->GetTransport())
        transport->RemovePassenger(player);

    if (player->IsInWorld())
    {
        TC_LOG_ERROR("network", "{} {} is still in world when teleported from map {} ({}) to new map {} ({})", player->GetGUID().ToString(), player->GetName(), oldMap->GetMapName(), oldMap->GetId(), newMap ? newMap->GetMapName() : "Unknown", loc.GetMapId());
        oldMap->RemovePlayerFromMap(player, false);
    }
        if (!map)
        {
            DETAIL_LOG("WorldSession::HandleMoveWorldportAckOpcode: %s was teleported far to nonexisten battleground instance "
                       " (map:%u, x:%f, y:%f, z:%f) Trying to port him to his previous place..",
                       GetPlayer()->GetGuidStr().c_str(), loc.mapId, loc.x, loc.y, loc.z);

    // relocate the player to the teleport destination
    // the CannotEnter checks are done in TeleporTo but conditions may change
    // while the player is in transit, for example the map may get full
    if (!newMap || newMap->CannotEnter(player))
    {
        TC_LOG_ERROR("network", "Map {} ({}) could not be created for player {} ({}), porting player to homebind", loc.GetMapId(), newMap ? newMap->GetMapName() : "Unknown", player->GetGUID().ToString(), player->GetName());
        player->TeleportTo(player->m_homebind);
        return;
    }
            GetPlayer()->SetSemaphoreTeleportFar(false);

            // Teleport to previous place, if cannot be ported back TP to homebind place
            if (!GetPlayer()->TeleportTo(old_loc))
            {
                DETAIL_LOG("WorldSession::HandleMoveWorldportAckOpcode: %s cannot be ported to his previous place, teleporting him to his homebind place...",
                           GetPlayer()->GetGuidStr().c_str());
                GetPlayer()->TeleportToHomebind();
            }
            return;
        }
    }

    float z = loc.GetPositionZ() + player->GetHoverOffset();
    player->Relocate(loc.GetPositionX(), loc.GetPositionY(), z, loc.GetOrientation());
    player->SetFallInformation(0, player->GetPositionZ());
    // reset instance validity, except if going to an instance inside an instance
    if (!GetPlayer()->m_InstanceValid && !mEntry->IsDungeon())
        GetPlayer()->m_InstanceValid = true;

    player->ResetMap();
    player->SetMap(newMap);
    // relocate the player to the teleport destination
    if (!map)
    {
        if (loc.mapId <= 1)
            GetPlayer()->SetLocationInstanceId(sMapMgr.GetContinentInstanceId(loc.mapId, loc.x, loc.y));
        map = sMapMgr.CreateMap(loc.mapId, GetPlayer());
    }

    WorldPackets::Movement::ResumeToken resumeToken;
    resumeToken.SequenceIndex = player->m_movementCounter;
    resumeToken.Reason = seamlessTeleport ? 2 : 1;
    SendPacket(resumeToken.Write());

    if (!seamlessTeleport)
        player->SendInitialPacketsBeforeAddToMap();

    // move player between transport copies on each map
    if (Transport* newTransport = newMap->GetTransport(transportInfo.guid))
    GetPlayer()->SetMap(map);
    if (GenericTransport* t = GetPlayer()->GetTransport()) // Transport position may have changed while loading
        t->UpdatePassengerPosition(GetPlayer());
    else
        GetPlayer()->Relocate(loc.x, loc.y, loc.z, loc.o);

    GetPlayer()->SendInitialPacketsBeforeAddToMap();
    // the CanEnter checks are done in TeleporTo but conditions may change
    // while the player is in transit, for example the map may get full
    if (!GetPlayer()->GetMap()->Add(GetPlayer()))
    {
        player->m_movementInfo.transport = transportInfo;
        newTransport->AddPassenger(player);
    }

    if (!player->GetMap()->AddPlayerToMap(player, !seamlessTeleport))
    {
        TC_LOG_ERROR("network", "WORLD: failed to teleport player {} {} to map {} ({}) because of unknown reason!",
            player->GetName(), player->GetGUID().ToString(), loc.GetMapId(), newMap ? newMap->GetMapName() : "Unknown");
        player->ResetMap();
        player->SetMap(oldMap);
        player->TeleportTo(player->m_homebind);
        GetPlayer()->SetSemaphoreTeleportFar(false);
        // if player wasn't added to map, reset his map pointer!
        GetPlayer()->ResetMap();

        DETAIL_LOG("WorldSession::HandleMoveWorldportAckOpcode: %s was teleported far but couldn't be added to map "
                   " (map:%u, x:%f, y:%f, z:%f) Trying to port him to his previous place..",
                   GetPlayer()->GetGuidStr().c_str(), loc.mapId, loc.x, loc.y, loc.z);

        // Teleport to previous place, if cannot be ported back TP to homebind place
        if (!GetPlayer()->TeleportTo(old_loc))
        {
            DETAIL_LOG("WorldSession::HandleMoveWorldportAckOpcode: %s cannot be ported to his previous place, teleporting him to his homebind place...",
                       GetPlayer()->GetGuidStr().c_str());
            GetPlayer()->TeleportToHomebind();
        }
        return;
    }
    GetPlayer()->SetSemaphoreTeleportFar(false);

    // battleground state prepare (in case join to BG), at relogin/tele player not invited
    // only add to bg group and object, if the player was invited (else he entered through command)
    if (player->InBattleground())
    if (_player->InBattleGround())
    {
        // cleanup seting if outdated
        if (!mEntry->IsBattleGround())
        {
            // We're not in BG
            player->SetBattlegroundId(0, BATTLEGROUND_TYPE_NONE);
            _player->SetBattleGroundId(0, BATTLEGROUND_TYPE_NONE);
            // reset destination bg team
            player->SetBGTeam(0);
            _player->SetBGTeam(TEAM_NONE);
        }
        // join to bg case
        else if (Battleground* bg = player->GetBattleground())
        else if (BattleGround *bg = _player->GetBattleGround())
        {
            if (player->IsInvitedForBattlegroundInstance(player->GetBattlegroundId()))
                bg->AddPlayer(player);
            if (_player->IsInvitedForBattleGroundInstance(_player->GetBattleGroundId()))
                bg->AddPlayer(_player);
        }
    }

    if (!seamlessTeleport)
        player->SendInitialPacketsAfterAddToMap();
    else
    {
        player->UpdateVisibilityForPlayer();
        if (Garrison* garrison = player->GetGarrison())
            garrison->SendRemoteInfo();
    }
    GetPlayer()->SendInitialPacketsAfterAddToMap();

    // flight fast teleport case
    if (player->IsInFlight())
    {
        if (!player->InBattleground())
        // the movement could be expiring so check for destination (ritual of summoning / gm teleport)
        if (!_player->InBattleGround() && !_player->m_taxi.empty())
        {
            if (!seamlessTeleport)
            {
                // short preparations to continue flight
                MovementGenerator* movementGenerator = player->GetMotionMaster()->GetCurrentMovementGenerator();
                movementGenerator->Initialize(player);
            }
            // short preparations to continue flight
            FlightPathMovementGenerator* flight = (FlightPathMovementGenerator*)(GetPlayer()->GetMotionMaster()->top());
            flight->Reset(*GetPlayer());
            return;
        }

        // battleground state prepare, stop flight
        player->FinishTaxiFlight();
        GetPlayer()->GetMotionMaster()->MovementExpired();
        GetPlayer()->m_taxi.ClearTaxiDestinations();
    }

    if (!player->IsAlive() && player->GetTeleportOptions() & TELE_REVIVE_AT_TELEPORT)
        player->ResurrectPlayer(0.5f);

    // resurrect character at enter into instance where his corpse exist after add to map
    if (mEntry->IsDungeon() && !player->IsAlive())
    {
        if (player->GetCorpseLocation().GetMapId() == mEntry->ID)
        {
            player->ResurrectPlayer(0.5f);
            player->SpawnCorpseBones();
        }
    }

    if (mEntry->IsDungeon())
    {
        // check if this instance has a reset time and send it to player if so
        MapDb2Entries entries{ mEntry->ID, newMap->GetDifficultyID() };
        if (entries.MapDifficulty->HasResetSchedule())
        {
            WorldPackets::Instance::RaidInstanceMessage raidInstanceMessage;
            raidInstanceMessage.Type = RAID_INSTANCE_WELCOME;
            raidInstanceMessage.MapID = mEntry->ID;
            raidInstanceMessage.DifficultyID = newMap->GetDifficultyID();
            if (InstanceLock const* playerLock = sInstanceLockMgr.FindActiveInstanceLock(GetPlayer()->GetGUID(), entries))
            {
                raidInstanceMessage.Locked = !playerLock->IsExpired();
                raidInstanceMessage.Extended = playerLock->IsExtended();
            }
            else
            {
                raidInstanceMessage.Locked = false;
                raidInstanceMessage.Extended = false;
            }
            SendPacket(raidInstanceMessage.Write());
        }
    if (mEntry->IsRaid())
    {
        if (time_t timeReset = sMapPersistentStateMgr.GetScheduler().GetResetTimeFor(mEntry->id))
        {
            uint32 timeleft = uint32(timeReset - time(nullptr));
            GetPlayer()->SendInstanceResetWarning(mEntry->id, timeleft);
        }
    }

        // check if instance is valid
        if (!player->CheckInstanceValidity(false))
            player->m_InstanceValid = false;
    }

    // update zone immediately, otherwise leave channel will cause crash in mtmap
    uint32 newzone, newarea;
    player->GetZoneAndAreaId(newzone, newarea);
    player->UpdateZone(newzone, newarea);

    // mount allow check
    if (!mEntry->IsMountAllowed())
        _player->RemoveSpellsCausingAura(SPELL_AURA_MOUNTED);

    // honorless target
    if (player->pvpInfo.IsHostile)
        player->CastSpell(player, 2479, true);
    if (!GetPlayer()->pvpInfo.inPvPEnforcedArea)
        GetPlayer()->RemoveDelayedOperation(DELAYED_CAST_HONORLESS_TARGET);

    // resummon pet
    player->ResummonPetTemporaryUnSummonedIfAny();

    //lets process all delayed operations on successful teleport
    player->ProcessDelayedOperations();
}
    GetPlayer()->ProcessDelayedOperations();

    // Let the client know its new position by sending a heartbeat!
    // The Windows client figures this out by itself, but the MacOS one does
    // not.
    //
    // On a successful port, the camera of the MacOS client is facing south and
    // ignores any movement from the transport object. Triggering
    // `SMSG_STANDSTATE_UPDATE' with its current state resets the camera
    // (implemented in `WorldSession::HandleZoneUpdateOpcode').
    if (_clientOS == CLIENT_OS_MAC && GetPlayer()->m_movementInfo.HasMovementFlag(MOVEFLAG_ONTRANSPORT))
    {
        GetPlayer()->SendHeartBeat(true);
    }
}

void WorldSession::HandleMoveTeleportAckOpcode(WorldPacket& recvData)
{
    DEBUG_LOG("WORLD: Recvd MSG_MOVE_TELEPORT_ACK");

    ObjectGuid guid;
    recvData >> guid;
    uint32 movementCounter = 0;
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_9_4
    recvData >> movementCounter;
#endif
    uint32 time = 0;
    recvData >> time;
    DEBUG_LOG("Guid: %s", guid.GetString().c_str());
    DEBUG_LOG("Counter %u, time %u", movementCounter, time / IN_MILLISECONDS);

    Unit* pMover = _player->GetMover();
    Player* pPlayerMover = pMover->ToPlayer();

    if (!pPlayerMover || !pPlayerMover->IsBeingTeleportedNear())
        return;

    if (guid != pPlayerMover->GetObjectGuid())
        return;

    if (!pMover->FindPendingMovementTeleportChange(movementCounter))
    {
        sLog.outInfo("WorldSession::HandleMoveTeleportAckOpcode: Player %s from account id %u sent MSG_MOVE_TELEPORT_ACK with counter %u, but no pending teleport found (current counter is %u)",
            _player->GetName(), _player->GetSession()->GetAccountId(), movementCounter, pMover->GetMovementCounter());
    }

    pPlayerMover->ExecuteTeleportNear();
}

void Player::ExecuteTeleportNear()
{
    if (!IsBeingTeleportedNear())
    {
        sLog.outInfo("Player::ExecuteNearTeleport called without near teleport scheduled!");
        return;
    }

void WorldSession::HandleMoveTeleportAck(WorldPackets::Movement::MoveTeleportAck& packet)
{
    TC_LOG_DEBUG("network", "CMSG_MOVE_TELEPORT_ACK: Guid: {}, Sequence: {}, Time: {}", packet.MoverGUID.ToString(), packet.AckIndex, packet.MoveTime);
    SetSemaphoreTeleportNear(false);

    WorldLocation const& dest = GetTeleportDest();
    TeleportPositionRelocation(dest);
    MovementPacketSender::SendTeleportToObservers(this);

    // resummon pet, if the destination is in another continent instance, let Player::SwitchInstance do it
    // because the client will request the name for the old pet guid and receive no answer
    // result would be a pet named "unknown"
    if (GetTemporaryUnsummonedPetNumber())
    {
        if (sWorld.getConfig(CONFIG_BOOL_CONTINENTS_INSTANCIATE) && GetMap()->IsContinent())
        {
            bool transition = false;
            if (sMapMgr.GetContinentInstanceId(GetMap()->GetId(), dest.x, dest.y, &transition) == GetInstanceId())
                ResummonPetTemporaryUnSummonedIfAny();
        }
        else
            ResummonPetTemporaryUnSummonedIfAny();
    }

    Player* plMover = _player->GetUnitBeingMoved()->ToPlayer();
    // lets process all delayed operations on successful teleport
    ProcessDelayedOperations();
}

void WorldSession::HandleMovementOpcodes(WorldPacket& recvData)
{
    uint32 const opcode = recvData.GetOpcode();
    DEBUG_LOG("WORLD: Recvd %s (%u, 0x%X) opcode", LookupOpcodeName(opcode), opcode, opcode);

    // Do not accept packets sent before this time.
    if (recvData.GetPacketTime() <= m_moveRejectTime)
        return;

    Unit* pMover = _player->GetMover();

    if (pMover->GetObjectGuid() != _clientMoverGuid)
        return;
        
    Player* pPlayerMover = pMover->ToPlayer();

    // ignore, waiting processing in WorldSession::HandleMoveWorldportAckOpcode and WorldSession::HandleMoveTeleportAck
    if (pPlayerMover && pPlayerMover->IsBeingTeleported())
    {
        recvData.rpos(recvData.wpos());                   // prevent warnings spam
        return;
    }

    /* extract packet */
    MovementInfo movementInfo = pPlayerMover ? pPlayerMover->m_movementInfo : MovementInfo();
    recvData >> movementInfo;
    movementInfo.UpdateTime(recvData.GetPacketTime());
    /*----------------*/

    if (!VerifyMovementInfo(movementInfo))
        return;

    if (pPlayerMover)
    {
        if (!_player->GetCheatData()->HandleFlagTests(pPlayerMover, movementInfo, opcode) || 
            !_player->GetCheatData()->HandlePositionTests(pPlayerMover, movementInfo, opcode))
        {
            m_moveRejectTime = WorldTimer::getMSTime();
            return;
        }
    }

    // This is required for proper movement extrapolation
    if (opcode == MSG_MOVE_JUMP)
        pMover->SetJumpInitialSpeed(7.95797334f);
    else if (opcode == MSG_MOVE_FALL_LAND)
        pMover->SetJumpInitialSpeed(-9.645f);

    if (movementInfo.HasMovementFlag(MOVEFLAG_MASK_MOVING))
    {
        // Interrupt spell cast at move
        pMover->InterruptSpellsWithInterruptFlags(SPELL_INTERRUPT_FLAG_MOVEMENT);
        pMover->InterruptSpellsWithChannelFlags(CHANNEL_FLAG_MOVING_CANCELS);
        // Fix bug after 1.11 where client doesn't send stand state update while casting.
        // Test case: Begin eating or drinking, then start casting Hearthstone and run.
        pMover->SetStandState(UNIT_STAND_STATE_STAND);
    }

    HandleMoverRelocation(pMover, movementInfo);

    // fall damage generation (ignore in flight case that can be triggered also at lags in moment teleportation to another map).
    if (opcode == MSG_MOVE_FALL_LAND && pPlayerMover && !pPlayerMover->IsTaxiFlying())
        pPlayerMover->HandleFall(movementInfo);

    // TODO: remove it
    // reset knockback state when fall to ground or water
    if (pPlayerMover)
    {
        if ((opcode == MSG_MOVE_FALL_LAND || opcode == MSG_MOVE_START_SWIM) && pPlayerMover->IsLaunched())
        {
            pPlayerMover->SetLaunched(false);
            pPlayerMover->SetXYSpeed(0.0f);
        }

void WorldSession::HandleMovementOpcode(OpcodeClient opcode, MovementInfo& movementInfo)
{
    Unit* mover = _player->GetUnitBeingMoved();
        pPlayerMover->UpdateFallInformationIfNeed(movementInfo, opcode);
    }

    WorldPacket data(opcode, recvData.size());

#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
    data << _clientMoverGuid.WriteAsPacked();
#else
    data << _clientMoverGuid.GetRawValue();
#endif
    movementInfo.Write(data);

    TC_LOG_TRACE("opcodes.movement", "HandleMovementOpcode Name {}: opcode {} {} Flags {} Flags2 {} Pos {}",
        mover->GetName(), opcode, GetOpcodeNameForLogging(opcode),
        movementInfo.flags, movementInfo.flags2, movementInfo.pos.ToString());
    pMover->SendMovementMessageToSet(std::move(data), true, _player);

    // Fix movement issue on older clients where if the player jumps while running,
    // and then lets go of the key while in the air, he appears to continue moving
    // forward on other people's screen. Once he moves for real, they will see him
    // teleport back to where he was standing after he jumped.
#if SUPPORTED_CLIENT_BUILD == CLIENT_BUILD_1_9_4
    if (opcode == MSG_MOVE_FALL_LAND)
    {
        uint16 opcode2 = 0;
        if (!movementInfo.HasMovementFlag(MOVEFLAG_MASK_MOVING))
            opcode2 = MSG_MOVE_STOP;
        else if (movementInfo.HasMovementFlag(MOVEFLAG_BACKWARD))
            opcode2 = MSG_MOVE_START_BACKWARD;
        else if (movementInfo.HasMovementFlag(MOVEFLAG_FORWARD))
            opcode2 = MSG_MOVE_START_FORWARD;
        else if (movementInfo.HasMovementFlag(MOVEFLAG_STRAFE_LEFT))
            opcode2 = MSG_MOVE_START_STRAFE_LEFT;
        else if (movementInfo.HasMovementFlag(MOVEFLAG_STRAFE_RIGHT))
            opcode2 = MSG_MOVE_START_STRAFE_RIGHT;

        if (opcode2)
        {
            WorldPacket data(opcode2, recvData.size());
            data << _clientMoverGuid.WriteAsPacked();             // write guid
            movementInfo.Write(data);                             // write data

            pMover->SendMovementMessageToSet(std::move(data), true, _player);
        }
    }
#endif
}

/*
handles those packets:
CMSG_FORCE_RUN_SPEED_CHANGE_ACK
CMSG_FORCE_RUN_BACK_SPEED_CHANGE_ACK
CMSG_FORCE_SWIM_SPEED_CHANGE_ACK
CMSG_FORCE_WALK_SPEED_CHANGE_ACK
CMSG_FORCE_SWIM_BACK_SPEED_CHANGE_ACK
CMSG_FORCE_TURN_RATE_CHANGE_ACK
*/
void WorldSession::HandleForceSpeedChangeAckOpcodes(WorldPacket& recvData)
{
    uint32 const opcode = recvData.GetOpcode();
    DEBUG_LOG("WORLD: Recvd %s (%u, 0x%X) opcode", LookupOpcodeName(opcode), opcode, opcode);

    /* extract packet */
    ObjectGuid guid;
    recvData >> guid;
    uint32 movementCounter = 0;
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_9_4
    recvData >> movementCounter;
#endif
    MovementInfo movementInfo;
    recvData >> movementInfo;
    float  speedReceived;
    recvData >> speedReceived;
    movementInfo.UpdateTime(recvData.GetPacketTime());
    /*----------------*/

    // now can skip not our packet
    if (guid != _clientMoverGuid && guid != _player->GetObjectGuid() && guid != _player->GetMover()->GetObjectGuid())
        return;

    if (!movementInfo.pos.IsPositionValid())
        return;

    if (!mover->movespline->Finalized())
        return;
    UnitMoveType move_type;
    switch (opcode)
    {
        case CMSG_FORCE_WALK_SPEED_CHANGE_ACK:
            move_type = MOVE_WALK;
            break;
        case CMSG_FORCE_RUN_SPEED_CHANGE_ACK:
            move_type = MOVE_RUN;
            break;
        case CMSG_FORCE_RUN_BACK_SPEED_CHANGE_ACK:
            move_type = MOVE_RUN_BACK;
            break;
        case CMSG_FORCE_SWIM_SPEED_CHANGE_ACK:
            move_type = MOVE_SWIM;
            break;
        case CMSG_FORCE_SWIM_BACK_SPEED_CHANGE_ACK:
            move_type = MOVE_SWIM_BACK;
            break;
        case CMSG_FORCE_TURN_RATE_CHANGE_ACK:
            move_type = MOVE_TURN_RATE;
            break;
        default:
            sLog.outError("WorldSession::HandleForceSpeedChangeAck: Unknown move type opcode: %u", opcode);
            return;
    }

    Unit* pMover = _player->GetMap()->GetUnit(guid);

    if (!pMover)
        return;

        // transports size limited
        // (also received at zeppelin leave by some reason with t_* as absolute in continent coordinates, can be safely skipped)
        if (fabs(movementInfo.transport.pos.GetPositionX()) > 75.0f || fabs(movementInfo.transport.pos.GetPositionY()) > 75.0f || fabs(movementInfo.transport.pos.GetPositionZ()) > 75.0f)
            return;
    // verify that indeed the client is replying with the changes that were send to him
    if (!pMover->HasPendingMovementChange())
    {
        sLog.outInfo("WorldSession::HandleForceSpeedChangeAck: Player %s from account id %u sent opcode %u with counter %u, but no movement change ack was expected from this player (current counter is %u)",
            _player->GetName(), _player->GetSession()->GetAccountId(), opcode, movementCounter, pMover->GetMovementCounter());
        if (movementCounter == 0 || movementCounter > pMover->GetMovementCounter())
            _player->GetCheatData()->OnWrongAckData();
        return;
    }

        if (!Trinity::IsValidMapCoord(movementInfo.pos.GetPositionX() + movementInfo.transport.pos.GetPositionX(), movementInfo.pos.GetPositionY() + movementInfo.transport.pos.GetPositionY(),
            movementInfo.pos.GetPositionZ() + movementInfo.transport.pos.GetPositionZ(), movementInfo.pos.GetOrientation() + movementInfo.transport.pos.GetOrientation()))
            return;

        // if we boarded a transport, add us to it
        if (plrMover)
        {
            if (!plrMover->GetTransport())
            {
                if (GameObject* go = plrMover->GetMap()->GetGameObject(movementInfo.transport.guid))
                    if (TransportBase* transport = go->ToTransportBase())
                        transport->AddPassenger(plrMover);
    if (!pMover->FindPendingMovementSpeedChange(speedReceived, movementCounter, move_type))
    {
        sLog.outInfo("WorldSession::HandleForceSpeedChangeAck: Player %s from account id %u sent opcode %u with counter %u, but received data does not match pending change (current counter is %u)",
            _player->GetName(), _player->GetSession()->GetAccountId(), opcode, movementCounter, pMover->GetMovementCounter());
        if (movementCounter == 0 || movementCounter > pMover->GetMovementCounter())
            _player->GetCheatData()->OnWrongAckData();
        return;
    }
    
    // Use fake loop here to handle movement position checks separately from change ACK.
    do
    {
        // Do not accept packets sent before this time.
        if (recvData.GetPacketTime() <= m_moveRejectTime)
            break;

        if (!VerifyMovementInfo(movementInfo))
            break;

        Player* pPlayerMover = pMover->ToPlayer();

        if (pPlayerMover)
        {
            if (!_player->GetCheatData()->HandleFlagTests(pPlayerMover, movementInfo, opcode) || 
                !_player->GetCheatData()->HandlePositionTests(pPlayerMover, movementInfo, opcode))
            {
                m_moveRejectTime = WorldTimer::getMSTime();
                break;
            }
            else if (plrMover->GetTransport()->GetTransportGUID() != movementInfo.transport.guid)
            {
                plrMover->GetTransport()->RemovePassenger(plrMover);
                if (GameObject* go = plrMover->GetMap()->GetGameObject(movementInfo.transport.guid))
                {
                    if (TransportBase* transport = go->ToTransportBase())
                        transport->AddPassenger(plrMover);
                    else
                        movementInfo.ResetTransport();
                }
                else
                    movementInfo.ResetTransport();
            }
        }
        }
        
        if ((pMover == _player->GetMover()) &&
            (!pPlayerMover || !pPlayerMover->IsBeingTeleported()))
        {
            // Update position if it has changed.
            HandleMoverRelocation(pMover, movementInfo);
            if (pPlayerMover)
                pPlayerMover->UpdateFallInformationIfNeed(movementInfo, opcode);
        }
        else
        {
            // Can only change flags and speed for not current active mover.
            pMover->m_movementInfo.moveFlags = movementInfo.moveFlags;
            pMover->m_movementInfo.CorrectData(pMover);
        }
    } while (false);

    // the client data has been verified, let's do the actual change now
    float newSpeedRate = speedReceived / baseMoveSpeed[move_type];
    pMover->SetSpeedRateReal(move_type, newSpeedRate);
    MovementPacketSender::SendSpeedChangeToObservers(pMover, move_type, speedReceived);
}

        if (!mover->GetTransport() && !mover->GetVehicle())
            movementInfo.transport.Reset();
    }
    else if (plrMover && plrMover->GetTransport())                // if we were on a transport, leave
        plrMover->GetTransport()->RemovePassenger(plrMover);
/*
handles those packets:
CMSG_MOVE_WATER_WALK_ACK
CMSG_MOVE_HOVER_ACK
CMSG_MOVE_FEATHER_FALL_ACK
*/
void WorldSession::HandleMovementFlagChangeToggleAck(WorldPacket& recvData)
{
    uint32 const opcode = recvData.GetOpcode();
    DEBUG_LOG("WORLD: Recvd %s (%u, 0x%X) opcode", LookupOpcodeName(opcode), opcode, opcode);

    /* extract packet */
    ObjectGuid guid;
    recvData >> guid;
    uint32 movementCounter = 0;
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_9_4
    recvData >> movementCounter;
#endif
    MovementInfo movementInfo;
    recvData >> movementInfo;
    movementInfo.UpdateTime(recvData.GetPacketTime());
    uint32 applyInt;
    recvData >> applyInt;
    bool applyReceived = applyInt != 0u;
    /*----------------*/

    // make sure this client is allowed to control the unit which guid is provided
    if (guid != _clientMoverGuid && guid != _player->GetObjectGuid() && guid != _player->GetMover()->GetObjectGuid())
        return;

    Unit* pMover = _player->GetMap()->GetUnit(guid);

    if (!pMover)
        return;

    // verify that indeed the client is replying with the changes that were send to him
    if (!pMover->HasPendingMovementChange())
    {
        sLog.outInfo("WorldSession::HandleMovementFlagChangeToggleAck: Player %s from account id %u sent opcode %u with counter %u, but no movement change ack was expected from this player (current counter is %u)",
            _player->GetName(), _player->GetSession()->GetAccountId(), opcode, movementCounter, pMover->GetMovementCounter());
        if (movementCounter == 0 || movementCounter > pMover->GetMovementCounter())
            _player->GetCheatData()->OnWrongAckData();
        return;
    }

    MovementFlags mFlag = MOVEFLAG_NONE;
    MovementChangeType changeTypeReceived;

    switch (opcode)
    {
        case CMSG_MOVE_WATER_WALK_ACK:      changeTypeReceived = WATER_WALK; mFlag = MOVEFLAG_WATERWALKING; break;
        case CMSG_MOVE_HOVER_ACK:           changeTypeReceived = SET_HOVER; mFlag = MOVEFLAG_HOVER; break;
        case CMSG_MOVE_FEATHER_FALL_ACK:    changeTypeReceived = FEATHER_FALL; mFlag = MOVEFLAG_SAFE_FALL; break;
        default:
            sLog.outInfo("WorldSession::HandleMovementFlagChangeToggleAck: Unknown move type opcode: %u", opcode);
            return;
    }

    if (!pMover->FindPendingMovementFlagChange(movementCounter, applyReceived, changeTypeReceived))
    {
        sLog.outInfo("WorldSession::HandleMovementFlagChangeToggleAck: Player %s from account id %u sent opcode %u with counter %u, but received data does not match pending change (current counter is %u)",
            _player->GetName(), _player->GetSession()->GetAccountId(), opcode, movementCounter, pMover->GetMovementCounter());
        if (movementCounter == 0 || movementCounter > pMover->GetMovementCounter())
            _player->GetCheatData()->OnWrongAckData();
        return;
    }

    if (opcode == CMSG_MOVE_FEATHER_FALL_ACK)
        pMover->SetJumpInitialSpeed(std::max(pMover->GetJumpInitialSpeed(), 7.0f));

    /* process position-change */
    movementInfo.guid = mover->GetGUID();
    movementInfo.time = AdjustClientMovementTime(movementInfo.time);
    mover->m_movementInfo = movementInfo;
    // Use fake loop here to handle movement position checks separately from change ACK.
    do
    {
        // Do not accept packets sent before this time.
        if (recvData.GetPacketTime() <= m_moveRejectTime)
            break;

        if (!VerifyMovementInfo(movementInfo))
            break;

        Player* pPlayerMover = pMover->ToPlayer();

        if (pPlayerMover)
        {
            if (!_player->GetCheatData()->HandleFlagTests(pPlayerMover, movementInfo, opcode) || 
                !_player->GetCheatData()->HandlePositionTests(pPlayerMover, movementInfo, opcode))
            {
                m_moveRejectTime = WorldTimer::getMSTime();
                break;
            }
        }

        if ((pMover == _player->GetMover()) &&
            (!pPlayerMover || !pPlayerMover->IsBeingTeleported()))
        {
            // Update position if it has changed.
            HandleMoverRelocation(pMover, movementInfo);
            if (pPlayerMover)
                pPlayerMover->UpdateFallInformationIfNeed(movementInfo, opcode);
        }
        else
        {
            // Can only change flags and speed for not current active mover.
            pMover->m_movementInfo.moveFlags = movementInfo.moveFlags;
            pMover->m_movementInfo.CorrectData(pMover);
        }
    } while (false);

    switch (changeTypeReceived)
    {
        case WATER_WALK:            pMover->SetWaterWalkingReal(applyReceived); break;
        case SET_HOVER:             pMover->SetHoverReal(applyReceived); break;
        case FEATHER_FALL:          pMover->SetFeatherFallReal(applyReceived); break;
        default:
            sLog.outInfo("WorldSession::HandleMovementFlagChangeToggleAck: Unknown move type opcode: %u", opcode);
            return;
    }

    if (mFlag != MOVEFLAG_NONE)
        MovementPacketSender::SendMovementFlagChangeToObservers(pMover, mFlag, applyReceived);
}

/*
handles those packets:
CMSG_FORCE_MOVE_ROOT_ACK
CMSG_FORCE_MOVE_UNROOT_ACK
*/
void WorldSession::HandleMoveRootAck(WorldPacket& recvData)
{
    uint32 const opcode = recvData.GetOpcode();
    DEBUG_LOG("WORLD: Recvd %s (%u, 0x%X) opcode", LookupOpcodeName(opcode), opcode, opcode);
    
    /* extract packet */
    ObjectGuid guid;
    recvData >> guid;
    uint32 movementCounter = 0;
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_9_4
    recvData >> movementCounter;
#endif
    MovementInfo movementInfo;
    recvData >> movementInfo;
    movementInfo.UpdateTime(recvData.GetPacketTime());
    /*----------------*/

    // make sure this client is allowed to control the unit which guid is provided
    if (guid != _clientMoverGuid && guid != _player->GetObjectGuid() && guid != _player->GetMover()->GetObjectGuid())
        return;

    Unit* pMover = _player->GetMap()->GetUnit(guid);

    if (!pMover)
        return;

    // verify that indeed the client is replying with the changes that were send to him
    if (!pMover->HasPendingMovementChange())
    {
        sLog.outInfo("WorldSession::HandleMoveRootAck: Player %s from account id %u sent opcode %u with counter %u, but no movement change ack was expected from this player (current counter is %u)",
            _player->GetName(), _player->GetSession()->GetAccountId(), opcode, movementCounter, pMover->GetMovementCounter());
        if (movementCounter == 0 || movementCounter > pMover->GetMovementCounter())
            _player->GetCheatData()->OnWrongAckData();
        return;
    }

    bool applyReceived = (opcode == CMSG_FORCE_MOVE_ROOT_ACK);

    if (!pMover->FindPendingMovementRootChange(movementCounter, applyReceived))
    {
        sLog.outInfo("WorldSession::HandleMoveRootAck: Player %s from account id %u sent opcode %u with counter %u, but received data does not match pending change (current counter is %u)",
            _player->GetName(), _player->GetSession()->GetAccountId(), opcode, movementCounter, pMover->GetMovementCounter());
        if (movementCounter == 0 || movementCounter > pMover->GetMovementCounter())
            _player->GetCheatData()->OnWrongAckData();
        return;
    }

    // Use fake loop here to handle movement position checks separately from change ACK.
    do
    {
        // Do not accept packets sent before this time.
        if (recvData.GetPacketTime() <= m_moveRejectTime)
            break;

        if (!VerifyMovementInfo(movementInfo))
            break;

        Player* pPlayerMover = pMover->ToPlayer();

        if (movementInfo.pos.GetPositionZ() < plrMover->GetMap()->GetMinHeight(plrMover->GetPhaseShift(), movementInfo.pos.GetPositionX(), movementInfo.pos.GetPositionY()))
        {
            if (!(plrMover->GetBattleground() && plrMover->GetBattleground()->HandlePlayerUnderMap(_player)))
            {
                // NOTE: this is actually called many times while falling
                // even after the player has been teleported away
                /// @todo discard movement packets after the player is rooted
                if (plrMover->IsAlive())
                {
                    TC_LOG_DEBUG("entities.player.falldamage", "FALLDAMAGE Below map. Map min height: {} , Player debug info:\n{}", plrMover->GetMap()->GetMinHeight(plrMover->GetPhaseShift(), movementInfo.pos.GetPositionX(), movementInfo.pos.GetPositionY()), plrMover->GetDebugInfo());
                    plrMover->SetPlayerFlag(PLAYER_FLAGS_IS_OUT_OF_BOUNDS);
                    plrMover->EnvironmentalDamage(DAMAGE_FALL_TO_VOID, GetPlayer()->GetMaxHealth());
                    // player can be alive if GM/etc
                    // change the death state to CORPSE to prevent the death timer from
                    // starting in the next player update
                    if (plrMover->IsAlive())
                        plrMover->KillPlayer();
                }
        if (pPlayerMover)
        {
            if (!_player->GetCheatData()->HandleFlagTests(pPlayerMover, movementInfo, opcode) ||
                !_player->GetCheatData()->HandlePositionTests(pPlayerMover, movementInfo, opcode))
            {
                m_moveRejectTime = WorldTimer::getMSTime();
                break;
            }
        }

        if ((pMover == _player->GetMover()) &&
            (!pPlayerMover || !pPlayerMover->IsBeingTeleported()))
        {
            plrMover->RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags2::Jump);
            Unit::ProcSkillsAndAuras(plrMover, nullptr, PROC_FLAG_JUMP, PROC_FLAG_NONE, PROC_SPELL_TYPE_MASK_ALL, PROC_SPELL_PHASE_NONE, PROC_HIT_NONE, nullptr, nullptr, nullptr);
            // Update position if it has changed.
            HandleMoverRelocation(pMover, movementInfo);
            if (pPlayerMover)
                pPlayerMover->UpdateFallInformationIfNeed(movementInfo, opcode);
        }
        else
        {
            // Can only change flags and speed for not current active mover.
            pMover->m_movementInfo.moveFlags = movementInfo.moveFlags;
            pMover->m_movementInfo.CorrectData(pMover);
        }
    } while (false);

    pMover->SetRootedReal(applyReceived);
    MovementPacketSender::SendMovementFlagChangeToObservers(pMover, MOVEFLAG_ROOT, applyReceived);
}

void WorldSession::HandleMoveKnockBackAck(WorldPacket& recvData)
{
    DEBUG_LOG("WORLD: Recvd CMSG_MOVE_KNOCK_BACK_ACK");

    /* extract packet */
    ObjectGuid guid;
    recvData >> guid;
    uint32 movementCounter = 0;
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_9_4
    recvData >> movementCounter;
#endif
    MovementInfo movementInfo;
    recvData >> movementInfo;
    movementInfo.UpdateTime(recvData.GetPacketTime());
    /*----------------*/

    if (guid != _clientMoverGuid && guid != _player->GetObjectGuid() && guid != _player->GetMover()->GetObjectGuid())
        return;

    Unit* pMover = _player->GetMap()->GetUnit(guid);

    if (!pMover)
        return;

    if (!VerifyMovementInfo(movementInfo))
        return;

    // verify that indeed the client is replying with the changes that were send to him
    if (!pMover->HasPendingMovementChange())
    {
        sLog.outInfo("WorldSession::HandleMoveKnockBackAck: Player %s from account id %u sent opcode %u with counter %u, but no movement change ack was expected from this player (current counter is %u)",
            _player->GetName(), _player->GetSession()->GetAccountId(), recvData.GetOpcode(), movementCounter, pMover->GetMovementCounter());
        if (movementCounter == 0 || movementCounter > pMover->GetMovementCounter())
            _player->GetCheatData()->OnWrongAckData();
        return;
    }

    if (!pMover->FindPendingMovementKnockbackChange(movementInfo, movementCounter))
    {
        sLog.outInfo("WorldSession::HandleMoveKnockBackAck: Player %s from account id %u sent opcode %u with counter %u, but received data does not match pending change (current counter is %u)",
            _player->GetName(), _player->GetSession()->GetAccountId(), recvData.GetOpcode(), movementCounter, pMover->GetMovementCounter());
        if (movementCounter == 0 || movementCounter > pMover->GetMovementCounter())
            _player->GetCheatData()->OnWrongAckData();
        return;
    }

    // ignore, waiting processing in WorldSession::HandleMoveWorldportAckOpcode and WorldSession::HandleMoveTeleportAck
    if (pMover->IsPlayer() && static_cast<Player*>(pMover)->IsBeingTeleported())
        return;

        default:
            TC_LOG_ERROR("network", "WorldSession::HandleForceSpeedChangeAck: Unknown move type opcode: {}", opcode);
    if (Player* pPlayerMover = pMover->ToPlayer())
    {
        if (!_player->GetCheatData()->HandleFlagTests(pPlayerMover, movementInfo, recvData.GetOpcode()) ||
            !_player->GetCheatData()->HandlePositionTests(pPlayerMover, movementInfo, recvData.GetOpcode()))
        {
            m_moveRejectTime = WorldTimer::getMSTime();
            return;
        }
    }

    HandleMoverRelocation(pMover, movementInfo);

    MovementPacketSender::SendKnockBackToObservers(pMover, movementInfo.jump.cosAngle, movementInfo.jump.sinAngle, movementInfo.jump.xyspeed, movementInfo.jump.velocity);
}

void WorldSession::HandleMoveSplineDoneOpcode(WorldPacket& recvData)
{
    DEBUG_LOG("WORLD: Recvd CMSG_MOVE_SPLINE_DONE");

    MovementInfo movementInfo;                              // used only for proper packet read

    recvData >> movementInfo;
    recvData >> Unused<uint32>();                          // unk
    recvData >> Unused<uint32>();                          // unk2

    // Forward packet to near players
    recvData.SetOpcode(MSG_MOVE_STOP);
    recvData.rpos(0);
    HandleMovementOpcodes(recvData);
}

void WorldSession::HandleSetActiveMoverOpcode(WorldPacket& recvData)
{
    DEBUG_LOG("WORLD: Recvd CMSG_SET_ACTIVE_MOVER");

    ObjectGuid guid;
    recvData >> guid;

    ObjectGuid serverMoverGuid = _player->GetMover()->GetObjectGuid();

    // Before 1.10, client sends 0 as guid if it has no control.
#if SUPPORTED_CLIENT_BUILD <= CLIENT_BUILD_1_9_4
    if ((serverMoverGuid == _player->GetObjectGuid()) && !_player->HasSelfMovementControl())
        serverMoverGuid = ObjectGuid();
#endif

    if (serverMoverGuid != guid)
    {
        sLog.outError("HandleSetActiveMoverOpcode: incorrect mover guid: mover is %s and should be %s",
                      _player->GetMover()->GetGuidStr().c_str(), guid.GetString().c_str());
        _clientMoverGuid = _player->GetMover()->GetObjectGuid();
        return;
    }

    if (!_player->GetTransport() && std::fabs(_player->GetSpeed(move_type) - packet.Speed) > 0.01f)
    {
        if (_player->GetSpeed(move_type) > packet.Speed)         // must be greater - just correct
        {
            TC_LOG_ERROR("network", "{}SpeedChange player {} is NOT correct (must be {} instead {}), force set to correct value",
                move_type_name[move_type], _player->GetName(), _player->GetSpeed(move_type), packet.Speed);
            _player->SetSpeedRate(move_type, _player->GetSpeedRate(move_type));
        }
        else                                                // must be lesser - cheating
    if (!guid.IsEmpty())
    {
        Unit* pMover = _player->GetMap()->GetUnit(guid);

        if (pMover && pMover->IsCreature() && pMover->IsRooted())
            MovementPacketSender::AddMovementFlagChangeToController(pMover, MOVEFLAG_ROOT, true);
    }

    // mover swap after Eyes of the Beast, PetAI::UpdateAI handle the pet's return
    // Check if we actually have a pet before looking up
    if (_player->GetPetGuid() && _player->GetPetGuid() == _clientMoverGuid)
    {
        if (Pet* pet = _player->GetPet())
        {
            TC_LOG_DEBUG("misc", "Player {} from account id {} kicked for incorrect speed (must be {} instead {})",
                _player->GetName(), _player->GetSession()->GetAccountId(), _player->GetSpeed(move_type), packet.Speed);
            _player->GetSession()->KickPlayer("WorldSession::HandleForceSpeedChangeAck Incorrect speed");
            pet->ClearUnitState(UNIT_STAT_POSSESSED);
            pet->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_POSSESSED);
            // out of range pet dismissed
            if (!pet->IsWithinDistInMap(_player, pet->GetMap()->GetGridActivationDistance()))
                _player->RemovePet(PET_SAVE_REAGENTS);
        }
    }

    _clientMoverGuid = guid;
}

void WorldSession::HandleSetActiveMoverOpcode(WorldPackets::Movement::SetActiveMover& packet)
{
    if (GetPlayer()->IsInWorld())
        if (_player->GetUnitBeingMoved()->GetGUID() != packet.ActiveMover)
            TC_LOG_DEBUG("network", "HandleSetActiveMoverOpcode: incorrect mover guid: mover is {} and should be {}" , packet.ActiveMover.ToString(), _player->GetUnitBeingMoved()->GetGUID().ToString());
}

void WorldSession::HandleMoveKnockBackAck(WorldPackets::Movement::MoveKnockBackAck& movementAck)
{
    GetPlayer()->ValidateMovementInfo(&movementAck.Ack.Status);

    if (_player->m_unitMovedByMe->GetGUID() != movementAck.Ack.Status.guid)
void WorldSession::HandleMoveNotActiveMoverOpcode(WorldPacket& recvData)
{
    DEBUG_LOG("WORLD: Recvd CMSG_MOVE_NOT_ACTIVE_MOVER");
    recvData.hexlike();

    MovementInfo movementInfo;

#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_9_4
    ObjectGuid old_mover_guid;
    recvData >> old_mover_guid;
    recvData >> movementInfo;
    _clientMoverGuid = ObjectGuid();

    // Client sent not active mover, but maybe the mover is actually set?
    if (_player->GetMover() && _player->GetMover()->GetObjectGuid() == old_mover_guid)
    {
        DETAIL_LOG("HandleMoveNotActiveMover: incorrect mover guid: mover is %s and should be %s instead of %s",
                       _player->GetMover()->GetGuidStr().c_str(),
                       _player->GetGuidStr().c_str(),
                       old_mover_guid.GetString().c_str());
        recvData.rpos(recvData.wpos());                   // prevent warnings spam
        return;
    }
#else
    recvData >> movementInfo;
    _clientMoverGuid = ObjectGuid();
#endif
    
    if (!_player->GetCheatData()->HandleFlagTests(_player, movementInfo, recvData.GetOpcode()) ||
        !_player->GetCheatData()->HandlePositionTests(_player, movementInfo, recvData.GetOpcode()))
    {
        return;
    }

    movementAck.Ack.Status.time = AdjustClientMovementTime(movementAck.Ack.Status.time);
    _player->m_movementInfo = movementAck.Ack.Status;
    // Prevent client from removing root flag.
    if (_player->HasUnitMovementFlag(MOVEFLAG_ROOT) && !movementInfo.HasMovementFlag(MOVEFLAG_ROOT))
        movementInfo.AddMovementFlag(MOVEFLAG_ROOT);

    _player->m_movementInfo = movementInfo;
}

void WorldSession::HandleMountSpecialAnimOpcode(WorldPacket& /*recvdata*/)
{
    //DEBUG_LOG("WORLD: Recvd CMSG_MOUNTSPECIAL_ANIM");

    WorldPacket data(SMSG_MOUNTSPECIAL_ANIM, 8);
    data << GetPlayer()->GetObjectGuid();

    GetPlayer()->SendMovementMessageToSet(std::move(data), false);
}

void WorldSession::HandleSummonResponseOpcode(WorldPacket& recvData)
{
    if (!_player->IsAlive() || _player->IsInCombat())
        return;

    ObjectGuid summonerGuid;
    recvData >> summonerGuid;

    _player->SummonIfPossible(true);
}

void WorldSession::HandleMoveTimeSkippedOpcode(WorldPacket& recvData)
{
    DEBUG_LOG("WORLD: Time Lag/Synchronization Resent/Update");

    ObjectGuid guid;
    recvData >> guid;
    uint32 lag;
    recvData >> lag;

    if (guid != _clientMoverGuid && guid != _player->GetObjectGuid() && guid != _player->GetMover()->GetObjectGuid())
        return;

    Unit* pMover = _player->GetMap()->GetUnit(guid);

    if (!pMover)
        return;

    pMover->m_movementInfo.stime += lag;
    pMover->m_movementInfo.ctime += lag;

    // fix an 1.12 client problem with transports
    if (_player->HasJustBoarded())
    {
        _player->SetJustBoarded(false);
        if (GenericTransport* pTransport = pMover->GetTransport())
        {
            pTransport->SendOutOfRangeUpdateToPlayer(_player);
            pTransport->SendCreateUpdateToPlayer(_player);
        }
    }
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
    else
    {
        TC_LOG_ERROR("network", "HandleMoveApplyMovementForceAck: guid error, expected {}, got {}",
            mover->GetGUID().ToString(), moveApplyMovementForceAck.Ack.Status.guid.ToString());
        return;
    }
        WorldPacket data(MSG_MOVE_TIME_SKIPPED, 12);
        data << pMover->GetPackGUID();
        data << lag;
        pMover->SendMovementMessageToSet(std::move(data), true, _player);
    }
#endif
}

    moveApplyMovementForceAck.Ack.Status.time = AdjustClientMovementTime(moveApplyMovementForceAck.Ack.Status.time);
bool WorldSession::VerifyMovementInfo(MovementInfo const& movementInfo, ObjectGuid const& guid) const
{
    // ignore wrong guid (player attempt cheating own session for not own guid possible...)
    if (guid != _player->GetMover()->GetObjectGuid())
        return false;

    return VerifyMovementInfo(movementInfo);
}

bool WorldSession::VerifyMovementInfo(MovementInfo const& movementInfo) const
{
    if (!MaNGOS::IsValidMapCoord(movementInfo.GetPos().x, movementInfo.GetPos().y, movementInfo.GetPos().z, movementInfo.GetPos().o))
        return false;

    if (movementInfo.HasMovementFlag(MOVEFLAG_ONTRANSPORT))
    {
        TC_LOG_ERROR("network", "HandleMoveRemoveMovementForceAck: guid error, expected {}, got {}",
            mover->GetGUID().ToString(), moveRemoveMovementForceAck.Ack.Status.guid.ToString());
        return;
        // transports size limited
        // (also received at zeppelin/lift leave by some reason with t_* as absolute in continent coordinates, can be safely skipped)
        if (std::fabs(movementInfo.GetTransportPos().x) > 250 || std::fabs(movementInfo.GetTransportPos().y) > 250 || std::fabs(movementInfo.GetTransportPos().z) > 100)
            return false;

        if (!MaNGOS::IsValidMapCoord(movementInfo.GetPos().x + movementInfo.GetTransportPos().x, movementInfo.GetPos().y + movementInfo.GetTransportPos().y,
                                     movementInfo.GetPos().z + movementInfo.GetTransportPos().z, movementInfo.GetPos().o + movementInfo.GetTransportPos().o))
            return false;
    }

    moveRemoveMovementForceAck.Ack.Status.time = AdjustClientMovementTime(moveRemoveMovementForceAck.Ack.Status.time);

    WorldPackets::Movement::MoveUpdateRemoveMovementForce updateRemoveMovementForce;
    updateRemoveMovementForce.Status = &moveRemoveMovementForceAck.Ack.Status;
    updateRemoveMovementForce.TriggerGUID = moveRemoveMovementForceAck.ID;
    mover->SendMessageToSet(updateRemoveMovementForce.Write(), false);
    return true;
}

void WorldSession::HandleMoverRelocation(Unit* pMover, MovementInfo& movementInfo)
{
    movementInfo.CorrectData(pMover);

    // Prevent client from removing root flag.
    if (pMover->HasUnitMovementFlag(MOVEFLAG_ROOT) && !movementInfo.HasMovementFlag(MOVEFLAG_ROOT))
        movementInfo.AddMovementFlag(MOVEFLAG_ROOT);

    Player* const pPlayerMover = pMover->ToPlayer();

    // prevent tampered movement data
    if (setModMovementForceMagnitudeAck.Ack.Status.guid != mover->GetGUID())
    {
        TC_LOG_ERROR("network", "HandleSetModMovementForceMagnitudeAck: guid error, expected {}, got {}",
            mover->GetGUID().ToString(), setModMovementForceMagnitudeAck.Ack.Status.guid.ToString());
        return;
    }
    if (pPlayerMover)
    {
        // ignore current relocation if needed
        if (pPlayerMover->IsNextRelocationIgnored())
        {
            pPlayerMover->DoIgnoreRelocation();
            return;
        }

        if (movementInfo.HasMovementFlag(MOVEFLAG_MASK_MOVING))
        {
            if (ObjectGuid const& lootGuid = pPlayerMover->GetLootGuid())
                if (!lootGuid.IsItem())
                    pPlayerMover->GetSession()->DoLootRelease(lootGuid);
        }
    }

    if (!pPlayerMover)
        pMover->GetMap()->CreatureRelocation((Creature*)pMover, movementInfo.GetPos().x, movementInfo.GetPos().y, movementInfo.GetPos().z, movementInfo.GetPos().o);

    pMover->m_movementInfo = movementInfo;

    if (pMover->m_movementInfo.HasMovementFlag(MOVEFLAG_ONTRANSPORT))
    {
        if (!pMover->GetTransport())
        {
            if (pPlayerMover)
                GetPlayer()->GetCheatData()->OnTransport(pPlayerMover, pPlayerMover->m_movementInfo.GetTransportGuid());

            if (GenericTransport* transport = pMover->GetMap()->GetTransport(pMover->m_movementInfo.GetTransportGuid()))
            {
                TC_LOG_DEBUG("misc", "Player {} from account id {} kicked for incorrect movement force magnitude (must be {} instead {})",
                    _player->GetName(), _player->GetSession()->GetAccountId(), expectedModMagnitude, setModMovementForceMagnitudeAck.Speed);
                _player->GetSession()->KickPlayer("WorldSession::HandleMoveSetModMovementForceMagnitudeAck Incorrect magnitude");
                return;
                transport->AddPassenger(pMover);
                if (pPlayerMover)
                    pPlayerMover->SetJustBoarded(true); // fix a 1.12 client problem with transports
            }
        }
    }

    setModMovementForceMagnitudeAck.Ack.Status.time = AdjustClientMovementTime(setModMovementForceMagnitudeAck.Ack.Status.time);

    WorldPackets::Movement::MoveUpdateSpeed updateModMovementForceMagnitude(SMSG_MOVE_UPDATE_MOD_MOVEMENT_FORCE_MAGNITUDE);
    updateModMovementForceMagnitude.Status = &setModMovementForceMagnitudeAck.Ack.Status;
    updateModMovementForceMagnitude.Speed = setModMovementForceMagnitudeAck.Speed;
    mover->SendMessageToSet(updateModMovementForceMagnitude.Write(), false);
}

void WorldSession::HandleMoveSplineDoneOpcode(WorldPackets::Movement::MoveSplineDone& moveSplineDone)
{
    MovementInfo movementInfo = moveSplineDone.Status;
    _player->ValidateMovementInfo(&movementInfo);
        else
        {
            if (pPlayerMover)
                pPlayerMover->SetJustBoarded(false);
            pMover->m_movementInfo.pos.x = pMover->m_movementInfo.GetTransportPos().x;
            pMover->m_movementInfo.pos.y = pMover->m_movementInfo.GetTransportPos().y;
            pMover->m_movementInfo.pos.z = pMover->m_movementInfo.GetTransportPos().z;
            pMover->m_movementInfo.pos.o = pMover->m_movementInfo.GetTransportPos().o;
            pMover->GetTransport()->CalculatePassengerPosition(pMover->m_movementInfo.pos.x, pMover->m_movementInfo.pos.y, pMover->m_movementInfo.pos.z, &pMover->m_movementInfo.pos.o);
        }
    }
    else if (pMover->GetTransport()) // if we were on a transport, leave
    {
        pMover->m_transport->RemovePassenger(pMover);
        pMover->m_transport = nullptr;
        pMover->m_movementInfo.ClearTransportData();
    }

    movementInfo = pMover->m_movementInfo;

    if (pPlayerMover)
        pPlayerMover->SetPosition(movementInfo.GetPos().x, movementInfo.GetPos().y, movementInfo.GetPos().z, movementInfo.GetPos().o);
    else
        pMover->GetMap()->CreatureRelocation((Creature*)pMover, movementInfo.GetPos().x, movementInfo.GetPos().y, movementInfo.GetPos().z, movementInfo.GetPos().o);

    uint32 curDest = GetPlayer()->m_taxi.GetTaxiDestination();
    if (curDest)
    {
        TaxiNodesEntry const* curDestNode = sTaxiNodesStore.LookupEntry(curDest);

        // far teleport case
        if (curDestNode && curDestNode->ContinentID != GetPlayer()->GetMapId() && GetPlayer()->GetMotionMaster()->GetCurrentMovementGeneratorType() == FLIGHT_MOTION_TYPE)
    if (pPlayerMover)
    {
        // Nostalrius - antiundermap1
        if (movementInfo.HasMovementFlag(MOVEFLAG_FALLINGFAR))
        {
            float hauteur = pPlayerMover->GetMap()->GetHeight(pPlayerMover->GetPositionX(), pPlayerMover->GetPositionY(), pPlayerMover->GetPositionZ(), true);
            bool undermap = false;
            // Undermap
            if ((pPlayerMover->GetPositionZ() + 100.0f) < hauteur)
                undermap = true;
            if (pPlayerMover->GetPositionZ() < 250.0f && pPlayerMover->GetMapId() == 489)
                undermap = true;

            if (undermap)
                if (pPlayerMover->UndermapRecall())
                    sLog.outInfo("[UNDERMAP] %s [GUID %u]. MapId:%u %f %f %f", pPlayerMover->GetName(), pPlayerMover->GetGUIDLow(), pPlayerMover->GetMapId(), pPlayerMover->GetPositionX(), pPlayerMover->GetPositionY(), pPlayerMover->GetPositionZ());
        }
        else if (pPlayerMover->CanFreeMove())
            pPlayerMover->SaveNoUndermapPosition(movementInfo.GetPos().x, movementInfo.GetPos().y, movementInfo.GetPos().z + 3.0f, movementInfo.GetPos().o);
        
        // Antiundermap2: teleport to graveyard
        if (movementInfo.GetPos().z < -500.0f)
        {
            if (FlightPathMovementGenerator* flight = dynamic_cast<FlightPathMovementGenerator*>(GetPlayer()->GetMotionMaster()->GetCurrentMovementGenerator()))
            // NOTE: this is actually called many times while falling
            // even after the player has been teleported away
            // TODO: discard movement packets after the player is rooted
            if (pPlayerMover->IsAlive())
            {
                // short preparations to continue flight
                flight->SetCurrentNodeAfterTeleport();
                TaxiPathNodeEntry const* node = flight->GetPath()[flight->GetCurrentNode()];
                flight->SkipCurrentNode();
                if (pPlayerMover->InBattleGround())
                    pPlayerMover->EnvironmentalDamage(DAMAGE_FALL_TO_VOID, pPlayerMover->GetHealth());
                else
                    pPlayerMover->EnvironmentalDamage(DAMAGE_FALL_TO_VOID, pPlayerMover->GetHealth() / 2);

                // player can be alive if GM and God
                if (!pPlayerMover->IsAlive())
                {
                    // change the death state to CORPSE to prevent the death timer from
                    // starting in the next player update
                    pPlayerMover->KillPlayer();
                    pPlayerMover->BuildPlayerRepop();
                }
            }

            // cancel the death timer here if started
            sLog.outInfo("[UNDERMAP/Teleport] Player %s teleported.", pPlayerMover->GetName(), pPlayerMover->GetGUIDLow(), pPlayerMover->GetMapId(), pPlayerMover->GetPositionX(), pPlayerMover->GetPositionY(), pPlayerMover->GetPositionZ());
            pPlayerMover->RepopAtGraveyard();
        }
    }
}

