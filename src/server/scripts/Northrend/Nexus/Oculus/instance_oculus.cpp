/*
 * Copyright (C) 2010 TrinityScript 2
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

#define MAX_ENCOUNTER 5

/* The Occulus encounters:
0 - Drakos the Interrogator
1 - Varos Cloudstrider
2 - Mage-Lord Urom
3 - Ley-Guardian Eregos */

struct Locations {
        float x,y,z,o;
};

static Locations BossMoveLoc[]=
{
    {951.233337f, 1034.698608f, 359.967377f, 1.119904f}, // Verdisa
    {943.559143f, 1045.573730f, 359.967377f, 0.365921f}, // Belgar
    {944.670776f, 1058.858032f, 359.967377f, 5.639870f}  // Eternos
};

class instance_oculus : public InstanceMapScript
{
public:
    instance_oculus() : InstanceMapScript("instance_oculus", 578) { }

    struct instance_oculus_InstanceMapScript : public InstanceScript
    {
        instance_oculus_InstanceMapScript(Map* pMap) : InstanceScript(pMap) {Initialize();};

        uint64 uiDrakos;
        uint64 uiVaros;
        uint64 uiUrom;
        uint64 uiEregos;
        uint64 uiBera;
        uint64 uiVerdisa;
        uint64 uiEternos;
        uint64 uiLootGUID;


        uint16 m_auiEncounter[MAX_ENCOUNTER];
        std::string str_data;

        void Initialize()
        {              
            memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));
                    uiDrakos = 0;
                    uiVaros = 0;
                    uiUrom = 0;
                    uiEregos = 0;
                    uiBera = 0;
                    uiVerdisa = 0;
                    uiEternos = 0;
                    uiLootGUID = 0;
        }

        std::list<uint64> GameObjectList;

        void OnGameObjectCreate(GameObject* go)
        {
            switch(go->GetEntry())
            {
                case GO_DRAGON_CAGE_DOOR:
                    if (DATA_DRAKOS_EVENT == DONE)
                        go->SetGoState(GO_STATE_ACTIVE);
                    else
                        go->SetGoState(GO_STATE_READY);       
                        GameObjectList.push_back(go->GetGUID());
                        break;
                case GO_CACHE_OF_ERAGOS:
                case GO_CACHE_OF_ERAGOS_H:
                    uiLootGUID = go->GetGUID();
                    break;
            }
        }

        void OnCreatureCreate(Creature* creature)
        {
            switch(creature->GetEntry())
            {
                case CREATURE_DRAKOS:
                    uiDrakos = creature->GetGUID();
                    break;
                case CREATURE_VAROS:
                    uiVaros = creature->GetGUID();
                    break;
                case CREATURE_UROM:
                    uiUrom = creature->GetGUID();
                    break;
                case CREATURE_EREGOS:
                    uiEregos = creature->GetGUID();
                    creature->SetUnitMovementFlags(MOVEMENTFLAG_CAN_FLY);
                    break;
                case CREATURE_AZURE_GUARDIAN:
                    creature->SetUnitMovementFlags(MOVEMENTFLAG_CAN_FLY);
                    break;
                case NPC_BELGARISTRASZ:
                    uiBera = creature->GetGUID();
                    creature->SetReactState(REACT_PASSIVE);
                    break;
                case NPC_VERDISA:
                    uiVerdisa = creature->GetGUID();
                    creature->SetReactState(REACT_PASSIVE);
                    break;
                case NPC_ETERNOS :
                    uiEternos = creature->GetGUID();
                    creature->SetReactState(REACT_PASSIVE);
                    break;
                break;      
            }
        }

        void SetData(uint32 type, uint32 data)
        {
            switch(type)
            {
                case DATA_DRAKOS_EVENT:
                    m_auiEncounter[0] = data;
                                    if (data == DONE)
                                    {
                        OpenCageDoors();
                                            if(uiBera)
                                                    {
                                                            Creature* pBera = instance->GetCreature(uiBera);
                                                            if(pBera)
                                                            {
                                                                    pBera->SetUnitMovementFlags(MOVEMENTFLAG_WALKING);
                                                                    pBera->GetMotionMaster()->MovePoint(1,BossMoveLoc[1].x,BossMoveLoc[1].y,BossMoveLoc[1].z);
                                                            }
                                                    }
                                                    if(uiVerdisa)
                                                    {
                                                            Creature* pVerdisa = instance->GetCreature(uiVerdisa);
                                                            if(pVerdisa)
                                                            {
                                                                    pVerdisa->SetUnitMovementFlags(MOVEMENTFLAG_WALKING);
                                                                    pVerdisa->GetMotionMaster()->MovePoint(2,BossMoveLoc[0].x,BossMoveLoc[0].y,BossMoveLoc[0].z);
                                                            }
                                                    }
                                                    if(uiEternos)
                                                    {
                                                            Creature* pEternos = instance->GetCreature(uiEternos);
                                                            if(pEternos)
                                                            {
                                                                    pEternos->SetUnitMovementFlags(MOVEMENTFLAG_WALKING);
                                                                    pEternos->GetMotionMaster()->MovePoint(3,BossMoveLoc[2].x,BossMoveLoc[2].y,BossMoveLoc[2].z);
                                                            }
                                                    }
                                    }
                    break;
                case DATA_VAROS_EVENT:
                    m_auiEncounter[1] = data;
                    break;
                case DATA_UROM_EVENT:
                    m_auiEncounter[2] = data;
                    break;
                case DATA_EREGOS_EVENT:
                    m_auiEncounter[3] = data;
                                    if(data == DONE)
                                    {
                                        if (GameObject* pChest = instance->GetGameObject(uiLootGUID))
                                                pChest->SetRespawnTime(1*DAY);
                                    }
                    break;
                case DATA_CENTRIFUGE_CONSTRUCT_EVENT:
                    m_auiEncounter[4] = data;
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
                case DATA_CENTRIFUGE_CONSTRUCT_EVENT:  return m_auiEncounter[4];;
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
                if (GameObject* go = instance->GetGameObject(*itr))
                    go->SetGoState(GO_STATE_ACTIVE);
            }
        }



        std::string GetSaveData()
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;
            saveStream << "T O " << m_auiEncounter[0] << " " << m_auiEncounter[1] << " " << m_auiEncounter[2] << " " << m_auiEncounter[3] << " " << m_auiEncounter[4];

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
            uint16 data0, data1, data2, data3, data4;

            std::istringstream loadStream(in);
            loadStream >> dataHead1 >> dataHead2 >> data0 >> data1 >> data2 >> data3 >> data4;

            if (dataHead1 == 'T' && dataHead2 == 'O')
            {
                m_auiEncounter[0] = data0;
                m_auiEncounter[1] = data1;
                m_auiEncounter[2] = data2;
                m_auiEncounter[3] = data3;
                m_auiEncounter[4] = data4;

                for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                    if (m_auiEncounter[i] == IN_PROGRESS)
                        m_auiEncounter[i] = NOT_STARTED;

            } else OUT_LOAD_INST_DATA_FAIL;

            OUT_LOAD_INST_DATA_COMPLETE;
        }
    };

    InstanceScript* GetInstanceScript(InstanceMap* pMap) const
    {
        return new instance_oculus_InstanceMapScript(pMap);
    };
};

void AddSC_instance_oculus()
{
    new instance_oculus();
}