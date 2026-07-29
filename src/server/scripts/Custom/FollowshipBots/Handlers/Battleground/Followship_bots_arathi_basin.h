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
#include "GameObject.h"
#include "Position.h"

class Creature;
class BattlegroundMap;

struct FSB_BattlegroundData;

namespace FSBBattleground::ArathiBasin
{
    static constexpr uint32 FSB_AB_MAX_TEAM_SIZE = 15;
    static constexpr uint32 MAX_ATTACKERS_PER_POINT = 3;
    static constexpr uint32 MAX_DEFENDERS_PER_POINT = 2;

    static constexpr uint32 BG_AB_OBJECTID_CAPTURE_POINT_STABLES     = 227420;
    static constexpr uint32 BG_AB_OBJECTID_CAPTURE_POINT_BLACKSMITH  = 227522;
    static constexpr uint32 BG_AB_OBJECTID_CAPTURE_POINT_FARM        = 227536;
    static constexpr uint32 BG_AB_OBJECTID_CAPTURE_POINT_GOLD_MINE   = 227538;
    static constexpr uint32 BG_AB_OBJECTID_CAPTURE_POINT_LUMBER_MILL = 227544;

    namespace Creatures
    {
        static constexpr uint32 BG_AB_SPIRIT_HEALER_HORDE = 13117;
        static constexpr uint32 BG_AB_SPIRIT_HEALER_ALLIANCE = 13116;
    }

    namespace Positions
    {
        static constexpr Position BG_AB_GRAVEYARD_HORDE = { 713.f, 645.038f, -12.685f };
        static constexpr Position BG_AB_GRAVEYARD_ALLIANCE = { 1347.4499f, 1274.05f, -11.1053f };
    }

    enum class ABState : uint8
    {
        None,
        AttackStables,
        AttackMine,
        AttackMill,
        AttackBlacksmith,
        AttackFarm,
        DefendStables,
        DefendMine,
        DefendMill,
        DefendBlacksmith,
        DefendFarm
    };

    inline uint32 GetCapturePointEntryForState(ABState state)
    {
        switch (state)
        {
        case ABState::AttackStables:
        case ABState::DefendStables:
            return BG_AB_OBJECTID_CAPTURE_POINT_STABLES;
        case ABState::AttackMine:
        case ABState::DefendMine:
            return BG_AB_OBJECTID_CAPTURE_POINT_GOLD_MINE;
        case ABState::AttackMill:
        case ABState::DefendMill:
            return BG_AB_OBJECTID_CAPTURE_POINT_LUMBER_MILL;
        case ABState::AttackBlacksmith:
        case ABState::DefendBlacksmith:
            return BG_AB_OBJECTID_CAPTURE_POINT_BLACKSMITH;
        case ABState::AttackFarm:
        case ABState::DefendFarm:
            return BG_AB_OBJECTID_CAPTURE_POINT_FARM;
        default:
            return 0;
        }
    }

    inline ABState GetDefendStateForAttack(ABState attackState)
    {
        switch (attackState)
        {
        case ABState::AttackStables:     return ABState::DefendStables;
        case ABState::AttackMine:        return ABState::DefendMine;
        case ABState::AttackMill:        return ABState::DefendMill;
        case ABState::AttackBlacksmith:  return ABState::DefendBlacksmith;
        case ABState::AttackFarm:        return ABState::DefendFarm;
        default:                         return ABState::None;
        }
    }

    inline ABState GetAttackStateForDefend(ABState defendState)
    {
        switch (defendState)
        {
        case ABState::DefendStables:     return ABState::AttackStables;
        case ABState::DefendMine:        return ABState::AttackMine;
        case ABState::DefendMill:        return ABState::AttackMill;
        case ABState::DefendBlacksmith:  return ABState::AttackBlacksmith;
        case ABState::DefendFarm:        return ABState::AttackFarm;
        default:                         return ABState::None;
        }
    }

    void UpdateBot(Creature* bot, FSB_BattlegroundData* bgData);
    void OnMovementInform(Creature* bot, FSB_BattlegroundData* bgData, uint32 type, uint32 id);
    void SetBotState(Creature* bot, FSB_BattlegroundData* bgData, ABState newState);
    ABState RollNewABState(Creature* bot, BattlegroundMap* bgMap);
    void TryAssaultCapturePoint(Creature* bot, FSB_BattlegroundData* bgData);
    void CheckCapturePointState(Creature* bot, FSB_BattlegroundData* bgData);
    GameObject* FindCapturePointByEntry(BattlegroundMap* bgMap, uint32 entry);
    bool IsNodeOwnedByTeam(GameObject* capturePoint, Team team);
    uint32 CountBotsOnState(Creature* bot, BattlegroundMap* bgMap, ABState state);
}
