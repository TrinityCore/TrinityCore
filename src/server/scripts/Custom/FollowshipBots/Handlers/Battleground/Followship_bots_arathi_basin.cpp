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

#include "Followship_bots_arathi_basin.h"

#include "Battleground.h"
#include "BattlegroundPackets.h"
#include "Creature.h"
#include "GameObject.h"
#include "Log.h"
#include "Map.h"
#include "MotionMaster.h"
#include "Random.h"

#include <vector>

#include "Followship_bots_ai_base.h"
#include "Followship_bots_battleground_handler.h"
#include "Followship_bots_events_handler.h"
#include "Followship_bots_movement_handler.h"

#include "ScriptHelpers.h"

namespace FSBBattleground::ArathiBasin
{
    void SetBotState(Creature* bot, FSB_BattlegroundData* bgData, ABState newState)
    {
        if (!bot || !bgData)
            return;

        bgData->abState = newState;
        bgData->abCaptureTimer = 0;

        if (newState != ABState::None)
            FSBEvents::ScheduleBotEvent(bot, FSB_EVENT_BATTLEGROUND_STATE_CHAT, 2s, 10s);
    }

    GameObject* FindCapturePointByEntry(BattlegroundMap* bgMap, uint32 entry)
    {
        if (!bgMap || !entry)
            return nullptr;

        for (auto const& [guid, go] : bgMap->GetObjectsStore().Data.FindContainer<GameObject>())
        {
            if (go && go->GetEntry() == entry)
                return go;
        }

        return nullptr;
    }

    bool IsNodeOwnedByTeam(GameObject* capturePoint, Team team)
    {
        if (!capturePoint)
            return false;

        auto const& state = capturePoint->GetGOValue()->CapturePoint.State;
        if (team == ALLIANCE)
            return state == WorldPackets::Battleground::BattlegroundCapturePointState::AllianceCaptured;
        if (team == HORDE)
            return state == WorldPackets::Battleground::BattlegroundCapturePointState::HordeCaptured;
        return false;
    }

    uint32 CountBotsOnState(Creature* bot, BattlegroundMap* bgMap, ABState state)
    {
        if (!bot || !bgMap)
            return 0;

        std::vector<Creature*> teamBots = FSBBattleground::CollectBotsOnTeam(bgMap, FSBBattleground::GetBotTeam(bot));

        uint32 count = 0;
        for (Creature* otherBot : teamBots)
        {
            if (!otherBot || otherBot == bot)
                continue;

            FSB_BaseAI* otherAI = dynamic_cast<FSB_BaseAI*>(otherBot->AI());
            if (!otherAI)
                continue;

            FSB_BattlegroundData* otherData = otherAI->GetBattlegroundData();
            if (!otherData)
                continue;

            if (otherData->abState == state)
                ++count;
        }

        return count;
    }

    ABState RollNewABState(Creature* bot, BattlegroundMap* bgMap)
    {
        std::vector<ABState> allAttackStates = {
            ABState::AttackStables,
            ABState::AttackMine,
            ABState::AttackMill,
            ABState::AttackBlacksmith,
            ABState::AttackFarm
        };

        std::vector<ABState> allDefendStates = {
            ABState::DefendStables,
            ABState::DefendMine,
            ABState::DefendMill,
            ABState::DefendBlacksmith,
            ABState::DefendFarm
        };

        if (!bot || !bgMap)
            return allAttackStates[urand(0, allAttackStates.size() - 1)];

        Team team = FSBBattleground::GetBotTeam(bot);
        if (team != ALLIANCE && team != HORDE)
            return allAttackStates[urand(0, allAttackStates.size() - 1)];

        struct NodeEntry { uint32 entry; ABState attack; ABState defend; };
        static const NodeEntry nodes[] = {
            { BG_AB_OBJECTID_CAPTURE_POINT_STABLES,     ABState::AttackStables,    ABState::DefendStables },
            { BG_AB_OBJECTID_CAPTURE_POINT_GOLD_MINE,   ABState::AttackMine,       ABState::DefendMine },
            { BG_AB_OBJECTID_CAPTURE_POINT_LUMBER_MILL, ABState::AttackMill,       ABState::DefendMill },
            { BG_AB_OBJECTID_CAPTURE_POINT_BLACKSMITH,  ABState::AttackBlacksmith, ABState::DefendBlacksmith },
            { BG_AB_OBJECTID_CAPTURE_POINT_FARM,        ABState::AttackFarm,       ABState::DefendFarm }
        };

        // Tier 1: Attack nodes not owned by bot team, respecting MAX_ATTACKERS_PER_POINT
        std::vector<ABState> attackCandidates;
        for (auto const& node : nodes)
        {
            GameObject* cp = FindCapturePointByEntry(bgMap, node.entry);
            if (!cp)
                continue;

            if (!IsNodeOwnedByTeam(cp, team))
            {
                if (CountBotsOnState(bot, bgMap, node.attack) < MAX_ATTACKERS_PER_POINT)
                    attackCandidates.push_back(node.attack);
            }
        }

        if (!attackCandidates.empty())
            return attackCandidates[urand(0, attackCandidates.size() - 1)];

        // Tier 2: Defend nodes owned by bot team, respecting MAX_DEFENDERS_PER_POINT
        std::vector<ABState> defendCandidates;
        for (auto const& node : nodes)
        {
            GameObject* cp = FindCapturePointByEntry(bgMap, node.entry);
            if (!cp)
                continue;

            if (IsNodeOwnedByTeam(cp, team))
            {
                if (CountBotsOnState(bot, bgMap, node.defend) < MAX_DEFENDERS_PER_POINT)
                    defendCandidates.push_back(node.defend);
            }
        }

        if (!defendCandidates.empty())
            return defendCandidates[urand(0, defendCandidates.size() - 1)];

        // Tier 3: Fallback - pick a random defend state (override cap)
        TC_LOG_DEBUG("scripts.fsb.battleground", "FSB AB: Bot {} re-roll fallback to random defend (all caps full)", bot->GetName());
        return allDefendStates[urand(0, allDefendStates.size() - 1)];
    }

    GameObject* FindCapturePoint(Creature* bot, FSB_BattlegroundData* bgData)
    {
        BattlegroundMap* bgMap = bot->GetMap()->ToBattlegroundMap();
        if (!bgMap)
            return nullptr;

        uint32 entry = GetCapturePointEntryForState(bgData->abState);
        if (!entry)
            return nullptr;

        for (auto const& [guid, go] : bgMap->GetObjectsStore().Data.FindContainer<GameObject>())
        {
            if (go && go->GetEntry() == entry)
                return go;
        }

        return nullptr;
    }

    void TryAssaultCapturePoint(Creature* bot, FSB_BattlegroundData* bgData)
    {
        if (!bot || !bgData || !bot->IsAlive())
            return;

        GameObject* capturePoint = FindCapturePoint(bot, bgData);
        if (!capturePoint)
            return;

        if (!capturePoint->CanInteractWithCapturePoint(bot))
            return;

        TC_LOG_DEBUG("scripts.fsb.battleground", "FSB AB: Bot {} assaulting capture point {} state {}",
            bot->GetName(), capturePoint->GetEntry(), static_cast<uint32>(bgData->abState));

        Team botTeam = FSBBattleground::GetBotTeam(bot);
        TeamId botTeamId = (botTeam == HORDE) ? TEAM_HORDE : TEAM_ALLIANCE;

        if (capturePoint->GetGOValue()->CapturePoint.LastTeamCapture == botTeamId)
            ScriptHelpers::RecordBotBaseDefended(bot->GetGUID());
        else
            ScriptHelpers::RecordBotBaseAssaulted(bot->GetGUID());

        capturePoint->AssaultCapturePoint(bot);
    }

    void CheckCapturePointState(Creature* bot, FSB_BattlegroundData* bgData)
    {
        if (!bot || !bgData || !bot->IsAlive())
            return;

        if (bgData->abState == ABState::None)
            return;

        auto isAttackState = [](ABState s)
        {
            return s == ABState::AttackStables || s == ABState::AttackMine || s == ABState::AttackMill
                || s == ABState::AttackBlacksmith || s == ABState::AttackFarm;
        };

        auto isDefendState = [](ABState s)
        {
            return s == ABState::DefendStables || s == ABState::DefendMine || s == ABState::DefendMill
                || s == ABState::DefendBlacksmith || s == ABState::DefendFarm;
        };

        Team botTeam = FSBBattleground::GetBotTeam(bot);
        if (botTeam != ALLIANCE && botTeam != HORDE)
            return;

        // Handle defend states: check if node is still owned by bot team
        if (isDefendState(bgData->abState))
        {
            GameObject* capturePoint = FindCapturePoint(bot, bgData);
            if (!capturePoint)
                return;

            if (!IsNodeOwnedByTeam(capturePoint, botTeam))
            {
                ABState attackState = GetAttackStateForDefend(bgData->abState);
                if (attackState == ABState::None)
                    return;

                BattlegroundMap* bgMap = bot->GetMap()->ToBattlegroundMap();
                if (bgMap && CountBotsOnState(bot, bgMap, attackState) < MAX_ATTACKERS_PER_POINT)
                {
                    TC_LOG_DEBUG("scripts.fsb.battleground", "FSB AB: Bot {} lost node, switching {} -> {}",
                        bot->GetName(), static_cast<uint32>(bgData->abState), static_cast<uint32>(attackState));
                    SetBotState(bot, bgData, attackState);
                }
                else
                {
                    TC_LOG_DEBUG("scripts.fsb.battleground", "FSB AB: Bot {} lost node but attack cap full, re-rolling",
                        bot->GetName());
                    SetBotState(bot, bgData, ABState::None);
                    FSBEvents::ScheduleBotEvent(bot, FSB_EVENT_AB_REROLL_STATE, 2s);
                }
            }
            return;
        }

        if (!isAttackState(bgData->abState))
            return;

        GameObject* capturePoint = FindCapturePoint(bot, bgData);
        if (!capturePoint)
            return;

        // Check if node is already captured by bot's team -> switch to defend
        if (IsNodeOwnedByTeam(capturePoint, botTeam))
        {
            ABState defendState = GetDefendStateForAttack(bgData->abState);
            if (defendState == ABState::None)
                return;

            BattlegroundMap* bgMap = bot->GetMap()->ToBattlegroundMap();
            if (bgMap && CountBotsOnState(bot, bgMap, defendState) < MAX_DEFENDERS_PER_POINT)
            {
                TC_LOG_DEBUG("scripts.fsb.battleground", "FSB AB: Bot {} node captured, switching {} -> {}",
                    bot->GetName(), static_cast<uint32>(bgData->abState), static_cast<uint32>(defendState));
                SetBotState(bot, bgData, defendState);
            }
            else
            {
                TC_LOG_DEBUG("scripts.fsb.battleground", "FSB AB: Bot {} node captured but defender cap full, re-rolling",
                    bot->GetName());
                SetBotState(bot, bgData, ABState::None);
                FSBEvents::ScheduleBotEvent(bot, FSB_EVENT_AB_REROLL_STATE, 2s);
            }
            return;
        }

        // Timer countdown - wait before assaulting
        if (bgData->abCaptureTimer > 0)
        {
            if (bgData->abCaptureTimer >= 3000)
                bgData->abCaptureTimer -= 3000;
            else
                bgData->abCaptureTimer = 0;

            if (bgData->abCaptureTimer > 0)
                return;
        }

        // Timer is 0 - only assault if close enough and not in combat
        if (bot->GetDistance(capturePoint) > 5.0f)
            return;

        if (bot->IsInCombat())
            return;

        TryAssaultCapturePoint(bot, bgData);
    }

    void UpdateBot(Creature* bot, FSB_BattlegroundData* bgData)
    {
        if (!bot || !bgData || !bot->IsAlive())
            return;

        if (bgData->abState == ABState::None)
            return;

        BattlegroundMap* bgMap = bot->GetMap()->ToBattlegroundMap();
        if (!bgMap)
            return;

        Battleground* bg = bgMap->GetBG();
        if (!bg)
            return;

        if (bg->GetStatus() != STATUS_IN_PROGRESS)
            return;

        MovementGeneratorType moveType = FSBMovement::GetMovementType(bot);
        if (moveType == POINT_MOTION_TYPE || moveType == EFFECT_MOTION_TYPE || moveType == CHASE_MOTION_TYPE)
            return;

        auto isDefendState = [](ABState s)
            {
                return s == ABState::DefendStables || s == ABState::DefendMine || s == ABState::DefendMill
                    || s == ABState::DefendBlacksmith || s == ABState::DefendFarm;
            };

        FSB_BaseAI* baseAI = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!baseAI)
            return;

        if (isDefendState(bgData->abState) && (bot->IsInCombat() || baseAI->botGenericData.isRecovering))
            return;

        GameObject* capturePoint = FindCapturePoint(bot, bgData);
        if (!capturePoint)
        {
            TC_LOG_DEBUG("scripts.fsb.battleground", "FSB AB: UpdateBot bot {} state {} could not find capture point object",
                bot->GetName(), static_cast<uint32>(bgData->abState));
            return;
        }

        auto isAttackState = [](ABState s)
        {
            return s == ABState::AttackStables || s == ABState::AttackMine || s == ABState::AttackMill
                || s == ABState::AttackBlacksmith || s == ABState::AttackFarm;
        };

        Position const& goPos = capturePoint->GetPosition();

        float angle = frand(0.0f, 6.283185307f);
        float offsetRadius = isAttackState(bgData->abState) ? 3.0f : 10.0f;
        Position offset(std::cos(angle) * offsetRadius, std::sin(angle) * offsetRadius, 0.0f, 0.0f);
        Position targetPos = goPos.GetPositionWithOffset(offset);

        uint32 movementPoint = isAttackState(bgData->abState)
            ? FSBMovement::MOVEMENT_POINT_AB_ATTACK_NODE
            : FSBMovement::MOVEMENT_POINT_AB_DEFEND_NODE;

        bot->GetMotionMaster()->MovePoint(movementPoint, targetPos, true);
    }

    void OnMovementInform(Creature* bot, FSB_BattlegroundData* bgData, uint32 /*type*/, uint32 id)
    {
        if (!bot || !bgData || !bot->IsAlive())
            return;

        if (id == FSBMovement::MOVEMENT_POINT_AB_ATTACK_NODE)
        {
            bgData->abCaptureTimer = 10000;
            FSBEvents::ScheduleBotEvent(bot, FSB_EVENT_AB_CHECK_CAPTURE, 1s);
            return;
        }

        if (id == FSBMovement::MOVEMENT_POINT_AB_DEFEND_NODE)
        {
            // No-op; the tick handles the re-shuffle.
            return;
        }
    }
}
