#include "precompiled.h"
#include "def_vault_of_archavon.h"

#define NUMBER_OF_ENCOUNTERS      2

struct TRINITY_DLL_DECL instance_archavon : public ScriptedInstance
{
    instance_archavon(Map* pMap) : ScriptedInstance(pMap) {Initialize();};

    std::string strInstData;
    uint64 Archavon;
    uint64 Emalon;
    uint32 Encounters[NUMBER_OF_ENCOUNTERS];

    void Initialize()
    {
        Archavon = 0;
        Emalon = 0;

        for(uint8 i = 0; i < NUMBER_OF_ENCOUNTERS; ++i)
            Encounters[i] = NOT_STARTED;
    }

    bool IsEncounterInProgress() const
    {
        for(uint8 i = 0; i < NUMBER_OF_ENCOUNTERS; ++i)
            if (Encounters[i] == IN_PROGRESS)
                return true;

        return false;
    }

    void OnCreatureCreate(Creature *creature, bool add)
    {
        switch(creature->GetEntry())
        {
            case 31125:    Archavon = creature->GetGUID();        break;
            case 33993:    Emalon = creature->GetGUID();        break;
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
            case DATA_ARCHAVON_EVENT:    return Encounters[0];
            case DATA_EMALON_EVENT:    return Encounters[1];
        }
        return 0;
    }

    void SetData(uint32 identifier, uint32 data)
    {
        switch(identifier)
        {
            case DATA_ARCHAVON_EVENT:    Encounters[0] = data;  break;
            case DATA_EMALON_EVENT:    Encounters[1] = data;  break;
        }

        if (data == DONE)
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;
            saveStream << Encounters[0] << " " << Encounters[1];

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
        loadStream >> Encounters[0] >> Encounters[1];

        for(uint8 i = 1; i < NUMBER_OF_ENCOUNTERS; ++i)
        {
            if (Encounters[i] == IN_PROGRESS)
                Encounters[i] = NOT_STARTED;
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
