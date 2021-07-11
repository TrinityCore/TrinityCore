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

#ifndef MOVEMENT_SENDER_H
#define MOVEMENT_SENDER_H

#include "Object.h"
#include "UnitDefines.h"

class Player;
class Unit;
class MovementInfo;
struct PlayerMovementPendingChange;

//!
//!   movement flag changes for player controlled units:
//!   >>> APPLY
//!   {
//!       // Step1 Sent by the server to the mover's client       // Step2 Sent back by the mover's client to the server      // Step3 Sent to observers (all of these should be renamed to SMSG! Confirmed by sniff analysis)
//!       { SMSG_FORCE_MOVE_ROOT,                                 CMSG_FORCE_MOVE_ROOT_ACK,                                   MSG_MOVE_ROOT },
//!       { SMSG_MOVE_WATER_WALK,                                 CMSG_MOVE_WATER_WALK_ACK,                                   MSG_MOVE_WATER_WALK },
//!       { SMSG_MOVE_SET_HOVER,                                  CMSG_MOVE_HOVER_ACK,                                        MSG_MOVE_HOVER },
//!       { SMSG_MOVE_FEATHER_FALL,                               CMSG_MOVE_FEATHER_FALL_ACK,                                 MSG_MOVE_FEATHER_FALL },
//!   },
//!   >>> UNAPPLY
//!   {
//!       { SMSG_FORCE_MOVE_UNROOT,                               CMSG_FORCE_MOVE_UNROOT_ACK,                                 MSG_MOVE_UNROOT },
//!       { SMSG_MOVE_LAND_WALK,                                  CMSG_MOVE_WATER_WALK_ACK,                                   MSG_MOVE_WATER_WALK },
//!       { SMSG_MOVE_UNSET_HOVER,                                CMSG_MOVE_HOVER_ACK,                                        MSG_MOVE_HOVER },
//!       { SMSG_MOVE_NORMAL_FALL,                                CMSG_MOVE_FEATHER_FALL_ACK,                                 MSG_MOVE_FEATHER_FALL },
//!   }
//!
//!   ----------------------
//!   Speed changes on player controlled units:
//!       // Step1 Sent by the server to the mover's client     // Step2 Sent back by the mover's client to the server      // Step3 Sent to observers
//!       { SMSG_FORCE_WALK_SPEED_CHANGE,                       CMSG_FORCE_WALK_SPEED_CHANGE_ACK,                           MSG_MOVE_SET_WALK_SPEED },
//!       { SMSG_FORCE_RUN_SPEED_CHANGE,                        CMSG_FORCE_RUN_SPEED_CHANGE_ACK,                            MSG_MOVE_SET_RUN_SPEED },
//!       { SMSG_FORCE_RUN_BACK_SPEED_CHANGE,                   CMSG_FORCE_RUN_BACK_SPEED_CHANGE_ACK,                       MSG_MOVE_SET_RUN_BACK_SPEED },
//!       { SMSG_FORCE_SWIM_SPEED_CHANGE,                       CMSG_FORCE_SWIM_SPEED_CHANGE_ACK,                           MSG_MOVE_SET_SWIM_SPEED },
//!       { SMSG_FORCE_SWIM_BACK_SPEED_CHANGE,                  CMSG_FORCE_SWIM_BACK_SPEED_CHANGE_ACK,                      MSG_MOVE_SET_SWIM_BACK_SPEED },
//!       { SMSG_FORCE_TURN_RATE_CHANGE,                        CMSG_FORCE_TURN_RATE_CHANGE_ACK,                            MSG_MOVE_SET_TURN_RATE },
//!
//!   ----------------------
//!   Other type of changes
//!       // Step1 Sent by the server to the mover's client     // Step2 Sent back by the mover's client to the server      // Step3 Sent to observers
//!       { MSG_MOVE_TELEPORT_ACK,                              MSG_MOVE_TELEPORT_ACK,                                      MSG_MOVE_TELEPORT },
//!       { SMSG_MOVE_KNOCK_BACK,                               CMSG_MOVE_KNOCK_BACK_ACK,                                   MSG_MOVE_KNOCK_BACK },
//!
//!   ----------------------
//!   movement flag changes for server controlled units: (these player movement flags have no equivalent in spline: SET_CAN_FLY and SET_CAN_TRANSITION_BETWEEN_SWIM_AND_FLY)
//!   apply
//!   {
//!       SMSG_SPLINE_MOVE_GRAVITY_DISABLE,
//!       SMSG_SPLINE_MOVE_ROOT,
//!       SMSG_SPLINE_MOVE_WATER_WALK,
//!       SMSG_SPLINE_MOVE_FEATHER_FALL,
//!       SMSG_SPLINE_MOVE_SET_HOVER,
//!   }
//!   unapply
//!   {
//!       SMSG_SPLINE_MOVE_GRAVITY_ENABLE,
//!       SMSG_SPLINE_MOVE_UNROOT,
//!       SMSG_SPLINE_MOVE_LAND_WALK,
//!       SMSG_SPLINE_MOVE_NORMAL_FALL,
//!       SMSG_SPLINE_MOVE_UNSET_HOVER,
//!   }

/*
xxxxxToMover() and xxxxxToObservers() methods should be only used on a unit controlled & moved by a player (as in direct client control: possess).
ToMover() to send a packet to the client (asking for confirmation before acting the change) and ToObservers once the change has been acted and should be broadcasted to the other players around (the observers).

xxxxxToAll() method should be used on a unit controlled & moved by the server (@todo note to self: does a player moved unit under the control of a temporary disorient (Scatter Shot eg) or fear fall into this category? EDIT: by looking at the effects of Psychic Scream (10890), the answer is yes)
*/
namespace MovementPacketSender
{
        /* speed change */
        void AddSpeedChangeToController(Unit* unit, UnitMoveType mtype, float newRate);
        void SendSpeedChangeToController(Unit* unit, Player* mover, PlayerMovementPendingChange& pendingChange);
        void SendSpeedChangeToObservers(Unit* unit, UnitMoveType mtype, float newSpeed);
        void SendSpeedChangeToAll(Unit* unit, UnitMoveType mtype, float newRate);

        /* teleport */
        void SendTeleportToController(Unit* unit, float x, float y, float z, float ang);
        void SendTeleportToObservers(Unit* unit);

        /* knockback */
        void SendKnockBackToController(Unit* unit, float vcos, float vsin, float speedXY, float speedZ);
        void SendKnockBackToObservers(Unit* unit, float vcos, float vsin, float speedXY, float speedZ);

        /* movement flag change */
        void AddMovementFlagChangeToController(Unit* unit, MovementFlags mFlag, bool apply);
        void SendMovementFlagChangeToController(Unit* unit, Player* mover, PlayerMovementPendingChange& pendingChange);
        void SendMovementFlagChangeToObservers(Unit* unit, MovementFlags mFlag, bool apply);
        void SendMovementFlagChangeToAll(Unit* unit, MovementFlags mFlag, bool apply);

        // utility method
        MovementChangeType GetChangeTypeByMoveType(UnitMoveType moveType);
        UnitMoveType GetMoveTypeByChangeType(MovementChangeType moveType);
};

#endif
