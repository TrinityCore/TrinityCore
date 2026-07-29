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

#pragma once

#include "Followship_bots_defines.h"

namespace FSBMovement
{
    // Movement point IDs
    static constexpr uint32 MOVEMENT_POINT_BOSS_DISTANCE = 0;
    static constexpr uint32 MOVEMENT_POINT_HIRED_LEAVE = 1;
    static constexpr uint32 MOVEMENT_POINT_DEADMINES_VEHICLE = 2;
    static constexpr uint32 MOVEMENT_POINT_DRUID_ROOTS_ESCAPE = 3;
    static constexpr uint32 MOVEMENT_POINT_COOKIE_FOOD = 4;
    static constexpr uint32 MOVEMENT_POINT_WSG_DEFEND = 6;
    static constexpr uint32 MOVEMENT_POINT_WSG_EXIT = 7;
    static constexpr uint32 MOVEMENT_POINT_WSG_JUMP = 10;
    static constexpr uint32 MOVEMENT_POINT_WSG_CENTER = 11;
    static constexpr uint32 MOVEMENT_POINT_WSG_OBJECTIVE = 12;
    static constexpr uint32 MOVEMENT_POINT_WSG_RETURN_FLAG = 14;
    static constexpr uint32 MOVEMENT_POINT_WSG_ATTACK = 15;
    static constexpr uint32 MOVEMENT_POINT_WSG_ATTACK_JUMP = 16;
    static constexpr uint32 MOVEMENT_POINT_WSG_DROPPED_FLAG = 17;
    static constexpr uint32 MOVEMENT_POINT_WSG_GRAVEYARD_MOVE = 18;
    static constexpr uint32 MOVEMENT_POINT_WSG_GRAVEYARD_JUMP = 19;

    static constexpr uint32 MOVEMENT_POINT_AB_ATTACK_NODE = 30;
    static constexpr uint32 MOVEMENT_POINT_AB_DEFEND_NODE = 31;

    static constexpr uint32 MOVEMENT_POINT_ARENA_ROAM = 40;

    static constexpr int8 MOVEMENT_POINT_CORPSE = 20;
    static constexpr int8 MOVEMENT_POINT_NEAR_FIRE = 21;

    inline bool IsWsgMovementPoint(uint32 id)
    {
        switch (id)
        {
        case MOVEMENT_POINT_WSG_DEFEND:
        case MOVEMENT_POINT_WSG_EXIT:
        case MOVEMENT_POINT_WSG_JUMP:
        case MOVEMENT_POINT_WSG_CENTER:
        case MOVEMENT_POINT_WSG_OBJECTIVE:
        case MOVEMENT_POINT_WSG_RETURN_FLAG:
        case MOVEMENT_POINT_WSG_ATTACK:
        case MOVEMENT_POINT_WSG_ATTACK_JUMP:
        case MOVEMENT_POINT_WSG_DROPPED_FLAG:
        case MOVEMENT_POINT_WSG_GRAVEYARD_MOVE:
        case MOVEMENT_POINT_WSG_GRAVEYARD_JUMP:
        case MOVEMENT_POINT_AB_ATTACK_NODE:
        case MOVEMENT_POINT_AB_DEFEND_NODE:
            return true;
        default:
            return false;
        }
    }

    FSB_MovementStates GetBotMoveState(Creature* bot);

    void StopFollow(Creature* bot);
    void ResumeFollow(Creature* bot, float followDistance, float followAngle);

    bool EnsureInRange(Creature* bot, Unit* target);
    bool EnsureInRange(Creature* bot, Unit* target, float range);

    MovementGeneratorType GetMovementType(Unit* me);

    void HandleBattlegroundMovement(Creature* bot, uint32 type, uint32 id);

    void BotSetMountedState(Creature* bot, bool& botMounted);

    void BotHandleReturnMovement(Creature* bot);
}
