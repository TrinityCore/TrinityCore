/*
 * Copyright (C) 2009 - 2010 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "ScriptPCH.h"
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

enum AzureSaboteurSpells
{
    SABOTEUR_SHIELD_DISRUPTION                      = 58291,
    SABOTEUR_SHIELD_EFFECT                          = 45775
};

enum CrystalSpells
{
    SPELL_ARCANE_LIGHTNING                          = 57912
};

enum Events
{
    EVENT_ACTIVATE_CRYSTAL                          = 20001
};

const Position PortalLocation[] =
{
    {1877.51, 850.104, 44.6599, 4.7822 },     // WP 1
    {1918.37, 853.437, 47.1624, 4.12294},     // WP 2
    {1936.07, 803.198, 53.3749, 3.12414},     // WP 3
    {1927.61, 758.436, 51.4533, 2.20891},     // WP 4
    {1890.64, 753.471, 48.7224, 1.71042},     // WP 5
    {1908.31, 809.657, 38.7037, 3.08701}      // WP 6
};

const Position BossStartMove1  = {1894.684448, 739.390503, 47.668003};
const Position BossStartMove2  = {1875.173950, 860.832703, 43.333565};
const Position BossStartMove21 = {1858.854614, 855.071411, 43.333565};
const Position BossStartMove22 = {1891.926636, 863.388977, 43.333565};
const Position BossStartMove3  = {1916.138062, 778.152222, 35.772308};
const Position BossStartMove4  = {1853.618286, 758.557617, 38.657505};
const Position BossStartMove5  = {1906.683960, 842.348022, 38.637459};
const Position BossStartMove6  = {1928.207031, 852.864441, 47.200813};

const Position CyanigosasSpawnLocation = {1930.281250, 804.407715, 52.410946, 3.139621};
const Position MiddleRoomLocation = {1892.291260, 805.696838, 38.438862, 3.139621};
const Position MiddleRoomPortalSaboLocation = {1896.622925, 804.854126, 38.504772, 3.139621};

//Cyanigosa's prefight event data
enum Yells
{
    CYANIGOSA_SAY_SPAWN                           = -1608005
};
enum Spells
{
    CYANIGOSA_SPELL_TRANSFORM                     = 58668,
    CYANIGOSA_BLUE_AURA                           = 47759,
};
enum Achievements
{
    ACHIEV_DEFENSELESS                            = 1816
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
    uint64 uiTeleportationPortal;
    uint64 uiSaboteurPortal;

    uint64 uiActivationCrystal[3];

    uint32 uiActivationTimer;
    uint32 uiCyanigosaEventTimer;

    std::set<uint64> trashMobs; // to kill with crystal

    uint8 uiWaveCount;
    uint8 uiLocation;
    uint8 uiFirstBoss;
    uint8 uiSecondBoss;
    uint8 uiRemoveNpc;
    uint32 uiDoorSpellTimer;
    
    uint8 uiMainDoorState;
    uint8 uiDoorIntegrity;

    uint8 m_auiEncounter[MAX_ENCOUNTER];
    uint8 uiCountErekemGuards;
    uint8 uiCountActivationCrystals;
    uint8 uiCyanigosaEventPhase;

    bool bActive;
    bool bWiped;
    bool bIsDoorSpellCasted;
    bool bCrystalActivated;

    std::list<uint8> NpcAtDoorCastingList;

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
        uiTeleportationPortal = 0;
        uiSaboteurPortal = 0;

        trashMobs.clear();
        
        uiRemoveNpc = 0;

        uiMainDoorState = GO_STATE_ACTIVE;
        uiDoorIntegrity = 100;

        uiWaveCount = 0;
        uiLocation = urand(0,5);
        uiFirstBoss = 0;
        uiSecondBoss = 0;
        uiCountErekemGuards = 0;
        uiCountActivationCrystals = 0;
        uiCyanigosaEventPhase = 1;

        uiActivationTimer = 5000;
        uiDoorSpellTimer = 2000;
        uiCyanigosaEventTimer = 3*IN_MILISECONDS;

        bActive = false;
        bIsDoorSpellCasted = false;
        bCrystalActivated = false;

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
                pCreature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE|UNIT_FLAG_NON_ATTACKABLE);
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

    void OnGameObjectCreate(GameObject* pGo, bool /*add*/)
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
                    if (!bCrystalActivated && uiDoorIntegrity == 100)
                        DoCompleteAchievement(ACHIEV_DEFENSELESS);
                }
                break;
            case DATA_WAVE_COUNT:
                uiWaveCount = data;
                bActive = true;
                break;
            case DATA_REMOVE_NPC:
                uiRemoveNpc = data;
                break;
            case DATA_PORTAL_LOCATION:
                uiLocation = (uint8)data;
                break;
            case DATA_DOOR_INTEGRITY:
                uiDoorIntegrity = data;
                DoUpdateWorldState(WORLD_STATE_VH_PRISON_STATE, uiDoorIntegrity);
                break;
            case DATA_NPC_PRESENCE_AT_DOOR_ADD:
                NpcAtDoorCastingList.push_back(data);
                break;
            case DATA_NPC_PRESENCE_AT_DOOR_REMOVE:
                if(!NpcAtDoorCastingList.empty())
                    NpcAtDoorCastingList.pop_back();
                break;
            case DATA_MAIN_DOOR:
                if(GameObject* pMainDoor = instance->GetGameObject(uiMainDoor))
                {
                    switch(data)
                    {
                        case GO_STATE_ACTIVE:
                            pMainDoor->SetGoState(GO_STATE_ACTIVE);
                            break;
                        case GO_STATE_READY:
                            pMainDoor->SetGoState(GO_STATE_READY);
                            break;
                        case GO_STATE_ACTIVE_ALTERNATIVE:
                            pMainDoor->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
                            break;
                    }
                }
                uiMainDoorState = data;
                break;
            case DATA_START_BOSS_ENCOUNTER:
                switch(uiWaveCount)
                {
                    case 6:
                        StartBossEncounter(uiFirstBoss);
                        break;
                    case 12:
                        StartBossEncounter(uiSecondBoss);
                        break;
                }
                break;
            case DATA_ACTIVATE_CRYSTAL:
                ActivateCrystal();
                break;
        }
    }

    void SetData64(uint32 type, uint64 data)
    {
        switch(type)
        {
            case DATA_ADD_TRASH_MOB:
                trashMobs.insert(data);
                break;
            case DATA_DEL_TRASH_MOB:
                trashMobs.erase(data);
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
            case DATA_PORTAL_LOCATION:          return uiLocation;
            case DATA_DOOR_INTEGRITY:           return uiDoorIntegrity;
            case DATA_NPC_PRESENCE_AT_DOOR:     return NpcAtDoorCastingList.size();
            case DATA_MAIN_DOOR:                return uiMainDoorState;
            case DATA_FIRST_BOSS:               return uiFirstBoss;
            case DATA_SECOND_BOSS:              return uiSecondBoss;
        }

        return 0;
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
            case DATA_TELEPORTATION_PORTAL:     return uiTeleportationPortal;
            case DATA_SABOTEUR_PORTAL:          return uiSaboteurPortal;
        }

        return 0;
    }

    void SpawnPortal()
    {
        SetData(DATA_PORTAL_LOCATION, (GetData(DATA_PORTAL_LOCATION) + urand(1,5))%6);
        if (Creature *pSinclari = instance->GetCreature(uiSinclari))
            if(Creature *portal = pSinclari->SummonCreature(CREATURE_TELEPORTATION_PORTAL,PortalLocation[GetData(DATA_PORTAL_LOCATION)],TEMPSUMMON_CORPSE_DESPAWN))
                uiTeleportationPortal = portal->GetGUID();
    }

    void StartBossEncounter(uint8 uiBoss, bool bForceRespawn = true)
    {
        Creature* pBoss = NULL;

        switch(uiBoss)
        {
            case BOSS_MORAGG:
                HandleGameObject(uiMoraggCell,bForceRespawn);
                pBoss = instance->GetCreature(uiMoragg);
                if (pBoss)
                    pBoss->GetMotionMaster()->MovePoint(0, BossStartMove1);
                break;
            case BOSS_EREKEM:
                HandleGameObject(uiErekemCell, bForceRespawn);
                HandleGameObject(uiErekemRightGuardCell, bForceRespawn);
                HandleGameObject(uiErekemLeftGuardCell, bForceRespawn);

                pBoss = instance->GetCreature(uiErekem);

                if (pBoss)
                    pBoss->GetMotionMaster()->MovePoint(0, BossStartMove2);

                if (Creature* pGuard1 = instance->GetCreature(uiErekemGuard[0]))
                {
                    if (bForceRespawn)
                        pGuard1->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE|UNIT_FLAG_NON_ATTACKABLE);
                    else
                        pGuard1->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE|UNIT_FLAG_NON_ATTACKABLE);
                    pGuard1->GetMotionMaster()->MovePoint(0, BossStartMove21);
                }

                if (Creature* pGuard2 = instance->GetCreature(uiErekemGuard[1]))
                {
                    if (bForceRespawn)
                        pGuard2->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE|UNIT_FLAG_NON_ATTACKABLE);
                    else
                        pGuard2->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE|UNIT_FLAG_NON_ATTACKABLE);
                    pGuard2->GetMotionMaster()->MovePoint(0, BossStartMove22);
                }
                break;
            case BOSS_ICHORON:
                HandleGameObject(uiIchoronCell,bForceRespawn);
                pBoss = instance->GetCreature(uiIchoron);
                if (pBoss)
                    pBoss->GetMotionMaster()->MovePoint(0, BossStartMove3);
                break;
            case BOSS_LAVANTHOR:
                HandleGameObject(uiLavanthorCell,bForceRespawn);
                pBoss = instance->GetCreature(uiLavanthor);
                if (pBoss)
                    pBoss->GetMotionMaster()->MovePoint(0, BossStartMove4);
                break;
            case BOSS_XEVOZZ:
                HandleGameObject(uiXevozzCell,bForceRespawn);
                pBoss = instance->GetCreature(uiXevozz);
                if (pBoss)
                    pBoss->GetMotionMaster()->MovePoint(0, BossStartMove5);
                break;
            case BOSS_ZURAMAT:
                HandleGameObject(uiZuramatCell,bForceRespawn);
                pBoss = instance->GetCreature(uiZuramat);
                if (pBoss)
                    pBoss->GetMotionMaster()->MovePoint(0, BossStartMove6);
                break;
        }

        // generic boss state changes
        if (pBoss)
        {
            pBoss->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE|UNIT_FLAG_NON_ATTACKABLE);
            pBoss->SetReactState(REACT_AGGRESSIVE);

            if (!bForceRespawn)
            {
                if (pBoss->isDead())
                {
                    // respawn but avoid to be looted again
                    pBoss->Respawn();
                    pBoss->RemoveLootMode(1);
                }
                pBoss->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE|UNIT_FLAG_NON_ATTACKABLE);
                uiWaveCount = 0;
            }
        }
    }

    void AddWave()
    {
        DoUpdateWorldState(WORLD_STATE_VH, 1);
        DoUpdateWorldState(WORLD_STATE_VH_WAVE_COUNT, uiWaveCount);

        switch(uiWaveCount)
        {
            case 6:
                if (uiFirstBoss == 0)
                    uiFirstBoss = urand(1,6);
                if (Creature *pSinclari = instance->GetCreature(uiSinclari))
                {
                    if(Creature *pPortal = pSinclari->SummonCreature(CREATURE_TELEPORTATION_PORTAL, MiddleRoomPortalSaboLocation, TEMPSUMMON_CORPSE_DESPAWN))
                        uiSaboteurPortal = pPortal->GetGUID();
                    if (Creature *pAzureSaboteur = pSinclari->SummonCreature(CREATURE_SABOTEOUR, MiddleRoomLocation, TEMPSUMMON_DEAD_DESPAWN))
                        pAzureSaboteur->CastSpell(pAzureSaboteur, SABOTEUR_SHIELD_EFFECT, false);
                }
                break;
            case 12:
                if (uiSecondBoss == 0)
                    do
                    {
                        uiSecondBoss = urand(1,6);
                    } while (uiSecondBoss == uiFirstBoss);
                if (Creature *pSinclari = instance->GetCreature(uiSinclari))
                {
                    if(Creature *pPortal = pSinclari->SummonCreature(CREATURE_TELEPORTATION_PORTAL, MiddleRoomPortalSaboLocation, TEMPSUMMON_CORPSE_DESPAWN))
                        uiSaboteurPortal = pPortal->GetGUID();
                    if (Creature *pAzureSaboteur = pSinclari->SummonCreature(CREATURE_SABOTEOUR, MiddleRoomLocation, TEMPSUMMON_DEAD_DESPAWN))
                        pAzureSaboteur->CastSpell(pAzureSaboteur, SABOTEUR_SHIELD_EFFECT, false);
                }
                break;
            case 18:
            {
                Creature *pSinclari = instance->GetCreature(uiSinclari);
                if (pSinclari)
                    pSinclari->SummonCreature(CREATURE_CYANIGOSA,CyanigosasSpawnLocation,TEMPSUMMON_DEAD_DESPAWN);
                break;
            }
            case 1:
            {
                if (GameObject* pMainDoor = instance->GetGameObject(uiMainDoor))
                    pMainDoor->SetGoState(GO_STATE_READY);
                DoUpdateWorldState(WORLD_STATE_VH_PRISON_STATE, 100);
            }
            default:
                SpawnPortal();
                break;
        }
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

        // portals should spawn if other portal is dead and doors are closed
        if (bActive && GetData(DATA_MAIN_DOOR) == GO_STATE_READY)
        {
            if (uiActivationTimer < diff)
            {
                AddWave();
                bActive = false;
                uiActivationTimer = 5000;
            } else uiActivationTimer -= diff;
        }

        // if doors are closed (means event is in progres) and players have wiped then reset instance
        if (GetData(DATA_MAIN_DOOR) != GO_STATE_ACTIVE && CheckWipe())
        {
            SetData(DATA_REMOVE_NPC, 1);
            StartBossEncounter(uiFirstBoss, false);
            StartBossEncounter(uiSecondBoss, false);

            SetData(DATA_MAIN_DOOR,GO_STATE_ACTIVE);
            SetData(DATA_WAVE_COUNT, 0);

            if (Creature* pSinclari = instance->GetCreature(uiSinclari))
            {
                pSinclari->SetVisibility(VISIBILITY_ON);

                std::list<Creature*> GuardList;
                pSinclari->GetCreatureListWithEntryInGrid(GuardList, NPC_VIOLET_HOLD_GUARD, 40.0f);
                if (!GuardList.empty())
                {
                    for (std::list<Creature*>::const_iterator itr = GuardList.begin(); itr != GuardList.end(); ++itr)
                    {
                        if (Creature* pGuard = *itr)
                        {
                            pGuard->SetVisibility(VISIBILITY_ON);
                            pGuard->SetReactState(REACT_AGGRESSIVE);
                            pGuard->GetMotionMaster()->MovePoint(1,pGuard->GetHomePosition());
                        }
                    }
                }
                pSinclari->GetMotionMaster()->MovePoint(1,pSinclari->GetHomePosition());
                pSinclari->RemoveFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NOT_SELECTABLE);
            }
        }

        // Cyanigosa is spawned but not tranformed, prefight event
        Creature *pCyanigosa = instance->GetCreature(uiCyanigosa);
        if (pCyanigosa && !pCyanigosa->HasAura(CYANIGOSA_SPELL_TRANSFORM))
        {
            if (uiCyanigosaEventTimer <= diff)
            {
                switch(uiCyanigosaEventPhase)
                {
                    case 1:
                        pCyanigosa->CastSpell(pCyanigosa, CYANIGOSA_BLUE_AURA, false);
                        DoScriptText(CYANIGOSA_SAY_SPAWN, pCyanigosa);
                        uiCyanigosaEventTimer = 7*IN_MILISECONDS;
                        ++uiCyanigosaEventPhase;
                        break;
                    case 2:
                        pCyanigosa->GetMotionMaster()->MoveJump(MiddleRoomLocation.GetPositionX(), MiddleRoomLocation.GetPositionY(), MiddleRoomLocation.GetPositionZ(), 10.0f, 20.0f);
                        pCyanigosa->CastSpell(pCyanigosa, CYANIGOSA_BLUE_AURA, false);
                        uiCyanigosaEventTimer = 7*IN_MILISECONDS;
                        ++uiCyanigosaEventPhase;
                        break;
                    case 3:
                        pCyanigosa->RemoveAurasDueToSpell(CYANIGOSA_BLUE_AURA);
                        pCyanigosa->CastSpell(pCyanigosa, CYANIGOSA_SPELL_TRANSFORM, 0);
                        pCyanigosa->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE|UNIT_FLAG_NON_ATTACKABLE);
                        pCyanigosa->SetReactState(REACT_AGGRESSIVE);
                        uiCyanigosaEventTimer = 2*IN_MILISECONDS;
                        ++uiCyanigosaEventPhase;
                        break;
                    case 4:
                        uiCyanigosaEventPhase = 0;
                        break;
                }
            } else uiCyanigosaEventTimer -= diff;
        }

        // if there are NPCs in front of the prison door, which are casting the door seal spell and doors are active
        if(GetData(DATA_NPC_PRESENCE_AT_DOOR) && (GetData(DATA_MAIN_DOOR) == GO_STATE_READY))
        {
            // if door integrity is > 0 then decrase it's integrity state
            if(GetData(DATA_DOOR_INTEGRITY))
            {
                if(uiDoorSpellTimer < diff)
                {
                    SetData(DATA_DOOR_INTEGRITY,GetData(DATA_DOOR_INTEGRITY)-1);
                    uiDoorSpellTimer =2000;
                } else uiDoorSpellTimer -= diff;
            }
            // else set door state to active (means door will open and group have failed to sustain mob invasion on the door)
            else
                SetData(DATA_MAIN_DOOR,GO_STATE_ACTIVE);
        }
    }

    void ActivateCrystal()
    {
        // Kill all mobs registered with SetData64(ADD_TRASH_MOB)
        // TODO: All visual, spells etc
        for (std::set<uint64>::const_iterator itr = trashMobs.begin(); itr != trashMobs.end(); ++itr)
        {
            Creature* pCreature = instance->GetCreature(*itr);
            if (pCreature && pCreature->isAlive())
                pCreature->CastSpell(pCreature,SPELL_ARCANE_LIGHTNING,true);  // Who should cast the spell?
        }
    }

    void ProcessEvent(GameObject* pGO, uint32 uiEventId)
    {
        switch(uiEventId)
        {
            case EVENT_ACTIVATE_CRYSTAL:
                bCrystalActivated = true; // Activation by player's will throw event signal
                ActivateCrystal();
                break;
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
