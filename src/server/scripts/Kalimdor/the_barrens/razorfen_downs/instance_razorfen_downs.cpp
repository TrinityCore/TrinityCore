/*
 * Copyright (C) 2010 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "scriptPCH.h"
#include "razorfen_downs.h"

#define    MAX_ENCOUNTER  1

struct instance_razorfen_downs : public ScriptedInstance
{
    instance_razorfen_downs(Map* pMap) : ScriptedInstance(pMap)
    {
        Initialize();
    };

    uint64 uiGongGUID;
    uint64 uiCupFire1GUID;
    uint64 uiCupFire2GUID;

    uint32 m_auiEncounter[MAX_ENCOUNTER];

    uint8 uiGongWaves;

    std::string str_data;
    std::string strInstData;

    void Initialize() override
    {
        uiGongGUID = 0;

        uiCupFire1GUID = 0;

        uiCupFire2GUID = 0;

        uiGongWaves = 0;

        memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));
    }

    void Load(char const* chrIn) override
    {
        if (!chrIn)
        {
            OUT_LOAD_INST_DATA_FAIL;
            return;
        }

        OUT_LOAD_INST_DATA(chrIn);

        std::istringstream loadStream(chrIn);
        loadStream >> m_auiEncounter[0];


        for (uint32 & i : m_auiEncounter)
            if (i == IN_PROGRESS)
                i = NOT_STARTED;

        OUT_LOAD_INST_DATA_COMPLETE;
    }

    void OnObjectCreate(GameObject* pGo) override
    {
        switch (pGo->GetEntry())
        {
            case GO_GONG:
                uiGongGUID = pGo->GetGUID();
                if (m_auiEncounter[0] == DONE)
                    pGo->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NO_INTERACT);
                break;
            case GO_IDOL_CUP_FIRE:
                if (uiCupFire1GUID != 0)
                    uiCupFire2GUID = pGo->GetGUID();
                else
                    uiCupFire1GUID = pGo->GetGUID();
                break;
            default:
                break;
        }
    }

    void SetData(uint32 uiType, uint32 uiData) override
    {
        if (uiType == DATA_GONG_WAVES)
        {
            uiGongWaves = uiData;
            switch (uiGongWaves)
            {
                case 9:
                case 14:
                    if (GameObject* pGo = instance->GetGameObject(uiGongGUID))
                        pGo->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NO_INTERACT);
                    break;
                case 1:
                case 10:
                case 15:
                {
                    GameObject* pGo = instance->GetGameObject(uiGongGUID);

                    if (!pGo)
                        return;

                    pGo->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NO_INTERACT);

                    uint32 uiCreature = 0;
                    uint8 uiSummonTimes = 0;

                    switch (uiGongWaves)
                    {
                        case 1:
                            uiCreature = CREATURE_TOMB_FIEND;
                            uiSummonTimes = 7;
                            break;
                        case 10:
                            uiCreature = CREATURE_TOMB_REAVER;
                            uiSummonTimes = 3;
                            break;
                        case 15:
                            uiCreature = CREATURE_TUTEN_KASH;
                            break;
                        default:
                            break;
                    }

                    if (Creature* pCreature = pGo->SummonCreature(uiCreature, 2502.635f, 844.140f, 46.896f, 0.633f))
                    {
                        if (uiGongWaves == 10 || uiGongWaves == 1)
                        {
                            float x, y, z;
                            for (uint8 i = 0; i < uiSummonTimes; ++i)
                            {
                                if (i % 2 == 1)
                                {
                                    x = 2502.635f;
                                    y = 844.140f;
                                    z = 46.896f;
                                }
                                else
                                {
                                    x = 2546.33f;
                                    y = 887.455f;
                                    z = 47.69f;
                                }
                                if (Creature* pSummon = pGo->SummonCreature(uiCreature, x + float(irand(-5, 5)), y + float(irand(-5, 5)), z, 0.633f))
                                {
                                    pSummon->SetWalk(false);
                                    pSummon->GetMotionMaster()->MovePoint(0, 2533.479f + float(irand(-5, 5)), 870.020f + float(irand(-5, 5)), 47.678f, MOVE_PATHFINDING);
                                }
                            }
                        }
                        pCreature->SetWalk(false);
                        pCreature->GetMotionMaster()->MovePoint(0, 2533.479f + float(irand(-5, 5)), 870.020f + float(irand(-5, 5)), 47.678f, MOVE_PATHFINDING);
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

        if (uiType == EXTINGUISH_FIRES)
        {
            if (GameObject* pGoCupFire1 = instance->GetGameObject(uiCupFire1GUID))
                pGoCupFire1->SetLootState(GO_JUST_DEACTIVATED);
            if (GameObject* pGoCupFire2 = instance->GetGameObject(uiCupFire2GUID))
                pGoCupFire2->SetLootState(GO_JUST_DEACTIVATED);
        }

        if (uiData == DONE)
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;
            saveStream << m_auiEncounter[0];

            strInstData = saveStream.str();

            SaveToDB();
            OUT_SAVE_INST_DATA_COMPLETE;
        }

    }

    uint32 GetData(uint32 uiType) override
    {
        switch (uiType)
        {
            case DATA_GONG_WAVES:
                return uiGongWaves;
        }

        return 0;
    }

    uint64 GetData64(uint32 uiType) override
    {
        switch (uiType)
        {
            case DATA_GONG:
                return uiGongGUID;
        }

        return 0;
    }
};

InstanceData* GetInstanceData_instance_razorfen_downs(Map* pMap)
{
    return new instance_razorfen_downs(pMap);
}

void AddSC_instance_razorfen_downs()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "instance_razorfen_downs";
    newscript->GetInstanceData = &GetInstanceData_instance_razorfen_downs;
    newscript->RegisterSelf();
}
