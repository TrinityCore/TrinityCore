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

#include "MovementDefines.h"
#include "Define.h"
#include "SmartEnum.h"
#include <stdexcept>

namespace Trinity::Impl::EnumUtilsImpl
{

/*******************************************************************************\
|* data for enum 'MovementGeneratorType' in 'MovementDefines.h' auto-generated *|
\*******************************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<MovementGeneratorType>::ToString(MovementGeneratorType value)
{
    switch (value)
    {
        case IDLE_MOTION_TYPE: return { "IDLE_MOTION_TYPE", "IDLE_MOTION_TYPE", "IdleMovementGenerator.h" };
        case RANDOM_MOTION_TYPE: return { "RANDOM_MOTION_TYPE", "RANDOM_MOTION_TYPE", "RandomMovementGenerator.h" };
        case WAYPOINT_MOTION_TYPE: return { "WAYPOINT_MOTION_TYPE", "WAYPOINT_MOTION_TYPE", "WaypointMovementGenerator.h" };
        case MAX_DB_MOTION_TYPE: return { "MAX_DB_MOTION_TYPE", "MAX_DB_MOTION_TYPE", "Below motion types can't be set in DB." };
        case CONFUSED_MOTION_TYPE: return { "CONFUSED_MOTION_TYPE", "CONFUSED_MOTION_TYPE", "ConfusedMovementGenerator.h" };
        case CHASE_MOTION_TYPE: return { "CHASE_MOTION_TYPE", "CHASE_MOTION_TYPE", "ChaseMovementGenerator.h" };
        case HOME_MOTION_TYPE: return { "HOME_MOTION_TYPE", "HOME_MOTION_TYPE", "HomeMovementGenerator.h" };
        case FLIGHT_MOTION_TYPE: return { "FLIGHT_MOTION_TYPE", "FLIGHT_MOTION_TYPE", "FlightPathMovementGenerator.h" };
        case POINT_MOTION_TYPE: return { "POINT_MOTION_TYPE", "POINT_MOTION_TYPE", "PointMovementGenerator.h" };
        case FLEEING_MOTION_TYPE: return { "FLEEING_MOTION_TYPE", "FLEEING_MOTION_TYPE", "FleeingMovementGenerator.h" };
        case DISTRACT_MOTION_TYPE: return { "DISTRACT_MOTION_TYPE", "DISTRACT_MOTION_TYPE", "IdleMovementGenerator.h" };
        case ASSISTANCE_MOTION_TYPE: return { "ASSISTANCE_MOTION_TYPE", "ASSISTANCE_MOTION_TYPE", "PointMovementGenerator.h" };
        case ASSISTANCE_DISTRACT_MOTION_TYPE: return { "ASSISTANCE_DISTRACT_MOTION_TYPE", "ASSISTANCE_DISTRACT_MOTION_TYPE", "IdleMovementGenerator.h" };
        case TIMED_FLEEING_MOTION_TYPE: return { "TIMED_FLEEING_MOTION_TYPE", "TIMED_FLEEING_MOTION_TYPE", "FleeingMovementGenerator.h" };
        case FOLLOW_MOTION_TYPE: return { "FOLLOW_MOTION_TYPE", "FOLLOW_MOTION_TYPE", "FollowMovementGenerator.h" };
        case ROTATE_MOTION_TYPE: return { "ROTATE_MOTION_TYPE", "ROTATE_MOTION_TYPE", "IdleMovementGenerator.h" };
        case EFFECT_MOTION_TYPE: return { "EFFECT_MOTION_TYPE", "EFFECT_MOTION_TYPE", "" };
        case SPLINE_CHAIN_MOTION_TYPE: return { "SPLINE_CHAIN_MOTION_TYPE", "SPLINE_CHAIN_MOTION_TYPE", "SplineChainMovementGenerator.h" };
        case FORMATION_MOTION_TYPE: return { "FORMATION_MOTION_TYPE", "FORMATION_MOTION_TYPE", "FormationMovementGenerator.h" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<MovementGeneratorType>::Count() { return 19; }

template <>
TC_API_EXPORT MovementGeneratorType EnumUtils<MovementGeneratorType>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return IDLE_MOTION_TYPE;
        case 1: return RANDOM_MOTION_TYPE;
        case 2: return WAYPOINT_MOTION_TYPE;
        case 3: return MAX_DB_MOTION_TYPE;
        case 4: return CONFUSED_MOTION_TYPE;
        case 5: return CHASE_MOTION_TYPE;
        case 6: return HOME_MOTION_TYPE;
        case 7: return FLIGHT_MOTION_TYPE;
        case 8: return POINT_MOTION_TYPE;
        case 9: return FLEEING_MOTION_TYPE;
        case 10: return DISTRACT_MOTION_TYPE;
        case 11: return ASSISTANCE_MOTION_TYPE;
        case 12: return ASSISTANCE_DISTRACT_MOTION_TYPE;
        case 13: return TIMED_FLEEING_MOTION_TYPE;
        case 14: return FOLLOW_MOTION_TYPE;
        case 15: return ROTATE_MOTION_TYPE;
        case 16: return EFFECT_MOTION_TYPE;
        case 17: return SPLINE_CHAIN_MOTION_TYPE;
        case 18: return FORMATION_MOTION_TYPE;
        default: throw std::out_of_range("index");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<MovementGeneratorType>::ToIndex(MovementGeneratorType value)
{
    switch (value)
    {
        case IDLE_MOTION_TYPE: return 0;
        case RANDOM_MOTION_TYPE: return 1;
        case WAYPOINT_MOTION_TYPE: return 2;
        case MAX_DB_MOTION_TYPE: return 3;
        case CONFUSED_MOTION_TYPE: return 4;
        case CHASE_MOTION_TYPE: return 5;
        case HOME_MOTION_TYPE: return 6;
        case FLIGHT_MOTION_TYPE: return 7;
        case POINT_MOTION_TYPE: return 8;
        case FLEEING_MOTION_TYPE: return 9;
        case DISTRACT_MOTION_TYPE: return 10;
        case ASSISTANCE_MOTION_TYPE: return 11;
        case ASSISTANCE_DISTRACT_MOTION_TYPE: return 12;
        case TIMED_FLEEING_MOTION_TYPE: return 13;
        case FOLLOW_MOTION_TYPE: return 14;
        case ROTATE_MOTION_TYPE: return 15;
        case EFFECT_MOTION_TYPE: return 16;
        case SPLINE_CHAIN_MOTION_TYPE: return 17;
        case FORMATION_MOTION_TYPE: return 18;
        default: throw std::out_of_range("value");
    }
}
}
