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

#include "AnticheatMgr.h"
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
#include "World.h"
	
#define ANTICHEAT_EXCEPTION_INFO

void WorldSession::HandleMoveWorldportAckOpcode(WorldPacket & /*recv_data*/)
{
    sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: got MSG_MOVE_WORLDPORT_ACK.");
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
    sLog->outDebug(LOG_FILTER_NETWORKIO, "MSG_MOVE_TELEPORT_ACK");
    uint64 guid;

    recv_data.readPackGUID(guid);

    uint32 flags, time;
    recv_data >> flags >> time;
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
	Vehicle *vehMover = mover->GetVehicleKit();	
    if (vehMover)	
        if (mover->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PLAYER_CONTROLLED))	
            if (Unit *charmer = mover->GetCharmer())	
                if (charmer->GetTypeId() == TYPEID_PLAYER)	
                    plMover = (Player*)charmer;

    // ignore, waiting processing in WorldSession::HandleMoveWorldportAckOpcode and WorldSession::HandleMoveTeleportAck
    if (plMover && plMover->IsBeingTeleported())
    {
        recv_data.rfinish();                   // prevent warnings spam
        return;
    }

    /* extract packet */
    uint64 guid;

    recv_data.readPackGUID(guid);

    MovementInfo movementInfo;
    movementInfo.guid = guid;
    ReadMovementInfo(recv_data, &movementInfo);

    recv_data.rfinish();                   // prevent warnings spam

    // prevent tampered movement data
    if (guid != mover->GetGUID())
        return;

    if (!movementInfo.pos.IsPositionValid())
    {
        recv_data.rfinish();                   // prevent warnings spam
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
        if (plMover && !plMover->m_transport && !plMover->m_temp_transport)
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
			if (!plMover->m_transport)	
                if (Map *tempMap = mover->GetMap())	
                    if (GameObject *tempTransport = tempMap->GetGameObject(movementInfo.t_guid))	
                        if (tempTransport->IsTransport())	
                            plMover->m_temp_transport = tempTransport;
        }

        if ((!plMover && !mover->GetTransport() && !mover->GetVehicle()) || (plMover && !plMover->m_vehicle && !plMover->m_transport && !plMover->m_temp_transport))
        {
            GameObject* go = mover->GetMap()->GetGameObject(movementInfo.t_guid);
            if (!go || go->GetGoType() != GAMEOBJECT_TYPE_TRANSPORT)
                movementInfo.flags &= ~MOVEMENTFLAG_ONTRANSPORT;
        }
    }
    else if (plMover && (plMover->m_transport || plMover->m_temp_transport))               // if we were on a transport, leave
    {
        if (plMover->m_transport)	
        {	
            plMover->m_transport->RemovePassenger(plMover);	
            plMover->m_transport = NULL;	
        }	
        plMover->m_temp_transport = NULL;        movementInfo.t_pos.Relocate(0.0f, 0.0f, 0.0f, 0.0f);
        movementInfo.t_time = 0;
        movementInfo.t_seat = -1;
    }

    // fall damage generation (ignore in flight case that can be triggered also at lags in moment teleportation to another map).
    if (opcode == MSG_MOVE_FALL_LAND && plMover && !plMover->isInFlight())
    {	
	
        plMover->m_anti_JumpCount = 0;	
        plMover->m_anti_JumpBaseZ = 0;	
        if (!vehMover)	
            plMover->HandleFall(movementInfo);	
    }

    if (plMover && ((movementInfo.flags & MOVEMENTFLAG_SWIMMING) != 0) != plMover->IsInWater())
    {
        // now client not include swimming flag in case jumping under water
        plMover->SetInWater(!plMover->IsInWater() || plMover->GetBaseMap()->IsUnderWater(movementInfo.pos.GetPositionX(), movementInfo.pos.GetPositionY(), movementInfo.pos.GetPositionZ()));
    }

    if (plMover)
        sAnticheatMgr->StartHackDetection(plMover, movementInfo, opcode);

    /*----------------------*/
    bool check_passed = true;	
    #ifdef ANTICHEAT_DEBUG	
    sLog.outBasic("AntiCheat By jacob-%s > time: %d fall-time: %d | xyzo: %f, %f, %fo(%f) flags[%X] opcode[%s] | transport (xyzo): %f, %f, %fo(%f)",	
        plMover->GetName(), movementInfo.time, movementInfo.fallTime, movementInfo.x, movementInfo.y, movementInfo.z, movementInfo.o,	
        movementInfo.flags, LookupOpcodeName(opcode), movementInfo.t_x, movementInfo.t_y, movementInfo.t_z, movementInfo.t_o);	
    sLog.outBasic("Anticheat By jacob-%s Transport > GUID: (low)%d - (high)%d",	
        plMover->GetName(), GUID_LOPART(movementInfo.t_guid), GUID_HIPART(movementInfo.t_guid));	
    #endif	
	
    if (plMover)	
    {	
        if (World::GetEnableMvAnticheat() && !plMover->GetCharmerOrOwnerPlayerOrPlayerItself()->isGameMaster())	
        {	
	
            int32 cClientTimeDelta = 1500;	
            if (plMover->m_anti_LastClientTime != 0)	
            {	
                cClientTimeDelta = movementInfo.time - plMover->m_anti_LastClientTime;	
                plMover->m_anti_DeltaClientTime += cClientTimeDelta;	
                plMover->m_anti_LastClientTime = movementInfo.time;	
            }	
            else	
                plMover->m_anti_LastClientTime = movementInfo.time;

    /* process position-change */
	         const uint64 cServerTime = getMSTime();	
            uint32 cServerTimeDelta = 1500;	
            if (plMover->m_anti_LastServerTime != 0)	
            {	
                cServerTimeDelta = cServerTime - plMover->m_anti_LastServerTime;	
                plMover->m_anti_DeltaServerTime += cServerTimeDelta;	
                plMover->m_anti_LastServerTime = cServerTime;	
            }	
            else	
                plMover->m_anti_LastServerTime = cServerTime;	
		
            if (plMover->m_anti_DeltaServerTime < 15000 && plMover->m_anti_DeltaClientTime < 15000)	
                plMover->m_anti_DeltaClientTime = plMover->m_anti_DeltaServerTime;	
	
            const int32 sync_time = plMover->m_anti_DeltaClientTime - plMover->m_anti_DeltaServerTime;	
	
            #ifdef ANTICHEAT_DEBUG	
            sLog.outBasic("Anticheat By jacob-%s Time > cClientTimeDelta: %d, cServerTime: %d | deltaC: %d - deltaS: %d | SyncTime: %d", plMover->GetName(), cClientTimeDelta, cServerTime, plMover->m_anti_DeltaClientTime, plMover->m_anti_DeltaServerTime, sync_time);	
            #endif	
		
            const int32 GetMistimingDelta = abs(int32(World::GetMistimingDelta()));	
            if (sync_time > GetMistimingDelta)	
            {	
                cClientTimeDelta = cServerTimeDelta;	
                ++(plMover->m_anti_MistimingCount);	
	
                const bool bMistimingModulo = plMover->m_anti_MistimingCount % 50 == 0;	
	
                if (bMistimingModulo)	
                {	
                    #ifdef ANTICHEAT_EXCEPTION_INFO	
                    sLog->outError("Anticheat By jacob-%s, mistiming exception #%d, mistiming: %dms", plMover->GetName(), plMover->m_anti_MistimingCount, sync_time);	
                    #endif	
                    check_passed = false;	
                }
	
                {	
                    WorldPacket data(SMSG_MOVE_SET_CAN_FLY, 12);	
                    data.append(plMover->GetPackGUID());	
                    data << uint32(0);	
                    SendPacket(&data);	
                }	

                {	
                    WorldPacket data(SMSG_MOVE_UNSET_CAN_FLY, 12);	
                    data.append(plMover->GetPackGUID());	
                    data << uint32(0);	
                    SendPacket(&data);	
                }		
	

            }		
	
            const uint32 curDest = plMover->m_taxi.GetTaxiDestination(); // check taxi flight
	
            if (!curDest)	
            {	
                UnitMoveType move_type;	
		
                if (movementInfo.flags & MOVEMENTFLAG_FLYING)	
                    move_type = movementInfo.flags & MOVEMENTFLAG_BACKWARD ? MOVE_FLIGHT_BACK : MOVE_FLIGHT;	
                else if (movementInfo.flags & MOVEMENTFLAG_SWIMMING)	
                    move_type = movementInfo.flags & MOVEMENTFLAG_BACKWARD ? MOVE_SWIM_BACK : MOVE_SWIM;	
                else if (movementInfo.flags & MOVEMENTFLAG_WALKING)	
                    move_type = MOVE_WALK;		
                else	
                    move_type = movementInfo.flags & MOVEMENTFLAG_BACKWARD ? MOVE_SWIM_BACK : MOVE_RUN;	
	
                const float current_speed = mover->GetSpeed(move_type);		
		
                const float delta_x = plMover->m_transport || plMover->m_temp_transport ? 0 : plMover->GetPositionX() - movementInfo.pos.GetPositionX();	
                const float delta_y = plMover->m_transport || plMover->m_temp_transport ? 0 : plMover->GetPositionY() - movementInfo.pos.GetPositionY();	
                const float delta_z = plMover->m_transport || plMover->m_temp_transport ? 0 : plMover->GetPositionZ() - movementInfo.pos.GetPositionZ();	
                const float real_delta = plMover->m_transport || plMover->m_temp_transport ? 0 : pow(delta_x, 2) + pow(delta_y, 2);		
	
                const bool no_fly_auras = !(plMover->HasAuraType(SPELL_AURA_FLY) || plMover->HasAuraType(SPELL_AURA_MOD_INCREASE_VEHICLE_FLIGHT_SPEED)	
                    || plMover->HasAuraType(SPELL_AURA_MOD_INCREASE_MOUNTED_FLIGHT_SPEED) || plMover->HasAuraType(SPELL_AURA_MOD_INCREASE_FLIGHT_SPEED)	
                    || plMover->HasAuraType(SPELL_AURA_MOD_MOUNTED_FLIGHT_SPEED_ALWAYS) || plMover->HasAuraType(SPELL_AURA_MOD_FLIGHT_SPEED_NOT_STACK));	
                const bool no_fly_flags = (movementInfo.flags & (MOVEMENTFLAG_CAN_FLY | MOVEMENTFLAG_FLYING)) == 0;	
	
                const bool no_swim_flags = (movementInfo.flags & MOVEMENTFLAG_SWIMMING) == 0;	
                const bool no_swim_in_water = !mover->IsInWater();	
                const bool no_swim_above_water = movementInfo.pos.GetPositionZ()-7.0f >= mover->GetBaseMap()->GetWaterLevel(movementInfo.pos.GetPositionX(),movementInfo.pos.GetPositionY());	
                const bool no_swim_water = no_swim_in_water && no_swim_above_water;	
	
                const bool no_waterwalk_flags = (movementInfo.flags & MOVEMENTFLAG_WATERWALKING) == 0;	
                const bool no_waterwalk_auras = !(plMover->HasAuraType(SPELL_AURA_WATER_WALK) || plMover->HasAuraType(SPELL_AURA_GHOST));	
	
                if (cClientTimeDelta < 0)	
                    cClientTimeDelta = 0;	
                const float time_delta = cClientTimeDelta < 1500 ? float(cClientTimeDelta)/1000.0f : 1.5f; 	
	
                const float tg_z = (real_delta != 0 && no_fly_auras && no_swim_flags) ? (pow(delta_z, 2) / real_delta) : -99999; 	
	
                if (current_speed < plMover->m_anti_Last_HSpeed && plMover->m_anti_LastSpeedChangeTime == 0)	
                    plMover->m_anti_LastSpeedChangeTime = movementInfo.time + uint32(floor(((plMover->m_anti_Last_HSpeed / current_speed) * 1500)) + 100); 	
	
                const float allowed_delta = plMover->m_transport || plMover->m_temp_transport ? 2 : 	
                    pow(std::max(current_speed, plMover->m_anti_Last_HSpeed) * time_delta, 2)	
                    + 2                                                                            	
                    + (tg_z > 2.2 ? pow(delta_z, 2)/2.37f : 0);                                     	
	
                if (movementInfo.time > plMover->m_anti_LastSpeedChangeTime)	
                {	
                    plMover->m_anti_Last_HSpeed = current_speed;                                    	
                    plMover->m_anti_Last_VSpeed = -2.3f;	
                    plMover->m_anti_LastSpeedChangeTime = 0;	
                }	
	
                const float JumpHeight = plMover->m_anti_JumpBaseZ - movementInfo.pos.GetPositionZ();	
                if (no_fly_auras && no_swim_in_water && plMover->m_anti_JumpBaseZ != 0 && JumpHeight < plMover->m_anti_Last_VSpeed)	
                {	
                    #ifdef ANTICHEAT_EXCEPTION_INFO	
                    sLog->outError("Anticheat By jacob-%s, AntiGravity exception. JumpHeight = %f, Allowed Vertical Speed = %f",	
                        plMover->GetName(), JumpHeight, plMover->m_anti_Last_VSpeed);	
                    #endif	
                    check_passed = false;	
	
                    {	
                        WorldPacket data(SMSG_MOVE_SET_CAN_FLY, 12);	
                        data.append(plMover->GetPackGUID());	
                        data << uint32(0);	
                        SendPacket(&data);	
                    }	
	
                    {	
                        WorldPacket data(SMSG_MOVE_UNSET_CAN_FLY, 12);	
                        data.append(plMover->GetPackGUID());	
                        data << uint32(0);	
                        SendPacket(&data);	
                    }	
	
                }	
		
                if (opcode == MSG_MOVE_JUMP)	
                {	
                    if (no_fly_auras && no_swim_water)	
                    {	
                        if (plMover->m_anti_JumpCount >= 1)	
                        {		
                            check_passed = false;		
                            {	
                                WorldPacket data(SMSG_MOVE_SET_CAN_FLY, 12);	
                                data.append(plMover->GetPackGUID());	
                                data << uint32(0);	
                                SendPacket(&data);	
                            }	
                            {
                                WorldPacket data(SMSG_MOVE_UNSET_CAN_FLY, 12);
                                data.append(plMover->GetPackGUID());	
                                data << uint32(0);	
                                SendPacket(&data);	
                            }		
                            plMover->m_anti_JumpCount = 0;	
                        }	
                        else	
                        {	
                            plMover->m_anti_JumpCount += 1;	
                            plMover->m_anti_JumpBaseZ = movementInfo.pos.GetPositionZ();	
                        }	
                    } else	
                        plMover->m_anti_JumpCount = 0;	
                }	
	
                if (real_delta > allowed_delta)	
                {	
                    #ifdef ANTICHEAT_EXCEPTION_INFO	
                    if (real_delta < 4900.0f)	
                        sLog->outError("Anticheat By jacob-%s, speed exception | cDelta=%f aDelta=%f | cSpeed=%f lSpeed=%f deltaTime=%f", plMover->GetName(), real_delta, allowed_delta, current_speed, plMover->m_anti_Last_HSpeed, time_delta);	
                    else	
                        sLog->outError("Anticheat By jacob-%s, teleport exception | cDelta=%f aDelta=%f | cSpeed=%f lSpeed=%f deltaTime=%f", plMover->GetName(), real_delta, allowed_delta, current_speed, plMover->m_anti_Last_HSpeed, time_delta);	
                    #endif	
                    check_passed = false;
		
                }	
		
                if (delta_z < plMover->m_anti_Last_VSpeed && plMover->m_anti_JumpCount == 0 && tg_z > 2.37f)	
                {	
                    #ifdef ANTICHEAT_EXCEPTION_INFO	
                    sLog->outError("Anticheat By jacob-%s, mountain exception | tg_z=%f", plMover->GetName(), tg_z);	
                    #endif	
                    check_passed = false;	
	
                }	
			
                if (no_fly_auras && !no_fly_flags)
                {	
                    #ifdef ANTICHEAT_EXCEPTION_INFO 	
                    sLog->outError("Anticheat By jacob-%s, flight exception. {SPELL_AURA_FLY=[%X]} {SPELL_AURA_MOD_INCREASE_MOUNTED_FLIGHT_SPEED=[%X]} {SPELL_AURA_MOD_INCREASE_FLIGHT_SPEED=[%X]} {SPELL_AURA_MOD_MOUNTED_FLIGHT_SPEED_ALWAYS=[%X]} {SPELL_AURA_MOD_FLIGHT_SPEED_NOT_STACK=[%X]} {plMover->GetVehicle()=[%X]}",	
                        plMover->GetName(),	
                        plMover->HasAuraType(SPELL_AURA_FLY), plMover->HasAuraType(SPELL_AURA_MOD_INCREASE_MOUNTED_FLIGHT_SPEED),	
                        plMover->HasAuraType(SPELL_AURA_MOD_INCREASE_FLIGHT_SPEED), plMover->HasAuraType(SPELL_AURA_MOD_MOUNTED_FLIGHT_SPEED_ALWAYS),	
                        plMover->HasAuraType(SPELL_AURA_MOD_FLIGHT_SPEED_NOT_STACK), plMover->GetVehicle());	
                    #endif	
                    check_passed = false;
	
                    {	
                        WorldPacket data(SMSG_MOVE_SET_CAN_FLY, 12);	
                        data.append(plMover->GetPackGUID());	
                        data << uint32(0);	
                        SendPacket(&data);	
                    }	
	 
                    {	
                        WorldPacket data(SMSG_MOVE_UNSET_CAN_FLY, 12);	
                        data.append(plMover->GetPackGUID());	
                        data << uint32(0);	
                        SendPacket(&data);	
                    }	
                }	
		
                if (no_waterwalk_auras && !no_waterwalk_flags)	
                {	
                    #ifdef ANTICHEAT_EXCEPTION_INFO	
                    sLog->outError("Anticheat By jacob-%s, waterwalk exception. [%X]{SPELL_AURA_WATER_WALK=[%X]}",	
                        plMover->GetName(), movementInfo.flags, plMover->HasAuraType(SPELL_AURA_WATER_WALK));	
                    #endif	
                    check_passed = false;		
                    {	
                        WorldPacket data(SMSG_MOVE_SET_CAN_FLY, 12);	
                        data.append(plMover->GetPackGUID());	
                        data << uint32(0);	
                        SendPacket(&data);	
                    }
	
                    {	
                        WorldPacket data(SMSG_MOVE_UNSET_CAN_FLY, 12);	
                        data.append(plMover->GetPackGUID());	
                        data << uint32(0);	
                        SendPacket(&data);	
                    }	

                }	
	
                if (no_swim_in_water && movementInfo.pos.GetPositionZ() < 0.0001f && movementInfo.pos.GetPositionZ() > -0.0001f)	
                {	
                    if (const Map *map = plMover->GetMap())	
                    {	
                        float plane_z = map->GetHeight(movementInfo.pos.GetPositionX(), movementInfo.pos.GetPositionY(), MAX_HEIGHT) - movementInfo.pos.GetPositionZ();	
                        plane_z = (plane_z < -500.0f) ? 0.0f : plane_z; 	
                        if (plane_z > 0.1f || plane_z < -0.1f)	
                        {	
                            #ifdef ANTICHEAT_DEBUG	
                            sLog->outDebug("Anticheat By jacob-%s, teleport to plane exception. plane_z: %f", plMover->GetName(), plane_z);	
                            #endif	
                            #ifdef ANTICHEAT_EXCEPTION_INFO	
                            if (plMover->m_anti_TeleToPlane_Count > World::GetTeleportToPlaneAlarms())	
                            {	
                                sLog->outError("Anticheat By jacob-%s, teleport to plane exception. Exception count: %d", plMover->GetName(), plMover->m_anti_TeleToPlane_Count);	

                            }	
                            #endif	
                            ++(plMover->m_anti_TeleToPlane_Count);	
                            check_passed = false;

	
                        }	
                    }	
                }
                else	
                    plMover->m_anti_TeleToPlane_Count = 0;	
            }
        }	
    }
		
    if (check_passed)	
    {
    WorldPacket data(opcode, recv_data.size());
    movementInfo.time = getMSTime();
    movementInfo.guid = mover->GetGUID();
    WriteMovementInfo(&data, &movementInfo);
    mover->SendMessageToSet(&data, _player);

    mover->m_movementInfo = movementInfo;

    // this is almost never true (not sure why it is sometimes, but it is), normally use mover->IsVehicle()
    if (mover->GetVehicle())
    {
        mover->SetOrientation(movementInfo.pos.GetOrientation());
        return;
    }

    mover->UpdatePosition(movementInfo.pos);

    if (plMover && !vehMover)                               // nothing is charmed, or player charmed
    {
        plMover->UpdateFallInformationIfNeed(movementInfo, opcode);

        float underMapValueZ;

        switch (plMover->GetMapId())
        {
            case 617: underMapValueZ = 3.0f; break; // Dalaran Sewers
            case 618: underMapValueZ = 28.0f; break; // Ring of Valor
            default: underMapValueZ = -500.0f; break;
        }

        if (movementInfo.pos.GetPositionZ() < underMapValueZ)
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
        if (plMover->m_anti_AlarmCount > 0)	
        {	
            sLog->outError("Anticheat By jacob-%s produce %d anticheat alarms", plMover->GetName(), plMover->m_anti_AlarmCount);
            plMover->m_anti_AlarmCount = 0;
        }		
     }	
    }	
    else if (plMover)	
    {	
        if (plMover->m_transport)	
        {	
            plMover->m_transport->RemovePassenger(plMover);	
            plMover->m_transport = NULL;	
        }	
        plMover->m_temp_transport = NULL;	
        ++(plMover->m_anti_AlarmCount);	
        WorldPacket data;	
        plMover->SetUnitMovementFlags(0);	
        plMover->SendTeleportAckPacket();	
        plMover->BuildHeartBeatMsg(&data);	
        plMover->SendMessageToSet(&data, true);
    }
	
}

void WorldSession::HandleForceSpeedChangeAck(WorldPacket &recv_data)
{
    uint32 opcode = recv_data.GetOpcode();
    sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: Recvd %s (%u, 0x%X) opcode", LookupOpcodeName(opcode), opcode, opcode);

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
	
    _player->SetUnitMovementFlags(movementInfo.flags);	
    #ifdef ANTICHEAT_DEBUG	
    sLog->outBasic("%s CMSG_MOVE_KNOCK_BACK_ACK: time: %d, fall time: %d | xyzo: %f,%f,%fo(%f) flags[%X]", GetPlayer()->GetName(), movementInfo.time, movementInfo.fallTime, movementInfo.x, movementInfo.y, movementInfo.z, movementInfo.o, movementInfo.flags);	
    sLog->outBasic("%s CMSG_MOVE_KNOCK_BACK_ACK additional: Vspeed: %f, Hspeed: %f", GetPlayer()->GetName(), movementInfo.j_unk, movementInfo.j_xyspeed);	
    #endif
	
    _player->m_movementInfo = movementInfo;	
    _player->m_anti_Last_HSpeed = movementInfo.j_xyspeed;	
    _player->m_anti_Last_VSpeed = movementInfo.j_zspeed < 3.2f ? movementInfo.j_zspeed - 1.0f : 3.2f;	
	
    const uint32 dt = (_player->m_anti_Last_VSpeed < 0) ? int(ceil(_player->m_anti_Last_VSpeed/-25)*1000) : int(ceil(_player->m_anti_Last_VSpeed/25)*1000);	
    _player->m_anti_LastSpeedChangeTime = movementInfo.time + dt + 1000;

    recv_data >> newspeed;
    /*----------------*/

    // client ACK send one packet for mounted/run case and need skip all except last from its
    // in other cases anti-cheat check can be fail in false case
    UnitMoveType move_type;
    UnitMoveType force_move_type;

    static char const* move_type_name[MAX_MOVE_TYPE] = {  "Walk", "Run", "RunBack", "Swim", "SwimBack", "TurnRate", "Flight", "FlightBack", "PitchRate" };

    switch (opcode)
    {
        case CMSG_FORCE_WALK_SPEED_CHANGE_ACK:          move_type = MOVE_WALK;          force_move_type = MOVE_WALK;        break;
        case CMSG_FORCE_RUN_SPEED_CHANGE_ACK:           move_type = MOVE_RUN;           force_move_type = MOVE_RUN;         break;
        case CMSG_FORCE_RUN_BACK_SPEED_CHANGE_ACK:      move_type = MOVE_RUN_BACK;      force_move_type = MOVE_RUN_BACK;    break;
        case CMSG_FORCE_SWIM_SPEED_CHANGE_ACK:          move_type = MOVE_SWIM;          force_move_type = MOVE_SWIM;        break;
        case CMSG_FORCE_SWIM_BACK_SPEED_CHANGE_ACK:     move_type = MOVE_SWIM_BACK;     force_move_type = MOVE_SWIM_BACK;   break;
        case CMSG_FORCE_TURN_RATE_CHANGE_ACK:           move_type = MOVE_TURN_RATE;     force_move_type = MOVE_TURN_RATE;   break;
        case CMSG_FORCE_FLIGHT_SPEED_CHANGE_ACK:        move_type = MOVE_FLIGHT;        force_move_type = MOVE_FLIGHT;      break;
        case CMSG_FORCE_FLIGHT_BACK_SPEED_CHANGE_ACK:   move_type = MOVE_FLIGHT_BACK;   force_move_type = MOVE_FLIGHT_BACK; break;
        case CMSG_FORCE_PITCH_RATE_CHANGE_ACK:          move_type = MOVE_PITCH_RATE;    force_move_type = MOVE_PITCH_RATE;  break;
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
        if (_player->m_mover->GetGUID() != guid)
            sLog->outError("HandleSetActiveMoverOpcode: incorrect mover guid: mover is " UI64FMTD " (%s - Entry: %u) and should be " UI64FMTD, guid, GetLogNameForGuid(guid), GUID_ENPART(guid), _player->m_mover->GetGUID());
    }
}

void WorldSession::HandleMoveNotActiveMover(WorldPacket &recv_data)
{
    sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: Recvd CMSG_MOVE_NOT_ACTIVE_MOVER");

    uint64 old_mover_guid;
    recv_data.readPackGUID(old_mover_guid);

    MovementInfo mi;
    ReadMovementInfo(recv_data, &mi);

    mi.guid = old_mover_guid;

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

    WorldPacket data(MSG_MOVE_KNOCK_BACK, 66);
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

    uint64 summoner_guid;
    bool agree;
    recv_data >> summoner_guid;
    recv_data >> agree;

    _player->SummonIfPossible(agree);
}
