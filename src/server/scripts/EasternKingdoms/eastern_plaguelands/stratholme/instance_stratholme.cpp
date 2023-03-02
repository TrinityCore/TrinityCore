#include "scriptPCH.h"
#include "stratholme.h"

enum
{
    GO_SERVICE_ENTRANCE         = 175368,
    GO_GAUNTLET_GATE1           = 175357,
    GO_SLAUGHTER_SQUARE_GATE    = 175358,
    GO_ZIGGURAT1                = 175380,                   // baroness
    GO_ZIGGURAT2                = 175379,                   // nerub'enkan
    GO_ZIGGURAT3                = 175381,                   // maleki
    GO_ZIGGURAT4                = 175405,                   // rammstein
    GO_ZIGGURAT5                = 175796,                   // baron
    GO_PORT_GAUNTLET            = 175374,                   // port from gauntlet to slaugther
    GO_PORT_SLAUGTHER           = 175373,                   // port at slaugther
    GO_PORT_ELDERS              = 175377,                   // port at elders square
    GO_PORT_TRAP_GATE_1         = 175351,                   // Portcullis used in the gate traps (rats trap)
    GO_PORT_TRAP_GATE_2         = 175350,                   // Scarlet side
    GO_PORT_TRAP_GATE_3         = 175355,                   // Undead side
    GO_PORT_TRAP_GATE_4         = 175354,
    GO_CAGE_YSIDA               = 181071,                   // in 2 parts, the base is: 181072

    NPC_CRYSTAL                 = 10415,                    // three ziggurat crystals
    NPC_BARON                   = 10440,
    NPC_YSIDA_TRIGGER           = 16100,
    NPC_TIMMY                   = 10808,
    NPC_DATHROHAN               = 10812,
    NPC_MAGISTRATE              = 10435,

    NPC_RAMSTEIN                = 10439,
    NPC_ABOM_BILE               = 10416,
    NPC_ABOM_VENOM              = 10417,
    NPC_BLACK_GUARD             = 10394,
    NPC_YSIDA                   = 16031,
    NPC_PLAGUED_RAT             = 10441,
    NPC_PLAGUED_INSECT          = 10461,
    NPC_PLAGUED_MAGGOT          = 10536,
    NPC_MINDLESS_UNDEAD         = 11030,
    NPC_VENGEFUL_PHANTOM        = 10387,
    NPC_THE_UNFORGIVEN          = 10516,

    RIVENDARE_YELL_45MIN        = -1000020,
    RIVENDARE_YELL_10MIN        = -1000021,
    RIVENDARE_YELL_5MIN         = -1000022,
    YSIDA_YELL_5MIN             = -1000023,
    RIVENDARE_YELL_FAILED       = -1000024,
    RIVENDARE_YELL_RAMMSTEIN    = -1000025,
    RAMMSTEIN_YELL_SPAWN        = -1000026,
    BLACKGUARD_YELL_SPAWN       = -1000027,
    RIVENDARE_YELL_READY        = -1000028,
    YSIDA_YELL_FAILED           = -1000029,
    YSIDA_SAY_REWARD            = -1000030,

    SPELL_YSIDA_FREED           = 27773
};

static Position const aGateTrap[] =                    // Positions of the two Gate Traps
{
    {3612.29f, -3335.39f, 124.077f, 3.14159f},              // Scarlet side
    {3919.88f, -3547.34f, 134.269f, 2.94961f}               // Undead side
};

static uint32 const aPlaguedCritters[] =
{
    NPC_PLAGUED_RAT, NPC_PLAGUED_MAGGOT, NPC_PLAGUED_INSECT
};

static Position const unforgivenTriggerSpot(3712.607f, -3429.338f, 131.001f, 0.0f);

struct instance_stratholme : public ScriptedInstance
{
    instance_stratholme(Map* pMap) : ScriptedInstance(pMap)
    {
        Initialize();
    };

    uint32 m_auiEncounter[STRAT_MAX_ENCOUNTER];

    uint32 m_uiGateTrapTimers[2][3];
    bool IsSilverHandDead[5];

    uint8 m_phaseBaron;
    uint32 m_uiBaronRun_Timer;
    uint32 m_uiSlaugtherSquare_Timer;
    uint32 m_uiSlaugtherAboMob_Timer;

    uint64 m_uiServiceEntranceGUID;
    uint64 m_uiGauntletGate1GUID;
    uint64 m_uiSlaughterSquareGateGUID;
    uint64 m_uiZiggurat1GUID;
    uint64 m_uiZiggurat2GUID;
    uint64 m_uiZiggurat3GUID;
    uint64 m_uiZiggurat4GUID;
    uint64 m_uiZiggurat5GUID;
    uint64 m_uiPortGauntletGUID;
    uint64 m_uiPortSlaugtherGUID;
    uint64 m_uiPortElderGUID;
    uint64 m_cageYsidaGUID;
    uint64 m_ratTrapGateGUID[4];

    uint64 m_uiBaronGUID;
    uint64 m_uiTimmyGUID;
    uint64 m_uiYsidaTriggerGUID;
    uint64 m_uiYsidaGUID;
    uint64 m_uiRamsteinGUID;
    uint64 m_uiDathrohanGUID;
    std::set<uint64> crystalsGUID;
    std::set<uint64> abomnationGUID;
    std::list<uint64> slaugtherAboGUID;
    std::set<uint64> npc_placeEcarlateGUID;
    bool m_summoningRammstein;

    uint8 m_uiBlackguardCount;
    uint32 m_uiYsidaReward_Timer;
    uint32 m_uiPostboxesUsed;

    void Initialize() override
    {
        memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));
        memset(&m_ratTrapGateGUID, 0, sizeof(m_ratTrapGateGUID));

        for (auto& trapTimer : m_uiGateTrapTimers)
            for (uint8 j = 0; j < 3; ++j)
                trapTimer[j] = 0;

        for (bool & i : IsSilverHandDead)
            i = false;

        m_phaseBaron = 0;
        m_uiBaronRun_Timer = 0;
        m_uiSlaugtherSquare_Timer = 0;
        m_uiSlaugtherAboMob_Timer = 0;

        m_uiServiceEntranceGUID = 0;
        m_uiGauntletGate1GUID = 0;
        m_uiSlaughterSquareGateGUID = 0;
        m_uiZiggurat1GUID = 0;
        m_uiZiggurat2GUID = 0;
        m_uiZiggurat3GUID = 0;
        m_uiZiggurat4GUID = 0;
        m_uiZiggurat5GUID = 0;
        m_uiPortGauntletGUID = 0;
        m_uiPortSlaugtherGUID = 0;
        m_uiPortElderGUID = 0;
        m_cageYsidaGUID = 0;

        m_uiBaronGUID = 0;
        m_uiYsidaTriggerGUID = 0;
        m_uiYsidaGUID = 0;
        m_uiRamsteinGUID = 0;
        m_uiDathrohanGUID = 0;

        crystalsGUID.clear();
        abomnationGUID.clear();
        slaugtherAboGUID.clear();
        npc_placeEcarlateGUID.clear();

        m_summoningRammstein = false;

        m_uiBlackguardCount = 5;
        m_uiYsidaReward_Timer = 0;
        m_uiPostboxesUsed = 0;
    }

    bool IsEncounterInProgress() const override
    {
        for (uint32 i : m_auiEncounter)
            if (i == IN_PROGRESS)
                return true;
        return false;
    }

    bool StartSlaugtherSquare()
    {
        uint32 uiCount = crystalsGUID.size();

        for (const auto i : crystalsGUID)
        {
            if (Creature* pCristal = instance->GetCreature(i))
            {
                if (!pCristal->IsAlive())
                    --uiCount;
            }
            else
                --uiCount;
        }

        if (!uiCount)
        {
            UpdateGoState(m_uiPortGauntletGUID, GO_STATE_ACTIVE, false);
            UpdateGoState(m_uiPortSlaugtherGUID, GO_STATE_ACTIVE, false);
            SetData(TYPE_CRISTAL_ALL_DIE, DONE);
            return true;
        }
        else
        {
            sLog.outDebug("Instance Stratholme: Cannot open slaugther square yet.");
            return false;
        }
    }

    //if withRestoreTime true, then newState will be ignored and GO should be restored to original state after 10 seconds
    void UpdateGoState(uint64 goGuid, uint32 newState, bool withRestoreTime)
    {
        if (!goGuid)
            return;

        if (GameObject* pGo = instance->GetGameObject(goGuid))
        {
            if (withRestoreTime)
                pGo->UseDoorOrButton(10);
            else
                pGo->SetGoState(GOState(newState));
        }
    }

    void OnCreatureCreate(Creature* pCreature) override
    {
        switch (pCreature->GetEntry())
        {
            case NPC_BARON:
                m_uiBaronGUID = pCreature->GetGUID();
                if (GetData(TYPE_RAMSTEIN) != DONE)
                    pCreature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                break;
            case NPC_YSIDA_TRIGGER:
                m_uiYsidaTriggerGUID = pCreature->GetGUID();
                break;
            case NPC_YSIDA:
                m_uiYsidaGUID = pCreature->GetGUID();
                break;
            case NPC_CRYSTAL:
                crystalsGUID.insert(pCreature->GetGUID());
                break;
            case NPC_ABOM_BILE:
            case NPC_ABOM_VENOM:
                abomnationGUID.insert(pCreature->GetGUID());
                slaugtherAboGUID.push_back(pCreature->GetGUID());
                break;
            case NPC_RAMSTEIN:
                m_uiRamsteinGUID = pCreature->GetGUID();
                break;
            case NPC_TIMMY:
                m_uiTimmyGUID = pCreature->GetGUID();
                break;
            case NPC_DATHROHAN:
                m_uiDathrohanGUID = pCreature->GetGUID();
                break;
            case NPC_MAGISTRATE:
                pCreature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                break;
        }

        // on add tous les pnj (le tri sera fait chaque uptade) sinon on a un probleme de coodon�e (il nous donne x, y et z = 0)
        npc_placeEcarlateGUID.insert(pCreature->GetGUID());
    }

    void OnGameObjectCreate(GameObject* pGo) override
    {
        switch (pGo->GetEntry())
        {
            case GO_SERVICE_ENTRANCE:
                m_uiServiceEntranceGUID = pGo->GetGUID();
                break;
            case GO_GAUNTLET_GATE1:
                //weird, but unless flag is set, client will not respond as expected. DB bug?
                pGo->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_LOCKED);
                m_uiGauntletGate1GUID = pGo->GetGUID();
                break;
            case GO_SLAUGHTER_SQUARE_GATE:
                m_uiSlaughterSquareGateGUID = pGo->GetGUID();
                break;
            case GO_ZIGGURAT1:
                m_uiZiggurat1GUID = pGo->GetGUID();
                if (GetData(TYPE_NERUB) == DONE)
                    pGo->UseDoorOrButton();
                break;
            case GO_ZIGGURAT2:
                m_uiZiggurat2GUID = pGo->GetGUID();
                if (GetData(TYPE_NERUB) == DONE)
                    pGo->UseDoorOrButton();
                break;
            case GO_ZIGGURAT3:
                m_uiZiggurat3GUID = pGo->GetGUID();
                if (GetData(TYPE_PALLID) == DONE)
                    pGo->UseDoorOrButton();
                break;
            case GO_ZIGGURAT4:
                if (GetData(TYPE_RAMSTEIN) == DONE)
                    pGo->UseDoorOrButton();
                m_uiZiggurat4GUID = pGo->GetGUID();
                break;
            case GO_ZIGGURAT5:
                if (GetData(TYPE_RAMSTEIN) == DONE)
                    pGo->UseDoorOrButton();
                m_uiZiggurat5GUID = pGo->GetGUID();
                break;
            case GO_PORT_GAUNTLET:
                m_uiPortGauntletGUID = pGo->GetGUID();
                if (GetData(TYPE_CRISTAL_ALL_DIE) == DONE)
                    pGo->UseDoorOrButton();
                break;
            case GO_PORT_SLAUGTHER:
                m_uiPortSlaugtherGUID = pGo->GetGUID();
                if (GetData(TYPE_CRISTAL_ALL_DIE) == DONE)
                    pGo->UseDoorOrButton();
                break;
            case GO_PORT_ELDERS:
                m_uiPortElderGUID = pGo->GetGUID();
                break;
            case GO_PORT_TRAP_GATE_1:
                m_ratTrapGateGUID[0] = pGo->GetGUID();
                break;
            case GO_PORT_TRAP_GATE_2:
                m_ratTrapGateGUID[1] = pGo->GetGUID();
                break;
            case GO_PORT_TRAP_GATE_3:
                m_ratTrapGateGUID[2] = pGo->GetGUID();
                break;
            case GO_PORT_TRAP_GATE_4:
                m_ratTrapGateGUID[3] = pGo->GetGUID();
                break;
            case GO_CAGE_YSIDA:
                m_cageYsidaGUID = pGo->GetGUID();
                break;
        }
    }

    void OnCreatureDeath(Creature *who) override
    {
        switch (who->GetEntry())
        {
            case NPC_BLACK_GUARD:
                m_uiBlackguardCount--;
                if (!m_uiBlackguardCount)
                {
                    if (Creature* pBaron = instance->GetCreature(m_uiBaronGUID))
                        DoScriptText(RIVENDARE_YELL_READY, pBaron);
                }
                break;
        }
    }

    uint32 GetData(uint32 uiType) override
    {
        switch (uiType)
        {
            case TYPE_SH_QUEST:
                if (IsSilverHandDead[0] && IsSilverHandDead[1] && IsSilverHandDead[2] && IsSilverHandDead[3] && IsSilverHandDead[4])
                    return 1;
                return 0;
        }
        if (uiType < STRAT_MAX_ENCOUNTER)
            return m_auiEncounter[uiType];
        return 0;
    }

    uint64 GetData64(uint32 uiData) override
    {
        switch (uiData)
        {
            case DATA_BARON:
                return m_uiBaronGUID;
            case DATA_YSIDA_TRIGGER:
                return m_uiYsidaTriggerGUID;
            case NPC_DATHROHAN:
                return m_uiDathrohanGUID;
        }
        return 0;
    }

    void SetData(uint32 uiType, uint32 uiData) override
    {
        switch (uiType)
        {
            case TYPE_BARON_RUN:
            {
                switch (uiData)
                {
                    case IN_PROGRESS:
                        if (m_auiEncounter[TYPE_BARON_RUN] == IN_PROGRESS || m_auiEncounter[TYPE_BARON_RUN] == FAIL)
                            break;
                        m_uiBaronRun_Timer = 45*MINUTE*IN_MILLISECONDS;
                        m_phaseBaron = 0;
                        sLog.outDebug("Instance Stratholme: Baron run in progress.");
                        if (Creature* pYsidaT = instance->GetCreature(m_uiYsidaTriggerGUID))
                            pYsidaT->SummonCreature(NPC_YSIDA,
                                                    4044.163f, -3334.2f, 115.0596f, 4.2f,
                                                    TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 1*HOUR*IN_MILLISECONDS);
                        break;
                    case FAIL:
                        //may add code to remove aura from players, but in theory the time should be up already and removed.
                        break;
                    case DONE:
                        if (instance->GetGameObject(m_cageYsidaGUID))
                            instance->GetGameObject(m_cageYsidaGUID)->SetGoState(GO_STATE_ACTIVE);
                        if (Creature* pYsida = instance->GetCreature(m_uiYsidaGUID))
                        {
                            pYsida->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                            pYsida->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                            pYsida->SetWalk(true);
                            pYsida->GetMotionMaster()->MovePoint(1, 4041.2f, -3339.0f, 115.1f, MOVE_PATHFINDING);
                        }
                        m_uiYsidaReward_Timer = 5000;
                        m_uiBaronRun_Timer = 0;
                        break;
                }
                m_auiEncounter[TYPE_BARON_RUN] = uiData;
                break;
            }
            case TYPE_BARONESS:
            {
                m_auiEncounter[TYPE_BARONESS] = uiData;
                if (uiData == DONE)
                    UpdateGoState(m_uiZiggurat1GUID, GO_STATE_ACTIVE, false);
                break;
            }
            case TYPE_NERUB:
            {
                m_auiEncounter[TYPE_NERUB] = uiData;
                if (uiData == DONE)
                    UpdateGoState(m_uiZiggurat2GUID, GO_STATE_ACTIVE, false);
                break;
            }
            case TYPE_PALLID:
            {
                m_auiEncounter[TYPE_PALLID] = uiData;
                if (uiData == DONE)
                    UpdateGoState(m_uiZiggurat3GUID, GO_STATE_ACTIVE, false);
                break;
            }
            case TYPE_RAMSTEIN:
            {
                if (uiData == SPECIAL) // on mob Aggro OK
                {
                    if (GameObject* pGob = instance->GetGameObject(m_uiPortGauntletGUID))
                        if (pGob->GetGoState() != GO_STATE_READY) // Si pas ferm�e
                            UpdateGoState(m_uiPortGauntletGUID, GO_STATE_READY, false);
                    m_uiSlaugtherAboMob_Timer = 20000;
                }
                if (uiData == IN_PROGRESS) // on mob Death // on ramstein aggro OK
                {
                    if (m_summoningRammstein)
                        return;
                    m_summoningRammstein = true; // Prevent stack overflow (SummonRammstein can lead to call SetData(TYPE_RAMSTEIN)).
                    if (m_uiRamsteinGUID)
                    {
                        if (GameObject* pGob = instance->GetGameObject(m_uiPortGauntletGUID))
                            if (pGob->GetGoState() != GO_STATE_READY) // Si pas ferm�e
                                UpdateGoState(m_uiPortGauntletGUID, GO_STATE_READY, false);
                        m_auiEncounter[TYPE_RAMSTEIN] = uiData;
                        m_summoningRammstein = false;
                        break;
                    }

                    uint32 uiCount = abomnationGUID.size();
                    for (const auto i : abomnationGUID)
                    {
                        if (Creature* pAbom = instance->GetCreature(i))
                        {
                            if (!pAbom->IsAlive())
                                --uiCount;
                        }
                    }

                    if (!uiCount)
                    {
                        if (Creature* pBaron = instance->GetCreature(m_uiBaronGUID))
                            DoScriptText(RIVENDARE_YELL_RAMMSTEIN, pBaron);
                        UpdateGoState(m_uiZiggurat4GUID, GO_STATE_ACTIVE, false);
                        m_uiSlaugtherSquare_Timer = 5000;
                        SummonRamstein();
                    }
                    else
                        sLog.outDebug("Instance Stratholme: %u Abomnation left to kill.", uiCount);
                    m_summoningRammstein = false;
                }
                if (uiData == DONE) // on ramstein death OK
                {
                    DoUseDoorOrButton(m_uiSlaughterSquareGateGUID, 91);

                    for (uint8 i = 0; i < 34; ++i)
                    {
                        if (Creature* pUndead = instance->SummonCreature(NPC_MINDLESS_UNDEAD, 3929.6f + frand(0.0f, 3.0f), -3384.3 + frand(0.0f, 3.0f), 120.0f, 4.88f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 1800000))
                        {
                            float x = 4012.0f;
                            float y = -3418.92f;
                            float z = 117.294f;
                            pUndead->GetRandomPoint(x, y, z, 10.0f, x, y, z);
                            pUndead->SetHomePosition(x, y, z, frand(0.0f, 6.0f));
                            pUndead->GetMotionMaster()->Clear();
                            pUndead->GetMotionMaster()->MoveRandom(false, 5.0f);
                            pUndead->SetWalk(false);
                            pUndead->GetMotionMaster()->MovePoint(1, 3941.29f, -3394.84f, 119.69f, MOVE_FORCE_DESTINATION | MOVE_STRAIGHT_PATH);
                        }
                    }
                    //UpdateGoState(m_uiZiggurat4GUID,GO_STATE_ACTIVE,false);
                    m_uiSlaugtherSquare_Timer = 60000;
                    sLog.outDebug("Instance Stratholme: Slaugther event will continue in 60 sec.");
                }
                if (uiData == FAIL) // on mob Evade // on ramstein evade
                {
                    if (GameObject* pGob = instance->GetGameObject(m_uiPortGauntletGUID))
                        if (pGob->GetGoState() != GO_STATE_ACTIVE) // Si pas ouverte && wipe
                            UpdateGoState(m_uiPortGauntletGUID, GO_STATE_ACTIVE, false);
                    m_uiSlaugtherAboMob_Timer = 0;
                }
                m_auiEncounter[TYPE_RAMSTEIN] = uiData;
                break;
            }
            case TYPE_BARON:
            {
                if (uiData == IN_PROGRESS)
                {
                    if (GameObject* pGob = instance->GetGameObject(m_uiZiggurat4GUID))
                        if (pGob->GetGoState() != GO_STATE_READY) // Si pas ferm�e
                            UpdateGoState(m_uiZiggurat4GUID, GO_STATE_READY, false);
                    UpdateGoState(m_uiZiggurat5GUID, GO_STATE_READY, false);
                    if (GameObject* pGob = instance->GetGameObject(m_uiPortGauntletGUID))
                        if (pGob->GetGoState() != GO_STATE_READY) // Si pas ferm�e
                            UpdateGoState(m_uiPortGauntletGUID, GO_STATE_READY, false);
                }
                if (uiData == DONE)
                {
                    if (GetData(TYPE_BARON_RUN) == IN_PROGRESS)
                    {
                        Map::PlayerList const& players = instance->GetPlayers();

                        if (!players.isEmpty())
                        {
                            std::list<uint32> baronSpells;
                            std::list<uint32>::iterator spells_itr;
                            baronSpells.push_back(SPELL_BARON_ULTIMATUM_45MIN);
                            baronSpells.push_back(SPELL_BARON_ULTIMATUM_10MIN);
                            baronSpells.push_back(SPELL_BARON_ULTIMATUM_5MIN);
                            baronSpells.push_back(SPELL_BARON_ULTIMATUM_1MIN);

                            for (const auto& itr : players)
                            {
                                if (Player* pPlayer = itr.getSource())
                                {
                                    for (spells_itr = baronSpells.begin(); spells_itr != baronSpells.end(); ++spells_itr)
                                        if (pPlayer->HasAura(*spells_itr))
                                            pPlayer->RemoveAurasDueToSpell(*spells_itr);

                                    if (pPlayer->GetQuestStatus(QUEST_DEAD_MAN_PLEA) == QUEST_STATUS_INCOMPLETE)
                                        pPlayer->AreaExploredOrEventHappens(QUEST_DEAD_MAN_PLEA);
                                }
                            }
                        }
                        SetData(TYPE_BARON_RUN, DONE);
                    }
                    if (GameObject* pGob = instance->GetGameObject(m_uiZiggurat4GUID))
                        if (pGob->GetGoState() != GO_STATE_ACTIVE) // Si pas ouverte
                            UpdateGoState(m_uiZiggurat4GUID, GO_STATE_ACTIVE, false);
                    UpdateGoState(m_uiZiggurat5GUID, GO_STATE_ACTIVE, false);
                    UpdateGoState(m_uiPortGauntletGUID, GO_STATE_ACTIVE, false);
                }
                if (uiData == FAIL)
                {
                    if (GameObject* pGob = instance->GetGameObject(m_uiZiggurat4GUID))
                        if (pGob->GetGoState() != GO_STATE_ACTIVE) // Si pas ouverte
                            UpdateGoState(m_uiZiggurat4GUID, GO_STATE_ACTIVE, false);
                    UpdateGoState(m_uiZiggurat5GUID, GO_STATE_ACTIVE, false);
                    if (GameObject* pGob = instance->GetGameObject(m_uiPortGauntletGUID))
                        if (pGob->GetGoState() != GO_STATE_ACTIVE) // Si pas ouverte
                            UpdateGoState(m_uiPortGauntletGUID, GO_STATE_ACTIVE, false);
                }

                m_auiEncounter[TYPE_BARON] = uiData;
                break;
            }
            case TYPE_CRISTAL_DIE:
            {
                StartSlaugtherSquare();
                break;
            }
            case TYPE_CRISTAL_ALL_DIE:
            case TYPE_EVENT_AURIUS:
            case TYPE_RAMSTEIN_EVENT:
            case TYPE_UNFORGIVEN:
            {
                m_auiEncounter[uiType] = uiData;
                break;
            }
            case TYPE_SH_AELMAR:
            {
                IsSilverHandDead[0] = (uiData) != 0;
                break;
            }
            case TYPE_SH_CATHELA:
            {
                IsSilverHandDead[1] = (uiData) != 0;
                break;
            }
            case TYPE_SH_GREGOR:
            {
                IsSilverHandDead[2] = (uiData) != 0;
                break;
            }
            case TYPE_SH_NEMAS:
            {
                IsSilverHandDead[3] = (uiData) != 0;
                break;
            }
            case TYPE_SH_VICAR:
            {
                IsSilverHandDead[4] = (uiData) != 0;
                break;
            }
            case TYPE_POSTMASTER:
            {
                m_auiEncounter[uiType] = uiData;
                if (uiData == IN_PROGRESS)
                {
                    ++m_uiPostboxesUsed;

                    // After the second post box prepare to spawn the Post Master
                    if (m_uiPostboxesUsed == 2)
                        SetData(TYPE_POSTMASTER, SPECIAL);
                }
                // No need to save anything here, so return
                return;
            }

        }
        if (uiData == DONE)
        {
            std::ostringstream saveStream;
            for (uint32 i : m_auiEncounter)
                saveStream << i << " ";
            strInstData = saveStream.str();

            SaveToDB();
        }
    }

    /** Load / save system */
    std::string strInstData;
    char const* Save() override
    {
        return strInstData.c_str();
    }

    void Load(char const* chrIn) override
    {
        if (!chrIn)
            return;
        std::istringstream loadStream(chrIn);
        for (uint32 & i : m_auiEncounter)
        {
            loadStream >> i;
            if (i == IN_PROGRESS)
                i = NOT_STARTED;
        }
        if (GetData(TYPE_RAMSTEIN_EVENT) == DONE && GetData(TYPE_RAMSTEIN) != DONE)
            SummonRamstein();
    }
    /** Custom functions */

    bool JoueurDansPiegeRat1()
    {
        //float x1 = 3907.45f;
        //float y1 = -3550.41f;
        float x2 = 3909.34f;
        float y2 = -3540.14f;
        float x3 = 3930.1f;
        float y3 = -3554.4f;
        //float x4 = 3931.9f;
        //float y4 = -3544.6f;

        Map::PlayerList const &listeJoueur = instance->GetPlayers();
        for (const auto& itr : listeJoueur)
        {
            /*
            la zone est un paralelograme
                        ________    vx4
                  x2-> |        |___
             y          /|        |  /
             ^         / |        | /
             |->x    /------------/
                    ^x1             ^x3
            */
            if (itr.getSource()->IsAlive() && !itr.getSource()->IsGameMaster() && itr.getSource()->IsGMVisible())
            {
                //hauteur corect ?
                if (itr.getSource()->GetPositionZ() < 135 && itr.getSource()->GetPositionZ() > 130)
                    continue;

                //carre central ?
                if (itr.getSource()->GetPositionX() < x3 && itr.getSource()->GetPositionX() > x2 &&
                        itr.getSource()->GetPositionY() < y3 && itr.getSource()->GetPositionY() > y2 + 4)
                    continue;

                return true;
            }
        }
        return false;
    }

    bool JoueurDansPiegeRat2()
    {
        Map::PlayerList const &listeJoueur = instance->GetPlayers();
        for (const auto& itr : listeJoueur)
        {
            if (itr.getSource()->IsAlive() && !itr.getSource()->IsGameMaster() && itr.getSource()->IsGMVisible() &&
                    itr.getSource()->GetPositionX() < 3621.32 && itr.getSource()->GetPositionX() > 3603.18 &&
                    itr.getSource()->GetPositionY() < -3335 && itr.getSource()->GetPositionY() > -3340.46 &&
                    itr.getSource()->GetPositionZ() < 130 && itr.getSource()->GetPositionZ() > 123)
                return true;
        }
        return false;
    }

    void MoveAbomnationMob()
    {
        if (!slaugtherAboGUID.empty())
        {
            uint32 randAbo = urand(0, slaugtherAboGUID.size() - 1);
            std::list<uint64>::const_iterator Iter = slaugtherAboGUID.begin();
            for (uint32 i = 0; i < randAbo; ++i)
                ++Iter;

            if (Creature* pAbom = instance->GetCreature(*Iter))
            {
                if (pAbom->IsAlive() && !pAbom->IsInCombat())
                {
                    pAbom->GetMotionMaster()->MovePoint(0, 4037.194f, -3473.741943f, 121.738808f);
                    //pAbom->GetMotionMaster()->MovePoint(1, 4038.45288f, -3487.635498f, 121.742157f);
                    //pAbom->SetHomePosition(4036.40527f, -3470.181152f, 121.749062f, 4.7418f);
                }
                m_uiSlaugtherAboMob_Timer = (pAbom->GetEntry() == NPC_ABOM_BILE) ? 45000 : urand(35000, 40000);
                slaugtherAboGUID.remove(*Iter);
            }
        }
    }

    void Update(uint32 uiDiff) override
    {
        if (GetData(TYPE_UNFORGIVEN) == NOT_STARTED)
        {
            Map::PlayerList const& players = instance->GetPlayers();
            for (const auto& player : players)
            {
                if (Player* pPlayer = player.getSource())
                {
                    if (pPlayer->IsTargetable(true, false) &&
                        pPlayer->GetDistance3dToCenter(unforgivenTriggerSpot) < 10.0f)
                    {
                        SetData(TYPE_UNFORGIVEN, DONE);
                        instance->SummonCreature(NPC_THE_UNFORGIVEN, 3719.82f, -3426.25f, 131.844f, 3.3412f, TEMPSUMMON_DEAD_DESPAWN, 1 * HOUR * IN_MILLISECONDS);
                        instance->SummonCreature(NPC_VENGEFUL_PHANTOM, 3715.85f, -3428.25f, 131.442f, 3.57792f, TEMPSUMMON_DEAD_DESPAWN, 1 * HOUR * IN_MILLISECONDS);
                        instance->SummonCreature(NPC_VENGEFUL_PHANTOM, 3714.14f, -3423.75f, 131.673f, 3.61283f, TEMPSUMMON_DEAD_DESPAWN, 1 * HOUR * IN_MILLISECONDS);
                        instance->SummonCreature(NPC_VENGEFUL_PHANTOM, 3721.93f, -3429.88f, 131.844f, 3.33358f, TEMPSUMMON_DEAD_DESPAWN, 1 * HOUR * IN_MILLISECONDS);
                        instance->SummonCreature(NPC_VENGEFUL_PHANTOM, 3718.09f, -3432.27f, 131.306f, 4.3381f, TEMPSUMMON_DEAD_DESPAWN, 1 * HOUR * IN_MILLISECONDS);
                        break;
                    }
                }
            }
        }

        // Loop over the two Gate traps, each one has up to three timers (trap reset, gate opening delay, critters spawning delay)
        for (uint8 i = 0; i < 2; i++)
        {
            // Check that the trap is not on cooldown, if so check if player/pet is in range
            if (m_uiGateTrapTimers[i][0])
            {
                m_uiGateTrapTimers[i][0] -= uiDiff;
                if (m_uiGateTrapTimers[i][0] <= uiDiff)
                {
                    DEBUG_LOG("SD2: Instance Stratholme - Rat Trap reseted %u.", i);
                    m_uiGateTrapTimers[i][0] = 0;
                }
            }
            else
            {
                Map::PlayerList const& players = instance->GetPlayers();
                for (const auto& player : players)
                {
                    if (Player* pPlayer = player.getSource())
                    {
                        if (!pPlayer->IsGameMaster() && pPlayer->IsWithinDist2d(aGateTrap[i].x, aGateTrap[i].y, 5.5f))
                            DoGateTrap(i);

                        Pet* pet = pPlayer->GetPet();
                        if (!pPlayer->IsGameMaster() && pet && pet->IsWithinDist2d(aGateTrap[i].x, aGateTrap[i].y, 5.5f))
                            DoGateTrap(i);
                    }
                }
            }
            // Timer to reopen the gates
            if (m_uiGateTrapTimers[i][1])
            {
                if (m_uiGateTrapTimers[i][1] <= uiDiff)
                {
                    DoUseDoorOrButton(m_ratTrapGateGUID[2 * i]);
                    DoUseDoorOrButton(m_ratTrapGateGUID[2 * i + 1]);
                    m_uiGateTrapTimers[i][1] = 0;
                }
                else
                    m_uiGateTrapTimers[i][1] -= uiDiff;
            }
            // Delay timer to spawn the plagued critters once the gate are closing
            if (m_uiGateTrapTimers[i][2])
            {
                if (m_uiGateTrapTimers[i][2] <= uiDiff)
                {
                    if (Player* pPlayer = GetPlayerInMap())
                        DoSpawnPlaguedCritters(i, pPlayer);
                    m_uiGateTrapTimers[i][2] = 0;
                }
                else
                    m_uiGateTrapTimers[i][2] -= uiDiff;
            }
        }

        if (m_uiBaronRun_Timer)
        {
            if (m_uiBaronRun_Timer <= 45*MINUTE*IN_MILLISECONDS && m_phaseBaron == 0)
            {
                m_phaseBaron++;

                if (Creature* pBaron = instance->GetCreature(m_uiBaronGUID))
                    DoScriptText(RIVENDARE_YELL_45MIN, pBaron);

                Map::PlayerList const& players = instance->GetPlayers();
                if (!players.isEmpty())
                    for (const auto& player : players)
                        if (!player.getSource()->HasAura(SPELL_BARON_ULTIMATUM_45MIN, EFFECT_INDEX_0))
                            player.getSource()->CastSpell(player.getSource(), SPELL_BARON_ULTIMATUM_45MIN, true);
            }
            if (m_uiBaronRun_Timer <= 10*MINUTE*IN_MILLISECONDS && m_phaseBaron == 1)
            {
                m_phaseBaron++;

                if (Creature* pBaron = instance->GetCreature(m_uiBaronGUID))
                    DoScriptText(RIVENDARE_YELL_10MIN, pBaron);

                Map::PlayerList const& players = instance->GetPlayers();
                if (!players.isEmpty())
                    for (const auto& player : players)
                        if (!player.getSource()->HasAura(SPELL_BARON_ULTIMATUM_10MIN, EFFECT_INDEX_0))
                            player.getSource()->CastSpell(player.getSource(), SPELL_BARON_ULTIMATUM_10MIN, true);
            }
            if (m_uiBaronRun_Timer <= 5*MINUTE*IN_MILLISECONDS && m_phaseBaron == 2)
            {
                m_phaseBaron++;

                if (Creature* pBaron = instance->GetCreature(m_uiBaronGUID))
                    DoScriptText(RIVENDARE_YELL_5MIN, pBaron);

                Map::PlayerList const& players = instance->GetPlayers();
                if (!players.isEmpty())
                    for (const auto& player : players)
                        if (!player.getSource()->HasAura(SPELL_BARON_ULTIMATUM_5MIN, EFFECT_INDEX_0))
                            player.getSource()->CastSpell(player.getSource(), SPELL_BARON_ULTIMATUM_5MIN, true);
            }
            if (m_uiBaronRun_Timer <= 5*MINUTE*IN_MILLISECONDS - 3000 && m_phaseBaron == 3)
            {
                m_phaseBaron++;

                if (Creature* pYsida = instance->GetCreature(m_uiYsidaGUID))
                    DoScriptText(YSIDA_YELL_5MIN, pYsida);
            }
            if (m_uiBaronRun_Timer <= 1*MINUTE*IN_MILLISECONDS && m_phaseBaron == 4)
            {
                m_phaseBaron++;

                Map::PlayerList const& players = instance->GetPlayers();
                if (!players.isEmpty())
                    for (const auto& player : players)
                        if (!player.getSource()->HasAura(SPELL_BARON_ULTIMATUM_1MIN, EFFECT_INDEX_0))
                            player.getSource()->CastSpell(player.getSource(), SPELL_BARON_ULTIMATUM_1MIN, true);
            }
            if (m_uiBaronRun_Timer <= uiDiff)
            {
                m_phaseBaron = 6;
                m_uiBaronRun_Timer = 0;

                if (GetData(TYPE_BARON_RUN) != DONE)
                    SetData(TYPE_BARON_RUN, FAIL);

                if (Creature* pBaron = instance->GetCreature(m_uiBaronGUID))
                    DoScriptText(RIVENDARE_YELL_FAILED, pBaron);

                if (instance->GetGameObject(m_cageYsidaGUID))
                    instance->GetGameObject(m_cageYsidaGUID)->SetGoState(GO_STATE_ACTIVE);

                if (Creature* pYsida = instance->GetCreature(m_uiYsidaGUID))
                {
                    DoScriptText(YSIDA_YELL_FAILED, pYsida);
                    pYsida->CastSpell(pYsida, 5, true); // deathtouch
                }

                sLog.outDebug("Instance Stratholme: Baron run event reached end. Event has state %u.", GetData(TYPE_BARON_RUN));
            }
            else
                m_uiBaronRun_Timer -= uiDiff;
        }

        if (m_uiSlaugtherAboMob_Timer)
        {
            if (m_uiSlaugtherAboMob_Timer <= uiDiff)
            {
                if (!slaugtherAboGUID.empty())
                    MoveAbomnationMob();
                else
                    m_uiSlaugtherAboMob_Timer = 0;
            }
            else
                m_uiSlaugtherAboMob_Timer -= uiDiff;
        }

        if (m_uiSlaugtherSquare_Timer)
        {
            if (m_uiSlaugtherSquare_Timer <= uiDiff)
            {
                if (GetData(TYPE_RAMSTEIN) == IN_PROGRESS)
                {
                    UpdateGoState(m_uiZiggurat4GUID, GO_STATE_READY, false);
                    if (Creature* pRamstein = instance->GetCreature(m_uiRamsteinGUID))
                        DoScriptText(RAMMSTEIN_YELL_SPAWN, pRamstein);
                }
                else
                {
                    if (Creature* pBaron = instance->GetCreature(m_uiBaronGUID))
                    {
                        for (uint8 i = 0; i < 5; ++i)
                        {
                            if (Creature* pBlackGuard = pBaron->SummonCreature(NPC_BLACK_GUARD, 4032.84f + float(urand(0, 2)), -3380.567f + float(urand(0, 2)), 119.739571f, 4.7614f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 1800000))
                            {
                                pBlackGuard->GetMotionMaster()->MovePoint(0, 4033.34f, -3419.75f, 116.35f);
                                pBlackGuard->SetHomePosition(4033.34f, -3419.75f, 116.35f, 4.80f);
                                if (i == 0)
                                    DoScriptText(BLACKGUARD_YELL_SPAWN, pBlackGuard);
                            }
                        }
                        UpdateGoState(m_uiZiggurat4GUID, GO_STATE_ACTIVE, false);
                        UpdateGoState(m_uiZiggurat5GUID, GO_STATE_ACTIVE, false);
                        pBaron->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);

                        sLog.outDebug("Instance Stratholme: Black guard sentries spawned. Opening gates to baron.");
                    }
                }
                m_uiSlaugtherSquare_Timer = 0;
            }
            else
                m_uiSlaugtherSquare_Timer -= uiDiff;
        }

        if (m_uiYsidaReward_Timer)
        {
            if (m_uiYsidaReward_Timer <= uiDiff)
            {
                if (Creature* pYsida = instance->GetCreature(m_uiYsidaGUID))
                    DoScriptText(YSIDA_SAY_REWARD, pYsida);
                /* disable until t0.5 quest line is in TODO: handle this with eventMgr check
                // reward +150 Argent Dawn reputation
                Map::PlayerList const& players = instance->GetPlayers();
                if (!players.isEmpty())
                {
                    for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                    {
                        if (Player* pPlayer = itr->getSource())
                            pPlayer->CastSpell(pPlayer, SPELL_YSIDA_FREED, true);
                    }
                }
                */
                m_uiYsidaReward_Timer = 0;
            }
            else
                m_uiYsidaReward_Timer -= uiDiff;
        }
    }
    void SummonRamstein()
    {
        if (Creature* pRamstein = instance->SummonCreature(NPC_RAMSTEIN, 4032.35f, -3380.567f, 119.739571f, 4.7614f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 1800000))
        {
            pRamstein->GetMotionMaster()->MovePoint(0, 4033.009f, -3404.3293f, 115.3554f);
            pRamstein->SetHomePosition(4033.009f, -3404.3293f, 115.3554f, 4.788970f);
            SetData(TYPE_RAMSTEIN_EVENT, DONE);
            sLog.outDebug("Instance Stratholme: Ramstein spawned.");
        }
    }
    void DoGateTrap(uint8 uiGate)
    {
        // Check if timer was not already set by another player/pet a few milliseconds before
        if (m_uiGateTrapTimers[uiGate][0])
            return;

        DEBUG_LOG("SD2: Instance Stratholme - Rat Trap activated %i.", uiGate);
        // close the gates
        DoUseDoorOrButton(m_ratTrapGateGUID[2 * uiGate]);
        DoUseDoorOrButton(m_ratTrapGateGUID[2 * uiGate + 1]);

        // set timer to reset the trap
        m_uiGateTrapTimers[uiGate][0] = 30 * MINUTE * IN_MILLISECONDS;
        // set timer to reopen gates
        m_uiGateTrapTimers[uiGate][1] = 20 * IN_MILLISECONDS;
        // set timer to spawn the plagued critters
        m_uiGateTrapTimers[uiGate][2] = 2 * IN_MILLISECONDS;
    }

    void DoSpawnPlaguedCritters(uint8 uiGate, Player* pPlayer)
    {
        if (!pPlayer)
            return;

        uint32 uiEntry = aPlaguedCritters[urand(0, 2)];
        for (uint8 i = 0; i < 30; ++i)
        {
            float fX, fY, fZ;
            pPlayer->GetRandomPoint(aGateTrap[uiGate].x, aGateTrap[uiGate].y, aGateTrap[uiGate].z, 8.0f, fX, fY, fZ);
            pPlayer->SummonCreature(uiEntry, fX, fY, fZ, 0, TEMPSUMMON_DEAD_DESPAWN, 0);
        }
    }
};

InstanceData* GetInstanceData_instance_stratholme(Map* pMap)
{
    return new instance_stratholme(pMap);
}

void AddSC_instance_stratholme()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "instance_stratholme";
    newscript->GetInstanceData = &GetInstanceData_instance_stratholme;
    newscript->RegisterSelf();
}
