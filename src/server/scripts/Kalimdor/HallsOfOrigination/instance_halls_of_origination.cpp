/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
    {GO_ANHUURS_DOOR,                 DATA_TEMPLE_GUARDIAN_ANHUUR, DOOR_TYPE_PASSAGE, BOUNDARY_NONE },
    {GO_ANHUURS_BRIDGE,               DATA_TEMPLE_GUARDIAN_ANHUUR, DOOR_TYPE_PASSAGE, BOUNDARY_NONE },
    {GO_DOODAD_ULDUM_ELEVATOR_COL01,  DATA_TEMPLE_GUARDIAN_ANHUUR, DOOR_TYPE_PASSAGE, BOUNDARY_NONE },
    {GO_VAULT_OF_LIGHTS_DOOR,         DATA_VAULT_OF_LIGHTS,        DOOR_TYPE_PASSAGE, BOUNDARY_NONE },
    {GO_DOODAD_ULDUM_LIGHTMACHINE_02, DATA_EARTH_WARDEN,           DOOR_TYPE_PASSAGE, BOUNDARY_NONE },
    {GO_DOODAD_ULDUM_LASERBEAMS01,    DATA_EARTH_WARDEN,           DOOR_TYPE_PASSAGE, BOUNDARY_NONE },
    {GO_DOODAD_ULDUM_LIGHTMACHINE_01, DATA_FIRE_WARDEN,            DOOR_TYPE_PASSAGE, BOUNDARY_NONE },
    {GO_DOODAD_ULDUM_LASERBEAMS_01,   DATA_FIRE_WARDEN,            DOOR_TYPE_PASSAGE, BOUNDARY_NONE },
    {GO_DOODAD_ULDUM_LIGHTMACHINE_03, DATA_WATER_WARDEN,           DOOR_TYPE_PASSAGE, BOUNDARY_NONE },
    {GO_DOODAD_ULDUM_LASERBEAMS_03,   DATA_WATER_WARDEN,           DOOR_TYPE_PASSAGE, BOUNDARY_NONE },
    {GO_DOODAD_ULDUM_LIGHTMACHINE_04, DATA_AIR_WARDEN,             DOOR_TYPE_PASSAGE, BOUNDARY_NONE },
    {GO_DOODAD_ULDUM_LASERBEAMS_02,   DATA_AIR_WARDEN,             DOOR_TYPE_PASSAGE, BOUNDARY_NONE },
    {0,                              0,                            DOOR_TYPE_ROOM,    BOUNDARY_NONE }
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
                BrannBronzebeardGUID = 0;
                AnraphetGUID = 0;
                AnraphetDoorGUID = 0;
                SunMirrorGUID = 0;
                _deadElementals = 0;
            }

            void OnGameObjectCreate(GameObject* go) OVERRIDE
            {
                switch (go->GetEntry())
                {
                    case GO_ANHUURS_BRIDGE:
                        AnhuursBridgeGUID = go->GetGUID();
                    case GO_DOODAD_ULDUM_ELEVATOR_COL01:
                    case GO_VAULT_OF_LIGHTS_DOOR:
                    case GO_DOODAD_ULDUM_LIGHTMACHINE_01:
                    case GO_DOODAD_ULDUM_LIGHTMACHINE_02:
                    case GO_DOODAD_ULDUM_LIGHTMACHINE_03:
                    case GO_DOODAD_ULDUM_LIGHTMACHINE_04:
                    case GO_DOODAD_ULDUM_LASERBEAMS01:
                    case GO_DOODAD_ULDUM_LASERBEAMS_01:
                    case GO_DOODAD_ULDUM_LASERBEAMS_02:
                    case GO_DOODAD_ULDUM_LASERBEAMS_03:
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
                    case GO_SUN_MIRROR:
                        SunMirrorGUID = go->GetGUID();
                        break;
                    case GO_ANRAPHET_DOOR:
                        AnraphetDoorGUID = go->GetGUID();
                        break;
                }
            }

            void OnGameObjectRemove(GameObject* go) OVERRIDE
            {
                switch (go->GetEntry())
                {
                    case GO_ANHUURS_BRIDGE:
                    case GO_DOODAD_ULDUM_ELEVATOR_COL01:
                    case GO_ANHUURS_DOOR:
                    case GO_VAULT_OF_LIGHTS_DOOR:
                    case GO_DOODAD_ULDUM_LIGHTMACHINE_01:
                    case GO_DOODAD_ULDUM_LIGHTMACHINE_02:
                    case GO_DOODAD_ULDUM_LIGHTMACHINE_03:
                    case GO_DOODAD_ULDUM_LIGHTMACHINE_04:
                    case GO_DOODAD_ULDUM_LASERBEAMS01:
                    case GO_DOODAD_ULDUM_LASERBEAMS_01:
                    case GO_DOODAD_ULDUM_LASERBEAMS_02:
                    case GO_DOODAD_ULDUM_LASERBEAMS_03:
                        AddDoor(go, false);
                        break;
                }
            }

            void OnCreatureCreate(Creature* creature) OVERRIDE
            {
                switch (creature->GetEntry())
                {
                    case BOSS_TEMPLE_GUARDIAN_ANHUUR:
                        TempleGuardianAnhuurGUID = creature->GetGUID();
                        break;
                    case NPC_BRANN_BRONZEBEARD_0:
                        BrannBronzebeardGUID = creature->GetGUID();
                        break;
                    case BOSS_ANRAPHET:
                        AnraphetGUID = creature->GetGUID();
                        break;
                }
            }

            uint32 GetData(uint32 data) const OVERRIDE
            {
                switch (data)
                {
                    case DATA_DEAD_ELEMENTALS:
                        return _deadElementals;
                    default:
                        break;
                }

                return 0;
            }

            uint64 GetData64(uint32 index) const OVERRIDE
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
                    case DATA_BRANN_0_GUID:
                        return BrannBronzebeardGUID;
                    case DATA_ANRAPHET_GUID:
                        return AnraphetGUID;
                }

                return 0;
            }

            void IncreaseDeadElementals(uint32 inc)
            {
                _deadElementals += inc;
                if (_deadElementals == 4)
                {
                    if (GameObject* mirror = instance->GetGameObject(SunMirrorGUID))
                        mirror->SetGoState(GO_STATE_ACTIVE);
                    if (GameObject* door = instance->GetGameObject(AnraphetDoorGUID))
                        door->SetGoState(GO_STATE_ACTIVE);
                }
            }

            void OnUnitDeath(Unit* unit) OVERRIDE
            {
                Creature* creature = unit->ToCreature();
                if (!creature)
                    return;

                switch (creature->GetEntry())
                {
                    case NPC_FIRE_WARDEN:
                    case NPC_EARTH_WARDEN:
                    case NPC_WATER_WARDEN:
                    case NPC_AIR_WARDEN:
                        uint32 data = creature->GetEntry() - WARDEN_ENTRY_DATA_DELTA;
                        SetBossState(data, IN_PROGRESS); // Needs to be set to IN_PROGRESS or else the gameobjects state won't be updated
                        SetBossState(data, DONE);
                        IncreaseDeadElementals(1);
                        if (Creature* brann = instance->GetCreature(BrannBronzebeardGUID))
                            brann->AI()->DoAction(ACTION_ELEMENTAL_DIED);
                        break;
                }
            }

            std::string GetSaveData() OVERRIDE
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;
                saveStream << "H O " << GetBossSaveData() << _deadElementals;

                OUT_SAVE_INST_DATA_COMPLETE;
                return saveStream.str();
            }

            void Load(const char* str) OVERRIDE
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
                    uint32 tmp;
                    loadStream >> tmp;
                    IncreaseDeadElementals(tmp);
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
            uint64 BrannBronzebeardGUID;
            uint64 AnraphetGUID;
            uint64 AnraphetDoorGUID;
            uint64 SunMirrorGUID;
            uint32 _deadElementals;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const OVERRIDE
        {
            return new instance_halls_of_origination_InstanceMapScript(map);
        }
};

void AddSC_instance_halls_of_origination()
{
    new instance_halls_of_origination();
}
