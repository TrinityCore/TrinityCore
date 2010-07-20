/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ScriptPCH.h"
#include "obsidian_sanctum.h"

#define MAX_ENCOUNTER     1

/* Obsidian Sanctum encounters:
0 - Sartharion
*/

struct instance_obsidian_sanctum : public ScriptedInstance
{
    instance_obsidian_sanctum(Map* pMap) : ScriptedInstance(pMap) {Initialize();};

    uint32 m_auiEncounter[MAX_ENCOUNTER];
    uint64 m_uiSartharionGUID;
    uint64 m_uiTenebronGUID;
    uint64 m_uiShadronGUID;
    uint64 m_uiVesperonGUID;

    bool m_bTenebronKilled;
    bool m_bShadronKilled;
    bool m_bVesperonKilled;

    void Initialize()
    {
        memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

        m_uiSartharionGUID = 0;
        m_uiTenebronGUID   = 0;
        m_uiShadronGUID    = 0;
        m_uiVesperonGUID   = 0;

        m_bTenebronKilled = false;
        m_bShadronKilled = false;
        m_bVesperonKilled = false;
    }

    void OnCreatureCreate(Creature* pCreature, bool /*add*/)
    {
        switch(pCreature->GetEntry())
        {
            case NPC_SARTHARION:
                m_uiSartharionGUID = pCreature->GetGUID();
                break;
            //three dragons below set to active state once created.
            //we must expect bigger raid to encounter main boss, and then three dragons must be active due to grid differences
            case NPC_TENEBRON:
                m_uiTenebronGUID = pCreature->GetGUID();
                pCreature->setActive(true);
                break;
            case NPC_SHADRON:
                m_uiShadronGUID = pCreature->GetGUID();
                pCreature->setActive(true);
                break;
            case NPC_VESPERON:
                m_uiVesperonGUID = pCreature->GetGUID();
                pCreature->setActive(true);
                break;
        }
    }

    void SetData(uint32 uiType, uint32 uiData)
    {
        if (uiType == TYPE_SARTHARION_EVENT)
            m_auiEncounter[0] = uiData;
        else if(uiType == TYPE_TENEBRON_PREKILLED)
            m_bTenebronKilled = true;
        else if(uiType == TYPE_SHADRON_PREKILLED)
            m_bShadronKilled = true;
        else if(uiType == TYPE_VESPERON_PREKILLED)
            m_bVesperonKilled = true;
    }

    uint32 GetData(uint32 uiType)
    {
        if (uiType == TYPE_SARTHARION_EVENT)
            return m_auiEncounter[0];
        else if(uiType == TYPE_TENEBRON_PREKILLED)
            return m_bTenebronKilled;
        else if(uiType == TYPE_SHADRON_PREKILLED)
            return m_bShadronKilled;
        else if(uiType == TYPE_VESPERON_PREKILLED)
            return m_bVesperonKilled;

        return 0;
    }

    uint64 GetData64(uint32 uiData)
    {
        switch(uiData)
        {
            case DATA_SARTHARION:
                return m_uiSartharionGUID;
            case DATA_TENEBRON:
                return m_uiTenebronGUID;
            case DATA_SHADRON:
                return m_uiShadronGUID;
            case DATA_VESPERON:
                return m_uiVesperonGUID;
        }
        return 0;
    }
};

InstanceData* GetInstanceData_instance_obsidian_sanctum(Map* pMap)
{
    return new instance_obsidian_sanctum(pMap);
}

void AddSC_instance_obsidian_sanctum()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_obsidian_sanctum";
    newscript->GetInstanceData = &GetInstanceData_instance_obsidian_sanctum;
    newscript->RegisterSelf();
}
