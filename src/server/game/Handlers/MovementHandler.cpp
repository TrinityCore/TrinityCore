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
#include "Battleground.h"
#include "Common.h"
#include "Corpse.h"
#include "DB2Stores.h"
#include "FlightPathMovementGenerator.h"
#include "GameTime.h"
#include "Garrison.h"
#include "InstancePackets.h"
#include "InstanceSaveMgr.h"
#include "Log.h"
#include "MapManager.h"
#include "MovementPackets.h"
#include "ObjectMgr.h"
#include "Opcodes.h"
#include "Player.h"
#include "SpellInfo.h"
#include "MotionMaster.h"
#include "MovementGenerator.h"
#include "Transport.h"
#include "Vehicle.h"
#include "SpellMgr.h"

#define MOVEMENT_PACKET_TIME_DELAY 0

void WorldSession::HandleMoveWorldportAckOpcode(WorldPackets::Movement::WorldPortResponse& /*packet*/)
{
    HandleMoveWorldportAck();
}

void WorldSession::HandleMoveWorldportAck()
{
    Player* player = GetPlayer();
    // ignore unexpected far teleports
    if (!player->IsBeingTeleportedFar())
        return;

    bool seamlessTeleport = player->IsBeingTeleportedSeamlessly();
    player->SetSemaphoreTeleportFar(false);

    // get the teleport destination
    WorldLocation const& loc = player->GetTeleportDest();

    // possible errors in the coordinate validity check
    if (!MapManager::IsValidMapCoord(loc))
    {
        LogoutPlayer(false);
        return;
    }

    // get the destination map entry, not the current one, this will fix homebind and reset greeting
    MapEntry const* mEntry = sMapStore.LookupEntry(loc.GetMapId());
    InstanceTemplate const* mInstance = sObjectMgr->GetInstanceTemplate(loc.GetMapId());

    // reset instance validity, except if going to an instance inside an instance
    if (player->m_InstanceValid == false && !mInstance)
        player->m_InstanceValid = true;

    Map* oldMap = player->GetMap();
    Map* newMap = sMapMgr->CreateMap(loc.GetMapId(), player);

    if (player->IsInWorld())
    {
        TC_LOG_ERROR("network", "%s %s is still in world when teleported from map %s (%u) to new map %s (%u)", player->GetGUID().ToString().c_str(), player->GetName().c_str(), oldMap->GetMapName(), oldMap->GetId(), newMap ? newMap->GetMapName() : "Unknown", loc.GetMapId());
        oldMap->RemovePlayerFromMap(player, false);
    }

    // relocate the player to the teleport destination
    // the CannotEnter checks are done in TeleporTo but conditions may change
    // while the player is in transit, for example the map may get full
    if (!newMap || newMap->CannotEnter(player))
    {
        TC_LOG_ERROR("network", "Map %d (%s) could not be created for player %s (%s), porting player to homebind", loc.GetMapId(), newMap ? newMap->GetMapName() : "Unknown", player->GetGUID().ToString().c_str(), player->GetName().c_str());
        player->TeleportTo(player->m_homebind);
        return;
    }

    float z = loc.GetPositionZ() + player->GetHoverOffset();
    player->Relocate(loc.GetPositionX(), loc.GetPositionY(), z, loc.GetOrientation());
    player->SetFallInformation(0, player->GetPositionZ());

    player->ResetMap();
    player->SetMap(newMap);

    WorldPackets::Movement::ResumeToken resumeToken;
    resumeToken.SequenceIndex = player->m_movementCounter;
    resumeToken.Reason = seamlessTeleport ? 2 : 1;
    SendPacket(resumeToken.Write());

    if (!seamlessTeleport)
        player->SendInitialPacketsBeforeAddToMap();

    if (!player->GetMap()->AddPlayerToMap(player, !seamlessTeleport))
    {
        TC_LOG_ERROR("network", "WORLD: failed to teleport player %s (%s) to map %d (%s) because of unknown reason!",
            player->GetName().c_str(), player->GetGUID().ToString().c_str(), loc.GetMapId(), newMap ? newMap->GetMapName() : "Unknown");
        player->ResetMap();
        player->SetMap(oldMap);
        player->TeleportTo(player->m_homebind);
        return;
    }

    // battleground state prepare (in case join to BG), at relogin/tele player not invited
    // only add to bg group and object, if the player was invited (else he entered through command)
    if (player->InBattleground())
    {
        // cleanup setting if outdated
        if (!mEntry->IsBattlegroundOrArena())
        {
            // We're not in BG
            player->SetBattlegroundId(0, BATTLEGROUND_TYPE_NONE);
            // reset destination bg team
            player->SetBGTeam(0);
        }
        // join to bg case
        else if (Battleground* bg = player->GetBattleground())
        {
            if (player->IsInvitedForBattlegroundInstance(player->GetBattlegroundId()))
                bg->AddPlayer(player);
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

    // flight fast teleport case
    if (player->IsInFlight())
    {
        if (!player->InBattleground())
        {
            if (!seamlessTeleport)
            {
                // short preparations to continue flight
                MovementGenerator* movementGenerator = player->GetMotionMaster()->GetCurrentMovementGenerator();
                movementGenerator->Initialize(player);
            }
            return;
        }

        // battleground state prepare, stop flight
        player->FinishTaxiFlight();
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

    if (mInstance)
    {
        // check if this instance has a reset time and send it to player if so
        Difficulty diff = newMap->GetDifficultyID();
        if (MapDifficultyEntry const* mapDiff = sDB2Manager.GetMapDifficultyData(mEntry->ID, diff))
        {
            if (mapDiff->GetRaidDuration())
            {
                if (time_t timeReset = sInstanceSaveMgr->GetResetTimeFor(mEntry->ID, diff))
                {
                    uint32 timeleft = uint32(timeReset - GameTime::GetGameTime());
                    player->SendInstanceResetWarning(mEntry->ID, diff, timeleft, true);
                }
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

    // honorless target
    if (player->pvpInfo.IsHostile)
        player->CastSpell(player, 2479, true);

    // in friendly area
    else if (player->IsPvP() && !player->HasPlayerFlag(PLAYER_FLAGS_IN_PVP))
        player->UpdatePvP(false, false);

    // resummon pet
    player->ResummonPetTemporaryUnSummonedIfAny();

    //lets process all delayed operations on successful teleport
    player->ProcessDelayedOperations();
}

void WorldSession::HandleSuspendTokenResponse(WorldPackets::Movement::SuspendTokenResponse& /*suspendTokenResponse*/)
{
    if (!_player->IsBeingTeleportedFar())
        return;

    WorldLocation const& loc = GetPlayer()->GetTeleportDest();

    if (sMapStore.AssertEntry(loc.GetMapId())->IsDungeon())
    {
        WorldPackets::Instance::UpdateLastInstance updateLastInstance;
        updateLastInstance.MapID = loc.GetMapId();
        SendPacket(updateLastInstance.Write());
    }

    WorldPackets::Movement::NewWorld packet;
    packet.MapID = loc.GetMapId();
    packet.Loc.Pos = loc;
    packet.Reason = !_player->IsBeingTeleportedSeamlessly() ? NEW_WORLD_NORMAL : NEW_WORLD_SEAMLESS;
    SendPacket(packet.Write());

    if (_player->IsBeingTeleportedSeamlessly())
        HandleMoveWorldportAck();
}

void WorldSession::HandleMoveTeleportAck(WorldPackets::Movement::MoveTeleportAck& packet)
{
    TC_LOG_DEBUG("network", "CMSG_MOVE_TELEPORT_ACK: Guid: %s, Sequence: %u, Time: %u", packet.MoverGUID.ToString().c_str(), packet.AckIndex, packet.MoveTime);

    Player* plMover = _player->m_unitMovedByMe->ToPlayer();

    if (!plMover || !plMover->IsBeingTeleportedNear())
        return;

    if (packet.MoverGUID != plMover->GetGUID())
        return;

    plMover->SetSemaphoreTeleportNear(false);

    uint32 old_zone = plMover->GetZoneId();

    WorldLocation const& dest = plMover->GetTeleportDest();

    plMover->UpdatePosition(dest, true);
    plMover->SetFallInformation(0, GetPlayer()->GetPositionZ());

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
        else if (plMover->IsPvP() && !plMover->HasPlayerFlag(PLAYER_FLAGS_IN_PVP))
            plMover->UpdatePvP(false, false);
    }

    // resummon pet
    GetPlayer()->ResummonPetTemporaryUnSummonedIfAny();

    //lets process all delayed operations on successful teleport
    GetPlayer()->ProcessDelayedOperations();
}

void WorldSession::HandleMovementOpcodes(WorldPackets::Movement::ClientPlayerMovement& packet)
{
    HandleMovementOpcode(packet.GetOpcode(), packet.Status);
}

void WorldSession::HandleMovementOpcode(OpcodeClient opcode, MovementInfo& movementInfo)
{
    Unit* mover = _player->m_unitMovedByMe;

    ASSERT(mover != nullptr);                      // there must always be a mover

    Player* plrMover = mover->ToPlayer();

    TC_LOG_TRACE("opcodes.movement", "HandleMovementOpcode Name %s: opcode %u %s Flags %u Flags2 %u Pos %s",
        mover->GetName().c_str(), opcode, GetOpcodeNameForLogging(opcode).c_str(),
        movementInfo.flags, movementInfo.flags2, movementInfo.pos.ToString().c_str());

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
    if (plrMover && (plrMover->GetEmoteState() != 0))
        plrMover->SetEmoteState(EMOTE_ONESHOT_NONE);

    /* handle special cases */
    if (!movementInfo.transport.guid.IsEmpty())
    {
        // We were teleported, skip packets that were broadcast before teleport
        if (movementInfo.pos.GetExactDist2d(mover) > SIZE_OF_GRIDS)
            return;

        // transports size limited
        // (also received at zeppelin leave by some reason with t_* as absolute in continent coordinates, can be safely skipped)
        if (fabs(movementInfo.transport.pos.GetPositionX()) > 75.0f || fabs(movementInfo.transport.pos.GetPositionY()) > 75.0f || fabs(movementInfo.transport.pos.GetPositionZ()) > 75.0f)
        {
            return;
        }

        if (!Trinity::IsValidMapCoord(movementInfo.pos.GetPositionX() + movementInfo.transport.pos.GetPositionX(), movementInfo.pos.GetPositionY() + movementInfo.transport.pos.GetPositionY(),
            movementInfo.pos.GetPositionZ() + movementInfo.transport.pos.GetPositionZ(), movementInfo.pos.GetOrientation() + movementInfo.transport.pos.GetOrientation()))
        {
            return;
        }

        // if we boarded a transport, add us to it
        if (plrMover)
        {
            if (!plrMover->GetTransport())
            {
                if (Transport* transport = plrMover->GetMap()->GetTransport(movementInfo.transport.guid))
                    transport->AddPassenger(plrMover);
            }
            else if (plrMover->GetTransport()->GetGUID() != movementInfo.transport.guid)
            {
                plrMover->GetTransport()->RemovePassenger(plrMover);
                if (Transport* transport = plrMover->GetMap()->GetTransport(movementInfo.transport.guid))
                    transport->AddPassenger(plrMover);
                else
                    movementInfo.ResetTransport();
            }
        }

        if (!mover->GetTransport() && !mover->GetVehicle())
        {
            GameObject* go = mover->GetMap()->GetGameObject(movementInfo.transport.guid);
            if (!go || go->GetGoType() != GAMEOBJECT_TYPE_TRANSPORT)
                movementInfo.transport.Reset();
        }
    }
    else if (plrMover && plrMover->GetTransport())                // if we were on a transport, leave
        plrMover->m_transport->RemovePassenger(plrMover);

    // fall damage generation (ignore in flight case that can be triggered also at lags in moment teleportation to another map).
    if (opcode == CMSG_MOVE_FALL_LAND && plrMover && !plrMover->IsInFlight())
        plrMover->HandleFall(movementInfo);

    // interrupt parachutes upon falling or landing in water
    if (opcode == CMSG_MOVE_FALL_LAND || opcode == CMSG_MOVE_START_SWIM || opcode == CMSG_MOVE_SET_FLY)
        mover->RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::LandingOrFlight); // Parachutes

    uint32 mstime = GameTime::GetGameTimeMS();
    /*----------------------*/
    if (m_clientTimeDelay == 0)
        m_clientTimeDelay = mstime - movementInfo.time;

    /* process position-change */
    movementInfo.time = movementInfo.time + m_clientTimeDelay + MOVEMENT_PACKET_TIME_DELAY;

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

    WorldPackets::Movement::MoveUpdate moveUpdate;
    moveUpdate.Status = &mover->m_movementInfo;
    mover->SendMessageToSet(moveUpdate.Write(), _player);

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
                    plrMover->AddPlayerFlag(PLAYER_FLAGS_IS_OUT_OF_BOUNDS);
                    plrMover->EnvironmentalDamage(DAMAGE_FALL_TO_VOID, GetPlayer()->GetMaxHealth());
                    // player can be alive if GM/etc
                    // change the death state to CORPSE to prevent the death timer from
                    // starting in the next player update
                    if (plrMover->IsAlive())
                        plrMover->KillPlayer();
                }
            }
        }
        else
            plrMover->RemovePlayerFlag(PLAYER_FLAGS_IS_OUT_OF_BOUNDS);

        if (opcode == CMSG_MOVE_JUMP)
        {
            plrMover->RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags2::Jump);
            Unit::ProcSkillsAndAuras(plrMover, nullptr, PROC_FLAG_JUMP, PROC_FLAG_NONE, PROC_SPELL_TYPE_MASK_ALL, PROC_SPELL_PHASE_NONE, PROC_HIT_NONE, nullptr, nullptr, nullptr);
        }
    }
}

void WorldSession::HandleForceSpeedChangeAck(WorldPackets::Movement::MovementSpeedAck& packet)
{

    GetPlayer()->ValidateMovementInfo(&packet.Ack.Status);

    // now can skip not our packet
    if (_player->GetGUID() != packet.Ack.Status.guid)
        return;

    /*----------------*/

    // client ACK send one packet for mounted/run case and need skip all except last from its
    // in other cases anti-cheat check can be fail in false case
    UnitMoveType move_type;

    static char const* const move_type_name[MAX_MOVE_TYPE] =
    {
        "Walk",
        "Run",
        "RunBack",
        "Swim",
        "SwimBack",
        "TurnRate",
        "Flight",
        "FlightBack",
        "PitchRate"
    };

    OpcodeClient opcode = packet.GetOpcode();
    switch (opcode)
    {

        case CMSG_MOVE_FORCE_WALK_SPEED_CHANGE_ACK:        move_type = MOVE_WALK;        break;
        case CMSG_MOVE_FORCE_RUN_SPEED_CHANGE_ACK:         move_type = MOVE_RUN;         break;
        case CMSG_MOVE_FORCE_RUN_BACK_SPEED_CHANGE_ACK:    move_type = MOVE_RUN_BACK;    break;
        case CMSG_MOVE_FORCE_SWIM_SPEED_CHANGE_ACK:        move_type = MOVE_SWIM;        break;
        case CMSG_MOVE_FORCE_SWIM_BACK_SPEED_CHANGE_ACK:   move_type = MOVE_SWIM_BACK;   break;
        case CMSG_MOVE_FORCE_TURN_RATE_CHANGE_ACK:         move_type = MOVE_TURN_RATE;   break;
        case CMSG_MOVE_FORCE_FLIGHT_SPEED_CHANGE_ACK:      move_type = MOVE_FLIGHT;      break;
        case CMSG_MOVE_FORCE_FLIGHT_BACK_SPEED_CHANGE_ACK: move_type = MOVE_FLIGHT_BACK; break;
        case CMSG_MOVE_FORCE_PITCH_RATE_CHANGE_ACK:        move_type = MOVE_PITCH_RATE;  break;

        default:
            TC_LOG_ERROR("network", "WorldSession::HandleForceSpeedChangeAck: Unknown move type opcode: %u", opcode);
            return;
    }

    // skip all forced speed changes except last and unexpected
    // in run/mounted case used one ACK and it must be skipped. m_forced_speed_changes[MOVE_RUN] store both.
    if (_player->m_forced_speed_changes[move_type] > 0)
    {
        --_player->m_forced_speed_changes[move_type];
        if (_player->m_forced_speed_changes[move_type] > 0)
            return;
    }

    if (!_player->GetTransport() && std::fabs(_player->GetSpeed(move_type) - packet.Speed) > 0.01f)
    {
        if (_player->GetSpeed(move_type) > packet.Speed)         // must be greater - just correct
        {
            TC_LOG_ERROR("network", "%sSpeedChange player %s is NOT correct (must be %f instead %f), force set to correct value",
                move_type_name[move_type], _player->GetName().c_str(), _player->GetSpeed(move_type), packet.Speed);
            _player->SetSpeedRate(move_type, _player->GetSpeedRate(move_type));
        }
        else                                                // must be lesser - cheating
        {
            TC_LOG_DEBUG("misc", "Player %s from account id %u kicked for incorrect speed (must be %f instead %f)",
                _player->GetName().c_str(), _player->GetSession()->GetAccountId(), _player->GetSpeed(move_type), packet.Speed);
            _player->GetSession()->KickPlayer();
        }
    }
}

void WorldSession::HandleSetActiveMoverOpcode(WorldPackets::Movement::SetActiveMover& packet)
{
    if (GetPlayer()->IsInWorld())
        if (_player->m_unitMovedByMe->GetGUID() != packet.ActiveMover)
            TC_LOG_DEBUG("network", "HandleSetActiveMoverOpcode: incorrect mover guid: mover is %s and should be %s" , packet.ActiveMover.ToString().c_str(), _player->m_unitMovedByMe->GetGUID().ToString().c_str());
}

void WorldSession::HandleMoveKnockBackAck(WorldPackets::Movement::MoveKnockBackAck& movementAck)
{
    GetPlayer()->ValidateMovementInfo(&movementAck.Ack.Status);

    if (_player->m_unitMovedByMe->GetGUID() != movementAck.Ack.Status.guid)
        return;

    _player->m_movementInfo = movementAck.Ack.Status;

    WorldPackets::Movement::MoveUpdateKnockBack updateKnockBack;
    updateKnockBack.Status = &_player->m_movementInfo;
    _player->SendMessageToSet(updateKnockBack.Write(), false);
}

void WorldSession::HandleMovementAckMessage(WorldPackets::Movement::MovementAckMessage& movementAck)
{
    GetPlayer()->ValidateMovementInfo(&movementAck.Ack.Status);
}

void WorldSession::HandleSummonResponseOpcode(WorldPackets::Movement::SummonResponse& packet)
{
    if (!_player->IsAlive() || _player->IsInCombat())
        return;

    _player->SummonIfPossible(packet.Accept);
}

void WorldSession::HandleSetCollisionHeightAck(WorldPackets::Movement::MoveSetCollisionHeightAck& setCollisionHeightAck)
{
    GetPlayer()->ValidateMovementInfo(&setCollisionHeightAck.Data.Status);
}

void WorldSession::HandleMoveApplyMovementForceAck(WorldPackets::Movement::MoveApplyMovementForceAck& moveApplyMovementForceAck)
{
    Unit* mover = _player->m_unitMovedByMe;
    ASSERT(mover != nullptr);
    _player->ValidateMovementInfo(&moveApplyMovementForceAck.Ack.Status);

    // prevent tampered movement data
    if (moveApplyMovementForceAck.Ack.Status.guid != mover->GetGUID())
    {
        TC_LOG_ERROR("network", "HandleMoveApplyMovementForceAck: guid error, expected %s, got %s",
            mover->GetGUID().ToString().c_str(), moveApplyMovementForceAck.Ack.Status.guid.ToString().c_str());
        return;
    }

    moveApplyMovementForceAck.Ack.Status.time += m_clientTimeDelay + MOVEMENT_PACKET_TIME_DELAY;

    WorldPackets::Movement::MoveUpdateApplyMovementForce updateApplyMovementForce;
    updateApplyMovementForce.Status = &moveApplyMovementForceAck.Ack.Status;
    updateApplyMovementForce.Force = &moveApplyMovementForceAck.Force;
    mover->SendMessageToSet(updateApplyMovementForce.Write(), false);
}

void WorldSession::HandleMoveRemoveMovementForceAck(WorldPackets::Movement::MoveRemoveMovementForceAck& moveRemoveMovementForceAck)
{
    Unit* mover = _player->m_unitMovedByMe;
    ASSERT(mover != nullptr);
    _player->ValidateMovementInfo(&moveRemoveMovementForceAck.Ack.Status);

    // prevent tampered movement data
    if (moveRemoveMovementForceAck.Ack.Status.guid != mover->GetGUID())
    {
        TC_LOG_ERROR("network", "HandleMoveRemoveMovementForceAck: guid error, expected %s, got %s",
            mover->GetGUID().ToString().c_str(), moveRemoveMovementForceAck.Ack.Status.guid.ToString().c_str());
        return;
    }

    moveRemoveMovementForceAck.Ack.Status.time += m_clientTimeDelay + MOVEMENT_PACKET_TIME_DELAY;

    WorldPackets::Movement::MoveUpdateRemoveMovementForce updateRemoveMovementForce;
    updateRemoveMovementForce.Status = &moveRemoveMovementForceAck.Ack.Status;
    updateRemoveMovementForce.TriggerGUID = moveRemoveMovementForceAck.ID;
    mover->SendMessageToSet(updateRemoveMovementForce.Write(), false);
}

void WorldSession::HandleMoveSetModMovementForceMagnitudeAck(WorldPackets::Movement::MovementSpeedAck& setModMovementForceMagnitudeAck)
{
    Unit* mover = _player->m_unitMovedByMe;
    ASSERT(mover != nullptr);                      // there must always be a mover
    _player->ValidateMovementInfo(&setModMovementForceMagnitudeAck.Ack.Status);

    // prevent tampered movement data
    if (setModMovementForceMagnitudeAck.Ack.Status.guid != mover->GetGUID())
    {
        TC_LOG_ERROR("network", "HandleSetModMovementForceMagnitudeAck: guid error, expected %s, got %s",
            mover->GetGUID().ToString().c_str(), setModMovementForceMagnitudeAck.Ack.Status.guid.ToString().c_str());
        return;
    }

    // skip all except last
    if (_player->m_movementForceModMagnitudeChanges > 0)
    {
        --_player->m_movementForceModMagnitudeChanges;
        if (!_player->m_movementForceModMagnitudeChanges)
        {
            float expectedModMagnitude = 1.0f;
            if (MovementForces const* movementForces = mover->GetMovementForces())
                expectedModMagnitude = movementForces->GetModMagnitude();

            if (std::fabs(expectedModMagnitude - setModMovementForceMagnitudeAck.Speed) > 0.01f)
            {
                TC_LOG_DEBUG("misc", "Player %s from account id %u kicked for incorrect movement force magnitude (must be %f instead %f)",
                    _player->GetName().c_str(), _player->GetSession()->GetAccountId(), expectedModMagnitude, setModMovementForceMagnitudeAck.Speed);
                _player->GetSession()->KickPlayer();
                return;
            }
        }
    }

    setModMovementForceMagnitudeAck.Ack.Status.time += m_clientTimeDelay + MOVEMENT_PACKET_TIME_DELAY;

    WorldPackets::Movement::MoveUpdateSpeed updateModMovementForceMagnitude(SMSG_MOVE_UPDATE_MOD_MOVEMENT_FORCE_MAGNITUDE);
    updateModMovementForceMagnitude.Status = &setModMovementForceMagnitudeAck.Ack.Status;
    updateModMovementForceMagnitude.Speed = setModMovementForceMagnitudeAck.Speed;
    mover->SendMessageToSet(updateModMovementForceMagnitude.Write(), false);
}

void WorldSession::HandleMoveTimeSkippedOpcode(WorldPackets::Movement::MoveTimeSkipped& /*moveTimeSkipped*/)
{
}

void WorldSession::HandleMoveSplineDoneOpcode(WorldPackets::Movement::MoveSplineDone& moveSplineDone)
{
    MovementInfo movementInfo = moveSplineDone.Status;
    _player->ValidateMovementInfo(&movementInfo);

    // in taxi flight packet received in 2 case:
    // 1) end taxi path in far (multi-node) flight
    // 2) switch from one map to other in case multim-map taxi path
    // we need process only (1)

    uint32 curDest = GetPlayer()->m_taxi.GetTaxiDestination();
    if (curDest)
    {
        TaxiNodesEntry const* curDestNode = sTaxiNodesStore.LookupEntry(curDest);

        // far teleport case
        if (curDestNode && curDestNode->ContinentID != GetPlayer()->GetMapId() && GetPlayer()->GetMotionMaster()->GetCurrentMovementGeneratorType() == FLIGHT_MOTION_TYPE)
        {
            if (FlightPathMovementGenerator* flight = dynamic_cast<FlightPathMovementGenerator*>(GetPlayer()->GetMotionMaster()->GetCurrentMovementGenerator()))
            {
                // short preparations to continue flight
                flight->SetCurrentNodeAfterTeleport();
                TaxiPathNodeEntry const* node = flight->GetPath()[flight->GetCurrentNode()];
                flight->SkipCurrentNode();

                GetPlayer()->TeleportTo(curDestNode->ContinentID, node->Loc.X, node->Loc.Y, node->Loc.Z, GetPlayer()->GetOrientation());
            }
        }

        return;
    }

    // at this point only 1 node is expected (final destination)
    if (GetPlayer()->m_taxi.GetPath().size() != 1)
        return;

    GetPlayer()->CleanupAfterTaxiFlight();
    GetPlayer()->SetFallInformation(0, GetPlayer()->GetPositionZ());
    if (GetPlayer()->pvpInfo.IsHostile)
        GetPlayer()->CastSpell(GetPlayer(), 2479, true);
}
