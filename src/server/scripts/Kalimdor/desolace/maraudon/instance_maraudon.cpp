/*
  ROCKETTE FOR NOSTALRIUS
 */

#include "scriptPCH.h"
#include "maraudon.h"

struct instance_maraudon : public ScriptedInstance
{
    instance_maraudon(Map *pMap) : ScriptedInstance(pMap)
    {
        cGuid = 0;
    }

    uint32 m_auiEncounter[MARAUDON_MAX_ENCOUNTER];
    std::string strInstData;

    uint64 cGuid;
    uint64 spewedLarvaGuid;
    uint64 vineGuid;
    uint64 larvaSpewerGuid;
    bool bRespawnSpewedLarva;
    uint32 uiSpewedLarvaTimer;

    void Initialize() override
    {
        memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

        cGuid = 0;
        spewedLarvaGuid = 0;
        vineGuid = 0;
        larvaSpewerGuid = 0;
        bRespawnSpewedLarva = false;
        uiSpewedLarvaTimer = 4000;

    }

    void OnCreatureCreate(Creature *pCreature) override
    {
        switch (pCreature->GetEntry())
        {
            case NPC_CELEBRAS_REDEEMED:
                cGuid = pCreature->GetObjectGuid();

                if (m_auiEncounter[TYPE_CELEBRAS] != DONE)
                    pCreature->SetVisibility(VISIBILITY_OFF);
                break;
            case NPC_SPEWED_LARVA:
                spewedLarvaGuid = pCreature->GetObjectGuid();
                // No functional spewer no larva
                if (m_auiEncounter[TYPE_LARVA_SPEWER] == DONE)
                    pCreature->DisappearAndDie();
                break;
        }
    }

    void OnGameObjectCreate(GameObject* pGo) override
    {
        switch (pGo->GetEntry())
        {
            case GO_HEALED_CELEBRIAN_VINE:
                // The healed vine is summoned by the corrupted one
                vineGuid = pGo->GetObjectGuid();
                break;
            case GO_LARVA_SPEWER:
                larvaSpewerGuid = pGo->GetObjectGuid();
                // Alternative state = destroyed
                if (m_auiEncounter[TYPE_LARVA_SPEWER] == DONE)
                    pGo->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
                break;
        }
    }

    void OnCreatureRespawn(Creature *pCreature) override
    {
        switch (pCreature->GetEntry())
        {
            case NPC_SPEWED_LARVA:
                // No functional spewer no larva
                if (m_auiEncounter[TYPE_LARVA_SPEWER] == DONE)
                    pCreature->DisappearAndDie();
                break;
        }
    }

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
    }

    uint32 GetData(uint32 uiType) override
    {
        switch (uiType)
        {
            case TYPE_LARVA_SPEWER:
                return m_auiEncounter[TYPE_LARVA_SPEWER];
                break;
            case TYPE_CELEBRAS:
                return m_auiEncounter[TYPE_CELEBRAS];
                break;
            default:
                return 0;
        }
    }

    void SetData(uint32 uiType, uint32 uiData) override
    {
        switch (uiType)
        {
            case TYPE_LARVA_SPEWER:
                if (uiData == IN_PROGRESS)
                {
                    // First kill our larva
                    if (Creature* pSpewedLarva = instance->GetCreature(spewedLarvaGuid))
                        pSpewedLarva->DisappearAndDie();
                    SpewLarva();
                }
                else
                    m_auiEncounter[TYPE_LARVA_SPEWER] = uiData;
                break;
            case TYPE_CELEBRAS:
                if (uiData == DONE)
                    if (Creature* pCreature = instance->GetCreature(GetData64(NPC_CELEBRAS_REDEEMED)))
                        pCreature->SetVisibility(VISIBILITY_ON);

                m_auiEncounter[TYPE_CELEBRAS] = uiData;
                break;
        }

        if (uiData == DONE)
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;
            for (uint32 i : m_auiEncounter)
                saveStream << i << " ";

            strInstData = saveStream.str();

            SaveToDB();
            OUT_SAVE_INST_DATA_COMPLETE;
        }
    }

    uint64 GetData64(uint32 uiData) override
    {
        switch (uiData)
        {
            case NPC_CELEBRAS_REDEEMED:
                return cGuid;
        }

        return 0;
    }

    void SpewLarva()
    {
        if (GameObject* pLarvaSpewer = instance->GetGameObject(larvaSpewerGuid))
            if (pLarvaSpewer->GetGoState() == GO_STATE_READY)
            {
                // The custom animation is the spewing
                pLarvaSpewer->SendGameObjectCustomAnim();
                bRespawnSpewedLarva = true;
                uiSpewedLarvaTimer = 4000;
            }
    }

    void Update(uint32 uiDiff) override
    {
        // Remove a corrupted vine when a healed one was summoned over
        if (vineGuid)
        {
            if (GameObject* pHealedVine = GetGameObject(vineGuid))
                if (GameObject* pCorruptedVine = GetClosestGameObjectWithEntry(pHealedVine, GO_VYLESTEM_VINE, INTERACTION_DISTANCE))
                    pCorruptedVine->AddObjectToRemoveList();
            vineGuid = 0;
        }

        // Respawn a larva 4 seconds after the spewer animation start
        if (bRespawnSpewedLarva)
        {
            if (bRespawnSpewedLarva && uiSpewedLarvaTimer <= uiDiff)
            {
                if (Creature* pSpewedLarva = instance->GetCreature(spewedLarvaGuid))
                    pSpewedLarva->Respawn();
                bRespawnSpewedLarva = false;
            }
            else uiSpewedLarvaTimer -= uiDiff;
        }
    }
};

InstanceData* GetInstanceData_instance_maraudon(Map* pMap)
{
    return new instance_maraudon(pMap);
}

void AddSC_instance_maraudon()
{
    Script* pNewScript;

    pNewScript = new Script;
    pNewScript->Name = "instance_maraudon";
    pNewScript->GetInstanceData = &GetInstanceData_instance_maraudon;
    pNewScript->RegisterSelf();
}
