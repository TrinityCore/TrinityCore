/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "CreatureGroups.h"
#include "halls_of_origination.h"
#include "InstanceScript.h"
#include "Map.h"

DoorData const doorData[] =
{
    { GO_DOODAD_ULDUM_DOOR_14,         DATA_TEMPLE_GUARDIAN_ANHUUR, DOOR_TYPE_ROOM    },
    { GO_DOODAD_ULDUM_DOOR_15,         DATA_TEMPLE_GUARDIAN_ANHUUR, DOOR_TYPE_PASSAGE },
    { GO_ANHUURS_BRIDGE,               DATA_TEMPLE_GUARDIAN_ANHUUR, DOOR_TYPE_PASSAGE },
    { GO_DOODAD_ULDUM_ELEVATOR_COL01,  DATA_TEMPLE_GUARDIAN_ANHUUR, DOOR_TYPE_PASSAGE },
    { GO_VAULT_OF_LIGHTS_DOOR,         DATA_VAULT_OF_LIGHTS,        DOOR_TYPE_PASSAGE },
    { GO_DOODAD_ULDUM_LIGHTMACHINE_02, DATA_EARTH_WARDEN,           DOOR_TYPE_PASSAGE },
    { GO_DOODAD_ULDUM_LIGHTMACHINE_01, DATA_FIRE_WARDEN,            DOOR_TYPE_PASSAGE },
    { GO_DOODAD_ULDUM_LIGHTMACHINE_03, DATA_WATER_WARDEN,           DOOR_TYPE_PASSAGE },
    { GO_DOODAD_ULDUM_LIGHTMACHINE_04, DATA_AIR_WARDEN,             DOOR_TYPE_PASSAGE },
    { GO_LIFT_GLASS_STAR,              DATA_ANRAPHET,               DOOR_TYPE_PASSAGE },
    { GO_LIFT_GLASS_STAR_2,            DATA_ANRAPHET,               DOOR_TYPE_PASSAGE },
    { 0,                               0,                           DOOR_TYPE_ROOM    }
};

/*BossBoundaryData const boundaries =
{
};*/

ObjectData const creatureData[] =
{
    { BOSS_TEMPLE_GUARDIAN_ANHUUR,      DATA_TEMPLE_GUARDIAN_ANHUUR },
    { BOSS_EARTHRAGER_PTAH,             DATA_EARTHRAGER_PTAH        },
    { NPC_BRANN_BRONZEBEARD_0,          DATA_BRANN_0                },
    { NPC_FIRE_WARDEN,                  DATA_FIRE_WARDEN            },
    { NPC_EARTH_WARDEN,                 DATA_EARTH_WARDEN           },
    { NPC_WATER_WARDEN,                 DATA_WATER_WARDEN           },
    { NPC_AIR_WARDEN,                   DATA_AIR_WARDEN             },
    { BOSS_ANRAPHET,                    DATA_ANRAPHET               },
    { BOSS_ISISET,                      DATA_ISISET                 },
//  { BOSS_AMMUNAE,                     DATA_AMMUNAE                },
//  { BOSS_SETESH,                      DATA_SETESH                 },
//  { BOSS_RAJH,                        DATA_RAJH                   },
    { 0,                                0 } // END
};

ObjectData const gameObjectData[] =
{
    { GO_DOODAD_ULDUM_DOOR_15,          DATA_ANHUUR_DOOR                },
    { GO_DOODAD_ULDUM_LASERBEAMS01,     DATA_LASERBEAMS_EARTH_WARDEN    },
    { GO_DOODAD_ULDUM_LASERBEAMS_01,    DATA_LASERBEAMS_FIRE_WARDEN     },
    { GO_DOODAD_ULDUM_LASERBEAMS_02,    DATA_LASERBEAMS_AIR_WARDEN      },
    { GO_DOODAD_ULDUM_LASERBEAMS_03,    DATA_LASERBEAMS_WATER_WARDEN    },
    { GO_SUN_MIRROR,                    DATA_ANRAPHET_SUN_MIRROR        },
    { GO_ANRAPHET_DOOR,                 DATA_ANRAPHET_DOOR              },
    { GO_LIFT_OF_THE_MAKERS,            DATA_LIFT_OF_THE_MAKERS         },
    { 0,                                0 } //END
};

// Halls of Origination Transit Device positions
const Position EntranceTransitDevicePos      = { -934.576f,  470.708f,  53.8334f, 3.08918f };
const Position ElevatorTransitDevicePos      = { -536.462f,  193.262f,  79.839f,  3.08918f };
const Position EarthragerTransitDevicePos    = { -506.194f, -337.028f, 162.363f,  1.55334f };
const Position TempleTransitDevicePos        = { -506.766f, -686.826f, 139.97f,   1.55334f };
const Position VaultOfLightsTransitDevicePos = { -276.288f,  366.781f,  75.8439f, 3.08918f };
const Position AnraphetTransitDevicePos      = {  -74.1892f, 366.75f,   89.4228f, 3.08918f };

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
                LoadDoorData(doorData);
                LoadObjectData(creatureData, gameObjectData);
                _deadElementals = 0;

                _wardenPositionSpells.push_back(SPELL_TELEPORT_EARTH);
                _wardenPositionSpells.push_back(SPELL_TELEPORT_AIR);
                _wardenPositionSpells.push_back(SPELL_TELEPORT_FIRE);
                _wardenPositionSpells.push_back(SPELL_TELEPORT_WATER);
                Trinity::Containers::RandomShuffle(_wardenPositionSpells);
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                InstanceScript::OnGameObjectCreate(go);

                switch (go->GetEntry())
                {
                    case GO_LIFT_OF_THE_MAKERS:
                        go->SetTransportState(GO_STATE_TRANSPORT_ACTIVE);
                        go->SetTransportState(GO_STATE_TRANSPORT_STOPPED, 0);
                        break;
                    case GO_DOODAD_ULDUM_LASERBEAMS01:
                    case GO_DOODAD_ULDUM_LASERBEAMS_01:
                    case GO_DOODAD_ULDUM_LASERBEAMS_02:
                    case GO_DOODAD_ULDUM_LASERBEAMS_03:
                    case GO_SUN_MIRROR:
                    case GO_ANRAPHET_DOOR:
                        if (_deadElementals == 4)
                            go->SetGoState(GO_STATE_ACTIVE);
                        break;
                    case GO_ULDUM_TEMPLE: // Research about these objects.
                    case GO_REORIGINATION_MECHANISM_1:
                    case GO_REORIGINATION_MECHANISM_2:
                    case GO_REORIGINATION_MECHANISM_3:
                    case GO_REORIGINATION_MECHANISM_4:
                    case GO_REORIGINATION_MECHANISM_5:
                        go->SetGoState(GO_STATE_ACTIVE);
                        break;
                    default:
                        break;
                }

                // Pretty much all instance gameobjects are far-visible, no?
                // Requires implementation of far-visibility: https://github.com/TrinityCore/TrinityCore/pull/20725
                //go->SetFarVisible(true);
            }

            void OnCreatureCreate(Creature* creature) override
            {
                InstanceScript::OnCreatureCreate(creature);

                switch (creature->GetEntry())
                {
                    case BOSS_ANRAPHET: // active (their AI runs the event at the Vault of Lights)
                    case NPC_BRANN_BRONZEBEARD_0:
                        creature->setActive(true);
                        break;
                    case NPC_FIRE_WARDEN: // random teleport spell + far-visibility
                    case NPC_EARTH_WARDEN:
                    case NPC_WATER_WARDEN:
                    case NPC_AIR_WARDEN:
                        //creature->SetFarVisible(true); 
                        creature->CastSpell(nullptr, _wardenPositionSpells.back());
                        _wardenPositionSpells.pop_back();
                        // No break here!
                    case NPC_STONE_TROGG_PILLAGER: // far-visibility
                    case NPC_STONE_TROGG_BRUTE:
                    case NPC_STONE_TROGG_ROCK_FLINGER:
                        // Requires implementation of far-visibility: https://github.com/TrinityCore/TrinityCore/pull/20725
                        //creature->SetFarVisible(true);
                        break;
                    case NPC_SPATIAL_FLUX:
                    case NPC_SPATIAL_ANOMALY:
                    case NPC_FLUX_ANIMATOR:
                    case NPC_STAR_SHARD:
                        creature->SearchFormation();
                        if (creature->GetFormation())
                            isisetTrashGUIDs.push_back(creature->GetGUID());
                        break;
                    default:
                        break;
                }
            }

            void SetData(uint32 data, uint32 value) override
            {
                switch (data)
                {
                    case DATA_ISISET_PHASE:
                        _isisetPhase = value;
                        break;
                    case DATA_ISISET_ASTRAL_RAIN_ALIVE:
                        _isisetAstralRainAlive = value;
                        break;
                    case DATA_ISISET_CELESTIAL_CALL_ALIVE:
                        _isisetCelestialCallAlive = value;
                        break;
                    case DATA_ISISET_VEIL_OF_SKY_ALIVE:
                        _isisetVeilOfSkyAlive = value;
                        break;
                }
            }

            uint32 GetData(uint32 data) const override
            {
                switch (data)
                {
                    case DATA_DEAD_ELEMENTALS:
                        return _deadElementals;
                    case DATA_ISISET_PHASE:
                        return _isisetPhase;
                    case DATA_ISISET_ASTRAL_RAIN_ALIVE:
                        return _isisetAstralRainAlive;
                    case DATA_ISISET_CELESTIAL_CALL_ALIVE:
                        return _isisetCelestialCallAlive;
                    case DATA_ISISET_VEIL_OF_SKY_ALIVE:
                        return _isisetVeilOfSkyAlive;
                    default:
                        break;
                }

                return 0;
            }

            void OnUnitDeath(Unit* unit) override
            {
                Creature* creature = unit->ToCreature();
                if (!creature)
                    return;

                switch (creature->GetEntry())
                {
                    case BOSS_TEMPLE_GUARDIAN_ANHUUR:
                        unit->SummonGameObject(GO_HOO_TRANSIT_DEVICE, EntranceTransitDevicePos, QuaternionData(), 0);
                        break;
                    case BOSS_EARTHRAGER_PTAH:
                        unit->SummonGameObject(GO_HOO_TRANSIT_DEVICE, EarthragerTransitDevicePos, QuaternionData(), 0);
                        unit->SummonGameObject(GO_HOO_TRANSIT_DEVICE, TempleTransitDevicePos, QuaternionData(), 0);
                        break;
                    case BOSS_ANRAPHET:
                        unit->SummonGameObject(GO_HOO_TRANSIT_DEVICE, VaultOfLightsTransitDevicePos, QuaternionData(), 0);
                        unit->SummonGameObject(GO_HOO_TRANSIT_DEVICE, AnraphetTransitDevicePos, QuaternionData(), 0);
                        unit->SummonGameObject(GO_HOO_TRANSIT_DEVICE_2, ElevatorTransitDevicePos, QuaternionData(), 0);
                        break;
                    case NPC_FIRE_WARDEN:
                    case NPC_EARTH_WARDEN:
                    case NPC_WATER_WARDEN:
                    case NPC_AIR_WARDEN:
                    {
                        uint32 data = creature->GetEntry() - WARDEN_ENTRY_DATA_DELTA;
                        SetBossState(data, IN_PROGRESS); // Needs to be set to IN_PROGRESS or else the gameobjects state won't be updated
                        SetBossState(data, DONE);
                        ++_deadElementals;
                        if (Creature* brann = GetCreature(DATA_BRANN_0))
                            brann->AI()->DoAction(ACTION_ELEMENTAL_DIED);
                        break;
                    }
                    case NPC_SPATIAL_ANOMALY:
                    case NPC_FLUX_ANIMATOR:
                    case NPC_STAR_SHARD:
                    {
                        CreatureGroup* group = creature->GetFormation();

                        // Check if whole formation is dead, then despawn its leader
                        for (ObjectGuid guid : isisetTrashGUIDs)
                            if (Creature* member = instance->GetCreature(guid))
                                if (member->GetEntry() != NPC_SPATIAL_FLUX && member->GetFormation()->GetId() == group->GetId() && member->IsAlive())
                                    return;

                        // Despawn leader (Spatial Flux)
                        if (Creature* leader = group->getLeader())
                            leader->DespawnOrUnsummon();

                        break;
                    }
                    default:
                        break;
                }
            }

            void WriteSaveDataMore(std::ostringstream& data) override
            {
                data << _deadElementals;
            }

            void ReadSaveDataMore(std::istringstream& data) override
            {
                data >> _deadElementals;
            }

        protected:
            std::vector<uint32> _wardenPositionSpells;
            GuidVector isisetTrashGUIDs;
            uint32 _deadElementals;
            uint32 _isisetPhase;
            uint32 _isisetAstralRainAlive;
            uint32 _isisetCelestialCallAlive;
            uint32 _isisetVeilOfSkyAlive;
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
