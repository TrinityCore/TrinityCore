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
#include "ulduar.h"

enum eGameObjects
{
    GO_KOLOGARN_CHEST_HERO  = 195047,
    GO_KOLOGARN_CHEST       = 195046,
    GO_THORIM_CHEST_HERO    = 194315,
    GO_THORIM_CHEST         = 194314,
    GO_HODIR_CHEST_HERO     = 194308,
    GO_HODIR_CHEST          = 194307,
    GO_FREYA_CHEST_HERO     = 194325,
    GO_FREYA_CHEST          = 194324,
    GO_LEVIATHAN_DOOR       = 194905,
    GO_LEVIATHAN_GATE       = 194630
};

struct instance_ulduar : public ScriptedInstance
{
    instance_ulduar(Map* pMap) : ScriptedInstance(pMap) { Initialize(); };

    uint32 uiEncounter[MAX_ENCOUNTER];
    std::string m_strInstData;
    uint8  flag;

    uint64 uiLeviathanGUID;
    uint64 uiIgnisGUID;
    uint64 uiRazorscaleGUID;
    uint64 uiXT002GUID;
    uint64 uiAssemblyGUIDs[3];
    uint64 uiKologarnGUID;
    uint64 uiAuriayaGUID;
    uint64 uiMimironGUID;
    uint64 uiHodirGUID;
    uint64 uiThorimGUID;
    uint64 uiFreyaGUID;
    uint64 uiVezaxGUID;
    uint64 uiYoggSaronGUID;
    uint64 uiAlgalonGUID;
    uint64 uiLeviathanDoor[7];
    uint64 uiLeviathanGateGUID;

    uint64 uiKologarnChestGUID;
    uint64 uiThorimChestGUID;
    uint64 uiHodirChestGUID;
    uint64 uiFreyaChestGUID;

    void Initialize()
    {   
        uiIgnisGUID           = 0;
        uiRazorscaleGUID      = 0;
        uiXT002GUID           = 0;
        uiKologarnGUID        = 0;
        uiAuriayaGUID         = 0;
        uiMimironGUID         = 0;
        uiHodirGUID           = 0;
        uiThorimGUID          = 0;
        uiFreyaGUID           = 0;
        uiVezaxGUID           = 0;
        uiYoggSaronGUID       = 0;
        uiAlgalonGUID         = 0;
        uiKologarnChestGUID   = 0;
        uiKologarnChestGUID   = 0;
        uiHodirChestGUID      = 0;
        uiFreyaChestGUID      = 0;
        uiLeviathanGateGUID   = 0;
        flag                  = 0;

        memset(&uiEncounter, 0, sizeof(uiEncounter));
        memset(&uiAssemblyGUIDs, 0, sizeof(uiAssemblyGUIDs));
        memset(&uiLeviathanDoor, 0, sizeof(uiLeviathanDoor));
    }

    bool IsEncounterInProgress() const
    {
        for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
        {
            if (uiEncounter[i] == IN_PROGRESS)
                return true;
        }

        return false;
    }

    void OnCreatureCreate(Creature* pCreature, bool /*add*/)
    {
        switch(pCreature->GetEntry())
        {
            case NPC_LEVIATHAN:
                uiLeviathanGUID = pCreature->GetGUID();             
                break;
            case NPC_IGNIS:
                uiIgnisGUID = pCreature->GetGUID();
                break;
            case NPC_RAZORSCALE:
                uiRazorscaleGUID = pCreature->GetGUID();
                break;
            case NPC_XT002:
                uiXT002GUID = pCreature->GetGUID();
                break;

            // Assembly of Iron
            case NPC_STEELBREAKER:
                uiAssemblyGUIDs[0] = pCreature->GetGUID();
                break;
            case NPC_MOLGEIM:
                uiAssemblyGUIDs[1] = pCreature->GetGUID();
                break;
            case NPC_BRUNDIR:
                uiAssemblyGUIDs[2] = pCreature->GetGUID();
                break;

            case NPC_KOLOGARN:
                uiKologarnGUID = pCreature->GetGUID();
                break;
            case NPC_AURIAYA:
                uiAuriayaGUID = pCreature->GetGUID();
                break;
            case NPC_MIMIRON:
                uiMimironGUID = pCreature->GetGUID();
                break;
            case NPC_HODIR:
                uiHodirGUID = pCreature->GetGUID();
                break;
            case NPC_THORIM:
                uiThorimGUID = pCreature->GetGUID();
                break;
            case NPC_FREYA:
                uiFreyaGUID = pCreature->GetGUID();
                break;
            case NPC_VEZAX:
                uiVezaxGUID = pCreature->GetGUID();
                break;
            case NPC_YOGGSARON:
                uiYoggSaronGUID = pCreature->GetGUID();
                break;
            case NPC_ALGALON:
                uiAlgalonGUID = pCreature->GetGUID();
                break;
        }

     }

    void OnGameObjectCreate(GameObject* pGO, bool add)
    {
        switch(pGO->GetEntry())
        {
            case GO_KOLOGARN_CHEST_HERO:
            case GO_KOLOGARN_CHEST:
                uiKologarnChestGUID  = add ? pGO->GetGUID() : NULL;
                break;
            case GO_THORIM_CHEST_HERO:
            case GO_THORIM_CHEST:
                uiThorimChestGUID = add ? pGO->GetGUID() : NULL;
                break;
            case GO_HODIR_CHEST_HERO:
            case GO_HODIR_CHEST:
                uiHodirChestGUID = add ? pGO->GetGUID() : NULL;
                break;
            case GO_FREYA_CHEST_HERO:
            case GO_FREYA_CHEST:
                uiFreyaChestGUID = add ? pGO->GetGUID() : NULL;
                break;
            case GO_LEVIATHAN_DOOR:
                uiLeviathanDoor[flag] = pGO->GetGUID();
                HandleGameObject(NULL, true, pGO);
                flag++;
                if (flag == 7)
                    flag =0;
                break;
            case GO_LEVIATHAN_GATE:                
                uiLeviathanGateGUID = add ? pGO->GetGUID() : NULL;
                HandleGameObject(NULL, false, pGO); 
                break;             
        }
    }

    void ProcessEvent(GameObject* pGO, uint32 uiEventId)
    {
        // Flame Leviathan's Tower Event triggers
       Creature* pFlameLeviathan = instance->GetCreature(uiLeviathanGUID);

        if (pFlameLeviathan && pFlameLeviathan->isAlive()) //No leviathan, no event triggering ;)
            switch(uiEventId)
            {
                case EVENT_TOWER_OF_STORM_DESTROYED:
                    //pGO->GetInstanceData()->SetData(DATA_TOWER_STORMS,DESTROYED);
                    pFlameLeviathan->AI()->DoAction(1);                    
                    break;
                case EVENT_TOWER_OF_FROST_DESTROYED:
                    pFlameLeviathan->AI()->DoAction(2);
                    break;
                case EVENT_TOWER_OF_FLAMES_DESTROYED:
                    pFlameLeviathan->AI()->DoAction(3);
                    break;
                case EVENT_TOWER_OF_LIFE_DESTROYED:
                    pFlameLeviathan->AI()->DoAction(4);
                    break;
            }
    }

    void SetData(uint32 type, uint32 data)
    {
        switch(type)
        {
            /*case TYPE_IGNIS:
            case TYPE_RAZORSCALE:
            case TYPE_XT002:
            case TYPE_ASSEMBLY:
            case TYPE_AURIAYA:
            case TYPE_MIMIRON:
            case TYPE_VEZAX:
            case TYPE_YOGGSARON:
                break;*/
            case TYPE_LEVIATHAN:
                if (data == IN_PROGRESS)
                {
                    for (uint8 uiI = 0; uiI < 7; ++uiI)
                        HandleGameObject(uiLeviathanDoor[uiI],false);
                }
                else
                {
                    for (uint8 uiI = 0; uiI < 7; ++uiI)
                        HandleGameObject(uiLeviathanDoor[uiI],true);
                }
                break;
            case TYPE_KOLOGARN:
                if (data == DONE)
                    if (GameObject* pGO = instance->GetGameObject(uiKologarnChestGUID))
                        pGO->SetRespawnTime(pGO->GetRespawnDelay());
                break;
            case TYPE_HODIR:
                if (data == DONE)
                    if (GameObject* pGO = instance->GetGameObject(uiHodirChestGUID))
                        pGO->SetRespawnTime(pGO->GetRespawnDelay());
                break;
            case TYPE_THORIM:
                if (data == DONE)
                    if (GameObject* pGO = instance->GetGameObject(uiThorimChestGUID))
                        pGO->SetRespawnTime(pGO->GetRespawnDelay());
                break;
            case TYPE_FREYA:
                if (data == DONE)
                    if (GameObject* pGO = instance->GetGameObject(uiFreyaChestGUID))
                        pGO->SetRespawnTime(pGO->GetRespawnDelay());
                break;
            case TYPE_COLOSSUS:
                uiEncounter[TYPE_COLOSSUS] = data;
                if (data == 2)
                {
                    if (Creature* pBoss = instance->GetCreature(uiLeviathanGUID))
                        pBoss->AI()->DoAction(10);
                    if (GameObject* pGate = instance->GetGameObject(uiLeviathanGateGUID))
                        pGate->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);                                                               
                }
                break;            
            default:
                break;
        }

        if (data == DONE)
            SaveToDB();
    }

    uint64 GetData64(uint32 data)
    {
        switch(data)
        {
            case TYPE_LEVIATHAN:            return uiLeviathanGUID;
            case TYPE_IGNIS:                return uiIgnisGUID;
            case TYPE_RAZORSCALE:           return uiRazorscaleGUID;
            case TYPE_XT002:                return uiXT002GUID;
            case TYPE_KOLOGARN:             return uiKologarnGUID;
            case TYPE_AURIAYA:              return uiAuriayaGUID;
            case TYPE_MIMIRON:              return uiMimironGUID;
            case TYPE_HODIR:                return uiMimironGUID;
            case TYPE_THORIM:               return uiThorimGUID;
            case TYPE_FREYA:                return uiFreyaGUID;
            case TYPE_VEZAX:                return uiVezaxGUID;
            case TYPE_YOGGSARON:            return uiYoggSaronGUID;
            case TYPE_ALGALON:              return uiAlgalonGUID;

            // Assembly of Iron
            case DATA_STEELBREAKER:         return uiAssemblyGUIDs[0];
            case DATA_MOLGEIM:              return uiAssemblyGUIDs[1];
            case DATA_BRUNDIR:              return uiAssemblyGUIDs[2];
        }

        return 0;
    }

    uint32 GetData(uint32 type)
    {
        switch(type)
        {
            case TYPE_LEVIATHAN:
            case TYPE_IGNIS:
            case TYPE_RAZORSCALE:
            case TYPE_XT002:
            case TYPE_ASSEMBLY:
            case TYPE_KOLOGARN:
            case TYPE_AURIAYA:
            case TYPE_MIMIRON:
            case TYPE_HODIR:
            case TYPE_THORIM:
            case TYPE_FREYA:
            case TYPE_VEZAX:
            case TYPE_YOGGSARON:
            case TYPE_ALGALON:
            case TYPE_COLOSSUS:
                return uiEncounter[type];
        }

        return 0;
    }

    std::string GetSaveData()
    {
        OUT_SAVE_INST_DATA;

        std::ostringstream saveStream;
        saveStream << "U U " << uiEncounter[0] << " " << uiEncounter[1] << " " << uiEncounter[2] << " " << uiEncounter[3]
                   << " " << uiEncounter[4] << " " << uiEncounter[5] << " " << uiEncounter[6] << " " << uiEncounter[7]
                   << " " << uiEncounter[8] << " " << uiEncounter[9] << " " << uiEncounter[10] << " " << uiEncounter[11]
                   << " " << uiEncounter[12] << " " << uiEncounter[13] << " " << uiEncounter[14];

        m_strInstData = saveStream.str();

        OUT_SAVE_INST_DATA_COMPLETE;
        return m_strInstData;
    }

    void Load(const char* strIn)
    {
        if (!strIn)
        {
            OUT_LOAD_INST_DATA_FAIL;
            return;
        }

        OUT_LOAD_INST_DATA(strIn);

        char dataHead1, dataHead2;
        uint32 data0, data1, data2, data3, data4, data5, data6,
            data7, data8, data9, data10, data11, data12, data13, data14;

        std::istringstream loadStream(strIn);
        loadStream >> dataHead1 >> dataHead2 >> data0 >> data1 >> data2 >> data3 >> data4 >> data5 >> data6
            >> data7 >> data8 >> data9 >> data10 >> data11 >> data12 >> data13 >> data14;

        if (dataHead1 == 'U' && dataHead2 == 'U')
        {
            for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
            {
                loadStream >> uiEncounter[i];

                if (uiEncounter[i] == IN_PROGRESS)
                    uiEncounter[i] = NOT_STARTED;
            }
        }
        OUT_LOAD_INST_DATA_COMPLETE;
    }
};

InstanceData* GetInstanceData_instance_ulduar(Map* pMap)
{
    return new instance_ulduar(pMap);
}

void AddSC_instance_ulduar()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_ulduar";
    newscript->GetInstanceData = &GetInstanceData_instance_ulduar;
    newscript->RegisterSelf();
}
