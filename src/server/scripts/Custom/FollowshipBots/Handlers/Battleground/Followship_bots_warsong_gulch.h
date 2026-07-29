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

#include "Position.h"
#include "SharedDefines.h"
#include "TemporarySummon.h"

#include "Followship_bots_ai_base.h"
#include <string>

class Battleground;
class Player;
class Unit;

struct FSB_BattlegroundData;

namespace FSBBattleground::WarsongGulch
{
    enum class WSGState : uint8
    {
        None,
        DefendBase,
        HoldCenter,
        AttackFlag,
        ReturnFlag,
        ProtectCarrier
    };

    enum class WSGMovePhase : uint8
    {
        None,
        Exiting,
        MovingToCenter,
        Attacking,
        MovingToFlag,
        AtObjective,
        ReviveMove,
        ReviveJump
    };

    enum class WSGPathChoice : uint8
    {
        BaseExit = 1,
        BaseAttack = 2,
        EnemyBaseExit = 3
    };

    static constexpr uint32 FSB_WSG_MAX_TEAM_SIZE = 10;

    static constexpr float FSB_WSG_JUMP_SPEED = 10.0f;
    static constexpr float FSB_WSG_JUMP_MAX_HEIGHT = 10.0f;
    static constexpr float FSB_WSG_CENTER_OFFSET_RADIUS = 8.0f;
    static constexpr float FSB_WSG_FLAG_SEARCH_RANGE = 10.0f;
    static constexpr uint8 MaxBaseDefenders = 3;
    static constexpr uint8 MaxMiddleDefenders = 4;
    static constexpr uint8 MaxFlagAttackers = 5;

    static constexpr Position FSB_WSG_GRAVEYARD_ALLIANCE = { 1410.592f, 1562.315f, 328.3285f, 0.0f };
    static constexpr Position FSB_WSG_GRAVEYARD_ALLIANCE_MOVE = { 1387.0648f, 1544.4152f, 329.9592f };
    static constexpr Position FSB_WSG_GRAVEYARD_ALLIANCE_JUMP = { 1374.65f, 1539.1124f, 320.9783f };
    static constexpr Position FSB_WSG_GRAVEYARD_HORDE = { 1058.005f, 1373.705f, 328.5538f, 0.0f };
    static constexpr Position FSB_WSG_GRAVEYARD_HORDE_MOVE = { 1070.554f, 1384.56f, 328.9073f };
    static constexpr Position FSB_WSG_GRAVEYARD_HORDE_JUMP = { 1075.2363f, 1396.4595f, 322.2837f };

    static constexpr Position FSB_WSG_BASE_ALLIANCE = { 1516.0f, 1481.0f, 352.0f, 0.0f };
    static constexpr Position FSB_WSG_BASE_HORDE = { 930.0f, 1437.567f, 345.536f, 0.0f };

    static constexpr Position FSB_WSG_FLAG_ALLIANCE = { 1535.4586f, 1480.9598f, 352.6968f, 0.0f };
    static constexpr Position FSB_WSG_FLAG_HORDE = { 920.8129f, 1434.5511f, 345.8729f, 0.0f };

    static constexpr Position FSB_WSG_CENTER = { 1212.0f, 1469.0f, 345.536f, 0.0f };

    namespace Spells
    {
        static constexpr uint32 HordeFlag = 156618;
        static constexpr uint32 AllianceFlag = 156621;
        static constexpr uint32 WarsongFlag = 23333;
        static constexpr uint32 SilverwingFlag = 23335;
        static constexpr uint32 DroppedHordeFlag = 23334;
        static constexpr uint32 DroppedAllianceFlag = 23336;
    }

    namespace Objects
    {
        static constexpr uint32 BaseHordeFlag = 227740;
        static constexpr uint32 BaseAllianceFlag = 227741;
        static constexpr uint32 SpawnedAllianceFlag = 227745;
        static constexpr uint32 SpawnedHordeFlag = 227744;
    }

    struct WSGPath
    {
        std::array<Position, 8> points;
        uint8 count;
        bool hasJump;
        Position jump;
    };

    // Near graveyard
    inline WSGPath const AllianceExitPath1 =
    {
        {
            Position(1505.3951f, 1492.0402f, 352.3743f),
            Position(1455.5461f, 1493.4531f, 351.6170f),
            Position(1422.3452f, 1530.2088f, 340.6996f)
        },
        3, true, Position(1400.0762f, 1531.7379f, 322.7053f)
    };

    // Center tunnel
    inline WSGPath const AllianceExitPath2 =
    {
        {
            Position(1509.0966f, 1457.5687f, 350.6935f),
            Position(1441.1824f, 1460.2907f, 341.5768f),
            Position(1363.4025f, 1461.5205f, 324.7423f)
        },
        3, true, Position(1350.3236f, 1461.3178f, 323.6935f)
    };

    // Center tunnel
    inline WSGPath const HordeExitPath1 =
    {
        {
            Position(939.0695f, 1459.5577f, 344.7154f),
            Position(1011.6952f, 1459.5695f, 334.4982f),
            Position(1117.2037f, 1462.1458f, 316.4730f)
        },
        3, true, Position(1131.3631f, 1460.2930f, 314.6424f)
    };

    // Near graveyard
    inline WSGPath const HordeExitPath2 =
    {
        {
            Position(947.0158f, 1422.6073f, 345.4355f),
            Position(995.0747f, 1422.5394f, 345.1290f),
            Position(1062.1445f, 1400.8360f, 336.7558f)
        },
        3, true, Position(1075.2363f, 1396.4595f, 322.2837f)
    };

    // Center tunnel
    inline WSGPath const AllianceAttackPath1 =
    {
        {
            Position(1363.4025f, 1461.5205f, 324.7423f),
            Position(1441.1824f, 1460.2907f, 341.5768f),
            Position(1509.0966f, 1457.5687f, 350.6935f)
        },
        3, false, Position()
    };

    // Side path
    inline WSGPath const AllianceAttackPath2 =
    {
        {
            Position(1349.7447f, 1407.4890f, 325.2285f),
            Position(1372.4014f, 1379.3076f, 330.2068f),
            Position(1408.5594f, 1408.8072f, 344.3476f),
            Position(1407.9438f, 1460.0124f, 348.0763f),
            Position(1467.9635f, 1458.8614f, 362.9517f),
            Position(1529.7808f, 1460.1724f, 362.7264f)
        },
        6, true, Position(1527.6835f, 1471.8970f, 351.9594f)
    };

    // Center tunnel
    inline WSGPath const HordeAttackPath1 =
    {
        {
            Position(1117.2037f, 1462.1458f, 316.4730f),
            Position(1011.6952f, 1459.5695f, 334.4982f),
            Position(939.0695f, 1459.5577f, 344.7154f)
        },
        3, false, Position()
    };

    // Side path
    inline WSGPath const HordeAttackPath2 =
    {
        {
            Position(1091.7185f, 1535.4669f, 315.9850f),
            Position(1066.9182f, 1554.7525f, 321.3725f),
            Position(1042.7249f, 1530.6914f, 336.6773f),
            Position(1057.0529f, 1455.6038f, 341.5280f),
            Position(985.4289f, 1458.1486f, 356.3080f),
            Position(927.8468f, 1457.0494f, 356.0725f)
        },
        6, true, Position(925.6894f, 1445.4456f, 345.5816f)
    };

    // Center tunnel
    inline WSGPath const AllianceExitHordePath1 =
    {
        {
            Position(939.0695f, 1459.5577f, 344.7154f),
            Position(1011.6952f, 1459.5695f, 334.4982f),
            Position(1117.2037f, 1462.1458f, 316.4730f),
        },
        3, false, Position()
    };

    // Side path
    inline WSGPath const AllianceExitHordePath2 =
    {
        {
            Position(947.0158f, 1422.6073f, 345.4355f),
            Position(966.376f, 1422.8261f, 344.9271f),
            Position(965.8685f, 1458.3905f, 356.1229f),
            Position(985.4289f, 1458.1486f, 356.3080f),
            Position(1057.0529f, 1455.6038f, 341.5280f),
            Position(1042.7249f, 1530.6914f, 336.6773f),
            Position(1066.9182f, 1554.7525f, 321.3725f),
            Position(1091.7185f, 1535.4669f, 315.9850f)
        },
        8, false, Position()
    };

    // Center tunnel
    inline WSGPath const HordeExitAlliancePath1 =
    {
        {
            Position(1509.0966f, 1457.5687f, 350.6935f),
            Position(1441.1824f, 1460.2907f, 341.5768f),
            Position(1363.4025f, 1461.5205f, 324.7423f)
        },
        3, false, Position()
    };

    // Side path
    inline WSGPath const HordeExitAlliancePath2 =
    {
        {
            Position(1505.3951f, 1492.0402f, 352.3743f),
            Position(1488.7253f, 1491.5529f, 352.2453f),
            Position(1487.9959f, 1457.962f, 362.74f),
            Position(1467.9635f, 1458.8614f, 362.9517f),
            Position(1407.9438f, 1460.0124f, 348.0763f),
            Position(1408.5594f, 1408.8072f, 344.3476f),
            Position(1372.4014f, 1379.3076f, 330.2068f),
            Position(1349.7447f, 1407.4890f, 325.2285f),
        },
        8, false, Position()
    };

    inline std::array<Position, 4> const CenterPositions =
    {
        Position(1209.4315f, 1520.9934f, 309.0975f, 5.0f),
        Position(1214.3841f, 1480.7662f, 307.9321f, 3.5f),
        Position(1226.8264f, 1408.7434f, 310.8634f, 3.0f),
        Position(1240.8289f, 1339.2724f, 312.3503f, 2.32f)
    };

    inline Team GetEnemyTeam(Team team)
    {
        return team == ALLIANCE ? HORDE : ALLIANCE;
    }

    inline WSGPath const& GetPath(Team team, WSGPathChoice choice, uint8 pathIndex, Team botTeam = ALLIANCE)
    {
        uint8 idx = pathIndex % 2;
        if (choice == WSGPathChoice::BaseExit)
        {
            if (team == ALLIANCE)
                return idx == 0 ? AllianceExitPath1 : AllianceExitPath2;
            else
                return idx == 0 ? HordeExitPath1 : HordeExitPath2;
        }
        else if (choice == WSGPathChoice::BaseAttack)
        {
            if (team == ALLIANCE)
                return idx == 0 ? AllianceAttackPath1 : AllianceAttackPath2;
            else
                return idx == 0 ? HordeAttackPath1 : HordeAttackPath2;
        }
        else // WSGPathChoice::EnemyBaseExit
        {
            if (botTeam == ALLIANCE)
                return idx == 0 ? AllianceExitHordePath1 : AllianceExitHordePath2;
            else
                return idx == 0 ? HordeExitAlliancePath1 : HordeExitAlliancePath2;
        }
    }

    // Attack paths lead toward the enemy base during AttackFlag, or back home during ReturnFlag.
    Team GetAttackTargetTeam(Creature* bot, FSB_BattlegroundData* bgData);

    inline Position GetRandomOffsetPosition(Position const& basePos, float minRadius, float maxRadius)
    {
        float angle = frand(0.0f, 6.283185307f);
        float distance = frand(minRadius, maxRadius);
        Position offset(std::cos(angle) * distance, std::sin(angle) * distance, 0.0f, 0.0f);
        return basePos.GetPositionWithOffset(offset);
    }

    void MoveToExitStep(Creature* bot, FSB_BattlegroundData* bgData);
    void MoveToAttackStep(Creature* bot, FSB_BattlegroundData* bgData);
    void MoveToCenter(Creature* bot, FSB_BattlegroundData* bgData, bool withOffset, bool pickNew);
    void MoveToFlagPoint(Creature* bot, FSB_BattlegroundData* bgData);

    // Returns the index of the path point (>= fromStep) closest to the bot's current position.
    // Used to resume an interrupted path without walking back to the original step.
    uint8 GetClosestPathStep(Creature* bot, WSGPath const& path, uint8 fromStep);

    inline bool BotHasFlagAura(Creature* bot)
    {
        return bot->HasAura(Spells::WarsongFlag) || bot->HasAura(Spells::SilverwingFlag)
            || bot->HasAura(Spells::AllianceFlag) || bot->HasAura(Spells::HordeFlag);
    }

    void OnMovementInform(Creature* bot, FSB_BattlegroundData* bgData, uint32 type, uint32 id);

    void UpdateBot(Creature* bot, FSB_BattlegroundData* bgData);
    void SetBotState(Creature* bot, FSB_BattlegroundData* bgData, WSGState newState);

    void TryUseEnemyFlag(Creature* bot, FSB_BattlegroundData* bgData);
    void TryUseDroppedFlag(Creature* bot, FSB_BattlegroundData* bgData);
    void TryCaptureFlag(Creature* bot, FSB_BattlegroundData* bgData);

    // Called after a WSG bot successfully captures the flag.
    void OnBotCapturedFlag(Creature* bot);

    // Returns the PVP stat IDs used by WSG for the scoreboard.
    std::vector<uint32> GetPvpStatIds();

    bool IsEnemyFlagTaken(Creature* bot);
    bool IsOwnFlagInBase(Creature* bot);
    WSGState GetWSGBotState(Creature* bot, WSGState currentState);
}
