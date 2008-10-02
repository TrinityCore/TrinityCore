/*
 * Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
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
    if(!MapManager::Instance().GetMap(GetPlayer()->GetMapId(), GetPlayer())->Add(GetPlayer()))
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

    // battleground state preper
    if(_player->InBattleGround())
    {
        BattleGround *bg = _player->GetBattleGround();
        if(bg)
        {
            if(bg->GetMapId() == _player->GetMapId())       // we teleported to bg
            {
                if(!bg->GetBgRaid(_player->GetTeam()))      // first player joined
                {
                    Group *group = new Group;
                    bg->SetBgRaid(_player->GetTeam(), group);
                    group->Create(_player->GetGUIDLow(), _player->GetName());
                }
                else                                        // raid already exist
                {
                    bg->GetBgRaid(_player->GetTeam())->AddMember(_player->GetGUID(), _player->GetName());
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

    if(GetPlayer()->GetDontMove())
        return;

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

    //Save movement flags
    _player->SetUnitMovementFlags(MovementFlags);

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

    if (!MaNGOS::IsValidMapCoord(movementInfo.x, movementInfo.y, movementInfo.z, movementInfo.o))
        return;

    /* handle special cases */
    if (MovementFlags & MOVEMENTFLAG_ONTRANSPORT)
    {
        // transports size limited
        // (also received at zeppelin leave by some reason with t_* as absolute in continent coordinates, can be safely skipped)
        if( movementInfo.t_x > 50 || movementInfo.t_y > 50 || movementInfo.t_z > 50 )
            return;

        if( !MaNGOS::IsValidMapCoord(movementInfo.x+movementInfo.t_x, movementInfo.y+movementInfo.t_y,
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
                    _player->RemoveSpellsCausingAura(SPELL_AURA_MOUNTED);

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

    // fall damage generation (ignore in flight case that can be triggred also at lags in moment teleportation to another map).
    if (recv_data.GetOpcode() == MSG_MOVE_FALL_LAND && !GetPlayer()->isInFlight())
    {
        Player *target = GetPlayer();

        //Players with Feather Fall or low fall time, or physical immunity (charges used) are ignored
        if (movementInfo.fallTime > 1100 && !target->isDead() && !target->isGameMaster() &&
            !target->HasAuraType(SPELL_AURA_HOVER) && !target->HasAuraType(SPELL_AURA_FEATHER_FALL) &&
            !target->HasAuraType(SPELL_AURA_FLY) && !target->IsImmunedToDamage(SPELL_SCHOOL_MASK_NORMAL,true) )
        {
            //Safe fall, fall time reduction
            int32 safe_fall = target->GetTotalAuraModifier(SPELL_AURA_SAFE_FALL);
            uint32 fall_time = (movementInfo.fallTime > (safe_fall*10)) ? movementInfo.fallTime - (safe_fall*10) : 0;

            if(fall_time > 1100)                            //Prevent damage if fall time < 1100
            {
                //Fall Damage calculation
                float fallperc = float(fall_time)/1100;
                uint32 damage = (uint32)(((fallperc*fallperc -1) / 9 * target->GetMaxHealth())*sWorld.getRate(RATE_DAMAGE_FALL));

                float height = movementInfo.z;
                target->UpdateGroundPositionZ(movementInfo.x,movementInfo.y,height);

                if (damage > 0)
                {
                    //Prevent fall damage from being more than the player maximum health
                    if (damage > target->GetMaxHealth())
                        damage = target->GetMaxHealth();

                    // Gust of Wind
                    if (target->GetDummyAura(43621))
                        damage = target->GetMaxHealth()/2;

                    target->EnvironmentalDamage(target->GetGUID(), DAMAGE_FALL, damage);
                }

                //Z given by moveinfo, LastZ, FallTime, WaterZ, MapZ, Damage, Safefall reduction
                DEBUG_LOG("FALLDAMAGE z=%f sz=%f pZ=%f FallTime=%d mZ=%f damage=%d SF=%d" , movementInfo.z, height, target->GetPositionZ(), movementInfo.fallTime, height, damage, safe_fall);
            }
        }

        //handle fall and logout at the same time (logout started before fall finished)
        /* outdated and create problems with sit at stun sometime
        if (target->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_ROTATE))
        {
            target->SetStandState(PLAYER_STATE_SIT);
            // Can't move
            WorldPacket data( SMSG_FORCE_MOVE_ROOT, 12 );
            data.append(target->GetPackGUID());
            data << (uint32)2;
            SendPacket( &data );
        }
        */
    }

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

    if(GetPlayer()->isMovingOrTurning())
        GetPlayer()->RemoveSpellsCausingAura(SPELL_AURA_FEIGN_DEATH);

    if(movementInfo.z < -500.0f)
    {
        // NOTE: this is actually called many times while falling
        // even after the player has been teleported away
        // TODO: discard movement packets after the player is rooted
        if(GetPlayer()->isAlive())
        {
            GetPlayer()->EnvironmentalDamage(GetPlayer()->GetGUID(),DAMAGE_FALL_TO_VOID, GetPlayer()->GetMaxHealth());
            // change the death state to CORPSE to prevent the death timer from
            // starting in the next player update
            GetPlayer()->KillPlayer();
            GetPlayer()->BuildPlayerRepop();
        }

        // cancel the death timer here if started
        GetPlayer()->RepopAtGraveyard();
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

    static char const* move_type_name[MAX_MOVE_TYPE] = {  "Walk", "Run", "Walkback", "Swim", "Swimback", "Turn", "Fly", "Flyback" };

    uint16 opcode = recv_data.GetOpcode();
    switch(opcode)
    {
        case CMSG_FORCE_WALK_SPEED_CHANGE_ACK:          move_type = MOVE_WALK;     force_move_type = MOVE_WALK;     break;
        case CMSG_FORCE_RUN_SPEED_CHANGE_ACK:           move_type = MOVE_RUN;      force_move_type = MOVE_RUN;      break;
        case CMSG_FORCE_RUN_BACK_SPEED_CHANGE_ACK:      move_type = MOVE_WALKBACK; force_move_type = MOVE_WALKBACK; break;
        case CMSG_FORCE_SWIM_SPEED_CHANGE_ACK:          move_type = MOVE_SWIM;     force_move_type = MOVE_SWIM;     break;
        case CMSG_FORCE_SWIM_BACK_SPEED_CHANGE_ACK:     move_type = MOVE_SWIMBACK; force_move_type = MOVE_SWIMBACK; break;
        case CMSG_FORCE_TURN_RATE_CHANGE_ACK:           move_type = MOVE_TURN;     force_move_type = MOVE_TURN;     break;
        case CMSG_FORCE_FLIGHT_SPEED_CHANGE_ACK:        move_type = MOVE_FLY;      force_move_type = MOVE_FLY;      break;
        case CMSG_FORCE_FLIGHT_BACK_SPEED_CHANGE_ACK:   move_type = MOVE_FLYBACK;  force_move_type = MOVE_FLYBACK;  break;
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
