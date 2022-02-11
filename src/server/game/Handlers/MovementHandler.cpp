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

#include "Battleground.h"
#include "Common.h"
#include "Corpse.h"
#include "GameTime.h"
#include "GameClient.h"
#include "InstanceSaveMgr.h"
#include "Log.h"
#include "MapManager.h"
#include "MotionMaster.h"
#include "MovementGenerator.h"
#include "MovementPacketSender.h"
#include "MoveSpline.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Opcodes.h"
#include "Player.h"
#include "Transport.h"
#include "Vehicle.h"
#include "World.h"
#include "WorldPacket.h"
#include "WorldSession.h"
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
        TC_LOG_ERROR("network", "Map %d (%s) could not be created for player %s (%s), porting player to homebind", loc.GetMapId(), newMap ? newMap->GetMapName() : "Unknown", player->GetGUID().ToString().c_str(), player->GetName().c_str());
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
        TC_LOG_ERROR("network", "WORLD: failed to teleport player %s %s to map %d (%s) because of unknown reason!",
            player->GetName().c_str(), player->GetGUID().ToString().c_str(), loc.GetMapId(), newMap ? newMap->GetMapName() : "Unknown");
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
        if (player->GetCorpseLocation().GetMapId() == mEntry->ID)
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
        if (MapDifficulty const* mapDiff = GetMapDifficultyData(mEntry->ID, diff))
        {
            if (mapDiff->resetTime)
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
    ObjectGuid guid;

    recvData >> guid.ReadAsPacked();

    if (!IsRightUnitBeingMoved(guid))
    {
        recvData.rfinish();                     // prevent warnings spam
        return;
    }

    uint32 sequenceIndex, time;
    recvData >> sequenceIndex >> time;

    GameClient* client = GetGameClient();
    Unit* mover = client->GetActivelyMovedUnit();
    Player* plMover = mover->ToPlayer();

    if (!plMover || !plMover->IsBeingTeleportedNear())
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
        else if (plMover->IsPvP() && !plMover->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_IN_PVP))
            plMover->UpdatePvP(false, false);
    }

    // resummon pet
    GetPlayer()->ResummonPetTemporaryUnSummonedIfAny();

    //lets process all delayed operations on successful teleport
    GetPlayer()->ProcessDelayedOperations();
}

void WorldSession::HandleMovementOpcodes(WorldPacket& recvData)
{
    uint16 opcode = recvData.GetOpcode();

    ObjectGuid guid;
    recvData >> guid.ReadAsPacked();

    if (!IsRightUnitBeingMoved(guid))
    {
        recvData.rfinish();                     // prevent warnings spam
        return;
    }

    GameClient* client = GetGameClient();
    Unit* mover = client->GetActivelyMovedUnit();
    Player* plrMover = mover->ToPlayer();

    // ignore, waiting processing in WorldSession::HandleMoveWorldportAckOpcode and WorldSession::HandleMoveTeleportAck
    if (plrMover && plrMover->IsBeingTeleported())
    {
        recvData.rfinish();                     // prevent warnings spam
        return;
    }

    /* extract packet */

    MovementInfo movementInfo;
    movementInfo.guid = guid;
    ReadMovementInfo(recvData, &movementInfo);

    recvData.rfinish();                         // prevent warnings spam

    if (!movementInfo.pos.IsPositionValid())
    {
        recvData.rfinish();                     // prevent warnings spam
        return;
    }

    if (!mover->movespline->Finalized())
    {
        recvData.rfinish();                     // prevent warnings spam
        return;
    }

    /* handle special cases */
    if (movementInfo.HasMovementFlag(MOVEMENTFLAG_ONTRANSPORT))
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
        {
            recvData.rfinish();                 // prevent warnings spam
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

    /* process position-change */
    WorldPacket data(opcode, recvData.size());
    int64 movementTime = (int64) movementInfo.time + _timeSyncClockDelta;
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
    WriteMovementInfo(&data, &movementInfo);
    mover->SendMessageToSet(&data, _player);

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
                    mover->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_TURNING);
                }
            }
        }
        return;
    }

    mover->UpdatePosition(movementInfo.pos);

    if (plrMover)                                            // nothing is charmed, or player charmed
    {
        if (plrMover->IsSitState() && (movementInfo.flags & (MOVEMENTFLAG_MASK_MOVING | MOVEMENTFLAG_MASK_TURNING)))
            plrMover->SetStandState(UNIT_STAND_STATE_STAND);

        plrMover->UpdateFallInformationIfNeed(movementInfo, opcode);

        if (movementInfo.pos.GetPositionZ() < plrMover->GetMap()->GetMinHeight(movementInfo.pos.GetPositionX(), movementInfo.pos.GetPositionY()))
        {
            if (!(plrMover->GetBattleground() && plrMover->GetBattleground()->HandlePlayerUnderMap(plrMover)))
            {
                // NOTE: this is actually called many times while falling
                // even after the player has been teleported away
                /// @todo discard movement packets after the player is rooted
                if (plrMover->IsAlive())
                {
                    TC_LOG_DEBUG("entities.player.falldamage", "FALLDAMAGE Below map. Map min height: %f , Player debug info:\n%s", plrMover->GetMap()->GetMinHeight(movementInfo.pos.GetPositionX(), movementInfo.pos.GetPositionY()), plrMover->GetDebugInfo().c_str());
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
        else
            plrMover->RemoveFlag(PLAYER_FLAGS, PLAYER_FLAGS_IS_OUT_OF_BOUNDS);
    }
}

void WorldSession::HandleForceSpeedChangeAck(WorldPacket &recvData)
{
    /* extract packet */
    ObjectGuid guid;
    recvData >> guid.ReadAsPacked();

    GameClient* client = GetGameClient();

    // ACK handlers should call GameClient::IsAllowedToMove instead of WorldSession::IsRightUnitBeingMoved
    // because the ACK could be coming from a unit that is under the control of that client but is not the 'Active Mover' unit.
    // Example: Get a speed buff on yourself, then mount a vehicle before the end of the buff. When the buff expires,
    // a force message will be sent to the client regarding the player and the client is required to respond with an ACK.
    // But the vehicle will be the active mover unit at that time.
    if (!client->IsAllowedToMove(guid))
    {
        recvData.rfinish();                     // prevent warnings spam
        TC_LOG_DEBUG("entities.unit", "Ignoring ACK. Bad or outdated movement data by Player %s", _player->GetName().c_str());
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
    ReadMovementInfo(recvData, &movementInfo);
    recvData >> speedReceived;

    ASSERT(mover);

    // verify that indeed the client is replying with the changes that were send to him
    if (!mover->HasPendingMovementChange() || mover->PeakFirstPendingMovementChange().movementCounter > movementCounter)
    {
        TC_LOG_DEBUG("entities.unit", "Ignoring ACK. Bad or outdated movement data by Player %s", _player->GetName().c_str());
        return;
    }

    PlayerMovementPendingChange pendingChange = mover->PopPendingMovementChange();
    float speedSent = pendingChange.newValue;
    MovementChangeType changeType = pendingChange.movementChangeType;
    UnitMoveType moveTypeSent;
    switch (changeType)
    {
        case MovementChangeType::SPEED_CHANGE_WALK:                 moveTypeSent = MOVE_WALK; break;
        case MovementChangeType::SPEED_CHANGE_RUN:                  moveTypeSent = MOVE_RUN; break;
        case MovementChangeType::SPEED_CHANGE_RUN_BACK:             moveTypeSent = MOVE_RUN_BACK; break;
        case MovementChangeType::SPEED_CHANGE_SWIM:                 moveTypeSent = MOVE_SWIM; break;
        case MovementChangeType::SPEED_CHANGE_SWIM_BACK:            moveTypeSent = MOVE_SWIM_BACK; break;
        case MovementChangeType::RATE_CHANGE_TURN:                  moveTypeSent = MOVE_TURN_RATE; break;
        case MovementChangeType::SPEED_CHANGE_FLIGHT_SPEED:         moveTypeSent = MOVE_FLIGHT; break;
        case MovementChangeType::SPEED_CHANGE_FLIGHT_BACK_SPEED:    moveTypeSent = MOVE_FLIGHT_BACK; break;
        case MovementChangeType::RATE_CHANGE_PITCH:                 moveTypeSent = MOVE_PITCH_RATE; break;
        default:
            TC_LOG_INFO("cheat", "WorldSession::HandleForceSpeedChangeAck: Player %s from account id %u kicked for incorrect data returned in an ack. movementChangeType: %u",
                _player->GetName().c_str(), _player->GetSession()->GetAccountId(), static_cast<uint32>(AsUnderlyingType(changeType)));
            if (sWorld->getIntConfig(CONFIG_PENDING_MOVE_CHANGES_TIMEOUT) != 0)
                _player->GetSession()->KickPlayer("incorrect movementChangeType returned in an ack");
            return;
    }

    if (pendingChange.movementCounter != movementCounter)
    {
        TC_LOG_INFO("cheat", "WorldSession::HandleForceSpeedChangeAck: Player %s from account id %u kicked for incorrect data returned in an ack. pendingChange.movementCounter: %u, movementCounter: %u",
            _player->GetName().c_str(), _player->GetSession()->GetAccountId(), pendingChange.movementCounter, movementCounter);
        if (sWorld->getIntConfig(CONFIG_PENDING_MOVE_CHANGES_TIMEOUT) != 0)
            _player->GetSession()->KickPlayer("incorrect movementCounter returned in an ack");
        return;
    }

    if (std::fabs(speedSent - speedReceived) > 0.01f)
    {
        TC_LOG_INFO("cheat", "WorldSession::HandleForceSpeedChangeAck: Player %s from account id %u kicked for incorrect data returned in an ack. speedSent - speedReceived: %f",
            _player->GetName().c_str(), _player->GetSession()->GetAccountId(), std::fabs(speedSent - speedReceived));
        if (sWorld->getIntConfig(CONFIG_PENDING_MOVE_CHANGES_TIMEOUT) != 0)
            _player->GetSession()->KickPlayer("incorrect speed returned in an ack");
        return;
    }

    if (moveTypeSent != move_type)
    {
        TC_LOG_INFO("cheat", "WorldSession::HandleForceSpeedChangeAck: Player %s from account id %u kicked for incorrect data returned in an ack. moveTypeSent: %u, move_type: %u",
            _player->GetName().c_str(), _player->GetSession()->GetAccountId(), static_cast<uint32>(AsUnderlyingType(moveTypeSent)), static_cast<uint32>(AsUnderlyingType(move_type)));
        if (sWorld->getIntConfig(CONFIG_PENDING_MOVE_CHANGES_TIMEOUT) != 0)
            _player->GetSession()->KickPlayer("incorrect moveType returned in an ack");
        return;
    }

    /* the client data has been verified. let's do the actual change now */
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

    float newSpeedRate = speedSent / (mover->IsControlledByPlayer() ? playerBaseMoveSpeed[move_type] : baseMoveSpeed[move_type]);
    mover->SetSpeedRateReal(move_type, newSpeedRate);
    MovementPacketSender::SendSpeedChangeToObservers(mover, move_type, speedSent);
}

void WorldSession::HandleSetActiveMoverOpcode(WorldPacket &recvData)
{
    TC_LOG_DEBUG("network", "WORLD: Recvd CMSG_SET_ACTIVE_MOVER");

    ObjectGuid guid;
    recvData >> guid;

    GameClient* client = GetGameClient();

    // step 1: look at the list of units that this client is allowed to move. check if the client is allowed to even move the
    // unit that is mentioned in the packet. if not, either silently ignore, log this event or kick the client.
    if (!client->IsAllowedToMove(guid))
    {
        // @todo log or kick or do nothing depending on configuration
        TC_LOG_DEBUG("entities.unit", "set active mover FAILED for client of player %s. GUID %s.", _player->GetName().c_str(), guid.ToString().c_str());
        return;
    }

    // step 2:
    TC_LOG_DEBUG("entities.unit", "set active mover OK for client of player %s. GUID %s.", _player->GetName().c_str(), guid.ToString().c_str());
    Unit* newActivelyMovedUnit = ObjectAccessor::GetUnit(*_player, guid);
    client->SetActivelyMovedUnit(newActivelyMovedUnit);
}

void WorldSession::HandleMoveNotActiveMover(WorldPacket &recvData)
{
    TC_LOG_DEBUG("network", "WORLD: Recvd CMSG_MOVE_NOT_ACTIVE_MOVER");

    ObjectGuid old_mover_guid;
    recvData >> old_mover_guid.ReadAsPacked();
    recvData.rfinish();                   // prevent warnings spam.
    // the movement info in this kind of packet is ignored for now. It's unclear if it should be used.

    GameClient* client = GetGameClient();

    if (client->GetActivelyMovedUnit() == nullptr || client->GetActivelyMovedUnit()->GetGUID() != old_mover_guid)
    {
        TC_LOG_DEBUG("entities.unit", "unset active mover FAILED for client of player %s. GUID %s.", _player->GetName().c_str(), old_mover_guid.ToString().c_str());
        return;
    }

    TC_LOG_DEBUG("entities.unit", "unset active mover OK for client of player %s. GUID %s.", _player->GetName().c_str(), old_mover_guid.ToString().c_str());
    client->SetActivelyMovedUnit(nullptr);
}

void WorldSession::HandleMountSpecialAnimOpcode(WorldPacket& /*recvData*/)
{
    WorldPacket data(SMSG_MOUNTSPECIAL_ANIM, 8);
    data << uint64(GetPlayer()->GetGUID());

    GetPlayer()->SendMessageToSet(&data, false);
}

void WorldSession::HandleMoveKnockBackAck(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "CMSG_MOVE_KNOCK_BACK_ACK");

    ObjectGuid guid;
    recvData >> guid.ReadAsPacked();

    GameClient* client = GetGameClient();

    // ACK handlers should call GameClient::IsAllowedToMove instead of WorldSession::IsRightUnitBeingMoved
    // because the ACK could be coming from a unit that is under the control of that client but is not the 'Active Mover' unit.
    // Example: Get a speed buff on yourself, then mount a vehicle before the end of the buff. When the buff expires,
    // a force message will be sent to the client regarding the player and the client is required to respond with an ACK.
    // But the vehicle will be the active mover unit at that time.
    if (!client->IsAllowedToMove(guid))
    {
        recvData.rfinish();                     // prevent warnings spam
        return;
    }

    Unit* mover = ObjectAccessor::GetUnit(*_player, guid);
    ASSERT(mover);

    recvData.read_skip<uint32>();                          // unk

    MovementInfo movementInfo;
    movementInfo.guid = guid;
    ReadMovementInfo(recvData, &movementInfo);

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

    WorldPacket data(MSG_MOVE_KNOCK_BACK, 66);
    WriteMovementInfo(&data, &movementInfo);

    // knockback specific info
    data << movementInfo.jump.sinAngle;
    data << movementInfo.jump.cosAngle;
    data << movementInfo.jump.xyspeed;
    data << movementInfo.jump.zspeed;

    client->GetBasePlayer()->SendMessageToSet(&data, false);
}

void WorldSession::HandleMoveHoverAck(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "CMSG_MOVE_HOVER_ACK");

    ObjectGuid guid;                                        // guid - unused
    recvData >> guid.ReadAsPacked();

    GameClient* client = GetGameClient();
    if (!client->IsAllowedToMove(guid))
    {
        recvData.rfinish();                     // prevent warnings spam
        return;
    }

    recvData.read_skip<uint32>();                           // unk

    MovementInfo movementInfo;
    movementInfo.guid = guid;
    ReadMovementInfo(recvData, &movementInfo);

    recvData.read_skip<uint32>();                           // unk2
}

void WorldSession::HandleMoveWaterWalkAck(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "CMSG_MOVE_WATER_WALK_ACK");

    ObjectGuid guid;                                        // guid - unused
    recvData >> guid.ReadAsPacked();

    GameClient* client = GetGameClient();
    if (!client->IsAllowedToMove(guid))
    {
        recvData.rfinish();                     // prevent warnings spam
        return;
    }

    recvData.read_skip<uint32>();                           // unk

    MovementInfo movementInfo;
    movementInfo.guid = guid;
    ReadMovementInfo(recvData, &movementInfo);

    recvData.read_skip<uint32>();                           // unk2
}

void WorldSession::HandleMoveRootAck(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "CMSG_FORCE_MOVE_ROOT_ACK");

    ObjectGuid guid;                                        // guid - unused
    recvData >> guid.ReadAsPacked();

    GameClient* client = GetGameClient();
    if (!client->IsAllowedToMove(guid))
    {
        recvData.rfinish();                     // prevent warnings spam
        return;
    }

    recvData.read_skip<uint32>();                           // unk

    MovementInfo movementInfo;
    movementInfo.guid = guid;
    ReadMovementInfo(recvData, &movementInfo);
}

void WorldSession::HandleFeatherFallAck(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "WORLD: CMSG_MOVE_FEATHER_FALL_ACK");

    ObjectGuid guid;                                        // guid - unused
    recvData >> guid.ReadAsPacked();

    GameClient* client = GetGameClient();
    if (!client->IsAllowedToMove(guid))
    {
        recvData.rfinish();                     // prevent warnings spam
        return;
    }

    recvData.read_skip<uint32>();                           // unk

    MovementInfo movementInfo;
    movementInfo.guid = guid;
    ReadMovementInfo(recvData, &movementInfo);

    recvData.read_skip<uint32>();                           // unk2
}

void WorldSession::HandleMoveUnRootAck(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "WORLD: CMSG_FORCE_MOVE_UNROOT_ACK");

    ObjectGuid guid;                                        // guid - unused
    recvData >> guid.ReadAsPacked();

    GameClient* client = GetGameClient();
    if (!client->IsAllowedToMove(guid))
    {
        recvData.rfinish();                     // prevent warnings spam
        return;
    }

    recvData.read_skip<uint32>();                           // unk

    MovementInfo movementInfo;
    movementInfo.guid = guid;
    ReadMovementInfo(recvData, &movementInfo);
}

void WorldSession::HandleMoveSetCanFlyAckOpcode(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "WORLD: CMSG_MOVE_SET_CAN_FLY_ACK");

    ObjectGuid guid;                                        // guid - unused
    recvData >> guid.ReadAsPacked();

    GameClient* client = GetGameClient();
    if (!client->IsAllowedToMove(guid))
    {
        recvData.rfinish();                     // prevent warnings spam
        return;
    }

    recvData.read_skip<uint32>();                           // unk

    MovementInfo movementInfo;
    movementInfo.guid = guid;
    ReadMovementInfo(recvData, &movementInfo);

    recvData.read_skip<uint32>();                           // unk2
}

void WorldSession::HandleMoveSetCanTransitionBetweenSwinAndFlyAck(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "WORLD: CMSG_MOVE_SET_CAN_TRANSITION_BETWEEN_SWIM_AND_FLY_ACK");

    ObjectGuid guid;
    recvData >> guid.ReadAsPacked();

    GameClient* client = GetGameClient();
    if (!client->IsAllowedToMove(guid))
    {
        recvData.rfinish();                     // prevent warnings spam
        return;
    }

    recvData.read_skip<uint32>();                           // unk

    MovementInfo movementInfo;
    movementInfo.guid = guid;
    ReadMovementInfo(recvData, &movementInfo);

    recvData.read_skip<uint32>();                           // unk2
}

void WorldSession::HandleMoveGravityDisableAck(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "WORLD: CMSG_MOVE_GRAVITY_DISABLE_ACK");

    ObjectGuid guid;
    recvData >> guid.ReadAsPacked();

    GameClient* client = GetGameClient();
    if (!client->IsAllowedToMove(guid))
    {
        recvData.rfinish();                     // prevent warnings spam
        return;
    }

    recvData.read_skip<uint32>();                           // unk

    MovementInfo movementInfo;
    movementInfo.guid = guid;
    ReadMovementInfo(recvData, &movementInfo);
}

void WorldSession::HandleMoveGravityEnableAck(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "WORLD: CMSG_MOVE_GRAVITY_ENABLE_ACK");

    ObjectGuid guid;
    recvData >> guid.ReadAsPacked();

    GameClient* client = GetGameClient();
    if (!client->IsAllowedToMove(guid))
    {
        recvData.rfinish();                     // prevent warnings spam
        return;
    }

    recvData.read_skip<uint32>();                           // unk

    MovementInfo movementInfo;
    movementInfo.guid = guid;
    ReadMovementInfo(recvData, &movementInfo);
}

void WorldSession::HandleMoveSetCollisionHgtAck(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "WORLD: CMSG_MOVE_SET_COLLISION_HGT_ACK");

    ObjectGuid guid;
    float  newValue;
    recvData >> guid.ReadAsPacked();

    GameClient* client = GetGameClient();
    if (!client->IsAllowedToMove(guid))
    {
        recvData.rfinish();                     // prevent warnings spam
        return;
    }

    recvData.read_skip<uint32>();                           // movement counter

    MovementInfo movementInfo;
    movementInfo.guid = guid;
    ReadMovementInfo(recvData, &movementInfo);

    recvData >> newValue;
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

    if (!IsRightUnitBeingMoved(guid))
    {
        recvData.rfinish();                     // prevent warnings spam
        return;
    }

    GameClient* client = GetGameClient();
    Unit* mover = client->GetActivelyMovedUnit();
    mover->m_movementInfo.time += timeSkipped;

    WorldPacket data(MSG_MOVE_TIME_SKIPPED, recvData.size());
    data << guid.WriteAsPacked();
    data << timeSkipped;
    GetPlayer()->SendMessageToSet(&data, false);
}

void WorldSession::HandleTimeSyncResponse(WorldPacket& recvData)
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
    int64 clockDelta = (int64)serverTimeAtSent + (int64)lagDelay - (int64)clientTimestamp;
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
        if (pair.second < latencyStandardDeviation + latencyMedian) {
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
