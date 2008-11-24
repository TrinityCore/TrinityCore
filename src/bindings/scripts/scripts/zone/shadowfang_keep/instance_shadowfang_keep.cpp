/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SD%Complete: 75
SDComment: TODO: check what other parts would require additional code (ex: make sure door are in open state if boss dead)
SDCategory: Shadowfang Keep
EndScriptData */

#include "precompiled.h"
#include "def_shadowfang_keep.h"

#define ENCOUNTERS              4

struct TRINITY_DLL_DECL instance_shadowfang_keep : public ScriptedInstance
{
    instance_shadowfang_keep(Map *Map) : ScriptedInstance(Map) {Initialize();};

    uint32 Encounter[ENCOUNTERS];

    uint64 DoorCourtyard;
    uint64 DoorSorcerer;
    uint64 DoorArugal;

    void Initialize()
    {
        DoorCourtyard  = 0;
        DoorSorcerer   = 0;
        DoorArugal     = 0;

		 for(uint8 i=0; i < ENCOUNTERS; ++i)
			 Encounter[i] = NOT_STARTED;
    }

    void OnObjectCreate(GameObject *go)
    {
        switch(go->GetEntry())
        {
		case 18895: DoorCourtyard = go->GetGUID(); break;
		case 18972: DoorSorcerer = go->GetGUID(); break;
		case 18971: DoorArugal = go->GetGUID(); break;
        }
    }

	void OpenDoor(uint64 DoorGUID, bool open)
    {
        if(GameObject *Door = instance->GetGameObjectInMap(DoorGUID))
            Door->SetUInt32Value(GAMEOBJECT_STATE, open ? 0 : 1);
    }

    void SetData(uint32 type, uint32 data)
    {
        switch(type)
        {
            case TYPE_FREE_NPC:
                if(data == DONE)                
                    OpenDoor(DoorCourtyard, true);                                
                Encounter[0] = data;
                break;
            case TYPE_RETHILGORE:
                Encounter[1] = data;
                break;
            case TYPE_FENRUS:
                if(data == DONE)
					OpenDoor(DoorSorcerer, true);                                      
                Encounter[2] = data;
                break;
            case TYPE_NANDOS:
                if(data == DONE)                
                    OpenDoor(DoorArugal, true);             
                Encounter[3] = data;
                break;
        }
    }

    uint32 GetData(uint32 type)
    {
        switch(type)
        {
            case TYPE_FREE_NPC:
                return Encounter[0];
            case TYPE_RETHILGORE:
                return Encounter[1];
            case TYPE_FENRUS:
                return Encounter[2];
            case TYPE_NANDOS:
                return Encounter[3];
        }
        return 0;
    }

};

InstanceData* GetInstanceData_instance_shadowfang_keep(Map* map)
{
    return new instance_shadowfang_keep(map);
}

void AddSC_instance_shadowfang_keep()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_shadowfang_keep";
    newscript->GetInstanceData = GetInstanceData_instance_shadowfang_keep;
    newscript->RegisterSelf();
}
