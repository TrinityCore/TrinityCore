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
SDName: Instance_Utgarde_Keep
SD%Complete: 90
SDComment: Instance Data Scripts and functions to acquire mobs and set encounter status for use in various Utgarde Keep Scripts
SDCategory: Utgarde Keep
EndScriptData */

#include "precompiled.h"
#include "def_utgarde_keep.h"

#define MAX_ENCOUNTER     3

#define ENTRY_BELLOW_1          186688
#define ENTRY_BELLOW_2          186689
#define ENTRY_BELLOW_3          186690

#define ENTRY_FORGEFIRE_1       186692
#define ENTRY_FORGEFIRE_2       186693
#define ENTRY_FORGEFIRE_3       186691

#define ENTRY_GLOWING_ANVIL_1   186609
#define ENTRY_GLOWING_ANVIL_2   186610
#define ENTRY_GLOWING_ANVIL_3   186611

/* Utgarde Keep encounters:
0 - Prince Keleseth
1 - Skarvald Dalronn
2 - Ingvar the Plunderer
*/

struct TRINITY_DLL_DECL instance_utgarde_keep : public ScriptedInstance
{
    instance_utgarde_keep(Map* pMap) : ScriptedInstance(pMap) {Initialize();};

    uint64 Keleseth;
    uint64 Skarvald;
    uint64 Dalronn;
    uint64 Ingvar;

    uint64 forge_bellow[3];
    uint64 forge_fire[3];
    uint64 forge_anvil[3];

    uint32 m_auiEncounter[MAX_ENCOUNTER];
    std::string str_data;

   void Initialize()
   {
        memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

        Keleseth = 0;
        Skarvald = 0;
        Dalronn =0;
        Ingvar =0;

        for(uint8 i= 0; i < 3; ++i)
        {
            forge_bellow[i] = 0;
            forge_fire[i] = 0;
            forge_anvil[i] = 0;
        }
    }

    bool IsEncounterInProgress() const
    {
        for(uint8 i = 0; i < MAX_ENCOUNTER; ++i)
            if (m_auiEncounter[i] == IN_PROGRESS) return true;

        return false;
    }

    Player* GetPlayerInMap()
    {
        Map::PlayerList const& players = instance->GetPlayers();

        if (!players.isEmpty())
        {
            for(Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
            {
                if (Player* plr = itr->getSource())
                return plr;
            }
        }

        debug_log("TSCR: Instance Utgarde Keep: GetPlayerInMap, but PlayerList is empty!");
        return NULL;
    }

    void OnCreatureCreate(Creature *creature, bool add)
    {
        switch(creature->GetEntry())
        {
            case 23953:    Keleseth = creature->GetGUID();             break;
            case 24201:    Dalronn = creature->GetGUID();              break;
            case 24200:    Skarvald = creature->GetGUID();             break;
            case 23954:    Ingvar = creature->GetGUID();               break;
        }
    }

    void OnGameObjectCreate(GameObject *go, bool add)
    {
        switch(go->GetEntry())
        {
        //door and object id
        case ENTRY_BELLOW_1: forge_bellow[0] = go->GetGUID(); break;
        case ENTRY_BELLOW_2: forge_bellow[1] = go->GetGUID(); break;
        case ENTRY_BELLOW_3: forge_bellow[2] = go->GetGUID(); break;
        case ENTRY_FORGEFIRE_1: forge_fire[0] = go->GetGUID(); break;
        case ENTRY_FORGEFIRE_2: forge_fire[1] = go->GetGUID(); break;
        case ENTRY_FORGEFIRE_3: forge_fire[2] = go->GetGUID(); break;
        case ENTRY_GLOWING_ANVIL_1: forge_anvil[0] = go->GetGUID(); break;
        case ENTRY_GLOWING_ANVIL_2: forge_anvil[1] = go->GetGUID(); break;
        case ENTRY_GLOWING_ANVIL_3: forge_anvil[2] = go->GetGUID(); break;
        }
    }

    uint64 GetData64(uint32 identifier)
    {
        switch(identifier)
        {
            case DATA_PRINCEKELESETH:         return Keleseth;
            case DATA_DALRONN:                return Dalronn;
            case DATA_SKARVALD:               return Skarvald;
            case DATA_INGVAR:                 return Ingvar;
        }

        return 0;
    }

    void SetData(uint32 type, uint32 data)
    {
        switch(type)
        {
        case DATA_PRINCEKELESETH_EVENT:
            if (data == DONE)
            {
                //HandleGameObject(doorname, 0);
            }
            m_auiEncounter[0] = data;
            break;
        case DATA_SKARVALD_DALRONN_EVENT:
            if (data == DONE)
            {
                //HandleGameObject(doorname, 0);
            }
            m_auiEncounter[1] = data;
            break;
        case DATA_INGVAR_EVENT:
            if (data == DONE)
            {
                //HandleGameObject(doorname, 0);
            }
            m_auiEncounter[2] = data;
            break;
        case EVENT_FORGE_1:
            if (data == NOT_STARTED)
            {
                HandleGameObject(forge_bellow[0],false);
                HandleGameObject(forge_fire[0],false);
                HandleGameObject(forge_anvil[0],false);
            }else
            {
                HandleGameObject(forge_bellow[0],true);
                HandleGameObject(forge_fire[0],true);
                HandleGameObject(forge_anvil[0],true);
            }
            break;
        case EVENT_FORGE_2:
            if (data == NOT_STARTED)
            {
                HandleGameObject(forge_bellow[1],false);
                HandleGameObject(forge_fire[1],false);
                HandleGameObject(forge_anvil[1],false);
            }else
            {
                HandleGameObject(forge_bellow[1],true);
                HandleGameObject(forge_fire[1],true);
                HandleGameObject(forge_anvil[1],true);
            }
            break;
        case EVENT_FORGE_3:
            if (data == NOT_STARTED)
            {
                HandleGameObject(forge_bellow[2],false);
                HandleGameObject(forge_fire[2],false);
                HandleGameObject(forge_anvil[2],false);
            }else
            {
                HandleGameObject(forge_bellow[2],true);
                HandleGameObject(forge_fire[2],true);
                HandleGameObject(forge_anvil[2],true);
            }
            break;
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
            case DATA_PRINCEKELESETH_EVENT:     return m_auiEncounter[0];
            case DATA_SKARVALD_DALRONN_EVENT:   return m_auiEncounter[1];
            case DATA_INGVAR_EVENT:             return m_auiEncounter[2];
        }

        return 0;
    }

    std::string GetSaveData()
    {
        OUT_SAVE_INST_DATA;

        std::ostringstream saveStream;
        saveStream << "U K " << m_auiEncounter[0] << " " << m_auiEncounter[1] << " "
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

        if (dataHead1 == 'U' && dataHead2 == 'K')
        {
            m_auiEncounter[0] = data0;
            m_auiEncounter[1] = data1;
            m_auiEncounter[2] = data2;

            for(uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                if (m_auiEncounter[i] == IN_PROGRESS)
                    m_auiEncounter[i] = NOT_STARTED;

        }else OUT_LOAD_INST_DATA_FAIL;

        OUT_LOAD_INST_DATA_COMPLETE;
    }
};

InstanceData* GetInstanceData_instance_utgarde_keep(Map* pMap)
{
   return new instance_utgarde_keep(pMap);
}

void AddSC_instance_utgarde_keep()
{
   Script *newscript;
   newscript = new Script;
   newscript->Name = "instance_utgarde_keep";
   newscript->GetInstanceData = &GetInstanceData_instance_utgarde_keep;
   newscript->RegisterSelf();
}
