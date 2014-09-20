/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

/* ScriptData
SDName: Instance_Karazhan
SD%Complete: 70
SDComment: Instance Script for Karazhan to help in various encounters. @todo GameObject visibility for Opera event.
SDCategory: Karazhan
EndScriptData */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "karazhan.h"

#define MAX_ENCOUNTER      12

/*
0  - Attumen + Midnight (optional)
1  - Moroes
2  - Maiden of Virtue (optional)
3  - Hyakiss the Lurker /  Rokad the Ravager  / Shadikith the Glider
4  - Opera Event
5  - Curator
6  - Shade of Aran (optional)
7  - Terestian Illhoof (optional)
8  - Netherspite (optional)
9  - Chess Event
10 - Prince Malchezzar
11 - Nightbane
*/

class instance_karazhan : public InstanceMapScript
{
public:
    instance_karazhan() : InstanceMapScript("instance_karazhan", 532) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_karazhan_InstanceMapScript(map);
    }

    struct instance_karazhan_InstanceMapScript : public InstanceScript
    {
        instance_karazhan_InstanceMapScript(Map* map) : InstanceScript(map) { }

        uint32 m_auiEncounter[MAX_ENCOUNTER];
        std::string strSaveData;

        uint32 m_uiOperaEvent;
        uint32 m_uiOzDeathCount;

        ObjectGuid m_uiCurtainGUID;
        ObjectGuid m_uiStageDoorLeftGUID;
        ObjectGuid m_uiStageDoorRightGUID;
        ObjectGuid m_uiKilrekGUID;
        ObjectGuid m_uiTerestianGUID;
        ObjectGuid m_uiMoroesGUID;
        ObjectGuid m_uiLibraryDoor;                                     // Door at Shade of Aran
        ObjectGuid m_uiMassiveDoor;                                     // Door at Netherspite
        ObjectGuid m_uiSideEntranceDoor;                                // Side Entrance
        ObjectGuid m_uiGamesmansDoor;                                   // Door before Chess
        ObjectGuid m_uiGamesmansExitDoor;                               // Door after Chess
        ObjectGuid m_uiNetherspaceDoor;                                // Door at Malchezaar
        ObjectGuid MastersTerraceDoor[2];
        ObjectGuid ImageGUID;
        ObjectGuid DustCoveredChest;

        void Initialize() override
        {
            SetHeaders(DataHeader);
            memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

            // 1 - OZ, 2 - HOOD, 3 - RAJ, this never gets altered.
            m_uiOperaEvent      = urand(1, 3);
            m_uiOzDeathCount    = 0;
        }

        bool IsEncounterInProgress() const override
        {
            for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                if (m_auiEncounter[i] == IN_PROGRESS)
                    return true;

            return false;
        }

        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
                case 17229:   m_uiKilrekGUID = creature->GetGUID();      break;
                case 15688:   m_uiTerestianGUID = creature->GetGUID();   break;
                case 15687:   m_uiMoroesGUID = creature->GetGUID();      break;
            }
        }

        void SetData(uint32 type, uint32 uiData) override
        {
            switch (type)
            {
                case TYPE_ATTUMEN:              m_auiEncounter[0] = uiData; break;
                case TYPE_MOROES:
                    if (m_auiEncounter[1] == DONE)
                        break;
                    m_auiEncounter[1] = uiData;
                    break;
                case TYPE_MAIDEN:               m_auiEncounter[2] = uiData; break;
                case TYPE_OPTIONAL_BOSS:        m_auiEncounter[3] = uiData; break;
                case TYPE_OPERA:
                    m_auiEncounter[4] = uiData;
                    if (uiData == DONE)
                        UpdateEncounterState(ENCOUNTER_CREDIT_KILL_CREATURE, 16812, NULL);
                    break;
                case TYPE_CURATOR:              m_auiEncounter[5] = uiData; break;
                case TYPE_ARAN:                 m_auiEncounter[6] = uiData; break;
                case TYPE_TERESTIAN:            m_auiEncounter[7] = uiData; break;
                case TYPE_NETHERSPITE:          m_auiEncounter[8] = uiData; break;
                case TYPE_CHESS:
                    if (uiData == DONE)
                        DoRespawnGameObject(DustCoveredChest, DAY);
                    m_auiEncounter[9]  = uiData;
                    break;
                case TYPE_MALCHEZZAR:           m_auiEncounter[10] = uiData; break;
                case TYPE_NIGHTBANE:
                    if (m_auiEncounter[11] != DONE)
                        m_auiEncounter[11] = uiData;
                    break;
                case DATA_OPERA_OZ_DEATHCOUNT:
                    if (uiData == SPECIAL)
                        ++m_uiOzDeathCount;
                    else if (uiData == IN_PROGRESS)
                        m_uiOzDeathCount = 0;
                    break;
            }

            if (uiData == DONE)
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;
                saveStream << m_auiEncounter[0] << ' ' << m_auiEncounter[1] << ' ' << m_auiEncounter[2] << ' '
                    << m_auiEncounter[3] << ' ' << m_auiEncounter[4] << ' ' << m_auiEncounter[5] << ' ' << m_auiEncounter[6] << ' '
                    << m_auiEncounter[7] << ' ' << m_auiEncounter[8] << ' ' << m_auiEncounter[9] << ' ' << m_auiEncounter[10] << ' ' << m_auiEncounter[11];

                strSaveData = saveStream.str();

                SaveToDB();
                OUT_SAVE_INST_DATA_COMPLETE;
            }
        }

         void SetGuidData(uint32 identifier, ObjectGuid data) override
         {
             switch (identifier)
             {
             case DATA_IMAGE_OF_MEDIVH: ImageGUID = data;
             }
         }

        void OnGameObjectCreate(GameObject* go) override
        {
            switch (go->GetEntry())
            {
                case 183932:   m_uiCurtainGUID          = go->GetGUID();         break;
                case 184278:
                    m_uiStageDoorLeftGUID = go->GetGUID();
                    if (m_auiEncounter[4] == DONE)
                        go->SetGoState(GO_STATE_ACTIVE);
                    break;
                case 184279:
                    m_uiStageDoorRightGUID = go->GetGUID();
                    if (m_auiEncounter[4] == DONE)
                        go->SetGoState(GO_STATE_ACTIVE);
                    break;
                case 184517:   m_uiLibraryDoor          = go->GetGUID();         break;
                case 185521:   m_uiMassiveDoor          = go->GetGUID();         break;
                case 184276:   m_uiGamesmansDoor        = go->GetGUID();         break;
                case 184277:   m_uiGamesmansExitDoor    = go->GetGUID();         break;
                case 185134:   m_uiNetherspaceDoor      = go->GetGUID();         break;
                case 184274:    MastersTerraceDoor[0] = go->GetGUID();  break;
                case 184280:    MastersTerraceDoor[1] = go->GetGUID();  break;
                case 184275:
                    m_uiSideEntranceDoor = go->GetGUID();
                    if (m_auiEncounter[4] == DONE)
                        go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_LOCKED);
                    else
                        go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_LOCKED);
                    break;
                case 185119: DustCoveredChest = go->GetGUID(); break;
            }

            switch (m_uiOperaEvent)
            {
                /// @todo Set Object visibilities for Opera based on performance
                case EVENT_OZ:
                    break;

                case EVENT_HOOD:
                    break;

                case EVENT_RAJ:
                    break;
            }
        }

        std::string GetSaveData() override
        {
            return strSaveData;
        }

        uint32 GetData(uint32 uiData) const override
        {
            switch (uiData)
            {
                case TYPE_ATTUMEN:              return m_auiEncounter[0];
                case TYPE_MOROES:               return m_auiEncounter[1];
                case TYPE_MAIDEN:               return m_auiEncounter[2];
                case TYPE_OPTIONAL_BOSS:        return m_auiEncounter[3];
                case TYPE_OPERA:                return m_auiEncounter[4];
                case TYPE_CURATOR:              return m_auiEncounter[5];
                case TYPE_ARAN:                 return m_auiEncounter[6];
                case TYPE_TERESTIAN:            return m_auiEncounter[7];
                case TYPE_NETHERSPITE:          return m_auiEncounter[8];
                case TYPE_CHESS:                return m_auiEncounter[9];
                case TYPE_MALCHEZZAR:           return m_auiEncounter[10];
                case TYPE_NIGHTBANE:            return m_auiEncounter[11];
                case DATA_OPERA_PERFORMANCE:    return m_uiOperaEvent;
                case DATA_OPERA_OZ_DEATHCOUNT:  return m_uiOzDeathCount;
            }

            return 0;
        }

        ObjectGuid GetGuidData(uint32 uiData) const override
        {
            switch (uiData)
            {
                case DATA_KILREK:                   return m_uiKilrekGUID;
                case DATA_TERESTIAN:                return m_uiTerestianGUID;
                case DATA_MOROES:                   return m_uiMoroesGUID;
                case DATA_GO_STAGEDOORLEFT:         return m_uiStageDoorLeftGUID;
                case DATA_GO_STAGEDOORRIGHT:        return m_uiStageDoorRightGUID;
                case DATA_GO_CURTAINS:              return m_uiCurtainGUID;
                case DATA_GO_LIBRARY_DOOR:          return m_uiLibraryDoor;
                case DATA_GO_MASSIVE_DOOR:          return m_uiMassiveDoor;
                case DATA_GO_SIDE_ENTRANCE_DOOR:    return m_uiSideEntranceDoor;
                case DATA_GO_GAME_DOOR:             return m_uiGamesmansDoor;
                case DATA_GO_GAME_EXIT_DOOR:        return m_uiGamesmansExitDoor;
                case DATA_GO_NETHER_DOOR:           return m_uiNetherspaceDoor;
                case DATA_MASTERS_TERRACE_DOOR_1:   return MastersTerraceDoor[0];
                case DATA_MASTERS_TERRACE_DOOR_2:   return MastersTerraceDoor[1];
                case DATA_IMAGE_OF_MEDIVH:          return ImageGUID;
            }

            return ObjectGuid::Empty;
        }

        void Load(char const* chrIn)
        {
            if (!chrIn)
            {
                OUT_LOAD_INST_DATA_FAIL;
                return;
            }

            OUT_LOAD_INST_DATA(chrIn);
            std::istringstream loadStream(chrIn);

            loadStream >> m_auiEncounter[0] >> m_auiEncounter[1] >> m_auiEncounter[2] >> m_auiEncounter[3]
                >> m_auiEncounter[4] >> m_auiEncounter[5] >> m_auiEncounter[6] >> m_auiEncounter[7]
                >> m_auiEncounter[8] >> m_auiEncounter[9] >> m_auiEncounter[10] >> m_auiEncounter[11];
            for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                if (m_auiEncounter[i] == IN_PROGRESS)                // Do not load an encounter as "In Progress" - reset it instead.
                    m_auiEncounter[i] = NOT_STARTED;
            OUT_LOAD_INST_DATA_COMPLETE;
        }
    };
};

void AddSC_instance_karazhan()
{
    new instance_karazhan();
}
