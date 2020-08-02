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

#include "end_time.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "InstanceScript.h"
#include "ScriptMgr.h"

ObjectData const creatureData[] =
{
    { BOSS_MUROZOND,                        DATA_MUROZOND                       },
    { NPC_NOZDORMU_BRONZE_DRAGON_SHRINE,    DATA_NOZDORMU_BRONZE_DRAGON_SHRINE  },
    { 0,                                    0                                   } // END
};

ObjectData const gameobjectData[] =
{
    { GO_HOURGLASS_OF_TIME, DATA_HOURGLASS_OF_TIME } // END
};

DoorData const doorData[] =
{
    { 0, 0, DOOR_TYPE_ROOM } // END
};

class instance_end_time : public InstanceMapScript
{
public:
    instance_end_time() : InstanceMapScript(ETScriptName, 938) { }

    struct instance_end_time_InstanceMapScript : public InstanceScript
    {
        instance_end_time_InstanceMapScript(InstanceMap* map) : InstanceScript(map), _killedInfiniteDragonkins(0)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            LoadDoorData(doorData);
            LoadObjectData(creatureData, gameobjectData);
        }

        void OnUnitDeath(Unit* unit) override
        {
            if (!unit->IsCreature())
                return;

            switch (unit->GetEntry())
            {
                case NPC_INFINITE_SUPRESSOR:
                case NPC_INFINITE_WARDEN:
                    ++_killedInfiniteDragonkins;
                    if (_killedInfiniteDragonkins == 4 || _killedInfiniteDragonkins == 8)
                        if (Creature* murozond = GetCreature(DATA_MUROZOND))
                            if (murozond->IsAIEnabled)
                                murozond->AI()->SetData(DATA_MUROZOND_INTRO, _killedInfiniteDragonkins == 4 ? IN_PROGRESS : DONE);
                    break;
                default:
                    break;
            }
        }
    private:
        uint8 _killedInfiniteDragonkins;
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_end_time_InstanceMapScript(map);
    }
};

void AddSC_instance_end_time()
{
    new instance_end_time();
}
