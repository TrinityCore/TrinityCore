/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

#include "MovementPacketSender.h"
#include "Player.h"
#include "Opcodes.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "Anticheat.h"

// Spline packets are for units controlled by the server. "Force speed change" (wrongly named opcodes) and "move set speed" packets are for units controlled by a player.
OpcodesList const moveTypeToOpcode[MAX_MOVE_TYPE][3] =
{
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
    { SMSG_SPLINE_SET_WALK_SPEED,        SMSG_FORCE_WALK_SPEED_CHANGE,           MSG_MOVE_SET_WALK_SPEED },
    { SMSG_SPLINE_SET_RUN_SPEED,         SMSG_FORCE_RUN_SPEED_CHANGE,            MSG_MOVE_SET_RUN_SPEED },
    { SMSG_SPLINE_SET_RUN_BACK_SPEED,    SMSG_FORCE_RUN_BACK_SPEED_CHANGE,       MSG_MOVE_SET_RUN_BACK_SPEED },
    { SMSG_SPLINE_SET_SWIM_SPEED,        SMSG_FORCE_SWIM_SPEED_CHANGE,           MSG_MOVE_SET_SWIM_SPEED },
    { SMSG_SPLINE_SET_SWIM_BACK_SPEED,   SMSG_FORCE_SWIM_BACK_SPEED_CHANGE,      MSG_MOVE_SET_SWIM_BACK_SPEED },
    { SMSG_SPLINE_SET_TURN_RATE,         SMSG_FORCE_TURN_RATE_CHANGE,            MSG_MOVE_SET_TURN_RATE },
#else
    { MSG_MOVE_SET_WALK_SPEED,           SMSG_FORCE_WALK_SPEED_CHANGE,           MSG_MOVE_SET_WALK_SPEED },
    { MSG_MOVE_SET_RUN_SPEED,            SMSG_FORCE_RUN_SPEED_CHANGE,            MSG_MOVE_SET_RUN_SPEED },
    { MSG_MOVE_SET_RUN_BACK_SPEED,       SMSG_FORCE_RUN_BACK_SPEED_CHANGE,       MSG_MOVE_SET_RUN_BACK_SPEED },
    { MSG_MOVE_SET_SWIM_SPEED,           SMSG_FORCE_SWIM_SPEED_CHANGE,           MSG_MOVE_SET_SWIM_SPEED },
    { MSG_MOVE_SET_SWIM_BACK_SPEED,      SMSG_FORCE_SWIM_BACK_SPEED_CHANGE,      MSG_MOVE_SET_SWIM_BACK_SPEED },
    { MSG_MOVE_SET_TURN_RATE,            SMSG_FORCE_TURN_RATE_CHANGE,            MSG_MOVE_SET_TURN_RATE },
#endif
};

void MovementPacketSender::AddSpeedChangeToController(Unit* unit, UnitMoveType mtype, float newRate)
{
    Player* mover = unit->GetPlayerMovingMe();
    if (!mover)
    {
        sLog.outError("MovementPacketSender::SendSpeedChangeToController: Incorrect use of the function. It was called on a unit controlled by the server!");
        return;
    }

    float newSpeedFlat = newRate * baseMoveSpeed[mtype]; 
    uint32 mCounter = unit->GetMovementCounterAndInc();
    PlayerMovementPendingChange pendingChange;
    pendingChange.movementCounter = mCounter;
    pendingChange.newValue = newSpeedFlat;
    pendingChange.movementChangeType = MovementPacketSender::GetChangeTypeByMoveType(mtype);
    pendingChange.controller = mover->GetObjectGuid();
    unit->PushPendingMovementChange(pendingChange);

    SendSpeedChangeToController(unit, mover, pendingChange);
}

void MovementPacketSender::SendSpeedChangeToController(Unit* unit, Player* mover, PlayerMovementPendingChange& pendingChange)
{
    UnitMoveType mtype = GetMoveTypeByChangeType(pendingChange.movementChangeType);
    WorldPacket data;
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_9_4
    data.Initialize(moveTypeToOpcode[mtype][1], 8 + 4 + 4);
    data << unit->GetPackGUID();
    data << pendingChange.movementCounter;
#elif SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
    data.Initialize(moveTypeToOpcode[mtype][1], 8 + 4);
    data << unit->GetPackGUID();
#else
    data.Initialize(moveTypeToOpcode[mtype][1], 8 + 4);
    data << unit->GetGUID();
#endif
    data << float(pendingChange.newValue);

    mover->GetSession()->SendPacket(&data);
}

MovementChangeType MovementPacketSender::GetChangeTypeByMoveType(UnitMoveType moveType)
{
    switch (moveType)
    {
        case MOVE_WALK:         return SPEED_CHANGE_WALK;
        case MOVE_RUN:          return SPEED_CHANGE_RUN;
        case MOVE_RUN_BACK:     return SPEED_CHANGE_RUN_BACK;
        case MOVE_SWIM:         return SPEED_CHANGE_SWIM;
        case MOVE_SWIM_BACK:    return SPEED_CHANGE_SWIM_BACK;
        case MOVE_TURN_RATE:    return RATE_CHANGE_TURN;
        default:
            ASSERT(false && "MovementPacketSender::SendSpeedChangeToController Unsupported UnitMoveType");
    }
}

UnitMoveType MovementPacketSender::GetMoveTypeByChangeType(MovementChangeType moveType)
{
    switch (moveType)
    {
        case SPEED_CHANGE_WALK:         return MOVE_WALK;
        case SPEED_CHANGE_RUN:          return MOVE_RUN;
        case SPEED_CHANGE_RUN_BACK:     return MOVE_RUN_BACK;
        case SPEED_CHANGE_SWIM:         return MOVE_SWIM;
        case SPEED_CHANGE_SWIM_BACK:    return MOVE_SWIM_BACK;
        case RATE_CHANGE_TURN:          return MOVE_TURN_RATE;
        default:
            ASSERT(false && "MovementPacketSender::SendSpeedChangeToController Unsupported MovementChangeType");
    }
}

void MovementPacketSender::SendSpeedChangeToObservers(Unit* unit, UnitMoveType mtype, float newSpeed)
{
    Player* mover = unit->GetPlayerMovingMe();
    if (!mover)
    {
        sLog.outError("MovementPacketSender::SendSpeedChangeToObservers: Incorrect use of the function. It was called on a unit controlled by the server!");
        return;
    }

    WorldPacket data;
    data.Initialize(moveTypeToOpcode[mtype][2], 8 + 30 + 4);
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
    data << unit->GetPackGUID();
#else
    data << unit->GetGUID();
#endif
    data << unit->m_movementInfo;
    data << float(newSpeed);
    unit->SendMovementMessageToSet(std::move(data), true, mover);
}

void MovementPacketSender::SendSpeedChangeToAll(Unit* unit, UnitMoveType mtype, float newRate)
{
    WorldPacket data;
    data.Initialize(moveTypeToOpcode[mtype][0], 8 + 4);
    data << unit->GetPackGUID();
    data << float(newRate * baseMoveSpeed[mtype]);
    unit->SendMovementMessageToSet(std::move(data), true);
}

void MovementPacketSender::SendTeleportToController(Unit* unit, float x, float y, float z, float ang)
{
    Player* mover = unit->GetPlayerMovingMe();
    if (!mover)
    {
        sLog.outError("MovementPacketSender::SendTeleportToController: Incorrect use of the function. It was called on a unit controlled by the server!");
        return;
    }

    uint32 mCounter = unit->GetMovementCounterAndInc();
    PlayerMovementPendingChange pendingChange;
    pendingChange.movementCounter = mCounter;
    pendingChange.movementChangeType = TELEPORT;
    pendingChange.controller = mover->GetObjectGuid();
    unit->PushPendingMovementChange(pendingChange);

    MovementInfo mi = unit->m_movementInfo;
    mi.UpdateTime(WorldTimer::getMSTime());
    mi.ChangePosition(x, y, z, ang);

    WorldPacket data(MSG_MOVE_TELEPORT_ACK, 41);
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
    data << unit->GetPackGUID();
#else
    data << unit->GetGUID();
#endif
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_9_4
    data << mCounter;                                      // this value increments every time
#endif
    data << mi;

    mover->GetSession()->SendPacket(&data);
}

void MovementPacketSender::SendTeleportToObservers(Unit* unit)
{
    Player* mover = unit->GetPlayerMovingMe();
    if (!mover)
    {
        sLog.outError("MovementPacketSender::SendTeleportToObservers: Incorrect use of the function. It was called on a unit controlled by the server!");
        return;
    }

    WorldPacket data(MSG_MOVE_TELEPORT, 64);
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
    data << unit->GetPackGUID();
#else
    data << unit->GetGUID();
#endif
    data << unit->m_movementInfo;
    unit->SendMovementMessageToSet(std::move(data), true, mover);
}

void MovementPacketSender::SendKnockBackToController(Unit* unit, float vcos, float vsin, float speedXY, float speedZ)
{
    Player* mover = unit->GetPlayerMovingMe();
    if (!mover)
    {
        sLog.outError("MovementPacketSender::SendKnockBackToController: Incorrect use of the function. It was called on a unit controlled by the server!");
        return;
    }

    uint32 mCounter = unit->GetMovementCounterAndInc();
    PlayerMovementPendingChange pendingChange;
    pendingChange.movementCounter = mCounter;
    pendingChange.movementChangeType = KNOCK_BACK;
    pendingChange.knockbackInfo.vcos = vcos;
    pendingChange.knockbackInfo.vsin = vsin;
    pendingChange.knockbackInfo.speedXY = speedXY;
    pendingChange.knockbackInfo.speedZ = speedZ;
    pendingChange.controller = mover->GetObjectGuid();
    unit->PushPendingMovementChange(pendingChange);

    WorldPacket data(SMSG_MOVE_KNOCK_BACK, (8 + 4 + 4 + 4 + 4 + 4));

#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
    data << unit->GetPackGUID();
#else
    data << unit->GetGUID();
#endif

#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_9_4
    data << mCounter;
#endif

    data << float(vcos);                                    // x direction
    data << float(vsin);                                    // y direction
    data << float(speedXY);                                 // Horizontal speed
    data << float(speedZ);                                 // Z Movement speed (vertical)
    mover->GetSession()->SendPacket(&data);
}

void MovementPacketSender::SendKnockBackToObservers(Unit* unit, float vcos, float vsin, float speedXY, float speedZ)
{
    Player* mover = unit->GetPlayerMovingMe();
    if (!mover)
    {
        sLog.outError("MovementPacketSender::SendSpeedChangeToObservers: Incorrect use of the function. It was called on a unit controlled by the server!");
        return;
    }

    WorldPacket data(MSG_MOVE_KNOCK_BACK);

#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
    data << unit->GetPackGUID();
#else
    data << unit->GetGUID();
#endif

    data << unit->m_movementInfo;
    data << vcos;
    data << vsin;
    data << speedXY;
    data << speedZ;
    unit->SendMovementMessageToSet(std::move(data), true, mover);
}

void MovementPacketSender::AddMovementFlagChangeToController(Unit* unit, MovementFlags mFlag, bool apply)
{
    Player* mover = unit->GetPlayerMovingMe();
    if (!mover)
    {
        sLog.outError("MovementPacketSender::AddMovementFlagChangeToController: Incorrect use of the function. It was called on a unit controlled by the server!");
        return;
    }

    MovementChangeType movementChangeType;
    switch (mFlag)
    {
        case MOVEFLAG_ROOT:                 movementChangeType = ROOT; break;
        case MOVEFLAG_WATERWALKING:         movementChangeType = WATER_WALK; break;
        case MOVEFLAG_HOVER:                movementChangeType = SET_HOVER; break;
        case MOVEFLAG_SAFE_FALL:            movementChangeType = FEATHER_FALL; break;
        default:
            sLog.outError("MovementPacketSender::AddMovementFlagChangeToController: Unsupported MovementFlag (%d), data not sent to client.", mFlag);
            return;
    }

    uint32 mCounter = unit->GetMovementCounterAndInc();
    PlayerMovementPendingChange pendingChange;
    pendingChange.movementCounter = mCounter;
    pendingChange.movementChangeType = movementChangeType;
    pendingChange.apply = apply;
    pendingChange.controller = mover->GetObjectGuid();
    unit->PushPendingMovementChange(pendingChange);

    SendMovementFlagChangeToController(unit, mover, pendingChange);
}

void MovementPacketSender::SendMovementFlagChangeToController(Unit* unit, Player* mover, PlayerMovementPendingChange& pendingChange)
{
    uint16 opcode;
    switch (pendingChange.movementChangeType)
    {
        case ROOT: opcode = pendingChange.apply ? SMSG_FORCE_MOVE_ROOT : SMSG_FORCE_MOVE_UNROOT; break;
        case WATER_WALK: opcode = pendingChange.apply ? SMSG_MOVE_WATER_WALK : SMSG_MOVE_LAND_WALK; break;
        case SET_HOVER: opcode = pendingChange.apply ? SMSG_MOVE_SET_HOVER : SMSG_MOVE_UNSET_HOVER; break;
        case FEATHER_FALL: opcode = pendingChange.apply ? SMSG_MOVE_FEATHER_FALL : SMSG_MOVE_NORMAL_FALL; break;
        default:
            sLog.outError("MovementPacketSender::SendMovementFlagChangeToController: Unsupported movement change (%u), data not sent to client.", pendingChange.movementChangeType);
            return;
    }

#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
    WorldPacket data(opcode, unit->GetPackGUID().size() + 4);
    data << unit->GetPackGUID();
#else
    WorldPacket data(opcode, 8 + 4);
    data << unit->GetGUID();
#endif

#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_9_4
    data << pendingChange.movementCounter;
#endif

    mover->GetSession()->SendPacket(&data);
}

void MovementPacketSender::SendMovementFlagChangeToObservers(Unit* unit, MovementFlags mFlag, bool apply)
{
    Player* mover = unit->GetPlayerMovingMe();
    if (!mover)
    {
        sLog.outError("MovementPacketSender::AddMovementFlagChangeToController: Incorrect use of the function. It was called on a unit controlled by the server!");
        return;
    }

    uint16 opcode;
    switch (mFlag)
    {
        case MOVEFLAG_ROOT:                 opcode = apply ? MSG_MOVE_ROOT : MSG_MOVE_UNROOT; break;
        case MOVEFLAG_WATERWALKING:         opcode = MSG_MOVE_WATER_WALK; break;
        case MOVEFLAG_HOVER:                opcode = MSG_MOVE_HOVER; break;
        case MOVEFLAG_SAFE_FALL:            opcode = MSG_MOVE_FEATHER_FALL; break;
        default:
            sLog.outError("MovementPacketSender::SendMovementFlagChangeToObservers: Unsupported MovementFlag (%d), data not sent to client.", mFlag);
            return;
    }

    WorldPacket data(opcode, 64);
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
    data << unit->GetPackGUID();
#else
    data << unit->GetGUID();
#endif
    data << unit->m_movementInfo;
    unit->SendMovementMessageToSet(std::move(data), true, mover);
}

void MovementPacketSender::SendMovementFlagChangeToAll(Unit* unit, MovementFlags mFlag, bool apply)
{
    uint16 opcode;
    switch (mFlag)
    {
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
        case MOVEFLAG_ROOT:             opcode = apply ? SMSG_SPLINE_MOVE_ROOT              : SMSG_SPLINE_MOVE_UNROOT; break;
        case MOVEFLAG_WATERWALKING:     opcode = apply ? SMSG_SPLINE_MOVE_WATER_WALK        : SMSG_SPLINE_MOVE_LAND_WALK; break;
        case MOVEFLAG_SAFE_FALL:        opcode = apply ? SMSG_SPLINE_MOVE_FEATHER_FALL      : SMSG_SPLINE_MOVE_NORMAL_FALL; break;
        case MOVEFLAG_HOVER:            opcode = apply ? SMSG_SPLINE_MOVE_SET_HOVER         : SMSG_SPLINE_MOVE_UNSET_HOVER; break;
#else
        case MOVEFLAG_ROOT:             opcode = apply ? MSG_MOVE_ROOT                      : MSG_MOVE_UNROOT; break;
        case MOVEFLAG_WATERWALKING:     opcode = apply ? MSG_MOVE_WATER_WALK                : MSG_MOVE_WATER_WALK; break;
        case MOVEFLAG_SAFE_FALL:        opcode = apply ? MSG_MOVE_FEATHER_FALL              : MSG_MOVE_FEATHER_FALL; break;
        case MOVEFLAG_HOVER:            opcode = apply ? MSG_MOVE_HOVER                     : MSG_MOVE_HOVER; break;
#endif
        default:
            sLog.outError("MovementPacketSender::SendMovementFlagChangeToAll: Unsupported MovementFlag (%d), data not sent to client.", mFlag);
            return;
    }

#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
    WorldPacket data(opcode, unit->GetPackGUID().size() + 4);
    data << unit->GetPackGUID();
#else
    WorldPacket data(opcode, 64);
    data << unit->GetGUID();
    data << unit->m_movementInfo;
#endif

    unit->SendMovementMessageToSet(std::move(data), true);
}
