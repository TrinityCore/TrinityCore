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

#include "Define.h"

class Battleground;
class BattlegroundMap;
class Creature;
class Unit;

struct FSB_BattlegroundData;

namespace FSBBattleground::Arena
{
    static constexpr float ARENA_TARGET_SCAN_RADIUS = 300.0f;
    static constexpr float ARENA_RANDOM_MOVE_MIN = 5.0f;
    static constexpr float ARENA_RANDOM_MOVE_MAX = 10.0f;
    static constexpr int32 ARENA_MOVE_MAX_RETRIES = 5;
    static constexpr float ARENA_MOVE_MIN_VALID_DIST = 3.0f;

    void InitializeArenaBot(Creature* bot, FSB_BattlegroundData* bgData, Battleground* bg);
    void HandleArenaStart(Creature* bot);
    void HandleArenaTick(Creature* bot);
    Unit* FindArenaTarget(Creature* bot, float range);
    void IssueRandomMovement(Creature* bot);
}
