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
#include "halls_of_reflection.h"

#define MAX_ENCOUNTER 3

/* Halls of Reflection encounters:
0- Falric
1- Marwyn
2- The Lich King
*/

struct instance_halls_of_reflection : public ScriptedInstance
{
    instance_halls_of_reflection(Map* pMap) : ScriptedInstance(pMap) {Initialize();};

    uint64 uiFalric;
    uint64 uiMarwyn;
    uint64 uiLichKing;

    uint32 m_auiEncounter[MAX_ENCOUNTER];

    void Initialize()
    {
        uiFalric = 0;
        uiMarwyn = 0;
        uiLichKing = 0;

        for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
            m_auiEncounter[i] = NOT_STARTED;
    }

    void OnCreatureCreate(Creature* pCreature, bool /*add*/)
    {
        switch(pCreature->GetEntry())
        {
            case CREATURE_FALRIC:
                uiFalric = pCreature->GetGUID();
                break;
            case CREATURE_MARWYN:
                uiMarwyn = pCreature->GetGUID();
                break;
            case CREATURE_LICHKING:
                uiLichKing = pCreature->GetGUID();
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
            case DATA_FALRIC_EVENT:
                m_auiEncounter[0] = data;
                break;
            case DATA_MARWYN_EVENT:
                m_auiEncounter[1] = data;
                break;
            case DATA_LICHKING_EVENT:
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
            case DATA_FALRIC_EVENT:         return m_auiEncounter[0];
            case DATA_MARWYN_EVENT:         return m_auiEncounter[1];
            case DATA_LICHKING_EVENT:       return m_auiEncounter[2];
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
        saveStream << "H R " << m_auiEncounter[0] << " " << m_auiEncounter[1] << m_auiEncounter[2];

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

        if (dataHead1 == 'H' && dataHead2 == 'R')
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

InstanceData* GetInstanceData_instance_halls_of_reflection(Map* pMap)
{
    return new instance_halls_of_reflection(pMap);
}

void AddSC_halls_of_reflection()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_halls_of_reflection";
    newscript->GetInstanceData = &GetInstanceData_instance_halls_of_reflection;
    newscript->RegisterSelf();
}
