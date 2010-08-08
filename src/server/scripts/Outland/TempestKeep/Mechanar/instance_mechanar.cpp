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
SDName: Instance_Mechanar
SD%Complete: 100
SDComment:
SDCategory: Mechanar
EndScriptData */

#include "ScriptPCH.h"
#include "mechanar.h"

#define MAX_ENCOUNTER      1

class instance_mechanar : public InstanceMapScript
{
    public:
        instance_mechanar()
            : InstanceMapScript("instance_mechanar")
        {
        }
        
        struct instance_mechanar_InstanceMapScript : public InstanceScript
        {
            instance_mechanar_InstanceMapScript(Map* pMap) : InstanceScript(pMap) { Initialize(); };
            
            uint32 m_auiEncounter[MAX_ENCOUNTER];
            
            void Initialize()
            {
                memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));
            }
            
            bool IsEncounterInProgress() const
            {
                for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                    if (m_auiEncounter[i] == IN_PROGRESS)
                        return true;

                return false;
            }
            
            uint32 GetData(uint32 type)
            {
                switch(type)
                {
                case DATA_NETHERMANCER_EVENT:   return m_auiEncounter[0];
                }

                return false;
            }

            uint64 GetData64 (uint32 /*identifier*/)
            {
                return 0;
            }

            void SetData(uint32 type, uint32 data)
            {
                switch(type)
                {
                case DATA_NETHERMANCER_EVENT:   m_auiEncounter[0] = data;   break;
                }
            }
        };
            InstanceScript* GetInstanceScript(InstanceMap* pMap) const
            {
                return new instance_mechanar_InstanceMapScript(pMap);
            }
        
};


void AddSC_instance_mechanar()
{
    new instance_mechanar;
}

