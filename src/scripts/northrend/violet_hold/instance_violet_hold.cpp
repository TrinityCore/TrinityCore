#include "ScriptedPch.h"
#include "violet_hold.h"

#define MAX_ENCOUNTER          3

/* Violet Hold encounters:
0 - First boss
1 - Second boss
2 - Cyanigosa*/

/* Violet hold bosses:
1 - Moragg
2 - Erekem
3 - Ichoron
4 - Lavanthor
5 - Xevozz
6 - Zuramat
7 - Cyanigosa */

enum GameObjects
{
    GO_MAIN_DOOR                                    = 191723,
    GO_XEVOZZ_DOOR                                  = 191556,
    GO_LAVANTHOR_DOOR                               = 191566,
    GO_ICHORON_DOOR                                 = 191722,
    GO_ZURAMAT_DOOR                                 = 191565,
    GO_EREKEM_DOOR                                  = 191564,
    GO_EREKEM_GUARD_1_DOOR                          = 191563,
    GO_EREKEM_GUARD_2_DOOR                          = 191562,
    GO_MORAGG_DOOR                                  = 191606,
    GO_INTRO_ACTIVATION_CRYSTAL                     = 193615,
    GO_ACTIVATION_CRYSTAL                           = 193611
};

const Position PortalLocation[] =
{
  {1936.07, 803.198, 53.3749, 3.12414},
  {1877.51, 850.104, 44.6599, 4.7822 },
  {1890.64, 753.471, 48.7224, 1.71042}
};

struct instance_violet_hold : public ScriptedInstance
{
    instance_violet_hold(Map* pMap) : ScriptedInstance(pMap) {Initialize();};

    uint64 uiMoragg;
    uint64 uiErekem;
    uint64 uiErekemGuard[2];
    uint64 uiIchoron;
    uint64 uiLavanthor;
    uint64 uiXevozz;
    uint64 uiZuramat;
    uint64 uiCyanigosa;
    uint64 uiSinclari;

    uint64 uiMoraggCell;
    uint64 uiErekemCell;
    uint64 uiErekemLeftGuardCell;
    uint64 uiErekemRightGuardCell;
    uint64 uiIchoronCell;
    uint64 uiLavanthorCell;
    uint64 uiXevozzCell;
    uint64 uiZuramatCell;
    uint64 uiMainDoor;

    uint64 uiActivationCrystal[3];

    uint32 uiActivationTimer;

    uint8 uiWaveCount;
    uint8 uiLocation;
    uint8 uiFirstBoss;
    uint8 uiSecondBoss;
    uint8 uiRemoveNpc;

    uint8 m_auiEncounter[MAX_ENCOUNTER];
    uint8 uiCountErekemGuards;
    uint8 uiCountActivationCrystals;

    bool bActive;
    bool bWiped;

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
        uiErekemGuard[0] = 0;
        uiErekemGuard[1] = 0;
        uiIchoronCell = 0;
        uiLavanthorCell = 0;
        uiXevozzCell = 0;
        uiZuramatCell = 0;
        uiMainDoor = 0;
        uiRemoveNpc = 0;

        uiWaveCount = 0;
        uiLocation = urand(0,2);
        uiFirstBoss = 0;
        uiSecondBoss = 0;
        uiCountErekemGuards = 0;
        uiCountActivationCrystals = 0;

        uiActivationTimer = 5000;

        bActive = false;
        bWiped  = false;

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
            case CREATURE_EREKEM_GUARD:
                if (uiCountErekemGuards < 2)
                {
                    uiErekemGuard[uiCountErekemGuards++] = pCreature->GetGUID();
                    pCreature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE|UNIT_FLAG_NON_ATTACKABLE);
                }
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

        if (add && (pCreature->GetGUID() == uiFirstBoss || pCreature->GetGUID() == uiSecondBoss))
        {
            pCreature->AllLootRemovedFromCorpse();
            pCreature->RemoveLootMode(1);
        }
    }

    void OnGameObjectCreate(GameObject* pGo, bool add)
    {
        switch(pGo->GetEntry())
        {
            case GO_EREKEM_GUARD_1_DOOR:
                uiErekemLeftGuardCell = pGo->GetGUID();
                break;
            case GO_EREKEM_GUARD_2_DOOR:
                uiErekemRightGuardCell = pGo->GetGUID();
                break;
            case GO_EREKEM_DOOR:
                uiErekemCell = pGo->GetGUID();
                break;
            case GO_ZURAMAT_DOOR:
                uiZuramatCell = pGo->GetGUID();
                break;
            case GO_LAVANTHOR_DOOR:
                uiLavanthorCell = pGo->GetGUID();
                break;
            case GO_MORAGG_DOOR:
                uiMoraggCell = pGo->GetGUID();
                break;
            case GO_ICHORON_DOOR:
                uiIchoronCell = pGo->GetGUID();
                break;
            case GO_XEVOZZ_DOOR:
                uiXevozzCell = pGo->GetGUID();
                break;
            case GO_MAIN_DOOR:
                uiMainDoor = pGo->GetGUID();
                break;
            case GO_ACTIVATION_CRYSTAL:
                if (uiCountActivationCrystals < 3)
                    uiActivationCrystal[uiCountActivationCrystals++] = pGo->GetGUID();
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
                bActive = true;
                break;
            case DATA_REMOVE_NPC:
                uiRemoveNpc = data;
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
            case DATA_REMOVE_NPC:               return uiRemoveNpc;
        }

        return 0;
    }

    void SpawnPortal()
    {
        if (Creature *pSinclari = instance->GetCreature(uiSinclari))
            if (Creature *pPortal = pSinclari->SummonCreature(CREATURE_TELEPORTATION_PORTAL,PortalLocation[uiLocation],TEMPSUMMON_CORPSE_DESPAWN))
                uiLocation = (uiLocation+urand(1,2))%3;
    }

    void StartBossEncounter(uint8 uiBoss, bool bForceRespawn = true)
    {
        Creature* pBoss = NULL;

        switch(uiBoss)
        {
            case BOSS_MORAGG:
                HandleGameObject(uiMoraggCell,bForceRespawn);
                if (pBoss = instance->GetCreature(uiMoragg))
                    pBoss->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE|UNIT_FLAG_NON_ATTACKABLE);
                break;
            case BOSS_EREKEM:
                HandleGameObject(uiErekemCell, bForceRespawn);
                HandleGameObject(uiErekemRightGuardCell, bForceRespawn);
                HandleGameObject(uiErekemLeftGuardCell, bForceRespawn);

                if (pBoss = instance->GetCreature(uiErekem))
                    pBoss->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE|UNIT_FLAG_NON_ATTACKABLE);

                if (Creature* pGuard1 = instance->GetCreature(uiErekemGuard[0]))
                {
                    if (bForceRespawn)
                        pGuard1->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE|UNIT_FLAG_NON_ATTACKABLE);
                    else
                        pGuard1->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE|UNIT_FLAG_NON_ATTACKABLE);
                }

                if (Creature* pGuard2 = instance->GetCreature(uiErekemGuard[1]))
                {
                    if (bForceRespawn)
                        pGuard2->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE|UNIT_FLAG_NON_ATTACKABLE);
                    else
                        pGuard2->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE|UNIT_FLAG_NON_ATTACKABLE);
                }
                break;
            case BOSS_ICHORON:
                HandleGameObject(uiIchoronCell,bForceRespawn);
                if (pBoss = instance->GetCreature(uiIchoron))
                    pBoss->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE|UNIT_FLAG_NON_ATTACKABLE);
                break;
            case BOSS_LAVANTHOR:
                HandleGameObject(uiLavanthorCell,bForceRespawn);
                if (pBoss = instance->GetCreature(uiLavanthor))
                    pBoss->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE|UNIT_FLAG_NON_ATTACKABLE);
                break;
            case BOSS_XEVOZZ:
                HandleGameObject(uiXevozzCell,bForceRespawn);
                if (pBoss = instance->GetCreature(uiXevozz))
                    pBoss->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE|UNIT_FLAG_NON_ATTACKABLE);
                break;
            case BOSS_ZURAMAT:
                HandleGameObject(uiZuramatCell,bForceRespawn);
                if (pBoss = instance->GetCreature(uiZuramat))
                    pBoss->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE|UNIT_FLAG_NON_ATTACKABLE);
                break;
        }

        if (!bForceRespawn && pBoss)
        {
            if (pBoss->isDead())
            {
                // respawn but avoid to be looted again
                pBoss->Respawn();
                pBoss->RemoveLootMode(1);
            }
            pBoss->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE|UNIT_FLAG_NON_ATTACKABLE);
            SetData(DATA_WAVE_COUNT,0);
            uiWaveCount = 0;
        }
    }

    void AddWave()
    {
        DoUpdateWorldState(WORLD_STATE_VH, 1);
        DoUpdateWorldState(WORLD_STATE_VH_WAVE_COUNT, uiWaveCount);
        DoUpdateWorldState(WORLD_STATE_VH_PRISON_STATE, 100); // TODO

        switch(uiWaveCount)
        {
            case 6:
                if (uiFirstBoss == 0)
                    uiFirstBoss = urand(1,6);
                StartBossEncounter(uiFirstBoss);
                break;
            case 12:
                if (uiSecondBoss == 0)
                    do 
                    {
                        uiSecondBoss = urand(1,6);
                    } while (uiSecondBoss == uiFirstBoss);
                StartBossEncounter(uiSecondBoss);
                break;
            case 18:
            {
                Creature *pSinclari = instance->GetCreature(uiSinclari);
                if (pSinclari)
                    pSinclari->SummonCreature(CREATURE_CYANIGOSA,PortalLocation[0],TEMPSUMMON_DEAD_DESPAWN);
                break;
            }
            case 1:
            {
                if (GameObject* pMainDoor = instance->GetGameObject(uiMainDoor))
                    pMainDoor->SetGoState(GO_STATE_READY);
            }
            default:
                if (!bWiped)
                    SpawnPortal();
                bWiped = false;
                break;
        }
    }

    uint64 GetData64(uint32 identifier)
    {
        switch(identifier)
        {
            case DATA_MORAGG:                   return uiMoragg;
            case DATA_EREKEM:                   return uiErekem;
            case DATA_EREKEM_GUARD_1:           return uiErekemGuard[0];
            case DATA_EREKEM_GUARD_2:           return uiErekemGuard[1];
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
        saveStream << "V H " << (uint16)m_auiEncounter[0] 
            << " " << (uint16)m_auiEncounter[1]
            << " " << (uint16)m_auiEncounter[2]
            << " " << (uint16)uiFirstBoss
            << " " << (uint16)uiSecondBoss;

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
        } else OUT_LOAD_INST_DATA_FAIL;

        OUT_LOAD_INST_DATA_COMPLETE;
    }

    bool CheckWipe()
    {
        Map::PlayerList const &players = instance->GetPlayers();
        for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
        {
            Player* pPlayer = itr->getSource();
            if (pPlayer->isGameMaster())
                continue;

            if (pPlayer->isAlive())
                return false;
        }

        return true;
    }

    void Update(uint32 diff)
    {
        if (!instance->HavePlayers())
            return;

        if (bActive)
        {
            if (uiActivationTimer < diff)
            {
                AddWave();
                bActive = false;
                uiActivationTimer = 5000;
            } else uiActivationTimer -= diff;
        }

        if (GameObject* pMainDoor = instance->GetGameObject(uiMainDoor))
            if (pMainDoor->GetGoState() != GO_STATE_ACTIVE && CheckWipe())
            {
                SetData(DATA_REMOVE_NPC, 1);
                StartBossEncounter(uiFirstBoss, false);
                StartBossEncounter(uiSecondBoss, false);
                bWiped = true;
                if (Creature* pSinclari = instance->GetCreature(uiSinclari))
                {
                    pSinclari->DisappearAndDie();
                    pSinclari->Respawn(true);
                }

                if (GameObject* pMainDoor = instance->GetGameObject(uiMainDoor))
                    pMainDoor->SetGoState(GO_STATE_ACTIVE);
                SetData(DATA_WAVE_COUNT, 0);
            }
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
