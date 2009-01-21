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
SDName: Instance_Blood_Furnace
SD%Complete: 85
SDComment: 
SDCategory: Hellfire Citadel, Blood Furnace
EndScriptData */

#include "precompiled.h"
#include "def_blood_furnace.h"

#define ENTRY_DOOR1                 181823
#define ENTRY_DOOR2                 181766

struct TRINITY_DLL_DECL instance_blood_furnace : public ScriptedInstance
{
    instance_blood_furnace(Map *map) : ScriptedInstance(map) {Initialize();};


    uint64 Door1GUID;
    uint64 Door2GUID;


    void Initialize()
    {
        Door1GUID = 0;
        Door2GUID = 0;
    }

    void OnObjectCreate(GameObject *go)
    {
        switch(go->GetEntry())
        {
            case ENTRY_DOOR1: Door1GUID = go->GetGUID(); break;
            case ENTRY_DOOR2: Door2GUID = go->GetGUID(); break;
        }
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
	 	 
        debug_log("SD2: Instance Blood Furnace: GetPlayerInMap, but PlayerList is empty!");
        return NULL;
    }
	 	 
    void HandleGameObject(uint64 guid, uint32 state)
    {
        Player *player = GetPlayerInMap();
	 
        if (!player || !guid)
        {
            debug_log("SD2: Blood Furnace: HandleGameObject fail");
            return;
        }
	 	 
        if (GameObject *go = GameObject::GetGameObject(*player,guid))
            go->SetGoState(state);
    }

    void SetData(uint32 type, uint32 data)
    {
        switch(type)
        {
            case DATA_KELIDANEVENT:
                if( data == DONE )
                {
                    HandleGameObject(Door1GUID,0);
                    HandleGameObject(Door2GUID,0);
                }
                break;
        }
    }
};

InstanceData* GetInstanceData_instance_blood_furnace(Map* map)
{
    return new instance_blood_furnace(map);
}

void AddSC_instance_blood_furnace()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_blood_furnace";
    newscript->GetInstanceData = &GetInstanceData_instance_blood_furnace;
    newscript->RegisterSelf();
}