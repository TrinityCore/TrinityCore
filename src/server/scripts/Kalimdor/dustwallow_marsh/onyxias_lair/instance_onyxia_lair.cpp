#include "scriptPCH.h"
#include "instance_onyxia_lair.h"

#define MAX_ENCOUNTER   1

enum
{
    GO_WHELP_SPAWNER = 176510,
    SPELL_SUMMON_WHELP = 17646,
};

struct instance_onyxia_lair : public ScriptedInstance
{
    instance_onyxia_lair(Map* pMap) : ScriptedInstance(pMap)
    {
        Initialize();
    };
    uint32 m_auiEncounter[MAX_ENCOUNTER];

    void Initialize() override { }

    bool IsEncounterInProgress() const override
    {
        for (uint32 i : m_auiEncounter)
            if (i == IN_PROGRESS)
                return true;
        return false;
    }

    uint32 GetData(uint32 identifier) override
    {
        switch (identifier)
        {
            case DATA_ONYXIA_EVENT:
                return m_auiEncounter[0];
        }
        return 0;
    }

    void SetData(uint32 uiType, uint32 uiData) override
    {
        switch (uiType)
        {
            case DATA_ONYXIA_EVENT:
                m_auiEncounter[0] = uiData;
                break;
        }
    }

    void OnObjectCreate(GameObject* pGo) override
    {
        switch (pGo->GetEntry())
        {
            case GO_WHELP_SPAWNER:
                pGo->CastSpell(pGo->GetPositionX(), pGo->GetPositionY(), pGo->GetPositionZ(), SPELL_SUMMON_WHELP, true);
                break;
        }
    }
};

InstanceData* GetInstanceData_instance_onyxia_lair(Map* pMap)
{
    return new instance_onyxia_lair(pMap);
}

void AddSC_instance_onyxia_lair()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "instance_onyxia_lair";
    newscript->GetInstanceData = &GetInstanceData_instance_onyxia_lair;
    newscript->RegisterSelf();
}
