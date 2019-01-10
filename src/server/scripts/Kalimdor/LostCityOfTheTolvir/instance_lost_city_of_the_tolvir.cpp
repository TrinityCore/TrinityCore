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

#include "ScriptMgr.h"
#include "Containers.h"
#include "CreatureAI.h"
#include "EventMap.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "lost_city_of_the_tolvir.h"
#include "AreaBoundary.h"
#include "Map.h"
#include "TemporarySummon.h"
#include "Weather.h"

enum TimedEvents
{
    EVENT_SPAWN_AUGH = 1
};

enum SummonGroups
{
    SUMMON_GROUP_WIND_TUNNEL = 0
};

enum Actions
{
    // Lockmaw and Augh
    ACTION_AUGH_INTRO       = 1,
    ACTION_AUGH_ATTACKABLE  = 2,

    // High Prophet Barim

    ACTION_PULL_BACK        = 1,

    // Siamat
    ACTION_UNLEASHED        = 1
};

Position const AughSpawnPos =   { -11058.91f, -1625.342f, -0.1304993f, 4.782202f };
Position const AughHomePos =    { -11062.5f, -1662.39f, 0.7606202f, 0.8028514f };

ObjectData const creatureData[] =
{
    { BOSS_GENERAL_HUSAM,           DATA_GENERAL_HUSAM          },
    { BOSS_LOCKMAW,                 DATA_LOCKMAW                },
    { BOSS_AUGH,                    DATA_AUGH                   },
    { BOSS_HIGH_PROPHET_BARIM,      DATA_HIGH_PROPHET_BARIM     },
    { BOSS_SIAMAT,                  DATA_SIAMAT                 },
    { NPC_BLAZE_OF_THE_HEAVENS,     DATA_BLAZE_OF_THE_HEAVENS   },
    { NPC_HARBINGER_OF_DARKNESS,    DATA_HARBINGER_OF_DARKNESS  },
    { NPC_SERVANT_OF_SIAMAT_1,      DATA_SERVANT_OF_SIAMAT_1    },
    { NPC_SERVANT_OF_SIAMAT_2,      DATA_SERVANT_OF_SIAMAT_2    },
    { NPC_SERVANT_OF_SIAMAT_3,      DATA_SERVANT_OF_SIAMAT_3    },
    { 0,                            0                           } // End
};

ObjectData const gameObjectData[] =
{
    { GO_SIAMATS_PLATFORM,  DATA_SIAMAT_PLATFORM   },
    { 0,                    0                      } // End
};

BossBoundaryData const boundaries =
{
    { DATA_SIAMAT,          new CircleBoundary(Position(-10948.60f, -1400.09f), 54.0f) },
    { DATA_LOCKMAW,         new CircleBoundary(Position(-11040.49f, -1643.47f), 80.0f) },
    { DATA_AUGH,            new CircleBoundary(Position(-11040.49f, -1643.47f), 80.0f) },
    { DATA_GENERAL_HUSAM,   new CircleBoundary(Position(-10872.05f, -1367.73f), 80.0f) },
};

class instance_lost_city_of_the_tolvir : public InstanceMapScript
{
    public:
        instance_lost_city_of_the_tolvir() : InstanceMapScript(LCTScriptName, 755) { }

        struct instance_lost_city_of_the_tolvir_InstanceMapScript : public InstanceScript
        {
            instance_lost_city_of_the_tolvir_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadObjectData(creatureData, gameObjectData);
                LoadBossBoundaries(boundaries);
                Initialize();
            }

            void Initialize()
            {
                heroicAughSpawned = false;
            }

            void OnCreatureCreate(Creature* creature) override
            {
                InstanceScript::OnCreatureCreate(creature);

                switch (creature->GetEntry())
                {
                    case BOSS_SIAMAT:
                        creature->SetFarVisible(true);
                        creature->setActive(true);
                        break;
                    case NPC_ADD_STALKER:
                        addStalkerGUIDs.push_back(creature->GetGUID());
                        break;
                    case NPC_WIND_TUNNEL:
                        creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                        creature->setActive(true);
                        break;
                    case NPC_REPENTANCE:
                        repenteanceGUIDs.push_back(creature->GetGUID());
                        break;
                    default:
                        break;
                }
                    
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                InstanceScript::OnGameObjectCreate(go);

                switch (go->GetEntry())
                {
                    case GO_SIAMATS_PLATFORM:
                        go->setActive(true);
                        go->SetFarVisible(true);
                        if (IsSiamatEnabled())
                        {
                            go->SetDestructibleState(GO_DESTRUCTIBLE_DESTROYED);
                            go->EnableCollision(true);
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
                    case DATA_LOCKMAW:
                        if (!instance->IsHeroic() && state == DONE)
                            SetBossState(DATA_LOCKMAW_AND_AUGH, DONE);
                        else if (instance->IsHeroic() && state == DONE && !heroicAughSpawned)
                            events.ScheduleEvent(EVENT_SPAWN_AUGH, Seconds(4));
                        break;
                    case DATA_AUGH: // Since Augh is summoned, we need to handle his respawn here
                        if (state == DONE)
                            SetBossState(DATA_LOCKMAW_AND_AUGH, DONE);
                        else if (state == FAIL)
                            events.ScheduleEvent(EVENT_SPAWN_AUGH, Seconds(30));
                        break;
                    case DATA_HIGH_PROPHET_BARIM:
                        if (state == FAIL)
                            repenteanceGUIDs.clear();
                    case DATA_GENERAL_HUSAM:
                    case DATA_LOCKMAW_AND_AUGH:
                        if (state == DONE && IsSiamatEnabled())
                        {
                            if (GameObject* platform = GetGameObject(DATA_SIAMAT_PLATFORM))
                            {
                                platform->SetDestructibleState(GO_DESTRUCTIBLE_DESTROYED);
                                platform->EnableCollision(true);
                            }

                            if (Creature* siamat = GetCreature(DATA_SIAMAT))
                                siamat->AI()->DoAction(ACTION_UNLEASHED);

                            instance->SetZoneWeather(ZONE_ID_LOST_CITY, WEATHER_STATE_HEAVY_RAIN, 1.0f);
                            instance->SummonCreatureGroup(SUMMON_GROUP_WIND_TUNNEL);
                        }
                        break;
                    case DATA_SIAMAT: // anti-cheat protection
                        if (state == IN_PROGRESS && !IsSiamatEnabled())
                            if (Creature* siamat = GetCreature(DATA_SIAMAT))
                                siamat->AI()->EnterEvadeMode();
                        if (state == DONE)
                            instance->SetZoneWeather(ZONE_ID_LOST_CITY, WEATHER_STATE_FOG, 1.0f);
                        break;
                    default:
                        break;
                }
                return true;
            }

            void SetData(uint32 data, uint32 value) override
            {
                switch (data)
                {
                    case DATA_LOCKMAW_COMBAT_ASSISTANCE:
                        switch (value)
                        {
                            case ASSISTANCE_SUMMON_AUGH_DART:
                                if (Unit* stalker = instance->GetCreature(Trinity::Containers::SelectRandomContainerElement(addStalkerGUIDs)))
                                    stalker->CastSpell(stalker, SPELL_SUMMON_AUGH_DART);
                                SetData(DATA_LOCKMAW_COMBAT_ASSISTANCE, ASSISTANCE_NONE);
                                break;
                            case ASSISTANCE_SUMMON_AUGH_WHIRLWIND:
                                if (Unit* stalker = instance->GetCreature(Trinity::Containers::SelectRandomContainerElement(addStalkerGUIDs)))
                                    stalker->CastSpell(stalker, SPELL_SUMMON_AUGH_WHIRLWIND);
                                SetData(DATA_LOCKMAW_COMBAT_ASSISTANCE, ASSISTANCE_NONE);
                                break;
                            case ASSISTANCE_SUMMON_CROCOLISKS:
                            {
                                GuidVector tempList = addStalkerGUIDs;
                                if (!tempList.empty())
                                {
                                    Trinity::Containers::RandomResize(tempList, 4);
                                    for (auto itr = tempList.begin(); itr != tempList.end(); itr++)
                                        if (Unit* stalker = instance->GetCreature(*itr))
                                            stalker->CastSpell(stalker, SPELL_SUMMON_CROCOLISK);
                                }
                                SetData(DATA_LOCKMAW_COMBAT_ASSISTANCE, ASSISTANCE_NONE);
                                break;
                            }
                            default:
                                break;
                        }
                        break;
                    case DATA_REPENTEANCE_ENDED:
                        for (ObjectGuid guid : repenteanceGUIDs)
                            if (Creature* repenteance = instance->GetCreature(guid))
                                repenteance->AI()->DoAction(ACTION_PULL_BACK);
                        break;
                    default:
                        break;
                }
            }

            bool IsSiamatEnabled()
            {
                for (LCTDataTypes boss : { DATA_GENERAL_HUSAM, DATA_LOCKMAW_AND_AUGH, DATA_HIGH_PROPHET_BARIM })
                    if (GetBossState(boss) != DONE)
                        return false;
                return true;
            }

            void Update(uint32 diff) override
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SPAWN_AUGH:
                            if (!heroicAughSpawned)
                            {
                                if (Creature* augh = instance->SummonCreature(BOSS_AUGH, AughSpawnPos))
                                    augh->AI()->DoAction(ACTION_AUGH_INTRO);
                                heroicAughSpawned = true;
                            }
                            else if (heroicAughSpawned)
                                if (Creature* augh = instance->SummonCreature(BOSS_AUGH, AughHomePos))
                                    augh->AI()->DoAction(ACTION_AUGH_ATTACKABLE);
                            break;
                        default:
                            break;
                    }
                }
            }

            void ReadSaveDataMore(std::istringstream& /*data*/) override
            {
                if (IsSiamatEnabled())
                {
                    if (Creature* siamat = GetCreature(DATA_SIAMAT))
                        siamat->setActive(true);

                    instance->SetZoneWeather(ZONE_ID_LOST_CITY, WEATHER_STATE_HEAVY_RAIN, 1.0f);
                    instance->SummonCreatureGroup(SUMMON_GROUP_WIND_TUNNEL);
                }
            }

        protected:
            EventMap events;
            bool heroicAughSpawned;
            GuidVector addStalkerGUIDs;
            GuidVector repenteanceGUIDs;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_lost_city_of_the_tolvir_InstanceMapScript(map);
        }
};

void AddSC_instance_lost_city_of_the_tolvir()
{
    new instance_lost_city_of_the_tolvir();
}
