/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "halls_of_stone.h"

#define MAX_ENCOUNTER 4

/* Halls of Stone encounters:
0- Krystallus
1- Maiden of Grief
2- Escort Event
3- Sjonnir The Ironshaper
*/

class instance_halls_of_stone : public InstanceMapScript
{
public:
    instance_halls_of_stone() : InstanceMapScript("instance_halls_of_stone") { }

    InstanceScript* GetInstanceData_InstanceMapScript(Map* pMap)
    {
        return new instance_halls_of_stone_InstanceMapScript(pMap);
    }

    struct instance_halls_of_stone_InstanceMapScript : public InstanceScript
    {
        instance_halls_of_stone_InstanceMapScript(Map* pMap) : InstanceScript(pMap) {Initialize();};

        uint64 uiMaidenOfGrief;
        uint64 uiKrystallus;
        uint64 uiSjonnir;

        uint64 uiKaddrak;
        uint64 uiAbedneum;
        uint64 uiMarnak;
        uint64 uiBrann;

        uint64 uiMaidenOfGriefDoor;
        uint64 uiSjonnirDoor;
        uint64 uiBrannDoor;
        uint64 uiTribunalConsole;
        uint64 uiTribunalChest;
        uint64 uiTribunalSkyFloor;
        uint64 uiKaddrakGo;
        uint64 uiAbedneumGo;
        uint64 uiMarnakGo;

        uint32 m_auiEncounter[MAX_ENCOUNTER];

        std::string str_data;

        void Initialize()
        {
            uiMaidenOfGrief = 0;
            uiKrystallus = 0;
            uiSjonnir = 0;

            uiKaddrak = 0;
            uiMarnak = 0;
            uiAbedneum = 0;
            uiBrann = 0;

            uiMaidenOfGriefDoor = 0;
            uiSjonnirDoor = 0;
            uiBrannDoor = 0;
            uiKaddrakGo = 0;
            uiMarnakGo = 0;
            uiAbedneumGo = 0;
            uiTribunalConsole = 0;
            uiTribunalChest = 0;
            uiTribunalSkyFloor = 0;

            for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                m_auiEncounter[i] = NOT_STARTED;
        }

        void OnCreatureCreate(Creature* pCreature, bool /*add*/)
        {
            switch(pCreature->GetEntry())
            {
                case CREATURE_MAIDEN: uiMaidenOfGrief = pCreature->GetGUID(); break;
                case CREATURE_KRYSTALLUS: uiKrystallus = pCreature->GetGUID(); break;
                case CREATURE_SJONNIR: uiSjonnir = pCreature->GetGUID(); break;
                case CREATURE_MARNAK: uiMarnak = pCreature->GetGUID(); break;
                case CREATURE_KADDRAK: uiKaddrak = pCreature->GetGUID(); break;
                case CREATURE_ABEDNEUM: uiAbedneum = pCreature->GetGUID(); break;
                case CREATURE_BRANN: uiBrann = pCreature->GetGUID(); break;
            }
        }

        void OnGameObjectCreate(GameObject* pGo, bool /*add*/)
        {
            switch(pGo->GetEntry())
            {
                case GO_ABEDNEUM:
                    uiAbedneumGo = pGo->GetGUID();
                    break;
                case GO_MARNAK:
                    uiMarnakGo = pGo->GetGUID();
                    break;
                case GO_KADDRAK:
                    uiKaddrakGo = pGo->GetGUID();
                    break;
                case GO_MAIDEN_DOOR:
                    uiMaidenOfGriefDoor = pGo->GetGUID();
                    if (m_auiEncounter[0] == DONE)
                        pGo->SetGoState(GO_STATE_ACTIVE);
                    else
                        pGo->SetGoState(GO_STATE_READY);
                    break;
                case GO_BRANN_DOOR:
                    uiBrannDoor = pGo->GetGUID();
                    if (m_auiEncounter[1] == DONE)
                        pGo->SetGoState(GO_STATE_ACTIVE);
                    else
                        pGo->SetGoState(GO_STATE_READY);
                    break;
                case GO_SJONNIR_DOOR:
                    uiSjonnirDoor = pGo->GetGUID();
                    if (m_auiEncounter[2] == DONE)
                        pGo->SetGoState(GO_STATE_ACTIVE);
                    else
                        pGo->SetGoState(GO_STATE_READY);
                    break;
                case GO_TRIBUNAL_CONSOLE:
                    uiTribunalConsole = pGo->GetGUID();
                    break;
                case GO_TRIBUNAL_CHEST:
                case GO_TRIBUNAL_CHEST_HERO:
                    uiTribunalChest = pGo->GetGUID();
                    if (m_auiEncounter[2] == DONE)
                        pGo->RemoveFlag(GAMEOBJECT_FLAGS,GO_FLAG_INTERACT_COND);
                    break;
                case 191527:
                    uiTribunalSkyFloor = pGo->GetGUID();
                    break;
            }
        }

        void SetData(uint32 type, uint32 data)
        {
            switch(type)
            {
                case DATA_MAIDEN_OF_GRIEF_EVENT:
                    m_auiEncounter[1] = data;
                    if (m_auiEncounter[1] == DONE)
                        HandleGameObject(uiBrannDoor,true);
                    break;
                case DATA_KRYSTALLUS_EVENT:
                    m_auiEncounter[0] = data;
                    if (m_auiEncounter[0] == DONE)
                        HandleGameObject(uiMaidenOfGriefDoor,true);
                    break;
                case DATA_SJONNIR_EVENT:
                    m_auiEncounter[3] = data;
                    break;
                case DATA_BRANN_EVENT:
                    m_auiEncounter[2] = data;
                    if (m_auiEncounter[2] == DONE)
                    {
                        HandleGameObject(uiSjonnirDoor,true);
                        GameObject *pGo = instance->GetGameObject(uiTribunalChest);
                        if (pGo)
                            pGo->RemoveFlag(GAMEOBJECT_FLAGS,GO_FLAG_INTERACT_COND);
                    }
                    break;
            }

            if (data == DONE)
                SaveToDB();
        }

        uint32 GetData(uint32 type)
        {
            switch(type)
            {
                case DATA_KRYSTALLUS_EVENT:                return m_auiEncounter[0];
                case DATA_MAIDEN_OF_GRIEF_EVENT:           return m_auiEncounter[1];
                case DATA_SJONNIR_EVENT:                   return m_auiEncounter[2];
                case DATA_BRANN_EVENT:                     return m_auiEncounter[3];
            }

            return 0;
        }

        uint64 GetData64(uint32 identifier)
        {
            switch(identifier)
            {
                case DATA_MAIDEN_OF_GRIEF:                 return uiMaidenOfGrief;
                case DATA_KRYSTALLUS:                      return uiKrystallus;
                case DATA_SJONNIR:                         return uiSjonnir;
                case DATA_KADDRAK:                         return uiKaddrak;
                case DATA_MARNAK:                          return uiMarnak;
                case DATA_ABEDNEUM:                        return uiAbedneum;
                case DATA_GO_TRIBUNAL_CONSOLE:             return uiTribunalConsole;
                case DATA_GO_KADDRAK:                      return uiKaddrakGo;
                case DATA_GO_ABEDNEUM:                     return uiAbedneumGo;
                case DATA_GO_MARNAK:                       return uiMarnakGo;
                case DATA_GO_SKY_FLOOR:                    return uiTribunalSkyFloor;
                case DATA_SJONNIR_DOOR:                    return uiSjonnirDoor;
                case DATA_MAIDEN_DOOR:                     return uiMaidenOfGriefDoor;
            }

            return 0;
        }

        std::string GetSaveData()
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;
            saveStream << "H S " << m_auiEncounter[0] << " " << m_auiEncounter[1] << " " << m_auiEncounter[2] << " " << m_auiEncounter[3];

            str_data = saveStream.str();

            OUT_SAVE_INST_DATA_COMPLETE;
            return str_data;
        }

        void Load(const char* in)
        {
            if (!in)
            {
                OUT_LOAD_INST_DATA_FAIL;
                return;
            }

            OUT_LOAD_INST_DATA(in);

            char dataHead1, dataHead2;
            uint16 data0, data1, data2, data3;

            std::istringstream loadStream(in);
            loadStream >> dataHead1 >> dataHead2 >> data0 >> data1 >> data2 >> data3;

            if (dataHead1 == 'H' && dataHead2 == 'S')
            {
                m_auiEncounter[0] = data0;
                m_auiEncounter[1] = data1;
                m_auiEncounter[2] = data2;
                m_auiEncounter[3] = data3;

                for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                    if (m_auiEncounter[i] == IN_PROGRESS)
                        m_auiEncounter[i] = NOT_STARTED;

            } else OUT_LOAD_INST_DATA_FAIL;

            OUT_LOAD_INST_DATA_COMPLETE;
        }
    };

};


void AddSC_instance_halls_of_stone()
{
    new instance_halls_of_stone();
}
