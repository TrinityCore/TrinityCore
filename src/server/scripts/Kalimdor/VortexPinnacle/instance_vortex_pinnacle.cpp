/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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
 
#include "vortex_pinnacle.h"
#include "ScriptPCH.h"

#define MAX_ENCOUNTER 3

class instance_vortex_pinnacle : public InstanceMapScript
{
    public:
        instance_vortex_pinnacle() : InstanceMapScript("instance_vortex_pinnacle", 657) { }

        struct instance_vortex_pinnacle_InstanceMapScript : public InstanceScript
        {
            instance_vortex_pinnacle_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                GrandVizierErtan = 0;

                memset(&Encounter, 0, sizeof(Encounter));
            }

            void OnCreatureCreate(Creature* creature)
            {
                switch (creature->GetEntry())
                {
                    case BOSS_GRAND_VIZIER_ERTAN:
                        GrandVizierErtan = creature->GetGUID();
                    break;
                }
            }

            void OnGameObjectCreate(GameObject* go) {}

            uint64 GetData64(uint32 type)
            {
                return 0;
            }

            uint32 GetData(uint32 type)
            {
                return Encounter[type];
            }

            void SetData(uint32 uiType, uint32 uiData)
            {
                Encounter[uiType] = uiData;

                if (uiData == DONE)
                    SaveToDB();
            }

            std::string GetSaveData()
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;
                saveStream << "H O O " << GetBossSaveData();

                OUT_SAVE_INST_DATA_COMPLETE;
                return saveStream.str();
            }

            void Load(const char* in)
            {
                if (!in)
                {
                    OUT_LOAD_INST_DATA_FAIL;
                    return;
                }

                OUT_LOAD_INST_DATA(in);

                char dataHead1, dataHead2, dataHead3;

                std::istringstream loadStream(in);
                loadStream >> dataHead1 >> dataHead2 >> dataHead3;

                /*if (dataHead1 == 'H' && dataHead2 == 'O' && dataHead3 == 'O')
                {
                    for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                    {
                        uint32 tmpState;
                        loadStream >> tmpState;
                        if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
                            tmpState = NOT_STARTED;
                        SetBossState(i, EncounterState(tmpState));
                    }
                } else OUT_LOAD_INST_DATA_FAIL;*/

                OUT_LOAD_INST_DATA_COMPLETE;
            }

        private:
            uint32 Encounter[MAX_ENCOUNTER];
            uint64 GrandVizierErtan;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const
        {
            return new instance_vortex_pinnacle_InstanceMapScript(map);
        }
};

void AddSC_instance_vortex_pinnacle()
{
    new instance_vortex_pinnacle();
}