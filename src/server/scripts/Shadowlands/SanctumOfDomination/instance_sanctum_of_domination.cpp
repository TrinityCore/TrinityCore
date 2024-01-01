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
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "sanctum_of_domination.h"

ObjectData const creatureData[] =
{
    { BOSS_SYLVANAS_WINDRUNNER,        DATA_SYLVANAS_WINDRUNNER         },
    { NPC_SYLVANAS_SHADOWCOPY_RIDING,  DATA_SYLVANAS_SHADOWCOPY_RIDING  },
    { NPC_BOLVAR_FORDRAGON_PINNACLE,   DATA_BOLVAR_FORDRAGON_PINNACLE   },
    { NPC_JAINA_PROUDMOORE_PINNACLE,   DATA_JAINA_PROUDMOORE_PINNACLE   },
    { NPC_THRALL_PINNACLE,             DATA_THRALL_PINNACLE             },
    { NPC_THRONE_OF_THE_DAMNED,        DATA_THRONE_OF_THE_DAMNED        },
    { 0,                               0                                } // END
};

DungeonEncounterData const encounters[] =
{
    { DATA_THE_TARRAGRUE,              {{ 2423 }} },
    { DATA_THE_EYE_OF_THE_JAILER,      {{ 2433 }} },
    { DATA_THE_NINE,                   {{ 2429 }} },
    { DATA_REMNANT_OF_NERZHUL,         {{ 2432 }} },
    { DATA_SOULRENDER_DORMAZAIN,       {{ 2434 }} },
    { DATA_PAINSMITH_RAZNAL,           {{ 2430 }} },
    { DATA_GUARDIAN_OF_THE_FIRST_ONES, {{ 2436 }} },
    { DATA_FATESCRIBE_ROHKALO,         {{ 2431 }} },
    { DATA_KELTHUZAD,                  {{ 2422 }} },
    { DATA_SYLVANAS_WINDRUNNER,        {{ 2435 }} }
};

class instance_sanctum_of_domination : public InstanceMapScript
{
public:
    instance_sanctum_of_domination() : InstanceMapScript(SODScriptName, 2450) { }

    struct instance_sanctum_of_domination_InstanceMapScript : public InstanceScript
    {
        instance_sanctum_of_domination_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            LoadDungeonEncounterData(encounters);
            LoadObjectData(creatureData, nullptr);

            SylvanasIntroductionState = NOT_STARTED;
        }

        void OnCreatureCreate(Creature* creature) override
        {
            InstanceScript::OnCreatureCreate(creature);

            switch (creature->GetEntry())
            {
                case BOSS_SYLVANAS_WINDRUNNER:
                    SylvanasGUID = creature->GetGUID();
                    break;

                case NPC_SYLVANAS_SHADOWCOPY_RIDING:
                    SylvanasShadowcopyRidingGUID = creature->GetGUID();
                    break;

                case NPC_BOLVAR_FORDRAGON_PINNACLE:
                    BolvarPinnacleGUID = creature->GetGUID();
                    break;

                case NPC_JAINA_PROUDMOORE_PINNACLE:
                    JainaPinnacleGUID = creature->GetGUID();
                    break;

                case NPC_THRALL_PINNACLE:
                    ThrallPinnacleGUID = creature->GetGUID();
                    break;

                case NPC_THRONE_OF_THE_DAMNED:
                    ThroneOfTheDamnedGUID = creature->GetGUID();
                    break;

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
                    TorghastSpikeGUIDs.push_back(go->GetGUID());
                    break;

                default:
                    break;
            }
        }

        ObjectGuid GetGuidData(uint32 type) const override
        {
            switch (type)
            {
                case DATA_SYLVANAS_WINDRUNNER:
                    return SylvanasGUID;
                case DATA_BOLVAR_FORDRAGON_PINNACLE:
                    return BolvarPinnacleGUID;
                case DATA_JAINA_PROUDMOORE_PINNACLE:
                    return JainaPinnacleGUID;
                case DATA_THRALL_PINNACLE:
                    return ThrallPinnacleGUID;
                case DATA_THRONE_OF_THE_DAMNED:
                    return ThroneOfTheDamnedGUID;
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
                    if (state == NOT_STARTED)
                    {
                        DoUpdateWorldState(WORLD_STATE_SYLVANAS_ENCOUNTER_STARTED, 0);

                        if (Creature* throneTeleporter = GetCreature(DATA_THRONE_OF_THE_DAMNED))
                            throneTeleporter->SetVisible(true);

                        for (ObjectGuid const& spikeGUID : TorghastSpikeGUIDs)
                            if (GameObject* torghastSpike = instance->GetGameObject(spikeGUID))
                                torghastSpike->SetSpellVisualId(0);
                    }
                    else if (state == IN_PROGRESS)
                    {
                        DoUpdateWorldState(WORLD_STATE_SYLVANAS_ENCOUNTER_STARTED, 1);

                        if (Creature* throneTeleporter = GetCreature(DATA_THRONE_OF_THE_DAMNED))
                            throneTeleporter->SetVisible(false);
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
                case DATA_SYLVANAS_INTRODUCTION:
                {
                    switch (data)
                    {
                        case IN_PROGRESS:
                            SylvanasIntroductionState = IN_PROGRESS;
                            if (Creature* sylvanas = GetCreature(DATA_SYLVANAS_WINDRUNNER))
                                sylvanas->SetHomePosition(SylvanasRespawnPos);
                            break;

                        case DONE:
                            SylvanasIntroductionState = DONE;
                            if (Creature* sylvanas = GetCreature(DATA_SYLVANAS_WINDRUNNER))
                            {
                                sylvanas->RemoveUnitFlag(UNIT_FLAG_NOT_ATTACKABLE_1);
                                sylvanas->SetImmuneToAll(false);
                                sylvanas->SetSpeed(MOVE_RUN, 14.0f);
                            }
                            break;

                        default:
                            break;
                    }
                    break;
                }

                default:
                    break;
            }
        }

        uint32 GetData(uint32 type) const override
        {
            switch (type)
            {
                case DATA_SYLVANAS_INTRODUCTION:
                    return SylvanasIntroductionState;
                default:
                    break;
            }

            return 0;
        }

    protected:
        ObjectGuid SylvanasGUID;
        ObjectGuid SylvanasShadowcopyRidingGUID;
        ObjectGuid BolvarPinnacleGUID;
        ObjectGuid JainaPinnacleGUID;
        ObjectGuid ThrallPinnacleGUID;
        ObjectGuid ThroneOfTheDamnedGUID;
        std::vector<ObjectGuid> TorghastSpikeGUIDs;
        uint8 SylvanasIntroductionState;
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
