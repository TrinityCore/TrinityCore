#include "precompiled.h"
#include "def_vault_of_archavon.h"
#define ENCOUNTERS 2
/* Vault of Archavon encounters:
1 - Archavon the Stone Watcher event
2 - Emalon the Storm Watcher event
*/
struct TRINITY_DLL_DECL instance_archavon : public ScriptedInstance
{
    instance_archavon(Map *Map) : ScriptedInstance(Map) {Initialize();};
    uint32 Encounters[ENCOUNTERS];
    uint64 Archavon;
    uint64 Emalon;
    void Initialize()
    {
        Archavon = 0;
        Emalon = 0;
        for (uint8 i = 0; i < ENCOUNTERS; i++)
            Encounters[i] = NOT_STARTED;
    }
    bool IsEncounterInProgress() const
    {
        for (uint8 i = 0; i < ENCOUNTERS; i++)
            if(Encounters[i] == IN_PROGRESS) return true;
        return false;
    }
    void OnCreatureCreate(Creature *creature, bool add)
    {
        switch(creature->GetEntry())
        {
        case 31125: Archavon = creature->GetGUID(); break;
        case 33993: Emalon = creature->GetGUID(); break;
        }
    }
    uint32 GetData(uint32 type)
    {
        switch(type)
        {
        case DATA_ARCHAVON_EVENT: return Encounters[0];
        case DATA_EMALON_EVENT: return Encounters[1];
        }
        return 0;
    }
    uint64 GetData64(uint32 identifier)
    {
        switch(identifier)
        {
        case DATA_ARCHAVON: return Archavon;
        case DATA_EMALON: return Emalon;
        }
        return 0;
    }
    void SetData(uint32 type, uint32 data)
    {
        switch(type)
        {
            case DATA_ARCHAVON_EVENT: Encounters[0] = data; break;
            case DATA_EMALON_EVENT: Encounters[1] = data; break;
        }
        if(data == DONE)
            SaveToDB();
    }
    std::string GetSaveData()
    {
        OUT_SAVE_INST_DATA;
        std::ostringstream stream;
        stream << Encounters[0] << " " << Encounters[1];
        char* out = new char[stream.str().length() + 1];
        strcpy(out, stream.str().c_str());
        if(out)
        {
            OUT_SAVE_INST_DATA_COMPLETE;
            return out;
        }
        return NULL;
    }
    void Load(const char* in)
    {
        if(!in)
        {
            OUT_LOAD_INST_DATA_FAIL;
            return;
        }
        OUT_LOAD_INST_DATA(in);
        std::istringstream stream(in);
        stream >> Encounters[0] >> Encounters[1];
        for (uint8 i = 0; i < ENCOUNTERS; ++i)
            if(Encounters[i] == IN_PROGRESS)
                Encounters[i] = NOT_STARTED;
        OUT_LOAD_INST_DATA_COMPLETE;
    }
};
InstanceData* GetInstanceData_instance_archavon(Map* map)
{
    return new instance_archavon(map);
}
void AddSC_instance_archavon()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_archavon";
    newscript->GetInstanceData = &GetInstanceData_instance_archavon;
    newscript->RegisterSelf();
}
