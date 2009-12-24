/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Instance_Shadowfang_Keep
SD%Complete: 90
SDComment:
SDCategory: Shadowfang Keep
EndScriptData */

#include "precompiled.h"
#include "shadowfang_keep.h"

#define MAX_ENCOUNTER              4

enum eEnums
{
    SAY_BOSS_DIE_AD         = -1033007,
    SAY_BOSS_DIE_AS         = -1033008,

    NPC_ASH                 = 3850,
    NPC_ADA                 = 3849,

    GO_COURTYARD_DOOR       = 18895,                        //door to open when talking to NPC's
    GO_SORCERER_DOOR        = 18972,                        //door to open when Fenrus the Devourer
    GO_ARUGAL_DOOR          = 18971                         //door to open when Wolf Master Nandos
};

struct TRINITY_DLL_DECL instance_shadowfang_keep : public ScriptedInstance
{
    instance_shadowfang_keep(Map* pMap) : ScriptedInstance(pMap) {Initialize();};

    uint32 m_auiEncounter[MAX_ENCOUNTER];
    std::string str_data;

    uint64 uiAshGUID;
    uint64 uiAdaGUID;

    uint64 DoorCourtyardGUID;
    uint64 DoorSorcererGUID;
    uint64 DoorArugalGUID;

    void Initialize()
    {
        memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

        uiAshGUID = 0;
        uiAdaGUID = 0;

        DoorCourtyardGUID = 0;
        DoorSorcererGUID = 0;
        DoorArugalGUID = 0;
    }

    void OnCreatureCreate(Creature* pCreature, bool add)
    {
        switch(pCreature->GetEntry())
        {
            case NPC_ASH: uiAshGUID = pCreature->GetGUID(); break;
            case NPC_ADA: uiAdaGUID = pCreature->GetGUID(); break;
        }
    }

    void OnGameObjectCreate(GameObject* pGo, bool add)
    {
        switch(pGo->GetEntry())
        {
            case GO_COURTYARD_DOOR:
                DoorCourtyardGUID = pGo->GetGUID();
                if (m_auiEncounter[0] == DONE)
                    HandleGameObject(NULL, true, pGo);
                break;
            case GO_SORCERER_DOOR:
                DoorSorcererGUID = pGo->GetGUID();
                if (m_auiEncounter[2] == DONE)
                    HandleGameObject(NULL, true, pGo);
                break;
            case GO_ARUGAL_DOOR:
                DoorArugalGUID = pGo->GetGUID();
                if (m_auiEncounter[3] == DONE)
                    HandleGameObject(NULL, true, pGo);
                break;
        }
    }

    void DoSpeech()
    {
        Creature* pAda = instance->GetCreature(uiAdaGUID);
        Creature* pAsh = instance->GetCreature(uiAshGUID);

        if (pAda && pAda->isAlive() && pAsh && pAsh->isAlive())
        {
            DoScriptText(SAY_BOSS_DIE_AD,pAda);
            DoScriptText(SAY_BOSS_DIE_AS,pAsh);
        }
    }

    void SetData(uint32 type, uint32 data)
    {
        switch(type)
        {
            case TYPE_FREE_NPC:
                if (data == DONE)
                    DoUseDoorOrButton(DoorCourtyardGUID);
                m_auiEncounter[0] = data;
                break;
            case TYPE_RETHILGORE:
                if (data == DONE)
                    DoSpeech();
                m_auiEncounter[1] = data;
                break;
            case TYPE_FENRUS:
                if (data == DONE)
                    DoUseDoorOrButton(DoorSorcererGUID);
                m_auiEncounter[2] = data;
                break;
            case TYPE_NANDOS:
                if (data == DONE)
                    DoUseDoorOrButton(DoorArugalGUID);
                m_auiEncounter[3] = data;
                break;
        }

        if (data == DONE)
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;
            saveStream << m_auiEncounter[0] << " " << m_auiEncounter[1] << " " << m_auiEncounter[2] << " " << m_auiEncounter[3];

            str_data = saveStream.str();

            SaveToDB();
            OUT_SAVE_INST_DATA_COMPLETE;
        }
    }

    uint32 GetData(uint32 type)
    {
        switch(type)
        {
            case TYPE_FREE_NPC:
                return m_auiEncounter[0];
            case TYPE_RETHILGORE:
                return m_auiEncounter[1];
            case TYPE_FENRUS:
                return m_auiEncounter[2];
            case TYPE_NANDOS:
                return m_auiEncounter[3];
        }
        return 0;
    }

    std::string GetSaveData()
    {
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

        std::istringstream loadStream(in);
        loadStream >> m_auiEncounter[0] >> m_auiEncounter[1] >> m_auiEncounter[2] >> m_auiEncounter[3];

        for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
        {
            if (m_auiEncounter[i] == IN_PROGRESS)
                m_auiEncounter[i] = NOT_STARTED;
        }

        OUT_LOAD_INST_DATA_COMPLETE;
    }
};

InstanceData* GetInstanceData_instance_shadowfang_keep(Map* pMap)
{
    return new instance_shadowfang_keep(pMap);
}

void AddSC_instance_shadowfang_keep()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_shadowfang_keep";
    newscript->GetInstanceData = &GetInstanceData_instance_shadowfang_keep;
    newscript->RegisterSelf();
}

