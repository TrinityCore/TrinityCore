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
#include "forge_of_souls.h"

#define MAX_ENCOUNTER 2

/* Forge of Souls encounters:
0- Bronjahm, The Godfather of Souls
1- The Devourer of Souls
*/

struct instance_forge_of_souls : public ScriptedInstance
{
    instance_forge_of_souls(Map* pMap) : ScriptedInstance(pMap) {Initialize();};

    uint64 uiBronjahm;
    uint64 uiDevourer;

    uint32 m_auiEncounter[MAX_ENCOUNTER];

    void Initialize()
    {
        uiBronjahm = 0;
        uiDevourer = 0;
        
        for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
            m_auiEncounter[i] = NOT_STARTED;
    }

    void OnCreatureCreate(Creature* pCreature, bool add)
    {
        switch(pCreature->GetEntry())
        {
            case CREATURE_BRONJAHM:
                uiBronjahm = pCreature->GetGUID();
                break;
            case CREATURE_DEVOURER:
                uiDevourer = pCreature->GetGUID();
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
            case DATA_BRONJAHM_EVENT:
                m_auiEncounter[0] = data;
                break;
            case DATA_DEVOURER_EVENT:
                m_auiEncounter[1] = data;
                break;
        }

        if (data == DONE)
            SaveToDB();
    }

    uint32 GetData(uint32 type)
    {
        switch(type)
        {
            case DATA_BRONJAHM_EVENT:    return m_auiEncounter[0];
            case DATA_DEVOURER_EVENT:    return m_auiEncounter[1];
        }

        return 0;
    }

    uint64 GetData64(uint32 identifier)
    {
        switch(identifier)
        {
            case DATA_BRONJAHM:         return uiBronjahm;
        }

        return 0;
    }

    std::string GetSaveData()
    {
        OUT_SAVE_INST_DATA;

        std::ostringstream saveStream;
        saveStream << "F S " << m_auiEncounter[0] << " " << m_auiEncounter[1];

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
        uint16 data0, data1;

        std::istringstream loadStream(in);
        loadStream >> dataHead1 >> dataHead2 >> data0 >> data1;

        if (dataHead1 == 'F' && dataHead2 == 'S')
        {
            m_auiEncounter[0] = data0;
            m_auiEncounter[1] = data1;

            for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                if (m_auiEncounter[i] == IN_PROGRESS)
                    m_auiEncounter[i] = NOT_STARTED;

        } else OUT_LOAD_INST_DATA_FAIL;

        OUT_LOAD_INST_DATA_COMPLETE;
    }
};

InstanceData* GetInstanceData_instance_forge_of_souls(Map* pMap)
{
    return new instance_forge_of_souls(pMap);
}

void AddSC_forge_of_souls()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_forge_of_souls";
    newscript->GetInstanceData = &GetInstanceData_instance_forge_of_souls;
    newscript->RegisterSelf();
}
