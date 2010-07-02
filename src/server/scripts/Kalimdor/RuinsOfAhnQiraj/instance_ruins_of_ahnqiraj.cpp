/* Copyright (C) 2008 - 2010 Trinity <http://www.trinitycore.org/>
 * Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

/* ScriptData
SDName: Instance_Ruins_of_Ahnqiraj
SD%Complete: 0
SDComment: Place holder
SDCategory: Ruins of Ahn'Qiraj
EndScriptData */

#include "ScriptPCH.h"
#include "ruins_of_ahnqiraj.h"

#define MAX_ENCOUNTER 6

/* Ruins of Ahn'Qiraj encounters:
0 - Kurinnaxx
1 - General Rajaxx
2 - Moam
3 - Buru the Gorger
4 - Ayamiss the Hunter
5 - Ossirian the Unscarred */

struct instance_ruins_of_ahn_qiraj : public ScriptedInstance
{
    instance_ruins_of_ahn_qiraj(Map* pMap) : ScriptedInstance(pMap) { Initialize(); }

    uint64 uiKurinaxx;
    uint64 uiRajaxx;
    uint64 uiMoam;
    uint64 uiBuru;
    uint64 uiAyamiss;
    uint64 uiOssirian;

    uint8 m_auiEncounter[MAX_ENCOUNTER];
    std::string str_data;

    void Initialize()
    {
        memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

        uiKurinaxx = 0;
        uiRajaxx = 0;
        uiMoam = 0;
        uiBuru = 0;
        uiAyamiss = 0;
        uiOssirian = 0;
    }

    bool IsEncounterInProgress() const
    {
        for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
            if (m_auiEncounter[i] == IN_PROGRESS) return true;

        return false;
    }

    void OnCreatureCreate(Creature* pCreature, bool /*add*/)
    {
        switch (pCreature->GetEntry())
        {
            case CREATURE_KURINAXX:
                uiKurinaxx = pCreature->GetGUID();
                break;
            case CREATURE_RAJAXX:
                uiRajaxx = pCreature->GetGUID();
                break;
            case CREATURE_MOAM:
                uiMoam = pCreature->GetGUID();
                break;
            case CREATURE_BURU:
                uiBuru = pCreature->GetGUID();
                break;
            case CREATURE_AYAMISS:
                uiAyamiss = pCreature->GetGUID();
                break;
            case CREATURE_OSSIRIAN:
                uiOssirian = pCreature->GetGUID();
                break;
        }
    }

    uint32 GetData(uint32 identifier)
    {
        switch(identifier)
        {
            case DATA_KURINNAXX_EVENT:               return m_auiEncounter[0];
            case DATA_RAJAXX_EVENT:                  return m_auiEncounter[1];
            case DATA_MOAM_EVENT:                    return m_auiEncounter[2];
            case DATA_BURU_EVENT:                    return m_auiEncounter[3];
            case DATA_AYAMISS_EVENT:                 return m_auiEncounter[4];
            case DATA_OSSIRIAN_EVENT:                return m_auiEncounter[5];
        }

        return 0;
    }

    void SetData(uint32 identifier, uint32 data)
    {
        switch(identifier)
        {
            case DATA_KURINNAXX_EVENT:
                m_auiEncounter[0] = data;
                break;
            case DATA_RAJAXX_EVENT:
                m_auiEncounter[1] = data;
                break;
            case DATA_MOAM_EVENT:
                m_auiEncounter[2] = data;
                break;
            case DATA_BURU_EVENT:
                m_auiEncounter[3] = data;
                break;
            case DATA_AYAMISS_EVENT:
                m_auiEncounter[4] = data;
                break;
            case DATA_OSSIRIAN_EVENT:
                m_auiEncounter[5] = data;
                break;
        }

        if (data == DONE)
            SaveToDB();
    }

    uint64 GetData64(uint32 uiIdentifier)
    {
        switch(uiIdentifier)
        {
            case DATA_KURINNAXX:              return uiKurinaxx;
            case DATA_RAJAXX:                 return uiRajaxx;
            case DATA_MOAM:                   return uiMoam;
            case DATA_BURU:                   return uiBuru;
            case DATA_AYAMISS:                return uiAyamiss;
            case DATA_OSSIRIAN:               return uiOssirian;
        }

        return 0;
    }

    std::string GetSaveData()
    {
        OUT_SAVE_INST_DATA;

        std::ostringstream saveStream;
        saveStream << "R A " << m_auiEncounter[0] << " " << m_auiEncounter[1] << " "
            << m_auiEncounter[2] << " " << m_auiEncounter[3] << " " << m_auiEncounter[4] << " " << m_auiEncounter[5];

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
        uint16 data0, data1, data2, data3, data4, data5;

        std::istringstream loadStream(in);
        loadStream >> dataHead1 >> dataHead2 >> data0 >> data1 >> data2 >> data3 >> data4 >> data5;

        if (dataHead1 == 'R' && dataHead2 == 'A')
        {
            m_auiEncounter[0] = data0;
            m_auiEncounter[1] = data1;
            m_auiEncounter[2] = data2;
            m_auiEncounter[3] = data3;
            m_auiEncounter[4] = data4;
            m_auiEncounter[5] = data5;

            for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                if (m_auiEncounter[i] == IN_PROGRESS)
                    m_auiEncounter[i] = NOT_STARTED;

        } else OUT_LOAD_INST_DATA_FAIL;
    }
};

InstanceData* GetInstanceData_instance_ruins_of_ahn_qiraj(Map* pMap)
{
    return new instance_ruins_of_ahn_qiraj(pMap);
}

void AddSC_instance_ruins_of_ahnqiraj()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_ruins_of_ahnqiraj";
    newscript->GetInstanceData = &GetInstanceData_instance_ruins_of_ahn_qiraj;
    newscript->RegisterSelf();
}
