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

#include "MovementPacketSender.h"
#include "GameClient.h"
#include "MovementPackets.h"
#include "Unit.h"

// SMSG_SPLINE_SET_* messages are for units controlled by the server.
// SMSG_FORCE_*_SPEED_CHANGE messages are for units controlled by a player and require the client to respond with an ACK message.
// MSG_MOVE_SET_*_SPEED is used to broadcast changes to observers of units controlled by a player
Opcodes const MovementPacketSender::moveTypeToOpcode[MAX_MOVE_TYPE][3] =
{
    { SMSG_SPLINE_SET_WALK_SPEED,        SMSG_FORCE_WALK_SPEED_CHANGE,           MSG_MOVE_SET_WALK_SPEED },
    { SMSG_SPLINE_SET_RUN_SPEED,         SMSG_FORCE_RUN_SPEED_CHANGE,            MSG_MOVE_SET_RUN_SPEED },
    { SMSG_SPLINE_SET_RUN_BACK_SPEED,    SMSG_FORCE_RUN_BACK_SPEED_CHANGE,       MSG_MOVE_SET_RUN_BACK_SPEED },
    { SMSG_SPLINE_SET_SWIM_SPEED,        SMSG_FORCE_SWIM_SPEED_CHANGE,           MSG_MOVE_SET_SWIM_SPEED },
    { SMSG_SPLINE_SET_SWIM_BACK_SPEED,   SMSG_FORCE_SWIM_BACK_SPEED_CHANGE,      MSG_MOVE_SET_SWIM_BACK_SPEED },
    { SMSG_SPLINE_SET_TURN_RATE,         SMSG_FORCE_TURN_RATE_CHANGE,            MSG_MOVE_SET_TURN_RATE },
    { SMSG_SPLINE_SET_FLIGHT_SPEED,      SMSG_FORCE_FLIGHT_SPEED_CHANGE,         MSG_MOVE_SET_FLIGHT_SPEED },
    { SMSG_SPLINE_SET_FLIGHT_BACK_SPEED, SMSG_FORCE_FLIGHT_BACK_SPEED_CHANGE,    MSG_MOVE_SET_FLIGHT_BACK_SPEED },
    { SMSG_SPLINE_SET_PITCH_RATE,        SMSG_FORCE_PITCH_RATE_CHANGE,           MSG_MOVE_SET_PITCH_RATE },
};

MovementChangeType MovementPacketSender::GetChangeTypeByMoveType(UnitMoveType moveType)
{
    switch (moveType)
    {
        case MOVE_WALK:         return MovementChangeType::SPEED_CHANGE_WALK;
        case MOVE_RUN:          return MovementChangeType::SPEED_CHANGE_RUN;
        case MOVE_RUN_BACK:     return MovementChangeType::SPEED_CHANGE_RUN_BACK;
        case MOVE_SWIM:         return MovementChangeType::SPEED_CHANGE_SWIM;
        case MOVE_SWIM_BACK:    return MovementChangeType::SPEED_CHANGE_SWIM_BACK;
        case MOVE_TURN_RATE:    return MovementChangeType::RATE_CHANGE_TURN;
        case MOVE_FLIGHT:       return MovementChangeType::SPEED_CHANGE_FLIGHT_SPEED;
        case MOVE_FLIGHT_BACK:  return MovementChangeType::SPEED_CHANGE_FLIGHT_BACK_SPEED;
        case MOVE_PITCH_RATE:   return MovementChangeType::RATE_CHANGE_PITCH;
        default:
            ASSERT(false, "MovementPacketSender::SendSpeedChangeToMover Unsupported UnitMoveType");
    }
}

void MovementPacketSender::SendSpeedChangeToMover(Unit* unit, UnitMoveType mtype, float newSpeedFlat)
{
    GameClient* controller = unit->GetGameClientMovingMe();

    ASSERT(controller);

    uint32 mCounter = unit->GetMovementCounterAndInc();
    PlayerMovementPendingChange pendingChange;
    pendingChange.movementCounter = mCounter;
    pendingChange.newValue = newSpeedFlat;
    pendingChange.movementChangeType = MovementPacketSender::GetChangeTypeByMoveType(mtype);
    unit->PushPendingMovementChange(pendingChange);

    WorldPackets::Movement::MoveSetSpeed packet(moveTypeToOpcode[mtype][1]);
    packet.MoverGUID = unit->GetGUID();
    packet.SequenceIndex = mCounter;
    packet.Speed = newSpeedFlat;
    controller->SendDirectMessage(packet.Write());
}

void MovementPacketSender::SendSpeedChangeToObservers(Unit* unit, UnitMoveType mtype, float newSpeedFlat)
{
    GameClient* controller = unit->GetGameClientMovingMe();

    ASSERT(controller);

    WorldPackets::Movement::MoveUpdateSpeed packet(moveTypeToOpcode[mtype][2]);
    packet.Status = &unit->m_movementInfo;
    packet.Speed = newSpeedFlat;
    unit->SendMessageToSet(packet.Write(), controller->GetBasePlayer());
}

void MovementPacketSender::SendSpeedChangeToAll(Unit* unit, UnitMoveType mtype, float newSpeedFlat)
{
    GameClient* controller = unit->GetGameClientMovingMe();

    ASSERT(!controller);

    WorldPackets::Movement::MoveSplineSetSpeed packet(moveTypeToOpcode[mtype][0]);
    packet.MoverGUID = unit->GetGUID();
    packet.Speed = newSpeedFlat;
    unit->SendMessageToSet(packet.Write(), true);
}
