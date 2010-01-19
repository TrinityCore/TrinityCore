/*
* Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/

#include "ScriptedPch.h"
#include "culling_of_stratholme.h"

#define MAX_ENCOUNTER 5

/* Culling of Stratholme encounters:
0 - Meathook
1 - Salramm the Fleshcrafter
2 - Chrono-Lord Epoch 
3 - Mal'Ganis 
4 - Infinite Corruptor (Heroic only)
*/

struct TRINITY_DLL_DECL instance_culling_of_stratholme : public ScriptedInstance
{
    instance_culling_of_stratholme(Map* pMap) : ScriptedInstance(pMap) {Initialize();};
    
    uint64 uiMeathook;
    uint64 uiSalramm;
    uint64 uiEpoch;
    uint64 uiMalGanis;
    uint64 uiInfinite;

    uint64 uiShkafGate;
    uint64 uiMalGanisGate1;
    uint64 uiMalGanisGate2;
    uint64 uiMalGanisChest;
    
    uint8 m_auiEncounter[MAX_ENCOUNTER];
    std::string str_data;
    
    bool IsEncounterInProgress() const
    {
        for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
            if (m_auiEncounter[i] == IN_PROGRESS) return true;

        return false;
    }
    
    void OnCreatureCreate(Creature* pCreature, bool add)
    {
        switch(pCreature->GetEntry())
        {
            case NPC_MEATHOOK:
                uiMeathook = pCreature->GetGUID();
                break;
            case NPC_SALRAMM:
                uiSalramm = pCreature->GetGUID();
                break;
            case NPC_EPOCH:
                uiEpoch = pCreature->GetGUID();
                break;
            case NPC_MAL_GANIS:
                uiMalGanis = pCreature->GetGUID();
                break;
            case NPC_INFINITE:
                uiInfinite = pCreature->GetGUID();
                break;
        }
    }

    void OnGameObjectCreate(GameObject* pGo, bool add)
    {
        switch(pGo->GetEntry())
        {
            case GO_SHKAF_GATE:
                uiShkafGate = pGo->GetGUID();
                break;
            case GO_MALGANIS_GATE_1:
                uiMalGanisGate1 = pGo->GetGUID();
                break;
            case GO_MALGANIS_GATE_2:
                uiMalGanisGate2 = pGo->GetGUID();
                break;
            case GO_MALGANIS_CHEST:
                uiMalGanisChest = pGo->GetGUID();
                break;
        }
    }
    
    void SetData(uint32 type, uint32 data)
    {
        switch(type)
        {
            case DATA_MEATHOOK_EVENT:
                m_auiEncounter[0] = data;
                break;
            case DATA_SALRAMM_EVENT:
                m_auiEncounter[1] = data;
                break;
            case DATA_EPOCH_EVENT:
                m_auiEncounter[2] = data;
                break;
            case DATA_MAL_GANIS_EVENT:
                m_auiEncounter[3] = data;
                GameObject *pGate;
                if (data == IN_PROGRESS && (pGate = instance->GetGameObject(uiMalGanisGate2)))
                    pGate->SetGoState(GO_STATE_READY);
                break;
            case DATA_INFINITE_EVENT:
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
            case DATA_MEATHOOK_EVENT:             return m_auiEncounter[0];
            case DATA_SALRAMM_EVENT:              return m_auiEncounter[1];
            case DATA_EPOCH_EVENT:                return m_auiEncounter[2];
            case DATA_MAL_GANIS_EVENT:            return m_auiEncounter[3];
            case DATA_INFINITE_EVENT:             return m_auiEncounter[4];
        }
        return 0;
    }
    
    uint64 GetData64(uint32 identifier)
    {
        switch(identifier)
        {
            case DATA_MEATHOOK:                   return uiMeathook;
            case DATA_SALRAMM:                    return uiSalramm;
            case DATA_EPOCH:                      return uiEpoch;
            case DATA_MAL_GANIS:                  return uiMalGanis;
            case DATA_INFINITE:                   return uiInfinite;
            case DATA_MAL_GANIS_GATE_1:           return uiMalGanisGate1;
            case DATA_MAL_GANIS_GATE_2:           return uiMalGanisGate2;
            case DATA_MAL_GANIS_CHEST:            return uiMalGanisChest;
        }
        return 0;
    }
    
    std::string GetSaveData()
    {
        OUT_SAVE_INST_DATA;

        std::ostringstream saveStream;
        saveStream << "C S " << m_auiEncounter[0] << " " << m_auiEncounter[1] << " "
            << m_auiEncounter[2] << " " << m_auiEncounter[3] << " " << m_auiEncounter[4];

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

        if (dataHead1 == 'C' && dataHead2 == 'S')
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

InstanceData* GetInstanceData_instance_culling_of_stratholme(Map* pMap)
{
    return new instance_culling_of_stratholme(pMap);
}

void AddSC_instance_culling_of_stratholme()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_culling_of_stratholme";
    newscript->GetInstanceData = &GetInstanceData_instance_culling_of_stratholme;
    newscript->RegisterSelf();
}
