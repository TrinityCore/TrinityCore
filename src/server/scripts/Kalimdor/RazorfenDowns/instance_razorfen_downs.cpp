/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "razorfen_downs.h"

#define    MAX_ENCOUNTER  1

class instance_razorfen_downs : public InstanceMapScript
{
public:
    instance_razorfen_downs() : InstanceMapScript("instance_razorfen_downs", 129) { }

    InstanceScript* GetInstanceScript(InstanceMap* pMap) const
    {
        return new instance_razorfen_downs_InstanceMapScript(pMap);
    }

    struct instance_razorfen_downs_InstanceMapScript : public InstanceScript
    {
        instance_razorfen_downs_InstanceMapScript(Map* pMap) : InstanceScript(pMap)
        {
            Initialize();
        };

        uint64 uiGongGUID;

        uint32 m_auiEncounter[MAX_ENCOUNTER];

        uint16 uiGongWaves;

        std::string str_data;

        void Initialize()
        {
            uiGongGUID = 0;

            uiGongWaves = 0;

            memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));
        }

        std::string GetSaveData()
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;

            saveStream << "T C " << m_auiEncounter[0]
                << " " << uiGongWaves;

            str_data = saveStream.str();

            OUT_SAVE_INST_DATA_COMPLETE;
            return str_data;
        }

        void Load(const char* in)
        {
            if (!in)
            {
                OUT_LOAD_INST_DATA_FAIL;
                return;
            }

            OUT_LOAD_INST_DATA(in);

            char dataHead1, dataHead2;
            uint16 data0, data1;

            std::istringstream loadStream(in);
            loadStream >> dataHead1 >> dataHead2 >> data0 >> data1;

            if (dataHead1 == 'T' && dataHead2 == 'C')
            {
                m_auiEncounter[0] = data0;

                for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                    if (m_auiEncounter[i] == IN_PROGRESS)
                        m_auiEncounter[i] = NOT_STARTED;

                uiGongWaves = data1;
            } else OUT_LOAD_INST_DATA_FAIL;

            OUT_LOAD_INST_DATA_COMPLETE;
        }

        void OnGameObjectCreate(GameObject* pGo, bool /*bAdd*/)
        {
            switch(pGo->GetEntry())
            {
                case GO_GONG:
                    uiGongGUID = pGo->GetGUID();
                    if (m_auiEncounter[0] == DONE)
                        pGo->SetFlag(GAMEOBJECT_FLAGS,GO_FLAG_UNK1);
                    break;
                default:
                    break;
            }
        }

        void SetData(uint32 uiType, uint32 uiData)
        {
            if (uiType == DATA_GONG_WAVES)
            {
                uiGongWaves = uiData;

                switch(uiGongWaves)
                {
                    case 9:
                    case 14:
                        if (GameObject* pGo = instance->GetGameObject(uiGongGUID))
                            pGo->RemoveFlag(GAMEOBJECT_FLAGS,GO_FLAG_UNK1);
                        break;
                    case 1:
                    case 10:
                    case 16:
                    {
                        GameObject* pGo = instance->GetGameObject(uiGongGUID);

                        if (!pGo)
                            return;

                        pGo->SetFlag(GAMEOBJECT_FLAGS,GO_FLAG_UNK1);

                        uint32 uiCreature = 0;
                        uint8 uiSummonTimes = 0;

                        switch(uiGongWaves)
                        {
                            case 1:
                                uiCreature = CREATURE_TOMB_FIEND;
                                uiSummonTimes = 7;
                                break;
                            case 10:
                                uiCreature = CREATURE_TOMB_REAVER;
                                uiSummonTimes = 3;
                                break;
                            case 16:
                                uiCreature = CREATURE_TUTEN_KASH;
                                break;
                            default:
                                break;
                        }


                        if (Creature* pCreature = pGo->SummonCreature(uiCreature,2502.635f,844.140f,46.896f,0.633f))
                        {
                            if (uiGongWaves == 10 || uiGongWaves == 1)
                            {
                                for (uint8 i = 0; i < uiSummonTimes; ++i)
                                {
                                    if (Creature* pSummon = pGo->SummonCreature(uiCreature,2502.635f + float(irand(-5,5)),844.140f + float(irand(-5,5)),46.896f,0.633f))
                                        pSummon->GetMotionMaster()->MovePoint(0,2533.479f + float(irand(-5,5)),870.020f + float(irand(-5,5)),47.678f);
                                }
                            }
                            pCreature->GetMotionMaster()->MovePoint(0,2533.479f + float(irand(-5,5)),870.020f + float(irand(-5,5)),47.678f);
                        }
                        break;
                    }
                    default:
                        break;
                }
            }

            if (uiType == BOSS_TUTEN_KASH)
            {
                m_auiEncounter[0] = uiData;

                if (uiData == DONE)
                    SaveToDB();
            }
        }

        uint32 GetData(uint32 uiType)
        {
            switch(uiType)
            {
                case DATA_GONG_WAVES:
                    return uiGongWaves;
            }

            return 0;
        }

        uint64 GetData64(uint32 uiType)
        {
            switch(uiType)
            {
                case DATA_GONG: return uiGongGUID;
            }

            return 0;
        }
    };

};


void AddSC_instance_razorfen_downs()
{
    new instance_razorfen_downs();
}
