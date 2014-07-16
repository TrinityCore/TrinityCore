/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

/// @todo Implement proper support for vehicle+player teleportation
/// @todo Use spell victory/defeat in wg instead of RewardMarkOfHonor() && RewardHonor
/// @todo Add proper implement of achievement

#include "BattlefieldWG.h"
#include "AchievementMgr.h"
#include "Battleground.h"
#include "MapManager.h"
#include "ObjectMgr.h"
#include "Opcodes.h"
#include "Player.h"
#include "SpellAuras.h"
#include "TemporarySummon.h"
#include "WorldSession.h"

BattlefieldWG::~BattlefieldWG()
{
    for (Workshop::const_iterator itr = WorkshopsList.begin(); itr != WorkshopsList.end(); ++itr)
        delete *itr;

    for (GameObjectBuilding::const_iterator itr = BuildingsInZone.begin(); itr != BuildingsInZone.end(); ++itr)
        delete *itr;
}

bool BattlefieldWG::SetupBattlefield()
{
    m_TypeId = BATTLEFIELD_WG;                              // See enum BattlefieldTypes
    m_BattleId = BATTLEFIELD_BATTLEID_WG;
    m_ZoneId = BATTLEFIELD_WG_ZONEID;
    m_MapId = BATTLEFIELD_WG_MAPID;
    m_Map = sMapMgr->FindMap(m_MapId, 0);

    InitStalker(BATTLEFIELD_WG_NPC_STALKER, WintergraspStalkerPos);

    m_MaxPlayer = sWorld->getIntConfig(CONFIG_WINTERGRASP_PLR_MAX);
    m_IsEnabled = sWorld->getBoolConfig(CONFIG_WINTERGRASP_ENABLE);
    m_MinPlayer = sWorld->getIntConfig(CONFIG_WINTERGRASP_PLR_MIN);
    m_MinLevel = sWorld->getIntConfig(CONFIG_WINTERGRASP_PLR_MIN_LVL);
    m_BattleTime = sWorld->getIntConfig(CONFIG_WINTERGRASP_BATTLETIME) * MINUTE * IN_MILLISECONDS;
    m_NoWarBattleTime = sWorld->getIntConfig(CONFIG_WINTERGRASP_NOBATTLETIME) * MINUTE * IN_MILLISECONDS;
    m_RestartAfterCrash = sWorld->getIntConfig(CONFIG_WINTERGRASP_RESTART_AFTER_CRASH) * MINUTE * IN_MILLISECONDS;

    m_TimeForAcceptInvite = 20;
    m_StartGroupingTimer = 15 * MINUTE * IN_MILLISECONDS;
    m_StartGrouping = false;

    m_tenacityStack = 0;

    KickPosition.Relocate(5728.117f, 2714.346f, 697.733f, 0);
    KickPosition.m_mapId = m_MapId;

    RegisterZone(m_ZoneId);

    m_Data32.resize(BATTLEFIELD_WG_DATA_MAX);

    m_saveTimer = 60000;

    // Init GraveYards
    SetGraveyardNumber(BATTLEFIELD_WG_GRAVEYARD_MAX);

    // Load from db
    if ((sWorld->getWorldState(BATTLEFIELD_WG_WORLD_STATE_ACTIVE) == 0) && (sWorld->getWorldState(BATTLEFIELD_WG_WORLD_STATE_DEFENDER) == 0)
            && (sWorld->getWorldState(ClockWorldState[0]) == 0))
    {
        sWorld->setWorldState(BATTLEFIELD_WG_WORLD_STATE_ACTIVE, uint64(false));
        sWorld->setWorldState(BATTLEFIELD_WG_WORLD_STATE_DEFENDER, uint64(urand(0, 1)));
        sWorld->setWorldState(ClockWorldState[0], uint64(m_NoWarBattleTime));
    }

    m_isActive = bool(sWorld->getWorldState(BATTLEFIELD_WG_WORLD_STATE_ACTIVE));
    m_DefenderTeam = TeamId(sWorld->getWorldState(BATTLEFIELD_WG_WORLD_STATE_DEFENDER));

    m_Timer = sWorld->getWorldState(ClockWorldState[0]);
    if (m_isActive)
    {
        m_isActive = false;
        m_Timer = m_RestartAfterCrash;
    }

    for (uint8 i = 0; i < BATTLEFIELD_WG_GRAVEYARD_MAX; i++)
    {
        BfGraveyardWG* graveyard = new BfGraveyardWG(this);

        // When between games, the graveyard is controlled by the defending team
        if (WGGraveYard[i].startcontrol == TEAM_NEUTRAL)
            graveyard->Initialize(m_DefenderTeam, WGGraveYard[i].gyid);
        else
            graveyard->Initialize(WGGraveYard[i].startcontrol, WGGraveYard[i].gyid);

        graveyard->SetTextId(WGGraveYard[i].textid);
        m_GraveyardList[i] = graveyard;
    }


    // Spawn workshop creatures and gameobjects
    for (uint8 i = 0; i < WG_MAX_WORKSHOP; i++)
    {
        WGWorkshop* workshop = new WGWorkshop(this, i);
        if (i < BATTLEFIELD_WG_WORKSHOP_KEEP_WEST)
            workshop->GiveControlTo(GetAttackerTeam(), true);
        else
            workshop->GiveControlTo(GetDefenderTeam(), true);

        // Note: Capture point is added once the gameobject is created.
        WorkshopsList.insert(workshop);
    }

    // Spawn NPCs in the defender's keep, both Horde and Alliance
    for (uint8 i = 0; i < WG_MAX_KEEP_NPC; i++)
    {
        // Horde npc
        if (Creature* creature = SpawnCreature(WGKeepNPC[i].entryHorde, WGKeepNPC[i].x, WGKeepNPC[i].y, WGKeepNPC[i].z, WGKeepNPC[i].o, TEAM_HORDE))
            KeepCreature[TEAM_HORDE].insert(creature->GetGUID());
        // Alliance npc
        if (Creature* creature = SpawnCreature(WGKeepNPC[i].entryAlliance, WGKeepNPC[i].x, WGKeepNPC[i].y, WGKeepNPC[i].z, WGKeepNPC[i].o, TEAM_ALLIANCE))
            KeepCreature[TEAM_ALLIANCE].insert(creature->GetGUID());
    }

    // Hide NPCs from the Attacker's team in the keep
    for (GuidSet::const_iterator itr = KeepCreature[GetAttackerTeam()].begin(); itr != KeepCreature[GetAttackerTeam()].end(); ++itr)
        if (Creature* creature = GetCreature(*itr))
            HideNpc(creature);

    // Spawn Horde NPCs outside the keep
    for (uint8 i = 0; i < WG_OUTSIDE_ALLIANCE_NPC; i++)
        if (Creature* creature = SpawnCreature(WGOutsideNPC[i].entryHorde, WGOutsideNPC[i].x, WGOutsideNPC[i].y, WGOutsideNPC[i].z, WGOutsideNPC[i].o, TEAM_HORDE))
            OutsideCreature[TEAM_HORDE].insert(creature->GetGUID());

    // Spawn Alliance NPCs outside the keep
    for (uint8 i = WG_OUTSIDE_ALLIANCE_NPC; i < WG_MAX_OUTSIDE_NPC; i++)
        if (Creature* creature = SpawnCreature(WGOutsideNPC[i].entryAlliance, WGOutsideNPC[i].x, WGOutsideNPC[i].y, WGOutsideNPC[i].z, WGOutsideNPC[i].o, TEAM_ALLIANCE))
            OutsideCreature[TEAM_ALLIANCE].insert(creature->GetGUID());

    // Hide units outside the keep that are defenders
    for (GuidSet::const_iterator itr = OutsideCreature[GetDefenderTeam()].begin(); itr != OutsideCreature[GetDefenderTeam()].end(); ++itr)
        if (Creature* creature = GetCreature(*itr))
            HideNpc(creature);

    // Spawn turrets and hide them per default
    for (uint8 i = 0; i < WG_MAX_TURRET; i++)
    {
        Position towerCannonPos = WGTurret[i].GetPosition();
        if (Creature* creature = SpawnCreature(NPC_WINTERGRASP_TOWER_CANNON, towerCannonPos, TEAM_ALLIANCE))
        {
            CanonList.insert(creature->GetGUID());
            HideNpc(creature);
        }
    }

    // Spawn all gameobjects
    for (uint8 i = 0; i < WG_MAX_OBJ; i++)
    {
        if (GameObject* go = SpawnGameObject(WGGameObjectBuilding[i].entry, WGGameObjectBuilding[i].x, WGGameObjectBuilding[i].y, WGGameObjectBuilding[i].z, WGGameObjectBuilding[i].o))
        {
            BfWGGameObjectBuilding* b = new BfWGGameObjectBuilding(this);
            b->Init(go, WGGameObjectBuilding[i].type, WGGameObjectBuilding[i].WorldState, WGGameObjectBuilding[i].nameId);
            if (!IsEnabled() && go->GetEntry() == GO_WINTERGRASP_VAULT_GATE)
                go->SetDestructibleState(GO_DESTRUCTIBLE_DESTROYED);
            BuildingsInZone.insert(b);
        }
    }

    // Spawning portal defender
    for (uint8 i = 0; i < WG_MAX_TELEPORTER; i++)
    {
        if (GameObject* go = SpawnGameObject(WGPortalDefenderData[i].entry, WGPortalDefenderData[i].x, WGPortalDefenderData[i].y, WGPortalDefenderData[i].z, WGPortalDefenderData[i].o))
        {
            DefenderPortalList.insert(go->GetGUID());
            go->SetFaction(WintergraspFaction[GetDefenderTeam()]);
        }
    }

    UpdateCounterVehicle(true);
    return true;
}

bool BattlefieldWG::Update(uint32 diff)
{
    bool m_return = Battlefield::Update(diff);
    if (m_saveTimer <= diff)
    {
        sWorld->setWorldState(BATTLEFIELD_WG_WORLD_STATE_ACTIVE, m_isActive);
        sWorld->setWorldState(BATTLEFIELD_WG_WORLD_STATE_DEFENDER, m_DefenderTeam);
        sWorld->setWorldState(ClockWorldState[0], m_Timer);
        m_saveTimer = 60 * IN_MILLISECONDS;
    }
    else
        m_saveTimer -= diff;

    return m_return;
}

void BattlefieldWG::OnBattleStart()
{
    // Spawn titan relic
    if (GameObject* relic = SpawnGameObject(GO_WINTERGRASP_TITAN_S_RELIC, 5440.0f, 2840.8f, 430.43f, 0))
    {
        // Update faction of relic, only attacker can click on
        relic->SetFaction(WintergraspFaction[GetAttackerTeam()]);
        // Set in use (not allow to click on before last door is broken)
        relic->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
        m_titansRelicGUID = relic->GetGUID();
    }
    else
        TC_LOG_ERROR("bg.battlefield", "WG: Failed to spawn titan relic.");


    // Update tower visibility and update faction
    for (GuidSet::const_iterator itr = CanonList.begin(); itr != CanonList.end(); ++itr)
    {
        if (Creature* creature = GetCreature(*itr))
        {
            ShowNpc(creature, true);
            creature->setFaction(WintergraspFaction[GetDefenderTeam()]);
        }
    }

    // Rebuild all wall
    for (GameObjectBuilding::const_iterator itr = BuildingsInZone.begin(); itr != BuildingsInZone.end(); ++itr)
    {
        if (*itr)
        {
            (*itr)->Rebuild();
            (*itr)->UpdateTurretAttack(false);
        }
    }

    SetData(BATTLEFIELD_WG_DATA_BROKEN_TOWER_ATT, 0);
    SetData(BATTLEFIELD_WG_DATA_BROKEN_TOWER_DEF, 0);
    SetData(BATTLEFIELD_WG_DATA_DAMAGED_TOWER_ATT, 0);
    SetData(BATTLEFIELD_WG_DATA_DAMAGED_TOWER_DEF, 0);

    // Update graveyard (in no war time all graveyard is to deffender, in war time, depend of base)
    for (Workshop::const_iterator itr = WorkshopsList.begin(); itr != WorkshopsList.end(); ++itr)
        if (*itr)
            (*itr)->UpdateGraveyardAndWorkshop();

    for (uint8 team = 0; team < 2; ++team)
        for (GuidSet::const_iterator itr = m_players[team].begin(); itr != m_players[team].end(); ++itr)
        {
            // Kick player in orb room, TODO: offline player ?
            if (Player* player = sObjectAccessor->FindPlayer(*itr))
            {
                float x, y, z;
                player->GetPosition(x, y, z);
                if (5500 > x && x > 5392 && y < 2880 && y > 2800 && z < 480)
                    player->TeleportTo(571, 5349.8686f, 2838.481f, 409.240f, 0.046328f);
                SendInitWorldStatesTo(player);
            }
        }
    // Initialize vehicle counter
    UpdateCounterVehicle(true);
    // Send start warning to all players
    SendWarningToAllInZone(BATTLEFIELD_WG_TEXT_START);
}

void BattlefieldWG::UpdateCounterVehicle(bool init)
{
    if (init)
    {
        SetData(BATTLEFIELD_WG_DATA_VEHICLE_H, 0);
        SetData(BATTLEFIELD_WG_DATA_VEHICLE_A, 0);
    }
    SetData(BATTLEFIELD_WG_DATA_MAX_VEHICLE_H, 0);
    SetData(BATTLEFIELD_WG_DATA_MAX_VEHICLE_A, 0);

    for (Workshop::const_iterator itr = WorkshopsList.begin(); itr != WorkshopsList.end(); ++itr)
    {
        if (WGWorkshop* workshop = (*itr))
        {
            if (workshop->teamControl == TEAM_ALLIANCE)
                UpdateData(BATTLEFIELD_WG_DATA_MAX_VEHICLE_A, 4);
            else if (workshop->teamControl == TEAM_HORDE)
                UpdateData(BATTLEFIELD_WG_DATA_MAX_VEHICLE_H, 4);
        }
    }

    UpdateVehicleCountWG();
}

void BattlefieldWG::OnBattleEnd(bool endByTimer)
{
    // Remove relic
    if (m_titansRelicGUID)
        if (GameObject* relic = GetGameObject(m_titansRelicGUID))
            relic->RemoveFromWorld();
    m_titansRelicGUID = 0;

    // Remove turret
    for (GuidSet::const_iterator itr = CanonList.begin(); itr != CanonList.end(); ++itr)
    {
        if (Creature* creature = GetCreature(*itr))
        {
            if (!endByTimer)
                creature->setFaction(WintergraspFaction[GetDefenderTeam()]);
            HideNpc(creature);
        }
    }

    if (!endByTimer) // One player triggered the relic
    {
        // Change all npc in keep
        for (GuidSet::const_iterator itr = KeepCreature[GetAttackerTeam()].begin(); itr != KeepCreature[GetAttackerTeam()].end(); ++itr)
            if (Creature* creature = GetCreature(*itr))
                HideNpc(creature);

        for (GuidSet::const_iterator itr = KeepCreature[GetDefenderTeam()].begin(); itr != KeepCreature[GetDefenderTeam()].end(); ++itr)
            if (Creature* creature = GetCreature(*itr))
                ShowNpc(creature, true);

        // Change all npc out of keep
        for (GuidSet::const_iterator itr = OutsideCreature[GetDefenderTeam()].begin(); itr != OutsideCreature[GetDefenderTeam()].end(); ++itr)
            if (Creature* creature = GetCreature(*itr))
                HideNpc(creature);

        for (GuidSet::const_iterator itr = OutsideCreature[GetAttackerTeam()].begin(); itr != OutsideCreature[GetAttackerTeam()].end(); ++itr)
            if (Creature* creature = GetCreature(*itr))
                ShowNpc(creature, true);
    }

    // Update all graveyard, control is to defender when no wartime
    for (uint8 i = 0; i < BATTLEFIELD_WG_GY_HORDE; i++)
        if (BfGraveyard* graveyard = GetGraveyardById(i))
            graveyard->GiveControlTo(GetDefenderTeam());

    for (GuidSet::const_iterator itr = m_KeepGameObject[GetDefenderTeam()].begin(); itr != m_KeepGameObject[GetDefenderTeam()].end(); ++itr)
        if (GameObject* object = GetGameObject(*itr))
            object->SetRespawnTime(RESPAWN_IMMEDIATELY);

    for (GuidSet::const_iterator itr = m_KeepGameObject[GetAttackerTeam()].begin(); itr != m_KeepGameObject[GetAttackerTeam()].end(); ++itr)
        if (GameObject* object = GetGameObject(*itr))
            object->SetRespawnTime(RESPAWN_ONE_DAY);

    // Update portal defender faction
    for (GuidSet::const_iterator itr = DefenderPortalList.begin(); itr != DefenderPortalList.end(); ++itr)
        if (GameObject* portal = GetGameObject(*itr))
            portal->SetFaction(WintergraspFaction[GetDefenderTeam()]);

    // Saving data
    for (GameObjectBuilding::const_iterator itr = BuildingsInZone.begin(); itr != BuildingsInZone.end(); ++itr)
        (*itr)->Save();
    for (Workshop::const_iterator itr = WorkshopsList.begin(); itr != WorkshopsList.end(); ++itr)
        (*itr)->Save();

    for (GuidSet::const_iterator itr = m_PlayersInWar[GetDefenderTeam()].begin(); itr != m_PlayersInWar[GetDefenderTeam()].end(); ++itr)
    {
        if (Player* player = sObjectAccessor->FindPlayer(*itr))
        {
            player->CastSpell(player, SPELL_ESSENCE_OF_WINTERGRASP, true);
            player->CastSpell(player, SPELL_VICTORY_REWARD, true);
            // Send Wintergrasp victory achievement
            DoCompleteOrIncrementAchievement(ACHIEVEMENTS_WIN_WG, player);
            // Award achievement for succeeding in Wintergrasp in 10 minutes or less
            if (!endByTimer && GetTimer() <= 10000)
                DoCompleteOrIncrementAchievement(ACHIEVEMENTS_WIN_WG_TIMER_10, player);
        }
    }

    for (GuidSet::const_iterator itr = m_PlayersInWar[GetAttackerTeam()].begin(); itr != m_PlayersInWar[GetAttackerTeam()].end(); ++itr)
        if (Player* player = sObjectAccessor->FindPlayer(*itr))
            player->CastSpell(player, SPELL_DEFEAT_REWARD, true);

    for (uint8 team = 0; team < 2; ++team)
    {
        for (GuidSet::const_iterator itr = m_PlayersInWar[team].begin(); itr != m_PlayersInWar[team].end(); ++itr)
            if (Player* player = sObjectAccessor->FindPlayer(*itr))
                RemoveAurasFromPlayer(player);

        m_PlayersInWar[team].clear();

        for (GuidSet::const_iterator itr = m_vehicles[team].begin(); itr != m_vehicles[team].end(); ++itr)
            if (Creature* creature = GetCreature(*itr))
                if (creature->IsVehicle())
                    creature->DespawnOrUnsummon();

        m_vehicles[team].clear();
    }

    if (!endByTimer)
    {
        for (uint8 team = 0; team < 2; ++team)
        {
            for (GuidSet::const_iterator itr = m_players[team].begin(); itr != m_players[team].end(); ++itr)
            {
                if (Player* player = sObjectAccessor->FindPlayer(*itr))
                {
                    player->RemoveAurasDueToSpell(m_DefenderTeam == TEAM_ALLIANCE ? SPELL_HORDE_CONTROL_PHASE_SHIFT : SPELL_ALLIANCE_CONTROL_PHASE_SHIFT, player->GetGUID());
                    player->AddAura(m_DefenderTeam == TEAM_HORDE ? SPELL_HORDE_CONTROL_PHASE_SHIFT : SPELL_ALLIANCE_CONTROL_PHASE_SHIFT, player);
                }
            }
        }
    }

    if (!endByTimer) // win alli/horde
        SendWarningToAllInZone((GetDefenderTeam() == TEAM_ALLIANCE) ? BATTLEFIELD_WG_TEXT_WIN_KEEP : BATTLEFIELD_WG_TEXT_WIN_KEEP + 1);
    else // defend alli/horde
        SendWarningToAllInZone((GetDefenderTeam() == TEAM_ALLIANCE) ? BATTLEFIELD_WG_TEXT_DEFEND_KEEP : BATTLEFIELD_WG_TEXT_DEFEND_KEEP + 1);
}

// *******************************************************
// ******************* Reward System *********************
// *******************************************************
void BattlefieldWG::DoCompleteOrIncrementAchievement(uint32 achievement, Player* player, uint8 /*incrementNumber*/)
{
    AchievementEntry const* achievementEntry = sAchievementMgr->GetAchievement(achievement);

    if (!achievementEntry)
        return;

    switch (achievement)
    {
        case ACHIEVEMENTS_WIN_WG_100:
        {
            // player->UpdateAchievementCriteria();
        }
        default:
        {
            if (player)
                player->CompletedAchievement(achievementEntry);
            break;
        }
    }

}

void BattlefieldWG::OnStartGrouping()
{
    SendWarningToAllInZone(BATTLEFIELD_WG_TEXT_WILL_START);
}

uint8 BattlefieldWG::GetSpiritGraveyardId(uint32 areaId) const
{
    switch (areaId)
    {
        case AREA_WINTERGRASP_FORTRESS:
            return BATTLEFIELD_WG_GY_KEEP;
        case AREA_THE_SUNKEN_RING:
            return BATTLEFIELD_WG_GY_WORKSHOP_NE;
        case AREA_THE_BROKEN_TEMPLATE:
            return BATTLEFIELD_WG_GY_WORKSHOP_NW;
        case AREA_WESTPARK_WORKSHOP:
            return BATTLEFIELD_WG_GY_WORKSHOP_SW;
        case AREA_EASTPARK_WORKSHOP:
            return BATTLEFIELD_WG_GY_WORKSHOP_SE;
        case AREA_WINTERGRASP:
            return BATTLEFIELD_WG_GY_ALLIANCE;
        case AREA_THE_CHILLED_QUAGMIRE:
            return BATTLEFIELD_WG_GY_HORDE;
        default:
            TC_LOG_ERROR("bg.battlefield", "BattlefieldWG::GetSpiritGraveyardId: Unexpected Area Id %u", areaId);
            break;
    }

    return 0;
}

void BattlefieldWG::OnCreatureCreate(Creature* creature)
{
    // Accessing to db spawned creatures
    switch (creature->GetEntry())
    {
        case NPC_DWARVEN_SPIRIT_GUIDE:
        case NPC_TAUNKA_SPIRIT_GUIDE:
        {
            TeamId teamId = (creature->GetEntry() == NPC_DWARVEN_SPIRIT_GUIDE ? TEAM_ALLIANCE : TEAM_HORDE);
            uint8 graveyardId = GetSpiritGraveyardId(creature->GetAreaId());
            if (m_GraveyardList[graveyardId])
                m_GraveyardList[graveyardId]->SetSpirit(creature, teamId);
            break;
        }
    }

    // untested code - not sure if it is valid.
    if (IsWarTime())
    {
        switch (creature->GetEntry())
        {
            case NPC_WINTERGRASP_SIEGE_ENGINE_ALLIANCE:
            case NPC_WINTERGRASP_SIEGE_ENGINE_HORDE:
            case NPC_WINTERGRASP_CATAPULT:
            case NPC_WINTERGRASP_DEMOLISHER:
            {
                if (!creature->ToTempSummon() || !creature->ToTempSummon()->GetSummonerGUID() || !sObjectAccessor->FindPlayer(creature->ToTempSummon()->GetSummonerGUID()))
                {
                    creature->DespawnOrUnsummon();
                    return;
                }

                Player* creator = sObjectAccessor->FindPlayer(creature->ToTempSummon()->GetSummonerGUID());
                TeamId team = creator->GetTeamId();

                if (team == TEAM_HORDE)
                {
                    if (GetData(BATTLEFIELD_WG_DATA_VEHICLE_H) < GetData(BATTLEFIELD_WG_DATA_MAX_VEHICLE_H))
                    {
                        UpdateData(BATTLEFIELD_WG_DATA_VEHICLE_H, 1);
                        creature->AddAura(SPELL_HORDE_FLAG, creature);
                        m_vehicles[team].insert(creature->GetGUID());
                        UpdateVehicleCountWG();
                    }
                    else
                    {
                        creature->DespawnOrUnsummon();
                        return;
                    }
                }
                else
                {
                    if (GetData(BATTLEFIELD_WG_DATA_VEHICLE_A) < GetData(BATTLEFIELD_WG_DATA_MAX_VEHICLE_A))
                    {
                        UpdateData(BATTLEFIELD_WG_DATA_VEHICLE_A, 1);
                        creature->AddAura(SPELL_ALLIANCE_FLAG, creature);
                        m_vehicles[team].insert(creature->GetGUID());
                        UpdateVehicleCountWG();
                    }
                    else
                    {
                        creature->DespawnOrUnsummon();
                        return;
                    }
                }

                creature->CastSpell(creator, SPELL_GRAB_PASSENGER, true);
                break;
            }
        }
    }
}

void BattlefieldWG::OnCreatureRemove(Creature* /*creature*/)
{
/* possibly can be used later
    if (IsWarTime())
    {
        switch (creature->GetEntry())
        {
            case NPC_WINTERGRASP_SIEGE_ENGINE_ALLIANCE:
            case NPC_WINTERGRASP_SIEGE_ENGINE_HORDE:
            case NPC_WINTERGRASP_CATAPULT:
            case NPC_WINTERGRASP_DEMOLISHER:
            {
                uint8 team;
                if (creature->getFaction() == WintergraspFaction[TEAM_ALLIANCE])
                    team = TEAM_ALLIANCE;
                else if (creature->getFaction() == WintergraspFaction[TEAM_HORDE])
                    team = TEAM_HORDE;
                else
                    return;

                m_vehicles[team].erase(creature->GetGUID());
                if (team == TEAM_HORDE)
                    UpdateData(BATTLEFIELD_WG_DATA_VEHICLE_H, -1);
                else
                    UpdateData(BATTLEFIELD_WG_DATA_VEHICLE_A, -1);
                UpdateVehicleCountWG();

                break;
            }
        }
    }*/
}

void BattlefieldWG::OnGameObjectCreate(GameObject* go)
{
    uint8 workshopId = 0;

    switch (go->GetEntry())
    {
        case GO_WINTERGRASP_FACTORY_BANNER_NE:
            workshopId = BATTLEFIELD_WG_WORKSHOP_NE;
            break;
        case GO_WINTERGRASP_FACTORY_BANNER_NW:
            workshopId = BATTLEFIELD_WG_WORKSHOP_NW;
            break;
        case GO_WINTERGRASP_FACTORY_BANNER_SE:
            workshopId = BATTLEFIELD_WG_WORKSHOP_SE;
            break;
        case GO_WINTERGRASP_FACTORY_BANNER_SW:
            workshopId = BATTLEFIELD_WG_WORKSHOP_SW;
            break;
        default:
            return;
    }

    for (Workshop::const_iterator itr = WorkshopsList.begin(); itr != WorkshopsList.end(); ++itr)
    {
        if (WGWorkshop* workshop = (*itr))
        {
            if (workshop->workshopId == workshopId)
            {
                WintergraspCapturePoint* capturePoint = new WintergraspCapturePoint(this, GetAttackerTeam());

                capturePoint->SetCapturePointData(go);
                capturePoint->LinkToWorkshop(workshop);
                AddCapturePoint(capturePoint);
                break;
            }
        }
    }
}

// Called when player kill a unit in wg zone
void BattlefieldWG::HandleKill(Player* killer, Unit* victim)
{
    if (killer == victim)
        return;

    bool again = false;
    TeamId killerTeam = killer->GetTeamId();

    if (victim->GetTypeId() == TYPEID_PLAYER)
    {
        for (GuidSet::const_iterator itr = m_PlayersInWar[killerTeam].begin(); itr != m_PlayersInWar[killerTeam].end(); ++itr)
            if (Player* player = sObjectAccessor->FindPlayer(*itr))
                if (player->GetDistance2d(killer) < 40)
                    PromotePlayer(player);
        return;
    }

    for (GuidSet::const_iterator itr = KeepCreature[GetOtherTeam(killerTeam)].begin();
         itr != KeepCreature[GetOtherTeam(killerTeam)].end(); ++itr)
    {
        if (Creature* creature = GetCreature(*itr))
        {
            if (victim->GetEntry() == creature->GetEntry() && !again)
            {
                again = true;
                for (GuidSet::const_iterator iter = m_PlayersInWar[killerTeam].begin(); iter != m_PlayersInWar[killerTeam].end(); ++iter)
                    if (Player* player = sObjectAccessor->FindPlayer(*iter))
                        if (player->GetDistance2d(killer) < 40.0f)
                            PromotePlayer(player);
            }
        }
    }
    /// @todoRecent PvP activity worldstate
}

bool BattlefieldWG::FindAndRemoveVehicleFromList(Unit* vehicle)
{
    for (uint32 itr = 0; itr < 2; ++itr)
    {
        if (m_vehicles[itr].find(vehicle->GetGUID()) != m_vehicles[itr].end())
        {
            m_vehicles[itr].erase(vehicle->GetGUID());
            if (itr == TEAM_HORDE)
                UpdateData(BATTLEFIELD_WG_DATA_VEHICLE_H, -1);
            else
                UpdateData(BATTLEFIELD_WG_DATA_VEHICLE_A, -1);
            return true;
        }
    }
    return false;
}

void BattlefieldWG::OnUnitDeath(Unit* unit)
{
    if (IsWarTime())
        if (unit->IsVehicle())
            if (FindAndRemoveVehicleFromList(unit))
                UpdateVehicleCountWG();
}

// Update rank for player
void BattlefieldWG::PromotePlayer(Player* killer)
{
    if (!m_isActive)
        return;
    // Updating rank of player
    if (Aura* auraRecruit = killer->GetAura(SPELL_RECRUIT))
    {
        if (auraRecruit->GetStackAmount() >= 5)
        {
            killer->RemoveAura(SPELL_RECRUIT);
            killer->CastSpell(killer, SPELL_CORPORAL, true);
            SendWarningToPlayer(killer, BATTLEFIELD_WG_TEXT_FIRSTRANK);
        }
        else
            killer->CastSpell(killer, SPELL_RECRUIT, true);
    }
    else if (Aura* auraCorporal = killer->GetAura(SPELL_CORPORAL))
    {
        if (auraCorporal->GetStackAmount() >= 5)
        {
            killer->RemoveAura(SPELL_CORPORAL);
            killer->CastSpell(killer, SPELL_LIEUTENANT, true);
            SendWarningToPlayer(killer, BATTLEFIELD_WG_TEXT_SECONDRANK);
        }
        else
            killer->CastSpell(killer, SPELL_CORPORAL, true);
    }
}

void BattlefieldWG::RemoveAurasFromPlayer(Player* player)
{
    player->RemoveAurasDueToSpell(SPELL_RECRUIT);
    player->RemoveAurasDueToSpell(SPELL_CORPORAL);
    player->RemoveAurasDueToSpell(SPELL_LIEUTENANT);
    player->RemoveAurasDueToSpell(SPELL_TOWER_CONTROL);
    player->RemoveAurasDueToSpell(SPELL_SPIRITUAL_IMMUNITY);
    player->RemoveAurasDueToSpell(SPELL_TENACITY);
    player->RemoveAurasDueToSpell(SPELL_ESSENCE_OF_WINTERGRASP);
    player->RemoveAurasDueToSpell(SPELL_WINTERGRASP_RESTRICTED_FLIGHT_AREA);
}

void BattlefieldWG::OnPlayerJoinWar(Player* player)
{
    RemoveAurasFromPlayer(player);

    player->CastSpell(player, SPELL_RECRUIT, true);

    if (player->GetZoneId() != m_ZoneId)
    {
        if (player->GetTeamId() == GetDefenderTeam())
            player->TeleportTo(571, 5345, 2842, 410, 3.14f);
        else
        {
            if (player->GetTeamId() == TEAM_HORDE)
                player->TeleportTo(571, 5025.857422f, 3674.628906f, 362.737122f, 4.135169f);
            else
                player->TeleportTo(571, 5101.284f, 2186.564f, 373.549f, 3.812f);
        }
    }

    UpdateTenacity();

    if (player->GetTeamId() == GetAttackerTeam())
    {
        if (GetData(BATTLEFIELD_WG_DATA_BROKEN_TOWER_ATT) < 3)
            player->SetAuraStack(SPELL_TOWER_CONTROL, player, 3 - GetData(BATTLEFIELD_WG_DATA_BROKEN_TOWER_ATT));
    }
    else
    {
        if (GetData(BATTLEFIELD_WG_DATA_BROKEN_TOWER_ATT) > 0)
           player->SetAuraStack(SPELL_TOWER_CONTROL, player, GetData(BATTLEFIELD_WG_DATA_BROKEN_TOWER_ATT));
    }
    SendInitWorldStatesTo(player);
}

void BattlefieldWG::OnPlayerLeaveWar(Player* player)
{
    // Remove all aura from WG /// @todo false we can go out of this zone on retail and keep Rank buff, remove on end of WG
    if (!player->GetSession()->PlayerLogout())
    {
        if (Creature* vehicle = player->GetVehicleCreatureBase())   // Remove vehicle of player if he go out.
            vehicle->DespawnOrUnsummon();

        RemoveAurasFromPlayer(player);
    }

    player->RemoveAurasDueToSpell(SPELL_HORDE_CONTROLS_FACTORY_PHASE_SHIFT);
    player->RemoveAurasDueToSpell(SPELL_ALLIANCE_CONTROLS_FACTORY_PHASE_SHIFT);
    player->RemoveAurasDueToSpell(SPELL_HORDE_CONTROL_PHASE_SHIFT);
    player->RemoveAurasDueToSpell(SPELL_ALLIANCE_CONTROL_PHASE_SHIFT);
}

void BattlefieldWG::OnPlayerLeaveZone(Player* player)
{
    if (!m_isActive)
        RemoveAurasFromPlayer(player);

    player->RemoveAurasDueToSpell(SPELL_HORDE_CONTROLS_FACTORY_PHASE_SHIFT);
    player->RemoveAurasDueToSpell(SPELL_ALLIANCE_CONTROLS_FACTORY_PHASE_SHIFT);
    player->RemoveAurasDueToSpell(SPELL_HORDE_CONTROL_PHASE_SHIFT);
    player->RemoveAurasDueToSpell(SPELL_ALLIANCE_CONTROL_PHASE_SHIFT);
}

void BattlefieldWG::OnPlayerEnterZone(Player* player)
{
    if (!m_isActive)
        RemoveAurasFromPlayer(player);

    player->AddAura(m_DefenderTeam == TEAM_HORDE ? SPELL_HORDE_CONTROL_PHASE_SHIFT : SPELL_ALLIANCE_CONTROL_PHASE_SHIFT, player);
    // Send worldstate to player
    SendInitWorldStatesTo(player);
}

uint32 BattlefieldWG::GetData(uint32 data) const
{
    switch (data)
    {
        // Used to determine when the phasing spells must be cast
        // See: SpellArea::IsFitToRequirements
        case AREA_THE_SUNKEN_RING:
        case AREA_THE_BROKEN_TEMPLATE:
        case AREA_WESTPARK_WORKSHOP:
        case AREA_EASTPARK_WORKSHOP:
            // Graveyards and Workshops are controlled by the same team.
            if (BfGraveyard const* graveyard = GetGraveyardById(GetSpiritGraveyardId(data)))
                return graveyard->GetControlTeamId();
            break;
        default:
            break;
    }

    return Battlefield::GetData(data);
}


void BattlefieldWG::FillInitialWorldStates(WorldPacket& data)
{
    data << uint32(BATTLEFIELD_WG_WORLD_STATE_ATTACKER) << uint32(GetAttackerTeam());
    data << uint32(BATTLEFIELD_WG_WORLD_STATE_DEFENDER) << uint32(GetDefenderTeam());
    data << uint32(BATTLEFIELD_WG_WORLD_STATE_ACTIVE) << uint32(IsWarTime() ? 0 : 1); // Note: cleanup these two, their names look awkward
    data << uint32(BATTLEFIELD_WG_WORLD_STATE_SHOW_WORLDSTATE) << uint32(IsWarTime() ? 1 : 0);

    for (uint32 i = 0; i < 2; ++i)
        data << ClockWorldState[i] << uint32(time(NULL) + (m_Timer / 1000));

    data << uint32(BATTLEFIELD_WG_WORLD_STATE_VEHICLE_H) << uint32(GetData(BATTLEFIELD_WG_DATA_VEHICLE_H));
    data << uint32(BATTLEFIELD_WG_WORLD_STATE_MAX_VEHICLE_H) << GetData(BATTLEFIELD_WG_DATA_MAX_VEHICLE_H);
    data << uint32(BATTLEFIELD_WG_WORLD_STATE_VEHICLE_A) << uint32(GetData(BATTLEFIELD_WG_DATA_VEHICLE_A));
    data << uint32(BATTLEFIELD_WG_WORLD_STATE_MAX_VEHICLE_A) << GetData(BATTLEFIELD_WG_DATA_MAX_VEHICLE_A);

    for (GameObjectBuilding::const_iterator itr = BuildingsInZone.begin(); itr != BuildingsInZone.end(); ++itr)
        data << (*itr)->m_WorldState << (*itr)->m_State;

    for (Workshop::const_iterator itr = WorkshopsList.begin(); itr != WorkshopsList.end(); ++itr)
        if (*itr)
            data << WorkshopsData[(*itr)->workshopId].worldstate << (*itr)->state;
}

void BattlefieldWG::SendInitWorldStatesTo(Player* player)
{
    WorldPacket data(SMSG_INIT_WORLD_STATES, (4 + 4 + 4 + 2 + (BuildingsInZone.size() * 8) + (WorkshopsList.size() * 8)));

    data << uint32(m_MapId);
    data << uint32(m_ZoneId);
    data << uint32(0);
    data << uint16(10 + BuildingsInZone.size() + WorkshopsList.size()); // Number of fields

    FillInitialWorldStates(data);

    player->SendDirectMessage(&data);
}

void BattlefieldWG::SendInitWorldStatesToAll()
{
    for (uint8 team = 0; team < 2; team++)
        for (GuidSet::iterator itr = m_players[team].begin(); itr != m_players[team].end(); ++itr)
            if (Player* player = sObjectAccessor->FindPlayer(*itr))
                SendInitWorldStatesTo(player);
}

void BattlefieldWG::BrokenWallOrTower(TeamId /*team*/)
{
// might be some use for this in the future. old code commented out below. KL
/*    if (team == GetDefenderTeam())
    {
        for (GuidSet::const_iterator itr = m_PlayersInWar[GetAttackerTeam()].begin(); itr != m_PlayersInWar[GetAttackerTeam()].end(); ++itr)
        {
            if (Player* player = sObjectAccessor->FindPlayer(*itr))
                IncrementQuest(player, WGQuest[player->GetTeamId()][2], true);
        }
    }*/
}

// Called when a tower is broke
void BattlefieldWG::UpdatedDestroyedTowerCount(TeamId team)
{
    // Destroy an attack tower
    if (team == GetAttackerTeam())
    {
        // Update counter
        UpdateData(BATTLEFIELD_WG_DATA_DAMAGED_TOWER_ATT, -1);
        UpdateData(BATTLEFIELD_WG_DATA_BROKEN_TOWER_ATT, 1);

        // Remove buff stack on attackers
        for (GuidSet::const_iterator itr = m_PlayersInWar[GetAttackerTeam()].begin(); itr != m_PlayersInWar[GetAttackerTeam()].end(); ++itr)
            if (Player* player = sObjectAccessor->FindPlayer(*itr))
                player->RemoveAuraFromStack(SPELL_TOWER_CONTROL);

        // Add buff stack to defenders
        for (GuidSet::const_iterator itr = m_PlayersInWar[GetDefenderTeam()].begin(); itr != m_PlayersInWar[GetDefenderTeam()].end(); ++itr)
            if (Player* player = sObjectAccessor->FindPlayer(*itr))
            {
                player->CastSpell(player, SPELL_TOWER_CONTROL, true);
                DoCompleteOrIncrementAchievement(ACHIEVEMENTS_WG_TOWER_DESTROY, player);
            }

        // If all three south towers are destroyed (ie. all attack towers), remove ten minutes from battle time
        if (GetData(BATTLEFIELD_WG_DATA_BROKEN_TOWER_ATT) == 3)
        {
            if (int32(m_Timer - 600000) < 0)
                m_Timer = 0;
            else
                m_Timer -= 600000;
            SendInitWorldStatesToAll();
        }
    }
    else
    {
        UpdateData(BATTLEFIELD_WG_DATA_DAMAGED_TOWER_DEF, -1);
        UpdateData(BATTLEFIELD_WG_DATA_BROKEN_TOWER_DEF, 1);
    }
}

void BattlefieldWG::ProcessEvent(WorldObject* obj, uint32 eventId)
{
    if (!obj || !IsWarTime())
        return;

    // We handle only gameobjects here
    GameObject* go = obj->ToGameObject();
    if (!go)
        return;

    // On click on titan relic
    if (go->GetEntry() == GO_WINTERGRASP_TITAN_S_RELIC)
    {
        if (CanInteractWithRelic())
            EndBattle(false);
        else if (GameObject* relic = GetRelic())
            relic->SetRespawnTime(RESPAWN_IMMEDIATELY);
    }

    // if destroy or damage event, search the wall/tower and update worldstate/send warning message
    for (GameObjectBuilding::const_iterator itr = BuildingsInZone.begin(); itr != BuildingsInZone.end(); ++itr)
    {
        if (GameObject* build = GetGameObject((*itr)->m_BuildGUID))
        {
            if (go->GetEntry() == build->GetEntry())
            {
                if (build->GetGOInfo()->building.damagedEvent == eventId)
                    (*itr)->Damaged();

                if (build->GetGOInfo()->building.destroyedEvent == eventId)
                    (*itr)->Destroyed();

                break;
            }
        }
    }
}

// Called when a tower is damaged, used for honor reward calcul
void BattlefieldWG::UpdateDamagedTowerCount(TeamId team)
{
    if (team == GetAttackerTeam())
        UpdateData(BATTLEFIELD_WG_DATA_DAMAGED_TOWER_ATT, 1);
    else
        UpdateData(BATTLEFIELD_WG_DATA_DAMAGED_TOWER_DEF, 1);
}

// Update vehicle count WorldState to player
void BattlefieldWG::UpdateVehicleCountWG()
{
    SendUpdateWorldState(BATTLEFIELD_WG_WORLD_STATE_VEHICLE_H,     GetData(BATTLEFIELD_WG_DATA_VEHICLE_H));
    SendUpdateWorldState(BATTLEFIELD_WG_WORLD_STATE_MAX_VEHICLE_H, GetData(BATTLEFIELD_WG_DATA_MAX_VEHICLE_H));
    SendUpdateWorldState(BATTLEFIELD_WG_WORLD_STATE_VEHICLE_A,     GetData(BATTLEFIELD_WG_DATA_VEHICLE_A));
    SendUpdateWorldState(BATTLEFIELD_WG_WORLD_STATE_MAX_VEHICLE_A, GetData(BATTLEFIELD_WG_DATA_MAX_VEHICLE_A));
}

void BattlefieldWG::UpdateTenacity()
{
    TeamId team = TEAM_NEUTRAL;
    uint32 alliancePlayers = m_PlayersInWar[TEAM_ALLIANCE].size();
    uint32 hordePlayers = m_PlayersInWar[TEAM_HORDE].size();
    int32 newStack = 0;

    if (alliancePlayers && hordePlayers)
    {
        if (alliancePlayers < hordePlayers)
            newStack = int32((float(hordePlayers / alliancePlayers) - 1) * 4);  // positive, should cast on alliance
        else if (alliancePlayers > hordePlayers)
            newStack = int32((1 - float(alliancePlayers / hordePlayers)) * 4);  // negative, should cast on horde
    }

    if (newStack == int32(m_tenacityStack))
        return;

    if (m_tenacityStack > 0 && newStack <= 0)               // old buff was on alliance
        team = TEAM_ALLIANCE;
    else if (newStack >= 0)                                 // old buff was on horde
        team = TEAM_HORDE;

    m_tenacityStack = newStack;
    // Remove old buff
    if (team != TEAM_NEUTRAL)
    {
        for (GuidSet::const_iterator itr = m_players[team].begin(); itr != m_players[team].end(); ++itr)
            if (Player* player = sObjectAccessor->FindPlayer(*itr))
                if (player->getLevel() >= m_MinLevel)
                    player->RemoveAurasDueToSpell(SPELL_TENACITY);

        for (GuidSet::const_iterator itr = m_vehicles[team].begin(); itr != m_vehicles[team].end(); ++itr)
            if (Creature* creature = GetCreature(*itr))
                creature->RemoveAurasDueToSpell(SPELL_TENACITY_VEHICLE);
    }

    // Apply new buff
    if (newStack)
    {
        team = newStack > 0 ? TEAM_ALLIANCE : TEAM_HORDE;

        if (newStack < 0)
            newStack = -newStack;
        if (newStack > 20)
            newStack = 20;

        uint32 buff_honor = SPELL_GREATEST_HONOR;
        if (newStack < 15)
            buff_honor = SPELL_GREATER_HONOR;
        if (newStack < 10)
            buff_honor = SPELL_GREAT_HONOR;
        if (newStack < 5)
            buff_honor = 0;

        for (GuidSet::const_iterator itr = m_PlayersInWar[team].begin(); itr != m_PlayersInWar[team].end(); ++itr)
            if (Player* player = sObjectAccessor->FindPlayer(*itr))
                player->SetAuraStack(SPELL_TENACITY, player, newStack);

        for (GuidSet::const_iterator itr = m_vehicles[team].begin(); itr != m_vehicles[team].end(); ++itr)
            if (Creature* creature = GetCreature(*itr))
                creature->SetAuraStack(SPELL_TENACITY_VEHICLE, creature, newStack);

        if (buff_honor != 0)
        {
            for (GuidSet::const_iterator itr = m_PlayersInWar[team].begin(); itr != m_PlayersInWar[team].end(); ++itr)
                if (Player* player = sObjectAccessor->FindPlayer(*itr))
                    player->CastSpell(player, buff_honor, true);
            for (GuidSet::const_iterator itr = m_vehicles[team].begin(); itr != m_vehicles[team].end(); ++itr)
                if (Creature* creature = GetCreature(*itr))
                    creature->CastSpell(creature, buff_honor, true);
        }
    }
}

WintergraspCapturePoint::WintergraspCapturePoint(BattlefieldWG* battlefield, TeamId teamInControl) : BfCapturePoint(battlefield)
{
    m_Bf = battlefield;
    m_team = teamInControl;
    m_Workshop = NULL;
}

void WintergraspCapturePoint::ChangeTeam(TeamId /*oldTeam*/)
{
    ASSERT(m_Workshop);
    m_Workshop->GiveControlTo(m_team, false);
}

BfGraveyardWG::BfGraveyardWG(BattlefieldWG* battlefield) : BfGraveyard(battlefield)
{
    m_Bf = battlefield;
    m_GossipTextId = 0;
}

BfWGGameObjectBuilding::BfWGGameObjectBuilding(BattlefieldWG* wg)
{
    m_WG = wg;
    m_Team = 0;
    m_BuildGUID = 0;
    m_Type = 0;
    m_WorldState = 0;
    m_State = 0;
    m_NameId = 0;
}

void BfWGGameObjectBuilding::Rebuild()
{
    switch (m_Type)
    {
        case BATTLEFIELD_WG_OBJECTTYPE_KEEP_TOWER:
        case BATTLEFIELD_WG_OBJECTTYPE_DOOR_LAST:
        case BATTLEFIELD_WG_OBJECTTYPE_DOOR:
        case BATTLEFIELD_WG_OBJECTTYPE_WALL:
            m_Team = m_WG->GetDefenderTeam();           // Objects that are part of the keep should be the defender's
            break;
        case BATTLEFIELD_WG_OBJECTTYPE_TOWER:
            m_Team = m_WG->GetAttackerTeam();           // The towers in the south should be the attacker's
            break;
        default:
            m_Team = TEAM_NEUTRAL;
            break;
    }

    if (GameObject* build = m_WG->GetGameObject(m_BuildGUID))
    {
        // Rebuild gameobject
        if (build->IsDestructibleBuilding())
        {
            build->SetDestructibleState(GO_DESTRUCTIBLE_REBUILDING, NULL, true);
            if (build->GetEntry() == GO_WINTERGRASP_VAULT_GATE)
                if (GameObject* go = build->FindNearestGameObject(GO_WINTERGRASP_KEEP_COLLISION_WALL, 50.0f))
                    go->SetGoState(GO_STATE_READY);

            // Update worldstate
            m_State = BATTLEFIELD_WG_OBJECTSTATE_ALLIANCE_INTACT - (m_Team * 3);
            m_WG->SendUpdateWorldState(m_WorldState, m_State);
        }
        UpdateCreatureAndGo();
        build->SetFaction(WintergraspFaction[m_Team]);
    }
}

void BfWGGameObjectBuilding::Damaged()
{
    // Update worldstate
    m_State = BATTLEFIELD_WG_OBJECTSTATE_ALLIANCE_DAMAGE - (m_Team * 3);
    m_WG->SendUpdateWorldState(m_WorldState, m_State);

    // Send warning message
    if (m_NameId)                                       // tower damage + name
        m_WG->SendWarningToAllInZone(m_NameId);

    for (uint64 guid : m_CreatureTopList[m_WG->GetAttackerTeam()])
        if (Creature* creature = m_WG->GetCreature(guid))
            m_WG->HideNpc(creature);

    for (uint64 guid : m_TurretTopList)
        if (Creature* creature = m_WG->GetCreature(guid))
            m_WG->HideNpc(creature);

    if (m_Type == BATTLEFIELD_WG_OBJECTTYPE_KEEP_TOWER)
        m_WG->UpdateDamagedTowerCount(m_WG->GetDefenderTeam());
    else if (m_Type == BATTLEFIELD_WG_OBJECTTYPE_TOWER)
        m_WG->UpdateDamagedTowerCount(m_WG->GetAttackerTeam());
}

void BfWGGameObjectBuilding::Destroyed()
{
    // Update worldstate
    m_State = BATTLEFIELD_WG_OBJECTSTATE_ALLIANCE_DESTROY - (m_Team * 3);
    m_WG->SendUpdateWorldState(m_WorldState, m_State);

    // Warn players
    if (m_NameId)
        m_WG->SendWarningToAllInZone(m_NameId);

    switch (m_Type)
    {
        // Inform the global wintergrasp script of the destruction of this object
        case BATTLEFIELD_WG_OBJECTTYPE_TOWER:
        case BATTLEFIELD_WG_OBJECTTYPE_KEEP_TOWER:
            m_WG->UpdatedDestroyedTowerCount(TeamId(m_Team));
            break;
        case BATTLEFIELD_WG_OBJECTTYPE_DOOR_LAST:
            if (GameObject* build = m_WG->GetGameObject(m_BuildGUID))
                if (GameObject* go = build->FindNearestGameObject(GO_WINTERGRASP_KEEP_COLLISION_WALL, 50.0f))
                    go->SetGoState(GO_STATE_ACTIVE);
            m_WG->SetRelicInteractible(true);
            if (m_WG->GetRelic())
                m_WG->GetRelic()->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
            else
                TC_LOG_ERROR("misc", "BattlefieldWG: Relic not found.");
            break;
    }

    m_WG->BrokenWallOrTower(TeamId(m_Team));
}

void BfWGGameObjectBuilding::Init(GameObject* go, uint32 type, uint32 worldstate, uint32 nameId)
{
    if (!go)
        return;

    // GameObject associated to object
    m_BuildGUID = go->GetGUID();

    // Type of building (WALL/TOWER/DOOR)
    m_Type = type;

    // WorldState for client (icon on map)
    m_WorldState = worldstate;

    // NameId for Warning text
    m_NameId = nameId;

    switch (m_Type)
    {
        case BATTLEFIELD_WG_OBJECTTYPE_KEEP_TOWER:
        case BATTLEFIELD_WG_OBJECTTYPE_DOOR_LAST:
        case BATTLEFIELD_WG_OBJECTTYPE_DOOR:
        case BATTLEFIELD_WG_OBJECTTYPE_WALL:
            m_Team = m_WG->GetDefenderTeam();           // Objects that are part of the keep should be the defender's
            break;
        case BATTLEFIELD_WG_OBJECTTYPE_TOWER:
            m_Team = m_WG->GetAttackerTeam();           // The towers in the south should be the attacker's
            break;
        default:
            m_Team = TEAM_NEUTRAL;
            break;
    }

    m_State = sWorld->getWorldState(m_WorldState);
    switch (m_State)
    {
        case BATTLEFIELD_WG_OBJECTSTATE_ALLIANCE_INTACT:
        case BATTLEFIELD_WG_OBJECTSTATE_HORDE_INTACT:
            go->SetDestructibleState(GO_DESTRUCTIBLE_REBUILDING, NULL, true);
            break;
        case BATTLEFIELD_WG_OBJECTSTATE_ALLIANCE_DESTROY:
        case BATTLEFIELD_WG_OBJECTSTATE_HORDE_DESTROY:
            go->SetDestructibleState(GO_DESTRUCTIBLE_DESTROYED);
            break;
        case BATTLEFIELD_WG_OBJECTSTATE_ALLIANCE_DAMAGE:
        case BATTLEFIELD_WG_OBJECTSTATE_HORDE_DAMAGE:
            go->SetDestructibleState(GO_DESTRUCTIBLE_DAMAGED);
            break;
    }

    int32 towerId = -1;
    switch (go->GetEntry())
    {
        case GO_WINTERGRASP_FORTRESS_TOWER_1:
            towerId = 0;
            break;
        case GO_WINTERGRASP_FORTRESS_TOWER_2:
            towerId = 1;
            break;
        case GO_WINTERGRASP_FORTRESS_TOWER_3:
            towerId = 2;
            break;
        case GO_WINTERGRASP_FORTRESS_TOWER_4:
            towerId = 3;
            break;
        case GO_WINTERGRASP_SHADOWSIGHT_TOWER:
            towerId = 4;
            break;
        case GO_WINTERGRASP_WINTER_S_EDGE_TOWER:
            towerId = 5;
            break;
        case GO_WINTERGRASP_FLAMEWATCH_TOWER:
            towerId = 6;
            break;
    }

    if (towerId > 3) // Attacker towers
    {
        // Spawn associate gameobjects
        for (uint8 i = 0; i < AttackTowers[towerId - 4].nbObject; i++)
        {
            WintergraspObjectPositionData const& gobData = AttackTowers[towerId - 4].GameObject[i];
            if (GameObject* goHorde = m_WG->SpawnGameObject(gobData.entryHorde, gobData.x, gobData.y, gobData.z, gobData.o))
                m_GameObjectList[TEAM_HORDE].insert(goHorde->GetGUID());
            if (GameObject* goAlliance = m_WG->SpawnGameObject(gobData.entryAlliance, gobData.x, gobData.y, gobData.z, gobData.o))
                m_GameObjectList[TEAM_ALLIANCE].insert(goAlliance->GetGUID());
        }

        // Spawn associate npc bottom
        for (uint8 i = 0; i < AttackTowers[towerId - 4].nbCreatureBottom; i++)
        {
            WintergraspObjectPositionData const& creatureData = AttackTowers[towerId - 4].CreatureBottom[i];
            if (Creature* creature = m_WG->SpawnCreature(creatureData.entryHorde, creatureData.x, creatureData.y, creatureData.z, creatureData.o, TEAM_HORDE))
                m_CreatureBottomList[TEAM_HORDE].insert(creature->GetGUID());
            if (Creature* creature = m_WG->SpawnCreature(creatureData.entryAlliance, creatureData.x, creatureData.y, creatureData.z, creatureData.o, TEAM_ALLIANCE))
                m_CreatureBottomList[TEAM_ALLIANCE].insert(creature->GetGUID());
        }

        // Spawn associate npc top
        for (uint8 i = 0; i < AttackTowers[towerId - 4].nbCreatureTop; i++)
        {
            WintergraspObjectPositionData const& creatureData = AttackTowers[towerId - 4].CreatureTop[i];
            if (Creature* creature = m_WG->SpawnCreature(creatureData.entryHorde, creatureData.x, creatureData.y, creatureData.z, creatureData.o, TEAM_HORDE))
                m_CreatureTopList[TEAM_HORDE].insert(creature->GetGUID());
            if (Creature* creature = m_WG->SpawnCreature(creatureData.entryAlliance, creatureData.x, creatureData.y, creatureData.z, creatureData.o, TEAM_ALLIANCE))
                m_CreatureTopList[TEAM_ALLIANCE].insert(creature->GetGUID());
        }
    }

    if (towerId >= 0)
    {
        // Spawn Turret bottom
        for (uint8 i = 0; i < TowerCannon[towerId].nbTowerCannonBottom; i++)
        {
            Position const& turretPos = TowerCannon[towerId].TowerCannonBottom[i];
            if (Creature* turret = m_WG->SpawnCreature(NPC_WINTERGRASP_TOWER_CANNON, turretPos, TEAM_ALLIANCE))
            {
                m_TowerCannonBottomList.insert(turret->GetGUID());
                switch (go->GetEntry())
                {
                    case GO_WINTERGRASP_FORTRESS_TOWER_1:
                    case GO_WINTERGRASP_FORTRESS_TOWER_2:
                    case GO_WINTERGRASP_FORTRESS_TOWER_3:
                    case GO_WINTERGRASP_FORTRESS_TOWER_4:
                        turret->setFaction(WintergraspFaction[m_WG->GetDefenderTeam()]);
                        break;
                    case GO_WINTERGRASP_SHADOWSIGHT_TOWER:
                    case GO_WINTERGRASP_WINTER_S_EDGE_TOWER:
                    case GO_WINTERGRASP_FLAMEWATCH_TOWER:
                        turret->setFaction(WintergraspFaction[m_WG->GetAttackerTeam()]);
                        break;
                }
                m_WG->HideNpc(turret);
            }
        }

        // Spawn Turret top
        for (uint8 i = 0; i < TowerCannon[towerId].nbTurretTop; i++)
        {
            Position const& towerCannonPos = TowerCannon[towerId].TurretTop[i];
            if (Creature* turret = m_WG->SpawnCreature(NPC_WINTERGRASP_TOWER_CANNON, towerCannonPos, TeamId(0)))
            {
                m_TurretTopList.insert(turret->GetGUID());
                switch (go->GetEntry())
                {
                    case GO_WINTERGRASP_FORTRESS_TOWER_1:
                    case GO_WINTERGRASP_FORTRESS_TOWER_2:
                    case GO_WINTERGRASP_FORTRESS_TOWER_3:
                    case GO_WINTERGRASP_FORTRESS_TOWER_4:
                        turret->setFaction(WintergraspFaction[m_WG->GetDefenderTeam()]);
                        break;
                    case GO_WINTERGRASP_SHADOWSIGHT_TOWER:
                    case GO_WINTERGRASP_WINTER_S_EDGE_TOWER:
                    case GO_WINTERGRASP_FLAMEWATCH_TOWER:
                        turret->setFaction(WintergraspFaction[m_WG->GetAttackerTeam()]);
                        break;
                }
                m_WG->HideNpc(turret);
            }
        }
        UpdateCreatureAndGo();
    }
}

void BfWGGameObjectBuilding::UpdateCreatureAndGo()
{
    for (uint64 guid : m_CreatureTopList[m_WG->GetDefenderTeam()])
        if (Creature* creature = m_WG->GetCreature(guid))
            m_WG->HideNpc(creature);

    for (uint64 guid : m_CreatureTopList[m_WG->GetAttackerTeam()])
        if (Creature* creature = m_WG->GetCreature(guid))
            m_WG->ShowNpc(creature, true);

    for (uint64 guid : m_CreatureBottomList[m_WG->GetDefenderTeam()])
        if (Creature* creature = m_WG->GetCreature(guid))
            m_WG->HideNpc(creature);

    for (uint64 guid : m_CreatureBottomList[m_WG->GetAttackerTeam()])
        if (Creature* creature = m_WG->GetCreature(guid))
            m_WG->ShowNpc(creature, true);

    for (uint64 guid : m_GameObjectList[m_WG->GetDefenderTeam()])
        if (GameObject* object = m_WG->GetGameObject(guid))
            object->SetRespawnTime(RESPAWN_ONE_DAY);

    for (uint64 guid : m_GameObjectList[m_WG->GetAttackerTeam()])
        if (GameObject* object = m_WG->GetGameObject(guid))
            object->SetRespawnTime(RESPAWN_IMMEDIATELY);
}

void BfWGGameObjectBuilding::UpdateTurretAttack(bool disable)
{
    for (uint64 guid : m_TowerCannonBottomList)
    {
        if (Creature* creature = m_WG->GetCreature(guid))
        {
            if (GameObject* build = m_WG->GetGameObject(m_BuildGUID))
            {
                if (disable)
                    m_WG->HideNpc(creature);
                else
                    m_WG->ShowNpc(creature, true);

                switch (build->GetEntry())
                {
                    case GO_WINTERGRASP_FORTRESS_TOWER_1:
                    case GO_WINTERGRASP_FORTRESS_TOWER_2:
                    case GO_WINTERGRASP_FORTRESS_TOWER_3:
                    case GO_WINTERGRASP_FORTRESS_TOWER_4:
                    {
                        creature->setFaction(WintergraspFaction[m_WG->GetDefenderTeam()]);
                        break;
                    }
                    case GO_WINTERGRASP_SHADOWSIGHT_TOWER:
                    case GO_WINTERGRASP_WINTER_S_EDGE_TOWER:
                    case GO_WINTERGRASP_FLAMEWATCH_TOWER:
                    {
                        creature->setFaction(WintergraspFaction[m_WG->GetAttackerTeam()]);
                        break;
                    }
                }
            }
        }
    }

    for (uint64 guid : m_TurretTopList)
    {
        if (Creature* creature = m_WG->GetCreature(guid))
        {
            if (GameObject* build = m_WG->GetGameObject(m_BuildGUID))
            {
                if (disable)
                    m_WG->HideNpc(creature);
                else
                    m_WG->ShowNpc(creature, true);

                switch (build->GetEntry())
                {
                    case GO_WINTERGRASP_FORTRESS_TOWER_1:
                    case GO_WINTERGRASP_FORTRESS_TOWER_2:
                    case GO_WINTERGRASP_FORTRESS_TOWER_3:
                    case GO_WINTERGRASP_FORTRESS_TOWER_4:
                    {
                        creature->setFaction(WintergraspFaction[m_WG->GetDefenderTeam()]);
                        break;
                    }
                    case GO_WINTERGRASP_SHADOWSIGHT_TOWER:
                    case GO_WINTERGRASP_WINTER_S_EDGE_TOWER:
                    case GO_WINTERGRASP_FLAMEWATCH_TOWER:
                    {
                        creature->setFaction(WintergraspFaction[m_WG->GetAttackerTeam()]);
                        break;
                    }
                }
            }
        }
    }
}

void BfWGGameObjectBuilding::Save()
{
    sWorld->setWorldState(m_WorldState, m_State);
}

WGWorkshop::WGWorkshop(BattlefieldWG* _bf, uint8 _workshopId)
{
    ASSERT(_bf || _workshopId < WG_MAX_WORKSHOP);

    bf = _bf;
    workshopId = _workshopId;
    teamControl = BATTLEFIELD_WG_TEAM_NEUTRAL;
    state = BATTLEFIELD_WG_OBJECTSTATE_NONE;
}

void WGWorkshop::GiveControlTo(uint8 team, bool init)
{
    switch (team)
    {
        case BATTLEFIELD_WG_TEAM_NEUTRAL:
        {
            // Send warning message to all player to inform a faction attack to a workshop
            // alliance / horde attacking a workshop
            bf->SendWarningToAllInZone(teamControl ? WorkshopsData[workshopId].text : WorkshopsData[workshopId].text + 1);
            break;
        }
        case BATTLEFIELD_WG_TEAM_ALLIANCE:
        case BATTLEFIELD_WG_TEAM_HORDE:
        {
            // Updating worldstate
            state = team == BATTLEFIELD_WG_TEAM_ALLIANCE ? BATTLEFIELD_WG_OBJECTSTATE_ALLIANCE_INTACT : BATTLEFIELD_WG_OBJECTSTATE_HORDE_INTACT;
            bf->SendUpdateWorldState(WorkshopsData[workshopId].worldstate, state);

            // Warning message
            if (!init)                              // workshop taken - alliance
                bf->SendWarningToAllInZone(team == BATTLEFIELD_WG_TEAM_ALLIANCE ? WorkshopsData[workshopId].text : WorkshopsData[workshopId].text + 1);

            // Found associate graveyard and update it
            if (workshopId < BATTLEFIELD_WG_WORKSHOP_KEEP_WEST)
                if (bf->GetGraveyardById(workshopId))
                    bf->GetGraveyardById(workshopId)->GiveControlTo(team == BATTLEFIELD_WG_TEAM_ALLIANCE ? TEAM_ALLIANCE : TEAM_HORDE);

            teamControl = team;
            break;
        }
    }

    if (!init)
        bf->UpdateCounterVehicle(false);
}

void WGWorkshop::UpdateGraveyardAndWorkshop()
{
    if (workshopId < BATTLEFIELD_WG_WORKSHOP_KEEP_WEST)
        bf->GetGraveyardById(workshopId)->GiveControlTo(TeamId(teamControl));
    else
        GiveControlTo(bf->GetDefenderTeam(), true);
}

void WGWorkshop::Save()
{
    sWorld->setWorldState(WorkshopsData[workshopId].worldstate, state);
}

WintergraspWorkshopData::WintergraspWorkshopData(BattlefieldWG* wg)
{
    m_WG = wg;
    m_BuildGUID = 0;
    m_Type = 0;
    m_State = 0;
    m_WorldState = 0;
    m_TeamControl = 0;
    m_NameId = 0;
}

void WintergraspWorkshopData::AddCreature(WintergraspObjectPositionData const& obj)
{
    if (Creature* creature = m_WG->SpawnCreature(obj.entryHorde, obj.x, obj.y, obj.z, obj.o, TEAM_HORDE))
        m_CreatureOnPoint[TEAM_HORDE].insert(creature->GetGUID());

    if (Creature* creature = m_WG->SpawnCreature(obj.entryAlliance, obj.x, obj.y, obj.z, obj.o, TEAM_ALLIANCE))
        m_CreatureOnPoint[TEAM_ALLIANCE].insert(creature->GetGUID());
}

void WintergraspWorkshopData::AddGameObject(WintergraspObjectPositionData const& obj)
{
    if (GameObject* gameobject = m_WG->SpawnGameObject(obj.entryHorde, obj.x, obj.y, obj.z, obj.o))
        m_GameObjectOnPoint[TEAM_HORDE].insert(gameobject->GetGUID());
    if (GameObject* gameobject = m_WG->SpawnGameObject(obj.entryAlliance, obj.x, obj.y, obj.z, obj.o))
        m_GameObjectOnPoint[TEAM_ALLIANCE].insert(gameobject->GetGUID());
}

void WintergraspWorkshopData::Init(uint32 worldstate, uint32 type, uint32 nameId)
{
    m_WorldState = worldstate;
    m_Type = type;
    m_NameId = nameId;
}

void WintergraspWorkshopData::GiveControlTo(uint8 team, bool init)
{
    switch (team)
    {
        case BATTLEFIELD_WG_TEAM_NEUTRAL:
        {
            // Send warning message to all player for inform a faction attack a workshop
            // alliance / horde attacking workshop
            m_WG->SendWarningToAllInZone(m_TeamControl ? m_NameId : m_NameId + 1);
            break;
        }
        case BATTLEFIELD_WG_TEAM_ALLIANCE:
        {
            // Show Alliance creature
            for (uint64 guid : m_CreatureOnPoint[TEAM_ALLIANCE])
                if (Creature* creature = m_WG->GetCreature(guid))
                    m_WG->ShowNpc(creature, creature->GetEntry() != 30499);

            // Hide Horde creature
            for (uint64 guid : m_CreatureOnPoint[TEAM_HORDE])
                if (Creature* creature = m_WG->GetCreature(guid))
                    m_WG->HideNpc(creature);

            // Show Alliance gameobject
            for (uint64 guid : m_GameObjectOnPoint[TEAM_ALLIANCE])
                if (GameObject* object = m_WG->GetGameObject(guid))
                    object->SetRespawnTime(RESPAWN_IMMEDIATELY);

            // Hide Horde gameobject
            for (uint64 guid : m_GameObjectOnPoint[TEAM_HORDE])
                if (GameObject* object = m_WG->GetGameObject(guid))
                    object->SetRespawnTime(RESPAWN_ONE_DAY);


            // Updating worldstate
            m_State = BATTLEFIELD_WG_OBJECTSTATE_ALLIANCE_INTACT;
            m_WG->SendUpdateWorldState(m_WorldState, m_State);

            // Warning message
            if (!init)                              // workshop taken - alliance
                m_WG->SendWarningToAllInZone(m_NameId);

            // Found associate graveyard and update it
            if (m_Type < BATTLEFIELD_WG_WORKSHOP_KEEP_WEST)
                if (m_WG->GetGraveyardById(m_Type))
                    m_WG->GetGraveyardById(m_Type)->GiveControlTo(TEAM_ALLIANCE);

            m_TeamControl = team;
            break;
        }
        case BATTLEFIELD_WG_TEAM_HORDE:
        {
            // Show Horde creature
            for (uint64 guid : m_CreatureOnPoint[TEAM_HORDE])
                if (Creature* creature = m_WG->GetCreature(guid))
                    m_WG->ShowNpc(creature, creature->GetEntry() != 30400);

            // Hide Alliance creature
            for (uint64 guid : m_CreatureOnPoint[TEAM_ALLIANCE])
                if (Creature* creature = m_WG->GetCreature(guid))
                    m_WG->HideNpc(creature);

            // Hide Alliance gameobject
            for (uint64 guid : m_GameObjectOnPoint[TEAM_ALLIANCE])
                if (GameObject* object = m_WG->GetGameObject(guid))
                    object->SetRespawnTime(RESPAWN_ONE_DAY);

            // Show Horde gameobject
            for (uint64 guid : m_GameObjectOnPoint[TEAM_HORDE])
                if (GameObject* object = m_WG->GetGameObject(guid))
                    object->SetRespawnTime(RESPAWN_IMMEDIATELY);

            // Update worldstate
            m_State = BATTLEFIELD_WG_OBJECTSTATE_HORDE_INTACT;
            m_WG->SendUpdateWorldState(m_WorldState, m_State);

            // Warning message
            if (!init)                              // workshop taken - horde
                m_WG->SendWarningToAllInZone(m_NameId + 1);

            // Update graveyard control
            if (m_Type < BATTLEFIELD_WG_WORKSHOP_KEEP_WEST)
                if (m_WG->GetGraveyardById(m_Type))
                    m_WG->GetGraveyardById(m_Type)->GiveControlTo(TEAM_HORDE);

            m_TeamControl = team;
            break;
        }
    }
    if (!init)
        m_WG->UpdateCounterVehicle(false);
}

void WintergraspWorkshopData::UpdateGraveyardAndWorkshop()
{
    if (m_Type < BATTLEFIELD_WG_WORKSHOP_KEEP_WEST)
        m_WG->GetGraveyardById(m_Type)->GiveControlTo(TeamId(m_TeamControl));
    else
        GiveControlTo(m_WG->GetDefenderTeam(), true);
}

void WintergraspWorkshopData::Save()
{
    sWorld->setWorldState(m_WorldState, m_State);
}
