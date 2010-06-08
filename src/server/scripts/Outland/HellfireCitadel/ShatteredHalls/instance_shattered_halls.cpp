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

#include "ScriptPCH.h"
#include "shattered_halls.h"

#define MAX_ENCOUNTER  2

#define DOOR_NETHEKURSE     1

struct instance_shattered_halls : public ScriptedInstance
{
    instance_shattered_halls(Map* pMap) : ScriptedInstance(pMap) {Initialize();};

    uint32 m_auiEncounter[MAX_ENCOUNTER];
    uint64 nethekurseGUID;
    uint64 nethekurseDoorGUID;

    void Initialize()
    {
        memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

        nethekurseGUID = 0;
        nethekurseDoorGUID = 0;
    }

    void OnGameObjectCreate(GameObject* pGo, bool /*add*/)
    {
        switch(pGo->GetEntry())
        {
            case DOOR_NETHEKURSE: nethekurseDoorGUID = pGo->GetGUID(); break;
        }
    }

    void OnCreatureCreate(Creature* pCreature, bool /*add*/)
    {
        switch(pCreature->GetEntry())
        {
            case 16807: nethekurseGUID = pCreature->GetGUID(); break;
        }
    }

    void SetData(uint32 type, uint32 data)
    {
        switch(type)
        {
            case TYPE_NETHEKURSE:
                m_auiEncounter[0] = data;
                break;
            case TYPE_OMROGG:
                m_auiEncounter[1] = data;
                break;
        }
    }

    uint32 GetData(uint32 type)
    {
        switch(type)
        {
            case TYPE_NETHEKURSE:
                return m_auiEncounter[0];
            case TYPE_OMROGG:
                return m_auiEncounter[1];
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

InstanceData* GetInstanceData_instance_shattered_halls(Map* pMap)
{
    return new instance_shattered_halls(pMap);
}

void AddSC_instance_shattered_halls()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_shattered_halls";
    newscript->GetInstanceData = &GetInstanceData_instance_shattered_halls;
    newscript->RegisterSelf();
}

