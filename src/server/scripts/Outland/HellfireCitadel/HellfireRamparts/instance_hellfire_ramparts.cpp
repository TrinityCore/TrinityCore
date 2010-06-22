/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Instance_Hellfire_Ramparts
SD%Complete: 50
SDComment:
SDCategory: Hellfire Ramparts
EndScriptData */

#include "ScriptPCH.h"
#include "hellfire_ramparts.h"

struct instance_ramparts : public ScriptedInstance
{
    instance_ramparts(Map* pMap) : ScriptedInstance(pMap) {Initialize();}

    uint32 m_auiEncounter[MAX_ENCOUNTER];
    uint64 m_uiChestNGUID;
    uint64 m_uiChestHGUID;

    void Initialize()
    {
        memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

        m_uiChestNGUID = 0;
        m_uiChestHGUID = 0;
    }

    void OnGameObjectCreate(GameObject* pGo, bool /*add*/)
    {
        switch(pGo->GetEntry())
        {
            case 185168: m_uiChestNGUID = pGo->GetGUID(); break;
            case 185169: m_uiChestHGUID = pGo->GetGUID(); break;
        }
    }

    void SetData(uint32 uiType, uint32 uiData)
    {
        sLog.outDebug("TSCR: Instance Ramparts: SetData received for type %u with data %u",uiType,uiData);

        switch(uiType)
        {
            case TYPE_VAZRUDEN:
                if (uiData == DONE && m_auiEncounter[1] == DONE)
                    DoRespawnGameObject(instance->IsHeroic() ? m_uiChestHGUID : m_uiChestNGUID, HOUR*IN_MILISECONDS);
                m_auiEncounter[0] = uiData;
                break;
            case TYPE_NAZAN:
                if (uiData == DONE && m_auiEncounter[0] == DONE)
                    DoRespawnGameObject(instance->IsHeroic() ? m_uiChestHGUID : m_uiChestNGUID, HOUR*IN_MILISECONDS);
                m_auiEncounter[1] = uiData;
                break;
        }
    }
};

InstanceData* GetInstanceData_instance_ramparts(Map* pMap)
{
    return new instance_ramparts(pMap);
}

void AddSC_instance_ramparts()
{
    Script* pNewScript;
    pNewScript = new Script;
    pNewScript->Name = "instance_ramparts";
    pNewScript->GetInstanceData = &GetInstanceData_instance_ramparts;
    pNewScript->RegisterSelf();
}
