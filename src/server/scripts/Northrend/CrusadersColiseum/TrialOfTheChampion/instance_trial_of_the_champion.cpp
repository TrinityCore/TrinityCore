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

#include "GameObject.h"
#include "InstanceScript.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "trial_of_the_champion.h"

ObjectData const creatureData[] =
{
    { NPC_ARELAS,       DATA_ANNOUNCER    },
    { NPC_JAEREN,       DATA_ANNOUNCER    },
    { NPC_TIRION,       DATA_TIRION       },
    { NPC_VARIAN,       DATA_VARIAN       },
    { NPC_JAINA,        DATA_JAINA        },
    { NPC_GARROSH,      DATA_GARROSH      },
    { NPC_THRALL,       DATA_THRALL       },
    { NPC_BLACK_KNIGHT, DATA_BLACK_KNIGHT },
    { 0,                0                 } // END
};

ObjectData const gameObjectData[] =
{
    { GO_MAIN_GATE,           DATA_MAIN_GATE         },
    { GO_CHAMPION_S_CACHE,    DATA_CHAMPION_S_CACHE  },
    { GO_CHAMPION_S_CACHE_H,  DATA_CHAMPION_S_CACHE  },
    { GO_EADRIC_S_CACHE,      DATA_EADRIC_S_CACHE    },
    { GO_EADRIC_S_CACHE_H,    DATA_EADRIC_S_CACHE    },
    { GO_CONFESSOR_S_CACHE,   DATA_CONFESSOR_S_CACHE },
    { GO_CONFESSOR_S_CACHE_H, DATA_CONFESSOR_S_CACHE },
    { 0,                      0                      } // END
};

DoorData const doorData[] =
{
    { GO_NORTH_PORTCULLIS, DATA_GRAND_CHAMPIONS,  DOOR_TYPE_ROOM },
    { GO_NORTH_PORTCULLIS, DATA_ARGENT_CHALLENGE, DOOR_TYPE_ROOM },
    { GO_NORTH_PORTCULLIS, DATA_BLACK_KNIGHT,     DOOR_TYPE_ROOM },
    { 0,                   0,                     DOOR_TYPE_ROOM } // END
};

uint8 const GrandChampionsCount = 3;

class instance_trial_of_the_champion : public InstanceMapScript
{
    public:
        instance_trial_of_the_champion() : InstanceMapScript(ToCScriptName, 650) { }

        struct instance_trial_of_the_champion_InstanceMapScript : public InstanceScript
        {
            instance_trial_of_the_champion_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(MAX_ENCOUNTER);
                LoadObjectData(creatureData, gameObjectData);
                LoadDoorData(doorData);

                _teamInInstance = 0;
                _argentSoldierDeaths = 0;
            }

            uint32 GetCreatureEntry(uint32 /*guidLow*/, CreatureData const* data) override
            {
                uint32 entry = data->id;
                switch (entry)
                {
                    case NPC_JAEREN:
                        if (_teamInInstance == ALLIANCE)
                            return NPC_ARELAS;
                        break;
                    case VEHICLE_ARGENT_WARHORSE_COSMETIC:
                        if (_teamInInstance == ALLIANCE)
                            return VEHICLE_ARGENT_WARHORSE_A;
                        break;
                    case VEHICLE_ARGENT_BATTLEWORG_H:
                        if (_teamInInstance == ALLIANCE)
                            return VEHICLE_ARGENT_BATTLEWORG_COSMETIC;
                        break;
                    default:
                        break;
                }

                return entry;
            }

            void OnCreatureCreate(Creature* creature) override
            {
                if (!_teamInInstance)
                {
                    Map::PlayerList const& players = instance->GetPlayers();
                    if (!players.isEmpty())
                        if (Player* player = players.begin()->GetSource())
                            _teamInInstance = player->GetTeam();
                }

                switch (creature->GetEntry())
                {
                    case NPC_MOKRA:
                    case NPC_ERESSEA:
                    case NPC_RUNOK:
                    case NPC_ZULTORE:
                    case NPC_VISCERI:
                    case NPC_JACOB:
                    case NPC_AMBROSE:
                    case NPC_COLOSOS:
                    case NPC_JAELYNE:
                    case NPC_LANA:
                        SetGrandChampionData(creature);
                        break;
                    case VEHICLE_ARGENT_WARHORSE_COSMETIC:
                    case VEHICLE_ARGENT_WARHORSE_A:
                    case VEHICLE_ARGENT_BATTLEWORG_COSMETIC:
                    case VEHICLE_ARGENT_BATTLEWORG_H:
                        _vehicles.push_back(creature->GetGUID());
                        break;

                    case NPC_EADRIC:
                    case NPC_PALETRESS:
                        _argentChampionGUID = creature->GetGUID();
                        break;
                    case VEHICLE_BLACK_KNIGHT:
                        _blackKnightVehicleGUID = creature->GetGUID();
                        break;
                    // Setting passive and unattackable flags to Lesser Champions and Grand Champions' vehicles
                    case NPC_DARNASSUS_CHAMPION:
                    case NPC_EXODAR_CHAMPION:
                    case NPC_STORMWIND_CHAMPION:
                    case NPC_GNOMEREGAN_CHAMPION:
                    case NPC_IRONFORGE_CHAMPION:
                    case NPC_UNDERCITY_CHAMPION:
                    case NPC_THUNDER_BLUFF_CHAMPION:
                    case NPC_ORGRIMMAR_CHAMPION:
                    case NPC_SILVERMOON_CHAMPION:
                    case NPC_SEN_JIN_CHAMPION:
                    case VEHICLE_AMBROSE_BOLTSPARK_MOUNT:
                    case VEHICLE_COLOSOS_MOUNT:
                    case VEHICLE_MARSHAL_JACOB_ALERIUS_MOUNT:
                    case VEHICLE_MOKRA_SKULLCRUSHER_MOUNT:
                    case VEHICLE_ERESSEA_DAWNSINGER_MOUNT:
                    case VEHICLE_RUNOK_WILDMANE_MOUNT:
                    case VEHICLE_ZUL_TORE_MOUNT:
                    case VEHICLE_EVENSONG_MOUNT:
                    case VEHICLE_DEATHSTALKER_VESCERI_MOUNT:
                    case VEHICLE_LANA_STOUTHAMMER_MOUNT:
                        creature->SetReactState(REACT_PASSIVE);
                        creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        break;
                    default:
                        break;
                }

                InstanceScript::OnCreatureCreate(creature);
            }

            void SetGrandChampionData(Creature* creature)
            {
                for (uint8 i = 0; i < GrandChampionsCount; ++i)
                {
                    if (!_grandChampionGUIDs[i])
                    {
                        _grandChampionGUIDs[i] = creature->GetGUID();
                        break;
                    }
                }
            }

            bool SetBossState(uint32 id, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(id, state))
                    return false;

                switch (id)
                {
                    case DATA_GRAND_CHAMPIONS:
                        if (state == DONE)
                        {
                            if (Creature* announcer = GetCreature(DATA_ANNOUNCER))
                            {
                                // On heroic mode we must bind players to the instance
                                if (instance->IsHeroic())
                                    instance->ToInstanceMap()->PermBindAllPlayers();

                                announcer->GetMotionMaster()->MovePoint(1, announcerWaitPos);
                                announcer->AI()->SetData(DATA_GRAND_CHAMPIONS_DONE, 0);

                                DoRespawnGameObject(GetObjectGuid(DATA_CHAMPION_S_CACHE), 1 * DAY);
                                if (GameObject* cache = GetGameObject(DATA_CHAMPION_S_CACHE))
                                    cache->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                            }
                        }
                        break;
                    case DATA_ARGENT_CHALLENGE:
                        if (state == SPECIAL)
                        {
                            if (Creature* champion = instance->GetCreature(_argentChampionGUID))
                            {
                                champion->InterruptNonMeleeSpells(true);
                                champion->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                                champion->SetReactState(REACT_PASSIVE);
                                champion->SetHealth(1);
                                champion->CombatStop(true);
                                champion->SetRegenerateHealth(false);
                                champion->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);
                                champion->SetHomePosition(745.87f, 625.88f, 411.17f, champion->GetHomePosition().GetOrientation());
                                champion->GetMotionMaster()->MoveTargetedHome();
                            }
                        }
                        else if (state == DONE)
                        {
                            if (Creature* announcer = GetCreature(DATA_ANNOUNCER))
                            {
                                // On heroic mode we must bind players to the instance
                                if (instance->IsHeroic())
                                    instance->ToInstanceMap()->PermBindAllPlayers();

                                announcer->GetMotionMaster()->MovePoint(1, announcerWaitPos);

                                uint32 dataType;
                                switch (_argentChampionGUID.GetEntry())
                                {
                                    case NPC_EADRIC:
                                        dataType = DATA_EADRIC_S_CACHE;
                                        break;
                                    case NPC_PALETRESS:
                                        dataType = DATA_CONFESSOR_S_CACHE;
                                        break;
                                    default:
                                        ABORT();
                                        break;
                                }

                                DoRespawnGameObject(GetObjectGuid(dataType), 1 * DAY);
                                if (GameObject* cache = GetGameObject(dataType))
                                    cache->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                            }
                        }
                        break;
                    case DATA_BLACK_KNIGHT:
                        if (state == DONE)
                        {
                            if (Creature* announcer = GetCreature(DATA_ANNOUNCER))
                                announcer->AI()->SetData(DATA_BLACK_KNIGHT_DONE, 0);
                        }
                        break;
                    default:
                        break;
                }
                return true;
            }

            void SetData(uint32 type, uint32 data) override
            {
                switch (type)
                {
                    case DATA_REMOVE_VEHICLES:
                    {
                        for (ObjectGuid const& guid : _vehicles)
                            if (Creature* vehicle = instance->GetCreature(guid))
                                vehicle->DespawnOrUnsummon();

                        // We must remove defense spells from players
                        Map::PlayerList const& players = instance->GetPlayers();
                        for (auto itr = players.begin(); itr != players.end(); ++itr)
                        {
                            Player* plr = itr->GetSource();
                            plr->RemoveAurasDueToSpell(62552); // Actual defense spell
                            plr->RemoveAurasDueToSpell(63130); // Shield Level 1 (visual only)
                            plr->RemoveAurasDueToSpell(63131); // Shield Level 2 (visual only)
                            plr->RemoveAurasDueToSpell(63132); // Shield Level 3 (visual only)
                        }
                        break;
                    }
                    case DATA_ARGENT_SOLDIER_DEFEATED:
                        _argentSoldierDeaths = data;
                        if (_argentSoldierDeaths == 9)
                        {
                            if (Creature* boss = instance->GetCreature(_argentChampionGUID))
                            {
                                boss->SetFaction(FACTION_MONSTER_2);
                                boss->SetHomePosition(747.02f, 637.65f, 411.57f, centerOrientation);
                                boss->GetMotionMaster()->MovePoint(1, boss->GetHomePosition());
                            }
                        }
                        break;
                    default:
                        break;
                }
            }

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_TEAM_IN_INSTANCE:
                        return _teamInInstance;
                    case DATA_ARGENT_SOLDIER_DEFEATED:
                        return _argentSoldierDeaths;
                    default:
                        break;
                }

                return 0;
            }

            ObjectGuid GetGuidData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_GRAND_CHAMPION_1:
                    case DATA_GRAND_CHAMPION_2:
                    case DATA_GRAND_CHAMPION_3:
                        return _grandChampionGUIDs[type - DATA_GRAND_CHAMPION_1];
                    case DATA_GRAND_CHAMPION_VEHICLE_1:
                    case DATA_GRAND_CHAMPION_VEHICLE_2:
                    case DATA_GRAND_CHAMPION_VEHICLE_3:
                        return _grandChampionVehicleGUIDs[type - DATA_GRAND_CHAMPION_VEHICLE_1];
                    case DATA_ARGENT_CHAMPION:
                        return _argentChampionGUID;
                    case DATA_BLACK_KNIGHT_VEHICLE:
                        return _blackKnightVehicleGUID;
                    default:
                        break;
                }

                return InstanceScript::GetGuidData(type);
            }

            void SetGuidData(uint32 type, ObjectGuid data) override
            {
                switch (type)
                {
                    case DATA_GRAND_CHAMPION_VEHICLE_1:
                    case DATA_GRAND_CHAMPION_VEHICLE_2:
                    case DATA_GRAND_CHAMPION_VEHICLE_3:
                        _grandChampionVehicleGUIDs[type - DATA_GRAND_CHAMPION_VEHICLE_1] = data;
                        break;
                    default:
                        break;
                }
            }

        private:
            ObjectGuid _grandChampionVehicleGUIDs[GrandChampionsCount];
            ObjectGuid _grandChampionGUIDs[GrandChampionsCount];

            ObjectGuid _argentChampionGUID;
            ObjectGuid _blackKnightVehicleGUID;

            GuidVector _vehicles;

            uint32 _teamInInstance;
            uint8 _argentSoldierDeaths;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_trial_of_the_champion_InstanceMapScript(map);
        }
};

void AddSC_instance_trial_of_the_champion()
{
    new instance_trial_of_the_champion();
}