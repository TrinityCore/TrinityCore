/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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
SDName: Instance Trial of the Champion
SDComment: missing fireworks when boss encounter is set to done
SDCategory: Trial Of the Champion
EndScriptData */

#include "InstanceScript.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "trial_of_the_champion.h"

ObjectData const creatureData[] =
{
    { NPC_ARELAS,       DATA_ANNOUNCER        },
    { NPC_JAEREN,       DATA_ANNOUNCER        },
    { NPC_TIRION,       DATA_TIRION           },
    { NPC_VARIAN,       DATA_VARIAN           },
    { NPC_JAINA,        DATA_JAINA            },
    { NPC_GARROSH,      DATA_GARROSH          },
    { NPC_THRALL,       DATA_THRALL           },
    { NPC_BLACK_KNIGHT, DATA_THE_BLACK_KNIGHT },
    { 0,                0                     } // END
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

class instance_trial_of_the_champion : public InstanceMapScript
{
public:
    instance_trial_of_the_champion() : InstanceMapScript(ToCScriptName, 650) { }

    struct instance_trial_of_the_champion_InstanceMapScript : public InstanceScript
    {
        instance_trial_of_the_champion_InstanceMapScript(Map* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            LoadObjectData(creatureData, gameObjectData);

            TeamInInstance = 0;
            uiArgentSoldierDeaths = 0;
        }

        uint32 GetCreatureEntry(uint32 /*guidLow*/, CreatureData const* data) override
        {
            if (!TeamInInstance)
            {
                Map::PlayerList const& players = instance->GetPlayers();
                if (!players.isEmpty())
                    if (Player* player = players.begin()->GetSource())
                        TeamInInstance = player->GetTeam();
            }

            uint32 entry = data->id;
            switch (entry)
            {
                case VEHICLE_ARGENT_WARHORSE_COSMETIC:
                    if (TeamInInstance == ALLIANCE)
                        return VEHICLE_ARGENT_BATTLEWORG_COSMETIC;
                    break;
                case VEHICLE_ARGENT_WARHORSE:
                    if (TeamInInstance == HORDE)
                        return VEHICLE_ARGENT_BATTLEWORG;
                    break;
                case VEHICLE_ARGENT_BATTLEWORG:
                    if (TeamInInstance == ALLIANCE)
                        return VEHICLE_ARGENT_WARHORSE;
                    break;
                case VEHICLE_ARGENT_BATTLEWORG_COSMETIC:
                    if (TeamInInstance == HORDE)
                        return VEHICLE_ARGENT_WARHORSE_COSMETIC;
                    break;
                default:
                    break;
            }

            return entry;
        }

        void OnCreatureCreate(Creature* creature) override
        {
            if (!TeamInInstance)
            {
                Map::PlayerList const& players = instance->GetPlayers();
                if (!players.isEmpty())
                    if (Player* player = players.begin()->GetSource())
                        TeamInInstance = player->GetTeam();
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
                // Coliseum Announcer || Just NPC_JAEREN must be spawned.
                case NPC_JAEREN:
                    if (TeamInInstance == ALLIANCE)
                        creature->UpdateEntry(NPC_ARELAS);
                    break;
                case VEHICLE_ARGENT_WARHORSE_COSMETIC:
                case VEHICLE_ARGENT_WARHORSE:
                case VEHICLE_ARGENT_BATTLEWORG:
                case VEHICLE_ARGENT_BATTLEWORG_COSMETIC:
                    VehicleList.push_back(creature->GetGUID());
                    break;
                case NPC_EADRIC:
                case NPC_PALETRESS:
                    uiArgentChampionGUID = creature->GetGUID();
                    break;
                case VEHICLE_BLACK_KNIGHT:
                    uiBlackKnightVehicleGUID = creature->GetGUID();
                    break;
                // Setting passive and unattackable flags to Lesser Champions and Grand Champions' vehicles
                case VEHICLE_DARNASSUS_CHAMPION:
                case VEHICLE_EXODAR_CHAMPION:
                case VEHICLE_STORMWIND_CHAMPION:
                case VEHICLE_GNOMEREGAN_CHAMPION:
                case VEHICLE_IRONFORGE_CHAMPION:
                case VEHICLE_UNDERCITY_CHAMPION:
                case VEHICLE_THUNDER_BLUFF_CHAMPION:
                case VEHICLE_ORGRIMMAR_CHAMPION:
                case VEHICLE_SILVERMOON_CHAMPION:
                case VEHICLE_SENJIN_CHAMPION:
                case VEHICLE_AMBROSE_BOLTSPARK_MOUNT:
                case VEHICLE_COLOSOS_MOUNT:
                case VEHICLE_MARSHAL_JACOB_ALERIUS_MOUNT:
                case VEHICLE_MOKRA_SKILLCRUSHER_MOUNT:
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

        void SetGrandChampionData(Creature* cr)
        {
            if (!uiGrandChampion1GUID)
                uiGrandChampion1GUID = cr->GetGUID();
            else if (!uiGrandChampion2GUID)
                uiGrandChampion2GUID = cr->GetGUID();
            else if (!uiGrandChampion3GUID)
                uiGrandChampion3GUID = cr->GetGUID();
        }

        void SetData(uint32 uiType, uint32 uiData) override
        {
            switch (uiType)
            {
                case DATA_REMOVE_VEHICLES:
                {
                    for (ObjectGuid const& guid : VehicleList)
                        if (Creature* summon = instance->GetCreature(guid))
                            summon->DespawnOrUnsummon();

                    // We must remove defense spells from players
                    Map::PlayerList const& players = instance->GetPlayers();
                    for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                    {
                        Player* plr = itr->GetSource();
                        plr->RemoveAura(62552); // Actual defense spell
                        plr->RemoveAura(63130); // Shield Level 1 (visual only)
                        plr->RemoveAura(63131); // Shield Level 2 (visual only)
                        plr->RemoveAura(63132); // Shield Level 3 (visual only)
                    }
                    break;
                }
                case DATA_ARGENT_SOLDIER_DEFEATED:
                    uiArgentSoldierDeaths = uiData;
                    if (uiArgentSoldierDeaths == 9)
                    {
                        if (Creature* pBoss = instance->GetCreature(uiArgentChampionGUID))
                        {
                            pBoss->setFaction(16);
                            pBoss->SetHomePosition(747.02f, 637.65f, 411.57f, centerOrientation);
                            pBoss->GetMotionMaster()->MovePoint(1, pBoss->GetHomePosition());
                        }
                    }
                    break;
                default:
                    break;
            }
        }

        bool SetBossState(uint32 type, EncounterState state) override
        {
            if (!InstanceScript::SetBossState(type, state))
                return false;

            switch (type)
            {
                case DATA_GRAND_CHAMPIONS:
                    if (state == DONE)
                    {
                        if (Creature* pAnnouncer = GetCreature(DATA_ANNOUNCER))
                        {
                            // On heroic mode we must bind players to the instance
                            if (instance->IsHeroic())
                            {
                                Map::PlayerList const &players = instance->GetPlayers();
                                for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                                {
                                    Player* plr = itr->GetSource();
                                    if (!plr->IsGameMaster())
                                    {
                                        if (instance->ToInstanceMap())
                                            instance->ToInstanceMap()->PermBindAllPlayers();
                                        break;
                                    }
                                }
                            }
                            pAnnouncer->GetMotionMaster()->MovePoint(1, announcerWaitPos);
                            pAnnouncer->AI()->SetData(DATA_GRAND_CHAMPIONS_DONE, 0);
                            if (GameObject* cache = GetGameObject(DATA_CHAMPION_S_CACHE))
                            {
                                cache->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                                cache->SetRespawnTime(1 * DAY);
                            }
                        }
                    }
                    break;
                case DATA_EADRIC_THE_PURE:
                case DATA_ARGENT_CONFESSOR_PALETRESS:
                    if (state == SPECIAL)
                    {
                        if (Creature* pChampion = instance->GetCreature(uiArgentChampionGUID))
                        {
                            pChampion->InterruptNonMeleeSpells(true);
                            pChampion->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            pChampion->SetReactState(REACT_PASSIVE);
                            pChampion->SetHealth(1);
                            pChampion->CombatStop(true);
                            pChampion->setRegeneratingHealth(false);
                            pChampion->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);
                            pChampion->SetHomePosition(745.87f, 625.88f, 411.17f, pChampion->GetHomePosition().GetOrientation());
                            pChampion->GetMotionMaster()->MoveTargetedHome();
                        }
                    }
                    else if (state == DONE)
                    {
                        if (Creature* pAnnouncer = GetCreature(DATA_ANNOUNCER))
                        {
                            // On heroic mode we must bind players to the instance
                            if (instance->IsHeroic())
                            {
                                Map::PlayerList const &players = instance->GetPlayers();
                                for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                                {
                                    Player* plr = itr->GetSource();
                                    if (!plr->IsGameMaster())
                                    {
                                        if (instance->ToInstanceMap())
                                            instance->ToInstanceMap()->PermBindAllPlayers();
                                        break;
                                    }
                                }
                            }
                            pAnnouncer->GetMotionMaster()->MovePoint(1, announcerWaitPos);
                            if (type == DATA_EADRIC_THE_PURE)
                            {
                                if (GameObject* cache = GetGameObject(DATA_EADRIC_S_CACHE))
                                {
                                    cache->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                                    cache->SetRespawnTime(1 * DAY);
                                }
                            }
                            else
                            {
                                if (GameObject* cache = GetGameObject(DATA_CONFESSOR_S_CACHE))
                                {
                                    cache->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                                    cache->SetRespawnTime(1 * DAY);
                                }
                            }
                        }
                    }
                    break;
                case DATA_THE_BLACK_KNIGHT:
                    if (state == DONE)
                    {
                        if (Creature* pAnnouncer = GetCreature(DATA_ANNOUNCER))
                            pAnnouncer->AI()->SetData(DATA_BLACK_KNIGHT_DONE, 0);
                    }
                    break;
                default:
                    break;
            }
            return true;
        }

        uint32 GetData(uint32 type) const override
        {
            switch (type)
            {
                case DATA_TEAM_IN_INSTANCE:
                    return TeamInInstance;
                case DATA_ARGENT_SOLDIER_DEFEATED:
                    return uiArgentSoldierDeaths;
                default:
                    break;
            }
            return 0;
        }

        ObjectGuid GetGuidData(uint32 type) const override
        {
            switch (type)
            {
                case DATA_GRAND_CHAMPION_1: return uiGrandChampion1GUID;
                case DATA_GRAND_CHAMPION_2: return uiGrandChampion2GUID;
                case DATA_GRAND_CHAMPION_3: return uiGrandChampion3GUID;

                case DATA_GRAND_CHAMPION_VEHICLE_1: return uiGrandChampionVehicle1GUID;
                case DATA_GRAND_CHAMPION_VEHICLE_2: return uiGrandChampionVehicle2GUID;
                case DATA_GRAND_CHAMPION_VEHICLE_3: return uiGrandChampionVehicle3GUID;

                case DATA_ARGENT_CHAMPION: return uiArgentChampionGUID;

                case DATA_BLACK_KNIGHT_VEHICLE: return uiBlackKnightVehicleGUID;
            }

            return GetObjectGuid(type);
        }

        void SetGuidData(uint32 uiType, ObjectGuid uiData) override
        {
            switch (uiType)
            {
                case DATA_GRAND_CHAMPION_VEHICLE_1:
                    uiGrandChampionVehicle1GUID = uiData;
                    break;
                case DATA_GRAND_CHAMPION_VEHICLE_2:
                    uiGrandChampionVehicle2GUID = uiData;
                    break;
                case DATA_GRAND_CHAMPION_VEHICLE_3:
                    uiGrandChampionVehicle3GUID = uiData;
                    break;
            }
        }

    private:
        ObjectGuid uiGrandChampionVehicle1GUID;
        ObjectGuid uiGrandChampionVehicle2GUID;
        ObjectGuid uiGrandChampionVehicle3GUID;
        ObjectGuid uiGrandChampion1GUID;
        ObjectGuid uiGrandChampion2GUID;
        ObjectGuid uiGrandChampion3GUID;
        ObjectGuid uiArgentChampionGUID;
        ObjectGuid uiBlackKnightVehicleGUID;

        GuidList VehicleList;

        uint32 TeamInInstance;
        uint8 uiArgentSoldierDeaths;
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
