/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

#include "terrace_of_endless_spring.h"

DoorData const doorData[] =
{
    {0,                                      0,                         DOOR_TYPE_ROOM,       BOUNDARY_NONE},// END
};

class instance_terrace_of_endless_spring : public InstanceMapScript
{
    public:
        instance_terrace_of_endless_spring() : InstanceMapScript("instance_terrace_of_endless_spring", 996) { }

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_terrace_of_endless_spring_InstanceMapScript(map);
        }

        struct instance_terrace_of_endless_spring_InstanceMapScript : public InstanceScript
        {
            instance_terrace_of_endless_spring_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                kaolanGUID = 0;
                regailGUID = 0;
                asaniGUID = 0;
                tsulongGUID = 0;
                leishiGUID = 0;
                shaoffearGUID = 0;
            }
            
            uint32 dataStorage[MAX_DATA];

            void Initialize()
            {
                SetBossNumber(MAX_DATA);
                LoadDoorData(doorData);

                memset(dataStorage, 0, MAX_DATA * sizeof(uint32));
            }

            void OnCreatureCreate(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case NPC_KAOLAN:        kaolanGUID      = creature->GetGUID(); break;
                    case NPC_REGAIL:        regailGUID      = creature->GetGUID(); break;
                    case NPC_ASANI:         asaniGUID       = creature->GetGUID(); break;
                    case NPC_TSULONG:       tsulongGUID     = creature->GetGUID(); break;
                    case NPC_LEI_SHI:       leishiGUID      = creature->GetGUID(); break;
                    case NPC_SHA_OF_FEAR:   shaoffearGUID   = creature->GetGUID(); break;
                    default:
                        break;
                }
            }

            void SetData(uint32 type, uint32 data) override
            {
                if (type < MAX_DATA)
                    dataStorage[type] = data;
            }

            uint32 GetData(uint32 type) const override
            {
                if (type < MAX_DATA)
                    return dataStorage[type];

                return 0;
            }

            uint64 GetData64(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_KAOLAN:        return kaolanGUID;
                    case DATA_REGAIL:        return regailGUID;
                    case DATA_ASANI:         return asaniGUID;
                    case DATA_TSULONG:       return tsulongGUID;
                    case DATA_LEI_SHI:       return leishiGUID;
                    case DATA_SHA_OF_FEAR:   return shaoffearGUID;
                    default:
                        break;
                }

                return 0;
            }

            std::string GetSaveData() override
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;
                saveStream << "T E S " << GetBossSaveData();

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

                char dataHead1, dataHead2, dataHead3;

                std::istringstream loadStream(str);
                loadStream >> dataHead1 >> dataHead2 >> dataHead3;

                if (dataHead1 == 'T' && dataHead2 == 'E' && dataHead3 == 'S')
                {
                    for (uint8 i = 0; i < MAX_DATA; ++i)
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
                uint64 kaolanGUID;
                uint64 regailGUID;
                uint64 asaniGUID;
                uint64 tsulongGUID;
                uint64 leishiGUID;
                uint64 shaoffearGUID;
        };
};

void AddSC_instance_terrace_of_endless_spring()
{
    new instance_terrace_of_endless_spring();
}
