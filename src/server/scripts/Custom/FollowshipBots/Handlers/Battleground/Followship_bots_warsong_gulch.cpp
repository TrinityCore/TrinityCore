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

#include "Followship_bots_warsong_gulch.h"

#include "Battleground.h"
#include "Creature.h"
#include "DBCEnums.h"
#include "GameObject.h"
#include "Log.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "PetDefines.h"
#include "Player.h"
#include "Random.h"
#include "Timer.h"

#include <algorithm>
#include <string>
#include <vector>

#include "Followship_bots_battleground_handler.h"
#include "Followship_bots_combat_handler.h"
#include "Followship_bots_events_handler.h"
#include "Followship_bots_recovery_handler.h"
#include "Followship_bots_movement_handler.h"
#include "Followship_bots_mgr.h"

namespace FSBBattleground::WarsongGulch
{
    Position GetPositionWithOffsetForState(WSGState state, Position const& basePos)
    {
        float minRadius = 0.0f;
        float maxRadius = 0.0f;

        switch (state)
        {
        case WSGState::DefendBase:
            minRadius = 3.0f;
            maxRadius = 5.0f;
            break;
        case WSGState::HoldCenter:
            minRadius = 5.0f;
            maxRadius = 10.0f;
            break;
        case WSGState::AttackFlag:
        default:
            return basePos;
        }

        float angle = frand(0.0f, 6.283185307f);
        float distance = frand(minRadius, maxRadius);
        Position offset(std::cos(angle) * distance, std::sin(angle) * distance, 0.0f, 0.0f);
        return basePos.GetPositionWithOffset(offset);
    }

    Team GetAttackTargetTeam(Creature* bot, FSB_BattlegroundData* bgData)
    {
        Team botTeam = FSBBattleground::GetBotTeam(bot);
        if (bgData->wsgState == WSGState::AttackFlag)
            return GetEnemyTeam(botTeam);
        return botTeam; // ReturnFlag, DefendBase, ProtectCarrier
    }

    uint8 GetClosestPathStep(Creature* bot, WSGPath const& path, uint8 fromStep)
    {
        if (!bot || path.count == 0)
            return 0;

        if (fromStep >= path.count)
            return path.count - 1;

        Position botPos = bot->GetPosition();
        uint8 bestStep = fromStep;
        float bestDistSq = botPos.GetExactDistSq(path.points[fromStep]);

        for (uint8 i = fromStep + 1; i < path.count; ++i)
        {
            float distSq = botPos.GetExactDistSq(path.points[i]);
            if (distSq < bestDistSq)
            {
                bestDistSq = distSq;
                bestStep = i;
            }
        }

        return bestStep;
    }

    void MoveToExitStep(Creature* bot, FSB_BattlegroundData* bgData)
    {
        Team botTeam = FSBBattleground::GetBotTeam(bot);
        WSGPath const& path = GetPath(botTeam, bgData->wsgExitPathChoice, bgData->wsgPathIndex, botTeam);
        bgData->wsgPathStep = GetClosestPathStep(bot, path, bgData->wsgPathStep);
        uint8 step = std::min<uint8>(bgData->wsgPathStep, path.count - 1);
        bot->GetMotionMaster()->MovePoint(FSBMovement::MOVEMENT_POINT_WSG_EXIT, path.points[step], true);
    }

    void MoveToAttackStep(Creature* bot, FSB_BattlegroundData* bgData)
    {
        WSGPath const& path = GetPath(GetAttackTargetTeam(bot, bgData), WSGPathChoice::BaseAttack, bgData->wsgPathIndex);
        bgData->wsgPathStep = GetClosestPathStep(bot, path, bgData->wsgPathStep);
        uint8 step = std::min<uint8>(bgData->wsgPathStep, path.count - 1);
        bot->GetMotionMaster()->MovePoint(FSBMovement::MOVEMENT_POINT_WSG_ATTACK, path.points[step], true);
    }

    void MoveToGraveyardMove(Creature* bot)
    {
        Team botTeam = FSBBattleground::GetBotTeam(bot);
        Position const& movePos = botTeam == ALLIANCE ? FSB_WSG_GRAVEYARD_ALLIANCE_MOVE : FSB_WSG_GRAVEYARD_HORDE_MOVE;
        bot->GetMotionMaster()->MovePoint(FSBMovement::MOVEMENT_POINT_WSG_GRAVEYARD_MOVE, movePos, true);
    }

    void MoveToGraveyardJump(Creature* bot)
    {
        Team botTeam = FSBBattleground::GetBotTeam(bot);
        Position const& jumpPos = botTeam == ALLIANCE ? FSB_WSG_GRAVEYARD_ALLIANCE_JUMP : FSB_WSG_GRAVEYARD_HORDE_JUMP;
        bot->GetMotionMaster()->MoveJump(FSBMovement::MOVEMENT_POINT_WSG_GRAVEYARD_JUMP, jumpPos, FSB_WSG_JUMP_SPEED, {}, FSB_WSG_JUMP_MAX_HEIGHT);
    }

    void MoveToCenter(Creature* bot, FSB_BattlegroundData* bgData, bool withOffset, bool pickNew)
    {
        if (pickNew)
            bgData->wsgCenterIndex = urand(0, CenterPositions.size() - 1);

        Position target = CenterPositions[bgData->wsgCenterIndex];
        if (withOffset)
            target = GetRandomOffsetPosition(target, 0.0f, FSB_WSG_CENTER_OFFSET_RADIUS);

        bot->GetMotionMaster()->MovePoint(FSBMovement::MOVEMENT_POINT_WSG_CENTER, target, true);
    }

    void MoveToFlagPoint(Creature* bot, FSB_BattlegroundData* bgData)
    {
        Team botTeam = FSBBattleground::GetBotTeam(bot);
        if (bgData->wsgState == WSGState::AttackFlag)
        {
            Position const& enemyFlag = botTeam == ALLIANCE ? FSB_WSG_FLAG_HORDE : FSB_WSG_FLAG_ALLIANCE;
            bot->GetMotionMaster()->MovePoint(FSBMovement::MOVEMENT_POINT_WSG_OBJECTIVE, enemyFlag, true);
        }
        else // ReturnFlag
        {
            Position const& ownFlag = botTeam == ALLIANCE ? FSB_WSG_FLAG_ALLIANCE : FSB_WSG_FLAG_HORDE;
            bot->GetMotionMaster()->MovePoint(FSBMovement::MOVEMENT_POINT_WSG_RETURN_FLAG, ownFlag, true);
        }
    }

    Creature* FindFriendlyCarrier(Creature* bot)
    {
        Team botTeam = FSBBattleground::GetBotTeam(bot);
        BattlegroundMap* bgMap = bot->GetMap()->ToBattlegroundMap();
        if (!bgMap)
            return nullptr;

        for (auto const& [guid, creature] : bgMap->GetObjectsStore().Data.Head)
        {
            if (!creature || !creature->IsBot() || creature == bot)
                continue;

            auto baseAI = dynamic_cast<FSB_BaseAI*>(creature->AI());
            if (!baseAI || baseAI->botHired)
                continue;

            Team creatureTeam = FSBUtils::GetTeamFromFSBRace(baseAI->botRace);
            if (creatureTeam != botTeam)
                continue;

            if (BotHasFlagAura(creature))
                return creature;
        }
        return nullptr;
    }

    namespace Impl
    {
        void StopAttacking(Creature* bot, FSB_BattlegroundData* /*bgData*/)
        {
            if (!bot)
                return;

            if (bot->GetVictim())
                bot->AttackStop();

            bot->InterruptNonMeleeSpells(false);
            bot->CombatStop(true);
            bot->ClearInCombat();

            // Only clear a chase we started; never wipe an objective point move.
            MovementGeneratorType moveType = FSBMovement::GetMovementType(bot);
            if (moveType == CHASE_MOTION_TYPE)
                bot->GetMotionMaster()->Clear();
        }

        enum class WSGReturnRegion
        {
            EnemyBase,
            Center,
            OwnBase
        };

        // Picks the most direct route home for a bot that just picked up the enemy flag,
        // based on whether the bot is in the enemy base, the center, or its own base.
        void SetupReturnFlagPath(Creature* bot, FSB_BattlegroundData* bgData)
        {
            if (!bot || !bgData)
            {
                TC_LOG_INFO("scripts.fsb.battleground", "FSB WSG: SetupReturnFlagPath called with null bot/bgData");
                return;
            }

            Team botTeam = FSBBattleground::GetBotTeam(bot);
            Position const& ownBase = botTeam == ALLIANCE ? FSB_WSG_BASE_ALLIANCE : FSB_WSG_BASE_HORDE;
            Position const& enemyBase = botTeam == ALLIANCE ? FSB_WSG_BASE_HORDE : FSB_WSG_BASE_ALLIANCE;

            Position botPos = bot->GetPosition();
            float distToOwnBase = botPos.GetExactDist(ownBase);
            float distToEnemyBase = botPos.GetExactDist(enemyBase);

            float distToCenter = botPos.GetExactDist2d(CenterPositions[1]);
            for (Position const& centerPos : CenterPositions)
            {
                float dist = botPos.GetExactDist(centerPos);
                if (dist < distToCenter)
                    distToCenter = dist;
            }

            TC_LOG_INFO("scripts.fsb.battleground", "FSB WSG: SetupReturnFlagPath entry bot={} team={} pos=({:.1f},{:.1f},{:.1f}) distOwnBase={:.1f} distEnemyBase={:.1f} distCenter={:.1f}",
                bot->GetName(), botTeam, botPos.GetPositionX(), botPos.GetPositionY(), botPos.GetPositionZ(),
                distToOwnBase, distToEnemyBase, distToCenter);

            WSGReturnRegion region;
            char const* regionName = "Unknown";
            if (distToEnemyBase <= distToCenter && distToEnemyBase <= distToOwnBase)
            {
                region = WSGReturnRegion::EnemyBase;
                regionName = "EnemyBase";
            }
            else if (distToCenter <= distToOwnBase)
            {
                region = WSGReturnRegion::Center;
                regionName = "Center";
            }
            else
            {
                region = WSGReturnRegion::OwnBase;
                regionName = "OwnBase";
            }

            switch (region)
            {
            case WSGReturnRegion::EnemyBase:
            {
                TC_LOG_DEBUG("scripts.fsb.battleground", "FSB WSG: SetupReturnFlagPath bot {} in enemy base, using enemy-base exit path.", bot->GetName());
                bgData->wsgMovePhase = WSGMovePhase::Exiting;
                bgData->wsgExitPathChoice = WSGPathChoice::EnemyBaseExit;
                WSGPath const& path = GetPath(botTeam, WSGPathChoice::EnemyBaseExit, bgData->wsgPathIndex, botTeam);
                bgData->wsgPathStep = GetClosestPathStep(bot, path, 0);
                MoveToExitStep(bot, bgData);
                TC_LOG_INFO("scripts.fsb.battleground", "FSB WSG: SetupReturnFlagPath result bot={} region={} phase=Exiting path=EnemyBaseExit{} step={} hasFlag={} target=({:.1f},{:.1f},{:.1f})",
                    bot->GetName(), regionName, static_cast<uint32>(bgData->wsgPathIndex), bgData->wsgPathStep,
                    BotHasFlagAura(bot), path.points[bgData->wsgPathStep].GetPositionX(),
                    path.points[bgData->wsgPathStep].GetPositionY(), path.points[bgData->wsgPathStep].GetPositionZ());
                break;
            }
            case WSGReturnRegion::Center:
            {
                TC_LOG_DEBUG("scripts.fsb.battleground", "FSB WSG: SetupReturnFlagPath bot {} in center, using own attack path from step 0.", bot->GetName());
                bgData->wsgMovePhase = WSGMovePhase::Attacking;
                bgData->wsgPathStep = 0;
                WSGPath const& path = GetPath(botTeam, WSGPathChoice::BaseAttack, bgData->wsgPathIndex);
                bot->GetMotionMaster()->MovePoint(FSBMovement::MOVEMENT_POINT_WSG_ATTACK, path.points[0]);
                TC_LOG_INFO("scripts.fsb.battleground", "FSB WSG: SetupReturnFlagPath result bot={} region={} phase=Attacking path=OwnAttack{} step=0 hasFlag={} target=({:.1f},{:.1f},{:.1f})",
                    bot->GetName(), regionName, static_cast<uint32>(bgData->wsgPathIndex),
                    BotHasFlagAura(bot), path.points[0].GetPositionX(),
                    path.points[0].GetPositionY(), path.points[0].GetPositionZ());
                break;
            }
            case WSGReturnRegion::OwnBase:
            {
                TC_LOG_DEBUG("scripts.fsb.battleground", "FSB WSG: SetupReturnFlagPath bot {} in own base, moving directly to flag capture.", bot->GetName());
                bgData->wsgMovePhase = WSGMovePhase::MovingToFlag;
                MoveToFlagPoint(bot, bgData);
                Position const& flagPos = botTeam == ALLIANCE ? FSB_WSG_FLAG_ALLIANCE : FSB_WSG_FLAG_HORDE;
                TC_LOG_INFO("scripts.fsb.battleground", "FSB WSG: SetupReturnFlagPath result bot={} region={} phase=MovingToFlag path=DirectToFlag hasFlag={} target=({:.1f},{:.1f},{:.1f})",
                    bot->GetName(), regionName, BotHasFlagAura(bot), flagPos.GetPositionX(), flagPos.GetPositionY(), flagPos.GetPositionZ());
                break;
            }
            }
        }

        // Routes an AttackFlag bot back to the center when it re-rolls to HoldCenter.
        // Uses the enemy team's exit path (same side as the attack path) and picks the
        // closest point among center positions and that exit path.
        void SetupHoldCenterFromAttack(Creature* bot, FSB_BattlegroundData* bgData)
        {
            if (!bot || !bgData)
                return;

            Team botTeam = FSBBattleground::GetBotTeam(bot);
            if (botTeam != ALLIANCE && botTeam != HORDE)
                return;

            // Use the dedicated enemy-base exit path to route back toward the center.
            bgData->wsgExitPathChoice = WSGPathChoice::EnemyBaseExit;
            WSGPath const& enemyExitPath = GetPath(botTeam, WSGPathChoice::EnemyBaseExit, bgData->wsgPathIndex, botTeam);

            Position botPos = bot->GetPosition();
            Position const* bestPos = nullptr;
            float bestDistSq = -1.0f;
            bool bestIsCenter = false;
            uint8 bestIndex = 0;

            for (uint8 i = 0; i < CenterPositions.size(); ++i)
            {
                float distSq = botPos.GetExactDistSq(CenterPositions[i]);
                if (!bestPos || distSq < bestDistSq)
                {
                    bestPos = &CenterPositions[i];
                    bestDistSq = distSq;
                    bestIsCenter = true;
                    bestIndex = i;
                }
            }

            for (uint8 i = 0; i < enemyExitPath.count; ++i)
            {
                float distSq = botPos.GetExactDistSq(enemyExitPath.points[i]);
                if (!bestPos || distSq < bestDistSq)
                {
                    bestPos = &enemyExitPath.points[i];
                    bestDistSq = distSq;
                    bestIsCenter = false;
                    bestIndex = i;
                }
            }

            if (!bestPos)
                return;

            if (bestIsCenter)
            {
                bgData->wsgCenterIndex = bestIndex;
                bgData->wsgMovePhase = WSGMovePhase::MovingToCenter;
                bot->GetMotionMaster()->MovePoint(FSBMovement::MOVEMENT_POINT_WSG_CENTER, *bestPos);
            }
            else
            {
                bgData->wsgPathStep = bestIndex;
                bgData->wsgMovePhase = WSGMovePhase::Exiting;
                MoveToExitStep(bot, bgData);
            }
        }
    }

    void UpdateBot(Creature* bot, FSB_BattlegroundData* bgData)
    {
        if (!bot || !bgData)
            return;

        if (!bot->IsAlive())
            return;

        // Dropped flags are highest priority - override combat to grab/return them.
        TryUseDroppedFlag(bot, bgData);

        if (FSBRecovery::BotHasRecoveryActive(bot))
            return;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI || baseAI->botHired)
            return;

        MovementGeneratorType moveType = FSBMovement::GetMovementType(bot);
        if (moveType == POINT_MOTION_TYPE || moveType == EFFECT_MOTION_TYPE || moveType == CHASE_MOTION_TYPE)
            return;

        BattlegroundMap* bgMap = bot->GetMap()->ToBattlegroundMap();
        if (!bgMap)
            return;

        Battleground* bg = bgMap->GetBG();
        if (!bg)
            return;

        if (bg->GetStatus() != STATUS_IN_PROGRESS)
            return;

        Team botTeam = FSBBattleground::GetBotTeam(bot);
        if (botTeam != ALLIANCE && botTeam != HORDE)
            return;

        // Graveyard revival: always move to the ledge and jump first, regardless of state.
        if (bgData->wsgMovePhase == WSGMovePhase::ReviveMove)
        {
            MoveToGraveyardMove(bot);
            return;
        }
        if (bgData->wsgMovePhase == WSGMovePhase::ReviveJump)
        {
            MoveToGraveyardJump(bot);
            return;
        }

        // If a friendly bot is carrying the flag, AttackFlag or HoldCenter bots
        // either protect it or fall back to the center depending on distance.
        if (bgData->wsgState == WSGState::AttackFlag || bgData->wsgState == WSGState::HoldCenter)
        {
            if (Creature* carrier = FindFriendlyCarrier(bot))
            {
                if (bot->GetDistance(carrier) < 50.0f)
                    SetBotState(bot, bgData, WSGState::ProtectCarrier);
                else if (bgData->wsgState == WSGState::AttackFlag)
                    SetBotState(bot, bgData, WSGState::HoldCenter);
                return;
            }
        }

        switch (bgData->wsgState)
        {
        case WSGState::DefendBase:
        {
            Position const& basePos = botTeam == ALLIANCE ? FSB_WSG_BASE_ALLIANCE : FSB_WSG_BASE_HORDE;
            if (bgData->wsgMovePhase == WSGMovePhase::None && bot->GetDistance(basePos) > 50.0f)
            {
                // Far from base (e.g., re-rolling from center): use the path home.
                bgData->wsgMovePhase = WSGMovePhase::Attacking;
                bgData->wsgPathStep = 0;
                MoveToAttackStep(bot, bgData);
            }
            else if (bgData->wsgMovePhase == WSGMovePhase::Attacking)
            {
                MoveToAttackStep(bot, bgData);
            }
            else if (bgData->wsgCapturePending)
            {
                // Waiting to capture: stay within 2 yards of the home flag so the capture trigger is always reached.
                Position const& flagPos = botTeam == ALLIANCE ? FSB_WSG_FLAG_ALLIANCE : FSB_WSG_FLAG_HORDE;
                float angle = frand(0.0f, 6.283185307f);
                float distance = frand(0.0f, 2.0f);
                Position offset(std::cos(angle) * distance, std::sin(angle) * distance, 0.0f, 0.0f);
                Position movePos = flagPos.GetPositionWithOffset(offset);
                bot->GetMotionMaster()->MovePoint(FSBMovement::MOVEMENT_POINT_WSG_DEFEND, movePos);
            }
            else
            {
                // Near the base: shuffle around the flag room.
                Position movePos = GetPositionWithOffsetForState(WSGState::DefendBase, basePos);
                bot->GetMotionMaster()->MovePoint(FSBMovement::MOVEMENT_POINT_WSG_DEFEND, movePos);
            }
            break;
        }
        case WSGState::ProtectCarrier:
        {
            Creature* carrier = FindFriendlyCarrier(bot);
            if (!carrier || bot->GetDistance(carrier) > 50.0f)
            {
                bot->GetMotionMaster()->Clear();
                SetBotState(bot, bgData, WSGState::HoldCenter);
                break;
            }

            if (FSBMovement::GetMovementType(bot) != FOLLOW_MOTION_TYPE)
                bot->GetMotionMaster()->MoveFollow(carrier, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
            break;
        }
        case WSGState::HoldCenter:
        case WSGState::AttackFlag:
        case WSGState::ReturnFlag:
        {
            TC_LOG_DEBUG("scripts.fsb.battleground", "FSB WSG: UpdateBot state={} bot {} movePhase={} hasFlag={} pos=({:.1f},{:.1f},{:.1f})",
                static_cast<uint32>(bgData->wsgState), bot->GetName(), static_cast<uint32>(bgData->wsgMovePhase), BotHasFlagAura(bot),
                bot->GetPositionX(), bot->GetPositionY(), bot->GetPositionZ());
            switch (bgData->wsgMovePhase)
            {
            case WSGMovePhase::None:
                if (bgData->wsgState == WSGState::ReturnFlag)
                {
                    TC_LOG_INFO("scripts.fsb.battleground", "FSB WSG: UpdateBot ReturnFlag/None bot={} phase={} pos=({:.1f},{:.1f},{:.1f})",
                        bot->GetName(), static_cast<uint32>(bgData->wsgMovePhase),
                        bot->GetPositionX(), bot->GetPositionY(), bot->GetPositionZ());
                    Impl::SetupReturnFlagPath(bot, bgData);
                }
                else
                {
                    bgData->wsgMovePhase = WSGMovePhase::Exiting;
                    bgData->wsgPathStep = 0;
                    bgData->wsgExitPathChoice = WSGPathChoice::BaseExit;
                    MoveToExitStep(bot, bgData);
                }
                break;
            case WSGMovePhase::Exiting:
                // Combat or death interrupted the chain; resume the current exit step.
                MoveToExitStep(bot, bgData);
                break;
            case WSGMovePhase::MovingToCenter:
                MoveToCenter(bot, bgData, bgData->wsgState == WSGState::HoldCenter, false);
                break;
            case WSGMovePhase::Attacking:
                MoveToAttackStep(bot, bgData);
                break;
            case WSGMovePhase::MovingToFlag:
                MoveToFlagPoint(bot, bgData);
                break;
            case WSGMovePhase::AtObjective:
                // HoldCenter bots shuffle around their chosen center position.
                if (bgData->wsgState == WSGState::HoldCenter)
                    MoveToCenter(bot, bgData, true, false);
                break;
            default:
                break;
            }
            break;
        }
        default:
            break;
        }
    }

    void SetBotState(Creature* bot, FSB_BattlegroundData* bgData, WSGState newState)
    {
        if (!bot || !bgData)
            return;

        // Update tracked state counts via ZoneScript GetData/SetData (per team)
        if (ZoneScript* zoneScript = bot->GetZoneScript())
        {
            bool isAlliance = FSBBattleground::GetBotTeam(bot) == ALLIANCE;
            uint32 baseDefendersId = isAlliance ? FSBBattleground::DataCurrentBaseDefendersAlliance : FSBBattleground::DataCurrentBaseDefendersHorde;
            uint32 middleDefendersId = isAlliance ? FSBBattleground::DataCurrentMiddleDefendersAlliance : FSBBattleground::DataCurrentMiddleDefendersHorde;
            uint32 flagAttackersId = isAlliance ? FSBBattleground::DataCurrentFlagAttackersAlliance : FSBBattleground::DataCurrentFlagAttackersHorde;

            WSGState oldState = bgData->wsgState;

            switch (oldState)
            {
                case WSGState::DefendBase:
                    zoneScript->SetData(baseDefendersId, zoneScript->GetData(baseDefendersId) - 1);
                    break;
                case WSGState::HoldCenter:
                    zoneScript->SetData(middleDefendersId, zoneScript->GetData(middleDefendersId) - 1);
                    break;
                case WSGState::AttackFlag:
                    zoneScript->SetData(flagAttackersId, zoneScript->GetData(flagAttackersId) - 1);
                    break;
                default:
                    break;
            }

            switch (newState)
            {
                case WSGState::DefendBase:
                    zoneScript->SetData(baseDefendersId, zoneScript->GetData(baseDefendersId) + 1);
                    break;
                case WSGState::HoldCenter:
                    zoneScript->SetData(middleDefendersId, zoneScript->GetData(middleDefendersId) + 1);
                    break;
                case WSGState::AttackFlag:
                    zoneScript->SetData(flagAttackersId, zoneScript->GetData(flagAttackersId) + 1);
                    break;
                default:
                    break;
            }
        }

        WSGState oldState = bgData->wsgState;

        // Do not interrupt the graveyard exit sequence. State/counts are already updated above;
        // just record the new state and let the revive move/jump finish.
        if (bgData->wsgMovePhase == WSGMovePhase::ReviveMove || bgData->wsgMovePhase == WSGMovePhase::ReviveJump)
        {
            bgData->wsgState = newState;
            return;
        }

        // AttackFlag bots that fall back to HoldCenter should route back from the enemy side,
        // not walk back to their own base. Use the enemy exit path and the closest center/path point.
        if (oldState == WSGState::AttackFlag && newState == WSGState::HoldCenter)
        {
            bgData->wsgState = newState;
            Impl::SetupHoldCenterFromAttack(bot, bgData);
        }
        else
        {
            bgData->wsgState = newState;
            bgData->wsgMovePhase = WSGMovePhase::None;
            bgData->wsgPathStep = 0;
            bgData->wsgPathIndex = urand(0, 1);
            bgData->wsgExitPathChoice = WSGPathChoice::BaseExit;
        }

        if (newState != WSGState::None)
            FSBEvents::ScheduleBotEvent(bot, FSB_EVENT_BATTLEGROUND_STATE_CHAT, 2s, 10s);
    }

    void TryUseEnemyFlag(Creature* bot, FSB_BattlegroundData* bgData)
    {
        if (!bot || !bgData || !bot->IsAlive())
            return;

        if (bgData->wsgState != WSGState::AttackFlag)
            return;

        Team botTeam = FSBBattleground::GetBotTeam(bot);
        if (botTeam != ALLIANCE && botTeam != HORDE)
            return;

        uint32 flagEntry = botTeam == ALLIANCE ? Objects::BaseHordeFlag : Objects::BaseAllianceFlag;
        GameObject* flag = bot->FindNearestGameObject(flagEntry, FSB_WSG_FLAG_SEARCH_RANGE);
        if (!flag)
        {
            TC_LOG_DEBUG("scripts.fsb.battleground", "FSB WSG: TryUseEnemyFlag bot {} - no flag entry {} found within {} yd",
                bot->GetName(), flagEntry, FSB_WSG_FLAG_SEARCH_RANGE);
            return;
        }

        TC_LOG_DEBUG("scripts.fsb.battleground", "FSB WSG: TryUseEnemyFlag bot {} found flag entry={} dist={:.1f}, using it",
            bot->GetName(), flag->GetEntry(), bot->GetDistance(flag));

        // GameObject::Use is a no-op unless the flag state is InBase, so only the first bot picks it up.
        flag->Use(bot);

        if (BotHasFlagAura(bot))
        {
            TC_LOG_DEBUG("scripts.fsb.battleground", "FSB WSG: bot {} picked up enemy flag! Setting ReturnFlag state.", bot->GetName());
            SetBotState(bot, bgData, WSGState::ReturnFlag);
            UpdateBot(bot, bgData); // start the return journey immediately
        }
        // else: another bot picked it first; the next tick re-issues the objective move and retries.
    }

    void TryUseDroppedFlag(Creature* bot, FSB_BattlegroundData* bgData)
    {
        if (!bot || !bgData || !bot->IsAlive())
            return;

        if (bgData->wsgMovePhase == WSGMovePhase::ReviveMove || bgData->wsgMovePhase == WSGMovePhase::ReviveJump)
            return;

        if (BotHasFlagAura(bot))
            return;

        Team botTeam = FSBBattleground::GetBotTeam(bot);
        if (botTeam != ALLIANCE && botTeam != HORDE)
            return;

        // Search for dropped flags
        GameObject* droppedFlag = bot->FindNearestGameObjectWithOptions(20.f, { .GameObjectId = Objects::SpawnedAllianceFlag, .IgnorePrivateObjects = false });
        if (!droppedFlag)
            droppedFlag = bot->FindNearestGameObjectWithOptions(20.f, { .GameObjectId = Objects::SpawnedHordeFlag, .IgnorePrivateObjects = false });

        if (!droppedFlag)
            return;

        TC_LOG_DEBUG("scripts.fsb.battleground", "FSB WSG: bot {} found dropped flag entry={} dist={:.1f} at ({:.1f}, {:.1f}, {:.1f})",
            bot->GetName(), droppedFlag->GetEntry(), bot->GetDistance(droppedFlag),
            droppedFlag->GetPositionX(), droppedFlag->GetPositionY(), droppedFlag->GetPositionZ());

        float dist = bot->GetDistance(droppedFlag);
        if (dist > 5.0f)
        {
            // Stop combat while moving to the flag.
            Impl::StopAttacking(bot, bgData);

            // Move to 3 yards from the flag, toward the bot's current position
            Position const& flagPos = droppedFlag->GetPosition();
            float angle = flagPos.GetAbsoluteAngle(bot->GetPosition());
            Position offset(std::cos(angle) * 3.0f, std::sin(angle) * 3.0f, 0.0f, 0.0f);
            Position movePos = flagPos.GetPositionWithOffset(offset);
            bot->GetMotionMaster()->MovePoint(FSBMovement::MOVEMENT_POINT_WSG_DROPPED_FLAG, movePos);
            return;
        }

        // Close enough - use it
        droppedFlag->Use(bot);

        if (BotHasFlagAura(bot))
        {
            SetBotState(bot, bgData, WSGState::ReturnFlag);
            UpdateBot(bot, bgData);
        }
    }

    void TryCaptureFlag(Creature* bot, FSB_BattlegroundData* bgData)
    {
        if (!bot || !bgData || !bot->IsAlive())
            return;

        if (!BotHasFlagAura(bot))
        {
            bgData->wsgCapturePending = false;
            return;
        }

        if (!IsOwnFlagInBase(bot))
        {
            TC_LOG_DEBUG("scripts.fsb.battleground", "FSB WSG: TryCaptureFlag bot {} own flag not in base, switching to defend and rescheduling capture", bot->GetName());
            bgData->wsgCapturePending = true;
            if (bgData->wsgState != WSGState::DefendBase)
                SetBotState(bot, bgData, WSGState::DefendBase);
            FSBEvents::ScheduleBotEvent(bot, FSB_EVENT_WSG_BOT_CAPTURE, 3s);
            return;
        }

        bgData->wsgCapturePending = false;

        ZoneScript* zoneScript = bot->GetZoneScript();
        if (!zoneScript)
            return;

        TC_LOG_DEBUG("scripts.fsb.battleground", "FSB WSG: TryCaptureFlag bot {} own flag in base, calling OnCaptureFlag", bot->GetName());
        zoneScript->OnCaptureFlag(nullptr, bot);
    }

    void OnMovementInform(Creature* bot, FSB_BattlegroundData* bgData, uint32 type, uint32 id)
    {
        if (!bot || !bgData || !bot->IsAlive())
            return;

        if (type == EFFECT_MOTION_TYPE)
        {
            if (id == FSBMovement::MOVEMENT_POINT_WSG_JUMP)
            {
                // Exit path jump landed; head to a random center position.
                bgData->wsgMovePhase = WSGMovePhase::MovingToCenter;
                MoveToCenter(bot, bgData, bgData->wsgState == WSGState::HoldCenter, true);
            }
            else if (id == FSBMovement::MOVEMENT_POINT_WSG_ATTACK_JUMP)
            {
                // Attack path jump landed; head to the flag position.
                bgData->wsgMovePhase = WSGMovePhase::MovingToFlag;
                MoveToFlagPoint(bot, bgData);
            }
            else if (id == FSBMovement::MOVEMENT_POINT_WSG_GRAVEYARD_JUMP)
            {
                // Landed after the graveyard jump; resume the re-evaluated state.
                if (bgData->wsgState == WSGState::HoldCenter || bgData->wsgState == WSGState::AttackFlag)
                    bgData->wsgMovePhase = WSGMovePhase::MovingToCenter;
                else
                    bgData->wsgMovePhase = WSGMovePhase::None;
                UpdateBot(bot, bgData);
            }
            return;
        }

        if (type != POINT_MOTION_TYPE)
            return;

        switch (id)
        {
        case FSBMovement::MOVEMENT_POINT_WSG_DEFEND:
            // No-op; the tick handles the re-shuffle.
            break;
        case FSBMovement::MOVEMENT_POINT_WSG_EXIT:
        {
            Team botTeam = FSBBattleground::GetBotTeam(bot);
            WSGPath const& path = GetPath(botTeam, bgData->wsgExitPathChoice, bgData->wsgPathIndex, botTeam);
            ++bgData->wsgPathStep;
            if (bgData->wsgPathStep < path.count)
                MoveToExitStep(bot, bgData);
            else if (path.hasJump)
                bot->GetMotionMaster()->MoveJump(FSBMovement::MOVEMENT_POINT_WSG_JUMP, path.jump, FSB_WSG_JUMP_SPEED, {}, FSB_WSG_JUMP_MAX_HEIGHT);
            else
            {
                bgData->wsgMovePhase = WSGMovePhase::MovingToCenter;
                MoveToCenter(bot, bgData, bgData->wsgState == WSGState::HoldCenter, true);
            }
            break;
        }
        case FSBMovement::MOVEMENT_POINT_WSG_CENTER:
        {
            if (bgData->wsgState == WSGState::HoldCenter)
            {
                bgData->wsgMovePhase = WSGMovePhase::AtObjective;
            }
            else if (bgData->wsgState == WSGState::AttackFlag || bgData->wsgState == WSGState::ReturnFlag)
            {
                bgData->wsgMovePhase = WSGMovePhase::Attacking;
                bgData->wsgPathStep = 0;
                MoveToAttackStep(bot, bgData);
            }
            break;
        }
        case FSBMovement::MOVEMENT_POINT_WSG_ATTACK:
        {
            WSGPath const& path = GetPath(GetAttackTargetTeam(bot, bgData), WSGPathChoice::BaseAttack, bgData->wsgPathIndex);
            ++bgData->wsgPathStep;
            if (bgData->wsgPathStep < path.count)
                MoveToAttackStep(bot, bgData);
            else if (path.hasJump)
                bot->GetMotionMaster()->MoveJump(FSBMovement::MOVEMENT_POINT_WSG_ATTACK_JUMP, path.jump, FSB_WSG_JUMP_SPEED, {}, FSB_WSG_JUMP_MAX_HEIGHT);
            else
            {
                if (bgData->wsgState == WSGState::DefendBase)
                {
                    // Returning home to defend: move to the base position so the tick can shuffle.
                    bgData->wsgMovePhase = WSGMovePhase::None;
                    Position const& basePos = FSBBattleground::GetBotTeam(bot) == ALLIANCE ? FSB_WSG_BASE_ALLIANCE : FSB_WSG_BASE_HORDE;
                    bot->GetMotionMaster()->MovePoint(FSBMovement::MOVEMENT_POINT_WSG_DEFEND, basePos);
                }
                else
                {
                    bgData->wsgMovePhase = WSGMovePhase::MovingToFlag;
                    MoveToFlagPoint(bot, bgData);
                }
            }
            break;
        }
        case FSBMovement::MOVEMENT_POINT_WSG_OBJECTIVE:
            // Reached the enemy flag position; use the flag after a 1s delay.
            bot->GetMotionMaster()->Clear();
            FSBEvents::ScheduleBotEvent(bot, FSB_EVENT_WSG_USE_FLAG, 1s);
            break;
        case FSBMovement::MOVEMENT_POINT_WSG_RETURN_FLAG:
            // Arrived at own base with the enemy flag; trigger capture directly via ZoneScript.
            bot->GetMotionMaster()->Clear();
            bgData->wsgMovePhase = WSGMovePhase::AtObjective;
            FSBEvents::ScheduleBotEvent(bot, FSB_EVENT_WSG_BOT_CAPTURE, 500ms);
            break;
        case FSBMovement::MOVEMENT_POINT_WSG_DROPPED_FLAG:
            // Reached the dropped flag position; use it after a short delay.
            bot->GetMotionMaster()->Clear();
            FSBEvents::ScheduleBotEvent(bot, FSB_EVENT_WSG_USE_DROPPED_FLAG, 500ms);
            break;
        case FSBMovement::MOVEMENT_POINT_WSG_GRAVEYARD_MOVE:
            // Reached the graveyard ledge; jump down into the battleground.
            bgData->wsgMovePhase = WSGMovePhase::ReviveJump;
            MoveToGraveyardJump(bot);
            break;
        default:
            break;
        }
    }

    std::vector<uint32> GetPvpStatIds()
    {
        return { 928, 929 }; // PVP_STAT_FLAG_CAPTURES, PVP_STAT_FLAG_RETURNS
    }

    bool IsEnemyFlagTaken(Creature* bot)
    {
        if (!bot)
            return false;

        Team botTeam = FSBBattleground::GetBotTeam(bot);
        uint32 enemyFlagEntry = botTeam == ALLIANCE ? Objects::BaseHordeFlag : Objects::BaseAllianceFlag;

        BattlegroundMap* bgMap = bot->GetMap()->ToBattlegroundMap();
        if (!bgMap)
            return false;

        bool found = false;
        for (auto const& [guid, go] : bgMap->GetObjectsStore().Data.FindContainer<GameObject>())
        {
            if (!go || go->GetEntry() != enemyFlagEntry)
                continue;

            found = true;
            TC_LOG_DEBUG("scripts.fsb.battleground", "FSB WSG: IsEnemyFlagTaken bot {} found enemy flag {} state={}", bot->GetName(), enemyFlagEntry, static_cast<uint8>(go->GetFlagState()));
            return go->GetFlagState() == FlagState::Taken;
        }

        if (!found)
            TC_LOG_DEBUG("scripts.fsb.battleground", "FSB WSG: IsEnemyFlagTaken bot {} found no gameobject with entry {}", bot->GetName(), enemyFlagEntry);

        return false;
    }

    bool IsOwnFlagInBase(Creature* bot)
    {
        if (!bot)
            return false;

        Team botTeam = FSBBattleground::GetBotTeam(bot);
        uint32 ownFlagEntry = botTeam == ALLIANCE ? Objects::BaseAllianceFlag : Objects::BaseHordeFlag;

        BattlegroundMap* bgMap = bot->GetMap()->ToBattlegroundMap();
        if (!bgMap)
            return false;

        for (auto const& [guid, go] : bgMap->GetObjectsStore().Data.FindContainer<GameObject>())
        {
            if (!go || go->GetEntry() != ownFlagEntry)
                continue;

            TC_LOG_DEBUG("scripts.fsb.battleground", "FSB WSG: IsOwnFlagInBase bot {} found own flag {} state={}", bot->GetName(), ownFlagEntry, static_cast<uint8>(go->GetFlagState()));
            return go->GetFlagState() == FlagState::InBase;
        }

        TC_LOG_DEBUG("scripts.fsb.battleground", "FSB WSG: IsOwnFlagInBase bot {} found no gameobject with entry {}", bot->GetName(), ownFlagEntry);
        return false;
    }

    WSGState GetWSGBotState(Creature* bot, WSGState /*currentState*/)
    {
        if (bot)
            if (auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI()))
                if (FSB_BattlegroundData* bgData = baseAI->GetBattlegroundData())
                    if (bgData->wsgCapturePending)
                        return WSGState::DefendBase;

        bool enemyFlagTaken = IsEnemyFlagTaken(bot);

        ZoneScript* zoneScript = bot ? bot->GetZoneScript() : nullptr;

        std::vector<WSGState> available;
        if (zoneScript)
        {
            bool isAlliance = FSBBattleground::GetBotTeam(bot) == ALLIANCE;
            uint32 baseDefendersId = isAlliance ? FSBBattleground::DataCurrentBaseDefendersAlliance : FSBBattleground::DataCurrentBaseDefendersHorde;
            uint32 middleDefendersId = isAlliance ? FSBBattleground::DataCurrentMiddleDefendersAlliance : FSBBattleground::DataCurrentMiddleDefendersHorde;
            uint32 flagAttackersId = isAlliance ? FSBBattleground::DataCurrentFlagAttackersAlliance : FSBBattleground::DataCurrentFlagAttackersHorde;

            if (zoneScript->GetData(baseDefendersId) < MaxBaseDefenders)
                available.push_back(WSGState::DefendBase);
            if (zoneScript->GetData(middleDefendersId) < MaxMiddleDefenders)
                available.push_back(WSGState::HoldCenter);
            if (!enemyFlagTaken && zoneScript->GetData(flagAttackersId) < MaxFlagAttackers)
                available.push_back(WSGState::AttackFlag);
        }
        else
        {
            available.push_back(WSGState::DefendBase);
            available.push_back(WSGState::HoldCenter);
            if (!enemyFlagTaken)
                available.push_back(WSGState::AttackFlag);
        }

        if (available.empty())
            return WSGState::HoldCenter;

        return available[urand(0, available.size() - 1)];
    }

    void OnBotCapturedFlag(Creature* bot)
    {
        if (!bot || !bot->IsBot())
            return;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI || baseAI->botHired)
            return;

        if (FSB_BattlegroundData* bgData = baseAI->GetBattlegroundData())
            bgData->wsgCapturePending = false;

        // Re-roll the capturing bot after a short delay.
        FSBEvents::ScheduleBotEvent(bot, FSB_EVENT_WSG_REROLL_STATE, 10s);

        // Re-roll all non-hired WSG bots currently holding center.
        BattlegroundMap* bgMap = bot->GetMap()->ToBattlegroundMap();
        if (!bgMap)
            return;

        for (auto const& [guid, creature] : bgMap->GetObjectsStore().Data.Head)
        {
            if (!creature || !creature->IsBot() || creature == bot)
                continue;

            auto otherAI = dynamic_cast<FSB_BaseAI*>(creature->AI());
            if (!otherAI || otherAI->botHired)
                continue;

            FSB_BattlegroundData* otherBgData = otherAI->GetBattlegroundData();
            if (!otherBgData || (otherBgData->bgTypeId != BATTLEGROUND_WS && otherBgData->bgTypeId != BATTLEGROUND_WG_CTF))
                continue;

            if (otherBgData->wsgState == WSGState::HoldCenter || otherBgData->wsgState == WSGState::DefendBase)
                FSBEvents::ScheduleBotEvent(creature, FSB_EVENT_WSG_REROLL_STATE, 10s);
        }
    }
}
