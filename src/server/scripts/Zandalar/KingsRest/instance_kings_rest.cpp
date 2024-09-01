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
#include "InstanceScript.h"
#include "Map.h"
#include "ScriptMgr.h"
#include "kings_rest.h"

ObjectData const creatureData[] =
{
    { BOSS_GOLDEN_SERPENT,          DATA_GOLDEN_SERPENT         },
    { BOSS_MCHIMBA_THE_EMBALMER,    DATA_MCHIMBA_THE_EMBALMER   },
    { BOSS_AKAALI_THE_CONQUEROR,    DATA_AKAALI_THE_CONQUEROR   },
    { BOSS_ZANAZAL_THE_WISE,        DATA_ZANAZAL_THE_WISE       },
    { BOSS_KULA_THE_BUTCHER,        DATA_KULA_THE_BUTCHER       },
    { BOSS_KING_DAZAR,              DATA_KING_DAZAR             },
    { 0,                            0                           }  // END
};

DoorData const doorData[] =
{
    { GO_KINGS_REST_SERPENT_POST_DOOR,     DATA_GOLDEN_SERPENT,        EncounterDoorBehavior::OpenWhenDone          },
    { 0,                                   0,                          EncounterDoorBehavior::OpenWhenNotInProgress }  // END
};

ObjectData const objectData[] =
{
    { GO_KINGS_REST_ENTRYWAY_DOOR,      DATA_KINGS_REST_INTRO_DOOR  },
    { GO_KINGS_REST_LIQUID_GOLD_POOL,   DATA_KINGS_REST_LIQUID_POOL },
    { 0,                                0                           }  // END
};

DungeonEncounterData const encounters[] =
{
    { DATA_GOLDEN_SERPENT,          {{ 2139 }} },
    { DATA_COUNCIL_OF_TRIBES,       {{ 2140 }} },
    { DATA_MCHIMBA_THE_EMBALMER,    {{ 2142 }} },
    { DATA_KING_DAZAR,              {{ 2143 }} },
};

class instance_kings_rest : public InstanceMapScript
{
public:
    instance_kings_rest() : InstanceMapScript(KingsRestScriptName, 1762) { }

    struct instance_kings_rest_InstanceMapScript : public InstanceScript
    {
        instance_kings_rest_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            LoadObjectData(creatureData, objectData);
            LoadDoorData(doorData);
            LoadDungeonEncounterData(encounters);

            _serpentTempleSpawns = 0;
        }

        void OnCreatureCreate(Creature* creature) override
        {
            InstanceScript::OnCreatureCreate(creature);

            if (creature->HasStringId("TempleEvent"))
                _serpentTempleSpawns++;
        }

        void OnUnitDeath(Unit* unit) override
        {
            Creature* creature = unit->ToCreature();
            if (!creature)
                return;

            if (creature->HasStringId("TempleEvent"))
            {
                _serpentTempleSpawns--;
                if (_serpentTempleSpawns > 0)
                    return;

                instance->SpawnGroupSpawn(SPAWN_GROUP_SERPENT_BOSS);
            }
        }

    private:
        uint8 _serpentTempleSpawns;
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_kings_rest_InstanceMapScript(map);
    }
};

void AddSC_instance_kings_rest()
{
    new instance_kings_rest();
}
