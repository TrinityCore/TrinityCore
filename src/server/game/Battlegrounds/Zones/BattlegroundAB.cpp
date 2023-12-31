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

#include "BattlegroundAB.h"
#include "BattlegroundMgr.h"
#include "BattlegroundPackets.h"
#include "BattlegroundScore.h"
#include "Creature.h"
#include "GameObject.h"
#include "Log.h"
#include "Map.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "SpellInfo.h"

enum ArathiBasinPvpStats
{
    PVP_STAT_BASES_ASSAULTED    = 926,
    PVP_STAT_BASES_DEFENDED     = 927,
};

BattlegroundAB::BattlegroundAB(BattlegroundTemplate const* battlegroundTemplate) : Battleground(battlegroundTemplate)
{
    m_IsInformedNearVictory = false;
    BgObjects.resize(0);
    BgCreatures.resize(0);
    m_lastTick = 0;

    for (uint8 i = 0; i < PVP_TEAMS_COUNT; ++i)
    {
        m_HonorScoreTics[i] = 0;
        m_ReputationScoreTics[i] = 0;
    }

    m_HonorTics = 0;
    m_ReputationTics = 0;
}

BattlegroundAB::~BattlegroundAB() { }

void BattlegroundAB::PostUpdateImpl(uint32 diff)
{
    if (GetStatus() == STATUS_IN_PROGRESS)
    {
        // Accumulate points
        m_lastTick += diff;
        if (m_lastTick > BG_AB_TickInterval)
        {
            m_lastTick -= BG_AB_TickInterval;

            uint8 ally = 0, horde = 0;
            _CalculateTeamNodes(ally, horde);
            uint8 points[PVP_TEAMS_COUNT] = { ally, horde };

            for (uint8 team = 0; team < PVP_TEAMS_COUNT; ++team)
            {
                if (!points[team])
                    continue;

                m_TeamScores[team] += BG_AB_TickPoints[points[team]];
                m_HonorScoreTics[team] += BG_AB_TickPoints[points[team]];
                m_ReputationScoreTics[team] += BG_AB_TickPoints[points[team]];

                if (m_ReputationScoreTics[team] >= m_ReputationTics)
                {
                    (team == TEAM_ALLIANCE) ? RewardReputationToTeam(509, 10, ALLIANCE) : RewardReputationToTeam(510, 10, HORDE);
                    m_ReputationScoreTics[team] -= m_ReputationTics;
                }

                if (m_HonorScoreTics[team] >= m_HonorTics)
                {
                    RewardHonorToTeam(GetBonusHonorFromKill(1), (team == TEAM_ALLIANCE) ? ALLIANCE : HORDE);
                    m_HonorScoreTics[team] -= m_HonorTics;
                }

                if (!m_IsInformedNearVictory && m_TeamScores[team] > BG_AB_WARNING_NEAR_VICTORY_SCORE)
                {
                    if (team == TEAM_ALLIANCE)
                    {
                        SendBroadcastText(BG_AB_TEXT_ALLIANCE_NEAR_VICTORY, CHAT_MSG_BG_SYSTEM_NEUTRAL);
                        PlaySoundToAll(BG_AB_SOUND_NEAR_VICTORY_ALLIANCE);
                    }
                    else
                    {
                        SendBroadcastText(BG_AB_TEXT_HORDE_NEAR_VICTORY, CHAT_MSG_BG_SYSTEM_NEUTRAL);
                        PlaySoundToAll(BG_AB_SOUND_NEAR_VICTORY_HORDE);
                    }
                    m_IsInformedNearVictory = true;
                }

                if (m_TeamScores[team] > BG_AB_MAX_TEAM_SCORE)
                    m_TeamScores[team] = BG_AB_MAX_TEAM_SCORE;

                if (team == TEAM_ALLIANCE)
                    UpdateWorldState(BG_AB_WS_RESOURCES_ALLY, m_TeamScores[team]);
                else
                    UpdateWorldState(BG_AB_WS_RESOURCES_HORDE, m_TeamScores[team]);
                // update achievement flags
                // we increased m_TeamScores[team] so we just need to check if it is 500 more than other teams resources
                uint8 otherTeam = (team + 1) % PVP_TEAMS_COUNT;
                if (m_TeamScores[team] > m_TeamScores[otherTeam] + 500)
                {
                    if (team == TEAM_ALLIANCE)
                        UpdateWorldState(BG_AB_WS_HAD_500_DISADVANTAGE_HORDE, 1);
                    else
                        UpdateWorldState(BG_AB_WS_HAD_500_DISADVANTAGE_ALLIANCE, 1);
                }
            }

            UpdateWorldState(BG_AB_WS_OCCUPIED_BASES_ALLY, ally);
            UpdateWorldState(BG_AB_WS_OCCUPIED_BASES_HORDE, horde);
        }

        // Test win condition
        if (m_TeamScores[TEAM_ALLIANCE] >= BG_AB_MAX_TEAM_SCORE)
            EndBattleground(ALLIANCE);
        else if (m_TeamScores[TEAM_HORDE] >= BG_AB_MAX_TEAM_SCORE)
            EndBattleground(HORDE);
    }
}

void BattlegroundAB::StartingEventOpenDoors()
{
    // Achievement: Let's Get This Done
    TriggerGameEvent(AB_EVENT_START_BATTLE);
}

void BattlegroundAB::HandleAreaTrigger(Player* player, uint32 trigger, bool entered)
{
    switch (trigger)
    {
        case 6635: // Horde Start
        case 6634: // Alliance Start
            if (GetStatus() == STATUS_WAIT_JOIN && !entered)
                TeleportPlayerToExploitLocation(player);
            break;
        case 3948:                                          // Arathi Basin Alliance Exit.
        case 3949:                                          // Arathi Basin Horde Exit.
        case 3866:                                          // Stables
        case 3869:                                          // Gold Mine
        case 3867:                                          // Farm
        case 3868:                                          // Lumber Mill
        case 3870:                                          // Black Smith
        case 4020:                                          // Unk1
        case 4021:                                          // Unk2
        case 4674:                                          // Unk3
            //break;
        default:
            Battleground::HandleAreaTrigger(player, trigger, entered);
            break;
    }
}

void BattlegroundAB::_CalculateTeamNodes(uint8& alliance, uint8& horde)
{
    alliance = 0;
    horde = 0;

    if (BattlegroundMap* map = FindBgMap())
    {
        for (ObjectGuid const& guid : _capturePoints)
        {
            if (GameObject* capturePoint = map->GetGameObject(guid))
            {
                int32 wsValue = map->GetWorldStateValue(capturePoint->GetGOInfo()->capturePoint.worldState1);
                switch (WorldPackets::Battleground::BattlegroundCapturePointState(wsValue))
                {
                    case WorldPackets::Battleground::BattlegroundCapturePointState::AllianceCaptured:
                        ++alliance;
                        break;
                    case WorldPackets::Battleground::BattlegroundCapturePointState::HordeCaptured:
                        ++horde;
                        break;
                    default:
                        break;
                }
            }
        }
    }
}

Team BattlegroundAB::GetPrematureWinner()
{
    // How many bases each team owns
    uint8 ally = 0, horde = 0;
    _CalculateTeamNodes(ally, horde);

    if (ally > horde)
        return ALLIANCE;
    else if (horde > ally)
        return HORDE;

    // If the values are equal, fall back to the original result (based on number of players on each team)
    return Battleground::GetPrematureWinner();
}

void BattlegroundAB::ProcessEvent(WorldObject* /*source*/, uint32 eventId, WorldObject* invoker)
{
    switch (eventId)
    {
        case AB_EVENT_START_BATTLE:
        {
            for (ObjectGuid const& guid : _creaturesToRemoveOnMatchStart)
                if (Creature* creature = GetBgMap()->GetCreature(guid))
                    creature->DespawnOrUnsummon();

            for (ObjectGuid const& guid : _gameobjectsToRemoveOnMatchStart)
                if (GameObject* gameObject = GetBgMap()->GetGameObject(guid))
                    gameObject->DespawnOrUnsummon();

            for (ObjectGuid const& guid : _doors)
            {
                if (GameObject* gameObject = GetBgMap()->GetGameObject(guid))
                {
                    gameObject->UseDoorOrButton();
                    gameObject->DespawnOrUnsummon(3s);
                }
            }
            break;
        }
        case AB_EVENT_CONTESTED_BLACKSMITH_ALLIANCE:
            UpdateWorldState(BG_AB_WS_BLACKSMITH_ALLIANCE_CONTROL_STATE, 1);
            UpdateWorldState(BG_AB_WS_BLACKSMITH_HORDE_CONTROL_STATE, 0);
            PlaySoundToAll(BG_AB_SOUND_NODE_ASSAULTED_ALLIANCE);
            if (Player* player = invoker->ToPlayer())
                UpdatePvpStat(player, PVP_STAT_BASES_ASSAULTED, 1);
            break;
        case AB_EVENT_DEFENDED_BLACKSMITH_ALLIANCE:
            UpdateWorldState(BG_AB_WS_BLACKSMITH_ALLIANCE_CONTROL_STATE, 2);
            UpdateWorldState(BG_AB_WS_BLACKSMITH_HORDE_CONTROL_STATE, 0);
            PlaySoundToAll(BG_AB_SOUND_NODE_CAPTURED_ALLIANCE);
            if (Player* player = invoker->ToPlayer())
                UpdatePvpStat(player, PVP_STAT_BASES_DEFENDED, 1);
            break;
        case AB_EVENT_CAPTURE_BLACKSMITH_ALLIANCE:
            UpdateWorldState(BG_AB_WS_BLACKSMITH_ALLIANCE_CONTROL_STATE, 2);
            PlaySoundToAll(BG_AB_SOUND_NODE_CAPTURED_ALLIANCE);
            break;
        case AB_EVENT_CONTESTED_BLACKSMITH_HORDE:
            UpdateWorldState(BG_AB_WS_BLACKSMITH_ALLIANCE_CONTROL_STATE, 0);
            UpdateWorldState(BG_AB_WS_BLACKSMITH_HORDE_CONTROL_STATE, 1);
            PlaySoundToAll(BG_AB_SOUND_NODE_ASSAULTED_HORDE);
            if (Player* player = invoker->ToPlayer())
                UpdatePvpStat(player, PVP_STAT_BASES_ASSAULTED, 1);
            break;
        case AB_EVENT_DEFENDED_BLACKSMITH_HORDE:
            UpdateWorldState(BG_AB_WS_BLACKSMITH_ALLIANCE_CONTROL_STATE, 0);
            UpdateWorldState(BG_AB_WS_BLACKSMITH_HORDE_CONTROL_STATE, 2);
            PlaySoundToAll(BG_AB_SOUND_NODE_CAPTURED_HORDE);
            if (Player* player = invoker->ToPlayer())
                UpdatePvpStat(player, PVP_STAT_BASES_DEFENDED, 1);
            break;
        case AB_EVENT_CAPTURE_BLACKSMITH_HORDE:
            UpdateWorldState(BG_AB_WS_BLACKSMITH_HORDE_CONTROL_STATE, 2);
            PlaySoundToAll(BG_AB_SOUND_NODE_CAPTURED_HORDE);
            break;
        case AB_EVENT_CONTESTED_FARM_ALLIANCE:
            UpdateWorldState(BG_AB_WS_FARM_ALLIANCE_CONTROL_STATE, 1);
            UpdateWorldState(BG_AB_WS_FARM_HORDE_CONTROL_STATE, 0);
            PlaySoundToAll(BG_AB_SOUND_NODE_ASSAULTED_ALLIANCE);
            if (Player* player = invoker->ToPlayer())
                UpdatePvpStat(player, PVP_STAT_BASES_ASSAULTED, 1);
            break;
        case AB_EVENT_DEFENDED_FARM_ALLIANCE:
            UpdateWorldState(BG_AB_WS_FARM_ALLIANCE_CONTROL_STATE, 2);
            UpdateWorldState(BG_AB_WS_FARM_HORDE_CONTROL_STATE, 0);
            PlaySoundToAll(BG_AB_SOUND_NODE_CAPTURED_ALLIANCE);
            if (Player* player = invoker->ToPlayer())
                UpdatePvpStat(player, PVP_STAT_BASES_DEFENDED, 1);
            break;
        case AB_EVENT_CAPTURE_FARM_ALLIANCE:
            UpdateWorldState(BG_AB_WS_FARM_ALLIANCE_CONTROL_STATE, 2);
            PlaySoundToAll(BG_AB_SOUND_NODE_CAPTURED_ALLIANCE);
            break;
        case AB_EVENT_CONTESTED_FARM_HORDE:
            UpdateWorldState(BG_AB_WS_FARM_ALLIANCE_CONTROL_STATE, 0);
            UpdateWorldState(BG_AB_WS_FARM_HORDE_CONTROL_STATE, 1);
            PlaySoundToAll(BG_AB_SOUND_NODE_ASSAULTED_HORDE);
            if (Player* player = invoker->ToPlayer())
                UpdatePvpStat(player, PVP_STAT_BASES_ASSAULTED, 1);
            break;
        case AB_EVENT_DEFENDED_FARM_HORDE:
            UpdateWorldState(BG_AB_WS_FARM_ALLIANCE_CONTROL_STATE, 0);
            UpdateWorldState(BG_AB_WS_FARM_HORDE_CONTROL_STATE, 2);
            PlaySoundToAll(BG_AB_SOUND_NODE_CAPTURED_HORDE);
            if (Player* player = invoker->ToPlayer())
                UpdatePvpStat(player, PVP_STAT_BASES_DEFENDED, 1);
            break;
        case AB_EVENT_CAPTURE_FARM_HORDE:
            UpdateWorldState(BG_AB_WS_FARM_HORDE_CONTROL_STATE, 2);
            PlaySoundToAll(BG_AB_SOUND_NODE_CAPTURED_HORDE);
            break;
        case AB_EVENT_CONTESTED_GOLD_MINE_ALLIANCE:
            UpdateWorldState(BG_AB_WS_GOLD_MINE_ALLIANCE_CONTROL_STATE, 1);
            UpdateWorldState(BG_AB_WS_GOLD_MINE_HORDE_CONTROL_STATE, 0);
            PlaySoundToAll(BG_AB_SOUND_NODE_ASSAULTED_ALLIANCE);
            if (Player* player = invoker->ToPlayer())
                UpdatePvpStat(player, PVP_STAT_BASES_ASSAULTED, 1);
            break;
        case AB_EVENT_DEFENDED_GOLD_MINE_ALLIANCE:
            UpdateWorldState(BG_AB_WS_GOLD_MINE_ALLIANCE_CONTROL_STATE, 2);
            UpdateWorldState(BG_AB_WS_GOLD_MINE_HORDE_CONTROL_STATE, 0);
            PlaySoundToAll(BG_AB_SOUND_NODE_CAPTURED_ALLIANCE);
            if (Player* player = invoker->ToPlayer())
                UpdatePvpStat(player, PVP_STAT_BASES_DEFENDED, 1);
            break;
        case AB_EVENT_CAPTURE_GOLD_MINE_ALLIANCE:
            UpdateWorldState(BG_AB_WS_GOLD_MINE_ALLIANCE_CONTROL_STATE, 2);
            PlaySoundToAll(BG_AB_SOUND_NODE_CAPTURED_ALLIANCE);
            break;
        case AB_EVENT_CONTESTED_GOLD_MINE_HORDE:
            UpdateWorldState(BG_AB_WS_GOLD_MINE_ALLIANCE_CONTROL_STATE, 0);
            UpdateWorldState(BG_AB_WS_GOLD_MINE_HORDE_CONTROL_STATE, 1);
            PlaySoundToAll(BG_AB_SOUND_NODE_ASSAULTED_HORDE);
            if (Player* player = invoker->ToPlayer())
                UpdatePvpStat(player, PVP_STAT_BASES_ASSAULTED, 1);
            break;
        case AB_EVENT_DEFENDED_GOLD_MINE_HORDE:
            UpdateWorldState(BG_AB_WS_GOLD_MINE_ALLIANCE_CONTROL_STATE, 0);
            UpdateWorldState(BG_AB_WS_GOLD_MINE_HORDE_CONTROL_STATE, 2);
            PlaySoundToAll(BG_AB_SOUND_NODE_CAPTURED_HORDE);
            if (Player* player = invoker->ToPlayer())
                UpdatePvpStat(player, PVP_STAT_BASES_DEFENDED, 1);
            break;
        case AB_EVENT_CAPTURE_GOLD_MINE_HORDE:
            UpdateWorldState(BG_AB_WS_GOLD_MINE_HORDE_CONTROL_STATE, 2);
            PlaySoundToAll(BG_AB_SOUND_NODE_CAPTURED_HORDE);
            break;
        case AB_EVENT_CONTESTED_LUMBER_MILL_ALLIANCE:
            UpdateWorldState(BG_AB_WS_LUMBER_MILL_ALLIANCE_CONTROL_STATE, 1);
            UpdateWorldState(BG_AB_WS_LUMBER_MILL_HORDE_CONTROL_STATE, 0);
            PlaySoundToAll(BG_AB_SOUND_NODE_ASSAULTED_ALLIANCE);
            if (Player* player = invoker->ToPlayer())
                UpdatePvpStat(player, PVP_STAT_BASES_ASSAULTED, 1);
            break;
        case AB_EVENT_DEFENDED_LUMBER_MILL_ALLIANCE:
            UpdateWorldState(BG_AB_WS_LUMBER_MILL_ALLIANCE_CONTROL_STATE, 2);
            UpdateWorldState(BG_AB_WS_LUMBER_MILL_HORDE_CONTROL_STATE, 0);
            PlaySoundToAll(BG_AB_SOUND_NODE_CAPTURED_ALLIANCE);
            if (Player* player = invoker->ToPlayer())
                UpdatePvpStat(player, PVP_STAT_BASES_DEFENDED, 1);
            break;
        case AB_EVENT_CAPTURE_LUMBER_MILL_ALLIANCE:
            UpdateWorldState(BG_AB_WS_LUMBER_MILL_ALLIANCE_CONTROL_STATE, 2);
            PlaySoundToAll(BG_AB_SOUND_NODE_CAPTURED_ALLIANCE);
            break;
        case AB_EVENT_CONTESTED_LUMBER_MILL_HORDE:
            UpdateWorldState(BG_AB_WS_LUMBER_MILL_ALLIANCE_CONTROL_STATE, 0);
            UpdateWorldState(BG_AB_WS_LUMBER_MILL_HORDE_CONTROL_STATE, 1);
            PlaySoundToAll(BG_AB_SOUND_NODE_ASSAULTED_HORDE);
            if (Player* player = invoker->ToPlayer())
                UpdatePvpStat(player, PVP_STAT_BASES_ASSAULTED, 1);
            break;
        case AB_EVENT_DEFENDED_LUMBER_MILL_HORDE:
            UpdateWorldState(BG_AB_WS_LUMBER_MILL_ALLIANCE_CONTROL_STATE, 0);
            UpdateWorldState(BG_AB_WS_LUMBER_MILL_HORDE_CONTROL_STATE, 2);
            PlaySoundToAll(BG_AB_SOUND_NODE_CAPTURED_HORDE);
            if (Player* player = invoker->ToPlayer())
                UpdatePvpStat(player, PVP_STAT_BASES_DEFENDED, 1);
            break;
        case AB_EVENT_CAPTURE_LUMBER_MILL_HORDE:
            UpdateWorldState(BG_AB_WS_LUMBER_MILL_HORDE_CONTROL_STATE, 2);
            PlaySoundToAll(BG_AB_SOUND_NODE_CAPTURED_HORDE);
            break;
        case AB_EVENT_CONTESTED_STABLES_ALLIANCE:
            UpdateWorldState(BG_AB_WS_STABLES_ALLIANCE_CONTROL_STATE, 1);
            UpdateWorldState(BG_AB_WS_STABLES_HORDE_CONTROL_STATE, 0);
            PlaySoundToAll(BG_AB_SOUND_NODE_ASSAULTED_ALLIANCE);
            if (Player* player = invoker->ToPlayer())
                UpdatePvpStat(player, PVP_STAT_BASES_ASSAULTED, 1);
            break;
        case AB_EVENT_DEFENDED_STABLES_ALLIANCE:
            UpdateWorldState(BG_AB_WS_STABLES_ALLIANCE_CONTROL_STATE, 2);
            UpdateWorldState(BG_AB_WS_STABLES_HORDE_CONTROL_STATE, 0);
            PlaySoundToAll(BG_AB_SOUND_NODE_CAPTURED_ALLIANCE);
            if (Player* player = invoker->ToPlayer())
                UpdatePvpStat(player, PVP_STAT_BASES_DEFENDED, 1);
            break;
        case AB_EVENT_CAPTURE_STABLES_ALLIANCE:
            UpdateWorldState(BG_AB_WS_STABLES_ALLIANCE_CONTROL_STATE, 2);
            PlaySoundToAll(BG_AB_SOUND_NODE_CAPTURED_ALLIANCE);
            break;
        case AB_EVENT_CONTESTED_STABLES_HORDE:
            UpdateWorldState(BG_AB_WS_STABLES_ALLIANCE_CONTROL_STATE, 0);
            UpdateWorldState(BG_AB_WS_STABLES_HORDE_CONTROL_STATE, 1);
            PlaySoundToAll(BG_AB_SOUND_NODE_ASSAULTED_HORDE);
            if (Player* player = invoker->ToPlayer())
                UpdatePvpStat(player, PVP_STAT_BASES_ASSAULTED, 1);
            break;
        case AB_EVENT_DEFENDED_STABLES_HORDE:
            UpdateWorldState(BG_AB_WS_STABLES_ALLIANCE_CONTROL_STATE, 0);
            UpdateWorldState(BG_AB_WS_STABLES_HORDE_CONTROL_STATE, 2);
            PlaySoundToAll(BG_AB_SOUND_NODE_CAPTURED_HORDE);
            if (Player* player = invoker->ToPlayer())
                UpdatePvpStat(player, PVP_STAT_BASES_DEFENDED, 1);
            break;
        case AB_EVENT_CAPTURE_STABLES_HORDE:
            UpdateWorldState(BG_AB_WS_STABLES_HORDE_CONTROL_STATE, 2);
            PlaySoundToAll(BG_AB_SOUND_NODE_CAPTURED_HORDE);
            break;
        default:
            TC_LOG_WARN("bg.events", "BattlegroundAB::ProcessEvent: Unhandled event %u.", eventId);
            break;
    }
}

void BattlegroundAB::OnCreatureCreate(Creature* creature)
{
    switch (creature->GetEntry())
    {
        case BG_AB_NPC_THE_BLACK_BRIDE:
        case BG_AB_NPC_RADULF_LEDER:
            _creaturesToRemoveOnMatchStart.push_back(creature->GetGUID());
            break;
        default:
            break;
    }
}

void BattlegroundAB::OnGameObjectCreate(GameObject* gameObject)
{
    if (gameObject->GetGOInfo()->type == GAMEOBJECT_TYPE_CAPTURE_POINT)
        _capturePoints.push_back(gameObject->GetGUID());

    switch (gameObject->GetEntry())
    {
        case BG_AB_OBJECTID_GHOST_GATE:
            _gameobjectsToRemoveOnMatchStart.push_back(gameObject->GetGUID());
            break;
        case BG_AB_OBJECTID_ALLIANCE_DOOR:
        case BG_AB_OBJECTID_HORDE_DOOR:
            _doors.push_back(gameObject->GetGUID());
            break;
        default:
            break;
    }
}

bool BattlegroundAB::SetupBattleground()
{
    UpdateWorldState(BG_AB_WS_RESOURCES_MAX, BG_AB_MAX_TEAM_SCORE);
    UpdateWorldState(BG_AB_WS_RESOURCES_WARNING, BG_AB_WARNING_NEAR_VICTORY_SCORE);

    return true;
}

void BattlegroundAB::Reset()
{
    //call parent's class reset
    Battleground::Reset();

    m_TeamScores[TEAM_ALLIANCE]          = 0;
    m_TeamScores[TEAM_HORDE]             = 0;
    m_lastTick                           = 0;
    m_HonorScoreTics[TEAM_ALLIANCE]      = 0;
    m_HonorScoreTics[TEAM_HORDE]         = 0;
    m_ReputationScoreTics[TEAM_ALLIANCE] = 0;
    m_ReputationScoreTics[TEAM_HORDE]    = 0;
    m_IsInformedNearVictory                 = false;
    bool isBGWeekend = sBattlegroundMgr->IsBGWeekend(GetTypeID());
    m_HonorTics = (isBGWeekend) ? BG_AB_ABBGWeekendHonorTicks : BG_AB_NotABBGWeekendHonorTicks;
    m_ReputationTics = (isBGWeekend) ? BG_AB_ABBGWeekendReputationTicks : BG_AB_NotABBGWeekendReputationTicks;

    _creaturesToRemoveOnMatchStart.clear();
    _gameobjectsToRemoveOnMatchStart.clear();
    _doors.clear();
    _capturePoints.clear();
}

void BattlegroundAB::EndBattleground(Team winner)
{
    // Win reward
    if (winner == ALLIANCE)
        RewardHonorToTeam(GetBonusHonorFromKill(1), ALLIANCE);
    if (winner == HORDE)
        RewardHonorToTeam(GetBonusHonorFromKill(1), HORDE);
    // Complete map_end rewards (even if no team wins)
    RewardHonorToTeam(GetBonusHonorFromKill(1), HORDE);
    RewardHonorToTeam(GetBonusHonorFromKill(1), ALLIANCE);

    Battleground::EndBattleground(winner);
}

WorldSafeLocsEntry const* BattlegroundAB::GetClosestGraveyard(Player* player)
{
    return sObjectMgr->GetClosestGraveyard(player->GetWorldLocation(), player->GetTeam(), player);
}

WorldSafeLocsEntry const* BattlegroundAB::GetExploitTeleportLocation(Team team)
{
    return sObjectMgr->GetWorldSafeLoc(team == ALLIANCE ? AB_EXPLOIT_TELEPORT_LOCATION_ALLIANCE : AB_EXPLOIT_TELEPORT_LOCATION_HORDE);
}
