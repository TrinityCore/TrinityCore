#include "precompiled.h"
#include "def_gundrak.h"
#define MAX_ENCOUNTER     5
/* GunDrak encounters:
0 - Slad'Ran
1 - Moorabi
2 - Drakkari Colossus
3 - Gal'Darah
4 - Eck the Ferocious
*/
struct TRINITY_DLL_DECL instance_gundrak : public ScriptedInstance
{
    instance_gundrak(Map* pMap) : ScriptedInstance(pMap)
    {
        bHeroicMode = pMap->IsHeroic();
        Initialize();
    };
    bool bHeroicMode;
    uint64 uiSladRan;
    uint64 uiMoorabi;
    uint64 uiDrakkariColossus;
    uint64 uiGalDarah;
    uint64 uiEckTheFerocious;
    uint64 uiSladRanAltar;
    uint64 uiMoorabiAltar;
    uint64 uiDrakkariColossusAltar;
    uint64 uiSladRanStatue;
    uint64 uiMoorabiStatue;
    uint64 uiDrakkariColossusStatue;
    uint64 uiEckTheFerociousDoor;
    uint64 uiGalDarahDoor1;
    uint64 uiGalDarahDoor2;
    uint64 uiBridge;
    uint64 uiCollision;
    uint32 m_auiEncounter[MAX_ENCOUNTER];
    std::string str_data;
    void Initialize()
   {
       uiSladRan = 0;
       uiMoorabi = 0;
       uiDrakkariColossus = 0;
       uiGalDarah = 0;
       uiEckTheFerocious = 0;
       uiSladRanAltar = 0;
       uiMoorabiAltar = 0;
       uiDrakkariColossusAltar = 0;
       uiSladRanStatue = 0;
       uiMoorabiStatue = 0;
       uiDrakkariColossusStatue = 0;
       uiEckTheFerociousDoor = 0;
       uiGalDarahDoor1 = 0;
       uiGalDarahDoor2 = 0;
       uiBridge = 0;
       uiCollision = 0;
       memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));
   }
   bool IsEncounterInProgress() const
    {
        for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
            if (m_auiEncounter[i] == IN_PROGRESS) return true;
        return false;
    }
    void OnCreatureCreate(Creature* pCreature, bool add)
    {
        switch(pCreature->GetEntry())
        {
            case 29304: uiSladRan = pCreature->GetGUID(); break;
            case 29305: uiMoorabi = pCreature->GetGUID(); break;
            case 29306: uiGalDarah = pCreature->GetGUID(); break;
            case 29307: uiDrakkariColossus = pCreature->GetGUID(); break;
            case 29932: uiEckTheFerocious = pCreature->GetGUID(); break;
        }
    }
    void OnGameObjectCreate(GameObject* pGo, bool add)
    {
        switch(pGo->GetEntry())
        {
            case 192518:
                uiSladRanAltar = pGo->GetGUID();
                if (m_auiEncounter[0] == DONE)
                    pGo->RemoveFlag(GAMEOBJECT_FLAGS,GO_FLAG_UNK1);
                break;
            case 192519:
                uiMoorabiAltar = pGo->GetGUID();
                if (m_auiEncounter[1] == DONE)
                    pGo->RemoveFlag(GAMEOBJECT_FLAGS,GO_FLAG_UNK1);
                break;
            case 192520:
                uiDrakkariColossusAltar = pGo->GetGUID();
                if (m_auiEncounter[2] == DONE)
                    pGo->RemoveFlag(GAMEOBJECT_FLAGS,GO_FLAG_UNK1);
                break;
            case 192564:
                uiSladRanStatue = pGo->GetGUID();
                break;
            case 192565:
                uiMoorabiStatue = pGo->GetGUID();
                break;
            case 192567:
                uiDrakkariColossusStatue = pGo->GetGUID();
                break;
            case 192632:
                uiEckTheFerociousDoor = pGo->GetGUID();
                if (bHeroicMode && m_auiEncounter[1] == DONE)
                    HandleGameObject(NULL,true,pGo);
                break;
            case 193208:
                uiGalDarahDoor1 = pGo->GetGUID();
                if (m_auiEncounter[3] == DONE)
                    HandleGameObject(NULL,true,pGo);
                break;
            case 193209:
                uiGalDarahDoor2 = pGo->GetGUID();
                if (m_auiEncounter[3] == DONE)
                    HandleGameObject(NULL,true,pGo);
                break;
            case 193188:
                uiBridge = pGo->GetGUID();
                HandleGameObject(NULL,true,pGo);
                break;
            case 192633:
                uiCollision = pGo->GetGUID();
                HandleGameObject(NULL,true,pGo);
                break;
        }
    }
    void SetData(uint32 type, uint32 data)
    {
        switch(type)
        {
        case DATA_SLAD_RAN_EVENT:
            m_auiEncounter[0] = data;
            if (data == DONE)
            {
              GameObject* pGo = instance->GetGameObject(uiSladRanAltar);
              if (pGo)
                  pGo->RemoveFlag(GAMEOBJECT_FLAGS,GO_FLAG_UNK1);
            }
            break;
        case DATA_MOORABI_EVENT:
            m_auiEncounter[1] = data;
            if (data == DONE)
            {
              GameObject* pGo = instance->GetGameObject(uiMoorabiAltar);
              if (pGo)
                  pGo->RemoveFlag(GAMEOBJECT_FLAGS,GO_FLAG_UNK1);
              if (bHeroicMode)
                  HandleGameObject(uiEckTheFerociousDoor,true);
            }
            break;
        case DATA_DRAKKARI_COLOSSUS_EVENT:
            m_auiEncounter[2] = data;
            if (data == DONE)
            {
              GameObject* pGo = instance->GetGameObject(uiDrakkariColossusAltar);
              if (pGo)
                  pGo->RemoveFlag(GAMEOBJECT_FLAGS,GO_FLAG_UNK1);
            }
            break;
        case DATA_GAL_DARAH_EVENT:
            m_auiEncounter[3] = data;
            if (data == DONE)
            {
                HandleGameObject(uiGalDarahDoor1,true);
                HandleGameObject(uiGalDarahDoor2,true);
            }
            break;
        case DATA_ECK_THE_FEROCIOUS_EVENT:
            m_auiEncounter[4] = data;
            break;
        }
        if (data == DONE)
            SaveToDB();
    }
    uint32 GetData(uint32 type)
    {
        switch(type)
        {
            case DATA_SLAD_RAN_EVENT:             return m_auiEncounter[0];
            case DATA_MOORABI_EVENT:              return m_auiEncounter[1];
            case DATA_GAL_DARAH_EVENT:            return m_auiEncounter[2];
            case DATA_DRAKKARI_COLOSSUS_EVENT:    return m_auiEncounter[3];
            case DATA_ECK_THE_FEROCIOUS_EVENT:    return m_auiEncounter[4];
        }
        return 0;
    }
    uint64 GetData64(uint32 type)
    {
        switch(type)
        {
            case DATA_SLAD_RAN_ALTAR:             return uiSladRanAltar;
            case DATA_MOORABI_ALTAR:              return uiMoorabiAltar;
            case DATA_DRAKKARI_COLOSSUS_ALTAR:    return uiDrakkariColossusAltar;
            case DATA_SLAD_RAN_STATUE:            return uiSladRanStatue;
            case DATA_MOORABI_STATUE:             return uiMoorabiStatue;
            case DATA_DRAKKARI_COLOSSUS_STATUE:   return uiDrakkariColossusStatue;
        }
        return 0;
    }
    std::string GetSaveData()
    {
        OUT_SAVE_INST_DATA;
        std::ostringstream saveStream;
        saveStream << "G D " << m_auiEncounter[0] << " " << m_auiEncounter[1] << " "
            << m_auiEncounter[2] << " " << m_auiEncounter[3] << " " << m_auiEncounter[4];
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
        uint16 data0, data1, data2, data3, data4;
        std::istringstream loadStream(in);
        loadStream >> dataHead1 >> dataHead2 >> data0 >> data1 >> data2 >> data3 >> data4;
        if (dataHead1 == 'G' && dataHead2 == 'D')
        {
            m_auiEncounter[0] = data0;
            m_auiEncounter[1] = data1;
            m_auiEncounter[2] = data2;
            m_auiEncounter[3] = data3;
            m_auiEncounter[4] = data4;
            for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                if (m_auiEncounter[i] == IN_PROGRESS)
                    m_auiEncounter[i] = NOT_STARTED;
        }else OUT_LOAD_INST_DATA_FAIL;
        OUT_LOAD_INST_DATA_COMPLETE;
    }
    void CheckAltars()
    {
        GameObject* pSladRanAltar = instance->GetGameObject(uiSladRanAltar);
        GameObject* pMoorabiAltar = instance->GetGameObject(uiMoorabiAltar);
        GameObject* pDrakkariColossusAltar = instance->GetGameObject(uiDrakkariColossusAltar);
        if (pSladRanAltar && pSladRanAltar->GetGoState() == GO_STATE_ACTIVE &&
            pMoorabiAltar && pMoorabiAltar->GetGoState() == GO_STATE_ACTIVE &&
            pDrakkariColossusAltar && pDrakkariColossusAltar->GetGoState() == GO_STATE_ACTIVE)
        {
            HandleGameObject(uiBridge,false);
            HandleGameObject(uiCollision,false);
        }
    }
};
bool GOHello_altar(Player *pPlayer, GameObject *pGO)
{
    ScriptedInstance *pInstance = pGO->GetInstanceData();
    uint32 uiStatue;
    pGO->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_UNK1);
    pGO->SetGoState(GO_STATE_ACTIVE);
    if (pInstance)
    {
        switch(pGO->GetEntry())
        {
            case 192518: uiStatue = pInstance->GetData64(DATA_SLAD_RAN_STATUE); break;
            case 192519: uiStatue = pInstance->GetData64(DATA_MOORABI_STATUE); break;
            case 192520: uiStatue = pInstance->GetData64(DATA_DRAKKARI_COLOSSUS_STATUE); break;
        }
        pInstance->HandleGameObject(uiStatue,true);
        ((instance_gundrak*)pInstance)->CheckAltars();
        return true;
    }
    return false;
}
InstanceData* GetInstanceData_instance_gundrak(Map* pMap)
{
    return new instance_gundrak(pMap);
}
void AddSC_instance_gundrak()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_gundrak";
    newscript->GetInstanceData = &GetInstanceData_instance_gundrak;
    newscript->RegisterSelf();
    newscript = new Script;
    newscript->Name = "go_gundrak_altar";
    newscript->pGOHello = &GOHello_altar;
    newscript->RegisterSelf();
}
