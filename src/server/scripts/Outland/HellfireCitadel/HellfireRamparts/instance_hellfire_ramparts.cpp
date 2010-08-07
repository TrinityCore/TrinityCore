/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

/* ScriptData
SDName: Instance_Hellfire_Ramparts
SD%Complete: 50
SDComment:
SDCategory: Hellfire Ramparts
EndScriptData */

#include "ScriptPCH.h"
#include "hellfire_ramparts.h"

class instance_ramparts : public InstanceMapScript
{
    public:
        instance_ramparts()
            : InstanceMapScript("instance_ramparts")
        {
        }            

        struct instance_ramparts_InstanceMapScript : public ScriptedInstance
        {
            instance_ramparts_InstanceMapScript(Map* pMap) : ScriptedInstance(pMap) {Initialize();}

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
                    case 185168: 
                        m_uiChestNGUID = pGo->GetGUID(); 
                        break;
                    case 185169: 
                        m_uiChestHGUID = pGo->GetGUID(); 
                        break;
                }
            }

            void SetData(uint32 uiType, uint32 uiData)
            {
                sLog.outDebug("TSCR: Instance Ramparts: SetData received for type %u with data %u",uiType,uiData);

                switch(uiType)
                {
                    case TYPE_VAZRUDEN:
                        if (uiData == DONE && m_auiEncounter[1] == DONE)
                            DoRespawnGameObject(instance->IsHeroic() ? m_uiChestHGUID : m_uiChestNGUID, HOUR*IN_MILLISECONDS);
                        m_auiEncounter[0] = uiData;
                        break;
                    case TYPE_NAZAN:
                        if (uiData == DONE && m_auiEncounter[0] == DONE)
                            DoRespawnGameObject(instance->IsHeroic() ? m_uiChestHGUID : m_uiChestNGUID, HOUR*IN_MILLISECONDS);
                        m_auiEncounter[1] = uiData;
                        break;
                }
            }
        };

        InstanceData* GetInstanceData(Map* pMap) const
        {
            return new instance_ramparts_InstanceMapScript(pMap);
        }
};

void AddSC_instance_ramparts()
{
    new instance_ramparts;
}
