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
SDName: Instance_Shattered_Halls
SD%Complete: 50
SDComment: currently missing info about door. instance not complete
SDCategory: Hellfire Citadel, Shattered Halls
EndScriptData */

#include "precompiled.h"
#include "def_shattered_halls.h"

#define ENCOUNTERS  2

#define DOOR_NETHEKURSE     1

struct TRINITY_DLL_DECL instance_shattered_halls : public ScriptedInstance
{
    instance_shattered_halls(Map *map) : ScriptedInstance(map) {Initialize();};

    uint32 Encounter[ENCOUNTERS];
    uint64 nethekurseGUID;
    uint64 nethekurseDoorGUID;

    void Initialize()
    {
        nethekurseGUID = 0;
        nethekurseDoorGUID = 0;

        for(uint8 i = 0; i < ENCOUNTERS; i++)
            Encounter[i] = NOT_STARTED;
    }

    void OnObjectCreate(GameObject *go)
    {
        switch( go->GetEntry() )
        {
            case DOOR_NETHEKURSE: nethekurseDoorGUID = go->GetGUID(); break;
        }
    }

    void OnCreatureCreate(Creature *creature, uint32 creature_entry)
    {
        switch( creature_entry )
        {
            case 16807: nethekurseGUID = creature->GetGUID(); break;
        }
    }

    void SetData(uint32 type, uint32 data)
    {
        switch( type )
        {
            case TYPE_NETHEKURSE:
                Encounter[0] = data;
                break;
            case TYPE_OMROGG:
                Encounter[1] = data;
                break;
        }
    }

    uint32 GetData(uint32 type)
    {
        switch( type )
        {
            case TYPE_NETHEKURSE:
                return Encounter[0];
            case TYPE_OMROGG:
                return Encounter[1];
        }
        return 0;
    }

    uint64 GetData64(uint32 data)
    {
        switch(data)
        {
            case DATA_NETHEKURSE:
                return nethekurseGUID;
            case DATA_NETHEKURSE_DOOR:
                return nethekurseDoorGUID;
        }
        return 0;
    }
};

InstanceData* GetInstanceData_instance_shattered_halls(Map* map)
{
    return new instance_shattered_halls(map);
}

void AddSC_instance_shattered_halls()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_shattered_halls";
    newscript->GetInstanceData = &GetInstanceData_instance_shattered_halls;
    newscript->RegisterSelf();
}

