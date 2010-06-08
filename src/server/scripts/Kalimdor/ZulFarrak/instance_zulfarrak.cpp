 /*
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"

#define NPC_GAHZRILLA 7273

struct instance_zulfarrak : public ScriptedInstance
{
    instance_zulfarrak(Map* pMap) : ScriptedInstance(pMap) {Initialize();}

    uint32 GahzRillaEncounter;

    void Initialize()
    {
        GahzRillaEncounter = NOT_STARTED;
    }

    void OnCreatureCreate(Creature* pCreature, bool /*add*/)
    {
        if (pCreature->GetEntry() == NPC_GAHZRILLA)
        {
            if (GahzRillaEncounter >= IN_PROGRESS)
                pCreature->DisappearAndDie();
            else
                GahzRillaEncounter = IN_PROGRESS;
        }
    }
};

InstanceData* GetInstanceData_instance_zulfarrak(Map* pMap)
{
    return new instance_zulfarrak(pMap);
}

void AddSC_instance_zulfarrak()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_zulfarrak";
    newscript->GetInstanceData = &GetInstanceData_instance_zulfarrak;
    newscript->RegisterSelf();
}
