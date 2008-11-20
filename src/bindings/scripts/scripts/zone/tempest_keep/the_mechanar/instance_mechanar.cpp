/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Instance_Mechanar
SD%Complete: 100
SDComment: 
SDCategory: Mechanar
EndScriptData */

#include "precompiled.h"
#include "def_mechanar.h"

struct TRINITY_DLL_DECL instance_mechanar : public ScriptedInstance
{
    instance_mechanar(Map *Map) : ScriptedInstance(Map) {Initialize();};

    
    bool IsBossDied[1];

    void OnCreatureCreate (Creature *creature, uint32 creature_entry)
    {
    } 

    void Initialize()
    {
        IsBossDied[0] = false;
    }

    bool IsEncounterInProgress() const 
    {
        //not active
        return false;
    }

    uint32 GetData(uint32 type)
    {
        switch(type)
        {
            case DATA_SEPETHREAISDEAD:
                if(IsBossDied[0])
                    return 1;
                break;
        }

        return 0;
    }

    uint64 GetData64 (uint32 identifier)
    {
        return 0;
    }

    void SetData(uint32 type, uint32 data)
    {
        switch(type)
        {
            case DATA_SEPETHREA_DEATH:
                IsBossDied[0] = true;
                break;
        }
    }
};

InstanceData* GetInstanceData_instance_mechanar(Map* map)
{
    return new instance_mechanar(map);
}

void AddSC_instance_mechanar()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_mechanar";
    newscript->GetInstanceData = GetInstanceData_instance_mechanar;
    newscript->RegisterSelf();
}
