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
    { GO_DOODAD_ULDUM_DOOR_15,          DATA_ANHUUR_DOOR                },
    { GO_VAULT_OF_LIGHTS_DOOR,          DATA_VAULT_OF_LIGHTS_DOOR       },
    { GO_DOODAD_ULDUM_LIGHTMACHINE_02,  DATA_LIGHTMACHINE_EARTH         },
    { GO_DOODAD_ULDUM_LIGHTMACHINE_01,  DATA_LIGHTMACHINE_AIR           },
    { GO_DOODAD_ULDUM_LIGHTMACHINE_04,  DATA_LIGHTMACHINE_FIRE          },
    { GO_DOODAD_ULDUM_LIGHTMACHINE_03,  DATA_LIGHTMACHINE_WATER         },
    { GO_DOODAD_ULDUM_LASERBEAMS01,     DATA_LASERBEAMS_EARTH           },
    { GO_DOODAD_ULDUM_LASERBEAMS_01,    DATA_LASERBEAMS_AIR             },
    { GO_DOODAD_ULDUM_LASERBEAMS_03,    DATA_LASERBEAMS_FIRE            },
    { GO_DOODAD_ULDUM_LASERBEAMS_02,    DATA_LASERBEAMS_WATER           },
    { GO_SUN_MIRROR,                    DATA_ANRAPHET_SUN_MIRROR        },
    { GO_ANRAPHET_DOOR,                 DATA_ANRAPHET_DOOR              },
    { GO_LIFT_OF_THE_MAKERS,            DATA_LIFT_OF_THE_MAKERS         },
    { 0,                                0                               } //END
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
                LoadDoorData(doorData);
                LoadObjectData(creatureData, gameObjectData);
            }

            void Initialize()
            {
                _brannIntroStarted = 0;
                _deadElementals = 0;
                _anraphetInitialized = false;
                _vaultOfLightState = NOT_STARTED;
            }

            void OnPlayerEnter(Player* /*player*/) override
            {
                if (!_anraphetInitialized)
                {
                    if (GetData(DATA_VAULT_OF_LIGHTS) != DONE)
                    {
                        if (Creature* anraphet = instance->SummonCreature(BOSS_ANRAPHET, AnraphetSpawnPos))
                        {
                            anraphet->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNK_6 | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_SELECTABLE);
                            anraphet->SetReactState(REACT_PASSIVE);
                        }
                    }
                    else
                        instance->SummonCreature(BOSS_ANRAPHET, AnraphetRespawnPos);

                    _anraphetInitialized = true;
                }
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
                        go->SetTransportState(GO_STATE_TRANSPORT_STOPPED, 0);
                        break;
                    case GO_VAULT_OF_LIGHTS_DOOR:
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
                    case GO_ANRAPHET_DOOR:
                        go->SetFarVisible(true);
                        go->setActive(true);
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
                    default:
                        break;
                }

                go->SetFarVisible(true);
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
                        creature->SetInCombatWithZone();
                        if (Creature* ptah = GetCreature(DATA_EARTHRAGER_PTAH))
                            ptah->AI()->JustSummoned(creature);
                        break;
                    case BOSS_ANRAPHET:
                    case NPC_BRANN_BRONZEBEARD_0:
                        creature->setActive(true);
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
                        if (GetBossState(DATA_VAULT_OF_LIGHTS) == DONE)
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
                    case NPC_CAVE_IN_STALKER:
                        if (creature->GetPositionZ() <= 70.0f)
                            _caveInStalkerGUIDs.insert(creature->GetGUID());
                        break;
                    default:
                        break;
                }
            }

            void SetData(uint32 data, uint32 value) override
            {
                switch (data)
                {
                    case DATA_UPDATE_LASERBEAMS:
                        UpdateAllLaserBeams();
                        break;
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
                            if (Creature* beetleStalker = instance->GetCreature(guid))
                                if (-400.f < beetleStalker->GetPositionY() && beetleStalker->GetPositionY() < -390.f) // 2 stalkers in the middle
                                    beetleStalker->CastSpell(beetleStalker, SPELL_SUMMON_DUSTBONE_HORROR);
                                else
                                    beetleStalker->CastSpell(beetleStalker, SPELL_BEETLE_BURROW);
                        break;
                    case DATA_VAULT_OF_LIGHTS:
                        _vaultOfLightState = value;

                        if (value == IN_PROGRESS)
                        {
                            if (GameObject* door = GetGameObject(DATA_VAULT_OF_LIGHTS_DOOR))
                                door->SetGoState(GO_STATE_ACTIVE);

                            DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_VAULT_OF_LIGHTS_START_EVENT);
                        }
                        else if (value == DONE)
                            DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET2, SPELL_VAULT_OF_LIGHTS_CREDIT);

                        SaveToDB();
                        break;
                    default:
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
                    case NPC_FIRE_WARDEN:
                    case NPC_EARTH_WARDEN:
                    case NPC_WATER_WARDEN:
                    case NPC_AIR_WARDEN:
                        _deadElementals++;
                        if (Creature* brann = GetCreature(DATA_BRANN_0))
                            brann->AI()->DoAction(ACTION_ELEMENTAL_DIED);
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
                        default:
                            break;
                    }
                }
            }

            void WriteSaveDataMore(std::ostringstream& data) override
            {
                data << _vaultOfLightState << ' '
                    << _deadElementals;
            }

            void ReadSaveDataMore(std::istringstream& data) override
            {
                data >> _vaultOfLightState;
                data >> _deadElementals;
            }

        private:
            
            void UpdateAllLightMachines()
            {
            }

            // Activated 9 seconds after warden dies (on SetData DATA_UPDATE_LASERBEAMS, called by Brann).
            void UpdateAllLaserBeams()
            {
            }

            void UpdateTransitDevice(GameObject* transit)
            {
                if (transit->GetPositionX() < -900.f) // The southernmost transit: x = -934.576
                    transit->SetRespawnTime(GetBossState(DATA_TEMPLE_GUARDIAN_ANHUUR) == DONE ? -1 : DAY);
                else if (transit->GetPositionY() < -300.f) // The two easternmost transits: y = -337.028, y = -686.826
                    transit->SetRespawnTime(GetBossState(DATA_EARTHRAGER_PTAH) == DONE ? -1 : DAY);
                else // All other transits.
                    transit->SetRespawnTime(GetBossState(DATA_ANRAPHET) == DONE ? -1 : DAY);
            }

            EventMap _events;
            GuidSet _transitDeviceGUIDs;
            GuidSet _hooCamelGUIDs;
            GuidSet _isisetTrashGUIDs;
            GuidSet _caveInStalkerGUIDs;
            GuidSet _beetleStalkerGUIDS;
            uint32 _brannIntroStarted;
            uint32 _deadElementals;
            uint32 _isisetPhase;
            uint32 _isisetAstralRainAlive;
            uint32 _isisetCelestialCallAlive;
            uint32 _isisetVeilOfSkyAlive;
            uint8 _vaultOfLightState;
            bool _anraphetInitialized;
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
