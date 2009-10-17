#include "precompiled.h"
#include "def_halls_of_stone.h"

#define MAX_ENCOUNTER 4

/* Halls of Stone encounters:
0- Krystallus
1- Maiden of Grief
2- Escort Event
3- Sjonnir The Ironshaper
*/

struct TRINITY_DLL_DECL instance_halls_of_stone : public ScriptedInstance
{
    instance_halls_of_stone(Map* pMap) : ScriptedInstance(pMap) {Initialize();};

    uint64 uiMaidenOfGrief;
    uint64 uiKrystallus;
    uint64 uiSjonnir;

    uint64 uiKaddrak;
    uint64 uiAbedneum;
    uint64 uiMarnak;
    uint64 uiBrann;

    uint64 uiMaidenOfGriefDoor;
    uint64 uiSjonnirDoor;
    uint64 uiBrannDoor;
    uint64 uiTribunalConsole;
    uint64 uiTribunalChest;
    uint64 uiTribunalSkyFloor;
    uint64 uiKaddrakGo;
    uint64 uiAbedneumGo;
    uint64 uiMarnakGo;

    uint32 m_auiEncounter[MAX_ENCOUNTER];

    std::string str_data;

    void Initialize()
    {
        uiMaidenOfGrief = 0;
        uiKrystallus = 0;
        uiSjonnir = 0;

        uiKaddrak = 0;
        uiMarnak = 0;
        uiAbedneum = 0;
        uiBrann = 0;

        uiMaidenOfGriefDoor = 0;
        uiSjonnirDoor = 0;
        uiBrannDoor = 0;
        uiKaddrakGo = 0;
        uiMarnakGo = 0;
        uiAbedneumGo = 0;
        uiTribunalConsole = 0;
        uiTribunalChest = 0;
        uiTribunalSkyFloor = 0;

        for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
            m_auiEncounter[i] = NOT_STARTED;
    }

    void OnCreatureCreate(Creature* pCreature, bool add)
    {
        switch(pCreature->GetEntry())
        {
            case 27975: uiMaidenOfGrief = pCreature->GetGUID(); break;
            case 27977: uiKrystallus = pCreature->GetGUID(); break;
            case 27978: uiSjonnir = pCreature->GetGUID(); break;
            case 30897: uiMarnak = pCreature->GetGUID(); break;
            case 30898: uiKaddrak = pCreature->GetGUID(); break;
            case 30099: uiAbedneum = pCreature->GetGUID(); break;
            case 28070: uiBrann = pCreature->GetGUID(); break;
        }
    }

    void OnGameObjectCreate(GameObject* pGo, bool add)
    {
        switch(pGo->GetEntry())
        {
            case 191669:
                uiAbedneumGo = pGo->GetGUID();
                break;
            case 192170:
                uiMarnakGo = pGo->GetGUID();
                break;
            case 192171:
                uiKaddrakGo = pGo->GetGUID();
                break;
            case 191292:
                uiMaidenOfGriefDoor = pGo->GetGUID();
                if (m_auiEncounter[0] == DONE)
                    pGo->SetGoState(GO_STATE_ACTIVE);
                else
                    pGo->SetGoState(GO_STATE_READY);
                break;
            case 191295:
                uiBrannDoor = pGo->GetGUID();
                if (m_auiEncounter[1] == DONE)
                    pGo->SetGoState(GO_STATE_ACTIVE);
                else
                    pGo->SetGoState(GO_STATE_READY);
                break;
            case 191296:
                uiSjonnirDoor = pGo->GetGUID();
                if (m_auiEncounter[2] == DONE)
                    pGo->SetGoState(GO_STATE_ACTIVE);
                else
                    pGo->SetGoState(GO_STATE_READY);
                break;
            case 193907:
                uiTribunalConsole = pGo->GetGUID();
                break;
            case 190586:
                uiTribunalChest = pGo->GetGUID();
                break;
            case 191527:
                uiTribunalSkyFloor = pGo->GetGUID();
                break;
        }
    }

    void SetData(uint32 type, uint32 data)
    {
        switch(type)
        {
            case DATA_MAIDEN_OF_GRIEF_EVENT:
                m_auiEncounter[1] = data;
                if (m_auiEncounter[1] == DONE)
                    HandleGameObject(uiBrannDoor,true);
                break;
            case DATA_KRYSTALLUS_EVENT:
                m_auiEncounter[0] = data;
                if (m_auiEncounter[0] == DONE)
                    HandleGameObject(uiMaidenOfGriefDoor,true);
                break;
            case DATA_SJONNIR_EVENT:
                m_auiEncounter[3] = data;
                break;
            case DATA_BRANN_EVENT:
                m_auiEncounter[2] = data;
                if (m_auiEncounter[2] == DONE)
                    HandleGameObject(uiSjonnirDoor,true);
                break;
        }

        if (data == DONE)
            SaveToDB();
    }

    uint32 GetData(uint32 type)
    {
        switch(type)
        {
            case DATA_KRYSTALLUS_EVENT:                return m_auiEncounter[0];
            case DATA_MAIDEN_OF_GRIEF_EVENT:           return m_auiEncounter[1];
            case DATA_SJONNIR_EVENT:                   return m_auiEncounter[2];
            case DATA_BRANN_EVENT:                     return m_auiEncounter[3];
        }

        return 0;
    }

    uint64 GetData64(uint32 identifier)
    {
        switch(identifier)
        {
            case DATA_MAIDEN_OF_GRIEF:                 return uiMaidenOfGrief;
            case DATA_KRYSTALLUS:                      return uiKrystallus;
            case DATA_SJONNIR:                         return uiSjonnir;
            case DATA_KADDRAK:                         return uiKaddrak;
            case DATA_MARNAK:                          return uiMarnak;
            case DATA_ABEDNEUM:                        return uiAbedneum;
            case DATA_GO_TRIBUNAL_CONSOLE:             return uiTribunalConsole;
            case DATA_GO_KADDRAK:                      return uiKaddrakGo;
            case DATA_GO_ABEDNEUM:                     return uiAbedneumGo;
            case DATA_GO_MARNAK:                       return uiMarnakGo;
            case DATA_GO_SKY_FLOOR:                    return uiTribunalSkyFloor;
        }

        return 0;
    }

    std::string GetSaveData()
    {
        OUT_SAVE_INST_DATA;

        std::ostringstream saveStream;
        saveStream << "H S " << m_auiEncounter[0] << " " << m_auiEncounter[1] << " " << m_auiEncounter[2] << " " << m_auiEncounter[3];

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
        uint16 data0, data1, data2, data3;

        std::istringstream loadStream(in);
        loadStream >> dataHead1 >> dataHead2 >> data0 >> data1 >> data2 >> data3;

        if (dataHead1 == 'H' && dataHead2 == 'S')
        {
            m_auiEncounter[0] = data0;
            m_auiEncounter[1] = data1;
            m_auiEncounter[2] = data2;
            m_auiEncounter[3] = data3;

            for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                if (m_auiEncounter[i] == IN_PROGRESS)
                    m_auiEncounter[i] = NOT_STARTED;

        } else OUT_LOAD_INST_DATA_FAIL;

        OUT_LOAD_INST_DATA_COMPLETE;
    }
};

InstanceData* GetInstanceData_instance_halls_of_stone(Map* pMap)
{
    return new instance_halls_of_stone(pMap);
}

void AddSC_instance_halls_of_stone()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_halls_of_stone";
    newscript->GetInstanceData = &GetInstanceData_instance_halls_of_stone;
    newscript->RegisterSelf();
}
