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
SDName: Instance_Scholomance
SD%Complete: 100
SDComment:
SDCategory: Scholomance
EndScriptData */

#include "scriptPCH.h"
#include "scholomance.h"

struct instance_scholomance : public ScriptedInstance
{
    instance_scholomance(Map* pMap) : ScriptedInstance(pMap)
    {
        Initialize();
    };

    std::string strInstData;
    uint32 m_auiEncounter[INSTANCE_SCHOLOMANCE_MAX_ENCOUNTER];

    uint64 m_uiVectusGUID;
    uint64 m_uiMardukeGUID;

    uint64 m_uiGateKirtonosGUID;
    uint64 m_uiGateGandlingGUID;
    uint64 m_uiGateMiliciaGUID;
    uint64 m_uiGateTheolenGUID;
    uint64 m_uiGatePolkeltGUID;
    uint64 m_uiGateRavenianGUID;
    uint64 m_uiGateBarovGUID;
    uint64 m_uiGateIlluciaGUID;
    uint64 m_uiBrazierKirtonosGUID;

    void Initialize() override
    {
        memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

        m_uiGateKirtonosGUID = 0;
        m_uiGateGandlingGUID = 0;
        m_uiGateMiliciaGUID = 0;
        m_uiGateTheolenGUID = 0;
        m_uiGatePolkeltGUID = 0;
        m_uiGateRavenianGUID = 0;
        m_uiGateBarovGUID = 0;
        m_uiGateIlluciaGUID = 0;
        m_uiBrazierKirtonosGUID = 0;

    }
    void OnCreatureCreate(Creature* pCreature) override
    {
        switch (pCreature->GetEntry())
        {
            case NPC_VECTUS:
                m_uiVectusGUID = pCreature->GetGUID();
                break;
            case NPC_MARDUKE:
                m_uiMardukeGUID = pCreature->GetGUID();
                break;
        }
    }
    void OnGameObjectCreate(GameObject* pGo) override
    {
        switch (pGo->GetEntry())
        {
            case GO_GATE_KIRTONOS:
                m_uiGateKirtonosGUID = pGo->GetGUID();
                break;
            case GO_GATE_GANDLING:
                m_uiGateGandlingGUID = pGo->GetGUID();
                break;
            case GO_GATE_MALICIA:
                m_uiGateMiliciaGUID = pGo->GetGUID();
                break;
            case GO_GATE_THEOLEN:
                m_uiGateTheolenGUID = pGo->GetGUID();
                break;
            case GO_GATE_POLKELT:
                m_uiGatePolkeltGUID = pGo->GetGUID();
                break;
            case GO_GATE_RAVENIAN:
                m_uiGateRavenianGUID = pGo->GetGUID();
                break;
            case GO_GATE_BAROV:
                m_uiGateBarovGUID = pGo->GetGUID();
                break;
            case GO_GATE_ILLUCIA:
                m_uiGateIlluciaGUID = pGo->GetGUID();
                break;
            case GO_BRAZIER_KIRTONOS:
                m_uiBrazierKirtonosGUID = pGo->GetGUID();
                break;
            case GO_VIEWING_ROOM_DOOR:
                if (GetData(TYPE_VIEWING_ROOM_DOOR) == DONE)
                    pGo->UseDoorOrButton();
                break;
        }
    }

    uint32 GetData(uint32 uiType) override
    {
        if (uiType == TYPE_GANDLING)
        {
            if (m_auiEncounter[TYPE_GANDLING] == NOT_STARTED && m_auiEncounter[TYPE_ALEXEIBAROV] == DONE && m_auiEncounter[TYPE_THEOLEN] == DONE && m_auiEncounter[TYPE_RAVENIAN] == DONE &&
                    m_auiEncounter[TYPE_POLKELT] == DONE && m_auiEncounter[TYPE_MALICIA] == DONE && m_auiEncounter[TYPE_ILLUCIABAROV] == DONE)
                m_auiEncounter[TYPE_GANDLING] = SPECIAL;
            return m_auiEncounter[TYPE_GANDLING];
        }
        if (uiType < INSTANCE_SCHOLOMANCE_MAX_ENCOUNTER)
            return m_auiEncounter[uiType];
        return 0;
    }
    uint64 GetData64(uint32 uiData) override
    {
        switch (uiData)
        {
            case DATA_VECTUS:
                return m_uiVectusGUID;
            case DATA_MARDUKE:
                return m_uiMardukeGUID;
        }
        return 0;
    }
    void OnCreatureDeath(Creature *who) override
    {
        switch (who->GetEntry())
        {
            case NPC_KIRTONOS:
                if (GameObject* pGo = instance->GetGameObject(m_uiGateKirtonosGUID))
                    if (pGo->GetGoState() != GO_STATE_ACTIVE) // fermée
                        DoUseDoorOrButton(m_uiGateKirtonosGUID);
                break;
        }
    }

    void SetData(uint32 uiType, uint32 uiData) override
    {
        switch (uiType)
        {
            case TYPE_GANDLING:
                m_auiEncounter[TYPE_GANDLING] = uiData;
                if (uiData == FAIL || uiData == DONE)
                {
                    if (GameObject* pGo = instance->GetGameObject(m_uiGateMiliciaGUID))
                        if (pGo->GetGoState() != GO_STATE_ACTIVE)
                            DoUseDoorOrButton(m_uiGateMiliciaGUID);
                    if (GameObject* pGo = instance->GetGameObject(m_uiGateTheolenGUID))
                        if (pGo->GetGoState() != GO_STATE_ACTIVE)
                            DoUseDoorOrButton(m_uiGateTheolenGUID);
                    if (GameObject* pGo = instance->GetGameObject(m_uiGatePolkeltGUID))
                        if (pGo->GetGoState() != GO_STATE_ACTIVE)
                            DoUseDoorOrButton(m_uiGatePolkeltGUID);
                    if (GameObject* pGo = instance->GetGameObject(m_uiGateRavenianGUID))
                        if (pGo->GetGoState() != GO_STATE_ACTIVE)
                            DoUseDoorOrButton(m_uiGateRavenianGUID);
                    if (GameObject* pGo = instance->GetGameObject(m_uiGateBarovGUID))
                        if (pGo->GetGoState() != GO_STATE_ACTIVE)
                            DoUseDoorOrButton(m_uiGateBarovGUID);
                    if (GameObject* pGo = instance->GetGameObject(m_uiGateIlluciaGUID))
                        if (pGo->GetGoState() != GO_STATE_ACTIVE)
                            DoUseDoorOrButton(m_uiGateIlluciaGUID);
                }
                break;
            case TYPE_KIRTONOS:
                m_auiEncounter[TYPE_KIRTONOS] = uiData;
                if (uiData == IN_PROGRESS)
                {
                    if (GameObject* pGo = instance->GetGameObject(m_uiGateKirtonosGUID))
                        if (pGo->GetGoState() == GO_STATE_ACTIVE)
                            DoUseDoorOrButton(m_uiGateKirtonosGUID);
                }
                else if (uiData == FAIL)
                {
                    if (GameObject* pGo = instance->GetGameObject(m_uiGateKirtonosGUID))
                        if (pGo->GetGoState() != GO_STATE_ACTIVE)
                            DoUseDoorOrButton(m_uiGateKirtonosGUID);
                    if (GameObject* pGo = instance->GetGameObject(m_uiBrazierKirtonosGUID))
                            pGo->ResetDoorOrButton();
                }
                break;
            case TYPE_ALEXEIBAROV:
            case TYPE_THEOLEN:
            case TYPE_RAVENIAN:
            case TYPE_POLKELT:
            case TYPE_MALICIA:
            case TYPE_ILLUCIABAROV:
            case TYPE_VIEWING_ROOM_DOOR:
                m_auiEncounter[uiType] = uiData;
                break;
            default:
                break;
        }

        if (uiData == DONE)
        {
            std::ostringstream saveStream;
            for (uint32 i : m_auiEncounter)
                saveStream << i << " ";
            strInstData = saveStream.str();

            SaveToDB();
            OUT_SAVE_INST_DATA_COMPLETE;
        }
        SummonGandlingIfPossible();
    }
    /** Load / save system */
    char const* Save() override
    {
        return strInstData.c_str();
    }

    void Load(char const* chrIn) override
    {
        if (!chrIn)
            return;
        std::istringstream loadStream(chrIn);
        for (uint32 & i : m_auiEncounter)
        {
            loadStream >> i;
            if (i == IN_PROGRESS)
                i = NOT_STARTED;
        }
        SummonGandlingIfPossible();

        OUT_LOAD_INST_DATA_COMPLETE;
    }
    void SummonGandlingIfPossible()
    {
        if (GetData(TYPE_GANDLING) == SPECIAL)
        {
            instance->SummonCreature(NPC_GANDLING, 180.771f, -5.4286f, 75.5702f, 1.29154f, TEMPSUMMON_DEAD_DESPAWN, 0);
            SetData(TYPE_GANDLING, IN_PROGRESS);
        }
    }
};

InstanceData* GetInstanceData_instance_scholomance(Map* pMap)
{
    return new instance_scholomance(pMap);
}

bool GOOpen_brazier_herald(Player* pUser, GameObject *pGo)
{
    if (InstanceData* pInst = pGo->GetInstanceData())
    {
        switch (pInst->GetData(TYPE_KIRTONOS))
        {
            case IN_PROGRESS:
            case DONE:
                return false;
        }

        pInst->SetData(TYPE_KIRTONOS, IN_PROGRESS);
        pGo->PlayDirectSound(SOUND_SCREECH, 0);

        pUser->SummonCreature(NPC_KIRTONOS, 315.028f, 70.53845f, 102.1496f, 0.3859715f, TEMPSUMMON_DEAD_DESPAWN, 900000);
    }

    return true;
}

struct go_viewing_room_door : public GameObjectAI
{
    go_viewing_room_door(GameObject* pGo) : GameObjectAI(pGo) {}

    bool OnUse(Unit* user) override
    {
        // Save door state to database
        if (user && user->GetInstanceData())
            user->GetInstanceData()->SetData(TYPE_VIEWING_ROOM_DOOR, DONE);
        return false;
    }
};

GameObjectAI* GOGetAI_go_viewing_room_door(GameObject *pGo)
{
    return new go_viewing_room_door(pGo);
}

void AddSC_instance_scholomance()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "instance_scholomance";
    newscript->GetInstanceData = &GetInstanceData_instance_scholomance;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "go_brazier_herald";
    newscript->GOOpen = &GOOpen_brazier_herald;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "go_viewing_room_door";
    newscript->GOGetAI = &GOGetAI_go_viewing_room_door;
    newscript->RegisterSelf();
}
