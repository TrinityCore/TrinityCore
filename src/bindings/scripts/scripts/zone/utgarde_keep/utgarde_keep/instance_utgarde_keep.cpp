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

#define ENCOUNTERS     3

/* Utgarde Keep encounters:
0 - Prince Keleseth
1 - Skarvald Dalronn
2 - Ingvar the Plunderer
*/

struct TRINITY_DLL_DECL instance_utgarde_keep : public ScriptedInstance
{
    instance_utgarde_keep(Map *Map) : ScriptedInstance(Map) {Initialize();};

    uint64 Keleseth;
    uint64 Skarvald;
    uint64 Dalronn;
    uint64 Ingvar;

    uint32 Encounters[ENCOUNTERS];
    std::string str_data;

   void Initialize()
   {
        Keleseth = 0;
        Skarvald = 0;
        Dalronn =0;
        Ingvar =0;

        for(uint8 i = 0; i < ENCOUNTERS; ++i)
            Encounters[i] = NOT_STARTED;
    }

    bool IsEncounterInProgress() const
    {
        for(uint8 i = 0; i < ENCOUNTERS; ++i)
            if(Encounters[i] == IN_PROGRESS) return true;

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

    void HandleGameObject(uint64 guid, uint32 state)
    {
        Player *player = GetPlayerInMap();

        if (!player || !guid)
        {
            debug_log("TSCR: Utgarde Keep: HandleGameObject fail");
            return;
        }

        if (GameObject *go = GameObject::GetGameObject(*player,guid))
            go->SetGoState(state);
    }

    void OnCreatureCreate(Creature *creature, uint32 creature_entry)
    {
        switch(creature_entry)
        {
            case 23953:    Keleseth = creature->GetGUID();             break;
            case 24201:    Dalronn = creature->GetGUID();              break;
            case 24200:    Skarvald = creature->GetGUID();             break;
            case 23954:    Ingvar = creature->GetGUID();               break;
        }
    }

    void OnObjectCreate(GameObject* go)
    {
        //switch(go->GetEntry())
        //{
        //door and object id
        //}
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
            if(data == DONE)
            {
                //HandleGameObject(doorname, 0);
            }
            Encounters[0] = data;break;
        case DATA_SKARVALD_DALRONN_EVENT:
            if(data == DONE)
            {
                //HandleGameObject(doorname, 0);
            }
            Encounters[1] = data; break;
        case DATA_INGVAR_EVENT:
            if(data == DONE)
            {
                //HandleGameObject(doorname, 0);
            }
            Encounters[2] = data; break;
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
            case DATA_PRINCEKELESETH_EVENT:     return Encounters[0];
            case DATA_SKARVALD_DALRONN_EVENT:   return Encounters[1];
            case DATA_INGVAR_EVENT:             return Encounters[2];
        }

        return 0;
    }

   const char* Save()
    {
        OUT_SAVE_INST_DATA;

        std::ostringstream saveStream;
        saveStream << "U K " << Encounters[0] << " " << Encounters[1] << " "
            << Encounters[2];

        str_data = saveStream.str();

        OUT_SAVE_INST_DATA_COMPLETE;
        return str_data.c_str();
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

        if( dataHead1 == 'U' && dataHead2 == 'K')
        {
            Encounters[0] = data0;
            Encounters[1] = data1;
            Encounters[2] = data2;

            for(uint8 i = 0; i < ENCOUNTERS; ++i)
                if (Encounters[i] == IN_PROGRESS)
                    Encounters[i] = NOT_STARTED;

        }else OUT_LOAD_INST_DATA_FAIL;

        OUT_LOAD_INST_DATA_COMPLETE;
    }
};

InstanceData* GetInstanceData_instance_utgarde_keep(Map* map)
{
   return new instance_utgarde_keep(map);
}

void AddSC_instance_utgarde_keep()
{
   Script *newscript;
   newscript = new Script;
   newscript->Name = "instance_utgarde_keep";
   newscript->GetInstanceData = &GetInstanceData_instance_utgarde_keep;
   newscript->RegisterSelf();
}
