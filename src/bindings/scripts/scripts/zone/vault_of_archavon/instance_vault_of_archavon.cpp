#include "precompiled.h"
#include "def_vault_of_archavon.h"

#define NUMBER_OF_ENCOUNTERS      2

struct TRINITY_DLL_DECL instance_archavon : public ScriptedInstance
{
    instance_archavon(Map* pMap) : ScriptedInstance(pMap) {Initialize();};

    std::string strInstData;
    uint64 Archavon;
    uint64 Emalon;
    uint32 m_auiEncounter[NUMBER_OF_ENCOUNTERS];

    void Initialize()
    {
        memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

        Archavon = 0;
        Emalon = 0;
    }

    bool IsEncounterInProgress() const
    {
        for(uint8 i = 0; i < NUMBER_OF_ENCOUNTERS; ++i)
            if (m_auiEncounter[i] == IN_PROGRESS)
                return true;

        return false;
    }

    void OnCreatureCreate(Creature* pCreature, bool add)
    {
        switch(pCreature->GetEntry())
        {
            case 31125:    Archavon = pCreature->GetGUID();        break;
            case 33993:    Emalon = pCreature->GetGUID();        break;
        }
    }

    uint64 GetData64(uint32 identifier)
    {
        switch(identifier)
        {
            case DATA_ARCHAVON:    return Archavon;
            case DATA_EMALON:        return Emalon;
        }
        return 0;
    }

    uint32 GetData(uint32 identifier)
    {
        switch(identifier)
        {
            case DATA_ARCHAVON_EVENT:    return m_auiEncounter[0];
            case DATA_EMALON_EVENT:    return m_auiEncounter[1];
        }
        return 0;
    }

    void SetData(uint32 identifier, uint32 data)
    {
        switch(identifier)
        {
            case DATA_ARCHAVON_EVENT:    m_auiEncounter[0] = data;  break;
            case DATA_EMALON_EVENT:    m_auiEncounter[1] = data;  break;
        }

        if (data == DONE)
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;
            saveStream << m_auiEncounter[0] << " " << m_auiEncounter[1];

            strInstData = saveStream.str();

            SaveToDB();
            OUT_SAVE_INST_DATA_COMPLETE;
        }
    }

    std::string GetSaveData()
    {
        return strInstData;
    }

    void Load(const char* chrIn)
    {
        if (!chrIn)
        {
            OUT_LOAD_INST_DATA_FAIL;
            return;
        }

        OUT_LOAD_INST_DATA(chrIn);

        std::istringstream loadStream(chrIn);
        loadStream >> m_auiEncounter[0] >> m_auiEncounter[1];

        for(uint8 i = 1; i < NUMBER_OF_ENCOUNTERS; ++i)
        {
            if (m_auiEncounter[i] == IN_PROGRESS)
                m_auiEncounter[i] = NOT_STARTED;
        }

        OUT_LOAD_INST_DATA_COMPLETE;
    }
};

InstanceData* GetInstanceData_instance_archavon(Map* pMap)
{
    return new instance_archavon(pMap);
}

void AddSC_instance_archavon()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_archavon";
    newscript->GetInstanceData = &GetInstanceData_instance_archavon;
    newscript->RegisterSelf();
}
