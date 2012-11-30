/*
 * Copyright (C) 2008 - 2010 Trinity <http://www.trinitycore.org/>
 *
 * Copyright (C) 2006 - 2010 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/* ScriptData
SDName: instance_halls_of_reflection
SD%Complete: 70%
SDComment:
SDErrors:
SDCategory: instance script
SDAuthor: /dev/rsa, modified by MaxXx2021 aka Mioka
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "InstanceScript.h"
#include "halls_of_reflection.h"
#include "World.h"
#include "Player.h"

#define MAX_ENCOUNTER 3

/* Halls of Reflection encounters:
0- Falric
1- Marwyn
2- The Lich King
*/

enum eEnum
{
    ENCOUNTER_WAVE_MERCENARY                      = 6,
    ENCOUNTER_WAVE_FOOTMAN                        = 10,
    ENCOUNTER_WAVE_RIFLEMAN                       = 6,
    ENCOUNTER_WAVE_PRIEST                         = 6,
    ENCOUNTER_WAVE_MAGE                           = 6,
};

enum Events
{
    EVENT_NONE,
    EVENT_NEXT_WAVE,
    EVENT_START_LICH_KING,
};

static Position PriestSpawnPos[ENCOUNTER_WAVE_PRIEST] =
{
    {5277.74f, 2016.88f, 707.778f, 5.96903f},
    {5295.88f, 2040.34f, 707.778f, 5.07891f},
    {5320.37f, 1980.13f, 707.778f, 2.00713f},
    {5280.51f, 1997.84f, 707.778f, 0.296706f},
    {5302.45f, 2042.22f, 707.778f, 4.90438f},
    {5306.57f, 1977.47f, 707.778f, 1.50098f},
};

static Position MageSpawnPos[ENCOUNTER_WAVE_MAGE] =
{
    {5312.75f, 2037.12f, 707.778f, 4.59022f},
    {5309.58f, 2042.67f, 707.778f, 4.69494f},
    {5275.08f, 2008.72f, 707.778f, 6.21337f},
    {5279.65f, 2004.66f, 707.778f, 0.069813f},
    {5275.48f, 2001.14f, 707.778f, 0.174533f},
    {5316.7f, 2041.55f, 707.778f, 4.50295f},
};

static Position MercenarySpawnPos[ENCOUNTER_WAVE_MERCENARY] =
{
    {5302.25f, 1972.41f, 707.778f, 1.37881f},
    {5311.03f, 1972.23f, 707.778f, 1.64061f},
    {5277.36f, 1993.23f, 707.778f, 0.401426f},
    {5318.7f, 2036.11f, 707.778f, 4.2237f},
    {5335.72f, 1996.86f, 707.778f, 2.74017f},
    {5299.43f, 1979.01f, 707.778f, 1.23918f},
};

static Position FootmenSpawnPos[ENCOUNTER_WAVE_FOOTMAN] =
{
    {5306.06f, 2037, 707.778f, 4.81711f},
    {5344.15f, 2007.17f, 707.778f, 3.15905f},
    {5337.83f, 2010.06f, 707.778f, 3.22886f},
    {5343.29f, 1999.38f, 707.778f, 2.9147f},
    {5340.84f, 1992.46f, 707.778f, 2.75762f},
    {5325.07f, 1977.6f, 707.778f, 2.07694f},
    {5336.6f, 2017.28f, 707.778f, 3.47321f},
    {5313.82f, 1978.15f, 707.778f, 1.74533f},
    {5280.63f, 2012.16f, 707.778f, 6.05629f},
    {5322.96f, 2040.29f, 707.778f, 4.34587f},
};

static Position RiflemanSpawnPos[ENCOUNTER_WAVE_RIFLEMAN] =
{
    {5343.47f, 2015.95f, 707.778f, 3.49066f},
    {5337.86f, 2003.4f, 707.778f, 2.98451f},
    {5319.16f, 1974, 707.778f, 1.91986f},
    {5299.25f, 2036, 707.778f, 5.02655f},
    {5295.64f, 1973.76f, 707.778f, 1.18682f},
    {5282.9f, 2019.6f, 707.778f, 5.88176f},
};

class instance_halls_of_reflection : public InstanceMapScript
{
public:
    instance_halls_of_reflection() : InstanceMapScript("instance_halls_of_reflection", 668) { }

    struct instance_halls_of_reflection_InstanceMapScript : public InstanceScript
    {
        instance_halls_of_reflection_InstanceMapScript(Map* pMap) : InstanceScript(pMap) 
        {
            Difficulty = pMap->GetDifficulty();
            Initialize();
        }

        uint32 m_auiEncounter[MAX_ENCOUNTERS+1];
        uint32 m_auiLider;
        std::string strSaveData;

        uint8 Difficulty;
        uint8 m_uiSummons;

        uint64 m_uiFalricGUID;
        uint64 m_uiMarwynGUID;  
        uint64 m_uiLichKingGUID;
        uint64 m_uiLiderGUID;

        uint64 m_uiMainGateGUID;
        uint64 m_uiExitGateGUID;
        uint64 m_uiDoor2GUID;
        uint64 m_uiDoor3GUID;

        uint64 m_uiFrostGeneralGUID;
        uint64 m_uiCaptainsChestHordeGUID;
        uint64 m_uiCaptainsChestAllianceGUID;
        uint64 m_uiFrostmourneGUID;
        uint64 m_uiFrostmourneAltarGUID;
        uint64 m_uiPortalGUID;
        uint64 m_uiIceWall1GUID;
        uint64 m_uiIceWall2GUID;
        uint64 m_uiIceWall3GUID;
        uint64 m_uiIceWall4GUID;
        uint64 m_uiGoCaveGUID;
        uint32 m_uiTeamInInstance;

        void Initialize()
        {
            for (uint8 i = 0; i < MAX_ENCOUNTERS; ++i)
                m_auiEncounter[i] = NOT_STARTED;
            m_uiMainGateGUID = 0;
            m_uiFrostmourneGUID = 0;
            m_uiFalricGUID = 0;
            m_uiLiderGUID = 0;
            m_uiLichKingGUID = 0;
            m_uiExitGateGUID = 0;
            m_uiSummons = 0;
            m_uiIceWall1GUID = 0;
            m_uiIceWall2GUID = 0;
            m_uiIceWall3GUID = 0;
            m_uiIceWall4GUID = 0;
            m_uiGoCaveGUID = 0;
            m_uiTeamInInstance = 0;
        }

        void OpenDoor(uint64 guid)
        {
            if(!guid) return;
            GameObject* go = instance->GetGameObject(guid);
            if(go) go->SetGoState(GO_STATE_ACTIVE);
        }

        void CloseDoor(uint64 guid)
        {
            if(!guid) return;
            GameObject* go = instance->GetGameObject(guid);
            if(go) go->SetGoState(GO_STATE_READY);
        }

        void OnCreatureCreate(Creature* creature)
        {
            Map::PlayerList const &players = instance->GetPlayers();
            if (!players.isEmpty())
                if (Player* pPlayer = players.begin()->getSource())
                    m_uiTeamInInstance = pPlayer->GetTeam();

            switch(creature->GetEntry())
            {
                case NPC_FALRIC: 
                       m_uiFalricGUID = creature->GetGUID(); 
                       break;
                case NPC_MARWYN: 
                       m_uiMarwynGUID = creature->GetGUID();  
                       break;
                case BOSS_LICH_KING: 
                       m_uiLichKingGUID = creature->GetGUID();
                       break;
                case NPC_FROST_GENERAL:
                       m_uiFrostGeneralGUID = creature->GetGUID();
                       break;
            }
        }

        void OnPlayerEnter(Player *pPlayer)
        {

        enum PhaseControl
        {
            HORDE_CONTROL_PHASE_SHIFT_1    = 55773,
            HORDE_CONTROL_PHASE_SHIFT_2    = 60028,
            ALLIANCE_CONTROL_PHASE_SHIFT_1 = 55774,
            ALLIANCE_CONTROL_PHASE_SHIFT_2 = 60027,
        };
        
         if (!sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_GROUP)) return;

            switch (pPlayer->GetTeam())
            {
                case ALLIANCE:
                      if (pPlayer && pPlayer->IsInWorld() && pPlayer->HasAura(HORDE_CONTROL_PHASE_SHIFT_1))
                          pPlayer->RemoveAurasDueToSpell(HORDE_CONTROL_PHASE_SHIFT_1);
                      pPlayer->CastSpell(pPlayer, HORDE_CONTROL_PHASE_SHIFT_2, false);
                      break;
                case HORDE:
                      if (pPlayer && pPlayer->IsInWorld() && pPlayer->HasAura(ALLIANCE_CONTROL_PHASE_SHIFT_1)) 
                          pPlayer->RemoveAurasDueToSpell(ALLIANCE_CONTROL_PHASE_SHIFT_1);
                      pPlayer->CastSpell(pPlayer, ALLIANCE_CONTROL_PHASE_SHIFT_2, false);
                      break;
            };

        };

        void OnGameObjectCreate(GameObject* go)
        {
            switch(go->GetEntry())
            {
                case GO_IMPENETRABLE_DOOR: m_uiMainGateGUID = go->GetGUID(); break;
                case GO_FROSTMOURNE: m_uiFrostmourneGUID = go->GetGUID(); break;
                case GO_ICECROWN_DOOR:     m_uiExitGateGUID = go->GetGUID(); break;
                case GO_ICECROWN_DOOR_2:   m_uiDoor2GUID = go->GetGUID(); break;
                case GO_ICECROWN_DOOR_3:   m_uiDoor3GUID = go->GetGUID(); break;
                case GO_PORTAL:            m_uiPortalGUID = go->GetGUID(); break;
                case GO_CAPTAIN_CHEST_1:
                                      if (Difficulty == RAID_DIFFICULTY_10MAN_NORMAL)
                                      m_uiCaptainsChestHordeGUID = go->GetGUID(); 
                                      break;
                case GO_CAPTAIN_CHEST_3:
                                      if (Difficulty == RAID_DIFFICULTY_25MAN_NORMAL)
                                      m_uiCaptainsChestHordeGUID = go->GetGUID(); 
                                      break;
                case GO_CAPTAIN_CHEST_2:
                                      if (Difficulty == RAID_DIFFICULTY_10MAN_NORMAL)
                                      m_uiCaptainsChestAllianceGUID = go->GetGUID(); 
                                      break;
                case GO_CAPTAIN_CHEST_4:
                                      if (Difficulty == RAID_DIFFICULTY_25MAN_NORMAL)
                                      m_uiCaptainsChestAllianceGUID = go->GetGUID(); 
                                      break;
                case GO_ICE_WALL_1:
                    m_uiIceWall1GUID = go->GetGUID();
                    go->SetGoState(GO_STATE_READY);
                    break;
                case GO_ICE_WALL_2:
                    m_uiIceWall2GUID = go->GetGUID();
                    go->SetGoState(GO_STATE_READY);
                    break;
                case GO_ICE_WALL_3:
                    m_uiIceWall3GUID = go->GetGUID();
                    go->SetGoState(GO_STATE_READY);
                    break;
                case GO_ICE_WALL_4:
                    m_uiIceWall4GUID = go->GetGUID();
                    go->SetGoState(GO_STATE_READY);
                    break;
                case GO_CAVE:
                    m_uiGoCaveGUID = go->GetGUID();
                    go->SetGoState(GO_STATE_ACTIVE);
                    break;
            }
        }

        void SetData(uint32 uiType, uint32 uiData)
        {
            switch(uiType)
            {
                case TYPE_PHASE:                m_auiEncounter[uiType] = uiData; break;
                case TYPE_EVENT:                m_auiEncounter[uiType] = uiData;
                                                uiData = NOT_STARTED;
                    break;
                case TYPE_FALRIC:               m_auiEncounter[uiType] = uiData;
                    if(uiData == SPECIAL)
                                                    CloseDoor(m_uiExitGateGUID);
                    break;
                case TYPE_MARWYN:               m_auiEncounter[uiType] = uiData;
                    if(uiData == DONE)
                    {
                                                   OpenDoor(m_uiMainGateGUID);
                                                   OpenDoor(m_uiExitGateGUID);
                    }
                    break;
                case TYPE_FROST_GENERAL:        m_auiEncounter[uiType] = uiData; 
                                                if(uiData == DONE)
                                                   OpenDoor(m_uiDoor2GUID);
                    break;
                case TYPE_LICH_KING:            m_auiEncounter[uiType] = uiData;
                                                if(uiData == IN_PROGRESS)
                                                   OpenDoor(m_uiDoor3GUID);
                                                if(uiData == DONE)
                                                {
                                                if (m_auiLider == 1)
                                                {
                                                if (GameObject* pChest = instance->GetGameObject(m_uiCaptainsChestAllianceGUID))
                                                    if (pChest && !pChest->isSpawned()) {
                                                        pChest->SetRespawnTime(DAY);
                                                    };
                                                } else
                                                if (GameObject* pChest = instance->GetGameObject(m_uiCaptainsChestHordeGUID))
                                                    if (pChest && !pChest->isSpawned()) {
                                                        pChest->SetRespawnTime(DAY);
                                                    };
                                                if (GameObject* pPortal = instance->GetGameObject(m_uiPortalGUID))
                                                    if (pPortal && !pPortal->isSpawned()) {
                                                        pPortal->SetRespawnTime(DAY);
                                                    };
                                                }
                    break;
                case TYPE_ICE_WALL_01:          m_auiEncounter[uiType] = uiData; break;
                case TYPE_ICE_WALL_02:          m_auiEncounter[uiType] = uiData; break;
                case TYPE_ICE_WALL_03:          m_auiEncounter[uiType] = uiData; break;
                case TYPE_ICE_WALL_04:          m_auiEncounter[uiType] = uiData; break;
                case TYPE_HALLS:                m_auiEncounter[uiType] = uiData; break;
                case DATA_LIDER:                m_auiLider = uiData;
                                                uiData = NOT_STARTED;
                    break;
                case DATA_SUMMONS:              if (uiData == 3) m_uiSummons = 0;
                                                else if (uiData == 1) ++m_uiSummons;
                                                else if (uiData == 0) --m_uiSummons;
                                                uiData = NOT_STARTED;
                    break;
            }

            if (uiData == DONE)
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;

                for(uint8 i = 0; i < MAX_ENCOUNTERS; ++i)
                    saveStream << m_auiEncounter[i] << " ";

                strSaveData = saveStream.str();

                SaveToDB();
                OUT_SAVE_INST_DATA_COMPLETE;
            }
        }

        const char* Save()
        {
            return strSaveData.c_str();
        }

        uint32 GetData(uint32 uiType) const
        {
            switch(uiType)
            {
                case TYPE_PHASE:                return m_auiEncounter[uiType];
                case TYPE_EVENT:                return m_auiEncounter[uiType];
                case TYPE_FALRIC:               return m_auiEncounter[uiType];
                case TYPE_MARWYN:               return m_auiEncounter[uiType];
                case TYPE_LICH_KING:            return m_auiEncounter[uiType];
                case TYPE_FROST_GENERAL:        return m_auiEncounter[uiType];
                case TYPE_ICE_WALL_01:          return m_auiEncounter[uiType];
                case TYPE_ICE_WALL_02:          return m_auiEncounter[uiType];
                case TYPE_ICE_WALL_03:          return m_auiEncounter[uiType];
                case TYPE_ICE_WALL_04:          return m_auiEncounter[uiType];
                case TYPE_HALLS:                return m_auiEncounter[uiType];
                case DATA_LIDER:                return m_auiLider;
                case DATA_SUMMONS:              return m_uiSummons;
                case DATA_TEAM_IN_INSTANCE:     return m_uiTeamInInstance;
                default:                        return 0;
            }
            return 0;
        }

        void SetData64(uint32 uiData, uint64 uiGuid)
        {
            switch(uiData)
            {
                case DATA_ESCAPE_LIDER:
                       m_uiLiderGUID = uiGuid;
                       break;
            }
        }

        uint64 GetData64(uint32 uiData) const
        {
            switch(uiData)
            {
                case GO_IMPENETRABLE_DOOR: return m_uiMainGateGUID;
                case GO_FROSTMOURNE:       return m_uiFrostmourneGUID;
                case NPC_FALRIC:           return m_uiFalricGUID;
                case NPC_MARWYN:           return m_uiMarwynGUID;
                case BOSS_LICH_KING:       return m_uiLichKingGUID;
                case DATA_ESCAPE_LIDER:    return m_uiLiderGUID;
                case NPC_FROST_GENERAL:    return m_uiFrostGeneralGUID;
                case GO_ICECROWN_DOOR:     return m_uiExitGateGUID;
                case GO_ICECROWN_DOOR_2:   return m_uiDoor2GUID;
                case GO_ICECROWN_DOOR_3:   return m_uiDoor3GUID;
                case GO_ICE_WALL_1:        return m_uiIceWall1GUID;
                case GO_ICE_WALL_2:        return m_uiIceWall2GUID;
                case GO_ICE_WALL_3:        return m_uiIceWall3GUID;
                case GO_ICE_WALL_4:        return m_uiIceWall4GUID;
                case GO_CAVE:              return m_uiGoCaveGUID;
            }
            return 0;
        }

        void Load(const char* chrIn)
        {
            if (!chrIn)
            {
                OUT_LOAD_INST_DATA_FAIL;
                return;
            }

            OUT_LOAD_INST_DATA(chrIn);

            std::istringstream loadStream(chrIn);

            for(uint8 i = 0; i < MAX_ENCOUNTERS; ++i)
            {
                loadStream >> m_auiEncounter[i];

                if (m_auiEncounter[i] == IN_PROGRESS)
                    m_auiEncounter[i] = NOT_STARTED;
            }

            OUT_LOAD_INST_DATA_COMPLETE;
        }

    };

    InstanceScript* GetInstanceScript (InstanceMap* pMap) const
    {
        return new instance_halls_of_reflection_InstanceMapScript(pMap);
    }
};


void AddSC_instance_halls_of_reflection()
{
    new instance_halls_of_reflection();
}
