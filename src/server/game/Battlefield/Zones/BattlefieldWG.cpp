/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

// TODO: Implement proper support for vehicle+player teleportation
// TODO: Use spell victory/defeat in wg instead of RewardMarkOfHonor() && RewardHonor
// TODO: Add proper implement of achievement

#include "ObjectMgr.h"
#include "BattlefieldWG.h"
#include "SpellAuras.h"

enum eWGBfData
{
    BATTLEFIELD_WG_ZONEID                        = 4197,             // Wintergrasp
    BATTLEFIELD_WG_MAPID                         = 571,              // Northrend
};

bool BattlefieldWG::SetupBattlefield()
{
    InitStalker(BATTLEFIELD_WG_NPC_STALKER, WintergraspStalkerPos[0], WintergraspStalkerPos[1], WintergraspStalkerPos[2], WintergraspStalkerPos[3]);

    m_TypeId = BATTLEFIELD_WG;                              // See enum BattlefieldTypes
    m_BattleId = BATTLEFIELD_BATTLEID_WG;
    m_ZoneId = BATTLEFIELD_WG_ZONEID;
    m_MapId = BATTLEFIELD_WG_MAPID;

    m_MaxPlayer = sWorld->getIntConfig(CONFIG_WINTERGRASP_PLR_MAX);
    m_enable = sWorld->getBoolConfig(CONFIG_WINTERGRASP_ENABLE);
    m_MinPlayer = sWorld->getIntConfig(CONFIG_WINTERGRASP_PLR_MIN);
    m_MinLevel = sWorld->getIntConfig(CONFIG_WINTERGRASP_PLR_MIN_LVL);
    m_BattleTime = sWorld->getIntConfig(CONFIG_WINTERGRASP_BATTLETIME) * MINUTE;
    m_NoWarBattleTime = sWorld->getIntConfig(CONFIG_WINTERGRASP_NOBATTLETIME) * MINUTE;
    m_RestartAfterCrash = sWorld->getIntConfig(CONFIG_WINTERGRASP_RESTART_AFTER_CRASH) * MINUTE;

    m_TimeForAcceptInvite = 20;
    m_StartGroupingTimer = 15 * MINUTE;
    m_StartGrouping = false;

    m_tenacityStack = 0;

    KickPosition.Relocate(5728.117f, 2714.346f, 697.733f, 0);
    KickPosition.m_mapId = m_MapId;

    RegisterZone(m_ZoneId);

    m_Data32.resize(BATTLEFIELD_WG_DATA_MAX);

    m_saveTimer = 60000;

    // Init GraveYards
    SetGraveyardNumber(BATTLEFIELD_WG_GY_MAX);

    // Load from db
    if ((sWorld->getWorldState(3801) == 0) && (sWorld->getWorldState(3802) == 0) && (sWorld->getWorldState(ClockWorldState[0]) == 0))
    {
        sWorld->setWorldState(3801, false);
        sWorld->setWorldState(3802, urand(0, 1));
        sWorld->setWorldState(ClockWorldState[0], m_NoWarBattleTime);
    }

    m_BattlefieldActive = sWorld->getWorldState(3801);
    m_DefenderTeam = TeamId(sWorld->getWorldState(3802));

    m_Timer = sWorld->getWorldState(ClockWorldState[0]);
    if (m_BattlefieldActive)
    {
        m_BattlefieldActive = false;
        m_Timer = m_RestartAfterCrash;
    }

    for (uint8 i = 0; i < BATTLEFIELD_WG_GY_MAX; i++)
    {
        BfGraveYardWG *gy = new BfGraveYardWG(this);
        if (WGGraveYard[i].startcontrol == TEAM_NEUTRAL) // When between games, the graveyard is controlled by the defending team
            gy->Init(NPC_TAUNKA_SPIRIT_GUIDE, NPC_DWARVEN_SPIRIT_GUIDE, WGGraveYard[i].x, WGGraveYard[i].y, WGGraveYard[i].z, WGGraveYard[i].o, m_DefenderTeam, WGGraveYard[i].gyid);
        else
            gy->Init(NPC_TAUNKA_SPIRIT_GUIDE, NPC_DWARVEN_SPIRIT_GUIDE, WGGraveYard[i].x, WGGraveYard[i].y, WGGraveYard[i].z, WGGraveYard[i].o, WGGraveYard[i].startcontrol, WGGraveYard[i].gyid);
        gy->SetTextId(WGGraveYard[i].textid);
        m_GraveYardList[i] = gy;
    }

    // Spawn workshop creatures and gameobjects
    for (uint8 i = 0; i < WG_MAX_WORKSHOP; i++)
    {
        BfWGWorkShopData *ws = new BfWGWorkShopData(this);      // Create new object
        // Init:setup variable
        ws->Init(WGWorkShopDataBase[i].worldstate, WGWorkShopDataBase[i].type, WGWorkShopDataBase[i].nameid);
        // Spawn associate npc on this point (Guard/Engineer)
        for (uint8 c = 0; c < WGWorkShopDataBase[i].nbcreature; c++)
            ws->AddCreature(WGWorkShopDataBase[i].CreatureData[c]);

        // Spawn associate gameobject on this point (Horde/Alliance flags)
        for (uint8 g = 0; g < WGWorkShopDataBase[i].nbgob; g++)
            ws->AddGameObject(WGWorkShopDataBase[i].GameObjectData[g]);

        // Create PvPCapturePoint
        if (WGWorkShopDataBase[i].type < BATTLEFIELD_WG_WORKSHOP_KEEP_WEST)
        {
            ws->ChangeControl(GetAttackerTeam(), true);     // Update control of this point 
            // Create Object
            BfCapturePointWG *workshop = new BfCapturePointWG(this, GetAttackerTeam());
            // Spawn gameobject associate (see in OnGameObjectCreate, of OutdoorPvP for see association)
            workshop->SetCapturePointData(WGWorkShopDataBase[i].CapturePoint.entryh, 571,
                                          WGWorkShopDataBase[i].CapturePoint.x, WGWorkShopDataBase[i].CapturePoint.y, WGWorkShopDataBase[i].CapturePoint.z, 0);
            workshop->LinkToWorkShop(ws);                   // Link our point to the capture point (for faction changement)
            AddCapturePoint(workshop);                      // Add this capture point to list for update this (view in Update() of OutdoorPvP)
        }
        else
            ws->ChangeControl(GetDefenderTeam(), true);     // Update control of this point (Keep workshop= to deffender team)

        WorkShopList.insert(ws);
    }
    // Spawning npc in keep
    for (uint8 i = 0; i < WG_MAX_KEEP_NPC; i++)
    {
        // Horde npc
        if (Creature* creature = SpawnCreature(WGKeepNPC[i].entryh, WGKeepNPC[i].x, WGKeepNPC[i].y, WGKeepNPC[i].z, WGKeepNPC[i].o, TEAM_HORDE))
            KeepCreature[TEAM_HORDE].insert(creature->GetGUID());
        // Alliance npc
        if (Creature* creature = SpawnCreature(WGKeepNPC[i].entrya, WGKeepNPC[i].x, WGKeepNPC[i].y, WGKeepNPC[i].z, WGKeepNPC[i].o, TEAM_ALLIANCE))
            KeepCreature[TEAM_ALLIANCE].insert(creature->GetGUID());
    }
    // Hide keep npc
    for (GuidSet::const_iterator itr = KeepCreature[GetAttackerTeam()].begin(); itr != KeepCreature[GetAttackerTeam()].end(); ++itr)
        if (Unit* unit = sObjectAccessor->FindUnit((*itr)))
            if (Creature* creature = unit->ToCreature())
                HideNpc(creature);
    // Spawn out of keep npc
    // Horde npc
    for (uint8 i = 0; i < WG_OUTSIDE_ALLIANCE_NPC; i++)
        if (Creature* creature = SpawnCreature(WGOutsideNPC[i].entryh, WGOutsideNPC[i].x, WGOutsideNPC[i].y, WGOutsideNPC[i].z, WGOutsideNPC[i].o, TEAM_HORDE))
            OutsideCreature[TEAM_HORDE].insert(creature->GetGUID());
    // Alliance npc
    for (uint8 i = WG_OUTSIDE_ALLIANCE_NPC; i < WG_MAX_OUTSIDE_NPC; i++)
        if (Creature* creature = SpawnCreature(WGOutsideNPC[i].entrya, WGOutsideNPC[i].x, WGOutsideNPC[i].y, WGOutsideNPC[i].z, WGOutsideNPC[i].o, TEAM_ALLIANCE))
            OutsideCreature[TEAM_ALLIANCE].insert(creature->GetGUID());
    // Hide outside npc
    for (GuidSet::const_iterator itr = OutsideCreature[GetDefenderTeam()].begin(); itr != OutsideCreature[GetDefenderTeam()].end(); ++itr)
        if (Unit* unit = sObjectAccessor->FindUnit((*itr)))
            if (Creature* creature = unit->ToCreature())
                HideNpc(creature);
    for (uint8 i = 0; i < WG_MAX_TURRET; i++)
    {
        if (Creature* creature = SpawnCreature(28366, WGTurret[i].x, WGTurret[i].y, WGTurret[i].z, WGTurret[i].o, TeamId(0)))
        {
            CanonList.insert(creature->GetGUID());
            HideNpc(creature);
        }
    }
    // Spawning Buiding
    for (uint8 i = 0; i < WG_MAX_OBJ; i++)
    {
        GameObject* go =
            SpawnGameObject(WGGameObjectBuillding[i].entry, WGGameObjectBuillding[i].x, WGGameObjectBuillding[i].y, WGGameObjectBuillding[i].z, WGGameObjectBuillding[i].o);
        BfWGGameObjectBuilding *b = new BfWGGameObjectBuilding(this);
        b->Init(go, WGGameObjectBuillding[i].type, WGGameObjectBuillding[i].WorldState, WGGameObjectBuillding[i].nameid);
        BuildingsInZone.insert(b);
    }
    // Spawning portal defender
    for (uint8 i = 0; i < WG_MAX_TELEPORTER; i++)
    {
        GameObject* go = SpawnGameObject(WGPortalDefenderData[i].entry, WGPortalDefenderData[i].x, WGPortalDefenderData[i].y, WGPortalDefenderData[i].z, WGPortalDefenderData[i].o);
        DefenderPortalList.insert(go);
        go->SetUInt32Value(GAMEOBJECT_FACTION, WintergraspFaction[GetDefenderTeam()]);
    }

    // Spawn banner in keep
    for (uint8 i = 0; i < WG_KEEPGAMEOBJECT_MAX; i++)
    {
        if (GameObject* go = SpawnGameObject(WGKeepGameObject[i].entryh, WGKeepGameObject[i].x, WGKeepGameObject[i].y, WGKeepGameObject[i].z, WGKeepGameObject[i].o))
        {
            go->SetRespawnTime(GetDefenderTeam()? RESPAWN_ONE_DAY : RESPAWN_IMMEDIATELY);
            m_KeepGameObject[1].insert(go);
        }
        if (GameObject* go = SpawnGameObject(WGKeepGameObject[i].entrya, WGKeepGameObject[i].x, WGKeepGameObject[i].y, WGKeepGameObject[i].z, WGKeepGameObject[i].o))
        {
            go->SetRespawnTime(GetDefenderTeam()? RESPAWN_IMMEDIATELY : RESPAWN_ONE_DAY);
            m_KeepGameObject[0].insert(go);
        }
    }

    // Show defender banner in keep
    for (GameObjectSet::const_iterator itr = m_KeepGameObject[GetDefenderTeam()].begin(); itr != m_KeepGameObject[GetDefenderTeam()].end(); ++itr)
        (*itr)->SetRespawnTime(RESPAWN_IMMEDIATELY);

    // Hide attackant banner in keep
    for (GameObjectSet::const_iterator itr = m_KeepGameObject[GetAttackerTeam()].begin(); itr != m_KeepGameObject[GetAttackerTeam()].end(); ++itr)
        (*itr)->SetRespawnTime(RESPAWN_ONE_DAY);

    UpdateCounterVehicle(true);
    return true;
}

bool BattlefieldWG::Update(uint32 diff)
{
    bool m_return = Battlefield::Update(diff);
    if (m_saveTimer <= diff)
    {
        sWorld->setWorldState(3801, m_BattlefieldActive);
        sWorld->setWorldState(3802, m_DefenderTeam);
        sWorld->setWorldState(ClockWorldState[0], m_Timer);
        m_saveTimer = 60 * IN_MILLISECONDS;
    }
    else
        m_saveTimer -= diff;

    for (GuidSet::const_iterator itr = m_PlayersIsSpellImu.begin(); itr != m_PlayersIsSpellImu.end(); ++itr)
        if (Player* player = sObjectMgr->GetPlayer((*itr)))
        {
            if (player->HasAura(SPELL_SPIRITUAL_IMMUNITY))
            {
                const WorldSafeLocsEntry *graveyard = GetClosestGraveYard(player);
                if (graveyard)
                {
                    if (player->GetDistance2d(graveyard->x, graveyard->y) > 10.0f)
                    {
                        player->RemoveAurasDueToSpell(SPELL_SPIRITUAL_IMMUNITY);
                        m_PlayersIsSpellImu.erase(player->GetGUID());
                    }
                }
            }
        }

    if (m_BattlefieldActive)
    {
        for (uint8 team = 0; team < 2; ++team)
            for (GuidSet::const_iterator itr = m_vehicles[team].begin(); itr != m_vehicles[team].end(); ++itr)
                if (Unit* unit = sObjectAccessor->FindUnit((*itr)))
                {
                    if (unit->IsInWater() && !unit->HasAura(SPELL_WINTERGRASP_WATER))
                        unit->AddAura(SPELL_WINTERGRASP_WATER, unit);
                    if (!unit->IsInWater() && unit->HasAura(SPELL_WINTERGRASP_WATER))
                        unit->RemoveAurasDueToSpell(SPELL_WINTERGRASP_WATER);
                }

    }

    for (uint8 team = 0; team < 2; ++team)
        for (GuidSet::const_iterator itr = m_players[team].begin(); itr != m_players[team].end(); ++itr)
            if (Player* player = sObjectMgr->GetPlayer((*itr)))
                for (BfCapturePointMap::iterator cp_itr = m_capturePoints.begin(); cp_itr != m_capturePoints.end(); ++cp_itr)
                {
                    if ((*cp_itr).second->GetCapturePointGo()->GetExactDist2dSq(player) < 22500.0f) // 150*150
                    {
                        player->AddAura((*cp_itr).second->GetTeamId() == TEAM_HORDE ? SPELL_HORDE_CONTROLS_FACTORY_PHASE_SHIFT : SPELL_ALLIANCE_CONTROLS_FACTORY_PHASE_SHIFT, player);
                        player->RemoveAurasDueToSpell((*cp_itr).second->GetTeamId() == TEAM_ALLIANCE ? SPELL_HORDE_CONTROLS_FACTORY_PHASE_SHIFT : SPELL_ALLIANCE_CONTROLS_FACTORY_PHASE_SHIFT);
                        break;
                    }
                }

    return m_return;
}

void BattlefieldWG::AddPlayerToResurrectQueue(uint64 npc_guid, uint64 player_guid)
{
    Battlefield::AddPlayerToResurrectQueue(npc_guid, player_guid);
    if (IsWarTime())
    {
        if (Player* player = sObjectMgr->GetPlayer(player_guid))
        {
            if (!player->HasAura(SPELL_SPIRITUAL_IMMUNITY))
            {
                player->CastSpell(player, SPELL_SPIRITUAL_IMMUNITY, true);
                m_PlayersIsSpellImu.insert(player->GetGUID());
            }
        }
    }
}

void BattlefieldWG::OnBattleStart()
{
    // Spawn titan relic
    m_relic = SpawnGameObject(BATTLEFIELD_WG_GAMEOBJECT_TITAN_RELIC, 5440.0f, 2840.8f, 430.43f, 0);
    if (m_relic)
    {
        // Update faction of relic, only attacker can click on
        m_relic->SetUInt32Value(GAMEOBJECT_FACTION, WintergraspFaction[GetAttackerTeam()]);
        // Set in use (not allow to click on before last door is broken)
        m_relic->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
    }
    else
        sLog->outError("WG: Failed to spawn titan relic.");


    // Update tower visibility and update faction
    for (GuidSet::const_iterator itr = CanonList.begin(); itr != CanonList.end(); ++itr)
    {
        if (Unit* unit = sObjectAccessor->FindUnit((*itr)))
        {
            if (Creature* creature = unit->ToCreature())
            {
                ShowNpc(creature, true);
                creature->setFaction(WintergraspFaction[GetDefenderTeam()]);
            }
        }
    }

    // Rebuild all wall
    for (GameObjectBuilding::const_iterator itr = BuildingsInZone.begin(); itr != BuildingsInZone.end(); ++itr)
    {
        if ((*itr))
        {
            (*itr)->Rebuild();
            (*itr)->UpdateTurretAttack(false);
        }
    }

    m_Data32[BATTLEFIELD_WG_DATA_BROKEN_TOWER_ATT] = 0;
    m_Data32[BATTLEFIELD_WG_DATA_BROKEN_TOWER_DEF] = 0;
    m_Data32[BATTLEFIELD_WG_DATA_DAMAGED_TOWER_ATT] = 0;
    m_Data32[BATTLEFIELD_WG_DATA_DAMAGED_TOWER_DEF] = 0;

    // Update graveyard (in no war time all graveyard is to deffender, in war time, depend of base)
    for (WorkShop::const_iterator itr = WorkShopList.begin(); itr != WorkShopList.end(); ++itr)
    {
        if ((*itr))
            (*itr)->UpdateGraveYardAndWorkshop();
    }

    for (uint8 team = 0; team < 2; ++team)
        for (GuidSet::const_iterator p_itr = m_players[team].begin(); p_itr != m_players[team].end(); ++p_itr)
        {
            // Kick player in orb room, TODO: offline player ?
            if (Player* player = sObjectMgr->GetPlayer((*p_itr)))
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
        m_Data32[BATTLEFIELD_WG_DATA_VEHICLE_H] = 0;
        m_Data32[BATTLEFIELD_WG_DATA_VEHICLE_A] = 0;
    }
    m_Data32[BATTLEFIELD_WG_DATA_MAX_VEHICLE_H] = 0;
    m_Data32[BATTLEFIELD_WG_DATA_MAX_VEHICLE_A] = 0;

    for (WorkShop::const_iterator itr = WorkShopList.begin(); itr != WorkShopList.end(); ++itr)
    {
        if (BfWGWorkShopData * workshop = (*itr))
        {
            if (workshop->m_TeamControl == TEAM_ALLIANCE)
                m_Data32[BATTLEFIELD_WG_DATA_MAX_VEHICLE_A] = m_Data32[BATTLEFIELD_WG_DATA_MAX_VEHICLE_A] + 4;
            else if (workshop->m_TeamControl == TEAM_HORDE)
                m_Data32[BATTLEFIELD_WG_DATA_MAX_VEHICLE_H] = m_Data32[BATTLEFIELD_WG_DATA_MAX_VEHICLE_H] + 4;
        }
    }

    UpdateVehicleCountWG();
}

void BattlefieldWG::OnBattleEnd(bool endbytimer)
{
    // Remove relic
    if (m_relic)
        m_relic->RemoveFromWorld();
    m_relic = NULL;

    // Remove turret
    for (GuidSet::const_iterator itr = CanonList.begin(); itr != CanonList.end(); ++itr)
    {
        if (Unit* unit = sObjectAccessor->FindUnit((*itr)))
        {
            if (Creature* creature = unit->ToCreature())
            {
                if (!endbytimer)
                    creature->setFaction(WintergraspFaction[GetDefenderTeam()]);
                HideNpc(creature);
            }
        }
    }

    // If endbytimer is false, battle is end by clicking on relic
    if (!endbytimer)
    {
        // Change all npc in keep
        for (GuidSet::const_iterator itr = KeepCreature[GetAttackerTeam()].begin(); itr != KeepCreature[GetAttackerTeam()].end(); ++itr)
        {
            if (Unit* unit = sObjectAccessor->FindUnit((*itr)))
                if (Creature* creature = unit->ToCreature())
                    HideNpc(creature);
        }
        for (GuidSet::const_iterator itr = KeepCreature[GetDefenderTeam()].begin(); itr != KeepCreature[GetDefenderTeam()].end(); ++itr)
        {
            if (Unit* unit = sObjectAccessor->FindUnit((*itr)))
                if (Creature* creature = unit->ToCreature())
                    ShowNpc(creature, true);
        }
        // Change all npc out of keep
        for (GuidSet::const_iterator itr = OutsideCreature[GetDefenderTeam()].begin(); itr != OutsideCreature[GetDefenderTeam()].end(); ++itr)
        {
            if (Unit* unit = sObjectAccessor->FindUnit((*itr)))
                if (Creature* creature = unit->ToCreature())
                    HideNpc(creature);
        }
        for (GuidSet::const_iterator itr = OutsideCreature[GetAttackerTeam()].begin(); itr != OutsideCreature[GetAttackerTeam()].end(); ++itr)
        {
            if (Unit* unit = sObjectAccessor->FindUnit((*itr)))
                if (Creature* creature = unit->ToCreature())
                    ShowNpc(creature, true);
        }
    }

    // Update all graveyard, control is to defender when no wartime
    for (uint8 i = 0; i < BATTLEFIELD_WG_GY_HORDE; i++)
    {
        if (GetGraveYardById(i))
        {
            GetGraveYardById(i)->ChangeControl(GetDefenderTeam());
        }
    }

    for (GameObjectSet::const_iterator itr = m_KeepGameObject[GetDefenderTeam()].begin(); itr != m_KeepGameObject[GetDefenderTeam()].end(); ++itr)
        (*itr)->SetRespawnTime(RESPAWN_IMMEDIATELY);

    for (GameObjectSet::const_iterator itr = m_KeepGameObject[GetAttackerTeam()].begin(); itr != m_KeepGameObject[GetAttackerTeam()].end(); ++itr)
        (*itr)->SetRespawnTime(RESPAWN_ONE_DAY);

    // Update portal defender faction
    for (GameObjectSet::const_iterator itr = DefenderPortalList.begin(); itr != DefenderPortalList.end(); ++itr)
        (*itr)->SetUInt32Value(GAMEOBJECT_FACTION, WintergraspFaction[GetDefenderTeam()]);

    // Saving data
    for (GameObjectBuilding::const_iterator itr = BuildingsInZone.begin(); itr != BuildingsInZone.end(); ++itr)
        (*itr)->Save();
    for (WorkShop::const_iterator itr = WorkShopList.begin(); itr != WorkShopList.end(); ++itr)
        (*itr)->Save();

    uint32 WinHonor = 0;
    uint32 LossHonor = 0;

    if (!endbytimer)
    {
        WinHonor = 3000 + 400 * m_Data32[BATTLEFIELD_WG_DATA_BROKEN_TOWER_DEF] + 100 * m_Data32[BATTLEFIELD_WG_DATA_DAMAGED_TOWER_DEF];
        LossHonor = 1000 + 400 * m_Data32[BATTLEFIELD_WG_DATA_BROKEN_TOWER_ATT] + 100 * m_Data32[BATTLEFIELD_WG_DATA_DAMAGED_TOWER_ATT];
    }
    else
    {
        WinHonor = 3000 + 400 * m_Data32[BATTLEFIELD_WG_DATA_BROKEN_TOWER_ATT] + 100 * m_Data32[BATTLEFIELD_WG_DATA_DAMAGED_TOWER_ATT];
        LossHonor = 1000 + 400 * m_Data32[BATTLEFIELD_WG_DATA_BROKEN_TOWER_DEF] + 100 * m_Data32[BATTLEFIELD_WG_DATA_DAMAGED_TOWER_DEF];
    }

    for (GuidSet::const_iterator itr = m_PlayersInWar[GetDefenderTeam()].begin(); itr != m_PlayersInWar[GetDefenderTeam()].end(); ++itr)
    {
        if (Player* player = sObjectMgr->GetPlayer((*itr)))
        {
            player->AddAura(SPELL_ESSENCE_OF_WINTERGRASP, player);
            if (player->HasAura(SPELL_LIEUTENANT))
            {
                player->RewardHonor(NULL, 1, WinHonor);
                RewardMarkOfHonor(player, 3);
            }
            else if (player->HasAura(SPELL_CORPORAL))
            {
                player->RewardHonor(NULL, 1, WinHonor);
                RewardMarkOfHonor(player, 2);
            }
            if (player->GetTeamId() == TEAM_HORDE)
                IncrementQuest(player, 13183, true);
            else
                IncrementQuest(player, 13181, true);
            // Send Wintergrasp victory achievement
            DoCompleteOrIncrementAchievement(ACHIEVEMENTS_WIN_WG, player);
            // Award achievement for succeeding in Wintergrasp in 10 minutes or less
            if (!endbytimer && GetTimer() <= 10000)
                DoCompleteOrIncrementAchievement(ACHIEVEMENTS_WIN_WG_TIMER_10, player);
        }
    }
    for (GuidSet::const_iterator itr = m_PlayersInWar[GetAttackerTeam()].begin(); itr != m_PlayersInWar[GetAttackerTeam()].end(); ++itr)
    {
        if (Player* player = sObjectMgr->GetPlayer((*itr)))
        {
            if (player->HasAura(SPELL_LIEUTENANT))
            {
                player->RewardHonor(NULL, 1, LossHonor);
                RewardMarkOfHonor(player, 1);
            }
            else if (player->HasAura(SPELL_CORPORAL))
            {
                player->RewardHonor(NULL, 1, LossHonor);
                RewardMarkOfHonor(player, 1);
            }
        }
    }

    for (uint8 team = 0; team < 2; ++team)
    {
        for (GuidSet::const_iterator itr = m_PlayersInWar[team].begin(); itr != m_PlayersInWar[team].end(); ++itr)
        {
            if (Player* player = sObjectMgr->GetPlayer((*itr)))
            {
                player->RemoveAura(SPELL_TOWER_CONTROL);
                player->RemoveAurasDueToSpell(SPELL_RECRUIT);
                player->RemoveAurasDueToSpell(SPELL_CORPORAL);
                player->RemoveAurasDueToSpell(SPELL_LIEUTENANT);
                player->RemoveAurasDueToSpell(SPELL_TENACITY);
                player->RemoveAurasDueToSpell(SPELL_SPIRITUAL_IMMUNITY);
            }
        }
        m_PlayersInWar[team].clear();

        for (GuidSet::const_iterator itr = m_vehicles[team].begin(); itr != m_vehicles[team].end(); ++itr)
        {
            if (Unit* unit = sObjectAccessor->FindUnit((*itr)))
                if (Creature* creature = unit->ToCreature())
                    if (creature->IsVehicle())
                        creature->GetVehicleKit()->Dismiss();
        }
        m_vehicles[team].clear();
    }

    if (!endbytimer)
    {
        for (uint8 team = 0; team < 2; ++team)
        {
            for (GuidSet::const_iterator itr = m_players[team].begin(); itr != m_players[team].end(); ++itr)
            {
                if (Player* player = sObjectMgr->GetPlayer((*itr)))
                {
                    player->RemoveAurasDueToSpell(m_DefenderTeam == TEAM_ALLIANCE ? SPELL_HORDE_CONTROL_PHASE_SHIFT : SPELL_ALLIANCE_CONTROL_PHASE_SHIFT, player->GetGUID());
                    player->AddAura(m_DefenderTeam == TEAM_HORDE ? SPELL_HORDE_CONTROL_PHASE_SHIFT : SPELL_ALLIANCE_CONTROL_PHASE_SHIFT, player);
                }
            }
        }
    }

    if (!endbytimer)
    {                                                       // win alli/horde
        SendWarningToAllInZone((GetDefenderTeam() == TEAM_ALLIANCE) ? BATTLEFIELD_WG_TEXT_WIN_KEEP : BATTLEFIELD_WG_TEXT_WIN_KEEP + 1);
    }
    else
    {                                                       // defend alli/horde
        SendWarningToAllInZone((GetDefenderTeam() == TEAM_ALLIANCE) ? BATTLEFIELD_WG_TEXT_DEFEND_KEEP : BATTLEFIELD_WG_TEXT_DEFEND_KEEP + 1);
    }
}

// *****************************************************
// *******************Reward System*********************
// *****************************************************
void BattlefieldWG::DoCompleteOrIncrementAchievement(uint32 achievement, Player *player, uint8 /*incrementNumber */ )
{
    AchievementEntry const* AE = GetAchievementStore()->LookupEntry(achievement);

    switch (achievement)
    {
        case ACHIEVEMENTS_WIN_WG_100:
            {
                // player->GetAchievementMgr().UpdateAchievementCriteria();
            }
        default:
            {
                if (player)
                    player->CompletedAchievement(AE);
            }
            break;
    }

}

void BattlefieldWG::RewardMarkOfHonor(Player* player, uint32 count)
{
    // 'Inactive' this aura prevents the player from gaining honor points and battleground tokens
    if (count == 0)
        return;

    ItemPosCountVec dest;
    uint32 no_space_count = 0;
    uint8 msg = player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, WG_MARK_OF_HONOR, count, &no_space_count);

    if (msg == EQUIP_ERR_ITEM_NOT_FOUND)
    {
        return;
    }

    if (msg != EQUIP_ERR_OK)                                // convert to possible store amount
        count -= no_space_count;

    if (count != 0 && !dest.empty())                        // can add some
        if (Item * item = player->StoreNewItem(dest, WG_MARK_OF_HONOR, true, 0))
            player->SendNewItem(item, count, true, false);
}

void BattlefieldWG::OnStartGrouping()
{
    // Warn
    SendWarningToAllInZone(BATTLEFIELD_WG_TEXT_WILL_START);
}

void BattlefieldWG::OnCreatureCreate(Creature *creature, bool add)
{
    if (IsWarTime())
    {
        switch (creature->GetEntry())
        {
            case 28312:
            case 32627:
            case 27881:
            case 28094:
                {
                    uint8 team;
                    if (creature->getFaction() == WintergraspFaction[TEAM_ALLIANCE])
                        team = TEAM_ALLIANCE;
                    else if (creature->getFaction() == WintergraspFaction[TEAM_HORDE])
                        team = TEAM_HORDE;
                    else
                        return;

                    if (add)
                    {
                        if (team == TEAM_HORDE)
                        {
                            m_Data32[BATTLEFIELD_WG_DATA_VEHICLE_H]++;
                            if (GetData(BATTLEFIELD_WG_DATA_VEHICLE_H) <= GetData(BATTLEFIELD_WG_DATA_MAX_VEHICLE_H))
                            {
                                creature->AddAura(SPELL_HORDE_FLAG, creature);
                                m_vehicles[team].insert(creature->GetGUID());
                                UpdateVehicleCountWG();
                            }
                            else
                            {
                                creature->setDeathState(DEAD);
                                creature->SetRespawnTime(RESPAWN_ONE_DAY);
                                return;
                            }
                        }
                        else
                        {
                            m_Data32[BATTLEFIELD_WG_DATA_VEHICLE_A]++;
                            if (GetData(BATTLEFIELD_WG_DATA_VEHICLE_A) <= GetData(BATTLEFIELD_WG_DATA_MAX_VEHICLE_A))
                            {
                                creature->AddAura(SPELL_ALLIANCE_FLAG, creature);
                                m_vehicles[team].insert(creature->GetGUID());
                                UpdateVehicleCountWG();
                            }
                            else
                            {
                                creature->setDeathState(DEAD);
                                creature->SetRespawnTime(RESPAWN_ONE_DAY);
                                return;
                            }
                        }
                    }
                    else
                    {
                        m_vehicles[team].erase(creature->GetGUID());
                        if (team == TEAM_HORDE)
                            m_Data32[BATTLEFIELD_WG_DATA_VEHICLE_H]--;
                        else
                            m_Data32[BATTLEFIELD_WG_DATA_VEHICLE_A]--;
                        UpdateVehicleCountWG();
                    }
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
    if (victim->GetTypeId() == TYPEID_PLAYER)
    {
        IncrementQuest(killer, WGQuest[killer->GetTeamId()][4]);
        IncrementQuest(killer, WGQuest[killer->GetTeamId()][5]);
        for (GuidSet::const_iterator p_itr = m_PlayersInWar[killer->GetTeamId()].begin(); p_itr != m_PlayersInWar[killer->GetTeamId()].end(); ++p_itr)
        {
            if (Player* player = sObjectAccessor->FindPlayer(*p_itr))
                if (player->GetDistance2d(killer) < 40)
                    PromotePlayer(player);
        }
        return;
    }
    for (GuidSet::const_iterator itr = m_vehicles[killer->GetTeamId()? TEAM_ALLIANCE : TEAM_HORDE].begin();
         itr != m_vehicles[killer->GetTeamId()? TEAM_ALLIANCE : TEAM_HORDE].end(); ++itr)
    {
        if (Unit* unit = sObjectAccessor->FindUnit((*itr)))
        {
            if (Creature* creature = unit->ToCreature())
            {
                if (victim->GetEntry() == creature->GetEntry() && !again)
                {
                    again = true;
                    for (GuidSet::const_iterator p_itr = m_PlayersInWar[killer->GetTeamId()].begin(); p_itr != m_PlayersInWar[killer->GetTeamId()].end(); ++p_itr)
                    {
                        if (Player* player = sObjectAccessor->FindPlayer(*p_itr))
                            if (player->GetDistance2d(killer) < 40)
                                IncrementQuest(player, IncrementQuest(killer, WGQuest[killer->GetTeamId()][0]));
                    }
                }
            }
        }
    }
    for (GuidSet::const_iterator itr = KeepCreature[killer->GetTeamId()? TEAM_ALLIANCE : TEAM_HORDE].begin();
         itr != KeepCreature[killer->GetTeamId()? TEAM_ALLIANCE : TEAM_HORDE].end(); ++itr)
    {
        if (Unit* unit = sObjectAccessor->FindUnit((*itr)))
        {
            if (Creature* creature = unit->ToCreature())
            {
                if (victim->GetEntry() == creature->GetEntry() && !again)
                {
                    again = true;
                    IncrementQuest(killer, WGQuest[killer->GetTeamId()][4]);
                    IncrementQuest(killer, WGQuest[killer->GetTeamId()][5]);
                    for (GuidSet::const_iterator p_itr = m_PlayersInWar[killer->GetTeamId()].begin(); p_itr != m_PlayersInWar[killer->GetTeamId()].end(); ++p_itr)
                    {
                        if (Player* player = sObjectAccessor->FindPlayer(*p_itr))
                            if (player->GetDistance2d(killer) < 40)
                                PromotePlayer(player);
                    }
                }
            }
        }
    }
    // TODO:Recent PvP activity worldstate
}

// Update rank for player
void BattlefieldWG::PromotePlayer(Player* killer)
{
    if (!m_BattlefieldActive)
        return;
    // Updating rank of player
    if (Aura* aur = killer->GetAura(SPELL_RECRUIT))
    {
        if (aur->GetStackAmount() >= 5)                     // 7 or more TODO:
        {
            killer->RemoveAura(SPELL_RECRUIT);
            killer->CastSpell(killer, SPELL_CORPORAL, true);
            SendWarningToPlayer(killer, BATTLEFIELD_WG_TEXT_FIRSTRANK);
        }
        else
            killer->CastSpell(killer, SPELL_RECRUIT, true);
    }
    else if (Aura* aur = killer->GetAura(SPELL_CORPORAL))
    {
        if (aur->GetStackAmount() >= 5)                     // 7 or more TODO:
        {
            killer->RemoveAura(SPELL_CORPORAL);
            killer->CastSpell(killer, SPELL_LIEUTENANT, true);
            SendWarningToPlayer(killer, BATTLEFIELD_WG_TEXT_SECONDRANK);
        }
        else
            killer->CastSpell(killer, SPELL_CORPORAL, true);
    }
}

void BattlefieldWG::OnPlayerJoinWar(Player* player)
{
    player->RemoveAurasDueToSpell(SPELL_RECRUIT);
    player->RemoveAurasDueToSpell(SPELL_CORPORAL);
    player->RemoveAurasDueToSpell(SPELL_LIEUTENANT);
    player->RemoveAurasDueToSpell(SPELL_TOWER_CONTROL);
    player->RemoveAurasDueToSpell(SPELL_SPIRITUAL_IMMUNITY);
    player->RemoveAurasDueToSpell(SPELL_TENACITY);
    player->RemoveAurasDueToSpell(SPELL_ESSENCE_OF_WINTERGRASP);

    player->CastSpell(player, SPELL_RECRUIT, true);

    if (player->GetZoneId() != m_ZoneId)
    {
        if (player->GetTeamId() == GetDefenderTeam())
        {
            player->TeleportTo(571, 5345, 2842, 410, 3.14f);
        }
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
        if (3 - m_Data32[BATTLEFIELD_WG_DATA_BROKEN_TOWER_ATT] > 0)
            player->SetAuraStack(SPELL_TOWER_CONTROL, player, 3 - m_Data32[BATTLEFIELD_WG_DATA_BROKEN_TOWER_ATT]);
    }
    else
    {
        if (m_Data32[BATTLEFIELD_WG_DATA_BROKEN_TOWER_ATT] > 0)
            player->SetAuraStack(SPELL_TOWER_CONTROL, player, m_Data32[BATTLEFIELD_WG_DATA_BROKEN_TOWER_ATT]);
    }
    SendInitWorldStatesTo(player);
}

void BattlefieldWG::OnPlayerLeaveWar(Player* player)
{
    // Remove all aura from WG // TODO: false we can go out of this zone on retail and keep Rank buff, remove on end of WG
    if (!player->GetSession()->PlayerLogout())
    {
        if (player->GetVehicle())                              // Remove vehicle of player if he go out.
            player->GetVehicle()->Dismiss();
        player->RemoveAurasDueToSpell(SPELL_RECRUIT);
        player->RemoveAurasDueToSpell(SPELL_CORPORAL);
        player->RemoveAurasDueToSpell(SPELL_LIEUTENANT);
        player->RemoveAurasDueToSpell(SPELL_TOWER_CONTROL);
        player->RemoveAurasDueToSpell(SPELL_SPIRITUAL_IMMUNITY);
        player->RemoveAurasDueToSpell(SPELL_TENACITY);
        player->RemoveAurasDueToSpell(SPELL_WINTERGRASP_RESTRICTED_FLIGHT_AREA);
        player->RemoveAurasDueToSpell(SPELL_ESSENCE_OF_WINTERGRASP);
        player->RemoveAurasDueToSpell(SPELL_TOWER_CONTROL);
    }
    player->RemoveAurasDueToSpell(SPELL_HORDE_CONTROLS_FACTORY_PHASE_SHIFT);
    player->RemoveAurasDueToSpell(SPELL_ALLIANCE_CONTROLS_FACTORY_PHASE_SHIFT);
    player->RemoveAurasDueToSpell(SPELL_HORDE_CONTROL_PHASE_SHIFT);
    player->RemoveAurasDueToSpell(SPELL_ALLIANCE_CONTROL_PHASE_SHIFT);
}

void BattlefieldWG::OnPlayerLeaveZone(Player* player)
{
    player->RemoveAurasDueToSpell(SPELL_ESSENCE_OF_WINTERGRASP);
    if (!m_BattlefieldActive)
    {
        player->RemoveAurasDueToSpell(SPELL_RECRUIT);
        player->RemoveAurasDueToSpell(SPELL_CORPORAL);
        player->RemoveAurasDueToSpell(SPELL_LIEUTENANT);
        player->RemoveAurasDueToSpell(SPELL_TOWER_CONTROL);
        player->RemoveAurasDueToSpell(SPELL_SPIRITUAL_IMMUNITY);
        player->RemoveAurasDueToSpell(SPELL_TENACITY);
        player->RemoveAurasDueToSpell(SPELL_WINTERGRASP_RESTRICTED_FLIGHT_AREA);
        player->RemoveAurasDueToSpell(SPELL_TOWER_CONTROL);
    }
    player->RemoveAurasDueToSpell(SPELL_HORDE_CONTROLS_FACTORY_PHASE_SHIFT);
    player->RemoveAurasDueToSpell(SPELL_ALLIANCE_CONTROLS_FACTORY_PHASE_SHIFT);
    player->RemoveAurasDueToSpell(SPELL_HORDE_CONTROL_PHASE_SHIFT);
    player->RemoveAurasDueToSpell(SPELL_ALLIANCE_CONTROL_PHASE_SHIFT);
}

void BattlefieldWG::OnPlayerEnterZone(Player* player)
{
    player->RemoveAurasDueToSpell(SPELL_ESSENCE_OF_WINTERGRASP);
    if (!m_BattlefieldActive)
    {
        player->RemoveAurasDueToSpell(SPELL_RECRUIT);
        player->RemoveAurasDueToSpell(SPELL_CORPORAL);
        player->RemoveAurasDueToSpell(SPELL_LIEUTENANT);
        player->RemoveAurasDueToSpell(SPELL_TOWER_CONTROL);
        player->RemoveAurasDueToSpell(SPELL_SPIRITUAL_IMMUNITY);
        player->RemoveAurasDueToSpell(SPELL_TENACITY);
        player->RemoveAurasDueToSpell(SPELL_WINTERGRASP_RESTRICTED_FLIGHT_AREA);
        player->RemoveAurasDueToSpell(SPELL_TOWER_CONTROL);
        if (player->GetTeamId() == GetDefenderTeam())
            player->AddAura(SPELL_ESSENCE_OF_WINTERGRASP, player);
    }

    player->AddAura(m_DefenderTeam == TEAM_HORDE ? SPELL_HORDE_CONTROL_PHASE_SHIFT : SPELL_ALLIANCE_CONTROL_PHASE_SHIFT, player);
    // Send worldstate to player
    SendInitWorldStatesTo(player);
}

// Method sending worldsate to player
WorldPacket BattlefieldWG::BuildInitWorldStates()
{
    WorldPacket data(SMSG_INIT_WORLD_STATES, (4 + 4 + 4 + 2 + (BuildingsInZone.size() * 8) + (WorkShopList.size() * 8)));

    data << uint32(m_MapId);
    data << uint32(m_ZoneId);
    data << uint32(0);
    data << uint16(4 + 2 + 4 + BuildingsInZone.size() + WorkShopList.size());

    data << uint32(3803) << uint32(GetAttackerTeam());
    data << uint32(3802) << uint32(GetDefenderTeam());
    data << uint32(3801) << uint32(IsWarTime()? 0 : 1);
    data << uint32(3710) << uint32(IsWarTime()? 1 : 0);

    for (uint32 i = 0; i < 2; ++i)
        data << ClockWorldState[i] << uint32(time(NULL) + (m_Timer / 1000));

    data << uint32(3490) << uint32(GetData(BATTLEFIELD_WG_DATA_VEHICLE_H));
    data << uint32(3491) << GetData(BATTLEFIELD_WG_DATA_MAX_VEHICLE_H);
    data << uint32(3680) << uint32(GetData(BATTLEFIELD_WG_DATA_VEHICLE_A));
    data << uint32(3681) << GetData(BATTLEFIELD_WG_DATA_MAX_VEHICLE_A);

    for (GameObjectBuilding::const_iterator itr = BuildingsInZone.begin(); itr != BuildingsInZone.end(); ++itr)
    {
        data << (*itr)->m_WorldState << (*itr)->m_State;
    }
    for (WorkShop::const_iterator itr = WorkShopList.begin(); itr != WorkShopList.end(); ++itr)
    {
        data << (*itr)->m_WorldState << (*itr)->m_State;
    }
    return data;
}

void BattlefieldWG::SendInitWorldStatesTo(Player *player)
{
    WorldPacket data = BuildInitWorldStates();
    player->GetSession()->SendPacket(&data);
}

void BattlefieldWG::SendInitWorldStatesToAll()
{
    WorldPacket data = BuildInitWorldStates();
    for (uint8 team = 0; team < 2; team++)
        for (GuidSet::iterator itr = m_players[team].begin(); itr != m_players[team].end(); ++itr)
            if (Player* player = sObjectMgr->GetPlayer((*itr)))
                player->GetSession()->SendPacket(&data);
}

void BattlefieldWG::BrokenWallOrTower(TeamId team)
{
    if (team == GetDefenderTeam())
    {
        for (GuidSet::const_iterator p_itr = m_PlayersInWar[GetAttackerTeam()].begin(); p_itr != m_PlayersInWar[GetAttackerTeam()].end(); ++p_itr)
        {
            if (Player* player = sObjectMgr->GetPlayer((*p_itr)))
            {
                if (player->GetTeamId() == TEAM_ALLIANCE)
                    IncrementQuest(player, 13222);
                else
                    IncrementQuest(player, 13223);
            }
        }
    }
}
// Called when a tower is broke
void BattlefieldWG::AddBrokenTower(TeamId team)
{
    // Destroy an attack tower
    if (team == GetAttackerTeam())
    {
        // Update counter
        m_Data32[BATTLEFIELD_WG_DATA_DAMAGED_TOWER_ATT]--;
        m_Data32[BATTLEFIELD_WG_DATA_BROKEN_TOWER_ATT]++;

        // Remove buff stack
        for (GuidSet::const_iterator itr = m_PlayersInWar[GetAttackerTeam()].begin(); itr != m_PlayersInWar[GetAttackerTeam()].end(); ++itr)
            if (Player* player = sObjectMgr->GetPlayer((*itr)))
                player->RemoveAuraFromStack(SPELL_TOWER_CONTROL);

        // Add buff stack
        for (GuidSet::const_iterator itr = m_PlayersInWar[GetDefenderTeam()].begin(); itr != m_PlayersInWar[GetDefenderTeam()].end(); ++itr)
            if (Player* player = sObjectMgr->GetPlayer((*itr)))
            {
                player->CastSpell(player, SPELL_TOWER_CONTROL, true);
                if (player->GetTeamId() == TEAM_HORDE)
                    IncrementQuest(player, 13539, true);
                else
                    IncrementQuest(player, 13538, true);
                DoCompleteOrIncrementAchievement(ACHIEVEMENTS_WG_TOWER_DESTROY, player);
            }
        // If the threw south tower is destroy
        if (m_Data32[BATTLEFIELD_WG_DATA_BROKEN_TOWER_ATT] == 3)
        {
            // Remove 10 minutes to battle time
            if (int32(m_Timer - 600000) < 0)
            {
                m_Timer = 0;
            }
            else
            {
                m_Timer -= 600000;
            }
            SendInitWorldStatesToAll();
        }
    }
    else
    {
        m_Data32[BATTLEFIELD_WG_DATA_DAMAGED_TOWER_DEF]--;
        m_Data32[BATTLEFIELD_WG_DATA_BROKEN_TOWER_DEF]++;
    }
}

void BattlefieldWG::ProcessEvent(GameObject *obj, uint32 eventId)
{
    if (!obj || !IsWarTime())
        return;

    // On click on titan relic
    if (obj->GetEntry() == BATTLEFIELD_WG_GAMEOBJECT_TITAN_RELIC)
    {
        // Check that the door is break
        if (m_CanClickOnOrb)
            EndBattle(false);
        else // if door is not break, respawn relic.
            m_relic->SetRespawnTime(RESPAWN_IMMEDIATELY);
    }

    // if destroy or damage event, search the wall/tower and update worldstate/send warning message
    for (GameObjectBuilding::const_iterator itr = BuildingsInZone.begin(); itr != BuildingsInZone.end(); ++itr)
    {
        if (obj->GetEntry() == (*itr)->m_Build->GetEntry())
        {
            if ((*itr)->m_Build->GetGOInfo()->building.damagedEvent == eventId)
                (*itr)->Damaged();

            if ((*itr)->m_Build->GetGOInfo()->building.destroyedEvent == eventId)
                (*itr)->Destroyed();

            break;
        }
    }
}

// Called when a tower is damaged, used for honor reward calcul
void BattlefieldWG::AddDamagedTower(TeamId team)
{
    if (team == GetAttackerTeam())
    {
        m_Data32[BATTLEFIELD_WG_DATA_DAMAGED_TOWER_ATT]++;
    }
    else
    {
        m_Data32[BATTLEFIELD_WG_DATA_DAMAGED_TOWER_DEF]++;
    }
}

// Update vehicle count WorldState to player
void BattlefieldWG::UpdateVehicleCountWG()
{
    SendUpdateWorldState(3490, GetData(BATTLEFIELD_WG_DATA_VEHICLE_H));
    SendUpdateWorldState(3491, GetData(BATTLEFIELD_WG_DATA_MAX_VEHICLE_H));
    SendUpdateWorldState(3680, GetData(BATTLEFIELD_WG_DATA_VEHICLE_A));
    SendUpdateWorldState(3681, GetData(BATTLEFIELD_WG_DATA_MAX_VEHICLE_A));
}

void BattlefieldWG::UpdateTenacity()
{
    TeamId team = TEAM_NEUTRAL;
    uint32 allianceNum = m_PlayersInWar[TEAM_ALLIANCE].size();
    uint32 hordeNum = m_PlayersInWar[TEAM_HORDE].size();
    int32 newStack = 0;

    if (allianceNum && hordeNum)
    {
        if (allianceNum < hordeNum)
            newStack = int32((float (hordeNum) / float (allianceNum) - 1) *4);  // positive, should cast on alliance
        else if (allianceNum > hordeNum)
            newStack = int32((1 - float (allianceNum) / float (hordeNum)) *4);  // negative, should cast on horde
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
            if (Player* player = sObjectMgr->GetPlayer((*itr)))
                if (player->getLevel() >= m_MinLevel)
                    player->RemoveAurasDueToSpell(SPELL_TENACITY);

        for (GuidSet::const_iterator itr = m_vehicles[team].begin(); itr != m_vehicles[team].end(); ++itr)
            if (Unit* unit = sObjectAccessor->FindUnit((*itr)))
                if (Creature* creature = unit->ToCreature())
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
        buff_honor = (newStack < 15) ? (uint32) SPELL_GREATER_HONOR : buff_honor;
        buff_honor = (newStack < 10) ? (uint32) SPELL_GREAT_HONOR : buff_honor;
        buff_honor = (newStack < 5) ? 0 : buff_honor;

        for (GuidSet::const_iterator itr = m_PlayersInWar[team].begin(); itr != m_PlayersInWar[team].end(); ++itr)
            if (Player* player = sObjectMgr->GetPlayer((*itr)))
                player->SetAuraStack(SPELL_TENACITY, player, newStack);
        for (GuidSet::const_iterator itr = m_vehicles[team].begin(); itr != m_vehicles[team].end(); ++itr)
            if (Unit* unit = sObjectAccessor->FindUnit((*itr)))
                if (Creature* creature = unit->ToCreature())
                    creature->SetAuraStack(SPELL_TENACITY_VEHICLE, creature, newStack);

        if (buff_honor != 0)
        {
            for (GuidSet::const_iterator itr = m_PlayersInWar[team].begin(); itr != m_PlayersInWar[team].end(); ++itr)
                if (Player* player = sObjectMgr->GetPlayer((*itr)))
                    player->AddAura(buff_honor, player);
            for (GuidSet::const_iterator itr = m_vehicles[team].begin(); itr != m_vehicles[team].end(); ++itr)
                if (Unit* unit = sObjectAccessor->FindUnit((*itr)))
                    if (Creature* creature = unit->ToCreature())
                        creature->AddAura(buff_honor, creature);
        }
    }
}

void BfCapturePointWG::ChangeTeam(TeamId /*oldTeam */ )
{
    m_WorkShop->ChangeControl(m_team, false);
}

BfCapturePointWG::BfCapturePointWG(BattlefieldWG* bf, TeamId control) : BfCapturePoint(bf)
{
    m_Bf = bf;
    m_team = control;
}

BfGraveYardWG::BfGraveYardWG(BattlefieldWG* bf) : BfGraveYard(bf)
{
    m_Bf = bf;
}
