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

#include "InstanceScript.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "dragon_soul.h"

ObjectData const creatureData[] =
{
    { BOSS_MADNESS_OF_DEATHWING,            DATA_MADNESS_OF_DEATHWING               },
    { NPC_DEATHWING_MADNESS_OF_DEATHWING,   DATA_DEATHWING_MADNESS_OF_DEATHWING     },
    { NPC_THRALL_MADNESS_OF_DEATHWING,      DATA_THRALL_MADNESS_OF_DEATHWING        },
    { NPC_YSERA_MADNESS_OF_DEATHWING,       DATA_YSERA_MADNESS_OF_DEATHWING         },
    { NPC_ALEXSTRASZA_MADNESS_OF_DEATHWING, DATA_ALEXSTRASZA_MADNESS_OF_DEATHWING   },
    { NPC_NOZDORMU_MADNESS_OF_DEATHWING,    DATA_NOZDORMU_MADNESS_OF_DEATHWING      },
    { NPC_KALECGOS_MADNESS_OF_DEATHWING,    DATA_KALECGOS_MADNESS_OF_DEATHWING      },
    { NPC_TAIL_TENTACLE,                    DATA_TAIL_TENTACLE_MADNESS_OF_DEATHWING },
    { 0,                                    0                                       } // END
};

ObjectData const gameobjectData[] =
{
    { 0, 0 } // END
};

DoorData const doorData[] =
{
    { 0, 0, DOOR_TYPE_ROOM } // END
};

class instance_dragon_soul : public InstanceMapScript
{
public:
    instance_dragon_soul() : InstanceMapScript(DSScriptName, 967) { }

    struct instance_dragon_soul_InstanceMapScript : public InstanceScript
    {
        instance_dragon_soul_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            LoadDoorData(doorData);
            LoadObjectData(creatureData, gameobjectData);
        }

        void OnCreatureCreate(Creature* creature) override
        {
            InstanceScript::OnCreatureCreate(creature);

            switch (creature->GetEntry())
            {
                case NPC_YSERA_MADNESS_OF_DEATHWING:
                case NPC_ALEXSTRASZA_MADNESS_OF_DEATHWING:
                case NPC_NOZDORMU_MADNESS_OF_DEATHWING:
                case NPC_KALECGOS_MADNESS_OF_DEATHWING:
                    creature->setActive(true); // Ugly as fuck but the boss area is just too big...
                    break;
                default:
                    break;
            }
        }

        void OnPlayerEnter(Player* player) override
        {
            if (GetBossState(DATA_MADNESS_OF_DEATHWING) == DONE)
                player->CastSpell(player, SPELL_CALM_MAELSTROM_SKYBOX);
        }
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_dragon_soul_InstanceMapScript(map);
    }
};

void AddSC_instance_dragon_soul()
{
    new instance_dragon_soul();
}
