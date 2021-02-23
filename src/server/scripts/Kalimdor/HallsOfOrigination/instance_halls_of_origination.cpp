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

#include "halls_of_origination.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "CreatureGroups.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "World.h"
#include "TemporarySummon.h"

DoorData const doorData[] =
{
    { GO_DOODAD_ULDUM_DOOR_14,         DATA_TEMPLE_GUARDIAN_ANHUUR, DOOR_TYPE_ROOM    },
    { GO_DOODAD_ULDUM_DOOR_15,         DATA_TEMPLE_GUARDIAN_ANHUUR, DOOR_TYPE_PASSAGE },
    { GO_ANHUURS_BRIDGE,               DATA_TEMPLE_GUARDIAN_ANHUUR, DOOR_TYPE_PASSAGE },
    { GO_DOODAD_ULDUM_ELEVATOR_COL01,  DATA_TEMPLE_GUARDIAN_ANHUUR, DOOR_TYPE_PASSAGE },
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
    { BOSS_ANRAPHET,                    DATA_ANRAPHET               },
    { BOSS_ISISET,                      DATA_ISISET                 },
    { BOSS_AMMUNAE,                     DATA_AMMUNAE                },
    { BOSS_SETESH,                      DATA_SETESH                 },
    { BOSS_RAJH,                        DATA_RAJH                   },
    { 0,                                0                           } // END
};

ObjectData const gameObjectData[] =
{
    { GO_DOODAD_ULDUM_DOOR_15,          DATA_ANHUUR_DOOR                    },
    { GO_VAULT_OF_LIGHTS_ENTRANCE_DOOR, DATA_VAULT_OF_LIGHTS_ENTRANCE_DOOR  },
    { GO_DOODAD_ULDUM_LIGHTMACHINE_01,  DATA_LIGHT_MACHINE_1                },
    { GO_DOODAD_ULDUM_LIGHTMACHINE_02,  DATA_LIGHT_MACHINE_2                },
    { GO_DOODAD_ULDUM_LIGHTMACHINE_03,  DATA_LIGHT_MACHINE_3                },
    { GO_DOODAD_ULDUM_LIGHTMACHINE_04,  DATA_LIGHT_MACHINE_4                },
    { GO_DOODAD_ULDUM_LASERBEAMS_01,    DATA_LASER_BEAMS_1                  },
    { GO_DOODAD_ULDUM_LASERBEAMS01,     DATA_LASER_BEAMS_2                  },
    { GO_DOODAD_ULDUM_LASERBEAMS_03,    DATA_LASER_BEAMS_3                  },
    { GO_DOODAD_ULDUM_LASERBEAMS_02,    DATA_LASER_BEAMS_4                  },
    { GO_SUN_MIRROR,                    DATA_SUN_MIRROR                     },
    { GO_VAULT_OF_LIGHTS_BOSS_DOOR,     DATA_VAULT_OF_LIGHTS_BOSS_DOOR      },
    { GO_LIFT_OF_THE_MAKERS,            DATA_LIFT_OF_THE_MAKERS             },
    { 0,                                0                                   } //END
};

enum Events
{
    EVENT_RESPAWN_ANRAPHET = 1,
    // Sequence is important here. Do NOT change the event order.
    EVENT_ACTIVATE_LASER_BEAMS_1,
    EVENT_ACTIVATE_LASER_BEAMS_2,
    EVENT_ACTIVATE_LASER_BEAMS_3,
    EVENT_ACTIVATE_LASER_BEAMS_4,
    EVENT_OPEN_CONTROL_ROOM
};

constexpr uint8 const MAX_VAULT_OF_LIGHTS_WARDEN = 4;

std::array<Position, MAX_VAULT_OF_LIGHTS_WARDEN> VaultOfLightsWardenPositions =
{
    Position(-329.96182f, 246.30208f, 89.21011f, 1.5707964f), // Bottom Right
    Position(-329.72745f, 481.14236f, 89.21011f, 4.712389f),  // Bottom Left
    Position(-223.04861f, 243.16145f, 89.21015f, 1.5882496f), // Top Right
    Position(-223.26042f, 488.22223f, 89.21015f, 4.712389f)   // Top Left
};

class instance_halls_of_origination : public InstanceMapScript
{
    public:
        instance_halls_of_origination() : InstanceMapScript(HoOScriptName, 644) { }

        struct instance_halls_of_origination_InstanceMapScript : public InstanceScript
        {
            instance_halls_of_origination_InstanceMapScript(InstanceMap* map) : InstanceScript(map), _vaultOfLightState(NOT_STARTED)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadDoorData(doorData);
                LoadObjectData(creatureData, gameObjectData);
            }

            void Create() override
            {
                InstanceScript::Create();
                if (Creature* anraphet = instance->SummonCreature(BOSS_ANRAPHET, AnraphetSpawnPos))
                {
                    anraphet->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_SELECTABLE);
                    anraphet->SetReactState(REACT_PASSIVE);
                }
                SetupVaultOfLightsWarden();
            }

            void Load(char const* data) override
            {
                InstanceScript::Load(data);
                if (GetData(DATA_VAULT_OF_LIGHTS) != DONE)
                {
                    if (Creature* anraphet = instance->SummonCreature(BOSS_ANRAPHET, AnraphetSpawnPos))
                    {
                        anraphet->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_SELECTABLE);
                        anraphet->SetReactState(REACT_PASSIVE);
                    }
                    SetupVaultOfLightsWarden();
                }
                else if (GetBossState(DATA_ANRAPHET) != DONE)
                    instance->SummonCreature(BOSS_ANRAPHET, AnraphetRespawnPos);
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                InstanceScript::OnGameObjectCreate(go);

                switch (go->GetEntry())
                {
                    case GO_HOO_TRANSIT_DEVICE:
                    case GO_HOO_TRANSIT_DEVICE_2:
                        _transitDeviceGUIDs.insert(go->GetGUID());
                        UpdateTransitDevice(go);
                        break;
                    case GO_LIFT_OF_THE_MAKERS:
                        //go->SetTransportState(GO_STATE_TRANSPORT_STOPPED, 0);
                        break;
                    case GO_VAULT_OF_LIGHTS_ENTRANCE_DOOR:
                        if (_vaultOfLightState != NOT_STARTED)
                            go->SetGoState(GO_STATE_ACTIVE);
                        break;
                    case GO_DOODAD_ULDUM_LASERBEAMS01:
                    case GO_DOODAD_ULDUM_LASERBEAMS_01:
                    case GO_DOODAD_ULDUM_LASERBEAMS_02:
                    case GO_DOODAD_ULDUM_LASERBEAMS_03:
                    case GO_DOODAD_ULDUM_LIGHTMACHINE_01:
                    case GO_DOODAD_ULDUM_LIGHTMACHINE_02:
                    case GO_DOODAD_ULDUM_LIGHTMACHINE_03:
                    case GO_DOODAD_ULDUM_LIGHTMACHINE_04:
                    case GO_SUN_MIRROR:
                    case GO_VAULT_OF_LIGHTS_BOSS_DOOR:
                        go->SetFarVisible(true);
                        if (GetData(DATA_VAULT_OF_LIGHTS) == DONE)
                            go->SetGoState(GO_STATE_ACTIVE);
                        break;
                    case GO_ULDUM_TEMPLE:
                    case GO_REORIGINATION_MECHANISM_1:
                    case GO_REORIGINATION_MECHANISM_2:
                    case GO_REORIGINATION_MECHANISM_3:
                    case GO_REORIGINATION_MECHANISM_4:
                    case GO_REORIGINATION_MECHANISM_5:
                        go->SetGoState(GO_STATE_ACTIVE);
                        break;
                    case GO_BEACON_OF_LIGHT_NORMAL_1:
                    case GO_BEACON_OF_LIGHT_NORMAL_2:
                    case GO_BEACON_OF_LIGHT_HEROIC_1:
                    case GO_BEACON_OF_LIGHT_HEROIC_2:
                        _anhuurEncounterGUIDs.insert(go->GetGUID());
                        break;
                    default:
                        break;
                }
            }

            void OnCreatureCreate(Creature* creature) override
            {
                InstanceScript::OnCreatureCreate(creature);

                switch (creature->GetEntry())
                {
                    case NPC_HOO_CAMEL:
                        _hooCamelGUIDs.insert(creature->GetGUID());
                        break;
                    case NPC_BEETLE_STALKER:
                        _beetleStalkerGUIDS.insert(creature->GetGUID());
                        break;
                    case NPC_DUSTBONE_HORROR:
                    case NPC_JEWELED_SCARAB:
                        if (Creature* ptah = GetCreature(DATA_EARTHRAGER_PTAH))
                            ptah->AI()->JustSummoned(creature);
                        break;
                    case BOSS_ANRAPHET:
                    case NPC_BRANN_BRONZEBEARD_0:
                        creature->SetFarVisible(true);
                        break;
                    case NPC_FIRE_WARDEN:
                    case NPC_EARTH_WARDEN:
                    case NPC_WATER_WARDEN:
                    case NPC_AIR_WARDEN:
                        creature->SetFarVisible(true);
                        break;
                    case NPC_STONE_TROGG_PILLAGER:
                    case NPC_STONE_TROGG_BRUTE:
                    case NPC_STONE_TROGG_ROCK_FLINGER:
                        if (GetData(DATA_VAULT_OF_LIGHTS) == DONE)
                            creature->DespawnOrUnsummon(0, Seconds(DAY));
                        creature->SetFarVisible(true);
                        break;
                    case NPC_SPATIAL_FLUX_TRASH:
                    case NPC_SPATIAL_ANOMALY:
                    case NPC_FLUX_ANIMATOR:
                    case NPC_STAR_SHARD:
                        creature->SearchFormation();
                        if (creature->GetFormation())
                            _isisetTrashGUIDs.insert(creature->GetGUID());
                        break;
                    case NPC_ALPHA_BEAM:
                        if (Creature* anraphet = GetCreature(DATA_ANRAPHET))
                            anraphet->AI()->JustSummoned(creature);
                        break;
                    case NPC_CAVE_IN_STALKER:
                        _anhuurEncounterGUIDs.insert(creature->GetGUID());
                        if (creature->GetPositionZ() <= 70.0f)
                            _caveInStalkerGUIDs.insert(creature->GetGUID());
                        break;
                    case NPC_PIT_VIPER:
                         _anhuurEncounterGUIDs.insert(creature->GetGUID());
                        break;
                    default:
                        break;
                }
            }

            void SetData(uint32 data, uint32 value) override
            {
                switch (data)
                {
                    case DATA_HANDLE_SHIELD_VISUAL:
                        for (ObjectGuid guid : _caveInStalkerGUIDs)
                        {
                            if (Creature* stalker = instance->GetCreature(guid))
                            {
                                if (value == IN_PROGRESS)
                                {
                                    if (stalker->GetPositionX() > -640.0f)
                                        stalker->CastSpell(stalker, SPELL_SHIELD_VISUAL_LEFT, true);
                                    else
                                        stalker->CastSpell(stalker, SPELL_SHIELD_VISUAL_RIGHT, true);
                                }
                            }
                        }
                        break;
                    case DATA_HANDLE_BEAM_OF_LIGHT:
                        for (ObjectGuid guid : _caveInStalkerGUIDs)
                        {
                            if (Creature* stalker = instance->GetCreature(guid))
                            {
                                if (value == IN_PROGRESS)
                                {
                                    if (stalker->GetPositionX() > -640.0f)
                                        stalker->CastSpell(stalker, SPELL_BEAM_OF_LIGHT_LEFT, true);
                                    else
                                        stalker->CastSpell(stalker, SPELL_BEAM_OF_LIGHT_RIGHT, true);
                                }
                                else
                                    stalker->RemoveAllAuras();
                            }
                        }
                        break;
                    case DATA_SUMMON_SANDSTORM_ADDS:
                        for (ObjectGuid guid : _beetleStalkerGUIDS)
                        {
                            if (Creature* beetleStalker = instance->GetCreature(guid))
                            {
                                if (-400.f < beetleStalker->GetPositionY() && beetleStalker->GetPositionY() < -390.f) // 2 stalkers in the middle
                                    beetleStalker->CastSpell(beetleStalker, SPELL_SUMMON_DUSTBONE_HORROR);
                                else
                                    beetleStalker->CastSpell(beetleStalker, SPELL_BEETLE_BURROW);
                            }
                        }
                        break;
                    case DATA_VAULT_OF_LIGHTS:
                        _vaultOfLightState = EncounterState(value);

                        if (value == IN_PROGRESS)
                        {
                            if (GameObject* door = GetGameObject(DATA_VAULT_OF_LIGHTS_ENTRANCE_DOOR))
                                door->SetGoState(GO_STATE_ACTIVE);

                            DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_VAULT_OF_LIGHTS_START_EVENT);
                        }
                        else if (value == DONE)
                        {
                            DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET2, SPELL_VAULT_OF_LIGHTS_CREDIT);
                            _events.ScheduleEvent(EVENT_OPEN_CONTROL_ROOM, 8s);
                            SaveToDB();
                        }
                        break;
                    case DATA_WARDEN_1_DIED:
                    case DATA_WARDEN_2_DIED:
                    case DATA_WARDEN_3_DIED:
                    case DATA_WARDEN_4_DIED:
                        if (value == DONE)
                        {
                            ActivateLightMachine(data - DATA_WARDEN_1_DIED);
                            if (Creature* brann = GetCreature(DATA_BRANN_0))
                                if (brann->IsAIEnabled)
                                    brann->AI()->SetData(data, value);
                        }
                        break;
                    default:
                        break;
                }
            }

            uint32 GetData(uint32 data) const override
            {
                switch (data)
                {
                    case DATA_VAULT_OF_LIGHTS:
                        return _vaultOfLightState;
                    default:
                        break;
                }

                return 0;
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                if (state == DONE)
                    for (ObjectGuid guid : _transitDeviceGUIDs)
                        if (GameObject* transit = instance->GetGameObject(guid))
                            UpdateTransitDevice(transit);

                switch (type)
                {
                    case DATA_TEMPLE_GUARDIAN_ANHUUR:
                        if (state == FAIL || state == DONE)
                        {
                            for (ObjectGuid guid : _anhuurEncounterGUIDs)
                            {
                                if (guid.IsGameObject())
                                {
                                    if (GameObject* go = instance->GetGameObject(guid))
                                        go->DespawnOrUnsummon(0s, state == FAIL ? 5s : 0s);
                                }
                                else if (Creature* creature = instance->GetCreature(guid))
                                    creature->DespawnOrUnsummon(0s, state == FAIL ? 30s : 0s);
                            }
                            _anhuurEncounterGUIDs.clear();
                        }
                        break;
                    case DATA_EARTHRAGER_PTAH:
                        if (state == IN_PROGRESS)
                        {
                            // Camels cannot be mounted during the boss fight.
                            for (ObjectGuid guid : _hooCamelGUIDs)
                                if (Creature* camel = instance->GetCreature(guid))
                                    camel->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                        }
                        else
                        {
                            // Make camels mountable again.
                            for (ObjectGuid guid : _hooCamelGUIDs)
                                if (Creature* camel = instance->GetCreature(guid))
                                    camel->SetFlag(UNIT_FIELD_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);

                            for (ObjectGuid guid : _beetleStalkerGUIDS)
                                if (Creature* beetleStalker = instance->GetCreature(guid))
                                    beetleStalker->RemoveAllAuras();
                        }
                        break;
                    case DATA_ANRAPHET:
                        if (state == FAIL)
                            _events.ScheduleEvent(EVENT_RESPAWN_ANRAPHET, 30s);
                        break;
                    default:
                        break;
                }

                return true;
            }

            void OnUnitDeath(Unit* unit) override
            {
                Creature* creature = unit->ToCreature();
                if (!creature)
                    return;

                switch (creature->GetEntry())
                {
                    case NPC_DUSTBONE_HORROR:
                    case NPC_JEWELED_SCARAB:
                        if (Creature* ptah = GetCreature(DATA_EARTHRAGER_PTAH))
                            ptah->GetAI()->DoAction(ACTION_PTAH_ADD_DIED);
                        break;
                    case NPC_SPATIAL_ANOMALY:
                    case NPC_FLUX_ANIMATOR:
                    case NPC_STAR_SHARD:
                    {
                        CreatureGroup* group = creature->GetFormation();
                        if (!group)
                            return;

                        // Check if whole formation is dead, then despawn its leader
                        for (ObjectGuid guid : _isisetTrashGUIDs)
                            if (Creature* member = instance->GetCreature(guid))
                                if (member->GetEntry() != NPC_SPATIAL_FLUX_TRASH && member->GetFormation()->GetId() == group->GetId() && member->IsAlive())
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

            void Update(uint32 diff) override
            {
                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_RESPAWN_ANRAPHET:
                            instance->SummonCreature(BOSS_ANRAPHET, AnraphetRespawnPos);
                            break;
                        case EVENT_ACTIVATE_LASER_BEAMS_1:
                        case EVENT_ACTIVATE_LASER_BEAMS_2:
                        case EVENT_ACTIVATE_LASER_BEAMS_3:
                        case EVENT_ACTIVATE_LASER_BEAMS_4:
                            if (GameObject* beams = GetGameObject(DATA_LASER_BEAMS_1 +  eventId - EVENT_ACTIVATE_LASER_BEAMS_1))
                                beams->SetGoState(GO_STATE_ACTIVE);
                            break;
                        case EVENT_OPEN_CONTROL_ROOM:
                            if (GameObject* bossDoor = GetGameObject(DATA_VAULT_OF_LIGHTS_BOSS_DOOR))
                                bossDoor->SetGoState(GO_STATE_ACTIVE);
                            if (GameObject* sunMirror = GetGameObject(DATA_SUN_MIRROR))
                                sunMirror->SetGoState(GO_STATE_ACTIVE);

                            if (Creature* anraphet = GetCreature(DATA_ANRAPHET))
                                if (anraphet->IsAIEnabled)
                                    anraphet->AI()->DoAction(ACTION_ANRAPHET_INTRO);
                            break;
                        default:
                            break;
                    }
                }
            }

            void WriteSaveDataMore(std::ostringstream& data) override
            {
                data << _vaultOfLightState;
            }

            void ReadSaveDataMore(std::istringstream& data) override
            {
                data >> _vaultOfLightState;
            }

        private:
            void UpdateTransitDevice(GameObject* transit)
            {
                if (transit->GetPositionX() < -900.f) // The southernmost transit: x = -934.576
                    transit->SetRespawnTime(GetBossState(DATA_TEMPLE_GUARDIAN_ANHUUR) == DONE ? -1 : DAY);
                else if (transit->GetPositionY() < -300.f) // The two easternmost transits: y = -337.028, y = -686.826
                    transit->SetRespawnTime(GetBossState(DATA_EARTHRAGER_PTAH) == DONE ? -1 : DAY);
                else // All other transits.
                    transit->SetRespawnTime(GetBossState(DATA_ANRAPHET) == DONE ? -1 : DAY);
            }

            void SetupVaultOfLightsWarden()
            {
                if (GetBossState(DATA_ANRAPHET) == DONE)
                    return;

                std::array<uint32, MAX_VAULT_OF_LIGHTS_WARDEN> wardenEntries =
                {
                    NPC_FIRE_WARDEN,
                    NPC_EARTH_WARDEN,
                    NPC_WATER_WARDEN,
                    NPC_AIR_WARDEN
                };

                // Wardens are always being randomized on each reset
                Trinity::Containers::RandomShuffle(wardenEntries);

                for (uint8 i = 0; i < MAX_VAULT_OF_LIGHTS_WARDEN; ++i)
                {
                    if (Creature* warden = instance->SummonCreature(wardenEntries[i], VaultOfLightsWardenPositions[i]))
                        if (warden->IsAIEnabled)
                            warden->AI()->SetData(DATA_WARDEN_NUMBER, i);
                }
            }

            void ActivateLightMachine(uint8 number)
            {
                if (GameObject* lightMachine = GetGameObject(DATA_LIGHT_MACHINE_1 + number))
                    lightMachine->SetGoState(GO_STATE_ACTIVE);

                _events.ScheduleEvent(EVENT_ACTIVATE_LASER_BEAMS_1 + number, 9s);
            }

            EventMap _events;
            GuidSet _transitDeviceGUIDs;
            GuidSet _hooCamelGUIDs;
            GuidSet _isisetTrashGUIDs;
            GuidSet _caveInStalkerGUIDs;
            GuidSet _anhuurEncounterGUIDs;
            GuidSet _beetleStalkerGUIDS;
            uint8 _vaultOfLightState;
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
