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
#include "AreaBoundary.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Log.h"
#include "Map.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "TemporarySummon.h"
#include "trial_of_the_crusader.h"

 // ToDo: Remove magic numbers of events

BossBoundaryData const boundaries =
{
    { DATA_NORTHREND_BEASTS,  new CircleBoundary(Position(563.26f, 139.6f), 75.0)        },
    { DATA_JARAXXUS,          new CircleBoundary(Position(563.26f, 139.6f), 75.0)        },
    { DATA_FACTION_CRUSADERS, new CircleBoundary(Position(563.26f, 139.6f), 75.0)        },
    { DATA_TWIN_VALKIRIES,    new CircleBoundary(Position(563.26f, 139.6f), 75.0)        },
    { DATA_ANUBARAK,          new EllipseBoundary(Position(746.0f, 135.0f), 100.0, 75.0) }
};

ObjectData const creatureData[] =
{
    { NPC_GORMOK,                   DATA_GORMOK_THE_IMPALER    },
    { NPC_ACIDMAW,                  DATA_ACIDMAW               },
    { NPC_DREADSCALE,               DATA_DREADSCALE            },
    { NPC_ICEHOWL,                  DATA_ICEHOWL               },
    { NPC_BEASTS_COMBAT_STALKER,    DATA_BEASTS_COMBAT_STALKER },
    { NPC_FURIOUS_CHARGE_STALKER,   DATA_FURIOUS_CHARGE        },
    { NPC_JARAXXUS,                 DATA_JARAXXUS              },
    { NPC_CHAMPIONS_CONTROLLER,     DATA_FACTION_CRUSADERS     },
    { NPC_FJOLA_LIGHTBANE,          DATA_FJOLA_LIGHTBANE       },
    { NPC_EYDIS_DARKBANE,           DATA_EYDIS_DARKBANE        },
    { NPC_LICH_KING,                DATA_LICH_KING             },
    { NPC_ANUBARAK,                 DATA_ANUBARAK              },
    { NPC_TIRION_FORDRING,          DATA_FORDRING              },
    { NPC_TIRION_FORDRING_ANUBARAK, DATA_FORDRING_ANUBARAK     },
    { NPC_VARIAN,                   DATA_VARIAN                },
    { NPC_GARROSH,                  DATA_GARROSH               },
    { NPC_FIZZLEBANG,               DATA_FIZZLEBANG            },
    { NPC_LICH_KING_VOICE,          DATA_LICH_KING_VOICE       },
    { 0,                            0                          } // END
};

ObjectData const gameObjectData[] =
{
    { GO_CRUSADERS_CACHE_10,    DATA_CRUSADERS_CHEST },
    { GO_CRUSADERS_CACHE_25,    DATA_CRUSADERS_CHEST },
    { GO_CRUSADERS_CACHE_10_H,  DATA_CRUSADERS_CHEST },
    { GO_CRUSADERS_CACHE_25_H,  DATA_CRUSADERS_CHEST },
    { GO_ARGENT_COLISEUM_FLOOR, DATA_COLISEUM_FLOOR  },
    { GO_MAIN_GATE_DOOR,        DATA_MAIN_GATE       },
    { GO_EAST_PORTCULLIS,       DATA_EAST_PORTCULLIS },
    { GO_WEB_DOOR,              DATA_WEB_DOOR        },
    { GO_TRIBUTE_CHEST_10H_25,  DATA_TRIBUTE_CHEST   },
    { GO_TRIBUTE_CHEST_10H_45,  DATA_TRIBUTE_CHEST   },
    { GO_TRIBUTE_CHEST_10H_50,  DATA_TRIBUTE_CHEST   },
    { GO_TRIBUTE_CHEST_10H_99,  DATA_TRIBUTE_CHEST   },
    { GO_TRIBUTE_CHEST_25H_25,  DATA_TRIBUTE_CHEST   },
    { GO_TRIBUTE_CHEST_25H_45,  DATA_TRIBUTE_CHEST   },
    { GO_TRIBUTE_CHEST_25H_50,  DATA_TRIBUTE_CHEST   },
    { GO_TRIBUTE_CHEST_25H_99,  DATA_TRIBUTE_CHEST   },
    { 0,                        0                    } // END
};

DoorData const doorData[] =
{
    { GO_EAST_PORTCULLIS, DATA_NORTHREND_BEASTS,  EncounterDoorBehavior::OpenWhenNotInProgress },
    { GO_EAST_PORTCULLIS, DATA_JARAXXUS,          EncounterDoorBehavior::OpenWhenNotInProgress },
    { GO_EAST_PORTCULLIS, DATA_FACTION_CRUSADERS, EncounterDoorBehavior::OpenWhenNotInProgress },
    { GO_EAST_PORTCULLIS, DATA_TWIN_VALKIRIES,    EncounterDoorBehavior::OpenWhenNotInProgress },
    { GO_EAST_PORTCULLIS, DATA_LICH_KING,         EncounterDoorBehavior::OpenWhenNotInProgress },
    { GO_WEB_DOOR,        DATA_ANUBARAK,          EncounterDoorBehavior::OpenWhenNotInProgress },
    { 0,                  0,                      EncounterDoorBehavior::OpenWhenNotInProgress } // END
};

DungeonEncounterData const encounters[] =
{
    { DATA_NORTHREND_BEASTS, {{ 1088 }} },
    { DATA_JARAXXUS, {{ 1087 }} },
    { DATA_FACTION_CRUSADERS, {{ 1086 }} },
    { DATA_TWIN_VALKIRIES, {{ 1089 }} },
    { DATA_ANUBARAK, {{ 1085 }} }
};

class instance_trial_of_the_crusader : public InstanceMapScript
{
    public:
        instance_trial_of_the_crusader() : InstanceMapScript(ToCrScriptName, 649) { }

        struct instance_trial_of_the_crusader_InstanceMapScript : public InstanceScript
        {
            instance_trial_of_the_crusader_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadBossBoundaries(boundaries);
                LoadObjectData(creatureData, gameObjectData);
                LoadDoorData(doorData);
                LoadDungeonEncounterData(encounters);
                EventStage = 0;
                NorthrendBeasts = NOT_STARTED;
                NorthrendBeastsCount = 4;
                EventTimer = 1000;
                NotOneButTwoJormungarsTimer = 0;
                ResilienceWillFixItTimer = 0;
                SnoboldCount = 0;
                MistressOfPainCount = 0;
                PlayerDeathCount = 0;
                CrusadersSpecialState = false;
                TributeToDedicatedInsanity = false; // NYI, set to true when implement it
                DoUpdateWorldState(UPDATE_STATE_UI_SHOW, instance->IsHeroic() ? 1 : 0);
            }

            void OnPlayerEnter(Player* player) override
            {
                if (NorthrendBeasts == GORMOK_IN_PROGRESS)
                    player->CreateVehicleKit(PLAYER_VEHICLE_ID, 0);
            }

            void OnCreatureCreate(Creature* creature) override
            {
                InstanceScript::OnCreatureCreate(creature);
                if (creature->GetEntry() == NPC_SNOBOLD_VASSAL)
                    snoboldGUIDS.push_back(creature->GetGUID());
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                InstanceScript::OnGameObjectCreate(go);
                if (go->GetEntry() == GO_ARGENT_COLISEUM_FLOOR)
                    if (GetBossState(DATA_LICH_KING) == DONE)
                        go->SetDestructibleState(GO_DESTRUCTIBLE_DAMAGED);
            }

            void OnUnitDeath(Unit* unit) override
            {
                if (unit->GetTypeId() == TYPEID_PLAYER && IsEncounterInProgress())
                {
                    ++PlayerDeathCount;
                    DoUpdateWorldState(WORLD_STATE_PLAYER_DEATHS, PlayerDeathCount);
                }
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                switch (type)
                {
                    case DATA_NORTHREND_BEASTS:
                        break;
                    case DATA_JARAXXUS:
                        if (state == FAIL)
                        {
                            if (Creature* fordring = GetCreature(DATA_FORDRING))
                                fordring->AI()->DoAction(ACTION_JARAXXUS_WIPE);
                            MistressOfPainCount = 0;
                        }
                        else if (state == DONE)
                        {
                            if (Creature* fordring = GetCreature(DATA_FORDRING))
                                fordring->AI()->DoAction(ACTION_JARAXXUS_DEFEATED);
                            EventStage = 2000;
                        }
                        break;
                    case DATA_FACTION_CRUSADERS:
                        switch (state)
                        {
                            case IN_PROGRESS:
                                ResilienceWillFixItTimer = 0;
                                break;
                            case FAIL:
                                CrusadersSpecialState = false;
                                if (Creature* fordring = GetCreature(DATA_FORDRING))
                                    fordring->AI()->DoAction(ACTION_FACTION_WIPE);
                                break;
                            case DONE:
                                DoUpdateCriteria(CriteriaType::BeSpellTarget, SPELL_DEFEAT_FACTION_CHAMPIONS);
                                if (ResilienceWillFixItTimer > 0)
                                    DoUpdateCriteria(CriteriaType::BeSpellTarget, SPELL_CHAMPIONS_KILLED_IN_MINUTE);
                                DoRespawnGameObject(GetGuidData(DATA_CRUSADERS_CHEST), 7_days);
                                if (GameObject* cache = GetGameObject(DATA_CRUSADERS_CHEST))
                                    cache->RemoveFlag(GO_FLAG_NOT_SELECTABLE);
                                if (Creature* fordring = GetCreature(DATA_FORDRING))
                                    fordring->AI()->DoAction(ACTION_CHAMPIONS_DEFEATED);
                                EventStage = 3100;
                                break;
                            default:
                                break;
                        }
                        break;
                    case DATA_TWIN_VALKIRIES:
                        // Cleanup chest
                        if (GameObject* cache = GetGameObject(DATA_CRUSADERS_CHEST))
                            cache->Delete();
                        switch (state)
                        {
                            case FAIL:
                                if (Creature* fordring = GetCreature(DATA_FORDRING))
                                    fordring->AI()->DoAction(ACTION_VALKYR_WIPE);
                                break;
                            case DONE:
                                if (Creature* fordring = GetCreature(DATA_FORDRING))
                                    fordring->AI()->DoAction(ACTION_VALKYR_DEFEATED);
                                break;
                            default:
                                break;
                        }
                        break;
                    case DATA_LICH_KING:
                        break;
                    case DATA_ANUBARAK:
                        switch (state)
                        {
                            case DONE:
                            {
                                EventStage = 6000;
                                break;
                            }
                            default:
                                break;
                        }
                        break;
                    default:
                        break;
                }

                if (type < EncounterCount)
                {
                    TC_LOG_DEBUG("scripts", "[ToCr] BossState(type {}) {} = state {};", type, GetBossState(type), state);
                    if (state == FAIL)
                    {
                        EventStage = (type == DATA_NORTHREND_BEASTS ? 666 : 0);
                        state = NOT_STARTED;
                    }
                }
                return true;
            }

            void HandleNorthrendBeastsDone()
            {
                --NorthrendBeastsCount;
                if (!NorthrendBeastsCount)
                {
                    SetData(TYPE_NORTHREND_BEASTS, DONE);
                    SetBossState(DATA_NORTHREND_BEASTS, DONE);
                    SetData(DATA_DESPAWN_SNOBOLDS, 0);
                    EventStage = 400;
                    if (Creature* combatStalker = GetCreature(DATA_BEASTS_COMBAT_STALKER))
                        combatStalker->DespawnOrUnsummon();
                    HandlePlayerVehicle(false);
                    if (Creature* fordring = GetCreature(DATA_FORDRING))
                        fordring->AI()->DoAction(ACTION_NORTHREND_BEASTS_DEFEATED);
                }
            }

            void HandlePlayerVehicle(bool apply)
            {
                Map::PlayerList const &players = instance->GetPlayers();
                for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                    if (Player* player = itr->GetSource())
                    {
                        if (apply)
                            player->CreateVehicleKit(PLAYER_VEHICLE_ID, 0);
                        else
                            player->RemoveVehicleKit();
                    }
            }

            void SetData(uint32 type, uint32 data) override
            {
                switch (type)
                {
                    case TYPE_EVENT:
                        EventStage = data;
                        data = NOT_STARTED;
                        break;
                    case TYPE_EVENT_TIMER:
                        EventTimer = data;
                        data = NOT_STARTED;
                        break;
                    case TYPE_NORTHREND_BEASTS:
                        NorthrendBeasts = data;
                        switch (data)
                        {
                            case GORMOK_IN_PROGRESS:
                                SetBossState(DATA_NORTHREND_BEASTS, IN_PROGRESS);
                                NorthrendBeastsCount = 4;
                                HandlePlayerVehicle(true);
                                break;
                            case GORMOK_DONE:
                                if (Creature* tirion = GetCreature(DATA_FORDRING))
                                    tirion->AI()->DoAction(ACTION_START_JORMUNGARS);
                                HandleNorthrendBeastsDone();
                                break;
                            case SNAKES_IN_PROGRESS:
                                NotOneButTwoJormungarsTimer = 0;
                                break;
                            case SNAKES_SPECIAL:
                                NotOneButTwoJormungarsTimer = 10*IN_MILLISECONDS;
                                HandleNorthrendBeastsDone();
                                break;
                            case SNAKES_DONE:
                                if (NotOneButTwoJormungarsTimer > 0)
                                    DoUpdateCriteria(CriteriaType::BeSpellTarget, SPELL_WORMS_KILLED_IN_10_SECONDS);
                                if (Creature* tirion = GetCreature(DATA_FORDRING))
                                    tirion->AI()->DoAction(ACTION_START_ICEHOWL);
                                HandleNorthrendBeastsDone();
                                break;
                            case ICEHOWL_DONE:
                                HandleNorthrendBeastsDone();
                                break;
                            case FAIL:
                                HandlePlayerVehicle(false);
                                SetBossState(DATA_NORTHREND_BEASTS, FAIL);
                                if (Creature* tirion = GetCreature(DATA_FORDRING))
                                    tirion->AI()->DoAction(ACTION_NORTHREND_BEASTS_WIPE);
                                SnoboldCount = 0;
                                break;
                            default:
                                break;
                        }
                        break;
                    case DATA_DESPAWN_SNOBOLDS:
                        for (ObjectGuid guid : snoboldGUIDS)
                            if (Creature* snobold = instance->GetCreature(guid))
                                snobold->DespawnOrUnsummon();
                        snoboldGUIDS.clear();
                        break;
                    //Achievements
                    case DATA_SNOBOLD_COUNT:
                        if (data == INCREASE)
                            ++SnoboldCount;
                        else if (data == DECREASE)
                            --SnoboldCount;
                        break;
                    case DATA_MISTRESS_OF_PAIN_COUNT:
                        if (data == INCREASE)
                            ++MistressOfPainCount;
                        else if (data == DECREASE)
                            --MistressOfPainCount;
                        break;
                    case DATA_FACTION_CRUSADERS: // Achivement Resilience will Fix
                        ResilienceWillFixItTimer = 60 * IN_MILLISECONDS;
                        CrusadersSpecialState = true;
                        break;
                    default:
                        break;
                }
            }

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                    case TYPE_EVENT:
                        return EventStage;
                    case TYPE_NORTHREND_BEASTS:
                        return NorthrendBeasts;
                    case TYPE_EVENT_TIMER:
                        return EventTimer;
                    case TYPE_EVENT_NPC:
                        switch (EventStage)
                        {
                            case 110:
                            case 140:
                            case 150:
                            case 155:
                            case 200:
                            case 205:
                            case 210:
                            case 220:
                            case 300:
                            case 305:
                            case 310:
                            case 315:
                            case 400:
                            case 666:
                            case 1010:
                            case 1180:
                            case 2000:
                            case 2030:
                            case 3000:
                            case 3001:
                            case 3060:
                            case 3061:
                            case 3090:
                            case 3091:
                            case 3092:
                            case 3100:
                            case 3110:
                            case 4000:
                            case 4010:
                            case 4015:
                            case 4016:
                            case 4040:
                            case 4050:
                            case 5000:
                            case 5005:
                            case 5020:
                            case 6000:
                            case 6005:
                            case 6010:
                                return NPC_TIRION_FORDRING;
                                break;
                            case 5010:
                            case 5030:
                            case 5040:
                            case 5050:
                            case 5060:
                            case 5070:
                            case 5080:
                                return NPC_LICH_KING;
                                break;
                            case 120:
                            case 122:
                            case 2020:
                            case 3080:
                            case 3051:
                            case 3071:
                            case 4020:
                                return NPC_VARIAN;
                                break;
                            case 130:
                            case 132:
                            case 2010:
                            case 3050:
                            case 3070:
                            case 3081:
                            case 4030:
                                return NPC_GARROSH;
                                break;
                            case 1110:
                            case 1120:
                            case 1130:
                            case 1132:
                            case 1134:
                            case 1135:
                            case 1140:
                            case 1142:
                            case 1144:
                            case 1150:
                                return NPC_FIZZLEBANG;
                                break;
                            default:
                                return NPC_TIRION_FORDRING;
                                break;
                        };
                    default:
                        break;
                }

                return 0;
            }

            void Update(uint32 diff) override
            {
                if (GetData(TYPE_NORTHREND_BEASTS) == SNAKES_SPECIAL && NotOneButTwoJormungarsTimer)
                {
                    if (NotOneButTwoJormungarsTimer <= diff)
                        NotOneButTwoJormungarsTimer = 0;
                    else
                        NotOneButTwoJormungarsTimer -= diff;
                }

                if (CrusadersSpecialState && ResilienceWillFixItTimer)
                {
                    if (ResilienceWillFixItTimer <= diff)
                        ResilienceWillFixItTimer = 0;
                    else
                        ResilienceWillFixItTimer -= diff;
                }
            }

            bool CheckAchievementCriteriaMeet(uint32 criteria_id, Player const* /*source*/, Unit const* /*target*/, uint32 /*miscvalue1*/) override
            {
                switch (criteria_id)
                {
                    case UPPER_BACK_PAIN_10_PLAYER:
                    case UPPER_BACK_PAIN_10_PLAYER_HEROIC:
                        return SnoboldCount >= 2;
                    case UPPER_BACK_PAIN_25_PLAYER:
                    case UPPER_BACK_PAIN_25_PLAYER_HEROIC:
                        return SnoboldCount >= 4;
                    case THREE_SIXTY_PAIN_SPIKE_10_PLAYER:
                    case THREE_SIXTY_PAIN_SPIKE_10_PLAYER_HEROIC:
                    case THREE_SIXTY_PAIN_SPIKE_25_PLAYER:
                    case THREE_SIXTY_PAIN_SPIKE_25_PLAYER_HEROIC:
                        return MistressOfPainCount >= 2;
                    case A_TRIBUTE_TO_DEDICATED_INSANITY:
                        return false; // no longer obtainable
                    default:
                        break;
                }

                return false;
            }

            protected:
                uint32 EventStage;
                uint32 EventTimer;
                uint32 NorthrendBeasts;
                bool CrusadersSpecialState;
                GuidVector snoboldGUIDS;

                // Achievement stuff
                uint32 NotOneButTwoJormungarsTimer;
                uint32 ResilienceWillFixItTimer;
                uint8 SnoboldCount;
                uint8 MistressOfPainCount;
                uint8 NorthrendBeastsCount;
                int32 PlayerDeathCount;
                bool TributeToDedicatedInsanity;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_trial_of_the_crusader_InstanceMapScript(map);
        }
};

void AddSC_instance_trial_of_the_crusader()
{
    new instance_trial_of_the_crusader();
}
