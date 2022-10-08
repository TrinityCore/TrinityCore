/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/* ScriptData
SDName: Instance_Deadmines
SD%Complete: 0
SDComment: Placeholder
SDCategory: Deadmines
EndScriptData */

#include "scriptPCH.h"
#include "deadmines.h"

struct instance_deadmines : public ScriptedInstance
{
    instance_deadmines(Map* pMap) : ScriptedInstance(pMap)
    {
        Initialize();
    };

    uint32 m_auiEncounter[INSTANCE_DM_MAX_ENCOUNTER];

    uint64 m_uiIronCladGUID;
    uint64 m_uiCannonGUID;
    uint64 m_uiSmiteGUID;
    uint64 m_uiRhahkGUID;
    uint64 m_uiGilnidGUID;
    uint64 m_uiDMFChestGUID;

    uint64 m_uiDoor1GUID;
    uint64 m_uiDoor2GUID;
    uint64 m_uiDoor3GUID;

    uint32 m_uiSpawnPatrolOnRhahkDeath;
    bool   isRhahkDead;
    uint32 isGunPowderEventDone;
    bool   isGilnidDead;
    uint32 m_uiSpawnPatrolOnGilnidDeath;

    uint32 m_uiIronDoor_Timer;
    uint32 m_uiDoor_Step;

    void Initialize() override
    {
        memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

        m_uiIronCladGUID = 0;
        m_uiCannonGUID = 0;
        m_uiSmiteGUID = 0;
        m_uiRhahkGUID = 0;
        m_uiGilnidGUID = 0;
        m_uiSpawnPatrolOnRhahkDeath = 30000;
        isRhahkDead = false;
        isGunPowderEventDone = 0;
        isGilnidDead = false;
        m_uiSpawnPatrolOnGilnidDeath = 30000;

        m_uiIronDoor_Timer = 0;
        m_uiDoor_Step = 0;
    }

    void OnCreatureCreate(Creature* pCreature) override
    {
        if (pCreature->GetEntry() == NPC_RHAHKZOR)
            m_uiRhahkGUID = pCreature->GetGUID();

        if (pCreature->GetEntry() == NPC_GILDNID)
            m_uiGilnidGUID = pCreature->GetGUID();

        if (pCreature->GetEntry() == NPC_MR_SMITE)
            m_uiSmiteGUID = pCreature->GetGUID();

        /** Initialize Rhahz Patrol */
        if (pCreature->GetRespawnDelay() == 43199)
        {
            pCreature->SetVisibility(VISIBILITY_OFF);
            pCreature->SetFactionTemplateId(35);
        }

        /** Initialize Gilnid Patrol */
        if (pCreature->GetRespawnDelay() == 43201)
        {
            pCreature->SetVisibility(VISIBILITY_OFF);
            pCreature->SetFactionTemplateId(35);
        }
    }

    void OnCreatureDeath(Creature *who) override
    {
        switch (who->GetEntry())
        {
            case NPC_RHAHKZOR :
                if (GameObject* pGo = instance->GetGameObject(m_uiDoor1GUID))
                    if (pGo->GetGoState() != GO_STATE_ACTIVE)
                        DoUseDoorOrButton(m_uiDoor1GUID);

                isRhahkDead = true;
                m_uiSpawnPatrolOnRhahkDeath = 60000;
                break;
            case NPC_SNEED :
                if (GameObject* pGo = instance->GetGameObject(m_uiDoor2GUID))
                    if (pGo->GetGoState() != GO_STATE_ACTIVE)
                        DoUseDoorOrButton(m_uiDoor2GUID);
                break;
            case NPC_GILDNID :
                if (GameObject* pGo = instance->GetGameObject(m_uiDoor3GUID))
                    if (pGo->GetGoState() != GO_STATE_ACTIVE)
                        DoUseDoorOrButton(m_uiDoor3GUID);

                isGilnidDead = true;
                m_uiSpawnPatrolOnGilnidDeath = 30000;

                break;
        }
    }

    void OnObjectCreate(GameObject* pGo) override
    {
        if (pGo->GetEntry() == GO_IRON_CLAD)
            m_uiIronCladGUID = pGo->GetGUID();

        if (pGo->GetEntry() == GO_DEFIAS_CANNON)
            m_uiCannonGUID = pGo->GetGUID();

        if (pGo->GetEntry() == GO_DOOR1)
            m_uiDoor1GUID = pGo->GetGUID();
        if (pGo->GetEntry() == GO_DOOR2 && pGo->GetPositionX() > -291.0f && pGo->GetPositionX() < -290.0f)
            m_uiDoor2GUID = pGo->GetGUID();
        if (pGo->GetEntry() == GO_DOOR2 && pGo->GetPositionX() > -169.0f && pGo->GetPositionX() < -168.0f)
            m_uiDoor3GUID = pGo->GetGUID();

        if (pGo->GetEntry() == GO_DMF_CHEST)
        {
            pGo->SetVisible(false);
            m_uiDMFChestGUID = pGo->GetGUID();
        }
    }

    void OnPlayerEnter(Player* pPlayer) override
    {
        if (!pPlayer)
            return;

        // Darkmoon chest visible only for players on the quest
        if (pPlayer->GetQuestStatus(QUEST_FORTUNE_AWAITS) == QUEST_STATUS_COMPLETE)
        {
            if (GameObject* pGo = instance->GetGameObject(m_uiDMFChestGUID))
                pGo->SetVisible(true);
        }
    }

    void SetData(uint32 uiType, uint32 uiData) override
    {
        if (uiType == TYPE_DEFIAS_ENDDOOR)
        {
            if (uiData == IN_PROGRESS)
            {
                if (GameObject* pGo = instance->GetGameObject(m_uiIronCladGUID))
                {
                    // no breaking the door if it's open
                    if (!(pGo->GetGoState() == GO_STATE_ACTIVE))
                        pGo->UseDoorOrButton(0, true);
                    m_uiIronDoor_Timer = 3000;
                }
            }
            m_auiEncounter[0] = uiData;
        }
        else if (uiType == GUN_POWDER_EVENT)
            isGunPowderEventDone = uiData;
    }

    uint32 GetData(uint32 uiType) override
    {
        if (uiType == TYPE_DEFIAS_ENDDOOR)
            return m_auiEncounter[0];
        else if (uiType == GUN_POWDER_EVENT)
            return isGunPowderEventDone;
        return 0;
    }

    uint64 GetData64(uint32 uiData) override
    {
        if (uiData == DATA_DEFIAS_DOOR)
            return m_uiIronCladGUID;

        return 0;
    }

    void Update(uint32 uiDiff) override
    {
        if (isRhahkDead)
        {
            std::list<Creature*> m_EscortList;

            if (Creature* pRhahk = instance->GetCreature(m_uiRhahkGUID))
            {

                if (m_uiSpawnPatrolOnRhahkDeath <= uiDiff)
                {
                    GetCreatureListWithEntryInGrid(m_EscortList, pRhahk, 634, 400.0f);
                    for (const auto& it : m_EscortList)
                        if (it->GetRespawnDelay() == 43199)
                        {
                            it->SetVisibility(VISIBILITY_ON);
                            it->SetFactionTemplateId(17);
                        }
                    m_EscortList.clear();

                    GetCreatureListWithEntryInGrid(m_EscortList, pRhahk, 1729, 400.0f);
                    for (const auto& it : m_EscortList)
                        if (it->GetRespawnDelay() == 43199)
                        {
                            it->SetVisibility(VISIBILITY_ON);
                            it->SetFactionTemplateId(17);
                        }
                    m_EscortList.clear();
                }
                else
                    m_uiSpawnPatrolOnRhahkDeath -= uiDiff;
            }
        }

        if (isGilnidDead)
        {
            std::list<Creature*> m_EscortList;

            if (Creature* pGilnid = instance->GetCreature(m_uiGilnidGUID))
            {
                if (m_uiSpawnPatrolOnGilnidDeath <= uiDiff)
                {
                    GetCreatureListWithEntryInGrid(m_EscortList, pGilnid, 4417, 400.0f);
                    for (const auto& it : m_EscortList)
                        if (it->GetRespawnDelay() == 43201)
                        {
                            it->SetVisibility(VISIBILITY_ON);
                            it->SetFactionTemplateId(17);
                        }
                    m_EscortList.clear();

                    GetCreatureListWithEntryInGrid(m_EscortList, pGilnid, 4418, 400.0f);
                    for (const auto& it : m_EscortList)
                        if (it->GetRespawnDelay() == 43201)
                        {
                            it->SetVisibility(VISIBILITY_ON);
                            it->SetFactionTemplateId(17);
                        }
                    m_EscortList.clear();
                }
                else
                    m_uiSpawnPatrolOnGilnidDeath -= uiDiff;
            }
        }


        if (m_uiIronDoor_Timer)
        {
            if (m_uiIronDoor_Timer <= uiDiff)
            {
                if (Creature* pMrSmite = instance->GetCreature(m_uiSmiteGUID))
                {
                    std::list<Creature*> m_EscortList;

                    switch (m_uiDoor_Step)
                    {
                        case 0:
                            DoScriptText(INST_SAY_ALARM1, pMrSmite);
                            GetCreatureListWithEntryInGrid(m_EscortList, pMrSmite, 657, 400.0f);
                            for (const auto& it : m_EscortList)
                                if (it->GetRespawnDelay() == 43202)
                                    it->GetMotionMaster()->MovePoint(0, -99.6611f, -671.071655f, 7.42241f, MOVE_PATHFINDING | MOVE_RUN_MODE);
                            m_EscortList.clear();
                            ++m_uiDoor_Step;
                            m_uiIronDoor_Timer = 15000;
                            break;
                        case 1:
                            DoScriptText(INST_SAY_ALARM2, pMrSmite);
                            m_uiDoor_Step = 0;
                            m_uiIronDoor_Timer = 0;
                            sLog.outDebug("Instance Deadmines: Iron door event reached end.");
                            break;
                    }
                }
                else
                    m_uiIronDoor_Timer = 0;
            }
            else
                m_uiIronDoor_Timer -= uiDiff;
        }
    }
};

InstanceData* GetInstanceData_instance_deadmines(Map* pMap)
{
    return new instance_deadmines(pMap);
}

void AddSC_instance_deadmines()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "instance_deadmines";
    newscript->GetInstanceData = &GetInstanceData_instance_deadmines;
    newscript->RegisterSelf();
}
