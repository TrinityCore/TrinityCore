/*
 * Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
 *
 * Copyright (C) 2008 Trinity <http://www.trinitycore.org/>
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

#include "Common.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "Opcodes.h"
#include "Log.h"
#include "World.h"
#include "Corpse.h"
#include "Player.h"
#include "MapManager.h"
#include "Transports.h"
#include "BattleGround.h"
#include "WaypointMovementGenerator.h"
#include "InstanceSaveMgr.h"

void WorldSession::HandleMoveWorldportAckOpcode( WorldPacket & /*recv_data*/ )
{
    sLog.outDebug( "WORLD: got MSG_MOVE_WORLDPORT_ACK." );
    HandleMoveWorldportAckOpcode();
}

void WorldSession::HandleMoveWorldportAckOpcode()
{
    // get the teleport destination
    WorldLocation &loc = GetPlayer()->GetTeleportDest();

    // possible errors in the coordinate validity check
    if(!MapManager::IsValidMapCoord(loc.mapid,loc.x,loc.y,loc.z,loc.o))
    {
        LogoutPlayer(false);
        return;
    }

    // get the destination map entry, not the current one, this will fix homebind and reset greeting
    MapEntry const* mEntry = sMapStore.LookupEntry(loc.mapid);
    InstanceTemplate const* mInstance = objmgr.GetInstanceTemplate(loc.mapid);

    // reset instance validity, except if going to an instance inside an instance
    if(GetPlayer()->m_InstanceValid == false && !mInstance)
        GetPlayer()->m_InstanceValid = true;

    GetPlayer()->SetSemaphoreTeleport(false);

    // relocate the player to the teleport destination
    GetPlayer()->SetMapId(loc.mapid);
    GetPlayer()->Relocate(loc.x, loc.y, loc.z, loc.o);

    // since the MapId is set before the GetInstance call, the InstanceId must be set to 0
    // to let GetInstance() determine the proper InstanceId based on the player's binds
    GetPlayer()->SetInstanceId(0);

    // check this before Map::Add(player), because that will create the instance save!
    bool reset_notify = (GetPlayer()->GetBoundInstance(GetPlayer()->GetMapId(), GetPlayer()->GetDifficulty()) == NULL);

    GetPlayer()->SendInitialPacketsBeforeAddToMap();
    // the CanEnter checks are done in TeleporTo but conditions may change
    // while the player is in transit, for example the map may get full
    if(!GetPlayer()->GetMap()->Add(GetPlayer()))
    {
        sLog.outDebug("WORLD: teleport of player %s (%d) to location %d,%f,%f,%f,%f failed", GetPlayer()->GetName(), GetPlayer()->GetGUIDLow(), loc.mapid, loc.x, loc.y, loc.z, loc.o);
        // teleport the player home
        GetPlayer()->SetDontMove(false);
        if(!GetPlayer()->TeleportTo(GetPlayer()->m_homebindMapId, GetPlayer()->m_homebindX, GetPlayer()->m_homebindY, GetPlayer()->m_homebindZ, GetPlayer()->GetOrientation()))
        {
            // the player must always be able to teleport home
            sLog.outError("WORLD: failed to teleport player %s (%d) to homebind location %d,%f,%f,%f,%f!", GetPlayer()->GetName(), GetPlayer()->GetGUIDLow(), GetPlayer()->m_homebindMapId, GetPlayer()->m_homebindX, GetPlayer()->m_homebindY, GetPlayer()->m_homebindZ, GetPlayer()->GetOrientation());
            assert(false);
        }
        return;
    }
    GetPlayer()->SendInitialPacketsAfterAddToMap();

    // flight fast teleport case
    if(GetPlayer()->GetMotionMaster()->GetCurrentMovementGeneratorType()==FLIGHT_MOTION_TYPE)
    {
        if(!_player->InBattleGround())
        {
            // short preparations to continue flight
            GetPlayer()->SetDontMove(false);
            FlightPathMovementGenerator* flight = (FlightPathMovementGenerator*)(GetPlayer()->GetMotionMaster()->top());
            flight->Initialize(*GetPlayer());
            return;
        }

        // battleground state prepare, stop flight
        GetPlayer()->GetMotionMaster()->MovementExpired();
        GetPlayer()->m_taxi.ClearTaxiDestinations();
    }

    // resurrect character at enter into instance where his corpse exist after add to map
    Corpse *corpse = GetPlayer()->GetCorpse();
    if (corpse && corpse->GetType() != CORPSE_BONES && corpse->GetMapId() == GetPlayer()->GetMapId())
    {
        if( mEntry->IsDungeon() )
        {
            GetPlayer()->ResurrectPlayer(0.5f,false);
            GetPlayer()->SpawnCorpseBones();
            GetPlayer()->SaveToDB();
        }
    }

    if(mEntry->IsRaid() && mInstance)
    {
        if(reset_notify)
        {
            uint32 timeleft = sInstanceSaveManager.GetResetTimeFor(GetPlayer()->GetMapId()) - time(NULL);
            GetPlayer()->SendInstanceResetWarning(GetPlayer()->GetMapId(), timeleft); // greeting at the entrance of the resort raid instance
        }
    }

    // mount allow check
    if(!mEntry->IsMountAllowed())
        _player->RemoveSpellsCausingAura(SPELL_AURA_MOUNTED);

    // battleground state prepare
    // only add to bg group and object, if the player was invited (else he entered through command)
    if(_player->InBattleGround() && _player->IsInvitedForBattleGroundInstance(_player->GetBattleGroundId()))
    {
        BattleGround *bg = _player->GetBattleGround();
        if(bg)
        {
            bg->AddPlayer(_player);
            if(bg->GetMapId() == _player->GetMapId())       // we teleported to bg
            {
                // get the team this way, because arenas might 'override' the teams.
                uint32 team = bg->GetPlayerTeam(_player->GetGUID());
                if(!team)
                    team = _player->GetTeam();
                if(!bg->GetBgRaid(team))      // first player joined
                {
                    Group *group = new Group;
                    bg->SetBgRaid(team, group);
                    group->Create(_player->GetGUIDLow(), _player->GetName());
                }
                else                                        // raid already exist
                {
                    bg->GetBgRaid(team)->AddMember(_player->GetGUID(), _player->GetName());
                }
            }
        }
    }

    // honorless target
    if(GetPlayer()->pvpInfo.inHostileArea)
        GetPlayer()->CastSpell(GetPlayer(), 2479, true);

    // resummon pet
    if(GetPlayer()->m_temporaryUnsummonedPetNumber)
    {
        Pet* NewPet = new Pet;
        if(!NewPet->LoadPetFromDB(GetPlayer(), 0, GetPlayer()->m_temporaryUnsummonedPetNumber, true))
            delete NewPet;

        GetPlayer()->m_temporaryUnsummonedPetNumber = 0;
    }

    GetPlayer()->SetDontMove(false);
}

void WorldSession::HandleMovementOpcodes( WorldPacket & recv_data )
{
    CHECK_PACKET_SIZE(recv_data, 4+1+4+4+4+4+4);

    /* extract packet */
    MovementInfo movementInfo;
    uint32 MovementFlags;

    recv_data >> MovementFlags;
    recv_data >> movementInfo.unk1;
    recv_data >> movementInfo.time;
    recv_data >> movementInfo.x;
    recv_data >> movementInfo.y;
    recv_data >> movementInfo.z;
    recv_data >> movementInfo.o;

    if(MovementFlags & MOVEMENTFLAG_ONTRANSPORT)
    {
        // recheck
        CHECK_PACKET_SIZE(recv_data, recv_data.rpos()+8+4+4+4+4+4);

        recv_data >> movementInfo.t_guid;
        recv_data >> movementInfo.t_x;
        recv_data >> movementInfo.t_y;
        recv_data >> movementInfo.t_z;
        recv_data >> movementInfo.t_o;
        recv_data >> movementInfo.t_time;
    }

    if(MovementFlags & (MOVEMENTFLAG_SWIMMING | MOVEMENTFLAG_FLYING2))
    {
        // recheck
        CHECK_PACKET_SIZE(recv_data, recv_data.rpos()+4);

        recv_data >> movementInfo.s_pitch;                  // pitch, -1.55=looking down, 0=looking straight forward, +1.55=looking up
    }

    // recheck
    CHECK_PACKET_SIZE(recv_data, recv_data.rpos()+4);

    recv_data >> movementInfo.fallTime;                     // duration of last jump (when in jump duration from jump begin to now)

    if(MovementFlags & MOVEMENTFLAG_JUMPING)
    {
        // recheck
        CHECK_PACKET_SIZE(recv_data, recv_data.rpos()+4+4+4+4);

        recv_data >> movementInfo.j_unk;                    // constant, but different when jumping in water and on land?
        recv_data >> movementInfo.j_sinAngle;               // sin of angle between orientation0 and players orientation
        recv_data >> movementInfo.j_cosAngle;               // cos of angle between orientation0 and players orientation
        recv_data >> movementInfo.j_xyspeed;                // speed of xy movement
    }

    if(MovementFlags & MOVEMENTFLAG_SPLINE)
    {
        // recheck
        CHECK_PACKET_SIZE(recv_data, recv_data.rpos()+4);

        recv_data >> movementInfo.u_unk1;                   // unknown
    }
    /*----------------*/

    if(recv_data.size() != recv_data.rpos())
    {
        sLog.outError("MovementHandler: player %s (guid %d, account %u) sent a packet (opcode %u) that is %u bytes larger than it should be. Kicked as cheater.", _player->GetName(), _player->GetGUIDLow(), _player->GetSession()->GetAccountId(), recv_data.GetOpcode(), recv_data.size() - recv_data.rpos());
        KickPlayer();
        return;
    }

    if (!Trinity::IsValidMapCoord(movementInfo.x, movementInfo.y, movementInfo.z, movementInfo.o))
        return;

    // Handle possessed unit movement separately
    Unit* pos_unit = GetPlayer()->GetCharm();
    if (pos_unit && pos_unit->isPossessed()) // can be charmed but not possessed
    {
        HandlePossessedMovement(recv_data, movementInfo, MovementFlags);
        return;
    }

    if (GetPlayer()->GetDontMove())
        return;

    //Save movement flags
    GetPlayer()->SetUnitMovementFlags(MovementFlags);

    /* handle special cases */
    if (MovementFlags & MOVEMENTFLAG_ONTRANSPORT)
    {
        // transports size limited
        // (also received at zeppelin leave by some reason with t_* as absolute in continent coordinates, can be safely skipped)
        if( movementInfo.t_x > 50 || movementInfo.t_y > 50 || movementInfo.t_z > 50 )
            return;

        if( !Trinity::IsValidMapCoord(movementInfo.x+movementInfo.t_x, movementInfo.y+movementInfo.t_y,
            movementInfo.z+movementInfo.t_z, movementInfo.o+movementInfo.t_o) )
            return;

        // if we boarded a transport, add us to it
        if (!GetPlayer()->m_transport)
        {
            // elevators also cause the client to send MOVEMENTFLAG_ONTRANSPORT - just unmount if the guid can be found in the transport list
            for (MapManager::TransportSet::iterator iter = MapManager::Instance().m_Transports.begin(); iter != MapManager::Instance().m_Transports.end(); ++iter)
            {
                if ((*iter)->GetGUID() == movementInfo.t_guid)
                {
                    // unmount before boarding
                    GetPlayer()->RemoveSpellsCausingAura(SPELL_AURA_MOUNTED);

                    GetPlayer()->m_transport = (*iter);
                    (*iter)->AddPassenger(GetPlayer());
                    break;
                }
            }
        }
    }
    else if (GetPlayer()->m_transport)                      // if we were on a transport, leave
    {
        GetPlayer()->m_transport->RemovePassenger(GetPlayer());
        GetPlayer()->m_transport = NULL;
        movementInfo.t_x = 0.0f;
        movementInfo.t_y = 0.0f;
        movementInfo.t_z = 0.0f;
        movementInfo.t_o = 0.0f;
        movementInfo.t_time = 0;
    }

    // fall damage generation (ignore in flight case that can be triggered also at lags in moment teleportation to another map).
    if (recv_data.GetOpcode() == MSG_MOVE_FALL_LAND && !GetPlayer()->isInFlight())
        GetPlayer()->HandleFallDamage(movementInfo);

    if(((MovementFlags & MOVEMENTFLAG_SWIMMING) != 0) != GetPlayer()->IsInWater())
    {
        // now client not include swimming flag in case jumping under water
        GetPlayer()->SetInWater( !GetPlayer()->IsInWater() || GetPlayer()->GetBaseMap()->IsUnderWater(movementInfo.x, movementInfo.y, movementInfo.z) );
    }

    /*----------------------*/

    /* process position-change */
    recv_data.put<uint32>(5, getMSTime());                  // offset flags(4) + unk(1)
    WorldPacket data(recv_data.GetOpcode(), (GetPlayer()->GetPackGUID().size()+recv_data.size()));
    data.append(GetPlayer()->GetPackGUID());
    data.append(recv_data.contents(), recv_data.size());
    GetPlayer()->SendMessageToSet(&data, false);

    GetPlayer()->SetPosition(movementInfo.x, movementInfo.y, movementInfo.z, movementInfo.o);
    GetPlayer()->m_movementInfo = movementInfo;
    if (GetPlayer()->m_lastFallTime >= movementInfo.fallTime || GetPlayer()->m_lastFallZ <=movementInfo.z || recv_data.GetOpcode() == MSG_MOVE_FALL_LAND)
        GetPlayer()->SetFallInformation(movementInfo.fallTime, movementInfo.z);

    if(GetPlayer()->isMovingOrTurning())
        GetPlayer()->RemoveSpellsCausingAura(SPELL_AURA_FEIGN_DEATH);

    if(movementInfo.z < -500.0f)
        GetPlayer()->HandleFallUnderMap();
}

void WorldSession::HandlePossessedMovement(WorldPacket& recv_data, MovementInfo& movementInfo, uint32& MovementFlags)
{
    // Whatever the client is controlling, it will send the GUID of the original player.
    // If current player is controlling, it must be handled like the controlled player sent these opcodes

    Unit* pos_unit = GetPlayer()->GetCharm();

    if (pos_unit->GetTypeId() == TYPEID_PLAYER && ((Player*)pos_unit)->GetDontMove())
        return;

    //Save movement flags
    pos_unit->SetUnitMovementFlags(MovementFlags);

    // Remove possession if possessed unit enters a transport
    if (MovementFlags & MOVEMENTFLAG_ONTRANSPORT)
    {
        GetPlayer()->Uncharm();
        return;
    }

    recv_data.put<uint32>(5, getMSTime());
    WorldPacket data(recv_data.GetOpcode(), pos_unit->GetPackGUID().size()+recv_data.size());
    data.append(pos_unit->GetPackGUID());
    data.append(recv_data.contents(), recv_data.size());
    // Send the packet to self but not to the possessed player; for creatures the first bool is irrelevant
    pos_unit->SendMessageToSet(&data, true, false);

    // Possessed is a player
    if (pos_unit->GetTypeId() == TYPEID_PLAYER)
    {
        Player* plr = (Player*)pos_unit;

        if (recv_data.GetOpcode() == MSG_MOVE_FALL_LAND)
            plr->HandleFallDamage(movementInfo);

        if(((MovementFlags & MOVEMENTFLAG_SWIMMING) != 0) != plr->IsInWater())
        {
            // Now client not include swimming flag in case jumping under water
            plr->SetInWater( !plr->IsInWater() || plr->GetBaseMap()->IsUnderWater(movementInfo.x, movementInfo.y, movementInfo.z) );
        }

        plr->SetPosition(movementInfo.x, movementInfo.y, movementInfo.z, movementInfo.o, false);
        plr->m_movementInfo = movementInfo;

        if(plr->isMovingOrTurning())
            plr->RemoveSpellsCausingAura(SPELL_AURA_FEIGN_DEATH);

        if(movementInfo.z < -500.0f)
        {
            GetPlayer()->Uncharm();
            plr->HandleFallUnderMap();
        }
    }
    else // Possessed unit is a creature
    {
        Map* map = MapManager::Instance().GetMap(pos_unit->GetMapId(), pos_unit);
        map->CreatureRelocation((Creature*)pos_unit, movementInfo.x, movementInfo.y, movementInfo.z, movementInfo.o);
    }
}

void WorldSession::HandleForceSpeedChangeAck(WorldPacket &recv_data)
{
    CHECK_PACKET_SIZE(recv_data, 8+4+4+1+4+4+4+4+4);

    /* extract packet */
    uint64 guid;
    uint8  unkB;
    uint32 unk1, flags, time, fallTime;
    float x, y, z, orientation;

    uint64 t_GUID;
    float  t_x, t_y, t_z, t_o;
    uint32 t_time;
    float  s_pitch;
    float  j_unk1, j_sinAngle, j_cosAngle, j_xyspeed;
    float  u_unk1;
    float  newspeed;

    recv_data >> guid;

    // now can skip not our packet
    if(_player->GetGUID() != guid)
        return;

    // continue parse packet

    recv_data >> unk1;
    recv_data >> flags >> unkB >> time;
    recv_data >> x >> y >> z >> orientation;
    if (flags & MOVEMENTFLAG_ONTRANSPORT)
    {
        // recheck
        CHECK_PACKET_SIZE(recv_data, recv_data.rpos()+8+4+4+4+4+4);

        recv_data >> t_GUID;
        recv_data >> t_x >> t_y >> t_z >> t_o >> t_time;
    }
    if (flags & (MOVEMENTFLAG_SWIMMING | MOVEMENTFLAG_FLYING2))
    {
        // recheck
        CHECK_PACKET_SIZE(recv_data, recv_data.rpos()+4);

        recv_data >> s_pitch;                               // pitch, -1.55=looking down, 0=looking straight forward, +1.55=looking up
    }

    // recheck
    CHECK_PACKET_SIZE(recv_data, recv_data.rpos()+4);

    recv_data >> fallTime;                                  // duration of last jump (when in jump duration from jump begin to now)

    if ((flags & MOVEMENTFLAG_JUMPING) || (flags & MOVEMENTFLAG_FALLING))
    {
        // recheck
        CHECK_PACKET_SIZE(recv_data, recv_data.rpos()+4+4+4+4);

        recv_data >> j_unk1;                                // ?constant, but different when jumping in water and on land?
        recv_data >> j_sinAngle >> j_cosAngle;              // sin + cos of angle between orientation0 and players orientation
        recv_data >> j_xyspeed;                             // speed of xy movement
    }

    if(flags & MOVEMENTFLAG_SPLINE)
    {
        // recheck
        CHECK_PACKET_SIZE(recv_data, recv_data.rpos()+4);

        recv_data >> u_unk1;                                // unknown
    }

    // recheck
    CHECK_PACKET_SIZE(recv_data, recv_data.rpos()+4);

    recv_data >> newspeed;
    /*----------------*/

    // client ACK send one packet for mounted/run case and need skip all except last from its
    // in other cases anti-cheat check can be fail in false case
    UnitMoveType move_type;
    UnitMoveType force_move_type;

    static char const* move_type_name[MAX_MOVE_TYPE] = {  "Walk", "Run", "RunBack", "Swim", "SwimBack", "TurnRate", "Flight", "FlightBack" };

    uint16 opcode = recv_data.GetOpcode();
    switch(opcode)
    {
        case CMSG_FORCE_WALK_SPEED_CHANGE_ACK:          move_type = MOVE_WALK;          force_move_type = MOVE_WALK;        break;
        case CMSG_FORCE_RUN_SPEED_CHANGE_ACK:           move_type = MOVE_RUN;           force_move_type = MOVE_RUN;         break;
        case CMSG_FORCE_RUN_BACK_SPEED_CHANGE_ACK:      move_type = MOVE_RUN_BACK;      force_move_type = MOVE_RUN_BACK;    break;
        case CMSG_FORCE_SWIM_SPEED_CHANGE_ACK:          move_type = MOVE_SWIM;          force_move_type = MOVE_SWIM;        break;
        case CMSG_FORCE_SWIM_BACK_SPEED_CHANGE_ACK:     move_type = MOVE_SWIM_BACK;     force_move_type = MOVE_SWIM_BACK;   break;
        case CMSG_FORCE_TURN_RATE_CHANGE_ACK:           move_type = MOVE_TURN_RATE;     force_move_type = MOVE_TURN_RATE;   break;
        case CMSG_FORCE_FLIGHT_SPEED_CHANGE_ACK:        move_type = MOVE_FLIGHT;        force_move_type = MOVE_FLIGHT;      break;
        case CMSG_FORCE_FLIGHT_BACK_SPEED_CHANGE_ACK:   move_type = MOVE_FLIGHT_BACK;   force_move_type = MOVE_FLIGHT_BACK; break;
        default:
            sLog.outError("WorldSession::HandleForceSpeedChangeAck: Unknown move type opcode: %u", opcode);
            return;
    }

    // skip all forced speed changes except last and unexpected
    // in run/mounted case used one ACK and it must be skipped.m_forced_speed_changes[MOVE_RUN} store both.
    if(_player->m_forced_speed_changes[force_move_type] > 0)
    {
        --_player->m_forced_speed_changes[force_move_type];
        if(_player->m_forced_speed_changes[force_move_type] > 0)
            return;
    }

    if (!_player->GetTransport() && fabs(_player->GetSpeed(move_type) - newspeed) > 0.01f)
    {
        if(_player->GetSpeed(move_type) > newspeed)         // must be greater - just correct
        {
            sLog.outError("%sSpeedChange player %s is NOT correct (must be %f instead %f), force set to correct value",
                move_type_name[move_type], _player->GetName(), _player->GetSpeed(move_type), newspeed);
            _player->SetSpeed(move_type,_player->GetSpeedRate(move_type),true);
        }
        else                                                // must be lesser - cheating
        {
            sLog.outBasic("Player %s from account id %u kicked for incorrect speed (must be %f instead %f)",
                _player->GetName(),_player->GetSession()->GetAccountId(),_player->GetSpeed(move_type), newspeed);
            _player->GetSession()->KickPlayer();
        }
    }
}

void WorldSession::HandleSetActiveMoverOpcode(WorldPacket &recv_data)
{
    sLog.outDebug("WORLD: Recvd CMSG_SET_ACTIVE_MOVER");

    CHECK_PACKET_SIZE(recv_data,8);

    uint64 guid;
    recv_data >> guid;

    WorldPacket data(SMSG_TIME_SYNC_REQ, 4);                // new 2.0.x, enable movement
    data << uint32(0x00000000);                             // on blizz it increments periodically
    SendPacket(&data);
}

void WorldSession::HandleNotActiveMoverOpcode(WorldPacket& /*recv_data*/)
{
    sLog.outDebug("WORLD: Recvd CMSG_MOVE_NOT_ACTIVE_MOVER");
}

void WorldSession::HandleMountSpecialAnimOpcode(WorldPacket& /*recvdata*/)
{
    //sLog.outDebug("WORLD: Recvd CMSG_MOUNTSPECIAL_ANIM");

    WorldPacket data(SMSG_MOUNTSPECIAL_ANIM, 8);
    data << uint64(GetPlayer()->GetGUID());

    GetPlayer()->SendMessageToSet(&data, false);
}

void WorldSession::HandleMoveKnockBackAck( WorldPacket & /*recv_data*/ )
{
    // CHECK_PACKET_SIZE(recv_data,?);
    sLog.outDebug("CMSG_MOVE_KNOCK_BACK_ACK");
    // Currently not used but maybe use later for recheck final player position
    // (must be at call same as into "recv_data >> x >> y >> z >> orientation;"

    /*
    uint32 flags, time;
    float x, y, z, orientation;
    uint64 guid;
    uint32 sequence;
    uint32 ukn1;
    float xdirection,ydirection,hspeed,vspeed;

    recv_data >> guid;
    recv_data >> sequence;
    recv_data >> flags >> time;
    recv_data >> x >> y >> z >> orientation;
    recv_data >> ukn1; //unknown
    recv_data >> vspeed >> xdirection >> ydirection >> hspeed;

    // skip not personal message;
    if(GetPlayer()->GetGUID()!=guid)
        return;

    // check code
    */
}

void WorldSession::HandleMoveHoverAck( WorldPacket& /*recv_data*/ )
{
    sLog.outDebug("CMSG_MOVE_HOVER_ACK");
}

void WorldSession::HandleMoveWaterWalkAck(WorldPacket& /*recv_data*/)
{
    sLog.outDebug("CMSG_MOVE_WATER_WALK_ACK");
}

void WorldSession::HandleSummonResponseOpcode(WorldPacket& recv_data)
{
    CHECK_PACKET_SIZE(recv_data,8+1);

    if(!_player->isAlive() || _player->isInCombat() )
        return;

    uint64 summoner_guid;
    bool agree;
    recv_data >> summoner_guid;
    recv_data >> agree;

    _player->SummonIfPossible(agree);
}

