/*
 * Scripted for --> Mangos-Zero Special Thanks for VladimirMangos, Yehonal, Theluda, Drkotas, Shin, Wrath Team.
 * Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Instance_Wailing_Caverns
SD%Complete: 0
SDComment: Placeholder
SDCategory: Wailing Caverns
EndScriptData */

#include "scriptPCH.h"
#include "def_wailing_caverns.h"

struct instance_wailing_caverns : public ScriptedInstance
{
    instance_wailing_caverns(Map* pMap) : ScriptedInstance(pMap)
    {
        Initialize();
    }

    uint32 m_auiEncounter[WAILING_CAVERNS_MAX_ENCOUNTER];
    std::string strInstData;

    uint64 m_uiDiscipleGUID;
    uint64 m_uiNaralexGUID;
    uint64 m_uiAnacondraGUID;
    //uint64 m_uiVerdanGUID;
    uint64 m_uiSerpentisGUID;
    uint64 m_uiDMFChestGUID;
    bool Assaulted;

    // to be despawn when the nightmare is over
    std::vector<uint64> vNightmareMonsters;

    void Initialize() override
    {
        memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

        m_uiDiscipleGUID = 0;
        m_uiNaralexGUID = 0;
        m_uiAnacondraGUID = 0;
        //m_uiVerdanGUID = 0;
        m_uiSerpentisGUID = 0;
        Assaulted = false;
    }

    void OnCreatureCreate(Creature* pCreature) override
    {
        switch (pCreature->GetEntry())
        {
            case 3678:
                m_uiDiscipleGUID = pCreature->GetGUID();
                break;
            case 3679:
                m_uiNaralexGUID = pCreature->GetGUID();
                break;
            case 3673:
                m_uiSerpentisGUID = pCreature->GetGUID();
                break;
            case 3671:
                m_uiAnacondraGUID = pCreature->GetGUID();
                break;
                /*case 5775:                  // Verdan the Everliving
                    m_uiVerdanGUID = pCreature->GetGUID();
                    pCreature->SetVisibility(VISIBILITY_OFF);
                    pCreature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    pCreature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    pCreature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
                    break;*/
        }
        if ((pCreature->GetCreatureType() != CREATURE_TYPE_CRITTER) &&
            pCreature->GetFactionTemplateId() != 35 && // the 2 druids
            pCreature->GetEntry() != 3653) // Kresh is cool
            vNightmareMonsters.push_back(pCreature->GetGUID());
    }

    void OnObjectCreate(GameObject* pGo) override
    {
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
        switch (uiType)
        {
            case TYPE_ANACONDRA:
                m_auiEncounter[TYPE_ANACONDRA] = uiData;
                if (uiData == DONE && !Assaulted)
                {
                    if (Creature* pSerpentis = instance->GetCreature(m_uiSerpentisGUID))
                        if (pSerpentis->IsAlive())
                            DoScriptText(SERPENTIS_YELL, pSerpentis);
                    Assaulted = true;
                }
                if (uiData == SPECIAL)
                {
                    if (Creature* pAna = instance->GetCreature(m_uiAnacondraGUID))
                        if (pAna->IsAlive())
                            if (Creature* pDruid = GetClosestCreatureWithEntry(pAna, 3840, INTERACTION_DISTANCE))
                                if (pDruid->IsAlive())
                                    pDruid->DisappearAndDie();
                }
                break;
            case TYPE_COBRAHN:
                m_auiEncounter[TYPE_COBRAHN] = uiData;
                if (uiData == DONE && !Assaulted)
                {
                    if (Creature* pSerpentis = instance->GetCreature(m_uiSerpentisGUID))
                        if (pSerpentis->IsAlive())
                            DoScriptText(SERPENTIS_YELL, pSerpentis);
                    Assaulted = true;
                }
                break;
            case TYPE_PYTHAS:
                m_auiEncounter[TYPE_PYTHAS] = uiData;
                if (uiData == DONE && !Assaulted)
                {
                    if (Creature* pSerpentis = instance->GetCreature(m_uiSerpentisGUID))
                        if (pSerpentis->IsAlive())
                            DoScriptText(SERPENTIS_YELL, pSerpentis);
                    Assaulted = true;
                }
                break;
            case TYPE_MUTANUS:
                m_auiEncounter[uiType] = uiData;
                if (uiData == DONE) // despawn every hostile creature
                {
                    auto it = vNightmareMonsters.begin();
                    while (it != vNightmareMonsters.end())
                    {
                        if (Creature* pCreature = instance->GetCreature(*it))
                        {
                            if (pCreature->IsAlive() || pCreature->loot.empty())
                                pCreature->ForcedDespawn();
                        }
                        it = vNightmareMonsters.erase(it);
                    }
                }
                break;
            case TYPE_SERPENTIS:
            case TYPE_DISCIPLE:
                m_auiEncounter[uiType] = uiData;
                break;
            default:
                sLog.outError("Instance Wiling Caverns: ERROR SetData = %u for type %u does not exist/not implemented.", uiType, uiData);
                break;
        }
        if (m_auiEncounter[0] == DONE && m_auiEncounter[1] == DONE && m_auiEncounter[2] == DONE && m_auiEncounter[3] == DONE && m_auiEncounter[4] == NOT_STARTED)
        {
            sLog.outDebug("Debug:Wailing Caverns encounters done");
            SetData(TYPE_DISCIPLE, SPECIAL);
            if (Creature* pDisciple = instance->GetCreature(m_uiDiscipleGUID))
            {
                pDisciple->SetDefaultGossipMenuId(GOSSIP_DISCIPLE_SPECIAL);
                DoScriptText(YELL_AFTER_GOSSIP, pDisciple);
            } 
        }

        if (uiData == DONE)
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;
            saveStream << m_auiEncounter[0] << " " << m_auiEncounter[1] << " " << m_auiEncounter[2] << " "
                       << m_auiEncounter[3] << " " << m_auiEncounter[4] << " " << m_auiEncounter[5];

            strInstData = saveStream.str();

            SaveToDB();
            OUT_SAVE_INST_DATA_COMPLETE;
        }
    }

    char const* Save() override
    {
        return strInstData.c_str();
    }

    uint32 GetData(uint32 uiType) override
    {
        switch (uiType)
        {
            case TYPE_ANACONDRA:
            case TYPE_COBRAHN:
            case TYPE_PYTHAS:
            case TYPE_SERPENTIS:
            case TYPE_DISCIPLE:
            case TYPE_MUTANUS:
                return m_auiEncounter[uiType];
        }
        return 0;
    }

    uint64 GetData64(uint32 uiData) override
    {
        switch (uiData)
        {
            case DATA_NARALEX:
                return m_uiNaralexGUID;
        }
        return 0;
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
        loadStream >> m_auiEncounter[0] >> m_auiEncounter[1] >> m_auiEncounter[2] >> m_auiEncounter[3] >> m_auiEncounter[4] >> m_auiEncounter[5];

        for (uint32 & i : m_auiEncounter)
            if (i == IN_PROGRESS)
                i = NOT_STARTED;

        OUT_LOAD_INST_DATA_COMPLETE;
    }
};

InstanceData* GetInstanceData_instance_wailing_caverns(Map* pMap)
{
    return new instance_wailing_caverns(pMap);
}

void AddSC_instance_wailing_caverns()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "instance_wailing_caverns";
    newscript->GetInstanceData = &GetInstanceData_instance_wailing_caverns;
    newscript->RegisterSelf();
}
