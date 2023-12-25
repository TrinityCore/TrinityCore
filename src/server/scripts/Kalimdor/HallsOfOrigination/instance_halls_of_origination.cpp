/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "ScriptMgr.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "halls_of_origination.h"
#include "InstanceScript.h"
#include "Map.h"

DoorData const doorData[] =
{
    { GO_ANHUURS_DOOR,                  BOSS_TEMPLE_GUARDIAN_ANHUUR,    EncounterDoorBehavior::OpenWhenDone },
    { GO_ANHUURS_BRIDGE,                BOSS_TEMPLE_GUARDIAN_ANHUUR,    EncounterDoorBehavior::OpenWhenDone },
    { GO_DOODAD_ULDUM_ELEVATOR_COL01,   BOSS_TEMPLE_GUARDIAN_ANHUUR,    EncounterDoorBehavior::OpenWhenDone },
    { GO_VAULT_OF_LIGHTS_DOOR,          BOSS_VAULT_OF_LIGHTS,           EncounterDoorBehavior::OpenWhenDone },
    { GO_DOODAD_ULDUM_LIGHTMACHINE_02,  BOSS_EARTH_WARDEN,              EncounterDoorBehavior::OpenWhenDone },
    { GO_DOODAD_ULDUM_LASERBEAMS01,     BOSS_EARTH_WARDEN,              EncounterDoorBehavior::OpenWhenDone },
    { GO_DOODAD_ULDUM_LIGHTMACHINE_01,  BOSS_FIRE_WARDEN,               EncounterDoorBehavior::OpenWhenDone },
    { GO_DOODAD_ULDUM_LASERBEAMS_01,    BOSS_FIRE_WARDEN,               EncounterDoorBehavior::OpenWhenDone },
    { GO_DOODAD_ULDUM_LIGHTMACHINE_03,  BOSS_WATER_WARDEN,              EncounterDoorBehavior::OpenWhenDone },
    { GO_DOODAD_ULDUM_LASERBEAMS_03,    BOSS_WATER_WARDEN,              EncounterDoorBehavior::OpenWhenDone },
    { GO_DOODAD_ULDUM_LIGHTMACHINE_04,  BOSS_AIR_WARDEN,                EncounterDoorBehavior::OpenWhenDone },
    { GO_DOODAD_ULDUM_LASERBEAMS_02,    BOSS_AIR_WARDEN,                EncounterDoorBehavior::OpenWhenDone },
    { 0,                                0,                              EncounterDoorBehavior::OpenWhenNotInProgress }
};

ObjectData const creatureData[] =
{
    { NPC_TEMPLE_GUARDIAN_ANHUUR,       BOSS_TEMPLE_GUARDIAN_ANHUUR },
    { NPC_ANRAPHET,                     BOSS_ANRAPHET               },
    { NPC_EARTHRAGER_PTAH,              BOSS_EARTHRAGER_PTAH        },
    { NPC_BRANN_BRONZEBEARD_0,          DATA_BRANN_BRONZEBEARD      },
    { 0,                                0                           } //END
};

ObjectData const gameObjectData[] =
{
    { GO_LIFT_OF_THE_MAKERS,            DATA_LIFT_OF_THE_MAKERS             },
    { 0,                                0                                   } //END
};

DungeonEncounterData const encounters[] =
{
    { BOSS_TEMPLE_GUARDIAN_ANHUUR,  {{ 1080 }} },
    { BOSS_EARTHRAGER_PTAH,         {{ 1076 }} },
    { BOSS_ANRAPHET,                {{ 1075 }} },
    { BOSS_ISISET,                  {{ 1077 }} },
    { BOSS_AMMUNAE,                 {{ 1074 }} },
    { BOSS_SETESH,                  {{ 1079 }} },
    { BOSS_RAJH,                    {{ 1078 }} }
};

class instance_halls_of_origination : public InstanceMapScript
{
    public:
        instance_halls_of_origination() : InstanceMapScript(HoOScriptName, 644) { }

        struct instance_halls_of_origination_InstanceMapScript : public InstanceScript
        {
            instance_halls_of_origination_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadObjectData(creatureData, gameObjectData);
                LoadDoorData(doorData);
                LoadDungeonEncounterData(encounters);
                _deadElementals = 0;
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                InstanceScript::OnGameObjectCreate(go);

                switch (go->GetEntry())
                {
                    case GO_ANHUURS_BRIDGE:
                        AnhuursBridgeGUID = go->GetGUID();
                        [[fallthrough]];
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

            void OnGameObjectRemove(GameObject* go) override
            {
                InstanceScript::OnGameObjectRemove(go);

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

            uint32 GetData(uint32 data) const override
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

            ObjectGuid GetGuidData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_ANHUUR_BRIDGE:
                        return AnhuursBridgeGUID;
                    case DATA_ANHUUR_DOOR:
                        return AnhuursDoorGUID;
                    case DATA_ANHUUR_LEFT_BEACON:
                        return AnhuurLeftBeaconGUID;
                    case DATA_ANHUUR_RIGHT_BEACON:
                        return AnhuurRightBeaconGUID;
                }

                return InstanceScript::GetGuidData(type);
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

            void OnUnitDeath(Unit* unit) override
            {
                InstanceScript::OnUnitDeath(unit);

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
                        if (Creature* brann = GetCreature(DATA_BRANN_BRONZEBEARD))
                            brann->AI()->DoAction(ACTION_ELEMENTAL_DIED);
                        break;
                }
            }

            void AfterDataLoad() override
            {
                if (GetBossState(BOSS_ANRAPHET) == DONE)
                    IncreaseDeadElementals(4);
            }

        protected:
            ObjectGuid AnhuursBridgeGUID;
            ObjectGuid AnhuursDoorGUID;
            ObjectGuid AnhuurRightBeaconGUID;
            ObjectGuid AnhuurLeftBeaconGUID;
            ObjectGuid AnraphetDoorGUID;
            ObjectGuid SunMirrorGUID;
            uint32 _deadElementals;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_halls_of_origination_InstanceMapScript(map);
        }
};

void AddSC_instance_halls_of_origination()
{
    new instance_halls_of_origination();
}
