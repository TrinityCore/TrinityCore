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
#include "oculus.h"

#define MAX_ENCOUNTER 4

/* The Occulus encounters:
0 - Drakos the Interrogator
1 - Varos Cloudstrider
2 - Mage-Lord Urom
3 - Ley-Guardian Eregos */

class instance_oculus : public InstanceMapScript
{
public:
    instance_oculus() : InstanceMapScript("instance_oculus", 578) { }

    InstanceScript* GetInstanceScript(InstanceMap* pMap) const
    {
        return new instance_oculus_InstanceMapScript(pMap);
    }

    struct instance_oculus_InstanceMapScript : public InstanceScript
    {
        instance_oculus_InstanceMapScript(Map* pMap) : InstanceScript(pMap) {Initialize();};

        uint64 uiDrakos;
        uint64 uiVaros;
        uint64 uiUrom;
        uint64 uiEregos;

        uint8 uiPlataformUrom;

        uint16 m_auiEncounter[MAX_ENCOUNTER];
        std::string str_data;

        std::list<uint64> GameObjectList;

        void Initialize()
        {
            uiPlataformUrom = 0;
        }

        void OnCreatureCreate(Creature* pCreature, bool /*add*/)
        {
            switch(pCreature->GetEntry())
            {
                case CREATURE_DRAKOS:
                    uiDrakos = pCreature->GetGUID();
                    break;
                case CREATURE_VAROS:
                    uiVaros = pCreature->GetGUID();
                    break;
                case CREATURE_UROM:
                    uiUrom = pCreature->GetGUID();
                    break;
                case CREATURE_EREGOS:
                    uiEregos = pCreature->GetGUID();
                    break;
            }
        }

        void OnGameObjectCreate(GameObject* pGO, bool bAdd)
        {
            if (pGO->GetEntry() == GO_DRAGON_CAGE_DOOR)
            {
                if (DATA_DRAKOS_EVENT == DONE)
                    pGO->SetGoState(GO_STATE_ACTIVE);
                else
                    pGO->SetGoState(GO_STATE_READY);

                GameObjectList.push_back(pGO->GetGUID());
            }
        }

        void SetData(uint32 type, uint32 data)
        {
            switch(type)
            {
                case DATA_DRAKOS_EVENT:
                    m_auiEncounter[0] = data;
                    if (data == DONE)
                        OpenCageDoors();
                    break;
                case DATA_VAROS_EVENT:
                    m_auiEncounter[1] = data;
                    break;
                case DATA_UROM_EVENT:
                    m_auiEncounter[2] = data;
                    break;
                case DATA_EREGOS_EVENT:
                    m_auiEncounter[3] = data;
                    break;
                case DATA_UROM_PLATAFORM:
                    uiPlataformUrom = data;
                    break;
            }

            if (data == DONE)
                SaveToDB();
        }

        uint32 GetData(uint32 type)
        {
            switch(type)
            {
                case DATA_DRAKOS_EVENT:                return m_auiEncounter[0];
                case DATA_VAROS_EVENT:                 return m_auiEncounter[1];
                case DATA_UROM_EVENT:                  return m_auiEncounter[2];
                case DATA_EREGOS_EVENT:                return m_auiEncounter[3];
                case DATA_UROM_PLATAFORM:              return uiPlataformUrom;
            }

            return 0;
        }

        uint64 GetData64(uint32 identifier)
        {
            switch(identifier)
            {
                case DATA_DRAKOS:                 return uiDrakos;
                case DATA_VAROS:                  return uiVaros;
                case DATA_UROM:                   return uiUrom;
                case DATA_EREGOS:                 return uiEregos;
            }

            return 0;
        }

        void OpenCageDoors()
        {
            if (GameObjectList.empty())
                return;

            for (std::list<uint64>::const_iterator itr = GameObjectList.begin(); itr != GameObjectList.end(); ++itr)
            {
                if (GameObject* pGO = instance->GetGameObject(*itr))
                    pGO->SetGoState(GO_STATE_ACTIVE);
            }
        }

        std::string GetSaveData()
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;
            saveStream << "T O " << m_auiEncounter[0] << " " << m_auiEncounter[1] << " " << m_auiEncounter[2] << " " << m_auiEncounter[3];

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

            if (dataHead1 == 'T' && dataHead2 == 'O')
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


void AddSC_instance_oculus()
{
    new instance_oculus();
}
