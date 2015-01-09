/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#include "BattlegroundAV.h"

#include "ObjectMgr.h"
#include "WorldPacket.h"

#include "BattlegroundMap.h"
#include "BattlegroundScore.h"

#include "GameObject.h"
#include "Language.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "WorldSession.h"

void BattlegroundAV::InstallBattleground()
{
    m_BgObjects.resize(BG_AV_OBJECT_MAX);
    m_BgCreatures.resize(AV_CPLACE_MAX+AV_STATICCPLACE_MAX);

    for (uint8 i = 0; i < 2; i++)

        TeamScores[i] = BG_AV_SCORE_INITIAL_POINTS;
        _isInformedNearVictory[i] = false;
        _captainAlive[i] = true;
        _captainBuffTimer[i] = 120000 + urand(0, 4) * MINUTE; //as far as i could see, the buff is randomly so i make 2minutes (thats the duration of the buff itself) + 0-4minutes TODO get the right times
        _mineOwner[i] = BG_TEAMS_COUNT;
        _minePreviousOwner[i] = _mineOwner[i];
    }
        InitNode(i, BG_TEAM_ALLIANCE, false);
    for (AVNodeId i = BG_AV_NODES_DUNBALDAR_SOUTH; i <= BG_AV_NODES_STONEHEART_BUNKER; ++i) //alliance towers
        InitNode(i, BG_TEAM_ALLIANCE, true);
    for (AVNodeId i = BG_AV_NODES_ICEBLOOD_GRAVE; i <= BG_AV_NODES_FROSTWOLF_HUT; ++i) //horde graves
        InitNode(i, BG_TEAM_HORDE, false);
    for (AVNodeId i = BG_AV_NODES_ICEBLOOD_TOWER; i <= BG_AV_NODES_FROSTWOLF_WTOWER; ++i) //horde towers
        InitNode(i, BG_TEAM_HORDE, true);

    InitNode(BG_AV_NODES_SNOWFALL_GRAVE, BG_TEAMS_COUNT, false); //give snowfall neutral owner

    _mineTimer = AV_MINE_TICK_TIMER;
}

void BattlegroundAV::InitializeTextIds()
{
    PreparationPhaseTextIds[BG_STARTING_EVENT_FIRST]  = LANG_BG_AV_START_TWO_MINUTES;
    PreparationPhaseTextIds[BG_STARTING_EVENT_SECOND] = LANG_BG_AV_START_ONE_MINUTE;
    PreparationPhaseTextIds[BG_STARTING_EVENT_THIRD]  = LANG_BG_AV_START_HALF_MINUTE;
    PreparationPhaseTextIds[BG_STARTING_EVENT_FOURTH] = LANG_BG_AV_HAS_BEGUN;
}

void BattlegroundAV::InitializeObjects()
{
    ObjectGUIDsByType.resize(BG_AV_OBJECT_MAX + AV_CPLACE_MAX + AV_STATICCPLACE_MAX);

    // Create starting objects
    AddGameObject(BG_AV_OBJECT_DOOR_A, BG_AV_OBJECTID_GATE_A, BG_AV_DoorPositons[0][0], BG_AV_DoorPositons[0][1], BG_AV_DoorPositons[0][2], BG_AV_DoorPositons[0][3], 0, 0, sin(BG_AV_DoorPositons[0][3]/2), cos(BG_AV_DoorPositons[0][3]/2), RESPAWN_IMMEDIATELY);
    AddGameObject(BG_AV_OBJECT_DOOR_H, BG_AV_OBJECTID_GATE_H, BG_AV_DoorPositons[1][0], BG_AV_DoorPositons[1][1], BG_AV_DoorPositons[1][2], BG_AV_DoorPositons[1][3], 0, 0, sin(BG_AV_DoorPositons[1][3]/2), cos(BG_AV_DoorPositons[1][3]/2), RESPAWN_IMMEDIATELY);

    //spawn node-objects
    for (uint8 i = BG_AV_NODES_FIRSTAID_STATION ; i < BG_AV_NODES_MAX; ++i)
    {
        if (i <= BG_AV_NODES_FROSTWOLF_HUT)
        {
            AddGameObject(i, BG_AV_OBJECTID_BANNER_A_B, BG_AV_ObjectPos[i][0], BG_AV_ObjectPos[i][1], BG_AV_ObjectPos[i][2], BG_AV_ObjectPos[i][3], 0, 0, sin(BG_AV_ObjectPos[i][3]/2), cos(BG_AV_ObjectPos[i][3]/2), RESPAWN_ONE_DAY);
            AddGameObject(i+11, BG_AV_OBJECTID_BANNER_CONT_A_B, BG_AV_ObjectPos[i][0], BG_AV_ObjectPos[i][1], BG_AV_ObjectPos[i][2], BG_AV_ObjectPos[i][3], 0, 0, sin(BG_AV_ObjectPos[i][3]/2), cos(BG_AV_ObjectPos[i][3]/2), RESPAWN_ONE_DAY);
            AddGameObject(i+33, BG_AV_OBJECTID_BANNER_H_B, BG_AV_ObjectPos[i][0], BG_AV_ObjectPos[i][1], BG_AV_ObjectPos[i][2], BG_AV_ObjectPos[i][3], 0, 0, sin(BG_AV_ObjectPos[i][3]/2), cos(BG_AV_ObjectPos[i][3]/2), RESPAWN_ONE_DAY);
            AddGameObject(i+22, BG_AV_OBJECTID_BANNER_CONT_H_B, BG_AV_ObjectPos[i][0], BG_AV_ObjectPos[i][1], BG_AV_ObjectPos[i][2], BG_AV_ObjectPos[i][3], 0, 0, sin(BG_AV_ObjectPos[i][3]/2), cos(BG_AV_ObjectPos[i][3]/2), RESPAWN_ONE_DAY);
            AddGameObject(BG_AV_OBJECT_AURA_N_FIRSTAID_STATION+i*3, BG_AV_OBJECTID_AURA_N, BG_AV_ObjectPos[i][0], BG_AV_ObjectPos[i][1], BG_AV_ObjectPos[i][2], BG_AV_ObjectPos[i][3], 0, 0, sin(BG_AV_ObjectPos[i][3]/2), cos(BG_AV_ObjectPos[i][3]/2), RESPAWN_ONE_DAY);
            AddGameObject(BG_AV_OBJECT_AURA_A_FIRSTAID_STATION+i*3, BG_AV_OBJECTID_AURA_A, BG_AV_ObjectPos[i][0], BG_AV_ObjectPos[i][1], BG_AV_ObjectPos[i][2], BG_AV_ObjectPos[i][3], 0, 0, sin(BG_AV_ObjectPos[i][3]/2), cos(BG_AV_ObjectPos[i][3]/2), RESPAWN_ONE_DAY);
            AddGameObject(BG_AV_OBJECT_AURA_H_FIRSTAID_STATION+i*3, BG_AV_OBJECTID_AURA_H, BG_AV_ObjectPos[i][0], BG_AV_ObjectPos[i][1], BG_AV_ObjectPos[i][2], BG_AV_ObjectPos[i][3], 0, 0, sin(BG_AV_ObjectPos[i][3]/2), cos(BG_AV_ObjectPos[i][3]/2), RESPAWN_ONE_DAY);
        }
        else //towers
        {
            if (i <= BG_AV_NODES_STONEHEART_BUNKER) //alliance towers
            {
                AddGameObject(i, BG_AV_OBJECTID_BANNER_A, BG_AV_ObjectPos[i][0], BG_AV_ObjectPos[i][1], BG_AV_ObjectPos[i][2], BG_AV_ObjectPos[i][3], 0, 0, sin(BG_AV_ObjectPos[i][3]/2), cos(BG_AV_ObjectPos[i][3]/2), RESPAWN_ONE_DAY);
                AddGameObject(i+22, BG_AV_OBJECTID_BANNER_CONT_H, BG_AV_ObjectPos[i][0], BG_AV_ObjectPos[i][1], BG_AV_ObjectPos[i][2], BG_AV_ObjectPos[i][3], 0, 0, sin(BG_AV_ObjectPos[i][3]/2), cos(BG_AV_ObjectPos[i][3]/2), RESPAWN_ONE_DAY);
                AddGameObject(BG_AV_OBJECT_TAURA_A_DUNBALDAR_SOUTH+(2*(i-BG_AV_NODES_DUNBALDAR_SOUTH)), BG_AV_OBJECTID_AURA_A, BG_AV_ObjectPos[i+8][0], BG_AV_ObjectPos[i+8][1], BG_AV_ObjectPos[i+8][2], BG_AV_ObjectPos[i+8][3], 0, 0, sin(BG_AV_ObjectPos[i+8][3]/2), cos(BG_AV_ObjectPos[i+8][3]/2), RESPAWN_ONE_DAY);
                AddGameObject(BG_AV_OBJECT_TAURA_H_DUNBALDAR_SOUTH+(2*(i-BG_AV_NODES_DUNBALDAR_SOUTH)), BG_AV_OBJECTID_AURA_N, BG_AV_ObjectPos[i+8][0], BG_AV_ObjectPos[i+8][1], BG_AV_ObjectPos[i+8][2], BG_AV_ObjectPos[i+8][3], 0, 0, sin(BG_AV_ObjectPos[i+8][3]/2), cos(BG_AV_ObjectPos[i+8][3]/2), RESPAWN_ONE_DAY);
                AddGameObject(BG_AV_OBJECT_TFLAG_A_DUNBALDAR_SOUTH+(2*(i-BG_AV_NODES_DUNBALDAR_SOUTH)), BG_AV_OBJECTID_TOWER_BANNER_A, BG_AV_ObjectPos[i+8][0], BG_AV_ObjectPos[i+8][1], BG_AV_ObjectPos[i+8][2], BG_AV_ObjectPos[i+8][3], 0, 0, sin(BG_AV_ObjectPos[i+8][3]/2), cos(BG_AV_ObjectPos[i+8][3]/2), RESPAWN_ONE_DAY);
                AddGameObject(BG_AV_OBJECT_TFLAG_H_DUNBALDAR_SOUTH+(2*(i-BG_AV_NODES_DUNBALDAR_SOUTH)), BG_AV_OBJECTID_TOWER_BANNER_PH, BG_AV_ObjectPos[i+8][0], BG_AV_ObjectPos[i+8][1], BG_AV_ObjectPos[i+8][2], BG_AV_ObjectPos[i+8][3], 0, 0, sin(BG_AV_ObjectPos[i+8][3]/2), cos(BG_AV_ObjectPos[i+8][3]/2), RESPAWN_ONE_DAY);
            }
            else //horde towers
            {
                AddGameObject(i+7, BG_AV_OBJECTID_BANNER_CONT_A, BG_AV_ObjectPos[i][0], BG_AV_ObjectPos[i][1], BG_AV_ObjectPos[i][2], BG_AV_ObjectPos[i][3], 0, 0, sin(BG_AV_ObjectPos[i][3]/2), cos(BG_AV_ObjectPos[i][3]/2), RESPAWN_ONE_DAY);
                AddGameObject(i+29, BG_AV_OBJECTID_BANNER_H, BG_AV_ObjectPos[i][0], BG_AV_ObjectPos[i][1], BG_AV_ObjectPos[i][2], BG_AV_ObjectPos[i][3], 0, 0, sin(BG_AV_ObjectPos[i][3]/2), cos(BG_AV_ObjectPos[i][3]/2), RESPAWN_ONE_DAY);
                AddGameObject(BG_AV_OBJECT_TAURA_A_DUNBALDAR_SOUTH+(2*(i-BG_AV_NODES_DUNBALDAR_SOUTH)), BG_AV_OBJECTID_AURA_N, BG_AV_ObjectPos[i+8][0], BG_AV_ObjectPos[i+8][1], BG_AV_ObjectPos[i+8][2], BG_AV_ObjectPos[i+8][3], 0, 0, sin(BG_AV_ObjectPos[i+8][3]/2), cos(BG_AV_ObjectPos[i+8][3]/2), RESPAWN_ONE_DAY);
                AddGameObject(BG_AV_OBJECT_TAURA_H_DUNBALDAR_SOUTH+(2*(i-BG_AV_NODES_DUNBALDAR_SOUTH)), BG_AV_OBJECTID_AURA_H, BG_AV_ObjectPos[i+8][0], BG_AV_ObjectPos[i+8][1], BG_AV_ObjectPos[i+8][2], BG_AV_ObjectPos[i+8][3], 0, 0, sin(BG_AV_ObjectPos[i+8][3]/2), cos(BG_AV_ObjectPos[i+8][3]/2), RESPAWN_ONE_DAY);
                AddGameObject(BG_AV_OBJECT_TFLAG_A_DUNBALDAR_SOUTH+(2*(i-BG_AV_NODES_DUNBALDAR_SOUTH)), BG_AV_OBJECTID_TOWER_BANNER_PA, BG_AV_ObjectPos[i+8][0], BG_AV_ObjectPos[i+8][1], BG_AV_ObjectPos[i+8][2], BG_AV_ObjectPos[i+8][3], 0, 0, sin(BG_AV_ObjectPos[i+8][3]/2), cos(BG_AV_ObjectPos[i+8][3]/2), RESPAWN_ONE_DAY);
                AddGameObject(BG_AV_OBJECT_TFLAG_H_DUNBALDAR_SOUTH+(2*(i-BG_AV_NODES_DUNBALDAR_SOUTH)), BG_AV_OBJECTID_TOWER_BANNER_H, BG_AV_ObjectPos[i+8][0], BG_AV_ObjectPos[i+8][1], BG_AV_ObjectPos[i+8][2], BG_AV_ObjectPos[i+8][3], 0, 0, sin(BG_AV_ObjectPos[i+8][3]/2), cos(BG_AV_ObjectPos[i+8][3]/2), RESPAWN_ONE_DAY);
            }

            for (uint8 j=0; j <= 9; j++) //burning aura
                AddGameObject(BG_AV_OBJECT_BURN_DUNBALDAR_SOUTH+((i-BG_AV_NODES_DUNBALDAR_SOUTH)*10)+j, BG_AV_OBJECTID_FIRE, BG_AV_ObjectPos[AV_OPLACE_BURN_DUNBALDAR_SOUTH+((i-BG_AV_NODES_DUNBALDAR_SOUTH)*10)+j][0], BG_AV_ObjectPos[AV_OPLACE_BURN_DUNBALDAR_SOUTH+((i-BG_AV_NODES_DUNBALDAR_SOUTH)*10)+j][1], BG_AV_ObjectPos[AV_OPLACE_BURN_DUNBALDAR_SOUTH+((i-BG_AV_NODES_DUNBALDAR_SOUTH)*10)+j][2], BG_AV_ObjectPos[AV_OPLACE_BURN_DUNBALDAR_SOUTH+((i-BG_AV_NODES_DUNBALDAR_SOUTH)*10)+j][3], 0, 0, sin(BG_AV_ObjectPos[AV_OPLACE_BURN_DUNBALDAR_SOUTH+((i-BG_AV_NODES_DUNBALDAR_SOUTH)*10)+j][3]/2), cos(BG_AV_ObjectPos[AV_OPLACE_BURN_DUNBALDAR_SOUTH+((i-BG_AV_NODES_DUNBALDAR_SOUTH)*10)+j][3]/2), RESPAWN_ONE_DAY);
        }
    }

    for (uint8 i=0; i<2; i++) //burning aura for buildings
    {
        for (uint8 j=0; j <= 9; j++)
        {
            if (j<5)
                AddGameObject(BG_AV_OBJECT_BURN_BUILDING_ALLIANCE+(i*10)+j, BG_AV_OBJECTID_SMOKE, BG_AV_ObjectPos[AV_OPLACE_BURN_BUILDING_A+(i*10)+j][0], BG_AV_ObjectPos[AV_OPLACE_BURN_BUILDING_A+(i*10)+j][1], BG_AV_ObjectPos[AV_OPLACE_BURN_BUILDING_A+(i*10)+j][2], BG_AV_ObjectPos[AV_OPLACE_BURN_BUILDING_A+(i*10)+j][3], 0, 0, sin(BG_AV_ObjectPos[AV_OPLACE_BURN_BUILDING_A+(i*10)+j][3]/2), cos(BG_AV_ObjectPos[AV_OPLACE_BURN_BUILDING_A+(i*10)+j][3]/2), RESPAWN_ONE_DAY);

            else
                AddGameObject(BG_AV_OBJECT_BURN_BUILDING_ALLIANCE+(i*10)+j, BG_AV_OBJECTID_FIRE, BG_AV_ObjectPos[AV_OPLACE_BURN_BUILDING_A+(i*10)+j][0], BG_AV_ObjectPos[AV_OPLACE_BURN_BUILDING_A+(i*10)+j][1], BG_AV_ObjectPos[AV_OPLACE_BURN_BUILDING_A+(i*10)+j][2], BG_AV_ObjectPos[AV_OPLACE_BURN_BUILDING_A+(i*10)+j][3], 0, 0, sin(BG_AV_ObjectPos[AV_OPLACE_BURN_BUILDING_A+(i*10)+j][3]/2), cos(BG_AV_ObjectPos[AV_OPLACE_BURN_BUILDING_A+(i*10)+j][3]/2), RESPAWN_ONE_DAY);
        }
    }

    for (uint16 i= 0; i <= (BG_AV_OBJECT_MINE_SUPPLY_N_MAX-BG_AV_OBJECT_MINE_SUPPLY_N_MIN); i++)
        AddGameObject(BG_AV_OBJECT_MINE_SUPPLY_N_MIN+i, BG_AV_OBJECTID_MINE_N, BG_AV_ObjectPos[AV_OPLACE_MINE_SUPPLY_N_MIN+i][0], BG_AV_ObjectPos[AV_OPLACE_MINE_SUPPLY_N_MIN+i][1], BG_AV_ObjectPos[AV_OPLACE_MINE_SUPPLY_N_MIN+i][2], BG_AV_ObjectPos[AV_OPLACE_MINE_SUPPLY_N_MIN+i][3], 0, 0, sin(BG_AV_ObjectPos[AV_OPLACE_MINE_SUPPLY_N_MIN+i][3]/2), cos(BG_AV_ObjectPos[AV_OPLACE_MINE_SUPPLY_N_MIN+i][3]/2), RESPAWN_ONE_DAY);

    for (uint16 i= 0 ; i <= (BG_AV_OBJECT_MINE_SUPPLY_S_MAX-BG_AV_OBJECT_MINE_SUPPLY_S_MIN); i++)
        AddGameObject(BG_AV_OBJECT_MINE_SUPPLY_S_MIN+i, BG_AV_OBJECTID_MINE_S, BG_AV_ObjectPos[AV_OPLACE_MINE_SUPPLY_S_MIN+i][0], BG_AV_ObjectPos[AV_OPLACE_MINE_SUPPLY_S_MIN+i][1], BG_AV_ObjectPos[AV_OPLACE_MINE_SUPPLY_S_MIN+i][2], BG_AV_ObjectPos[AV_OPLACE_MINE_SUPPLY_S_MIN+i][3], 0, 0, sin(BG_AV_ObjectPos[AV_OPLACE_MINE_SUPPLY_S_MIN+i][3]/2), cos(BG_AV_ObjectPos[AV_OPLACE_MINE_SUPPLY_S_MIN+i][3]/2), RESPAWN_ONE_DAY);

    AddGameObject(BG_AV_OBJECT_FLAG_N_SNOWFALL_GRAVE, BG_AV_OBJECTID_BANNER_SNOWFALL_N , BG_AV_ObjectPos[BG_AV_NODES_SNOWFALL_GRAVE][0], BG_AV_ObjectPos[BG_AV_NODES_SNOWFALL_GRAVE][1], BG_AV_ObjectPos[BG_AV_NODES_SNOWFALL_GRAVE][2], BG_AV_ObjectPos[BG_AV_NODES_SNOWFALL_GRAVE][3], 0, 0, sin(BG_AV_ObjectPos[BG_AV_NODES_SNOWFALL_GRAVE][3]/2), cos(BG_AV_ObjectPos[BG_AV_NODES_SNOWFALL_GRAVE][3]/2), RESPAWN_ONE_DAY);

    for (uint8 i = 0; i < 4; i++)
    {
        AddGameObject(BG_AV_OBJECT_SNOW_EYECANDY_A+i, BG_AV_OBJECTID_SNOWFALL_CANDY_A , BG_AV_ObjectPos[AV_OPLACE_SNOW_1+i][0], BG_AV_ObjectPos[AV_OPLACE_SNOW_1+i][1], BG_AV_ObjectPos[AV_OPLACE_SNOW_1+i][2], BG_AV_ObjectPos[AV_OPLACE_SNOW_1+i][3], 0, 0, sin(BG_AV_ObjectPos[AV_OPLACE_SNOW_1+i][3]/2), cos(BG_AV_ObjectPos[AV_OPLACE_SNOW_1+i][3]/2), RESPAWN_ONE_DAY);
        AddGameObject(BG_AV_OBJECT_SNOW_EYECANDY_PA+i, BG_AV_OBJECTID_SNOWFALL_CANDY_PA , BG_AV_ObjectPos[AV_OPLACE_SNOW_1+i][0], BG_AV_ObjectPos[AV_OPLACE_SNOW_1+i][1], BG_AV_ObjectPos[AV_OPLACE_SNOW_1+i][2], BG_AV_ObjectPos[AV_OPLACE_SNOW_1+i][3], 0, 0, sin(BG_AV_ObjectPos[AV_OPLACE_SNOW_1+i][3]/2), cos(BG_AV_ObjectPos[AV_OPLACE_SNOW_1+i][3]/2), RESPAWN_ONE_DAY);
        AddGameObject(BG_AV_OBJECT_SNOW_EYECANDY_H+i, BG_AV_OBJECTID_SNOWFALL_CANDY_H , BG_AV_ObjectPos[AV_OPLACE_SNOW_1+i][0], BG_AV_ObjectPos[AV_OPLACE_SNOW_1+i][1], BG_AV_ObjectPos[AV_OPLACE_SNOW_1+i][2], BG_AV_ObjectPos[AV_OPLACE_SNOW_1+i][3], 0, 0, sin(BG_AV_ObjectPos[AV_OPLACE_SNOW_1+i][3]/2), cos(BG_AV_ObjectPos[AV_OPLACE_SNOW_1+i][3]/2), RESPAWN_ONE_DAY);
        AddGameObject(BG_AV_OBJECT_SNOW_EYECANDY_PH+i, BG_AV_OBJECTID_SNOWFALL_CANDY_PH , BG_AV_ObjectPos[AV_OPLACE_SNOW_1+i][0], BG_AV_ObjectPos[AV_OPLACE_SNOW_1+i][1], BG_AV_ObjectPos[AV_OPLACE_SNOW_1+i][2], BG_AV_ObjectPos[AV_OPLACE_SNOW_1+i][3], 0, 0, sin(BG_AV_ObjectPos[AV_OPLACE_SNOW_1+i][3]/2), cos(BG_AV_ObjectPos[AV_OPLACE_SNOW_1+i][3]/2), RESPAWN_ONE_DAY);
    }

    uint16 i;

    // Initial Nodes
    for (i = 0; i < BG_AV_OBJECT_MAX; i++)
        SpawnGameObject(i, RESPAWN_ONE_DAY);

    for (i = BG_AV_OBJECT_FLAG_A_FIRSTAID_STATION; i <= BG_AV_OBJECT_FLAG_A_STONEHEART_GRAVE ; i++)
    {
        SpawnGameObject(BG_AV_OBJECT_AURA_A_FIRSTAID_STATION+3*i, RESPAWN_IMMEDIATELY);
        SpawnGameObject(i, RESPAWN_IMMEDIATELY);
    }

    for (i = BG_AV_OBJECT_FLAG_A_DUNBALDAR_SOUTH; i <= BG_AV_OBJECT_FLAG_A_STONEHEART_BUNKER ; i++)
        SpawnGameObject(i, RESPAWN_IMMEDIATELY);

    for (i = BG_AV_OBJECT_FLAG_H_ICEBLOOD_GRAVE; i <= BG_AV_OBJECT_FLAG_H_FROSTWOLF_WTOWER ; i++)
    {
        SpawnGameObject(i, RESPAWN_IMMEDIATELY);
        if (i <= BG_AV_OBJECT_FLAG_H_FROSTWOLF_HUT)
            SpawnGameObject(BG_AV_OBJECT_AURA_H_FIRSTAID_STATION+3*GetNodeThroughObject(i), RESPAWN_IMMEDIATELY);
    }

    for (i = BG_AV_OBJECT_TFLAG_A_DUNBALDAR_SOUTH; i <= BG_AV_OBJECT_TFLAG_A_STONEHEART_BUNKER; i+=2)
    {
        SpawnGameObject(i, RESPAWN_IMMEDIATELY); //flag
        SpawnGameObject(i+16, RESPAWN_IMMEDIATELY); //aura
    }

    for (i = BG_AV_OBJECT_TFLAG_H_ICEBLOOD_TOWER; i <= BG_AV_OBJECT_TFLAG_H_FROSTWOLF_WTOWER; i+=2)
    {
        SpawnGameObject(i, RESPAWN_IMMEDIATELY); //flag
        SpawnGameObject(i+16, RESPAWN_IMMEDIATELY); //aura
    }

    //snowfall and the doors
    for (i = BG_AV_OBJECT_FLAG_N_SNOWFALL_GRAVE; i <= BG_AV_OBJECT_DOOR_A; i++)
        SpawnGameObject(i, RESPAWN_IMMEDIATELY);

    SpawnGameObject(BG_AV_OBJECT_AURA_N_SNOWFALL_GRAVE, RESPAWN_IMMEDIATELY);

    DoorClose(BG_AV_OBJECT_DOOR_A);
    DoorClose(BG_AV_OBJECT_DOOR_H);

    //creatures
    for (AVNodeId i= BG_AV_NODES_FIRSTAID_STATION; i < BG_AV_NODES_MAX; ++i)
    {
        if (m_Nodes[i].Owner)
            PopulateNode(i);
    }

    //all creatures which don't get despawned through the script are static
    for (i=0; i < AV_STATICCPLACE_MAX; i++)
        AddAVCreature(0, i+AV_CPLACE_MAX);

    //mainspiritguides:
    AddSpiritGuide(7, BG_AV_CreaturePos[7][0], BG_AV_CreaturePos[7][1], BG_AV_CreaturePos[7][2], BG_AV_CreaturePos[7][3], BG_TEAM_ALLIANCE);
    AddSpiritGuide(8, BG_AV_CreaturePos[8][0], BG_AV_CreaturePos[8][1], BG_AV_CreaturePos[8][2], BG_AV_CreaturePos[8][3], BG_TEAM_HORDE);

    //spawn the marshals (those who get deleted, if a tower gets destroyed)
    for (i=AV_NPC_A_MARSHAL_SOUTH; i <= AV_NPC_H_MARSHAL_WTOWER; i++)
        AddAVCreature(i, AV_CPLACE_A_MARSHAL_SOUTH+(i-AV_NPC_A_MARSHAL_SOUTH));

    AddAVCreature(AV_NPC_HERALD, AV_CPLACE_HERALD);
}

void BattlegroundAV::StartBattleground()
{
    BattlegroundMap::StartBattleground();

    for (uint16 i= BG_AV_OBJECT_MINE_SUPPLY_N_MIN; i <= BG_AV_OBJECT_MINE_SUPPLY_N_MAX; i++)
        SpawnGameObject(i, RESPAWN_IMMEDIATELY);
    for (uint16 i= BG_AV_OBJECT_MINE_SUPPLY_S_MIN; i <= BG_AV_OBJECT_MINE_SUPPLY_S_MAX; i++)
        SpawnGameObject(i, RESPAWN_IMMEDIATELY);
    for (uint8 mine = AV_NORTH_MINE; mine <= AV_SOUTH_MINE; mine++) //mine population
        ChangeMineOwner(mine, BG_TEAMS_COUNT, true);

    UpdateWorldState(AV_SHOW_H_SCORE, 1);
    UpdateWorldState(AV_SHOW_A_SCORE, 1);

    DoorOpen(BG_AV_OBJECT_DOOR_H);
    DoorOpen(BG_AV_OBJECT_DOOR_A);
}

void BattlegroundAV::EndBattleground(BattlegroundWinner winner)
{
    //calculate bonuskills for both teams:
    //first towers:
    uint8 kills[2]={0, 0}; //0=ally 1=horde
    uint8 rep[2]={0, 0}; //0=ally 1=horde
    for (AVNodeId i = BG_AV_NODES_DUNBALDAR_SOUTH; i <= BG_AV_NODES_FROSTWOLF_WTOWER; ++i)
    {
        if (m_Nodes[i].State == POINT_CONTROLED)
        {
            if (m_Nodes[i].Owner == BG_TEAM_ALLIANCE)
            {
                rep[0]   += BG_AV_REP_SURVIVING_TOWER;
                kills[0] += BG_AV_KILL_SURVIVING_TOWER;
            }
            else
            {
        for (uint8 j = 0; j < 9; j++)
            m_Team_QuestStatus[i][j] = 0;
        m_Team_Scores[i] = 0;
        m_IsInformedNearVictory[i] = false;
        m_CaptainAlive[i] = true;
        m_CaptainBuffTimer[i] = 0;
        m_Mine_Owner[i] = 0;
        m_Mine_PrevOwner[i] = 0;
        m_Mine_Reclaim_Timer[i] = 0;
        {
            kills[i] += BG_AV_KILL_SURVIVING_CAPTAIN;
            rep[i]   += BG_AV_REP_SURVIVING_CAPTAIN;
        }
        if (rep[i] != 0)
            RewardReputationToTeam((i == 0)?730:729, rep[i], (i == 0)? BG_TEAM_ALLIANCE : BG_TEAM_HORDE);
        if (kills[i] != 0)
            RewardHonorToTeam(GetBonusHonor(kills[i]), (i == 0)?BG_TEAM_ALLIANCE : BG_TEAM_HORDE);
    }

    //TODO add enterevademode for all attacking creatures
    BattlegroundMap::EndBattleground(winner);
    }

    m_Mine_Timer = 0;

    return Trinity::Honor::hk_honor_at_level(m_MaxLevel, kills);
        InitNode(i, 0, false);

    StartMessageIds[BG_STARTING_EVENT_FIRST]  = LANG_BG_AV_START_TWO_MINUTES;
    StartMessageIds[BG_STARTING_EVENT_SECOND] = LANG_BG_AV_START_ONE_MINUTE;
    StartMessageIds[BG_STARTING_EVENT_THIRD]  = LANG_BG_AV_START_HALF_MINUTE;
    StartMessageIds[BG_STARTING_EVENT_FOURTH] = LANG_BG_AV_HAS_BEGUN;
}

void BattlegroundAV::OnPlayerKill(Player* victim, Player* killer)

{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    BattlegroundMap::OnPlayerKill(victim, killer);
    UpdateScore(victim->GetBGTeam(), -1);
}

void BattlegroundAV::HandleKillUnit(Creature* unit, Player* killer)
{
    TC_LOG_DEBUG("bg.battleground", "bg_av HandleKillUnit %i", unit->GetEntry());
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;
    uint32 entry = unit->GetEntry();
    /*
    uint32 triggerSpawnID = 0;
    if (creature->GetEntry() == BG_AV_CreatureInfo[AV_NPC_A_CAPTAIN][0])
        triggerSpawnID = AV_CPLACE_TRIGGER16;
    else if (creature->GetEntry() == BG_AV_CreatureInfo[AV_NPC_A_BOSS][0])
        triggerSpawnID = AV_CPLACE_TRIGGER17;
    else if (creature->GetEntry() == BG_AV_CreatureInfo[AV_NPC_H_CAPTAIN][0])
        triggerSpawnID = AV_CPLACE_TRIGGER18;
    else if (creature->GetEntry() == BG_AV_CreatureInfo[AV_NPC_H_BOSS][0])
        triggerSpawnID = AV_CPLACE_TRIGGER19;
    */
    if (entry == BG_AV_CreatureInfo[AV_NPC_A_BOSS])
    {
        CastSpellOnTeam(23658, BG_TEAM_HORDE); //this is a spell which finishes a quest where a player has to kill the boss
        RewardReputationToTeam(729, BG_AV_REP_BOSS, BG_TEAM_HORDE);
        RewardHonorToTeam(GetBonusHonorFromKill(BG_AV_KILL_BOSS), HORDE);
        EndBattleground(WINNER_HORDE);
        DeleteCreature(AV_CPLACE_TRIGGER17);
    }
    else if (entry == BG_AV_CreatureInfo[AV_NPC_H_BOSS])
    {
        CastSpellOnTeam(23658, BG_TEAM_ALLIANCE); //this is a spell which finishes a quest where a player has to kill the boss
        RewardReputationToTeam(730, BG_AV_REP_BOSS, BG_TEAM_ALLIANCE);
        RewardHonorToTeam(GetBonusHonor(BG_AV_KILL_BOSS), BG_TEAM_ALLIANCE);
        EndBattleground(WINNER_ALLIANCE);
        DeleteCreature(AV_CPLACE_TRIGGER19);
    }
    else if (entry == BG_AV_CreatureInfo[AV_NPC_A_CAPTAIN])
    {
        if (!_captainAlive[0])
        {
            TC_LOG_ERROR("bg.battleground", "Killed a Captain twice, please report this bug, if you haven't done \".respawn\"");
            return;
        }
        _captainAlive[0]=false;
        RewardReputationToTeam(729, BG_AV_REP_CAPTAIN, BG_TEAM_HORDE);
        RewardHonorToTeam(GetBonusHonor(BG_AV_KILL_CAPTAIN), HORDE);
        UpdateScore(BG_TEAM_ALLIANCE, (-1)*BG_AV_RES_CAPTAIN);
        //spawn destroyed aura
        for (uint8 i=0; i <= 9; i++)
            SpawnGameObject(BG_AV_OBJECT_BURN_BUILDING_ALLIANCE+i, RESPAWN_IMMEDIATELY);
        Creature* creature = GetCreature(AV_CPLACE_HERALD);
            SendMessageToAll(LANG_BG_AV_A_CAPTAIN_DEAD, CHAT_MSG_MONSTER_YELL, creature);
        DeleteCreature(AV_CPLACE_TRIGGER16);

        if (Creature* herold = GetBGCreature(AV_CPLACE_HERALD))
            herold->AI()->Talk(TEXT_STORMPIKE_GENERAL_DEAD);
    }
    else if (entry == BG_AV_CreatureInfo[AV_NPC_H_CAPTAIN])
    {
        if (!_captainAlive[1])
        {
            TC_LOG_ERROR("bg.battleground", "Killed a Captain twice, please report this bug, if you haven't done \".respawn\"");
            return;
        }
        _captainAlive[1]=false;
        RewardReputationToTeam(730, BG_AV_REP_CAPTAIN, BG_TEAM_ALLIANCE);
        RewardHonorToTeam(GetBonusHonorFromKill(BG_AV_KILL_CAPTAIN), ALLIANCE);
        UpdateScore(BG_TEAM_HORDE, (-1)*BG_AV_RES_CAPTAIN);
        //spawn destroyed aura
        for (uint8 i=0; i <= 9; i++)
            SpawnGameObject(BG_AV_OBJECT_BURN_BUILDING_HORDE+i, RESPAWN_IMMEDIATELY);
        Creature* creature = GetBGCreature(AV_CPLACE_HERALD);
            
        if (Creature* herold = GetBGCreature(AV_CPLACE_HERALD))
            herold->AI()->Talk(TEXT_FROSTWOLF_GENERAL_DEAD);
    }
    else if (entry == BG_AV_CreatureInfo[AV_NPC_N_MINE_N_4] || entry == BG_AV_CreatureInfo[AV_NPC_N_MINE_A_4] || entry == BG_AV_CreatureInfo[AV_NPC_N_MINE_H_4])
        ChangeMineOwner(AV_NORTH_MINE, killer->GetTeam());
    else if (entry == BG_AV_CreatureInfo[AV_NPC_S_MINE_N_4] || entry == BG_AV_CreatureInfo[AV_NPC_S_MINE_A_4] || entry == BG_AV_CreatureInfo[AV_NPC_S_MINE_H_4])
        ChangeMineOwner(AV_SOUTH_MINE, killer->GetTeam());
}

void BattlegroundAV::HandleQuestComplete(uint32 questid, Player* player)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;//maybe we should log this, cause this must be a cheater or a big bug

    /// @todo add reputation, events (including quest not available anymore, next quest available, go/npc de/spawning)and maybe honor
    TC_LOG_DEBUG("bg.battleground", "BG_AV Quest %i completed", questid);
    switch (questid)
    {
        case AV_QUEST_A_SCRAPS1:
        case AV_QUEST_A_SCRAPS2:
        case AV_QUEST_H_SCRAPS1:
        case AV_QUEST_H_SCRAPS2:
            _teamQuestStatus[team][0]+=20;
            if (_teamQuestStatus[team][0] == 500 || _teamQuestStatus[team][0] == 1000 || _teamQuestStatus[team][0] == 1500) //25, 50, 75 turn ins
            {
                TC_LOG_DEBUG("bg.battleground", "BG_AV Quest %i completed starting with unit upgrading..", questid);
                for (AVNodeId i = BG_AV_NODES_FIRSTAID_STATION; i <= BG_AV_NODES_FROSTWOLF_HUT; ++i)
                    if (m_Nodes[i].Owner == player->GetTeam() && m_Nodes[i].State == POINT_CONTROLED)
                    {
                        DePopulateNode(i);
                        PopulateNode(i);
                            //maybe this is bad, because it will instantly respawn all creatures on every grave..
                     }
            }
            break;
        case AV_QUEST_A_COMMANDER1:
        case AV_QUEST_H_COMMANDER1:
            _teamQuestStatus[team][1]++;
            RewardReputationToTeam(team, 1, BattlegroundTeamId(player->GetBGTeam()));
            if (_teamQuestStatus[team][1] == 30)
                TC_LOG_DEBUG("bg.battleground", "BG_AV Quest %i completed (need to implement some events here", questid);
            break;
        case AV_QUEST_A_COMMANDER2:
        case AV_QUEST_H_COMMANDER2:
            _teamQuestStatus[team][2]++;
            RewardReputationToTeam(team, 1, BattlegroundTeamId(player->GetBGTeam()));
            if (_teamQuestStatus[team][2] == 60)
                TC_LOG_DEBUG("bg.battleground", "BG_AV Quest %i completed (need to implement some events here", questid);
            break;
        case AV_QUEST_A_COMMANDER3:
        case AV_QUEST_H_COMMANDER3:
            _teamQuestStatus[team][3]++;
            RewardReputationToTeam(team, 1, BattlegroundTeamId(player->GetBGTeam()));
            if (m_Team_QuestStatus[team][1] == 120)
                TC_LOG_DEBUG("bg.battleground", "BG_AV Quest %i completed (need to implement some events here", questid);
            break;
        case AV_QUEST_A_BOSS1:
        case AV_QUEST_H_BOSS1:
            _teamQuestStatus[team][4] += 9; //you can turn in 10 or 1 item..
        case AV_QUEST_A_BOSS2:
        case AV_QUEST_H_BOSS2:
            _teamQuestStatus[team][4]++;
            if (_teamQuestStatus[team][4] >= 200)
                TC_LOG_DEBUG("bg.battleground", "BG_AV Quest %i completed (need to implement some events here", questid);
            break;
        case AV_QUEST_A_NEAR_MINE:
        case AV_QUEST_H_NEAR_MINE:
            _teamQuestStatus[team][5]++;
            if (_teamQuestStatus[team][5] == 28)
            {
                TC_LOG_DEBUG("bg.battleground", "BG_AV Quest %i completed (need to implement some events here", questid);
                if (_teamQuestStatus[team][6] == 7)
                    TC_LOG_DEBUG("bg.battleground", "BG_AV Quest %i completed (need to implement some events here - ground assault ready", questid);
            }
            break;
        case AV_QUEST_A_OTHER_MINE:
        case AV_QUEST_H_OTHER_MINE:
            _teamQuestStatus[team][6]++;
            if (_teamQuestStatus[team][6] == 7)
            {
                TC_LOG_DEBUG("bg.battleground", "BG_AV Quest %i completed (need to implement some events here", questid);
                if (_teamQuestStatus[team][5] == 20)
                    TC_LOG_DEBUG("bg.battleground", "BG_AV Quest %i completed (need to implement some events here - ground assault ready", questid);
            }
            break;
        case AV_QUEST_A_RIDER_HIDE:
        case AV_QUEST_H_RIDER_HIDE:
            _teamQuestStatus[team][7]++;
            if (_teamQuestStatus[team][7] == 25)
            {
                TC_LOG_DEBUG("bg.battleground", "BG_AV Quest %i completed (need to implement some events here", questid);
                if (_teamQuestStatus[team][8] == 25)
                    TC_LOG_DEBUG("bg.battleground", "BG_AV Quest %i completed (need to implement some events here - rider assault ready", questid);
            }
            break;
        case AV_QUEST_A_RIDER_TAME:
        case AV_QUEST_H_RIDER_TAME:
            _teamQuestStatus[team][8]++;
            if (_teamQuestStatus[team][8] == 25)
            {
                TC_LOG_DEBUG("bg.battleground", "BG_AV Quest %i completed (need to implement some events here", questid);
                if (_teamQuestStatus[team][7] == 25)
                    TC_LOG_DEBUG("bg.battleground", "BG_AV Quest %i completed (need to implement some events here - rider assault ready", questid);
            }
            break;
        default:
            TC_LOG_DEBUG("bg.battleground", "BG_AV Quest %i completed but is not interesting at all", questid);
            return; //was no interesting quest at all
            break;
    }
}

void BattlegroundAV::UpdateScore(uint16 team, int16 points)
{ //note: to remove reinforcementpoints points must be negative, for adding reinforcements points must be positive
    ASSERT(team == BG_TEAM_ALLIANCE || team == BG_TEAM_HORDE);
    TeamScores[team] += points;

    UpdateWorldState(((team == BG_TEAM_HORDE) ? AV_Horde_Score : AV_Alliance_Score), TeamScores[team]);
    if (points < 0)
    {
        if (TeamScores[team] < 1)
        {
            TeamScores[team] = 0;
            EndBattleground(((teamindex == TEAM_HORDE)?ALLIANCE:HORDE));
        }
        else if (!_isInformedNearVictory[team] && TeamScores[team] < SEND_MSG_NEAR_LOSE)
        {
            SendMessageToAll(teamindex == BG_TEAM_HORDE?LANG_BG_AV_H_NEAR_LOSE:LANG_BG_AV_A_NEAR_LOSE, teamindex == BG_TEAM_HORDE ? CHAT_MSG_BG_SYSTEM_HORDE : CHAT_MSG_BG_SYSTEM_ALLIANCE);
            PlaySoundToAll(AV_SOUND_NEAR_VICTORY);
            _isInformedNearVictory[team] = true;
        }
    }
}

Creature* BattlegroundAV::AddAVCreature(uint16 cinfoid, uint16 type)
{
    bool isStatic = false;
    Creature* creature = NULL;
    ASSERT(type <= AV_CPLACE_MAX + AV_STATICCPLACE_MAX);
    if (type >= AV_CPLACE_MAX) //static
    {
        type -= AV_CPLACE_MAX;
        cinfoid = uint16(BG_AV_StaticCreaturePos[type][4]);
        creature = AddCreature(BG_AV_StaticCreatureInfo[cinfoid],
                               type + AV_CPLACE_MAX,
                               BG_AV_StaticCreaturePos[type][0],
                               BG_AV_StaticCreaturePos[type][1],
                               BG_AV_StaticCreaturePos[type][2],
                               BG_AV_StaticCreaturePos[type][3]);
        isStatic = true;
    }
    else
    {
        creature = AddCreature(BG_AV_CreatureInfo[cinfoid], type, BG_AV_CreaturePos[type]);
    }
    if (!creature)
        return NULL;
    if (creature->GetEntry() == BG_AV_CreatureInfo[AV_NPC_A_CAPTAIN] || creature->GetEntry() == BG_AV_CreatureInfo[AV_NPC_H_CAPTAIN])
        creature->SetRespawnDelay(RESPAWN_ONE_DAY); /// @todo look if this can be done by database + also add this for the wingcommanders

    if ((isStatic && cinfoid >= 10 && cinfoid <= 14) || (!isStatic && ((cinfoid >= AV_NPC_A_GRAVEDEFENSE0 && cinfoid <= AV_NPC_A_GRAVEDEFENSE3) ||
        (cinfoid >= AV_NPC_H_GRAVEDEFENSE0 && cinfoid <= AV_NPC_H_GRAVEDEFENSE3))))
    {
        if (!isStatic && ((cinfoid >= AV_NPC_A_GRAVEDEFENSE0 && cinfoid <= AV_NPC_A_GRAVEDEFENSE3)
            || (cinfoid >= AV_NPC_H_GRAVEDEFENSE0 && cinfoid <= AV_NPC_H_GRAVEDEFENSE3)))
        {
            CreatureData &data = sObjectMgr->NewOrExistCreatureData(creature->GetDBTableGUIDLow());
            data.spawndist = 5;
        }
        //else spawndist will be 15, so creatures move maximum=10
        //creature->SetDefaultMovementType(RANDOM_MOTION_TYPE);
        creature->GetMotionMaster()->Initialize();
        creature->setDeathState(JUST_DIED);
        creature->Respawn();
        /// @todo find a way to add a motionmaster without killing the creature (i
        //just copied this code from a gm-command
    }

    uint32 triggerSpawnID = 0;
    uint32 newFaction = 0;
    if (creature->GetEntry() == BG_AV_CreatureInfo[AV_NPC_A_CAPTAIN])
    {
        triggerSpawnID = AV_CPLACE_TRIGGER16;
        newFaction = 84;
    }
    else if (creature->GetEntry() == BG_AV_CreatureInfo[AV_NPC_A_BOSS])
    {
        triggerSpawnID = AV_CPLACE_TRIGGER17;
        newFaction = 84;
    }
    else if (creature->GetEntry() == BG_AV_CreatureInfo[AV_NPC_H_CAPTAIN])
    {
        triggerSpawnID = AV_CPLACE_TRIGGER18;
        newFaction = 83;
    }
    else if (creature->GetEntry() == BG_AV_CreatureInfo[AV_NPC_H_BOSS])
    {
        triggerSpawnID = AV_CPLACE_TRIGGER19;
        newFaction = 83;
    }
    if (triggerSpawnID && newFaction)
    {
        if (Creature* trigger = AddCreature(WORLD_TRIGGER, triggerSpawnID, BG_AV_CreaturePos[triggerSpawnID]))
        {
            trigger->setFaction(newFaction);
            trigger->CastSpell(trigger, SPELL_HONORABLE_DEFENDER_25Y, false);
        }
    }

    return creature;
}

void BattlegroundAV::Update(uint32 diff)
{
    BattlegroundMap::ProcessInProgress(diff);
    for (uint8 i=0; i <= 1; i++)//0=alliance, 1=horde
    {
        if (!_captainAlive[i])
            continue;
        if (_captainBuffTimer[i] > diff)
            _captainBuffTimer[i] -= diff;
        else
        {
            if (i == 0)
            {
                CastSpellOnTeam(AV_BUFF_A_CAPTAIN, BG_TEAM_ALLIANCE);
                    if (Creature* creature = GetBGCreature(AV_CPLACE_MAX + 61))
                if (creature)
                        YellToAll(creature, LANG_BG_AV_A_CAPTAIN_BUFF, LANG_COMMON);
            }
            else
            {
                CastSpellOnTeam(AV_BUFF_H_CAPTAIN, BG_TEAM_HORDE);
                Creature* creature = GetCreature(AV_CPLACE_MAX + 59); //TODO: make the captains a dynamic creature
                if (creature)
            }
            _captainBuffTimer[i] = 120000 + urand(0, 4)* 60000; //as far as i could see, the buff is randomly so i make 2minutes (thats the duration of the buff itself) + 0-4minutes TODO get the right times
        }
    }
    //add points from mine owning, and look if he neutral team wanrts to reclaim the mine
    _mineTimer -=diff;
    for (uint8 mine=0; mine <2; mine++)
    {
        if (_mineOwner[mine] == BG_TEAM_ALLIANCE || _mineOwner[mine] == BG_TEAM_HORDE)
        {
            if (_mineTimer <= 0)
                UpdateScore(_mineOwner[mine], 1);

            if (_mineReclaimTimer[mine] > diff)
                _mineReclaimTimer[mine] -= diff;
            else{ //we don't need to set this timer to 0 cause this codepart wont get called when this thing is 0
                ChangeMineOwner(mine, BG_TEAMS_COUNT);
            }
        }
    }
    if (_mineTimer <= 0)
        _mineTimer=AV_MINE_TICK_TIMER; //this is at the end, cause we need to update both mines

    //looks for all timers of the nodes and destroy the building (for graveyards the building wont get destroyed, it goes just to the other team
    for (AVNodeId i = BG_AV_NODES_FIRSTAID_STATION; i < BG_AV_NODES_MAX; ++i)
        if (m_Nodes[i].State == POINT_ASSAULTED) //maybe remove this
        {
            if (m_Nodes[i].Timer > diff)
                m_Nodes[i].Timer -= diff;
            else
                EventPlayerDestroyedPoint(i);
        }
}
    TC_LOG_DEBUG("bg.battleground", "BG_AV: start spawning mine stuff");

    // Achievement: The Alterac Blitz
    StartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, BG_AV_EVENT_START_BATTLE);

void BattlegroundAV::OnPlayerJoin(Player *plr)
{
    Battleground::AddPlayer(plr);
    PlayerScores[player->GetGUID()] = new BattlegroundAVScore(player->GetGUID(), player->GetBGTeam());
    PlayerScores[plr->GetGUIDLow()] = sc;
    uint8 kills[2] = {0, 0}; // 0 = Alliance 1 = Horde
    uint8 rep[2] = {0, 0};   // 0 = Alliance 1 = Horde

    if (_maxLevel == 0)
        _maxLevel=(plr->getLevel()%10 == 0)? plr->getLevel() : (plr->getLevel()-(plr->getLevel()%10))+10; //TODO: just look at the code \^_^/ --but queue-info should provide this information..
            RewardReputationToTeam((i == 0)?730:729, rep[i], (i == 0)?ALLIANCE:HORDE);

    /// @todo add enterevademode for all attacking creatures
}

void BattlegroundAV::RemovePlayer(Player* player, ObjectGuid /*guid*/, uint32 /*team*/)
{
    if (!plr)
    {
        TC_LOG_ERROR("bg.battleground", "bg_AV no player at remove");
        return;
    }
    /// @todo search more buffs
    player->RemoveAurasDueToSpell(AV_BUFF_ARMOR);
    player->RemoveAurasDueToSpell(AV_BUFF_A_CAPTAIN);
    player->RemoveAurasDueToSpell(AV_BUFF_H_CAPTAIN);
}

void BattlegroundAV::HandleAreaTrigger(Player* player, uint32 trigger)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;

    switch (trigger)
    {
        case 95:
        case 2608:
            if (Source->GetTeam() != ALLIANCE)
                player->GetSession()->SendAreaTriggerMessage("Only The Alliance can use that portal");
            else
                player->LeaveBattleground();
            break;
        case 2606:
            if (Source->GetTeam() != BG_TEAM_HORDE)
                player->GetSession()->SendAreaTriggerMessage("Only The Horde can use that portal");
            else
                player->LeaveBattleground();
            break;
        case 3326:
        case 3327:
        case 3328:
        case 3329:
        case 3330:
        case 3331:
            //Source->Unmount();
            break;
        default:
            Battleground::HandleAreaTrigger(player, trigger);
            break;
    }
}

bool BattlegroundAV::UpdatePlayerScore(Player* player, uint32 type, uint32 value, bool doAddHonor)
{
    if (!Battleground::UpdatePlayerScore(player, type, value, doAddHonor))
        return false;

    switch (type)
    {
        case SCORE_GRAVEYARDS_ASSAULTED:
            player->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BG_OBJECTIVE_CAPTURE, AV_OBJECTIVE_ASSAULT_GRAVEYARD);
            break;
        case SCORE_GRAVEYARDS_DEFENDED:
            player->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BG_OBJECTIVE_CAPTURE, AV_OBJECTIVE_DEFEND_GRAVEYARD);
            break;
        case SCORE_TOWERS_ASSAULTED:
            player->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BG_OBJECTIVE_CAPTURE, AV_OBJECTIVE_ASSAULT_TOWER);
            break;
        case SCORE_TOWERS_DEFENDED:
            player->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BG_OBJECTIVE_CAPTURE, AV_OBJECTIVE_DEFEND_TOWER);
        default:
            BattlegroundMap::UpdatePlayerScore(Source, type, value, doAddHonor);
            break;
    }
    return true;
}

void BattlegroundAV::EventPlayerDestroyedPoint(AVNodeId node)
{
    uint32 object = GetObjectThroughNode(node);
    TC_LOG_DEBUG("bg.battleground", "bg_av: player destroyed point node %i object %i", node, object);

    //despawn banner
    SpawnGameObject(object, RESPAWN_ONE_DAY);
    DestroyNode(node);
    UpdateNodeWorldState(node);

    uint32 owner = m_Nodes[node].Owner;
    if (IsTower(node))
    {
        uint8 tmp = node-BG_AV_NODES_DUNBALDAR_SOUTH;

        //despawn marshal
        if (m_BgCreatures[AV_CPLACE_A_MARSHAL_SOUTH + tmp])

        //spawn destroyed aura
        for (uint8 i=0; i <= 9; i++)
            SpawnGameObject(BG_AV_OBJECT_BURN_DUNBALDAR_SOUTH + i + (tmp * 10), RESPAWN_IMMEDIATELY);

        UpdateScore((owner == ALLIANCE) ? HORDE : ALLIANCE, -1 * BG_AV_RES_TOWER);
        RewardReputationToTeam(owner == ALLIANCE ? 730 : 729, BG_AV_REP_TOWER, owner);
        RewardHonorToTeam(GetBonusHonorFromKill(BG_AV_KILL_TOWER), owner);

        SpawnGameObject(BG_AV_OBJECT_TAURA_A_DUNBALDAR_SOUTH+ owner+(2*tmp), RESPAWN_ONE_DAY);
        SpawnGameObject(BG_AV_OBJECT_TFLAG_A_DUNBALDAR_SOUTH+ owner+(2*tmp), RESPAWN_ONE_DAY);
    }
    else
    {
        if (owner == BG_TEAM_ALLIANCE)
            SpawnGameObject(object-11, RESPAWN_IMMEDIATELY);
        else
            SpawnGameObject(object+11, RESPAWN_IMMEDIATELY);
        SpawnGameObject(BG_AV_OBJECT_AURA_N_FIRSTAID_STATION+3*node, RESPAWN_ONE_DAY);
        SpawnGameObject(BG_AV_OBJECT_AURA_A_FIRSTAID_STATION+owner+3*node, RESPAWN_IMMEDIATELY);
        PopulateNode(node);
        if (node == BG_AV_NODES_SNOWFALL_GRAVE) //snowfall eyecandy
        {
            for (uint8 i = 0; i < 4; i++)
            {
                SpawnGameObject(((owner == BG_TEAM_ALLIANCE)?BG_AV_OBJECT_SNOW_EYECANDY_PA : BG_AV_OBJECT_SNOW_EYECANDY_PH)+i, RESPAWN_ONE_DAY);
                SpawnGameObject(((owner == BG_TEAM_ALLIANCE)?BG_AV_OBJECT_SNOW_EYECANDY_A  : BG_AV_OBJECT_SNOW_EYECANDY_H)+i, RESPAWN_IMMEDIATELY);
            }
        }
    }
        sprintf(buf, sObjectMgr->GetTrinityStringForDBCLocale(LANG_BG_AV_TOWER_TAKEN), GetNodeName(node), (owner == BG_TEAM_ALLIANCE) ? sObjectMgr->GetTrinityStringForDBCLocale(LANG_BG_AV_ALLY) : sObjectMgr->GetTrinityStringForDBCLocale(LANG_BG_AV_HORDE));

    Creature* creature = GetCreature(AV_CPLACE_HERALD);
        if (Creature* herold = GetBGCreature(AV_CPLACE_HERALD))
        YellToAll(creature, buf, LANG_UNIVERSAL);
}

void BattlegroundAV::ChangeMineOwner(uint8 mine, uint32 team, bool initial)
{
    // mine=0 northmine mine=1 southmin
    // changing the owner results in setting respawntim to infinite for current creatures,
    // spawning new mine owners creatures and changing the chest-objects so that the current owning team can use them
    ASSERT(mine == AV_NORTH_MINE || mine == AV_SOUTH_MINE);
    if (team != BG_TEAM_ALLIANCE && team != BG_TEAM_HORDE)
        team = BG_TEAMS_COUNT;
        PlaySoundToAll((team == ALLIANCE)?AV_SOUND_ALLIANCE_GOOD:AV_SOUND_HORDE_GOOD);

    if (_mineOwner[mine] == team && !initial)
        return;
    _minePreviousOwner[mine] = _mineOwner[mine];
    _mineOwner[mine] = team;

    if (!initial)
    {
        TC_LOG_DEBUG("bg.battleground", "bg_av depopulating mine %i (0=north, 1=south)", mine);
        if (mine == AV_SOUTH_MINE)
            for (uint16 i=AV_CPLACE_MINE_S_S_MIN; i <= AV_CPLACE_MINE_S_S_MAX; i++)
                if (!BgCreatures[i].IsEmpty())
                    DelCreature(i); /// @todo just set the respawntime to 999999
        for (uint16 i=((mine == AV_NORTH_MINE)?AV_CPLACE_MINE_N_1_MIN:AV_CPLACE_MINE_S_1_MIN); i <= ((mine == AV_NORTH_MINE)?AV_CPLACE_MINE_N_3:AV_CPLACE_MINE_S_3); i++)
                DeleteCreature(i); //TODO here also
    }
    SendMineWorldStates(mine);

    TC_LOG_DEBUG("bg.battleground", "bg_av populating mine %i (0=north, 1=south)", mine);
    uint16 miner;
    //also neutral team exists.. after a big time, the neutral team tries to conquer the mine
    if (mine == AV_NORTH_MINE)
    {
        if (team == BG_TEAM_ALLIANCE)
            miner = AV_NPC_N_MINE_A_1;
        else if (team == BG_TEAM_HORDE)
            miner = AV_NPC_N_MINE_H_1;
        else
            miner = AV_NPC_N_MINE_N_1;
    }
    else
    {
        uint16 cinfo;
        if (team == BG_TEAM_ALLIANCE)
            miner = AV_NPC_S_MINE_A_1;
        else if (team == BG_TEAM_HORDE)
            miner = AV_NPC_S_MINE_H_1;
        else
            miner = AV_NPC_S_MINE_N_1;
       //vermin
        TC_LOG_DEBUG("bg.battleground", "spawning vermin");
        if (team == BG_TEAM_ALLIANCE)
            cinfo = AV_NPC_S_MINE_A_3;
        else if (team == BG_TEAM_HORDE)
            cinfo = AV_NPC_S_MINE_H_3;
        else
            cinfo = AV_NPC_S_MINE_N_S;
        for (uint16 i=AV_CPLACE_MINE_S_S_MIN; i <= AV_CPLACE_MINE_S_S_MAX; i++)
            AddAVCreature(cinfo, i);
    }
    for (uint16 i=((mine == AV_NORTH_MINE)?AV_CPLACE_MINE_N_1_MIN:AV_CPLACE_MINE_S_1_MIN); i <= ((mine == AV_NORTH_MINE)?AV_CPLACE_MINE_N_1_MAX:AV_CPLACE_MINE_S_1_MAX); i++)
        AddAVCreature(miner, i);
    //the next chooses randomly between 2 cretures
    for (uint16 i=((mine == AV_NORTH_MINE)?AV_CPLACE_MINE_N_2_MIN:AV_CPLACE_MINE_S_2_MIN); i <= ((mine == AV_NORTH_MINE)?AV_CPLACE_MINE_N_2_MAX:AV_CPLACE_MINE_S_2_MAX); i++)
        AddAVCreature(miner+(urand(1, 2)), i);
    AddAVCreature(miner+3, (mine == AV_NORTH_MINE)?AV_CPLACE_MINE_N_3:AV_CPLACE_MINE_S_3);

    if (team == BG_TEAM_ALLIANCE || team == BG_TEAM_HORDE)
    {
        _mineReclaimTimer[mine]=AV_MINE_RECLAIM_TIMER;

        sprintf(buf, GetTrinityString(LANG_BG_AV_MINE_TAKEN), GetTrinityString((mine == AV_NORTH_MINE) ? LANG_BG_AV_MINE_NORTH : LANG_BG_AV_MINE_SOUTH), (team == ALLIANCE) ?  GetTrinityString(LANG_BG_AV_ALLY) : GetTrinityString(LANG_BG_AV_HORDE));
        Creature* creature = GetBGCreature(AV_CPLACE_HERALD);
            if (mine == AV_NORTH_MINE)
            SendMessageToAll(buf, CHAT_MSG_MONSTER_YELL, creature);
            else if (mine == AV_SOUTH_MINE)
                herold->AI()->Talk(team == ALLIANCE ? TEXT_COLDTOOTH_MINE_ALLIANCE_TAKEN : TEXT_COLDTOOTH_MINE_HORDE_TAKEN);
        }
    }
    else
    {
        if (mine == AV_SOUTH_MINE) //i think this gets called all the time
        {
            if (Creature* creature = GetCreature(AV_CPLACE_MINE_S_3))
                creature->AI()->Talk(TEXT_SNIVVLE_RANDOM);
        }
    }
    return;
}

bool BattlegroundAV::CanActivateGO(int32 GOId, uint32 team) const
{
    if (GOId == BG_AV_OBJECTID_MINE_N)
         return (_mineOwner[AV_NORTH_MINE] == team);
    if (GOId == BG_AV_OBJECTID_MINE_S)
         return (_mineOwner[AV_SOUTH_MINE] == team);
    return true; //cause it's no mine'object it is ok if this is true
}

void BattlegroundAV::PopulateNode(AVNodeId node)
{
    uint32 owner = m_Nodes[node].Owner;
    ASSERT(owner == BG_TEAM_ALLIANCE || owner == BG_TEAM_HORDE);

    uint32 c_place = AV_CPLACE_DEFENSE_STORM_AID + (4 * node);
    uint32 creatureid;
    if (IsTower(node))
        creatureid=(owner == BG_TEAM_ALLIANCE)?AV_NPC_A_TOWERDEFENSE:AV_NPC_H_TOWERDEFENSE;
    else
    {
        if (_teamQuestStatus[owner][0] < 500)
            creatureid = (owner == BG_TEAM_ALLIANCE) ? AV_NPC_A_GRAVEDEFENSE0 : AV_NPC_H_GRAVEDEFENSE0;
        else if (_teamQuestStatus[owner][0] < 1000)
            creatureid = (owner == BG_TEAM_ALLIANCE) ? AV_NPC_A_GRAVEDEFENSE1 : AV_NPC_H_GRAVEDEFENSE1;
        else if (_teamQuestStatus[owner][0] < 1500)
            creatureid = (owner == BG_TEAM_ALLIANCE) ? AV_NPC_A_GRAVEDEFENSE2 : AV_NPC_H_GRAVEDEFENSE2;
        else
            creatureid = (owner == BG_TEAM_ALLIANCE) ? AV_NPC_A_GRAVEDEFENSE3 : AV_NPC_H_GRAVEDEFENSE3;
        
        //spiritguide
        DeleteCreature(node);
        if (!AddSpiritGuide(node, BG_AV_CreaturePos[node][0], BG_AV_CreaturePos[node][1], BG_AV_CreaturePos[node][2], BG_AV_CreaturePos[node][3], owner))
            sLog->outError("AV: couldn't spawn spiritguide at node %i", node);
        AddSpiritGuide(node, BG_AV_CreaturePos[node][0], BG_AV_CreaturePos[node][1], BG_AV_CreaturePos[node][2], BG_AV_CreaturePos[node][3], owner);
    }
    for (uint8 i=0; i<4; i++)
        AddAVCreature(creatureid, c_place+i);

    if (node >= BG_AV_NODES_MAX)//fail safe
        return;
    Creature* trigger = GetCreature(node + 302);//0-302 other creatures
    if (!trigger)
    {
       trigger = AddCreature(WORLD_TRIGGER,
                             node + 302,
                             BG_AV_CreaturePos[node + 302],
                             GetTeamIndexByTeamId(owner));
    }

    //add bonus honor aura trigger creature when node is accupied
    //cast bonus aura (+50% honor in 25yards)
    //aura should only apply to players who have accupied the node, set correct faction for trigger
    if (trigger)
    {
        if (owner != BG_TEAM_ALLIANCE && owner != BG_TEAM_HORDE)//node can be neutral, remove trigger
        {
            DeleteCreature(node + 302);
            return;
        }
        trigger->setFaction(owner == BG_TEAM_ALLIANCE ? 84 : 83);
        trigger->CastSpell(trigger, SPELL_HONORABLE_DEFENDER_25Y, false);
    }
}
void BattlegroundAV::DePopulateNode(AVNodeId node)
{
    uint32 c_place = AV_CPLACE_DEFENSE_STORM_AID + (4 * node);
    for (uint8 i = 0; i < 4; i++)
        if (!BgCreatures[c_place + i].IsEmpty())
    
    //spiritguide
    if (!IsTower(node) && m_BgCreatures[node])
        DeleteCreature(node);

    //remove bonus honor aura trigger creature when node is lost
    if (node < BG_AV_NODES_MAX)//fail safe
        DeleteCreature(node + 302);//NULL checks are in DeleteCreature! 0-302 spirit guides
}

AVNodeId BattlegroundAV::GetNodeThroughObject(uint32 object)
{
    TC_LOG_DEBUG("bg.battleground", "bg_AV getnodethroughobject %i", object);
    if (object <= BG_AV_OBJECT_FLAG_A_STONEHEART_BUNKER)
        return AVNodeId(object);
    if (object <= BG_AV_OBJECT_FLAG_C_A_FROSTWOLF_HUT)
        return AVNodeId(object - 11);
    if (object <= BG_AV_OBJECT_FLAG_C_A_FROSTWOLF_WTOWER)
        return AVNodeId(object - 7);
    if (object <= BG_AV_OBJECT_FLAG_C_H_STONEHEART_BUNKER)
        return AVNodeId(object -22);
    if (object <= BG_AV_OBJECT_FLAG_H_FROSTWOLF_HUT)
        return AVNodeId(object - 33);
    if (object <= BG_AV_OBJECT_FLAG_H_FROSTWOLF_WTOWER)
        return AVNodeId(object - 29);
    if (object == BG_AV_OBJECT_FLAG_N_SNOWFALL_GRAVE)
        return BG_AV_NODES_SNOWFALL_GRAVE;
    TC_LOG_ERROR("bg.battleground", "BattlegroundAV: ERROR! GetPlace got a wrong object :(");
    ASSERT(false);
    return AVNodeId(0);
}

uint32 BattlegroundAV::GetObjectThroughNode(AVNodeId node)
{ //this function is the counterpart to GetNodeThroughObject()
    TC_LOG_DEBUG("bg.battleground", "bg_AV GetObjectThroughNode %i", node);
    if (m_Nodes[node].Owner == BG_TEAM_ALLIANCE)
    {
        if (m_Nodes[node].State == POINT_ASSAULTED)
        {
            if (node <= BG_AV_NODES_FROSTWOLF_HUT)
                return node+11;
            if (node >= BG_AV_NODES_ICEBLOOD_TOWER && node <= BG_AV_NODES_FROSTWOLF_WTOWER)
                return node+7;
        }
        else if (m_Nodes[node].State == POINT_CONTROLED)
            if (node <= BG_AV_NODES_STONEHEART_BUNKER)
                return node;
    }
    else if (m_Nodes[node].Owner == BG_TEAM_HORDE)
    {
        if (m_Nodes[node].State == POINT_ASSAULTED)
        {
            if (node <= BG_AV_NODES_STONEHEART_BUNKER)
                return node+22;
        }
        else if (m_Nodes[node].State == POINT_CONTROLED)
        {
            if (node <= BG_AV_NODES_FROSTWOLF_HUT)
                return node+33;
            if (node >= BG_AV_NODES_ICEBLOOD_TOWER && node <= BG_AV_NODES_FROSTWOLF_WTOWER)
                return node+29;
        }
    }
    else if (m_Nodes[node].Owner == BG_TEAMS_COUNT)
        return BG_AV_OBJECT_FLAG_N_SNOWFALL_GRAVE;
    TC_LOG_ERROR("bg.battleground", "BattlegroundAV: Error! GetPlaceNode couldn't resolve node %i", node);
    ASSERT(false);
    return 0;
}

//called when using banner

void BattlegroundAV::EventPlayerClickedOnFlag(Player* source, GameObject* target_obj)
{
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;
    int32 object = GetObjectType(target_obj->GetGUID());
    TC_LOG_DEBUG("bg.battleground", "BG_AV using gameobject %i with type %i", target_obj->GetEntry(), object);
    if (object < 0)
        return;
    switch (target_obj->GetEntry())
    {
        case BG_AV_OBJECTID_BANNER_A:
        case BG_AV_OBJECTID_BANNER_A_B:
        case BG_AV_OBJECTID_BANNER_H:
        case BG_AV_OBJECTID_BANNER_H_B:
        case BG_AV_OBJECTID_BANNER_SNOWFALL_N:
            EventPlayerAssaultsPoint(source, object);
            break;
        case BG_AV_OBJECTID_BANNER_CONT_A:
        case BG_AV_OBJECTID_BANNER_CONT_A_B:
        case BG_AV_OBJECTID_BANNER_CONT_H:
        case BG_AV_OBJECTID_BANNER_CONT_H_B:
            EventPlayerDefendsPoint(source, object);
            break;
        default:
            break;
    }
}

void BattlegroundAV::EventPlayerDefendsPoint(Player* player, uint32 object)
{
    ASSERT(GetStatus() == STATUS_IN_PROGRESS);
    AVNodeId node = GetNodeThroughObject(object);

    BattlegroundTeamId owner = m_Nodes[node].Owner; //maybe should name it prevowner
    BattlegroundTeamId team = BattlegroundTeamId(player->GetBGTeam());

    if (owner == team || m_Nodes[node].State != POINT_ASSAULTED)
        return;

    if (m_Nodes[node].TotalOwner == BG_TEAMS_COUNT) // Neutral
    { //until snowfall doesn't belong to anyone it is better handled in assault-code
        ASSERT(node == BG_AV_NODES_SNOWFALL_GRAVE); //currently the only neutral grave
        EventPlayerAssaultsPoint(player, object);
        return;
    }
    TC_LOG_DEBUG("bg.battleground", "player defends point object: %i node: %i", object, node);
    if (m_Nodes[node].PrevOwner != team)
    {
        TC_LOG_ERROR("bg.battleground", "BG_AV: player defends point which doesn't belong to his team %i", node);
        return;
    }

   //spawn new go :)
    if (m_Nodes[node].Owner == BG_TEAM_ALLIANCE)
        SpawnGameObject(object+22, RESPAWN_IMMEDIATELY); //spawn horde banner
    else
        SpawnGameObject(object-22, RESPAWN_IMMEDIATELY); //spawn alliance banner

    if (!IsTower(node))
    {
        SpawnGameObject(BG_AV_OBJECT_AURA_N_FIRSTAID_STATION+3*node, RESPAWN_ONE_DAY);
        SpawnGameObject(BG_AV_OBJECT_AURA_A_FIRSTAID_STATION+team+3*node, RESPAWN_IMMEDIATELY);
    }
        // despawn old go
    SpawnGameObject(object, RESPAWN_ONE_DAY);

    DefendNode(node, team);
    PopulateNode(node);
    UpdateNodeWorldState(node);

    if (IsTower(node))
    {
        //spawn big flag+aura on top of tower
        SpawnGameObject(BG_AV_OBJECT_TAURA_A_DUNBALDAR_SOUTH+(2*(node-BG_AV_NODES_DUNBALDAR_SOUTH)), (team == BG_TEAM_ALLIANCE)? RESPAWN_IMMEDIATELY : RESPAWN_ONE_DAY);
        SpawnGameObject(BG_AV_OBJECT_TAURA_H_DUNBALDAR_SOUTH+(2*(node-BG_AV_NODES_DUNBALDAR_SOUTH)), (team == BG_TEAM_HORDE)? RESPAWN_IMMEDIATELY : RESPAWN_ONE_DAY);
        SpawnGameObject(BG_AV_OBJECT_TFLAG_A_DUNBALDAR_SOUTH+(2*(node-BG_AV_NODES_DUNBALDAR_SOUTH)), (team == BG_TEAM_ALLIANCE)? RESPAWN_IMMEDIATELY : RESPAWN_ONE_DAY);
        SpawnGameObject(BG_AV_OBJECT_TFLAG_H_DUNBALDAR_SOUTH+(2*(node-BG_AV_NODES_DUNBALDAR_SOUTH)), (team == BG_TEAM_HORDE)? RESPAWN_IMMEDIATELY : RESPAWN_ONE_DAY);
    }
    else if (node == BG_AV_NODES_SNOWFALL_GRAVE) //snowfall eyecandy
    {
        for (uint8 i = 0; i < 4; i++)
        {
            SpawnGameObject(((owner == BG_TEAM_ALLIANCE)?BG_AV_OBJECT_SNOW_EYECANDY_PA : BG_AV_OBJECT_SNOW_EYECANDY_PH)+i, RESPAWN_ONE_DAY);
            SpawnGameObject(((team == BG_TEAM_ALLIANCE)?BG_AV_OBJECT_SNOW_EYECANDY_A : BG_AV_OBJECT_SNOW_EYECANDY_H)+i, RESPAWN_IMMEDIATELY);
        }
    }

    if (StaticNodeInfo const* nodeInfo = GetStaticNodeInfo(node))
        if (Creature* herold = GetBGCreature(AV_CPLACE_HERALD))
            herold->AI()->Talk(team == ALLIANCE ? nodeInfo->TextIds.AllianceCapture : nodeInfo->TextIds.HordeCapture);

        SendMessageToAll(buf, CHAT_MSG_MONSTER_YELL, creature);
    // update the statistic for the defending player
    UpdatePlayerScore(player, IsTower(node) ? SCORE_TOWERS_DEFENDED : SCORE_GRAVEYARDS_DEFENDED, 1);
        PlaySoundToAll((team == ALLIANCE)?AV_SOUND_ALLIANCE_GOOD:AV_SOUND_HORDE_GOOD);
}

void BattlegroundAV::EventPlayerAssaultsPoint(Player* player, uint32 object)
{
    ASSERT(GetStatus() == STATUS_IN_PROGRESS);

    AVNodeId node = GetNodeThroughObject(object);
    BattlegroundTeamId owner = m_Nodes[node].Owner; //maybe name it prevowner
    BattlegroundTeamId team  = BattlegroundTeamId(player->GetBGTeam());
    TC_LOG_DEBUG("bg.battleground", "bg_av: player assaults point object %i node %i", object, node);
    if (owner == team || team == m_Nodes[node].TotalOwner)
        return; //surely a gm used this object

    if (node == BG_AV_NODES_SNOWFALL_GRAVE) //snowfall is a bit special in capping + it gets eyecandy stuff
    {
        if (object == BG_AV_OBJECT_FLAG_N_SNOWFALL_GRAVE) //initial capping
        {
            ASSERT(owner == BG_TEAMS_COUNT && m_Nodes[node].TotalOwner == BG_TEAMS_COUNT);
            if (team == BG_TEAM_ALLIANCE)
                SpawnGameObject(BG_AV_OBJECT_FLAG_C_A_SNOWFALL_GRAVE, RESPAWN_IMMEDIATELY);
            else
                SpawnGameObject(BG_AV_OBJECT_FLAG_C_H_SNOWFALL_GRAVE, RESPAWN_IMMEDIATELY);
            SpawnGameObject(BG_AV_OBJECT_AURA_N_FIRSTAID_STATION+3*node, RESPAWN_IMMEDIATELY); //neutral aura spawn
        }
        else if (m_Nodes[node].TotalOwner == BG_TEAMS_COUNT) //recapping, when no team owns this node realy
        {
            if (!(m_Nodes[node].State != POINT_CONTROLED))
            if (team == BG_TEAM_ALLIANCE)
                SpawnGameObject(object-11, RESPAWN_IMMEDIATELY);
            else
                SpawnGameObject(object+11, RESPAWN_IMMEDIATELY);
        }
        //eyecandy
        uint32 spawn, despawn;
        if (team == BG_TEAM_ALLIANCE)
        {
            despawn = (m_Nodes[node].State == POINT_ASSAULTED)?BG_AV_OBJECT_SNOW_EYECANDY_PH : BG_AV_OBJECT_SNOW_EYECANDY_H;
            spawn = BG_AV_OBJECT_SNOW_EYECANDY_PA;
        }
        else
        {
            despawn = (m_Nodes[node].State == POINT_ASSAULTED)?BG_AV_OBJECT_SNOW_EYECANDY_PA : BG_AV_OBJECT_SNOW_EYECANDY_A;
            spawn = BG_AV_OBJECT_SNOW_EYECANDY_PH;
        }
        for (uint8 i = 0; i < 4; i++)
        {
            SpawnGameObject(despawn+i, RESPAWN_ONE_DAY);
            SpawnGameObject(spawn+i, RESPAWN_IMMEDIATELY);
        }
    }

    //if snowfall gots capped it can be handled like all other graveyards
    if (m_Nodes[node].TotalOwner != BG_TEAMS_COUNT)
    {
        ASSERT(m_Nodes[node].Owner != BG_TEAMS_COUNT);
        if (team == BG_TEAM_ALLIANCE)
            SpawnGameObject(object-22, RESPAWN_IMMEDIATELY);
        else
            SpawnGameObject(object+22, RESPAWN_IMMEDIATELY);
        if (IsTower(node))
        { //spawning/despawning of bigflag+aura
            SpawnGameObject(BG_AV_OBJECT_TAURA_A_DUNBALDAR_SOUTH+(2*(node-BG_AV_NODES_DUNBALDAR_SOUTH)), (team == BG_TEAM_ALLIANCE)? RESPAWN_IMMEDIATELY : RESPAWN_ONE_DAY);
            SpawnGameObject(BG_AV_OBJECT_TAURA_H_DUNBALDAR_SOUTH+(2*(node-BG_AV_NODES_DUNBALDAR_SOUTH)), (team == BG_TEAM_HORDE)? RESPAWN_IMMEDIATELY : RESPAWN_ONE_DAY);
            SpawnGameObject(BG_AV_OBJECT_TFLAG_A_DUNBALDAR_SOUTH+(2*(node-BG_AV_NODES_DUNBALDAR_SOUTH)), (team == BG_TEAM_ALLIANCE)? RESPAWN_IMMEDIATELY : RESPAWN_ONE_DAY);
            SpawnGameObject(BG_AV_OBJECT_TFLAG_H_DUNBALDAR_SOUTH+(2*(node-BG_AV_NODES_DUNBALDAR_SOUTH)), (team == BG_TEAM_HORDE)? RESPAWN_IMMEDIATELY : RESPAWN_ONE_DAY);
        }
        else
        {
            //spawning/despawning of aura
            SpawnGameObject(BG_AV_OBJECT_AURA_N_FIRSTAID_STATION+3*node, RESPAWN_IMMEDIATELY); //neutral aura spawn
            SpawnGameObject(BG_AV_OBJECT_AURA_A_FIRSTAID_STATION+owner+3*node, RESPAWN_ONE_DAY); //teeamaura despawn

            std::vector<uint64> ghost_list = ReviveQueue[ObjectGUIDsByType[node]];
                        plr->TeleportTo(GetId(), ClosestGrave->x, ClosestGrave->y, ClosestGrave->z, plr->GetOrientation());

                ReviveQueue[ObjectGUIDsByType[node]].clear();
        }

        DePopulateNode(node);
    }

    SpawnGameObject(object, RESPAWN_ONE_DAY); //delete old banner
    AssaultNode(node, team);
    UpdateNodeWorldState(node);

    if (StaticNodeInfo const* nodeInfo = GetStaticNodeInfo(node))
        if (Creature* herold = GetBGCreature(AV_CPLACE_HERALD))
    sprintf(buf, (IsTower(node)) ? sObjectMgr->GetTrinityStringForDBCLocale(LANG_BG_AV_TOWER_ASSAULTED) : sObjectMgr->GetTrinityStringForDBCLocale(LANG_BG_AV_GRAVE_ASSAULTED), GetNodeName(node),  (team == BG_TEAM_ALLIANCE) ?  sObjectMgr->GetTrinityStringForDBCLocale(LANG_BG_AV_ALLY) : sObjectMgr->GetTrinityStringForDBCLocale(LANG_BG_AV_HORDE));
    Creature* creature = GetCreature(AV_CPLACE_HERALD);
        SendMessageToAll(buf, CHAT_MSG_MONSTER_YELL, creature);
    // update the statistic for the assaulting player
    UpdatePlayerScore(player, (IsTower(node)) ? SCORE_TOWERS_ASSAULTED : SCORE_GRAVEYARDS_ASSAULTED, 1);
}

void BattlegroundAV::FillInitialWorldStates(WorldPacket& data)
{
    for (uint8 i = BG_AV_NODES_FIRSTAID_STATION; i < BG_AV_NODES_MAX; ++i)
    {
        uint16 owner = m_Nodes[i].Owner;
        BG_AV_States state = m_Nodes[i].State;
            data << uint32(BG_AV_NodeWorldStates[i][GetWorldStateType(j, BG_TEAM_ALLIANCE)]) << uint32((m_Nodes[i].Owner == BG_TEAM_ALLIANCE && stateok)?1:0);
            data << uint32(BG_AV_NodeWorldStates[i][GetWorldStateType(j, BG_TEAM_HORDE)]) << uint32((m_Nodes[i].Owner == BG_TEAM_HORDE && stateok)?1:0);

        data << uint32(BGAVNodeInfo[i].WorldStateIds.AllianceAssault) << uint32(owner == ALLIANCE && state == POINT_ASSAULTED);
        data << uint32(BGAVNodeInfo[i].WorldStateIds.AllianceControl) << uint32(owner == ALLIANCE && state >= POINT_DESTROYED);
        data << uint32(BGAVNodeInfo[i].WorldStateIds.HordeAssault) << uint32(owner == HORDE && state == POINT_ASSAULTED);
        data << uint32(BGAVNodeInfo[i].WorldStateIds.HordeControl) << uint32(owner == HORDE && state >= POINT_DESTROYED);
            data << uint32(BG_AV_NodeWorldStates[i][GetWorldStateType(j, ALLIANCE)]) << uint32((m_Nodes[i].Owner == ALLIANCE && stateok)?1:0);
            data << uint32(BG_AV_NodeWorldStates[i][GetWorldStateType(j, HORDE)]) << uint32((m_Nodes[i].Owner == HORDE && stateok)?1:0);
    }
    if (m_Nodes[BG_AV_NODES_SNOWFALL_GRAVE].Owner == BG_TEAMS_COUNT) //cause neutral teams aren't handled generic
    data << uint32(AV_SNOWFALL_N) << uint32(m_Nodes[BG_AV_NODES_SNOWFALL_GRAVE].Owner == AV_NEUTRAL_TEAM);

    data << uint32(AV_Horde_Score) << uint32(TeamScores[1]);
    if (GetStatus() == STATUS_IN_PROGRESS){ //only if game started the teamscores are displayed
        data << uint32(AV_SHOW_A_SCORE) << uint32(1);
        data << uint32(AV_SHOW_H_SCORE) << uint32(1);
    }
    else
    {
        data << uint32(AV_SHOW_A_SCORE) << uint32(0);
        data << uint32(AV_SHOW_H_SCORE) << uint32(0);
    }
    SendMineWorldStates(AV_NORTH_MINE);
    SendMineWorldStates(AV_SOUTH_MINE);
}

void BattlegroundAV::UpdateNodeWorldState(BG_AV_Nodes node)
{
    if (StaticNodeInfo const* nodeInfo = GetStaticNodeInfo(node))
    ASSERT(team != BG_TEAMS_COUNT);
    if (team == BG_TEAM_ALLIANCE)
    if (team == HORDE)
    {
        uint16 owner = m_Nodes[node].Owner;
        BG_AV_States state = m_Nodes[node].State;

        UpdateWorldState(nodeInfo->WorldStateIds.AllianceAssault, owner == ALLIANCE && state == POINT_ASSAULTED);
        UpdateWorldState(nodeInfo->WorldStateIds.AllianceControl, owner == ALLIANCE && state >= POINT_DESTROYED);
        UpdateWorldState(nodeInfo->WorldStateIds.HordeAssault, owner == HORDE && state == POINT_ASSAULTED);
        UpdateWorldState(nodeInfo->WorldStateIds.HordeControl, owner == HORDE && state >= POINT_DESTROYED);
    }

void BattlegroundAV::UpdateNodeWorldState(AVNodeId node)
        UpdateWorldState(AV_SNOWFALL_N, m_Nodes[node].Owner == AV_NEUTRAL_TEAM);
}

void BattlegroundAV::SendMineWorldStates(uint32 mine)
{
    ASSERT(mine == AV_NORTH_MINE || mine == AV_SOUTH_MINE);
// currently i'm sure, that this works (:
//    ASSERT(m_Mine_PrevOwner[mine] == BG_TEAM_ALLIANCE || m_Mine_PrevOwner[mine] == BG_TEAM_HORDE || m_Mine_PrevOwner[mine] == BG_TEAMS_COUNT);
//    ASSERT(m_Mine_Owner[mine] == BG_TEAM_ALLIANCE || m_Mine_Owner[mine] == BG_TEAM_HORDE || m_Mine_Owner[mine] == BG_TEAMS_COUNT);

    uint8 owner, prevowner, mine2; //those variables are needed to access the right worldstate in the BG_AV_MineWorldStates array
    mine2 = (mine == AV_NORTH_MINE)?0:1;
    if (_minePreviousOwner[mine] == BG_TEAM_ALLIANCE)
        prevowner = 0;
    else if (_minePreviousOwner[mine] == BG_TEAM_HORDE)
        prevowner = 2;
    else
        prevowner = 1;
    if (_mineOwner[mine] == BG_TEAM_ALLIANCE)
        owner = 0;
    else if (_mineOwner[mine] == BG_TEAM_HORDE)
        owner = 2;
    else
        owner = 1;

    UpdateWorldState(BG_AV_MineWorldStates[mine2][owner], 1);
    if (prevowner != owner)
        UpdateWorldState(BG_AV_MineWorldStates[mine2][prevowner], 0);
}

WorldSafeLocsEntry const* BattlegroundAV::GetClosestGraveYard(Player* player)
{
    WorldSafeLocsEntry const* pGraveyard = NULL;
    WorldSafeLocsEntry const* entry = NULL;
    float dist = 0;
    float minDist = 0;
    float x, y;

    player->GetPosition(x, y);

    pGraveyard = sWorldSafeLocsStore.LookupEntry(BG_AV_GraveyardIds[player->GetBGTeam()+7]);
    minDist = (pGraveyard->Loc.X - x)*(pGraveyard->Loc.X - x)+(pGraveyard->Loc.Y - y)*(pGraveyard->Loc.Y - y);

    for (uint8 i = BG_AV_NODES_FIRSTAID_STATION; i <= BG_AV_NODES_FROSTWOLF_HUT; ++i)
        if (m_Nodes[i].Owner == player->GetTeam() && m_Nodes[i].State == POINT_CONTROLED)
        {
            entry = sWorldSafeLocsStore.LookupEntry(BG_AV_GraveyardIds[i]);
            if (entry)
            {
                dist = (entry->Loc.X - x)*(entry->Loc.X - x)+(entry->Loc.Y - y)*(entry->Loc.Y - y);
                if (dist < minDist)
                {
                    minDist = dist;
                    pGraveyard = entry;
                }
            }
        }
    return pGraveyard;
}

        || !AddObject(BG_AV_OBJECT_DOOR_H, BG_AV_OBJECTID_GATE_H, BG_AV_DoorPositons[1][0], BG_AV_DoorPositons[1][1], BG_AV_DoorPositons[1][2], BG_AV_DoorPositons[1][3], 0, 0, sin(BG_AV_DoorPositons[1][3]/2), cos(BG_AV_DoorPositons[1][3]/2), RESPAWN_IMMEDIATELY))

                              BG_AV_ObjectPos[i],
                              0, 0, std::sin(BG_AV_ObjectPos[i].GetOrientation()/2), std::cos(BG_AV_ObjectPos[i].GetOrientation()/2), RESPAWN_ONE_DAY)
                || !AddObject(i+33, BG_AV_OBJECTID_BANNER_H_B,
                              BG_AV_ObjectPos[i],
                              0, 0, std::sin(BG_AV_ObjectPos[i].GetOrientation()/2), std::cos(BG_AV_ObjectPos[i].GetOrientation()/2), RESPAWN_ONE_DAY)
                || !AddObject(i+22, BG_AV_OBJECTID_BANNER_CONT_H_B,
                              BG_AV_ObjectPos[i],
                              0, 0, std::sin(BG_AV_ObjectPos[i].GetOrientation()/2), std::cos(BG_AV_ObjectPos[i].GetOrientation()/2), RESPAWN_ONE_DAY)
                || !AddObject(BG_AV_OBJECT_AURA_A_FIRSTAID_STATION+i*3, BG_AV_OBJECTID_AURA_A,
                              BG_AV_ObjectPos[i],
                              0, 0, std::sin(BG_AV_ObjectPos[i].GetOrientation()/2), std::cos(BG_AV_ObjectPos[i].GetOrientation()/2), RESPAWN_ONE_DAY)
                || !AddObject(BG_AV_OBJECT_AURA_H_FIRSTAID_STATION+i*3, BG_AV_OBJECTID_AURA_H,
                              BG_AV_ObjectPos[i],
                              0, 0, std::sin(BG_AV_ObjectPos[i].GetOrientation()/2), std::cos(BG_AV_ObjectPos[i].GetOrientation()/2), RESPAWN_ONE_DAY))
                if (!AddObject(i, BG_AV_OBJECTID_BANNER_A,
                               BG_AV_ObjectPos[i],
                               0, 0, std::sin(BG_AV_ObjectPos[i].GetOrientation()/2), std::cos(BG_AV_ObjectPos[i].GetOrientation()/2), RESPAWN_ONE_DAY)
                    || !AddObject(i+22, BG_AV_OBJECTID_BANNER_CONT_H,
                                  BG_AV_ObjectPos[i],
                                  0, 0, std::sin(BG_AV_ObjectPos[i].GetOrientation()/2), std::cos(BG_AV_ObjectPos[i].GetOrientation()/2), RESPAWN_ONE_DAY)
                    || !AddObject(BG_AV_OBJECT_TAURA_A_DUNBALDAR_SOUTH+(2*(i-BG_AV_NODES_DUNBALDAR_SOUTH)), BG_AV_OBJECTID_AURA_A,
                                  BG_AV_ObjectPos[i+8],
                                  0, 0, std::sin(BG_AV_ObjectPos[i+8].GetOrientation()/2), std::cos(BG_AV_ObjectPos[i+8].GetOrientation()/2), RESPAWN_ONE_DAY)
                    || !AddObject(BG_AV_OBJECT_TAURA_H_DUNBALDAR_SOUTH+(2*(i-BG_AV_NODES_DUNBALDAR_SOUTH)), BG_AV_OBJECTID_AURA_N,
                                  BG_AV_ObjectPos[i+8],
                                  0, 0, std::sin(BG_AV_ObjectPos[i+8].GetOrientation()/2), std::cos(BG_AV_ObjectPos[i+8].GetOrientation()/2), RESPAWN_ONE_DAY)
                    || !AddObject(BG_AV_OBJECT_TFLAG_A_DUNBALDAR_SOUTH+(2*(i-BG_AV_NODES_DUNBALDAR_SOUTH)), BG_AV_OBJECTID_TOWER_BANNER_A,
                                  BG_AV_ObjectPos[i+8],
                                  0, 0, std::sin(BG_AV_ObjectPos[i+8].GetOrientation()/2), std::cos(BG_AV_ObjectPos[i+8].GetOrientation()/2), RESPAWN_ONE_DAY)
                    || !AddObject(BG_AV_OBJECT_TFLAG_H_DUNBALDAR_SOUTH+(2*(i-BG_AV_NODES_DUNBALDAR_SOUTH)), BG_AV_OBJECTID_TOWER_BANNER_PH,
                                  BG_AV_ObjectPos[i+8],
                                  0, 0, std::sin(BG_AV_ObjectPos[i+8].GetOrientation()/2), std::cos(BG_AV_ObjectPos[i+8].GetOrientation()/2), RESPAWN_ONE_DAY))
                    TC_LOG_ERROR("bg.battleground", "BatteGroundAV: Failed to spawn some object Battleground not created!3");
                if (!AddObject(i+7, BG_AV_OBJECTID_BANNER_CONT_A, BG_AV_ObjectPos[i][0], BG_AV_ObjectPos[i][1], BG_AV_ObjectPos[i][2], BG_AV_ObjectPos[i][3], 0, 0, sin(BG_AV_ObjectPos[i][3]/2), cos(BG_AV_ObjectPos[i][3]/2), RESPAWN_ONE_DAY)
                    || !AddObject(i+29, BG_AV_OBJECTID_BANNER_H, BG_AV_ObjectPos[i][0], BG_AV_ObjectPos[i][1], BG_AV_ObjectPos[i][2], BG_AV_ObjectPos[i][3], 0, 0, sin(BG_AV_ObjectPos[i][3]/2), cos(BG_AV_ObjectPos[i][3]/2), RESPAWN_ONE_DAY)
                    || !AddObject(BG_AV_OBJECT_TAURA_A_DUNBALDAR_SOUTH+(2*(i-BG_AV_NODES_DUNBALDAR_SOUTH)), BG_AV_OBJECTID_AURA_N, BG_AV_ObjectPos[i+8][0], BG_AV_ObjectPos[i+8][1], BG_AV_ObjectPos[i+8][2], BG_AV_ObjectPos[i+8][3], 0, 0, sin(BG_AV_ObjectPos[i+8][3]/2), cos(BG_AV_ObjectPos[i+8][3]/2), RESPAWN_ONE_DAY)
                    || !AddObject(BG_AV_OBJECT_TAURA_H_DUNBALDAR_SOUTH+(2*(i-BG_AV_NODES_DUNBALDAR_SOUTH)), BG_AV_OBJECTID_AURA_H, BG_AV_ObjectPos[i+8][0], BG_AV_ObjectPos[i+8][1], BG_AV_ObjectPos[i+8][2], BG_AV_ObjectPos[i+8][3], 0, 0, sin(BG_AV_ObjectPos[i+8][3]/2), cos(BG_AV_ObjectPos[i+8][3]/2), RESPAWN_ONE_DAY)
                    || !AddObject(BG_AV_OBJECT_TFLAG_A_DUNBALDAR_SOUTH+(2*(i-BG_AV_NODES_DUNBALDAR_SOUTH)), BG_AV_OBJECTID_TOWER_BANNER_PA, BG_AV_ObjectPos[i+8][0], BG_AV_ObjectPos[i+8][1], BG_AV_ObjectPos[i+8][2], BG_AV_ObjectPos[i+8][3], 0, 0, sin(BG_AV_ObjectPos[i+8][3]/2), cos(BG_AV_ObjectPos[i+8][3]/2), RESPAWN_ONE_DAY)
                    || !AddObject(BG_AV_OBJECT_TFLAG_H_DUNBALDAR_SOUTH+(2*(i-BG_AV_NODES_DUNBALDAR_SOUTH)), BG_AV_OBJECTID_TOWER_BANNER_H, BG_AV_ObjectPos[i+8][0], BG_AV_ObjectPos[i+8][1], BG_AV_ObjectPos[i+8][2], BG_AV_ObjectPos[i+8][3], 0, 0, sin(BG_AV_ObjectPos[i+8][3]/2), cos(BG_AV_ObjectPos[i+8][3]/2), RESPAWN_ONE_DAY))
                    || !AddObject(BG_AV_OBJECT_TAURA_A_DUNBALDAR_SOUTH+(2*(i-BG_AV_NODES_DUNBALDAR_SOUTH)), BG_AV_OBJECTID_AURA_N,
                                  BG_AV_ObjectPos[i+8],
                                  0, 0, std::sin(BG_AV_ObjectPos[i+8].GetOrientation()/2), std::cos(BG_AV_ObjectPos[i+8].GetOrientation()/2), RESPAWN_ONE_DAY)
                    || !AddObject(BG_AV_OBJECT_TAURA_H_DUNBALDAR_SOUTH+(2*(i-BG_AV_NODES_DUNBALDAR_SOUTH)), BG_AV_OBJECTID_AURA_H,
                                  BG_AV_ObjectPos[i+8],
                                  0, 0, std::sin(BG_AV_ObjectPos[i+8].GetOrientation()/2), std::cos(BG_AV_ObjectPos[i+8].GetOrientation()/2), RESPAWN_ONE_DAY)
                    || !AddObject(BG_AV_OBJECT_TFLAG_A_DUNBALDAR_SOUTH+(2*(i-BG_AV_NODES_DUNBALDAR_SOUTH)), BG_AV_OBJECTID_TOWER_BANNER_PA,
                                  BG_AV_ObjectPos[i+8],
                                  0, 0, std::sin(BG_AV_ObjectPos[i+8].GetOrientation()/2), std::cos(BG_AV_ObjectPos[i+8].GetOrientation()/2), RESPAWN_ONE_DAY)
                    || !AddObject(BG_AV_OBJECT_TFLAG_H_DUNBALDAR_SOUTH+(2*(i-BG_AV_NODES_DUNBALDAR_SOUTH)), BG_AV_OBJECTID_TOWER_BANNER_H,
                                  BG_AV_ObjectPos[i+8],
                                  0, 0, std::sin(BG_AV_ObjectPos[i+8].GetOrientation()/2), std::cos(BG_AV_ObjectPos[i+8].GetOrientation()/2), RESPAWN_ONE_DAY))
                if (!AddObject(BG_AV_OBJECT_BURN_DUNBALDAR_SOUTH+((i-BG_AV_NODES_DUNBALDAR_SOUTH)*10)+j,
                               BG_AV_OBJECTID_FIRE,
                               BG_AV_ObjectPos[AV_OPLACE_BURN_DUNBALDAR_SOUTH+((i-BG_AV_NODES_DUNBALDAR_SOUTH)*10)+j],
                               0,
                               0,
                               std::sin(BG_AV_ObjectPos[AV_OPLACE_BURN_DUNBALDAR_SOUTH+((i-BG_AV_NODES_DUNBALDAR_SOUTH)*10)+j].GetOrientation()/2),
                               std::cos(BG_AV_ObjectPos[AV_OPLACE_BURN_DUNBALDAR_SOUTH+((i-BG_AV_NODES_DUNBALDAR_SOUTH)*10)+j].GetOrientation()/2),
                               RESPAWN_ONE_DAY))
                    sLog->outError("BatteGroundAV: Failed to spawn some object Battleground not created!5.%i", i);
                               BG_AV_OBJECTID_SMOKE,
                               BG_AV_ObjectPos[AV_OPLACE_BURN_BUILDING_A+(i*10)+j],
                               0,
                               0,
                               std::sin(BG_AV_ObjectPos[AV_OPLACE_BURN_BUILDING_A+(i*10)+j].GetOrientation()/2),
                               std::cos(BG_AV_ObjectPos[AV_OPLACE_BURN_BUILDING_A+(i*10)+j].GetOrientation()/2),
                               RESPAWN_ONE_DAY))
                if (!AddObject(BG_AV_OBJECT_BURN_BUILDING_ALLIANCE+(i*10)+j, BG_AV_OBJECTID_FIRE, BG_AV_ObjectPos[AV_OPLACE_BURN_BUILDING_A+(i*10)+j][0], BG_AV_ObjectPos[AV_OPLACE_BURN_BUILDING_A+(i*10)+j][1], BG_AV_ObjectPos[AV_OPLACE_BURN_BUILDING_A+(i*10)+j][2], BG_AV_ObjectPos[AV_OPLACE_BURN_BUILDING_A+(i*10)+j][3], 0, 0, sin(BG_AV_ObjectPos[AV_OPLACE_BURN_BUILDING_A+(i*10)+j][3]/2), cos(BG_AV_ObjectPos[AV_OPLACE_BURN_BUILDING_A+(i*10)+j][3]/2), RESPAWN_ONE_DAY))
                               BG_AV_OBJECTID_FIRE,
                               BG_AV_ObjectPos[AV_OPLACE_BURN_BUILDING_A+(i*10)+j],
                               0,
                               0,
                               std::sin(BG_AV_ObjectPos[AV_OPLACE_BURN_BUILDING_A+(i*10)+j].GetOrientation()/2),
                               std::cos(BG_AV_ObjectPos[AV_OPLACE_BURN_BUILDING_A+(i*10)+j].GetOrientation()/2),
                               RESPAWN_ONE_DAY))
        if (!AddObject(BG_AV_OBJECT_MINE_SUPPLY_N_MIN+i,
                       BG_AV_OBJECTID_MINE_N,
                       BG_AV_ObjectPos[AV_OPLACE_MINE_SUPPLY_N_MIN+i],
                       0,
                       0,
                       std::sin(BG_AV_ObjectPos[AV_OPLACE_MINE_SUPPLY_N_MIN+i].GetOrientation()/2),
                       std::cos(BG_AV_ObjectPos[AV_OPLACE_MINE_SUPPLY_N_MIN+i].GetOrientation()/2),
                       RESPAWN_ONE_DAY))
    for (uint16 i= 0 ; i <= (BG_AV_OBJECT_MINE_SUPPLY_S_MAX-BG_AV_OBJECT_MINE_SUPPLY_S_MIN); i++)
                       BG_AV_OBJECTID_MINE_S,
                       BG_AV_ObjectPos[AV_OPLACE_MINE_SUPPLY_S_MIN+i],
                       0,
                       0,
                       std::sin(BG_AV_ObjectPos[AV_OPLACE_MINE_SUPPLY_S_MIN+i].GetOrientation()/2),
                       std::cos(BG_AV_ObjectPos[AV_OPLACE_MINE_SUPPLY_S_MIN+i].GetOrientation()/2),
                       RESPAWN_ONE_DAY))
            TC_LOG_ERROR("bg.battleground", "BatteGroundAV: Failed to spawn some mine supplies Battleground not created!7.6.%i", i);

const char* BattlegroundAV::GetNodeName(AVNodeId node)
                   BG_AV_OBJECTID_BANNER_SNOWFALL_N,
                   BG_AV_ObjectPos[BG_AV_NODES_SNOWFALL_GRAVE],
                   0,
                   0,
                   std::sin(BG_AV_ObjectPos[BG_AV_NODES_SNOWFALL_GRAVE].GetOrientation()/2),
                   std::cos(BG_AV_ObjectPos[BG_AV_NODES_SNOWFALL_GRAVE].GetOrientation()/2),
                   RESPAWN_ONE_DAY))
        sLog->outError("BatteGroundAV: Failed to spawn some object Battleground not created!8");
                          BG_AV_ObjectPos[AV_OPLACE_SNOW_1+i],
                          0, 0, std::sin(BG_AV_ObjectPos[AV_OPLACE_SNOW_1+i].GetOrientation()/2), std::cos(BG_AV_ObjectPos[AV_OPLACE_SNOW_1+i].GetOrientation()/2), RESPAWN_ONE_DAY)
            || !AddObject(BG_AV_OBJECT_SNOW_EYECANDY_H+i, BG_AV_OBJECTID_SNOWFALL_CANDY_H,
                          BG_AV_ObjectPos[AV_OPLACE_SNOW_1+i],
                          0, 0, std::sin(BG_AV_ObjectPos[AV_OPLACE_SNOW_1+i].GetOrientation()/2), std::cos(BG_AV_ObjectPos[AV_OPLACE_SNOW_1+i].GetOrientation()/2), RESPAWN_ONE_DAY)
            || !AddObject(BG_AV_OBJECT_SNOW_EYECANDY_PH+i, BG_AV_OBJECTID_SNOWFALL_CANDY_PH,
                          BG_AV_ObjectPos[AV_OPLACE_SNOW_1+i],
                          0, 0, std::sin(BG_AV_ObjectPos[AV_OPLACE_SNOW_1+i].GetOrientation()/2), std::cos(BG_AV_ObjectPos[AV_OPLACE_SNOW_1+i].GetOrientation()/2), RESPAWN_ONE_DAY))
            TC_LOG_ERROR("bg.battleground", "BatteGroundAV: Failed to spawn some object Battleground not created!9.%i", i);
    for (i = BG_AV_OBJECT_FLAG_A_FIRSTAID_STATION; i <= BG_AV_OBJECT_FLAG_A_STONEHEART_GRAVE ; i++){
    for (i = BG_AV_OBJECT_FLAG_A_FIRSTAID_STATION; i <= BG_AV_OBJECT_FLAG_A_STONEHEART_GRAVE; i++)
    {

    for (i = BG_AV_OBJECT_FLAG_A_DUNBALDAR_SOUTH; i <= BG_AV_OBJECT_FLAG_A_STONEHEART_BUNKER ; i++)
    for (i = BG_AV_OBJECT_FLAG_H_ICEBLOOD_GRAVE; i <= BG_AV_OBJECT_FLAG_H_FROSTWOLF_WTOWER ; i++){
    for (i = BG_AV_OBJECT_FLAG_H_ICEBLOOD_GRAVE; i <= BG_AV_OBJECT_FLAG_H_FROSTWOLF_WTOWER; i++)
    {




    sLog->outDebug(LOG_FILTER_BATTLEGROUND, "BG_AV start poputlating nodes");
    for (BG_AV_Nodes i= BG_AV_NODES_FIRSTAID_STATION; i < BG_AV_NODES_MAX; ++i)
    sLog->outDebug(LOG_FILTER_BATTLEGROUND, "BG_AV: start spawning static creatures");
    for (i=0; i < AV_STATICCPLACE_MAX; i++)
        AddAVCreature(0, i+AV_CPLACE_MAX);
    sLog->outDebug(LOG_FILTER_BATTLEGROUND, "BG_AV: start spawning spiritguides creatures");
    AddSpiritGuide(7, BG_AV_CreaturePos[7][0], BG_AV_CreaturePos[7][1], BG_AV_CreaturePos[7][2], BG_AV_CreaturePos[7][3], ALLIANCE);
    AddSpiritGuide(8, BG_AV_CreaturePos[8][0], BG_AV_CreaturePos[8][1], BG_AV_CreaturePos[8][2], BG_AV_CreaturePos[8][3], HORDE);
    TC_LOG_DEBUG("bg.battleground", "BG_AV: start spawning marshal creatures");
    for (i = AV_NPC_A_MARSHAL_SOUTH; i <= AV_NPC_H_MARSHAL_WTOWER; i++)
        AddAVCreature(i, AV_CPLACE_A_MARSHAL_SOUTH + (i - AV_NPC_A_MARSHAL_SOUTH));
void BattlegroundAV::AssaultNode(AVNodeId node, BattlegroundTeamId team)
{
    if (m_Nodes[node].TotalOwner == team)
    {
        TC_LOG_FATAL("bg.battleground", "Assaulting team is TotalOwner of node");
        ASSERT(false);
    }
    if (m_Nodes[node].Owner == team)
    {
        TC_LOG_FATAL("bg.battleground", "Assaulting team is owner of node");
        ASSERT(false);
    }
    if (m_Nodes[node].State == POINT_DESTROYED)
    {
        TC_LOG_FATAL("bg.battleground", "Destroyed node is being assaulted");
        ASSERT(false);
    }
    if (m_Nodes[node].State == POINT_ASSAULTED && m_Nodes[node].TotalOwner) //only assault an assaulted node if no totalowner exists
    {
        TC_LOG_FATAL("bg.battleground", "Assault on an not assaulted node with total owner");
        ASSERT(false);
    }
    //the timer gets another time, if the previous owner was 0 == Neutral
    m_Nodes[node].Timer      = (m_Nodes[node].PrevOwner)? BG_AV_CAPTIME : BG_AV_SNOWFALL_FIRSTCAP;
    m_Nodes[node].PrevOwner  = m_Nodes[node].Owner;
    m_Nodes[node].Owner      = team;
    m_Nodes[node].PrevState  = m_Nodes[node].State;
    m_Nodes[node].State      = POINT_ASSAULTED;
}

void BattlegroundAV::DestroyNode(AVNodeId node)
{
    ASSERT(m_Nodes[node].State == POINT_ASSAULTED);

    m_Nodes[node].TotalOwner = m_Nodes[node].Owner;
    m_Nodes[node].PrevOwner  = m_Nodes[node].Owner;
    m_Nodes[node].PrevState  = m_Nodes[node].State;
    m_Nodes[node].State      = (m_Nodes[node].Tower)? POINT_DESTROYED : POINT_CONTROLED;
    m_Nodes[node].Timer      = 0;
}

void BattlegroundAV::InitNode(AVNodeId node, BattlegroundTeamId team, bool tower)
{
    m_Nodes[node].TotalOwner = team;
    m_Nodes[node].Owner      = team;
    m_Nodes[node].PrevOwner  = 0;
    m_Nodes[node].State      = POINT_CONTROLED;
    m_Nodes[node].PrevState  = m_Nodes[node].State;
    m_Nodes[node].State      = POINT_CONTROLED;
    m_Nodes[node].Timer      = 0;
    m_Nodes[node].Tower      = tower;
}

void BattlegroundAV::DefendNode(AVNodeId node, BattlegroundTeamId team)
{
    ASSERT(m_Nodes[node].TotalOwner == team);
    ASSERT(m_Nodes[node].Owner != team);
    ASSERT(m_Nodes[node].State != POINT_CONTROLED && m_Nodes[node].State != POINT_DESTROYED);
    m_Nodes[node].PrevOwner  = m_Nodes[node].Owner;
    m_Nodes[node].Owner      = team;
    m_Nodes[node].PrevState  = m_Nodes[node].State;
    m_Nodes[node].State      = POINT_CONTROLED;
    m_Nodes[node].Timer      = 0;
}

        m_Team_Scores[i]=BG_AV_SCORE_INITIAL_POINTS;
        m_CaptainBuffTimer[i] = 120000 + urand(0, 4)* 60; //as far as i could see, the buff is randomly so i make 2minutes (thats the duration of the buff itself) + 0-4minutes @todo get the right times

        if (!BgCreatures[i].IsEmpty())
}

bool BattlegroundAV::CheckAchievementCriteriaMeet(uint32 criteriaId, Player const* source, Unit const* target, uint32 miscValue)
{
    uint32 team = source->GetTeam();
    switch (criteriaId)
    {
        case BG_CRITERIA_CHECK_EVERYTHING_COUNTS:
            for (uint8 mine = 0; mine < 2; mine++)
                if (m_Mine_Owner[mine] != team)
                    return false;

            return true;
        case BG_CRITERIA_CHECK_AV_PERFECTION:
        {
            if (team == ALLIANCE)
            {
                for (BG_AV_Nodes i = BG_AV_NODES_DUNBALDAR_SOUTH; i <= BG_AV_NODES_STONEHEART_BUNKER; ++i) // alliance towers controlled
                {
                    if (m_Nodes[i].State == POINT_CONTROLED)
                    {
                        if (m_Nodes[i].Owner != ALLIANCE)
                            return false;
                    }
                    else
                        return false;
                }
                for (BG_AV_Nodes i = BG_AV_NODES_ICEBLOOD_TOWER; i <= BG_AV_NODES_FROSTWOLF_WTOWER; ++i) // horde towers destroyed
                    if (m_Nodes[i].State != POINT_DESTROYED)
                        return false;

                if (!m_CaptainAlive[0])
                    return false;

                return true;
            }
            else if (team == HORDE)
            {
                for (BG_AV_Nodes i = BG_AV_NODES_ICEBLOOD_TOWER; i <= BG_AV_NODES_FROSTWOLF_WTOWER; ++i) // horde towers controlled
                {
                    if (m_Nodes[i].State == POINT_CONTROLED)
                    {
                        if (m_Nodes[i].Owner != HORDE)
                            return false;
                    }
                    else
                        return false;
}
                for (BG_AV_Nodes i = BG_AV_NODES_DUNBALDAR_SOUTH; i <= BG_AV_NODES_STONEHEART_BUNKER; ++i) // alliance towers destroyed
                    if (m_Nodes[i].State != POINT_DESTROYED)
                        return false;

                if (!m_CaptainAlive[1])
                    return false;

                return true;
            }
        }
    }

    return Battleground::CheckAchievementCriteriaMeet(criteriaId, source, target, miscValue);
}

uint32 BattlegroundAV::GetPrematureWinner()
{
    uint32 allianceScore = m_Team_Scores[GetTeamIndexByTeamId(ALLIANCE)];
    uint32 hordeScore = m_Team_Scores[GetTeamIndexByTeamId(HORDE)];

    if (allianceScore > hordeScore)
        return ALLIANCE;
    else if (hordeScore > allianceScore)
        return HORDE;

    return Battleground::GetPrematureWinner();
}