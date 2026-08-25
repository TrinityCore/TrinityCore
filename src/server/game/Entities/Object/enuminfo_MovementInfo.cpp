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

#include "MovementInfo.h"
#include "Define.h"
#include "SmartEnum.h"
#include <stdexcept>

namespace Trinity::Impl::EnumUtilsImpl
{

/********************************************************************\
|* data for enum 'MovementFlags' in 'MovementInfo.h' auto-generated *|
\********************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<MovementFlags>::ToString(MovementFlags value)
{
    switch (value)
    {
        case MOVEMENTFLAG_FORWARD: return { "MOVEMENTFLAG_FORWARD", "MOVEMENTFLAG_FORWARD", "" };
        case MOVEMENTFLAG_BACKWARD: return { "MOVEMENTFLAG_BACKWARD", "MOVEMENTFLAG_BACKWARD", "" };
        case MOVEMENTFLAG_STRAFE_LEFT: return { "MOVEMENTFLAG_STRAFE_LEFT", "MOVEMENTFLAG_STRAFE_LEFT", "" };
        case MOVEMENTFLAG_STRAFE_RIGHT: return { "MOVEMENTFLAG_STRAFE_RIGHT", "MOVEMENTFLAG_STRAFE_RIGHT", "" };
        case MOVEMENTFLAG_LEFT: return { "MOVEMENTFLAG_LEFT", "MOVEMENTFLAG_LEFT", "" };
        case MOVEMENTFLAG_RIGHT: return { "MOVEMENTFLAG_RIGHT", "MOVEMENTFLAG_RIGHT", "" };
        case MOVEMENTFLAG_PITCH_UP: return { "MOVEMENTFLAG_PITCH_UP", "MOVEMENTFLAG_PITCH_UP", "" };
        case MOVEMENTFLAG_PITCH_DOWN: return { "MOVEMENTFLAG_PITCH_DOWN", "MOVEMENTFLAG_PITCH_DOWN", "" };
        case MOVEMENTFLAG_WALKING: return { "MOVEMENTFLAG_WALKING", "MOVEMENTFLAG_WALKING", "Walking" };
        case MOVEMENTFLAG_DISABLE_GRAVITY: return { "MOVEMENTFLAG_DISABLE_GRAVITY", "MOVEMENTFLAG_DISABLE_GRAVITY", "Former MOVEMENTFLAG_LEVITATING. This is used when walking is not possible." };
        case MOVEMENTFLAG_ROOT: return { "MOVEMENTFLAG_ROOT", "MOVEMENTFLAG_ROOT", "Must not be set along with MOVEMENTFLAG_MASK_MOVING" };
        case MOVEMENTFLAG_FALLING: return { "MOVEMENTFLAG_FALLING", "MOVEMENTFLAG_FALLING", "damage dealt on that type of falling" };
        case MOVEMENTFLAG_FALLING_FAR: return { "MOVEMENTFLAG_FALLING_FAR", "MOVEMENTFLAG_FALLING_FAR", "" };
        case MOVEMENTFLAG_PENDING_STOP: return { "MOVEMENTFLAG_PENDING_STOP", "MOVEMENTFLAG_PENDING_STOP", "" };
        case MOVEMENTFLAG_PENDING_STRAFE_STOP: return { "MOVEMENTFLAG_PENDING_STRAFE_STOP", "MOVEMENTFLAG_PENDING_STRAFE_STOP", "" };
        case MOVEMENTFLAG_PENDING_FORWARD: return { "MOVEMENTFLAG_PENDING_FORWARD", "MOVEMENTFLAG_PENDING_FORWARD", "" };
        case MOVEMENTFLAG_PENDING_BACKWARD: return { "MOVEMENTFLAG_PENDING_BACKWARD", "MOVEMENTFLAG_PENDING_BACKWARD", "" };
        case MOVEMENTFLAG_PENDING_STRAFE_LEFT: return { "MOVEMENTFLAG_PENDING_STRAFE_LEFT", "MOVEMENTFLAG_PENDING_STRAFE_LEFT", "" };
        case MOVEMENTFLAG_PENDING_STRAFE_RIGHT: return { "MOVEMENTFLAG_PENDING_STRAFE_RIGHT", "MOVEMENTFLAG_PENDING_STRAFE_RIGHT", "" };
        case MOVEMENTFLAG_PENDING_ROOT: return { "MOVEMENTFLAG_PENDING_ROOT", "MOVEMENTFLAG_PENDING_ROOT", "" };
        case MOVEMENTFLAG_SWIMMING: return { "MOVEMENTFLAG_SWIMMING", "MOVEMENTFLAG_SWIMMING", "appears with fly flag also" };
        case MOVEMENTFLAG_ASCENDING: return { "MOVEMENTFLAG_ASCENDING", "MOVEMENTFLAG_ASCENDING", "press \042space\042 when flying" };
        case MOVEMENTFLAG_DESCENDING: return { "MOVEMENTFLAG_DESCENDING", "MOVEMENTFLAG_DESCENDING", "" };
        case MOVEMENTFLAG_CAN_FLY: return { "MOVEMENTFLAG_CAN_FLY", "MOVEMENTFLAG_CAN_FLY", "Appears when unit can fly. For example, appears when a player sits on a mount." };
        case MOVEMENTFLAG_FLYING: return { "MOVEMENTFLAG_FLYING", "MOVEMENTFLAG_FLYING", "unit is actually flying. pretty sure this is only used for players. creatures use disable_gravity" };
        case MOVEMENTFLAG_SPLINE_ELEVATION: return { "MOVEMENTFLAG_SPLINE_ELEVATION", "MOVEMENTFLAG_SPLINE_ELEVATION", "used for flight paths" };
        case MOVEMENTFLAG_WATERWALKING: return { "MOVEMENTFLAG_WATERWALKING", "MOVEMENTFLAG_WATERWALKING", "prevent unit from falling through water" };
        case MOVEMENTFLAG_FALLING_SLOW: return { "MOVEMENTFLAG_FALLING_SLOW", "MOVEMENTFLAG_FALLING_SLOW", "active rogue safe fall spell (passive)" };
        case MOVEMENTFLAG_CANNOT_SWIM: return { "MOVEMENTFLAG_CANNOT_SWIM", "MOVEMENTFLAG_CANNOT_SWIM", "" };
        case MOVEMENTFLAG_DISABLE_COLLISION: return { "MOVEMENTFLAG_DISABLE_COLLISION", "MOVEMENTFLAG_DISABLE_COLLISION", "" };
        case MOVEMENTFLAG_KNOCKBACK: return { "MOVEMENTFLAG_KNOCKBACK", "MOVEMENTFLAG_KNOCKBACK", "" };
        case MOVEMENTFLAG_TOUCHING_GROUND: return { "MOVEMENTFLAG_TOUCHING_GROUND", "MOVEMENTFLAG_TOUCHING_GROUND", "terrain normal calculation is disabled if this flag is not present, client automatically handles setting this flag" };
        case MOVEMENTFLAG_NO_STRAFE: return { "MOVEMENTFLAG_NO_STRAFE", "MOVEMENTFLAG_NO_STRAFE", "" };
        case MOVEMENTFLAG_NO_JUMPING: return { "MOVEMENTFLAG_NO_JUMPING", "MOVEMENTFLAG_NO_JUMPING", "" };
        case MOVEMENTFLAG_FULL_SPEED_TURNING: return { "MOVEMENTFLAG_FULL_SPEED_TURNING", "MOVEMENTFLAG_FULL_SPEED_TURNING", "" };
        case MOVEMENTFLAG_FULL_SPEED_PITCHING: return { "MOVEMENTFLAG_FULL_SPEED_PITCHING", "MOVEMENTFLAG_FULL_SPEED_PITCHING", "" };
        case MOVEMENTFLAG_ALWAYS_ALLOW_PITCHING: return { "MOVEMENTFLAG_ALWAYS_ALLOW_PITCHING", "MOVEMENTFLAG_ALWAYS_ALLOW_PITCHING", "" };
        case MOVEMENTFLAG_WATERWALKING_FULL_PITCH: return { "MOVEMENTFLAG_WATERWALKING_FULL_PITCH", "MOVEMENTFLAG_WATERWALKING_FULL_PITCH", "" };
        case MOVEMENTFLAG_CAN_SWIM_TO_FLY_TRANS: return { "MOVEMENTFLAG_CAN_SWIM_TO_FLY_TRANS", "MOVEMENTFLAG_CAN_SWIM_TO_FLY_TRANS", "" };
        case MOVEMENTFLAG_CAN_TURN_WHILE_FALLING: return { "MOVEMENTFLAG_CAN_TURN_WHILE_FALLING", "MOVEMENTFLAG_CAN_TURN_WHILE_FALLING", "" };
        case MOVEMENTFLAG_IGNORE_MOVEMENT_FORCES: return { "MOVEMENTFLAG_IGNORE_MOVEMENT_FORCES", "MOVEMENTFLAG_IGNORE_MOVEMENT_FORCES", "" };
        case MOVEMENTFLAG_CAN_DOUBLE_JUMP: return { "MOVEMENTFLAG_CAN_DOUBLE_JUMP", "MOVEMENTFLAG_CAN_DOUBLE_JUMP", "" };
        case MOVEMENTFLAG_DOUBLE_JUMP: return { "MOVEMENTFLAG_DOUBLE_JUMP", "MOVEMENTFLAG_DOUBLE_JUMP", "" };
        case MOVEMENTFLAG_UNK43: return { "MOVEMENTFLAG_UNK43", "MOVEMENTFLAG_UNK43", "old MovementFlags2 0x8000" };
        case MOVEMENTFLAG_DISABLE_INERTIA: return { "MOVEMENTFLAG_DISABLE_INERTIA", "MOVEMENTFLAG_DISABLE_INERTIA", "" };
        case MOVEMENTFLAG_CAN_ADV_FLY: return { "MOVEMENTFLAG_CAN_ADV_FLY", "MOVEMENTFLAG_CAN_ADV_FLY", "" };
        case MOVEMENTFLAG_ADV_FLYING: return { "MOVEMENTFLAG_ADV_FLYING", "MOVEMENTFLAG_ADV_FLYING", "" };
        case MOVEMENTFLAG_UNK47: return { "MOVEMENTFLAG_UNK47", "MOVEMENTFLAG_UNK47", "old MovementFlags3 0x8" };
        case MOVEMENTFLAG_UNK48: return { "MOVEMENTFLAG_UNK48", "MOVEMENTFLAG_UNK48", "old MovementFlags3 0x10" };
        case MOVEMENTFLAG_FALLING_ADV_FLY_DISMOUNT: return { "MOVEMENTFLAG_FALLING_ADV_FLY_DISMOUNT", "MOVEMENTFLAG_FALLING_ADV_FLY_DISMOUNT", "falling after dismounting while adv flying" };
        case MOVEMENTFLAG_UNK50: return { "MOVEMENTFLAG_UNK50", "MOVEMENTFLAG_UNK50", "old MovementFlags3 0x200" };
        case MOVEMENTFLAG_WALKING_ON_WATER: return { "MOVEMENTFLAG_WALKING_ON_WATER", "MOVEMENTFLAG_WALKING_ON_WATER", "currently on water surface" };
        case MOVEMENTFLAG_CAN_DRIVE: return { "MOVEMENTFLAG_CAN_DRIVE", "MOVEMENTFLAG_CAN_DRIVE", "" };
        case MOVEMENTFLAG_DRIVING_FORWARD: return { "MOVEMENTFLAG_DRIVING_FORWARD", "MOVEMENTFLAG_DRIVING_FORWARD", "" };
        case MOVEMENTFLAG_DRIVING_BACKWARD: return { "MOVEMENTFLAG_DRIVING_BACKWARD", "MOVEMENTFLAG_DRIVING_BACKWARD", "" };
        case MOVEMENTFLAG_UNK55: return { "MOVEMENTFLAG_UNK55", "MOVEMENTFLAG_UNK55", "old MovementFlags3 0x20000" };
        case MOVEMENTFLAG_UNK56: return { "MOVEMENTFLAG_UNK56", "MOVEMENTFLAG_UNK56", "old MovementFlags3 0x40000" };
        case MOVEMENTFLAG_UNK57: return { "MOVEMENTFLAG_UNK57", "MOVEMENTFLAG_UNK57", "old MovementFlags3 0x80000" };
        case MOVEMENTFLAG_UNK58: return { "MOVEMENTFLAG_UNK58", "MOVEMENTFLAG_UNK58", "" };
        case MOVEMENTFLAG_HOVER: return { "MOVEMENTFLAG_HOVER", "MOVEMENTFLAG_HOVER", "" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<MovementFlags>::Count() { return 60; }

template <>
TC_API_EXPORT MovementFlags EnumUtils<MovementFlags>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return MOVEMENTFLAG_FORWARD;
        case 1: return MOVEMENTFLAG_BACKWARD;
        case 2: return MOVEMENTFLAG_STRAFE_LEFT;
        case 3: return MOVEMENTFLAG_STRAFE_RIGHT;
        case 4: return MOVEMENTFLAG_LEFT;
        case 5: return MOVEMENTFLAG_RIGHT;
        case 6: return MOVEMENTFLAG_PITCH_UP;
        case 7: return MOVEMENTFLAG_PITCH_DOWN;
        case 8: return MOVEMENTFLAG_WALKING;
        case 9: return MOVEMENTFLAG_DISABLE_GRAVITY;
        case 10: return MOVEMENTFLAG_ROOT;
        case 11: return MOVEMENTFLAG_FALLING;
        case 12: return MOVEMENTFLAG_FALLING_FAR;
        case 13: return MOVEMENTFLAG_PENDING_STOP;
        case 14: return MOVEMENTFLAG_PENDING_STRAFE_STOP;
        case 15: return MOVEMENTFLAG_PENDING_FORWARD;
        case 16: return MOVEMENTFLAG_PENDING_BACKWARD;
        case 17: return MOVEMENTFLAG_PENDING_STRAFE_LEFT;
        case 18: return MOVEMENTFLAG_PENDING_STRAFE_RIGHT;
        case 19: return MOVEMENTFLAG_PENDING_ROOT;
        case 20: return MOVEMENTFLAG_SWIMMING;
        case 21: return MOVEMENTFLAG_ASCENDING;
        case 22: return MOVEMENTFLAG_DESCENDING;
        case 23: return MOVEMENTFLAG_CAN_FLY;
        case 24: return MOVEMENTFLAG_FLYING;
        case 25: return MOVEMENTFLAG_SPLINE_ELEVATION;
        case 26: return MOVEMENTFLAG_WATERWALKING;
        case 27: return MOVEMENTFLAG_FALLING_SLOW;
        case 28: return MOVEMENTFLAG_CANNOT_SWIM;
        case 29: return MOVEMENTFLAG_DISABLE_COLLISION;
        case 30: return MOVEMENTFLAG_KNOCKBACK;
        case 31: return MOVEMENTFLAG_TOUCHING_GROUND;
        case 32: return MOVEMENTFLAG_NO_STRAFE;
        case 33: return MOVEMENTFLAG_NO_JUMPING;
        case 34: return MOVEMENTFLAG_FULL_SPEED_TURNING;
        case 35: return MOVEMENTFLAG_FULL_SPEED_PITCHING;
        case 36: return MOVEMENTFLAG_ALWAYS_ALLOW_PITCHING;
        case 37: return MOVEMENTFLAG_WATERWALKING_FULL_PITCH;
        case 38: return MOVEMENTFLAG_CAN_SWIM_TO_FLY_TRANS;
        case 39: return MOVEMENTFLAG_CAN_TURN_WHILE_FALLING;
        case 40: return MOVEMENTFLAG_IGNORE_MOVEMENT_FORCES;
        case 41: return MOVEMENTFLAG_CAN_DOUBLE_JUMP;
        case 42: return MOVEMENTFLAG_DOUBLE_JUMP;
        case 43: return MOVEMENTFLAG_UNK43;
        case 44: return MOVEMENTFLAG_DISABLE_INERTIA;
        case 45: return MOVEMENTFLAG_CAN_ADV_FLY;
        case 46: return MOVEMENTFLAG_ADV_FLYING;
        case 47: return MOVEMENTFLAG_UNK47;
        case 48: return MOVEMENTFLAG_UNK48;
        case 49: return MOVEMENTFLAG_FALLING_ADV_FLY_DISMOUNT;
        case 50: return MOVEMENTFLAG_UNK50;
        case 51: return MOVEMENTFLAG_WALKING_ON_WATER;
        case 52: return MOVEMENTFLAG_CAN_DRIVE;
        case 53: return MOVEMENTFLAG_DRIVING_FORWARD;
        case 54: return MOVEMENTFLAG_DRIVING_BACKWARD;
        case 55: return MOVEMENTFLAG_UNK55;
        case 56: return MOVEMENTFLAG_UNK56;
        case 57: return MOVEMENTFLAG_UNK57;
        case 58: return MOVEMENTFLAG_UNK58;
        case 59: return MOVEMENTFLAG_HOVER;
        default: throw std::out_of_range("index");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<MovementFlags>::ToIndex(MovementFlags value)
{
    switch (value)
    {
        case MOVEMENTFLAG_FORWARD: return 0;
        case MOVEMENTFLAG_BACKWARD: return 1;
        case MOVEMENTFLAG_STRAFE_LEFT: return 2;
        case MOVEMENTFLAG_STRAFE_RIGHT: return 3;
        case MOVEMENTFLAG_LEFT: return 4;
        case MOVEMENTFLAG_RIGHT: return 5;
        case MOVEMENTFLAG_PITCH_UP: return 6;
        case MOVEMENTFLAG_PITCH_DOWN: return 7;
        case MOVEMENTFLAG_WALKING: return 8;
        case MOVEMENTFLAG_DISABLE_GRAVITY: return 9;
        case MOVEMENTFLAG_ROOT: return 10;
        case MOVEMENTFLAG_FALLING: return 11;
        case MOVEMENTFLAG_FALLING_FAR: return 12;
        case MOVEMENTFLAG_PENDING_STOP: return 13;
        case MOVEMENTFLAG_PENDING_STRAFE_STOP: return 14;
        case MOVEMENTFLAG_PENDING_FORWARD: return 15;
        case MOVEMENTFLAG_PENDING_BACKWARD: return 16;
        case MOVEMENTFLAG_PENDING_STRAFE_LEFT: return 17;
        case MOVEMENTFLAG_PENDING_STRAFE_RIGHT: return 18;
        case MOVEMENTFLAG_PENDING_ROOT: return 19;
        case MOVEMENTFLAG_SWIMMING: return 20;
        case MOVEMENTFLAG_ASCENDING: return 21;
        case MOVEMENTFLAG_DESCENDING: return 22;
        case MOVEMENTFLAG_CAN_FLY: return 23;
        case MOVEMENTFLAG_FLYING: return 24;
        case MOVEMENTFLAG_SPLINE_ELEVATION: return 25;
        case MOVEMENTFLAG_WATERWALKING: return 26;
        case MOVEMENTFLAG_FALLING_SLOW: return 27;
        case MOVEMENTFLAG_CANNOT_SWIM: return 28;
        case MOVEMENTFLAG_DISABLE_COLLISION: return 29;
        case MOVEMENTFLAG_KNOCKBACK: return 30;
        case MOVEMENTFLAG_TOUCHING_GROUND: return 31;
        case MOVEMENTFLAG_NO_STRAFE: return 32;
        case MOVEMENTFLAG_NO_JUMPING: return 33;
        case MOVEMENTFLAG_FULL_SPEED_TURNING: return 34;
        case MOVEMENTFLAG_FULL_SPEED_PITCHING: return 35;
        case MOVEMENTFLAG_ALWAYS_ALLOW_PITCHING: return 36;
        case MOVEMENTFLAG_WATERWALKING_FULL_PITCH: return 37;
        case MOVEMENTFLAG_CAN_SWIM_TO_FLY_TRANS: return 38;
        case MOVEMENTFLAG_CAN_TURN_WHILE_FALLING: return 39;
        case MOVEMENTFLAG_IGNORE_MOVEMENT_FORCES: return 40;
        case MOVEMENTFLAG_CAN_DOUBLE_JUMP: return 41;
        case MOVEMENTFLAG_DOUBLE_JUMP: return 42;
        case MOVEMENTFLAG_UNK43: return 43;
        case MOVEMENTFLAG_DISABLE_INERTIA: return 44;
        case MOVEMENTFLAG_CAN_ADV_FLY: return 45;
        case MOVEMENTFLAG_ADV_FLYING: return 46;
        case MOVEMENTFLAG_UNK47: return 47;
        case MOVEMENTFLAG_UNK48: return 48;
        case MOVEMENTFLAG_FALLING_ADV_FLY_DISMOUNT: return 49;
        case MOVEMENTFLAG_UNK50: return 50;
        case MOVEMENTFLAG_WALKING_ON_WATER: return 51;
        case MOVEMENTFLAG_CAN_DRIVE: return 52;
        case MOVEMENTFLAG_DRIVING_FORWARD: return 53;
        case MOVEMENTFLAG_DRIVING_BACKWARD: return 54;
        case MOVEMENTFLAG_UNK55: return 55;
        case MOVEMENTFLAG_UNK56: return 56;
        case MOVEMENTFLAG_UNK57: return 57;
        case MOVEMENTFLAG_UNK58: return 58;
        case MOVEMENTFLAG_HOVER: return 59;
        default: throw std::out_of_range("value");
    }
}
}
