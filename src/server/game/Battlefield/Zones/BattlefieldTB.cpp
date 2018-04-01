/*
* Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

// TO-DO:
//  - Implement proper support for vehicles (Player::VehicleSpellInitialize())
//     - Siege Engine Turret (45564) crashing server (Auras: Unknown Shapeshift Type: 24)
//  - Graveyard spirit phasing, ressurection, Spiritual Immunity aura for players nearby
//  - Warn and teleport players out of the Baradin Hold instance (need sniffs; spell 94964?)
//  - Not sure, but players should probably be able to ressurect from guide spirits when there's no battle
//  - Check and script achievements

#include "BattlefieldTB.h"
#include "AchievementMgr.h"
#include "Battleground.h"
#include "CreatureTextMgr.h"
#include "GameObject.h"
#include "MapManager.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "Random.h"
#include "SpellAuras.h"
#include "TemporarySummon.h"
#include "World.h"
#include "WorldStatePackets.h"

BattlefieldTB::~BattlefieldTB() { }

bool BattlefieldTB::SetupBattlefield()
{
    m_TypeId = BATTLEFIELD_TB;                              // See enum BattlefieldTypes
    m_BattleId = BATTLEFIELD_BATTLEID_TB;
    m_ZoneId = BATTLEFIELD_TB_ZONEID;
    m_MapId = BATTLEFIELD_TB_MAPID;
    m_Map = sMapMgr->CreateBaseMap(m_MapId);

    InitStalker(NPC_DEBUG_ANNOUNCER, TolBaradDebugAnnouncerPos);

    m_MaxPlayer = sWorld->getIntConfig(CONFIG_TOLBARAD_PLR_MAX);
    m_IsEnabled = sWorld->getBoolConfig(CONFIG_TOLBARAD_ENABLE);
    m_MinPlayer = sWorld->getIntConfig(CONFIG_TOLBARAD_PLR_MIN);
    m_MinLevel = sWorld->getIntConfig(CONFIG_TOLBARAD_PLR_MIN_LVL);
    m_BattleTime = sWorld->getIntConfig(CONFIG_TOLBARAD_BATTLETIME) * MINUTE * IN_MILLISECONDS;
    m_BonusTime = sWorld->getIntConfig(CONFIG_TOLBARAD_BONUSTIME) * MINUTE * IN_MILLISECONDS;
    m_NoWarBattleTime = sWorld->getIntConfig(CONFIG_TOLBARAD_NOBATTLETIME) * MINUTE * IN_MILLISECONDS;
    m_RestartAfterCrash = sWorld->getIntConfig(CONFIG_TOLBARAD_RESTART_AFTER_CRASH) * MINUTE * IN_MILLISECONDS;

    m_TimeForAcceptInvite = 20;
    m_StartGroupingTimer = 15 * MINUTE * IN_MILLISECONDS;
    m_StartGrouping = false;
    m_isActive = false;

    KickPosition.Relocate(-605.5f, 1181.31f, 95.96f, 6.177155f);
    KickPosition.m_mapId = m_MapId;

    RegisterZone(m_ZoneId);

    m_Data32.resize(BATTLEFIELD_TB_DATA_MAX);

    m_saveTimer = 5 * MINUTE * IN_MILLISECONDS;

    updatedNPCAndObjects = true;
    m_updateObjectsTimer = 0;

    // Was there a battle going on or time isn't set yet? Then use m_RestartAfterCrash
    if (sWorld->getWorldState(TB_WS_STATE_BATTLE) == 1 || sWorld->getWorldState(TB_WS_TIME_NEXT_BATTLE) == 0)
        sWorld->setWorldState(TB_WS_TIME_NEXT_BATTLE, m_RestartAfterCrash);

    // Set timer
    m_Timer = sWorld->getWorldState(TB_WS_TIME_NEXT_BATTLE);

    // Defending team isn't set yet? Choose randomly.
    if (sWorld->getWorldState(TB_WS_FACTION_CONTROLLING) == 0)
        sWorld->setWorldState(TB_WS_FACTION_CONTROLLING, uint32(urand(1, 2)));

    // Set defender team
    SetDefenderTeam(TeamId(sWorld->getWorldState(TB_WS_FACTION_CONTROLLING) - 1));

    // Just to save world states
    SendInitWorldStatesToAll();

    // Create capture points
    for (uint8 i = 0; i < TB_BASE_COUNT; i++)
    {
        TolBaradCapturePoint* capturePoint = new TolBaradCapturePoint(this, GetDefenderTeam());

        //Spawn flag pole
        if (GameObject* go = SpawnGameObject(TBCapturePoints[i].entryFlagPole[GetDefenderTeam()], TBCapturePoints[i].pos, QuaternionData()))
        {
            go->SetGoArtKit(GetDefenderTeam() == TEAM_ALLIANCE ? TB_GO_ARTKIT_FLAG_ALLIANCE : TB_GO_ARTKIT_FLAG_HORDE);
            capturePoint->SetCapturePointData(go);
        }
        AddCapturePoint(capturePoint);
    }

    // Spawn towers
    for (uint8 i = 0; i < TB_TOWERS_COUNT; i++)
        if (GameObject* go = SpawnGameObject(TBTowers[i].entry, TBTowers[i].pos, QuaternionData()))
            Towers.insert(go->GetGUID());

    // Init Graveyards
    SetGraveyardNumber(BATTLEFIELD_TB_GRAVEYARD_MAX);

    // Graveyards
    for (uint8 i = 0; i < BATTLEFIELD_TB_GRAVEYARD_MAX; i++)
    {
        BfGraveyard* graveyard = new BfGraveyard(this);

        // When between games, the graveyard is controlled by the defending team
        graveyard->Initialize(GetDefenderTeam(), TBGraveyards[i].gyid);

        // Spawn spirits
        for (uint8 team = 0; team < 2; team++)
            if (Creature* creature = SpawnCreature(TBGraveyards[i].spiritEntry[team], TBGraveyards[i].pos))
                graveyard->SetSpirit(creature, TeamId(team));

        m_GraveyardList[i] = graveyard;
    }

    // Time warning vars
    warnedFiveMinutes = false;
    warnedTwoMinutes = false;
    warnedOneMinute = false;

    UpdateNPCsAndGameObjects();

    return true;
}

bool BattlefieldTB::Update(uint32 diff)
{
    bool m_return = Battlefield::Update(diff);

    // Minutes till battle preparation warnings
    if (GetState() == BATTLEFIELD_INACTIVE)
    {
        if (m_Timer <= 5 * MINUTE * IN_MILLISECONDS + m_StartGroupingTimer && !warnedFiveMinutes)
        {
            warnedFiveMinutes = true;
            SendWarning(TB_TEXT_PREPARATIONS_IN_5_MIN);
        }

        if (m_Timer <= 2 * MINUTE * IN_MILLISECONDS + m_StartGroupingTimer && !warnedTwoMinutes)
        {
            warnedTwoMinutes = true;
            SendWarning(TB_TEXT_PREPARATIONS_IN_2_MIN);
        }

        if (m_Timer <= 1 * MINUTE * IN_MILLISECONDS + m_StartGroupingTimer && !warnedOneMinute)
        {
            warnedOneMinute = true;
            SendWarning(TB_TEXT_PREPARATIONS_IN_1_MIN);
        }
    }

    if (!updatedNPCAndObjects)
    {
        if (m_updateObjectsTimer <= diff)
        {
            UpdateNPCsAndGameObjects();
            updatedNPCAndObjects = true;
        }
        else
            m_updateObjectsTimer -= diff;
    }

    if (m_saveTimer <= diff)
    {
        if (!IsWarTime())
            sWorld->setWorldState(TB_WS_TIME_NEXT_BATTLE, m_Timer);
        m_saveTimer = 60 * IN_MILLISECONDS;
    }
    else
        m_saveTimer -= diff;

    return m_return;
}

void BattlefieldTB::OnPlayerEnterZone(Player* player)
{
    if (!m_isActive)
        RemoveAurasFromPlayer(player);

    SendInitWorldStatesTo(player);
}

void BattlefieldTB::OnPlayerLeaveZone(Player* player)
{
    if (!m_isActive)
        RemoveAurasFromPlayer(player);
}

void BattlefieldTB::OnPlayerJoinWar(Player* player)
{
    RemoveAurasFromPlayer(player);

    player->SetPvP(true);

    // Bonus damage buff for attackers
    if (player->GetTeamId() == GetAttackerTeam() && GetData(BATTLEFIELD_TB_DATA_TOWERS_DESTROYED) > 0)
        player->CastCustomSpell(SPELL_TOWER_ATTACK_BONUS, SPELLVALUE_AURA_STACK, GetData(BATTLEFIELD_TB_DATA_TOWERS_DESTROYED), player, TRIGGERED_FULL_MASK);
}


void BattlefieldTB::OnPlayerLeaveWar(Player* player)
{
    RemoveAurasFromPlayer(player);
}

void BattlefieldTB::RemoveAurasFromPlayer(Player* player)
{
    player->RemoveAurasDueToSpell(SPELL_TB_SLOW_FALL);
    player->RemoveAurasDueToSpell(SPELL_TB_VETERAN);
    player->RemoveAurasDueToSpell(SPELL_TOWER_ATTACK_BONUS);
    player->RemoveAurasDueToSpell(SPELL_TB_SPIRITUAL_IMMUNITY);
}

// 62 fields, [7]-[68]
void BattlefieldTB::FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& packet)
{
    packet.Worldstates.emplace_back(uint32(TB_WS_ALLIANCE_ATTACKING_SHOW), int32(IsWarTime() && GetAttackerTeam() == TEAM_ALLIANCE ? 1 : 0));
    packet.Worldstates.emplace_back(uint32(TB_WS_HORDE_ATTACKING_SHOW), int32(IsWarTime() && GetAttackerTeam() == TEAM_HORDE ? 1 : 0));

    // Not sure if TB
    //packet.Worldstates.emplace_back(uint32(TB_WS_9_UNKNOWN), int32(1));

    packet.Worldstates.emplace_back(uint32(TB_WS_SOUTH_DAMAGED_NEUTRAL), int32(0));
    packet.Worldstates.emplace_back(uint32(TB_WS_SOUTH_INTACT_NEUTRAL), int32(0));

    packet.Worldstates.emplace_back(uint32(TB_WS_PROGRESS_SHOW), int32(0));

    // Buildings/bases
    for (BfCapturePointMap::iterator itr = m_capturePoints.begin(); itr != m_capturePoints.end(); ++itr)
    {
        uint8 i = TB_BASE_COUNT;
        switch (itr->second->GetCapturePointEntry())
        {
            case GO_CAPTURE_POINT_NORTH_A_DEFENDING:
            case GO_CAPTURE_POINT_NORTH_H_DEFENDING:
                i = TB_BASE_IRONCLAD_GARRISON;
                break;
            case GO_CAPTURE_POINT_EAST_A_DEFENDING:
            case GO_CAPTURE_POINT_EAST_H_DEFENDING:
                i = TB_BASE_SLAGWORKS;
                break;
            case GO_CAPTURE_POINT_WEST_A_DEFENDING:
            case GO_CAPTURE_POINT_WEST_H_DEFENDING:
                i = TB_BASE_WARDENS_VIGIL;
                break;
            default:
                continue;
        }

        TeamId team = TEAM_NEUTRAL;
        bool controlled = false;
        bool capturing = false;

        switch (itr->second->GetObjectiveState())
        {
            case BF_CAPTUREPOINT_OBJECTIVESTATE_ALLIANCE:
            case BF_CAPTUREPOINT_OBJECTIVESTATE_HORDE:
                controlled = true;
                team = itr->second->GetTeamId();
                break;
            case BF_CAPTUREPOINT_OBJECTIVESTATE_HORDE_ALLIANCE_CHALLENGE:
            case BF_CAPTUREPOINT_OBJECTIVESTATE_NEUTRAL_ALLIANCE_CHALLENGE:
                team = TEAM_ALLIANCE;
                capturing = true;
                break;
            case BF_CAPTUREPOINT_OBJECTIVESTATE_ALLIANCE_HORDE_CHALLENGE:
            case BF_CAPTUREPOINT_OBJECTIVESTATE_NEUTRAL_HORDE_CHALLENGE:
                team = TEAM_HORDE;
                capturing = true;
                break;
            default:
                team = TEAM_NEUTRAL;
                break;
        }

        packet.Worldstates.emplace_back(uint32(TBCapturePoints[i].wsControlled[TEAM_ALLIANCE]), int32(team == TEAM_ALLIANCE && controlled ? 1 : 0));
        packet.Worldstates.emplace_back(uint32(TBCapturePoints[i].wsCapturing[TEAM_ALLIANCE]), int32(team == TEAM_ALLIANCE && capturing ? 1 : 0));
        packet.Worldstates.emplace_back(uint32(TBCapturePoints[i].wsNeutral), int32(team == TEAM_NEUTRAL ? 1 : 0));
        packet.Worldstates.emplace_back(uint32(TBCapturePoints[i].wsCapturing[TEAM_HORDE]), int32(team == TEAM_HORDE && capturing ? 1 : 0));
        packet.Worldstates.emplace_back(uint32(TBCapturePoints[i].wsControlled[TEAM_HORDE]), int32(team == TEAM_HORDE && controlled ? 1 : 0));
    }

    packet.Worldstates.emplace_back(uint32(TB_WS_TOWERS_DESTROYED_SHOW), int32(GetData(BATTLEFIELD_TB_DATA_TOWERS_DESTROYED)));
    packet.Worldstates.emplace_back(uint32(TB_WS_BUILDINGS_CAPTURED_SHOW), int32(IsWarTime() ? 1 : 0));
    packet.Worldstates.emplace_back(uint32(TB_WS_BUILDINGS_CAPTURED), int32(GetData(BATTLEFIELD_TB_DATA_BUILDINGS_CAPTURED)));
    packet.Worldstates.emplace_back(uint32(TB_WS_TOWERS_DESTROYED), int32(0));

    packet.Worldstates.emplace_back(uint32(TB_WS_TIME_BATTLE_END_SHOW), int32(IsWarTime() ? 1 : 0));

    packet.Worldstates.emplace_back(uint32(TB_WS_STATE_BATTLE), int32(IsWarTime() ? 1 : 0));
    packet.Worldstates.emplace_back(uint32(TB_WS_STATE_PREPARATIONS), int32(GetState() == BATTLEFIELD_WARMUP ? 1 : 0));

    // Not sure if TB
    //packet.Worldstates.emplace_back(uint32(TB_WS_35_UNKNOWN), int32(0));
    //packet.Worldstates.emplace_back(uint32(TB_WS_36_UNKNOWN), int32(0));
    //packet.Worldstates.emplace_back(uint32(TB_WS_37_UNKNOWN), int32(0));

    // Unused tower icons
    packet.Worldstates.emplace_back(uint32(TB_WS_WEST_DAMAGED_NEUTRAL), int32(0));
    packet.Worldstates.emplace_back(uint32(TB_WS_WEST_INTACT_NEUTRAL), int32(0));
    packet.Worldstates.emplace_back(uint32(TB_WS_EAST_DAMAGED_NEUTRAL), int32(0));
    packet.Worldstates.emplace_back(uint32(TB_WS_EAST_INTACT_NEUTRAL), int32(0));

    // Towers/spires
    for (uint8 i = 0; i < TB_TOWERS_COUNT; i++)
    {
        // Find gameobject
        for (ObjectGuid guid : Towers)
        {
            GameObject* tower = GetGameObject(guid);
            if (!tower || tower->GetEntry() != TBTowers[i].entry)
                continue;

            TeamId team = GetDefenderTeam(); // 0-false -> alliance; 1-true -> horde
            bool intact = tower->GetDestructibleState() == GO_DESTRUCTIBLE_INTACT;
            bool damaged = tower->GetDestructibleState() == GO_DESTRUCTIBLE_DAMAGED;
            bool destroyed = tower->GetDestructibleState() == GO_DESTRUCTIBLE_DESTROYED;

            packet.Worldstates.emplace_back(uint32(TBTowers[i].wsIntact[TEAM_ALLIANCE]), int32(!team && intact ? 1 : 0));
            packet.Worldstates.emplace_back(uint32(TBTowers[i].wsDamaged[TEAM_ALLIANCE]), int32(!team && damaged ? 1 : 0));
            packet.Worldstates.emplace_back(uint32(TBTowers[i].wsDestroyed), int32(destroyed ? 1 : 0));
            packet.Worldstates.emplace_back(uint32(TBTowers[i].wsDamaged[TEAM_HORDE]), int32(team && damaged ? 1 : 0));
            packet.Worldstates.emplace_back(uint32(TBTowers[i].wsIntact[TEAM_HORDE]), int32(team && intact ? 1 : 0));
        }
    }

    packet.Worldstates.emplace_back(uint32(TB_WS_TIME_NEXT_BATTLE_SHOW), int32(!IsWarTime() ? 1 : 0));

    packet.Worldstates.emplace_back(uint32(TB_WS_ALLIANCE_CONTROLS_SHOW), int32(!IsWarTime() && GetDefenderTeam() == TEAM_ALLIANCE ? 1 : 0));
    packet.Worldstates.emplace_back(uint32(TB_WS_HORDE_CONTROLS_SHOW), int32(!IsWarTime() && GetDefenderTeam() == TEAM_HORDE ? 1 : 0));

    packet.Worldstates.emplace_back(uint32(TB_WS_TIME_BATTLE_END), int32(IsWarTime() ? time(NULL) + (m_Timer / 1000) : 0));
    packet.Worldstates.emplace_back(uint32(TB_WS_TIME_NEXT_BATTLE), int32(!IsWarTime() ? time(NULL) + (m_Timer / 1000) : 0));

    // Not sure if TB
    //packet.Worldstates.emplace_back(uint32(TB_WS_65_UNKNOWN), int32(0));
    //packet.Worldstates.emplace_back(uint32(TB_WS_66_UNKNOWN), int32(0));

    packet.Worldstates.emplace_back(uint32(TB_WS_KEEP_ALLIANCE), int32(GetDefenderTeam() == TEAM_ALLIANCE ? 1 : 0));
    packet.Worldstates.emplace_back(uint32(TB_WS_KEEP_HORDE), int32(GetDefenderTeam() == TEAM_HORDE ? 1 : 0));
}

void BattlefieldTB::SendInitWorldStatesTo(Player* player)
{
    WorldPackets::WorldState::InitWorldStates packet;
    packet.AreaID = m_ZoneId;
    packet.MapID = m_MapId;
    packet.SubareaID = 0;

    FillInitialWorldStates(packet);

    player->SendDirectMessage(packet.Write());
}

void BattlefieldTB::SendInitWorldStatesToAll()
{
    // Save
    sWorld->setWorldState(TB_WS_STATE_BATTLE, uint32(IsWarTime() ? 1 : 0));
    sWorld->setWorldState(TB_WS_ALLIANCE_CONTROLS_SHOW, uint32(!IsWarTime() && GetDefenderTeam() == TEAM_ALLIANCE ? 1 : 0));
    sWorld->setWorldState(TB_WS_HORDE_CONTROLS_SHOW, uint32(!IsWarTime() && GetDefenderTeam() == TEAM_HORDE ? 1 : 0));
    sWorld->setWorldState(TB_WS_ALLIANCE_ATTACKING_SHOW, uint32(IsWarTime() && GetAttackerTeam() == TEAM_ALLIANCE ? 1 : 0));
    sWorld->setWorldState(TB_WS_HORDE_ATTACKING_SHOW, uint32(IsWarTime() && GetAttackerTeam() == TEAM_HORDE ? 1 : 0));
    sWorld->setWorldState(TB_WS_TIME_NEXT_BATTLE, uint32(!IsWarTime() ? m_Timer : 0));
    sWorld->setWorldState(TB_WS_TIME_NEXT_BATTLE_SHOW, uint32(!IsWarTime() ? 1 : 0));

    // Tol Barad
    for (uint8 team = 0; team < BG_TEAMS_COUNT; team++)
        for (ObjectGuid const& guid : m_players[team])
            if (Player* player = ObjectAccessor::FindPlayer(guid))
                SendInitWorldStatesTo(player);

    // Tol Barad Peninsula
    Map::PlayerList const& players = m_Map->GetPlayers();
    for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
        if (Player* player = itr->GetSource()->ToPlayer())
            if (player->GetZoneId() == 5389) // ZONE_TOL_BARAD_PENINSULA
                player->SendInitWorldStates(5389, player->GetAreaId());
}

void BattlefieldTB::OnStartGrouping()
{
    UpdateNPCsAndGameObjects();

    SendUpdateWorldState(TB_WS_STATE_PREPARATIONS, uint32(1));

    // Teleport players out of questing area
    for (uint8 team = 0; team < BG_TEAMS_COUNT; ++team)
        for (ObjectGuid const& guid : m_players[team])
            if (Player* player = ObjectAccessor::FindPlayer(guid))
                if (player->GetAreaId() == TBQuestAreas[m_iCellblockRandom].entry)
                    player->CastSpell(player, TBQuestAreas[m_iCellblockRandom].teleportSpell, true);

    // Should we also teleport players out of Baradin Hold underground area?
};

void BattlefieldTB::OnBattleStart()
{
    SetData(BATTLEFIELD_TB_DATA_BUILDINGS_CAPTURED, uint32(0));
    SetData(BATTLEFIELD_TB_DATA_TOWERS_INTACT, uint32(3));
    SetData(BATTLEFIELD_TB_DATA_TOWERS_DESTROYED, uint32(0));

    UpdateNPCsAndGameObjects();

    SendInitWorldStatesToAll();
};

void BattlefieldTB::OnBattleEnd(bool endByTimer)
{
    if (!endByTimer) // Attackers win (but now they are defenders already)
        SendWarning(GetDefenderTeam() == TEAM_ALLIANCE ? TB_TEXT_FORTRESS_CAPTURE_ALLIANCE : TB_TEXT_FORTRESS_CAPTURE_HORDE);
    else // Defenders win
        SendWarning(GetDefenderTeam() == TEAM_ALLIANCE ? TB_TEXT_FORTRESS_DEFEND_ALLIANCE : TB_TEXT_FORTRESS_DEFEND_HORDE);

    // UpdateNPCsAndGameObjects() must be called 1 minute after battle ends
    m_updateObjectsTimer = 1 * MINUTE * IN_MILLISECONDS;
    updatedNPCAndObjects = false;

    // Complete quest
    TeamCastSpell(GetDefenderTeam(), GetDefenderTeam() == TEAM_ALLIANCE ? SPELL_VICTORY_ALLIANCE : SPELL_VICTORY_HORDE);

    // Rewards
    TeamCastSpell(GetDefenderTeam(), GetDefenderTeam() == TEAM_ALLIANCE ? SPELL_REWARD_VICTORY_ALLIANCE : SPELL_REWARD_VICTORY_HORDE);
    for (uint32 i = 0; i < GetData(BATTLEFIELD_TB_DATA_TOWERS_INTACT); i++) // Unsure, for each intact tower or only once for having any tower intact?
        TeamCastSpell(GetDefenderTeam(), SPELL_REWARD_TOWER_INTACT);
    TeamCastSpell(GetAttackerTeam(), SPELL_REWARD_DEFEAT);

    for (uint8 team = 0; team < 2; ++team)
    {
        for (ObjectGuid const& guid : m_PlayersInWar[team])
            if (Player* player = ObjectAccessor::FindPlayer(guid))
                RemoveAurasFromPlayer(player);

        m_PlayersInWar[team].clear();
    }

    // Reset time warning vars
    warnedFiveMinutes = false;
    warnedTwoMinutes = false;
    warnedOneMinute = false;
};

void BattlefieldTB::UpdateNPCsAndGameObjects()
{
    for (ObjectGuid guid : BattleInactiveNPCs)
        if (Creature* creature = GetCreature(guid))
            HideNpc(creature);

    for (ObjectGuid guid : BattleInactiveGOs)
        if (GameObject* gameobject = GetGameObject(guid))
            gameobject->SetRespawnTime(RESPAWN_ONE_DAY);

    for (ObjectGuid guid : TemporaryNPCs)
        if (Creature* creature = GetCreature(guid))
            creature->RemoveFromWorld();
    TemporaryNPCs.clear();

    for (ObjectGuid guid : TemporaryGOs)
        if (GameObject* gameobject = GetGameObject(guid))
            gameobject->Delete();
    TemporaryGOs.clear();

    // Tol Barad gates - closed during warmup
    if (GameObject* gates = GetGameObject(TBGatesGUID))
        gates->SetGoState(GetState() == BATTLEFIELD_WARMUP ? GO_STATE_READY : GO_STATE_ACTIVE);

    // Baradin Hold door - open when inactive
    if (GameObject* door = GetGameObject(TBDoorGUID))
        door->SetGoState(GetState() == BATTLEFIELD_INACTIVE ? GO_STATE_ACTIVE : GO_STATE_READY);

    // Decide which cellblock and questgiver will be active.
    m_iCellblockRandom = GetState() == BATTLEFIELD_INACTIVE ? urand(CELLBLOCK_THE_HOLE, CELLBLOCK_CURSED_DEPTHS) : uint8(CELLBLOCK_NONE);

    // To The Hole gate
    if (GameObject* door = GetGameObject(m_gateToTheHoleGUID))
        door->SetGoState(m_iCellblockRandom == CELLBLOCK_THE_HOLE ? GO_STATE_ACTIVE : GO_STATE_READY);

    // D-Block gate
    if (GameObject* door = GetGameObject(m_gateDBlockGUID))
        door->SetGoState(m_iCellblockRandom == CELLBLOCK_D_BLOCK ? GO_STATE_ACTIVE : GO_STATE_READY);

    // Cursed Depths gate
    if (GameObject* door = GetGameObject(m_gateCursedDepthsGUID))
        door->SetGoState(m_iCellblockRandom == CELLBLOCK_CURSED_DEPTHS ? GO_STATE_ACTIVE : GO_STATE_READY);

    if (GetState() == BATTLEFIELD_INACTIVE)
    {
        // Delete capture points
        for (BfCapturePointMap::iterator itr = m_capturePoints.begin(); itr != m_capturePoints.end(); ++itr)
            itr->second->DelCapturePoint();
        m_capturePoints.clear();

        // Create capture points
        for (uint8 i = 0; i < TB_BASE_COUNT; i++)
        {
            TolBaradCapturePoint* capturePoint = new TolBaradCapturePoint(this, GetDefenderTeam());

            //Spawn flag pole
            if (GameObject* go = SpawnGameObject(TBCapturePoints[i].entryFlagPole[GetDefenderTeam()], TBCapturePoints[i].pos, QuaternionData()))
            {
                go->SetGoArtKit(GetDefenderTeam() == TEAM_ALLIANCE ? TB_GO_ARTKIT_FLAG_ALLIANCE : TB_GO_ARTKIT_FLAG_HORDE);
                capturePoint->SetCapturePointData(go);
            }

            AddCapturePoint(capturePoint);
        }

        for (ObjectGuid guid : BattleInactiveNPCs)
            if (Creature* creature = GetCreature(guid))
                ShowNpc(creature, true);

        for (ObjectGuid guid : BattleInactiveGOs)
            if (GameObject* gameobject = GetGameObject(guid))
                gameobject->SetRespawnTime(RESPAWN_IMMEDIATELY);

        for (uint8 i = 0; i < TB_QUEST_INFANTRY_MAX; i++)
        {
            uint32 entry = TB_QUEST_INFANTRY[GetDefenderTeam()][urand(0,3)];
            if (Creature* creature = SpawnCreature(entry, TBQuestInfantrySpawnData[i]))
                TemporaryNPCs.insert(creature->GetGUID());
        }

        for (uint8 i = 0; i < TB_GUARDS_MAX; i++)
            if (Creature* creature = SpawnCreature(GetDefenderTeam() == TEAM_ALLIANCE ? NPC_BARADIN_GUARD : NPC_HELLSCREAMS_SENTRY, GuardNPCSpawns[i]))
                TemporaryNPCs.insert(creature->GetGUID());

        for (uint8 i = 0; i < TB_FACTION_NPC_MAX; i++)
            if (Creature* creature = SpawnCreature(GetDefenderTeam() == TEAM_ALLIANCE ? FactionNPCSpawns[i].entryAlliance : FactionNPCSpawns[i].entryHorde, FactionNPCSpawns[i].pos))
                TemporaryNPCs.insert(creature->GetGUID());

        if (Creature* creature = SpawnCreature(RandomQuestgivers[GetDefenderTeam()][m_iCellblockRandom], RandomQuestgiverPos))
            TemporaryNPCs.insert(creature->GetGUID());

        // Spawn portals
        for (uint8 i = 0; i < TB_PORTAL_MAX; i++)
            if (GameObject* go = SpawnGameObject(TBPortalEntry[GetDefenderTeam()], TBPortals[i], QuaternionData()))
                TemporaryGOs.insert(go->GetGUID());

        // Update towers
        for (ObjectGuid guid : Towers)
            if (GameObject* go = GetGameObject(guid))
                go->SetDestructibleState(GO_DESTRUCTIBLE_REBUILDING);
    }
    else if (GetState() == BATTLEFIELD_IN_PROGRESS)
    {
        for (uint8 i = 0; i < TB_ABANDONED_SIEGE_ENGINE_COUNT; i++)
            if (Creature* creature = SpawnCreature(NPC_ABANDONED_SIEGE_ENGINE, TBAbandonedSiegeEngineSpawnData[i]))
                TemporaryNPCs.insert(creature->GetGUID());

        for (ObjectGuid guid : Towers)
        {
            if (GameObject* go = GetGameObject(guid))
            {
                go->SetDestructibleState(GO_DESTRUCTIBLE_INTACT);
                go->ModifyHealth(go->GetGOValue()->Building.MaxHealth);
            }
        }
    }

    // Spawn banners
    for (uint8 i = 0; i < TB_BANNER_MAX; i++)
        if (GameObject* go = SpawnGameObject(TBBannerEntry[GetDefenderTeam()], TBBanners[i], QuaternionData()))
            TemporaryGOs.insert(go->GetGUID());

    // Set graveyard controls
    for (uint8 i = 0; i < BATTLEFIELD_TB_GRAVEYARD_MAX; i++)
        if (BfGraveyard* graveyard = GetGraveyardById(i))
            graveyard->GiveControlTo(!IsWarTime() || TBGraveyards[i].defenderControls ? GetDefenderTeam() : GetAttackerTeam());
};

void BattlefieldTB::OnCreatureCreate(Creature* creature)
{
    switch (creature->GetEntry())
    {
        // Store NPCs that need visibility toggling
        case NPC_TOLBARAD_CAPTIVE_SPIRIT:
        case NPC_TOLBARAD_CELLBLOCK_OOZE:
        case NPC_TOLBARAD_ARCHMAGE_GALUS:
        case NPC_TOLBARAD_GHASTLY_CONVICT:
        case NPC_TOLBARAD_SHIVARRA_DESTROYER:
        case NPC_TOLBARAD_CELL_WATCHER:
        case NPC_TOLBARAD_SVARNOS:
        case NPC_TOLBARAD_JAILED_WRATHGUARD:
        case NPC_TOLBARAD_IMPRISONED_IMP:
        case NPC_TOLBARAD_WARDEN_SILVA:
        case NPC_TOLBARAD_WARDEN_GUARD:
        case NPC_TOLBARAD_IMPRISONED_WORKER:
        case NPC_TOLBARAD_EXILED_MAGE:
        case NPC_CROCOLISK:
        case NPC_PROBLIM:
            BattleInactiveNPCs.insert(creature->GetGUID());
            if (GetState() == BATTLEFIELD_WARMUP) // If battle is about to start, we must hide these.
                HideNpc(creature);
            break;
        case NPC_ABANDONED_SIEGE_ENGINE:
            creature->setFaction(TBFactions[GetDefenderTeam()]);
            creature->CastSpell(creature, SPELL_THICK_LAYER_OF_RUST, true);
            break;
        case NPC_SIEGE_ENGINE_TURRET:
            if (Unit* charmerOrOwner = creature->GetCharmerOrOwner())
                if (Unit* vehiclebase = charmerOrOwner->GetVehicleBase())
                    creature->EnterVehicle(vehiclebase);
            break;
        case NPC_TOWER_RANGE_FINDER:
            creature->CastSpell(creature, SPELL_TOWER_RANGE_FINDER_PERIODIC, true);
            break;
        case NPC_TB_GY_SPIRIT_BARADIN_HOLD_A:
        case NPC_TB_GY_SPIRIT_BARADIN_HOLD_H:
        case NPC_TB_GY_SPIRIT_IRONCLAD_GARRISON_A:
        case NPC_TB_GY_SPIRIT_WARDENS_VIGIL_A:
        case NPC_TB_GY_SPIRIT_EAST_SPIRE_A:
        case NPC_TB_GY_SPIRIT_SOUTH_SPIRE_A:
        case NPC_TB_GY_SPIRIT_WEST_SPIRE_A:
        case NPC_TB_GY_SPIRIT_SLAGWORKS_A:
        case NPC_TB_GY_SPIRIT_IRONCLAD_GARRISON_H:
        case NPC_TB_GY_SPIRIT_WARDENS_VIGIL_H:
        case NPC_TB_GY_SPIRIT_SLAGWORKS_H:
        case NPC_TB_GY_SPIRIT_WEST_SPIRE_H:
        case NPC_TB_GY_SPIRIT_EAST_SPIRE_H:
        case NPC_TB_GY_SPIRIT_SOUTH_SPIRE_H:
            creature->CastSpell(creature, SPELL_TB_SPIRITUAL_IMMUNITY, true);
            creature->CastSpell(creature, SPELL_TB_SPIRIT_HEAL_CHANNEL, true);
            break;
        default:
            break;
    }
};

void BattlefieldTB::OnGameObjectCreate(GameObject* go)
{
    switch (go->GetEntry())
    {
        case GO_TOLBARAD_GATES:
            TBGatesGUID = go->GetGUID();
            go->SetGoState(GetState() == BATTLEFIELD_WARMUP ? GO_STATE_READY : GO_STATE_ACTIVE);
            break;
        case GO_TOLBARAD_DOOR:
            TBDoorGUID = go->GetGUID();
            go->SetGoState(GetState() == BATTLEFIELD_INACTIVE ? GO_STATE_ACTIVE : GO_STATE_READY);
            break;
        case GO_GATE_TO_THE_HOLE:
            m_gateToTheHoleGUID = go->GetGUID();
            go->SetGoState(m_iCellblockRandom == CELLBLOCK_THE_HOLE ? GO_STATE_ACTIVE : GO_STATE_READY);
            break;
        case GO_GATE_D_BLOCK:
            m_gateDBlockGUID = go->GetGUID();
            go->SetGoState(m_iCellblockRandom == CELLBLOCK_D_BLOCK ? GO_STATE_ACTIVE : GO_STATE_READY);
            break;
        case GO_CURSED_DEPTHS_GATE:
            m_gateCursedDepthsGUID = go->GetGUID();
            go->SetGoState(m_iCellblockRandom == CELLBLOCK_CURSED_DEPTHS ? GO_STATE_ACTIVE : GO_STATE_READY);
            break;
        case GO_CRATE_OF_CELLBLOCK_RATIONS:
        case GO_CURSED_SHACKLES:
        case GO_DUSTY_PRISON_JOURNAL:
        case GO_TB_MEETING_STONE:
        case GO_TB_INSTANCE_VISUAL_1:
        case GO_TB_INSTANCE_VISUAL_2:
        case GO_TB_INSTANCE_VISUAL_3:
        case GO_TB_INSTANCE_VISUAL_4:
            BattleInactiveGOs.insert(go->GetGUID());
            if (GetState() == BATTLEFIELD_WARMUP) // If battle is about to start, we must hide these.
                go->SetRespawnTime(RESPAWN_ONE_DAY);
            break;
        default:
            break;
    }
};

void BattlefieldTB::ProcessEvent(WorldObject* obj, uint32 eventId)
{
    if (!IsWarTime())
        return;

    if (eventId == EVENT_COUNT_CAPTURED_BASE)
    {
        UpdateCapturedBaseCount();
        return;
    }

    if (!obj)
        return;

    GameObject* go = obj->ToGameObject();
    if (!go)
        return;

    TBTowerId towerId;
    switch (go->GetEntry())
    {
        case GO_WEST_SPIRE:
            towerId = TB_TOWER_WEST_SPIRE;
            break;
        case GO_EAST_SPIRE:
            towerId = TB_TOWER_EAST_SPIRE;
            break;
        case GO_SOUTH_SPIRE:
            towerId = TB_TOWER_SOUTH_SPIRE;
            break;
        default:
            return;
    }

    if (go->GetDestructibleState() == GO_DESTRUCTIBLE_DAMAGED)
        TowerDamaged(towerId);
    else if (go->GetDestructibleState() == GO_DESTRUCTIBLE_DESTROYED)
        TowerDestroyed(towerId);
}

void BattlefieldTB::TowerDamaged(TBTowerId tbTowerId)
{
    if (!IsWarTime())
        return;

    SendWarning(TBTowers[tbTowerId].textDamaged);

    SetData(BATTLEFIELD_TB_DATA_TOWERS_INTACT, GetData(BATTLEFIELD_TB_DATA_TOWERS_INTACT) - 1);

    SendUpdateWorldState(uint32(TBTowers[tbTowerId].wsIntact[GetDefenderTeam()]), int32(0));
    SendUpdateWorldState(uint32(TBTowers[tbTowerId].wsDamaged[GetDefenderTeam()]), int32(1));

    TeamCastSpell(GetAttackerTeam(), SPELL_REWARD_TOWER_DAMAGED);
}

void BattlefieldTB::TowerDestroyed(TBTowerId tbTowerId)
{
    if (!IsWarTime())
        return;

    // Add 5 minute bonus time
    m_Timer += m_BonusTime;

    SendUpdateWorldState(TB_WS_TIME_BATTLE_END, uint32(time(NULL) + (m_Timer / 1000)));

    SendWarning(TBTowers[tbTowerId].textDamaged);

    SetData(BATTLEFIELD_TB_DATA_TOWERS_DESTROYED, GetData(BATTLEFIELD_TB_DATA_TOWERS_DESTROYED) + 1);
    SendUpdateWorldState(uint32(TB_WS_TOWERS_DESTROYED), int32(GetData(BATTLEFIELD_TB_DATA_TOWERS_DESTROYED)));

    SendUpdateWorldState(uint32(TBTowers[tbTowerId].wsDamaged[GetDefenderTeam()]), int32(0));
    SendUpdateWorldState(uint32(TBTowers[tbTowerId].wsDestroyed), int32(1));

    // Attack bonus buff
    for (ObjectGuid const& guid : m_PlayersInWar[GetAttackerTeam()])
        if (Player* player = ObjectAccessor::FindPlayer(guid))
            player->CastCustomSpell(SPELL_TOWER_ATTACK_BONUS, SPELLVALUE_AURA_STACK, GetData(BATTLEFIELD_TB_DATA_TOWERS_DESTROYED), player, TRIGGERED_FULL_MASK);

    // Honor reward
    TeamCastSpell(GetAttackerTeam(), SPELL_REWARD_TOWER_DESTROYED);
}

void BattlefieldTB::UpdateCapturedBaseCount()
{
    uint32 numCapturedBases = 0; // How many bases attacker has captured

    for (BfCapturePointMap::iterator itr = m_capturePoints.begin(); itr != m_capturePoints.end(); ++itr)
        if (itr->second->GetTeamId() == GetAttackerTeam())
            numCapturedBases += 1;

    SetData(BATTLEFIELD_TB_DATA_BUILDINGS_CAPTURED, numCapturedBases);
    SendUpdateWorldState(TB_WS_BUILDINGS_CAPTURED, uint32(numCapturedBases));

    // Check if attackers won
    if (numCapturedBases == TB_BASE_COUNT)
        EndBattle(false);
}

// Called when player kill a unit in wg zone
void BattlefieldTB::HandleKill(Player* killer, Unit* victim)
{
    if (killer == victim || victim->GetTypeId() != TYPEID_PLAYER)
        return;

    TeamId killerTeam = killer->GetTeamId();
    for (ObjectGuid const& guid : m_PlayersInWar[killerTeam])
        if (Player* player = ObjectAccessor::FindPlayer(guid))
            if (player->GetDistance2d(killer) < 40.0f)
                PromotePlayer(player);
}

void BattlefieldTB::PromotePlayer(Player* killer)
{
    if (!m_isActive || killer->HasAura(SPELL_TB_VETERAN))
        return;

    killer->CastSpell(killer, SPELL_TB_VETERAN, true);
}

TolBaradCapturePoint::TolBaradCapturePoint(BattlefieldTB* battlefield, TeamId teamInControl) : BfCapturePoint(battlefield)
{
    m_Bf = battlefield;
    m_team = teamInControl;
    m_value = teamInControl == TEAM_ALLIANCE ? m_maxValue : -m_maxValue;
    m_State = teamInControl == TEAM_ALLIANCE ? BF_CAPTUREPOINT_OBJECTIVESTATE_ALLIANCE : BF_CAPTUREPOINT_OBJECTIVESTATE_HORDE;
}

void TolBaradCapturePoint::ChangeTeam(TeamId /*oldTeam*/)
{
    // Find out index
    uint8 iBase = TB_BASE_COUNT;
    for (uint8 i = 0; i < TB_BASE_COUNT; i++)
        if (GetCapturePointEntry() == TBCapturePoints[i].entryFlagPole[m_Bf->GetDefenderTeam()])
            iBase = i;

    if (iBase == TB_BASE_COUNT)
        return;

    // Turn off previous world state icon
    switch (m_OldState)
    {
        case BF_CAPTUREPOINT_OBJECTIVESTATE_ALLIANCE:
        case BF_CAPTUREPOINT_OBJECTIVESTATE_HORDE:
            SendUpdateWorldState(TBCapturePoints[iBase].wsControlled[GetTeamId()], uint32(0));
            break;
        case BF_CAPTUREPOINT_OBJECTIVESTATE_HORDE_ALLIANCE_CHALLENGE:
        case BF_CAPTUREPOINT_OBJECTIVESTATE_NEUTRAL_ALLIANCE_CHALLENGE:
            SendUpdateWorldState(TBCapturePoints[iBase].wsCapturing[TEAM_ALLIANCE], uint32(0));
            break;
        case BF_CAPTUREPOINT_OBJECTIVESTATE_ALLIANCE_HORDE_CHALLENGE:
        case BF_CAPTUREPOINT_OBJECTIVESTATE_NEUTRAL_HORDE_CHALLENGE:
            SendUpdateWorldState(TBCapturePoints[iBase].wsCapturing[TEAM_HORDE], uint32(0));
            break;
        default:
            break;
    }

    // Turn on new world state icon and send warning
    switch (m_State)
    {
        case BF_CAPTUREPOINT_OBJECTIVESTATE_ALLIANCE:
        case BF_CAPTUREPOINT_OBJECTIVESTATE_HORDE:
            m_Bf->SendWarning(TBCapturePoints[iBase].textGained[GetTeamId()]);
            SendUpdateWorldState(TBCapturePoints[iBase].wsControlled[GetTeamId()], uint32(1));
            GetCapturePointGo()->SetGoArtKit(GetTeamId() == TEAM_ALLIANCE ? TB_GO_ARTKIT_FLAG_ALLIANCE : TB_GO_ARTKIT_FLAG_HORDE);
            break;
        case BF_CAPTUREPOINT_OBJECTIVESTATE_HORDE_ALLIANCE_CHALLENGE:
            m_Bf->SendWarning(TBCapturePoints[iBase].textLost[TEAM_HORDE]);
            //no break here!
        case BF_CAPTUREPOINT_OBJECTIVESTATE_NEUTRAL_ALLIANCE_CHALLENGE:
            SendUpdateWorldState(TBCapturePoints[iBase].wsCapturing[TEAM_ALLIANCE], uint32(1));
            GetCapturePointGo()->SetGoArtKit(TB_GO_ARTKIT_FLAG_NONE);
            break;
        case BF_CAPTUREPOINT_OBJECTIVESTATE_ALLIANCE_HORDE_CHALLENGE:
            m_Bf->SendWarning(TBCapturePoints[iBase].textLost[TEAM_ALLIANCE]);
            //no break here!
        case BF_CAPTUREPOINT_OBJECTIVESTATE_NEUTRAL_HORDE_CHALLENGE:
            SendUpdateWorldState(TBCapturePoints[iBase].wsCapturing[TEAM_HORDE], uint32(1));
            GetCapturePointGo()->SetGoArtKit(TB_GO_ARTKIT_FLAG_NONE);
            break;
        default:
            break;
    }

    // Update counter
    m_Bf->ProcessEvent(NULL, EVENT_COUNT_CAPTURED_BASE);
}
