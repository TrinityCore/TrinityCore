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

#include "Common.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "Opcodes.h"
#include "Log.h"
#include "Corpse.h"
#include "Language.h"
#include "Player.h"
#include "MapManager.h"
#include "MotionMaster.h"
#include "MovementGenerator.h"
#include "Transport.h"
#include "Battleground.h"
#include "InstanceSaveMgr.h"
#include "ObjectMgr.h"
#include "Vehicle.h"
#include "GameTime.h"
#include "MovementPacketSender.h"
#include "RBAC.h"

void WorldSession::HandleMoveWorldportAckOpcode(WorldPacket & /*recvData*/)
{
    TC_LOG_DEBUG("network", "WORLD: got MSG_MOVE_WORLDPORT_ACK.");
    HandleMoveWorldportAck();
}

void WorldSession::HandleMoveWorldportAck()
{
    Player* player = GetPlayer();
    // ignore unexpected far teleports
    if (!player->IsBeingTeleportedFar())
        return;

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
        TC_LOG_ERROR("network", "Map %d (%s) could not be created for player %d (%s), porting player to homebind", loc.GetMapId(), newMap ? newMap->GetMapName() : "Unknown", player->GetGUID().GetCounter(), player->GetName().c_str());
        player->TeleportTo(player->m_homebindMapId, player->m_homebindX, player->m_homebindY, player->m_homebindZ, player->GetOrientation());
        return;
    }

    float z = loc.GetPositionZ() + player->GetHoverOffset();
    player->Relocate(loc.GetPositionX(), loc.GetPositionY(), z, loc.GetOrientation());
    player->SetFallInformation(0, player->GetPositionZ());

    player->ResetMap();
    player->SetMap(newMap);

    player->SendInitialPacketsBeforeAddToMap();
    if (!player->GetMap()->AddPlayerToMap(player))
    {
        TC_LOG_ERROR("network", "WORLD: failed to teleport player %s (%d) to map %d (%s) because of unknown reason!",
            player->GetName().c_str(), player->GetGUID().GetCounter(), loc.GetMapId(), newMap ? newMap->GetMapName() : "Unknown");
        player->ResetMap();
        player->SetMap(oldMap);
        player->TeleportTo(player->m_homebindMapId, player->m_homebindX, player->m_homebindY, player->m_homebindZ, player->GetOrientation());
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

    player->SendInitialPacketsAfterAddToMap();

    // flight fast teleport case
    if (player->IsInFlight())
    {
        if (!player->InBattleground())
        {
            // short preparations to continue flight
            MovementGenerator* movementGenerator = player->GetMotionMaster()->GetCurrentMovementGenerator();
            movementGenerator->Initialize(player);
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
        if (player->GetCorpseLocation().GetMapId() == mEntry->MapID)
        {
            player->ResurrectPlayer(0.5f);
            player->SpawnCorpseBones();
        }
    }

    bool allowMount = !mEntry->IsDungeon() || mEntry->IsBattlegroundOrArena();
    if (mInstance)
    {
        // check if this instance has a reset time and send it to player if so
        Difficulty diff = player->GetDifficulty(mEntry->IsRaid());
        if (MapDifficulty const* mapDiff = GetMapDifficultyData(mEntry->MapID, diff))
        {
            if (mapDiff->resetTime)
            {
                if (time_t timeReset = sInstanceSaveMgr->GetResetTimeFor(mEntry->MapID, diff))
                {
                    uint32 timeleft = uint32(timeReset - GameTime::GetGameTime());
                    player->SendInstanceResetWarning(mEntry->MapID, diff, timeleft, true);
                }
            }
        }

        // check if instance is valid
        if (!player->CheckInstanceValidity(false))
            player->m_InstanceValid = false;

        // instance mounting is handled in InstanceTemplate
        allowMount = mInstance->AllowMount;
    }

    // mount allow check
    if (!allowMount)
        player->RemoveAurasByType(SPELL_AURA_MOUNTED);

    // update zone immediately, otherwise leave channel will cause crash in mtmap
    uint32 newzone, newarea;
    player->GetZoneAndAreaId(newzone, newarea);
    player->UpdateZone(newzone, newarea);

    // honorless target
    if (player->pvpInfo.IsHostile)
        player->CastSpell(player, 2479, true);

    // in friendly area
    else if (player->IsPvP() && !player->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_IN_PVP))
        player->UpdatePvP(false, false);

    // resummon pet
    player->ResummonPetTemporaryUnSummonedIfAny();

    //lets process all delayed operations on successful teleport
    player->ProcessDelayedOperations();
}

void WorldSession::HandleMoveTeleportAck(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "MSG_MOVE_TELEPORT_ACK");
    /* extract packet */
    ObjectGuid guid;
    recvData >> guid.ReadAsPacked();

    // make sure this client is allowed to control the unit which guid is provided
    if (!_player->IsInClientControlSet(guid))
    {
        recvData.rfinish();                   // prevent warnings spam
        TC_LOG_ERROR("entities.unit", "WorldSession::HandleMoveTeleportAck: The client doesn't have the permission to move this unit!");
        return;
    }

    Unit* mover = ObjectAccessor::GetUnit(*_player, guid);

    uint32 movementCounter, time;
    recvData >> movementCounter >> time;

    // verify that indeed the client is replying with the changes that were send to him
    if (!mover->HasPendingMovementChange())
    {
        TC_LOG_INFO("cheat", "WorldSession::HandleMoveTeleportAck: Player %s from account id %u kicked because no movement change ack was expected from this player",
            _player->GetName().c_str(), _player->GetSession()->GetAccountId());
        _player->GetSession()->KickPlayer();
        return;
    }

    PlayerMovementPendingChange pendingChange = mover->PopPendingMovementChange();
    if (pendingChange.movementCounter != movementCounter || pendingChange.movementChangeType != TELEPORT)
    {
        TC_LOG_INFO("cheat", "WorldSession::HandleMoveTeleportAck: Player %s from account id %u kicked for incorrect data returned in an ack",
            _player->GetName().c_str(), _player->GetSession()->GetAccountId());
        _player->GetSession()->KickPlayer();
        return;
    }

    Player* plMover = _player->m_unitMovedByMe->ToPlayer();

    if (!plMover || !plMover->IsBeingTeleportedNear())
        return;

    plMover->SetSemaphoreTeleportNear(false);

    WorldLocation const& dest = plMover->GetTeleportDest();
    // now that it has been acknowledge, we can inform the observers of that teleport
    MovementInfo movementInfo = plMover->GetMovementInfo();
    movementInfo.pos.Relocate(dest);
    if (TransportBase* transportBase = plMover->GetDirectTransport())
    {
        float x, y, z, o;
        dest.GetPosition(x, y, z, o);
        transportBase->CalculatePassengerOffset(x, y, z, &o);
        movementInfo.transport.pos.Relocate(x, y, z, o);
    }
    MovementPacketSender::SendTeleportPacket(plMover, movementInfo);

    uint32 old_zone = plMover->GetZoneId();

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
        else if (plMover->IsPvP() && !plMover->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_IN_PVP))
            plMover->UpdatePvP(false, false);
    }

    // resummon pet
    GetPlayer()->ResummonPetTemporaryUnSummonedIfAny();

    //lets process all delayed operations on successful teleport
    GetPlayer()->ProcessDelayedOperations();
}

/*
These packets are sent by the client in order to transmit the movement of the character currently controlled by the client.
This character is usually the player but it can be a creature (in case of a possess (eg priest MC)) or a vehicle. Later in this handler explaination,
'player' will be used when 'player controlled unit' should have been used.
The server then retransmits these packets to the other clients, which will extrapolate the unit's motion.
All the server has to do with all these packets is:
1) validate & update the data received: position, orientation, fall data and movement flags (this list should be exhaustive. please update if there is something missing).
2) transmit this packet to the other players nearby

Handles:

MSG_MOVE_START_FORWARD
MSG_MOVE_START_BACKWARD
MSG_MOVE_STOP
MSG_MOVE_START_STRAFE_LEFT
MSG_MOVE_START_STRAFE_RIGHT
MSG_MOVE_STOP_STRAFE
MSG_MOVE_JUMP
MSG_MOVE_START_TURN_LEFT
MSG_MOVE_START_TURN_RIGHT
MSG_MOVE_STOP_TURN
MSG_MOVE_START_PITCH_UP
MSG_MOVE_START_PITCH_DOWN
MSG_MOVE_STOP_PITCH
MSG_MOVE_SET_RUN_MODE
MSG_MOVE_SET_WALK_MODE
MSG_MOVE_FALL_LAND
MSG_MOVE_START_SWIM
MSG_MOVE_STOP_SWIM
MSG_MOVE_SET_FACING
MSG_MOVE_SET_PITCH
MSG_MOVE_HEARTBEAT -- packet sent every 0.5 s when the player is moving. 
MSG_MOVE_START_ASCEND
MSG_MOVE_STOP_ASCEND
MSG_MOVE_START_DESCEND

CMSG_MOVE_FALL_RESET -- the player has encounter an object while failing, thus modifing the trajectory of his fall. this packet gives info regarding the new trajectory. !!!! @todo: needs to be processed in a different handler and this opcode shouldn'nt be sent to other clients !!!!
CMSG_MOVE_SET_FLY -- the player has started or stopped to fly (toggle effect). !!!! @todo: needs to be processed in a different handler and this opcode shouldn'nt be sent to other clients !!!!
CMSG_MOVE_CHNG_TRANSPORT !!!! @todo: needs to be processed in a different handler and this opcode shouldn'nt be sent to other clients !!!!
*/
void WorldSession::HandleMovementOpcodes(WorldPacket& recvData)
{
    uint16 opcode = recvData.GetOpcode();

    /* extract packet */
    MovementInfo movementInfo;
    movementInfo.FillContentFromPacket(&recvData, true);
    recvData.rfinish();                         // prevent warnings spam

    // make sure this client is allowed to control the unit which guid is provided
    if (!_player->IsInClientControlSet(movementInfo.guid))
    {
        recvData.rfinish();                   // prevent warnings spam
        TC_LOG_ERROR("entities.unit", "WorldSession::HandleMovementOpcodes: The client doesn't have the permission to move this unit!");
        return;
    }

    Unit* mover = ObjectAccessor::GetUnit(*_player, movementInfo.guid);
    Player* plrMover = mover->ToPlayer();

    // ignore movement packets if the player is getting far teleported (change of map). keep processing movement packets when the unit is only doing a near teleport.
    if (plrMover && plrMover->IsBeingTeleportedFar())
    {
        recvData.rfinish();                     // prevent warnings spam
        return;
    }

    if (!movementInfo.pos.IsPositionValid())
        return;

    /* validate new movement packet */
    mover->ValidateMovementInfo(&movementInfo);

    /* handle special cases */
    if (movementInfo.HasMovementFlag(MOVEMENTFLAG_ONTRANSPORT)) // @todo: move this stuff. CMSG_MOVE_CHNG_TRANSPORT should be handled elsewhere than here.
    {
        // We were teleported, skip packets that were broadcast before teleport
        if (movementInfo.pos.GetExactDist2d(mover) > SIZE_OF_GRIDS)
        {
            recvData.rfinish();                 // prevent warnings spam
            return;
        }

        // transports size limited
        // (also received at zeppelin leave by some reason with t_* as absolute in continent coordinates, can be safely skipped)
        if (fabs(movementInfo.transport.pos.GetPositionX()) > 75.0f || fabs(movementInfo.transport.pos.GetPositionY()) > 75.0f || fabs(movementInfo.transport.pos.GetPositionZ()) > 75.0f)
        {
            recvData.rfinish();                 // prevent warnings spam
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
                if (Transport* transport = plrMover->GetMap()->GetTransport(movementInfo.transport.guid))
                    transport->AddPassenger(plrMover);
            }
            else if (plrMover->GetTransport()->GetGUID() != movementInfo.transport.guid)
            {
                plrMover->GetTransport()->RemovePassenger(plrMover);
                if (Transport* transport = plrMover->GetMap()->GetTransport(movementInfo.transport.guid))
                    transport->AddPassenger(plrMover);
                else
                    movementInfo.transport.Reset();
            }
        }

        if (!mover->GetTransport() && !mover->GetVehicle())
        {
            GameObject* go = mover->GetMap()->GetGameObject(movementInfo.transport.guid);
            if (!go || go->GetGoType() != GAMEOBJECT_TYPE_TRANSPORT)
                movementInfo.RemoveMovementFlag(MOVEMENTFLAG_ONTRANSPORT);
        }
    }
    else if (plrMover && plrMover->GetTransport())                // if we were on a transport, leave
    {
        plrMover->GetTransport()->RemovePassenger(plrMover);
        movementInfo.transport.Reset();
    }

    // fall damage generation (ignore in flight case that can be triggered also at lags in moment teleportation to another map).
    if (opcode == MSG_MOVE_FALL_LAND && plrMover && !plrMover->IsInFlight())
        plrMover->HandleFall(movementInfo);

    // interrupt parachutes upon falling or landing in water
    if (opcode == MSG_MOVE_FALL_LAND || opcode == MSG_MOVE_START_SWIM)
        mover->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_LANDING); // Parachutes

    if (plrMover && ((movementInfo.flags & MOVEMENTFLAG_SWIMMING) != 0) != plrMover->IsInWater())
    {
        // now client not include swimming flag in case jumping under water
        plrMover->SetInWater(!plrMover->IsInWater() || plrMover->GetBaseMap()->IsUnderWater(movementInfo.pos.GetPositionX(), movementInfo.pos.GetPositionY(), movementInfo.pos.GetPositionZ()));
    }

    /* process position-change */
    mover->UpdateMovementInfo(movementInfo);

    // as strange as it may be, retail servers actually use MSG_MOVE_START_SWIM_CHEAT & MSG_MOVE_STOP_SWIM_CHEAT to respectively set and unset the 'Flying' movement flag. 
    // The only thing left to do is to move the handling of CMSG_MOVE_SET_FLY into a different handler
    if (opcode == CMSG_MOVE_SET_FLY)
        opcode = movementInfo.HasMovementFlag(MOVEMENTFLAG_FLYING) ? MSG_MOVE_START_SWIM_CHEAT : MSG_MOVE_STOP_SWIM_CHEAT;

    WorldPacket data(opcode, recvData.size());
    mover->GetMovementInfo().WriteContentIntoPacket(&data, true);
    mover->SendMessageToSet(&data, _player);

    // Some vehicles allow the passenger to turn by himself
    if (Vehicle* vehicle = mover->GetVehicle())
    {
        if (VehicleSeatEntry const* seat = vehicle->GetSeatForPassenger(mover))
        {
            if (seat->m_flags & VEHICLE_SEAT_FLAG_ALLOW_TURNING)
            {
                if (movementInfo.pos.GetOrientation() != mover->GetOrientation())
                {
                    mover->SetOrientation(movementInfo.pos.GetOrientation());
                    mover->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_TURNING);
                }
            }
        }
        return;
    }

    mover->UpdatePosition(movementInfo.pos); // unsure if this can be safely deleted since it is also called in "mover->UpdateMovementInfo(movementInfo)" but the above if blocks may influence the unit's orintation

    if (plrMover)                                            // nothing is charmed, or player charmed
    {
        if (plrMover->IsSitState() && (movementInfo.flags & (MOVEMENTFLAG_MASK_MOVING | MOVEMENTFLAG_MASK_TURNING)))
            plrMover->SetStandState(UNIT_STAND_STATE_STAND);

        plrMover->UpdateFallInformationIfNeed(movementInfo, opcode);

        if (movementInfo.pos.GetPositionZ() < plrMover->GetMap()->GetMinHeight(movementInfo.pos.GetPositionX(), movementInfo.pos.GetPositionY()))
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
    }
}

void WorldSession::HandleForceSpeedChangeAck(WorldPacket &recvData)
{
    /* extract packet */
    ObjectGuid guid;
    recvData >> guid.ReadAsPacked();

    // make sure this client is allowed to control the unit which guid is provided
    if(!_player->IsInClientControlSet(guid))
    {
        recvData.rfinish();                   // prevent warnings spam
        TC_LOG_ERROR("entities.unit", "WorldSession::HandleForceSpeedChangeAck: The client doesn't have the permission to move this unit!");
        return;
    }

    Unit* mover = ObjectAccessor::GetUnit(*_player, guid);

    UnitMoveType move_type;
    switch (recvData.GetOpcode())
    {
        case CMSG_FORCE_WALK_SPEED_CHANGE_ACK:          move_type = MOVE_WALK;          break;
        case CMSG_FORCE_RUN_SPEED_CHANGE_ACK:           move_type = MOVE_RUN;           break;
        case CMSG_FORCE_RUN_BACK_SPEED_CHANGE_ACK:      move_type = MOVE_RUN_BACK;      break;
        case CMSG_FORCE_SWIM_SPEED_CHANGE_ACK:          move_type = MOVE_SWIM;          break;
        case CMSG_FORCE_SWIM_BACK_SPEED_CHANGE_ACK:     move_type = MOVE_SWIM_BACK;     break;
        case CMSG_FORCE_TURN_RATE_CHANGE_ACK:           move_type = MOVE_TURN_RATE;     break;
        case CMSG_FORCE_FLIGHT_SPEED_CHANGE_ACK:        move_type = MOVE_FLIGHT;        break;
        case CMSG_FORCE_FLIGHT_BACK_SPEED_CHANGE_ACK:   move_type = MOVE_FLIGHT_BACK;   break;
        case CMSG_FORCE_PITCH_RATE_CHANGE_ACK:          move_type = MOVE_PITCH_RATE;    break;
        default:
            TC_LOG_ERROR("network", "WorldSession::HandleForceSpeedChangeAck: Unknown move type opcode: %s", GetOpcodeNameForLogging(static_cast<OpcodeClient>(recvData.GetOpcode())).c_str());
            return;
    }

    uint32 movementCounter;
    float  speedReceived;
    MovementInfo movementInfo;
    movementInfo.guid = guid;

    recvData >> movementCounter;
    movementInfo.FillContentFromPacket(&recvData);
    recvData >> speedReceived;

    // verify that indeed the client is replying with the changes that were send to him
    if (!mover->HasPendingMovementChange())
    {
        TC_LOG_INFO("cheat", "WorldSession::HandleForceSpeedChangeAck: Player %s from account id %u kicked because no movement change ack was expected from this player",
            _player->GetName().c_str(), _player->GetSession()->GetAccountId());
        _player->GetSession()->KickPlayer();
        return;
    }

    PlayerMovementPendingChange pendingChange = mover->PopPendingMovementChange();
    float speedSent = pendingChange.newValue;
    MovementChangeType changeType = pendingChange.movementChangeType;
    UnitMoveType moveTypeSent;
    switch (changeType)
    {
        case SPEED_CHANGE_WALK:                 moveTypeSent = MOVE_WALK; break;
        case SPEED_CHANGE_RUN:                  moveTypeSent = MOVE_RUN; break;
        case SPEED_CHANGE_RUN_BACK:             moveTypeSent = MOVE_RUN_BACK; break;
        case SPEED_CHANGE_SWIM:                 moveTypeSent = MOVE_SWIM; break;
        case SPEED_CHANGE_SWIM_BACK:            moveTypeSent = MOVE_SWIM_BACK; break;
        case RATE_CHANGE_TURN:                  moveTypeSent = MOVE_TURN_RATE; break;
        case SPEED_CHANGE_FLIGHT_SPEED:         moveTypeSent = MOVE_FLIGHT; break;
        case SPEED_CHANGE_FLIGHT_BACK_SPEED:    moveTypeSent = MOVE_FLIGHT_BACK; break;
        case RATE_CHANGE_PITCH:                 moveTypeSent = MOVE_PITCH_RATE; break;
        default:
            TC_LOG_INFO("cheat", "WorldSession::HandleForceSpeedChangeAck: Player %s from account id %u kicked for incorrect data returned in an ack",
                _player->GetName().c_str(), _player->GetSession()->GetAccountId());
            _player->GetSession()->KickPlayer();
            return;
    }

    if (pendingChange.movementCounter != movementCounter || std::fabs(speedSent - speedReceived) > 0.01f || moveTypeSent!= move_type)
    {
        TC_LOG_INFO("cheat", "WorldSession::HandleForceSpeedChangeAck: Player %s from account id %u kicked for incorrect data returned in an ack",
            _player->GetName().c_str(), _player->GetSession()->GetAccountId());
        _player->GetSession()->KickPlayer();
        return;
    }

    /* the client data has been verified. let's do the actual change now */
    float newSpeedRate = speedSent / (mover->IsControlledByPlayer() ? playerBaseMoveSpeed[move_type] : baseMoveSpeed[move_type]); // is it sure that IsControlledByPlayer() should be used?
    mover->UpdateMovementInfo(movementInfo);
    mover->SetSpeedRateReal(move_type, newSpeedRate);
    MovementPacketSender::SendSpeedChangeToObservers(mover, move_type, speedSent);
}

void WorldSession::HandleCollisionHeightChangeAck(WorldPacket &recvData)
{
    /* extract packet */
    ObjectGuid guid;
    uint32 movementCounter;
    MovementInfo movementInfo;
    float  heightReceived;

    recvData >> guid.ReadAsPacked();
    movementInfo.guid = guid;
    recvData >> movementCounter;
    movementInfo.FillContentFromPacket(&recvData, false);
    recvData >> heightReceived;

    // make sure this client is allowed to control the unit which guid is provided
    if (!_player->IsInClientControlSet(guid))
    {
        recvData.rfinish();                   // prevent warnings spam
        TC_LOG_ERROR("entities.unit", "WorldSession::HandleCollisionHeightChangeAck: The client doesn't have the permission to move this unit!");
        return;
    }

    Unit* mover = ObjectAccessor::GetUnit(*_player, guid);

    // verify that indeed the client is replying with the changes that were send to him
    if (!mover->HasPendingMovementChange())
    {
        TC_LOG_INFO("cheat", "WorldSession::HandleCollisionHeightChangeAck: Player %s from account id %u kicked because no movement change ack was expected from this player",
            _player->GetName().c_str(), _player->GetSession()->GetAccountId());
        _player->GetSession()->KickPlayer();
        return;
    }

    PlayerMovementPendingChange pendingChange = mover->PopPendingMovementChange();
    float heightSent = pendingChange.newValue;
    MovementChangeType changeType = pendingChange.movementChangeType;

    if (pendingChange.movementCounter != movementCounter || changeType != SET_COLLISION_HGT || std::fabs(heightSent - heightReceived) > 0.01f)
    {
        TC_LOG_INFO("cheat", "WorldSession::HandleCollisionHeightChangeAck: Player %s from account id %u kicked for incorrect data returned in an ack",
            _player->GetName().c_str(), _player->GetSession()->GetAccountId());
        _player->GetSession()->KickPlayer();
        return;
    }

    mover->ValidateMovementInfo(&movementInfo);
    /* the client data has been verified. let's do the actual change now */
    mover->UpdateMovementInfo(movementInfo);
    mover->SetCollisionHeightReal(heightSent);
    MovementPacketSender::SendHeightChangeToObservers(mover, heightSent);
}

void WorldSession::HandleSetActiveMoverOpcode(WorldPacket &recvData)
{
    TC_LOG_DEBUG("network", "WORLD: Recvd CMSG_SET_ACTIVE_MOVER");

    ObjectGuid guid;
    recvData >> guid;

    _player->InsertIntoClientControlSet(guid);
    _player->m_pendingNewAllowedMover = false;
}

void WorldSession::HandleMoveNotActiveMover(WorldPacket &recvData)
{
    TC_LOG_DEBUG("network", "WORLD: Recvd CMSG_MOVE_NOT_ACTIVE_MOVER");

    MovementInfo movementInfo;
    movementInfo.FillContentFromPacket(&recvData, true);

    // make sure this client is allowed to control the unit which guid is provided
    if (!_player->IsInClientControlSet(movementInfo.guid))
    {
        recvData.rfinish();                   // prevent warnings spam
        TC_LOG_ERROR("entities.unit", "WorldSession::HandleMoveNotActiveMover: The client doesn't have the permission to move this unit!");
        return;
    }

    Unit* mover = ObjectAccessor::GetUnit(*_player, movementInfo.guid);

    mover->ValidateMovementInfo(&movementInfo);
    mover->UpdateMovementInfo(movementInfo);

    if (!_player->m_pendingNewAllowedMover)
        _player->RemoveFromClientControlSet(movementInfo.guid);

    _player->m_pendingNewAllowedMover = false;
}

void WorldSession::HandleMountSpecialAnimOpcode(WorldPacket& /*recvData*/)
{
    WorldPacket data(SMSG_MOUNTSPECIAL_ANIM, 8);
    data << uint64(GetPlayer()->GetGUID());

    GetPlayer()->SendMessageToSet(&data, false);
}

void WorldSession::HandleMoveKnockBackAck(WorldPacket& recvData)
{
    /* extract packet */
    ObjectGuid guid;
    uint32 movementCounter;
    MovementInfo movementInfo;

    recvData >> guid.ReadAsPacked();
    movementInfo.guid = guid;
    recvData >> movementCounter;
    movementInfo.FillContentFromPacket(&recvData, false);

    // make sure this client is allowed to control the unit which guid is provided
    if (!_player->IsInClientControlSet(guid))
    {
        recvData.rfinish();                   // prevent warnings spam
        TC_LOG_ERROR("entities.unit", "WorldSession::HandleMoveKnockBackAck: The client doesn't have the permission to move this unit!");
        return;
    }

    Unit* mover = ObjectAccessor::GetUnit(*_player, guid);

    // verify that indeed the client is replying with the changes that were send to him
    if (!mover->HasPendingMovementChange())
    {
        TC_LOG_INFO("cheat", "WorldSession::HandleMoveKnockBackAck: Player %s from account id %u kicked because no movement change ack was expected from this player",
            _player->GetName().c_str(), _player->GetSession()->GetAccountId());
        _player->GetSession()->KickPlayer();
        return;
    }

    PlayerMovementPendingChange pendingChange = mover->PopPendingMovementChange();
    if (pendingChange.movementCounter != movementCounter || pendingChange.movementChangeType != KNOCK_BACK
        || std::fabs(pendingChange.knockbackInfo.speedXY - movementInfo.jump.xyspeed) > 0.01f
        || std::fabs(pendingChange.knockbackInfo.speedZ - movementInfo.jump.zspeed) > 0.01f
        || std::fabs(pendingChange.knockbackInfo.vcos - movementInfo.jump.cosAngle) > 0.01f
        || std::fabs(pendingChange.knockbackInfo.vsin - movementInfo.jump.sinAngle) > 0.01f)
    {
        TC_LOG_INFO("cheat", "WorldSession::HandleMoveKnockBackAck: Player %s from account id %u kicked for incorrect data returned in an ack",
            _player->GetName().c_str(), _player->GetSession()->GetAccountId());
        _player->GetSession()->KickPlayer();
        return;
    }

    // knocking a player removes the CanFly flag (the client reacts the same way).
    mover->SetCanFlyReal(false);

    mover->ValidateMovementInfo(&movementInfo);
    /* the client data has been verified. let's do the actual change now */
    mover->UpdateMovementInfo(movementInfo);
    MovementPacketSender::SendKnockBackToObservers(mover, movementInfo.jump.cosAngle, movementInfo.jump.sinAngle, movementInfo.jump.xyspeed, movementInfo.jump.zspeed);
}

/*
handles those packets:

APPLY:

CMSG_FORCE_MOVE_ROOT_ACK
CMSG_MOVE_GRAVITY_DISABLE_ACK

UNAPPLY:

CMSG_FORCE_MOVE_UNROOT_ACK
CMSG_MOVE_GRAVITY_ENABLE_ACK
*/
void WorldSession::HandleMovementFlagChangeAck(WorldPacket& recvData)
{
    /* extract packet */
    ObjectGuid guid;
    uint32 movementCounter;
    MovementInfo movementInfo;

    recvData >> guid.ReadAsPacked();
    movementInfo.guid = guid;
    recvData >> movementCounter;
    movementInfo.FillContentFromPacket(&recvData);

    // make sure this client is allowed to control the unit which guid is provided
    if (!_player->IsInClientControlSet(guid))
    {
        recvData.rfinish();                   // prevent warnings spam
        TC_LOG_ERROR("entities.unit", "WorldSession::HandleMovementFlagChangeAck: The client doesn't have the permission to move this unit!");
        return;
    }

    Unit* mover = ObjectAccessor::GetUnit(*_player, guid);

    // verify that indeed the client is replying with the changes that were send to him
    if (!mover->HasPendingMovementChange())
    {
        TC_LOG_INFO("cheat", "WorldSession::HandleMovementFlagChangeAck: Player %s from account id %u kicked because no movement change ack was expected from this player",
            _player->GetName().c_str(), _player->GetSession()->GetAccountId());
        _player->GetSession()->KickPlayer();
        return;
    }

    PlayerMovementPendingChange pendingChange = mover->PopPendingMovementChange();
    bool applySent = pendingChange.apply;
    MovementChangeType changeTypeSent = pendingChange.movementChangeType;

    MovementFlags mFlag;
    MovementChangeType changeTypeReceived;
    bool applyReceived;
    switch (recvData.GetOpcode())
    {
        case CMSG_FORCE_MOVE_ROOT_ACK:      changeTypeReceived = ROOT; applyReceived = true; mFlag = MOVEMENTFLAG_ROOT; break;
        case CMSG_FORCE_MOVE_UNROOT_ACK:    changeTypeReceived = ROOT; applyReceived = false; mFlag = MOVEMENTFLAG_ROOT; break;

        case CMSG_MOVE_GRAVITY_DISABLE_ACK: changeTypeReceived = GRAVITY_DISABLE; applyReceived = true; mFlag = MOVEMENTFLAG_DISABLE_GRAVITY; break;
        case CMSG_MOVE_GRAVITY_ENABLE_ACK:  changeTypeReceived = GRAVITY_DISABLE; applyReceived = false; mFlag = MOVEMENTFLAG_DISABLE_GRAVITY; break;
        default:
            TC_LOG_ERROR("network", "WorldSession::HandleMovementFlagChangeAck: Unknown move type opcode: %s", GetOpcodeNameForLogging(static_cast<OpcodeClient>(recvData.GetOpcode())).c_str());
            return;
    }

    if (pendingChange.movementCounter != movementCounter 
        || applySent != applyReceived
        || changeTypeSent != changeTypeReceived)
    {
        TC_LOG_INFO("cheat", "WorldSession::HandleMovementFlagChangeAck: Player %s from account id %u kicked for incorrect data returned in an ack",
            _player->GetName().c_str(), _player->GetSession()->GetAccountId());
        _player->GetSession()->KickPlayer();
        return;
    }

    switch (changeTypeReceived)
    {
        case ROOT: mover->SetRootedReal(applyReceived); break;
        case GRAVITY_DISABLE: mover->SetDisableGravityReal(applyReceived); break;
        default:
            TC_LOG_ERROR("network", "WorldSession::HandleMovementFlagChangeAck: Unknown move type opcode: %s", GetOpcodeNameForLogging(static_cast<OpcodeClient>(recvData.GetOpcode())).c_str());
            return;
    }

    mover->ValidateMovementInfo(&movementInfo);
    mover->UpdateMovementInfo(movementInfo);
    MovementPacketSender::SendMovementFlagChangeToObservers(mover, mFlag, applySent);
}

/*
handles those packets:

CMSG_MOVE_WATER_WALK_ACK
CMSG_MOVE_HOVER_ACK
CMSG_MOVE_SET_CAN_FLY_ACK
CMSG_MOVE_SET_CAN_TRANSITION_BETWEEN_SWIM_AND_FLY_ACK
CMSG_MOVE_FEATHER_FALL_ACK
*/
void WorldSession::HandleMovementFlagChangeToggleAck(WorldPacket& recvData)
{
    /* extract packet */
    ObjectGuid guid;
    uint32 movementCounter;
    MovementInfo movementInfo;
    uint32 applyInt;
    bool applyReceived;

    recvData >> guid.ReadAsPacked();
    movementInfo.guid = guid;
    recvData >> movementCounter;
    movementInfo.FillContentFromPacket(&recvData);
    recvData >> applyInt;
    applyReceived = applyInt == 0u ? false : true;

    // make sure this client is allowed to control the unit which guid is provided
    if (!_player->IsInClientControlSet(guid))
    {
        recvData.rfinish();                   // prevent warnings spam
        TC_LOG_ERROR("entities.unit", "WorldSession::HandleMovementFlagChangeToggleAck: The client doesn't have the permission to move this unit!");
        return;
    }

    Unit* mover = ObjectAccessor::GetUnit(*_player, guid);

    // verify that indeed the client is replying with the changes that were send to him
    if (!mover->HasPendingMovementChange())
    {
        TC_LOG_INFO("cheat", "WorldSession::HandleMovementFlagChangeToggleAck: Player %s from account id %u kicked because no movement change ack was expected from this player",
            _player->GetName().c_str(), _player->GetSession()->GetAccountId());
        _player->GetSession()->KickPlayer();
        return;
    }

    PlayerMovementPendingChange pendingChange = mover->PopPendingMovementChange();
    bool applySent = pendingChange.apply;
    MovementChangeType changeTypeSent = pendingChange.movementChangeType;

    MovementFlags mFlag = MOVEMENTFLAG_NONE;
    MovementFlags2 mFlag2 = MOVEMENTFLAG2_NONE;
    MovementChangeType changeTypeReceived;
    switch (recvData.GetOpcode())
    {
        case CMSG_MOVE_WATER_WALK_ACK:      changeTypeReceived = WATER_WALK; mFlag = MOVEMENTFLAG_WATERWALKING; break;
        case CMSG_MOVE_HOVER_ACK:           changeTypeReceived = SET_HOVER; mFlag = MOVEMENTFLAG_HOVER; break;
        case CMSG_MOVE_SET_CAN_FLY_ACK:     changeTypeReceived = SET_CAN_FLY; mFlag = MOVEMENTFLAG_CAN_FLY; break;
        case CMSG_MOVE_SET_CAN_TRANSITION_BETWEEN_SWIM_AND_FLY_ACK:
            changeTypeReceived = SET_CAN_TRANSITION_BETWEEN_SWIM_AND_FLY; mFlag2 = MOVEMENTFLAG2_CAN_TRANSITION_BETWEEN_SWIM_AND_FLY; break;
        case CMSG_MOVE_FEATHER_FALL_ACK:    changeTypeReceived = FEATHER_FALL; mFlag = MOVEMENTFLAG_FALLING_SLOW; break;
        default:
            TC_LOG_ERROR("network", "WorldSession::HandleMovementFlagChangeToggleAck: Unknown move type opcode: %s", GetOpcodeNameForLogging(static_cast<OpcodeClient>(recvData.GetOpcode())).c_str());
            return;
    }

    if (pendingChange.movementCounter != movementCounter
        || applySent != applyReceived
        || changeTypeSent != changeTypeReceived)
    {
        TC_LOG_INFO("cheat", "WorldSession::HandleMovementFlagChangeToggleAck: Player %s from account id %u kicked for incorrect data returned in an ack",
            _player->GetName().c_str(), _player->GetSession()->GetAccountId());
        _player->GetSession()->KickPlayer();
        return;
    }

    switch (changeTypeReceived)
    {
        case WATER_WALK:            mover->SetWaterWalkingReal(applyReceived); break;
        case SET_HOVER:             mover->SetHoverReal(applyReceived); break;
        case SET_CAN_FLY:           mover->SetCanFlyReal(applyReceived); break;
        case SET_CAN_TRANSITION_BETWEEN_SWIM_AND_FLY: 
                                    mover->SetCanTransitionBetweenSwimAndFlyReal(applyReceived); break;
        case FEATHER_FALL:          mover->SetFeatherFallReal(applyReceived); break;
        default:
            TC_LOG_ERROR("network", "WorldSession::HandleMovementFlagChangeToggleAck: Unknown move type opcode: %s", GetOpcodeNameForLogging(static_cast<OpcodeClient>(recvData.GetOpcode())).c_str());
            return;
    }

    mover->ValidateMovementInfo(&movementInfo);
    mover->UpdateMovementInfo(movementInfo);
    if(mFlag != MOVEMENTFLAG_NONE)
        MovementPacketSender::SendMovementFlagChangeToObservers(mover, mFlag, applySent);
    else
        MovementPacketSender::SendMovementFlagChangeToObservers(mover, mFlag2);
}

/*
Handles CMSG_WORLD_TELEPORT. That packet is sent by the client when the user types a special build-in command restricted to GMs.
cf http://wow.gamepedia.com/Console_variables#GM_Commands
The usage of this packet is therefore restricted to GMs and will never be used by normal players.
*/
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

void WorldSession::HandleMoveTimeSkippedOpcode(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_MOVE_TIME_SKIPPED");

    ObjectGuid guid;
    uint32 timeSkipped;
    recvData >> guid.ReadAsPacked();
    recvData >> timeSkipped;

    Unit* mover = GetPlayer()->m_unitMovedByMe;

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

    mover->m_movementInfo.time += timeSkipped;

    WorldPacket data(MSG_MOVE_TIME_SKIPPED, recvData.size());
    data << guid.WriteAsPacked();
    data << timeSkipped;
    GetPlayer()->SendMessageToSet(&data, false);
}
