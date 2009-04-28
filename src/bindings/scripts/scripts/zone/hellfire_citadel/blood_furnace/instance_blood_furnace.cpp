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

#define ENTRY_SEWER1                 181823
#define ENTRY_SEWER2                 181766

struct TRINITY_DLL_DECL instance_blood_furnace : public ScriptedInstance
{
    instance_blood_furnace(Map *map) : ScriptedInstance(map) {Initialize();};


    uint64 Sewer1GUID;
    uint64 Sewer2GUID;


    void Initialize()
    {
        Sewer1GUID = 0;
        Sewer2GUID = 0;
    }

    void OnObjectCreate(GameObject *go)
    {
        switch(go->GetEntry())
        {
            case ENTRY_SEWER1: Sewer1GUID = go->GetGUID(); break;
            case ENTRY_SEWER2: Sewer2GUID = go->GetGUID(); break;
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

        debug_log("TSCR: Instance Blood Furnace: GetPlayerInMap, but PlayerList is empty!");
        return NULL;
    }

    void SetData(uint32 type, uint32 data)
    {
        switch(type)
        {
            case DATA_KELIDANEVENT:
                if( data == DONE )
                {
                    HandleGameObject(Sewer1GUID, true);
                    HandleGameObject(Sewer2GUID, true);
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

