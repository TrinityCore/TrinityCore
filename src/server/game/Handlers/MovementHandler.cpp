/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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
#include "MapManager.h"
#include "Transport.h"
#include "Battleground.h"
#include "WaypointMovementGenerator.h"
#include "InstanceSaveMgr.h"
#include "ObjectMgr.h"
#include "Vehicle.h"
#include "World.h"
#include "WardenWin.h"
#include "Appender.h"

// Movement anticheat defines
//#define ANTICHEAT_DEBUG
#define ANTICHEAT_EXCEPTION_INFO
// End Movement anticheat defines

#define MOVEMENT_PACKET_TIME_DELAY 0

void WorldSession::HandleMoveWorldportAckOpcode(WorldPacket & /*recvData*/)
{
    TC_LOG_DEBUG("network", "WORLD: got MSG_MOVE_WORLDPORT_ACK.");
    HandleMoveWorldportAckOpcode();
}

void WorldSession::HandleMoveWorldportAckOpcode()
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
    InstanceTemplate const* mInstance = sObjectMgr->GetInstanceTemplate(loc.GetMapId());

    // reset instance validity, except if going to an instance inside an instance
    if (GetPlayer()->m_InstanceValid == false && !mInstance)
        GetPlayer()->m_InstanceValid = true;

    Map* oldMap = GetPlayer()->GetMap();
    Map* newMap = sMapMgr->CreateMap(loc.GetMapId(), GetPlayer());

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

    float z = loc.GetPositionZ();
    if (GetPlayer()->HasUnitMovementFlag(MOVEMENTFLAG_HOVER))
        z += GetPlayer()->GetFloatValue(UNIT_FIELD_HOVERHEIGHT);
    GetPlayer()->Relocate(loc.GetPositionX(), loc.GetPositionY(), z, loc.GetOrientation());

    GetPlayer()->ResetMap();
    GetPlayer()->SetMap(newMap);

    GetPlayer()->SendInitialPacketsBeforeAddToMap();
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
            FlightPathMovementGenerator* flight = (FlightPathMovementGenerator*)(GetPlayer()->GetMotionMaster()->top());
            flight->Initialize(GetPlayer());
            return;
        }

        // battleground state prepare, stop flight
        GetPlayer()->GetMotionMaster()->MovementExpired();
        GetPlayer()->CleanupAfterTaxiFlight();
    }

    // resurrect character at enter into instance where his corpse exist after add to map

    if (mEntry->IsDungeon() && !GetPlayer()->IsAlive())
        if (GetPlayer()->GetCorpseLocation().GetMapId() == mEntry->MapID)
        {
            GetPlayer()->ResurrectPlayer(0.5f, false);
            GetPlayer()->SpawnCorpseBones();
        }

    bool allowMount = !mEntry->IsDungeon() || mEntry->IsBattlegroundOrArena();
    if (mInstance)
    {
        // check if this instance has a reset time and send it to player if so
        Difficulty diff = GetPlayer()->GetDifficulty(mEntry->IsRaid());
        if (MapDifficulty const* mapDiff = GetMapDifficultyData(mEntry->MapID, diff))
        {
            if (mapDiff->resetTime)
            {
                if (time_t timeReset = sInstanceSaveMgr->GetResetTimeFor(mEntry->MapID, diff))
                {
                    uint32 timeleft = uint32(timeReset - time(NULL));
                    GetPlayer()->SendInstanceResetWarning(mEntry->MapID, diff, timeleft, true);
                }
            }
        }

        // check if instance is valid
        if (!GetPlayer()->CheckInstanceValidity(false))
            GetPlayer()->m_InstanceValid = false;

        // instance mounting is handled in InstanceTemplate
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

void WorldSession::HandleMoveTeleportAck(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "MSG_MOVE_TELEPORT_ACK");
    ObjectGuid guid;

    recvData >> guid.ReadAsPacked();

    uint32 flags, time;
    recvData >> flags >> time;

    Player* plrMover = _player->m_mover->ToPlayer();

    if (!plrMover || !plrMover->IsBeingTeleportedNear())
        return;

    if (guid != plrMover->GetGUID())
        return;

    plrMover->SetSemaphoreTeleportNear(false);

    uint32 old_zone = plrMover->GetZoneId();

    WorldLocation const& dest = plrMover->GetTeleportDest();

    plrMover->UpdatePosition(dest, true);

    uint32 newzone, newarea;
    plrMover->GetZoneAndAreaId(newzone, newarea);
    plrMover->UpdateZone(newzone, newarea);

    // new zone
    if (old_zone != newzone)
    {
        // honorless target
        if (plrMover->pvpInfo.IsHostile)
            plrMover->CastSpell(plrMover, 2479, true);

        // in friendly area
        else if (plrMover->IsPvP() && !plrMover->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_IN_PVP))
            plrMover->UpdatePvP(false, false);
    }

    // resummon pet
    GetPlayer()->ResummonPetTemporaryUnSummonedIfAny();

    //lets process all delayed operations on successful teleport
    GetPlayer()->ProcessDelayedOperations();
}

void WorldSession::HandleMovementOpcodes(WorldPacket & recvData)
{
    uint16 opcode = recvData.GetOpcode();

    Unit* mover = _player->m_mover;

    ASSERT(mover != NULL);                      // there must always be a mover

    Player* plrMover = mover->GetTypeId() == TYPEID_PLAYER ? (Player*)mover : NULL;
    Vehicle* vehMover = mover->GetVehicleKit();
    if (vehMover)
        if (mover->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PLAYER_CONTROLLED))
            if (Unit* charmer = mover->GetCharmer())
                if (charmer->GetTypeId() == TYPEID_PLAYER)
                    plrMover = (Player*)charmer;

    // ignore, waiting processing in WorldSession::HandleMoveWorldportAckOpcode and WorldSession::HandleMoveTeleportAck
    if (plrMover && plrMover->IsBeingTeleported())
    {
        recvData.rfinish();                     // prevent warnings spam
        return;
    }

    /* extract packet */
    ObjectGuid guid;

    recvData >> guid.ReadAsPacked();

    MovementInfo movementInfo;
    movementInfo.guid = guid;
    ReadMovementInfo(recvData, &movementInfo);

    recvData.rfinish();                         // prevent warnings spam

    // prevent tampered movement data
    if (guid != mover->GetGUID())
        return;

    if (!movementInfo.pos.IsPositionValid())
    {
        recvData.rfinish();                     // prevent warnings spam
        return;
    }

    /* handle special cases */
    if (movementInfo.HasMovementFlag(MOVEMENTFLAG_ONTRANSPORT))
    {
        // transports size limited
        // (also received at zeppelin leave by some reason with t_* as absolute in continent coordinates, can be safely skipped)
        if (movementInfo.transport.pos.GetPositionX() > 50 || movementInfo.transport.pos.GetPositionY() > 50 || movementInfo.transport.pos.GetPositionZ() > 50)
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
        if (plrMover && !plrMover->m_transport && !plrMover->m_temp_transport)
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

            if (!plrMover->m_transport)
                if (Map *tempMap = mover->GetMap())
                    if (GameObject *tempTransport = tempMap->GetGameObject(movementInfo.transport.guid))
                        if (tempTransport->IsTransport())
                            plrMover->m_temp_transport = tempTransport;
        if ((!plrMover && !mover->GetTransport() && !mover->GetVehicle()) || (plrMover && !plrMover->m_vehicle && !plrMover->m_transport && !plrMover->m_temp_transport)) // Not sure if the first part is needed. Just added it for verbosity.
        {
            GameObject* go = mover->GetMap()->GetGameObject(movementInfo.transport.guid);
            if (!go || go->GetGoType() != GAMEOBJECT_TYPE_TRANSPORT)
                movementInfo.RemoveMovementFlag(MOVEMENTFLAG_ONTRANSPORT);
        }
    }
    else if (plrMover && (plrMover->m_transport || plrMover->m_temp_transport)) // if we were on a transport, leave
    {
        if (plrMover->m_transport)
        {
            plrMover->m_transport->RemovePassenger(plrMover);
            plrMover->m_transport = NULL;
        }
        plrMover->m_temp_transport = NULL;
        movementInfo.transport.Reset();
    }

    // fall damage generation (ignore in flight case that can be triggered also at lags in moment teleportation to another map).
    if (opcode == MSG_MOVE_FALL_LAND && plrMover && !plrMover->IsInFlight())
    {
        // movement anticheat
        plrMover->m_anti_JumpCount = 0;
        plrMover->m_anti_JumpBaseZ = 0;
        if (!vehMover)
            plrMover->HandleFall(movementInfo);
    }

    if (plrMover && ((movementInfo.flags & MOVEMENTFLAG_SWIMMING) != 0) != plrMover->IsInWater())
    {
        // now client not include swimming flag in case jumping under water
        plrMover->SetInWater(!plrMover->IsInWater() || plrMover->GetBaseMap()->IsUnderWater(movementInfo.pos.GetPositionX(), movementInfo.pos.GetPositionY(), movementInfo.pos.GetPositionZ()));
    }

    uint32 mstime = getMSTime();
    /*----------------------*/
    if (m_clientTimeDelay == 0)
        m_clientTimeDelay = mstime - movementInfo.time;
    // begin anti cheat
    bool check_passed = true;
    #ifdef ANTICHEAT_DEBUG
   TC_LOG_WARN("cheat", "AC2-%s > time: %d fall-time: %d | xyzo: %f, %f, %fo(%f) flags[%X] opcode[%s] | transport (xyzo): %f, %f, %fo(%f)",
       plrMover->GetName(), movementInfo.time, movementInfo.fallTime, movementInfo.pos.m_positionX, movementInfo.pos.m_positionY, movementInfo.pos.m_positionZ, movementInfo.pos.m_orientation,
    movementInfo.flags, LookupOpcodeName(opcode), movementInfo.transport.pos.m_positionX, movementInfo.transport.pos.m_positionY, movementInfo.transport.pos.m_positionZ, movementInfo.transport.pos.m_orientation);
    TC_LOG_WARN("cheat", "AC2-%s Transport > GUID: (low)%d - (high)%d",
        plrMover->GetName(), GUID_LOPART(movementInfo.transport.guid), GUID_HIPART(movementInfo.transport.guid));
    #endif

    if (plrMover)
    {
        if (World::GetEnableMvAnticheat() && !plrMover->IsGameMaster() && !plrMover->GetCharmerOrOwnerPlayerOrPlayerItself()->IsGameMaster() && !plrMover->GetCharmerOrOwnerPlayerOrPlayerItself()->GetVehicle())
        {
            // calc time deltas
            int32 cClientTimeDelta = 1500;
            if (plrMover->m_anti_LastClientTime != 0)
            {
                cClientTimeDelta = movementInfo.time - plrMover->m_anti_LastClientTime;
                plrMover->m_anti_DeltaClientTime += cClientTimeDelta;
                plrMover->m_anti_LastClientTime = movementInfo.time;
            }
            else
                plrMover->m_anti_LastClientTime = movementInfo.time;

            const uint64 cServerTime = getMSTime();
            uint32 cServerTimeDelta = 1500;
            if (plrMover->m_anti_LastServerTime != 0)
            {
                cServerTimeDelta = cServerTime - plrMover->m_anti_LastServerTime;
                plrMover->m_anti_DeltaServerTime += cServerTimeDelta;
                plrMover->m_anti_LastServerTime = cServerTime;
            }
            else
                plrMover->m_anti_LastServerTime = cServerTime;

            // resync times on client login (first 15 sec for heavy areas)
            if (plrMover->m_anti_DeltaServerTime < 15000 && plrMover->m_anti_DeltaClientTime < 15000)
                plrMover->m_anti_DeltaClientTime = plrMover->m_anti_DeltaServerTime;

            const int32 sync_time = plrMover->m_anti_DeltaClientTime - plrMover->m_anti_DeltaServerTime;

            #ifdef ANTICHEAT_DEBUG
            TC_LOG_WARN("cheat", "AC2-%s Time > cClientTimeDelta: %d, cServerTime: %d | deltaC: %d - deltaS: %d | SyncTime: %d", plrMover->GetName(), cClientTimeDelta, cServerTime, plrMover->m_anti_DeltaClientTime, plrMover->m_anti_DeltaServerTime, sync_time);
            #endif

            // mistiming checks
            const int32 GetMistimingDelta = abs(int32(World::GetMistimingDelta()));
            if (sync_time > GetMistimingDelta)
            {
                cClientTimeDelta = cServerTimeDelta;
                ++(plrMover->m_anti_MistimingCount);

                const bool bMistimingModulo = plrMover->m_anti_MistimingCount % 50 == 0;

                if (bMistimingModulo)
                {
                    #ifdef ANTICHEAT_EXCEPTION_INFO
                    TC_LOG_WARN("cheat", "AC2-%s, mistiming exception #%d, mistiming: %dms Action: %s", plrMover->GetName().c_str(),  plrMover->m_anti_MistimingCount, sync_time, &Warden::Penalty);
                    #endif
                    check_passed = false;
                }
                //if (vehMover)
                //    vehMover->Die();
                // Tell the player "Sure, you can fly!"
                {
                    WorldPacket data(SMSG_MOVE_SET_CAN_FLY, 12);
                    data << plrMover->GetPackGUID();
                    data << uint32(0);
                    SendPacket(&data);
                }
                // Then tell the player "Wait, no, you can't."
                {
                    WorldPacket data(SMSG_MOVE_UNSET_CAN_FLY, 12);
                    data << plrMover->GetPackGUID();
                    data << uint32(0);
                    SendPacket(&data);
                }
                //plrMover->FallGround(2);

                /* Disabled, not passive at all, and apparently causing crashes:
                if (plrMover->m_anti_MistimingCount > World::GetMistimingAlarms())
                {
                    sWorld.SendWorldText(3, strcat("Kicking cheater: ", plrMover->GetName()));
                    KickPlayer();
                    return;
                } */
            }
            // end mistiming checks

            const uint32 curDest = plrMover->m_taxi.GetTaxiDestination(); // check taxi flight
            if (!curDest)
            {
                UnitMoveType move_type;

                // calculating section
                // current speed
                if (movementInfo.flags & MOVEMENTFLAG_FLYING)
                    move_type = movementInfo.flags & MOVEMENTFLAG_BACKWARD ? MOVE_FLIGHT_BACK : MOVE_FLIGHT;
                else if (movementInfo.flags & MOVEMENTFLAG_SWIMMING)
                    move_type = movementInfo.flags & MOVEMENTFLAG_BACKWARD ? MOVE_SWIM_BACK : MOVE_SWIM;
                else if (movementInfo.flags & MOVEMENTFLAG_WALKING)
                    move_type = MOVE_WALK;
                // hmm... in first time after login player has MOVE_SWIMBACK instead MOVE_WALKBACK
                else
                    move_type = movementInfo.flags & MOVEMENTFLAG_BACKWARD ? MOVE_SWIM_BACK : MOVE_RUN;

                const float current_speed = mover->GetSpeed(move_type);
                // end current speed

                // movement distance
                const float delta_x = plrMover->m_transport || plrMover->m_temp_transport ? 0 : plrMover->GetPositionX() - movementInfo.pos.GetPositionX();
                const float delta_y = plrMover->m_transport || plrMover->m_temp_transport ? 0 : plrMover->GetPositionY() - movementInfo.pos.GetPositionY();
                const float delta_z = plrMover->m_transport || plrMover->m_temp_transport ? 0 : plrMover->GetPositionZ() - movementInfo.pos.GetPositionZ();
                const float real_delta = plrMover->m_transport || plrMover->m_temp_transport ? 0 : pow(delta_x, 2) + pow(delta_y, 2);
                // end movement distance

                const bool no_fly_auras = !(plrMover->HasAuraType(SPELL_AURA_FLY) || plrMover->HasAuraType(SPELL_AURA_MOD_INCREASE_VEHICLE_FLIGHT_SPEED)
                    || plrMover->HasAuraType(SPELL_AURA_MOD_INCREASE_MOUNTED_FLIGHT_SPEED) || plrMover->HasAuraType(SPELL_AURA_MOD_INCREASE_FLIGHT_SPEED)
                    || plrMover->HasAuraType(SPELL_AURA_MOD_MOUNTED_FLIGHT_SPEED_ALWAYS) || plrMover->HasAuraType(SPELL_AURA_MOD_FLIGHT_SPEED_NOT_STACK));
                const bool no_fly_flags = (movementInfo.flags & (MOVEMENTFLAG_CAN_FLY | MOVEMENTFLAG_FLYING)) == 0;

                const bool no_swim_flags = (movementInfo.flags & MOVEMENTFLAG_SWIMMING) == 0;
                const bool no_swim_in_water = !mover->IsInWater();
                const bool no_swim_above_water = movementInfo.pos.GetPositionZ()-7.0f >= mover->GetBaseMap()->GetWaterLevel(movementInfo.pos.GetPositionX(),movementInfo.pos.GetPositionY());
                const bool no_swim_water = no_swim_in_water && no_swim_above_water;

                const bool no_waterwalk_flags = (movementInfo.flags & MOVEMENTFLAG_WATERWALKING) == 0;
                const bool no_waterwalk_auras = !(plrMover->HasAuraType(SPELL_AURA_WATER_WALK) || plrMover->HasAuraType(SPELL_AURA_GHOST));

                if (cClientTimeDelta < 0)
                    cClientTimeDelta = 0;
                const float time_delta = cClientTimeDelta < 1500 ? float(cClientTimeDelta)/1000.0f : 1.5f; // normalize time - 1.5 second allowed for heavy loaded server

                const float tg_z = (real_delta != 0 && no_fly_auras && no_swim_flags) ? (pow(delta_z, 2) / real_delta) : -99999; // movement distance tangents
	
                if (current_speed < plrMover->m_anti_Last_HSpeed && plrMover->m_anti_LastSpeedChangeTime == 0)
                    plrMover->m_anti_LastSpeedChangeTime = movementInfo.time + uint32(floor(((plrMover->m_anti_Last_HSpeed / current_speed) * 1500)) + 100); // 100ms above for random fluctuation

                const float allowed_delta = plrMover->m_transport || plrMover->m_temp_transport ? 2 : // movement distance allowed delta
                    pow(std::max(current_speed, plrMover->m_anti_Last_HSpeed) * time_delta, 2)
                    + 2                                                                             // minimum allowed delta
                    + (tg_z > 2.2 ? pow(delta_z, 2)/2.37f : 0);                                     // mountain fall allowed delta

                if (movementInfo.time > plrMover->m_anti_LastSpeedChangeTime)
                {
                    plrMover->m_anti_Last_HSpeed = current_speed;                                    // store current speed
                    plrMover->m_anti_Last_VSpeed = -2.3f;
                    plrMover->m_anti_LastSpeedChangeTime = 0;
                }
                // end calculating section

                // AntiGravity (thanks to Meekro)
                const float JumpHeight = plrMover->m_anti_JumpBaseZ - movementInfo.pos.GetPositionZ();
                if (no_fly_auras && no_swim_in_water && plrMover->m_anti_JumpBaseZ != 0 && JumpHeight < plrMover->m_anti_Last_VSpeed)
                {
                    #ifdef ANTICHEAT_EXCEPTION_INFO
                    TC_LOG_WARN("cheat", "AC2-%s, AntiGravity exception. JumpHeight = %f, Allowed Vertical Speed = %f",
                        plrMover->GetName().c_str(), JumpHeight, plrMover->m_anti_Last_VSpeed);
                    #endif
                    check_passed = false;
                    //if (vehMover)
                    //    vehMover->Die();
                    // Tell the player "Sure, you can fly!"
                    {
                        WorldPacket data(SMSG_MOVE_SET_CAN_FLY, 12);
                        data << plrMover->GetPackGUID();
                        data << uint32(0);
                        SendPacket(&data);
                    }
                    // Then tell the player "Wait, no, you can't."
                    {
                        WorldPacket data(SMSG_MOVE_UNSET_CAN_FLY, 12);
                        data << plrMover->GetPackGUID();
                        data << uint32(0);
                        SendPacket(&data);
                    }
                    //plrMover->FallGround(2);
                }

                // multi jump checks
                if (opcode == MSG_MOVE_JUMP)
                {
                    if (no_fly_auras && no_swim_water)
                    {
                        if (plrMover->m_anti_JumpCount >= 1)
                        {
                            // don't process new jump packet
                            check_passed = false;
                            #ifdef ANTICHEAT_EXCEPTION_INFO
                            TC_LOG_WARN("cheat", "AC2-%s, Multijump exception.", plrMover->GetName().c_str(), JumpHeight, plrMover->m_anti_Last_VSpeed);
                            #endif
                            //if (vehMover)
                            //    vehMover->Die();
                            // Tell the player "Sure, you can fly!"
                            {
                                WorldPacket data(SMSG_MOVE_SET_CAN_FLY, 12);
                               data << plrMover->GetPackGUID();
                                data << uint32(0);
                                SendPacket(&data);
                            }
                            // Then tell the player "Wait, no, you can't."
                            {
                                WorldPacket data(SMSG_MOVE_UNSET_CAN_FLY, 12);
                                data << plrMover->GetPackGUID();
                                data << uint32(0);
                                SendPacket(&data);
                            }
                            //plrMover->FallGround(2);
                            plrMover->m_anti_JumpCount = 0;
                        }
                        else
                        {
                            plrMover->m_anti_JumpCount += 1;
                            plrMover->m_anti_JumpBaseZ = movementInfo.pos.GetPositionZ();
                        }
                    } else
                        plrMover->m_anti_JumpCount = 0;
                }

                // speed and teleport hack checks
                if (real_delta > allowed_delta)
                {
                    #ifdef ANTICHEAT_EXCEPTION_INFO
                    if (real_delta < 4900.0f)
                    {
                        TC_LOG_WARN("cheat", "AC2-%s, speed exception | cDelta=%f aDelta=%f | cSpeed=%f lSpeed=%f deltaTime=%f", plrMover->GetName().c_str(), real_delta, allowed_delta, current_speed, plrMover->m_anti_Last_HSpeed, time_delta);
                    } else {
                        TC_LOG_WARN("cheat", "AC2-%s, teleport exception | cDelta=%f aDelta=%f | cSpeed=%f lSpeed=%f deltaTime=%f", plrMover->GetName().c_str(), real_delta, allowed_delta, current_speed, plrMover->m_anti_Last_HSpeed, time_delta);
                    }
                    #endif
                    check_passed = false;
                    //if (vehMover)
                    //    vehMover->Die();
                    //plrMover->FallGround(2);
                }

                // mountain hack checks // 1.56f (delta_z < GetPlayer()->m_anti_Last_VSpeed))
                if (delta_z < plrMover->m_anti_Last_VSpeed && plrMover->m_anti_JumpCount == 0 && tg_z > 2.37f)
                {
                    #ifdef ANTICHEAT_EXCEPTION_INFO
                    TC_LOG_WARN("cheat", "AC2-%s, mountain exception | tg_z=%f", plrMover->GetName().c_str(), tg_z);
                    #endif
                    check_passed = false;
                //    if (vehMover)
                //        vehMover->Die();
                }
				
                // Fly hack checks
                if (no_fly_auras && !no_fly_flags)
                {
                    #ifdef ANTICHEAT_EXCEPTION_INFO // Aura numbers: 201, 206, 207, 208, 209, 211
                    //TC_LOG_WARN("cheat", "AC2-%s, flight exception. {SPELL_AURA_FLY=[%X]} {SPELL_AURA_MOD_INCREASE_MOUNTED_FLIGHT_SPEED=[%X]} {SPELL_AURA_MOD_INCREASE_FLIGHT_SPEED=[%X]} {SPELL_AURA_MOD_MOUNTED_FLIGHT_SPEED_ALWAYS=[%X]} {SPELL_AURA_MOD_FLIGHT_SPEED_NOT_STACK=[%X]} {plrMover->GetVehicle()=[%X]}",
                        plrMover->GetName().c_str(),
    					 //Last Updated By ShopWoW.ir                    
						 plrMover->HasAuraType(SPELL_AURA_FLY), plrMover->HasAuraType(SPELL_AURA_MOD_INCREASE_MOUNTED_FLIGHT_SPEED),
                        plrMover->HasAuraType(SPELL_AURA_MOD_INCREASE_FLIGHT_SPEED), plrMover->HasAuraType(SPELL_AURA_MOD_MOUNTED_FLIGHT_SPEED_ALWAYS),
                        plrMover->HasAuraType(SPELL_AURA_MOD_FLIGHT_SPEED_NOT_STACK), plrMover->GetVehicle();
                    #endif
                    check_passed = false;
                    //if (vehMover)
                    //    vehMover->Die();
                    // Tell the player "Sure, you can fly!"
                    {
                        WorldPacket data(SMSG_MOVE_SET_CAN_FLY, 12);
                        data << plrMover->GetPackGUID();
                        data << uint32(0);
                        SendPacket(&data);
                    }
                    // Then tell the player "Wait, no, you can't."
                    {
                        WorldPacket data(SMSG_MOVE_UNSET_CAN_FLY, 12);
                        data << plrMover->GetPackGUID();
                        data << uint32(0);
                        SendPacket(&data);
                    }
                    //plrMover->FallGround(2);
                }

                // Waterwalk checks
                if (no_waterwalk_auras && !no_waterwalk_flags)
                {
                    #ifdef ANTICHEAT_EXCEPTION_INFO
                    TC_LOG_WARN("cheat", "AC2-%s, waterwalk exception. [%X]{SPELL_AURA_WATER_WALK=[%X]}",
                        plrMover->GetName().c_str(), movementInfo.flags, plrMover->HasAuraType(SPELL_AURA_WATER_WALK));
                    #endif
                    check_passed = false;
                    //if (vehMover)
                    //    vehMover->Die();
                    // Tell the player "Sure, you can fly!"
                    {
                        WorldPacket data(SMSG_MOVE_SET_CAN_FLY, 12);
                        data << plrMover->GetPackGUID();
                        data << uint32(0);
                        SendPacket(&data);
                    }
                    // Then tell the player "Wait, no, you can't."
                    {
                        WorldPacket data(SMSG_MOVE_UNSET_CAN_FLY, 12);
                        data << plrMover->GetPackGUID();
                        data << uint32(0);
                        SendPacket(&data);
                    }
                    //plrMover->FallGround(2);
                }

                // Teleport To Plane checks
                if (no_swim_in_water && movementInfo.pos.GetPositionZ() < 0.0001f && movementInfo.pos.GetPositionZ() > -0.0001f)
                {
                    if (const Map *map = plrMover->GetMap())
                    {
                        float plane_z = map->GetHeight(movementInfo.pos.GetPositionX(), movementInfo.pos.GetPositionY(), MAX_HEIGHT) - movementInfo.pos.GetPositionZ();
                        plane_z = (plane_z < -500.0f) ? 0.0f : plane_z; // check holes in height map
                        if (plane_z > 0.1f || plane_z < -0.1f)
                        {
                            #ifdef ANTICHEAT_DEBUG
                            TC_LOG_WARN("cheat", "AC2-%s, teleport to plane exception. plane_z: %f", plrMover->GetName(), plane_z);
                            #endif
                            #ifdef ANTICHEAT_EXCEPTION_INFO
                            if (plrMover->m_anti_TeleToPlane_Count > World::GetTeleportToPlaneAlarms())
                            {
                                TC_LOG_WARN("cheat", "AC2-%s, teleport to plane exception. Exception count: %d", plrMover->GetName().c_str(), plrMover->m_anti_TeleToPlane_Count);
                                /* Disabled, not passive at all, and apparently causing crashes:
                                sWorld.SendWorldText(3, strcat("Kicking cheater: ", plrMover->GetName()));
                                KickPlayer();
                                return; */
                            }
                            #endif
                            ++(plrMover->m_anti_TeleToPlane_Count);
                            check_passed = false;
                            //if (vehMover)
                            //    vehMover->Die();
                        }
                    }
                }
                else
                    plrMover->m_anti_TeleToPlane_Count = 0;
            }
        }
    }
     /* process position-change */
    if (check_passed)
    {
    WorldPacket data(opcode, recvData.size());
    movementInfo.time = movementInfo.time + m_clientTimeDelay + MOVEMENT_PACKET_TIME_DELAY;

    movementInfo.guid = mover->GetGUID();
    WriteMovementInfo(&data, &movementInfo);
    mover->SendMessageToSet(&data, _player);

    mover->m_movementInfo = movementInfo;

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

    mover->UpdatePosition(movementInfo.pos);

    if (plrMover && !vehMover)                               // nothing is charmed, or player charmed
    {
        if (plrMover->IsSitState() && (movementInfo.flags & (MOVEMENTFLAG_MASK_MOVING | MOVEMENTFLAG_MASK_TURNING)))
            plrMover->SetStandState(UNIT_STAND_STATE_STAND);

        plrMover->UpdateFallInformationIfNeed(movementInfo, opcode);

        float underMapValueZ;

        switch (plrMover->GetMapId())
        {
            case 617: underMapValueZ = 3.0f; break; // Dalaran Sewers
            case 618: underMapValueZ = 28.0f; break; // Ring of Valor
            default: underMapValueZ = -500.0f; break;
        }

        if (movementInfo.pos.GetPositionZ() < plrMover->GetMap()->GetMinHeight(movementInfo.pos.GetPositionX(), movementInfo.pos.GetPositionY()) || movementInfo.pos.GetPositionZ() < underMapValueZ)
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
                    if (!plrMover->IsAlive())
                        plrMover->KillPlayer();
                }
            }
        }
        // movement anticheat
        if (plrMover->m_anti_AlarmCount > 0)
        {
            TC_LOG_WARN("cheat", "AC2-%s produce %d anticheat alarms.", plrMover->GetName().c_str(), plrMover->m_anti_AlarmCount);
            plrMover->m_anti_AlarmCount = 0;
        }
        // end movement anticheat
     }		
    }
    else if (plrMover)
    {
        if (plrMover->m_transport)
        {
            plrMover->m_transport->RemovePassenger(plrMover);
            plrMover->m_transport = NULL;
        }
        plrMover->m_temp_transport = NULL;
        ++(plrMover->m_anti_AlarmCount);
        WorldPacket data;
        plrMover->SetUnitMovementFlags(0);
        plrMover->SendTeleportAckPacket();
        plrMover->BuildHeartBeatMsg(&data);
        plrMover->SendMessageToSet(&data, true);
    }
		
}

void WorldSession::HandleForceSpeedChangeAck(WorldPacket &recvData)
{
    /* extract packet */
    ObjectGuid guid;
    uint32 unk1;
    float  newspeed;

    recvData >> guid.ReadAsPacked();

    // now can skip not our packet
    if (_player->GetGUID() != guid)
    {
        recvData.rfinish();                   // prevent warnings spam
        return;
    }

    // continue parse packet

    recvData >> unk1;                                      // counter or moveEvent

    MovementInfo movementInfo;
    movementInfo.guid = guid;
    ReadMovementInfo(recvData, &movementInfo);

    recvData >> newspeed;
    /*----------------*/

    // client ACK send one packet for mounted/run case and need skip all except last from its
    // in other cases anti-cheat check can be fail in false case
    UnitMoveType move_type;
    UnitMoveType force_move_type;

    static char const* move_type_name[MAX_MOVE_TYPE] = {  "Walk", "Run", "RunBack", "Swim", "SwimBack", "TurnRate", "Flight", "FlightBack", "PitchRate" };

    switch (recvData.GetOpcode())
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
            TC_LOG_ERROR("network", "WorldSession::HandleForceSpeedChangeAck: Unknown move type opcode: %u", recvData.GetOpcode());
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

    if (!_player->GetTransport() && std::fabs(_player->GetSpeed(move_type) - newspeed) > 0.01f)
    {
        if (_player->GetSpeed(move_type) > newspeed)         // must be greater - just correct
        {
            TC_LOG_ERROR("network", "%sSpeedChange player %s is NOT correct (must be %f instead %f), force set to correct value",
                move_type_name[move_type], _player->GetName().c_str(), _player->GetSpeed(move_type), newspeed);
            _player->SetSpeedRate(move_type, _player->GetSpeedRate(move_type));
        }
        else                                                // must be lesser - cheating
        {
            TC_LOG_DEBUG("misc", "Player %s from account id %u kicked for incorrect speed (must be %f instead %f)",
                _player->GetName().c_str(), _player->GetSession()->GetAccountId(), _player->GetSpeed(move_type), newspeed);
            _player->GetSession()->KickPlayer();
        }
    }
}

void WorldSession::HandleSetActiveMoverOpcode(WorldPacket &recvData)
{
    TC_LOG_DEBUG("network", "WORLD: Recvd CMSG_SET_ACTIVE_MOVER");

    ObjectGuid guid;
    recvData >> guid;

    if (GetPlayer()->IsInWorld())
        if (_player->m_mover->GetGUID() != guid)
            TC_LOG_DEBUG("network", "HandleSetActiveMoverOpcode: incorrect mover guid: mover is %s and should be %s" , guid.ToString().c_str(), _player->m_mover->GetGUID().ToString().c_str());
}

void WorldSession::HandleMoveNotActiveMover(WorldPacket &recvData)
{
    TC_LOG_DEBUG("network", "WORLD: Recvd CMSG_MOVE_NOT_ACTIVE_MOVER");

    ObjectGuid old_mover_guid;
    recvData >> old_mover_guid.ReadAsPacked();

    MovementInfo mi;
    ReadMovementInfo(recvData, &mi);

    mi.guid = old_mover_guid;

    _player->m_movementInfo = mi;
}

void WorldSession::HandleMountSpecialAnimOpcode(WorldPacket& /*recvData*/)
{
    WorldPacket data(SMSG_MOUNTSPECIAL_ANIM, 8);
    data << uint64(GetPlayer()->GetGUID());

    GetPlayer()->SendMessageToSet(&data, false);
}

void WorldSession::HandleMoveKnockBackAck(WorldPacket & recvData)
{
    TC_LOG_DEBUG("network", "CMSG_MOVE_KNOCK_BACK_ACK");

    ObjectGuid guid;
    recvData >> guid.ReadAsPacked();

    if (_player->m_mover->GetGUID() != guid)
        return;

    recvData.read_skip<uint32>();                          // unk

    MovementInfo movementInfo;
    ReadMovementInfo(recvData, &movementInfo);
	
    // Save movement flags
    _player->SetUnitMovementFlags(movementInfo.flags);
    #ifdef ANTICHEAT_DEBUG
    TC_LOG_WARN("cheat", "%s CMSG_MOVE_KNOCK_BACK_ACK: time: %d, fall time: %d | xyzo: %f,%f,%fo(%f) flags[%X] Vspeed: %f, Hspeed: %f", GetPlayer()->GetName(), movementInfo.time, movementInfo.fallTime, movementInfo.pos.m_positionX, movementInfo.pos.m_positionY, movementInfo.pos.m_positionZ, movementInfo.pos.m_orientation, movementInfo.flags, movementInfo.jump.zspeed, movementInfo.jump.xyspeed);
    #endif
	
    _player->m_movementInfo = movementInfo;
    _player->m_anti_Last_HSpeed = movementInfo.jump.xyspeed;
    _player->m_anti_Last_VSpeed = movementInfo.jump.zspeed < 3.2f ? movementInfo.jump.zspeed - 1.0f : 3.2f;

    const uint32 dt = (_player->m_anti_Last_VSpeed < 0) ? int(ceil(_player->m_anti_Last_VSpeed/-25)*1000) : int(ceil(_player->m_anti_Last_VSpeed/25)*1000);
    _player->m_anti_LastSpeedChangeTime = movementInfo.time + dt + 1000;
	
    WorldPacket data(MSG_MOVE_KNOCK_BACK, 66);
    data << guid.WriteAsPacked();
    _player->BuildMovementPacket(&data);

    // knockback specific info
    data << movementInfo.jump.sinAngle;
    data << movementInfo.jump.cosAngle;
    data << movementInfo.jump.xyspeed;
    data << movementInfo.jump.zspeed;

    _player->SendMessageToSet(&data, false);
}

void WorldSession::HandleMoveHoverAck(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "CMSG_MOVE_HOVER_ACK");

    ObjectGuid guid;                                        // guid - unused
    recvData >> guid.ReadAsPacked();

    recvData.read_skip<uint32>();                           // unk

    MovementInfo movementInfo;
    ReadMovementInfo(recvData, &movementInfo);

    recvData.read_skip<uint32>();                           // unk2
}

void WorldSession::HandleMoveWaterWalkAck(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "CMSG_MOVE_WATER_WALK_ACK");

    ObjectGuid guid;                                        // guid - unused
    recvData >> guid.ReadAsPacked();

    recvData.read_skip<uint32>();                           // unk

    MovementInfo movementInfo;
    ReadMovementInfo(recvData, &movementInfo);

    recvData.read_skip<uint32>();                           // unk2
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
