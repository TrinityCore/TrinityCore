#include "precompiled.h"
#include "escort_ai.h"
#include "def_halls_of_stone.h"

enum Texts
{
    SAY_KILL_1                          = -1603012,
    SAY_KILL_2                          = -1603013,
    SAY_KILL_3                          = -1603014,
    SAY_LOW_HEALTH                      = -1603015,
    SAY_DEATH                           = -1603016,
    SAY_PLAYER_DEATH_1                  = -1603017,
    SAY_PLAYER_DEATH_2                  = -1603018,
    SAY_PLAYER_DEATH_3                  = -1603019,
    SAY_ESCORT_START                    = -1603020,

    SAY_SPAWN_DWARF                     = -1603021,
    SAY_SPAWN_TROGG                     = -1603022,
    SAY_SPAWN_OOZE                      = -1603023,
    SAY_SPAWN_EARTHEN                   = -1603024,

    SAY_EVENT_INTRO_1                   = -1603025,
    SAY_EVENT_INTRO_2                   = -1603026,
    SAY_EVENT_INTRO_3_ABED              = -1603027,

    SAY_EVENT_A_1                       = -1603028,
    SAY_EVENT_A_2_KADD                  = -1603029,
    SAY_EVENT_A_3                       = -1603030,

    SAY_EVENT_B_1                       = -1603031,
    SAY_EVENT_B_2_MARN                  = -1603032,
    SAY_EVENT_B_3                       = -1603033,

    SAY_EVENT_C_1                       = -1603034,
    SAY_EVENT_C_2_ABED                  = -1603035,
    SAY_EVENT_C_3                       = -1603036,

    SAY_EVENT_D_1                       = -1603037,
    SAY_EVENT_D_2_ABED                  = -1603038,
    SAY_EVENT_D_3                       = -1603039,
    SAY_EVENT_D_4_ABED                  = -1603040,

    SAY_EVENT_END_01                    = -1603041,
    SAY_EVENT_END_02                    = -1603042,
    SAY_EVENT_END_03_ABED               = -1603043,
    SAY_EVENT_END_04                    = -1603044,
    SAY_EVENT_END_05_ABED               = -1603045,
    SAY_EVENT_END_06                    = -1603046,
    SAY_EVENT_END_07_ABED               = -1603047,
    SAY_EVENT_END_08                    = -1603048,
    SAY_EVENT_END_09_KADD               = -1603049,
    SAY_EVENT_END_10                    = -1603050,
    SAY_EVENT_END_11_KADD               = -1603051,
    SAY_EVENT_END_12                    = -1603052,
    SAY_EVENT_END_13_KADD               = -1603053,
    SAY_EVENT_END_14                    = -1603054,
    SAY_EVENT_END_15_MARN               = -1603055,
    SAY_EVENT_END_16                    = -1603056,
    SAY_EVENT_END_17_MARN               = -1603057,
    SAY_EVENT_END_18                    = -1603058,
    SAY_EVENT_END_19_MARN               = -1603059,
    SAY_EVENT_END_20                    = -1603060,
    SAY_EVENT_END_21_ABED               = -1603061,

    SAY_VICTORY_SJONNIR_1               = -1603062,
    SAY_VICTORY_SJONNIR_2               = -1603063,

    SAY_ENTRANCE_MEET                   = -1603064,

    TEXT_ID_START                       = 13100,
    TEXT_ID_PROGRESS                    = 13101
};

enum Creatures
{
    CREATURE_TRIBUNAL_OF_THE_AGES       = 28234,
    CREATURE_BRANN_BRONZEBEARD          = 28070,
    CREATURE_DARK_MATTER_TARGET         = 28237,
    CREATURE_SEARING_GAZE_TARGET        = 28265,
    CREATURE_DARK_RUNE_PROTECTOR        = 27983,
    CREATURE_DARK_RUNE_STORMCALLER      = 27984,
    CREATURE_IRON_GOLEM_CUSTODIAN       = 27985,
    CREATURE_KADDRAK                    = 30898
};

enum Spells
{
    SPELL_STEALTH                       = 58506,
    //Kadrak
    SPELL_GLARE_OF_THE_TRIBUNAL         = 50988,
    H_SPELL_GLARE_OF_THE_TRIBUNAL       = 59868,
    //Marnak
    SPELL_DARK_MATTER                   = 51012,
    H_SPELL_DARK_MATTER                 = 59868,
    //Abedneum
    SPELL_SEARING_GAZE                  = 51136,
    H_SPELL_SEARING_GAZE                = 59867
};

enum Quests
{
    QUEST_HALLS_OF_STONE                = 13207
};

#define GOSSIP_ITEM_START               "Brann, it would be our honor!"
#define GOSSIP_ITEM_PROGRESS            "Let's move Brann, enough of the history lessons!"

struct Locations
{
    float x, y, z;
};

static Locations SpawnLocations[]=
{
    {946.992, 397.016, 208.374},
    {960.748, 382.944, 208.374},
};

struct TRINITY_DLL_DECL mob_tribuna_controllerAI : public ScriptedAI
{
    mob_tribuna_controllerAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
        SetCombatMovement(false);
    }

    ScriptedInstance* pInstance;

    uint32 uiKaddrakEncounterTimer;
    uint32 uiMarnakEncounterTimer;
    uint32 uiAbedneumEncounterTimer;

    bool bKaddrakActivated;
    bool bMarnakActivated;
    bool bAbedneumActivated;

    std::list<Creature*> lKaddrakGUIDList;

    void Reset()
    {
        uiKaddrakEncounterTimer = 1500;
        uiMarnakEncounterTimer = 10000;
        uiAbedneumEncounterTimer = 10000;

        bKaddrakActivated = false;
        bMarnakActivated = false;
        bAbedneumActivated = false;

        lKaddrakGUIDList.clear();
    }

    void UpdateFacesList()
   {
        /*GetCreatureListWithEntryInGrid(lKaddrakGUIDList, m_creature, CREATURE_KADDRAK, 50.0f);
        if (!lKaddrakGUIDList.empty())
        {
            uint32 uiPositionCounter = 0;
            for(std::list<Creature*>::iterator itr = lKaddrakGUIDList.begin(); itr != lKaddrakGUIDList.end(); ++itr)
            {
                if ((*itr)->isAlive())
                {
                    if (uiPositionCounter == 0)
                    {
                        (*itr)->GetMap()->CreatureRelocation((*itr), 927.265, 333.200, 218.780, (*itr)->GetOrientation());
                        (*itr)->SendMonsterMove(927.265, 333.200, 218.780, 0, (*itr)->GetMovementFlags(), 1);
                    }
                    else
                    {
                        (*itr)->GetMap()->CreatureRelocation((*itr), 921.745, 328.076, 218.780, (*itr)->GetOrientation());
                        (*itr)->SendMonsterMove(921.745, 328.076, 218.780, 0, (*itr)->GetMovementFlags(), 1);
                    }
                }
                ++uiPositionCounter;
            }
        }*/
    }

    void UpdateAI(const uint32 diff)
    {
        if(bKaddrakActivated)
        {
            if (uiKaddrakEncounterTimer < diff)
            {
                Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0);
                while (pTarget && pTarget->GetTypeId() != TYPEID_PLAYER)
                    pTarget = SelectUnit(SELECT_TARGET_RANDOM,0);
                if (pTarget && !lKaddrakGUIDList.empty())
                    for(std::list<Creature*>::iterator itr = lKaddrakGUIDList.begin(); itr != lKaddrakGUIDList.end(); ++itr)
                        if ((*itr)->isAlive())
                            (*itr)->CastSpell(pTarget, HeroicMode ? H_SPELL_GLARE_OF_THE_TRIBUNAL : SPELL_GLARE_OF_THE_TRIBUNAL, true);
                uiKaddrakEncounterTimer = 1500;
            } else uiKaddrakEncounterTimer -= diff;
        }
        if (bMarnakActivated)
        {
            if (uiMarnakEncounterTimer < diff)
            {
                Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0);
                while (pTarget && pTarget->GetTypeId() != TYPEID_PLAYER)
                    pTarget = SelectUnit(SELECT_TARGET_RANDOM,0);
                if (pTarget)
                {
                    if (Creature* pSummon = m_creature->SummonCreature(CREATURE_DARK_MATTER_TARGET, pTarget->GetPositionX(), pTarget->GetPositionY(), pTarget->GetPositionZ(), 0.0f, TEMPSUMMON_TIMED_DESPAWN, 1000))
                    {
                        pSummon->SetDisplayId(11686);
                        pSummon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        pSummon->CastSpell(pTarget, HeroicMode ? H_SPELL_DARK_MATTER : SPELL_DARK_MATTER, true);
                    }
                }
                uiMarnakEncounterTimer = 30000 + rand()%1000;
            } else uiMarnakEncounterTimer -= diff;
        }
        if (bAbedneumActivated)
        {
            if (uiAbedneumEncounterTimer < diff)
            {
                Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0);
                while (pTarget && pTarget->GetTypeId() != TYPEID_PLAYER)
                    pTarget = SelectUnit(SELECT_TARGET_RANDOM,0);
                if (pTarget)
                {
                    if (Creature* pSummon = m_creature->SummonCreature(CREATURE_SEARING_GAZE_TARGET, pTarget->GetPositionX(), pTarget->GetPositionY(), pTarget->GetPositionZ(), 0.0f, TEMPSUMMON_TIMED_DESPAWN, 1000))
                    {
                        pSummon->SetDisplayId(11686);
                        pSummon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        pSummon->CastSpell(pTarget, HeroicMode ? H_SPELL_SEARING_GAZE : SPELL_SEARING_GAZE, true);
                    }
                }
                uiAbedneumEncounterTimer = 30000 + rand()%1000;
            } else uiAbedneumEncounterTimer -= diff;
        }
    }
};

struct TRINITY_DLL_DECL npc_brann_hosAI : public npc_escortAI
{
    npc_brann_hosAI(Creature *c) : npc_escortAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    uint32 uiStep;
    uint32 uiPhaseTimer;

    uint64 uiControllerGUID;
    std::list<uint64> lDwarfGUIDList;

    ScriptedInstance* pInstance;

    bool bIsBattle;
    bool bIsLowHP;

    void Reset()
    {
        if (!HasEscortState(STATE_ESCORT_ESCORTING))
        {
            bIsLowHP = false;
            bIsBattle = false;
            uiStep = 0;
            uiPhaseTimer = 0;
            uiControllerGUID = 0;

            DespawnDwarf();

            if (pInstance)
                pInstance->SetData(DATA_BRANN_EVENT, NOT_STARTED);
        }
    }

    void DespawnDwarf()
    {
        if (lDwarfGUIDList.empty())
            return;
        for (std::list<uint64>::iterator itr = lDwarfGUIDList.begin(); itr != lDwarfGUIDList.end(); ++itr)
        {
            Creature* pTemp = Unit::GetCreature(*m_creature, pInstance ? (*itr) : 0);
            if (pTemp && pTemp->isAlive())
                pTemp->ForcedDespawn();
        }
        lDwarfGUIDList.clear();
    }

    void WaypointReached(uint32 uiPointId)
    {
        switch(uiPointId)
        {
            case 7:
                if (Creature* pCreature = GetClosestCreatureWithEntry(m_creature, CREATURE_TRIBUNAL_OF_THE_AGES, 100.0f))
                {
                    if (!pCreature->isAlive())
                        pCreature->Respawn();
                    ((mob_tribuna_controllerAI*)pCreature->AI())->UpdateFacesList();
                    uiControllerGUID = pCreature->GetGUID();
                }
                break;
            case 13:
                DoScriptText(SAY_EVENT_INTRO_1, m_creature);
                SetEscortPaused(true);
                SetRun(true);
                JumpToNextStep(20000);
                break;
            case 17:
                DoScriptText(SAY_EVENT_INTRO_2, m_creature);
                if (pInstance)
                    pInstance->HandleGameObject(pInstance->GetData64(DATA_GO_TRIBUNAL_CONSOLE),true);
                m_creature->SetStandState(UNIT_STAND_STATE_KNEEL);
                SetEscortPaused(true);
                JumpToNextStep(8500);
                break;
            case 18:
                SetEscortPaused(true);
                break;
        }
     }

     void SpawnDwarf(uint32 uiType)
     {
       switch(uiType)
       {
           case 1:
           {
               uint32 uiSpawnNumber = (HeroicMode ? 3 : 2);
               for (uint8 i = 0; i < uiSpawnNumber; ++i)
                   m_creature->SummonCreature(CREATURE_DARK_RUNE_PROTECTOR, SpawnLocations[0].x, SpawnLocations[0].y, SpawnLocations[0].z, 0.0f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 30000);
               m_creature->SummonCreature(CREATURE_DARK_RUNE_STORMCALLER, SpawnLocations[0].x, SpawnLocations[0].y, SpawnLocations[0].z, 0.0f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 30000);
               break;
           }
           case 2:
               for (uint8 i = 0; i < 2; ++i)
                   m_creature->SummonCreature(CREATURE_DARK_RUNE_STORMCALLER, SpawnLocations[1].x, SpawnLocations[1].y, SpawnLocations[1].z, 0.0f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 30000);
               break;
           case 3:
               m_creature->SummonCreature(CREATURE_IRON_GOLEM_CUSTODIAN, SpawnLocations[1].x, SpawnLocations[1].y, SpawnLocations[1].z, 0.0f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 30000);
               break;
       }
     }

    void JustSummoned(Creature* pSummoned)
    {
        lDwarfGUIDList.push_back(pSummoned->GetGUID());
        pSummoned->AddThreat(m_creature, 0.0f);
        pSummoned->AI()->AttackStart(m_creature);
    }

    void JumpToNextStep(uint32 uiTimer)
    {
      uiPhaseTimer = uiTimer;
      uiStep++;
    }

    void StartWP()
    {
        m_creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
        SetEscortPaused(false);
        uiStep = 1;
    }

    void UpdateEscortAI(const uint32 uiDiff)
    {
        if (uiPhaseTimer < uiDiff)
        {
            switch(uiStep)
            {
                case 1:
                    if (pInstance)
                    {
                        if (pInstance->GetData(DATA_BRANN_EVENT) != NOT_STARTED)
                            return;
                        pInstance->SetData(DATA_BRANN_EVENT, IN_PROGRESS);
                    }
                    bIsBattle = false;
                    DoScriptText(SAY_ESCORT_START, m_creature);
                    JumpToNextStep(0);
                    break;
                case 3:
                    SetEscortPaused(false);
                    JumpToNextStep(0);
                    break;
                case 5:
                    if (pInstance)
                        if (Creature* pTemp = (Unit::GetCreature(*m_creature, pInstance->GetData64(DATA_ABEDNEUM))))
                            DoScriptText(SAY_EVENT_INTRO_3_ABED, pTemp);
                        JumpToNextStep(8500);
                    break;
                case 6:
                    DoScriptText(SAY_EVENT_A_1, m_creature);
                    JumpToNextStep(6500);
                    break;
                case 7:
                    if (pInstance)
                        if (Creature* pTemp = Unit::GetCreature(*m_creature, pInstance->GetData64(DATA_KADDRAK)))
                            DoScriptText(SAY_EVENT_A_2_KADD, pTemp);
                        JumpToNextStep(12500);
                    break;
                case 8:
                    DoScriptText(SAY_EVENT_A_3, m_creature);
                    if (pInstance)
                        pInstance->HandleGameObject(pInstance->GetData64(DATA_GO_KADDRAK),true);
                    if (Creature* pTemp = Unit::GetCreature(*m_creature, uiControllerGUID))
                        ((mob_tribuna_controllerAI*)pTemp->AI())->bKaddrakActivated = true;
                    JumpToNextStep(5000);
                    break;
                case 9:
                    SpawnDwarf(1);
                    JumpToNextStep(20000);
                    break;
                case 10:
                    DoScriptText(SAY_EVENT_B_1, m_creature);
                    JumpToNextStep(6000);
                    break;
                case 11:
                    if (pInstance)
                        if (Creature* pTemp = Unit::GetCreature(*m_creature, pInstance->GetData64(DATA_MARNAK)))
                            DoScriptText(SAY_EVENT_B_2_MARN, pTemp);
                    SpawnDwarf(1);
                    JumpToNextStep(20000);
                    break;
                case 12:
                    DoScriptText(SAY_EVENT_B_3, m_creature);
                    if (pInstance)
                        pInstance->HandleGameObject(pInstance->GetData64(DATA_GO_MARNAK),true);
                    if (Creature* pTemp = Unit::GetCreature(*m_creature, uiControllerGUID))
                        ((mob_tribuna_controllerAI*)pTemp->AI())->bMarnakActivated = true;
                    JumpToNextStep(10000);
                    break;
                case 13:
                    SpawnDwarf(1);
                    JumpToNextStep(10000);
                    break;
                case 14:
                    SpawnDwarf(2);
                    JumpToNextStep(20000);
                    break;
                case 15:
                    DoScriptText(SAY_EVENT_C_1, m_creature);
                    SpawnDwarf(1);
                    JumpToNextStep(10000);
                    break;
                case 16:
                    SpawnDwarf(2);
                    JumpToNextStep(20000);
                    break;
                case 17:
                    if (pInstance)
                        if (Creature* pTemp = Unit::GetCreature(*m_creature, pInstance->GetData64(DATA_ABEDNEUM)))
                            DoScriptText(SAY_EVENT_C_2_ABED, pTemp);
                        SpawnDwarf(1);
                    JumpToNextStep(20000);
                    break;
                case 18:
                    DoScriptText(SAY_EVENT_C_3, m_creature);
                    if (pInstance)
                        pInstance->HandleGameObject(pInstance->GetData64(DATA_GO_ABEDNEUM),true);
                    if (Creature* pTemp = Unit::GetCreature(*m_creature, uiControllerGUID))
                        ((mob_tribuna_controllerAI*)pTemp->AI())->bAbedneumActivated = true;
                    JumpToNextStep(5000);
                    break;
                case 19:
                    SpawnDwarf(2);
                    JumpToNextStep(10000);
                    break;
                case 20:
                    SpawnDwarf(1);
                    JumpToNextStep(15000);
                    break;
                case 21:
                    DoScriptText(SAY_EVENT_D_1, m_creature);
                    SpawnDwarf(3);
                    JumpToNextStep(20000);
                    break;
                case 22:
                    if (pInstance)
                        if (Creature* pTemp = Unit::GetCreature(*m_creature, pInstance->GetData64(DATA_ABEDNEUM)))
                            DoScriptText(SAY_EVENT_D_2_ABED, pTemp);
                    SpawnDwarf(1);
                    JumpToNextStep(5000);
                    break;
                case 23:
                    SpawnDwarf(2);
                    JumpToNextStep(15000);
                    break;
                case 24:
                    DoScriptText(SAY_EVENT_D_3, m_creature);
                    SpawnDwarf(3);
                    JumpToNextStep(5000);
                    break;
                case 25:
                    SpawnDwarf(1);
                    JumpToNextStep(5000);
                    break;
                case 26:
                    SpawnDwarf(2);
                    JumpToNextStep(10000);
                    break;
                case 27:
                    if (pInstance)
                        if (Creature* pTemp = Unit::GetCreature(*m_creature, pInstance->GetData64(DATA_ABEDNEUM)))
                            DoScriptText(SAY_EVENT_D_4_ABED, pTemp);
                    SpawnDwarf(1);
                    JumpToNextStep(10000);
                    break;
                case 28:
                    DoScriptText(SAY_EVENT_END_01, m_creature);
                    m_creature->SetStandState(UNIT_STAND_STATE_STAND);
                    if (pInstance)
                        pInstance->HandleGameObject(pInstance->GetData64(DATA_GO_SKY_FLOOR),true);
                    if (Creature* pTemp = Unit::GetCreature(*m_creature, uiControllerGUID))
                        pTemp->DealDamage(pTemp, pTemp->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                    bIsBattle = true;
                    SetEscortPaused(false);
                    JumpToNextStep(6500);
                    break;
                case 29:
                    DoScriptText(SAY_EVENT_END_02, m_creature);
                    JumpToNextStep(5500);
                    break;
                case 30:
                    if (pInstance)
                        if (Creature* pTemp = Unit::GetCreature(*m_creature, pInstance->GetData64(DATA_ABEDNEUM)))
                            DoScriptText(SAY_EVENT_END_03_ABED, pTemp);
                    JumpToNextStep(8500);
                    break;
                case 31:
                    DoScriptText(SAY_EVENT_END_04, m_creature);
                    JumpToNextStep(11500);
                    break;
                case 32:
                    if (pInstance)
                        if (Creature* pTemp = Unit::GetCreature(*m_creature, pInstance->GetData64(DATA_ABEDNEUM)))
                            DoScriptText(SAY_EVENT_END_05_ABED, pTemp);
                        JumpToNextStep(11500);
                    break;
                case 33:
                    DoScriptText(SAY_EVENT_END_06, m_creature);
                    JumpToNextStep(4500);
                    break;
                case 34:
                    if (pInstance)
                        if (Creature* pTemp = Unit::GetCreature(*m_creature, pInstance->GetData64(DATA_ABEDNEUM)))
                            DoScriptText(SAY_EVENT_END_07_ABED, pTemp);
                        JumpToNextStep(22500);
                    break;
                case 35:
                    DoScriptText(SAY_EVENT_END_08, m_creature);
                    JumpToNextStep(7500);
                    break;
                case 36:
                    if (pInstance)
                        if (Creature* pTemp = Unit::GetCreature(*m_creature, pInstance->GetData64(DATA_KADDRAK)))
                            DoScriptText(SAY_EVENT_END_09_KADD, pTemp);
                    JumpToNextStep(18500);
                    break;
                case 37:
                    DoScriptText(SAY_EVENT_END_10, m_creature);
                    JumpToNextStep(5500);
                    break;
                case 38:
                    if (pInstance)
                        if (Creature* pTemp = Unit::GetCreature(*m_creature, pInstance->GetData64(DATA_KADDRAK)))
                            DoScriptText(SAY_EVENT_END_11_KADD, pTemp);
                        JumpToNextStep(20500);
                    break;
                case 39:
                    DoScriptText(SAY_EVENT_END_12, m_creature);
                    JumpToNextStep(2500);
                    break;
                case 40:
                    if (pInstance)
                        if (Creature* pTemp = Unit::GetCreature(*m_creature, pInstance->GetData64(DATA_KADDRAK)))
                            DoScriptText(SAY_EVENT_END_13_KADD, pTemp);
                    JumpToNextStep(19500);
                    break;
                case 41:
                    DoScriptText(SAY_EVENT_END_14, m_creature);
                    JumpToNextStep(10500);
                    break;
                case 42:
                    if (pInstance)
                        if (Creature* pTemp = Unit::GetCreature(*m_creature, pInstance->GetData64(DATA_MARNAK)))
                            DoScriptText(SAY_EVENT_END_15_MARN, pTemp);
                        JumpToNextStep(6500);
                    break;
                case 43:
                    DoScriptText(SAY_EVENT_END_16, m_creature);
                    JumpToNextStep(6500);
                    break;
                case 44:
                    if (pInstance)
                        if (Creature* pTemp = Unit::GetCreature(*m_creature, pInstance->GetData64(DATA_MARNAK)))
                            DoScriptText(SAY_EVENT_END_17_MARN, pTemp);
                        JumpToNextStep(25500);
                    break;
                case 45:
                    DoScriptText(SAY_EVENT_END_18, m_creature);
                    JumpToNextStep(23500);
                    break;
                case 46:
                    if (pInstance)
                        if (Creature* pTemp = Unit::GetCreature(*m_creature, pInstance->GetData64(DATA_MARNAK)))
                            DoScriptText(SAY_EVENT_END_19_MARN, pTemp);
                        JumpToNextStep(3500);
                    break;
                case 47:
                    DoScriptText(SAY_EVENT_END_20, m_creature);
                    JumpToNextStep(8500);
                    break;
                case 48:
                    if (pInstance)
                        if (Creature* pTemp = Unit::GetCreature(*m_creature, pInstance->GetData64(DATA_ABEDNEUM)))
                            DoScriptText(SAY_EVENT_END_21_ABED, pTemp);
                        JumpToNextStep(5500);
                    break;
                case 49:
                {
                    if (pInstance)
                    {
                        pInstance->HandleGameObject(pInstance->GetData64(DATA_GO_KADDRAK),true);
                        pInstance->HandleGameObject(pInstance->GetData64(DATA_GO_MARNAK),true);
                        pInstance->HandleGameObject(pInstance->GetData64(DATA_GO_ABEDNEUM),true);
                        pInstance->HandleGameObject(pInstance->GetData64(DATA_GO_SKY_FLOOR),true);
                        pInstance->SetData(DATA_BRANN_EVENT, DONE);
                    }
                    Player* pPlayer = GetPlayerForEscort();
                    if (pPlayer)
                        pPlayer->GroupEventHappens(QUEST_HALLS_OF_STONE, m_creature);
                    m_creature->SetUInt32Value(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    m_creature->SetUInt32Value(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                    JumpToNextStep(180000);
                    break;
                }
                case 50:
                    SetEscortPaused(false);
                    break;
            }
        } else uiPhaseTimer -= uiDiff;

        if (!bIsLowHP && (m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) <= 30)
        {
            DoScriptText(SAY_LOW_HEALTH, m_creature);
            bIsLowHP = true;
        } else if (bIsLowHP && (m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) > 30)
            bIsLowHP = false;
    }
};

bool GossipHello_npc_brann_hos(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());

    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_START, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
    pPlayer->SEND_GOSSIP_MENU(TEXT_ID_START, pCreature->GetGUID());

    return true;
}

bool GossipSelect_npc_brann_hos(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    if (uiAction == GOSSIP_ACTION_INFO_DEF+1 || uiAction == GOSSIP_ACTION_INFO_DEF+2)
    {
        pPlayer->CLOSE_GOSSIP_MENU();
        ((npc_brann_hosAI*)pCreature->AI())->StartWP();
    }

    return true;
}

CreatureAI* GetAI_mob_tribuna_controller(Creature* pCreature)
{
    return new mob_tribuna_controllerAI(pCreature);
}

CreatureAI* GetAI_npc_brann_hos(Creature* pCreature)
{
    return new npc_brann_hosAI(pCreature);
}

void AddSC_halls_of_stone()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "npc_brann_hos";
    newscript->GetAI = &GetAI_npc_brann_hos;
    newscript->pGossipHello = &GossipHello_npc_brann_hos;
    newscript->pGossipSelect = &GossipSelect_npc_brann_hos;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_tribuna_controller";
    newscript->GetAI = &GetAI_mob_tribuna_controller;
    newscript->RegisterSelf();
}