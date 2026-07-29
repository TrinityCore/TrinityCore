/*
 * This file is part of the Stefal WoW Project.
 * It is designed to work exclusively with the TrinityCore framework.
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
 * This code is provided for personal and educational use within the
 * Stefal WoW Project. It is not intended for commercial distribution,
 * resale, or any form of monetization.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

// MoveChase range for spell casters
constexpr float SPELL_MAX_RANGE = 30.0f;
constexpr float SPELL_MIN_RANGE = 18.0f;



enum FSB_Data
{
    FSB_DATA_HIRED = 1,
    FSB_DATA_HIRE_TIME_LEFT = 2,
};

enum FSB_GenericEvents
{
    
    FSB_EVENT_CHECK_DESPAWN = 7,

};

enum FSB_Events
{
    FSB_EVENT_HIRED_MAINTENANCE = 30,
    FSB_EVENT_HIRED_CHECK_TELEPORT = 32,
    
    FSB_EVENT_HIRED_WAIT_HEALER_RESSURECT = 34,
    
    
    FSB_EVENT_HIRED_CHECK_MOUNT = 35,
    FSB_EVENT_HIRED_CHECK_RESS_TARGETS = 36,
    FSB_EVENT_SOULSTONE_RESSURECT = 39,

    FSB_EVENT_COMBAT_MAINTENANCE = 41,

    FSB_EVENT_GRAVEYARD_RESSURECT = 45,
    FSB_EVENT_HIRED_TELEPORT_DUNGEON = 46,
    FSB_EVENT_HIRED_DUNGEON_RESSURECT = 47,

    FSB_EVENT_PERIODIC_MAINTENANCE = 50,
};

enum FSB_Actions
{    
    FSB_ACTION_WAIT_HEALER_RESSURECT = 2,
    FSB_ACTION_TELEPORT_DUNGEON = 3,
    FSB_ACTION_SOULSTONE_RESSURECT = 4,
};

constexpr float FOLLOW_DISTANCE_CLOSE = 3.0f;
constexpr float FOLLOW_DISTANCE_NORMAL = 5.0f;
constexpr float FOLLOW_DISTANCE_WIDE = 8.0f;

constexpr float FOLLOW_ANGLE_BEHIND = 0.0f;
constexpr float FOLLOW_ANGLE_FRONT = float(M_PI);
constexpr float FOLLOW_ANGLE_LEFT = float(M_PI) / 2.0f;
constexpr float FOLLOW_ANGLE_RIGHT =  float(-M_PI) / 2.0f;
