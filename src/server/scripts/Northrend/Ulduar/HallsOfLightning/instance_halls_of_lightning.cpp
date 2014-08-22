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
#include "halls_of_lightning.h"

DoorData const doorData[] =
{
    { GO_VOLKHAN_DOOR, DATA_VOLKHAN, DOOR_TYPE_PASSAGE, BOUNDARY_NONE },
    { GO_IONAR_DOOR,   DATA_IONAR,   DOOR_TYPE_PASSAGE, BOUNDARY_NONE },
    { GO_LOKEN_DOOR,   DATA_LOKEN,   DOOR_TYPE_PASSAGE, BOUNDARY_NONE },
    { 0,               0,            DOOR_TYPE_ROOM,    BOUNDARY_NONE } // END
};

class instance_halls_of_lightning : public InstanceMapScript
{
    public:
        instance_halls_of_lightning() : InstanceMapScript(HoLScriptName, 602) { }

        struct instance_halls_of_lightning_InstanceMapScript : public InstanceScript
        {
            instance_halls_of_lightning_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                SetBossNumber(EncounterCount);
                LoadDoorData(doorData);

                GeneralBjarngrimGUID = 0;
                VolkhanGUID          = 0;
                IonarGUID            = 0;
                LokenGUID            = 0;

                LokenGlobeGUID       = 0;
            }

            void OnCreatureCreate(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case NPC_BJARNGRIM:
                        GeneralBjarngrimGUID = creature->GetGUID();
                        break;
                    case NPC_VOLKHAN:
                        VolkhanGUID = creature->GetGUID();
                        break;
                    case NPC_IONAR:
                        IonarGUID = creature->GetGUID();
                        break;
                    case NPC_LOKEN:
                        LokenGUID = creature->GetGUID();
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                    case GO_VOLKHAN_DOOR:
                    case GO_IONAR_DOOR:
                    case GO_LOKEN_DOOR:
                        AddDoor(go, true);
                        break;
                    case GO_LOKEN_THRONE:
                        LokenGlobeGUID = go->GetGUID();
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectRemove(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                    case GO_VOLKHAN_DOOR:
                    case GO_IONAR_DOOR:
                    case GO_LOKEN_DOOR:
                        AddDoor(go, false);
                        break;
                    default:
                        break;
                }
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                switch (type)
                {
                    case DATA_LOKEN:
                        if (state == DONE)
                            if (GameObject* globe = instance->GetGameObject(LokenGlobeGUID))
                                globe->SendCustomAnim(0);
                        break;
                    default:
                        break;
                }

                return true;
            }

            uint64 GetData64(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_BJARNGRIM:
                        return GeneralBjarngrimGUID;
                    case DATA_VOLKHAN:
                        return VolkhanGUID;
                    case DATA_IONAR:
                        return IonarGUID;
                    case DATA_LOKEN:
                        return LokenGUID;
                    default:
                        break;
                }
                return 0;
            }

            std::string GetSaveData() override
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;
                saveStream << "H L " << GetBossSaveData();

                OUT_SAVE_INST_DATA_COMPLETE;
                return saveStream.str();
            }

            void Load(const char* str) override
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

                if (dataHead1 == 'H' && dataHead2 == 'L')
                {
                    for (uint32 i = 0; i < EncounterCount; ++i)
                    {
                        uint32 tmpState;
                        loadStream >> tmpState;
                        if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
                            tmpState = NOT_STARTED;
                        SetBossState(i, EncounterState(tmpState));
                    }
                }
                else
                    OUT_LOAD_INST_DATA_FAIL;

                OUT_LOAD_INST_DATA_COMPLETE;
            }

        protected:
            uint64 GeneralBjarngrimGUID;
            uint64 VolkhanGUID;
            uint64 IonarGUID;
            uint64 LokenGUID;

            uint64 LokenGlobeGUID;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_halls_of_lightning_InstanceMapScript(map);
        }
};

void AddSC_instance_halls_of_lightning()
{
    new instance_halls_of_lightning();
}
