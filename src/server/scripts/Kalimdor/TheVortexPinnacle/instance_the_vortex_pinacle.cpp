/*
* Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 3 of the License, or (at your
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

#include "the_vortex_pinnacle.h"
#include "InstanceScript.h"
#include "ScriptMgr.h"

class instance_the_vortex_pinnacle : public InstanceMapScript
{
    public:
    instance_the_vortex_pinnacle() : InstanceMapScript("instance_the_vortex_pinnacle", 657) {}
	
    struct instance_the_vortex_pinnacle_InstanceMapScript : public InstanceScript
    {
        instance_the_vortex_pinnacle_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetBossNumber(BOSSNUMBER);
			
            GrandVizierErtanGUID   = 0;
            AltairusGUID           = 0;
            AsaadGUID              = 0;
        }
		
        void OnCreatureCreate(Creature* creature) OVERRIDE
        {
            switch(creature->GetEntry())
            {
            case BOSS_GRAND_VIZIER_ERTAN:
                GrandVizierErtanGUID = creature->GetGUID();
                break;
            case BOSS_ALTAIRUS:
                AltairusGUID = creature->GetGUID();
                break;
            case BOSS_ASAAD:
                AsaadGUID = creature->GetGUID();
                break;
            }
        }
		
        void OnGameObjectCreate(GameObject* go) OVERRIDE
        {
        }
		
        uint64 GetData64(uint32 data) const OVERRIDE
        {
            switch(data)
            {
            case DATA_GRAND_VIZIER_ERTAN:
                return GrandVizierErtanGUID;
            case DATA_ALTAIRUS:
                return AltairusGUID;
            case DATA_ASAAD:
                return AsaadGUID;
            }
			
            return 0;
        }
		
        void OnGameObjectRemove(GameObject* go) OVERRIDE
	{
	}
		
	std::string GetSaveData() OVERRIDE
	{
            OUT_SAVE_INST_DATA;
            std::ostringstream saveStream;
            saveStream << "T V P " << GetBossSaveData();
            OUT_SAVE_INST_DATA_COMPLETE;
            return saveStream.str();
        }
		
        void Load(const char* in) OVERRIDE
        {
            if(!in)
            {
                OUT_LOAD_INST_DATA_FAIL;
                return;
            }
            
            OUT_LOAD_INST_DATA(in);
            
            char dataHead1, dataHead2, dataHead3;
            
            std::istringstream loadStream(in);
            loadStream >> dataHead1 >> dataHead2 >> dataHead3;
            
            if(dataHead1 == 'T' && dataHead2 == 'V' && dataHead3 == 'P')
            {
                for(uint8 i = 0; i < BOSSNUMBER; ++i)
                {
                    uint32 tmpState;
                    loadStream >> tmpState;
					
                    if(tmpState == IN_PROGRESS || tmpState > SPECIAL) tmpState = NOT_STARTED;
					
                    SetBossState(i, EncounterState(tmpState));
                }
            }
            else OUT_LOAD_INST_DATA_FAIL;
			
            OUT_LOAD_INST_DATA_COMPLETE;
        }
		
        protected:
        uint64 GrandVizierErtanGUID;
        uint64 AltairusGUID;
        uint64 AsaadGUID;
    };
	
    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new instance_the_vortex_pinnacle_InstanceMapScript(map);
    }
};

void AddSC_instance_the_vortex_pinnacle()
{
    new instance_the_vortex_pinnacle();
}
