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
#include "sepulcher_of_the_first_ones.h"

ObjectData const creatureData[] =
{
    { BOSS_ANDUIN_WRYNN,               DATA_ANDUIN_WRYNN         },
    { NPC_BEFOULED_BARRIER,            DATA_BEFOULED_BARRIER     },
    { NPC_EMPTY_VESSEL,                DATA_EMPTY_VESSEL         },
    { NPC_GRIM_REFLECTION,             DATA_GRIM_REFLECTION      },
    { BOSS_REMNANT_OF_A_FALLEN_KING,   DATA_REMNANT_OF_A_FALLEN_KING },
    { NPC_UTHER_THE_LIGHTBRINGER,      DATA_UTHER_THE_LIGHTBRINGER },
    { NPC_LADY_JAINA_PROUDMOORE,       DATA_JAINA_PROUDMOORE     },
    { NPC_SYLVANAS_WINDRUNNER,         DATA_SYLVANAS_WINDRUNNER  },
    { NPC_FIRIM,                       DATA_FIRIM                },
    { NPC_ANDUIN_SOUL,                 DATA_ANDUIN_SOUL          },
    { NPC_BEACON_OF_HOPE,              DATA_BEACON_OF_HOPE       },
    {0, 0}

};

DungeonEncounterData const encounters[] =
{
    { DATA_ANDUIN_WRYNN, {{ 2546 }} },

};

enum Spells
{
    SPELL_ANDUIN_PLUNGE_KINGSMOURNE = 369125,
};

class instance_sepulcher_of_the_first_ones : public InstanceMapScript
{
public:
    instance_sepulcher_of_the_first_ones() : InstanceMapScript(SFOScriptName, 2481) { }

    struct instance_sepulcher_of_the_first_ones_InstanceMapScript : public InstanceScript
    {
        instance_sepulcher_of_the_first_ones_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            LoadDungeonEncounterData(encounters);
            LoadObjectData(creatureData, nullptr);
            AnduinIntroductionData = NOT_STARTED;

        }

        void OnCreatureCreate(Creature* creature) override
        {
            InstanceScript::OnCreatureCreate(creature);

            switch (creature->GetEntry())
            {
                case BOSS_ANDUIN_WRYNN:
                    AnduinWrynnGUID = creature->GetGUID();
                    break;

                case BOSS_REMNANT_OF_A_FALLEN_KING:
                    RemnantGUID = creature->GetGUID();
                    break;

                case NPC_BEACON_OF_HOPE:
                    BeaconOfHopeGUID = creature->GetGUID();
                    break;

                case NPC_SYLVANAS_WINDRUNNER:
                    SylvanasGUID = creature->GetGUID();
                    break;

                case NPC_UTHER_THE_LIGHTBRINGER:
                    UtherGUID = creature->GetGUID();
                    break;

                case NPC_LADY_JAINA_PROUDMOORE:
                    JainaGUID = creature->GetGUID();
                    break;

                case NPC_ANDUIN_SOUL:
                    AnduinGUID = creature->GetGUID();
                    break;

                default:
                    break;
            }
        }

        bool SetBossState(uint32 id, EncounterState state) override
        {
            if (!InstanceScript::SetBossState(id, state))
                return false;

            switch (id)
            {
                case DATA_ANDUIN_WRYNN:
                {
                    switch (state)
                    {
                        case NOT_STARTED:
                        {
                            DoUpdateWorldState(WORLD_STATE_ANDUIN_ENCOUNTER_STARTED, 0);
                            break;
                        }

                        case IN_PROGRESS:
                        {
                            Creature* anduin = GetCreature(DATA_ANDUIN_WRYNN);
                            if (!anduin)
                                return false;

                            DoUpdateWorldState(WORLD_STATE_ANDUIN_ENCOUNTER_STARTED, 1);

                            if (Creature* uther = GetCreature(DATA_UTHER_THE_LIGHTBRINGER))
                            {
                                uther->SetFaction(2);
                                uther->AI()->JustEngagedWith(anduin);
                                uther->GetThreatManager().AddThreat(anduin, 1000);
                            }

                            if (Creature* sylvanas = GetCreature(DATA_SYLVANAS_WINDRUNNER))
                            {
                                sylvanas->SetFaction(2);
                                sylvanas->AI()->JustEngagedWith(anduin);
                                sylvanas->GetThreatManager().AddThreat(anduin, 1000);
                                sylvanas->GetAI()->AttackStartCaster(anduin, 25.0f);
                            }

                            if (Creature* jaina = GetCreature(DATA_JAINA_PROUDMOORE))
                            {
                                jaina->SetFaction(2);
                                jaina->AI()->JustEngagedWith(anduin);
                                jaina->GetThreatManager().AddThreat(anduin, 1000);
                                jaina->GetAI()->AttackStartCaster(anduin, 25.0f);
                            }
                            break;
                        }

                        default:
                            break;
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
                case DATA_ANDUIN_WRYNN_INTRODUCTION:
                {
                    switch (data)
                    {
                        case NOT_STARTED:
                        {
                            AnduinIntroductionData = NOT_STARTED;
                            if (Creature* anduin = GetCreature(DATA_ANDUIN_WRYNN))
                            {
                                anduin->CastSpell(anduin, SPELL_ANDUIN_PLUNGE_KINGSMOURNE);
                                anduin->SetUnitFlag(UNIT_FLAG_NOT_ATTACKABLE_1);
                                anduin->SetUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                                anduin->SetUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
                                anduin->SetImmuneToAll(true);
                            }
                            break;
                        }
                        case IN_PROGRESS:
                        {
                            AnduinIntroductionData = IN_PROGRESS;
                            break;
                        }

                        case DONE:
                        {
                            AnduinIntroductionData = DONE;
                            if (Creature* anduin = GetCreature(DATA_ANDUIN_WRYNN))
                            {
                                anduin->RemoveUnitFlag(UNIT_FLAG_NOT_ATTACKABLE_1);
                                anduin->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                                anduin->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
                                anduin->SetImmuneToAll(false);
                                anduin->SetSpeed(MOVE_RUN, 11.0f);
                                anduin->RemoveAurasDueToSpell(SPELL_ANDUIN_PLUNGE_KINGSMOURNE);
                            }
                            break;
                        }
                        default:
                            break;
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
                case DATA_ANDUIN_WRYNN_INTRODUCTION:
                    return AnduinIntroductionData;
                case DATA_ANDUIN_WRYNN_FINAL_MOVIE:
                    return AnduinFinalData;
                default:
                    break;
            }

            return 0;
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            InstanceScript::OnGameObjectCreate(go);

            switch (go->GetEntry())
            {
                case GAMEOBJECT_BRIDGE_TO_ANDUIN:
                    BridgeToAnduinGUID = go->GetGUID();
                    break;

                case GAMEOBJECT_BRIDGE_AFTER_ANDUIN:
                    BridgeAfterAnduinGUID = go->GetGUID();
                    break;

                default:
                    break;
            }
        }

        ObjectGuid GetGuidData(uint32 type) const override
        {
            switch (type)
            {
                case DATA_ANDUIN_WRYNN:
                    return AnduinWrynnGUID;

                case DATA_BEFOULED_BARRIER:
                    return BefouledBarrierGUID;

                case DATA_EMPTY_VESSEL:
                    return EmptyVesselGUID;

                case DATA_GRIM_REFLECTION:
                    return GrimReflectionGUID;

                case DATA_REMNANT_OF_A_FALLEN_KING:
                    return RemnantGUID;

                case DATA_BEACON_OF_HOPE:
                    return BeaconOfHopeGUID;
                case DATA_UTHER_THE_LIGHTBRINGER:
                    return UtherGUID;

                case DATA_JAINA_PROUDMOORE:
                    return JainaGUID;

                case DATA_SYLVANAS_WINDRUNNER:
                    return SylvanasGUID;

                case DATA_FIRIM:
                    return FirimGUID;

                default:
                    break;
            }

            return InstanceScript::GetGuidData(type);
        }

    protected:
        ObjectGuid AnduinWrynnGUID;
        ObjectGuid BefouledBarrierGUID;
        ObjectGuid EmptyVesselGUID;
        ObjectGuid LostSoulGUID;
        ObjectGuid GrimReflectionGUID;
        ObjectGuid RemnantGUID;
        ObjectGuid BeaconOfHopeGUID;
        ObjectGuid UtherGUID;
        ObjectGuid JainaGUID;
        ObjectGuid SylvanasGUID;
        ObjectGuid FirimGUID;
        ObjectGuid AnduinGUID;
        ObjectGuid TreasureofTheFirstOnesGUID;
        ObjectGuid BridgeToAnduinGUID;
        ObjectGuid BridgeAfterAnduinGUID;
        uint8 AnduinGObjectData;
        uint8 AnduinIntroductionData;
        uint8 AnduinFinalData;
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_sepulcher_of_the_first_ones_InstanceMapScript(map);
    }
};

void AddSC_instance_sepulcher_of_the_first_ones()
{
    new instance_sepulcher_of_the_first_ones();
}
