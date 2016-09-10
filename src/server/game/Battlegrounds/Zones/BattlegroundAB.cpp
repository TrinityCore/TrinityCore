/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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
#include "WorldPacket.h"
#include "BattlegroundMgr.h"
#include "Creature.h"
#include "Language.h"
#include "Player.h"
#include "Util.h"
#include "WorldSession.h"

uint32 const BG_AB_OP_NODESTATES[5] = { 1767, 1782, 1772, 1792, 1787 };
uint32 const BG_AB_OP_NODEICONS[5] = { 1842, 1846, 1845, 1844, 1843 };

uint32 const BG_AB_NotABBGWeekendHonorTicks      = 260;
uint32 const BG_AB_ABBGWeekendHonorTicks         = 160;
uint32 const BG_AB_NotABBGWeekendReputationTicks = 160;
uint32 const BG_AB_ABBGWeekendReputationTicks    = 120;

uint32 const AB_EVENT_START_BATTLE               = 9158; // Achievement: Let's Get This Done

uint32 const BG_AB_NodeGameObject[BG_AB_DYNAMIC_NODE_GO_COUNT] =
{
    BG_AB_OBJECTID_NODE_BANNER_0,
    BG_AB_OBJECTID_BANNER_CONT_A,
    BG_AB_OBJECTID_BANNER_CONT_H,
    BG_AB_OBJECTID_BANNER_A,
    BG_AB_OBJECTID_BANNER_H,
    BG_AB_OBJECTID_AURA_A,
    BG_AB_OBJECTID_AURA_H,
    BG_AB_OBJECTID_AURA_C
};

BattlegroundGOSpawnPoint const BG_AB_NodePositions[BG_AB_DYNAMIC_NODES_COUNT] =
{
    { 0, { 1166.785f, 1200.132f, -56.70859f,  0.9075713f }, { 0.f, 0.f,  0.4383707f, 0.8987942f }, RESPAWN_ONE_DAY },      // stables
    { 0, { 977.0799f, 1046.542f, -44.83030f, -2.6179890f }, { 0.f, 0.f, -0.9659252f, 0.2588213f }, RESPAWN_ONE_DAY },      // blacksmith
    { 0, { 806.1821f, 874.2723f, -55.99371f, -2.3038310f }, { 0.f, 0.f, -0.9135447f, 0.4067384f }, RESPAWN_ONE_DAY },      // farm
    { 0, { 856.1419f, 1148.902f,  11.18469f, -2.3038310f }, { 0.f, 0.f, -0.9135447f, 0.4067384f }, RESPAWN_ONE_DAY },      // lumber mill
    { 0, { 1146.922f, 848.1899f, -110.9200f,  2.4260080f }, { 0.f, 0.f,  0.9366722f, 0.3502074f }, RESPAWN_ONE_DAY }       // gold mine
};

BattlegroundGOSpawnPoint const BattlegroundABDoors[BG_TEAMS_COUNT] =
{
    { BG_AB_OBJECTID_GATE_A, { 1284.597f, 1281.167f, -15.97792f,  0.7068594f }, { 0.012957f, -0.060288f, 0.344959f,  0.936590f }, RESPAWN_IMMEDIATELY },
    { BG_AB_OBJECTID_GATE_H, { 708.0903f, 708.4479f, -17.83420f, -2.3910990f }, { 0.050291f,  0.015127f, 0.929217f, -0.365784f }, RESPAWN_IMMEDIATELY }
};

uint32 const BG_AB_BuffEntries[BG_MAX_BUFFS] =
{
    BG_AB_FOOD_BUFF,
    BG_AB_BERSERK_BUFF,
    BG_AB_SPEED_BUFF
};

BattlegroundBuffData const buffEntries =
{
    { BG_AB_SPEED_BUFF, BG_AB_FOOD_BUFF, BG_AB_BERSERK_BUFF }
};

BattlegroundGOSpawnPoint const BG_AB_BuffPositions[BG_AB_DYNAMIC_NODES_COUNT] =
{
    { 0, { 1185.566f, 1184.629f, -56.36329f,  2.3038310f }, { 0.f, 0.f,  0.9135447f, 0.40673840f }, RESPAWN_ONE_DAY },  // stables
    { 0, { 990.1131f, 1008.730f, -42.60328f,  0.8203033f }, { 0.f, 0.f,  0.3987484f, 0.91706040f }, RESPAWN_ONE_DAY },  // blacksmith
    { 0, { 818.0089f, 842.3543f, -56.54062f, -3.1066520f }, { 0.f, 0.f, -0.9998474f, 0.01746928f }, RESPAWN_ONE_DAY },  // farm
    { 0, { 808.8463f, 1185.417f,  11.92161f, -0.6632232f }, { 0.f, 0.f, -0.3255672f, 0.94551890f }, RESPAWN_ONE_DAY },  // lumber mill
    { 0, { 1147.091f, 816.8362f, -98.39896f, -0.2268925f }, { 0.f, 0.f, -0.1132030f, 0.99357190f }, RESPAWN_ONE_DAY }   // gold mine
};

// Tick intervals and given points: case 0, 1, 2, 3, 4, 5 captured nodes
uint32 const BG_AB_TickIntervals[BG_AB_DYNAMIC_NODES_COUNT + 1] = { 0, 12000, 9000, 6000, 3000, 1000 };
uint32 const BG_AB_TickPoints[BG_AB_DYNAMIC_NODES_COUNT + 1]    = { 0, 10, 10, 10, 10, 30 };

// WorldSafeLocs ids for 5 nodes, and for ally, and horde starting location
uint32 const BG_AB_GraveyardIds[BG_AB_ALL_NODES_COUNT] = { 895, 894, 893, 897, 896, 898, 899 };

Position const BG_AB_SpiritGuidePos[BG_AB_ALL_NODES_COUNT] =
{
    { 1200.03f, 1171.09f, -56.47f, 5.15f },                 // stables
    { 1017.43f, 960.610f, -42.95f, 4.88f },                 // blacksmith
    { 833.000f, 793.000f, -57.25f, 5.27f },                 // farm
    { 775.170f, 1206.40f,  15.79f, 1.90f },                 // lumber mill
    { 1207.48f, 787.000f, -83.36f, 5.51f },                 // gold mine
    { 1354.05f, 1275.48f, -11.30f, 4.77f },                 // alliance starting base
    { 714.610f, 646.150f, -10.87f, 4.34f }                  // horde starting base
};

BattlegroundAB::BattlegroundAB()
{
    m_IsInformedNearVictory = false;
    SetChangeBuffs(true, &buffEntries);

    SetGameObjectsNumber(BG_AB_OBJECT_MAX);
    SetCreaturesNumber(BG_AB_ALL_NODES_COUNT + BG_AB_DYNAMIC_NODES_COUNT); //+5 for aura triggers

    for (uint8 i = 0; i < BG_AB_DYNAMIC_NODES_COUNT; ++i)
    {
        m_Nodes[i] = BG_AB_NODE_TYPE_NEUTRAL;
        m_prevNodes[i] = BG_AB_NODE_TYPE_NEUTRAL;
        m_BannerTimers[i].type = 0;
        m_BannerTimers[i].teamIndex = TEAM_NEUTRAL;
    }

    for (uint8 i = 0; i < BG_TEAMS_COUNT; ++i)
    {
        m_lastTick[i] = 0;
        m_HonorScoreTics[i] = 0;
        m_ReputationScoreTics[i] = 0;
        m_TeamScores500Disadvantage[i] = false;
    }

    m_HonorTics = 0;
    m_ReputationTics = 0;

    StartMessageIds[BG_STARTING_EVENT_FIRST]  = LANG_BG_AB_START_TWO_MINUTES;
    StartMessageIds[BG_STARTING_EVENT_SECOND] = LANG_BG_AB_START_ONE_MINUTE;
    StartMessageIds[BG_STARTING_EVENT_THIRD]  = LANG_BG_AB_START_HALF_MINUTE;
    StartMessageIds[BG_STARTING_EVENT_FOURTH] = LANG_BG_AB_HAS_BEGUN;
}

BattlegroundAB::~BattlegroundAB() { }

void BattlegroundAB::PostUpdateImpl(uint32 diff)
{
    if (GetStatus() == STATUS_IN_PROGRESS)
    {
        m_Events.Update(diff);

        while (uint32 eventId = m_Events.ExecuteEvent())
        {
            switch (eventId)
            {
                // 2 sec delay to spawn new banner instead previous despawned one
                case EVENT_BANNER_UPDATE_0:
                case EVENT_BANNER_UPDATE_1:
                case EVENT_BANNER_UPDATE_2:
                case EVENT_BANNER_UPDATE_3:
                case EVENT_BANNER_UPDATE_4:
                {
                    uint8 const nodeId = eventId - EVENT_BANNER_UPDATE_0;

                    _CreateBanner(nodeId, m_BannerTimers[nodeId].type, m_BannerTimers[nodeId].teamIndex, false);
                    break;
                }
                // 1-minute to occupy a node from contested state
                case EVENT_NODE_CAPTURE_0:
                case EVENT_NODE_CAPTURE_1:
                case EVENT_NODE_CAPTURE_2:
                case EVENT_NODE_CAPTURE_3:
                case EVENT_NODE_CAPTURE_4:
                {
                    uint8 const nodeId = eventId - EVENT_NODE_CAPTURE_0;

                    // Change from contested to occupied !
                    TeamId teamIndex = TeamId(m_Nodes[nodeId] - BG_AB_NODE_TYPE_CONTESTED);
                    m_prevNodes[nodeId] = m_Nodes[nodeId];
                    m_Nodes[nodeId] = BG_AB_NodeStatus(m_Nodes[nodeId] + BG_AB_NODE_TYPE_OCCUPIED - BG_AB_NODE_TYPE_CONTESTED);

                    // burn current contested banner
                    _DelBanner(nodeId, BG_AB_NODE_TYPE_CONTESTED, teamIndex);

                    // create new occupied banner
                    _CreateBanner(nodeId, BG_AB_NODE_TYPE_OCCUPIED, teamIndex, true);
                    _SendNodeUpdate(nodeId);
                    _NodeOccupied(nodeId, teamIndex);

                    // Message to chatlog
                    if (teamIndex == TEAM_ALLIANCE)
                    {
                        // FIXME: team and node names not localized
                        SendMessage2ToAll(LANG_BG_AB_NODE_TAKEN, CHAT_MSG_BG_SYSTEM_ALLIANCE, nullptr, LANG_BG_AB_ALLY, _GetNodeNameId(nodeId));
                        PlaySoundToAll(BG_AB_SOUND_NODE_CAPTURED_ALLIANCE);
                    }
                    else
                    {
                        // FIXME: team and node names not localized
                        SendMessage2ToAll(LANG_BG_AB_NODE_TAKEN, CHAT_MSG_BG_SYSTEM_HORDE, nullptr, LANG_BG_AB_HORDE, _GetNodeNameId(nodeId));
                        PlaySoundToAll(BG_AB_SOUND_NODE_CAPTURED_HORDE);
                    }
                    break;
                }
            }
        }

        uint32 capturedNodes[BG_TEAMS_COUNT] = { 0, 0 };

        for (uint8 node = 0; node < BG_AB_DYNAMIC_NODES_COUNT; ++node)
        {
            for (uint8 teamIndex = TEAM_ALLIANCE; teamIndex < BG_TEAMS_COUNT; ++teamIndex)
                if (m_Nodes[node] == BG_AB_NODE_TYPE_OCCUPIED + teamIndex)
                    ++capturedNodes[teamIndex];
        }

        // Accumulate points
        for (uint8 team = 0; team < BG_TEAMS_COUNT; ++team)
        {
            uint32 teamNodes = capturedNodes[team];
            if (!teamNodes)
                continue;

            m_lastTick[team] += diff;

            if (m_lastTick[team] > BG_AB_TickIntervals[teamNodes])
            {
                m_lastTick[team] -= BG_AB_TickIntervals[teamNodes];
                m_TeamScores[team] += BG_AB_TickPoints[teamNodes];
                m_HonorScoreTics[team] += BG_AB_TickPoints[teamNodes];
                m_ReputationScoreTics[team] += BG_AB_TickPoints[teamNodes];

                if (m_ReputationScoreTics[team] >= m_ReputationTics)
                {
                    RewardReputationToTeam(509, 510, 10, team == ALLIANCE ? ALLIANCE : HORDE);
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
                        SendMessageToAll(LANG_BG_AB_A_NEAR_VICTORY, CHAT_MSG_BG_SYSTEM_NEUTRAL);
                    else
                        SendMessageToAll(LANG_BG_AB_H_NEAR_VICTORY, CHAT_MSG_BG_SYSTEM_NEUTRAL);
                    PlaySoundToAll(BG_AB_SOUND_NEAR_VICTORY);
                    m_IsInformedNearVictory = true;
                }

                if (m_TeamScores[team] > BG_AB_MAX_TEAM_SCORE)
                    m_TeamScores[team] = BG_AB_MAX_TEAM_SCORE;

                if (team == TEAM_ALLIANCE)
                    UpdateWorldState(BG_AB_OP_RESOURCES_ALLY, m_TeamScores[team]);
                else if (team == TEAM_HORDE)
                    UpdateWorldState(BG_AB_OP_RESOURCES_HORDE, m_TeamScores[team]);
                // update achievement flags
                // we increased m_TeamScores[team] so we just need to check if it is 500 more than other teams resources
                uint8 otherTeam = (team + 1) % BG_TEAMS_COUNT;
                if (m_TeamScores[team] > m_TeamScores[otherTeam] + 500)
                    m_TeamScores500Disadvantage[otherTeam] = true;
            }
        }

        // Test win condition
        if (m_TeamScores[TEAM_ALLIANCE] >= BG_AB_MAX_TEAM_SCORE)
            EndBattleground(ALLIANCE);
        else if (m_TeamScores[TEAM_HORDE] >= BG_AB_MAX_TEAM_SCORE)
            EndBattleground(HORDE);
    }
}

void BattlegroundAB::StartingEventCloseDoors()
{
    // despawn banners, auras and buffs
    for (uint32 obj = BG_AB_OBJECT_BANNER_NEUTRAL; obj < BG_AB_DYNAMIC_NODES_COUNT * BG_AB_DYNAMIC_NODE_GO_COUNT; ++obj)
        SpawnBGObject(obj, RESPAWN_ONE_DAY);
    for (uint32 i = 0; i < BG_AB_DYNAMIC_NODES_COUNT * BG_MAX_BUFFS; ++i)
        SpawnBGObject(BG_AB_OBJECT_BUFF_FIRST + i, RESPAWN_ONE_DAY);

    // Starting doors
    for (uint32 door = BG_AB_OBJECT_GATE_A; door <= BG_AB_OBJECT_GATE_H; ++door)
    {
        DoorClose(door);
        SpawnBGObject(door, RESPAWN_IMMEDIATELY);
    }

    // Starting base spirit guides
    _NodeOccupied(BG_AB_SPIRIT_ALIANCE, TEAM_ALLIANCE);
    _NodeOccupied(BG_AB_SPIRIT_HORDE, TEAM_HORDE);
}

void BattlegroundAB::StartingEventOpenDoors()
{
    // spawn neutral banners
    for (uint32 banner = BG_AB_OBJECT_BANNER_NEUTRAL, i = 0; i < BG_AB_DYNAMIC_NODES_COUNT; banner += BG_AB_DYNAMIC_NODE_GO_COUNT, ++i)
        SpawnBGObject(banner, RESPAWN_IMMEDIATELY);
    for (uint32 i = 0; i < BG_AB_DYNAMIC_NODES_COUNT; ++i)
    {
        //randomly select buff to spawn
        uint8 buff = urand(0, BG_MAX_BUFFS - 1);
        SpawnBGObject(BG_AB_OBJECT_BUFF_FIRST + buff + i * BG_MAX_BUFFS, RESPAWN_IMMEDIATELY);
    }

    for (uint32 door = BG_AB_OBJECT_GATE_A; door <= BG_AB_OBJECT_GATE_H; ++door)
        DoorOpen(door);

    // Achievement: Let's Get This Done
    StartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, AB_EVENT_START_BATTLE);
}

void BattlegroundAB::AddPlayer(Player* player)
{
    Battleground::AddPlayer(player);
    PlayerScores[player->GetGUID().GetCounter()] = new BattlegroundABScore(player->GetGUID());
}

void BattlegroundAB::RemovePlayer(Player* /*player*/, ObjectGuid /*guid*/, uint32 /*team*/)
{
}

void BattlegroundAB::HandleAreaTrigger(Player* player, uint32 trigger)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    switch (trigger)
    {
        case 3948:                                          // Arathi Basin Alliance Exit.
            if (player->GetTeam() != ALLIANCE)
                player->GetSession()->SendAreaTriggerMessage("Only The Alliance can use that portal");
            else
                player->LeaveBattleground();
            break;
        case 3949:                                          // Arathi Basin Horde Exit.
            if (player->GetTeam() != HORDE)
                player->GetSession()->SendAreaTriggerMessage("Only The Horde can use that portal");
            else
                player->LeaveBattleground();
            break;
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
            Battleground::HandleAreaTrigger(player, trigger);
            break;
    }
}

/*  type: 0-neutral, 1-contested, 3-occupied
    teamIndex: 0-ally, 1-horde                        */
void BattlegroundAB::_CreateBanner(uint8 node, uint8 type, TeamId teamIndex, bool delay)
{
    // Just put it into the queue
    if (delay)
    {
        m_BannerTimers[node].type = type;
        m_BannerTimers[node].teamIndex = teamIndex;

        m_Events.ScheduleEvent(EVENT_BANNER_UPDATE_0 + node, Seconds(2));
        return;
    }

    uint8 obj = node * BG_AB_DYNAMIC_NODE_GO_COUNT + type + teamIndex;

    SpawnBGObject(obj, RESPAWN_IMMEDIATELY);

    // handle aura with banner
    if (!type)
        return;

    obj = node * BG_AB_DYNAMIC_NODE_GO_COUNT + ((type == BG_AB_NODE_TYPE_OCCUPIED) ? (BG_AB_OBJECT_AURA_ALLY + teamIndex) : BG_AB_OBJECT_AURA_CONTESTED);
    SpawnBGObject(obj, RESPAWN_IMMEDIATELY);
}

void BattlegroundAB::_DelBanner(uint8 node, uint8 type, TeamId teamIndex)
{
    uint8 obj = node * BG_AB_DYNAMIC_NODE_GO_COUNT + type + teamIndex;
    SpawnBGObject(obj, RESPAWN_ONE_DAY);

    // handle aura with banner
    if (!type)
        return;

    obj = node * BG_AB_DYNAMIC_NODE_GO_COUNT + ((type == BG_AB_NODE_TYPE_OCCUPIED) ? (BG_AB_OBJECT_AURA_ALLY + teamIndex) : BG_AB_OBJECT_AURA_CONTESTED);
    SpawnBGObject(obj, RESPAWN_ONE_DAY);
}

int32 BattlegroundAB::_GetNodeNameId(uint8 node)
{
    switch (node)
    {
        case BG_AB_NODE_STABLES:    return LANG_BG_AB_NODE_STABLES;
        case BG_AB_NODE_BLACKSMITH: return LANG_BG_AB_NODE_BLACKSMITH;
        case BG_AB_NODE_FARM:       return LANG_BG_AB_NODE_FARM;
        case BG_AB_NODE_LUMBER_MILL:return LANG_BG_AB_NODE_LUMBER_MILL;
        case BG_AB_NODE_GOLD_MINE:  return LANG_BG_AB_NODE_GOLD_MINE;
        default:
            ABORT();
    }
    return 0;
}

void BattlegroundAB::FillInitialWorldStates(WorldPacket& data)
{
    static uint8 const plusArray[BG_AB_DYNAMIC_NODES_COUNT] = { 0, 2, 3, 0, 1 };

    // Node icons
    for (uint8 node = 0; node < BG_AB_DYNAMIC_NODES_COUNT; ++node)
        data << uint32(BG_AB_OP_NODEICONS[node]) << uint32((m_Nodes[node] == 0)?1:0);

    // Node occupied states
    for (uint8 node = 0; node < BG_AB_DYNAMIC_NODES_COUNT; ++node)
        for (uint8 i = 1; i < BG_AB_DYNAMIC_NODES_COUNT; ++i)
            data << uint32(BG_AB_OP_NODESTATES[node] + plusArray[i]) << uint32((m_Nodes[node] == i) ? 1 : 0);

    // How many bases each team owns
    uint8 ally = 0, horde = 0;
    for (uint8 node = 0; node < BG_AB_DYNAMIC_NODES_COUNT; ++node)
        if (m_Nodes[node] == BG_AB_NODE_STATUS_ALLY_OCCUPIED)
            ++ally;
        else if (m_Nodes[node] == BG_AB_NODE_STATUS_HORDE_OCCUPIED)
            ++horde;

    data << uint32(BG_AB_OP_OCCUPIED_BASES_ALLY)  << uint32(ally);
    data << uint32(BG_AB_OP_OCCUPIED_BASES_HORDE) << uint32(horde);

    // Team scores
    data << uint32(BG_AB_OP_RESOURCES_MAX)      << uint32(BG_AB_MAX_TEAM_SCORE);
    data << uint32(BG_AB_OP_RESOURCES_WARNING)  << uint32(BG_AB_WARNING_NEAR_VICTORY_SCORE);
    data << uint32(BG_AB_OP_RESOURCES_ALLY)     << uint32(m_TeamScores[TEAM_ALLIANCE]);
    data << uint32(BG_AB_OP_RESOURCES_HORDE)    << uint32(m_TeamScores[TEAM_HORDE]);

    // other unknown
    data << uint32(0x745) << uint32(0x2);           // 37 1861 unk
}

void BattlegroundAB::_SendNodeUpdate(uint8 node)
{
    // Send node owner state update to refresh map icons on client
    static uint8 const plusArray[BG_AB_DYNAMIC_NODES_COUNT] = { 0, 2, 3, 0, 1 };

    if (m_prevNodes[node])
        UpdateWorldState(BG_AB_OP_NODESTATES[node] + plusArray[m_prevNodes[node]], 0);
    else
        UpdateWorldState(BG_AB_OP_NODEICONS[node], 0);

    UpdateWorldState(BG_AB_OP_NODESTATES[node] + plusArray[m_Nodes[node]], 1);

    // How many bases each team owns
    uint8 ally = 0, horde = 0;
    for (uint8 i = 0; i < BG_AB_DYNAMIC_NODES_COUNT; ++i)
    {
        if (m_Nodes[i] == BG_AB_NODE_STATUS_ALLY_OCCUPIED)
            ++ally;
        else if (m_Nodes[i] == BG_AB_NODE_STATUS_HORDE_OCCUPIED)
            ++horde;
    }

    UpdateWorldState(BG_AB_OP_OCCUPIED_BASES_ALLY, ally);
    UpdateWorldState(BG_AB_OP_OCCUPIED_BASES_HORDE, horde);
}

void BattlegroundAB::_NodeOccupied(uint8 node, TeamId teamIndex)
{
    if (!AddSpiritGuide(node, BG_AB_SpiritGuidePos[node], teamIndex))
        TC_LOG_ERROR("bg.battleground", "Failed to spawn spirit guide! point: %u, teamId: %u, ", node, teamIndex);

    if (node >= BG_AB_DYNAMIC_NODES_COUNT) //only dynamic nodes, no start points
        return;

    uint8 capturedNodes = 0;
    for (uint8 i = 0; i < BG_AB_DYNAMIC_NODES_COUNT; ++i)
        if (m_Nodes[i] == BG_AB_NODE_TYPE_OCCUPIED + teamIndex)
            ++capturedNodes;

    if (capturedNodes >= BG_AB_DYNAMIC_NODES_COUNT)
        CastSpellOnTeam(SPELL_AB_QUEST_REWARD_5_BASES, teamIndex == TEAM_ALLIANCE ? ALLIANCE : HORDE);

    if (capturedNodes >= 4)
        CastSpellOnTeam(SPELL_AB_QUEST_REWARD_4_BASES, teamIndex == TEAM_ALLIANCE ? ALLIANCE : HORDE);

    Creature* trigger = GetBGCreature(node + BG_AB_ALL_NODES_COUNT, false); // 0-6 spirit guides
    if (!trigger)
        trigger = AddCreature(WORLD_TRIGGER, node + BG_AB_ALL_NODES_COUNT, BG_AB_NodePositions[node].Pos);

    if (!trigger)
        return;

    //add bonus honor aura trigger creature when node is accupied
    //cast bonus aura (+50% honor in 25yards)
    //aura should only apply to players who have accupied the node, set correct faction for trigger
    trigger->setFaction(teamIndex == TEAM_ALLIANCE ? 84 : 83);
    trigger->CastSpell(trigger, SPELL_HONORABLE_DEFENDER_25Y, false);
}

void BattlegroundAB::_NodeDeOccupied(uint8 node)
{
    if (node >= BG_AB_DYNAMIC_NODES_COUNT)
        return;

    //remove bonus honor aura trigger creature when node is lost
    if (node < BG_AB_DYNAMIC_NODES_COUNT) //only dynamic nodes, no start points
        DelCreature(node + BG_AB_ALL_NODES_COUNT); //NULL checks are in DelCreature! 0-6 spirit guides

    if (Creature* spiritGuide = GetBGCreature(node, false))
        RelocateDeadPlayers(spiritGuide->GetGUID());

    DelCreature(node);

    // buff object isn't despawned
}

/* Invoked if a player used a banner as a gameobject */
void BattlegroundAB::EventPlayerClickedOnFlag(Player* source, GameObject* /*target_obj*/)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    uint8 node = BG_AB_NODE_STABLES;
    GameObject* obj = GetBGObject(node * BG_AB_DYNAMIC_NODE_GO_COUNT + BG_AB_OBJECT_AURA_CONTESTED);
    while ((node < BG_AB_DYNAMIC_NODES_COUNT) && ((!obj) || (!source->IsWithinDistInMap(obj, 10.f))))
    {
        ++node;
        obj = GetBGObject(node * BG_AB_DYNAMIC_NODE_GO_COUNT + BG_AB_OBJECT_AURA_CONTESTED);
    }

    if (node == BG_AB_DYNAMIC_NODES_COUNT)
    {
        // this means our player isn't close to any of banners - maybe cheater ??
        return;
    }

    TeamId teamIndex = GetTeamIndexByTeamId(source->GetTeam());

    // Check if player really could use this banner, not cheated
    if (!(m_Nodes[node] == 0 || teamIndex == m_Nodes[node] % BG_TEAMS_COUNT))
        return;

    source->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_ENTER_PVP_COMBAT);
    uint32 sound = 0;
    // If node is neutral, change to contested
    if (m_Nodes[node] == BG_AB_NODE_TYPE_NEUTRAL)
    {
        UpdatePlayerScore(source, SCORE_BASES_ASSAULTED, 1);
        m_prevNodes[node] = m_Nodes[node];
        m_Nodes[node] = BG_AB_NodeStatus(BG_AB_NODE_TYPE_CONTESTED + teamIndex);
        // burn current neutral banner
        _DelBanner(node, BG_AB_NODE_TYPE_NEUTRAL, TeamId(0));
        // create new contested banner
        _CreateBanner(node, BG_AB_NODE_TYPE_CONTESTED, teamIndex, true);
        _SendNodeUpdate(node);
        m_Events.ScheduleEvent(EVENT_NODE_CAPTURE_0 + node, BG_AB_FLAG_CAPTURING_TIME);

        // FIXME: team and node names not localized
        if (teamIndex == TEAM_ALLIANCE)
            SendMessage2ToAll(LANG_BG_AB_NODE_CLAIMED, CHAT_MSG_BG_SYSTEM_ALLIANCE, source, _GetNodeNameId(node), LANG_BG_AB_ALLY);
        else
            SendMessage2ToAll(LANG_BG_AB_NODE_CLAIMED, CHAT_MSG_BG_SYSTEM_HORDE, source, _GetNodeNameId(node), LANG_BG_AB_HORDE);

        sound = BG_AB_SOUND_NODE_CLAIMED;
    }
    // If node is contested
    else if ((m_Nodes[node] == BG_AB_NODE_STATUS_ALLY_CONTESTED) || (m_Nodes[node] == BG_AB_NODE_STATUS_HORDE_CONTESTED))
    {
        // If last state is NOT occupied, change node to enemy-contested
        if (m_prevNodes[node] < BG_AB_NODE_TYPE_OCCUPIED)
        {
            UpdatePlayerScore(source, SCORE_BASES_ASSAULTED, 1);
            m_prevNodes[node] = m_Nodes[node];
            m_Nodes[node] = BG_AB_NodeStatus(BG_AB_NODE_TYPE_CONTESTED + teamIndex);
            // burn current contested banner
            _DelBanner(node, BG_AB_NODE_TYPE_CONTESTED, teamIndex == TEAM_ALLIANCE ? TEAM_HORDE : TEAM_ALLIANCE);
            // create new contested banner
            _CreateBanner(node, BG_AB_NODE_TYPE_CONTESTED, teamIndex, true);
            _SendNodeUpdate(node);
            m_Events.RescheduleEvent(EVENT_NODE_CAPTURE_0 + node, BG_AB_FLAG_CAPTURING_TIME);

            // FIXME: node names not localized
            if (teamIndex == TEAM_ALLIANCE)
                SendMessage2ToAll(LANG_BG_AB_NODE_ASSAULTED, CHAT_MSG_BG_SYSTEM_ALLIANCE, source, _GetNodeNameId(node));
            else
                SendMessage2ToAll(LANG_BG_AB_NODE_ASSAULTED, CHAT_MSG_BG_SYSTEM_HORDE, source, _GetNodeNameId(node));
        }
        // If contested, change back to occupied
        else
        {
            UpdatePlayerScore(source, SCORE_BASES_DEFENDED, 1);
            m_prevNodes[node] = m_Nodes[node];
            m_Nodes[node] = BG_AB_NodeStatus(BG_AB_NODE_TYPE_OCCUPIED + teamIndex);
            // burn current contested banner
            _DelBanner(node, BG_AB_NODE_TYPE_CONTESTED, teamIndex == TEAM_ALLIANCE ? TEAM_HORDE : TEAM_ALLIANCE);
            // create new occupied banner
            _CreateBanner(node, BG_AB_NODE_TYPE_OCCUPIED, teamIndex, true);
            _SendNodeUpdate(node);
            m_Events.CancelEvent(EVENT_NODE_CAPTURE_0 + node);

            _NodeOccupied(node, teamIndex);

            // FIXME: node names not localized
            if (teamIndex == TEAM_ALLIANCE)
                SendMessage2ToAll(LANG_BG_AB_NODE_DEFENDED, CHAT_MSG_BG_SYSTEM_ALLIANCE, source, _GetNodeNameId(node));
            else
                SendMessage2ToAll(LANG_BG_AB_NODE_DEFENDED, CHAT_MSG_BG_SYSTEM_HORDE, source, _GetNodeNameId(node));
        }
        sound = (teamIndex == TEAM_ALLIANCE) ? BG_AB_SOUND_NODE_ASSAULTED_ALLIANCE : BG_AB_SOUND_NODE_ASSAULTED_HORDE;
    }
    // If node is occupied, change to enemy-contested
    else
    {
        UpdatePlayerScore(source, SCORE_BASES_ASSAULTED, 1);
        m_prevNodes[node] = m_Nodes[node];
        m_Nodes[node] = BG_AB_NodeStatus(BG_AB_NODE_TYPE_CONTESTED + teamIndex);
        // burn current occupied banner
        _DelBanner(node, BG_AB_NODE_TYPE_OCCUPIED, teamIndex == TEAM_ALLIANCE ? TEAM_HORDE : TEAM_ALLIANCE);
        // create new contested banner
        _CreateBanner(node, BG_AB_NODE_TYPE_CONTESTED, teamIndex, true);
        _SendNodeUpdate(node);
        _NodeDeOccupied(node);
        m_Events.ScheduleEvent(EVENT_NODE_CAPTURE_0 + node, BG_AB_FLAG_CAPTURING_TIME);

        // FIXME: node names not localized
        if (teamIndex == TEAM_ALLIANCE)
            SendMessage2ToAll(LANG_BG_AB_NODE_ASSAULTED, CHAT_MSG_BG_SYSTEM_ALLIANCE, source, _GetNodeNameId(node));
        else
            SendMessage2ToAll(LANG_BG_AB_NODE_ASSAULTED, CHAT_MSG_BG_SYSTEM_HORDE, source, _GetNodeNameId(node));

        sound = (teamIndex == TEAM_ALLIANCE) ? BG_AB_SOUND_NODE_ASSAULTED_ALLIANCE : BG_AB_SOUND_NODE_ASSAULTED_HORDE;
    }

    // If node is occupied again, send "X has taken the Y" msg.
    if (m_Nodes[node] >= BG_AB_NODE_TYPE_OCCUPIED)
    {
        // FIXME: team and node names not localized
        if (teamIndex == TEAM_ALLIANCE)
            SendMessage2ToAll(LANG_BG_AB_NODE_TAKEN, CHAT_MSG_BG_SYSTEM_ALLIANCE, nullptr, LANG_BG_AB_ALLY, _GetNodeNameId(node));
        else
            SendMessage2ToAll(LANG_BG_AB_NODE_TAKEN, CHAT_MSG_BG_SYSTEM_HORDE, nullptr, LANG_BG_AB_HORDE, _GetNodeNameId(node));
    }
    PlaySoundToAll(sound);
}

uint32 BattlegroundAB::GetPrematureWinner()
{
    // How many bases each team owns
    uint8 ally = 0, horde = 0;
    for (uint8 i = 0; i < BG_AB_DYNAMIC_NODES_COUNT; ++i)
        if (m_Nodes[i] == BG_AB_NODE_STATUS_ALLY_OCCUPIED)
            ++ally;
        else if (m_Nodes[i] == BG_AB_NODE_STATUS_HORDE_OCCUPIED)
            ++horde;

    if (ally > horde)
        return ALLIANCE;
    else if (horde > ally)
        return HORDE;

    // If the values are equal, fall back to the original result (based on number of players on each team)
    return Battleground::GetPrematureWinner();
}

bool BattlegroundAB::SetupBattleground()
{
    for (uint32 i = 0; i < BG_AB_DYNAMIC_NODES_COUNT * BG_AB_DYNAMIC_NODE_GO_COUNT; ++i)
    {
        uint32 const nodeID = i / BG_AB_DYNAMIC_NODE_GO_COUNT;
        uint32 const objID  = i % BG_AB_DYNAMIC_NODE_GO_COUNT;

        uint32 entry = BG_AB_NodeGameObject[objID];
        if (objID == 0) // new node
            entry += nodeID;

        BattlegroundGOSpawnPoint const& nodeSpawn = BG_AB_NodePositions[nodeID];
        if (!AddObject(BG_AB_OBJECT_FIRST + i, entry, nodeSpawn.Pos, nodeSpawn.Rot, nodeSpawn.SpawnTime))
        {
            TC_LOG_ERROR("bg.battleground", "BattleGroundAB: Failed to spawn GameObject! (Entry: %u)", entry);
            return false;
        }
    }

    for (uint32 i = 0; i < BG_TEAMS_COUNT; ++i)
    {
        BattlegroundGOSpawnPoint const& door = BattlegroundABDoors[i];
        if (!AddObject(BG_AB_OBJECT_GATE_A + i, door.Entry, door.Pos, door.Rot, door.SpawnTime))
        {
            TC_LOG_ERROR("bg.battleground", "BattleGroundAB: Failed to spawn door object (Entry: %u). Battleground not created!", door.Entry);
            return false;
        }
    }

    //buffs
    for (uint32 i = 0; i < BG_AB_DYNAMIC_NODES_COUNT * BG_MAX_BUFFS; ++i)
    {
        uint32 const nodeID = i / BG_MAX_BUFFS;
        uint32 const objId  = i % BG_MAX_BUFFS;

        uint32 entry = BG_AB_BuffEntries[objId];

        BattlegroundGOSpawnPoint const& nodeBuff = BG_AB_BuffPositions[nodeID];
        if (!AddObject(BG_AB_OBJECT_BUFF_FIRST + i, entry, nodeBuff.Pos, nodeBuff.Rot, nodeBuff.SpawnTime))
        {
            TC_LOG_ERROR("bg.battleground", "BattleGroundAB: Failed to spawn buff object (Entry: %u). Battleground not created!", entry);
            return false;
        }
    }

    return true;
}

void BattlegroundAB::Reset()
{
    //call parent's class reset
    Battleground::Reset();

    m_IsInformedNearVictory                 = false;
    bool isBGWeekend = sBattlegroundMgr->IsBGWeekend(GetTypeID());
    m_HonorTics = (isBGWeekend) ? BG_AB_ABBGWeekendHonorTicks : BG_AB_NotABBGWeekendHonorTicks;
    m_ReputationTics = (isBGWeekend) ? BG_AB_ABBGWeekendReputationTicks : BG_AB_NotABBGWeekendReputationTicks;
    m_Events.Reset();

    for (uint8 i = 0; i < BG_AB_DYNAMIC_NODES_COUNT; ++i)
    {
        m_Nodes[i] = BG_AB_NODE_TYPE_NEUTRAL;
        m_prevNodes[i] = BG_AB_NODE_TYPE_NEUTRAL;
    }

    for (uint8 i = 0; i < BG_TEAMS_COUNT; ++i)
    {
        m_TeamScores[i] = 0;
        m_lastTick[i] = 0;
        m_HonorScoreTics[i] = 0;
        m_ReputationScoreTics[i] = 0;
        m_TeamScores500Disadvantage[i] = false;
    }

    for (uint8 i = 0; i < BG_AB_ALL_NODES_COUNT + BG_AB_DYNAMIC_NODES_COUNT; ++i) // +5 for aura triggers
        DelCreature(i);
}

void BattlegroundAB::EndBattleground(uint32 winner)
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

WorldSafeLocsEntry const* BattlegroundAB::GetClosestGraveYard(Player* player)
{
    TeamId teamIndex = player->GetTeamId();

    // Is there any occupied node for this team?
    std::vector<uint8> nodes;
    nodes.reserve(BG_AB_DYNAMIC_NODES_COUNT);

    for (uint8 i = 0; i < BG_AB_DYNAMIC_NODES_COUNT; ++i)
        if (m_Nodes[i] == teamIndex + BG_AB_NODE_TYPE_OCCUPIED)
            nodes.push_back(i);

    WorldSafeLocsEntry const* good_entry = nullptr;
    // If so, select the closest node to place ghost on
    if (!nodes.empty())
    {
        float plr_x, plr_y;
        player->GetPosition(plr_x, plr_y);

        float minDistSq = 999999.0f;
        for (uint8 node : nodes)
        {
            WorldSafeLocsEntry const* entry = sWorldSafeLocsStore.LookupEntry(BG_AB_GraveyardIds[node]);
            if (!entry)
                continue;

            float distSq = (entry->x - plr_x) * (entry->x - plr_x) + (entry->y - plr_y) * (entry->y - plr_y);
            if (minDistSq > distSq)
            {
                minDistSq = distSq;
                good_entry = entry;
            }
        }
    }

    // If not, place ghost on starting location
    if (!good_entry)
        good_entry = sWorldSafeLocsStore.LookupEntry(BG_AB_GraveyardIds[BG_AB_SPIRIT_ALIANCE + teamIndex]);

    return good_entry;
}

bool BattlegroundAB::UpdatePlayerScore(Player* player, uint32 type, uint32 value, bool doAddHonor)
{
    if (!Battleground::UpdatePlayerScore(player, type, value, doAddHonor))
        return false;

    switch (type)
    {
        case SCORE_BASES_ASSAULTED:
            player->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BG_OBJECTIVE_CAPTURE, AB_OBJECTIVE_ASSAULT_BASE);
            break;
        case SCORE_BASES_DEFENDED:
            player->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BG_OBJECTIVE_CAPTURE, AB_OBJECTIVE_DEFEND_BASE);
            break;
        default:
            break;
    }
    return true;
}

bool BattlegroundAB::IsAllNodesControlledByTeam(uint32 team) const
{
    for (uint8 i = 0; i < BG_AB_DYNAMIC_NODES_COUNT; ++i)
        if (m_Nodes[i] != BG_AB_NODE_TYPE_OCCUPIED + GetTeamIndexByTeamId(team))
            return false;

    return true;
}

bool BattlegroundAB::CheckAchievementCriteriaMeet(uint32 criteriaId, Player const* player, Unit const* target, uint32 miscvalue)
{
    switch (criteriaId)
    {
        case BG_CRITERIA_CHECK_RESILIENT_VICTORY:
            return m_TeamScores500Disadvantage[GetTeamIndexByTeamId(player->GetTeam())];
    }

    return Battleground::CheckAchievementCriteriaMeet(criteriaId, player, target, miscvalue);
}