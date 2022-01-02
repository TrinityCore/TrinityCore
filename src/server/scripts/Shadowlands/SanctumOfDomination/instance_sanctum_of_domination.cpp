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

#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "sanctum_of_domination.h"

ObjectData const creatureData[] =
{
  /*{ BOSS_THE_TERRAGRUE,              DATA_THE_TERRAGRUE               },
    { BOSS_THE_EYE_OF_THE_JAILER,      DATA_THE_EYE_OF_THE_JAILER       },
    { BOSS_SKYJA,                      DATA_THE_NINE                    },
    { BOSS_REMNANT_OF_NERZHUL,         DATA_REMNANT_OF_NERZHUL          },
    { BOSS_SOULRENDER_DORMAZAIN,       DATA_SOULRENDER_DORMAZAIN        },
    { BOSS_PAINSMITH_RAZNAL,           DATA_PAINSMITH_RAZNAL            },
    { BOSS_GUARDIAN_OF_THE_FIRST_ONES, DATA_GUARDIAN_OF_THE_FIRST_ONES  },
    { BOSS_FATESCRIBE_ROHKALO,         DATA_FATESCRIBE_ROHKALO          },
    { BOSS_KELTHUZAD,                  DATA_KELTHUZAD                   },*/
    { BOSS_SYLVANAS_WINDRUNNER,        DATA_SYLVANAS_WINDRUNNER         },
    { NPC_BOLVAR_FORDRAGON_PINNACLE,   DATA_BOLVAR_FORDRAGON_PINNACLE   },
    { NPC_JAINA_PROUDMOORE_PINNACLE,   DATA_JAINA_PROUDMOORE_PINNACLE   },
    { NPC_THRALL_PINNACLE,             DATA_THRALL_PINNACLE             },
    { NPC_ANDUIN_CRUCIBLE,             DATA_ANDUIN_CRUCIBLE             },
    { 0,                               0                                } // END
};

class instance_sanctum_of_domination : public InstanceMapScript
{
public:
    instance_sanctum_of_domination() : InstanceMapScript(SDScriptName, 2450) { }

    struct instance_sanctum_of_domination_InstanceMapScript : public InstanceScript
    {
        instance_sanctum_of_domination_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            LoadObjectData(creatureData, nullptr);
        }

        void OnPlayerEnter(Player* /*player*/) override
        {
            /*
            if (GetData(DATA_SYLVANAS_INTRO) == NOT_STARTED)
            {
                if (Creature* sylvanas = GetCreature(DATA_SYLVANAS_WINDRUNNER))
                {
                    if (sylvanas->IsAIEnabled())
                        sylvanas->AI()->DoAction(ACTION_START_SYLVANAS_INTRO);
                }
            }
            */
        }

        void OnCreatureCreate(Creature* creature) override
        {
            InstanceScript::OnCreatureCreate(creature);

            switch (creature->GetEntry())
            {
                /*
                case BOSS_THE_TERRAGRUE:
                {
                    TerragrueGUID = creature->GetGUID();
                    break;
                }

                case BOSS_THE_EYE_OF_THE_JAILER:
                {
                    EyeoftheJailerGUID = creature->GetGUID();
                    break;
                }

                case BOSS_SKYJA:
                {
                    SkyjaGUID = creature->GetGUID();
                    break;
                }

                case BOSS_REMNANT_OF_NERZHUL:
                {
                    RemnantofNerzhulGUID = creature->GetGUID();
                    break;
                }

                case BOSS_SOULRENDER_DORMAZAIN:
                {
                    SoulrenderDormazainGUID = creature->GetGUID();
                    break;
                }

                case BOSS_PAINSMITH_RAZNAL:
                {
                    PainsmithRaznalGUID = creature->GetGUID();
                    break;
                }

                case BOSS_GUARDIAN_OF_THE_FIRST_ONES:
                {
                    GuardianoftheFirstOnesGUID = creature->GetGUID();
                    break;
                }

                case BOSS_FATESCRIBE_ROHKALO:
                {
                    FatescribeRohkaloGUID = creature->GetGUID();
                    break;
                }

                case BOSS_KELTHUZAD:
                {
                    KelthuzadGUID = creature->GetGUID();
                    break;
                }*/

                case BOSS_SYLVANAS_WINDRUNNER:
                {
                    SylvanasGUID = creature->GetGUID();

                    if (GetData(DATA_SYLVANAS_INTRO) != DONE)
                        SetData(DATA_SYLVANAS_INTRO, DONE);
                    break;
                }

                case DATA_BOLVAR_FORDRAGON_PINNACLE:
                {
                    BolvarPinnacleGUID = creature->GetGUID();

                    if (Creature* sylvanas = GetCreature(DATA_SYLVANAS_WINDRUNNER))
                        sylvanas->AI()->JustSummoned(creature);
                    break;
                }

                case NPC_JAINA_PROUDMOORE_PINNACLE:
                {
                    JainaPinnacleGUID = creature->GetGUID();

                    if (Creature* sylvanas = GetCreature(DATA_SYLVANAS_WINDRUNNER))
                        sylvanas->AI()->JustSummoned(creature);

                    break;
                }

                case DATA_THRALL_PINNACLE:
                {
                    ThrallPinnacleGUID = creature->GetGUID();

                    if (Creature* sylvanas = GetCreature(DATA_SYLVANAS_WINDRUNNER))
                        sylvanas->AI()->JustSummoned(creature);
                    break;
                }

                default:
                    break;
            }
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            switch (go->GetEntry())
            {
                case GAMEOBJECT_TORGHAST_SPIKE_01:
                case GAMEOBJECT_TORGHAST_SPIKE_02:
                case GAMEOBJECT_TORGHAST_SPIKE_03:
                case GAMEOBJECT_TORGHAST_SPIKE_04:
                case GAMEOBJECT_TORGHAST_SPIKE_05:
                case GAMEOBJECT_TORGHAST_SPIKE_06:
                case GAMEOBJECT_TORGHAST_SPIKE_07:
                case GAMEOBJECT_TORGHAST_SPIKE_08:
                case GAMEOBJECT_TORGHAST_SPIKE_09:
                case GAMEOBJECT_TORGHAST_SPIKE_10:
                case GAMEOBJECT_TORGHAST_SPIKE_11:
                case GAMEOBJECT_TORGHAST_SPIKE_12:
                    TorghastSpikeGUID.push_back(go->GetGUID());
            }
        }

        uint32 GetData(uint32 type) const override
        {
            switch (type)
            {
                case DATA_SYLVANAS_INTRO:
                    return SylvanasIntro;

                default:
                    break;
            }

            return 0;
        }

        ObjectGuid GetGuidData(uint32 type) const override
        {
            switch (type)
            {
                /*
                case DATA_THE_TERRAGRUE:
                    return TerragrueGUID;
                case DATA_THE_EYE_OF_THE_JAILER:
                    return EyeoftheJailerGUID;
                case DATA_THE_NINE:
                    return SkyjaGUID;
                case DATA_REMNANT_OF_NERZHUL:
                    return RemnantofNerzhulGUID;
                case DATA_SOULRENDER_DORMAZAIN:
                    return SoulrenderDormazainGUID;
                case DATA_PAINSMITH_RAZNAL:
                    return PainsmithRaznalGUID;
                case DATA_GUARDIAN_OF_THE_FIRST_ONES:
                    return GuardianoftheFirstOnesGUID;
                case DATA_FATESCRIBE_ROHKALO:
                    return FatescribeRohkaloGUID;
                case DATA_KELTHUZAD:
                    return KelthuzadGUID;*/
                case DATA_SYLVANAS_WINDRUNNER:
                    return SylvanasGUID;
                default:
                    break;
            }

            return ObjectGuid::Empty;
        }

        bool SetBossState(uint32 id, EncounterState state) override
        {
            if (!InstanceScript::SetBossState(id, state))
                return false;

            switch (id)
            {
                case DATA_SYLVANAS_WINDRUNNER:
                {
                    if (state == IN_PROGRESS)
                    {
                        if (Creature* bolvar = GetCreature(DATA_BOLVAR_FORDRAGON_PINNACLE))
                        {
                            if (bolvar->IsAIEnabled())
                                bolvar->AI()->DoZoneInCombat();
                        }

                        if (Creature* thrall = GetCreature(DATA_THRALL_PINNACLE))
                        {
                            if (thrall->IsAIEnabled())
                                thrall->AI()->DoZoneInCombat();
                        }

                        if (Creature* jaina = GetCreature(DATA_JAINA_PROUDMOORE_PINNACLE))
                        {
                            if (jaina->IsAIEnabled())
                                jaina->AI()->DoZoneInCombat();
                        }
                    }

                    if (state == FAIL)
                    {
                        for (ObjectGuid const& spikeGUID : TorghastSpikeGUID)
                        {
                            if (GameObject* torghastSpike = instance->GetGameObject(spikeGUID))
                                torghastSpike->SetSpellVisualId(0);
                        }

                        Events.ScheduleEvent(EVENT_RESET_PLAYERS_ON_SYLVANAS, 1s);
                    }

                    break;
                }

                default:
                    break;
            }

            return true;
        }

        void SetData(uint32 type, uint32 data) override
        {
            switch (type)
            {
                case DATA_SYLVANAS_INTRO:
                {
                    switch (data)
                    {
                        case NOT_STARTED:
                        {
                            if (GetBossState(DATA_SYLVANAS_WINDRUNNER) != DONE)
                            {
                                if (Creature* sylvanas = GetCreature(DATA_SYLVANAS_WINDRUNNER))
                                {
                                    sylvanas->AddUnitFlag(UNIT_FLAG_NOT_ATTACKABLE_1);
                                    sylvanas->AddUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                                    sylvanas->AddUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);

                                    sylvanas->SetSpeed(UnitMoveType::MOVE_RUN, 4.0f);
                                }
                            }

                            break;
                        }

                        case DONE:
                        {
                            if (GetBossState(DATA_SYLVANAS_WINDRUNNER) != DONE)
                            {
                                if (Creature* sylvanas = GetCreature(DATA_SYLVANAS_WINDRUNNER))
                                {
                                    sylvanas->RemoveUnitFlag(UNIT_FLAG_NOT_ATTACKABLE_1);
                                    sylvanas->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                                    sylvanas->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);

                                    sylvanas->SetSpeed(UnitMoveType::MOVE_RUN, 14.0f);
                                }
                            }

                            break;
                        }

                        default:
                            break;
                    }
                }

                default:
                    break;
            }
        }

        void Update(uint32 diff) override
        {
            Events.Update(diff);

            while (uint32 eventId = Events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_RESET_PLAYERS_ON_SYLVANAS:
                    {
                        Map::PlayerList const& playerList = instance->GetPlayers();

                        for (Map::PlayerList::const_iterator itr = playerList.begin(); itr != playerList.end(); ++itr)
                        {
                            if (Player* player = itr->GetSource())
                            {
                                if (player->GetAreaId() != AREA_PINNACLE_OF_DOMINANCE)
                                    player->NearTeleportTo(SylvanasPlatformRevivePos, false);
                            }
                        }

                        break;
                    }

                    default:
                        break;
                }
            }
        }

        protected:
            EventMap Events;
            ObjectGuid TerragrueGUID;
            ObjectGuid EyeoftheJailerGUID;
            ObjectGuid SkyjaGUID;
            ObjectGuid RemnantofNerzhulGUID;
            ObjectGuid SoulrenderDormazainGUID;
            ObjectGuid PainsmithRaznalGUID;
            ObjectGuid GuardianoftheFirstOnesGUID;
            ObjectGuid FatescribeRohkaloGUID;
            ObjectGuid KelthuzadGUID;
            ObjectGuid SylvanasGUID;
            ObjectGuid BolvarPinnacleGUID;
            ObjectGuid JainaPinnacleGUID;
            ObjectGuid ThrallPinnacleGUID;
            std::vector<ObjectGuid> TorghastSpikeGUID;
            uint32 SylvanasIntro;
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_sanctum_of_domination_InstanceMapScript(map);
    }
};

void AddSC_instance_sanctum_of_domination()
{
    new instance_sanctum_of_domination();
}
