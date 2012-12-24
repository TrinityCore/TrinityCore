/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "ScriptedCreature.h"
#include "Map.h"
#include "PoolMgr.h"
#include "AccountMgr.h"
#include "halls_of_origination.h"
#include "Player.h"
#include "WorldPacket.h"
#include "WorldSession.h"

DoorData const doorData[] = 
{
    {GO_ANHUURS_DOOR,                DATA_TEMPLE_GUARDIAN_ANHUUR, DOOR_TYPE_PASSAGE, BOUNDARY_NONE },
    {GO_ANHUURS_BRIDGE,              DATA_TEMPLE_GUARDIAN_ANHUUR, DOOR_TYPE_PASSAGE, BOUNDARY_NONE },
    {GO_DOODAD_ULDUM_ELEVATOR_COL01, DATA_TEMPLE_GUARDIAN_ANHUUR, DOOR_TYPE_PASSAGE, BOUNDARY_NONE },
    {0,                              0,                           DOOR_TYPE_ROOM,    BOUNDARY_NONE }
};

class instance_halls_of_origination : public InstanceMapScript
{
    public:
        instance_halls_of_origination() : InstanceMapScript(HoOScriptName, 644) { }

        struct instance_halls_of_origination_InstanceMapScript : public InstanceScript
        {
            instance_halls_of_origination_InstanceMapScript(InstanceMap* map) : InstanceScript(map) 
            {
                SetBossNumber(EncounterCount);
                LoadDoorData(doorData);
                TempleGuardianAnhuurGUID = 0;
                AnhuursBridgeGUID = 0;
                AnhuursDoorGUID = 0;
                AnhuurRightBeaconGUID = 0;
                AnhuurLeftBeaconGUID = 0;
            }
            
            void OnGameObjectCreate(GameObject* go)
            {
                switch (go->GetEntry())
                {
                    case GO_ANHUURS_BRIDGE:
                        AnhuursBridgeGUID = go->GetGUID();
                    case GO_DOODAD_ULDUM_ELEVATOR_COL01:
                        AddDoor(go, true);
                        break;
                    case GO_ANHUURS_DOOR:
                        AnhuursDoorGUID = go->GetGUID();
                        AddDoor(go, true);
                        break;
                    case GO_ANHUURS_RIGHT_BEACON:
                        AnhuurRightBeaconGUID = go->GetGUID();
                        break;
                    case GO_ANHUURS_LEFT_BEACON:
                        AnhuurLeftBeaconGUID = go->GetGUID();
                        break;
                }
            }

            void OnCreatureCreate(Creature* creature)
            {
                switch (creature->GetEntry())
                {
                    case BOSS_TEMPLE_GUARDIAN_ANHUUR:
                        TempleGuardianAnhuurGUID = creature->GetGUID();
                        break;
                }
            }

            uint64 GetData64(uint32 index) const
            {
                switch (index)
                {
                    case DATA_ANHUUR_BRIDGE:
                        return AnhuursBridgeGUID;
                    case DATA_ANHUUR_DOOR:
                        return AnhuursDoorGUID;
                    case DATA_ANHUUR_LEFT_BEACON:
                        return AnhuurLeftBeaconGUID;
                    case DATA_ANHUUR_RIGHT_BEACON:
                        return AnhuurRightBeaconGUID;
                    case DATA_ANHUUR_GUID:
                        return TempleGuardianAnhuurGUID;
                }
                
                return 0;
            }

            std::string GetSaveData()
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;
                saveStream << "H O " << GetBossSaveData();

                OUT_SAVE_INST_DATA_COMPLETE;
                return saveStream.str();
            }

            void Load(const char* str)
            {
                if (!str)
                {
                    OUT_LOAD_INST_DATA_FAIL;
                    return;
                }

                OUT_LOAD_INST_DATA(str);

                char dataHead1, dataHead2;

                std::istringstream loadStream(str);
                loadStream >> dataHead1 >> dataHead2;

                if (dataHead1 == 'H' && dataHead2 == 'O')
                {
                    for (uint32 i = 0; i < EncounterCount; ++i)
                    {
                        uint32 tmpState;
                        loadStream >> tmpState;
                        if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
                            tmpState = NOT_STARTED;
                        SetBossState(i, EncounterState(tmpState));
                    }
                }
                else
                    OUT_LOAD_INST_DATA_FAIL;

                OUT_LOAD_INST_DATA_COMPLETE;
            }

        protected:
            uint64 TempleGuardianAnhuurGUID;
            uint64 AnhuursBridgeGUID;
            uint64 AnhuursDoorGUID;
            uint64 AnhuurRightBeaconGUID;
            uint64 AnhuurLeftBeaconGUID;
        };
        
        InstanceScript* GetInstanceScript(InstanceMap* map) const
        {
            return new instance_halls_of_origination_InstanceMapScript(map);
        }
};

void AddSC_instance_halls_of_origination()
{
    new instance_halls_of_origination();
}
