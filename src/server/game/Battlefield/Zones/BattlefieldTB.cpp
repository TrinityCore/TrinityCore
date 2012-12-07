/*
* Copyright (C) 2011-2012 Project SkyFire <http://www.projectskyfire.org/>
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 3 of the License, or (at your
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

#include "BattlefieldTB.h"
#include "SpellAuras.h"
#include "GroupMgr.h"

bool BattlefieldTB::SetupBattlefield()
{
    m_TypeId                     = BATTLEFIELD_TB;    //View enum BattlefieldTypes
    m_BattleId                   = BATTLEFIELD_BATTLEID_TB;
    m_ZoneId                     = 5095; // Tol Barad
    _MapId                       = 732;  // Map X
    m_MaxPlayer                  = sWorld->getIntConfig(CONFIG_TOL_BARAD_PLR_MAX);
    m_enable                     = sWorld->getBoolConfig(CONFIG_TOL_BARAD_ENABLE);
    m_MinPlayer                  = sWorld->getIntConfig(CONFIG_TOL_BARAD_PLR_MIN);
    m_MinLevel                   = sWorld->getIntConfig(CONFIG_TOL_BARAD_PLR_MIN_LVL);
    m_BattleTime                 = sWorld->getIntConfig(CONFIG_TOL_BARAD_BATTLETIME)*60*1000;   // Time of battle (in ms)
    m_NoWarBattleTime            = sWorld->getIntConfig(CONFIG_TOL_BARAD_NOBATTLETIME)*60*1000; // Time between to battle (in ms)
    m_TimeForAcceptInvite        = 20; // in second
    m_StartGroupingTimer         = 15*60*1000; // in ms
    m_StartGrouping=false;
    KickPositionA.Relocate(-363.897f, 1047.931f, 22, 0);
    KickPositionA.m_mapId        = _MapId;
    KickPositionH.Relocate(-609.336f, 1392.194f, 21.5f, 0);
    KickPositionH.m_mapId        = _MapId;
    RegisterZone(m_ZoneId);
    m_Data32.resize(BATTLEFIELD_TB_DATA_MAX);
    m_saveTimer                  = 60000;

    // Init GraveYards
    SetGraveyardNumber(BATTLEFIELD_TB_GY_MAX);

    //Load from db
    if (( sWorld->getWorldState(5387) == 0 ) && (sWorld->getWorldState(5384) == 0) && (sWorld->getWorldState(TBClockWorldState[0]) == 0 ))
    {
        sWorld->setWorldState(5387, false);
        sWorld->setWorldState(5384, urand(0, 1));
        sWorld->setWorldState(TBClockWorldState[0], m_NoWarBattleTime);
    }

        m_WarTime                = sWorld->getWorldState(5387);
        m_DefenderTeam           = (TeamId)sWorld->getWorldState(5384);
        m_Timer                  = sWorld->getWorldState(TBClockWorldState[0]);
    if (m_WarTime)
    {
        m_WarTime = false;
        m_Timer = 10 * 60 * 1000;
    }

    for (uint8 i=0; i<BATTLEFIELD_TB_GY_MAX; i++)
    {
        BfGraveYardTB* gy = new BfGraveYardTB(this);
        if (TBGraveYard[i].startcontrol == TEAM_NEUTRAL)
        {
            // In no war time Gy is control by defender
            gy->Init(45079, 45066, TBGraveYard[i].x, TBGraveYard[i].y, TBGraveYard[i].z, TBGraveYard[i].o, m_DefenderTeam, TBGraveYard[i].guid);
        }
        else
            gy->Init(45079, 45066, TBGraveYard[i].x, TBGraveYard[i].y, TBGraveYard[i].z, TBGraveYard[i].o, TBGraveYard[i].startcontrol, TBGraveYard[i].guid);
        gy->SetTextId(TBGraveYard[i].textid);
        m_GraveYardList[i] = gy;
    }

    // Pop des gameobject et creature du TBWorkShop
    for (uint8 i = 0; i<TB_MAX_WORKSHOP; i++)
    {
        BfTBWorkShopData* ws = new BfTBWorkShopData(this); // Create new object
        // Init:setup variable
        ws->Init(TBCapturePointDataBase[i].worldstate, TBCapturePointDataBase[i].type, TBCapturePointDataBase[i].nameid);
        // Spawn associate gameobject on this point (Horde/Alliance flags)
        for (int g = 0; g<TBCapturePointDataBase[i].nbgob; g++)
        {
            ws->AddGameObject(TBCapturePointDataBase[i].GameObjectData[g]);
        }

        // Create PvPCapturePoint
        if (TBCapturePointDataBase[i].type < BATTLEFIELD_TB_FORT_MAX)
        {
            ws->ChangeControl(GetAttackerTeam(), true); // Update control of this point
            m_Data32[BATTLEFIELD_TB_DATA_CAPTURED_FORT_ATT]++;
            m_Data32[BATTLEFIELD_TB_DATA_CAPTURED_FORT_DEF]--;
            // Create Object
            BfCapturePointTB* TBWorkShop = new BfCapturePointTB(this, GetAttackerTeam());
            // Spawn gameobject associate (see in OnGameObjectCreate, of OutdoorPvP for see association)
            if (TBWorkShop->SetCapturePointData(TBCapturePointDataBase[i].CapturePoint.entryh, 732,
                TBCapturePointDataBase[i].CapturePoint.x,
                TBCapturePointDataBase[i].CapturePoint.y,
                TBCapturePointDataBase[i].CapturePoint.z,
                0))
            {
                TBWorkShop->LinkToWorkShop(ws);   // Link our point to the capture point (for faction changement)
                AddCapturePoint(TBWorkShop);      // Add this capture point to list for update this (view in Update() of OutdoorPvP)
            }
        }
        else
        {
            m_Data32[BATTLEFIELD_TB_DATA_CAPTURED_FORT_ATT]--;
            m_Data32[BATTLEFIELD_TB_DATA_CAPTURED_FORT_DEF]++;
            ws->ChangeControl(GetDefenderTeam(), true); // Update control of this point (Keep TBWorkShop= to deffender team)
        }
        WorkShopList.insert(ws);
    }

    // Spawning npc in keep
    for (uint8 i = 0; i<TB_MAX_KEEP_NPC; i++)
    {
        // Horde npc
        if (Creature* creature = SpawnCreature(TBKeepNPC[i].entryh, TBKeepNPC[i].x, TBKeepNPC[i].y, TBKeepNPC[i].z, TBKeepNPC[i].o, TEAM_HORDE))
            KeepCreature[TEAM_HORDE].insert(creature->GetGUID());
        // Alliance npc
        if (Creature* creature = SpawnCreature(TBKeepNPC[i].entrya, TBKeepNPC[i].x, TBKeepNPC[i].y, TBKeepNPC[i].z, TBKeepNPC[i].o, TEAM_ALLIANCE))
            KeepCreature[TEAM_ALLIANCE].insert(creature->GetGUID());
    }

    // Hide keep npc
    for (GuidSet::const_iterator itr = KeepCreature[GetAttackerTeam()].begin(); itr != KeepCreature[GetAttackerTeam()].end(); ++itr)
        if (Unit* unit = ObjectAccessor::FindUnit((*itr)))
            if (Creature* creature = unit->ToCreature())
                HideNpc(creature);

    // Spawning battle npcs
    for (uint8 i = 0; i<TB_MAX_WAR_NPC; i++)
    {
        // Horde npc
        if (Creature* creature = SpawnCreature(TBWarNPC[i].entryh, TBWarNPC[i].x, TBWarNPC[i].y, TBWarNPC[i].z, TBWarNPC[i].o, TEAM_HORDE))
            WarCreature[TEAM_HORDE].insert(creature->GetGUID());
        // Alliance npc
        if (Creature* creature = SpawnCreature(TBWarNPC[i].entrya, TBWarNPC[i].x, TBWarNPC[i].y, TBWarNPC[i].z, TBWarNPC[i].o, TEAM_ALLIANCE))
            WarCreature[TEAM_ALLIANCE].insert(creature->GetGUID());
    }

    // Hide battle npcs
    for (GuidSet::const_iterator itr = WarCreature[GetDefenderTeam()].begin(); itr != WarCreature[GetDefenderTeam()].end(); ++itr)
        if (Unit* unit = ObjectAccessor::FindUnit((*itr)))
            if (Creature* creature = unit->ToCreature())
                HideNpc(creature);

    for (GuidSet::const_iterator itr = WarCreature[GetAttackerTeam()].begin(); itr != WarCreature[GetAttackerTeam()].end(); ++itr)
        if (Unit* unit = ObjectAccessor::FindUnit((*itr)))
            if (Creature* creature = unit->ToCreature())
                HideNpc(creature);

    //Spawning Buiding
    for (uint8 i = 0; i<TB_MAX_OBJ; i++)
    {
        GameObject* go = SpawnGameObject(TBGameObjectBuillding[i].entry, TBGameObjectBuillding[i].x, TBGameObjectBuillding[i].y, TBGameObjectBuillding[i].z, TBGameObjectBuillding[i].o);
        if (go)
        {
            BfTBGameObjectBuilding* b = new BfTBGameObjectBuilding(this);
            b->Init(go, TBGameObjectBuillding[i].type, TBGameObjectBuillding[i].WorldState, TBGameObjectBuillding[i].nameid);
            BuildingsInZone.insert(b);
        }
    }
    return true;
}

bool BattlefieldTB::Update(uint32 diff)
{
    bool m_return = Battlefield::Update(diff);
    if (m_saveTimer <= diff)
    {
        sWorld->setWorldState(5387, m_WarTime);
        if (IsWarTime())
        {
            sWorld->setWorldState(5546, GetAttackerTeam());
            sWorld->setWorldState(5547, GetAttackerTeam());
        }
        else
            sWorld->setWorldState(5384, m_DefenderTeam);
        sWorld->setWorldState(TBClockWorldState[0], m_Timer );
        m_saveTimer = 60 * IN_MILLISECONDS;
    }
    else
        m_saveTimer -= diff;

    for (GuidSet::const_iterator itr = m_PlayersIsSpellImu.begin(); itr != m_PlayersIsSpellImu.end(); ++itr)
        if (Player* player = ObjectAccessor::FindPlayer((*itr)))
        {
            if (player->HasAura(SPELL_SPIRITUAL_IMMUNITY_TB))
            {
                const WorldSafeLocsEntry* graveyard = GetClosestGraveYard(player);
                if (graveyard)
                {
                    if (player->GetDistance2d(graveyard->x, graveyard->y) > 6.0f)
                    {
                        player->RemoveAurasDueToSpell(SPELL_SPIRITUAL_IMMUNITY_TB);
                        m_PlayersIsSpellImu.erase(player->GetGUID());
                    }
                }
            }
        }
    return m_return;
}

void BattlefieldTB::AddPlayerToResurrectQueue(uint64 npc_guid, uint64 player_guid)
{
    Battlefield::AddPlayerToResurrectQueue(npc_guid, player_guid);
    if (IsWarTime())
    {
        if (Player* player = ObjectAccessor::FindPlayer(player_guid))
        {
            if (!player->HasAura(SPELL_SPIRITUAL_IMMUNITY_TB))
            {
                player->CastSpell(player, SPELL_SPIRITUAL_IMMUNITY_TB, true);
                m_PlayersIsSpellImu.insert(player->GetGUID());
            }
        }
    }
}

void BattlefieldTB::OnBattleStart()
{
    // Rebuild all wall
    /*for (TBGameObjectBuilding::const_iterator itr = BuildingsInZone.begin(); itr != BuildingsInZone.end(); ++itr)
        if ((*itr))
            (*itr)->Rebuild();*/

    m_Data32[BATTLEFIELD_TB_DATA_BROKEN_TOWER_DEF] = 0;
    m_Data32[BATTLEFIELD_TB_DATA_CAPTURED_FORT_DEF] = 3;
    m_Data32[BATTLEFIELD_TB_DATA_CAPTURED_FORT_ATT] = 0;

    // Update graveyard (in no war time all graveyard is to deffender, in war time, depend of base)
    for (TBWorkShop::const_iterator itr = WorkShopList.begin(); itr != WorkShopList.end(); ++itr)
    {
        if ((*itr))
            (*itr)->UpdateGraveYardAndWorkshop();
    }

    //Hide keep npc
    for (GuidSet::const_iterator itr = KeepCreature[GetAttackerTeam()].begin(); itr != KeepCreature[GetAttackerTeam()].end(); ++itr)
        if (Unit* unit = ObjectAccessor::FindUnit((*itr)))
            if (Creature* creature = unit->ToCreature())
                HideNpc(creature);

    for (GuidSet::const_iterator itr = KeepCreature[GetDefenderTeam()].begin(); itr != KeepCreature[GetDefenderTeam()].end(); ++itr)
        if (Unit* unit = ObjectAccessor::FindUnit((*itr)))
            if (Creature* creature = unit->ToCreature())
                HideNpc(creature);

    //Show battle npcs
    for (GuidSet::const_iterator itr = WarCreature[GetDefenderTeam()].begin(); itr != WarCreature[GetDefenderTeam()].end(); ++itr)
        if (Unit* unit = ObjectAccessor::FindUnit((*itr)))
            if (Creature* creature = unit->ToCreature())
                HideNpc(creature);

    //Show battle npcs
    for (GuidSet::const_iterator itr = WarCreature[GetAttackerTeam()].begin(); itr != WarCreature[GetAttackerTeam()].end(); ++itr)
        if (Unit* unit = ObjectAccessor::FindUnit((*itr)))
            if (Creature* creature = unit->ToCreature())
                HideNpc(creature);

    //Warnin message
    SendWarningToAllInZone(BATTLEFIELD_TB_TEXT_START);
}

void BattlefieldTB::OnBattleEnd(bool endbytimer)
{
    if (!endbytimer)
    {
        //Change all npc in keep
        for (GuidSet::const_iterator itr = KeepCreature[GetAttackerTeam()].begin(); itr != KeepCreature[GetAttackerTeam()].end(); ++itr)
        {
            if (Unit* unit = ObjectAccessor::FindUnit((*itr)))
                if (Creature* creature = unit->ToCreature())
                    HideNpc(creature);
        }
        for (GuidSet::const_iterator itr = KeepCreature[GetDefenderTeam()].begin(); itr != KeepCreature[GetDefenderTeam()].end(); ++itr)
        {
            if (Unit* unit = ObjectAccessor::FindUnit((*itr)))
                if (Creature* creature = unit->ToCreature())
                    ShowNpc(creature, true);
        }
        // Hide creatures that should be visible only when battle is on.
        for (GuidSet::const_iterator itr = WarCreature[GetAttackerTeam()].begin(); itr != WarCreature[GetAttackerTeam()].end(); ++itr)
        {
            if (Unit* unit = ObjectAccessor::FindUnit((*itr)))
                if (Creature* creature = unit->ToCreature())
                    HideNpc(creature);
        }
        for (GuidSet::const_iterator itr = WarCreature[GetDefenderTeam()].begin(); itr != WarCreature[GetDefenderTeam()].end(); ++itr)
        {
            if (Unit* unit = ObjectAccessor::FindUnit((*itr)))
                if (Creature* creature = unit->ToCreature())
                    HideNpc(creature);
        }
        /*//Change all npc out of keep
        for (GuidSet::const_iterator itr = OutsideCreature[GetDefenderTeam()].begin(); itr != OutsideCreature[GetDefenderTeam()].end(); ++itr)
        {
            if (Unit* unit = ObjectAccessor::FindUnit((*itr)))
                if (Creature* creature = unit->ToCreature())
                    HideNpc(creature);
        }
        for (GuidSet::const_iterator itr = OutsideCreature[GetAttackerTeam()].begin(); itr != OutsideCreature[GetAttackerTeam()].end(); ++itr)
        {
            if (Unit* unit = ObjectAccessor::FindUnit((*itr)))
                if (Creature* creature = unit->ToCreature())
                    ShowNpc(creature, true);
        }*/
    }

    for (TBGameObjectBuilding::const_iterator itr = BuildingsInZone.begin(); itr != BuildingsInZone.end(); ++itr)
        if ((*itr))
            if (!endbytimer)
                (*itr)->Rebuild();

    // Update all graveyard, control is to defender when no wartime
    for (uint8 i = 0; i<BATTLEFIELD_TB_GY_HORDE; i++)
    {
        if (GetGraveYardById(i))
        {
            GetGraveYardById(i)->ChangeControl(GetDefenderTeam());
        }
    }

    for (TBGameObjectSet::const_iterator itr = m_KeepGameObject[GetDefenderTeam()].begin(); itr != m_KeepGameObject[GetDefenderTeam()].end(); ++itr)
        (*itr)->SetRespawnTime(RESPAWN_IMMEDIATELY);

    for (TBGameObjectSet::const_iterator itr = m_KeepGameObject[GetAttackerTeam()].begin(); itr != m_KeepGameObject[GetAttackerTeam()].end(); ++itr)
        (*itr)->SetRespawnTime(RESPAWN_ONE_DAY);

    //Saving data
    for (TBGameObjectBuilding::const_iterator itr = BuildingsInZone.begin(); itr != BuildingsInZone.end(); ++itr)
        (*itr)->Save();
    for (TBWorkShop::const_iterator itr = WorkShopList.begin(); itr != WorkShopList.end(); ++itr)
        (*itr)->Save();

    for (GuidSet::const_iterator itr = m_PlayersInWar[GetDefenderTeam()].begin(); itr != m_PlayersInWar[GetDefenderTeam()].end(); ++itr)
    {
        if (Player* player = ObjectAccessor::FindPlayer((*itr)))
        {
            if (player->GetTeamId() == TEAM_HORDE)
            {
                player->CastSpell(player, SPELL_TOL_BARAD_VICTORY_HORDE, true);
                player->CastSpell(player, SPELL_TOL_BARAD_QUEST_HORDE, true);
            }
            else
            {
                player->CastSpell(player, SPELL_TOL_BARAD_VICTORY_ALLIANCE, true);
                player->CastSpell(player, SPELL_TOL_BARAD_QUEST_ALLIANCE, true);
            }
            // Victory, TB TODO
            //DoCompleteOrIncrementAchievement(ACHIEVEMENTS_WIN_TB, player);
            // Ployez sous notre joug
            /*if (GetTimer() <= 10000 && !endbytimer)
                DoCompleteOrIncrementAchievement(ACHIEVEMENTS_WIN_TB_TIMER_10, player);*/
        }
    }
    for (GuidSet::const_iterator itr = m_PlayersInWar[GetAttackerTeam()].begin(); itr != m_PlayersInWar[GetAttackerTeam()].end(); ++itr)
    {
        if (Player* player = ObjectAccessor::FindPlayer((*itr)))
        {
            player->CastSpell(player, SPELL_TOL_BARAD_DEFEAT, true);
        }
    }

    for (uint8 team = 0; team < 2; ++team)
    {
        for (GuidSet::const_iterator itr = m_PlayersInWar[team].begin(); itr != m_PlayersInWar[team].end(); ++itr)
        {
            if (Player* player = ObjectAccessor::FindPlayer((*itr)))
            {
                player->RemoveAura(SPELL_TOWER_BONUS);
                player->RemoveAurasDueToSpell(SPELL_VETERAN);
                player->RemoveAurasDueToSpell(SPELL_SPIRITUAL_IMMUNITY_TB);
            }
        }
        m_PlayersInWar[team].clear();

        for (GuidSet::const_iterator itr = m_vehicles[team].begin(); itr != m_vehicles[team].end(); ++itr)
        {
            if (Unit* unit = ObjectAccessor::FindUnit((*itr)))
                if (Creature* creature = unit->ToCreature())
                    if (creature->IsVehicle())
                        creature->GetVehicleKit()->Dismiss();
        }
        m_vehicles[team].clear();
    }

    if (!endbytimer)
    {
        SendWarningToAllInZone(BATTLEFIELD_TB_TEXT_WIN_KEEP,
            sObjectMgr->GetSkyFireStringForDBCLocale((GetDefenderTeam() == TEAM_ALLIANCE) ? BATTLEFIELD_TB_TEXT_ALLIANCE : BATTLEFIELD_TB_TEXT_HORDE));
    }
    else
    {
        SendWarningToAllInZone(BATTLEFIELD_TB_TEXT_DEFEND_KEEP,
            sObjectMgr->GetSkyFireStringForDBCLocale((GetDefenderTeam() == TEAM_ALLIANCE) ? BATTLEFIELD_TB_TEXT_ALLIANCE : BATTLEFIELD_TB_TEXT_HORDE));
    }
}

/******************************************************
*                    Reward System                    *
******************************************************/

void BattlefieldTB::DoCompleteOrIncrementAchievement(uint32 achievement, Player* player, uint8 /*incrementNumber*/)
{
    /*AchievementEntry const* AE = GetAchievementStore()->LookupEntry(achievement);

    switch (achievement)
    {
        case ACHIEVEMENTS_WIN_TB_100 :
        {
            //player->GetAchievementMgr().UpdateAchievementCriteria();
        }
        default:
        {
            if (player)
                player->CompletedAchievement(AE);
        }
        break;
    }*/
}

void BattlefieldTB::OnStartGrouping()
{
    //Warn
    SendWarningToAllInZone(BATTLEFIELD_TB_TEXT_WILL_START);
}

void BattlefieldTB::OnPlayerJoinWar(Player* player)
{
    player->RemoveAurasDueToSpell(SPELL_VETERAN);
    player->RemoveAurasDueToSpell(SPELL_SPIRITUAL_IMMUNITY_TB);
    player->RemoveAurasDueToSpell(SPELL_TOWER_BONUS);

    if (player->GetZoneId() != m_ZoneId)
        if (player->GetTeamId() == GetDefenderTeam())
        {
            player->TeleportTo(732, -1244.58f, 981.233f, 155.426f, 0);
            player->CastSpell(player, SPELL_SLOW_FALL_TB, true);
        }
        else
            player->TeleportTo(732, -827.212646f, 1187.948608f, 112.81f, 3.092834f);

    if (player->GetTeamId() == GetAttackerTeam())
    {
        player->CastSpell(player, SPELL_VETERAN, true);
        if (3-m_Data32[BATTLEFIELD_TB_DATA_BROKEN_TOWER_DEF]>0)
            player->SetAuraStack(SPELL_TOWER_BONUS, player, 3-m_Data32[BATTLEFIELD_TB_DATA_BROKEN_TOWER_DEF]);
    }
    else
    {
        if (m_Data32[BATTLEFIELD_TB_DATA_BROKEN_TOWER_DEF]>0)
            player->SetAuraStack(SPELL_TOWER_BONUS, player, m_Data32[BATTLEFIELD_TB_DATA_BROKEN_TOWER_DEF]);
    }
    SendInitWorldStatesTo(player);
}

void BattlefieldTB::OnPlayerLeaveWar(Player* player)
{
    if (!player->GetSession()->PlayerLogout())
    {
        player->RemoveAurasDueToSpell(SPELL_VETERAN);
        player->RemoveAurasDueToSpell(SPELL_SPIRITUAL_IMMUNITY_TB);
        player->RemoveAurasDueToSpell(SPELL_TOWER_BONUS);
    }
}

void BattlefieldTB::OnPlayerLeaveZone(Player* player)
{
    if (!m_WarTime)
    {
        player->RemoveAurasDueToSpell(SPELL_VETERAN);
        player->RemoveAurasDueToSpell(SPELL_SPIRITUAL_IMMUNITY_TB);
        player->RemoveAurasDueToSpell(SPELL_TOWER_BONUS);
    }}

void BattlefieldTB::OnPlayerEnterZone(Player* player)
{
    if (!m_WarTime)
    {
        player->RemoveAurasDueToSpell(SPELL_VETERAN);
        player->RemoveAurasDueToSpell(SPELL_SPIRITUAL_IMMUNITY_TB);
        player->RemoveAurasDueToSpell(SPELL_TOWER_BONUS);
    }

    // Send worldstate to player
    SendInitWorldStatesTo(player);
}
// Method sending worldsate to player
WorldPacket BattlefieldTB::BuildInitWorldStates()
{
    WorldPacket data(SMSG_INIT_WORLD_STATES, (4+4+4+2+(BuildingsInZone.size()*8)+(WorkShopList.size()*8)));

    data << uint32(_MapId);
    data << uint32(m_ZoneId);
    data << uint32(0);
    data << uint16(4+2+4+BuildingsInZone.size()+WorkShopList.size());

    data << uint32(5385) << uint32(IsWarTime() ? 0 : GetAttackerTeam()); // Alliance Controlled
    data << uint32(5384) << uint32(IsWarTime() ? 0 : GetDefenderTeam()); // Horde Controlled
    // data << uint32(5547) << uint32(IsWarTime() ? GetAttackerTeam() : 0); // Horde is Attacking
    // data << uint32(5546) << uint32(IsWarTime() ? GetAttackerTeam() : 0); // Alliance is Attacking
    data << uint32(5349) << uint32(IsWarTime() ? BATTLEFIELD_TB_DATA_CAPTURED_FORT_ATT : 0); // Captured count
    data << uint32(5346) << uint32(IsWarTime() ? 1 : 0); // Time remaining
    data << uint32(5387) << uint32(IsWarTime() ? 0 : 1); // Next Battle

    for (uint32 i = 0; i < 2; ++i)
        data << TBClockWorldState[i] << uint32(time(NULL)+(m_Timer / 1000));

    for (TBGameObjectBuilding::const_iterator itr = BuildingsInZone.begin(); itr != BuildingsInZone.end(); ++itr)
    {
        data << (*itr)->m_WorldState << (*itr)->m_State;
    }
    for (TBWorkShop::const_iterator itr = WorkShopList.begin(); itr != WorkShopList.end(); ++itr)
    {
        data << (*itr)->m_WorldState << (*itr)->m_State;
    }
    return data;
}

void BattlefieldTB::SendInitWorldStatesTo(Player* player)
{
   WorldPacket data = BuildInitWorldStates();
   player->GetSession()->SendPacket(&data);
}

void BattlefieldTB::SendInitWorldStatesToAll()
{
    WorldPacket data = BuildInitWorldStates();
    for (uint8 team = 0; team<2; team++)
        for (GuidSet::iterator itr = m_players[team].begin(); itr != m_players[team].end(); ++itr)
            if (Player* player = ObjectAccessor::FindPlayer((*itr)))
                player->GetSession()->SendPacket(&data);
}

void BattlefieldTB::AddBrokenTower(TeamId team)
{
    m_BattleTime += 5*60*1000; // Increase battle time by 5 mins.
    m_Data32[BATTLEFIELD_TB_DATA_BROKEN_TOWER_DEF]++;
    // Destroy an attack tower
    if (team == GetDefenderTeam())
    {
        // Remove buff stack
        for (GuidSet::const_iterator itr = m_PlayersInWar[GetDefenderTeam()].begin(); itr != m_PlayersInWar[GetDefenderTeam()].end(); ++itr)
            if (Player* player = ObjectAccessor::FindPlayer((*itr)))
                player->RemoveAuraFromStack(SPELL_TOWER_BONUS);

        // Add buff stack
        for (GuidSet::const_iterator itr = m_PlayersInWar[GetAttackerTeam()].begin(); itr != m_PlayersInWar[GetAttackerTeam()].end(); ++itr)
            if (Player* player = ObjectAccessor::FindPlayer((*itr)))
            {
                player->CastSpell(player, SPELL_TOWER_BONUS, true);
                //DoCompleteOrIncrementAchievement(ACHIEVEMENTS_TB_TOWER_DESTROY, player); TODO
            }

        if (m_Data32[BATTLEFIELD_TB_DATA_BROKEN_TOWER_DEF] == 3)
        {
            if (int32(m_Timer-600000)<0)
                m_Timer = 0;
            else
                m_Timer -= 600000;

            SendInitWorldStatesToAll();
        }
    }
}

void BattlefieldTB::ProcessEvent(GameObject* obj, uint32 eventId)
{
    if (!obj || !IsWarTime())
        return;
    //On click on titan relic
    if (BATTLEFIELD_TB_DATA_CAPTURED_FORT_DEF == 0)
        EndBattle(false);

    //if destroy or damage event, search the wall/tower and update worldstate/send warning message
    for (TBGameObjectBuilding::const_iterator itr = BuildingsInZone.begin(); itr != BuildingsInZone.end(); ++itr)
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

void BfCapturePointTB::ChangeTeam(TeamId /*oldteam*/)
{
    m_WorkShop->ChangeControl(_team, false);
}

BfCapturePointTB::BfCapturePointTB(BattlefieldTB* bf, TeamId control) : BfCapturePoint(bf)
{
    m_Bf = bf;
    _team = control;
}

BfGraveYardTB::BfGraveYardTB(BattlefieldTB* bf) : BfGraveYard(bf)
{
    m_Bf = bf;
}
