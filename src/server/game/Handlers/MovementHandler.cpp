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

#include "Common.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "ObjectAccessor.h"
#include "Opcodes.h"
#include "Log.h"
#include "Map.h"
#include "Corpse.h"
#include "DBCStores.h"
#include "Player.h"
#include "MapManager.h"
#include "MotionMaster.h"
#include "MovementGenerator.h"
#include "MovementPacketSender.h"
#include "MovementPackets.h"
#include "MovementStructures.h"
#include "Transport.h"
#include "Battleground.h"
#include "InstanceSaveMgr.h"
#include "Vehicle.h"
#include "GameTime.h"
#include "GameClient.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include <boost/accumulators/statistics/variance.hpp>
#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics.hpp>

void WorldSession::HandleMoveWorldportAckOpcode(WorldPacket & /*recvData*/)
{
    TC_LOG_DEBUG("network", "WORLD: got MSG_MOVE_WORLDPORT_ACK.");
    HandleMoveWorldportAck();
}

void WorldSession::HandleMoveWorldportAck()
{
    // ignore unexpected far teleports
    if (!GetPlayer()->IsBeingTeleportedFar())
        return;

    GetPlayer()->SetSemaphoreTeleportFar(false);

    // get the teleport destination
    WorldLocation const& loc = GetPlayer()->GetTeleportDest();

    // possible errors in the coordinate validity check
    if (!MapManager::IsValidMapCoord(loc))
    {
        LogoutPlayer(false);
        return;
    }

    // get the destination map entry, not the current one, this will fix homebind and reset greeting
    MapEntry const* mEntry = sMapStore.LookupEntry(loc.GetMapId());

    // reset instance validity, except if going to an instance inside an instance
    if (GetPlayer()->m_InstanceValid == false && !mEntry->IsDungeon())
        GetPlayer()->m_InstanceValid = true;

    Map* oldMap = GetPlayer()->GetMap();
    Map* newMap = GetPlayer()->GetTeleportDestInstanceId() ?
        sMapMgr->FindMap(loc.GetMapId(), *GetPlayer()->GetTeleportDestInstanceId()) :
        sMapMgr->CreateMap(loc.GetMapId(), GetPlayer());

    MovementInfo::TransportInfo transportInfo = GetPlayer()->m_movementInfo.transport;
    if (TransportBase* transport = GetPlayer()->GetTransport())
        transport->RemovePassenger(GetPlayer());

    if (GetPlayer()->IsInWorld())
    {
        TC_LOG_ERROR("network", "%s %s is still in world when teleported from map %s (%u) to new map %s (%u)", GetPlayer()->GetGUID().ToString().c_str(), GetPlayer()->GetName().c_str(), oldMap->GetMapName(), oldMap->GetId(), newMap ? newMap->GetMapName() : "Unknown", loc.GetMapId());
        oldMap->RemovePlayerFromMap(GetPlayer(), false);
    }

    // relocate the player to the teleport destination
    // the CannotEnter checks are done in TeleporTo but conditions may change
    // while the player is in transit, for example the map may get full
    if (!newMap || newMap->CannotEnter(GetPlayer()))
    {
        TC_LOG_ERROR("network", "Map %d (%s) could not be created for player %d (%s), porting player to homebind", loc.GetMapId(), newMap ? newMap->GetMapName() : "Unknown", GetPlayer()->GetGUID().GetCounter(), GetPlayer()->GetName().c_str());
        GetPlayer()->TeleportTo(GetPlayer()->m_homebindMapId, GetPlayer()->m_homebindX, GetPlayer()->m_homebindY, GetPlayer()->m_homebindZ, GetPlayer()->GetOrientation());
        return;
    }

    float z = loc.GetPositionZ() + GetPlayer()->GetHoverOffset();

    GetPlayer()->Relocate(loc.GetPositionX(), loc.GetPositionY(), z, loc.GetOrientation());
    GetPlayer()->SetFallInformation(0, GetPlayer()->GetPositionZ());

    GetPlayer()->ResetMap();
    GetPlayer()->SetMap(newMap);

    GetPlayer()->SendInitialPacketsBeforeAddToMap();

    // move player between transport copies on each map
    if (Transport* newTransport = newMap->GetTransport(transportInfo.guid))
    {
        GetPlayer()->m_movementInfo.transport = transportInfo;
        newTransport->AddPassenger(GetPlayer());
    }

    if (!GetPlayer()->GetMap()->AddPlayerToMap(GetPlayer()))
    {
        TC_LOG_ERROR("network", "WORLD: failed to teleport player %s (%d) to map %d (%s) because of unknown reason!",
            GetPlayer()->GetName().c_str(), GetPlayer()->GetGUID().GetCounter(), loc.GetMapId(), newMap ? newMap->GetMapName() : "Unknown");
        GetPlayer()->ResetMap();
        GetPlayer()->SetMap(oldMap);
        GetPlayer()->TeleportTo(GetPlayer()->m_homebindMapId, GetPlayer()->m_homebindX, GetPlayer()->m_homebindY, GetPlayer()->m_homebindZ, GetPlayer()->GetOrientation());
        return;
    }

    // battleground state prepare (in case join to BG), at relogin/tele player not invited
    // only add to bg group and object, if the player was invited (else he entered through command)
    if (_player->InBattleground())
    {
        // cleanup setting if outdated
        if (!mEntry->IsBattlegroundOrArena())
        {
            // We're not in BG
            _player->SetBattlegroundId(0, BATTLEGROUND_TYPE_NONE);
            // reset destination bg team
            _player->SetBGTeam(0);
        }
        // join to bg case
        else if (Battleground* bg = _player->GetBattleground())
        {
            if (_player->IsInvitedForBattlegroundInstance(_player->GetBattlegroundId()))
                bg->AddPlayer(_player);
        }
    }

    GetPlayer()->SendInitialPacketsAfterAddToMap();

    // flight fast teleport case
    if (GetPlayer()->GetMotionMaster()->GetCurrentMovementGeneratorType() == FLIGHT_MOTION_TYPE)
    {
        if (!_player->InBattleground())
        {
            // short preparations to continue flight
            MovementGenerator* movementGenerator = GetPlayer()->GetMotionMaster()->top();
            movementGenerator->Initialize(GetPlayer());
            return;
        }

        // battleground state prepare, stop flight
        GetPlayer()->GetMotionMaster()->MovementExpired();
        GetPlayer()->CleanupAfterTaxiFlight();
    }

    // resurrect character at enter into instance where his corpse exist after add to map

    if (mEntry->IsDungeon() && !GetPlayer()->IsAlive())
    {
        if (GetPlayer()->GetCorpseLocation().GetMapId() == mEntry->ID)
        {
            GetPlayer()->ResurrectPlayer(0.5f, false);
            GetPlayer()->SpawnCorpseBones();
        }
    }

    if (mEntry->IsDungeon())
    {
        // check if this instance has a reset time and send it to player if so
        Difficulty diff = newMap->GetDifficulty();
        if (MapDifficulty const* mapDiff = sDBCManager.GetMapDifficultyData(mEntry->ID, diff))
        {
            if (mapDiff->resetTime)
            {
                if (time_t timeReset = sInstanceSaveMgr->GetResetTimeFor(mEntry->ID, diff))
                {
                    uint32 timeleft = uint32(timeReset - GameTime::GetGameTime());
                    GetPlayer()->SendInstanceResetWarning(mEntry->ID, diff, timeleft, true);
                }
            }
        }

        // check if instance is valid
        if (!GetPlayer()->CheckInstanceValidity(false))
            GetPlayer()->m_InstanceValid = false;
    }

    // update zone immediately, otherwise leave channel will cause crash in mtmap
    uint32 newzone, newarea;
    GetPlayer()->GetZoneAndAreaId(newzone, newarea);
    GetPlayer()->UpdateZone(newzone, newarea);

    // honorless target
    if (GetPlayer()->pvpInfo.IsHostile)
        GetPlayer()->CastSpell(GetPlayer(), 2479, true);

    // in friendly area
    else if (GetPlayer()->IsPvP() && !GetPlayer()->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_IN_PVP))
        GetPlayer()->UpdatePvP(false, false);

    // resummon pet
    GetPlayer()->ResummonPetTemporaryUnSummonedIfAny();

    //lets process all delayed operations on successful teleport
    GetPlayer()->ProcessDelayedOperations();
}

void WorldSession::HandleSuspendTokenResponse(WorldPackets::Movement::SuspendTokenResponse& /*suspendTokenResponse*/)
{
    if (!_player->IsBeingTeleportedFar())
        return;

    WorldLocation const& loc = GetPlayer()->GetTeleportDest();
    WorldPackets::Movement::NewWorld packet;
    packet.MapID = loc.GetMapId();
    packet.Pos = loc;
    SendPacket(packet.Write());

    _player->SendSavedInstances();
}

void WorldSession::HandleMoveTeleportAck(WorldPackets::Movement::MoveTeleportAck& packet)
{
    if (!IsRightUnitBeingMoved(packet.MoverGUID))
        return;

    GameClient* client = GetGameClient();
    Unit* mover = client->GetActivelyMovedUnit();
    Player* plMover = mover->ToPlayer();

    if (!plMover || !plMover->IsBeingTeleportedNear())
        return;


    plMover->SetSemaphoreTeleportNear(false);

    uint32 old_zone = plMover->GetZoneId();

    WorldLocation const& dest = plMover->GetTeleportDest();

    WorldPackets::Movement::MoveUpdateTeleport moveUpdateTeleport;
    moveUpdateTeleport.Status = &plMover->m_movementInfo;
    moveUpdateTeleport.Status->pos.Relocate(dest);
    plMover->SendMessageToSet(moveUpdateTeleport.Write(), false);

    plMover->UpdatePosition(dest, true);
    plMover->SetFallInformation(0, plMover->GetPositionZ());

    uint32 newzone, newarea;
    plMover->GetZoneAndAreaId(newzone, newarea);
    plMover->UpdateZone(newzone, newarea);

    // new zone
    if (old_zone != newzone)
    {
        // honorless target
        if (plMover->pvpInfo.IsHostile)
            plMover->CastSpell(plMover, 2479, true);

        // in friendly area
        else if (plMover->IsPvP() && !plMover->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_IN_PVP))
            plMover->UpdatePvP(false, false);
    }

    // resummon pet
    GetPlayer()->ResummonPetTemporaryUnSummonedIfAny();

    //lets process all delayed operations on successful teleport
    GetPlayer()->ProcessDelayedOperations();
}

void WorldSession::HandleMovementOpcodes(WorldPacket& recvPacket)
{
    /* extract packet */
    MovementInfo movementInfo;
    GetPlayer()->ReadMovementInfo(recvPacket, &movementInfo);
    uint16 opcode = recvPacket.GetOpcode();

    HandleMovementOpcode(opcode, movementInfo);
}

void WorldSession::HandleMovementOpcode(uint16 opcode, MovementInfo& movementInfo)
{
    if (!IsRightUnitBeingMoved(movementInfo.guid))
        return;

    GameClient* client = GetGameClient();
    Unit* mover = client->GetActivelyMovedUnit();

    // there must always be a mover
    if (!mover)
        return;

    Player* plrMover = mover->ToPlayer();

    // ignore, waiting processing in WorldSession::HandleMoveWorldportAckOpcode and WorldSession::HandleMoveTeleportAck
    if (plrMover && plrMover->IsBeingTeleported())
        return;

    GetPlayer()->ValidateMovementInfo(&movementInfo);

    // prevent tampered movement data
    if (movementInfo.guid != mover->GetGUID())
    {
        TC_LOG_ERROR("network", "HandleMovementOpcodes: guid error");
        return;
    }
    if (!movementInfo.pos.IsPositionValid())
    {
        TC_LOG_ERROR("network", "HandleMovementOpcodes: Invalid Position");
        return;
    }

    // stop some emotes at player move
    if (plrMover && (plrMover->GetUInt32Value(UNIT_NPC_EMOTESTATE) != 0))
        plrMover->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);

    /* handle special cases */
    if (!movementInfo.transport.guid.IsEmpty())
    {
        // We were teleported, skip packets that were broadcast before teleport
        if (movementInfo.pos.GetExactDist2d(mover) > SIZE_OF_GRIDS)
            return;

        // transports size limited
        // (also received at zeppelin leave by some reason with t_* as absolute in continent coordinates, can be safely skipped)
        if (fabs(movementInfo.transport.pos.GetPositionX()) > 75.0f || fabs(movementInfo.transport.pos.GetPositionY()) > 75.0f || fabs(movementInfo.transport.pos.GetPositionZ()) > 75.0f)
            return;

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

        if (!mover->GetTransport() && !mover->GetVehicle())
            movementInfo.transport.Reset();
    }
    else if (plrMover && plrMover->GetTransport())                // if we were on a transport, leave
        plrMover->GetTransport()->RemovePassenger(plrMover);

    // fall damage generation (ignore in flight case that can be triggered also at lags in moment teleportation to another map).
    if (opcode == MSG_MOVE_FALL_LAND && plrMover && !plrMover->IsInFlight())
        plrMover->HandleFall(movementInfo);

    // interrupt parachutes upon falling or landing in water
    if (opcode == MSG_MOVE_FALL_LAND || opcode == MSG_MOVE_START_SWIM || opcode == CMSG_MOVE_SET_CAN_FLY)
        mover->RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::LandingOrFlight); // Parachutes

    /* process position-change */
    int64 movementTime = (int64)movementInfo.time + _timeSyncClockDelta;
    if (_timeSyncClockDelta == 0 || movementTime < 0 || movementTime > 0xFFFFFFFF)
    {
        TC_LOG_WARN("misc", "The computed movement time using clockDelta is erronous. Using fallback instead");
        movementInfo.time = GameTime::GetGameTimeMS();
    }
    else
    {
        movementInfo.time = (uint32)movementTime;
    }

    movementInfo.guid = mover->GetGUID();
    mover->m_movementInfo = movementInfo;

    // Some vehicles allow the passenger to turn by himself
    if (Vehicle* vehicle = mover->GetVehicle())
    {
        if (VehicleSeatEntry const* seat = vehicle->GetSeatForPassenger(mover))
        {
            if (seat->Flags & VEHICLE_SEAT_FLAG_ALLOW_TURNING)
            {
                if (movementInfo.pos.GetOrientation() != mover->GetOrientation())
                {
                    mover->SetOrientation(movementInfo.pos.GetOrientation());
                    mover->RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::Turning);
                }
            }
        }
        return;
    }

    mover->UpdatePosition(movementInfo.pos);

    WorldPacket data(SMSG_MOVE_UPDATE);
    mover->WriteMovementInfo(data);
    mover->SendMessageToSet(&data, _player);

    if (plrMover)                                            // nothing is charmed, or player charmed
    {
        if (plrMover->IsSitState() && (movementInfo.flags & (MOVEMENTFLAG_MASK_MOVING | MOVEMENTFLAG_MASK_TURNING)))
            plrMover->SetStandState(UNIT_STAND_STATE_STAND);

        plrMover->UpdateFallInformationIfNeed(movementInfo, opcode);

        if (movementInfo.pos.GetPositionZ() < plrMover->GetMap()->GetMinHeight(plrMover->GetPhaseShift(), movementInfo.pos.GetPositionX(), movementInfo.pos.GetPositionY()))
        {
            if (!(plrMover->GetBattleground() && plrMover->GetBattleground()->HandlePlayerUnderMap(_player)))
            {
                // NOTE: this is actually called many times while falling
                // even after the player has been teleported away
                /// @todo discard movement packets after the player is rooted
                if (plrMover->IsAlive())
                {
                    plrMover->SetFlag(PLAYER_FLAGS, PLAYER_FLAGS_IS_OUT_OF_BOUNDS);
                    plrMover->EnvironmentalDamage(DAMAGE_FALL_TO_VOID, GetPlayer()->GetMaxHealth());
                    // player can be alive if GM/etc
                    // change the death state to CORPSE to prevent the death timer from
                    // starting in the next player update
                    if (plrMover->IsAlive())
                        plrMover->KillPlayer();
                }
            }
        }

        if (opcode == MSG_MOVE_JUMP)
        {
            plrMover->RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags2::Jump);
            Unit::ProcSkillsAndAuras(plrMover, nullptr, PROC_FLAG_JUMP, PROC_FLAG_NONE, PROC_SPELL_TYPE_MASK_ALL, PROC_SPELL_PHASE_NONE, PROC_HIT_NONE, nullptr, nullptr, nullptr);
        }
    }
}

void WorldSession::HandleForceSpeedChangeAck(WorldPacket &recvData)
{
    /* extract packet */
    MovementInfo movementInfo;
    static MovementStatusElements const speedElement = MSEExtraFloat;
    Movement::ExtraMovementStatusElement extras(&speedElement);
    GetPlayer()->ReadMovementInfo(recvData, &movementInfo, &extras);

    GameClient* client = GetGameClient();

    // ACK handlers should call GameClient::IsAllowedToMove instead of WorldSession::IsRightUnitBeingMoved
    // because the ACK could be coming from a unit that is under the control of that client but is not the 'Active Mover' unit.
    // Example: Get a speed buff on yourself, then mount a vehicle before the end of the buff. When the buff expires,
    // a force message will be sent to the client regarding the player and the client is required to respond with an ACK.
    // But the vehicle will be the active mover unit at that time.
    if (!client->IsAllowedToMove(movementInfo.guid))
    {
        TC_LOG_ERROR("entities.unit", "Ignoring ACK. Bad or outdated movement data by Player %s", _player->GetName().c_str());
        return;
    }

    Unit* mover = ObjectAccessor::GetUnit(*_player, movementInfo.guid);

    UnitMoveType move_type;
    switch (recvData.GetOpcode())
    {
        case CMSG_MOVE_FORCE_WALK_SPEED_CHANGE_ACK:          move_type = MOVE_WALK;          break;
        case CMSG_MOVE_FORCE_RUN_SPEED_CHANGE_ACK:           move_type = MOVE_RUN;           break;
        case CMSG_MOVE_FORCE_RUN_BACK_SPEED_CHANGE_ACK:      move_type = MOVE_RUN_BACK;      break;
        case CMSG_MOVE_FORCE_SWIM_SPEED_CHANGE_ACK:          move_type = MOVE_SWIM;          break;
        case CMSG_MOVE_FORCE_SWIM_BACK_SPEED_CHANGE_ACK:     move_type = MOVE_SWIM_BACK;     break;
        case CMSG_MOVE_FORCE_TURN_RATE_CHANGE_ACK:           move_type = MOVE_TURN_RATE;     break;
        case CMSG_MOVE_FORCE_FLIGHT_SPEED_CHANGE_ACK:        move_type = MOVE_FLIGHT;        break;
        case CMSG_MOVE_FORCE_FLIGHT_BACK_SPEED_CHANGE_ACK:   move_type = MOVE_FLIGHT_BACK;   break;
        case CMSG_MOVE_FORCE_PITCH_RATE_CHANGE_ACK:          move_type = MOVE_PITCH_RATE;    break;
        default:
            TC_LOG_ERROR("network", "WorldSession::HandleForceSpeedChangeAck: Unknown move type opcode: %s", GetOpcodeNameForLogging(static_cast<OpcodeClient>(recvData.GetOpcode())).c_str());
            return;
    }

    MovementChangeType changeType = MovementPacketSender::GetChangeTypeByMoveType(move_type);

    // verify that we have a pending change for the change type and that the counter equals our expected change in case we are about to receive multiple ack messages for the same type
    PlayerMovementPendingChange const* pendingChange = mover->GetPendingMovementChange(changeType);
    if (!pendingChange || pendingChange->movementCounter != movementInfo.movementCounter)
        return;

    // Player tried to apply a speed that has not been request. Possible cheating or malformed packet. Kick the player
    float speedReceived = extras.Data.floatData;
    float speedSent = pendingChange->newValue;
    if (std::fabs(speedSent - speedReceived) > 0.01f)
    {
        TC_LOG_INFO("cheat", "WorldSession::HandleForceSpeedChangeAck: Player %s from account id %u kicked for incorrect data returned in an ack",
            _player->GetName().c_str(), _player->GetSession()->GetAccountId());
        _player->GetSession()->KickPlayer();
        return;
    }

    MovementPacketSender::SendSpeedChangeToObservers(mover, move_type, speedSent);
    mover->ClearPendingMovementChangeForType(changeType);
}

void WorldSession::HandleSetActiveMoverOpcode(WorldPackets::Movement::SetActiveMover& packet)
{
    GameClient* client = GetGameClient();

    // step 1: look at the list of units that this client is allowed to move. check if the client is allowed to even move the
    // unit that is mentioned in the packet. if not, either silently ignore, log this event or kick the client.
    if (!client->IsAllowedToMove(packet.ActiveMover))
    {
        // @todo log or kick or do nothing depending on configuration
        TC_LOG_DEBUG("entities.unit", "set active mover FAILED for client of player %s. GUID %s.", _player->GetName().c_str(), packet.ActiveMover.ToString().c_str());
        return;
    }

    // step 2:
    TC_LOG_DEBUG("entities.unit", "set active mover OK for client of player %s. GUID %s.", _player->GetName().c_str(), packet.ActiveMover.ToString().c_str());
    Unit* newActivelyMovedUnit = ObjectAccessor::GetUnit(*_player, packet.ActiveMover);
    client->SetActivelyMovedUnit(newActivelyMovedUnit);
}

void WorldSession::HandleMoveNotActiveMover(WorldPacket &recvData)
{
    TC_LOG_DEBUG("network", "WORLD: Recvd CMSG_MOVE_NOT_ACTIVE_MOVER");

    MovementInfo movementInfo;
    _player->ReadMovementInfo(recvData, &movementInfo);

    GameClient* client = GetGameClient();
    if (client->GetActivelyMovedUnit() == nullptr || client->GetActivelyMovedUnit()->GetGUID() != movementInfo.guid)
    {
        TC_LOG_DEBUG("entities.unit", "unset active mover FAILED for client of player %s. GUID %s.", _player->GetName().c_str(), movementInfo.guid.ToString().c_str());
        return;
    }

    TC_LOG_DEBUG("entities.unit", "unset active mover OK for client of player %s. GUID %s.", _player->GetName().c_str(), movementInfo.guid.ToString().c_str());
    client->SetActivelyMovedUnit(nullptr);
}

void WorldSession::HandleMountSpecialAnimOpcode(WorldPacket& /*recvData*/)
{
    WorldPacket data(SMSG_MOUNTSPECIAL_ANIM, 8);
    data << uint64(GetPlayer()->GetGUID());

    GetPlayer()->SendMessageToSet(&data, false);
}

void WorldSession::HandleSummonResponseOpcode(WorldPacket& recvData)
{
    if (!_player->IsAlive() || _player->IsInCombat())
        return;

    ObjectGuid summoner_guid;
    bool agree;
    recvData >> summoner_guid;
    recvData >> agree;

    _player->SummonIfPossible(agree);
}

void WorldSession::HandleMoveKnockBackAck(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "CMSG_MOVE_KNOCK_BACK_ACK");

    MovementInfo movementInfo;
    GetPlayer()->ReadMovementInfo(recvData, &movementInfo);

    GameClient* client = GetGameClient();

    // ACK handlers should call GameClient::IsAllowedToMove instead of WorldSession::IsRightUnitBeingMoved
    // because the ACK could be coming from a unit that is under the control of that client but is not the 'Active Mover' unit.
    // Example: Get a speed buff on yourself, then mount a vehicle before the end of the buff. When the buff expires,
    // a force message will be sent to the client regarding the player and the client is required to respond with an ACK.
    // But the vehicle will be the active mover unit at that time.
    if (!client->IsAllowedToMove(movementInfo.guid))
        return;

    Unit* mover = ObjectAccessor::GetUnit(*_player, movementInfo.guid);

    int64 movementTime = (int64)movementInfo.time + _timeSyncClockDelta;
    if (_timeSyncClockDelta == 0 || movementTime < 0 || movementTime > 0xFFFFFFFF)
    {
        TC_LOG_WARN("misc", "The computed movement time using clockDelta is erronous. Using fallback instead");
        movementInfo.time = GameTime::GetGameTimeMS();
    }
    else
    {
        movementInfo.time = (uint32)movementTime;
    }

    mover->m_movementInfo = movementInfo;
    mover->UpdatePosition(movementInfo.pos);

    WorldPacket data(SMSG_MOVE_UPDATE_KNOCK_BACK, 66);
    mover->WriteMovementInfo(data);
    client->GetBasePlayer()->SendMessageToSet(&data, false);
}

void WorldSession::HandleMoveHoverAck(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "CMSG_MOVE_HOVER_ACK");
    MovementInfo movementInfo;
    GetPlayer()->ReadMovementInfo(recvData, &movementInfo);
}

void WorldSession::HandleMoveWaterWalkAck(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "CMSG_MOVE_WATER_WALK_ACK");
    MovementInfo movementInfo;
    GetPlayer()->ReadMovementInfo(recvData, &movementInfo);
}

void WorldSession::HandleMoveRootAck(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "CMSG_FORCE_MOVE_ROOT_ACK");
    MovementInfo movementInfo;
    GetPlayer()->ReadMovementInfo(recvData, &movementInfo);
}

void WorldSession::HandleFeatherFallAck(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "CMSG_MOVE_FEATHER_FALL_ACK");
    MovementInfo movementInfo;
    GetPlayer()->ReadMovementInfo(recvData, &movementInfo);
}

void WorldSession::HandleMoveUnRootAck(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "CMSG_FORCE_MOVE_UNROOT_ACK");
    MovementInfo movementInfo;
    GetPlayer()->ReadMovementInfo(recvData, &movementInfo);
}

void WorldSession::HandleMoveSetCanTransitionBetweenSwinAndFlyAck(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "CMSG_MOVE_SET_CAN_TRANSITION_BETWEEN_SWIM_AND_FLY_ACK");
    MovementInfo movementInfo;
    GetPlayer()->ReadMovementInfo(recvData, &movementInfo);

    GameClient* client = GetGameClient();
    if (!client->IsAllowedToMove(movementInfo.guid))
        return;

    Unit* mover = ObjectAccessor::GetUnit(*_player, movementInfo.guid);

    // verify that we have a pending change for the change type and that the counter equals our expected change in case we are about to receive multiple ack messages for the same type
    PlayerMovementPendingChange const* pendingChange = mover->GetPendingMovementChange(MovementChangeType::SET_CAN_TRANSITION_BETWEEN_SWIM_AND_FLY);
    if (!pendingChange || pendingChange->movementCounter != movementInfo.movementCounter)
        return;

    MovementPacketSender::SendMovementFlagChangeToObservers(mover);
    mover->ClearPendingMovementChangeForType(MovementChangeType::SET_CAN_TRANSITION_BETWEEN_SWIM_AND_FLY);
}

void WorldSession::HandleMoveGravityDisableAck(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "received %s", GetOpcodeNameForLogging(static_cast<OpcodeClient>(recvData.GetOpcode())).c_str());
    MovementInfo movementInfo;
    GetPlayer()->ReadMovementInfo(recvData, &movementInfo);

    GameClient* client = GetGameClient();
    if (!client->IsAllowedToMove(movementInfo.guid))
        return;

    Unit* mover = ObjectAccessor::GetUnit(*_player, movementInfo.guid);

    // verify that we have a pending change for the change type and that the counter equals our expected change in case we are about to receive multiple ack messages for the same type
    PlayerMovementPendingChange const* pendingChange = mover->GetPendingMovementChange(MovementChangeType::GRAVITY_DISABLE);
    bool disable = recvData.GetOpcode() == CMSG_MOVE_GRAVITY_DISABLE_ACK;
    if (!pendingChange || pendingChange->movementCounter != movementInfo.movementCounter)
        return;

    if (pendingChange->apply != disable)
    {
        TC_LOG_INFO("cheat", "WorldSession::HandleMoveGravityDisableAck: Player %s from account id %u kicked for incorrect data returned in an ack",
            _player->GetName().c_str(), _player->GetSession()->GetAccountId());
        _player->GetSession()->KickPlayer();
        return;
    }

    MovementPacketSender::SendMovementFlagChangeToObservers(mover);
    mover->ClearPendingMovementChangeForType(MovementChangeType::GRAVITY_DISABLE);
}

void WorldSession::HandleSetCollisionHeightAck(WorldPacket& recvData)
{
    MovementInfo movementInfo;
    static MovementStatusElements const extraElements[] =
    {
        MSEExtraFloat,
        MSEExtraTwoBits
    };

    Movement::ExtraMovementStatusElement extra(extraElements);
    GetPlayer()->ReadMovementInfo(recvData, &movementInfo, &extra);

    GameClient* client = GetGameClient();
    if (!client->IsAllowedToMove(movementInfo.guid))
        return;

    Unit* mover = ObjectAccessor::GetUnit(*_player, movementInfo.guid);

    PlayerMovementPendingChange const* pendingChange = mover->GetPendingMovementChange(MovementChangeType::SET_COLLISION_HGT);
    if (!pendingChange || pendingChange->movementCounter != movementInfo.movementCounter)
        return;

    if (std::fabs(pendingChange->newValue - extra.Data.floatData) > 0.01f)
    {
        TC_LOG_INFO("cheat", "WorldSession::HandleSetCollisionHeightAck: Player %s from account id %u kicked for incorrect data returned in an ack",
            _player->GetName().c_str(), _player->GetSession()->GetAccountId());
        _player->GetSession()->KickPlayer();
        return;
    }

    MovementPacketSender::SendHeightChangeToObservers(mover, pendingChange->newValue);
}

void WorldSession::HandleMoveSetCanFlyAckOpcode(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "CMSG_MOVE_SET_CAN_FLY_ACK");
    MovementInfo movementInfo;
    GetPlayer()->ReadMovementInfo(recvData, &movementInfo);

    GameClient* client = GetGameClient();
    if (!client->IsAllowedToMove(movementInfo.guid))
        return;

    Unit* mover = ObjectAccessor::GetUnit(*_player, movementInfo.guid);

    // verify that we have a pending change for the change type and that the counter equals our expected change in case we are about to receive multiple ack messages for the same type
    PlayerMovementPendingChange const* pendingChange = mover->GetPendingMovementChange(MovementChangeType::SET_CAN_FLY);
    if (!pendingChange || pendingChange->movementCounter != movementInfo.movementCounter)
        return;

    int64 movementTime = (int64)movementInfo.time + _timeSyncClockDelta;
    if (_timeSyncClockDelta == 0 || movementTime < 0 || movementTime > 0xFFFFFFFF)
    {
        TC_LOG_WARN("misc", "The computed movement time using clockDelta is erronous. Using fallback instead");
        movementInfo.time = GameTime::GetGameTimeMS();
    }
    else
    {
        movementInfo.time = (uint32)movementTime;
    }

    MovementPacketSender::SendMovementFlagChangeToObservers(mover);
    mover->ClearPendingMovementChangeForType(MovementChangeType::SET_CAN_FLY);
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

    if (!IsRightUnitBeingMoved(guid))
        return;

    GameClient* client = GetGameClient();
    Unit* mover = client->GetActivelyMovedUnit();

    if (!mover)
    {
        TC_LOG_WARN("entities.player", "WorldSession::HandleMoveTimeSkippedOpcode wrong mover state from the unit moved by the player %s", GetPlayer()->GetGUID().ToString().c_str());
        return;
    }

    // prevent tampered movement data
    if (guid != mover->GetGUID())
    {
        TC_LOG_WARN("entities.player", "WorldSession::HandleMoveTimeSkippedOpcode wrong guid from the unit moved by the player %s", GetPlayer()->GetGUID().ToString().c_str());
        return;
    }

    mover->m_movementInfo.time += time;

    WorldPacket data(MSG_MOVE_TIME_SKIPPED, recvData.size());
    data << time;
    data << guid.WriteAsPacked();
    GetPlayer()->SendMessageToSet(&data, false);
}

void WorldSession::HandleTimeSyncResp(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "CMSG_TIME_SYNC_RESP");

    uint32 counter, clientTimestamp;
    recvData >> counter >> clientTimestamp;

    if (_pendingTimeSyncRequests.count(counter) == 0)
        return;

    uint32 serverTimeAtSent = _pendingTimeSyncRequests.at(counter);
    _pendingTimeSyncRequests.erase(counter);

    // time it took for the request to travel to the client, for the client to process it and reply and for response to travel back to the server.
    // we are going to make 2 assumptions:
    // 1) we assume that the request processing time equals 0.
    // 2) we assume that the packet took as much time to travel from server to client than it took to travel from client to server.
    uint32 roundTripDuration = getMSTimeDiff(serverTimeAtSent, recvData.GetReceivedTime());
    uint32 lagDelay = roundTripDuration / 2;

    /*
    clockDelta = serverTime - clientTime
    where
    serverTime: time that was displayed on the clock of the SERVER at the moment when the client processed the SMSG_TIME_SYNC_REQUEST packet.
    clientTime:  time that was displayed on the clock of the CLIENT at the moment when the client processed the SMSG_TIME_SYNC_REQUEST packet.

    Once clockDelta has been computed, we can compute the time of an event on server clock when we know the time of that same event on the client clock,
    using the following relation:
    serverTime = clockDelta + clientTime
    */
    int64 clockDelta = (int64)(serverTimeAtSent + lagDelay) - (int64)clientTimestamp;
    _timeSyncClockDeltaQueue.push_back(std::pair<int64, uint32>(clockDelta, roundTripDuration));
    ComputeNewClockDelta();
}

void WorldSession::ComputeNewClockDelta()
{
    // implementation of the technique described here: https://web.archive.org/web/20180430214420/http://www.mine-control.com/zack/timesync/timesync.html
    // to reduce the skew induced by dropped TCP packets that get resent.

    using namespace boost::accumulators;

    accumulator_set<uint32, features<tag::mean, tag::median, tag::variance(lazy)> > latencyAccumulator;

    for (auto pair : _timeSyncClockDeltaQueue)
        latencyAccumulator(pair.second);

    uint32 latencyMedian = static_cast<uint32>(std::round(median(latencyAccumulator)));
    uint32 latencyStandardDeviation = static_cast<uint32>(std::round(sqrt(variance(latencyAccumulator))));

    accumulator_set<int64, features<tag::mean> > clockDeltasAfterFiltering;
    uint32 sampleSizeAfterFiltering = 0;
    for (auto pair : _timeSyncClockDeltaQueue)
    {
        if (pair.second < latencyStandardDeviation + latencyMedian)
        {
            clockDeltasAfterFiltering(pair.first);
            sampleSizeAfterFiltering++;
        }
    }

    if (sampleSizeAfterFiltering != 0)
    {
        int64 meanClockDelta = static_cast<int64>(std::round(mean(clockDeltasAfterFiltering)));
        if (std::abs(meanClockDelta - _timeSyncClockDelta) > 25)
            _timeSyncClockDelta = meanClockDelta;
    }
    else if (_timeSyncClockDelta == 0)
    {
        std::pair<int64, uint32> back = _timeSyncClockDeltaQueue.back();
        _timeSyncClockDelta = back.first;
    }
}
