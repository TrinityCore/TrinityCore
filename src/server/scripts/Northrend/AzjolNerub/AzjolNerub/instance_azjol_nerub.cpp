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
#include "azjol_nerub.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "InstanceScript.h"

DoorData const doorData[] =
{
    { GO_KRIKTHIR_DOOR,     DATA_KRIKTHIR,                  DOOR_TYPE_PASSAGE },
    { GO_ANUBARAK_DOOR_1,   DATA_ANUBARAK,                  DOOR_TYPE_ROOM    },
    { GO_ANUBARAK_DOOR_2,   DATA_ANUBARAK,                  DOOR_TYPE_ROOM    },
    { GO_ANUBARAK_DOOR_3,   DATA_ANUBARAK,                  DOOR_TYPE_ROOM    },
    { 0,                    0,                              DOOR_TYPE_ROOM    } // END
};

ObjectData const creatureData[] =
{
    { NPC_KRIKTHIR,        DATA_KRIKTHIR        },
    { NPC_HADRONOX,        DATA_HADRONOX        },
    { NPC_ANUBARAK,        DATA_ANUBARAK        },
    { NPC_WATCHER_NARJIL,  DATA_WATCHER_GASHRA  },
    { NPC_WATCHER_GASHRA,  DATA_WATCHER_SILTHIK },
    { NPC_WATCHER_SILTHIK, DATA_WATCHER_NARJIL  },
    { 0,                   0                    } // END
};

ObjectData const gameobjectData[] =
{
    { GO_ANUBARAK_DOOR_1, DATA_ANUBARAK_WALL   },
    { GO_ANUBARAK_DOOR_3, DATA_ANUBARAK_WALL_2 },
    { 0,                  0                    } // END
};

BossBoundaryData const boundaries =
{
    { DATA_KRIKTHIR, new RectangleBoundary(400.0f, 580.0f, 623.5f, 810.0f)     },
    { DATA_HADRONOX, new ZRangeBoundary(666.0f, 776.0f)                        },
    { DATA_ANUBARAK, new CircleBoundary(Position(550.6178f, 253.5917f), 26.0f) }
};

class instance_azjol_nerub : public InstanceMapScript
{
    public:
        instance_azjol_nerub() : InstanceMapScript(AzjolNerubScriptName, 601) { }

        struct instance_azjol_nerub_InstanceScript : public InstanceScript
        {
            instance_azjol_nerub_InstanceScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadBossBoundaries(boundaries);
                LoadDoorData(doorData);
                LoadObjectData(creatureData, gameobjectData);
                GateWatcherGreet = 0;
            }

            void OnUnitDeath(Unit* who) override
            {
                InstanceScript::OnUnitDeath(who);

                if (who->GetTypeId() != TYPEID_UNIT || GetBossState(DATA_KRIKTHIR) == DONE)
                    return;

                Creature* creature = who->ToCreature();
                if (creature->IsCritter() || creature->IsCharmedOwnedByPlayerOrPlayer())
                    return;

                if (Creature* gatewatcher = GetCreature(DATA_KRIKTHIR))
                    gatewatcher->AI()->DoAction(-ACTION_GATEWATCHER_GREET);
            }

            bool CheckRequiredBosses(uint32 bossId, Player const* player) const override
            {
                if (_SkipCheckRequiredBosses(player))
                    return true;

                if (bossId > DATA_KRIKTHIR && GetBossState(DATA_KRIKTHIR) != DONE)
                    return false;

                return true;
            }

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_GATEWATCHER_GREET:
                        return GateWatcherGreet;
                    default:
                        return 0;
                }
            }

            void SetData(uint32 type, uint32 data) override
            {
                switch (type)
                {
                    case DATA_GATEWATCHER_GREET:
                        GateWatcherGreet = data;
                        break;
                    default:
                        break;
                }
            }

        protected:
            uint8 GateWatcherGreet;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_azjol_nerub_InstanceScript(map);
        }
};

void AddSC_instance_azjol_nerub()
{
   new instance_azjol_nerub();
}
