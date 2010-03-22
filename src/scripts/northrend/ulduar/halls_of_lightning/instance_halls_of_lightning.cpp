/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/* ScriptData
SDName: Instance_Halls_of_Lightning
SD%Complete: 90%
SDComment: All ready.
SDCategory: Halls of Lightning
EndScriptData */

#include "ScriptedPch.h"
#include "halls_of_lightning.h"

/* Halls of Lightning encounters:
0 - General Bjarngrim
1 - Volkhan
2 - Ionar
3 - Loken
*/

struct instance_halls_of_lightning : public ScriptedInstance
{
    instance_halls_of_lightning(Map* pMap) : ScriptedInstance(pMap) {Initialize();};

    uint32 m_auiEncounter[MAX_ENCOUNTER];

    uint64 m_uiGeneralBjarngrimGUID;
    uint64 m_uiIonarGUID;
    uint64 m_uiLokenGUID;
    uint64 m_uiVolkhanGUID;

    uint64 m_uiBjarngrimDoorGUID;
    uint64 m_uiVolkhanDoorGUID;
    uint64 m_uiIonarDoorGUID;
    uint64 m_uiLokenDoorGUID;
    uint64 m_uiLokenGlobeGUID;

    void Initialize()
    {
        memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

        m_uiGeneralBjarngrimGUID = 0;
        m_uiVolkhanGUID          = 0;
        m_uiIonarGUID            = 0;
        m_uiLokenGUID            = 0;

        m_uiBjarngrimDoorGUID    = 0;
        m_uiVolkhanDoorGUID      = 0;
        m_uiIonarDoorGUID        = 0;
        m_uiLokenDoorGUID        = 0;
        m_uiLokenGlobeGUID       = 0;
    }

    void OnCreatureCreate(Creature* pCreature, bool add)
    {
        switch(pCreature->GetEntry())
        {
            case NPC_BJARNGRIM:
                m_uiGeneralBjarngrimGUID = pCreature->GetGUID();
                break;
            case NPC_VOLKHAN:
                m_uiVolkhanGUID = pCreature->GetGUID();
                break;
            case NPC_IONAR:
                m_uiIonarGUID = pCreature->GetGUID();
                break;
            case NPC_LOKEN:
                m_uiLokenGUID = pCreature->GetGUID();
                break;
        }
    }

    void OnGameObjectCreate(GameObject* pGo, bool add)
    {
        switch(pGo->GetEntry())
        {
            case GO_BJARNGRIM_DOOR:
                m_uiBjarngrimDoorGUID = pGo->GetGUID();
                if (m_auiEncounter[0] == DONE)
                    pGo->SetGoState(GO_STATE_ACTIVE);
                else
                    pGo->SetGoState(GO_STATE_READY);
                break;
            case GO_VOLKHAN_DOOR:
                m_uiVolkhanDoorGUID = pGo->GetGUID();
                if (m_auiEncounter[1] == DONE)
                    pGo->SetGoState(GO_STATE_ACTIVE);
                else
                    pGo->SetGoState(GO_STATE_READY);
                break;
            case GO_IONAR_DOOR:
                m_uiIonarDoorGUID = pGo->GetGUID();
                if (m_auiEncounter[2] == DONE)
                    pGo->SetGoState(GO_STATE_ACTIVE);
                else
                    pGo->SetGoState(GO_STATE_READY);
                break;
            case GO_LOKEN_DOOR:
                m_uiLokenDoorGUID = pGo->GetGUID();
                if (m_auiEncounter[3] == DONE)
                    pGo->SetGoState(GO_STATE_ACTIVE);
                else
                    pGo->SetGoState(GO_STATE_READY);
                break;
            case GO_LOKEN_THRONE:
                m_uiLokenGlobeGUID = pGo->GetGUID();
                break;
        }
    }

    void SetData(uint32 uiType, uint32 uiData)
    {
        switch(uiType)
        {
            case TYPE_BJARNGRIM:
                if (uiData == DONE)
                    DoUseDoorOrButton(m_uiBjarngrimDoorGUID);
                m_auiEncounter[0] = uiData;
                break;
            case TYPE_VOLKHAN:
                if (uiData == DONE)
                    DoUseDoorOrButton(m_uiVolkhanDoorGUID);
                m_auiEncounter[1] = uiData;
                break;
            case TYPE_IONAR:
                if (uiData == DONE)
                    DoUseDoorOrButton(m_uiIonarDoorGUID);
                m_auiEncounter[2] = uiData;
                break;
            case TYPE_LOKEN:
                if (uiData == DONE)
                {
                    DoUseDoorOrButton(m_uiLokenDoorGUID);

                    //Appears to be type 5 GO with animation. Need to figure out how this work, code below only placeholder
                    if (GameObject* pGlobe = instance->GetGameObject(m_uiLokenGlobeGUID))
                        pGlobe->SetGoState(GO_STATE_ACTIVE);
                }
                m_auiEncounter[3] = uiData;
                break;
        }

        if (uiData == DONE)
            SaveToDB();
    }

    uint32 GetData(uint32 uiType)
    {
        switch(uiType)
        {
            case TYPE_BJARNGRIM:
                return m_auiEncounter[0];
            case TYPE_VOLKHAN:
                return m_auiEncounter[1];
            case TYPE_IONAR:
                return m_auiEncounter[2];
            case TYPE_LOKEN:
                return m_auiEncounter[3];
        }
        return 0;
    }

    uint64 GetData64(uint32 uiData)
    {
        switch(uiData)
        {
            case DATA_BJARNGRIM:
                return m_uiGeneralBjarngrimGUID;
            case DATA_VOLKHAN:
                return m_uiVolkhanGUID;
            case DATA_IONAR:
                return m_uiIonarGUID;
            case DATA_LOKEN:
                return m_uiLokenGUID;
        }
        return 0;
    }

    std::string GetSaveData()
    {
        OUT_SAVE_INST_DATA;

        std::ostringstream saveStream;
        saveStream << "H L " << m_auiEncounter[0] << " " << m_auiEncounter[1] << " "
        << m_auiEncounter[2] << " " << m_auiEncounter[3];

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
        uint16 data0, data1, data2, data3;

        std::istringstream loadStream(in);
        loadStream >> dataHead1 >> dataHead2 >> data0 >> data1 >> data2 >> data3;

        if (dataHead1 == 'H' && dataHead2 == 'L')
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

InstanceData* GetInstanceData_instance_halls_of_lightning(Map* pMap)
{
    return new instance_halls_of_lightning(pMap);
}

void AddSC_instance_halls_of_lightning()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_halls_of_lightning";
    newscript->GetInstanceData = &GetInstanceData_instance_halls_of_lightning;
    newscript->RegisterSelf();
}
