/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
#include "InstanceScript.h"
#include "firelands.h"

DoorData const doorData[] =
{
    {GO_LORD_RHYOLITH_BRIDGE,    DATA_LORD_RHYOLITH,      DOOR_TYPE_ROOM,        BOUNDARY_E    },
    {GO_BETH_TILAC_DOOR,         DATA_BETH_TILAC,         DOOR_TYPE_ROOM,        BOUNDARY_SE   },
    //{GO_BALEROC_FIREWALL,        DATA_BALEROC,            DOOR_TYPE_ROOM,        BOUNDARY_S    },
    {GO_MAJORDOMO_FIREWALL,      DATA_MAJORDOMO_STAGHELM, DOOR_TYPE_PASSAGE,     BOUNDARY_N    },
    {GO_RAGNAROS_DOOR,           DATA_RAGNAROS,           DOOR_TYPE_ROOM,        BOUNDARY_S    },
    {0,                          0,                       DOOR_TYPE_ROOM,        BOUNDARY_NONE }, //END
}; //Baleroc door is special, it depends on the health status of the other bosses in the instance

class instance_firelands : public InstanceMapScript
{
    public:
        instance_firelands() : InstanceMapScript(FirelandsScriptName, 720) { }

        struct instance_firelands_InstanceScript : public InstanceScript
        {
            instance_firelands_InstanceScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadDoorData(doorData);

                BalerocGUID = 0;
            }

            void OnCreatureCreate(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case NPC_SMOULDERING_HATCHLING:
                        // Cannot directly start attacking here as the creature is not yet on map
                        creature->m_Events.AddEvent(new DelayedAttackStartEvent(creature), creature->m_Events.CalculateTime(500));
                        break;
                    case NPC_BALEROC:
                        BalerocGUID = creature->GetGUID();
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* go) OVERRIDE
            {
                switch(go->GetEntry())
                {
                    case GO_LORD_RHYOLITH_BRIDGE:
                    case GO_BETH_TILAC_DOOR:
                    //case GO_BALEROC_FIREWALL:
                    case GO_MAJORDOMO_FIREWALL:
                    case GO_RAGNAROS_DOOR:
                        AddDoor(go, true);
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectRemove(GameObject* go) OVERRIDE
            {
                switch (go->GetEntry())
                {
                    case GO_LORD_RHYOLITH_BRIDGE:
                    case GO_BETH_TILAC_DOOR:
                    //case GO_BALEROC_FIREWALL:
                    case GO_MAJORDOMO_FIREWALL:
                    case GO_RAGNAROS_DOOR:
                        AddDoor(go, false);
                        break;
                    default:
                        break;
                }
            }

            uint64 GetData64(uint32 type) const OVERRIDE
            {
                switch (type)
                {
                    case DATA_BALEROC:
                        return BalerocGUID;
                }

                return 0;
            }

            std::string GetSaveData() OVERRIDE
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;
                saveStream << "F L " << GetBossSaveData();

                OUT_SAVE_INST_DATA_COMPLETE;
                return saveStream.str();
            }

            void Load(const char* str) OVERRIDE
            {
                if (!str)
                {
                    OUT_LOAD_INST_DATA_FAIL;
                    return;
                }

                OUT_LOAD_INST_DATA(str);

                char dataHead1, dataHead2;

                std::istringstream loadStream(str);
                loadStream >> dataHead1 >> dataHead2;

                if (dataHead1 == 'F' && dataHead2 == 'L')
                {
                    for (uint32 i = 0; i < EncounterCount; ++i)
                    {
                        uint32 tmpState;
                        loadStream >> tmpState;
                        if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
                            tmpState = NOT_STARTED;
                        SetBossState(i, EncounterState(tmpState));
                    }

                    uint32 temp = 0;
                    loadStream >> temp;
                }
                else
                    OUT_LOAD_INST_DATA_FAIL;

                OUT_LOAD_INST_DATA_COMPLETE;
            }

            private:
                uint64 BalerocGUID;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_firelands_InstanceScript(map);
        }
};

void AddSC_instance_firelands()
{
    new instance_firelands();
}
