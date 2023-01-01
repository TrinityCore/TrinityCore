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

#include "BattlegroundEY.h"
#include "BattlegroundMgr.h"
#include "BattlegroundPackets.h"
#include "Creature.h"
#include "GameObject.h"
#include "Log.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "Random.h"
#include "SpellInfo.h"
#include "Util.h"

// these variables aren't used outside of this file, so declare them only here
uint32 BG_EY_HonorScoreTicks[BG_HONOR_MODE_NUM] =
{
    260, // normal honor
    160  // holiday
};

BattlegroundEY::BattlegroundEY(BattlegroundTemplate const* battlegroundTemplate) : Battleground(battlegroundTemplate)
{
    m_BuffChange = true;
    BgObjects.resize(BG_EY_OBJECT_MAX);
    BgCreatures.resize(BG_EY_CREATURES_MAX);
    m_Points_Trigger[FEL_REAVER] = TR_FEL_REAVER_BUFF;
    m_Points_Trigger[BLOOD_ELF] = TR_BLOOD_ELF_BUFF;
    m_Points_Trigger[DRAENEI_RUINS] = TR_DRAENEI_RUINS_BUFF;
    m_Points_Trigger[MAGE_TOWER] = TR_MAGE_TOWER_BUFF;
    m_HonorScoreTics[TEAM_ALLIANCE] = 0;
    m_HonorScoreTics[TEAM_HORDE] = 0;
    m_TeamPointsCount[TEAM_ALLIANCE] = 0;
    m_TeamPointsCount[TEAM_HORDE] = 0;
    m_FlagKeeper.Clear();
    m_DroppedFlagGUID.Clear();
    m_FlagCapturedBgObjectType = 0;
    m_FlagState = BG_EY_FLAG_STATE_ON_BASE;
    m_FlagsTimer = 0;
    m_TowerCapCheckTimer = 0;
    m_PointAddingTimer = 0;
    m_HonorTics = 0;

    for (uint8 i = 0; i < EY_POINTS_MAX; ++i)
    {
        m_PointOwnedByTeam[i] = EY_POINT_NO_OWNER;
        m_PointState[i] = EY_POINT_STATE_UNCONTROLLED;
        m_PointBarStatus[i] = BG_EY_PROGRESS_BAR_STATE_MIDDLE;
        m_LastPointCaptureStatus[i] = BattlegroundPointCaptureStatus::Neutral;
    }

    for (uint8 i = 0; i < 2 * EY_POINTS_MAX; ++i)
        m_CurrentPointPlayersCount[i] = 0;
}

BattlegroundEY::~BattlegroundEY() { }

void BattlegroundEY::PostUpdateImpl(uint32 diff)
{
    if (GetStatus() == STATUS_IN_PROGRESS)
    {
        m_PointAddingTimer -= diff;
        if (m_PointAddingTimer <= 0)
        {
            m_PointAddingTimer = BG_EY_FPOINTS_TICK_TIME;
            if (m_TeamPointsCount[TEAM_ALLIANCE] > 0)
                AddPoints(ALLIANCE, BG_EY_TickPoints[m_TeamPointsCount[TEAM_ALLIANCE] - 1]);
            if (m_TeamPointsCount[TEAM_HORDE] > 0)
                AddPoints(HORDE, BG_EY_TickPoints[m_TeamPointsCount[TEAM_HORDE] - 1]);
        }

        if (m_FlagState == BG_EY_FLAG_STATE_WAIT_RESPAWN || m_FlagState == BG_EY_FLAG_STATE_ON_GROUND)
        {
            m_FlagsTimer -= diff;

            if (m_FlagsTimer < 0)
            {
                m_FlagsTimer = 0;
                if (m_FlagState == BG_EY_FLAG_STATE_WAIT_RESPAWN)
                    RespawnFlag(true);
                else
                    RespawnFlagAfterDrop();
            }
        }

        m_TowerCapCheckTimer -= diff;
        if (m_TowerCapCheckTimer <= 0)
        {
            //check if player joined point
            /*I used this order of calls, because although we will check if one player is in gameobject's distance 2 times
              but we can count of players on current point in CheckSomeoneLeftPoint
            */
            CheckSomeoneJoinedPoint();
            //check if player left point
            CheckSomeoneLeftPoint();
            UpdatePointStatuses();
            m_TowerCapCheckTimer = BG_EY_FPOINTS_TICK_TIME;
        }
    }
}

void BattlegroundEY::StartingEventCloseDoors()
{
    SpawnBGObject(BG_EY_OBJECT_DOOR_A, RESPAWN_IMMEDIATELY);
    SpawnBGObject(BG_EY_OBJECT_DOOR_H, RESPAWN_IMMEDIATELY);

    for (uint32 i = BG_EY_OBJECT_A_BANNER_FEL_REAVER_CENTER; i < BG_EY_OBJECT_MAX; ++i)
        SpawnBGObject(i, RESPAWN_ONE_DAY);
}

void BattlegroundEY::StartingEventOpenDoors()
{
    SpawnBGObject(BG_EY_OBJECT_DOOR_A, RESPAWN_ONE_DAY);
    SpawnBGObject(BG_EY_OBJECT_DOOR_H, RESPAWN_ONE_DAY);

    for (uint32 i = BG_EY_OBJECT_N_BANNER_FEL_REAVER_CENTER; i <= BG_EY_OBJECT_FLAG_NETHERSTORM; ++i)
        SpawnBGObject(i, RESPAWN_IMMEDIATELY);
    for (uint32 i = 0; i < EY_POINTS_MAX; ++i)
    {
        //randomly spawn buff
        uint8 buff = urand(0, 2);
        SpawnBGObject(BG_EY_OBJECT_SPEEDBUFF_FEL_REAVER + buff + i * 3, RESPAWN_IMMEDIATELY);
    }

    // Achievement: Flurry
    TriggerGameEvent(BG_EY_EVENT_START_BATTLE);
}

void BattlegroundEY::AddPoints(uint32 Team, uint32 Points)
{
    TeamId team_index = GetTeamIndexByTeamId(Team);
    m_TeamScores[team_index] += Points;
    m_HonorScoreTics[team_index] += Points;
    if (m_HonorScoreTics[team_index] >= m_HonorTics)
    {
        RewardHonorToTeam(GetBonusHonorFromKill(1), Team);
        m_HonorScoreTics[team_index] -= m_HonorTics;
    }
    UpdateTeamScore(team_index);
}

BattlegroundPointCaptureStatus BattlegroundEY::GetPointCaptureStatus(uint32 point) const
{
    if (m_PointBarStatus[point] >= BG_EY_PROGRESS_BAR_ALI_CONTROLLED)
        return BattlegroundPointCaptureStatus::AllianceControlled;

    if (m_PointBarStatus[point] <= BG_EY_PROGRESS_BAR_HORDE_CONTROLLED)
        return BattlegroundPointCaptureStatus::HordeControlled;

    if (m_CurrentPointPlayersCount[2 * point] == m_CurrentPointPlayersCount[2 * point + 1])
        return BattlegroundPointCaptureStatus::Neutral;

    return m_CurrentPointPlayersCount[2 * point] > m_CurrentPointPlayersCount[2 * point + 1]
        ? BattlegroundPointCaptureStatus::AllianceCapturing
        : BattlegroundPointCaptureStatus::HordeCapturing;
}

void BattlegroundEY::CheckSomeoneJoinedPoint()
{
    GameObject* obj = nullptr;
    for (uint8 i = 0; i < EY_POINTS_MAX; ++i)
    {
        obj = GetBgMap()->GetGameObject(BgObjects[BG_EY_OBJECT_TOWER_CAP_FEL_REAVER + i]);
        if (obj)
        {
            uint8 j = 0;
            while (j < m_PlayersNearPoint[EY_POINTS_MAX].size())
            {
                Player* player = ObjectAccessor::FindPlayer(m_PlayersNearPoint[EY_POINTS_MAX][j]);
                if (!player)
                {
                    TC_LOG_ERROR("bg.battleground", "BattlegroundEY:CheckSomeoneJoinedPoint: Player (%s) could not be found!", m_PlayersNearPoint[EY_POINTS_MAX][j].ToString().c_str());
                    ++j;
                    continue;
                }
                if (player->CanCaptureTowerPoint() && player->IsWithinDistInMap(obj, BG_EY_POINT_RADIUS))
                {
                    //player joined point!
                    //show progress bar
                    player->SendUpdateWorldState(PROGRESS_BAR_PERCENT_GREY, BG_EY_PROGRESS_BAR_PERCENT_GREY);
                    player->SendUpdateWorldState(PROGRESS_BAR_STATUS, m_PointBarStatus[i]);
                    player->SendUpdateWorldState(PROGRESS_BAR_SHOW, BG_EY_PROGRESS_BAR_SHOW);
                    //add player to point
                    m_PlayersNearPoint[i].push_back(m_PlayersNearPoint[EY_POINTS_MAX][j]);
                    //remove player from "free space"
                    m_PlayersNearPoint[EY_POINTS_MAX].erase(m_PlayersNearPoint[EY_POINTS_MAX].begin() + j);
                }
                else
                    ++j;
            }
        }
    }
}

void BattlegroundEY::CheckSomeoneLeftPoint()
{
    //reset current point counts
    for (uint8 i = 0; i < 2*EY_POINTS_MAX; ++i)
        m_CurrentPointPlayersCount[i] = 0;
    GameObject* obj = nullptr;
    for (uint8 i = 0; i < EY_POINTS_MAX; ++i)
    {
        obj = GetBgMap()->GetGameObject(BgObjects[BG_EY_OBJECT_TOWER_CAP_FEL_REAVER + i]);
        if (obj)
        {
            uint8 j = 0;
            while (j < m_PlayersNearPoint[i].size())
            {
                Player* player = ObjectAccessor::FindPlayer(m_PlayersNearPoint[i][j]);
                if (!player)
                {
                    TC_LOG_ERROR("bg.battleground", "BattlegroundEY:CheckSomeoneLeftPoint Player (%s) could not be found!", m_PlayersNearPoint[i][j].ToString().c_str());
                    //move non-existing players to "free space" - this will cause many errors showing in log, but it is a very important bug
                    m_PlayersNearPoint[EY_POINTS_MAX].push_back(m_PlayersNearPoint[i][j]);
                    m_PlayersNearPoint[i].erase(m_PlayersNearPoint[i].begin() + j);
                    continue;
                }
                if (!player->CanCaptureTowerPoint() || !player->IsWithinDistInMap(obj, BG_EY_POINT_RADIUS))
                    //move player out of point (add him to players that are out of points
                {
                    m_PlayersNearPoint[EY_POINTS_MAX].push_back(m_PlayersNearPoint[i][j]);
                    m_PlayersNearPoint[i].erase(m_PlayersNearPoint[i].begin() + j);
                    player->SendUpdateWorldState(PROGRESS_BAR_SHOW, BG_EY_PROGRESS_BAR_DONT_SHOW);
                }
                else
                {
                    //player is neat flag, so update count:
                    m_CurrentPointPlayersCount[2 * i + GetTeamIndexByTeamId(GetPlayerTeam(player->GetGUID()))]++;
                    ++j;
                }
            }
        }
    }
}

void BattlegroundEY::UpdatePointStatuses()
{
    for (uint8 point = 0; point < EY_POINTS_MAX; ++point)
    {
        if (!m_PlayersNearPoint[point].empty())
        {
            //count new point bar status:
            int32 pointDelta = int32(m_CurrentPointPlayersCount[2 * point]) - int32(m_CurrentPointPlayersCount[2 * point + 1]);
            RoundToInterval<int32>(pointDelta, -BG_EY_POINT_MAX_CAPTURERS_COUNT, BG_EY_POINT_MAX_CAPTURERS_COUNT);
            m_PointBarStatus[point] += pointDelta;

            if (m_PointBarStatus[point] > BG_EY_PROGRESS_BAR_ALI_CONTROLLED)
                //point is fully alliance's
                m_PointBarStatus[point] = BG_EY_PROGRESS_BAR_ALI_CONTROLLED;
            if (m_PointBarStatus[point] < BG_EY_PROGRESS_BAR_HORDE_CONTROLLED)
                //point is fully horde's
                m_PointBarStatus[point] = BG_EY_PROGRESS_BAR_HORDE_CONTROLLED;

            uint32 pointOwnerTeamId = 0;
            //find which team should own this point
            if (m_PointBarStatus[point] <= BG_EY_PROGRESS_BAR_NEUTRAL_LOW)
                pointOwnerTeamId = HORDE;
            else if (m_PointBarStatus[point] >= BG_EY_PROGRESS_BAR_NEUTRAL_HIGH)
                pointOwnerTeamId = ALLIANCE;
            else
                pointOwnerTeamId = EY_POINT_NO_OWNER;

            for (uint8 i = 0; i < m_PlayersNearPoint[point].size(); ++i)
            {
                Player* player = ObjectAccessor::FindPlayer(m_PlayersNearPoint[point][i]);
                if (player)
                {
                    player->SendUpdateWorldState(PROGRESS_BAR_STATUS, m_PointBarStatus[point]);
                    uint32 team = GetPlayerTeam(player->GetGUID());
                    //if point owner changed we must evoke event!
                    if (pointOwnerTeamId != m_PointOwnedByTeam[point])
                    {
                        //point was uncontrolled and player is from team which captured point
                        if (m_PointState[point] == EY_POINT_STATE_UNCONTROLLED && team == pointOwnerTeamId)
                            this->EventTeamCapturedPoint(player, point);

                        //point was under control and player isn't from team which controlled it
                        if (m_PointState[point] == EY_POINT_UNDER_CONTROL && team != m_PointOwnedByTeam[point])
                            this->EventTeamLostPoint(player, point);
                    }

                    /// @workaround The original AreaTrigger is covered by a bigger one and not triggered on client side.
                    if (point == FEL_REAVER && m_PointOwnedByTeam[point] == team)
                        if (m_FlagState && GetFlagPickerGUID() == player->GetGUID())
                            if (player->GetDistance(2044.0f, 1729.729f, 1190.03f) < 3.0f)
                                EventPlayerCapturedFlag(player, BG_EY_OBJECT_FLAG_FEL_REAVER);
                }
            }
        }

        BattlegroundPointCaptureStatus captureStatus = GetPointCaptureStatus(point);
        if (m_LastPointCaptureStatus[point] != captureStatus)
        {
            UpdateWorldState(m_PointsIconStruct[point].WorldStateAllianceStatusBarIcon, captureStatus == BattlegroundPointCaptureStatus::AllianceControlled ? 2 : (captureStatus == BattlegroundPointCaptureStatus::AllianceCapturing ? 1 : 0));
            UpdateWorldState(m_PointsIconStruct[point].WorldStateHordeStatusBarIcon, captureStatus == BattlegroundPointCaptureStatus::HordeControlled ? 2 : (captureStatus == BattlegroundPointCaptureStatus::HordeCapturing ? 1 : 0));
            m_LastPointCaptureStatus[point] = captureStatus;
        }
    }
}

void BattlegroundEY::UpdateTeamScore(uint32 Team)
{
    uint32 score = GetTeamScore(Team);

    if (score >= BG_EY_MAX_TEAM_SCORE)
    {
        score = BG_EY_MAX_TEAM_SCORE;
        if (Team == TEAM_ALLIANCE)
            EndBattleground(ALLIANCE);
        else
            EndBattleground(HORDE);
    }

    if (Team == TEAM_ALLIANCE)
        UpdateWorldState(EY_ALLIANCE_RESOURCES, score);
    else
        UpdateWorldState(EY_HORDE_RESOURCES, score);
}

void BattlegroundEY::EndBattleground(uint32 winner)
{
    // Win reward
    if (winner == ALLIANCE)
        RewardHonorToTeam(GetBonusHonorFromKill(1), ALLIANCE);
    if (winner == HORDE)
        RewardHonorToTeam(GetBonusHonorFromKill(1), HORDE);
    // Complete map reward
    RewardHonorToTeam(GetBonusHonorFromKill(1), ALLIANCE);
    RewardHonorToTeam(GetBonusHonorFromKill(1), HORDE);

    Battleground::EndBattleground(winner);
}

void BattlegroundEY::UpdatePointsCount(uint32 Team)
{
    if (Team == ALLIANCE)
        UpdateWorldState(EY_ALLIANCE_BASE, m_TeamPointsCount[TEAM_ALLIANCE]);
    else
        UpdateWorldState(EY_HORDE_BASE, m_TeamPointsCount[TEAM_HORDE]);
}

void BattlegroundEY::UpdatePointsIcons(uint32 Team, uint32 Point)
{
    //we MUST firstly send 0, after that we can send 1!!!
    if (m_PointState[Point] == EY_POINT_UNDER_CONTROL)
    {
        UpdateWorldState(m_PointsIconStruct[Point].WorldStateControlIndex, 0);
        if (Team == ALLIANCE)
            UpdateWorldState(m_PointsIconStruct[Point].WorldStateAllianceControlledIndex, 1);
        else
            UpdateWorldState(m_PointsIconStruct[Point].WorldStateHordeControlledIndex, 1);
    }
    else
    {
        if (Team == ALLIANCE)
            UpdateWorldState(m_PointsIconStruct[Point].WorldStateAllianceControlledIndex, 0);
        else
            UpdateWorldState(m_PointsIconStruct[Point].WorldStateHordeControlledIndex, 0);
        UpdateWorldState(m_PointsIconStruct[Point].WorldStateControlIndex, 1);
    }
}

void BattlegroundEY::AddPlayer(Player* player)
{
    bool const isInBattleground = IsPlayerInBattleground(player->GetGUID());
    Battleground::AddPlayer(player);
    if (!isInBattleground)
        PlayerScores[player->GetGUID()] = new BattlegroundEYScore(player->GetGUID(), player->GetBGTeam());

    m_PlayersNearPoint[EY_POINTS_MAX].push_back(player->GetGUID());
}

void BattlegroundEY::RemovePlayer(Player* player, ObjectGuid guid, uint32 /*team*/)
{
    // sometimes flag aura not removed :(
    for (int j = EY_POINTS_MAX; j >= 0; --j)
    {
        for (size_t i = 0; i < m_PlayersNearPoint[j].size(); ++i)
            if (m_PlayersNearPoint[j][i] == guid)
                m_PlayersNearPoint[j].erase(m_PlayersNearPoint[j].begin() + i);
    }
    if (IsFlagPickedup())
    {
        if (m_FlagKeeper == guid)
        {
            if (player)
                EventPlayerDroppedFlag(player);
            else
            {
                SetFlagPicker(ObjectGuid::Empty);
                RespawnFlag(true);
            }
        }
    }
}

void BattlegroundEY::HandleAreaTrigger(Player* player, uint32 trigger, bool entered)
{
    if (!player->IsAlive())                                  //hack code, must be removed later
        return;

    switch (trigger)
    {
        case 4530: // Horde Start
        case 4531: // Alliance Start
            if (GetStatus() == STATUS_WAIT_JOIN && !entered)
                TeleportPlayerToExploitLocation(player);
            break;
        case TR_BLOOD_ELF_POINT:
            if (m_PointState[BLOOD_ELF] == EY_POINT_UNDER_CONTROL && m_PointOwnedByTeam[BLOOD_ELF] == GetPlayerTeam(player->GetGUID()))
                if (m_FlagState && GetFlagPickerGUID() == player->GetGUID())
                    EventPlayerCapturedFlag(player, BG_EY_OBJECT_FLAG_BLOOD_ELF);
            break;
        case TR_FEL_REAVER_POINT:
            if (m_PointState[FEL_REAVER] == EY_POINT_UNDER_CONTROL && m_PointOwnedByTeam[FEL_REAVER] == GetPlayerTeam(player->GetGUID()))
                if (m_FlagState && GetFlagPickerGUID() == player->GetGUID())
                    EventPlayerCapturedFlag(player, BG_EY_OBJECT_FLAG_FEL_REAVER);
            break;
        case TR_MAGE_TOWER_POINT:
            if (m_PointState[MAGE_TOWER] == EY_POINT_UNDER_CONTROL && m_PointOwnedByTeam[MAGE_TOWER] == GetPlayerTeam(player->GetGUID()))
                if (m_FlagState && GetFlagPickerGUID() == player->GetGUID())
                    EventPlayerCapturedFlag(player, BG_EY_OBJECT_FLAG_MAGE_TOWER);
            break;
        case TR_DRAENEI_RUINS_POINT:
            if (m_PointState[DRAENEI_RUINS] == EY_POINT_UNDER_CONTROL && m_PointOwnedByTeam[DRAENEI_RUINS] == GetPlayerTeam(player->GetGUID()))
                if (m_FlagState && GetFlagPickerGUID() == player->GetGUID())
                    EventPlayerCapturedFlag(player, BG_EY_OBJECT_FLAG_DRAENEI_RUINS);
            break;
        case 4512:
        case 4515:
        case 4517:
        case 4519:
        case 4568:
        case 4569:
        case 4570:
        case 4571:
        case 5866:
            break;
        default:
            Battleground::HandleAreaTrigger(player, trigger, entered);
            break;
    }
}

bool BattlegroundEY::SetupBattleground()
{
        // doors
    if (!AddObject(BG_EY_OBJECT_DOOR_A, BG_OBJECT_A_DOOR_EY_ENTRY, 2527.59716796875f, 1596.90625f, 1238.4544677734375f, 3.159139871597290039f, 0.173641681671142578f, 0.001514434814453125f, -0.98476982116699218f, 0.008638577535748481f, RESPAWN_IMMEDIATELY)
        || !AddObject(BG_EY_OBJECT_DOOR_H, BG_OBJECT_H_DOOR_EY_ENTRY, 1803.2066650390625f, 1539.486083984375f, 1238.4544677734375f, 3.13898324966430664f, 0.173647880554199218, 0.0f, 0.984807014465332031f, 0.001244877814315259f, RESPAWN_IMMEDIATELY)
        // banners (alliance)
        || !AddObject(BG_EY_OBJECT_A_BANNER_FEL_REAVER_CENTER, BG_OBJECT_A_BANNER_EY_ENTRY, 2057.47265625f, 1735.109130859375f, 1188.065673828125f, 5.305802345275878906f, 0.0f, 0.0f, -0.46947097778320312f, 0.882947921752929687f, RESPAWN_ONE_DAY)
        || !AddObject(BG_EY_OBJECT_A_BANNER_FEL_REAVER_LEFT, BG_OBJECT_A_BANNER_EY_ENTRY, 2032.248291015625f, 1729.546875f, 1191.2296142578125f, 1.797688722610473632f, 0.0f, 0.0f, 0.7826080322265625f, 0.622514784336090087f, RESPAWN_ONE_DAY)
        || !AddObject(BG_EY_OBJECT_A_BANNER_FEL_REAVER_RIGHT, BG_OBJECT_A_BANNER_EY_ENTRY, 2092.338623046875f, 1775.4739990234375f, 1187.504150390625f, 5.811946868896484375f, 0.0f, 0.0f, -0.2334451675415039f, 0.972369968891143798f, RESPAWN_ONE_DAY)
        || !AddObject(BG_EY_OBJECT_A_BANNER_BLOOD_ELF_CENTER, BG_OBJECT_A_BANNER_EY_ENTRY, 2047.1910400390625f, 1349.1927490234375f, 1189.0032958984375f, 4.660029888153076171f, 0.0f, 0.0f, -0.72537422180175781f, 0.688354730606079101f, RESPAWN_ONE_DAY)
        || !AddObject(BG_EY_OBJECT_A_BANNER_BLOOD_ELF_LEFT, BG_OBJECT_A_BANNER_EY_ENTRY, 2074.319580078125f, 1385.779541015625f, 1194.7203369140625f, 0.488691210746765136f, 0.0f, 0.0f, 0.241921424865722656f, 0.970295846462249755f, RESPAWN_ONE_DAY)
        || !AddObject(BG_EY_OBJECT_A_BANNER_BLOOD_ELF_RIGHT, BG_OBJECT_A_BANNER_EY_ENTRY, 2025.125f, 1386.123291015625f, 1192.7354736328125f, 2.391098499298095703f, 0.0f, 0.0f, 0.930417060852050781f, 0.366502493619918823f, RESPAWN_ONE_DAY)
        || !AddObject(BG_EY_OBJECT_A_BANNER_DRAENEI_RUINS_CENTER, BG_OBJECT_A_BANNER_EY_ENTRY, 2276.796875f, 1400.407958984375f, 1196.333740234375f, 2.44346022605895996f, 0.0f, 0.0f, 0.939692497253417968f, 0.34202045202255249f, RESPAWN_ONE_DAY)
        || !AddObject(BG_EY_OBJECT_A_BANNER_DRAENEI_RUINS_LEFT, BG_OBJECT_A_BANNER_EY_ENTRY, 2305.776123046875f, 1404.5572509765625f, 1199.384765625f, 1.745326757431030273f, 0.0f, 0.0f, 0.766043663024902343f, 0.642788589000701904f, RESPAWN_ONE_DAY)
        || !AddObject(BG_EY_OBJECT_A_BANNER_DRAENEI_RUINS_RIGHT, BG_OBJECT_A_BANNER_EY_ENTRY, 2245.395751953125f, 1366.4132080078125f, 1195.27880859375f, 2.216565132141113281f, 0.0f, 0.0f, 0.894933700561523437f, 0.44619917869567871f, RESPAWN_ONE_DAY)
        || !AddObject(BG_EY_OBJECT_A_BANNER_MAGE_TOWER_CENTER, BG_OBJECT_A_BANNER_EY_ENTRY, 2270.8359375f, 1784.080322265625f, 1186.757080078125f, 2.426007747650146484f, 0.0f, 0.0f, 0.936672210693359375f, 0.350207358598709106f, RESPAWN_ONE_DAY)
        || !AddObject(BG_EY_OBJECT_A_BANNER_MAGE_TOWER_LEFT, BG_OBJECT_A_BANNER_EY_ENTRY, 2269.126708984375f, 1737.703125f, 1186.8145751953125f, 0.994837164878845214f, 0.0f, 0.0f, 0.477158546447753906f, 0.878817260265350341f, RESPAWN_ONE_DAY)
        || !AddObject(BG_EY_OBJECT_A_BANNER_MAGE_TOWER_RIGHT, BG_OBJECT_A_BANNER_EY_ENTRY, 2300.85595703125f, 1741.24658203125f, 1187.793212890625f, 5.497788906097412109f, 0.0f, 0.0f, -0.38268280029296875f, 0.923879802227020263f, RESPAWN_ONE_DAY)
        // banners (horde)
        || !AddObject(BG_EY_OBJECT_H_BANNER_FEL_REAVER_CENTER, BG_OBJECT_H_BANNER_EY_ENTRY, 2057.45654296875f, 1735.07470703125f, 1187.9063720703125f, 5.35816192626953125f, 0.0f, 0.0f, -0.446197509765625f, 0.894934535026550292f, RESPAWN_ONE_DAY)
        || !AddObject(BG_EY_OBJECT_H_BANNER_FEL_REAVER_LEFT, BG_OBJECT_H_BANNER_EY_ENTRY, 2032.251708984375f, 1729.532958984375f, 1190.3251953125f, 1.867502212524414062f, 0.0f, 0.0f, 0.803856849670410156f, 0.594822824001312255f, RESPAWN_ONE_DAY)
        || !AddObject(BG_EY_OBJECT_H_BANNER_FEL_REAVER_RIGHT, BG_OBJECT_H_BANNER_EY_ENTRY, 2092.354248046875f, 1775.4583740234375f, 1187.079345703125f, 5.881760597229003906f, 0.0f, 0.0f, -0.19936752319335937f, 0.979924798011779785f, RESPAWN_ONE_DAY)
        || !AddObject(BG_EY_OBJECT_H_BANNER_BLOOD_ELF_CENTER, BG_OBJECT_H_BANNER_EY_ENTRY, 2047.1978759765625f, 1349.1875f, 1188.5650634765625f, 4.625123500823974609f, 0.0f, 0.0f, -0.73727703094482421f, 0.67559051513671875f, RESPAWN_ONE_DAY)
        || !AddObject(BG_EY_OBJECT_H_BANNER_BLOOD_ELF_LEFT, BG_OBJECT_H_BANNER_EY_ENTRY, 2074.3056640625f, 1385.7725830078125f, 1194.4686279296875f, 0.471238493919372558f, 0.0f, 0.0f, 0.233445167541503906f, 0.972369968891143798f, RESPAWN_ONE_DAY)
        || !AddObject(BG_EY_OBJECT_H_BANNER_BLOOD_ELF_RIGHT, BG_OBJECT_H_BANNER_EY_ENTRY, 2025.09375f, 1386.12158203125f, 1192.6536865234375f, 2.373644113540649414f, 0.0f, 0.0f, 0.927183151245117187f, 0.37460830807685852f, RESPAWN_ONE_DAY)
        || !AddObject(BG_EY_OBJECT_H_BANNER_DRAENEI_RUINS_CENTER, BG_OBJECT_H_BANNER_EY_ENTRY, 2276.798583984375f, 1400.4410400390625f, 1196.2200927734375f, 2.495818138122558593f, 0.0f, 0.0f, 0.948323249816894531f, 0.317305892705917358f, RESPAWN_ONE_DAY)
        || !AddObject(BG_EY_OBJECT_H_BANNER_DRAENEI_RUINS_LEFT, BG_OBJECT_H_BANNER_EY_ENTRY, 2305.763916015625f, 1404.5972900390625f, 1199.3333740234375f, 1.640606880187988281f, 0.0f, 0.0f, 0.731352806091308593f, 0.6819993257522583f, RESPAWN_ONE_DAY)
        || !AddObject(BG_EY_OBJECT_H_BANNER_DRAENEI_RUINS_RIGHT, BG_OBJECT_H_BANNER_EY_ENTRY, 2245.382080078125f, 1366.454833984375f, 1195.1815185546875f, 2.373644113540649414f, 0.0f, 0.0f, 0.927183151245117187f, 0.37460830807685852f, RESPAWN_ONE_DAY)
        || !AddObject(BG_EY_OBJECT_H_BANNER_MAGE_TOWER_CENTER, BG_OBJECT_H_BANNER_EY_ENTRY, 2270.869873046875f, 1784.0989990234375f, 1186.4384765625f, 2.356194972991943359f, 0.0f, 0.0f, 0.923879623413085937f, 0.382683247327804565f, RESPAWN_ONE_DAY)
        || !AddObject(BG_EY_OBJECT_H_BANNER_MAGE_TOWER_LEFT, BG_OBJECT_H_BANNER_EY_ENTRY, 2268.59716796875f, 1737.0191650390625f, 1186.75390625f, 0.942476630210876464f, 0.0f, 0.0f, 0.453989982604980468f, 0.891006767749786376f, RESPAWN_ONE_DAY)
        || !AddObject(BG_EY_OBJECT_H_BANNER_MAGE_TOWER_RIGHT, BG_OBJECT_H_BANNER_EY_ENTRY, 2301.01904296875f, 1741.4930419921875f, 1187.48974609375f, 5.375615119934082031f, 0.0f, 0.0f, -0.4383707046508789f, 0.898794233798980712f, RESPAWN_ONE_DAY)
        // banners (natural)
        || !AddObject(BG_EY_OBJECT_N_BANNER_FEL_REAVER_CENTER, BG_OBJECT_N_BANNER_EY_ENTRY, 2057.4931640625f, 1735.111083984375f, 1187.675537109375f, 5.340708732604980468f, 0.0f, 0.0f, -0.45398998260498046f, 0.891006767749786376f, RESPAWN_ONE_DAY)
        || !AddObject(BG_EY_OBJECT_N_BANNER_FEL_REAVER_LEFT, BG_OBJECT_N_BANNER_EY_ENTRY, 2032.2569580078125f, 1729.5572509765625f, 1191.0802001953125f, 1.797688722610473632f, 0.0f, 0.0f, 0.7826080322265625f, 0.622514784336090087f, RESPAWN_ONE_DAY)
        || !AddObject(BG_EY_OBJECT_N_BANNER_FEL_REAVER_RIGHT, BG_OBJECT_N_BANNER_EY_ENTRY, 2092.395751953125f, 1775.451416015625f, 1186.965576171875f, 5.89921426773071289f, 0.0f, 0.0f, -0.19080829620361328f, 0.981627285480499267f, RESPAWN_ONE_DAY)
        || !AddObject(BG_EY_OBJECT_N_BANNER_BLOOD_ELF_CENTER, BG_OBJECT_N_BANNER_EY_ENTRY, 2047.1875f, 1349.1944580078125f, 1188.5731201171875f, 4.642575740814208984f, 0.0f, 0.0f, -0.731353759765625f, 0.681998312473297119f, RESPAWN_ONE_DAY)
        || !AddObject(BG_EY_OBJECT_N_BANNER_BLOOD_ELF_LEFT, BG_OBJECT_N_BANNER_EY_ENTRY, 2074.3212890625f, 1385.76220703125f, 1194.362060546875f, 0.488691210746765136f, 0.0f, 0.0f, 0.241921424865722656f, 0.970295846462249755f, RESPAWN_ONE_DAY)
        || !AddObject(BG_EY_OBJECT_N_BANNER_BLOOD_ELF_RIGHT, BG_OBJECT_N_BANNER_EY_ENTRY, 2025.13720703125f, 1386.1336669921875f, 1192.5482177734375f, 2.391098499298095703f, 0.0f, 0.0f, 0.930417060852050781f, 0.366502493619918823f, RESPAWN_ONE_DAY)
        || !AddObject(BG_EY_OBJECT_N_BANNER_DRAENEI_RUINS_CENTER, BG_OBJECT_N_BANNER_EY_ENTRY, 2276.833251953125f, 1400.4375f, 1196.146728515625f, 2.478367090225219726f, 0.0f, 0.0f, 0.94551849365234375f, 0.325568377971649169f, RESPAWN_ONE_DAY)
        || !AddObject(BG_EY_OBJECT_N_BANNER_DRAENEI_RUINS_LEFT, BG_OBJECT_N_BANNER_EY_ENTRY, 2305.77783203125f, 1404.5364990234375f, 1199.246337890625f, 1.570795774459838867f, 0.0f, 0.0f, 0.707106590270996093f, 0.707106947898864746f, RESPAWN_ONE_DAY)
        || !AddObject(BG_EY_OBJECT_N_BANNER_DRAENEI_RUINS_RIGHT, BG_OBJECT_N_BANNER_EY_ENTRY, 2245.40966796875f, 1366.4410400390625f, 1195.1107177734375f, 2.356194972991943359f, 0.0f, 0.0f, 0.923879623413085937f, 0.382683247327804565f, RESPAWN_ONE_DAY)
        || !AddObject(BG_EY_OBJECT_N_BANNER_MAGE_TOWER_CENTER, BG_OBJECT_N_BANNER_EY_ENTRY, 2270.84033203125f, 1784.1197509765625f, 1186.1473388671875f, 2.303830623626708984f, 0.0f, 0.0f, 0.913544654846191406f, 0.406738430261611938f, RESPAWN_ONE_DAY)
        || !AddObject(BG_EY_OBJECT_N_BANNER_MAGE_TOWER_LEFT, BG_OBJECT_N_BANNER_EY_ENTRY, 2268.46533203125f, 1736.8385009765625f, 1186.742919921875f, 0.942476630210876464f, 0.0f, 0.0f, 0.453989982604980468f, 0.891006767749786376f, RESPAWN_ONE_DAY)
        || !AddObject(BG_EY_OBJECT_N_BANNER_MAGE_TOWER_RIGHT, BG_OBJECT_N_BANNER_EY_ENTRY, 2300.9931640625f, 1741.5504150390625f, 1187.10693359375f, 5.375615119934082031f, 0.0f, 0.0f, -0.4383707046508789f, 0.898794233798980712f, RESPAWN_ONE_DAY)
        // flags
        || !AddObject(BG_EY_OBJECT_FLAG_NETHERSTORM, BG_OBJECT_FLAG2_EY_ENTRY, 2174.444580078125f, 1569.421875f, 1159.852783203125f, 4.625123500823974609f, 0.0f, 0.0f, -0.73727703094482421f, 0.67559051513671875f, RESPAWN_ONE_DAY)
        || !AddObject(BG_EY_OBJECT_FLAG_FEL_REAVER, BG_OBJECT_FLAG1_EY_ENTRY, 2044.28f, 1729.68f, 1189.96f, -0.017453f, 0, 0, 0.008727f, -0.999962f, RESPAWN_ONE_DAY)
        || !AddObject(BG_EY_OBJECT_FLAG_BLOOD_ELF, BG_OBJECT_FLAG1_EY_ENTRY, 2048.83f, 1393.65f, 1194.49f, 0.20944f, 0, 0, 0.104528f, 0.994522f, RESPAWN_ONE_DAY)
        || !AddObject(BG_EY_OBJECT_FLAG_DRAENEI_RUINS, BG_OBJECT_FLAG1_EY_ENTRY, 2286.56f, 1402.36f, 1197.11f, 3.72381f, 0, 0, 0.957926f, -0.287016f, RESPAWN_ONE_DAY)
        || !AddObject(BG_EY_OBJECT_FLAG_MAGE_TOWER, BG_OBJECT_FLAG1_EY_ENTRY, 2284.48f, 1731.23f, 1189.99f, 2.89725f, 0, 0, 0.992546f, 0.121869f, RESPAWN_ONE_DAY)
        // tower cap
        || !AddObject(BG_EY_OBJECT_TOWER_CAP_FEL_REAVER, BG_OBJECT_FR_TOWER_CAP_EY_ENTRY, 2024.600708f, 1742.819580f, 1195.157715f, 2.443461f, 0, 0, 0.939693f, 0.342020f, RESPAWN_ONE_DAY)
        || !AddObject(BG_EY_OBJECT_TOWER_CAP_BLOOD_ELF, BG_OBJECT_BE_TOWER_CAP_EY_ENTRY, 2050.493164f, 1372.235962f, 1194.563477f, 1.710423f, 0, 0, 0.754710f, 0.656059f, RESPAWN_ONE_DAY)
        || !AddObject(BG_EY_OBJECT_TOWER_CAP_DRAENEI_RUINS, BG_OBJECT_DR_TOWER_CAP_EY_ENTRY, 2301.010498f, 1386.931641f, 1197.183472f, 1.570796f, 0, 0, 0.707107f, 0.707107f, RESPAWN_ONE_DAY)
        || !AddObject(BG_EY_OBJECT_TOWER_CAP_MAGE_TOWER, BG_OBJECT_HU_TOWER_CAP_EY_ENTRY, 2282.121582f, 1760.006958f, 1189.707153f, 1.919862f, 0, 0, 0.819152f, 0.573576f, RESPAWN_ONE_DAY)
        // buffs
        || !AddObject(BG_EY_OBJECT_SPEEDBUFF_FEL_REAVER, BG_OBJECT_SPEED_BUFF_FEL_REAVER_EY_ENTRY, 2046.462646484375f, 1749.1666259765625f, 1190.010498046875f, 5.410521507263183593f, 0.0f, 0.0f, -0.42261791229248046f, 0.906307935714721679f, RESPAWN_ONE_DAY)
        || !AddObject(BG_EY_OBJECT_REGENBUFF_FEL_REAVER, BG_OBJECT_RESTORATION_BUFF_FEL_REAVER_EY_ENTRY, 2046.462646484375f, 1749.1666259765625f, 1190.010498046875f, 5.410521507263183593f, 0.0f, 0.0f, -0.42261791229248046f, 0.906307935714721679f, RESPAWN_ONE_DAY)
        || !AddObject(BG_EY_OBJECT_BERSERKBUFF_FEL_REAVER, BG_OBJECT_BERSERK_BUFF_FEL_REAVER_EY_ENTRY, 2046.462646484375f, 1749.1666259765625f, 1190.010498046875f, 5.410521507263183593f, 0.0f, 0.0f, -0.42261791229248046f, 0.906307935714721679f, RESPAWN_ONE_DAY)
        || !AddObject(BG_EY_OBJECT_SPEEDBUFF_BLOOD_ELF, BG_OBJECT_SPEED_BUFF_BLOOD_ELF_EY_ENTRY, 2050.46826171875f, 1372.2020263671875f, 1194.5634765625f, 1.675513744354248046f, 0.0f, 0.0f, 0.743144035339355468f, 0.669131457805633544f, RESPAWN_ONE_DAY)
        || !AddObject(BG_EY_OBJECT_REGENBUFF_BLOOD_ELF, BG_OBJECT_RESTORATION_BUFF_BLOOD_ELF_EY_ENTRY, 2050.46826171875f, 1372.2020263671875f, 1194.5634765625f, 1.675513744354248046f, 0.0f, 0.0f, 0.743144035339355468f, 0.669131457805633544f, RESPAWN_ONE_DAY)
        || !AddObject(BG_EY_OBJECT_BERSERKBUFF_BLOOD_ELF, BG_OBJECT_BERSERK_BUFF_BLOOD_ELF_EY_ENTRY, 2050.46826171875f, 1372.2020263671875f, 1194.5634765625f, 1.675513744354248046f, 0.0f, 0.0f, 0.743144035339355468f, 0.669131457805633544f, RESPAWN_ONE_DAY)
        || !AddObject(BG_EY_OBJECT_SPEEDBUFF_DRAENEI_RUINS, BG_OBJECT_SPEED_BUFF_DRAENEI_RUINS_EY_ENTRY, 2302.4765625f, 1391.244873046875f, 1197.7364501953125f, 1.762782454490661621f, 0.0f, 0.0f, 0.771624565124511718f, 0.636078238487243652f, RESPAWN_ONE_DAY)
        || !AddObject(BG_EY_OBJECT_REGENBUFF_DRAENEI_RUINS, BG_OBJECT_RESTORATION_BUFF_DRAENEI_RUINS_EY_ENTRY, 2302.4765625f, 1391.244873046875f, 1197.7364501953125f, 1.762782454490661621f, 0.0f, 0.0f, 0.771624565124511718f, 0.636078238487243652f, RESPAWN_ONE_DAY)
        || !AddObject(BG_EY_OBJECT_BERSERKBUFF_DRAENEI_RUINS, BG_OBJECT_BERSERK_BUFF_DRAENEI_RUINS_EY_ENTRY, 2302.4765625f, 1391.244873046875f, 1197.7364501953125f, 1.762782454490661621f, 0.0f, 0.0f, 0.771624565124511718f, 0.636078238487243652f, RESPAWN_ONE_DAY)
        || !AddObject(BG_EY_OBJECT_SPEEDBUFF_MAGE_TOWER, BG_OBJECT_SPEED_BUFF_MAGE_TOWER_EY_ENTRY, 2283.7099609375f, 1748.8699951171875f, 1189.7071533203125f, 4.782202720642089843f, 0.0f, 0.0f, -0.68199825286865234f, 0.731353819370269775f, RESPAWN_ONE_DAY)
        || !AddObject(BG_EY_OBJECT_REGENBUFF_MAGE_TOWER, BG_OBJECT_RESTORATION_BUFF_MAGE_TOWER_EY_ENTRY, 2283.7099609375f, 1748.8699951171875f, 1189.7071533203125f, 4.782202720642089843f, 0.0f, 0.0f, -0.68199825286865234f, 0.731353819370269775f, RESPAWN_ONE_DAY)
        || !AddObject(BG_EY_OBJECT_BERSERKBUFF_MAGE_TOWER, BG_OBJECT_BERSERK_BUFF_MAGE_TOWER_EY_ENTRY, 2283.7099609375f, 1748.8699951171875f, 1189.7071533203125f, 4.782202720642089843f, 0.0f, 0.0f, -0.68199825286865234f, 0.731353819370269775f, RESPAWN_ONE_DAY)
        )
    {
        TC_LOG_ERROR("sql.sql", "BatteGroundEY: Failed to spawn some objects. The battleground was not created.");
        return false;
    }

    WorldSafeLocsEntry const* sg = sObjectMgr->GetWorldSafeLoc(EY_GRAVEYARD_MAIN_ALLIANCE);
    if (!sg || !AddSpiritGuide(EY_SPIRIT_MAIN_ALLIANCE, sg->Loc.GetPositionX(), sg->Loc.GetPositionY(), sg->Loc.GetPositionZ(), 3.124139f, TEAM_ALLIANCE))
    {
        TC_LOG_ERROR("sql.sql", "BatteGroundEY: Failed to spawn spirit guide. The battleground was not created.");
        return false;
    }

    sg = sObjectMgr->GetWorldSafeLoc(EY_GRAVEYARD_MAIN_HORDE);
    if (!sg || !AddSpiritGuide(EY_SPIRIT_MAIN_HORDE, sg->Loc.GetPositionX(), sg->Loc.GetPositionY(), sg->Loc.GetPositionZ(), 3.193953f, TEAM_HORDE))
    {
        TC_LOG_ERROR("sql.sql", "BatteGroundEY: Failed to spawn spirit guide. The battleground was not created.");
        return false;
    }

    UpdateWorldState(EY_MAX_RESOURCES, BG_EY_MAX_TEAM_SCORE);

    return true;
}

void BattlegroundEY::Reset()
{
    //call parent's class reset
    Battleground::Reset();

    m_TeamScores[TEAM_ALLIANCE] = 0;
    m_TeamScores[TEAM_HORDE] = 0;
    m_TeamPointsCount[TEAM_ALLIANCE] = 0;
    m_TeamPointsCount[TEAM_HORDE] = 0;
    m_HonorScoreTics[TEAM_ALLIANCE] = 0;
    m_HonorScoreTics[TEAM_HORDE] = 0;
    m_FlagState = BG_EY_FLAG_STATE_ON_BASE;
    m_FlagCapturedBgObjectType = 0;
    m_FlagKeeper.Clear();
    m_DroppedFlagGUID.Clear();
    m_PointAddingTimer = 0;
    m_TowerCapCheckTimer = 0;
    bool isBGWeekend = sBattlegroundMgr->IsBGWeekend(GetTypeID());
    m_HonorTics = (isBGWeekend) ? BG_EY_EYWeekendHonorTicks : BG_EY_NotEYWeekendHonorTicks;

    for (uint8 i = 0; i < EY_POINTS_MAX; ++i)
    {
        m_PointOwnedByTeam[i] = EY_POINT_NO_OWNER;
        m_PointState[i] = EY_POINT_STATE_UNCONTROLLED;
        m_PointBarStatus[i] = BG_EY_PROGRESS_BAR_STATE_MIDDLE;
        m_PlayersNearPoint[i].clear();
        m_PlayersNearPoint[i].reserve(15);                  //tip size
    }
    m_PlayersNearPoint[EY_PLAYERS_OUT_OF_POINTS].clear();
    m_PlayersNearPoint[EY_PLAYERS_OUT_OF_POINTS].reserve(30);
}

void BattlegroundEY::RespawnFlag(bool send_message)
{
    if (m_FlagCapturedBgObjectType > 0)
        SpawnBGObject(m_FlagCapturedBgObjectType, RESPAWN_ONE_DAY);

    m_FlagCapturedBgObjectType = 0;
    m_FlagState = BG_EY_FLAG_STATE_ON_BASE;
    SpawnBGObject(BG_EY_OBJECT_FLAG_NETHERSTORM, RESPAWN_IMMEDIATELY);

    if (send_message)
    {
        SendBroadcastText(BG_EY_TEXT_FLAG_RESET, CHAT_MSG_BG_SYSTEM_NEUTRAL);
        PlaySoundToAll(BG_EY_SOUND_FLAG_RESET);             // flags respawned sound...
    }

    UpdateWorldState(NETHERSTORM_FLAG, 1);
}

void BattlegroundEY::RespawnFlagAfterDrop()
{
    RespawnFlag(true);

    GameObject* obj = GetBgMap()->GetGameObject(GetDroppedFlagGUID());
    if (obj)
        obj->Delete();
    else
        TC_LOG_ERROR("bg.battleground", "BattlegroundEY: Unknown dropped flag (%s).", GetDroppedFlagGUID().ToString().c_str());

    SetDroppedFlagGUID(ObjectGuid::Empty);
}

void BattlegroundEY::HandleKillPlayer(Player* player, Player* killer)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    Battleground::HandleKillPlayer(player, killer);
    EventPlayerDroppedFlag(player);
}

void BattlegroundEY::EventPlayerDroppedFlag(Player* player)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
    {
        // if not running, do not cast things at the dropper player, neither send unnecessary messages
        // just take off the aura
        if (IsFlagPickedup() && GetFlagPickerGUID() == player->GetGUID())
        {
            SetFlagPicker(ObjectGuid::Empty);
            player->RemoveAurasDueToSpell(BG_EY_NETHERSTORM_FLAG_SPELL);
        }
        return;
    }

    if (!IsFlagPickedup())
        return;

    if (GetFlagPickerGUID() != player->GetGUID())
        return;

    SetFlagPicker(ObjectGuid::Empty);
    player->RemoveAurasDueToSpell(BG_EY_NETHERSTORM_FLAG_SPELL);
    m_FlagState = BG_EY_FLAG_STATE_ON_GROUND;
    m_FlagsTimer = BG_EY_FLAG_RESPAWN_TIME;
    player->CastSpell(player, SPELL_RECENTLY_DROPPED_FLAG, true);
    player->CastSpell(player, BG_EY_PLAYER_DROPPED_FLAG_SPELL, true);
    //this does not work correctly :((it should remove flag carrier name)
    UpdateWorldState(NETHERSTORM_FLAG_STATE_HORDE, BG_EY_FLAG_STATE_WAIT_RESPAWN);
    UpdateWorldState(NETHERSTORM_FLAG_STATE_ALLIANCE, BG_EY_FLAG_STATE_WAIT_RESPAWN);

    if (GetPlayerTeam(player->GetGUID()) == ALLIANCE)
        SendBroadcastText(BG_EY_TEXT_FLAG_DROPPED, CHAT_MSG_BG_SYSTEM_ALLIANCE);
    else
        SendBroadcastText(BG_EY_TEXT_FLAG_DROPPED, CHAT_MSG_BG_SYSTEM_HORDE);
}

void BattlegroundEY::EventPlayerClickedOnFlag(Player* player, GameObject* target_obj)
{
    if (GetStatus() != STATUS_IN_PROGRESS || IsFlagPickedup() || !player->IsWithinDistInMap(target_obj, 10))
        return;

    if (GetPlayerTeam(player->GetGUID()) == ALLIANCE)
    {
        UpdateWorldState(NETHERSTORM_FLAG_STATE_ALLIANCE, BG_EY_FLAG_STATE_ON_PLAYER);
        PlaySoundToAll(BG_EY_SOUND_FLAG_PICKED_UP_ALLIANCE);
    }
    else
    {
        UpdateWorldState(NETHERSTORM_FLAG_STATE_HORDE, BG_EY_FLAG_STATE_ON_PLAYER);
        PlaySoundToAll(BG_EY_SOUND_FLAG_PICKED_UP_HORDE);
    }

    if (m_FlagState == BG_EY_FLAG_STATE_ON_BASE)
        UpdateWorldState(NETHERSTORM_FLAG, 0);
    m_FlagState = BG_EY_FLAG_STATE_ON_PLAYER;

    SpawnBGObject(BG_EY_OBJECT_FLAG_NETHERSTORM, RESPAWN_ONE_DAY);
    SetFlagPicker(player->GetGUID());
    //get flag aura on player
    player->CastSpell(player, BG_EY_NETHERSTORM_FLAG_SPELL, true);
    player->RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::PvPActive);

    if (GetPlayerTeam(player->GetGUID()) == ALLIANCE)
        SendBroadcastText(BG_EY_TEXT_TAKEN_FLAG, CHAT_MSG_BG_SYSTEM_ALLIANCE, player);
    else
        SendBroadcastText(BG_EY_TEXT_TAKEN_FLAG, CHAT_MSG_BG_SYSTEM_HORDE, player);
}

void BattlegroundEY::EventTeamLostPoint(Player* player, uint32 Point)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    //Natural point
    uint32 Team = m_PointOwnedByTeam[Point];

    if (!Team)
        return;

    if (Team == ALLIANCE)
    {
        m_TeamPointsCount[TEAM_ALLIANCE]--;
        SpawnBGObject(m_LosingPointTypes[Point].DespawnObjectTypeAlliance, RESPAWN_ONE_DAY);
        SpawnBGObject(m_LosingPointTypes[Point].DespawnObjectTypeAlliance + 1, RESPAWN_ONE_DAY);
        SpawnBGObject(m_LosingPointTypes[Point].DespawnObjectTypeAlliance + 2, RESPAWN_ONE_DAY);
    }
    else
    {
        m_TeamPointsCount[TEAM_HORDE]--;
        SpawnBGObject(m_LosingPointTypes[Point].DespawnObjectTypeHorde, RESPAWN_ONE_DAY);
        SpawnBGObject(m_LosingPointTypes[Point].DespawnObjectTypeHorde + 1, RESPAWN_ONE_DAY);
        SpawnBGObject(m_LosingPointTypes[Point].DespawnObjectTypeHorde + 2, RESPAWN_ONE_DAY);
    }

    SpawnBGObject(m_LosingPointTypes[Point].SpawnNeutralObjectType, RESPAWN_IMMEDIATELY);
    SpawnBGObject(m_LosingPointTypes[Point].SpawnNeutralObjectType + 1, RESPAWN_IMMEDIATELY);
    SpawnBGObject(m_LosingPointTypes[Point].SpawnNeutralObjectType + 2, RESPAWN_IMMEDIATELY);

    //buff isn't despawned

    m_PointOwnedByTeam[Point] = EY_POINT_NO_OWNER;
    m_PointState[Point] = EY_POINT_NO_OWNER;

    if (Team == ALLIANCE)
        SendBroadcastText(m_LosingPointTypes[Point].MessageIdAlliance, CHAT_MSG_BG_SYSTEM_ALLIANCE, player);
    else
        SendBroadcastText(m_LosingPointTypes[Point].MessageIdHorde, CHAT_MSG_BG_SYSTEM_HORDE, player);

    UpdatePointsIcons(Team, Point);
    UpdatePointsCount(Team);

    //remove bonus honor aura trigger creature when node is lost
    DelCreature(Point + 6);//NULL checks are in DelCreature! 0-5 spirit guides
}

void BattlegroundEY::EventTeamCapturedPoint(Player* player, uint32 Point)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    uint32 Team = GetPlayerTeam(player->GetGUID());

    SpawnBGObject(m_CapturingPointTypes[Point].DespawnNeutralObjectType, RESPAWN_ONE_DAY);
    SpawnBGObject(m_CapturingPointTypes[Point].DespawnNeutralObjectType + 1, RESPAWN_ONE_DAY);
    SpawnBGObject(m_CapturingPointTypes[Point].DespawnNeutralObjectType + 2, RESPAWN_ONE_DAY);

    if (Team == ALLIANCE)
    {
        m_TeamPointsCount[TEAM_ALLIANCE]++;
        SpawnBGObject(m_CapturingPointTypes[Point].SpawnObjectTypeAlliance, RESPAWN_IMMEDIATELY);
        SpawnBGObject(m_CapturingPointTypes[Point].SpawnObjectTypeAlliance + 1, RESPAWN_IMMEDIATELY);
        SpawnBGObject(m_CapturingPointTypes[Point].SpawnObjectTypeAlliance + 2, RESPAWN_IMMEDIATELY);
    }
    else
    {
        m_TeamPointsCount[TEAM_HORDE]++;
        SpawnBGObject(m_CapturingPointTypes[Point].SpawnObjectTypeHorde, RESPAWN_IMMEDIATELY);
        SpawnBGObject(m_CapturingPointTypes[Point].SpawnObjectTypeHorde + 1, RESPAWN_IMMEDIATELY);
        SpawnBGObject(m_CapturingPointTypes[Point].SpawnObjectTypeHorde + 2, RESPAWN_IMMEDIATELY);
    }

    //buff isn't respawned

    m_PointOwnedByTeam[Point] = Team;
    m_PointState[Point] = EY_POINT_UNDER_CONTROL;

    if (Team == ALLIANCE)
        SendBroadcastText(m_CapturingPointTypes[Point].MessageIdAlliance, CHAT_MSG_BG_SYSTEM_ALLIANCE, player);
    else
        SendBroadcastText(m_CapturingPointTypes[Point].MessageIdHorde, CHAT_MSG_BG_SYSTEM_HORDE, player);

    if (!BgCreatures[Point].IsEmpty())
        DelCreature(Point);

    WorldSafeLocsEntry const* sg = sObjectMgr->GetWorldSafeLoc(m_CapturingPointTypes[Point].GraveyardId);
    if (!sg || !AddSpiritGuide(Point, sg->Loc.GetPositionX(), sg->Loc.GetPositionY(), sg->Loc.GetPositionZ(), 3.124139f, GetTeamIndexByTeamId(Team)))
        TC_LOG_ERROR("bg.battleground", "BatteGroundEY: Failed to spawn spirit guide. point: %u, team: %u, graveyard_id: %u",
            Point, Team, m_CapturingPointTypes[Point].GraveyardId);

//    SpawnBGCreature(Point, RESPAWN_IMMEDIATELY);

    UpdatePointsIcons(Team, Point);
    UpdatePointsCount(Team);

    Creature* trigger = GetBGCreature(Point + 6, false);//0-5 spirit guides
    if (!trigger)
        trigger = AddCreature(WORLD_TRIGGER, Point+6, BG_EY_TriggerPositions[Point], GetTeamIndexByTeamId(Team));

    //add bonus honor aura trigger creature when node is accupied
    //cast bonus aura (+50% honor in 25yards)
    //aura should only apply to players who have accupied the node, set correct faction for trigger
    if (trigger)
    {
        trigger->SetFaction(Team == ALLIANCE ? FACTION_ALLIANCE_GENERIC : FACTION_HORDE_GENERIC);
        trigger->CastSpell(trigger, SPELL_HONORABLE_DEFENDER_25Y, false);
    }
}

void BattlegroundEY::EventPlayerCapturedFlag(Player* player, uint32 BgObjectType)
{
    if (GetStatus() != STATUS_IN_PROGRESS || GetFlagPickerGUID() != player->GetGUID())
        return;

    SetFlagPicker(ObjectGuid::Empty);
    m_FlagState = BG_EY_FLAG_STATE_WAIT_RESPAWN;
    player->RemoveAurasDueToSpell(BG_EY_NETHERSTORM_FLAG_SPELL);

    player->RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::PvPActive);

    uint32 team = GetPlayerTeam(player->GetGUID());
    if (team == ALLIANCE)
    {
        SendBroadcastText(BG_EY_TEXT_ALLIANCE_CAPTURED_FLAG, CHAT_MSG_BG_SYSTEM_ALLIANCE, player);
        PlaySoundToAll(BG_EY_SOUND_FLAG_CAPTURED_ALLIANCE);
    }
    else
    {
        SendBroadcastText(BG_EY_TEXT_HORDE_CAPTURED_FLAG, CHAT_MSG_BG_SYSTEM_HORDE, player);
        PlaySoundToAll(BG_EY_SOUND_FLAG_CAPTURED_HORDE);
    }

    SpawnBGObject(BgObjectType, RESPAWN_IMMEDIATELY);

    m_FlagsTimer = BG_EY_FLAG_RESPAWN_TIME;
    m_FlagCapturedBgObjectType = BgObjectType;

    uint8 team_id = GetTeamIndexByTeamId(team);
    if (m_TeamPointsCount[team_id] > 0)
        AddPoints(team, BG_EY_FlagPoints[m_TeamPointsCount[team_id] - 1]);

    UpdateWorldState(NETHERSTORM_FLAG_STATE_HORDE, BG_EY_FLAG_STATE_ON_BASE);
    UpdateWorldState(NETHERSTORM_FLAG_STATE_ALLIANCE, BG_EY_FLAG_STATE_ON_BASE);

    UpdatePlayerScore(player, SCORE_FLAG_CAPTURES, 1);
}

bool BattlegroundEY::UpdatePlayerScore(Player* player, uint32 type, uint32 value, bool doAddHonor)
{
    if (!Battleground::UpdatePlayerScore(player, type, value, doAddHonor))
        return false;

    switch (type)
    {
        case SCORE_FLAG_CAPTURES:
            player->UpdateCriteria(CriteriaType::TrackedWorldStateUIModified, EY_OBJECTIVE_CAPTURE_FLAG);
            break;
        default:
            break;
    }
    return true;
}

WorldSafeLocsEntry const* BattlegroundEY::GetClosestGraveyard(Player* player)
{
    uint32 g_id = 0;

    uint32 team = GetPlayerTeam(player->GetGUID());
    switch (team)
    {
        case ALLIANCE: g_id = EY_GRAVEYARD_MAIN_ALLIANCE; break;
        case HORDE:    g_id = EY_GRAVEYARD_MAIN_HORDE;    break;
        default:       return nullptr;
    }

    float distance, nearestDistance;

    WorldSafeLocsEntry const* entry = nullptr;
    WorldSafeLocsEntry const* nearestEntry = nullptr;
    entry = sObjectMgr->GetWorldSafeLoc(g_id);
    nearestEntry = entry;

    if (!entry)
    {
        TC_LOG_ERROR("bg.battleground", "BattlegroundEY: The main team graveyard could not be found. The graveyard system will not be operational!");
        return nullptr;
    }

    float plr_x = player->GetPositionX();
    float plr_y = player->GetPositionY();
    float plr_z = player->GetPositionZ();

    distance = (entry->Loc.GetPositionX() - plr_x) * (entry->Loc.GetPositionX() - plr_x)
        + (entry->Loc.GetPositionY() - plr_y) * (entry->Loc.GetPositionY() - plr_y)
        + (entry->Loc.GetPositionZ() - plr_z) * (entry->Loc.GetPositionZ() - plr_z);
    nearestDistance = distance;

    for (uint8 i = 0; i < EY_POINTS_MAX; ++i)
    {
        if (m_PointOwnedByTeam[i] == team && m_PointState[i] == EY_POINT_UNDER_CONTROL)
        {
            entry = sObjectMgr->GetWorldSafeLoc(m_CapturingPointTypes[i].GraveyardId);
            if (!entry)
                TC_LOG_ERROR("bg.battleground", "BattlegroundEY: Graveyard %u could not be found.", m_CapturingPointTypes[i].GraveyardId);
            else
            {
                distance = (entry->Loc.GetPositionX() - plr_x) * (entry->Loc.GetPositionX() - plr_x)
                    + (entry->Loc.GetPositionY() - plr_y) * (entry->Loc.GetPositionY() - plr_y)
                    + (entry->Loc.GetPositionZ() - plr_z) * (entry->Loc.GetPositionZ() - plr_z);
                if (distance < nearestDistance)
                {
                    nearestDistance = distance;
                    nearestEntry = entry;
                }
            }
        }
    }

    return nearestEntry;
}

WorldSafeLocsEntry const* BattlegroundEY::GetExploitTeleportLocation(Team team)
{
    return sObjectMgr->GetWorldSafeLoc(team == ALLIANCE ? EY_EXPLOIT_TELEPORT_LOCATION_ALLIANCE : EY_EXPLOIT_TELEPORT_LOCATION_HORDE);
}

uint32 BattlegroundEY::GetPrematureWinner()
{
    if (GetTeamScore(TEAM_ALLIANCE) > GetTeamScore(TEAM_HORDE))
        return ALLIANCE;
    else if (GetTeamScore(TEAM_HORDE) > GetTeamScore(TEAM_ALLIANCE))
        return HORDE;

    return Battleground::GetPrematureWinner();
}
