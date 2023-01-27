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
SDName: Instance_Shadowfang_Keep
SD%Complete: 100
SDComment:
SDCategory: Shadowfang Keep
EndScriptData */

#include "scriptPCH.h"

enum
{
    TYPE_FREE_NPC           = 1,
    TYPE_RETHILGORE         = 2,
    TYPE_FENRUS             = 3,
    TYPE_NANDOS             = 4,
    TYPE_INTRO              = 5,
    TYPE_VOIDWALKER         = 6,
    MAX_ENCOUNTER           = 6,

    NPC_BARON_SILVERLAINE   = 3887,
    NPC_CMD_SPRINGVALE      = 4278,
    NPC_ASH                 = 3850,
    NPC_ADA                 = 3849,
    NPC_ARUGAL              = 10000,                        //"Arugal" says intro text
    NPC_ARCHMAGE_ARUGAL     = 4275,                         //"Archmage Arugal" does Fenrus event
    NPC_FENRUS              = 4274,                         //used to summon Arugal in Fenrus event
    NPC_VINCENT             = 4444,                         //Vincent should be "dead" is Arugal is done the intro already
    NPC_NANDOS              = 3927,

    GO_COURTYARD_DOOR       = 18895,                        //door to open when talking to NPC's
    GO_SORCERER_DOOR        = 18972,                        //door to open when Fenrus the Devourer dies
    GO_ARUGAL_DOOR          = 18971,                        //door to open when Wolf Master Nandos dies
    GO_ARUGAL_FOCUS         = 18973,                        //this generates the lightning visual in the Fenrus event
};

struct instance_shadowfang_keep : public ScriptedInstance
{
    instance_shadowfang_keep(Map* pMap) : ScriptedInstance(pMap)
    {
        Initialize();
    };

    uint32 m_auiEncounter[MAX_ENCOUNTER];
    std::string strInstData;

    uint64 m_uiAshGUID;
    uint64 m_uiAdaGUID;

    uint64 m_uiDoorCourtyardGUID;
    uint64 m_uiDoorSorcererGUID;
    uint64 m_uiDoorArugalGUID;
    uint64 m_uiBaronSilverlaineGUID;
    uint64 m_uiCmdSpringvaleGUID;

    uint64 m_uiFenrusGUID;
    uint64 m_uiVincentGUID;
    uint64 m_uiNandosGUID;

    uint32 m_uiVoidWalkerCount;

    uint32 m_uiSpawnPatrolOnBaronDeath;
    uint32 m_uiSpawnPatrolOnCmdDeath;

    bool isBaronDead;
    bool isCmdDead;

    void Initialize() override
    {
        memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

        m_uiAshGUID = 0;
        m_uiAdaGUID = 0;

        m_uiDoorCourtyardGUID = 0;
        m_uiDoorSorcererGUID  = 0;
        m_uiDoorArugalGUID    = 0;

        m_uiFenrusGUID        = 0;
        m_uiVincentGUID       = 0;
        m_uiCmdSpringvaleGUID = 0;

        isBaronDead = false;
        isCmdDead   = false;
        m_uiSpawnPatrolOnBaronDeath = 6000;
        m_uiSpawnPatrolOnCmdDeath   = 6000;

        m_uiBaronSilverlaineGUID = 0;
        //Nostalrius
        m_uiVoidWalkerCount   = 0;
    }

    void OnCreatureCreate(Creature* pCreature) override
    {
        switch (pCreature->GetEntry())
        {
            case NPC_ASH:
                m_uiAshGUID = pCreature->GetGUID();
                break;
            case NPC_ADA:
                m_uiAdaGUID = pCreature->GetGUID();
                break;
            case NPC_FENRUS:
                m_uiFenrusGUID = pCreature->GetGUID();
                break;
            case NPC_ARUGAL:
                //if Arugal has done the intro, make him invisible!
                if (m_auiEncounter[4] == DONE)
                    pCreature->SetVisibility(VISIBILITY_OFF);
                break;
            case NPC_VINCENT:
                m_uiVincentGUID = pCreature->GetGUID();
                //if Arugal has done the intro, make Vincent dead!
                if (m_auiEncounter[4] == DONE)
                    pCreature->SetStandState(UNIT_STAND_STATE_DEAD);
                break;
            case NPC_BARON_SILVERLAINE:
                m_uiBaronSilverlaineGUID = pCreature->GetGUID();
                break;
            case NPC_NANDOS:
                m_uiNandosGUID = pCreature->GetGUID();
                break;
            case NPC_CMD_SPRINGVALE:
                m_uiCmdSpringvaleGUID = pCreature->GetGUID();
                break;
        }
        /** Initialize NPC_BARON_SILVERLAINE boss Patrol */
        if (pCreature->GetRespawnDelay() == 7201)
        {
            pCreature->SetVisibility(VISIBILITY_OFF);
            pCreature->SetFactionTemplateId(35);
        }

        /** Initialize 4278 Patrol */
        if (pCreature->GetRespawnDelay() == 7202)
        {
            pCreature->SetVisibility(VISIBILITY_OFF);
            pCreature->SetFactionTemplateId(35);
        }
    }

    void OnCreatureDeath(Creature* pCreature) override
    {
        switch (pCreature->GetEntry())
        {
            case NPC_BARON_SILVERLAINE:
                isBaronDead = true;
                break;
            case NPC_CMD_SPRINGVALE:
                isCmdDead = true;
                break;
        }
    }


    void OnObjectCreate(GameObject* pGo) override
    {
        switch (pGo->GetEntry())
        {
            case GO_COURTYARD_DOOR:
                m_uiDoorCourtyardGUID = pGo->GetGUID();
                if (m_auiEncounter[0] == DONE)
                    pGo->SetGoState(GO_STATE_ACTIVE);
                break;
            //for this we ignore voidwalkers, because if the server restarts
            //they won't be there, but Fenrus is dead so the door can't be opened!
            case GO_SORCERER_DOOR:
                m_uiDoorSorcererGUID = pGo->GetGUID();
                if (m_auiEncounter[2] == DONE)
                    pGo->SetGoState(GO_STATE_ACTIVE);
                break;
            case GO_ARUGAL_DOOR:
                m_uiDoorArugalGUID = pGo->GetGUID();
                if (m_auiEncounter[3] == DONE)
                    pGo->SetGoState(GO_STATE_ACTIVE);
                break;
        }
    }

    void Update(uint32 uiDiff) override
    {
        if (isBaronDead)
        {
            std::list<Creature*> m_EscortList;

            if (Creature* pBaron = instance->GetCreature(m_uiBaronSilverlaineGUID))
            {

                if (m_uiSpawnPatrolOnBaronDeath <= uiDiff)
                {
                    GetCreatureListWithEntryInGrid(m_EscortList, pBaron, 3854, 400.0f);
                    for (const auto& it : m_EscortList)
                        if (it->GetRespawnDelay() == 7201)
                        {
                            it->SetVisibility(VISIBILITY_ON);
                            it->SetFactionTemplateId(17);
                        }
                    m_EscortList.clear();
                }
                else
                    m_uiSpawnPatrolOnBaronDeath -= uiDiff;
            }
        }
        if (isCmdDead)
        {
            std::list<Creature*> m_EscortList;

            if (Creature* pCmd = instance->GetCreature(m_uiCmdSpringvaleGUID))
            {

                if (m_uiSpawnPatrolOnCmdDeath <= uiDiff)
                {
                    GetCreatureListWithEntryInGrid(m_EscortList, pCmd, 3854, 400.0f);
                    for (const auto& it : m_EscortList)
                        if (it->GetRespawnDelay() == 7202)
                        {
                            it->SetVisibility(VISIBILITY_ON);
                            it->SetFactionTemplateId(17);
                        }
                    m_EscortList.clear();
                }
                else
                    m_uiSpawnPatrolOnCmdDeath -= uiDiff;
            }
        }

    }

    void SetData(uint32 uiType, uint32 uiData) override
    {
        switch (uiType)
        {
            case TYPE_FREE_NPC:
                if (uiData == DONE)
                    DoUseDoorOrButton(m_uiDoorCourtyardGUID);
                m_auiEncounter[0] = uiData;
                break;
            case TYPE_RETHILGORE:
                m_auiEncounter[1] = uiData;
                break;
            case TYPE_FENRUS:
                m_auiEncounter[2] = uiData;
                break;
            case TYPE_NANDOS:
                if (uiData == DONE)
                    DoUseDoorOrButton(m_uiDoorArugalGUID);
                m_auiEncounter[3] = uiData;
                break;
            case TYPE_INTRO:
                m_auiEncounter[4] = uiData;
                break;
            case TYPE_VOIDWALKER:
                if (uiData == DONE)
                {
                    m_auiEncounter[5]++;
                    if (m_auiEncounter[5] > 3)
                        DoUseDoorOrButton(m_uiDoorSorcererGUID);
                }
                break;
        }

        if (uiData == DONE)
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;
            saveStream << m_auiEncounter[0] << " " << m_auiEncounter[1] << " " << m_auiEncounter[2] << " " << m_auiEncounter[3]
                       << " " << m_auiEncounter[4] << " " << m_auiEncounter[5];

            strInstData = saveStream.str();

            SaveToDB();
            OUT_SAVE_INST_DATA_COMPLETE;
        }
    }

    uint32 GetData(uint32 uiType) override
    {
        switch (uiType)
        {
            case TYPE_FREE_NPC:
                return m_auiEncounter[0];
            case TYPE_RETHILGORE:
                return m_auiEncounter[1];
            case TYPE_FENRUS:
                return m_auiEncounter[2];
            case TYPE_NANDOS:
                return m_auiEncounter[3];
            case TYPE_INTRO:
                return m_auiEncounter[4];
            default:
                break;
        }
        return 0;
    }

    char const* Save() override
    {
        return strInstData.c_str();
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
        loadStream >> m_auiEncounter[0] >> m_auiEncounter[1] >> m_auiEncounter[2] >> m_auiEncounter[3]
                   >> m_auiEncounter[4] >> m_auiEncounter[5];

        for (uint32 & i : m_auiEncounter)
        {
            if (i == IN_PROGRESS)
                i = NOT_STARTED;
        }

        OUT_LOAD_INST_DATA_COMPLETE;
    }
};

InstanceData* GetInstanceData_instance_shadowfang_keep(Map* pMap)
{
    return new instance_shadowfang_keep(pMap);
}

void AddSC_instance_shadowfang_keep()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "instance_shadowfang_keep";
    newscript->GetInstanceData = &GetInstanceData_instance_shadowfang_keep;
    newscript->RegisterSelf();
}
