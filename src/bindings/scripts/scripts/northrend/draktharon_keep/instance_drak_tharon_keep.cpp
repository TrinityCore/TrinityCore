/*
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
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

#include "precompiled.h"
#include "drak_tharon_keep.h"

#define MAX_ENCOUNTER     4
/* Drak'Tharon Keep encounters:
0 - Trollgore
1 - Novos
2 - King Dred
3 - Tharon Ja
*/

enum Creatures
{
    NPC_TROLLGORE                                          = 26630,
    NPC_NOVOS                                              = 26631,
    NPC_KING_DRED                                          = 27483,
    NPC_THARON_JA                                          = 26632
};
enum GameObjects
{
    GO_NOVOS_CRYSTAL_1                                     = 189299,
    GO_NOVOS_CRYSTAL_2                                     = 189300,
    GO_NOVOS_CRYSTAL_3                                     = 189301,
    GO_NOVOS_CRYSTAL_4                                     = 189302
};

struct TRINITY_DLL_DECL instance_drak_tharon : public ScriptedInstance
{
    instance_drak_tharon(Map* pMap) : ScriptedInstance(pMap) {Initialize();};

    uint64 uiTrollgore;
    uint64 uiNovos;
    uint64 uiDred;
    uint64 uiTharonJa;

    uint64 uiNovosCrystal1;
    uint64 uiNovosCrystal2;
    uint64 uiNovosCrystal3;
    uint64 uiNovosCrystal4;

    uint8 m_auiEncounter[MAX_ENCOUNTER];

    std::string str_data;

    void Initialize()
    {
        uiTrollgore = 0;
        uiNovos = 0;
        uiDred = 0;
        uiTharonJa = 0;
        uiNovosCrystal1 = 0;
        uiNovosCrystal2 = 0;
        uiNovosCrystal3 = 0;
        uiNovosCrystal4 = 0;
    }

    bool IsEncounterInProgress() const
    {
        for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
            if (m_auiEncounter[i] == IN_PROGRESS) return true;

        return false;
    }

    void OnGameObjectCreate(GameObject* pGo, bool add)
    {
        switch(pGo->GetEntry())
        {
            case GO_NOVOS_CRYSTAL_1:
                uiNovosCrystal1 = pGo->GetGUID();
                break;
            case GO_NOVOS_CRYSTAL_2:
                uiNovosCrystal2 = pGo->GetGUID();
                break;
            case GO_NOVOS_CRYSTAL_3:
                uiNovosCrystal3 = pGo->GetGUID();
                break;
            case GO_NOVOS_CRYSTAL_4:
                uiNovosCrystal4 = pGo->GetGUID();
                break;
        }
    }

    void OnCreatureCreate(Creature* pCreature, bool add)
    {
        switch(pCreature->GetEntry())
        {
            case NPC_TROLLGORE:
                uiTrollgore = pCreature->GetGUID();
                break;
            case NPC_NOVOS:
                uiNovos = pCreature->GetGUID();
                break;
            case NPC_KING_DRED:
                uiDred = pCreature->GetGUID();
                break;
            case NPC_THARON_JA:
                uiTharonJa = pCreature->GetGUID();
                break;
        }
    }

    uint64 GetData64(uint32 identifier)
    {
        switch(identifier)
        {
            case DATA_TROLLGORE:          return uiTrollgore;
            case DATA_NOVOS:              return uiNovos;
            case DATA_DRED:               return uiDred;
            case DATA_THARON_JA:          return uiTharonJa;
            case DATA_NOVOS_CRYSTAL_1:    return uiNovosCrystal1;
            case DATA_NOVOS_CRYSTAL_2:    return uiNovosCrystal2;
            case DATA_NOVOS_CRYSTAL_3:    return uiNovosCrystal3;
            case DATA_NOVOS_CRYSTAL_4:    return uiNovosCrystal4;
        }

        return 0;
    }

    void SetData(uint32 type, uint32 data)
    {
        switch(type)
        {
            case DATA_TROLLGORE_EVENT:
                m_auiEncounter[0] = data;
                break;
            case DATA_NOVOS_EVENT:
                m_auiEncounter[1] = data;
                break;
            case DATA_DRED_EVENT:
                m_auiEncounter[2] = data;
                break;
            case DATA_THARON_JA_EVENT:
                m_auiEncounter[3] = data;
                break;
        }

        if (data == DONE)
        {
            SaveToDB();
        }
    }

    uint32 GetData(uint32 type)
    {
        switch (type)
        {
            case DATA_TROLLGORE_EVENT:    return m_auiEncounter[0];
            case DATA_NOVOS_EVENT:        return m_auiEncounter[1];
            case DATA_DRED_EVENT:         return m_auiEncounter[2];
            case DATA_THARON_JA_EVENT:    return m_auiEncounter[3];
        }
        return 0;
    }

    std::string GetSaveData()
    {
        OUT_SAVE_INST_DATA;

        std::string str_data;

        std::ostringstream saveStream;
        saveStream << "D K " << m_auiEncounter[0] << " " << m_auiEncounter[1] << " "
            << m_auiEncounter[2] << " " << m_auiEncounter[3];

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
        uint16 data0,data1,data2,data3;

        std::istringstream loadStream(in);
        loadStream >> dataHead1 >> dataHead2 >> data0 >> data1 >> data2 >> data3;

        if (dataHead1 == 'D' && dataHead2 == 'K')
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

InstanceData* GetInstanceData_instance_drak_tharon(Map* pMap)
{
    return new instance_drak_tharon(pMap);
}

void AddSC_instance_drak_tharon()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_drak_tharon";
    newscript->GetInstanceData = &GetInstanceData_instance_drak_tharon;
    newscript->RegisterSelf();
}
