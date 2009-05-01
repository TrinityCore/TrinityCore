#include "precompiled.h"
#include "def_nexus.h"

struct TRINITY_DLL_DECL instance_nexus : public ScriptedInstance
{
    instance_nexus(Map *Map) : ScriptedInstance(Map) {Initialize();};

    uint64 Anomalus,
           Ormorok,
           Magus_telestra,
           Magus_frost,
           Magus_fire,
           Magus_arcane,
           keristrasza,
           Commander_kolurg,
           Commander_stoutbeard;
    bool   IsBossDied[9];

    void Initialize()
    {
        Anomalus = 0;
        Ormorok = 0;
        Magus_telestra =0;
        Magus_frost =0;
        Magus_fire =0;
        Magus_arcane =0;
        keristrasza =0;
        Commander_kolurg = 0;
        Commander_stoutbeard = 0;
        IsBossDied[0] = false;
        IsBossDied[1] = false;
        IsBossDied[2] = false;
        IsBossDied[3] = false;
        IsBossDied[4] = false;
        IsBossDied[5] = false;
        IsBossDied[6] = false;
        IsBossDied[7] = false;
        IsBossDied[8] = false;
    }

    bool IsEncounterInProgress() const
    {
        //not active
        return false;
    }
    void OnCreatureCreate(Creature *creature, uint32 creature_entry)
    {
        switch(creature->GetEntry())
        {
            case 26763:    Anomalus = creature->GetGUID();             break;
            case 26794:    Ormorok = creature->GetGUID();              break;
            case 26731:    Magus_telestra = creature->GetGUID();       break;
            case 26930:    Magus_frost = creature->GetGUID();          break;
            case 26928:    Magus_fire = creature->GetGUID();           break;
            case 26926:    Magus_arcane = creature->GetGUID();         break;
            case 26723:    keristrasza = creature->GetGUID();          break;
            case 26798:    Commander_kolurg = creature->GetGUID();     break;
            case 26796:    Commander_stoutbeard = creature->GetGUID(); break;
        }
    }
    uint32 GetData(uint32 type)
    {
        switch(type)
        {
            case DATA_ANOMALUSDEAD:
                if(IsBossDied[0])
                    return 1;
                break;
            case DATA_ORMOROKDDEAD:
                if(IsBossDied[1])
                    return 1;
                break;
            case DATA_MAGUSTELESTRADEAD:
                if(IsBossDied[2])
                    return 1;
                break;
            case DATA_MAGUSTELESTRA_A_DEAD:
                if(IsBossDied[3])
                    return 1;
                break;
            case DATA_MAGUSTELESTRA_F_DEAD:
                if(IsBossDied[4])
                    return 1;
                break;
            case DATA_MAGUSTELESTRA_FI_DEAD:
                if(IsBossDied[5])
                    return 1;
                break;
            case DATA_KERISTRASZADEAD:
                if(IsBossDied[6])
                    return 1;
                break;
            case DATA_COMMANDER_KOLURGDEAD:
                if(IsBossDied[7])
                    return 1;
                break;
            case DATA_COMMANDER_STOUTBEARDDEAD:
                if(IsBossDied[8])
                    return 1;
                break;
        }

        return 0;
    }

    uint64 GetData64 (uint32 identifier)
    {
        return 0;
    }

    void SetData(uint32 type, uint32 data)
    {
        switch(type)
        {
            case DATA_ANOMALUS_DEATH:
                IsBossDied[0] = true;
                break;
            case DATA_ORMOROK_DEATH:
                IsBossDied[1] = true;
                break;
            case DATA_MAGUSTELESTRA_DEATH:
                IsBossDied[2] = true;
                break;
            case DATA_MAGUSTELESTRA_A_DEATH:
                IsBossDied[3] = true;
                break;
            case DATA_MAGUSTELESTRA_F_DEATH:
                IsBossDied[4] = true;
                break;
            case DATA_MAGUSTELESTRA_FI_DEAD:
                IsBossDied[5] = true;
                break;
            case DATA_KERISTRASZA_DEATH:
                IsBossDied[6] = true;
                break;
            case DATA_COMMANDER_KOLURG_DEATH:
                IsBossDied[7] = true;
                break;
            case DATA_COMMANDER_STOUTBEARD_DEATH:
                IsBossDied[8] = true;
                break;
        }
    }
};

InstanceData* GetInstanceData_instance_nexus(Map* map)
{
    return new instance_nexus(map);
}

void AddSC_instance_nexus()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_nexus";
    newscript->GetInstanceData = &GetInstanceData_instance_nexus;
    newscript->RegisterSelf();
}
