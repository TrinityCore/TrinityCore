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

#include "heart_of_fear.h"
#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "ScriptedCreature.h"

DoorData const doorData[] =
{
    {0,                                      0,                         DOOR_TYPE_ROOM,       BOUNDARY_NONE},// END
};

class instance_heart_of_fear : public InstanceMapScript
{
    public:
        instance_heart_of_fear() : InstanceMapScript("instance_heart_of_fear", 1009) { }

        InstanceScript* GetInstanceScript(InstanceMap* map) const
        {
            return new instance_heart_of_fear_InstanceMapScript(map);
        }

        struct instance_heart_of_fear_InstanceMapScript : public InstanceScript
        {
            instance_heart_of_fear_InstanceMapScript(Map* map) : InstanceScript(map) {}

            uint64 vizierZorlockGUID;
            uint64 bladeLordTayakGUID;
            uint64 garalonGUID;
            uint64 windLordMeljarakGUID;
            uint64 amberShaperUnsokGUID;
            uint64 empressShekzeerGUID;

            uint32 dataStorage[MAX_DATA];

            void Initialize()
            {
                SetBossNumber(DATA_MAX_BOSS_DATA);
                LoadDoorData(doorData);

                memset(dataStorage, 0, MAX_DATA * sizeof(uint32));
            }

            void OnCreatureCreate(Creature* creature)
            {
                switch (creature->GetEntry())
                {
                    case NPC_ZORLOCK:  vizierZorlockGUID    = creature->GetGUID(); break;
                    case NPC_TAYAK:    bladeLordTayakGUID   = creature->GetGUID(); break;
                    case NPC_GARALON:  garalonGUID          = creature->GetGUID(); break;
                    case NPC_UNSOK:    windLordMeljarakGUID = creature->GetGUID(); break;
                    case NPC_SHEKZEER: amberShaperUnsokGUID = creature->GetGUID(); break;
                    case NPC_MELJARAK: empressShekzeerGUID  = creature->GetGUID(); break;
                    default:
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* go)
            {
            }

            bool SetBossState(uint32 id, EncounterState state)
            {
                if (!InstanceScript::SetBossState(id, state))
                    return false;

                return true;
            }

            void SetData(uint32 type, uint32 data)
            {
                switch (type)
                {
                    case 0:
                    default:
                        if (type < MAX_DATA)
                            dataStorage[type] = data;
                        break;
                }
            }

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                    case 0:
                    default:
                        if (type < MAX_DATA)
                            return dataStorage[type];
                        break;
                }

                return 0;
            }

            uint64 GetData64(uint32 type) const override
            {
                switch (type)
                {
                    case NPC_ZORLOCK:  return vizierZorlockGUID;
                    case NPC_TAYAK:    return bladeLordTayakGUID;
                    case NPC_GARALON:  return garalonGUID;
                    case NPC_UNSOK:    return windLordMeljarakGUID;
                    case NPC_SHEKZEER: return amberShaperUnsokGUID;
                    case NPC_MELJARAK: return empressShekzeerGUID;
                    default:
                        break;
                }

                return 0;
            }

            bool CheckRequiredBosses(uint32 bossId, Player const* player = NULL) const
            {
                if (!InstanceScript::CheckRequiredBosses(bossId, player))
                    return false;

                if (bossId > 0)
                    if (GetBossState(bossId - 1) != DONE)
                        return false;

                return true;
            }

            std::string GetSaveData() override
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;
                saveStream << "H F " << GetBossSaveData();

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

                if (dataHead1 == 'H' && dataHead2 == 'F')
                {
                    for (uint8 i = 0; i < DATA_MAX_BOSS_DATA; ++i)
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
        };
};

void AddSC_instance_heart_of_fear()
{
    new instance_heart_of_fear();
}
