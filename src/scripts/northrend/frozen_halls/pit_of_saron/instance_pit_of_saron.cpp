/* Copyright (C) 2006 - 2010 TrinityCore <https://www.trinitycore.org/>
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
#include "pit_of_saron.h"

#define MAX_ENCOUNTER 3

/* Pit of Saron encounters:
0- Forgemaster Garfrost
1- Krick and Ick
2- Scourgelord Tyrannus
*/

struct instance_pit_of_saron : public ScriptedInstance
{
    instance_pit_of_saron(Map* pMap) : ScriptedInstance(pMap) {Initialize();};

    uint64 uiForgemaster;
    uint64 uiKrick;
    uint64 uiIck;
    uint64 uiTyrannus;

    uint32 m_auiEncounter[MAX_ENCOUNTER];

    void Initialize()
    {
        uiForgemaster = 0;
        uiKrick = 0;
        uiIck = 0;
        uiTyrannus = 0;
        
        for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
            m_auiEncounter[i] = NOT_STARTED;
    }

    void OnCreatureCreate(Creature* pCreature, bool add)
    {
        switch(pCreature->GetEntry())
        {
            case CREATURE_FORGEMASTER:
                uiForgemaster = pCreature->GetGUID();
                break;
            case CREATURE_KRICK:
                uiKrick = pCreature->GetGUID();
                break;
            case CREATURE_ICK:
                uiIck = pCreature->GetGUID();
                break;
            case CREATURE_TYRANNUS:
                uiTyrannus = pCreature->GetGUID();
                break;                
        }
    }
/*
    void OnGameObjectCreate(GameObject* pGo, bool add)
    {
        switch(pGo->GetEntry())
        {
        }
    }
*/
    void SetData(uint32 type, uint32 data)
    {
        switch(type)
        {
            case DATA_FORGEMASTER_EVENT:
                m_auiEncounter[0] = data;
                break;
            case DATA_KRICKANDICK_EVENT:
                m_auiEncounter[1] = data;
                break;
            case DATA_TYRANNUS_EVENT:
                m_auiEncounter[2] = data;
                break;                
        }

        if (data == DONE)
            SaveToDB();
    }

    uint32 GetData(uint32 type)
    {
        switch(type)
        {
            case DATA_FORGEMASTER_EVENT:    return m_auiEncounter[0];
            case DATA_KRICKANDICK_EVENT:    return m_auiEncounter[1];
            case DATA_TYRANNUS_EVENT:       return m_auiEncounter[2];
        }

        return 0;
    }
/*
    uint64 GetData64(uint32 identifier)
    {
        switch(identifier)
        {
        }

        return 0;
    }
*/
    std::string GetSaveData()
    {
        OUT_SAVE_INST_DATA;

        std::ostringstream saveStream;
        saveStream << "P S " << m_auiEncounter[0] << " " << m_auiEncounter[1] << m_auiEncounter[2];

        OUT_SAVE_INST_DATA_COMPLETE;
        return saveStream.str();
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
        uint16 data0, data1, data2;

        std::istringstream loadStream(in);
        loadStream >> dataHead1 >> dataHead2 >> data0 >> data1 >> data2;

        if (dataHead1 == 'P' && dataHead2 == 'S')
        {
            m_auiEncounter[0] = data0;
            m_auiEncounter[1] = data1;
            m_auiEncounter[2] = data2;

            for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                if (m_auiEncounter[i] == IN_PROGRESS)
                    m_auiEncounter[i] = NOT_STARTED;

        } else OUT_LOAD_INST_DATA_FAIL;

        OUT_LOAD_INST_DATA_COMPLETE;
    }
};

InstanceData* GetInstanceData_instance_pit_of_saron(Map* pMap)
{
    return new instance_pit_of_saron(pMap);
}

void AddSC_pit_of_saron()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_pit_of_saron";
    newscript->GetInstanceData = &GetInstanceData_instance_pit_of_saron;
    newscript->RegisterSelf();
}
