/* Copyright (C) 2008 - 2010 Trinity <http://www.trinitycore.org/>
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

/* ScriptData
SDName: Instance_Onyxias_Lair
SD%Complete: 100
SDComment: 
SDCategory: Onyxia's Lair
EndScriptData */

#include "ScriptPCH.h"
#include "onyxias_lair.h"

struct instance_onyxias_lair : public ScriptedInstance
{
    instance_onyxias_lair(Map* pMap) : ScriptedInstance(pMap) {Initialize();};

    //Eruption is a BFS graph problem
    //One map to remember all floor, one map to keep floor that still need to erupt and one queue to know what needs to be removed
    std::map<uint64,uint32> FloorEruptionGUID[2]; 
    std::queue<uint64> FloorEruptionGUIDQueue; 
    
    uint64 m_uiOnyxiasGUID;
    uint32 m_uiOnyxiaLiftoffTimer;
    uint32 m_uiManyWhelpsCounter;
    uint32 m_uiEruptTimer;

    uint8  m_auiEncounter[MAX_ENCOUNTER];

    bool   m_bAchievManyWhelpsHandleIt;
    bool   m_bAchievSheDeepBreathMore;

    void Initialize()
    {
        memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

        m_uiOnyxiasGUID = 0;
        m_uiOnyxiaLiftoffTimer = 0;
        m_uiManyWhelpsCounter = 0;
        m_bAchievManyWhelpsHandleIt = false;
        m_bAchievSheDeepBreathMore = true;

        m_uiEruptTimer = 0;
    }

    void OnCreatureCreate(Creature* pCreature, bool add)
    {
        switch (pCreature->GetEntry())
        {
            case NPC_ONYXIA:
                m_uiOnyxiasGUID = pCreature->GetGUID();
                break;
        }
    }

    void OnGameObjectCreate(GameObject* pGo, bool add)
    {
        if ((pGo->GetGOInfo()->displayId == 4392 || pGo->GetGOInfo()->displayId == 4472) && pGo->GetGOInfo()->trap.spellId == 17731)
        {
            if (add)
                FloorEruptionGUID[0].insert(std::make_pair(pGo->GetGUID(),0));
            else
                FloorEruptionGUID[0].erase(pGo->GetGUID());
            return;
        }

        switch(pGo->GetEntry())
        {
            case GO_WHELP_SPAWNER:
                Position pGoPos;
                pGo->GetPosition(&pGoPos);
                if (Creature* pTemp = pGo->SummonCreature(NPC_WHELP,pGoPos,TEMPSUMMON_CORPSE_DESPAWN))
                {
                    pTemp->SetInCombatWithZone();
                    ++m_uiManyWhelpsCounter;
                }
                break;
        }
    }

    void FloorEruption(uint64 floorEruptedGUID)
    {
        if (GameObject *pFloorEruption = instance->GetGameObject(floorEruptedGUID))
        {
            //THIS GOB IS A TRAP - What shall i do? =(
            //Cast it spell? Copyed Heigan method
            pFloorEruption->SendCustomAnim();
            pFloorEruption->CastSpell(NULL, Difficulty(instance->GetSpawnMode()) == RAID_DIFFICULTY_10MAN_NORMAL ? 17731 : 69294); //pFloorEruption->GetGOInfo()->trap.spellId

            //Get all immediatly nearby floors 
            std::list<GameObject*> nearFloorList;
            Trinity::GameObjectInRangeCheck check(pFloorEruption->GetPositionX(), pFloorEruption->GetPositionY(), pFloorEruption->GetPositionZ(), 15);
            Trinity::GameObjectListSearcher<Trinity::GameObjectInRangeCheck> searcher(pFloorEruption, nearFloorList, check);
            pFloorEruption->VisitNearbyGridObject(999, searcher);
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

    void SetData(uint32 uiType, uint32 uiData)
    {
        switch(uiType)
        {
            case DATA_ONYXIA:
                m_auiEncounter[0] = uiData;
                if (uiData == IN_PROGRESS)
                    SetData(DATA_SHE_DEEP_BREATH_MORE, IN_PROGRESS);
                break;
            case DATA_ONYXIA_PHASE:
                if (uiData == PHASE_BREATH) //Used to mark the liftoff phase
                {
                    m_bAchievManyWhelpsHandleIt = false;
                    m_uiManyWhelpsCounter = 0;
                    m_uiOnyxiaLiftoffTimer = 10*IN_MILISECONDS;
                }
                break;
            case DATA_SHE_DEEP_BREATH_MORE:
                if (uiData == IN_PROGRESS)
                {
                    m_bAchievSheDeepBreathMore = true;
                }
                else if (uiData == FAIL)
                {
                    m_bAchievSheDeepBreathMore = false;
                }
                break;
        }

        if (uiType < MAX_ENCOUNTER && uiData == DONE)
            SaveToDB();
    }

    void SetData64(uint32 uiType, uint64 uiData)
    {
        switch(uiType)
        {
            case DATA_FLOOR_ERUPTION_GUID:
                FloorEruptionGUID[1] = FloorEruptionGUID[0];
                FloorEruptionGUIDQueue.push(uiData);
                m_uiEruptTimer = 2500;
                break;
        }
    }

    uint32 GetData(uint32 uiType)
    {
        switch(uiType)
        {
            case DATA_ONYXIA:
                return m_auiEncounter[0];
        }

        return 0;
    }

    uint64 GetData64(uint32 uiData)
    {
        switch(uiData)
        {
            case DATA_ONYXIA_GUID:
                return m_uiOnyxiasGUID;
        }

        return 0;
    }

    void Update(uint32 uiDiff)
    {
        if (GetData(DATA_ONYXIA) == IN_PROGRESS)
        {
            if (m_uiOnyxiaLiftoffTimer && m_uiOnyxiaLiftoffTimer <= uiDiff)
            {
                m_uiOnyxiaLiftoffTimer = 0;
                if (m_uiManyWhelpsCounter >= 50)
                    m_bAchievManyWhelpsHandleIt = true;
            } else m_uiOnyxiaLiftoffTimer -= uiDiff;
        }

        if (!FloorEruptionGUIDQueue.empty()) 
        {
            if (m_uiEruptTimer <= uiDiff)
            {
                uint32 treeHeight = 0;
                do 
                {
                    treeHeight = (*FloorEruptionGUID[1].find(FloorEruptionGUIDQueue.front())).second;
                    FloorEruption(FloorEruptionGUIDQueue.front());
                    FloorEruptionGUIDQueue.pop();
                } while (!FloorEruptionGUIDQueue.empty() && (*FloorEruptionGUID[1].find(FloorEruptionGUIDQueue.front())).second == treeHeight);
                m_uiEruptTimer = 1000;
            }
            else
                m_uiEruptTimer -= uiDiff;
        }
    }

    bool CheckAchievementCriteriaMeet(uint32 criteria_id, Player const* source, Unit const* target = NULL, uint32 miscvalue1 = 0)
    {
        switch(criteria_id)
        {
            case ACHIEV_CRITERIA_MANY_WHELPS_10_PLAYER:  // Criteria for achievement 4403: Many Whelps! Handle It! (10 player) Hatch 50 eggs in 10s
            case ACHIEV_CRITERIA_MANY_WHELPS_25_PLAYER:  // Criteria for achievement 4406: Many Whelps! Handle It! (25 player) Hatch 50 eggs in 10s
                return m_bAchievManyWhelpsHandleIt;
            case ACHIEV_CRITERIA_DEEP_BREATH_10_PLAYER:  // Criteria for achievement 4404: She Deep Breaths More (10 player) Everybody evade Deep Breath
            case ACHIEV_CRITERIA_DEEP_BREATH_25_PLAYER:  // Criteria for achievement 4407: She Deep Breaths More (25 player) Everybody evade Deep Breath
                return m_bAchievSheDeepBreathMore;
        }
        return false;
    }
};

InstanceData* GetInstanceData_instance_onyxias_lair(Map* pMap)
{
    return new instance_onyxias_lair(pMap);
}

void AddSC_instance_onyxias_lair()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_onyxias_lair";
    newscript->GetInstanceData = &GetInstanceData_instance_onyxias_lair;
    newscript->RegisterSelf();
}
