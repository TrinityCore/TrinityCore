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
#include "magisters_terrace.h"

/*
0  - Selin Fireheart
1  - Vexallus
2  - Priestess Delrissa
3  - Kael'thas Sunstrider
*/

DoorData const doorData[] =
{
    { GO_SELIN_DOOR,           DATA_SELIN,    DOOR_TYPE_PASSAGE, BOUNDARY_NONE },
    { GO_SELIN_ENCOUNTER_DOOR, DATA_SELIN,    DOOR_TYPE_ROOM,    BOUNDARY_NONE },
    { GO_VEXALLUS_DOOR,        DATA_VEXALLUS, DOOR_TYPE_PASSAGE, BOUNDARY_NONE },
    { GO_DELRISSA_DOOR,        DATA_DELRISSA, DOOR_TYPE_PASSAGE, BOUNDARY_NONE },
    { GO_KAEL_DOOR,            DATA_KAELTHAS, DOOR_TYPE_ROOM,    BOUNDARY_NONE },
    { 0,                       0,             DOOR_TYPE_ROOM,    BOUNDARY_NONE } // END
};

class instance_magisters_terrace : public InstanceMapScript
{
    public:
        instance_magisters_terrace() : InstanceMapScript("instance_magisters_terrace", 585) { }

        struct instance_magisters_terrace_InstanceMapScript : public InstanceScript
        {
            instance_magisters_terrace_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                SetBossNumber(EncounterCount);
                LoadDoorData(doorData);

                FelCrystals.clear();
                DelrissaDeathCount = 0;

                SelinGUID          = 0;
                DelrissaGUID       = 0;
                EscapeOrbGUID      = 0;
                FelCristalIndex    = 0;

                memset(KaelStatue, 0, 2 * sizeof(uint64));
            }

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_DELRISSA_DEATH_COUNT:
                        return DelrissaDeathCount;
                    case DATA_FEL_CRYSTAL_SIZE:
                        return uint32(FelCrystals.size());
                    default:
                        break;
                }
                return 0;
            }

            void SetData(uint32 type, uint32 data) override
            {
                switch (type)
                {
                    case DATA_DELRISSA_DEATH_COUNT:
                        if (data == SPECIAL)
                            ++DelrissaDeathCount;
                        else
                            DelrissaDeathCount = 0;
                        break;
                    case DATA_KAELTHAS_STATUES:
                        HandleGameObject(KaelStatue[0], data);
                        HandleGameObject(KaelStatue[1], data);
                        break;
                    default:
                        break;
                }
            }

            void OnCreatureCreate(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case NPC_SELIN:
                        SelinGUID = creature->GetGUID();
                        break;
                    case NPC_DELRISSA:
                        DelrissaGUID = creature->GetGUID();
                        break;
                    case NPC_FELCRYSTALS:
                        FelCrystals.push_back(creature->GetGUID());
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                    case GO_VEXALLUS_DOOR:
                    case GO_SELIN_DOOR:
                    case GO_SELIN_ENCOUNTER_DOOR:
                    case GO_DELRISSA_DOOR:
                    case GO_KAEL_DOOR:
                        AddDoor(go, true);
                        break;
                    case GO_KAEL_STATUE_1:
                        KaelStatue[0] = go->GetGUID();
                        break;
                    case GO_KAEL_STATUE_2:
                        KaelStatue[1] = go->GetGUID();
                        break;
                    case GO_ESCAPE_ORB:
                        EscapeOrbGUID = go->GetGUID();
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectRemove(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                    case GO_VEXALLUS_DOOR:
                    case GO_SELIN_DOOR:
                    case GO_SELIN_ENCOUNTER_DOOR:
                    case GO_DELRISSA_DOOR:
                    case GO_KAEL_DOOR:
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
                    case DATA_DELRISSA:
                        if (type == IN_PROGRESS)
                            DelrissaDeathCount = 0;
                        break;
                    default:
                        break;
                }
                return true;
            }

            std::string GetSaveData() override
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;
                saveStream << "M T " << GetBossSaveData();

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
                if (dataHead1 == 'M' && dataHead2 == 'T')
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

            uint64 GetData64(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_SELIN:
                        return SelinGUID;
                    case DATA_DELRISSA:
                        return DelrissaGUID;
                    case DATA_KAEL_STATUE_LEFT:
                        return KaelStatue[0];
                    case DATA_KAEL_STATUE_RIGHT:
                        return KaelStatue[1];
                    case DATA_ESCAPE_ORB:
                        return EscapeOrbGUID;
                    case DATA_FEL_CRYSTAL:
                        if (FelCrystals.size() < FelCristalIndex)
                        {
                            TC_LOG_ERROR("scripts", "Magisters Terrace: No Fel Crystals loaded in Inst Data");
                            return 0;
                        }

                        return FelCrystals.at(FelCristalIndex);
                    default:
                        break;
                }
                return 0;
            }

            void SetData64(uint32 type, uint64 value) override
            {
                if (type == DATA_FEL_CRYSTAL)
                    FelCristalIndex = value;
            }

        protected:
            std::vector<uint64> FelCrystals;

            uint64 SelinGUID;
            uint64 DelrissaGUID;
            uint64 KaelStatue[2];
            uint64 EscapeOrbGUID;
            uint32 DelrissaDeathCount;
            uint8 FelCristalIndex;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_magisters_terrace_InstanceMapScript(map);
        }
};

void AddSC_instance_magisters_terrace()
{
    new instance_magisters_terrace();
}
