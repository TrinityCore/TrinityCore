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
SDName: instance_stratholme
SD%Complete: 100
SDComment: 
SDCategory: Stratholme
EndScriptData */

#include "precompiled.h"
#include "def_stratholme.h"

struct TRINITY_DLL_DECL instance_stratholme : public ScriptedInstance
{
    instance_stratholme(Map *Map) : ScriptedInstance(Map) {Initialize();};

    bool IsSilverHandDead[5];

    void SetData(uint32 type, uint32 data)
    {
        switch(type)
        {
            case TYPE_SH_AELMAR:
                IsSilverHandDead[0] = (data) ? true : false;
                break;
            case TYPE_SH_CATHELA:
                IsSilverHandDead[1] = (data) ? true : false;
                break;
            case TYPE_SH_GREGOR:
                IsSilverHandDead[2] = (data) ? true : false;
                break;
            case TYPE_SH_NEMAS:
                IsSilverHandDead[3] = (data) ? true : false;
                break;
            case TYPE_SH_VICAR:
                IsSilverHandDead[4] = (data) ? true : false;
                break;
        }
    }

    uint32 GetData(uint32 type)
    {
        if(type == TYPE_SH_QUEST)
            if(IsSilverHandDead[0] && IsSilverHandDead[1] && IsSilverHandDead[2] && IsSilverHandDead[3] && IsSilverHandDead[4])
                return true;

        return false;
    }
};

InstanceData* GetInstanceData_instance_stratholme(Map* map)
{
    return new instance_stratholme(map);
}

void AddSC_instance_stratholme()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_stratholme";
    newscript->GetInstanceData = GetInstanceData_instance_stratholme;
    m_scripts[nrscripts++] = newscript;
}
