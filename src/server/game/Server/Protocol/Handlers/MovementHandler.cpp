/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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
#include "Player.h"
#include "SpellAuras.h"
#include "MapManager.h"
#include "Transport.h"
#include "Battleground.h"
#include "WaypointMovementGenerator.h"
#include "InstanceSaveMgr.h"
#include "ObjectMgr.h"
#include "MovementStructures.h"

void WorldSession::HandleMoveWorldportAckOpcode(WorldPacket & /*recv_data*/)
{
    sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: got CMSG_WORLD_PORT_RESPONSE.");
    HandleMoveWorldportAckOpcode();
}

void WorldSession::HandleMoveWorldportAckOpcode()
{
    // ignore unexpected far teleports
    if (!GetPlayer()->IsBeingTeleportedFar())
        return;

    GetPlayer()->SetSemaphoreTeleportFar(false);

    // get the teleport destination
    WorldLocation &loc = GetPlayer()->GetTeleportDest();

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
    if (GetPlayer()->m_InstanceValid == false && !mInstance)
        GetPlayer()->m_InstanceValid = true;

    Map* oldMap = GetPlayer()->GetMap();
    ASSERT(oldMap);
    if (GetPlayer()->IsInWorld())
    {
        sLog->outCrash("Player (Name %s) is still in world when teleported from map %u to new map %u", GetPlayer()->GetName(), oldMap->GetId(), loc.GetMapId());
        oldMap->RemovePlayerFromMap(GetPlayer(), false);
    }

    // relocate the player to the teleport destination
    Map* newMap = sMapMgr->CreateMap(loc.GetMapId(), GetPlayer());
    // the CanEnter checks are done in TeleporTo but conditions may change
    // while the player is in transit, for example the map may get full
    if (!newMap || !newMap->CanEnter(GetPlayer()))
    {
        sLog->outError("Map %d could not be created for player %d, porting player to homebind", loc.GetMapId(), GetPlayer()->GetGUIDLow());
        GetPlayer()->TeleportTo(GetPlayer()->m_homebindMapId, GetPlayer()->m_homebindX, GetPlayer()->m_homebindY, GetPlayer()->m_homebindZ, GetPlayer()->GetOrientation());
        return;
    }
    else
        GetPlayer()->Relocate(&loc);

    GetPlayer()->ResetMap();
    GetPlayer()->SetMap(newMap);

    GetPlayer()->SendInitialPacketsBeforeAddToMap();
    if (!GetPlayer()->GetMap()->AddPlayerToMap(GetPlayer()))
    {
        sLog->outError("WORLD: failed to teleport player %s (%d) to map %d because of unknown reason!", GetPlayer()->GetName(), GetPlayer()->GetGUIDLow(), loc.GetMapId());
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
            FlightPathMovementGenerator* flight = (FlightPathMovementGenerator*)(GetPlayer()->GetMotionMaster()->top());
            flight->Initialize(*GetPlayer());
            return;
        }

        // battleground state prepare, stop flight
        GetPlayer()->GetMotionMaster()->MovementExpired();
        GetPlayer()->CleanupAfterTaxiFlight();
    }

    // resurrect character at enter into instance where his corpse exist after add to map
    Corpse* corpse = GetPlayer()->GetCorpse();
    if (corpse && corpse->GetType() != CORPSE_BONES && corpse->GetMapId() == GetPlayer()->GetMapId())
    {
        if (mEntry->IsDungeon())
        {
            GetPlayer()->ResurrectPlayer(0.5f, false);
            GetPlayer()->SpawnCorpseBones();
        }
    }

    bool allowMount = !mEntry->IsDungeon() || mEntry->IsBattlegroundOrArena();
    if (mInstance)
    {
        Difficulty diff = GetPlayer()->GetDifficulty(mEntry->IsRaid());
        if (MapDifficulty const* mapDiff = GetMapDifficultyData(mEntry->MapID, diff))
        {
            if (mapDiff->resetTime)
            {
                if (time_t timeReset = sInstanceSaveMgr->GetResetTimeFor(mEntry->MapID, diff))
                {
                    uint32 timeleft = uint32(timeReset - time(NULL));
                    GetPlayer()->SendInstanceResetWarning(mEntry->MapID, diff, timeleft);
                }
            }
        }
        allowMount = mInstance->AllowMount;
    }

    // mount allow check
    if (!allowMount)
        _player->RemoveAurasByType(SPELL_AURA_MOUNTED);

    // update zone immediately, otherwise leave channel will cause crash in mtmap
    uint32 newzone, newarea;
    GetPlayer()->GetZoneAndAreaId(newzone, newarea);
    GetPlayer()->UpdateZone(newzone, newarea);

    // honorless target
    if (GetPlayer()->pvpInfo.inHostileArea)
        GetPlayer()->CastSpell(GetPlayer(), 2479, true);

    // in friendly area
    else if (GetPlayer()->IsPvP() && !GetPlayer()->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_IN_PVP))
        GetPlayer()->UpdatePvP(false, false);

    // resummon pet
    GetPlayer()->ResummonPetTemporaryUnSummonedIfAny();

    //lets process all delayed operations on successful teleport
    GetPlayer()->ProcessDelayedOperations();
}

void WorldSession::HandleMoveTeleportAck(WorldPacket& recv_data)
{
    sLog->outDebug(LOG_FILTER_NETWORKIO, "CMSG_MOVE_TELEPORT_ACK");

    BitStream mask = recv_data.ReadBitStream(8);
    
    uint32 flags, time;
    recv_data >> flags >> time;

    ByteBuffer bytes(8, true);
    recv_data.ReadXorByte(mask[6], bytes[1]);
    recv_data.ReadXorByte(mask[0], bytes[3]);
    recv_data.ReadXorByte(mask[1], bytes[2]);
    recv_data.ReadXorByte(mask[7], bytes[0]);
    recv_data.ReadXorByte(mask[5], bytes[6]);
    recv_data.ReadXorByte(mask[3], bytes[4]);
    recv_data.ReadXorByte(mask[2], bytes[7]);
    recv_data.ReadXorByte(mask[4], bytes[5]);

    uint64 guid = BitConverter::ToUInt64(bytes);

    sLog->outStaticDebug("Guid " UI64FMTD, guid);
    sLog->outStaticDebug("Flags %u, time %u", flags, time/IN_MILLISECONDS);

    Unit* mover = _player->m_mover;
    Player* plMover = mover->GetTypeId() == TYPEID_PLAYER ? (Player*)mover : NULL;

    if (!plMover || !plMover->IsBeingTeleportedNear())
        return;

    if (guid != plMover->GetGUID())
        return;

    plMover->SetSemaphoreTeleportNear(false);

    uint32 old_zone = plMover->GetZoneId();

    WorldLocation const& dest = plMover->GetTeleportDest();

    plMover->UpdatePosition(dest, true);

    uint32 newzone, newarea;
    plMover->GetZoneAndAreaId(newzone, newarea);
    plMover->UpdateZone(newzone, newarea);

    // new zone
    if (old_zone != newzone)
    {
        // honorless target
        if (plMover->pvpInfo.inHostileArea)
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

void WorldSession::HandleMovementOpcodes(WorldPacket & recv_data)
{
    uint16 opcode = recv_data.GetOpcode();

    Unit* mover = _player->m_mover;

    ASSERT(mover != NULL);                                  // there must always be a mover

    Player* plMover = mover->GetTypeId() == TYPEID_PLAYER ? (Player*)mover : NULL;

    // ignore, waiting processing in WorldSession::HandleMoveWorldportAckOpcode and WorldSession::HandleMoveTeleportAck
    if (plMover && plMover->IsBeingTeleported())
    {
        return;
    }

    /* extract packet */
    MovementInfo movementInfo;
    ReadMovementInfo(recv_data, &movementInfo);

    // prevent tampered movement data
    if (movementInfo.guid != mover->GetGUID())
    {
        sLog->outError("HandleMovementOpcodes: guid error");
        return;
    }
    if (!movementInfo.pos.IsPositionValid())
    {
        sLog->outError("HandleMovementOpcodes: Invalid Position");
        return;
    }

    /* handle special cases */
    if (movementInfo.flags & MOVEMENTFLAG_ONTRANSPORT)
    {
        // transports size limited
        // (also received at zeppelin leave by some reason with t_* as absolute in continent coordinates, can be safely skipped)
        if (movementInfo.t_pos.GetPositionX() > 50 || movementInfo.t_pos.GetPositionY() > 50 || movementInfo.t_pos.GetPositionZ() > 50)
        {
            recv_data.rfinish();                   // prevent warnings spam
            return;
        }

        if (!Trinity::IsValidMapCoord(movementInfo.pos.GetPositionX() + movementInfo.t_pos.GetPositionX(), movementInfo.pos.GetPositionY() + movementInfo.t_pos.GetPositionY(),
            movementInfo.pos.GetPositionZ() + movementInfo.t_pos.GetPositionZ(), movementInfo.pos.GetOrientation() + movementInfo.t_pos.GetOrientation()))
        {
            recv_data.rfinish();                   // prevent warnings spam
            return;
        }

        // if we boarded a transport, add us to it
        if (plMover && !plMover->GetTransport())
        {
            // elevators also cause the client to send MOVEMENTFLAG_ONTRANSPORT - just dismount if the guid can be found in the transport list
            for (MapManager::TransportSet::const_iterator iter = sMapMgr->m_Transports.begin(); iter != sMapMgr->m_Transports.end(); ++iter)
            {
                if ((*iter)->GetGUID() == movementInfo.t_guid)
                {
                    plMover->m_transport = (*iter);
                    (*iter)->AddPassenger(plMover);
                    break;
                }
            }
        }

        if (!mover->GetTransport() && !mover->GetVehicle())
        {
            GameObject* go = mover->GetMap()->GetGameObject(movementInfo.t_guid);
            if (!go || go->GetGoType() != GAMEOBJECT_TYPE_TRANSPORT)
                movementInfo.flags &= ~MOVEMENTFLAG_ONTRANSPORT;
        }
    }
    else if (plMover && plMover->GetTransport())                // if we were on a transport, leave
    {
        plMover->m_transport->RemovePassenger(plMover);
        plMover->m_transport = NULL;
        movementInfo.t_pos.Relocate(0.0f, 0.0f, 0.0f, 0.0f);
        movementInfo.t_time = 0;
        movementInfo.t_seat = -1;
    }

    // fall damage generation (ignore in flight case that can be triggered also at lags in moment teleportation to another map).
    if (opcode == MSG_MOVE_FALL_LAND && plMover && !plMover->isInFlight())
        plMover->HandleFall(movementInfo);

    if (plMover && ((movementInfo.flags & MOVEMENTFLAG_SWIMMING) != 0) != plMover->IsInWater())
    {
        // now client not include swimming flag in case jumping under water
        plMover->SetInWater(!plMover->IsInWater() || plMover->GetBaseMap()->IsUnderWater(movementInfo.pos.GetPositionX(), movementInfo.pos.GetPositionY(), movementInfo.pos.GetPositionZ()));
    }

    /*----------------------*/

    /* process position-change */
    WorldPacket data(SMSG_PLAYER_MOVE, recv_data.size());
    movementInfo.time = getMSTime();
    movementInfo.guid = mover->GetGUID();
    WriteMovementInfo(data, &movementInfo);
    mover->SendMessageToSet(&data, _player);

    mover->m_movementInfo = movementInfo;

    // this is almost never true (not sure why it is sometimes, but it is), normally use mover->IsVehicle()
    if (mover->GetVehicle())
    {
        mover->SetOrientation(movementInfo.pos.GetOrientation());
        return;
    }

    mover->UpdatePosition(movementInfo.pos);

    if (plMover)                                            // nothing is charmed, or player charmed
    {
        plMover->UpdateFallInformationIfNeed(movementInfo, opcode);

        if (movementInfo.pos.GetPositionZ() < -500.0f)
        {
            if (!(plMover->InBattleground()
                && plMover->GetBattleground()
                && plMover->GetBattleground()->HandlePlayerUnderMap(_player)))
            {
                // NOTE: this is actually called many times while falling
                // even after the player has been teleported away
                // TODO: discard movement packets after the player is rooted
                if (plMover->isAlive())
                {
                    plMover->EnvironmentalDamage(DAMAGE_FALL_TO_VOID, GetPlayer()->GetMaxHealth());
                    // player can be alive if GM/etc
                    // change the death state to CORPSE to prevent the death timer from
                    // starting in the next player update
                    if (!plMover->isAlive())
                        plMover->KillPlayer();
                }
            }
        }
    }
}

void WorldSession::HandleForceSpeedChangeAck(WorldPacket &recv_data)
{
    uint32 opcode = recv_data.GetOpcode();
    sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: Recvd %s (%u, 0x%X) opcode", LookupOpcodeName(Opcodes(opcode)), opcode, opcode);

    /* extract packet */
    uint64 guid;
    uint32 unk1;
    float  newspeed;

    recv_data.readPackGUID(guid);

    // now can skip not our packet
    if (_player->GetGUID() != guid)
    {
        recv_data.rfinish();                   // prevent warnings spam
        return;
    }

    // continue parse packet

    recv_data >> unk1;                                      // counter or moveEvent

    MovementInfo movementInfo;
    movementInfo.guid = guid;
    ReadMovementInfo(recv_data, &movementInfo);

    recv_data >> newspeed;
    /*----------------*/

    // client ACK send one packet for mounted/run case and need skip all except last from its
    // in other cases anti-cheat check can be fail in false case
    UnitMoveType move_type;
    UnitMoveType force_move_type;

    static char const* move_type_name[MAX_MOVE_TYPE] = {  "Walk", "Run", "RunBack", "Swim", "SwimBack", "TurnRate", "Flight", "FlightBack", "PitchRate" };

    switch (opcode)
    {
        case CMSG_MOVE_FORCE_WALK_SPEED_CHANGE_ACK:          move_type = MOVE_WALK;          force_move_type = MOVE_WALK;        break;
        case CMSG_MOVE_FORCE_RUN_SPEED_CHANGE_ACK:           move_type = MOVE_RUN;           force_move_type = MOVE_RUN;         break;
        case CMSG_MOVE_FORCE_RUN_BACK_SPEED_CHANGE_ACK:      move_type = MOVE_RUN_BACK;      force_move_type = MOVE_RUN_BACK;    break;
        case CMSG_MOVE_FORCE_SWIM_SPEED_CHANGE_ACK:          move_type = MOVE_SWIM;          force_move_type = MOVE_SWIM;        break;
        case CMSG_MOVE_FORCE_SWIM_BACK_SPEED_CHANGE_ACK:     move_type = MOVE_SWIM_BACK;     force_move_type = MOVE_SWIM_BACK;   break;
        case CMSG_MOVE_FORCE_TURN_RATE_CHANGE_ACK:           move_type = MOVE_TURN_RATE;     force_move_type = MOVE_TURN_RATE;   break;
        case CMSG_MOVE_FORCE_FLIGHT_SPEED_CHANGE_ACK:        move_type = MOVE_FLIGHT;        force_move_type = MOVE_FLIGHT;      break;
        case CMSG_MOVE_FORCE_FLIGHT_BACK_SPEED_CHANGE_ACK:   move_type = MOVE_FLIGHT_BACK;   force_move_type = MOVE_FLIGHT_BACK; break;
        case CMSG_MOVE_FORCE_PITCH_RATE_CHANGE_ACK:          move_type = MOVE_PITCH_RATE;    force_move_type = MOVE_PITCH_RATE;  break;
        default:
            sLog->outError("WorldSession::HandleForceSpeedChangeAck: Unknown move type opcode: %u", opcode);
            return;
    }

    // skip all forced speed changes except last and unexpected
    // in run/mounted case used one ACK and it must be skipped.m_forced_speed_changes[MOVE_RUN} store both.
    if (_player->m_forced_speed_changes[force_move_type] > 0)
    {
        --_player->m_forced_speed_changes[force_move_type];
        if (_player->m_forced_speed_changes[force_move_type] > 0)
            return;
    }

    if (!_player->GetTransport() && fabs(_player->GetSpeed(move_type) - newspeed) > 0.01f)
    {
        if (_player->GetSpeed(move_type) > newspeed)         // must be greater - just correct
        {
            sLog->outError("%sSpeedChange player %s is NOT correct (must be %f instead %f), force set to correct value",
                move_type_name[move_type], _player->GetName(), _player->GetSpeed(move_type), newspeed);
            _player->SetSpeed(move_type, _player->GetSpeedRate(move_type), true);
        }
        else                                                // must be lesser - cheating
        {
            sLog->outBasic("Player %s from account id %u kicked for incorrect speed (must be %f instead %f)",
                _player->GetName(), _player->GetSession()->GetAccountId(), _player->GetSpeed(move_type), newspeed);
            _player->GetSession()->KickPlayer();
        }
    }
}

void WorldSession::HandleSetActiveMoverOpcode(WorldPacket &recv_data)
{
    sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: Recvd CMSG_SET_ACTIVE_MOVER");

    uint64 guid;
    recv_data >> guid;

    if (GetPlayer()->IsInWorld())
    {
        if (Unit* mover = ObjectAccessor::GetUnit(*GetPlayer(), guid))
        {
            GetPlayer()->SetMover(mover);
            if (mover != GetPlayer() && mover->canFly())
            {
                GetPlayer()->SendSetFlyPacket(true);
            }
        }
        else
        {
            sLog->outError("HandleSetActiveMoverOpcode: incorrect mover guid: mover is " UI64FMTD " (%s - Entry: %u) and should be " UI64FMTD, guid, GetLogNameForGuid(guid), GUID_ENPART(guid), _player->m_mover->GetGUID());
            GetPlayer()->SetMover(GetPlayer());
        }
    }
}

void WorldSession::HandleMoveNotActiveMover(WorldPacket &recv_data)
{
    sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: Recvd CMSG_MOVE_NOT_ACTIVE_MOVER");

    uint64 old_mover_guid;
    recv_data.readPackGUID(old_mover_guid);

    MovementInfo mi;
    mi.guid = old_mover_guid;
    ReadMovementInfo(recv_data, &mi);

    _player->m_movementInfo = mi;
}

void WorldSession::HandleMountSpecialAnimOpcode(WorldPacket& /*recv_data*/)
{
    WorldPacket data(SMSG_MOUNTSPECIAL_ANIM, 8);
    data << uint64(GetPlayer()->GetGUID());

    GetPlayer()->SendMessageToSet(&data, false);
}

void WorldSession::HandleMoveKnockBackAck(WorldPacket & recv_data)
{
    sLog->outDebug(LOG_FILTER_NETWORKIO, "CMSG_MOVE_KNOCK_BACK_ACK");

    uint64 guid;
    recv_data.readPackGUID(guid);

    if (_player->m_mover->GetGUID() != guid)
        return;

    recv_data.read_skip<uint32>();                          // unk

    MovementInfo movementInfo;
    ReadMovementInfo(recv_data, &movementInfo);
    _player->m_movementInfo = movementInfo;

    WorldPacket data(SMSG_MOVE_UPDATE_KNOCK_BACK, 66);
    data.appendPackGUID(guid);
    _player->BuildMovementPacket(&data);

    // knockback specific info
    data << movementInfo.j_sinAngle;
    data << movementInfo.j_cosAngle;
    data << movementInfo.j_xyspeed;
    data << movementInfo.j_zspeed;

    _player->SendMessageToSet(&data, false);
}

void WorldSession::HandleMoveHoverAck(WorldPacket& recv_data)
{
    sLog->outDebug(LOG_FILTER_NETWORKIO, "CMSG_MOVE_HOVER_ACK");

    uint64 guid;                                            // guid - unused
    recv_data.readPackGUID(guid);

    recv_data.read_skip<uint32>();                          // unk

    MovementInfo movementInfo;
    ReadMovementInfo(recv_data, &movementInfo);

    recv_data.read_skip<uint32>();                          // unk2
}

void WorldSession::HandleMoveWaterWalkAck(WorldPacket& recv_data)
{
    sLog->outDebug(LOG_FILTER_NETWORKIO, "CMSG_MOVE_WATER_WALK_ACK");

    uint64 guid;                                            // guid - unused
    recv_data.readPackGUID(guid);

    recv_data.read_skip<uint32>();                          // unk

    MovementInfo movementInfo;
    ReadMovementInfo(recv_data, &movementInfo);

    recv_data.read_skip<uint32>();                          // unk2
}

void WorldSession::HandleSummonResponseOpcode(WorldPacket& recv_data)
{
    if (!_player->isAlive() || _player->isInCombat())
        return;

    uint64 summonerGuid;
    bool agree;
    recv_data >> summonerGuid;
    recv_data >> agree;

    _player->SummonIfPossible(agree);
}

void WorldSession::ReadMovementInfo(WorldPacket &data, MovementInfo* mi)
{
    bool HaveTransportData = false,
       HaveTransportTime2 = false,
       HaveTransportTime3 = false,
       HavePitch = false,
       HaveFallData = false,
       HaveFallDirection = false,
       HaveSplineElevation = false,
       HaveSpline = false;

   MovementStatusElements *sequence = GetMovementStatusElementsSequence(data.GetOpcode());
   if (sequence == NULL)
       return;

   BytesGuid guid;
   BytesGuid tguid;

   guid.guid = 0;
   tguid.guid = 0;

   for (uint32 i = 0; i < MSE_COUNT; i++)
   {
       MovementStatusElements element = sequence[i];

       if (element >= MSEGuidByte0 && element <= MSEGuidByte7)
       {
           data.ReadByteMask(guid.bytes[element - MSEGuidByte0]);
           continue;
       }

       if (element >= MSETransportGuidByte0 &&
           element <= MSETransportGuidByte7)
       {
           if (HaveTransportData)
               data.ReadByteMask(tguid.bytes[element - MSETransportGuidByte0]);
           continue;
       }

       if (element >= MSEGuidByte0_2 && element <= MSEGuidByte7_2)
       {
           data.ReadByteSeq(guid.bytes[element - MSEGuidByte0_2]);
           continue;
       }

       if (element >= MSETransportGuidByte0_2 &&
           element <= MSETransportGuidByte7_2)
       {
           if (HaveTransportData)
               data.ReadByteSeq(tguid.bytes[element - MSETransportGuidByte0_2]);
           continue;
       }

       switch (element)
       {
       case MSEFlags:
           mi->flags = data.ReadBits(30);
           break;
       case MSEFlags2:
           mi->flags2 = data.ReadBits(12);
           break;
       case MSETimestamp:
           data >> mi->time;
           break;
       case MSEHavePitch:
           HavePitch = data.ReadBit();
           break;
       case MSEHaveFallData:
           HaveFallData = data.ReadBit();
           break;
       case MSEHaveFallDirection:
           if (HaveFallData)
               HaveFallDirection = data.ReadBit();
           break;
       case MSEHaveTransportData:
           HaveTransportData = data.ReadBit();
           break;
       case MSETransportHaveTime2:
           if (HaveTransportData)
               HaveTransportTime2 = data.ReadBit();
           break;
       case MSETransportHaveTime3:
           if (HaveTransportData)
               HaveTransportTime3 = data.ReadBit();
           break;
       case MSEHaveSpline:
           HaveSpline = data.ReadBit();
           break;
       case MSEHaveSplineElev:
           HaveSplineElevation = data.ReadBit();
           break;
       case MSEPositionX:
           data >> mi->pos.PositionXYZStream();
           break;
       case MSEPositionY:
       case MSEPositionZ:
           break; // assume they always go as vector of 3
       case MSEPositionO:
           data >> mi->pos.m_orientation;
           break;
       case MSEPitch:
           if (HavePitch)
               data >> mi->pitch;
           break;
       case MSEFallTime:
           if (HaveFallData)
               data >> mi->fallTime;
           break;
       case MSESplineElev:
           if (HaveSplineElevation)
               data >> mi->splineElevation;
           break;
       case MSEFallHorizontalSpeed:
           if (HaveFallDirection)
               data >> mi->j_xyspeed;
           break;
       case MSEFallVerticalSpeed:
           if (HaveFallData)
               data >> mi->j_zspeed;
           break;
       case MSEFallCosAngle:
           if (HaveFallDirection)
               data >> mi->j_cosAngle;
           break;
       case MSEFallSinAngle:
           if (HaveFallDirection)
               data >> mi->j_sinAngle;
           break;
       case MSETransportSeat:
           if (HaveTransportData)
               data >> mi->t_seat;
           break;
       case MSETransportPositionO:
           if (HaveTransportData)
               data >> mi->t_pos.m_orientation;
           break;
       case MSETransportPositionX:
           if (HaveTransportData)
               data >> mi->t_pos.PositionXYZStream();
           break;
       case MSETransportPositionY:
       case MSETransportPositionZ:
           break; // assume they always go as vector of 3
       case MSETransportTime:
           if (HaveTransportData)
               data >> mi->t_time;
           break;
       case MSETransportTime2:
           if (HaveTransportTime2)
               data >> mi->t_time2;
           break;
       case MSETransportTime3:
           if (HaveTransportTime3)
               data >> mi->t_time3;
           break;
       default:
           WPError(false, "Incorrect sequence element detected at ReadMovementInfo");
       }
   }

   mi->guid = guid.guid;
   mi->t_guid = tguid.guid;

   if (HaveTransportData && mi->pos.m_positionX != mi->t_pos.m_positionX)
       if (GetPlayer()->GetTransport())
           GetPlayer()->GetTransport()->UpdatePosition(mi);
}

void WorldSession::WriteMovementInfo(WorldPacket &data, MovementInfo* mi)
{
    bool HaveTransportData = mi->HasMovementFlag(MOVEMENTFLAG_ONTRANSPORT),
       HaveTransportTime2 = (mi->flags2 & MOVEMENTFLAG2_INTERPOLATED_MOVEMENT) != 0,
       HaveTransportTime3 = false,
       HavePitch = (mi->HasMovementFlag(MovementFlags(MOVEMENTFLAG_SWIMMING | MOVEMENTFLAG_FLYING)))
       || (mi->flags2 & MOVEMENTFLAG2_ALWAYS_ALLOW_PITCHING),
       HaveFallData = mi->HasExtraMovementFlag(MOVEMENTFLAG2_INTERPOLATED_TURNING),
       HaveFallDirection = mi->HasMovementFlag(MOVEMENTFLAG_JUMPING),
       HaveSplineElevation = mi->HasMovementFlag(MOVEMENTFLAG_SPLINE_ELEVATION),
       HaveSpline = false;

   MovementStatusElements *sequence = GetMovementStatusElementsSequence(data.GetOpcode());
   if(!sequence)
       return;
   uint8 *guid = (uint8 *)&mi->guid;
   uint8 *tguid = (uint8 *)&mi->t_guid;
   for(uint32 i=0; i < MSE_COUNT; i++)
   {
       MovementStatusElements element = sequence[i];

       if (element >= MSEGuidByte0 && element <= MSEGuidByte7)
       {
           data.WriteByteMask(guid[element - MSEGuidByte0]);
           continue;
       }

       if (element >= MSETransportGuidByte0 &&
           element <= MSETransportGuidByte7)
       {
           if (HaveTransportData)
               data.WriteByteMask(tguid[element - MSETransportGuidByte0]);
           continue;
       }

       if (element >= MSEGuidByte0_2 && element <= MSEGuidByte7_2)
       {
           data.WriteByteSeq(guid[element - MSEGuidByte0_2]);
           continue;
       }

       if (element >= MSETransportGuidByte0_2 &&
           element <= MSETransportGuidByte7_2)
       {
           if (HaveTransportData)
               data.WriteByteSeq(tguid[element - MSETransportGuidByte0_2]);
           continue;
       }

       switch (element)
       {
       case MSEFlags:
           data.WriteBits(mi->flags, 30);
           break;
       case MSEFlags2:
           data.WriteBits(mi->flags2, 12);
           break;
       case MSETimestamp:
           data << mi->time;
           break;
       case MSEHavePitch:
           data.WriteBit(HavePitch);
           break;
       case MSEHaveFallData:
           data.WriteBit(HaveFallData);
           break;
       case MSEHaveFallDirection:
           if (HaveFallData)
               data.WriteBit(HaveFallDirection);
           break;
       case MSEHaveTransportData:
           data.WriteBit(HaveTransportData);
           break;
       case MSETransportHaveTime2:
           if (HaveTransportData)
               data.WriteBit(HaveTransportTime2);
           break;
       case MSETransportHaveTime3:
           if (HaveTransportData)
               data.WriteBit(HaveTransportTime3);
           break;
       case MSEHaveSpline:
           data.WriteBit(HaveSpline);
           break;
       case MSEHaveSplineElev:
           data.WriteBit(HaveSplineElevation);
           break;
       case MSEPositionX:
           data << mi->pos.PositionXYZStream();
           break;
       case MSEPositionY:
       case MSEPositionZ:
           break; // assume they always go as vector of 3
       case MSEPositionO:
           data << mi->pos.m_orientation;
           break;
       case MSEPitch:
           if (HavePitch)
               data << mi->pitch;
           break;
       case MSEFallTime:
           if (HaveFallData)
               data << mi->fallTime;
           break;
       case MSESplineElev:
           if (HaveSplineElevation)
               data << mi->splineElevation;
           break;
       case MSEFallHorizontalSpeed:
           if (HaveFallDirection)
               data << mi->j_xyspeed;
           break;
       case MSEFallVerticalSpeed:
           if (HaveFallData)
               data << mi->j_zspeed;
           break;
       case MSEFallCosAngle:
           if (HaveFallDirection)
               data << mi->j_cosAngle;
           break;
       case MSEFallSinAngle:
           if (HaveFallDirection)
               data << mi->j_sinAngle;
           break;
       case MSETransportSeat:
           if (HaveTransportData)
               data << mi->t_seat;
           break;
       case MSETransportPositionO:
           if (HaveTransportData)
               data << mi->t_pos.m_orientation;
           break;
       case MSETransportPositionX:
           if (HaveTransportData)
               data << mi->t_pos.PositionXYZStream();
           break;
       case MSETransportPositionY:
       case MSETransportPositionZ:
           break; // assume they always go as vector of 3
       case MSETransportTime:
           if (HaveTransportData)
               data << mi->t_time;
           break;
       case MSETransportTime2:
           if (HaveTransportTime2)
               data << mi->t_time2;
           break;
       case MSETransportTime3:
           if (HaveTransportTime3)
               data << mi->t_time3;
           break;
       default:
           WPError(false, "Incorrect sequence element detected at ReadMovementInfo");
       }
   }
}
