/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "razorfen_downs.h"
#include "TemporarySummon.h"

Position const PosSummonTutenkash[15] =
{
    // 7349 Tomb Fiend
    { 2487.339f, 805.9111f, 43.08361f, 2.844887f  },
    { 2485.405f, 804.1145f, 43.68511f, 3.054326f  },
    { 2488.431f, 801.2809f, 42.70374f, 4.29351f   },
    { 2489.914f, 804.7949f, 43.25175f, 1.658063f  },
    { 2541.246f, 907.0941f, 46.64201f, 2.024582f  },
    { 2544.701f, 907.6331f, 46.38007f, 1.605703f  },
    { 2541.49f,  911.1756f, 46.26493f, 4.817109f  },
    { 2544.693f, 912.8887f, 46.39912f, 2.129302f  },
    { 2524.036f, 834.4852f, 48.37031f, 0.8028514f },
    { 2527.017f, 829.9793f, 48.06498f, 0.6981317f },
    // 7351 Tomb Reaver
    { 2542.818f, 904.9359f, 46.80911f, 4.642576f  },
    { 2543.287f, 911.2448f, 46.32785f, 0.6806784f },
    { 2489.083f, 806.5914f, 43.21102f, 3.682645f  },
    { 2486.828f, 802.8737f, 43.19883f, 2.9147f    },
    // 7355 Tuten'kash
    { 2487.939f, 804.2224f, 43.10735f, 1.692969f  }
};

class instance_razorfen_downs : public InstanceMapScript
{
public:
    instance_razorfen_downs() : InstanceMapScript(RFDScriptName, 129) { }

    struct instance_razorfen_downs_InstanceMapScript : public InstanceScript
    {
        instance_razorfen_downs_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            gongWave = 0;
            fiendsKilled = 0;
            reaversKilled = 0;
            summonLowRange = 0;
            summonHighRange = 0;
            summonCreature = 0;
        }

        void OnGameObjectCreate(GameObject* gameObject) override
        {
            switch (gameObject->GetEntry())
            {
                case GO_GONG:
                    goGongGUID = gameObject->GetGUID();
                    if (GetBossState(DATA_TUTEN_KASH) == DONE)
                        gameObject->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                    break;
                case GO_IDOL_OVEN_FIRE:
                case GO_IDOL_CUP_FIRE:
                case GO_IDOL_MOUTH_FIRE:
                    if (GetBossState(DATA_EXTINGUISHING_THE_IDOL) == DONE)
                        gameObject->Delete();
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
                case DATA_TUTEN_KASH:
                case DATA_MORDRESH_FIRE_EYE:
                case DATA_GLUTTON:
                case DATA_AMNENNAR_THE_COLD_BRINGER:
                case DATA_GONG:
                case DATA_WAVE:
                case DATA_EXTINGUISHING_THE_IDOL:
                    break;
                default:
                    break;
            }
            return true;
        }

        void SetData(uint32 type, uint32 data) override
        {
            if (type == DATA_WAVE)
            {
                switch (data)
                {
                    case IN_PROGRESS:
                    {
                        if (GameObject* go = instance->GetGameObject(goGongGUID))
                            go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);

                        switch (gongWave)
                        {
                            case 0:
                                summonLowRange = 0;
                                summonHighRange = 10;
                                summonCreature = NPC_TOMB_FIEND;
                                break;
                            case 1:
                                summonLowRange = 10;
                                summonHighRange = 14;
                                summonCreature = NPC_TOMB_REAVER;
                                break;
                            case 2:
                                summonLowRange = 14;
                                summonHighRange = 15;
                                summonCreature = NPC_TUTEN_KASH;
                                break;
                        }

                        if (GameObject* go = instance->GetGameObject(goGongGUID))
                            for (uint8 i = summonLowRange; i < summonHighRange; ++i)
                                if (Creature* creature = go->SummonCreature(summonCreature, PosSummonTutenkash[i]))
                                    creature->GetMotionMaster()->MovePoint(0, 2533.479f + float(irand(-5, 5)), 870.020f + float(irand(-5, 5)), 47.678f);

                        ++gongWave;
                        break;
                    }
                    case NPC_TOMB_FIEND:
                        if (++fiendsKilled == 10)
                        {
                            fiendsKilled = 0;
                            if (GameObject* go = instance->GetGameObject(goGongGUID))
                                go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                        }
                        break;
                    case NPC_TOMB_REAVER:
                        if (++reaversKilled == 4)
                        {
                            reaversKilled = 0;
                            if (GameObject* go = instance->GetGameObject(goGongGUID))
                                go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                        }
                        break;
                }
            }
        }

    protected:
        ObjectGuid goGongGUID;
        uint16 gongWave;
        uint8  fiendsKilled;
        uint8  reaversKilled;
        uint8  summonLowRange;
        uint8  summonHighRange;
        uint32 summonCreature;
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_razorfen_downs_InstanceMapScript(map);
    }
};

void AddSC_instance_razorfen_downs()
{
    new instance_razorfen_downs();
}
