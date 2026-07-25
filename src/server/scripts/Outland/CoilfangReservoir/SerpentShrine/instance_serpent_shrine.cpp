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
#include "EventMap.h"
#include "InstanceScript.h"
#include "Map.h"
#include "serpent_shrine.h"

/* Serpentshrine cavern encounters:
0 - Hydross The Unstable event
1 - Leotheras The Blind Event
2 - The Lurker Below Event
3 - Fathom-Lord Karathress Event
4 - Morogrim Tidewalker Event
5 - Lady Vashj Event
*/

static constexpr ObjectData creatureData[] =
{
    { NPC_CARIBDIS,            DATA_CARIBDIS               },
    { NPC_TIDALVESS,           DATA_TIDALVESS              },
    { NPC_SHARKKIS,            DATA_SHARKKIS               },
    { NPC_KARATHRESS,          BOSS_FATHOM_LORD_KARATHRESS },
    { NPC_LEOTHERAS_THE_BLIND, BOSS_LEOTHERAS_THE_BLIND    },
    { NPC_LADY_VASHJ,          BOSS_LADY_VASHJ             },
    { 0,                       0                           } // END
};

static constexpr ObjectData gameObjectData[] =
{
    { GO_BRIDGE_PART_1,           DATA_BRIDGE_PART_1      },
    { GO_BRIDGE_PART_2,           DATA_BRIDGE_PART_2      },
    { GO_BRIDGE_PART_3,           DATA_BRIDGE_PART_3      },
    { GO_SHIELD_GENERATOR_1,      DATA_SHIELD_GENERATOR_1 },
    { GO_SHIELD_GENERATOR_2,      DATA_SHIELD_GENERATOR_2 },
    { GO_SHIELD_GENERATOR_3,      DATA_SHIELD_GENERATOR_3 },
    { GO_SHIELD_GENERATOR_4,      DATA_SHIELD_GENERATOR_4 },
    { 0,                          0                       } // END
};

class instance_serpent_shrine : public InstanceMapScript
{
    public:
        instance_serpent_shrine() : InstanceMapScript(SSCScriptName, 548) { }

        struct instance_serpentshrine_cavern_InstanceMapScript : public InstanceScript
        {
            instance_serpentshrine_cavern_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadObjectData(creatureData, gameObjectData);

                KilledElitesCount = 0;
            }

            void OnUnitDeath(Unit* unit) override
            {
                switch (unit->GetEntry())
                {
                    case NPC_COILFANG_PRIESTESS:
                    case NPC_COILFANG_SHATTERER:
                        if (KilledElitesCount < MIN_KILLED_ELITES)
                            ++KilledElitesCount;
                        SaveToDB();
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
                    case BOSS_THE_LURKER_BELOW:
                        if (state == FAIL)
                            Events.ScheduleEvent(EVENT_RESPAWN_STRANGE_POOL, 15s);
                        break;
                    default:
                        break;
                }

                return true;
            }

            uint32 GetData(uint32 type) const override
            {
                if (type == DATA_KILLED_ELITES)
                    return KilledElitesCount;

                return 0;
            }

            void Update(uint32 diff) override
            {
                Events.Update(diff);

                if (Events.ExecuteEvent() == EVENT_RESPAWN_STRANGE_POOL)
                    SetBossState(BOSS_THE_LURKER_BELOW, NOT_STARTED);
            }

            void WriteSaveDataMore(std::ostringstream& stream) override
            {
                stream << KilledElitesCount;
            }

            void ReadSaveDataMore(std::istringstream& stream) override
            {
                stream >> KilledElitesCount;
            }

        protected:
            EventMap Events;
            uint32 KilledElitesCount;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_serpentshrine_cavern_InstanceMapScript(map);
        }
};

void AddSC_instance_serpentshrine_cavern()
{
    new instance_serpent_shrine();
}
