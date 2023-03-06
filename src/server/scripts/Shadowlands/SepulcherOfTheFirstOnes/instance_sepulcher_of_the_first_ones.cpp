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
    { NPC_SYLVANAS_WINDRUNNER,         DATA_SYLVANAS_WINDRUNNER  },
    { NPC_ANDUIN_SOUL,                 DATA_ANDUIN_SOUL          },
    { NPC_BEACON_OF_HOPE,              DATA_BEACON_OF_HOPE       },
    {0, 0}

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
            SetData(DATA_ANDUIN_WRYNN, TO_BE_DECIDED);
            SetData(DATA_ANDUIN_GAMEOBJECTS, TO_BE_DECIDED);
            SetBossNumber(EncounterCount);
            LoadObjectData(creatureData, nullptr);
            
        }

        void OnPlayerEnter(Player* /*player*/) override
        {

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

            case NPC_BEACON_OF_HOPE:
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

                    case TO_BE_DECIDED:
                    {

                    }

                    case NOT_STARTED:
                    {

                        break;
                    }

                    case IN_PROGRESS:
                    {

                    }

                    case FAIL:
                    {
                        break;
                    }

                    case DONE:
                    {

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
        void OnGameObjectCreate(GameObject* go) override
        {
            InstanceScript::OnGameObjectCreate(go);

            switch (go->GetEntry())
            {
            case GAMEOBJECT_BRIDGE_TO_ANDUIN:
                BridgeToAnduinGUID = go->GetGUID();
                break;

            case GAMEOBJECT_ANDUIN_CHEST_LOOT:
                TreasureofTheFirstOnesGUID = go->GetGUID();
                break;

            case GAMEOBJECT_BRIDGE_AFTER_ANDUIN:
            {
                BridgeAfterAnduinGUID = go->GetGUID();
                break;
            }

                break;
            default:
                break;
            }
        }


        void SetData(uint32 type, uint32 data) override
        {
            switch (type)
            {
            case DATA_ANDUIN_GAMEOBJECTS:
            {
                switch (data)
                {

                }
                break;
            }

            default:
                break;
            }
        }

        uint32 GetData(uint32 type) const override
        {

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

            case DATA_UTHER_THE_LIGHTBRINGER:
                return UtherGUID;

            case DATA_JAINA_PROUDMOORE:
                return JainaGUID;

            case DATA_SYLVANAS_WINDRUNNER:
                return SylvanasGUID;          


            default:
                break;
            }

            return InstanceScript::GetGuidData(type);
        }

        void Update(uint32 diff) override
        {
            Events.Update(diff);

            while (uint32 eventId = Events.ExecuteEvent())
            {
                switch (eventId)
                {


                default:
                    break;
                }
            }
        }

    protected:
        EventMap Events;
        ObjectGuid AnduinWrynnGUID;
        ObjectGuid BefouledBarrierGUID;
        ObjectGuid EmptyVesselGUID;
        ObjectGuid LostSoulGUID;
        ObjectGuid GrimReflectionGUID;
        ObjectGuid RemnantGUID;
        ObjectGuid UtherGUID;
        ObjectGuid JainaGUID;
        ObjectGuid SylvanasGUID;
        ObjectGuid AnduinGUID;
        ObjectGuid TreasureofTheFirstOnesGUID;
        ObjectGuid BridgeToAnduinGUID;
        ObjectGuid BridgeAfterAnduinGUID;
        uint8 AnduinGObjectData;

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
