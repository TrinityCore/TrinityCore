/*
 * Copyright (C) 2009 Trinity <http://www.trinitycore.org/>
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

/* ScriptData
SDName: Instance_Azjol_Nerub
SD%Complete: 0
SDComment: Placeholder
SDCategory: Azjol Nerub
EndScriptData */

#include "ScriptedPch.h"
#include "azjol_nerub.h"

#define MAX_ENCOUNTER     3

/* Azjol Nerub encounters:
0 - Krik'thir the Gatewatcher
1 - Hadronox
2 - Anub'arak
*/

struct instance_azjol_nerub : public ScriptedInstance
{
    instance_azjol_nerub(Map* pMap) : ScriptedInstance(pMap) {Initialize();};

    uint64 m_uiKrikthir;
    uint64 m_uiHadronox;
    uint64 m_uiAnubarak;
    uint64 m_uiWatcherGashra;
    uint64 m_uiWatcherSilthik;
    uint64 m_uiWatcherNarjil;

    uint64 m_uiKrikthirDoor;

    uint32 m_auiEncounter[MAX_ENCOUNTER];

   void Initialize()
   {
        memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

        m_uiKrikthir = 0;
        m_uiHadronox = 0;
        m_uiAnubarak = 0;
        m_uiWatcherGashra = 0;
        m_uiWatcherSilthik = 0;
        m_uiWatcherNarjil = 0;
        m_uiKrikthirDoor = 0;
    }

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
            case 28684:    m_uiKrikthir = pCreature->GetGUID();        break;
            case 28921:    m_uiHadronox = pCreature->GetGUID();        break;
            case 29120:    m_uiAnubarak = pCreature->GetGUID();        break;
            case 28730:    m_uiWatcherGashra = pCreature->GetGUID();   break;
            case 28731:    m_uiWatcherSilthik = pCreature->GetGUID();  break;
            case 28729:    m_uiWatcherNarjil = pCreature->GetGUID();   break;
        }
    }

    void OnGameObjectCreate(GameObject* pGo, bool add)
    {
        switch (pGo->GetEntry())
        {
            case 192395:
                m_uiKrikthirDoor = pGo->GetGUID();
                if (m_auiEncounter[0] == DONE)
                    HandleGameObject(NULL,true,pGo);
                break;
        }
    }

    uint64 GetData64(uint32 identifier)
    {
        switch(identifier)
        {
            case DATA_KRIKTHIR_THE_GATEWATCHER:     return m_uiKrikthir;
            case DATA_HADRONOX:                     return m_uiHadronox;
            case DATA_ANUBARAK:                     return m_uiAnubarak;
            case DATA_WATCHER_GASHRA:               return m_uiWatcherGashra;
            case DATA_WATCHER_SILTHIK:              return m_uiWatcherSilthik;
            case DATA_WATCHER_NARJIL:               return m_uiWatcherNarjil;
        }

        return 0;
    }

    void SetData(uint32 type, uint32 data)
    {
        switch(type)
        {
        case DATA_KRIKTHIR_THE_GATEWATCHER_EVENT:
            m_auiEncounter[0] = data;
            if (data == DONE)
                HandleGameObject(m_uiKrikthirDoor,true);
            break;
        case DATA_HADRONOX_EVENT:
            m_auiEncounter[1] = data; break;
        case DATA_ANUBARAK_EVENT:
            m_auiEncounter[2] = data; break;
        }

        if (data == DONE)
        {
            SaveToDB();
        }
    }

    uint32 GetData(uint32 type)
    {
        switch(type)
        {
            case DATA_KRIKTHIR_THE_GATEWATCHER_EVENT:   return m_auiEncounter[0];
            case DATA_HADRONOX_EVENT:                   return m_auiEncounter[1];
            case DATA_ANUBARAK_EVENT:                   return m_auiEncounter[2];
        }

        return 0;
    }

   std::string GetSaveData()
    {
        OUT_SAVE_INST_DATA;

        std::string str_data;

        std::ostringstream saveStream;
        saveStream << "A N " << m_auiEncounter[0] << " " << m_auiEncounter[1] << " "
            << m_auiEncounter[2];

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
        uint16 data0,data1,data2;

        std::istringstream loadStream(in);
        loadStream >> dataHead1 >> dataHead2 >> data0 >> data1 >> data2;

        if (dataHead1 == 'A' && dataHead2 == 'N')
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

InstanceData* GetInstanceData_instance_azjol_nerub(Map* pMap)
{
   return new instance_azjol_nerub(pMap);
}

void AddSC_instance_azjol_nerub()
{
   Script *newscript;
   newscript = new Script;
   newscript->Name = "instance_azjol_nerub";
   newscript->GetInstanceData = &GetInstanceData_instance_azjol_nerub;
   newscript->RegisterSelf();
}
