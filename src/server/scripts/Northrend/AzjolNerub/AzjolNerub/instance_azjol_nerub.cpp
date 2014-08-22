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
#include "azjol_nerub.h"

DoorData const doorData[] =
{
    { GO_KRIKTHIR_DOOR,     DATA_KRIKTHIR_THE_GATEWATCHER,  DOOR_TYPE_PASSAGE,  BOUNDARY_NONE },
    { GO_ANUBARAK_DOOR_1,   DATA_ANUBARAK,                  DOOR_TYPE_ROOM,     BOUNDARY_NONE },
    { GO_ANUBARAK_DOOR_2,   DATA_ANUBARAK,                  DOOR_TYPE_ROOM,     BOUNDARY_NONE },
    { GO_ANUBARAK_DOOR_3,   DATA_ANUBARAK,                  DOOR_TYPE_ROOM,     BOUNDARY_NONE },
    { 0,                    0,                              DOOR_TYPE_ROOM,     BOUNDARY_NONE } // END
};

class instance_azjol_nerub : public InstanceMapScript
{
    public:
        instance_azjol_nerub() : InstanceMapScript(AzjolNerubScriptName, 601) { }

        struct instance_azjol_nerub_InstanceScript : public InstanceScript
        {
            instance_azjol_nerub_InstanceScript(Map* map) : InstanceScript(map)
            {
                SetBossNumber(EncounterCount);
                LoadDoorData(doorData);

                KrikthirGUID        = 0;
                HadronoxGUID        = 0;
                AnubarakGUID        = 0;
                WatcherGashraGUID   = 0;
                WatcherSilthikGUID  = 0;
                WatcherNarjilGUID   = 0;
            }

            void OnCreatureCreate(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case NPC_KRIKTHIR:
                        KrikthirGUID = creature->GetGUID();
                        break;
                    case NPC_HADRONOX:
                        HadronoxGUID = creature->GetGUID();
                        break;
                    case NPC_ANUBARAK:
                        AnubarakGUID = creature->GetGUID();
                        break;
                    case NPC_WATCHER_NARJIL:
                        WatcherNarjilGUID = creature->GetGUID();
                        break;
                    case NPC_WATCHER_GASHRA:
                        WatcherGashraGUID = creature->GetGUID();
                        break;
                    case NPC_WATCHER_SILTHIK:
                        WatcherSilthikGUID = creature->GetGUID();
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                    case GO_KRIKTHIR_DOOR:
                    case GO_ANUBARAK_DOOR_1:
                    case GO_ANUBARAK_DOOR_2:
                    case GO_ANUBARAK_DOOR_3:
                        AddDoor(go, true);
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectRemove(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                    case GO_KRIKTHIR_DOOR:
                    case GO_ANUBARAK_DOOR_1:
                    case GO_ANUBARAK_DOOR_2:
                    case GO_ANUBARAK_DOOR_3:
                        AddDoor(go, false);
                        break;
                    default:
                        break;
                }
            }

            uint64 GetData64(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_KRIKTHIR_THE_GATEWATCHER:
                        return KrikthirGUID;
                    case DATA_HADRONOX:
                        return HadronoxGUID;
                    case DATA_ANUBARAK:
                        return AnubarakGUID;
                    case DATA_WATCHER_GASHRA:
                        return WatcherGashraGUID;
                    case DATA_WATCHER_SILTHIK:
                        return WatcherSilthikGUID;
                    case DATA_WATCHER_NARJIL:
                        return WatcherNarjilGUID;
                    default:
                        break;
                }

                return 0;
            }

            std::string GetSaveData() override
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;
                saveStream << "A N " << GetBossSaveData();

                OUT_SAVE_INST_DATA_COMPLETE;
                return saveStream.str();
            }

            void Load(char const* str) override
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

                if (dataHead1 == 'A' && dataHead2 == 'N')
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
            uint64 KrikthirGUID;
            uint64 HadronoxGUID;
            uint64 AnubarakGUID;
            uint64 WatcherGashraGUID;
            uint64 WatcherSilthikGUID;
            uint64 WatcherNarjilGUID;
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
