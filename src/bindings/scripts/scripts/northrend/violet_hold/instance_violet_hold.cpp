#include "precompiled.h"
#include "def_violet_hold.h"

#define MAX_ENCOUNTER          3

/* Violet Hold encounters:
0 - First boss
1 - Second boss
2 - Cyanigosa*/

/* Violet hold bosses:
0 - Moragg
1 - Erekem
2 - Ichoron
3 - Lavanthor
4 - Xevozz
5 - Zuramat
6 - Cyanigosa */
enum Creatures
{
    CREATURE_TELEPORTATION_PORTAL                   = 31011,
    CREATURE_XEVOZZ                                 = 29266,
    CREATURE_LAVANTHOR                              = 29312,
    CREATURE_ICHORON                                = 29313,
    CREATURE_ZURAMAT                                = 29314,
    CREATURE_EREKEM                                 = 29315,
    CREATURE_MORAGG                                 = 29316,
    CREATURE_CYANIGOSA                              = 31134,
    CREATURE_SINCLARI                               = 30658
};
struct Location
{
    float x,y,z,orientation;
};
const Location PortalLocation[] =
{
  {1936.07, 803.198, 53.3749, 3.12414},
  {1877.51, 850.104, 44.6599, 4.7822 },
  {1890.64, 753.471, 48.7224, 1.71042}
};
struct TRINITY_DLL_DECL instance_violet_hold : public ScriptedInstance
{
    instance_violet_hold(Map* pMap) : ScriptedInstance(pMap) {Initialize();};

    uint64 uiMoragg;
    uint64 uiErekem;
    uint64 uiIchoron;
    uint64 uiLavanthor;
    uint64 uiXevozz;
    uint64 uiZuramat;
    uint64 uiCyanigosa;
    uint64 uiSinclari;

    uint64 uiMoraggCell;
    uint64 uiErekemCell;
    uint64 uiErekemRightGuardCell;
    uint64 uiErekemLeftGuardCell;
    uint64 uiIchoronCell;
    uint64 uiLavanthorCell;
    uint64 uiXevozzCell;
    uint64 uiZuramatCell;
    uint64 uiMainDoor;

    uint8 uiWaveCount;
    uint8 uiLocation;
    uint8 uiFirstBoss;
    uint8 uiSecondBoss;

    uint8 m_auiEncounter[MAX_ENCOUNTER];

    bool HeroicMode;

    std::string str_data;

    void Initialize()
    {
        uiMoragg = 0;
        uiErekem = 0;
        uiIchoron = 0;
        uiLavanthor = 0;
        uiXevozz = 0;
        uiZuramat = 0;
        uiCyanigosa = 0;
        uiSinclari = 0;

        uiMoraggCell = 0;
        uiErekemCell = 0;
        uiErekemRightGuardCell = 0;
        uiErekemLeftGuardCell = 0;
        uiIchoronCell = 0;
        uiLavanthorCell = 0;
        uiXevozzCell = 0;
        uiZuramatCell = 0;
        uiMainDoor = 0;

        uiWaveCount = 0;
        uiLocation = 0;
        uiFirstBoss = 0;
        uiSecondBoss = 0;

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
            case CREATURE_XEVOZZ:
                uiXevozz = pCreature->GetGUID();
                break;
            case CREATURE_LAVANTHOR:
                uiLavanthor = pCreature->GetGUID();
                break;
            case CREATURE_ICHORON:
                uiIchoron = pCreature->GetGUID();
                break;
            case CREATURE_ZURAMAT:
                uiZuramat = pCreature->GetGUID();
                break;
            case CREATURE_EREKEM:
                uiErekem = pCreature->GetGUID();
                break;
            case CREATURE_MORAGG:
                uiMoragg = pCreature->GetGUID();
                break;
            case CREATURE_CYANIGOSA:
                uiCyanigosa = pCreature->GetGUID();
                break;
            case CREATURE_SINCLARI:
                uiSinclari = pCreature->GetGUID();
                break;
        }
    }

    void OnGameObjectCreate(GameObject* pGo, bool add)
    {
        switch(pGo->GetEntry())
        {
            case 191562:
                uiErekemLeftGuardCell = pGo->GetGUID();
                break;
            case 191563:
                uiErekemRightGuardCell = pGo->GetGUID();
                break;
            case 191564:
                uiErekemCell = pGo->GetGUID();
                if (m_auiEncounter[1] == DONE)
                    HandleGameObject(NULL, true, pGo);
                break;
            case 191565:
                uiZuramatCell = pGo->GetGUID();
                if (m_auiEncounter[5] == DONE)
                    HandleGameObject(NULL, true, pGo);
                break;
            case 191566:
                uiLavanthorCell = pGo->GetGUID();
                if (m_auiEncounter[3] == DONE)
                    HandleGameObject(NULL, true, pGo);
                break;
            case 191606:
                uiMoraggCell = pGo->GetGUID();
                if (m_auiEncounter[0] == DONE)
                    HandleGameObject(NULL, true, pGo);
                break;
            case 191722:
                uiIchoronCell = pGo->GetGUID();
                if (m_auiEncounter[2] == DONE)
                    HandleGameObject(NULL, true, pGo);
                break;
            case 191723:
                uiXevozzCell = pGo->GetGUID();
                if (m_auiEncounter[4] == DONE)
                    HandleGameObject(NULL, true, pGo);
                break;
        }
    }

    void SetData(uint32 type, uint32 data)
    {
        switch(type)
        {
            case DATA_1ST_BOSS_EVENT:
                m_auiEncounter[0] = data;
                if (data == DONE)
                    SaveToDB();
                break;
            case DATA_2ND_BOSS_EVENT:
                m_auiEncounter[1] = data;
                if (data == DONE)
                    SaveToDB();
                break;
            case DATA_CYANIGOSA_EVENT:
                m_auiEncounter[2] = data;
                if (data == DONE)
                {
                    SaveToDB();
                    if (GameObject* pMainDoor = instance->GetGameObject(uiMainDoor))
                        pMainDoor->SetGoState(GO_STATE_ACTIVE);
                }
                break;
            case DATA_WAVE_COUNT:
                uiWaveCount = data;
                switch(data)
                {
                    case 6:
                        uiFirstBoss = rand()%6;
                        StartBossEncounter(uiFirstBoss);
                        break;
                    case 12:
                        uiSecondBoss = rand()%6;
                        while (uiSecondBoss == uiFirstBoss)
                            uiSecondBoss = rand()%6;
                        StartBossEncounter(uiSecondBoss);
                        break;
                    case 18:
                    {
                        Creature *pSinclari = instance->GetCreature(uiSinclari);
                        if (pSinclari)
                            pSinclari->SummonCreature(CREATURE_CYANIGOSA,PortalLocation[0].x,PortalLocation[0].y,
                                                       PortalLocation[0].z,PortalLocation[0].orientation,TEMPSUMMON_CORPSE_DESPAWN,0);
                        break;
                    }
                    case 1:
                    {
                        if (GameObject* pMainDoor = instance->GetGameObject(uiMainDoor))
                            pMainDoor->SetGoState(GO_STATE_READY);
                    }
                    default:
                    {
                        Creature *pSinclari = instance->GetCreature(uiSinclari);
                        if (pSinclari)
                        {
                            pSinclari->SummonCreature(CREATURE_TELEPORTATION_PORTAL,PortalLocation[uiLocation].x,PortalLocation[uiLocation].y,
                                                       PortalLocation[uiLocation].z,PortalLocation[uiLocation].orientation,
                                                       TEMPSUMMON_CORPSE_DESPAWN,0);
                            uiLocation = (++uiLocation)%3;
                        }
                    }
                }
                break;
        }
    }

    uint32 GetData(uint32 type)
    {
        switch(type)
        {
            case DATA_1ST_BOSS_EVENT:           return m_auiEncounter[0];
            case DATA_2ND_BOSS_EVENT:           return m_auiEncounter[1];
            case DATA_CYANIGOSA_EVENT:          return m_auiEncounter[2];
            case DATA_WAVE_COUNT:               return uiWaveCount;
        }

        return 0;
    }

    void StartBossEncounter(uint8 uiBoss)
    {
        Creature* pBoss = NULL;
        switch(uiBoss)
        {
            case 0:               //Moragg
                HandleGameObject(uiMoraggCell,true);
                if (pBoss = instance->GetCreature(uiMoragg))
                {
                    pBoss->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
                    pBoss->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                }
                break;
            case 1:               //Erekem
                HandleGameObject(uiErekemCell,true);
                if (pBoss = instance->GetCreature(uiErekem))
                {
                    if (HeroicMode)
                    {
                        HandleGameObject(uiErekemRightGuardCell,true);
                        HandleGameObject(uiErekemLeftGuardCell,true);
                    }
                    pBoss->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
                    pBoss->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                }
                break;
            case 2:               //Ichoron
                HandleGameObject(uiIchoronCell,true);
                if (pBoss = instance->GetCreature(uiIchoron))
                {
                    pBoss->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
                    pBoss->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                }
                break;
            case 3:               //Lavanthor
                HandleGameObject(uiLavanthorCell,true);
                if (pBoss = instance->GetCreature(uiLavanthor))
                {
                    pBoss->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
                    pBoss->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                }
                break;
            case 4:               //Xevozz
                HandleGameObject(uiXevozzCell,true);
                if (pBoss = instance->GetCreature(uiXevozz))
                {
                    pBoss->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
                    pBoss->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                }
                break;
            case 5:               //Zuramat
                HandleGameObject(uiZuramatCell,true);
                if (pBoss = instance->GetCreature(uiZuramat))
                {
                    pBoss->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
                    pBoss->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                }
                break;
        }
    }

    uint64 GetData64(uint32 identifier)
    {
        switch(identifier)
        {
            case DATA_MORAGG:                   return uiMoragg;
            case DATA_EREKEM:                   return uiErekem;
            case DATA_ICHORON:                  return uiIchoron;
            case DATA_LAVANTHOR:                return uiLavanthor;
            case DATA_XEVOZZ:                   return uiXevozz;
            case DATA_ZURAMAT:                  return uiZuramat;
            case DATA_CYANIGOSA:                return uiCyanigosa;
            case DATA_MORAGG_CELL:              return uiMoraggCell;
            case DATA_EREKEM_CELL:              return uiErekemCell;
            case DATA_EREKEM_RIGHT_GUARD_CELL:  return uiErekemRightGuardCell;
            case DATA_EREKEM_LEFT_GUARD_CELL:   return uiErekemLeftGuardCell;
            case DATA_ICHORON_CELL:             return uiIchoronCell;
            case DATA_LAVANTHOR_CELL:           return uiLavanthorCell;
            case DATA_XEVOZZ_CELL:              return uiXevozzCell;
            case DATA_ZURAMAT_CELL:             return uiZuramatCell;
            case DATA_MAIN_DOOR:                return uiMainDoor;
            case DATA_SINCLARI:                 return uiSinclari;
        }

        return 0;
    }

    std::string GetSaveData()
    {
        OUT_SAVE_INST_DATA;

        std::ostringstream saveStream;
        saveStream << "V H " << m_auiEncounter[0] << " " << m_auiEncounter[1] << " "
            << m_auiEncounter[2] << " " << uiFirstBoss << " " << uiSecondBoss;

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

        if (dataHead1 == 'V' && dataHead2 == 'H')
        {
            m_auiEncounter[0] = data0;
            m_auiEncounter[1] = data1;
            m_auiEncounter[2] = data2;

            for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                if (m_auiEncounter[i] == IN_PROGRESS)
                    m_auiEncounter[i] = NOT_STARTED;

            uiFirstBoss = data3;
            uiSecondBoss = data4;
        }else OUT_LOAD_INST_DATA_FAIL;

        OUT_LOAD_INST_DATA_COMPLETE;
    }
};

InstanceData* GetInstanceData_instance_violet_hold(Map* pMap)
{
    return new instance_violet_hold(pMap);
}

void AddSC_instance_violet_hold()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_violet_hold";
    newscript->GetInstanceData = &GetInstanceData_instance_violet_hold;
    newscript->RegisterSelf();
}
