/*
 * Copyright (C) 2010 Trinity <http://www.trinitycore.org/>
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
#include "gnomeregan.h"

#define    MAX_ENCOUNTER  1

struct instance_gnomeregan : public ScriptedInstance
{
    instance_gnomeregan(Map* pMap) : ScriptedInstance(pMap)
    {
        Initialize();
    };

    uint32 m_auiEncounter[MAX_ENCOUNTER];

    uint64 uiCaveInLeftGUID;
    uint64 uiCaveInRightGUID;

    uint64 uiBastmasterEmiShortfuseGUID;

    void Initialize()
    {
        memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

        uiCaveInLeftGUID                = 0;
        uiCaveInRightGUID               = 0;

        uiBastmasterEmiShortfuseGUID    = 0;
    }

    void Load(const char* in)
    {
        if (!in)
        {
            OUT_LOAD_INST_DATA_FAIL;
            return;
        }

        OUT_LOAD_INST_DATA(in);

        std::istringstream loadStream(in);
        loadStream >> m_auiEncounter[0];

        for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
        {
            if (m_auiEncounter[i] == IN_PROGRESS)
                m_auiEncounter[i] = NOT_STARTED;
        }

        OUT_LOAD_INST_DATA_COMPLETE;
    }

    void OnCreatureCreate(Creature* pCreature, bool bAdd)
    {
        switch(pCreature->GetEntry())
        {
            case NPC_BLASTMASTER_EMI_SHORTFUSE: uiBastmasterEmiShortfuseGUID = pCreature->GetGUID(); break;
        }
    }

    void OnGameObjectCreate(GameObject* pGo, bool bAdd)
    {
        switch(pGo->GetEntry())
        {
            case GO_CAVE_IN_LEFT:
                uiCaveInLeftGUID = pGo->GetGUID();
                if (m_auiEncounter[0] == DONE || m_auiEncounter[0] == NOT_STARTED)
                    HandleGameObject(NULL,false,pGo);
                break;
            case GO_CAVE_IN_RIGHT:
                uiCaveInRightGUID = pGo->GetGUID();
                if (m_auiEncounter[0] == DONE || m_auiEncounter[0] == NOT_STARTED)
                    HandleGameObject(NULL,false,pGo);
                break;
        }
    }

    void SetData(uint32 uiType, uint32 uiData)
    {
        switch(uiType)
        {
            case TYPE_EVENT:
                m_auiEncounter[0] = uiData; break;
                if (uiData == DONE)
                    SaveToDB();
                break;
        }
    }

    uint32 GetData(uint32 uiType, uint32 uiData)
    {
        switch(uiType)
        {
            case TYPE_EVENT:    return m_auiEncounter[0];
        }
    }

    uint64 GetData64(uint32 uiType)
    {
        switch(uiType)
        {
            case DATA_GO_CAVE_IN_LEFT:              return uiCaveInLeftGUID;
            case DATA_GO_CAVE_IN_RIGHT:             return uiCaveInRightGUID;
            case DATA_NPC_BASTMASTER_EMI_SHORTFUSE: return uiBastmasterEmiShortfuseGUID;
        }

        return 0;
    }
};

InstanceData* GetInstanceData_instance_gnomeregan(Map* pMap)
{
    return new instance_gnomeregan(pMap);
}

void AddSC_instance_gnomeregan()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "instance_gnomeregan";
    newscript->GetInstanceData = &GetInstanceData_instance_gnomeregan;
    newscript->RegisterSelf();
}
