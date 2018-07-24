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
#include "blackrock_caverns.h"
#include "InstanceScript.h"
#include "Map.h"

ObjectData const creatureData[] =
{
    { BOSS_ROMOGG_BONECRUSHER,          DATA_ROMOGG_BONECRUSHER         },
    { BOSS_CORLA_HERALD_OF_TWILIGHT,    DATA_CORLA_HERALD_OF_TWILIGHT   },
    { NPC_RAZ_THE_CRAZED,               DATA_RAZ_THE_CRAZED             },
    { 0,                                0                               }
};

class instance_blackrock_caverns : public InstanceMapScript
{
    public:
        instance_blackrock_caverns(): InstanceMapScript(BCScriptName, 645) { }

        struct instance_blackrock_caverns_InstanceMapScript : public InstanceScript
        {
            instance_blackrock_caverns_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadObjectData(creatureData, nullptr);
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                switch (type)
                {
                    case DATA_ROMOGG_BONECRUSHER:
                    case DATA_CORLA_HERALD_OF_TWILIGHT:
                    case DATA_KARSH_STEELBENDER:
                    case DATA_BEAUTY:
                    case DATA_ASCENDANT_LORD_OBSIDIUS:
                        break;
                    default:
                        break;
                }

                return true;
            }

            void OnCreatureCreate(Creature* creature) override
            {
                InstanceScript::OnCreatureCreate(creature);

                switch (creature->GetEntry())
                {
                    case NPC_QUAKE:
                    case NPC_ANGERED_EARTH:
                        if (Creature* romogg = GetCreature(DATA_ROMOGG_BONECRUSHER))
                            romogg->AI()->JustSummoned(creature);
                        break;
                    default:
                        break;
                }
            }
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_blackrock_caverns_InstanceMapScript(map);
        }
};

void AddSC_instance_blackrock_caverns()
{
    new instance_blackrock_caverns();
}
