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

#include "BattlegroundAV.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "DB2Stores.h"
#include "GameObject.h"
#include "Log.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectMgr.h"
#include "Player.h"

enum AlteracValleyPvpStats
{
    PVP_STAT_TOWERS_ASSAULTED       = 61,
    PVP_STAT_GRAVEYARDS_ASSAULTED   = 63,
    PVP_STAT_TOWERS_DEFENDED        = 64,
    PVP_STAT_GRAVEYARDS_DEFENDED    = 65,
    PVP_STAT_SECONDARY_OBJECTIVES   = 82
};

enum AlteracValleyMisc
{
    NEAR_LOSE_POINTS = 140
};

enum AlteracValleyHonorKillBonus
{
    HONOR_KILL_BONUS_BOSS       = 4,
    HONOR_KILL_BONUS_CAPTAIN    = 3,
    HONOR_KILL_BONUS_SURVIVING_TOWER    = 2,
    HONOR_KILL_BONUS_SURVIVING_CAPTAIN  = 2,
    HONOR_KILL_BONUS_DESTROY_TOWER      = 3
};

enum AlteracValleyReputationGains
{
    REP_GAIN_BOSS       = 350,
    REP_GAIN_CAPTAIN    = 125,
    REP_GAIN_DESTROY_TOWER      = 12,
    REP_GAIN_SURVIVING_TOWER    = 12,
    REP_GAIN_SURVIVING_CAPTAIN  = 125
};

enum AlteracValleyResourceLoss
{
    RESOURCE_LOSS_TOWER     = -75,
    RESOURCE_LOSS_CAPTAIN   = -100
};

enum AlteracValleySpells
{
    SPELL_COMPLETE_ALTERAC_VALLEY_QUEST = 23658,
};

enum AlteracValleyFactions
{
    FACTION_FROSTWOLF_CLAN  = 729,
    FACTION_STORMPIKE_GUARD = 730,
};

BattlegroundAV::BattlegroundAV(BattlegroundTemplate const* battlegroundTemplate) : Battleground(battlegroundTemplate)
{
    BgObjects.resize(0);
    BgCreatures.resize(0);

    _teamResources = { BG_AV_SCORE_INITIAL_POINTS, BG_AV_SCORE_INITIAL_POINTS };
    _isInformedNearVictory = { false, false };

    for (uint8 i = 0; i < 2; i++) //forloop for both teams (it just make 0 == alliance and 1 == horde also for both mines 0=north 1=south
    {
        for (uint8 j = 0; j < 9; j++)
            m_Team_QuestStatus[i][j] = 0;

        _captainBuffTimer[i].Reset(120000 + urand(0, 4) * 60); //as far as i could see, the buff is randomly so i make 2minutes (thats the duration of the buff itself) + 0-4minutes @todo get the right times
    }

    _mineInfo[uint8(AlteracValleyMine::North)] = { TEAM_OTHER, { AV_WS_IRONDEEP_MINE_OWNER, AV_WS_IRONDEEP_MINE_ALLIANCE_CONTROLLED, AV_WS_IRONDEEP_MINE_HORDE_CONTROLLED, AV_WS_IRONDEEP_MINE_TROGG_CONTROLLED, TEXT_IRONDEEP_MINE_ALLIANCE_TAKEN, TEXT_IRONDEEP_MINE_HORDE_TAKEN } };
    _mineInfo[uint8(AlteracValleyMine::South)] = { TEAM_OTHER, { AV_WS_COLDTOOTH_MINE_OWNER, AV_WS_COLDTOOTH_MINE_ALLIANCE_CONTROLLED, AV_WS_COLDTOOTH_MINE_HORDE_CONTROLLED, AV_WS_COLDTOOTH_MINE_KOBOLD_CONTROLLED, TEXT_COLDTOOTH_MINE_ALLIANCE_TAKEN, TEXT_COLDTOOTH_MINE_HORDE_TAKEN } };

    for (BG_AV_Nodes i = BG_AV_NODES_FIRSTAID_STATION; i <= BG_AV_NODES_STONEHEART_GRAVE; ++i) //alliance graves
        InitNode(i, ALLIANCE, false);
    for (BG_AV_Nodes i = BG_AV_NODES_DUNBALDAR_SOUTH; i <= BG_AV_NODES_STONEHEART_BUNKER; ++i) //alliance towers
        InitNode(i, ALLIANCE, true);
    for (BG_AV_Nodes i = BG_AV_NODES_ICEBLOOD_GRAVE; i <= BG_AV_NODES_FROSTWOLF_HUT; ++i) //horde graves
        InitNode(i, HORDE, false);
    for (BG_AV_Nodes i = BG_AV_NODES_ICEBLOOD_TOWER; i <= BG_AV_NODES_FROSTWOLF_WTOWER; ++i) //horde towers
        InitNode(i, HORDE, true);
    InitNode(BG_AV_NODES_SNOWFALL_GRAVE, TEAM_OTHER, false); //give snowfall neutral owner

    _mineResourceTimer.Reset(BG_AV_MINE_RESOURCE_TIMER);

    StartMessageIds[BG_STARTING_EVENT_SECOND] = BG_AV_TEXT_START_ONE_MINUTE;
    StartMessageIds[BG_STARTING_EVENT_THIRD]  = BG_AV_TEXT_START_HALF_MINUTE;
    StartMessageIds[BG_STARTING_EVENT_FOURTH] = BG_AV_TEXT_BATTLE_HAS_BEGUN;
}

void BattlegroundAV::HandleKillPlayer(Player* player, Player* killer)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    Battleground::HandleKillPlayer(player, killer);
    UpdateScore(GetPlayerTeam(player->GetGUID()), -1);
}

void BattlegroundAV::HandleKillUnit(Creature* unit, Unit* killer)
{
    TC_LOG_DEBUG("bg.battleground", "bg_av HandleKillUnit {}", unit->GetEntry());
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    switch (unit->GetEntry())
    {
        case BG_AV_CREATURE_VANNDAR:
        {
            UpdateWorldState(AV_WS_VANDAAR_ALIVE, 0);
            CastSpellOnTeam(SPELL_COMPLETE_ALTERAC_VALLEY_QUEST, HORDE); //this is a spell which finishes a quest where a player has to kill the boss
            RewardReputationToTeam(FACTION_FROSTWOLF_CLAN, REP_GAIN_BOSS, HORDE);
            RewardHonorToTeam(GetBonusHonorFromKill(HONOR_KILL_BONUS_BOSS), HORDE);
            EndBattleground(HORDE);
            break;
        }
        case BG_AV_CREATURE_DREKTHAR:
        {
            UpdateWorldState(AV_WS_DREKTHAR_ALIVE, 0);
            CastSpellOnTeam(SPELL_COMPLETE_ALTERAC_VALLEY_QUEST, ALLIANCE); //this is a spell which finishes a quest where a player has to kill the boss
            RewardReputationToTeam(FACTION_STORMPIKE_GUARD, REP_GAIN_BOSS, ALLIANCE);
            RewardHonorToTeam(GetBonusHonorFromKill(HONOR_KILL_BONUS_BOSS), ALLIANCE);
            EndBattleground(ALLIANCE);
            break;
        }
        case BG_AV_CREATURE_BALINDA:
        {
            UpdateWorldState(AV_WS_BALINDA_ALIVE, 0);
            RewardReputationToTeam(FACTION_FROSTWOLF_CLAN, REP_GAIN_CAPTAIN, HORDE);
            RewardHonorToTeam(GetBonusHonorFromKill(HONOR_KILL_BONUS_CAPTAIN), HORDE);
            UpdateScore(ALLIANCE, RESOURCE_LOSS_CAPTAIN);
            if (Creature* herald = FindHerald("bg_av_herald_horde_win"))
                herald->AI()->Talk(TEXT_STORMPIKE_GENERAL_DEAD);
            break;
        }
        case BG_AV_CREATURE_GALVANGAR:
        {
            UpdateWorldState(AV_WS_GALVAGAR_ALIVE, 0);
            RewardReputationToTeam(FACTION_STORMPIKE_GUARD, REP_GAIN_CAPTAIN, ALLIANCE);
            RewardHonorToTeam(GetBonusHonorFromKill(HONOR_KILL_BONUS_CAPTAIN), ALLIANCE);
            UpdateScore(HORDE, RESOURCE_LOSS_CAPTAIN);
            if (Creature* herald = FindHerald("bg_av_herald_alliance_win"))
                herald->AI()->Talk(TEXT_FROSTWOLF_GENERAL_DEAD);
            break;
        }
        case BG_AV_CREATURE_MORLOCH:
        {
            // if mine is not owned by morloch, then nothing happens
            if (_mineInfo[uint8(AlteracValleyMine::North)].Owner != TEAM_OTHER)
                break;

            Team killerTeam = GetPlayerTeam(Coalesce<Unit>(killer->GetCharmerOrOwnerPlayerOrPlayerItself(), killer)->GetGUID());
            ChangeMineOwner(AlteracValleyMine::North, killerTeam);
            break;
        }
        case BG_AV_CREATURE_TASKMASTER_SNIVVLE:
        {
            if (_mineInfo[uint8(AlteracValleyMine::South)].Owner != TEAM_OTHER)
                break;

            Team killerTeam = GetPlayerTeam(Coalesce<Unit>(killer->GetCharmerOrOwnerPlayerOrPlayerItself(), killer)->GetGUID());
            ChangeMineOwner(AlteracValleyMine::South, killerTeam);
            break;
        }
        case BG_AV_CREATURE_UMI_THORSON:
        case BG_AV_CREATURE_KEETAR:
        {
            Team killerTeam = GetPlayerTeam(Coalesce<Unit>(killer->GetCharmerOrOwnerPlayerOrPlayerItself(), killer)->GetGUID());
            ChangeMineOwner(AlteracValleyMine::North, killerTeam);
            break;
        }
        case BG_AV_CREATURE_AGI_RUMBLESTOMP:
        case BG_AV_CREATURE_MASHA_SWIFTCUT:
        {
            Team killerTeam = GetPlayerTeam(Coalesce<Unit>(killer->GetCharmerOrOwnerPlayerOrPlayerItself(), killer)->GetGUID());
            ChangeMineOwner(AlteracValleyMine::South, killerTeam);
            break;
        }
    }
}

void BattlegroundAV::HandleQuestComplete(uint32 questid, Player* player)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;//maybe we should log this, cause this must be a cheater or a big bug
    Team team = GetPlayerTeam(player->GetGUID());
    TeamId teamIndex = GetTeamIndexByTeamId(team);
    /// @todo add reputation, events (including quest not available anymore, next quest available, go/npc de/spawning)and maybe honor
    TC_LOG_DEBUG("bg.battleground", "BG_AV Quest {} completed", questid);
    switch (questid)
    {
        case AV_QUEST_A_SCRAPS1:
        case AV_QUEST_A_SCRAPS2:
        case AV_QUEST_H_SCRAPS1:
        case AV_QUEST_H_SCRAPS2:
            m_Team_QuestStatus[teamIndex][0] += 20;
            break;
        case AV_QUEST_A_COMMANDER1:
        case AV_QUEST_H_COMMANDER1:
            m_Team_QuestStatus[teamIndex][1]++;
            RewardReputationToTeam(teamIndex, 1, team);
            if (m_Team_QuestStatus[teamIndex][1] == 30)
                TC_LOG_DEBUG("bg.battleground", "BG_AV Quest {} completed (need to implement some events here", questid);
            break;
        case AV_QUEST_A_COMMANDER2:
        case AV_QUEST_H_COMMANDER2:
            m_Team_QuestStatus[teamIndex][2]++;
            RewardReputationToTeam(teamIndex, 1, team);
            if (m_Team_QuestStatus[teamIndex][2] == 60)
                TC_LOG_DEBUG("bg.battleground", "BG_AV Quest {} completed (need to implement some events here", questid);
            break;
        case AV_QUEST_A_COMMANDER3:
        case AV_QUEST_H_COMMANDER3:
            m_Team_QuestStatus[teamIndex][3]++;
            RewardReputationToTeam(teamIndex, 1, team);
            if (m_Team_QuestStatus[teamIndex][3] == 120)
                TC_LOG_DEBUG("bg.battleground", "BG_AV Quest {} completed (need to implement some events here", questid);
            break;
        case AV_QUEST_A_BOSS1:
        case AV_QUEST_H_BOSS1:
            m_Team_QuestStatus[teamIndex][4] += 4; //you can turn in 5 or 1 item..
            [[fallthrough]];
        case AV_QUEST_A_BOSS2:
        case AV_QUEST_H_BOSS2:
            m_Team_QuestStatus[teamIndex][4]++;
            if (m_Team_QuestStatus[teamIndex][4] >= 200)
                TC_LOG_DEBUG("bg.battleground", "BG_AV Quest {} completed (need to implement some events here", questid);
            UpdateWorldState(teamIndex == TEAM_ALLIANCE ? AV_WS_IVUS_STORM_CRYSTAL_COUNT : AV_WS_LOKHOLAR_STORMPIKE_SOLDIERS_BLOOD_COUNT, m_Team_QuestStatus[teamIndex][4]);
            break;
        case AV_QUEST_A_NEAR_MINE:
        case AV_QUEST_H_NEAR_MINE:
            m_Team_QuestStatus[teamIndex][5]++;
            if (m_Team_QuestStatus[teamIndex][5] == 28)
            {
                TC_LOG_DEBUG("bg.battleground", "BG_AV Quest {} completed (need to implement some events here", questid);
                if (m_Team_QuestStatus[teamIndex][6] == 7)
                    TC_LOG_DEBUG("bg.battleground", "BG_AV Quest {} completed (need to implement some events here - ground assault ready", questid);
            }
            break;
        case AV_QUEST_A_OTHER_MINE:
        case AV_QUEST_H_OTHER_MINE:
            m_Team_QuestStatus[teamIndex][6]++;
            if (m_Team_QuestStatus[teamIndex][6] == 7)
            {
                TC_LOG_DEBUG("bg.battleground", "BG_AV Quest {} completed (need to implement some events here", questid);
                if (m_Team_QuestStatus[teamIndex][5] == 20)
                    TC_LOG_DEBUG("bg.battleground", "BG_AV Quest {} completed (need to implement some events here - ground assault ready", questid);
            }
            break;
        case AV_QUEST_A_RIDER_HIDE:
        case AV_QUEST_H_RIDER_HIDE:
            m_Team_QuestStatus[teamIndex][7]++;
            if (m_Team_QuestStatus[teamIndex][7] == 25)
            {
                TC_LOG_DEBUG("bg.battleground", "BG_AV Quest {} completed (need to implement some events here", questid);
                if (m_Team_QuestStatus[teamIndex][8] == 25)
                    TC_LOG_DEBUG("bg.battleground", "BG_AV Quest {} completed (need to implement some events here - rider assault ready", questid);
            }
            break;
        case AV_QUEST_A_RIDER_TAME:
        case AV_QUEST_H_RIDER_TAME:
            m_Team_QuestStatus[teamIndex][8]++;
            if (m_Team_QuestStatus[teamIndex][8] == 25)
            {
                TC_LOG_DEBUG("bg.battleground", "BG_AV Quest {} completed (need to implement some events here", questid);
                if (m_Team_QuestStatus[teamIndex][7] == 25)
                    TC_LOG_DEBUG("bg.battleground", "BG_AV Quest {} completed (need to implement some events here - rider assault ready", questid);
            }
            break;
        default:
            TC_LOG_DEBUG("bg.battleground", "BG_AV Quest {} completed but is not interesting at all", questid);
            break;
    }
}

void BattlegroundAV::UpdateScore(Team team, int16 points)
{
    ASSERT(team == ALLIANCE || team == HORDE);
    TeamId teamindex = GetTeamIndexByTeamId(team);
    _teamResources[teamindex] += points;

    UpdateWorldState(teamindex == TEAM_HORDE ? AV_WS_HORDE_REINFORCEMENTS : AV_WS_ALLIANCE_REINFORCEMENTS, _teamResources[teamindex]);
    if (points < 0)
    {
        if (_teamResources[teamindex] < 1)
        {
            _teamResources[teamindex] = 0;
            EndBattleground(teamindex == TEAM_HORDE ? ALLIANCE : HORDE);
        }
        else if (!_isInformedNearVictory[teamindex] && _teamResources[teamindex] < NEAR_LOSE_POINTS)
        {
            if (teamindex == TEAM_ALLIANCE)
                SendBroadcastText(BG_AV_TEXT_ALLIANCE_NEAR_LOSE, CHAT_MSG_BG_SYSTEM_ALLIANCE);
            else
                SendBroadcastText(BG_AV_TEXT_HORDE_NEAR_LOSE, CHAT_MSG_BG_SYSTEM_HORDE);
            PlaySoundToAll(AV_SOUND_NEAR_VICTORY);
            _isInformedNearVictory[teamindex] = true;
        }
    }
}

void BattlegroundAV::PostUpdateImpl(uint32 diff)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    _mineResourceTimer.Update(diff);
    if (_mineResourceTimer.Passed())
    {
        for (AlteracValleyMineInfo const& info : _mineInfo)
        {
            if (info.Owner == TEAM_OTHER)
                continue;

            UpdateScore(info.Owner, 1);
        }

        _mineResourceTimer.Reset(BG_AV_MINE_RESOURCE_TIMER);
    }

    for (uint8 i = TEAM_ALLIANCE; i <= TEAM_HORDE; i++)
    {
        if (!IsCaptainAlive(TeamId(i)))
            continue;

        _captainBuffTimer[i].Update(diff);
        if (_captainBuffTimer[i].Passed())
        {
            if (i == 0)
            {
                CastSpellOnTeam(AV_BUFF_A_CAPTAIN, ALLIANCE);
                if (Creature* creature = GetBgMap()->GetCreature(_balindaGUID))
                    creature->AI()->DoAction(ACTION_BUFF_YELL);
            }
            else
            {
                CastSpellOnTeam(AV_BUFF_H_CAPTAIN, HORDE);
                if (Creature* creature = GetBgMap()->GetCreature(_galvangarGUID))
                    creature->AI()->DoAction(ACTION_BUFF_YELL);
            }

            _captainBuffTimer[i].Reset(120000 + urand(0, 4) * 60000); //as far as i could see, the buff is randomly so i make 2minutes (thats the duration of the buff itself) + 0-4minutes @todo get the right times
        }
    }
}

bool BattlegroundAV::IsCaptainAlive(TeamId teamId) const
{
    if (teamId == TEAM_HORDE)
        return GetBgMap()->GetWorldStateValue(AV_WS_GALVAGAR_ALIVE) == 1;
    else if (teamId == TEAM_ALLIANCE)
        return GetBgMap()->GetWorldStateValue(AV_WS_BALINDA_ALIVE) == 1;

    return false;
}

void BattlegroundAV::StartingEventOpenDoors()
{
    TC_LOG_DEBUG("bg.battleground", "BG_AV: start spawning mine stuff");

    UpdateWorldState(AV_WS_SHOW_HORDE_REINFORCEMENTS, 1);
    UpdateWorldState(AV_WS_SHOW_ALLIANCE_REINFORCEMENTS, 1);

    // Achievement: The Alterac Blitz
    TriggerGameEvent(BG_AV_EVENT_START_BATTLE);

    for (ObjectGuid const& guid : _doorGUIDs)
    {
        if (GameObject* gameObject = GetBgMap()->GetGameObject(guid))
        {
            gameObject->UseDoorOrButton();
            Seconds delay = gameObject->GetEntry() == BG_AV_GHOST_GATE ? 0s : 3s;
            gameObject->DespawnOrUnsummon(delay);
        }
    }
}

void BattlegroundAV::EndBattleground(Team winner)
{
    //calculate bonuskills for both teams:
    //first towers:
    std::array<uint8, PVP_TEAMS_COUNT> kills = { 0, 0 };
    std::array<uint8, PVP_TEAMS_COUNT> rep = { 0, 0 };

    for (BG_AV_Nodes i = BG_AV_NODES_DUNBALDAR_SOUTH; i <= BG_AV_NODES_FROSTWOLF_WTOWER; ++i)
    {
        if (_nodes[i].State == POINT_CONTROLED)
        {
            if (_nodes[i].Owner == ALLIANCE)
            {
                rep[TEAM_ALLIANCE]   += REP_GAIN_SURVIVING_TOWER;
                kills[TEAM_ALLIANCE] += HONOR_KILL_BONUS_SURVIVING_TOWER;
            }
            else
            {
                rep[TEAM_HORDE]   += REP_GAIN_SURVIVING_TOWER;
                kills[TEAM_HORDE] += HONOR_KILL_BONUS_SURVIVING_TOWER;
            }
        }
    }

    for (uint8 i = TEAM_ALLIANCE; i <= TEAM_HORDE; ++i)
    {
        if (IsCaptainAlive(TeamId(i)))
        {
            kills[i] += HONOR_KILL_BONUS_SURVIVING_CAPTAIN;
            rep[i]   += REP_GAIN_SURVIVING_CAPTAIN;
        }
        if (rep[i] != 0)
            RewardReputationToTeam(i == 0 ? FACTION_STORMPIKE_GUARD : FACTION_FROSTWOLF_CLAN, rep[i], i == 0 ? ALLIANCE : HORDE);
        if (kills[i] != 0)
            RewardHonorToTeam(GetBonusHonorFromKill(kills[i]), i == 0 ? ALLIANCE : HORDE);
    }

    /// @todo add enterevademode for all attacking creatures
    Battleground::EndBattleground(winner);
}

void BattlegroundAV::RemovePlayer(Player* player, ObjectGuid /*guid*/, uint32 /*team*/)
{
    if (!player)
    {
        TC_LOG_ERROR("bg.battleground", "bg_AV no player at remove");
        return;
    }
    /// @todo search more buffs
    player->RemoveAurasDueToSpell(AV_BUFF_ARMOR);
}

void BattlegroundAV::EventPlayerDestroyedPoint(GameObject* gameobject)
{
    if (!gameobject)
        return;

    BG_AV_Nodes node = GetNodeThroughObject(gameobject->GetEntry());
    DestroyNode(node);
    UpdateNodeWorldState(node);

    Team owner = _nodes[node].Owner;
    if (IsTower(node))
    {
        UpdateScore((owner == ALLIANCE) ? HORDE : ALLIANCE, RESOURCE_LOSS_TOWER);
        RewardReputationToTeam(owner == ALLIANCE ? FACTION_STORMPIKE_GUARD : FACTION_FROSTWOLF_CLAN, REP_GAIN_DESTROY_TOWER, owner);
        RewardHonorToTeam(GetBonusHonorFromKill(HONOR_KILL_BONUS_DESTROY_TOWER), owner);
    }

    if (StaticNodeInfo const* nodeInfo = GetStaticNodeInfo(node))
        if (Creature* herald = FindHerald(nodeInfo->StringIds.HordeOrDestroy))
            herald->AI()->Talk(owner == ALLIANCE ? nodeInfo->TextIds.AllianceCapture : nodeInfo->TextIds.HordeCapture);

    GetBgMap()->UpdateSpawnGroupConditions();
}

void BattlegroundAV::DoAction(uint32 actionId, WorldObject* source, WorldObject* target)
{
    switch (actionId)
    {
        case ACTION_AV_CAPTURE_CAPTURABLE_OBJECT:
            EventPlayerDestroyedPoint(source->ToGameObject());
            break;
        case ACTION_AV_INTERACT_CAPTURABLE_OBJECT:
            if (target && source && source->IsPlayer())
                HandleInteractCapturableObject(source->ToPlayer(), target->ToGameObject());
            break;
        default:
            TC_LOG_ERROR("bg.battleground", "BattlegroundAV::DoAction: {}. Unhandled action.", actionId);
            break;
    }
}

void BattlegroundAV::ChangeMineOwner(AlteracValleyMine mine, Team team, bool initial)
{
    if (team != ALLIANCE && team != HORDE)
        team = TEAM_OTHER;

    AlteracValleyMineInfo& mineInfo = _mineInfo[uint8(mine)];

    if (mineInfo.Owner == team && !initial)
        return;

    mineInfo.Owner = team;

    SendMineWorldStates(mine);

    uint8 textId = team == ALLIANCE ? mineInfo.StaticInfo.TextIdAlliance : mineInfo.StaticInfo.TextIdHorde;

    std::string stringId = team == ALLIANCE ? "bg_av_herald_mine_alliance" : "bg_av_herald_mine_horde";

    if (Creature* herald = FindHerald(stringId))
        herald->AI()->Talk(textId);
}

BG_AV_Nodes BattlegroundAV::GetNodeThroughObject(uint32 object)
{
    switch (object)
    {
        case BG_AV_OBJECTID_AID_STATION_ALLIANCE_CONTROLLED:
        case BG_AV_OBJECTID_AID_STATION_HORDE_CONTESTED:
        case BG_AV_OBJECTID_AID_STATION_HORDE_CONTROLLED:
        case BG_AV_OBJECTID_AID_STATION_ALLIANCE_CONTESTED:
            return BG_AV_NODES_FIRSTAID_STATION;
        case BG_AV_OBJECTID_STORMPIKE_ALLIANCE_CONTROLLED:
        case BG_AV_OBJECTID_STORMPIKE_HORDE_CONTESTED:
        case BG_AV_OBJECTID_STORMPIKE_HORDE_CONTROLLED:
        case BG_AV_OBJECTID_STORMPIKE_ALLIANCE_CONTESTED:
            return BG_AV_NODES_STORMPIKE_GRAVE;
        case BG_AV_OBJECTID_STONEHEARTH_HORDE_CONTESTED:
        case BG_AV_OBJECTID_STONEHEARTH_HORDE_CONTROLLED:
        case BG_AV_OBJECTID_STONEHEARTH_ALLIANCE_CONTESTED:
        case BG_AV_OBJECTID_STONEHEARTH_ALLIANCE_CONTROLLED:
            return BG_AV_NODES_STONEHEART_GRAVE;
        case BG_AV_OBJECTID_SNOWFALL_NEUTRAL:
        case BG_AV_OBJECTID_SNOWFALL_HORDE_CONTESTED:
        case BG_AV_OBJECTID_SNOWFALL_ALLIANCE_CONTESTED:
        case BG_AV_OBJECTID_SNOWFALL_HORDE_CONTROLLED:
        case BG_AV_OBJECTID_SNOWFALL_ALLIANCE_CONTROLLED:
            return BG_AV_NODES_SNOWFALL_GRAVE;
        case BG_AV_OBJECTID_ICEBLOOD_HORDE_CONTROLLED:
        case BG_AV_OBJECTID_ICEBLOOD_ALLIANCE_CONTESTED:
        case BG_AV_OBJECTID_ICEBLOOD_ALLIANCE_CONTROLLED:
        case BG_AV_OBJECTID_ICEBLOOD_HORDE_CONTESTED:
            return BG_AV_NODES_ICEBLOOD_GRAVE;
        case BG_AV_OBJECTID_FROSTWOLF_HORDE_CONTROLLED:
        case BG_AV_OBJECTID_FROSTWOLF_ALLIANCE_CONTESTED:
        case BG_AV_OBJECTID_FROSTWOLF_ALLIANCE_CONTROLLED:
        case BG_AV_OBJECTID_FROSTWOLF_HORDE_CONTESTED:
            return BG_AV_NODES_FROSTWOLF_GRAVE;
        case BG_AV_OBJECTID_FROSTWOLF_HUT_HORDE_CONTROLLED:
        case BG_AV_OBJECTID_FROSTWOLF_HUT_ALLIANCE_CONTESTED:
        case BG_AV_OBJECTID_FROSTWOLF_HUT_ALLIANCE_CONTROLLED:
        case BG_AV_OBJECTID_FROSTWOLF_HUT_HORDE_CONTESTED:
            return BG_AV_NODES_FROSTWOLF_HUT;
        case BG_AV_OBJECTID_SOUTH_BUNKER_CONTROLLED_TOWER_BANNER:
        case BG_AV_OBJECTID_SOUTH_BUNKER_CONTROLLED_BANNER:
        case BG_AV_OBJECTID_SOUTH_BUNKER_CONTESTED_BANNER:
        case BG_AV_OBJECTID_SOUTH_BUNKER_CONTESTED_TOWER_BANNER:
            return BG_AV_NODES_DUNBALDAR_SOUTH;
        case BG_AV_OBJECTID_NORTH_BUNKER_CONTROLLED_TOWER_BANNER:
        case BG_AV_OBJECTID_NORTH_BUNKER_CONTROLLED_BANNER:
        case BG_AV_OBJECTID_NORTH_BUNKER_CONTESTED_BANNER:
        case BG_AV_OBJECTID_NORTH_BUNKER_CONTESTED_TOWER_BANNER:
            return BG_AV_NODES_DUNBALDAR_NORTH;
        case BG_AV_OBJECTID_EAST_TOWER_CONTROLLED_TOWER_BANNER:
        case BG_AV_OBJECTID_EAST_TOWER_CONTROLLED_BANNER:
        case BG_AV_OBJECTID_EAST_TOWER_CONTESTED_BANNER:
        case BG_AV_OBJECTID_EAST_TOWER_CONTESTED_TOWER_BANNER:
            return BG_AV_NODES_FROSTWOLF_ETOWER;
        case BG_AV_OBJECTID_WEST_TOWER_CONTROLLED_TOWER_BANNER:
        case BG_AV_OBJECTID_WEST_TOWER_CONTROLLED_BANNER:
        case BG_AV_OBJECTID_WEST_TOWER_CONTESTED_BANNER:
        case BG_AV_OBJECTID_WEST_TOWER_CONTESTED_TOWER_BANNER:
            return BG_AV_NODES_FROSTWOLF_WTOWER;
        case BG_AV_OBJECTID_TOWER_POINT_CONTROLLED_TOWER_BANNER:
        case BG_AV_OBJECTID_TOWER_POINT_CONTROLLED_BANNER:
        case BG_AV_OBJECTID_TOWER_POINT_CONTESTED_BANNER:
        case BG_AV_OBJECTID_TOWER_POINT_CONTESTED_TOWER_BANNER:
            return BG_AV_NODES_TOWER_POINT;
        case BG_AV_OBJECTID_ICEBLOOD_TOWER_CONTROLLED_TOWER_BANNER:
        case BG_AV_OBJECTID_ICEBLOOD_TOWER_CONTROLLED_BANNER:
        case BG_AV_OBJECTID_ICEBLOOD_TOWER_CONTESTED_BANNER:
        case BG_AV_OBJECTID_ICEBLOOD_TOWER_CONTESTED_TOWER_BANNER:
            return BG_AV_NODES_ICEBLOOD_TOWER;
        case BG_AV_OBJECTID_STONEHEARTH_BUNKER_CONTROLLED_TOWER_BANNER:
        case BG_AV_OBJECTID_STONEHEARTH_BUNKER_CONTROLLED_BANNER:
        case BG_AV_OBJECTID_STONEHEARTH_BUNKER_CONTESTED_BANNER:
        case BG_AV_OBJECTID_STONEHEARTH_BUNKER_CONTESTED_TOWER_BANNER:
            return BG_AV_NODES_STONEHEART_BUNKER;
        case BG_AV_OBJECTID_ICEWING_BUNKER_CONTROLLED_TOWER_BANNER:
        case BG_AV_OBJECTID_ICEWING_BUNKER_CONTROLLED_BANNER:
        case BG_AV_OBJECTID_ICEWING_BUNKER_CONTESTED_BANNER:
        case BG_AV_OBJECTID_ICEWING_BUNKER_CONTESTED_TOWER_BANNER:
            return BG_AV_NODES_ICEWING_BUNKER;
        default:
            TC_LOG_ERROR("bg.battleground", "BattlegroundAV: ERROR! GetPlace got a wrong object :(");
            ABORT();
            return BG_AV_Nodes(0);
    }
}

void BattlegroundAV::HandleInteractCapturableObject(Player* player, GameObject* target)
{
    if (!player || !target)
        return;

    switch (target->GetEntry())
    {
        // graveyards
        case BG_AV_OBJECTID_AID_STATION_ALLIANCE_CONTROLLED:
        case BG_AV_OBJECTID_AID_STATION_HORDE_CONTROLLED:
        case BG_AV_OBJECTID_FROSTWOLF_ALLIANCE_CONTROLLED:
        case BG_AV_OBJECTID_FROSTWOLF_HORDE_CONTROLLED:
        case BG_AV_OBJECTID_FROSTWOLF_HUT_ALLIANCE_CONTROLLED:
        case BG_AV_OBJECTID_FROSTWOLF_HUT_HORDE_CONTROLLED:
        case BG_AV_OBJECTID_ICEBLOOD_ALLIANCE_CONTROLLED:
        case BG_AV_OBJECTID_ICEBLOOD_HORDE_CONTROLLED:
        case BG_AV_OBJECTID_STONEHEARTH_ALLIANCE_CONTROLLED:
        case BG_AV_OBJECTID_STONEHEARTH_HORDE_CONTROLLED:
        case BG_AV_OBJECTID_STORMPIKE_ALLIANCE_CONTROLLED:
        case BG_AV_OBJECTID_STORMPIKE_HORDE_CONTROLLED:
        // Snowfall
        case BG_AV_OBJECTID_SNOWFALL_NEUTRAL:
        case BG_AV_OBJECTID_SNOWFALL_ALLIANCE_CONTROLLED:
        case BG_AV_OBJECTID_SNOWFALL_HORDE_CONTROLLED:
        // towers
        case BG_AV_OBJECTID_EAST_TOWER_CONTROLLED_BANNER:
        case BG_AV_OBJECTID_WEST_TOWER_CONTROLLED_BANNER:
        case BG_AV_OBJECTID_TOWER_POINT_CONTROLLED_BANNER:
        case BG_AV_OBJECTID_ICEBLOOD_TOWER_CONTROLLED_BANNER:
        case BG_AV_OBJECTID_STONEHEARTH_BUNKER_CONTROLLED_BANNER:
        case BG_AV_OBJECTID_ICEWING_BUNKER_CONTROLLED_BANNER:
        case BG_AV_OBJECTID_SOUTH_BUNKER_CONTROLLED_BANNER:
        case BG_AV_OBJECTID_NORTH_BUNKER_CONTROLLED_BANNER:
            EventPlayerAssaultsPoint(player, target->GetEntry());
            break;
        // graveyards
        case BG_AV_OBJECTID_AID_STATION_ALLIANCE_CONTESTED:
        case BG_AV_OBJECTID_AID_STATION_HORDE_CONTESTED:
        case BG_AV_OBJECTID_FROSTWOLF_ALLIANCE_CONTESTED:
        case BG_AV_OBJECTID_FROSTWOLF_HORDE_CONTESTED:
        case BG_AV_OBJECTID_FROSTWOLF_HUT_ALLIANCE_CONTESTED:
        case BG_AV_OBJECTID_FROSTWOLF_HUT_HORDE_CONTESTED:
        case BG_AV_OBJECTID_ICEBLOOD_ALLIANCE_CONTESTED:
        case BG_AV_OBJECTID_ICEBLOOD_HORDE_CONTESTED:
        case BG_AV_OBJECTID_STONEHEARTH_ALLIANCE_CONTESTED:
        case BG_AV_OBJECTID_STONEHEARTH_HORDE_CONTESTED:
        case BG_AV_OBJECTID_STORMPIKE_ALLIANCE_CONTESTED:
        case BG_AV_OBJECTID_STORMPIKE_HORDE_CONTESTED:
        // towers
        case BG_AV_OBJECTID_EAST_TOWER_CONTESTED_BANNER:
        case BG_AV_OBJECTID_WEST_TOWER_CONTESTED_BANNER:
        case BG_AV_OBJECTID_TOWER_POINT_CONTESTED_BANNER:
        case BG_AV_OBJECTID_ICEBLOOD_TOWER_CONTESTED_BANNER:
        case BG_AV_OBJECTID_STONEHEARTH_BUNKER_CONTESTED_BANNER:
        case BG_AV_OBJECTID_ICEWING_BUNKER_CONTESTED_BANNER:
        case BG_AV_OBJECTID_SOUTH_BUNKER_CONTESTED_BANNER:
        case BG_AV_OBJECTID_NORTH_BUNKER_CONTESTED_BANNER:
            EventPlayerDefendsPoint(player, target->GetEntry());
            break;
        // Snowfall special cases (either defend/assault)
        case BG_AV_OBJECTID_SNOWFALL_ALLIANCE_CONTESTED:
        case BG_AV_OBJECTID_SNOWFALL_HORDE_CONTESTED:
        {
            BG_AV_Nodes node = GetNodeThroughObject(target->GetEntry());
            if (_nodes[node].TotalOwner == TEAM_OTHER)
                EventPlayerAssaultsPoint(player, target->GetEntry());
            else
                EventPlayerDefendsPoint(player, target->GetEntry());
            break;
        }
        default:
            break;
    }
}

void BattlegroundAV::EventPlayerDefendsPoint(Player* player, uint32 object)
{
    BG_AV_Nodes node = GetNodeThroughObject(object);

    Team owner = _nodes[node].Owner;
    Team team = GetPlayerTeam(player->GetGUID());

    if (owner == team || _nodes[node].State != POINT_ASSAULTED)
        return;

    TC_LOG_DEBUG("bg.battleground", "player defends point object: {} node: {}", object, node);
    if (_nodes[node].PrevOwner != team)
    {
        TC_LOG_ERROR("bg.battleground", "BG_AV: player defends point which doesn't belong to his team {}", node);
        return;
    }

    DefendNode(node, team);
    UpdateNodeWorldState(node);

    if (StaticNodeInfo const* nodeInfo = GetStaticNodeInfo(node))
    {
        std::string stringId;

        if (IsTower(node))
            stringId = nodeInfo->StringIds.AllianceOrDefend;
        else
            stringId = team == ALLIANCE ? nodeInfo->StringIds.AllianceOrDefend : nodeInfo->StringIds.HordeOrDestroy;

        if (Creature* herald = FindHerald(stringId))
            herald->AI()->Talk(team == ALLIANCE ? nodeInfo->TextIds.AllianceCapture : nodeInfo->TextIds.HordeCapture);
    }

    // update the statistic for the defending player
    UpdatePvpStat(player, IsTower(node) ? PVP_STAT_TOWERS_DEFENDED : PVP_STAT_GRAVEYARDS_DEFENDED, 1);
    GetBgMap()->UpdateSpawnGroupConditions();
}

void BattlegroundAV::EventPlayerAssaultsPoint(Player* player, uint32 object)
{
    BG_AV_Nodes node = GetNodeThroughObject(object);
    Team owner = _nodes[node].Owner; //maybe name it prevowner
    Team team  = GetPlayerTeam(player->GetGUID());

    TC_LOG_DEBUG("bg.battleground", "bg_av: player assaults point object {} node {}", object, node);
    if (owner == team || team == _nodes[node].TotalOwner)
        return; //surely a gm used this object

    AssaultNode(node, team);
    UpdateNodeWorldState(node);

    if (StaticNodeInfo const* nodeInfo = GetStaticNodeInfo(node))
    {
        std::string stringId;
        if (IsTower(node))
            stringId = nodeInfo->StringIds.HordeOrDestroy;
        else
            stringId = team == ALLIANCE ? nodeInfo->StringIds.AllianceOrDefend : nodeInfo->StringIds.HordeOrDestroy;

        if (Creature* herald = FindHerald(stringId))
            herald->AI()->Talk(team == ALLIANCE ? nodeInfo->TextIds.AllianceAttack : nodeInfo->TextIds.HordeAttack);
    }

    // update the statistic for the assaulting player
    UpdatePvpStat(player, (IsTower(node)) ? PVP_STAT_TOWERS_ASSAULTED : PVP_STAT_GRAVEYARDS_ASSAULTED, 1);
    GetBgMap()->UpdateSpawnGroupConditions();
}

void BattlegroundAV::UpdateNodeWorldState(BG_AV_Nodes node)
{
    if (StaticNodeInfo const* nodeInfo = GetStaticNodeInfo(node))
    {
        uint16 owner = _nodes[node].Owner;
        BG_AV_States state = _nodes[node].State;

        UpdateWorldState(nodeInfo->WorldStateIds.AllianceAssault, owner == ALLIANCE && state == POINT_ASSAULTED);
        UpdateWorldState(nodeInfo->WorldStateIds.AllianceControl, owner == ALLIANCE && state >= POINT_DESTROYED);
        UpdateWorldState(nodeInfo->WorldStateIds.HordeAssault, owner == HORDE && state == POINT_ASSAULTED);
        UpdateWorldState(nodeInfo->WorldStateIds.HordeControl, owner == HORDE && state >= POINT_DESTROYED);
        if (nodeInfo->WorldStateIds.Owner)
            UpdateWorldState(nodeInfo->WorldStateIds.Owner, owner == HORDE ? 2 : owner == ALLIANCE ? 1 : 0);
    }

    if (node == BG_AV_NODES_SNOWFALL_GRAVE)
        UpdateWorldState(AV_WS_SNOWFALL_GRAVEYARD_UNCONTROLLED, _nodes[node].Owner == TEAM_OTHER);
}

void BattlegroundAV::SendMineWorldStates(AlteracValleyMine mine)
{
    AlteracValleyMineInfo& mineInfo = _mineInfo[uint8(mine)];
    UpdateWorldState(mineInfo.StaticInfo.WorldStateHordeControlled, mineInfo.Owner == HORDE);
    UpdateWorldState(mineInfo.StaticInfo.WorldStateAllianceControlled, mineInfo.Owner == ALLIANCE);
    UpdateWorldState(mineInfo.StaticInfo.WorldStateNeutralControlled, mineInfo.Owner == TEAM_OTHER);
    UpdateWorldState(mineInfo.StaticInfo.WorldStateOwner, mineInfo.Owner == HORDE ? 2 : mineInfo.Owner == ALLIANCE ? 1 : 0);
}

WorldSafeLocsEntry const* BattlegroundAV::GetExploitTeleportLocation(Team team)
{
    return sObjectMgr->GetWorldSafeLoc(team == ALLIANCE ? AV_EXPLOIT_TELEPORT_LOCATION_ALLIANCE : AV_EXPLOIT_TELEPORT_LOCATION_HORDE);
}

bool BattlegroundAV::SetupBattleground()
{
    return true;
}

void BattlegroundAV::AssaultNode(BG_AV_Nodes node, Team team)
{
    _nodes[node].PrevOwner  = _nodes[node].Owner;
    _nodes[node].Owner      = team;
    _nodes[node].PrevState  = _nodes[node].State;
    _nodes[node].State      = POINT_ASSAULTED;
}

void BattlegroundAV::DestroyNode(BG_AV_Nodes node)
{
    _nodes[node].TotalOwner = _nodes[node].Owner;
    _nodes[node].PrevOwner  = _nodes[node].Owner;
    _nodes[node].PrevState  = _nodes[node].State;
    _nodes[node].State      = (_nodes[node].Tower)? POINT_DESTROYED : POINT_CONTROLED;
}

void BattlegroundAV::InitNode(BG_AV_Nodes node, Team team, bool tower)
{
    _nodes[node].TotalOwner = team;
    _nodes[node].Owner      = team;
    _nodes[node].PrevOwner  = 0;
    _nodes[node].State      = POINT_CONTROLED;
    _nodes[node].PrevState  = _nodes[node].State;
    _nodes[node].State      = POINT_CONTROLED;
    _nodes[node].Tower      = tower;
}

void BattlegroundAV::DefendNode(BG_AV_Nodes node, Team team)
{
    _nodes[node].PrevOwner  = _nodes[node].Owner;
    _nodes[node].Owner      = team;
    _nodes[node].PrevState  = _nodes[node].State;
    _nodes[node].State      = POINT_CONTROLED;
}

Team BattlegroundAV::GetPrematureWinner()
{
    uint32 allianceScore = _teamResources[GetTeamIndexByTeamId(ALLIANCE)];
    uint32 hordeScore = _teamResources[GetTeamIndexByTeamId(HORDE)];

    if (allianceScore > hordeScore)
        return ALLIANCE;
    else if (hordeScore > allianceScore)
        return HORDE;

    return Battleground::GetPrematureWinner();
}

void BattlegroundAV::OnGameObjectCreate(GameObject* gameObject)
{
    switch (gameObject->GetEntry())
    {
        case BG_AV_GHOST_GATE:
        case BG_AV_OBJECTID_GATE:
            _doorGUIDs.insert(gameObject->GetGUID());
            break;
        default:
            break;
    }
}

void BattlegroundAV::OnCreatureCreate(Creature* creature)
{
    switch (creature->GetEntry())
    {
        case BG_AV_CREATURE_GALVANGAR:
            _galvangarGUID = creature->GetGUID();
            break;
        case BG_AV_CREATURE_BALINDA:
            _balindaGUID = creature->GetGUID();
            break;
        case BG_AV_CREATURE_HERALD:
            _heraldGUIDs.insert(creature->GetGUID());
            break;
        default:
            break;
    }
}

uint32 BattlegroundAV::GetData(uint32 dataId) const
{
    auto getDefenderTierForTeam = [&](TeamId teamId) -> BG_AV_DefenderTier
    {
        if (m_Team_QuestStatus[teamId][0] < 500)
            return BG_AV_DEFENDER_TIER_DEFENDER;

        if (m_Team_QuestStatus[teamId][0] < 1000)
            return BG_AV_DEFENDER_TIER_SEASONED;

        if (m_Team_QuestStatus[teamId][0] < 1500)
            return BG_AV_DEFENDER_TIER_VETERAN;

        return BG_AV_DEFENDER_TIER_CHAMPION;
    };

    switch (dataId)
    {
        case DATA_DEFENDER_TIER_ALLIANCE:
            return getDefenderTierForTeam(TEAM_ALLIANCE);
        case DATA_DEFENDER_TIER_HORDE:
            return getDefenderTierForTeam(TEAM_HORDE);
        default:
            return Battleground::GetData(dataId);
    }
}

Creature* BattlegroundAV::FindHerald(std::string_view stringId) const
{
    for (ObjectGuid const& guid : _heraldGUIDs)
        if (Creature* creature = GetBgMap()->GetCreature(guid))
            if (creature->HasStringId(stringId))
                return creature;

    return nullptr;
}
