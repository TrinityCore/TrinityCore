#include "precompiled.h"
#include "def_drak_tharon_keep.h"

#define MAX_ENCOUNTER     4
/* Drak'Tharon Keep encounters:
0 - Trollgore
1 - Novos
2 - King Dred
3 - Tharon Ja
*/

struct TRINITY_DLL_DECL instance_drak_tharon : public ScriptedInstance
{
    instance_drak_tharon(Map* pMap) : ScriptedInstance(pMap) {Initialize();};

    uint64 uiTrollgore;
    uint64 uiNovos;
    uint64 uiDred;
    uint64 uiTharonJa;

    uint64 uiNovosCrystal1;
    uint64 uiNovosCrystal2;
    uint64 uiNovosCrystal3;
    uint64 uiNovosCrystal4;

    uint8 m_auiEncounter[MAX_ENCOUNTER];

    std::string str_data;

    void Initialize()
    {
        uiTrollgore = 0;
        uiNovos = 0;
        uiDred = 0;
        uiTharonJa = 0;
        uiNovosCrystal1 = 0;
        uiNovosCrystal2 = 0;
        uiNovosCrystal3 = 0;
        uiNovosCrystal4 = 0;
    }

    bool IsEncounterInProgress() const
    {
        for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
            if (m_auiEncounter[i] == IN_PROGRESS) return true;

        return false;
    }

    void OnGameObjectCreate(GameObject* pGo, bool add)
    {
        switch(pGo->GetEntry())
        {
            case 189299:
                uiNovosCrystal1 = pGo->GetGUID();
                break;
            case 189300:
                uiNovosCrystal2 = pGo->GetGUID();
                break;
            case 189301:
                uiNovosCrystal3 = pGo->GetGUID();
                break;
            case 189302:
                uiNovosCrystal4 = pGo->GetGUID();
                break;
        }
    }

    void OnCreatureCreate(Creature* pCreature, bool add)
    {
        switch(pCreature->GetEntry())
        {
            case 26630:
                uiTrollgore = pCreature->GetGUID();
                break;
            case 26631:
                uiNovos = pCreature->GetGUID();
                break;
            case 27483:
                uiTrollgore = pCreature->GetGUID();
                break;
            case 26632:
                uiTharonJa = pCreature->GetGUID();
                break;
        }
    }

    uint64 GetData64(uint32 identifier)
    {
        switch(identifier)
        {
            case DATA_TROLLGORE:          return uiTrollgore;
            case DATA_NOVOS:              return uiNovos;
            case DATA_DRED:               return uiDred;
            case DATA_THARON_JA:          return uiTharonJa;
            case DATA_NOVOS_CRYSTAL_1:    return uiNovosCrystal1;
            case DATA_NOVOS_CRYSTAL_2:    return uiNovosCrystal2;
            case DATA_NOVOS_CRYSTAL_3:    return uiNovosCrystal3;
            case DATA_NOVOS_CRYSTAL_4:    return uiNovosCrystal4;
        }

        return 0;
    }

    void SetData(uint32 type, uint32 data)
    {
        switch(type)
        {
            case DATA_TROLLGORE_EVENT:
                m_auiEncounter[0] = data;
                break;
            case DATA_NOVOS_EVENT:
                m_auiEncounter[1] = data;
                break;
            case DATA_DRED_EVENT:
                m_auiEncounter[2] = data;
                break;
            case DATA_THARON_JA_EVENT:
                m_auiEncounter[3] = data;
                break;
        }

        if (data == DONE)
        {
            SaveToDB();
        }
    }

    uint32 GetData(uint32 type)
    {
        switch (type)
        {
            case DATA_TROLLGORE_EVENT:    return m_auiEncounter[0];
            case DATA_NOVOS_EVENT:        return m_auiEncounter[1];
            case DATA_DRED_EVENT:         return m_auiEncounter[2];
            case DATA_THARON_JA_EVENT:    return m_auiEncounter[3];
        }
        return 0;
    }

    std::string GetSaveData()
    {
        OUT_SAVE_INST_DATA;

        std::string str_data;

        std::ostringstream saveStream;
        saveStream << "D K " << m_auiEncounter[0] << " " << m_auiEncounter[1] << " "
            << m_auiEncounter[2] << " " << m_auiEncounter[3];

        str_data = saveStream.str();

        OUT_SAVE_INST_DATA_COMPLETE;
        return str_data;
    }

    void Load(const char* in)
    {
        if (!in)
        {
            OUT_LOAD_INST_DATA_FAIL;
            return;
        }

        OUT_LOAD_INST_DATA(in);

        char dataHead1, dataHead2;
        uint16 data0,data1,data2,data3;

        std::istringstream loadStream(in);
        loadStream >> dataHead1 >> dataHead2 >> data0 >> data1 >> data2 >> data3;

        if (dataHead1 == 'D' && dataHead2 == 'K')
        {
            m_auiEncounter[0] = data0;
            m_auiEncounter[1] = data1;
            m_auiEncounter[2] = data2;
            m_auiEncounter[3] = data3;

            for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                if (m_auiEncounter[i] == IN_PROGRESS)
                    m_auiEncounter[i] = NOT_STARTED;
        }else OUT_LOAD_INST_DATA_FAIL;

        OUT_LOAD_INST_DATA_COMPLETE;
    }
};

InstanceData* GetInstanceData_instance_drak_tharon(Map* pMap)
{
    return new instance_drak_tharon(pMap);
}

void AddSC_instance_drak_tharon()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_drak_tharon";
    newscript->GetInstanceData = &GetInstanceData_instance_drak_tharon;
    newscript->RegisterSelf();
}
