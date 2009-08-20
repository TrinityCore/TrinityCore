/*
 * Copyright (C) 2008 - 2009 Trinity <http://www.trinitycore.org/>
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

#include "precompiled.h"
#include "def_ulduar.h"

struct TRINITY_DLL_DECL instance_ulduar : public ScriptedInstance
{
    instance_ulduar(Map* pMap) : ScriptedInstance(pMap) {Initialize();};
    
    uint32 m_auiEncounter[MAX_ENCOUNTER];
    
    uint64 boss_assembly[3];
    
    void Initialize()
    {
        memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));
        
        for(uint8 i = 0; i < 3; ++i)
            boss_assembly[i] = 0;
    }
    
    bool IsEncounterInProgress() const
    {
        for(uint8 i = 0; i < MAX_ENCOUNTER; ++i)
            if (m_auiEncounter[i] == IN_PROGRESS) return true;

        return false;
    }
    
    void OnCreatureCreate(Creature* pCreature, bool add)
    {
        switch(pCreature->GetEntry())
        {
            case 32867: boss_assembly[0] = pCreature->GetGUID();    break;
            case 32927: boss_assembly[1] = pCreature->GetGUID();    break;
            case 32857: boss_assembly[2] = pCreature->GetGUID();    break;
        }
        
     }

    uint64 GetData64(uint32 identifier)
    {
        switch(identifier)
        {
            case DATA_STEELBREAKER:         return boss_assembly[0]; // Keep these three in current order
            case DATA_RUNEMASTER_MOLGEIM:   return boss_assembly[1];
            case DATA_STORMCALLER_BRUNDIR:  return boss_assembly[2];
            default:    return 0;
        }
    }
    
    uint32 GetData(uint32 type)
    {
        switch(type)
        {
            case BOSS_LEVIATHAN:
            case BOSS_IGNIS:
            case BOSS_RAZORSCALE:
            case BOSS_XT002:
            case BOSS_ASSEMBLY:
            case BOSS_KOLOGARN:
            case BOSS_AURIAYA:
            case BOSS_MIMIRON:
            case BOSS_HODIR:
            case BOSS_THORIM:
            case BOSS_FREYA:
            case BOSS_VEZAX:
            case BOSS_YOGGSARON:
            case BOSS_ALGALON:
                return m_auiEncounter[type];
        }
        
        return 0;
    }
    
    void SetData(uint32 type, uint32 data)
    {
        switch(type)
        {
            case DATA_ASSEMBLY:
                m_auiEncounter[BOSS_ASSEMBLY] = data;
            break;
        }
    }
};


InstanceData* GetInstanceData_instance_ulduar(Map* pMap)
{
    return new instance_ulduar(pMap);
}

void AddSC_instance_ulduar()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_ulduar";
    newscript->GetInstanceData = &GetInstanceData_instance_ulduar;
    newscript->RegisterSelf();
}