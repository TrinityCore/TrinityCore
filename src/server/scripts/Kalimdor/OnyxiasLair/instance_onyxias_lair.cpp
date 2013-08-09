/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

/* ScriptData
SDName: Instance_Onyxias_Lair
SD%Complete: 100
SDComment:
SDCategory: Onyxia's Lair
EndScriptData */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "Cell.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "onyxias_lair.h"
#include "TemporarySummon.h"

class instance_onyxias_lair : public InstanceMapScript
{
public:
    instance_onyxias_lair() : InstanceMapScript("instance_onyxias_lair", 249) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const OVERRIDE
    {
        return new instance_onyxias_lair_InstanceMapScript(map);
    }

    struct instance_onyxias_lair_InstanceMapScript : public InstanceScript
    {
        instance_onyxias_lair_InstanceMapScript(Map* map) : InstanceScript(map) {}

        //Eruption is a BFS graph problem
        //One map to remember all floor, one map to keep floor that still need to erupt and one queue to know what needs to be removed

        void Initialize()
        {
            SetBossNumber(EncounterCount);

            onyxiaGUID               = 0;
            onyxiaLiftoffTimer       = 0;
            manyWhelpsCounter        = 0;
            eruptTimer               = 0;

            achievManyWhelpsHandleIt = false;
            achievSheDeepBreathMore  = true;
        }

        void OnCreatureCreate(Creature* creature)
        {
            switch (creature->GetEntry())
            {
                case NPC_ONYXIA:
                    onyxiaGUID = creature->GetGUID();
                    break;
            }
        }

        void OnGameObjectCreate(GameObject* go)
        {
            if ((go->GetGOInfo()->displayId == 4392 || go->GetGOInfo()->displayId == 4472) && go->GetGOInfo()->trap.spellId == 17731)
            {
                FloorEruptionGUID[0].insert(std::make_pair(go->GetGUID(), 0));
                return;
            }

            switch (go->GetEntry())
            {
                case GO_WHELP_SPAWNER:
                    Position goPos;
                    go->GetPosition(&goPos);
                    if (Creature* temp = go->SummonCreature(NPC_WHELP, goPos, TEMPSUMMON_CORPSE_DESPAWN))
                    {
                        temp->SetInCombatWithZone();
                        ++manyWhelpsCounter;
                    }
                    break;
            }
        }

        void OnGameObjectRemove(GameObject* go)
        {
            if ((go->GetGOInfo()->displayId == 4392 || go->GetGOInfo()->displayId == 4472) && go->GetGOInfo()->trap.spellId == 17731)
            {
                FloorEruptionGUID[0].erase(go->GetGUID());
                return;
            }
        }

        void FloorEruption(uint64 floorEruptedGUID)
        {
            if (GameObject* floorEruption = instance->GetGameObject(floorEruptedGUID))
            {
                //THIS GOB IS A TRAP - What shall i do? =(
                //Cast it spell? Copyed Heigan method
                floorEruption->SendCustomAnim(floorEruption->GetGoAnimProgress());
                floorEruption->CastSpell(NULL, Difficulty(instance->GetSpawnMode()) == RAID_DIFFICULTY_10MAN_NORMAL ? 17731 : 69294); //pFloorEruption->GetGOInfo()->trap.spellId

                //Get all immediatly nearby floors
                std::list<GameObject*> nearFloorList;
                Trinity::GameObjectInRangeCheck check(floorEruption->GetPositionX(), floorEruption->GetPositionY(), floorEruption->GetPositionZ(), 15);
                Trinity::GameObjectListSearcher<Trinity::GameObjectInRangeCheck> searcher(floorEruption, nearFloorList, check);
                floorEruption->VisitNearbyGridObject(999, searcher);
                //remove all that are not present on FloorEruptionGUID[1] and update treeLen on each GUID
                for (std::list<GameObject*>::const_iterator itr = nearFloorList.begin(); itr != nearFloorList.end(); ++itr)
                {
                    if (((*itr)->GetGOInfo()->displayId == 4392 || (*itr)->GetGOInfo()->displayId == 4472) && (*itr)->GetGOInfo()->trap.spellId == 17731)
                    {
                        uint64 nearFloorGUID = (*itr)->GetGUID();
                        if (FloorEruptionGUID[1].find(nearFloorGUID) != FloorEruptionGUID[1].end() && (*FloorEruptionGUID[1].find(nearFloorGUID)).second == 0)
                        {
                            (*FloorEruptionGUID[1].find(nearFloorGUID)).second = (*FloorEruptionGUID[1].find(floorEruptedGUID)).second+1;
                            FloorEruptionGUIDQueue.push(nearFloorGUID);
                        }
                    }
                }
            }
            FloorEruptionGUID[1].erase(floorEruptedGUID);
        }

        bool SetBossState(uint32 type, EncounterState state)
        {
            if (!InstanceScript::SetBossState(type, state))
                return false;

            switch (type)
            {
                case DATA_ONYXIA:
                    if (state == IN_PROGRESS)
                        SetBossState(DATA_SHE_DEEP_BREATH_MORE, IN_PROGRESS);
                    break;
            }
            return true;
        }

        void SetData(uint32 type, uint32 data) OVERRIDE
        {
            switch (type)
            {
                case DATA_ONYXIA_PHASE:
                    if (data == PHASE_BREATH) //Used to mark the liftoff phase
                    {
                        achievManyWhelpsHandleIt = false;
                        manyWhelpsCounter = 0;
                        onyxiaLiftoffTimer = 10000;
                    }
                    break;
                case DATA_SHE_DEEP_BREATH_MORE:
                    if (data == IN_PROGRESS)
                    {
                        achievSheDeepBreathMore = true;
                    }
                    else if (data == FAIL)
                    {
                        achievSheDeepBreathMore = false;
                    }
                    break;
            }
        }

        void SetData64(uint32 type, uint64 data) OVERRIDE
        {
            switch (type)
            {
                case DATA_FLOOR_ERUPTION_GUID:
                    FloorEruptionGUID[1] = FloorEruptionGUID[0];
                    FloorEruptionGUIDQueue.push(data);
                    eruptTimer = 2500;
                    break;
            }
        }

        uint64 GetData64(uint32 data) const OVERRIDE
        {
            switch (data)
            {
                case NPC_ONYXIA:
                    return onyxiaGUID;
            }

            return 0;
        }

        void Update(uint32 diff)
        {
            if (GetBossState(DATA_ONYXIA) == IN_PROGRESS)
            {
                if (onyxiaLiftoffTimer && onyxiaLiftoffTimer <= diff)
                {
                    onyxiaLiftoffTimer = 0;
                    if (manyWhelpsCounter >= 50)
                        achievManyWhelpsHandleIt = true;
                } else onyxiaLiftoffTimer -= diff;
            }

            if (!FloorEruptionGUIDQueue.empty())
            {
                if (eruptTimer <= diff)
                {
                    uint32 treeHeight = 0;
                    do
                    {
                        treeHeight = (*FloorEruptionGUID[1].find(FloorEruptionGUIDQueue.front())).second;
                        FloorEruption(FloorEruptionGUIDQueue.front());
                        FloorEruptionGUIDQueue.pop();
                    } while (!FloorEruptionGUIDQueue.empty() && (*FloorEruptionGUID[1].find(FloorEruptionGUIDQueue.front())).second == treeHeight);
                    eruptTimer = 1000;
                }
                else
                    eruptTimer -= diff;
            }
        }

        bool CheckAchievementCriteriaMeet(uint32 criteria_id, Player const* /*source*/, Unit const* /*target*/ = NULL, uint32 /*miscvalue1*/ = 0)
        {
            switch (criteria_id)
            {
                case ACHIEV_CRITERIA_MANY_WHELPS_10_PLAYER:  // Criteria for achievement 4403: Many Whelps! Handle It! (10 player) Hatch 50 eggs in 10s
                case ACHIEV_CRITERIA_MANY_WHELPS_25_PLAYER:  // Criteria for achievement 4406: Many Whelps! Handle It! (25 player) Hatch 50 eggs in 10s
                    return achievManyWhelpsHandleIt;
                case ACHIEV_CRITERIA_DEEP_BREATH_10_PLAYER:  // Criteria for achievement 4404: She Deep Breaths More (10 player) Everybody evade Deep Breath
                case ACHIEV_CRITERIA_DEEP_BREATH_25_PLAYER:  // Criteria for achievement 4407: She Deep Breaths More (25 player) Everybody evade Deep Breath
                    return achievSheDeepBreathMore;
            }
            return false;
        }

        std::string GetSaveData()
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;
            saveStream << "O L " << GetBossSaveData();

            OUT_SAVE_INST_DATA_COMPLETE;
            return saveStream.str();
        }

        void Load(const char* strIn)
        {
            if (!strIn)
            {
                OUT_LOAD_INST_DATA_FAIL;
                return;
            }

            OUT_LOAD_INST_DATA(strIn);

            char dataHead1, dataHead2;

            std::istringstream loadStream(strIn);
            loadStream >> dataHead1 >> dataHead2;

            if (dataHead1 == 'O' && dataHead2 == 'L')
            {
                for (uint8 i = 0; i < EncounterCount; ++i)
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
            std::map<uint64, uint32> FloorEruptionGUID[2];
            std::queue<uint64> FloorEruptionGUIDQueue;
            uint64 onyxiaGUID;
            uint32 onyxiaLiftoffTimer;
            uint32 manyWhelpsCounter;
            uint32 eruptTimer;
            bool   achievManyWhelpsHandleIt;
            bool   achievSheDeepBreathMore;
    };
};

void AddSC_instance_onyxias_lair()
{
    new instance_onyxias_lair();
}
