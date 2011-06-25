/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ScriptPCH.h"
#include "naxxramas.h"
#define  SOUND_KT 14484

const DoorData doorData[] =
{
    {181126,    BOSS_ANUBREKHAN, DOOR_TYPE_ROOM,     BOUNDARY_S},
    {181195,    BOSS_ANUBREKHAN, DOOR_TYPE_PASSAGE,  0},
    {194022,    BOSS_FAERLINA,  DOOR_TYPE_PASSAGE,  0},
    {181209,    BOSS_FAERLINA,  DOOR_TYPE_PASSAGE,  0},
    {181209,    BOSS_MAEXXNA,   DOOR_TYPE_ROOM,     BOUNDARY_SW},
    {181200,    BOSS_NOTH,      DOOR_TYPE_ROOM,     BOUNDARY_N},
    {181201,    BOSS_NOTH,      DOOR_TYPE_PASSAGE,  BOUNDARY_E},
    {181202,    BOSS_NOTH,      DOOR_TYPE_PASSAGE,  0},
    {181202,    BOSS_HEIGAN,    DOOR_TYPE_ROOM,     BOUNDARY_N},
    {181203,    BOSS_HEIGAN,    DOOR_TYPE_PASSAGE,  BOUNDARY_E},
    {181241,    BOSS_HEIGAN,    DOOR_TYPE_PASSAGE,  0},
    {181241,    BOSS_LOATHEB,   DOOR_TYPE_ROOM,     BOUNDARY_W},
    {181123,    BOSS_PATCHWERK, DOOR_TYPE_PASSAGE,  0},
    {181123,    BOSS_GROBBULUS, DOOR_TYPE_ROOM,     0},
    {181120,    BOSS_GLUTH,     DOOR_TYPE_PASSAGE,  BOUNDARY_NW},
    {181121,    BOSS_GLUTH,     DOOR_TYPE_PASSAGE,  0},
    {181121,    BOSS_THADDIUS,  DOOR_TYPE_ROOM,     0},
    {181124,    BOSS_RAZUVIOUS, DOOR_TYPE_PASSAGE,  0},
    {181124,    BOSS_GOTHIK,    DOOR_TYPE_ROOM,     BOUNDARY_N},
    {181125,    BOSS_GOTHIK,    DOOR_TYPE_PASSAGE,  BOUNDARY_S},
    {181119,    BOSS_GOTHIK,    DOOR_TYPE_PASSAGE,  0},
    {181119,    BOSS_HORSEMEN,  DOOR_TYPE_ROOM,     BOUNDARY_NE},
    {181225,    BOSS_SAPPHIRON, DOOR_TYPE_PASSAGE,  BOUNDARY_W},
    {181228,    BOSS_KELTHUZAD, DOOR_TYPE_ROOM,     BOUNDARY_S},
    {0,         0,              DOOR_TYPE_ROOM,     0}, // EOF
};

const MinionData minionData[] =
{
    //{16573,     BOSS_ANUBREKHAN},     there is no spawn point in db, so we do not add them here
    {16506,     BOSS_FAERLINA},
    {16505,     BOSS_FAERLINA},
    {16803,     BOSS_RAZUVIOUS},
    {16063,     BOSS_HORSEMEN},
    {16064,     BOSS_HORSEMEN},
    {16065,     BOSS_HORSEMEN},
    {30549,     BOSS_HORSEMEN},
    {0,         0, }
};

enum eEnums
{
    GO_HORSEMEN_CHEST_HERO  = 193426,
    GO_HORSEMEN_CHEST       = 181366,                   //four horsemen event, DoRespawnGameObject() when event == DONE
    GO_GOTHIK_GATE          = 181170,
    GO_KELTHUZAD_PORTAL01   = 181402,
    GO_KELTHUZAD_PORTAL02   = 181403,
    GO_KELTHUZAD_PORTAL03   = 181404,
    GO_KELTHUZAD_PORTAL04   = 181405,
    GO_KELTHUZAD_TRIGGER    = 181444,

    GO_ROOM_ANUBREKHAN      = 181126,
    GO_PASSAGE_ANUBREKHAN   = 181195,
    GO_PASSAGE_FAERLINA     = 194022,
    GO_ROOM_MAEXXNA         = 181209,
    GO_ROOM_NOTH            = 181200,
    GO_PASSAGE_NOTH         = 181201,
    GO_ROOM_HEIGAN          = 181202,
    GO_PASSAGE_HEIGAN       = 181203,
    GO_ROOM_LOATHEB         = 181241,
    GO_ROOM_GROBBULUS       = 181123,
    GO_PASSAGE_GLUTH        = 181120,
    GO_ROOM_THADDIUS        = 181121,
    GO_ROOM_GOTHIK          = 181124,
    GO_PASSAGE_GOTHIK       = 181125,
    GO_ROOM_HORSEMEN        = 181119,
    GO_PASSAGE_SAPPHIRON    = 181225,
    GO_ROOM_KELTHUZAD       = 181228,
    // Portals
    GO_ARAC_PORTAL              = 181575,
    GO_PLAG_PORTAL              = 181577,
    GO_MILI_PORTAL              = 181578,
    GO_CONS_PORTAL              = 181576,

    SPELL_ERUPTION          = 29371,
    SPELL_SLIME             = 28801
};

enum eDoors
{
    DOOR_ROOM_ANUBREKHAN      = 0,
    DOOR_PASSAGE_ANUBREKHAN,
    DOOR_PASSAGE_FAERLINA,
    DOOR_ROOM_MAEXXNA,
    DOOR_ROOM_NOTH,
    DOOR_PASSAGE_NOTH,
    DOOR_ROOM_HEIGAN,
    DOOR_PASSAGE_HEIGAN,
    DOOR_ROOM_LOATHEB,
    DOOR_ROOM_GROBBULUS,
    DOOR_PASSAGE_GLUTH,
    DOOR_ROOM_THADDIUS,
    DOOR_ROOM_GOTHIK,
    DOOR_PASSAGE_GOTHIK,
    DOOR_ROOM_HORSEMEN,
    DOOR_PASSAGE_SAPPHIRON,
    DOOR_ROOM_KELTHUZAD,
    MAX_DOOR_NAXX
};

const float HeiganPos[2] = {2796, -3707};
const float HeiganEruptionSlope[3] =
{
    (-3685 - HeiganPos[1]) /(2724 - HeiganPos[0]),
    (-3647 - HeiganPos[1]) /(2749 - HeiganPos[0]),
    (-3637 - HeiganPos[1]) /(2771 - HeiganPos[0]),
};

// 0  H      x
//  1        ^
//   2       |
//    3  y<--o
inline uint32 GetEruptionSection(float x, float y)
{
    y -= HeiganPos[1];
    if (y < 1.0f)
        return 0;

    x -= HeiganPos[0];
    if (x > -1.0f)
        return 3;

    float slope = y/x;
    for (uint32 i = 0; i < 3; ++i)
        if (slope > HeiganEruptionSlope[i])
            return i;
    return 3;
}

class instance_naxxramas : public InstanceMapScript
{
public:
    instance_naxxramas() : InstanceMapScript("instance_naxxramas", 533) { }

    InstanceScript* GetInstanceScript(InstanceMap* pMap) const
    {
        return new instance_naxxramas_InstanceMapScript(pMap);
    }

    struct instance_naxxramas_InstanceMapScript : public InstanceScript
    {
        instance_naxxramas_InstanceMapScript(Map* pMap) : InstanceScript(pMap)
        {
            //SetBossNumber(MAX_BOSS_NUMBER);
            //LoadDoorData(doorData);
            //LoadMinionData(minionData);
            m_PlayerDeathCount = 0;
            m_HeiganPlayerDeathCount = 0;
            Step = 0;
		 instance->LoadGrid(139.702469f, -12.263711f);

            Initialize();
        }

        std::set<uint64> HeiganEruptionGUID[4];

        std::set<uint64> FaerlinaMinion;
        std::set<uint64> RazuviousMinion;
        std::set<uint64> Horsemen;

        uint32 m_auiEncounter[MAX_BOSS_NUMBER];
        uint32 m_PlayerDeathCount;
        uint32 m_HeiganPlayerDeathCount;
        uint32 SlimeCheckTimer;
        uint32 StepTimer;
        uint32 Step;

        uint64 GothikGateGUID;
        uint64 HorsemenChestGUID;
        uint64 SapphironGUID;
        uint64 uiFaerlina;
        uint64 uiThane;
        uint64 uiLady;
        uint64 uiBaron;
        uint64 uiSir;

        uint64 uiThaddius;
        uint64 uiFeugen;
        uint64 uiStalagg;

        uint64 AracPortalGUID;
        uint64 PlagPortalGUID;
        uint64 MiliPortalGUID;
        uint64 ConsPortalGUID;

        uint64 uiKelthuzad;        
        uint64 uiKelthuzade;
        uint64 uiKelthuzadcat;
        uint64 uiLichKing;
        uint64 uiKelthuzadTrigger;
        uint64 uiPortals[4];
        uint64 uiNaxxDoors[MAX_DOOR_NAXX];

        GOState gothikDoorState;

        time_t minHorsemenDiedTime;
        time_t maxHorsemenDiedTime;

        void Initialize()
        {
            memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));
            gothikDoorState = GO_STATE_ACTIVE;
            SlimeCheckTimer = 1000;
        }

        bool IsEncounterInProgress() const
        {
            for (int i = 0; i < MAX_BOSS_NUMBER; ++i)
                if (m_auiEncounter[i] == IN_PROGRESS)
                    return true;

            return false;
        }

        void OnPlayerKilled(Player *pPlayer) 
        {
            if(IsEncounterInProgress())
                m_PlayerDeathCount++;
            if(m_auiEncounter[BOSS_HEIGAN] == IN_PROGRESS)
                m_HeiganPlayerDeathCount++;
        }

        void OnCreatureCreate(Creature* pCreature)
        {
            switch(pCreature->GetEntry())
            {
                case 15989: SapphironGUID = pCreature->GetGUID(); return;
                case 15953: uiFaerlina = pCreature->GetGUID(); return;
                case 16064: uiThane = pCreature->GetGUID(); return;
                case 16065: uiLady = pCreature->GetGUID(); return;
                case 30549: uiBaron = pCreature->GetGUID(); return;
                case 16063: uiSir = pCreature->GetGUID(); return;
                case 15928: uiThaddius = pCreature->GetGUID(); return;
                case 15930: uiFeugen = pCreature->GetGUID(); return;
                case 15929: uiStalagg = pCreature->GetGUID(); return;
                case 15990: uiKelthuzad = pCreature->GetGUID(); return;
                case 300000: uiKelthuzade = pCreature->GetGUID(); return;
                case 16998: uiKelthuzadcat = pCreature->GetGUID(); return;
                case 37181: uiLichKing = pCreature->GetGUID(); return;
            }
            switch(pCreature->GetEntry())
            {
                case 16506:
                case 16505:
                    FaerlinaMinion.insert(pCreature->GetGUID());
                    break;
                case 16803:
                    RazuviousMinion.insert(pCreature->GetGUID());
                    break;
                case 16063:
                case 16064:
                case 16065:
                case 30549:
                    Horsemen.insert(pCreature->GetGUID());
                    break;
            }

            //AddMinion(pCreature, add);
        }

        void OnGameObjectRemove(GameObject* pGo)
        {
            if (pGo->GetGOInfo()->displayId == 6785 || pGo->GetGOInfo()->displayId == 1287)
            {
                uint32 section = GetEruptionSection(pGo->GetPositionX(), pGo->GetPositionY());
                HeiganEruptionGUID[section].erase(pGo->GetGUID());
                return;
            }

            if(pGo->GetEntry() == GO_BIRTH)
            {
                if (SapphironGUID)
                {
                    if (Creature *pSapphiron = instance->GetCreature(SapphironGUID))
                        pSapphiron->AI()->DoAction(DATA_SAPPHIRON_BIRTH);
                    return;
                }
            }
        }

        void OnGameObjectCreate(GameObject* pGo)
        {
            if (pGo->GetGOInfo()->displayId == 6785 || pGo->GetGOInfo()->displayId == 1287)
            {
                uint32 section = GetEruptionSection(pGo->GetPositionX(), pGo->GetPositionY());
                HeiganEruptionGUID[section].insert(pGo->GetGUID());
                return;
            }

            switch(pGo->GetEntry())
            {
                case GO_GOTHIK_GATE:
                    GothikGateGUID = pGo->GetGUID();
                    pGo->SetGoState(gothikDoorState);
                    break;
                case GO_HORSEMEN_CHEST: HorsemenChestGUID = pGo->GetGUID(); break;
                case GO_HORSEMEN_CHEST_HERO: HorsemenChestGUID = pGo->GetGUID(); break;
                case GO_KELTHUZAD_PORTAL01: uiPortals[0] = pGo->GetGUID(); break;
                case GO_KELTHUZAD_PORTAL02: uiPortals[1] = pGo->GetGUID(); break;
                case GO_KELTHUZAD_PORTAL03: uiPortals[2] = pGo->GetGUID(); break;
                case GO_KELTHUZAD_PORTAL04: uiPortals[3] = pGo->GetGUID(); break;
                case GO_KELTHUZAD_TRIGGER: uiKelthuzadTrigger = pGo->GetGUID(); break;
               case GO_ARAC_PORTAL:
                    AracPortalGUID = pGo->GetGUID();
                    break;
               case GO_PLAG_PORTAL:
                    PlagPortalGUID = pGo->GetGUID();
                    break;
                case GO_MILI_PORTAL:
                    MiliPortalGUID = pGo->GetGUID();
                    break;
                case GO_CONS_PORTAL:
                    ConsPortalGUID = pGo->GetGUID();
                    break;
                case GO_ROOM_ANUBREKHAN:
                    uiNaxxDoors[DOOR_ROOM_ANUBREKHAN] = pGo->GetGUID();
                    pGo->SetGoState(m_auiEncounter[BOSS_ANUBREKHAN] != IN_PROGRESS ? GO_STATE_ACTIVE : GO_STATE_READY);
                    break;
                case GO_PASSAGE_ANUBREKHAN:
                    uiNaxxDoors[DOOR_PASSAGE_ANUBREKHAN] = pGo->GetGUID();
                    pGo->SetGoState(m_auiEncounter[BOSS_ANUBREKHAN] == DONE ? GO_STATE_ACTIVE : GO_STATE_READY);
                    break;
                case GO_PASSAGE_FAERLINA:
                    uiNaxxDoors[DOOR_PASSAGE_FAERLINA] = pGo->GetGUID();
                    pGo->SetGoState(m_auiEncounter[BOSS_FAERLINA] == DONE ? GO_STATE_ACTIVE : GO_STATE_READY);
                    break;
                case GO_ROOM_MAEXXNA:
                    uiNaxxDoors[DOOR_ROOM_MAEXXNA] = pGo->GetGUID();
                    pGo->SetGoState((m_auiEncounter[BOSS_FAERLINA] == DONE && m_auiEncounter[BOSS_MAEXXNA] != IN_PROGRESS) ? GO_STATE_ACTIVE : GO_STATE_READY);
                    break;
                case GO_ROOM_NOTH:
                    uiNaxxDoors[DOOR_ROOM_NOTH] = pGo->GetGUID();
                    pGo->SetGoState(m_auiEncounter[BOSS_FAERLINA] != IN_PROGRESS ? GO_STATE_ACTIVE : GO_STATE_READY);
                    break;
                case GO_PASSAGE_NOTH:
                    uiNaxxDoors[DOOR_PASSAGE_NOTH] = pGo->GetGUID();
                    pGo->SetGoState(m_auiEncounter[BOSS_NOTH] == DONE ? GO_STATE_ACTIVE : GO_STATE_READY);
                    break;
                case GO_ROOM_HEIGAN:
                    uiNaxxDoors[DOOR_ROOM_HEIGAN] = pGo->GetGUID();
                    pGo->SetGoState(m_auiEncounter[BOSS_HEIGAN] != IN_PROGRESS ? GO_STATE_ACTIVE : GO_STATE_READY);
                    break;
                case GO_PASSAGE_HEIGAN:
                    uiNaxxDoors[DOOR_PASSAGE_HEIGAN] = pGo->GetGUID();
                    pGo->SetGoState(m_auiEncounter[BOSS_HEIGAN] == DONE ? GO_STATE_ACTIVE : GO_STATE_READY);
                    break;
                case GO_ROOM_LOATHEB:
                    uiNaxxDoors[DOOR_ROOM_LOATHEB] = pGo->GetGUID();
                    pGo->SetGoState((m_auiEncounter[BOSS_HEIGAN] == DONE && m_auiEncounter[BOSS_LOATHEB] != IN_PROGRESS) ? GO_STATE_ACTIVE : GO_STATE_READY);
                    break;
                case GO_ROOM_GROBBULUS:
                    uiNaxxDoors[DOOR_ROOM_GROBBULUS] = pGo->GetGUID();
                    pGo->SetGoState((m_auiEncounter[BOSS_PATCHWERK] == DONE && m_auiEncounter[BOSS_GROBBULUS] != IN_PROGRESS) ? GO_STATE_ACTIVE : GO_STATE_READY);
                    break;
                case GO_PASSAGE_GLUTH:
                    uiNaxxDoors[DOOR_PASSAGE_GLUTH] = pGo->GetGUID();
                    pGo->SetGoState(m_auiEncounter[BOSS_GLUTH] == DONE ? GO_STATE_ACTIVE : GO_STATE_READY);
                    break;
                case GO_ROOM_THADDIUS:
                    uiNaxxDoors[DOOR_ROOM_THADDIUS] = pGo->GetGUID();
                    pGo->SetGoState((m_auiEncounter[BOSS_GLUTH] == DONE && m_auiEncounter[BOSS_THADDIUS] != IN_PROGRESS) ? GO_STATE_ACTIVE : GO_STATE_READY);
                    break;
                case GO_ROOM_GOTHIK:
                    uiNaxxDoors[DOOR_ROOM_GOTHIK] = pGo->GetGUID();
                    pGo->SetGoState((m_auiEncounter[BOSS_RAZUVIOUS] == DONE && m_auiEncounter[BOSS_GOTHIK] != IN_PROGRESS) ? GO_STATE_ACTIVE : GO_STATE_READY);
                    break;
                case GO_PASSAGE_GOTHIK:
                    uiNaxxDoors[DOOR_PASSAGE_GOTHIK] = pGo->GetGUID();
                    pGo->SetGoState(m_auiEncounter[BOSS_GOTHIK] == DONE ? GO_STATE_ACTIVE : GO_STATE_READY);
                    break;
                case GO_ROOM_HORSEMEN:
                    uiNaxxDoors[DOOR_ROOM_HORSEMEN] = pGo->GetGUID();
                    pGo->SetGoState((m_auiEncounter[BOSS_GOTHIK] == DONE && m_auiEncounter[BOSS_HORSEMEN] != IN_PROGRESS) ? GO_STATE_ACTIVE : GO_STATE_READY);
                    break;
                case GO_PASSAGE_SAPPHIRON:
                    uiNaxxDoors[DOOR_PASSAGE_SAPPHIRON] = pGo->GetGUID();
                    pGo->SetGoState(m_auiEncounter[BOSS_SAPPHIRON] == DONE ? GO_STATE_ACTIVE : GO_STATE_READY);
                    break;
                case GO_ROOM_KELTHUZAD:
                    uiNaxxDoors[DOOR_ROOM_KELTHUZAD] = pGo->GetGUID();
                    pGo->SetGoState(m_auiEncounter[BOSS_KELTHUZAD] != IN_PROGRESS ? GO_STATE_ACTIVE : GO_STATE_READY);
                    break;
            }
            //AddDoor(pGo, add);
        }

        void SetData(uint32 id, uint32 data)
        {
            switch(id)
            {                
                case DATA_HEIGAN_ERUPT:
                    HeiganErupt(data);
                    break;
                case DATA_GOTHIK_GATE:
                    if (GameObject *pGothikGate = instance->GetGameObject(GothikGateGUID))
                        pGothikGate->SetGoState(GOState(data));
                    gothikDoorState = GOState(data);
                    break;
                case DATA_HORSEMEN0:
                case DATA_HORSEMEN1:
                case DATA_HORSEMEN2:
                case DATA_HORSEMEN3:
                    if (data == NOT_STARTED)
                    {
                        minHorsemenDiedTime = 0;
                        maxHorsemenDiedTime = 0;
                    }
                    else if (data == DONE)
                    {
                        time_t now = time(NULL);

                        if (minHorsemenDiedTime == 0)
                            minHorsemenDiedTime = now;

                        maxHorsemenDiedTime = now;
                    }
                    break;
            }
        }

        uint64 GetData64(uint32 id)
        {
            switch(id)
            {
            case DATA_FAERLINA:
                return uiFaerlina;
            case DATA_THANE:
                return uiThane;
            case DATA_LADY:
                return uiLady;
            case DATA_BARON:
                return uiBaron;
            case DATA_SIR:
                return uiSir;
            case DATA_THADDIUS:
                return uiThaddius;
            case DATA_FEUGEN:
                return uiFeugen;
            case DATA_STALAGG:
                return uiStalagg;
            case DATA_KELTHUZAD:
                return uiKelthuzad;
            case DATA_KELTHUZAD_PORTAL01:
                return uiPortals[0];
            case DATA_KELTHUZAD_PORTAL02:
                return uiPortals[1];
            case DATA_KELTHUZAD_PORTAL03:
                return uiPortals[2];
            case DATA_KELTHUZAD_PORTAL04:
                return uiPortals[3];
            case DATA_KELTHUZAD_TRIGGER:
                return uiKelthuzadTrigger;
            case DATA_GO_ROOM_HEIGAN:
                return uiNaxxDoors[DOOR_ROOM_HEIGAN];
            case DATA_GO_PASSAGE_HEIGAN:
                return uiNaxxDoors[DOOR_PASSAGE_HEIGAN];
            case DATA_KELTHUZAD_2:
                return uiKelthuzade;
            }
            return 0;
        }

        uint32 GetData(uint32 id)
        {
            if(id == DATA_PLAYER_DEATHS)
            {
                if(InstanceFinished())
                    return m_PlayerDeathCount;
                else return 1;
            }
            if(id == DATA_HEIGAN_PLAYER_DEATHS)
                return m_HeiganPlayerDeathCount;

            return GetNaxxBossState(id);
        }

        bool SetBossState(uint32 id, EncounterState state)
        {
            //if (!InstanceScript::SetBossState(id, state))
            //    return false;

            //if(m_auiEncounter[id] != state)
            //{
            UpdateNaxxMinionState(id,state);
            UpdateNaxxDoorState(id,state);
            //}

            if(m_auiEncounter[id] != DONE)
                m_auiEncounter[id] = state;

            if (id == BOSS_HEIGAN && state == NOT_STARTED)
                m_HeiganPlayerDeathCount = 0;

            if (id == BOSS_HORSEMEN && state == DONE)
            {
                if (GameObject *pHorsemenChest = instance->GetGameObject(HorsemenChestGUID))
				{
                    pHorsemenChest->SetRespawnTime(pHorsemenChest->GetRespawnDelay());
				}
				DoTaunt();
				if (GameObject *pMiliPortal = instance->GetGameObject(MiliPortalGUID))
					pMiliPortal->SetPhaseMask(2,true);
            }
            if(state == DONE)
                SaveToDB();
            return true;
        }

        EncounterState GetNaxxBossState(uint32 id)
        {
            if(id < MAX_BOSS_NUMBER)
                return ((EncounterState)m_auiEncounter[id]);
            else return NOT_STARTED;
        }

        void UpdateNaxxDoorState(uint32 id, EncounterState state)
        {
            switch(id)
            {
            case BOSS_ANUBREKHAN:
                HandleGameObject(uiNaxxDoors[DOOR_ROOM_ANUBREKHAN], state != IN_PROGRESS);
                HandleGameObject(uiNaxxDoors[DOOR_PASSAGE_ANUBREKHAN], state == DONE);
                break;
            case BOSS_FAERLINA:
                HandleGameObject(uiNaxxDoors[DOOR_PASSAGE_FAERLINA],state == DONE);
                HandleGameObject(uiNaxxDoors[DOOR_ROOM_MAEXXNA],state == DONE);
                break;
            case BOSS_MAEXXNA:
                HandleGameObject(uiNaxxDoors[DOOR_ROOM_MAEXXNA],state != IN_PROGRESS);
            if (state == DONE)
            {
                DoRespawnGameObject(AracPortalGUID, 30*MINUTE);
                DoTaunt();
            }
                break;
            case BOSS_NOTH:
                HandleGameObject(uiNaxxDoors[DOOR_ROOM_NOTH],state != IN_PROGRESS);
                HandleGameObject(uiNaxxDoors[DOOR_PASSAGE_NOTH],state == DONE);
                break;
            case BOSS_HEIGAN:
                HandleGameObject(uiNaxxDoors[DOOR_ROOM_HEIGAN], state != IN_PROGRESS);
                HandleGameObject(uiNaxxDoors[DOOR_PASSAGE_HEIGAN], state == DONE);
                HandleGameObject(uiNaxxDoors[DOOR_ROOM_LOATHEB], state == DONE);
                break;
            case BOSS_LOATHEB:
                HandleGameObject(uiNaxxDoors[DOOR_ROOM_LOATHEB], state != IN_PROGRESS);
            if (state == DONE)
            {
                DoTaunt();
                DoRespawnGameObject(PlagPortalGUID, 30*MINUTE);
            }
                break;
            case BOSS_PATCHWERK:
                HandleGameObject(uiNaxxDoors[DOOR_ROOM_GROBBULUS], state == DONE);
                break;
            case BOSS_GROBBULUS:
                HandleGameObject(uiNaxxDoors[DOOR_ROOM_GROBBULUS], state != IN_PROGRESS);
                break;
            case BOSS_GLUTH:
                HandleGameObject(uiNaxxDoors[DOOR_PASSAGE_GLUTH], state == DONE);
                HandleGameObject(uiNaxxDoors[DOOR_ROOM_THADDIUS], state == DONE);
                break;
            case BOSS_THADDIUS:
                HandleGameObject(uiNaxxDoors[DOOR_ROOM_THADDIUS], state != IN_PROGRESS);
            if (state == DONE)
            {
                DoTaunt();
                DoRespawnGameObject(ConsPortalGUID, 30*MINUTE);
            }
                break;
            case BOSS_RAZUVIOUS:
                HandleGameObject(uiNaxxDoors[DOOR_ROOM_GOTHIK], state == DONE);
                break;
            case BOSS_GOTHIK:
                HandleGameObject(uiNaxxDoors[DOOR_ROOM_GOTHIK], state != IN_PROGRESS);
                HandleGameObject(uiNaxxDoors[DOOR_PASSAGE_GOTHIK], state == DONE);
                HandleGameObject(uiNaxxDoors[DOOR_ROOM_HORSEMEN], state == DONE);
                break;
            case BOSS_HORSEMEN:
                HandleGameObject(uiNaxxDoors[DOOR_ROOM_HORSEMEN], state != IN_PROGRESS);
                break;
            case BOSS_SAPPHIRON:
                HandleGameObject(uiNaxxDoors[DOOR_PASSAGE_SAPPHIRON],state == DONE);
                if (state == DONE)
                {
			     Step = 1;
			     StepTimer = 100;
                 Event();
                }
                break;
            case BOSS_KELTHUZAD:
                HandleGameObject(uiNaxxDoors[DOOR_ROOM_KELTHUZAD],state != IN_PROGRESS);
                break;
            }
        }

        bool InstanceFinished()
        {
            for(int i = 0; i < MAX_BOSS_NUMBER; ++i)
                if(m_auiEncounter[i] != DONE)
                    return false;
            return true;
        }

        void UpdateNaxxMinionState(uint32 id, EncounterState state)
        {
            switch(id)
            {
            case BOSS_FAERLINA:
                for (std::set<uint64>::const_iterator i =  FaerlinaMinion.begin(); i != FaerlinaMinion.end(); ++i)
                    if(Creature* minion = instance->GetCreature((*i)))
                        UpdateMinionState(minion,state);
                break;
            case BOSS_RAZUVIOUS:
                for (std::set<uint64>::const_iterator i =  RazuviousMinion.begin(); i != RazuviousMinion.end(); ++i)
                    if(Creature* minion = instance->GetCreature((*i)))
                        UpdateMinionState(minion,state);
                break;
            case BOSS_HORSEMEN:
                for (std::set<uint64>::const_iterator i =  Horsemen.begin(); i != Horsemen.end(); ++i)
                    if(Creature* minion = instance->GetCreature((*i)))
                        UpdateMinionState(minion,state);
                break;
            }
        }

        void HeiganErupt(uint32 section)
        {
            for (uint32 i = 0; i < 4; ++i)
            {
                if (i == section)
                    continue;

                for (std::set<uint64>::const_iterator itr = HeiganEruptionGUID[i].begin(); itr != HeiganEruptionGUID[i].end(); ++itr)
                {
                    if (GameObject *pHeiganEruption = instance->GetGameObject(*itr))
                    {
                        pHeiganEruption->SendCustomAnim(pHeiganEruption->GetGoAnimProgress());
                        pHeiganEruption->CastSpell(NULL, SPELL_ERUPTION);
                    }
                }
            }
        }

        bool CheckAchievementCriteriaMeet(uint32 criteria_id, Player const* /*source*/, Unit const* /*target = NULL*/, uint32 /*miscvalue1 = 0*/)
        {
            switch(criteria_id)
            {
                case 7600:  // Criteria for achievement 2176: And They Would All Go Down Together 15sec of each other 10-man
                    if (Difficulty(instance->GetSpawnMode()) == RAID_DIFFICULTY_10MAN_NORMAL && (maxHorsemenDiedTime - minHorsemenDiedTime) < 15)
                        return true;
                    return false;
                case 7601:  // Criteria for achievement 2177: And They Would All Go Down Together 15sec of each other 25-man
                    if (Difficulty(instance->GetSpawnMode()) == RAID_DIFFICULTY_25MAN_NORMAL && (maxHorsemenDiedTime - minHorsemenDiedTime) < 15)
                        return true;
                    return false;
                //case 13233: // Criteria for achievement 2186: The Immortal (25-man)
                //    if (Difficulty(instance->GetSpawnMode()) == RAID_DIFFICULTY_25MAN_NORMAL && InstanceFinished() && m_PlayerDeathCount == 0)
                //        return true;
                //    return false;
                //case 13237: // Criteria for achievement 2187: The Undying (10-man)
                //    if (Difficulty(instance->GetSpawnMode()) == RAID_DIFFICULTY_10MAN_NORMAL && InstanceFinished() && m_PlayerDeathCount == 0)
                //        return true;
                //    return false;
            }
            return false;
        }

        std::string GetSaveData()
        {
            std::ostringstream saveStream;
            saveStream << "N X ";
            for(int i = 0; i < MAX_BOSS_NUMBER; ++i)
                saveStream << m_auiEncounter[i] << " ";

            saveStream << m_PlayerDeathCount;
            return saveStream.str();
        }

        void Load(const char * data)
        {
            std::istringstream loadStream(data);
            char dataHead1, dataHead2;
            loadStream >> dataHead1 >> dataHead2;
            std::string newdata = loadStream.str();

            uint32 buff;
            if(dataHead1 == 'N' && dataHead2 == 'X')
            {
                for(int i = 0; i < MAX_BOSS_NUMBER; ++i)
                {
                    loadStream >> buff;
                    m_auiEncounter[i]= buff;
                }
                //std::istringstream loadStream(LoadBossState(data));

                //loadStream >> buff;
                //gothikDoorState = GOState(buff);
                loadStream >> m_PlayerDeathCount;
            }
        }

void DoTaunt()
{
    if (m_auiEncounter[BOSS_KELTHUZAD] == DONE)
       return;
    Creature* pKelThuzade = instance->GetCreature(uiKelthuzade);

    if (pKelThuzade && pKelThuzade->isAlive())
    {
        uint8 uiWingsCleared = 0;

        if (m_auiEncounter[BOSS_HORSEMEN] == DONE)
            ++uiWingsCleared;

        if (m_auiEncounter[BOSS_THADDIUS] == DONE)
            ++uiWingsCleared;

        if (m_auiEncounter[BOSS_LOATHEB]  == DONE)
            ++uiWingsCleared;

        if (m_auiEncounter[BOSS_MAEXXNA]  == DONE)
            ++uiWingsCleared;

        switch(uiWingsCleared)
        {
            case 1: DoScriptText(SAY_KELTHUZAD_TAUNT1, pKelThuzade); break;
            case 2: DoScriptText(SAY_KELTHUZAD_TAUNT2, pKelThuzade); break;
            case 3: DoScriptText(SAY_KELTHUZAD_TAUNT3, pKelThuzade); break;
            case 4: DoScriptText(SAY_KELTHUZAD_TAUNT4, pKelThuzade); break;
        }
    }
}

        void Event()
        {
			if(!Step)
			return;
    if (m_auiEncounter[BOSS_KELTHUZAD] == DONE)
       return;
            Creature* pKelThuzade = instance->GetCreature(uiKelthuzade);
            Creature* pLichKing = instance->GetCreature(uiLichKing);
            switch(Step)
            {
			case 1:
				   JumpNextStep(10000);
			    break;
                case 2:
                        DoScriptText(SAY_SAPP_DIALOG1, pKelThuzade);
                        JumpNextStep(6000);
                    break;
			case 3:
                        DoScriptText(SAY_SAPP_DIALOG2_LICH, pLichKing);
                        JumpNextStep(16000);
                    break;
			case 4:
                        DoScriptText(SAY_SAPP_DIALOG3, pKelThuzade);
                        JumpNextStep(9000);
                    break;

                case 5:
                        DoScriptText(SAY_SAPP_DIALOG4_LICH, pLichKing);
                        JumpNextStep(7000);
                    break;
                case 6:
                        DoScriptText(SAY_SAPP_DIALOG5, pKelThuzade);
                        JumpNextStep(3000);
                    break;
            }
        }

        void JumpNextStep(uint32 Time)
        {
            StepTimer = Time;
            Step++;
        }

        void Update (uint32 diff)
        {
			if(!instance)
                return;

            if(StepTimer < diff)
                Event();
            else StepTimer -= diff;

            return;
            //Water checks
            //if (SlimeCheckTimer <= diff)
            //{
            //    Map::PlayerList const &PlayerList = instance->GetPlayers();
            //    if (PlayerList.isEmpty())
            //        return;

            //    for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
            //    {
            //        if (Player* pPlayer = i->getSource())
            //        {
            //            if (pPlayer->isAlive() && /*i->getSource()->GetPositionZ() <= -21.434931f*/pPlayer->IsInWater())
            //            {
            //                if (!pPlayer->HasAura(SPELL_SLIME))
            //                {
            //                    pPlayer->CastSpell(pPlayer, SPELL_SLIME,true);
            //                }
            //            }
            //            if (!pPlayer->IsInWater())
            //                pPlayer->RemoveAurasDueToSpell(SPELL_SLIME);
            //        }
            //    }
            //    SlimeCheckTimer = 1000;//remove stress from core
            //} else SlimeCheckTimer -= diff;
        }
    };

};

class AreaTrigger_at_naxxramas_frostwyrm_wing : public AreaTriggerScript
{
    public:

        AreaTrigger_at_naxxramas_frostwyrm_wing()
            : AreaTriggerScript("at_naxxramas_frostwyrm_wing")
        {
        }

        bool OnTrigger(Player* player, AreaTriggerEntry const* trigger)
        {
            if (player->isGameMaster())
                return false;

            InstanceScript *data = player->GetInstanceScript();
            if (data)
                for (uint32 i = BOSS_ANUBREKHAN; i < BOSS_SAPPHIRON; ++i)
                    if (data->GetData(i) != DONE)
                        return true;

            return false;
        }
};

class mr_bigglesworth_npc : public CreatureScript
{
    public:
        mr_bigglesworth_npc(): CreatureScript("mr_bigglesworth_npc") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mr_bigglesworth_npcAI (creature);
    }

    struct mr_bigglesworth_npcAI : public ScriptedAI
    {
        mr_bigglesworth_npcAI(Creature *c) : ScriptedAI(c)
        {
            instance = c->GetInstanceScript();
        }

        InstanceScript* instance;
        uint32 m_auiEncounter[MAX_BOSS_NUMBER];

        void JustDied(Unit* killer)
        {
    if (m_auiEncounter[BOSS_KELTHUZAD] == DONE)
       return;
                if (Creature* KelThuzad = Unit::GetCreature(*me, instance ? instance->GetData64(DATA_KELTHUZAD_2) : 0))
				{
                           KelThuzad->MonsterYellToZone(SAY_CAT_DIED, LANG_UNIVERSAL, 0);
                           DoPlaySoundToSet(me, SOUND_KT);
				}
        }
    };
};

class GOHello_go_naxxramas_portal_1 : public GameObjectScript
{
    public:
        GOHello_go_naxxramas_portal_1()
            : GameObjectScript("go_naxxramas_portal_1")
        {}

        bool OnGossipHello(Player* player, GameObject* /*go*/)
        {
            player->TeleportTo(533, 2991.641602f, -3448.677490f, 302.143555f, 3.918837f);
            return false;
        }
};

class GOHello_go_naxxramas_portal_2 : public GameObjectScript
{
    public:
        GOHello_go_naxxramas_portal_2()
            : GameObjectScript("go_naxxramas_portal_2")
        {}

        bool OnGossipHello(Player* player, GameObject* /*go*/)
        {
            player->TeleportTo(533, 2991.436279f, -3419.952881f, 302.091003f, 2.357990f);
            return false;
        }
};

class GOHello_go_naxxramas_portal_3 : public GameObjectScript
{
    public:
        GOHello_go_naxxramas_portal_3()
            : GameObjectScript("go_naxxramas_portal_3")
        {}

        bool OnGossipHello(Player* player, GameObject* /*go*/)
        {
            player->TeleportTo(533, 3019.996094f, -3420.144531f, 302.172424f, 0.838341f);
            return false;
        }
};

class GOHello_go_naxxramas_portal_4 : public GameObjectScript
{
    public:
        GOHello_go_naxxramas_portal_4()
            : GameObjectScript("go_naxxramas_portal_4")
        {}

        bool OnGossipHello(Player* player, GameObject* /*go*/)
        {
            player->TeleportTo(533, 3020.147949f, -3448.787109f, 302.068481f, 5.503996f);
            return false;
        }
};

void AddSC_instance_naxxramas()
{
    new instance_naxxramas();
    new AreaTrigger_at_naxxramas_frostwyrm_wing();
    new GOHello_go_naxxramas_portal_1();
    new GOHello_go_naxxramas_portal_2();
    new GOHello_go_naxxramas_portal_3();
    new GOHello_go_naxxramas_portal_4();
    new mr_bigglesworth_npc();
}
